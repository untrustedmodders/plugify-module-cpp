#pragma once

#include <plugify/cpp_plugin.hpp>
#include <plugify/string.hpp>
#include <plugify/vector.hpp>
#include <cstdint>

// Generated from cross_call_worker.pplugin by https://github.com/untrustedmodders/plugify-module-cpp/blob/main/generator/generator.py 

namespace cross_call_worker {
	inline void NoParamReturnVoid() {
		using NoParamReturnVoidFn = void (*)();
		static NoParamReturnVoidFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnVoid", reinterpret_cast<void**>(&__func));
		__func();
	}
	inline bool NoParamReturnBool() {
		using NoParamReturnBoolFn = bool (*)();
		static NoParamReturnBoolFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnBool", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char NoParamReturnChar8() {
		using NoParamReturnChar8Fn = char (*)();
		static NoParamReturnChar8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnChar8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char16_t NoParamReturnChar16() {
		using NoParamReturnChar16Fn = char16_t (*)();
		static NoParamReturnChar16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnChar16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int8_t NoParamReturnInt8() {
		using NoParamReturnInt8Fn = int8_t (*)();
		static NoParamReturnInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int16_t NoParamReturnInt16() {
		using NoParamReturnInt16Fn = int16_t (*)();
		static NoParamReturnInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int32_t NoParamReturnInt32() {
		using NoParamReturnInt32Fn = int32_t (*)();
		static NoParamReturnInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int64_t NoParamReturnInt64() {
		using NoParamReturnInt64Fn = int64_t (*)();
		static NoParamReturnInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint8_t NoParamReturnUInt8() {
		using NoParamReturnUInt8Fn = uint8_t (*)();
		static NoParamReturnUInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnUInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint16_t NoParamReturnUInt16() {
		using NoParamReturnUInt16Fn = uint16_t (*)();
		static NoParamReturnUInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnUInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint32_t NoParamReturnUInt32() {
		using NoParamReturnUInt32Fn = uint32_t (*)();
		static NoParamReturnUInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnUInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint64_t NoParamReturnUInt64() {
		using NoParamReturnUInt64Fn = uint64_t (*)();
		static NoParamReturnUInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnUInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void* NoParamReturnPointer() {
		using NoParamReturnPointerFn = void* (*)();
		static NoParamReturnPointerFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnPointer", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline float NoParamReturnFloat() {
		using NoParamReturnFloatFn = float (*)();
		static NoParamReturnFloatFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnFloat", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline double NoParamReturnDouble() {
		using NoParamReturnDoubleFn = double (*)();
		static NoParamReturnDoubleFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnDouble", reinterpret_cast<void**>(&__func));
		return __func();
	}
	using NoParamReturnFunctionFunc = void (*)();
	inline NoParamReturnFunctionFunc NoParamReturnFunction() {
		using NoParamReturnFunctionFn = NoParamReturnFunctionFunc (*)();
		static NoParamReturnFunctionFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnFunction", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::string NoParamReturnString() {
		using NoParamReturnStringFn = plg::string (*)();
		static NoParamReturnStringFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnString", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::any NoParamReturnAny() {
		using NoParamReturnAnyFn = plg::any (*)();
		static NoParamReturnAnyFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnAny", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<bool> NoParamReturnArrayBool() {
		using NoParamReturnArrayBoolFn = plg::vector<bool> (*)();
		static NoParamReturnArrayBoolFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayBool", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<char> NoParamReturnArrayChar8() {
		using NoParamReturnArrayChar8Fn = plg::vector<char> (*)();
		static NoParamReturnArrayChar8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayChar8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<char16_t> NoParamReturnArrayChar16() {
		using NoParamReturnArrayChar16Fn = plg::vector<char16_t> (*)();
		static NoParamReturnArrayChar16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayChar16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int8_t> NoParamReturnArrayInt8() {
		using NoParamReturnArrayInt8Fn = plg::vector<int8_t> (*)();
		static NoParamReturnArrayInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int16_t> NoParamReturnArrayInt16() {
		using NoParamReturnArrayInt16Fn = plg::vector<int16_t> (*)();
		static NoParamReturnArrayInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int32_t> NoParamReturnArrayInt32() {
		using NoParamReturnArrayInt32Fn = plg::vector<int32_t> (*)();
		static NoParamReturnArrayInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<int64_t> NoParamReturnArrayInt64() {
		using NoParamReturnArrayInt64Fn = plg::vector<int64_t> (*)();
		static NoParamReturnArrayInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint8_t> NoParamReturnArrayUInt8() {
		using NoParamReturnArrayUInt8Fn = plg::vector<uint8_t> (*)();
		static NoParamReturnArrayUInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint16_t> NoParamReturnArrayUInt16() {
		using NoParamReturnArrayUInt16Fn = plg::vector<uint16_t> (*)();
		static NoParamReturnArrayUInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint32_t> NoParamReturnArrayUInt32() {
		using NoParamReturnArrayUInt32Fn = plg::vector<uint32_t> (*)();
		static NoParamReturnArrayUInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<uint64_t> NoParamReturnArrayUInt64() {
		using NoParamReturnArrayUInt64Fn = plg::vector<uint64_t> (*)();
		static NoParamReturnArrayUInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<void*> NoParamReturnArrayPointer() {
		using NoParamReturnArrayPointerFn = plg::vector<void*> (*)();
		static NoParamReturnArrayPointerFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayPointer", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<float> NoParamReturnArrayFloat() {
		using NoParamReturnArrayFloatFn = plg::vector<float> (*)();
		static NoParamReturnArrayFloatFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayFloat", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<double> NoParamReturnArrayDouble() {
		using NoParamReturnArrayDoubleFn = plg::vector<double> (*)();
		static NoParamReturnArrayDoubleFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayDouble", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<plg::string> NoParamReturnArrayString() {
		using NoParamReturnArrayStringFn = plg::vector<plg::string> (*)();
		static NoParamReturnArrayStringFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayString", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vector<plg::any> NoParamReturnArrayAny() {
		using NoParamReturnArrayAnyFn = plg::vector<plg::any> (*)();
		static NoParamReturnArrayAnyFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnArrayAny", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vec2 NoParamReturnVector2() {
		using NoParamReturnVector2Fn = plg::vec2 (*)();
		static NoParamReturnVector2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnVector2", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vec3 NoParamReturnVector3() {
		using NoParamReturnVector3Fn = plg::vec3 (*)();
		static NoParamReturnVector3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnVector3", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::vec4 NoParamReturnVector4() {
		using NoParamReturnVector4Fn = plg::vec4 (*)();
		static NoParamReturnVector4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnVector4", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plg::mat4x4 NoParamReturnMatrix4x4() {
		using NoParamReturnMatrix4x4Fn = plg::mat4x4 (*)();
		static NoParamReturnMatrix4x4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.NoParamReturnMatrix4x4", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void Param1(int32_t a) {
		using Param1Fn = void (*)(int32_t);
		static Param1Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param1", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void Param2(int32_t a, float b) {
		using Param2Fn = void (*)(int32_t, float);
		static Param2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param2", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void Param3(int32_t a, float b, double c) {
		using Param3Fn = void (*)(int32_t, float, double);
		static Param3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param3", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void Param4(int32_t a, float b, double c, const plg::vec4& d) {
		using Param4Fn = void (*)(int32_t, float, double, const plg::vec4&);
		static Param4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param4", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void Param5(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e) {
		using Param5Fn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&);
		static Param5Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param5", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void Param6(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f) {
		using Param6Fn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char);
		static Param6Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param6", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void Param7(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g) {
		using Param7Fn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&);
		static Param7Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param7", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void Param8(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
		using Param8Fn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t);
		static Param8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param8", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void Param9(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
		using Param9Fn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t);
		static Param9Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param9", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void Param10(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
		using Param10Fn = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t, void*);
		static Param10Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.Param10", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRef1(int32_t& a) {
		using ParamRef1Fn = void (*)(int32_t&);
		static ParamRef1Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef1", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void ParamRef2(int32_t& a, float& b) {
		using ParamRef2Fn = void (*)(int32_t&, float&);
		static ParamRef2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef2", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void ParamRef3(int32_t& a, float& b, double& c) {
		using ParamRef3Fn = void (*)(int32_t&, float&, double&);
		static ParamRef3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef3", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void ParamRef4(int32_t& a, float& b, double& c, plg::vec4& d) {
		using ParamRef4Fn = void (*)(int32_t&, float&, double&, plg::vec4&);
		static ParamRef4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef4", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void ParamRef5(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e) {
		using ParamRef5Fn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&);
		static ParamRef5Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef5", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void ParamRef6(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f) {
		using ParamRef6Fn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&);
		static ParamRef6Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef6", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void ParamRef7(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g) {
		using ParamRef7Fn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&);
		static ParamRef7Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef7", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void ParamRef8(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
		using ParamRef8Fn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&);
		static ParamRef8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef8", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void ParamRef9(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
		using ParamRef9Fn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&);
		static ParamRef9Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef9", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void ParamRef10(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
		using ParamRef10Fn = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&, void*&);
		static ParamRef10Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRef10", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRefVectors(plg::vector<bool>& p1, plg::vector<char>& p2, plg::vector<char16_t>& p3, plg::vector<int8_t>& p4, plg::vector<int16_t>& p5, plg::vector<int32_t>& p6, plg::vector<int64_t>& p7, plg::vector<uint8_t>& p8, plg::vector<uint16_t>& p9, plg::vector<uint32_t>& p10, plg::vector<uint64_t>& p11, plg::vector<void*>& p12, plg::vector<float>& p13, plg::vector<double>& p14, plg::vector<plg::string>& p15) {
		using ParamRefVectorsFn = void (*)(plg::vector<bool>&, plg::vector<char>&, plg::vector<char16_t>&, plg::vector<int8_t>&, plg::vector<int16_t>&, plg::vector<int32_t>&, plg::vector<int64_t>&, plg::vector<uint8_t>&, plg::vector<uint16_t>&, plg::vector<uint32_t>&, plg::vector<uint64_t>&, plg::vector<void*>&, plg::vector<float>&, plg::vector<double>&, plg::vector<plg::string>&);
		static ParamRefVectorsFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamRefVectors", reinterpret_cast<void**>(&__func));
		__func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}
	inline int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
		using ParamAllPrimitivesFn = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
		static ParamAllPrimitivesFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamAllPrimitives", reinterpret_cast<void**>(&__func));
		return __func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	}
	inline void ParamVariant(const plg::any& p1, const plg::vector<plg::any>& p2) {
		using ParamVariantFn = void (*)(const plg::any&, const plg::vector<plg::any>&);
		static ParamVariantFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamVariant", reinterpret_cast<void**>(&__func));
		__func(p1, p2);
	}
	inline void ParamVariantRef(plg::any& p1, plg::vector<plg::any>& p2) {
		using ParamVariantRefFn = void (*)(plg::any&, plg::vector<plg::any>&);
		static ParamVariantRefFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ParamVariantRef", reinterpret_cast<void**>(&__func));
		__func(p1, p2);
	}
	using FuncVoid = void (*)();
	inline void CallFuncVoid(FuncVoid func) {
		using CallFuncVoidFn = void (*)(FuncVoid);
		static CallFuncVoidFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncVoid", reinterpret_cast<void**>(&__func));
		__func(func);
	}
	using FuncBool = bool (*)();
	inline bool CallFuncBool(FuncBool func) {
		using CallFuncBoolFn = bool (*)(FuncBool);
		static CallFuncBoolFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncBool", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar8 = char (*)();
	inline char CallFuncChar8(FuncChar8 func) {
		using CallFuncChar8Fn = char (*)(FuncChar8);
		static CallFuncChar8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncChar8", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar16 = char16_t (*)();
	inline char16_t CallFuncChar16(FuncChar16 func) {
		using CallFuncChar16Fn = char16_t (*)(FuncChar16);
		static CallFuncChar16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncChar16", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt8 = int8_t (*)();
	inline int8_t CallFuncInt8(FuncInt8 func) {
		using CallFuncInt8Fn = int8_t (*)(FuncInt8);
		static CallFuncInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt8", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt16 = int16_t (*)();
	inline int16_t CallFuncInt16(FuncInt16 func) {
		using CallFuncInt16Fn = int16_t (*)(FuncInt16);
		static CallFuncInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt16", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt32 = int32_t (*)();
	inline int32_t CallFuncInt32(FuncInt32 func) {
		using CallFuncInt32Fn = int32_t (*)(FuncInt32);
		static CallFuncInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt32", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt64 = int64_t (*)();
	inline int64_t CallFuncInt64(FuncInt64 func) {
		using CallFuncInt64Fn = int64_t (*)(FuncInt64);
		static CallFuncInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt64", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt8 = uint8_t (*)();
	inline uint8_t CallFuncUInt8(FuncUInt8 func) {
		using CallFuncUInt8Fn = uint8_t (*)(FuncUInt8);
		static CallFuncUInt8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt8", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt16 = uint16_t (*)();
	inline uint16_t CallFuncUInt16(FuncUInt16 func) {
		using CallFuncUInt16Fn = uint16_t (*)(FuncUInt16);
		static CallFuncUInt16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt16", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt32 = uint32_t (*)();
	inline uint32_t CallFuncUInt32(FuncUInt32 func) {
		using CallFuncUInt32Fn = uint32_t (*)(FuncUInt32);
		static CallFuncUInt32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt32", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt64 = uint64_t (*)();
	inline uint64_t CallFuncUInt64(FuncUInt64 func) {
		using CallFuncUInt64Fn = uint64_t (*)(FuncUInt64);
		static CallFuncUInt64Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt64", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncPtr = void* (*)();
	inline void* CallFuncPtr(FuncPtr func) {
		using CallFuncPtrFn = void* (*)(FuncPtr);
		static CallFuncPtrFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncPtr", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncFloat = float (*)();
	inline float CallFuncFloat(FuncFloat func) {
		using CallFuncFloatFn = float (*)(FuncFloat);
		static CallFuncFloatFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncFloat", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncDouble = double (*)();
	inline double CallFuncDouble(FuncDouble func) {
		using CallFuncDoubleFn = double (*)(FuncDouble);
		static CallFuncDoubleFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncDouble", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncString = plg::string (*)();
	inline plg::string CallFuncString(FuncString func) {
		using CallFuncStringFn = plg::string (*)(FuncString);
		static CallFuncStringFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncString", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncAny = plg::any (*)();
	inline plg::any CallFuncAny(FuncAny func) {
		using CallFuncAnyFn = plg::any (*)(FuncAny);
		static CallFuncAnyFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncAny", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncFunction = void* (*)();
	inline void* CallFuncFunction(FuncFunction func) {
		using CallFuncFunctionFn = void* (*)(FuncFunction);
		static CallFuncFunctionFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncFunction", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncBoolVector = plg::vector<bool> (*)();
	inline plg::vector<bool> CallFuncBoolVector(FuncBoolVector func) {
		using CallFuncBoolVectorFn = plg::vector<bool> (*)(FuncBoolVector);
		static CallFuncBoolVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncBoolVector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar8Vector = plg::vector<char> (*)();
	inline plg::vector<char> CallFuncChar8Vector(FuncChar8Vector func) {
		using CallFuncChar8VectorFn = plg::vector<char> (*)(FuncChar8Vector);
		static CallFuncChar8VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncChar8Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncChar16Vector = plg::vector<char16_t> (*)();
	inline plg::vector<char16_t> CallFuncChar16Vector(FuncChar16Vector func) {
		using CallFuncChar16VectorFn = plg::vector<char16_t> (*)(FuncChar16Vector);
		static CallFuncChar16VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncChar16Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt8Vector = plg::vector<int8_t> (*)();
	inline plg::vector<int8_t> CallFuncInt8Vector(FuncInt8Vector func) {
		using CallFuncInt8VectorFn = plg::vector<int8_t> (*)(FuncInt8Vector);
		static CallFuncInt8VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt8Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt16Vector = plg::vector<int16_t> (*)();
	inline plg::vector<int16_t> CallFuncInt16Vector(FuncInt16Vector func) {
		using CallFuncInt16VectorFn = plg::vector<int16_t> (*)(FuncInt16Vector);
		static CallFuncInt16VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt16Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt32Vector = plg::vector<int32_t> (*)();
	inline plg::vector<int32_t> CallFuncInt32Vector(FuncInt32Vector func) {
		using CallFuncInt32VectorFn = plg::vector<int32_t> (*)(FuncInt32Vector);
		static CallFuncInt32VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt32Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncInt64Vector = plg::vector<int64_t> (*)();
	inline plg::vector<int64_t> CallFuncInt64Vector(FuncInt64Vector func) {
		using CallFuncInt64VectorFn = plg::vector<int64_t> (*)(FuncInt64Vector);
		static CallFuncInt64VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncInt64Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt8Vector = plg::vector<uint8_t> (*)();
	inline plg::vector<uint8_t> CallFuncUInt8Vector(FuncUInt8Vector func) {
		using CallFuncUInt8VectorFn = plg::vector<uint8_t> (*)(FuncUInt8Vector);
		static CallFuncUInt8VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt8Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt16Vector = plg::vector<uint16_t> (*)();
	inline plg::vector<uint16_t> CallFuncUInt16Vector(FuncUInt16Vector func) {
		using CallFuncUInt16VectorFn = plg::vector<uint16_t> (*)(FuncUInt16Vector);
		static CallFuncUInt16VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt16Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt32Vector = plg::vector<uint32_t> (*)();
	inline plg::vector<uint32_t> CallFuncUInt32Vector(FuncUInt32Vector func) {
		using CallFuncUInt32VectorFn = plg::vector<uint32_t> (*)(FuncUInt32Vector);
		static CallFuncUInt32VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt32Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncUInt64Vector = plg::vector<uint64_t> (*)();
	inline plg::vector<uint64_t> CallFuncUInt64Vector(FuncUInt64Vector func) {
		using CallFuncUInt64VectorFn = plg::vector<uint64_t> (*)(FuncUInt64Vector);
		static CallFuncUInt64VectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncUInt64Vector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncPtrVector = plg::vector<void*> (*)();
	inline plg::vector<void*> CallFuncPtrVector(FuncPtrVector func) {
		using CallFuncPtrVectorFn = plg::vector<void*> (*)(FuncPtrVector);
		static CallFuncPtrVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncPtrVector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncFloatVector = plg::vector<float> (*)();
	inline plg::vector<float> CallFuncFloatVector(FuncFloatVector func) {
		using CallFuncFloatVectorFn = plg::vector<float> (*)(FuncFloatVector);
		static CallFuncFloatVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncFloatVector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncStringVector = plg::vector<plg::string> (*)();
	inline plg::vector<plg::string> CallFuncStringVector(FuncStringVector func) {
		using CallFuncStringVectorFn = plg::vector<plg::string> (*)(FuncStringVector);
		static CallFuncStringVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncStringVector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncAnyVector = plg::vector<plg::any> (*)();
	inline plg::vector<plg::any> CallFuncAnyVector(FuncAnyVector func) {
		using CallFuncAnyVectorFn = plg::vector<plg::any> (*)(FuncAnyVector);
		static CallFuncAnyVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncAnyVector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncDoubleVector = plg::vector<double> (*)();
	inline plg::vector<double> CallFuncDoubleVector(FuncDoubleVector func) {
		using CallFuncDoubleVectorFn = plg::vector<double> (*)(FuncDoubleVector);
		static CallFuncDoubleVectorFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncDoubleVector", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncVec2 = plg::vec2 (*)();
	inline plg::vec2 CallFuncVec2(FuncVec2 func) {
		using CallFuncVec2Fn = plg::vec2 (*)(FuncVec2);
		static CallFuncVec2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncVec2", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncVec3 = plg::vec3 (*)();
	inline plg::vec3 CallFuncVec3(FuncVec3 func) {
		using CallFuncVec3Fn = plg::vec3 (*)(FuncVec3);
		static CallFuncVec3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncVec3", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncVec4 = plg::vec4 (*)();
	inline plg::vec4 CallFuncVec4(FuncVec4 func) {
		using CallFuncVec4Fn = plg::vec4 (*)(FuncVec4);
		static CallFuncVec4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncVec4", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using FuncMat4x4 = plg::mat4x4 (*)();
	inline plg::mat4x4 CallFuncMat4x4(FuncMat4x4 func) {
		using CallFuncMat4x4Fn = plg::mat4x4 (*)(FuncMat4x4);
		static CallFuncMat4x4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFuncMat4x4", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func1 = int32_t (*)(const plg::vec3&);
	inline int32_t CallFunc1(Func1 func) {
		using CallFunc1Fn = int32_t (*)(Func1);
		static CallFunc1Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc1", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func2 = char (*)(float, int64_t);
	inline char CallFunc2(Func2 func) {
		using CallFunc2Fn = char (*)(Func2);
		static CallFunc2Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc2", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func3 = void (*)(void*, const plg::vec4&, const plg::string&);
	inline void CallFunc3(Func3 func) {
		using CallFunc3Fn = void (*)(Func3);
		static CallFunc3Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc3", reinterpret_cast<void**>(&__func));
		__func(func);
	}
	using Func4 = plg::vec4 (*)(bool, int32_t, char16_t, const plg::mat4x4&);
	inline plg::vec4 CallFunc4(Func4 func) {
		using CallFunc4Fn = plg::vec4 (*)(Func4);
		static CallFunc4Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc4", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func5 = bool (*)(int8_t, const plg::vec2&, void*, double, const plg::vector<uint64_t>&);
	inline bool CallFunc5(Func5 func) {
		using CallFunc5Fn = bool (*)(Func5);
		static CallFunc5Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc5", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func6 = int64_t (*)(const plg::string&, float, const plg::vector<float>&, int16_t, const plg::vector<uint8_t>&, void*);
	inline int64_t CallFunc6(Func6 func) {
		using CallFunc6Fn = int64_t (*)(Func6);
		static CallFunc6Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc6", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func7 = double (*)(const plg::vector<char>&, uint16_t, char16_t, const plg::vector<uint32_t>&, const plg::vec4&, bool, uint64_t);
	inline double CallFunc7(Func7 func) {
		using CallFunc7Fn = double (*)(Func7);
		static CallFunc7Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc7", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func8 = plg::mat4x4 (*)(const plg::vec3&, const plg::vector<uint32_t>&, int16_t, bool, const plg::vec4&, const plg::vector<char16_t>&, char16_t, int32_t);
	inline plg::mat4x4 CallFunc8(Func8 func) {
		using CallFunc8Fn = plg::mat4x4 (*)(Func8);
		static CallFunc8Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc8", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func9 = void (*)(float, const plg::vec2&, const plg::vector<int8_t>&, uint64_t, bool, const plg::string&, const plg::vec4&, int16_t, void*);
	inline void CallFunc9(Func9 func) {
		using CallFunc9Fn = void (*)(Func9);
		static CallFunc9Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc9", reinterpret_cast<void**>(&__func));
		__func(func);
	}
	using Func10 = uint32_t (*)(const plg::vec4&, const plg::mat4x4&, const plg::vector<uint32_t>&, uint64_t, const plg::vector<char>&, int32_t, bool, const plg::vec2&, int64_t, double);
	inline uint32_t CallFunc10(Func10 func) {
		using CallFunc10Fn = uint32_t (*)(Func10);
		static CallFunc10Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc10", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func11 = void* (*)(const plg::vector<bool>&, char16_t, uint8_t, double, const plg::vec3&, const plg::vector<int8_t>&, int64_t, uint16_t, float, const plg::vec2&, uint32_t);
	inline void* CallFunc11(Func11 func) {
		using CallFunc11Fn = void* (*)(Func11);
		static CallFunc11Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc11", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func12 = bool (*)(void*, const plg::vector<double>&, uint32_t, double, bool, int32_t, int8_t, uint64_t, float, const plg::vector<void*>&, int64_t, char);
	inline bool CallFunc12(Func12 func) {
		using CallFunc12Fn = bool (*)(Func12);
		static CallFunc12Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc12", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func13 = plg::string (*)(int64_t, const plg::vector<char>&, uint16_t, float, const plg::vector<bool>&, const plg::vec4&, const plg::string&, int32_t, const plg::vec3&, void*, const plg::vec2&, const plg::vector<uint8_t>&, int16_t);
	inline plg::string CallFunc13(Func13 func) {
		using CallFunc13Fn = plg::string (*)(Func13);
		static CallFunc13Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc13", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func14 = plg::vector<plg::string> (*)(const plg::vector<char>&, const plg::vector<uint32_t>&, const plg::mat4x4&, bool, char16_t, int32_t, const plg::vector<float>&, uint16_t, const plg::vector<uint8_t>&, int8_t, const plg::vec3&, const plg::vec4&, double, void*);
	inline plg::vector<plg::string> CallFunc14(Func14 func) {
		using CallFunc14Fn = plg::vector<plg::string> (*)(Func14);
		static CallFunc14Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc14", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func15 = int16_t (*)(const plg::vector<int16_t>&, const plg::mat4x4&, const plg::vec4&, void*, uint64_t, const plg::vector<uint32_t>&, bool, float, const plg::vector<char16_t>&, uint8_t, int32_t, const plg::vec2&, uint16_t, double, const plg::vector<uint8_t>&);
	inline int16_t CallFunc15(Func15 func) {
		using CallFunc15Fn = int16_t (*)(Func15);
		static CallFunc15Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc15", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func16 = void* (*)(const plg::vector<bool>&, int16_t, const plg::vector<int8_t>&, const plg::vec4&, const plg::mat4x4&, const plg::vec2&, const plg::vector<uint64_t>&, const plg::vector<char>&, const plg::string&, int64_t, const plg::vector<uint32_t>&, const plg::vec3&, float, double, int8_t, uint16_t);
	inline void* CallFunc16(Func16 func) {
		using CallFunc16Fn = void* (*)(Func16);
		static CallFunc16Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc16", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func17 = void (*)(int32_t&);
	inline plg::string CallFunc17(Func17 func) {
		using CallFunc17Fn = plg::string (*)(Func17);
		static CallFunc17Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc17", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func18 = plg::vec2 (*)(int8_t&, int16_t&);
	inline plg::string CallFunc18(Func18 func) {
		using CallFunc18Fn = plg::string (*)(Func18);
		static CallFunc18Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc18", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func19 = void (*)(uint32_t&, plg::vec3&, plg::vector<uint32_t>&);
	inline plg::string CallFunc19(Func19 func) {
		using CallFunc19Fn = plg::string (*)(Func19);
		static CallFunc19Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc19", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func20 = int32_t (*)(char16_t&, plg::vec4&, plg::vector<uint64_t>&, char&);
	inline plg::string CallFunc20(Func20 func) {
		using CallFunc20Fn = plg::string (*)(Func20);
		static CallFunc20Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc20", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func21 = float (*)(plg::mat4x4&, plg::vector<int32_t>&, plg::vec2&, bool&, double&);
	inline plg::string CallFunc21(Func21 func) {
		using CallFunc21Fn = plg::string (*)(Func21);
		static CallFunc21Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc21", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func22 = uint64_t (*)(void*&, uint32_t&, plg::vector<double>&, int16_t&, plg::string&, plg::vec4&);
	inline plg::string CallFunc22(Func22 func) {
		using CallFunc22Fn = plg::string (*)(Func22);
		static CallFunc22Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc22", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func23 = void (*)(uint64_t&, plg::vec2&, plg::vector<int16_t>&, char16_t&, float&, int8_t&, plg::vector<uint8_t>&);
	inline plg::string CallFunc23(Func23 func) {
		using CallFunc23Fn = plg::string (*)(Func23);
		static CallFunc23Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc23", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func24 = plg::mat4x4 (*)(plg::vector<char>&, int64_t&, plg::vector<uint8_t>&, plg::vec4&, uint64_t&, plg::vector<void*>&, double&, plg::vector<void*>&);
	inline plg::string CallFunc24(Func24 func) {
		using CallFunc24Fn = plg::string (*)(Func24);
		static CallFunc24Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc24", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func25 = double (*)(int32_t&, plg::vector<void*>&, bool&, uint8_t&, plg::string&, plg::vec3&, int64_t&, plg::vec4&, uint16_t&);
	inline plg::string CallFunc25(Func25 func) {
		using CallFunc25Fn = plg::string (*)(Func25);
		static CallFunc25Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc25", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func26 = char (*)(char16_t&, plg::vec2&, plg::mat4x4&, plg::vector<float>&, int16_t&, uint64_t&, uint32_t&, plg::vector<uint16_t>&, void*&, bool&);
	inline plg::string CallFunc26(Func26 func) {
		using CallFunc26Fn = plg::string (*)(Func26);
		static CallFunc26Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc26", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func27 = uint8_t (*)(float&, plg::vec3&, void*&, plg::vec2&, plg::vector<int16_t>&, plg::mat4x4&, bool&, plg::vec4&, int8_t&, int32_t&, plg::vector<uint8_t>&);
	inline plg::string CallFunc27(Func27 func) {
		using CallFunc27Fn = plg::string (*)(Func27);
		static CallFunc27Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc27", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func28 = plg::string (*)(void*&, uint16_t&, plg::vector<uint32_t>&, plg::mat4x4&, float&, plg::vec4&, plg::string&, plg::vector<uint64_t>&, int64_t&, bool&, plg::vec3&, plg::vector<float>&);
	inline plg::string CallFunc28(Func28 func) {
		using CallFunc28Fn = plg::string (*)(Func28);
		static CallFunc28Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc28", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func29 = plg::vector<plg::string> (*)(plg::vec4&, int32_t&, plg::vector<int8_t>&, double&, bool&, int8_t&, plg::vector<uint16_t>&, float&, plg::string&, plg::mat4x4&, uint64_t&, plg::vec3&, plg::vector<int64_t>&);
	inline plg::string CallFunc29(Func29 func) {
		using CallFunc29Fn = plg::string (*)(Func29);
		static CallFunc29Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc29", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func30 = int32_t (*)(void*&, plg::vec4&, int64_t&, plg::vector<uint32_t>&, bool&, plg::string&, plg::vec3&, plg::vector<uint8_t>&, float&, plg::vec2&, plg::mat4x4&, int8_t&, plg::vector<float>&, double&);
	inline plg::string CallFunc30(Func30 func) {
		using CallFunc30Fn = plg::string (*)(Func30);
		static CallFunc30Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc30", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func31 = plg::vec3 (*)(char&, uint32_t&, plg::vector<uint64_t>&, plg::vec4&, plg::string&, bool&, int64_t&, plg::vec2&, int8_t&, uint16_t&, plg::vector<int16_t>&, plg::mat4x4&, plg::vec3&, float&, plg::vector<double>&);
	inline plg::string CallFunc31(Func31 func) {
		using CallFunc31Fn = plg::string (*)(Func31);
		static CallFunc31Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc31", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func32 = double (*)(int32_t&, uint16_t&, plg::vector<int8_t>&, plg::vec4&, void*&, plg::vector<uint32_t>&, plg::mat4x4&, uint64_t&, plg::string&, int64_t&, plg::vec2&, plg::vector<int8_t>&, bool&, plg::vec3&, uint8_t&, plg::vector<char16_t>&);
	inline plg::string CallFunc32(Func32 func) {
		using CallFunc32Fn = plg::string (*)(Func32);
		static CallFunc32Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc32", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	using Func33 = void (*)(plg::any&);
	inline plg::string CallFunc33(Func33 func) {
		using CallFunc33Fn = plg::string (*)(Func33);
		static CallFunc33Fn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.CallFunc33", reinterpret_cast<void**>(&__func));
		return __func(func);
	}
	inline void ReverseCall(const plg::string& test) {
		using ReverseCallFn = void (*)(const plg::string&);
		static ReverseCallFn __func = nullptr;
		if (__func == nullptr) plg::GetMethodPtr2("cross_call_worker.ReverseCall", reinterpret_cast<void**>(&__func));
		__func(test);
	}
}
