#!/usr/bin/python3
import sys
import argparse
import os
import json
from enum import Enum


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
    'vec2': 'plg::vec2',
    'vec3': 'plg::vec3',
    'vec4': 'plg::vec4',
    'mat4x4': 'plg::mat4x4'
}


def convert_type(type_name: str, is_ref=False, is_ret=False) -> str:
    """Convert a type name to the corresponding C++ type."""
    try:
        if is_ret:
            return RET_TYPES_MAP[type_name]
        return REF_TYPES_MAP[type_name] if is_ref else VAL_TYPES_MAP[type_name]
    except KeyError:
        raise ValueError(f'Unsupported type: {type_name}')


class ParamGen(Enum):
    Types = 1
    Names = 2
    TypesNames = 3


def gen_params(params: list[dict], param_gen: ParamGen) -> str:
    """Generate function parameters based on the specified type."""
    def gen_param(index: int, param: dict) -> str:
        type_name = convert_type(
            param.get('type', ''),
            param.get('ref', False),
            False
        )
        if 'delegate' in type_name and 'prototype' in param:
            type_name = param['prototype'].get('name', 'UnnamedDelegate')
        if param_gen == ParamGen.Types:
            return type_name
        if param_gen == ParamGen.Names:
            return param.get('name', f'p{index}')
        if param_gen == ParamGen.TypesNames:
            return f'{type_name} {param.get("name", f"p{index}")}'
        return ''

    return ', '.join(gen_param(i, p) for i, p in enumerate(params)) if params else ''


def gen_delegate(prototype: dict) -> str:
    """Generate a delegate type definition."""
    ret_type_data = prototype.get('retType', {})
    ret_type = convert_type(
        ret_type_data.get('type', ''),
        ret_type_data.get('ref', False),
        True
    )
    param_types = gen_params(prototype.get('paramTypes', []), ParamGen.Types)
    delegate_name = prototype.get('name', 'UnnamedDelegate')
    return f'\tusing {delegate_name} = {ret_type} (*)({param_types});\n'


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
    tab = '    ' * tab_level

    # Start building the Doxygen comment
    docstring = [f"{tab}/**\n"]
    docstring.append(f"{tab} * @brief {description}\n")
    docstring.append(f"{tab} *\n")
    docstring.append(f"{tab} * @function {name}\n")

    # Add parameters
    for param in param_types:
        param_name = param.get('name', 'UnnamedParam')
        param_type = param.get('type', 'Any')
        param_desc = param.get('description', 'No description available.')
        docstring.append(f"{tab} * @param {param_name} ({param_type}): {param_desc}\n")

    # Add return type
    if ret_type.lower() != 'void':
        ret_desc = method.get('retType', {}).get('description', 'No description available.')
        docstring.append(f"{tab} *\n{tab} * @return {ret_type}: {ret_desc}\n")

    # Add callback prototype if present
    for param in param_types:
        if param.get('type') == 'function' and 'prototype' in param:
            prototype = param['prototype']
            proto_name = prototype.get('name', 'UnnamedCallback')
            proto_desc = prototype.get('description', 'No description provided.')
            proto_params = prototype.get('paramTypes', [])
            proto_ret = prototype.get('retType', {})

            docstring.append(f"{tab} *\n{tab} * @callback {proto_name}\n")
            docstring.append(f"{tab} * @brief {proto_desc}\n")
            docstring.append(f"{tab} *\n")

            for proto_param in proto_params:
                p_name = proto_param.get('name', 'UnnamedParam')
                p_type = proto_param.get('type', 'Any')
                p_desc = proto_param.get('description', 'No description available.')
                docstring.append(f"{tab} * @param {p_name} ({p_type}): {p_desc}\n")

            if proto_ret:
                proto_ret_type = proto_ret.get('type', 'void')
                proto_ret_desc = proto_ret.get('description', 'No description available.')
                docstring.append(f"{tab} *\n{tab} * @return (callback): {proto_ret_type}: {proto_ret_desc}\n")

    # Close Doxygen comment
    docstring.append(f"{tab} */\n")

    return ''.join(docstring)


def generate_header(plugin_name: str, pplugin: dict) -> str:
    """Generate the C++ header file content."""
    link = 'https://github.com/untrustedmodders/plugify-module-cpp/blob/main/generator/generator.py'
    content = [
        '#pragma once\n',
        '\n',
        '#include <plugify/cpp_plugin.hpp>\n',
        '#include <plugify/any.hpp>\n',
        '#include <cstdint>\n',
        '\n',
        f'// Generated from {plugin_name}.pplugin by {link}\n',
        '\n',
        f'namespace {plugin_name} {{\n'
    ]

    for method in pplugin.get('exportedMethods', []):
        ret_type_data = method.get('retType', {})
        ret_type = convert_type(
            ret_type_data.get('type', None),
            ret_type_data.get('ref', False),
            True
        )

        if 'prototype' in ret_type_data:
            ret_type = ret_type_data['prototype'].get('name', 'UnnamedPrototype')
            content.append(gen_delegate(ret_type_data['prototype']))

        for param in method.get('paramTypes', []):
            if 'prototype' in param:
                content.append(gen_delegate(param['prototype']))

        param_list = gen_params(method.get('paramTypes', []), ParamGen.TypesNames)
        param_types = gen_params(method.get('paramTypes', []), ParamGen.Types)
        param_names = gen_params(method.get('paramTypes', []), ParamGen.Names)

        content.append(gen_documentation(method, tab_level=1))

        method_name = method.get('name', 'UnnamedMethod')
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

    plugin_name = os.path.splitext(os.path.basename(manifest_path))[0]
    output_path = os.path.join(output_dir, 'pps', f'{plugin_name}.hpp')
    os.makedirs(os.path.dirname(output_path), exist_ok=True)

    if os.path.isfile(output_path) and not override:
        print(f'Output file already exists: {output_path}. Use --override to overwrite existing file.')
        return 1

    try:
        with open(manifest_path, 'r', encoding='utf-8') as file:
            pplugin = json.load(file)

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