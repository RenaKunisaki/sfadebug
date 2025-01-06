#!/usr/bin/env python3
"""Read the output of `dtk -L debug --no-color dol split`
and report the dependency chains.
"""
import sys
import re

re_depLine = re.compile(r'Adding dependency (\S+) \((0x........)\) \-\> (\S+) \((0x........)\)')
deps = {}
isDepended = set()
fileAddrs = {} # addr => filename

def procLine(line):
    fields = re_depLine.search(line)
    if fields is None: return
    file1 = fields.group(1)
    addr1 = fields.group(2)
    file2 = fields.group(3)
    addr2 = fields.group(4)

    if fileAddrs.get(addr1, file1) != file1:
        print("Address %s belongs to multiple files (%s, %s)" % (
            addr1, file1, fileAddrs.get(addr1, '?')
        ))
    if fileAddrs.get(addr2, file2) != file2:
        print("Address %s belongs to multiple files (%s, %s)" % (
            addr2, file2, fileAddrs.get(addr2, '?')
        ))
    fileAddrs[addr1] = file1
    fileAddrs[addr2] = file2

    if file1 not in deps:
        deps[file1] = []
    isDepended.add(file2)
    deps[file1].append(file2)

def printChain(file, seen=None, _depth=0):
    if file is None: return
    #assert _depth < 200
    if seen is None: seen = set()
    for dest in deps.get(file, []):
        if dest in seen:
            print("%s **** %s (%s) (CYCLE)" % (' ' * (_depth+1), dest,
                fileAddrs.get(dest, '?')))
            break
        seen.add(dest)
        print("%s%s (%s)" % (
            ' ' * (_depth+1),
            dest, fileAddrs.get(dest, '?'),
        ))
        printChain(dest, seen, _depth+1)

def printDeps():
    for k in deps.keys():
        if k in isDepended: continue
        print(k, fileAddrs.get(k, '?'))
        printChain(k)

def main(logPath):
    with open(logPath, 'rt') as file:
        for line in file.readlines():
            procLine(line)
    printDeps()

if __name__ == '__main__':
    main(sys.argv[1])
