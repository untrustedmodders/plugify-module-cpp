using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated with https://github.com/untrustedmodders/plugify-module-dotnet/blob/main/generator/generator.py from cross_call_master

namespace cross_call_master {
#pragma warning disable CS0649

	public enum Example : int
	{
		First = 1,
		Second = 2,
		Third = 3,
		Forth = 4,
	}



	public delegate int NoParamReturnFunctionCallbackFunc();
	public delegate void FuncVoid();
	public delegate Bool8 FuncBool();
	public delegate Char8 FuncChar8();
	public delegate Char16 FuncChar16();
	public delegate sbyte FuncInt8();
	public delegate short FuncInt16();
	public delegate int FuncInt32();
	public delegate long FuncInt64();
	public delegate byte FuncUInt8();
	public delegate ushort FuncUInt16();
	public delegate uint FuncUInt32();
	public delegate ulong FuncUInt64();
	public delegate nint FuncPtr();
	public delegate float FuncFloat();
	public delegate double FuncDouble();
	public delegate string FuncString();
	public delegate object? FuncAny();
	public delegate delegate FuncFunction();
	public delegate Bool8[] FuncBoolVector();
	public delegate Char8[] FuncChar8Vector();
	public delegate Char16[] FuncChar16Vector();
	public delegate sbyte[] FuncInt8Vector();
	public delegate short[] FuncInt16Vector();
	public delegate int[] FuncInt32Vector();
	public delegate long[] FuncInt64Vector();
	public delegate byte[] FuncUInt8Vector();
	public delegate ushort[] FuncUInt16Vector();
	public delegate uint[] FuncUInt32Vector();
	public delegate ulong[] FuncUInt64Vector();
	public delegate nint[] FuncPtrVector();
	public delegate float[] FuncFloatVector();
	public delegate double[] FuncDoubleVector();
	public delegate string[] FuncStringVector();
	public delegate object?[] FuncAnyVector();
	public delegate Vector2[] FuncVec2Vector();
	public delegate Vector3[] FuncVec3Vector();
	public delegate Vector4[] FuncVec4Vector();
	public delegate Matrix4x4[] FuncMat4x4Vector();
	public delegate Vector2 FuncVec2();
	public delegate Vector3 FuncVec3();
	public delegate Vector4 FuncVec4();
	public delegate Matrix4x4 FuncMat4x4();
	public delegate int Func1(ref Vector3 a);
	public delegate Char8 Func2(float a, long b);
	public delegate void Func3(nint a, ref Vector4 b, string c);
	public delegate Vector4 Func4(Bool8 a, int b, Char16 c, ref Matrix4x4 d);
	public delegate Bool8 Func5(sbyte a, ref Vector2 b, nint c, double d, ulong[] e);
	public delegate long Func6(string a, float b, float[] c, short d, byte[] e, nint f);
	public delegate double Func7(Char8[] vecC, ushort u16, Char16 ch16, uint[] vecU32, ref Vector4 vec4, Bool8 b, ulong u64);
	public delegate Matrix4x4 Func8(ref Vector3 vec3, uint[] vecU32, short i16, Bool8 b, ref Vector4 vec4, Char16[] vecC16, Char16 ch16, int i32);
	public delegate void Func9(float f, ref Vector2 vec2, sbyte[] vecI8, ulong u64, Bool8 b, string str, ref Vector4 vec4, short i16, nint ptr);
	public delegate uint Func10(ref Vector4 vec4, ref Matrix4x4 mat, uint[] vecU32, ulong u64, Char8[] vecC, int i32, Bool8 b, ref Vector2 vec2, long i64, double d);
	public delegate nint Func11(Bool8[] vecB, Char16 ch16, byte u8, double d, ref Vector3 vec3, sbyte[] vecI8, long i64, ushort u16, float f, ref Vector2 vec2, uint u32);
	public delegate Bool8 Func12(nint ptr, double[] vecD, uint u32, double d, Bool8 b, int i32, sbyte i8, ulong u64, float f, nint[] vecPtr, long i64, Char8 ch);
	public delegate string Func13(long i64, Char8[] vecC, ushort d, float f, Bool8[] b, ref Vector4 vec4, string str, int int32, ref Vector3 vec3, nint ptr, ref Vector2 vec2, byte[] arr, short i16);
	public delegate string[] Func14(Char8[] vecC, uint[] vecU32, ref Matrix4x4 mat, Bool8 b, Char16 ch16, int i32, float[] vecF, ushort u16, byte[] vecU8, sbyte i8, ref Vector3 vec3, ref Vector4 vec4, double d, nint ptr);
	public delegate short Func15(short[] vecI16, ref Matrix4x4 mat, ref Vector4 vec4, nint ptr, ulong u64, uint[] vecU32, Bool8 b, float f, Char16[] vecC16, byte u8, int i32, ref Vector2 vec2, ushort u16, double d, byte[] vecU8);
	public delegate nint Func16(Bool8[] vecB, short i16, sbyte[] vecI8, ref Vector4 vec4, ref Matrix4x4 mat, ref Vector2 vec2, ulong[] vecU64, Char8[] vecC, string str, long i64, uint[] vecU32, ref Vector3 vec3, float f, double d, sbyte i8, ushort u16);
	public delegate void Func17(ref int i32);
	public delegate Vector2 Func18(ref sbyte i8, ref short i16);
	public delegate void Func19(ref uint u32, ref Vector3 vec3, ref uint[] vecU32);
	public delegate int Func20(ref Char16 ch16, ref Vector4 vec4, ref ulong[] vecU64, ref Char8 ch);
	public delegate float Func21(ref Matrix4x4 mat, ref int[] vecI32, ref Vector2 vec2, ref Bool8 b, ref double extraParam);
	public delegate ulong Func22(ref nint ptr64Ref, ref uint uint32Ref, ref double[] vectorDoubleRef, ref short int16Ref, ref string plgStringRef, ref Vector4 plgVector4Ref);
	public delegate void Func23(ref ulong uint64Ref, ref Vector2 plgVector2Ref, ref short[] vectorInt16Ref, ref Char16 char16Ref, ref float floatRef, ref sbyte int8Ref, ref byte[] vectorUInt8Ref);
	public delegate Matrix4x4 Func24(ref Char8[] vectorCharRef, ref long int64Ref, ref byte[] vectorUInt8Ref, ref Vector4 plgVector4Ref, ref ulong uint64Ref, ref nint[] vectorptr64Ref, ref double doubleRef, ref nint[] vectorptr64Ref2);
	public delegate double Func25(ref int int32Ref, ref nint[] vectorptr64Ref, ref Bool8 boolRef, ref byte uint8Ref, ref string plgStringRef, ref Vector3 plgVector3Ref, ref long int64Ref, ref Vector4 plgVector4Ref, ref ushort uint16Ref);
	public delegate Char8 Func26(ref Char16 char16Ref, ref Vector2 plgVector2Ref, ref Matrix4x4 plgMatrix4x4Ref, ref float[] vectorFloatRef, ref short int16Ref, ref ulong uint64Ref, ref uint uint32Ref, ref ushort[] vectorUInt16Ref, ref nint ptr64Ref, ref Bool8 boolRef);
	public delegate byte Func27(ref float floatRef, ref Vector3 plgVector3Ref, ref nint ptr64Ref, ref Vector2 plgVector2Ref, ref short[] vectorInt16Ref, ref Matrix4x4 plgMatrix4x4Ref, ref Bool8 boolRef, ref Vector4 plgVector4Ref, ref sbyte int8Ref, ref int int32Ref, ref byte[] vectorUInt8Ref);
	public delegate string Func28(ref nint ptr64Ref, ref ushort uint16Ref, ref uint[] vectorUInt32Ref, ref Matrix4x4 plgMatrix4x4Ref, ref float floatRef, ref Vector4 plgVector4Ref, ref string plgStringRef, ref ulong[] vectorUInt64Ref, ref long int64Ref, ref Bool8 boolRef, ref Vector3 plgVector3Ref, ref float[] vectorFloatRef);
	public delegate string[] Func29(ref Vector4 plgVector4Ref, ref int int32Ref, ref sbyte[] vectorInt8Ref, ref double doubleRef, ref Bool8 boolRef, ref sbyte int8Ref, ref ushort[] vectorUInt16Ref, ref float floatRef, ref string plgStringRef, ref Matrix4x4 plgMatrix4x4Ref, ref ulong uint64Ref, ref Vector3 plgVector3Ref, ref long[] vectorInt64Ref);
	public delegate int Func30(ref nint ptr64Ref, ref Vector4 plgVector4Ref, ref long int64Ref, ref uint[] vectorUInt32Ref, ref Bool8 boolRef, ref string plgStringRef, ref Vector3 plgVector3Ref, ref byte[] vectorUInt8Ref, ref float floatRef, ref Vector2 plgVector2Ref, ref Matrix4x4 plgMatrix4x4Ref, ref sbyte int8Ref, ref float[] vectorFloatRef, ref double doubleRef);
	public delegate Vector3 Func31(ref Char8 charRef, ref uint uint32Ref, ref ulong[] vectorUInt64Ref, ref Vector4 plgVector4Ref, ref string plgStringRef, ref Bool8 boolRef, ref long int64Ref, ref Vector2 vec2Ref, ref sbyte int8Ref, ref ushort uint16Ref, ref short[] vectorInt16Ref, ref Matrix4x4 mat4x4Ref, ref Vector3 vec3Ref, ref float floatRef, ref double[] vectorDoubleRef);
	public delegate double Func32(ref int p1, ref ushort p2, ref sbyte[] p3, ref Vector4 p4, ref nint p5, ref uint[] p6, ref Matrix4x4 p7, ref ulong p8, ref string p9, ref long p10, ref Vector2 p11, ref sbyte[] p12, ref Bool8 p13, ref Vector3 p14, ref byte p15, ref Char16[] p16);
	public delegate void Func33(ref object? variant);
	public delegate Example[] FuncEnum(Example p1, ref Example[] p2);



	internal static unsafe class cross_call_master {

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="returnString">No description available.</param>

		internal static delegate*<string, void> ReverseReturn = &___ReverseReturn;
		internal static delegate* unmanaged[Cdecl]<String192*, void> __ReverseReturn;
		private static void ___ReverseReturn(string returnString)
		{
			var __returnString = NativeMethods.ConstructString(returnString);

			try {
				__ReverseReturn(&__returnString);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__returnString);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>

		internal static delegate*<void> NoParamReturnVoidCallback = &___NoParamReturnVoidCallback;
		internal static delegate* unmanaged[Cdecl]<void> __NoParamReturnVoidCallback;
		private static void ___NoParamReturnVoidCallback()
		{
			__NoParamReturnVoidCallback();
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Bool8> NoParamReturnBoolCallback = &___NoParamReturnBoolCallback;
		internal static delegate* unmanaged[Cdecl]<Bool8> __NoParamReturnBoolCallback;
		private static Bool8 ___NoParamReturnBoolCallback()
		{
			Bool8 __retVal = __NoParamReturnBoolCallback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Char8> NoParamReturnChar8Callback = &___NoParamReturnChar8Callback;
		internal static delegate* unmanaged[Cdecl]<Char8> __NoParamReturnChar8Callback;
		private static Char8 ___NoParamReturnChar8Callback()
		{
			Char8 __retVal = __NoParamReturnChar8Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Char16> NoParamReturnChar16Callback = &___NoParamReturnChar16Callback;
		internal static delegate* unmanaged[Cdecl]<Char16> __NoParamReturnChar16Callback;
		private static Char16 ___NoParamReturnChar16Callback()
		{
			Char16 __retVal = __NoParamReturnChar16Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<sbyte> NoParamReturnInt8Callback = &___NoParamReturnInt8Callback;
		internal static delegate* unmanaged[Cdecl]<sbyte> __NoParamReturnInt8Callback;
		private static sbyte ___NoParamReturnInt8Callback()
		{
			sbyte __retVal = __NoParamReturnInt8Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<short> NoParamReturnInt16Callback = &___NoParamReturnInt16Callback;
		internal static delegate* unmanaged[Cdecl]<short> __NoParamReturnInt16Callback;
		private static short ___NoParamReturnInt16Callback()
		{
			short __retVal = __NoParamReturnInt16Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<int> NoParamReturnInt32Callback = &___NoParamReturnInt32Callback;
		internal static delegate* unmanaged[Cdecl]<int> __NoParamReturnInt32Callback;
		private static int ___NoParamReturnInt32Callback()
		{
			int __retVal = __NoParamReturnInt32Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<long> NoParamReturnInt64Callback = &___NoParamReturnInt64Callback;
		internal static delegate* unmanaged[Cdecl]<long> __NoParamReturnInt64Callback;
		private static long ___NoParamReturnInt64Callback()
		{
			long __retVal = __NoParamReturnInt64Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<byte> NoParamReturnUInt8Callback = &___NoParamReturnUInt8Callback;
		internal static delegate* unmanaged[Cdecl]<byte> __NoParamReturnUInt8Callback;
		private static byte ___NoParamReturnUInt8Callback()
		{
			byte __retVal = __NoParamReturnUInt8Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<ushort> NoParamReturnUInt16Callback = &___NoParamReturnUInt16Callback;
		internal static delegate* unmanaged[Cdecl]<ushort> __NoParamReturnUInt16Callback;
		private static ushort ___NoParamReturnUInt16Callback()
		{
			ushort __retVal = __NoParamReturnUInt16Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<uint> NoParamReturnUInt32Callback = &___NoParamReturnUInt32Callback;
		internal static delegate* unmanaged[Cdecl]<uint> __NoParamReturnUInt32Callback;
		private static uint ___NoParamReturnUInt32Callback()
		{
			uint __retVal = __NoParamReturnUInt32Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<ulong> NoParamReturnUInt64Callback = &___NoParamReturnUInt64Callback;
		internal static delegate* unmanaged[Cdecl]<ulong> __NoParamReturnUInt64Callback;
		private static ulong ___NoParamReturnUInt64Callback()
		{
			ulong __retVal = __NoParamReturnUInt64Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<nint> NoParamReturnPointerCallback = &___NoParamReturnPointerCallback;
		internal static delegate* unmanaged[Cdecl]<nint> __NoParamReturnPointerCallback;
		private static nint ___NoParamReturnPointerCallback()
		{
			nint __retVal = __NoParamReturnPointerCallback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<float> NoParamReturnFloatCallback = &___NoParamReturnFloatCallback;
		internal static delegate* unmanaged[Cdecl]<float> __NoParamReturnFloatCallback;
		private static float ___NoParamReturnFloatCallback()
		{
			float __retVal = __NoParamReturnFloatCallback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<double> NoParamReturnDoubleCallback = &___NoParamReturnDoubleCallback;
		internal static delegate* unmanaged[Cdecl]<double> __NoParamReturnDoubleCallback;
		private static double ___NoParamReturnDoubleCallback()
		{
			double __retVal = __NoParamReturnDoubleCallback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<NoParamReturnFunctionCallbackFunc> NoParamReturnFunctionCallback = &___NoParamReturnFunctionCallback;
		internal static delegate* unmanaged[Cdecl]<nint> __NoParamReturnFunctionCallback;
		private static NoParamReturnFunctionCallbackFunc ___NoParamReturnFunctionCallback()
		{
			NoParamReturnFunctionCallbackFunc __retVal = __NoParamReturnFunctionCallback();
			return Marshal.GetDelegateForFunctionPointer<NoParamReturnFunctionCallbackFunc>(__retVal);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<string> NoParamReturnStringCallback = &___NoParamReturnStringCallback;
		internal static delegate* unmanaged[Cdecl]<String192> __NoParamReturnStringCallback;
		private static string ___NoParamReturnStringCallback()
		{
			string __retVal;
			String192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnStringCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<object?> NoParamReturnAnyCallback = &___NoParamReturnAnyCallback;
		internal static delegate* unmanaged[Cdecl]<Variant256> __NoParamReturnAnyCallback;
		private static object? ___NoParamReturnAnyCallback()
		{
			object? __retVal;
			Variant256 __retVal_native;

			try {
				__retVal_native = __NoParamReturnAnyCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetVariantData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVariant(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Bool8[]> NoParamReturnArrayBoolCallback = &___NoParamReturnArrayBoolCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayBoolCallback;
		private static Bool8[] ___NoParamReturnArrayBoolCallback()
		{
			Bool8[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayBoolCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Bool8[NativeMethods.GetVectorSizeBool(&__retVal_native)];
				NativeMethods.GetVectorDataBool(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorBool(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Char8[]> NoParamReturnArrayChar8Callback = &___NoParamReturnArrayChar8Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayChar8Callback;
		private static Char8[] ___NoParamReturnArrayChar8Callback()
		{
			Char8[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayChar8Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Char8[NativeMethods.GetVectorSizeChar8(&__retVal_native)];
				NativeMethods.GetVectorDataChar8(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorChar8(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Char16[]> NoParamReturnArrayChar16Callback = &___NoParamReturnArrayChar16Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayChar16Callback;
		private static Char16[] ___NoParamReturnArrayChar16Callback()
		{
			Char16[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayChar16Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Char16[NativeMethods.GetVectorSizeChar16(&__retVal_native)];
				NativeMethods.GetVectorDataChar16(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorChar16(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<sbyte[]> NoParamReturnArrayInt8Callback = &___NoParamReturnArrayInt8Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayInt8Callback;
		private static sbyte[] ___NoParamReturnArrayInt8Callback()
		{
			sbyte[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayInt8Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new sbyte[NativeMethods.GetVectorSizeInt8(&__retVal_native)];
				NativeMethods.GetVectorDataInt8(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt8(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<short[]> NoParamReturnArrayInt16Callback = &___NoParamReturnArrayInt16Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayInt16Callback;
		private static short[] ___NoParamReturnArrayInt16Callback()
		{
			short[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayInt16Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new short[NativeMethods.GetVectorSizeInt16(&__retVal_native)];
				NativeMethods.GetVectorDataInt16(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt16(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<int[]> NoParamReturnArrayInt32Callback = &___NoParamReturnArrayInt32Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayInt32Callback;
		private static int[] ___NoParamReturnArrayInt32Callback()
		{
			int[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayInt32Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new int[NativeMethods.GetVectorSizeInt32(&__retVal_native)];
				NativeMethods.GetVectorDataInt32(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt32(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<long[]> NoParamReturnArrayInt64Callback = &___NoParamReturnArrayInt64Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayInt64Callback;
		private static long[] ___NoParamReturnArrayInt64Callback()
		{
			long[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayInt64Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new long[NativeMethods.GetVectorSizeInt64(&__retVal_native)];
				NativeMethods.GetVectorDataInt64(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<byte[]> NoParamReturnArrayUInt8Callback = &___NoParamReturnArrayUInt8Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayUInt8Callback;
		private static byte[] ___NoParamReturnArrayUInt8Callback()
		{
			byte[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayUInt8Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new byte[NativeMethods.GetVectorSizeUInt8(&__retVal_native)];
				NativeMethods.GetVectorDataUInt8(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt8(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<ushort[]> NoParamReturnArrayUInt16Callback = &___NoParamReturnArrayUInt16Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayUInt16Callback;
		private static ushort[] ___NoParamReturnArrayUInt16Callback()
		{
			ushort[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayUInt16Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new ushort[NativeMethods.GetVectorSizeUInt16(&__retVal_native)];
				NativeMethods.GetVectorDataUInt16(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt16(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<uint[]> NoParamReturnArrayUInt32Callback = &___NoParamReturnArrayUInt32Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayUInt32Callback;
		private static uint[] ___NoParamReturnArrayUInt32Callback()
		{
			uint[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayUInt32Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new uint[NativeMethods.GetVectorSizeUInt32(&__retVal_native)];
				NativeMethods.GetVectorDataUInt32(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt32(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<ulong[]> NoParamReturnArrayUInt64Callback = &___NoParamReturnArrayUInt64Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayUInt64Callback;
		private static ulong[] ___NoParamReturnArrayUInt64Callback()
		{
			ulong[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayUInt64Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new ulong[NativeMethods.GetVectorSizeUInt64(&__retVal_native)];
				NativeMethods.GetVectorDataUInt64(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt64(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<nint[]> NoParamReturnArrayPointerCallback = &___NoParamReturnArrayPointerCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayPointerCallback;
		private static nint[] ___NoParamReturnArrayPointerCallback()
		{
			nint[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayPointerCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new nint[NativeMethods.GetVectorSizeIntPtr(&__retVal_native)];
				NativeMethods.GetVectorDataIntPtr(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorIntPtr(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<float[]> NoParamReturnArrayFloatCallback = &___NoParamReturnArrayFloatCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayFloatCallback;
		private static float[] ___NoParamReturnArrayFloatCallback()
		{
			float[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayFloatCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new float[NativeMethods.GetVectorSizeFloat(&__retVal_native)];
				NativeMethods.GetVectorDataFloat(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorFloat(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<double[]> NoParamReturnArrayDoubleCallback = &___NoParamReturnArrayDoubleCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayDoubleCallback;
		private static double[] ___NoParamReturnArrayDoubleCallback()
		{
			double[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayDoubleCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new double[NativeMethods.GetVectorSizeDouble(&__retVal_native)];
				NativeMethods.GetVectorDataDouble(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorDouble(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<string[]> NoParamReturnArrayStringCallback = &___NoParamReturnArrayStringCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayStringCallback;
		private static string[] ___NoParamReturnArrayStringCallback()
		{
			string[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayStringCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new string[NativeMethods.GetVectorSizeString(&__retVal_native)];
				NativeMethods.GetVectorDataString(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<object?[]> NoParamReturnArrayAnyCallback = &___NoParamReturnArrayAnyCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayAnyCallback;
		private static object?[] ___NoParamReturnArrayAnyCallback()
		{
			object?[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayAnyCallback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new object?[NativeMethods.GetVectorSizeVariant(&__retVal_native)];
				NativeMethods.GetVectorDataVariant(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVariant(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Vector2[]> NoParamReturnArrayVector2Callback = &___NoParamReturnArrayVector2Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayVector2Callback;
		private static Vector2[] ___NoParamReturnArrayVector2Callback()
		{
			Vector2[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayVector2Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Vector2[NativeMethods.GetVectorSizeVector2(&__retVal_native)];
				NativeMethods.GetVectorDataVector2(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVector2(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Vector3[]> NoParamReturnArrayVector3Callback = &___NoParamReturnArrayVector3Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayVector3Callback;
		private static Vector3[] ___NoParamReturnArrayVector3Callback()
		{
			Vector3[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayVector3Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Vector3[NativeMethods.GetVectorSizeVector3(&__retVal_native)];
				NativeMethods.GetVectorDataVector3(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVector3(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Vector4[]> NoParamReturnArrayVector4Callback = &___NoParamReturnArrayVector4Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayVector4Callback;
		private static Vector4[] ___NoParamReturnArrayVector4Callback()
		{
			Vector4[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayVector4Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Vector4[NativeMethods.GetVectorSizeVector4(&__retVal_native)];
				NativeMethods.GetVectorDataVector4(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVector4(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Matrix4x4[]> NoParamReturnArrayMatrix4x4Callback = &___NoParamReturnArrayMatrix4x4Callback;
		internal static delegate* unmanaged[Cdecl]<Vector192> __NoParamReturnArrayMatrix4x4Callback;
		private static Matrix4x4[] ___NoParamReturnArrayMatrix4x4Callback()
		{
			Matrix4x4[] __retVal;
			Vector192 __retVal_native;

			try {
				__retVal_native = __NoParamReturnArrayMatrix4x4Callback();
				// Unmarshal - Convert native data to managed data.
				__retVal = new Matrix4x4[NativeMethods.GetVectorSizeMatrix4x4(&__retVal_native)];
				NativeMethods.GetVectorDataMatrix4x4(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorMatrix4x4(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Vector2> NoParamReturnVector2Callback = &___NoParamReturnVector2Callback;
		internal static delegate* unmanaged[Cdecl]<Vector2> __NoParamReturnVector2Callback;
		private static Vector2 ___NoParamReturnVector2Callback()
		{
			Vector2 __retVal = __NoParamReturnVector2Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Vector3> NoParamReturnVector3Callback = &___NoParamReturnVector3Callback;
		internal static delegate* unmanaged[Cdecl]<Vector3> __NoParamReturnVector3Callback;
		private static Vector3 ___NoParamReturnVector3Callback()
		{
			Vector3 __retVal = __NoParamReturnVector3Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Vector4> NoParamReturnVector4Callback = &___NoParamReturnVector4Callback;
		internal static delegate* unmanaged[Cdecl]<Vector4> __NoParamReturnVector4Callback;
		private static Vector4 ___NoParamReturnVector4Callback()
		{
			Vector4 __retVal = __NoParamReturnVector4Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <returns>No description available.</returns>

		internal static delegate*<Matrix4x4> NoParamReturnMatrix4x4Callback = &___NoParamReturnMatrix4x4Callback;
		internal static delegate* unmanaged[Cdecl]<Matrix4x4> __NoParamReturnMatrix4x4Callback;
		private static Matrix4x4 ___NoParamReturnMatrix4x4Callback()
		{
			Matrix4x4 __retVal = __NoParamReturnMatrix4x4Callback();
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>

		internal static delegate*<int, void> Param1Callback = &___Param1Callback;
		internal static delegate* unmanaged[Cdecl]<int, void> __Param1Callback;
		private static void ___Param1Callback(int a)
		{
			__Param1Callback(a);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>

		internal static delegate*<int, float, void> Param2Callback = &___Param2Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, void> __Param2Callback;
		private static void ___Param2Callback(int a, float b)
		{
			__Param2Callback(a, b);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>

		internal static delegate*<int, float, double, void> Param3Callback = &___Param3Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, void> __Param3Callback;
		private static void ___Param3Callback(int a, float b, double c)
		{
			__Param3Callback(a, b, c);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>

		internal static delegate*<int, float, double, Vector4, void> Param4Callback = &___Param4Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, void> __Param4Callback;
		private static void ___Param4Callback(int a, float b, double c, Vector4 d)
		{
			__Param4Callback(a, b, c, &d);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>

		internal static delegate*<int, float, double, Vector4, long[], void> Param5Callback = &___Param5Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, Vector192*, void> __Param5Callback;
		private static void ___Param5Callback(int a, float b, double c, Vector4 d, long[] e)
		{
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);

			try {
				__Param5Callback(a, b, c, &d, &__e);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>

		internal static delegate*<int, float, double, Vector4, long[], Char8, void> Param6Callback = &___Param6Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, Vector192*, Char8, void> __Param6Callback;
		private static void ___Param6Callback(int a, float b, double c, Vector4 d, long[] e, Char8 f)
		{
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);

			try {
				__Param6Callback(a, b, c, &d, &__e, f);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>

		internal static delegate*<int, float, double, Vector4, long[], Char8, string, void> Param7Callback = &___Param7Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, Vector192*, Char8, String192*, void> __Param7Callback;
		private static void ___Param7Callback(int a, float b, double c, Vector4 d, long[] e, Char8 f, string g)
		{
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			var __g = NativeMethods.ConstructString(g);

			try {
				__Param7Callback(a, b, c, &d, &__e, f, &__g);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>
		/// <param name="h">No description available.</param>

		internal static delegate*<int, float, double, Vector4, long[], Char8, string, Char16, void> Param8Callback = &___Param8Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, Vector192*, Char8, String192*, Char16, void> __Param8Callback;
		private static void ___Param8Callback(int a, float b, double c, Vector4 d, long[] e, Char8 f, string g, Char16 h)
		{
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			var __g = NativeMethods.ConstructString(g);

			try {
				__Param8Callback(a, b, c, &d, &__e, f, &__g, h);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>
		/// <param name="h">No description available.</param>
		/// <param name="k">No description available.</param>

		internal static delegate*<int, float, double, Vector4, long[], Char8, string, Char16, short, void> Param9Callback = &___Param9Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, Vector192*, Char8, String192*, Char16, short, void> __Param9Callback;
		private static void ___Param9Callback(int a, float b, double c, Vector4 d, long[] e, Char8 f, string g, Char16 h, short k)
		{
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			var __g = NativeMethods.ConstructString(g);

			try {
				__Param9Callback(a, b, c, &d, &__e, f, &__g, h, k);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>
		/// <param name="h">No description available.</param>
		/// <param name="k">No description available.</param>
		/// <param name="l">No description available.</param>

		internal static delegate*<int, float, double, Vector4, long[], Char8, string, Char16, short, nint, void> Param10Callback = &___Param10Callback;
		internal static delegate* unmanaged[Cdecl]<int, float, double, Vector4*, Vector192*, Char8, String192*, Char16, short, nint, void> __Param10Callback;
		private static void ___Param10Callback(int a, float b, double c, Vector4 d, long[] e, Char8 f, string g, Char16 h, short k, nint l)
		{
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			var __g = NativeMethods.ConstructString(g);

			try {
				__Param10Callback(a, b, c, &d, &__e, f, &__g, h, k, l);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>

		internal static delegate*<ref int, void> ParamRef1Callback = &___ParamRef1Callback;
		internal static delegate* unmanaged[Cdecl]<int*, void> __ParamRef1Callback;
		private static void ___ParamRef1Callback(ref int a)
		{
			fixed(int* __a = &a) {

			__ParamRef1Callback(__a);

			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>

		internal static delegate*<ref int, ref float, void> ParamRef2Callback = &___ParamRef2Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, void> __ParamRef2Callback;
		private static void ___ParamRef2Callback(ref int a, ref float b)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {

			__ParamRef2Callback(__a, __b);

			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, void> ParamRef3Callback = &___ParamRef3Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, void> __ParamRef3Callback;
		private static void ___ParamRef3Callback(ref int a, ref float b, ref double c)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {

			__ParamRef3Callback(__a, __b, __c);

			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, void> ParamRef4Callback = &___ParamRef4Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, void> __ParamRef4Callback;
		private static void ___ParamRef4Callback(ref int a, ref float b, ref double c, ref Vector4 d)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {

			__ParamRef4Callback(__a, __b, __c, __d);

			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, ref long[], void> ParamRef5Callback = &___ParamRef5Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, Vector192*, void> __ParamRef5Callback;
		private static void ___ParamRef5Callback(ref int a, ref float b, ref double c, ref Vector4 d, ref long[] e)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);

			try {
				__ParamRef5Callback(__a, __b, __c, __d, &__e);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref e, NativeMethods.GetVectorSizeInt64(&__e));
				NativeMethods.GetVectorDataInt64(&__e, e);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
			}

			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, ref long[], ref Char8, void> ParamRef6Callback = &___ParamRef6Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, Vector192*, Char8*, void> __ParamRef6Callback;
		private static void ___ParamRef6Callback(ref int a, ref float b, ref double c, ref Vector4 d, ref long[] e, ref Char8 f)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			fixed(Char8* __f = &f) {

			try {
				__ParamRef6Callback(__a, __b, __c, __d, &__e, __f);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref e, NativeMethods.GetVectorSizeInt64(&__e));
				NativeMethods.GetVectorDataInt64(&__e, e);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
			}

			}
			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, ref long[], ref Char8, ref string, void> ParamRef7Callback = &___ParamRef7Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, Vector192*, Char8*, String192*, void> __ParamRef7Callback;
		private static void ___ParamRef7Callback(ref int a, ref float b, ref double c, ref Vector4 d, ref long[] e, ref Char8 f, ref string g)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			fixed(Char8* __f = &f) {
			var __g = NativeMethods.ConstructString(g);

			try {
				__ParamRef7Callback(__a, __b, __c, __d, &__e, __f, &__g);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref e, NativeMethods.GetVectorSizeInt64(&__e));
				NativeMethods.GetVectorDataInt64(&__e, e);
				g = NativeMethods.GetStringData(&__g);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}

			}
			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>
		/// <param name="h">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, ref long[], ref Char8, ref string, ref Char16, void> ParamRef8Callback = &___ParamRef8Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, Vector192*, Char8*, String192*, Char16*, void> __ParamRef8Callback;
		private static void ___ParamRef8Callback(ref int a, ref float b, ref double c, ref Vector4 d, ref long[] e, ref Char8 f, ref string g, ref Char16 h)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			fixed(Char8* __f = &f) {
			var __g = NativeMethods.ConstructString(g);
			fixed(Char16* __h = &h) {

			try {
				__ParamRef8Callback(__a, __b, __c, __d, &__e, __f, &__g, __h);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref e, NativeMethods.GetVectorSizeInt64(&__e));
				NativeMethods.GetVectorDataInt64(&__e, e);
				g = NativeMethods.GetStringData(&__g);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}

			}
			}
			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>
		/// <param name="h">No description available.</param>
		/// <param name="k">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, ref long[], ref Char8, ref string, ref Char16, ref short, void> ParamRef9Callback = &___ParamRef9Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, Vector192*, Char8*, String192*, Char16*, short*, void> __ParamRef9Callback;
		private static void ___ParamRef9Callback(ref int a, ref float b, ref double c, ref Vector4 d, ref long[] e, ref Char8 f, ref string g, ref Char16 h, ref short k)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			fixed(Char8* __f = &f) {
			var __g = NativeMethods.ConstructString(g);
			fixed(Char16* __h = &h) {
			fixed(short* __k = &k) {

			try {
				__ParamRef9Callback(__a, __b, __c, __d, &__e, __f, &__g, __h, __k);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref e, NativeMethods.GetVectorSizeInt64(&__e));
				NativeMethods.GetVectorDataInt64(&__e, e);
				g = NativeMethods.GetStringData(&__g);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}

			}
			}
			}
			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="a">No description available.</param>
		/// <param name="b">No description available.</param>
		/// <param name="c">No description available.</param>
		/// <param name="d">No description available.</param>
		/// <param name="e">No description available.</param>
		/// <param name="f">No description available.</param>
		/// <param name="g">No description available.</param>
		/// <param name="h">No description available.</param>
		/// <param name="k">No description available.</param>
		/// <param name="l">No description available.</param>

		internal static delegate*<ref int, ref float, ref double, ref Vector4, ref long[], ref Char8, ref string, ref Char16, ref short, ref nint, void> ParamRef10Callback = &___ParamRef10Callback;
		internal static delegate* unmanaged[Cdecl]<int*, float*, double*, Vector4*, Vector192*, Char8*, String192*, Char16*, short*, nint*, void> __ParamRef10Callback;
		private static void ___ParamRef10Callback(ref int a, ref float b, ref double c, ref Vector4 d, ref long[] e, ref Char8 f, ref string g, ref Char16 h, ref short k, ref nint l)
		{
			fixed(int* __a = &a) {
			fixed(float* __b = &b) {
			fixed(double* __c = &c) {
			fixed(Vector4* __d = &d) {
			var __e = NativeMethods.ConstructVectorInt64(e, e.Length);
			fixed(Char8* __f = &f) {
			var __g = NativeMethods.ConstructString(g);
			fixed(Char16* __h = &h) {
			fixed(short* __k = &k) {
			fixed(nint* __l = &l) {

			try {
				__ParamRef10Callback(__a, __b, __c, __d, &__e, __f, &__g, __h, __k, __l);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref e, NativeMethods.GetVectorSizeInt64(&__e));
				NativeMethods.GetVectorDataInt64(&__e, e);
				g = NativeMethods.GetStringData(&__g);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__e);
				NativeMethods.DestroyString(&__g);
			}

			}
			}
			}
			}
			}
			}
			}
			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="p1">No description available.</param>
		/// <param name="p2">No description available.</param>
		/// <param name="p3">No description available.</param>
		/// <param name="p4">No description available.</param>
		/// <param name="p5">No description available.</param>
		/// <param name="p6">No description available.</param>
		/// <param name="p7">No description available.</param>
		/// <param name="p8">No description available.</param>
		/// <param name="p9">No description available.</param>
		/// <param name="p10">No description available.</param>
		/// <param name="p11">No description available.</param>
		/// <param name="p12">No description available.</param>
		/// <param name="p13">No description available.</param>
		/// <param name="p14">No description available.</param>
		/// <param name="p15">No description available.</param>

		internal static delegate*<ref Bool8[], ref Char8[], ref Char16[], ref sbyte[], ref short[], ref int[], ref long[], ref byte[], ref ushort[], ref uint[], ref ulong[], ref nint[], ref float[], ref double[], ref string[], void> ParamRefVectorsCallback = &___ParamRefVectorsCallback;
		internal static delegate* unmanaged[Cdecl]<Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, Vector192*, void> __ParamRefVectorsCallback;
		private static void ___ParamRefVectorsCallback(ref Bool8[] p1, ref Char8[] p2, ref Char16[] p3, ref sbyte[] p4, ref short[] p5, ref int[] p6, ref long[] p7, ref byte[] p8, ref ushort[] p9, ref uint[] p10, ref ulong[] p11, ref nint[] p12, ref float[] p13, ref double[] p14, ref string[] p15)
		{
			var __p1 = NativeMethods.ConstructVectorBool(p1, p1.Length);
			var __p2 = NativeMethods.ConstructVectorChar8(p2, p2.Length);
			var __p3 = NativeMethods.ConstructVectorChar16(p3, p3.Length);
			var __p4 = NativeMethods.ConstructVectorInt8(p4, p4.Length);
			var __p5 = NativeMethods.ConstructVectorInt16(p5, p5.Length);
			var __p6 = NativeMethods.ConstructVectorInt32(p6, p6.Length);
			var __p7 = NativeMethods.ConstructVectorInt64(p7, p7.Length);
			var __p8 = NativeMethods.ConstructVectorUInt8(p8, p8.Length);
			var __p9 = NativeMethods.ConstructVectorUInt16(p9, p9.Length);
			var __p10 = NativeMethods.ConstructVectorUInt32(p10, p10.Length);
			var __p11 = NativeMethods.ConstructVectorUInt64(p11, p11.Length);
			var __p12 = NativeMethods.ConstructVectorIntPtr(p12, p12.Length);
			var __p13 = NativeMethods.ConstructVectorFloat(p13, p13.Length);
			var __p14 = NativeMethods.ConstructVectorDouble(p14, p14.Length);
			var __p15 = NativeMethods.ConstructVectorString(p15, p15.Length);

			try {
				__ParamRefVectorsCallback(&__p1, &__p2, &__p3, &__p4, &__p5, &__p6, &__p7, &__p8, &__p9, &__p10, &__p11, &__p12, &__p13, &__p14, &__p15);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref p1, NativeMethods.GetVectorSizeBool(&__p1));
				NativeMethods.GetVectorDataBool(&__p1, p1);
				Array.Resize(ref p2, NativeMethods.GetVectorSizeChar8(&__p2));
				NativeMethods.GetVectorDataChar8(&__p2, p2);
				Array.Resize(ref p3, NativeMethods.GetVectorSizeChar16(&__p3));
				NativeMethods.GetVectorDataChar16(&__p3, p3);
				Array.Resize(ref p4, NativeMethods.GetVectorSizeInt8(&__p4));
				NativeMethods.GetVectorDataInt8(&__p4, p4);
				Array.Resize(ref p5, NativeMethods.GetVectorSizeInt16(&__p5));
				NativeMethods.GetVectorDataInt16(&__p5, p5);
				Array.Resize(ref p6, NativeMethods.GetVectorSizeInt32(&__p6));
				NativeMethods.GetVectorDataInt32(&__p6, p6);
				Array.Resize(ref p7, NativeMethods.GetVectorSizeInt64(&__p7));
				NativeMethods.GetVectorDataInt64(&__p7, p7);
				Array.Resize(ref p8, NativeMethods.GetVectorSizeUInt8(&__p8));
				NativeMethods.GetVectorDataUInt8(&__p8, p8);
				Array.Resize(ref p9, NativeMethods.GetVectorSizeUInt16(&__p9));
				NativeMethods.GetVectorDataUInt16(&__p9, p9);
				Array.Resize(ref p10, NativeMethods.GetVectorSizeUInt32(&__p10));
				NativeMethods.GetVectorDataUInt32(&__p10, p10);
				Array.Resize(ref p11, NativeMethods.GetVectorSizeUInt64(&__p11));
				NativeMethods.GetVectorDataUInt64(&__p11, p11);
				Array.Resize(ref p12, NativeMethods.GetVectorSizeIntPtr(&__p12));
				NativeMethods.GetVectorDataIntPtr(&__p12, p12);
				Array.Resize(ref p13, NativeMethods.GetVectorSizeFloat(&__p13));
				NativeMethods.GetVectorDataFloat(&__p13, p13);
				Array.Resize(ref p14, NativeMethods.GetVectorSizeDouble(&__p14));
				NativeMethods.GetVectorDataDouble(&__p14, p14);
				Array.Resize(ref p15, NativeMethods.GetVectorSizeString(&__p15));
				NativeMethods.GetVectorDataString(&__p15, p15);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorBool(&__p1);
				NativeMethods.DestroyVectorChar8(&__p2);
				NativeMethods.DestroyVectorChar16(&__p3);
				NativeMethods.DestroyVectorInt8(&__p4);
				NativeMethods.DestroyVectorInt16(&__p5);
				NativeMethods.DestroyVectorInt32(&__p6);
				NativeMethods.DestroyVectorInt64(&__p7);
				NativeMethods.DestroyVectorUInt8(&__p8);
				NativeMethods.DestroyVectorUInt16(&__p9);
				NativeMethods.DestroyVectorUInt32(&__p10);
				NativeMethods.DestroyVectorUInt64(&__p11);
				NativeMethods.DestroyVectorIntPtr(&__p12);
				NativeMethods.DestroyVectorFloat(&__p13);
				NativeMethods.DestroyVectorDouble(&__p14);
				NativeMethods.DestroyVectorString(&__p15);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="p1">No description available.</param>
		/// <param name="p2">No description available.</param>
		/// <param name="p3">No description available.</param>
		/// <param name="p4">No description available.</param>
		/// <param name="p5">No description available.</param>
		/// <param name="p6">No description available.</param>
		/// <param name="p7">No description available.</param>
		/// <param name="p8">No description available.</param>
		/// <param name="p9">No description available.</param>
		/// <param name="p10">No description available.</param>
		/// <param name="p11">No description available.</param>
		/// <param name="p12">No description available.</param>
		/// <param name="p13">No description available.</param>
		/// <param name="p14">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Bool8, Char8, Char16, sbyte, short, int, long, byte, ushort, uint, ulong, nint, float, double, long> ParamAllPrimitivesCallback = &___ParamAllPrimitivesCallback;
		internal static delegate* unmanaged[Cdecl]<Bool8, Char8, Char16, sbyte, short, int, long, byte, ushort, uint, ulong, nint, float, double, long> __ParamAllPrimitivesCallback;
		private static long ___ParamAllPrimitivesCallback(Bool8 p1, Char8 p2, Char16 p3, sbyte p4, short p5, int p6, long p7, byte p8, ushort p9, uint p10, ulong p11, nint p12, float p13, double p14)
		{
			long __retVal = __ParamAllPrimitivesCallback(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="p1">No description available.</param>
		/// <param name="p2">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Example, Example[], int> ParamEnumCallback = &___ParamEnumCallback;
		internal static delegate* unmanaged[Cdecl]<Example, Vector192*, int> __ParamEnumCallback;
		private static int ___ParamEnumCallback(Example p1, Example[] p2)
		{
			int __retVal;
			var __p2 = NativeMethodsT.ConstructVectorInt32(p2, p2.Length);

			try {
				__retVal = __ParamEnumCallback(p1, &__p2);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt32(&__p2);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="p1">No description available.</param>
		/// <param name="p2">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<ref Example, ref Example[], int> ParamEnumRefCallback = &___ParamEnumRefCallback;
		internal static delegate* unmanaged[Cdecl]<Example*, Vector192*, int> __ParamEnumRefCallback;
		private static int ___ParamEnumRefCallback(ref Example p1, ref Example[] p2)
		{
			int __retVal;
			fixed(Example* __p1 = &p1) {
			var __p2 = NativeMethodsT.ConstructVectorInt32(p2, p2.Length);

			try {
				__retVal = __ParamEnumRefCallback(__p1, &__p2);
				// Unmarshal - Convert native data to managed data.
				Array.Resize(ref p2, NativeMethods.GetVectorSizeInt32(&__p2));
				NativeMethodsT.GetVectorDataInt32(&__p2, p2);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt32(&__p2);
			}
			return __retVal;

			}

		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="p1">No description available.</param>
		/// <param name="p2">No description available.</param>

		internal static delegate*<object?, object?[], void> ParamVariantCallback = &___ParamVariantCallback;
		internal static delegate* unmanaged[Cdecl]<Variant256*, Vector192*, void> __ParamVariantCallback;
		private static void ___ParamVariantCallback(object? p1, object?[] p2)
		{
			var __p1 = NativeMethods.ConstructVariant(p1);
			var __p2 = NativeMethods.ConstructVectorVariant(p2, p2.Length);

			try {
				__ParamVariantCallback(&__p1, &__p2);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVariant(&__p1);
				NativeMethods.DestroyVectorVariant(&__p2);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="p1">No description available.</param>
		/// <param name="p2">No description available.</param>

		internal static delegate*<ref object?, ref object?[], void> ParamVariantRefCallback = &___ParamVariantRefCallback;
		internal static delegate* unmanaged[Cdecl]<Variant256*, Vector192*, void> __ParamVariantRefCallback;
		private static void ___ParamVariantRefCallback(ref object? p1, ref object?[] p2)
		{
			var __p1 = NativeMethods.ConstructVariant(p1);
			var __p2 = NativeMethods.ConstructVectorVariant(p2, p2.Length);

			try {
				__ParamVariantRefCallback(&__p1, &__p2);
				// Unmarshal - Convert native data to managed data.
				p1 = NativeMethods.GetVariantData(&__p1);
				Array.Resize(ref p2, NativeMethods.GetVectorSizeVariant(&__p2));
				NativeMethods.GetVectorDataVariant(&__p2, p2);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVariant(&__p1);
				NativeMethods.DestroyVectorVariant(&__p2);
			}
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>

		internal static delegate*<FuncVoid, void> CallFuncVoidCallback = &___CallFuncVoidCallback;
		internal static delegate* unmanaged[Cdecl]<nint, void> __CallFuncVoidCallback;
		private static void ___CallFuncVoidCallback(FuncVoid func)
		{
			__CallFuncVoidCallback(Marshal.GetFunctionPointerForDelegate(func));
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncBool, Bool8> CallFuncBoolCallback = &___CallFuncBoolCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Bool8> __CallFuncBoolCallback;
		private static Bool8 ___CallFuncBoolCallback(FuncBool func)
		{
			Bool8 __retVal = __CallFuncBoolCallback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncChar8, Char8> CallFuncChar8Callback = &___CallFuncChar8Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Char8> __CallFuncChar8Callback;
		private static Char8 ___CallFuncChar8Callback(FuncChar8 func)
		{
			Char8 __retVal = __CallFuncChar8Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncChar16, Char16> CallFuncChar16Callback = &___CallFuncChar16Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Char16> __CallFuncChar16Callback;
		private static Char16 ___CallFuncChar16Callback(FuncChar16 func)
		{
			Char16 __retVal = __CallFuncChar16Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt8, sbyte> CallFuncInt8Callback = &___CallFuncInt8Callback;
		internal static delegate* unmanaged[Cdecl]<nint, sbyte> __CallFuncInt8Callback;
		private static sbyte ___CallFuncInt8Callback(FuncInt8 func)
		{
			sbyte __retVal = __CallFuncInt8Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt16, short> CallFuncInt16Callback = &___CallFuncInt16Callback;
		internal static delegate* unmanaged[Cdecl]<nint, short> __CallFuncInt16Callback;
		private static short ___CallFuncInt16Callback(FuncInt16 func)
		{
			short __retVal = __CallFuncInt16Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt32, int> CallFuncInt32Callback = &___CallFuncInt32Callback;
		internal static delegate* unmanaged[Cdecl]<nint, int> __CallFuncInt32Callback;
		private static int ___CallFuncInt32Callback(FuncInt32 func)
		{
			int __retVal = __CallFuncInt32Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt64, long> CallFuncInt64Callback = &___CallFuncInt64Callback;
		internal static delegate* unmanaged[Cdecl]<nint, long> __CallFuncInt64Callback;
		private static long ___CallFuncInt64Callback(FuncInt64 func)
		{
			long __retVal = __CallFuncInt64Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt8, byte> CallFuncUInt8Callback = &___CallFuncUInt8Callback;
		internal static delegate* unmanaged[Cdecl]<nint, byte> __CallFuncUInt8Callback;
		private static byte ___CallFuncUInt8Callback(FuncUInt8 func)
		{
			byte __retVal = __CallFuncUInt8Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt16, ushort> CallFuncUInt16Callback = &___CallFuncUInt16Callback;
		internal static delegate* unmanaged[Cdecl]<nint, ushort> __CallFuncUInt16Callback;
		private static ushort ___CallFuncUInt16Callback(FuncUInt16 func)
		{
			ushort __retVal = __CallFuncUInt16Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt32, uint> CallFuncUInt32Callback = &___CallFuncUInt32Callback;
		internal static delegate* unmanaged[Cdecl]<nint, uint> __CallFuncUInt32Callback;
		private static uint ___CallFuncUInt32Callback(FuncUInt32 func)
		{
			uint __retVal = __CallFuncUInt32Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt64, ulong> CallFuncUInt64Callback = &___CallFuncUInt64Callback;
		internal static delegate* unmanaged[Cdecl]<nint, ulong> __CallFuncUInt64Callback;
		private static ulong ___CallFuncUInt64Callback(FuncUInt64 func)
		{
			ulong __retVal = __CallFuncUInt64Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncPtr, nint> CallFuncPtrCallback = &___CallFuncPtrCallback;
		internal static delegate* unmanaged[Cdecl]<nint, nint> __CallFuncPtrCallback;
		private static nint ___CallFuncPtrCallback(FuncPtr func)
		{
			nint __retVal = __CallFuncPtrCallback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncFloat, float> CallFuncFloatCallback = &___CallFuncFloatCallback;
		internal static delegate* unmanaged[Cdecl]<nint, float> __CallFuncFloatCallback;
		private static float ___CallFuncFloatCallback(FuncFloat func)
		{
			float __retVal = __CallFuncFloatCallback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncDouble, double> CallFuncDoubleCallback = &___CallFuncDoubleCallback;
		internal static delegate* unmanaged[Cdecl]<nint, double> __CallFuncDoubleCallback;
		private static double ___CallFuncDoubleCallback(FuncDouble func)
		{
			double __retVal = __CallFuncDoubleCallback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncString, string> CallFuncStringCallback = &___CallFuncStringCallback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFuncStringCallback;
		private static string ___CallFuncStringCallback(FuncString func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncStringCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncAny, object?> CallFuncAnyCallback = &___CallFuncAnyCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Variant256> __CallFuncAnyCallback;
		private static object? ___CallFuncAnyCallback(FuncAny func)
		{
			object? __retVal;
			Variant256 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncAnyCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetVariantData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVariant(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncFunction, nint> CallFuncFunctionCallback = &___CallFuncFunctionCallback;
		internal static delegate* unmanaged[Cdecl]<nint, nint> __CallFuncFunctionCallback;
		private static nint ___CallFuncFunctionCallback(FuncFunction func)
		{
			nint __retVal = __CallFuncFunctionCallback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncBoolVector, Bool8[]> CallFuncBoolVectorCallback = &___CallFuncBoolVectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncBoolVectorCallback;
		private static Bool8[] ___CallFuncBoolVectorCallback(FuncBoolVector func)
		{
			Bool8[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncBoolVectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Bool8[NativeMethods.GetVectorSizeBool(&__retVal_native)];
				NativeMethods.GetVectorDataBool(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorBool(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncChar8Vector, Char8[]> CallFuncChar8VectorCallback = &___CallFuncChar8VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncChar8VectorCallback;
		private static Char8[] ___CallFuncChar8VectorCallback(FuncChar8Vector func)
		{
			Char8[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncChar8VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Char8[NativeMethods.GetVectorSizeChar8(&__retVal_native)];
				NativeMethods.GetVectorDataChar8(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorChar8(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncChar16Vector, Char16[]> CallFuncChar16VectorCallback = &___CallFuncChar16VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncChar16VectorCallback;
		private static Char16[] ___CallFuncChar16VectorCallback(FuncChar16Vector func)
		{
			Char16[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncChar16VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Char16[NativeMethods.GetVectorSizeChar16(&__retVal_native)];
				NativeMethods.GetVectorDataChar16(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorChar16(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt8Vector, sbyte[]> CallFuncInt8VectorCallback = &___CallFuncInt8VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncInt8VectorCallback;
		private static sbyte[] ___CallFuncInt8VectorCallback(FuncInt8Vector func)
		{
			sbyte[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncInt8VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new sbyte[NativeMethods.GetVectorSizeInt8(&__retVal_native)];
				NativeMethods.GetVectorDataInt8(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt8(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt16Vector, short[]> CallFuncInt16VectorCallback = &___CallFuncInt16VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncInt16VectorCallback;
		private static short[] ___CallFuncInt16VectorCallback(FuncInt16Vector func)
		{
			short[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncInt16VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new short[NativeMethods.GetVectorSizeInt16(&__retVal_native)];
				NativeMethods.GetVectorDataInt16(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt16(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt32Vector, int[]> CallFuncInt32VectorCallback = &___CallFuncInt32VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncInt32VectorCallback;
		private static int[] ___CallFuncInt32VectorCallback(FuncInt32Vector func)
		{
			int[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncInt32VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new int[NativeMethods.GetVectorSizeInt32(&__retVal_native)];
				NativeMethods.GetVectorDataInt32(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt32(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncInt64Vector, long[]> CallFuncInt64VectorCallback = &___CallFuncInt64VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncInt64VectorCallback;
		private static long[] ___CallFuncInt64VectorCallback(FuncInt64Vector func)
		{
			long[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncInt64VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new long[NativeMethods.GetVectorSizeInt64(&__retVal_native)];
				NativeMethods.GetVectorDataInt64(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorInt64(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt8Vector, byte[]> CallFuncUInt8VectorCallback = &___CallFuncUInt8VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncUInt8VectorCallback;
		private static byte[] ___CallFuncUInt8VectorCallback(FuncUInt8Vector func)
		{
			byte[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncUInt8VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new byte[NativeMethods.GetVectorSizeUInt8(&__retVal_native)];
				NativeMethods.GetVectorDataUInt8(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt8(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt16Vector, ushort[]> CallFuncUInt16VectorCallback = &___CallFuncUInt16VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncUInt16VectorCallback;
		private static ushort[] ___CallFuncUInt16VectorCallback(FuncUInt16Vector func)
		{
			ushort[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncUInt16VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new ushort[NativeMethods.GetVectorSizeUInt16(&__retVal_native)];
				NativeMethods.GetVectorDataUInt16(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt16(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt32Vector, uint[]> CallFuncUInt32VectorCallback = &___CallFuncUInt32VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncUInt32VectorCallback;
		private static uint[] ___CallFuncUInt32VectorCallback(FuncUInt32Vector func)
		{
			uint[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncUInt32VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new uint[NativeMethods.GetVectorSizeUInt32(&__retVal_native)];
				NativeMethods.GetVectorDataUInt32(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt32(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncUInt64Vector, ulong[]> CallFuncUInt64VectorCallback = &___CallFuncUInt64VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncUInt64VectorCallback;
		private static ulong[] ___CallFuncUInt64VectorCallback(FuncUInt64Vector func)
		{
			ulong[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncUInt64VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new ulong[NativeMethods.GetVectorSizeUInt64(&__retVal_native)];
				NativeMethods.GetVectorDataUInt64(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt64(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncPtrVector, nint[]> CallFuncPtrVectorCallback = &___CallFuncPtrVectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncPtrVectorCallback;
		private static nint[] ___CallFuncPtrVectorCallback(FuncPtrVector func)
		{
			nint[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncPtrVectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new nint[NativeMethods.GetVectorSizeIntPtr(&__retVal_native)];
				NativeMethods.GetVectorDataIntPtr(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorIntPtr(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncFloatVector, float[]> CallFuncFloatVectorCallback = &___CallFuncFloatVectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncFloatVectorCallback;
		private static float[] ___CallFuncFloatVectorCallback(FuncFloatVector func)
		{
			float[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncFloatVectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new float[NativeMethods.GetVectorSizeFloat(&__retVal_native)];
				NativeMethods.GetVectorDataFloat(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorFloat(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncDoubleVector, double[]> CallFuncDoubleVectorCallback = &___CallFuncDoubleVectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncDoubleVectorCallback;
		private static double[] ___CallFuncDoubleVectorCallback(FuncDoubleVector func)
		{
			double[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncDoubleVectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new double[NativeMethods.GetVectorSizeDouble(&__retVal_native)];
				NativeMethods.GetVectorDataDouble(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorDouble(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncStringVector, string[]> CallFuncStringVectorCallback = &___CallFuncStringVectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncStringVectorCallback;
		private static string[] ___CallFuncStringVectorCallback(FuncStringVector func)
		{
			string[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncStringVectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new string[NativeMethods.GetVectorSizeString(&__retVal_native)];
				NativeMethods.GetVectorDataString(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncAnyVector, object?[]> CallFuncAnyVectorCallback = &___CallFuncAnyVectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncAnyVectorCallback;
		private static object?[] ___CallFuncAnyVectorCallback(FuncAnyVector func)
		{
			object?[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncAnyVectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new object?[NativeMethods.GetVectorSizeVariant(&__retVal_native)];
				NativeMethods.GetVectorDataVariant(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVariant(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncVec2Vector, Vector2[]> CallFuncVec2VectorCallback = &___CallFuncVec2VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncVec2VectorCallback;
		private static Vector2[] ___CallFuncVec2VectorCallback(FuncVec2Vector func)
		{
			Vector2[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncVec2VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Vector2[NativeMethods.GetVectorSizeVector2(&__retVal_native)];
				NativeMethods.GetVectorDataVector2(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVector2(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncVec3Vector, Vector3[]> CallFuncVec3VectorCallback = &___CallFuncVec3VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncVec3VectorCallback;
		private static Vector3[] ___CallFuncVec3VectorCallback(FuncVec3Vector func)
		{
			Vector3[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncVec3VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Vector3[NativeMethods.GetVectorSizeVector3(&__retVal_native)];
				NativeMethods.GetVectorDataVector3(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVector3(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncVec4Vector, Vector4[]> CallFuncVec4VectorCallback = &___CallFuncVec4VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncVec4VectorCallback;
		private static Vector4[] ___CallFuncVec4VectorCallback(FuncVec4Vector func)
		{
			Vector4[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncVec4VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Vector4[NativeMethods.GetVectorSizeVector4(&__retVal_native)];
				NativeMethods.GetVectorDataVector4(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorVector4(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncMat4x4Vector, Matrix4x4[]> CallFuncMat4x4VectorCallback = &___CallFuncMat4x4VectorCallback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFuncMat4x4VectorCallback;
		private static Matrix4x4[] ___CallFuncMat4x4VectorCallback(FuncMat4x4Vector func)
		{
			Matrix4x4[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncMat4x4VectorCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new Matrix4x4[NativeMethods.GetVectorSizeMatrix4x4(&__retVal_native)];
				NativeMethods.GetVectorDataMatrix4x4(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorMatrix4x4(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncVec2, Vector2> CallFuncVec2Callback = &___CallFuncVec2Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector2> __CallFuncVec2Callback;
		private static Vector2 ___CallFuncVec2Callback(FuncVec2 func)
		{
			Vector2 __retVal = __CallFuncVec2Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncVec3, Vector3> CallFuncVec3Callback = &___CallFuncVec3Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector3> __CallFuncVec3Callback;
		private static Vector3 ___CallFuncVec3Callback(FuncVec3 func)
		{
			Vector3 __retVal = __CallFuncVec3Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncVec4, Vector4> CallFuncVec4Callback = &___CallFuncVec4Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector4> __CallFuncVec4Callback;
		private static Vector4 ___CallFuncVec4Callback(FuncVec4 func)
		{
			Vector4 __retVal = __CallFuncVec4Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncMat4x4, Matrix4x4> CallFuncMat4x4Callback = &___CallFuncMat4x4Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Matrix4x4> __CallFuncMat4x4Callback;
		private static Matrix4x4 ___CallFuncMat4x4Callback(FuncMat4x4 func)
		{
			Matrix4x4 __retVal = __CallFuncMat4x4Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func1, int> CallFunc1Callback = &___CallFunc1Callback;
		internal static delegate* unmanaged[Cdecl]<nint, int> __CallFunc1Callback;
		private static int ___CallFunc1Callback(Func1 func)
		{
			int __retVal = __CallFunc1Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func2, Char8> CallFunc2Callback = &___CallFunc2Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Char8> __CallFunc2Callback;
		private static Char8 ___CallFunc2Callback(Func2 func)
		{
			Char8 __retVal = __CallFunc2Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>

		internal static delegate*<Func3, void> CallFunc3Callback = &___CallFunc3Callback;
		internal static delegate* unmanaged[Cdecl]<nint, void> __CallFunc3Callback;
		private static void ___CallFunc3Callback(Func3 func)
		{
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__CallFunc3Callback(__func);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func4, Vector4> CallFunc4Callback = &___CallFunc4Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector4> __CallFunc4Callback;
		private static Vector4 ___CallFunc4Callback(Func4 func)
		{
			Vector4 __retVal = __CallFunc4Callback(Marshal.GetFunctionPointerForDelegate(func));
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func5, Bool8> CallFunc5Callback = &___CallFunc5Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Bool8> __CallFunc5Callback;
		private static Bool8 ___CallFunc5Callback(Func5 func)
		{
			Bool8 __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc5Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func6, long> CallFunc6Callback = &___CallFunc6Callback;
		internal static delegate* unmanaged[Cdecl]<nint, long> __CallFunc6Callback;
		private static long ___CallFunc6Callback(Func6 func)
		{
			long __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc6Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func7, double> CallFunc7Callback = &___CallFunc7Callback;
		internal static delegate* unmanaged[Cdecl]<nint, double> __CallFunc7Callback;
		private static double ___CallFunc7Callback(Func7 func)
		{
			double __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc7Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func8, Matrix4x4> CallFunc8Callback = &___CallFunc8Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Matrix4x4> __CallFunc8Callback;
		private static Matrix4x4 ___CallFunc8Callback(Func8 func)
		{
			Matrix4x4 __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc8Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>

		internal static delegate*<Func9, void> CallFunc9Callback = &___CallFunc9Callback;
		internal static delegate* unmanaged[Cdecl]<nint, void> __CallFunc9Callback;
		private static void ___CallFunc9Callback(Func9 func)
		{
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__CallFunc9Callback(__func);
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func10, uint> CallFunc10Callback = &___CallFunc10Callback;
		internal static delegate* unmanaged[Cdecl]<nint, uint> __CallFunc10Callback;
		private static uint ___CallFunc10Callback(Func10 func)
		{
			uint __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc10Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func11, nint> CallFunc11Callback = &___CallFunc11Callback;
		internal static delegate* unmanaged[Cdecl]<nint, nint> __CallFunc11Callback;
		private static nint ___CallFunc11Callback(Func11 func)
		{
			nint __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc11Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func12, Bool8> CallFunc12Callback = &___CallFunc12Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Bool8> __CallFunc12Callback;
		private static Bool8 ___CallFunc12Callback(Func12 func)
		{
			Bool8 __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc12Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func13, string> CallFunc13Callback = &___CallFunc13Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc13Callback;
		private static string ___CallFunc13Callback(Func13 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc13Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func14, string[]> CallFunc14Callback = &___CallFunc14Callback;
		internal static delegate* unmanaged[Cdecl]<nint, Vector192> __CallFunc14Callback;
		private static string[] ___CallFunc14Callback(Func14 func)
		{
			string[] __retVal;
			Vector192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc14Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = new string[NativeMethods.GetVectorSizeString(&__retVal_native)];
				NativeMethods.GetVectorDataString(&__retVal_native, __retVal);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func15, short> CallFunc15Callback = &___CallFunc15Callback;
		internal static delegate* unmanaged[Cdecl]<nint, short> __CallFunc15Callback;
		private static short ___CallFunc15Callback(Func15 func)
		{
			short __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc15Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func16, nint> CallFunc16Callback = &___CallFunc16Callback;
		internal static delegate* unmanaged[Cdecl]<nint, nint> __CallFunc16Callback;
		private static nint ___CallFunc16Callback(Func16 func)
		{
			nint __retVal;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			__retVal = __CallFunc16Callback(__func);
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func17, string> CallFunc17Callback = &___CallFunc17Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc17Callback;
		private static string ___CallFunc17Callback(Func17 func)
		{
			string __retVal;
			String192 __retVal_native;

			try {
				__retVal_native = __CallFunc17Callback(Marshal.GetFunctionPointerForDelegate(func));
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func18, string> CallFunc18Callback = &___CallFunc18Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc18Callback;
		private static string ___CallFunc18Callback(Func18 func)
		{
			string __retVal;
			String192 __retVal_native;

			try {
				__retVal_native = __CallFunc18Callback(Marshal.GetFunctionPointerForDelegate(func));
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func19, string> CallFunc19Callback = &___CallFunc19Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc19Callback;
		private static string ___CallFunc19Callback(Func19 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc19Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func20, string> CallFunc20Callback = &___CallFunc20Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc20Callback;
		private static string ___CallFunc20Callback(Func20 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc20Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func21, string> CallFunc21Callback = &___CallFunc21Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc21Callback;
		private static string ___CallFunc21Callback(Func21 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc21Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func22, string> CallFunc22Callback = &___CallFunc22Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc22Callback;
		private static string ___CallFunc22Callback(Func22 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc22Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func23, string> CallFunc23Callback = &___CallFunc23Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc23Callback;
		private static string ___CallFunc23Callback(Func23 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc23Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func24, string> CallFunc24Callback = &___CallFunc24Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc24Callback;
		private static string ___CallFunc24Callback(Func24 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc24Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func25, string> CallFunc25Callback = &___CallFunc25Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc25Callback;
		private static string ___CallFunc25Callback(Func25 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc25Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func26, string> CallFunc26Callback = &___CallFunc26Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc26Callback;
		private static string ___CallFunc26Callback(Func26 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc26Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func27, string> CallFunc27Callback = &___CallFunc27Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc27Callback;
		private static string ___CallFunc27Callback(Func27 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc27Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func28, string> CallFunc28Callback = &___CallFunc28Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc28Callback;
		private static string ___CallFunc28Callback(Func28 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc28Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func29, string> CallFunc29Callback = &___CallFunc29Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc29Callback;
		private static string ___CallFunc29Callback(Func29 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc29Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func30, string> CallFunc30Callback = &___CallFunc30Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc30Callback;
		private static string ___CallFunc30Callback(Func30 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc30Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func31, string> CallFunc31Callback = &___CallFunc31Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc31Callback;
		private static string ___CallFunc31Callback(Func31 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc31Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func32, string> CallFunc32Callback = &___CallFunc32Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc32Callback;
		private static string ___CallFunc32Callback(Func32 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc32Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<Func33, string> CallFunc33Callback = &___CallFunc33Callback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFunc33Callback;
		private static string ___CallFunc33Callback(Func33 func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFunc33Callback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

		/// <summary>
		/// No description provided.
		/// </summary>
		/// <param name="func">No description available.</param>
		/// <returns>No description available.</returns>

		internal static delegate*<FuncEnum, string> CallFuncEnumCallback = &___CallFuncEnumCallback;
		internal static delegate* unmanaged[Cdecl]<nint, String192> __CallFuncEnumCallback;
		private static string ___CallFuncEnumCallback(FuncEnum func)
		{
			string __retVal;
			String192 __retVal_native;
			var __func = Marshalling.GetFunctionPointerForDelegate(func);

			try {
				__retVal_native = __CallFuncEnumCallback(__func);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);

			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}

	}
#pragma warning restore CS0649
}