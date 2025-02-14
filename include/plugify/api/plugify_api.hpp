#pragma once

#include <cstdint>

namespace plg {
	constexpr int32_t kApiVersion = 1;

	extern "C" struct PluginResult {
		int32_t version;
		bool debug;
	};
}