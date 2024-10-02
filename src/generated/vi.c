
/* Library Function - Single Match
    viInterrupt
   
   Library: KioskDefault 0 0 */

void interruptHandler18(undefined4 param_1,OSContext *param2) { //80014608
  word wVar1;
  int iVar2;
  byte bVar3;
  OSContext OStack_2d8;
  
  wVar1 = vi_DI0_CTRL;
  bVar3 = (wVar1 & 0x8000) != 0;
  if ((bool)bVar3) {
    vi_DI0_CTRL = wVar1 & 0x7fff;
  }
  wVar1 = vi_DI1_CTRL;
  if ((wVar1 & 0x8000) != 0) {
    vi_DI1_CTRL = wVar1 & 0x7fff;
    bVar3 = bVar3 | 2;
  }
  wVar1 = vi_DI2_CTRL;
  if ((wVar1 & 0x8000) != 0) {
    vi_DI2_CTRL = wVar1 & 0x7fff;
    bVar3 = bVar3 | 4;
  }
  wVar1 = vi_DI3_CTRL;
  if ((wVar1 & 0x8000) != 0) {
    vi_DI3_CTRL = wVar1 & 0x7fff;
    bVar3 = bVar3 | 8;
  }
  wVar1 = vi_DI3_CTRL;
  if (((bVar3 & 4) == 0) && ((bVar3 & 8) == 0)) {
    if (bVar3 == 0) {
                    
      OSPanic("vi.c",0x2ba,"Failed assertion FALSE");
    }
    irqSyncFlag_80398348 = irqSyncFlag_80398348 + 1;
    OSClearContext(&OStack_2d8);
    OSSetCurrentContext(&OStack_2d8);
    if (pVideoThread_8039835c != (undefined *)0x0) {
                    /* {@symbol 8009fb1c} */
      (*(code *)pVideoThread_8039835c)(irqSyncFlag_80398348);
    }
    if (DAT_80398350 == 0) {
      if (((DAT_80398374 | DAT_80398370) != 0) &&
         (framesSinceViFlush = framesSinceViFlush + 1, 0x3c < framesSinceViFlush)) {
        OSReport("Warning: VIFlush() was not called for 60 frames although VI settings were changed");
        framesSinceViFlush = 0;
      }
    }
    else {
      framesSinceViFlush = 0;
      iVar2 = FUN_80014530();
      if (iVar2 != 0) {
        DAT_80398350 = 0;
      }
    }
    if (fptr_80398360 != (undefined *)0x0) {
      OSClearContext(&OStack_2d8);
                    /* {@symbol 8009fbc8} */
      (*(code *)fptr_80398360)(irqSyncFlag_80398348);
    }
    osThreadFn_8000e3a0((OSThread *)&OSThreadQueue_80398354);
    OSClearContext(&OStack_2d8);
    OSSetCurrentContext(param2);
  }
  else {
    OSSetCurrentContext(param2);
  }
  return;
}


/* Library Function - Single Match
    viSramFn_80014d88
   
   Library: KioskDefault 0 0 */

void _osGetDisplayOffsets(void) { //80014D88
  SramState *sram;
  
  sram = osOpenSram();
  if (sram == (SramState *)0x0) {
                    
    OSPanic("vi.c",0x3e2,"Failed assertion sram");
  }
  displayHOffset = (s16)sram->displayHOffset;
  displayVOffset = 0;
  osCloseSram(0);
  return;
}


/* Library Function - Single Match
    VIConfigure
   
   Library: KioskDefault 0 0 */

void VIConfigure(GXRenderModeObj *fmt) { //80015AAC
  bool bVar1;
  uint uVar2;
  BOOL_ level;
  uint uVar3;
  byte *pbVar4;
  
  if ((fmt->viHeight & 1) != 0) {
                    
    OSPanic("vi.c",0x601,"VIConfigure(): Odd number(%d) is specified to viHeight",(uint)fmt->viHeight);
  }
  if (((fmt->xFBmode == VI_XFBMODE_DF) || (fmt->viTVmode == VI_TVMODE_NTSC_PROG)) &&
     (fmt->xfbHeight != fmt->viHeight)) {
                    
    OSPanic("vi.c",0x607,"VIConfigure(): xfbHeight(%d) is not equal to viHeight(%d) when DF XFB mode or progressive mode is specified",(uint)fmt->xfbHeight,
            (uint)fmt->viHeight);
  }
  if (((fmt->xFBmode == VI_XFBMODE_SF) && (fmt->viTVmode != VI_TVMODE_NTSC_PROG)) &&
     ((uint)fmt->viHeight != (uint)fmt->xfbHeight << 1)) {
                    
    OSPanic("vi.c",0x60e,"VIConfigure(): xfbHeight(%d) is not as twice as viHeight(%d) when SF XFB mode is specified",(uint)fmt->xfbHeight,
            (uint)fmt->viHeight);
  }
  level = OSDisableInterrupts();
  if (fmt->viTVmode == VI_TVMODE_NTSC_PROG) {
    viMode_80326bd4 = 2;
  }
  else {
    uVar2 = fmt->viTVmode & 1;
    bVar1 = viMode_80326bd4 != uVar2;
    viMode_80326bd4 = uVar2;
    if (bVar1) {
      DAT_8039834c = 1;
    }
  }
  uVar3 = VIGetTvFormat();
  uVar2 = fmt->viTVmode >> 2;
  if (((uVar3 != uVar2) && ((uVar3 != 2 || (uVar2 != 0)))) && ((uVar3 != 0 || (uVar2 != 2)))) {
                    
                    /* bug? no params for format string */
    OSPanic("vi.c",0x635,"Doesn't match TV format: TV format in bootrom is %d but TV format specified in the game is %d (0:NTSC, 1:PAL, 2:MPAL)");
  }
  DAT_80326bb0 = fmt->viXOrigin;
  if (viMode_80326bd4 == 1) {
    DAT_80326bb2 = fmt->viYOrigin << 1;
  }
  else {
    DAT_80326bb2 = fmt->viYOrigin;
  }
  viWidth2 = fmt->viWidth;
  viWidth2 = fmt->fbWidth;
  viXfbHeight = fmt->xfbHeight;
  viIsProgScan = fmt->xFBmode;
  DAT_80326bc6 = 0;
  DAT_80326bc8 = 0;
  viXfbHeight2 = viXfbHeight;
  if ((viMode_80326bd4 != 2) && (viIsProgScan == VI_XFBMODE_SF)) {
    viXfbHeight2 = viXfbHeight << 1;
  }
  viWidth2 = viWidth2;
  viXfbHeight3 = viXfbHeight;
  viTvFmt = uVar3;
  pbVar4 = tvModeFn_80014878(fmt->viTVmode);
  PTR_DAT_80326c04 = pbVar4;
  FUN_80014b6c(*(short *)(pbVar4 + 2));
  if ((int)((*(ushort *)(pbVar4 + 0x1a) + 0x28) - (uint)pbVar4[0x1f]) < (int)(uint)fmt->viXOrigin) {
                    
    OSPanic("vi.c",0x654,"VIConfigure(): viXOrigin(%d) cannot be greater than %d in this TV mode",(uint)fmt->viXOrigin,
            (*(ushort *)(pbVar4 + 0x1a) + 0x28) - (uint)pbVar4[0x1f]);
  }
  if ((int)((uint)fmt->viXOrigin + (uint)fmt->viWidth) <
      (int)(0x2a8 - (uint)*(ushort *)(pbVar4 + 0x20))) {
                    
    OSPanic("vi.c",0x659,"VIConfigure(): viXOrigin + viWidth (%d) cannot be less than %d in this TV mode",
            (uint)fmt->viXOrigin + (uint)fmt->viWidth,0x2a8 - (uint)*(ushort *)(pbVar4 + 0x20));
  }
  if (DAT_80398364 == 0) {
    viTvFmt = 3;
  }
  FUN_8001517c((int)pbVar4);
  if (true) {
    if ((viTvFmt & 0xfffffffc) == 0) {
      DAT_80326ac2 = (ushort)(viMode_80326bd4 << 2) & 4 | DAT_80326ac2 & 0xfcfb |
                     (ushort)(viTvFmt << 8);
      DAT_80398370 = DAT_80398370 | 0x40000000;
      FUN_800153d0((uint)viWidth2,(uint)viWidth2,DAT_80326bf4);
      FUN_800157d8((int)pbVar4,DAT_80326bb8,viWidth2);
      FUN_800152e4((int)pbVar4);
      FUN_80015234((uint)viWidth2,viIsProgScan,(uint)DAT_80326bc6,(uint)viWidth2,"(P(",
                   "(P(" + 1,"(P(" + 2,&DAT_80326bec);
      if (DAT_80398380 != 0) {
        setFbbRegs(-0x7fcd9450,(uint *)&DAT_80326be4,(uint *)&DAT_80326be8,(uint *)&DAT_80326bfc,
                   (uint *)&DAT_80326c00);
      }
      setVerticalRegs(DAT_80326bba,DAT_80326bbc,*pbVar4,*(short *)(pbVar4 + 2),
                      *(short *)(pbVar4 + 4),*(short *)(pbVar4 + 6),*(short *)(pbVar4 + 8),
                      *(short *)(pbVar4 + 10),DAT_80326bf0);
      OSRestoreInterrupts(level);
      return;
    }
                    
    OSPanic("vi.c",0x66b,"GX Internal: Register field out of range");
  }
                    
  OSPanic("vi.c",0x66a,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    VISetNextFrameBuffer
   
   Library: KioskDefault 0 0 */

void VISetNextFrameBuffer(uint param1) { //80015F90
  BOOL_ level;
  
  if ((param1 & 0x1f) != 0) {
                    
    OSPanic("vi.c",0x6f7,"VISetNextFrameBuffer(): Frame buffer address(0x%08x) is not 32byte aligned",param1);
  }
  level = OSDisableInterrupts();
  DAT_80398380 = 1;
  nextFrameBuffer = param1;
  setFbbRegs(-0x7fcd9450,(uint *)&DAT_80326be4,(uint *)&DAT_80326be8,(uint *)&DAT_80326bfc,
             (uint *)&DAT_80326c00);
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    VIGetTvFormat
   
   Library: KioskDefault 0 0 */

int VIGetTvFormat(void) { //800161CC
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)OSPhysicalToCached(0xcc);
  iVar2 = *piVar1;
  if (((iVar2 != 0) && (iVar2 != 1)) && (iVar2 != 2)) {
                    
    OSPanic("vi.c",0x80d,"VIGetTvFormat(): Wrong format is stored in lo mem. Maybe lo mem is trashed");
  }
  return iVar2;
}

