package main

import "strings"

// extractTextFromDescription extracts text content from clang-doc's structured
// description format, handling nested Children structures.
func extractTextFromDescription(description interface{}) string {
	if description == nil {
		return ""
	}

	var texts []string

	var traverse func(node interface{})
	traverse = func(node interface{}) {
		switch n := node.(type) {
		case map[string]interface{}:
			if textVal, ok := n["Text"]; ok {
				if s, ok2 := textVal.(string); ok2 {
					s = strings.TrimSpace(s)
					if s != "" {
						texts = append(texts, s)
					}
				}
			}
			if children, ok := n["Children"]; ok {
				if cs, ok2 := children.([]interface{}); ok2 {
					for _, c := range cs {
						traverse(c)
					}
				}
			}
		case []interface{}:
			for _, item := range n {
				traverse(item)
			}
		}
	}

	traverse(description)
	return strings.Join(texts, " ")
}

// findFullCommentChildren returns the Children of the first FullComment entry
// in description, falling back to description itself if that yields nothing
// (matches Python's "children_to_search = children_to_search or description").
func findFullCommentChildren(description []interface{}) []interface{} {
	var childrenToSearch []interface{}
	for _, item := range description {
		m := asMap(item)
		if m != nil && getStr(m, "Kind") == "FullComment" {
			childrenToSearch = asSlice(m["Children"])
			break
		}
	}
	if len(childrenToSearch) == 0 {
		childrenToSearch = description
	}
	return childrenToSearch
}

// extractBriefDescription extracts the brief description from a function's Description field.
func extractBriefDescription(description []interface{}) string {
	if len(description) == 0 {
		return ""
	}

	// Handle FullComment wrapper
	for _, item := range description {
		m := asMap(item)
		if m != nil && getStr(m, "Kind") == "FullComment" {
			children := asSlice(m["Children"])
			for _, child := range children {
				cm := asMap(child)
				if cm != nil && getStr(cm, "Kind") == "BlockCommandComment" && getStr(cm, "Name") == "brief" {
					return extractTextFromDescription(cm["Children"])
				}
			}
		}
	}

	// Fallback: look directly for BlockCommandComment
	for _, item := range description {
		m := asMap(item)
		if m != nil && getStr(m, "Kind") == "BlockCommandComment" && getStr(m, "Name") == "brief" {
			return extractTextFromDescription(m["Children"])
		}
	}

	return ""
}

// extractParamDescriptions extracts parameter descriptions from a function's Description field.
func extractParamDescriptions(description []interface{}) map[string]string {
	result := map[string]string{}
	if len(description) == 0 {
		return result
	}

	childrenToSearch := findFullCommentChildren(description)

	for _, item := range childrenToSearch {
		m := asMap(item)
		if m != nil && getStr(m, "Kind") == "ParamCommandComment" {
			paramName := getStr(m, "ParamName")
			if paramName != "" {
				descText := extractTextFromDescription(m["Children"])
				if descText != "" {
					result[paramName] = descText
				}
			}
		}
	}

	return result
}

// extractReturnDescription extracts the return description from a function's Description field.
func extractReturnDescription(description []interface{}) string {
	if len(description) == 0 {
		return ""
	}

	childrenToSearch := findFullCommentChildren(description)

	for _, item := range childrenToSearch {
		m := asMap(item)
		if m != nil && getStr(m, "Kind") == "BlockCommandComment" && getStr(m, "Name") == "return" {
			return extractTextFromDescription(m["Children"])
		}
	}

	return ""
}

// extractEnumDescription extracts an enum description from a Description field.
func extractEnumDescription(description []interface{}) string {
	if len(description) == 0 {
		return ""
	}

	childrenToSearch := findFullCommentChildren(description)

	for _, item := range childrenToSearch {
		m := asMap(item)
		if m == nil {
			continue
		}
		kind := getStr(m, "Kind")
		if kind == "BlockCommandComment" && getStr(m, "Name") == "brief" {
			return extractTextFromDescription(m["Children"])
		} else if kind == "ParagraphComment" {
			text := extractTextFromDescription(m["Children"])
			if text != "" {
				return text
			}
		}
	}

	return ""
}
