
/* Library Function - Single Match
    siInterrupt
   
   Library: KioskDefault 0 0 */

void serialIrqHandler(undefined4 param_1,undefined4 param2) { //8000C6F8
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  iVar1 = si_chan;
  if (si_chan == -1) {
                    
    OSPanic("OSSerial.c",0xe2,"Failed assertion Si.chan != CHAN_NONE");
  }
  uVar3 = FUN_8000c538();
  pcVar2 = DAT_802d3140;
  DAT_802d3140 = (code *)0x0;
  FUN_8000c61c(iVar1);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(iVar1,uVar3,param2);
  }
  return;
}


void siInit(void) { //8000C788
  dword dVar1;
  
  DAT_80325ed8 = 0xffffffff;
  DAT_80325eb8 = 0xffffffff;
  DAT_80325e98 = 0xffffffff;
  DAT_80325e78 = 0xffffffff;
  si_POLL = 0;
  do {
    dVar1 = si_COMCSR;
  } while ((dVar1 & 1) != 0);
  si_COMCSR = 0x80000000;
  __OSSetInterruptHandler(0x14,serialIrqHandler);
  __OSUnmaskInterrupts(0x800);
  return;
}


/* Library Function - Single Match
    SITransfer
   
   Library: KioskDefault 0 0 */

undefined4
SITransfer(uint chan,int param2,uint outputSize,undefined4 param4,uint inputSize,int param6) { //8000C808
  dword dVar1;
  BOOL_ level;
  undefined4 uVar2;
  uint uVar3;
  uint local_30;
  
  if (((int)chan < 0) || (3 < (int)chan)) {
                    
    OSPanic("OSSerial.c",0x12a,"SITransfer(): invalid channel.");
  }
  if ((outputSize != 0) && (outputSize < 0x81)) {
    if ((inputSize != 0) && (inputSize < 0x81)) {
      level = OSDisableInterrupts();
      if (si_chan == 0xffffffff) {
        dVar1 = si_COMCSR;
        if ((dVar1 & 0x80000001) != 0) {
                    
          OSPanic("OSSerial.c",0x138,"Failed assertion (__SIRegs[SI_COMCSR_IDX] & (SI_COMCSR_TSTART_MASK | SI_COMCSR_TCINT_MASK)) == 0");
        }
        dVar1 = si_SR;
        si_SR = dVar1 & 0xf000000 >> ((chan & 7) << 3);
        si_chan = chan;
        si_inputSize = inputSize;
        DAT_802d313c = param4;
        DAT_802d3140 = param6;
        for (uVar3 = 0; uVar3 < outputSize + 3 >> 2; uVar3 = uVar3 + 1) {
          *(undefined4 *)(&JOY_REG + (uVar3 + 0x20) * 4) = *(undefined4 *)(param2 + uVar3 * 4);
        }
        if (outputSize == 0x80) {
          outputSize = 0;
        }
        if (inputSize == 0x80) {
          inputSize = 0;
        }
        local_30 = CONCAT31(CONCAT21(CONCAT11((param6 != 0) << 6,(char)outputSize),(char)inputSize),
                            (char)(chan << 1)) & 0xff7f7f06 | 0x80000001;
        si_COMCSR = local_30;
        OSRestoreInterrupts(level);
        uVar2 = 1;
      }
      else {
        OSRestoreInterrupts(level);
        uVar2 = 0;
      }
      return uVar2;
    }
                    
    OSPanic("OSSerial.c",0x12e,"SITransfer(): input size is out of range (must be 1 to 128).");
  }
                    
  OSPanic("OSSerial.c",300,"SITransfer(): output size is out of range (must be 1 to 128).");
}


dword get_siSR(void) { //8000CA10
  dword dVar1;
  
  dVar1 = si_SR;
  return dVar1;
}


/* Library Function - Single Match
    SISetCommand
   
   Library: KioskDefault 0 0 */

void SISetCommand(int chan,undefined4 cmd) { //8000CA20
  if ((-1 < chan) && (chan < 4)) {
    *(undefined4 *)(&JOY_REG + chan * 0xc) = cmd;
    return;
  }
                    
  OSPanic("OSSerial.c",0x197,"SISetCommand(): invalid channel.");
}


void set_SR_to_8000_0000(void) { //8000CA90
  si_SR = 0x80000000;
  return;
}


/* Library Function - Single Match
    SISetXY
   
   Library: KioskDefault 0 0 */

uint SISetXY(uint param1,uint param2) { //8000CAA0
  uint uVar1;
  BOOL_ level;
  
  if (param1 < 8) {
                    
    OSPanic("OSSerial.c",0x1ca,s_SISetXY____x_is_out_of_range__8_<_802d32c4);
  }
  if (0xff < param1) {
                    
    OSPanic("OSSerial.c",0x1cb,s_SISetXY____x_is_out_of_range__8_<_802d32c4);
  }
  if (0xff < param2) {
                    
    OSPanic("OSSerial.c",0x1cc,s_SISetXY____y_is_out_of_range__0_<_802d32f4);
  }
  level = OSDisableInterrupts();
  uVar1 = DAT_802d3134 & 0xfc0000ff | param1 << 0x10 | param2 << 8;
  DAT_802d3134 = uVar1;
  OSRestoreInterrupts(level);
  return uVar1;
}


/* Library Function - Single Match
    SIEnablePolling
   
   Library: KioskDefault 0 0 */

uint SIEnablePolling(uint param1) { //8000CB64
  uint uVar1;
  BOOL_ level;
  
  if ((param1 & 0xfffffff) != 0) {
                    
    OSPanic("OSSerial.c",0x1e8,"SIEnablePolling(): invalid chan bit(s).");
  }
  uVar1 = DAT_802d3134;
  if (param1 != 0) {
    level = OSDisableInterrupts();
    si_POLL = 0;
    uVar1 = param1 >> 0x18 & 0xf0;
    if (uVar1 == 0) {
                    
      OSPanic("OSSerial.c",0x202,"Failed assertion en");
    }
    uVar1 = DAT_802d3134 & ~(uVar1 >> 4) | param1 >> 0x18 & (uVar1 >> 4 | 0x3fffff0);
    si_SR = 0x80000000;
    si_POLL = uVar1;
    DAT_802d3134 = uVar1;
    OSRestoreInterrupts(level);
  }
  return uVar1;
}


/* Library Function - Single Match
    SIDisablePolling
   
   Library: KioskDefault 0 0 */

uint SIDisablePolling(uint param1) { //8000CC4C
  BOOL_ level;
  uint uVar1;
  
  if ((param1 & 0xfffffff) != 0) {
                    
    OSPanic("OSSerial.c",0x22d,"SIDisablePolling(): invalid chan bit(s).");
  }
  uVar1 = DAT_802d3134;
  if (param1 != 0) {
    level = OSDisableInterrupts();
    uVar1 = param1 >> 0x18 & 0xf0;
    if (uVar1 == 0) {
                    
      OSPanic("OSSerial.c",0x23a,"Failed assertion poll");
    }
    uVar1 = DAT_802d3134 & ~uVar1;
    si_POLL = uVar1;
    DAT_802d3134 = uVar1;
    OSRestoreInterrupts(level);
  }
  return uVar1;
}


/* Library Function - Single Match
    SIGetResponse
   
   Library: KioskDefault 0 0 */

void SIGetResponse(int param1,undefined4 *param2) { //8000CCF4
  if ((-1 < param1) && (param1 < 4)) {
    *param2 = *(undefined4 *)(&JOY_REG + (param1 * 3 + 1) * 4);
    param2[1] = *(undefined4 *)(&JOY_REG + (param1 * 3 + 2) * 4);
    return;
  }
                    
  OSPanic("OSSerial.c",0x250,"SIGetResponse(): invalid channel.");
}


/* Library Function - Single Match
    osSerialFn_8000cd84
   
   Library: KioskDefault 0 0 */

void exiCb_8000cd84(int param1) { //8000CD84
  int iVar1;
  int iVar2;
  int unaff_r31;
  uint *puVar3;
  OSTime OVar4;
  
  iVar2 = (param1 + 0x7fcda108) / 0x28;
  if ((-1 < iVar2) && (iVar2 < 4)) {
    OVar4 = OSGetTime();
    if (((uint)((ulonglong)OVar4 >> 0x20) ^ 0x80000000) <
        (uint)((uint)OVar4 < *(uint *)(unaff_r31 + 0x1c)) +
        (*(uint *)(unaff_r31 + 0x18) ^ 0x80000000)) {
                    
      OSPanic("OSSerial.c",0x267,s_Failed_assertion_packet_>time_<__802d33fc);
    }
    iVar1 = iVar2 * 0x20;
    puVar3 = &DAT_80325e78 + iVar2 * 8;
    if ((*puVar3 != 0xffffffff) &&
       (iVar2 = SITransfer(*puVar3,*(int *)(&DAT_80325e7c + iVar1),*(uint *)(&DAT_80325e80 + iVar1),
                           *(undefined4 *)(&DAT_80325e84 + iVar1),*(uint *)(&DAT_80325e88 + iVar1),
                           *(int *)(&DAT_80325e8c + iVar1)), iVar2 != 0)) {
      *puVar3 = 0xffffffff;
    }
    return;
  }
                    
  OSPanic("OSSerial.c",0x266,s_Failed_assertion_0_<__chan_&&_ch_802d33c8);
}

