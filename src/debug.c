#include "dolphin.h"
#include "types.h"
#include "gbi.h"
#include "n64pad.h"
#include "render.h"
#include "dll.h"

//there are multiple instances of:
//li  r0,0x0
//stb r0,0x0(0)
//used as a "poor man's assert"
inline void CRASH() { *(u8*)NULL = 0; }

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
    /* 0x0 */ char name[DIPROFSTRUCT_NAME_LEN+1];
    /* 0x18 */	undefined4 _18;
    /* 0x1c */	undefined4 time;
    /* 0x20 */	u8 _20;
    /* 0x21 */	undefined1 _21; //probably padding
    /* 0x22 */	undefined1 _22;
    /* 0x23 */	undefined1 _23;
} DiProfStruct;

//.bss (0x80325D20)
/* 8038ba60 */ DiProfStruct DiProfStruct_8038ba60[DIPROFSTRUCT_MAX_NUM];
/* 8038ba60 */ u8 DAT_8038ba60[64]; //no idea the size, just picked something to force it out of sdata
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

DiStack* diStackCreate(int param1,int param2); //80070320
int diStackGetNumItems(DiStack *stack); //800704d4
int diStackIsOverflow(DiStack *param_1); //800704b8
void diFn_800703c4(DiStack *stack, int*); //800703c4
void diStackPop(DiStack *stack,void *out); //80070440

int ret0_800BFC8C(void) { return 0; } //800BFC8C
void nop_800BFBF0(UNKTYPE*, UNKTYPE*, int);
void * mmAlloc2(uint size,uint tag,char *name); //8007badc

void memcpy_src_dst_len(void *src, void *dst, size_t len) { //800bfc20
    //extremely necessary function
    memcpy(dst,src,len);
}

void diProfReset(void) { //80179B60
    if(!diStack) diStack = diStackCreate(10,4);
    if(diStackGetNumItems(diStack) == 0) {
        printf("diProfReset: stack not empty\n");
    }
    diStackCount = 0;
    diProfCount = 0;
}

void diProfStart(void) { //80179BC8
    int unk0C;

    if(!diStack) {
        printf("diProfStart: before diProfReset!\n");
        CRASH();
    }
    if(diStackIsOverflow(diStack)) {
        printf("diProfStart: stack overflow\n");
        CRASH();
    }
    unk0C = ret0_800BFC8C();
    diFn_800703c4(diStack,&unk0C);
    diStackCount = diStackCount + 1;
}

void diProfEnd(undefined4 param1,char *name) { //80179C50
    int iVar1;
    int local_10;

    //local_8 = 0x21; //ghidra wtf? where did you find this code!?
    iVar1 = ret0_800BFC8C();
    diStackPop(diStack,&local_10);
    if(!diStack) {
        printf("diProfEnd: before diProfReset!\n");
        CRASH();
    }
    if(diProfCount == DIPROFSTRUCT_MAX_NUM) {
        //@bug missing argument, which causes ghidra to
        //produce an "extraout_r4" variable
        printf("diProfEnd: prof overflow (%d)\n");
    }
    else {
        memcpy_src_dst_len(name,
            &DiProfStruct_8038ba60 + diProfCount,
            DIPROFSTRUCT_NAME_LEN);
        DiProfStruct_8038ba60[diProfCount].name[DIPROFSTRUCT_NAME_LEN] = '\0';
        DiProfStruct_8038ba60[diProfCount]._18 = param1;
        DiProfStruct_8038ba60[diProfCount].time = iVar1 - local_10;
        DiProfStruct_8038ba60[diProfCount]._20 = diProfVar_803997dc;
        diProfCount += 1;
        diProfVar_803997dc += -1;
    }
}

//should be equivalent, only regalloc
void diProfPrint(uint mask) { //80179D60
    int uVar1;
    int iVar2;
    uint uVar3;
    uint ii;
    int jj;

    if(!diStack) {
        printf("diProfPrint: before diProfReset!\n");
        CRASH();
    }
    for(ii = 0; ii < diProfCount; ii++) {
        if((mask & DiProfStruct_8038ba60[ii]._18) == 0) continue;

        uVar1 = DiProfStruct_8038ba60[ii]._20;
        for(iVar2 = 0; iVar2 < (uVar1 << 1); iVar2++) printf(" ");
        printf("%s: %d", DiProfStruct_8038ba60[ii].name,
            DiProfStruct_8038ba60[ii].time);

        iVar2 = 0;
        for(uVar3 = ii - 1;
        (int)uVar3 >= 0 && DiProfStruct_8038ba60[uVar3]._20 > uVar1;
        uVar3--) {
            if ((uVar1 + 1) == DiProfStruct_8038ba60[uVar3]._20) {
                iVar2 += DiProfStruct_8038ba60[uVar3].time;
            }
        }
        if(iVar2) printf(" (%d+%d)",
            DiProfStruct_8038ba60[ii].time - iVar2,
            iVar2);
        printf("\n");
    }
}

//equiv except string offsets
void perfInitFn_80179ec0(void) { //80179ec0
    UNKTYPE *ptr = &DAT_8038ba60;
    DAT_80399828 = 0;
    bEnableRspStatusDisplay = FALSE;
    DAT_803997b8 = 0;
    DAT_803997c4 = 0;
    DAT_803997c8 = 0;
    DAT_803997cc = 0;
    DAT_80399820 = DAT_80399824 = 0;
    meter_distack  = mmAlloc2(16384,0xff00ff,"meter:distack");
    meter_cpustack = mmAlloc2(16000,0xff00ff,"meter:cpustack");
    meter_times    = mmAlloc2(16192,0xff00ff,"meter:times");
    meter_rcptimes = mmAlloc2( 3200,0xff00ff,"meter:rcptimes");
    meter_cputimes = mmAlloc2(16000,0xff00ff,"meter:cputimes");
    meter_actimes  = mmAlloc2( 3200,0xff00ff,"meter:actimes");
    meter_sctimes  = mmAlloc2( 6400,0xff00ff,"meter:sctimes");
    meter_cmdbuf   = mmAlloc2( 1024,0xff00ff,"meter:cmdbuf");
    meter_gfx      = mmAlloc2(64832,0xff00ff,"meter:gfx");
    initPerfMon();
    if (DAT_80396e88 == 0) {
        DAT_8039984c = 0x307e;
        DAT_80399850 = 0x24b8;
        DAT_80399854 = 0xe57;
    }
    else {
        DAT_8039984c = 0x279d;
        DAT_80399850 = 0x1e99;
        DAT_80399854 = 0xbf3;
    }
    debugSaveFn_8017a688();
    FUN_8017a638();
    PTR_DAT_803997f8 = meter_cputimes;
    PTR_DAT_803997fc = (void*)((int)meter_cputimes + 16000);
    PTR_DAT_80399804 = meter_actimes;
    PTR_DAT_80399808 = (void*)((int)meter_actimes + 3200);
    PTR_DAT_80399810 = meter_sctimes;
    PTR_DAT_80399814 = (void*)((int)meter_sctimes + 6400);
    PTR_DAT_803997ec = meter_rcptimes;
    PTR_DAT_803997f0 = (void*)((int)meter_rcptimes + 3200);
    nop_800BFBF0((void*)((int)ptr + 0x4A60),meter_cmdbuf,0x100);
    nop_800BFBF0((void*)((int)ptr + 0x4A90),&PTR_80399838,1);
    nop_800BFBF0((void*)((int)ptr + 0x4A78),&PTR_80399834,1);
}
