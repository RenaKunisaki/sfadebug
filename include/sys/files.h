#ifndef _SYS_FILES_H_
#define _SYS_FILES_H_

#include "../types.h"

typedef uint DataFileLoadedFlags;
typedef enum { //different from final!
    //inconsistent suffix capitalization is
    //just how the game names them
    FILE_NONE          = -1, //0xFFFFFFFF
    FILE_AUDIO_tab     =  0, //0x00
    FILE_AUDIO_bin     =  1, //0x01
    FILE_SFX_tab       =  2, //0x02
    FILE_SFX_bin       =  3, //0x03
    FILE_AMBIENT_tab   =  4, //0x04
    FILE_AMBIENT_bin   =  5, //0x05
    FILE_MUSIC_tab     =  6, //0x06
    FILE_MUSIC_bin     =  7, //0x07
    FILE_MPEG_tab      =  8, //0x08
    FILE_MPEG_bin      =  9, //0x09
    FILE_MUSICACT_bin  = 10, //0x0A
    FILE_CAMACTIO_bin  = 11, //0x0B
    FILE_LACTIONS_bin  = 12, //0x0C
    FILE_ANIMCURV_bin  = 13, //0x0D
    FILE_ANIMCURV_tab  = 14, //0x0E
    FILE_OBJSEQ2C_tab  = 15, //0x0F
    FILE_FONTS_bin     = 16, //0x10
    FILE_CACHEFON_bin  = 17, //0x11
    FILE_CACHEFON_bin2 = 18, //0x12
    FILE_GAMETEXT_bin  = 19, //0x13
    FILE_GAMETEXT_tab  = 20, //0x14
    FILE_globalma_bin  = 21, //0x15
    FILE_TABLES_bin    = 22, //0x16
    FILE_TABLES_tab    = 23, //0x17
    FILE_SCREENS_bin   = 24, //0x18
    FILE_SCREENS_tab   = 25, //0x19
    FILE_VOXMAP_tab    = 26, //0x1A
    FILE_VOXMAP_bin    = 27, //0x1B
    FILE_WARPTAB_bin   = 28, //0x1C
    FILE_MAPS_bin      = 29, //0x1D
    FILE_MAPS_tab      = 30, //0x1E
    FILE_MAPINFO_bin   = 31, //0x1F
    FILE_TEX1_bin      = 32, //0x20
    FILE_TEX1_tab      = 33, //0x21
    FILE_TEXTABLE_bin  = 34, //0x22
    FILE_TEX0_bin      = 35, //0x23
    FILE_TEX0_tab      = 36, //0x24
    FILE_BLOCKS_bin    = 37, //0x25
    FILE_BLOCKS_tab    = 38, //0x26
    FILE_TRKBLK_tab    = 39, //0x27
    FILE_HITS_bin      = 40, //0x28
    FILE_HITS_tab      = 41, //0x29
    FILE_MODELS_tab    = 42, //0x2A
    FILE_MODELS_bin    = 43, //0x2B
    FILE_MODELIND_bin  = 44, //0x2C
    FILE_MODANIM_TAB   = 45, //0x2D
    FILE_MODANIM_BIN   = 46, //0x2E
    FILE_ANIM_TAB      = 47, //0x2F
    FILE_ANIM_BIN      = 48, //0x30
    FILE_AMAP_TAB      = 49, //0x31
    FILE_AMAP_BIN      = 50, //0x32
    FILE_BITTABLE_bin  = 51, //0x33
    FILE_WEAPONDA_bin  = 52, //0x34
    FILE_VOXOBJ_tab    = 53, //0x35
    FILE_VOXOBJ_bin    = 54, //0x36
    FILE_MODLINES_bin  = 55, //0x37
    FILE_MODLINES_tab  = 56, //0x38
    FILE_SAVEGAME_bin  = 57, //0x39
    FILE_SAVEGAME_tab  = 58, //0x3A
    FILE_OBJSEQ_bin    = 59, //0x3B
    FILE_OBJSEQ_tab    = 60, //0x3C
    FILE_OBJECTS_tab   = 61, //0x3D
    FILE_OBJECTS_bin   = 62, //0x3E
    FILE_OBJINDEX_bin  = 63, //0x3F
    FILE_OBJEVENT_bin  = 64, //0x40
    FILE_OBJHITS_bin   = 65, //0x41
    FILE_DLLS_bin      = 66, //0x42
    FILE_DLLS_tab      = 67, //0x43
    FILE_DLLSIMPO_bin  = 68, //0x44
    FILE_MODELS_tab2   = 69, //0x45
    FILE_MODELS_bin2   = 70, //0x46
    FILE_BLOCKS_bin2   = 71, //0x47
    FILE_BLOCKS_tab2   = 72, //0x48
    FILE_ANIM_TAB2     = 73, //0x49
    FILE_ANIM_BIN2     = 74, //0x4A
    FILE_TEX1_bin2     = 75, //0x4B
    FILE_TEX1_tab2     = 76, //0x4C
    FILE_TEX0_bin2     = 77, //0x4D
    FILE_TEX0_tab2     = 78, //0x4E
    FILE_ENVFXACT_bin  = 79, //0x4F
    NUM_FILES          = 80, //0x50
    FILE_NULL          = 80, //0x50
    FILE_NULL2         = 81, //0x51
} DataFileId32;

#define MODELS_TAB_SIZE 0x800
#define ANIM_TAB_SIZE 3000 //not 0x3000
#define TEX0_TAB_SIZE 0x1000
#define TEX1_TAB_SIZE 0x1000
#define BLOCKS_TAB_SIZE 0x800

#endif //_SYS_FILES_H_
