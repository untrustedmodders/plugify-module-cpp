#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from cross_call_worker.pplugin (group: core)

namespace cross_call_worker {

  using _NoParamReturnVoid = void (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnVoid __cross_call_worker_NoParamReturnVoid;
namespace cross_call_worker {
  /**
   */
  inline void NoParamReturnVoid() {
    return __cross_call_worker_NoParamReturnVoid();
  }

  using _NoParamReturnBool = bool (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnBool __cross_call_worker_NoParamReturnBool;
namespace cross_call_worker {
  /**
   * @return bool
   */
  inline bool NoParamReturnBool() {
    return __cross_call_worker_NoParamReturnBool();
  }

  using _NoParamReturnChar8 = char (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnChar8 __cross_call_worker_NoParamReturnChar8;
namespace cross_call_worker {
  /**
   * @return char8
   */
  inline char NoParamReturnChar8() {
    return __cross_call_worker_NoParamReturnChar8();
  }

  using _NoParamReturnChar16 = char16_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnChar16 __cross_call_worker_NoParamReturnChar16;
namespace cross_call_worker {
  /**
   * @return char16
   */
  inline char16_t NoParamReturnChar16() {
    return __cross_call_worker_NoParamReturnChar16();
  }

  using _NoParamReturnInt8 = int8_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnInt8 __cross_call_worker_NoParamReturnInt8;
namespace cross_call_worker {
  /**
   * @return int8
   */
  inline int8_t NoParamReturnInt8() {
    return __cross_call_worker_NoParamReturnInt8();
  }

  using _NoParamReturnInt16 = int16_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnInt16 __cross_call_worker_NoParamReturnInt16;
namespace cross_call_worker {
  /**
   * @return int16
   */
  inline int16_t NoParamReturnInt16() {
    return __cross_call_worker_NoParamReturnInt16();
  }

  using _NoParamReturnInt32 = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnInt32 __cross_call_worker_NoParamReturnInt32;
namespace cross_call_worker {
  /**
   * @return int32
   */
  inline int32_t NoParamReturnInt32() {
    return __cross_call_worker_NoParamReturnInt32();
  }

  using _NoParamReturnInt64 = int64_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnInt64 __cross_call_worker_NoParamReturnInt64;
namespace cross_call_worker {
  /**
   * @return int64
   */
  inline int64_t NoParamReturnInt64() {
    return __cross_call_worker_NoParamReturnInt64();
  }

  using _NoParamReturnUInt8 = uint8_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnUInt8 __cross_call_worker_NoParamReturnUInt8;
namespace cross_call_worker {
  /**
   * @return uint8
   */
  inline uint8_t NoParamReturnUInt8() {
    return __cross_call_worker_NoParamReturnUInt8();
  }

  using _NoParamReturnUInt16 = uint16_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnUInt16 __cross_call_worker_NoParamReturnUInt16;
namespace cross_call_worker {
  /**
   * @return uint16
   */
  inline uint16_t NoParamReturnUInt16() {
    return __cross_call_worker_NoParamReturnUInt16();
  }

  using _NoParamReturnUInt32 = uint32_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnUInt32 __cross_call_worker_NoParamReturnUInt32;
namespace cross_call_worker {
  /**
   * @return uint32
   */
  inline uint32_t NoParamReturnUInt32() {
    return __cross_call_worker_NoParamReturnUInt32();
  }

  using _NoParamReturnUInt64 = uint64_t (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnUInt64 __cross_call_worker_NoParamReturnUInt64;
namespace cross_call_worker {
  /**
   * @return uint64
   */
  inline uint64_t NoParamReturnUInt64() {
    return __cross_call_worker_NoParamReturnUInt64();
  }

  using _NoParamReturnPointer = void* (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnPointer __cross_call_worker_NoParamReturnPointer;
namespace cross_call_worker {
  /**
   * @return ptr64
   */
  inline void* NoParamReturnPointer() {
    return __cross_call_worker_NoParamReturnPointer();
  }

  using _NoParamReturnFloat = float (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnFloat __cross_call_worker_NoParamReturnFloat;
namespace cross_call_worker {
  /**
   * @return float
   */
  inline float NoParamReturnFloat() {
    return __cross_call_worker_NoParamReturnFloat();
  }

  using _NoParamReturnDouble = double (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnDouble __cross_call_worker_NoParamReturnDouble;
namespace cross_call_worker {
  /**
   * @return double
   */
  inline double NoParamReturnDouble() {
    return __cross_call_worker_NoParamReturnDouble();
  }

  using _NoParamReturnFunction = NoParamReturnFunctionFunc (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnFunction __cross_call_worker_NoParamReturnFunction;
namespace cross_call_worker {
  /**
   * @return function
   */
  inline NoParamReturnFunctionFunc NoParamReturnFunction() {
    return __cross_call_worker_NoParamReturnFunction();
  }

  using _NoParamReturnString = plg::string (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnString __cross_call_worker_NoParamReturnString;
namespace cross_call_worker {
  /**
   * @return string
   */
  inline plg::string NoParamReturnString() {
    return __cross_call_worker_NoParamReturnString();
  }

  using _NoParamReturnAny = plg::any (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnAny __cross_call_worker_NoParamReturnAny;
namespace cross_call_worker {
  /**
   * @return any
   */
  inline plg::any NoParamReturnAny() {
    return __cross_call_worker_NoParamReturnAny();
  }

  using _NoParamReturnArrayBool = plg::vector<bool> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayBool __cross_call_worker_NoParamReturnArrayBool;
namespace cross_call_worker {
  /**
   * @return bool[]
   */
  inline plg::vector<bool> NoParamReturnArrayBool() {
    return __cross_call_worker_NoParamReturnArrayBool();
  }

  using _NoParamReturnArrayChar8 = plg::vector<char> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayChar8 __cross_call_worker_NoParamReturnArrayChar8;
namespace cross_call_worker {
  /**
   * @return char8[]
   */
  inline plg::vector<char> NoParamReturnArrayChar8() {
    return __cross_call_worker_NoParamReturnArrayChar8();
  }

  using _NoParamReturnArrayChar16 = plg::vector<char16_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayChar16 __cross_call_worker_NoParamReturnArrayChar16;
namespace cross_call_worker {
  /**
   * @return char16[]
   */
  inline plg::vector<char16_t> NoParamReturnArrayChar16() {
    return __cross_call_worker_NoParamReturnArrayChar16();
  }

  using _NoParamReturnArrayInt8 = plg::vector<int8_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayInt8 __cross_call_worker_NoParamReturnArrayInt8;
namespace cross_call_worker {
  /**
   * @return int8[]
   */
  inline plg::vector<int8_t> NoParamReturnArrayInt8() {
    return __cross_call_worker_NoParamReturnArrayInt8();
  }

  using _NoParamReturnArrayInt16 = plg::vector<int16_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayInt16 __cross_call_worker_NoParamReturnArrayInt16;
namespace cross_call_worker {
  /**
   * @return int16[]
   */
  inline plg::vector<int16_t> NoParamReturnArrayInt16() {
    return __cross_call_worker_NoParamReturnArrayInt16();
  }

  using _NoParamReturnArrayInt32 = plg::vector<int32_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayInt32 __cross_call_worker_NoParamReturnArrayInt32;
namespace cross_call_worker {
  /**
   * @return int32[]
   */
  inline plg::vector<int32_t> NoParamReturnArrayInt32() {
    return __cross_call_worker_NoParamReturnArrayInt32();
  }

  using _NoParamReturnArrayInt64 = plg::vector<int64_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayInt64 __cross_call_worker_NoParamReturnArrayInt64;
namespace cross_call_worker {
  /**
   * @return int64[]
   */
  inline plg::vector<int64_t> NoParamReturnArrayInt64() {
    return __cross_call_worker_NoParamReturnArrayInt64();
  }

  using _NoParamReturnArrayUInt8 = plg::vector<uint8_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayUInt8 __cross_call_worker_NoParamReturnArrayUInt8;
namespace cross_call_worker {
  /**
   * @return uint8[]
   */
  inline plg::vector<uint8_t> NoParamReturnArrayUInt8() {
    return __cross_call_worker_NoParamReturnArrayUInt8();
  }

  using _NoParamReturnArrayUInt16 = plg::vector<uint16_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayUInt16 __cross_call_worker_NoParamReturnArrayUInt16;
namespace cross_call_worker {
  /**
   * @return uint16[]
   */
  inline plg::vector<uint16_t> NoParamReturnArrayUInt16() {
    return __cross_call_worker_NoParamReturnArrayUInt16();
  }

  using _NoParamReturnArrayUInt32 = plg::vector<uint32_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayUInt32 __cross_call_worker_NoParamReturnArrayUInt32;
namespace cross_call_worker {
  /**
   * @return uint32[]
   */
  inline plg::vector<uint32_t> NoParamReturnArrayUInt32() {
    return __cross_call_worker_NoParamReturnArrayUInt32();
  }

  using _NoParamReturnArrayUInt64 = plg::vector<uint64_t> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayUInt64 __cross_call_worker_NoParamReturnArrayUInt64;
namespace cross_call_worker {
  /**
   * @return uint64[]
   */
  inline plg::vector<uint64_t> NoParamReturnArrayUInt64() {
    return __cross_call_worker_NoParamReturnArrayUInt64();
  }

  using _NoParamReturnArrayPointer = plg::vector<void*> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayPointer __cross_call_worker_NoParamReturnArrayPointer;
namespace cross_call_worker {
  /**
   * @return ptr64[]
   */
  inline plg::vector<void*> NoParamReturnArrayPointer() {
    return __cross_call_worker_NoParamReturnArrayPointer();
  }

  using _NoParamReturnArrayFloat = plg::vector<float> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayFloat __cross_call_worker_NoParamReturnArrayFloat;
namespace cross_call_worker {
  /**
   * @return float[]
   */
  inline plg::vector<float> NoParamReturnArrayFloat() {
    return __cross_call_worker_NoParamReturnArrayFloat();
  }

  using _NoParamReturnArrayDouble = plg::vector<double> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayDouble __cross_call_worker_NoParamReturnArrayDouble;
namespace cross_call_worker {
  /**
   * @return double[]
   */
  inline plg::vector<double> NoParamReturnArrayDouble() {
    return __cross_call_worker_NoParamReturnArrayDouble();
  }

  using _NoParamReturnArrayString = plg::vector<plg::string> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayString __cross_call_worker_NoParamReturnArrayString;
namespace cross_call_worker {
  /**
   * @return string[]
   */
  inline plg::vector<plg::string> NoParamReturnArrayString() {
    return __cross_call_worker_NoParamReturnArrayString();
  }

  using _NoParamReturnArrayAny = plg::vector<plg::any> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayAny __cross_call_worker_NoParamReturnArrayAny;
namespace cross_call_worker {
  /**
   * @return any[]
   */
  inline plg::vector<plg::any> NoParamReturnArrayAny() {
    return __cross_call_worker_NoParamReturnArrayAny();
  }

  using _NoParamReturnArrayVector2 = plg::vector<plg::vec2> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayVector2 __cross_call_worker_NoParamReturnArrayVector2;
namespace cross_call_worker {
  /**
   * @return vec2[]
   */
  inline plg::vector<plg::vec2> NoParamReturnArrayVector2() {
    return __cross_call_worker_NoParamReturnArrayVector2();
  }

  using _NoParamReturnArrayVector3 = plg::vector<plg::vec3> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayVector3 __cross_call_worker_NoParamReturnArrayVector3;
namespace cross_call_worker {
  /**
   * @return vec3[]
   */
  inline plg::vector<plg::vec3> NoParamReturnArrayVector3() {
    return __cross_call_worker_NoParamReturnArrayVector3();
  }

  using _NoParamReturnArrayVector4 = plg::vector<plg::vec4> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayVector4 __cross_call_worker_NoParamReturnArrayVector4;
namespace cross_call_worker {
  /**
   * @return vec4[]
   */
  inline plg::vector<plg::vec4> NoParamReturnArrayVector4() {
    return __cross_call_worker_NoParamReturnArrayVector4();
  }

  using _NoParamReturnArrayMatrix4x4 = plg::vector<plg::mat4x4> (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnArrayMatrix4x4 __cross_call_worker_NoParamReturnArrayMatrix4x4;
namespace cross_call_worker {
  /**
   * @return mat4x4[]
   */
  inline plg::vector<plg::mat4x4> NoParamReturnArrayMatrix4x4() {
    return __cross_call_worker_NoParamReturnArrayMatrix4x4();
  }

  using _NoParamReturnVector2 = plg::vec2 (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnVector2 __cross_call_worker_NoParamReturnVector2;
namespace cross_call_worker {
  /**
   * @return vec2
   */
  inline plg::vec2 NoParamReturnVector2() {
    return __cross_call_worker_NoParamReturnVector2();
  }

  using _NoParamReturnVector3 = plg::vec3 (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnVector3 __cross_call_worker_NoParamReturnVector3;
namespace cross_call_worker {
  /**
   * @return vec3
   */
  inline plg::vec3 NoParamReturnVector3() {
    return __cross_call_worker_NoParamReturnVector3();
  }

  using _NoParamReturnVector4 = plg::vec4 (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnVector4 __cross_call_worker_NoParamReturnVector4;
namespace cross_call_worker {
  /**
   * @return vec4
   */
  inline plg::vec4 NoParamReturnVector4() {
    return __cross_call_worker_NoParamReturnVector4();
  }

  using _NoParamReturnMatrix4x4 = plg::mat4x4 (*)();
}
extern "C" PLUGIN_API cross_call_worker::_NoParamReturnMatrix4x4 __cross_call_worker_NoParamReturnMatrix4x4;
namespace cross_call_worker {
  /**
   * @return mat4x4
   */
  inline plg::mat4x4 NoParamReturnMatrix4x4() {
    return __cross_call_worker_NoParamReturnMatrix4x4();
  }

  using _Param1 = void (*)(int32_t);
}
extern "C" PLUGIN_API cross_call_worker::_Param1 __cross_call_worker_Param1;
namespace cross_call_worker {
  /**
   * @param a (int32)
   */
  inline void Param1(int32_t a) {
    return __cross_call_worker_Param1(a);
  }

  using _Param2 = void (*)(int32_t, float);
}
extern "C" PLUGIN_API cross_call_worker::_Param2 __cross_call_worker_Param2;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   */
  inline void Param2(int32_t a, float b) {
    return __cross_call_worker_Param2(a, b);
  }

  using _Param3 = void (*)(int32_t, float, double);
}
extern "C" PLUGIN_API cross_call_worker::_Param3 __cross_call_worker_Param3;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   */
  inline void Param3(int32_t a, float b, double c) {
    return __cross_call_worker_Param3(a, b, c);
  }

  using _Param4 = void (*)(int32_t, float, double, const plg::vec4&);
}
extern "C" PLUGIN_API cross_call_worker::_Param4 __cross_call_worker_Param4;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   */
  inline void Param4(int32_t a, float b, double c, const plg::vec4& d) {
    return __cross_call_worker_Param4(a, b, c, d);
  }

  using _Param5 = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&);
}
extern "C" PLUGIN_API cross_call_worker::_Param5 __cross_call_worker_Param5;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   */
  inline void Param5(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e) {
    return __cross_call_worker_Param5(a, b, c, d, e);
  }

  using _Param6 = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char);
}
extern "C" PLUGIN_API cross_call_worker::_Param6 __cross_call_worker_Param6;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   */
  inline void Param6(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f) {
    return __cross_call_worker_Param6(a, b, c, d, e, f);
  }

  using _Param7 = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&);
}
extern "C" PLUGIN_API cross_call_worker::_Param7 __cross_call_worker_Param7;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   * @param g (string)
   */
  inline void Param7(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g) {
    return __cross_call_worker_Param7(a, b, c, d, e, f, g);
  }

  using _Param8 = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t);
}
extern "C" PLUGIN_API cross_call_worker::_Param8 __cross_call_worker_Param8;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   * @param g (string)
   * @param h (char16)
   */
  inline void Param8(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
    return __cross_call_worker_Param8(a, b, c, d, e, f, g, h);
  }

  using _Param9 = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t);
}
extern "C" PLUGIN_API cross_call_worker::_Param9 __cross_call_worker_Param9;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   * @param g (string)
   * @param h (char16)
   * @param k (int16)
   */
  inline void Param9(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
    return __cross_call_worker_Param9(a, b, c, d, e, f, g, h, k);
  }

  using _Param10 = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t, void*);
}
extern "C" PLUGIN_API cross_call_worker::_Param10 __cross_call_worker_Param10;
namespace cross_call_worker {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   * @param g (string)
   * @param h (char16)
   * @param k (int16)
   * @param l (ptr64)
   */
  inline void Param10(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
    return __cross_call_worker_Param10(a, b, c, d, e, f, g, h, k, l);
  }

  using _ParamRef1 = void (*)(int32_t&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef1 __cross_call_worker_ParamRef1;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   */
  inline void ParamRef1(int32_t& a) {
    return __cross_call_worker_ParamRef1(a);
  }

  using _ParamRef2 = void (*)(int32_t&, float&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef2 __cross_call_worker_ParamRef2;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   */
  inline void ParamRef2(int32_t& a, float& b) {
    return __cross_call_worker_ParamRef2(a, b);
  }

  using _ParamRef3 = void (*)(int32_t&, float&, double&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef3 __cross_call_worker_ParamRef3;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   */
  inline void ParamRef3(int32_t& a, float& b, double& c) {
    return __cross_call_worker_ParamRef3(a, b, c);
  }

  using _ParamRef4 = void (*)(int32_t&, float&, double&, plg::vec4&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef4 __cross_call_worker_ParamRef4;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   */
  inline void ParamRef4(int32_t& a, float& b, double& c, plg::vec4& d) {
    return __cross_call_worker_ParamRef4(a, b, c, d);
  }

  using _ParamRef5 = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef5 __cross_call_worker_ParamRef5;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   */
  inline void ParamRef5(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e) {
    return __cross_call_worker_ParamRef5(a, b, c, d, e);
  }

  using _ParamRef6 = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef6 __cross_call_worker_ParamRef6;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   */
  inline void ParamRef6(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f) {
    return __cross_call_worker_ParamRef6(a, b, c, d, e, f);
  }

  using _ParamRef7 = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef7 __cross_call_worker_ParamRef7;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   * @param g (string&)
   */
  inline void ParamRef7(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g) {
    return __cross_call_worker_ParamRef7(a, b, c, d, e, f, g);
  }

  using _ParamRef8 = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef8 __cross_call_worker_ParamRef8;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   * @param g (string&)
   * @param h (char16&)
   */
  inline void ParamRef8(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
    return __cross_call_worker_ParamRef8(a, b, c, d, e, f, g, h);
  }

  using _ParamRef9 = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef9 __cross_call_worker_ParamRef9;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   * @param g (string&)
   * @param h (char16&)
   * @param k (int16&)
   */
  inline void ParamRef9(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
    return __cross_call_worker_ParamRef9(a, b, c, d, e, f, g, h, k);
  }

  using _ParamRef10 = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&, void*&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRef10 __cross_call_worker_ParamRef10;
namespace cross_call_worker {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   * @param g (string&)
   * @param h (char16&)
   * @param k (int16&)
   * @param l (ptr64&)
   */
  inline void ParamRef10(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
    return __cross_call_worker_ParamRef10(a, b, c, d, e, f, g, h, k, l);
  }

  using _ParamRefVectors = void (*)(plg::vector<bool>&, plg::vector<char>&, plg::vector<char16_t>&, plg::vector<int8_t>&, plg::vector<int16_t>&, plg::vector<int32_t>&, plg::vector<int64_t>&, plg::vector<uint8_t>&, plg::vector<uint16_t>&, plg::vector<uint32_t>&, plg::vector<uint64_t>&, plg::vector<void*>&, plg::vector<float>&, plg::vector<double>&, plg::vector<plg::string>&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamRefVectors __cross_call_worker_ParamRefVectors;
namespace cross_call_worker {
  /**
   * @param p1 (bool[]&)
   * @param p2 (char8[]&)
   * @param p3 (char16[]&)
   * @param p4 (int8[]&)
   * @param p5 (int16[]&)
   * @param p6 (int32[]&)
   * @param p7 (int64[]&)
   * @param p8 (uint8[]&)
   * @param p9 (uint16[]&)
   * @param p10 (uint32[]&)
   * @param p11 (uint64[]&)
   * @param p12 (ptr64[]&)
   * @param p13 (float[]&)
   * @param p14 (double[]&)
   * @param p15 (string[]&)
   */
  inline void ParamRefVectors(plg::vector<bool>& p1, plg::vector<char>& p2, plg::vector<char16_t>& p3, plg::vector<int8_t>& p4, plg::vector<int16_t>& p5, plg::vector<int32_t>& p6, plg::vector<int64_t>& p7, plg::vector<uint8_t>& p8, plg::vector<uint16_t>& p9, plg::vector<uint32_t>& p10, plg::vector<uint64_t>& p11, plg::vector<void*>& p12, plg::vector<float>& p13, plg::vector<double>& p14, plg::vector<plg::string>& p15) {
    return __cross_call_worker_ParamRefVectors(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
  }

  using _ParamAllPrimitives = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
}
extern "C" PLUGIN_API cross_call_worker::_ParamAllPrimitives __cross_call_worker_ParamAllPrimitives;
namespace cross_call_worker {
  /**
   * @param p1 (bool)
   * @param p2 (char8)
   * @param p3 (char16)
   * @param p4 (int8)
   * @param p5 (int16)
   * @param p6 (int32)
   * @param p7 (int64)
   * @param p8 (uint8)
   * @param p9 (uint16)
   * @param p10 (uint32)
   * @param p11 (uint64)
   * @param p12 (ptr64)
   * @param p13 (float)
   * @param p14 (double)
   * @return int64
   */
  inline int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
    return __cross_call_worker_ParamAllPrimitives(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
  }

  using _ParamAllAliases = int32_t (*)(AliasBool, AliasChar8, AliasChar16, AliasInt8, AliasInt16, AliasInt32, AliasInt64, AliasPtr, AliasFloat, AliasDouble, const AliasString&, const AliasAny&, const AliasVec2&, const AliasVec3&, const AliasVec4&, const AliasMat4x4&, const AliasBoolVector&, const AliasChar8Vector&, const AliasChar16Vector&, const AliasInt8Vector&, const AliasInt16Vector&, const AliasInt32Vector&, const AliasInt64Vector&, const AliasPtrVector&, const AliasFloatVector&, const AliasDoubleVector&, const AliasStringVector&, const AliasAnyVector&, const AliasVec2Vector&, const AliasVec3Vector&, const AliasVec4Vector&, const AliasMat4x4Vector&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamAllAliases __cross_call_worker_ParamAllAliases;
namespace cross_call_worker {
  /**
   * @param aBool (bool)
   * @param aChar8 (char8)
   * @param aChar16 (char16)
   * @param aInt8 (int8)
   * @param aInt16 (int16)
   * @param aInt32 (int32)
   * @param aInt64 (int64)
   * @param aPtr (ptr64)
   * @param aFloat (float)
   * @param aDouble (double)
   * @param aString (string)
   * @param aAny (any)
   * @param aVec2 (vec2)
   * @param aVec3 (vec3)
   * @param aVec4 (vec4)
   * @param aMat4x4 (mat4x4)
   * @param aBoolVec (bool[])
   * @param aChar8Vec (char8[])
   * @param aChar16Vec (char16[])
   * @param aInt8Vec (int8[])
   * @param aInt16Vec (int16[])
   * @param aInt32Vec (int32[])
   * @param aInt64Vec (int64[])
   * @param aPtrVec (ptr64[])
   * @param aFloatVec (float[])
   * @param aDoubleVec (double[])
   * @param aStringVec (string[])
   * @param aAnyVec (any[])
   * @param aVec2Vec (vec2[])
   * @param aVec3Vec (vec3[])
   * @param aVec4Vec (vec4[])
   * @param aaMat4x4Vec (mat4x4[])
   * @return int32
   */
  inline int32_t ParamAllAliases(AliasBool aBool, AliasChar8 aChar8, AliasChar16 aChar16, AliasInt8 aInt8, AliasInt16 aInt16, AliasInt32 aInt32, AliasInt64 aInt64, AliasPtr aPtr, AliasFloat aFloat, AliasDouble aDouble, const AliasString& aString, const AliasAny& aAny, const AliasVec2& aVec2, const AliasVec3& aVec3, const AliasVec4& aVec4, const AliasMat4x4& aMat4x4, const AliasBoolVector& aBoolVec, const AliasChar8Vector& aChar8Vec, const AliasChar16Vector& aChar16Vec, const AliasInt8Vector& aInt8Vec, const AliasInt16Vector& aInt16Vec, const AliasInt32Vector& aInt32Vec, const AliasInt64Vector& aInt64Vec, const AliasPtrVector& aPtrVec, const AliasFloatVector& aFloatVec, const AliasDoubleVector& aDoubleVec, const AliasStringVector& aStringVec, const AliasAnyVector& aAnyVec, const AliasVec2Vector& aVec2Vec, const AliasVec3Vector& aVec3Vec, const AliasVec4Vector& aVec4Vec, const AliasMat4x4Vector& aaMat4x4Vec) {
    return __cross_call_worker_ParamAllAliases(aBool, aChar8, aChar16, aInt8, aInt16, aInt32, aInt64, aPtr, aFloat, aDouble, aString, aAny, aVec2, aVec3, aVec4, aMat4x4, aBoolVec, aChar8Vec, aChar16Vec, aInt8Vec, aInt16Vec, aInt32Vec, aInt64Vec, aPtrVec, aFloatVec, aDoubleVec, aStringVec, aAnyVec, aVec2Vec, aVec3Vec, aVec4Vec, aaMat4x4Vec);
  }

  using _ParamAllRefAliases = int64_t (*)(AliasBool&, AliasChar8&, AliasChar16&, AliasInt8&, AliasInt16&, AliasInt32&, AliasInt64&, AliasPtr&, AliasFloat&, AliasDouble&, AliasString&, AliasAny&, AliasVec2&, AliasVec3&, AliasVec4&, AliasMat4x4&, AliasBoolVector&, AliasChar8Vector&, AliasChar16Vector&, AliasInt8Vector&, AliasInt16Vector&, AliasInt32Vector&, AliasInt64Vector&, AliasPtrVector&, AliasFloatVector&, AliasDoubleVector&, AliasStringVector&, AliasAnyVector&, AliasVec2Vector&, AliasVec3Vector&, AliasVec4Vector&, AliasMat4x4Vector&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamAllRefAliases __cross_call_worker_ParamAllRefAliases;
namespace cross_call_worker {
  /**
   * @param aBool (bool&)
   * @param aChar8 (char8&)
   * @param aChar16 (char16&)
   * @param aInt8 (int8&)
   * @param aInt16 (int16&)
   * @param aInt32 (int32&)
   * @param aInt64 (int64&)
   * @param aPtr (ptr64&)
   * @param aFloat (float&)
   * @param aDouble (double&)
   * @param aString (string&)
   * @param aAny (any&)
   * @param aVec2 (vec2&)
   * @param aVec3 (vec3&)
   * @param aVec4 (vec4&)
   * @param aMat4x4 (mat4x4&)
   * @param aBoolVec (bool[]&)
   * @param aChar8Vec (char8[]&)
   * @param aChar16Vec (char16[]&)
   * @param aInt8Vec (int8[]&)
   * @param aInt16Vec (int16[]&)
   * @param aInt32Vec (int32[]&)
   * @param aInt64Vec (int64[]&)
   * @param aPtrVec (ptr64[]&)
   * @param aFloatVec (float[]&)
   * @param aDoubleVec (double[]&)
   * @param aStringVec (string[]&)
   * @param aAnyVec (any[]&)
   * @param aVec2Vec (vec2[]&)
   * @param aVec3Vec (vec3[]&)
   * @param aVec4Vec (vec4[]&)
   * @param aaMat4x4Vec (mat4x4[]&)
   * @return int64
   */
  inline int64_t ParamAllRefAliases(AliasBool& aBool, AliasChar8& aChar8, AliasChar16& aChar16, AliasInt8& aInt8, AliasInt16& aInt16, AliasInt32& aInt32, AliasInt64& aInt64, AliasPtr& aPtr, AliasFloat& aFloat, AliasDouble& aDouble, AliasString& aString, AliasAny& aAny, AliasVec2& aVec2, AliasVec3& aVec3, AliasVec4& aVec4, AliasMat4x4& aMat4x4, AliasBoolVector& aBoolVec, AliasChar8Vector& aChar8Vec, AliasChar16Vector& aChar16Vec, AliasInt8Vector& aInt8Vec, AliasInt16Vector& aInt16Vec, AliasInt32Vector& aInt32Vec, AliasInt64Vector& aInt64Vec, AliasPtrVector& aPtrVec, AliasFloatVector& aFloatVec, AliasDoubleVector& aDoubleVec, AliasStringVector& aStringVec, AliasAnyVector& aAnyVec, AliasVec2Vector& aVec2Vec, AliasVec3Vector& aVec3Vec, AliasVec4Vector& aVec4Vec, AliasMat4x4Vector& aaMat4x4Vec) {
    return __cross_call_worker_ParamAllRefAliases(aBool, aChar8, aChar16, aInt8, aInt16, aInt32, aInt64, aPtr, aFloat, aDouble, aString, aAny, aVec2, aVec3, aVec4, aMat4x4, aBoolVec, aChar8Vec, aChar16Vec, aInt8Vec, aInt16Vec, aInt32Vec, aInt64Vec, aPtrVec, aFloatVec, aDoubleVec, aStringVec, aAnyVec, aVec2Vec, aVec3Vec, aVec4Vec, aaMat4x4Vec);
  }

  using _ParamVariant = void (*)(const plg::any&, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamVariant __cross_call_worker_ParamVariant;
namespace cross_call_worker {
  /**
   * @param p1 (any)
   * @param p2 (any[])
   */
  inline void ParamVariant(const plg::any& p1, const plg::vector<plg::any>& p2) {
    return __cross_call_worker_ParamVariant(p1, p2);
  }

  using _ParamEnum = int32_t (*)(Example, const plg::vector<Example>&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamEnum __cross_call_worker_ParamEnum;
namespace cross_call_worker {
  /**
   * @param p1 (int32)
   * @param p2 (int32[])
   * @return int32
   */
  inline int32_t ParamEnum(Example p1, const plg::vector<Example>& p2) {
    return __cross_call_worker_ParamEnum(p1, p2);
  }

  using _ParamEnumRef = int32_t (*)(Example&, plg::vector<Example>&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamEnumRef __cross_call_worker_ParamEnumRef;
namespace cross_call_worker {
  /**
   * @param p1 (int32&)
   * @param p2 (int32[]&)
   * @return int32
   */
  inline int32_t ParamEnumRef(Example& p1, plg::vector<Example>& p2) {
    return __cross_call_worker_ParamEnumRef(p1, p2);
  }

  using _ParamVariantRef = void (*)(plg::any&, plg::vector<plg::any>&);
}
extern "C" PLUGIN_API cross_call_worker::_ParamVariantRef __cross_call_worker_ParamVariantRef;
namespace cross_call_worker {
  /**
   * @param p1 (any&)
   * @param p2 (any[]&)
   */
  inline void ParamVariantRef(plg::any& p1, plg::vector<plg::any>& p2) {
    return __cross_call_worker_ParamVariantRef(p1, p2);
  }

  using _CallFuncVoid = void (*)(FuncVoid);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVoid __cross_call_worker_CallFuncVoid;
namespace cross_call_worker {
  /**
   * @param func (function)
   */
  inline void CallFuncVoid(FuncVoid func) {
    return __cross_call_worker_CallFuncVoid(func);
  }

  using _CallFuncBool = bool (*)(FuncBool);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncBool __cross_call_worker_CallFuncBool;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return bool
   */
  inline bool CallFuncBool(FuncBool func) {
    return __cross_call_worker_CallFuncBool(func);
  }

  using _CallFuncChar8 = char (*)(FuncChar8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncChar8 __cross_call_worker_CallFuncChar8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char8
   */
  inline char CallFuncChar8(FuncChar8 func) {
    return __cross_call_worker_CallFuncChar8(func);
  }

  using _CallFuncChar16 = char16_t (*)(FuncChar16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncChar16 __cross_call_worker_CallFuncChar16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char16
   */
  inline char16_t CallFuncChar16(FuncChar16 func) {
    return __cross_call_worker_CallFuncChar16(func);
  }

  using _CallFuncInt8 = int8_t (*)(FuncInt8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt8 __cross_call_worker_CallFuncInt8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int8
   */
  inline int8_t CallFuncInt8(FuncInt8 func) {
    return __cross_call_worker_CallFuncInt8(func);
  }

  using _CallFuncInt16 = int16_t (*)(FuncInt16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt16 __cross_call_worker_CallFuncInt16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int16
   */
  inline int16_t CallFuncInt16(FuncInt16 func) {
    return __cross_call_worker_CallFuncInt16(func);
  }

  using _CallFuncInt32 = int32_t (*)(FuncInt32);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt32 __cross_call_worker_CallFuncInt32;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int32
   */
  inline int32_t CallFuncInt32(FuncInt32 func) {
    return __cross_call_worker_CallFuncInt32(func);
  }

  using _CallFuncInt64 = int64_t (*)(FuncInt64);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt64 __cross_call_worker_CallFuncInt64;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int64
   */
  inline int64_t CallFuncInt64(FuncInt64 func) {
    return __cross_call_worker_CallFuncInt64(func);
  }

  using _CallFuncUInt8 = uint8_t (*)(FuncUInt8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt8 __cross_call_worker_CallFuncUInt8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint8
   */
  inline uint8_t CallFuncUInt8(FuncUInt8 func) {
    return __cross_call_worker_CallFuncUInt8(func);
  }

  using _CallFuncUInt16 = uint16_t (*)(FuncUInt16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt16 __cross_call_worker_CallFuncUInt16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint16
   */
  inline uint16_t CallFuncUInt16(FuncUInt16 func) {
    return __cross_call_worker_CallFuncUInt16(func);
  }

  using _CallFuncUInt32 = uint32_t (*)(FuncUInt32);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt32 __cross_call_worker_CallFuncUInt32;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint32
   */
  inline uint32_t CallFuncUInt32(FuncUInt32 func) {
    return __cross_call_worker_CallFuncUInt32(func);
  }

  using _CallFuncUInt64 = uint64_t (*)(FuncUInt64);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt64 __cross_call_worker_CallFuncUInt64;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint64
   */
  inline uint64_t CallFuncUInt64(FuncUInt64 func) {
    return __cross_call_worker_CallFuncUInt64(func);
  }

  using _CallFuncPtr = void* (*)(FuncPtr);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncPtr __cross_call_worker_CallFuncPtr;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFuncPtr(FuncPtr func) {
    return __cross_call_worker_CallFuncPtr(func);
  }

  using _CallFuncFloat = float (*)(FuncFloat);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncFloat __cross_call_worker_CallFuncFloat;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return float
   */
  inline float CallFuncFloat(FuncFloat func) {
    return __cross_call_worker_CallFuncFloat(func);
  }

  using _CallFuncDouble = double (*)(FuncDouble);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncDouble __cross_call_worker_CallFuncDouble;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return double
   */
  inline double CallFuncDouble(FuncDouble func) {
    return __cross_call_worker_CallFuncDouble(func);
  }

  using _CallFuncString = plg::string (*)(FuncString);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncString __cross_call_worker_CallFuncString;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFuncString(FuncString func) {
    return __cross_call_worker_CallFuncString(func);
  }

  using _CallFuncAny = plg::any (*)(FuncAny);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAny __cross_call_worker_CallFuncAny;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return any
   */
  inline plg::any CallFuncAny(FuncAny func) {
    return __cross_call_worker_CallFuncAny(func);
  }

  using _CallFuncFunction = void* (*)(FuncFunction);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncFunction __cross_call_worker_CallFuncFunction;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFuncFunction(FuncFunction func) {
    return __cross_call_worker_CallFuncFunction(func);
  }

  using _CallFuncBoolVector = plg::vector<bool> (*)(FuncBoolVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncBoolVector __cross_call_worker_CallFuncBoolVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return bool[]
   */
  inline plg::vector<bool> CallFuncBoolVector(FuncBoolVector func) {
    return __cross_call_worker_CallFuncBoolVector(func);
  }

  using _CallFuncChar8Vector = plg::vector<char> (*)(FuncChar8Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncChar8Vector __cross_call_worker_CallFuncChar8Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char8[]
   */
  inline plg::vector<char> CallFuncChar8Vector(FuncChar8Vector func) {
    return __cross_call_worker_CallFuncChar8Vector(func);
  }

  using _CallFuncChar16Vector = plg::vector<char16_t> (*)(FuncChar16Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncChar16Vector __cross_call_worker_CallFuncChar16Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char16[]
   */
  inline plg::vector<char16_t> CallFuncChar16Vector(FuncChar16Vector func) {
    return __cross_call_worker_CallFuncChar16Vector(func);
  }

  using _CallFuncInt8Vector = plg::vector<int8_t> (*)(FuncInt8Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt8Vector __cross_call_worker_CallFuncInt8Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int8[]
   */
  inline plg::vector<int8_t> CallFuncInt8Vector(FuncInt8Vector func) {
    return __cross_call_worker_CallFuncInt8Vector(func);
  }

  using _CallFuncInt16Vector = plg::vector<int16_t> (*)(FuncInt16Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt16Vector __cross_call_worker_CallFuncInt16Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int16[]
   */
  inline plg::vector<int16_t> CallFuncInt16Vector(FuncInt16Vector func) {
    return __cross_call_worker_CallFuncInt16Vector(func);
  }

  using _CallFuncInt32Vector = plg::vector<int32_t> (*)(FuncInt32Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt32Vector __cross_call_worker_CallFuncInt32Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int32[]
   */
  inline plg::vector<int32_t> CallFuncInt32Vector(FuncInt32Vector func) {
    return __cross_call_worker_CallFuncInt32Vector(func);
  }

  using _CallFuncInt64Vector = plg::vector<int64_t> (*)(FuncInt64Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncInt64Vector __cross_call_worker_CallFuncInt64Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int64[]
   */
  inline plg::vector<int64_t> CallFuncInt64Vector(FuncInt64Vector func) {
    return __cross_call_worker_CallFuncInt64Vector(func);
  }

  using _CallFuncUInt8Vector = plg::vector<uint8_t> (*)(FuncUInt8Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt8Vector __cross_call_worker_CallFuncUInt8Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint8[]
   */
  inline plg::vector<uint8_t> CallFuncUInt8Vector(FuncUInt8Vector func) {
    return __cross_call_worker_CallFuncUInt8Vector(func);
  }

  using _CallFuncUInt16Vector = plg::vector<uint16_t> (*)(FuncUInt16Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt16Vector __cross_call_worker_CallFuncUInt16Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint16[]
   */
  inline plg::vector<uint16_t> CallFuncUInt16Vector(FuncUInt16Vector func) {
    return __cross_call_worker_CallFuncUInt16Vector(func);
  }

  using _CallFuncUInt32Vector = plg::vector<uint32_t> (*)(FuncUInt32Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt32Vector __cross_call_worker_CallFuncUInt32Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint32[]
   */
  inline plg::vector<uint32_t> CallFuncUInt32Vector(FuncUInt32Vector func) {
    return __cross_call_worker_CallFuncUInt32Vector(func);
  }

  using _CallFuncUInt64Vector = plg::vector<uint64_t> (*)(FuncUInt64Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncUInt64Vector __cross_call_worker_CallFuncUInt64Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint64[]
   */
  inline plg::vector<uint64_t> CallFuncUInt64Vector(FuncUInt64Vector func) {
    return __cross_call_worker_CallFuncUInt64Vector(func);
  }

  using _CallFuncPtrVector = plg::vector<void*> (*)(FuncPtrVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncPtrVector __cross_call_worker_CallFuncPtrVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64[]
   */
  inline plg::vector<void*> CallFuncPtrVector(FuncPtrVector func) {
    return __cross_call_worker_CallFuncPtrVector(func);
  }

  using _CallFuncFloatVector = plg::vector<float> (*)(FuncFloatVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncFloatVector __cross_call_worker_CallFuncFloatVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return float[]
   */
  inline plg::vector<float> CallFuncFloatVector(FuncFloatVector func) {
    return __cross_call_worker_CallFuncFloatVector(func);
  }

  using _CallFuncDoubleVector = plg::vector<double> (*)(FuncDoubleVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncDoubleVector __cross_call_worker_CallFuncDoubleVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return double[]
   */
  inline plg::vector<double> CallFuncDoubleVector(FuncDoubleVector func) {
    return __cross_call_worker_CallFuncDoubleVector(func);
  }

  using _CallFuncStringVector = plg::vector<plg::string> (*)(FuncStringVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncStringVector __cross_call_worker_CallFuncStringVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string[]
   */
  inline plg::vector<plg::string> CallFuncStringVector(FuncStringVector func) {
    return __cross_call_worker_CallFuncStringVector(func);
  }

  using _CallFuncAnyVector = plg::vector<plg::any> (*)(FuncAnyVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAnyVector __cross_call_worker_CallFuncAnyVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return any[]
   */
  inline plg::vector<plg::any> CallFuncAnyVector(FuncAnyVector func) {
    return __cross_call_worker_CallFuncAnyVector(func);
  }

  using _CallFuncVec2Vector = plg::vector<plg::vec2> (*)(FuncVec2Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVec2Vector __cross_call_worker_CallFuncVec2Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec2[]
   */
  inline plg::vector<plg::vec2> CallFuncVec2Vector(FuncVec2Vector func) {
    return __cross_call_worker_CallFuncVec2Vector(func);
  }

  using _CallFuncVec3Vector = plg::vector<plg::vec3> (*)(FuncVec3Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVec3Vector __cross_call_worker_CallFuncVec3Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec3[]
   */
  inline plg::vector<plg::vec3> CallFuncVec3Vector(FuncVec3Vector func) {
    return __cross_call_worker_CallFuncVec3Vector(func);
  }

  using _CallFuncVec4Vector = plg::vector<plg::vec4> (*)(FuncVec4Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVec4Vector __cross_call_worker_CallFuncVec4Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec4[]
   */
  inline plg::vector<plg::vec4> CallFuncVec4Vector(FuncVec4Vector func) {
    return __cross_call_worker_CallFuncVec4Vector(func);
  }

  using _CallFuncMat4x4Vector = plg::vector<plg::mat4x4> (*)(FuncMat4x4Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncMat4x4Vector __cross_call_worker_CallFuncMat4x4Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return mat4x4[]
   */
  inline plg::vector<plg::mat4x4> CallFuncMat4x4Vector(FuncMat4x4Vector func) {
    return __cross_call_worker_CallFuncMat4x4Vector(func);
  }

  using _CallFuncVec2 = plg::vec2 (*)(FuncVec2);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVec2 __cross_call_worker_CallFuncVec2;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec2
   */
  inline plg::vec2 CallFuncVec2(FuncVec2 func) {
    return __cross_call_worker_CallFuncVec2(func);
  }

  using _CallFuncVec3 = plg::vec3 (*)(FuncVec3);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVec3 __cross_call_worker_CallFuncVec3;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec3
   */
  inline plg::vec3 CallFuncVec3(FuncVec3 func) {
    return __cross_call_worker_CallFuncVec3(func);
  }

  using _CallFuncVec4 = plg::vec4 (*)(FuncVec4);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncVec4 __cross_call_worker_CallFuncVec4;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec4
   */
  inline plg::vec4 CallFuncVec4(FuncVec4 func) {
    return __cross_call_worker_CallFuncVec4(func);
  }

  using _CallFuncMat4x4 = plg::mat4x4 (*)(FuncMat4x4);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncMat4x4 __cross_call_worker_CallFuncMat4x4;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return mat4x4
   */
  inline plg::mat4x4 CallFuncMat4x4(FuncMat4x4 func) {
    return __cross_call_worker_CallFuncMat4x4(func);
  }

  using _CallFuncAliasBool = AliasBool (*)(FuncAliasBool);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasBool __cross_call_worker_CallFuncAliasBool;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return bool
   */
  inline AliasBool CallFuncAliasBool(FuncAliasBool func) {
    return __cross_call_worker_CallFuncAliasBool(func);
  }

  using _CallFuncAliasChar8 = AliasChar8 (*)(FuncAliasChar8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasChar8 __cross_call_worker_CallFuncAliasChar8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char8
   */
  inline AliasChar8 CallFuncAliasChar8(FuncAliasChar8 func) {
    return __cross_call_worker_CallFuncAliasChar8(func);
  }

  using _CallFuncAliasChar16 = AliasChar16 (*)(FuncAliasChar16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasChar16 __cross_call_worker_CallFuncAliasChar16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char16
   */
  inline AliasChar16 CallFuncAliasChar16(FuncAliasChar16 func) {
    return __cross_call_worker_CallFuncAliasChar16(func);
  }

  using _CallFuncAliasInt8 = AliasInt8 (*)(FuncAliasInt8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt8 __cross_call_worker_CallFuncAliasInt8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int8
   */
  inline AliasInt8 CallFuncAliasInt8(FuncAliasInt8 func) {
    return __cross_call_worker_CallFuncAliasInt8(func);
  }

  using _CallFuncAliasInt16 = AliasInt16 (*)(FuncAliasInt16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt16 __cross_call_worker_CallFuncAliasInt16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int16
   */
  inline AliasInt16 CallFuncAliasInt16(FuncAliasInt16 func) {
    return __cross_call_worker_CallFuncAliasInt16(func);
  }

  using _CallFuncAliasInt32 = AliasInt32 (*)(FuncAliasInt32);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt32 __cross_call_worker_CallFuncAliasInt32;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int32
   */
  inline AliasInt32 CallFuncAliasInt32(FuncAliasInt32 func) {
    return __cross_call_worker_CallFuncAliasInt32(func);
  }

  using _CallFuncAliasInt64 = AliasInt64 (*)(FuncAliasInt64);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt64 __cross_call_worker_CallFuncAliasInt64;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int64
   */
  inline AliasInt64 CallFuncAliasInt64(FuncAliasInt64 func) {
    return __cross_call_worker_CallFuncAliasInt64(func);
  }

  using _CallFuncAliasUInt8 = AliasUInt8 (*)(FuncAliasUInt8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt8 __cross_call_worker_CallFuncAliasUInt8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint8
   */
  inline AliasUInt8 CallFuncAliasUInt8(FuncAliasUInt8 func) {
    return __cross_call_worker_CallFuncAliasUInt8(func);
  }

  using _CallFuncAliasUInt16 = AliasUInt16 (*)(FuncAliasUInt16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt16 __cross_call_worker_CallFuncAliasUInt16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint16
   */
  inline AliasUInt16 CallFuncAliasUInt16(FuncAliasUInt16 func) {
    return __cross_call_worker_CallFuncAliasUInt16(func);
  }

  using _CallFuncAliasUInt32 = AliasUInt32 (*)(FuncAliasUInt32);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt32 __cross_call_worker_CallFuncAliasUInt32;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint32
   */
  inline AliasUInt32 CallFuncAliasUInt32(FuncAliasUInt32 func) {
    return __cross_call_worker_CallFuncAliasUInt32(func);
  }

  using _CallFuncAliasUInt64 = AliasUInt64 (*)(FuncAliasUInt64);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt64 __cross_call_worker_CallFuncAliasUInt64;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint64
   */
  inline AliasUInt64 CallFuncAliasUInt64(FuncAliasUInt64 func) {
    return __cross_call_worker_CallFuncAliasUInt64(func);
  }

  using _CallFuncAliasPtr = AliasPtr (*)(FuncAliasPtr);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasPtr __cross_call_worker_CallFuncAliasPtr;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline AliasPtr CallFuncAliasPtr(FuncAliasPtr func) {
    return __cross_call_worker_CallFuncAliasPtr(func);
  }

  using _CallFuncAliasFloat = AliasFloat (*)(FuncAliasFloat);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasFloat __cross_call_worker_CallFuncAliasFloat;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return float
   */
  inline AliasFloat CallFuncAliasFloat(FuncAliasFloat func) {
    return __cross_call_worker_CallFuncAliasFloat(func);
  }

  using _CallFuncAliasDouble = AliasDouble (*)(FuncAliasDouble);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasDouble __cross_call_worker_CallFuncAliasDouble;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return double
   */
  inline AliasDouble CallFuncAliasDouble(FuncAliasDouble func) {
    return __cross_call_worker_CallFuncAliasDouble(func);
  }

  using _CallFuncAliasString = AliasString (*)(FuncAliasString);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasString __cross_call_worker_CallFuncAliasString;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline AliasString CallFuncAliasString(FuncAliasString func) {
    return __cross_call_worker_CallFuncAliasString(func);
  }

  using _CallFuncAliasAny = AliasAny (*)(FuncAliasAny);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasAny __cross_call_worker_CallFuncAliasAny;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return any
   */
  inline AliasAny CallFuncAliasAny(FuncAliasAny func) {
    return __cross_call_worker_CallFuncAliasAny(func);
  }

  using _CallFuncAliasFunction = void* (*)(FuncAliasFunction);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasFunction __cross_call_worker_CallFuncAliasFunction;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFuncAliasFunction(FuncAliasFunction func) {
    return __cross_call_worker_CallFuncAliasFunction(func);
  }

  using _CallFuncAliasBoolVector = AliasBoolVector (*)(FuncAliasBoolVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasBoolVector __cross_call_worker_CallFuncAliasBoolVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return bool[]
   */
  inline AliasBoolVector CallFuncAliasBoolVector(FuncAliasBoolVector func) {
    return __cross_call_worker_CallFuncAliasBoolVector(func);
  }

  using _CallFuncAliasChar8Vector = AliasChar8Vector (*)(FuncAliasChar8Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasChar8Vector __cross_call_worker_CallFuncAliasChar8Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char8[]
   */
  inline AliasChar8Vector CallFuncAliasChar8Vector(FuncAliasChar8Vector func) {
    return __cross_call_worker_CallFuncAliasChar8Vector(func);
  }

  using _CallFuncAliasChar16Vector = AliasChar16Vector (*)(FuncAliasChar16Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasChar16Vector __cross_call_worker_CallFuncAliasChar16Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char16[]
   */
  inline AliasChar16Vector CallFuncAliasChar16Vector(FuncAliasChar16Vector func) {
    return __cross_call_worker_CallFuncAliasChar16Vector(func);
  }

  using _CallFuncAliasInt8Vector = AliasInt8Vector (*)(FuncAliasInt8Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt8Vector __cross_call_worker_CallFuncAliasInt8Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int8[]
   */
  inline AliasInt8Vector CallFuncAliasInt8Vector(FuncAliasInt8Vector func) {
    return __cross_call_worker_CallFuncAliasInt8Vector(func);
  }

  using _CallFuncAliasInt16Vector = AliasInt16Vector (*)(FuncAliasInt16Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt16Vector __cross_call_worker_CallFuncAliasInt16Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int16[]
   */
  inline AliasInt16Vector CallFuncAliasInt16Vector(FuncAliasInt16Vector func) {
    return __cross_call_worker_CallFuncAliasInt16Vector(func);
  }

  using _CallFuncAliasInt32Vector = AliasInt32Vector (*)(FuncAliasInt32Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt32Vector __cross_call_worker_CallFuncAliasInt32Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int32[]
   */
  inline AliasInt32Vector CallFuncAliasInt32Vector(FuncAliasInt32Vector func) {
    return __cross_call_worker_CallFuncAliasInt32Vector(func);
  }

  using _CallFuncAliasInt64Vector = AliasInt64Vector (*)(FuncAliasInt64Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasInt64Vector __cross_call_worker_CallFuncAliasInt64Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int64[]
   */
  inline AliasInt64Vector CallFuncAliasInt64Vector(FuncAliasInt64Vector func) {
    return __cross_call_worker_CallFuncAliasInt64Vector(func);
  }

  using _CallFuncAliasUInt8Vector = AliasUInt8Vector (*)(FuncAliasUInt8Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt8Vector __cross_call_worker_CallFuncAliasUInt8Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint8[]
   */
  inline AliasUInt8Vector CallFuncAliasUInt8Vector(FuncAliasUInt8Vector func) {
    return __cross_call_worker_CallFuncAliasUInt8Vector(func);
  }

  using _CallFuncAliasUInt16Vector = AliasUInt16Vector (*)(FuncAliasUInt16Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt16Vector __cross_call_worker_CallFuncAliasUInt16Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint16[]
   */
  inline AliasUInt16Vector CallFuncAliasUInt16Vector(FuncAliasUInt16Vector func) {
    return __cross_call_worker_CallFuncAliasUInt16Vector(func);
  }

  using _CallFuncAliasUInt32Vector = AliasUInt32Vector (*)(FuncAliasUInt32Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt32Vector __cross_call_worker_CallFuncAliasUInt32Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint32[]
   */
  inline AliasUInt32Vector CallFuncAliasUInt32Vector(FuncAliasUInt32Vector func) {
    return __cross_call_worker_CallFuncAliasUInt32Vector(func);
  }

  using _CallFuncAliasUInt64Vector = AliasUInt64Vector (*)(FuncAliasUInt64Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasUInt64Vector __cross_call_worker_CallFuncAliasUInt64Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint64[]
   */
  inline AliasUInt64Vector CallFuncAliasUInt64Vector(FuncAliasUInt64Vector func) {
    return __cross_call_worker_CallFuncAliasUInt64Vector(func);
  }

  using _CallFuncAliasPtrVector = AliasPtrVector (*)(FuncAliasPtrVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasPtrVector __cross_call_worker_CallFuncAliasPtrVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64[]
   */
  inline AliasPtrVector CallFuncAliasPtrVector(FuncAliasPtrVector func) {
    return __cross_call_worker_CallFuncAliasPtrVector(func);
  }

  using _CallFuncAliasFloatVector = AliasFloatVector (*)(FuncAliasFloatVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasFloatVector __cross_call_worker_CallFuncAliasFloatVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return float[]
   */
  inline AliasFloatVector CallFuncAliasFloatVector(FuncAliasFloatVector func) {
    return __cross_call_worker_CallFuncAliasFloatVector(func);
  }

  using _CallFuncAliasDoubleVector = AliasDoubleVector (*)(FuncAliasDoubleVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasDoubleVector __cross_call_worker_CallFuncAliasDoubleVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return double[]
   */
  inline AliasDoubleVector CallFuncAliasDoubleVector(FuncAliasDoubleVector func) {
    return __cross_call_worker_CallFuncAliasDoubleVector(func);
  }

  using _CallFuncAliasStringVector = AliasStringVector (*)(FuncAliasStringVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasStringVector __cross_call_worker_CallFuncAliasStringVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string[]
   */
  inline AliasStringVector CallFuncAliasStringVector(FuncAliasStringVector func) {
    return __cross_call_worker_CallFuncAliasStringVector(func);
  }

  using _CallFuncAliasAnyVector = AliasAnyVector (*)(FuncAliasAnyVector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasAnyVector __cross_call_worker_CallFuncAliasAnyVector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return any[]
   */
  inline AliasAnyVector CallFuncAliasAnyVector(FuncAliasAnyVector func) {
    return __cross_call_worker_CallFuncAliasAnyVector(func);
  }

  using _CallFuncAliasVec2Vector = AliasVec2Vector (*)(FuncAliasVec2Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasVec2Vector __cross_call_worker_CallFuncAliasVec2Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec2[]
   */
  inline AliasVec2Vector CallFuncAliasVec2Vector(FuncAliasVec2Vector func) {
    return __cross_call_worker_CallFuncAliasVec2Vector(func);
  }

  using _CallFuncAliasVec3Vector = AliasVec3Vector (*)(FuncAliasVec3Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasVec3Vector __cross_call_worker_CallFuncAliasVec3Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec3[]
   */
  inline AliasVec3Vector CallFuncAliasVec3Vector(FuncAliasVec3Vector func) {
    return __cross_call_worker_CallFuncAliasVec3Vector(func);
  }

  using _CallFuncAliasVec4Vector = AliasVec4Vector (*)(FuncAliasVec4Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasVec4Vector __cross_call_worker_CallFuncAliasVec4Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec4[]
   */
  inline AliasVec4Vector CallFuncAliasVec4Vector(FuncAliasVec4Vector func) {
    return __cross_call_worker_CallFuncAliasVec4Vector(func);
  }

  using _CallFuncAliasMat4x4Vector = AliasMat4x4Vector (*)(FuncAliasMat4x4Vector);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasMat4x4Vector __cross_call_worker_CallFuncAliasMat4x4Vector;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return mat4x4[]
   */
  inline AliasMat4x4Vector CallFuncAliasMat4x4Vector(FuncAliasMat4x4Vector func) {
    return __cross_call_worker_CallFuncAliasMat4x4Vector(func);
  }

  using _CallFuncAliasVec2 = AliasVec2 (*)(FuncAliasVec2);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasVec2 __cross_call_worker_CallFuncAliasVec2;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec2
   */
  inline AliasVec2 CallFuncAliasVec2(FuncAliasVec2 func) {
    return __cross_call_worker_CallFuncAliasVec2(func);
  }

  using _CallFuncAliasVec3 = AliasVec3 (*)(FuncAliasVec3);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasVec3 __cross_call_worker_CallFuncAliasVec3;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec3
   */
  inline AliasVec3 CallFuncAliasVec3(FuncAliasVec3 func) {
    return __cross_call_worker_CallFuncAliasVec3(func);
  }

  using _CallFuncAliasVec4 = AliasVec4 (*)(FuncAliasVec4);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasVec4 __cross_call_worker_CallFuncAliasVec4;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec4
   */
  inline AliasVec4 CallFuncAliasVec4(FuncAliasVec4 func) {
    return __cross_call_worker_CallFuncAliasVec4(func);
  }

  using _CallFuncAliasMat4x4 = AliasMat4x4 (*)(FuncAliasMat4x4);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasMat4x4 __cross_call_worker_CallFuncAliasMat4x4;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return mat4x4
   */
  inline AliasMat4x4 CallFuncAliasMat4x4(FuncAliasMat4x4 func) {
    return __cross_call_worker_CallFuncAliasMat4x4(func);
  }

  using _CallFuncAliasAll = plg::string (*)(FuncAliasAll);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncAliasAll __cross_call_worker_CallFuncAliasAll;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFuncAliasAll(FuncAliasAll func) {
    return __cross_call_worker_CallFuncAliasAll(func);
  }

  using _CallFunc1 = int32_t (*)(Func1);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc1 __cross_call_worker_CallFunc1;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int32
   */
  inline int32_t CallFunc1(Func1 func) {
    return __cross_call_worker_CallFunc1(func);
  }

  using _CallFunc2 = char (*)(Func2);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc2 __cross_call_worker_CallFunc2;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return char8
   */
  inline char CallFunc2(Func2 func) {
    return __cross_call_worker_CallFunc2(func);
  }

  using _CallFunc3 = void (*)(Func3);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc3 __cross_call_worker_CallFunc3;
namespace cross_call_worker {
  /**
   * @param func (function)
   */
  inline void CallFunc3(Func3 func) {
    return __cross_call_worker_CallFunc3(func);
  }

  using _CallFunc4 = plg::vec4 (*)(Func4);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc4 __cross_call_worker_CallFunc4;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return vec4
   */
  inline plg::vec4 CallFunc4(Func4 func) {
    return __cross_call_worker_CallFunc4(func);
  }

  using _CallFunc5 = bool (*)(Func5);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc5 __cross_call_worker_CallFunc5;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return bool
   */
  inline bool CallFunc5(Func5 func) {
    return __cross_call_worker_CallFunc5(func);
  }

  using _CallFunc6 = int64_t (*)(Func6);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc6 __cross_call_worker_CallFunc6;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int64
   */
  inline int64_t CallFunc6(Func6 func) {
    return __cross_call_worker_CallFunc6(func);
  }

  using _CallFunc7 = double (*)(Func7);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc7 __cross_call_worker_CallFunc7;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return double
   */
  inline double CallFunc7(Func7 func) {
    return __cross_call_worker_CallFunc7(func);
  }

  using _CallFunc8 = plg::mat4x4 (*)(Func8);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc8 __cross_call_worker_CallFunc8;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return mat4x4
   */
  inline plg::mat4x4 CallFunc8(Func8 func) {
    return __cross_call_worker_CallFunc8(func);
  }

  using _CallFunc9 = void (*)(Func9);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc9 __cross_call_worker_CallFunc9;
namespace cross_call_worker {
  /**
   * @param func (function)
   */
  inline void CallFunc9(Func9 func) {
    return __cross_call_worker_CallFunc9(func);
  }

  using _CallFunc10 = uint32_t (*)(Func10);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc10 __cross_call_worker_CallFunc10;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return uint32
   */
  inline uint32_t CallFunc10(Func10 func) {
    return __cross_call_worker_CallFunc10(func);
  }

  using _CallFunc11 = void* (*)(Func11);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc11 __cross_call_worker_CallFunc11;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFunc11(Func11 func) {
    return __cross_call_worker_CallFunc11(func);
  }

  using _CallFunc12 = bool (*)(Func12);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc12 __cross_call_worker_CallFunc12;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return bool
   */
  inline bool CallFunc12(Func12 func) {
    return __cross_call_worker_CallFunc12(func);
  }

  using _CallFunc13 = plg::string (*)(Func13);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc13 __cross_call_worker_CallFunc13;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc13(Func13 func) {
    return __cross_call_worker_CallFunc13(func);
  }

  using _CallFunc14 = plg::vector<plg::string> (*)(Func14);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc14 __cross_call_worker_CallFunc14;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string[]
   */
  inline plg::vector<plg::string> CallFunc14(Func14 func) {
    return __cross_call_worker_CallFunc14(func);
  }

  using _CallFunc15 = int16_t (*)(Func15);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc15 __cross_call_worker_CallFunc15;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return int16
   */
  inline int16_t CallFunc15(Func15 func) {
    return __cross_call_worker_CallFunc15(func);
  }

  using _CallFunc16 = void* (*)(Func16);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc16 __cross_call_worker_CallFunc16;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFunc16(Func16 func) {
    return __cross_call_worker_CallFunc16(func);
  }

  using _CallFunc17 = plg::string (*)(Func17);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc17 __cross_call_worker_CallFunc17;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc17(Func17 func) {
    return __cross_call_worker_CallFunc17(func);
  }

  using _CallFunc18 = plg::string (*)(Func18);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc18 __cross_call_worker_CallFunc18;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc18(Func18 func) {
    return __cross_call_worker_CallFunc18(func);
  }

  using _CallFunc19 = plg::string (*)(Func19);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc19 __cross_call_worker_CallFunc19;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc19(Func19 func) {
    return __cross_call_worker_CallFunc19(func);
  }

  using _CallFunc20 = plg::string (*)(Func20);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc20 __cross_call_worker_CallFunc20;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc20(Func20 func) {
    return __cross_call_worker_CallFunc20(func);
  }

  using _CallFunc21 = plg::string (*)(Func21);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc21 __cross_call_worker_CallFunc21;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc21(Func21 func) {
    return __cross_call_worker_CallFunc21(func);
  }

  using _CallFunc22 = plg::string (*)(Func22);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc22 __cross_call_worker_CallFunc22;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc22(Func22 func) {
    return __cross_call_worker_CallFunc22(func);
  }

  using _CallFunc23 = plg::string (*)(Func23);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc23 __cross_call_worker_CallFunc23;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc23(Func23 func) {
    return __cross_call_worker_CallFunc23(func);
  }

  using _CallFunc24 = plg::string (*)(Func24);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc24 __cross_call_worker_CallFunc24;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc24(Func24 func) {
    return __cross_call_worker_CallFunc24(func);
  }

  using _CallFunc25 = plg::string (*)(Func25);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc25 __cross_call_worker_CallFunc25;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc25(Func25 func) {
    return __cross_call_worker_CallFunc25(func);
  }

  using _CallFunc26 = plg::string (*)(Func26);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc26 __cross_call_worker_CallFunc26;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc26(Func26 func) {
    return __cross_call_worker_CallFunc26(func);
  }

  using _CallFunc27 = plg::string (*)(Func27);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc27 __cross_call_worker_CallFunc27;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc27(Func27 func) {
    return __cross_call_worker_CallFunc27(func);
  }

  using _CallFunc28 = plg::string (*)(Func28);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc28 __cross_call_worker_CallFunc28;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc28(Func28 func) {
    return __cross_call_worker_CallFunc28(func);
  }

  using _CallFunc29 = plg::string (*)(Func29);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc29 __cross_call_worker_CallFunc29;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc29(Func29 func) {
    return __cross_call_worker_CallFunc29(func);
  }

  using _CallFunc30 = plg::string (*)(Func30);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc30 __cross_call_worker_CallFunc30;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc30(Func30 func) {
    return __cross_call_worker_CallFunc30(func);
  }

  using _CallFunc31 = plg::string (*)(Func31);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc31 __cross_call_worker_CallFunc31;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc31(Func31 func) {
    return __cross_call_worker_CallFunc31(func);
  }

  using _CallFunc32 = plg::string (*)(Func32);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc32 __cross_call_worker_CallFunc32;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc32(Func32 func) {
    return __cross_call_worker_CallFunc32(func);
  }

  using _CallFunc33 = plg::string (*)(Func33);
}
extern "C" PLUGIN_API cross_call_worker::_CallFunc33 __cross_call_worker_CallFunc33;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc33(Func33 func) {
    return __cross_call_worker_CallFunc33(func);
  }

  using _CallFuncEnum = plg::string (*)(FuncEnum);
}
extern "C" PLUGIN_API cross_call_worker::_CallFuncEnum __cross_call_worker_CallFuncEnum;
namespace cross_call_worker {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFuncEnum(FuncEnum func) {
    return __cross_call_worker_CallFuncEnum(func);
  }

  using _ReverseCall = void (*)(const plg::string&);
}
extern "C" PLUGIN_API cross_call_worker::_ReverseCall __cross_call_worker_ReverseCall;
namespace cross_call_worker {
  /**
   * @param test (string)
   */
  inline void ReverseCall(const plg::string& test) {
    return __cross_call_worker_ReverseCall(test);
  }

} // namespace cross_call_worker
