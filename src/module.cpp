#include "module.hpp"

#include <plugify/assembly_loader.hpp>
#include <plugify/logger.hpp>

#include <plg/format.hpp>

using namespace plugify;
using namespace cpplm;
namespace fs = std::filesystem;

#define LOG_PREFIX "[CPPLM] "

// ILanguageModule
Result<InitData> CppLanguageModule::Initialize(const Provider& provider, [[maybe_unused]] const Extension& module) {
	_provider = std::make_unique<Provider>(provider);
	_provider->Log(LOG_PREFIX "Inited!", Severity::Debug);

	return InitData{ { .hasUpdate = false } };
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

void CppLanguageModule::OnUpdate([[maybe_unused]] std::chrono::milliseconds dt) {
}

bool CppLanguageModule::IsDebugBuild() {
	return CPPLM_IS_DEBUG;
}

void CppLanguageModule::OnMethodExport(const Extension& plugin) {
	const auto& methods = plugin.GetMethodsData();
	_nativesMap.reserve(_nativesMap.size() + methods.size());
	for (const auto& [method, addr] : methods) {
		_nativesMap.try_emplace(std::format("{}.{}", plugin.GetName(), method.GetName()), addr);
	}
}

Result<LoadData> CppLanguageModule::OnPluginLoad(const Extension& plugin) {
	fs::path entryPoint(plugin.GetEntry());
	fs::path assemblyPath(plugin.GetLocation() / entryPoint.parent_path() / std::format(CPPLM_LIBRARY_PREFIX "{}" CPPLM_LIBRARY_SUFFIX, plg::as_string(entryPoint.filename())));

	LoadFlag flags = LoadFlag::LazyBinding;
	if (_provider->IsPreferOwnSymbols()) {
		flags |= LoadFlag::DeepBind;
	}

	auto assemblyResult = _provider->Resolve<IAssemblyLoader>()->Load(assemblyPath, flags);
	if (!assemblyResult) {
		return MakeError(std::move(assemblyResult.error()));
	}

	auto& assembly = *assemblyResult;

	auto initResult = assembly->GetSymbol("Plugify_Init");
	if (!initResult) {
		return MakeError(std::move(initResult.error()));
	}
	auto startResult = assembly->GetSymbol("Plugify_PluginStart");
	if (!startResult) {
		return MakeError(std::move(startResult.error()));
	}
	auto updateResult = assembly->GetSymbol("Plugify_PluginUpdate");
	if (!updateResult) {
		return MakeError(std::move(updateResult.error()));
	}
	auto endResult = assembly->GetSymbol("Plugify_PluginEnd");
	if (!endResult) {
		return MakeError(std::move(endResult.error()));
	}
	auto contextResult = assembly->GetSymbol("Plugify_PluginContext");
	if (!contextResult) {
		return MakeError(std::move(contextResult.error()));
	}

	auto* initFunc = initResult->RCast<InitFunc>();
	auto* startFunc = startResult->RCast<StartFunc>();
	auto* updateFunc = updateResult->RCast<UpdateFunc>();
	auto* endFunc = endResult->RCast<EndFunc>();
	auto* contextFunc = contextResult->RCast<ContextFunc>();

	std::vector<std::string> errors;

	const std::vector<Method>& exportedMethods = plugin.GetMethods();
	std::vector<MethodData> methods;
	methods.reserve(exportedMethods.size());

	for (size_t i = 0; i < exportedMethods.size(); ++i) {
		const auto& method = exportedMethods[i];
		if (auto funcResult = assembly->GetSymbol(method.GetFuncName())) {
			methods.emplace_back(method, *funcResult);
		} else {
			errors.emplace_back(std::format("{:>3}. {} {}", i + 1, method.GetName(), funcResult.error()));
			if (constexpr size_t kMaxDisplay = 100; errors.size() >= kMaxDisplay) {
				errors.emplace_back(std::format("... and {} more", exportedMethods.size() - kMaxDisplay));
				break;
			}
		}
	}
	if (!errors.empty()) {
		return MakeError("Invalid methods:\n{}", plg::join(errors, "\n"));
	}

	const int requiredVersion = initFunc(_pluginApi.data(), plg::kApiVersion, static_cast<const void *>(&plugin));
	if (requiredVersion != 0) {
		return MakeError("Not supported plugin api {}, max supported {}", requiredVersion, plg::kApiVersion);
	}

	const auto& [hasUpdate, hasStart, hasEnd, hasDebug] = contextFunc ? *(contextFunc()) : plg::PluginContext{};

#if CPPLM_PLATFORM_WINDOWS
	constexpr bool cpplmBuildType = CPPLM_IS_DEBUG;
	if (hasDebug != cpplmBuildType) {
		return MakeError( "Build type mismatch: module={}, plugin={}",
					cpplmBuildType ? "debug" : "release",
					hasDebug ? "debug" : "release");
	}
#endif

	auto data = _assemblies.emplace_back(std::make_unique<AssemblyHolder>(std::move(assembly), updateFunc, startFunc, endFunc, contextFunc)).get();
	return LoadData{ std::move(methods), data, { hasUpdate, hasStart, hasEnd, !exportedMethods.empty() } };
}

void CppLanguageModule::OnPluginStart(const Extension& plugin) {
	plugin.GetUserData().RCast<AssemblyHolder*>()->startFunc();
}

void CppLanguageModule::OnPluginUpdate(const Extension& plugin, std::chrono::milliseconds dt) {
	plugin.GetUserData().RCast<AssemblyHolder*>()->updateFunc(dt);
}

void CppLanguageModule::OnPluginEnd(const Extension& plugin) {
	plugin.GetUserData().RCast<AssemblyHolder*>()->endFunc();
}

// Plugin API methods
MemAddr CppLanguageModule::GetNativeMethod(std::string_view methodName) const {
	if (const auto it = _nativesMap.find(methodName); it != _nativesMap.end()) {
		return std::get<MemAddr>(*it);
	}
	_provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find {}", methodName), Severity::Fatal);
	return nullptr;
}

void CppLanguageModule::GetNativeMethod(std::string_view methodName, MemAddr* addressDest) {
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

void* GetMethodPtr(std::string_view name) {
	return g_cpplm.GetNativeMethod(name);
}

void GetMethodPtr2(std::string_view name, MemAddr* dest) {
	g_cpplm.GetNativeMethod(name, dest);
}

plg::string GetBaseDir() {
	return plg::as_string(g_cpplm.GetProvider()->GetBaseDir());
}

plg::string GetExtensionsDir() {
	return plg::as_string(g_cpplm.GetProvider()->GetExtensionsDir());
}

plg::string GetConfigsDir() {
	return plg::as_string(g_cpplm.GetProvider()->GetConfigsDir());
}

plg::string GetDataDir() {
	return plg::as_string(g_cpplm.GetProvider()->GetDataDir());
}

plg::string GetLogsDir() {
	return plg::as_string(g_cpplm.GetProvider()->GetLogsDir());
}

plg::string GetCacheDir() {
	return plg::as_string(g_cpplm.GetProvider()->GetCacheDir());
}

bool IsExtensionLoaded(std::string_view name, std::optional<Constraint> constraint) {
	return g_cpplm.GetProvider()->IsExtensionLoaded(name, std::move(constraint));
}

UniqueId GetPluginId(const Extension& plugin) {
	return plugin.GetId();
}

plg::string GetPluginName(const Extension& plugin) {
	return plugin.GetName();
}

plg::string GetPluginDescription(const Extension& plugin) {
	return plugin.GetDescription();
}

Version GetPluginVersion(const Extension& plugin) {
	return plugin.GetVersion();
}

plg::string GetPluginAuthor(const Extension& plugin) {
	return plugin.GetAuthor();
}

plg::string GetPluginWebsite(const Extension& plugin) {
	return plugin.GetWebsite();
}

plg::string GetPluginLicense(const Extension& plugin) {
	return plugin.GetLicense();
}

plg::string GetPluginLocation(const Extension& plugin) {
	return plg::as_string(plugin.GetLocation());
}

struct Dependent {
	plg::string name;
	plg::range_set<> constraints;
	bool optional;
};

std::vector<Dependent> GetPluginDependencies(const Extension& plugin) {
	const std::vector<Dependency>& dependencies = plugin.GetDependencies();
	std::vector<Dependent> deps;
	deps.reserve(dependencies.size());
	for (const auto& dependency : dependencies) {
		deps.emplace_back(
			dependency.GetName(),
			dependency.GetConstraints(),
			dependency.IsOptional()
		);
	}
	return deps;
}

std::array<void*, 18> CppLanguageModule::_pluginApi = {
		reinterpret_cast<void*>(&::GetMethodPtr),
		reinterpret_cast<void*>(&::GetMethodPtr2),
		reinterpret_cast<void*>(&::GetBaseDir),
		reinterpret_cast<void*>(&::GetExtensionsDir),
		reinterpret_cast<void*>(&::GetConfigsDir),
		reinterpret_cast<void*>(&::GetDataDir),
		reinterpret_cast<void*>(&::GetLogsDir),
		reinterpret_cast<void*>(&::GetCacheDir),
		reinterpret_cast<void*>(&::IsExtensionLoaded),
		reinterpret_cast<void*>(&::GetPluginId),
		reinterpret_cast<void*>(&::GetPluginName),
		reinterpret_cast<void*>(&::GetPluginDescription),
		reinterpret_cast<void*>(&::GetPluginVersion),
		reinterpret_cast<void*>(&::GetPluginAuthor),
		reinterpret_cast<void*>(&::GetPluginWebsite),
		reinterpret_cast<void*>(&::GetPluginLicense),
		reinterpret_cast<void*>(&::GetPluginLocation),
		reinterpret_cast<void*>(&::GetPluginDependencies)
};

ILanguageModule* GetLanguageModule() {
	return &g_cpplm;
}
