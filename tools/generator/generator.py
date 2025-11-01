#!/usr/bin/python3
import sys
import argparse
import os
import json
from enum import IntEnum


TYPES_MAP = {
    'void': 'void',
    'bool': 'bool',
    'char8': 'char',
    'char16': 'char16_t',
    'int8': 'int8_t',
    'int16': 'int16_t',
    'int32': 'int32_t',
    'int64': 'int64_t',
    'uint8': 'uint8_t',
    'uint16': 'uint16_t',
    'uint32': 'uint32_t',
    'uint64': 'uint64_t',
    'ptr64': 'void*',
    'float': 'float',
    'double': 'double',
    'function': 'delegate',
    'string': 'plg::string',
    'any': 'plg::any',
    'bool[]': 'bool',
    'char8[]': 'char',
    'char16[]': 'char16_t',
    'int8[]': 'int8_t',
    'int16[]': 'int16_t',
    'int32[]': 'int32_t',
    'int64[]': 'int64_t',
    'uint8[]': 'uint8_t',
    'uint16[]': 'uint16_t',
    'uint32[]': 'uint32_t',
    'uint64[]': 'uint64_t',
    'ptr64[]': 'void*',
    'float[]': 'float',
    'double[]': 'double',
    'string[]': 'plg::string',
    'any[]': 'plg::any',
    'vec2[]': 'plg::vec2',
    'vec3[]': 'plg::vec3',
    'vec4[]': 'plg::vec4',
    'mat4x4[]': 'plg::mat4x4',
    'vec2': 'plg::vec2',
    'vec3': 'plg::vec3',
    'vec4': 'plg::vec4',
    'mat4x4': 'plg::mat4x4'
}


VAL_TYPES_MAP = {
    'void': 'void',
    'bool': 'bool',
    'char8': 'char',
    'char16': 'char16_t',
    'int8': 'int8_t',
    'int16': 'int16_t',
    'int32': 'int32_t',
    'int64': 'int64_t',
    'uint8': 'uint8_t',
    'uint16': 'uint16_t',
    'uint32': 'uint32_t',
    'uint64': 'uint64_t',
    'ptr64': 'void*',
    'float': 'float',
    'double': 'double',
    'function': 'delegate',
    'string': 'const plg::string&',
    'any': 'const plg::any&',
    'bool[]': 'const plg::vector<bool>&',
    'char8[]': 'const plg::vector<char>&',
    'char16[]': 'const plg::vector<char16_t>&',
    'int8[]': 'const plg::vector<int8_t>&',
    'int16[]': 'const plg::vector<int16_t>&',
    'int32[]': 'const plg::vector<int32_t>&',
    'int64[]': 'const plg::vector<int64_t>&',
    'uint8[]': 'const plg::vector<uint8_t>&',
    'uint16[]': 'const plg::vector<uint16_t>&',
    'uint32[]': 'const plg::vector<uint32_t>&',
    'uint64[]': 'const plg::vector<uint64_t>&',
    'ptr64[]': 'const plg::vector<void*>&',
    'float[]': 'const plg::vector<float>&',
    'double[]': 'const plg::vector<double>&',
    'string[]': 'const plg::vector<plg::string>&',
    'any[]': 'const plg::vector<plg::any>&',
    'vec2[]': 'const plg::vector<plg::vec2>&',
    'vec3[]': 'const plg::vector<plg::vec3>&',
    'vec4[]': 'const plg::vector<plg::vec4>&',
    'mat4x4[]': 'const plg::vector<plg::mat4x4>&',
    'vec2': 'const plg::vec2&',
    'vec3': 'const plg::vec3&',
    'vec4': 'const plg::vec4&',
    'mat4x4': 'const plg::mat4x4&'
}


REF_TYPES_MAP = {
    'void': 'void',
    'bool': 'bool&',
    'char8': 'char&',
    'char16': 'char16_t&',
    'int8': 'int8_t&',
    'int16': 'int16_t&',
    'int32': 'int32_t&',
    'int64': 'int64_t&',
    'uint8': 'uint8_t&',
    'uint16': 'uint16_t&',
    'uint32': 'uint32_t&',
    'uint64': 'uint64_t&',
    'ptr64': 'void*&',
    'float': 'float&',
    'double': 'double&',
    'function': 'delegate',
    'string': 'plg::string&',
    'any': 'plg::any&',
    'bool[]': 'plg::vector<bool>&',
    'char8[]': 'plg::vector<char>&',
    'char16[]': 'plg::vector<char16_t>&',
    'int8[]': 'plg::vector<int8_t>&',
    'int16[]': 'plg::vector<int16_t>&',
    'int32[]': 'plg::vector<int32_t>&',
    'int64[]': 'plg::vector<int64_t>&',
    'uint8[]': 'plg::vector<uint8_t>&',
    'uint16[]': 'plg::vector<uint16_t>&',
    'uint32[]': 'plg::vector<uint32_t>&',
    'uint64[]': 'plg::vector<uint64_t>&',
    'ptr64[]': 'plg::vector<void*>&',
    'float[]': 'plg::vector<float>&',
    'double[]': 'plg::vector<double>&',
    'string[]': 'plg::vector<plg::string>&',
    'any[]': 'plg::vector<plg::any>&',
    'vec2[]': 'plg::vector<plg::vec2>&',
    'vec3[]': 'plg::vector<plg::vec3>&',
    'vec4[]': 'plg::vector<plg::vec4>&',
    'mat4x4[]': 'plg::vector<plg::mat4x4>&',
    'vec2': 'plg::vec2&',
    'vec3': 'plg::vec3&',
    'vec4': 'plg::vec4&',
    'mat4x4': 'plg::mat4x4&'
}


RET_TYPES_MAP = {
    'void': 'void',
    'bool': 'bool',
    'char8': 'char',
    'char16': 'char16_t',
    'int8': 'int8_t',
    'int16': 'int16_t',
    'int32': 'int32_t',
    'int64': 'int64_t',
    'uint8': 'uint8_t',
    'uint16': 'uint16_t',
    'uint32': 'uint32_t',
    'uint64': 'uint64_t',
    'ptr64': 'void*',
    'float': 'float',
    'double': 'double',
    'function': 'delegate',
    'string': 'plg::string',
    'any': 'plg::any',
    'bool[]': 'plg::vector<bool>',
    'char8[]': 'plg::vector<char>',
    'char16[]': 'plg::vector<char16_t>',
    'int8[]': 'plg::vector<int8_t>',
    'int16[]': 'plg::vector<int16_t>',
    'int32[]': 'plg::vector<int32_t>',
    'int64[]': 'plg::vector<int64_t>',
    'uint8[]': 'plg::vector<uint8_t>',
    'uint16[]': 'plg::vector<uint16_t>',
    'uint32[]': 'plg::vector<uint32_t>',
    'uint64[]': 'plg::vector<uint64_t>',
    'ptr64[]': 'plg::vector<void*>',
    'float[]': 'plg::vector<float>',
    'double[]': 'plg::vector<double>',
    'string[]': 'plg::vector<plg::string>',
    'any[]': 'plg::vector<plg::any>',
    'vec2[]': 'plg::vector<plg::vec2>',
    'vec3[]': 'plg::vector<plg::vec3>',
    'vec4[]': 'plg::vector<plg::vec4>',
    'mat4x4[]': 'plg::vector<plg::mat4x4>',
    'vec2': 'plg::vec2',
    'vec3': 'plg::vec3',
    'vec4': 'plg::vec4',
    'mat4x4': 'plg::mat4x4'
}


INVALID_NAMES = {
    'alignas',
    'alignof',
    'and',
    'and_eq',
    'asm',
    'auto',
    'bitand',
    'bitor',
    'bool',
    'break',
    'case',
    'catch',
    'char',
    'char8_t',
    'char16_t',
    'char32_t',
    'class',
    'compl',
    'concept',
    'const',
    'consteval',
    'constexpr',
    'constinit',
    'continue',
    'co_await',
    'co_return',
    'co_yield',
    'decltype',
    'default',
    'delete',
    'do',
    'double',
    'dynamic_cast',
    'else',
    'enum',
    'explicit',
    'export',
    'extern',
    'false',
    'float',
    'for',
    'friend',
    'goto',
    'if',
    'inline',
    'int',
    'long',
    'mutable',
    'namespace',
    'new',
    'noexcept',
    'not',
    'not_eq',
    'nullptr',
    'operator',
    'or',
    'or_eq',
    'private',
    'protected',
    'public',
    'register',
    'reinterpret_cast',
    'requires',
    'return',
    'short',
    'signed',
    'sizeof',
    'static',
    'static_assert',
    'static_cast',
    'struct',
    'switch',
    'template',
    'this',
    'thread_local',
    'throw',
    'true',
    'try',
    'typedef',
    'typeid',
    'typename',
    'union',
    'unsigned',
    'using',
    'virtual',
    'void',
    'volatile',
    'wchar_t',
    'while',
    'xor',
    'xor_eq'
}


def convert_type(type_name: str, is_ref: bool = False, is_ret: bool = False) -> str:
    """Convert a type name to the corresponding C++ type."""
    try:
        if is_ret:
            return RET_TYPES_MAP[type_name]
        return REF_TYPES_MAP[type_name] if is_ref else VAL_TYPES_MAP[type_name]
    except KeyError:
        raise ValueError(f'Unsupported type: {type_name}')


def get_type_name(param: dict, is_ret: bool) -> str:
    param_type = param.get('type', 'Invalid')
    type_name = convert_type(param_type, 'ref' in param and param['ref'], is_ret)
    if 'delegate' in type_name and 'prototype' in param:
        return generate_name(param['prototype'].get('name', 'UnnamedDelegate'))
    elif 'enum' in param:
        return type_name.replace(TYPES_MAP.get(param_type, '?'), generate_name(param['enum'].get('name', 'UnnamedEnum')))
    return type_name


def generate_name(name: str) -> str:
    """
    Generates a valid C++ name by appending an underscore if the name is invalid.
    """
    return f'{name}_' if name in INVALID_NAMES else name


class ParamGen(IntEnum):
    Types = 1
    Names = 2
    TypesNames = 3


def gen_params(params: list[dict], param_gen: ParamGen) -> str:
    """Generate function parameters based on the specified type."""
    def gen_param(index: int, param: dict) -> str:
        type_name = get_type_name(param, False)
        match param_gen:
            case ParamGen.Types:
                return type_name
            case ParamGen.Names:
                return generate_name(param.get('name', f'p{index}'))
            case ParamGen.TypesNames:
                if param.get('default'):
                    return f'{type_name} {generate_name(param.get("name", f"p{index}"))} = {param["default"]}'
                return f'{type_name} {generate_name(param.get("name", f"p{index}"))}'
            case _:
                return ''

    return ', '.join(gen_param(i, p) for i, p in enumerate(params)) if params else ''


def gen_delegate_body(prototype: dict, delegates: set[str]) -> str:
    """
    Generates a C++ delegate definition from the provided prototype.
    """
    # Check for duplicate delegates
    delegate_name = prototype.get('name', 'UnnamedDelegate')
    delegate_description = prototype.get('description', '')

    # Check for duplicate descriptions
    if delegate_name in delegates:
        return ''  # Skip if already generated

    # Add the delegate name to the set
    delegates.add(delegate_name)

    # Get the return type and convert it
    ret_type_data = prototype.get('retType', {})
    ret_type = get_type_name(ret_type_data, True)

    # Start building the delegate definition
    delegate_code = []
    if delegate_description:
        delegate_code.append(gen_documentation(prototype, tab_level=1))
    param_types = gen_params(prototype.get('paramTypes', []), ParamGen.Types)
    delegate_code.append(f'\tusing {delegate_name} = {ret_type} (*)({param_types});')

    # Join the list into a single formatted string
    return '\n'.join(delegate_code)


def gen_enum_body(enum: dict, enum_type: str, enums: set[str]) -> str:
    """
    Generates a C++ enum definition from the provided enum metadata.
    """
    # Extract enum name and values
    enum_name = enum.get('name', 'InvalidEnum')
    enum_description = enum.get('description', '')
    enum_values = enum.get('values', [])

    # Check for duplicate enums
    if enum_name in enums:
        return ''  # Skip if already generated

    # Add the enum name to the set
    enums.add(enum_name)

    # Start building the enum definition
    enum_code = []
    if enum_description:
        enum_code.append(f'\t/**\n\t * @enum {enum_name}\n\t *\n\t * @brief {enum_description}\n\t */')
    enum_code.append(f'\tenum class {enum_name} : {convert_type(enum_type)} {{')

    # Iterate over the enum values and generate corresponding C++ entries
    for i, value in enumerate(enum_values):
        name = value.get('name', f'InvalidName_{i}')
        enum_value = value.get('value', str(i))
        description = value.get('description', '')

        # Add Doxygen comment for each value
        if description:
            enum_code.append(f'\t\t/**\n\t\t * @brief {description}\n\t\t */')
        enum_code.append(f'\t\t{name} = {enum_value},')

    # Close the enum definition
    enum_code.append("\t};")

    # Join the list into a single formatted string
    return '\n'.join(enum_code)


def gen_documentation(method: dict, tab_level: int = 0) -> str:
    """
    Generate a Doxygen-style comment block from a JSON block with customizable tabulation.

    Args:
        method (dict): The input JSON data describing the function.
        tab_level (int): The level of tabulation for the generated comment.

    Returns:
        str: The generated Doxygen comment block.
    """
    # Extract general details
    name = method.get('name', 'UnnamedFunction')
    description = method.get('description', 'No description provided.')
    param_types = method.get('paramTypes', [])
    ret_type = method.get('retType', {}).get('type', 'void')

    # Determine tabulation
    tab = '\t' * tab_level

    # Start building the Doxygen comment
    docstring = [f'{tab}/**\n{tab} * @brief {description}\n{tab} *\n{tab} * @function {name}\n']

    # Add parameters
    for param in param_types:
        param_name = param.get('name', 'UnnamedParam')
        param_type = param.get('type', 'Any')
        param_desc = param.get('description', 'No description available.')
        docstring.append(f'{tab} * @param {param_name} ({param_type}): {param_desc}\n')

    # Add return type
    if ret_type.lower() != 'void':
        ret_desc = method.get('retType', {}).get('description', 'No description available.')
        docstring.append(f'{tab} *\n{tab} * @return {ret_type}: {ret_desc}\n')

    # Close Doxygen comment
    docstring.append(f'{tab} */\n')

    return ''.join(docstring)


def generate_delegate_code(pplugin: dict, delegates: set[str]) -> str:
    """
    Generate C++ delegate code from a plugin definition.
    """
    # Container for all generated delegate code
    content = []

    def process_prototype(prototype: dict):
        """
        Generate delegate code from the given prototype if it hasn't been processed.
        """
        delegate_code = gen_delegate_body(prototype, delegates)
        if delegate_code:
            content.append(delegate_code)

    # Main loop: Process all exported methods in the plugin
    for method in pplugin.get('methods', []):
        # Check the return type for a delegate
        ret_type = method.get('retType', {})
        if 'prototype' in ret_type:
            process_prototype(ret_type['prototype'])

        # Check parameters for delegates
        for param in method.get('paramTypes', []):
            if 'prototype' in param:
                process_prototype(param['prototype'])

    content.append('\n')

    # Join all generated delegates into a single string
    return '\n'.join(content)


def generate_enum_code(pplugin: dict, enums: set[str]) -> str:
    """
    Generate C++ enum code from a plugin definition.
    """
    # Container for all generated enum code
    content = []

    def process_enum(enum_data: dict, enum_type: str):
        """
        Generate enum code from the given enum data if it hasn't been processed.
        """
        enum_code = gen_enum_body(enum_data, enum_type, enums)
        if enum_code:
            content.append(enum_code)

    def process_prototype(prototype: dict):
        """
        Recursively process a function prototype for enums.
        """
        if 'enum' in prototype.get('retType', {}):
            process_enum(prototype['retType']['enum'], prototype['retType'].get('type', ''))

        for param in prototype.get('paramTypes', []):
            if 'enum' in param:
                process_enum(param['enum'], param.get('type', ''))
            if 'prototype' in param:  # Process nested prototypes
                process_prototype(param['prototype'])

    # Main loop: Process all exported methods in the plugin
    for method in pplugin.get('methods', []):
        if 'retType' in method and 'enum' in method['retType']:
            process_enum(method['retType']['enum'], method['retType'].get('type', ''))

        for param in method.get('paramTypes', []):
            if 'enum' in param:
                process_enum(param['enum'], param.get('type', ''))
            if 'prototype' in param:  # Handle nested function prototypes
                process_prototype(param['prototype'])

    content.append('\n')

    # Join all generated enums into a single string
    return '\n'.join(content)


def generate_header(plugin_name: str, pplugin: dict) -> str:
    """Generate the C++ header file content."""
    link = 'https://github.com/untrustedmodders/plugify-module-cpp/blob/main/generator/generator.py'
    content = [
        '#pragma once\n',
        '\n',
        '#include <plg/plugin.hpp>\n',
        '#include <plg/any.hpp>\n',
        '#include <cstdint>\n',
        '\n',
        f'// Generated from {plugin_name}.pplugin by {link}\n',
        '\n',
        f'namespace {plugin_name} {{\n'
    ]

    # Append enum definitions
    enums = set()
    content.append(generate_enum_code(pplugin, enums))

    # Append delegate definitions
    delegates = set()
    content.append(generate_delegate_code(pplugin, delegates))

    for method in pplugin.get('methods', []):
        method_name = method.get('name', 'UnnamedMethod')
        param_types_data = method.get('paramTypes', [])
        ret_type_data = method.get('retType', {})
        
        ret_type = get_type_name(ret_type_data, True)
        param_list = gen_params(param_types_data, ParamGen.TypesNames)
        param_types = gen_params(param_types_data, ParamGen.Types)
        param_names = gen_params(param_types_data, ParamGen.Names)

        content.append(gen_documentation(method, tab_level=1))

        content.append(
            f'\tinline {ret_type} {method_name}({param_list}) {{\n'
            f'\t\tusing {method_name}Fn = {ret_type} (*)({param_types});\n'
            f'\t\tstatic {method_name}Fn __func = nullptr;\n'
            f'\t\tif (__func == nullptr) '
            f'plg::GetMethodPtr2("{plugin_name}.{method_name}", reinterpret_cast<void**>(&__func));\n'
            f'\t\t{"return " if ret_type_data.get("type", "void") != "void" else ""}__func({param_names});\n'
            '\t}\n\n'
        )

    content.append(f'}} // namespace {plugin_name}\n')
    return ''.join(content)


def main(manifest_path: str, output_dir: str, override: bool):
    """Main entry point for the script."""
    if not os.path.isfile(manifest_path):
        print(f'Manifest file does not exist: {manifest_path}')
        return 1
    if not os.path.isdir(output_dir):
        print(f'Output directory does not exist: {output_dir}')
        return 1

    try:
        with open(manifest_path, 'r', encoding='utf-8') as file:
            pplugin = json.load(file)
            
    except Exception as e:
        print(f'An error occurred: {e}')
        return 1

    plugin_name = pplugin.get('name', os.path.basename(manifest_path).rsplit('.', 3)[0])
    output_path = os.path.join(output_dir, 'pps', f'{plugin_name}.hpp')
    os.makedirs(os.path.dirname(output_path), exist_ok=True)

    if os.path.isfile(output_path) and not override:
        print(f'Output file already exists: {output_path}. Use --override to overwrite existing file.')
        return 1

    try:
        content = generate_header(plugin_name, pplugin)

        with open(output_path, 'w', encoding='utf-8') as file:
            file.write(content)

    except Exception as e:
        print(f'An error occurred: {e}')
        return 1

    print(f'Header generated at: {output_path}')
    return 0


def get_args():
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(description='Generate C++ .hpp include files for plugin manifests.')
    parser.add_argument('manifest', help='Path to the plugin manifest file')
    parser.add_argument('output', help='Path to the output directory')
    parser.add_argument('--override', action='store_true', help='Override existing files')
    return parser.parse_args()


if __name__ == '__main__':
    args = get_args()
    sys.exit(main(args.manifest, args.output, args.override))
