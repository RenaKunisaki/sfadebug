#!/usr/bin/env python3
"""Parse splits.txt to locate an address."""
import sys
import re
from pathlib import Path

re_file = re.compile(r'^(\S+):$')
re_section = re.compile(r'^\s+(\S+)\s+start:(\S+)\s+end:(\S+)$')

def main(args):
    if len(args) < 2:
        print(f"Usage: {sys.argv[0]} splits.txt address")
        sys.exit(1)
    target = int(args[1], 16)
    sections = []
    with open(args[0], 'rt') as file:
        curFile = None
        curDir  = None
        for line in file.readlines():
            fileName = re_file.match(line)
            section = re_section.match(line)
            if fileName and fileName.group(1) != 'Sections':
                #curDir  = list(Path(fileName.group(1)).parts)
                #curFile = curDir.pop()
                #curDir  = '/' + ('/'.join(curDir))
                curFile = fileName.group(1)
            elif section:
                secName  = section.group(1)
                secStart = int(section.group(2), 0)
                secEnd   = int(section.group(3), 0)
                #secLen   = "%X" % (int(secEnd,0) - int(secStart,0))
                #print(':'.join([
                #    curDir, curFile, secName,
                #    '"'+secStart[2:]+'"', '"'+secLen+'"']))
                if secStart <= target < secEnd:
                    print("0x%X: in %s %s (0x%X - 0x%X)" % (target,
                        curFile, secName, secStart, secEnd))
                    return
                sections.append({
                    'start': secStart,
                    'end':   secEnd,
                    'file':  curFile,
                    'name':  secName
                })

    # if we get here, we didn't find it
    sections.sort(key=lambda s: s['start'])
    for i in range(len(sections)-1):
        sec1, sec2 = sections[i], sections[i+1]
        if sec1['end'] <= target < sec2['start']:
            print("0x%X: between %s %s (0x%X - 0x%X) and %s %s (0x%X - 0x%X)" % (
                target,
                sec1['file'], sec1['name'], sec1['start'], sec1['end'],
                sec2['file'], sec2['name'], sec2['start'], sec2['end']))
            return
    print("0x%X: not found (section range is 0x%X - 0x%X)" % (target,
        sections[0]['start'], sections[-1]['end']))

if __name__ == '__main__':
    main(sys.argv[1:])
