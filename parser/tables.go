package main

import (
	"errors"
	"fmt"
	"sort"
	"strings"
)

// typeTables collects the prototypes and enums met while processing functions,
// so each is described once and named from every use site. A callback taken by
// twenty functions is written once rather than twenty times.
//
// C++ types in different namespaces can share a short name, and a name is what a
// reference resolves on, so a clash is recorded rather than letting one
// definition silently stand in for the other.
type typeTables struct {
	prototypes map[string]*PrototypeStruct
	enums      map[string]*EnumStruct
	clashes    []string
}

func newTypeTables() *typeTables {
	return &typeTables{
		prototypes: map[string]*PrototypeStruct{},
		enums:      map[string]*EnumStruct{},
	}
}

// addPrototype files a signature and returns the name to refer to it by.
func (t *typeTables) addPrototype(prototype *PrototypeStruct) string {
	if prototype == nil || prototype.Name == "" {
		return ""
	}

	existing, found := t.prototypes[prototype.Name]
	if !found {
		t.prototypes[prototype.Name] = prototype
	} else if !samePrototype(existing, prototype) {
		t.clash("prototype", prototype.Name)
	}

	return prototype.Name
}

// addEnum files an enumeration and returns the name to refer to it by.
func (t *typeTables) addEnum(enum *EnumStruct) string {
	if enum == nil || enum.Name == "" {
		return ""
	}

	existing, found := t.enums[enum.Name]
	if !found {
		t.enums[enum.Name] = enum
	} else if !sameEnum(existing, enum) {
		t.clash("enum", enum.Name)
	}

	return enum.Name
}

func (t *typeTables) clash(kind, name string) {
	clash := fmt.Sprintf("%s %q", kind, name)
	for _, seen := range t.clashes {
		if seen == clash {
			return
		}
	}
	t.clashes = append(t.clashes, clash)
}

// err reports the name clashes found while processing, if any.
func (t *typeTables) err() error {
	if len(t.clashes) == 0 {
		return nil
	}
	sort.Strings(t.clashes)
	return fmt.Errorf(
		"conflicting definitions share a name, so a reference to one would be ambiguous: %s",
		strings.Join(t.clashes, ", "))
}

func (t *typeTables) sortedPrototypes() []*PrototypeStruct {
	if len(t.prototypes) == 0 {
		return nil
	}
	out := make([]*PrototypeStruct, 0, len(t.prototypes))
	for _, p := range t.prototypes {
		out = append(out, p)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].Name < out[j].Name })
	return out
}

func (t *typeTables) sortedEnums() []*EnumStruct {
	if len(t.enums) == 0 {
		return nil
	}
	out := make([]*EnumStruct, 0, len(t.enums))
	for _, e := range t.enums {
		out = append(out, e)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].Name < out[j].Name })
	return out
}

// Definitions are compared on the parts that make up the type. Descriptions are
// left out: they mean nothing to a caller, and two spellings of the same type
// that differ only in wording are not a clash.

func sameParam(a, b *ParamType) bool {
	return a.Type == b.Type && a.Ref == b.Ref &&
		a.Prototype == b.Prototype && a.Enum == b.Enum
}

func sameRetType(a, b *RetType) bool {
	return a.Type == b.Type && a.Prototype == b.Prototype && a.Enum == b.Enum
}

func sameEnum(a, b *EnumStruct) bool {
	if len(a.Values) != len(b.Values) {
		return false
	}
	for i := range a.Values {
		if a.Values[i].Name != b.Values[i].Name || a.Values[i].Value != b.Values[i].Value {
			return false
		}
	}
	return true
}

func samePrototype(a, b *PrototypeStruct) bool {
	if len(a.ParamTypes) != len(b.ParamTypes) {
		return false
	}
	if !sameRetType(&a.RetType, &b.RetType) {
		return false
	}
	for i := range a.ParamTypes {
		if !sameParam(&a.ParamTypes[i], &b.ParamTypes[i]) {
			return false
		}
	}
	return true
}

// duplicateExports reports an exported name or symbol used more than once.
// Plugify refuses such a manifest at load, but naming them here puts the problem
// next to the header that declared it.
func duplicateExports(functions []MethodStruct) error {
	var problems []string
	seenName := make(map[string]bool, len(functions))
	seenSymbol := make(map[string]bool, len(functions))

	for _, f := range functions {
		if seenName[f.Name] {
			problems = append(problems, fmt.Sprintf("method %q is exported more than once", f.Name))
		}
		seenName[f.Name] = true

		if seenSymbol[f.FuncName] {
			problems = append(problems, fmt.Sprintf("symbol %q is exported more than once", f.FuncName))
		}
		seenSymbol[f.FuncName] = true
	}

	if len(problems) == 0 {
		return nil
	}

	sort.Strings(problems)
	return errors.New(strings.Join(problems, "; "))
}
