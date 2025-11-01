#!/usr/bin/env python3
"""
Convert JSON manifest to README markdown table format
"""

import json
import sys
from typing import Dict, List, Any


def format_type(param_type: str, is_ref: bool = False) -> str:
    """Format a parameter type for display in signature"""
    # Add reference indicator if needed
    if is_ref:
        return f"{param_type}&"
    return param_type


def format_signature(method: Dict[str, Any]) -> str:
    """Format method signature from JSON data"""
    func_name = method.get('funcName', method.get('name', 'Unknown'))

    # Format parameters
    params = []
    for param in method.get('paramTypes', []):
        param_name = param.get('name', '')
        param_type = param.get('type', 'any')
        is_ref = param.get('ref', False)

        formatted_type = format_type(param_type, is_ref)
        params.append(f"{param_name}: {formatted_type}")

    # Format return type
    ret_type = method.get('retType', {})
    return_type = ret_type.get('type', 'void')

    # Construct signature
    signature = f"{func_name}({', '.join(params)}): {return_type}"

    return signature


def escape_pipe(text: str) -> str:
    """Escape pipe characters in text for markdown tables"""
    return text.replace('|', '\\|')


def generate_markdown_table(methods: List[Dict[str, Any]], group_by: bool = False) -> str:
    """Generate markdown table from methods list"""
    lines = []

    if group_by:
        # Group methods by their 'group' field
        grouped = {}
        for method in methods:
            group = method.get('group', 'Other')
            if group not in grouped:
                grouped[group] = []
            grouped[group].append(method)

        # Generate table for each group
        for group_name in sorted(grouped.keys()):
            lines.append(f"\n### {group_name}\n")
            lines.append(f"<details><summary>Open methods list</summary> \n")
            lines.append("| Function | Signature | Description |")
            lines.append("|----------|-----------|-------------|")

            for method in grouped[group_name]:
                name = method.get('name', 'Unknown')
                signature = format_signature(method)
                description = method.get('description', '')

                # Escape pipe characters
                name = escape_pipe(name)
                signature = escape_pipe(signature)
                description = escape_pipe(description)

                lines.append(f"| {name} | `{signature}` | {description} |")
            
            lines.append("\n</details>\n")
    else:
        # Single table for all methods
        lines.append(f"<details><summary>Open methods list</summary> \n")
        lines.append("| Function | Signature | Description |")
        lines.append("|----------|-----------|-------------|")

        for method in methods:
            name = method.get('name', 'Unknown')
            signature = format_signature(method)
            description = method.get('description', '')

            # Escape pipe characters
            name = escape_pipe(name)
            signature = escape_pipe(signature)
            description = escape_pipe(description)

            lines.append(f"| {name} | `{signature}` | {description} |")
        
        lines.append("\n</details>\n")
    return '\n'.join(lines)


def main():
    """Main function to convert JSON to README table"""

    # Check command line arguments
    if len(sys.argv) < 2:
        print("Usage: python json_to_readme.py <input.json> [output.md]")
        print("\nOptions:")
        print("  --group    Group methods by their 'group' field")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = None
    group_by = False

    # Parse arguments
    for i, arg in enumerate(sys.argv[2:], 2):
        if arg == '--group':
            group_by = True
        else:
            output_file = arg

    # If no output file specified, use input filename with .md extension
    if not output_file:
        output_file = input_file.rsplit('.', 1)[0] + '_methods.md'

    try:
        # Read JSON file
        with open(input_file, 'r', encoding='utf-8') as f:
            data = json.load(f)

        # Extract methods
        methods = data.get('methods', [])

        if not methods:
            print("Warning: No methods found in JSON file")
            sys.exit(1)

        # Generate markdown table
        markdown_content = f"# API Methods\n\n"
        markdown_content += f"Generated from: {input_file}\n\n"
        markdown_content += f"Total methods: {len(methods)}\n\n"
        markdown_content += generate_markdown_table(methods, group_by)

        # Write to output file
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(markdown_content)

        print(f"Successfully converted {len(methods)} methods")
        print(f"Output written to: {output_file}")

        # Print summary of groups if available
        groups = set(m.get('group', 'Other') for m in methods)
        if len(groups) > 1:
            print(f"Found {len(groups)} groups: {', '.join(sorted(groups))}")
            print("Tip: Use --group flag to group methods in the output")

    except FileNotFoundError:
        print(f"Error: File '{input_file}' not found")
        sys.exit(1)
    except json.JSONDecodeError as e:
        print(f"Error: Invalid JSON in file '{input_file}': {e}")
        sys.exit(1)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)


# Alternative function for direct string conversion (can be imported and used in other scripts)
def json_string_to_markdown_table(json_string: str, group_by: bool = False) -> str:
    """Convert JSON string directly to markdown table string"""
    try:
        data = json.loads(json_string)
        methods = data.get('methods', [])

        if not methods:
            return "No methods found in JSON"

        return generate_markdown_table(methods, group_by)
    except json.JSONDecodeError as e:
        return f"Error parsing JSON: {e}"
    except Exception as e:
        return f"Error: {e}"


if __name__ == "__main__":
    main()