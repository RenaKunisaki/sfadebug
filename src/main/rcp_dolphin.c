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

extern Mtx44 projMtx_80382d00;

RcpQueue RcpQueue_8036bc80; //8036bc80
RcpQueue RcpQueue_8036bcfc; //8036bcfc
OSThread rcpThread; //8036bd78
struct OSStopwatch stopwatchCpu; //8036cfa8
struct OSStopwatch stopwatchGp; //8036cfe0
struct OSStopwatch stopwatchFrame; //8036d018

bool bNeedSetVerticalRegs; //80396de0
GXColor DAT_80396de4; //80396de4
RSPState *RSP_pState; //80396e28

void *rcpGxFifo; //80398b40
GXFifoObj *gxInitVal; //80398b44
void *pFrameBuffer_80398b48; //80398b48
void *pCurFrameBuffer; //80398b4c
bool gxBreakPtFlag_80398b50; //80398b50
bool rcpBreakptVal_80398b51; //80398b51
bool viVal_80398b52; //80398b52
u16 peToken_80398b54; //80398b54
OSThreadQueue rcpThreadQueue; //80398b58
float frameTime; //80398b60
float rcpBreakpointTime; //80398b64
float FLOAT_80398b68; //80398b68
int frameCountThisStep; //80398b6c
void *pFrameBuffer_80398b70; //80398b70
void *pFrameBuffer_80398b74; //80398b74
GXRenderModeObj *curTvParams; //80398b78
int DAT_80398b7c; //80398b7c
bool gxZUpdateEnable; //80398b80
int gxZCompareFunc; //80398b84
bool gxZCompareEnable; //80398b88

//declarations for other files
u16 getPeToken(void);
undefined* setViIrqCallback(void(*cb)(void));
void setVerticalRegsFn_80016018(int param_1);
void viFn_80015ea8(void);
float u64ToFloat(u64);

//unsure where these belong in this file
bool rcpQueueIsEmpty(RcpQueue *queue);

//declarations for this file
void videoInitFn_8009e5f0(undefined *unused, int bIsProgScan);
//rspFn_8009ed78
void rcpScreenWriteFn8009f0fc(Gfx_ **gfx, Texture *texture, uint x, int y,
    undefined4 param_5, int frameNo, int alpha, uint flags);
//rcpScreenWriteFn_8009f16c
void rcpScreenWrite(Gfx_ **gfx,Texture *texture,uint x,int y,
	uint blkStart,int blkEnd,int frameNo,int alpha,uint flags);
void nop_8009FA00();
void rcpGxBreakptHandler();
void rcpBreakptFn_8009fa94(void);
void videoThread_8009fb1c(void);
void rcpThreadFn_8009fcb8(void);
void rcpThreadMain(void);
void rcpQueueClear(RcpQueue *queue);
void rcpQueueAdd(RcpQueue *queue, RcpQueueItem *item);
void rcpQueueRemove(RcpQueueItem *outItem, RcpQueue *queue);
void rcpGxBreakptHandler();
void queue_top(RcpQueueItem *outItem, RcpQueue *queue);

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


/* probably related to drawing debug text or sprites */
void rspFn_8009ed78(Gfx_ **gfxIn, rspFn_8009ed78_struct *param_2,
int x, int y, u8 r, u8 g, u8 b, u8 a) {
	Texture2 *frame;
	Texture2 *tex;
	int frameNo;
	Gfx_ *gfx;
	int iFrame;
	int ii;
	int y2;
	int s1;
	int t1;
	int x1;
	int x2;
	int y1;

	iFrame = 0;
	gfx = *gfxIn;
	RSP_CMD_NOINC(&gfx, GX_SETCULLMODE, 0x00200404);
	rcpHandleSetCullMode(&gfx);

	RSP_CMD_NOINC(&gfx, (G_SETCOMBINE << 24) | 0x119623, 0xff2fffff);
	RSP_pipeSync(&gfx);

	RSP_CMD_NOINC(&gfx, (G_RDPSETOTHERMODE << 24) | 0x000c00, 0x00504240);
	rspPipeSyncFn800a697c(&gfx);
	x *= 4; y *= 4;

	for(; (tex = param_2[iFrame].items); iFrame++) {
		x1 = x + param_2[iFrame].x * 4;
		y1 = y + param_2[iFrame].y * 4;
		x2 = x1 + tex->width  * 4;
		y2 = y1 + tex->height * 4;
		if(x2 <= 0 || y2 <= 0) continue;

		s1 = 0; t1 = 0;
		if(x1 < 0) { s1 = -(x1 * 8); x1 = 0; }
		if(y1 < 0) { t1 = -(y1 * 8); y1 = 0; }

		//select correct frame
		frameNo = param_2[iFrame].frame >> 8;
		frame = tex;
		for(ii = 0; ii < frameNo && frame; ii++) {
			frame = frame->next;
		}

		RSP_CMD(&gfx, (G_SETTIMG << 24) | 0x100000, frame);
		gfx->pkt.param = (u32)frame; //@bug?
		RSP_CMD(&gfx, (G_SETTILE << 24) | 0x100000, 0x7000000);
		RSP_CMD(&gfx, (G_LOADBLOCK << 24),
			((MIN(frame->width * frame->height - 1, 0x7ff) & 0xfff) << 0xc) | 0x07000000);

		//G_SETTILE but, ((G_SETTILE << 24) | 0x100000) doesn't match
		RSP_CMD(&gfx, (((frame->width * 2 + 7) >> 3 & 0x1ffU) << 9) | 0xF5100000, 0);
		RSP_CMD(&gfx, (G_SETTILESIZE << 24),
			(((frame->width-1) * 0x4000) & 0xffc000) |
			((frame->height-1) * 4 & 0xffc));
		RSP_setTevColor2(&gfx, r, g, b, a);

		//draw the tile
		RSP_CMD(&gfx, GX_DRAW_IMG |
			((x2 & 0xfff) << 0xc) | (y2 & 0xfff),
			((x1 & 0xfff) << 0xc) | (y1 & 0xfff));
		RSP_CMD(&gfx, GX_DRAW_IMG_S1T1, (s1 << 0x10) | (t1 & 0xffff));
		RSP_CMD(&gfx, GX_DRAW_IMG_S2T2, 0x04000400);
		RSP_pState->bNeedPipeSync = true;
	}
	RSP_resetDp();
	*gfxIn = gfx;
}


void rcpScreenWriteFn8009f0fc(Gfx_ **gfx, Texture *texture, uint x, int y,
undefined4 param_5, int frameNo, int alpha, uint flags) {
    int h = texture->height;
	rcpScreenWrite(gfx, texture, x, y, 0, h,
        frameNo, alpha, flags);
}


void rcpScreenWriteFn_8009f16c(Gfx_ **gfx, Texture *texture, uint x, int y,
int blkStart, int blkEnd, int alpha, uint flags) { // 8009f16c
	int texH;

	texH = texture->height;
	blkStart -= y;
	if(blkStart < 0) blkStart = 0;
	blkEnd -= y;
	if(blkEnd > texH) blkEnd = texH;
	if(blkStart >= texH || blkEnd < 0) return;
	rcpScreenWrite(gfx, texture, x, y, blkStart, blkEnd,
		0, alpha, flags);
}


void rcpScreenWrite(Gfx_ **gfx,Texture *texture,uint x,int y,
uint blkStart,int blkEnd,int frameNo,int alpha,uint flags) {
    //TODO
}

void nop_8009FA00() {
    //empty function
}

void rcpGxBreakptHandler(void) {
	float time;
	OSTime time64;
	RcpQueueItem item;

	time64 = OSCheckStopwatch(&stopwatchGp);
	rcpBreakpointTime = u64ToFloat(time64) / 40500.0f;
	OSStopStopwatch(&stopwatchGp);
	OSResetStopwatch(&stopwatchGp);
	queue_top(&item, &RcpQueue_8036bc80);
	if((undefined *)item.frameBuffer == pCurFrameBuffer) {
		rcpBreakptVal_80398b51 = 1;
	} else {
		rcpBreakptFn_8009fa94();
	}
	return;
}

void rcpBreakptFn_8009fa94(void) { //8009fa94
	RcpQueueItem item;

	rcpQueueRemove(&item, &RcpQueue_8036bc80);
	rcpQueueAdd(&RcpQueue_8036bcfc, &item);
	OSWakeupThread(&rcpThreadQueue);
	OSStartStopwatch(&stopwatchGp);
	if(rcpQueueIsEmpty(&RcpQueue_8036bc80)) {
		GXDisableBreakPt();
		gxBreakPtFlag_80398b50 = 0;
	} else {
		queue_top(&item, &RcpQueue_8036bc80);
		GXEnableBreakPt((void*)item.unk00);
	}
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
		rcpBreakptFn_8009fa94();
		rcpBreakptVal_80398b51 = 0;
		viVal_80398b52 = false;
	}
}

void rcpThreadMain(void) {
	RcpQueueItem item;
    int dummy;
	do {
		OSSleepThread(&rcpThreadQueue);
		rcpQueueRemove(&item, &RcpQueue_8036bcfc);
	} while(true);
}

void rcpQueueClear(RcpQueue *queue) { //8009fc38
    queue->queue_top = 10;
}

void rcpQueueAdd(RcpQueue *queue, RcpQueueItem *item) { //8009fc44
	if(queue->queue_top == 10) {
		queue->queue_top = queue->count = 0;
	} else {
		queue->queue_top = (queue->queue_top + 1) % 10;
		if(queue->queue_top == queue->count) {
			OSPanic("rcp_dolphin.c", 1337, "queue overflow");
		}
	}
	*(queue->items + queue->queue_top) = *item;
}

void rcpQueueRemove(RcpQueueItem *outItem, RcpQueue *queue) {
	ushort uVar1;

	uVar1 = queue->count;
	if(queue->queue_top == 10) {
		OSPanic("rcp_dolphin.c", 0x546, "queue underflow");
	}
	if(queue->count == queue->queue_top) {
		queue->queue_top = 10;
	} else {
		queue->count = (queue->count + 1) % 10;
	}
	*outItem = *(queue->items + uVar1);
}

//probably reads the top item from the queue without removing it
void queue_top(RcpQueueItem *outItem, RcpQueue *queue) {
	ASSERTMSGLINE(1369, queue->queue_top != 10,
        "queue_top: queue empty");
	*outItem = queue->items[queue->count];
}
