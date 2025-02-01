#include "simple_tests.hpp"
#include <cstdint>
#include <limits>
#include <plugin_export.h>
#include <plugify/cpp_plugin.hpp>
#include <plugify/format.hpp>
#include <pps/cross_call_worker.hpp>
#include <numeric>

#define TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES (1 << 0)
#define TEST_NO_PARAM_ONLY_RETURN_OBJECTS (1 << 1)
#define TEST_NO_PARAM_ONLY_RETURN_ARRAYS (1 << 2)
#define TEST_NO_PARAM_ONLY_RETURN_VECTORS (1 << 3)
#define TEST_PARAMS_NO_REFS (1 << 4)
#define TEST_PARAMS_WITH_REFS (1 << 5)
#define TEST_PARAMS_REF_ARRAYS (1 << 6)
#define TEST_PARAMS_ALL_PRIMITIVES (1 << 7)
#define TEST_PARAMS_FUNCTIONS (1 << 8)
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES (1 << 16)
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS (1 << 17)
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS (1 << 18)
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS (1 << 19)
#define TEST_REVERSE_PARAMS_NO_REFS (1 << 20)
#define TEST_REVERSE_PARAMS_WITH_REFS (1 << 21)
#define TEST_REVERSE_PARAMS_REF_ARRAYS (1 << 22)
#define TEST_REVERSE_PARAMS_ALL_PRIMITIVES (1 << 23)
#define TEST_REVERSE_PARAMS_VARIANTS (1 << 24)
#define TEST_REVERSE_PARAMS_FUNCTIONS (1 << 25)
#define TEST_ALL 0xFFFFFFFF
#ifndef TEST_CASES
#define TEST_CASES TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES
#endif // !def TEST_CASE

using Example = cross_call_worker::Example;

// format support
#ifdef FMT_HEADER_ONLY
namespace fmt {
#else
namespace std {
#endif
    template<>
    struct formatter<Example> {
        constexpr auto parse(std::format_parse_context &ctx) {
            return ctx.begin();
        }

        template<class FormatContext>
        auto format(const Example& e, FormatContext &ctx) const {
            return std::format_to(ctx.out(), "{}", static_cast<int>(e));
        }
    };
}

// Mock Functions for the typedefs

void MockVoid() { /*std::cout << "Void function called\n";*/ }
bool MockBool() { return false; }
char MockChar8() { return 'B'; }
char16_t MockChar16() { return u'A'; }
int8_t MockInt8() { return 15; }
int16_t MockInt16() { return 150; }
int32_t MockInt32() { return 1500; }
int64_t MockInt64() { return 15000; }
uint8_t MockUInt8() { return 25; }
uint16_t MockUInt16() { return 250; }
uint32_t MockUInt32() { return 2500; }
uint64_t MockUInt64() { return 25000; }
void* MockPtr() { return reinterpret_cast<void*>(1); }
float MockFloat() { return 2.71f; }
double MockDouble() { return 5.55; }
void* MockFunction() { return reinterpret_cast<void*>(2); }
plg::string MockString() { return "Example string"; }
plg::any MockAny() { return 0xDEADBEAF; }

plg::vector<bool> MockBoolVector() { return {false, true}; }
plg::vector<char> MockChar8Vector() { return {'C', 'D'}; }
plg::vector<char16_t> MockChar16Vector() { return {u'C', u'D'}; }
plg::vector<int8_t> MockInt8Vector() { return {15, 25}; }
plg::vector<int16_t> MockInt16Vector() { return {150, 250}; }
plg::vector<int32_t> MockInt32Vector() { return {1500, 2500}; }
plg::vector<int64_t> MockInt64Vector() { return {15000, 25000}; }
plg::vector<uint8_t> MockUInt8Vector() { return {25, 35}; }
plg::vector<uint16_t> MockUInt16Vector() { return {250, 350}; }
plg::vector<uint32_t> MockUInt32Vector() { return {2500, 3500}; }
plg::vector<uint64_t> MockUInt64Vector() { return {25000, 35000}; }
plg::vector<void*> MockPtrVector() { return {reinterpret_cast<void*>(1), reinterpret_cast<void*>(2)}; }
plg::vector<float> MockFloatVector() { return {3.3f, 4.4f}; }
plg::vector<double> MockDoubleVector() { return {5.5, 6.6}; }
plg::vector<plg::string> MockStringVector() { return {"Foo", "Bar"}; }
plg::vector<plg::vec2> MockVec2Vector() {
    return {
            {1.1f, 2.2f},
            {3.3f, 4.4f},
            {-5.5f, -6.6f},
            {0.0f, 0.0f},
            {7.7f, 8.8f}
    };
}

plg::vector<plg::vec3> MockVec3Vector() {
    return {
            {1.1f, 2.2f, 3.3f},
            {4.4f, 5.5f, 6.6f},
            {-7.7f, -8.8f, -9.9f},
            {0.0f, 0.0f, 0.0f},
            {10.1f, 11.2f, 12.3f}
    };
}

plg::vector<plg::vec4> MockVec4Vector() {
    return {
            {1.1f, 2.2f, 3.3f, 4.4f},
            {5.5f, 6.6f, 7.7f, 8.8f},
            {-9.9f, -10.1f, -11.2f, -12.3f},
            {0.0f, 0.0f, 0.0f, 0.0f},
            {13.1f, 14.2f, 15.3f, 16.4f}
    };
}

plg::vector<plg::mat4x4> MockMat4x4Vector() {
    return {
            // Identity matrix
            {
                    1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
            },
            // Example random matrix
            {
                    2.0f, 3.0f, 4.0f, 5.0f,
                    6.0f, 7.0f, 8.0f, 9.0f,
                    10.0f, 11.0f, 12.0f, 13.0f,
                    14.0f, 15.0f, 16.0f, 17.0f
            },
            // Another random matrix
            {
                    -1.0f, -2.0f, -3.0f, -4.0f,
                    -5.0f, -6.0f, -7.0f, -8.0f,
                    -9.0f, -10.0f, -11.0f, -12.0f,
                    -13.0f, -14.0f, -15.0f, -16.0f
            }
    };
}
plg::vec2 MockVec2() { return {2.0f, 3.0f}; }
plg::vec3 MockVec3() { return {2.0f, 3.0f, 4.0f}; }
plg::vec4 MockVec4() { return {2.0f, 3.0f, 4.0f, 5.0f}; }
plg::mat4x4 MockMat4x4() { return {2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}; }

// Mock implementations for 1 parameter functions
int32_t MockFunc1(const plg::vec3& v) {
    const auto buffer = std::format("{}{}{}", v.x, v.y, v.z);
    return static_cast<int32_t>(v.x * 2 + v.y * 2 + v.z * 2);
}

// Mock implementations for 2 parameter functions
char MockFunc2(float a, int64_t b) {
    const auto buffer = std::format("{}{}", a, b);
    return '%';
}

// Mock implementations for 3 parameter functions
void MockFunc3(void* p, const plg::vec4& v, const plg::string& s) {
    const auto buffer = std::format("{}{}{}{}{}{}", p, v.x, v.y, v.z, v.w, s);
}

// Mock implementations for 4 parameter functions
plg::vec4 MockFunc4(bool flag, int32_t u, char16_t c, const plg::mat4x4& m) {
    const auto buffer = std::format("{}{}{}{}", flag, u, static_cast<uint16_t>(c), m.m[0][0]);
    return {5.0f, 6.0f, 7.0f, 8.0f};  // Returning a different dummy const plg::vec4
}

// Mock implementations for 5 parameter functions
bool MockFunc5(int8_t i, const plg::vec2& v, void* p, double d, const plg::vector<uint64_t>& vec) {
    const auto buffer = std::format("{}{}{}{}{}{}", i, v.x, v.y, p, d, vec.size());
    return false; // Changed return value to dummy false
}

// Mock implementations for 6 parameter functions
int64_t MockFunc6(const plg::string& s, float f, const plg::vector<float>& vec, int16_t i, const plg::vector<uint8_t>& uVec, void* p) {
    const auto buffer = std::format("{}{}{}{}{}{}", s, f, vec.size(), i, uVec.size(), p);
    return static_cast<int64_t>(f * 2 + i);  // Changed return value
}

// Mock implementations for 7 parameter functions
double MockFunc7(const plg::vector<char>& vec, uint16_t u, char16_t c, const plg::vector<uint32_t>& uVec, const plg::vec4& v, bool flag, uint64_t l) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}", vec.size(), u, static_cast<uint16_t>(c), uVec.size(), v.x, v.y, v.z, v.w, flag, l);
    return 6.28;  // Changed return value to a different dummy double
}

// Mock implementations for 8 parameter functions
plg::mat4x4 MockFunc8(const plg::vec3& v, const plg::vector<uint32_t>& uVec, int16_t i, bool flag, const plg::vec4& v4, const plg::vector<char16_t>& cVec, char16_t c, int32_t a) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}", v.x, v.y, v.z, uVec.size(), i, flag, v4.w, cVec.size(), static_cast<uint16_t>(c), a);
    return {}; // Returning a different dummy const plg::mat4x4
}

// Mock implementations for 9 parameter functions
void MockFunc9(float f, const plg::vec2& v, const plg::vector<int8_t>& iVec, uint64_t l, bool flag, const plg::string& s, const plg::vec4& v4, int16_t i, void* p) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}", f, v.x, v.y, iVec.size(), l, flag, s, v4.w, i, p);
}

// Mock implementations for 10 parameter functions
uint32_t MockFunc10(const plg::vec4& v4, const plg::mat4x4& m, const plg::vector<uint32_t>& uVec, uint64_t l, const plg::vector<char>& cVec, int32_t a, bool flag, const plg::vec2& v, int64_t i, double d) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", v4.x, v4.y, v4.z, v4.w, m.m[1][1], uVec.size(), l, cVec.size(), a, flag, v.x, v.y, i, d);
    return 84; // Changed to a different dummy uint32_t
}

// Mock implementations for 11 parameter functions
void* MockFunc11(const plg::vector<bool>& bVec, char16_t c, uint8_t u, double d, const plg::vec3& v3, const plg::vector<int8_t>& iVec, int64_t i, uint16_t u16, float f, const plg::vec2& v, uint32_t u32) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}", bVec.size(), static_cast<uint16_t>(c), u, d, v3.x, iVec.size(), i, u16, f, v.x, u32);
    return reinterpret_cast<void*>(1); // Changed to return a non-null pointer
}

// Mock implementations for 12 parameter functions
bool MockFunc12(void* p, const plg::vector<double>& dVec, uint32_t u, double d, bool flag, int32_t a, int8_t i, uint64_t l, float f, const plg::vector<void*>& pVec, int64_t i64, char c) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}", p, dVec.size(), u, d, flag, a, i, l, f, pVec.size(), i64, c);
    return true; // Changed to return dummy true
}

// Mock implementations for 13 parameter functions
plg::string MockFunc13(int64_t i64, const plg::vector<char>& cVec, uint16_t u16, float f, const plg::vector<bool>& bVec, const plg::vec4& v4, const plg::string& s, int32_t a, const plg::vec3& v3, void* p, const plg::vec2& v2, const plg::vector<uint8_t>& u8Vec, int16_t i16) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", i64, cVec.size(), u16, f, bVec.size(), v4.z, s, a, v3.x, p, v2.x, u8Vec.size(), i16);
    return "Updated Dummy String"; // Changed return string
}

// Mock implementations for 14 parameter functions
plg::vector<plg::string> MockFunc14(const plg::vector<char>& cVec, const plg::vector<uint32_t>& uVec, const plg::mat4x4& m, bool flag, char16_t c, int32_t a, const plg::vector<float>& fVec, uint16_t u16, const plg::vector<uint8_t>& u8Vec, int8_t i8, const plg::vec3& v3, const plg::vec4& v4, double d, void* p) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}", cVec.size(), uVec.size(), m.m[2][2], flag, static_cast<uint16_t>(c), a, fVec.size(), u16, u8Vec.size(), i8, v3.x, v4.x, d, p);
    return {"New String1", "New String2"}; // Changed return values
}

// Mock implementations for 15 parameter functions
int16_t MockFunc15(const plg::vector<int16_t>& iVec, const plg::mat4x4& m, const plg::vec4& v4, void* p, uint64_t l, const plg::vector<uint32_t>& uVec, bool flag, float f, const plg::vector<char16_t>& cVec, uint8_t u, int32_t a, const plg::vec2& v2, uint16_t u16, double d, const plg::vector<uint8_t>& u8Vec) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", iVec.size(), m.m[1][0], v4.x, p, l, uVec.size(), flag, f, cVec.size(), u, a, v2.x, u16, d, u8Vec.size());
    return 512; // Changed to a different dummy int16_t
}

// Mock implementations for 16 parameter functions
void* MockFunc16(const plg::vector<bool>& bVec, int16_t i16, const plg::vector<int8_t>& iVec, const plg::vec4& v4, const plg::mat4x4& m, const plg::vec2& v2, const plg::vector<uint64_t>& uVec, const plg::vector<char>& cVec, const plg::string& s, int64_t i64, const plg::vector<uint32_t>& u32Vec, const plg::vec3& v3, float f, double d, int8_t i8, uint16_t u16) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}", i16, bVec.size(), iVec.size(), v4.x,  v4.y,  v4.z, v4.w, m.m[2][3], v2.x, uVec.size(), cVec.size(), s, i64, u32Vec.size(), v3.x, f, d, i8, u16);
    return reinterpret_cast<void*>(2); // Changed to return a different non-null pointer
}

// Mock implementations for 17 parameter functions
void MockFunc17(int32_t& ref) {
    ref += 20;  // Modified value change
}

// Mock implementations for 18 parameter functions
plg::vec2 MockFunc18(int8_t& i8, int16_t& i16) {
    i8 = 10;     // Changed int8_t value
    i16 = 20;    // Changed int16_t value
    return {static_cast<float>(i8), static_cast<float>(i16)};  // Updated return values
}

// Mock implementations for 19 parameter functions
void MockFunc19(uint32_t& u32, plg::vec3& v3, plg::vector<uint32_t>& uVec) {
    u32 = 84;      // Changed uint32_t value
    v3 = {4.0f, 5.0f, 6.0f}; // Updated plg::vec3 reference
    uVec = {4, 5, 6}; // Changed plg::vector<uint32_t> values
}

// Mock implementations for 20 parameter functions
int32_t MockFunc20(char16_t& c, plg::vec4& v4, plg::vector<uint64_t>& uVec, char& ch) {
    c = u'g'; // Changed char16_t value
    v4 = {5.0f, 6.0f, 7.0f, 8.0f}; // Updated plg::vec4 reference
    uVec = {300, 400}; // Changed plg::vector<uint64_t> values
    ch = 'G'; // Modified char value
    return 1; // Updated return value
}

// Mock implementations for 21 parameter functions
float MockFunc21(plg::mat4x4& m, plg::vector<int32_t>& iVec, plg::vec2& v2, bool& flag, double& d) {
    flag = false; // Changed boolean reference
    d = 6.28;    // Updated double reference
    v2 = {3.0f, 4.0f}; // Changed plg::vec2 reference
    m = {
        1.5f, 0.7f, 0.9f, 0.6f,  // Updated values
        0.8f, 1.2f, 0.3f, 0.5f,
        1.1f, 0.4f, 1.3f, 0.8f,
        0.6f, 1.0f, 0.4f, 0.9f
    }; // Updated plg::mat4x4 reference
    iVec = {10, 20, 30}; // Changed plg::vector<int32_t> values
    return 1.0f; // Updated return value
}

// Mock implementations for 22 parameter functions
uint64_t MockFunc22(void*& p, uint32_t& u32, plg::vector<double>& dVec, int16_t& i16, plg::string& s, plg::vec4& v4) {
    p = reinterpret_cast<void*>(0x1); // Updated void* reference
    u32 = 150;    // Changed uint32_t value
    i16 = 456;   // Changed int16_t value
    s = "World"; // Changed string reference
    v4 = {5.0f, 6.0f, 7.0f, 8.0f}; // Updated plg::vec4 reference
    dVec = {4.4, 5.5, 6.6}; // Updated plg::vector<double> values
    return 2; // Updated return value
}

// Mock implementations for 23 parameter functions
void MockFunc23(uint64_t& u64, plg::vec2& v2, plg::vector<int16_t>& iVec, char16_t& c, float& f, int8_t& i8, plg::vector<uint8_t>& u8Vec) {
    u64 = 100; // Changed uint64_t reference
    f = 2.0f; // Updated float reference
    i8 = 2;  // Changed int8_t reference
    v2 = {6.0f, 7.0f}; // Updated plg::vec2 reference
    u8Vec = {4, 5, 6}; // Changed plg::vector<uint8_t> values
    c = L'Ⅷ'; // Updated char16_t value
    iVec = {4, 5, 6, 7}; // Changed plg::vector<int16_t> values
}

// Mock implementations for 24 parameter functions
plg::mat4x4 MockFunc24(plg::vector<char>& cVec, int64_t& i64, plg::vector<uint8_t>& u8Vec, plg::vec4& v4, uint64_t& u64, plg::vector<void*>& pVec, double& d, plg::vector<void*>& vVec) {
    i64 = 128;  // Changed int64_t reference
    d = 3.14;  // Updated double reference
    v4 = {5.0f, 6.0f, 7.0f, 8.0f}; // Updated plg::vec4 reference
    cVec = {'d', 'e', 'f'}; // Changed plg::vector<char> values
    u8Vec = {7, 8, 9}; // Changed plg::vector<uint8_t> values
    pVec = { reinterpret_cast<void *>(0xFFFFDDDDFFFFDDDD) }; // Updated plg::vector<void*> values
    vVec = {reinterpret_cast<void *>(3), reinterpret_cast<void *>(4)}; // Updated plg::vector<void*> values
    u64 = 0xFFFFFFFFFF; // Changed uint64_t reference
    return {}; // Returning dummy plg::mat4x4
}

// Mock implementations for 25 parameter functions
double MockFunc25(int32_t& i32, plg::vector<void*>& pVec, bool& flag, uint8_t& u8, plg::string& s, plg::vec3& v3, int64_t& i64, plg::vec4& v4, uint16_t& u16) {
    flag = true; // Changed boolean reference
    i32 = 200;    // Updated int32_t reference
    u8 = 128;     // Changed uint8_t reference
    v3 = {4.0f, 5.0f, 6.0f}; // Updated plg::vec3 reference
    v4 = {8.0f, 9.0f, 10.0f, 11.0f}; // Changed plg::vec4 reference
    s = "UpdatedMockFunc25"; // Changed string reference
    pVec = { reinterpret_cast<void *>(0xDEADBEEFDEADBEEF) }; // Updated plg::vector<void*> values
    i64 = 2023; // Changed int64_t reference
    u16 = 64222; // Changed uint16_t reference
    return 1.0;   // Updated return value
}

// Mock implementations for 26 parameter functions
char MockFunc26(char16_t& c, plg::vec2& v2, plg::mat4x4& m, plg::vector<float>& fVec, int16_t& i16, uint64_t& u64, uint32_t& u32, plg::vector<uint16_t>& u16Vec, void*& p, bool& flag) {
    c = u'A'; // Updated char16_t reference
    flag = false; // Changed boolean reference
    v2 = {4.0f, 5.0f}; // Updated plg::vec2 reference
    m = {
        0.5f, 0.3f, 0.1f, 0.4f,  // Updated values
        1.5f, 0.7f, 0.6f, 0.8f,
        1.1f, 0.4f, 0.2f, 1.0f,
        0.9f, 0.8f, 0.6f, 1.0f
    }; // Updated plg::mat4x4 reference
    fVec = {3.3f, 4.4f}; // Changed plg::vector<float> values
    u64 = 64; // Updated uint64_t reference
    u32 = 64; // Updated uint32_t reference
    u16Vec = {150, 250}; // Changed plg::vector<uint16_t> values
    i16 = 1024; // Changed int16_t reference
    p = reinterpret_cast<void *>(0xBADCAFE); // Updated void* reference
    return 'B'; // Updated return value
}

// Mock implementations for 27 parameter functions
uint8_t MockFunc27(float& f, plg::vec3& v3, void*& p, plg::vec2& v2, plg::vector<int16_t>& i16Vec, plg::mat4x4& m, bool& flag, plg::vec4& v4, int8_t& i8, int32_t& i32, plg::vector<uint8_t>& u8Vec) {
    f = 9.0f; // Changed float reference
    v3 = {7.0f, 8.0f, 9.0f}; // Updated plg::vec3 reference
    p = reinterpret_cast<void *>(0xDEADBEEFDEADBEEF); // Updated void* reference
    v2 = {5.0f, 6.0f}; // Updated plg::vec2 reference
    i16Vec = {3, 6, 9}; // Changed plg::vector<int16_t> values
    m = {
        1.5f, 2.5f, 3.5f, 4.5f, // Updated values
        5.5f, 6.5f, 7.5f, 8.5f,
        9.5f, 10.5f, 11.5f, 12.5f,
        13.5f, 14.5f, 15.5f, 16.5f
    }; // Updated plg::mat4x4 reference
    flag = true; // Changed boolean reference
    v4 = {2.0f, 3.0f, 4.0f, 5.0f}; // Changed plg::vec4 reference
    i8 = 10; // Updated int8_t reference
    i32 = 20; // Updated int32_t reference
    u8Vec = { 1, 55, 66, 87, 99, 23, 123 };
    return 27; // Updated return value
}

// Mock implementations for 28 parameter functions
plg::string MockFunc28(void*& ptr, uint16_t& u16, plg::vector<uint32_t>& u32Vec, plg::mat4x4& m, float& f, plg::vec4& v4, plg::string& str, plg::vector<uint64_t>& u64Vec, int64_t& i64, bool& b, plg::vec3& vec3, plg::vector<float>& fVec) {
    ptr = reinterpret_cast<void*>(0x7FFFFFFFFFFF);
    u16 = 60000; // Updated value
    u32Vec = { 10, 20, 30, 40, 50, 60 }; // Updated values
    m = {
        2.1f, 0.9f, 0.4f, 0.8f,  // Row 0
        0.5f, 1.2f, 0.7f, 0.4f,  // Row 1
        1.0f, 0.6f, 1.5f, 0.2f,  // Row 2
        0.8f, 0.3f, 0.9f, 1.1f   // Row 3
    };
    f = 7.5f; // Updated value for float reference
    v4 = {2.0f, 3.0f, 4.0f, 5.0f}; // Updated value for plg::vec4 reference
    u64Vec = {10, 20, 30}; // Updated values for plg::vector<uint64_t>
    i64 = 900000000000; // Updated value
    b = false; // Updated boolean value
    vec3 = {40, 50, 60}; // Updated values for plg::vec3
    str = "Updated MockFunc28"; // Updated string
    fVec = {10.0f, -500.0f, 1000.0f}; // Updated float vector
    return str; // Returning updated string
}

// Mock implementations for 29 parameter functions
plg::vector<plg::string> MockFunc29(plg::vec4& v4, int32_t& i32, plg::vector<int8_t>& iVec, double& d, bool& flag, int8_t& i8, plg::vector<uint16_t>& u16Vec, float& f, plg::string& s, plg::mat4x4& m, uint64_t& u64, plg::vec3& v3, plg::vector<int64_t>& i64Vec) {
    i32 = 50; // Updated value for int32_t reference
    flag = false; // Updated boolean value
    v4 = {2.5f, 3.5f, 4.5f, 5.5f}; // Updated value for plg::vec4 reference
    d = 6.28; // Updated double value
    i8 = 10; // Updated int8_t value
    u16Vec = {150, 250}; // Updated values for plg::vector<uint16_t>
    f = 2.5f; // Updated value for float reference
    s = "Updated MockFunc29"; // Updated string reference
    m = {
        0.6f, 1.1f, 0.7f, 0.2f,  // Row 0
        1.3f, 0.9f, 0.5f, 1.0f,  // Row 1
        0.8f, 0.4f, 1.6f, 0.7f,  // Row 2
        0.2f, 1.0f, 0.9f, 1.5f   // Row 3
    };
    u64 = 128; // Updated value for uint64_t reference
    v3 = {4.0f, 5.0f, 6.0f}; // Updated value for plg::vec3 reference
    i64Vec = {4, 5, 6}; // Updated values for plg::vector<int64_t>
    iVec = {100, 99, 98}; // Updated values for plg::vector<int8_t>
    return {"Updated Example", "Updated MockFunc29"}; // Returning updated vector of strings
}

// Mock implementations for 30 parameter functions
int32_t MockFunc30(void*& p, plg::vec4& v4, int64_t& i64, plg::vector<uint32_t>& uVec, bool& flag, plg::string& s, plg::vec3& v3, plg::vector<uint8_t>& u8Vec, float& f, plg::vec2& v2, plg::mat4x4& m, int8_t& i8, plg::vector<float>& vVec, double& d) {
    flag = true; // Updated boolean value
    f = 3.3f; // Updated value for float reference
    i64 = 2000; // Updated value for int64_t reference
    v2 = {4.0f, 5.0f}; // Updated value for plg::vec2 reference
    v4 = {2.0f, 4.0f, 6.0f, 8.0f}; // Updated value for plg::vec4 reference
    s = "Updated MockFunc30"; // Updated string reference
    p = reinterpret_cast<void*>(0x7FFFFFFFFFFF); // Keeping void* reference as nullptr
    uVec = {300, 400}; // Updated values for plg::vector<uint32_t>
    m = {
        0.6f, 0.2f, 1.5f, 0.9f,  // Row 0
        1.2f, 0.4f, 0.7f, 0.8f,  // Row 1
        0.5f, 0.1f, 1.7f, 0.4f,  // Row 2
        0.8f, 0.6f, 1.2f, 1.3f   // Row 3
    }; // Updated value for plg::mat4x4 reference
    i8 = 10; // Updated value for int8_t reference
    vVec = {3.0f, 3.0f, 4.0f, 4.0f}; // Updated values for plg::vector<float>
    d = 3.14159; // Updated double value
    v3 = { 4.0f, 5.0f, 6.0f }; // Updated values for plg::vec3
    u8Vec = { 128, 64, 255, 0, 100, 50 }; // Updated values for plg::vector<uint8_t>
    return 77; // Updated return value
}

// Mock implementations for 31 parameter functions
plg::vec3 MockFunc31(char& c, uint32_t& u32, plg::vector<uint64_t>& uVec, plg::vec4& v4, plg::string& s, bool& flag, int64_t& i64, plg::vec2& v2, int8_t& i8, uint16_t& u16, plg::vector<int16_t>& iVec, plg::mat4x4& m, plg::vec3& v3, float& f, plg::vector<double>& v4Vec) {
    u32 = 54321; // Updated value for uint32_t reference
    flag = false; // Updated boolean value
    v3 = {10.0f, 20.0f, 30.0f}; // Updated value for plg::vec3 reference
    c = 'D'; // Updated char value
    uVec = { UINT64_MAX, UINT64_MAX - 1 , UINT64_MAX - 2 };
    v4 = {5.0f, 6.0f, 7.0f, 8.0f}; // Updated value for plg::vec4 reference
    s = "Updated MockFunc31"; // Updated string reference
    i64 = 987654321; // Updated value for int64_t reference
    v2 = {6.0f, 7.0f}; // Updated value for plg::vec2 reference
    i8 = 9; // Updated int8_t value
    u16 = 500; // Updated value for uint16_t reference
    iVec = {5, 10}; // Updated values for plg::vector<int16_t>
    m = {
        1.0f, 0.2f, 1.1f, 0.4f,  // Row 0
        1.1f, 0.8f, 0.3f, 0.9f,  // Row 1
        0.5f, 0.7f, 1.8f, 0.6f,  // Row 2
        0.3f, 0.6f, 1.4f, 0.8f   // Row 3
    }; // Updated value for plg::mat4x4 reference
    f = 8.8f; // Updated value for float reference
    v4Vec = {0.2, 0.4, 0.6}; // Updated values for plg::vector<double>
    return {1.0f, 2.0f, 3.0f}; // Updated return value for plg::vec3
}

// Mock implementations for 32 parameter functions
double MockFunc32(int32_t& i32, uint16_t& u16, plg::vector<int8_t>& iVec, plg::vec4& v4, void*& p, plg::vector<uint32_t>& uVec, plg::mat4x4& m, uint64_t& u64, plg::string& s, int64_t& i64, plg::vec2& v2, plg::vector<int8_t>& u8Vec, bool& flag, plg::vec3& v3, uint8_t& u8, plg::vector<char16_t>& cVec) {
    i32 = 100; // Updated value for int32_t reference
    u16 = 512; // Updated value for uint16_t reference
    flag = true; // Updated boolean value
    v2 = {5.5f, 6.5f}; // Updated value for plg::vec2 reference
    u8Vec = {6, 7, 8, 9}; // Updated values for plg::vector<int8_t>
    v4 = {8.0f, 9.0f, 10.0f, 11.0f}; // Updated value for plg::vec4 reference
    s = "Updated MockFunc32"; // Updated string reference
    p = reinterpret_cast<void*>(0xDEADBEAFDEADBEAF); // Keeping void* reference as nullptr
    m = {
        0.5f, 0.3f, 0.2f, 0.1f,  // Row 0
        0.8f, 0.9f, 0.4f, 0.6f,  // Row 1
        0.1f, 0.7f, 1.0f, 0.5f,  // Row 2
        0.4f, 0.2f, 0.3f, 1.2f   // Row 3
    }; // Updated value for plg::mat4x4 reference
    u64 = 987654321; // Updated value for uint64_t reference
    uVec = {400, 500}; // Updated values for plg::vector<uint32_t>
    i64 = 2000; // Updated value for int64_t reference
    v3 = {1.0f, 2.0f, 3.0f}; // Updated value for plg::vec3 reference
    u8 = 15; // Updated value for uint8_t reference
    cVec = {u'x', u'y', u'z'}; // Updated values for plg::vector<char16_t>
    iVec = { 5, 10 }; // Updated values for plg::vector<int8_t>
    return 2.5; // Updated return value for double
}

// Mock implementations for 1 parameter functions
void MockFunc33(plg::any& variant) {
    variant = "Updated MockFunc33"; // Updated value for variant reference
}

// Mock implementations for enu parameters functions
plg::vector<Example> MockFuncEnum(Example p1, plg::vector<Example>& p2) {
    p2 = { Example::Forth, Example::Third, Example::Second };
    return { p1, Example::First };
}

class CrossCallMaster : public plg::IPluginEntry {
	void OnPluginStart() override {
		NoParamOnlyReturn();
		ParamsNoRefs();
		ParamsWithRefs();
		ParamsRefVectors();
		ParamsAllPrimitives();
		ParamsFunctions();
		ReverseNoParamOnlyReturn();
		ReverseParamsNoRefs();
		ReverseParamsWithRefs();
		ReverseParamsRefVectors();
		ReverseParamsAllPrimitives();
		ReverseParamsVariants();
		ReverseParamsFunctions();
		_tests.Run();
	}

    void OnPluginEnd() override {
        _tests.Reset();
    };

	void NoParamOnlyReturn() {
#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES
		_tests.Add("NoParamReturnVoid", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::NoParamReturnVoid();
		});
		_tests.Add("NoParamReturnBool", [](SimpleTests::Test& test) {
			auto expected = true;
			auto result = cross_call_worker::NoParamReturnBool();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnChar8", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<char>::max();
			auto result = cross_call_worker::NoParamReturnChar8();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", static_cast<uint8_t>(result), static_cast<uint8_t>(expected)));
			}
		});
		_tests.Add("NoParamReturnChar16", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<char16_t>::max();
			auto result = cross_call_worker::NoParamReturnChar16();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", static_cast<uint16_t>(result), static_cast<uint16_t>(expected)));
			}
		});
		_tests.Add("NoParamReturnInt8", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int8_t>::max();
			auto result = cross_call_worker::NoParamReturnInt8();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnInt16", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int16_t>::max();
			auto result = cross_call_worker::NoParamReturnInt16();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnInt32", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int32_t>::max();
			auto result = cross_call_worker::NoParamReturnInt32();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnInt64", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int64_t>::max();
			auto result = cross_call_worker::NoParamReturnInt64();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt8", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint8_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt8();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt16", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint16_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt16();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt32", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint32_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt32();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt64", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint64_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt64();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnPointer", [](SimpleTests::Test& test) {
			auto expected = reinterpret_cast<void*>(0x1);
			auto result = cross_call_worker::NoParamReturnPointer();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnFloat", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<float>::max();
			auto result = cross_call_worker::NoParamReturnFloat();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnDouble", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<double>::max();
			auto result = cross_call_worker::NoParamReturnDouble();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
#endif // TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES

#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_OBJECTS
		_tests.Add("NoParamReturnFunction", [](SimpleTests::Test& test) {
			cross_call_worker::NoParamReturnFunctionFunc expected = nullptr;
			auto result = cross_call_worker::NoParamReturnFunction();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", reinterpret_cast<void*>(result), reinterpret_cast<void*>(expected)));
			}
		});
		_tests.Add("NoParamReturnString", [](SimpleTests::Test& test) {
			auto expected = "Hello World";
			auto result = cross_call_worker::NoParamReturnString();
			if (result != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", result, expected));
			}
		});
		_tests.Add("NoParamReturnAny", [](SimpleTests::Test& test) {
			plg::any expected = plg::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			auto result = cross_call_worker::NoParamReturnAny();
			if (result.index() != expected.index() && std::format("{}", result) != std::format("{}", expected)) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", result, expected));
			}
		});
#endif // TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_OBJECTS

#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_ARRAYS
		_tests.Add("NoParamReturnArrayBool", [](SimpleTests::Test& test) {
			auto expected = plg::vector<bool>{true, false};
			auto result = cross_call_worker::NoParamReturnArrayBool();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayChar8", [](SimpleTests::Test& test) {
			auto expected = plg::vector<char>{'a', 'b', 'c', 'd'};
			auto result = cross_call_worker::NoParamReturnArrayChar8();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayChar16", [](SimpleTests::Test& test) {
			auto expected = plg::vector<char16_t>{u'a', u'b', u'c', u'd'};
			auto result = cross_call_worker::NoParamReturnArrayChar16();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayInt8", [](SimpleTests::Test& test) {
			auto expected = plg::vector<int8_t>{-3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt8();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayInt16", [](SimpleTests::Test& test) {
			auto expected = plg::vector<int16_t>{-4, -3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt16();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayInt32", [](SimpleTests::Test& test) {
			auto expected = plg::vector<int32_t>{-5, -4, -3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt32();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayInt64", [](SimpleTests::Test& test) {
			auto expected = plg::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt64();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayUInt8", [](SimpleTests::Test& test) {
			auto expected = plg::vector<uint8_t>{0, 1, 2, 3, 4, 5, 6, 7, 8};
			auto result = cross_call_worker::NoParamReturnArrayUInt8();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayUInt16", [](SimpleTests::Test& test) {
			auto expected = plg::vector<uint16_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			auto result = cross_call_worker::NoParamReturnArrayUInt16();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayUInt32", [](SimpleTests::Test& test) {
			auto expected = plg::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			auto result = cross_call_worker::NoParamReturnArrayUInt32();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayUInt64", [](SimpleTests::Test& test) {
			auto expected = plg::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
			auto result = cross_call_worker::NoParamReturnArrayUInt64();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayPointer", [](SimpleTests::Test& test) {
			auto expected = plg::vector<void*>{reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2), reinterpret_cast<void*>(3)};
			auto result = cross_call_worker::NoParamReturnArrayPointer();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayFloat", [](SimpleTests::Test& test) {
			auto expected = plg::vector<float>{-12.34f, 0.0f, 12.34f};
			auto result = cross_call_worker::NoParamReturnArrayFloat();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayDouble", [](SimpleTests::Test& test) {
			auto expected = plg::vector<double>{-12.345, 0.0, 12.345};
			auto result = cross_call_worker::NoParamReturnArrayDouble();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayString", [](SimpleTests::Test& test) {
			auto expected = plg::vector<plg::string>{"1st string", "2nd string", "3rd element string (Should be big enough to avoid small string optimization)"};
			auto result = cross_call_worker::NoParamReturnArrayString();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnArrayAny", [](SimpleTests::Test& test) {
			auto expected = plg::vector<plg::any>{1.0, 2.0f, "3rd element string (Should be big enough to avoid small string optimization)", plg::vector<plg::string>{"lolek", "and", "bolek"}, 1};
			auto result = cross_call_worker::NoParamReturnArrayAny();
			bool wrong = result.size() != expected.size();
            if (!wrong) {
                for (size_t i = 0; i < result.size(); ++i) {
                    wrong |= result[i].index() != expected[i].index() && std::format("{}", result) != std::format("{}", expected);
                }
            }
            if (wrong) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
        _tests.Add("NoParamReturnArrayVector2", [](SimpleTests::Test& test) {
            auto expected = plg::vector<plg::vec2>{{1.1f, 2.2f}, {-3.3f, 4.4f}, {5.5f, -6.6f}, {7.7f, 8.8f}, {0.0f, 0.0f}};
            auto result = cross_call_worker::NoParamReturnArrayVector2();
            if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
            }
        });
        _tests.Add("NoParamReturnArrayVector3", [](SimpleTests::Test& test) {
            auto expected = plg::vector<plg::vec3>{{1.1f, 2.2f, 3.3f}, {-4.4f, 5.5f, -6.6f}, {7.7f, 8.8f, 9.9f}, {0.0f, 0.0f, 0.0f}, {10.1f, -11.2f, 12.3f}};
            auto result = cross_call_worker::NoParamReturnArrayVector3();
            if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
            }
        });
        _tests.Add("NoParamReturnArrayVector4", [](SimpleTests::Test& test) {
            auto expected = plg::vector<plg::vec4>{{1.1f, 2.2f, 3.3f, 4.4f}, {-5.5f, 6.6f, -7.7f, 8.8f}, {9.9f, 0.0f, -1.1f, 2.2f}, {3.3f, 4.4f, 5.5f, 6.6f}, {-7.7f, -8.8f, 9.9f, -10.1f}};
            auto result = cross_call_worker::NoParamReturnArrayVector4();
            if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
            }
        });
        _tests.Add("NoParamReturnArrayMatrix4x4", [](SimpleTests::Test& test) {
            auto expected = plg::vector<plg::mat4x4>{{
                                                             1.0f, 0.0f, 0.0f, 0.0f,
                                                             0.0f, 1.0f, 0.0f, 0.0f,
                                                             0.0f, 0.0f, 1.0f, 0.0f,
                                                             0.0f, 0.0f, 0.0f, 1.0f  // Identity matrix
                                                     },
                                                     {
                                                             2.0f, 3.0f, 4.0f, 5.0f,
                                                             6.0f, 7.0f, 8.0f, 9.0f,
                                                             10.0f, 11.0f, 12.0f, 13.0f,
                                                             14.0f, 15.0f, 16.0f, 17.0f  // Example random matrix
                                                     },
                                                     {
                                                             -1.0f, -2.0f, -3.0f, -4.0f,
                                                             -5.0f, -6.0f, -7.0f, -8.0f,
                                                             -9.0f, -10.0f, -11.0f, -12.0f,
                                                             -13.0f, -14.0f, -15.0f, -16.0f  // Negative matrix
                                                     }};
            auto result = cross_call_worker::NoParamReturnArrayMatrix4x4();
            if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
            }
        });
#endif// TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_ARRAYS

#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_VECTORS
		_tests.Add("NoParamReturnVector2", [](SimpleTests::Test& test) {
			auto expected = plg::vec2{1, 2};
			auto result = cross_call_worker::NoParamReturnVector2();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result,  expected));
			}
		});
		_tests.Add("NoParamReturnVector3", [](SimpleTests::Test& test) {
			auto expected = plg::vec3{1, 2, 3};
			auto result = cross_call_worker::NoParamReturnVector3();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result,  expected));
			}
		});
		_tests.Add("NoParamReturnVector4", [](SimpleTests::Test& test) {
			auto expected = plg::vec4{1, 2, 3, 4};
			auto result = cross_call_worker::NoParamReturnVector4();
			if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result,  expected));
			}
		});
		_tests.Add("NoParamReturnMatrix4x4", [](SimpleTests::Test& test) {
			auto expected = plg::mat4x4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
			auto result = cross_call_worker::NoParamReturnMatrix4x4();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result,  expected));
			}
		});
#endif// TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_VECTORS
	}

	void ParamsNoRefs() {
#if TEST_CASES & TEST_PARAMS_NO_REFS
		constexpr const int32_t intValue = 42;
		constexpr float floatValue = 3.14f;
		constexpr const double doubleValue = 6.28;
		constexpr const char charValue = 'A';
		constexpr const char16_t char16Value = 'B';
		constexpr const int16_t shortValue = 10;
		constexpr void* const ptrValue = nullptr;
		
		_tests.Add("Param1", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::Param1(intValue);
		});

		_tests.Add("Param2", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::Param2(intValue, floatValue);
		});

		_tests.Add("Param3", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::Param3(intValue, floatValue, doubleValue);
		});

		_tests.Add("Param4", [&](SimpleTests::Test& /*test*/) {
			const plg::vec4 vector4Value{1.0f, 2.0f, 3.0f, 4.0f};
			cross_call_worker::Param4(intValue, floatValue, doubleValue, vector4Value);
		});

		_tests.Add("Param5", [&](SimpleTests::Test& /*test*/) {
			const plg::vec4 vector4Value{1.0f, 2.0f, 3.0f, 4.0f};
			const plg::vector<int64_t> longListValue = {100, 200, 300};
			cross_call_worker::Param5(intValue, floatValue, doubleValue, vector4Value, longListValue);
		});

		_tests.Add("Param6", [&](SimpleTests::Test& /*test*/) {
			const plg::vec4 vector4Value{1.0f, 2.0f, 3.0f, 4.0f};
			const plg::vector<int64_t> longListValue = {100, 200, 300};
			cross_call_worker::Param6(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue);
		});

		_tests.Add("Param7", [=](SimpleTests::Test& /*test*/) {
			const plg::vec4 vector4Value{1.0f, 2.0f, 3.0f, 4.0f};
			const plg::vector<int64_t> longListValue = {100, 200, 300};
			const plg::string stringValue = "Hello";
			cross_call_worker::Param7(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue);
		});

		_tests.Add("Param9", [=](SimpleTests::Test& /*test*/) {
			const plg::vec4 vector4Value{1.0f, 2.0f, 3.0f, 4.0f};
			const plg::vector<int64_t> longListValue = {100, 200, 300};
			const plg::string stringValue = "Hello";
			cross_call_worker::Param9(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue);
		});

		_tests.Add("Param10", [=](SimpleTests::Test& /*test*/) {
			const plg::vec4 vector4Value{1.0f, 2.0f, 3.0f, 4.0f};
			const plg::vector<int64_t> longListValue = {100, 200, 300};
			const plg::string stringValue = "Hello";
			cross_call_worker::Param10(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue, ptrValue);
		});
#endif // TEST_CASES & TEST_PARAMS_NO_REFS
	}

	void ParamsWithRefs() {
#if TEST_CASES & TEST_PARAMS_WITH_REFS
		_tests.Add("ParamRef1", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{42};
			int32_t intValue{};
			cross_call_worker::ParamRef1(intValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
		});
		_tests.Add("ParamRef2", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{10};
			const auto floatExpected = 3.14f;
			int32_t intValue{};
			float floatValue{};
			cross_call_worker::ParamRef2(intValue, floatValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
		});
		_tests.Add("ParamRef3", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{-20};
			const auto floatExpected = 2.718f;
			const auto doubleExpected = 3.14159;
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			cross_call_worker::ParamRef3(intValue, floatValue, doubleValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
		});
		_tests.Add("ParamRef4", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{100};
			const auto floatExpected = -5.55f;
			const auto doubleExpected = 1.618;
			const auto vector4Expected = plg::vec4{1.0f, 2.0f, 3.0f, 4.0f};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			cross_call_worker::ParamRef4(intValue, floatValue, doubleValue, vector4Value);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
                test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
		});
		_tests.Add("ParamRef5", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{500};
			const auto floatExpected = -10.5f;
			const auto doubleExpected = 2.71828;
			const auto vector4Expected = plg::vec4{-1.0f, -2.0f, -3.0f, -4.0f};
			const auto longListExpected = plg::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			plg::vector<int64_t> longListValue{};
			cross_call_worker::ParamRef5(intValue, floatValue, doubleValue, vector4Value, longListValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
                test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
			if (longListValue != longListExpected) {
				test.Fail(std::format("Wrong longListValue param {}, expected {}", longListValue, longListExpected));
			}
		});
		_tests.Add("ParamRef6", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{750};
			const auto floatExpected = 20.0f;
			const auto doubleExpected = 1.23456;
			const auto vector4Expected = plg::vec4{10.0f, 20.0f, 30.0f, 40.0f};
			const auto longListExpected = plg::vector<int64_t>{-6, -5, -4};
			const auto charExpected = 'Z';
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			plg::vector<int64_t> longListValue{};
			char charValue{};
			cross_call_worker::ParamRef6(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
                test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
			if (longListValue != longListExpected) {
                test.Fail(std::format("Wrong longListValue param {}, expected {}", longListValue, longListExpected));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
		});
		_tests.Add("ParamRef7", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{-1000};
			const auto floatExpected = 3.0f;
			const auto doubleExpected = -1;
			const auto vector4Expected = plg::vec4{100.0f, 200.0f, 300.0f, 400.0f};
			const auto longListExpected = plg::vector<int64_t>{-6, -5, -4, -3};
			const auto charExpected = 'Y';
			const auto stringExpected = plg::string{"Hello, World!"};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			plg::vector<int64_t> longListValue{};
			char charValue{};
			plg::string stringValue{};
			cross_call_worker::ParamRef7(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
			if (longListValue != longListExpected) {
                test.Fail(std::format("Wrong longListValue param {}, expected {}", longListValue, longListExpected));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
		});
		_tests.Add("ParamRef8", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{999};
			const auto floatExpected = -7.5f;
			const auto doubleExpected = 0.123456;
			const auto vector4Expected = plg::vec4{-100.0f, -200.0f, -300.0f, -400.0f};
			const auto longListExpected = plg::vector<int64_t>{-6, -5, -4, -3, -2, -1};
			const auto charExpected = 'X';
			const auto stringExpected = plg::string{"Goodbye, World!"};
			const auto char16Expected = 'A';
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			plg::vector<int64_t> longListValue{};
			char charValue{};
			plg::string stringValue{};
			char16_t char16Value{};
			cross_call_worker::ParamRef8(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
                test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
			if (longListValue != longListExpected) {
                test.Fail(std::format("Wrong longListValue param {}, expected {}", longListValue, longListExpected));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
			if (char16Value != char16Expected) {
				test.Fail(std::format("Wrong char16Value param {}, expected {}", static_cast<uint16_t>(char16Value), static_cast<uint16_t>(char16Expected)));
			}
		});
		_tests.Add("ParamRef9", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{-1234};
			const auto floatExpected = 123.45f;
			const auto doubleExpected = -678.9;
			const auto vector4Expected = plg::vec4{987.65f, 432.1f, 123.456f, 789.123f};
			const auto longListExpected = plg::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1, 5, 9};
			const auto charExpected = 'W';
			const auto stringExpected = plg::string{"Testing, 1 2 3"};
			const auto char16Expected = 'B';
			const auto shortExpected = int16_t{42};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			plg::vector<int64_t> longListValue{};
			char charValue{};
			plg::string stringValue{};
			char16_t char16Value{};
			int16_t shortValue{};
			cross_call_worker::ParamRef9(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
                test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
			if (longListValue != longListExpected) {
                test.Fail(std::format("Wrong longListValue param {}, expected {}", longListValue, longListExpected));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
			if (char16Value != char16Expected) {
				test.Fail(std::format("Wrong char16Value param {}, expected {}", static_cast<uint16_t>(char16Value), static_cast<uint16_t>(char16Expected)));
			}
			if (shortValue != shortExpected) {
				test.Fail(std::format("Wrong shortValue param {}, expected {}", shortValue, shortExpected));
			}
		});
		_tests.Add("ParamRef10", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{987};
			const auto floatExpected = -0.123f;
			const auto doubleExpected = 456.789;
			const auto vector4Expected = plg::vec4{-123.456f, 0.987f, 654.321f, -789.123f};
			const auto longListExpected = plg::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1, 5, 9, 4, -7};
			const auto charExpected = 'V';
			const auto stringExpected = plg::string{"Another string"};
			const auto char16Expected = 'C';
			const auto shortExpected = int16_t{-444};
			const auto ptrExpected = reinterpret_cast<void*>(0x12345678);
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plg::vec4 vector4Value{};
			plg::vector<int64_t> longListValue{};
			char charValue{};
			plg::string stringValue{};
			char16_t char16Value{};
			int16_t shortValue{};
			void* ptrValue{};
			cross_call_worker::ParamRef10(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue, ptrValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
                test.Fail(std::format("Wrong vector4Value param {}, expected {}", vector4Value, vector4Expected));
			}
			if (longListValue != longListExpected) {
                test.Fail(std::format("Wrong longListValue param {}, expected {}", longListValue, longListExpected));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
			if (char16Value != char16Expected) {
				test.Fail(std::format("Wrong char16Value param {}, expected {}", static_cast<uint16_t>(char16Value), static_cast<uint16_t>(char16Expected)));
			}
			if (shortValue != shortExpected) {
				test.Fail(std::format("Wrong shortValue param {}, expected {}", shortValue, shortExpected));
			}
			if (ptrValue != ptrExpected) {
				test.Fail(std::format("Wrong ptrValue param {}, expected {}", ptrValue, ptrExpected));
			}
		});
#endif// TEST_CASES & TEST_PARAMS_WITH_REFS
	}

	void ParamsRefVectors() {
#if TEST_CASES & TEST_PARAMS_REF_ARRAYS
		_tests.Add("ParamRefArrays", [](SimpleTests::Test& test) {
			const auto boolArrayExpected = plg::vector<bool>{true};
			const auto char8ArrayExpected = plg::vector<char>{'a', 'b', 'c'};
			const auto char16ArrayExpected = plg::vector<char16_t>{'d', 'e', 'f'};
			const auto sbyteArrayExpected = plg::vector<int8_t>{-3, -2, -1, 0, 1, 2, 3};
			const auto shortArrayExpected = plg::vector<int16_t>{-4, -3, -2, -1, 0, 1, 2, 3, 4};
			const auto intArrayExpected = plg::vector<int32_t>{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
			const auto longArrayExpected = plg::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
			const auto byteArrayExpected = plg::vector<uint8_t>{0, 1, 2, 3, 4, 5, 6, 7};
			const auto ushortArrayExpected = plg::vector<uint16_t>{0, 1, 2, 3, 4, 5, 6, 7, 8};
			const auto uintArrayExpected = plg::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			const auto ulongArrayExpected = plg::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			const auto intPtrArrayExpected = plg::vector<void*>{reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2)};
			const auto floatArrayExpected = plg::vector<float>{-12.34f, 0.0f, 12.34f};
			const auto doubleArrayExpected = plg::vector<double>{-12.345, 0.0, 12.345};
			const auto stringArrayExpected = plg::vector<plg::string>{"1", "12", "123", "1234", "12345", "123456"};
			plg::vector<bool> boolArray{true, false, true};
			plg::vector<char> char8Array{'A', 'B', 'C'};
			plg::vector<char16_t> char16Array{'D', 'E', 'F'};
			plg::vector<int8_t> sbyteArray{-1, -2, -3};
			plg::vector<int16_t> shortArray{10, 20, 30};
			plg::vector<int32_t> intArray{100, 200, 300};
			plg::vector<int64_t> longArray{1000, 2000, 3000};
			plg::vector<uint8_t> byteArray{1, 2, 3};
			plg::vector<uint16_t> ushortArray{1000, 2000, 3000};
			plg::vector<uint32_t> uintArray{10000, 20000, 30000};
			plg::vector<uint64_t> ulongArray{100000, 200000, 300000};
			plg::vector<void*> intPtrArray{nullptr, nullptr, nullptr};
			plg::vector<float> floatArray{1.1f, 2.2f, 3.3f};
			plg::vector<double> doubleArray{1.1, 2.2, 3.3};
			plg::vector<plg::string> stringArray{"Hello", "World", "!"};
			cross_call_worker::ParamRefVectors(boolArray, char8Array, char16Array, sbyteArray, shortArray, intArray, longArray,
				byteArray, ushortArray, uintArray, ulongArray, intPtrArray, floatArray, doubleArray, stringArray);
			if (boolArray != boolArrayExpected) {
				test.Fail(std::format("Wrong boolArray param {}, expected {}", char8Array, char8ArrayExpected));
			}
			if (char8Array != char8ArrayExpected) {
				test.Fail(std::format("Wrong char8Array array {}, expected {}", char8Array, char8ArrayExpected));
			}
			if (char16Array != char16ArrayExpected) {
				test.Fail(std::format("Wrong char16Array array {}, expected {}", char16Array, char16ArrayExpected));
			}
			if (sbyteArray != sbyteArrayExpected) {
				test.Fail(std::format("Wrong sbyteArray array {}, expected {}", sbyteArray, sbyteArrayExpected));
			}
			if (shortArray != shortArrayExpected) {
				test.Fail(std::format("Wrong shortArray array {}, expected {}", shortArray, shortArrayExpected));
			}
			if (intArray != intArrayExpected) {
				test.Fail(std::format("Wrong intArray array {}, expected {}", intArray, intArrayExpected));
			}
			if (longArray != longArrayExpected) {
				test.Fail(std::format("Wrong longArray array {}, expected {}", longArray, longArrayExpected));
			}
			if (byteArray != byteArrayExpected) {
				test.Fail(std::format("Wrong byteArray array {}, expected {}", byteArray, byteArrayExpected));
			}
			if (ushortArray != ushortArrayExpected) {
				test.Fail(std::format("Wrong ushortArray array {}, expected {}", ushortArray, ushortArrayExpected));
			}
			if (uintArray != uintArrayExpected) {
				test.Fail(std::format("Wrong uintArray array {}, expected {}", uintArray, uintArrayExpected));
			}
			if (ulongArray != ulongArrayExpected) {
				test.Fail(std::format("Wrong ulongArray array {}, expected {}", ulongArray, ulongArrayExpected));
			}
			if (intPtrArray != intPtrArrayExpected) {
				test.Fail(std::format("Wrong intPtrArray array {}, expected {}", intPtrArray, intPtrArrayExpected));
			}
			if (floatArray != floatArrayExpected) {
				test.Fail(std::format("Wrong floatArray array {}, expected {}", floatArray, floatArrayExpected));
			}
			if (doubleArray != doubleArrayExpected) {
				test.Fail(std::format("Wrong doubleArray array {}, expected {}", doubleArray, doubleArrayExpected));
			}
			if (stringArray != stringArrayExpected) {
				test.Fail(std::format("Wrong stringArray array {}, expected {}", stringArray, stringArrayExpected));
			}
		});
#endif// TEST_CASES & TEST_PARAMS_REF_ARRAYS
	}

	void ParamsAllPrimitives() {
#if TEST_CASES & TEST_PARAMS_ALL_PRIMITIVES
		_tests.Add("ParamAllPrimitives", [](SimpleTests::Test& test) {
			const auto expected = int64_t{56};
			const auto boolValue = true;
			const auto charValue = 'a';
			const auto char16Value = char16_t{'d'};
			const auto sbyteValue = int8_t{-3};
			const auto shortValue = int16_t{-4};
			const auto intValue = int32_t{-5};
			const auto longValue = int64_t{-6};
			const auto byteValue = uint8_t{7};
			const auto ushortValue = uint16_t{8};
			const auto uintValue = uint32_t{9};
			const auto ulongValue = uint64_t{10};
			const auto intPtrValue = reinterpret_cast<void*>(0);
			const auto floatValue = 1.1f;
			const auto doubleValue = 1.1;
			const auto result = cross_call_worker::ParamAllPrimitives(boolValue, charValue, char16Value, sbyteValue, shortValue, intValue, longValue,
																	  byteValue, ushortValue, uintValue, ulongValue, intPtrValue, floatValue, doubleValue);
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
        _tests.Add("ParamEnum", [](SimpleTests::Test& test) {
            const auto expected = int64_t{10};
            const auto enumValue = Example::Forth;
            const auto enumArrayValue = plg::vector<Example>{Example::First, Example::Second, Example::Third};
            const auto result = cross_call_worker::ParamEnum(enumValue, enumArrayValue);
            if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
            }
        });
        _tests.Add("ParamEnumRef", [](SimpleTests::Test& test) {
            const auto expected = int64_t{10};
            const auto enumValueExpected = Example::Forth;
            const auto enumArrayValueExpected = plg::vector<Example>{Example::First, Example::Second, Example::Third};
            Example enumValue{};
            plg::vector<Example> enumArrayValue{};
            const auto result = cross_call_worker::ParamEnumRef(enumValue, enumArrayValue);
            if (result != expected) {
                test.Fail(std::format("Wrong return {}, expected {}", result, expected));
            }
            if (enumValue != enumValueExpected) {
                test.Fail(std::format("Wrong doubleArray array {}, expected {}", enumValue, enumValueExpected));
            }
            if (enumArrayValue != enumArrayValueExpected) {
                test.Fail(std::format("Wrong stringArray array {}, expected {}", enumArrayValue, enumArrayValueExpected));
            }
        });
#endif// TEST_CASES & TEST_PARAMS_ALL_PRIMITIVES
	}

	void ParamsFunctions() {
#if TEST_CASES & TEST_PARAMS_FUNCTIONS
        _tests.Add("CallFuncVoid", [](SimpleTests::Test&) {
             cross_call_worker::CallFuncVoid(&MockVoid);
        });
        _tests.Add("CallFuncBool", [](SimpleTests::Test& test) {
            const bool expected = MockBool(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncBool(&MockBool);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncChar8", [](SimpleTests::Test& test) {
            const char expected = MockChar8(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncChar8(&MockChar8);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncChar16", [](SimpleTests::Test& test) {
            const char16_t expected = MockChar16(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncChar16(&MockChar16);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", static_cast<uint16_t>(result), static_cast<uint16_t>(expected)));
            }
        });
        _tests.Add("CallFuncInt8", [](SimpleTests::Test& test) {
            const int8_t expected = MockInt8(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt8(&MockInt8);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt16", [](SimpleTests::Test& test) {
            const int16_t expected = MockInt16(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt16(&MockInt16);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt32", [](SimpleTests::Test& test) {
            const int32_t expected = MockInt32(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt32(&MockInt32);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt64", [](SimpleTests::Test& test) {
            const int64_t expected = MockInt64(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt64(&MockInt64);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt8", [](SimpleTests::Test& test) {
            const uint8_t expected = MockUInt8(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt8(&MockUInt8);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt16", [](SimpleTests::Test& test) {
            const uint16_t expected = MockUInt16(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt16(&MockUInt16);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt32", [](SimpleTests::Test& test) {
            const uint32_t expected = MockUInt32(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt32(&MockUInt32);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt64", [](SimpleTests::Test& test) {
            const uint64_t expected = MockUInt64(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt64(&MockUInt64);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncPtr", [](SimpleTests::Test& test) {
            const void* expected = MockPtr(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncPtr(&MockPtr);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncFloat", [](SimpleTests::Test& test) {
            const float expected = MockFloat(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncFloat(&MockFloat);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncDouble", [](SimpleTests::Test& test) {
            const double expected = MockDouble(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncDouble(&MockDouble);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncString", [](SimpleTests::Test& test) {
            const plg::string expected = MockString(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncString(&MockString);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncAny", [](SimpleTests::Test& test) {
            const plg::any expected = MockAny(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncAny(&MockAny);
            if (result.index() != expected.index() && std::format("{}", result) != std::format("{}", expected)) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        /*_tests.Add("CallFuncFunction", [&](SimpleTests::Test& test) {
            const plg::string expected = "0x0"; // Adjust this if needed
            const auto result = cross_call_worker::CallFuncFunction();
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });*/
        _tests.Add("CallFuncBoolVector", [](SimpleTests::Test& test) {
            const plg::vector<bool> expected = MockBoolVector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncBoolVector(&MockBoolVector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncChar8Vector", [](SimpleTests::Test& test) {
            const plg::vector<char> expected = MockChar8Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncChar8Vector(&MockChar8Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncChar16Vector", [](SimpleTests::Test& test) {
            const plg::vector<char16_t> expected = MockChar16Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncChar16Vector(&MockChar16Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt8Vector", [](SimpleTests::Test& test) {
            const plg::vector<int8_t> expected = MockInt8Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt8Vector(&MockInt8Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt16Vector", [](SimpleTests::Test& test) {
            const plg::vector<int16_t> expected = MockInt16Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt16Vector(&MockInt16Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt32Vector", [](SimpleTests::Test& test) {
            const plg::vector<int32_t> expected = MockInt32Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt32Vector(&MockInt32Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncInt64Vector", [](SimpleTests::Test& test) {
            const plg::vector<int64_t> expected = MockInt64Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncInt64Vector(&MockInt64Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt8Vector", [](SimpleTests::Test& test) {
            const plg::vector<uint8_t> expected = MockUInt8Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt8Vector(&MockUInt8Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt16Vector", [](SimpleTests::Test& test) {
            const plg::vector<uint16_t> expected = MockUInt16Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt16Vector(&MockUInt16Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt32Vector", [](SimpleTests::Test& test) {
            const plg::vector<uint32_t> expected = MockUInt32Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt32Vector(&MockUInt32Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncUInt64Vector", [](SimpleTests::Test& test) {
            const plg::vector<uint64_t> expected = MockUInt64Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncUInt64Vector(&MockUInt64Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncPtrVector", [](SimpleTests::Test& test) {
            const plg::vector<void*> expected = MockPtrVector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncPtrVector(&MockPtrVector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncFloatVector", [](SimpleTests::Test& test) {
            const plg::vector<float> expected = MockFloatVector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncFloatVector(&MockFloatVector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncDoubleVector", [](SimpleTests::Test& test) {
            const plg::vector<double> expected = MockDoubleVector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncDoubleVector(&MockDoubleVector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncStringVector", [](SimpleTests::Test& test) {
            const plg::vector<plg::string> expected = MockStringVector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncStringVector(&MockStringVector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncVec2Vector", [](SimpleTests::Test& test) {
            const plg::vector<plg::vec2> expected = MockVec2Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncVec2Vector(&MockVec2Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncVec3Vector", [](SimpleTests::Test& test) {
            const plg::vector<plg::vec3> expected = MockVec3Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncVec3Vector(&MockVec3Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncVec4Vector", [](SimpleTests::Test& test) {
            const plg::vector<plg::vec4> expected = MockVec4Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncVec4Vector(&MockVec4Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncMat4x4Vector", [](SimpleTests::Test& test) {
            const plg::vector<plg::mat4x4> expected = MockMat4x4Vector(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncMat4x4Vector(&MockMat4x4Vector);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncVec2", [](SimpleTests::Test& test) {
            const plg::vec2 expected = MockVec2(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncVec2(&MockVec2);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncVec3", [](SimpleTests::Test& test) {
            const plg::vec3 expected = MockVec3(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncVec3(&MockVec3);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncVec4", [](SimpleTests::Test& test) {
            const plg::vec4 expected = MockVec4(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncVec4(&MockVec4);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncMat4x4", [](SimpleTests::Test& test) {
            const plg::mat4x4 expected = MockMat4x4(); // Adjust this if needed
            const auto result = cross_call_worker::CallFuncMat4x4(&MockMat4x4);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });

        _tests.Add("CallFunc1", [](SimpleTests::Test& test) {
            plg::vec3 vec{4.5f, 5.6f, 6.7f}; // Changed to random values
            const int32_t expected = MockFunc1(vec);
            const auto result = cross_call_worker::CallFunc1(&MockFunc1);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc2", [](SimpleTests::Test& test) {
            float f = 2.71f; // Changed to random float
            int64_t i64 = 200; // Changed to random int64_t
            const char expected = MockFunc2(f, i64);
            const auto result = cross_call_worker::CallFunc2(&MockFunc2);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc3", [](SimpleTests::Test&) {
            cross_call_worker::CallFunc3(&MockFunc3);
        });
        _tests.Add("CallFunc4", [](SimpleTests::Test& test) {
            bool b = false; // Changed to random bool
            int32_t u32 = 42; // Changed to random uint32_t
            char16_t ch16 = 'B'; // Changed to random character
            plg::mat4x4 mat{}; // Assume it's initialized properly
            const plg::vec4 expected = MockFunc4(b, u32, ch16, mat);
            const auto result = cross_call_worker::CallFunc4(&MockFunc4);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc5", [](SimpleTests::Test& test) {
            int8_t i8 = 10; // Changed to random int8_t
            plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
            void* ptr = reinterpret_cast<void *>(67890); // Example pointer changed
            double d = 1.618; // Changed to random double
            plg::vector<uint64_t> vec64{4, 5, 6}; // Changed to random values
            const bool expected = MockFunc5(i8, vec2, ptr, d, vec64);
            const auto result = cross_call_worker::CallFunc5(&MockFunc5);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc6", [](SimpleTests::Test& test) {
            plg::string str = "AnotherString"; // Changed string
            float f = 4.56f; // Changed to random float
            plg::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed to random values
            int16_t i16 = 30; // Changed to random int16_t
            plg::vector<uint8_t> vecU8{3, 4, 5}; // Changed to random values
            void* ptr = reinterpret_cast<void *>(24680); // Example pointer changed
            const int64_t expected = MockFunc6(str, f, vecF, i16, vecU8, ptr);
            const auto result = cross_call_worker::CallFunc6(&MockFunc6);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc7", [](SimpleTests::Test& test) {
            plg::vector<char> vecC{'X', 'Y', 'Z'}; // Changed to random chars
            uint16_t u16 = 20; // Changed to random uint16_t
            char16_t ch16 = 'C'; // Changed to random character
            plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
            plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
            bool b = false; // Changed to random bool
            uint64_t u64 = 200; // Changed to random uint64_t
            const double expected = MockFunc7(vecC, u16, ch16, vecU32, vec4, b, u64);
            const auto result = cross_call_worker::CallFunc7(&MockFunc7);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc8", [](SimpleTests::Test& test) {
            plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
            plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
            int16_t i16 = 30; // Changed to random int16_t
            bool b = false; // Changed to random bool
            plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
            plg::vector<char16_t> vecC16{ 'D', 'E' }; // Changed to random chars
            char16_t ch16 = L'B'; // Changed to random character
            int32_t i32 = 50; // Changed to random int32_t
            const plg::mat4x4 expected = MockFunc8(vec3, vecU32, i16, b, vec4, vecC16, ch16, i32);
            const auto result = cross_call_worker::CallFunc8(&MockFunc8);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc9", [](SimpleTests::Test&) {
            cross_call_worker::CallFunc9(&MockFunc9);
        });
        _tests.Add("CallFunc10", [](SimpleTests::Test& test) {
            plg::vec4 vec4{5.6f, 7.8f, 8.9f, 9.0f}; // Changed to random values
            plg::mat4x4 mat; // Assume it's initialized properly
            plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
            uint64_t u64 = 150; // Changed to random uint64_t
            plg::vector<char> vecC{'X', 'Y', 'Z'}; // Changed to random chars
            int32_t i32 = 60; // Changed to random int32_t
            bool b = false; // Changed to random bool
            plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
            int64_t i64 = 75; // Changed to random int64_t
            double d = 2.71; // Changed to random double
            const uint32_t expected = MockFunc10(vec4, mat, vecU32, u64, vecC, i32, b, vec2, i64, d);
            const auto result = cross_call_worker::CallFunc10(&MockFunc10);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc11", [](SimpleTests::Test& test) {
            plg::vector<bool> vecB{false, true, false}; // Changed to random bools
            char16_t ch16 = 'C'; // Changed to random character
            uint8_t u8 = 10; // Changed to random uint8_t
            double d = 2.71; // Changed to random double
            plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
            plg::vector<int8_t> vecI8{3, 4, 5}; // Changed to random values
            int64_t i64 = 150; // Changed to random int64_t
            uint16_t u16 = 20; // Changed to random uint16_t
            float f = 2.0f; // Changed to random float
            plg::vec2 vec2{4.5f, 6.7f}; // Changed to random values
            uint32_t u32 = 30; // Changed to random uint32_t
            const void* expected = MockFunc11(vecB, ch16, u8, d, vec3, vecI8, i64, u16, f, vec2, u32);
            const auto result = cross_call_worker::CallFunc11(&MockFunc11);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc12", [](SimpleTests::Test& test) {
            void* ptr = reinterpret_cast<void *>(98765); // Example pointer changed
            plg::vector<double> vecD{4.0, 5.0, 6.0}; // Changed to random values
            uint32_t u32 = 30; // Changed to random uint32_t
            double d = 1.41; // Changed to random double
            bool b = false; // Changed to random bool
            int32_t i32 = 25; // Changed to random int32_t
            int8_t i8 = 10; // Changed to random int8_t
            uint64_t u64 = 300; // Changed to random uint64_t
            float f = 2.72f; // Changed to random float
            plg::vector<void*> vecPtr{reinterpret_cast<void *>(2), reinterpret_cast<void *>(3), reinterpret_cast<void *>(4)}; // Changed to random values
            int64_t i64 = 200; // Changed to random int64_t
            char ch = 'B'; // Changed to random character
            const bool expected = MockFunc12(ptr, vecD, u32, d, b, i32, i8, u64, f, vecPtr, i64, ch);
            const auto result = cross_call_worker::CallFunc12(&MockFunc12);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc13", [](SimpleTests::Test& test) {
            int64_t i64 = 75; // Changed to random int64_t
            plg::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
            uint16_t u16 = 20; // Changed to random uint16_t
            float f = 2.71f; // Changed to random float
            plg::vector<bool> vecB{false, true, false}; // Changed to random bools
            plg::vec4 vec4{5.6f, 7.8f, 9.0f, 10.1f}; // Changed to random values
            plg::string str = "RandomString"; // Changed string
            int32_t i32 = 30; // Changed to random int32_t
            plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
            void* ptr = reinterpret_cast<void *>(13579); // Example pointer changed
            plg::vec2 vec2{4.5f, 6.7f}; // Changed to random values
            plg::vector<uint8_t> vecU8{2, 3, 4}; // Changed to random values
            int16_t i16 = 20; // Changed to random int16_t
            const plg::string expected = MockFunc13(i64, vecC, u16, f, vecB, vec4, str, i32, vec3, ptr, vec2, vecU8, i16);
            const auto result = cross_call_worker::CallFunc13(&MockFunc13);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc14", [](SimpleTests::Test& test) {
            plg::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
            plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
            plg::mat4x4 mat; // Assume it's initialized properly
            bool b = false; // Changed to random bool
            char16_t ch16 = L'B'; // Changed to random character
            int32_t i32 = 25; // Changed to random int32_t
            plg::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed to random values
            uint16_t u16 = 30; // Changed to random uint16_t
            plg::vector<uint8_t> vecU8{3, 4, 5}; // Changed to random values
            int8_t i8 = 10; // Changed to random int8_t
            plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
            plg::vec4 vec4{5.6f, 7.8f, 9.0f, 10.1f}; // Changed to random values
            double d = 2.72; // Changed to random double
            void* ptr = reinterpret_cast<void *>(54321); // Example pointer changed
            const plg::vector<plg::string> expected = MockFunc14(vecC, vecU32, mat, b, ch16, i32, vecF, u16, vecU8, i8, vec3, vec4, d, ptr);
            const auto result = cross_call_worker::CallFunc14(&MockFunc14);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc15", [](SimpleTests::Test& test) {
            plg::vector<int16_t> vecI16{4, 5, 6}; // Changed to random values
            plg::mat4x4 mat; // Assume it's initialized properly
            plg::vec4 vec4{7.8f, 8.9f, 9.0f, 10.1f}; // Changed to random values
            void* ptr = reinterpret_cast<void *>(12345); // Example pointer changed
            uint64_t u64 = 200; // Changed to random uint64_t
            plg::vector<uint32_t> vecU32{5, 6, 7}; // Changed to random values
            bool b = false; // Changed to random bool
            float f = 3.14f; // Changed to random float
            plg::vector<char16_t> vecC16{'D', 'E'}; // Changed to random chars
            uint8_t u8 = 6; // Changed to random uint8_t
            int32_t i32 = 25; // Changed to random int32_t
            plg::vec2 vec2{5.6f, 7.8f}; // Changed to random values
            uint16_t u16 = 40; // Changed to random uint16_t
            double d = 2.71; // Changed to random double
            plg::vector<uint8_t> vecU8{1, 3, 5}; // Changed to random values
            const int16_t expected = MockFunc15(vecI16, mat, vec4, ptr, u64, vecU32, b, f, vecC16, u8, i32, vec2, u16, d, vecU8);
            const auto result = cross_call_worker::CallFunc15(&MockFunc15);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc16", [](SimpleTests::Test& test) {
            plg::vector<bool> vecB{true, true, false}; // Changed to random bools
            int16_t i16 = 20; // Changed to random int16_t
            plg::vector<int8_t> vecI8{2, 3, 4}; // Changed to random values
            plg::vec4 vec4{7.8f, 8.9f, 9.0f, 10.1f}; // Changed to random values
            plg::mat4x4 mat; // Assume it's initialized properly
            plg::vec2 vec2{5.6f, 7.8f}; // Changed to random values
            plg::vector<uint64_t> vecU64{5, 6, 7}; // Changed to random values
            plg::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
            plg::string str = "DifferentString"; // Changed string
            int64_t i64 = 300; // Changed to random int64_t
            plg::vector<uint32_t> vecU32{6, 7, 8}; // Changed to random values
            plg::vec3 vec3{5.0f, 6.0f, 7.0f}; // Changed to random values
            float f = 3.14f; // Changed to random float
            double d = 2.718; // Changed to random double
            int8_t i8 = 6; // Changed to random int8_t
            uint16_t u16 = 30; // Changed to random uint16_t
            const void* expected = MockFunc16(vecB, i16, vecI8, vec4, mat, vec2, vecU64, vecC, str, i64, vecU32, vec3, f, d, i8, u16);
            const auto result = cross_call_worker::CallFunc16(&MockFunc16);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc17", [](SimpleTests::Test& test) {
            const plg::string expected = "62";
            const auto result = cross_call_worker::CallFunc17(&MockFunc17);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc18", [](SimpleTests::Test& test) {
            const plg::string expected = "{10, 20}|10|20";
            const auto result = cross_call_worker::CallFunc18(&MockFunc18);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc19", [](SimpleTests::Test& test) {
            const plg::string expected = "84|{4, 5, 6}|{4, 5, 6}";
            const auto result = cross_call_worker::CallFunc19(&MockFunc19);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc20", [](SimpleTests::Test& test) {
            const plg::string expected = "1|103|{5, 6, 7, 8}|{300, 400}|G";
            const auto result = cross_call_worker::CallFunc20(&MockFunc20);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc21", [](SimpleTests::Test& test) {
            const plg::string expected = "1|{{1.5, 0.7, 0.9, 0.6}, {0.8, 1.2, 0.3, 0.5}, {1.1, 0.4, 1.3, 0.8}, {0.6, 1, 0.4, 0.9}}|{10, 20, 30}|{3, 4}|false|6.28";
            const auto result = cross_call_worker::CallFunc21(&MockFunc21);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc22", [](SimpleTests::Test& test) {
            const plg::string expected = "2|0x1|150|{4.4, 5.5, 6.6}|456|World|{5, 6, 7, 8}";
            const auto result = cross_call_worker::CallFunc22(&MockFunc22);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc23", [](SimpleTests::Test& test) {
            const plg::string expected = "100|{6, 7}|{4, 5, 6, 7}|8551|2|2|{4, 5, 6}";
            const auto result = cross_call_worker::CallFunc23(&MockFunc23);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc24", [](SimpleTests::Test& test) {
            const plg::string expected = "{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}|{d, e, f}|128|{7, 8, 9}|{5, 6, 7, 8}|1099511627775|{0xffffddddffffdddd}|3.14|{0x3, 0x4}";
            const auto result = cross_call_worker::CallFunc24(&MockFunc24);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc25", [](SimpleTests::Test& test) {
            const plg::string expected = "1|200|{0xdeadbeefdeadbeef}|true|128|UpdatedMockFunc25|{4, 5, 6}|2023|{8, 9, 10, 11}|64222";
            const auto result = cross_call_worker::CallFunc25(&MockFunc25);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc26", [](SimpleTests::Test& test) {
            const plg::string expected = "B|65|{4, 5}|{{0.5, 0.3, 0.1, 0.4}, {1.5, 0.7, 0.6, 0.8}, {1.1, 0.4, 0.2, 1}, {0.9, 0.8, 0.6, 1}}|{3.3, 4.4}|64|64|{150, 250}|0xbadcafe|false";
            const auto result = cross_call_worker::CallFunc26(&MockFunc26);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc27", [](SimpleTests::Test& test) {
            const plg::string expected = "27|9|{7, 8, 9}|0xdeadbeefdeadbeef|{5, 6}|{3, 6, 9}|{{1.5, 2.5, 3.5, 4.5}, {5.5, 6.5, 7.5, 8.5}, {9.5, 10.5, 11.5, 12.5}, {13.5, 14.5, 15.5, 16.5}}|true|{2, 3, 4, 5}|10|20|{1, 55, 66, 87, 99, 23, 123}";
            const auto result = cross_call_worker::CallFunc27(&MockFunc27);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc28", [](SimpleTests::Test& test) {
            const plg::string expected = "Updated MockFunc28|0x7fffffffffff|60000|{10, 20, 30, 40, 50, 60}|{{2.1, 0.9, 0.4, 0.8}, {0.5, 1.2, 0.7, 0.4}, {1, 0.6, 1.5, 0.2}, {0.8, 0.3, 0.9, 1.1}}|7.5|{2, 3, 4, 5}|Updated MockFunc28|{10, 20, 30}|900000000000|false|{40, 50, 60}|{10, -500, 1000}";
            const auto result = cross_call_worker::CallFunc28(&MockFunc28);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc29", [](SimpleTests::Test& test) {
            const plg::string expected = "{'Updated Example', 'Updated MockFunc29'}|{2.5, 3.5, 4.5, 5.5}|50|{100, 99, 98}|6.28|false|10|{150, 250}|2.5|Updated MockFunc29|{{0.6, 1.1, 0.7, 0.2}, {1.3, 0.9, 0.5, 1}, {0.8, 0.4, 1.6, 0.7}, {0.2, 1, 0.9, 1.5}}|128|{4, 5, 6}|{4, 5, 6}";
            const auto result = cross_call_worker::CallFunc29(&MockFunc29);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc30", [](SimpleTests::Test& test) {
            const plg::string expected = "77|0x7fffffffffff|{2, 4, 6, 8}|2000|{300, 400}|true|Updated MockFunc30|{4, 5, 6}|{128, 64, 255, 0, 100, 50}|3.3|{4, 5}|{{0.6, 0.2, 1.5, 0.9}, {1.2, 0.4, 0.7, 0.8}, {0.5, 0.1, 1.7, 0.4}, {0.8, 0.6, 1.2, 1.3}}|10|{3, 3, 4, 4}|3.14159";
            const auto result = cross_call_worker::CallFunc30(&MockFunc30);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc31", [](SimpleTests::Test& test) {
            const plg::string expected = "{1, 2, 3}|D|54321|{18446744073709551615, 18446744073709551614, 18446744073709551613}|{5, 6, 7, 8}|Updated MockFunc31|false|987654321|{6, 7}|9|500|{5, 10}|{{1, 0.2, 1.1, 0.4}, {1.1, 0.8, 0.3, 0.9}, {0.5, 0.7, 1.8, 0.6}, {0.3, 0.6, 1.4, 0.8}}|{10, 20, 30}|8.8|{0.2, 0.4, 0.6}";
            const auto result = cross_call_worker::CallFunc31(&MockFunc31);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc32", [](SimpleTests::Test& test) {
            const plg::string expected = "100|512|{5, 10}|{8, 9, 10, 11}|0xdeadbeafdeadbeaf|{400, 500}|{{0.5, 0.3, 0.2, 0.1}, {0.8, 0.9, 0.4, 0.6}, {0.1, 0.7, 1, 0.5}, {0.4, 0.2, 0.3, 1.2}}|987654321|Updated MockFunc32|2000|{5.5, 6.5}|{6, 7, 8, 9}|true|{1, 2, 3}|15|{120, 121, 122}";
            const auto result = cross_call_worker::CallFunc32(&MockFunc32);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFunc33", [](SimpleTests::Test& test) {
            const plg::string expected = "Updated MockFunc33";
            const auto result = cross_call_worker::CallFunc33(&MockFunc33);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
        _tests.Add("CallFuncEnum", [](SimpleTests::Test& test) {
            const plg::string expected = "{4, 1}|{4, 3, 2}";
            const auto result = cross_call_worker::CallFuncEnum(&MockFuncEnum);
            if (result != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", result, expected));
            }
        });
#endif// TEST_CASES & TEST_PARAMS_FUNCTIONS
	}

	void ReverseNoParamOnlyReturn() {
#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES
		_tests.Add("ReverseNoParamReturnVoid", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::ReverseCall("NoParamReturnVoid");
		});
		_tests.Add("ReverseNoParamReturnBool", [&](SimpleTests::Test& test) {
			const plg::string expected = "true";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnBool");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnChar8", [&](SimpleTests::Test& test) {
			const plg::string expected = "P";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnChar8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnChar16", [&](SimpleTests::Test& test) {
			const plg::string expected = "1060"; // Ф
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnChar16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt8", [&](SimpleTests::Test& test) {
			const plg::string expected = "123";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt16", [&](SimpleTests::Test& test) {
			const plg::string expected = "32765";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt32", [&](SimpleTests::Test& test) {
			const plg::string expected = "2112211221";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt64", [&](SimpleTests::Test& test) {
			const plg::string expected = "8526495038839145831";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt8", [&](SimpleTests::Test& test) {
			const plg::string expected = "205";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt16", [&](SimpleTests::Test& test) {
			const plg::string expected = "52685";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt32", [&](SimpleTests::Test& test) {
			const plg::string expected = "3452816845";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt64", [&](SimpleTests::Test& test) {
			const plg::string expected = "14829735431805717965";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnPointer", [&](SimpleTests::Test& test) {
			const plg::string expected = "0xaabbccdd87655678";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnPointer");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnFloat", [&](SimpleTests::Test& test) {
			const plg::string expected = "0.123";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnFloat");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnDouble", [&](SimpleTests::Test& test) {
			const plg::string expected = "987.321";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnDouble");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS
		_tests.Add("ReverseNoParamReturnFunction", [&](SimpleTests::Test& test) {
			const plg::string expected = "365";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnFunction");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnString", [&](SimpleTests::Test& test) {
			const plg::string expected = "Convertiplane";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnString");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS
		_tests.Add("ReverseNoParamReturnArrayBool", [&](SimpleTests::Test& test) {
			const plg::string expected = "{false, true, true}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayBool");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayChar8", [&](SimpleTests::Test& test) {
			const plg::string expected = "{p, l, u, g}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayChar8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}

		});
		_tests.Add("ReverseNoParamReturnArrayChar16", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1095, 1072, 1088, 33}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayChar16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt8", [&](SimpleTests::Test& test) {
			const plg::string expected = "{10, -15, 20}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt16", [&](SimpleTests::Test& test) {
			const plg::string expected = "{10, -15, 20, -25}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt32", [&](SimpleTests::Test& test) {
			const plg::string expected = "{10, -15, 20, -25, 30}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt64", [&](SimpleTests::Test& test) {
			const plg::string expected = "{10, -15, 20, -25, 30, -35}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt8", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1, 2, 3, 200}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt16", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1, 2, 3, 200, 60000}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt32", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1, 2, 3, 200, 60000, 4000000000}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt64", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1, 2, 3, 200, 60000, 4000000000, 12223334445556667778}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayPointer", [&](SimpleTests::Test& test) {
			const plg::string expected = "{0x0, 0xdeadbeaf, 0xcdccddcccdddcccc}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayPointer");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayFloat", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1.1, -10.82, 555.555}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayFloat");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayDouble", [&](SimpleTests::Test& test) {
			const plg::string expected = "{1.1, -10.82, 555.555, 55555.55555, 123456789.98765}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayDouble");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayString", [&](SimpleTests::Test& test) {
			const plg::string expected = "{'5', 'true', '0.0', 'Hello', 'And Goodbay', 'Another long string to test. Pi equal 3,1415926535 8979323846 2643383279 5028841971 6939937510'}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayString");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS
		_tests.Add("ReverseNoParamReturnVector2", [&](SimpleTests::Test& test) {
			const plg::string expected = "{100.9, 200.8}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnVector2");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnVector3", [&](SimpleTests::Test& test) {
			const plg::string expected = "{100.9, 200.8, 300.7}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnVector3");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnVector4", [&](SimpleTests::Test& test) {
			const plg::string expected = "{100.9, 200.8, 300.7, 400.6}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnVector4");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnMatrix4x4", [&](SimpleTests::Test& test) {
			const plg::string expected = "{{1.1, 2.2, 3.3, 4.4}, {9.9, 1.1, 2.2, 3.3}, {8.8, 9.9, 1.1, 2.2}, {7.7, 8.8, 9.9, 1.1}}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnMatrix4x4");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS
	}

	void ReverseParamsNoRefs() {
#if TEST_CASES & TEST_REVERSE_PARAMS_NO_REFS
		_tests.Add("ReverseParam1", [&](SimpleTests::Test& test) {
			const plg::string expected = "999";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param1");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam2", [&](SimpleTests::Test& test) {
			const plg::string expected = "888|9.9";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param2");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam3", [&](SimpleTests::Test& test) {
			const plg::string expected = "777|8.8|9.8765";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param3");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam4", [&](SimpleTests::Test& test) {
			const plg::string expected = "666|7.7|8.7659|{100.1, 200.2, 300.3, 400.4}";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param4");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam5", [&](SimpleTests::Test& test) {
			const plg::string expected = "555|6.6|7.6598|{-105.1, -205.2, -305.3, -405.4}|{}";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param5");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam6", [&](SimpleTests::Test& test) {
			const plg::string expected = "444|5.5|6.5987|{110.1, 210.2, 310.3, 410.4}|{90000, -100, 20000}|65";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param6");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam7", [&](SimpleTests::Test& test) {
			const plg::string expected = "333|4.4|5.9876|{-115.1, -215.2, -315.3, -415.4}|{800000, 30000, -4000000}|66|red gold";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param7");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam8", [&](SimpleTests::Test& test) {
			const plg::string expected = "222|3.3|1.2345|{120.1, 220.2, 320.3, 420.4}|{7000000, 5000000, -600000000}|67|blue ice|90";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param8");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam9", [&](SimpleTests::Test& test) {
			const plg::string expected = "111|2.2|5.1234|{-125.1, -225.2, -325.3, -425.4}|{60000000, -700000000, 80000000000}|68|pink metal|89|-100";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param9");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam10", [&](SimpleTests::Test& test) {
			const plg::string expected = "1234|1.1|4.5123|{130.1, 230.2, 330.3, 430.4}|{500000000, 90000000000, 1000000000000}|69|green wood|88|-200|0xabeba";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param10");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_NO_REFS
	}

	void ReverseParamsWithRefs() {
#if TEST_CASES & TEST_REVERSE_PARAMS_WITH_REFS
		_tests.Add("ReverseParamRef1", [&](SimpleTests::Test& test) {
			const plg::string expected = "147";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef1");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef2", [&](SimpleTests::Test& test) {
			const plg::string expected = "852|0.1";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef2");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef3", [&](SimpleTests::Test& test) {
			const plg::string expected = "369|0.2|11111.11111";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef3");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef4", [&](SimpleTests::Test& test) {
			const plg::string expected = "987|0.3|22222.22222|{4.4, 3.3, 2.2, 1.1}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef4");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef5", [&](SimpleTests::Test& test) {
			const plg::string expected = "456|0.4|33333.33333|{1.4, 4.3, 3.2, 2.1}|{}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef5");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef6", [&](SimpleTests::Test& test) {
			const plg::string expected = "321|0.5|44444.44444|{1.1, 4.4, 3.3, 2.2}|{99}|122";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef6");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef7", [&](SimpleTests::Test& test) {
			const plg::string expected = "157|0.6|55555.55555|{2.1, 1.4, 4.3, 3.2}|{99, 8888}|121|my string";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef7");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef8", [&](SimpleTests::Test& test) {
			const plg::string expected = "759|0.7|66666.66666|{2.2, 1.1, 4.4, 3.3}|{99, 8888, 777777}|120|his string|1098";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef8");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef9", [&](SimpleTests::Test& test) {
			const plg::string expected = "953|0.8|77777.77777|{3.2, 2.1, 1.4, 4.3}|{99, 8888, 777777, 66666666}|119|her string|1099|-30003";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef9");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef10", [&](SimpleTests::Test& test) {
			const plg::string expected = "351|0.9|88888.88888|{3.3, 2.2, 1.1, 4.4}|{99, 8888, 777777, 66666666, 5555555555}|118|they string|1100|30003|0xabcdef";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef10");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_WITH_REFS
	}

	void ReverseParamsRefVectors() {
#if TEST_CASES & TEST_REVERSE_PARAMS_REF_ARRAYS
		_tests.Add("ReverseParamRefArrays", [&](SimpleTests::Test& test) {
			const plg::string expected = "{true, false}|{^}|{1103, 1094}|{-4, -3, -2, -1}|{-555, -444, -333}|{-66666, -77777}|{-7666555444}|"
				"{0, 1, 1, 2, 3, 5}|{32999}|{3000000000, 1}|{1, 22, 333, 4444, 55555, 999999999999}|{0xd, 0x9, 0x5, 0x1}|"
				"{91.23, 12.34, 23.45, 8.08}|{777.777777}|{'one', '1 two', '1 2 three'}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRefArrays");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_REF_ARRAYS
	}

	void ReverseParamsAllPrimitives() {
#if TEST_CASES & TEST_REVERSE_PARAMS_ALL_PRIMITIVES
		_tests.Add("ReverseParamAllPrimitives", [&](SimpleTests::Test& test) {
			const plg::string returnExpected = "65";
			const plg::string paramsExpected = "true|37|9762|-1|-1000|-1000000|-1000000000000|200|50000|3000000000|9999999999|0xfedcbaabcdef|0.001|987654.456789";
			_reverseReturn.reset();
			_reverseParams.reset();
			cross_call_worker::ReverseCall("ParamAllPrimitives");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != returnExpected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, returnExpected));
			}
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != paramsExpected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, paramsExpected));
			}
		});
        _tests.Add("ReverseParamEnum", [&](SimpleTests::Test& test) {
			const plg::string returnExpected = "10";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamEnum");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != returnExpected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, returnExpected));
			}
		});
        _tests.Add("ReverseParamRefEnum", [&](SimpleTests::Test& test) {
			const plg::string returnExpected = "5|1|{1, 1, 2}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamEnumRef");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != returnExpected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, returnExpected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_ALL_PRIMITIVES
	}

	void ReverseParamsVariants() {
#if TEST_CASES & TEST_REVERSE_PARAMS_VARIANTS
		_tests.Add("ReverseParamVariant", [&](SimpleTests::Test&) {
            cross_call_worker::ReverseCall("ParamVariant");
		});
        _tests.Add("ReverseParamVariantRef", [&](SimpleTests::Test& test) {
            const plg::string paramsExpected = "{1, 2, 3}|{true, 3.14, some really long string for avoid SSO optimization}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("ParamVariantRef");
            if (!_reverseReturn) {
                test.Fail("Params not set");
            } else if (*_reverseReturn != paramsExpected) {
                test.Fail(std::format("Wrong param values {}, expected {}", *_reverseReturn, paramsExpected));
            }
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_VARIANTS
	}

	void ReverseParamsFunctions() {
#if TEST_CASES & TEST_REVERSE_PARAMS_FUNCTIONS
        _tests.Add("ReverseCallFuncVoid", [](SimpleTests::Test&) {
            cross_call_worker::ReverseCall("CallFuncVoid");
        });
        _tests.Add("ReverseCallFuncBool", [&](SimpleTests::Test& test) {
            const plg::string expected = "true"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncBool");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncChar8", [&](SimpleTests::Test& test) {
            const plg::string expected = "65"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncChar8");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncChar16", [&](SimpleTests::Test& test) {
            const plg::string expected = "90"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncChar16");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt8", [&](SimpleTests::Test& test) {
            const plg::string expected = "10"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt8");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt16", [&](SimpleTests::Test& test) {
            const plg::string expected = "100"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt16");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt32", [&](SimpleTests::Test& test) {
            const plg::string expected = "1000"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt32");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt64", [&](SimpleTests::Test& test) {
            const plg::string expected = "10000"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt64");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt8", [&](SimpleTests::Test& test) {
            const plg::string expected = "20"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt8");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt16", [&](SimpleTests::Test& test) {
            const plg::string expected = "200"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt16");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt32", [&](SimpleTests::Test& test) {
            const plg::string expected = "2000"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt32");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt64", [&](SimpleTests::Test& test) {
            const plg::string expected = "20000"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt64");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncPtr", [&](SimpleTests::Test& test) {
            const plg::string expected = "0x0"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncPtr");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncFloat", [&](SimpleTests::Test& test) {
            const plg::string expected = "3.14"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncFloat");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncDouble", [&](SimpleTests::Test& test) {
            const plg::string expected = "6.28"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncDouble");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncString", [&](SimpleTests::Test& test) {
            const plg::string expected = "Test string"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncString");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncAny", [&](SimpleTests::Test& test) {
            const plg::string expected = "A";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncAny");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        /*_tests.Add("ReverseCallFuncFunction", [&](SimpleTests::Test& test) {
            const plg::string expected = "0x0"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncFunction");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });*/
        _tests.Add("ReverseCallFuncBoolVector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{true, false}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncBoolVector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncChar8Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{A, B}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncChar8Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncChar16Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{65, 66}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncChar16Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt8Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{10, 20}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt8Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt16Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{100, 200}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt16Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt32Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1000, 2000}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt32Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncInt64Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{10000, 20000}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncInt64Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt8Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{20, 30}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt8Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt16Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{200, 300}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt16Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt32Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{2000, 3000}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt32Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncUInt64Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{20000, 30000}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncUInt64Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncPtrVector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{0x0, 0x1}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncPtrVector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncFloatVector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1.1, 2.2}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncFloatVector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncDoubleVector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{3.3, 4.4}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncDoubleVector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncStringVector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{'Hello', 'World'}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncStringVector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncAnyVector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{Hello, 3.14, 6.28, 1, 3735928495}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncAnyVector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncVec2Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{0.5, -1.2}, {3.4, 7.8}, {-6.7, 2.3}, {8.9, -4.5}, {0, 0}}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncVec2Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncVec3Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{2.1, 3.2, 4.3}, {-5.4, 6.5, -7.6}, {8.7, 9.8, 0.1}, {1.2, -3.3, 4.4}, {-5.5, 6.6, -7.7}}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncVec3Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncVec4Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{0.1, 1.2, 2.3, 3.4}, {-4.5, 5.6, 6.7, -7.8}, {8.9, -9, 10.1, -11.2}, {12.3, 13.4, 14.5, 15.6}, {-16.7, 17.8, 18.9, -19}}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncVec4Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncMat4x4Vector", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}, {{0.5, 1, 1.5, 2}, {2.5, 3, 3.5, 4}, {4.5, 5, 5.5, 6}, {6.5, 7, 7.5, 8}}, {{-1, -2, -3, -4}, {-5, -6, -7, -8}, {-9, -10, -11, -12}, {-13, -14, -15, -16}}, {{1.1, 2.2, 3.3, 4.4}, {5.5, 6.6, 7.7, 8.8}, {9.9, 10, 11.1, 12.2}, {13.3, 14.4, 15.5, 16.6}}}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncMat4x4Vector");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncVec2", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1, 2}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncVec2");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncVec3", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1, 2, 3}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncVec3");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncVec4", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1, 2, 3, 4}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncVec4");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncMat4x4", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}"; // Adjust this if needed
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncMat4x4");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });

        _tests.Add("ReverseCallFunc1", [&](SimpleTests::Test& test) {
            const plg::string expected = "6";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc1");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc2", [&](SimpleTests::Test& test) {
            const plg::string expected = "&";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc2");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc3", [](SimpleTests::Test&) {
            cross_call_worker::ReverseCall("CallFunc3");
        });
        _tests.Add("ReverseCallFunc4", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1, 2, 3, 4}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc4");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc5", [&](SimpleTests::Test& test) {
            const plg::string expected = "true";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc5");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc6", [&](SimpleTests::Test& test) {
            const plg::string expected = "11";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc6");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc7", [&](SimpleTests::Test& test) {
            const plg::string expected = "3.14";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc7");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc8", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc8");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc9", [](SimpleTests::Test&) {
            cross_call_worker::ReverseCall("CallFunc9");
        });
        _tests.Add("ReverseCallFunc10", [&](SimpleTests::Test& test) {
            const plg::string expected = "42";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc10");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc11", [&](SimpleTests::Test& test) {
            const plg::string expected = "0x0";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc11");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc12", [&](SimpleTests::Test& test) {
            const plg::string expected = "false";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc12");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc13", [&](SimpleTests::Test& test) {
            const plg::string expected = "Dummy String";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc13");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc14", [&](SimpleTests::Test& test) {
            const plg::string expected = "{'String1', 'String2'}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc14");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc15", [&](SimpleTests::Test& test) {
            const plg::string expected = "257";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc15");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc16", [&](SimpleTests::Test& test) {
            const plg::string expected = "0x0";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc16");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc17", [&](SimpleTests::Test& test) {
            const plg::string expected = "30";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc17");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc18", [&](SimpleTests::Test& test) {
            const plg::string expected = "{5, 10}|5|10";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc18");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc19", [&](SimpleTests::Test& test) {
            const plg::string expected = "42|{1, 2, 3}|{1, 2, 3}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc19");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc20", [&](SimpleTests::Test& test) {
            const plg::string expected = "0|116|{1, 2, 3, 4}|{100, 200}|F";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc20");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc21", [&](SimpleTests::Test& test) {
            const plg::string expected = "0|{{1.3, 0.6, 0.8, 0.5}, {0.7, 1.1, 0.2, 0.4}, {0.9, 0.3, 1.2, 0.7}, {0.2, 0.8, 0.5, 1}}|{1, 2, 3}|{1, 2}|true|3.14";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc21");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc22", [&](SimpleTests::Test& test) {
            const plg::string expected = "0|0x0|99|{1.1, 2.2, 3.3}|123|Hello|{1, 2, 3, 4}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc22");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc23", [&](SimpleTests::Test& test) {
            const plg::string expected = "50|{3, 4}|{1, 2, 3, 4}|8548|1.5|-1|{1, 2, 3}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc23");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc24", [&](SimpleTests::Test& test) {
            const plg::string expected = "{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}|{a, b, c}|64|{5, 6, 7}|{1, 2, 3, 4}|4294967295|{0x0}|2.71|{0x1, 0x1, 0x2, 0x2}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc24");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc25", [&](SimpleTests::Test& test) {
            const plg::string expected = "0|100|{0x0}|false|250|MockFunc25|{1, 2, 3}|1337|{4, 5, 6, 7}|64222";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc25");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc26", [&](SimpleTests::Test& test) {
            const plg::string expected = "A|90|{2, 3}|{{0.9, 0.2, 0.4, 0.8}, {0.1, 1, 0.6, 0.3}, {0.7, 0.5, 0.2, 0.9}, {0.3, 0.4, 1.5, 0.1}}|{1.1, 2.2}|64|32|{100, 200}|0xdeadbeafdeadbeaf|true";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc26");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc27", [&](SimpleTests::Test& test) {
            const plg::string expected = "0|1|{-1, -2, -3}|0xdeadbeafdeadbeaf|{-111, 111}|{1, 2, 3, 4}|{{1, 0.5, 0.3, 0.7}, {0.8, 1.2, 0.6, 0.9}, {1.5, 1.1, 0.4, 0.2}, {0.3, 0.9, 0.7, 1}}|true|{1, 2, 3, 4}|111|30";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc27");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc28", [&](SimpleTests::Test& test) {
            const plg::string expected = "MockFunc28|0x0|65500|{1, 2, 3, 4, 5, 7}|{{1.4, 0.7, 0.2, 0.5}, {0.3, 1.1, 0.6, 0.8}, {0.9, 0.4, 1.3, 0.1}, {0.6, 0.2, 0.7, 1}}|5.5|{1, 2, 3, 4}|MockFunc28|{1, 2}|834748377834|true|{10, 20, 30}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc28");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc29", [&](SimpleTests::Test& test) {
            const plg::string expected = "{'Example', 'MockFunc29'}|{1, 2, 3, 4}|30|{127, 126, 125}|3.14|true|8|{100, 200}|1.5|MockFunc29|{{0.4, 1, 0.6, 0.3}, {1.2, 0.8, 0.5, 0.9}, {0.7, 0.3, 1.4, 0.6}, {0.1, 0.9, 0.8, 1.3}}|64";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc29");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc30", [&](SimpleTests::Test& test) {
            const plg::string expected = "42|0x0|{1, 2, 3, 4}|1000|{100, 200}|false|MockFunc30|{1, 2, 3}|{255, 0, 255, 200, 100, 200}|1.1|{3, 4}|{{0.5, 0.3, 1, 0.7}, {1.1, 0.9, 0.6, 0.4}, {0.2, 0.8, 1.5, 0.3}, {0.7, 0.4, 0.9, 1}}|8|{1, 1, 2, 2}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc30");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc31", [&](SimpleTests::Test& test) {
            const plg::string expected = "C|12345|{1, 2, 3, 4, 5}|{1, 2, 3, 4}|MockFunc31|true|123456789|{5, 6}|7|255|{1, 2}|{{0.8, 0.5, 1.2, 0.3}, {1, 0.7, 0.4, 0.6}, {0.9, 0.2, 0.5, 1.4}, {0.6, 0.8, 1.1, 0.7}}|{1, 2, 3}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc31");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc32", [&](SimpleTests::Test& test) {
            const plg::string expected = "42|255|{0, 1}|{4, 5, 6, 7}|0x0|{100, 200}|{{1, 0.4, 0.3, 0.9}, {0.7, 1.2, 0.5, 0.8}, {0.2, 0.6, 1.1, 0.4}, {0.9, 0.3, 0.8, 1.5}}|123456789|MockFunc32|1000|{2.5, 3.5}|{1, 2, 3, 4, 5, 9}|false|{0, 0, 0}|8|{97, 98, 99}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc32");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFunc33", [&](SimpleTests::Test& test) {
            const plg::string expected = "MockFunc33";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFunc33");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });
        _tests.Add("ReverseCallFuncEnum", [&](SimpleTests::Test& test) {
            const plg::string expected = "{1, 4}|{1, 2, 3}";
            _reverseReturn.reset();
            cross_call_worker::ReverseCall("CallFuncEnum");
            if (!_reverseReturn) {
                test.Fail("Params return not set");
            } else if (*_reverseReturn != expected) {
                test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
            }
        });

#endif// TEST_CASES & TEST_REVERSE_PARAMS_FUNCTIONS
	}

public:
	void ReverseReturn(const plg::string& returnString) {
		_reverseReturn = {returnString};
	}
	void ReverseParams(const plg::string& paramsString) {
		_reverseParams = {paramsString};
	}

private:
	SimpleTests _tests;
	std::optional<plg::string> _reverseReturn;
	std::optional<plg::string> _reverseParams;
};

CrossCallMaster g_plugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_plugin)

PLUGIFY_WARN_PUSH()

#if defined(__clang)
PLUGIFY_WARN_IGNORE("-Wreturn-type-c-linkage")
#elif defined(_MSC_VER)
PLUGIFY_WARN_IGNORE(4190)
#endif

extern "C"
PLUGIN_API void ReverseReturn(const plg::string& returnString) {
	g_plugin.ReverseReturn(returnString);
}

extern "C"
PLUGIN_API void NoParamReturnVoidCallback() {
}

extern "C"
PLUGIN_API bool NoParamReturnBoolCallback() {
	return true;
}

extern "C"
PLUGIN_API char NoParamReturnChar8Callback() {
	return 'P';
}

extern "C"
PLUGIN_API char16_t NoParamReturnChar16Callback() {
	return u'Ф';
}

extern "C"
PLUGIN_API int8_t NoParamReturnInt8Callback() {
	return 123;
}

extern "C"
PLUGIN_API int16_t NoParamReturnInt16Callback() {
	return 32765;
}

extern "C"
PLUGIN_API int32_t NoParamReturnInt32Callback() {
	return 2112211221;
}

extern "C"
PLUGIN_API int64_t NoParamReturnInt64Callback() {
	return 0x7654321001234567;
}

extern "C"
PLUGIN_API uint8_t NoParamReturnUInt8Callback() {
	return 0xCD;
}

extern "C"
PLUGIN_API uint16_t NoParamReturnUInt16Callback() {
	return 0xCDCD;
}

extern "C"
PLUGIN_API uint32_t NoParamReturnUInt32Callback() {
	return 0xCDCDCDCD;
}

extern "C"
PLUGIN_API uint64_t NoParamReturnUInt64Callback() {
	return 0xCDCDCDCDCDCDCDCD;
}

extern "C"
PLUGIN_API void* NoParamReturnPointerCallback() {
	return reinterpret_cast<void*>(0xAABBCCDD87655678);
}

extern "C"
PLUGIN_API float NoParamReturnFloatCallback() {
	return 0.123f;
}

extern "C"
PLUGIN_API double NoParamReturnDoubleCallback() {
	return 987.321;
}

using NoParamReturnFunctionCallbackFunc = int32_t (*)();

int32_t DaysInYear() {
	return 365;
}

extern "C"
PLUGIN_API NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
	return &DaysInYear;
}

extern "C"
PLUGIN_API plg::string NoParamReturnStringCallback() {
	return "Convertiplane";
}

extern "C"
PLUGIN_API plg::any NoParamReturnAnyCallback() {
    plg::any result{"any"};
    return result;
}

extern "C"
PLUGIN_API plg::vector<bool> NoParamReturnArrayBoolCallback() {
	return {false, true, true};
}

extern "C"
PLUGIN_API plg::vector<char> NoParamReturnArrayChar8Callback() {
	return {'p', 'l', 'u', 'g'};
}

extern "C"
PLUGIN_API plg::vector<char16_t> NoParamReturnArrayChar16Callback() {
	return {u'ч', u'а', u'р', u'!'};
}

extern "C"
PLUGIN_API plg::vector<int8_t> NoParamReturnArrayInt8Callback() {
	return {10, -15, 20};
}

extern "C"
PLUGIN_API plg::vector<int16_t> NoParamReturnArrayInt16Callback() {
	return {10, -15, 20, -25};
}

extern "C"
PLUGIN_API plg::vector<int32_t> NoParamReturnArrayInt32Callback() {
	return {10, -15, 20, -25, 30};
}

extern "C"
PLUGIN_API plg::vector<int64_t> NoParamReturnArrayInt64Callback() {
	return {10, -15, 20, -25, 30, -35};
}

extern "C"
PLUGIN_API plg::vector<uint8_t> NoParamReturnArrayUInt8Callback() {
	return  {1, 2, 3, 200};
}

extern "C"
PLUGIN_API plg::vector<uint16_t> NoParamReturnArrayUInt16Callback() {
	return {1, 2, 3, 200, 60000};
}

extern "C"
PLUGIN_API plg::vector<uint32_t> NoParamReturnArrayUInt32Callback() {
	return {1, 2, 3, 200, 60000, 4000000000};
}

extern "C"
PLUGIN_API plg::vector<uint64_t> NoParamReturnArrayUInt64Callback() {
	return {1, 2, 3, 200, 60000, 4000000000, 12223334445556667778ULL};
}

extern "C"
PLUGIN_API plg::vector<void*> NoParamReturnArrayPointerCallback() {
	return {reinterpret_cast<void*>(0x0), reinterpret_cast<void*>(0xdeadbeafLL), reinterpret_cast<void*>(0xcdccddcccdddcccc)};
}

extern "C"
PLUGIN_API plg::vector<float> NoParamReturnArrayFloatCallback() {
	return {1.1f, -10.82f, 555.555f};
}

extern "C"
PLUGIN_API plg::vector<double> NoParamReturnArrayDoubleCallback() {
	return {1.1, -10.82, 555.555, 55555.55555, 123456789.98765};
}

extern "C"
PLUGIN_API plg::vector<plg::string> NoParamReturnArrayStringCallback() {
	return {"5", "true", "0.0", "Hello", "And Goodbay", "Another long string to test. Pi equal 3,1415926535 8979323846 2643383279 5028841971 6939937510"};
}

extern "C"
PLUGIN_API plg::vector<plg::any> NoParamReturnArrayAnyCallback() {
    plg::vector<plg::any> result{5, true, 0.0, "Hello", nullptr, "Short string to test.", 3.1415926535f, 8979323846, 2643383279, 5028841971, 6939937510, plg::vector<int>{1, 2, 3, 4, 5}};
    return result;
}

extern "C"
PLUGIN_API plg::vector<plg::vec2> NoParamReturnArrayVector2Callback() {
    return {
        {1.0f, 2.0f},
        {3.0f, 4.5f},
        {5.1f, -1.2f},
        {0.0f, 0.0f},
        {8.7f, 3.3f}
    };
}

extern "C"
PLUGIN_API plg::vector<plg::vec3> NoParamReturnArrayVector3Callback() {
    return {
        {1.0f, 2.0f, 3.0f},
        {4.5f, 5.5f, 6.5f},
        {7.1f, -1.2f, 8.3f},
        {0.0f, 0.0f, 0.0f},
        {9.8f, 3.3f, 1.2f}
    };
}

extern "C"
PLUGIN_API plg::vector<plg::vec4> NoParamReturnArrayVector4Callback() {
    return {
        {1.0f, 2.0f, 3.0f, 4.0f},
        {4.5f, 5.5f, 6.5f, 7.5f},
        {7.1f, -1.2f, 8.3f, 9.4f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {9.8f, 3.3f, 1.2f, -2.2f}
    };
}

extern "C"
PLUGIN_API plg::vector<plg::mat4x4> NoParamReturnArrayMatrix4x4Callback() {
    return {
            // Identity matrix
            {
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
            },
            // Random matrix #1
            {
                1.5f, 2.0f, 3.0f, 4.0f,
                5.0f, 6.5f, 7.0f, 8.0f,
                9.0f, 10.5f, 11.0f, 12.0f,
                13.0f, 14.5f, 15.0f, 16.0f
            },
            // Random matrix #2
            {
                0.0f, -1.0f, -2.0f, -3.0f,
                4.0f, 0.0f, -5.0f, -6.0f,
                7.0f, 8.0f, 0.0f, -9.0f,
                10.0f, 11.0f, 12.0f, 0.0f
            }
    };
}

extern "C"
PLUGIN_API plg::vec2 NoParamReturnVector2Callback() {
	return {100.9f, 200.8f};
}

extern "C"
PLUGIN_API plg::vec3 NoParamReturnVector3Callback() {
	return {100.9f, 200.8f, 300.7f};
}

extern "C"
PLUGIN_API plg::vec4 NoParamReturnVector4Callback() {
	return {100.9f, 200.8f, 300.7f, 400.6f};
}

extern "C"
PLUGIN_API plg::mat4x4 NoParamReturnMatrix4x4Callback() {
	return {1.1f, 2.2f, 3.3f, 4.4f, 9.9f, 1.1f, 2.2f, 3.3f, 8.8f, 9.9f, 1.1f, 2.2f, 7.7f, 8.8f, 9.9f, 1.1f};
}

extern "C"
PLUGIN_API void Param1Callback(int32_t a) {
	g_plugin.ReverseParams(std::format("{}", a));
}

extern "C"
PLUGIN_API void Param2Callback(int32_t a, float b) {
	g_plugin.ReverseParams(std::format("{}|{}", a, b));
}

extern "C"
PLUGIN_API void Param3Callback(int32_t a, float b, double c) {
	g_plugin.ReverseParams(std::format("{}|{}|{}", a, b, c));
}

extern "C"
PLUGIN_API void Param4Callback(int32_t a, float b, double c, const plg::vec4& d) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}", a, b, c, d));
}

extern "C"
PLUGIN_API void Param5Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}", a, b, c, d, e));
}

extern "C"
PLUGIN_API void Param6Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}", a, b, c, d, e, static_cast<uint8_t>(f)));
}

extern "C"
PLUGIN_API void Param7Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e, static_cast<uint8_t>(f), g));
}

extern "C"
PLUGIN_API void Param8Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h)));
}

extern "C"
PLUGIN_API void Param9Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k));
}

extern "C"
PLUGIN_API void Param10Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k, l));
}

extern "C"
PLUGIN_API void ParamRef1Callback(int32_t& a) {
	a = 147;
}

extern "C"
PLUGIN_API void ParamRef2Callback(int32_t& a, float& b) {
	a = 852;
	b = 0.1f;
}

extern "C"
PLUGIN_API void ParamRef3Callback(int32_t& a, float& b, double& c) {
	a = 369;
	b = 0.2f;
	c = 11111.11111;
}

extern "C"
PLUGIN_API void ParamRef4Callback(int32_t& a, float& b, double& c, plg::vec4& d) {
	a = 987;
	b = 0.3f;
	c = 22222.22222;
	d = {4.4f, 3.3f, 2.2f, 1.1f};
}

extern "C"
PLUGIN_API void ParamRef5Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e) {
	a = 456;
	b = 0.4f;
	c = 33333.33333;
	d = {1.4f, 4.3f, 3.2f, 2.1f};
	e = {};
}

extern "C"
PLUGIN_API void ParamRef6Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f) {
	a = 321;
	b = 0.5f;
	c = 44444.44444;
	d = {1.1f, 4.4f, 3.3f, 2.2f};
	e = {99};
	f = 'z';
}

extern "C"
PLUGIN_API void ParamRef7Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g) {
	a = 157;
	b = 0.6f;
	c = 55555.55555;
	d = {2.1f, 1.4f, 4.3f, 3.2f};
	e = {99, 8888};
	f = 'y';
	g = "my string";
}

extern "C"
PLUGIN_API void ParamRef8Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
	a = 759;
	b = 0.7f;
	c = 66666.66666;
	d = {2.2f, 1.1f, 4.4f, 3.3f};
	e = {99, 8888, 777777};
	f = 'x';
	g = "his string";
	h = u'ъ';
}

extern "C"
PLUGIN_API void ParamRef9Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
	a = 953;
	b = 0.8f;
	c = 77777.77777;
	d = {3.2f, 2.1f, 1.4f, 4.3f};
	e = {99, 8888, 777777, 66666666};
	f = 'w';
	g = "her string";
	h = u'ы';
	k = -30003;
}

extern "C"
PLUGIN_API void ParamRef10Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
	a = 351;
	b = 0.9f;
	c = 88888.88888;
	d = {3.3f, 2.2f, 1.1f, 4.4f};
	e = {99, 8888, 777777, 66666666, 5555555555};
	f = 'v';
	g = "they string";
	h = u'ь';
	k = 30003;
	l = reinterpret_cast<void*>(0xabcdefLL);
}

extern "C"
PLUGIN_API void ParamRefVectorsCallback(plg::vector<bool>& p1, plg::vector<char>& p2, plg::vector<char16_t>& p3, plg::vector<int8_t>& p4, plg::vector<int16_t>& p5,
	plg::vector<int32_t>& p6, plg::vector<int64_t>& p7, plg::vector<uint8_t>& p8, plg::vector<uint16_t>& p9, plg::vector<uint32_t>& p10, plg::vector<uint64_t>& p11,
	plg::vector<void*>& p12, plg::vector<float>& p13, plg::vector<double>& p14, plg::vector<plg::string>& p15
) {
	p1 = {true, false};
	p2 = {'^'};
	p3 = {u'я', u'ц'};
	p4 = {-4, -3, -2, -1};
	p5 = {-555, -444, -333};
	p6 = {-66666, -77777};
	p7 = {-7666555444};
	p8 = {0, 1, 1, 2, 3, 5};
	p9 = {32999};
	p10 = {3000000000, 1};
	p11 = {1, 22, 333, 4444, 55555, 999999999999};
	p12 = {reinterpret_cast<void*>(13LL), reinterpret_cast<void*>(9LL), reinterpret_cast<void*>(5LL), reinterpret_cast<void*>(1LL)};
	p13 = {91.23f, 12.34f, 23.45f, 8.08f};
	p14 = {777.777777};
	p15 = {"one", "1 two", "1 2 three"};
}

extern "C"
PLUGIN_API int64_t ParamAllPrimitivesCallback(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10,
	uint64_t p11, void* p12, float p13, double p14
) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", p1, static_cast<uint8_t>(p2), static_cast<uint16_t>(p3), p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14));
	return 65;
}

extern "C"
PLUGIN_API int32_t ParamEnumCallback(Example p1, const plg::vector<Example>& p2) {
    return static_cast<int32_t>(p1) + std::accumulate(p2.begin(), p2.end(), int32_t{0},
        [](int32_t sum, const Example& e) {
            return sum + static_cast<int32_t>(e);
        });
}

extern "C"
PLUGIN_API int32_t ParamEnumRefCallback(Example& p1, plg::vector<Example>& p2) {
    p1 = Example::First;
    p2 = plg::vector<Example>{Example::First, Example::First, Example::Second};
    return static_cast<int32_t>(p1) + std::accumulate(p2.begin(), p2.end(), int32_t{0},
        [](int32_t sum, const Example& e) {
            return sum + static_cast<int32_t>(e);
        });
}

extern "C"
PLUGIN_API void ParamVariantCallback(const plg::any& p1, const plg::vector<plg::any>& p2) {
    g_plugin.ReverseParams(std::format("{}|{}", p1, p2));
}

extern "C"
PLUGIN_API void ParamVariantRefCallback(plg::any& p1, plg::vector<plg::any>& p2) {
    p1 = plg::vector<int>{1, 2, 3};
    p2.resize(3);
    p2[0] = true;
    p2[1] = 3.14f;
    p2[2] = "some really long string for avoid SSO optimization";
}

// Call functions using the typedefs
extern "C"
PLUGIN_API void CallFuncVoidCallback(cross_call_worker::FuncVoid func) {
    func();
}

extern "C"
PLUGIN_API bool CallFuncBoolCallback(cross_call_worker::FuncBool func) {
    bool result = func();
    return result;
}

extern "C"
PLUGIN_API char CallFuncChar8Callback(cross_call_worker::FuncChar8 func) {
    char result = func();
    return result;
}

extern "C"
PLUGIN_API char16_t CallFuncChar16Callback(cross_call_worker::FuncChar16 func) {
    char16_t result = func();
    return result;
}

extern "C"
PLUGIN_API int8_t CallFuncInt8Callback(cross_call_worker::FuncInt8 func) {
    int8_t result = func();
    return result;
}

extern "C"
PLUGIN_API int16_t CallFuncInt16Callback(cross_call_worker::FuncInt16 func) {
    int16_t result = func();
    return result;
}

extern "C"
PLUGIN_API int32_t CallFuncInt32Callback(cross_call_worker::FuncInt32 func) {
    int32_t result = func();
    return result;
}

extern "C"
PLUGIN_API int64_t CallFuncInt64Callback(cross_call_worker::FuncInt64 func) {
    int64_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint8_t CallFuncUInt8Callback(cross_call_worker::FuncUInt8 func) {
    uint8_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint16_t CallFuncUInt16Callback(cross_call_worker::FuncUInt16 func) {
    uint16_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint32_t CallFuncUInt32Callback(cross_call_worker::FuncUInt32 func) {
    uint32_t result = func();
    return result;
}

extern "C"
PLUGIN_API uint64_t CallFuncUInt64Callback(cross_call_worker::FuncUInt64 func) {
    uint64_t result = func();
    return result;
}

extern "C"
PLUGIN_API void* CallFuncPtrCallback(cross_call_worker::FuncPtr func) {
    void* result = func();
    return result;
}

extern "C"
PLUGIN_API float CallFuncFloatCallback(cross_call_worker::FuncFloat func) {
    float result = func();
    return result;
}

extern "C"
PLUGIN_API double CallFuncDoubleCallback(cross_call_worker::FuncDouble func) {
    double result = func();
    return result;
}

extern "C"
PLUGIN_API void* CallFuncFunctionCallback(cross_call_worker::FuncFunction func) {
    void* result = func();
    return result;
}

extern "C"
PLUGIN_API plg::string CallFuncStringCallback(cross_call_worker::FuncString func) {
    plg::string result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::any CallFuncAnyCallback(cross_call_worker::FuncAny func) {
    plg::any result = func();
    return result;
}

// Call functions for vector return types
extern "C"
PLUGIN_API  plg::vector<bool> CallFuncBoolVectorCallback(cross_call_worker::FuncBoolVector func) {
    plg::vector<bool> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<char> CallFuncChar8VectorCallback(cross_call_worker::FuncChar8Vector func) {
    plg::vector<char> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<char16_t> CallFuncChar16VectorCallback(cross_call_worker::FuncChar16Vector func) {
    plg::vector<char16_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int8_t> CallFuncInt8VectorCallback(cross_call_worker::FuncInt8Vector func) {
    plg::vector<int8_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int16_t> CallFuncInt16VectorCallback(cross_call_worker::FuncInt16Vector func) {
    plg::vector<int16_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int32_t> CallFuncInt32VectorCallback(cross_call_worker::FuncInt32Vector func) {
    plg::vector<int32_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int64_t> CallFuncInt64VectorCallback(cross_call_worker::FuncInt64Vector func) {
    plg::vector<int64_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint8_t> CallFuncUInt8VectorCallback(cross_call_worker::FuncUInt8Vector func) {
    plg::vector<uint8_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint16_t> CallFuncUInt16VectorCallback(cross_call_worker::FuncUInt16Vector func) {
    plg::vector<uint16_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint32_t> CallFuncUInt32VectorCallback(cross_call_worker::FuncUInt32Vector func) {
    plg::vector<uint32_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint64_t> CallFuncUInt64VectorCallback(cross_call_worker::FuncUInt64Vector func) {
    plg::vector<uint64_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API  plg::vector<void*> CallFuncPtrVectorCallback(cross_call_worker::FuncPtrVector func) {
    plg::vector<void*> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<float> CallFuncFloatVectorCallback(cross_call_worker::FuncFloatVector func) {
    plg::vector<float> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<double> CallFuncDoubleVectorCallback(cross_call_worker::FuncDoubleVector func) {
    plg::vector<double> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::string> CallFuncStringVectorCallback(cross_call_worker::FuncStringVector func) {
    plg::vector<plg::string> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::any> CallFuncAnyVectorCallback(cross_call_worker::FuncAnyVector func) {
    plg::vector<plg::any> result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vector<plg::vec2> CallFuncVec2VectorCallback(cross_call_worker::FuncVec2Vector func) {
    plg::vector<plg::vec2> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::vec3> CallFuncVec3VectorCallback(cross_call_worker::FuncVec3Vector func) {
    plg::vector<plg::vec3> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::vec4> CallFuncVec4VectorCallback(cross_call_worker::FuncVec4Vector func) {
    plg::vector<plg::vec4> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::mat4x4> CallFuncMat4x4VectorCallback(cross_call_worker::FuncMat4x4Vector func) {
    plg::vector<plg::mat4x4> result = func();
    return std::move(result);
}

// Call functions for vector return types
extern "C"
PLUGIN_API plg::vec2 CallFuncVec2Callback(cross_call_worker::FuncVec2 func) {
    plg::vec2 result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vec3 CallFuncVec3Callback(cross_call_worker::FuncVec3 func) {
    plg::vec3 result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vec4 CallFuncVec4Callback(cross_call_worker::FuncVec4 func) {
    plg::vec4 result = func();
    return result;
}

extern "C"
PLUGIN_API plg::mat4x4 CallFuncMat4x4Callback(cross_call_worker::FuncMat4x4 func) {
    plg::mat4x4 result = func();
    return result;
}

// 1 parameter
extern "C"
PLUGIN_API int32_t CallFunc1Callback(cross_call_worker::Func1 func) {
    plg::vec3 vec{1.0f, 2.0f, 3.0f};
    return func(vec);
}

// 2 parameters
extern "C"
PLUGIN_API char CallFunc2Callback(cross_call_worker::Func2 func) {
    float f = 3.14f;
    int64_t i64 = 100;
    return func(f, i64);
}

// 3 parameters
extern "C"
PLUGIN_API void CallFunc3Callback(cross_call_worker::Func3 func) {
    void* ptr = nullptr; // Example pointer
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    plg::string str = "Test";
    func(ptr, vec4, str);
}

// 4 parameters
extern "C"
PLUGIN_API plg::vec4 CallFunc4Callback(cross_call_worker::Func4 func) {
    bool b = true;
    int32_t u32 = 10;
    char16_t ch16 = 'A';
    plg::mat4x4 mat{}; // Assume it's initialized properly
    return func(b, u32, ch16, mat);
}

// 5 parameters
extern "C"
PLUGIN_API bool CallFunc5Callback(cross_call_worker::Func5 func) {
    int8_t i8 = 5;
    plg::vec2 vec2{1.0f, 2.0f};
    void* ptr = nullptr; // Example pointer
    double d = 3.14;
    plg::vector<uint64_t> vec64{1, 2, 3};
    return func(i8, vec2, ptr, d, vec64);
}

// 6 parameters
extern "C"
PLUGIN_API int64_t CallFunc6Callback(cross_call_worker::Func6 func) {
    plg::string str = "Test";
    float f = 1.23f;
    plg::vector<float> vecF{1.0f, 2.0f, 3.0f};
    int16_t i16 = 10;
    plg::vector<uint8_t> vecU8{0, 1, 2};
    void* ptr = nullptr; // Example pointer
    return func(str, f, vecF, i16, vecU8, ptr);
}

// 7 parameters
extern "C"
PLUGIN_API double CallFunc7Callback(cross_call_worker::Func7 func) {
    plg::vector<char> vecC{'A', 'B', 'C'};
    uint16_t u16 = 10;
    char16_t ch16 = 'A';
    plg::vector<uint32_t> vecU32{1, 2, 3};
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    bool b = true;
    uint64_t u64 = 100;
    return func(vecC, u16, ch16, vecU32, vec4, b, u64);
}

// 8 parameters
extern "C"
PLUGIN_API plg::mat4x4 CallFunc8Callback(cross_call_worker::Func8 func) {
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    plg::vector<uint32_t> vecU32{1, 2, 3};
    int16_t i16 = 10;
    bool b = true;
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    plg::vector<char16_t> vecC16{ 'A', 'B' };
    char16_t ch16 = L'A';
    int32_t i32 = 20;
    return func(vec3, vecU32, i16, b, vec4, vecC16, ch16, i32);
}

// 9 parameters
extern "C"
PLUGIN_API void CallFunc9Callback(cross_call_worker::Func9 func) {
    float f = 1.23f;
    plg::vec2 vec2{1.0f, 2.0f};
    plg::vector<int8_t> vecI8{1, 2, 3};
    uint64_t u64 = 100;
    bool b = true;
    plg::string str = "Test";
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    int16_t i16 = 10;
    void* ptr = nullptr; // Example pointer
    func(f, vec2, vecI8, u64, b, str, vec4, i16, ptr);
}

// 10 parameters
extern "C"
PLUGIN_API uint32_t CallFunc10Callback(cross_call_worker::Func10 func) {
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vector<uint32_t> vecU32{1, 2, 3};
    uint64_t u64 = 100;
    plg::vector<char> vecC{'A', 'B', 'C'};
    int32_t i32 = 20;
    bool b = true;
    plg::vec2 vec2{1.0f, 2.0f};
    int64_t i64 = 50;
    double d = 3.14;
    return func(vec4, mat, vecU32, u64, vecC, i32, b, vec2, i64, d);
}

// 11 parameters
extern "C"
PLUGIN_API void* CallFunc11Callback(cross_call_worker::Func11 func) {
    plg::vector<bool> vecB{true, false, true};
    char16_t ch16 = 'A';
    uint8_t u8 = 5;
    double d = 3.14;
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    plg::vector<int8_t> vecI8{1, 2, 3};
    int64_t i64 = 100;
    uint16_t u16 = 10;
    float f = 1.23f;
    plg::vec2 vec2{1.0f, 2.0f};
    uint32_t u32 = 20;
    return func(vecB, ch16, u8, d, vec3, vecI8, i64, u16, f, vec2, u32);
}

// 12 parameters
extern "C"
PLUGIN_API bool CallFunc12Callback(cross_call_worker::Func12 func) {
    void* ptr = nullptr; // Example pointer
    plg::vector<double> vecD{1.0, 2.0, 3.0};
    uint32_t u32 = 10;
    double d = 3.14;
    bool b = true;
    int32_t i32 = 20;
    int8_t i8 = 5;
    uint64_t u64 = 100;
    float f = 1.23f;
    plg::vector<void*> vecPtr{nullptr, reinterpret_cast<void*>(1), reinterpret_cast<void*>(2)};
    int64_t i64 = 50;
    char ch = 'A';
    return func(ptr, vecD, u32, d, b, i32, i8, u64, f, vecPtr, i64, ch);
}

// 13 parameters
extern "C"
PLUGIN_API plg::string CallFunc13Callback(cross_call_worker::Func13 func) {
    int64_t i64 = 50;
    plg::vector<char> vecC{'A', 'B', 'C'};
    uint16_t u16 = 10;
    float f = 1.23f;
    plg::vector<bool> vecB{true, false, true};
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    plg::string str = "Test";
    int32_t i32 = 20;
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    void* ptr = nullptr; // Example pointer
    plg::vec2 vec2{1.0f, 2.0f};
    plg::vector<uint8_t> vecU8{0, 1, 2};
    int16_t i16 = 10;
    auto ret = func(i64, vecC, u16, f, vecB, vec4, str, i32, vec3, ptr, vec2, vecU8, i16);
    return std::move(ret);
}

// 14 parameters
extern "C"
PLUGIN_API plg::vector<plg::string> CallFunc14Callback(cross_call_worker::Func14 func) {
    plg::vector<char> vecC{'A', 'B', 'C'};
    plg::vector<uint32_t> vecU32{1, 2, 3};
    plg::mat4x4 mat; // Assume it's initialized properly
    bool b = true;
    char16_t ch16 = L'A';
    int32_t i32 = 20;
    plg::vector<float> vecF{1.0f, 2.0f, 3.0f};
    uint16_t u16 = 10;
    plg::vector<uint8_t> vecU8{0, 1, 2};
    int8_t i8 = 5;
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    double d = 3.14;
    void* ptr = nullptr; // Example pointer
    auto ret = func(vecC, vecU32, mat, b, ch16, i32, vecF, u16, vecU8, i8, vec3, vec4, d, ptr);
    return std::move(ret);
}

// 15 parameters
extern "C"
PLUGIN_API int16_t CallFunc15Callback(cross_call_worker::Func15 func) {
    plg::vector<int16_t> vecI16{1, 2, 3};
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    void* ptr = nullptr; // Example pointer
    uint64_t u64 = 100;
    plg::vector<uint32_t> vecU32{1, 2, 3};
    bool b = true;
    float f = 1.23f;
    plg::vector<char16_t> vecC16{'A', 'B'};
    uint8_t u8 = 5;
    int32_t i32 = 20;
    plg::vec2 vec2{1.0f, 2.0f};
    uint16_t u16 = 10;
    double d = 3.14;
    plg::vector<uint8_t> vecU8{0, 1, 2};
    return func(vecI16, mat, vec4, ptr, u64, vecU32, b, f, vecC16, u8, i32, vec2, u16, d, vecU8);
}

// 16 parameters
extern "C"
PLUGIN_API void* CallFunc16Callback(cross_call_worker::Func16 func) {
    plg::vector<bool> vecB{true, false, true};
    int16_t i16 = 10;
    plg::vector<int8_t> vecI8{1, 2, 3};
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vec2 vec2{1.0f, 2.0f};
    plg::vector<uint64_t> vecU64{1, 2, 3};
    plg::vector<char> vecC{'A', 'B', 'C'};
    plg::string str = "Test";
    int64_t i64 = 50;
    plg::vector<uint32_t> vecU32{1, 2, 3};
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    float f = 1.23f;
    double d = 3.14;
    int8_t i8 = 5;
    uint16_t u16 = 10;
    return func(vecB, i16, vecI8, vec4, mat, vec2, vecU64, vecC, str, i64, vecU32, vec3, f, d, i8, u16);
}

// Additional Functions with Refs

// 1 parameter
extern "C"
PLUGIN_API plg::string CallFunc17Callback(cross_call_worker::Func17 func) {
    int32_t i32 = 20;
    func(i32);
    return std::format("{}", i32);
}

// 2 parameters
extern "C"
PLUGIN_API plg::string CallFunc18Callback(cross_call_worker::Func18 func) {
    int8_t i8 = 5;
    int16_t i16 = 10;
    plg::vec2 ret = func(i8, i16);
    return std::format("{}|{}|{}", ret, i8, i16);
}

// 3 parameters
extern "C"
PLUGIN_API plg::string CallFunc19Callback(cross_call_worker::Func19 func) {
    uint32_t u32 = 10;
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    plg::vector<uint32_t> vecU32{1, 2, 3};
    func(u32, vec3, vecU32);
    return std::format("{}|{}|{}", u32, vec3, vecU32);
}

// 4 parameters
extern "C"
PLUGIN_API plg::string CallFunc20Callback(cross_call_worker::Func20 func) {
    char16_t ch16 = 'A';
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    plg::vector<uint64_t> vecU64{1, 2, 3};
    char ch = 'B';
    int32_t ret = func(ch16, vec4, vecU64, ch);
    return std::format("{}|{}|{}|{}|{}", ret, static_cast<uint16_t>(ch16), vec4, vecU64, ch);
}

// 5 parameters
extern "C"
PLUGIN_API plg::string CallFunc21Callback(cross_call_worker::Func21 func) {
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vector<int32_t> vecI32{1, 2, 3};
    plg::vec2 vec2{1.0f, 2.0f};
    bool b = true;
    double d = 3.14;
    float ret = func(mat, vecI32, vec2, b, d);
    return std::format("{}|{}|{}|{}|{}|{}", ret, mat, vecI32, vec2, b ? "true" : "false", d);
}

// 6 parameters
extern "C"
PLUGIN_API plg::string CallFunc22Callback(cross_call_worker::Func22 func) {
    void* ptr = nullptr; // Example pointer
    uint32_t u32 = 10;
    plg::vector<double> vecD{1.0, 2.0, 3.0};
    int16_t i16 = 10;
    plg::string str = "Test";
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    uint64_t ret = func(ptr, u32, vecD, i16, str, vec4);
    return std::format("{}|{}|{}|{}|{}|{}|{}", ret, ptr, u32, vecD, i16, str.c_str(), vec4);
}

// 7 parameters
extern "C"
PLUGIN_API plg::string CallFunc23Callback(cross_call_worker::Func23 func) {
    uint64_t u64 = 100;
    plg::vec2 vec2{1.0f, 2.0f};
    plg::vector<int16_t> vecI16{1, 2, 3};
    char16_t ch16 = 'A';
    float f = 1.23f;
    int8_t i8 = 5;
    plg::vector<uint8_t> vecU8{0, 1, 2};
    func(u64, vec2, vecI16, ch16, f, i8, vecU8);
    return std::format("{}|{}|{}|{}|{}|{}|{}", u64, vec2, vecI16, static_cast<uint16_t>(ch16), f, i8, vecU8);
}

// 8 parameters
extern "C"
PLUGIN_API plg::string CallFunc24Callback(cross_call_worker::Func24 func) {
    plg::vector<char> vecC{'A', 'B', 'C'};
    int64_t i64 = 50;
    plg::vector<uint8_t> vecU8{0, 1, 2};
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    uint64_t u64 = 100;
    plg::vector<void*> vecPtr{ nullptr, reinterpret_cast<void*>(1), reinterpret_cast<void*>(2) };
    double d = 3.14;
    plg::vector<void*> vecV2{ reinterpret_cast<void*>(1), reinterpret_cast<void*>(2), reinterpret_cast<void*>(3), reinterpret_cast<void*>(4) };
    plg::mat4x4 ret = func(vecC, i64, vecU8, vec4, u64, vecPtr, d, vecV2);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, vecC, i64, vecU8, vec4, u64, vecPtr, d, vecV2);
}

// 9 parameters
extern "C"
PLUGIN_API plg::string CallFunc25Callback(cross_call_worker::Func25 func) {
    int32_t i32 = 20;
    plg::vector<void*> vecPtr{ reinterpret_cast<void*>(1), reinterpret_cast<void*>(2), reinterpret_cast<void*>(3) };
    bool b = true;
    uint8_t u8 = 5;
    plg::string str = "Test";
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    int64_t i64 = 50;
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    uint16_t u16 = 10;
    double ret = func(i32, vecPtr, b, u8, str, vec3, i64, vec4, u16);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, i32, vecPtr, b ? "true" : "false", u8, str.c_str(), vec3, i64, vec4, u16);
}

// 10 parameters
extern "C"
PLUGIN_API plg::string CallFunc26Callback(cross_call_worker::Func26 func) {
    char16_t ch16 = 'A';
    plg::vec2 vec2{1.0f, 2.0f};
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vector<float> vecF{1.0f, 2.0f, 3.0f};
    int16_t i16 = 10;
    uint64_t u64 = 100;
    uint32_t u32 = 10;
    plg::vector<uint16_t> vecU16{1, 2, 3};
    void* ptr = nullptr; // Example pointer
    bool b = true;
    char ret = func(ch16, vec2, mat, vecF, i16, u64, u32, vecU16, ptr, b);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, static_cast<uint16_t>(ch16), vec2, mat, vecF, u64, u32, vecU16, ptr, b ? "true" : "false");
}

// 11 parameters
extern "C"
PLUGIN_API plg::string CallFunc27Callback(cross_call_worker::Func27 func) {
    float f = 1.23f;
    plg::vec3 vec3{1.0f, 2.0f, 3.0f};
    void* ptr = nullptr; // Example pointer
    plg::vec2 vec2{1.0f, 2.0f};
    plg::vector<int16_t> vecI16{1, 2, 3};
    plg::mat4x4 mat; // Assume it's initialized properly
    bool b = true;
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f};
    int8_t i8 = 5;
    int32_t i32 = 20;
    plg::vector<uint8_t> vecU8{0, 1, 2};
    uint8_t ret = func(f, vec3, ptr, vec2, vecI16, mat, b, vec4, i8, i32, vecU8);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, f, vec3, ptr, vec2, vecI16, mat, b, vec4, i8, i32, vecU8);
}

// 12 parameters
extern "C"
PLUGIN_API plg::string CallFunc28Callback(cross_call_worker::Func28 func) {
    void* ptr = nullptr; // Example pointer
    uint16_t u16 = 10; // Example value
    plg::vector<uint32_t> vecU32{1, 2, 3}; // Sample vector
    plg::mat4x4 mat; // Assume initialized properly
    float f = 3.14f; // Example float
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f}; // Example Vector4
    plg::string str = "Example string"; // Example string
    plg::vector<uint64_t> vecU64{100, 200, 300}; // Sample vector
    int64_t i64 = 123456789; // Example int64
    bool b = true; // Example boolean
    plg::vec3 vec3{1.0f, 2.0f, 3.0f}; // Example Vector3
    plg::vector<float> vecF{1.0f, 2.0f, 3.0f}; // Sample vector of floats

    plg::string ret = func(ptr, u16, vecU32, mat, f, vec4, str, vecU64, i64, b, vec3, vecF);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ptr, u16, vecU32, mat, f, vec4, str, vecU64, i64, b, vec3, vecF);
}

// 13 parameters
extern "C"
PLUGIN_API plg::string CallFunc29Callback(cross_call_worker::Func29 func) {
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f}; // Example Vector4
    int32_t i32 = 42; // Example int32
    plg::vector<int8_t> vecI8{1, 2, 3}; // Sample vector of int8
    double d = 3.14; // Example double
    bool b = true; // Example boolean
    int8_t i8 = 5; // Example int8
    plg::vector<uint16_t> vecU16{1, 2, 3}; // Sample vector of uint16
    float f = 1.23f; // Example float
    plg::string str = "Another example string"; // Example string
    plg::mat4x4 mat; // Assume initialized properly
    uint64_t u64 = 100; // Example uint64
    plg::vec3 vec3{1.0f, 2.0f, 3.0f}; // Example Vector3
    plg::vector<int64_t> vecI64{1000, 2000, 3000}; // Sample vector of int64

    plg::vector<plg::string> ret = func(vec4, i32, vecI8, d, b, i8, vecU16, f, str, mat, u64, vec3, vecI64);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, vec4, i32, vecI8, d, b ? "true" : "false", i8, vecU16, f, str, mat, u64, vec3, vecI64);
}

// 14 parameters
extern "C"
PLUGIN_API plg::string CallFunc30Callback(cross_call_worker::Func30 func) {
    void* ptr = nullptr; // Example pointer
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f}; // Example Vector4
    int64_t i64 = 123456789; // Example int64
    plg::vector<uint32_t> vecU32{1, 2, 3}; // Sample vector of uint32
    bool b = true; // Example boolean
    plg::string str = "String for Func30"; // Example string
    plg::vec3 vec3{1.0f, 2.0f, 3.0f}; // Example Vector3
    plg::vector<uint8_t> vecU8{0, 1, 2}; // Sample vector of uint8
    float f = 4.56f; // Example float
    plg::vec2 vec2{1.0f, 2.0f}; // Example Vector2
    plg::mat4x4 mat; // Assume initialized properly
    int8_t i8 = 5; // Example int8
    plg::vector<float> vecF{1.0f, 2.0f, 3.0f}; // Sample vector of floats
    double d = 7.89; // Example double

    int32_t ret = func(ptr, vec4, i64, vecU32, b, str, vec3, vecU8, f, vec2, mat, i8, vecF, d);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ptr, vec4, i64, vecU32, b ? "true" : "false", str, vec3, vecU8, f, vec2, mat, i8, vecF, d);
}

// 15 parameters
extern "C"
PLUGIN_API plg::string CallFunc31Callback(cross_call_worker::Func31 func) {
    char ch = 'A'; // Example char
    uint32_t u32 = 100; // Example uint32
    plg::vector<uint64_t> vecU64{1, 2, 3}; // Sample vector of uint64
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f}; // Example Vector4
    plg::string str = "String for Func31"; // Example string
    bool b = false; // Example boolean
    int64_t i64 = 123456789; // Example int64
    plg::vec2 vec2{1.0f, 2.0f}; // Example Vector2
    int8_t i8 = 5; // Example int8
    uint16_t u16 = 10; // Example uint16
    plg::vector<int16_t> vecI16{1, 2, 3}; // Sample vector of int16
    plg::mat4x4 mat; // Assume initialized properly
    plg::vec3 vec3{1.0f, 2.0f, 3.0f}; // Example Vector3
    float f = 4.56f; // Example float
    plg::vector<double> vecD{1.0, 2.0, 3.0}; // Sample vector of doubles

    plg::vec3 ret = func(ch, u32, vecU64, vec4, str, b, i64, vec2, i8, u16, vecI16, mat, vec3, f, vecD);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ch, u32, vecU64, vec4, str, b ? "true" : "false", i64, vec2, i8, u16, vecI16, mat, vec3, f, vecD);
}

// 16 parameters
extern "C"
PLUGIN_API plg::string CallFunc32Callback(cross_call_worker::Func32 func) {
    int32_t i32 = 20; // Example int32 reference
    uint16_t u16 = 10; // Example uint16 reference
    plg::vector<int8_t> vecI8{1, 2, 3}; // Sample vector of int8
    plg::vec4 vec4{1.0f, 2.0f, 3.0f, 4.0f}; // Example Vector4
    void* ptr = nullptr; // Example pointer reference
    plg::vector<uint32_t> vecU32{1, 2, 3}; // Sample vector of uint32
    plg::mat4x4 mat; // Assume initialized properly
    uint64_t u64 = 100; // Example uint64
    plg::string str = "String for Func32"; // Example string
    int64_t i64 = 123456789; // Example int64
    plg::vec2 vec2{1.0f, 2.0f}; // Example Vector2
    plg::vector<int8_t> vecI8_2{4, 5, 6}; // Another sample vector of int8
    bool b = true; // Example boolean
    plg::vec3 vec3{1.0f, 2.0f, 3.0f}; // Example Vector3
    uint8_t u8 = 255; // Example uint8
    plg::vector<char16_t> vecC16{u'A', u'B', u'C'}; // Sample vector of char16

    func(i32, u16, vecI8, vec4, ptr, vecU32, mat, u64, str, i64, vec2, vecI8_2, b, vec3, u8, vecC16);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", i32, u16, vecI8, vec4, ptr, vecU32, mat, u64, str, i64, vec2, vecI8_2, b ? "true" : "false", vec3, u8, vecC16);
}

// 1 parameters
extern "C"
PLUGIN_API plg::string CallFunc33Callback(cross_call_worker::Func33 func) {
    plg::any variant; // Example variant reference
    func(variant);
    return std::format("{}", variant);
}

// enum parameters
extern "C"
PLUGIN_API plg::string CallFuncEnumCallback(cross_call_worker::FuncEnum func) {
    Example p1 = Example::First;
    plg::vector<Example> p2 = {Example::Second};
    auto ret = func(p1, p2);
    return std::format("{}|{}", ret, p2);
}

PLUGIFY_WARN_POP()