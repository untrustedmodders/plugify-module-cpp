package main

// asMap safely asserts v as a YAML-decoded mapping.
func asMap(v interface{}) map[string]interface{} {
	if v == nil {
		return nil
	}
	m, _ := v.(map[string]interface{})
	return m
}

// asSlice safely asserts v as a YAML-decoded sequence.
func asSlice(v interface{}) []interface{} {
	if v == nil {
		return nil
	}
	s, _ := v.([]interface{})
	return s
}

// getStr returns m[key] as a string, or "" if missing/not a string.
func getStr(m map[string]interface{}, key string) string {
	if m == nil {
		return ""
	}
	if v, ok := m[key]; ok && v != nil {
		if s, ok2 := v.(string); ok2 {
			return s
		}
	}
	return ""
}

// getStrDefault returns m[key] as a string, or def if the key is absent.
// Mirrors Python's dict.get(key, default) semantics (default only applies when the key is missing).
func getStrDefault(m map[string]interface{}, key, def string) string {
	if m == nil {
		return def
	}
	v, ok := m[key]
	if !ok {
		return def
	}
	if s, ok2 := v.(string); ok2 {
		return s
	}
	return def
}
