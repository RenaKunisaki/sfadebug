#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GSAP01-DEBUG",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20250520"
config.dtk_tag = "v1.5.1"
config.objdiff_tag = "v3.0.0-beta.8"
config.sjiswrap_tag = "v1.2.1"
config.wibo_tag = "0.6.16"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym version={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-g",
    "-sym on",
    "-warn off",  # remove 8 zillion lines about .note.split
    # "-listclosure", # Uncomment for Wii linkers
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers
# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = [
    "config/GSAP01-DEBUG/ldscript.tpl",
]

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    # "-W all",
    # "-O4,p",
    # "-O1,p",
    "-O0",
    "-opt peephole",
    # "-opt off",
    "-g",
    # "-func_align 8",
    # "-common on",
    # "-inline auto",
    # "-inline noauto,deferred",
    "-use_lmw_stmw on",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    "-i include/libc",
    f"-i build/{config.version}/include",
    f"-DVERSION={version_num}",
    "-DDEBUG=1",
]

# Debug flags
# if args.debug:
#    # Or -sym dwarf-2 for Wii compilers
#    cflags_base.extend(["-sym on", "-DDEBUG=1"])
# else:
#    cflags_base.append("-DNDEBUG=1")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# REL flags (not used, we have no rels)
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

config.linker_version = "GC/1.0"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.0",
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": objects,
    }


Matching = True  # Object matches and should be linked
NonMatching = False  # Object does not match and should not be linked
Equivalent = (
    config.non_matching
)  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = False
config.warn_missing_source = False
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "objects": [
            Object(Equivalent, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(Equivalent, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
        ],
    },
    DolphinLib("ai", [
        Object(Matching, "dolphin/ai/ai.c"),
    ]),
    DolphinLib("amcnotstub", [
        Object(Matching, "dolphin/amcnotstub/amcnotstub.c"),
    ]),
    DolphinLib("amcstubs", [
        Object(Matching, "dolphin/amcstubs/AmcExi2Stubs.c"),
    ]),
    DolphinLib("ar", [
        Object(Matching, "dolphin/ar/ar.c"),
        Object(Matching, "dolphin/ar/arq.c"),
    ]),
    DolphinLib("ax", [
        Object(Matching, "dolphin/ax/AX.c"),
        Object(Matching, "dolphin/ax/AXAlloc.c"),
        Object(Matching, "dolphin/ax/AXAux.c"),
        Object(Matching, "dolphin/ax/AXCL.c"),
        Object(Matching, "dolphin/ax/AXOut.c"),
        Object(Matching, "dolphin/ax/AXProf.c"),
        Object(Matching, "dolphin/ax/AXSPB.c"),
        Object(Matching, "dolphin/ax/AXVPB.c"),
        Object(Matching, "dolphin/ax/DSPCode.c"),
    ]),
    DolphinLib("axfx", [
        Object(Matching, "dolphin/axfx/chorus.c"),
        Object(Matching, "dolphin/axfx/delay.c"),
        Object(Matching, "dolphin/axfx/reverb_hi.c"),
        Object(Matching, "dolphin/axfx/reverb_std.c"),
    ]),
    DolphinLib("base", [
        Object(Matching, "dolphin/base/PPCArch.c"),
        Object(Matching, "dolphin/base/PPCPm.c"),
    ]),
    DolphinLib("card", [
        Object(Matching, "dolphin/card/CARDBios.c"),
        Object(Matching, "dolphin/card/CARDBlock.c"),
        Object(Matching, "dolphin/card/CARDCheck.c"),
        Object(Matching, "dolphin/card/CARDCreate.c"),
        Object(Matching, "dolphin/card/CARDDelete.c"),
        Object(Matching, "dolphin/card/CARDDir.c"),
        Object(Matching, "dolphin/card/CARDFormat.c"),
        Object(Matching, "dolphin/card/CARDMount.c"),
        Object(Matching, "dolphin/card/CARDOpen.c"),
        Object(Matching, "dolphin/card/CARDRaw.c"),
        Object(Matching, "dolphin/card/CARDRdwr.c"),
        Object(Matching, "dolphin/card/CARDRead.c"),
        Object(Matching, "dolphin/card/CARDRename.c"),
        Object(Matching, "dolphin/card/CARDStat.c"),
        Object(Matching, "dolphin/card/CARDStatEx.c"),
        Object(Matching, "dolphin/card/CARDUnlock.c"),
        Object(Matching, "dolphin/card/CARDWrite.c"),
    ]),
    DolphinLib("db", [
        Object(Matching, "dolphin/db/db.c"),
    ]),
    DolphinLib("demo", [
        Object(Matching, "dolphin/demo/DEMOFont.c"),
        Object(Matching, "dolphin/demo/DEMOInit.c"),
        Object(Matching, "dolphin/demo/DEMOPad.c"),
        Object(Matching, "dolphin/demo/DEMOPuts.c"),
        Object(Matching, "dolphin/demo/DEMOStats.c"),
        Object(Matching, "dolphin/demo/DEMOWin.c"),
    ]),
    DolphinLib("dolformat", [
        Object(Matching, "dolphin/dolformat/DOLLoader.c"),
    ]),
    DolphinLib("dsp", [
        Object(Matching, "dolphin/dsp/dsp_debug.c"),
        Object(Matching, "dolphin/dsp/dsp_task.c"),
        Object(Matching, "dolphin/dsp/dsp.c"),
    ]),
    DolphinLib("dtk", [
        Object(Matching, "dolphin/dtk/dtk.c"),
    ]),
    DolphinLib("dvd", [
        Object(Matching, "dolphin/dvd/dvd.c"),
        Object(Matching, "dolphin/dvd/dvdfs.c"),
        Object(Matching, "dolphin/dvd/dvdlow.c"),
        Object(Matching, "dolphin/dvd/dvdqueue.c"),
        Object(Matching, "dolphin/dvd/fstload.c"),
    ]),
    DolphinLib("fileCache", [
        Object(Matching, "dolphin/fileCache/fileCache.c"),
    ]),
    DolphinLib("G2D", [
        Object(Matching, "dolphin/G2D/G2D.c"),
    ]),
    DolphinLib("gx", [
        Object(Matching, "dolphin/gx/GXAttr.c"),
        Object(Matching, "dolphin/gx/GXBump.c"),
        Object(Matching, "dolphin/gx/GXDisplayList.c"),
        Object(Matching, "dolphin/gx/GXDraw.c"),
        Object(Matching, "dolphin/gx/GXFifo.c"),
        Object(Matching, "dolphin/gx/GXFrameBuf.c"),
        Object(Matching, "dolphin/gx/GXGeometry.c"),
        Object(Matching, "dolphin/gx/GXInit.c"),
        Object(Matching, "dolphin/gx/GXLight.c"),
        Object(Matching, "dolphin/gx/GXMisc.c"),
        Object(Matching, "dolphin/gx/GXPerf.c"),
        Object(Matching, "dolphin/gx/GXPixel.c"),
        Object(Matching, "dolphin/gx/GXSave.c"),
        Object(Matching, "dolphin/gx/GXStubs.c"),
        Object(Matching, "dolphin/gx/GXTev.c"),
        Object(Matching, "dolphin/gx/GXTexture.c"),
        Object(Matching, "dolphin/gx/GXTransform.c"),
        Object(Matching, "dolphin/gx/GXVerifRAS.c"),
        Object(Matching, "dolphin/gx/GXVerifXF.c"),
        Object(Matching, "dolphin/gx/GXVerify.c"),
        Object(Matching, "dolphin/gx/GXVert.c"),
    ]),
    DolphinLib("hio", [
        Object(Matching, "dolphin/hio/hio.c"),
    ]),
    DolphinLib("mcc", [
        Object(Matching, "dolphin/mcc/fio.c"),
        Object(Matching, "dolphin/mcc/mcc.c"),
        Object(Matching, "dolphin/mcc/tty.c"),
    ]),
    DolphinLib("mix", [
        Object(Matching, "dolphin/mix/mix.c"),
    ]),
    DolphinLib("mtx", [
        Object(Matching, "dolphin/mtx/mtx.c"),
        Object(Matching, "dolphin/mtx/mtx44.c"),
        Object(Matching, "dolphin/mtx/mtxstack.c"),
        Object(Matching, "dolphin/mtx/mtxvec.c"),
        Object(Matching, "dolphin/mtx/psmtx.c"),
        Object(Matching, "dolphin/mtx/vec.c"),
    ]),
    DolphinLib("odemustubs", [
        Object(Matching, "dolphin/odemustubs/odemustubs.c"),
    ]),
    DolphinLib("odenotstub", [
        Object(Matching, "dolphin/odenotstub/odenotstub.c"),
    ]),
    DolphinLib("os", [
        Object(Matching, "dolphin/os/OSAddress.c"),
        Object(Matching, "dolphin/os/OSAlarm.c"),
        Object(Matching, "dolphin/os/OSAlloc.c"),
        Object(Matching, "dolphin/os/OSArena.c"),
        Object(Matching, "dolphin/os/OSAudioSystem.c"),
        Object(Matching, "dolphin/os/OS.c"),
        Object(Matching, "dolphin/os/OSCache.c"),
        Object(Matching, "dolphin/os/OSContext.c"),
        Object(Matching, "dolphin/os/OSError.c"),
        Object(Matching, "dolphin/os/OSExiAd16.c"),
        Object(Matching, "dolphin/os/OSExi.c"),
        Object(Matching, "dolphin/os/OSFont.c"),
        Object(Matching, "dolphin/os/OSInterrupt.c"),
        Object(Matching, "dolphin/os/OSLink.c"),
        Object(Matching, "dolphin/os/OSMemory.c"),
        Object(Matching, "dolphin/os/OSMessage.c"),
        Object(Matching, "dolphin/os/OSMutex.c"),
        Object(Matching, "dolphin/os/OSReset.c"),
        Object(Matching, "dolphin/os/OSResetSW.c"),
        Object(Matching, "dolphin/os/OSRtc.c"),
        Object(Matching, "dolphin/os/OSSerial.c"),
        Object(Matching, "dolphin/os/OSStopwatch.c"),
        Object(Matching, "dolphin/os/OSSync.c"),
        Object(Matching, "dolphin/os/OSThread.c"),
        Object(Matching, "dolphin/os/OSTime.c"),
        Object(Matching, "dolphin/os/OSTimer.c"),
        Object(Matching, "dolphin/os/OSUartExi.c"),
        Object(Matching, "dolphin/os/__ppc_eabi_init.c"),
        Object(Matching, "dolphin/os/__start.c"),
        Object(Matching, "dolphin/os/time.dolphin.c"),
    ]),
    DolphinLib("pad", [
        Object(Matching, "dolphin/pad/Pad.c"),
        Object(Matching, "dolphin/pad/Padclamp.c"),
    ]),
    DolphinLib("perf", [
        Object(Matching, "dolphin/perf/perf.c"),
        Object(Matching, "dolphin/perf/perfdraw.c"),
    ]),
    DolphinLib("seq", [
        Object(Matching, "dolphin/seq/seq.c"),
    ]),
    DolphinLib("support", [
        Object(Matching, "dolphin/support/HTable.c"),
        Object(Matching, "dolphin/support/List.c"),
        Object(Matching, "dolphin/support/string.c"),
        Object(Matching, "dolphin/support/Tree.c"),
    ]),
    DolphinLib("syn", [
        Object(Matching, "dolphin/support/syn.c"),
        Object(Matching, "dolphin/support/synctrl.c"),
        Object(Matching, "dolphin/support/synenv.c"),
        Object(Matching, "dolphin/support/synlfo.c"),
        Object(Matching, "dolphin/support/synmix.c"),
        Object(Matching, "dolphin/support/synpitch.c"),
        Object(Matching, "dolphin/support/synsample.c"),
        Object(Matching, "dolphin/support/synvoice.c"),
        Object(Matching, "dolphin/support/synwt.c"),
    ]),
    DolphinLib("texPalette", [
        Object(Matching, "dolphin/texPalette/texPalette.c"),
    ]),
    DolphinLib("vi", [
        Object(Matching, "dolphin/vi/gpioexi.c"),
        Object(Matching, "dolphin/vi/i2c.c"),
        Object(Matching, "dolphin/vi/initphilips.c"),
        Object(Matching, "dolphin/vi/vi.c"),
    ]),
    DolphinLib("stub", [
        Object(Matching, "dolphin/stub.c"),
    ]),
    {
        "lib": "main",
        "mw_version": config.linker_version,
        "cflags": cflags_base,
        "progress_category": "game",  # str | List[str]
        "objects": [
            Object(Matching, "debug/dimenu.c"),
            Object(NonMatching, "debug/prof.c"),
            Object(Matching, "main/main.c"),
            Object(
                NonMatching,
                "main/mm_dolphin.c",
                extra_cflags=["-O0,s", "-use_lmw_stmw on",
                    "-opt peephole"],
            ),
            Object(
                NonMatching,
                "main/models_dolphin.c",
                extra_cflags=[*cflags_base, "-O0,s", "-use_lmw_stmw on"],
            ),
            Object(NonMatching, "main/objects.c"),
            Object(NonMatching, "main/objprint.c"),
            Object(Matching, "main/pi.c"),
        ],
    },
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
