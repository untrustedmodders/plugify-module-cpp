#include <plugify/assembly.hpp>
#include <plugify/language_module.hpp>
#include <plugify/module.hpp>
#include <plugify/plugify_provider.hpp>
#include <plugify/plugin.hpp>
#include <plugify_api.hpp>

#include <module_export.h>
#include <unordered_map>
#include <map>
#include <array>

namespace cpplm {
	struct string_hash {
		using is_transparent = void;
		[[nodiscard]] size_t operator()(const char* txt) const {
			return std::hash<std::string_view>{}(txt);
		}
		[[nodiscard]] size_t operator()(std::string_view txt) const {
			return std::hash<std::string_view>{}(txt);
		}
		[[nodiscard]] size_t operator()(const std::string& txt) const {
			return std::hash<std::string>{}(txt);
		}
	};

	using InitFunc = int (*)(void**, int, const void*);
	using StartFunc = void (*)();
	using UpdateFunc = void (*)(float);
	using EndFunc = void (*)();
	using ContextFunc = plg::PluginContext* (*)();

	struct AssemblyHolder {
		std::unique_ptr<plugify::Assembly> assembly;
		UpdateFunc updateFunc;
		StartFunc startFunc;
		EndFunc endFunc;
		ContextFunc contextFunc;
	};

	class CppLanguageModule final : public plugify::ILanguageModule {
	public:
		CppLanguageModule() = default;

		// ILanguageModule
		plugify::InitResult Initialize(std::weak_ptr<plugify::IPlugifyProvider> provider, plugify::ModuleHandle module) override;
		void Shutdown() override;
		void OnUpdate(plugify::DateTime dt) override;
		void OnMethodExport(plugify::PluginHandle plugin) override;
		plugify::LoadResult OnPluginLoad(plugify::PluginHandle plugin) override;
		void OnPluginStart(plugify::PluginHandle plugin) override;
		void OnPluginUpdate(plugify::PluginHandle plugin, plugify::DateTime dt) override;
		void OnPluginEnd(plugify::PluginHandle plugin) override;
		bool IsDebugBuild() override;

		const std::shared_ptr<plugify::IPlugifyProvider>& GetProvider() const { return _provider; }
		plugify::MemAddr GetNativeMethod(std::string_view methodName) const;
		void GetNativeMethod(std::string_view methodName, plugify::MemAddr* addressDest);

	private:
		std::shared_ptr<plugify::IPlugifyProvider> _provider;
		
		std::vector<std::unique_ptr<AssemblyHolder>> _assemblies;
		std::unordered_map<std::string, plugify::MemAddr, string_hash, std::equal_to<>> _nativesMap;
		
		std::vector<plugify::MemAddr*> _addresses;

		static std::array<void*, 17> _pluginApi;
	};

	extern CppLanguageModule g_cpplm;
}

extern "C" CPPLM_EXPORT plugify::ILanguageModule* GetLanguageModule();