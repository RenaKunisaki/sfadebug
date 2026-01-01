#include "dolphin.h"
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
#include "sys/files.h"
#include "sys/compress.h"
#include <stddef.h>
#include "placeholder.h"

enum {
    TexGetMipmapOp_getSize = 0,
    TexGetMipmapOp_getNext = 1, //unsure
    TexGetMipmapOp_copy = 2,
} TexGetMipmapOp;

//other files
int mergeTableFiles(uint *table,DataFileId32 file1,DataFileId32 file2,int count);
int lzoDecompress(void *src,int compLen,void *dest,int *outLen);

//this file
void initDataFiles(void);
void *loadDataFile(DataFileId32 file, char *memName);
int loadDataFileToBuf(DataFileId32 fileNo, void *buf);
u32 loadDataFileWithLength(DataFileId32 fileNo, void *dest,
    uint offset, u32 len);
void tex1GetMipmap(uint offset, uint mipIdx, uint *outSize,
    undefined4 *outCompSize, int size, void *dest, int doWhat);

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

    mergeTableFiles(MODELS_TAB, FILE_MODELS_tab,
        FILE_MODELS_tab2, MODELS_TAB_SIZE);
    mergeTableFiles(ANIM_TAB, FILE_ANIM_TAB,
        FILE_ANIM_TAB2, ANIM_TAB_SIZE);
    mergeTableFiles(TEX0_TAB, FILE_TEX0_tab,
        FILE_TEX0_tab2, TEX0_TAB_SIZE);
    mergeTableFiles(TEX1_TAB, FILE_TEX1_tab,
        FILE_TEX1_tab2, TEX1_TAB_SIZE);
    mergeTableFiles(BLOCKS_TAB, FILE_BLOCKS_tab,
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
	void *pvVar1;
	DVDFileInfo file;

	if(dataFilePtrs[fileNo]) return dataFilePtrs[fileNo];

    DVDOpen((char*)dataFileNames[fileNo], &file);
    dataFileSizes[fileNo] = (int)file.cb.callback;
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
        memcpy_src_dst_len(dataFilePtrs[fileNo],
            buf, dataFileSizes[fileNo]);
		DCStoreRange(buf, dataFileSizes[fileNo]);
		return dataFileSizes[fileNo];
	} else {
		DVDOpen((char*)dataFileNames[fileNo], &file);
		DCInvalidateRange(buf, (int)file.cb.callback);
		DVDReadPrio(&file, buf,
            (uint)file.cb.callback, 0, 2);
		DVDClose(&file);
        return (int)file.cb.callback;
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
 *  @return u32 Number of bytes read.
 */
u32 loadDataFileWithLength(DataFileId32 fileNo, void *buf,
uint offset, u32 len) {
	void *tmpBuf;
	DVDFileInfo file;

	if(!len) return 0;
	if(dataFilePtrs[fileNo]) {
        memcpy_src_dst_len(
		    (void *)((int)dataFilePtrs[fileNo] + offset), buf, len);
    } else {
		DVDOpen((char*)dataFileNames[fileNo], &file);
		if((((uint)buf & 0x1f) == 0) && ((len & 0x1f) == 0)) {
			DCInvalidateRange(buf, len);
			DVDReadPrio(&file, buf, len, offset, 2);
		} else {
			tmpBuf = mmAlloc(len + 0x1f & 0xffffffe0,
			    ALLOC_TAG_DVD_BUFFER,
			    (volatile u32)"temp dvd buffer");
			DCInvalidateRange(tmpBuf, len + 0x1f & 0xffffffe0);
			DVDReadPrio(&file, tmpBuf, len + 0x1f & 0xffffffe0, offset, 2);
			memcpy_src_dst_len(tmpBuf, buf, len);
			mmFree(tmpBuf);
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

void mapsBinGetRomlist(int offset, int *outNBlocks,
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

void loadModelsBin(uint offset, int *outNAnimations, uint *outAnimCacheSize,
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

void tex0GetMipmap(uint offset, uint mipIdx, uint *outSize,
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

void tex1GetMipmap(uint offset, uint mipIdx, uint *outSize,
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

MapDirIdx32 mapGetDirIdx(mapId32 map) {
	if((int)map >= NUM_MAP_DIRS) return 0;
	return mapIdXltnTbl[map];
}

int loadAndDecompressDataFile(DataFileId32 fileNo, void *dest, uint offset,
size_t length, uint *outSize, int index, u8 flags) {
	uint start;
	u32 loadFlags;
	char *sig;
	int *header;
	uint *tab2;
	uint *tab1;
	int ii;
	int local_8c;
	void *tmpBuf;
	DVDFileInfo file;
    uint **files;

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
                        while((tab2[ii++] & 0xffffff) <= start);
                        *outSize = tab2[ii-1] & 0xffffff;
                    } else if(start < (tab2[index - 1] & 0x00ffffff)) {
                        ii = 0;
                        while(start != (tab2[ii++] & 0xffffff));
                        while((tab2[ii++] & 0xffffff) <= start);
                        *outSize = (tab2[ii-1] & 0xffffff) - start;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0xffffff) <= start);
                        *outSize = (tab2[ii-1] & 0xffffff) - start;
                    }
                }
            } else if(offset & 0x10000000) {
                fileNo = FILE_MODELS_bin;
                if(outSize) {
                    start = tab1[index] & 0xffffff;
                    ii = 0;
                    if(start == 0) {
                        while((tab1[ii++] & 0xffffff) <= start);
                        *outSize = tab1[ii-1] & 0xffffff;
                    } else if(start < (tab1[index - 1] & 0x00ffffff)) {
                        ii = 0;
                        while(start != (tab1[ii++] & 0xffffff));
                        while((tab1[ii++] & 0xffffff) <= start);
                        *outSize = (tab1[ii-1] & 0xffffff) - start;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0xffffff) <= start);
                        *outSize = (tab1[ii-1] & 0xffffff) - start;
                    }
                }
            } else if(files[FILE_MODELS_tab]) {
                fileNo = FILE_MODELS_bin;
                if(outSize) {
                    start = tab1[index] & 0xffffff;
                    ii = 0;
                    if(start == 0) {
                        while((tab1[ii++] & 0xffffff) <= start);
                        *outSize = tab1[ii-1] & 0xffffff;
                    } else if(start < (tab1[index - 1] & 0xffffff)) {
                        ii = 0;
                        while(start != (tab1[ii++] & 0xffffff));
                        while((tab1[ii++] & 0xffffff) <= start);
                        *outSize = (tab1[ii-1] & 0xffffff) - start;
                    } else {
                        ii = index;
                        while((tab1[ii++] & 0xffffff) <= start);
                        *outSize = (tab1[ii-1] & 0xffffff) - start;
                    }
                }
            } else if(files[FILE_MODELS_tab2]) {
                fileNo = FILE_MODELS_bin2;
                if(outSize) {
                    start = tab2[index] & 0xffffff;
                    ii = 0;
                    if(start == 0) {
                        while((tab2[ii++] & 0xffffff) <= start);
                        *outSize = tab2[ii-1] & 0xffffff;
                    } else if((start < (tab2[index -1] & 0x00ffffff))) {
                        ii = 0;
                        while(start != (tab2[ii++] & 0xffffff));
                        while((tab2[ii++] & 0xffffff) <= start);
                        *outSize = (tab2[ii-1] & 0xffffff) - start;
                    } else {
                        ii = index;
                        while((tab2[ii++] & 0xffffff) <= start);
                        *outSize = (tab2[ii-1] & 0xffffff) - start;
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
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0xffffff);
                }
            } else if(offset & 0x10000000) {
                fileNo = FILE_ANIM_BIN;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0xffffff);
                }
            } else if(files[FILE_ANIM_TAB]) {
                fileNo = FILE_ANIM_BIN;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0xffffff);
                }
            } else if(files[FILE_ANIM_TAB2]) {
                fileNo = FILE_ANIM_BIN2;
                if(outSize) {
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0xffffff);
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
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0xffffff);
                }
            } else if(offset & 0x10000000) {
                fileNo = FILE_BLOCKS_bin;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0xffffff);
                }
            } else if(files[FILE_BLOCKS_tab]) {
                fileNo = FILE_BLOCKS_bin;
                if(outSize) {
                    *outSize = (tab1[index + 1] & 0x0fffffff) - (tab1[index] & 0xffffff);
                }
            } else if(files[FILE_BLOCKS_tab2]) {
                fileNo = FILE_BLOCKS_bin2;
                if(outSize) {
                    *outSize = (tab2[index + 1] & 0x0fffffff) - (tab2[index] & 0xffffff);
                }
            }
            offset &= 0x0fffffff;
            break;

        case FILE_TEX0_bin:
            loadFlags = getLoadedFileFlags();
            if(((loadFlags & 0x400) == 0) && ((loadFlags & 0x100) == 0)) {
                tab1 = (uint *)files[FILE_TEX0_tab];
            }
            if(((loadFlags & 0x800) == 0) && ((loadFlags & 0x200) == 0)) {
                tab2 = (uint *)files[FILE_TEX0_tab2];
            }
            if((tab2 == NULL) || ((TEX0_TAB[index] & 0x80000000) == 0)) {
                if((tab1 == NULL)
                    || ((TEX0_TAB[index] & 0x40000000) == 0)) {
                    if(tab2 == NULL) {
                        if((tab1)
                            && (fileNo = FILE_TEX0_bin, outSize)) {
                            offset = tab1[index] & 0x00ffffff;
                            if(offset == 0) {
                                ii = 0;
                                while((tab1[++ii] & 0x00ffffff) == 0);
                                *outSize = tab1[ii] & 0x00ffffff;
                            } else {
                                ii = index;
                                while((tab1[++ii] & 0x00ffffff) <= offset);
                                *outSize = (tab1[ii] & 0x00ffffff) - offset;
                            }
                        }
                    } else {
                        fileNo = FILE_TEX0_bin2;
                        if(outSize) {
                            offset = tab2[index] & 0x00ffffff;
                            if(offset == 0) {
                                ii = 0;
                                while((tab2[++ii] & 0x00ffffff) == 0);
                                *outSize = tab2[ii] & 0x00ffffff;
                            } else {
                                ii = index;
                                while((tab2[++ii] & 0x00ffffff) <= offset);
                                *outSize = (tab2[ii] & 0x00ffffff) - offset;
                            }
                        }
                    }
                } else {
                    fileNo = FILE_TEX0_bin;
                    if(outSize) {
                        offset = tab1[index] & 0x00ffffff;
                        if(offset == 0) {
                            ii = 0;
                            while((tab1[++ii] & 0x00ffffff) == 0);
                            *outSize = tab1[ii] & 0x00ffffff;
                        } else {
                            ii = index;
                            while((tab1[++ii] & 0x00ffffff) <= offset);
                            *outSize = (tab1[ii] & 0x00ffffff) - offset;
                        }
                    }
                }
            } else {
                fileNo = FILE_TEX0_bin2;
                if(outSize) {
                    offset = tab2[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab2[++ii] & 0x00ffffff) == 0);
                        *outSize = tab2[ii] & 0x00ffffff;
                    } else {
                        ii = index;
                        while((tab2[++ii] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii] & 0x00ffffff) - offset;
                    }
                }
            }
            offset &= 0x0fffffff;
            break;

        case FILE_TEX1_bin:
            loadFlags = getLoadedFileFlags();
            if(((loadFlags & 0x4000) == 0) && ((loadFlags & 0x1000) == 0)) {
                tab1 = (uint *)files[FILE_TEX1_tab];
            }
            if(((loadFlags & 0x8000) == 0) && ((loadFlags & 0x2000) == 0)) {
                tab2 = (uint *)files[FILE_TEX1_tab2];
            }
            if((tab2 == NULL) || ((TEX1_TAB[index] & 0x80000000) == 0)) {
                if((tab1 == NULL)
                    || ((TEX1_TAB[index] & 0x40000000) == 0)) {
                    if(tab2 == NULL) {
                        if((tab1)
                            && (fileNo = FILE_TEX1_bin, outSize)) {
                            offset = tab1[index] & 0x00ffffff;
                            if(offset == 0) {
                                ii = 0;
                                while((tab1[++ii] & 0x00ffffff) == 0);
                                *outSize = tab1[ii] & 0x00ffffff;
                            } else {
                                ii = index;
                                while((tab1[++ii] & 0x00ffffff) <= offset);
                                *outSize = (tab1[ii] & 0x00ffffff) - offset;
                            }
                        }
                    } else {
                        fileNo = FILE_TEX1_bin2;
                        if(outSize) {
                            offset = tab2[index] & 0x00ffffff;
                            if(offset == 0) {
                                ii = 0;
                                while((tab2[++ii] & 0x00ffffff) == 0);
                                *outSize = tab2[ii] & 0x00ffffff;
                            } else {
                                ii = index;
                                while((tab2[++ii] & 0x00ffffff) <= offset);
                                *outSize = (tab2[ii] & 0x00ffffff) - offset;
                            }
                        }
                    }
                } else {
                    fileNo = FILE_TEX1_bin;
                    if(outSize) {
                        offset = tab1[index] & 0x00ffffff;
                        if(offset == 0) {
                            ii = 0;
                            while((tab1[++ii] & 0x00ffffff) == 0);
                            *outSize = tab1[ii] & 0x00ffffff;
                        } else {
                            ii = index;
                            while((tab1[++ii] & 0x00ffffff) <= offset);
                            *outSize = (tab1[ii] & 0x00ffffff) - offset;
                        }
                    }
                }
            } else {
                fileNo = FILE_TEX1_bin2;
                if(outSize) {
                    offset = tab2[index] & 0x00ffffff;
                    if(offset == 0) {
                        ii = 0;
                        while((tab2[++ii] & 0x00ffffff) == 0);
                        *outSize = tab2[ii] & 0x00ffffff;
                    } else {
                        ii = index;
                        while((tab2[++ii] & 0x00ffffff) <= offset);
                        *outSize = (tab2[ii] & 0x00ffffff) - offset;
                    }
                }
            }
            offset &= 0x0fffffff;
            break;

        default: break;
    }
	if((flags & 1) == 0) { //decode the file
		if(files[fileNo] == NULL) {
			DVDOpen((char*)dataFileNames[fileNo], &file);
			if((((uint)dest & 0x1f) == 0) && ((length & 0x1f) == 0)) {
				DVDReadPrio(&file, dest, length, offset, 2);
			} else {
				tmpBuf = mmAlloc(length + 0x1f & 0xffffffe0,
				    ALLOC_TAG_DVD_BUFFER, (volatile u32)"temp dvd buffer");
				DVDReadPrio(&file, tmpBuf,
				    length + 0x1f & 0xffffffe0, offset, 2);
				memcpy_src_dst_len(tmpBuf, dest, length);
				mmFree(tmpBuf);
			}
			DCStoreRange(dest, length);
			DVDClose(&file);
		} else if((fileNo == FILE_MODELS_bin) || (fileNo == FILE_MODELS_bin2)) {
			header = (int *)((int)files[fileNo] + offset);
			if(*header == SIG_UNCOMPRESSED_FILE) {
				memcpy_src_dst_len((void *)((int)header + (int)files[fileNo] +
                    ((header[2] + 0x18) - (int)files[fileNo])),
				    dest, header[1]);
			} else if(*header == SIG_LZO_COMPRESSED_FILE) {
				lzoDecompress((void *)((int)header + (int)files[fileNo] +
                    ((header[2] + 0x28) - (int)files[fileNo])),
				    header[3] + -0x10, dest, &local_8c);
				DCStoreRange(dest, local_8c);
			}
		} else if((fileNo == FILE_TEX0_bin) || (fileNo == FILE_TEX0_bin2)) {
			lzoDecompress((void *)((int)files[fileNo] + (offset & 0x00ffffff) + 0x10),
			    *(int *)((int)files[fileNo] + (offset & 0x00ffffff) + 0xc),
			    dest, &local_8c);
			DCStoreRange(dest, local_8c);
		} else if((fileNo == FILE_TEX1_bin) || (fileNo == FILE_TEX1_bin2)) {
			start = offset & 0x00ffffff;
			sig = (char *)((int)files[fileNo] + start);
			if(!strncmp("DIR", sig, 3)) {
                return (int)files[fileNo] + start + 0x20;
            }
			if(!strncmp(sig, "LZO", 3)) {
				lzoDecompress(
				    (void *)((int)files[fileNo] + start + 0x10),
				    *(int *)(sig + 0xc), dest, &local_8c);
				DCStoreRange(dest, local_8c);
			}
		} else {
			memcpy_src_dst_len((void *)((int)files[fileNo] + offset),
                dest, length);
		}
	}
	return 0;
}

//mapLoadDataFile

int mapCheckCurBlocks(MapDirIdx32 map) {
	if(loadedFileMapIds[FILE_BLOCKS_bin ] == map - 1) return 0;
	if(loadedFileMapIds[FILE_BLOCKS_bin2] == map - 1) return 1;
	return -1;
}

int mergeTableFiles(uint *table, DataFileId32 fileNo1, DataFileId32 fileNo2,
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
                if(tbl2[ii] & 0x80000000u) table[ii] = tbl1[ii];
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
                BLOCKS_TAB[ii] = tbl2[ii] & 0xffffffU | 0x20000000;
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
                *(uint *)((int)table + ii * 4) = tbl2[ii] & 0xffffffU | 0x20000000;
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
                noTab1 = true;
            }
            if(tbl1) { STUBBED_OP(tbl1); }
            if(tbl2) { STUBBED_OP(tbl2); }
            if(noTab1) { STUBBED_OP(noTab1); }
		}
	}
	return 1;
}

#define FLIST_SIZE 20
#define piRomFreeLevel_flag_freeForCurMap 0x80000000
#define piRomFreeLevel_flag_freeForOtherMap 0x10000000

typedef struct {
    int fileNo;
    int mapNo;
} PiFreeListItem;
typedef struct {
    PiFreeListItem item[FLIST_SIZE];
} PiFreeList;
PiFreeList freeList;

int piRomFreeLevel(int map, uint flags) {
	int iList;
	PiFreeList localFreeList;

	localFreeList = freeList;
	//freeList.item[0].mapNo = map;

    for(iList = 0; iList < FLIST_SIZE; iList++) {
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
			mmFree(dataFilePtrs[localFreeList.item[iList].fileNo]);
			dataFilePtrs[localFreeList.item[iList].fileNo] = NULL;
			loadedFileMapIds[localFreeList.item[iList].fileNo] = -1;

            //if we freed a table file, rebuild the table
            switch(localFreeList.item[iList].fileNo) {
                case FILE_TEX1_tab: case FILE_TEX1_tab2:
                    mergeTableFiles(TEX1_TAB,
                        FILE_TEX1_tab, FILE_TEX1_tab2,
                        TEX1_TAB_SIZE);
                    break;

                case FILE_TEX0_tab: case FILE_TEX0_tab2:
                    mergeTableFiles(TEX0_TAB,
                        FILE_TEX0_tab, FILE_TEX0_tab2,
                        TEX0_TAB_SIZE);
                    break;

                case FILE_BLOCKS_tab: case FILE_BLOCKS_tab2:
                    mergeTableFiles(BLOCKS_TAB,
                        FILE_BLOCKS_tab, FILE_BLOCKS_tab2,
                        BLOCKS_TAB_SIZE);
                    break;

                case FILE_MODELS_tab: case FILE_MODELS_tab2:
                    mergeTableFiles(MODELS_TAB,
                        FILE_MODELS_tab, FILE_MODELS_tab2,
                        MODELS_TAB_SIZE);
                    break;

                case FILE_ANIM_TAB: case FILE_ANIM_TAB2:
                    mergeTableFiles(ANIM_TAB,
                        FILE_ANIM_TAB, FILE_ANIM_TAB2,
                        ANIM_TAB_SIZE);
                    break;
            }
		}
		if(iList >= FLIST_SIZE) {
			OSPanic("pi_dolphin.c", 3549,
			    "piRomFreeLevel(): flist array overflow");
		}
	}
	return 1;
}
