#!/usr/bin/python3
import argparse
import glob
import json
import os
import sys
import re
from cxxheaderparser import simple


def parse_doxygen_comment(comment: str):
    """Parse the Doxygen comment to extract brief, params, and return sections."""
    lines = [line.strip(' *') for line in comment.splitlines() if line.strip(' *')]

    parsed_data = {"brief": None, "params": [], "return": None}
    brief_pattern = re.compile(r"@brief\s+(.*)")
    param_pattern = re.compile(r"@param\s+(\w+)\s+(.*)")
    return_pattern = re.compile(r"@return\s+(.*)")

    for line in lines:
        if brief_match := brief_pattern.match(line):
            parsed_data["brief"] = brief_match.group(1)
        elif param_match := param_pattern.match(line):
            param_name, param_desc = param_match.groups()
            parsed_data["params"].append({"name": param_name, "description": param_desc})
        elif return_match := return_pattern.match(line):
            parsed_data["return"] = return_match.group(1)

    return parsed_data


def find_doxygen_for_function(file_content: str, function_name: str) -> str:
    """Find and return the Doxygen comment block for the function."""
    pattern = re.compile(rf"/\*\*(?:\s|\S)*?\*/\s*.*?\b{re.escape(function_name)}\b", re.MULTILINE)
    match = pattern.search(file_content)
    if match:
        doxygen_block = match.group(0)
        comment_end_index = doxygen_block.rfind("*/") + 2
        s = doxygen_block[:comment_end_index].strip()
        return s[s.rfind("@brief"):] if "@brief" in s else s
    return ""


def find_param_by_name(params, param_name):
    """Find parameter by name in the list of params."""
    return next((param for param in params if param.get('name') == param_name), None)


def map_type(t: str):
    """Map a C++ type to a more user-friendly format."""
    switch_dict = {
        'plg::string': 'string',
        'plg::vector<plg::string>': 'string[]',
        'plg::str': 'string',

        #'plg::vec': '?',

        'plg::any': 'any',
        'plg::vector<plg::any>': 'any[]',
        #'plg::var': 'any',

        # 'const char*': 'string',
        # 'char*': 'string',
        # 'const char**': 'string[]',
        # 'char**': 'string[]',

        'void': 'void',
        'bool': 'bool',
        'float': 'float',
        'double': 'double',
        'void*': 'ptr64',
        'uintptr_t': 'ptr64',
        'intptr_t': 'ptr64',
        'char': 'char8',
        'signed char': 'char8',
        'char16_t': 'char16',
        'int8_t': 'int8',
        'int8': 'int8',
        'int16_t': 'int16',
        'int16': 'int16',
        'short': 'int16',
        'int32_t': 'int32',
        'int32': 'int32',
        'int': 'int32',
        'long': 'int32',
        'int64_t': 'int64',
        'int64': 'int64',
        '__int64': 'int64',
        'long long': 'int64',
        'uint8_t': 'uint8',
        'uint8': 'uint8',
        'unsigned char': 'uint8',
        'byte': 'uint8',
        'uint16_t': 'uint16',
        'uint16': 'uint16',
        'unsigned short': 'uint16',
        'uint32_t': 'uint32',
        'uint32': 'uint32',
        'unsigned int': 'uint32',
        'unsigned long': 'uint32',
        'uint64_t': 'uint64',
        'uint64': 'uint64',
        'unsigned __int64': 'uint64',
        'unsigned long long': 'uint64',

        # 'bool*': 'bool[]',
        # 'float*': 'float[]',
        # 'double*': 'double[]',
        # 'void**': 'ptr64[]',
        # 'char16_t*': 'char16[]',
        # 'int8_t*': 'int8[]',
        # 'int8*': 'int8[]',
        # 'int16_t*': 'int16[]',
        # 'int16*': 'int16[]',
        # 'short*': 'int16[]',
        # 'int32_t*': 'int32[]',
        # 'int32*': 'int32[]',
        # 'int*': 'int32[]',
        # 'long*': 'int32[]',
        # 'int64_t*': 'int64[]',
        # 'int64*': 'int64[]',
        # '__int64*': 'int64[]',
        # 'long long*': 'int64[]',
        # 'uint8_t*': 'uint8[]',
        # 'uint8*': 'uint8[]',
        # 'unsigned char*': 'uint8[]',
        # 'byte*': 'uint8[]',
        # 'uint16_t*': 'uint16[]',
        # 'uint16*': 'uint16[]',
        # 'unsigned short*': 'uint16[]',
        # 'uint32_t*': 'uint32*[]',
        # 'uint32*': 'uint32[]',
        # 'unsigned int*': 'uint32[]',
        # 'unsigned long*': 'uint32[]',
        # 'uint64_t*': 'uint64[]',
        # 'uint64*': 'uint64[]',
        # 'unsigned __int64*': 'uint64[]',
        # 'unsigned long long*': 'uint64[]',

        'plg::vector<bool>': 'bool[]',
        'plg::vector<float>': 'float[]',
        'plg::vector<double>': 'double[]',
        'plg::vector<void*>': 'ptr64[]',
        'plg::vector<char16_t>': 'char16[]',
        'plg::vector<int8_t>': 'int8[]',
        'plg::vector<int8>': 'int8[]',
        'plg::vector<int16_t>': 'int16[]',
        'plg::vector<int16>': 'int16[]',
        'plg::vector<short>': 'int16[]',
        'plg::vector<int32_t>': 'int32[]',
        'plg::vector<int32>': 'int32[]',
        'plg::vector<int>': 'int32[]',
        'plg::vector<long>': 'int32[]',
        'plg::vector<int64_t>': 'int64[]',
        'plg::vector<int64>': 'int64[]',
        'plg::vector<__int64>': 'int64[]',
        'plg::vector<long long>': 'int64[]',
        'plg::vector<uint8_t>': 'uint8[]',
        'plg::vector<uint8>': 'uint8[]',
        'plg::vector<unsigned char>': 'uint8[]',
        'plg::vector<byte>': 'uint8[]',
        'plg::vector<uint16_t>': 'uint16[]',
        'plg::vector<uint16>': 'uint16[]',
        'plg::vector<unsigned short>': 'uint16[]',
        'plg::vector<uint32_t>': 'uint32[]',
        'plg::vector<uint32>': 'uint32[]',
        'plg::vector<unsigned int>': 'uint32[]',
        'plg::vector<unsigned long>': 'uint32[]',
        'plg::vector<uint64_t>': 'uint64[]',
        'plg::vector<uint64>': 'uint64[]',
        'plg::vector<unsigned __int64>': 'uint64[]',
        'plg::vector<unsigned long long>': 'uint64[]',
        
        'plg::vector<plg::vec3>': 'vec3[]',
        'plg::vector<vec3>': 'vec3[]',
        'plg::vector<Vector>': 'vec3[]',
        'plg::vector<QAngle>': 'vec3[]',
        'plg::vector<Vector3D>': 'vec3[]',
        'plg::vector<Vector3>': 'vec3[]',
        'plg::vector<Vector3f>': 'vec3[]',
        
        'plg::vector<plg::vec2>': 'vec2[]',
        'plg::vector<Vector2f>': 'vec2[]',
        'plg::vector<Vector2>': 'vec2[]',
        'plg::vector<Vector2D>': 'vec2[]',
        'plg::vector<vec2>': 'vec2[]',
         
        'plg::vector<plg::vec4>': 'vec4[]',
        'plg::vector<Vector4>': 'vec4[]',
        'plg::vector<Vector4f>': 'vec4[]',
        'plg::vector<Vector4D>': 'vec4[]',
        'plg::vector<vec4>': 'vec4[]',
        
        'plg::vector<plg::mat4x4>': 'mat4x4[]',
        'plg::vector<Matrix>': 'mat4x4[]',
        'plg::vector<Matrix4x4>': 'mat4x4[]',
        'plg::vector<mat4x4>': 'mat4x4[]',

        'CPlayerSlot': 'int32',
        'CEntityHandle': 'int32',
        'Handle': 'uint64',
        'ConVarHandle': 'uint64',
        'plg::vector<ConVarHandle>': 'uint64[]',

        'plg::vec3': 'vec3',
        'vec3': 'vec3',
        'Vector': 'vec3',
        'QAngle': 'vec3',
        'Vector3D': 'vec3',
        'Vector3': 'vec3',
        'Vector3f': 'vec3',
        
        'Vector2D': 'vec2',
        'plg::vec2': 'vec2',
        'vec2': 'vec2',
        'Vector2': 'vec2',
        'Vector2f': 'vec2',
        
        'Vector4D': 'vec4',
        'plg::vec4': 'vec4',
        'vec4': 'vec4',
        'Vector4': 'vec4',
        'Vector4f': 'vec4',
        
        'plg::mat4x4': 'mat4x4',
        'Matrix': 'mat4x4',
        'Matrix4x4': 'mat4x4',
        'mat4x4': 'mat4x4',
    }
    return switch_dict.get(t, '?')


def convert_type(t: str):
    """Convert type string into its mapped type and reference flag."""
    const = False
    if t.startswith('const '):
        t = t[len('const '):]
        const = True
    if t.endswith('*'):
        return 'ptr64', False
    elif t.endswith('&'):
        return [map_type(t[:-1]), not const]
    return map_type(t), False


def build_param_data(doxygen_block, param):
    """Build parameter data, including type and description."""
    param_type, ref = convert_type(param.type.format())
    description = find_param_by_name(doxygen_block['params'], param.name.format())
    param_data = {
        'name': param.name.format(),
        'type': param_type,
        'ref': ref
    }
    if description:
        param_data['description'] = description['description']
    return param_data


def build_return_type(function, doxygen_block):
    """Build the return type for a function."""
    return_data = {
        'type': convert_type(function.return_type.format())[0]
    }
    description = doxygen_block['return']
    if description:
        return_data['description'] = description
    return return_data


def process_function(function, file_name, doxygen_block):
    """Process the function and build the exported method dictionary."""
    param_types = [build_param_data(doxygen_block, param) for param in function.parameters]
    ret_type = build_return_type(function, doxygen_block)
    return {
        'name': function.name.format(),
        'group': file_name.lower().capitalize(),
        'description': doxygen_block['brief'],
        'funcName': function.name.format(),
        'paramTypes': param_types,
        'retType': ret_type
    }


def process_functions(parsed, file_name, file_contents):
    """Process all functions from the parsed content."""
    exported_methods = []
    for function in parsed.namespace.functions:
        print(f'{function.name.format()};')  # Debug: Show processing function
        doxygen_block = find_doxygen_for_function(file_contents, function.name.format())
        if doxygen_block:
            doxygen_data = parse_doxygen_comment(doxygen_block)
            function_data = process_function(function, file_name, doxygen_data)
            exported_methods.append(function_data)
    return exported_methods


def remove_specific_lines(text):
    lines = text.splitlines()  # Split into lines
    filtered_lines = [line for line in lines if not (line.strip().startswith('#') or line.strip().startswith('PLUGIFY_'))]
    return '\n'.join(filtered_lines)
    

def main(input_folder, output_file):
    """Main function to read files, parse them, and output the result."""
    all_exported_methods = []

    # Search for all .cpp files in the specified folder
    input_glob = os.path.join(input_folder, "*.cpp")
    for cpp_file in glob.glob(input_glob):
        print("")
        with open(cpp_file, 'r') as file:
            file_contents = remove_specific_lines(file.read())
        contents = file_contents.replace('extern "C"', '').replace('PLUGIN_API', '')
        file_name = os.path.splitext(os.path.basename(cpp_file))[0]
        parsed = simple.parse_string(contents, options=None)
        exported_methods = process_functions(parsed, file_name, file_contents)
        all_exported_methods.extend(exported_methods)

    with open(output_file, 'w') as f:
        json.dump(all_exported_methods, f, indent=4)


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("input_folder", help="Folder path to process")
    parser.add_argument("output_file", help="JSON file to output the processed results")
    return parser.parse_args()

if __name__ == "__main__":
    args = get_args()

    main(args.input_folder, args.output_file)
