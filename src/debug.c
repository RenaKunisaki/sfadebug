#include "dolphin.h"
#include "types.h"
#include "gbi.h"
#include "n64pad.h"
#include "render.h"
#include "dll.h"

// there are multiple instances of:
// li  r0,0x0
// stb r0,0x0(0)
// used as a "poor man's assert"
inline void CRASH() { *(u8 *)NULL = 0; }

typedef struct {
  /* 0x0 */ s16 nItems;
  /* 0x2 */ s16 max;
  /* 0x4 */ s16 itemSize;
  /* 0x6 */ s8 _06;
  /* 0x7 */ s8 _07;
  /* 0x8 */ s16 count;
  /* 0xa */ s8 _0a;
  /* 0xb */ s8 _0b;
  /* 0xc */ s16 *data;
} DiStack;

#define DIPROFSTRUCT_MAX_NUM 0x200
#define DIPROFSTRUCT_NAME_LEN 23
typedef struct {
  /* 0x0 */ char name[DIPROFSTRUCT_NAME_LEN + 1];
  /* 0x18 */ undefined4 _18;
  /* 0x1c */ undefined4 time;
  /* 0x20 */ u8 _20;
  /* 0x21 */ undefined1 _21; // probably padding
  /* 0x22 */ undefined1 _22;
  /* 0x23 */ undefined1 _23;
} DiProfStruct;

typedef struct {
    /* 0x0 */ undefined4 unk0;
    /* 0x4 */ undefined4 unk4;
    /* 0x8 */ Vec charPos;
    /* 0x14 */ uint unk14;
    /* 0x18 */ char	codeVersion[64];
    /* 0x58 */ char	buildDate[64];
    /* 0x98 */ char	buildAuthor[64];
    /* 0xd8 */ char	fullVersionString[64];
    /* 0x118 */ undefined4 unk118;
    /* 0x11c */ undefined unk11c;
    /* 0x11d */ undefined unk11d;
    /* 0x11e */ undefined unk11e;
    /* 0x11f */ undefined unk11f;
    /* 0x120 */ undefined unk120;
    /* 0x121 */ undefined unk121;
    /* 0x122 */ undefined unk122;
    /* 0x123 */ undefined unk123;
} DebugSaveStruct;

//.bss (0x80325D20)
/* 8038ba60 */ DiProfStruct DiProfStruct_8038ba60[DIPROFSTRUCT_MAX_NUM];
/* 8038ba60 */ u8 DAT_8038ba60[64]; // no idea the size, just picked something
                                    // to force it out of sdata
/* 803904c0 */ UNKTYPE *DAT_803904c0;
/* 803904d8 */ UNKTYPE *DAT_803904d8;
/* 803904f0 */ UNKTYPE *DAT_803904f0;

//.sdata (0x80396700)
/* 80396e88 */ extern int DAT_80396e88;

//.sbss (0x80398240)
/* 803997b8 */ int DAT_803997b8;
/* 803997c4 */ int DAT_803997c4;
/* 803997c8 */ int DAT_803997c8;
/* 803997cc */ int DAT_803997cc;
/* 803997d4 */ DiStack *diStack;
/* 803997d8 */ uint diProfCount;
/* 803997dc */ int diStackCount;
/* 803997dc */ u32 diProfVar_803997dc;
/* 803997e0 */ UNKTYPE *meter_times;
/* 803997e8 */ UNKTYPE *meter_rcptimes;
/* 803997ec */ UNKTYPE *PTR_DAT_803997ec;
/* 803997f0 */ UNKTYPE *PTR_DAT_803997f0;
/* 803997f4 */ UNKTYPE *meter_cputimes;
/* 803997f8 */ UNKTYPE *PTR_DAT_803997f8;
/* 803997fc */ UNKTYPE *PTR_DAT_803997fc;
/* 80399800 */ UNKTYPE *meter_actimes;
/* 80399804 */ UNKTYPE *PTR_DAT_80399804;
/* 80399808 */ UNKTYPE *PTR_DAT_80399808;
/* 8039980c */ UNKTYPE *meter_sctimes;
/* 80399810 */ UNKTYPE *PTR_DAT_80399810;
/* 80399814 */ UNKTYPE *PTR_DAT_80399814;
/* 80399818 */ UNKTYPE *meter_gfx;
/* 80399820 */ int DAT_80399820;
/* 80399824 */ int DAT_80399824;
/* 80399828 */ int DAT_80399828;
/* 8039982c */ BOOL bEnableRspStatusDisplay;
/* 80399830 */ UNKTYPE *meter_cmdbuf;
/* 80399834 */ UNKTYPE *PTR_80399834;
/* 80399838 */ UNKTYPE *PTR_80399838;
/* 8039983c */ UNKTYPE *meter_distack;
/* 80399840 */ UNKTYPE *meter_cpustack;
/* 8039984c */ int DAT_8039984c;
/* 80399850 */ int DAT_80399850;
/* 80399854 */ int DAT_80399854;

DiStack *diStackCreate(int param1, int param2); // 80070320
int diStackGetNumItems(DiStack *stack);         // 800704d4
int diStackIsOverflow(DiStack *param_1);        // 800704b8
void diFn_800703c4(DiStack *stack, int *);      // 800703c4
void diStackPop(DiStack *stack, void *out);     // 80070440

int ret0_800BFC8C(void) { return 0; } // 800BFC8C
void nop_800BFBF0(UNKTYPE *, UNKTYPE *, int);
void *mmAlloc2(uint size, uint tag, char *name); // 8007badc
void debugSaveFn_8017a688(void);

void memcpy_src_dst_len(void *src, void *dst, size_t len) { // 800bfc20
  // extremely necessary function
  memcpy(dst, src, len);
}

void diProfReset(void) { // 80179B60
  if (!diStack)
    diStack = diStackCreate(10, 4);
  if (diStackGetNumItems(diStack) == 0) {
    printf("diProfReset: stack not empty\n");
  }
  diStackCount = 0;
  diProfCount = 0;
}

void diProfStart(void) { // 80179BC8
  int unk0C;

  if (!diStack) {
    printf("diProfStart: before diProfReset!\n");
    CRASH();
  }
  if (diStackIsOverflow(diStack)) {
    printf("diProfStart: stack overflow\n");
    CRASH();
  }
  unk0C = ret0_800BFC8C();
  diFn_800703c4(diStack, &unk0C);
  diStackCount = diStackCount + 1;
}

void diProfEnd(undefined4 param1, char *name) { // 80179C50
  int iVar1;
  int local_10;

  // local_8 = 0x21; //ghidra wtf? where did you find this code!?
  iVar1 = ret0_800BFC8C();
  diStackPop(diStack, &local_10);
  if (!diStack) {
    printf("diProfEnd: before diProfReset!\n");
    CRASH();
  }
  if (diProfCount == DIPROFSTRUCT_MAX_NUM) {
    //@bug missing argument, which causes ghidra to
    // produce an "extraout_r4" variable
    printf("diProfEnd: prof overflow (%d)\n");
  } else {
    memcpy_src_dst_len(name, &DiProfStruct_8038ba60 + diProfCount,
                       DIPROFSTRUCT_NAME_LEN);
    DiProfStruct_8038ba60[diProfCount].name[DIPROFSTRUCT_NAME_LEN] = '\0';
    DiProfStruct_8038ba60[diProfCount]._18 = param1;
    DiProfStruct_8038ba60[diProfCount].time = iVar1 - local_10;
    DiProfStruct_8038ba60[diProfCount]._20 = diProfVar_803997dc;
    diProfCount += 1;
    diProfVar_803997dc += -1;
  }
}

// should be equivalent, only regalloc
void diProfPrint(uint mask) { // 80179D60
  int uVar1;
  int iVar2;
  uint uVar3;
  uint ii;
  int jj;

  if (!diStack) {
    printf("diProfPrint: before diProfReset!\n");
    CRASH();
  }
  for (ii = 0; ii < diProfCount; ii++) {
    if ((mask & DiProfStruct_8038ba60[ii]._18) == 0)
      continue;

    uVar1 = DiProfStruct_8038ba60[ii]._20;
    for (iVar2 = 0; iVar2 < (uVar1 << 1); iVar2++)
      printf(" ");
    printf("%s: %d", DiProfStruct_8038ba60[ii].name,
           DiProfStruct_8038ba60[ii].time);

    iVar2 = 0;
    for (uVar3 = ii - 1;
         (int)uVar3 >= 0 && DiProfStruct_8038ba60[uVar3]._20 > uVar1; uVar3--) {
      if ((uVar1 + 1) == DiProfStruct_8038ba60[uVar3]._20) {
        iVar2 += DiProfStruct_8038ba60[uVar3].time;
      }
    }
    if (iVar2)
      printf(" (%d+%d)", DiProfStruct_8038ba60[ii].time - iVar2, iVar2);
    printf("\n");
  }
}

// equiv except string offsets
void perfInit(void) { // 80179ec0
  UNKTYPE *ptr = &DAT_8038ba60;
  DAT_80399828 = 0;
  bEnableRspStatusDisplay = FALSE;
  DAT_803997b8 = 0;
  DAT_803997c4 = 0;
  DAT_803997c8 = 0;
  DAT_803997cc = 0;
  DAT_80399820 = DAT_80399824 = 0;
  meter_distack = mmAlloc2(16384, 0xff00ff, "meter:distack");
  meter_cpustack = mmAlloc2(16000, 0xff00ff, "meter:cpustack");
  meter_times = mmAlloc2(16192, 0xff00ff, "meter:times");
  meter_rcptimes = mmAlloc2(3200, 0xff00ff, "meter:rcptimes");
  meter_cputimes = mmAlloc2(16000, 0xff00ff, "meter:cputimes");
  meter_actimes = mmAlloc2(3200, 0xff00ff, "meter:actimes");
  meter_sctimes = mmAlloc2(6400, 0xff00ff, "meter:sctimes");
  meter_cmdbuf = mmAlloc2(1024, 0xff00ff, "meter:cmdbuf");
  meter_gfx = mmAlloc2(64832, 0xff00ff, "meter:gfx");
  initPerfMon();
  if (DAT_80396e88 == 0) {
    DAT_8039984c = 0x307e;
    DAT_80399850 = 0x24b8;
    DAT_80399854 = 0xe57;
  } else {
    DAT_8039984c = 0x279d;
    DAT_80399850 = 0x1e99;
    DAT_80399854 = 0xbf3;
  }
  debugSaveFn_8017a688();
  FUN_8017a638();
  PTR_DAT_803997f8 = meter_cputimes;
  PTR_DAT_803997fc = (void *)((int)meter_cputimes + 16000);
  PTR_DAT_80399804 = meter_actimes;
  PTR_DAT_80399808 = (void *)((int)meter_actimes + 3200);
  PTR_DAT_80399810 = meter_sctimes;
  PTR_DAT_80399814 = (void *)((int)meter_sctimes + 6400);
  PTR_DAT_803997ec = meter_rcptimes;
  PTR_DAT_803997f0 = (void *)((int)meter_rcptimes + 3200);
  nop_800BFBF0((void *)((int)ptr + 0x4A60), meter_cmdbuf, 0x100);
  nop_800BFBF0((void *)((int)ptr + 0x4A90), &PTR_80399838, 1);
  nop_800BFBF0((void *)((int)ptr + 0x4A78), &PTR_80399834, 1);
}

DebugSaveStruct *debugSaveBuf_803997c0;
int DWORD_803997b8;
int DWORD_803997c8;
void *DWORD_803997bc;
int diFlag_803997d0;
extern LoadedDLL *pDll_SaveGame;

void diProfStoreFn_8017a0d8(int param1) { // 8017A0D8
  int dVar1;

  dVar1 = DWORD_803997b8;
  if (((DWORD_803997c8 != 1) && (DWORD_803997c8 != 3)) &&
      (DWORD_803997c8 != 5)) {
    if (param1 == 0) {
      debugSaveFn_8017a688();
      diFlag_803997d0 = 0;
    } else if (param1 == 1) {
      fn_8017AFD8();
      debugSaveFn_8017a688();
      DWORD_803997bc = mmAlloc2(0x286e0, 0xff00ff, "meter:perfdata1");
      debugSaveBuf_803997c0 = (DebugSaveStruct *)mmAlloc2(0x124, 0xff00ff, "meter:perfdata2");
      if ((DWORD_803997bc == 0) || (debugSaveBuf_803997c0 == 0)) {
        printf("Sorry No DI memory left to store profile.");
        diFlag_803997d0 = 0;
      }
      debugSaveBuf_803997c0->unk118 = 0;
      diFlag_803997d0 = 0;
      nop_800BFC04(0x80000000, 0x9FFFFFFF);
      nop_800BFC08(0x80000000, 0x9FFFFFFF);
      pDll_SaveGame->funcs->func[6]();
    } else if (param1 == 2) {
      fn_8017AFD8();
      debugSaveFn_8017a688();
      DWORD_803997bc = mmAlloc2(0x5c, 0xff00ff, "meter:perfdata3");
      debugSaveBuf_803997c0 = (DebugSaveStruct *)mmAlloc2(0x124, 0xff00ff, "meter:perfdata4");
      if ((DWORD_803997bc == 0) || (debugSaveBuf_803997c0 == 0)) {
        printf("Sorry No DI memory left to store profile.");
        diFlag_803997d0 = 0;
      }
      debugSaveBuf_803997c0->unk118 = 0;
      DWORD_803997c8 = 4;
      diFlag_803997d0 = 0;
      dVar1 = param1;
    } else if (param1 == 3) {
      fn_8017AFD8();
      diFlag_803997d0 = 1;
      DWORD_803997c8 = 5;
      dVar1 = 1;
    } else
      dVar1 = param1;
  }
  DWORD_803997b8 = dVar1;
}

u8 lbl_803904C0[0x18]; // unknown type/size
int lbl_803904D8[0x18];
int lbl_803973C0;

void FUN_8017A2B0(void) { // 8017A2B0
  if (DWORD_803997b8 != 0) {
    retM1_afterLoadAsset_ret0xFFFF(&lbl_803904C0, &lbl_803973C0, 1);
    retM1_800BFBFC_ret0xFFFF(&lbl_803904D8, 0, 1);
  }
}

int fn_8017A300(void) { // 8017A300
  return DWORD_803997b8;
}

void setEnableRspStatusDisplay(BOOL param_1) { // 8017A308
  bEnableRspStatusDisplay = param_1;
  return;
}

BOOL getEnableRspStatusDisplay(void) { // 8017A310
  return bEnableRspStatusDisplay;
}

BOOL DWORD_80399828;             // assumed type
void fn_8017A318(BOOL param_1) { // 8017A318
  DWORD_80399828 = param_1;
}

BOOL fn_8017A320(void) { // 8017A320
  return DWORD_80399828;
}

u8 lbl_80399858[8];
void nop_8017a328(void) { // 8017A328
  nop_800BFC0C(&DiProfStruct_8038ba60);
  retM1_afterLoadAsset_ret0xFFFF(&lbl_803904C0, &lbl_80399858, 1);
  retM1_800BFBFC_ret0xFFFF(&lbl_803904D8, 0, 1);
}

union {
  struct {
    int rspTotalTime;
    int rdpWorkingTime;
    int rdpPipeNotStalledTime;
    int tmemLoadingTime;
  };
  int times[4];
} rspTimes;

int DAT_80390270[4];
int DAT_80390260[4];
int lbl_803973C4;
int fn_8017AFC4();
int diPrintf(const char *fmt, ...);

void printRspStatus(void) { // 8017A37C reloc
  int iVar2;
  float work;

  nop_800BFC0C(&DiProfStruct_8038ba60);
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    rspTimes.times[iVar2] =
        (DAT_80390270[iVar2] - DAT_80390260[iVar2]) & 0xffffff;
  }
  if ((fn_8017AFC4() == 0) && (bEnableRspStatusDisplay != 0)) {
    dprintReset();
    dprintSetBgColor(0, 0, 0xff, 0x80);

    work = ((u32)rspTimes.rspTotalTime * 1000.0f) / 62600000;
    diPrintf("Total time. = %2.1fmS", &work);
    // this constant probably is related to CPU speed

    work = ((u32)rspTimes.rdpWorkingTime * 100.0f) /
           (float)(u32)rspTimes.rspTotalTime;
    diPrintf("RDP working.   = %2.0f%%", &work);

    work = ((u32)rspTimes.rdpPipeNotStalledTime * 100.0f) /
           (float)(u32)rspTimes.rspTotalTime;
    diPrintf("Pipe not stalled.  = %2.0f%%", &work);

    work = ((u32)rspTimes.tmemLoadingTime * 100.0f) /
           (float)(u32)rspTimes.rspTotalTime;
    diPrintf("TMEM loading. = %2.0f%%", &work);
  }
  if (DWORD_80399828 != 0) {
    retM1_afterLoadAsset_ret0xFFFF(lbl_803904C0, (undefined *)&lbl_803973C4, 1);
    retM1_800BFBFC_ret0xFFFF((undefined *)&lbl_803904D8, 0, 1);
  }
}

undefined4 *DAT_803997f8;
undefined4 *DWORD_803997fc;
void store_0_to_stackC(int);

void dummiedProfFn_8017a59c(undefined4 param1) { // 8017A59C
  undefined4 *puVar1;

  store_0_to_stackC(param1);
  *(DAT_803997f8++) = 1;
  *(DAT_803997f8++) = ret0_800BFC8C();
  *(DAT_803997f8++) = param1;

  retM1_afterLoadAsset_ret0xFFFF(lbl_803904C0, DAT_803997f8 - 3, 0);
  if (DWORD_803997fc + 3 >= DAT_803997f8) {
    DAT_803997f8 = (undefined4 *)meter_cputimes;
  }
}

UNKTYPE *DAT_8039981c;
int DAT_80399844;
u8 BYTE_80399848;
undefined4 *DAT_803997e4;

void fn_8017A638(void) { // 8017A638
  DAT_8039981c = meter_gfx;
  DAT_80399844 = 0;
  BYTE_80399848 = 0;
  DAT_803997e4 = (undefined4 *)meter_times;
  *(DAT_803997e4++) = ret0_800BFC8C();
}

void debugSaveFn_8017a688(void) { // 8017A688
  Vec *pos;
  uint uVar1;

  if (((DWORD_803997bc != 0) && (DWORD_803997c8 != 1)) &&
      (DWORD_803997c8 != 3)) {
    /* {@symbol 8012da28} */
    pos = (Vec *)pDll_SaveGame->funcs->func[34]();
    /* {@symbol 8012d9a0} */
    uVar1 = pDll_SaveGame->funcs->func[27]() & 0xFF;

    debugSaveBuf_803997c0->unk0 = 0x124;
    debugSaveBuf_803997c0->unk4 = 0x5c;
    (debugSaveBuf_803997c0->charPos).x = pos->x;
    (debugSaveBuf_803997c0->charPos).y = pos->y;
    (debugSaveBuf_803997c0->charPos).z = pos->z;
    debugSaveBuf_803997c0->unk14 = uVar1;
    debugSaveBuf_803997c0->unk118 = DAT_803997c4;
    debugSaveBuf_803997c0->unk11c = 1;
    debugSaveBuf_803997c0->unk11d = 1;
    debugSaveBuf_803997c0->unk11e = 1;
    debugSaveBuf_803997c0->unk11f = 0;
    debugSaveBuf_803997c0->unk120 = 0;
    debugSaveBuf_803997c0->unk121 = 0;
    debugSaveBuf_803997c0->unk122 = 0;
    debugSaveBuf_803997c0->unk123 = 0;
    memset_(debugSaveBuf_803997c0->codeVersion,0,0x40);
    memset_(debugSaveBuf_803997c0->buildDate,0,0x40);
    memset_(debugSaveBuf_803997c0->buildAuthor,0,0x40);
    memset_(debugSaveBuf_803997c0->fullVersionString,0,0x40);
    strcpy(debugSaveBuf_803997c0->codeVersion,"1.3705");
    strcpy(debugSaveBuf_803997c0->buildDate,"03/01/01 16:09");
    strcpy(debugSaveBuf_803997c0->buildAuthor,"ptossell");
    strcpy(debugSaveBuf_803997c0->fullVersionString,"Version 2.8 14/12/98 15.30 L.Schuneman");
    if (DWORD_803997b8 == 1) {
      DWORD_803997c8 = 1;
    } else if (DWORD_803997b8 == 2) {
      DWORD_803997c8 = 3;
    }
  }
}
