# Plugify C++ Header Generator

A Python tool that automatically generates C++ header files with type-safe bindings for Plugify plugins from JSON manifest files.

## Overview

This generator reads `.pplugin` JSON manifest files and produces corresponding C++ header files (`.hpp`) that provide:
- Type-safe function wrappers
- Enum definitions
- Delegate (function pointer) type definitions
- Automatic method pointer resolution
- Doxygen-compatible documentation comments

## Requirements

- Python 3.10 or higher
- Input: `.pplugin` JSON manifest file
- Output: A directory for generated headers

## Installation

No installation required. Simply download the `generator.py` script and ensure it's executable:

```bash
chmod +x generator.py
```

## Usage

### Basic Syntax

```bash
python3 generator.py <manifest_path> <output_directory> [--override]
```

### Arguments

| Argument | Required | Description |
|----------|----------|-------------|
| `manifest_path` | Yes | Path to the `.pplugin` JSON manifest file |
| `output_directory` | Yes | Directory where the generated header will be saved |
| `--override` | No | Overwrite existing files (otherwise, script exits if file exists) |

### Examples

**Generate a header file:**
```bash
python3 generator.py my_plugin.pplugin ./output
```

**Override existing files:**
```bash
python3 generator.py my_plugin.pplugin ./output --override
```

**Result:**
```
Header generated at: ./output/pps/my_plugin.hpp
```

## Input Format

The script expects a JSON manifest file with the following structure:

```json
{
  "name": "my_plugin",
  "methods": [
    {
      "name": "MyFunction",
      "description": "Does something useful",
      "retType": {
        "type": "int32",
        "description": "Return value description"
      },
      "paramTypes": [
        {
          "name": "value",
          "type": "float",
          "description": "Parameter description"
        }
      ]
    }
  ]
}
```

### Supported Types

**Basic types:** `void`, `bool`, `char8`, `char16`, `int8`, `int16`, `int32`, `int64`, `uint8`, `uint16`, `uint32`, `uint64`, `ptr64`, `float`, `double`, `string`, `any`, `function`

**Vector types:** `vec2`, `vec3`, `vec4`, `mat4x4`

**Array types:** Add `[]` suffix (e.g., `int32[]`, `string[]`, `vec2[]`)

**Special features:**
- Enums with custom types
- Delegates (function pointers)
- Reference parameters (`"ref": true`)
- Default parameter values

## Output Format

The generated header includes:

```cpp
#pragma once

#include <plg/plugin.hpp>
#include <plg/any.hpp>
#include <cstdint>

namespace my_plugin {
    // Enums
    enum class MyEnum : int32_t { /* ... */ };
    
    // Delegates
    using MyCallback = void (*)(int32_t);
    
    // Function wrappers
    /**
     * @brief Does something useful
     * @function MyFunction
     * @param value (float): Parameter description
     * @return int32: Return value description
     */
    inline int32_t MyFunction(float value) {
        using MyFunctionFn = int32_t (*)(float);
        static MyFunctionFn __func = nullptr;
        if (__func == nullptr) 
            plg::GetMethodPtr2("my_plugin.MyFunction", 
                              reinterpret_cast<void**>(&__func));
        return __func(value);
    }
}
```

## Features

### Automatic Type Conversion
- Converts JSON types to appropriate C++ types
- Handles value types, references, and return types differently
- Supports vectors with `plg::vector<T>`

### Name Sanitization
- Automatically appends `_` to C++ reserved keywords
- Prevents naming conflicts

### Documentation Generation
- Creates Doxygen-style comments from JSON descriptions
- Documents parameters and return types

### Duplicate Prevention
- Tracks generated enums and delegates
- Avoids duplicate definitions

## Error Handling

The script will exit with an error if:
- Manifest file doesn't exist
- Output directory doesn't exist
- Output file already exists (without `--override`)
- JSON parsing fails
- Unsupported type is encountered

## Integration

Include the generated header in your C++ project:

```cpp
#include "pps/my_plugin.hpp"

int main() {
    float result = my_plugin::MyFunction(3.14f);
    return 0;
}
```

## Troubleshooting

**"Manifest file does not exist"**
- Check the path to your `.pplugin` file

**"Output directory does not exist"**
- Create the output directory first: `mkdir -p output`

**"Output file already exists"**
- Use `--override` flag or delete existing file

**"Unsupported type"**
- Check that all types in your manifest are in the supported types list

## Download Generator Script

The generator script is available at:
- **GitHub Repository:** https://github.com/untrustedmodders/plugify-module-cpp
- **Direct Link:** https://raw.githubusercontent.com/untrustedmodders/plugify-module-cpp/main/generator/generator.py

### Quick Download

```bash
# Using wget
wget https://raw.githubusercontent.com/untrustedmodders/plugify-module-cpp/main/generator/generator.py

# Using curl
curl -O https://raw.githubusercontent.com/untrustedmodders/plugify-module-cpp/main/generator/generator.py

# Make it executable
chmod +x generator.py
```

## License

[Add license information]

## Contributing

For issues, feature requests, or contributions, please visit the GitHub repository.
