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
    # DLL code range: 0x800C8760 - 0x802CE9DF
    {
        "lib": "main",
        "mw_version": config.linker_version,
        "cflags": cflags_base,
        "progress_category": "game",  # str | List[str]
        "objects": [
            Object(NonMatching, "amc/AmcExi.c"),
            Object(NonMatching, "debug.c"),
            Object(Matching, "debug/dimenu.c"),
            Object(NonMatching, "debug/prof.c"),
            Object(Matching, "main/main.c"),
            Object(Matching, "main/models_dolphin.c",
                extra_cflags=[*cflags_base, "-O0,s",
                    "-use_lmw_stmw on"],),
            Object(Matching, "main/objects.c"),
            Object(Matching, "main/objlist.c"),
            Object(Matching, "main/pi.c"),
            Object(NonMatching, "main/sparsearray.c"),
            Object(NonMatching, "dll/anim.c"),
            Object(NonMatching, "dll/animobj1C0.c"),
            Object(NonMatching, "dll/animobjD2.c"),
            Object(NonMatching, "dll/ARWarwingattachment.c"),
            Object(NonMatching, "dll/attention.c"),
            Object(NonMatching, "dll/attentioncam.c"),
            Object(NonMatching, "dll/baby_snowworm.c"),
            Object(NonMatching, "dll/backpack.c"),
            Object(NonMatching, "dll/baddieControl.c"),
            Object(NonMatching, "dll/balloonBaddie.c"),
            Object(NonMatching, "dll/BOSSdrakor_laser.c"),
            Object(NonMatching, "dll/boulder.c"),
            Object(NonMatching, "dll/brokecannon.c"),
            Object(NonMatching, "dll/BWalphaanim.c"),
            Object(NonMatching, "dll/cage.c"),
            Object(NonMatching, "dll/camcannon.c"),
            Object(NonMatching, "dll/camclimb.c"),
            Object(NonMatching, "dll/camcontrol.c"),
            Object(NonMatching, "dll/camDebug.c"),
            Object(NonMatching, "dll/camdrakor.c"),
            Object(NonMatching, "dll/camlockon.c"),
            Object(NonMatching, "dll/camshipbattle.c"),
            Object(NonMatching, "dll/camshipbattle5C.c"),
            Object(NonMatching, "dll/camslide.c"),
            Object(NonMatching, "dll/camstatic.c"),
            Object(NonMatching, "dll/camTalk.c"),
            Object(NonMatching, "dll/cannon.c"),
            Object(NonMatching, "dll/cannonball.c"),
            Object(NonMatching, "dll/CFBaby.c"),
            Object(NonMatching, "dll/cfguardian.c"),
            Object(NonMatching, "dll/CFlevelControl.c"),
            Object(NonMatching, "dll/cfprisonguard.c"),
            Object(NonMatching, "dll/CFPrisonGuard.c"),
            Object(NonMatching, "dll/Checkpoint.c"),
            Object(NonMatching, "dll/chuka.c"),
            Object(NonMatching, "dll/chukachuck.c"),
            Object(NonMatching, "dll/cloudrunner.c"),
            Object(NonMatching, "dll/collectable.c"),
            Object(NonMatching, "dll/commandmenu.c"),
            Object(NonMatching, "dll/core_snowworm.c"),
            Object(NonMatching, "dll/crate2.c"),
            Object(NonMatching, "dll/crawler253.c"),
            Object(NonMatching, "dll/CRdropbombs.c"),
            Object(NonMatching, "dll/CRfueltank.c"),
            Object(NonMatching, "dll/CRsnowclaw.c"),
            Object(NonMatching, "dll/CRsnowClaw.c"),
            Object(NonMatching, "dll/cutCam.c"),
            Object(NonMatching, "dll/DBdustgeezer.c"),
            Object(NonMatching, "dll/DBkillboulder.c"),
            Object(NonMatching, "dll/DBpointmum.c"),
            Object(NonMatching, "dll/DBprotection.c"),
            Object(NonMatching, "dll/DBshooter.c"),
            Object(NonMatching, "dll/df_partfx.c"),
            Object(NonMatching, "dll/DFlantern.c"),
            Object(NonMatching, "dll/dim_partfx.c"),
            Object(NonMatching, "dll/DIM2lift.c"),
            Object(NonMatching, "dll/DIMExplosion.c"),
            Object(NonMatching, "dll/DIMsnowball.c"),
            Object(NonMatching, "dll/DIMwooddoor.c"),
            Object(NonMatching, "dll/dinoCall02C8.c"),
            Object(NonMatching, "dll/dll_0A.c"),
            Object(NonMatching, "dll/dll_0E.c"),
            Object(NonMatching, "dll/dll_101.c"),
            Object(NonMatching, "dll/dll_10B.c"),
            Object(NonMatching, "dll/dll_11.c"),
            Object(NonMatching, "dll/dll_112.c"),
            Object(NonMatching, "dll/dll_117.c"),
            Object(NonMatching, "dll/dll_125.c"),
            Object(NonMatching, "dll/dll_12B.c"),
            Object(NonMatching, "dll/dll_132.c"),
            Object(NonMatching, "dll/dll_134.c"),
            Object(NonMatching, "dll/dll_13C.c"),
            Object(NonMatching, "dll/dll_13E.c"),
            Object(NonMatching, "dll/dll_141.c"),
            Object(NonMatching, "dll/dll_145.c"),
            Object(NonMatching, "dll/dll_147.c"),
            Object(NonMatching, "dll/dll_14D.c"),
            Object(NonMatching, "dll/dll_14F.c"),
            Object(NonMatching, "dll/dll_152.c"),
            Object(NonMatching, "dll/dll_156.c"),
            Object(NonMatching, "dll/dll_158.c"),
            Object(NonMatching, "dll/dll_15A.c"),
            Object(NonMatching, "dll/dll_15E.c"),
            Object(NonMatching, "dll/dll_165.c"),
            Object(NonMatching, "dll/dll_169.c"),
            Object(NonMatching, "dll/dll_174.c"),
            Object(NonMatching, "dll/dll_176.c"),
            Object(NonMatching, "dll/dll_187.c"),
            Object(NonMatching, "dll/dll_189.c"),
            Object(NonMatching, "dll/dll_19.c"),
            Object(NonMatching, "dll/dll_198.c"),
            Object(NonMatching, "dll/dll_1A.c"),
            Object(NonMatching, "dll/dll_1A5.c"),
            Object(NonMatching, "dll/dll_1A7.c"),
            Object(NonMatching, "dll/dll_1AD.c"),
            Object(NonMatching, "dll/dll_1B4.c"),
            Object(NonMatching, "dll/dll_1B6.c"),
            Object(NonMatching, "dll/dll_1E0.c"),
            Object(NonMatching, "dll/dll_1F1.c"),
            Object(NonMatching, "dll/dll_210.c"),
            Object(NonMatching, "dll/dll_213.c"),
            Object(NonMatching, "dll/dll_219.c"),
            Object(NonMatching, "dll/dll_221.c"),
            Object(NonMatching, "dll/dll_223.c"),
            Object(NonMatching, "dll/dll_232.c"),
            Object(NonMatching, "dll/dll_234.c"),
            Object(NonMatching, "dll/dll_23A.c"),
            Object(NonMatching, "dll/dll_23C.c"),
            Object(NonMatching, "dll/dll_245.c"),
            Object(NonMatching, "dll/dll_24D.c"),
            Object(NonMatching, "dll/dll_252.c"),
            Object(NonMatching, "dll/dll_254.c"),
            Object(NonMatching, "dll/dll_256.c"),
            Object(NonMatching, "dll/dll_25A.c"),
            Object(NonMatching, "dll/dll_25C.c"),
            Object(NonMatching, "dll/dll_265.c"),
            Object(NonMatching, "dll/dll_26D.c"),
            Object(NonMatching, "dll/dll_26F.c"),
            Object(NonMatching, "dll/dll_272.c"),
            Object(NonMatching, "dll/dll_276.c"),
            Object(NonMatching, "dll/dll_278.c"),
            Object(NonMatching, "dll/dll_27C.c"),
            Object(NonMatching, "dll/dll_27E.c"),
            Object(NonMatching, "dll/dll_285.c"),
            Object(NonMatching, "dll/dll_289.c"),
            Object(NonMatching, "dll/dll_28B.c"),
            Object(NonMatching, "dll/dll_28D.c"),
            Object(NonMatching, "dll/dll_28F.c"),
            Object(NonMatching, "dll/dll_290.c"),
            Object(NonMatching, "dll/dll_292.c"),
            Object(NonMatching, "dll/dll_294.c"),
            Object(NonMatching, "dll/dll_296.c"),
            Object(NonMatching, "dll/dll_29A.c"),
            Object(NonMatching, "dll/dll_29C.c"),
            Object(NonMatching, "dll/dll_2A5.c"),
            Object(NonMatching, "dll/dll_2B4.c"),
            Object(NonMatching, "dll/dll_2BE.c"),
            Object(NonMatching, "dll/dll_2C1.c"),
            Object(NonMatching, "dll/dll_2C5.c"),
            Object(NonMatching, "dll/dll_2D1.c"),
            Object(NonMatching, "dll/dll_2D2.c"),
            Object(NonMatching, "dll/dll_2D3.c"),
            Object(NonMatching, "dll/dll_2D4.c"),
            Object(NonMatching, "dll/dll_2D5.c"),
            Object(NonMatching, "dll/dll_2D6.c"),
            Object(NonMatching, "dll/dll_2DB.c"),
            Object(NonMatching, "dll/dll_2DC.c"),
            Object(NonMatching, "dll/dll_2DE.c"),
            Object(NonMatching, "dll/dll_2DF.c"),
            Object(NonMatching, "dll/dll_2E2.c"),
            Object(NonMatching, "dll/dll_2E4.c"),
            Object(NonMatching, "dll/dll_2E7.c"),
            Object(NonMatching, "dll/dll_2E8.c"),
            Object(NonMatching, "dll/dll_2EA.c"),
            Object(NonMatching, "dll/dll_2ED.c"),
            Object(NonMatching, "dll/dll_2EE.c"),
            Object(NonMatching, "dll/dll_2EF.c"),
            Object(NonMatching, "dll/dll_2F0.c"),
            Object(NonMatching, "dll/dll_2F2.c"),
            Object(NonMatching, "dll/dll_2F4.c"),
            Object(NonMatching, "dll/dll_36.c"),
            Object(NonMatching, "dll/dll_39.c"),
            Object(NonMatching, "dll/dll_3B.c"),
            Object(NonMatching, "dll/dll_3E.c"),
            Object(NonMatching, "dll/dll_40.c"),
            Object(NonMatching, "dll/dll_43.c"),
            Object(NonMatching, "dll/dll_44.c"),
            Object(NonMatching, "dll/dll_47.c"),
            Object(NonMatching, "dll/dll_48.c"),
            Object(NonMatching, "dll/dll_49.c"),
            Object(NonMatching, "dll/dll_4A.c"),
            Object(NonMatching, "dll/dll_4B.c"),
            Object(NonMatching, "dll/dll_4D.c"),
            Object(NonMatching, "dll/dll_4E.c"),
            Object(NonMatching, "dll/dll_53.c"),
            Object(NonMatching, "dll/dll_59.c"),
            Object(NonMatching, "dll/dll_5B.c"),
            Object(NonMatching, "dll/dll_5F.c"),
            Object(NonMatching, "dll/dll_60.c"),
            Object(NonMatching, "dll/dll_62.c"),
            Object(NonMatching, "dll/dll_64.c"),
            Object(NonMatching, "dll/dll_66.c"),
            Object(NonMatching, "dll/dll_68.c"),
            Object(NonMatching, "dll/dll_69.c"),
            Object(NonMatching, "dll/dll_6A.c"),
            Object(NonMatching, "dll/dll_6B.c"),
            Object(NonMatching, "dll/dll_6C.c"),
            Object(NonMatching, "dll/dll_6D.c"),
            Object(NonMatching, "dll/dll_6E.c"),
            Object(NonMatching, "dll/dll_6F.c"),
            Object(NonMatching, "dll/dll_70.c"),
            Object(NonMatching, "dll/dll_71.c"),
            Object(NonMatching, "dll/dll_72.c"),
            Object(NonMatching, "dll/dll_73.c"),
            Object(NonMatching, "dll/dll_74.c"),
            Object(NonMatching, "dll/dll_75.c"),
            Object(NonMatching, "dll/dll_76.c"),
            Object(NonMatching, "dll/dll_77.c"),
            Object(NonMatching, "dll/dll_78.c"),
            Object(NonMatching, "dll/dll_79.c"),
            Object(NonMatching, "dll/dll_7A.c"),
            Object(NonMatching, "dll/dll_7B.c"),
            Object(NonMatching, "dll/dll_7C.c"),
            Object(NonMatching, "dll/dll_7D.c"),
            Object(NonMatching, "dll/dll_7E.c"),
            Object(NonMatching, "dll/dll_7F.c"),
            Object(NonMatching, "dll/dll_80.c"),
            Object(NonMatching, "dll/dll_81.c"),
            Object(NonMatching, "dll/dll_82.c"),
            Object(NonMatching, "dll/dll_83.c"),
            Object(NonMatching, "dll/dll_84.c"),
            Object(NonMatching, "dll/dll_85.c"),
            Object(NonMatching, "dll/dll_87.c"),
            Object(NonMatching, "dll/dll_88.c"),
            Object(NonMatching, "dll/dll_89.c"),
            Object(NonMatching, "dll/dll_8A.c"),
            Object(NonMatching, "dll/dll_8B.c"),
            Object(NonMatching, "dll/dll_8C.c"),
            Object(NonMatching, "dll/dll_8D.c"),
            Object(NonMatching, "dll/dll_8E.c"),
            Object(NonMatching, "dll/dll_8F.c"),
            Object(NonMatching, "dll/dll_90.c"),
            Object(NonMatching, "dll/dll_91.c"),
            Object(NonMatching, "dll/dll_92.c"),
            Object(NonMatching, "dll/dll_93.c"),
            Object(NonMatching, "dll/dll_94.c"),
            Object(NonMatching, "dll/dll_95.c"),
            Object(NonMatching, "dll/dll_96.c"),
            Object(NonMatching, "dll/dll_97.c"),
            Object(NonMatching, "dll/dll_98.c"),
            Object(NonMatching, "dll/dll_99.c"),
            Object(NonMatching, "dll/dll_9A.c"),
            Object(NonMatching, "dll/dll_9B.c"),
            Object(NonMatching, "dll/dll_9C.c"),
            Object(NonMatching, "dll/dll_9D.c"),
            Object(NonMatching, "dll/dll_9E.c"),
            Object(NonMatching, "dll/dll_9F.c"),
            Object(NonMatching, "dll/dll_A0.c"),
            Object(NonMatching, "dll/dll_A1.c"),
            Object(NonMatching, "dll/dll_A2.c"),
            Object(NonMatching, "dll/dll_A3.c"),
            Object(NonMatching, "dll/dll_A4.c"),
            Object(NonMatching, "dll/dll_A5.c"),
            Object(NonMatching, "dll/dll_A6.c"),
            Object(NonMatching, "dll/dll_A7.c"),
            Object(NonMatching, "dll/dll_A8.c"),
            Object(NonMatching, "dll/dll_A9.c"),
            Object(NonMatching, "dll/dll_AA.c"),
            Object(NonMatching, "dll/dll_AB.c"),
            Object(NonMatching, "dll/dll_AC.c"),
            Object(NonMatching, "dll/dll_AD.c"),
            Object(NonMatching, "dll/dll_AE.c"),
            Object(NonMatching, "dll/dll_AF.c"),
            Object(NonMatching, "dll/dll_B0.c"),
            Object(NonMatching, "dll/dll_B1.c"),
            Object(NonMatching, "dll/dll_B2.c"),
            Object(NonMatching, "dll/dll_B3.c"),
            Object(NonMatching, "dll/dll_B4.c"),
            Object(NonMatching, "dll/dll_B5.c"),
            Object(NonMatching, "dll/dll_B6.c"),
            Object(NonMatching, "dll/dll_B7.c"),
            Object(NonMatching, "dll/dll_B8.c"),
            Object(NonMatching, "dll/dll_B9.c"),
            Object(NonMatching, "dll/dll_BA.c"),
            Object(NonMatching, "dll/dll_BB.c"),
            Object(NonMatching, "dll/dll_BC.c"),
            Object(NonMatching, "dll/dll_BD.c"),
            Object(NonMatching, "dll/dll_BE.c"),
            Object(NonMatching, "dll/dll_BF.c"),
            Object(NonMatching, "dll/dll_C0.c"),
            Object(NonMatching, "dll/dll_C1.c"),
            Object(NonMatching, "dll/dll_C2.c"),
            Object(NonMatching, "dll/dll_C3.c"),
            Object(NonMatching, "dll/dll_C4.c"),
            Object(NonMatching, "dll/dll_C5.c"),
            Object(NonMatching, "dll/dll_C6.c"),
            Object(NonMatching, "dll/dll_C7.c"),
            Object(NonMatching, "dll/dll_C8.c"),
            Object(NonMatching, "dll/dll_C9.c"),
            Object(NonMatching, "dll/dll_CB.c"),
            Object(NonMatching, "dll/dll_CC.c"),
            Object(NonMatching, "dll/dll_CD.c"),
            Object(NonMatching, "dll/dll_CE.c"),
            Object(NonMatching, "dll/dll_D1.c"),
            Object(NonMatching, "dll/dll_D3.c"),
            Object(NonMatching, "dll/dll_DA.c"),
            Object(NonMatching, "dll/dll_DB.c"),
            Object(NonMatching, "dll/dll_DF.c"),
            Object(NonMatching, "dll/dll_E2.c"),
            Object(NonMatching, "dll/dll_F4.c"),
            Object(NonMatching, "dll/door.c"),
            Object(NonMatching, "dll/draghead.c"),
            Object(NonMatching, "dll/DRbarrelplace.c"),
            Object(NonMatching, "dll/DRbullet.c"),
            Object(NonMatching, "dll/DRcagecontrol.c"),
            Object(NonMatching, "dll/DRCloudball.c"),
            Object(NonMatching, "dll/DRcloudcage.c"),
            Object(NonMatching, "dll/DRcollpieace.c"),
            Object(NonMatching, "dll/DRcradle.c"),
            Object(NonMatching, "dll/DRcreator.c"),
            Object(NonMatching, "dll/DRhalolight.c"),
            Object(NonMatching, "dll/DRlaserturret.c"),
            Object(NonMatching, "dll/DRlavacontrol.c"),
            Object(NonMatching, "dll/DRpickup.c"),
            Object(NonMatching, "dll/DRpulley.c"),
            Object(NonMatching, "dll/DRpushcart.c"),
            Object(NonMatching, "dll/DRsimplehuman.c"),
            Object(NonMatching, "dll/DRvines.c"),
            Object(NonMatching, "dll/DRyoutube.c"),
            Object(NonMatching, "dll/Dummy04.c"),
            Object(NonMatching, "dll/duster.c"),
            Object(NonMatching, "dll/expgfx.c"),
            Object(NonMatching, "dll/exploder.c"),
            Object(NonMatching, "dll/fireflyLantern.c"),
            Object(NonMatching, "dll/firstperson.c"),
            Object(NonMatching, "dll/flameblast.c"),
            Object(NonMatching, "dll/foodbag.c"),
            Object(NonMatching, "dll/foodMenu.c"),
            Object(NonMatching, "dll/fox.c"),
            Object(NonMatching, "dll/frontend_control.c"),
            Object(NonMatching, "dll/gameplay.c"),
            Object(NonMatching, "dll/gametext.c"),
            Object(NonMatching, "dll/gasvent.c"),
            Object(NonMatching, "dll/grenade.c"),
            Object(NonMatching, "dll/groundanim.c"),
            Object(NonMatching, "dll/IMsnowbike.c"),
            Object(NonMatching, "dll/intersect.c"),
            Object(NonMatching, "dll/killbot.c"),
            Object(NonMatching, "dll/ladders.c"),
            Object(NonMatching, "dll/ladders25D.c"),
            Object(NonMatching, "dll/lanternfirefly.c"),
            Object(NonMatching, "dll/laser19F.c"),
            Object(NonMatching, "dll/LGTcontrollight.c"),
            Object(NonMatching, "dll/LGTdirectionallight.c"),
            Object(NonMatching, "dll/LGTpointlight.c"),
            Object(NonMatching, "dll/LGTprojectedlight.c"),
            Object(NonMatching, "dll/lift1.c"),
            Object(NonMatching, "dll/light.c"),
            Object(NonMatching, "dll/magicdust.c"),
            Object(NonMatching, "dll/magicPlant.c"),
            Object(NonMatching, "dll/maketex.c"),
            Object(NonMatching, "dll/maybeTemplate.c"),
            Object(NonMatching, "dll/MMP_cratercritter.c"),
            Object(NonMatching, "dll/MMP_critterspit.c"),
            Object(NonMatching, "dll/MMP_gyservent.c"),
            Object(NonMatching, "dll/modanimeflash1.c"),
            Object(NonMatching, "dll/modcloudrunner2.c"),
            Object(NonMatching, "dll/modgfx67.c"),
            Object(NonMatching, "dll/moveLib.c"),
            Object(NonMatching, "dll/n_filemenu.c"),
            Object(NonMatching, "dll/n_options.c"),
            Object(NonMatching, "dll/n_pausemenu.c"),
            Object(NonMatching, "dll/n_rareware.c"),
            Object(NonMatching, "dll/newday.c"),
            Object(NonMatching, "dll/newfog.c"),
            Object(NonMatching, "dll/newSeqObj.c"),
            Object(NonMatching, "dll/newstars.c"),
            Object(NonMatching, "dll/objfsa.c"),
            Object(NonMatching, "dll/objhits.c"),
            Object(NonMatching, "dll/openingScene.c"),
            Object(NonMatching, "dll/partfx_badning.c"),
            Object(NonMatching, "dll/partfx_bayning.c"),
            Object(NonMatching, "dll/partfx_clfning.c"),
            Object(NonMatching, "dll/partfx_dakning.c"),
            Object(NonMatching, "dll/partfx_dfnning.c"),
            Object(NonMatching, "dll/partfx_icening.c"),
            Object(NonMatching, "dll/partfx_mmpning.c"),
            Object(NonMatching, "dll/partfx_nwaning.c"),
            Object(NonMatching, "dll/partfx_rexning.c"),
            Object(NonMatching, "dll/partfx_rexning2.c"),
            Object(NonMatching, "dll/partfx_rexning3.c"),
            Object(NonMatching, "dll/partfx_shpning.c"),
            Object(NonMatching, "dll/partfx_swcning.c"),
            Object(NonMatching, "dll/partfx_wcning.c"),
            Object(NonMatching, "dll/partfx_wcning2.c"),
            Object(NonMatching, "dll/partfx.c"),
            Object(NonMatching, "dll/partfx1F.c"),
            Object(NonMatching, "dll/partfx20.c"),
            Object(NonMatching, "dll/partfx22.c"),
            Object(NonMatching, "dll/pathcam.c"),
            Object(NonMatching, "dll/perform_viewer.c"),
            Object(NonMatching, "dll/pickup.c"),
            Object(NonMatching, "dll/picmenu.c"),
            Object(NonMatching, "dll/platform1.c"),
            Object(NonMatching, "dll/POST.c"),
            Object(NonMatching, "dll/projLib.c"),
            Object(NonMatching, "dll/propeller.c"),
            Object(NonMatching, "dll/pushpullObj.c"),
            Object(NonMatching, "dll/reverb_fx.c"),
            Object(NonMatching, "dll/s_data.c"),
            Object(NonMatching, "dll/savegame.c"),
            Object(NonMatching, "dll/SBcannonball.c"),
            Object(NonMatching, "dll/SBship.c"),
            Object(NonMatching, "dll/SBshipgun.c"),
            Object(NonMatching, "dll/screens.c"),
            Object(NonMatching, "dll/SCtumbleweedmeter.c"),
            Object(NonMatching, "dll/seqObj.c"),
            Object(NonMatching, "dll/seqObj11D.c"),
            Object(NonMatching, "dll/shipgun.c"),
            Object(NonMatching, "dll/SHkillermushroom.c"),
            Object(NonMatching, "dll/shrine.c"),
            Object(NonMatching, "dll/SHrocketmushroom.c"),
            Object(NonMatching, "dll/sidekickToy.c"),
            Object(NonMatching, "dll/skeetla.c"),
            Object(NonMatching, "dll/SKNControl.c"),
            Object(NonMatching, "dll/smallbasket.c"),
            Object(NonMatching, "dll/snd_init.c"),
            Object(NonMatching, "dll/sparsearray.c"),
            Object(NonMatching, "dll/spellStonePlace.c"),
            Object(NonMatching, "dll/statueball.c"),
            Object(NonMatching, "dll/swaphol.c"),
            Object(NonMatching, "dll/swarmBaddie.c"),
            Object(NonMatching, "dll/symbol.c"),
            Object(NonMatching, "dll/texScroll.c"),
            Object(NonMatching, "dll/tFrameAnimator.c"),
            Object(NonMatching, "dll/tFrameAnimator154.c"),
            Object(NonMatching, "dll/torch.c"),
            Object(NonMatching, "dll/track_dolphin.c"),
            Object(NonMatching, "dll/track/intersect.c"),
            Object(NonMatching, "dll/track/pllist.c"),
            Object(NonMatching, "dll/transporter.c"),
            Object(NonMatching, "dll/tree.c"),
            Object(NonMatching, "dll/TREX_Lazerwall.c"),
            Object(NonMatching, "dll/TREX_levelcontrol.c"),
            Object(NonMatching, "dll/TREX_trex.c"),
            Object(NonMatching, "dll/tricky.c"),
            Object(NonMatching, "dll/tumbleweed.c"),
            Object(NonMatching, "dll/Tumbleweed.c"),
            Object(NonMatching, "dll/TumbleweedBush.c"),
            Object(NonMatching, "dll/USEOBJ.c"),
            Object(NonMatching, "dll/VFlevcontrol.c"),
            Object(NonMatching, "dll/wall_crawler.c"),
            Object(NonMatching, "dll/WaterFlowWe.c"),
            Object(NonMatching, "dll/waterfx.c"),
            Object(NonMatching, "dll/WCbeacon.c"),
            Object(NonMatching, "dll/WCdial.c"),
            Object(NonMatching, "dll/WCfloortile.c"),
            Object(NonMatching, "dll/WClaser.c"),
            Object(NonMatching, "dll/WClevcontrol.c"),
            Object(NonMatching, "dll/WCpressureswitch.c"),
            Object(NonMatching, "dll/WCpressureSwitch.c"),
            Object(NonMatching, "dll/WCpushblock.c"),
            Object(NonMatching, "dll/weaponE6.c"),
            Object(NonMatching, "dll/weapons.c"),
            Object(NonMatching, "dll/wispBaddie.c"),
            Object(NonMatching, "dll/WMgeneralscales.c"),
            Object(NonMatching, "dll/WMlevcontrol.c"),
            Object(NonMatching, "dll/WORLDplanet.c"),
            Object(NonMatching, "dll/zbomb.c"),
            Object(NonMatching, "dll/zBomb.c"),
            Object(NonMatching, "hw_aramdma.c"),
            Object(NonMatching, "hw_dspctrl.c"),
            Object(NonMatching, "main/expr.c"),
            Object(NonMatching, "main/light.c"),
            Object(NonMatching, "main/lightmap.c"),
            Object(NonMatching, "main/maketex.c"),
            Object(NonMatching, "main/mm_dolphin.c",
                extra_cflags=["-O0,s", "-use_lmw_stmw on",
                    "-opt peephole"],),
            Object(NonMatching, "main/newshadows.c"),
            Object(NonMatching, "main/objanim.c"),
            Object(NonMatching, "main/objhits.c"),
            Object(NonMatching, "main/objlib.c"),
            Object(NonMatching, "main/objprint_dolphin.c"),
            Object(NonMatching, "main/objprint.c"),
            Object(NonMatching, "main/pi_dolphin.c"),
            Object(NonMatching, "main/rcp_dolphin.c"),
            Object(NonMatching, "main/shader.c"),
            Object(NonMatching, "main/SKNControl.c"),
            Object(NonMatching, "main/tex_dolphin.c"),
            Object(NonMatching, "main/timer.c"),
            Object(NonMatching, "main/track_dolphin.c"),
            Object(NonMatching, "musyx/chorus_fx.c"),
            Object(NonMatching, "musyx/hardware.c"),
            Object(NonMatching, "musyx/hw_aramdma.c"),
            Object(NonMatching, "musyx/hw_dolphin.c"),
            Object(NonMatching, "musyx/hw_memory.c"),
            Object(NonMatching, "musyx/reverb_fx.c"),
            Object(NonMatching, "musyx/reverb.c"),
            Object(NonMatching, "musyx/snd_init.c"),
            Object(NonMatching, "musyx/snd_math.c"),
            Object(NonMatching, "musyx/snd_midictrl.c"),
            Object(NonMatching, "musyx/snd_service.c"),
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
