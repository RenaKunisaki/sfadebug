#!/usr/bin/env python
""" Read a vars.txt file. For each symbol name, check a map
file to find the correct source file name.
"""
import sys
import re
from pathlib import Path

re_file = re.compile(r"^/*(.+)$")
re_sym  = re.compile(r'^([0-9a-fA-F]+) (.) (\S+)\s+(.+)$')
re_map  = re.compile(r'^\s+........ ...... ........\s+\S+\s+(\S+)\s+\S+\s+(.+)$')

funcs = {} # func name => info
filePaths = {} # file name => path

def findFiles(dir:Path, _depth=0):
    BASE_DIR = "src/"
    assert _depth < 10
    for file in dir.iterdir():
        if file.is_dir():
            findFiles(file, _depth+1)
        else:
            path = str(file)
            if path.startswith(BASE_DIR):
                path = path[len(BASE_DIR):]
            filePaths[file.name] = path

def readMapFile(inFile):
    for line in inFile.readlines():
        fields = re_map.match(line)
        if not fields: continue
        funcName, fileName = fields.groups()
        funcs[funcName] = {
            'file': fileName,
        }

def readVarsTxt(inFile):
    curFileName = '?'
    for line in inFile.readlines():
        if line.startswith('/'):
            # every such line should start with two slashes
            # but just to be sure, strip all leading slashes
            # and then add one
            mLine = re_file.match(line)
            if mLine: mLine = mLine.group(1)
            else: mLine = line
            curFileName = '/'+mLine
        else:
            mLine = re_sym.match(line)
            addr, symType, section, name = mLine.groups()
            func = funcs.get(name, {})
            func['addr'] = addr
            func['name'] = name
            func['section'] = section
            if 'file' not in func: func['file'] = curFileName

def printFuncs():
    # sort functions into files
    files = {}
    for name, func in funcs.items():
        if 'addr' not in func: continue # we don't have this function
        fileName = func['file']
        if fileName not in files:
            files[fileName] = {
                'funcs': [],
            }
        file = files[fileName]
        file['funcs'].append(func)

    # print each non-empty file
    for fileName, file in files.items():
        if len(file['funcs']) > 0:
            realName = filePaths.get(fileName, fileName)
            print(f"/{realName}")
            fileFuncs = []
            for func in file['funcs']:
                fileFuncs.append(func)

            for func in sorted(fileFuncs, key=lambda f: int(f['addr'], 16)):
                print(f"{func['addr']} S {func['section']} {func['name']}")

def main():
    if len(sys.argv) < 3:
        print("Usage:", sys.argv[0], "vars.txt symbols.map")
        return
    findFiles(Path('src/dolphin'))
    findFiles(Path('musyx'))
    with open(sys.argv[2], 'rt') as inFile:
        readMapFile(inFile)
    with open(sys.argv[1], 'rt') as inFile:
        readVarsTxt(inFile)
    printFuncs()

if __name__ == '__main__':
    main()
