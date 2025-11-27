#ifndef _GFX_RENDER_H_
#define _GFX_RENDER_H_
#include "../dolphin/mtx.h"
#include "dolphin/gx/GXStruct.h"
#include "gfx/gbi.h"
#include "gfx/textures.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define RCP_GX_FIFO_SIZE 0x10000

typedef enum {
    IsNotSubmap = 1,
    EnableMapUpdate = 2,
    Widescreen = 8,
    Cloudy = 16,
    DisableAntiAlias = 32,
    DrawLights = 64,
    DrawShadows = 128,
} RenderFlagsEnum;

typedef struct {
    /* 0x0 */	undefined4 tempCmd;
    /* 0x4 */	undefined4 tempCmdParam;
    /* 0x8 */	undefined4 _08;
    /* 0xc */	undefined4 _0C;
    /* 0x10 */	undefined _10;
    /* 0x11 */	undefined _11;
    /* 0x12 */	undefined _12;
    /* 0x13 */	undefined _13;
    /* 0x14 */	uint curPrimColor;
    /* 0x18 */	undefined _18;
    /* 0x19 */	undefined _19;
    /* 0x1a */	undefined _1A;
    /* 0x1b */	undefined _1B;
    /* 0x1c */	undefined _1C;
    /* 0x1d */	undefined _1D;
    /* 0x1e */	undefined _1E;
    /* 0x1f */	undefined _1F;
    /* 0x20 */	undefined _20;
    /* 0x21 */	undefined _21;
    /* 0x22 */	undefined _22;
    /* 0x23 */	undefined _23;
    /* 0x24 */	undefined _24;
    /* 0x25 */	undefined _25;
    /* 0x26 */	undefined _26;
    /* 0x27 */	undefined _27;
    /* 0x28 */	bool bNeedPipeSync;
    /* 0x29 */	uchar flags;
} RSPState;

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 unk06;
    /* 0x8 */ s16 s;
    /* 0xa */ s16 t;
    /* 0xc */ GXColor col;
} N64Vertex;

typedef struct {
    /* 0x0 */ undefined unk00;
    /* 0x1 */ u8 idxs[3]; //triangle idxs
    /* 0x4 */ undefined unk04;
    /* 0x5 */ undefined unk05;
    /* 0x6 */ undefined unk06;
    /* 0x7 */ undefined unk07;
    /* 0x8 */ undefined unk08;
    /* 0x9 */ undefined unk09;
    /* 0xa */ undefined unk0a;
    /* 0xb */ undefined unk0b;
    /* 0xc */ undefined unk0c;
    /* 0xd */ undefined unk0d;
    /* 0xe */ undefined unk0e;
    /* 0xf */ undefined unk0f;
} N64VertexIdxs;

typedef struct {
    /* 0x0 */ s8 _00;
    /* 0x1 */ s8 _01;
    /* 0x2 */ s8 _02;
    /* 0x3 */ s8 _03;
    /* 0x4 */ s8 _04;
    /* 0x5 */ s8 _05;
    /* 0x6 */ s8 _06;
    /* 0x7 */ s8 _07;
    /* 0x8 */ s8 _08;
    /* 0x9 */ s8 _09;
    /* 0xA */ s8 _0A;
    /* 0xB */ s8 _0B;
    /* 0xC */ s8 _0C;
    /* 0xD */ s8 _0D;
    /* 0xE */ s8 _0E;
    /* 0xF */ s8 _0F;
} Pol; //Polygon?

typedef struct {
    /* 0x0 */ Texture2 *items; //texture to use (NULL to end list)
    /* 0x4 */ int frame; //frame number to use
    /* 0x8 */ s16 x;
    /* 0xa */ s16 y;
} rspFn_8009ed78_struct;

#define MAIN_GFX_SIZE 10000
#define MAIN_MTX_SIZE 800
#define MAIN_VTX_SIZE 1000
#define MAIN_POL_SIZE 1000
#define DI_VTX_SIZE 1800
#define DI_POL_SIZE 3000

/* extern u8 main_framebuf_idx;
extern F3DEXcmdBuf *main_gfx[2];
extern Mtx44 *main_mtx[2];
extern N64Vertex *main_vtx[2];
extern Pol *main_pol[2];
extern N64Vertex *main_divtx[2];
extern Pol *main_dipol[2];

extern F3DEXcmdBuf *curCmdBuf;
extern F3DEXcmdBuf *gfx;
extern Mtx44 *mtx;
extern N64Vertex *curVtxBuffer;
extern Pol *curPolBuffer;
extern N64Vertex *curDiVtx;
extern Pol *curDiPol;
extern UNKTYPE *currentScreen;
extern UNKTYPE *otherZbuf;

extern short main_gfx_count;
extern short main_mtx_count;
extern short main_vtx_count;
extern short main_pol_count;
extern short di_vtx_count;
extern short di_pol_count;

extern RSPState *RSP_pState;
extern int diFlag_803997d0; */

Gfx* RSP_pipeSync(Gfx **gfx);
Gfx* rspPipeSyncFn800a6900(Gfx **gfx);
Gfx* RSP_setTevColor2(Gfx **gfx,u8 r,u8 g,u8 b,u8 a);

#define RSP_CMD(gfx, op, prm)         \
	do {                              \
		Gfx *gfx_ = (*(gfx))++;      \
		gfx_->words.w0 = (op);         \
		gfx_->words.w1 = (u32)(prm); \
	} while(0)

#define RSP_CMD_NOINC(gfx, op, prm)   \
	do {                              \
		Gfx *gfx_ = (*gfx);          \
		gfx_->words.w0 = (op);         \
		gfx_->words.w1 = (u32)(prm); \
	} while(0)

#define RDP_SET_CIMG(gfx, op, prm) \
    do { \
        (gfx)->words.w0 = _SHIFTL(G_SETCIMG, 24, 8) | (op); \
        (gfx)->words.w1 = (u32)(prm); \
        RSP_pipeSync(&gfx); \
    } while(0)

#define RDP_SET_OTHER_MODE(gfx, op, prm) \
    do { \
        Gfx *gfx_ = (gfx); \
        (gfx_)->words.w0 = _SHIFTL(G_RDPSETOTHERMODE, 24, 8) | (op); \
        (gfx_)->words.w1 = (u32)(prm); \
        rspPipeSyncFn800a6900(&gfx_); \
    } while(0)

#define RDP_SET_COMBINE(gfx, op, prm) \
    do { \
        Gfx *gfx_ = (gfx); \
        (gfx_)->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | (op); \
        (gfx_)->words.w1 = (u32)(prm); \
        RSP_pipeSync(&gfx_); \
    } while(0)

#define	RDP_SET_IMAGE(gfx, fmt, siz, width, i) \
    do { \
        Gfx *gfx_ = (gfx); \
        (gfx_)->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | \
            _SHIFTL(fmt, 21, 3) | \
            _SHIFTL(siz, 19, 2) | \
            _SHIFTL((width)-1, 0, 12); \
        (gfx_)->words.w1 = (unsigned int)(i);				\
    } while(0)

//this is one of the game's custom commands.
//it expects the next two commands to follow it in this
//order. it doesn't actually check them, just reads
//the parameters.
//N64 had something going on with quarter-pixel units
//so that might explain the shift by 14
#define RDP_GX_DRAW_IMAGE(gfx, x1, y1, x2, y2, s1, t1, s2, t2) do { \
	RSP_CMD((gfx), GX_DRAW_IMG | \
		(((x2) << 14) & 0xffc000) | ((y2) & 0xfff), \
        (((x1) << 14) & 0xffc000) | ((y1) & 0xfff)); \
	RSP_CMD((gfx), GX_DRAW_IMG_S1T1, ((s1) << 16) | ((t1) & 0xffff)); \
	RSP_CMD((gfx), GX_DRAW_IMG_S2T2, ((s2) << 16) | ((t2) & 0xffff)); \
	RSP_pState->bNeedPipeSync = true; \
} while(0)

#endif //_GFX_RENDER_H_
