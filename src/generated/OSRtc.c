
/* Library Function - Single Match
    osRtcFn_8000c0c0
   
   Library: KioskDefault 0 0 */

void rtcCb_8000c0c0(void) { //8000C0C0
  if (scb_locked != 0) {
                    
    OSPanic("OSRtc.c",0xf0,"Failed assertion !Scb.locked");
  }
  scb_sync = WriteSram((int)(SramState_80325e20.flash0Id + DAT_80325e60 + -0x14),DAT_80325e60,
                       0x40 - DAT_80325e60);
  if (scb_sync == 0) {
                    
    OSPanic("OSRtc.c",0xf6,"Failed assertion Scb.sync");
  }
  DAT_80325e60 = 0x40;
  return;
}


uint WriteSram(int param1,int param2,int param3) { //8000C164
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_c;
  SramState *local_8;
  
  local_8 = &SramState_80325e20;
  iVar4 = osExiFn_8000af80(0,1,-0x7fff3f40);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    iVar4 = EXISelect(0,1,3);
    if (iVar4 == 0) {
      EXIUnlock(0);
      uVar5 = 0;
    }
    else {
      local_c = param2 * 0x40 + 0x100U | 0xa0000000;
      uVar6 = osExiFn_80009f08(0,(int)&local_c,4,1,0);
      uVar5 = countLeadingZeros(uVar6);
      uVar6 = osExiFn_8000a354(0);
      uVar1 = countLeadingZeros(uVar6);
      uVar6 = EXIImmEx(0,param1,param3,1);
      uVar2 = countLeadingZeros(uVar6);
      uVar6 = EXIDeselect(0);
      uVar3 = countLeadingZeros(uVar6);
      EXIUnlock(0);
      uVar5 = countLeadingZeros((uVar5 | uVar1 | uVar2 | uVar3) >> 5);
      uVar5 = uVar5 >> 5;
    }
  }
  return uVar5;
}


/* Library Function - Single Match
    osRtcFn_8000c270
   
   Library: KioskDefault 0 0 */

void osRtcFn_8000c270(void) { //8000C270
  _osSramIrqDisableVal = 0;
  scb_locked = 0;
  scb_sync = _osReadRomBlock(0x80325e20);
  if (scb_sync == 0) {
                    
    OSPanic("OSRtc.c",300,"Failed assertion Scb.sync");
  }
  DAT_80325e60 = 0x40;
  return;
}


/* Library Function - Single Match
    osRtcFn_8000c2e0
   
   Library: KioskDefault 0 0 */

SramState * _osOpenSram(int param1) { //8000C2E0
  BOOL_ level;
  SramState *result;
  
  level = OSDisableInterrupts();
  if (scb_locked != 0) {
                    
    OSPanic("OSRtc.c",0x140,"Failed assertion !Scb.locked");
  }
  if (true) {
    scb_locked = 1;
    result = (SramState *)(SramState_80325e20.flash0Id + param1 + -0x14);
    _osSramIrqDisableVal = level;
  }
  else {
    OSRestoreInterrupts(level);
    result = (SramState *)0x0;
  }
  return result;
}


SramState * osOpenSram(void) { //8000C36C
  SramState *pSVar1;
  
  pSVar1 = _osOpenSram(0);
  return pSVar1;
}


void FUN_8000c390(void) { //8000C390
  _osOpenSram(0x14);
  return;
}


/* Library Function - Single Match
    osRtcFn_8000c3b4
   
   Library: KioskDefault 0 0 */

uint _osCloseSram(int param1,uint param2) { //8000C3B4
  u32 *puVar1;
  
  if (scb_locked == 0) {
                    
    OSPanic("OSRtc.c",0x162,"Failed assertion Scb.locked");
  }
  if (param1 != 0) {
    if (param2 == 0) {
      SramState_80325e20.checksum2 = 0;
      SramState_80325e20.checksum1 = 0;
      for (puVar1 = &SramState_80325e20.rtcOffset; puVar1 < SramState_80325e20.flash0Id;
          puVar1 = (u32 *)((int)puVar1 + 2)) {
        SramState_80325e20.checksum1 = SramState_80325e20.checksum1 + *(ushort *)puVar1;
        SramState_80325e20.checksum2 = SramState_80325e20.checksum2 + ~*(ushort *)puVar1;
      }
    }
    if (param2 < DAT_80325e60) {
      DAT_80325e60 = param2;
    }
    scb_sync = WriteSram((int)(SramState_80325e20.flash0Id + (DAT_80325e60 - 0x14)),DAT_80325e60,
                         0x40 - DAT_80325e60);
    if (scb_sync != 0) {
      DAT_80325e60 = 0x40;
    }
  }
  scb_locked = 0;
  OSRestoreInterrupts(_osSramIrqDisableVal);
  return scb_sync;
}


void osCloseSram(int param1) { //8000C4C0
  _osCloseSram(param1,0);
  return;
}


void FUN_8000c4ec(int param_1) { //8000C4EC
  _osCloseSram(param_1,0x14);
  return;
}

