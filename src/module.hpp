#pragma once

#include <plugify/assembly.hpp>
#include <plugify/language_module.hpp>
#include <plugify/assembly_loader.hpp>
#include <plugify/logger.hpp>
#include <plugify/extension.hpp>
#include <plugify/provider.hpp>

#include <api.hpp>
#include <module_export.h>

using namespace plugify;

namespace cpplm {
	using InitFunc = int (*)(void**, size_t, int, const void*);
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
		const std::shared_ptr<ILogger>& GetLogger() const { return _logger; }

	private:
		std::unique_ptr<Provider> _provider;
		std::shared_ptr<ILogger> _logger;
		std::shared_ptr<IAssemblyLoader> _loader;
		std::vector<std::unique_ptr<AssemblyHolder>> _assemblies;

		static std::array<void*, 17> _pluginApi;
	};

	extern CppLanguageModule g_cpplm;
}

extern "C" CPPLM_EXPORT ILanguageModule* GetLanguageModule();