#!/usr/bin/env python3
import re
import sys

def parseSplits(inputText):
    splits = {}
    curFile = None

    for line in inputText.strip().split('\n'):
        # Check if this is a file header line (ends with colon)
        if line and not line.startswith('\t') and line.endswith(':'):
            curFile = line.rstrip(':')

        # Check if this is a section line (starts with tab)
        elif line.startswith('\t') and curFile:
            # Parse the section line
            # Format: .section    start:0xADDR end:0xADDR
            match = re.match(
                r'\t(\.\w+)\s+start:(0x[0-9A-Fa-f]+)\s+end:(0x[0-9A-Fa-f]+)', line)
            if match:
                section   = match.group(1)
                startAddr = int(match.group(2), 0)
                endAddr   = int(match.group(3), 0)

                if startAddr in splits:
                    print(f"* duplicate start address {startAddr:08x}")
                splits[startAddr] = {
                    'start': startAddr,
                    'end':   endAddr,
                    'name':  section,
                    'file':  curFile,
                }

    return splits

def parseSymbols(inputText):
    symbols = {}
    for line in inputText.strip().split('\n'):
        match = re.match(
            r'^(\S+) = (\.[^:]+):(0x[0-9A-Fa-f]+);.*(size:0x[0-9A-Fa-f]+)', line)
        if match:
            name      = match.group(1)
            section   = match.group(2)
            startAddr = int(match.group(3), 0)
            size      = int(match.group(4)[5:], 0)
            if startAddr in symbols:
                print(f"* duplicate symbol address {startAddr:08x}")
            symbols[startAddr] = {
                'start':   startAddr,
                'end':     startAddr+size,
                'section': section,
                'name':    name,
            }
    return symbols

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} dir-with-splits.txt")
        sys.exit(1)

    # read splits.txt and symbols.txt
    with open(sys.argv[1] + '/splits.txt', 'r') as f:
        sections = parseSplits(f.read())

    with open(sys.argv[1] + '/symbols.txt', 'r') as f:
        symbols = parseSymbols(f.read())

    # print sections in address order
    prevAddr = 0x80000000
    prevSection = 'N/A'
    sectionStarts = sorted(sections.keys())
    for addr in sectionStarts:
        gap = addr - prevAddr
        if gap > 0: print(f"{prevAddr:08x} F {prevSection:<8s} ?")
        section = sections[addr]
        print(f"{addr:08x} F {section['name']:<8s} {section['file']} ------------------------------------------------")
        prevAddr = section['end']
        prevSection = section['name']

    # print symbols in address order
    prevAddr = 0x80000000
    symbolStarts = sorted(symbols.keys())
    for addr in symbolStarts:
        gap = addr - prevAddr
        if gap > 0: print(f"{prevAddr:08x} S")
        symbol = symbols[addr]
        print(f"{addr:08x} S {symbol['section']:<8s} {symbol['name']}")
        prevAddr = symbol['end']

if __name__ == '__main__':
    main()
