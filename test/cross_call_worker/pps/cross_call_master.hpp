#pragma once

#include <plugify/cpp_plugin.hpp>
#include <plugify/any.hpp>
#include <cstdint>

// Generated from cross_call_master.pplugin by https://github.com/untrustedmodders/plugify-module-cpp/blob/main/generator/generator.py

namespace cross_call_master {
	enum class Example : int32_t {
		First = 1,
		Second = 2,
		Third = 3,
		Forth = 4,
	};

	using NoParamReturnFunctionCallbackFunc = int32_t (*)();
	using FuncVoid = void (*)();
	using FuncBool = bool (*)();
	using FuncChar8 = char (*)();
	using FuncChar16 = char16_t (*)();
	using FuncInt8 = int8_t (*)();
	using FuncInt16 = int16_t (*)();
	using FuncInt32 = int32_t (*)();
	using FuncInt64 = int64_t (*)();
	using FuncUInt8 = uint8_t (*)();
	using FuncUInt16 = uint16_t (*)();
	using FuncUInt32 = uint32_t (*)();
	using FuncUInt64 = uint64_t (*)();
	using FuncPtr = void* (*)();
	using FuncFloat = float (*)();
	using FuncDouble = double (*)();
	using FuncString = plg::string (*)();
	using FuncAny = plg::any (*)();
	using FuncFunction = void* (*)();
	using FuncBoolVector = plg::vector<bool> (*)();
	using FuncChar8Vector = plg::vector<char> (*)();
	using FuncChar16Vector = plg::vector<char16_t> (*)();
	using FuncInt8Vector = plg::vector<int8_t> (*)();
	using FuncInt16Vector = plg::vector<int16_t> (*)();
	using FuncInt32Vector = plg::vector<int32_t> (*)();
	using FuncInt64Vector = plg::vector<int64_t> (*)();
	using FuncUInt8Vector = plg::vector<uint8_t> (*)();
	using FuncUInt16Vector = plg::vector<uint16_t> (*)();
	using FuncUInt32Vector = plg::vector<uint32_t> (*)();
	using FuncUInt64Vector = plg::vector<uint64_t> (*)();
	using FuncPtrVector = plg::vector<void*> (*)();
	using FuncFloatVector = plg::vector<float> (*)();
	using FuncDoubleVector = plg::vector<double> (*)();
	using FuncStringVector = plg::vector<plg::string> (*)();
	using FuncAnyVector = plg::vector<plg::any> (*)();
	using FuncVec2Vector = plg::vector<plg::vec2> (*)();
	using FuncVec3Vector = plg::vector<plg::vec3> (*)();
	using FuncVec4Vector = plg::vector<plg::vec4> (*)();
	using FuncMat4x4Vector = plg::vector<plg::mat4x4> (*)();
	using FuncVec2 = plg::vec2 (*)();
	using FuncVec3 = plg::vec3 (*)();
	using FuncVec4 = plg::vec4 (*)();
	using FuncMat4x4 = plg::mat4x4 (*)();
	using Func1 = int32_t (*)(const plg::vec3&);
	using Func2 = char (*)(float, int64_t);
	using Func3 = void (*)(void*, const plg::vec4&, const plg::string&);
	using Func4 = plg::vec4 (*)(bool, int32_t, char16_t, const plg::mat4x4&);
	using Func5 = bool (*)(int8_t, const plg::vec2&, void*, double, const plg::vector<uint64_t>&);
	using Func6 = int64_t (*)(const plg::string&, float, const plg::vector<float>&, int16_t, const plg::vector<uint8_t>&, void*);
	using Func7 = double (*)(const plg::vector<char>&, uint16_t, char16_t, const plg::vector<uint32_t>&, const plg::vec4&, bool, uint64_t);
	using Func8 = plg::mat4x4 (*)(const plg::vec3&, const plg::vector<uint32_t>&, int16_t, bool, const plg::vec4&, const plg::vector<char16_t>&, char16_t, int32_t);
	using Func9 = void (*)(float, const plg::vec2&, const plg::vector<int8_t>&, uint64_t, bool, const plg::string&, const plg::vec4&, int16_t, void*);
	using Func10 = uint32_t (*)(const plg::vec4&, const plg::mat4x4&, const plg::vector<uint32_t>&, uint64_t, const plg::vector<char>&, int32_t, bool, const plg::vec2&, int64_t, double);
	using Func11 = void* (*)(const plg::vector<bool>&, char16_t, uint8_t, double, const plg::vec3&, const plg::vector<int8_t>&, int64_t, uint16_t, float, const plg::vec2&, uint32_t);
	using Func12 = bool (*)(void*, const plg::vector<double>&, uint32_t, double, bool, int32_t, int8_t, uint64_t, float, const plg::vector<void*>&, int64_t, char);
	using Func13 = plg::string (*)(int64_t, const plg::vector<char>&, uint16_t, float, const plg::vector<bool>&, const plg::vec4&, const plg::string&, int32_t, const plg::vec3&, void*, const plg::vec2&, const plg::vector<uint8_t>&, int16_t);
	using Func14 = plg::vector<plg::string> (*)(const plg::vector<char>&, const plg::vector<uint32_t>&, const plg::mat4x4&, bool, char16_t, int32_t, const plg::vector<float>&, uint16_t, const plg::vector<uint8_t>&, int8_t, const plg::vec3&, const plg::vec4&, double, void*);
	using Func15 = int16_t (*)(const plg::vector<int16_t>&, const plg::mat4x4&, const plg::vec4&, void*, uint64_t, const plg::vector<uint32_t>&, bool, float, const plg::vector<char16_t>&, uint8_t, int32_t, const plg::vec2&, uint16_t, double, const plg::vector<uint8_t>&);
	using Func16 = void* (*)(const plg::vector<bool>&, int16_t, const plg::vector<int8_t>&, const plg::vec4&, const plg::mat4x4&, const plg::vec2&, const plg::vector<uint64_t>&, const plg::vector<char>&, const plg::string&, int64_t, const plg::vector<uint32_t>&, const plg::vec3&, float, double, int8_t, uint16_t);
	using Func17 = void (*)(int32_t&);
	using Func18 = plg::vec2 (*)(int8_t&, int16_t&);
	using Func19 = void (*)(uint32_t&, plg::vec3&, plg::vector<uint32_t>&);
	using Func20 = int32_t (*)(char16_t&, plg::vec4&, plg::vector<uint64_t>&, char&);
	using Func21 = float (*)(plg::mat4x4&, plg::vector<int32_t>&, plg::vec2&, bool&, double&);
	using Func22 = uint64_t (*)(void*&, uint32_t&, plg::vector<double>&, int16_t&, plg::string&, plg::vec4&);
	using Func23 = void (*)(uint64_t&, plg::vec2&, plg::vector<int16_t>&, char16_t&, float&, int8_t&, plg::vector<uint8_t>&);
	using Func24 = plg::mat4x4 (*)(plg::vector<char>&, int64_t&, plg::vector<uint8_t>&, plg::vec4&, uint64_t&, plg::vector<void*>&, double&, plg::vector<void*>&);
	using Func25 = double (*)(int32_t&, plg::vector<void*>&, bool&, uint8_t&, plg::string&, plg::vec3&, int64_t&, plg::vec4&, uint16_t&);
	using Func26 = char (*)(char16_t&, plg::vec2&, plg::mat4x4&, plg::vector<float>&, int16_t&, uint64_t&, uint32_t&, plg::vector<uint16_t>&, void*&, bool&);
	using Func27 = uint8_t (*)(float&, plg::vec3&, void*&, plg::vec2&, plg::vector<int16_t>&, plg::mat4x4&, bool&, plg::vec4&, int8_t&, int32_t&, plg::vector<uint8_t>&);
	using Func28 = plg::string (*)(void*&, uint16_t&, plg::vector<uint32_t>&, plg::mat4x4&, float&, plg::vec4&, plg::string&, plg::vector<uint64_t>&, int64_t&, bool&, plg::vec3&, plg::vector<float>&);
	using Func29 = plg::vector<plg::string> (*)(plg::vec4&, int32_t&, plg::vector<int8_t>&, double&, bool&, int8_t&, plg::vector<uint16_t>&, float&, plg::string&, plg::mat4x4&, uint64_t&, plg::vec3&, plg::vector<int64_t>&);
	using Func30 = int32_t (*)(void*&, plg::vec4&, int64_t&, plg::vector<uint32_t>&, bool&, plg::string&, plg::vec3&, plg::vector<uint8_t>&, float&, plg::vec2&, plg::mat4x4&, int8_t&, plg::vector<float>&, double&);
	using Func31 = plg::vec3 (*)(char&, uint32_t&, plg::vector<uint64_t>&, plg::vec4&, plg::string&, bool&, int64_t&, plg::vec2&, int8_t&, uint16_t&, plg::vector<int16_t>&, plg::mat4x4&, plg::vec3&, float&, plg::vector<double>&);
	using Func32 = double (*)(int32_t&, uint16_t&, plg::vector<int8_t>&, plg::vec4&, void*&, plg::vector<uint32_t>&, plg::mat4x4&, uint64_t&, plg::string&, int64_t&, plg::vec2&, plg::vector<int8_t>&, bool&, plg::vec3&, uint8_t&, plg::vector<char16_t>&);
	using Func33 = void (*)(plg::any&);
	using FuncEnum = plg::vector<Example> (*)(Example, plg::vector<Example>&);

	/**
	 * @brief No description provided.
	 *
	 * @function ReverseReturn
	 * @param returnString (string): No description available.
	 */
	inline void ReverseReturn(const plg::string& returnString) {
		using ReverseReturnFn = void (*)(const plg::string&);
		static ReverseReturnFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ReverseReturn", reinterpret_cast<void**>(&__func));
		__func(returnString);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnVoidCallback
	 */
	inline void NoParamReturnVoidCallback() {
		using NoParamReturnVoidCallbackFn = void (*)();
		static NoParamReturnVoidCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVoidCallback", reinterpret_cast<void**>(&__func));
		__func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnBoolCallback
	 *
	 * @return bool: No description available.
	 */
	inline bool NoParamReturnBoolCallback() {
		using NoParamReturnBoolCallbackFn = bool (*)();
		static NoParamReturnBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnBoolCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnChar8Callback
	 *
	 * @return char8: No description available.
	 */
	inline char NoParamReturnChar8Callback() {
		using NoParamReturnChar8CallbackFn = char (*)();
		static NoParamReturnChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnChar8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnChar16Callback
	 *
	 * @return char16: No description available.
	 */
	inline char16_t NoParamReturnChar16Callback() {
		using NoParamReturnChar16CallbackFn = char16_t (*)();
		static NoParamReturnChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnChar16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnInt8Callback
	 *
	 * @return int8: No description available.
	 */
	inline int8_t NoParamReturnInt8Callback() {
		using NoParamReturnInt8CallbackFn = int8_t (*)();
		static NoParamReturnInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnInt16Callback
	 *
	 * @return int16: No description available.
	 */
	inline int16_t NoParamReturnInt16Callback() {
		using NoParamReturnInt16CallbackFn = int16_t (*)();
		static NoParamReturnInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnInt32Callback
	 *
	 * @return int32: No description available.
	 */
	inline int32_t NoParamReturnInt32Callback() {
		using NoParamReturnInt32CallbackFn = int32_t (*)();
		static NoParamReturnInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnInt64Callback
	 *
	 * @return int64: No description available.
	 */
	inline int64_t NoParamReturnInt64Callback() {
		using NoParamReturnInt64CallbackFn = int64_t (*)();
		static NoParamReturnInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnUInt8Callback
	 *
	 * @return uint8: No description available.
	 */
	inline uint8_t NoParamReturnUInt8Callback() {
		using NoParamReturnUInt8CallbackFn = uint8_t (*)();
		static NoParamReturnUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnUInt16Callback
	 *
	 * @return uint16: No description available.
	 */
	inline uint16_t NoParamReturnUInt16Callback() {
		using NoParamReturnUInt16CallbackFn = uint16_t (*)();
		static NoParamReturnUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnUInt32Callback
	 *
	 * @return uint32: No description available.
	 */
	inline uint32_t NoParamReturnUInt32Callback() {
		using NoParamReturnUInt32CallbackFn = uint32_t (*)();
		static NoParamReturnUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnUInt64Callback
	 *
	 * @return uint64: No description available.
	 */
	inline uint64_t NoParamReturnUInt64Callback() {
		using NoParamReturnUInt64CallbackFn = uint64_t (*)();
		static NoParamReturnUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnPointerCallback
	 *
	 * @return ptr64: No description available.
	 */
	inline void* NoParamReturnPointerCallback() {
		using NoParamReturnPointerCallbackFn = void* (*)();
		static NoParamReturnPointerCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnPointerCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnFloatCallback
	 *
	 * @return float: No description available.
	 */
	inline float NoParamReturnFloatCallback() {
		using NoParamReturnFloatCallbackFn = float (*)();
		static NoParamReturnFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnFloatCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnDoubleCallback
	 *
	 * @return double: No description available.
	 */
	inline double NoParamReturnDoubleCallback() {
		using NoParamReturnDoubleCallbackFn = double (*)();
		static NoParamReturnDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnFunctionCallback
	 *
	 * @return function: No description available.
	 */
	inline NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
		using NoParamReturnFunctionCallbackFn = NoParamReturnFunctionCallbackFunc (*)();
		static NoParamReturnFunctionCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnFunctionCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnStringCallback
	 *
	 * @return string: No description available.
	 */
	inline plg::string NoParamReturnStringCallback() {
		using NoParamReturnStringCallbackFn = plg::string (*)();
		static NoParamReturnStringCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnStringCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnAnyCallback
	 *
	 * @return any: No description available.
	 */
	inline plg::any NoParamReturnAnyCallback() {
		using NoParamReturnAnyCallbackFn = plg::any (*)();
		static NoParamReturnAnyCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnAnyCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayBoolCallback
	 *
	 * @return bool[]: No description available.
	 */
	inline plg::vector<bool> NoParamReturnArrayBoolCallback() {
		using NoParamReturnArrayBoolCallbackFn = plg::vector<bool> (*)();
		static NoParamReturnArrayBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayBoolCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayChar8Callback
	 *
	 * @return char8[]: No description available.
	 */
	inline plg::vector<char> NoParamReturnArrayChar8Callback() {
		using NoParamReturnArrayChar8CallbackFn = plg::vector<char> (*)();
		static NoParamReturnArrayChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayChar8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayChar16Callback
	 *
	 * @return char16[]: No description available.
	 */
	inline plg::vector<char16_t> NoParamReturnArrayChar16Callback() {
		using NoParamReturnArrayChar16CallbackFn = plg::vector<char16_t> (*)();
		static NoParamReturnArrayChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayChar16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayInt8Callback
	 *
	 * @return int8[]: No description available.
	 */
	inline plg::vector<int8_t> NoParamReturnArrayInt8Callback() {
		using NoParamReturnArrayInt8CallbackFn = plg::vector<int8_t> (*)();
		static NoParamReturnArrayInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayInt16Callback
	 *
	 * @return int16[]: No description available.
	 */
	inline plg::vector<int16_t> NoParamReturnArrayInt16Callback() {
		using NoParamReturnArrayInt16CallbackFn = plg::vector<int16_t> (*)();
		static NoParamReturnArrayInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayInt32Callback
	 *
	 * @return int32[]: No description available.
	 */
	inline plg::vector<int32_t> NoParamReturnArrayInt32Callback() {
		using NoParamReturnArrayInt32CallbackFn = plg::vector<int32_t> (*)();
		static NoParamReturnArrayInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayInt64Callback
	 *
	 * @return int64[]: No description available.
	 */
	inline plg::vector<int64_t> NoParamReturnArrayInt64Callback() {
		using NoParamReturnArrayInt64CallbackFn = plg::vector<int64_t> (*)();
		static NoParamReturnArrayInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayUInt8Callback
	 *
	 * @return uint8[]: No description available.
	 */
	inline plg::vector<uint8_t> NoParamReturnArrayUInt8Callback() {
		using NoParamReturnArrayUInt8CallbackFn = plg::vector<uint8_t> (*)();
		static NoParamReturnArrayUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayUInt16Callback
	 *
	 * @return uint16[]: No description available.
	 */
	inline plg::vector<uint16_t> NoParamReturnArrayUInt16Callback() {
		using NoParamReturnArrayUInt16CallbackFn = plg::vector<uint16_t> (*)();
		static NoParamReturnArrayUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayUInt32Callback
	 *
	 * @return uint32[]: No description available.
	 */
	inline plg::vector<uint32_t> NoParamReturnArrayUInt32Callback() {
		using NoParamReturnArrayUInt32CallbackFn = plg::vector<uint32_t> (*)();
		static NoParamReturnArrayUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayUInt64Callback
	 *
	 * @return uint64[]: No description available.
	 */
	inline plg::vector<uint64_t> NoParamReturnArrayUInt64Callback() {
		using NoParamReturnArrayUInt64CallbackFn = plg::vector<uint64_t> (*)();
		static NoParamReturnArrayUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayPointerCallback
	 *
	 * @return ptr64[]: No description available.
	 */
	inline plg::vector<void*> NoParamReturnArrayPointerCallback() {
		using NoParamReturnArrayPointerCallbackFn = plg::vector<void*> (*)();
		static NoParamReturnArrayPointerCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayPointerCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayFloatCallback
	 *
	 * @return float[]: No description available.
	 */
	inline plg::vector<float> NoParamReturnArrayFloatCallback() {
		using NoParamReturnArrayFloatCallbackFn = plg::vector<float> (*)();
		static NoParamReturnArrayFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayFloatCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayDoubleCallback
	 *
	 * @return double[]: No description available.
	 */
	inline plg::vector<double> NoParamReturnArrayDoubleCallback() {
		using NoParamReturnArrayDoubleCallbackFn = plg::vector<double> (*)();
		static NoParamReturnArrayDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayStringCallback
	 *
	 * @return string[]: No description available.
	 */
	inline plg::vector<plg::string> NoParamReturnArrayStringCallback() {
		using NoParamReturnArrayStringCallbackFn = plg::vector<plg::string> (*)();
		static NoParamReturnArrayStringCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayStringCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayAnyCallback
	 *
	 * @return any[]: No description available.
	 */
	inline plg::vector<plg::any> NoParamReturnArrayAnyCallback() {
		using NoParamReturnArrayAnyCallbackFn = plg::vector<plg::any> (*)();
		static NoParamReturnArrayAnyCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayAnyCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayVector2Callback
	 *
	 * @return vec2[]: No description available.
	 */
	inline plg::vector<plg::vec2> NoParamReturnArrayVector2Callback() {
		using NoParamReturnArrayVector2CallbackFn = plg::vector<plg::vec2> (*)();
		static NoParamReturnArrayVector2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayVector2Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayVector3Callback
	 *
	 * @return vec3[]: No description available.
	 */
	inline plg::vector<plg::vec3> NoParamReturnArrayVector3Callback() {
		using NoParamReturnArrayVector3CallbackFn = plg::vector<plg::vec3> (*)();
		static NoParamReturnArrayVector3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayVector3Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayVector4Callback
	 *
	 * @return vec4[]: No description available.
	 */
	inline plg::vector<plg::vec4> NoParamReturnArrayVector4Callback() {
		using NoParamReturnArrayVector4CallbackFn = plg::vector<plg::vec4> (*)();
		static NoParamReturnArrayVector4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayVector4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnArrayMatrix4x4Callback
	 *
	 * @return mat4x4[]: No description available.
	 */
	inline plg::vector<plg::mat4x4> NoParamReturnArrayMatrix4x4Callback() {
		using NoParamReturnArrayMatrix4x4CallbackFn = plg::vector<plg::mat4x4> (*)();
		static NoParamReturnArrayMatrix4x4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayMatrix4x4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnVector2Callback
	 *
	 * @return vec2: No description available.
	 */
	inline plg::vec2 NoParamReturnVector2Callback() {
		using NoParamReturnVector2CallbackFn = plg::vec2 (*)();
		static NoParamReturnVector2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVector2Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnVector3Callback
	 *
	 * @return vec3: No description available.
	 */
	inline plg::vec3 NoParamReturnVector3Callback() {
		using NoParamReturnVector3CallbackFn = plg::vec3 (*)();
		static NoParamReturnVector3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVector3Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnVector4Callback
	 *
	 * @return vec4: No description available.
	 */
	inline plg::vec4 NoParamReturnVector4Callback() {
		using NoParamReturnVector4CallbackFn = plg::vec4 (*)();
		static NoParamReturnVector4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVector4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function NoParamReturnMatrix4x4Callback
	 *
	 * @return mat4x4: No description available.
	 */
	inline plg::mat4x4 NoParamReturnMatrix4x4Callback() {
		using NoParamReturnMatrix4x4CallbackFn = plg::mat4x4 (*)();
		static NoParamReturnMatrix4x4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnMatrix4x4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param1Callback
	 * @param a (int32): No description available.
	 */
	inline void Param1Callback(int32_t a) {
		using Param1CallbackFn = void (*)(int32_t);
		static Param1CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param1Callback", reinterpret_cast<void**>(&__func));
		__func(a);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param2Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 */
	inline void Param2Callback(int32_t a, float b) {
		using Param2CallbackFn = void (*)(int32_t, float);
		static Param2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param2Callback", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param3Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 */
	inline void Param3Callback(int32_t a, float b, double c) {
		using Param3CallbackFn = void (*)(int32_t, float, double);
		static Param3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param3Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param4Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 */
	inline void Param4Callback(int32_t a, float b, double c, const plg::vec4& d) {
		using Param4CallbackFn = void (*)(int32_t, float, double, const plg::vec4&);
		static Param4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param4Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param5Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 */
	inline void Param5Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e) {
		using Param5CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&);
		static Param5CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param5Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param6Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 */
	inline void Param6Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f) {
		using Param6CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char);
		static Param6CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param6Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param7Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 */
	inline void Param7Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g) {
		using Param7CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&);
		static Param7CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param7Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param8Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 * @param h (char16): No description available.
	 */
	inline void Param8Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
		using Param8CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t);
		static Param8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param8Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param9Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 * @param h (char16): No description available.
	 * @param k (int16): No description available.
	 */
	inline void Param9Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
		using Param9CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t);
		static Param9CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param9Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function Param10Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 * @param h (char16): No description available.
	 * @param k (int16): No description available.
	 * @param l (ptr64): No description available.
	 */
	inline void Param10Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
		using Param10CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t, void*);
		static Param10CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param10Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef1Callback
	 * @param a (int32): No description available.
	 */
	inline void ParamRef1Callback(int32_t& a) {
		using ParamRef1CallbackFn = void (*)(int32_t&);
		static ParamRef1CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef1Callback", reinterpret_cast<void**>(&__func));
		__func(a);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef2Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 */
	inline void ParamRef2Callback(int32_t& a, float& b) {
		using ParamRef2CallbackFn = void (*)(int32_t&, float&);
		static ParamRef2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef2Callback", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef3Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 */
	inline void ParamRef3Callback(int32_t& a, float& b, double& c) {
		using ParamRef3CallbackFn = void (*)(int32_t&, float&, double&);
		static ParamRef3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef3Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef4Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 */
	inline void ParamRef4Callback(int32_t& a, float& b, double& c, plg::vec4& d) {
		using ParamRef4CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&);
		static ParamRef4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef4Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef5Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 */
	inline void ParamRef5Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e) {
		using ParamRef5CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&);
		static ParamRef5CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef5Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef6Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 */
	inline void ParamRef6Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f) {
		using ParamRef6CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&);
		static ParamRef6CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef6Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef7Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 */
	inline void ParamRef7Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g) {
		using ParamRef7CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&);
		static ParamRef7CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef7Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef8Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 * @param h (char16): No description available.
	 */
	inline void ParamRef8Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
		using ParamRef8CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&);
		static ParamRef8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef8Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef9Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 * @param h (char16): No description available.
	 * @param k (int16): No description available.
	 */
	inline void ParamRef9Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
		using ParamRef9CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&);
		static ParamRef9CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef9Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRef10Callback
	 * @param a (int32): No description available.
	 * @param b (float): No description available.
	 * @param c (double): No description available.
	 * @param d (vec4): No description available.
	 * @param e (int64[]): No description available.
	 * @param f (char8): No description available.
	 * @param g (string): No description available.
	 * @param h (char16): No description available.
	 * @param k (int16): No description available.
	 * @param l (ptr64): No description available.
	 */
	inline void ParamRef10Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
		using ParamRef10CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&, void*&);
		static ParamRef10CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef10Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamRefVectorsCallback
	 * @param p1 (bool[]): No description available.
	 * @param p2 (char8[]): No description available.
	 * @param p3 (char16[]): No description available.
	 * @param p4 (int8[]): No description available.
	 * @param p5 (int16[]): No description available.
	 * @param p6 (int32[]): No description available.
	 * @param p7 (int64[]): No description available.
	 * @param p8 (uint8[]): No description available.
	 * @param p9 (uint16[]): No description available.
	 * @param p10 (uint32[]): No description available.
	 * @param p11 (uint64[]): No description available.
	 * @param p12 (ptr64[]): No description available.
	 * @param p13 (float[]): No description available.
	 * @param p14 (double[]): No description available.
	 * @param p15 (string[]): No description available.
	 */
	inline void ParamRefVectorsCallback(plg::vector<bool>& p1, plg::vector<char>& p2, plg::vector<char16_t>& p3, plg::vector<int8_t>& p4, plg::vector<int16_t>& p5, plg::vector<int32_t>& p6, plg::vector<int64_t>& p7, plg::vector<uint8_t>& p8, plg::vector<uint16_t>& p9, plg::vector<uint32_t>& p10, plg::vector<uint64_t>& p11, plg::vector<void*>& p12, plg::vector<float>& p13, plg::vector<double>& p14, plg::vector<plg::string>& p15) {
		using ParamRefVectorsCallbackFn = void (*)(plg::vector<bool>&, plg::vector<char>&, plg::vector<char16_t>&, plg::vector<int8_t>&, plg::vector<int16_t>&, plg::vector<int32_t>&, plg::vector<int64_t>&, plg::vector<uint8_t>&, plg::vector<uint16_t>&, plg::vector<uint32_t>&, plg::vector<uint64_t>&, plg::vector<void*>&, plg::vector<float>&, plg::vector<double>&, plg::vector<plg::string>&);
		static ParamRefVectorsCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRefVectorsCallback", reinterpret_cast<void**>(&__func));
		__func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamAllPrimitivesCallback
	 * @param p1 (bool): No description available.
	 * @param p2 (char8): No description available.
	 * @param p3 (char16): No description available.
	 * @param p4 (int8): No description available.
	 * @param p5 (int16): No description available.
	 * @param p6 (int32): No description available.
	 * @param p7 (int64): No description available.
	 * @param p8 (uint8): No description available.
	 * @param p9 (uint16): No description available.
	 * @param p10 (uint32): No description available.
	 * @param p11 (uint64): No description available.
	 * @param p12 (ptr64): No description available.
	 * @param p13 (float): No description available.
	 * @param p14 (double): No description available.
	 *
	 * @return int64: No description available.
	 */
	inline int64_t ParamAllPrimitivesCallback(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
		using ParamAllPrimitivesCallbackFn = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
		static ParamAllPrimitivesCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamAllPrimitivesCallback", reinterpret_cast<void**>(&__func));
		return __func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamEnumCallback
	 * @param p1 (int32): No description available.
	 * @param p2 (int32[]): No description available.
	 *
	 * @return int32: No description available.
	 */
	inline int32_t ParamEnumCallback(Example p1, const plg::vector<Example>& p2) {
		using ParamEnumCallbackFn = int32_t (*)(Example, const plg::vector<Example>&);
		static ParamEnumCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamEnumCallback", reinterpret_cast<void**>(&__func));
		return __func(p1, p2);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamEnumRefCallback
	 * @param p1 (int32): No description available.
	 * @param p2 (int32[]): No description available.
	 *
	 * @return int32: No description available.
	 */
	inline int32_t ParamEnumRefCallback(Example& p1, plg::vector<Example>& p2) {
		using ParamEnumRefCallbackFn = int32_t (*)(Example&, plg::vector<Example>&);
		static ParamEnumRefCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamEnumRefCallback", reinterpret_cast<void**>(&__func));
		return __func(p1, p2);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamVariantCallback
	 * @param p1 (any): No description available.
	 * @param p2 (any[]): No description available.
	 */
	inline void ParamVariantCallback(const plg::any& p1, const plg::vector<plg::any>& p2) {
		using ParamVariantCallbackFn = void (*)(const plg::any&, const plg::vector<plg::any>&);
		static ParamVariantCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamVariantCallback", reinterpret_cast<void**>(&__func));
		__func(p1, p2);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function ParamVariantRefCallback
	 * @param p1 (any): No description available.
	 * @param p2 (any[]): No description available.
	 */
	inline void ParamVariantRefCallback(plg::any& p1, plg::vector<plg::any>& p2) {
		using ParamVariantRefCallbackFn = void (*)(plg::any&, plg::vector<plg::any>&);
		static ParamVariantRefCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamVariantRefCallback", reinterpret_cast<void**>(&__func));
		__func(p1, p2);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVoidCallback
	 * @param func (function): No description available.
	 *
	 * @callback FuncVoid
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): void: No description available.
	 */
	inline void CallFuncVoidCallback(FuncVoid func) {
		using CallFuncVoidCallbackFn = void (*)(FuncVoid);
		static CallFuncVoidCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVoidCallback", reinterpret_cast<void**>(&__func));
		__func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncBoolCallback
	 * @param func (function): No description available.
	 *
	 * @return bool: No description available.
	 *
	 * @callback FuncBool
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): bool: No description available.
	 */
	inline bool CallFuncBoolCallback(FuncBool func) {
		using CallFuncBoolCallbackFn = bool (*)(FuncBool);
		static CallFuncBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncBoolCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncChar8Callback
	 * @param func (function): No description available.
	 *
	 * @return char8: No description available.
	 *
	 * @callback FuncChar8
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): char8: No description available.
	 */
	inline char CallFuncChar8Callback(FuncChar8 func) {
		using CallFuncChar8CallbackFn = char (*)(FuncChar8);
		static CallFuncChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncChar16Callback
	 * @param func (function): No description available.
	 *
	 * @return char16: No description available.
	 *
	 * @callback FuncChar16
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): char16: No description available.
	 */
	inline char16_t CallFuncChar16Callback(FuncChar16 func) {
		using CallFuncChar16CallbackFn = char16_t (*)(FuncChar16);
		static CallFuncChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt8Callback
	 * @param func (function): No description available.
	 *
	 * @return int8: No description available.
	 *
	 * @callback FuncInt8
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int8: No description available.
	 */
	inline int8_t CallFuncInt8Callback(FuncInt8 func) {
		using CallFuncInt8CallbackFn = int8_t (*)(FuncInt8);
		static CallFuncInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt16Callback
	 * @param func (function): No description available.
	 *
	 * @return int16: No description available.
	 *
	 * @callback FuncInt16
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int16: No description available.
	 */
	inline int16_t CallFuncInt16Callback(FuncInt16 func) {
		using CallFuncInt16CallbackFn = int16_t (*)(FuncInt16);
		static CallFuncInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt32Callback
	 * @param func (function): No description available.
	 *
	 * @return int32: No description available.
	 *
	 * @callback FuncInt32
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int32: No description available.
	 */
	inline int32_t CallFuncInt32Callback(FuncInt32 func) {
		using CallFuncInt32CallbackFn = int32_t (*)(FuncInt32);
		static CallFuncInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt32Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt64Callback
	 * @param func (function): No description available.
	 *
	 * @return int64: No description available.
	 *
	 * @callback FuncInt64
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int64: No description available.
	 */
	inline int64_t CallFuncInt64Callback(FuncInt64 func) {
		using CallFuncInt64CallbackFn = int64_t (*)(FuncInt64);
		static CallFuncInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt64Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt8Callback
	 * @param func (function): No description available.
	 *
	 * @return uint8: No description available.
	 *
	 * @callback FuncUInt8
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint8: No description available.
	 */
	inline uint8_t CallFuncUInt8Callback(FuncUInt8 func) {
		using CallFuncUInt8CallbackFn = uint8_t (*)(FuncUInt8);
		static CallFuncUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt16Callback
	 * @param func (function): No description available.
	 *
	 * @return uint16: No description available.
	 *
	 * @callback FuncUInt16
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint16: No description available.
	 */
	inline uint16_t CallFuncUInt16Callback(FuncUInt16 func) {
		using CallFuncUInt16CallbackFn = uint16_t (*)(FuncUInt16);
		static CallFuncUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt32Callback
	 * @param func (function): No description available.
	 *
	 * @return uint32: No description available.
	 *
	 * @callback FuncUInt32
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint32: No description available.
	 */
	inline uint32_t CallFuncUInt32Callback(FuncUInt32 func) {
		using CallFuncUInt32CallbackFn = uint32_t (*)(FuncUInt32);
		static CallFuncUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt64Callback
	 * @param func (function): No description available.
	 *
	 * @return uint64: No description available.
	 *
	 * @callback FuncUInt64
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint64: No description available.
	 */
	inline uint64_t CallFuncUInt64Callback(FuncUInt64 func) {
		using CallFuncUInt64CallbackFn = uint64_t (*)(FuncUInt64);
		static CallFuncUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncPtrCallback
	 * @param func (function): No description available.
	 *
	 * @return ptr64: No description available.
	 *
	 * @callback FuncPtr
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): ptr64: No description available.
	 */
	inline void* CallFuncPtrCallback(FuncPtr func) {
		using CallFuncPtrCallbackFn = void* (*)(FuncPtr);
		static CallFuncPtrCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncPtrCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncFloatCallback
	 * @param func (function): No description available.
	 *
	 * @return float: No description available.
	 *
	 * @callback FuncFloat
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): float: No description available.
	 */
	inline float CallFuncFloatCallback(FuncFloat func) {
		using CallFuncFloatCallbackFn = float (*)(FuncFloat);
		static CallFuncFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncFloatCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncDoubleCallback
	 * @param func (function): No description available.
	 *
	 * @return double: No description available.
	 *
	 * @callback FuncDouble
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): double: No description available.
	 */
	inline double CallFuncDoubleCallback(FuncDouble func) {
		using CallFuncDoubleCallbackFn = double (*)(FuncDouble);
		static CallFuncDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncStringCallback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback FuncString
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): string: No description available.
	 */
	inline plg::string CallFuncStringCallback(FuncString func) {
		using CallFuncStringCallbackFn = plg::string (*)(FuncString);
		static CallFuncStringCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncStringCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncAnyCallback
	 * @param func (function): No description available.
	 *
	 * @return any: No description available.
	 *
	 * @callback FuncAny
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): any: No description available.
	 */
	inline plg::any CallFuncAnyCallback(FuncAny func) {
		using CallFuncAnyCallbackFn = plg::any (*)(FuncAny);
		static CallFuncAnyCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncAnyCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncFunctionCallback
	 * @param func (function): No description available.
	 *
	 * @return ptr64: No description available.
	 *
	 * @callback FuncFunction
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): function: No description available.
	 */
	inline void* CallFuncFunctionCallback(FuncFunction func) {
		using CallFuncFunctionCallbackFn = void* (*)(FuncFunction);
		static CallFuncFunctionCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncFunctionCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncBoolVectorCallback
	 * @param func (function): No description available.
	 *
	 * @return bool[]: No description available.
	 *
	 * @callback FuncBoolVector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): bool[]: No description available.
	 */
	inline plg::vector<bool> CallFuncBoolVectorCallback(FuncBoolVector func) {
		using CallFuncBoolVectorCallbackFn = plg::vector<bool> (*)(FuncBoolVector);
		static CallFuncBoolVectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncBoolVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncChar8VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return char8[]: No description available.
	 *
	 * @callback FuncChar8Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): char8[]: No description available.
	 */
	inline plg::vector<char> CallFuncChar8VectorCallback(FuncChar8Vector func) {
		using CallFuncChar8VectorCallbackFn = plg::vector<char> (*)(FuncChar8Vector);
		static CallFuncChar8VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar8VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncChar16VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return char16[]: No description available.
	 *
	 * @callback FuncChar16Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): char16[]: No description available.
	 */
	inline plg::vector<char16_t> CallFuncChar16VectorCallback(FuncChar16Vector func) {
		using CallFuncChar16VectorCallbackFn = plg::vector<char16_t> (*)(FuncChar16Vector);
		static CallFuncChar16VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar16VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt8VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return int8[]: No description available.
	 *
	 * @callback FuncInt8Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int8[]: No description available.
	 */
	inline plg::vector<int8_t> CallFuncInt8VectorCallback(FuncInt8Vector func) {
		using CallFuncInt8VectorCallbackFn = plg::vector<int8_t> (*)(FuncInt8Vector);
		static CallFuncInt8VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt8VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt16VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return int16[]: No description available.
	 *
	 * @callback FuncInt16Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int16[]: No description available.
	 */
	inline plg::vector<int16_t> CallFuncInt16VectorCallback(FuncInt16Vector func) {
		using CallFuncInt16VectorCallbackFn = plg::vector<int16_t> (*)(FuncInt16Vector);
		static CallFuncInt16VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt16VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt32VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return int32[]: No description available.
	 *
	 * @callback FuncInt32Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int32[]: No description available.
	 */
	inline plg::vector<int32_t> CallFuncInt32VectorCallback(FuncInt32Vector func) {
		using CallFuncInt32VectorCallbackFn = plg::vector<int32_t> (*)(FuncInt32Vector);
		static CallFuncInt32VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt32VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncInt64VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return int64[]: No description available.
	 *
	 * @callback FuncInt64Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): int64[]: No description available.
	 */
	inline plg::vector<int64_t> CallFuncInt64VectorCallback(FuncInt64Vector func) {
		using CallFuncInt64VectorCallbackFn = plg::vector<int64_t> (*)(FuncInt64Vector);
		static CallFuncInt64VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt64VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt8VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return uint8[]: No description available.
	 *
	 * @callback FuncUInt8Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint8[]: No description available.
	 */
	inline plg::vector<uint8_t> CallFuncUInt8VectorCallback(FuncUInt8Vector func) {
		using CallFuncUInt8VectorCallbackFn = plg::vector<uint8_t> (*)(FuncUInt8Vector);
		static CallFuncUInt8VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt8VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt16VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return uint16[]: No description available.
	 *
	 * @callback FuncUInt16Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint16[]: No description available.
	 */
	inline plg::vector<uint16_t> CallFuncUInt16VectorCallback(FuncUInt16Vector func) {
		using CallFuncUInt16VectorCallbackFn = plg::vector<uint16_t> (*)(FuncUInt16Vector);
		static CallFuncUInt16VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt16VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt32VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return uint32[]: No description available.
	 *
	 * @callback FuncUInt32Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint32[]: No description available.
	 */
	inline plg::vector<uint32_t> CallFuncUInt32VectorCallback(FuncUInt32Vector func) {
		using CallFuncUInt32VectorCallbackFn = plg::vector<uint32_t> (*)(FuncUInt32Vector);
		static CallFuncUInt32VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt32VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncUInt64VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return uint64[]: No description available.
	 *
	 * @callback FuncUInt64Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): uint64[]: No description available.
	 */
	inline plg::vector<uint64_t> CallFuncUInt64VectorCallback(FuncUInt64Vector func) {
		using CallFuncUInt64VectorCallbackFn = plg::vector<uint64_t> (*)(FuncUInt64Vector);
		static CallFuncUInt64VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt64VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncPtrVectorCallback
	 * @param func (function): No description available.
	 *
	 * @return ptr64[]: No description available.
	 *
	 * @callback FuncPtrVector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): ptr64[]: No description available.
	 */
	inline plg::vector<void*> CallFuncPtrVectorCallback(FuncPtrVector func) {
		using CallFuncPtrVectorCallbackFn = plg::vector<void*> (*)(FuncPtrVector);
		static CallFuncPtrVectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncPtrVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncFloatVectorCallback
	 * @param func (function): No description available.
	 *
	 * @return float[]: No description available.
	 *
	 * @callback FuncFloatVector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): float[]: No description available.
	 */
	inline plg::vector<float> CallFuncFloatVectorCallback(FuncFloatVector func) {
		using CallFuncFloatVectorCallbackFn = plg::vector<float> (*)(FuncFloatVector);
		static CallFuncFloatVectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncFloatVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncDoubleVectorCallback
	 * @param func (function): No description available.
	 *
	 * @return double[]: No description available.
	 *
	 * @callback FuncDoubleVector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): double[]: No description available.
	 */
	inline plg::vector<double> CallFuncDoubleVectorCallback(FuncDoubleVector func) {
		using CallFuncDoubleVectorCallbackFn = plg::vector<double> (*)(FuncDoubleVector);
		static CallFuncDoubleVectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncDoubleVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncStringVectorCallback
	 * @param func (function): No description available.
	 *
	 * @return string[]: No description available.
	 *
	 * @callback FuncStringVector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): string[]: No description available.
	 */
	inline plg::vector<plg::string> CallFuncStringVectorCallback(FuncStringVector func) {
		using CallFuncStringVectorCallbackFn = plg::vector<plg::string> (*)(FuncStringVector);
		static CallFuncStringVectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncStringVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncAnyVectorCallback
	 * @param func (function): No description available.
	 *
	 * @return any[]: No description available.
	 *
	 * @callback FuncAnyVector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): any[]: No description available.
	 */
	inline plg::vector<plg::any> CallFuncAnyVectorCallback(FuncAnyVector func) {
		using CallFuncAnyVectorCallbackFn = plg::vector<plg::any> (*)(FuncAnyVector);
		static CallFuncAnyVectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncAnyVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVec2VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return vec2[]: No description available.
	 *
	 * @callback FuncVec2Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): vec2[]: No description available.
	 */
	inline plg::vector<plg::vec2> CallFuncVec2VectorCallback(FuncVec2Vector func) {
		using CallFuncVec2VectorCallbackFn = plg::vector<plg::vec2> (*)(FuncVec2Vector);
		static CallFuncVec2VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec2VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVec3VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return vec3[]: No description available.
	 *
	 * @callback FuncVec3Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): vec3[]: No description available.
	 */
	inline plg::vector<plg::vec3> CallFuncVec3VectorCallback(FuncVec3Vector func) {
		using CallFuncVec3VectorCallbackFn = plg::vector<plg::vec3> (*)(FuncVec3Vector);
		static CallFuncVec3VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec3VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVec4VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return vec4[]: No description available.
	 *
	 * @callback FuncVec4Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): vec4[]: No description available.
	 */
	inline plg::vector<plg::vec4> CallFuncVec4VectorCallback(FuncVec4Vector func) {
		using CallFuncVec4VectorCallbackFn = plg::vector<plg::vec4> (*)(FuncVec4Vector);
		static CallFuncVec4VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec4VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncMat4x4VectorCallback
	 * @param func (function): No description available.
	 *
	 * @return mat4x4[]: No description available.
	 *
	 * @callback FuncMat4x4Vector
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): mat4x4[]: No description available.
	 */
	inline plg::vector<plg::mat4x4> CallFuncMat4x4VectorCallback(FuncMat4x4Vector func) {
		using CallFuncMat4x4VectorCallbackFn = plg::vector<plg::mat4x4> (*)(FuncMat4x4Vector);
		static CallFuncMat4x4VectorCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncMat4x4VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVec2Callback
	 * @param func (function): No description available.
	 *
	 * @return vec2: No description available.
	 *
	 * @callback FuncVec2
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): vec2: No description available.
	 */
	inline plg::vec2 CallFuncVec2Callback(FuncVec2 func) {
		using CallFuncVec2CallbackFn = plg::vec2 (*)(FuncVec2);
		static CallFuncVec2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec2Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVec3Callback
	 * @param func (function): No description available.
	 *
	 * @return vec3: No description available.
	 *
	 * @callback FuncVec3
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): vec3: No description available.
	 */
	inline plg::vec3 CallFuncVec3Callback(FuncVec3 func) {
		using CallFuncVec3CallbackFn = plg::vec3 (*)(FuncVec3);
		static CallFuncVec3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec3Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncVec4Callback
	 * @param func (function): No description available.
	 *
	 * @return vec4: No description available.
	 *
	 * @callback FuncVec4
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): vec4: No description available.
	 */
	inline plg::vec4 CallFuncVec4Callback(FuncVec4 func) {
		using CallFuncVec4CallbackFn = plg::vec4 (*)(FuncVec4);
		static CallFuncVec4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec4Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncMat4x4Callback
	 * @param func (function): No description available.
	 *
	 * @return mat4x4: No description available.
	 *
	 * @callback FuncMat4x4
	 * @brief No description provided.
	 *
	 *
	 * @return (callback): mat4x4: No description available.
	 */
	inline plg::mat4x4 CallFuncMat4x4Callback(FuncMat4x4 func) {
		using CallFuncMat4x4CallbackFn = plg::mat4x4 (*)(FuncMat4x4);
		static CallFuncMat4x4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncMat4x4Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc1Callback
	 * @param func (function): No description available.
	 *
	 * @return int32: No description available.
	 *
	 * @callback Func1
	 * @brief No description provided.
	 *
	 * @param a (vec3): No description available.
	 *
	 * @return (callback): int32: No description available.
	 */
	inline int32_t CallFunc1Callback(Func1 func) {
		using CallFunc1CallbackFn = int32_t (*)(Func1);
		static CallFunc1CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc1Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc2Callback
	 * @param func (function): No description available.
	 *
	 * @return char8: No description available.
	 *
	 * @callback Func2
	 * @brief No description provided.
	 *
	 * @param a (float): No description available.
	 * @param b (int64): No description available.
	 *
	 * @return (callback): char8: No description available.
	 */
	inline char CallFunc2Callback(Func2 func) {
		using CallFunc2CallbackFn = char (*)(Func2);
		static CallFunc2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc2Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc3Callback
	 * @param func (function): No description available.
	 *
	 * @callback Func3
	 * @brief No description provided.
	 *
	 * @param a (ptr64): No description available.
	 * @param b (vec4): No description available.
	 * @param c (string): No description available.
	 *
	 * @return (callback): void: No description available.
	 */
	inline void CallFunc3Callback(Func3 func) {
		using CallFunc3CallbackFn = void (*)(Func3);
		static CallFunc3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc3Callback", reinterpret_cast<void**>(&__func));
		__func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc4Callback
	 * @param func (function): No description available.
	 *
	 * @return vec4: No description available.
	 *
	 * @callback Func4
	 * @brief No description provided.
	 *
	 * @param a (bool): No description available.
	 * @param b (int32): No description available.
	 * @param c (char16): No description available.
	 * @param d (mat4x4): No description available.
	 *
	 * @return (callback): vec4: No description available.
	 */
	inline plg::vec4 CallFunc4Callback(Func4 func) {
		using CallFunc4CallbackFn = plg::vec4 (*)(Func4);
		static CallFunc4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc4Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc5Callback
	 * @param func (function): No description available.
	 *
	 * @return bool: No description available.
	 *
	 * @callback Func5
	 * @brief No description provided.
	 *
	 * @param a (int8): No description available.
	 * @param b (vec2): No description available.
	 * @param c (ptr64): No description available.
	 * @param d (double): No description available.
	 * @param e (uint64[]): No description available.
	 *
	 * @return (callback): bool: No description available.
	 */
	inline bool CallFunc5Callback(Func5 func) {
		using CallFunc5CallbackFn = bool (*)(Func5);
		static CallFunc5CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc5Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc6Callback
	 * @param func (function): No description available.
	 *
	 * @return int64: No description available.
	 *
	 * @callback Func6
	 * @brief No description provided.
	 *
	 * @param a (string): No description available.
	 * @param b (float): No description available.
	 * @param c (float[]): No description available.
	 * @param d (int16): No description available.
	 * @param e (uint8[]): No description available.
	 * @param f (ptr64): No description available.
	 *
	 * @return (callback): int64: No description available.
	 */
	inline int64_t CallFunc6Callback(Func6 func) {
		using CallFunc6CallbackFn = int64_t (*)(Func6);
		static CallFunc6CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc6Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc7Callback
	 * @param func (function): No description available.
	 *
	 * @return double: No description available.
	 *
	 * @callback Func7
	 * @brief No description provided.
	 *
	 * @param vecC (char8[]): No description available.
	 * @param u16 (uint16): No description available.
	 * @param ch16 (char16): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param b (bool): No description available.
	 * @param u64 (uint64): No description available.
	 *
	 * @return (callback): double: No description available.
	 */
	inline double CallFunc7Callback(Func7 func) {
		using CallFunc7CallbackFn = double (*)(Func7);
		static CallFunc7CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc7Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc8Callback
	 * @param func (function): No description available.
	 *
	 * @return mat4x4: No description available.
	 *
	 * @callback Func8
	 * @brief No description provided.
	 *
	 * @param vec3 (vec3): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 * @param i16 (int16): No description available.
	 * @param b (bool): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param vecC16 (char16[]): No description available.
	 * @param ch16 (char16): No description available.
	 * @param i32 (int32): No description available.
	 *
	 * @return (callback): mat4x4: No description available.
	 */
	inline plg::mat4x4 CallFunc8Callback(Func8 func) {
		using CallFunc8CallbackFn = plg::mat4x4 (*)(Func8);
		static CallFunc8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc9Callback
	 * @param func (function): No description available.
	 *
	 * @callback Func9
	 * @brief No description provided.
	 *
	 * @param f (float): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param vecI8 (int8[]): No description available.
	 * @param u64 (uint64): No description available.
	 * @param b (bool): No description available.
	 * @param str (string): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param i16 (int16): No description available.
	 * @param ptr (ptr64): No description available.
	 *
	 * @return (callback): void: No description available.
	 */
	inline void CallFunc9Callback(Func9 func) {
		using CallFunc9CallbackFn = void (*)(Func9);
		static CallFunc9CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc9Callback", reinterpret_cast<void**>(&__func));
		__func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc10Callback
	 * @param func (function): No description available.
	 *
	 * @return uint32: No description available.
	 *
	 * @callback Func10
	 * @brief No description provided.
	 *
	 * @param vec4 (vec4): No description available.
	 * @param mat (mat4x4): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 * @param u64 (uint64): No description available.
	 * @param vecC (char8[]): No description available.
	 * @param i32 (int32): No description available.
	 * @param b (bool): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param i64 (int64): No description available.
	 * @param d (double): No description available.
	 *
	 * @return (callback): uint32: No description available.
	 */
	inline uint32_t CallFunc10Callback(Func10 func) {
		using CallFunc10CallbackFn = uint32_t (*)(Func10);
		static CallFunc10CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc10Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc11Callback
	 * @param func (function): No description available.
	 *
	 * @return ptr64: No description available.
	 *
	 * @callback Func11
	 * @brief No description provided.
	 *
	 * @param vecB (bool[]): No description available.
	 * @param ch16 (char16): No description available.
	 * @param u8 (uint8): No description available.
	 * @param d (double): No description available.
	 * @param vec3 (vec3): No description available.
	 * @param vecI8 (int8[]): No description available.
	 * @param i64 (int64): No description available.
	 * @param u16 (uint16): No description available.
	 * @param f (float): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param u32 (uint32): No description available.
	 *
	 * @return (callback): ptr64: No description available.
	 */
	inline void* CallFunc11Callback(Func11 func) {
		using CallFunc11CallbackFn = void* (*)(Func11);
		static CallFunc11CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc11Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc12Callback
	 * @param func (function): No description available.
	 *
	 * @return bool: No description available.
	 *
	 * @callback Func12
	 * @brief No description provided.
	 *
	 * @param ptr (ptr64): No description available.
	 * @param vecD (double[]): No description available.
	 * @param u32 (uint32): No description available.
	 * @param d (double): No description available.
	 * @param b (bool): No description available.
	 * @param i32 (int32): No description available.
	 * @param i8 (int8): No description available.
	 * @param u64 (uint64): No description available.
	 * @param f (float): No description available.
	 * @param vecPtr (ptr64[]): No description available.
	 * @param i64 (int64): No description available.
	 * @param ch (char8): No description available.
	 *
	 * @return (callback): bool: No description available.
	 */
	inline bool CallFunc12Callback(Func12 func) {
		using CallFunc12CallbackFn = bool (*)(Func12);
		static CallFunc12CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc12Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc13Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func13
	 * @brief No description provided.
	 *
	 * @param i64 (int64): No description available.
	 * @param vecC (char8[]): No description available.
	 * @param d (uint16): No description available.
	 * @param f (float): No description available.
	 * @param b (bool[]): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param str (string): No description available.
	 * @param int32 (int32): No description available.
	 * @param vec3 (vec3): No description available.
	 * @param ptr (ptr64): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param arr (uint8[]): No description available.
	 * @param i16 (int16): No description available.
	 *
	 * @return (callback): string: No description available.
	 */
	inline plg::string CallFunc13Callback(Func13 func) {
		using CallFunc13CallbackFn = plg::string (*)(Func13);
		static CallFunc13CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc13Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc14Callback
	 * @param func (function): No description available.
	 *
	 * @return string[]: No description available.
	 *
	 * @callback Func14
	 * @brief No description provided.
	 *
	 * @param vecC (char8[]): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 * @param mat (mat4x4): No description available.
	 * @param b (bool): No description available.
	 * @param ch16 (char16): No description available.
	 * @param i32 (int32): No description available.
	 * @param vecF (float[]): No description available.
	 * @param u16 (uint16): No description available.
	 * @param vecU8 (uint8[]): No description available.
	 * @param i8 (int8): No description available.
	 * @param vec3 (vec3): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param d (double): No description available.
	 * @param ptr (ptr64): No description available.
	 *
	 * @return (callback): string[]: No description available.
	 */
	inline plg::vector<plg::string> CallFunc14Callback(Func14 func) {
		using CallFunc14CallbackFn = plg::vector<plg::string> (*)(Func14);
		static CallFunc14CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc14Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc15Callback
	 * @param func (function): No description available.
	 *
	 * @return int16: No description available.
	 *
	 * @callback Func15
	 * @brief No description provided.
	 *
	 * @param vecI16 (int16[]): No description available.
	 * @param mat (mat4x4): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param ptr (ptr64): No description available.
	 * @param u64 (uint64): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 * @param b (bool): No description available.
	 * @param f (float): No description available.
	 * @param vecC16 (char16[]): No description available.
	 * @param u8 (uint8): No description available.
	 * @param i32 (int32): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param u16 (uint16): No description available.
	 * @param d (double): No description available.
	 * @param vecU8 (uint8[]): No description available.
	 *
	 * @return (callback): int16: No description available.
	 */
	inline int16_t CallFunc15Callback(Func15 func) {
		using CallFunc15CallbackFn = int16_t (*)(Func15);
		static CallFunc15CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc15Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc16Callback
	 * @param func (function): No description available.
	 *
	 * @return ptr64: No description available.
	 *
	 * @callback Func16
	 * @brief No description provided.
	 *
	 * @param vecB (bool[]): No description available.
	 * @param i16 (int16): No description available.
	 * @param vecI8 (int8[]): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param mat (mat4x4): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param vecU64 (uint64[]): No description available.
	 * @param vecC (char8[]): No description available.
	 * @param str (string): No description available.
	 * @param i64 (int64): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 * @param vec3 (vec3): No description available.
	 * @param f (float): No description available.
	 * @param d (double): No description available.
	 * @param i8 (int8): No description available.
	 * @param u16 (uint16): No description available.
	 *
	 * @return (callback): ptr64: No description available.
	 */
	inline void* CallFunc16Callback(Func16 func) {
		using CallFunc16CallbackFn = void* (*)(Func16);
		static CallFunc16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc17Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func17
	 * @brief No description provided.
	 *
	 * @param i32 (int32): No description available.
	 *
	 * @return (callback): void: No description available.
	 */
	inline plg::string CallFunc17Callback(Func17 func) {
		using CallFunc17CallbackFn = plg::string (*)(Func17);
		static CallFunc17CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc17Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc18Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func18
	 * @brief No description provided.
	 *
	 * @param i8 (int8): No description available.
	 * @param i16 (int16): No description available.
	 *
	 * @return (callback): vec2: No description available.
	 */
	inline plg::string CallFunc18Callback(Func18 func) {
		using CallFunc18CallbackFn = plg::string (*)(Func18);
		static CallFunc18CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc18Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc19Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func19
	 * @brief No description provided.
	 *
	 * @param u32 (uint32): No description available.
	 * @param vec3 (vec3): No description available.
	 * @param vecU32 (uint32[]): No description available.
	 *
	 * @return (callback): void: No description available.
	 */
	inline plg::string CallFunc19Callback(Func19 func) {
		using CallFunc19CallbackFn = plg::string (*)(Func19);
		static CallFunc19CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc19Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc20Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func20
	 * @brief No description provided.
	 *
	 * @param ch16 (char16): No description available.
	 * @param vec4 (vec4): No description available.
	 * @param vecU64 (uint64[]): No description available.
	 * @param ch (char8): No description available.
	 *
	 * @return (callback): int32: No description available.
	 */
	inline plg::string CallFunc20Callback(Func20 func) {
		using CallFunc20CallbackFn = plg::string (*)(Func20);
		static CallFunc20CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc20Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc21Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func21
	 * @brief No description provided.
	 *
	 * @param mat (mat4x4): No description available.
	 * @param vecI32 (int32[]): No description available.
	 * @param vec2 (vec2): No description available.
	 * @param b (bool): No description available.
	 * @param extraParam (double): No description available.
	 *
	 * @return (callback): float: No description available.
	 */
	inline plg::string CallFunc21Callback(Func21 func) {
		using CallFunc21CallbackFn = plg::string (*)(Func21);
		static CallFunc21CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc21Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc22Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func22
	 * @brief No description provided.
	 *
	 * @param ptr64Ref (ptr64): No description available.
	 * @param uint32Ref (uint32): No description available.
	 * @param vectorDoubleRef (double[]): No description available.
	 * @param int16Ref (int16): No description available.
	 * @param plgStringRef (string): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 *
	 * @return (callback): uint64: No description available.
	 */
	inline plg::string CallFunc22Callback(Func22 func) {
		using CallFunc22CallbackFn = plg::string (*)(Func22);
		static CallFunc22CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc22Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc23Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func23
	 * @brief No description provided.
	 *
	 * @param uint64Ref (uint64): No description available.
	 * @param plgVector2Ref (vec2): No description available.
	 * @param vectorInt16Ref (int16[]): No description available.
	 * @param char16Ref (char16): No description available.
	 * @param floatRef (float): No description available.
	 * @param int8Ref (int8): No description available.
	 * @param vectorUInt8Ref (uint8[]): No description available.
	 *
	 * @return (callback): void: No description available.
	 */
	inline plg::string CallFunc23Callback(Func23 func) {
		using CallFunc23CallbackFn = plg::string (*)(Func23);
		static CallFunc23CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc23Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc24Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func24
	 * @brief No description provided.
	 *
	 * @param vectorCharRef (char8[]): No description available.
	 * @param int64Ref (int64): No description available.
	 * @param vectorUInt8Ref (uint8[]): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 * @param uint64Ref (uint64): No description available.
	 * @param vectorptr64Ref (ptr64[]): No description available.
	 * @param doubleRef (double): No description available.
	 * @param vectorptr64Ref2 (ptr64[]): No description available.
	 *
	 * @return (callback): mat4x4: No description available.
	 */
	inline plg::string CallFunc24Callback(Func24 func) {
		using CallFunc24CallbackFn = plg::string (*)(Func24);
		static CallFunc24CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc24Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc25Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func25
	 * @brief No description provided.
	 *
	 * @param int32Ref (int32): No description available.
	 * @param vectorptr64Ref (ptr64[]): No description available.
	 * @param boolRef (bool): No description available.
	 * @param uint8Ref (uint8): No description available.
	 * @param plgStringRef (string): No description available.
	 * @param plgVector3Ref (vec3): No description available.
	 * @param int64Ref (int64): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 * @param uint16Ref (uint16): No description available.
	 *
	 * @return (callback): double: No description available.
	 */
	inline plg::string CallFunc25Callback(Func25 func) {
		using CallFunc25CallbackFn = plg::string (*)(Func25);
		static CallFunc25CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc25Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc26Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func26
	 * @brief No description provided.
	 *
	 * @param char16Ref (char16): No description available.
	 * @param plgVector2Ref (vec2): No description available.
	 * @param plgMatrix4x4Ref (mat4x4): No description available.
	 * @param vectorFloatRef (float[]): No description available.
	 * @param int16Ref (int16): No description available.
	 * @param uint64Ref (uint64): No description available.
	 * @param uint32Ref (uint32): No description available.
	 * @param vectorUInt16Ref (uint16[]): No description available.
	 * @param ptr64Ref (ptr64): No description available.
	 * @param boolRef (bool): No description available.
	 *
	 * @return (callback): char8: No description available.
	 */
	inline plg::string CallFunc26Callback(Func26 func) {
		using CallFunc26CallbackFn = plg::string (*)(Func26);
		static CallFunc26CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc26Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc27Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func27
	 * @brief No description provided.
	 *
	 * @param floatRef (float): No description available.
	 * @param plgVector3Ref (vec3): No description available.
	 * @param ptr64Ref (ptr64): No description available.
	 * @param plgVector2Ref (vec2): No description available.
	 * @param vectorInt16Ref (int16[]): No description available.
	 * @param plgMatrix4x4Ref (mat4x4): No description available.
	 * @param boolRef (bool): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 * @param int8Ref (int8): No description available.
	 * @param int32Ref (int32): No description available.
	 * @param vectorUInt8Ref (uint8[]): No description available.
	 *
	 * @return (callback): uint8: No description available.
	 */
	inline plg::string CallFunc27Callback(Func27 func) {
		using CallFunc27CallbackFn = plg::string (*)(Func27);
		static CallFunc27CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc27Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc28Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func28
	 * @brief No description provided.
	 *
	 * @param ptr64Ref (ptr64): No description available.
	 * @param uint16Ref (uint16): No description available.
	 * @param vectorUInt32Ref (uint32[]): No description available.
	 * @param plgMatrix4x4Ref (mat4x4): No description available.
	 * @param floatRef (float): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 * @param plgStringRef (string): No description available.
	 * @param vectorUInt64Ref (uint64[]): No description available.
	 * @param int64Ref (int64): No description available.
	 * @param boolRef (bool): No description available.
	 * @param plgVector3Ref (vec3): No description available.
	 * @param vectorFloatRef (float[]): No description available.
	 *
	 * @return (callback): string: No description available.
	 */
	inline plg::string CallFunc28Callback(Func28 func) {
		using CallFunc28CallbackFn = plg::string (*)(Func28);
		static CallFunc28CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc28Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc29Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func29
	 * @brief No description provided.
	 *
	 * @param plgVector4Ref (vec4): No description available.
	 * @param int32Ref (int32): No description available.
	 * @param vectorInt8Ref (int8[]): No description available.
	 * @param doubleRef (double): No description available.
	 * @param boolRef (bool): No description available.
	 * @param int8Ref (int8): No description available.
	 * @param vectorUInt16Ref (uint16[]): No description available.
	 * @param floatRef (float): No description available.
	 * @param plgStringRef (string): No description available.
	 * @param plgMatrix4x4Ref (mat4x4): No description available.
	 * @param uint64Ref (uint64): No description available.
	 * @param plgVector3Ref (vec3): No description available.
	 * @param vectorInt64Ref (int64[]): No description available.
	 *
	 * @return (callback): string[]: No description available.
	 */
	inline plg::string CallFunc29Callback(Func29 func) {
		using CallFunc29CallbackFn = plg::string (*)(Func29);
		static CallFunc29CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc29Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc30Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func30
	 * @brief No description provided.
	 *
	 * @param ptr64Ref (ptr64): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 * @param int64Ref (int64): No description available.
	 * @param vectorUInt32Ref (uint32[]): No description available.
	 * @param boolRef (bool): No description available.
	 * @param plgStringRef (string): No description available.
	 * @param plgVector3Ref (vec3): No description available.
	 * @param vectorUInt8Ref (uint8[]): No description available.
	 * @param floatRef (float): No description available.
	 * @param plgVector2Ref (vec2): No description available.
	 * @param plgMatrix4x4Ref (mat4x4): No description available.
	 * @param int8Ref (int8): No description available.
	 * @param vectorFloatRef (float[]): No description available.
	 * @param doubleRef (double): No description available.
	 *
	 * @return (callback): int32: No description available.
	 */
	inline plg::string CallFunc30Callback(Func30 func) {
		using CallFunc30CallbackFn = plg::string (*)(Func30);
		static CallFunc30CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc30Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc31Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func31
	 * @brief No description provided.
	 *
	 * @param charRef (char8): No description available.
	 * @param uint32Ref (uint32): No description available.
	 * @param vectorUInt64Ref (uint64[]): No description available.
	 * @param plgVector4Ref (vec4): No description available.
	 * @param plgStringRef (string): No description available.
	 * @param boolRef (bool): No description available.
	 * @param int64Ref (int64): No description available.
	 * @param vec2Ref (vec2): No description available.
	 * @param int8Ref (int8): No description available.
	 * @param uint16Ref (uint16): No description available.
	 * @param vectorInt16Ref (int16[]): No description available.
	 * @param mat4x4Ref (mat4x4): No description available.
	 * @param vec3Ref (vec3): No description available.
	 * @param floatRef (float): No description available.
	 * @param vectorDoubleRef (double[]): No description available.
	 *
	 * @return (callback): vec3: No description available.
	 */
	inline plg::string CallFunc31Callback(Func31 func) {
		using CallFunc31CallbackFn = plg::string (*)(Func31);
		static CallFunc31CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc31Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc32Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func32
	 * @brief No description provided.
	 *
	 * @param p1 (int32): No description available.
	 * @param p2 (uint16): No description available.
	 * @param p3 (int8[]): No description available.
	 * @param p4 (vec4): No description available.
	 * @param p5 (ptr64): No description available.
	 * @param p6 (uint32[]): No description available.
	 * @param p7 (mat4x4): No description available.
	 * @param p8 (uint64): No description available.
	 * @param p9 (string): No description available.
	 * @param p10 (int64): No description available.
	 * @param p11 (vec2): No description available.
	 * @param p12 (int8[]): No description available.
	 * @param p13 (bool): No description available.
	 * @param p14 (vec3): No description available.
	 * @param p15 (uint8): No description available.
	 * @param p16 (char16[]): No description available.
	 *
	 * @return (callback): double: No description available.
	 */
	inline plg::string CallFunc32Callback(Func32 func) {
		using CallFunc32CallbackFn = plg::string (*)(Func32);
		static CallFunc32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc32Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFunc33Callback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback Func33
	 * @brief No description provided.
	 *
	 * @param variant (any): No description available.
	 *
	 * @return (callback): void: No description available.
	 */
	inline plg::string CallFunc33Callback(Func33 func) {
		using CallFunc33CallbackFn = plg::string (*)(Func33);
		static CallFunc33CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc33Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

	/**
	 * @brief No description provided.
	 *
	 * @function CallFuncEnumCallback
	 * @param func (function): No description available.
	 *
	 * @return string: No description available.
	 *
	 * @callback FuncEnum
	 * @brief No description provided.
	 *
	 * @param p1 (int32): No description available.
	 * @param p2 (int32[]): No description available.
	 *
	 * @return (callback): int32[]: No description available.
	 */
	inline plg::string CallFuncEnumCallback(FuncEnum func) {
		using CallFuncEnumCallbackFn = plg::string (*)(FuncEnum);
		static CallFuncEnumCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncEnumCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}

} // namespace cross_call_master
