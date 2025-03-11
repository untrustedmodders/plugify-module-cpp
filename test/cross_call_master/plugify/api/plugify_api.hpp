#pragma once

#include <cstdint>

namespace plg {
	constexpr int kApiVersion = 1;

	struct PluginContext {
		bool hasUpdate{};
		bool hasStart{};
		bool hasEnd{};
		bool hasDebug{};
	};
}