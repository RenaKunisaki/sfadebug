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

#define RCP_GX_FIFO_SIZE 0x10000

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
u16 peToken_80398b54;
bool bNeedSetVerticalRegs;
bool rcpBreakptVal_80398b51;
bool viVal_80398b52;
int frameCountThisStep;

extern Mtx44 projMtx_80382d00;

u16 getPeToken(void);
undefined* setViIrqCallback(void(*cb)(void));
void setVerticalRegsFn_80016018(int param_1);
void viFn_80015ea8(void);

void rcpThreadMain(void) {
	RcpQueueItem item;
    int dummy;
	do {
		OSSleepThread(&rcpThreadQueue);
		rcpQueueRemoveFn_8009fcfc(&item, &RcpQueue_8036bcfc);
	} while(true);
}

void rcpQueueClear(RcpQueue *queue) { //8009fc38
    queue->queue_top = 10;
}

void videoThread_8009fb1c(void) { // 8009fb1c
	u16 token;
    int dummy;

	token = getPeToken();
	if(token == (u16)(peToken_80398b54 + 1)) {
		peToken_80398b54 = token;
		pCurFrameBuffer = (pCurFrameBuffer == pFrameBuffer_80398b74) ?
            pFrameBuffer_80398b70 : pFrameBuffer_80398b74;
		VISetNextFrameBuffer(pCurFrameBuffer);
		if(bNeedSetVerticalRegs) {
			setVerticalRegsFn_80016018(0);
			bNeedSetVerticalRegs = 0;
		}
		viFn_80015ea8();
		viVal_80398b52 = 1;
		frameCountThisStep = 0;
	}
	frameCountThisStep += 1;
}

void rcpThreadFn_8009fcb8(void) {
	if((rcpBreakptVal_80398b51 != 0) && (viVal_80398b52)) {
		rcpBreakptFn_8009fb08();
		rcpBreakptVal_80398b51 = 0;
		viVal_80398b52 = false;
	}
}

void rcpGxBreakptHandler() {
    //TODO
}

void videoInitFn_8009e5f0(undefined *unused, int bIsProgScan) {
	uint ii;
    uint tvMode;
	Mtx MStack_64;
	GXColor tevColor2;

	rcpGxFifo = mmAlloc(RCP_GX_FIFO_SIZE, ALLOC_TAG_SHAD_COL,
        (volatile u32) "rcp_dolphin:GfxFifo");
	DCInvalidateRange(rcpGxFifo, RCP_GX_FIFO_SIZE);
	gxInitVal = GXInit(rcpGxFifo, RCP_GX_FIFO_SIZE);

    VIConfigure(curTvParams);
	GXSetViewport(0, 0, curTvParams->fbWidth,
        curTvParams->xfbHeight, 0, 1);
	GXSetFieldMode(curTvParams->field_rendering,
	    curTvParams->xfbHeight <
        curTvParams->viHeight);
	GXSetScissor(0, 0, curTvParams->fbWidth,
        curTvParams->efbHeight);
	GXSetDispCopySrc(0, 0, curTvParams->fbWidth,
        curTvParams->efbHeight);
	GXSetDispCopyDst(curTvParams->fbWidth,curTvParams->xfbHeight);
    GXSetDispCopyYScale((float)curTvParams->xfbHeight /
        (float)curTvParams->efbHeight);

    if(bIsProgScan) {
        GXSetCopyFilter(curTvParams->aa, curTvParams->sample_pattern,
		    false, curTvParams->vfilter);
	} else {
		GXSetCopyFilter(curTvParams->aa, curTvParams->sample_pattern,
		    true, curTvParams->vfilter);
	}
	if(curTvParams->aa) {
		GXSetPixelFmt(GX_PF_RGB565_Z16,GX_ZC_LINEAR);
		GXSetDither(true);
	} else {
        GXSetPixelFmt(GX_PF_RGB8_Z24,GX_ZC_LINEAR);
		GXSetDither(false);
	}
	FUN_80030240(0);
	pCurFrameBuffer = pFrameBuffer_80398b74;
	pFrameBuffer_80398b48 = pFrameBuffer_80398b70;
	rcpQueueClear(&RcpQueue_8036bcfc);
	rcpQueueClear(&RcpQueue_8036bc80);
	OSInitThreadQueue(&rcpThreadQueue);
	OSCreateThread(&rcpThread, rcpThreadMain, NULL, &stopwatchCpu, 0x1000, 0xe, 1);
	OSResumeThread(&rcpThread);
	setViIrqCallback(videoThread_8009fb1c);
	set_viIrqCb_80398360(rcpThreadFn_8009fcb8);
	GXSetBreakpointHandler(rcpGxBreakptHandler);
	GXSetDispCopyGamma(0);
	viFn_80015ea8();
	waitNextFrame();
    tvMode = curTvParams->viTVmode & 1;
	if(tvMode) { waitNextFrame(); }
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_PNMTXIDX, 1);
	GXSetVtxDesc(GX_VA_POS, 1);
	GXSetVtxDesc(GX_VA_CLR0, 1);
	GXSetVtxDesc(GX_VA_TEX0, 1);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS, GX_CLR_RGBA,GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4, 7);
    GXSetVtxAttrFmt(GX_VTXFMT1,GX_VA_POS, GX_CLR_RGBA,GX_RGBA4, 2);
    GXSetVtxAttrFmt(GX_VTXFMT1,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT1,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,   0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_POS, GX_CLR_RGBA,GX_F32,   0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,   0);
    GXSetVtxAttrFmt(GX_VTXFMT2,GX_VA_TEX1,GX_CLR_RGBA,GX_F32,   0);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_POS, GX_CLR_RGBA,GX_RGBA4, 8);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_NBT, GX_CLR_RGBA,GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT3,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT4,GX_VA_POS, GX_CLR_RGBA,GX_F32,   0);
    GXSetVtxAttrFmt(GX_VTXFMT4,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4, 7);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_POS, GX_CLR_RGBA,GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4, 8);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4, 8);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4, 8);
    GXSetVtxAttrFmt(GX_VTXFMT5,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4, 8);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_POS, GX_CLR_RGBA,GX_RGBA4, 8);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_NRM, GX_CLR_RGB, GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4,10);
    GXSetVtxAttrFmt(GX_VTXFMT6,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4,10);
	DAT_80398b7c = 0;
	GXSetCullMode(DAT_80398b7c);
	GXSetCopyClear(DAT_80396de4, 0xffffff);
	GXSetBlendMode(0, 1, 0, 5);
	GXSetNumChans(1);
	GXSetChanCtrl(0, 0, 0, 1, 0, 0, 2);
	gxZCompareEnable = true;
	gxZCompareFunc = GX_LEQUAL;
	gxZUpdateEnable = true;
	GXSetZMode(gxZCompareEnable, gxZCompareFunc, gxZUpdateEnable);
	GXSetZCompLoc(1);
	MtxIdentity(&MStack_64);
	GXLoadPosMtxImm(MStack_64, 0);
	GXLoadTexMtxImm(MStack_64, 0x1e, 0);
	GXLoadTexMtxImm(MStack_64, 0x21, 0);
	GXSetCurrentMtx(0);
	OSInitStopwatch(&stopwatchCpu, "CPU");
	OSInitStopwatch(&stopwatchGp, "GP");
	OSInitStopwatch(&stopwatchFrame, "Frame");
	frameTime = 0.0f;
	rcpBreakpointTime = 0.0f;
	FLOAT_80398b68 = 0.0f;
	MTXOrtho(projMtx_80382d00, 0.0f, 480.0f, 0.0f, 640.0f, 1.0f, 100.0f);
	for(ii = 0; ii < RSP_NUM_SEGMENTS; ii++) {
		rspSegmentBase[ii] = (void *)0x80000000;
	}
	tevColor2.r = 0xff;
	tevColor2.g = 0x00;
	tevColor2.b = 0x00;
	tevColor2.a = 0xff;
	GXSetTevColor(GX_TEVREG2, tevColor2);
}

void nop_8009FA00() {
}

