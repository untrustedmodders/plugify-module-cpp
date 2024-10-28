#pragma once

#include <plugify/cpp_plugin.hpp>
#include <plugify/string.hpp>
#include <plugify/vector.hpp>
#include <cstdint>

// Generated from cross_call_master.pplugin by https://github.com/untrustedmodders/plugify-module-cpp/blob/main/generator/generator.py 

namespace cross_call_master {
	inline void ReverseReturn(const plg::string& returnString) {
		using ReverseReturnFn = void (*)(const plg::string&);
		static ReverseReturnFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ReverseReturn", reinterpret_cast<void**>(&__func));
		__func(returnString);
	}
	inline void NoParamReturnVoidCallback() {
		using NoParamReturnVoidCallbackFn = void (*)();
		static NoParamReturnVoidCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVoidCallback", reinterpret_cast<void**>(&__func));
		__func();
	}
	inline bool NoParamReturnBoolCallback() {
		using NoParamReturnBoolCallbackFn = bool (*)();
		static NoParamReturnBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnBoolCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char NoParamReturnChar8Callback() {
		using NoParamReturnChar8CallbackFn = char (*)();
		static NoParamReturnChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnChar8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char16_t NoParamReturnChar16Callback() {
		using NoParamReturnChar16CallbackFn = char16_t (*)();
		static NoParamReturnChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnChar16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int8_t NoParamReturnInt8Callback() {
		using NoParamReturnInt8CallbackFn = int8_t (*)();
		static NoParamReturnInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int16_t NoParamReturnInt16Callback() {
		using NoParamReturnInt16CallbackFn = int16_t (*)();
		static NoParamReturnInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int32_t NoParamReturnInt32Callback() {
		using NoParamReturnInt32CallbackFn = int32_t (*)();
		static NoParamReturnInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int64_t NoParamReturnInt64Callback() {
		using NoParamReturnInt64CallbackFn = int64_t (*)();
		static NoParamReturnInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint8_t NoParamReturnUInt8Callback() {
		using NoParamReturnUInt8CallbackFn = uint8_t (*)();
		static NoParamReturnUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint16_t NoParamReturnUInt16Callback() {
		using NoParamReturnUInt16CallbackFn = uint16_t (*)();
		static NoParamReturnUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint32_t NoParamReturnUInt32Callback() {
		using NoParamReturnUInt32CallbackFn = uint32_t (*)();
		static NoParamReturnUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint64_t NoParamReturnUInt64Callback() {
		using NoParamReturnUInt64CallbackFn = uint64_t (*)();
		static NoParamReturnUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void* NoParamReturnPointerCallback() {
		using NoParamReturnPointerCallbackFn = void* (*)();
		static NoParamReturnPointerCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnPointerCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline float NoParamReturnFloatCallback() {
		using NoParamReturnFloatCallbackFn = float (*)();
		static NoParamReturnFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnFloatCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline double NoParamReturnDoubleCallback() {
		using NoParamReturnDoubleCallbackFn = double (*)();
		static NoParamReturnDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	using NoParamReturnFunctionCallbackFunc = int32_t (*)();
	inline NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
		using NoParamReturnFunctionCallbackFn = NoParamReturnFunctionCallbackFunc (*)();
		static NoParamReturnFunctionCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnFunctionCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::string NoParamReturnStringCallback() {
		using NoParamReturnStringCallbackFn = plg::string (*)();
		static NoParamReturnStringCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnStringCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<bool> NoParamReturnArrayBoolCallback() {
		using NoParamReturnArrayBoolCallbackFn = plg::vector<bool> (*)();
		static NoParamReturnArrayBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayBoolCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<char> NoParamReturnArrayChar8Callback() {
		using NoParamReturnArrayChar8CallbackFn = plg::vector<char> (*)();
		static NoParamReturnArrayChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayChar8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<char16_t> NoParamReturnArrayChar16Callback() {
		using NoParamReturnArrayChar16CallbackFn = plg::vector<char16_t> (*)();
		static NoParamReturnArrayChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayChar16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int8_t> NoParamReturnArrayInt8Callback() {
		using NoParamReturnArrayInt8CallbackFn = plg::vector<int8_t> (*)();
		static NoParamReturnArrayInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int16_t> NoParamReturnArrayInt16Callback() {
		using NoParamReturnArrayInt16CallbackFn = plg::vector<int16_t> (*)();
		static NoParamReturnArrayInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int32_t> NoParamReturnArrayInt32Callback() {
		using NoParamReturnArrayInt32CallbackFn = plg::vector<int32_t> (*)();
		static NoParamReturnArrayInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int64_t> NoParamReturnArrayInt64Callback() {
		using NoParamReturnArrayInt64CallbackFn = plg::vector<int64_t> (*)();
		static NoParamReturnArrayInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint8_t> NoParamReturnArrayUInt8Callback() {
		using NoParamReturnArrayUInt8CallbackFn = plg::vector<uint8_t> (*)();
		static NoParamReturnArrayUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint16_t> NoParamReturnArrayUInt16Callback() {
		using NoParamReturnArrayUInt16CallbackFn = plg::vector<uint16_t> (*)();
		static NoParamReturnArrayUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint32_t> NoParamReturnArrayUInt32Callback() {
		using NoParamReturnArrayUInt32CallbackFn = plg::vector<uint32_t> (*)();
		static NoParamReturnArrayUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint64_t> NoParamReturnArrayUInt64Callback() {
		using NoParamReturnArrayUInt64CallbackFn = plg::vector<uint64_t> (*)();
		static NoParamReturnArrayUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<void*> NoParamReturnArrayPointerCallback() {
		using NoParamReturnArrayPointerCallbackFn = plg::vector<void*> (*)();
		static NoParamReturnArrayPointerCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayPointerCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<float> NoParamReturnArrayFloatCallback() {
		using NoParamReturnArrayFloatCallbackFn = plg::vector<float> (*)();
		static NoParamReturnArrayFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayFloatCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<double> NoParamReturnArrayDoubleCallback() {
		using NoParamReturnArrayDoubleCallbackFn = plg::vector<double> (*)();
		static NoParamReturnArrayDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<plg::string> NoParamReturnArrayStringCallback() {
		using NoParamReturnArrayStringCallbackFn = plg::vector<plg::string> (*)();
		static NoParamReturnArrayStringCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnArrayStringCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vec2 NoParamReturnVector2Callback() {
		using NoParamReturnVector2CallbackFn = plg::vec2 (*)();
		static NoParamReturnVector2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVector2Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vec3 NoParamReturnVector3Callback() {
		using NoParamReturnVector3CallbackFn = plg::vec3 (*)();
		static NoParamReturnVector3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVector3Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vec4 NoParamReturnVector4Callback() {
		using NoParamReturnVector4CallbackFn = plg::vec4 (*)();
		static NoParamReturnVector4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnVector4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::mat4x4 NoParamReturnMatrix4x4Callback() {
		using NoParamReturnMatrix4x4CallbackFn = plg::mat4x4 (*)();
		static NoParamReturnMatrix4x4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.NoParamReturnMatrix4x4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void Param1Callback(int32_t a) {
		using Param1CallbackFn = void (*)(int32_t);
		static Param1CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param1Callback", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void Param2Callback(int32_t a, float b) {
		using Param2CallbackFn = void (*)(int32_t, float);
		static Param2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param2Callback", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void Param3Callback(int32_t a, float b, double c) {
		using Param3CallbackFn = void (*)(int32_t, float, double);
		static Param3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param3Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void Param4Callback(int32_t a, float b, double c, const plg::vec4& d) {
		using Param4CallbackFn = void (*)(int32_t, float, double, const plg::vec4&);
		static Param4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param4Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void Param5Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e) {
		using Param5CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&);
		static Param5CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param5Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void Param6Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f) {
		using Param6CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char);
		static Param6CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param6Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void Param7Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g) {
		using Param7CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&);
		static Param7CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param7Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void Param8Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
		using Param8CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t);
		static Param8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param8Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void Param9Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
		using Param9CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t);
		static Param9CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param9Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void Param10Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
		using Param10CallbackFn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t, void*);
		static Param10CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.Param10Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRef1Callback(int32_t& a) {
		using ParamRef1CallbackFn = void (*)(int32_t&);
		static ParamRef1CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef1Callback", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void ParamRef2Callback(int32_t& a, float& b) {
		using ParamRef2CallbackFn = void (*)(int32_t&, float&);
		static ParamRef2CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef2Callback", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void ParamRef3Callback(int32_t& a, float& b, double& c) {
		using ParamRef3CallbackFn = void (*)(int32_t&, float&, double&);
		static ParamRef3CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef3Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void ParamRef4Callback(int32_t& a, float& b, double& c, plg::vec4& d) {
		using ParamRef4CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&);
		static ParamRef4CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef4Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void ParamRef5Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e) {
		using ParamRef5CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&);
		static ParamRef5CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef5Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void ParamRef6Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f) {
		using ParamRef6CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&);
		static ParamRef6CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef6Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void ParamRef7Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g) {
		using ParamRef7CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&);
		static ParamRef7CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef7Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void ParamRef8Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
		using ParamRef8CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&);
		static ParamRef8CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef8Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void ParamRef9Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
		using ParamRef9CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&);
		static ParamRef9CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef9Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void ParamRef10Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
		using ParamRef10CallbackFn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&, void*&);
		static ParamRef10CallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRef10Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRefVectorsCallback(plg::vector<bool>& p1, plg::vector<char>& p2, plg::vector<char16_t>& p3, plg::vector<int8_t>& p4, plg::vector<int16_t>& p5, plg::vector<int32_t>& p6, plg::vector<int64_t>& p7, plg::vector<uint8_t>& p8, plg::vector<uint16_t>& p9, plg::vector<uint32_t>& p10, plg::vector<uint64_t>& p11, plg::vector<void*>& p12, plg::vector<float>& p13, plg::vector<double>& p14, plg::vector<plg::string>& p15) {
		using ParamRefVectorsCallbackFn = void (*)(plg::vector<bool>&, plg::vector<char>&, plg::vector<char16_t>&, plg::vector<int8_t>&, plg::vector<int16_t>&, plg::vector<int32_t>&, plg::vector<int64_t>&, plg::vector<uint8_t>&, plg::vector<uint16_t>&, plg::vector<uint32_t>&, plg::vector<uint64_t>&, plg::vector<void*>&, plg::vector<float>&, plg::vector<double>&, plg::vector<plg::string>&);
		static ParamRefVectorsCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamRefVectorsCallback", reinterpret_cast<void**>(&__func));
		__func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}
	inline int64_t ParamAllPrimitivesCallback(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
		using ParamAllPrimitivesCallbackFn = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
		static ParamAllPrimitivesCallbackFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.ParamAllPrimitivesCallback", reinterpret_cast<void**>(&__func));
		return __func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	}
	using FuncVoid = void (*)();
	inline void CallFuncVoidCallback(FuncVoid func) {
		using CallFuncVoidFn = void (*)(FuncVoid);
		static CallFuncVoidFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVoidCallback", reinterpret_cast<void**>(&__func));
		__func(func);
	}
	using FuncBool = bool (*)();
	inline bool CallFuncBoolCallback(FuncBool func) {
		using CallFuncBoolFn = bool (*)(FuncBool);
		static CallFuncBoolFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncBoolCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar8 = char (*)();
	inline char CallFuncChar8Callback(FuncChar8 func) {
		using CallFuncChar8Fn = char (*)(FuncChar8);
		static CallFuncChar8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar16 = char16_t (*)();
	inline char16_t CallFuncChar16Callback(FuncChar16 func) {
		using CallFuncChar16Fn = char16_t (*)(FuncChar16);
		static CallFuncChar16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt8 = int8_t (*)();
	inline int8_t CallFuncInt8Callback(FuncInt8 func) {
		using CallFuncInt8Fn = int8_t (*)(FuncInt8);
		static CallFuncInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt16 = int16_t (*)();
	inline int16_t CallFuncInt16Callback(FuncInt16 func) {
		using CallFuncInt16Fn = int16_t (*)(FuncInt16);
		static CallFuncInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt32 = int32_t (*)();
	inline int32_t CallFuncInt32Callback(FuncInt32 func) {
		using CallFuncInt32Fn = int32_t (*)(FuncInt32);
		static CallFuncInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt32Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt64 = int64_t (*)();
	inline int64_t CallFuncInt64Callback(FuncInt64 func) {
		using CallFuncInt64Fn = int64_t (*)(FuncInt64);
		static CallFuncInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt64Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt8 = uint8_t (*)();
	inline uint8_t CallFuncUInt8Callback(FuncUInt8 func) {
		using CallFuncUInt8Fn = uint8_t (*)(FuncUInt8);
		static CallFuncUInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt16 = uint16_t (*)();
	inline uint16_t CallFuncUInt16Callback(FuncUInt16 func) {
		using CallFuncUInt16Fn = uint16_t (*)(FuncUInt16);
		static CallFuncUInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt32 = uint32_t (*)();
	inline uint32_t CallFuncUInt32Callback(FuncUInt32 func) {
		using CallFuncUInt32Fn = uint32_t (*)(FuncUInt32);
		static CallFuncUInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt64 = uint64_t (*)();
	inline uint64_t CallFuncUInt64Callback(FuncUInt64 func) {
		using CallFuncUInt64Fn = uint64_t (*)(FuncUInt64);
		static CallFuncUInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncPtr = void* (*)();
	inline void* CallFuncPtrCallback(FuncPtr func) {
		using CallFuncPtrFn = void* (*)(FuncPtr);
		static CallFuncPtrFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncPtrCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncFloat = float (*)();
	inline float CallFuncFloatCallback(FuncFloat func) {
		using CallFuncFloatFn = float (*)(FuncFloat);
		static CallFuncFloatFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncFloatCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncDouble = double (*)();
	inline double CallFuncDoubleCallback(FuncDouble func) {
		using CallFuncDoubleFn = double (*)(FuncDouble);
		static CallFuncDoubleFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncString = plg::string (*)();
	inline plg::string CallFuncStringCallback(FuncString func) {
		using CallFuncStringFn = plg::string (*)(FuncString);
		static CallFuncStringFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncStringCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncFunction = void* (*)();
	inline void* CallFuncFunctionCallback(FuncFunction func) {
		using CallFuncFunctionFn = void* (*)(FuncFunction);
		static CallFuncFunctionFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncFunctionCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncBoolVector = plg::vector<bool> (*)();
	inline plg::vector<bool> CallFuncBoolVectorCallback(FuncBoolVector func) {
		using CallFuncBoolVectorFn = plg::vector<bool> (*)(FuncBoolVector);
		static CallFuncBoolVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncBoolVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar8Vector = plg::vector<char> (*)();
	inline plg::vector<char> CallFuncChar8VectorCallback(FuncChar8Vector func) {
		using CallFuncChar8VectorFn = plg::vector<char> (*)(FuncChar8Vector);
		static CallFuncChar8VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar8VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar16Vector = plg::vector<char16_t> (*)();
	inline plg::vector<char16_t> CallFuncChar16VectorCallback(FuncChar16Vector func) {
		using CallFuncChar16VectorFn = plg::vector<char16_t> (*)(FuncChar16Vector);
		static CallFuncChar16VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncChar16VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt8Vector = plg::vector<int8_t> (*)();
	inline plg::vector<int8_t> CallFuncInt8VectorCallback(FuncInt8Vector func) {
		using CallFuncInt8VectorFn = plg::vector<int8_t> (*)(FuncInt8Vector);
		static CallFuncInt8VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt8VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt16Vector = plg::vector<int16_t> (*)();
	inline plg::vector<int16_t> CallFuncInt16VectorCallback(FuncInt16Vector func) {
		using CallFuncInt16VectorFn = plg::vector<int16_t> (*)(FuncInt16Vector);
		static CallFuncInt16VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt16VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt32Vector = plg::vector<int32_t> (*)();
	inline plg::vector<int32_t> CallFuncInt32VectorCallback(FuncInt32Vector func) {
		using CallFuncInt32VectorFn = plg::vector<int32_t> (*)(FuncInt32Vector);
		static CallFuncInt32VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt32VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt64Vector = plg::vector<int64_t> (*)();
	inline plg::vector<int64_t> CallFuncInt64VectorCallback(FuncInt64Vector func) {
		using CallFuncInt64VectorFn = plg::vector<int64_t> (*)(FuncInt64Vector);
		static CallFuncInt64VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncInt64VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt8Vector = plg::vector<uint8_t> (*)();
	inline plg::vector<uint8_t> CallFuncUInt8VectorCallback(FuncUInt8Vector func) {
		using CallFuncUInt8VectorFn = plg::vector<uint8_t> (*)(FuncUInt8Vector);
		static CallFuncUInt8VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt8VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt16Vector = plg::vector<uint16_t> (*)();
	inline plg::vector<uint16_t> CallFuncUInt16VectorCallback(FuncUInt16Vector func) {
		using CallFuncUInt16VectorFn = plg::vector<uint16_t> (*)(FuncUInt16Vector);
		static CallFuncUInt16VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt16VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt32Vector = plg::vector<uint32_t> (*)();
	inline plg::vector<uint32_t> CallFuncUInt32VectorCallback(FuncUInt32Vector func) {
		using CallFuncUInt32VectorFn = plg::vector<uint32_t> (*)(FuncUInt32Vector);
		static CallFuncUInt32VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt32VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt64Vector = plg::vector<uint64_t> (*)();
	inline plg::vector<uint64_t> CallFuncUInt64VectorCallback(FuncUInt64Vector func) {
		using CallFuncUInt64VectorFn = plg::vector<uint64_t> (*)(FuncUInt64Vector);
		static CallFuncUInt64VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncUInt64VectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncPtrVector = plg::vector<void*> (*)();
	inline plg::vector<void*> CallFuncPtrVectorCallback(FuncPtrVector func) {
		using CallFuncPtrVectorFn = plg::vector<void*> (*)(FuncPtrVector);
		static CallFuncPtrVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncPtrVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncFloatVector = plg::vector<float> (*)();
	inline plg::vector<float> CallFuncFloatVectorCallback(FuncFloatVector func) {
		using CallFuncFloatVectorFn = plg::vector<float> (*)(FuncFloatVector);
		static CallFuncFloatVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncFloatVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncStringVector = plg::vector<plg::string> (*)();
	inline plg::vector<plg::string> CallFuncStringVectorCallback(FuncStringVector func) {
		using CallFuncStringVectorFn = plg::vector<plg::string> (*)(FuncStringVector);
		static CallFuncStringVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncStringVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncDoubleVector = plg::vector<double> (*)();
	inline plg::vector<double> CallFuncDoubleVectorCallback(FuncDoubleVector func) {
		using CallFuncDoubleVectorFn = plg::vector<double> (*)(FuncDoubleVector);
		static CallFuncDoubleVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncDoubleVectorCallback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncVec2 = plg::vec2 (*)();
	inline plg::vec2 CallFuncVec2Callback(FuncVec2 func) {
		using CallFuncVec2Fn = plg::vec2 (*)(FuncVec2);
		static CallFuncVec2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec2Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncVec3 = plg::vec3 (*)();
	inline plg::vec3 CallFuncVec3Callback(FuncVec3 func) {
		using CallFuncVec3Fn = plg::vec3 (*)(FuncVec3);
		static CallFuncVec3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec3Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncVec4 = plg::vec4 (*)();
	inline plg::vec4 CallFuncVec4Callback(FuncVec4 func) {
		using CallFuncVec4Fn = plg::vec4 (*)(FuncVec4);
		static CallFuncVec4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncVec4Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncMat4x4 = plg::mat4x4 (*)();
	inline plg::mat4x4 CallFuncMat4x4Callback(FuncMat4x4 func) {
		using CallFuncMat4x4Fn = plg::mat4x4 (*)(FuncMat4x4);
		static CallFuncMat4x4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFuncMat4x4Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func1 = int32_t (*)(const plg::vec3&);
	inline int32_t CallFunc1Callback(Func1 func) {
		using CallFunc1Fn = int32_t (*)(Func1);
		static CallFunc1Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc1Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func2 = char (*)(float, int64_t);
	inline char CallFunc2Callback(Func2 func) {
		using CallFunc2Fn = char (*)(Func2);
		static CallFunc2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc2Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func3 = void (*)(void*, const plg::vec4&, const plg::string&);
	inline void CallFunc3Callback(Func3 func) {
		using CallFunc3Fn = void (*)(Func3);
		static CallFunc3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc3Callback", reinterpret_cast<void**>(&__func));
		__func(func);
	}
	using Func4 = plg::vec4 (*)(bool, int32_t, char16_t, const plg::mat4x4&);
	inline plg::vec4 CallFunc4Callback(Func4 func) {
		using CallFunc4Fn = plg::vec4 (*)(Func4);
		static CallFunc4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc4Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func5 = bool (*)(int8_t, const plg::vec2&, void*, double, const plg::vector<uint64_t>&);
	inline bool CallFunc5Callback(Func5 func) {
		using CallFunc5Fn = bool (*)(Func5);
		static CallFunc5Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc5Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func6 = int64_t (*)(const plg::string&, float, const plg::vector<float>&, int16_t, const plg::vector<uint8_t>&, void*);
	inline int64_t CallFunc6Callback(Func6 func) {
		using CallFunc6Fn = int64_t (*)(Func6);
		static CallFunc6Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc6Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func7 = double (*)(const plg::vector<char>&, uint16_t, char16_t, const plg::vector<uint32_t>&, const plg::vec4&, bool, uint64_t);
	inline double CallFunc7Callback(Func7 func) {
		using CallFunc7Fn = double (*)(Func7);
		static CallFunc7Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc7Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func8 = plg::mat4x4 (*)(const plg::vec3&, const plg::vector<uint32_t>&, int16_t, bool, const plg::vec4&, const plg::vector<char16_t>&, char16_t, int32_t);
	inline plg::mat4x4 CallFunc8Callback(Func8 func) {
		using CallFunc8Fn = plg::mat4x4 (*)(Func8);
		static CallFunc8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc8Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func9 = void (*)(float, const plg::vec2&, const plg::vector<int8_t>&, uint64_t, bool, const plg::string&, const plg::vec4&, int16_t, void*);
	inline void CallFunc9Callback(Func9 func) {
		using CallFunc9Fn = void (*)(Func9);
		static CallFunc9Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc9Callback", reinterpret_cast<void**>(&__func));
		__func(func);
	}
	using Func10 = uint32_t (*)(const plg::vec4&, const plg::mat4x4&, const plg::vector<uint32_t>&, uint64_t, const plg::vector<char>&, int32_t, bool, const plg::vec2&, int64_t, double);
	inline uint32_t CallFunc10Callback(Func10 func) {
		using CallFunc10Fn = uint32_t (*)(Func10);
		static CallFunc10Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc10Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func11 = void* (*)(const plg::vector<bool>&, char16_t, uint8_t, double, const plg::vec3&, const plg::vector<int8_t>&, int64_t, uint16_t, float, const plg::vec2&, uint32_t);
	inline void* CallFunc11Callback(Func11 func) {
		using CallFunc11Fn = void* (*)(Func11);
		static CallFunc11Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc11Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func12 = bool (*)(void*, const plg::vector<double>&, uint32_t, double, bool, int32_t, int8_t, uint64_t, float, const plg::vector<void*>&, int64_t, char);
	inline bool CallFunc12Callback(Func12 func) {
		using CallFunc12Fn = bool (*)(Func12);
		static CallFunc12Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc12Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func13 = plg::string (*)(int64_t, const plg::vector<char>&, uint16_t, float, const plg::vector<bool>&, const plg::vec4&, const plg::string&, int32_t, const plg::vec3&, void*, const plg::vec2&, const plg::vector<uint8_t>&, int16_t);
	inline plg::string CallFunc13Callback(Func13 func) {
		using CallFunc13Fn = plg::string (*)(Func13);
		static CallFunc13Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc13Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func14 = plg::vector<plg::string> (*)(const plg::vector<char>&, const plg::vector<uint32_t>&, const plg::mat4x4&, bool, char16_t, int32_t, const plg::vector<float>&, uint16_t, const plg::vector<uint8_t>&, int8_t, const plg::vec3&, const plg::vec4&, double, void*);
	inline plg::vector<plg::string> CallFunc14Callback(Func14 func) {
		using CallFunc14Fn = plg::vector<plg::string> (*)(Func14);
		static CallFunc14Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc14Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func15 = int16_t (*)(const plg::vector<int16_t>&, const plg::mat4x4&, const plg::vec4&, void*, uint64_t, const plg::vector<uint32_t>&, bool, float, const plg::vector<char16_t>&, uint8_t, int32_t, const plg::vec2&, uint16_t, double, const plg::vector<uint8_t>&);
	inline int16_t CallFunc15Callback(Func15 func) {
		using CallFunc15Fn = int16_t (*)(Func15);
		static CallFunc15Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc15Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func16 = void* (*)(const plg::vector<bool>&, int16_t, const plg::vector<int8_t>&, const plg::vec4&, const plg::mat4x4&, const plg::vec2&, const plg::vector<uint64_t>&, const plg::vector<char>&, const plg::string&, int64_t, const plg::vector<uint32_t>&, const plg::vec3&, float, double, int8_t, uint16_t);
	inline void* CallFunc16Callback(Func16 func) {
		using CallFunc16Fn = void* (*)(Func16);
		static CallFunc16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc16Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func17 = void (*)(int32_t&);
	inline plg::string CallFunc17Callback(Func17 func) {
		using CallFunc17Fn = plg::string (*)(Func17);
		static CallFunc17Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc17Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func18 = plg::vec2 (*)(int8_t&, int16_t&);
	inline plg::string CallFunc18Callback(Func18 func) {
		using CallFunc18Fn = plg::string (*)(Func18);
		static CallFunc18Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc18Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func19 = void (*)(uint32_t&, plg::vec3&, plg::vector<uint32_t>&);
	inline plg::string CallFunc19Callback(Func19 func) {
		using CallFunc19Fn = plg::string (*)(Func19);
		static CallFunc19Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc19Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func20 = int32_t (*)(char16_t&, plg::vec4&, plg::vector<uint64_t>&, char&);
	inline plg::string CallFunc20Callback(Func20 func) {
		using CallFunc20Fn = plg::string (*)(Func20);
		static CallFunc20Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc20Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func21 = float (*)(plg::mat4x4&, plg::vector<int32_t>&, plg::vec2&, bool&, double&);
	inline plg::string CallFunc21Callback(Func21 func) {
		using CallFunc21Fn = plg::string (*)(Func21);
		static CallFunc21Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc21Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func22 = uint64_t (*)(void*&, uint32_t&, plg::vector<double>&, int16_t&, plg::string&, plg::vec4&);
	inline plg::string CallFunc22Callback(Func22 func) {
		using CallFunc22Fn = plg::string (*)(Func22);
		static CallFunc22Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc22Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func23 = void (*)(uint64_t&, plg::vec2&, plg::vector<int16_t>&, char16_t&, float&, int8_t&, plg::vector<uint8_t>&);
	inline plg::string CallFunc23Callback(Func23 func) {
		using CallFunc23Fn = plg::string (*)(Func23);
		static CallFunc23Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc23Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func24 = plg::mat4x4 (*)(plg::vector<char>&, int64_t&, plg::vector<uint8_t>&, plg::vec4&, uint64_t&, plg::vector<void*>&, double&, plg::vector<void*>&);
	inline plg::string CallFunc24Callback(Func24 func) {
		using CallFunc24Fn = plg::string (*)(Func24);
		static CallFunc24Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc24Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func25 = double (*)(int32_t&, plg::vector<void*>&, bool&, uint8_t&, plg::string&, plg::vec3&, int64_t&, plg::vec4&, uint16_t&);
	inline plg::string CallFunc25Callback(Func25 func) {
		using CallFunc25Fn = plg::string (*)(Func25);
		static CallFunc25Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc25Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func26 = char (*)(char16_t&, plg::vec2&, plg::mat4x4&, plg::vector<float>&, int16_t&, uint64_t&, uint32_t&, plg::vector<uint16_t>&, void*&, bool&);
	inline plg::string CallFunc26Callback(Func26 func) {
		using CallFunc26Fn = plg::string (*)(Func26);
		static CallFunc26Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc26Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func27 = uint8_t (*)(float&, plg::vec3&, void*&, plg::vec2&, plg::vector<int16_t>&, plg::mat4x4&, bool&, plg::vec4&, int8_t&, int32_t&, plg::vector<uint8_t>&);
	inline plg::string CallFunc27Callback(Func27 func) {
		using CallFunc27Fn = plg::string (*)(Func27);
		static CallFunc27Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc27Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func28 = plg::string (*)(void*&, uint16_t&, plg::vector<uint32_t>&, plg::mat4x4&, float&, plg::vec4&, plg::string&, plg::vector<uint64_t>&, int64_t&, bool&, plg::vec3&, plg::vector<float>&);
	inline plg::string CallFunc28Callback(Func28 func) {
		using CallFunc28Fn = plg::string (*)(Func28);
		static CallFunc28Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc28Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func29 = plg::vector<plg::string> (*)(plg::vec4&, int32_t&, plg::vector<int8_t>&, double&, bool&, int8_t&, plg::vector<uint16_t>&, float&, plg::string&, plg::mat4x4&, uint64_t&, plg::vec3&, plg::vector<int64_t>&);
	inline plg::string CallFunc29Callback(Func29 func) {
		using CallFunc29Fn = plg::string (*)(Func29);
		static CallFunc29Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc29Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func30 = int32_t (*)(void*&, plg::vec4&, int64_t&, plg::vector<uint32_t>&, bool&, plg::string&, plg::vec3&, plg::vector<uint8_t>&, float&, plg::vec2&, plg::mat4x4&, int8_t&, plg::vector<float>&, double&);
	inline plg::string CallFunc30Callback(Func30 func) {
		using CallFunc30Fn = plg::string (*)(Func30);
		static CallFunc30Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc30Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func31 = plg::vec3 (*)(char&, uint32_t&, plg::vector<uint64_t>&, plg::vec4&, plg::string&, bool&, int64_t&, plg::vec2&, int8_t&, uint16_t&, plg::vector<int16_t>&, plg::mat4x4&, plg::vec3&, float&, plg::vector<double>&);
	inline plg::string CallFunc31Callback(Func31 func) {
		using CallFunc31Fn = plg::string (*)(Func31);
		static CallFunc31Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc31Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func32 = double (*)(int32_t&, uint16_t&, plg::vector<int8_t>&, plg::vec4&, void*&, plg::vector<uint32_t>&, plg::mat4x4&, uint64_t&, plg::string&, int64_t&, plg::vec2&, plg::vector<int8_t>&, bool&, plg::vec3&, uint8_t&, plg::vector<char16_t>&);
	inline plg::string CallFunc32Callback(Func32 func) {
		using CallFunc32Fn = plg::string (*)(Func32);
		static CallFunc32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_master.CallFunc32Callback", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
}
