
/* Library Function - Single Match
    mainLoop
   
   Library: KioskDefault 0 0 */

void gameLoop(void) { //800781D4
  float fVar1;
  F3DEXcommand *pFVar2;
  int iVar3;
  BOOL BVar4;
  BOOL BVar5;
  u16 uVar7;
  N64Button32 NVar6;
  uint uVar8;
  double fps2;
  u64 uVar9;
  undefined8 uVar10;
  int local_58;
  int local_54;
  undefined4 local_50 [2];
  double local_48;
  Gfx *cmdBuf2;
  float *times;
  
  _savefpr_30();
  setFrameTime(0);
  diProfReset();
  nop_8017a328();
  mainLoopGxSetupFn_8009e320();
  main_framebuf_idx = main_framebuf_idx ^ 1;
  cur_gfx = main_gfx[main_framebuf_idx];
  mtx = main_mtx[main_framebuf_idx];
  cur_vtx = (N64Vtx *)main_vtx[main_framebuf_idx];
  cur_pol = main_pol[main_framebuf_idx];
  cur_di_vtx = main_divtx[main_framebuf_idx];
  cur_di_pol = main_dipol[main_framebuf_idx];
  gfx = cur_gfx;
  RSP_segSetBase(&gfx,0,-0x80000000);
  RSP_segSetBase(&gfx,1,currentScreen);
  RSP_segSetBase(&gfx,2,otherZbuf);
  freakFn_800a58d0(&gfx,(uint)framesThisStep);
  FUN_8018f55c();
  RSP_rcpInitSp();
  RSP_rcpInitDp();
  if (RSP_pState->bNeedPipeSync != false) {
    RSP_pState->bNeedPipeSync = false;
    cmdBuf2 = gfx;
    pFVar2 = &gfx->cmd;
    gfx = gfx + 1;
    *pFVar2 = G_RDPPIPESYNC;
    cmdBuf2->param = 0;
  }
  cmdBuf2 = gfx;
  pFVar2 = &gfx->cmd;
  gfx = gfx + 1;
  *pFVar2 = G_SETZIMG;
  cmdBuf2->param = 0x2000000;
  uVar8 = 2;
  iVar3 = getRenderFlags();
  if (iVar3 == 0) {
    uVar8 = 0;
  }
  else {
    BVar4 = isCloudy();
    if (BVar4 == 0) {
      uVar8 = 3;
    }
  }
  nop_8009E5EC(&gfx,&mtx,(N64Vtx **)(uVar8 | 1));
  voxDataFn_8006d29c();
  gameUpdate();
  updateViewport();
  nop_80077B60();
  loadTableFiles_();
  debugDoPad1Toggles();
  nop_800671C8();
  BVar4 = isHeapDebugDisplayEnabled();
  if (BVar4 != 0) {
    drawHeapInfo(&gfx,&mtx,&cur_vtx);
  }
  cmdBuf2 = gfx;
  pFVar2 = &gfx->cmd;
  gfx = gfx + 1;
  *pFVar2 = G_RDPFULLSYNC;
  cmdBuf2->param = 0;
  cmdBuf2 = gfx;
  pFVar2 = &gfx->cmd;
  gfx = gfx + 1;
  *pFVar2 = X_SYNC;
  cmdBuf2->param = 0;
  perfFn_8018f5cc();
  mainRender((Gfx **)main_gfx[main_framebuf_idx],(Mtx44 **)gfx,(N64Vtx **)0x0);
  cmdBuf2 = (Gfx *)rspFn_8017c278();
  listCodeRender(cmdBuf2);
                    /* {@symbol 8011afa4} */
  (**(code **)(*(int *)pDll_gplay + 8))(&gfx,&mtx,&cur_vtx);
                    /* {@symbol 8011e690} */
  (**(code **)(*(int *)pDll_Dummy15 + 0x1c))(&gfx);
  gxMaybeFlush();
  joyRead();
  amAudioTick();
  processObjDeleteList();
  checkHeaps();
  printRspStatus();
  strBufFn_8018f2f8();
  if (diFlag_803997d0 != 0) {
    rspFramesLastStep = (u32)framesThisStep;
  }
  BVar4 = isFrameTimeDisplayEnabled();
  if (BVar4 != 0) {
    uVar9 = getFrameTime();
    uVar10 = __div2u((uint)(uVar9 >> 0x20),(uint)uVar9,0,0xc);
    local_48 = (double)CONCAT44(0x43300000,(uint)uVar10 ^ 0x80000000);
    fVar1 = (float)(local_48 - 4503601774854144.0) / 65536.0;
    fps2 = (double)fVar1;
    times = UnkStructVersionStuff_802eadc8.frameTimes + frameTimeArrayIdx;
    frameTimeArrayIdx = frameTimeArrayIdx + 1;
    *times = fVar1;
    if (frameTimeArrayIdx == 10) {
      frameTimeArrayIdx = 0;
    }
    fVar1 = 0.0;
    for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
      fVar1 = fVar1 + UnkStructVersionStuff_802eadc8.frameTimes[iVar3];
    }
    local_48 = (double)(longlong)(int)(600.0 / fVar1);
    dprintSetPos(0x1e,0x14);
    dprintSetColor(0xff,0xff,0xff,0xff);
    dprintSetBgColor(0,0,0,0x80);
    diPrintf("%f ",fps2);
    diPrintf("- %d ",(uint)framesThisStep);
    diPrintf("- %dfps",(int)(600.0 / fVar1));
  }
  BVar5 = shouldShowMemUsed();
  if (BVar5 != FALSE) {
    dprintSetPos(0x28,0xd4);
    dprintSetColor(0xff,0xff,0xff,0xff);
    dprintSetBgColor(0,0,0,0x80);
    iVar3 = FUN_8007c54c();
    diPrintf("%dk",iVar3 >> 10);
  }
  BVar5 = shouldShowTexCacheUsed();
  if (BVar5 != FALSE) {
    dprintSetPos(0x1e,0xe0);
    dprintSetColor(0xff,0xff,0xff,0xff);
    dprintSetBgColor(0,0,0,0x80);
    FUN_800a58bc(local_50,&local_54,&local_58);
    diPrintf("texcache: %d %d/%d",local_50[0],local_54 >> 10,local_58 >> 10);
  }
  uVar8 = (int)gfx - (int)main_gfx[main_framebuf_idx];
  iVar3 = ((int)uVar8 >> 3) + (uint)((int)uVar8 < 0 && (uVar8 & 7) != 0);
  if (10000 < iVar3) {
                    
    OSPanic("main.c",0x3a9,(char *)0x0);
  }
  if (main_gfx_count < iVar3) {
    main_gfx_count = (short)iVar3;
  }
  uVar8 = (int)mtx - (int)main_mtx[main_framebuf_idx];
  iVar3 = ((int)uVar8 >> 6) + (uint)((int)uVar8 < 0 && (uVar8 & 0x3f) != 0);
  if (800 < iVar3) {
    printf("Warning: Mtx-list overflow by %d!",iVar3 + -800);
  }
  if (main_mtx_count < iVar3) {
    main_mtx_count = (short)iVar3;
  }
  uVar8 = (int)cur_vtx - (int)main_vtx[main_framebuf_idx];
  iVar3 = ((int)uVar8 >> 4) + (uint)((int)uVar8 < 0 && (uVar8 & 0xf) != 0);
  if (1000 < iVar3) {
    printf("Warning: Vtx-list overflow by %d!",iVar3 + -1000);
  }
  if (main_vtx_count < iVar3) {
    main_vtx_count = (short)iVar3;
  }
  uVar8 = (int)cur_pol - (int)main_pol[main_framebuf_idx];
  iVar3 = ((int)uVar8 >> 4) + (uint)((int)uVar8 < 0 && (uVar8 & 0xf) != 0);
  if (1000 < iVar3) {
    printf("Warning: Pol-list overflow by %d!",iVar3 + -1000);
  }
  if (main_pol_count < iVar3) {
    main_pol_count = (short)iVar3;
  }
  uVar8 = (int)cur_di_vtx - (int)main_divtx[main_framebuf_idx];
  iVar3 = ((int)uVar8 >> 4) + (uint)((int)uVar8 < 0 && (uVar8 & 0xf) != 0);
  if (0x708 < iVar3) {
    printf("Warning: DI-vtx-list overflow by %d!",iVar3 + -0x708);
  }
  if (di_vtx_count < iVar3) {
    di_vtx_count = (short)iVar3;
  }
  uVar8 = (int)cur_di_pol - (int)main_dipol[main_framebuf_idx];
  iVar3 = ((int)uVar8 >> 4) + (uint)((int)uVar8 < 0 && (uVar8 & 0xf) != 0);
  if (3000 < iVar3) {
    printf("Warning: DI-pol-list overflow by %d!",iVar3 + -3000);
  }
  if (di_pol_count < iVar3) {
    di_pol_count = (short)iVar3;
  }
  if (main_dt != framesThisStep) {
    printf("main_dt has been changed!");
  }
  if (main_fdt != timeDelta) {
    printf("main_fdt has been changed!");
  }
  framesThisStep = viFrameSync();
  if (6 < framesThisStep) {
    framesThisStep = '\x06';
  }
  local_48 = (double)CONCAT44(0x43300000,(uint)framesThisStep);
  timeDelta = (float)(local_48 - 4503599627370496.0);
  prevOneOverTimeDelta = 1.0 / timeDelta;
  framesLastStep = framesThisStep;
  prevOneOverTimeDelta2 = 1.0 / timeDelta;
  prevTimeDelta = timeDelta;
  doQueuedLoads();
  uVar7 = getEnabledButtonsPressed(2);
  if ((uVar7 & 0x40) != 0) {
    no_diprintf = (bool)(1 - no_diprintf);
    printf("no_diprintf %d",(uint)no_diprintf);
  }
  main_dt = framesThisStep;
  main_fdt = timeDelta;
  if (diFlag_803997d0 != 0) {
    framesThisStep = (u8)rspFramesLastStep;
  }
  diMenu_main();
  FUN_8018f8dc();
  NVar6 = n64GetEnabledButtonsPressed(3);
  if ((NVar6 & N64_BUTTON_Z) != 0) {
    bEnablePartdev = TRUE - bEnablePartdev;
  }
  if (bEnablePartdev != FALSE) {
    DLL_free((LoadedDll *)pDll_objfsa);
    pDll_objfsa = (DLL_func *)runlinkDownloadCode(0x10,2);
    diPrintf("PARTDEV");
  }
  _restfpr_30();
  return;
}

