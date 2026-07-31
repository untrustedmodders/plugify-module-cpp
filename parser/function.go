package main

import (
	"path/filepath"
	"strings"
)

// Param is a function/prototype parameter in the output JSON.
type Param struct {
	Name        string             `json:"name"`
	Type        string             `json:"type"`
	Ref         bool               `json:"ref"`
	Description string             `json:"description,omitempty"`
	Enum        *EnumStruct        `json:"enum,omitempty"`
	Prototype   *FunctionPrototype `json:"prototype,omitempty"`
}

// RetType is a function/prototype return type in the output JSON.
type RetType struct {
	Type        string             `json:"type"`
	Description string             `json:"description,omitempty"`
	Enum        *EnumStruct        `json:"enum,omitempty"`
	Prototype   *FunctionPrototype `json:"prototype,omitempty"`
}

// FunctionPrototype is the signature of a function-pointer typedef, embedded
// into a Param or RetType.
type FunctionPrototype struct {
	Name        string  `json:"name"`
	FuncName    string  `json:"funcName"`
	Description string  `json:"description,omitempty"`
	ParamTypes  []Param `json:"paramTypes"`
	RetType     RetType `json:"retType"`
}

// FunctionData is a top-level exported function entry in the output JSON.
type FunctionData struct {
	Name        string  `json:"name"`
	FuncName    string  `json:"funcName"`
	ParamTypes  []Param `json:"paramTypes"`
	RetType     RetType `json:"retType"`
	Group       string  `json:"group,omitempty"`
	Description string  `json:"description,omitempty"`
}

// deriveGroupName mirrors os.path.splitext(os.path.basename(filename))[0].lower().capitalize().
func deriveGroupName(filename string) string {
	base := filepath.Base(filename)
	base = strings.TrimSuffix(base, filepath.Ext(base))
	lower := strings.ToLower(base)
	if lower == "" {
		return ""
	}
	return strings.ToUpper(lower[:1]) + lower[1:]
}

// processFunction processes a single function and converts it to the desired JSON format.
func processFunction(function map[string]interface{}, enumsMap map[string]EnumInfo, typedefsMap map[string]TypedefInfo, groupName string) FunctionData {
	funcName := getStrDefault(function, "Name", "Unknown")

	defLocation := asMap(function["DefLocation"])
	filename := getStr(defLocation, "Filename")

	if groupName == "" && filename != "" {
		groupName = deriveGroupName(filename)
	}

	// Extract descriptions - handle both list and dict formats.
	var description []interface{}
	switch d := function["Description"].(type) {
	case map[string]interface{}:
		description = asSlice(d["Children"])
	case []interface{}:
		description = d
	}

	briefDesc := extractBriefDescription(description)
	paramDescriptions := extractParamDescriptions(description)
	returnDesc := extractReturnDescription(description)

	// Process parameters.
	params := asSlice(function["Params"])
	paramTypes := make([]Param, 0, len(params))

	for _, p := range params {
		pm := asMap(p)
		paramTypeInfo := asMap(pm["Type"])
		paramTypeName := getStr(paramTypeInfo, "QualName")
		if paramTypeName == "" {
			paramTypeName = getStrDefault(paramTypeInfo, "Name", "?")
		}
		paramName := getStrDefault(pm, "Name", "unknown")

		mappedType, isRef := convertType(paramTypeName, enumsMap, typedefsMap)
		baseTypeName := stripTypeQualifiers(paramTypeName)

		paramData := Param{Name: paramName, Type: mappedType, Ref: isRef}

		if desc, ok := paramDescriptions[paramName]; ok {
			paramData.Description = desc
		}

		if _, ok := enumsMap[baseTypeName]; ok {
			if es := buildEnumStructure(baseTypeName, enumsMap); es != nil {
				paramData.Enum = es
			}
		} else if td, ok := typedefsMap[baseTypeName]; ok && td.IsFunctionPointer {
			paramData.Type = "function"
			if proto := buildFunctionPrototype(baseTypeName, typedefsMap, enumsMap); proto != nil {
				paramData.Prototype = proto
			}
		}

		paramTypes = append(paramTypes, paramData)
	}

	// Process return type.
	returnTypeInfo := asMap(asMap(function["ReturnType"])["Type"])
	returnTypeName := getStr(returnTypeInfo, "QualName")
	if returnTypeName == "" {
		returnTypeName = getStrDefault(returnTypeInfo, "Name", "void")
	}
	mappedReturnType, _ := convertType(returnTypeName, enumsMap, typedefsMap)

	retType := RetType{Type: mappedReturnType}
	if returnDesc != "" {
		retType.Description = returnDesc
	}

	baseReturnType := stripTypeQualifiers(returnTypeName)
	if _, ok := enumsMap[baseReturnType]; ok {
		if es := buildEnumStructure(baseReturnType, enumsMap); es != nil {
			retType.Enum = es
		}
	} else if td, ok := typedefsMap[baseReturnType]; ok && td.IsFunctionPointer {
		retType.Type = "function"
		if proto := buildFunctionPrototype(baseReturnType, typedefsMap, enumsMap); proto != nil {
			retType.Prototype = proto
		}
	}

	functionData := FunctionData{
		Name:       funcName,
		FuncName:   funcName,
		ParamTypes: paramTypes,
		RetType:    retType,
	}

	if groupName != "" {
		functionData.Group = groupName
	}
	if briefDesc != "" {
		functionData.Description = briefDesc
	}

	return functionData
}
