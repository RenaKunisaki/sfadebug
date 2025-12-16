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

#define SIG_UNCOMPRESSED_FILE 0xe0e0e0e0
#define SIG_LZO_COMPRESSED_FILE 0xf0f0f0f0
typedef struct {
    /* 0x00 */ int sig; //signature
    /* 0x04 */ int len;
    /* 0x08 */ int offset;
    /* 0x0C */ int compLen;
    /* 0x10 */ int unk10;
    /* 0x14 */ int unk14;
} DbMapsBinEntry;

enum {
    TexGetMipmapOp_getSize = 0,
    TexGetMipmapOp_getNext = 1, //unsure
    TexGetMipmapOp_copy = 2,
} TexGetMipmapOp;

int lzoDecompress(void *src,int compLen,void *dest,int *outLen);

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

void *dataFilePtrs[NUM_FILES];


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

	if(!(dataFilePtrs[FILE_TEX1_bin] || dataFilePtrs[FILE_TEX1_bin_4B])) return;
    tex1tabA = dataFilePtrs[FILE_TEX1_tab];
    tex1tabB = dataFilePtrs[FILE_TEX1_tab_4C];

    if(offset & 0x80000000) fileIdx = FILE_TEX1_bin_4B;
    else if(offset & 0x40000000) fileIdx = FILE_TEX1_bin;
    else if(tex1tabA) fileIdx = FILE_TEX1_bin;
    else if(tex1tabB) fileIdx = FILE_TEX1_bin_4B;
    //else fileIdx is undefined. not sure if this is a bug,
    //or something that should never be able to happen.

    offs = offset & 0xffffff;
    if((doWhat == TexGetMipmapOp_getNext) && dest) {
        //unsure what this is actually doing
        iVar1 = (int)(*(int*)dataFilePtrs[fileIdx] + offs * 2 +
            *(int *)((int)dest + size * 4));
        buf2 = (int*)(iVar1)+1;
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
