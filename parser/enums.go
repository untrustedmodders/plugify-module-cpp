package main

import "strconv"

// EnumValue is a single enum member, also used directly as JSON output.
type EnumValue struct {
	Name        string      `json:"name"`
	Value       interface{} `json:"value"`
	Description string      `json:"description,omitempty"`
}

// EnumInfo holds the parsed structure of an enum.
type EnumInfo struct {
	BaseType    string
	USR         string
	Name        string
	Description string
	Values      []EnumValue
}

// EnumStruct is the enum structure embedded into a parameter/return type in the output JSON.
type EnumStruct struct {
	Name        string      `json:"name"`
	Description string      `json:"description,omitempty"`
	Values      []EnumValue `json:"values,omitempty"`
}

// sentinelNames are enum member names filtered out of the output by default.
var sentinelNames = map[string]bool{
	"Count": true, "MAX": true, "Max": true,
	"INVALID": true, "Invalid": true, "NUM": true, "Num": true,
}

// normalizeEnumValue mirrors Python's `try: int(member_value) except (ValueError, TypeError): pass`.
func normalizeEnumValue(raw interface{}) interface{} {
	switch v := raw.(type) {
	case nil:
		return nil
	case string:
		if iv, err := strconv.ParseInt(v, 10, 64); err == nil {
			return iv
		}
		return v
	default:
		return v
	}
}

// buildEnumsMap builds a map of enum names to their base types and full structure.
func buildEnumsMap(yamlData map[string]interface{}) map[string]EnumInfo {
	enumsMap := map[string]EnumInfo{}

	childEnums := asSlice(yamlData["ChildEnums"])
	for _, enum := range childEnums {
		em := asMap(enum)
		if em == nil {
			continue
		}

		enumName := getStr(em, "Name")
		if enumName == "" {
			continue
		}

		baseTypeInfo := asMap(em["BaseType"])
		baseTypeTypeMap := asMap(baseTypeInfo["Type"])
		baseType := getStrDefault(baseTypeTypeMap, "Name", "int32")

		enumDescription := extractEnumDescription(asSlice(em["Description"]))

		var enumValues []EnumValue
		members := asSlice(em["Members"])
		for _, member := range members {
			mm := asMap(member)
			memberName := getStr(mm, "Name")
			memberValue := normalizeEnumValue(mm["Value"])
			memberDesc := extractTextFromDescription(mm["Description"])

			valueEntry := EnumValue{Name: memberName, Value: memberValue, Description: memberDesc}
			enumValues = append(enumValues, valueEntry)
		}

		enumsMap[enumName] = EnumInfo{
			BaseType:    mapType(baseType),
			USR:         getStr(em, "USR"),
			Name:        enumName,
			Description: enumDescription,
			Values:      enumValues,
		}
	}

	return enumsMap
}

// buildEnumStructure builds an enum structure for inclusion in a parameter/return type,
// filtering out sentinel values.
func buildEnumStructure(enumName string, enumsMap map[string]EnumInfo) *EnumStruct {
	info, ok := enumsMap[enumName]
	if !ok {
		return nil
	}

	es := &EnumStruct{Name: info.Name, Description: info.Description}

	var values []EnumValue
	for _, v := range info.Values {
		if v.Name != "" && !sentinelNames[v.Name] {
			values = append(values, EnumValue{Name: v.Name, Value: v.Value, Description: v.Description})
		}
	}
	es.Values = values

	return es
}
