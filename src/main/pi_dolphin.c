#include "dolphin.h"
#include "dolphin/dvd.h"
#include "dolphin/gx/GXStruct.h"
#include "dolphin/mtx.h"
#include "dolphin/os/OSCache.h"
#include "dolphin/os/OSStopwatch.h"
#include "dolphin/os/OSThread.h"
#include "gfx/models/animation.h"
#include "gfx/models/shaders.h"
#include "gfx/textures.h"
#include "macros.h"
#include "maps/Map.h"
#include "types.h"
#include "debug/debug.h"
#include "sys/alloc.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "gfx/models/models.h"
#include "sys/dll.h"
#include "obj/Objects.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "sys/pi.h"
#include "sys/compress.h"
#include <stddef.h>
#include "placeholder.h"

enum {
    TexGetMipmapOp_getSize = 0,
    TexGetMipmapOp_getNext = 1, //unsure
    TexGetMipmapOp_copy = 2,
} TexGetMipmapOp;

//strings that belong somewhere in this file probably.
//where they go, and what args, are mostly huge guesses.
//no guarantee they're in the right functions.
// * prefix for ones we've placed

// * "pi:table"
// * "preloaded ... %s tablesize=%d table=%x\n"
// * "LOAD FROM DISK... %s size %d\n"
// * " Size %i \n"
// * "ADDR ROMLOAD file=%s\n"
// * "LOAD FROM DISK... %s\n"
// * "######## DVDLOAD piRomLoadAddr() ----- file=%s  #################\n"
// * "temp dvd buffer"
// * "PIFREE buffer  addr 0x%x"
//   "piGetMapInfo() ----- table DB_MAPS or DB_MAPINDEX not loaded\n"
//   "piGetModelInfo() ----- table DB_MODELS not loaded\n"
//   "piGetTExtureInfo() ----- table DB_TEXTURES not loaded\n"
//   "piGetTEXTUREInfo() ----- table DB_TEXTURES not loaded\n"
// * "pi_dolphin.c"
// * "piRomLoadSection(): DB_MAPS Bin Not Loaded"
// * "<Cyc %d | Instr %d | L1misscyc %d | DCmiss %d>\n"
// * "piRomGetGamNumber() ----- mapNumber <%d> too high"
// * "######## DVDLOAD piRomLoadSectionL() ----- file=%s  #################\n"
// * "PIFREE buffer  addr 0x%x\n"
// * "ROMLOAD gamno=%d  level %s  fileno %d\n"
// * "PIFREE pitable[%d]  addr %d"
// * "FILENAME %s\n"
// * "LOAD FROM DISK... %s %s/%s %d size %d\n"
// * "######## DVDLOAD piRomLoadLevel() ---- file=%s  #################\n"
// * "PIFREE pitable[%d]ANIMCURVE/TAB  addr %d"
// * "INANIMCURVE LOCK %x\n"
// * "INANIMCURVETAB LOCK %x\n"
// * "ALL BASES FULL DB_BLOCKS\n"
// * "PIFREE pitable[%d]BLOCKS  addr %d"
// * "%s/mod%d.bin"
// * "INBLOCKS LOCK %x\n"
// * "ALL BASES FULL DB_BLOCKSTAB\n"
// * "PIFREE pitable[%d]BLOCKSTAB  addr %d"
// * "%s/mod%d.tab"
// * "BLOCKSTAB"
// * "INBLOCKTAB LOCK %x\n"
// * "GOT TO MODELS\n"
// * "forceload\n"
// * "allloaded 1\n"
// * "allloaded 2\n"
// * "ALL BASES FULL DB_MODELS\n"
// * "PIFREE pitable[%d]MODELS  addr %d"
// * "INMODELS LOCK %x\n"
// * "ALL BASES FULL DB_MODTAB\n"
// * "PIFREE pitable[%d]MODTAB  addr %d"
// * "INMODTABLOCK %x\n"
// * "ALL BASES FULL DB_ANIM\n"
// * "PIFREE pitable[%d]ANIM  addr %d"
// * "INANIM LOCK %x\n"
// * "ALL BASES FULL DB_ANIMTAB\n"
// * "PIFREE pitable[%d]ANIMTAB  addr %d"
// * "INANIMTAB LOCK %x\n"
// * "ALL BASES FULL DB_TEXTURES2\n"
// * "PIFREE pitable[%d]TEXTURES2  addr %d"
// * "######## DVDLOAD piRomLoadLevel() ---- file=%s  piTable 0x%x #################\n"
// * "INTEX2 LOCK %x\n"
// * "ALL BASES FULL DB_TEXTAB2\n"
// * "PIFREE pitable[%d]TEXTAB2  addr %d"
// * "######## DVDLOAD piRomLoadLevel() ----- file=%s  #################\n"
// * "INTEXTAB2 LOCK %x\n"
// * "ALL BASES FULL DB_TEXTURES\n"
// * "PIFREE pitable[%d]TEXTURES  addr %d"
// * "INTEX LOCK %x\n"
// * "ALL BASES FULL DB_TEXTAB\n"
// * "PIFREE pitable[%d]TEXTAB  addr %d"
// * "INTEXTAB LOCK %x\n"
// * "INTEXTABB LOCK %x\n"
// * "ERROR in piRomLoadLevel file %d\n"
// * "piMergeIndex  one or other tabfiles is not loaded %x %x\n"
// * "MODTAB %4d 0x%x "
// * "T1 0x%x "
// * "T2 0x%x "
//   "PIFREE pitable[%d]  addr 0x%x  --- gamno %d size %d the file GAMNO %d\n"
// * "Warning in piRomFreeLevel file || %s || not found !\n"
// * "piRomFreeLevel(): flist array overflow"
//   "ROMLOADTAB file=%s\n"
// * "piDVDCallbackModtab  error on MODTAB\n"
// * "\n\n\npiDVDCallbackModtab  %x\n\n\n"
// * "piDVDCallbackAnimtab  error on ANIMTAB\n"
// * "piDVDCallbackAnimtab %x\n"
// * "piDVDCallbackModbin  error on MODBIN\n"
// * "piDVDCallbackModtab %x\n"
// * "piDVDCallbackAnimbin  error on ANIMBIN\n"
// * "piDVDCallbackAnim %x\n"
// * "piDVDCallbackTex2bin  error on TEX2BIN\n"
// * "piDVDCallbackTEXTURES %x\n"
// * "piDVDCallbackTextab  error on TEX2TAB\n"
// * "piDVDCallbacktex2tab36 %x\n"
// * "piDVDCallbackTex2tab36 ------ CHECKSUM  0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTex2tab36 ------ CHECKSUM IS INCORRECT   0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTex2tab36 ------ RE-READING\n"
// * "piDVDCallbacktex2tab78 %x\n"
// * "piDVDCallbackTex2tab78 ------ CHECKSUM  0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTex2tab78 ------ CHECKSUM IS INCORRECT   0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTex2tab78 ------ RE-READING\n"
// * "piDVDCallbackTexbin  error on TEXBIN\n"
// * "piDVDCallbacktexbin %x\n"
// * "piDVDCallbackTextab  error on TEXTAB\n"
// * "piDVDCallbacktextab33 %x\n"
// * "piDVDCallbackTextab33 ------ CHECKSUM  0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTex2tab33 ------ CHECKSUM IS INCORRECT   0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTex2tab33 ------ RE-READING\n"
// * "piDVDCallbacktextab76 %x\n"
// * "piDVDCallbackTextab76 ------ CHECKSUM  0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTextab76 ------ CHECKSUM IS INCORRECT   0x%x  REALSUM 0x%x\n"
// * "piDVDCallbackTextab76 ------ RE-READING\n"
// * "piDVDCallbackBlockbin  error on BLOCKBIN\n"
// * "piDVDCallbackblockbin %x\n"
// * "piDVDCallbackBlockstab  error on BLOCKSTAB\n"
// * "piDVDCallbackblocktab %x\n"
// * "piDVDCallbackAnimCurveb  error on AnimCurve\n"
// * "piDVDCallbackAnimCurve %x\n"
// * "piDVDCallbackAnimCurveTab  error on AnimCurveTab\n"
// * "piDVDCallbackAnimCurveTab %x\n"

//other files
int piMergeIndex(uint *table,DataFileId32 file1,DataFileId32 file2,int count);
int lzoDecompress(void *src,int compLen,void *dest,int *outLen);

//unknown
void piDVDCallbackAnimCurve(long stat, DVDFileInfo *file);
void piDVDCallbackAnimCurveTab(long stat, DVDFileInfo *file);
void piDVDCallbackTexbin(long stat, DVDFileInfo *file);
void piDVDCallbackTextab33(long stat, DVDFileInfo *file);
void piDVDCallbackTexbin2(long stat, DVDFileInfo *file);
void piDvdCallbacktex2tab36(long stat, DVDFileInfo *file);
void piDVDCallbackBlockbin(long stat, DVDFileInfo *file);
void piDVDCallbackBlockstab(long stat, DVDFileInfo *file);
void piDVDCallbackModtab(long stat,  DVDFileInfo *file);
void piDVDCallbackModelsbin(long stat, DVDFileInfo *file);
void piDVDCallbackAnimtab(long stat, DVDFileInfo *file);
void piDVDCallbackAnimbin(long stat, DVDFileInfo *file);

//this file
void initDataFiles(void);
void *loadDataFile(DataFileId32 file, char *memName);
int loadDataFileToBuf(DataFileId32 fileNo, void *buf);
void piGetTEXTUREInfo(uint offset, uint mipIdx, uint *outSize,
    undefined4 *outCompSize, int size, void *dest, int doWhat);
void loadTableFiles(void);
uint piGetLoadedFlags(int param_1);

const char *dataFileNames[] = { //802ef02c
    "AUDIO.tab", "AUDIO.bin",
    "SFX.tab", "SFX.bin",
    "AMBIENT.tab", "AMBIENT.bin",
    "MUSIC.tab", "MUSIC.bin",
    "MPEG.tab", "MPEG.bin",
    "MUSICACT.bin",
    "CAMACTIO.bin",
    "LACTIONS.bin",
    "ANIMCURV.bin", "ANIMCURV.tab",
    "OBJSEQ2C.tab",
    "FONTS.bin",
    "CACHEFON.bin", "CACHEFON.bin",
    "GAMETEXT.bin", "GAMETEXT.tab",
    "globalma.bin",
    "TABLES.bin", "TABLES.tab",
    "SCREENS.bin", "SCREENS.tab",
    "VOXMAP.tab", "VOXMAP.bin",
    "WARPTAB.bin",
    "MAPS.bin", "MAPS.tab",
    "MAPINFO.bin",
    "TEX1.bin", "TEX1.tab",
    "TEXTABLE.bin",
    "TEX0.bin", "TEX0.tab",
    "BLOCKS.bin", "BLOCKS.tab",
    "TRKBLK.tab",
    "HITS.bin", "HITS.tab",
    "MODELS.tab", "MODELS.bin",
    "MODELIND.bin",
    "MODANIM.TAB", "MODANIM.BIN",
    "ANIM.TAB", "ANIM.BIN",
    "AMAP.TAB", "AMAP.BIN",
    "BITTABLE.bin",
    "WEAPONDA.bin",
    "VOXOBJ.tab", "VOXOBJ.bin",
    "MODLINES.bin", "MODLINES.tab",
    "SAVEGAME.bin", "SAVEGAME.tab",
    "OBJSEQ.bin", "OBJSEQ.tab",
    "OBJECTS.tab", "OBJECTS.bin",
    "OBJINDEX.bin",
    "OBJEVENT.bin",
    "OBJHITS.bin",
    "DLLS.bin", "DLLS.tab",
    "DLLSIMPO.bin",
    "MODELS.tab", "MODELS.bin",
    "BLOCKS.bin", "BLOCKS.tab",
    "ANIM.TAB", "ANIM.BIN",
    "TEX1.bin", "TEX1.tab",
    "TEX0.bin", "TEX0.tab",
    "ENVFXACT.bin",
    "NULL", "NULL"};

const char *mapDirNames[] = {
    "animtest",
    "dragrock",
    "dragrockbot",
    "swapholbot",
    "wallcity",
    "lightfoot",
    "cloudtreasure",
    "clouddungeon",
    "darkicemines",
    "icemountain",
    "darkicemines2",
    "bossgaldon",
    "insidegal",
    "magiccave",
    "dfshrine",
    "mmshrine",
    "ecshrine",
    "gpshrine",
    "dbshrine",
    "nwshrine",
    "worldmap",
    "capeclaw",
    "cloudrace",
    "bossdrakor",
    "bosstrex"};

const char *mapNames[] = {
    "animtest",
    "animtest",
    "animtest",
    "arwing",
    "dragrock",
    "animtest",
    "dfptop",
    "volcano",
    "animtest",
    "animtest",
    "dragrockbot",
    "dfalls",
    "swaphol",
    "animtest",
    "nwastes",
    "warlock",
    "shop",
    "animtest",
    "crfort",
    "swapholbot",
    "wallcity",
    "lightfoot",
    "cloudtreasure",
    "animtest",
    "clouddungeon",
    "mmpass",
    "darkicemines",
    "animtest",
    "desert",
    "animtest",
    "icemountain",
    "animtest",
    "animtest",
    "animtest",
    "darkicemines2",
    "bossgaldon",
    "animtest",
    "insidegal",
    "magiccave",
    "dfshrine",
    "mmshrine",
    "ecshrine",
    "gpshrine",
    "dbshrine",
    "nwshrine",
    "worldmap",
    "animtest",
    "capeclaw",
    "dbay",
    "animtest",
    "cloudrace",
    "bossdrakor",
    "animtest",
    "bosstrex",
    "animtest"};

const MapDirIdx32 mapIdXltnTbl[] = { //0x802ef38c
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_dragrock,
    MapDir_animtest_05,
    MapDir_volcano,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_swaphol,
    MapDir_swapholbot,
    MapDir_animtest_05,
    MapDir_nwastes,
    MapDir_warlock,
    MapDir_crfort,
    MapDir_wallcity,
    MapDir_lightfoot,
    MapDir_cloudtreasure,
    MapDir_clouddungeon,
    MapDir_animtest_05,
    MapDir_mmpass,
    MapDir_darkicemines,
    MapDir_animtest_05,
    MapDir_desert,
    MapDir_animtest_05,
    MapDir_icemountain,
    MapDir_animtest_1F,
    MapDir_animtest_20,
    MapDir_animtest_05,
    MapDir_darkicemines2,
    MapDir_bossgaldon,
    MapDir_capeclaw,
    MapDir_insidegal,
    MapDir_dfshrine,
    MapDir_mmshrine,
    MapDir_ecshrine,
    MapDir_gpshrine,
    MapDir_dbay,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_arwing,
    MapDir_dbshrine,
    MapDir_nwshrine,
    MapDir_worldmap,
    MapDir_animtest_05,
    MapDir_cloudrace,
    MapDir_bossdrakor,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_bosstrex,
    MapDir_animtest_05,
    MapDir_dfptop,
    MapDir_shop,
    MapDir_dragrockbot,
    MapDir_animtest_05,
    MapDir_magiccave,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_animtest_05,
    MapDir_animtest_05,
};

//.bss
int dataFileSizes[NUM_FILES]; //0x8036bb40
s16 loadedFileMapIds[NUM_FILES];
void *dataFilePtrs[NUM_FILES]; //0x8035CAD0
u8 dataFileArray_8035cc10[NUM_FILES]; //8035cc10 - initDataFiles stores 0 here for each file
uint MODELS_TAB[MODELS_TAB_SIZE];
uint ANIM_TAB[ANIM_TAB_SIZE]; //size might be 0x4e8?
uint TEX0_TAB[TEX0_TAB_SIZE]; //size might be 0x6d0?
uint TEX1_TAB[TEX1_TAB_SIZE];
uint BLOCKS_TAB[BLOCKS_TAB_SIZE]; //size might be 0x1000?

//.sbss
u32 loadingFiles; //0x80398B30 - PiLockFlags, which are being loaded in background
u32 loadedFiles; //0x80398B34 - PiLockFlags
u32 readyFiles; //0x80398B38 - PiLockFlags
PiFreeList piFreeList;

#define PIFREE(slot, name) if(dataFilePtrs[slot] != NULL) { \
    STUBBED_PRINTF("PIFREE pitable[%d]" #name "  addr %d", slot, dataFilePtrs[slot]); \
    mmFree(dataFilePtrs[slot]); \
    dataFilePtrs[slot] = NULL; \
}

void initDataFiles(void) {
	int file;
	for(file=0; file<=FILE_ENVFXACT_bin; file++) {
		switch(file) {
            case FILE_AUDIO_tab:
            case FILE_AUDIO_bin:
            case FILE_SFX_tab:
            case FILE_SFX_bin:
            case FILE_AMBIENT_tab:
            case FILE_AMBIENT_bin:
            case FILE_MUSIC_tab:
            case FILE_MUSIC_bin:
            case FILE_MPEG_tab:
            case FILE_MPEG_bin:
            case FILE_MUSICACT_bin:
            case FILE_ANIMCURV_bin:
            case FILE_ANIMCURV_tab:
            case FILE_CACHEFON_bin:
            case FILE_CACHEFON_bin2:
            case FILE_SCREENS_bin:
            case FILE_VOXMAP_bin:
            case FILE_TEX1_bin:
            case FILE_BLOCKS_bin:
            case FILE_BLOCKS_tab:
            case FILE_MODELS_tab:
            case FILE_MODELS_bin:
            case FILE_ANIM_TAB:
            case FILE_ANIM_BIN:
            case FILE_VOXOBJ_bin:
            case FILE_DLLS_bin:
            case FILE_DLLS_tab:
            case FILE_DLLSIMPO_bin:
            case FILE_MODELS_tab2:
            case FILE_MODELS_bin2:
            case FILE_BLOCKS_bin2:
            case FILE_BLOCKS_tab2:
            case FILE_ANIM_TAB2:
            case FILE_ANIM_BIN2:
            case FILE_TEX1_bin2:
            case FILE_TEX1_tab2:
            case FILE_TEX0_bin2:
            case FILE_TEX0_tab2:
				dataFilePtrs[file] = NULL;
				loadedFileMapIds[file] = -1;
				break;
			default:
                loadDataFile(file, "pi:table");
                loadedFileMapIds[file] = -1;
		}
        dataFileArray_8035cc10[file] = 0;
	}

    piMergeIndex(MODELS_TAB, FILE_MODELS_tab,
        FILE_MODELS_tab2, MODELS_TAB_SIZE);
    piMergeIndex(ANIM_TAB, FILE_ANIM_TAB,
        FILE_ANIM_TAB2, ANIM_TAB_SIZE);
    piMergeIndex(TEX0_TAB, FILE_TEX0_tab,
        FILE_TEX0_tab2, TEX0_TAB_SIZE);
    piMergeIndex(TEX1_TAB, FILE_TEX1_tab,
        FILE_TEX1_tab2, TEX1_TAB_SIZE);
    piMergeIndex(BLOCKS_TAB, FILE_BLOCKS_tab,
        FILE_BLOCKS_tab2, BLOCKS_TAB_SIZE);
}

/**
 * @brief Load file from disc and store it in newly allocated buffer.
 *
 *  @param fileNo Which file to load.
 *  @param memName (Unused) name of the memory block.
 *  @return void* The file content.
 *  @note If already loaded, returns the existing instance.
 */
void *loadDataFile(DataFileId32 fileNo, char *memName) {
	DVDFileInfo file;
	void *pvVar1;

	if(dataFilePtrs[fileNo]) {
        STUBBED_PRINTF("preloaded ... %s tablesize=%d table=%x\n",
            dataFileNames[fileNo], dataFileSizes[fileNo],
            dataFilePtrs[fileNo]);
        return dataFilePtrs[fileNo];
    }

    DVDOpen((char*)dataFileNames[fileNo], &file);
    dataFileSizes[fileNo] = file.length;
    STUBBED_PRINTF("LOAD FROM DISK... %s size %d\n",
        dataFileNames[fileNo], dataFileSizes[fileNo]);
    dataFilePtrs[fileNo] = mmAlloc(dataFileSizes[fileNo] + 0x20,
        ALLOC_TAG_DVD_BUFFER,
        (volatile u32)dataFileNames[fileNo]);
    DCInvalidateRange(dataFilePtrs[fileNo], dataFileSizes[fileNo]);
    DVDReadPrio(&file, dataFilePtrs[fileNo],
        dataFileSizes[fileNo], 0, 2);
    DVDClose(&file);
    return dataFilePtrs[fileNo];
}

/**
 * @brief Load file from disc and store it to specified buffer.
 *
 *  @param fileNo Which file to load.
 *  @param buf Buffer to store to.
 *  @return int The file size.
 *  @note If already loaded, copies existing instance.
 *  @note Buffer must be large enough for the file!
 */
int loadDataFileToBuf(DataFileId32 fileNo, void *buf) {
	DVDFileInfo file;

	if(dataFilePtrs[fileNo]) {
        STUBBED_PRINTF(" Size %i \n", dataFileSizes[fileNo]);
        memcpy_src_dst_len(dataFilePtrs[fileNo],
            buf, dataFileSizes[fileNo]);
		DCStoreRange(buf, dataFileSizes[fileNo]);
		return dataFileSizes[fileNo];
	} else {
        STUBBED_PRINTF("ADDR ROMLOAD file=%s\n", dataFileNames[fileNo]);
		DVDOpen((char*)dataFileNames[fileNo], &file);
        STUBBED_PRINTF("LOAD FROM DISK... %s\n", dataFileNames[fileNo]);
		DCInvalidateRange(buf, file.length);
		DVDReadPrio(&file, buf,
            (uint)file.cb.callback, 0, 2);
		DVDClose(&file);
        return file.length;
	}
}

/**
 * @brief Load portion of file from disc and store it
 *  to specified buffer,
 *
 *  @param fileNo Which file to load.
 *  @param buf Buffer to store to.
 *  @param offset Offset within file to read from.
 *  @param len Number of bytes to read.
 *  @return Number of bytes read.
 */
int piRomLoadAddr(DataFileId32 fileNo, void *buf,
uint offset, int len) {
	void *tmpBuf;
	DVDFileInfo file;
    int dummy1;
    int dummy2;

    dummy1 = 0;
    dummy2 = 0;
	if(!len) return 0;
	if(dataFilePtrs[fileNo]) {
        //file is already loaded, just copy from there
        memcpy_src_dst_len(
		    (void *)((int)dataFilePtrs[fileNo] + offset),
            buf, len);
    } else {
        STUBBED_PRINTF("######## DVDLOAD piRomLoadAddr() "
            "----- file=%s  #################\n", dataFileNames[fileNo]);
		DVDOpen((char*)dataFileNames[fileNo], &file);
        if((uint)buf & 0x1f || len & 0x1f) {
            //buffer and/or length aren't aligned.
            //have to read into a temp buffer and copy.
            //@bug missing checks for failures here
            tmpBuf = mmAlloc(len + 0x1f & ~0x1f,
			    ALLOC_TAG_DVD_BUFFER,
			    (volatile u32)"temp dvd buffer");
			DCInvalidateRange(tmpBuf, len + 0x1f & ~0x1f);
			DVDReadPrio(&file, tmpBuf, len + 0x1f & ~0x1f, offset, 2);
			memcpy_src_dst_len(tmpBuf, buf, len);
			mmFree(tmpBuf);
        } else {
            //buffer and length are aligned; can read directly into it.
			DCInvalidateRange(buf, len);
			DVDReadPrio(&file, buf, len, offset, 2);
		}
		DVDClose(&file);
	}
	DCStoreRange(buf, len);
	return len;
}

/**
 * @brief Get the length of a loaded file.
 *
 *  @param fileNo The file ID.
 *  @return int The length in bytes.
 *  @note Panics if the file isn't loaded.
 */
int getLoadedDataFileSize(DataFileId32 fileNo) {
	if(dataFilePtrs[fileNo]) { return dataFileSizes[fileNo]; }
	CRASH();
	return 0;
}

void piGetMapInfo(int offset, int *outNBlocks,
int *out1E, int *outRomListSize, int idx) {
	MapsBinEntry0 *entry0;
	int iVar2;
	astruct_6 *data;
	MapsBinEntry0 *entry;
	astruct_6 *iVar1;

    if((dataFilePtrs[FILE_MAPS_bin] && dataFilePtrs[FILE_MAPS_tab])) {
        entry0 = (MapsBinEntry0*)((u32)dataFilePtrs[FILE_MAPS_bin] + offset);
        *outNBlocks = entry0->nBlocks;
        *out1E = entry0->unk1e;
        iVar2 = *(int*)((int)dataFilePtrs[FILE_MAPS_tab] + idx * 4 + sizeof(astruct_6));
        data = (astruct_6*)((u32)dataFilePtrs[FILE_MAPS_bin] + iVar2);
        *outRomListSize = data->unk4 - (data->unkC + sizeof(ObjDef) + data->unk8);
    }
}

void piGetModelInfo(uint offset, int *outNAnimations, uint *outAnimCacheSize,
BOOL *outNoAmap, int *outSize, int id) {
	ModelsBinEntry *entry;
    ModelsBinEntry_Unk18 *unk18;
	DataFileId32 fileIdx;
    void *modelsTabA;
    void *modelsTabB;
    uint offs;

	if(!(dataFilePtrs[FILE_MODELS_bin] || dataFilePtrs[FILE_MODELS_bin2])) return;
    modelsTabA = dataFilePtrs[FILE_MODELS_tab];
    modelsTabB = dataFilePtrs[FILE_MODELS_tab2];

    if(offset & 0x20000000) fileIdx = FILE_MODELS_bin2;
    else if(offset & 0x10000000) fileIdx = FILE_MODELS_bin;
    else if(modelsTabA) fileIdx = FILE_MODELS_bin;
    else if(modelsTabB) fileIdx = FILE_MODELS_bin2;
    else {
        STUBBED_PRINTF("models_dolphin.c");
    }

    offs = (offset & 0x0fffffff);
    entry = (ModelsBinEntry *)((uint)dataFilePtrs[fileIdx] + offs);
    unk18 = &entry->unk18;
    *outNoAmap = unk18->noAmap;
    *outNAnimations = unk18 ->nAnimations;
    *outAnimCacheSize = unk18 ->animCacheSize;
    *outSize = entry->size;
}

//official name: piGetTExtureInfo (weird capitalization)
//gets info for tex0
void piGetTExtureInfo(uint offset, uint mipIdx, uint *outSize,
undefined4 *outCompSize, int nFrames, void *dest, int doWhat) {
    //doWhat: TexGetMipmapOp
	u32 uVar1;
	uint *entry;
	ZlbHeader *zlb;
	DataFileId32 fileIdx;
	uint offs;
    void *tex0tabA;
    void *tex0tabB;

    if(!(dataFilePtrs[FILE_TEX0_bin] || dataFilePtrs[FILE_TEX0_bin2])) return;
    tex0tabA = dataFilePtrs[FILE_TEX0_tab];
    tex0tabB = dataFilePtrs[FILE_TEX0_tab2];

    if(offset & 0x80000000) fileIdx = FILE_TEX0_bin2;
    else if(offset & 0x40000000) fileIdx = FILE_TEX0_bin;
    else if(tex0tabA) fileIdx = FILE_TEX0_bin;
    else if(tex0tabB) fileIdx = FILE_TEX0_bin2;

    offs = offset & 0x00ffffff;
    if((doWhat == TexGetMipmapOp_getNext) && dest) {
        entry = (uint *)((int)dataFilePtrs[fileIdx] + offs * 2
            + *(int *)((int)dest + nFrames * 4));
        /* in final this is entry[2], entry[1]
            but that's because entry has 4 added */
        offs = entry[3];
        *outSize = entry[2];
        *outCompSize = offs;
    } else if((doWhat == TexGetMipmapOp_copy) && dest) {
        memcpy_src_dst_len(
            (void *)((int)dataFilePtrs[fileIdx] + offs * 2),
            dest, (nFrames + 1) * 4);

    } else { //TexGetMipmapOp_getSize
        //unlike for tex1, DIR is not supported.
        zlb = (ZlbHeader *)((int)dataFilePtrs[fileIdx] + offs * 2);
        uVar1 = zlb->compLen;
        *outSize = zlb->decLen;
        *outCompSize = uVar1;
    }
}

//get info for tex1
void piGetTEXTUREInfo(uint offset, uint mipIdx, uint *outSize,
undefined4 *outCompSize, int nFrames, void *dest, int doWhat) {
    //doWhat: TexGetMipmapOp
	int iVar1;
	u32 compLen;
	int *entry;
	ZlbHeader *zlb;
	DataFileId32 fileIdx;
	uint offs;
    void *tex1tabA;
    void *tex1tabB;

	if(!(dataFilePtrs[FILE_TEX1_bin] || dataFilePtrs[FILE_TEX1_bin2])) return;
    tex1tabA = dataFilePtrs[FILE_TEX1_tab];
    tex1tabB = dataFilePtrs[FILE_TEX1_tab2];

    if(offset & 0x80000000) fileIdx = FILE_TEX1_bin2;
    else if(offset & 0x40000000) fileIdx = FILE_TEX1_bin;
    else if(tex1tabA) fileIdx = FILE_TEX1_bin;
    else if(tex1tabB) fileIdx = FILE_TEX1_bin2;
    //else fileIdx is undefined. not sure if this is a bug,
    //or something that should never be able to happen.

    offs = offset & 0x00ffffff;
    if((doWhat == TexGetMipmapOp_getNext) && dest) {
        //unsure what this is actually doing
        //r0  = r17 * 4
        //r19 = r24 + r0
        //r0  = r29 * 4
        //r3  = r30 + r0 (8035c9a8)
        //r4  = 0x128(r3)  (dataFilePtrs)
        //  the +0x128 is a red herring, it's fromm the section being offset wrong
        //r3  = r28 * 2
        //r0  = 0(r19)
        //r27 = r3  + r0
        //r27 = r4  + r27
        //r31 = r27 + 4
        //I think the differences are mostly because of the section offset
        entry = (int*)(
            (int)(*(int*)((int)dataFilePtrs[fileIdx]) + offs * 2 +
            ((int)dest + nFrames * 4))
        )+1;
        offs = entry[1];
        iVar1 = entry[2];
        *outCompSize = iVar1;
        *outSize = offs;

    } else if((doWhat == TexGetMipmapOp_copy) && dest) {
        memcpy_src_dst_len(
            (void *)((int)dataFilePtrs[fileIdx] + offs * 2),
            dest, (nFrames + 1) * 4);

    } else { //TexGetMipmapOp_getSize
        zlb = (ZlbHeader *)((int)dataFilePtrs[fileIdx] + offs * 2);
        compLen = zlb->compLen;
        *outSize = zlb->decLen;
        if(!strncmp("DIR", (char *)zlb, 3)) {
            *outCompSize = 0x0ffffffff;
        } else {
            *outCompSize = compLen;
        }
    }
}

void piRomLoadSection(int id, void *dest) {
	DbMapsBinEntry *entry;
    int len;
    int dummy;
    int dummy2;
    int outLen;

	if(!dataFilePtrs[FILE_MAPS_bin]) {
		OSPanic(__FILE__, 1084,
            "piRomLoadSection(): DB_MAPS Bin Not Loaded");
        STUBBED_OP(id);
	}
    entry = (DbMapsBinEntry *)((int)dataFilePtrs[FILE_MAPS_bin] + id);
	if(entry->sig == SIG_UNCOMPRESSED_FILE) {
        //what the hell is going on here
        id = (
            (entry->offset + sizeof(DbMapsBinEntry) + (uint)entry) -
            (uint)dataFilePtrs[FILE_MAPS_bin]
        );
        memcpy_src_dst_len((void*)(
            (uint)dataFilePtrs[FILE_MAPS_bin] + (uint)id),
            dest,entry->len);
	} else if(entry->sig == SIG_LZO_COMPRESSED_FILE) { //LZO compressed file.
		id = (entry->offset + 0x28) + (int)entry - (int)dataFilePtrs[FILE_MAPS_bin];
		PPCMtmmcr1(0x7fc00000);
		PPCMtmmcr0(0x42);

        outLen = lzoDecompress(
            (void *)((int)dataFilePtrs[FILE_MAPS_bin] + id),
            entry->compLen, dest, &len);

        PPCMtmmcr0(0);
		PPCMtmmcr1(0);
        STUBBED_PRINTF("<Cyc %d | Instr %d | L1misscyc %d | DCmiss %d>\n",
            (int)(PPCMfpmc1() * 0.001f),
            (int)(PPCMfpmc2() * 0.001f),
            (int)(PPCMfpmc3() * 0.001f),
            (int)(PPCMfpmc4() * 0.001f));
		PPCMtpmc1(0);
		PPCMtpmc2(0);
		PPCMtpmc3(0);
		PPCMtpmc4(0);

		DCStoreRange(dest, len);
	}
}

void loadTableFiles_(void) {
    loadTableFiles();
}

//convert map ID to dir index
MapDirIdx32 piRomGetGamNumber(mapId32 map) {
	if((int)map >= NUM_MAP_DIRS) {
        //doesn't match if we include a parameter
        STUBBED_PRINTF("piRomGetGamNumber() ----- mapNumber <%d> too high");
        return 0;
    }
	return mapIdXltnTbl[map];
}

//load and decompress an asset archive
int piRomLoadSectionL(DataFileId32 fileNo, void *dest, int offset,
size_t length, uint *outSize, int index, u8 flags) {
	int start;
	u32 loaded;
	char *sig;
	int *header;
	int *tab2;
	int *tab1;
	int ii;
	int readLen;
	void *tmpBuf;
	DVDFileInfo file;
    int **files;
    ZlbHeader zlb;
    int decompressResult; //set but not used

    files = dataFilePtrs;
	tab1 = NULL;
	tab2 = NULL;

    switch(fileNo) {
        case FILE_MODELS_bin:
            tab1 = files[FILE_MODELS_tab];
            tab2 = files[FILE_MODELS_tab2];
            if(offset & 0x20000000) {
                fileNo = FILE_MODELS_bin2;
                if(outSize) {
                    start = tab2[index] & 0x00ffffff;
                    ii = 0;
                    if(!start) {
                        while((tab2[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - start;
                    } else if(start < (tab2[index - 1] & 0x00ffffff)) {
                        ii = 0;
                        while(start != (tab2[ii++] & 0x00ffffff));
                        while((tab2[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - start;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - start;
                    }
                }
            } else if(offset & 0x10000000) {
                fileNo = FILE_MODELS_bin;
                if(outSize) {
                    start = tab1[index] & 0x00ffffff;
                    ii = 0;
                    if(start == 0) {
                        while((tab1[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - start;
                    } else if(start < (tab1[index - 1] & 0x00ffffff)) {
                        ii = 0;
                        while(start != (tab1[ii++] & 0x00ffffff));
                        while((tab1[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - start;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - start;
                    }
                }
            } else if(tab1) {
                fileNo = FILE_MODELS_bin;
                if(outSize) {
                    start = tab1[index] & 0x00ffffff;
                    ii = 0;
                    if(start == 0) {
                        while((tab1[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - start;
                    } else if(start < (tab1[index - 1] & 0x00ffffff)) {
                        ii = 0;
                        while(start != (tab1[ii++] & 0x00ffffff));
                        while((tab1[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - start;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - start;
                    }
                }
            } else if(tab2) {
                fileNo = FILE_MODELS_bin2;
                if(outSize) {
                    start = tab2[index] & 0x00ffffff;
                    ii = 0;
                    if(start == 0) {
                        while((tab2[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - start;
                    } else if((start < (tab2[index -1] & 0x00ffffff))) {
                        ii = 0;
                        while(start != (tab2[ii++] & 0x00ffffff));
                        while((tab2[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - start;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0x00ffffff) <= start);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - start;
                    }
                }
            }
            offset &= 0x0fffffff;
            break;

        case FILE_ANIM_BIN:
            tab1 = files[FILE_ANIM_TAB];
            tab2 = files[FILE_ANIM_TAB2];
            if(offset & 0x20000000) {
                fileNo = FILE_ANIM_BIN2;
                if(outSize) {
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0x00ffffff);
                }
            } else if(offset & 0x10000000) {
                fileNo = FILE_ANIM_BIN;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0x00ffffff);
                }
            } else if(tab1) {
                fileNo = FILE_ANIM_BIN;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0x00ffffff);
                }
            } else if(tab2) {
                fileNo = FILE_ANIM_BIN2;
                if(outSize) {
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0x00ffffff);
                }
            }
            offset &= 0x0fffffff;
            break;

        case FILE_BLOCKS_bin:
            tab1 = files[FILE_BLOCKS_tab];
            tab2 = files[FILE_BLOCKS_tab2];
            if(offset & 0x20000000) {
                fileNo = FILE_BLOCKS_bin2;
                if(outSize) {
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0x00ffffff);
                }
            } else if(offset & 0x10000000) {
                fileNo = FILE_BLOCKS_bin;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0x00ffffff);
                }
            } else if(tab1) {
                fileNo = FILE_BLOCKS_bin;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0x00ffffff);
                }
            } else if(tab2) {
                fileNo = FILE_BLOCKS_bin2;
                if(outSize) {
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0x00ffffff);
                }
            }
            offset &= 0x0fffffff;
            break;

        case FILE_TEX0_bin:
            loaded = piGetLoadedFlags(0);
            if(((loaded & 0x400) == 0) && ((loaded & 0x100) == 0)) {
                tab1 = files[FILE_TEX0_tab];
            }
            if(((loaded & 0x800) == 0) && ((loaded & 0x200) == 0)) {
                tab2 = files[FILE_TEX0_tab2];
            }
            if(tab2 && TEX0_TAB[index] & 0x80000000) {
                fileNo = FILE_TEX0_bin2;
                if(outSize) {
                    offset = tab2[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    }
                }
            }
            else if(tab1 && TEX0_TAB[index] & 0x40000000) {
                fileNo = FILE_TEX0_bin;
                if(outSize) {
                    offset = tab1[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    }
                }
            }
            else if(tab2) {
                fileNo = FILE_TEX0_bin2;
                if(outSize) {
                    offset = tab2[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    }
                }
            } else if(tab1) {
                fileNo = FILE_TEX0_bin;
                if(outSize) {
                    offset = tab1[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    }
                }
            }
            offset &= 0x0fffffff;
            break;

        case FILE_TEX1_bin:
            loaded = piGetLoadedFlags(0);
            if(((loaded & 0x4000) == 0) && ((loaded & 0x1000) == 0)) {
                tab1 = files[FILE_TEX1_tab];
            }
            if(((loaded & 0x8000) == 0) && ((loaded & 0x2000) == 0)) {
                tab2 = files[FILE_TEX1_tab2];
            }
            if(tab2 && TEX1_TAB[index] & 0x80000000) {
                fileNo = FILE_TEX1_bin2;
                if(outSize) {
                    offset = tab2[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    }
                }
            }
            else if(tab1 && TEX1_TAB[index] & 0x40000000) {
                fileNo = FILE_TEX1_bin;
                if(outSize) {
                    offset = tab1[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    }
                }
            }
            else if(tab2) {
                fileNo = FILE_TEX1_bin2;
                if(outSize) {
                    offset = tab2[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii-1] & 0x00ffffff) - offset;
                    }
                }
            } else if(tab1) {
                fileNo = FILE_TEX1_bin;
                if(outSize) {
                    offset = tab1[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0x00ffffff) <= offset);
                        *outSize = (tab1[ii-1] & 0x00ffffff) - offset;
                    }
                }
            }
            offset &= 0x0fffffff;
            break;

        default: break;
    }
    if(flags & 1) return 0;

    //decode the file
    if(!files[fileNo]) {
        //some debug assert?
        //this check makes no sense, since we check for it again later.
    }
    else if((fileNo == FILE_MODELS_bin) || (fileNo == FILE_MODELS_bin2)) {
        header = (int *)((int)files[fileNo] + offset);
        if(*header == SIG_UNCOMPRESSED_FILE) {
            memcpy_src_dst_len((void *)((int)header + (int)files[fileNo] +
                ((header[2] + 0x18) - (int)files[fileNo])),
                dest, header[1]);
        } else if(*header == SIG_LZO_COMPRESSED_FILE) {
            decompressResult = lzoDecompress((void *)((int)header + (int)files[fileNo] +
                ((header[2] + 0x28) - (int)files[fileNo])),
                header[3] + -0x10, dest, &readLen);
            DCStoreRange(dest, readLen);
        }
    }
    else if((fileNo == FILE_TEX0_bin) || (fileNo == FILE_TEX0_bin2)) {
        start = offset & 0x00ffffff;
        zlb = *(ZlbHeader*)(files[fileNo] + start);
        decompressResult = lzoDecompress((void *)((int)files[fileNo] + start + sizeof(ZlbHeader)),
            zlb.compLen,
            dest, &readLen);
        DCStoreRange(dest, readLen);
    }
    else if((fileNo == FILE_TEX1_bin) || (fileNo == FILE_TEX1_bin2)) {
        start = offset & 0x00ffffff;
        sig = (char *)((int)files[fileNo] + start);
        if(!strncmp("DIR", sig, 3)) {
            return (int)files[fileNo] + start + 0x20;
        }
        if(!strncmp(sig, "LZO", 3)) {
            decompressResult = lzoDecompress(
                (void *)((int)files[fileNo] + start + 0x10),
                *(int *)(sig + 0xc), dest, &readLen);
            DCStoreRange(dest, decompressResult);
        }
    }
    else if(files[fileNo]) {
        //default case, file is already loaded, just copy from it
        memcpy_src_dst_len((void *)((int)files[fileNo] + offset),
            dest, length);
    }
    else {
        STUBBED_PRINTF("######## DVDLOAD piRomLoadSectionL() ----- file=%s  #################\n",
            dataFileNames[fileNo]);
        //default case but file isn't loaded; read a chunk from it
        DVDOpen((char*)dataFileNames[fileNo], &file);
        if(((uint)dest & 0x1f) || (length & 0x1f)) {
            //not aligned; need to read aligned chunk into temp buffer.
            //probably could have used a stack buffer instead of alloc...
            tmpBuf = mmAlloc(length + 0x1f & 0x00ffffffe0,
                ALLOC_TAG_DVD_BUFFER, (volatile u32)"temp dvd buffer");
            DVDReadPrio(&file, tmpBuf,
                length + 0x1f & 0x00ffffffe0, offset, 2);
            memcpy_src_dst_len(tmpBuf, dest, length);
            STUBBED_PRINTF("PIFREE buffer  addr 0x%x\n", tmpBuf);
            mmFree(tmpBuf);
        } else { //range is aligned; we can read right into the destination buffer
            DVDReadPrio(&file, dest, length, offset, 2);
        }
        DCStoreRange(dest, length);
        DVDClose(&file);
    }
	return 0;
}

/**
 * @brief Load the specified file for the specified map.
 *
 *  @param gamno Map number to load for.
 *  @param fileNo File to load.
 *  @return The file data.
 *  @note May return NULL if the file is being loaded in the
 *    background, or there's no free slot to load it to.
 *    check @see{piLockFlags} to know if it's being loaded.
 */
void *piRomLoadLevel(int gamno, DataFileId32 fileNo) {
	bool bForceLoad;
	DVDFileInfo *pFile;
	int slot;
	char path[64];
	DVDFileInfo file;

    //@bug several missing null checks for mmAlloc

    STUBBED_PRINTF("ROMLOAD gamno=%d  level %s  fileno %d\n", gamno,
        mapNames[gamno], fileNo);

    STUBBED_PRINTF("FILENAME %s\n", dataFileNames[fileNo]);

    bForceLoad = false;
    switch(fileNo) {
        case FILE_VOXMAP_tab: //0x1A
        case FILE_VOXMAP_bin: { //0x1B
            if(dataFilePtrs[fileNo] && gamno == loadedFileMapIds[fileNo]) {
                //already loaded, return it
                return dataFilePtrs[fileNo];
            }
            PIFREE(fileNo, "");

            //open it
            //this one case uses a local variable for file instead of pFile,
            //probably because it never uses a callback.
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            if(!DVDOpen(path, &file)) return NULL;

            //total guess at params here
            STUBBED_PRINTF("LOAD FROM DISK... %s %s/%s %d size %d\n",
                "VOXMAPS", mapDirNames[gamno],
                dataFileNames[fileNo], fileNo, file.length);

            //get the size and alloc the buffer
            dataFileSizes[fileNo] = file.length;
            dataFilePtrs[fileNo] = mmAlloc(dataFileSizes[fileNo],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)"VOXMAPS");

            //read the file and return it
            DVDReadPrio(&file, dataFilePtrs[fileNo],
                dataFileSizes[fileNo], 0, 2);
            DVDClose(&file);
            loadedFileMapIds[fileNo] = gamno;
            return dataFilePtrs[fileNo];
        }

        case FILE_ANIMCURV_bin: //0x0D
        case FILE_ANIMCURV_tab: { //0x0E
            if(dataFilePtrs[fileNo] && gamno == loadedFileMapIds[fileNo]) {
                return dataFilePtrs[fileNo];
            }
            PIFREE(fileNo, "ANIMCURVE/TAB");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[fileNo]);
            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[fileNo] = pFile->length;
            dataFilePtrs[fileNo] = mmAlloc(dataFileSizes[fileNo],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[fileNo]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[fileNo],
                    dataFileSizes[fileNo], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
            } else if(fileNo == FILE_ANIMCURV_bin) {
                //callback will free pFile (XXX verify)
                loadedFiles |= FILE_FLAG_ANIMCURV_bin;
                STUBBED_PRINTF("INANIMCURVE LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[fileNo],
                    dataFileSizes[fileNo], 0, piDVDCallbackAnimCurve);
            } else {
                //callback will free pFile
                loadedFiles |= FILE_FLAG_ANIMCURV_tab;
                STUBBED_PRINTF("INANIMCURVETAB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[fileNo],
                    dataFileSizes[fileNo], 0, piDVDCallbackAnimCurveTab);
            }
            loadedFileMapIds[fileNo] = gamno;
            return dataFilePtrs[fileNo];
        }

        case FILE_BLOCKS_bin: { //0x25
            if(!(dataFilePtrs[FILE_BLOCKS_bin] || dataFilePtrs[FILE_BLOCKS_bin2])) {
                bForceLoad = true;
            }

            if(dataFilePtrs[FILE_BLOCKS_bin]
            && loadedFileMapIds[FILE_BLOCKS_bin] == gamno) {
                //already loaded in slot 1
                return dataFilePtrs[FILE_BLOCKS_bin];
            }
            else if(dataFilePtrs[FILE_BLOCKS_bin2]
            && loadedFileMapIds[FILE_BLOCKS_bin2] == gamno) {
                //already loaded in slot 2
                return dataFilePtrs[FILE_BLOCKS_bin2];
            }
            else if(loadedFileMapIds[FILE_BLOCKS_bin] == -1) {
                //slot 1 is empty, use it
                slot = FILE_BLOCKS_bin;
            }
            else if(loadedFileMapIds[FILE_BLOCKS_bin2] == -1) {
                //slot 2 is empty, use it
                slot = FILE_BLOCKS_bin2;
            }
            else { //no free slot to load to
                STUBBED_PRINTF("ALL BASES FULL DB_BLOCKS\n");
                return NULL;
            }

            PIFREE(slot, "BLOCKS");
            if(gamno > 4) {
                sprintf(path, "%s/mod%d.bin", mapNames[gamno], gamno + 1);
            } else {
                sprintf(path, "%s/mod%d.bin", mapNames[gamno], gamno);
            }

            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)"BLOCKS");
            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }
            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)"BLOCKS");
            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
            } else {
                //callback will free pFile
                if(slot == FILE_BLOCKS_bin) loadedFiles |= FILE_FLAG_BLOCKS_bin;
                else loadedFiles |= FILE_FLAG_BLOCKS_bin2;
                STUBBED_PRINTF("INBLOCKS LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackBlockbin);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_BLOCKS_tab: { //0x26
            if(!(dataFilePtrs[FILE_BLOCKS_tab] || dataFilePtrs[FILE_BLOCKS_tab2])) {
                bForceLoad = true;
            }
            if(dataFilePtrs[FILE_BLOCKS_tab]
            && loadedFileMapIds[FILE_BLOCKS_tab] == gamno) {
                return dataFilePtrs[FILE_BLOCKS_tab];
            }
            else if(dataFilePtrs[FILE_BLOCKS_tab2]
            && loadedFileMapIds[FILE_BLOCKS_tab2] == gamno) {
                return dataFilePtrs[FILE_BLOCKS_tab2];
            }
            else if(loadedFileMapIds[FILE_BLOCKS_tab] == -1) {
                slot = FILE_BLOCKS_tab;
            }
            else if(loadedFileMapIds[FILE_BLOCKS_tab2] == -1) {
                slot = FILE_BLOCKS_tab2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_BLOCKSTAB\n");
                return NULL;
            }

            PIFREE(slot, "BLOCKSTAB");
            if(gamno > 4) {
                sprintf(path, "%s/mod%d.tab", mapNames[gamno], gamno + 1);
            } else {
                sprintf(path, "%s/mod%d.tab", mapNames[gamno], gamno);
            }
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)"BLOCKSTAB");
            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
                piMergeIndex(BLOCKS_TAB, FILE_BLOCKS_tab,
                    FILE_BLOCKS_tab2, 0x800);
            } else {
                if(slot == FILE_BLOCKS_tab) loadedFiles |= FILE_FLAG_BLOCKS_tab;
                else loadedFiles |= FILE_FLAG_BLOCKS_tab2;
                STUBBED_PRINTF("INBLOCKTAB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackBlockstab);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_MODELS_bin: { //0x2B
            STUBBED_PRINTF("GOT TO MODELS\n");
            if(!(dataFilePtrs[FILE_MODELS_bin] || dataFilePtrs[FILE_MODELS_bin2])) {
                bForceLoad = true;
                STUBBED_PRINTF("forceload\n");
            }
            if(dataFilePtrs[FILE_MODELS_bin]
            && loadedFileMapIds[FILE_MODELS_bin] == gamno) {
                STUBBED_PRINTF("allloaded 1\n");
                return dataFilePtrs[FILE_MODELS_bin];
            }
            else if(dataFilePtrs[FILE_MODELS_bin2]
            && loadedFileMapIds[FILE_MODELS_bin2] == gamno) {
                STUBBED_PRINTF("allloaded 2\n");
                return dataFilePtrs[FILE_MODELS_bin2];
            }
            else if(loadedFileMapIds[FILE_MODELS_bin] == -1) {
                slot = FILE_MODELS_bin;
            }
            else if(loadedFileMapIds[FILE_MODELS_bin2] == -1) {
                slot = FILE_MODELS_bin2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_MODELS\n");
                return NULL;
            }

            PIFREE(slot, "MODELS");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
            } else {
                if(slot == FILE_MODELS_bin) loadedFiles |= FILE_FLAG_MODELS_bin;
                else loadedFiles |= FILE_FLAG_MODELS_bin2;
                STUBBED_PRINTF("INMODELS LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackModelsbin);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_MODELS_tab: { //0x2A
            if(!(dataFilePtrs[FILE_MODELS_tab] || dataFilePtrs[FILE_MODELS_tab2])) {
                bForceLoad = true;
                STUBBED_PRINTF("forceload\n");
            }

            if(dataFilePtrs[FILE_MODELS_tab]
            && loadedFileMapIds[FILE_MODELS_tab] == gamno) {
                return dataFilePtrs[FILE_MODELS_tab];
            }
            else if(dataFilePtrs[FILE_MODELS_tab2]
            && loadedFileMapIds[FILE_MODELS_tab2] == gamno) {
                return dataFilePtrs[FILE_MODELS_tab2];
            }
            else if(loadedFileMapIds[FILE_MODELS_tab] == -1) {
                slot = FILE_MODELS_tab;
            }
            else if(loadedFileMapIds[FILE_MODELS_tab2] == -1) {
                slot = FILE_MODELS_tab2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_MODTAB\n");
                return NULL;
            }

            PIFREE(slot, "MODTAB");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
                piMergeIndex(MODELS_TAB, FILE_MODELS_tab,
                    FILE_MODELS_tab2, 0x800);
            } else {
                if(slot == FILE_MODELS_tab) loadedFiles |= FILE_FLAG_MODELS_tab;
                else loadedFiles |= FILE_FLAG_MODELS_tab2;
                STUBBED_PRINTF("INMODTABLOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot], dataFileSizes[slot],
                    0, piDVDCallbackModtab);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_ANIM_BIN: { //0x30
            if(!(dataFilePtrs[FILE_ANIM_BIN] || dataFilePtrs[FILE_ANIM_BIN2])) {
                bForceLoad = true;
            }
            if(dataFilePtrs[FILE_ANIM_BIN]
            && loadedFileMapIds[FILE_ANIM_BIN] == gamno) {
                return dataFilePtrs[FILE_ANIM_BIN];
            }
            else if(dataFilePtrs[FILE_ANIM_BIN2]
            && loadedFileMapIds[FILE_ANIM_BIN2] == gamno) {
                return dataFilePtrs[FILE_ANIM_BIN2];
            }
            else if(loadedFileMapIds[FILE_ANIM_BIN] == -1) {
                slot = FILE_ANIM_BIN;
            }
            else if(loadedFileMapIds[FILE_ANIM_BIN2] == -1) {
                slot = FILE_ANIM_BIN2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_ANIM\n");
                return NULL;
            }

            PIFREE(slot, "ANIM");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
            } else {
                if(slot == FILE_ANIM_BIN) loadedFiles |= FILE_FLAG_ANIM_BIN;
                else loadedFiles |= FILE_FLAG_ANIM_BIN2;
                STUBBED_PRINTF("INANIM LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackAnimbin);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_ANIM_TAB: { //0x2F
            if(!(dataFilePtrs[FILE_ANIM_TAB] || dataFilePtrs[FILE_ANIM_TAB2])) {
                bForceLoad = true;
            }
            if(dataFilePtrs[FILE_ANIM_TAB]
            && loadedFileMapIds[FILE_ANIM_TAB] == gamno) {
                return dataFilePtrs[FILE_ANIM_TAB];
            }
            else if(dataFilePtrs[FILE_ANIM_TAB2]
            && loadedFileMapIds[FILE_ANIM_TAB2] == gamno) {
                return dataFilePtrs[FILE_ANIM_TAB2];
            }
            else if(loadedFileMapIds[FILE_ANIM_TAB] == -1) {
                slot = FILE_ANIM_TAB;
            }
            else if(loadedFileMapIds[FILE_ANIM_TAB2] == -1) {
                slot = FILE_ANIM_TAB2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_ANIMTAB\n");
                return NULL;
            }

            PIFREE(slot, "ANIMTAB");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
                piMergeIndex(ANIM_TAB,
                    FILE_ANIM_TAB, FILE_ANIM_TAB2, 3000);
            } else {
                if(slot == FILE_ANIM_TAB) loadedFiles |= FILE_FLAG_ANIM_TAB;
                else loadedFiles |= FILE_FLAG_ANIM_TAB2;
                STUBBED_PRINTF("INANIMTAB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackAnimtab);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_TEX0_bin: { //0x23
            if(!(dataFilePtrs[FILE_TEX0_bin] || dataFilePtrs[FILE_TEX0_bin2])) {
                bForceLoad = true;
            }
            if(dataFilePtrs[FILE_TEX0_bin]
            && loadedFileMapIds[FILE_TEX0_bin] == gamno) {
                return dataFilePtrs[FILE_TEX0_bin];
            }
            else if(dataFilePtrs[FILE_TEX0_bin2]
            && loadedFileMapIds[FILE_TEX0_bin2] == gamno) {
                return dataFilePtrs[FILE_TEX0_bin2];
            }
            else if(loadedFileMapIds[FILE_TEX0_bin] == -1) {
                slot = FILE_TEX0_bin;
            }
            else if(loadedFileMapIds[FILE_TEX0_bin2] == -1) {
                slot = FILE_TEX0_bin2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_TEXTURES2\n");
                return NULL;
            }

            PIFREE(slot, "TEXTURES2");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot] + 0x20,
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            STUBBED_PRINTF("######## DVDLOAD piRomLoadLevel() ---- "
                "file=%s  piTable 0x%x #################\n",
                dataFileNames[fileNo], dataFilePtrs[slot]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
            } else {
                if(slot == FILE_TEX0_bin) loadedFiles |= FILE_FLAG_TEX0_bin;
                else loadedFiles |= FILE_FLAG_TEX0_bin2;
                STUBBED_PRINTF("INTEX2 LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackTexbin2);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_TEX0_tab: { //0x24
            if(!(dataFilePtrs[FILE_TEX0_tab] || dataFilePtrs[FILE_TEX0_tab2])) {
                bForceLoad = true;
            }
            if(dataFilePtrs[FILE_TEX0_tab]
            && loadedFileMapIds[FILE_TEX0_tab] == gamno) {
                return dataFilePtrs[FILE_TEX0_tab];
            }
            else if(dataFilePtrs[FILE_TEX0_tab2]
            && loadedFileMapIds[FILE_TEX0_tab2] == gamno) {
                return dataFilePtrs[FILE_TEX0_tab2];
            }
            else if(loadedFileMapIds[FILE_TEX0_tab] == -1) {
                slot = FILE_TEX0_tab;
            }
            else if(loadedFileMapIds[FILE_TEX0_tab2] == -1) {
                slot = FILE_TEX0_tab2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_TEXTAB2\n");
                return NULL;
            }

            PIFREE(slot, "TEXTAB2");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot] + 0x20,
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            STUBBED_PRINTF("######## DVDLOAD piRomLoadLevel() ----- "
                "file=%s  #################\n",
                dataFileNames[fileNo]);

            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
                piMergeIndex(TEX0_TAB, FILE_TEX0_tab,
                    FILE_TEX0_tab2, 0x1000);
            } else if(slot == FILE_TEX0_tab) {
                loadedFiles |= FILE_FLAG_TEX0_tab;
                STUBBED_PRINTF("INTEX2TAB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDvdCallbacktex2tab36);
            } else {
                loadedFiles |= FILE_FLAG_TEX0_tab2;
                STUBBED_PRINTF("INTEX2TAB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackTextab33);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_TEX1_bin: { //0x20
            if(!(dataFilePtrs[FILE_TEX1_bin] || dataFilePtrs[FILE_TEX1_bin2])) {
                bForceLoad = true;
            }

            if(dataFilePtrs[FILE_TEX1_bin]
            && loadedFileMapIds[FILE_TEX1_bin] == gamno) {
                return dataFilePtrs[FILE_TEX1_bin];
            }
            else if(dataFilePtrs[FILE_TEX1_bin2]
            && loadedFileMapIds[FILE_TEX1_bin2] == gamno) {
                return dataFilePtrs[FILE_TEX1_bin2];
            }
            else if(loadedFileMapIds[FILE_TEX1_bin] == -1) {
                slot = FILE_TEX1_bin;
            }
            else if(loadedFileMapIds[FILE_TEX1_bin2] == -1) {
                slot = FILE_TEX1_bin2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_TEXTURES\n");
                return NULL;
            }

            PIFREE(slot, "TEXTURES");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[fileNo]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot] + 0x20,
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[fileNo]);
            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
            } else {
                if(slot == FILE_TEX1_bin) loadedFiles |= FILE_FLAG_TEX1_bin;
                else loadedFiles |= FILE_FLAG_TEX1_bin2;
                STUBBED_PRINTF("INTEX LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackTexbin);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        case FILE_TEX1_tab: { //0x21
            if(!(dataFilePtrs[FILE_TEX1_tab] || dataFilePtrs[FILE_TEX1_tab2])) {
                bForceLoad = true;
            }

            if(dataFilePtrs[FILE_TEX1_tab]
            && loadedFileMapIds[FILE_TEX1_tab] == gamno) {
                return dataFilePtrs[FILE_TEX1_tab];
            }
            else if(dataFilePtrs[FILE_TEX1_tab2]
            && loadedFileMapIds[FILE_TEX1_tab2] == gamno) {
                return dataFilePtrs[FILE_TEX1_tab2];
            }
            else if(loadedFileMapIds[FILE_TEX1_tab] == -1) {
                slot = FILE_TEX1_tab;
            }
            else if(loadedFileMapIds[FILE_TEX1_tab2] == -1) {
                slot = FILE_TEX1_tab2;
            }
            else {
                STUBBED_PRINTF("ALL BASES FULL DB_TEXTAB\n");
                return NULL;
            }

            PIFREE(slot, "TEXTAB");
            sprintf(path, "%s/%s", mapNames[gamno], dataFileNames[fileNo]);
            pFile = (DVDFileInfo *)mmAlloc(sizeof(DVDFileInfo),
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[slot]);

            if(!DVDOpen(path, pFile)) {
                //@bug pFile is leaked
                return NULL;
            }

            dataFileSizes[slot] = pFile->length;
            dataFilePtrs[slot] = mmAlloc(dataFileSizes[slot],
                ALLOC_TAG_DVD_BUFFER, (volatile u32)dataFileNames[fileNo]);
            DCInvalidateRange(dataFilePtrs[slot], dataFileSizes[slot]);
            if(bForceLoad) {
                DVDReadPrio(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, 2);
                DVDClose(pFile);
                mmFree(pFile);
                piMergeIndex(TEX1_TAB, FILE_TEX1_tab,
                    FILE_TEX1_tab2, 0x1000);
            } else if(slot == FILE_TEX1_tab) {
                loadedFiles |= FILE_FLAG_TEX1_tab;
                STUBBED_PRINTF("INTEXTAB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackTextab33);
            } else {
                loadedFiles |= FILE_FLAG_TEX1_tab2;
                STUBBED_PRINTF("INTEXTABB LOCK %x\n", loadedFiles);
                DVDReadAsync(pFile, dataFilePtrs[slot],
                    dataFileSizes[slot], 0, piDVDCallbackTextab33);
            }
            loadedFileMapIds[slot] = gamno;
            return dataFilePtrs[slot];
        }

        default: {
            STUBBED_PRINTF("######## DVDLOAD piRomLoadLevel() ---- "
                "file=%s  #################\n", dataFileNames[fileNo]);
            STUBBED_PRINTF("ERROR in piRomLoadLevel file %d\n", fileNo);
            return NULL;
        }
    }
}

int mapCheckCurBlocks(MapDirIdx32 map) {
	if(loadedFileMapIds[FILE_BLOCKS_bin ] == map - 1) return 0;
	if(loadedFileMapIds[FILE_BLOCKS_bin2] == map - 1) return 1;
	return -1;
}

int piMergeIndex(uint *table, DataFileId32 fileNo1, DataFileId32 fileNo2,
int count) {
	BOOL noTab1;
	BOOL noTab2;
	int tblSize;
	int *tbl1;
	int *tbl2;
	int ii;
	int local_24;
    int dummy;

	ii = 0;
	noTab1 = false;
	noTab2 = false;
	tblSize = 0;
    local_24 = 0;
    if(!dataFilePtrs[fileNo1] || !dataFilePtrs[fileNo2]) {
        STUBBED_PRINTF("piMergeIndex  one or other tabfiles is not loaded %x %x\n",
            dataFilePtrs[fileNo1], dataFilePtrs[fileNo2]);
        if(!dataFilePtrs[fileNo1]) noTab1 = true;
        if(!dataFilePtrs[fileNo2]) noTab2 = true;
    }
	tbl1 = (int *)dataFilePtrs[fileNo1];
	tbl2 = (int *)dataFilePtrs[fileNo2];
	if     (table == MODELS_TAB) tblSize = MODELS_TAB_SIZE;
	else if(table == ANIM_TAB)   tblSize = ANIM_TAB_SIZE;
	else if(table == TEX0_TAB)   tblSize = TEX0_TAB_SIZE;
	else if(table == TEX1_TAB)   tblSize = TEX1_TAB_SIZE;
	else if(table == BLOCKS_TAB) tblSize = BLOCKS_TAB_SIZE;

	if(table == TEX0_TAB || table == TEX1_TAB) {
		for(; ii < tblSize; ii++) {
			if(!(noTab1 || tbl1[ii] == -1 || !(tbl1[ii] & 0x80000000u))) {
                table[ii] = tbl1[ii] & 0x7fffffff;
                table[ii] = table[ii] | 0x40000000;
            } else if(!(noTab2 || tbl2[ii] == -1)) {
                //XXX these checks are weird, might be wrong
                if(tbl2[ii] & 0x80000000u) {
                    table[ii] = tbl1[ii];
                }
                else if(!noTab1) {
                    if(tbl2[ii]) table[ii] = tbl2[ii];
                }
                else if(!noTab2) {
                    if(tbl1[ii]) table[ii] = tbl1[ii];
                }
            }
		}
	} else if(table == BLOCKS_TAB) {
		for(; ii < tblSize; ii++) {
			if(!(noTab1 || (tbl1[ii] != -1))) {
				BLOCKS_TAB[ii] = 0;
				noTab1 = true;
			} else if(!((noTab2) || (tbl2[ii] != -1))) {
                BLOCKS_TAB[ii] = 0;
                noTab2 = true;
            } else if(!((noTab1) || (tbl1[ii] == -1) || ((tbl1[ii] & 0x10000000U) == 0))) {
                BLOCKS_TAB[ii] = tbl1[ii];
            } else if(!((noTab2) || (tbl2[ii] == -1) || ((tbl2[ii] & 0x10000000U) == 0))) {
                BLOCKS_TAB[ii] = tbl2[ii] & 0x00ffffffU | 0x20000000;
            } else if(!((noTab1) || (tbl1[ii] == 0))) {
                BLOCKS_TAB[ii] = tbl1[ii];
            } else if(!((noTab2) || (tbl2[ii] == 0))) {
                BLOCKS_TAB[ii] = tbl2[ii];
            } else {
                BLOCKS_TAB[ii] = 0;
            }
		}
	} else {
		for(; ii < tblSize; ii++) {
			if(!((noTab1) || (tbl1[ii] == -1) || ((tbl1[ii] & 0x10000000U) == 0))) {
				table[ii] = tbl1[ii];
			} else if(!((noTab2) || (tbl2[ii] == -1) || ((tbl2[ii] & 0x10000000U) == 0))) {
                *(uint *)((int)table + ii * 4) = tbl2[ii] & 0x00ffffffU | 0x20000000;
            } else if(!((noTab1) || (tbl1[ii] == 0))) {
                table[ii] = tbl1[ii];
            } else if((!noTab2) && (tbl2[ii] != 0)) {
                table[ii] = tbl2[ii];
            }
		}
	}
	*(undefined4 *)((int)table + (ii + -1) * 4) = 0x0ffffffff;
    //@bug? unreachable (local_24 is always 0)
	if(local_24 && table == TEX1_TAB) {
		for(local_24 = 0; local_24 < ii; local_24++) {
            if(!(local_24 - ((local_24 >> 3) * 8))) {
                STUBBED_OP(noTab1);
                if(tbl1) { STUBBED_OP(tbl1); }
                if(tbl2) { STUBBED_OP(tbl2); }
                if(noTab1) { STUBBED_OP(noTab1); }
            }
		}
	}
	return 1;
}

int piRomFreeLevel(int map, uint flags) {
	int iList;
	PiFreeList localFreeList;

	localFreeList = piFreeList;
	//freeList.item[0].mapNo = map;

    for(iList = 0; iList < PI_FLIST_SIZE; iList++) {
        /* this check works out to:
        - file is not NULL and either:
            - it belongs to the current map and we're freeing the current map,
                and a nonsensical bitfield check, OR
            - it belongs to the other map and we're freeing the other map
        */
		if(dataFilePtrs[localFreeList.item[iList].fileNo] && (
            flags & piRomFreeLevel_flag_freeForCurMap || (
                (flags & localFreeList.item[iList].fileNo + 1U) && //@bug this makes no sense (decomp error?)
                map == loadedFileMapIds[localFreeList.item[iList].fileNo]
            ) || (
                flags & piRomFreeLevel_flag_freeForOtherMap && (
                    map != loadedFileMapIds[localFreeList.item[iList].fileNo]
                )
        ))) {
            //free the file and clear the pointer and owner-map-ID
            STUBBED_PRINTF("PIFREE pitable[%d]  addr 0x%x  --- gamno %d size %d the file GAMNO %d\n",
                localFreeList.item[iList].fileNo,
                dataFilePtrs[localFreeList.item[iList].fileNo], map,
                dataFileSizes[localFreeList.item[iList].fileNo],
                loadedFileMapIds[localFreeList.item[iList].fileNo]);
			mmFree(dataFilePtrs[localFreeList.item[iList].fileNo]);
			dataFilePtrs[localFreeList.item[iList].fileNo] = NULL;
			loadedFileMapIds[localFreeList.item[iList].fileNo] = -1;

            //if we freed a table file, rebuild the table
            switch(localFreeList.item[iList].fileNo) {
                case FILE_TEX1_tab: case FILE_TEX1_tab2:
                    piMergeIndex(TEX1_TAB,
                        FILE_TEX1_tab, FILE_TEX1_tab2,
                        TEX1_TAB_SIZE);
                    break;

                case FILE_TEX0_tab: case FILE_TEX0_tab2:
                    piMergeIndex(TEX0_TAB,
                        FILE_TEX0_tab, FILE_TEX0_tab2,
                        TEX0_TAB_SIZE);
                    break;

                case FILE_BLOCKS_tab: case FILE_BLOCKS_tab2:
                    piMergeIndex(BLOCKS_TAB,
                        FILE_BLOCKS_tab, FILE_BLOCKS_tab2,
                        BLOCKS_TAB_SIZE);
                    break;

                case FILE_MODELS_tab: case FILE_MODELS_tab2:
                    piMergeIndex(MODELS_TAB,
                        FILE_MODELS_tab, FILE_MODELS_tab2,
                        MODELS_TAB_SIZE);
                    STUBBED_PRINTF("MODTAB %4d 0x%x ", map, flags);
                    STUBBED_PRINTF("T1 0x%x ", dataFilePtrs[FILE_MODELS_tab]);
                    STUBBED_PRINTF("T2 0x%x ", dataFilePtrs[FILE_MODELS_tab2]);
                    break;

                case FILE_ANIM_TAB: case FILE_ANIM_TAB2:
                    piMergeIndex(ANIM_TAB,
                        FILE_ANIM_TAB, FILE_ANIM_TAB2,
                        ANIM_TAB_SIZE);
                    break;
                default:
                    STUBBED_PRINTF("Warning in piRomFreeLevel file || %s || not found !\n",
                        dataFileNames[localFreeList.item[iList].fileNo]);
            }
		}
		if(iList >= PI_FLIST_SIZE) {
			OSPanic("pi_dolphin.c", 3549,
			    "piRomFreeLevel(): flist array overflow");
		}
	}
	return 1;
}

uint* piRomGetTab(DataFileId32 file) {
	switch(file) {
        case FILE_TEX1_tab: return TEX1_TAB;
        case FILE_TEX0_tab: return TEX0_TAB;
        case FILE_BLOCKS_tab: return BLOCKS_TAB;
        case FILE_MODELS_tab: return MODELS_TAB;
        case FILE_ANIM_TAB: return ANIM_TAB;
        default: {
            STUBBED_PRINTF("ROMLOADTAB file=%s\n", dataFileNames[file]);
            return NULL;
        }
    }
}

void loadTableFiles(void) {
	BOOL irq;
	uint loaded;

	irq = OSDisableInterrupts();
	loaded = piGetLoadedFlags(0);
	if(readyFiles & FILE_FLAG_MODELS_tab && !(loaded & FILE_FLAG_MODELS_tab)) {
		piMergeIndex(MODELS_TAB, FILE_MODELS_tab,
            FILE_MODELS_tab2, MODELS_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_MODELS_tab2 && !(loaded & FILE_FLAG_MODELS_tab2)) {
		piMergeIndex(MODELS_TAB, FILE_MODELS_tab,
            FILE_MODELS_tab2, MODELS_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_ANIM_TAB && !(loaded & FILE_FLAG_ANIM_TAB)) {
		piMergeIndex(ANIM_TAB, FILE_ANIM_TAB,
            FILE_ANIM_TAB2, ANIM_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_ANIM_TAB2 && !(loaded & FILE_FLAG_ANIM_TAB2)) {
		piMergeIndex(ANIM_TAB, FILE_ANIM_TAB,
            FILE_ANIM_TAB2, ANIM_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_TEX0_tab && !(loaded & FILE_FLAG_TEX0_tab)) {
		piMergeIndex(TEX0_TAB, FILE_TEX0_tab,
            FILE_TEX0_tab2, TEX0_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_TEX0_tab2 && !(loaded & FILE_FLAG_TEX0_tab2)) {
		piMergeIndex(TEX0_TAB, FILE_TEX0_tab,
            FILE_TEX0_tab2, TEX0_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_TEX1_tab && !(loaded & FILE_FLAG_TEX1_tab)) {
		piMergeIndex(TEX1_TAB, FILE_TEX1_tab,
            FILE_TEX1_tab2, TEX1_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_TEX1_tab2 && !(loaded & FILE_FLAG_TEX1_tab2)) {
		piMergeIndex(TEX1_TAB, FILE_TEX1_tab,
            FILE_TEX1_tab2, TEX1_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_BLOCKS_tab && !(loaded & FILE_FLAG_BLOCKS_tab)) {
		piMergeIndex(BLOCKS_TAB, FILE_BLOCKS_tab,
            FILE_BLOCKS_tab2, BLOCKS_TAB_SIZE);
	}
	if(readyFiles & FILE_FLAG_BLOCKS_tab2 && !(loaded & FILE_FLAG_BLOCKS_tab2)) {
		piMergeIndex(BLOCKS_TAB, FILE_BLOCKS_tab,
            FILE_BLOCKS_tab2, BLOCKS_TAB_SIZE);
	}
    //might be wrong vars here
	readyFiles = loaded;
	loadingFiles ^= loadedFiles;
	loadedFiles = 0;
	OSRestoreInterrupts(irq);
}

uint piGetLoadedFlags(int param_1) {
    BOOL level;
	uint dVar1;
	level = OSDisableInterrupts();
	dVar1 = loadingFiles;
	OSRestoreInterrupts(level);
	return dVar1;
}

void piDVDCallbackModtab(long stat, DVDFileInfo *file) {
	BOOL level;

    //this is the only one that disables interrupts...
	level = OSDisableInterrupts();
	if(stat == -1) {
        STUBBED_PRINTF("piDVDCallbackModtab  error on MODTAB\n");
		DVDClose(file);
		mmFree(file);
	} else {
		DVDClose(file);
		mmFree(file);
        STUBBED_PRINTF("\n\n\npiDVDCallbackModtab  %x\n\n\n", loadingFiles);
        //extra load of loadingFiles here...
		if(loadingFiles & FILE_FLAG_MODELS_tab) {
            loadedFiles |= FILE_FLAG_MODELS_tab;
		} else if(loadingFiles & FILE_FLAG_MODELS_tab2) {
            loadedFiles |= FILE_FLAG_MODELS_tab2;
        }
	}
	OSRestoreInterrupts(level);
}

void piDVDCallbackAnimtab(long stat, DVDFileInfo *file) {
	if(stat == -1) {
        STUBBED_PRINTF("piDVDCallbackAnimtab  error on ANIMTAB\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        STUBBED_PRINTF("piDVDCallbackAnimtab %x\n", loadingFiles);
        if(loadingFiles & FILE_FLAG_ANIM_TAB) {
            loadedFiles |= FILE_FLAG_ANIM_TAB;
        } else if(loadingFiles & FILE_FLAG_ANIM_TAB2) {
            loadedFiles |= FILE_FLAG_ANIM_TAB2;
        }
    }
}

void piDVDCallbackModbin(long stat, DVDFileInfo *file) {
	if(stat == -1) {
        STUBBED_PRINTF("piDVDCallbackModbin  error on MODBIN\n");
		DVDClose(file);
		mmFree(file);
    } else {
        DVDClose(file);
        mmFree(file);
        //@bug wrong message
        STUBBED_PRINTF("piDVDCallbackModtab %x\n", loadingFiles);
        if(loadingFiles & FILE_FLAG_MODELS_bin) {
            loadedFiles |= FILE_FLAG_MODELS_bin;
        } else if(loadingFiles & FILE_FLAG_MODELS_bin2) {
            loadedFiles |= FILE_FLAG_MODELS_bin2;
        }
    }
}

void piDVDCallbackAnimbin(long stat, DVDFileInfo *file) {
	if(stat == -1) {
        STUBBED_PRINTF("piDVDCallbackAnimbin  error on ANIMBIN\n");
		DVDClose(file);
		mmFree(file);
    } else {
        DVDClose(file);
        mmFree(file);
        STUBBED_PRINTF("piDVDCallbackAnim %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_ANIM_BIN) {
            loadingFiles |= FILE_FLAG_ANIM_BIN;
        }
        else if(loadedFiles & FILE_FLAG_ANIM_BIN2) {
            loadingFiles |= FILE_FLAG_ANIM_BIN2;
        }
    }
}

void piDVDCallbackTex2bin(long stat, DVDFileInfo *file) {
	if(stat == -1) {
        STUBBED_PRINTF("piDVDCallbackTex2bin  error on TEX2BIN\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        STUBBED_PRINTF("piDVDCallbackTEXTURES %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_TEX0_bin) {
            loadingFiles |= FILE_FLAG_TEX0_bin;
        }
        else if(loadedFiles & FILE_FLAG_TEX0_bin2) {
            loadingFiles |= FILE_FLAG_TEX0_bin2;
        }
    }
}

void piDvdCallbacktex2tab36(long stat, DVDFileInfo *file) {
	int idx;
	u8 *data;
    int *dataInt;
	int cksum;
	int realsum;
	int tmpsum;
    int val;

	val = 0;
	idx = 0;
	cksum = 0;
	tmpsum = 0;
	if(stat == -1) {
		OSReport("piDVDCallbackTextab  error on TEX2TAB\n");
		DVDClose(file);
		mmFree(file);
        return;
	}
    OSReport("piDVDCallbacktex2tab36 %x\n", loadedFiles);
    data = (u8 *)dataFilePtrs[FILE_TEX0_tab];
    dataInt = (int *)(dataFilePtrs[FILE_TEX0_tab]);
    while(val != -1) {
        val = dataInt[idx++];
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
    }
    cksum = dataInt[idx++];
    while(cksum == 0) cksum = dataInt[idx++];
    realsum = tmpsum;
    OSReport("piDVDCallbackTex2tab36 ------ CHECKSUM  0x%x  REALSUM 0x%x\n",
        cksum, realsum);
    if(cksum != realsum) {
        OSReport("piDVDCallbackTex2tab36 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTex2tab36 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTex2tab36 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTex2tab36 ------ RE-READING\n");
        DVDReadAsyncPrio(file, dataFilePtrs[FILE_TEX0_tab],
            dataFileSizes[FILE_TEX0_tab], 0,
            piDvdCallbacktex2tab36, 2);
        return;
    }
    DVDClose(file);
    mmFree(file);
    if((loadedFiles & FILE_FLAG_TEX0_tab) != 0) {
        loadingFiles |= FILE_FLAG_TEX0_tab;
    }
}

void piDvdCallbacktex2tab78(long stat, DVDFileInfo *file) {
	int idx;
	u8 *data;
    int *dataInt;
	int cksum;
	int realsum;
	int tmpsum;
    int val;

	val = 0;
	idx = 0;
	cksum = 0;
	tmpsum = 0;
	if(stat == -1) {
		OSReport("piDVDCallbackTextab  error on TEX2TAB\n");
		DVDClose(file);
		mmFree(file);
        return;
	}
    OSReport("piDVDCallbacktex2tab78 %x\n", loadedFiles);
    data = (u8 *)dataFilePtrs[FILE_TEX0_tab2];
    dataInt = (int *)(dataFilePtrs[FILE_TEX0_tab2]);
    while(val != -1) {
        val = dataInt[idx++];
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
    }
    cksum = dataInt[idx++];
    while(cksum == 0) cksum = dataInt[idx++];
    realsum = tmpsum;
    OSReport("piDVDCallbacktex2tab78 ------ CHECKSUM  0x%x  REALSUM 0x%x\n",
        cksum, realsum);
    if(cksum != realsum) {
        OSReport("piDVDCallbacktex2tab78 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbacktex2tab78 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbacktex2tab78 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbacktex2tab78 ------ RE-READING\n");
        DVDReadAsyncPrio(file, dataFilePtrs[FILE_TEX0_tab2],
            dataFileSizes[FILE_TEX0_tab2], 0,
            piDvdCallbacktex2tab78, 2);
        return;
    }
    DVDClose(file);
    mmFree(file);
    if((loadedFiles & FILE_FLAG_TEX0_tab2) != 0) {
        loadingFiles |= FILE_FLAG_TEX0_tab2;
    }
}

void piDVDCallbackTexbin(long stat, DVDFileInfo *file) {
	if(stat == -1) {
		OSReport("piDVDCallbackTexbin  error on TEXBIN\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        OSReport("piDVDCallbacktexbin %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_TEX1_bin) {
            loadingFiles |= FILE_FLAG_TEX1_bin;
        }
        else if(loadedFiles & FILE_FLAG_TEX1_bin2) {
            loadingFiles |= FILE_FLAG_TEX1_bin2;
        }
    }
}

void piDVDCallbackTex2tab33(long stat, DVDFileInfo *file) {
	int idx;
	u8 *data;
    int *dataInt;
	int cksum;
	int realsum;
	int tmpsum;
    int val;

	val = 0;
	idx = 0;
	cksum = 0;
	tmpsum = 0;
	if(stat == -1) {
		OSReport("piDVDCallbackTextab  error on TEXTAB\n");
		DVDClose(file);
		mmFree(file);
        return;
	}
    OSReport("piDVDCallbacktextab33 %x\n", loadedFiles);
    data = (u8 *)dataFilePtrs[FILE_TEX1_tab];
    dataInt = (int *)(dataFilePtrs[FILE_TEX1_tab]);
    while(val != -1) {
        val = dataInt[idx++];
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
    }
    cksum = dataInt[idx++];
    while(cksum == 0) cksum = dataInt[idx++];
    realsum = tmpsum;
    OSReport("piDVDCallbackTextab33 ------ CHECKSUM  0x%x  REALSUM 0x%x\n",
        cksum, realsum);
    if(cksum != realsum) {
        //XXX different message from above
        OSReport("piDVDCallbackTex2tab33 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTex2tab33 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTex2tab33 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTex2tab33 ------ RE-READING\n");
        DVDReadAsyncPrio(file, dataFilePtrs[FILE_TEX1_tab],
            dataFileSizes[FILE_TEX1_tab], 0,
            piDVDCallbackTex2tab33, 2);
        return;
    }
    DVDClose(file);
    mmFree(file);
    if((loadedFiles & FILE_FLAG_TEX1_tab) != 0) {
        loadingFiles |= FILE_FLAG_TEX1_tab;
    }
}

void piDVDCallbackTextab76(long stat, DVDFileInfo *file) {
	int idx;
	u8 *data;
    int *dataInt;
	int cksum;
	int realsum;
	int tmpsum;
    int val;

	val = 0;
	idx = 0;
	cksum = 0;
	tmpsum = 0;
	if(stat == -1) {
		OSReport("piDVDCallbackTextab  error on TEX2TAB\n");
		DVDClose(file);
		mmFree(file);
        return;
	}
    OSReport("piDVDCallbackTextab76 %x\n", loadedFiles);
    data = (u8 *)dataFilePtrs[FILE_TEX1_tab2];
    dataInt = (int *)(dataFilePtrs[FILE_TEX1_tab2]);
    while(val != -1) {
        val = dataInt[idx++];
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
        tmpsum += *(data++);
    }
    cksum = dataInt[idx++];
    while(cksum == 0) cksum = dataInt[idx++];
    realsum = tmpsum;
    OSReport("piDVDCallbackTextab76 ------ CHECKSUM  0x%x  REALSUM 0x%x\n",
        cksum, realsum);
    if(cksum != realsum) {
        OSReport("piDVDCallbackTextab76 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTextab76 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTextab76 ------ CHECKSUM IS INCORRECT   "
            "0x%x  REALSUM 0x%x\n", cksum, realsum);
        OSReport("piDVDCallbackTextab76 ------ RE-READING\n");
        DVDReadAsyncPrio(file, dataFilePtrs[FILE_TEX1_tab2],
            dataFileSizes[FILE_TEX1_tab2], 0,
            piDVDCallbackTextab76, 2);
        return;
    }
    DVDClose(file);
    mmFree(file);
    if((loadedFiles & FILE_FLAG_TEX1_tab2) != 0) {
        loadingFiles |= FILE_FLAG_TEX1_tab2;
    }
}

void piDVDCallbackBlockbin(long stat, DVDFileInfo *file) {
    //strangely "block" not "blocks" unlike elsewhere
	if(stat == -1) {
		OSReport("piDVDCallbackBlockbin  error on BLOCKBIN\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        OSReport("piDVDCallbackblockbin %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_BLOCKS_bin) {
            loadingFiles |= FILE_FLAG_BLOCKS_bin;
        } else if(loadedFiles & FILE_FLAG_BLOCKS_bin2) {
            loadingFiles |= FILE_FLAG_BLOCKS_bin2;
        }
    }
}

void piDVDCallbackBlockstab(long stat, DVDFileInfo *file) {
	if(stat == -1) {
		OSReport("piDVDCallbackBlockstab  error on BLOCKSTAB\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        OSReport("piDVDCallbackblocktab %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_BLOCKS_tab) {
            loadingFiles |= FILE_FLAG_BLOCKS_tab;
        } else if(loadedFiles & FILE_FLAG_BLOCKS_tab2) {
            loadingFiles |= FILE_FLAG_BLOCKS_tab2;
        }
    }
}

void piDVDCallbackAnimCurve(long stat, DVDFileInfo *file) {
	if(stat == -1) {
        //@bug typo'd name
		OSReport("piDVDCallbackAnimCurveb  error on AnimCurve\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        OSReport("piDVDCallbackAnimCurve %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_ANIMCURV_bin) {
            loadingFiles |= FILE_FLAG_ANIMCURV_bin;
        }
    }
}

void piDVDCallbackAnimCurveTab(long stat, DVDFileInfo *file) {
	if(stat == -1) {
		OSReport("piDVDCallbackAnimCurveTab  error on AnimCurve\n");
		DVDClose(file);
		mmFree(file);
	} else {
        DVDClose(file);
        mmFree(file);
        OSReport("piDVDCallbackAnimCurveTab %x\n", loadedFiles);
        if(loadedFiles & FILE_FLAG_ANIMCURV_tab) {
            loadingFiles |= FILE_FLAG_ANIMCURV_tab;
        }
    }
}
