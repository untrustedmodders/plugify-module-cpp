// Command parser parses clang-doc's YAML output and generates JSON for exported functions.
// It is a Go port of parser.py, kept for reference in this directory.
package main

import (
	"encoding/json"
	"errors"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"gopkg.in/yaml.v3"
)

func usage() {
	fmt.Fprintln(os.Stderr, `Parse clang-doc YAML output and generate JSON for exported functions

Usage:
  parser [options] <input_path> <output_file>

Arguments:
  input_path            Path to YAML file or directory containing YAML files
  output_file            JSON file to output the processed results

Options:
  -n, --name-filter <s>  Filter functions by name (case-insensitive substring match)
  -f, --file-filter <s>  Filter functions by source path prefix
  -h, --help              Show this help message`)
}

// parseArgs parses CLI arguments argparse-style: positional args and flags may
// appear in any order, and both long (--name-filter) and short (-n) forms are accepted.
func parseArgs(argv []string) (inputPath, outputFile, nameFilter, fileFilter string, err error) {
	var positional []string

	takeValue := func(i *int, flagName string) (string, error) {
		if *i+1 >= len(argv) {
			return "", fmt.Errorf("argument %s: expected one argument", flagName)
		}
		*i++
		return argv[*i], nil
	}

	for i := 0; i < len(argv); i++ {
		arg := argv[i]
		switch {
		case arg == "-h" || arg == "--help":
			usage()
			os.Exit(0)
		case arg == "--name-filter" || arg == "-n":
			v, e := takeValue(&i, arg)
			if e != nil {
				return "", "", "", "", e
			}
			nameFilter = v
		case strings.HasPrefix(arg, "--name-filter="):
			nameFilter = strings.TrimPrefix(arg, "--name-filter=")
		case arg == "--file-filter" || arg == "-f":
			v, e := takeValue(&i, arg)
			if e != nil {
				return "", "", "", "", e
			}
			fileFilter = v
		case strings.HasPrefix(arg, "--file-filter="):
			fileFilter = strings.TrimPrefix(arg, "--file-filter=")
		default:
			positional = append(positional, arg)
		}
	}

	if len(positional) < 2 {
		return "", "", "", "", fmt.Errorf("the following arguments are required: input_path, output_file")
	}
	if len(positional) > 2 {
		return "", "", "", "", fmt.Errorf("unrecognized arguments: %s", strings.Join(positional[2:], " "))
	}

	return positional[0], positional[1], nameFilter, fileFilter, nil
}

// processYamlFile processes a single YAML file and extracts functions.
func processYamlFile(yamlFile, nameFilter, fileFilter string, tables *typeTables) ([]MethodStruct, error) {
	raw, err := os.ReadFile(yamlFile)
	if err != nil {
		return nil, err
	}

	var yamlData map[string]interface{}
	if err := yaml.Unmarshal(raw, &yamlData); err != nil {
		return nil, fmt.Errorf("parsing %s: %w", yamlFile, err)
	}
	if yamlData == nil {
		return nil, nil
	}

	// Build lookup maps - enums first, then typedefs (which may reference enums).
	enumsMap := buildEnumsMap(yamlData)
	typedefsMap := buildTypedefsMap(yamlData)

	var methods []MethodStruct

	childFunctions := asSlice(yamlData["ChildFunctions"])
	for _, fn := range childFunctions {
		fm := asMap(fn)
		if fm == nil {
			continue
		}

		funcName := getStr(fm, "Name")
		defLocation := asMap(fm["DefLocation"])
		fileName := getStr(defLocation, "Filename")

		if nameFilter != "" && !strings.Contains(strings.ToLower(funcName), strings.ToLower(nameFilter)) {
			continue
		}
		if fileFilter != "" && !strings.Contains(strings.ToLower(fileName), strings.ToLower(fileFilter)) {
			continue
		}

		method := processMethodStruct(fm, enumsMap, typedefsMap, "", tables)
		methods = append(methods, method)
		fmt.Printf("Processed: %s\n", funcName)
	}

	return methods, nil
}

func run(inputPath, outputFile, nameFilter, fileFilter string) error {
	info, err := os.Stat(inputPath)
	if err != nil {
		return fmt.Errorf("%s is neither a file nor a directory", inputPath)
	}

	// One set of tables across every file, so a type used by several headers is
	// described once rather than once per header.
	tables := newTypeTables()

	var allMethods []MethodStruct

	if info.IsDir() {
		matches, err := filepath.Glob(filepath.Join(inputPath, "*.yaml"))
		if err != nil {
			return err
		}
		sort.Strings(matches)

		for _, yamlFile := range matches {
			fmt.Printf("\nProcessing: %s\n", yamlFile)
			methods, err := processYamlFile(yamlFile, nameFilter, fileFilter, tables)
			if err != nil {
				return err
			}
			allMethods = append(allMethods, methods...)
		}
	} else {
		methods, err := processYamlFile(inputPath, nameFilter, fileFilter, tables)
		if err != nil {
			return err
		}
		allMethods = methods
	}

	if allMethods == nil {
		allMethods = []MethodStruct{}
	}

	if err := errors.Join(tables.err(), duplicateExports(allMethods)); err != nil {
		return err
	}

	// Sorted by name so the output reads the same however the headers are
	// arranged, and so re-running over a reordered doc set produces no diff.
	sort.Slice(allMethods, func(i, j int) bool { return allMethods[i].Name < allMethods[j].Name })

	output := Output{
		Methods:    allMethods,
		Prototypes: tables.sortedPrototypes(),
		Enums:      tables.sortedEnums(),
	}

	data, err := json.MarshalIndent(output, "", "    ")
	if err != nil {
		return err
	}
	if err := os.WriteFile(outputFile, data, 0644); err != nil {
		return err
	}

	fmt.Printf("\nTotal functions exported: %d (%d prototypes, %d enums)\n",
		len(allMethods), len(output.Prototypes), len(output.Enums))
	fmt.Printf("Output written to: %s\n", outputFile)

	return nil
}

func main() {
	inputPath, outputFile, nameFilter, fileFilter, err := parseArgs(os.Args[1:])
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error:", err)
		usage()
		os.Exit(2)
	}

	if err := run(inputPath, outputFile, nameFilter, fileFilter); err != nil {
		fmt.Fprintln(os.Stderr, "Error:", err)
		os.Exit(1)
	}
}
