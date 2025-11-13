# Clang-Doc YAML to JSON Parser

A Python script that parses clang-doc's YAML output and converts it into a structured JSON format suitable for the Plugify project.

## Overview

This script replaces the previous parser that used cxxheaderparser to directly parse C++ files with Doxygen comments. The new approach leverages clang-doc's YAML output, which provides more accurate and complete information about functions, enums, and typedefs.

## Features

- **Parses clang-doc YAML output**: Extracts function signatures, parameters, return types, and documentation
- **Type mapping**: Converts C++ types to simplified user-friendly types (e.g., `plg::string` → `string`)
- **Enum handling**: Automatically resolves enum types to their base types
- **Enum structure generation**: Includes full enum definitions with values and descriptions
- **Function typedef parsing**: Parses function pointer typedefs and generates complete prototypes
- **Nested enum support**: Handles enums within function prototypes
- **Typedef support**: Identifies and marks typedef parameters
- **Description extraction**: Extracts Doxygen/brief descriptions, parameter descriptions, and return descriptions
- **Filtering**: Filter functions by name or source file prefix
- **Batch processing**: Process single YAML files or entire directories

## Requirements

- Python 3.6+
- PyYAML

Install dependencies:
```bash
pip install pyyaml
```

## Usage

### Basic Usage

```bash
python3 clang_doc_parser.py <input_path> <output_file>
```

**Arguments:**
- `input_path`: Path to a YAML file or directory containing YAML files
- `output_file`: Path to the output JSON file

### Examples

1. **Process a single YAML file:**
   ```bash
   python3 clang_doc_parser.py index.yaml output.json
   ```

2. **Process all YAML files in a directory:**
   ```bash
   python3 clang_doc_parser.py ./docs output.json
   ```

3. **Filter by function name:**
   ```bash
   python3 clang_doc_parser.py index.yaml output.json --name-filter "Command"
   ```
   This will only include functions with "Command" in their name.

4. **Filter by source file prefix:**
   ```bash
   python3 clang_doc_parser.py index.yaml output.json --file-filter "commands"
   ```
   This will only include functions from files starting with "commands" (e.g., `commands.cpp`).

5. **Combine filters:**
   ```bash
   python3 clang_doc_parser.py index.yaml output.json --name-filter "Add" --file-filter "commands"
   ```

### Command-Line Options

- `--name-filter` / `-n`: Filter functions by name (case-insensitive substring match)
- `--file-filter` / `-f`: Filter functions by source filename prefix
- `--help` / `-h`: Show help message

## Integration with CMake

To integrate clang-doc into your CMake project:

```cmake
find_program(CLANG_DOC clang-doc)
if(CLANG_DOC)
    add_custom_target(docs
        COMMAND ${CLANG_DOC}
            --executor=all-TUs
            -p ${CMAKE_CURRENT_BINARY_DIR}
            --output=${CMAKE_CURRENT_SOURCE_DIR}/docs
            --extra-arg=-Wno-error
            --format=yaml
            ${CMAKE_SOURCE_DIR}/src/*.cpp
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating documentation with clang-doc"
    )
endif()
```

Then run:
```bash
cmake --build . --target docs
python3 clang_doc_parser.py docs/index.yaml exported_functions.json
```

## Output Format

The script generates JSON with comprehensive type information including enum structures and function prototypes.

### Basic Function Example

```json
{
    "name": "AddAdminCommand",
    "group": "Commands",
    "description": "Creates a console command as an administrative command.",
    "funcName": "AddAdminCommand",
    "paramTypes": [
        {
            "name": "name",
            "type": "string",
            "ref": false,
            "description": "The name of the console command."
        }
    ],
    "retType": {
        "type": "bool",
        "description": "A boolean indicating whether the command was successfully added."
    }
}
```

### Parameter with Enum Structure

When a parameter uses an enum type, the full enum definition is included:

```json
{
    "name": "mode",
    "type": "uint8",
    "ref": false,
    "description": "Whether the hook was in post mode (after processing) or pre mode (before processing).",
    "enum": {
        "name": "HookMode",
        "description": "Enum representing the type of callback.",
        "values": [
            {
                "name": "Pre",
                "value": 0,
                "description": "Callback will be executed before the original function"
            },
            {
                "name": "Post",
                "value": 1,
                "description": "Callback will be executed after the original function"
            }
        ]
    }
}
```

### Parameter with Function Prototype

When a parameter is a function pointer typedef, the complete function signature is included:

```json
{
    "name": "callback",
    "type": "function",
    "ref": false,
    "description": "A callback function that is invoked when the command is executed.",
    "prototype": {
        "name": "CommandCallback",
        "funcName": "CommandCallback",
        "description": "Handles the execution of a command triggered by a caller.",
        "paramTypes": [
            {
                "name": "param1",
                "type": "int32",
                "ref": false
            },
            {
                "name": "param2",
                "type": "int32",
                "ref": false,
                "enum": {
                    "name": "CommandCallingContext",
                    "description": "The command execution context.",
                    "values": [
                        {
                            "name": "Console",
                            "value": 0,
                            "description": "The command execute from the client's console."
                        }
                    ]
                }
            }
        ],
        "retType": {
            "type": "int32",
            "enum": {
                "name": "ResultType",
                "description": "Enum representing the possible results of an operation.",
                "values": [...]
            }
        }
    }
}
```

### Field Descriptions

- `name`: Function name
- `group`: Derived from the source filename (e.g., "Commands" from `commands.cpp`)
- `description`: Brief description from Doxygen comments
- `funcName`: Function name (same as `name`)
- `paramTypes`: Array of parameter objects:
  - `name`: Parameter name
  - `type`: Mapped type (e.g., "string", "int32", "vec3[]", "function")
  - `ref`: Boolean indicating if it's a reference parameter
  - `description`: Parameter description from Doxygen comments (if available)
  - `enum`: (Optional) Full enum structure if parameter is an enum type
  - `prototype`: (Optional) Full function signature if parameter is a function pointer typedef
- `retType`: Return type object:
  - `type`: Mapped return type
  - `description`: Return description from Doxygen comments (if available)
  - `enum`: (Optional) Full enum structure if return type is an enum

## Advanced Features

### Enum Structure Generation

The parser automatically detects enum types and includes their complete definition:
- Enum name and description
- All enum values with their numeric values
- Per-value descriptions (if documented)
- Automatically filters out sentinel values like "Count", "MAX", "INVALID"

### Function Pointer Typedef Parsing

The parser can parse function pointer typedefs from their underlying signature:
- Extracts return type and parameter types
- Recursively processes parameter types (including nested enums)
- Generates parameter names (param1, param2, etc.)
- Includes full function description from typedef documentation

**Note**: Parameter names in function prototypes are auto-generated as `param1`, `param2`, etc. To include meaningful parameter names and descriptions, you'll need to add them manually or extend the parser to read from additional documentation sources.

### Nested Enum Support

Enums can appear at multiple levels:
- Function parameters
- Function return types
- Function prototype parameters (within typedef)
- Function prototype return types (within typedef)

All enum references include the complete enum structure with values and descriptions.

## Type Mapping

The script maps C++ types to simplified types:

| C++ Type | Mapped Type |
|----------|-------------|
| `plg::string`, `const plg::string &` | `string` |
| `plg::vector<plg::string>` | `string[]` |
| `int`, `int32_t`, `long` | `int32` |
| `int64_t`, `long long` | `int64` |
| `bool` | `bool` |
| `float` | `float` |
| `double` | `double` |
| `void*` | `ptr64` |
| `plg::vector<int>` | `int32[]` |
| `Vector`, `QAngle`, `plg::vec3` | `vec3` |
| Enums | Base type (e.g., `uint8`, `int32`) + enum structure |
| Function pointer typedefs | `function` + prototype structure |
| Other typedefs | `?` |

Pointers (except `void*`) are mapped to `ptr64`, and unknown types default to `?`.

## Advantages over Previous Parser

1. **More accurate parsing**: Leverages Clang's AST instead of regex-based parsing
2. **Better enum handling**: Automatically resolves enum base types and includes full enum definitions
3. **Function typedef support**: Parses function pointer signatures from typedefs
4. **Structured documentation**: Extracts Doxygen comments in a more reliable way
5. **Type safety**: Uses Clang's type system for accurate type information
6. **Better scalability**: Can handle complex C++ constructs that regex parsing struggled with
7. **Nested type support**: Handles enums within function prototypes and other complex scenarios

## Troubleshooting

### No functions exported
- Ensure your YAML file contains a `ChildFunctions` section
- Check that your filters aren't too restrictive
- Verify the YAML file is properly formatted

### Type showing as '?'
- The type is not in the type mapping dictionary
- You can add custom type mappings to the `map_type()` function

### Missing descriptions
- Ensure your source files have proper Doxygen comments with `@brief`, `@param`, and `@return` tags
- Verify clang-doc is extracting the comments (check the YAML file)

### Missing enum structures
- Verify the enum is defined in the YAML file's `ChildEnums` section
- Ensure the enum has proper Doxygen documentation
- Check that enum values are documented

### Function prototype parameters have generic names
- This is expected behavior - clang-doc doesn't preserve parameter names in typedef signatures
- Parameter names are auto-generated as `param1`, `param2`, etc.
- To add meaningful names, you can either:
  - Manually edit the JSON output
  - Extend the parser to read parameter metadata from additional sources
  - Use wrapper functions with documented parameters instead of raw typedefs

## Configuration

### Filtering Sentinel Enum Values

By default, the parser filters out common sentinel enum values like "Count", "MAX", "INVALID", etc. You can customize this behavior by modifying the `sentinel_names` set in the `build_enum_structure()` function:

```python
sentinel_names = {'Count', 'MAX', 'Max', 'INVALID', 'Invalid', 'NUM', 'Num'}
```

## License

This script is part of the Plugify project.
