ninja_required_version = 1.3

# The arguments passed to configure.py, for rerunning it.
configure_args = --verbose
python = "/usr/bin/python3"

# Variables
ldflags = -fp hardware -nodefaults -g -sym on -warn off
mw_version = GC/1.0

# Tooling
rule download_tool
  command = $python tools/download_tool.py $tool $out --tag $tag
  description = TOOL $out
rule decompctx
  command = $python tools/decompctx.py $in -o $out -d $out.d
  description = CTX $in
  depfile = $out.d
  deps = gcc
build build/tools/dtk: download_tool | tools/download_tool.py
  tool = dtk
  tag = v0.9.4
build build/tools/objdiff-cli: download_tool | tools/download_tool.py
  tool = objdiff-cli
  tag = v2.0.0-beta.3
build build/tools/sjiswrap.exe: download_tool | tools/download_tool.py
  tool = sjiswrap
  tag = v1.1.1
build build/tools/wibo: download_tool | tools/download_tool.py
  tool = wibo
  tag = 0.6.11
build build/compilers: download_tool | tools/download_tool.py
  tool = compilers
  tag = 20240706
build build/binutils: download_tool | tools/download_tool.py
  tool = binutils
  tag = 2.42-1

# Download all tools
build tools: phony build/tools/dtk build/tools/sjiswrap.exe $
    build/tools/wibo build/compilers build/binutils build/tools/objdiff-cli

# Link ELF file
rule link
  command = build/tools/wibo build/compilers/$mw_version/mwldeppc.exe $
      $ldflags -o $out @$out.rsp
  description = LINK $out
  rspfile = $out.rsp
  rspfile_content = $in_newline

# Generate DOL
rule elf2dol
  command = build/tools/dtk elf2dol $in $out
  description = DOL $out

# MWCC build
rule mwcc
  command = build/tools/wibo build/compilers/$mw_version/mwcceppc.exe $
      $cflags -MMD -c $in -o $basedir && $python tools/transform_dep.py $
      $basefile.d $basefile.d
  description = MWCC $out
  depfile = $basefile.d
  deps = gcc

# MWCC build (with UTF-8 to Shift JIS wrapper)
rule mwcc_sjis
  command = build/tools/wibo build/tools/sjiswrap.exe $
      build/compilers/$mw_version/mwcceppc.exe $cflags -MMD -c $in -o $
      $basedir && $python tools/transform_dep.py $basefile.d $basefile.d
  description = MWCC $out
  depfile = $basefile.d
  deps = gcc

# Assemble asm
rule as
  command = build/binutils/powerpc-eabi-as $asflags -o $out $in -MD $out.d $
      && build/tools/dtk elf fixup $out $out
  description = AS $out
  depfile = $out.d
  deps = gcc

# Host build
host_cflags = -I include -Wno-trigraphs
host_cppflags = -std=c++98 -I include -fno-exceptions -fno-rtti $
    -D_CRT_SECURE_NO_WARNINGS -Wno-trigraphs -Wno-c++11-extensions
rule host_cc
  command = clang $host_cflags -c -o $out $in
  description = CC $out
rule host_cpp
  command = clang++ $host_cppflags -c -o $out $in
  description = CXX $out

# Source files
# main/pi.c: main (linked False)
build build/GSAP01-DEBUG/src/main/pi.o: mwcc_sjis src/main/pi.c | $
    build/compilers build/tools/wibo build/tools/sjiswrap.exe $
    tools/transform_dep.py
  mw_version = GC/1.0
  cflags = -nodefaults -proc gekko -align powerpc -enum int -fp hardware $
      -Cpp_exceptions off -O0 -opt peephole -g -use_lmw_stmw on -pragma $
      "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath $
      -RTTI off -fp_contract on -str reuse -multibyte -i include -i $
      include/libc -i build/GSAP01-DEBUG/include -DVERSION=0 -DNDEBUG=1
  basedir = build/GSAP01-DEBUG/src/main
  basefile = build/GSAP01-DEBUG/src/main/pi
build build/GSAP01-DEBUG/src/main/pi.ctx: decompctx src/main/pi.c | $
    tools/decompctx.py

# main/main.c: main (linked False)
build build/GSAP01-DEBUG/src/main/main.o: mwcc_sjis src/main/main.c | $
    build/compilers build/tools/wibo build/tools/sjiswrap.exe $
    tools/transform_dep.py
  mw_version = GC/1.0
  cflags = -nodefaults -proc gekko -align powerpc -enum int -fp hardware $
      -Cpp_exceptions off -O0 -opt peephole -g -use_lmw_stmw on -pragma $
      "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath $
      -RTTI off -fp_contract on -str reuse -multibyte -i include -i $
      include/libc -i build/GSAP01-DEBUG/include -DVERSION=0 -DNDEBUG=1
  basedir = build/GSAP01-DEBUG/src/main
  basefile = build/GSAP01-DEBUG/src/main/main
build build/GSAP01-DEBUG/src/main/main.ctx: decompctx src/main/main.c | $
    tools/decompctx.py

# main/mm_dolphin.c: main (linked False)
build build/GSAP01-DEBUG/src/main/mm_dolphin.o: mwcc_sjis $
    src/main/mm_dolphin.c | build/compilers build/tools/wibo $
    build/tools/sjiswrap.exe tools/transform_dep.py
  mw_version = GC/1.0
  cflags = -nodefaults -proc gekko -align powerpc -enum int -fp hardware $
      -Cpp_exceptions off -O0 -opt peephole -g -use_lmw_stmw on -pragma $
      "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath $
      -RTTI off -fp_contract on -str reuse -multibyte -i include -i $
      include/libc -i build/GSAP01-DEBUG/include -DVERSION=0 -DNDEBUG=1
  basedir = build/GSAP01-DEBUG/src/main
  basefile = build/GSAP01-DEBUG/src/main/mm_dolphin
build build/GSAP01-DEBUG/src/main/mm_dolphin.ctx: decompctx $
    src/main/mm_dolphin.c | tools/decompctx.py

# main/models_dolphin.c: main (linked False)
build build/GSAP01-DEBUG/src/main/models_dolphin.o: mwcc_sjis $
    src/main/models_dolphin.c | build/compilers build/tools/wibo $
    build/tools/sjiswrap.exe tools/transform_dep.py
  mw_version = GC/1.0
  cflags = -nodefaults -proc gekko -align powerpc -enum int -fp hardware $
      -Cpp_exceptions off -O0 -opt peephole -g -use_lmw_stmw on -pragma $
      "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath $
      -RTTI off -fp_contract on -str reuse -multibyte -i include -i $
      include/libc -i build/GSAP01-DEBUG/include -DVERSION=0 -DNDEBUG=1
  basedir = build/GSAP01-DEBUG/src/main
  basefile = build/GSAP01-DEBUG/src/main/models_dolphin
build build/GSAP01-DEBUG/src/main/models_dolphin.ctx: decompctx $
    src/main/models_dolphin.c | tools/decompctx.py


# Link default
build build/GSAP01-DEBUG/default.elf: link $
    build/GSAP01-DEBUG/obj/auto_11_8039A1A0_sdata2.o $
    build/GSAP01-DEBUG/obj/auto_10_80398240_sbss.o $
    build/GSAP01-DEBUG/obj/auto_09_80396700_sdata.o $
    build/GSAP01-DEBUG/obj/auto_08_80325D20_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_802D0D60_data.o $
    build/GSAP01-DEBUG/obj/auto_06_802CEA40_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80006CC0_text.o $
    build/GSAP01-DEBUG/obj/dolphin/db.o build/GSAP01-DEBUG/obj/mtx.o $
    build/GSAP01-DEBUG/obj/auto_07_802D4838_data.o $
    build/GSAP01-DEBUG/obj/mtx44.o $
    build/GSAP01-DEBUG/obj/auto_07_802D4A38_data.o $
    build/GSAP01-DEBUG/obj/dolphin/vec.o $
    build/GSAP01-DEBUG/obj/auto_03_800103CC_text.o $
    build/GSAP01-DEBUG/obj/dolphin/mtxvec.o $
    build/GSAP01-DEBUG/obj/dolphin/dvdlow.o $
    build/GSAP01-DEBUG/obj/dolphin/dvdfs.o $
    build/GSAP01-DEBUG/obj/dolphin/dvd.o $
    build/GSAP01-DEBUG/obj/auto_08_80326A00_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_802D6740_data.o $
    build/GSAP01-DEBUG/obj/dolphin/dvdqueue.o $
    build/GSAP01-DEBUG/obj/auto_08_80326A38_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_80014258_text.o $
    build/GSAP01-DEBUG/obj/dolphin/vi.o $
    build/GSAP01-DEBUG/obj/auto_03_80016610_text.o $
    build/GSAP01-DEBUG/obj/dolphin/Pad.o $
    build/GSAP01-DEBUG/obj/auto_08_80326C28_bss.o $
    build/GSAP01-DEBUG/obj/dolphin/snd_init.o $
    build/GSAP01-DEBUG/obj/auto_03_80053C5C_text.o $
    build/GSAP01-DEBUG/obj/auto_CheckRoomStatus_text.o $
    build/GSAP01-DEBUG/obj/auto_03_8005417C_text.o $
    build/GSAP01-DEBUG/obj/auto_CheckDoorStatus_text.o $
    build/GSAP01-DEBUG/obj/auto_CalcEmitter_text.o $
    build/GSAP01-DEBUG/obj/auto_03_80054818_text.o $
    build/GSAP01-DEBUG/obj/auto_SetFXParameters_text.o $
    build/GSAP01-DEBUG/obj/auto_EmitterShutdown_text.o $
    build/GSAP01-DEBUG/obj/auto_sndCheckEmitter_text.o $
    build/GSAP01-DEBUG/obj/auto_sndRemoveEmitter_text.o $
    build/GSAP01-DEBUG/obj/auto_03_80054B34_text.o $
    build/GSAP01-DEBUG/obj/auto_StartContinousEmitte_text.o $
    build/GSAP01-DEBUG/obj/auto_s3dHandle_text.o $
    build/GSAP01-DEBUG/obj/auto_03_80055390_text.o $
    build/GSAP01-DEBUG/obj/auto_DoInit_text.o $
    build/GSAP01-DEBUG/obj/auto_sndInit_text.o $
    build/GSAP01-DEBUG/obj/auto_sndSetMaxVoices_text.o $
    build/GSAP01-DEBUG/obj/musyx/snd_init.o $
    build/GSAP01-DEBUG/obj/musyx/snd_math.o $
    build/GSAP01-DEBUG/obj/musyx/snd_midictrl.o $
    build/GSAP01-DEBUG/obj/musyx/snd_service.o $
    build/GSAP01-DEBUG/obj/musyx/hardware.o $
    build/GSAP01-DEBUG/obj/musyx/hw_aramdma.o $
    build/GSAP01-DEBUG/obj/musyx/hw_dolphin.o $
    build/GSAP01-DEBUG/obj/musyx/hw_memory.o $
    build/GSAP01-DEBUG/obj/musyx/reverb_fx.o $
    build/GSAP01-DEBUG/obj/musyx/reverb.o $
    build/GSAP01-DEBUG/obj/musyx/chorus_fx.o $
    build/GSAP01-DEBUG/obj/auto_03_8005A858_text.o $
    build/GSAP01-DEBUG/obj/auto_00_80003100_init.o $
    build/GSAP01-DEBUG/obj/amc/AmcExi.o $
    build/GSAP01-DEBUG/obj/auto_03_8005ACBC_text.o $
    build/GSAP01-DEBUG/obj/auto_callShutdownFuncs_text.o $
    build/GSAP01-DEBUG/obj/auto_03_8005B5A8_text.o $
    build/GSAP01-DEBUG/obj/__init_cpp_exceptions.o $
    build/GSAP01-DEBUG/obj/auto_03_8005BD20_text.o $
    build/GSAP01-DEBUG/obj/auto_preInit_800636e8_text.o $
    build/GSAP01-DEBUG/obj/auto_03_80063718_text.o $
    build/GSAP01-DEBUG/obj/sparsearray.o $
    build/GSAP01-DEBUG/obj/auto_03_80070B18_text.o $
    build/GSAP01-DEBUG/obj/main/light.o $
    build/GSAP01-DEBUG/obj/auto_03_8007725C_text.o $
    build/GSAP01-DEBUG/obj/main/pi.o build/GSAP01-DEBUG/obj/main/main.o $
    build/GSAP01-DEBUG/obj/auto_03_8007A284_text.o $
    build/GSAP01-DEBUG/obj/main/mm_dolphin.o $
    build/GSAP01-DEBUG/obj/auto_08_80357698_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_8007C4AC_text.o $
    build/GSAP01-DEBUG/obj/main/models_dolphin.o $
    build/GSAP01-DEBUG/obj/main/SKNControl.o $
    build/GSAP01-DEBUG/obj/auto_03_80081DB4_text.o $
    build/GSAP01-DEBUG/obj/main/objects.o $
    build/GSAP01-DEBUG/obj/auto_03_80085F14_text.o $
    build/GSAP01-DEBUG/obj/objanim.o $
    build/GSAP01-DEBUG/obj/auto_03_80086488_text.o $
    build/GSAP01-DEBUG/obj/main/objhits.o $
    build/GSAP01-DEBUG/obj/auto_03_8009063C_text.o $
    build/GSAP01-DEBUG/obj/main/objlib.o $
    build/GSAP01-DEBUG/obj/auto_03_800927D4_text.o $
    build/GSAP01-DEBUG/obj/expr.o $
    build/GSAP01-DEBUG/obj/auto_03_8009452C_text.o $
    build/GSAP01-DEBUG/obj/main/objprint.o $
    build/GSAP01-DEBUG/obj/auto_06_802CF3F8_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_800961A0_text.o $
    build/GSAP01-DEBUG/obj/main/objprint_dolphin.o $
    build/GSAP01-DEBUG/obj/auto_03_800993E0_text.o $
    build/GSAP01-DEBUG/obj/main/pi_dolphin.o $
    build/GSAP01-DEBUG/obj/auto_03_8009D36C_text.o $
    build/GSAP01-DEBUG/obj/main/rcp_dolphin.o $
    build/GSAP01-DEBUG/obj/auto_03_8009FE30_text.o $
    build/GSAP01-DEBUG/obj/main/shader.o $
    build/GSAP01-DEBUG/obj/auto_06_802CF518_rodata.o $
    build/GSAP01-DEBUG/obj/newday.o build/GSAP01-DEBUG/obj/newfog.o $
    build/GSAP01-DEBUG/obj/auto_03_800A3270_text.o $
    build/GSAP01-DEBUG/obj/main/lightmap.o $
    build/GSAP01-DEBUG/obj/main/tex_dolphin.o $
    build/GSAP01-DEBUG/obj/auto_03_800A4F38_text.o $
    build/GSAP01-DEBUG/obj/main/track_dolphin.o $
    build/GSAP01-DEBUG/obj/auto_03_800B20DC_text.o $
    build/GSAP01-DEBUG/obj/newshadows.o $
    build/GSAP01-DEBUG/obj/auto_03_800B4AE0_text.o $
    build/GSAP01-DEBUG/obj/track/pllist.o $
    build/GSAP01-DEBUG/obj/auto_03_800B63FC_text.o $
    build/GSAP01-DEBUG/obj/track/intersect.o $
    build/GSAP01-DEBUG/obj/auto_03_800BCE04_text.o $
    build/GSAP01-DEBUG/obj/main/maketex.o $
    build/GSAP01-DEBUG/obj/auto_03_800BEF64_text.o $
    build/GSAP01-DEBUG/obj/timer.o build/GSAP01-DEBUG/obj/anim.o $
    build/GSAP01-DEBUG/obj/auto_03_800D16B0_text.o $
    build/GSAP01-DEBUG/obj/newclouds.o build/GSAP01-DEBUG/obj/newstars.o $
    build/GSAP01-DEBUG/obj/auto_03_800D8370_text.o $
    build/GSAP01-DEBUG/obj/dll_0A.o $
    build/GSAP01-DEBUG/obj/auto_03_800D99A4_text.o $
    build/GSAP01-DEBUG/obj/waterfx.o $
    build/GSAP01-DEBUG/obj/auto_03_800DB40C_text.o $
    build/GSAP01-DEBUG/obj/modgfx.o $
    build/GSAP01-DEBUG/obj/auto_06_802CF798_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_800E5F68_text.o $
    build/GSAP01-DEBUG/obj/projgfx.o $
    build/GSAP01-DEBUG/obj/auto_03_800E9DC4_text.o $
    build/GSAP01-DEBUG/obj/modelfx.o $
    build/GSAP01-DEBUG/obj/auto_03_800EAD40_text.o $
    build/GSAP01-DEBUG/obj/partfx.o build/GSAP01-DEBUG/obj/partfx1F.o $
    build/GSAP01-DEBUG/obj/partfx20.o build/GSAP01-DEBUG/obj/dim_partfx.o $
    build/GSAP01-DEBUG/obj/partfx22.o $
    build/GSAP01-DEBUG/obj/partfx_nwaning.o $
    build/GSAP01-DEBUG/obj/partfx_swcning.o $
    build/GSAP01-DEBUG/obj/partfx_shpning.o $
    build/GSAP01-DEBUG/obj/partfx_clfning.o $
    build/GSAP01-DEBUG/obj/partfx_bayning.o $
    build/GSAP01-DEBUG/obj/partfx_badning.o $
    build/GSAP01-DEBUG/obj/partfx_icening.o $
    build/GSAP01-DEBUG/obj/partfx_rexning.o $
    build/GSAP01-DEBUG/obj/partfx_rexning2.o $
    build/GSAP01-DEBUG/obj/auto_08_80385E28_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_802F88A8_data.o $
    build/GSAP01-DEBUG/obj/partfx_dakning.o $
    build/GSAP01-DEBUG/obj/partfx_rexning3.o $
    build/GSAP01-DEBUG/obj/partfx_dfnning.o $
    build/GSAP01-DEBUG/obj/auto_03_80115508_text.o $
    build/GSAP01-DEBUG/obj/df_partfx.o $
    build/GSAP01-DEBUG/obj/partfx_wcning.o $
    build/GSAP01-DEBUG/obj/partfx_mmpning.o $
    build/GSAP01-DEBUG/obj/partfx_wcning2.o $
    build/GSAP01-DEBUG/obj/Checkpoint.o $
    build/GSAP01-DEBUG/obj/auto_03_8011A9F8_text.o $
    build/GSAP01-DEBUG/obj/dll_1A.o $
    build/GSAP01-DEBUG/obj/auto_07_802F90E8_data.o $
    build/GSAP01-DEBUG/obj/Dummy04.o build/GSAP01-DEBUG/obj/objfsa.o $
    build/GSAP01-DEBUG/obj/auto_03_8011DBFC_text.o $
    build/GSAP01-DEBUG/obj/subtitles.o $
    build/GSAP01-DEBUG/obj/auto_03_8011FD68_text.o $
    build/GSAP01-DEBUG/obj/Dummy15.o $
    build/GSAP01-DEBUG/obj/auto_03_8011FDA4_text.o $
    build/GSAP01-DEBUG/obj/TrickyWalk.o $
    build/GSAP01-DEBUG/obj/auto_03_80124090_text.o $
    build/GSAP01-DEBUG/obj/curves.o $
    build/GSAP01-DEBUG/obj/auto_03_8012A6B8_text.o $
    build/GSAP01-DEBUG/obj/gameplay.o build/GSAP01-DEBUG/obj/foodbag.o $
    build/GSAP01-DEBUG/obj/auto_06_802CFC28_rodata.o $
    build/GSAP01-DEBUG/obj/savegame.o $
    build/GSAP01-DEBUG/obj/auto_03_8012F358_text.o $
    build/GSAP01-DEBUG/obj/screens.o $
    build/GSAP01-DEBUG/obj/auto_03_8012F530_text.o $
    build/GSAP01-DEBUG/obj/pickup.o $
    build/GSAP01-DEBUG/obj/auto_03_8012FA8C_text.o $
    build/GSAP01-DEBUG/obj/modanimeflash1.o $
    build/GSAP01-DEBUG/obj/auto_03_8012FB84_text.o $
    build/GSAP01-DEBUG/obj/dll_66.o $
    build/GSAP01-DEBUG/obj/auto_03_8012FFA4_text.o $
    build/GSAP01-DEBUG/obj/modgfx67.o $
    build/GSAP01-DEBUG/obj/auto_03_8013056C_text.o $
    build/GSAP01-DEBUG/obj/dll_68.o $
    build/GSAP01-DEBUG/obj/auto_03_801317B8_text.o $
    build/GSAP01-DEBUG/obj/dll_69.o $
    build/GSAP01-DEBUG/obj/auto_03_80131C40_text.o $
    build/GSAP01-DEBUG/obj/dll_6A.o $
    build/GSAP01-DEBUG/obj/auto_03_801320C8_text.o $
    build/GSAP01-DEBUG/obj/dll_6B.o $
    build/GSAP01-DEBUG/obj/auto_03_8013255C_text.o $
    build/GSAP01-DEBUG/obj/dll_6C.o $
    build/GSAP01-DEBUG/obj/auto_03_80132A50_text.o $
    build/GSAP01-DEBUG/obj/dll_6D.o $
    build/GSAP01-DEBUG/obj/auto_03_80133000_text.o $
    build/GSAP01-DEBUG/obj/dll_6E.o $
    build/GSAP01-DEBUG/obj/auto_03_801335DC_text.o $
    build/GSAP01-DEBUG/obj/dll_6F.o $
    build/GSAP01-DEBUG/obj/auto_03_80133B64_text.o $
    build/GSAP01-DEBUG/obj/dll_70.o $
    build/GSAP01-DEBUG/obj/auto_03_8013447C_text.o $
    build/GSAP01-DEBUG/obj/dll_71.o $
    build/GSAP01-DEBUG/obj/auto_03_801348BC_text.o $
    build/GSAP01-DEBUG/obj/dll_AF.o $
    build/GSAP01-DEBUG/obj/auto_03_80134DF4_text.o $
    build/GSAP01-DEBUG/obj/dll_72.o $
    build/GSAP01-DEBUG/obj/auto_03_80135354_text.o $
    build/GSAP01-DEBUG/obj/dll_73.o $
    build/GSAP01-DEBUG/obj/auto_03_801359E0_text.o $
    build/GSAP01-DEBUG/obj/dll_74.o $
    build/GSAP01-DEBUG/obj/auto_03_80135D64_text.o $
    build/GSAP01-DEBUG/obj/dll_64.o $
    build/GSAP01-DEBUG/obj/auto_03_801361D8_text.o $
    build/GSAP01-DEBUG/obj/dll_75.o $
    build/GSAP01-DEBUG/obj/auto_03_801361FC_text.o $
    build/GSAP01-DEBUG/obj/dll_76.o $
    build/GSAP01-DEBUG/obj/auto_03_80136794_text.o $
    build/GSAP01-DEBUG/obj/dll_77.o $
    build/GSAP01-DEBUG/obj/auto_03_80136C3C_text.o $
    build/GSAP01-DEBUG/obj/dll_78.o $
    build/GSAP01-DEBUG/obj/auto_03_80136F84_text.o $
    build/GSAP01-DEBUG/obj/dll_79.o $
    build/GSAP01-DEBUG/obj/auto_03_80136FA8_text.o $
    build/GSAP01-DEBUG/obj/dll_7A.o $
    build/GSAP01-DEBUG/obj/auto_03_801372F0_text.o $
    build/GSAP01-DEBUG/obj/dll_7B.o $
    build/GSAP01-DEBUG/obj/auto_03_80137638_text.o $
    build/GSAP01-DEBUG/obj/dll_7C.o $
    build/GSAP01-DEBUG/obj/auto_03_80137F28_text.o $
    build/GSAP01-DEBUG/obj/dll_7D.o $
    build/GSAP01-DEBUG/obj/auto_03_80138760_text.o $
    build/GSAP01-DEBUG/obj/dll_7E.o $
    build/GSAP01-DEBUG/obj/auto_03_80138C9C_text.o $
    build/GSAP01-DEBUG/obj/dll_7F.o $
    build/GSAP01-DEBUG/obj/auto_03_801390E8_text.o $
    build/GSAP01-DEBUG/obj/dll_80.o $
    build/GSAP01-DEBUG/obj/auto_03_80139720_text.o $
    build/GSAP01-DEBUG/obj/dll_81.o $
    build/GSAP01-DEBUG/obj/auto_03_80139CCC_text.o $
    build/GSAP01-DEBUG/obj/dll_82.o $
    build/GSAP01-DEBUG/obj/auto_03_8013A19C_text.o $
    build/GSAP01-DEBUG/obj/dll_83.o $
    build/GSAP01-DEBUG/obj/auto_03_8013A4F8_text.o $
    build/GSAP01-DEBUG/obj/dll_84.o $
    build/GSAP01-DEBUG/obj/auto_03_8013A854_text.o $
    build/GSAP01-DEBUG/obj/dll_85.o $
    build/GSAP01-DEBUG/obj/auto_03_8013AE34_text.o $
    build/GSAP01-DEBUG/obj/modcloudrunner2.o $
    build/GSAP01-DEBUG/obj/auto_03_8013B840_text.o $
    build/GSAP01-DEBUG/obj/dll_87.o $
    build/GSAP01-DEBUG/obj/auto_03_8013BD58_text.o $
    build/GSAP01-DEBUG/obj/dll_88.o $
    build/GSAP01-DEBUG/obj/auto_03_8013C3FC_text.o $
    build/GSAP01-DEBUG/obj/dll_89.o $
    build/GSAP01-DEBUG/obj/auto_03_8013CAF4_text.o $
    build/GSAP01-DEBUG/obj/dll_8A.o $
    build/GSAP01-DEBUG/obj/auto_03_8013CF8C_text.o $
    build/GSAP01-DEBUG/obj/dll_8B.o $
    build/GSAP01-DEBUG/obj/auto_03_8013D39C_text.o $
    build/GSAP01-DEBUG/obj/dll_8C.o $
    build/GSAP01-DEBUG/obj/auto_03_8013D95C_text.o $
    build/GSAP01-DEBUG/obj/dll_8D.o $
    build/GSAP01-DEBUG/obj/auto_03_8013DCC0_text.o $
    build/GSAP01-DEBUG/obj/dll_8E.o $
    build/GSAP01-DEBUG/obj/auto_03_8013E390_text.o $
    build/GSAP01-DEBUG/obj/dll_8F.o $
    build/GSAP01-DEBUG/obj/auto_03_8013E93C_text.o $
    build/GSAP01-DEBUG/obj/dll_90.o $
    build/GSAP01-DEBUG/obj/auto_03_8013EFE4_text.o $
    build/GSAP01-DEBUG/obj/dll_91.o $
    build/GSAP01-DEBUG/obj/auto_03_8013F688_text.o $
    build/GSAP01-DEBUG/obj/dll_92.o $
    build/GSAP01-DEBUG/obj/auto_03_8013FDE4_text.o $
    build/GSAP01-DEBUG/obj/dll_93.o $
    build/GSAP01-DEBUG/obj/auto_03_801401E4_text.o $
    build/GSAP01-DEBUG/obj/dll_94.o $
    build/GSAP01-DEBUG/obj/auto_03_80140630_text.o $
    build/GSAP01-DEBUG/obj/dll_95.o $
    build/GSAP01-DEBUG/obj/auto_03_80140A40_text.o $
    build/GSAP01-DEBUG/obj/dll_96.o $
    build/GSAP01-DEBUG/obj/auto_03_80140E8C_text.o $
    build/GSAP01-DEBUG/obj/dll_97.o $
    build/GSAP01-DEBUG/obj/auto_03_801410BC_text.o $
    build/GSAP01-DEBUG/obj/dll_98.o $
    build/GSAP01-DEBUG/obj/auto_03_8014173C_text.o $
    build/GSAP01-DEBUG/obj/dll_99.o $
    build/GSAP01-DEBUG/obj/auto_03_80141E44_text.o $
    build/GSAP01-DEBUG/obj/dll_9A.o $
    build/GSAP01-DEBUG/obj/auto_03_80142994_text.o $
    build/GSAP01-DEBUG/obj/dll_9B.o $
    build/GSAP01-DEBUG/obj/auto_03_80143134_text.o $
    build/GSAP01-DEBUG/obj/dll_9C.o $
    build/GSAP01-DEBUG/obj/auto_03_8014357C_text.o $
    build/GSAP01-DEBUG/obj/dll_9D.o $
    build/GSAP01-DEBUG/obj/auto_03_80143C5C_text.o $
    build/GSAP01-DEBUG/obj/dll_9E.o $
    build/GSAP01-DEBUG/obj/auto_03_801442C4_text.o $
    build/GSAP01-DEBUG/obj/dll_9F.o $
    build/GSAP01-DEBUG/obj/auto_03_801447BC_text.o $
    build/GSAP01-DEBUG/obj/dll_A0.o $
    build/GSAP01-DEBUG/obj/auto_03_80144B48_text.o $
    build/GSAP01-DEBUG/obj/dll_A1.o $
    build/GSAP01-DEBUG/obj/auto_03_80145040_text.o $
    build/GSAP01-DEBUG/obj/dll_A2.o $
    build/GSAP01-DEBUG/obj/auto_03_80145444_text.o $
    build/GSAP01-DEBUG/obj/dll_A3.o $
    build/GSAP01-DEBUG/obj/auto_03_8014583C_text.o $
    build/GSAP01-DEBUG/obj/dll_A4.o $
    build/GSAP01-DEBUG/obj/auto_03_80145D34_text.o $
    build/GSAP01-DEBUG/obj/dll_A5.o $
    build/GSAP01-DEBUG/obj/auto_03_801461FC_text.o $
    build/GSAP01-DEBUG/obj/dll_A6.o $
    build/GSAP01-DEBUG/obj/auto_03_801466F4_text.o $
    build/GSAP01-DEBUG/obj/dll_A7.o $
    build/GSAP01-DEBUG/obj/auto_03_8014712C_text.o $
    build/GSAP01-DEBUG/obj/dll_A8.o $
    build/GSAP01-DEBUG/obj/auto_03_80147668_text.o $
    build/GSAP01-DEBUG/obj/dll_A9.o $
    build/GSAP01-DEBUG/obj/auto_03_80147BB4_text.o $
    build/GSAP01-DEBUG/obj/dll_AA.o $
    build/GSAP01-DEBUG/obj/auto_03_801480B4_text.o $
    build/GSAP01-DEBUG/obj/dll_AB.o $
    build/GSAP01-DEBUG/obj/auto_03_801485F0_text.o $
    build/GSAP01-DEBUG/obj/dll_AC.o $
    build/GSAP01-DEBUG/obj/auto_03_80148C04_text.o $
    build/GSAP01-DEBUG/obj/dll_AD.o $
    build/GSAP01-DEBUG/obj/auto_03_80149094_text.o $
    build/GSAP01-DEBUG/obj/dll_AE.o $
    build/GSAP01-DEBUG/obj/auto_03_801495D0_text.o $
    build/GSAP01-DEBUG/obj/dll_B0.o $
    build/GSAP01-DEBUG/obj/auto_03_80149A94_text.o $
    build/GSAP01-DEBUG/obj/dll_B1.o $
    build/GSAP01-DEBUG/obj/auto_03_80149AA0_text.o $
    build/GSAP01-DEBUG/obj/dll_B2.o $
    build/GSAP01-DEBUG/obj/auto_03_8014A104_text.o $
    build/GSAP01-DEBUG/obj/dll_B3.o $
    build/GSAP01-DEBUG/obj/auto_03_8014A860_text.o $
    build/GSAP01-DEBUG/obj/dll_B4.o $
    build/GSAP01-DEBUG/obj/auto_03_8014ADE8_text.o $
    build/GSAP01-DEBUG/obj/dll_B5.o $
    build/GSAP01-DEBUG/obj/auto_03_8014B308_text.o $
    build/GSAP01-DEBUG/obj/dll_B6.o $
    build/GSAP01-DEBUG/obj/auto_03_8014B828_text.o $
    build/GSAP01-DEBUG/obj/dll_B7.o $
    build/GSAP01-DEBUG/obj/auto_03_8014BAB0_text.o $
    build/GSAP01-DEBUG/obj/dll_B8.o $
    build/GSAP01-DEBUG/obj/auto_03_8014BAC0_text.o $
    build/GSAP01-DEBUG/obj/dll_B9.o $
    build/GSAP01-DEBUG/obj/auto_03_8014C040_text.o $
    build/GSAP01-DEBUG/obj/dll_BA.o $
    build/GSAP01-DEBUG/obj/auto_03_8014C48C_text.o $
    build/GSAP01-DEBUG/obj/dll_BB.o $
    build/GSAP01-DEBUG/obj/auto_03_8014CDC4_text.o $
    build/GSAP01-DEBUG/obj/dll_BC.o $
    build/GSAP01-DEBUG/obj/auto_03_8014D2F4_text.o $
    build/GSAP01-DEBUG/obj/dll_BD.o $
    build/GSAP01-DEBUG/obj/auto_03_8014D7C0_text.o $
    build/GSAP01-DEBUG/obj/dll_BF.o $
    build/GSAP01-DEBUG/obj/auto_03_8014DF40_text.o $
    build/GSAP01-DEBUG/obj/dll_C4.o $
    build/GSAP01-DEBUG/obj/auto_03_8014E440_text.o $
    build/GSAP01-DEBUG/obj/dll_C5.o $
    build/GSAP01-DEBUG/obj/auto_03_8014E9F8_text.o $
    build/GSAP01-DEBUG/obj/dll_C6.o $
    build/GSAP01-DEBUG/obj/auto_03_8014EF50_text.o $
    build/GSAP01-DEBUG/obj/dll_C0.o $
    build/GSAP01-DEBUG/obj/auto_03_8014F484_text.o $
    build/GSAP01-DEBUG/obj/dll_C1.o $
    build/GSAP01-DEBUG/obj/auto_03_8014F7D4_text.o $
    build/GSAP01-DEBUG/obj/dll_BE.o $
    build/GSAP01-DEBUG/obj/auto_03_8014FB98_text.o $
    build/GSAP01-DEBUG/obj/dll_C2.o $
    build/GSAP01-DEBUG/obj/auto_03_80150004_text.o $
    build/GSAP01-DEBUG/obj/dll_C3.o $
    build/GSAP01-DEBUG/obj/auto_03_8015043C_text.o $
    build/GSAP01-DEBUG/obj/dll_C7.o $
    build/GSAP01-DEBUG/obj/auto_03_80150750_text.o $
    build/GSAP01-DEBUG/obj/dll_C8.o $
    build/GSAP01-DEBUG/obj/auto_03_80150CF0_text.o $
    build/GSAP01-DEBUG/obj/dll_C9.o $
    build/GSAP01-DEBUG/obj/auto_03_801511D4_text.o $
    build/GSAP01-DEBUG/obj/dll_CB.o $
    build/GSAP01-DEBUG/obj/auto_03_80152584_text.o $
    build/GSAP01-DEBUG/obj/dll_CC.o $
    build/GSAP01-DEBUG/obj/auto_03_801528BC_text.o $
    build/GSAP01-DEBUG/obj/dll_CD.o $
    build/GSAP01-DEBUG/obj/auto_03_80152C04_text.o $
    build/GSAP01-DEBUG/obj/dll_CE.o $
    build/GSAP01-DEBUG/obj/auto_03_80152FFC_text.o $
    build/GSAP01-DEBUG/obj/camcontrol.o $
    build/GSAP01-DEBUG/obj/auto_03_80154598_text.o $
    build/GSAP01-DEBUG/obj/cutCam.o $
    build/GSAP01-DEBUG/obj/auto_03_80156DDC_text.o $
    build/GSAP01-DEBUG/obj/attention.o $
    build/GSAP01-DEBUG/obj/auto_03_80158380_text.o $
    build/GSAP01-DEBUG/obj/camslide.o $
    build/GSAP01-DEBUG/obj/auto_03_80158EA4_text.o $
    build/GSAP01-DEBUG/obj/firstperson.o $
    build/GSAP01-DEBUG/obj/auto_03_80159B08_text.o $
    build/GSAP01-DEBUG/obj/dll_53.o $
    build/GSAP01-DEBUG/obj/auto_03_8015AA28_text.o $
    build/GSAP01-DEBUG/obj/camstatic.o $
    build/GSAP01-DEBUG/obj/auto_03_8015AE9C_text.o $
    build/GSAP01-DEBUG/obj/pathcam.o $
    build/GSAP01-DEBUG/obj/auto_03_8015C0F8_text.o $
    build/GSAP01-DEBUG/obj/camlockon.o $
    build/GSAP01-DEBUG/obj/auto_03_8015E174_text.o $
    build/GSAP01-DEBUG/obj/camshipbattle.o $
    build/GSAP01-DEBUG/obj/auto_07_803022F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8015E994_text.o $
    build/GSAP01-DEBUG/obj/camclimb.o $
    build/GSAP01-DEBUG/obj/auto_07_80302360_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8015EF2C_text.o $
    build/GSAP01-DEBUG/obj/dll_59.o $
    build/GSAP01-DEBUG/obj/auto_03_8015F120_text.o $
    build/GSAP01-DEBUG/obj/camTalk.o $
    build/GSAP01-DEBUG/obj/auto_03_8015F644_text.o $
    build/GSAP01-DEBUG/obj/dll_5B.o $
    build/GSAP01-DEBUG/obj/auto_03_8016035C_text.o $
    build/GSAP01-DEBUG/obj/camshipbattle5C.o $
    build/GSAP01-DEBUG/obj/auto_07_80302448_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8016062C_text.o $
    build/GSAP01-DEBUG/obj/attentioncam.o $
    build/GSAP01-DEBUG/obj/auto_03_801607F4_text.o $
    build/GSAP01-DEBUG/obj/camcannon.o $
    build/GSAP01-DEBUG/obj/auto_03_801609E8_text.o $
    build/GSAP01-DEBUG/obj/dll_5F.o $
    build/GSAP01-DEBUG/obj/auto_03_80160CFC_text.o $
    build/GSAP01-DEBUG/obj/dll_60.o $
    build/GSAP01-DEBUG/obj/auto_03_80161154_text.o $
    build/GSAP01-DEBUG/obj/camdrakor.o $
    build/GSAP01-DEBUG/obj/auto_03_80161718_text.o $
    build/GSAP01-DEBUG/obj/dll_62.o $
    build/GSAP01-DEBUG/obj/auto_03_801618B8_text.o $
    build/GSAP01-DEBUG/obj/camDebug.o $
    build/GSAP01-DEBUG/obj/auto_03_80161A00_text.o $
    build/GSAP01-DEBUG/obj/baddieControl.o $
    build/GSAP01-DEBUG/obj/auto_06_802CFC90_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80163E78_text.o $
    build/GSAP01-DEBUG/obj/moveLib.o $
    build/GSAP01-DEBUG/obj/auto_03_80165A38_text.o $
    build/GSAP01-DEBUG/obj/projLib.o $
    build/GSAP01-DEBUG/obj/auto_03_80165F54_text.o $
    build/GSAP01-DEBUG/obj/POST.o $
    build/GSAP01-DEBUG/obj/auto_03_801663B8_text.o $
    build/GSAP01-DEBUG/obj/n_rareware.o $
    build/GSAP01-DEBUG/obj/auto_03_80166828_text.o $
    build/GSAP01-DEBUG/obj/dll_39.o $
    build/GSAP01-DEBUG/obj/auto_03_80167094_text.o $
    build/GSAP01-DEBUG/obj/n_filemenu.o $
    build/GSAP01-DEBUG/obj/auto_03_80167938_text.o $
    build/GSAP01-DEBUG/obj/dll_3B.o $
    build/GSAP01-DEBUG/obj/auto_03_80168DEC_text.o $
    build/GSAP01-DEBUG/obj/n_options.o $
    build/GSAP01-DEBUG/obj/auto_03_80169FE4_text.o $
    build/GSAP01-DEBUG/obj/n_pausemenu.o $
    build/GSAP01-DEBUG/obj/auto_03_8016BD20_text.o $
    build/GSAP01-DEBUG/obj/dll_3E.o $
    build/GSAP01-DEBUG/obj/auto_03_8016C8A0_text.o $
    build/GSAP01-DEBUG/obj/dll_40.o $
    build/GSAP01-DEBUG/obj/auto_03_8016CDC4_text.o $
    build/GSAP01-DEBUG/obj/dll_44.o $
    build/GSAP01-DEBUG/obj/auto_03_80173A50_text.o $
    build/GSAP01-DEBUG/obj/picmenu.o $
    build/GSAP01-DEBUG/obj/auto_03_80174938_text.o $
    build/GSAP01-DEBUG/obj/frontend_control.o $
    build/GSAP01-DEBUG/obj/auto_03_80175448_text.o $
    build/GSAP01-DEBUG/obj/dll_43.o $
    build/GSAP01-DEBUG/obj/auto_03_801759A4_text.o $
    build/GSAP01-DEBUG/obj/dll_47.o build/GSAP01-DEBUG/obj/dll_36.o $
    build/GSAP01-DEBUG/obj/auto_03_80177BE4_text.o $
    build/GSAP01-DEBUG/obj/dll_48.o $
    build/GSAP01-DEBUG/obj/auto_03_801785B0_text.o $
    build/GSAP01-DEBUG/obj/dll_49.o $
    build/GSAP01-DEBUG/obj/auto_03_80178B10_text.o $
    build/GSAP01-DEBUG/obj/dll_4A.o $
    build/GSAP01-DEBUG/obj/auto_03_80179648_text.o $
    build/GSAP01-DEBUG/obj/dll_4B.o $
    build/GSAP01-DEBUG/obj/auto_03_80179664_text.o $
    build/GSAP01-DEBUG/obj/swaphol.o $
    build/GSAP01-DEBUG/obj/auto_03_80179670_text.o $
    build/GSAP01-DEBUG/obj/dll_4E.o $
    build/GSAP01-DEBUG/obj/auto_03_80179A50_text.o $
    build/GSAP01-DEBUG/obj/dll_4D.o $
    build/GSAP01-DEBUG/obj/auto_03_80179B10_text.o $
    build/GSAP01-DEBUG/obj/debug/debug.o $
    build/GSAP01-DEBUG/obj/auto_08_80390978_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_8017C278_text.o $
    build/GSAP01-DEBUG/obj/tricky.o $
    build/GSAP01-DEBUG/obj/auto_06_802CFFA8_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_801AA540_text.o $
    build/GSAP01-DEBUG/obj/maybeTemplate.o $
    build/GSAP01-DEBUG/obj/auto_08_80395850_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_8030FAA0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801B19EC_text.o $
    build/GSAP01-DEBUG/obj/balloonBaddie.o $
    build/GSAP01-DEBUG/obj/auto_03_801B48D8_text.o $
    build/GSAP01-DEBUG/obj/swarmBaddie.o $
    build/GSAP01-DEBUG/obj/auto_03_801B53A8_text.o $
    build/GSAP01-DEBUG/obj/wispBaddie.o $
    build/GSAP01-DEBUG/obj/auto_03_801B5E24_text.o $
    build/GSAP01-DEBUG/obj/baby_snowworm.o build/GSAP01-DEBUG/obj/chuka.o $
    build/GSAP01-DEBUG/obj/auto_07_803104B0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801BE2E8_text.o $
    build/GSAP01-DEBUG/obj/chukachuck.o $
    build/GSAP01-DEBUG/obj/auto_03_801BE6D0_text.o $
    build/GSAP01-DEBUG/obj/wall_crawler.o $
    build/GSAP01-DEBUG/obj/auto_08_80395908_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_803105F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801BEEA4_text.o $
    build/GSAP01-DEBUG/obj/dll_DB.o $
    build/GSAP01-DEBUG/obj/auto_03_801BFF1C_text.o $
    build/GSAP01-DEBUG/obj/dll_DA.o $
    build/GSAP01-DEBUG/obj/auto_03_801C1944_text.o $
    build/GSAP01-DEBUG/obj/TumbleweedBush.o $
    build/GSAP01-DEBUG/obj/auto_03_801C1E24_text.o $
    build/GSAP01-DEBUG/obj/Tumbleweed.o $
    build/GSAP01-DEBUG/obj/auto_07_80310858_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801C3440_text.o $
    build/GSAP01-DEBUG/obj/skeetla.o $
    build/GSAP01-DEBUG/obj/auto_08_80395990_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_803109F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801C476C_text.o $
    build/GSAP01-DEBUG/obj/dll_DF.o $
    build/GSAP01-DEBUG/obj/auto_03_801C676C_text.o $
    build/GSAP01-DEBUG/obj/MMP_cratercritter.o $
    build/GSAP01-DEBUG/obj/auto_07_80310AF8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801C6D98_text.o $
    build/GSAP01-DEBUG/obj/MMP_critterspit.o $
    build/GSAP01-DEBUG/obj/auto_07_80310B88_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801C8810_text.o $
    build/GSAP01-DEBUG/obj/dll_E2.o $
    build/GSAP01-DEBUG/obj/auto_03_801C8A84_text.o $
    build/GSAP01-DEBUG/obj/dll_D1.o $
    build/GSAP01-DEBUG/obj/auto_03_801C8ABC_text.o $
    build/GSAP01-DEBUG/obj/animobjD2.o $
    build/GSAP01-DEBUG/obj/auto_03_801C8E80_text.o $
    build/GSAP01-DEBUG/obj/dll_D3.o $
    build/GSAP01-DEBUG/obj/auto_03_801C8F2C_text.o $
    build/GSAP01-DEBUG/obj/weaponE6.o $
    build/GSAP01-DEBUG/obj/auto_08_803959F8_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_80310D10_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801C9BD4_text.o $
    build/GSAP01-DEBUG/obj/cannon.o $
    build/GSAP01-DEBUG/obj/auto_07_80310DC8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801CB8FC_text.o $
    build/GSAP01-DEBUG/obj/cannonball.o $
    build/GSAP01-DEBUG/obj/auto_03_801CBBB8_text.o $
    build/GSAP01-DEBUG/obj/projball.o $
    build/GSAP01-DEBUG/obj/auto_03_801CC380_text.o $
    build/GSAP01-DEBUG/obj/grenade.o $
    build/GSAP01-DEBUG/obj/auto_03_801CD010_text.o $
    build/GSAP01-DEBUG/obj/flamethrower.o $
    build/GSAP01-DEBUG/obj/auto_07_80310EB8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801CDB8C_text.o $
    build/GSAP01-DEBUG/obj/tesla.o $
    build/GSAP01-DEBUG/obj/auto_07_80310F50_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801CE8E4_text.o $
    build/GSAP01-DEBUG/obj/dll_EC.o $
    build/GSAP01-DEBUG/obj/auto_03_801CEDD0_text.o $
    build/GSAP01-DEBUG/obj/TrickyCurve.o $
    build/GSAP01-DEBUG/obj/auto_07_803110E0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801D0F80_text.o $
    build/GSAP01-DEBUG/obj/sfxplayer.o $
    build/GSAP01-DEBUG/obj/auto_03_801D13C0_text.o $
    build/GSAP01-DEBUG/obj/crate.o $
    build/GSAP01-DEBUG/obj/auto_03_801D19C4_text.o $
    build/GSAP01-DEBUG/obj/crate2.o $
    build/GSAP01-DEBUG/obj/auto_03_801D1DA0_text.o $
    build/GSAP01-DEBUG/obj/dll_F0.o $
    build/GSAP01-DEBUG/obj/auto_03_801D1F94_text.o $
    build/GSAP01-DEBUG/obj/dll_101.o $
    build/GSAP01-DEBUG/obj/auto_08_80395A20_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_801D246C_text.o $
    build/GSAP01-DEBUG/obj/dll_F2.o $
    build/GSAP01-DEBUG/obj/auto_03_801D26AC_text.o $
    build/GSAP01-DEBUG/obj/dll_F3.o $
    build/GSAP01-DEBUG/obj/auto_03_801D2838_text.o $
    build/GSAP01-DEBUG/obj/dll_F1.o $
    build/GSAP01-DEBUG/obj/auto_03_801D2964_text.o $
    build/GSAP01-DEBUG/obj/dll_F4.o $
    build/GSAP01-DEBUG/obj/auto_03_801D2990_text.o $
    build/GSAP01-DEBUG/obj/collectable.o $
    build/GSAP01-DEBUG/obj/auto_03_801D3C6C_text.o $
    build/GSAP01-DEBUG/obj/magicGem.o $
    build/GSAP01-DEBUG/obj/auto_07_803113C8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801D4A44_text.o $
    build/GSAP01-DEBUG/obj/dll_F7.o $
    build/GSAP01-DEBUG/obj/auto_03_801D4F34_text.o $
    build/GSAP01-DEBUG/obj/pushpullObj.o $
    build/GSAP01-DEBUG/obj/auto_06_802D02A8_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_801D6138_text.o $
    build/GSAP01-DEBUG/obj/dll_F9.o $
    build/GSAP01-DEBUG/obj/auto_03_801D7090_text.o $
    build/GSAP01-DEBUG/obj/OBJ_InvHit.o $
    build/GSAP01-DEBUG/obj/auto_07_803115F0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801D79B8_text.o $
    build/GSAP01-DEBUG/obj/iceblast.o $
    build/GSAP01-DEBUG/obj/auto_03_801D7C38_text.o $
    build/GSAP01-DEBUG/obj/flameblast.o $
    build/GSAP01-DEBUG/obj/auto_03_801D7E60_text.o $
    build/GSAP01-DEBUG/obj/dll_FD.o $
    build/GSAP01-DEBUG/obj/auto_03_801D81A8_text.o $
    build/GSAP01-DEBUG/obj/sidekickToy.o $
    build/GSAP01-DEBUG/obj/auto_03_801D9440_text.o $
    build/GSAP01-DEBUG/obj/dll_FF.o $
    build/GSAP01-DEBUG/obj/auto_07_80311808_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801D9940_text.o $
    build/GSAP01-DEBUG/obj/dll_102.o $
    build/GSAP01-DEBUG/obj/auto_03_801D9DA4_text.o $
    build/GSAP01-DEBUG/obj/projswitch.o $
    build/GSAP01-DEBUG/obj/auto_03_801DA1B0_text.o $
    build/GSAP01-DEBUG/obj/dll_104.o $
    build/GSAP01-DEBUG/obj/auto_03_801DA4BC_text.o $
    build/GSAP01-DEBUG/obj/pressureSwitch.o $
    build/GSAP01-DEBUG/obj/auto_07_80311950_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DA9B4_text.o $
    build/GSAP01-DEBUG/obj/door.o $
    build/GSAP01-DEBUG/obj/auto_03_801DAF64_text.o $
    build/GSAP01-DEBUG/obj/dll_118.o $
    build/GSAP01-DEBUG/obj/auto_07_80311A28_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DB7D0_text.o $
    build/GSAP01-DEBUG/obj/useObj.o $
    build/GSAP01-DEBUG/obj/auto_07_80311AE0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DBE04_text.o $
    build/GSAP01-DEBUG/obj/seqObj.o $
    build/GSAP01-DEBUG/obj/auto_03_801DC254_text.o $
    build/GSAP01-DEBUG/obj/newSeqObj.o $
    build/GSAP01-DEBUG/obj/auto_03_801DC670_text.o $
    build/GSAP01-DEBUG/obj/seqObj11D.o $
    build/GSAP01-DEBUG/obj/auto_03_801DCA44_text.o $
    build/GSAP01-DEBUG/obj/seqObj11E.o $
    build/GSAP01-DEBUG/obj/auto_07_80311E40_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DCE84_text.o $
    build/GSAP01-DEBUG/obj/dll_11F.o $
    build/GSAP01-DEBUG/obj/auto_03_801DD1A8_text.o $
    build/GSAP01-DEBUG/obj/foodbag120.o $
    build/GSAP01-DEBUG/obj/auto_07_80312048_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DDAAC_text.o $
    build/GSAP01-DEBUG/obj/foodMenu.o build/GSAP01-DEBUG/obj/fruit.o $
    build/GSAP01-DEBUG/obj/auto_07_803121E8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DF60C_text.o $
    build/GSAP01-DEBUG/obj/fruitBranch.o $
    build/GSAP01-DEBUG/obj/auto_07_80312240_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801DFF28_text.o $
    build/GSAP01-DEBUG/obj/dll_124.o $
    build/GSAP01-DEBUG/obj/auto_07_80312328_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801E1078_text.o $
    build/GSAP01-DEBUG/obj/dll_125.o $
    build/GSAP01-DEBUG/obj/auto_03_801E2630_text.o $
    build/GSAP01-DEBUG/obj/talkObj.o $
    build/GSAP01-DEBUG/obj/auto_07_803123F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801E2A18_text.o $
    build/GSAP01-DEBUG/obj/interactObj.o $
    build/GSAP01-DEBUG/obj/auto_07_80312480_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801E2DF8_text.o $
    build/GSAP01-DEBUG/obj/magicPlant.o $
    build/GSAP01-DEBUG/obj/auto_03_801E31BC_text.o $
    build/GSAP01-DEBUG/obj/dll_10A.o $
    build/GSAP01-DEBUG/obj/auto_03_801E3D18_text.o $
    build/GSAP01-DEBUG/obj/dll_10B.o $
    build/GSAP01-DEBUG/obj/auto_03_801E3F64_text.o $
    build/GSAP01-DEBUG/obj/duster.o $
    build/GSAP01-DEBUG/obj/auto_03_801E4668_text.o $
    build/GSAP01-DEBUG/obj/fish.o $
    build/GSAP01-DEBUG/obj/auto_07_80312618_data.o $
    build/GSAP01-DEBUG/obj/smallbasket.o $
    build/GSAP01-DEBUG/obj/auto_03_801E5A10_text.o $
    build/GSAP01-DEBUG/obj/mediumbasket.o $
    build/GSAP01-DEBUG/obj/auto_07_803126D8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801E7244_text.o $
    build/GSAP01-DEBUG/obj/scarab.o $
    build/GSAP01-DEBUG/obj/auto_07_80312758_data.o $
    build/GSAP01-DEBUG/obj/auto_06_802D02F8_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_801E87F4_text.o $
    build/GSAP01-DEBUG/obj/zBomb.o $
    build/GSAP01-DEBUG/obj/auto_03_801E975C_text.o $
    build/GSAP01-DEBUG/obj/dll_111.o $
    build/GSAP01-DEBUG/obj/auto_03_801E9A28_text.o $
    build/GSAP01-DEBUG/obj/dll_112.o $
    build/GSAP01-DEBUG/obj/auto_03_801EA058_text.o $
    build/GSAP01-DEBUG/obj/dll_117.o $
    build/GSAP01-DEBUG/obj/auto_03_801EA4E8_text.o $
    build/GSAP01-DEBUG/obj/fireflyLantern.o $
    build/GSAP01-DEBUG/obj/auto_03_801EB0D8_text.o $
    build/GSAP01-DEBUG/obj/dll_115.o $
    build/GSAP01-DEBUG/obj/auto_03_801EB39C_text.o $
    build/GSAP01-DEBUG/obj/dll_EE.o $
    build/GSAP01-DEBUG/obj/auto_07_80312940_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801EB8F4_text.o $
    build/GSAP01-DEBUG/obj/barrel.o $
    build/GSAP01-DEBUG/obj/auto_03_801EBC94_text.o $
    build/GSAP01-DEBUG/obj/ladders.o $
    build/GSAP01-DEBUG/obj/auto_03_801EBF30_text.o $
    build/GSAP01-DEBUG/obj/dll_128.o $
    build/GSAP01-DEBUG/obj/auto_03_801EC18C_text.o $
    build/GSAP01-DEBUG/obj/waterfallControl.o $
    build/GSAP01-DEBUG/obj/auto_07_80312A60_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801EC288_text.o $
    build/GSAP01-DEBUG/obj/backpack.o $
    build/GSAP01-DEBUG/obj/auto_08_80395A60_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_801EC694_text.o $
    build/GSAP01-DEBUG/obj/dll_F5.o $
    build/GSAP01-DEBUG/obj/auto_03_801ECECC_text.o $
    build/GSAP01-DEBUG/obj/dll_12B.o $
    build/GSAP01-DEBUG/obj/auto_03_801ED16C_text.o $
    build/GSAP01-DEBUG/obj/landedArwing.o $
    build/GSAP01-DEBUG/obj/auto_07_80312C60_data.o $
    build/GSAP01-DEBUG/obj/staffAction.o $
    build/GSAP01-DEBUG/obj/auto_03_801ED6B0_text.o $
    build/GSAP01-DEBUG/obj/treasurechest.o $
    build/GSAP01-DEBUG/obj/auto_03_801EE608_text.o $
    build/GSAP01-DEBUG/obj/dll_131.o $
    build/GSAP01-DEBUG/obj/auto_03_801EE958_text.o $
    build/GSAP01-DEBUG/obj/dll_134.o $
    build/GSAP01-DEBUG/obj/auto_03_801EEB34_text.o $
    build/GSAP01-DEBUG/obj/campfire.o $
    build/GSAP01-DEBUG/obj/auto_03_801EF104_text.o $
    build/GSAP01-DEBUG/obj/dll_13B.o $
    build/GSAP01-DEBUG/obj/auto_03_801EF2E0_text.o $
    build/GSAP01-DEBUG/obj/dll_13C.o $
    build/GSAP01-DEBUG/obj/auto_03_801EF924_text.o $
    build/GSAP01-DEBUG/obj/dll_132.o $
    build/GSAP01-DEBUG/obj/auto_03_801EFB84_text.o $
    build/GSAP01-DEBUG/obj/fire.o $
    build/GSAP01-DEBUG/obj/auto_03_801EFE48_text.o $
    build/GSAP01-DEBUG/obj/genprops.o $
    build/GSAP01-DEBUG/obj/auto_07_80312F80_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F1E58_text.o $
    build/GSAP01-DEBUG/obj/gfxEmit.o $
    build/GSAP01-DEBUG/obj/auto_07_80313010_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F2594_text.o $
    build/GSAP01-DEBUG/obj/dll_13F.o $
    build/GSAP01-DEBUG/obj/auto_03_801F3080_text.o $
    build/GSAP01-DEBUG/obj/dll_141.o $
    build/GSAP01-DEBUG/obj/auto_03_801F3FF4_text.o $
    build/GSAP01-DEBUG/obj/dll_138.o $
    build/GSAP01-DEBUG/obj/auto_03_801F4A3C_text.o $
    build/GSAP01-DEBUG/obj/transporter.o $
    build/GSAP01-DEBUG/obj/auto_03_801F560C_text.o $
    build/GSAP01-DEBUG/obj/autoTransporter.o $
    build/GSAP01-DEBUG/obj/auto_07_803131B8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F606C_text.o $
    build/GSAP01-DEBUG/obj/dll_13E.o $
    build/GSAP01-DEBUG/obj/auto_03_801F6194_text.o $
    build/GSAP01-DEBUG/obj/dll_140.o $
    build/GSAP01-DEBUG/obj/auto_03_801F6418_text.o $
    build/GSAP01-DEBUG/obj/tFrameAnimator.o $
    build/GSAP01-DEBUG/obj/auto_03_801F6668_text.o $
    build/GSAP01-DEBUG/obj/screenOverlay.o $
    build/GSAP01-DEBUG/obj/auto_07_803132F0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F6A34_text.o $
    build/GSAP01-DEBUG/obj/dll_145.o $
    build/GSAP01-DEBUG/obj/auto_03_801F6BFC_text.o $
    build/GSAP01-DEBUG/obj/texScroll.o $
    build/GSAP01-DEBUG/obj/auto_03_801F6F38_text.o $
    build/GSAP01-DEBUG/obj/dll_147.o $
    build/GSAP01-DEBUG/obj/auto_03_801F7094_text.o $
    build/GSAP01-DEBUG/obj/dll_148.o $
    build/GSAP01-DEBUG/obj/auto_07_803134A8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F77EC_text.o $
    build/GSAP01-DEBUG/obj/alphaanim.o $
    build/GSAP01-DEBUG/obj/auto_07_80313508_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F7FDC_text.o $
    build/GSAP01-DEBUG/obj/groundAnimator.o $
    build/GSAP01-DEBUG/obj/auto_07_80313590_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F8B64_text.o $
    build/GSAP01-DEBUG/obj/crackanim.o $
    build/GSAP01-DEBUG/obj/auto_07_80313628_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F8EB0_text.o $
    build/GSAP01-DEBUG/obj/dll_14C.o $
    build/GSAP01-DEBUG/obj/auto_03_801F91C0_text.o $
    build/GSAP01-DEBUG/obj/dll_14D.o $
    build/GSAP01-DEBUG/obj/auto_03_801F9384_text.o $
    build/GSAP01-DEBUG/obj/dll_14E.o $
    build/GSAP01-DEBUG/obj/auto_07_803136F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801F9800_text.o $
    build/GSAP01-DEBUG/obj/dll_14F.o $
    build/GSAP01-DEBUG/obj/auto_03_801FAFB4_text.o $
    build/GSAP01-DEBUG/obj/dll_150.o $
    build/GSAP01-DEBUG/obj/auto_03_801FB134_text.o $
    build/GSAP01-DEBUG/obj/exploder.o $
    build/GSAP01-DEBUG/obj/auto_03_801FBBB0_text.o $
    build/GSAP01-DEBUG/obj/dll_152.o $
    build/GSAP01-DEBUG/obj/auto_03_801FC368_text.o $
    build/GSAP01-DEBUG/obj/dll_153.o $
    build/GSAP01-DEBUG/obj/auto_07_80313920_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801FCAA4_text.o $
    build/GSAP01-DEBUG/obj/tFrameAnimator154.o $
    build/GSAP01-DEBUG/obj/auto_03_801FD3D0_text.o $
    build/GSAP01-DEBUG/obj/dll_155.o $
    build/GSAP01-DEBUG/obj/auto_07_803139E8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_801FD81C_text.o $
    build/GSAP01-DEBUG/obj/dll_144.o $
    build/GSAP01-DEBUG/obj/auto_03_801FDD38_text.o $
    build/GSAP01-DEBUG/obj/trigger.o $
    build/GSAP01-DEBUG/obj/auto_03_801FE7A8_text.o $
    build/GSAP01-DEBUG/obj/dll_16C.o $
    build/GSAP01-DEBUG/obj/auto_03_80200F60_text.o $
    build/GSAP01-DEBUG/obj/dll_159.o $
    build/GSAP01-DEBUG/obj/auto_08_80395B18_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_803146D8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80201338_text.o $
    build/GSAP01-DEBUG/obj/dll_15A.o $
    build/GSAP01-DEBUG/obj/auto_08_80395CE0_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_80201968_text.o $
    build/GSAP01-DEBUG/obj/dll_15B.o $
    build/GSAP01-DEBUG/obj/auto_07_803147A0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802023FC_text.o $
    build/GSAP01-DEBUG/obj/CFguardian.o $
    build/GSAP01-DEBUG/obj/auto_06_802D03B8_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80202B08_text.o $
    build/GSAP01-DEBUG/obj/windlift.o $
    build/GSAP01-DEBUG/obj/auto_07_80314C68_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80204E70_text.o $
    build/GSAP01-DEBUG/obj/dll_15E.o $
    build/GSAP01-DEBUG/obj/auto_03_80205698_text.o $
    build/GSAP01-DEBUG/obj/CFcrystal.o $
    build/GSAP01-DEBUG/obj/auto_03_802059B8_text.o $
    build/GSAP01-DEBUG/obj/CFBaby.o $
    build/GSAP01-DEBUG/obj/auto_03_80206E34_text.o $
    build/GSAP01-DEBUG/obj/laser.o $
    build/GSAP01-DEBUG/obj/auto_03_8020797C_text.o $
    build/GSAP01-DEBUG/obj/CFPrisonGuard.o $
    build/GSAP01-DEBUG/obj/auto_03_80207D38_text.o $
    build/GSAP01-DEBUG/obj/dll_163.o $
    build/GSAP01-DEBUG/obj/auto_03_8020860C_text.o $
    build/GSAP01-DEBUG/obj/dll_164.o $
    build/GSAP01-DEBUG/obj/auto_03_8020879C_text.o $
    build/GSAP01-DEBUG/obj/dll_165.o $
    build/GSAP01-DEBUG/obj/auto_03_80208818_text.o $
    build/GSAP01-DEBUG/obj/dll_166.o $
    build/GSAP01-DEBUG/obj/auto_03_802088B0_text.o $
    build/GSAP01-DEBUG/obj/robotpatrol.o $
    build/GSAP01-DEBUG/obj/auto_03_802090FC_text.o $
    build/GSAP01-DEBUG/obj/dll_168.o $
    build/GSAP01-DEBUG/obj/auto_03_8020AEA0_text.o $
    build/GSAP01-DEBUG/obj/dll_169.o $
    build/GSAP01-DEBUG/obj/auto_03_8020AF70_text.o $
    build/GSAP01-DEBUG/obj/dll_16A.o $
    build/GSAP01-DEBUG/obj/auto_03_8020B050_text.o $
    build/GSAP01-DEBUG/obj/dll_16B.o $
    build/GSAP01-DEBUG/obj/auto_03_8020B278_text.o $
    build/GSAP01-DEBUG/obj/CFtoggleswitch.o $
    build/GSAP01-DEBUG/obj/auto_03_8020B67C_text.o $
    build/GSAP01-DEBUG/obj/dll_16E.o $
    build/GSAP01-DEBUG/obj/auto_07_803151B0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8020B964_text.o $
    build/GSAP01-DEBUG/obj/DRbarrelplace.o $
    build/GSAP01-DEBUG/obj/auto_07_80315308_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8020C3C0_text.o $
    build/GSAP01-DEBUG/obj/dll_170.o $
    build/GSAP01-DEBUG/obj/auto_03_8020D5A0_text.o $
    build/GSAP01-DEBUG/obj/SimpleExploder.o $
    build/GSAP01-DEBUG/obj/auto_07_80315558_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8020DA34_text.o $
    build/GSAP01-DEBUG/obj/dll_172.o $
    build/GSAP01-DEBUG/obj/auto_03_8020E4D8_text.o $
    build/GSAP01-DEBUG/obj/CFforcecontrol.o $
    build/GSAP01-DEBUG/obj/auto_03_8020E8D4_text.o $
    build/GSAP01-DEBUG/obj/dll_174.o $
    build/GSAP01-DEBUG/obj/auto_03_8020F278_text.o $
    build/GSAP01-DEBUG/obj/dll_175.o $
    build/GSAP01-DEBUG/obj/auto_03_8020F81C_text.o $
    build/GSAP01-DEBUG/obj/dll_176.o $
    build/GSAP01-DEBUG/obj/auto_03_8020F98C_text.o $
    build/GSAP01-DEBUG/obj/robot.o $
    build/GSAP01-DEBUG/obj/auto_03_80210834_text.o $
    build/GSAP01-DEBUG/obj/treasureRelated0177.o $
    build/GSAP01-DEBUG/obj/auto_03_802118D0_text.o $
    build/GSAP01-DEBUG/obj/dll_179.o $
    build/GSAP01-DEBUG/obj/auto_03_80211F28_text.o $
    build/GSAP01-DEBUG/obj/dll_17A.o $
    build/GSAP01-DEBUG/obj/auto_03_80212360_text.o $
    build/GSAP01-DEBUG/obj/CFlevelControl.o $
    build/GSAP01-DEBUG/obj/auto_03_80212704_text.o $
    build/GSAP01-DEBUG/obj/CFTreasSharpy.o $
    build/GSAP01-DEBUG/obj/auto_07_80315C50_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80213384_text.o $
    build/GSAP01-DEBUG/obj/CFchuckobj.o $
    build/GSAP01-DEBUG/obj/auto_03_80214768_text.o $
    build/GSAP01-DEBUG/obj/CFwalltorch.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0440_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80214D2C_text.o $
    build/GSAP01-DEBUG/obj/dll_17F.o $
    build/GSAP01-DEBUG/obj/auto_07_80315E58_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802153D0_text.o $
    build/GSAP01-DEBUG/obj/dll_180.o $
    build/GSAP01-DEBUG/obj/auto_03_80215E98_text.o $
    build/GSAP01-DEBUG/obj/holoPoint.o $
    build/GSAP01-DEBUG/obj/auto_03_80216004_text.o $
    build/GSAP01-DEBUG/obj/dll_182.o $
    build/GSAP01-DEBUG/obj/auto_07_80315F80_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80216398_text.o $
    build/GSAP01-DEBUG/obj/dll_1A0.o $
    build/GSAP01-DEBUG/obj/auto_03_80219700_text.o $
    build/GSAP01-DEBUG/obj/dll_1A1.o $
    build/GSAP01-DEBUG/obj/auto_03_80219D5C_text.o $
    build/GSAP01-DEBUG/obj/dll_1A2.o $
    build/GSAP01-DEBUG/obj/auto_03_80219E18_text.o $
    build/GSAP01-DEBUG/obj/mmp_barrel.o $
    build/GSAP01-DEBUG/obj/auto_07_803160B0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8021A4F0_text.o $
    build/GSAP01-DEBUG/obj/mmp_levelcontrol.o $
    build/GSAP01-DEBUG/obj/auto_07_80316148_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8021A81C_text.o $
    build/GSAP01-DEBUG/obj/dll_1A5.o $
    build/GSAP01-DEBUG/obj/auto_03_8021AB2C_text.o $
    build/GSAP01-DEBUG/obj/MMP_asteroid.o $
    build/GSAP01-DEBUG/obj/auto_03_8021B480_text.o $
    build/GSAP01-DEBUG/obj/MMP_moonrock.o $
    build/GSAP01-DEBUG/obj/auto_08_80395D48_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_80316210_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8021BB5C_text.o $
    build/GSAP01-DEBUG/obj/dll_1A7.o $
    build/GSAP01-DEBUG/obj/auto_03_8021C41C_text.o $
    build/GSAP01-DEBUG/obj/MMP_gyservent.o $
    build/GSAP01-DEBUG/obj/auto_03_8021C59C_text.o $
    build/GSAP01-DEBUG/obj/dll_1AA.o $
    build/GSAP01-DEBUG/obj/auto_03_8021CB74_text.o $
    build/GSAP01-DEBUG/obj/cage.o $
    build/GSAP01-DEBUG/obj/auto_03_8021D400_text.o $
    build/GSAP01-DEBUG/obj/dll_1AC.o $
    build/GSAP01-DEBUG/obj/auto_03_8021D8E4_text.o $
    build/GSAP01-DEBUG/obj/dll_1AD.o $
    build/GSAP01-DEBUG/obj/auto_03_8021DAA0_text.o $
    build/GSAP01-DEBUG/obj/dll_1AE.o $
    build/GSAP01-DEBUG/obj/auto_03_8021DCEC_text.o $
    build/GSAP01-DEBUG/obj/dll_1B0.o $
    build/GSAP01-DEBUG/obj/auto_03_8021E034_text.o $
    build/GSAP01-DEBUG/obj/fireCrystalLightRelated01AF.o $
    build/GSAP01-DEBUG/obj/auto_07_80316480_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8021E448_text.o $
    build/GSAP01-DEBUG/obj/dll_1B1.o $
    build/GSAP01-DEBUG/obj/auto_03_8021E9EC_text.o $
    build/GSAP01-DEBUG/obj/hightop.o $
    build/GSAP01-DEBUG/obj/auto_07_80316520_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8021EF48_text.o $
    build/GSAP01-DEBUG/obj/dll_1B3.o $
    build/GSAP01-DEBUG/obj/auto_03_8021F12C_text.o $
    build/GSAP01-DEBUG/obj/dll_1B4.o $
    build/GSAP01-DEBUG/obj/auto_03_8021FD14_text.o $
    build/GSAP01-DEBUG/obj/dll_1B5.o $
    build/GSAP01-DEBUG/obj/auto_03_8022012C_text.o $
    build/GSAP01-DEBUG/obj/dll_1B6.o $
    build/GSAP01-DEBUG/obj/auto_03_80220294_text.o $
    build/GSAP01-DEBUG/obj/dll_1B7.o $
    build/GSAP01-DEBUG/obj/auto_03_80220774_text.o $
    build/GSAP01-DEBUG/obj/sandwormBoss.o $
    build/GSAP01-DEBUG/obj/auto_03_80221A5C_text.o $
    build/GSAP01-DEBUG/obj/dll_1B9.o $
    build/GSAP01-DEBUG/obj/auto_07_80316770_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80221DB0_text.o $
    build/GSAP01-DEBUG/obj/gasvent.o $
    build/GSAP01-DEBUG/obj/auto_03_80221F68_text.o $
    build/GSAP01-DEBUG/obj/dll_1BC.o $
    build/GSAP01-DEBUG/obj/auto_03_80222018_text.o $
    build/GSAP01-DEBUG/obj/dll_1BD.o $
    build/GSAP01-DEBUG/obj/auto_03_8022220C_text.o $
    build/GSAP01-DEBUG/obj/cannontargetControl.o $
    build/GSAP01-DEBUG/obj/auto_03_802224D8_text.o $
    build/GSAP01-DEBUG/obj/gasventControl.o $
    build/GSAP01-DEBUG/obj/auto_07_803168C8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80222974_text.o $
    build/GSAP01-DEBUG/obj/dll_183.o $
    build/GSAP01-DEBUG/obj/auto_03_80222CF4_text.o $
    build/GSAP01-DEBUG/obj/IMicicle.o $
    build/GSAP01-DEBUG/obj/auto_07_80316968_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022388C_text.o $
    build/GSAP01-DEBUG/obj/dll_185.o $
    build/GSAP01-DEBUG/obj/auto_03_80223EE0_text.o $
    build/GSAP01-DEBUG/obj/dll_186.o $
    build/GSAP01-DEBUG/obj/auto_03_80224464_text.o $
    build/GSAP01-DEBUG/obj/dll_187.o $
    build/GSAP01-DEBUG/obj/auto_03_802249A8_text.o $
    build/GSAP01-DEBUG/obj/IMspacecraft.o $
    build/GSAP01-DEBUG/obj/auto_03_80224D84_text.o $
    build/GSAP01-DEBUG/obj/dll_189.o $
    build/GSAP01-DEBUG/obj/auto_03_80225318_text.o $
    build/GSAP01-DEBUG/obj/dll_18A.o $
    build/GSAP01-DEBUG/obj/auto_03_802254D8_text.o $
    build/GSAP01-DEBUG/obj/dll_18B.o $
    build/GSAP01-DEBUG/obj/auto_03_80225854_text.o $
    build/GSAP01-DEBUG/obj/DIMlavaball.o $
    build/GSAP01-DEBUG/obj/auto_07_80316B50_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80225FD8_text.o $
    build/GSAP01-DEBUG/obj/dimlavagen.o $
    build/GSAP01-DEBUG/obj/auto_07_80316BE8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80226680_text.o $
    build/GSAP01-DEBUG/obj/DIMlogfire.o $
    build/GSAP01-DEBUG/obj/auto_03_80226AF0_text.o $
    build/GSAP01-DEBUG/obj/DIMsnowball.o $
    build/GSAP01-DEBUG/obj/auto_03_80227270_text.o $
    build/GSAP01-DEBUG/obj/dll_204.o $
    build/GSAP01-DEBUG/obj/auto_03_8022745C_text.o $
    build/GSAP01-DEBUG/obj/dll_205.o $
    build/GSAP01-DEBUG/obj/auto_03_8022764C_text.o $
    build/GSAP01-DEBUG/obj/dll_206.o $
    build/GSAP01-DEBUG/obj/auto_03_8022791C_text.o $
    build/GSAP01-DEBUG/obj/DIMboulder.o $
    build/GSAP01-DEBUG/obj/auto_07_80318628_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80227EF8_text.o $
    build/GSAP01-DEBUG/obj/DIMcannon.o $
    build/GSAP01-DEBUG/obj/auto_03_8022877C_text.o $
    build/GSAP01-DEBUG/obj/DIMlavasmash.o $
    build/GSAP01-DEBUG/obj/auto_03_80229600_text.o $
    build/GSAP01-DEBUG/obj/dll_20A.o $
    build/GSAP01-DEBUG/obj/auto_03_80229994_text.o $
    build/GSAP01-DEBUG/obj/dll_20B.o $
    build/GSAP01-DEBUG/obj/auto_03_80229BB0_text.o $
    build/GSAP01-DEBUG/obj/DIMExplosion.o $
    build/GSAP01-DEBUG/obj/auto_03_80229F14_text.o $
    build/GSAP01-DEBUG/obj/DIMwooddoor.o $
    build/GSAP01-DEBUG/obj/auto_03_8022A2E8_text.o $
    build/GSAP01-DEBUG/obj/dll_210.o $
    build/GSAP01-DEBUG/obj/auto_03_8022A694_text.o $
    build/GSAP01-DEBUG/obj/dll_20E.o $
    build/GSAP01-DEBUG/obj/auto_03_8022AE40_text.o $
    build/GSAP01-DEBUG/obj/DIMlevcontrol.o $
    build/GSAP01-DEBUG/obj/auto_07_80318858_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022B308_text.o $
    build/GSAP01-DEBUG/obj/dll_211.o $
    build/GSAP01-DEBUG/obj/auto_07_803188A0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022B400_text.o $
    build/GSAP01-DEBUG/obj/DIM2conveyor.o $
    build/GSAP01-DEBUG/obj/auto_07_803188E8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022B5CC_text.o $
    build/GSAP01-DEBUG/obj/DIM2flameburst.o $
    build/GSAP01-DEBUG/obj/auto_03_8022BE44_text.o $
    build/GSAP01-DEBUG/obj/DIM2snowball.o $
    build/GSAP01-DEBUG/obj/auto_07_803189D0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022C4DC_text.o $
    build/GSAP01-DEBUG/obj/DIM2generator.o $
    build/GSAP01-DEBUG/obj/auto_07_80318AA0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022C9D8_text.o $
    build/GSAP01-DEBUG/obj/dll_219.o $
    build/GSAP01-DEBUG/obj/auto_03_8022CCF0_text.o $
    build/GSAP01-DEBUG/obj/DIM2projrock.o $
    build/GSAP01-DEBUG/obj/auto_07_80318B28_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022D580_text.o $
    build/GSAP01-DEBUG/obj/DIM2lift.o $
    build/GSAP01-DEBUG/obj/auto_03_8022DA04_text.o $
    build/GSAP01-DEBUG/obj/DIM2icefloe.o $
    build/GSAP01-DEBUG/obj/auto_07_80318C38_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8022DE40_text.o $
    build/GSAP01-DEBUG/obj/DIM2icicle.o $
    build/GSAP01-DEBUG/obj/auto_03_8022E2D4_text.o $
    build/GSAP01-DEBUG/obj/dll_21E.o $
    build/GSAP01-DEBUG/obj/auto_03_8022E404_text.o $
    build/GSAP01-DEBUG/obj/dll_21F.o $
    build/GSAP01-DEBUG/obj/auto_03_8022EB70_text.o $
    build/GSAP01-DEBUG/obj/DIMboss.o $
    build/GSAP01-DEBUG/obj/auto_08_80396280_bss.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0640_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_8022F478_text.o $
    build/GSAP01-DEBUG/obj/dll_221.o $
    build/GSAP01-DEBUG/obj/auto_03_80232518_text.o $
    build/GSAP01-DEBUG/obj/DIMbosstonsil.o $
    build/GSAP01-DEBUG/obj/auto_03_80232A4C_text.o $
    build/GSAP01-DEBUG/obj/dll_223.o $
    build/GSAP01-DEBUG/obj/auto_03_80233A74_text.o $
    build/GSAP01-DEBUG/obj/DIMbossspit.o $
    build/GSAP01-DEBUG/obj/auto_03_80234230_text.o $
    build/GSAP01-DEBUG/obj/dll_224.o $
    build/GSAP01-DEBUG/obj/auto_03_80234940_text.o $
    build/GSAP01-DEBUG/obj/dll_226.o $
    build/GSAP01-DEBUG/obj/auto_03_80234AF0_text.o $
    build/GSAP01-DEBUG/obj/dll_227.o $
    build/GSAP01-DEBUG/obj/auto_07_80319158_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80234F48_text.o $
    build/GSAP01-DEBUG/obj/riverFlowRelated018D.o $
    build/GSAP01-DEBUG/obj/auto_03_802351C4_text.o $
    build/GSAP01-DEBUG/obj/dll_18E.o $
    build/GSAP01-DEBUG/obj/auto_03_802353E4_text.o $
    build/GSAP01-DEBUG/obj/rope.o $
    build/GSAP01-DEBUG/obj/auto_06_802D06B0_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_8023670C_text.o $
    build/GSAP01-DEBUG/obj/DFcradle.o $
    build/GSAP01-DEBUG/obj/auto_03_80237980_text.o $
    build/GSAP01-DEBUG/obj/DFpulley.o $
    build/GSAP01-DEBUG/obj/auto_07_803193A0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80237E04_text.o $
    build/GSAP01-DEBUG/obj/DFbarrel.o $
    build/GSAP01-DEBUG/obj/auto_03_8023804C_text.o $
    build/GSAP01-DEBUG/obj/DFbarrelanim.o $
    build/GSAP01-DEBUG/obj/auto_07_803193F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80238AC0_text.o $
    build/GSAP01-DEBUG/obj/dll_194.o $
    build/GSAP01-DEBUG/obj/auto_03_80238CA0_text.o $
    build/GSAP01-DEBUG/obj/dll_195.o $
    build/GSAP01-DEBUG/obj/auto_03_80238DA0_text.o $
    build/GSAP01-DEBUG/obj/dll_196.o $
    build/GSAP01-DEBUG/obj/auto_03_8023901C_text.o $
    build/GSAP01-DEBUG/obj/DFmole.o $
    build/GSAP01-DEBUG/obj/auto_08_80396308_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_80239434_text.o $
    build/GSAP01-DEBUG/obj/DFwhirlpool.o $
    build/GSAP01-DEBUG/obj/auto_03_8023A894_text.o $
    build/GSAP01-DEBUG/obj/dll_198.o $
    build/GSAP01-DEBUG/obj/auto_03_8023AB10_text.o $
    build/GSAP01-DEBUG/obj/dll_199.o $
    build/GSAP01-DEBUG/obj/auto_03_8023AE8C_text.o $
    build/GSAP01-DEBUG/obj/DFlantern.o $
    build/GSAP01-DEBUG/obj/auto_03_8023B6FC_text.o $
    build/GSAP01-DEBUG/obj/dll_19C.o $
    build/GSAP01-DEBUG/obj/auto_03_8023C32C_text.o $
    build/GSAP01-DEBUG/obj/dll_19E.o $
    build/GSAP01-DEBUG/obj/auto_03_8023CEA0_text.o $
    build/GSAP01-DEBUG/obj/creator19D.o $
    build/GSAP01-DEBUG/obj/auto_03_8023D284_text.o $
    build/GSAP01-DEBUG/obj/laser19F.o $
    build/GSAP01-DEBUG/obj/auto_03_8023DDF0_text.o $
    build/GSAP01-DEBUG/obj/mmshrine/shrine.o $
    build/GSAP01-DEBUG/obj/auto_07_80319840_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8023E734_text.o $
    build/GSAP01-DEBUG/obj/animobj1C0.o $
    build/GSAP01-DEBUG/obj/auto_03_8023EBAC_text.o $
    build/GSAP01-DEBUG/obj/torch1C1.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0720_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_8023F430_text.o $
    build/GSAP01-DEBUG/obj/shrine1C2.o $
    build/GSAP01-DEBUG/obj/auto_03_802405C4_text.o $
    build/GSAP01-DEBUG/obj/creator1C4.o $
    build/GSAP01-DEBUG/obj/auto_03_80240C74_text.o $
    build/GSAP01-DEBUG/obj/dll_1C5.o $
    build/GSAP01-DEBUG/obj/auto_08_80396338_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_80241830_text.o $
    build/GSAP01-DEBUG/obj/creator1C6.o $
    build/GSAP01-DEBUG/obj/auto_03_80242048_text.o $
    build/GSAP01-DEBUG/obj/scene1C7.o $
    build/GSAP01-DEBUG/obj/auto_03_802422D4_text.o $
    build/GSAP01-DEBUG/obj/flybaddie.o $
    build/GSAP01-DEBUG/obj/auto_03_80242844_text.o $
    build/GSAP01-DEBUG/obj/colrise.o $
    build/GSAP01-DEBUG/obj/auto_07_80319C30_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80242E70_text.o $
    build/GSAP01-DEBUG/obj/cup1C3.o $
    build/GSAP01-DEBUG/obj/auto_03_80243698_text.o $
    build/GSAP01-DEBUG/obj/dll_1CA.o $
    build/GSAP01-DEBUG/obj/auto_07_80319CC8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8024417C_text.o $
    build/GSAP01-DEBUG/obj/symbol.o $
    build/GSAP01-DEBUG/obj/auto_03_80244A4C_text.o $
    build/GSAP01-DEBUG/obj/dll_1CC.o $
    build/GSAP01-DEBUG/obj/auto_03_802453CC_text.o $
    build/GSAP01-DEBUG/obj/torch1CD.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0750_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80245D78_text.o $
    build/GSAP01-DEBUG/obj/shrine1CE.o $
    build/GSAP01-DEBUG/obj/auto_03_80246778_text.o $
    build/GSAP01-DEBUG/obj/creator1CF.o $
    build/GSAP01-DEBUG/obj/auto_07_80319EB8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80246FF8_text.o $
    build/GSAP01-DEBUG/obj/dll_1D0.o $
    build/GSAP01-DEBUG/obj/auto_03_80247444_text.o $
    build/GSAP01-DEBUG/obj/dll_1D1.o $
    build/GSAP01-DEBUG/obj/auto_03_802476AC_text.o $
    build/GSAP01-DEBUG/obj/ped.o $
    build/GSAP01-DEBUG/obj/auto_03_80247C6C_text.o $
    build/GSAP01-DEBUG/obj/dll_1D3.o $
    build/GSAP01-DEBUG/obj/auto_03_802487A8_text.o $
    build/GSAP01-DEBUG/obj/creator1D4.o $
    build/GSAP01-DEBUG/obj/auto_03_80248E8C_text.o $
    build/GSAP01-DEBUG/obj/dll_1D5.o $
    build/GSAP01-DEBUG/obj/auto_07_8031A078_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802498FC_text.o $
    build/GSAP01-DEBUG/obj/creator1D6.o $
    build/GSAP01-DEBUG/obj/auto_07_8031A128_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80249ED0_text.o $
    build/GSAP01-DEBUG/obj/flybaddie1D7.o $
    build/GSAP01-DEBUG/obj/auto_03_8024A4A8_text.o $
    build/GSAP01-DEBUG/obj/projball1D8.o $
    build/GSAP01-DEBUG/obj/auto_03_8024AEB4_text.o $
    build/GSAP01-DEBUG/obj/torch1D9.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0770_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_8024B7A8_text.o $
    build/GSAP01-DEBUG/obj/NWsfx.o $
    build/GSAP01-DEBUG/obj/auto_03_8024B938_text.o $
    build/GSAP01-DEBUG/obj/dll_1DB.o $
    build/GSAP01-DEBUG/obj/auto_03_8024BB6C_text.o $
    build/GSAP01-DEBUG/obj/dll_1DC.o $
    build/GSAP01-DEBUG/obj/auto_03_8024BEDC_text.o $
    build/GSAP01-DEBUG/obj/NWmammoth.o $
    build/GSAP01-DEBUG/obj/auto_03_8024C710_text.o $
    build/GSAP01-DEBUG/obj/NWtricky.o $
    build/GSAP01-DEBUG/obj/auto_07_8031A630_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8024DF94_text.o $
    build/GSAP01-DEBUG/obj/dll_1DF.o $
    build/GSAP01-DEBUG/obj/auto_03_8024E2C8_text.o $
    build/GSAP01-DEBUG/obj/dll_1E0.o $
    build/GSAP01-DEBUG/obj/auto_03_8024E4B4_text.o $
    build/GSAP01-DEBUG/obj/dll_1E1.o $
    build/GSAP01-DEBUG/obj/auto_03_8024E6D8_text.o $
    build/GSAP01-DEBUG/obj/dll_1E2.o $
    build/GSAP01-DEBUG/obj/auto_03_8024E944_text.o $
    build/GSAP01-DEBUG/obj/SHmushroom.o $
    build/GSAP01-DEBUG/obj/auto_03_8024EF1C_text.o $
    build/GSAP01-DEBUG/obj/SHkillermushroom.o $
    build/GSAP01-DEBUG/obj/auto_03_8025064C_text.o $
    build/GSAP01-DEBUG/obj/SHrocketmushroom.o $
    build/GSAP01-DEBUG/obj/auto_03_80250FA8_text.o $
    build/GSAP01-DEBUG/obj/SHspore.o $
    build/GSAP01-DEBUG/obj/auto_03_80251C98_text.o $
    build/GSAP01-DEBUG/obj/dll_1E7.o $
    build/GSAP01-DEBUG/obj/auto_03_80251DEC_text.o $
    build/GSAP01-DEBUG/obj/lily.o $
    build/GSAP01-DEBUG/obj/auto_03_802520A4_text.o $
    build/GSAP01-DEBUG/obj/dll_1E8.o $
    build/GSAP01-DEBUG/obj/auto_07_8031AA48_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80252428_text.o $
    build/GSAP01-DEBUG/obj/SHthorntail.o $
    build/GSAP01-DEBUG/obj/auto_03_80252900_text.o $
    build/GSAP01-DEBUG/obj/SHroot.o $
    build/GSAP01-DEBUG/obj/auto_07_8031B070_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802543C8_text.o $
    build/GSAP01-DEBUG/obj/dll_1EC.o $
    build/GSAP01-DEBUG/obj/auto_03_802544D4_text.o $
    build/GSAP01-DEBUG/obj/dll_1F0.o $
    build/GSAP01-DEBUG/obj/auto_03_802547AC_text.o $
    build/GSAP01-DEBUG/obj/dll_1EE.o $
    build/GSAP01-DEBUG/obj/auto_03_80255008_text.o $
    build/GSAP01-DEBUG/obj/dll_1ED.o $
    build/GSAP01-DEBUG/obj/auto_03_802551C0_text.o $
    build/GSAP01-DEBUG/obj/dll_1EF.o $
    build/GSAP01-DEBUG/obj/auto_03_8025537C_text.o $
    build/GSAP01-DEBUG/obj/dll_1F1.o $
    build/GSAP01-DEBUG/obj/auto_03_8025592C_text.o $
    build/GSAP01-DEBUG/obj/SClevelcontrol.o $
    build/GSAP01-DEBUG/obj/auto_03_80255FBC_text.o $
    build/GSAP01-DEBUG/obj/SClightfoot.o $
    build/GSAP01-DEBUG/obj/auto_08_80396378_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_80256C1C_text.o $
    build/GSAP01-DEBUG/obj/dll_1F3.o $
    build/GSAP01-DEBUG/obj/auto_03_802581DC_text.o $
    build/GSAP01-DEBUG/obj/SCchieflightfoot.o $
    build/GSAP01-DEBUG/obj/auto_03_80258AE8_text.o $
    build/GSAP01-DEBUG/obj/SCbirchtree.o $
    build/GSAP01-DEBUG/obj/auto_07_8031B7E0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80259ED8_text.o $
    build/GSAP01-DEBUG/obj/SCtotempole.o $
    build/GSAP01-DEBUG/obj/auto_03_8025A8FC_text.o $
    build/GSAP01-DEBUG/obj/SClantern.o $
    build/GSAP01-DEBUG/obj/auto_07_8031B918_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8025B0C4_text.o $
    build/GSAP01-DEBUG/obj/SCcollectables.o $
    build/GSAP01-DEBUG/obj/auto_03_8025B96C_text.o $
    build/GSAP01-DEBUG/obj/SCanimobj.o $
    build/GSAP01-DEBUG/obj/auto_07_8031B9B8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8025C114_text.o $
    build/GSAP01-DEBUG/obj/SCtotemlogpuz.o $
    build/GSAP01-DEBUG/obj/auto_07_8031BA00_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8025C5EC_text.o $
    build/GSAP01-DEBUG/obj/SCtumbleweedmeter.o $
    build/GSAP01-DEBUG/obj/auto_03_8025C9D0_text.o $
    build/GSAP01-DEBUG/obj/SCtotembondpuz.o $
    build/GSAP01-DEBUG/obj/auto_03_8025CC24_text.o $
    build/GSAP01-DEBUG/obj/SCtotemstrength.o $
    build/GSAP01-DEBUG/obj/auto_07_8031BB40_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8025D690_text.o $
    build/GSAP01-DEBUG/obj/dll_1FF.o $
    build/GSAP01-DEBUG/obj/auto_03_8025E13C_text.o $
    build/GSAP01-DEBUG/obj/dll_157.o $
    build/GSAP01-DEBUG/obj/auto_03_8025E438_text.o $
    build/GSAP01-DEBUG/obj/dll_156.o $
    build/GSAP01-DEBUG/obj/auto_03_8025E87C_text.o $
    build/GSAP01-DEBUG/obj/dll_158.o $
    build/GSAP01-DEBUG/obj/auto_03_8025E914_text.o $
    build/GSAP01-DEBUG/obj/SBship.o $
    build/GSAP01-DEBUG/obj/auto_03_8025EEE4_text.o $
    build/GSAP01-DEBUG/obj/SBcloudrunner.o $
    build/GSAP01-DEBUG/obj/auto_07_8031BCC8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80261DF8_text.o $
    build/GSAP01-DEBUG/obj/SBpropeller.o $
    build/GSAP01-DEBUG/obj/auto_07_8031BD28_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802623BC_text.o $
    build/GSAP01-DEBUG/obj/SBshiphead.o $
    build/GSAP01-DEBUG/obj/auto_03_80262E4C_text.o $
    build/GSAP01-DEBUG/obj/dll_22C.o $
    build/GSAP01-DEBUG/obj/auto_03_80262FE0_text.o $
    build/GSAP01-DEBUG/obj/SBshipgun.o $
    build/GSAP01-DEBUG/obj/auto_03_80263A8C_text.o $
    build/GSAP01-DEBUG/obj/SBcannonball.o $
    build/GSAP01-DEBUG/obj/auto_03_80264308_text.o $
    build/GSAP01-DEBUG/obj/dll_22E.o $
    build/GSAP01-DEBUG/obj/auto_03_8026461C_text.o $
    build/GSAP01-DEBUG/obj/SBcloudball.o $
    build/GSAP01-DEBUG/obj/auto_03_80264DAC_text.o $
    build/GSAP01-DEBUG/obj/dll_231.o $
    build/GSAP01-DEBUG/obj/auto_03_802654DC_text.o $
    build/GSAP01-DEBUG/obj/SBcagedkyte.o $
    build/GSAP01-DEBUG/obj/auto_03_8026575C_text.o $
    build/GSAP01-DEBUG/obj/dll_232.o $
    build/GSAP01-DEBUG/obj/auto_03_8026586C_text.o $
    build/GSAP01-DEBUG/obj/dll_234.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0790_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80265D10_text.o $
    build/GSAP01-DEBUG/obj/dll_235.o $
    build/GSAP01-DEBUG/obj/auto_03_80266164_text.o $
    build/GSAP01-DEBUG/obj/scalesanim.o $
    build/GSAP01-DEBUG/obj/auto_03_80266560_text.o $
    build/GSAP01-DEBUG/obj/dll_236.o $
    build/GSAP01-DEBUG/obj/auto_03_8026712C_text.o $
    build/GSAP01-DEBUG/obj/dll_238.o $
    build/GSAP01-DEBUG/obj/auto_03_8026724C_text.o $
    build/GSAP01-DEBUG/obj/brokecannon.o $
    build/GSAP01-DEBUG/obj/auto_03_80267340_text.o $
    build/GSAP01-DEBUG/obj/SPshop.o $
    build/GSAP01-DEBUG/obj/auto_03_80267A24_text.o $
    build/GSAP01-DEBUG/obj/SPshopkeeper.o $
    build/GSAP01-DEBUG/obj/auto_03_80267DC8_text.o $
    build/GSAP01-DEBUG/obj/dll_2CB.o $
    build/GSAP01-DEBUG/obj/auto_03_802696CC_text.o $
    build/GSAP01-DEBUG/obj/SPscarab.o $
    build/GSAP01-DEBUG/obj/auto_03_80269B20_text.o $
    build/GSAP01-DEBUG/obj/SPdrape.o $
    build/GSAP01-DEBUG/obj/auto_07_8031C6E0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80269FA8_text.o $
    build/GSAP01-DEBUG/obj/dll_2D0.o $
    build/GSAP01-DEBUG/obj/auto_03_8026A210_text.o $
    build/GSAP01-DEBUG/obj/IMsnowbike.o $
    build/GSAP01-DEBUG/obj/auto_08_803963C8_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_8026B640_text.o $
    build/GSAP01-DEBUG/obj/dll_29F.o $
    build/GSAP01-DEBUG/obj/auto_07_8031C8E8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8026EDCC_text.o $
    build/GSAP01-DEBUG/obj/DFlog.o $
    build/GSAP01-DEBUG/obj/auto_07_8031CAE0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80270FE4_text.o $
    build/GSAP01-DEBUG/obj/DRearthwalk.o $
    build/GSAP01-DEBUG/obj/auto_06_802D08D8_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80273D54_text.o $
    build/GSAP01-DEBUG/obj/BWlog.o $
    build/GSAP01-DEBUG/obj/auto_07_8031CC70_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80275AC8_text.o $
    build/GSAP01-DEBUG/obj/CRsnowbike.o $
    build/GSAP01-DEBUG/obj/auto_08_803964B8_bss.o $
    build/GSAP01-DEBUG/obj/auto_03_80278790_text.o $
    build/GSAP01-DEBUG/obj/DRcloudrunner.o $
    build/GSAP01-DEBUG/obj/auto_08_80396528_bss.o $
    build/GSAP01-DEBUG/obj/auto_07_8031CF80_data.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0928_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_8027BC30_text.o $
    build/GSAP01-DEBUG/obj/dll_2A2.o $
    build/GSAP01-DEBUG/obj/auto_03_8027DAA8_text.o $
    build/GSAP01-DEBUG/obj/dll_23B.o $
    build/GSAP01-DEBUG/obj/auto_07_8031D0F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8027E6C8_text.o $
    build/GSAP01-DEBUG/obj/dll_23A.o $
    build/GSAP01-DEBUG/obj/auto_03_8027EC0C_text.o $
    build/GSAP01-DEBUG/obj/dll_23C.o $
    build/GSAP01-DEBUG/obj/auto_03_8027F080_text.o $
    build/GSAP01-DEBUG/obj/deaddino.o $
    build/GSAP01-DEBUG/obj/auto_07_8031D408_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8027F6CC_text.o $
    build/GSAP01-DEBUG/obj/laser23E.o $
    build/GSAP01-DEBUG/obj/auto_03_802805DC_text.o $
    build/GSAP01-DEBUG/obj/pswitch.o $
    build/GSAP01-DEBUG/obj/auto_07_8031D4A8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80280A88_text.o $
    build/GSAP01-DEBUG/obj/dll_241.o $
    build/GSAP01-DEBUG/obj/auto_03_80280E0C_text.o $
    build/GSAP01-DEBUG/obj/dll_23F.o $
    build/GSAP01-DEBUG/obj/auto_03_80281040_text.o $
    build/GSAP01-DEBUG/obj/dll_242.o $
    build/GSAP01-DEBUG/obj/auto_07_8031D610_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802812D8_text.o $
    build/GSAP01-DEBUG/obj/colrise243.o $
    build/GSAP01-DEBUG/obj/auto_03_80282228_text.o $
    build/GSAP01-DEBUG/obj/dll_244.o $
    build/GSAP01-DEBUG/obj/auto_03_802824DC_text.o $
    build/GSAP01-DEBUG/obj/dll_245.o $
    build/GSAP01-DEBUG/obj/auto_03_802827B0_text.o $
    build/GSAP01-DEBUG/obj/torch246.o $
    build/GSAP01-DEBUG/obj/auto_03_80282DA4_text.o $
    build/GSAP01-DEBUG/obj/dll_247.o $
    build/GSAP01-DEBUG/obj/auto_03_802830CC_text.o $
    build/GSAP01-DEBUG/obj/walltorch248.o $
    build/GSAP01-DEBUG/obj/auto_07_8031D858_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802836E4_text.o $
    build/GSAP01-DEBUG/obj/dll_249.o $
    build/GSAP01-DEBUG/obj/auto_03_80283AD8_text.o $
    build/GSAP01-DEBUG/obj/dll_24A.o $
    build/GSAP01-DEBUG/obj/auto_03_80283F70_text.o $
    build/GSAP01-DEBUG/obj/WMlevcontrol.o $
    build/GSAP01-DEBUG/obj/auto_03_80284280_text.o $
    build/GSAP01-DEBUG/obj/WMgeneralscales.o $
    build/GSAP01-DEBUG/obj/auto_03_80285208_text.o $
    build/GSAP01-DEBUG/obj/dll_24D.o $
    build/GSAP01-DEBUG/obj/auto_03_80285ED0_text.o $
    build/GSAP01-DEBUG/obj/dll_24E.o $
    build/GSAP01-DEBUG/obj/auto_03_802865B4_text.o $
    build/GSAP01-DEBUG/obj/openingScene.o $
    build/GSAP01-DEBUG/obj/auto_03_802869F0_text.o $
    build/GSAP01-DEBUG/obj/WMcrystal.o $
    build/GSAP01-DEBUG/obj/auto_07_8031E000_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8028855C_text.o $
    build/GSAP01-DEBUG/obj/dll_251.o $
    build/GSAP01-DEBUG/obj/auto_03_80288CD0_text.o $
    build/GSAP01-DEBUG/obj/dll_252.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0A88_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_80288FC0_text.o $
    build/GSAP01-DEBUG/obj/crawler253.o $
    build/GSAP01-DEBUG/obj/auto_03_8028A334_text.o $
    build/GSAP01-DEBUG/obj/dll_254.o $
    build/GSAP01-DEBUG/obj/auto_03_8028AAFC_text.o $
    build/GSAP01-DEBUG/obj/dll_255.o $
    build/GSAP01-DEBUG/obj/auto_03_8028AB94_text.o $
    build/GSAP01-DEBUG/obj/dll_256.o $
    build/GSAP01-DEBUG/obj/auto_03_8028ACE8_text.o $
    build/GSAP01-DEBUG/obj/VFlevcontrol.o $
    build/GSAP01-DEBUG/obj/auto_03_8028B600_text.o $
    build/GSAP01-DEBUG/obj/dll_258.o $
    build/GSAP01-DEBUG/obj/auto_03_8028B890_text.o $
    build/GSAP01-DEBUG/obj/minifire.o $
    build/GSAP01-DEBUG/obj/auto_07_8031E2A0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8028BE30_text.o $
    build/GSAP01-DEBUG/obj/dll_25A.o $
    build/GSAP01-DEBUG/obj/auto_03_8028BFC0_text.o $
    build/GSAP01-DEBUG/obj/statueball.o $
    build/GSAP01-DEBUG/obj/auto_03_8028C59C_text.o $
    build/GSAP01-DEBUG/obj/dll_25C.o $
    build/GSAP01-DEBUG/obj/auto_03_8028C94C_text.o $
    build/GSAP01-DEBUG/obj/ladders25D.o $
    build/GSAP01-DEBUG/obj/auto_03_8028CB38_text.o $
    build/GSAP01-DEBUG/obj/lift1.o $
    build/GSAP01-DEBUG/obj/auto_03_8028D4A0_text.o $
    build/GSAP01-DEBUG/obj/fireblock.o $
    build/GSAP01-DEBUG/obj/auto_03_8028E044_text.o $
    build/GSAP01-DEBUG/obj/platform1.o $
    build/GSAP01-DEBUG/obj/auto_03_8028E708_text.o $
    build/GSAP01-DEBUG/obj/doorswitch261.o $
    build/GSAP01-DEBUG/obj/auto_03_8028EBB4_text.o $
    build/GSAP01-DEBUG/obj/dll_262.o $
    build/GSAP01-DEBUG/obj/auto_03_8028F154_text.o $
    build/GSAP01-DEBUG/obj/draghead.o $
    build/GSAP01-DEBUG/obj/auto_03_8028F3BC_text.o $
    build/GSAP01-DEBUG/obj/dll_264.o $
    build/GSAP01-DEBUG/obj/auto_03_8028FBF4_text.o $
    build/GSAP01-DEBUG/obj/dll_265.o $
    build/GSAP01-DEBUG/obj/auto_03_8028FDC0_text.o $
    build/GSAP01-DEBUG/obj/dll_266.o $
    build/GSAP01-DEBUG/obj/auto_03_80290240_text.o $
    build/GSAP01-DEBUG/obj/lavaflow.o $
    build/GSAP01-DEBUG/obj/auto_03_8029041C_text.o $
    build/GSAP01-DEBUG/obj/dll_268.o $
    build/GSAP01-DEBUG/obj/auto_03_80290A10_text.o $
    build/GSAP01-DEBUG/obj/spellStonePlace.o $
    build/GSAP01-DEBUG/obj/auto_03_80290B54_text.o $
    build/GSAP01-DEBUG/obj/DBrockfall.o $
    build/GSAP01-DEBUG/obj/auto_07_80320D10_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802915F4_text.o $
    build/GSAP01-DEBUG/obj/rockGenerator.o $
    build/GSAP01-DEBUG/obj/auto_07_80320D60_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029189C_text.o $
    build/GSAP01-DEBUG/obj/DBpointmum.o $
    build/GSAP01-DEBUG/obj/auto_03_80291D58_text.o $
    build/GSAP01-DEBUG/obj/dll_26D.o $
    build/GSAP01-DEBUG/obj/auto_03_80293910_text.o $
    build/GSAP01-DEBUG/obj/DBspike.o $
    build/GSAP01-DEBUG/obj/auto_07_80321160_data.o $
    build/GSAP01-DEBUG/obj/auto_03_80293E64_text.o $
    build/GSAP01-DEBUG/obj/dll_26F.o $
    build/GSAP01-DEBUG/obj/auto_03_802941DC_text.o $
    build/GSAP01-DEBUG/obj/dll_271.o $
    build/GSAP01-DEBUG/obj/auto_03_80295DEC_text.o $
    build/GSAP01-DEBUG/obj/dll_272.o $
    build/GSAP01-DEBUG/obj/auto_03_802962D8_text.o $
    build/GSAP01-DEBUG/obj/dll_273.o $
    build/GSAP01-DEBUG/obj/auto_03_80296844_text.o $
    build/GSAP01-DEBUG/obj/dbayMap.o $
    build/GSAP01-DEBUG/obj/auto_07_803215B8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029773C_text.o $
    build/GSAP01-DEBUG/obj/dll_275.o $
    build/GSAP01-DEBUG/obj/auto_03_8029802C_text.o $
    build/GSAP01-DEBUG/obj/dll_276.o $
    build/GSAP01-DEBUG/obj/auto_03_80298504_text.o $
    build/GSAP01-DEBUG/obj/dll_277.o $
    build/GSAP01-DEBUG/obj/auto_07_80321AA0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029900C_text.o $
    build/GSAP01-DEBUG/obj/dll_278.o $
    build/GSAP01-DEBUG/obj/auto_03_80299CF4_text.o $
    build/GSAP01-DEBUG/obj/dbayExp.o $
    build/GSAP01-DEBUG/obj/auto_03_8029A120_text.o $
    build/GSAP01-DEBUG/obj/DBwaterflow.o $
    build/GSAP01-DEBUG/obj/auto_07_80321C28_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029AC4C_text.o $
    build/GSAP01-DEBUG/obj/dll_27B.o $
    build/GSAP01-DEBUG/obj/auto_03_8029B0A4_text.o $
    build/GSAP01-DEBUG/obj/dll_27C.o $
    build/GSAP01-DEBUG/obj/auto_03_8029B728_text.o $
    build/GSAP01-DEBUG/obj/dll_27D.o $
    build/GSAP01-DEBUG/obj/auto_07_80321D38_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029BCF8_text.o $
    build/GSAP01-DEBUG/obj/dll_27E.o $
    build/GSAP01-DEBUG/obj/auto_07_80321DA0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029C2D8_text.o $
    build/GSAP01-DEBUG/obj/DBlightgo.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0C10_rodata.o $
    build/GSAP01-DEBUG/obj/auto_03_8029CB14_text.o $
    build/GSAP01-DEBUG/obj/dll_280.o $
    build/GSAP01-DEBUG/obj/auto_07_80321E58_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029D1D8_text.o $
    build/GSAP01-DEBUG/obj/DBshooter.o $
    build/GSAP01-DEBUG/obj/auto_03_8029DA30_text.o $
    build/GSAP01-DEBUG/obj/DBbullet.o $
    build/GSAP01-DEBUG/obj/auto_03_8029E56C_text.o $
    build/GSAP01-DEBUG/obj/DBprotection.o $
    build/GSAP01-DEBUG/obj/auto_07_80321FB8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029EB44_text.o $
    build/GSAP01-DEBUG/obj/killbot.o $
    build/GSAP01-DEBUG/obj/auto_03_8029F3D4_text.o $
    build/GSAP01-DEBUG/obj/dll_285.o $
    build/GSAP01-DEBUG/obj/auto_03_8029F784_text.o $
    build/GSAP01-DEBUG/obj/DBdustgeezer.o $
    build/GSAP01-DEBUG/obj/auto_07_803220C0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_8029FD88_text.o $
    build/GSAP01-DEBUG/obj/DBbonedust.o $
    build/GSAP01-DEBUG/obj/auto_07_80322118_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802A0310_text.o $
    build/GSAP01-DEBUG/obj/DBkillboulder.o $
    build/GSAP01-DEBUG/obj/auto_07_80322188_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802A0C5C_text.o $
    build/GSAP01-DEBUG/obj/dll_289.o $
    build/GSAP01-DEBUG/obj/auto_03_802A0EDC_text.o $
    build/GSAP01-DEBUG/obj/DBstealerworm.o $
    build/GSAP01-DEBUG/obj/auto_07_80322A20_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802A4ED0_text.o $
    build/GSAP01-DEBUG/obj/dll_28B.o $
    build/GSAP01-DEBUG/obj/auto_07_80322A80_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802A56A4_text.o $
    build/GSAP01-DEBUG/obj/useobj28C.o $
    build/GSAP01-DEBUG/obj/auto_07_80322B50_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802A5E98_text.o $
    build/GSAP01-DEBUG/obj/dll_28D.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6148_text.o $
    build/GSAP01-DEBUG/obj/dll_28E.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6358_text.o $
    build/GSAP01-DEBUG/obj/dll_290.o $
    build/GSAP01-DEBUG/obj/auto_03_802A692C_text.o $
    build/GSAP01-DEBUG/obj/dll_291.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6A18_text.o $
    build/GSAP01-DEBUG/obj/dll_28F.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6AE4_text.o $
    build/GSAP01-DEBUG/obj/dll_292.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6BBC_text.o $
    build/GSAP01-DEBUG/obj/dll_293.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6C90_text.o $
    build/GSAP01-DEBUG/obj/dll_294.o $
    build/GSAP01-DEBUG/obj/auto_03_802A6FE4_text.o $
    build/GSAP01-DEBUG/obj/BOSSdrakor_laser.o $
    build/GSAP01-DEBUG/obj/auto_07_80322EC8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802A7774_text.o $
    build/GSAP01-DEBUG/obj/dll_296.o $
    build/GSAP01-DEBUG/obj/auto_03_802A7AC0_text.o $
    build/GSAP01-DEBUG/obj/dll_297.o $
    build/GSAP01-DEBUG/obj/auto_03_802A7B74_text.o $
    build/GSAP01-DEBUG/obj/WORLDplanet.o $
    build/GSAP01-DEBUG/obj/auto_07_80323010_data.o $
    build/GSAP01-DEBUG/obj/dll_213.o $
    build/GSAP01-DEBUG/obj/auto_03_802A9878_text.o $
    build/GSAP01-DEBUG/obj/CRsnowClaw.o $
    build/GSAP01-DEBUG/obj/auto_07_80323098_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802AA188_text.o $
    build/GSAP01-DEBUG/obj/dll_2A4.o $
    build/GSAP01-DEBUG/obj/auto_03_802AA900_text.o $
    build/GSAP01-DEBUG/obj/dll_2A5.o $
    build/GSAP01-DEBUG/obj/auto_03_802AAE38_text.o $
    build/GSAP01-DEBUG/obj/CRfueltank.o $
    build/GSAP01-DEBUG/obj/auto_07_80323220_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802AB0C4_text.o $
    build/GSAP01-DEBUG/obj/zBomb02A7.o $
    build/GSAP01-DEBUG/obj/TREX_levelcontrol.o $
    build/GSAP01-DEBUG/obj/auto_07_80323338_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802ABCAC_text.o $
    build/GSAP01-DEBUG/obj/TREX_trex.o $
    build/GSAP01-DEBUG/obj/auto_07_803233E0_data.o $
    build/GSAP01-DEBUG/obj/dll_29A.o $
    build/GSAP01-DEBUG/obj/auto_03_802AF7A4_text.o $
    build/GSAP01-DEBUG/obj/TREX_Lazerwall.o $
    build/GSAP01-DEBUG/obj/auto_07_80323658_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802AFDEC_text.o $
    build/GSAP01-DEBUG/obj/dll_29C.o $
    build/GSAP01-DEBUG/obj/auto_03_802AFF18_text.o $
    build/GSAP01-DEBUG/obj/dll_29D.o $
    build/GSAP01-DEBUG/obj/auto_03_802B00FC_text.o $
    build/GSAP01-DEBUG/obj/DRlaserturret.o $
    build/GSAP01-DEBUG/obj/auto_07_80323708_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B0DB0_text.o $
    build/GSAP01-DEBUG/obj/DRpushcart.o $
    build/GSAP01-DEBUG/obj/auto_03_802B2FA8_text.o $
    build/GSAP01-DEBUG/obj/DRbullet.o build/GSAP01-DEBUG/obj/DRCloudball.o $
    build/GSAP01-DEBUG/obj/auto_07_803238B8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B3DFC_text.o $
    build/GSAP01-DEBUG/obj/DRlavacontrol.o $
    build/GSAP01-DEBUG/obj/auto_07_80323910_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B4430_text.o $
    build/GSAP01-DEBUG/obj/DRsimplehuman.o $
    build/GSAP01-DEBUG/obj/auto_07_803239E8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B510C_text.o $
    build/GSAP01-DEBUG/obj/DRcreator.o $
    build/GSAP01-DEBUG/obj/auto_07_80323A68_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B5A08_text.o $
    build/GSAP01-DEBUG/obj/DRyoutube.o $
    build/GSAP01-DEBUG/obj/auto_07_80323A88_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B5C9C_text.o $
    build/GSAP01-DEBUG/obj/DRexplodeDoor.o $
    build/GSAP01-DEBUG/obj/auto_07_80323AD0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B6184_text.o $
    build/GSAP01-DEBUG/obj/DRgeezer.o $
    build/GSAP01-DEBUG/obj/auto_07_80323B20_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B65E4_text.o $
    build/GSAP01-DEBUG/obj/DRcagecontrol.o $
    build/GSAP01-DEBUG/obj/auto_07_80323B68_data.o $
    build/GSAP01-DEBUG/obj/dll_2B4.o $
    build/GSAP01-DEBUG/obj/auto_03_802B6CB0_text.o $
    build/GSAP01-DEBUG/obj/DRcloudcage.o $
    build/GSAP01-DEBUG/obj/auto_03_802B782C_text.o $
    build/GSAP01-DEBUG/obj/DRvines.o build/GSAP01-DEBUG/obj/DRshackle.o $
    build/GSAP01-DEBUG/obj/auto_07_80323D10_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802B846C_text.o $
    build/GSAP01-DEBUG/obj/DRhightop.o build/GSAP01-DEBUG/obj/DRbells.o $
    build/GSAP01-DEBUG/obj/auto_03_802BA4FC_text.o $
    build/GSAP01-DEBUG/obj/DRpickup.o $
    build/GSAP01-DEBUG/obj/auto_03_802BAC78_text.o $
    build/GSAP01-DEBUG/obj/DRicefire.o $
    build/GSAP01-DEBUG/obj/auto_03_802BB660_text.o $
    build/GSAP01-DEBUG/obj/DRcradle.o $
    build/GSAP01-DEBUG/obj/auto_07_80323F50_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802BBD9C_text.o $
    build/GSAP01-DEBUG/obj/DRpulley.o $
    build/GSAP01-DEBUG/obj/auto_03_802BC120_text.o $
    build/GSAP01-DEBUG/obj/dll_2BE.o $
    build/GSAP01-DEBUG/obj/auto_07_80324008_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802BC3E8_text.o $
    build/GSAP01-DEBUG/obj/DRprojswitch.o $
    build/GSAP01-DEBUG/obj/auto_03_802BC84C_text.o $
    build/GSAP01-DEBUG/obj/DRcollpieace.o $
    build/GSAP01-DEBUG/obj/auto_03_802BCF04_text.o $
    build/GSAP01-DEBUG/obj/dll_2C1.o $
    build/GSAP01-DEBUG/obj/auto_07_80324128_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802BD238_text.o $
    build/GSAP01-DEBUG/obj/dll_2C2.o $
    build/GSAP01-DEBUG/obj/auto_03_802BD694_text.o $
    build/GSAP01-DEBUG/obj/DRcavein.o $
    build/GSAP01-DEBUG/obj/auto_07_803241A0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802BD9DC_text.o $
    build/GSAP01-DEBUG/obj/dll_2C4.o $
    build/GSAP01-DEBUG/obj/auto_07_80324208_data.o $
    build/GSAP01-DEBUG/obj/dll_2C5.o $
    build/GSAP01-DEBUG/obj/auto_03_802BE418_text.o $
    build/GSAP01-DEBUG/obj/dll_2C6.o $
    build/GSAP01-DEBUG/obj/auto_03_802BE80C_text.o $
    build/GSAP01-DEBUG/obj/DRhalolight.o $
    build/GSAP01-DEBUG/obj/auto_07_803242F8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802BECE4_text.o $
    build/GSAP01-DEBUG/obj/dinoCall02C8.o $
    build/GSAP01-DEBUG/obj/auto_07_80324358_data.o $
    build/GSAP01-DEBUG/obj/dinoCall02C9.o $
    build/GSAP01-DEBUG/obj/auto_03_802BF06C_text.o $
    build/GSAP01-DEBUG/obj/dll_2CA.o $
    build/GSAP01-DEBUG/obj/auto_03_802BF420_text.o $
    build/GSAP01-DEBUG/obj/BWalphaanim.o $
    build/GSAP01-DEBUG/obj/auto_07_803244E0_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802BF6D0_text.o $
    build/GSAP01-DEBUG/obj/dll_2E7.o $
    build/GSAP01-DEBUG/obj/auto_03_802BF7A4_text.o $
    build/GSAP01-DEBUG/obj/dll_2D1.o build/GSAP01-DEBUG/obj/dll_2D2.o $
    build/GSAP01-DEBUG/obj/auto_03_802BFF18_text.o $
    build/GSAP01-DEBUG/obj/dll_2D3.o $
    build/GSAP01-DEBUG/obj/auto_06_802D0CE8_rodata.o $
    build/GSAP01-DEBUG/obj/dll_2D4.o $
    build/GSAP01-DEBUG/obj/auto_03_802C09B4_text.o $
    build/GSAP01-DEBUG/obj/WCpushblock.o $
    build/GSAP01-DEBUG/obj/auto_07_803246B8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802C16D4_text.o $
    build/GSAP01-DEBUG/obj/dll_2D5.o $
    build/GSAP01-DEBUG/obj/auto_03_802C18F8_text.o $
    build/GSAP01-DEBUG/obj/dll_2D6.o $
    build/GSAP01-DEBUG/obj/auto_03_802C197C_text.o $
    build/GSAP01-DEBUG/obj/WClevcontrol.o $
    build/GSAP01-DEBUG/obj/auto_08_803966A8_bss.o $
    build/GSAP01-DEBUG/obj/WCbeacon.o $
    build/GSAP01-DEBUG/obj/auto_07_803249C8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802C34AC_text.o $
    build/GSAP01-DEBUG/obj/dll_2DB.o $
    build/GSAP01-DEBUG/obj/auto_03_802C3994_text.o $
    build/GSAP01-DEBUG/obj/WCpressureSwitch.o $
    build/GSAP01-DEBUG/obj/auto_07_80324A58_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802C3E94_text.o $
    build/GSAP01-DEBUG/obj/dll_2DC.o $
    build/GSAP01-DEBUG/obj/auto_03_802C42DC_text.o $
    build/GSAP01-DEBUG/obj/USEOBJ.o $
    build/GSAP01-DEBUG/obj/auto_07_80324B30_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802C48B4_text.o $
    build/GSAP01-DEBUG/obj/dll_2DE.o $
    build/GSAP01-DEBUG/obj/auto_03_802C4C38_text.o $
    build/GSAP01-DEBUG/obj/dll_2E4.o $
    build/GSAP01-DEBUG/obj/auto_03_802C4F08_text.o $
    build/GSAP01-DEBUG/obj/dll_2DF.o $
    build/GSAP01-DEBUG/obj/auto_03_802C5214_text.o $
    build/GSAP01-DEBUG/obj/WCdial.o $
    build/GSAP01-DEBUG/obj/auto_03_802C5970_text.o $
    build/GSAP01-DEBUG/obj/WClaser.o $
    build/GSAP01-DEBUG/obj/auto_07_80324C90_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802C62C0_text.o $
    build/GSAP01-DEBUG/obj/dll_2E2.o $
    build/GSAP01-DEBUG/obj/auto_03_802C6630_text.o $
    build/GSAP01-DEBUG/obj/WCfloortile.o $
    build/GSAP01-DEBUG/obj/auto_07_80324CD8_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802C6CB0_text.o $
    build/GSAP01-DEBUG/obj/dll_2E8.o $
    build/GSAP01-DEBUG/obj/auto_03_802C6EB4_text.o $
    build/GSAP01-DEBUG/obj/ARWarwingattachment.o $
    build/GSAP01-DEBUG/obj/auto_07_80325650_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802CA550_text.o $
    build/GSAP01-DEBUG/obj/dll_2ED.o $
    build/GSAP01-DEBUG/obj/auto_03_802CA678_text.o $
    build/GSAP01-DEBUG/obj/dll_2EE.o $
    build/GSAP01-DEBUG/obj/auto_03_802CA6EC_text.o $
    build/GSAP01-DEBUG/obj/dll_2EF.o $
    build/GSAP01-DEBUG/obj/auto_03_802CA760_text.o $
    build/GSAP01-DEBUG/obj/dll_2F1.o $
    build/GSAP01-DEBUG/obj/auto_03_802CABC8_text.o $
    build/GSAP01-DEBUG/obj/dll_2F2.o $
    build/GSAP01-DEBUG/obj/auto_03_802CAF98_text.o $
    build/GSAP01-DEBUG/obj/dll_2F3.o $
    build/GSAP01-DEBUG/obj/auto_03_802CB2AC_text.o $
    build/GSAP01-DEBUG/obj/LGTpointlight.o $
    build/GSAP01-DEBUG/obj/auto_07_80325988_data.o $
    build/GSAP01-DEBUG/obj/auto_03_802CC22C_text.o $
    build/GSAP01-DEBUG/obj/LGTdirectionallight.o $
    build/GSAP01-DEBUG/obj/LGTprojectedlight.o $
    build/GSAP01-DEBUG/obj/auto_07_80325BA0_data.o $
    build/GSAP01-DEBUG/obj/LGTcontrollight.o $
    build/GSAP01-DEBUG/obj/auto_03_802CD564_text.o $
    build/GSAP01-DEBUG/obj/WaterFlowWe.o $
    build/GSAP01-DEBUG/obj/auto_03_802CD7C0_text.o $
    build/GSAP01-DEBUG/obj/tree.o build/GSAP01-DEBUG/obj/boulder.o $
    build/GSAP01-DEBUG/obj/auto_03_802CE9E0_text.o | $
    build/GSAP01-DEBUG/ldscript.lcf build/compilers build/tools/wibo
  ldflags = $ldflags -lcf build/GSAP01-DEBUG/ldscript.lcf


build build/GSAP01-DEBUG/default.dol: elf2dol $
    build/GSAP01-DEBUG/default.elf | build/tools/dtk
# Generate REL(s)
rule makerel
  command = build/tools/dtk rel make -w -c $config $names @$rspfile
  description = REL
  rspfile = $rspfile
  rspfile_content = $in_newline
# Build all source files
build all_source: phony build/GSAP01-DEBUG/src/main/pi.o $
    build/GSAP01-DEBUG/src/main/main.o $
    build/GSAP01-DEBUG/src/main/mm_dolphin.o $
    build/GSAP01-DEBUG/src/main/models_dolphin.o

# Build all source files with a host compiler
build all_source_host: phony

# Check hash
rule check
  command = build/tools/dtk shasum  -c $in -o $out
  description = CHECK $in
build build/GSAP01-DEBUG/ok: check config/GSAP01-DEBUG/build.sha1 | $
    build/tools/dtk build/GSAP01-DEBUG/default.dol

# Calculate progress
rule progress
  command = $python configure.py $configure_args progress
  description = PROGRESS
build build/GSAP01-DEBUG/progress.json: progress | build/GSAP01-DEBUG/ok $
    configure.py tools/project.py config/GSAP01-DEBUG/config.yml
# Generate progress report
rule report
  command = build/tools/objdiff-cli report generate -o $out
  description = REPORT
build build/GSAP01-DEBUG/report.json: report | build/tools/objdiff-cli $
    all_source
# Check for mismatching symbols
rule dol_diff
  command = build/tools/dtk -L error dol diff $in
  description = DIFF build/GSAP01-DEBUG/default.elf
build dol_diff: dol_diff config/GSAP01-DEBUG/config.yml $
    build/GSAP01-DEBUG/default.elf
build diff: phony dol_diff

# Apply symbols from linked ELF
rule dol_apply
  command = build/tools/dtk dol apply $in
  description = APPLY build/GSAP01-DEBUG/default.elf
build dol_apply: dol_apply config/GSAP01-DEBUG/config.yml $
    build/GSAP01-DEBUG/default.elf | build/GSAP01-DEBUG/ok
build apply: phony dol_apply

# Split DOL into relocatable objects
rule split
  command = build/tools/dtk dol split $in $out_dir
  description = SPLIT $in
  depfile = $out_dir/dep
  deps = gcc
build build/GSAP01-DEBUG/config.json: split config/GSAP01-DEBUG/config.yml $
    | build/tools/dtk
  out_dir = build/GSAP01-DEBUG

# Reconfigure on change
rule configure
  command = $python configure.py $configure_args
  description = RUN configure.py
  generator = 1
build build.ninja: configure | build/GSAP01-DEBUG/config.json configure.py $
    tools/project.py tools/ninja_syntax.py config/GSAP01-DEBUG/ldscript.tpl

# Default rule
default build/GSAP01-DEBUG/progress.json
