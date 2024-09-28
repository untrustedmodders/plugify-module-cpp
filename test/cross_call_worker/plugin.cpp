#include <pps/cross_call_master.h>
#include <plugify/cpp_plugin.h>
#include <plugin_export.h>
#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <limits>
#include <cstdint>
#include <unordered_map>
#include <functional>

class CrossCallWorker : public plg::IPluginEntry {
};

CrossCallWorker g_plugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_plugin)

extern "C"
PLUGIN_API void NoParamReturnVoid() {
}

extern "C"
PLUGIN_API bool NoParamReturnBool() {
	return true;
}

extern "C"
PLUGIN_API char NoParamReturnChar8() {
	return std::numeric_limits<char>::max();
}

extern "C"
PLUGIN_API char16_t NoParamReturnChar16() {
	return std::numeric_limits<char16_t>::max();
}

extern "C"
PLUGIN_API int8_t NoParamReturnInt8() {
	return std::numeric_limits<int8_t>::max();
}

extern "C"
PLUGIN_API int16_t NoParamReturnInt16() {
	return std::numeric_limits<int16_t>::max();
}

extern "C"
PLUGIN_API int32_t NoParamReturnInt32() {
	return std::numeric_limits<int32_t>::max();
}

extern "C"
PLUGIN_API int64_t NoParamReturnInt64() {
	return std::numeric_limits<int64_t>::max();
}

extern "C"
PLUGIN_API uint8_t NoParamReturnUInt8() {
	return std::numeric_limits<uint8_t>::max();
}

extern "C"
PLUGIN_API uint16_t NoParamReturnUInt16() {
	return std::numeric_limits<uint16_t>::max();
}

extern "C"
PLUGIN_API uint32_t NoParamReturnUInt32() {
	return std::numeric_limits<uint32_t>::max();
}

extern "C"
PLUGIN_API uint64_t NoParamReturnUInt64() {
	return std::numeric_limits<uint64_t>::max();
}

extern "C"
PLUGIN_API void* NoParamReturnPointer() {
	return reinterpret_cast<void*>(0x1);
}

extern "C"
PLUGIN_API float NoParamReturnFloat() {
	return std::numeric_limits<float>::max();
}

extern "C"
PLUGIN_API double NoParamReturnDouble() {
	return std::numeric_limits<double>::max();
}

using NoParamReturnFunctionFunc = void (*)();

extern "C"
PLUGIN_API NoParamReturnFunctionFunc NoParamReturnFunction() {
	return nullptr;
}

extern "C"
PLUGIN_API void NoParamReturnString(plg::string& stringRet) {
	std::construct_at(&stringRet, "Hello World");
}

extern "C"
PLUGIN_API void NoParamReturnArrayBool(std::vector<bool>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<bool>{true, false});
}

extern "C"
PLUGIN_API void NoParamReturnArrayChar8(std::vector<char>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<char>{'a', 'b', 'c', 'd'});
}

extern "C"
PLUGIN_API void NoParamReturnArrayChar16(std::vector<char16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<char16_t>{u'a', u'b', u'c', u'd'});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt8(std::vector<int8_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int8_t>{-3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt16(std::vector<int16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int16_t>{-4, -3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt32(std::vector<int32_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int32_t>{-5, -4, -3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt64(std::vector<int64_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt8(std::vector<uint8_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint8_t>{0, 1, 2, 3, 4, 5, 6, 7, 8});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt16(std::vector<uint16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint16_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt32(std::vector<uint32_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt64(std::vector<uint64_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
}

extern "C"
PLUGIN_API void NoParamReturnArrayPointer(std::vector<void*>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<void*>{reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2), reinterpret_cast<void*>(3)});
}

extern "C"
PLUGIN_API void NoParamReturnArrayFloat(std::vector<float>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<float>{-12.34f, 0.0f, 12.34f});
}

extern "C"
PLUGIN_API void NoParamReturnArrayDouble(std::vector<double>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<double>{-12.345, 0.0, 12.345});
}

extern "C"
PLUGIN_API void NoParamReturnArrayString(std::vector<plg::string>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<plg::string>{"1st string", "2nd string", "3rd element string (Should be big enough to avoid small string optimization)"});
}

extern "C"
PLUGIN_API plg::vec2 NoParamReturnVector2() {
	return {1.f, 2.f};
}

extern "C"
PLUGIN_API plg::vec3 NoParamReturnVector3() {
	return {1.f, 2.f, 3.f};
}

extern "C"
PLUGIN_API plg::vec4 NoParamReturnVector4() {
	return {1.f, 2.f, 3.f, 4.f};
}

extern "C"
PLUGIN_API plg::mat4x4 NoParamReturnMatrix4x4() {
	return {1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f};
}

extern "C"
PLUGIN_API void Param1(int32_t a) {
	const auto buffer = std::format("{}", a);
}

extern "C"
PLUGIN_API void Param2(int32_t a, float b) {
	const auto buffer = std::format("{}{:.2f}", a, b);
}

extern "C"
PLUGIN_API void Param3(int32_t a, float b, double c) {
	const auto buffer = std::format("{}{:.2f}{:.2f}", a, b, c);
}

extern "C"
PLUGIN_API void Param4(int32_t a, float b, double c, const plg::vec4& d) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}", a, b, c, d.x, d.w);
}

extern "C"
PLUGIN_API void Param5(int32_t a, float b, double c, const plg::vec4& d, const std::vector<int64_t>& e) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0});
}

extern "C"
PLUGIN_API void Param6(int32_t a, float b, double c, const plg::vec4& d, const std::vector<int64_t>& e, char f) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f));
}

extern "C"
PLUGIN_API void Param7(int32_t a, float b, double c, const plg::vec4& d, const std::vector<int64_t>& e, char f, const plg::string& g) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g);
}

extern "C"
PLUGIN_API void Param8(int32_t a, float b, double c, const plg::vec4& d, const std::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h));
}

extern "C"
PLUGIN_API void Param9(int32_t a, float b, double c, const plg::vec4& d, const std::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k);
}

extern "C"
PLUGIN_API void Param10(int32_t a, float b, double c, const plg::vec4& d, const std::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k, l);
}

extern "C"
PLUGIN_API void ParamRef1(int32_t& a) {
	a = 42;
}

extern "C"
PLUGIN_API void ParamRef2(int32_t& a, float& b) {
	a = 10;
	b = 3.14f;
}

extern "C"
PLUGIN_API void ParamRef3(int32_t& a, float& b, double& c) {
	a = -20;
	b = 2.718f;
	c = 3.14159;
}

extern "C"
PLUGIN_API void ParamRef4(int32_t& a, float& b, double& c, plg::vec4& d) {
	a = 100;
	b = -5.55f;
	c = 1.618;
	d = {1.0f, 2.0f, 3.0f, 4.0f};
}

extern "C"
PLUGIN_API void ParamRef5(int32_t& a, float& b, double& c, plg::vec4& d, std::vector<int64_t>& e) {
	a = 500;
	b = -10.5f;
	c = 2.71828;
	d = {-1.0f, -2.0f, -3.0f, -4.0f};
	e = {-6, -5, -4, -3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API void ParamRef6(int32_t& a, float& b, double& c, plg::vec4& d, std::vector<int64_t>& e, char& f) {
	a = 750;
	b = 20.0f;
	c = 1.23456;
	d = {10.0f, 20.0f, 30.0f, 40.0f};
	e = {-6, -5, -4};
	f = 'Z';
}

extern "C"
PLUGIN_API void ParamRef7(int32_t& a, float& b, double& c, plg::vec4& d, std::vector<int64_t>& e, char& f, plg::string& g) {
	a = -1000;
	b = 3.0f;
	c = -1.0;
	d = {100.0f, 200.0f, 300.0f, 400.0f};
	e = {-6, -5, -4, -3};
	f = 'Y';
	g = "Hello, World!";
}

extern "C"
PLUGIN_API void ParamRef8(int32_t& a, float& b, double& c, plg::vec4& d, std::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
	a = 999;
	b = -7.5f;
	c = 0.123456;
	d = {-100.0f, -200.0f, -300.0f, -400.0f};
	e = {-6, -5, -4, -3, -2, -1};
	f = 'X';
	g = "Goodbye, World!";
	h = 'A';
}

extern "C"
PLUGIN_API void ParamRef9(int32_t& a, float& b, double& c, plg::vec4& d, std::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
	a = -1234;
	b = 123.45f;
	c = -678.9;
	d = {987.65f, 432.1f, 123.456f, 789.123f};
	e = {-6, -5, -4, -3, -2, -1, 0, 1, 5, 9};
	f = 'W';
	g = "Testing, 1 2 3";
	h = 'B';
	k = 42;
}

extern "C"
PLUGIN_API void ParamRef10(int32_t& a, float& b, double& c, plg::vec4& d, std::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
	a = 987;
	b = -0.123f;
	c = 456.789;
	d = {-123.456f, 0.987f, 654.321f, -789.123f};
	e = {-6, -5, -4, -3, -2, -1, 0, 1, 5, 9, 4, -7};
	f = 'V';
	g = "Another string";
	h = 'C';
	k = -444;
	l = reinterpret_cast<void*>(0x12345678);
}

extern "C"
PLUGIN_API void ParamRefVectors(std::vector<bool>& p1, std::vector<char>& p2, std::vector<char16_t>& p3, std::vector<int8_t>& p4, std::vector<int16_t>& p5,
	std::vector<int32_t>& p6, std::vector<int64_t>& p7, std::vector<uint8_t>& p8, std::vector<uint16_t>& p9, std::vector<uint32_t>& p10, std::vector<uint64_t>& p11,
	std::vector<void*>& p12, std::vector<float>& p13, std::vector<double>& p14, std::vector<plg::string>& p15
) {
	p1 = {true};
	p2 = {'a', 'b', 'c'};
	p3 = {'d', 'e', 'f'};
	p4 = {-3, -2, -1, 0, 1, 2, 3};
	p5 = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
	p6 = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	p7 = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
	p8 = {0, 1, 2, 3, 4, 5, 6, 7};
	p9 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	p10 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	p11 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	p12 = {reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2)};
	p13 = {-12.34f, 0.0f, 12.34f};
	p14 = {-12.345, 0.0, 12.345};
	p15 = {"1", "12", "123", "1234", "12345", "123456"};
}

extern "C"
PLUGIN_API int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10,
	uint64_t p11, void* p12, float p13, double p14
) {
	const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{:.3f}{:.3f}", p1, static_cast<uint8_t>(p2), static_cast<uint8_t>(p3), p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	return 56;
}


// Call functions using the typedefs
extern "C"
PLUGIN_API void CallFuncVoid(cross_call_master::FuncVoid func) {
    func();
}

extern "C"
PLUGIN_API bool CallFuncBool(cross_call_master::FuncBool func) {
    bool result = func();
    return result;
}

extern "C"
PLUGIN_API char8_t CallFuncChar8(cross_call_master::FuncChar8 func) {
    char8_t result = func();
    return result;
}

extern "C"
PLUGIN_API char16_t CallFuncChar16(cross_call_master::FuncChar16 func) {
    char16_t result = func();
    return result;
}

extern "C"
PLUGIN_API int8_t CallFuncInt8(cross_call_master::FuncInt8 func) {
    int8_t result = func();
    return result;
}

extern "C"
PLUGIN_API int16_t CallFuncInt16(cross_call_master::FuncInt16 func) {
    int16_t result = func();
    return result;
}

extern "C"
PLUGIN_API int32_t CallFuncInt32(cross_call_master::FuncInt32 func) {
    int32_t result = func();
    return result;
}

extern "C"
PLUGIN_API int64_t CallFuncInt64(cross_call_master::FuncInt64 func) {
    int64_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint8_t CallFuncUInt8(cross_call_master::FuncUInt8 func) {
    uint8_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint16_t CallFuncUInt16(cross_call_master::FuncUInt16 func) {
    uint16_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint32_t CallFuncUInt32(cross_call_master::FuncUInt32 func) {
    uint32_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint64_t CallFuncUInt64(cross_call_master::FuncUInt64 func) {
    uint64_t result = func();
    return result;
}

extern "C"
PLUGIN_API void* CallFuncPtr(cross_call_master::FuncPtr func) {
    void* result = func();
    return result;
}

extern "C"
PLUGIN_API float CallFuncFloat(cross_call_master::FuncFloat func) {
    float result = func();
    return result;
}

extern "C"
PLUGIN_API double CallFuncDouble(cross_call_master::FuncDouble func) {
    double result = func();
    return result;
}

extern "C"
PLUGIN_API void* CallFuncFunction(cross_call_master::FuncFunction func) {
    void* result = func();
    return result;
}

extern "C"
PLUGIN_API void CallFuncString(plg::string* output, cross_call_master::FuncString func) {
    plg::string result = func();
    std::construct_at(output, result);
}

// Call functions for vector return types
extern "C"
PLUGIN_API void CallFuncBoolVector(std::vector<bool>* output, cross_call_master::FuncBoolVector func) {
    std::vector<bool> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncChar8Vector(std::vector<char>* output, cross_call_master::FuncChar8Vector func) {
    std::vector<char> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncChar16Vector(std::vector<char16_t>* output, cross_call_master::FuncChar16Vector func) {
    std::vector<char16_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncInt8Vector(std::vector<int8_t>* output, cross_call_master::FuncInt8Vector func) {
    std::vector<int8_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncInt16Vector(std::vector<int16_t>* output, cross_call_master::FuncInt16Vector func) {
    std::vector<int16_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncInt32Vector(std::vector<int32_t>* output, cross_call_master::FuncInt32Vector func) {
    std::vector<int32_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncInt64Vector(std::vector<int64_t>* output, cross_call_master::FuncInt64Vector func) {
    std::vector<int64_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncUInt8Vector(std::vector<uint8_t>* output, cross_call_master::FuncUInt8Vector func) {
    std::vector<uint8_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncUInt16Vector(std::vector<uint16_t>* output, cross_call_master::FuncUInt16Vector func) {
    std::vector<uint16_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncUInt32Vector(std::vector<uint32_t>* output, cross_call_master::FuncUInt32Vector func) {
    std::vector<uint32_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncUInt64Vector(std::vector<uint64_t>* output, cross_call_master::FuncUInt64Vector func) {
    std::vector<uint64_t> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncPtrVector(std::vector<void*>* output, cross_call_master::FuncPtrVector func) {
    std::vector<void*> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncFloatVector(std::vector<float>* output, cross_call_master::FuncFloatVector func) {
    std::vector<float> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncDoubleVector(std::vector<double>* output, cross_call_master::FuncDoubleVector func) {
    std::vector<double> result = func();
    std::construct_at(output, result);
}

extern "C"
PLUGIN_API void CallFuncStringVector(std::vector<plg::string>* output, cross_call_master::FuncStringVector func) {
    std::vector<plg::string> result = func();
    std::construct_at(output, result);
}

// Call functions for vector return types
extern "C"
PLUGIN_API plg::vec2 CallFuncVec2(cross_call_master::FuncVec2 func) {
    plg::vec2 result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vec3 CallFuncVec3(cross_call_master::FuncVec3 func) {
    plg::vec3 result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vec4 CallFuncVec4(cross_call_master::FuncVec4 func) {
    plg::vec4 result = func();
    return result;
}

extern "C"
PLUGIN_API plg::mat4x4 CallFuncMat4x4(cross_call_master::FuncMat4x4 func) {
    plg::mat4x4 result = func();
    return result;
}

// 1 parameter
extern "C"
PLUGIN_API int32_t CallFunc1(cross_call_master::Func1 func) {
    plg::vec3 vec{4.5f, 5.6f, 6.7f}; // Changed to random values
    return func(vec);
}

// 2 parameters
extern "C"
PLUGIN_API char CallFunc2(cross_call_master::Func2 func) {
    float f = 2.71f; // Changed to random float
    int64_t i64 = 200; // Changed to random int64_t
    return func(f, i64);
}

// 3 parameters
extern "C"
PLUGIN_API void CallFunc3(cross_call_master::Func3 func) {
    void* ptr = reinterpret_cast<void *>(12345); // Example pointer changed
    plg::vec4 vec4{7.8f, 8.9f, 9.1f, 10.2f}; // Changed to random values
    plg::string str = "RandomString"; // Changed string
    func(ptr, vec4, str);
}

// 4 parameters
extern "C"
PLUGIN_API plg::vec4 CallFunc4(cross_call_master::Func4 func) {
    bool b = false; // Changed to random bool
    int32_t u32 = 42; // Changed to random uint32_t
    char16_t ch16 = 'B'; // Changed to random character
    plg::mat4x4 mat; // Assume it's initialized properly
    return func(b, u32, ch16, mat);
}

// 5 parameters
extern "C"
PLUGIN_API bool CallFunc5(cross_call_master::Func5 func) {
    int8_t i8 = 10; // Changed to random int8_t
    plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
    void* ptr = reinterpret_cast<void *>(67890); // Example pointer changed
    double d = 1.618; // Changed to random double
    std::vector<uint64_t> vec64{4, 5, 6}; // Changed to random values
    return func(i8, vec2, ptr, d, vec64);
}

// 6 parameters
extern "C"
PLUGIN_API int64_t CallFunc6(cross_call_master::Func6 func) {
    plg::string str = "AnotherString"; // Changed string
    float f = 4.56f; // Changed to random float
    std::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed to random values
    int16_t i16 = 30; // Changed to random int16_t
    std::vector<uint8_t> vecU8{3, 4, 5}; // Changed to random values
    void* ptr = reinterpret_cast<void *>(24680); // Example pointer changed
    return func(str, f, vecF, i16, vecU8, ptr);
}

// 7 parameters
extern "C"
PLUGIN_API double CallFunc7(cross_call_master::Func7 func) {
    std::vector<char> vecC{'X', 'Y', 'Z'}; // Changed to random chars
    uint16_t u16 = 20; // Changed to random uint16_t
    char16_t ch16 = 'C'; // Changed to random character
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
    plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
    bool b = false; // Changed to random bool
    uint64_t u64 = 200; // Changed to random uint64_t
    return func(vecC, u16, ch16, vecU32, vec4, b, u64);
}

// 8 parameters
extern "C"
PLUGIN_API plg::mat4x4 CallFunc8(cross_call_master::Func8 func) {
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
    int16_t i16 = 30; // Changed to random int16_t
    bool b = false; // Changed to random bool
    plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
    std::vector<char16_t> vecC16{ 'D', 'E' }; // Changed to random chars
    char16_t ch16 = L'B'; // Changed to random character
    int32_t i32 = 50; // Changed to random int32_t
    return func(vec3, vecU32, i16, b, vec4, vecC16, ch16, i32);
}

// 9 parameters
extern "C"
PLUGIN_API void CallFunc9(cross_call_master::Func9 func) {
    float f = 2.71f; // Changed to random float
    plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
    std::vector<int8_t> vecI8{4, 5, 6}; // Changed to random values
    uint64_t u64 = 250; // Changed to random uint64_t
    bool b = false; // Changed to random bool
    plg::string str = "Random"; // Changed string
    plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
    int16_t i16 = 30; // Changed to random int16_t
    void* ptr = reinterpret_cast<void *>(13579); // Example pointer changed
    func(f, vec2, vecI8, u64, b, str, vec4, i16, ptr);
}

// 10 parameters
extern "C"
PLUGIN_API uint32_t CallFunc10(cross_call_master::Func10 func) {
    plg::vec4 vec4{5.6f, 7.8f, 8.9f, 9.0f}; // Changed to random values
    plg::mat4x4 mat; // Assume it's initialized properly
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
    uint64_t u64 = 150; // Changed to random uint64_t
    std::vector<char> vecC{'X', 'Y', 'Z'}; // Changed to random chars
    int32_t i32 = 60; // Changed to random int32_t
    bool b = false; // Changed to random bool
    plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
    int64_t i64 = 75; // Changed to random int64_t
    double d = 2.71; // Changed to random double
    return func(vec4, mat, vecU32, u64, vecC, i32, b, vec2, i64, d);
}

// 11 parameters
extern "C"
PLUGIN_API void* CallFunc11(cross_call_master::Func11 func) {
    std::vector<bool> vecB{false, true, false}; // Changed to random bools
    char16_t ch16 = 'C'; // Changed to random character
    uint8_t u8 = 10; // Changed to random uint8_t
    double d = 2.71; // Changed to random double
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
    std::vector<int8_t> vecI8{3, 4, 5}; // Changed to random values
    int64_t i64 = 150; // Changed to random int64_t
    uint16_t u16 = 20; // Changed to random uint16_t
    float f = 2.0f; // Changed to random float
    plg::vec2 vec2{4.5f, 6.7f}; // Changed to random values
    uint32_t u32 = 30; // Changed to random uint32_t
    return func(vecB, ch16, u8, d, vec3, vecI8, i64, u16, f, vec2, u32);
}

// 12 parameters
extern "C"
PLUGIN_API bool CallFunc12(cross_call_master::Func12 func) {
    void* ptr = reinterpret_cast<void *>(98765); // Example pointer changed
    std::vector<double> vecD{4.0, 5.0, 6.0}; // Changed to random values
    uint32_t u32 = 30; // Changed to random uint32_t
    double d = 1.41; // Changed to random double
    bool b = false; // Changed to random bool
    int32_t i32 = 25; // Changed to random int32_t
    int8_t i8 = 10; // Changed to random int8_t
    uint64_t u64 = 300; // Changed to random uint64_t
    float f = 2.72f; // Changed to random float
    std::vector<void*> vecPtr{reinterpret_cast<void *>(2), reinterpret_cast<void *>(3), reinterpret_cast<void *>(4)}; // Changed to random values
    int64_t i64 = 200; // Changed to random int64_t
    char ch = 'B'; // Changed to random character
    return func(ptr, vecD, u32, d, b, i32, i8, u64, f, vecPtr, i64, ch);
}

// 13 parameters
extern "C"
PLUGIN_API void CallFunc13(plg::string* output, cross_call_master::Func13 func) {
    int64_t i64 = 75; // Changed to random int64_t
    std::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
    uint16_t u16 = 20; // Changed to random uint16_t
    float f = 2.71f; // Changed to random float
    std::vector<bool> vecB{false, true, false}; // Changed to random bools
    plg::vec4 vec4{5.6f, 7.8f, 9.0f, 10.1f}; // Changed to random values
    plg::string str = "RandomString"; // Changed string
    int32_t i32 = 30; // Changed to random int32_t
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
    void* ptr = reinterpret_cast<void *>(13579); // Example pointer changed
    plg::vec2 vec2{4.5f, 6.7f}; // Changed to random values
    std::vector<uint8_t> vecU8{2, 3, 4}; // Changed to random values
    int16_t i16 = 20; // Changed to random int16_t
    auto ret = func(i64, vecC, u16, f, vecB, vec4, str, i32, vec3, ptr, vec2, vecU8, i16);
    std::construct_at(output, std::move(ret));
}

// 14 parameters
extern "C"
PLUGIN_API void CallFunc14(std::vector<plg::string>* output, cross_call_master::Func14 func) {
    std::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
    plg::mat4x4 mat; // Assume it's initialized properly
    bool b = false; // Changed to random bool
    char16_t ch16 = L'B'; // Changed to random character
    int32_t i32 = 25; // Changed to random int32_t
    std::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed to random values
    uint16_t u16 = 30; // Changed to random uint16_t
    std::vector<uint8_t> vecU8{3, 4, 5}; // Changed to random values
    int8_t i8 = 10; // Changed to random int8_t
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
    plg::vec4 vec4{5.6f, 7.8f, 9.0f, 10.1f}; // Changed to random values
    double d = 2.72; // Changed to random double
    void* ptr = reinterpret_cast<void *>(54321); // Example pointer changed
    auto ret = func(vecC, vecU32, mat, b, ch16, i32, vecF, u16, vecU8, i8, vec3, vec4, d, ptr);
    std::construct_at(output, std::move(ret));
}

// 15 parameters
extern "C"
PLUGIN_API int16_t CallFunc15(cross_call_master::Func15 func) {
    std::vector<int16_t> vecI16{4, 5, 6}; // Changed to random values
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vec4 vec4{7.8f, 8.9f, 9.0f, 10.1f}; // Changed to random values
    void* ptr = reinterpret_cast<void *>(12345); // Example pointer changed
    uint64_t u64 = 200; // Changed to random uint64_t
    std::vector<uint32_t> vecU32{5, 6, 7}; // Changed to random values
    bool b = false; // Changed to random bool
    float f = 3.14f; // Changed to random float
    std::vector<char16_t> vecC16{'D', 'E'}; // Changed to random chars
    uint8_t u8 = 6; // Changed to random uint8_t
    int32_t i32 = 25; // Changed to random int32_t
    plg::vec2 vec2{5.6f, 7.8f}; // Changed to random values
    uint16_t u16 = 40; // Changed to random uint16_t
    double d = 2.71; // Changed to random double
    std::vector<uint8_t> vecU8{1, 3, 5}; // Changed to random values
    return func(vecI16, mat, vec4, ptr, u64, vecU32, b, f, vecC16, u8, i32, vec2, u16, d, vecU8);
}

// 16 parameters
extern "C"
PLUGIN_API void* CallFunc16(cross_call_master::Func16 func) {
    std::vector<bool> vecB{true, true, false}; // Changed to random bools
    int16_t i16 = 20; // Changed to random int16_t
    std::vector<int8_t> vecI8{2, 3, 4}; // Changed to random values
    plg::vec4 vec4{7.8f, 8.9f, 9.0f, 10.1f}; // Changed to random values
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vec2 vec2{5.6f, 7.8f}; // Changed to random values
    std::vector<uint64_t> vecU64{5, 6, 7}; // Changed to random values
    std::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
    plg::string str = "DifferentString"; // Changed string
    int64_t i64 = 300; // Changed to random int64_t
    std::vector<uint32_t> vecU32{6, 7, 8}; // Changed to random values
    plg::vec3 vec3{5.0f, 6.0f, 7.0f}; // Changed to random values
    float f = 3.14f; // Changed to random float
    double d = 2.718; // Changed to random double
    int8_t i8 = 6; // Changed to random int8_t
    uint16_t u16 = 30; // Changed to random uint16_t
    return func(vecB, i16, vecI8, vec4, mat, vec2, vecU64, vecC, str, i64, vecU32, vec3, f, d, i8, u16);
}


namespace {
    // Helper function to convert a vector of integers to a string
    template<typename T>
    std::string VectorToString(const std::vector<T>& vec) {
        std::string result;
        if (!vec.empty()) {
            result = std::format("{}", vec[0]);
            for (auto it = std::next(vec.begin()); it != vec.end(); ++it) {
                std::format_to(std::back_inserter(result), ", {}", *it);
            }
        }
        return std::format("{{{}}}", result);
    }

    // Overload for char to convert to string
    template<>
    std::string VectorToString(const std::vector<plg::string>& vec) {
        std::string result;
        if (!vec.empty()) {
            result = std::format("'{}'", vec[0]);
            for (auto it = std::next(vec.begin()); it != vec.end(); ++it) {
                std::format_to(std::back_inserter(result), ", '{}'", *it);
            }
        }
        return std::format("{{{}}}", result);
    }

    // Overload for char16_t to convert to string
    template<>
    std::string VectorToString(const std::vector<char16_t>& vec) {
        std::string result;
        if (!vec.empty()) {
            result = std::format("'{}'", static_cast<uint16_t>(vec[0]));
            for (auto it = std::next(vec.begin()); it != vec.end(); ++it) {
                std::format_to(std::back_inserter(result), ", '{}'", static_cast<uint16_t>(*it));
            }
        }
        return std::format("{{{}}}", result);
    }

    template<typename T>
    std::string PodToString(const T& t) {
        static_assert("Unknown");
    }

    template<>
    std::string PodToString(const plg::vec2& t) {
        return std::format("{{{}, {}}}", t.x, t.y);
    }

    template<>
    std::string PodToString(const plg::vec3& t) {
        return std::format("{{{}, {}, {}}}", t.x, t.y, t.z);
    }

    template<>
    std::string PodToString(const plg::vec4& t) {
        return std::format("{{{}, {}, {}, {}}}", t.x, t.y, t.z, t.w);
    }

    template<>
    std::string PodToString(const plg::mat4x4& t) {
        return std::format(
                "{{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}",
                t.m[0][0], t.m[0][1], t.m[0][2], t.m[0][3],
                t.m[1][0], t.m[1][1], t.m[1][2], t.m[1][3],
                t.m[2][0], t.m[2][1], t.m[2][2], t.m[2][3],
                t.m[3][0], t.m[3][1], t.m[3][2], t.m[3][3]
        );
    }
}

// 1 parameter
extern "C"
PLUGIN_API void CallFunc17(plg::string* output, cross_call_master::Func17 func) {
    int32_t i32 = 42; // Changed from 20 to 42
    func(i32);
    std::construct_at(output, std::format("{}", i32));
}

// 2 parameters
extern "C"
PLUGIN_API void CallFunc18(plg::string* output, cross_call_master::Func18 func) {
    int8_t i8 = 9; // Changed from 5 to 9
    int16_t i16 = 25; // Changed from 10 to 25
    plg::vec2 ret = func(i8, i16);
    std::construct_at(output, std::format("{}|{}|{}", PodToString(ret), i8, i16));
}

// 3 parameters
extern "C"
PLUGIN_API void CallFunc19(plg::string* output, cross_call_master::Func19 func) {
    uint32_t u32 = 75; // Changed from 10 to 75
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values in vec3
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed vector values
    func(u32, vec3, vecU32);
    std::construct_at(output, std::format("{}|{}|{}", u32, PodToString(vec3), VectorToString(vecU32)));
}

// 4 parameters
extern "C"
PLUGIN_API void CallFunc20(plg::string* output, cross_call_master::Func20 func) {
    char16_t ch16 = 'Z'; // Changed from 'A' to 'Z'
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    std::vector<uint64_t> vecU64{4, 5, 6}; // Changed vector values
    char ch = 'X'; // Changed from 'B' to 'X'
    int32_t ret = func(ch16, vec4, vecU64, ch);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}", ret, static_cast<uint16_t>(ch16), PodToString(vec4), VectorToString(vecU64), ch));
}

// 5 parameters
extern "C"
PLUGIN_API void CallFunc21(plg::string* output, cross_call_master::Func21 func) {
    plg::mat4x4 mat; // Assume it's initialized properly
    std::vector<int32_t> vecI32{4, 5, 6}; // Changed vector values
    plg::vec2 vec2{3.0f, 4.0f}; // Changed vec2 values
    bool b = false; // Changed from true to false
    double d = 6.28; // Changed from 3.14 to 6.28
    float ret = func(mat, vecI32, vec2, b, d);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}", ret, PodToString(mat), VectorToString(vecI32), PodToString(vec2), b ? "true" : "false", d));
}

// 6 parameters
extern "C"
PLUGIN_API void CallFunc22(plg::string* output, cross_call_master::Func22 func) {
    void* ptr = reinterpret_cast<void *>(1); // Changed from 0 to 1
    uint32_t u32 = 20; // Changed from 10 to 20
    std::vector<double> vecD{4.0, 5.0, 6.0}; // Changed vector values
    int16_t i16 = 15; // Changed from 10 to 15
    plg::string str = "Updated Test"; // Changed string
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    uint64_t ret = func(ptr, u32, vecD, i16, str, vec4);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}", ret, ptr, u32, VectorToString(vecD), i16, str.c_str(), PodToString(vec4)));
}

// 7 parameters
extern "C"
PLUGIN_API void CallFunc23(plg::string* output, cross_call_master::Func23 func) {
    uint64_t u64 = 200; // Changed from 100 to 200
    plg::vec2 vec2{3.0f, 4.0f}; // Changed vec2 values
    std::vector<int16_t> vecI16{4, 5, 6}; // Changed vector values
    char16_t ch16 = 'Y'; // Changed from 'A' to 'Y'
    float f = 2.34f; // Changed from 1.23f to 2.34f
    int8_t i8 = 10; // Changed from 5 to 10
    std::vector<uint8_t> vecU8{3, 4, 5}; // Changed vector values
    func(u64, vec2, vecI16, ch16, f, i8, vecU8);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}", u64, PodToString(vec2), VectorToString(vecI16), static_cast<uint16_t>(ch16), f, i8, VectorToString(vecU8)));
}

// 8 parameters
extern "C"
PLUGIN_API void CallFunc24(plg::string* output, cross_call_master::Func24 func) {
    std::vector<char> vecC{'D', 'E', 'F'}; // Changed from {'A', 'B', 'C'} to {'D', 'E', 'F'}
    int64_t i64 = 100; // Changed from 50 to 100
    std::vector<uint8_t> vecU8{3, 4, 5}; // Changed vector values
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    uint64_t u64 = 200; // Changed from 100 to 200
    std::vector<void*> vecPtr{reinterpret_cast<void*>(3), reinterpret_cast<void*>(4), reinterpret_cast<void*>(5)}; // Changed vector values
    double d = 6.28; // Changed from 3.14 to 6.28
    std::vector<void*> vecV2{ reinterpret_cast<void*>(4), reinterpret_cast<void*>(5), reinterpret_cast<void*>(6), reinterpret_cast<void*>(7) }; // Changed vector values
    plg::mat4x4 ret = func(vecC, i64, vecU8, vec4, u64, vecPtr, d, vecV2);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}", PodToString(ret), VectorToString(vecC), i64, VectorToString(vecU8), PodToString(vec4), u64, VectorToString(vecPtr), d, VectorToString(vecV2)));
}

// 9 parameters
extern "C"
PLUGIN_API void CallFunc25(plg::string* output, cross_call_master::Func25 func) {
    int32_t i32 = 50; // Changed from 20 to 50
    std::vector<void*> vecPtr{reinterpret_cast<void*>(3), reinterpret_cast<void*>(4), reinterpret_cast<void*>(5)}; // Changed vector values
    bool b = false; // Changed from true to false
    uint8_t u8 = 10; // Changed from 5 to 10
    plg::string str = "Updated Test String"; // Changed string
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed vec3 values
    int64_t i64 = 100; // Changed from 50 to 100
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    uint16_t u16 = 20; // Changed from 10 to 20
    double ret = func(i32, vecPtr, b, u8, str, vec3, i64, vec4, u16);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, i32, VectorToString(vecPtr), b ? "true" : "false", u8, str.c_str(), PodToString(vec3), i64, PodToString(vec4), u16));
}

// 10 parameters
extern "C"
PLUGIN_API void CallFunc26(plg::string* output, cross_call_master::Func26 func) {
    char16_t ch16 = 'B'; // Changed from 'A' to 'B'
    plg::vec2 vec2{3.0f, 4.0f}; // Changed vec2 values
    plg::mat4x4 mat; // Assume it's initialized properly
    std::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed vector values
    int16_t i16 = 20; // Changed from 10 to 20
    uint64_t u64 = 200; // Changed from 100 to 200
    uint32_t u32 = 20; // Changed from 10 to 20
    std::vector<uint16_t> vecU16{3, 4, 5};
    void* ptr = reinterpret_cast<void*>(0xDEADBEAFDEADBEAF); // Example pointer
    bool b = false;
    char ret = func(ch16, vec2, mat, vecF, i16, u64, u32, vecU16, ptr, b);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, static_cast<uint16_t>(ch16), PodToString(vec2), PodToString(mat), VectorToString(vecF), u64, u32, VectorToString(vecU16), ptr, b ? "true" : "false"));
}
// 11 parameters
extern "C"
PLUGIN_API void CallFunc27(plg::string* output, cross_call_master::Func27 func) {
    float f = 2.56f; // Changed from 1.23f
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    void* ptr = nullptr; // Example pointer
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    std::vector<int16_t> vecI16{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume it's initialized properly
    bool b = false; // Changed from true to false
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed values
    int8_t i8 = 10; // Changed from 5 to 10
    int32_t i32 = 40; // Changed from 20 to 40
    std::vector<uint8_t> vecU8{3, 4, 5}; // Changed values
    uint8_t ret = func(f, vec3, ptr, vec2, vecI16, mat, b, vec4, i8, i32, vecU8);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, f, PodToString(vec3), ptr, PodToString(vec2), VectorToString(vecI16), PodToString(mat), b, PodToString(vec4), i8, i32, VectorToString(vecU8)));
}

// 12 parameters
extern "C"
PLUGIN_API void CallFunc28(plg::string* output, cross_call_master::Func28 func) {
    void* ptr = reinterpret_cast<void *>(1); // Changed from 0
    uint16_t u16 = 20; // Changed from 10
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    float f = 2.71f; // Changed from 3.14f
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed values
    plg::string str = "New example string"; // Changed string
    std::vector<uint64_t> vecU64{400, 500, 600}; // Changed values
    int64_t i64 = 987654321; // Changed from 123456789
    bool b = false; // Changed from true
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    std::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed values

    plg::string ret = func(ptr, u16, vecU32, mat, f, vec4, str, vecU64, i64, b, vec3, vecF);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ptr, u16, VectorToString(vecU32), PodToString(mat), f, PodToString(vec4), str, VectorToString(vecU64), i64, b, PodToString(vec3), VectorToString(vecF)));
}

// 13 parameters
extern "C"
PLUGIN_API void CallFunc29(plg::string* output, cross_call_master::Func29 func) {
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    int32_t i32 = 99; // Changed from 42
    std::vector<int8_t> vecI8{4, 5, 6}; // Changed values
    double d = 2.71; // Changed from 3.14
    bool b = false; // Changed from true
    int8_t i8 = 10; // Changed from 5
    std::vector<uint16_t> vecU16{4, 5, 6}; // Changed values
    float f = 3.21f; // Changed from 1.23f
    plg::string str = "Yet another example string"; // Changed string
    plg::mat4x4 mat; // Assume initialized properly
    uint64_t u64 = 200; // Changed from 100
    plg::vec3 vec3{5.0f, 6.0f, 7.0f}; // Changed values
    std::vector<int64_t> vecI64{2000, 3000, 4000}; // Changed values

    std::vector<plg::string> ret = func(vec4, i32, vecI8, d, b, i8, vecU16, f, str, mat, u64, vec3, vecI64);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", VectorToString(ret), PodToString(vec4), i32, VectorToString(vecI8), d, b ? "true" : "false", i8, VectorToString(vecU16), f, str, PodToString(mat), u64, PodToString(vec3), VectorToString(vecI64)));
}

// 14 parameters
extern "C"
PLUGIN_API void CallFunc30(plg::string* output, cross_call_master::Func30 func) {
    void* ptr = reinterpret_cast<void *>(1); // Changed from 0
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    int64_t i64 = 987654321; // Changed from 123456789
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed values
    bool b = false; // Changed from true
    plg::string str = "Updated String for Func30"; // Changed string
    plg::vec3 vec3{5.0f, 6.0f, 7.0f}; // Changed values
    std::vector<uint8_t> vecU8{1, 2, 3}; // Changed values
    float f = 5.67f; // Changed from 4.56f
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    int8_t i8 = 10; // Changed from 5
    std::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed values
    double d = 8.90; // Changed from 7.89

    int32_t ret = func(ptr, vec4, i64, vecU32, b, str, vec3, vecU8, f, vec2, mat, i8, vecF, d);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ptr, PodToString(vec4), i64, VectorToString(vecU32), b ? "true" : "false", str, PodToString(vec3), VectorToString(vecU8), f, PodToString(vec2), PodToString(mat), i8, VectorToString(vecF), d));
}

// 15 parameters
extern "C"
PLUGIN_API void CallFunc31(plg::string* output, cross_call_master::Func31 func) {
    char ch = 'B'; // Changed from 'A'
    uint32_t u32 = 200; // Changed from 100
    std::vector<uint64_t> vecU64{4, 5, 6}; // Changed values
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    plg::string str = "Updated String for Func31"; // Changed string
    bool b = true; // Changed from false
    int64_t i64 = 987654321; // Changed from 123456789
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    int8_t i8 = 10; // Changed from 5
    uint16_t u16 = 20; // Changed from 10
    std::vector<int16_t> vecI16{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    float f = 5.67f; // Changed from 4.56f
    std::vector<double> vecD{4.0, 5.0, 6.0}; // Changed values

    plg::vec3 ret = func(ch, u32, vecU64, vec4, str, b, i64, vec2, i8, u16, vecI16, mat, vec3, f, vecD);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ch, u32, VectorToString(vecU64), PodToString(vec4), str, b ? "true" : "false", i64, PodToString(vec2), i8, u16, VectorToString(vecI16), PodToString(mat), PodToString(vec3), f, VectorToString(vecD)));
}

// 16 parameters
extern "C"
PLUGIN_API void CallFunc32(plg::string* output, cross_call_master::Func32 func) {
    int32_t i32 = 30; // Changed from 20
    uint16_t u16 = 20; // Changed from 10
    std::vector<int8_t> vecI8{4, 5, 6}; // Changed values
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    void* ptr = reinterpret_cast<void *>(1); // Changed from 0
    std::vector<uint32_t> vecU32{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    uint64_t u64 = 200; // Changed from 100
    plg::string str = "Updated String for Func32"; // Changed string
    int64_t i64 = 987654321; // Changed from 123456789
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    std::vector<int8_t> vecI8_2{7, 8, 9}; // Another sample vector of int8
    bool b = false; // Changed from true
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    uint8_t u8 = 128; // Changed from 255
    std::vector<char16_t> vecC16{u'D', u'E', u'F'}; // Changed values

    func(i32, u16, vecI8, vec4, ptr, vecU32, mat, u64, str, i64, vec2, vecI8_2, b, vec3, u8, vecC16);
    std::construct_at(output, std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", i32, u16, VectorToString(vecI8), PodToString(vec4), ptr, VectorToString(vecU32), PodToString(mat), u64, str, i64, PodToString(vec2), VectorToString(vecI8_2), b ? "true" : "false", PodToString(vec3), u8, VectorToString(vecC16)));
}

// Mock Functions for the typedefs

void MockVoid() { /*std::cout << "Void function called\n";*/ }
bool MockBool() { return true; }
char MockChar8() { return 'A'; }
char16_t MockChar16() { return u'Z'; }
int8_t MockInt8() { return 10; }
int16_t MockInt16() { return 100; }
int32_t MockInt32() { return 1000; }
int64_t MockInt64() { return 10000; }
uint8_t MockUInt8() { return 20; }
uint16_t MockUInt16() { return 200; }
uint32_t MockUInt32() { return 2000; }
uint64_t MockUInt64() { return 20000; }
void* MockPtr() { return nullptr; }
float MockFloat() { return 3.14f; }
double MockDouble() { return 6.28; }
void* MockFunction() { return nullptr; }
plg::string MockString() { return "Test string"; }

std::vector<bool> MockBoolVector() { return {true, false}; }
std::vector<char> MockChar8Vector() { return {'A', 'B'}; }
std::vector<char16_t> MockChar16Vector() { return {u'A', u'B'}; }
std::vector<int8_t> MockInt8Vector() { return {10, 20}; }
std::vector<int16_t> MockInt16Vector() { return {100, 200}; }
std::vector<int32_t> MockInt32Vector() { return {1000, 2000}; }
std::vector<int64_t> MockInt64Vector() { return {10000, 20000}; }
std::vector<uint8_t> MockUInt8Vector() { return {20, 30}; }
std::vector<uint16_t> MockUInt16Vector() { return {200, 300}; }
std::vector<uint32_t> MockUInt32Vector() { return {2000, 3000}; }
std::vector<uint64_t> MockUInt64Vector() { return {20000, 30000}; }
std::vector<void*> MockPtrVector() { return {nullptr, reinterpret_cast<void *>(1) }; }
std::vector<float> MockFloatVector() { return {1.1f, 2.2f}; }
std::vector<double> MockDoubleVector() { return {3.3, 4.4}; }
std::vector<plg::string> MockStringVector() { return {"Hello", "World"}; }

plg::vec2 MockVec2() { return {1.0f, 2.0f}; }
plg::vec3 MockVec3() { return {1.0f, 2.0f, 3.0f}; }
plg::vec4 MockVec4() { return {1.0f, 2.0f, 3.0f, 4.0f}; }
plg::mat4x4 MockMat4x4() { return {{{1.0f}}}; }

// Mock implementations for 1 parameter functions
int32_t MockFunc1(const plg::vec3& v) {
    const auto buffer = std::format("{}{}{}", v.x, v.y, v.z);
	return static_cast<int32_t>(v.x + v.y + v.z);
}

// Mock implementations for 2 parameter functions
char MockFunc2(float a, int64_t b) {
    const auto buffer = std::format("{}{}", a, b);
	return static_cast<char>(a + b);
}

// Mock implementations for 3 parameter functions
void MockFunc3(void* p, const plg::vec4& v, const plg::string& s) {
    const auto buffer = std::format("{}{}", p, v.x, v.y, v.z, v.w, s);
}

// Mock implementations for 4 parameter functions
plg::vec4 MockFunc4(bool flag, int32_t u, char16_t c, const plg::mat4x4& m) {
    const auto buffer = std::format("{}{}{}{}", flag, u, static_cast<uint16_t>(c), m.m[3][3]);
	return {1.0f, 2.0f, 3.0f, 4.0f};  // Returning a dummy const plg::vec4
}

// Mock implementations for 5 parameter functions
bool MockFunc5(int8_t i, const plg::vec2& v, void* p, double d, const std::vector<uint64_t>& vec) {
    const auto buffer = std::format("{}{}{}{}{}{}", i, v.x, v.y, p, d, vec.size());
	return true; // Returning dummy bool
}

// Mock implementations for 6 parameter functions
int64_t MockFunc6(const plg::string& s, float f, const std::vector<float>& vec, int16_t i, const std::vector<uint8_t>& uVec, void* p) {
    const auto buffer = std::format("{}{}{}{}{}{}", s, f, vec.size(), i, uVec.size(), p);
	return static_cast<int64_t>(f + i);  // Returning a dummy int64_t
}

// Mock implementations for 7 parameter functions
double MockFunc7(const std::vector<char>& vec, uint16_t u, char16_t c, const std::vector<uint32_t>& uVec, const plg::vec4& v, bool flag, uint64_t l) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", vec.size(), u, static_cast<uint16_t>(c), uVec.size(), v.x, v.y, v.z, v.w, flag, l);
	return 3.14;  // Returning dummy double
}

// Mock implementations for 8 parameter functions
plg::mat4x4 MockFunc8(const plg::vec3& v, const std::vector<uint32_t>& uVec, int16_t i, bool flag, const plg::vec4& v4, const std::vector<char16_t>& cVec, char16_t c, int32_t a) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", v.x, v.y, v.z, uVec.size(), i, flag, v4.w, cVec.size(), static_cast<uint16_t>(c), a);
    return {}; // Returning a dummy const plg::mat4x4
}

// Mock implementations for 9 parameter functions
void MockFunc9(float f, const plg::vec2& v, const std::vector<int8_t>& iVec, uint64_t l, bool flag, const plg::string& s, const plg::vec4& v4, int16_t i, void* p) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", f, v.x, v.y, iVec.size(), l, flag, s, v4.w, i, p);
}

// Mock implementations for 10 parameter functions
uint32_t MockFunc10(const plg::vec4& v4, const plg::mat4x4& m, const std::vector<uint32_t>& uVec, uint64_t l, const std::vector<char>& cVec, int32_t a, bool flag, const plg::vec2& v, int64_t i, double d) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{}{}", v4.x, v4.y, v4.z, v4.w, m.m[3][3], uVec.size(), l, cVec.size(), a, flag, v.x, v.y, i, d);
	return 42; // Returning dummy uint32_t
}

// Mock implementations for 11 parameter functions
void* MockFunc11(const std::vector<bool>& bVec, char16_t c, uint8_t u, double d, const plg::vec3& v3, const std::vector<int8_t>& iVec, int64_t i, uint16_t u16, float f, const plg::vec2& v, uint32_t u32) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", bVec.size(), static_cast<uint16_t>(c), u, d, v3.x, iVec.size(), i, u16, f, v.x, u32);
	return 0; // Returning dummy void*
}

// Mock implementations for 12 parameter functions
bool MockFunc12(void* p, const std::vector<double>& dVec, uint32_t u, double d, bool flag, int32_t a, int8_t i, uint64_t l, float f, const std::vector<void*>& pVec, int64_t i64, char c) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}", p, dVec.size(), u, d, flag, a, i, l, f, pVec.size(), i64, c);
	return false; // Returning dummy bool
}

// Mock implementations for 13 parameter functions
plg::string MockFunc13(int64_t i64, const std::vector<char>& cVec, uint16_t u16, float f, const std::vector<bool>& bVec, const plg::vec4& v4, const plg::string& s, int32_t a, const plg::vec3& v3, void* p, const plg::vec2& v2, const std::vector<uint8_t>& u8Vec, int16_t i16) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", i64, cVec.size(), u16, f, bVec.size(), v4.z, s, a, v3.x, p, v2.x, u8Vec.size(), i16);
	return "Dummy String"; // Returning dummy string
}

// Mock implementations for 14 parameter functions
std::vector<plg::string> MockFunc14(const std::vector<char>& cVec, const std::vector<uint32_t>& uVec, const plg::mat4x4& m, bool flag, char16_t c, int32_t a, const std::vector<float>& fVec, uint16_t u16, const std::vector<uint8_t>& u8Vec, int8_t i8, const plg::vec3& v3, const plg::vec4& v4, double d, void* p) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}", cVec.size(), uVec.size(), m.m[3][3], flag, static_cast<uint16_t>(c), a, fVec.size(), u16, u8Vec.size(), i8, v3.x, v4.x, d, p);
	return {"String1", "String2"}; // Returning dummy vector of strings
}

// Mock implementations for 15 parameter functions
int16_t MockFunc15(const std::vector<int16_t>& iVec, const plg::mat4x4& m, const plg::vec4& v4, void* p, uint64_t l, const std::vector<uint32_t>& uVec, bool flag, float f, const std::vector<char16_t>& cVec, uint8_t u, int32_t a, const plg::vec2& v2, uint16_t u16, double d, const std::vector<uint8_t>& u8Vec) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", iVec.size(), m.m[3][3], v4.x, p, l, uVec.size(), flag, f, cVec.size(), u, a, v2.x, u16, d, u8Vec.size());
	return 257; // Returning dummy int16_t
}

// Mock implementations for 16 parameter functions
void* MockFunc16(const std::vector<bool>& bVec, int16_t i16, const std::vector<int8_t>& iVec, const plg::vec4& v4, const plg::mat4x4& m, const plg::vec2& v2, const std::vector<uint64_t>& uVec, const std::vector<char>& cVec, const plg::string& s, int64_t i64, const std::vector<uint32_t>& u32Vec, const plg::vec3& v3, float f, double d, int8_t i8, uint16_t u16) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}", i16, bVec.size(), iVec.size(), v4.x,  v4.y,  v4.z, v4.w, m.m[3][3], v2.x, uVec.size(), cVec.size(), s, i64, u32Vec.size(), v3.x, f, d, i8, u16);
	return 0; // Returning dummy void*
}

// Mock implementations for 17 parameter functions
void MockFunc17(int32_t& ref) {
	ref += 10;  // Modifying the reference
}

// Mock implementations for 18 parameter functions
plg::vec2 MockFunc18(int8_t& i8, int16_t& i16) {
	i8 = 5;     // Setting a value for int8_t reference
	i16 = 10;   // Setting a value for int16_t reference
	return {static_cast<float>(i8), static_cast<float>(i16)};  // Returning dummy plg::vec2
}

// Mock implementations for 19 parameter functions
void MockFunc19(uint32_t& u32, plg::vec3& v3, std::vector<uint32_t>& uVec) {
	u32 = 42;      // Setting a value for uint32_t reference
	v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
	uVec = {1, 2, 3}; // Setting values for std::vector<uint32_t>
}

// Mock implementations for 20 parameter functions
int32_t MockFunc20(char16_t& c, plg::vec4& v4, std::vector<uint64_t>& uVec, char& ch) {
	c = u't'; // Setting a value for char16_t reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
	uVec = {100, 200}; // Setting values for std::vector<uint64_t>
	ch = 'F';
	return 0; // Returning dummy int32_t
}

// Mock implementations for 21 parameter functions
float MockFunc21(plg::mat4x4& m, std::vector<int32_t>& iVec, plg::vec2& v2, bool& flag, double& d) {
	flag = true; // Setting a value for bool reference
	d = 3.14;    // Setting a value for double reference
	v2 = {1.0f, 2.0f}; // Setting a value for plg::vec2 reference
    m = {
            {
                    {1.3f, 0.6f, 0.8f, 0.5f},  // Row 0
                    {0.7f, 1.1f, 0.2f, 0.4f},  // Row 1
                    {0.9f, 0.3f, 1.2f, 0.7f},  // Row 2
                    {0.2f, 0.8f, 0.5f, 1.0f}   // Row 3
            }
    };// Setting a value for plg::mat4x4 reference
	iVec = {1, 2, 3}; // Setting values for std::vector<int32_t>
	return 0.0f; // Returning dummy float
}

// Mock implementations for 22 parameter functions
uint64_t MockFunc22(void*& p, uint32_t& u32, std::vector<double>& dVec, int16_t& i16, plg::string& s, plg::vec4& v4) {
	//std::cout << "MockFunc22 called with uint32_t: " << u32 << ", int16_t: " << i16 << "\n";
	p = nullptr; // Setting a value for void* reference
	u32 = 99;    // Setting a value for uint32_t reference
	i16 = 123;   // Setting a value for int16_t reference
	s = "Hello"; // Setting a value for string reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
	dVec = {1.1, 2.2, 3.3}; // Setting values for std::vector<double>
	return 0; // Returning dummy uint64_t
}

// Mock implementations for 23 parameter functions
void MockFunc23(uint64_t& u64, plg::vec2& v2, std::vector<int16_t>& iVec, char16_t& c, float& f, int8_t& i8, std::vector<uint8_t>& u8Vec) {
	//std::cout << "MockFunc23 called with float: " << f << ", int8_t: " << static_cast<int>(i8) << "\n";
	u64 = 50; // Setting a value for uint64_t reference
	f = 1.5f; // Setting a value for float reference
	i8 = -1;  // Setting a value for int8_t reference
	v2 = {3.0f, 4.0f}; // Setting a value for plg::vec2 reference
	u8Vec = {1, 2, 3}; // Setting values for std::vector<uint8_t>
	c = L'Ⅴ';
	iVec = {1, 2, 3, 4};
}

// Mock implementations for 24 parameter functions
plg::mat4x4 MockFunc24(std::vector<char>& cVec, int64_t& i64, std::vector<uint8_t>& u8Vec, plg::vec4& v4, uint64_t& u64, std::vector<void*>& pVec, double& d, std::vector<void*>& vVec) {
	//std::cout << "MockFunc24 called with int64_t: " << i64 << ", double: " << d << "\n";
	i64 = 64;  // Setting a value for int64_t reference
	d = 2.71;  // Setting a value for double reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
	cVec = {'a', 'b', 'c'}; // Setting values for std::vector<char>
	u8Vec = {5, 6, 7}; // Setting values for std::vector<uint8_t>
	pVec = {nullptr}; // Setting values for std::vector<void*>
	vVec = {reinterpret_cast<void *>(1), reinterpret_cast<void *>(1), reinterpret_cast<void *>(2), reinterpret_cast<void *>(2)}; // Setting values for std::vector<void*>
	u64 = 0xffffffff;
	return {}; // Returning dummy plg::mat4x4
}

// Mock implementations for 25 parameter functions
double MockFunc25(int32_t& i32, std::vector<void*>& pVec, bool& flag, uint8_t& u8, plg::string& s, plg::vec3& v3, int64_t& i64, plg::vec4& v4, uint16_t& u16) {
	//std::cout << "MockFunc25 called with bool: " << flag << ", int32_t: " << i32 << "\n";
	flag = false; // Setting a value for bool reference
	i32 = 100;    // Setting a value for int32_t reference
	u8 = 250;     // Setting a value for uint8_t reference
	v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
	v4 = {4.0f, 5.0f, 6.0f, 7.0f}; // Setting a value for plg::vec4 reference
	s = "MockFunc25"; // Setting a value for string reference
	pVec = {nullptr}; // Setting values for std::vector<void*>
	i64 = 1337;
    u16 = 64222;
	return 0.0;   // Returning dummy double
}

// Mock implementations for 26 parameter functions
char MockFunc26(char16_t& c, plg::vec2& v2, plg::mat4x4& m, std::vector<float>& fVec, int16_t& i16, uint64_t& u64, uint32_t& u32, std::vector<uint16_t>& u16Vec, void*& p, bool& flag) {
	//std::cout << "MockFunc26 called with char16: " << c << ", bool: " << flag << "\n";
	c = u'Z'; // Setting a value for char16_t reference
	flag = true; // Setting a value for bool reference
	v2 = {2.0f, 3.0f}; // Setting a value for plg::vec2 reference
    m = {
            {
                    {0.9f, 0.2f, 0.4f, 0.8f},  // Row 0
                    {0.1f, 1.0f, 0.6f, 0.3f},  // Row 1
                    {0.7f, 0.5f, 0.2f, 0.9f},  // Row 2
                    {0.3f, 0.4f, 1.5f, 0.1f}   // Row 3
            }
    }; // Setting a value for plg::mat4x4 reference
	fVec = {1.1f, 2.2f}; // Setting values for std::vector<float>
	u64 = 64; // Setting a value for uint64_t reference
	u32 = 32; // Setting a value for uint32_t reference
	u16Vec = {100, 200}; // Setting values for std::vector<uint16_t>
	i16 = 332;
	p = reinterpret_cast<void *>(0xDEADBEAFDEADBEAF);
	return 'A'; // Returning dummy char
}

// Mock implementations for 27 parameter functions
uint8_t MockFunc27(float& f, plg::vec3& v3, void*& p, plg::vec2& v2, std::vector<int16_t>& i16Vec, plg::mat4x4& m, bool& flag, plg::vec4& v4, int8_t& i8, int32_t& i32, std::vector<uint8_t>& u8Vec) {
	//std::cout << "MockFunc27 called with uint8_t: " << static_cast<int>(u8) << ", bool: " << flag << "\n";
    f = 1.0;
    v3 = {-1.0f, -2.0f, -3.0f};
    p = reinterpret_cast<void *>(0xDEADBEAFDEADBEAF);
    v2 = {-111.0f, 111.0f};
    i16Vec = { 1, 2, 3, 4 };
    m = {
            {
                    {1.0f, 0.5f, 0.3f, 0.7f},  // Row 0
                    {0.8f, 1.2f, 0.6f, 0.9f},  // Row 1
                    {1.5f, 1.1f, 0.4f, 0.2f},  // Row 2
                    {0.3f, 0.9f, 0.7f, 1.0f}   // Row 3
            }
    };
    flag = true;
    v4 = {1.0f, 2.0f, 3.0f, 4.0f};
    i8 = 111;
    i32 = 30;
    u8Vec = { 0, 0, 0, 0, 0, 0, 1, 0 };
	return 0; // Returning dummy int
}

// Mock implementations for 28 parameter functions
plg::string MockFunc28(void*& ptr, uint16_t& u16, std::vector<uint32_t>& u32Vec, plg::mat4x4& m, float& f, plg::vec4& v4, plg::string& str, std::vector<uint64_t>& u64Vec, int64_t& i64, bool& b, plg::vec3& vec3, std::vector<float>& fVec) {
	//std::cout << "MockFunc28 called with float: " << f << "\n";
    ptr = nullptr;
    u16 = 65500;
    u32Vec = { 1, 2, 3, 4, 5, 7 };
    m = {
            {
                    {1.4f, 0.7f, 0.2f, 0.5f},  // Row 0
                    {0.3f, 1.1f, 0.6f, 0.8f},  // Row 1
                    {0.9f, 0.4f, 1.3f, 0.1f},  // Row 2
                    {0.6f, 0.2f, 0.7f, 1.0f}   // Row 3
            }
    };
    f = 5.5f; // Setting a value for float reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    u64Vec = {1, 2}; // Setting values for std::vector<int16_t>
    i64 = 834748377834;
    b = true,
	vec3 = {10, 20, 30}; // Setting values for std::vector<uint32_t>
	str = "MockFunc28"; // Setting a value for string reference
    fVec = {1.0f, -1000.0f, 2000.0f };
	return str; // Returning dummy string
}

// Mock implementations for 29 parameter functions
std::vector<plg::string> MockFunc29(plg::vec4& v4, int32_t& i32, std::vector<int8_t>& iVec, double& d, bool& flag, int8_t& i8, std::vector<uint16_t>& u16Vec, float& f, plg::string& s, plg::mat4x4& m, uint64_t& u64, plg::vec3& v3, std::vector<int64_t>& i64Vec) {
	//std::cout << "MockFunc29 called with int32_t: " << i32 << ", bool: " << flag << "\n";
	i32 = 30; // Setting a value for int32_t reference
	flag = true; // Setting a value for bool reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
	d = 3.14; // Setting a value for double reference
	i8 = 8; // Setting a value for int8_t reference
	u16Vec = {100, 200}; // Setting values for std::vector<uint16_t>
	f = 1.5f; // Setting a value for float reference
	s = "MockFunc29"; // Setting a value for string reference
    m = {
            {
                    {0.4f, 1.0f, 0.6f, 0.3f},  // Row 0
                    {1.2f, 0.8f, 0.5f, 0.9f},  // Row 1
                    {0.7f, 0.3f, 1.4f, 0.6f},  // Row 2
                    {0.1f, 0.9f, 0.8f, 1.3f}   // Row 3
            }
    };
    // Setting a value for plg::mat4x4 reference
	u64 = 64; // Setting a value for uint64_t reference
	v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
	i64Vec = {1, 2, 3}; // Setting values for std::vector<int64_t>
	iVec = {127, 126, 125};
	return {"Example", "MockFunc29"}; // Returning dummy vector of strings
}

// Mock implementations for 30 parameter functions
int32_t MockFunc30(void*& p, plg::vec4& v4, int64_t& i64, std::vector<uint32_t>& uVec, bool& flag, plg::string& s, plg::vec3& v3, std::vector<uint8_t>& u8Vec, float& f, plg::vec2& v2, plg::mat4x4& m, int8_t& i8, std::vector<float>& vVec, double& d) {
	//std::cout << "MockFunc30 called with int64_t: " << i64 << ", bool: " << flag << "\n";
	flag = false; // Setting a value for bool reference
	f = 1.1f;    // Setting a value for float reference
	i64 = 1000;  // Setting a value for int64_t reference
	v2 = {3.0f, 4.0f}; // Setting a value for plg::vec2 reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
	s = "MockFunc30"; // Setting a value for string reference
	p = nullptr; // Setting a value for void* reference
	uVec = {100, 200}; // Setting values for std::vector<uint32_t>
    m = {
            {
                    {0.5f, 0.3f, 1.0f, 0.7f},  // Row 0
                    {1.1f, 0.9f, 0.6f, 0.4f},  // Row 1
                    {0.2f, 0.8f, 1.5f, 0.3f},  // Row 2
                    {0.7f, 0.4f, 0.9f, 1.0f}   // Row 3
            }
    }; // Setting a value for plg::mat4x4 reference
	i8 = 8; // Setting a value for int8_t reference
	vVec = {1.0f, 1.0f, 2.0f, 2.0f}; // Setting values for std::vector<float>
	d = 2.718; // Setting a value for double reference
	v3 = { 1, 2, 3 };
	u8Vec = { 255, 0, 255, 200, 100, 200 };
	return 42; // Returning dummy int32_t
}

// Mock implementations for 31 parameter functions
plg::vec3 MockFunc31(char& c, uint32_t& u32, std::vector<uint64_t>& uVec, plg::vec4& v4, plg::string& s, bool& flag, int64_t& i64, plg::vec2& v2, int8_t& i8, uint16_t& u16, std::vector<int16_t>& iVec, plg::mat4x4& m, plg::vec3& v3, float& f, std::vector<double>& v4Vec) {
	//std::cout << "MockFunc31 called with uint32_t: " << u32 << ", bool: " << flag << "\n";
	u32 = 12345; // Setting a value for uint32_t reference
	flag = true; // Setting a value for bool reference
	v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
	c = 'C'; // Setting a value for char reference
	v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
	s = "MockFunc31"; // Setting a value for string reference
	i64 = 123456789; // Setting a value for int64_t reference
	v2 = {5.0f, 6.0f}; // Setting a value for plg::vec2 reference
	i8 = 7; // Setting a value for int8_t reference
	u16 = 255; // Setting a value for uint16_t reference
	iVec = {1, 2}; // Setting values for std::vector<int16_t>
    m = {
            {
                    {0.8f, 0.5f, 1.2f, 0.3f},  // Row 0
                    {1.0f, 0.7f, 0.4f, 0.6f},  // Row 1
                    {0.9f, 0.2f, 0.5f, 1.4f},  // Row 2
                    {0.6f, 0.8f, 1.1f, 0.7f}   // Row 3
            }
    }; // Setting a value for plg::mat4x4 reference
	v4Vec = {1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0}; // Setting values for std::vector<double>
	uVec = { 1, 2, 3, 4, 5 };
	f = -1.0f;
	return {1.0f, 1.5f, 3.0f}; // Returning dummy plg::vec3
}

// Mock implementations for 32 parameter functions
double MockFunc32(int32_t& i32, uint16_t& u16, std::vector<int8_t>& iVec, plg::vec4& v4, void*& p, std::vector<uint32_t>& uVec, plg::mat4x4& m, uint64_t& u64, plg::string& s, int64_t& i64, plg::vec2& v2, std::vector<int8_t>& u8Vec, bool& flag, plg::vec3& v3, uint8_t& u8, std::vector<char16_t>& cVec) {
	//std::cout << "MockFunc32 called with int32_t: " << i32 << ", uint16_t: " << u16 << "\n";
	i32 = 42; // Setting a value for int32_t reference
	u16 = 255; // Setting a value for uint16_t reference
	flag = false; // Setting a value for bool reference
	v2 = {2.5f, 3.5f}; // Setting a value for plg::vec2 reference
    u8Vec = { 1, 2, 3, 4, 5, 9 };
	v4 = {4.0f, 5.0f, 6.0f, 7.0f}; // Setting a value for plg::vec4 reference
	s = "MockFunc32"; // Setting a value for string reference
	p = nullptr; // Setting a value for void* reference
    m = {
            {
                    {1.0f, 0.4f, 0.3f, 0.9f},  // Row 0
                    {0.7f, 1.2f, 0.5f, 0.8f},  // Row 1
                    {0.2f, 0.6f, 1.1f, 0.4f},  // Row 2
                    {0.9f, 0.3f, 0.8f, 1.5f}   // Row 3
            }
    }; // Setting a value for plg::mat4x4 reference
	u64 = 123456789; // Setting a value for uint64_t reference
	uVec = {100, 200}; // Setting values for std::vector<uint32_t>
	i64 = 1000; // Setting a value for int64_t reference
	v3 = {0.0f, 0.0f, 0.0f}; // Setting a value for plg::vec3 reference
	u8 = 8; // Setting a value for uint8_t reference
	cVec = {u'a', u'b', u'c'}; // Setting values for std::vector<char16_t>
	iVec = { 0, 1 };
	return 1.0; // Returning dummy double
}

extern "C"
PLUGIN_API void ReverseCall(const plg::string& test) {
    static std::unordered_map<plg::string, void(*)()> tests {
            {"NoParamReturnVoid", []() {
                cross_call_master::NoParamReturnVoidCallback();
            }},
            {"NoParamReturnBool", []() {
                const auto result = cross_call_master::NoParamReturnBoolCallback();
                cross_call_master::ReverseReturn(result == true ? "true" : (result == false ? "false" : "<wrong return>"));
            }},
            {"NoParamReturnChar8", []() {
                const auto result = cross_call_master::NoParamReturnChar8Callback();
                cross_call_master::ReverseReturn(std::format("{}", static_cast<uint8_t>(result)));
            }},
            {"NoParamReturnChar16", []() {
                const auto result = cross_call_master::NoParamReturnChar16Callback();
                cross_call_master::ReverseReturn(std::format("{}", static_cast<uint16_t>(result)));
            }},
            {"NoParamReturnInt8", []() {
                const auto result = cross_call_master::NoParamReturnInt8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnInt16", []() {
                const auto result = cross_call_master::NoParamReturnInt16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnInt32", []() {
                const auto result = cross_call_master::NoParamReturnInt32Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnInt64", []() {
                const auto result = cross_call_master::NoParamReturnInt64Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnUInt8", []() {
                const auto result = cross_call_master::NoParamReturnUInt8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnUInt16", []() {
                const auto result = cross_call_master::NoParamReturnUInt16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnUInt32", []() {
                const auto result = cross_call_master::NoParamReturnUInt32Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnUInt64", []() {
                const auto result = cross_call_master::NoParamReturnUInt64Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnPointer", []() {
                const auto result = cross_call_master::NoParamReturnPointerCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnFloat", []() {
                const auto result = cross_call_master::NoParamReturnFloatCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnDouble", []() {
                const auto result = cross_call_master::NoParamReturnDoubleCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"NoParamReturnFunction", []() {
                const auto result = cross_call_master::NoParamReturnFunctionCallback();
                cross_call_master::ReverseReturn(result ? std::format("{}", result()) : "<null function pointer>");
            }},
            {"NoParamReturnString", []() {
                const auto result = cross_call_master::NoParamReturnStringCallback();
                cross_call_master::ReverseReturn(result);
            }},
            {"NoParamReturnArrayBool", []() {
                const auto result = cross_call_master::NoParamReturnArrayBoolCallback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", static_cast<bool>(result[0]));
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", static_cast<bool>(*it));
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayChar8", []() {
                const auto result = cross_call_master::NoParamReturnArrayChar8Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", static_cast<uint8_t>(result[0]));
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", static_cast<uint8_t>(*it));
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayChar16", []() {
                const auto result = cross_call_master::NoParamReturnArrayChar16Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", static_cast<uint16_t>(result[0]));
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", static_cast<uint16_t>(*it));
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayInt8", []() {
                const auto result = cross_call_master::NoParamReturnArrayInt8Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayInt16", []() {
                const auto result = cross_call_master::NoParamReturnArrayInt16Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayInt32", []() {
                const auto result = cross_call_master::NoParamReturnArrayInt32Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayInt64", []() {
                const auto result = cross_call_master::NoParamReturnArrayInt64Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayUInt8", []() {
                const auto result = cross_call_master::NoParamReturnArrayUInt8Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayUInt16", []() {
                const auto result = cross_call_master::NoParamReturnArrayUInt16Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayUInt32", []() {
                const auto result = cross_call_master::NoParamReturnArrayUInt32Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayUInt64", []() {
                const auto result = cross_call_master::NoParamReturnArrayUInt64Callback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayPointer", []() {
                const auto result = cross_call_master::NoParamReturnArrayPointerCallback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayFloat", []() {
                const auto result = cross_call_master::NoParamReturnArrayFloatCallback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayDouble", []() {
                const auto result = cross_call_master::NoParamReturnArrayDoubleCallback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnArrayString", []() {
                const auto result = cross_call_master::NoParamReturnArrayStringCallback();
                plg::string result_formated;
                if (!result.empty()) {
                    result_formated = std::format("'{}'", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(result_formated), ", '{}'", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
            }},
            {"NoParamReturnVector2", []() {
                const auto result = cross_call_master::NoParamReturnVector2Callback();
                cross_call_master::ReverseReturn(std::format("{{{}, {}}}", result.x, result.y));
            }},
            {"NoParamReturnVector3", []() {
                const auto result = cross_call_master::NoParamReturnVector3Callback();
                cross_call_master::ReverseReturn(std::format("{{{}, {}, {}}}", result.x, result.y, result.z));
            }},
            {"NoParamReturnVector4", []() {
                const auto result = cross_call_master::NoParamReturnVector4Callback();
                cross_call_master::ReverseReturn(std::format("{{{}, {}, {}, {}}}", result.x, result.y, result.z, result.w));
            }},
            {"NoParamReturnMatrix4x4", []() {
                const auto result = cross_call_master::NoParamReturnMatrix4x4Callback();
                cross_call_master::ReverseReturn(std::format("{{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}",
                                                             result.m[0][0], result.m[0][1], result.m[0][2], result.m[0][3],
                                                             result.m[1][0], result.m[1][1], result.m[1][2], result.m[1][3],
                                                             result.m[2][0], result.m[2][1], result.m[2][2], result.m[2][3],
                                                             result.m[3][0], result.m[3][1], result.m[3][2], result.m[3][3]));
            }},
            {"Param1", []() {
                cross_call_master::Param1Callback(999);
            }},
            {"Param2", []() {
                cross_call_master::Param2Callback(888, 9.9f);
            }},
            {"Param3", []() {
                cross_call_master::Param3Callback(777, 8.8f, 9.8765);
            }},
            {"Param4", []() {
                cross_call_master::Param4Callback(666, 7.7f, 8.7659, {100.1f, 200.2f, 300.3f, 400.4f});
            }},
            {"Param5", []() {
                cross_call_master::Param5Callback(555, 6.6f, 7.6598, {-105.1f, -205.2f, -305.3f, -405.4f}, {});
            }},
            {"Param6", []() {
                cross_call_master::Param6Callback(444, 5.5f, 6.5987, {110.1f, 210.2f, 310.3f, 410.4f}, {90000, -100, 20000}, 'A');
            }},
            {"Param7", []() {
                cross_call_master::Param7Callback(333, 4.4f, 5.9876, {-115.1f, -215.2f, -315.3f, -415.4f}, {800000, 30000, -4000000}, 'B', "red gold");
            }},
            {"Param8", []() {
                cross_call_master::Param8Callback(222, 3.3f, 1.2345, {120.1f, 220.2f, 320.3f, 420.4f}, {7000000, 5000000, -600000000}, 'C', "blue ice", u'Z');
            }},
            {"Param9", []() {
                cross_call_master::Param9Callback(111, 2.2f, 5.1234, {-125.1f, -225.2f, -325.3f, -425.4f}, {60000000, -700000000, 80000000000}, 'D', "pink metal", u'Y', -100);
            }},
            {"Param10", []() {
                cross_call_master::Param10Callback(1234, 1.1f, 4.5123, {130.1f, 230.2f, 330.3f, 430.4f}, {500000000, 90000000000, 1000000000000}, 'E', "green wood", u'X', -200, reinterpret_cast<void*>(0xabebaLL));
            }},
            {"ParamRef1", []() {
                int32_t a{};
                cross_call_master::ParamRef1Callback(a);
                cross_call_master::ReverseReturn(std::format("{}", a));
            }},
            {"ParamRef2", []() {
                int32_t a{};
                float b{};
                cross_call_master::ParamRef2Callback(a, b);
                cross_call_master::ReverseReturn(std::format("{}|{}", a, b));
            }},
            {"ParamRef3", []() {
                int32_t a{};
                float b{};
                double c{};
                cross_call_master::ParamRef3Callback(a, b, c);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}", a, b, c));
            }},
            {"ParamRef4", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                cross_call_master::ParamRef4Callback(a, b, c, d);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}", a, b, c, d.x, d.y, d.z, d.w));
            }},
            {"ParamRef5", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                std::vector<int64_t> e{};
                cross_call_master::ParamRef5Callback(a, b, c, d, e);
                plg::string e_formated;
                if (!e.empty()) {
                    e_formated = std::format("{}", e[0]);
                    for (auto it = std::next(e.begin()); it != e.end(); ++it) {
                        std::format_to(std::back_inserter(e_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}", a, b, c, d.x, d.y, d.z, d.w, e_formated));
            }},
            {"ParamRef6", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                std::vector<int64_t> e{};
                char f{};
                cross_call_master::ParamRef6Callback(a, b, c, d, e, f);
                plg::string e_formated;
                if (!e.empty()) {
                    e_formated = std::format("{}", e[0]);
                    for (auto it = std::next(e.begin()); it != e.end(); ++it) {
                        std::format_to(std::back_inserter(e_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
                                                                 static_cast<uint8_t>(f)));
            }},
            {"ParamRef7", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                std::vector<int64_t> e{};
                char f{};
                plg::string g{};
                cross_call_master::ParamRef7Callback(a, b, c, d, e, f, g);
                plg::string e_formated;
                if (!e.empty()) {
                    e_formated = std::format("{}", e[0]);
                    for (auto it = std::next(e.begin()); it != e.end(); ++it) {
                        std::format_to(std::back_inserter(e_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
                                                                 static_cast<uint8_t>(f), g));
            }},
            {"ParamRef8", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                std::vector<int64_t> e{};
                char f{};
                plg::string g{};
                char16_t h{};
                cross_call_master::ParamRef8Callback(a, b, c, d, e, f, g, h);
                plg::string e_formated;
                if (!e.empty()) {
                    e_formated = std::format("{}", e[0]);
                    for (auto it = std::next(e.begin()); it != e.end(); ++it) {
                        std::format_to(std::back_inserter(e_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
                                                                 static_cast<uint8_t>(f), g, static_cast<uint16_t>(h)));
            }},
            {"ParamRef9", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                std::vector<int64_t> e{};
                char f{};
                plg::string g{};
                char16_t h{};
                int16_t k{};
                cross_call_master::ParamRef9Callback(a, b, c, d, e, f, g, h, k);
                plg::string e_formated;
                if (!e.empty()) {
                    e_formated = std::format("{}", e[0]);
                    for (auto it = std::next(e.begin()); it != e.end(); ++it) {
                        std::format_to(std::back_inserter(e_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
                                                                 static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k));
            }},
            {"ParamRef10", []() {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                std::vector<int64_t> e{};
                char f{};
                plg::string g{};
                char16_t h{};
                int16_t k{};
                void* l{};
                cross_call_master::ParamRef10Callback(a, b, c, d, e, f, g, h, k, l);
                plg::string e_formated;
                if (!e.empty()) {
                    e_formated = std::format("{}", e[0]);
                    for (auto it = std::next(e.begin()); it != e.end(); ++it) {
                        std::format_to(std::back_inserter(e_formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
                                                                 static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k, l));
            }},
            {"ParamRefArrays", []() {
                std::vector<bool> p1{true};
                std::vector<char> p2{'A'};
                std::vector<char16_t> p3{u'A'};
                std::vector<int8_t> p4{-1};
                std::vector<int16_t> p5{-1};
                std::vector<int32_t> p6{-1};
                std::vector<int64_t> p7{-1LL};
                std::vector<uint8_t> p8{0};
                std::vector<uint16_t> p9{0};
                std::vector<uint32_t> p10{0};
                std::vector<uint64_t> p11{0};
                std::vector<void*> p12{nullptr};
                std::vector<float> p13{1.0f};
                std::vector<double> p14{1.0};
                std::vector<plg::string> p15{"Hi"};
                cross_call_master::ParamRefVectorsCallback(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
                plg::string p1_formated;
                if (!p1.empty()) {
                    p1_formated = std::format("{}", static_cast<bool>(p1[0]));
                    for (auto it = std::next(p1.begin()); it != p1.end(); ++it) {
                        std::format_to(std::back_inserter(p1_formated), ", {}", static_cast<bool>(*it));
                    }
                }
                plg::string p2_formated;
                if (!p2.empty()) {
                    p2_formated = std::format("{}", static_cast<uint8_t>(p2[0]));
                    for (auto it = std::next(p2.begin()); it != p2.end(); ++it) {
                        std::format_to(std::back_inserter(p2_formated), ", {}", static_cast<uint8_t>(*it));
                    }
                }
                plg::string p3_formated;
                if (!p3.empty()) {
                    p3_formated = std::format("{}", static_cast<uint16_t>(p3[0]));
                    for (auto it = std::next(p3.begin()); it != p3.end(); ++it) {
                        std::format_to(std::back_inserter(p3_formated), ", {}", static_cast<uint16_t>(*it));
                    }
                }
                plg::string p4_formated;
                if (!p4.empty()) {
                    p4_formated = std::format("{}", p4[0]);
                    for (auto it = std::next(p4.begin()); it != p4.end(); ++it) {
                        std::format_to(std::back_inserter(p4_formated), ", {}", *it);
                    }
                }
                plg::string p5_formated;
                if (!p5.empty()) {
                    p5_formated = std::format("{}", p5[0]);
                    for (auto it = std::next(p5.begin()); it != p5.end(); ++it) {
                        std::format_to(std::back_inserter(p5_formated), ", {}", *it);
                    }
                }
                plg::string p6_formated;
                if (!p6.empty()) {
                    p6_formated = std::format("{}", p6[0]);
                    for (auto it = std::next(p6.begin()); it != p6.end(); ++it) {
                        std::format_to(std::back_inserter(p6_formated), ", {}", *it);
                    }
                }
                plg::string p7_formated;
                if (!p7.empty()) {
                    p7_formated = std::format("{}", p7[0]);
                    for (auto it = std::next(p7.begin()); it != p7.end(); ++it) {
                        std::format_to(std::back_inserter(p7_formated), ", {}", *it);
                    }
                }
                plg::string p8_formated;
                if (!p8.empty()) {
                    p8_formated = std::format("{}", p8[0]);
                    for (auto it = std::next(p8.begin()); it != p8.end(); ++it) {
                        std::format_to(std::back_inserter(p8_formated), ", {}", *it);
                    }
                }
                plg::string p9_formated;
                if (!p9.empty()) {
                    p9_formated = std::format("{}", p9[0]);
                    for (auto it = std::next(p9.begin()); it != p9.end(); ++it) {
                        std::format_to(std::back_inserter(p9_formated), ", {}", *it);
                    }
                }
                plg::string p10_formated;
                if (!p10.empty()) {
                    p10_formated = std::format("{}", p10[0]);
                    for (auto it = std::next(p10.begin()); it != p10.end(); ++it) {
                        std::format_to(std::back_inserter(p10_formated), ", {}", *it);
                    }
                }
                plg::string p11_formated;
                if (!p11.empty()) {
                    p11_formated = std::format("{}", p11[0]);
                    for (auto it = std::next(p11.begin()); it != p11.end(); ++it) {
                        std::format_to(std::back_inserter(p11_formated), ", {}", *it);
                    }
                }
                plg::string p12_formated;
                if (!p12.empty()) {
                    p12_formated = std::format("{}", p12[0]);
                    for (auto it = std::next(p12.begin()); it != p12.end(); ++it) {
                        std::format_to(std::back_inserter(p12_formated), ", {}", *it);
                    }
                }
                plg::string p13_formated;
                if (!p13.empty()) {
                    p13_formated = std::format("{}", p13[0]);
                    for (auto it = std::next(p13.begin()); it != p13.end(); ++it) {
                        std::format_to(std::back_inserter(p13_formated), ", {}", *it);
                    }
                }
                plg::string p14_formated;
                if (!p14.empty()) {
                    p14_formated = std::format("{}", p14[0]);
                    for (auto it = std::next(p14.begin()); it != p14.end(); ++it) {
                        std::format_to(std::back_inserter(p14_formated), ", {}", *it);
                    }
                }
                plg::string p15_formated;
                if (!p15.empty()) {
                    p15_formated = std::format("'{}'", p15[0]);
                    for (auto it = std::next(p15.begin()); it != p15.end(); ++it) {
                        std::format_to(std::back_inserter(p15_formated), ", '{}'", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}",
                                                                 p1_formated, p2_formated, p3_formated, p4_formated, p5_formated, p6_formated, p7_formated, p8_formated,
                                                                 p9_formated, p10_formated, p11_formated, p12_formated, p13_formated, p14_formated, p15_formated));
            }},
            {"ParamAllPrimitives", []() {
                const auto result = cross_call_master::ParamAllPrimitivesCallback(true, '%', u'☢', -1, -1000, -1000000, -1000000000000LL, 200, 50000, 3000000000LL, 9999999999LL,
                                                                                  reinterpret_cast<void*>(0xfedcbaabcdefLL), 0.001f, 987654.456789);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncVoid", []() {
                cross_call_master::CallFuncVoidCallback(&MockVoid);
            }},
            {"CallFuncBool", []() {
                const auto result = cross_call_master::CallFuncBoolCallback(&MockBool);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncChar8", []() {
                const auto result = cross_call_master::CallFuncChar8Callback(&MockChar8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncChar16", []() {
                const auto result = cross_call_master::CallFuncChar16Callback(&MockChar16);
                cross_call_master::ReverseReturn(std::format("{}", static_cast<int16_t>(result)));
            }},
            {"CallFuncInt8", []() {
                const auto result = cross_call_master::CallFuncInt8Callback(&MockInt8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncInt16", []() {
                const auto result = cross_call_master::CallFuncInt16Callback(&MockInt16);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncInt32", []() {
                const auto result = cross_call_master::CallFuncInt32Callback(&MockInt32);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncInt64", []() {
                const auto result = cross_call_master::CallFuncInt64Callback(&MockInt64);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncUInt8", []() {
                const auto result = cross_call_master::CallFuncUInt8Callback(&MockUInt8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncUInt16", []() {
                const auto result = cross_call_master::CallFuncUInt16Callback(&MockUInt16);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncUInt32", []() {
                const auto result = cross_call_master::CallFuncUInt32Callback(&MockUInt32);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncUInt64", []() {
                const auto result = cross_call_master::CallFuncUInt64Callback(&MockUInt64);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncPtr", []() {
                const auto result = cross_call_master::CallFuncPtrCallback(&MockPtr);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncFloat", []() {
                const auto result = cross_call_master::CallFuncFloatCallback(&MockFloat);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncDouble", []() {
                const auto result = cross_call_master::CallFuncDoubleCallback(&MockDouble);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncString", []() {
                const auto result = cross_call_master::CallFuncStringCallback(&MockString);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFuncBoolVector", []() {
                const auto result = cross_call_master::CallFuncBoolVectorCallback(&MockBoolVector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncChar8Vector", []() {
                const auto result = cross_call_master::CallFuncChar8VectorCallback(&MockChar8Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncChar16Vector", []() {
                const auto result = cross_call_master::CallFuncChar16VectorCallback(&MockChar16Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", static_cast<uint16_t>(result[0]));
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", static_cast<uint16_t>(*it));
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncInt8Vector", []() {
                const auto result = cross_call_master::CallFuncInt8VectorCallback(&MockInt8Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncInt16Vector", []() {
                const auto result = cross_call_master::CallFuncInt16VectorCallback(&MockInt16Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncInt32Vector", []() {
                const auto result = cross_call_master::CallFuncInt32VectorCallback(&MockInt32Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncInt64Vector", []() {
                const auto result = cross_call_master::CallFuncInt64VectorCallback(&MockInt64Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncUInt8Vector", []() {
                const auto result = cross_call_master::CallFuncUInt8VectorCallback(&MockUInt8Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncUInt16Vector", []() {
                const auto result = cross_call_master::CallFuncUInt16VectorCallback(&MockUInt16Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncUInt32Vector", []() {
                const auto result = cross_call_master::CallFuncUInt32VectorCallback(&MockUInt32Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncUInt64Vector", []() {
                const auto result = cross_call_master::CallFuncUInt64VectorCallback(&MockUInt64Vector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncPtrVector", []() {
                const auto result = cross_call_master::CallFuncPtrVectorCallback(&MockPtrVector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncFloatVector", []() {
                const auto result = cross_call_master::CallFuncFloatVectorCallback(&MockFloatVector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncDoubleVector", []() {
                const auto result = cross_call_master::CallFuncDoubleVectorCallback(&MockDoubleVector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("{}", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", {}", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncStringVector", []() {
                const auto result = cross_call_master::CallFuncStringVectorCallback(&MockStringVector);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("'{}'", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", '{}'", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFuncVec2", []() {
                const auto result = cross_call_master::CallFuncVec2Callback(&MockVec2);
                cross_call_master::ReverseReturn(std::format("{{{}, {}}}", result.x, result.y));
            }},
            {"CallFuncVec3", []() {
                const auto result = cross_call_master::CallFuncVec3Callback(&MockVec3);
                cross_call_master::ReverseReturn(std::format("{{{}, {}, {}}}", result.x, result.y, result.z));
            }},
            {"CallFuncVec4", []() {
                const auto result = cross_call_master::CallFuncVec4Callback(&MockVec4);
                cross_call_master::ReverseReturn(std::format("{{{}, {}, {}, {}}}", result.x, result.y, result.z, result.w));
            }},
            {"CallFuncMat4x4", []() {
                const auto result = cross_call_master::CallFuncMat4x4Callback(&MockMat4x4);
                cross_call_master::ReverseReturn(std::format("{{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}",
                                                             result.m[0][0], result.m[0][1], result.m[0][2], result.m[0][3],
                                                             result.m[1][0], result.m[1][1], result.m[1][2], result.m[1][3],
                                                             result.m[2][0], result.m[2][1], result.m[2][2], result.m[2][3],
                                                             result.m[3][0], result.m[3][1], result.m[3][2], result.m[3][3]));
            }},
            {"CallFunc1", []() {
                const auto result = cross_call_master::CallFunc1Callback(&MockFunc1);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc2", []() {
                const auto result = cross_call_master::CallFunc2Callback(&MockFunc2);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc3", []() {
                cross_call_master::CallFunc3Callback(&MockFunc3);
            }},
            {"CallFunc4", []() {
                const auto result = cross_call_master::CallFunc4Callback(&MockFunc4);
                cross_call_master::ReverseReturn(std::format("{{{}, {}, {}, {}}}", result.x, result.y, result.z, result.w));
            }},
            {"CallFunc5", []() {
                const auto result = cross_call_master::CallFunc5Callback(&MockFunc5);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc6", []() {
                const auto result = cross_call_master::CallFunc6Callback(&MockFunc6);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc7", []() {
                const auto result = cross_call_master::CallFunc7Callback(&MockFunc7);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc8", []() {
                const auto result = cross_call_master::CallFunc8Callback(&MockFunc8);
                cross_call_master::ReverseReturn(std::format("{{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}",
                                                             result.m[0][0], result.m[0][1], result.m[0][2], result.m[0][3],
                                                             result.m[1][0], result.m[1][1], result.m[1][2], result.m[1][3],
                                                             result.m[2][0], result.m[2][1], result.m[2][2], result.m[2][3],
                                                             result.m[3][0], result.m[3][1], result.m[3][2], result.m[3][3]));
            }},
            {"CallFunc9", []() {
                cross_call_master::CallFunc9Callback(&MockFunc9);
            }},
            {"CallFunc10", []() {
                const auto result = cross_call_master::CallFunc10Callback(&MockFunc10);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc11", []() {
                const auto result = cross_call_master::CallFunc11Callback(&MockFunc11);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc12", []() {
                const auto result = cross_call_master::CallFunc12Callback(&MockFunc12);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc13", []() {
                const auto result = cross_call_master::CallFunc13Callback(&MockFunc13);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc14", []() {
                const auto result = cross_call_master::CallFunc14Callback(&MockFunc14);
                plg::string formated;
                if (!result.empty()) {
                    formated = std::format("'{}'", result[0]);
                    for (auto it = std::next(result.begin()); it != result.end(); ++it) {
                        std::format_to(std::back_inserter(formated), ", '{}'", *it);
                    }
                }
                cross_call_master::ReverseReturn(std::format("{{{}}}", formated));
            }},
            {"CallFunc15", []() {
                const auto result = cross_call_master::CallFunc15Callback(&MockFunc15);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc16", []() {
                const auto result = cross_call_master::CallFunc16Callback(&MockFunc16);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc17", []() {
                const auto result = cross_call_master::CallFunc17Callback(&MockFunc17);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc18", []() {
                const auto result = cross_call_master::CallFunc18Callback(&MockFunc18);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc19", []() {
                const auto result = cross_call_master::CallFunc19Callback(&MockFunc19);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc20", []() {
                const auto result = cross_call_master::CallFunc20Callback(&MockFunc20);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc21", []() {
                const auto result = cross_call_master::CallFunc21Callback(&MockFunc21);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc22", []() {
                const auto result = cross_call_master::CallFunc22Callback(&MockFunc22);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc23", []() {
                const auto result = cross_call_master::CallFunc23Callback(&MockFunc23);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc24", []() {
                const auto result = cross_call_master::CallFunc24Callback(&MockFunc24);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc25", []() {
                const auto result = cross_call_master::CallFunc25Callback(&MockFunc25);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc26", []() {
                const auto result = cross_call_master::CallFunc26Callback(&MockFunc26);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc27", []() {
                const auto result = cross_call_master::CallFunc27Callback(&MockFunc27);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc28", []() {
                const auto result = cross_call_master::CallFunc28Callback(&MockFunc28);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc29", []() {
                const auto result = cross_call_master::CallFunc29Callback(&MockFunc29);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc30", []() {
                const auto result = cross_call_master::CallFunc30Callback(&MockFunc30);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc31", []() {
                const auto result = cross_call_master::CallFunc31Callback(&MockFunc31);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }},
            {"CallFunc32", []() {
                const auto result = cross_call_master::CallFunc32Callback(&MockFunc32);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }}
    };
    auto it = tests.find(test);
    if (it != tests.end()) {
        std::get<void(*)()>(*it)();
    }
}