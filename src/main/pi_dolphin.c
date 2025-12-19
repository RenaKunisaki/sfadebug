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
		DVDOpen(dataFileNames[fileNo], &file);
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

    offs = (offset & 0xfffffff);
    entry = (ModelsBinEntry *)((uint)dataFilePtrs[fileIdx] + offs);
    unk18 = &entry->unk18;
    *outNoAmap = unk18->noAmap;
    *outNAnimations = unk18 ->nAnimations;
    *outAnimCacheSize = unk18 ->animCacheSize;
    *outSize = entry->size;
}

void tex1GetMipmap(uint offset, uint mipIdx, uint *outSize,
undefined4 *outCompSize, int size, void *dest, int doWhat) {
    //doWhat: TexGetMipmapOp
	int iVar1;
	u32 compLen;
	int *buf2;
	ZlbHeader *buf;
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

    offs = offset & 0xffffff;
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
        buf2 = (int*)(
            (int)(*(int*)((int)dataFilePtrs[fileIdx]) + offs * 2 +
            ((int)dest + size * 4))
        )+1;
        offs = buf2[1];
        iVar1 = buf2[2];
        *outCompSize = iVar1;
        *outSize = offs;

    } else if((doWhat == TexGetMipmapOp_copy) && dest) {
        memcpy_src_dst_len(
            (void *)((int)dataFilePtrs[fileIdx] + offs * 2),
            dest, (size + 1) * 4);

    } else { //TexGetMipmapOp_getSize
        buf = (ZlbHeader *)((int)dataFilePtrs[fileIdx] + offs * 2);
        compLen = buf->compLen;
        *outSize = buf->decLen;
        if(!strncmp("DIR", (char *)buf, 3)) {
            *outCompSize = 0xffffffff;
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
