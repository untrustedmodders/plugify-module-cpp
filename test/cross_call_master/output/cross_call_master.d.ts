// Generated from cross_call_master.pplugin by https://github.com/untrustedmodders/plugify-module-v8/blob/main/generator/generator.py

declare module "plugify" {
  /**
   * Represents a plugin with metadata information.
   */
  type Plugin = {
    /** Unique identifier for the plugin */
    id: bigint;
    /** Short name of the plugin */
    name: string;
    /** Full name of the plugin */
    fullName: string;
    /** Description of the plugin */
    description: string;
    /** Version of the plugin */
    version: string;
    /** Author of the plugin */
    author: string;
    /** Website of the plugin */
    website: string;
    /** Base directory where the plugin is stored */
    baseDir: string;
    /** List of dependencies required by the plugin */
    dependencies: string[];
  };

  /**
   * Represents a 2D vector with basic mathematical operations.
   */
  type Vector2 = {
    /** X-coordinate of the vector */
    x: number;
    /** Y-coordinate of the vector */
    y: number;
    /** Adds another Vector2 to this vector */
    add: (vector: Vector2) => Vector2;
    /** Subtracts another Vector2 from this vector */
    subtract: (vector: Vector2) => Vector2;
    /** Scales this vector by a scalar */
    scale: (scalar: number) => Vector2;
    /** Returns the magnitude (length) of the vector */
    magnitude: () => number;
    /** Returns a normalized (unit length) version of this vector */
    normalize: () => Vector2;
    /** Returns the dot product with another Vector2 */
    dot: (vector: Vector2) => number;
    /** Computes the distance between this vector and another Vector2 */
    distanceTo: (vector: Vector2) => number;
  };

  /**
   * Represents a 3D vector with basic mathematical operations.
   */
  type Vector3 = {
    /** X-coordinate of the vector */
    x: number;
    /** Y-coordinate of the vector */
    y: number;
    /** Z-coordinate of the vector */
    z: number;
    /** Adds another Vector3 to this vector */
    add: (vector: Vector3) => Vector3;
    /** Subtracts another Vector3 from this vector */
    subtract: (vector: Vector3) => Vector3;
    /** Scales this vector by a scalar */
    scale: (scalar: number) => Vector3;
    /** Returns the magnitude (length) of the vector */
    magnitude: () => number;
    /** Returns a normalized (unit length) version of this vector */
    normalize: () => Vector3;
    /** Returns the dot product with another Vector3 */
    dot: (vector: Vector3) => number;
    /** Computes the cross product with another Vector3 */
    cross: (vector: Vector3) => Vector3;
    /** Computes the distance between this vector and another Vector3 */
    distanceTo: (vector: Vector3) => number;
  };

  /**
   * Represents a 4D vector with basic mathematical operations.
   */
  type Vector4 = {
    /** X-coordinate of the vector */
    x: number;
    /** Y-coordinate of the vector */
    y: number;
    /** Z-coordinate of the vector */
    z: number;
    /** W-coordinate of the vector */
    w: number;
    /** Adds another Vector4 to this vector */
    add: (vector: Vector4) => Vector4;
    /** Subtracts another Vector4 from this vector */
    subtract: (vector: Vector4) => Vector4;
    /** Scales this vector by a scalar */
    scale: (scalar: number) => Vector4;
    /** Returns the magnitude (length) of the vector */
    magnitude: () => number;
    /** Returns a normalized (unit length) version of this vector */
    normalize: () => Vector4;
    /** Returns the dot product with another Vector4 */
    dot: (vector: Vector4) => number;
    /** Computes the distance between this vector and another Vector4 */
    distanceTo: (vector: Vector4) => number;
  };

  /**
   * Represents a 4x4 matrix with operations for transformations.
   */
  type Matrix4x4 = {
    /** Elements stored as a 2D array */
    elements: number[][];
    /** Adds another matrix to this matrix */
    add: (matrix: Matrix4x4) => Matrix4x4;
    /** Subtracts another matrix from this matrix */
    subtract: (matrix: Matrix4x4) => Matrix4x4;
    /** Multiplies this matrix with another matrix */
    multiply: (matrix: Matrix4x4) => Matrix4x4;
    /** Multiplies this matrix with a Vector4 */
    multiplyVector: (vector: Vector4) => Vector4;
    /** Returns the transpose of this matrix */
    transpose: () => Matrix4x4;
  };
}

declare module ":cross_call_master" {
  import { Vector2, Vector3, Vector4, Matrix4x4 } from "plugify";


  export const enum Example {
    First = 1,
    Second = 2,
    Third = 3,
    Forth = 4,
  }


  export type NoParamReturnFunctionCallbackFunc = () => number;
  export type FuncVoid = () => void;
  export type FuncBool = () => boolean;
  export type FuncChar8 = () => string;
  export type FuncChar16 = () => string;
  export type FuncInt8 = () => number;
  export type FuncInt16 = () => number;
  export type FuncInt32 = () => number;
  export type FuncInt64 = () => number;
  export type FuncUInt8 = () => number;
  export type FuncUInt16 = () => number;
  export type FuncUInt32 = () => number;
  export type FuncUInt64 = () => bigint;
  export type FuncPtr = () => bigint;
  export type FuncFloat = () => number;
  export type FuncDouble = () => number;
  export type FuncString = () => string;
  export type FuncAny = () => any;
  export type FuncFunction = () => delegate;
  export type FuncBoolVector = () => boolean[];
  export type FuncChar8Vector = () => string[];
  export type FuncChar16Vector = () => string[];
  export type FuncInt8Vector = () => number[];
  export type FuncInt16Vector = () => number[];
  export type FuncInt32Vector = () => number[];
  export type FuncInt64Vector = () => number[];
  export type FuncUInt8Vector = () => number[];
  export type FuncUInt16Vector = () => number[];
  export type FuncUInt32Vector = () => number[];
  export type FuncUInt64Vector = () => bigint[];
  export type FuncPtrVector = () => bigint[];
  export type FuncFloatVector = () => number[];
  export type FuncDoubleVector = () => number[];
  export type FuncStringVector = () => string[];
  export type FuncAnyVector = () => any[];
  export type FuncVec2Vector = () => Vector2[];
  export type FuncVec3Vector = () => Vector3[];
  export type FuncVec4Vector = () => Vector4[];
  export type FuncMat4x4Vector = () => Matrix4x4[];
  export type FuncVec2 = () => Vector2;
  export type FuncVec3 = () => Vector3;
  export type FuncVec4 = () => Vector4;
  export type FuncMat4x4 = () => Matrix4x4;
  export type Func1 = (a: Vector3) => number;
  export type Func2 = (a: number, b: number) => string;
  export type Func3 = (a: bigint, b: Vector4, c: string) => void;
  export type Func4 = (a: boolean, b: number, c: string, d: Matrix4x4) => Vector4;
  export type Func5 = (a: number, b: Vector2, c: bigint, d: number, e: bigint[]) => boolean;
  export type Func6 = (a: string, b: number, c: number[], d: number, e: number[], f: bigint) => number;
  export type Func7 = (vecC: string[], u16: number, ch16: string, vecU32: number[], vec4: Vector4, b: boolean, u64: bigint) => number;
  export type Func8 = (vec3: Vector3, vecU32: number[], i16: number, b: boolean, vec4: Vector4, vecC16: string[], ch16: string, i32: number) => Matrix4x4;
  export type Func9 = (f: number, vec2: Vector2, vecI8: number[], u64: bigint, b: boolean, str: string, vec4: Vector4, i16: number, ptr: bigint) => void;
  export type Func10 = (vec4: Vector4, mat: Matrix4x4, vecU32: number[], u64: bigint, vecC: string[], i32: number, b: boolean, vec2: Vector2, i64: number, d: number) => number;
  export type Func11 = (vecB: boolean[], ch16: string, u8: number, d: number, vec3: Vector3, vecI8: number[], i64: number, u16: number, f: number, vec2: Vector2, u32: number) => bigint;
  export type Func12 = (ptr: bigint, vecD: number[], u32: number, d: number, b: boolean, i32: number, i8: number, u64: bigint, f: number, vecPtr: bigint[], i64: number, ch: string) => boolean;
  export type Func13 = (i64: number, vecC: string[], d: number, f: number, b: boolean[], vec4: Vector4, str: string, int32: number, vec3: Vector3, ptr: bigint, vec2: Vector2, arr: number[], i16: number) => string;
  export type Func14 = (vecC: string[], vecU32: number[], mat: Matrix4x4, b: boolean, ch16: string, i32: number, vecF: number[], u16: number, vecU8: number[], i8: number, vec3: Vector3, vec4: Vector4, d: number, ptr: bigint) => string[];
  export type Func15 = (vecI16: number[], mat: Matrix4x4, vec4: Vector4, ptr: bigint, u64: bigint, vecU32: number[], b: boolean, f: number, vecC16: string[], u8: number, i32: number, vec2: Vector2, u16: number, d: number, vecU8: number[]) => number;
  export type Func16 = (vecB: boolean[], i16: number, vecI8: number[], vec4: Vector4, mat: Matrix4x4, vec2: Vector2, vecU64: bigint[], vecC: string[], str: string, i64: number, vecU32: number[], vec3: Vector3, f: number, d: number, i8: number, u16: number) => bigint;
  export type Func17 = (i32: number) => [void,number];
  export type Func18 = (i8: number, i16: number) => [Vector2,number,number];
  export type Func19 = (u32: number, vec3: Vector3, vecU32: number[]) => [void,number,Vector3,number[]];
  export type Func20 = (ch16: string, vec4: Vector4, vecU64: bigint[], ch: string) => [number,string,Vector4,bigint[],string];
  export type Func21 = (mat: Matrix4x4, vecI32: number[], vec2: Vector2, b: boolean, extraParam: number) => [number,Matrix4x4,number[],Vector2,boolean,number];
  export type Func22 = (ptr64Ref: bigint, uint32Ref: number, vectorDoubleRef: number[], int16Ref: number, plgStringRef: string, plgVector4Ref: Vector4) => [bigint,bigint,number,number[],number,string,Vector4];
  export type Func23 = (uint64Ref: bigint, plgVector2Ref: Vector2, vectorInt16Ref: number[], char16Ref: string, floatRef: number, int8Ref: number, vectorUInt8Ref: number[]) => [void,bigint,Vector2,number[],string,number,number,number[]];
  export type Func24 = (vectorCharRef: string[], int64Ref: number, vectorUInt8Ref: number[], plgVector4Ref: Vector4, uint64Ref: bigint, vectorptr64Ref: bigint[], doubleRef: number, vectorptr64Ref2: bigint[]) => [Matrix4x4,string[],number,number[],Vector4,bigint,bigint[],number,bigint[]];
  export type Func25 = (int32Ref: number, vectorptr64Ref: bigint[], boolRef: boolean, uint8Ref: number, plgStringRef: string, plgVector3Ref: Vector3, int64Ref: number, plgVector4Ref: Vector4, uint16Ref: number) => [number,number,bigint[],boolean,number,string,Vector3,number,Vector4,number];
  export type Func26 = (char16Ref: string, plgVector2Ref: Vector2, plgMatrix4x4Ref: Matrix4x4, vectorFloatRef: number[], int16Ref: number, uint64Ref: bigint, uint32Ref: number, vectorUInt16Ref: number[], ptr64Ref: bigint, boolRef: boolean) => [string,string,Vector2,Matrix4x4,number[],number,bigint,number,number[],bigint,boolean];
  export type Func27 = (floatRef: number, plgVector3Ref: Vector3, ptr64Ref: bigint, plgVector2Ref: Vector2, vectorInt16Ref: number[], plgMatrix4x4Ref: Matrix4x4, boolRef: boolean, plgVector4Ref: Vector4, int8Ref: number, int32Ref: number, vectorUInt8Ref: number[]) => [number,number,Vector3,bigint,Vector2,number[],Matrix4x4,boolean,Vector4,number,number,number[]];
  export type Func28 = (ptr64Ref: bigint, uint16Ref: number, vectorUInt32Ref: number[], plgMatrix4x4Ref: Matrix4x4, floatRef: number, plgVector4Ref: Vector4, plgStringRef: string, vectorUInt64Ref: bigint[], int64Ref: number, boolRef: boolean, plgVector3Ref: Vector3, vectorFloatRef: number[]) => [string,bigint,number,number[],Matrix4x4,number,Vector4,string,bigint[],number,boolean,Vector3,number[]];
  export type Func29 = (plgVector4Ref: Vector4, int32Ref: number, vectorInt8Ref: number[], doubleRef: number, boolRef: boolean, int8Ref: number, vectorUInt16Ref: number[], floatRef: number, plgStringRef: string, plgMatrix4x4Ref: Matrix4x4, uint64Ref: bigint, plgVector3Ref: Vector3, vectorInt64Ref: number[]) => [string[],Vector4,number,number[],number,boolean,number,number[],number,string,Matrix4x4,bigint,Vector3,number[]];
  export type Func30 = (ptr64Ref: bigint, plgVector4Ref: Vector4, int64Ref: number, vectorUInt32Ref: number[], boolRef: boolean, plgStringRef: string, plgVector3Ref: Vector3, vectorUInt8Ref: number[], floatRef: number, plgVector2Ref: Vector2, plgMatrix4x4Ref: Matrix4x4, int8Ref: number, vectorFloatRef: number[], doubleRef: number) => [number,bigint,Vector4,number,number[],boolean,string,Vector3,number[],number,Vector2,Matrix4x4,number,number[],number];
  export type Func31 = (charRef: string, uint32Ref: number, vectorUInt64Ref: bigint[], plgVector4Ref: Vector4, plgStringRef: string, boolRef: boolean, int64Ref: number, vec2Ref: Vector2, int8Ref: number, uint16Ref: number, vectorInt16Ref: number[], mat4x4Ref: Matrix4x4, vec3Ref: Vector3, floatRef: number, vectorDoubleRef: number[]) => [Vector3,string,number,bigint[],Vector4,string,boolean,number,Vector2,number,number,number[],Matrix4x4,Vector3,number,number[]];
  export type Func32 = (p1: number, p2: number, p3: number[], p4: Vector4, p5: bigint, p6: number[], p7: Matrix4x4, p8: bigint, p9: string, p10: number, p11: Vector2, p12: number[], p13: boolean, p14: Vector3, p15: number, p16: string[]) => [number,number,number,number[],Vector4,bigint,number[],Matrix4x4,bigint,string,number,Vector2,number[],boolean,Vector3,number,string[]];
  export type Func33 = (variant: any) => [void,any];
  export type FuncEnum = (p1: Example, p2: Example[]) => [Example[],Example[]];



  /**
   * No description provided.
   *
   * @param {string} returnString - No description available.
   */
  export function ReverseReturn(returnString: string): void;
  /**
   * No description provided.
   *
   */
  export function NoParamReturnVoidCallback(): void;
  /**
   * No description provided.
   *
   * @returns {bool} - No description available.
   */
  export function NoParamReturnBoolCallback(): boolean;
  /**
   * No description provided.
   *
   * @returns {char8} - No description available.
   */
  export function NoParamReturnChar8Callback(): string;
  /**
   * No description provided.
   *
   * @returns {char16} - No description available.
   */
  export function NoParamReturnChar16Callback(): string;
  /**
   * No description provided.
   *
   * @returns {int8} - No description available.
   */
  export function NoParamReturnInt8Callback(): number;
  /**
   * No description provided.
   *
   * @returns {int16} - No description available.
   */
  export function NoParamReturnInt16Callback(): number;
  /**
   * No description provided.
   *
   * @returns {int32} - No description available.
   */
  export function NoParamReturnInt32Callback(): number;
  /**
   * No description provided.
   *
   * @returns {int64} - No description available.
   */
  export function NoParamReturnInt64Callback(): number;
  /**
   * No description provided.
   *
   * @returns {uint8} - No description available.
   */
  export function NoParamReturnUInt8Callback(): number;
  /**
   * No description provided.
   *
   * @returns {uint16} - No description available.
   */
  export function NoParamReturnUInt16Callback(): number;
  /**
   * No description provided.
   *
   * @returns {uint32} - No description available.
   */
  export function NoParamReturnUInt32Callback(): number;
  /**
   * No description provided.
   *
   * @returns {uint64} - No description available.
   */
  export function NoParamReturnUInt64Callback(): bigint;
  /**
   * No description provided.
   *
   * @returns {ptr64} - No description available.
   */
  export function NoParamReturnPointerCallback(): bigint;
  /**
   * No description provided.
   *
   * @returns {float} - No description available.
   */
  export function NoParamReturnFloatCallback(): number;
  /**
   * No description provided.
   *
   * @returns {double} - No description available.
   */
  export function NoParamReturnDoubleCallback(): number;
  /**
   * No description provided.
   *
   * @returns {function} - No description available.
   */
  export function NoParamReturnFunctionCallback(): NoParamReturnFunctionCallbackFunc;
  /**
   * No description provided.
   *
   * @returns {string} - No description available.
   */
  export function NoParamReturnStringCallback(): string;
  /**
   * No description provided.
   *
   * @returns {any} - No description available.
   */
  export function NoParamReturnAnyCallback(): any;
  /**
   * No description provided.
   *
   * @returns {bool[]} - No description available.
   */
  export function NoParamReturnArrayBoolCallback(): boolean[];
  /**
   * No description provided.
   *
   * @returns {char8[]} - No description available.
   */
  export function NoParamReturnArrayChar8Callback(): string[];
  /**
   * No description provided.
   *
   * @returns {char16[]} - No description available.
   */
  export function NoParamReturnArrayChar16Callback(): string[];
  /**
   * No description provided.
   *
   * @returns {int8[]} - No description available.
   */
  export function NoParamReturnArrayInt8Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {int16[]} - No description available.
   */
  export function NoParamReturnArrayInt16Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {int32[]} - No description available.
   */
  export function NoParamReturnArrayInt32Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {int64[]} - No description available.
   */
  export function NoParamReturnArrayInt64Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {uint8[]} - No description available.
   */
  export function NoParamReturnArrayUInt8Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {uint16[]} - No description available.
   */
  export function NoParamReturnArrayUInt16Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {uint32[]} - No description available.
   */
  export function NoParamReturnArrayUInt32Callback(): number[];
  /**
   * No description provided.
   *
   * @returns {uint64[]} - No description available.
   */
  export function NoParamReturnArrayUInt64Callback(): bigint[];
  /**
   * No description provided.
   *
   * @returns {ptr64[]} - No description available.
   */
  export function NoParamReturnArrayPointerCallback(): bigint[];
  /**
   * No description provided.
   *
   * @returns {float[]} - No description available.
   */
  export function NoParamReturnArrayFloatCallback(): number[];
  /**
   * No description provided.
   *
   * @returns {double[]} - No description available.
   */
  export function NoParamReturnArrayDoubleCallback(): number[];
  /**
   * No description provided.
   *
   * @returns {string[]} - No description available.
   */
  export function NoParamReturnArrayStringCallback(): string[];
  /**
   * No description provided.
   *
   * @returns {any[]} - No description available.
   */
  export function NoParamReturnArrayAnyCallback(): any[];
  /**
   * No description provided.
   *
   * @returns {vec2[]} - No description available.
   */
  export function NoParamReturnArrayVector2Callback(): Vector2[];
  /**
   * No description provided.
   *
   * @returns {vec3[]} - No description available.
   */
  export function NoParamReturnArrayVector3Callback(): Vector3[];
  /**
   * No description provided.
   *
   * @returns {vec4[]} - No description available.
   */
  export function NoParamReturnArrayVector4Callback(): Vector4[];
  /**
   * No description provided.
   *
   * @returns {mat4x4[]} - No description available.
   */
  export function NoParamReturnArrayMatrix4x4Callback(): Matrix4x4[];
  /**
   * No description provided.
   *
   * @returns {vec2} - No description available.
   */
  export function NoParamReturnVector2Callback(): Vector2;
  /**
   * No description provided.
   *
   * @returns {vec3} - No description available.
   */
  export function NoParamReturnVector3Callback(): Vector3;
  /**
   * No description provided.
   *
   * @returns {vec4} - No description available.
   */
  export function NoParamReturnVector4Callback(): Vector4;
  /**
   * No description provided.
   *
   * @returns {mat4x4} - No description available.
   */
  export function NoParamReturnMatrix4x4Callback(): Matrix4x4;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   */
  export function Param1Callback(a: number): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   */
  export function Param2Callback(a: number, b: number): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   */
  export function Param3Callback(a: number, b: number, c: number): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   */
  export function Param4Callback(a: number, b: number, c: number, d: Vector4): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   */
  export function Param5Callback(a: number, b: number, c: number, d: Vector4, e: number[]): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   */
  export function Param6Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   */
  export function Param7Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   * @param {char16} h - No description available.
   */
  export function Param8Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string, h: string): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   * @param {char16} h - No description available.
   * @param {int16} k - No description available.
   */
  export function Param9Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string, h: string, k: number): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   * @param {char16} h - No description available.
   * @param {int16} k - No description available.
   * @param {ptr64} l - No description available.
   */
  export function Param10Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string, h: string, k: number, l: bigint): void;
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   */
  export function ParamRef1Callback(a: number): [void,number];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   */
  export function ParamRef2Callback(a: number, b: number): [void,number,number];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   */
  export function ParamRef3Callback(a: number, b: number, c: number): [void,number,number,number];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   */
  export function ParamRef4Callback(a: number, b: number, c: number, d: Vector4): [void,number,number,number,Vector4];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   */
  export function ParamRef5Callback(a: number, b: number, c: number, d: Vector4, e: number[]): [void,number,number,number,Vector4,number[]];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   */
  export function ParamRef6Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string): [void,number,number,number,Vector4,number[],string];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   */
  export function ParamRef7Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string): [void,number,number,number,Vector4,number[],string,string];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   * @param {char16} h - No description available.
   */
  export function ParamRef8Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string, h: string): [void,number,number,number,Vector4,number[],string,string,string];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   * @param {char16} h - No description available.
   * @param {int16} k - No description available.
   */
  export function ParamRef9Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string, h: string, k: number): [void,number,number,number,Vector4,number[],string,string,string,number];
  /**
   * No description provided.
   *
   * @param {int32} a - No description available.
   * @param {float} b - No description available.
   * @param {double} c - No description available.
   * @param {vec4} d - No description available.
   * @param {int64[]} e - No description available.
   * @param {char8} f - No description available.
   * @param {string} g - No description available.
   * @param {char16} h - No description available.
   * @param {int16} k - No description available.
   * @param {ptr64} l - No description available.
   */
  export function ParamRef10Callback(a: number, b: number, c: number, d: Vector4, e: number[], f: string, g: string, h: string, k: number, l: bigint): [void,number,number,number,Vector4,number[],string,string,string,number,bigint];
  /**
   * No description provided.
   *
   * @param {bool[]} p1 - No description available.
   * @param {char8[]} p2 - No description available.
   * @param {char16[]} p3 - No description available.
   * @param {int8[]} p4 - No description available.
   * @param {int16[]} p5 - No description available.
   * @param {int32[]} p6 - No description available.
   * @param {int64[]} p7 - No description available.
   * @param {uint8[]} p8 - No description available.
   * @param {uint16[]} p9 - No description available.
   * @param {uint32[]} p10 - No description available.
   * @param {uint64[]} p11 - No description available.
   * @param {ptr64[]} p12 - No description available.
   * @param {float[]} p13 - No description available.
   * @param {double[]} p14 - No description available.
   * @param {string[]} p15 - No description available.
   */
  export function ParamRefVectorsCallback(p1: boolean[], p2: string[], p3: string[], p4: number[], p5: number[], p6: number[], p7: number[], p8: number[], p9: number[], p10: number[], p11: bigint[], p12: bigint[], p13: number[], p14: number[], p15: string[]): [void,boolean[],string[],string[],number[],number[],number[],number[],number[],number[],number[],bigint[],bigint[],number[],number[],string[]];
  /**
   * No description provided.
   *
   * @param {bool} p1 - No description available.
   * @param {char8} p2 - No description available.
   * @param {char16} p3 - No description available.
   * @param {int8} p4 - No description available.
   * @param {int16} p5 - No description available.
   * @param {int32} p6 - No description available.
   * @param {int64} p7 - No description available.
   * @param {uint8} p8 - No description available.
   * @param {uint16} p9 - No description available.
   * @param {uint32} p10 - No description available.
   * @param {uint64} p11 - No description available.
   * @param {ptr64} p12 - No description available.
   * @param {float} p13 - No description available.
   * @param {double} p14 - No description available.
   * @returns {int64} - No description available.
   */
  export function ParamAllPrimitivesCallback(p1: boolean, p2: string, p3: string, p4: number, p5: number, p6: number, p7: number, p8: number, p9: number, p10: number, p11: bigint, p12: bigint, p13: number, p14: number): number;
  /**
   * No description provided.
   *
   * @param {int32} p1 - No description available.
   * @param {int32[]} p2 - No description available.
   * @returns {int32} - No description available.
   */
  export function ParamEnumCallback(p1: Example, p2: Example[]): number;
  /**
   * No description provided.
   *
   * @param {int32} p1 - No description available.
   * @param {int32[]} p2 - No description available.
   * @returns {int32} - No description available.
   */
  export function ParamEnumRefCallback(p1: Example, p2: Example[]): [number,Example,Example[]];
  /**
   * No description provided.
   *
   * @param {any} p1 - No description available.
   * @param {any[]} p2 - No description available.
   */
  export function ParamVariantCallback(p1: any, p2: any[]): void;
  /**
   * No description provided.
   *
   * @param {any} p1 - No description available.
   * @param {any[]} p2 - No description available.
   */
  export function ParamVariantRefCallback(p1: any, p2: any[]): [void,any,any[]];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   */
  export function CallFuncVoidCallback(func: FuncVoid): void;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {bool} - No description available.
   */
  export function CallFuncBoolCallback(func: FuncBool): boolean;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {char8} - No description available.
   */
  export function CallFuncChar8Callback(func: FuncChar8): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {char16} - No description available.
   */
  export function CallFuncChar16Callback(func: FuncChar16): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int8} - No description available.
   */
  export function CallFuncInt8Callback(func: FuncInt8): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int16} - No description available.
   */
  export function CallFuncInt16Callback(func: FuncInt16): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int32} - No description available.
   */
  export function CallFuncInt32Callback(func: FuncInt32): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int64} - No description available.
   */
  export function CallFuncInt64Callback(func: FuncInt64): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint8} - No description available.
   */
  export function CallFuncUInt8Callback(func: FuncUInt8): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint16} - No description available.
   */
  export function CallFuncUInt16Callback(func: FuncUInt16): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint32} - No description available.
   */
  export function CallFuncUInt32Callback(func: FuncUInt32): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint64} - No description available.
   */
  export function CallFuncUInt64Callback(func: FuncUInt64): bigint;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {ptr64} - No description available.
   */
  export function CallFuncPtrCallback(func: FuncPtr): bigint;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {float} - No description available.
   */
  export function CallFuncFloatCallback(func: FuncFloat): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {double} - No description available.
   */
  export function CallFuncDoubleCallback(func: FuncDouble): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFuncStringCallback(func: FuncString): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {any} - No description available.
   */
  export function CallFuncAnyCallback(func: FuncAny): any;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {ptr64} - No description available.
   */
  export function CallFuncFunctionCallback(func: FuncFunction): bigint;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {bool[]} - No description available.
   */
  export function CallFuncBoolVectorCallback(func: FuncBoolVector): boolean[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {char8[]} - No description available.
   */
  export function CallFuncChar8VectorCallback(func: FuncChar8Vector): string[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {char16[]} - No description available.
   */
  export function CallFuncChar16VectorCallback(func: FuncChar16Vector): string[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int8[]} - No description available.
   */
  export function CallFuncInt8VectorCallback(func: FuncInt8Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int16[]} - No description available.
   */
  export function CallFuncInt16VectorCallback(func: FuncInt16Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int32[]} - No description available.
   */
  export function CallFuncInt32VectorCallback(func: FuncInt32Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int64[]} - No description available.
   */
  export function CallFuncInt64VectorCallback(func: FuncInt64Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint8[]} - No description available.
   */
  export function CallFuncUInt8VectorCallback(func: FuncUInt8Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint16[]} - No description available.
   */
  export function CallFuncUInt16VectorCallback(func: FuncUInt16Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint32[]} - No description available.
   */
  export function CallFuncUInt32VectorCallback(func: FuncUInt32Vector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint64[]} - No description available.
   */
  export function CallFuncUInt64VectorCallback(func: FuncUInt64Vector): bigint[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {ptr64[]} - No description available.
   */
  export function CallFuncPtrVectorCallback(func: FuncPtrVector): bigint[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {float[]} - No description available.
   */
  export function CallFuncFloatVectorCallback(func: FuncFloatVector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {double[]} - No description available.
   */
  export function CallFuncDoubleVectorCallback(func: FuncDoubleVector): number[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string[]} - No description available.
   */
  export function CallFuncStringVectorCallback(func: FuncStringVector): string[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {any[]} - No description available.
   */
  export function CallFuncAnyVectorCallback(func: FuncAnyVector): any[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec2[]} - No description available.
   */
  export function CallFuncVec2VectorCallback(func: FuncVec2Vector): Vector2[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec3[]} - No description available.
   */
  export function CallFuncVec3VectorCallback(func: FuncVec3Vector): Vector3[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec4[]} - No description available.
   */
  export function CallFuncVec4VectorCallback(func: FuncVec4Vector): Vector4[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {mat4x4[]} - No description available.
   */
  export function CallFuncMat4x4VectorCallback(func: FuncMat4x4Vector): Matrix4x4[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec2} - No description available.
   */
  export function CallFuncVec2Callback(func: FuncVec2): Vector2;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec3} - No description available.
   */
  export function CallFuncVec3Callback(func: FuncVec3): Vector3;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec4} - No description available.
   */
  export function CallFuncVec4Callback(func: FuncVec4): Vector4;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {mat4x4} - No description available.
   */
  export function CallFuncMat4x4Callback(func: FuncMat4x4): Matrix4x4;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int32} - No description available.
   */
  export function CallFunc1Callback(func: Func1): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {char8} - No description available.
   */
  export function CallFunc2Callback(func: Func2): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   */
  export function CallFunc3Callback(func: Func3): void;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {vec4} - No description available.
   */
  export function CallFunc4Callback(func: Func4): Vector4;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {bool} - No description available.
   */
  export function CallFunc5Callback(func: Func5): boolean;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int64} - No description available.
   */
  export function CallFunc6Callback(func: Func6): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {double} - No description available.
   */
  export function CallFunc7Callback(func: Func7): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {mat4x4} - No description available.
   */
  export function CallFunc8Callback(func: Func8): Matrix4x4;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   */
  export function CallFunc9Callback(func: Func9): void;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {uint32} - No description available.
   */
  export function CallFunc10Callback(func: Func10): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {ptr64} - No description available.
   */
  export function CallFunc11Callback(func: Func11): bigint;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {bool} - No description available.
   */
  export function CallFunc12Callback(func: Func12): boolean;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc13Callback(func: Func13): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string[]} - No description available.
   */
  export function CallFunc14Callback(func: Func14): string[];
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {int16} - No description available.
   */
  export function CallFunc15Callback(func: Func15): number;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {ptr64} - No description available.
   */
  export function CallFunc16Callback(func: Func16): bigint;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc17Callback(func: Func17): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc18Callback(func: Func18): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc19Callback(func: Func19): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc20Callback(func: Func20): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc21Callback(func: Func21): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc22Callback(func: Func22): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc23Callback(func: Func23): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc24Callback(func: Func24): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc25Callback(func: Func25): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc26Callback(func: Func26): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc27Callback(func: Func27): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc28Callback(func: Func28): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc29Callback(func: Func29): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc30Callback(func: Func30): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc31Callback(func: Func31): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc32Callback(func: Func32): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFunc33Callback(func: Func33): string;
  /**
   * No description provided.
   *
   * @param {function} func - No description available.
   * @returns {string} - No description available.
   */
  export function CallFuncEnumCallback(func: FuncEnum): string;
}