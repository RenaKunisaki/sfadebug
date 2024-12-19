#!/usr/bin/env python3
"""Parse splits.txt and report overlaps."""
import sys

def parseSectionLine(line):
    """Parse a section definition."""
    parts = line[1:].split() # skip the leading tab
    sec = parts.pop(0)
    fields = {}
    for part in parts:
        name, val = part.split(':', maxsplit=1)
        fields[name] = int(val, 0)
    return sec, fields

def parseFile(file):
    """Parse the splits.txt file."""
    curFileName = None
    sections = []
    while True:
        line = file.readline()
        # a blank line will be '\n'
        # getting the empty string indicates EOF
        if line == '': break

        # a line starting with a tab denotes a section
        # of the previously specified file
        elif line.startswith('\t'):
            if curFileName is None: continue
            # skip this pseudo-file
            if curFileName == 'Sections': continue
            sec, fields = parseSectionLine(line)
            sections.append((
                curFileName+':'+sec, fields['start'], fields['end']-1))

        elif ':' in line: # specifies file name
            curFileName, _ = line.split(':', maxsplit=1)
    return sections

def printOverlaps(items):
    """Given items of the form (name, start, end),
    print all overlapping items.
    Note these ranges are inclusive, so ('a', 1, 3)
    is considered overlapping with ('b', 3, 4).
    """
    for i in range(len(items)):
        name_i, start_i, end_i = items[i]
        for j in range(i + 1, len(items)):
            name_j, start_j, end_j = items[j]
            if not (end_i < start_j or end_j < start_i):
                print("Overlap 0x%X - 0x%X / 0x%X - 0x%X (%s / %s)" % (
                    start_i, end_i, start_j, end_j, name_i, name_j))

def main():
    with open(sys.argv[1], 'rt') as file:
        sections = parseFile(file)
        printOverlaps(sections)

if __name__ == '__main__':
    main()
