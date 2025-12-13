#pragma once

#include <plugin_export.h>

#include "enums.hpp"
#include "delegates.hpp"
#include "resource.hpp"
#include "counter.hpp"

// Generated from cross_call_master.pplugin (group: core)

namespace cross_call_master {

  using _ReverseReturn = void (*)(const plg::string&);
}
extern "C" PLUGIN_API cross_call_master::_ReverseReturn __cross_call_master_ReverseReturn;
namespace cross_call_master {
  /**
   * @param returnString (string)
   */
  inline void ReverseReturn(const plg::string& returnString) {
    return __cross_call_master_ReverseReturn(returnString);
  }

  using _NoParamReturnVoidCallback = void (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnVoidCallback __cross_call_master_NoParamReturnVoidCallback;
namespace cross_call_master {
  /**
   */
  inline void NoParamReturnVoidCallback() {
    return __cross_call_master_NoParamReturnVoidCallback();
  }

  using _NoParamReturnBoolCallback = bool (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnBoolCallback __cross_call_master_NoParamReturnBoolCallback;
namespace cross_call_master {
  /**
   * @return bool
   */
  inline bool NoParamReturnBoolCallback() {
    return __cross_call_master_NoParamReturnBoolCallback();
  }

  using _NoParamReturnChar8Callback = char (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnChar8Callback __cross_call_master_NoParamReturnChar8Callback;
namespace cross_call_master {
  /**
   * @return char8
   */
  inline char NoParamReturnChar8Callback() {
    return __cross_call_master_NoParamReturnChar8Callback();
  }

  using _NoParamReturnChar16Callback = char16_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnChar16Callback __cross_call_master_NoParamReturnChar16Callback;
namespace cross_call_master {
  /**
   * @return char16
   */
  inline char16_t NoParamReturnChar16Callback() {
    return __cross_call_master_NoParamReturnChar16Callback();
  }

  using _NoParamReturnInt8Callback = int8_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnInt8Callback __cross_call_master_NoParamReturnInt8Callback;
namespace cross_call_master {
  /**
   * @return int8
   */
  inline int8_t NoParamReturnInt8Callback() {
    return __cross_call_master_NoParamReturnInt8Callback();
  }

  using _NoParamReturnInt16Callback = int16_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnInt16Callback __cross_call_master_NoParamReturnInt16Callback;
namespace cross_call_master {
  /**
   * @return int16
   */
  inline int16_t NoParamReturnInt16Callback() {
    return __cross_call_master_NoParamReturnInt16Callback();
  }

  using _NoParamReturnInt32Callback = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnInt32Callback __cross_call_master_NoParamReturnInt32Callback;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t NoParamReturnInt32Callback() {
    return __cross_call_master_NoParamReturnInt32Callback();
  }

  using _NoParamReturnInt64Callback = int64_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnInt64Callback __cross_call_master_NoParamReturnInt64Callback;
namespace cross_call_master {
  /**
   * @return int64
   */
  inline int64_t NoParamReturnInt64Callback() {
    return __cross_call_master_NoParamReturnInt64Callback();
  }

  using _NoParamReturnUInt8Callback = uint8_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnUInt8Callback __cross_call_master_NoParamReturnUInt8Callback;
namespace cross_call_master {
  /**
   * @return uint8
   */
  inline uint8_t NoParamReturnUInt8Callback() {
    return __cross_call_master_NoParamReturnUInt8Callback();
  }

  using _NoParamReturnUInt16Callback = uint16_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnUInt16Callback __cross_call_master_NoParamReturnUInt16Callback;
namespace cross_call_master {
  /**
   * @return uint16
   */
  inline uint16_t NoParamReturnUInt16Callback() {
    return __cross_call_master_NoParamReturnUInt16Callback();
  }

  using _NoParamReturnUInt32Callback = uint32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnUInt32Callback __cross_call_master_NoParamReturnUInt32Callback;
namespace cross_call_master {
  /**
   * @return uint32
   */
  inline uint32_t NoParamReturnUInt32Callback() {
    return __cross_call_master_NoParamReturnUInt32Callback();
  }

  using _NoParamReturnUInt64Callback = uint64_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnUInt64Callback __cross_call_master_NoParamReturnUInt64Callback;
namespace cross_call_master {
  /**
   * @return uint64
   */
  inline uint64_t NoParamReturnUInt64Callback() {
    return __cross_call_master_NoParamReturnUInt64Callback();
  }

  using _NoParamReturnPointerCallback = void* (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnPointerCallback __cross_call_master_NoParamReturnPointerCallback;
namespace cross_call_master {
  /**
   * @return ptr64
   */
  inline void* NoParamReturnPointerCallback() {
    return __cross_call_master_NoParamReturnPointerCallback();
  }

  using _NoParamReturnFloatCallback = float (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnFloatCallback __cross_call_master_NoParamReturnFloatCallback;
namespace cross_call_master {
  /**
   * @return float
   */
  inline float NoParamReturnFloatCallback() {
    return __cross_call_master_NoParamReturnFloatCallback();
  }

  using _NoParamReturnDoubleCallback = double (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnDoubleCallback __cross_call_master_NoParamReturnDoubleCallback;
namespace cross_call_master {
  /**
   * @return double
   */
  inline double NoParamReturnDoubleCallback() {
    return __cross_call_master_NoParamReturnDoubleCallback();
  }

  using _NoParamReturnFunctionCallback = NoParamReturnFunctionCallbackFunc (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnFunctionCallback __cross_call_master_NoParamReturnFunctionCallback;
namespace cross_call_master {
  /**
   * @return function
   */
  inline NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
    return __cross_call_master_NoParamReturnFunctionCallback();
  }

  using _NoParamReturnStringCallback = plg::string (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnStringCallback __cross_call_master_NoParamReturnStringCallback;
namespace cross_call_master {
  /**
   * @return string
   */
  inline plg::string NoParamReturnStringCallback() {
    return __cross_call_master_NoParamReturnStringCallback();
  }

  using _NoParamReturnAnyCallback = plg::any (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnAnyCallback __cross_call_master_NoParamReturnAnyCallback;
namespace cross_call_master {
  /**
   * @return any
   */
  inline plg::any NoParamReturnAnyCallback() {
    return __cross_call_master_NoParamReturnAnyCallback();
  }

  using _NoParamReturnArrayBoolCallback = plg::vector<bool> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayBoolCallback __cross_call_master_NoParamReturnArrayBoolCallback;
namespace cross_call_master {
  /**
   * @return bool[]
   */
  inline plg::vector<bool> NoParamReturnArrayBoolCallback() {
    return __cross_call_master_NoParamReturnArrayBoolCallback();
  }

  using _NoParamReturnArrayChar8Callback = plg::vector<char> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayChar8Callback __cross_call_master_NoParamReturnArrayChar8Callback;
namespace cross_call_master {
  /**
   * @return char8[]
   */
  inline plg::vector<char> NoParamReturnArrayChar8Callback() {
    return __cross_call_master_NoParamReturnArrayChar8Callback();
  }

  using _NoParamReturnArrayChar16Callback = plg::vector<char16_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayChar16Callback __cross_call_master_NoParamReturnArrayChar16Callback;
namespace cross_call_master {
  /**
   * @return char16[]
   */
  inline plg::vector<char16_t> NoParamReturnArrayChar16Callback() {
    return __cross_call_master_NoParamReturnArrayChar16Callback();
  }

  using _NoParamReturnArrayInt8Callback = plg::vector<int8_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayInt8Callback __cross_call_master_NoParamReturnArrayInt8Callback;
namespace cross_call_master {
  /**
   * @return int8[]
   */
  inline plg::vector<int8_t> NoParamReturnArrayInt8Callback() {
    return __cross_call_master_NoParamReturnArrayInt8Callback();
  }

  using _NoParamReturnArrayInt16Callback = plg::vector<int16_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayInt16Callback __cross_call_master_NoParamReturnArrayInt16Callback;
namespace cross_call_master {
  /**
   * @return int16[]
   */
  inline plg::vector<int16_t> NoParamReturnArrayInt16Callback() {
    return __cross_call_master_NoParamReturnArrayInt16Callback();
  }

  using _NoParamReturnArrayInt32Callback = plg::vector<int32_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayInt32Callback __cross_call_master_NoParamReturnArrayInt32Callback;
namespace cross_call_master {
  /**
   * @return int32[]
   */
  inline plg::vector<int32_t> NoParamReturnArrayInt32Callback() {
    return __cross_call_master_NoParamReturnArrayInt32Callback();
  }

  using _NoParamReturnArrayInt64Callback = plg::vector<int64_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayInt64Callback __cross_call_master_NoParamReturnArrayInt64Callback;
namespace cross_call_master {
  /**
   * @return int64[]
   */
  inline plg::vector<int64_t> NoParamReturnArrayInt64Callback() {
    return __cross_call_master_NoParamReturnArrayInt64Callback();
  }

  using _NoParamReturnArrayUInt8Callback = plg::vector<uint8_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayUInt8Callback __cross_call_master_NoParamReturnArrayUInt8Callback;
namespace cross_call_master {
  /**
   * @return uint8[]
   */
  inline plg::vector<uint8_t> NoParamReturnArrayUInt8Callback() {
    return __cross_call_master_NoParamReturnArrayUInt8Callback();
  }

  using _NoParamReturnArrayUInt16Callback = plg::vector<uint16_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayUInt16Callback __cross_call_master_NoParamReturnArrayUInt16Callback;
namespace cross_call_master {
  /**
   * @return uint16[]
   */
  inline plg::vector<uint16_t> NoParamReturnArrayUInt16Callback() {
    return __cross_call_master_NoParamReturnArrayUInt16Callback();
  }

  using _NoParamReturnArrayUInt32Callback = plg::vector<uint32_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayUInt32Callback __cross_call_master_NoParamReturnArrayUInt32Callback;
namespace cross_call_master {
  /**
   * @return uint32[]
   */
  inline plg::vector<uint32_t> NoParamReturnArrayUInt32Callback() {
    return __cross_call_master_NoParamReturnArrayUInt32Callback();
  }

  using _NoParamReturnArrayUInt64Callback = plg::vector<uint64_t> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayUInt64Callback __cross_call_master_NoParamReturnArrayUInt64Callback;
namespace cross_call_master {
  /**
   * @return uint64[]
   */
  inline plg::vector<uint64_t> NoParamReturnArrayUInt64Callback() {
    return __cross_call_master_NoParamReturnArrayUInt64Callback();
  }

  using _NoParamReturnArrayPointerCallback = plg::vector<void*> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayPointerCallback __cross_call_master_NoParamReturnArrayPointerCallback;
namespace cross_call_master {
  /**
   * @return ptr64[]
   */
  inline plg::vector<void*> NoParamReturnArrayPointerCallback() {
    return __cross_call_master_NoParamReturnArrayPointerCallback();
  }

  using _NoParamReturnArrayFloatCallback = plg::vector<float> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayFloatCallback __cross_call_master_NoParamReturnArrayFloatCallback;
namespace cross_call_master {
  /**
   * @return float[]
   */
  inline plg::vector<float> NoParamReturnArrayFloatCallback() {
    return __cross_call_master_NoParamReturnArrayFloatCallback();
  }

  using _NoParamReturnArrayDoubleCallback = plg::vector<double> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayDoubleCallback __cross_call_master_NoParamReturnArrayDoubleCallback;
namespace cross_call_master {
  /**
   * @return double[]
   */
  inline plg::vector<double> NoParamReturnArrayDoubleCallback() {
    return __cross_call_master_NoParamReturnArrayDoubleCallback();
  }

  using _NoParamReturnArrayStringCallback = plg::vector<plg::string> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayStringCallback __cross_call_master_NoParamReturnArrayStringCallback;
namespace cross_call_master {
  /**
   * @return string[]
   */
  inline plg::vector<plg::string> NoParamReturnArrayStringCallback() {
    return __cross_call_master_NoParamReturnArrayStringCallback();
  }

  using _NoParamReturnArrayAnyCallback = plg::vector<plg::any> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayAnyCallback __cross_call_master_NoParamReturnArrayAnyCallback;
namespace cross_call_master {
  /**
   * @return any[]
   */
  inline plg::vector<plg::any> NoParamReturnArrayAnyCallback() {
    return __cross_call_master_NoParamReturnArrayAnyCallback();
  }

  using _NoParamReturnArrayVector2Callback = plg::vector<plg::vec2> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayVector2Callback __cross_call_master_NoParamReturnArrayVector2Callback;
namespace cross_call_master {
  /**
   * @return vec2[]
   */
  inline plg::vector<plg::vec2> NoParamReturnArrayVector2Callback() {
    return __cross_call_master_NoParamReturnArrayVector2Callback();
  }

  using _NoParamReturnArrayVector3Callback = plg::vector<plg::vec3> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayVector3Callback __cross_call_master_NoParamReturnArrayVector3Callback;
namespace cross_call_master {
  /**
   * @return vec3[]
   */
  inline plg::vector<plg::vec3> NoParamReturnArrayVector3Callback() {
    return __cross_call_master_NoParamReturnArrayVector3Callback();
  }

  using _NoParamReturnArrayVector4Callback = plg::vector<plg::vec4> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayVector4Callback __cross_call_master_NoParamReturnArrayVector4Callback;
namespace cross_call_master {
  /**
   * @return vec4[]
   */
  inline plg::vector<plg::vec4> NoParamReturnArrayVector4Callback() {
    return __cross_call_master_NoParamReturnArrayVector4Callback();
  }

  using _NoParamReturnArrayMatrix4x4Callback = plg::vector<plg::mat4x4> (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnArrayMatrix4x4Callback __cross_call_master_NoParamReturnArrayMatrix4x4Callback;
namespace cross_call_master {
  /**
   * @return mat4x4[]
   */
  inline plg::vector<plg::mat4x4> NoParamReturnArrayMatrix4x4Callback() {
    return __cross_call_master_NoParamReturnArrayMatrix4x4Callback();
  }

  using _NoParamReturnVector2Callback = plg::vec2 (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnVector2Callback __cross_call_master_NoParamReturnVector2Callback;
namespace cross_call_master {
  /**
   * @return vec2
   */
  inline plg::vec2 NoParamReturnVector2Callback() {
    return __cross_call_master_NoParamReturnVector2Callback();
  }

  using _NoParamReturnVector3Callback = plg::vec3 (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnVector3Callback __cross_call_master_NoParamReturnVector3Callback;
namespace cross_call_master {
  /**
   * @return vec3
   */
  inline plg::vec3 NoParamReturnVector3Callback() {
    return __cross_call_master_NoParamReturnVector3Callback();
  }

  using _NoParamReturnVector4Callback = plg::vec4 (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnVector4Callback __cross_call_master_NoParamReturnVector4Callback;
namespace cross_call_master {
  /**
   * @return vec4
   */
  inline plg::vec4 NoParamReturnVector4Callback() {
    return __cross_call_master_NoParamReturnVector4Callback();
  }

  using _NoParamReturnMatrix4x4Callback = plg::mat4x4 (*)();
}
extern "C" PLUGIN_API cross_call_master::_NoParamReturnMatrix4x4Callback __cross_call_master_NoParamReturnMatrix4x4Callback;
namespace cross_call_master {
  /**
   * @return mat4x4
   */
  inline plg::mat4x4 NoParamReturnMatrix4x4Callback() {
    return __cross_call_master_NoParamReturnMatrix4x4Callback();
  }

  using _Param1Callback = void (*)(int32_t);
}
extern "C" PLUGIN_API cross_call_master::_Param1Callback __cross_call_master_Param1Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   */
  inline void Param1Callback(int32_t a) {
    return __cross_call_master_Param1Callback(a);
  }

  using _Param2Callback = void (*)(int32_t, float);
}
extern "C" PLUGIN_API cross_call_master::_Param2Callback __cross_call_master_Param2Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   * @param b (float)
   */
  inline void Param2Callback(int32_t a, float b) {
    return __cross_call_master_Param2Callback(a, b);
  }

  using _Param3Callback = void (*)(int32_t, float, double);
}
extern "C" PLUGIN_API cross_call_master::_Param3Callback __cross_call_master_Param3Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   */
  inline void Param3Callback(int32_t a, float b, double c) {
    return __cross_call_master_Param3Callback(a, b, c);
  }

  using _Param4Callback = void (*)(int32_t, float, double, const plg::vec4&);
}
extern "C" PLUGIN_API cross_call_master::_Param4Callback __cross_call_master_Param4Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   */
  inline void Param4Callback(int32_t a, float b, double c, const plg::vec4& d) {
    return __cross_call_master_Param4Callback(a, b, c, d);
  }

  using _Param5Callback = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&);
}
extern "C" PLUGIN_API cross_call_master::_Param5Callback __cross_call_master_Param5Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   */
  inline void Param5Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e) {
    return __cross_call_master_Param5Callback(a, b, c, d, e);
  }

  using _Param6Callback = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char);
}
extern "C" PLUGIN_API cross_call_master::_Param6Callback __cross_call_master_Param6Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   */
  inline void Param6Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f) {
    return __cross_call_master_Param6Callback(a, b, c, d, e, f);
  }

  using _Param7Callback = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&);
}
extern "C" PLUGIN_API cross_call_master::_Param7Callback __cross_call_master_Param7Callback;
namespace cross_call_master {
  /**
   * @param a (int32)
   * @param b (float)
   * @param c (double)
   * @param d (vec4)
   * @param e (int64[])
   * @param f (char8)
   * @param g (string)
   */
  inline void Param7Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g) {
    return __cross_call_master_Param7Callback(a, b, c, d, e, f, g);
  }

  using _Param8Callback = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t);
}
extern "C" PLUGIN_API cross_call_master::_Param8Callback __cross_call_master_Param8Callback;
namespace cross_call_master {
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
  inline void Param8Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h) {
    return __cross_call_master_Param8Callback(a, b, c, d, e, f, g, h);
  }

  using _Param9Callback = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t);
}
extern "C" PLUGIN_API cross_call_master::_Param9Callback __cross_call_master_Param9Callback;
namespace cross_call_master {
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
  inline void Param9Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k) {
    return __cross_call_master_Param9Callback(a, b, c, d, e, f, g, h, k);
  }

  using _Param10Callback = void (*)(int32_t, float, double, const plg::vec4&, const plg::vector<int64_t>&, char, const plg::string&, char16_t, int16_t, void*);
}
extern "C" PLUGIN_API cross_call_master::_Param10Callback __cross_call_master_Param10Callback;
namespace cross_call_master {
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
  inline void Param10Callback(int32_t a, float b, double c, const plg::vec4& d, const plg::vector<int64_t>& e, char f, const plg::string& g, char16_t h, int16_t k, void* l) {
    return __cross_call_master_Param10Callback(a, b, c, d, e, f, g, h, k, l);
  }

  using _ParamRef1Callback = void (*)(int32_t&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef1Callback __cross_call_master_ParamRef1Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   */
  inline void ParamRef1Callback(int32_t& a) {
    return __cross_call_master_ParamRef1Callback(a);
  }

  using _ParamRef2Callback = void (*)(int32_t&, float&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef2Callback __cross_call_master_ParamRef2Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   * @param b (float&)
   */
  inline void ParamRef2Callback(int32_t& a, float& b) {
    return __cross_call_master_ParamRef2Callback(a, b);
  }

  using _ParamRef3Callback = void (*)(int32_t&, float&, double&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef3Callback __cross_call_master_ParamRef3Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   */
  inline void ParamRef3Callback(int32_t& a, float& b, double& c) {
    return __cross_call_master_ParamRef3Callback(a, b, c);
  }

  using _ParamRef4Callback = void (*)(int32_t&, float&, double&, plg::vec4&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef4Callback __cross_call_master_ParamRef4Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   */
  inline void ParamRef4Callback(int32_t& a, float& b, double& c, plg::vec4& d) {
    return __cross_call_master_ParamRef4Callback(a, b, c, d);
  }

  using _ParamRef5Callback = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef5Callback __cross_call_master_ParamRef5Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   */
  inline void ParamRef5Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e) {
    return __cross_call_master_ParamRef5Callback(a, b, c, d, e);
  }

  using _ParamRef6Callback = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef6Callback __cross_call_master_ParamRef6Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   */
  inline void ParamRef6Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f) {
    return __cross_call_master_ParamRef6Callback(a, b, c, d, e, f);
  }

  using _ParamRef7Callback = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef7Callback __cross_call_master_ParamRef7Callback;
namespace cross_call_master {
  /**
   * @param a (int32&)
   * @param b (float&)
   * @param c (double&)
   * @param d (vec4&)
   * @param e (int64[]&)
   * @param f (char8&)
   * @param g (string&)
   */
  inline void ParamRef7Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g) {
    return __cross_call_master_ParamRef7Callback(a, b, c, d, e, f, g);
  }

  using _ParamRef8Callback = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef8Callback __cross_call_master_ParamRef8Callback;
namespace cross_call_master {
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
  inline void ParamRef8Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h) {
    return __cross_call_master_ParamRef8Callback(a, b, c, d, e, f, g, h);
  }

  using _ParamRef9Callback = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef9Callback __cross_call_master_ParamRef9Callback;
namespace cross_call_master {
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
  inline void ParamRef9Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k) {
    return __cross_call_master_ParamRef9Callback(a, b, c, d, e, f, g, h, k);
  }

  using _ParamRef10Callback = void (*)(int32_t&, float&, double&, plg::vec4&, plg::vector<int64_t>&, char&, plg::string&, char16_t&, int16_t&, void*&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRef10Callback __cross_call_master_ParamRef10Callback;
namespace cross_call_master {
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
  inline void ParamRef10Callback(int32_t& a, float& b, double& c, plg::vec4& d, plg::vector<int64_t>& e, char& f, plg::string& g, char16_t& h, int16_t& k, void*& l) {
    return __cross_call_master_ParamRef10Callback(a, b, c, d, e, f, g, h, k, l);
  }

  using _ParamRefVectorsCallback = void (*)(plg::vector<bool>&, plg::vector<char>&, plg::vector<char16_t>&, plg::vector<int8_t>&, plg::vector<int16_t>&, plg::vector<int32_t>&, plg::vector<int64_t>&, plg::vector<uint8_t>&, plg::vector<uint16_t>&, plg::vector<uint32_t>&, plg::vector<uint64_t>&, plg::vector<void*>&, plg::vector<float>&, plg::vector<double>&, plg::vector<plg::string>&);
}
extern "C" PLUGIN_API cross_call_master::_ParamRefVectorsCallback __cross_call_master_ParamRefVectorsCallback;
namespace cross_call_master {
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
  inline void ParamRefVectorsCallback(plg::vector<bool>& p1, plg::vector<char>& p2, plg::vector<char16_t>& p3, plg::vector<int8_t>& p4, plg::vector<int16_t>& p5, plg::vector<int32_t>& p6, plg::vector<int64_t>& p7, plg::vector<uint8_t>& p8, plg::vector<uint16_t>& p9, plg::vector<uint32_t>& p10, plg::vector<uint64_t>& p11, plg::vector<void*>& p12, plg::vector<float>& p13, plg::vector<double>& p14, plg::vector<plg::string>& p15) {
    return __cross_call_master_ParamRefVectorsCallback(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
  }

  using _ParamAllPrimitivesCallback = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
}
extern "C" PLUGIN_API cross_call_master::_ParamAllPrimitivesCallback __cross_call_master_ParamAllPrimitivesCallback;
namespace cross_call_master {
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
  inline int64_t ParamAllPrimitivesCallback(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
    return __cross_call_master_ParamAllPrimitivesCallback(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
  }

  using _ParamEnumCallback = int32_t (*)(Example, const plg::vector<Example>&);
}
extern "C" PLUGIN_API cross_call_master::_ParamEnumCallback __cross_call_master_ParamEnumCallback;
namespace cross_call_master {
  /**
   * @param p1 (int32)
   * @param p2 (int32[])
   * @return int32
   */
  inline int32_t ParamEnumCallback(Example p1, const plg::vector<Example>& p2) {
    return __cross_call_master_ParamEnumCallback(p1, p2);
  }

  using _ParamEnumRefCallback = int32_t (*)(Example&, plg::vector<Example>&);
}
extern "C" PLUGIN_API cross_call_master::_ParamEnumRefCallback __cross_call_master_ParamEnumRefCallback;
namespace cross_call_master {
  /**
   * @param p1 (int32&)
   * @param p2 (int32[]&)
   * @return int32
   */
  inline int32_t ParamEnumRefCallback(Example& p1, plg::vector<Example>& p2) {
    return __cross_call_master_ParamEnumRefCallback(p1, p2);
  }

  using _ParamVariantCallback = void (*)(const plg::any&, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API cross_call_master::_ParamVariantCallback __cross_call_master_ParamVariantCallback;
namespace cross_call_master {
  /**
   * @param p1 (any)
   * @param p2 (any[])
   */
  inline void ParamVariantCallback(const plg::any& p1, const plg::vector<plg::any>& p2) {
    return __cross_call_master_ParamVariantCallback(p1, p2);
  }

  using _ParamVariantRefCallback = void (*)(plg::any&, plg::vector<plg::any>&);
}
extern "C" PLUGIN_API cross_call_master::_ParamVariantRefCallback __cross_call_master_ParamVariantRefCallback;
namespace cross_call_master {
  /**
   * @param p1 (any&)
   * @param p2 (any[]&)
   */
  inline void ParamVariantRefCallback(plg::any& p1, plg::vector<plg::any>& p2) {
    return __cross_call_master_ParamVariantRefCallback(p1, p2);
  }

  using _CallFuncVoidCallback = void (*)(FuncVoid);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVoidCallback __cross_call_master_CallFuncVoidCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   */
  inline void CallFuncVoidCallback(FuncVoid func) {
    return __cross_call_master_CallFuncVoidCallback(func);
  }

  using _CallFuncBoolCallback = bool (*)(FuncBool);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncBoolCallback __cross_call_master_CallFuncBoolCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return bool
   */
  inline bool CallFuncBoolCallback(FuncBool func) {
    return __cross_call_master_CallFuncBoolCallback(func);
  }

  using _CallFuncChar8Callback = char (*)(FuncChar8);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncChar8Callback __cross_call_master_CallFuncChar8Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return char8
   */
  inline char CallFuncChar8Callback(FuncChar8 func) {
    return __cross_call_master_CallFuncChar8Callback(func);
  }

  using _CallFuncChar16Callback = char16_t (*)(FuncChar16);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncChar16Callback __cross_call_master_CallFuncChar16Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return char16
   */
  inline char16_t CallFuncChar16Callback(FuncChar16 func) {
    return __cross_call_master_CallFuncChar16Callback(func);
  }

  using _CallFuncInt8Callback = int8_t (*)(FuncInt8);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt8Callback __cross_call_master_CallFuncInt8Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int8
   */
  inline int8_t CallFuncInt8Callback(FuncInt8 func) {
    return __cross_call_master_CallFuncInt8Callback(func);
  }

  using _CallFuncInt16Callback = int16_t (*)(FuncInt16);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt16Callback __cross_call_master_CallFuncInt16Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int16
   */
  inline int16_t CallFuncInt16Callback(FuncInt16 func) {
    return __cross_call_master_CallFuncInt16Callback(func);
  }

  using _CallFuncInt32Callback = int32_t (*)(FuncInt32);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt32Callback __cross_call_master_CallFuncInt32Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int32
   */
  inline int32_t CallFuncInt32Callback(FuncInt32 func) {
    return __cross_call_master_CallFuncInt32Callback(func);
  }

  using _CallFuncInt64Callback = int64_t (*)(FuncInt64);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt64Callback __cross_call_master_CallFuncInt64Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int64
   */
  inline int64_t CallFuncInt64Callback(FuncInt64 func) {
    return __cross_call_master_CallFuncInt64Callback(func);
  }

  using _CallFuncUInt8Callback = uint8_t (*)(FuncUInt8);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt8Callback __cross_call_master_CallFuncUInt8Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint8
   */
  inline uint8_t CallFuncUInt8Callback(FuncUInt8 func) {
    return __cross_call_master_CallFuncUInt8Callback(func);
  }

  using _CallFuncUInt16Callback = uint16_t (*)(FuncUInt16);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt16Callback __cross_call_master_CallFuncUInt16Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint16
   */
  inline uint16_t CallFuncUInt16Callback(FuncUInt16 func) {
    return __cross_call_master_CallFuncUInt16Callback(func);
  }

  using _CallFuncUInt32Callback = uint32_t (*)(FuncUInt32);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt32Callback __cross_call_master_CallFuncUInt32Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint32
   */
  inline uint32_t CallFuncUInt32Callback(FuncUInt32 func) {
    return __cross_call_master_CallFuncUInt32Callback(func);
  }

  using _CallFuncUInt64Callback = uint64_t (*)(FuncUInt64);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt64Callback __cross_call_master_CallFuncUInt64Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint64
   */
  inline uint64_t CallFuncUInt64Callback(FuncUInt64 func) {
    return __cross_call_master_CallFuncUInt64Callback(func);
  }

  using _CallFuncPtrCallback = void* (*)(FuncPtr);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncPtrCallback __cross_call_master_CallFuncPtrCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFuncPtrCallback(FuncPtr func) {
    return __cross_call_master_CallFuncPtrCallback(func);
  }

  using _CallFuncFloatCallback = float (*)(FuncFloat);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncFloatCallback __cross_call_master_CallFuncFloatCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return float
   */
  inline float CallFuncFloatCallback(FuncFloat func) {
    return __cross_call_master_CallFuncFloatCallback(func);
  }

  using _CallFuncDoubleCallback = double (*)(FuncDouble);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncDoubleCallback __cross_call_master_CallFuncDoubleCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return double
   */
  inline double CallFuncDoubleCallback(FuncDouble func) {
    return __cross_call_master_CallFuncDoubleCallback(func);
  }

  using _CallFuncStringCallback = plg::string (*)(FuncString);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncStringCallback __cross_call_master_CallFuncStringCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFuncStringCallback(FuncString func) {
    return __cross_call_master_CallFuncStringCallback(func);
  }

  using _CallFuncAnyCallback = plg::any (*)(FuncAny);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncAnyCallback __cross_call_master_CallFuncAnyCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return any
   */
  inline plg::any CallFuncAnyCallback(FuncAny func) {
    return __cross_call_master_CallFuncAnyCallback(func);
  }

  using _CallFuncFunctionCallback = void* (*)(FuncFunction);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncFunctionCallback __cross_call_master_CallFuncFunctionCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFuncFunctionCallback(FuncFunction func) {
    return __cross_call_master_CallFuncFunctionCallback(func);
  }

  using _CallFuncBoolVectorCallback = plg::vector<bool> (*)(FuncBoolVector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncBoolVectorCallback __cross_call_master_CallFuncBoolVectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return bool[]
   */
  inline plg::vector<bool> CallFuncBoolVectorCallback(FuncBoolVector func) {
    return __cross_call_master_CallFuncBoolVectorCallback(func);
  }

  using _CallFuncChar8VectorCallback = plg::vector<char> (*)(FuncChar8Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncChar8VectorCallback __cross_call_master_CallFuncChar8VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return char8[]
   */
  inline plg::vector<char> CallFuncChar8VectorCallback(FuncChar8Vector func) {
    return __cross_call_master_CallFuncChar8VectorCallback(func);
  }

  using _CallFuncChar16VectorCallback = plg::vector<char16_t> (*)(FuncChar16Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncChar16VectorCallback __cross_call_master_CallFuncChar16VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return char16[]
   */
  inline plg::vector<char16_t> CallFuncChar16VectorCallback(FuncChar16Vector func) {
    return __cross_call_master_CallFuncChar16VectorCallback(func);
  }

  using _CallFuncInt8VectorCallback = plg::vector<int8_t> (*)(FuncInt8Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt8VectorCallback __cross_call_master_CallFuncInt8VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int8[]
   */
  inline plg::vector<int8_t> CallFuncInt8VectorCallback(FuncInt8Vector func) {
    return __cross_call_master_CallFuncInt8VectorCallback(func);
  }

  using _CallFuncInt16VectorCallback = plg::vector<int16_t> (*)(FuncInt16Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt16VectorCallback __cross_call_master_CallFuncInt16VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int16[]
   */
  inline plg::vector<int16_t> CallFuncInt16VectorCallback(FuncInt16Vector func) {
    return __cross_call_master_CallFuncInt16VectorCallback(func);
  }

  using _CallFuncInt32VectorCallback = plg::vector<int32_t> (*)(FuncInt32Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt32VectorCallback __cross_call_master_CallFuncInt32VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int32[]
   */
  inline plg::vector<int32_t> CallFuncInt32VectorCallback(FuncInt32Vector func) {
    return __cross_call_master_CallFuncInt32VectorCallback(func);
  }

  using _CallFuncInt64VectorCallback = plg::vector<int64_t> (*)(FuncInt64Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncInt64VectorCallback __cross_call_master_CallFuncInt64VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int64[]
   */
  inline plg::vector<int64_t> CallFuncInt64VectorCallback(FuncInt64Vector func) {
    return __cross_call_master_CallFuncInt64VectorCallback(func);
  }

  using _CallFuncUInt8VectorCallback = plg::vector<uint8_t> (*)(FuncUInt8Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt8VectorCallback __cross_call_master_CallFuncUInt8VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint8[]
   */
  inline plg::vector<uint8_t> CallFuncUInt8VectorCallback(FuncUInt8Vector func) {
    return __cross_call_master_CallFuncUInt8VectorCallback(func);
  }

  using _CallFuncUInt16VectorCallback = plg::vector<uint16_t> (*)(FuncUInt16Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt16VectorCallback __cross_call_master_CallFuncUInt16VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint16[]
   */
  inline plg::vector<uint16_t> CallFuncUInt16VectorCallback(FuncUInt16Vector func) {
    return __cross_call_master_CallFuncUInt16VectorCallback(func);
  }

  using _CallFuncUInt32VectorCallback = plg::vector<uint32_t> (*)(FuncUInt32Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt32VectorCallback __cross_call_master_CallFuncUInt32VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint32[]
   */
  inline plg::vector<uint32_t> CallFuncUInt32VectorCallback(FuncUInt32Vector func) {
    return __cross_call_master_CallFuncUInt32VectorCallback(func);
  }

  using _CallFuncUInt64VectorCallback = plg::vector<uint64_t> (*)(FuncUInt64Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncUInt64VectorCallback __cross_call_master_CallFuncUInt64VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint64[]
   */
  inline plg::vector<uint64_t> CallFuncUInt64VectorCallback(FuncUInt64Vector func) {
    return __cross_call_master_CallFuncUInt64VectorCallback(func);
  }

  using _CallFuncPtrVectorCallback = plg::vector<void*> (*)(FuncPtrVector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncPtrVectorCallback __cross_call_master_CallFuncPtrVectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return ptr64[]
   */
  inline plg::vector<void*> CallFuncPtrVectorCallback(FuncPtrVector func) {
    return __cross_call_master_CallFuncPtrVectorCallback(func);
  }

  using _CallFuncFloatVectorCallback = plg::vector<float> (*)(FuncFloatVector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncFloatVectorCallback __cross_call_master_CallFuncFloatVectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return float[]
   */
  inline plg::vector<float> CallFuncFloatVectorCallback(FuncFloatVector func) {
    return __cross_call_master_CallFuncFloatVectorCallback(func);
  }

  using _CallFuncDoubleVectorCallback = plg::vector<double> (*)(FuncDoubleVector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncDoubleVectorCallback __cross_call_master_CallFuncDoubleVectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return double[]
   */
  inline plg::vector<double> CallFuncDoubleVectorCallback(FuncDoubleVector func) {
    return __cross_call_master_CallFuncDoubleVectorCallback(func);
  }

  using _CallFuncStringVectorCallback = plg::vector<plg::string> (*)(FuncStringVector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncStringVectorCallback __cross_call_master_CallFuncStringVectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string[]
   */
  inline plg::vector<plg::string> CallFuncStringVectorCallback(FuncStringVector func) {
    return __cross_call_master_CallFuncStringVectorCallback(func);
  }

  using _CallFuncAnyVectorCallback = plg::vector<plg::any> (*)(FuncAnyVector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncAnyVectorCallback __cross_call_master_CallFuncAnyVectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return any[]
   */
  inline plg::vector<plg::any> CallFuncAnyVectorCallback(FuncAnyVector func) {
    return __cross_call_master_CallFuncAnyVectorCallback(func);
  }

  using _CallFuncVec2VectorCallback = plg::vector<plg::vec2> (*)(FuncVec2Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVec2VectorCallback __cross_call_master_CallFuncVec2VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec2[]
   */
  inline plg::vector<plg::vec2> CallFuncVec2VectorCallback(FuncVec2Vector func) {
    return __cross_call_master_CallFuncVec2VectorCallback(func);
  }

  using _CallFuncVec3VectorCallback = plg::vector<plg::vec3> (*)(FuncVec3Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVec3VectorCallback __cross_call_master_CallFuncVec3VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec3[]
   */
  inline plg::vector<plg::vec3> CallFuncVec3VectorCallback(FuncVec3Vector func) {
    return __cross_call_master_CallFuncVec3VectorCallback(func);
  }

  using _CallFuncVec4VectorCallback = plg::vector<plg::vec4> (*)(FuncVec4Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVec4VectorCallback __cross_call_master_CallFuncVec4VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec4[]
   */
  inline plg::vector<plg::vec4> CallFuncVec4VectorCallback(FuncVec4Vector func) {
    return __cross_call_master_CallFuncVec4VectorCallback(func);
  }

  using _CallFuncMat4x4VectorCallback = plg::vector<plg::mat4x4> (*)(FuncMat4x4Vector);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncMat4x4VectorCallback __cross_call_master_CallFuncMat4x4VectorCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return mat4x4[]
   */
  inline plg::vector<plg::mat4x4> CallFuncMat4x4VectorCallback(FuncMat4x4Vector func) {
    return __cross_call_master_CallFuncMat4x4VectorCallback(func);
  }

  using _CallFuncVec2Callback = plg::vec2 (*)(FuncVec2);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVec2Callback __cross_call_master_CallFuncVec2Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec2
   */
  inline plg::vec2 CallFuncVec2Callback(FuncVec2 func) {
    return __cross_call_master_CallFuncVec2Callback(func);
  }

  using _CallFuncVec3Callback = plg::vec3 (*)(FuncVec3);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVec3Callback __cross_call_master_CallFuncVec3Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec3
   */
  inline plg::vec3 CallFuncVec3Callback(FuncVec3 func) {
    return __cross_call_master_CallFuncVec3Callback(func);
  }

  using _CallFuncVec4Callback = plg::vec4 (*)(FuncVec4);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncVec4Callback __cross_call_master_CallFuncVec4Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec4
   */
  inline plg::vec4 CallFuncVec4Callback(FuncVec4 func) {
    return __cross_call_master_CallFuncVec4Callback(func);
  }

  using _CallFuncMat4x4Callback = plg::mat4x4 (*)(FuncMat4x4);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncMat4x4Callback __cross_call_master_CallFuncMat4x4Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return mat4x4
   */
  inline plg::mat4x4 CallFuncMat4x4Callback(FuncMat4x4 func) {
    return __cross_call_master_CallFuncMat4x4Callback(func);
  }

  using _CallFunc1Callback = int32_t (*)(Func1);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc1Callback __cross_call_master_CallFunc1Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int32
   */
  inline int32_t CallFunc1Callback(Func1 func) {
    return __cross_call_master_CallFunc1Callback(func);
  }

  using _CallFunc2Callback = char (*)(Func2);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc2Callback __cross_call_master_CallFunc2Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return char8
   */
  inline char CallFunc2Callback(Func2 func) {
    return __cross_call_master_CallFunc2Callback(func);
  }

  using _CallFunc3Callback = void (*)(Func3);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc3Callback __cross_call_master_CallFunc3Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   */
  inline void CallFunc3Callback(Func3 func) {
    return __cross_call_master_CallFunc3Callback(func);
  }

  using _CallFunc4Callback = plg::vec4 (*)(Func4);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc4Callback __cross_call_master_CallFunc4Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return vec4
   */
  inline plg::vec4 CallFunc4Callback(Func4 func) {
    return __cross_call_master_CallFunc4Callback(func);
  }

  using _CallFunc5Callback = bool (*)(Func5);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc5Callback __cross_call_master_CallFunc5Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return bool
   */
  inline bool CallFunc5Callback(Func5 func) {
    return __cross_call_master_CallFunc5Callback(func);
  }

  using _CallFunc6Callback = int64_t (*)(Func6);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc6Callback __cross_call_master_CallFunc6Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int64
   */
  inline int64_t CallFunc6Callback(Func6 func) {
    return __cross_call_master_CallFunc6Callback(func);
  }

  using _CallFunc7Callback = double (*)(Func7);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc7Callback __cross_call_master_CallFunc7Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return double
   */
  inline double CallFunc7Callback(Func7 func) {
    return __cross_call_master_CallFunc7Callback(func);
  }

  using _CallFunc8Callback = plg::mat4x4 (*)(Func8);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc8Callback __cross_call_master_CallFunc8Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return mat4x4
   */
  inline plg::mat4x4 CallFunc8Callback(Func8 func) {
    return __cross_call_master_CallFunc8Callback(func);
  }

  using _CallFunc9Callback = void (*)(Func9);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc9Callback __cross_call_master_CallFunc9Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   */
  inline void CallFunc9Callback(Func9 func) {
    return __cross_call_master_CallFunc9Callback(func);
  }

  using _CallFunc10Callback = uint32_t (*)(Func10);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc10Callback __cross_call_master_CallFunc10Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return uint32
   */
  inline uint32_t CallFunc10Callback(Func10 func) {
    return __cross_call_master_CallFunc10Callback(func);
  }

  using _CallFunc11Callback = void* (*)(Func11);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc11Callback __cross_call_master_CallFunc11Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFunc11Callback(Func11 func) {
    return __cross_call_master_CallFunc11Callback(func);
  }

  using _CallFunc12Callback = bool (*)(Func12);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc12Callback __cross_call_master_CallFunc12Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return bool
   */
  inline bool CallFunc12Callback(Func12 func) {
    return __cross_call_master_CallFunc12Callback(func);
  }

  using _CallFunc13Callback = plg::string (*)(Func13);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc13Callback __cross_call_master_CallFunc13Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc13Callback(Func13 func) {
    return __cross_call_master_CallFunc13Callback(func);
  }

  using _CallFunc14Callback = plg::vector<plg::string> (*)(Func14);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc14Callback __cross_call_master_CallFunc14Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string[]
   */
  inline plg::vector<plg::string> CallFunc14Callback(Func14 func) {
    return __cross_call_master_CallFunc14Callback(func);
  }

  using _CallFunc15Callback = int16_t (*)(Func15);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc15Callback __cross_call_master_CallFunc15Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return int16
   */
  inline int16_t CallFunc15Callback(Func15 func) {
    return __cross_call_master_CallFunc15Callback(func);
  }

  using _CallFunc16Callback = void* (*)(Func16);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc16Callback __cross_call_master_CallFunc16Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return ptr64
   */
  inline void* CallFunc16Callback(Func16 func) {
    return __cross_call_master_CallFunc16Callback(func);
  }

  using _CallFunc17Callback = plg::string (*)(Func17);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc17Callback __cross_call_master_CallFunc17Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc17Callback(Func17 func) {
    return __cross_call_master_CallFunc17Callback(func);
  }

  using _CallFunc18Callback = plg::string (*)(Func18);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc18Callback __cross_call_master_CallFunc18Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc18Callback(Func18 func) {
    return __cross_call_master_CallFunc18Callback(func);
  }

  using _CallFunc19Callback = plg::string (*)(Func19);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc19Callback __cross_call_master_CallFunc19Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc19Callback(Func19 func) {
    return __cross_call_master_CallFunc19Callback(func);
  }

  using _CallFunc20Callback = plg::string (*)(Func20);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc20Callback __cross_call_master_CallFunc20Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc20Callback(Func20 func) {
    return __cross_call_master_CallFunc20Callback(func);
  }

  using _CallFunc21Callback = plg::string (*)(Func21);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc21Callback __cross_call_master_CallFunc21Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc21Callback(Func21 func) {
    return __cross_call_master_CallFunc21Callback(func);
  }

  using _CallFunc22Callback = plg::string (*)(Func22);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc22Callback __cross_call_master_CallFunc22Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc22Callback(Func22 func) {
    return __cross_call_master_CallFunc22Callback(func);
  }

  using _CallFunc23Callback = plg::string (*)(Func23);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc23Callback __cross_call_master_CallFunc23Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc23Callback(Func23 func) {
    return __cross_call_master_CallFunc23Callback(func);
  }

  using _CallFunc24Callback = plg::string (*)(Func24);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc24Callback __cross_call_master_CallFunc24Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc24Callback(Func24 func) {
    return __cross_call_master_CallFunc24Callback(func);
  }

  using _CallFunc25Callback = plg::string (*)(Func25);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc25Callback __cross_call_master_CallFunc25Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc25Callback(Func25 func) {
    return __cross_call_master_CallFunc25Callback(func);
  }

  using _CallFunc26Callback = plg::string (*)(Func26);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc26Callback __cross_call_master_CallFunc26Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc26Callback(Func26 func) {
    return __cross_call_master_CallFunc26Callback(func);
  }

  using _CallFunc27Callback = plg::string (*)(Func27);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc27Callback __cross_call_master_CallFunc27Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc27Callback(Func27 func) {
    return __cross_call_master_CallFunc27Callback(func);
  }

  using _CallFunc28Callback = plg::string (*)(Func28);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc28Callback __cross_call_master_CallFunc28Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc28Callback(Func28 func) {
    return __cross_call_master_CallFunc28Callback(func);
  }

  using _CallFunc29Callback = plg::string (*)(Func29);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc29Callback __cross_call_master_CallFunc29Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc29Callback(Func29 func) {
    return __cross_call_master_CallFunc29Callback(func);
  }

  using _CallFunc30Callback = plg::string (*)(Func30);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc30Callback __cross_call_master_CallFunc30Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc30Callback(Func30 func) {
    return __cross_call_master_CallFunc30Callback(func);
  }

  using _CallFunc31Callback = plg::string (*)(Func31);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc31Callback __cross_call_master_CallFunc31Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc31Callback(Func31 func) {
    return __cross_call_master_CallFunc31Callback(func);
  }

  using _CallFunc32Callback = plg::string (*)(Func32);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc32Callback __cross_call_master_CallFunc32Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc32Callback(Func32 func) {
    return __cross_call_master_CallFunc32Callback(func);
  }

  using _CallFunc33Callback = plg::string (*)(Func33);
}
extern "C" PLUGIN_API cross_call_master::_CallFunc33Callback __cross_call_master_CallFunc33Callback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFunc33Callback(Func33 func) {
    return __cross_call_master_CallFunc33Callback(func);
  }

  using _CallFuncEnumCallback = plg::string (*)(FuncEnum);
}
extern "C" PLUGIN_API cross_call_master::_CallFuncEnumCallback __cross_call_master_CallFuncEnumCallback;
namespace cross_call_master {
  /**
   * @param func (function)
   * @return string
   */
  inline plg::string CallFuncEnumCallback(FuncEnum func) {
    return __cross_call_master_CallFuncEnumCallback(func);
  }

  /**
   * @brief RAII wrapper for ResourceHandle pointer
   */
  class ResourceHandle final {
  public:
    /**
     * @param id (int32)
     * @param name (string)
     */
    explicit ResourceHandle(int32_t id, const plg::string& name)
      : ResourceHandle(ResourceHandleCreate(id, name), Ownership::Owned) {}

    /**
     */
    explicit ResourceHandle()
      : ResourceHandle(ResourceHandleCreateDefault(), Ownership::Owned) {}

    ~ResourceHandle() {
      destroy();
    }

    ResourceHandle(const ResourceHandle&) = delete;
    ResourceHandle& operator=(const ResourceHandle&) = delete;

    ResourceHandle(ResourceHandle&& other) noexcept
      : _handle(other._handle)
      , _ownership(other._ownership) {
      other.nullify();
    }

    ResourceHandle& operator=(ResourceHandle&& other) noexcept {
      if (this != &other) {
        destroy();
        _handle = other._handle;
        _ownership = other._ownership;
        other.nullify();
      }
      return *this;
    }

    ResourceHandle(void* handle, Ownership ownership = Ownership::Borrowed) : _handle(handle), _ownership(ownership) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      nullify();
      return handle;
    }

    void reset() noexcept {
      destroy();
      nullify();
    }

    void swap(ResourceHandle& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
      swap(_ownership, other._ownership);
    }

    friend void swap(ResourceHandle& lhs, ResourceHandle& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != nullptr; }
    [[nodiscard]] auto operator<=>(const ResourceHandle& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const ResourceHandle& other) const noexcept { return _handle == other._handle; }

    /**
     * @return int32
     */
    int32_t GetId() {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      return cross_call_master::ResourceHandleGetId(_handle);
    }

    /**
     * @return string
     */
    plg::string GetName() {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      return cross_call_master::ResourceHandleGetName(_handle);
    }

    /**
     * @param name (string)
     */
    void SetName(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      cross_call_master::ResourceHandleSetName(_handle, name);
    }

    /**
     */
    void IncrementCounter() {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      cross_call_master::ResourceHandleIncrementCounter(_handle);
    }

    /**
     * @return int32
     */
    int32_t GetCounter() {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      return cross_call_master::ResourceHandleGetCounter(_handle);
    }

    /**
     * @param value (float)
     */
    void AddData(float value) {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      cross_call_master::ResourceHandleAddData(_handle, value);
    }

    /**
     * @return float[]
     */
    plg::vector<float> GetData() {
      if (_handle == nullptr) throw std::runtime_error("ResourceHandle: Empty handle");
      return cross_call_master::ResourceHandleGetData(_handle);
    }

    /**
     * @return int32
     */
    static int32_t GetAliveCount() {
      return cross_call_master::ResourceHandleGetAliveCount();
    }

    /**
     * @return int32
     */
    static int32_t GetTotalCreated() {
      return cross_call_master::ResourceHandleGetTotalCreated();
    }

    /**
     * @return int32
     */
    static int32_t GetTotalDestroyed() {
      return cross_call_master::ResourceHandleGetTotalDestroyed();
    }

  private:
    void destroy() const noexcept {
      if (_handle != nullptr && _ownership == Ownership::Owned) {
        ResourceHandleDestroy(_handle);
      }
    }

    void nullify() noexcept {
      _handle = nullptr;
      _ownership = Ownership::Borrowed;
    }

    void* _handle{nullptr};
    Ownership _ownership{Ownership::Borrowed};
  };


  /**
   */
  class Counter final {
  public:
    /**
     * @param initialValue (int64)
     */
    explicit Counter(int64_t initialValue)
      : Counter(CounterCreate(initialValue), Ownership::Owned) {}

    /**
     */
    explicit Counter()
      : Counter(CounterCreateZero(), Ownership::Owned) {}

    Counter(const Counter&) = default;
    Counter& operator=(const Counter&) = default;
    Counter(Counter&&) noexcept = default;
    Counter& operator=(Counter&&) noexcept = default;
    ~Counter() = default;

    explicit Counter(void* handle, [[maybe_unused]] Ownership ownership = Ownership::Borrowed) : _handle(handle) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      _handle = nullptr;
      return handle;
    }

    void reset() noexcept {
      _handle = nullptr;
    }

    void swap(Counter& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
    }

    friend void swap(Counter& lhs, Counter& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != nullptr; }
    [[nodiscard]] auto operator<=>(const Counter& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const Counter& other) const noexcept { return _handle == other._handle; }

    /**
     * @return int64
     */
    int64_t GetValue() {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      return cross_call_master::CounterGetValue(_handle);
    }

    /**
     * @param value (int64)
     */
    void SetValue(int64_t value) {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      cross_call_master::CounterSetValue(_handle, value);
    }

    /**
     */
    void Increment() {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      cross_call_master::CounterIncrement(_handle);
    }

    /**
     */
    void Decrement() {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      cross_call_master::CounterDecrement(_handle);
    }

    /**
     * @param amount (int64)
     */
    void Add(int64_t amount) {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      cross_call_master::CounterAdd(_handle, amount);
    }

    /**
     */
    void Reset() {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      cross_call_master::CounterReset(_handle);
    }

    /**
     * @return bool
     */
    bool IsPositive() {
      if (_handle == nullptr) throw std::runtime_error("Counter: Empty handle");
      return cross_call_master::CounterIsPositive(_handle);
    }

    /**
     * @param value1 (int64)
     * @param value2 (int64)
     * @return int32
     */
    static int32_t Compare(int64_t value1, int64_t value2) {
      return cross_call_master::CounterCompare(value1, value2);
    }

    /**
     * @param values (int64[])
     * @return int64
     */
    static int64_t Sum(const plg::vector<int64_t>& values) {
      return cross_call_master::CounterSum(values);
    }

  private:
    void* _handle{nullptr};
  };


} // namespace cross_call_master
