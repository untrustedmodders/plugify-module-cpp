package main

import (
	"fmt"
	"regexp"
	"strings"
)

// TypedefInfo holds the parsed structure of a typedef.
type TypedefInfo struct {
	Underlying        string
	USR               string
	Description       string
	IsFunctionPointer bool
	ReturnType        string
	ParamTypes        []string
}

var fnPtrReturnTypeRe = regexp.MustCompile(`^\s*(.+?)\s*\(\*\)`)

// parseFunctionPointerSignature parses a function pointer signature string, e.g.
// "ResultType (*)(int, CommandCallingContext, const plg::vector<plg::string> &)".
// Returns (returnType, paramTypes).
func parseFunctionPointerSignature(signature string) (string, []string) {
	if signature == "" || !strings.Contains(signature, "(*)") {
		return "", nil
	}

	m := fnPtrReturnTypeRe.FindStringSubmatch(signature)
	if m == nil {
		return "", nil
	}
	returnType := strings.TrimSpace(m[1])

	idx := strings.Index(signature, "(*)")
	paramsStart := idx + len("(*)")
	paramsStr := strings.TrimSpace(signature[paramsStart:])

	if !strings.HasPrefix(paramsStr, "(") || !strings.HasSuffix(paramsStr, ")") {
		return returnType, nil
	}

	paramsStr = strings.TrimSpace(paramsStr[1 : len(paramsStr)-1])
	if paramsStr == "" || paramsStr == "void" {
		return returnType, nil
	}

	// Parse parameters - tricky due to nested templates and pointers.
	var params []string
	var current strings.Builder
	depth := 0

	for _, ch := range paramsStr {
		switch ch {
		case '<':
			depth++
			current.WriteRune(ch)
		case '>':
			depth--
			current.WriteRune(ch)
		case ',':
			if depth == 0 {
				if p := strings.TrimSpace(current.String()); p != "" {
					params = append(params, p)
				}
				current.Reset()
			} else {
				current.WriteRune(ch)
			}
		default:
			current.WriteRune(ch)
		}
	}
	if p := strings.TrimSpace(current.String()); p != "" {
		params = append(params, p)
	}

	return returnType, params
}

// buildTypedefsMap builds a map of typedef names with parsed function signatures.
func buildTypedefsMap(yamlData map[string]interface{}) map[string]TypedefInfo {
	typedefsMap := map[string]TypedefInfo{}

	childTypedefs := asSlice(yamlData["ChildTypedefs"])
	for _, typedef := range childTypedefs {
		tm := asMap(typedef)
		if tm == nil {
			continue
		}

		typedefName := getStr(tm, "Name")
		if typedefName == "" {
			continue
		}

		underlyingName := getStr(asMap(tm["Underlying"]), "Name")

		entry := TypedefInfo{
			Underlying:  underlyingName,
			USR:         getStr(tm, "USR"),
			Description: extractTextFromDescription(tm["Description"]),
		}

		if strings.Contains(underlyingName, "(*)") {
			returnType, paramTypes := parseFunctionPointerSignature(underlyingName)
			entry.IsFunctionPointer = true
			entry.ReturnType = returnType
			entry.ParamTypes = paramTypes
		}

		typedefsMap[typedefName] = entry
	}

	return typedefsMap
}

// buildFunctionPrototype builds a function prototype structure for a function pointer typedef.
func buildFunctionPrototype(typedefName string, typedefsMap map[string]TypedefInfo, enumsMap map[string]EnumInfo) *FunctionPrototype {
	info, ok := typedefsMap[typedefName]
	if !ok || !info.IsFunctionPointer {
		return nil
	}

	proto := &FunctionPrototype{Name: typedefName, FuncName: typedefName}
	if info.Description != "" {
		proto.Description = info.Description
	}

	paramTypesList := make([]Param, 0, len(info.ParamTypes))
	for i, paramTypeStr := range info.ParamTypes {
		paramName := fmt.Sprintf("param%d", i+1)
		mappedType, isRef := convertType(paramTypeStr, enumsMap, typedefsMap)

		paramData := Param{Name: paramName, Type: mappedType, Ref: isRef}

		baseTypeName := stripTypeQualifiers(paramTypeStr)
		if _, ok := enumsMap[baseTypeName]; ok {
			if es := buildEnumStructure(baseTypeName, enumsMap); es != nil {
				paramData.Enum = es
			}
		}

		paramTypesList = append(paramTypesList, paramData)
	}
	proto.ParamTypes = paramTypesList

	// ReturnType may be empty (e.g. an unparsed signature); convertType handles that as "?".
	returnTypeStr := info.ReturnType
	mappedReturnType, _ := convertType(returnTypeStr, enumsMap, typedefsMap)
	retType := RetType{Type: mappedReturnType}

	baseReturnType := stripTypeQualifiers(returnTypeStr)
	if _, ok := enumsMap[baseReturnType]; ok {
		if es := buildEnumStructure(baseReturnType, enumsMap); es != nil {
			retType.Enum = es
		}
	} else if td, ok := typedefsMap[baseReturnType]; ok && td.IsFunctionPointer {
		retType.Type = "function"
		if p := buildFunctionPrototype(baseReturnType, typedefsMap, enumsMap); p != nil {
			retType.Prototype = p
		}
	}
	proto.RetType = retType

	return proto
}
