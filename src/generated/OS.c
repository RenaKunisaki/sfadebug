
/* Library Function - Single Match
    _osInit
   
   Library: KioskDefault 0 0 */

void OSInit(void) { //80006DA8
  DVDBI2 **dvdBi2;
  undefined *arena;
  u32 uVar1;
  void *pvVar2;
  void *pvVar3;
  DVDBI2 *bi2;
  dword piType;
  
  if (isOsInit != FALSE) {
    return;
  }
  isOsInit = TRUE;
  OSDisableInterrupts();
  pBootInfo = (OSBootInfo *)OSPhysicalToCached(0);
  pBi2DebugFlag = (undefined *)0x0;
  bSupportLongFileNames = FALSE;
  dvdBi2 = (DVDBI2 **)OSPhysicalToCached(0xf4);
  bi2 = *dvdBi2;
  if (bi2 != (DVDBI2 *)0x0) {
    pBi2DebugFlag = (undefined *)&bi2->debugFlag;
    bSupportLongFileNames = bi2->supportLongFileNames;
    padSpec2 = bi2->padSpec;
  }
  if (pBootInfo->arenaLo == (void *)0x0) {
    arena = &__ArenaLo;
  }
  else {
    arena = (undefined *)pBootInfo->arenaLo;
  }
  osSetArenaLo(arena);
  if (((pBootInfo->arenaLo == (void *)0x0) && (pBi2DebugFlag != (undefined *)0x0)) &&
     (*(uint *)pBi2DebugFlag < 2)) {
    osSetArenaLo(&DAT_803b4180);
  }
  if (pBootInfo->arenaHi == (void *)0x0) {
    arena = &__ArenaHi;
  }
  else {
    arena = (undefined *)pBootInfo->arenaHi;
  }
  osSetArenaHi(arena);
  debugInit();
  initExceptions();
  __OSModuleInit();
  exceptionInitFn_8000b4b0();
  __OSSetInterruptHandler(0x16,interruptHandler16);
  _osInstallFpuUnavailableHandler();
  __OSCacheInit();
  initIrq_8000ae98();
  siInit();
  osRtcFn_8000c270();
  osThreadFn_8000d228();
  __OSInitAudioSystem();
  if (pBootInfo == (OSBootInfo *)0x0) {
                    
    OSPanic("OS.c",0x252,"Failed assertion BootInfo");
  }
  if ((pBootInfo->consoleType & 0x10000000) == 0) {
    pBootInfo->consoleType = 1;
  }
  else {
    pBootInfo->consoleType = 0x10000004;
  }
  piType = pi_TYPE;
  pBootInfo->consoleType = pBootInfo->consoleType + (piType >> 0x1c);
  OSReport("Dolphin OS $Revision: 36 $.");
  OSReport("Kernel built : %s %s",kernelBuildDate,kernelBuildTime);
  OSReport("Console Type : ");
  uVar1 = getConsoleType();
  if ((uVar1 & 0x10000000) == 0) {
    OSReport("Retail %d",uVar1);
  }
  else if (uVar1 == 0x10000002) {
    OSReport("EPPC Arthur");
  }
  else {
    if ((int)uVar1 < 0x10000002) {
      if (uVar1 == 0x10000000) {
        OSReport("Mac Emulator");
        goto LAB_8000705c;
      }
      if (0xfffffff < (int)uVar1) {
        OSReport("PC Emulator");
        goto LAB_8000705c;
      }
    }
    else if ((int)uVar1 < 0x10000004) {
      OSReport("EPPC Minnow");
      goto LAB_8000705c;
    }
    OSReport("Development HW%d",uVar1 + 0xeffffffd);
  }
LAB_8000705c:
  OSReport("Memory %d MB",pBootInfo->memorySize >> 0x14);
  pvVar2 = OSGetArenaHi();
  pvVar3 = OSGetArenaLo();
  OSReport("Arena : 0x%x - 0x%x",pvVar3,pvVar2);
  if ((pBi2DebugFlag != (undefined *)0x0) && (1 < *(uint *)pBi2DebugFlag)) {
    debugInitFn_8005fbcc();
  }
  OSEnableInterrupts();
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    debugInit
   
   Library: KioskDefault 0 0 */

void debugInit(void) { //800070CC
  uint uVar1;
  int *__dest;
  uint uVar2;
  void *__dest_00;
  code *pcVar3;
  uint uVar4;
  byte exception;
  
  uVar1 = _irqHandler_800074e8;
  if (false) {
                    
    OSPanic("OS.c",0x2f1,"OSExceptionInit(): too big exception vector code.");
  }
  __dest = (int *)OSPhysicalToCached(0x60);
  if (*__dest == 0) {
    _osDebugPrint("Installing OSDBIntegrator");
    memcpy(__dest,OSDBIntegrator,0x24);
    DCFlushRange(__dest,0x24);
    sync(0);
    ICInvalidateRange(__dest,0x24);
  }
  for (uVar4 = 0; (uVar4 & 0xff) < 0xf; uVar4 = uVar4 + 1) {
    if (((pBi2DebugFlag == (undefined *)0x0) || (*(uint *)pBi2DebugFlag < 2)) ||
       (uVar2 = FUN_8000e8bc(uVar4), uVar2 == 0)) {
      _irqHandler_800074e8 = uVar1 | uVar4 & 0xff;
      uVar2 = FUN_8000e8bc(uVar4);
      if (uVar2 == 0) {
        pcVar3 = FUN_800074d8;
        for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 4) {
          *(undefined4 *)pcVar3 = 0x60000000;
          pcVar3 = (code *)((int)pcVar3 + 4);
        }
      }
      else {
        _osDebugPrint(s_>>>_OSINIT__exception__d_vectore_802d0fdc,uVar4 & 0xff);
        memcpy(FUN_800074d8,FUN_80007380,4);
      }
      __dest_00 = OSPhysicalToCached(debugExceptionTypes[uVar4 & 0xff]);
      memcpy(__dest_00,ecxeptionHandler_80007480,0x98);
      DCFlushRange(__dest_00,0x98);
      sync(0);
      ICInvalidateRange(__dest_00,0x98);
    }
    else {
      _osDebugPrint(s_>>>_OSINIT__exception__d_command_802d0fac,uVar4 & 0xff);
    }
  }
  exceptionHandlers = (undefined ***)OSPhysicalToCached(0x3000);
  for (exception = 0; exception < 0xf; exception = exception + 1) {
    __OSSetExceptionHandler(exception,defaultExceptionHandler);
  }
  _irqHandler_800074e8 = uVar1;
  _osDebugPrint("Exceptions initialized...");
  return;
}


/* Library Function - Single Match
    __OSSetExceptionHandler
   
   Library: KioskDefault 0 0 */

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception,__OSExceptionHandler handler) { //80007384
  undefined **ppuVar1;
  
  if (0xe < exception) {
                    
    OSPanic("OS.c",0x37f,"__OSSetExceptionHandler(): unknown exception.");
  }
  ppuVar1 = exceptionHandlers[exception];
  exceptionHandlers[exception] = (undefined **)handler;
  return (__OSExceptionHandler)ppuVar1;
}


/* Library Function - Single Match
    __OSGetExceptionHandler
   
   Library: KioskDefault 0 0 */

__OSExceptionHandler __OSGetExceptionHandler(__OSException exception) { //80007410
  if (0xe < exception) {
                    
    OSPanic("OS.c",0x396,"__OSGetExceptionHandler(): unknown exception.");
  }
  return (__OSExceptionHandler)exceptionHandlers[exception];
}

