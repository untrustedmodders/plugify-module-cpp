#pragma once

#include "enums.hpp"
#include "aliases.hpp"
// Generated from cross_call_worker.pplugin

namespace cross_call_worker {

  using NoParamReturnFunctionFunc = void (*)();


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


  using FuncFunctionInner = void (*)();


  using FuncFunction = FuncFunctionInner (*)();


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


  using FuncAliasBool = AliasBool (*)();


  using FuncAliasChar8 = AliasChar8 (*)();


  using FuncAliasChar16 = AliasChar16 (*)();


  using FuncAliasInt8 = AliasInt8 (*)();


  using FuncAliasInt16 = AliasInt16 (*)();


  using FuncAliasInt32 = AliasInt32 (*)();


  using FuncAliasInt64 = AliasInt64 (*)();


  using FuncAliasUInt8 = AliasUInt8 (*)();


  using FuncAliasUInt16 = AliasUInt16 (*)();


  using FuncAliasUInt32 = AliasUInt32 (*)();


  using FuncAliasUInt64 = AliasUInt64 (*)();


  using FuncAliasPtr = AliasPtr (*)();


  using FuncAliasFloat = AliasFloat (*)();


  using FuncAliasDouble = AliasDouble (*)();


  using FuncAliasString = AliasString (*)();


  using FuncAliasAny = AliasAny (*)();


  using FuncAliasFunction = AliasFunction (*)();


  using FuncAliasFunctionInner = void (*)();


  using FuncAliasBoolVector = AliasBoolVector (*)();


  using FuncAliasChar8Vector = AliasChar8Vector (*)();


  using FuncAliasChar16Vector = AliasChar16Vector (*)();


  using FuncAliasInt8Vector = AliasInt8Vector (*)();


  using FuncAliasInt16Vector = AliasInt16Vector (*)();


  using FuncAliasInt32Vector = AliasInt32Vector (*)();


  using FuncAliasInt64Vector = AliasInt64Vector (*)();


  using FuncAliasUInt8Vector = AliasUInt8Vector (*)();


  using FuncAliasUInt16Vector = AliasUInt16Vector (*)();


  using FuncAliasUInt32Vector = AliasUInt32Vector (*)();


  using FuncAliasUInt64Vector = AliasUInt64Vector (*)();


  using FuncAliasPtrVector = AliasPtrVector (*)();


  using FuncAliasFloatVector = AliasFloatVector (*)();


  using FuncAliasDoubleVector = AliasDoubleVector (*)();


  using FuncAliasStringVector = AliasStringVector (*)();


  using FuncAliasAnyVector = AliasAnyVector (*)();


  using FuncAliasVec2Vector = AliasVec2Vector (*)();


  using FuncAliasVec3Vector = AliasVec3Vector (*)();


  using FuncAliasVec4Vector = AliasVec4Vector (*)();


  using FuncAliasMat4x4Vector = AliasMat4x4Vector (*)();


  using FuncAliasVec2 = AliasVec2 (*)();


  using FuncAliasVec3 = AliasVec3 (*)();


  using FuncAliasVec4 = AliasVec4 (*)();


  using FuncAliasMat4x4 = AliasMat4x4 (*)();


  using FuncAliasAll = plg::string (*)(AliasBool, AliasChar8, AliasChar16, AliasInt8, AliasInt16, AliasInt32, AliasInt64, AliasPtr, AliasFloat, AliasDouble, const AliasString&, const AliasAny&, const AliasVec2&, const AliasVec3&, const AliasVec4&, const AliasMat4x4&, const AliasBoolVector&, const AliasChar8Vector&, const AliasChar16Vector&, const AliasInt8Vector&, const AliasInt16Vector&, const AliasInt32Vector&, const AliasInt64Vector&, const AliasPtrVector&, const AliasFloatVector&, const AliasDoubleVector&, const AliasStringVector&, const AliasAnyVector&, const AliasVec2Vector&, const AliasVec3Vector&, const AliasVec4Vector&, const AliasMat4x4Vector&);


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


} // namespace cross_call_worker
