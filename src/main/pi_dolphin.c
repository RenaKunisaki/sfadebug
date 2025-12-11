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
#include <stddef.h>
#include "placeholder.h"

int lzoDecompress(void *src,int compLen,void *dest,int *outLen);

void *dataFilePtrs[NUM_FILES];

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

void piRomLoadSection(int id, void *dest) {
	int offset;
	DbMapsBinEntry *entry;
	int len;
    int outLen;
    int fmpc1;
    int fmpc2;
    int fmpc3;
    int fmpc4;

	if(!dataFilePtrs[FILE_MAPS_bin]) {
		OSPanic("pi_dolphin.c", 1084,
            "piRomLoadSection(): DB_MAPS Bin Not Loaded");
	}
	entry = (DbMapsBinEntry *)((int)dataFilePtrs[FILE_MAPS_bin] + id);
	if(entry->sig == SIG_UNCOMPRESSED_FILE) {
        /*
        r31 = entry; //dataFilePtrs[FILE_MAPS_bin] + id;
        r4  = mapsBin; //dataFilePtrs[FILE_MAPS_bin];
        r0  = offset; //r31[8];
        r29 = mapsBin - (offset + entry + 0x18);
        r3  = mapsBin + r29;
        r4  = dest;
        r5  = entry->len;
        */
		memcpy_src_dst_len(
            (void *)(
                (int)dataFilePtrs[FILE_MAPS_bin] +
                entry->offset +
                (int)entry +
                sizeof(DbMapsBinEntry)
            ),
            dest,entry->len);
	} else if(entry->sig == SIG_LZO_COMPRESSED_FILE) { //LZO compressed file.
		offset = (entry->offset + 0x28) + (int)entry - (int)dataFilePtrs[FILE_MAPS_bin];
		PPCMtmmcr1(0x7fc00000);
		PPCMtmmcr0(0x42);

        outLen = lzoDecompress(
            (void *)((int)dataFilePtrs[FILE_MAPS_bin] + offset),
            entry->compLen, dest, &len);

        PPCMtmmcr0(0);
		PPCMtmmcr1(0);
        fmpc1 = PPCMfpmc1() * 0.001f;
        fmpc2 = PPCMfpmc2() * 0.001f;
        fmpc3 = PPCMfpmc3() * 0.001f;
        fmpc4 = PPCMfpmc4() * 0.001f;
        //probably some stubbed prints here
		PPCMtpmc1(0);
		PPCMtpmc2(0);
		PPCMtpmc3(0);
		PPCMtpmc4(0);

		DCStoreRange(dest, len);
	}
	return;
}
