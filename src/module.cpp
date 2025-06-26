#include "module.hpp"

#include <plugify/mem_addr.hpp>
#include <plugify/mem_accessor.hpp>
#include <plugify/mem_protector.hpp>
#include <plugify/compat_format.hpp>
#include <plugify/plugin_reference_descriptor.hpp>
#include <plugify/plugin_descriptor.hpp>
#include <plugify/plugin.hpp>
#include <plugify/log.hpp>

using namespace plugify;
using namespace cpplm;
namespace fs = std::filesystem;

#define LOG_PREFIX "[CPPLM] "

// ILanguageModule
InitResult CppLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, ModuleHandle /*module*/) {
	if (!((_provider = provider.lock()))) {
		return ErrorData{ "Provider not exposed" };
	}

	_provider->Log(LOG_PREFIX "Inited!", Severity::Debug);

	return InitResultData{{ .hasUpdate = false }};
}

void CppLanguageModule::Shutdown() {
	for (MemAddr* addr : _addresses) {
		*addr = nullptr;
	}
	_nativesMap.clear();
	_addresses.clear();
	_assemblies.clear();
	_provider.reset();
}

void CppLanguageModule::OnUpdate(plugify::DateTime /*dt*/) {
}

bool CppLanguageModule::IsDebugBuild() {
	return CPPLM_IS_DEBUG;
}

void CppLanguageModule::OnMethodExport(PluginHandle plugin) {
	for (const auto& [method, addr] : plugin.GetMethods()) {
		_nativesMap.try_emplace(std::format("{}.{}", plugin.GetName(), method.GetName()), addr);
	}
}

LoadResult CppLanguageModule::OnPluginLoad(PluginHandle plugin) {
	fs::path entryPoint(plugin.GetDescriptor().GetEntryPoint());
	fs::path assemblyPath(plugin.GetBaseDir() / entryPoint.parent_path() / std::format(CPPLM_LIBRARY_PREFIX "{}" CPPLM_LIBRARY_SUFFIX, entryPoint.filename().string()));

	LoadFlag flags = LoadFlag::Lazy;
	if (_provider->IsPreferOwnSymbols()) {
		flags |= LoadFlag::Deepbind;
	}

	auto assembly = std::make_unique<Assembly>(assemblyPath, flags);
	if (!assembly->IsValid()) {
		return ErrorData{ std::format("Failed to load assembly: {}", assembly->GetError()) };
	}

	auto* const initFunc = assembly->GetFunctionByName("Plugify_Init").RCast<InitFunc>();
	if (!initFunc) {
		return ErrorData{ "Not found 'Plugify_Init' function" };
	}

	auto* const startFunc = assembly->GetFunctionByName("Plugify_PluginStart").RCast<StartFunc>();
	auto* const updateFunc = assembly->GetFunctionByName("Plugify_PluginUpdate").RCast<UpdateFunc>();
	auto* const endFunc = assembly->GetFunctionByName("Plugify_PluginEnd").RCast<EndFunc>();
	auto* const contextFunc = assembly->GetFunctionByName("Plugify_PluginContext").RCast<ContextFunc>();

	std::vector<std::string_view> funcErrors;

	std::span<const MethodHandle> exportedMethods = plugin.GetDescriptor().GetExportedMethods();
	std::vector<MethodData> methods;
	methods.reserve(exportedMethods.size());

	for (const auto& method : exportedMethods) {
		if (auto const func = assembly->GetFunctionByName(method.GetFunctionName())) {
			methods.emplace_back(method, func);
		} else {
			funcErrors.emplace_back(method.GetName());
		}
	}
	if (!funcErrors.empty()) {
		std::string funcs(funcErrors[0]);
		for (auto it = std::next(funcErrors.begin()); it != funcErrors.end(); ++it) {
			std::format_to(std::back_inserter(funcs), ", {}", *it);
		}
		return ErrorData{ std::format("Not found {} method function(s)", funcs) };
	}

	const int requiredVersion = initFunc(_pluginApi.data(), plg::kApiVersion, plugin);
	if (requiredVersion != 0) {
		return ErrorData{ std::format("Not supported plugin api {}, max supported {}", requiredVersion, plg::kApiVersion) };
	}

	const auto& [hasUpdate, hasStart, hasEnd, hasDebug] = contextFunc ? *(contextFunc()) : plg::PluginContext{};

#if CPPLM_PLATFORM_WINDOWS
	constexpr bool cpplmBuildType = CPPLM_IS_DEBUG;
	if (hasDebug != cpplmBuildType) {
		return ErrorData{ std::format("Mismatch between module ({}) build type and plugin ({}) build type.", (cpplmBuildType ? "debug" : "release"), (hasDebug ? "debug" : "release")) };
	}
#endif

	auto data = _assemblies.emplace_back(std::make_unique<AssemblyHolder>(std::move(assembly), updateFunc, startFunc, endFunc, contextFunc)).get();
	return LoadResultData{ std::move(methods), data, { hasUpdate, hasStart, hasEnd, !exportedMethods.empty() } };
}

void CppLanguageModule::OnPluginStart(PluginHandle plugin) {
	plugin.GetData().RCast<AssemblyHolder*>()->startFunc();
}

void CppLanguageModule::OnPluginUpdate(plugify::PluginHandle plugin, plugify::DateTime dt) {
	plugin.GetData().RCast<AssemblyHolder*>()->updateFunc(dt.AsSeconds());
}

void CppLanguageModule::OnPluginEnd(PluginHandle plugin) {
	plugin.GetData().RCast<AssemblyHolder*>()->endFunc();
}

// Plugin API methods
MemAddr CppLanguageModule::GetNativeMethod(std::string_view methodName) const {
	if (const auto it = _nativesMap.find(methodName); it != _nativesMap.end()) {
		return std::get<MemAddr>(*it);
	}
	_provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find {}", methodName), Severity::Fatal);
	return nullptr;
}

void CppLanguageModule::GetNativeMethod(std::string_view methodName, plugify::MemAddr* addressDest) {
	if (const auto it = _nativesMap.find(methodName); it != _nativesMap.end()) {
		*addressDest = std::get<MemAddr>(*it);
		_addresses.emplace_back(addressDest);
		return;
	}
	_provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find: '{}'", methodName), Severity::Fatal);
}

namespace cpplm {
	CppLanguageModule g_cpplm;
}

void* GetMethodPtr(std::string_view methodName) {
	return g_cpplm.GetNativeMethod(methodName);
}

void GetMethodPtr2(std::string_view methodName, MemAddr* addressDest) {
	g_cpplm.GetNativeMethod(methodName, addressDest);
}

bool IsModuleLoaded(std::string_view moduleName, std::optional<plg::version> requiredVersion, bool minimum) {
	return g_cpplm.GetProvider()->IsModuleLoaded(moduleName, requiredVersion, minimum);
}

bool IsPluginLoaded(std::string_view pluginName, std::optional<plg::version> requiredVersion, bool minimum) {
	return g_cpplm.GetProvider()->IsPluginLoaded(pluginName, requiredVersion, minimum);
}

UniqueId GetPluginId(PluginHandle plugin) {
	return plugin.GetId();
}

std::string_view GetPluginName(PluginHandle plugin) {
	return plugin.GetName();
}

std::string_view GetPluginFullName(PluginHandle plugin) {
	return plugin.GetFriendlyName();
}

std::string_view GetPluginDescription(PluginHandle plugin) {
	return plugin.GetDescriptor().GetDescription();
}

std::string_view GetPluginVersion(PluginHandle plugin) {
	return plugin.GetDescriptor().GetVersionName();
}

std::string_view GetPluginAuthor(PluginHandle plugin) {
	return plugin.GetDescriptor().GetCreatedBy();
}

std::string_view GetPluginWebsite(PluginHandle plugin) {
	return plugin.GetDescriptor().GetCreatedByURL();
}

fs::path_view GetPluginBaseDir(PluginHandle plugin) {
	return plugin.GetBaseDir();
}

fs::path_view GetPluginConfigsDir(PluginHandle plugin) {
	return plugin.GetConfigsDir();
}

fs::path_view GetPluginDataDir(PluginHandle plugin) {
	return plugin.GetDataDir();
}

fs::path_view GetPluginLogsDir(PluginHandle plugin) {
	return plugin.GetLogsDir();
}

std::vector<std::string_view> GetPluginDependencies(PluginHandle plugin) {
	std::span<const PluginReferenceDescriptorHandle> dependencies = plugin.GetDescriptor().GetDependencies();
	std::vector<std::string_view> deps;
	deps.reserve(dependencies.size());
	for (const auto& dependency : dependencies) {
		deps.emplace_back(dependency.GetName());
	}
	return deps;
}

std::optional<fs::path_view> FindPluginResource(PluginHandle plugin, fs::path_view path) {
	return plugin.FindResource(path);
}

std::array<void*, 17> CppLanguageModule::_pluginApi = {
		reinterpret_cast<void*>(&::GetMethodPtr),
		reinterpret_cast<void*>(&::GetMethodPtr2),
		reinterpret_cast<void*>(&::IsModuleLoaded),
		reinterpret_cast<void*>(&::IsPluginLoaded),
		reinterpret_cast<void*>(&::GetPluginId),
		reinterpret_cast<void*>(&::GetPluginName),
		reinterpret_cast<void*>(&::GetPluginFullName),
		reinterpret_cast<void*>(&::GetPluginDescription),
		reinterpret_cast<void*>(&::GetPluginVersion),
		reinterpret_cast<void*>(&::GetPluginAuthor),
		reinterpret_cast<void*>(&::GetPluginWebsite),
		reinterpret_cast<void*>(&::GetPluginBaseDir),
		reinterpret_cast<void*>(&::GetPluginConfigsDir),
		reinterpret_cast<void*>(&::GetPluginDataDir),
		reinterpret_cast<void*>(&::GetPluginLogsDir),
		reinterpret_cast<void*>(&::GetPluginDependencies),
		reinterpret_cast<void*>(&::FindPluginResource)
};

ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
