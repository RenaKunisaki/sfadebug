
/* Library Function - Single Match
    aramDmaFn_80019490
   
   Library: KioskDefault 0 0 */

void ARStartDMA(int param1,uint param2,undefined4 param3,uint param4) { //80019490
  ushort uVar1;
  BOOL_ level;
  
  level = OSDisableInterrupts();
  uVar1 = dsp_CSR;
  if ((uVar1 & 0x200) != 0) {
                    
    OSPanic("ar.c",0x148,"ARAM DMA already in progress");
  }
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("ar.c",0x149,"AR: Main memory address is not a multiple of 32 bytes!");
  }
  if ((param4 & 0x1f) != 0) {
                    
    OSPanic("ar.c",0x14a,"AR: DMA transfer length is not a multiple of 32 bytes!");
  }
  uVar1 = dsp_AR_DMA_MMADDR_H._0_2_;
  dsp_AR_DMA_MMADDR_H._0_2_ = uVar1 & 0xfc00 | (ushort)(param2 >> 0x10);
  uVar1 = dsp_AR_DMA_MMADDR_H._2_2_;
  dsp_AR_DMA_MMADDR_H._2_2_ = uVar1 & 0x1f | (ushort)param2;
  uVar1 = dsp_AR_DMA_ARADDR_H._0_2_;
  dsp_AR_DMA_ARADDR_H._0_2_ = uVar1 & 0xfc00 | (ushort)((uint)param3 >> 0x10);
  uVar1 = dsp_AR_DMA_ARADDR_H._2_2_;
  dsp_AR_DMA_ARADDR_H._2_2_ = uVar1 & 0x1f | (ushort)param3;
  uVar1 = dsp_AR_DMA_CNT_H._0_2_;
  dsp_AR_DMA_CNT_H._0_2_ = uVar1 & 0x7fff | (ushort)(param1 << 0xf);
  uVar1 = dsp_AR_DMA_CNT_H._0_2_;
  dsp_AR_DMA_CNT_H._0_2_ = uVar1 & 0xfc00 | (ushort)(param4 >> 0x10);
  uVar1 = dsp_AR_DMA_CNT_H._2_2_;
  dsp_AR_DMA_CNT_H._2_2_ = uVar1 & 0x1f | (ushort)param4;
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    ARInit
   
   Library: KioskDefault 0 0 */

void ARInit(u32 *stack_index_addr,u32 num_entries) { //80019600
  ushort uVar1;
  BOOL_ level;
  int size;
  uint refresh;
  
  if (DAT_8039841c != 1) {
    level = OSDisableInterrupts();
    audioCb_80398408 = (undefined *)0x0;
    __OSSetInterruptHandler(6,FUN_8001977c);
    __OSUnmaskInterrupts(0x2000000);
    aramUserBase = &DAT_00004000;
    refresh = (uint)(((float)((double)CONCAT44(0x43300000,busClockMhz) - 4503599627370496.0) /
                     2.025e+08) * 196.0);
    arNumEntries = num_entries;
    arStackIndexAddr = (undefined *)stack_index_addr;
    if (196.0 < (float)((double)CONCAT44(0x43300000,refresh & 0xffff) - 4503599627370496.0)) {
                    
      OSPanic("ar.c",0x227,"ARInit(): ILLEGAL SDRAM REFRESH VALUE");
    }
    uVar1 = dsp_AR_REFRESH;
    dsp_AR_REFRESH = uVar1 & 0xff00 | (ushort)refresh & 0xff;
    __ARChecksize();
    DAT_8039841c = 1;
    OSRestoreInterrupts(level);
    size = getAramSize();
    OSReport("ARInit(): ARAM size        : %d bytes",size);
    OSReport("ARInit(): USER Base address: 0x%08X",aramUserBase);
    OSReport("ARInit(): Refresh          : 0x%04X",refresh & 0xffff);
  }
  return;
}


/* Library Function - Single Match
    __ARChecksize
   
   Library: KioskDefault 0 0 */

void __ARChecksize(void) { //800199EC
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  int aiStack_e0 [16];
  undefined4 auStack_a0 [16];
  int aiStack_60 [17];
  
  OSReport("__ARChecksize(): Initializing for RevB+ SDRAM controller...");
  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
    aiStack_60[uVar3] = -0x21524111;
    auStack_a0[uVar3] = 0xbad0bad0;
  }
  DCFlushRange(aiStack_60,0x20);
  DCFlushRange(auStack_a0,0x20);
  do {
    uVar4 = dsp_AR_MODE;
  } while ((uVar4 & 1) == 0);
  uVar4 = dsp_AR_SIZE;
  dsp_AR_SIZE = uVar4 & 0xffc0 | 0x24;
  ARStartDMA(auStack_a0,0,0x20);
  ARStartDMA(auStack_a0,0x200000,0x20);
  ARStartDMA(auStack_a0,0x200,0x20);
  ARStartDMA(auStack_a0,0x1000000,0x20);
  ARStartDMA(auStack_a0,0x400000,0x20);
  memset_(aiStack_e0,0,0x20);
  DCFlushRange(aiStack_e0,0x20);
  ARStartDMA(aiStack_60,0,0x20);
  ARStartDMA(aiStack_e0,0,0x20);
  DCInvalidateRange(aiStack_e0,0x20);
  if (aiStack_e0[0] != aiStack_60[0]) {
                    
    OSPanic("ar.c",0x3b2,"__ARChecksize(): Internal ARAM not present!");
  }
  memset_(aiStack_e0,0,0x20);
  DCFlushRange(aiStack_e0,0x20);
  ARStartDMA(aiStack_e0,0x200000,0x20);
  DCInvalidateRange(aiStack_e0,0x20);
  if (aiStack_e0[0] == aiStack_60[0]) {
    uVar4 = 0;
    iVar5 = 0x200000;
  }
  else {
    memset_(aiStack_e0,0,0x20);
    DCFlushRange(aiStack_e0,0x20);
    ARStartDMA(aiStack_e0,0x1000000,0x20);
    DCInvalidateRange(aiStack_e0,0x20);
    if (aiStack_e0[0] == aiStack_60[0]) {
      uVar4 = 1;
      iVar5 = 0x400000;
    }
    else {
      memset_(aiStack_e0,0,0x20);
      DCFlushRange(aiStack_e0,0x20);
      ARStartDMA(aiStack_e0,0x200,0x20);
      DCInvalidateRange(aiStack_e0,0x20);
      if (aiStack_e0[0] == aiStack_60[0]) {
        uVar4 = 2;
        iVar5 = 0x800000;
      }
      else {
        memset_(aiStack_e0,0,0x20);
        DCFlushRange(aiStack_e0,0x20);
        ARStartDMA(aiStack_e0,0x400000,0x20);
        DCInvalidateRange(aiStack_e0,0x20);
        if (aiStack_e0[0] == aiStack_60[0]) {
          uVar4 = 3;
          iVar5 = 0x1000000;
        }
        else {
          uVar4 = 4;
          iVar5 = 0x2000000;
        }
      }
    }
  }
  uVar1 = dsp_AR_SIZE;
  dsp_AR_SIZE = uVar1 & 0xffc0 | 0x20 | uVar4;
  ARStartDMA(auStack_a0,iVar5,0x20);
  ARStartDMA(auStack_a0,iVar5 + 0x200000,0x20);
  ARStartDMA(auStack_a0,iVar5 + 0x1000000,0x20);
  ARStartDMA(auStack_a0,iVar5 + 0x200,0x20);
  ARStartDMA(auStack_a0,iVar5 + 0x400000,0x20);
  memset_(aiStack_e0,0,0x20);
  DCFlushRange(aiStack_e0,0x20);
  ARStartDMA(aiStack_60,iVar5,0x20);
  ARStartDMA(aiStack_e0,iVar5,0x20);
  DCInvalidateRange(aiStack_e0,0x20);
  if (aiStack_e0[0] == aiStack_60[0]) {
    memset_(aiStack_e0,0,0x20);
    DCFlushRange(aiStack_e0,0x20);
    ARStartDMA(aiStack_e0,iVar5 + 0x200000,0x20);
    DCInvalidateRange(aiStack_e0,0x20);
    if (aiStack_e0[0] == aiStack_60[0]) {
      iVar5 = iVar5 + 0x200000;
    }
    else {
      memset_(aiStack_e0,0,0x20);
      DCFlushRange(aiStack_e0,0x20);
      ARStartDMA(aiStack_e0,iVar5 + 0x1000000,0x20);
      DCInvalidateRange(aiStack_e0,0x20);
      if (aiStack_e0[0] == aiStack_60[0]) {
        uVar4 = uVar4 | 8;
        iVar5 = iVar5 + 0x400000;
      }
      else {
        memset_(aiStack_e0,0,0x20);
        DCFlushRange(aiStack_e0,0x20);
        ARStartDMA(aiStack_e0,iVar5 + 0x200,0x20);
        DCInvalidateRange(aiStack_e0,0x20);
        if (aiStack_e0[0] == aiStack_60[0]) {
          uVar4 = uVar4 | 0x10;
          iVar5 = iVar5 + 0x800000;
        }
        else {
          memset_(aiStack_e0,0,0x20);
          DCFlushRange(aiStack_e0,0x20);
          ARStartDMA(aiStack_e0,iVar5 + 0x400000,0x20);
          DCInvalidateRange(aiStack_e0,0x20);
          if (aiStack_e0[0] == aiStack_60[0]) {
            uVar4 = uVar4 | 0x18;
            iVar5 = iVar5 + 0x1000000;
          }
          else {
            uVar4 = uVar4 | 0x20;
            iVar5 = iVar5 + 0x2000000;
          }
        }
      }
    }
    OSReport("__ARChecksize(): ARAM Expansion present");
    uVar1 = dsp_AR_SIZE;
    dsp_AR_SIZE = uVar1 & 0xffc0 | uVar4;
  }
  piVar2 = (int *)OSPhysicalToUncached(0xd0);
  *piVar2 = iVar5;
  aramSize = iVar5;
  return;
}

