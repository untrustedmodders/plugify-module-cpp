#pragma once

#include <cstdint>
#include <string_view>

namespace plg {
	constexpr int kApiVersion = 1;

	extern "C" {
		struct PluginContext {
			bool hasUpdate{};
			bool hasStart{};
			bool hasEnd{};
			bool hasDebug{};
		};
	}
}

namespace std::filesystem {
#if _WIN32
	using path_view = std::wstring_view;
#else
	using path_view = std::string_view;
#endif
} // namespace std::filesystem
