#!/usr/bin/python3
import argparse
import json
import yaml
import os
import re
from pathlib import Path


def map_type(t: str):
    """Map a C++ type to a more user-friendly format."""
    switch_dict = {
        'plg::string': 'string',
        'plg::vector<plg::string>': 'string[]',
        'plg::str': 'string',
        'plg::any': 'any',
        'plg::vector<plg::any>': 'any[]',

        'void': 'void',
        'bool': 'bool',
        'float': 'float',
        'double': 'double',
        'void*': 'ptr64',
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


def convert_type(type_str: str, enums_map: dict, typedefs_map: dict):
    """
    Convert type string into its mapped type and reference flag.
    Returns (mapped_type, is_reference)
    """
    if not type_str:
        return '?', False

    const = False
    t = type_str.strip()

    # Remove const qualifier
    if t.startswith('const '):
        t = t[len('const '):]
        const = True

    # Handle pointers
    if t.endswith('*'):
        return 'ptr64', False

    # Handle references
    elif t.endswith('&'):
        base_type = t[:-1].strip()
        if base_type.startswith('const '):
            base_type = base_type[len('const '):]
            const = True

        # Check if it's an enum
        if base_type in enums_map:
            mapped = enums_map[base_type].get('BaseType', '?')
            return mapped, not const

        # Check if it's a typedef
        if base_type in typedefs_map:
            return '?', not const  # Typedefs usually stay as '?'

        return map_type(base_type), not const

    # Check if it's an enum
    if t in enums_map:
        return enums_map[t].get('BaseType', '?'), False

    # Check if it's a typedef
    if t in typedefs_map:
        return '?', False  # Typedefs usually stay as '?'

    return map_type(t), False


def extract_text_from_description(description):
    """
    Extract text content from clang-doc's structured description format.
    Handles nested Children structures.
    """
    if not description:
        return ""

    texts = []

    def traverse(node):
        if isinstance(node, dict):
            kind = node.get('Kind', '')

            # Extract direct text
            if 'Text' in node:
                text = node['Text'].strip()
                if text:
                    texts.append(text)

            # Traverse children
            if 'Children' in node:
                for child in node['Children']:
                    traverse(child)
        elif isinstance(node, list):
            for item in node:
                traverse(item)

    traverse(description)
    return ' '.join(texts)


def extract_brief_description(description):
    """Extract the brief description from the function's Description field."""
    if not description or not isinstance(description, list):
        return None

    # Handle FullComment wrapper
    for item in description:
        if isinstance(item, dict) and item.get('Kind') == 'FullComment':
            children = item.get('Children', [])
            for child in children:
                if isinstance(child, dict) and child.get('Kind') == 'BlockCommandComment':
                    if child.get('Name') == 'brief':
                        return extract_text_from_description(child.get('Children', []))

    # Fallback: look directly for BlockCommandComment
    for item in description:
        if isinstance(item, dict) and item.get('Kind') == 'BlockCommandComment':
            if item.get('Name') == 'brief':
                return extract_text_from_description(item.get('Children', []))

    return None


def extract_param_descriptions(description):
    """Extract parameter descriptions from the function's Description field."""
    if not description or not isinstance(description, list):
        return {}

    param_descriptions = {}

    # Handle FullComment wrapper
    children_to_search = []
    for item in description:
        if isinstance(item, dict) and item.get('Kind') == 'FullComment':
            children_to_search = item.get('Children', [])
            break

    # Fallback: search description directly
    if not children_to_search:
        children_to_search = description

    for item in children_to_search:
        if isinstance(item, dict) and item.get('Kind') == 'ParamCommandComment':
            param_name = item.get('ParamName')
            if param_name:
                desc_text = extract_text_from_description(item.get('Children', []))
                if desc_text:
                    param_descriptions[param_name] = desc_text

    return param_descriptions


def extract_return_description(description):
    """Extract the return description from the function's Description field."""
    if not description or not isinstance(description, list):
        return None

    # Handle FullComment wrapper
    children_to_search = []
    for item in description:
        if isinstance(item, dict) and item.get('Kind') == 'FullComment':
            children_to_search = item.get('Children', [])
            break

    # Fallback: search description directly
    if not children_to_search:
        children_to_search = description

    for item in children_to_search:
        if isinstance(item, dict) and item.get('Kind') == 'BlockCommandComment':
            if item.get('Name') == 'return':
                return extract_text_from_description(item.get('Children', []))

    return None


def build_enums_map(yaml_data):
    """Build a map of enum names to their base types."""
    enums_map = {}

    if 'ChildEnums' in yaml_data:
        for enum in yaml_data['ChildEnums']:
            enum_name = enum.get('Name')
            base_type_info = enum.get('BaseType', {})
            base_type = base_type_info.get('Type', {}).get('Name', 'int32')

            if enum_name:
                enums_map[enum_name] = {
                    'BaseType': map_type(base_type),
                    'USR': enum.get('USR')
                }

    return enums_map


def build_typedefs_map(yaml_data):
    """Build a map of typedef names."""
    typedefs_map = {}

    if 'ChildTypedefs' in yaml_data:
        for typedef in yaml_data['ChildTypedefs']:
            typedef_name = typedef.get('Name')
            if typedef_name:
                typedefs_map[typedef_name] = {
                    'Underlying': typedef.get('Underlying', {}).get('Name', '?'),
                    'USR': typedef.get('USR')
                }

    return typedefs_map


def process_function(function, enums_map, typedefs_map, group_name=None):
    """Process a single function and convert it to the desired JSON format."""

    # Extract function name
    func_name = function.get('Name', 'Unknown')

    # Extract location info for group determination
    def_location = function.get('DefLocation', {})
    filename = def_location.get('Filename', '')

    # Determine group name from filename if not provided
    if not group_name and filename:
        base_name = os.path.splitext(os.path.basename(filename))[0]
        group_name = base_name.lower().capitalize()

    # Extract descriptions - handle both list and dict formats
    description = function.get('Description')
    if isinstance(description, dict):
        description = description.get('Children', [])
    elif not isinstance(description, list):
        description = []

    brief_desc = extract_brief_description(description)
    param_descriptions = extract_param_descriptions(description)
    return_desc = extract_return_description(description)

    # Process parameters
    param_types = []
    params = function.get('Params', [])

    for param in params:
        param_type_info = param.get('Type', {})
        param_type_name = param_type_info.get('QualName') or param_type_info.get('Name', '?')
        param_name = param.get('Name', 'unknown')

        # Convert type
        mapped_type, is_ref = convert_type(param_type_name, enums_map, typedefs_map)

        param_data = {
            'name': param_name,
            'type': mapped_type,
            'ref': is_ref
        }

        # Add description if available
        if param_name in param_descriptions:
            param_data['description'] = param_descriptions[param_name]

        param_types.append(param_data)

    # Process return type
    return_type_info = function.get('ReturnType', {}).get('Type', {})
    return_type_name = return_type_info.get('QualName') or return_type_info.get('Name', 'void')
    mapped_return_type, _ = convert_type(return_type_name, enums_map, typedefs_map)

    ret_type = {
        'type': mapped_return_type
    }

    if return_desc:
        ret_type['description'] = return_desc

    # Build final function data
    function_data = {
        'name': func_name,
        'funcName': func_name,
        'paramTypes': param_types,
        'retType': ret_type
    }

    if group_name:
        function_data['group'] = group_name

    if brief_desc:
        function_data['description'] = brief_desc

    return function_data


def filter_functions(functions, name_filter=None, file_prefix=None):
    """Filter functions by name or filename prefix."""
    filtered = []

    for func in functions:
        # Check name filter
        if name_filter and name_filter.lower() not in func.get('name', '').lower():
            continue

        # Check file prefix filter
        if file_prefix:
            def_location = func.get('DefLocation', {})
            filename = def_location.get('Filename', '')
            basename = os.path.basename(filename)

            if not basename.startswith(file_prefix):
                continue

        filtered.append(func)

    return filtered


def process_yaml_file(yaml_file, name_filter=None, file_prefix=None):
    """Process a single YAML file and extract functions."""
    with open(yaml_file, 'r') as f:
        yaml_data = yaml.safe_load(f)

    if not yaml_data:
        return []

    # Build lookup maps
    enums_map = build_enums_map(yaml_data)
    typedefs_map = build_typedefs_map(yaml_data)

    # Process functions
    all_functions = []

    if 'ChildFunctions' in yaml_data:
        for function in yaml_data['ChildFunctions']:
            # Apply filters at the raw level
            func_name = function.get('Name', '')
            def_location = function.get('DefLocation', {})
            filename = def_location.get('Filename', '')
            basename = os.path.basename(filename)

            # Check name filter
            if name_filter and name_filter.lower() not in func_name.lower():
                continue

            # Check file prefix filter
            if file_prefix and not basename.startswith(file_prefix):
                continue

            # Process the function
            func_data = process_function(function, enums_map, typedefs_map)
            all_functions.append(func_data)
            print(f'Processed: {func_name}')

    return all_functions


def main(input_path, output_file, name_filter=None, file_prefix=None):
    """Main function to process YAML files and generate JSON output."""
    all_exported_methods = []

    # Check if input is a file or directory
    input_path_obj = Path(input_path)

    if input_path_obj.is_file():
        # Process single YAML file
        all_exported_methods = process_yaml_file(input_path, name_filter, file_prefix)
    elif input_path_obj.is_dir():
        # Process all YAML files in directory
        for yaml_file in input_path_obj.glob('*.yaml'):
            print(f'\nProcessing: {yaml_file}')
            functions = process_yaml_file(yaml_file, name_filter, file_prefix)
            all_exported_methods.extend(functions)
    else:
        print(f"Error: {input_path} is neither a file nor a directory")
        return

    # Write output
    with open(output_file, 'w') as f:
        json.dump(all_exported_methods, f, indent=4)

    print(f'\nTotal functions exported: {len(all_exported_methods)}')
    print(f'Output written to: {output_file}')


def get_args():
    parser = argparse.ArgumentParser(
        description='Parse clang-doc YAML output and generate JSON for exported functions'
    )
    parser.add_argument(
        'input_path',
        help='Path to YAML file or directory containing YAML files'
    )
    parser.add_argument(
        'output_file',
        help='JSON file to output the processed results'
    )
    parser.add_argument(
        '--name-filter',
        '-n',
        help='Filter functions by name (case-insensitive substring match)',
        default=None
    )
    parser.add_argument(
        '--file-prefix',
        '-f',
        help='Filter functions by source filename prefix',
        default=None
    )
    return parser.parse_args()


if __name__ == "__main__":
    args = get_args()
    main(args.input_path, args.output_file, args.name_filter, args.file_prefix)