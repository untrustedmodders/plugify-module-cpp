#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <plg/format.hpp>
#include <plg/plugin.hpp>
#include <plg/formatter.hpp>
#include <plugin_export.h>
#include <cross_call_master/cross_call_master.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

PLUGIFY_WARN_PUSH()

#if defined(__clang__)
PLUGIFY_WARN_IGNORE ("-Wreturn-type-c-linkage")
#elif defined(_MSC_VER)
PLUGIFY_WARN_IGNORE(4190)
#endif

using Example = cross_call_master::Example;

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
        auto format(const Example &e, FormatContext &ctx) const {
            return std::format_to(ctx.out(), "{}", static_cast<int>(e));
        }
    };
}

class CrossCallWorker final : public plg::IPluginEntry {
};

CrossCallWorker g_plugin;
EXPOSE_PLUGIN(PLUGIN_API, CrossCallWorker, &g_plugin)

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
PLUGIN_API void *NoParamReturnPointer() {
    return reinterpret_cast<void *>(0x1);
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
PLUGIN_API plg::string NoParamReturnString() {
    return "Hello World";
}

extern "C"
PLUGIN_API plg::any NoParamReturnAny() {
    return plg::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

extern "C"
PLUGIN_API plg::vector<bool> NoParamReturnArrayBool() {
    return {true, false};
}

extern "C"
PLUGIN_API plg::vector<char> NoParamReturnArrayChar8() {
    return {'a', 'b', 'c', 'd'};
}

extern "C"
PLUGIN_API plg::vector<char16_t> NoParamReturnArrayChar16() {
    return {u'a', u'b', u'c', u'd'};
}

extern "C"
PLUGIN_API plg::vector<int8_t> NoParamReturnArrayInt8() {
    return {-3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API plg::vector<int16_t> NoParamReturnArrayInt16() {
    return {-4, -3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API plg::vector<int32_t> NoParamReturnArrayInt32() {
    return {-5, -4, -3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API plg::vector<int64_t> NoParamReturnArrayInt64() {
    return {-6, -5, -4, -3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API plg::vector<uint8_t> NoParamReturnArrayUInt8() {
    return {0, 1, 2, 3, 4, 5, 6, 7, 8};
}

extern "C"
PLUGIN_API plg::vector<uint16_t> NoParamReturnArrayUInt16() {
    return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
}

extern "C"
PLUGIN_API plg::vector<uint32_t> NoParamReturnArrayUInt32() {
    return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

extern "C"
PLUGIN_API plg::vector<uint64_t> NoParamReturnArrayUInt64() {
    return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
}

extern "C"
PLUGIN_API plg::vector<void *> NoParamReturnArrayPointer() {
    return {
        reinterpret_cast<void *>(0), reinterpret_cast<void *>(1), reinterpret_cast<void *>(2),
        reinterpret_cast<void *>(3)
    };
}

extern "C"
PLUGIN_API plg::vector<float> NoParamReturnArrayFloat() {
    return {-12.34f, 0.0f, 12.34f};
}

extern "C"
PLUGIN_API plg::vector<double> NoParamReturnArrayDouble() {
    return {-12.345, 0.0, 12.345};
}

extern "C"
PLUGIN_API plg::vector<plg::string> NoParamReturnArrayString() {
    return {"1st string", "2nd string", "3rd element string (Should be big enough to avoid small string optimization)"};
}

extern "C"
PLUGIN_API plg::vector<plg::any> NoParamReturnArrayAny() {
    return {
        1.0, 2.0f, "3rd element string (Should be big enough to avoid small string optimization)",
        plg::vector<plg::string>{"lolek", "and", "bolek"}, 1
    };
}

extern "C"
PLUGIN_API plg::vector<plg::vec2> NoParamReturnArrayVector2() {
    return {
        {1.1f, 2.2f},
        {-3.3f, 4.4f},
        {5.5f, -6.6f},
        {7.7f, 8.8f},
        {0.0f, 0.0f}
    };
}

extern "C"
PLUGIN_API plg::vector<plg::vec3> NoParamReturnArrayVector3() {
    return {
        {1.1f, 2.2f, 3.3f},
        {-4.4f, 5.5f, -6.6f},
        {7.7f, 8.8f, 9.9f},
        {0.0f, 0.0f, 0.0f},
        {10.1f, -11.2f, 12.3f}
    };
}

extern "C"
PLUGIN_API plg::vector<plg::vec4> NoParamReturnArrayVector4() {
    return {
        {1.1f, 2.2f, 3.3f, 4.4f},
        {-5.5f, 6.6f, -7.7f, 8.8f},
        {9.9f, 0.0f, -1.1f, 2.2f},
        {3.3f, 4.4f, 5.5f, 6.6f},
        {-7.7f, -8.8f, 9.9f, -10.1f}
    };
}

extern "C"
PLUGIN_API plg::vector<plg::mat4x4> NoParamReturnArrayMatrix4x4() {
    return {
        {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f // Identity matrix
        },
        {
            2.0f, 3.0f, 4.0f, 5.0f,
            6.0f, 7.0f, 8.0f, 9.0f,
            10.0f, 11.0f, 12.0f, 13.0f,
            14.0f, 15.0f, 16.0f, 17.0f // Example random matrix
        },
        {
            -1.0f, -2.0f, -3.0f, -4.0f,
            -5.0f, -6.0f, -7.0f, -8.0f,
            -9.0f, -10.0f, -11.0f, -12.0f,
            -13.0f, -14.0f, -15.0f, -16.0f // Negative matrix
        }
    };
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
PLUGIN_API void Param4(int32_t a, float b, double c, const plg::vec4 &d) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}", a, b, c, d.x, d.w);
}

extern "C"
PLUGIN_API void Param5(int32_t a, float b, double c, const plg::vec4 &d, const plg::vector<int64_t> &e) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}", a, b, c, d.x, d.w, e.size(),
                                    e.size() == 3 ? e[2] : int64_t{0});
}

extern "C"
PLUGIN_API void Param6(int32_t a, float b, double c, const plg::vec4 &d, const plg::vector<int64_t> &e, char f) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}", a, b, c, d.x, d.w, e.size(),
                                    e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f));
}

extern "C"
PLUGIN_API void Param7(int32_t a, float b, double c, const plg::vec4 &d, const plg::vector<int64_t> &e, char f,
                       const plg::string &g) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}", a, b, c, d.x, d.w, e.size(),
                                    e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g);
}

extern "C"
PLUGIN_API void Param8(int32_t a, float b, double c, const plg::vec4 &d, const plg::vector<int64_t> &e, char f,
                       const plg::string &g, char16_t h) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(),
                                    e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g,
                                    static_cast<uint16_t>(h));
}

extern "C"
PLUGIN_API void Param9(int32_t a, float b, double c, const plg::vec4 &d, const plg::vector<int64_t> &e, char f,
                       const plg::string &g, char16_t h, int16_t k) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(),
                                    e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g,
                                    static_cast<uint16_t>(h), k);
}

extern "C"
PLUGIN_API void Param10(int32_t a, float b, double c, const plg::vec4 &d, const plg::vector<int64_t> &e, char f,
                        const plg::string &g, char16_t h, int16_t k, void *l) {
    const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(),
                                    e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g,
                                    static_cast<uint16_t>(h), k, l);
}

extern "C"
PLUGIN_API void ParamRef1(int32_t &a) {
    a = 42;
}

extern "C"
PLUGIN_API void ParamRef2(int32_t &a, float &b) {
    a = 10;
    b = 3.14f;
}

extern "C"
PLUGIN_API void ParamRef3(int32_t &a, float &b, double &c) {
    a = -20;
    b = 2.718f;
    c = 3.14159;
}

extern "C"
PLUGIN_API void ParamRef4(int32_t &a, float &b, double &c, plg::vec4 &d) {
    a = 100;
    b = -5.55f;
    c = 1.618;
    d = {1.0f, 2.0f, 3.0f, 4.0f};
}

extern "C"
PLUGIN_API void ParamRef5(int32_t &a, float &b, double &c, plg::vec4 &d, plg::vector<int64_t> &e) {
    a = 500;
    b = -10.5f;
    c = 2.71828;
    d = {-1.0f, -2.0f, -3.0f, -4.0f};
    e = {-6, -5, -4, -3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API void ParamRef6(int32_t &a, float &b, double &c, plg::vec4 &d, plg::vector<int64_t> &e, char &f) {
    a = 750;
    b = 20.0f;
    c = 1.23456;
    d = {10.0f, 20.0f, 30.0f, 40.0f};
    e = {-6, -5, -4};
    f = 'Z';
}

extern "C"
PLUGIN_API void ParamRef7(int32_t &a, float &b, double &c, plg::vec4 &d, plg::vector<int64_t> &e, char &f,
                          plg::string &g) {
    a = -1000;
    b = 3.0f;
    c = -1.0;
    d = {100.0f, 200.0f, 300.0f, 400.0f};
    e = {-6, -5, -4, -3};
    f = 'Y';
    g = "Hello, World!";
}

extern "C"
PLUGIN_API void ParamRef8(int32_t &a, float &b, double &c, plg::vec4 &d, plg::vector<int64_t> &e, char &f,
                          plg::string &g, char16_t &h) {
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
PLUGIN_API void ParamRef9(int32_t &a, float &b, double &c, plg::vec4 &d, plg::vector<int64_t> &e, char &f,
                          plg::string &g, char16_t &h, int16_t &k) {
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
PLUGIN_API void ParamRef10(int32_t &a, float &b, double &c, plg::vec4 &d, plg::vector<int64_t> &e, char &f,
                           plg::string &g, char16_t &h, int16_t &k, void *&l) {
    a = 987;
    b = -0.123f;
    c = 456.789;
    d = {-123.456f, 0.987f, 654.321f, -789.123f};
    e = {-6, -5, -4, -3, -2, -1, 0, 1, 5, 9, 4, -7};
    f = 'V';
    g = "Another string";
    h = 'C';
    k = -444;
    l = reinterpret_cast<void *>(0x12345678);
}

extern "C"
PLUGIN_API void ParamRefVectors(plg::vector<bool> &p1, plg::vector<char> &p2, plg::vector<char16_t> &p3,
                                plg::vector<int8_t> &p4, plg::vector<int16_t> &p5,
                                plg::vector<int32_t> &p6, plg::vector<int64_t> &p7, plg::vector<uint8_t> &p8,
                                plg::vector<uint16_t> &p9, plg::vector<uint32_t> &p10, plg::vector<uint64_t> &p11,
                                plg::vector<void *> &p12, plg::vector<float> &p13, plg::vector<double> &p14,
                                plg::vector<plg::string> &p15
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
    p12 = {reinterpret_cast<void *>(0), reinterpret_cast<void *>(1), reinterpret_cast<void *>(2)};
    p13 = {-12.34f, 0.0f, 12.34f};
    p14 = {-12.345, 0.0, 12.345};
    p15 = {"1", "12", "123", "1234", "12345", "123456"};
}

extern "C"
PLUGIN_API int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7,
                                      uint8_t p8, uint16_t p9, uint32_t p10,
                                      uint64_t p11, void *p12, float p13, double p14
) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{:.3f}{:.3f}", p1, static_cast<uint8_t>(p2),
                                    static_cast<uint8_t>(p3), p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    return 56;
}

extern "C"
PLUGIN_API int32_t ParamAllAliases(
	const cross_call_master::AliasBool          aBool,
	const cross_call_master::AliasChar8         aChar8,
	const cross_call_master::AliasChar16        aChar16,
	const cross_call_master::AliasInt8          aInt8,
	const cross_call_master::AliasInt16         aInt16,
	const cross_call_master::AliasInt32         aInt32,
	const cross_call_master::AliasInt64         aInt64,
	const cross_call_master::AliasPtr           aPtr,
	const cross_call_master::AliasFloat         aFloat,
	const cross_call_master::AliasDouble        aDouble,
	const cross_call_master::AliasString&       aString,
	const cross_call_master::AliasAny&          aAny,
	const cross_call_master::AliasVec2&         aVec2,
	const cross_call_master::AliasVec3&         aVec3,
	const cross_call_master::AliasVec4&         aVec4,
	const cross_call_master::AliasMat4x4&       aMat4x4,
	const cross_call_master::AliasBoolVector&   aBoolVec,
	const cross_call_master::AliasChar8Vector&  aChar8Vec,
	const cross_call_master::AliasChar16Vector& aChar16Vec,
	const cross_call_master::AliasInt8Vector&   aInt8Vec,
	const cross_call_master::AliasInt16Vector&  aInt16Vec,
	const cross_call_master::AliasInt32Vector&  aInt32Vec,
	const cross_call_master::AliasInt64Vector&  aInt64Vec,
	const cross_call_master::AliasPtrVector&    aPtrVec,
	const cross_call_master::AliasFloatVector&  aFloatVec,
	const cross_call_master::AliasDoubleVector& aDoubleVec,
	const cross_call_master::AliasStringVector& aStringVec,
	const cross_call_master::AliasAnyVector&    aAnyVec,
	const cross_call_master::AliasVec2Vector&   aVec2Vec,
	const cross_call_master::AliasVec3Vector&   aVec3Vec,
	const cross_call_master::AliasVec4Vector&   aVec4Vec,
	const cross_call_master::AliasMat4x4Vector& aMat4x4Vec
) {
	const auto buffer = std::format(
		"{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}",
		aBool,
		aChar8,
		static_cast<uint16_t>(aChar16),
		aInt8,
		aInt16,
		aInt32,
		aInt64,
		aPtr,
		aFloat,
		aDouble,
		aString,
		aAny,
		aVec2,
		aVec3,
		aVec4,
		aMat4x4,
		aBoolVec,
		aChar8Vec,
		aChar16Vec,
		aInt8Vec,
		aInt16Vec,
		aInt32Vec,
		aInt64Vec,
		aPtrVec,
		aFloatVec,
		aDoubleVec,
		aStringVec,
		aAnyVec,
		aVec2Vec,
		aVec3Vec,
		aVec4Vec,
		aMat4x4Vec
	);
	return -1;
}

extern "C"
PLUGIN_API int64_t ParamAllRefAliases(
	cross_call_master::AliasBool&         aBool,
	cross_call_master::AliasChar8&        aChar8,
	cross_call_master::AliasChar16&       aChar16,
	cross_call_master::AliasInt8&         aInt8,
	cross_call_master::AliasInt16&        aInt16,
	cross_call_master::AliasInt32&        aInt32,
	cross_call_master::AliasInt64&        aInt64,
	cross_call_master::AliasPtr&          aPtr,
	cross_call_master::AliasFloat&        aFloat,
	cross_call_master::AliasDouble&       aDouble,
	cross_call_master::AliasString&       aString,
	cross_call_master::AliasAny&          aAny,
	cross_call_master::AliasVec2&         aVec2,
	cross_call_master::AliasVec3&         aVec3,
	cross_call_master::AliasVec4&         aVec4,
	cross_call_master::AliasMat4x4&       aMat4x4,
	cross_call_master::AliasBoolVector&   aBoolVec,
	cross_call_master::AliasChar8Vector&  aChar8Vec,
	cross_call_master::AliasChar16Vector& aChar16Vec,
	cross_call_master::AliasInt8Vector&   aInt8Vec,
	cross_call_master::AliasInt16Vector&  aInt16Vec,
	cross_call_master::AliasInt32Vector&  aInt32Vec,
	cross_call_master::AliasInt64Vector&  aInt64Vec,
	cross_call_master::AliasPtrVector&    aPtrVec,
	cross_call_master::AliasFloatVector&  aFloatVec,
	cross_call_master::AliasDoubleVector& aDoubleVec,
	cross_call_master::AliasStringVector& aStringVec,
	cross_call_master::AliasAnyVector&    aAnyVec,
	cross_call_master::AliasVec2Vector&   aVec2Vec,
	cross_call_master::AliasVec3Vector&   aVec3Vec,
	cross_call_master::AliasVec4Vector&   aVec4Vec,
	cross_call_master::AliasMat4x4Vector& aMat4x4Vec
) {
	aBool = true;
	aChar8 = 'A';
	aChar16 = u'0';
	aInt8 = 1;
	aInt16 = 2;
	aInt32 = 3;
	aInt64 = 4;
	aPtr = nullptr;
	aFloat = 5.0f;
	aDouble = 5.0;
	aString = "seven";
	aAny = "six";
	aVec2 = {0.1f, 0.2f};
	aVec3 = {0.3f, 0.4f, 0.5f};
	aVec4 = {0.6f, 0.7f, 0.8f, 0.9f};
	aMat4x4 = {1.4f, 1.1f, 1.2f, 1.3f, 2.4f, 2.1f, 2.2f, 2.3f, 3.4f, 3.1f, 3.2f, 3.3f, 4.4f, 4.1f, 4.2f, 4.3f};
	aBoolVec = {aBool};
	aChar8Vec = {aChar8};
	aChar16Vec = {aChar16};
	aInt8Vec = {aInt8};
	aInt16Vec = {aInt16};
	aInt32Vec = {aInt32};
	aInt64Vec = {aInt64};
	aPtrVec = {aPtr};
	aFloatVec = {aFloat};
	aDoubleVec = {aDouble};
	aStringVec = {aString};
	aAnyVec = {aAny};
	aVec2Vec = {aVec2};
	aVec3Vec = {aVec3};
	aVec4Vec = {aVec4};
	aMat4x4Vec = {aMat4x4};
	return 24;
}

extern "C"
PLUGIN_API int32_t ParamEnum(Example p1, const plg::vector<Example> &p2) {
    return static_cast<int32_t>(p1) + std::accumulate(p2.begin(), p2.end(), int32_t{0},
                                                      [](int32_t sum, const Example &e) {
                                                          return sum + static_cast<int32_t>(e);
                                                      });
}

extern "C"
PLUGIN_API int32_t ParamEnumRef(Example &p1, plg::vector<Example> &p2) {
    p1 = Example::Forth;
    p2 = plg::vector<Example>{Example::First, Example::Second, Example::Third};
    return static_cast<int32_t>(p1) + std::accumulate(p2.begin(), p2.end(), int32_t{0},
                                                      [](int32_t sum, const Example &e) {
                                                          return sum + static_cast<int32_t>(e);
                                                      });
}

extern "C"
PLUGIN_API void ParamVariant(const plg::any &p1, const plg::vector<plg::any> &p2) {
    const auto buffer = std::format("{}|{}", p1, p2);
}

extern "C"
PLUGIN_API void ParamVariantRef(plg::any &p1, plg::vector<plg::any> &p2) {
    p1 = 'Z';
    p2.resize(5);
    p2[0] = false;
    p2[1] = 6.28;
    p2[2] = plg::vector<double>{1, 2, 3};
    p2[3] = nullptr;
    p2[4] = 123456789;
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
PLUGIN_API char CallFuncChar8(cross_call_master::FuncChar8 func) {
    char result = func();
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
PLUGIN_API void *CallFuncPtr(cross_call_master::FuncPtr func) {
    void *result = func();
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
PLUGIN_API void *CallFuncFunction(cross_call_master::FuncFunction func) {
    void *result = func();
    return result;
}

extern "C"
PLUGIN_API plg::string CallFuncString(cross_call_master::FuncString func) {
    plg::string result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::any CallFuncAny(cross_call_master::FuncAny func) {
    plg::any result = func();
    return result;
}

// Call functions for vector return types
extern "C"
PLUGIN_API  plg::vector<bool> CallFuncBoolVector(cross_call_master::FuncBoolVector func) {
    plg::vector<bool> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<char> CallFuncChar8Vector(cross_call_master::FuncChar8Vector func) {
    plg::vector<char> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<char16_t> CallFuncChar16Vector(cross_call_master::FuncChar16Vector func) {
    plg::vector<char16_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int8_t> CallFuncInt8Vector(cross_call_master::FuncInt8Vector func) {
    plg::vector<int8_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int16_t> CallFuncInt16Vector(cross_call_master::FuncInt16Vector func) {
    plg::vector<int16_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int32_t> CallFuncInt32Vector(cross_call_master::FuncInt32Vector func) {
    plg::vector<int32_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<int64_t> CallFuncInt64Vector(cross_call_master::FuncInt64Vector func) {
    plg::vector<int64_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint8_t> CallFuncUInt8Vector(cross_call_master::FuncUInt8Vector func) {
    plg::vector<uint8_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint16_t> CallFuncUInt16Vector(cross_call_master::FuncUInt16Vector func) {
    plg::vector<uint16_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint32_t> CallFuncUInt32Vector(cross_call_master::FuncUInt32Vector func) {
    plg::vector<uint32_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<uint64_t> CallFuncUInt64Vector(cross_call_master::FuncUInt64Vector func) {
    plg::vector<uint64_t> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<void *> CallFuncPtrVector(cross_call_master::FuncPtrVector func) {
    plg::vector<void *> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<float> CallFuncFloatVector(cross_call_master::FuncFloatVector func) {
    plg::vector<float> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<double> CallFuncDoubleVector(cross_call_master::FuncDoubleVector func) {
    plg::vector<double> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::string> CallFuncStringVector(cross_call_master::FuncStringVector func) {
    plg::vector<plg::string> result = func();
    return std::move(result);
}

extern "C"
PLUGIN_API plg::vector<plg::any> CallFuncAnyVector(cross_call_master::FuncAnyVector func) {
    plg::vector<plg::any> result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vector<plg::vec2> CallFuncVec2Vector(cross_call_master::FuncVec2Vector func) {
    plg::vector<plg::vec2> result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vector<plg::vec3> CallFuncVec3Vector(cross_call_master::FuncVec3Vector func) {
    plg::vector<plg::vec3> result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vector<plg::vec4> CallFuncVec4Vector(cross_call_master::FuncVec4Vector func) {
    plg::vector<plg::vec4> result = func();
    return result;
}

extern "C"
PLUGIN_API plg::vector<plg::mat4x4> CallFuncMat4x4Vector(cross_call_master::FuncMat4x4Vector func) {
    plg::vector<plg::mat4x4> result = func();
    return result;
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
    void *ptr = reinterpret_cast<void *>(12345); // Example pointer changed
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
    plg::mat4x4 mat{}; // Assume it's initialized properly
    return func(b, u32, ch16, mat);
}

// 5 parameters
extern "C"
PLUGIN_API bool CallFunc5(cross_call_master::Func5 func) {
    int8_t i8 = 10; // Changed to random int8_t
    plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
    void *ptr = reinterpret_cast<void *>(67890); // Example pointer changed
    double d = 1.618; // Changed to random double
    plg::vector<uint64_t> vec64{4, 5, 6}; // Changed to random values
    return func(i8, vec2, ptr, d, vec64);
}

// 6 parameters
extern "C"
PLUGIN_API int64_t CallFunc6(cross_call_master::Func6 func) {
    plg::string str = "AnotherString"; // Changed string
    float f = 4.56f; // Changed to random float
    plg::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed to random values
    int16_t i16 = 30; // Changed to random int16_t
    plg::vector<uint8_t> vecU8{3, 4, 5}; // Changed to random values
    void *ptr = reinterpret_cast<void *>(24680); // Example pointer changed
    return func(str, f, vecF, i16, vecU8, ptr);
}

// 7 parameters
extern "C"
PLUGIN_API double CallFunc7(cross_call_master::Func7 func) {
    plg::vector<char> vecC{'X', 'Y', 'Z'}; // Changed to random chars
    uint16_t u16 = 20; // Changed to random uint16_t
    char16_t ch16 = 'C'; // Changed to random character
    plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
    plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
    bool b = false; // Changed to random bool
    uint64_t u64 = 200; // Changed to random uint64_t
    return func(vecC, u16, ch16, vecU32, vec4, b, u64);
}

// 8 parameters
extern "C"
PLUGIN_API plg::mat4x4 CallFunc8(cross_call_master::Func8 func) {
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
    plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed to random values
    int16_t i16 = 30; // Changed to random int16_t
    bool b = false; // Changed to random bool
    plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
    plg::vector<char16_t> vecC16{'D', 'E'}; // Changed to random chars
    char16_t ch16 = L'B'; // Changed to random character
    int32_t i32 = 50; // Changed to random int32_t
    return func(vec3, vecU32, i16, b, vec4, vecC16, ch16, i32);
}

// 9 parameters
extern "C"
PLUGIN_API void CallFunc9(cross_call_master::Func9 func) {
    float f = 2.71f; // Changed to random float
    plg::vec2 vec2{3.4f, 5.6f}; // Changed to random values
    plg::vector<int8_t> vecI8{4, 5, 6}; // Changed to random values
    uint64_t u64 = 250; // Changed to random uint64_t
    bool b = false; // Changed to random bool
    plg::string str = "Random"; // Changed string
    plg::vec4 vec4{4.5f, 5.6f, 6.7f, 7.8f}; // Changed to random values
    int16_t i16 = 30; // Changed to random int16_t
    void *ptr = reinterpret_cast<void *>(13579); // Example pointer changed
    func(f, vec2, vecI8, u64, b, str, vec4, i16, ptr);
}

// 10 parameters
extern "C"
PLUGIN_API uint32_t CallFunc10(cross_call_master::Func10 func) {
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
    return func(vec4, mat, vecU32, u64, vecC, i32, b, vec2, i64, d);
}

// 11 parameters
extern "C"
PLUGIN_API void *CallFunc11(cross_call_master::Func11 func) {
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
    return func(vecB, ch16, u8, d, vec3, vecI8, i64, u16, f, vec2, u32);
}

// 12 parameters
extern "C"
PLUGIN_API bool CallFunc12(cross_call_master::Func12 func) {
    void *ptr = reinterpret_cast<void *>(98765); // Example pointer changed
    plg::vector<double> vecD{4.0, 5.0, 6.0}; // Changed to random values
    uint32_t u32 = 30; // Changed to random uint32_t
    double d = 1.41; // Changed to random double
    bool b = false; // Changed to random bool
    int32_t i32 = 25; // Changed to random int32_t
    int8_t i8 = 10; // Changed to random int8_t
    uint64_t u64 = 300; // Changed to random uint64_t
    float f = 2.72f; // Changed to random float
    plg::vector<void *> vecPtr{
        reinterpret_cast<void *>(2), reinterpret_cast<void *>(3), reinterpret_cast<void *>(4)
    }; // Changed to random values
    int64_t i64 = 200; // Changed to random int64_t
    char ch = 'B'; // Changed to random character
    return func(ptr, vecD, u32, d, b, i32, i8, u64, f, vecPtr, i64, ch);
}

// 13 parameters
extern "C"
PLUGIN_API plg::string CallFunc13(cross_call_master::Func13 func) {
    int64_t i64 = 75; // Changed to random int64_t
    plg::vector<char> vecC{'D', 'E', 'F'}; // Changed to random chars
    uint16_t u16 = 20; // Changed to random uint16_t
    float f = 2.71f; // Changed to random float
    plg::vector<bool> vecB{false, true, false}; // Changed to random bools
    plg::vec4 vec4{5.6f, 7.8f, 9.0f, 10.1f}; // Changed to random values
    plg::string str = "RandomString"; // Changed string
    int32_t i32 = 30; // Changed to random int32_t
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed to random values
    void *ptr = reinterpret_cast<void *>(13579); // Example pointer changed
    plg::vec2 vec2{4.5f, 6.7f}; // Changed to random values
    plg::vector<uint8_t> vecU8{2, 3, 4}; // Changed to random values
    int16_t i16 = 20; // Changed to random int16_t
    auto ret = func(i64, vecC, u16, f, vecB, vec4, str, i32, vec3, ptr, vec2, vecU8, i16);
    return std::move(ret);
}

// 14 parameters
extern "C"
PLUGIN_API plg::vector<plg::string> CallFunc14(cross_call_master::Func14 func) {
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
    void *ptr = reinterpret_cast<void *>(54321); // Example pointer changed
    auto ret = func(vecC, vecU32, mat, b, ch16, i32, vecF, u16, vecU8, i8, vec3, vec4, d, ptr);
    return std::move(ret);
}

// 15 parameters
extern "C"
PLUGIN_API int16_t CallFunc15(cross_call_master::Func15 func) {
    plg::vector<int16_t> vecI16{4, 5, 6}; // Changed to random values
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vec4 vec4{7.8f, 8.9f, 9.0f, 10.1f}; // Changed to random values
    void *ptr = reinterpret_cast<void *>(12345); // Example pointer changed
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
    return func(vecI16, mat, vec4, ptr, u64, vecU32, b, f, vecC16, u8, i32, vec2, u16, d, vecU8);
}

// 16 parameters
extern "C"
PLUGIN_API void *CallFunc16(cross_call_master::Func16 func) {
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
    return func(vecB, i16, vecI8, vec4, mat, vec2, vecU64, vecC, str, i64, vecU32, vec3, f, d, i8, u16);
}

// 1 parameter
extern "C"
PLUGIN_API plg::string CallFunc17(cross_call_master::Func17 func) {
    int32_t i32 = 42; // Changed from 20 to 42
    func(i32);
    return std::format("{}", i32);
}

// 2 parameters
extern "C"
PLUGIN_API plg::string CallFunc18(cross_call_master::Func18 func) {
    int8_t i8 = 9; // Changed from 5 to 9
    int16_t i16 = 25; // Changed from 10 to 25
    plg::vec2 ret = func(i8, i16);
    return std::format("{}|{}|{}", ret, i8, i16);
}

// 3 parameters
extern "C"
PLUGIN_API plg::string CallFunc19(cross_call_master::Func19 func) {
    uint32_t u32 = 75; // Changed from 10 to 75
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values in vec3
    plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed vector values
    func(u32, vec3, vecU32);
    return std::format("{}|{}|{}", u32, vec3, vecU32);
}

// 4 parameters
extern "C"
PLUGIN_API plg::string CallFunc20(cross_call_master::Func20 func) {
    char16_t ch16 = 'Z'; // Changed from 'A' to 'Z'
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    plg::vector<uint64_t> vecU64{4, 5, 6}; // Changed vector values
    char ch = 'X'; // Changed from 'B' to 'X'
    int32_t ret = func(ch16, vec4, vecU64, ch);
    return std::format("{}|{}|{}|{}|{}", ret, static_cast<uint16_t>(ch16), vec4, vecU64, ch);
}

// 5 parameters
extern "C"
PLUGIN_API plg::string CallFunc21(cross_call_master::Func21 func) {
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vector<int32_t> vecI32{4, 5, 6}; // Changed vector values
    plg::vec2 vec2{3.0f, 4.0f}; // Changed vec2 values
    bool b = false; // Changed from true to false
    double d = 6.28; // Changed from 3.14 to 6.28
    float ret = func(mat, vecI32, vec2, b, d);
    return std::format("{}|{}|{}|{}|{}|{}", ret, mat, vecI32, vec2, b ? "true" : "false", d);
}

// 6 parameters
extern "C"
PLUGIN_API plg::string CallFunc22(cross_call_master::Func22 func) {
    void *ptr = reinterpret_cast<void *>(1); // Changed from 0 to 1
    uint32_t u32 = 20; // Changed from 10 to 20
    plg::vector<double> vecD{4.0, 5.0, 6.0}; // Changed vector values
    int16_t i16 = 15; // Changed from 10 to 15
    plg::string str = "Updated Test"; // Changed string
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    uint64_t ret = func(ptr, u32, vecD, i16, str, vec4);
    return std::format("{}|{}|{}|{}|{}|{}|{}", ret, ptr, u32, vecD, i16, str.c_str(), vec4);
}

// 7 parameters
extern "C"
PLUGIN_API plg::string CallFunc23(cross_call_master::Func23 func) {
    uint64_t u64 = 200; // Changed from 100 to 200
    plg::vec2 vec2{3.0f, 4.0f}; // Changed vec2 values
    plg::vector<int16_t> vecI16{4, 5, 6}; // Changed vector values
    char16_t ch16 = 'Y'; // Changed from 'A' to 'Y'
    float f = 2.34f; // Changed from 1.23f to 2.34f
    int8_t i8 = 10; // Changed from 5 to 10
    plg::vector<uint8_t> vecU8{3, 4, 5}; // Changed vector values
    func(u64, vec2, vecI16, ch16, f, i8, vecU8);
    return std::format("{}|{}|{}|{}|{}|{}|{}", u64, vec2, vecI16, static_cast<uint16_t>(ch16), f, i8, vecU8);
}

// 8 parameters
extern "C"
PLUGIN_API plg::string CallFunc24(cross_call_master::Func24 func) {
    plg::vector<char> vecC{'D', 'E', 'F'}; // Changed from {'A', 'B', 'C'} to {'D', 'E', 'F'}
    int64_t i64 = 100; // Changed from 50 to 100
    plg::vector<uint8_t> vecU8{3, 4, 5}; // Changed vector values
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    uint64_t u64 = 200; // Changed from 100 to 200
    plg::vector<void *> vecPtr{
        reinterpret_cast<void *>(3), reinterpret_cast<void *>(4), reinterpret_cast<void *>(5)
    }; // Changed vector values
    double d = 6.28; // Changed from 3.14 to 6.28
    plg::vector<void *> vecV2{
        reinterpret_cast<void *>(4), reinterpret_cast<void *>(5), reinterpret_cast<void *>(6),
        reinterpret_cast<void *>(7)
    }; // Changed vector values
    plg::mat4x4 ret = func(vecC, i64, vecU8, vec4, u64, vecPtr, d, vecV2);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, vecC, i64, vecU8, vec4, u64, vecPtr, d, vecV2);
}

// 9 parameters
extern "C"
PLUGIN_API plg::string CallFunc25(cross_call_master::Func25 func) {
    int32_t i32 = 50; // Changed from 20 to 50
    plg::vector<void *> vecPtr{
        reinterpret_cast<void *>(3), reinterpret_cast<void *>(4), reinterpret_cast<void *>(5)
    }; // Changed vector values
    bool b = false; // Changed from true to false
    uint8_t u8 = 10; // Changed from 5 to 10
    plg::string str = "Updated Test String"; // Changed string
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed vec3 values
    int64_t i64 = 100; // Changed from 50 to 100
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed vec4 values
    uint16_t u16 = 20; // Changed from 10 to 20
    double ret = func(i32, vecPtr, b, u8, str, vec3, i64, vec4, u16);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, i32, vecPtr, b ? "true" : "false", u8, str.c_str(), vec3,
                       i64, vec4, u16);
}

// 10 parameters
extern "C"
PLUGIN_API plg::string CallFunc26(cross_call_master::Func26 func) {
    char16_t ch16 = 'B'; // Changed from 'A' to 'B'
    plg::vec2 vec2{3.0f, 4.0f}; // Changed vec2 values
    plg::mat4x4 mat; // Assume it's initialized properly
    plg::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed vector values
    int16_t i16 = 20; // Changed from 10 to 20
    uint64_t u64 = 200; // Changed from 100 to 200
    uint32_t u32 = 20; // Changed from 10 to 20
    plg::vector<uint16_t> vecU16{3, 4, 5};
    void *ptr = reinterpret_cast<void *>(0xDEADBEAFDEADBEAF); // Example pointer
    bool b = false;
    char ret = func(ch16, vec2, mat, vecF, i16, u64, u32, vecU16, ptr, b);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, static_cast<uint16_t>(ch16), vec2, mat, vecF, u64, u32,
                       vecU16, ptr, b ? "true" : "false");
}

// 11 parameters
extern "C"
PLUGIN_API plg::string CallFunc27(cross_call_master::Func27 func) {
    float f = 2.56f; // Changed from 1.23f
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    void *ptr = nullptr; // Example pointer
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    plg::vector<int16_t> vecI16{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume it's initialized properly
    bool b = false; // Changed from true to false
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed values
    int8_t i8 = 10; // Changed from 5 to 10
    int32_t i32 = 40; // Changed from 20 to 40
    plg::vector<uint8_t> vecU8{3, 4, 5}; // Changed values
    uint8_t ret = func(f, vec3, ptr, vec2, vecI16, mat, b, vec4, i8, i32, vecU8);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, f, vec3, ptr, vec2, vecI16, mat, b, vec4, i8, i32,
                       vecU8);
}

// 12 parameters
extern "C"
PLUGIN_API plg::string CallFunc28(cross_call_master::Func28 func) {
    void *ptr = reinterpret_cast<void *>(1); // Changed from 0
    uint16_t u16 = 20; // Changed from 10
    plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    float f = 2.71f; // Changed from 3.14f
    plg::vec4 vec4{5.0f, 6.0f, 7.0f, 8.0f}; // Changed values
    plg::string str = "New example string"; // Changed string
    plg::vector<uint64_t> vecU64{400, 500, 600}; // Changed values
    int64_t i64 = 987654321; // Changed from 123456789
    bool b = false; // Changed from true
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    plg::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed values

    plg::string ret = func(ptr, u16, vecU32, mat, f, vec4, str, vecU64, i64, b, vec3, vecF);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ptr, u16, vecU32, mat, f, vec4, str, vecU64, i64,
                       b, vec3, vecF);
}

// 13 parameters
extern "C"
PLUGIN_API plg::string CallFunc29(cross_call_master::Func29 func) {
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    int32_t i32 = 99; // Changed from 42
    plg::vector<int8_t> vecI8{4, 5, 6}; // Changed values
    double d = 2.71; // Changed from 3.14
    bool b = false; // Changed from true
    int8_t i8 = 10; // Changed from 5
    plg::vector<uint16_t> vecU16{4, 5, 6}; // Changed values
    float f = 3.21f; // Changed from 1.23f
    plg::string str = "Yet another example string"; // Changed string
    plg::mat4x4 mat; // Assume initialized properly
    uint64_t u64 = 200; // Changed from 100
    plg::vec3 vec3{5.0f, 6.0f, 7.0f}; // Changed values
    plg::vector<int64_t> vecI64{2000, 3000, 4000}; // Changed values

    plg::vector<plg::string> ret = func(vec4, i32, vecI8, d, b, i8, vecU16, f, str, mat, u64, vec3, vecI64);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, vec4, i32, vecI8, d, b ? "true" : "false", i8,
                       vecU16, f, str, mat, u64, vec3, vecI64);
}

// 14 parameters
extern "C"
PLUGIN_API plg::string CallFunc30(cross_call_master::Func30 func) {
    void *ptr = reinterpret_cast<void *>(1); // Changed from 0
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    int64_t i64 = 987654321; // Changed from 123456789
    plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed values
    bool b = false; // Changed from true
    plg::string str = "Updated String for Func30"; // Changed string
    plg::vec3 vec3{5.0f, 6.0f, 7.0f}; // Changed values
    plg::vector<uint8_t> vecU8{1, 2, 3}; // Changed values
    float f = 5.67f; // Changed from 4.56f
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    int8_t i8 = 10; // Changed from 5
    plg::vector<float> vecF{4.0f, 5.0f, 6.0f}; // Changed values
    double d = 8.90; // Changed from 7.89

    int32_t ret = func(ptr, vec4, i64, vecU32, b, str, vec3, vecU8, f, vec2, mat, i8, vecF, d);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ptr, vec4, i64, vecU32,
                       b ? "true" : "false", str, vec3, vecU8, f, vec2, mat, i8, vecF, d);
}

// 15 parameters
extern "C"
PLUGIN_API plg::string CallFunc31(cross_call_master::Func31 func) {
    char ch = 'B'; // Changed from 'A'
    uint32_t u32 = 200; // Changed from 100
    plg::vector<uint64_t> vecU64{4, 5, 6}; // Changed values
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    plg::string str = "Updated String for Func31"; // Changed string
    bool b = true; // Changed from false
    int64_t i64 = 987654321; // Changed from 123456789
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    int8_t i8 = 10; // Changed from 5
    uint16_t u16 = 20; // Changed from 10
    plg::vector<int16_t> vecI16{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    float f = 5.67f; // Changed from 4.56f
    plg::vector<double> vecD{4.0, 5.0, 6.0}; // Changed values

    plg::vec3 ret = func(ch, u32, vecU64, vec4, str, b, i64, vec2, i8, u16, vecI16, mat, vec3, f, vecD);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", ret, ch, u32, vecU64, vec4, str,
                       b ? "true" : "false", i64, vec2, i8, u16, vecI16, mat, vec3, f, vecD);
}

// 16 parameters
extern "C"
PLUGIN_API plg::string CallFunc32(cross_call_master::Func32 func) {
    int32_t i32 = 30; // Changed from 20
    uint16_t u16 = 20; // Changed from 10
    plg::vector<int8_t> vecI8{4, 5, 6}; // Changed values
    plg::vec4 vec4{2.0f, 3.0f, 4.0f, 5.0f}; // Changed values
    void *ptr = reinterpret_cast<void *>(1); // Changed from 0
    plg::vector<uint32_t> vecU32{4, 5, 6}; // Changed values
    plg::mat4x4 mat; // Assume initialized properly
    uint64_t u64 = 200; // Changed from 100
    plg::string str = "Updated String for Func32"; // Changed string
    int64_t i64 = 987654321; // Changed from 123456789
    plg::vec2 vec2{3.0f, 4.0f}; // Changed values
    plg::vector<int8_t> vecI8_2{7, 8, 9}; // Another sample vector of int8
    bool b = false; // Changed from true
    plg::vec3 vec3{4.0f, 5.0f, 6.0f}; // Changed values
    uint8_t u8 = 128; // Changed from 255
    plg::vector<char16_t> vecC16{u'D', u'E', u'F'}; // Changed values

    func(i32, u16, vecI8, vec4, ptr, vecU32, mat, u64, str, i64, vec2, vecI8_2, b, vec3, u8, vecC16);
    return std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", i32, u16, vecI8, vec4, ptr, vecU32, mat, u64,
                       str, i64, vec2, vecI8_2, b ? "true" : "false", vec3, u8, vecC16);
}

// 1 parameters
extern "C"
PLUGIN_API plg::string CallFunc33(cross_call_master::Func33 func) {
    plg::any variant = 30;
    func(variant);
    return std::format("{}", variant);
}

// enums
extern "C"
PLUGIN_API plg::string CallFuncEnum(cross_call_master::FuncEnum func) {
    cross_call_master::Example p1 = cross_call_master::Example::Forth;
    plg::vector<cross_call_master::Example> p2;
    auto ret = func(p1, p2);
    return std::format("{}|{}", ret, p2);
}

// aliases

extern "C"
PLUGIN_API cross_call_master::AliasBool CallFuncAliasBool(cross_call_master::FuncAliasBool func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasChar8 CallFuncAliasChar8(cross_call_master::FuncAliasChar8 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasChar16 CallFuncAliasChar16(cross_call_master::FuncAliasChar16 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt8 CallFuncAliasInt8(cross_call_master::FuncAliasInt8 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt16 CallFuncAliasInt16(cross_call_master::FuncAliasInt16 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt32 CallFuncAliasInt32(cross_call_master::FuncAliasInt32 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt64 CallFuncAliasInt64(cross_call_master::FuncAliasInt64 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt8 CallFuncAliasUInt8(cross_call_master::FuncAliasUInt8 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt16 CallFuncAliasUInt16(cross_call_master::FuncAliasUInt16 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt32 CallFuncAliasUInt32(cross_call_master::FuncAliasUInt32 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt64 CallFuncAliasUInt64(cross_call_master::FuncAliasUInt64 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasPtr CallFuncAliasPtr(cross_call_master::FuncAliasPtr func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasFloat CallFuncAliasFloat(cross_call_master::FuncAliasFloat func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasDouble CallFuncAliasDouble(cross_call_master::FuncAliasDouble func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasFunction CallFuncAliasFunction(cross_call_master::FuncAliasFunction func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasString CallFuncAliasString(cross_call_master::FuncAliasString func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasAny CallFuncAliasAny(cross_call_master::FuncAliasAny func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasBoolVector CallFuncAliasBoolVector(cross_call_master::FuncAliasBoolVector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasChar8Vector CallFuncAliasChar8Vector(cross_call_master::FuncAliasChar8Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasChar16Vector CallFuncAliasChar16Vector(cross_call_master::FuncAliasChar16Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt8Vector CallFuncAliasInt8Vector(cross_call_master::FuncAliasInt8Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt16Vector CallFuncAliasInt16Vector(cross_call_master::FuncAliasInt16Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt32Vector CallFuncAliasInt32Vector(cross_call_master::FuncAliasInt32Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasInt64Vector CallFuncAliasInt64Vector(cross_call_master::FuncAliasInt64Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt8Vector CallFuncAliasUInt8Vector(cross_call_master::FuncAliasUInt8Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt16Vector CallFuncAliasUInt16Vector(cross_call_master::FuncAliasUInt16Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt32Vector CallFuncAliasUInt32Vector(cross_call_master::FuncAliasUInt32Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasUInt64Vector CallFuncAliasUInt64Vector(cross_call_master::FuncAliasUInt64Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasPtrVector CallFuncAliasPtrVector(cross_call_master::FuncAliasPtrVector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasFloatVector CallFuncAliasFloatVector(cross_call_master::FuncAliasFloatVector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasDoubleVector CallFuncAliasDoubleVector(cross_call_master::FuncAliasDoubleVector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasStringVector CallFuncAliasStringVector(cross_call_master::FuncAliasStringVector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasAnyVector CallFuncAliasAnyVector(cross_call_master::FuncAliasAnyVector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasVec2Vector CallFuncAliasVec2Vector(cross_call_master::FuncAliasVec2Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasVec3Vector CallFuncAliasVec3Vector(cross_call_master::FuncAliasVec3Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasVec4Vector CallFuncAliasVec4Vector(cross_call_master::FuncAliasVec4Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasMat4x4Vector CallFuncAliasMat4x4Vector(cross_call_master::FuncAliasMat4x4Vector func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasVec2 CallFuncAliasVec2(cross_call_master::FuncAliasVec2 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasVec3 CallFuncAliasVec3(cross_call_master::FuncAliasVec3 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasVec4 CallFuncAliasVec4(cross_call_master::FuncAliasVec4 func) { return func(); }

extern "C"
PLUGIN_API cross_call_master::AliasMat4x4 CallFuncAliasMat4x4(cross_call_master::FuncAliasMat4x4 func) { return func(); }

extern "C"
PLUGIN_API plg::string CallFuncAliasAll(cross_call_master::FuncAliasAll func) {
	cross_call_master::AliasBool aBool{true};
	cross_call_master::AliasChar8 aChar8{'A'};
	cross_call_master::AliasChar16 aChar16{u'0'};
	cross_call_master::AliasInt8 aInt8{1};
	cross_call_master::AliasInt16 aInt16{2};
	cross_call_master::AliasInt32 aInt32{3};
	cross_call_master::AliasInt64 aInt64{4};
	cross_call_master::AliasPtr aPtr{};
	cross_call_master::AliasFloat aFloat{5.5f};
	cross_call_master::AliasDouble aDouble{6.6};
	cross_call_master::AliasString aString{"seven"};
	cross_call_master::AliasAny aAny{"six"};
	cross_call_master::AliasVec2 aVec2{0.1f, 0.2f};
	cross_call_master::AliasVec3 aVec3{0.3f, 0.4f, 0.5f};
	cross_call_master::AliasVec4 aVec4{0.6f, 0.7f, 0.8f, 0.9f};
	cross_call_master::AliasMat4x4 aMat4x4{1.4f, 1.1f, 1.2f, 1.3f, 2.4f, 2.1f, 2.2f, 2.3f, 3.4f, 3.1f, 3.2f, 3.3f, 4.4f, 4.1f, 4.2f, 4.3f};
	cross_call_master::AliasBoolVector aBoolVec{aBool};
	cross_call_master::AliasChar8Vector aChar8Vec{aChar8};
	cross_call_master::AliasChar16Vector aChar16Vec{aChar16};
	cross_call_master::AliasInt8Vector aInt8Vec{aInt8};
	cross_call_master::AliasInt16Vector aInt16Vec{aInt16};
	cross_call_master::AliasInt32Vector aInt32Vec{aInt32};
	cross_call_master::AliasInt64Vector aInt64Vec{aInt64};
	cross_call_master::AliasPtrVector aPtrVec{aPtr};
	cross_call_master::AliasFloatVector aFloatVec{aFloat};
	cross_call_master::AliasDoubleVector aDoubleVec{aDouble};
	cross_call_master::AliasStringVector aStringVec{aString};
	cross_call_master::AliasAnyVector aAnyVec{aAny};
	cross_call_master::AliasVec2Vector aVec2Vec{aVec2};
	cross_call_master::AliasVec3Vector aVec3Vec{aVec3};
	cross_call_master::AliasVec4Vector aVec4Vec{aVec4};
	cross_call_master::AliasMat4x4Vector aMat4x4Vec{aMat4x4};
	plg::string result = func(aBool, aChar8, aChar16, aInt8, aInt16, aInt32, aInt64, aPtr, aFloat, aDouble, aString, aAny, aVec2, aVec3, aVec4, aMat4x4, aBoolVec, aChar8Vec, aChar16Vec, aInt8Vec, aInt16Vec, aInt32Vec, aInt64Vec, aPtrVec, aFloatVec, aDoubleVec, aStringVec, aAnyVec, aVec2Vec, aVec3Vec, aVec4Vec, aMat4x4Vec);
	return result;
}

// Mock Functions for the typedefs

void MockVoid() {
    /*std::cout << "Void function called\n";*/
}

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
void *MockPtr() { return nullptr; }
float MockFloat() { return 3.14f; }
double MockDouble() { return 6.28; }
void *MockFunction() { return nullptr; }
plg::string MockString() { return "Test string"; }
plg::any MockAny() { return L'A'; }

plg::vector<bool> MockBoolVector() { return {true, false}; }
plg::vector<char> MockChar8Vector() { return {'A', 'B'}; }
plg::vector<char16_t> MockChar16Vector() { return {u'A', u'B'}; }
plg::vector<int8_t> MockInt8Vector() { return {10, 20}; }
plg::vector<int16_t> MockInt16Vector() { return {100, 200}; }
plg::vector<int32_t> MockInt32Vector() { return {1000, 2000}; }
plg::vector<int64_t> MockInt64Vector() { return {10000, 20000}; }
plg::vector<uint8_t> MockUInt8Vector() { return {20, 30}; }
plg::vector<uint16_t> MockUInt16Vector() { return {200, 300}; }
plg::vector<uint32_t> MockUInt32Vector() { return {2000, 3000}; }
plg::vector<uint64_t> MockUInt64Vector() { return {20000, 30000}; }
plg::vector<void *> MockPtrVector() { return {nullptr, reinterpret_cast<void *>(1)}; }
plg::vector<float> MockFloatVector() { return {1.1f, 2.2f}; }
plg::vector<double> MockDoubleVector() { return {3.3, 4.4}; }
plg::vector<plg::string> MockStringVector() { return {"Hello", "World"}; }
plg::vector<plg::any> MockAnyVector() { return {"Hello", 3.14f, 6.28, 1, 0xDEADBEAF}; }

plg::vector<plg::vec2> MockVec2Vector() {
    return {
        {0.5f, -1.2f},
        {3.4f, 7.8f},
        {-6.7f, 2.3f},
        {8.9f, -4.5f},
        {0.0f, 0.0f}
    };
}

plg::vector<plg::vec3> MockVec3Vector() {
    return {
        {2.1f, 3.2f, 4.3f},
        {-5.4f, 6.5f, -7.6f},
        {8.7f, 9.8f, 0.1f},
        {1.2f, -3.3f, 4.4f},
        {-5.5f, 6.6f, -7.7f}
    };
}

plg::vector<plg::vec4> MockVec4Vector() {
    return {
        {0.1f, 1.2f, 2.3f, 3.4f},
        {-4.5f, 5.6f, 6.7f, -7.8f},
        {8.9f, -9.0f, 10.1f, -11.2f},
        {12.3f, 13.4f, 14.5f, 15.6f},
        {-16.7f, 17.8f, 18.9f, -19.0f}
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
        // Random matrix #1
        {
            0.5f, 1.0f, 1.5f, 2.0f,
            2.5f, 3.0f, 3.5f, 4.0f,
            4.5f, 5.0f, 5.5f, 6.0f,
            6.5f, 7.0f, 7.5f, 8.0f
        },
        // Random matrix #2
        {
            -1.0f, -2.0f, -3.0f, -4.0f,
            -5.0f, -6.0f, -7.0f, -8.0f,
            -9.0f, -10.0f, -11.0f, -12.0f,
            -13.0f, -14.0f, -15.0f, -16.0f
        },
        // Random matrix #3
        {
            1.1f, 2.2f, 3.3f, 4.4f,
            5.5f, 6.6f, 7.7f, 8.8f,
            9.9f, 10.0f, 11.1f, 12.2f,
            13.3f, 14.4f, 15.5f, 16.6f
        }
    };
}

plg::vec2 MockVec2() { return {1.0f, 2.0f}; }
plg::vec3 MockVec3() { return {1.0f, 2.0f, 3.0f}; }
plg::vec4 MockVec4() { return {1.0f, 2.0f, 3.0f, 4.0f}; }

plg::mat4x4 MockMat4x4() {
    return {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
}

// Mock implementations for 1 parameter functions
int32_t MockFunc1(const plg::vec3 &v) {
    const auto buffer = std::format("{}{}{}", v.x, v.y, v.z);
    return static_cast<int32_t>(v.x + v.y + v.z);
}

// Mock implementations for 2 parameter functions
char MockFunc2(float a, int64_t b) {
    const auto buffer = std::format("{}{}", a, b);
    return '&';
}

// Mock implementations for 3 parameter functions
void MockFunc3(void *p, const plg::vec4 &v, const plg::string &s) {
    const auto buffer = std::format("{}{}{}{}{}{}", p, v.x, v.y, v.z, v.w, s);
}

// Mock implementations for 4 parameter functions
plg::vec4 MockFunc4(bool flag, int32_t u, char16_t c, const plg::mat4x4 &m) {
    const auto buffer = std::format("{}{}{}{}", flag, u, static_cast<uint16_t>(c), m.m[3][3]);
    return {1.0f, 2.0f, 3.0f, 4.0f}; // Returning a dummy const plg::vec4
}

// Mock implementations for 5 parameter functions
bool MockFunc5(int8_t i, const plg::vec2 &v, void *p, double d, const plg::vector<uint64_t> &vec) {
    const auto buffer = std::format("{}{}{}{}{}{}", i, v.x, v.y, p, d, vec.size());
    return true; // Returning dummy bool
}

// Mock implementations for 6 parameter functions
int64_t MockFunc6(const plg::string &s, float f, const plg::vector<float> &vec, int16_t i,
                  const plg::vector<uint8_t> &uVec, void *p) {
    const auto buffer = std::format("{}{}{}{}{}{}", s, f, vec.size(), i, uVec.size(), p);
    return static_cast<int64_t>(f + i); // Returning a dummy int64_t
}

// Mock implementations for 7 parameter functions
double MockFunc7(const plg::vector<char> &vec, uint16_t u, char16_t c, const plg::vector<uint32_t> &uVec,
                 const plg::vec4 &v, bool flag, uint64_t l) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", vec.size(), u, static_cast<uint16_t>(c), uVec.size(), v.x,
                                    v.y, v.z, v.w, flag, l);
    return 3.14; // Returning dummy double
}

// Mock implementations for 8 parameter functions
plg::mat4x4 MockFunc8(const plg::vec3 &v, const plg::vector<uint32_t> &uVec, int16_t i, bool flag, const plg::vec4 &v4,
                      const plg::vector<char16_t> &cVec, char16_t c, int32_t a) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", v.x, v.y, v.z, uVec.size(), i, flag, v4.w, cVec.size(),
                                    static_cast<uint16_t>(c), a);
    return {}; // Returning a dummy const plg::mat4x4
}

// Mock implementations for 9 parameter functions
void MockFunc9(float f, const plg::vec2 &v, const plg::vector<int8_t> &iVec, uint64_t l, bool flag,
               const plg::string &s, const plg::vec4 &v4, int16_t i, void *p) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", f, v.x, v.y, iVec.size(), l, flag, s, v4.w, i, p);
}

// Mock implementations for 10 parameter functions
uint32_t MockFunc10(const plg::vec4 &v4, const plg::mat4x4 &m, const plg::vector<uint32_t> &uVec, uint64_t l,
                    const plg::vector<char> &cVec, int32_t a, bool flag, const plg::vec2 &v, int64_t i, double d) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{}{}", v4.x, v4.y, v4.z, v4.w, m.m[3][3], uVec.size(), l,
                                    cVec.size(), a, flag, v.x, v.y, i, d);
    return 42; // Returning dummy uint32_t
}

// Mock implementations for 11 parameter functions
void *MockFunc11(const plg::vector<bool> &bVec, char16_t c, uint8_t u, double d, const plg::vec3 &v3,
                 const plg::vector<int8_t> &iVec, int64_t i, uint16_t u16, float f, const plg::vec2 &v, uint32_t u32) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", bVec.size(), static_cast<uint16_t>(c), u, d, v3.x,
                                    iVec.size(), i, u16, f, v.x, u32);
    return 0; // Returning dummy void*
}

// Mock implementations for 12 parameter functions
bool MockFunc12(void *p, const plg::vector<double> &dVec, uint32_t u, double d, bool flag, int32_t a, int8_t i,
                uint64_t l, float f, const plg::vector<void *> &pVec, int64_t i64, char c) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}", p, dVec.size(), u, d, flag, a, i, l, f, pVec.size(),
                                    i64, c);
    return false; // Returning dummy bool
}

// Mock implementations for 13 parameter functions
plg::string MockFunc13(int64_t i64, const plg::vector<char> &cVec, uint16_t u16, float f, const plg::vector<bool> &bVec,
                       const plg::vec4 &v4, const plg::string &s, int32_t a, const plg::vec3 &v3, void *p,
                       const plg::vec2 &v2, const plg::vector<uint8_t> &u8Vec, int16_t i16) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", i64, cVec.size(), u16, f, bVec.size(), v4.z, s, a, v3.x, p,
                                    v2.x, u8Vec.size(), i16);
    return "Dummy String"; // Returning dummy string
}

// Mock implementations for 14 parameter functions
plg::vector<plg::string> MockFunc14(const plg::vector<char> &cVec, const plg::vector<uint32_t> &uVec,
                                    const plg::mat4x4 &m, bool flag, char16_t c, int32_t a,
                                    const plg::vector<float> &fVec, uint16_t u16, const plg::vector<uint8_t> &u8Vec,
                                    int8_t i8, const plg::vec3 &v3, const plg::vec4 &v4, double d, void *p) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}", cVec.size(), uVec.size(), m.m[3][3], flag,
                                    static_cast<uint16_t>(c), a, fVec.size(), u16, u8Vec.size(), i8, v3.x, v4.x, d, p);
    return {"String1", "String2"}; // Returning dummy vector of strings
}

// Mock implementations for 15 parameter functions
int16_t MockFunc15(const plg::vector<int16_t> &iVec, const plg::mat4x4 &m, const plg::vec4 &v4, void *p, uint64_t l,
                   const plg::vector<uint32_t> &uVec, bool flag, float f, const plg::vector<char16_t> &cVec, uint8_t u,
                   int32_t a, const plg::vec2 &v2, uint16_t u16, double d, const plg::vector<uint8_t> &u8Vec) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}", iVec.size(), m.m[3][3], v4.x, p, l, uVec.size(), flag, f,
                                    cVec.size(), u, a, v2.x, u16, d, u8Vec.size());
    return 257; // Returning dummy int16_t
}

// Mock implementations for 16 parameter functions
void *MockFunc16(const plg::vector<bool> &bVec, int16_t i16, const plg::vector<int8_t> &iVec, const plg::vec4 &v4,
                 const plg::mat4x4 &m, const plg::vec2 &v2, const plg::vector<uint64_t> &uVec,
                 const plg::vector<char> &cVec, const plg::string &s, int64_t i64, const plg::vector<uint32_t> &u32Vec,
                 const plg::vec3 &v3, float f, double d, int8_t i8, uint16_t u16) {
    const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}", i16, bVec.size(), iVec.size(), v4.x, v4.y, v4.z,
                                    v4.w, m.m[3][3], v2.x, uVec.size(), cVec.size(), s, i64, u32Vec.size(), v3.x, f, d,
                                    i8, u16);
    return 0; // Returning dummy void*
}

// Mock implementations for 17 parameter functions
void MockFunc17(int32_t &ref) {
    ref += 10; // Modifying the reference
}

// Mock implementations for 18 parameter functions
plg::vec2 MockFunc18(int8_t &i8, int16_t &i16) {
    i8 = 5; // Setting a value for int8_t reference
    i16 = 10; // Setting a value for int16_t reference
    return {static_cast<float>(i8), static_cast<float>(i16)}; // Returning dummy plg::vec2
}

// Mock implementations for 19 parameter functions
void MockFunc19(uint32_t &u32, plg::vec3 &v3, plg::vector<uint32_t> &uVec) {
    u32 = 42; // Setting a value for uint32_t reference
    v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
    uVec = {1, 2, 3}; // Setting values for plg::vector<uint32_t>
}

// Mock implementations for 20 parameter functions
int32_t MockFunc20(char16_t &c, plg::vec4 &v4, plg::vector<uint64_t> &uVec, char &ch) {
    c = u't'; // Setting a value for char16_t reference
    v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    uVec = {100, 200}; // Setting values for plg::vector<uint64_t>
    ch = 'F';
    return 0; // Returning dummy int32_t
}

// Mock implementations for 21 parameter functions
float MockFunc21(plg::mat4x4 &m, plg::vector<int32_t> &iVec, plg::vec2 &v2, bool &flag, double &d) {
    flag = true; // Setting a value for bool reference
    d = 3.14; // Setting a value for double reference
    v2 = {1.0f, 2.0f}; // Setting a value for plg::vec2 reference
    m = {
        1.3f, 0.6f, 0.8f, 0.5f, // Row 0
        0.7f, 1.1f, 0.2f, 0.4f, // Row 1
        0.9f, 0.3f, 1.2f, 0.7f, // Row 2
        0.2f, 0.8f, 0.5f, 1.0f // Row 3
    }; // Setting a value for plg::mat4x4 reference
    iVec = {1, 2, 3}; // Setting values for plg::vector<int32_t>
    return 0.0f; // Returning dummy float
}

// Mock implementations for 22 parameter functions
uint64_t MockFunc22(void *&p, uint32_t &u32, plg::vector<double> &dVec, int16_t &i16, plg::string &s, plg::vec4 &v4) {
    //std::cout << "MockFunc22 called with uint32_t: " << u32 << ", int16_t: " << i16 << "\n";
    p = nullptr; // Setting a value for void* reference
    u32 = 99; // Setting a value for uint32_t reference
    i16 = 123; // Setting a value for int16_t reference
    s = "Hello"; // Setting a value for string reference
    v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    dVec = {1.1, 2.2, 3.3}; // Setting values for plg::vector<double>
    return 0; // Returning dummy uint64_t
}

// Mock implementations for 23 parameter functions
void MockFunc23(uint64_t &u64, plg::vec2 &v2, plg::vector<int16_t> &iVec, char16_t &c, float &f, int8_t &i8,
                plg::vector<uint8_t> &u8Vec) {
    //std::cout << "MockFunc23 called with float: " << f << ", int8_t: " << static_cast<int>(i8) << "\n";
    u64 = 50; // Setting a value for uint64_t reference
    f = 1.5f; // Setting a value for float reference
    i8 = -1; // Setting a value for int8_t reference
    v2 = {3.0f, 4.0f}; // Setting a value for plg::vec2 reference
    u8Vec = {1, 2, 3}; // Setting values for plg::vector<uint8_t>
    c = L'Ⅴ';
    iVec = {1, 2, 3, 4};
}

// Mock implementations for 24 parameter functions
plg::mat4x4 MockFunc24(plg::vector<char> &cVec, int64_t &i64, plg::vector<uint8_t> &u8Vec, plg::vec4 &v4, uint64_t &u64,
                       plg::vector<void *> &pVec, double &d, plg::vector<void *> &vVec) {
    //std::cout << "MockFunc24 called with int64_t: " << i64 << ", double: " << d << "\n";
    i64 = 64; // Setting a value for int64_t reference
    d = 2.71; // Setting a value for double reference
    v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    cVec = {'a', 'b', 'c'}; // Setting values for plg::vector<char>
    u8Vec = {5, 6, 7}; // Setting values for plg::vector<uint8_t>
    pVec = {nullptr}; // Setting values for plg::vector<void*>
    vVec = {
        reinterpret_cast<void *>(1), reinterpret_cast<void *>(1), reinterpret_cast<void *>(2),
        reinterpret_cast<void *>(2)
    }; // Setting values for plg::vector<void*>
    u64 = 0xffffffff;
    return {}; // Returning dummy plg::mat4x4
}

// Mock implementations for 25 parameter functions
double MockFunc25(int32_t &i32, plg::vector<void *> &pVec, bool &flag, uint8_t &u8, plg::string &s, plg::vec3 &v3,
                  int64_t &i64, plg::vec4 &v4, uint16_t &u16) {
    //std::cout << "MockFunc25 called with bool: " << flag << ", int32_t: " << i32 << "\n";
    flag = false; // Setting a value for bool reference
    i32 = 100; // Setting a value for int32_t reference
    u8 = 250; // Setting a value for uint8_t reference
    v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
    v4 = {4.0f, 5.0f, 6.0f, 7.0f}; // Setting a value for plg::vec4 reference
    s = "MockFunc25"; // Setting a value for string reference
    pVec = {nullptr}; // Setting values for plg::vector<void*>
    i64 = 1337;
    u16 = 64222;
    return 0.0; // Returning dummy double
}

// Mock implementations for 26 parameter functions
char MockFunc26(char16_t &c, plg::vec2 &v2, plg::mat4x4 &m, plg::vector<float> &fVec, int16_t &i16, uint64_t &u64,
                uint32_t &u32, plg::vector<uint16_t> &u16Vec, void *&p, bool &flag) {
    //std::cout << "MockFunc26 called with char16: " << c << ", bool: " << flag << "\n";
    c = u'Z'; // Setting a value for char16_t reference
    flag = true; // Setting a value for bool reference
    v2 = {2.0f, 3.0f}; // Setting a value for plg::vec2 reference
    m = {
        0.9f, 0.2f, 0.4f, 0.8f, // Row 0
        0.1f, 1.0f, 0.6f, 0.3f, // Row 1
        0.7f, 0.5f, 0.2f, 0.9f, // Row 2
        0.3f, 0.4f, 1.5f, 0.1f // Row 3
    }; // Setting a value for plg::mat4x4 reference
    fVec = {1.1f, 2.2f}; // Setting values for plg::vector<float>
    u64 = 64; // Setting a value for uint64_t reference
    u32 = 32; // Setting a value for uint32_t reference
    u16Vec = {100, 200}; // Setting values for plg::vector<uint16_t>
    i16 = 332;
    p = reinterpret_cast<void *>(0xDEADBEAFDEADBEAF);
    return 'A'; // Returning dummy char
}

// Mock implementations for 27 parameter functions
uint8_t MockFunc27(float &f, plg::vec3 &v3, void *&p, plg::vec2 &v2, plg::vector<int16_t> &i16Vec, plg::mat4x4 &m,
                   bool &flag, plg::vec4 &v4, int8_t &i8, int32_t &i32, plg::vector<uint8_t> &u8Vec) {
    //std::cout << "MockFunc27 called with uint8_t: " << static_cast<int>(u8) << ", bool: " << flag << "\n";
    f = 1.0;
    v3 = {-1.0f, -2.0f, -3.0f};
    p = reinterpret_cast<void *>(0xDEADBEAFDEADBEAF);
    v2 = {-111.0f, 111.0f};
    i16Vec = {1, 2, 3, 4};
    m = {
        1.0f, 0.5f, 0.3f, 0.7f, // Row 0
        0.8f, 1.2f, 0.6f, 0.9f, // Row 1
        1.5f, 1.1f, 0.4f, 0.2f, // Row 2
        0.3f, 0.9f, 0.7f, 1.0f // Row 3
    };
    flag = true;
    v4 = {1.0f, 2.0f, 3.0f, 4.0f};
    i8 = 111;
    i32 = 30;
    u8Vec = {0, 0, 0, 0, 0, 0, 1, 0};
    return 0; // Returning dummy int
}

// Mock implementations for 28 parameter functions
plg::string MockFunc28(void *&ptr, uint16_t &u16, plg::vector<uint32_t> &u32Vec, plg::mat4x4 &m, float &f,
                       plg::vec4 &v4, plg::string &str, plg::vector<uint64_t> &u64Vec, int64_t &i64, bool &b,
                       plg::vec3 &vec3, plg::vector<float> &fVec) {
    //std::cout << "MockFunc28 called with float: " << f << "\n";
    ptr = nullptr;
    u16 = 65500;
    u32Vec = {1, 2, 3, 4, 5, 7};
    m = {
        1.4f, 0.7f, 0.2f, 0.5f, // Row 0
        0.3f, 1.1f, 0.6f, 0.8f, // Row 1
        0.9f, 0.4f, 1.3f, 0.1f, // Row 2
        0.6f, 0.2f, 0.7f, 1.0f // Row 3
    };
    f = 5.5f; // Setting a value for float reference
    v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    u64Vec = {1, 2}; // Setting values for plg::vector<int16_t>
    i64 = 834748377834;
    b = true,
            vec3 = {10, 20, 30}; // Setting values for plg::vector<uint32_t>
    str = "MockFunc28"; // Setting a value for string reference
    fVec = {1.0f, -1000.0f, 2000.0f};
    return str; // Returning dummy string
}

// Mock implementations for 29 parameter functions
plg::vector<plg::string> MockFunc29(plg::vec4 &v4, int32_t &i32, plg::vector<int8_t> &iVec, double &d, bool &flag,
                                    int8_t &i8, plg::vector<uint16_t> &u16Vec, float &f, plg::string &s, plg::mat4x4 &m,
                                    uint64_t &u64, plg::vec3 &v3, plg::vector<int64_t> &i64Vec) {
    //std::cout << "MockFunc29 called with int32_t: " << i32 << ", bool: " << flag << "\n";
    i32 = 30; // Setting a value for int32_t reference
    flag = true; // Setting a value for bool reference
    v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    d = 3.14; // Setting a value for double reference
    i8 = 8; // Setting a value for int8_t reference
    u16Vec = {100, 200}; // Setting values for plg::vector<uint16_t>
    f = 1.5f; // Setting a value for float reference
    s = "MockFunc29"; // Setting a value for string reference
    m = {
        0.4f, 1.0f, 0.6f, 0.3f, // Row 0
        1.2f, 0.8f, 0.5f, 0.9f, // Row 1
        0.7f, 0.3f, 1.4f, 0.6f, // Row 2
        0.1f, 0.9f, 0.8f, 1.3f // Row 3
    };
    // Setting a value for plg::mat4x4 reference
    u64 = 64; // Setting a value for uint64_t reference
    v3 = {1.0f, 2.0f, 3.0f}; // Setting a value for plg::vec3 reference
    i64Vec = {1, 2, 3}; // Setting values for plg::vector<int64_t>
    iVec = {127, 126, 125};
    return {"Example", "MockFunc29"}; // Returning dummy vector of strings
}

// Mock implementations for 30 parameter functions
int32_t MockFunc30(void *&p, plg::vec4 &v4, int64_t &i64, plg::vector<uint32_t> &uVec, bool &flag, plg::string &s,
                   plg::vec3 &v3, plg::vector<uint8_t> &u8Vec, float &f, plg::vec2 &v2, plg::mat4x4 &m, int8_t &i8,
                   plg::vector<float> &vVec, double &d) {
    //std::cout << "MockFunc30 called with int64_t: " << i64 << ", bool: " << flag << "\n";
    flag = false; // Setting a value for bool reference
    f = 1.1f; // Setting a value for float reference
    i64 = 1000; // Setting a value for int64_t reference
    v2 = {3.0f, 4.0f}; // Setting a value for plg::vec2 reference
    v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // Setting a value for plg::vec4 reference
    s = "MockFunc30"; // Setting a value for string reference
    p = nullptr; // Setting a value for void* reference
    uVec = {100, 200}; // Setting values for plg::vector<uint32_t>
    m = {
        0.5f, 0.3f, 1.0f, 0.7f, // Row 0
        1.1f, 0.9f, 0.6f, 0.4f, // Row 1
        0.2f, 0.8f, 1.5f, 0.3f, // Row 2
        0.7f, 0.4f, 0.9f, 1.0f // Row 3
    }; // Setting a value for plg::mat4x4 reference
    i8 = 8; // Setting a value for int8_t reference
    vVec = {1.0f, 1.0f, 2.0f, 2.0f}; // Setting values for plg::vector<float>
    d = 2.718; // Setting a value for double reference
    v3 = {1, 2, 3};
    u8Vec = {255, 0, 255, 200, 100, 200};
    return 42; // Returning dummy int32_t
}

// Mock implementations for 31 parameter functions
plg::vec3 MockFunc31(char &c, uint32_t &u32, plg::vector<uint64_t> &uVec, plg::vec4 &v4, plg::string &s, bool &flag,
                     int64_t &i64, plg::vec2 &v2, int8_t &i8, uint16_t &u16, plg::vector<int16_t> &iVec, plg::mat4x4 &m,
                     plg::vec3 &v3, float &f, plg::vector<double> &v4Vec) {
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
    iVec = {1, 2}; // Setting values for plg::vector<int16_t>
    m = {
        0.8f, 0.5f, 1.2f, 0.3f, // Row 0
        1.0f, 0.7f, 0.4f, 0.6f, // Row 1
        0.9f, 0.2f, 0.5f, 1.4f, // Row 2
        0.6f, 0.8f, 1.1f, 0.7f // Row 3
    }; // Setting a value for plg::mat4x4 reference
    v4Vec = {1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0}; // Setting values for plg::vector<double>
    uVec = {1, 2, 3, 4, 5};
    f = -1.0f;
    return {1.0f, 1.5f, 3.0f}; // Returning dummy plg::vec3
}

// Mock implementations for 32 parameter functions
double MockFunc32(int32_t &i32, uint16_t &u16, plg::vector<int8_t> &iVec, plg::vec4 &v4, void *&p,
                  plg::vector<uint32_t> &uVec, plg::mat4x4 &m, uint64_t &u64, plg::string &s, int64_t &i64,
                  plg::vec2 &v2, plg::vector<int8_t> &u8Vec, bool &flag, plg::vec3 &v3, uint8_t &u8,
                  plg::vector<char16_t> &cVec) {
    //std::cout << "MockFunc32 called with int32_t: " << i32 << ", uint16_t: " << u16 << "\n";
    i32 = 42; // Setting a value for int32_t reference
    u16 = 255; // Setting a value for uint16_t reference
    flag = false; // Setting a value for bool reference
    v2 = {2.5f, 3.5f}; // Setting a value for plg::vec2 reference
    u8Vec = {1, 2, 3, 4, 5, 9};
    v4 = {4.0f, 5.0f, 6.0f, 7.0f}; // Setting a value for plg::vec4 reference
    s = "MockFunc32"; // Setting a value for string reference
    p = nullptr; // Setting a value for void* reference
    m = {
        1.0f, 0.4f, 0.3f, 0.9f, // Row 0
        0.7f, 1.2f, 0.5f, 0.8f, // Row 1
        0.2f, 0.6f, 1.1f, 0.4f, // Row 2
        0.9f, 0.3f, 0.8f, 1.5f // Row 3
    }; // Setting a value for plg::mat4x4 reference
    u64 = 123456789; // Setting a value for uint64_t reference
    uVec = {100, 200}; // Setting values for plg::vector<uint32_t>
    i64 = 1000; // Setting a value for int64_t reference
    v3 = {0.0f, 0.0f, 0.0f}; // Setting a value for plg::vec3 reference
    u8 = 8; // Setting a value for uint8_t reference
    cVec = {u'a', u'b', u'c'}; // Setting values for plg::vector<char16_t>
    iVec = {0, 1};
    return 1.0; // Returning dummy double
}

// Mock implementations for 1 parameter functions
void MockFunc33(plg::any &variant) {
    variant = "MockFunc33";
}

// Mock implementations for enum parameters functions
plg::vector<cross_call_master::Example> MockFuncEnum(cross_call_master::Example p1,
                                                     plg::vector<cross_call_master::Example> &p2) {
    p2 = {cross_call_master::Example::First, cross_call_master::Example::Second, cross_call_master::Example::Third};
    return {p1, cross_call_master::Example::Forth};
}

// Mock implementation for alias parameters functions


cross_call_master::AliasBool MockFuncAliasBool() { return true; }
cross_call_master::AliasChar8 MockFuncAliasChar8() { return 'A'; }
cross_call_master::AliasChar16 MockFuncAliasChar16() { return u'Z'; }
cross_call_master::AliasInt8 MockFuncAliasInt8() { return 10; }
cross_call_master::AliasInt16 MockFuncAliasInt16() { return 100; }
cross_call_master::AliasInt32 MockFuncAliasInt32() { return 1000; }
cross_call_master::AliasInt64 MockFuncAliasInt64() { return 10000; }
cross_call_master::AliasUInt8 MockFuncAliasUInt8() { return 20; }
cross_call_master::AliasUInt16 MockFuncAliasUInt16() { return 200; }
cross_call_master::AliasUInt32 MockFuncAliasUInt32() { return 2000; }
cross_call_master::AliasUInt64 MockFuncAliasUInt64() { return 20000; }
cross_call_master::AliasPtr MockFuncAliasPtr() { return nullptr; }
cross_call_master::AliasFloat MockFuncAliasFloat() { return 3.14f; }
cross_call_master::AliasDouble MockFuncAliasDouble() { return 6.28; }
cross_call_master::AliasFunction MockFuncAliasFunction() { return nullptr; }
cross_call_master::AliasString MockFuncAliasString() { return "Test string"; }
cross_call_master::AliasAny MockFuncAliasAny() { return L'A'; }

cross_call_master::AliasBoolVector MockFuncAliasBoolVector() { return {true, false}; }
cross_call_master::AliasChar8Vector MockFuncAliasChar8Vector() { return {'A', 'B'}; }
cross_call_master::AliasChar16Vector MockFuncAliasChar16Vector() { return {u'A', u'B'}; }
cross_call_master::AliasInt8Vector MockFuncAliasInt8Vector() { return {10, 20}; }
cross_call_master::AliasInt16Vector MockFuncAliasInt16Vector() { return {100, 200}; }
cross_call_master::AliasInt32Vector MockFuncAliasInt32Vector() { return {1000, 2000}; }
cross_call_master::AliasInt64Vector MockFuncAliasInt64Vector() { return {10000, 20000}; }
cross_call_master::AliasUInt8Vector MockFuncAliasUInt8Vector() { return {20, 30}; }
cross_call_master::AliasUInt16Vector MockFuncAliasUInt16Vector() { return {200, 300}; }
cross_call_master::AliasUInt32Vector MockFuncAliasUInt32Vector() { return {2000, 3000}; }
cross_call_master::AliasUInt64Vector MockFuncAliasUInt64Vector() { return {20000, 30000}; }
cross_call_master::AliasPtrVector MockFuncAliasPtrVector() { return {nullptr, reinterpret_cast<void *>(1)}; }
cross_call_master::AliasFloatVector MockFuncAliasFloatVector() { return {1.1f, 2.2f}; }
cross_call_master::AliasDoubleVector MockFuncAliasDoubleVector() { return {3.3, 4.4}; }
cross_call_master::AliasStringVector MockFuncAliasStringVector() { return {"Hello", "World"}; }
cross_call_master::AliasAnyVector MockFuncAliasAnyVector() { return {"Hello", 3.14f, 6.28, 1, 0xDEADBEAF}; }

cross_call_master::AliasVec2Vector MockFuncAliasVec2Vector() {
    return {
        {0.5f, -1.2f},
        {3.4f, 7.8f},
        {-6.7f, 2.3f},
        {8.9f, -4.5f},
        {0.0f, 0.0f}
    };
}

cross_call_master::AliasVec3Vector MockFuncAliasVec3Vector() {
    return {
        {2.1f, 3.2f, 4.3f},
        {-5.4f, 6.5f, -7.6f},
        {8.7f, 9.8f, 0.1f},
        {1.2f, -3.3f, 4.4f},
        {-5.5f, 6.6f, -7.7f}
    };
}

cross_call_master::AliasVec4Vector MockFuncAliasVec4Vector() {
    return {
        {0.1f, 1.2f, 2.3f, 3.4f},
        {-4.5f, 5.6f, 6.7f, -7.8f},
        {8.9f, -9.0f, 10.1f, -11.2f},
        {12.3f, 13.4f, 14.5f, 15.6f},
        {-16.7f, 17.8f, 18.9f, -19.0f}
    };
}

cross_call_master::AliasMat4x4Vector MockFuncAliasMat4x4Vector() {
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
            0.5f, 1.0f, 1.5f, 2.0f,
            2.5f, 3.0f, 3.5f, 4.0f,
            4.5f, 5.0f, 5.5f, 6.0f,
            6.5f, 7.0f, 7.5f, 8.0f
        },
        // Random matrix #2
        {
            -1.0f, -2.0f, -3.0f, -4.0f,
            -5.0f, -6.0f, -7.0f, -8.0f,
            -9.0f, -10.0f, -11.0f, -12.0f,
            -13.0f, -14.0f, -15.0f, -16.0f
        },
        // Random matrix #3
        {
            1.1f, 2.2f, 3.3f, 4.4f,
            5.5f, 6.6f, 7.7f, 8.8f,
            9.9f, 10.0f, 11.1f, 12.2f,
            13.3f, 14.4f, 15.5f, 16.6f
        }
    };
}

cross_call_master::AliasVec2 MockFuncAliasVec2() { return {1.0f, 2.0f}; }
cross_call_master::AliasVec3 MockFuncAliasVec3() { return {1.0f, 2.0f, 3.0f}; }
cross_call_master::AliasVec4 MockFuncAliasVec4() { return {1.0f, 2.0f, 3.0f, 4.0f}; }

cross_call_master::AliasMat4x4 MockFuncAliasMat4x4() {
    return {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
}

plg::string MockFuncAliasAll(
    cross_call_master::AliasBool          aBool,
    cross_call_master::AliasChar8         aChar8,
    cross_call_master::AliasChar16        aChar16,
    cross_call_master::AliasInt8          aInt8,
    cross_call_master::AliasInt16         aInt16,
    cross_call_master::AliasInt32         aInt32,
    cross_call_master::AliasInt64         aInt64,
    cross_call_master::AliasPtr           aPtr,
    cross_call_master::AliasFloat         aFloat,
    cross_call_master::AliasDouble        aDouble,
    const cross_call_master::AliasString&       aString,
    const cross_call_master::AliasAny&          aAny,
    const cross_call_master::AliasVec2&         aVec2,
    const cross_call_master::AliasVec3&         aVec3,
    const cross_call_master::AliasVec4&         aVec4,
    const cross_call_master::AliasMat4x4&       aMat4x4,
    const cross_call_master::AliasBoolVector&   aBoolVec,
    const cross_call_master::AliasChar8Vector&  aChar8Vec,
    const cross_call_master::AliasChar16Vector& aChar16Vec,
    const cross_call_master::AliasInt8Vector&   aInt8Vec,
    const cross_call_master::AliasInt16Vector&  aInt16Vec,
    const cross_call_master::AliasInt32Vector&  aInt32Vec,
    const cross_call_master::AliasInt64Vector&  aInt64Vec,
    const cross_call_master::AliasPtrVector&    aPtrVec,
    const cross_call_master::AliasFloatVector&  aFloatVec,
    const cross_call_master::AliasDoubleVector& aDoubleVec,
    const cross_call_master::AliasStringVector& aStringVec,
    const cross_call_master::AliasAnyVector&    aAnyVec,
    const cross_call_master::AliasVec2Vector&   aVec2Vec,
    const cross_call_master::AliasVec3Vector&   aVec3Vec,
    const cross_call_master::AliasVec4Vector&   aVec4Vec,
    const cross_call_master::AliasMat4x4Vector& aMat4x4Vec
) {
    return std::format(
        "{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}",
        aBool,
        aChar8,
        static_cast<uint16_t>(aChar16),
        aInt8,
        aInt16,
        aInt32,
        aInt64,
        aPtr,
        aFloat,
        aDouble,
        aString,
        aAny,
        aVec2,
        aVec3,
        aVec4,
        aMat4x4,
        aBoolVec,
        aChar8Vec,
        aChar16Vec,
        aInt8Vec,
        aInt16Vec,
        aInt32Vec,
        aInt64Vec,
        aPtrVec,
        aFloatVec,
        aDoubleVec,
        aStringVec,
        aAnyVec,
        aVec2Vec,
        aVec3Vec,
        aVec4Vec,
        aMat4x4Vec
    );
}

class TestClass {
private:
    // Conditional logging - only in debug builds
    static void Log([[maybe_unused]] const plg::string& message) {
#ifdef VERBOSE
        std::println("{}", message);
#endif
    }
public:
    static plg::string BasicLifecycle() {
        Log("TEST 1: Basic Lifecycle");
        Log("_______________________");

        int32_t initialAlive = cross_call_master::ResourceHandle::GetAliveCount();
        int32_t initialCreated = cross_call_master::ResourceHandle::GetTotalCreated();

        {
            cross_call_master::ResourceHandle resource(1, "Test1");

            Log(std::format("v Created ResourceHandle ID: {}", resource.GetId()));
            Log(std::format("v Alive count increased: {}", cross_call_master::ResourceHandle::GetAliveCount()));
        }

        int32_t finalAlive = cross_call_master::ResourceHandle::GetAliveCount();
        int32_t finalCreated = cross_call_master::ResourceHandle::GetTotalCreated();
        int32_t finalDestroyed = cross_call_master::ResourceHandle::GetTotalDestroyed();

        Log(std::format("v Destructor called, alive count: {}", finalAlive));
        Log(std::format("v Total created: {}", finalCreated - initialCreated));
        Log(std::format("v Total destroyed: {}", finalDestroyed));

        if (finalAlive == initialAlive && finalCreated == finalDestroyed) {
            Log("v TEST 1 PASSED: Lifecycle working correctly\n");
            return "true";
        } else {
            Log("x TEST 1 FAILED: Lifecycle mismatch!\n");
            return "false";
        }
    }

    static plg::string StateManagement() {
        Log("TEST 2: State Management");
        Log("________________________");

        cross_call_master::ResourceHandle resource(2, "StateTest");

        resource.IncrementCounter();
        resource.IncrementCounter();
        resource.IncrementCounter();
        int32_t counter = resource.GetCounter();
        Log(std::format("v Counter incremented 3 times: {}", counter));

        resource.SetName("StateTestModified");
        plg::string newName = resource.GetName();
        Log(std::format("v Name changed to: {}", newName));

        resource.AddData(1.1f);
        resource.AddData(2.2f);
        resource.AddData(3.3f);
        plg::vector<float> data = resource.GetData();
        Log(std::format("v Added {} data points", data.size()));

        if (counter == 3 && newName == "StateTestModified" && data.size() == 3) {
            Log("v TEST 2 PASSED: State management working\n");
            return "true";
        } else {
            Log("x TEST 2 FAILED: State not preserved!\n");
            return "false";
        }
    }

    static plg::string MultipleInstances() {
        Log("TEST 3: Multiple Instances");
        Log("__________________________");

        int32_t beforeAlive = cross_call_master::ResourceHandle::GetAliveCount();

        {
            cross_call_master::ResourceHandle r1(10, "Instance1");
            cross_call_master::ResourceHandle r2(20, "Instance2");
            cross_call_master::ResourceHandle r3;

            int32_t duringAlive = cross_call_master::ResourceHandle::GetAliveCount();
            Log(std::format("v Created 3 instances, alive: {}", duringAlive));
            Log(std::format("v R1 ID: {}, R2 ID: {}, R3 ID: {}", r1.GetId(), r2.GetId(), r3.GetId()));

            if (duringAlive - beforeAlive == 3) {
                Log("v All 3 instances tracked correctly");
            }
        }

        int32_t afterAlive = cross_call_master::ResourceHandle::GetAliveCount();

        if (afterAlive == beforeAlive) {
            Log("v TEST 3 PASSED: All instances destroyed properly\n");
            return "true";
        } else {
            Log(std::format("x TEST 3 FAILED: Leak detected! Before: {}, After: {}\n", beforeAlive, afterAlive));
            return "false";
        }
    }

    static plg::string CounterWithoutDestructor() {
        Log("TEST 4: Counter (No Destructor)");
        Log("________________________________");

        cross_call_master::Counter counter(100);
        Log(std::format("v Created Counter with value: {}", counter.GetValue()));

        counter.Increment();
        counter.Increment();
        counter.Add(50);
        int64_t value = counter.GetValue();
        Log(std::format("v After operations, value: {}", value));

        bool isPositive = counter.IsPositive();
        Log(std::format("v Is positive: {}", isPositive));

        if (value == 152 && isPositive) {
            Log("v TEST 4 PASSED: Counter operations working\n");
            return "true";
        } else {
            Log("x TEST 4 FAILED: Counter operations incorrect\n");
            return "false";
        }
    }

    static plg::string StaticMethods() {
        Log("TEST 5: Static Methods");
        Log("______________________");

        int32_t alive = cross_call_master::ResourceHandle::GetAliveCount();
        int32_t created = cross_call_master::ResourceHandle::GetTotalCreated();
        int32_t destroyed = cross_call_master::ResourceHandle::GetTotalDestroyed();
        Log(std::format("v ResourceHandle stats - Alive: {}, Created: {}, Destroyed: {}", alive, created, destroyed));

        int32_t cmp1 = cross_call_master::Counter::Compare(100, 50);
        int32_t cmp2 = cross_call_master::Counter::Compare(50, 100);
        int32_t cmp3 = cross_call_master::Counter::Compare(50, 50);
        Log(std::format("v Counter.Compare(100, 50) = {} (expected 1)", cmp1));
        Log(std::format("v Counter.Compare(50, 100) = {} (expected -1)", cmp2));
        Log(std::format("v Counter.Compare(50, 50) = {} (expected 0)", cmp3));

        plg::vector<int64_t> values = {1, 2, 3, 4, 5};
        int64_t sum = cross_call_master::Counter::Sum(values);
        Log(std::format("v Counter.Sum([1,2,3,4,5]) = {} (expected 15)", sum));

        if (cmp1 == 1 && cmp2 == -1 && cmp3 == 0 && sum == 15) {
            Log("v TEST 5 PASSED: Static methods working\n");
            return "true";
        } else {
            Log("x TEST 5 FAILED: Static methods incorrect\n");
            return "false";
        }
    }

    static plg::string MemoryLeakDetection() {
        Log("TEST 6: Memory Leak Detection");
        Log("______________________________");

        int32_t beforeAlive = cross_call_master::ResourceHandle::GetAliveCount();

        {
            cross_call_master::ResourceHandle leaked(999, "IntentionalLeak");
            Log(std::format("v Created resource ID: {}", leaked.GetId()));
        }

        int32_t afterAlive = cross_call_master::ResourceHandle::GetAliveCount();

        Log(std::format("v Before leak test: {} alive", beforeAlive));
        Log(std::format("v After release: {} alive", afterAlive));

        if (afterAlive == beforeAlive) {
    		Log("v TEST 6 PASSED: Destructor cleaned up leaked resource\n");
            return "true";
        } else {
    		Log("x TEST 6 FAILED: Resource still alive (FATAL)\n");
            return "false";
        }
    }

    static plg::string ExceptionHandling() {
        Log("TEST 7: Exception Handling");
        Log("__________________________");

        try {
            cross_call_master::ResourceHandle resource(777, "ExceptionTest");
            resource.reset();
            resource.GetId();
            Log("x TEST 7 FAILED: No exception thrown!\n");
            return "false";
        }
        catch (const std::runtime_error& ex) {
            Log(std::format("v Caught expected exception: {}", ex.what()));
            Log("v TEST 7 PASSED: Exception handling working\n");
            return "true";
        }
    }

	static plg::string OwnershipTransfer() {
    	Log("TEST 7: Ownership Transfer (get + release)");
    	Log("_________________________________________");

    	int initial_alive = cross_call_master::ResourceHandle::GetAliveCount();
    	[[maybe_unused]] int initial_created = cross_call_master::ResourceHandle::GetTotalCreated();

    	cross_call_master::ResourceHandle resource(42, "OwnershipTest");
    	Log(std::format("v Created ResourceHandle ID: {}", resource.GetId()));

    	// Get internal wrapper (simulate internal pointer access)
    	auto* wrapper = resource.get();
    	Log(std::format("v get() returned internal wrapper: {}",
						reinterpret_cast<uintptr_t>(wrapper)));

    	// Release ownership
    	auto* handle = resource.release();
    	Log(std::format("v release() returned handle: {}",
						reinterpret_cast<uintptr_t>(handle)));

    	if (wrapper != handle) {
    		Log("x TEST 7 FAILED: get() did not return internal wrapper");
    		return "false";
    	}

    	try {
    		resource.GetId();
    		Log("x TEST 7 FAILED: ResourceHandle still accessible after release()");
    		return "false";
    	} catch (const std::exception&) {
    		Log("v ResourceHandle is invalid after release()");
    	}

    	// Check that handle is now owned externally and alive count updated correctly
    	int alive_after_release = cross_call_master::ResourceHandle::GetAliveCount();
    	if (alive_after_release != initial_alive + 1) {
    		Log(std::format("x TEST 7 FAILED: Alive count mismatch after release. "
							"Expected {}, got {}",
							initial_alive + 1, alive_after_release));
    		return "false";
    	}

    	cross_call_master::ResourceHandleDestroy(handle);

    	Log("v TEST 7 PASSED: Ownership transfer working correctly\n");
    	return "true";
    }
};

extern "C"
PLUGIN_API void ReverseCall(const plg::string &test) {
    static std::unordered_map<plg::string, void(*)()> tests{
        {
            "NoParamReturnVoid", [] {
                cross_call_master::NoParamReturnVoidCallback();
            }
        },
        {
            "NoParamReturnBool", [] {
                const auto result = cross_call_master::NoParamReturnBoolCallback();
                cross_call_master::ReverseReturn(result == true
                                                     ? "true"
                                                     : (result == false ? "false" : "<wrong return>"));
            }
        },
        {
            "NoParamReturnChar8", [] {
                const auto result = cross_call_master::NoParamReturnChar8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnChar16", [] {
                const auto result = cross_call_master::NoParamReturnChar16Callback();
                cross_call_master::ReverseReturn(std::format("{}", static_cast<uint16_t>(result)));
            }
        },
        {
            "NoParamReturnInt8", [] {
                const auto result = cross_call_master::NoParamReturnInt8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnInt16", [] {
                const auto result = cross_call_master::NoParamReturnInt16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnInt32", [] {
                const auto result = cross_call_master::NoParamReturnInt32Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnInt64", [] {
                const auto result = cross_call_master::NoParamReturnInt64Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnUInt8", [] {
                const auto result = cross_call_master::NoParamReturnUInt8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnUInt16", [] {
                const auto result = cross_call_master::NoParamReturnUInt16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnUInt32", [] {
                const auto result = cross_call_master::NoParamReturnUInt32Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnUInt64", [] {
                const auto result = cross_call_master::NoParamReturnUInt64Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnPointer", [] {
                const auto result = cross_call_master::NoParamReturnPointerCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnFloat", [] {
                const auto result = cross_call_master::NoParamReturnFloatCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnDouble", [] {
                const auto result = cross_call_master::NoParamReturnDoubleCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnFunction", [] {
                const auto result = cross_call_master::NoParamReturnFunctionCallback();
                cross_call_master::ReverseReturn(result ? std::format("{}", result()) : "<null function pointer>");
            }
        },
        {
            "NoParamReturnString", [] {
                const auto result = cross_call_master::NoParamReturnStringCallback();
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "NoParamReturnAny", [] {
                const auto result = cross_call_master::NoParamReturnAnyCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayBool", [] {
                const auto result = cross_call_master::NoParamReturnArrayBoolCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayChar8", [] {
                const auto result = cross_call_master::NoParamReturnArrayChar8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayChar16", [] {
                const auto result = cross_call_master::NoParamReturnArrayChar16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayInt8", [] {
                const auto result = cross_call_master::NoParamReturnArrayInt8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayInt16", [] {
                const auto result = cross_call_master::NoParamReturnArrayInt16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayInt32", [] {
                const auto result = cross_call_master::NoParamReturnArrayInt32Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayInt64", [] {
                const auto result = cross_call_master::NoParamReturnArrayInt64Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayUInt8", [] {
                const auto result = cross_call_master::NoParamReturnArrayUInt8Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayUInt16", [] {
                const auto result = cross_call_master::NoParamReturnArrayUInt16Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayUInt32", [] {
                const auto result = cross_call_master::NoParamReturnArrayUInt32Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayUInt64", [] {
                const auto result = cross_call_master::NoParamReturnArrayUInt64Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayPointer", [] {
                const auto result = cross_call_master::NoParamReturnArrayPointerCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayFloat", [] {
                const auto result = cross_call_master::NoParamReturnArrayFloatCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayDouble", [] {
                const auto result = cross_call_master::NoParamReturnArrayDoubleCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayString", [] {
                const auto result = cross_call_master::NoParamReturnArrayStringCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayAny", [] {
                const auto result = cross_call_master::NoParamReturnArrayAnyCallback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayVector2", [] {
                const auto result = cross_call_master::NoParamReturnArrayVector2Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayVector3", [] {
                const auto result = cross_call_master::NoParamReturnArrayVector3Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayVector4", [] {
                const auto result = cross_call_master::NoParamReturnArrayVector4Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnArrayMatrix4x4", [] {
                const auto result = cross_call_master::NoParamReturnArrayMatrix4x4Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnVector2", [] {
                const auto result = cross_call_master::NoParamReturnVector2Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnVector3", [] {
                const auto result = cross_call_master::NoParamReturnVector3Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnVector4", [] {
                const auto result = cross_call_master::NoParamReturnVector4Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "NoParamReturnMatrix4x4", [] {
                const auto result = cross_call_master::NoParamReturnMatrix4x4Callback();
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "Param1", [] {
                cross_call_master::Param1Callback(999);
            }
        },
        {
            "Param2", [] {
                cross_call_master::Param2Callback(888, 9.9f);
            }
        },
        {
            "Param3", [] {
                cross_call_master::Param3Callback(777, 8.8f, 9.8765);
            }
        },
        {
            "Param4", [] {
                cross_call_master::Param4Callback(666, 7.7f, 8.7659, {100.1f, 200.2f, 300.3f, 400.4f});
            }
        },
        {
            "Param5", [] {
                cross_call_master::Param5Callback(555, 6.6f, 7.6598, {-105.1f, -205.2f, -305.3f, -405.4f}, {});
            }
        },
        {
            "Param6", [] {
                cross_call_master::Param6Callback(444, 5.5f, 6.5987, {110.1f, 210.2f, 310.3f, 410.4f},
                                                  {90000, -100, 20000}, 'A');
            }
        },
        {
            "Param7", [] {
                cross_call_master::Param7Callback(333, 4.4f, 5.9876, {-115.1f, -215.2f, -315.3f, -415.4f},
                                                  {800000, 30000, -4000000}, 'B', "red gold");
            }
        },
        {
            "Param8", [] {
                cross_call_master::Param8Callback(222, 3.3f, 1.2345, {120.1f, 220.2f, 320.3f, 420.4f},
                                                  {7000000, 5000000, -600000000}, 'C', "blue ice", u'Z');
            }
        },
        {
            "Param9", [] {
                cross_call_master::Param9Callback(111, 2.2f, 5.1234, {-125.1f, -225.2f, -325.3f, -425.4f},
                                                  {60000000, -700000000, 80000000000}, 'D', "pink metal", u'Y', -100);
            }
        },
        {
            "Param10", [] {
                cross_call_master::Param10Callback(1234, 1.1f, 4.5123, {130.1f, 230.2f, 330.3f, 430.4f},
                                                   {500000000, 90000000000, 1000000000000}, 'E', "green wood", u'X',
                                                   -200, reinterpret_cast<void *>(0xabebaLL));
            }
        },
        {
            "ParamRef1", [] {
                int32_t a{};
                cross_call_master::ParamRef1Callback(a);
                cross_call_master::ReverseReturn(std::format("{}", a));
            }
        },
        {
            "ParamRef2", [] {
                int32_t a{};
                float b{};
                cross_call_master::ParamRef2Callback(a, b);
                cross_call_master::ReverseReturn(std::format("{}|{}", a, b));
            }
        },
        {
            "ParamRef3", [] {
                int32_t a{};
                float b{};
                double c{};
                cross_call_master::ParamRef3Callback(a, b, c);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}", a, b, c));
            }
        },
        {
            "ParamRef4", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                cross_call_master::ParamRef4Callback(a, b, c, d);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}", a, b, c, d));
            }
        },
        {
            "ParamRef5", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                plg::vector<int64_t> e{};
                cross_call_master::ParamRef5Callback(a, b, c, d, e);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}", a, b, c, d, e));
            }
        },
        {
            "ParamRef6", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                plg::vector<int64_t> e{};
                char f{};
                cross_call_master::ParamRef6Callback(a, b, c, d, e, f);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}|{}", a, b, c, d, e,
                                                             static_cast<uint8_t>(f)));
            }
        },
        {
            "ParamRef7", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                plg::vector<int64_t> e{};
                char f{};
                plg::string g{};
                cross_call_master::ParamRef7Callback(a, b, c, d, e, f, g);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e,
                                                             static_cast<uint8_t>(f), g));
            }
        },
        {
            "ParamRef8", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                plg::vector<int64_t> e{};
                char f{};
                plg::string g{};
                char16_t h{};
                cross_call_master::ParamRef8Callback(a, b, c, d, e, f, g, h);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e,
                                                             static_cast<uint8_t>(f), g, static_cast<uint16_t>(h)));
            }
        },
        {
            "ParamRef9", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                plg::vector<int64_t> e{};
                char f{};
                plg::string g{};
                char16_t h{};
                int16_t k{};
                cross_call_master::ParamRef9Callback(a, b, c, d, e, f, g, h, k);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e,
                                                             static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k));
            }
        },
        {
            "ParamRef10", [] {
                int32_t a{};
                float b{};
                double c{};
                plg::vec4 d{};
                plg::vector<int64_t> e{};
                char f{};
                plg::string g{};
                char16_t h{};
                int16_t k{};
                void *l{};
                cross_call_master::ParamRef10Callback(a, b, c, d, e, f, g, h, k, l);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", a, b, c, d, e,
                                                             static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k,
                                                             l));
            }
        },
        {
            "ParamRefArrays", [] {
                plg::vector<bool> p1{true};
                plg::vector<char> p2{'A'};
                plg::vector<char16_t> p3{u'A'};
                plg::vector<int8_t> p4{-1};
                plg::vector<int16_t> p5{-1};
                plg::vector<int32_t> p6{-1};
                plg::vector<int64_t> p7{-1LL};
                plg::vector<uint8_t> p8{0};
                plg::vector<uint16_t> p9{0};
                plg::vector<uint32_t> p10{0};
                plg::vector<uint64_t> p11{0};
                plg::vector<void *> p12{nullptr};
                plg::vector<float> p13{1.0f};
                plg::vector<double> p14{1.0};
                plg::vector<plg::string> p15{"Hi"};
                cross_call_master::ParamRefVectorsCallback(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                                           p15);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}",
                                                             p1, p2, p3, p4, p5, p6, p7, p8,
                                                             p9, p10, p11, p12, p13, p14, p15));
            }
        },
        {
            "ParamAllPrimitives", [] {
                const auto result = cross_call_master::ParamAllPrimitivesCallback(
                    true, '%', u'☢', -1, -1000, -1000000, -1000000000000LL, 200, 50000, 3000000000LL, 9999999999LL,
                    reinterpret_cast<void *>(0xfedcbaabcdefLL), 0.001f, 987654.456789);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "ParamAllAliases", [] {
            	cross_call_master::AliasBool aBool{true};
            	cross_call_master::AliasChar8 aChar8{'A'};
            	cross_call_master::AliasChar16 aChar16{u'0'};
            	cross_call_master::AliasInt8 aInt8{1};
            	cross_call_master::AliasInt16 aInt16{2};
            	cross_call_master::AliasInt32 aInt32{3};
            	cross_call_master::AliasInt64 aInt64{4};
            	cross_call_master::AliasPtr aPtr{};
            	cross_call_master::AliasFloat aFloat{5.5f};
            	cross_call_master::AliasDouble aDouble{6.6};
            	cross_call_master::AliasString aString{"seven"};
            	cross_call_master::AliasAny aAny{"six"};
            	cross_call_master::AliasVec2 aVec2{0.1f, 0.2f};
            	cross_call_master::AliasVec3 aVec3{0.3f, 0.4f, 0.5f};
            	cross_call_master::AliasVec4 aVec4{0.6f, 0.7f, 0.8f, 0.9f};
            	cross_call_master::AliasMat4x4 aMat4x4{1.4f, 1.1f, 1.2f, 1.3f, 2.4f, 2.1f, 2.2f, 2.3f, 3.4f, 3.1f, 3.2f, 3.3f, 4.4f, 4.1f, 4.2f, 4.3f};
            	cross_call_master::AliasBoolVector aBoolVec{aBool};
            	cross_call_master::AliasChar8Vector aChar8Vec{aChar8};
            	cross_call_master::AliasChar16Vector aChar16Vec{aChar16};
            	cross_call_master::AliasInt8Vector aInt8Vec{aInt8};
            	cross_call_master::AliasInt16Vector aInt16Vec{aInt16};
            	cross_call_master::AliasInt32Vector aInt32Vec{aInt32};
            	cross_call_master::AliasInt64Vector aInt64Vec{aInt64};
            	cross_call_master::AliasPtrVector aPtrVec{aPtr};
            	cross_call_master::AliasFloatVector aFloatVec{aFloat};
            	cross_call_master::AliasDoubleVector aDoubleVec{aDouble};
            	cross_call_master::AliasStringVector aStringVec{aString};
            	cross_call_master::AliasAnyVector aAnyVec{aAny};
            	cross_call_master::AliasVec2Vector aVec2Vec{aVec2};
            	cross_call_master::AliasVec3Vector aVec3Vec{aVec3};
            	cross_call_master::AliasVec4Vector aVec4Vec{aVec4};
            	cross_call_master::AliasMat4x4Vector aMat4x4Vec{aMat4x4};
                const auto result = cross_call_master::ParamAllAliasesCallback(aBool, aChar8, aChar16, aInt8, aInt16, aInt32, aInt64, aPtr, aFloat, aDouble, aString, aAny, aVec2, aVec3, aVec4, aMat4x4, aBoolVec, aChar8Vec, aChar16Vec, aInt8Vec, aInt16Vec, aInt32Vec, aInt64Vec, aPtrVec, aFloatVec, aDoubleVec, aStringVec, aAnyVec, aVec2Vec, aVec3Vec, aVec4Vec, aMat4x4Vec);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "ParamAllRefAliases", [] {
            	cross_call_master::AliasBool aBool = {};
            	cross_call_master::AliasChar8 aChar8 = {};
            	cross_call_master::AliasChar16 aChar16 = {};
            	cross_call_master::AliasInt8 aInt8 = {};
            	cross_call_master::AliasInt16 aInt16 = {};
            	cross_call_master::AliasInt32 aInt32 = {};
            	cross_call_master::AliasInt64 aInt64 = {};
            	cross_call_master::AliasPtr aPtr = {};
            	cross_call_master::AliasFloat aFloat = {};
            	cross_call_master::AliasDouble aDouble = {};
            	cross_call_master::AliasString aString = {};
            	cross_call_master::AliasAny aAny = {};
            	cross_call_master::AliasVec2 aVec2 = {};
            	cross_call_master::AliasVec3 aVec3 = {};
            	cross_call_master::AliasVec4 aVec4 = {};
            	cross_call_master::AliasMat4x4 aMat4x4 = {};
            	cross_call_master::AliasBoolVector aBoolVec = {aBool};
            	cross_call_master::AliasChar8Vector aChar8Vec = {aChar8};
            	cross_call_master::AliasChar16Vector aChar16Vec = {aChar16};
            	cross_call_master::AliasInt8Vector aInt8Vec = {aInt8};
            	cross_call_master::AliasInt16Vector aInt16Vec = {aInt16};
            	cross_call_master::AliasInt32Vector aInt32Vec = {aInt32};
            	cross_call_master::AliasInt64Vector aInt64Vec = {aInt64};
            	cross_call_master::AliasPtrVector aPtrVec = {aPtr};
            	cross_call_master::AliasFloatVector aFloatVec = {aFloat};
            	cross_call_master::AliasDoubleVector aDoubleVec = {aDouble};
            	cross_call_master::AliasStringVector aStringVec = {aString};
            	cross_call_master::AliasAnyVector aAnyVec = {aAny};
            	cross_call_master::AliasVec2Vector aVec2Vec = {aVec2};
            	cross_call_master::AliasVec3Vector aVec3Vec = {aVec3};
            	cross_call_master::AliasVec4Vector aVec4Vec = {aVec4};
            	cross_call_master::AliasMat4x4Vector aMat4x4Vec = {aMat4x4};
                const auto result = cross_call_master::ParamAllRefAliasesCallback(aBool, aChar8, aChar16, aInt8, aInt16, aInt32, aInt64, aPtr, aFloat, aDouble, aString, aAny, aVec2, aVec3, aVec4, aMat4x4, aBoolVec, aChar8Vec, aChar16Vec, aInt8Vec, aInt16Vec, aInt32Vec, aInt64Vec, aPtrVec, aFloatVec, aDoubleVec, aStringVec, aAnyVec, aVec2Vec, aVec3Vec, aVec4Vec, aMat4x4Vec);
            	cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "ParamEnum", [] {
                cross_call_master::Example p1 = cross_call_master::Example::Forth;
                plg::vector<cross_call_master::Example> p2{
                    cross_call_master::Example::First, cross_call_master::Example::Second,
                    cross_call_master::Example::Third
                };
                const auto result = cross_call_master::ParamEnumCallback(p1, p2);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "ParamEnumRef", [] {
                cross_call_master::Example p1 = cross_call_master::Example::First;
                plg::vector<cross_call_master::Example> p2{
                    cross_call_master::Example::First, cross_call_master::Example::First,
                    cross_call_master::Example::Second
                };
                const auto result = cross_call_master::ParamEnumRefCallback(p1, p2);
                cross_call_master::ReverseReturn(std::format("{}|{}|{}", result, p1, p2));
            }
        },
        {
            "ParamVariant", [] {
                plg::any p1 = "my custom string with enough chars";
                plg::vector<plg::any> p2{
                    'X', u'☢', -1, -1000, -1000000, -1000000000000LL, 200, 50000, 3000000000LL, 9999999999LL,
                    reinterpret_cast<void *>(0xfedcbaabcdefLL), 0.001f, 987654.456789
                };
                cross_call_master::ParamVariantCallback(p1, p2);
            }
        },
        {
            "ParamVariantRef", [] {
                plg::any p1 = "my custom string with enough chars";
                plg::vector<plg::any> p2{
                    'X', u'☢', -1, -1000, -1000000, -1000000000000LL, 200, 50000, 3000000000LL, 9999999999LL,
                    reinterpret_cast<void *>(0xfedcbaabcdefLL), 0.001f, 987654.456789
                };
                cross_call_master::ParamVariantRefCallback(p1, p2);
                cross_call_master::ReverseReturn(std::format("{}|{}", p1, p2));
            }
        },
        {
            "CallFuncVoid", [] {
                cross_call_master::CallFuncVoidCallback(&MockVoid);
            }
        },
        {
            "CallFuncBool", [] {
                const auto result = cross_call_master::CallFuncBoolCallback(&MockBool);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncChar8", [] {
                const auto result = cross_call_master::CallFuncChar8Callback(&MockChar8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncChar16", [] {
                const auto result = cross_call_master::CallFuncChar16Callback(&MockChar16);
                cross_call_master::ReverseReturn(std::format("{}", static_cast<uint16_t>(result)));
            }
        },
        {
            "CallFuncInt8", [] {
                const auto result = cross_call_master::CallFuncInt8Callback(&MockInt8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt16", [] {
                const auto result = cross_call_master::CallFuncInt16Callback(&MockInt16);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt32", [] {
                const auto result = cross_call_master::CallFuncInt32Callback(&MockInt32);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt64", [] {
                const auto result = cross_call_master::CallFuncInt64Callback(&MockInt64);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt8", [] {
                const auto result = cross_call_master::CallFuncUInt8Callback(&MockUInt8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt16", [] {
                const auto result = cross_call_master::CallFuncUInt16Callback(&MockUInt16);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt32", [] {
                const auto result = cross_call_master::CallFuncUInt32Callback(&MockUInt32);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt64", [] {
                const auto result = cross_call_master::CallFuncUInt64Callback(&MockUInt64);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncPtr", [] {
                const auto result = cross_call_master::CallFuncPtrCallback(&MockPtr);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncFloat", [] {
                const auto result = cross_call_master::CallFuncFloatCallback(&MockFloat);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncDouble", [] {
                const auto result = cross_call_master::CallFuncDoubleCallback(&MockDouble);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncString", [] {
                const auto result = cross_call_master::CallFuncStringCallback(&MockString);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFuncAny", [] {
                auto result = cross_call_master::CallFuncAnyCallback(&MockAny);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncBoolVector", [] {
                const auto result = cross_call_master::CallFuncBoolVectorCallback(&MockBoolVector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncChar8Vector", [] {
                const auto result = cross_call_master::CallFuncChar8VectorCallback(&MockChar8Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncChar16Vector", [] {
                const auto result = cross_call_master::CallFuncChar16VectorCallback(&MockChar16Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt8Vector", [] {
                const auto result = cross_call_master::CallFuncInt8VectorCallback(&MockInt8Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt16Vector", [] {
                const auto result = cross_call_master::CallFuncInt16VectorCallback(&MockInt16Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt32Vector", [] {
                const auto result = cross_call_master::CallFuncInt32VectorCallback(&MockInt32Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncInt64Vector", [] {
                const auto result = cross_call_master::CallFuncInt64VectorCallback(&MockInt64Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt8Vector", [] {
                const auto result = cross_call_master::CallFuncUInt8VectorCallback(&MockUInt8Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt16Vector", [] {
                const auto result = cross_call_master::CallFuncUInt16VectorCallback(&MockUInt16Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt32Vector", [] {
                const auto result = cross_call_master::CallFuncUInt32VectorCallback(&MockUInt32Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncUInt64Vector", [] {
                const auto result = cross_call_master::CallFuncUInt64VectorCallback(&MockUInt64Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncPtrVector", [] {
                const auto result = cross_call_master::CallFuncPtrVectorCallback(&MockPtrVector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncFloatVector", [] {
                const auto result = cross_call_master::CallFuncFloatVectorCallback(&MockFloatVector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncDoubleVector", [] {
                const auto result = cross_call_master::CallFuncDoubleVectorCallback(&MockDoubleVector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncStringVector", [] {
                const auto result = cross_call_master::CallFuncStringVectorCallback(&MockStringVector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncAnyVector", [] {
                const auto result = cross_call_master::CallFuncAnyVectorCallback(&MockAnyVector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncVec2Vector", [] {
                const auto result = cross_call_master::CallFuncVec2VectorCallback(&MockVec2Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncVec3Vector", [] {
                const auto result = cross_call_master::CallFuncVec3VectorCallback(&MockVec3Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncVec4Vector", [] {
                const auto result = cross_call_master::CallFuncVec4VectorCallback(&MockVec4Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncMat4x4Vector", [] {
                const auto result = cross_call_master::CallFuncMat4x4VectorCallback(&MockMat4x4Vector);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncVec2", [] {
                const auto result = cross_call_master::CallFuncVec2Callback(&MockVec2);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncVec3", [] {
                const auto result = cross_call_master::CallFuncVec3Callback(&MockVec3);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncVec4", [] {
                const auto result = cross_call_master::CallFuncVec4Callback(&MockVec4);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFuncMat4x4", [] {
                const auto result = cross_call_master::CallFuncMat4x4Callback(&MockMat4x4);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc1", [] {
                const auto result = cross_call_master::CallFunc1Callback(&MockFunc1);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc2", [] {
                const auto result = cross_call_master::CallFunc2Callback(&MockFunc2);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc3", [] {
                cross_call_master::CallFunc3Callback(&MockFunc3);
            }
        },
        {
            "CallFunc4", [] {
                const auto result = cross_call_master::CallFunc4Callback(&MockFunc4);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc5", [] {
                const auto result = cross_call_master::CallFunc5Callback(&MockFunc5);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc6", [] {
                const auto result = cross_call_master::CallFunc6Callback(&MockFunc6);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc7", [] {
                const auto result = cross_call_master::CallFunc7Callback(&MockFunc7);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc8", [] {
                const auto result = cross_call_master::CallFunc8Callback(&MockFunc8);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc9", [] {
                cross_call_master::CallFunc9Callback(&MockFunc9);
            }
        },
        {
            "CallFunc10", [] {
                const auto result = cross_call_master::CallFunc10Callback(&MockFunc10);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc11", [] {
                const auto result = cross_call_master::CallFunc11Callback(&MockFunc11);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc12", [] {
                const auto result = cross_call_master::CallFunc12Callback(&MockFunc12);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc13", [] {
                const auto result = cross_call_master::CallFunc13Callback(&MockFunc13);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc14", [] {
                const auto result = cross_call_master::CallFunc14Callback(&MockFunc14);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc15", [] {
                const auto result = cross_call_master::CallFunc15Callback(&MockFunc15);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc16", [] {
                const auto result = cross_call_master::CallFunc16Callback(&MockFunc16);
                cross_call_master::ReverseReturn(std::format("{}", result));
            }
        },
        {
            "CallFunc17", [] {
                const auto result = cross_call_master::CallFunc17Callback(&MockFunc17);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc18", [] {
                const auto result = cross_call_master::CallFunc18Callback(&MockFunc18);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc19", [] {
                const auto result = cross_call_master::CallFunc19Callback(&MockFunc19);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc20", [] {
                const auto result = cross_call_master::CallFunc20Callback(&MockFunc20);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc21", [] {
                const auto result = cross_call_master::CallFunc21Callback(&MockFunc21);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc22", [] {
                const auto result = cross_call_master::CallFunc22Callback(&MockFunc22);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc23", [] {
                const auto result = cross_call_master::CallFunc23Callback(&MockFunc23);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc24", [] {
                const auto result = cross_call_master::CallFunc24Callback(&MockFunc24);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc25", [] {
                const auto result = cross_call_master::CallFunc25Callback(&MockFunc25);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc26", [] {
                const auto result = cross_call_master::CallFunc26Callback(&MockFunc26);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc27", [] {
                const auto result = cross_call_master::CallFunc27Callback(&MockFunc27);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc28", [] {
                const auto result = cross_call_master::CallFunc28Callback(&MockFunc28);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc29", [] {
                const auto result = cross_call_master::CallFunc29Callback(&MockFunc29);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc30", [] {
                const auto result = cross_call_master::CallFunc30Callback(&MockFunc30);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc31", [] {
                const auto result = cross_call_master::CallFunc31Callback(&MockFunc31);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc32", [] {
                const auto result = cross_call_master::CallFunc32Callback(&MockFunc32);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFunc33", [] {
                const auto result = cross_call_master::CallFunc33Callback(&MockFunc33);
                cross_call_master::ReverseReturn(result);
            }
        },
        {
            "CallFuncEnum", [] {
                const auto result = cross_call_master::CallFuncEnumCallback(&MockFuncEnum);
                cross_call_master::ReverseReturn(result);
            }
        },
		{
			"CallFuncAliasBool", [] {
				const auto result = cross_call_master::CallFuncAliasBoolCallback(&MockFuncAliasBool);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasChar8", [] {
				const auto result = cross_call_master::CallFuncAliasChar8Callback(&MockFuncAliasChar8);
				cross_call_master::ReverseReturn(std::format("{}", static_cast<uint8_t>(result)));
			}
		},
		{
			"CallFuncAliasChar16", [] {
				const auto result = cross_call_master::CallFuncAliasChar16Callback(&MockFuncAliasChar16);
				cross_call_master::ReverseReturn(std::format("{}", static_cast<int16_t>(result)));
			}
		},
		{
			"CallFuncAliasInt8", [] {
				const auto result = cross_call_master::CallFuncAliasInt8Callback(&MockFuncAliasInt8);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt16", [] {
				const auto result = cross_call_master::CallFuncAliasInt16Callback(&MockFuncAliasInt16);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt32", [] {
				const auto result = cross_call_master::CallFuncAliasInt32Callback(&MockFuncAliasInt32);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt64", [] {
				const auto result = cross_call_master::CallFuncAliasInt64Callback(&MockFuncAliasInt64);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt8", [] {
				const auto result = cross_call_master::CallFuncAliasUInt8Callback(&MockFuncAliasUInt8);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt16", [] {
				const auto result = cross_call_master::CallFuncAliasUInt16Callback(&MockFuncAliasUInt16);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt32", [] {
				const auto result = cross_call_master::CallFuncAliasUInt32Callback(&MockFuncAliasUInt32);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt64", [] {
				const auto result = cross_call_master::CallFuncAliasUInt64Callback(&MockFuncAliasUInt64);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasPtr", [] {
				const auto result = cross_call_master::CallFuncAliasPtrCallback(&MockFuncAliasPtr);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasFloat", [] {
				const auto result = cross_call_master::CallFuncAliasFloatCallback(&MockFuncAliasFloat);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasDouble", [] {
				const auto result = cross_call_master::CallFuncAliasDoubleCallback(&MockFuncAliasDouble);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasFunction", [] {
				const auto result = cross_call_master::CallFuncAliasFunctionCallback(&MockFuncAliasFunction);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasString", [] {
				const auto result = cross_call_master::CallFuncAliasStringCallback(&MockFuncAliasString);
				cross_call_master::ReverseReturn(result);
			}
		},
		{
			"CallFuncAliasAny", [] {
				const auto result = cross_call_master::CallFuncAliasAnyCallback(&MockFuncAliasAny);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasBoolVector", [] {
				const auto result = cross_call_master::CallFuncAliasBoolVectorCallback(&MockFuncAliasBoolVector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasChar8Vector", [] {
				const auto result = cross_call_master::CallFuncAliasChar8VectorCallback(&MockFuncAliasChar8Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasChar16Vector", [] {
				const auto result = cross_call_master::CallFuncAliasChar16VectorCallback(&MockFuncAliasChar16Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt8Vector", [] {
				const auto result = cross_call_master::CallFuncAliasInt8VectorCallback(&MockFuncAliasInt8Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt16Vector", [] {
				const auto result = cross_call_master::CallFuncAliasInt16VectorCallback(&MockFuncAliasInt16Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt32Vector", [] {
				const auto result = cross_call_master::CallFuncAliasInt32VectorCallback(&MockFuncAliasInt32Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasInt64Vector", [] {
				const auto result = cross_call_master::CallFuncAliasInt64VectorCallback(&MockFuncAliasInt64Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt8Vector", [] {
				const auto result = cross_call_master::CallFuncAliasUInt8VectorCallback(&MockFuncAliasUInt8Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt16Vector", [] {
				const auto result = cross_call_master::CallFuncAliasUInt16VectorCallback(&MockFuncAliasUInt16Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt32Vector", [] {
				const auto result = cross_call_master::CallFuncAliasUInt32VectorCallback(&MockFuncAliasUInt32Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasUInt64Vector", [] {
				const auto result = cross_call_master::CallFuncAliasUInt64VectorCallback(&MockFuncAliasUInt64Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasPtrVector", [] {
				const auto result = cross_call_master::CallFuncAliasPtrVectorCallback(&MockFuncAliasPtrVector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasFloatVector", [] {
				const auto result = cross_call_master::CallFuncAliasFloatVectorCallback(&MockFuncAliasFloatVector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasDoubleVector", [] {
				const auto result = cross_call_master::CallFuncAliasDoubleVectorCallback(&MockFuncAliasDoubleVector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasStringVector", [] {
				const auto result = cross_call_master::CallFuncAliasStringVectorCallback(&MockFuncAliasStringVector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasAnyVector", [] {
				const auto result = cross_call_master::CallFuncAliasAnyVectorCallback(&MockFuncAliasAnyVector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasVec2Vector", [] {
				const auto result = cross_call_master::CallFuncAliasVec2VectorCallback(&MockFuncAliasVec2Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasVec3Vector", [] {
				const auto result = cross_call_master::CallFuncAliasVec3VectorCallback(&MockFuncAliasVec3Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasVec4Vector", [] {
				const auto result = cross_call_master::CallFuncAliasVec4VectorCallback(&MockFuncAliasVec4Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasMat4x4Vector", [] {
				const auto result = cross_call_master::CallFuncAliasMat4x4VectorCallback(&MockFuncAliasMat4x4Vector);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasVec2", [] {
				const auto result = cross_call_master::CallFuncAliasVec2Callback(&MockFuncAliasVec2);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasVec3", [] {
				const auto result = cross_call_master::CallFuncAliasVec3Callback(&MockFuncAliasVec3);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasVec4", [] {
				const auto result = cross_call_master::CallFuncAliasVec4Callback(&MockFuncAliasVec4);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasMat4x4", [] {
				const auto result = cross_call_master::CallFuncAliasMat4x4Callback(&MockFuncAliasMat4x4);
				cross_call_master::ReverseReturn(std::format("{}", result));
			}
		},
		{
			"CallFuncAliasAll", [] {
				const auto result = cross_call_master::CallFuncAliasAllCallback(&MockFuncAliasAll);
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassBasicLifecycle", [] {
				const auto result = TestClass::BasicLifecycle();
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassStateManagement", [] {
				const auto result = TestClass::StateManagement();
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassMultipleInstances", [] {
				const auto result = TestClass::MultipleInstances();
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassCounterWithoutDestructor", [] {
				const auto result = TestClass::CounterWithoutDestructor();
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassStaticMethods", [] {
				const auto result = TestClass::StaticMethods();
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassMemoryLeakDetection", [] {
				const auto result = TestClass::MemoryLeakDetection();
				cross_call_master::ReverseReturn(result);
			}
		},
		{ 
			"ClassExceptionHandling", [] {
				const auto result = TestClass::ExceptionHandling();
				cross_call_master::ReverseReturn(result);
			}
		},
		{
			"ClassOwnershipTransfer", [] {
				const auto result = TestClass::OwnershipTransfer();
				cross_call_master::ReverseReturn(result);
			}
		}
    };
    auto it = tests.find(test);
    if (it != tests.end()) {
        std::get<void(*)()>(*it)();
    }
}

PLUGIFY_WARN_POP()
