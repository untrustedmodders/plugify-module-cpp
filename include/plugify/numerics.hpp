#pragma once

#include <plugify/vector.hpp>
#include <plugify/string.hpp>

namespace plg {
	PLUGIFY_WARN_PUSH()

#if defined(__clang__)
	PLUGIFY_WARN_IGNORE("-Wgnu-anonymous-struct")
	PLUGIFY_WARN_IGNORE("-Wnested-anon-types")
#elif defined(__GNUC__)
	PLUGIFY_WARN_IGNORE("-Wpedantic")
#elif defined(_MSC_VER)
	PLUGIFY_WARN_IGNORE(4201)
#endif

	extern "C" {
		struct vec2 {
			union {
				struct {
					float x;
					float y;
				};
				float data[2];
			};
		};

		struct vec3 {
			union {
				struct {
					float x;
					float y;
					float z;
				};
				float data[3];
			};
		};

		struct vec4 {
			union {
				struct {
					float x;
					float y;
					float z;
					float w;
				};
				float data[4];
			};
		};

		struct mat4x4 {
			union {
				struct {
					float m00, m01, m02, m03;
					float m10, m11, m12, m13;
					float m20, m21, m22, m23;
					float m30, m31, m32, m33;
				};
				float data[4][4];
			};
		};
	}

	PLUGIFY_WARN_POP()

	[[nodiscard]] constexpr bool operator==(const vec2& lhs, const vec2& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	[[nodiscard]] constexpr bool operator==(const vec3& lhs, const vec3& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	[[nodiscard]] constexpr bool operator==(const vec4& lhs, const vec4& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	[[nodiscard]] constexpr bool operator==(const mat4x4& lhs, const mat4x4& rhs) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (lhs.data[i][j] != rhs.data[i][j])
					return false;
			}
		}
		return true;
	}
} // namespace plg