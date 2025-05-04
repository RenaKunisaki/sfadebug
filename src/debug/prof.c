#include "dolphin.h"
#include "types.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/dll.h"
#include "debug.h"

union {
	struct {
		int rspTotalTime;
		int rdpWorkingTime;
		int rdpPipeNotStalledTime;
		int tmemLoadingTime;
	};
	int times[4];
} rspTimes;

/* 80390260 */ int DWORD_80390260[4];
/* 80390270 */ int DWORD_80390270[4];
/* 803904C0 */ u8 lbl_803904C0[0x18]; // unknown type/size
/* 803904D8 */ int lbl_803904D8[0x18];
/* 803973C0 */ extern int lbl_803973C0;
/* 803973C4 */ extern int lbl_803973C4;

//.bss (0x80325D20)
/* 8038ba60 */ DiProfStruct DiProfStruct_8038ba60[DIPROFSTRUCT_MAX_NUM];
/* 8038ba60 */ u8 DWORD_8038ba60[64]; // no idea the size, just picked something
                                    // to force it out of sdata
/* 803904c0 */ UNKTYPE *DWORD_803904c0;
/* 803904d8 */ UNKTYPE *DWORD_803904d8;
/* 803904f0 */ UNKTYPE *DWORD_803904f0;

//.sdata (0x80396700)
/* 80396e88 */ extern int DWORD_80396e88;

//.sbss (0x80398240)
/* 803989A4 */ extern LoadedDLL *pDll_SaveGame;
//end 803989d0
/* 803997B8 */ extern int DWORD_803997b8;
/* 803997BC */ extern DebugSaveStruct *pMeterPerfdata1;
/* 803997C0 */ extern DebugSaveStruct *pMeterPerfdata2;
/* 803997C4 */ extern int DAT_803997c4;
/* 803997C8 */ extern int DWORD_803997c8;
/* 803997CC */ extern int DWORD_803997cc;
/* 803997D0 */ extern int diFlag_803997d0;
/* 803997D4 */ extern DiStack *diStack;
/* 803997D8 */ extern uint diProfCount;
/* 803997DC */ extern int diStackCount;
/* 803997E0 */ extern UNKTYPE *meter_times;
/* 803997E4 */ extern undefined4 *PTR_DAT_803997e4;
/* 803997E8 */ extern UNKTYPE *meter_rcptimes;
/* 803997EC */ extern UNKTYPE *PTR_DAT_803997ec;
/* 803997F0 */ extern UNKTYPE *PTR_DAT_803997f0;
/* 803997F4 */ extern UNKTYPE *meter_cputimes;
/* 803997F8 */ extern int *PTR_DAT_803997f8;
/* 803997FC */ extern int *PTR_DAT_803997fc;
/* 80399800 */ extern UNKTYPE *meter_actimes;
/* 80399804 */ extern UNKTYPE *PTR_DAT_80399804;
/* 80399808 */ extern UNKTYPE *PTR_DAT_80399808;
/* 8039980C */ extern UNKTYPE *meter_sctimes;
/* 80399810 */ extern UNKTYPE *PTR_DAT_80399810;
/* 80399814 */ extern UNKTYPE *PTR_DAT_80399814;
/* 80399818 */ extern UNKTYPE *meter_gfx;
/* 8039981C */ extern UNKTYPE *PTR_DAT_8039981c;
/* 80399820 */ extern int DWORD_80399820;
/* 80399824 */ extern int DWORD_80399824;
/* 80399828 */ extern BOOL DWORD_80399828; // assumed type
/* 8039982C */ extern BOOL bEnableRspStatusDisplay;
/* 80399830 */ extern UNKTYPE *meter_cmdbuf;
/* 80399834 */ extern UNKTYPE *DWORD_80399834;
/* 80399838 */ extern UNKTYPE *DWORD_80399838;
/* 8039983C */ extern UNKTYPE *meter_distack;
/* 80399840 */ extern UNKTYPE *meter_cpustack;
/* 80399844 */ extern int DAT_80399844;
/* 80399848 */ extern u8 BYTE_80399848;
/* 8039984C */ extern int DWORD_8039984c;
/* 80399850 */ extern int DWORD_80399850;
/* 80399854 */ extern int DWORD_80399854;
/* 80398b70 */ extern void *pFrameBuffer_80398b70;
/* 80398b74 */ extern void *pFrameBuffer_80398b74;

void fn_8017A638(void);
s8 fn_8017AFC4(void);
int diPrintf(const char *fmt, ...);
DiStack *diStackCreate(int param1, int param2); // 80070320
int diStackGetNumItems(DiStack *stack); // 800704d4
int diStackIsOverflow(DiStack *param_1); // 800704b8
void diFn_800703c4(DiStack *stack, int *); // 800703c4
void diStackPop(DiStack *stack, void *out); // 80070440
int ret0_800BFC8C(void); // 800BFC8C
void nop_800BFBF0(UNKTYPE *, UNKTYPE *, int);
void *mmAlloc2(uint size, uint tag, char *name); // 8007badc
void memcpy_src_dst_len(void *src, void *dst, size_t len); // 800bfc20
void debugSaveFn_8017a688(void);

void diProfReset(void) { // 80179B60
	if(!diStack) diStack = diStackCreate(10, 4);
	if(diStackGetNumItems(diStack) == 0) {
		printf("diProfReset: stack not empty\n");
	}
	diStackCount = 0;
	diProfCount = 0;
}

void diProfStart(void) { // 80179BC8
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
	diFn_800703c4(diStack, &unk0C);
	diStackCount = diStackCount + 1;
}

void diProfEnd(undefined4 param1, char *name) { // 80179C50
	int iVar1;
	int local_10;

	// local_8 = 0x21; //ghidra wtf? where did you find this code!?
	iVar1 = ret0_800BFC8C();
	diStackPop(diStack, &local_10);
	if(!diStack) {
		printf("diProfEnd: before diProfReset!\n");
		CRASH();
	}
	if(diProfCount == DIPROFSTRUCT_MAX_NUM) {
		//@bug missing argument, which causes ghidra to
		// produce an "extraout_r4" variable
		printf("diProfEnd: prof overflow (%d)\n");
	} else {
		memcpy_src_dst_len(
		    name, &DiProfStruct_8038ba60 + diProfCount, DIPROFSTRUCT_NAME_LEN);
		DiProfStruct_8038ba60[diProfCount].name[DIPROFSTRUCT_NAME_LEN] = '\0';
		DiProfStruct_8038ba60[diProfCount]._18 = param1;
		DiProfStruct_8038ba60[diProfCount].time = iVar1 - local_10;
		DiProfStruct_8038ba60[diProfCount]._20 = diStackCount;
		diProfCount += 1;
		diStackCount += -1;
	}
}

// should be equivalent, only regalloc
void diProfPrint(uint mask) { // 80179D60
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
		printf("%s: %d",
		    DiProfStruct_8038ba60[ii].name,
		    DiProfStruct_8038ba60[ii].time);

		iVar2 = 0;
		for(uVar3 = ii - 1;
		    (int)uVar3 >= 0 && DiProfStruct_8038ba60[uVar3]._20 > uVar1;
		    uVar3--) {
			if((uVar1 + 1) == DiProfStruct_8038ba60[uVar3]._20) {
				iVar2 += DiProfStruct_8038ba60[uVar3].time;
			}
		}
		if(iVar2)
			printf(" (%d+%d)", DiProfStruct_8038ba60[ii].time - iVar2, iVar2);
		printf("\n");
	}
}

// equiv except string offsets
void perfInit(void) { // 80179ec0
	UNKTYPE *ptr = &DWORD_8038ba60;
	DWORD_80399828 = FALSE;
	bEnableRspStatusDisplay = FALSE;
	DWORD_803997b8 = 0;
	DAT_803997c4 = 0;
	DWORD_803997c8 = 0;
	DWORD_803997cc = 0;
	DWORD_80399820 = DWORD_80399824 = 0;
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
	if(DWORD_80396e88 == 0) {
		DWORD_8039984c = 0x307e;
		DWORD_80399850 = 0x24b8;
		DWORD_80399854 = 0xe57;
	} else {
		DWORD_8039984c = 0x279d;
		DWORD_80399850 = 0x1e99;
		DWORD_80399854 = 0xbf3;
	}
	debugSaveFn_8017a688();
	fn_8017A638();
	PTR_DAT_803997f8 = meter_cputimes;
	PTR_DAT_803997fc = (void *)((int)meter_cputimes + 16000);
	PTR_DAT_80399804 = meter_actimes;
	PTR_DAT_80399808 = (void *)((int)meter_actimes + 3200);
	PTR_DAT_80399810 = meter_sctimes;
	PTR_DAT_80399814 = (void *)((int)meter_sctimes + 6400);
	PTR_DAT_803997ec = meter_rcptimes;
	PTR_DAT_803997f0 = (void *)((int)meter_rcptimes + 3200);
	nop_800BFBF0((void *)((int)ptr + 0x4A60), meter_cmdbuf, 0x100);
	nop_800BFBF0((void *)((int)ptr + 0x4A90), &DWORD_80399838, 1);
	nop_800BFBF0((void *)((int)ptr + 0x4A78), &DWORD_80399834, 1);
}

void diProfStoreFn_8017a0d8(int param1) { // 8017A0D8
	int dVar1;

	dVar1 = DWORD_803997b8;
	if(((DWORD_803997c8 != 1) && (DWORD_803997c8 != 3))
	    && (DWORD_803997c8 != 5)) {
		if(param1 == 0) {
			debugSaveFn_8017a688();
			diFlag_803997d0 = 0;
		} else if(param1 == 1) {
			fn_8017AFD8();
			debugSaveFn_8017a688();
			pMeterPerfdata1 = mmAlloc2(0x286e0, 0xff00ff, "meter:perfdata1");
			pMeterPerfdata2 = (DebugSaveStruct *)mmAlloc2(
			    0x124, 0xff00ff, "meter:perfdata2");
			if((pMeterPerfdata1 == 0) || (pMeterPerfdata2 == 0)) {
				printf("Sorry No DI memory left to store profile.");
				diFlag_803997d0 = 0;
			}
			pMeterPerfdata2->unk118 = 0;
			diFlag_803997d0 = 0;
			nop_800BFC04(0x80000000, 0x9FFFFFFF);
			nop_800BFC08(0x80000000, 0x9FFFFFFF);
			pDll_SaveGame->funcs->func[6]();
		} else if(param1 == 2) {
			fn_8017AFD8();
			debugSaveFn_8017a688();
			pMeterPerfdata1 = mmAlloc2(0x5c, 0xff00ff, "meter:perfdata3");
			pMeterPerfdata2 = (DebugSaveStruct *)mmAlloc2(
			    0x124, 0xff00ff, "meter:perfdata4");
			if((pMeterPerfdata1 == 0) || (pMeterPerfdata2 == 0)) {
				printf("Sorry No DI memory left to store profile.");
				diFlag_803997d0 = 0;
			}
			pMeterPerfdata2->unk118 = 0;
			DWORD_803997c8 = 4;
			diFlag_803997d0 = 0;
			dVar1 = param1;
		} else if(param1 == 3) {
			fn_8017AFD8();
			diFlag_803997d0 = 1;
			DWORD_803997c8 = 5;
			dVar1 = 1;
		} else
			dVar1 = param1;
	}
	DWORD_803997b8 = dVar1;
}

void fn_8017A2B0(void) { // 8017A2B0
	if(DWORD_803997b8 != 0) {
		retM1_afterLoadAsset(&lbl_803904C0, &lbl_803973C0, 1);
		retM1_800BFBFC(&lbl_803904D8, 0, 1);
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

void fn_8017A318(BOOL param_1) { // 8017A318
	DWORD_80399828 = param_1;
}

BOOL fn_8017A320(void) { // 8017A320
	return DWORD_80399828;
}

extern u8 lbl_80399858[8];
void nop_8017a328(void) { // 8017A328
	nop_800BFC0C(&DiProfStruct_8038ba60);
	retM1_afterLoadAsset(&lbl_803904C0, &lbl_80399858, 1);
	retM1_800BFBFC(&lbl_803904D8, 0, 1);
}

void printRspStatus(void) { // 8017A37C reloc
	int iVar2;
	float work;

	nop_800BFC0C(&DiProfStruct_8038ba60);
	for(iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
		rspTimes.times[iVar2]
		    = (DWORD_80390270[iVar2] - DWORD_80390260[iVar2]) & 0xffffff;
	}
	if((fn_8017AFC4() == 0) && (bEnableRspStatusDisplay != 0)) {
		dprintReset();
		dprintSetBgColor(0, 0, 0xff, 0x80);

		work = ((u32)rspTimes.rspTotalTime * 1000.0f) / 62600000;
		diPrintf("Total time. = %2.1fmS", &work);
		// this constant probably is related to CPU speed

		work = ((u32)rspTimes.rdpWorkingTime * 100.0f)
		    / (float)(u32)rspTimes.rspTotalTime;
		diPrintf("RDP working.   = %2.0f%%", &work);

		work = ((u32)rspTimes.rdpPipeNotStalledTime * 100.0f)
		    / (float)(u32)rspTimes.rspTotalTime;
		diPrintf("Pipe not stalled.  = %2.0f%%", &work);

		work = ((u32)rspTimes.tmemLoadingTime * 100.0f)
		    / (float)(u32)rspTimes.rspTotalTime;
		diPrintf("TMEM loading. = %2.0f%%", &work);
	}
	if(DWORD_80399828 != 0) {
		retM1_afterLoadAsset(
		    lbl_803904C0, (undefined *)&lbl_803973C4, 1);
		retM1_800BFBFC((undefined *)&lbl_803904D8, 0, 1);
	}
}

void store_0_to_stackC(int);

void dummiedProfFn_8017a59c(undefined4 param1) { // 8017A59C
	undefined4 *puVar1;

	store_0_to_stackC(param1);
	*(PTR_DAT_803997f8++) = 1;
	*(PTR_DAT_803997f8++) = ret0_800BFC8C();
	*(PTR_DAT_803997f8++) = param1;

	retM1_afterLoadAsset(lbl_803904C0, PTR_DAT_803997f8 - 3, 0);
	if(PTR_DAT_803997fc + 3 >= PTR_DAT_803997f8) {
		PTR_DAT_803997f8 = (undefined4 *)meter_cputimes;
	}
}

void fn_8017A638(void) { // 8017A638
	PTR_DAT_8039981c = meter_gfx;
	DAT_80399844 = 0;
	BYTE_80399848 = 0;
	PTR_DAT_803997e4 = (undefined4 *)meter_times;
	*(PTR_DAT_803997e4++) = ret0_800BFC8C();
}

void debugSaveFn_8017a688(void) { // 8017A688
	Vec *pos;
	uint uVar1;

	if(((pMeterPerfdata1 != 0) && (DWORD_803997c8 != 1))
	    && (DWORD_803997c8 != 3)) {
		/* {@symbol 8012da28} */
		pos = (Vec *)pDll_SaveGame->funcs->func[34]();
		/* {@symbol 8012d9a0} */
		uVar1 = pDll_SaveGame->funcs->func[27]() & 0xFF;

		pMeterPerfdata2->unk0 = 0x124;
		pMeterPerfdata2->unk4 = 0x5c;
		(pMeterPerfdata2->charPos).x = pos->x;
		(pMeterPerfdata2->charPos).y = pos->y;
		(pMeterPerfdata2->charPos).z = pos->z;
		pMeterPerfdata2->unk14 = uVar1;
		pMeterPerfdata2->unk118 = DAT_803997c4;
		pMeterPerfdata2->unk11c = 1;
		pMeterPerfdata2->unk11d = 1;
		pMeterPerfdata2->unk11e = 1;
		pMeterPerfdata2->unk11f = 0;
		pMeterPerfdata2->unk120 = 0;
		pMeterPerfdata2->unk121 = 0;
		pMeterPerfdata2->unk122 = 0;
		pMeterPerfdata2->unk123 = 0;
		memset_(pMeterPerfdata2->codeVersion, 0, 0x40);
		memset_(pMeterPerfdata2->buildDate, 0, 0x40);
		memset_(pMeterPerfdata2->buildAuthor, 0, 0x40);
		memset_(pMeterPerfdata2->fullVersionString, 0, 0x40);
		strcpy(pMeterPerfdata2->codeVersion, CODE_VERSION);
		strcpy(pMeterPerfdata2->buildDate, BUILD_DATE);
		strcpy(pMeterPerfdata2->buildAuthor, BUILD_AUTHOR);
		strcpy(pMeterPerfdata2->fullVersionString, VERSION_STRING);
		if(DWORD_803997b8 == 1) {
			DWORD_803997c8 = 1;
		} else if(DWORD_803997b8 == 2) {
			DWORD_803997c8 = 3;
		}
	}
}
