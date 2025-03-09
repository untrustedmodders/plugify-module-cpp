import plugify.plugify;

// Generated from cross_call_master.pplugin by https://github.com/untrustedmodders/plugify-module-dlang/blob/main/generator/generator.py
	enum Example : int {
		First = 1,
		Second = 2,
		Third = 3,
		Forth = 4,
	};

	alias NoParamReturnFunctionCallbackFunc = int (*)();
	alias FuncVoid = void (*)();
	alias FuncBool = bool (*)();
	alias FuncChar8 = char (*)();
	alias FuncChar16 = wchar (*)();
	alias FuncInt8 = byte (*)();
	alias FuncInt16 = short (*)();
	alias FuncInt32 = int (*)();
	alias FuncInt64 = long (*)();
	alias FuncUInt8 = ubyte (*)();
	alias FuncUInt16 = ushort (*)();
	alias FuncUInt32 = uint (*)();
	alias FuncUInt64 = ulong (*)();
	alias FuncPtr = uintptr_t (*)();
	alias FuncFloat = float (*)();
	alias FuncDouble = double (*)();
	alias FuncString = string (*)();
	alias FuncAny = PlgVariant (*)();
	alias FuncFunction = delegate (*)();
	alias FuncBoolVector = bool[] (*)();
	alias FuncChar8Vector = char[] (*)();
	alias FuncChar16Vector = wchar[] (*)();
	alias FuncInt8Vector = byte[] (*)();
	alias FuncInt16Vector = short[] (*)();
	alias FuncInt32Vector = int[] (*)();
	alias FuncInt64Vector = long[] (*)();
	alias FuncUInt8Vector = ubyte[] (*)();
	alias FuncUInt16Vector = ushort[] (*)();
	alias FuncUInt32Vector = ulong[] (*)();
	alias FuncUInt64Vector = ulong[] (*)();
	alias FuncPtrVector = uintptr_t[] (*)();
	alias FuncFloatVector = float[] (*)();
	alias FuncDoubleVector = double[] (*)();
	alias FuncStringVector = string[] (*)();
	alias FuncAnyVector = PlgVariant[] (*)();
	alias FuncVec2Vector = Vec2[] (*)();
	alias FuncVec3Vector = Vec3[] (*)();
	alias FuncVec4Vector = Vec4[] (*)();
	alias FuncMat4x4Vector = Mat4x4[] (*)();
	alias FuncVec2 = Vec2 (*)();
	alias FuncVec3 = Vec3 (*)();
	alias FuncVec4 = Vec4 (*)();
	alias FuncMat4x4 = Mat4x4 (*)();
	alias Func1 = int (*)(Vec3);
	alias Func2 = char (*)(float, long);
	alias Func3 = void (*)(uintptr_t, Vec4, string);
	alias Func4 = Vec4 (*)(bool, int, wchar, Mat4x4);
	alias Func5 = bool (*)(byte, Vec2, uintptr_t, double, ulong[]);
	alias Func6 = long (*)(string, float, float[], short, ubyte[], uintptr_t);
	alias Func7 = double (*)(char[], ushort, wchar, ulong[], Vec4, bool, ulong);
	alias Func8 = Mat4x4 (*)(Vec3, ulong[], short, bool, Vec4, wchar[], wchar, int);
	alias Func9 = void (*)(float, Vec2, byte[], ulong, bool, string, Vec4, short, uintptr_t);
	alias Func10 = uint (*)(Vec4, Mat4x4, ulong[], ulong, char[], int, bool, Vec2, long, double);
	alias Func11 = uintptr_t (*)(bool[], wchar, ubyte, double, Vec3, byte[], long, ushort, float, Vec2, uint);
	alias Func12 = bool (*)(uintptr_t, double[], uint, double, bool, int, byte, ulong, float, uintptr_t[], long, char);
	alias Func13 = string (*)(long, char[], ushort, float, bool[], Vec4, string, int, Vec3, uintptr_t, Vec2, ubyte[], short);
	alias Func14 = string[] (*)(char[], ulong[], Mat4x4, bool, wchar, int, float[], ushort, ubyte[], byte, Vec3, Vec4, double, uintptr_t);
	alias Func15 = short (*)(short[], Mat4x4, Vec4, uintptr_t, ulong, ulong[], bool, float, wchar[], ubyte, int, Vec2, ushort, double, ubyte[]);
	alias Func16 = uintptr_t (*)(bool[], short, byte[], Vec4, Mat4x4, Vec2, ulong[], char[], string, long, ulong[], Vec3, float, double, byte, ushort);
	alias Func17 = void (*)(refint);
	alias Func18 = Vec2 (*)(refbyte, refshort);
	alias Func19 = void (*)(refuint, refVec3, refulong[]);
	alias Func20 = int (*)(refwchar, refVec4, refulong[], refchar);
	alias Func21 = float (*)(refMat4x4, refint[], refVec2, refbool, refdouble);
	alias Func22 = ulong (*)(refuintptr_t, refuint, refdouble[], refshort, refstring, refVec4);
	alias Func23 = void (*)(refulong, refVec2, refshort[], refwchar, reffloat, refbyte, refubyte[]);
	alias Func24 = Mat4x4 (*)(refchar[], reflong, refubyte[], refVec4, refulong, refuintptr_t[], refdouble, refuintptr_t[]);
	alias Func25 = double (*)(refint, refuintptr_t[], refbool, refubyte, refstring, refVec3, reflong, refVec4, refushort);
	alias Func26 = char (*)(refwchar, refVec2, refMat4x4, reffloat[], refshort, refulong, refuint, refushort[], refuintptr_t, refbool);
	alias Func27 = ubyte (*)(reffloat, refVec3, refuintptr_t, refVec2, refshort[], refMat4x4, refbool, refVec4, refbyte, refint, refubyte[]);
	alias Func28 = string (*)(refuintptr_t, refushort, refulong[], refMat4x4, reffloat, refVec4, refstring, refulong[], reflong, refbool, refVec3, reffloat[]);
	alias Func29 = string[] (*)(refVec4, refint, refbyte[], refdouble, refbool, refbyte, refushort[], reffloat, refstring, refMat4x4, refulong, refVec3, reflong[]);
	alias Func30 = int (*)(refuintptr_t, refVec4, reflong, refulong[], refbool, refstring, refVec3, refubyte[], reffloat, refVec2, refMat4x4, refbyte, reffloat[], refdouble);
	alias Func31 = Vec3 (*)(refchar, refuint, refulong[], refVec4, refstring, refbool, reflong, refVec2, refbyte, refushort, refshort[], refMat4x4, refVec3, reffloat, refdouble[]);
	alias Func32 = double (*)(refint, refushort, refbyte[], refVec4, refuintptr_t, refulong[], refMat4x4, refulong, refstring, reflong, refVec2, refbyte[], refbool, refVec3, refubyte, refwchar[]);
	alias Func33 = void (*)(refPlgVariant);
	alias FuncEnum = Example (*)(Example, refExample);

/**
 * @brief No description provided.
 *
 * @function ReverseReturn
 * @param returnString (string): No description available.
 */
pragma(inline, true) void ReverseReturn(string returnString) {
	alias ReverseReturnFn = extern (C) void function(string);
	__gshared ReverseReturnFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ReverseReturn");
	__func(returnString);
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnVoidCallback
 */
pragma(inline, true) void NoParamReturnVoidCallback() {
	alias NoParamReturnVoidCallbackFn = extern (C) void function();
	__gshared NoParamReturnVoidCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnVoidCallback");
	__func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnBoolCallback
 *
 * @return bool: No description available.
 */
pragma(inline, true) bool NoParamReturnBoolCallback() {
	alias NoParamReturnBoolCallbackFn = extern (C) bool function();
	__gshared NoParamReturnBoolCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnBoolCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnChar8Callback
 *
 * @return char8: No description available.
 */
pragma(inline, true) char NoParamReturnChar8Callback() {
	alias NoParamReturnChar8CallbackFn = extern (C) char function();
	__gshared NoParamReturnChar8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnChar8Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnChar16Callback
 *
 * @return char16: No description available.
 */
pragma(inline, true) wchar NoParamReturnChar16Callback() {
	alias NoParamReturnChar16CallbackFn = extern (C) wchar function();
	__gshared NoParamReturnChar16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnChar16Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnInt8Callback
 *
 * @return int8: No description available.
 */
pragma(inline, true) byte NoParamReturnInt8Callback() {
	alias NoParamReturnInt8CallbackFn = extern (C) byte function();
	__gshared NoParamReturnInt8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnInt8Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnInt16Callback
 *
 * @return int16: No description available.
 */
pragma(inline, true) short NoParamReturnInt16Callback() {
	alias NoParamReturnInt16CallbackFn = extern (C) short function();
	__gshared NoParamReturnInt16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnInt16Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnInt32Callback
 *
 * @return int32: No description available.
 */
pragma(inline, true) int NoParamReturnInt32Callback() {
	alias NoParamReturnInt32CallbackFn = extern (C) int function();
	__gshared NoParamReturnInt32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnInt32Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnInt64Callback
 *
 * @return int64: No description available.
 */
pragma(inline, true) long NoParamReturnInt64Callback() {
	alias NoParamReturnInt64CallbackFn = extern (C) long function();
	__gshared NoParamReturnInt64CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnInt64Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnUInt8Callback
 *
 * @return uint8: No description available.
 */
pragma(inline, true) ubyte NoParamReturnUInt8Callback() {
	alias NoParamReturnUInt8CallbackFn = extern (C) ubyte function();
	__gshared NoParamReturnUInt8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnUInt8Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnUInt16Callback
 *
 * @return uint16: No description available.
 */
pragma(inline, true) ushort NoParamReturnUInt16Callback() {
	alias NoParamReturnUInt16CallbackFn = extern (C) ushort function();
	__gshared NoParamReturnUInt16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnUInt16Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnUInt32Callback
 *
 * @return uint32: No description available.
 */
pragma(inline, true) uint NoParamReturnUInt32Callback() {
	alias NoParamReturnUInt32CallbackFn = extern (C) uint function();
	__gshared NoParamReturnUInt32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnUInt32Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnUInt64Callback
 *
 * @return uint64: No description available.
 */
pragma(inline, true) ulong NoParamReturnUInt64Callback() {
	alias NoParamReturnUInt64CallbackFn = extern (C) ulong function();
	__gshared NoParamReturnUInt64CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnUInt64Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnPointerCallback
 *
 * @return ptr64: No description available.
 */
pragma(inline, true) uintptr_t NoParamReturnPointerCallback() {
	alias NoParamReturnPointerCallbackFn = extern (C) uintptr_t function();
	__gshared NoParamReturnPointerCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnPointerCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnFloatCallback
 *
 * @return float: No description available.
 */
pragma(inline, true) float NoParamReturnFloatCallback() {
	alias NoParamReturnFloatCallbackFn = extern (C) float function();
	__gshared NoParamReturnFloatCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnFloatCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnDoubleCallback
 *
 * @return double: No description available.
 */
pragma(inline, true) double NoParamReturnDoubleCallback() {
	alias NoParamReturnDoubleCallbackFn = extern (C) double function();
	__gshared NoParamReturnDoubleCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnDoubleCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnFunctionCallback
 *
 * @return function: No description available.
 */
pragma(inline, true) NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
	alias NoParamReturnFunctionCallbackFn = extern (C) NoParamReturnFunctionCallbackFunc function();
	__gshared NoParamReturnFunctionCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnFunctionCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnStringCallback
 *
 * @return string: No description available.
 */
pragma(inline, true) string NoParamReturnStringCallback() {
	alias NoParamReturnStringCallbackFn = extern (C) string function();
	__gshared NoParamReturnStringCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnStringCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnAnyCallback
 *
 * @return any: No description available.
 */
pragma(inline, true) PlgVariant NoParamReturnAnyCallback() {
	alias NoParamReturnAnyCallbackFn = extern (C) PlgVariant function();
	__gshared NoParamReturnAnyCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnAnyCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayBoolCallback
 *
 * @return bool[]: No description available.
 */
pragma(inline, true) bool[] NoParamReturnArrayBoolCallback() {
	alias NoParamReturnArrayBoolCallbackFn = extern (C) bool[] function();
	__gshared NoParamReturnArrayBoolCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayBoolCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayChar8Callback
 *
 * @return char8[]: No description available.
 */
pragma(inline, true) char[] NoParamReturnArrayChar8Callback() {
	alias NoParamReturnArrayChar8CallbackFn = extern (C) char[] function();
	__gshared NoParamReturnArrayChar8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayChar8Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayChar16Callback
 *
 * @return char16[]: No description available.
 */
pragma(inline, true) wchar[] NoParamReturnArrayChar16Callback() {
	alias NoParamReturnArrayChar16CallbackFn = extern (C) wchar[] function();
	__gshared NoParamReturnArrayChar16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayChar16Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayInt8Callback
 *
 * @return int8[]: No description available.
 */
pragma(inline, true) byte[] NoParamReturnArrayInt8Callback() {
	alias NoParamReturnArrayInt8CallbackFn = extern (C) byte[] function();
	__gshared NoParamReturnArrayInt8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayInt8Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayInt16Callback
 *
 * @return int16[]: No description available.
 */
pragma(inline, true) short[] NoParamReturnArrayInt16Callback() {
	alias NoParamReturnArrayInt16CallbackFn = extern (C) short[] function();
	__gshared NoParamReturnArrayInt16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayInt16Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayInt32Callback
 *
 * @return int32[]: No description available.
 */
pragma(inline, true) int[] NoParamReturnArrayInt32Callback() {
	alias NoParamReturnArrayInt32CallbackFn = extern (C) int[] function();
	__gshared NoParamReturnArrayInt32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayInt32Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayInt64Callback
 *
 * @return int64[]: No description available.
 */
pragma(inline, true) long[] NoParamReturnArrayInt64Callback() {
	alias NoParamReturnArrayInt64CallbackFn = extern (C) long[] function();
	__gshared NoParamReturnArrayInt64CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayInt64Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayUInt8Callback
 *
 * @return uint8[]: No description available.
 */
pragma(inline, true) ubyte[] NoParamReturnArrayUInt8Callback() {
	alias NoParamReturnArrayUInt8CallbackFn = extern (C) ubyte[] function();
	__gshared NoParamReturnArrayUInt8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayUInt8Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayUInt16Callback
 *
 * @return uint16[]: No description available.
 */
pragma(inline, true) ushort[] NoParamReturnArrayUInt16Callback() {
	alias NoParamReturnArrayUInt16CallbackFn = extern (C) ushort[] function();
	__gshared NoParamReturnArrayUInt16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayUInt16Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayUInt32Callback
 *
 * @return uint32[]: No description available.
 */
pragma(inline, true) ulong[] NoParamReturnArrayUInt32Callback() {
	alias NoParamReturnArrayUInt32CallbackFn = extern (C) ulong[] function();
	__gshared NoParamReturnArrayUInt32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayUInt32Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayUInt64Callback
 *
 * @return uint64[]: No description available.
 */
pragma(inline, true) ulong[] NoParamReturnArrayUInt64Callback() {
	alias NoParamReturnArrayUInt64CallbackFn = extern (C) ulong[] function();
	__gshared NoParamReturnArrayUInt64CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayUInt64Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayPointerCallback
 *
 * @return ptr64[]: No description available.
 */
pragma(inline, true) uintptr_t[] NoParamReturnArrayPointerCallback() {
	alias NoParamReturnArrayPointerCallbackFn = extern (C) uintptr_t[] function();
	__gshared NoParamReturnArrayPointerCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayPointerCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayFloatCallback
 *
 * @return float[]: No description available.
 */
pragma(inline, true) float[] NoParamReturnArrayFloatCallback() {
	alias NoParamReturnArrayFloatCallbackFn = extern (C) float[] function();
	__gshared NoParamReturnArrayFloatCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayFloatCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayDoubleCallback
 *
 * @return double[]: No description available.
 */
pragma(inline, true) double[] NoParamReturnArrayDoubleCallback() {
	alias NoParamReturnArrayDoubleCallbackFn = extern (C) double[] function();
	__gshared NoParamReturnArrayDoubleCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayDoubleCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayStringCallback
 *
 * @return string[]: No description available.
 */
pragma(inline, true) string[] NoParamReturnArrayStringCallback() {
	alias NoParamReturnArrayStringCallbackFn = extern (C) string[] function();
	__gshared NoParamReturnArrayStringCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayStringCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayAnyCallback
 *
 * @return any[]: No description available.
 */
pragma(inline, true) PlgVariant[] NoParamReturnArrayAnyCallback() {
	alias NoParamReturnArrayAnyCallbackFn = extern (C) PlgVariant[] function();
	__gshared NoParamReturnArrayAnyCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayAnyCallback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayVector2Callback
 *
 * @return vec2[]: No description available.
 */
pragma(inline, true) Vec2[] NoParamReturnArrayVector2Callback() {
	alias NoParamReturnArrayVector2CallbackFn = extern (C) Vec2[] function();
	__gshared NoParamReturnArrayVector2CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayVector2Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayVector3Callback
 *
 * @return vec3[]: No description available.
 */
pragma(inline, true) Vec3[] NoParamReturnArrayVector3Callback() {
	alias NoParamReturnArrayVector3CallbackFn = extern (C) Vec3[] function();
	__gshared NoParamReturnArrayVector3CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayVector3Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayVector4Callback
 *
 * @return vec4[]: No description available.
 */
pragma(inline, true) Vec4[] NoParamReturnArrayVector4Callback() {
	alias NoParamReturnArrayVector4CallbackFn = extern (C) Vec4[] function();
	__gshared NoParamReturnArrayVector4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayVector4Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnArrayMatrix4x4Callback
 *
 * @return mat4x4[]: No description available.
 */
pragma(inline, true) Mat4x4[] NoParamReturnArrayMatrix4x4Callback() {
	alias NoParamReturnArrayMatrix4x4CallbackFn = extern (C) Mat4x4[] function();
	__gshared NoParamReturnArrayMatrix4x4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnArrayMatrix4x4Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnVector2Callback
 *
 * @return vec2: No description available.
 */
pragma(inline, true) Vec2 NoParamReturnVector2Callback() {
	alias NoParamReturnVector2CallbackFn = extern (C) Vec2 function();
	__gshared NoParamReturnVector2CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnVector2Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnVector3Callback
 *
 * @return vec3: No description available.
 */
pragma(inline, true) Vec3 NoParamReturnVector3Callback() {
	alias NoParamReturnVector3CallbackFn = extern (C) Vec3 function();
	__gshared NoParamReturnVector3CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnVector3Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnVector4Callback
 *
 * @return vec4: No description available.
 */
pragma(inline, true) Vec4 NoParamReturnVector4Callback() {
	alias NoParamReturnVector4CallbackFn = extern (C) Vec4 function();
	__gshared NoParamReturnVector4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnVector4Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function NoParamReturnMatrix4x4Callback
 *
 * @return mat4x4: No description available.
 */
pragma(inline, true) Mat4x4 NoParamReturnMatrix4x4Callback() {
	alias NoParamReturnMatrix4x4CallbackFn = extern (C) Mat4x4 function();
	__gshared NoParamReturnMatrix4x4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.NoParamReturnMatrix4x4Callback");
	return __func();
}

/**
 * @brief No description provided.
 *
 * @function Param1Callback
 * @param a (int32): No description available.
 */
pragma(inline, true) void Param1Callback(int a) {
	alias Param1CallbackFn = extern (C) void function(int);
	__gshared Param1CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param1Callback");
	__func(a);
}

/**
 * @brief No description provided.
 *
 * @function Param2Callback
 * @param a (int32): No description available.
 * @param b (float): No description available.
 */
pragma(inline, true) void Param2Callback(int a, float b) {
	alias Param2CallbackFn = extern (C) void function(int, float);
	__gshared Param2CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param2Callback");
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
pragma(inline, true) void Param3Callback(int a, float b, double c) {
	alias Param3CallbackFn = extern (C) void function(int, float, double);
	__gshared Param3CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param3Callback");
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
pragma(inline, true) void Param4Callback(int a, float b, double c, Vec4 d) {
	alias Param4CallbackFn = extern (C) void function(int, float, double, Vec4);
	__gshared Param4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param4Callback");
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
pragma(inline, true) void Param5Callback(int a, float b, double c, Vec4 d, long[] e) {
	alias Param5CallbackFn = extern (C) void function(int, float, double, Vec4, long[]);
	__gshared Param5CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param5Callback");
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
pragma(inline, true) void Param6Callback(int a, float b, double c, Vec4 d, long[] e, char f) {
	alias Param6CallbackFn = extern (C) void function(int, float, double, Vec4, long[], char);
	__gshared Param6CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param6Callback");
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
pragma(inline, true) void Param7Callback(int a, float b, double c, Vec4 d, long[] e, char f, string g) {
	alias Param7CallbackFn = extern (C) void function(int, float, double, Vec4, long[], char, string);
	__gshared Param7CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param7Callback");
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
pragma(inline, true) void Param8Callback(int a, float b, double c, Vec4 d, long[] e, char f, string g, wchar h) {
	alias Param8CallbackFn = extern (C) void function(int, float, double, Vec4, long[], char, string, wchar);
	__gshared Param8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param8Callback");
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
pragma(inline, true) void Param9Callback(int a, float b, double c, Vec4 d, long[] e, char f, string g, wchar h, short k) {
	alias Param9CallbackFn = extern (C) void function(int, float, double, Vec4, long[], char, string, wchar, short);
	__gshared Param9CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param9Callback");
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
pragma(inline, true) void Param10Callback(int a, float b, double c, Vec4 d, long[] e, char f, string g, wchar h, short k, uintptr_t l) {
	alias Param10CallbackFn = extern (C) void function(int, float, double, Vec4, long[], char, string, wchar, short, uintptr_t);
	__gshared Param10CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.Param10Callback");
	__func(a, b, c, d, e, f, g, h, k, l);
}

/**
 * @brief No description provided.
 *
 * @function ParamRef1Callback
 * @param a (int32): No description available.
 */
pragma(inline, true) void ParamRef1Callback(refint a) {
	alias ParamRef1CallbackFn = extern (C) void function(refint);
	__gshared ParamRef1CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef1Callback");
	__func(a);
}

/**
 * @brief No description provided.
 *
 * @function ParamRef2Callback
 * @param a (int32): No description available.
 * @param b (float): No description available.
 */
pragma(inline, true) void ParamRef2Callback(refint a, reffloat b) {
	alias ParamRef2CallbackFn = extern (C) void function(refint, reffloat);
	__gshared ParamRef2CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef2Callback");
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
pragma(inline, true) void ParamRef3Callback(refint a, reffloat b, refdouble c) {
	alias ParamRef3CallbackFn = extern (C) void function(refint, reffloat, refdouble);
	__gshared ParamRef3CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef3Callback");
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
pragma(inline, true) void ParamRef4Callback(refint a, reffloat b, refdouble c, refVec4 d) {
	alias ParamRef4CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4);
	__gshared ParamRef4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef4Callback");
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
pragma(inline, true) void ParamRef5Callback(refint a, reffloat b, refdouble c, refVec4 d, reflong[] e) {
	alias ParamRef5CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4, reflong[]);
	__gshared ParamRef5CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef5Callback");
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
pragma(inline, true) void ParamRef6Callback(refint a, reffloat b, refdouble c, refVec4 d, reflong[] e, refchar f) {
	alias ParamRef6CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4, reflong[], refchar);
	__gshared ParamRef6CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef6Callback");
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
pragma(inline, true) void ParamRef7Callback(refint a, reffloat b, refdouble c, refVec4 d, reflong[] e, refchar f, refstring g) {
	alias ParamRef7CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4, reflong[], refchar, refstring);
	__gshared ParamRef7CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef7Callback");
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
pragma(inline, true) void ParamRef8Callback(refint a, reffloat b, refdouble c, refVec4 d, reflong[] e, refchar f, refstring g, refwchar h) {
	alias ParamRef8CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4, reflong[], refchar, refstring, refwchar);
	__gshared ParamRef8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef8Callback");
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
pragma(inline, true) void ParamRef9Callback(refint a, reffloat b, refdouble c, refVec4 d, reflong[] e, refchar f, refstring g, refwchar h, refshort k) {
	alias ParamRef9CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4, reflong[], refchar, refstring, refwchar, refshort);
	__gshared ParamRef9CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef9Callback");
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
pragma(inline, true) void ParamRef10Callback(refint a, reffloat b, refdouble c, refVec4 d, reflong[] e, refchar f, refstring g, refwchar h, refshort k, refuintptr_t l) {
	alias ParamRef10CallbackFn = extern (C) void function(refint, reffloat, refdouble, refVec4, reflong[], refchar, refstring, refwchar, refshort, refuintptr_t);
	__gshared ParamRef10CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRef10Callback");
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
pragma(inline, true) void ParamRefVectorsCallback(refbool[] p1, refchar[] p2, refwchar[] p3, refbyte[] p4, refshort[] p5, refint[] p6, reflong[] p7, refubyte[] p8, refushort[] p9, refulong[] p10, refulong[] p11, refuintptr_t[] p12, reffloat[] p13, refdouble[] p14, refstring[] p15) {
	alias ParamRefVectorsCallbackFn = extern (C) void function(refbool[], refchar[], refwchar[], refbyte[], refshort[], refint[], reflong[], refubyte[], refushort[], refulong[], refulong[], refuintptr_t[], reffloat[], refdouble[], refstring[]);
	__gshared ParamRefVectorsCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamRefVectorsCallback");
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
pragma(inline, true) long ParamAllPrimitivesCallback(bool p1, char p2, wchar p3, byte p4, short p5, int p6, long p7, ubyte p8, ushort p9, uint p10, ulong p11, uintptr_t p12, float p13, double p14) {
	alias ParamAllPrimitivesCallbackFn = extern (C) long function(bool, char, wchar, byte, short, int, long, ubyte, ushort, uint, ulong, uintptr_t, float, double);
	__gshared ParamAllPrimitivesCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamAllPrimitivesCallback");
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
pragma(inline, true) int ParamEnumCallback(Example p1, Example p2) {
	alias ParamEnumCallbackFn = extern (C) int function(Example, Example);
	__gshared ParamEnumCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamEnumCallback");
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
pragma(inline, true) int ParamEnumRefCallback(refExample p1, refExample p2) {
	alias ParamEnumRefCallbackFn = extern (C) int function(refExample, refExample);
	__gshared ParamEnumRefCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamEnumRefCallback");
	return __func(p1, p2);
}

/**
 * @brief No description provided.
 *
 * @function ParamVariantCallback
 * @param p1 (any): No description available.
 * @param p2 (any[]): No description available.
 */
pragma(inline, true) void ParamVariantCallback(PlgVariant p1, PlgVariant[] p2) {
	alias ParamVariantCallbackFn = extern (C) void function(PlgVariant, PlgVariant[]);
	__gshared ParamVariantCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamVariantCallback");
	__func(p1, p2);
}

/**
 * @brief No description provided.
 *
 * @function ParamVariantRefCallback
 * @param p1 (any): No description available.
 * @param p2 (any[]): No description available.
 */
pragma(inline, true) void ParamVariantRefCallback(refPlgVariant p1, refPlgVariant[] p2) {
	alias ParamVariantRefCallbackFn = extern (C) void function(refPlgVariant, refPlgVariant[]);
	__gshared ParamVariantRefCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.ParamVariantRefCallback");
	__func(p1, p2);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVoidCallback
 * @param func (function): No description available.
 */
pragma(inline, true) void CallFuncVoidCallback(FuncVoid func) {
	alias CallFuncVoidCallbackFn = extern (C) void function(FuncVoid);
	__gshared CallFuncVoidCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVoidCallback");
	__func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncBoolCallback
 * @param func (function): No description available.
 *
 * @return bool: No description available.
 */
pragma(inline, true) bool CallFuncBoolCallback(FuncBool func) {
	alias CallFuncBoolCallbackFn = extern (C) bool function(FuncBool);
	__gshared CallFuncBoolCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncBoolCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncChar8Callback
 * @param func (function): No description available.
 *
 * @return char8: No description available.
 */
pragma(inline, true) char CallFuncChar8Callback(FuncChar8 func) {
	alias CallFuncChar8CallbackFn = extern (C) char function(FuncChar8);
	__gshared CallFuncChar8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncChar8Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncChar16Callback
 * @param func (function): No description available.
 *
 * @return char16: No description available.
 */
pragma(inline, true) wchar CallFuncChar16Callback(FuncChar16 func) {
	alias CallFuncChar16CallbackFn = extern (C) wchar function(FuncChar16);
	__gshared CallFuncChar16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncChar16Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt8Callback
 * @param func (function): No description available.
 *
 * @return int8: No description available.
 */
pragma(inline, true) byte CallFuncInt8Callback(FuncInt8 func) {
	alias CallFuncInt8CallbackFn = extern (C) byte function(FuncInt8);
	__gshared CallFuncInt8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt8Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt16Callback
 * @param func (function): No description available.
 *
 * @return int16: No description available.
 */
pragma(inline, true) short CallFuncInt16Callback(FuncInt16 func) {
	alias CallFuncInt16CallbackFn = extern (C) short function(FuncInt16);
	__gshared CallFuncInt16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt16Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt32Callback
 * @param func (function): No description available.
 *
 * @return int32: No description available.
 */
pragma(inline, true) int CallFuncInt32Callback(FuncInt32 func) {
	alias CallFuncInt32CallbackFn = extern (C) int function(FuncInt32);
	__gshared CallFuncInt32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt32Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt64Callback
 * @param func (function): No description available.
 *
 * @return int64: No description available.
 */
pragma(inline, true) long CallFuncInt64Callback(FuncInt64 func) {
	alias CallFuncInt64CallbackFn = extern (C) long function(FuncInt64);
	__gshared CallFuncInt64CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt64Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt8Callback
 * @param func (function): No description available.
 *
 * @return uint8: No description available.
 */
pragma(inline, true) ubyte CallFuncUInt8Callback(FuncUInt8 func) {
	alias CallFuncUInt8CallbackFn = extern (C) ubyte function(FuncUInt8);
	__gshared CallFuncUInt8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt8Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt16Callback
 * @param func (function): No description available.
 *
 * @return uint16: No description available.
 */
pragma(inline, true) ushort CallFuncUInt16Callback(FuncUInt16 func) {
	alias CallFuncUInt16CallbackFn = extern (C) ushort function(FuncUInt16);
	__gshared CallFuncUInt16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt16Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt32Callback
 * @param func (function): No description available.
 *
 * @return uint32: No description available.
 */
pragma(inline, true) uint CallFuncUInt32Callback(FuncUInt32 func) {
	alias CallFuncUInt32CallbackFn = extern (C) uint function(FuncUInt32);
	__gshared CallFuncUInt32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt32Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt64Callback
 * @param func (function): No description available.
 *
 * @return uint64: No description available.
 */
pragma(inline, true) ulong CallFuncUInt64Callback(FuncUInt64 func) {
	alias CallFuncUInt64CallbackFn = extern (C) ulong function(FuncUInt64);
	__gshared CallFuncUInt64CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt64Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncPtrCallback
 * @param func (function): No description available.
 *
 * @return ptr64: No description available.
 */
pragma(inline, true) uintptr_t CallFuncPtrCallback(FuncPtr func) {
	alias CallFuncPtrCallbackFn = extern (C) uintptr_t function(FuncPtr);
	__gshared CallFuncPtrCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncPtrCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncFloatCallback
 * @param func (function): No description available.
 *
 * @return float: No description available.
 */
pragma(inline, true) float CallFuncFloatCallback(FuncFloat func) {
	alias CallFuncFloatCallbackFn = extern (C) float function(FuncFloat);
	__gshared CallFuncFloatCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncFloatCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncDoubleCallback
 * @param func (function): No description available.
 *
 * @return double: No description available.
 */
pragma(inline, true) double CallFuncDoubleCallback(FuncDouble func) {
	alias CallFuncDoubleCallbackFn = extern (C) double function(FuncDouble);
	__gshared CallFuncDoubleCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncDoubleCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncStringCallback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFuncStringCallback(FuncString func) {
	alias CallFuncStringCallbackFn = extern (C) string function(FuncString);
	__gshared CallFuncStringCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncStringCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncAnyCallback
 * @param func (function): No description available.
 *
 * @return any: No description available.
 */
pragma(inline, true) PlgVariant CallFuncAnyCallback(FuncAny func) {
	alias CallFuncAnyCallbackFn = extern (C) PlgVariant function(FuncAny);
	__gshared CallFuncAnyCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncAnyCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncFunctionCallback
 * @param func (function): No description available.
 *
 * @return ptr64: No description available.
 */
pragma(inline, true) uintptr_t CallFuncFunctionCallback(FuncFunction func) {
	alias CallFuncFunctionCallbackFn = extern (C) uintptr_t function(FuncFunction);
	__gshared CallFuncFunctionCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncFunctionCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncBoolVectorCallback
 * @param func (function): No description available.
 *
 * @return bool[]: No description available.
 */
pragma(inline, true) bool[] CallFuncBoolVectorCallback(FuncBoolVector func) {
	alias CallFuncBoolVectorCallbackFn = extern (C) bool[] function(FuncBoolVector);
	__gshared CallFuncBoolVectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncBoolVectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncChar8VectorCallback
 * @param func (function): No description available.
 *
 * @return char8[]: No description available.
 */
pragma(inline, true) char[] CallFuncChar8VectorCallback(FuncChar8Vector func) {
	alias CallFuncChar8VectorCallbackFn = extern (C) char[] function(FuncChar8Vector);
	__gshared CallFuncChar8VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncChar8VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncChar16VectorCallback
 * @param func (function): No description available.
 *
 * @return char16[]: No description available.
 */
pragma(inline, true) wchar[] CallFuncChar16VectorCallback(FuncChar16Vector func) {
	alias CallFuncChar16VectorCallbackFn = extern (C) wchar[] function(FuncChar16Vector);
	__gshared CallFuncChar16VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncChar16VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt8VectorCallback
 * @param func (function): No description available.
 *
 * @return int8[]: No description available.
 */
pragma(inline, true) byte[] CallFuncInt8VectorCallback(FuncInt8Vector func) {
	alias CallFuncInt8VectorCallbackFn = extern (C) byte[] function(FuncInt8Vector);
	__gshared CallFuncInt8VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt8VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt16VectorCallback
 * @param func (function): No description available.
 *
 * @return int16[]: No description available.
 */
pragma(inline, true) short[] CallFuncInt16VectorCallback(FuncInt16Vector func) {
	alias CallFuncInt16VectorCallbackFn = extern (C) short[] function(FuncInt16Vector);
	__gshared CallFuncInt16VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt16VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt32VectorCallback
 * @param func (function): No description available.
 *
 * @return int32[]: No description available.
 */
pragma(inline, true) int[] CallFuncInt32VectorCallback(FuncInt32Vector func) {
	alias CallFuncInt32VectorCallbackFn = extern (C) int[] function(FuncInt32Vector);
	__gshared CallFuncInt32VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt32VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncInt64VectorCallback
 * @param func (function): No description available.
 *
 * @return int64[]: No description available.
 */
pragma(inline, true) long[] CallFuncInt64VectorCallback(FuncInt64Vector func) {
	alias CallFuncInt64VectorCallbackFn = extern (C) long[] function(FuncInt64Vector);
	__gshared CallFuncInt64VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncInt64VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt8VectorCallback
 * @param func (function): No description available.
 *
 * @return uint8[]: No description available.
 */
pragma(inline, true) ubyte[] CallFuncUInt8VectorCallback(FuncUInt8Vector func) {
	alias CallFuncUInt8VectorCallbackFn = extern (C) ubyte[] function(FuncUInt8Vector);
	__gshared CallFuncUInt8VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt8VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt16VectorCallback
 * @param func (function): No description available.
 *
 * @return uint16[]: No description available.
 */
pragma(inline, true) ushort[] CallFuncUInt16VectorCallback(FuncUInt16Vector func) {
	alias CallFuncUInt16VectorCallbackFn = extern (C) ushort[] function(FuncUInt16Vector);
	__gshared CallFuncUInt16VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt16VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt32VectorCallback
 * @param func (function): No description available.
 *
 * @return uint32[]: No description available.
 */
pragma(inline, true) ulong[] CallFuncUInt32VectorCallback(FuncUInt32Vector func) {
	alias CallFuncUInt32VectorCallbackFn = extern (C) ulong[] function(FuncUInt32Vector);
	__gshared CallFuncUInt32VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt32VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncUInt64VectorCallback
 * @param func (function): No description available.
 *
 * @return uint64[]: No description available.
 */
pragma(inline, true) ulong[] CallFuncUInt64VectorCallback(FuncUInt64Vector func) {
	alias CallFuncUInt64VectorCallbackFn = extern (C) ulong[] function(FuncUInt64Vector);
	__gshared CallFuncUInt64VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncUInt64VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncPtrVectorCallback
 * @param func (function): No description available.
 *
 * @return ptr64[]: No description available.
 */
pragma(inline, true) uintptr_t[] CallFuncPtrVectorCallback(FuncPtrVector func) {
	alias CallFuncPtrVectorCallbackFn = extern (C) uintptr_t[] function(FuncPtrVector);
	__gshared CallFuncPtrVectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncPtrVectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncFloatVectorCallback
 * @param func (function): No description available.
 *
 * @return float[]: No description available.
 */
pragma(inline, true) float[] CallFuncFloatVectorCallback(FuncFloatVector func) {
	alias CallFuncFloatVectorCallbackFn = extern (C) float[] function(FuncFloatVector);
	__gshared CallFuncFloatVectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncFloatVectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncDoubleVectorCallback
 * @param func (function): No description available.
 *
 * @return double[]: No description available.
 */
pragma(inline, true) double[] CallFuncDoubleVectorCallback(FuncDoubleVector func) {
	alias CallFuncDoubleVectorCallbackFn = extern (C) double[] function(FuncDoubleVector);
	__gshared CallFuncDoubleVectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncDoubleVectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncStringVectorCallback
 * @param func (function): No description available.
 *
 * @return string[]: No description available.
 */
pragma(inline, true) string[] CallFuncStringVectorCallback(FuncStringVector func) {
	alias CallFuncStringVectorCallbackFn = extern (C) string[] function(FuncStringVector);
	__gshared CallFuncStringVectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncStringVectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncAnyVectorCallback
 * @param func (function): No description available.
 *
 * @return any[]: No description available.
 */
pragma(inline, true) PlgVariant[] CallFuncAnyVectorCallback(FuncAnyVector func) {
	alias CallFuncAnyVectorCallbackFn = extern (C) PlgVariant[] function(FuncAnyVector);
	__gshared CallFuncAnyVectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncAnyVectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVec2VectorCallback
 * @param func (function): No description available.
 *
 * @return vec2[]: No description available.
 */
pragma(inline, true) Vec2[] CallFuncVec2VectorCallback(FuncVec2Vector func) {
	alias CallFuncVec2VectorCallbackFn = extern (C) Vec2[] function(FuncVec2Vector);
	__gshared CallFuncVec2VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVec2VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVec3VectorCallback
 * @param func (function): No description available.
 *
 * @return vec3[]: No description available.
 */
pragma(inline, true) Vec3[] CallFuncVec3VectorCallback(FuncVec3Vector func) {
	alias CallFuncVec3VectorCallbackFn = extern (C) Vec3[] function(FuncVec3Vector);
	__gshared CallFuncVec3VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVec3VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVec4VectorCallback
 * @param func (function): No description available.
 *
 * @return vec4[]: No description available.
 */
pragma(inline, true) Vec4[] CallFuncVec4VectorCallback(FuncVec4Vector func) {
	alias CallFuncVec4VectorCallbackFn = extern (C) Vec4[] function(FuncVec4Vector);
	__gshared CallFuncVec4VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVec4VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncMat4x4VectorCallback
 * @param func (function): No description available.
 *
 * @return mat4x4[]: No description available.
 */
pragma(inline, true) Mat4x4[] CallFuncMat4x4VectorCallback(FuncMat4x4Vector func) {
	alias CallFuncMat4x4VectorCallbackFn = extern (C) Mat4x4[] function(FuncMat4x4Vector);
	__gshared CallFuncMat4x4VectorCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncMat4x4VectorCallback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVec2Callback
 * @param func (function): No description available.
 *
 * @return vec2: No description available.
 */
pragma(inline, true) Vec2 CallFuncVec2Callback(FuncVec2 func) {
	alias CallFuncVec2CallbackFn = extern (C) Vec2 function(FuncVec2);
	__gshared CallFuncVec2CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVec2Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVec3Callback
 * @param func (function): No description available.
 *
 * @return vec3: No description available.
 */
pragma(inline, true) Vec3 CallFuncVec3Callback(FuncVec3 func) {
	alias CallFuncVec3CallbackFn = extern (C) Vec3 function(FuncVec3);
	__gshared CallFuncVec3CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVec3Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncVec4Callback
 * @param func (function): No description available.
 *
 * @return vec4: No description available.
 */
pragma(inline, true) Vec4 CallFuncVec4Callback(FuncVec4 func) {
	alias CallFuncVec4CallbackFn = extern (C) Vec4 function(FuncVec4);
	__gshared CallFuncVec4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncVec4Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncMat4x4Callback
 * @param func (function): No description available.
 *
 * @return mat4x4: No description available.
 */
pragma(inline, true) Mat4x4 CallFuncMat4x4Callback(FuncMat4x4 func) {
	alias CallFuncMat4x4CallbackFn = extern (C) Mat4x4 function(FuncMat4x4);
	__gshared CallFuncMat4x4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncMat4x4Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc1Callback
 * @param func (function): No description available.
 *
 * @return int32: No description available.
 */
pragma(inline, true) int CallFunc1Callback(Func1 func) {
	alias CallFunc1CallbackFn = extern (C) int function(Func1);
	__gshared CallFunc1CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc1Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc2Callback
 * @param func (function): No description available.
 *
 * @return char8: No description available.
 */
pragma(inline, true) char CallFunc2Callback(Func2 func) {
	alias CallFunc2CallbackFn = extern (C) char function(Func2);
	__gshared CallFunc2CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc2Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc3Callback
 * @param func (function): No description available.
 */
pragma(inline, true) void CallFunc3Callback(Func3 func) {
	alias CallFunc3CallbackFn = extern (C) void function(Func3);
	__gshared CallFunc3CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc3Callback");
	__func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc4Callback
 * @param func (function): No description available.
 *
 * @return vec4: No description available.
 */
pragma(inline, true) Vec4 CallFunc4Callback(Func4 func) {
	alias CallFunc4CallbackFn = extern (C) Vec4 function(Func4);
	__gshared CallFunc4CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc4Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc5Callback
 * @param func (function): No description available.
 *
 * @return bool: No description available.
 */
pragma(inline, true) bool CallFunc5Callback(Func5 func) {
	alias CallFunc5CallbackFn = extern (C) bool function(Func5);
	__gshared CallFunc5CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc5Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc6Callback
 * @param func (function): No description available.
 *
 * @return int64: No description available.
 */
pragma(inline, true) long CallFunc6Callback(Func6 func) {
	alias CallFunc6CallbackFn = extern (C) long function(Func6);
	__gshared CallFunc6CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc6Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc7Callback
 * @param func (function): No description available.
 *
 * @return double: No description available.
 */
pragma(inline, true) double CallFunc7Callback(Func7 func) {
	alias CallFunc7CallbackFn = extern (C) double function(Func7);
	__gshared CallFunc7CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc7Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc8Callback
 * @param func (function): No description available.
 *
 * @return mat4x4: No description available.
 */
pragma(inline, true) Mat4x4 CallFunc8Callback(Func8 func) {
	alias CallFunc8CallbackFn = extern (C) Mat4x4 function(Func8);
	__gshared CallFunc8CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc8Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc9Callback
 * @param func (function): No description available.
 */
pragma(inline, true) void CallFunc9Callback(Func9 func) {
	alias CallFunc9CallbackFn = extern (C) void function(Func9);
	__gshared CallFunc9CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc9Callback");
	__func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc10Callback
 * @param func (function): No description available.
 *
 * @return uint32: No description available.
 */
pragma(inline, true) uint CallFunc10Callback(Func10 func) {
	alias CallFunc10CallbackFn = extern (C) uint function(Func10);
	__gshared CallFunc10CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc10Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc11Callback
 * @param func (function): No description available.
 *
 * @return ptr64: No description available.
 */
pragma(inline, true) uintptr_t CallFunc11Callback(Func11 func) {
	alias CallFunc11CallbackFn = extern (C) uintptr_t function(Func11);
	__gshared CallFunc11CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc11Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc12Callback
 * @param func (function): No description available.
 *
 * @return bool: No description available.
 */
pragma(inline, true) bool CallFunc12Callback(Func12 func) {
	alias CallFunc12CallbackFn = extern (C) bool function(Func12);
	__gshared CallFunc12CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc12Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc13Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc13Callback(Func13 func) {
	alias CallFunc13CallbackFn = extern (C) string function(Func13);
	__gshared CallFunc13CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc13Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc14Callback
 * @param func (function): No description available.
 *
 * @return string[]: No description available.
 */
pragma(inline, true) string[] CallFunc14Callback(Func14 func) {
	alias CallFunc14CallbackFn = extern (C) string[] function(Func14);
	__gshared CallFunc14CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc14Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc15Callback
 * @param func (function): No description available.
 *
 * @return int16: No description available.
 */
pragma(inline, true) short CallFunc15Callback(Func15 func) {
	alias CallFunc15CallbackFn = extern (C) short function(Func15);
	__gshared CallFunc15CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc15Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc16Callback
 * @param func (function): No description available.
 *
 * @return ptr64: No description available.
 */
pragma(inline, true) uintptr_t CallFunc16Callback(Func16 func) {
	alias CallFunc16CallbackFn = extern (C) uintptr_t function(Func16);
	__gshared CallFunc16CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc16Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc17Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc17Callback(Func17 func) {
	alias CallFunc17CallbackFn = extern (C) string function(Func17);
	__gshared CallFunc17CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc17Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc18Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc18Callback(Func18 func) {
	alias CallFunc18CallbackFn = extern (C) string function(Func18);
	__gshared CallFunc18CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc18Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc19Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc19Callback(Func19 func) {
	alias CallFunc19CallbackFn = extern (C) string function(Func19);
	__gshared CallFunc19CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc19Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc20Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc20Callback(Func20 func) {
	alias CallFunc20CallbackFn = extern (C) string function(Func20);
	__gshared CallFunc20CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc20Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc21Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc21Callback(Func21 func) {
	alias CallFunc21CallbackFn = extern (C) string function(Func21);
	__gshared CallFunc21CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc21Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc22Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc22Callback(Func22 func) {
	alias CallFunc22CallbackFn = extern (C) string function(Func22);
	__gshared CallFunc22CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc22Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc23Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc23Callback(Func23 func) {
	alias CallFunc23CallbackFn = extern (C) string function(Func23);
	__gshared CallFunc23CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc23Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc24Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc24Callback(Func24 func) {
	alias CallFunc24CallbackFn = extern (C) string function(Func24);
	__gshared CallFunc24CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc24Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc25Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc25Callback(Func25 func) {
	alias CallFunc25CallbackFn = extern (C) string function(Func25);
	__gshared CallFunc25CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc25Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc26Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc26Callback(Func26 func) {
	alias CallFunc26CallbackFn = extern (C) string function(Func26);
	__gshared CallFunc26CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc26Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc27Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc27Callback(Func27 func) {
	alias CallFunc27CallbackFn = extern (C) string function(Func27);
	__gshared CallFunc27CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc27Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc28Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc28Callback(Func28 func) {
	alias CallFunc28CallbackFn = extern (C) string function(Func28);
	__gshared CallFunc28CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc28Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc29Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc29Callback(Func29 func) {
	alias CallFunc29CallbackFn = extern (C) string function(Func29);
	__gshared CallFunc29CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc29Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc30Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc30Callback(Func30 func) {
	alias CallFunc30CallbackFn = extern (C) string function(Func30);
	__gshared CallFunc30CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc30Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc31Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc31Callback(Func31 func) {
	alias CallFunc31CallbackFn = extern (C) string function(Func31);
	__gshared CallFunc31CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc31Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc32Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc32Callback(Func32 func) {
	alias CallFunc32CallbackFn = extern (C) string function(Func32);
	__gshared CallFunc32CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc32Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFunc33Callback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFunc33Callback(Func33 func) {
	alias CallFunc33CallbackFn = extern (C) string function(Func33);
	__gshared CallFunc33CallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFunc33Callback");
	return __func(func);
}

/**
 * @brief No description provided.
 *
 * @function CallFuncEnumCallback
 * @param func (function): No description available.
 *
 * @return string: No description available.
 */
pragma(inline, true) string CallFuncEnumCallback(FuncEnum func) {
	alias CallFuncEnumCallbackFn = extern (C) string function(FuncEnum);
	__gshared CallFuncEnumCallbackFn __func = nullptr;
	if (__func == nullptr) __func = plugify.GetMethodPtr("cross_call_master.CallFuncEnumCallback");
	return __func(func);
}

