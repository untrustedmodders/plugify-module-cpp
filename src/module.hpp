#pragma once

#include <plugify/assembly.hpp>
#include <plugify/language_module.hpp>
#include <plugify/extension.hpp>
#include <plugify/provider.hpp>

#include <api.hpp>
#include <module_export.h>

#include <unordered_map>
#include <map>
#include <array>

using namespace plugify;

namespace cpplm {
	using InitFunc = int (*)(void**, int, const void*);
	using StartFunc = void (*)();
	using UpdateFunc = void (*)(std::chrono::milliseconds);
	using EndFunc = void (*)();
	using ContextFunc = plg::PluginContext* (*)();

	struct AssemblyHolder {
		std::shared_ptr<IAssembly> assembly;
		UpdateFunc updateFunc;
		StartFunc startFunc;
		EndFunc endFunc;
		ContextFunc contextFunc;
	};

	class CppLanguageModule final : public ILanguageModule {
	public:
		CppLanguageModule() = default;

		// ILanguageModule
		Result<InitData> Initialize(const Provider& provider, const Extension& module) override;
		void Shutdown() override;
		void OnUpdate(std::chrono::milliseconds dt) override;
		void OnMethodExport(const Extension& plugin) override;
		Result<LoadData> OnPluginLoad(const Extension& plugin) override;
		void OnPluginStart(const Extension& plugin) override;
		void OnPluginUpdate(const Extension& plugin, std::chrono::milliseconds dt) override;
		void OnPluginEnd(const Extension& plugin) override;
		bool IsDebugBuild() override;

		const std::unique_ptr<Provider>& GetProvider() const { return _provider; }
		MemAddr GetNativeMethod(std::string_view methodName) const;
		void GetNativeMethod(std::string_view methodName, MemAddr* addressDest);

	private:
		std::unique_ptr<Provider> _provider;
		
		std::vector<std::unique_ptr<AssemblyHolder>> _assemblies;
		std::unordered_map<std::string, MemAddr, plg::string_hash, std::equal_to<>> _nativesMap;
		
		std::vector<MemAddr*> _addresses;

		static std::array<void*, 18> _pluginApi;
	};

	extern CppLanguageModule g_cpplm;
}

extern "C" CPPLM_EXPORT ILanguageModule* GetLanguageModule();