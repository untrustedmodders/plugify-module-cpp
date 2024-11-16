#!/usr/bin/python3
import argparse
import glob
import json
import os
import sys

from cxxheaderparser import simple


def map_type(type: str):
    switch_dict = {
        'plg::string': 'string',
        'plg::vector<plg::string>': 'string[]',

        # 'const char*': 'string',
        # 'char*': 'string',
        # 'const char**': 'string[]',
        # 'char**': 'string[]',

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
    return switch_dict.get(type, '?')


def convert_type(type: str):
    const = False
    if type.startswith('const '):
        type = type[len('const '):]
        const = True
    if type.endswith('*'):
        return 'ptr64', False
    elif type.endswith('&'):
        return [map_type(type[:-1]), not const]
    return map_type(type), False


def main(folder_dir, output_file):
    if not folder_dir:
        folder_dir = os.getcwd()
    else:
        if not os.path.isdir(folder_dir):
            print(f'Folder with headers not exists {folder_dir}')
            return 1
    exported_methods = []
    search_pattern = os.path.join(folder_dir, '*.cpp')
    file_list = glob.glob(search_pattern)
    for file_path in file_list:
        with open(file_path, 'r') as file:
            file_contents = file.read()
            contents = file_contents.replace('extern "C"', '').replace('PLUGIN_API', '')
            parsed = simple.parse_string(contents, options=None)
            for function in parsed.namespace.functions:
                ret_type = convert_type(function.return_type.format())[0]
                obj_ret = ret_type == 'void'
                param_types = []
                first_param = True
                for param in function.parameters:
                    type = convert_type(param.type.format())
                    if obj_ret and first_param and (type[0] == 'string' or '[]' in type[0]) and type[1] is True:
                        ret_type = type[0]
                        first_param = False
                        continue
                    # print(param.type.format())
                    param_types.append({
                        'name': param.name.format(),
                        'type': type[0],
                        'ref': type[1],
                    })
                    first_param = False
                print(function.name.format())
                exported_methods.append({
                    'name': function.name.format(),
                    'funcName': function.name.format(),
                    'paramTypes': param_types,
                    'retType': {
                        'type': ret_type,
                    }
                })

    if not output_file:
        print(json.dumps(exported_methods, indent=2))
    else:
        with open(output_file, 'w') as json_file:
            json.dump(exported_methods, json_file, indent=2)


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('folder')
    parser.add_argument('output')
    return parser.parse_args()


if __name__ == '__main__':
    args = get_args()
    sys.exit(main(args.folder, args.output))
