package main

import "strings"

// convertType converts a type string into its mapped type and reference flag.
// Returns (mappedType, isReference), mirroring parser.py's convert_type().
func convertType(typeStr string, enumsMap map[string]EnumInfo, typedefsMap map[string]TypedefInfo) (string, bool) {
	return convertTypeSeen(typeStr, enumsMap, typedefsMap, map[string]bool{})
}

func convertTypeSeen(typeStr string, enumsMap map[string]EnumInfo, typedefsMap map[string]TypedefInfo, seen map[string]bool) (string, bool) {
	if typeStr == "" {
		return "?", false
	}

	constFlag := false
	t := strings.TrimSpace(typeStr)

	// Remove const qualifier
	if strings.HasPrefix(t, "const ") {
		t = t[len("const "):]
		constFlag = true
	}

	// Handle pointers
	if strings.HasSuffix(t, "*") {
		return "ptr64", false
	}

	// Handle references
	if strings.HasSuffix(t, "&") {
		baseType := strings.TrimSpace(t[:len(t)-1])
		if strings.HasPrefix(baseType, "const ") {
			baseType = strings.TrimSpace(baseType[len("const "):])
			constFlag = true
		}

		// Check if it's an enum
		if info, ok := enumsMap[baseType]; ok {
			mapped := info.BaseType
			if mapped == "" {
				mapped = "?"
			}
			return mapped, !constFlag
		}

		// Check if it's a (non-function-pointer) typedef; resolve to its underlying type
		if mapped, ok := resolveTypedefBase(baseType, enumsMap, typedefsMap, seen); ok {
			return mapped, !constFlag
		}

		return mapType(baseType), !constFlag
	}

	// Check if it's an enum
	if info, ok := enumsMap[t]; ok {
		mapped := info.BaseType
		if mapped == "" {
			mapped = "?"
		}
		return mapped, false
	}

	// Check if it's a (non-function-pointer) typedef; resolve to its underlying type
	if mapped, ok := resolveTypedefBase(t, enumsMap, typedefsMap, seen); ok {
		return mapped, false
	}

	return mapType(t), false
}

// resolveTypedefBase resolves t as a plain (non-function-pointer) typedef name to
// its underlying mapped type, following typedef chains recursively. Function-pointer
// typedefs are left alone here - callers handle those separately by emitting a
// "function" type with a prototype. ok is false when t is not such a typedef.
func resolveTypedefBase(t string, enumsMap map[string]EnumInfo, typedefsMap map[string]TypedefInfo, seen map[string]bool) (string, bool) {
	td, ok := typedefsMap[t]
	if !ok || td.IsFunctionPointer {
		return "", false
	}
	if seen[t] {
		return "?", true
	}
	seen[t] = true
	mapped, _ := convertTypeSeen(td.Underlying, enumsMap, typedefsMap, seen)
	return mapped, true
}

// stripTypeQualifiers strips const/&/* substrings from a type name, mirroring
// param_type_name.replace('const', ”).replace('&', ”).replace('*', ”).strip().
func stripTypeQualifiers(s string) string {
	s = strings.ReplaceAll(s, "const", "")
	s = strings.ReplaceAll(s, "&", "")
	s = strings.ReplaceAll(s, "*", "")
	return strings.TrimSpace(s)
}
