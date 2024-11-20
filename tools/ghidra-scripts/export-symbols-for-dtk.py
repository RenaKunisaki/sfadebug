#Export symbol info for decomp-toolkit.
#Given a directory, writes a splits.txt file and a set of
#source files containing decompiled code.
#Source file names are taken from function names.
#Functions without a name tag are written to the file 'unknown'.
#Asks for two directories. The first is where to output the
#generated source files. The second is the location of the dtk
#config files (symbols.txt, etc).
#@author Rena
#@category Functions
#@keybinding
#@menupath
#@toolbar

import jarray
import os
import re
from array import array
from ghidra.app.decompiler import DecompInterface, DecompileOptions
#from ghidra.util.task import ConsoleTaskMonitor
from ghidra.program.model.listing import VariableUtilities
from ghidra.program.model.symbol import SourceType, Namespace
from ghidra.util.exception import UsrException, DuplicateNameException
from ghidra.program.model.data import StructureDataType, DataTypeConflictHandler, PointerDataType
from ghidra.app.plugin.core.analysis import AutoAnalysisManager
from ghidra.app.plugin.core.analysis import ConstantPropagationAnalyzer
from ghidra.util.classfinder import ClassSearcher
from ghidra.program.model.symbol import SourceType, RefType
from ghidra.program.util import SymbolicPropogator
import string
from java.lang import NullPointerException

###################################### Script parameters

SECTION_NAMES = (
    'text', # must be first
    'bss',
    'sbss',
    'data',
    'sdata',
    'rodata',
    'init',
    'ctors',
    'dtors',
    'sdata2',
)
SECTION_ALIGN = {
    'text':    4,
    'bss':     8,
    'sbss':   32,
    'data':   32,
    'sdata':  32,
    'rodata':  4,
    'ctors':   4,
    'dtors':   4,
    'sdata2':  4,
}
SYMBOL_MIN_ADDR = 0x80003100
SYMBOL_MAX_ADDR = 0x81800000

ASSERT_FUNCS = {
    # address: (arg, arg...)
    # only 'file' arg is currently used
    0x80009968: ('msg',), # OSReport
    0x800099f8: ('file', 'line', 'msg'), # OSPanic
}

re_stringRef = re.compile(r's_([0-9a-zA-Z_]+)_([0-9a-fA-F]{8})')
re_symbolsTxt = re.compile(r'^(\S+)\s*=\s*([^\s:]+):(\S+);\s*//\s*(.+)$')
re_splitFileName = re.compile(r'^([^\.]+)')

###################################### General Ghidra stuff

listing = currentProgram.getListing()
AF      = currentProgram.getAddressFactory()
DT      = currentProgram.getDataTypeManager()
FM      = currentProgram.getFunctionManager()
mem     = currentProgram.getMemory()
tPointer= currentProgram.getDataTypeManager().getDataType("/pointer")
symTab  = currentProgram.getSymbolTable()
StringColumnDisplay  = ghidra.app.tablechooser.StringColumnDisplay
AddressableRowObject = ghidra.app.tablechooser.AddressableRowObject
TableChooserExecutor = ghidra.app.tablechooser.TableChooserExecutor

ifc = DecompInterface()
opts = DecompileOptions()
opts.setCommentStyle(DecompileOptions.CommentStyleEnum.CStyle)
opts.setNoCastPrint(False)
opts.setConventionPrint(False)
opts.setSimplifyDoublePrecision(True)
opts.setEliminateUnreachable(False)
opts.setEOLCommentIncluded(True)
opts.setHeadCommentIncluded(True)
opts.setPLATECommentIncluded(True)
opts.setPOSTCommentIncluded(True)
opts.setPRECommentIncluded(True)
ifc.toggleSyntaxTree(False) # give raw C code
ifc.toggleCCode(True) # yes, give C code
ifc.setOptions(opts)
ifc.openProgram(currentProgram)

def addrToInt(addr):
    """Convert Address to integer."""
    return int(str(addr), 16)

def intToAddr(addr):
    """Convert integer to Address."""
    return AF.getAddress("0x%08X" % addr)

def checkCanceled():
    if monitor.isCancelled(): raise Exception("Cancelled")

def readString(addr, length=None, maxLength=1000):
    """Read null-terminated or fixed-length string from address.

    Return string and length.
    """
    if type(addr) is int:
        addr = intToAddr(addr)
    resLen = 0
    if length is not None:
        data = jarray.zeros(length, "b")
        mem.getBytes(addr, data)
        resLen = length
    else:
        data = []
        while len(data) < maxLength:
            resLen += 1
            try: b = mem.getByte(addr)
            except ghidra.program.model.mem.MemoryAccessException: break
            if b == 0: break
            data.append(b)
            addr = addr.add(1)
    return "".join(map(lambda c: chr(c) if c >= 0x20 and c <= 0x7E else '', data)), resLen

def getCodeUnitContaining(address):
    return currentProgram.getListing().getCodeUnitAt(address)

def getConstantAnalyzer(program):
    mgr = AutoAnalysisManager.getAnalysisManager(program)
    analyzers = ClassSearcher.getInstances(ConstantPropagationAnalyzer)
    for analyzer in analyzers:
        if analyzer.canAnalyze(program):
            return mgr.getAnalyzer(analyzer.getName())
    return None

def analyzeFunction(function, monitor):
    program = function.getProgram()
    analyzer = getConstantAnalyzer(program)
    symEval = SymbolicPropogator(program)
    symEval.setParamRefCheck (True)
    symEval.setReturnRefCheck(True)
    symEval.setStoredRefCheck(True)
    analyzer.flowConstants(program, function.getEntryPoint(), function.getBody(),
        symEval, monitor)
    return symEval

def getSectionTypeAt(addr):
    # note: bss can also be sbss
    # data can also be sdata, etc
    mem = getMemoryBlock(intToAddr(addr))
    if mem is None: return None
    name = str(mem.getName())
    if name.startswith('.'): return name[1:]

    #if mem.isExecute(): return 'text'
    #if not mem.isInitialized(): return 'bss'
    #if not mem.isWrite(): return 'rodata'
    #return 'data'
    return None

###################################### tagging functions

# used to track cases where the same file name appears
# multiple times.
FILE_NAME_STRINGS = {} # addr => name

def findCall(caller, addrCall):
    """Scan through 'caller' and find the first address
    at which it calls/jumps to 'addrCall'.
    addrCall should be an Address object."""
    addrStart = caller.body.minAddress
    addrEnd   = caller.body.maxAddress
    addressSetView = AF.getAddressSet(addrStart, addrEnd)
    instrs = listing.getInstructions(addressSetView, True)
    for i, instr in enumerate(instrs):
        for addrDst in instr.getFlows():
            if addrDst == addrCall:
                return instr.getAddress()
    return None

def assignTagsFromCall(funcAddr, paramIdx):
    """Check every function that calls the function at
    'funcAddr'. Retrieve the source file name from the
    parameter 'paramIdx' and tag the calling function
    with that name.
    """
    addrObj = intToAddr(funcAddr)
    func = getFunctionAt(addrObj)
    monitor.setMessage("Finding calls to " + str(func.getName()))
    for caller in func.getCallingFunctions(monitor):
        # find where exactly this is called from
        callAddr = findCall(caller, addrObj)
        if callAddr is None: continue

        # extract the desired parameter from that call
        prop  = analyzeFunction(caller, monitor)
        instr = listing.getCodeUnitAt(callAddr)
        # XXX hardcoded register for PPC
        val = prop.getRegisterValue(callAddr,
            instr.getRegister('r%d' % (paramIdx + 3)))
        if val is None:
            print("[!] Can't find param for call to %s at 0x%X" % (
                str(func.getName()), addrToInt(callAddr)))
            continue
        val = val.getValue() & 0xFFFFFFFF

        # the value should be the address of a string
        fileName, nameLen = readString(intToAddr(val))
        oldName = fileName
        if val in FILE_NAME_STRINGS:
            fileName = FILE_NAME_STRINGS[val]

        # see if this name appears at another address
        for nameAddr, nameVal in FILE_NAME_STRINGS.items():
            if nameVal == fileName and nameAddr != val:
                print("[!] Multiple instances of file name: %s (0x%X, 0x%X)" % (
                    fileName, val, nameAddr))
                # stuff the address in to distinguish it
                nameStart = re_splitFileName.match(fileName).group(1)
                fileName = '%s.%08x%s' % (nameStart, val,
                    fileName[len(nameStart):])
                #print(" => %s" % fileName)
        FILE_NAME_STRINGS[val] = fileName

        # tag the caller with this name
        if fileName != oldName: caller.removeTag(oldName)
        caller.addTag(fileName)

def assignTagsToFunctions():
    """For each function listed in ASSERT_FUNCS which has
    a 'file' parameter, iterate all calls to it.
    Tag the calling functions with that name.
    """
    for addr, params in ASSERT_FUNCS.items():
        for i, param in enumerate(params):
            if param == 'file':
                assignTagsFromCall(addr, i)

###################################### symbols.txt

SYMBOLS_TXT_DATA_TYPE_MAP = {
    '1byte':  'byte',
    '2byte':  'word',
    '4byte':  'dword',
    '8byte':  'qword',
    'double': 'double',
    'float':  'float',
    # if no 'data' param, guess from the size
    1: 'byte',
    2: 'word',
    4: 'dword',
    8: 'double', # qword doesn't exist?
}
GENERIC_FUNC_NAME_PREFIXES = ('FUN_', 'unk_', 'fn', 'lbl_')

def readSymbolsTxt(path):
    symbols = {}
    with open(path, 'r') as file:
        for line in file.readlines():
            com = line.find('#')
            if com >= 0: line = line[0:com]
            parts = re_symbolsTxt.match(line)
            if parts is None: continue
            name   = parts.group(1)
            sec    = parts.group(2)
            addr   = parts.group(3)
            params = parts.group(4)
            addr   = int(addr, 0)
            params = params.split()
            if name in symbols:
                print("[!] Duplicate symbol name: "+name)
            sym = {
                'name':    name,
                'address': addr,
                'section': sec,
            }
            symbols[name] = sym
            #symbols[addr] = sym
            if addr == 0x802D0240:
                print(" *** adding symbols.txt %08X: %s" % (
                    addr, name))
            for param in params:
                param = param.split(':')
                if param[0] == 'size': param[1] = int(param[1], 0)
                try: sym[param[0]] = param[1]
                except IndexError: sym[param[0]] = True
    return symbols

def correctSymbolSizes(symbols):
    """for each symbol, check if we have a known size in
    Ghidra and if so, override the symbol size from that."""
    for name, sym in symbols.items():
        addr    = sym['address']
        addrObj = intToAddr(addr)
        addrMin = None
        addrMax = None
        unit    = getFunctionContaining(addrObj)
        if unit is None:
            unit = getDataContaining(addrObj)
            if unit is None: continue
            addrMin = addrToInt(unit.getMinAddress())
            addrMax = addrToInt(unit.getMaxAddress())
        else: # is function
            addrMin = addrToInt(unit.body.minAddress)
            addrMax = addrToInt(unit.body.maxAddress)
        sym['size'] = addrMax - addrMin

def applySymbolsTxt(symbols):
    for name, sym in symbols.items():
        addr    = sym['address']
        aEnd    = addr + sym.get('size', 1) - 1
        addrObj = intToAddr(addr)
        addrMin = None
        addrMax = None
        unit    = getFunctionContaining(addrObj)
        if unit is None:
            unit = getDataContaining(addrObj)
            if unit is not None:
                addrMin = addrToInt(unit.getMinAddress())
                addrMax = addrToInt(unit.getMaxAddress())
        else: # is function
            addrMin = addrToInt(unit.body.minAddress)
            addrMax = addrToInt(unit.body.maxAddress)

        if unit is not None:
            # temporarily muted to reduce spam
            #if addrMin != addr or addrMax != aEnd:
            #    print("[!] Symbol conflict at 0x%08X - 0x%08X (%s, %s, 0x%08X - 0x%08X )" % (
            #        addr, aEnd, name, sym['type'], addrMin, addrMax))

            # set function name if current one is generic
            func = getFunctionContaining(addrObj)
            if func is not None and not name.startswith(GENERIC_FUNC_NAME_PREFIXES):
                oldName = str(func.name)
                if name != oldName and (
                    (oldName.startswith(GENERIC_FUNC_NAME_PREFIXES)
                    or re.match(r'[0-9a-fA-F]+$', oldName))):
                        func.setName(name, SourceType.IMPORTED)
                        # preserve old name in a comment
                        if not oldName.startswith(GENERIC_FUNC_NAME_PREFIXES):
                            comment = getPlateComment(intToAddr(addrMin))
                            comment = comment.text if comment else ''
                            comment = list(comment.split('\n'))
                            if comment[0].startswith('aka: '):
                                comment.pop(0) # remove previous
                            comment.insert(0, "aka: "+oldName)
                            setPlateComment(intToAddr(addrMin), '\n'.join(comment))
        else:
            if sym['type'] == 'function':
                func = createFunction(addrObj, name)
                fEnd = addrToInt(func.body.maxAddress)
                if fEnd != aEnd:
                    print(("[!] Function at 0x%08X (%s) length is 0x%X, file says 0x%X") % (
                        addr, name, (fEnd-addr)+1, sym['size']))
            else:
                createLabel(addrObj, name, True, SourceType.IMPORTED)
                typ = sym.get('data', None)
                if typ == 'string':
                    createAsciiString(addrObj, sym['size'])
                else:
                    typ = SYMBOLS_TXT_DATA_TYPE_MAP.get(typ, None)
                    if typ is None:
                        typ = SYMBOLS_TXT_DATA_TYPE_MAP.get(
                            sym['size'], 'byte')
                    try: dType = getDataTypes(typ)[0]
                    except IndexError:
                        print("[!] Data type '%s' not found" % str(typ))
                        continue
                    nElems = sym['size'] // dType.getLength()
                    #print("name = %s typ = %s len = %d / %d = %d" % (name,
                    #    typ, sym['size'], dType.getLength(), nElems))
                    try:
                        if nElems > 1: # lol
                            listing.createData(addrObj, dType, nElems)
                        else: createData(addrObj, dType)
                    except ghidra.program.model.util.CodeUnitInsertionException:
                        print("[!] Symbol conflict at 0x%08X - 0x%08X (%s, %s)" % (
                            addr, aEnd, name, sym['type']))

IGNORE_FIELDS = (
    'data', 'type', 'address', 'section', 'name')
TYPE_NAME_MAP = {
    'undefined':  'byte',
    'undefined1': 'byte',
    'undefined2': '2byte',
    'undefined4': '4byte',
    'undefined8': '8byte',
    'pointer':    '4byte',
    's8':         'byte',
    'u8':         'byte',
    'char':       'byte',
    'bool':       'byte',
    'BOOL':       '4byte',
    's16':        'short',
    'u16':        '2byte',
    's32':        'int',
    'u32':        '4byte',
    's64':        '8byte',
    'u64':        '8byte',
}
VALID_DATA_TYPES = ('byte', '2byte', '4byte', '8byte',
    'int', 'short', 'float', 'double', 'string', 'wstring',
    'string_table', 'wstring_table')
def writeSymbolsTxt(outPath, files, symbols):
    # build a map of address => file/section
    addrMap = [] # (start, end, file, sectionName)
    for name, srcFile in files.items():
        for secName in SECTION_NAMES:
            if secName not in srcFile: continue
            sec = srcFile[secName]
            aMin = sec['min']
            aMax = sec['max']
            addrMap.append((aMin, aMax, srcFile, secName))

    monitor.setIndeterminate(False)
    monitor.setMessage("Writing symbols...")
    monitor.setProgress(0)
    monitor.setMaximum(SYMBOL_MAX_ADDR - SYMBOL_MIN_ADDR)
    outSymbols = {}
    outAddrs   = {}

    nextAddr = intToAddr(SYMBOL_MIN_ADDR)
    prevAddr = addrToInt(nextAddr)
    while True:
        sym = getSymbolAt(nextAddr)
        if sym is None: sym = getSymbolAfter(nextAddr)
        if sym is None: break
        addrObj = sym.getAddress()
        nextAddr = addrObj.add(1)
        addr = addrToInt(addrObj)
        monitor.setProgress(addr - SYMBOL_MIN_ADDR)

        symName = sym.getName(True)
        if '::override::' in symName: continue
        if symName.startswith('@'): continue
        symName = symName.replace('::', '_')

        # why are we skipping over 802d1058?
        # is it not assigned a section? no, it's not.
        # why not? it's referenced by __OSGetExceptionHandler
        # which is in OS.c
        # populateDataRefs sees that reference and adds it
        # to DATA_REFS
        # findDataSections then should be seeing that and
        # making it part of OS.c's data
        # 802d1058 in section data, file OS.c (0x802D0D60 - 0x802D107F)
        # so why is that section missing?
        # [*] Missing section: 0x802D0D48 - 0x802D1080
        # *** section moved from 802D0D60 - 802D0D60, end 802D1085
        # *** section end for 802D0D60 moved from 802D1085 to 802D1088
        # looks like overlapping section removal is being fooled by
        # some strange cases, eg:
        # CARDStat.c:text (80040DC8-80040F48) overlaps with
        # GXGeometry.h:text (8002C444-802CD3F8)
        # this particular case looks like multiple copies of GX
        # are linked in
        # there are multiple copies of string "GXGeometry.h"
        # so (at least some of) the fix may be to detect when the
        # same name is used at different addresses.
        # this isn't handled by this script, but by the one we
        # used to assign the function tags.
        if prevAddr <= 0x802d1058 and addr >= 0x802d1058:
            print("802d1058", hex(prevAddr), hex(addr), sym)
        prevAddr = addrToInt(nextAddr)

        # get the section
        symSection = None
        for entry in addrMap:
            if addr >= entry[0] and addr < entry[1]:
                symSection = entry[3]
                break
        # fall back to block-name-based check (less accurate)
        if symSection is None: symSection = getSectionTypeAt(addr)
        if symSection is None:
            #print("[!] No section for symbol 0x%08X: %s" % (
            #    addr, symName))
            continue
            #symSection = "unk"
        if not symSection.startswith('.'):
            symSection = '.'+symSection

        # get the object type, data type, and size
        symType, symSize, symData = 'object', None, None
        func = getFunctionAt(addrObj)
        if func is not None:
            symType = 'function'
            symSize = (addrToInt(func.body.maxAddress) - addr)+1
            if symSize < 0: symSize = 0
        else:
            data = getDataAt(addrObj)
            if data is None: symSize = 4
            else:
                symSize = data.getLength()
                symData = data.getBaseDataType().getName()
                if '*' in symData: symData = '4byte'
                if symData.startswith('char['): symData = 'string'
                elif '[' in symData: symData = None
                symData = TYPE_NAME_MAP.get(symData, symData)
                if symData not in VALID_DATA_TYPES:
                    if   symSize == 1: symData = 'byte'
                    elif symSize == 2: symData = '2byte'
                    elif symSize == 4: symData = '4byte'
                    elif symSize == 8: symData = '8byte'
                    else: symData = None

        # get info from original symbols.txt
        extInfo = []
        symTxt = symbols.get(symName, {})
        symTxt['size'] = symSize
        for k, v in symTxt.items():
            if k == 'size': v = '0x%X' % v
            if k in IGNORE_FIELDS: pass
            elif v == True: extInfo.append(k)
            else: extInfo.append('%s:%s' % (k, str(v)))
        if symData is not None:
            extInfo.append('data:'+str(symData))

        outSymbols[symName] = {
            'name': symName,
            'section': symSection,
            'addr': addr,
            'type': symType,
            'ext':  extInfo,
        }
        outAddrs[addr] = symName

    # merge original symbols.txt data into this
    for name, symTxt in symbols.items():
        # skip those we've already got from ghidra
        if name in outSymbols: continue
        if symTxt['address'] in outAddrs: continue
        extInfo = []
        for k, v in symTxt.items():
            if k == 'size': v = '0x%X' % v
            if k in IGNORE_FIELDS: pass
            elif v == True: extInfo.append(k)
            else: extInfo.append('%s:%s' % (k, str(v)))
        outSymbols[name] = {
            'name': name,
            'section': symTxt['section'],
            'addr': symTxt['address'],
            'type': symTxt['type'],
            'ext':  extInfo,
        }

    sortedSyms = list(outSymbols.values())
    sortedSyms.sort(key=lambda s: s['addr'])

    with open(outPath + '/symbols.txt', 'wt') as outFile:
        for sym in sortedSyms:
            ext = sym['ext']
            outFile.write(
                '%s = %s:0x%08X; // type:%s %s\n' % (
                sym['name'], sym['section'], sym['addr'],
                sym['type'], ' '.join(ext)))

###################################### Sanity checks

def checkSymbolsPastBlockEnd():
    """Iterate all symbols, and check if they overlap
    multiple memory blocks."""
    monitor.setIndeterminate(False)
    monitor.setProgress(0)
    monitor.setMessage("Checking symbol blocks")
    nextAddr = 0xFFFFFFFF
    maxAddr  = 0
    blocks = getMemoryBlocks()
    for block in blocks:
        aMin     = addrToInt(block.getStart())
        aMax     = addrToInt(block.getEnd())
        nextAddr = min(nextAddr, aMin)
        maxAddr  = max(maxAddr,  aMax)
    minAddr = nextAddr
    monitor.setMaximum(maxAddr - nextAddr)
    nextAddr = intToAddr(nextAddr)
    sym = getSymbolAt(nextAddr)
    if sym is None: sym = getSymbolAfter(nextAddr)

    uiUpdateCount = 0
    while sym is not None:
        name = sym.getName()
        addr = sym.getAddress()
        uiUpdateCount += 1
        if uiUpdateCount >= 100:
            monitor.setProgress(addrToInt(addr) - minAddr)
            monitor.setMessage("Checking symbol blocks: "+str(name))
            uiUpdateCount = 0
        unit = getCodeUnitContaining(addr)
        if unit is None: unit = getDataContaining(addr)
        if unit is not None:
            addrMin = unit.getMinAddress()
            addrMax = unit.getMaxAddress()
            bMin = getMemoryBlock(addrMin)
            bMax = getMemoryBlock(addrMax)
            if bMin != bMax:
                print("[!] Symbol %s (0x%08X - 0x%08X) spans multiple blocks" % (
                    name, addrToInt(addrMin), addrToInt(addrMax)))
        prevSym = sym
        while prevSym == sym:
            sym = getSymbolAfter(addr)
            addr = addr.add(1)

def checkMemoryBlocks(files):
    """Iterate sections and ensure they reside within
    exactly one memory block.
    """
    for fileName, file in files.items():
        for secName in SECTION_NAMES:
            if secName not in file: continue
            sec = file[secName]
            bMin = getMemoryBlock(intToAddr(sec['min']))
            bMax = getMemoryBlock(intToAddr(sec['max'] - 1))
            if bMin != bMax:
                print("[!] Section %s %s (%08X - %08X) spans multiple blocks" % (
                    fileName, secName, sec['min'], sec['max']))

###################################### Iterating functions

def _filterFunc(func):
	#if func.name.startswith(filterFuncPrefixes): return False
	return True

def listFuncs():
    for func in filter(_filterFunc, listing.getFunctions(True)):
        checkCanceled()
        ret = func.getReturnType()
        if ret is not None and ret.getName() != 'undefined':
            ret = ret.getName()
        else:
            ret = None
        result = {
            'func':   func,
            'start':  addrToInt(func.body.minAddress),
            'end':    addrToInt(func.body.maxAddress)+1,
            'proto':  str(func.signature.prototypeString),
            'name':   str(func.name),
            #'params': list(listParams(func)),
            'comment': getPlateComment(func.body.minAddress),
            'return':  ret,
            'tags':    func.getTags(),
        }
        fileName = None
        for tag in result['tags']:
            if str(tag).endswith(('.c', '.cpp', '.h', '.hpp', '.s')):
                fileName = str(tag)
                break
        result['file'] = fileName
        yield result

def updateFuncFile(files, func):
    fileName = func['file'] or 'unknown'
    secName  = getSectionTypeAt(func['start'])
    if fileName not in files:
        files[fileName] = {
            'text': {'min':0xFFFFFFFF, 'max':0},
            'funcs': [],
        }
    file = files[fileName]
    # in case name is not 'text' (eg 'init')
    if secName not in file:
        file[secName] = {'min':0xFFFFFFFF, 'max':0}
    file[secName]['min'] = min(file[secName]['min'], func['start'])
    file[secName]['max'] = max(file[secName]['max'], func['end'])
    file['funcs'].append(func)

###################################### Iterating data

stringRefs = {}
def _getStringRef(match):
    addr = int(match.group(2), 16)
    if addr is None: return match.group(0) # return the original string
    if addr not in stringRefs:
        s, len = readString(intToAddr(addr))
        # TODO: better escaping
        s = s.replace('"', '\\"')
        stringRefs[addr] = '"' + s + '"'
    return stringRefs[addr]

def writeFunction(func, file, fileName):
    # decompile the function
    checkCanceled()
    monitor.setMessage("Writing: %s: %s" % (fileName, func['name']))
    monitor.incrementProgress(1)
    res = ifc.decompileFunction(func['func'], 0, monitor) # DecompileResults
    if not res.decompileCompleted():
        print("Decompile error", func['name'], res.getErrorMessage())
        return
    df = res.getDecompiledFunction() # DecompiledFunction
    code = df.getC()
    #sig = df.getSignature()

    # replace string refs with actual strings
    code = re_stringRef.sub(_getStringRef, code)

    # replace stuff we don't care about
    code = code.replace(
        '/* WARNING: Subroutine does not return */', '')

    # replace namespace syntax for C
    code = code.replace('::', '_')

    # put the address after the opening brace
    code = code.replace('\n\n{', ' { //%08X' % func['start'], 1)

    file.write(code)

DATA_REFS = {} # addr => set of filenames it's referenced in
def populateDataRefsForFunc(func):
    # given func, look at all variables it references that
    # are within RAM.
    # populate a set of the files each variable is referenced in.
    for addr in range(func['start'], func['end'], 4):
        refs = getReferencesFrom(intToAddr(addr))
        for ref in refs:
            try: refAddr = addrToInt(ref.getToAddress())
            except ValueError: refAddr = 0 # eg "Stack[0x4]"
            if (refAddr >= SYMBOL_MIN_ADDR
            and refAddr <  SYMBOL_MAX_ADDR):
                # this is a valid reference
                sec = getSectionTypeAt(refAddr)
                if sec in ('bss', 'data', 'rodata', 'init'):
                    data = getDataAt(ref.getToAddress())
                    if data is None: dLen = 4
                    else: dLen = data.getLength()
                    for dAddr in range(refAddr, refAddr+dLen):
                        if dAddr not in DATA_REFS:
                            # not set() because no good way to
                            # retrieve elements from it
                            DATA_REFS[dAddr] = []
                        if (func['file'] is not None
                        and func['file'] not in DATA_REFS[dAddr]):
                            DATA_REFS[dAddr].append(func['file'])

def populateDataRefs(files):
    # for each function in each file,
    # list all memory references from the function.
    for name, srcFile in files.items():
        for func in srcFile['funcs']:
            populateDataRefsForFunc(func)

###################################### Sections

def alignSections(files):
    # ensure all sections start and end on an aligned address.
    monitor.setMessage("Aligning sections...")
    for fileName, file in files.items():
        for secName in SECTION_NAMES:
            if secName not in file: continue
            sec = file[secName]
            align = SECTION_ALIGN.get(secName, 4)
            prevMin, prevMax = sec['min'], sec['max']
            sec['min'] = sec['min'] & ~(align-1)
            if sec['min'] == 0x802D0D60:
                print(" *** section moved from %08X - %08X, end %08X" % (
                    prevMin, sec['min'], sec['max']))
            align = 4
            pad = sec['max'] % align
            if pad > 0: sec['max'] += align-pad
            if sec['min'] == 0x802D0D60:
                print(" *** section end for %08X moved from %08X to %08X" % (
                    sec['min'], prevMax, sec['max']))

def removeOverlappingSections(files):
    # sections = {fileName: {secName: {min:0, max:0}}}
    monitor.setMessage("Removing overlaps...")
    addrs = {}
    delList = {}
    for fileName, file in files.items():
        delList[fileName] = []
        for secName in SECTION_NAMES:
            if secName not in file: continue
            sec = file[secName]
            secStr = '%s:%s (%08X-%08X)' % (fileName, secName,
                sec['min'], sec['max'])
            for addr in range(sec['min'], sec['max'], 4):
                if addr in addrs:
                    if secName not in delList[fileName]:
                        print("%s overlaps with %s" % (
                            secStr, addrs[addr]))
                        delList[fileName].append(secName)
                addrs[addr] = secStr
    for fileName, delItems in delList.items():
        file = files[fileName]
        for secName in delItems:
            # may have already been removed
            if secName in file: del file[secName]

def findDataSections(files):
    monitor.setMessage("Finding sections...")
    populateDataRefs(files)

    # take all variables that are only referenced by one file.
    # singleFileVars = list of addresses.
    singleFileVars = list(filter(
        lambda k: len(DATA_REFS[k]) == 1,
        DATA_REFS.keys()))

    # find the range of variable addresses referenced by each file.
    # XXX this sometimes gives an absurdly large range.
    for addr in singleFileVars:
        fileName = DATA_REFS[addr][0] # which file?
        file = files[fileName]
        for secName in SECTION_NAMES:
            if secName not in file:
                file[secName] = {'min':0xFFFFFFFF, 'max':0}
        sec = getSectionTypeAt(addr) # which section?
        if sec in file:
            file[sec]['min'] = min(file[sec]['min'], addr)
            file[sec]['max'] = max(file[sec]['max'], addr)

def fillSectionGaps(files):
    """Create splits for areas that aren't assigned to any section."""
    monitor.setMessage("Finding unidentified sections...")
    monitor.setIndeterminate(True)
    sections = [] # (start, section)
    for fileName, file in files.items():
        for secName in SECTION_NAMES:
            if secName not in file: continue
            sec = file[secName]
            if ((SYMBOL_MIN_ADDR <= sec['min'] < SYMBOL_MAX_ADDR)
            and (SYMBOL_MIN_ADDR <= sec['max'] < SYMBOL_MAX_ADDR)):
                sections.append((sec['min'], sec))
    sections.sort(key=lambda it: it[0]) # sort by start addr

    # XXX this is creating a section from
    # .text	start:0x80073E70 end:0x800816B4
    # which completely overlaps main.c
    # because apparently main.c isn't here yet
    # main.c bss: 0xFFFFFFF8 - 0x0
    # main.c sbss: 0xFFFFFFE0 - 0x0
    # main.c sdata: 0xFFFFFFE0 - 0x0
    # main.c rodata: 0xFFFFFFFC - 0x0
    # main.c init: 0xFFFFFFFC - 0x0
    # main.c ctors: 0xFFFFFFFC - 0x0
    # main.c dtors: 0xFFFFFFFC - 0x0
    # main.c sdata2: 0xFFFFFFFC - 0x0
    # text is missing. how does it end up in splits?
    # from mergeSplits()

    # this is from the end of front.c to the start of SKNControl.c
    # main.c is 0x80077CA8 - 0x8007A284
    # ? (57): 0x80073C58 - 0x80073E70 (front.c .text)
    # main.c .text should be here... it's not present in `sections`?
    # ? (58): 0x800816B4 - 0x80081994 (SKNControl.c .text)
    newSecs = []
    prevEnd = SYMBOL_MIN_ADDR
    for i, entry in enumerate(sections):
        sec     = entry[1]
        addrMin = entry[0]
        addrMax = sec['max']
        if addrMin > prevEnd:
            print("[*] Missing section: 0x%08X - 0x%08X" % (
                prevEnd, addrMin))
            newSecs.append((prevEnd, addrMin))
        prevEnd = addrMax

    for sec in newSecs:
        name = 'unk%08X' % sec[0]
        mem  = getSectionTypeAt(sec[0])
        if mem == 'init': # HACK
            name = 'init.c'
            if name not in files:
                files[name] = { 'funcs': [] }
            if mem not in files[name]:
                files[name][mem] = {'min':sec[0], 'max':sec[1]}
            files[name][mem]['min'] = min(files[name][mem]['min'], sec[0])
            files[name][mem]['max'] = max(files[name][mem]['max'], sec[1])
        else:
            files[name] = {
                mem: {'min':sec[0], 'max':sec[1]},
                'funcs': [],
            }

###################################### splits.txt

re_splits_file    = re.compile(r'^(\S+):$')
re_splits_section = re.compile(r'^\s+(\S+)\s+start:(\S+)\s+end:(\S+)$')
re_splits_header  = re.compile(r'^\s+(\S+)\s+type:(\S+)\s+align:(\S+)')

def readSplitsTxt(path):
    # read the original splits.txt and add in
    # any sections we don't have here.
    result = {}
    headerItems = [] # order matters
    with open(path, 'rt') as file:
        curFile = None
        lines = list(file.readlines())
        while len(lines) > 0:
            line = lines.pop(0)
            fileName = re_splits_file.match(line)
            section  = re_splits_section.match(line)
            if fileName:
                fileName = fileName.group(1)
                if fileName == 'Sections':
                    while len(lines) > 0:
                        line = lines.pop(0)
                        header = re_splits_header.match(line)
                        if header:
                            headerItems.append({
                                'name':  header.group(1),
                                'type':  header.group(2),
                                'align': header.group(3),
                            })
                        else: break
                else:
                    curFile = {}
                    result[fileName] = curFile
            elif section:
                secName  = section.group(1)
                secStart = int(section.group(2), 0)
                secEnd   = int(section.group(3), 0)
                curFile[secName[1:]] = {
                    'min': secStart,
                    'max': secEnd,
                }
    return result, headerItems

def getSectionAt(files, addr):
    for fileName, file in files.items():
        for secName in SECTION_NAMES:
            if secName not in file: continue
            sec = file[secName]
            if (sec['min'] <= addr and sec['max'] > addr
            and sec['min'] >= SYMBOL_MIN_ADDR
            and sec['min'] <  SYMBOL_MAX_ADDR
            and sec['max'] >= SYMBOL_MIN_ADDR
            and sec['max'] <  SYMBOL_MAX_ADDR):
                return fileName, file, secName, sec
    return None, None, None, None

def importSection(files, fileName, file, secName, sec):
    """Add this section (from original splits.txt)
    to the given file, and correct any resulting
    section overlaps."""
    newStart, newEnd = sec['min'], sec['max']
    # TODO: optimize
    for addr in range(newStart, newEnd, 4):
        olFileName, olFile, olSecName, olSec = getSectionAt(files, addr)
        if olFileName is not None:
            print("Imported section %s .%s (0x%X - 0x%X) overlaps %s .%s (0x%X - 0x%X)" % (
                fileName, secName, newStart, newEnd,
                olFileName, olSecName, olSec['min'], olSec['max']))
            # this section overlaps the other's start and/or end
            isStart = newEnd   >= olSec['min']
            isEnd   = newStart <= olSec['max']
            if isStart and isEnd:
                if fileName.startswith('unk'): # delete this section
                    print("Discarding section %s %s" % (
                        fileName, secName))
                    return
                else: # delete the other section
                    print("Discarding section %s %s" % (
                        olFileName, olSecName))
                    del olFile[olSecName]

            elif isStart: # change the end
                print("Section %s %s end 0x%X => 0x%X" % (
                    fileName, secName, sec['max'], olSec['min']))
                sec['max'] = olSec['min']

            else: # isEnd; change the staet
                print("Section %s %s start 0x%X => 0x%X" % (
                    fileName, secName, sec['min'], olSec['max']))
                sec['min'] = olSec['max']

            break
            # XXX can there be multiple overlaps?
    # we may have shrunk the section to nothing
    if sec['max'] > sec['min']:
        file[secName] = sec
    else:
        print("Section %s %s truncated to zero length" % (
            fileName, secName))

def mergeSplits(origSplits, files):
    for fileName, splits in origSplits.items():
        file = files.get(fileName, splits)
        for secName, sec in splits.items():
            if secName not in file:
                print("Merge %s %s (0x%X - 0x%X)" % (
                    fileName, secName, sec['min'], sec['max']))
                importSection(files, fileName, file, secName, sec)

def _sortFilesKey(entry):
    file = entry[1]
    for sec in SECTION_NAMES:
        if sec in file:
            return file[sec]['min']
    return 0

def writeSplitsTxt(inPath, outPath, files, symbols, headerItems):
    # sort the split info
    monitor.setIndeterminate(True)
    monitor.setMessage("Sorting...")
    sortedFiles = []
    for name, srcFile in files.items():
        sortedFiles.append((name, srcFile))
    sortedFiles.sort(key=_sortFilesKey)

    # write the split info
    monitor.setIndeterminate(False)
    monitor.setMessage("Writing splits...")
    monitor.setProgress(0)
    monitor.setMaximum(len(sortedFiles))
    with open(outPath + '/splits.txt', 'wt') as outFile:
        outFile.write('Sections:\n')
        for item in headerItems:
            outFile.write('\t%-12stype:%s align:%s\n' % (
                item['name'], item['type'], item['align']))
        for name, srcFile in sortedFiles:
            monitor.incrementProgress(1)
            if name == 'unknown': continue
            outFile.write('\n%s:\n' % name)
            for secName in SECTION_NAMES:
                if secName not in srcFile: continue
                sec = srcFile[secName]
                aMin = sec['min']
                aMax = sec['max']
                if aMin < aMax:
                    outFile.write('\t.%s\tstart:0x%08X end:0x%08X\n' % (
                        secName, aMin, aMax))

###################################### main

def run():
    outPath = str(askDirectory("Select Export Path", "Export"))
    monitor.setIndeterminate(True)

    inPath  = str(askDirectory("Select Config Directory", "Import"))
    symbols = readSymbolsTxt(inPath+'/symbols.txt')
    correctSymbolSizes(symbols)
    applySymbolsTxt(symbols)

    # get the func/file info
    monitor.setMessage("Scanning functions...")
    files = {} # fileName => file info
    nFuncs = 0
    for func in listFuncs():
        updateFuncFile(files, func) # populates files[fileName]
        nFuncs = nFuncs + 1
        #print(func['name'], func['tags'])

    origSplits, headerItems = readSplitsTxt(inPath+'/splits.txt')

    # try to find the data sections.
    findDataSections(files)
    alignSections(files)
    removeOverlappingSections(files)
    checkMemoryBlocks(files)
    checkSymbolsPastBlockEnd()
    fillSectionGaps(files)
    mergeSplits(origSplits, files)

    writeSplitsTxt(inPath, outPath, files, symbols, headerItems)
    writeSymbolsTxt(outPath, files, symbols)

    # write the functions (disabled until the splits are right)
    #monitor.setIndeterminate(False)
    #monitor.setMaximum(nFuncs)
    #monitor.setMessage("Writing functions...")
    #for name, srcFile in files.items():
    #    path  = outPath + '/' + name
    #    parts = path.split('/')
    #    parts.pop()
    #    try:
    #        os.makedirs('/'.join(parts))
    #    except OSError as ex: # lol no exist_ok param
    #        if ex.errno != 17: raise # file exists
    #    with open(outPath + '/' + name, 'wt') as file:
    #        for func in srcFile['funcs']:
    #            writeFunction(func, file, name)

run()
# XXX a way to call this without editing the script
#assignTagsToFunctions()
