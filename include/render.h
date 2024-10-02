#include "dolphin/mtx.h"

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
/* 0x6 */ s8 _06;
/* 0x7 */ s8 _07;
/* 0x8 */ s16 s;
/* 0xa */ s16 t;
/* 0xb */ u8 r;
/* 0xc */ u8 g;
/* 0xd */ u8 b;
/* 0xe */ u8 a;
} N64Vertex;

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
