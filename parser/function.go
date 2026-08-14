package main

import (
	"path/filepath"
	"strings"
)

// ParamType is a function/prototype parameter in the output JSON.
//
// Enum and Prototype name an entry in the output's shared tables rather than
// carrying the definition, so a type used by many functions is described once.
// AliasStruct stays inline: it renames a type at one use site rather than describing
// a type others can share.
type ParamType struct {
	Name        string       `json:"name"`
	Type        string       `json:"type"`
	Ref         bool         `json:"ref"`
	Description string       `json:"description,omitempty"`
	Enum        string       `json:"enum,omitempty"`
	Alias       *AliasStruct `json:"alias,omitempty"`
	Prototype   string       `json:"prototype,omitempty"`
}

// RetType is a function/prototype return type in the output JSON.
type RetType struct {
	Type        string       `json:"type"`
	Description string       `json:"description,omitempty"`
	Enum        string       `json:"enum,omitempty"`
	Alias       *AliasStruct `json:"alias,omitempty"`
	Prototype   string       `json:"prototype,omitempty"`
}

// Prototype is the signature of a function-pointer typedef, embedded
// into a ParamType or RetType.
type Prototype struct {
	Name        string      `json:"name"`
	FuncName    string      `json:"funcName"`
	Description string      `json:"description,omitempty"`
	ParamTypes  []ParamType `json:"paramTypes"`
	RetType     RetType     `json:"retType"`
}

// Method is a top-level exported function entry in the output JSON.
type Method struct {
	Name        string      `json:"name"`
	FuncName    string      `json:"funcName"`
	ParamTypes  []ParamType `json:"paramTypes"`
	RetType     RetType     `json:"retType"`
	Group       string      `json:"group,omitempty"`
	Description string      `json:"description,omitempty"`
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
func processFunction(function map[string]interface{}, enumsMap map[string]EnumInfo, typedefsMap map[string]TypedefInfo, groupName string, tables *typeTables) Method {
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
	paramTypes := make([]ParamType, 0, len(params))

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

		paramData := ParamType{Name: paramName, Type: mappedType, Ref: isRef}

		paramData.Description = paramDescriptions[paramName]

		if _, ok := enumsMap[baseTypeName]; ok {
			paramData.Enum = tables.addEnum(buildEnumStructure(baseTypeName, enumsMap))
		} else if td, ok := typedefsMap[baseTypeName]; ok {
			if td.IsFunctionPointer {
				paramData.Type = "function"
				paramData.Prototype = tables.addPrototype(buildPrototype(baseTypeName, typedefsMap, enumsMap, tables))
			} else if alias := buildAliasStructure(baseTypeName, typedefsMap); alias != nil {
				paramData.Alias = alias
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

	retType := RetType{Type: mappedReturnType, Description: returnDesc}

	baseReturnType := stripTypeQualifiers(returnTypeName)
	if _, ok := enumsMap[baseReturnType]; ok {
		retType.Enum = tables.addEnum(buildEnumStructure(baseReturnType, enumsMap))
	} else if td, ok := typedefsMap[baseReturnType]; ok {
		if td.IsFunctionPointer {
			retType.Type = "function"
			retType.Prototype = tables.addPrototype(buildPrototype(baseReturnType, typedefsMap, enumsMap, tables))
		} else if alias := buildAliasStructure(baseReturnType, typedefsMap); alias != nil {
			retType.Alias = alias
		}
	}

	return Method{
		Name:        funcName,
		FuncName:    funcName,
		ParamTypes:  paramTypes,
		RetType:     retType,
		Group:       groupName,
		Description: briefDesc,
	}
}

// Output is the document this tool writes: the exported functions, plus the
// prototype and enum tables they refer to by name. Merged into a .pplugin by
// whatever assembles the manifest.
type Output struct {
	Methods    []Method      `json:"methods"`
	Prototypes []*Prototype  `json:"prototypes,omitempty"`
	Enums      []*EnumStruct `json:"enums,omitempty"`
}
