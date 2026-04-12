#!/usr/bin/env python3
"""Read vars.txt and add in the strings if they're present."""
import re
import sys
import struct
import string

NUM_TEXT_SECTIONS = 7
NUM_DATA_SECTIONS = 11
inputDol = None
dolSections = {}

def loadDol(path):
    global inputDol, dolSections
    inputDol = open(sys.argv[1], 'rb')

    # read the .text and .data offset, addrs, sizes.
    # we don't care about .bss or entry point.
    nWords = (NUM_TEXT_SECTIONS+NUM_DATA_SECTIONS)*3
    header = inputDol.read(nWords*4)
    header = struct.unpack('>%dI' % nWords, header)

    offsAddr = NUM_TEXT_SECTIONS+NUM_DATA_SECTIONS
    offsSize = offsAddr*2
    for i in range(NUM_TEXT_SECTIONS):
        dolSections['.text%d' % i] = {
            'offset':  header[i],
            'address': header[i+offsAddr],
            'size':    header[i+offsSize],
            'end':     header[i+offsAddr] + header[i+offsSize],
        }
    for i in range(NUM_DATA_SECTIONS):
        n = i+NUM_TEXT_SECTIONS
        dolSections['.data%d' % i] = {
            'offset':  header[n],
            'address': header[n+offsAddr],
            'size':    header[n+offsSize],
            'end':     header[n+offsAddr] + header[n+offsSize],
        }

    # leave inputDol open to read from

def _readString(offset):
    global inputDol
    inputDol.seek(offset)
    result = ''
    while len(result) < 1000:
        b = inputDol.read(1)
        if b == b'': return None # reached EOF
        try: b = chr(b[0])
        except UnicodeDecodeError: return None
        if b == '\0': break
        elif b in string.printable: result += b
        else: return None
    if len(result) < 5: return None
    result = result.replace('\n', '\\n')
    return result

def getString(address):
    """If this address points to a string, return the string.
    Otherwise, return None.
    """
    for i in range(NUM_DATA_SECTIONS):
        section = dolSections['.data%d' % i]
        if section['address'] <= address < section['end']:
            # this is in .data section. could be a string.
            offset = address - section['address']
            return _readString(offset+section['offset'])

    return None


def readVars(inputText):
    pat = re.compile(r'^(0x)?([0-9a-fA-F]+)' + # address
        r'\s+S' + # literal 'S'
        r'\s+(\S+)' + # section name
        r'\s+(\S+)' + # label
        r'(.*)$') # anyting else
    result = []
    for line in inputText.strip().split('\n'):
        parts = pat.match(line)
        if parts:
            address = int(parts.group(2), 16)
            section = parts.group(3)
            label = parts.group(4)
            misc = parts.group(5)
            strVal = getString(address)
            if strVal is None:
                result.append(line)
            else:
                result.append(f'{address:08x} S {section:<8s} {label} "{strVal}" {misc}')
        else: result.append(line)
    return result

def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} file.dol vars.txt")
        sys.exit(1)

    loadDol(sys.argv[1])
    with open(sys.argv[2], 'r') as f:
        lines = readVars(f.read())

    inputDol.close()
    for line in lines:
        print(line)

if __name__ == '__main__':
    main()
