#!/usr/bin/env python3
import re
import sys

def convert_format(input_text):
    output_lines = []
    current_file = None

    for line in input_text.strip().split('\n'):
        # Check if this is a file header line (ends with colon)
        if line and not line.startswith('\t') and line.endswith(':'):
            current_file = line.rstrip(':')
        # Check if this is a section line (starts with tab)
        elif line.startswith('\t') and current_file:
            # Parse the section line
            # Format: .section    start:0xADDR end:0xADDR
            match = re.match(r'\t(\.\w+)\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)', line)
            if match:
                section = match.group(1)
                start_addr = match.group(2)
                end_addr = match.group(3)

                output_lines.append(f"/* {start_addr} */ {current_file} {section} start")
                output_lines.append(f"/* {end_addr} */ {current_file} {section} end")

    return '\n'.join(output_lines)

def main():
    if len(sys.argv) > 1:
        # Read from file
        with open(sys.argv[1], 'r') as f:
            input_text = f.read()
    else:
        # Read from stdin
        input_text = sys.stdin.read()

    result = convert_format(input_text)
    print(result)

if __name__ == '__main__':
    main()
