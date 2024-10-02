#include "dolphin.h"
#include "types.h"
#include "debug.h"
#include "alloc.h"
#include "gbi.h"
#include "n64pad.h"
#include "render.h"
#include "dll.h"
#include "ObjDef.h"
#include "ObjInstance.h"
#include "GameBits.h"
#include "SaveGame.h"
#include "files.h"

//.data (0x802D0D60)
/* 802eadc8 */ const char *buildDate = "03/01/01 16:09";
/* 802eadd8 */ const char *buildName = "ptossell";
/* 802eade3 */ const char *buildVersion = "Version 2.8 14/12/98 15.30 L.Schuneman";
/* 802eae0c */ int tempDllIds[3] = {-1, 0x33, 0x35};
/* 802eae18 */ DLL *tempDlls[3];
/* 802eae24 */ float frameTimes[10];

/* 80321198 */ char _defaultBits[] = " Stolen "; //likely part of larger struct

//.bss (0x80325D20)
/* 80355238 */ PlayerPrevPosition playerPrevPositions[NUM_PLAYER_PREV_POSITIONS];

//.sdata (0x80396700)
/* 80396c14 */ s8 debugMenuPrevState;
/* 80396c15 */ u8 framesThisStep;
/* 80396c16 */ u8 framesLastStep;
/* 80396c18 */ float timeDelta;
/* 80396c1c */ float prevTimeDelta;
/* 80396c20 */ float prevOneOverTimeDelta;
/* 80396c24 */ float prevOneOverTimeDelta2;
/* 80396c28 */ int mapParam_80396c28; //related to gfx dlls
/* 80396c2c */ u8 main_dt;
/* 80396c30 */ float main_fdt;
/* 80396e28 */ RSPState *RSP_pState;
/* 80396E88 */ int DAT_80396E88;
/* 80396E8C */ int N64_RAM_SIZE = 0x800000;
/* 80396E90 */ int unk_80396E90 = 0x80000000;

//.sbss (0x80398240)
/* 803988e0 */ N64Vertex *main_vtx[2];
/* 803988e8 */ N64Vertex *cur_vtx;
/* 803988ec */ Pol *main_pol[2];
/* 803988f4 */ Pol *cur_pol;
/* 803988f8 */ short main_gfx_count;
/* 803988fa */ short main_mtx_count;
/* 803988fc */ short main_vtx_count;
/* 803988fe */ short main_pol_count;
/* 80398900 */ short di_vtx_count;
/* 80398902 */ short di_pol_count;
/* 80398905 */ s8 anyQueuedLoads; //maybe "isMapChangePending"
/* 80398906 */ u8 main_framebuf_idx;
/* 80398907 */ s8 screenBlankFrameCount;
/* 80398909 */ s8 e3MenuFrameCount_80398909; //probably not actually E3 related
/* 8039890a */ u8 DAT_8039890a;
/* 8039890b */ u8 DAT_8039890b;
/* 8039890c */ s8 alSynFlag = 1;
/* 80398910 */ Pol *main_dipol[2];
/* 80398918 */ Pol *cur_di_pol;
/* 8039891c */ N64Vertex *main_divtx[2];
/* 80398924 */ N64Vertex *cur_di_vtx;
/* 80398928 */ u8 no_diprintf;
/* 8039892c */ u32 piLockedFlags;
/* 80398930 */ bool isProgressiveScan;
/* 80398934 */ LoadedDLL *pDll_gplay;
/* 80398938 */ LoadedDLL *pDll_ObjSeq;
/* 8039893c */ LoadedDLL *pDll_checkpoint;
/* 80398940 */ LoadedDLL *pDll_newfog;
/* 80398944 */ LoadedDLL *pDll08;
/* 80398948 */ LoadedDLL *pDll_newstars;
/* 8039894C */ LoadedDLL *pDll0A;
/* 80398950 */ LoadedDLL *pDll_expgfx;
/* 80398954 */ LoadedDLL *pdll_camcontrol;
/* 80398958 */ LoadedDLL *pDll_Dummy04;
/* 8039895c */ LoadedDLL *pDll05;
/* 80398960 */ LoadedDLL *pDll05_2;
/* 80398964 */ LoadedDLL *pDll_modgfx;
/* 80398968 */ LoadedDLL *pDll_projgfx;
/* 8039896c */ LoadedDLL *pDll_0E;
/* 80398970 */ LoadedDLL *pDll_partfx;
/* 80398974 */ LoadedDLL *pDll_objfsa;
/* 80398978 */ LoadedDLL *pDll11;
/* 8039897c */ LoadedDLL *pDll_gametext;
/* 80398980 */ LoadedDLL *pDll_subtitles;
/* 80398984 */ LoadedDLL *pDll_Dummy15;
/* 80398988 */ LoadedDLL *pDll_waterfx;
/* 8039898c */ LoadedDLL *pDll_TrickyWalk;
/* 80398990 */ LoadedDLL *pDll_curve;
/* 80398994 */ LoadedDLL *pDll_RomCurve;
/* 80398998 */ LoadedDLL *pDll_frontend_control;
/* 8039899c */ LoadedDLL *pDLL_47;
/* 803989a0 */ LoadedDLL *pDll1A;
/* 803989a4 */ LoadedDLL *pDll_SaveGame;
/* 803989a8 */ LoadedDLL *pDll36;
/* 803989ac */ LoadedDLL *pDll_modelfx;
/* 803989b0 */ LoadedDLL *pDLL_48;
/* 803989b4 */ LoadedDLL *pDll_baddieControl;
/* 803989b8 */ LoadedDLL *pDll_partfx1F;
/* 803989bc */ LoadedDLL *pDll_n_POST;
/* 803989c0 */ LoadedDLL *pDll_projLib;
/* 803989c4 */ int frameTimeArrayIdx;
/* 803989c8 */ u32 rspFramesLastStep;
/* 803989cc */ BOOL bEnablePartdev;
/* 803989d0 */ bool DAT_803989d0;
/* 803989d4 */ SaveGame *pLastSavedGame;
/* 803989d8 */ BitTableEntry *bitTable;
/* 803989dc */ s16 numGameBits;
/* 803989E0 */ int playerPrevPosidx;
/* 803989E4 */ int frameCount_playerPosLog;
/* 803989e8 */ Mtx44 *mtx;
/* 803989ec */ Mtx44 *main_mtx[2];
/* 803989f4 */ Gfx *cur_gfx;
/* 803989f8 */ Gfx *gfx;
/* 803989fc */ Gfx *main_gfx[2];
/* 80398e44 */ UNKTYPE *currentScreen;
/* 80398e48 */ UNKTYPE *otherZbuf;
/* 803997d0 */ int diFlag_803997d0;
/* 803999d0 */ int DAT_803999d0;
/* 80399a74 */ s8 DAT_80399a74;

ObjInstance* objGetMain(void);
BOOL videoBackendRun(void);
bool checkSomeDebugFlags_8017c4f8(); //8017c4f8
u16 getEnabledButtonsHeld(int pad);
void nop_8009FA00(Gfx **buf);
int getDebugMenuState(void);
void objUpdateFn_80081f94(void);
void objUpdateFn_80082238(void);
void updateEnvironment(BOOL bDontDoAnything);
void setShowCommandMenu(s8 param1); //maybe just blankScreen()
void FUN_8016eb9c(undefined param_1,uint param_2);
void objUpdateFn_800823dc(void);
void updatePlayerPosLog(void);
void gfxDllFn_80073b44(void);
void camUpdateFn_8018a9e0(void);
void camUpdateFn_8018ae34(void);
void trackIntersect(void);
void playerUpdateFn_800ae404(void);
void doPendingMapLoads(void);
void updateObjMtxs(void);
void Trackdraw(Gfx **rspCmdBuf,Mtx44 **mtxBuf,N64Vertex **vtxBuf,
    Pol **polBuf, N64Vertex **diVtx, Pol **diPol);
void cameraFn_800698b4(Gfx **cmdBuf,Mtx44 **mtxBuf);
void updateViewMatrix(void);
void callGfxFuncPtr3(Gfx **cmdBuf,Mtx44 **mtxBuf,
    N64Vertex **vtxBuf,Pol **param_4);
void gxResetScissor(Gfx **cmdBuf);
void disableDebugObjSequencer(void);
void cutsceneExit(void);
undefined4 piRomFreeLevel(int map,uint flags);
void objEditUpdate(void);
BOOL DLL_free(LoadedDLL *dll);
void clearPlayerPosLog(void);

void init(void);
void showExpansionPakNeededScreen(void);
void bootCheckStack(void) { //80068dfc
    //might be checkReset
}

void gameLoop(void);
void setFrameTime(OSTime);
void diProfReset(void);
void nop_8017a328(void);
void mainLoopGxSetupFn_8009e320(void);
void RSP_segSetBase(Gfx**, int, void*);
void freakFn_800a58d0(Gfx**, int);
void FUN_8018f55c(void);
void RSP_rcpInitSp(void);
void RSP_rcpInitDp(void);
int getRenderFlags(void);
BOOL isCloudy(void);
void nop_8009E5EC(Gfx**, Mtx44**, u8);
BOOL isHeapDebugDisplayEnabled();
void drawHeapInfo(Gfx**, Mtx44**, N64Vertex**);
void perfFn_8018f5cc(void);
int mainRender(Gfx*, Mtx44*, int);
Gfx* rspFn_8017c278(void);
void listCodeRender(Gfx*);
int gxMaybeFlush(void);
void joyRead(void);
void amAudioTick(void);
void processObjDeleteList(void);
void checkHeaps(void);
void printRspStatus(void);
void strBufFn_8018f2f8(void);
BOOL isFrameTimeDisplayEnabled(void);
u64 getFrameTime(void);
void dprintSetPos(int, int);
void dprintSetColor(u8, u8, u8, u8);
void dprintSetBgColor(u8, u8, u8, u8);
void diPrintf(const char*, ...);
BOOL shouldShowMemUsed(void);
BOOL shouldShowTexCacheUsed(void);
void FUN_800a58bc(int*, int*, int*);
s32 viFrameSync(int);
void doQueuedLoads(void);
u32 getEnabledButtonsPressed(int);
void diMenu_main(void);
void FUN_8018f8dc(void);
u32 n64GetEnabledButtonsPressed(int);

void OSInit(void);
void initBsod(void);
void dvdInit(void);
void viInit(void);
void piInit(void);
void waitNextFrame(void);
void padUpdate(PADStatus *pad);
void __VIInit(uint param1);
void LCEnable(void);
void initHeaps(void);
void audioInit(void);
void diProfReset(void);
void allocRzipHeaderBuf(void);
void FUN_800777d8(void);
void perfInitFn_80179ec0(void);
void initPerfMon(void);
void nop_800C850C(UNKTYPE *param_1,UNKTYPE *param_2,
    int param_3,u8 param_4, int param_5);
void initDataFiles(void);
void allocFrameBuffers(void);
int padSetup(void);
void texInitTextures(void);
void trkBlocksInit(void);
void initModels(void);
void initDllsTab(void);
void Object_initObjects(void);
void debugPrintInit(void);
void initModLines(void);
void initEnv(void);
void initFootVol(void);
void Font_init(void);
void gfxDebugInit(void);
void FUN_80081994(void);
void initCard(void);
void playerInitFuncPtrs_(void);
void diMenuInit(void *callback, int);
void globalMapInit(void);
void initBitTable(void);
void diCreateDisplayList(void);
void debugMenuReset(void);
void diMenu_main(void);
void diProfPrint(uint param1);
void lightMapFn_800a32dc(void);
void videoInitFn_8009e5f0(void *unused, int bIsProgScan);
void enterMainDebugMenu(void);

void mainChangeMap(int mapNo,uint setupPoint,int playerNo,
int param4);
void setDebugMenuState(int state);
void mapDoDebugSetupPoint(void);
int rand(void);

GXRenderModeObj gxRenderModeProgScan = { //802d8d88
    /* viTVmode; */ VI_TVMODE_NTSC_PROG,
    /* fbWidth; */ 640,
    /* efbHeight; */ 480,
    /* xfbHeight; */ 480,
    /* viXOrigin; */ 40,
    /* viYOrigin; */ 0,
    /* viWidth; */ 640,
    /* viHeight; */ 480,
    /* xFBmode; */ VI_XFBMODE_SF,
    /* field_rendering; */ 0,
    /* aa; */ 0,
    /* sample_pattern[12][2]; */
        6,6,6,6,6,6,
        6,6,6,6,6,6,
        6,6,6,6,6,6,
        6,6,6,6,6,6,
    /* vfilter[7]; */
        0x00, 0x00, 0x15, 0x16, 0x15, 0x00, 0x00,
};
GXRenderModeObj gxRenderModeInterlaced = { //802d8e3c
    /* viTVmode; */ VI_TVMODE_NTSC_INT,
    /* fbWidth; */ 640,
    /* efbHeight; */ 480,
    /* xfbHeight; */ 480,
    /* viXOrigin; */ 40,
    /* viYOrigin; */ 0,
    /* viWidth; */ 640,
    /* viHeight; */ 480,
    /* xFBmode; */ VI_XFBMODE_DF,
    /* field_rendering; */ 0,
    /* aa; */ 0,
    /* sample_pattern[12][2]; */
        6,6,6,6,6,6,
        6,6,6,6,6,6,
        6,6,6,6,6,6,
        6,6,6,6,6,6,
    /* vfilter[7]; */
        0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08,
};
GXRenderModeObj *curGxRenderMode; //80398b78
u8 DAT_80352f30[0x7EF]; //80352f30, unk type
s8 padSetupOk = -1; //80398908
s8 debugMenuState; //80398904


//a copy of this exists in the binary even though
//it's also inlined in the headers
#define OS_GQR_F32 0x0000
#define OS_GQR_U8 0x0004
#define OS_GQR_U16 0x0005
#define OS_GQR_S8 0x0006
#define OS_GQR_S16 0x0007
void OSInitFastCast(void) {
  asm {
        li      r3, OS_GQR_U8
        oris    r3, r3, OS_GQR_U8
        mtspr   GQR2, r3

        li      r3, OS_GQR_U16
        oris    r3, r3, OS_GQR_U16
        mtspr   GQR3, r3

        li      r3, OS_GQR_S8
        oris    r3, r3, OS_GQR_S8
        mtspr   GQR4, r3

        li      r3, OS_GQR_S16
        oris    r3, r3, OS_GQR_S16
        mtspr   GQR5, r3
  }
}

void init(void) {
    UNKTYPE *unk_80352f30;
    int iVar3;
    PADStatus pad[4];
    struct {
        uint _00;
        uint _04;
    } unk50;

    unk_80352f30 = (UNKTYPE*)DAT_80352f30;
    unk50._04 = 321123;
    unk50._00 = 0;
    OSInitFastCast();
    OSInit();
    initBsod();
    dvdInit();
    viInit();
    piInit();
    waitNextFrame();
    waitNextFrame();
    padUpdate(pad);
    if(isProgressiveScan) {
        __VIInit(2);
        curGxRenderMode = &gxRenderModeProgScan;
    }
    else {
        curGxRenderMode = &gxRenderModeInterlaced;
    }
    viInit();
    piInit();
    LCEnable();
    initHeaps();
    audioInit();
    diProfReset();
    allocRzipHeaderBuf();
    FUN_800777d8();
    perfInitFn_80179ec0();
    initPerfMon();

    if(DAT_80396E88 == 0) iVar3 = 0x10;
    else if(DAT_80396E88 == 2) iVar3 = 0x1e;
    else iVar3 = 2;
    nop_800C850C(unk_80352f30,
        //XXX unknown struct type
        (void*)((u32)unk_80352f30+0x2308),0xd,iVar3,1);

    initDataFiles();
    videoInitFn_8009e5f0(unk_80352f30,(uint)isProgressiveScan);
    allocFrameBuffers();
    main_framebuf_idx = 0;
    gfx = main_gfx[main_framebuf_idx];
    padSetupOk = padSetup();
    texInitTextures();
    trkBlocksInit();
    initModels();
    initDllsTab();
    Object_initObjects();
    debugPrintInit();
    initModLines();
    initEnv();
    initFootVol();
    Font_init();
    gfxDebugInit();
    FUN_80081994();
    initCard();
    playerInitFuncPtrs_();
    debugMenuState = 1;
    diMenuInit(enterMainDebugMenu, 0);
    globalMapInit();
    if(N64_RAM_SIZE != 0x800000) {
        pDll05 = runlinkDownloadCode(5,0x24);
        pDll05_2 = pDll05;
        pDll_subtitles = runlinkDownloadCode(0x14,6);
        pDll_SaveGame = runlinkDownloadCode(0x1c,0x2f);
        pDll_gplay = runlinkDownloadCode(0x1b,4);
    }
    else {
        pdll_camcontrol = runlinkDownloadCode(1,0xf);
        pDll_ObjSeq = runlinkDownloadCode(2,0x17);
        pDll_waterfx = runlinkDownloadCode(0x16,8);
        pDll11 = runlinkDownloadCode(0x11,0x16);
        pDll_checkpoint = runlinkDownloadCode(3,0x1e);
        pDll_gplay = runlinkDownloadCode(0x1b,5);
        pDll_curve = runlinkDownloadCode(0x18,0x10);
        pDll_newfog = runlinkDownloadCode(7,0xf);
        pDll08 = runlinkDownloadCode(8,0xc);
        pDll_newstars = runlinkDownloadCode(9,8);
        pDll0A = runlinkDownloadCode(10,3);
        pDll_expgfx = runlinkDownloadCode(0xb,10);
        pDll_Dummy04 = runlinkDownloadCode(4,0xd);
        pDll05 = runlinkDownloadCode(5,0x24);
        pDll05_2 = pDll05;
        pDll_modgfx = runlinkDownloadCode(0xc,10);
        pDll_projgfx = runlinkDownloadCode(0xd,0xc);
        pDll_0E = runlinkDownloadCode(0xe,8);
        pDll_partfx = runlinkDownloadCode(0xf,3);
        pDll_objfsa = runlinkDownloadCode(0x10,2);
        pDll_gametext = runlinkDownloadCode(0x13,3);
        pDll_subtitles = runlinkDownloadCode(0x14,5);
        pDll_Dummy15 = runlinkDownloadCode(0x15,7);
        pDll_TrickyWalk = runlinkDownloadCode(0x17,7);
        pDll_RomCurve = runlinkDownloadCode(0x19,0x26);
        pDll_frontend_control = runlinkDownloadCode(0x46,7);
        pDll1A = runlinkDownloadCode(0x1a,9);
        pDll_SaveGame = runlinkDownloadCode(0x1c,0x24);
        pDll36 = runlinkDownloadCode(0x36,10);
        pDll_modelfx = runlinkDownloadCode(0x1d,6);
        pDll_baddieControl = runlinkDownloadCode(0x1e,6);
        pDll_partfx1F = runlinkDownloadCode(0x1f,0x16);
        pDll_n_POST = runlinkDownloadCode(0x37,2);
        pDll_projLib = runlinkDownloadCode(0x34,0xc);
        pDll_modelfx->funcs->_4.func1();
    }
    initBitTable();
    alSynFlag = 1;
    gDPFullSync(gfx++);
    gSync(gfx++, 0);
    diCreateDisplayList();
    debugMenuReset();
    if (N64_RAM_SIZE == 0x800000) {
        doQueuedLoads();
    }
    diMenu_main();
    diProfPrint(2);
    lightMapFn_800a32dc();
}

int main(int argc, char **argv) {
  if (argc > 1 && strcmp(argv[1], "prog") == 0u) {
    //@bug this should probably be set to true
    isProgressiveScan = false;
  }
  init();
  while (true) {
    diProfReset();
    if (N64_RAM_SIZE != 0x800000)
      showExpansionPakNeededScreen();
    else
      gameLoop();
    bootCheckStack();
  }
  return 0;
}

inline float getFrames(s32 v) { return v / 65536.0f; }
inline float* getPastFrameTimes() {
    return frameTimes;
}
inline void doFrameTimeDisplay() {
    u64 time;
    int ii;
    int fps;
    float fpsFlt;
    float ftime;

    time = getFrameTime();
    ftime = getFrames(time / 12);
    //I really hope this is fake.
    getPastFrameTimes()[frameTimeArrayIdx++] = ftime;
    if (frameTimeArrayIdx == 10) frameTimeArrayIdx = 0;

    fpsFlt = 0.0f;
    for (ii = 0; ii < 10; ii++) {
        fpsFlt += getPastFrameTimes()[ii];
    }
    fpsFlt = 600.0f / fpsFlt;
    fps = fpsFlt;

    dprintSetPos(0x1e, 0x14);
    dprintSetColor(0xff, 0xff, 0xff, 0xff);
    dprintSetBgColor(0, 0, 0, 0x80);
    diPrintf("\t%f ", ftime);
    diPrintf(" - %d ", framesThisStep);
    diPrintf("- %dfps\n", fps);
}
inline void updateTimeDelta2()  {
    framesThisStep = viFrameSync(0);
    if (framesThisStep > 6) framesThisStep = 6;
    timeDelta = framesThisStep;
    prevOneOverTimeDelta = 1.0f / timeDelta;
    framesLastStep = framesThisStep;
    prevTimeDelta = timeDelta;
    prevOneOverTimeDelta2 = 1.0f / timeDelta;
}
inline void updateTimeDelta() {
    if ((uint)main_dt != framesThisStep) {
        printf("main_dt has been changed!\n");
    }
    if (main_fdt != timeDelta) {
        printf("main_fdt has been changed!\n");
    }
    updateTimeDelta2();
}

void gameLoop(void) {
    int uVar3;
    int uVar13;
    int local_50; //0x08
    int local_54; //0x0c
    int local_58; //0x10

    setFrameTime(0ull);
    diProfReset();
    nop_8017a328();
    mainLoopGxSetupFn_8009e320();
    main_framebuf_idx ^= 1;
    cur_gfx = main_gfx[main_framebuf_idx];
    mtx = main_mtx[main_framebuf_idx];
    cur_vtx = main_vtx[main_framebuf_idx];
    cur_pol = main_pol[main_framebuf_idx];
    gfx = cur_gfx;
    cur_di_vtx = main_divtx[main_framebuf_idx];
    cur_di_pol = main_dipol[main_framebuf_idx];
    RSP_segSetBase(&gfx, 0, (void*)0x80000000);
    RSP_segSetBase(&gfx, 1, currentScreen);
    RSP_segSetBase(&gfx, 2, otherZbuf);
    freakFn_800a58d0(&gfx, framesThisStep);
    FUN_8018f55c();
    RSP_rcpInitSp();
    RSP_rcpInitDp();
    if (RSP_pState->bNeedPipeSync != false) {
        RSP_pState->bNeedPipeSync = false;
        gDPPipeSync(gfx++);
    }
    gDPSetDepthImage(gfx++, 0x2000000);
    uVar13 = 2;
    if(!getRenderFlags()) uVar13 = 0;
    else if (!isCloudy()) uVar13 |= 1;
    uVar13 |= 1; //wat
    nop_8009E5EC(&gfx, &mtx, uVar13);
    voxDataFn_8006d29c();
    gameUpdate();
    updateViewport();
    nop_80077B60();
    loadTableFiles_();
    debugDoPad1Toggles();
    nop_800671C8();
    if (isHeapDebugDisplayEnabled()) {
        drawHeapInfo(&gfx, &mtx, &cur_vtx);
    }
    gDPFullSync(gfx++);
    gSync(gfx++, 0);
    perfFn_8018f5cc();
    mainRender(main_gfx[main_framebuf_idx], mtx, 0);
    listCodeRender(rspFn_8017c278());
    pDll_gplay->funcs->func[0](&gfx, &mtx, &cur_vtx);
    pDll_Dummy15->funcs->func[5](&gfx);
    gxMaybeFlush();
    joyRead();
    amAudioTick();
    processObjDeleteList();
    checkHeaps();
    printRspStatus();
    strBufFn_8018f2f8();
    if (diFlag_803997d0) rspFramesLastStep = (uint)framesThisStep;
    if (isFrameTimeDisplayEnabled()) doFrameTimeDisplay();
    if (shouldShowMemUsed()) {
        dprintSetPos(0x28, 0xd4);
        dprintSetColor(0xff, 0xff, 0xff, 0xff);
        dprintSetBgColor(0, 0, 0, 0x80);
        diPrintf("%dk\n", FUN_8007c54c(0) >> 10);
    }
    if (shouldShowTexCacheUsed()) {
        dprintSetPos(0x1e, 0xe0);
        dprintSetColor(0xff, 0xff, 0xff, 0xff);
        dprintSetBgColor(0, 0, 0, 0x80);
        FUN_800a58bc(&local_50, &local_54, &local_58);
        diPrintf("texcache: %d %d/%d\n", local_50, local_54 >> 10,
            local_58 >> 10);
    }
    uVar3 = gfx - main_gfx[main_framebuf_idx];
    if (uVar3 > MAIN_GFX_SIZE) {
        OSPanic("main.c", 937, NULL);
        //@unreachable
        printf("Warning: Gfx-list overflow by %d!\n", uVar3 - MAIN_GFX_SIZE);
    }
    //@bug compare should be main_gfx_count > uVar3?
    if (uVar3 > main_gfx_count) main_gfx_count = uVar3;

    uVar3 = mtx - main_mtx[main_framebuf_idx];
    if (uVar3 > MAIN_MTX_SIZE) {
        printf("Warning: Mtx-list overflow by %d!\n", uVar3 - MAIN_MTX_SIZE);
    }
    if (uVar3 > main_mtx_count) main_mtx_count = (short)uVar3;

    uVar3 = cur_vtx - main_vtx[main_framebuf_idx];
    if (uVar3 > MAIN_VTX_SIZE) {
        printf("Warning: Vtx-list overflow by %d!\n", uVar3 - MAIN_VTX_SIZE);
    }
    if (uVar3 > main_vtx_count) main_vtx_count = (short)uVar3;

    uVar3 = cur_pol - main_pol[main_framebuf_idx];
    if (uVar3 > MAIN_POL_SIZE) {
        printf("Warning: Pol-list overflow by %d!\n", uVar3 - MAIN_POL_SIZE);
    }
    if (uVar3 > main_pol_count) main_pol_count = (short)uVar3;

    uVar3 = cur_di_vtx - main_divtx[main_framebuf_idx];
    if (uVar3 > DI_VTX_SIZE) {
        printf("Warning: DI-vtx-list overflow by %d!\n", uVar3 - DI_VTX_SIZE);
    }
    if (uVar3 > di_vtx_count) di_vtx_count = (short)uVar3;

    uVar3 = cur_di_pol - main_dipol[main_framebuf_idx];
    if (uVar3 > DI_POL_SIZE) {
        printf("Warning: DI-pol-list overflow by %d!\n", uVar3 - DI_POL_SIZE);
    }
    if (uVar3 > di_pol_count) di_pol_count = (short)uVar3;

    updateTimeDelta();
    doQueuedLoads();
    if(getEnabledButtonsPressed(2) & PAD_TRIGGER_L) {
        no_diprintf = 1 - no_diprintf;
        printf("no_diprintf %d\n", no_diprintf);
    }
    main_dt = framesThisStep;
    main_fdt = timeDelta;
    if (diFlag_803997d0 != 0) {
        framesThisStep = rspFramesLastStep;
    }
    diMenu_main();
    FUN_8018f8dc();
    if ((n64GetEnabledButtonsPressed(3) & N64_BUTTON_Z) != 0) {
        bEnablePartdev = 1 - bEnablePartdev;
    }
    if (bEnablePartdev) {
        DLL_free(pDll_objfsa);
        pDll_objfsa = runlinkDownloadCode(0x10, 2);
        diPrintf("PARTDEV\n");
    }
}

void showExpansionPakNeededScreen(void) { //800789a0
    mainLoopGxSetupFn_8009e320();
    mainRender(main_gfx[main_framebuf_idx], mtx, 0);
    main_framebuf_idx ^= 1;
    gfx = main_gfx[main_framebuf_idx];
    mtx = main_mtx[main_framebuf_idx];
    cur_vtx = (N64Vertex *)main_vtx[main_framebuf_idx];
    cur_pol = main_pol[main_framebuf_idx];
    RSP_segSetBase(&gfx, 0, (void*)0x80000000);
    RSP_segSetBase(&gfx,1,currentScreen);
    RSP_segSetBase(&gfx,2,otherZbuf);
    RSP_rcpInitSp();
    RSP_rcpInitDp();
    if (RSP_pState->bNeedPipeSync != false) {
        RSP_pState->bNeedPipeSync = false;
        gDPPipeSync(gfx++);
    }
    gDPSetDepthImage(gfx++, 0x2000000);
    videoBackendRun();
    callGfxFuncPtr3(&gfx, &mtx, &cur_vtx, &cur_pol);
    nop_80077B60();
    pDll_gplay->funcs->func[0](&gfx, &mtx, &cur_vtx);
    gDPFullSync(gfx++);
    gSync(gfx++, 0);
    joyRead();
    gxMaybeFlush();
    checkHeaps();
    updateTimeDelta2();
}

int gameUpdate(void) { //80078BBC
    u16 bPressed;
    ObjInstance *player;

    player = objGetMain();
    pDll_ObjSeq->funcs->func[19]();
    pDll_Dummy15->funcs->func[4]();
    if(videoBackendRun() == FALSE) {
        int bHeld = getEnabledButtonsHeld(0);
        bPressed = getEnabledButtonsPressed(0);
        if(screenBlankFrameCount) nop_8009FA00(&gfx);
        if(!screenBlankFrameCount) {
            if(getDebugMenuState() == 1) objUpdateFn_80081f94();
            else if (FUN_8017afc4() == 0) objUpdateFn_80081f94();
            else objUpdateFn_80082238();
            updateEnvironment(FALSE);

            //@bug redundant check
            if(e3MenuFrameCount_80398909 == 0
            && e3MenuFrameCount_80398909 == 0) {
                if((screenBlankFrameCount == 0)
                && ((bPressed & PAD_BUTTON_START) != 0)) {
                    player = objGetMain();
                    if (player
                    && ((player->flags_0xb0 & ObjInstance_FlagsB0_SeqActive) == 0)) {
                        setShowCommandMenu(2);
                        FUN_8016eb9c(5,1);
                        screenBlankFrameCount = 1;
                    }
                }
            }
            pDll_SaveGame->funcs->func[26](); //updateTimes
        }
        else objUpdateFn_800823dc();
        if(!screenBlankFrameCount) updatePlayerPosLog();
        gfxDllFn_80073b44();
        camUpdateFn_8018a9e0();
        camUpdateFn_8018ae34();
        trackIntersect();
        playerUpdateFn_800ae404();
        doPendingMapLoads();
        updateObjMtxs();
        pDll_Dummy04->funcs->func[13]();
        if(screenBlankFrameCount == 0) {
            if(ret0_8017C358() == 0) {
                Trackdraw(&gfx,&mtx,&cur_vtx,
                    &cur_pol,&cur_di_vtx,&cur_di_pol);
                cameraFn_800698b4(&gfx,&mtx);
                updateViewMatrix();
                if (checkSomeDebugFlags_8017c4f8()) {
                    if (DAT_803999d0 == 0) {
                        if (DAT_80399a74 == 0) {
                            pDll_Dummy04->funcs->func[14](
                                &gfx,&cur_di_vtx,&cur_di_pol); //checkpoint related
                        }
                        pDll_RomCurve->funcs->func[41](
                            &gfx,&cur_di_vtx,&cur_di_pol);
                        pDll_checkpoint->funcs->func[15](
                            &gfx,&cur_di_vtx,&cur_di_pol,&mtx);
                    }
                }
            }
            if (getDebugMenuState() == 1) {
                bHeld &= ~(PAD_TRIGGER_Z|PAD_TRIGGER_R|PAD_TRIGGER_L);
            }
        }
        pDll_gametext->funcs->func[1](&gfx); //free
        callGfxFuncPtr3(&gfx,&mtx, &cur_vtx, &cur_pol);
        gxResetScissor(&gfx);
        if((e3MenuFrameCount_80398909 -= framesThisStep) < 0) {
            e3MenuFrameCount_80398909 = 0;
        }
        if(bHeld == (PAD_TRIGGER_R|PAD_TRIGGER_L)) {
            disableDebugObjSequencer();
            cutsceneExit();
            piRomFreeLevel(0,0x80000000);
            debugMenuReset();
        }
        objEditUpdate();
    }
}

void mapChangeFn_80078e98(void) { //80078e98
    nop_800BF4AC(14, 0, 0);
    FUN_800a6ffc(0);
    setDrawTrackSky(FALSE);
    pDll05->funcs->func[5](3);
    pDll05->funcs->func[5](0);
    pDll05->funcs->func[5](1);
    pDll_Dummy15->funcs->func[3](); //free
    cutsceneExit();
    mainChangeMap(1,0,1,0xffffffff);
}

void doQueuedLoads(void) { //80078f48
    if (anyQueuedLoads) {
        OSReport("$$$$$  CHANGEMAP \n");
        freeFn_8007bd28(0);
        if (DAT_803989d0 != false) {
            setColor_8009e5d0(0,0,0);
            nop_800C8504();
            unloadMap();
            gfx = main_gfx[main_framebuf_idx];
            gDPFullSync(gfx++);
            gSync(gfx++, 0);
        }
        anyQueuedLoads = false;
        freeFn_8007bd28(0);
        FUN_80068e00();
        if (-1 < mapParam_80396c28) {
            gfxDllFn_8007399c(mapParam_80396c28);
            mapParam_80396c28 = -1;
        }
        beginLoadingMap();
        if (pDll_waterfx) {
            pDll_waterfx->funcs->func[1](1);
        }
        freeFn_8007bd28(2);
        DAT_803989d0 = true;
    }
}

void mainChangeMap(int mapNo,uint setupPoint,int playerNo,
int param4) { //80079068
    CharPos *playerPos;

    OSReport("mainChangeMap(%d,%d,%d)\n",mapNo,setupPoint,playerNo);
    setDebugMenuState(0);
    if(playerNo < 0) playerNo = 0;
    mapDoDebugSetupPoint();
    clearPlayerPosLog();
    pDll_modelfx->funcs->_4.func1();
    pDll_SaveGame->funcs->func[0](0); //newgame
    pDll_SaveGame->funcs->func[28](playerNo & 0xFF); //setPlayerNo
    playerPos = (CharPos*)pDll_SaveGame->funcs->func[34](); //getCurCharPos
    mapLoadFn_800ad69c(mapNo,setupPoint,
        &playerPos->pos.x,&playerPos->pos.y,&playerPos->pos.z,
        &playerPos->layer);
    /* func09 */
    //(**(code **)(*(int *)pDll_SaveGame + 0x1c))
    pDll_SaveGame->funcs->func[5](
        playerPos, 0, 0, playerPos->layer);
    if (mapGetPlayerObjType(NULL) != ObjDefNo_Sabre) {
        playerPos->pos.x = 0.0f;
        playerPos->pos.y = 0.0f;
        playerPos->pos.z = 0.0f;
    }
    anyQueuedLoads = true;
    mapParam_80396c28 = param4;
}

void mapLoadByCoords(float x,float y,float z) { //800791AC
    setDebugMenuState(0);
    mapSetup(x,y,z);
    clearPlayerPosLog();
    anyQueuedLoads = true;
}

void newGameAtPos(float x, float y, float z,
volatile uint playerNo) { //800791F8
    Vec pos;

    pos.x = x;
    pos.y = y;
    pos.z = z;
    setDebugMenuState(0);
    pDll_SaveGame->funcs->func[0](0); //newgame
    pDll_SaveGame->funcs->func[28](playerNo & 0xFF); //setPlayerNo
    pDll_SaveGame->funcs->func[5](&pos, 0, 0, 0);
    pDll_SaveGame->funcs->func[6]();
}

void mapReload(void) { //800792B0
    mapReloadWithFadeout();
    anyQueuedLoads = true;
}

void debugMenuReset(void) { //800792D8
    nop_800BF4F8();
    mainChangeMap(1,0,0,0);
    setDebugMenuState(1);
}

int getDebugMenuState(void) { //80079314
    return debugMenuState;
}

void setDebugMenuState(int state) { //80079320
    debugMenuState = state;
}

void diMenu_main(void) { //8007932C
    if (debugMenuState != debugMenuPrevState) {
        switch(debugMenuState) {
            case 1: enterMainDebugMenu(); break;
            case 2: diMenuFn_maybeReset(); break;
            default: debugMenuResetFn_8017c4d4();
        }
    }
    debugMenuPrevState = debugMenuState;
}

int getScreenBlankFrameCount(void) { //8007939C
    return screenBlankFrameCount;
}

void cutsceneExit(void) { //800793A8
    screenBlankFrameCount = 0;
}

void allocFrameBuffers(void) { //800793B4 string reloc
    main_gfx[0] = (Gfx *)mmAlloc(160000,LISTS_COL,"main:gfx");
    main_gfx[1] = main_gfx[0] + 10000;
    main_mtx[0] = (Mtx44 *)mmAlloc(0x19000,LISTS_COL,"main:mtx");
    main_mtx[1] = main_mtx[0] + 800;
    main_pol[0] = (Pol *)mmAlloc(32000,LISTS_COL,"main:pol");
    main_pol[1] = main_pol[0] + 1000;
    main_vtx[0] = (N64Vertex *)mmAlloc(32000,LISTS_COL,"main:vtx");
    main_vtx[1] = main_vtx[0] + 1000;
    main_dipol[0] = (Pol *)mmAlloc2(96000,1,"main:dipol");
    main_dipol[1] = main_dipol[0] + 3000;
    main_divtx[0] = (N64Vertex *)mmAlloc2(0xe100,1,"main:divtx");
    main_divtx[1] = main_divtx[0] + 0x708;
}

void setE3MenuFrameCount(s8 param1) { //800794D4
    e3MenuFrameCount_80398909 = param1;
}

bool TriggSetpShouldUnload(void) { //800794DC
    //deterines whether TriggSetp should unload after activating.
    //in final, returns 1
    return 0;
}

UNKTYPE* fn_800794E4(void) { //800794E4
    return &DAT_80352f30;
}

void initBitTable(void) { //800794F0
    //load BITTABLE.BIN which defines the GameBits struct
    loadAsset_file((void*)&bitTable,FILE_BITTABLE_BIN);
    //@bug should be >> 2, as entries are 4 bytes wide
    //this bug persists to final versions (maybe they were
    //2 bytes wide before?)
    numGameBits = getLoadedDataFileSize(FILE_BITTABLE_BIN) >> 1;
    pLastSavedGame = (SaveGame*)pDll_SaveGame->funcs->func[32]();
}

void mainSetBits(int bitNo,uint value) { //80079544 regalloc
    u32 mask;
    u8 *bits;
    u32 mask2;
    s32 offsBit;
    int ii;
    u32 iBit;
    s32 nBits;
    u32 iByte;

    //bits = (u8*)&_defaultBits;
    if (((bitNo != GAMEBIT_ALWAYS_1)
    && (bitNo != GAMEBIT_ALWAYS_0)) && (bitNo != -1)) {
        if ((bitNo < 0) || (bitNo >= numGameBits)) {
            printf("mainSetBits: Out of range %d/%d.\n",
                bitNo, numGameBits);
        }
        else {
            switch(bitTable[bitNo].flags >> GAMEBIT_FLAG_TABLE_IDX_SHIFT) {
                case 0: bits = pLastSavedGame->gameBits0; break;
                case 1: bits = pLastSavedGame->gameBits1; break;
                case 2: bits = pLastSavedGame->gameBits2; break;
                case 3: bits = pLastSavedGame->gameBits3; break;
            }
            if(bitTable[bitNo].flags & GAMEBIT_FLAG_HAS_HINT_TEXT) {
                pDll_modelfx->funcs->func[0](
                    bitTable[bitNo].hintTextIdx);
            }
            offsBit = bitTable[bitNo].iBit; //bit offset
            nBits = (bitTable[bitNo].flags & GAMEBIT_FLAG_MASK_SIZE) + 1;
            mask = 1;
            for(ii = offsBit; ii < offsBit+nBits; ii++) {
                iBit  = ii & 7;
                iByte = ii >> 3;
                mask2 = 1 << iBit;
                if(value & mask) bits[iByte] |= mask2;
                else bits[iByte] &= ~mask2;
                mask <<= 1;
            }
        }
    }
}

uint mainGetBit(int bitNo) { //800796D8
    uint mask;
    uint result;
    u32 mask2;
    s32 offsBit;
    u32 iByte;
    u8 *bits;
    int ii;
    u32 mask3;
    s32 nBits;

    if(bitNo == GAMEBIT_ALWAYS_1) return 1;
    if(bitNo == GAMEBIT_ALWAYS_0) return 0;
    if(bitNo == -1) return 0;
    if(bitNo < 0 || bitNo >= numGameBits) return 0;

    switch(bitTable[bitNo].flags >> GAMEBIT_FLAG_TABLE_IDX_SHIFT) {
        case 0: bits = pLastSavedGame->gameBits0; break;
        case 1: bits = pLastSavedGame->gameBits1; break;
        case 2: bits = pLastSavedGame->gameBits2; break;
        case 3: bits = pLastSavedGame->gameBits3; break;
    }
    offsBit =  bitTable[bitNo].iBit; //bit offset
    nBits   = (bitTable[bitNo].flags & GAMEBIT_FLAG_MASK_SIZE) + 1;
    result  = 0;
    mask    = 1;
    for(ii = offsBit; ii < offsBit+nBits; ii++) {
        mask2 = (ii & 7);
        iByte = ii >> 3;
        mask3 = (1 << mask2);
        if(bits[iByte] & mask3) result |= mask;
        mask <<= 1;
    }
    return result;
}

uint mainIncBit(int bitNo) { //8007980C
    int uVar1;
    int vMax;

    uVar1 = mainGetBit(bitNo) + 1;
    vMax = 1 << ((bitTable[bitNo].flags & GAMEBIT_FLAG_MASK_SIZE)+1);
    if(uVar1 < vMax) mainSetBits(bitNo,uVar1);
    else uVar1 -= 1;
    return uVar1;
}


uint mainDecBit(int bitNo) { //80079880
    int uVar1;

    uVar1 = mainGetBit(bitNo);
    if(uVar1) {
        mainSetBits(bitNo, --uVar1);
        return uVar1;
    }
    else return 0;
}


int debugSetupPoint; //80399904
int debugSetupPointMapNo; //80399924

void mapDoDebugSetupPoint(void) { //800798D8
    switch(debugSetupPointMapNo) {
        case 0x9: break;
        case 0xE:
            if(debugSetupPoint >= 2) {
                mainSetBits(0x2b2,1);
            }
            if(debugSetupPoint >= 3) {
                mainSetBits(0x2b9,1);
                mainSetBits(0x2c5,1);
            }
            if(debugSetupPoint >= 4 && debugSetupPoint != 0) {
                mainSetBits(0x2cd,1);
                mainSetBits(0x2ce,1);
                mainSetBits(0x2cf,1);
                mainSetBits(0x82,1);
                mainSetBits(0x83,1);
                mainSetBits(0x84,1);
                mainSetBits(0x2d9,1);
                mainSetBits(0x2d0,1);
                mainSetBits(0x2cc,1);
            }
            break;
        case 0x6:
            mainSetBits(0x2d,1);
            mainSetBits(0x1d7,1);
            if(debugSetupPoint >= 1) {
                mainSetBits(0x16,1);
            }
            if(debugSetupPoint >= 2) {
                mainSetBits(0x18,1);
            }
            if(debugSetupPoint >= 3) {
                mainSetBits(0x10b,1);
            }
            if(debugSetupPoint >= 4) {
                mainSetBits(0x12,1);
                mainSetBits(0xd,1);
                mainSetBits(0xdb,1);
                mainSetBits(0xdc,1);
            }
            if(debugSetupPoint >= 5) {
                mainSetBits(0x19,1);
                mainSetBits(0xd,1);
                mainSetBits(0xe,1);
                mainSetBits(0xf,1);
            }
            if(debugSetupPoint >= 9) {
                mainSetBits(0x10,1);
            }
            break;
    }

}

N64Vertex** getcur_di_vtx(void) { //80079AD0
    return &cur_di_vtx;
}

BOOL DLL_createTempDll(int id) { //80079AD8
    //should be equivalent, only reloc
    uint idx;

    //find a free slot
    idx = 0;
    while(id != tempDllIds[idx]) {
        if(++idx >= 3) break;
    }
    if(idx == 3) return FALSE;

    if(tempDlls[idx]) {
        printf(" WARNING : temp dll no %i is alreadly created \n",id);
    }
    tempDlls[idx] = (DLL *)runlinkDownloadCode((ushort)id,1);
    return TRUE;
}

BOOL DLL_removeTempDll(int id) { //80079B80
    //should be equivalent, only reloc
    int iVar1;
    uint idx;

    for (idx = 0;
    (idx < 3 && (id != tempDllIds[idx])); idx++) {
    }
    if (idx == 3) return FALSE;
    if(!tempDlls[idx]) {
        printf(" WARNING : temp dll no %i is alreadly removed \n",id);
        return FALSE;
    }
    if(free((int)tempDlls[idx])) {
        tempDlls[idx] = NULL;
    }
    return TRUE;
}

void loadDlls47_48(void) { //80079C40
    if(!pDLL_48) {
        pDLL_47 = runlinkDownloadCode(0x47,10);
        pDLL_48 = runlinkDownloadCode(0x48,3);
    }
}

void freeDlls47_48(void) { //80079C88
    if(pDLL_48) {
        DLL_free(pDLL_47);
        pDLL_47 = NULL;
        DLL_free(pDLL_48);
        pDLL_48 = NULL;
    }
}

void fn_80079CD0(void) { //80079CD0
    DAT_8039890a = 0;
    DAT_8039890b = 0;
}

void fn_80079CE4(float x,float y, float z,
int playerNo) { //80079CE4
    if(++DAT_8039890a >= 5) {
        DAT_8039890a = 0;
        DAT_8039890b = 1;
    }
    newGameAtPos(x, y, z, playerNo);
}

int fn_80079D4C(void) { //80079D4C
    int uVar1;
    uVar1 = DAT_8039890a + 1;
    if (uVar1 >= 5) {
        uVar1 = 0;
    }
    return uVar1;
}

s8 fn_80079D78(void) { //80079D78
    return DAT_8039890a;
}

s8 fn_80079D80(void) { //80079D80
    return DAT_8039890b;
}

u32 getPiLockedFlags(void) { //80079D88
    return piLockedFlags;
}

void clearPlayerPosLog(void) { //80079D90
    memclr(playerPrevPositions,0x3c0);
    playerPrevPosidx = 0;
}

void updatePlayerPosLog(void) { //80079DC4
    ObjInstance *player;
    PlayerPrevPosition *pos;

    player = objGetMain();
    pos = &playerPrevPositions[playerPrevPosidx];
    frameCount_playerPosLog += framesThisStep;
    if(player) {
        pos->pos.x = (player->pos).pos.x;
        pos->pos.y = (player->pos).pos.y;
        pos->pos.z = (player->pos).pos.z;
        pos->time = frameCount_playerPosLog;
        if(++playerPrevPosidx >= NUM_PLAYER_PREV_POSITIONS) {
            playerPrevPosidx = 0;
        }
    }
}

void multVectorByMatrix(float x,float y,float z,
Mtx44Ptr m,float *outX,float *outY,float *outZ) { //80079E58
    *outX = m[3][0] + (m[2][0] * z + (m[0][0] * x + (m[1][0] * y)));
    *outY = m[3][1] + (m[2][1] * z + (m[0][1] * x + (m[1][1] * y)));
    *outZ = m[3][2] + (m[2][2] * z + (m[0][2] * x + (m[1][2] * y)));
}

void MtxFastXFMF(float *a,float *b,float *out) { //80079EC8
    float f31;
    float f30;
    float f29;
    float f28;
    float f27;
    float f26;
    float f25;

    f28 = b[0]; f29 = a[0];
    f27 = b[1]; f31 = a[4];
    f26 = b[2]; f30 = a[8];
    f29 = f28 * f29;
    f31 = f27 * f31;
    f30 = f26 * f30;
    f31 = f29 + f31;
    f29 = a[1];
    f25 = f31 + f30;
    f31 = a[5];
    f30 = a[9];
    f29 = f28 * f29;
    out[0] = f25;

    f31 = f27 * f31;
    f30 = f26 * f30;
    f31 = f29 + f31;
    f29 = a[2];
    f25 = f31 + f30;
    f31 = a[6];
    f30 = a[10];
    f29 = f28 * f29;
    out[1] = f25;

    f31 = f27 * f31;
    f30 = f26 * f30;
    f31 = f29 + f31;
    f30 = f31 + f30;
    out[2] = f30;
}

void Mtx44_Mult(float *a,float *b,float *out) { //80079F6C
    //name may be wrong as this doesn't take Mtx44*
    //or Mtx44Ptr
    float tmp[16];
    int ii;
    int yy;
    int xx;

    for(yy = 0; yy < 4; yy++) {
        for(xx = 0; xx < 4; xx++) {
            tmp[xx + yy * 4] = 0.0f;
            for(ii = 0; ii < 4; ii++) {
                tmp[xx + yy * 4] +=
                    a[ii + yy * 4] *
                    b[xx + ii * 4];
            }
        }
    }
    for(yy = 0; yy < 4; yy++) {
        for(xx = 0; xx < 4; xx++) {
            out[xx + yy * 4] = tmp[xx + yy * 4];
        }
    }
}

void Mtx44_VecMult(float *pa,float *pb,float *pout) { //8007A05C
    //no idea the proper name
    float f31;
    float f30;
    float f29;
    float f28;
    float f27;
    float f26;
    float f25;
    float f24;

    float *r30 = pa;
    float *r31 = pb;
    float *r29 = pout;
    float *r28 = &r30[12];
    do {
        f25 = r30[0];
        f26 = r30[1];
        f24 = r30[2];
        f30 = r31[0];
        f29 = r31[4];
        f31 = r31[8];
        f30 = f25 * f30;
        f29 = f26 * f29;
        f31 = f24 * f31;
        f28 = f30 + f29;
        f30 = r31[1];
        f29 = r31[5];
        f27 = f31 + f28;
        f31 = r31[9];
        r29[0] = f27;

        f30 = f25 * f30;
        f29 = f26 * f29;
        f31 = f24 * f31;
        f28 = f30 + f29;
        f30 = r31[2];
        f29 = r31[6];
        f27 = f31 + f28;
        f31 = r31[10];
        r29[1] = f27;

        f30 = f25 * f30;
        f29 = f26 * f29;
        f31 = f24 * f31;
        f28 = f30 + f29;
        f27 = f31 + f28;
        r29[2] = f27;

        r29 += 4;
        r30 += 4;
    } while(r28 != r30);

    f25 = r30[0];
    f26 = r30[1];
    f24 = r30[2];
    f30 = r31[0];
    f29 = r31[4];
    f31 = r31[8];
    f28 = r31[12];
    f30 = f25 * f30;
    f29 = f26 * f29;
    f31 = f24 * f31;
    f28 = f30 + f28;
    f31 = f29 + f31;
    f30 = r31[1];
    f29 = r31[5];
    f27 = f31 + f28;
    f31 = r31[9];
    f28 = r31[13];
    r29[0] = f27;

    f30 = f25 * f30;
    f29 = f26 * f29;
    f31 = f24 * f31;
    f28 = f30 + f28;
    f31 = f29 + f31;
    f30 = r31[2];
    f29 = r31[6];
    f27 = f31 + f28;
    f31 = r31[10];
    f28 = r31[14];
    r29[1] = f27;

    f30 = f25 * f30;
    f29 = f26 * f29;
    f31 = f24 * f31;
    f28 = f30 + f28;
    f31 = f29 + f31;
    f27 = f31 + f28;
    r29[2] = f27;
}

void MTX44_Copy(float *src,float *dst) { //8007A1B8
    //odd name because MTXCopy is aliased.
    //this seems to be some other matrix function
    //that wants float[16] instead of float[4][4].
    int iVar1;
    for (iVar1 = 0; iVar1 < 0x10; iVar1 += 1) {
        dst[iVar1] = src[iVar1];
    }
}

void MTX44_Copy2(float *src,float *dst) { //8007A1F0
    //exact same as previous function, no idea why it exists
    int iVar1;
    for (iVar1 = 0; iVar1 < 0x10; iVar1 += 1) {
        dst[iVar1] = src[iVar1];
    }
}

int randInt(int min,int max) { //8007A228
    uint uVar1;

    if(max == min) return min;
    uVar1 = ((uint)rand() % (max - min + 1));
    uVar1 += min;
    return uVar1;
}
