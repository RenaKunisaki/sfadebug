#!/usr/bin/env python3
"""Parse splits.txt to populate a spreadsheet."""
import re
from pathlib import Path

re_file = re.compile(r'^(\S+):$')
re_section = re.compile(r'^\s+(\S+)\s+start:(\S+)\s+end:(\S+)$')

def main():
    with open('../config/GSAP01-DEBUG/splits.txt', 'rt') as file:
        curFile = None
        curDir  = None
        for line in file.readlines():
            fileName = re_file.match(line)
            section = re_section.match(line)
            if fileName and fileName.group(1) != 'Sections':
                curDir  = list(Path(fileName.group(1)).parts)
                curFile = curDir.pop()
                curDir  = '/' + ('/'.join(curDir))
            elif section:
                secName  = section.group(1)
                secStart = section.group(2)
                secEnd   = section.group(3)
                secLen   = "%X" % (int(secEnd,0) - int(secStart,0))
                print(':'.join([
                    curDir, curFile, secName,
                    '"'+secStart[2:]+'"', '"'+secLen+'"']))

if __name__ == '__main__':
    main()
