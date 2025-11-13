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

void *rcpGxFifo; //80398b40;
GXFifoObj *gxInitVal; //80398b44
GXRenderModeObj *curTvParams; //80398b78
void *pCurFrameBuffer; //80398B4C
void *pFrameBuffer_80398b70;
void *pFrameBuffer_80398b74;
void *pFrameBuffer_80398b48;
RcpQueue RcpQueue_8036bc80;
RcpQueue RcpQueue_8036bcfc;
OSThreadQueue rcpThreadQueue; //80398B58
OSThread rcpThread; //8036BD78
struct OSStopwatch stopwatchCpu; //8036cfa8
struct OSStopwatch stopwatchGp;
struct OSStopwatch stopwatchFrame;
int DAT_80398b7c;
GXColor DAT_80396de4;
bool gxZCompareEnable;
int gxZCompareFunc;
bool gxZUpdateEnable;
float frameTime;
float rcpBreakpointTime;
float FLOAT_80398b68;
Mtx44 projMtx_80382d00;
void *rspSegmentBase[RSP_NUM_SEGMENTS];

void rcpThreadMain(void) {
	RcpQueueItem item;
    int dummy;
	do {
		OSSleepThread(&rcpThreadQueue);
		rcpQueueRemoveFn_8009fcfc(&item, &RcpQueue_8036bcfc);
	} while(true);
}

void *videoThread_8009fb1c; //8009fb1c TODO should be a function
void *rcpThreadFn_8009fc00; //TODO should be a function
void *rcpGxBreakptHandler; //TODO should be a function

void videoInitFn_8009e5f0(undefined *unused, int bIsProgScan) {
	uint uVar1;
	double in_register_00004008;
	double in_register_00004018;
	double in_register_00004028;
	GXColor local_70;
	GXColor local_6c;
	undefined4 local_68;
	Mtx MStack_64;
	undefined4 uStack_30;
	uint efbHeight;
	undefined4 uStack_28;
	uint xfbHeight2;
	undefined4 uStack_20;
	uint xfbHeight;
	undefined4 uStack_18;
	uint fbWidth;

	rcpGxFifo = mmAlloc(
	    0x10000, ALLOC_TAG_SHAD_COL, (volatile u32) "rcp_dolphin:GfxFifo");
	DCInvalidateRange(rcpGxFifo, 0x10000);
	gxInitVal = GXInit(rcpGxFifo, 0x10000);
	VIConfigure(curTvParams);
	fbWidth = (uint)curTvParams->fbWidth;
	uStack_18 = 0x43300000;
	xfbHeight = (uint)curTvParams->xfbHeight;
	uStack_20 = 0x43300000;
	GXSetViewport_(0.0, 0.0, (double)fbWidth, (double)xfbHeight, 0.0, 1.0);
	GXSetFieldMode(curTvParams->field_rendering,
	    (uint)curTvParams->xfbHeight - (uint)curTvParams->viHeight >> 0x1f);
	GXSetScissor(
	    0, 0, (uint)curTvParams->fbWidth, (uint)curTvParams->efbHeight);
	GXSetDispCopySrc(
	    0, 0, (uint)curTvParams->fbWidth, (uint)curTvParams->efbHeight);
	GXSetDispCopyDst(curTvParams->fbWidth,curTvParams->xfbHeight);
	xfbHeight2 = (uint)curTvParams->xfbHeight;
	uStack_28 = 0x43300000;
	efbHeight = (uint)curTvParams->efbHeight;
	uStack_30 = 0x43300000;
	GXSetDispCopyYScale((double)((float)xfbHeight2 / (float)efbHeight));
	if(bIsProgScan == 0) {
		GXSetCopyFilter(curTvParams->aa, curTvParams->sample_pattern,
		    true, curTvParams->vfilter);
	} else {
		GXSetCopyFilter(curTvParams->aa, curTvParams->sample_pattern,
		    false, curTvParams->vfilter);
	}
	if(curTvParams->aa == 0) {
		GXSetPixelFmt(0, 0);
		GXSetDither(0);
	} else {
		GXSetPixelFmt(2, 0);
		GXSetDither(1);
	}
	FUN_80030240(0);
	pCurFrameBuffer = pFrameBuffer_80398b74;
	pFrameBuffer_80398b48 = pFrameBuffer_80398b70;
	rcpQueueClear(&RcpQueue_8036bc80);
	rcpQueueClear(&RcpQueue_8036bcfc);
	OSInitThreadQueue(&rcpThreadQueue);
	OSCreateThread((OSThread *)&rcpThread,
	    rcpThreadMain,
	    NULL,
	    &stopwatchCpu,
	    0x1000,
	    0xe,
	    1);
	OSResumeThread((OSThread *)&rcpThread);
	setViIrqCallback(videoThread_8009fb1c);
	set_viIrqCb_80398360(rcpThreadFn_8009fc00);
	GXSetBreakpointHandler(rcpGxBreakptHandler);
	GXSetDispCopyGamma(0);
	viFn_80015ea8();
	waitNextFrame();
	if((curTvParams->viTVmode & 1) != 0) { waitNextFrame(); }
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_PNMTXIDX, 1);
	GXSetVtxDesc(GX_VA_POS, 1);
	GXSetVtxDesc(GX_VA_CLR0, 1);
	GXSetVtxDesc(GX_VA_TEX0, 1);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,7);
    GXSetVtxAttrFmt(GX_VTXFMT1,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,2);
    GXSetVtxAttrFmt(GX_VTXFMT1,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
    GXSetVtxAttrFmt(GX_VTXFMT1,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_TEX1,GX_CLR_RGBA,GX_F32,0);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,8);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_NBT,GX_CLR_RGBA,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT4,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    GXSetVtxAttrFmt(GX_VTXFMT4,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
    GXSetVtxAttrFmt(GX_VTXFMT4,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,7);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,8);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4,8);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4,8);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,8);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_NRM,GX_CLR_RGB,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA4,0);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4,10);
	DAT_80398b7c = 0;
	GXSetCullMode(GX_CULL_NONE);
	local_6c = DAT_80396de4;
	GXSetCopyClear(local_6c, 0xffffff);
	GXSetBlendMode(0, 1, 0, 5);
	GXSetNumChans(1);
	GXSetChanCtrl(0, 0, 0, 1, 0, 0, 2);
	gxZCompareEnable = 1;
	gxZCompareFunc = 3;
	gxZUpdateEnable = 1;
	GXSetZMode(true, GX_LEQUAL, true);
	GXSetZCompLoc(1);
	MtxIdentity(&MStack_64);
	GXLoadPosMtxImm(MStack_64, 0);
	GXLoadTexMtxImm(MStack_64, 0x1e, 0);
	GXLoadTexMtxImm(MStack_64, 0x21, 0);
	GXSetCurrentMtx(0);
	OSInitStopwatch(&stopwatchCpu, "CPU");
	OSInitStopwatch(&stopwatchGp, "GP");
	OSInitStopwatch(&stopwatchFrame, "Frame");
	frameTime = 0.0;
	rcpBreakpointTime = 0.0;
	FLOAT_80398b68 = 0.0;
	C_MTXOrtho(in_register_00004008,
	    0.0,
	    in_register_00004018,
	    480.0,
	    in_register_00004028,
	    0.0,
	    &projMtx_80382d00);
	for(uVar1 = 0; uVar1 < 0x10; uVar1++) {
		rspSegmentBase[uVar1] = (void *)0x80000000;
	}
	local_68 = 0xff0000ff;
	local_70.r = 0xff;
	local_70.g = 0;
	local_70.b = 0;
	local_70.a = 0xff;
	GXSetTevColor(3, local_70);
	return;
}
