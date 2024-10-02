
/* Library Function - Single Match
    AIStartDMA
   
   Library: KioskDefault 0 0 */

void AIStartDMA(void) { //800188A4
  ushort uVar1;
  undefined4 in_r3;
  BOOL_ level;
  uint in_r4;
  
  level = OSDisableInterrupts();
  uVar1 = dsp_DMA_START_HI;
  dsp_DMA_START_HI = uVar1 & 0xfc00 | (ushort)((uint)in_r3 >> 0x10);
  uVar1 = dsp_DMA_START_LO;
  dsp_DMA_START_LO = uVar1 & 0x1f | (ushort)in_r3;
  if ((in_r4 & 0x1f) != 0) {
                    
    OSPanic("ai.c",0x12e,"AIStartDMA: length must be multiple of 32 bytes");
  }
  uVar1 = dsp_DMA_LENGTH;
  dsp_DMA_LENGTH = uVar1 & 0x8000 | (ushort)(in_r4 >> 5);
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    aiGxFn_80018994
   
   Library: KioskDefault 0 0 */

void AISetStreamPlayState(uint param1) { //80018994
  u32 uVar1;
  uint uVar2;
  uint param1_00;
  BOOL_ level;
  
  uVar1 = AIGetStreamPlayState();
  if (param1 != uVar1) {
    uVar2 = AIGetStreamSamplingRate();
    if ((uVar2 == 0) && (param1 == 1)) {
      param1_00 = FUN_80018e3c();
      uVar1 = AIGetStreamPlayState();
      AISetStreamVolLeft(0);
      AISetStreamVolRight(0);
      level = OSDisableInterrupts();
      __AI_SRC_INIT();
      uVar2 = ai_CR;
      ai_CR = uVar2 & 0xffffffdf | 0x20;
      uVar2 = ai_CR;
      ai_CR = uVar2 & 0xfffffffe | 1;
      OSRestoreInterrupts(level);
      AISetStreamVolRight(param1_00);
      AISetStreamVolLeft(uVar1);
    }
    else {
      if ((param1 & 0xfffffffe) != 0) {
                    
        OSPanic("ai.c",0x27f,"GX Internal: Register field out of range");
      }
      uVar2 = ai_CR;
      ai_CR = uVar2 & 0xfffffffe | param1;
    }
  }
  return;
}


/* Library Function - Single Match
    aiStreamFn_80018a9c
   
   Library: KioskDefault 0 0 */

void AISetDSPSampleRate(uint param1) { //80018A9C
  uint uVar1;
  u32 param1_00;
  uint param1_01;
  u32 uVar2;
  uint uVar3;
  BOOL_ level;
  
  uVar1 = FUN_80018be0();
  if (param1 != uVar1) {
    uVar1 = ai_CR;
    ai_CR = uVar1 & 0xffffffbf;
    if (param1 == 0) {
      param1_00 = AIGetStreamPlayState();
      param1_01 = FUN_80018e3c();
      uVar2 = AIGetStreamPlayState();
      uVar3 = AIGetStreamSamplingRate();
      AISetStreamVolRight(0);
      AISetStreamVolLeft(0);
      level = OSDisableInterrupts();
      __AI_SRC_INIT();
      uVar1 = ai_CR;
      ai_CR = uVar1 & 0xffffffdf | 0x20;
      if ((uVar3 & 0xfffffffe) != 0) {
                    
        OSPanic("ai.c",0x2d9,"GX Internal: Register field out of range");
      }
      uVar1 = ai_CR;
      ai_CR = uVar1 & 0xfffffffd | uVar3 << 1;
      if ((uVar2 & 0xfffffffe) != 0) {
                    
        OSPanic("ai.c",0x2da,"GX Internal: Register field out of range");
      }
      uVar1 = ai_CR;
      ai_CR = uVar1 & 0xfffffffe | uVar2;
      uVar1 = ai_CR;
      ai_CR = uVar1 | 0x40;
      OSRestoreInterrupts(level);
      AISetStreamVolRight(param1_00);
      AISetStreamVolLeft(param1_01);
    }
  }
  return;
}


/* Library Function - Single Match
    _aiSetStreamSamplingRate_80018c40
   
   Library: KioskDefault 0 0 */

void __AI_set_stream_sample_rate(uint param1) { //80018C40
  uint uVar1;
  uint uVar2;
  u32 param1_00;
  u32 param1_01;
  uint param1_02;
  BOOL_ level;
  
  uVar2 = AIGetStreamSamplingRate();
  if (param1 != uVar2) {
    param1_00 = AIGetStreamPlayState();
    param1_01 = AIGetStreamPlayState();
    param1_02 = FUN_80018e3c();
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    uVar2 = ai_CR;
    uVar1 = ai_CR;
    ai_CR = uVar1 & 0xffffffbf;
    level = OSDisableInterrupts();
    __AI_SRC_INIT();
    uVar1 = ai_CR;
    ai_CR = uVar1 | uVar2 & 0x40;
    uVar2 = ai_CR;
    ai_CR = uVar2 & 0xffffffdf | 0x20;
    if ((param1 & 0xfffffffe) != 0) {
                    
      OSPanic("ai.c",0x369,"GX Internal: Register field out of range");
    }
    uVar2 = ai_CR;
    ai_CR = uVar2 & 0xfffffffd | param1 << 1;
    OSRestoreInterrupts(level);
    AISetStreamPlayState(param1_00);
    AISetStreamVolRight(param1_01);
    AISetStreamVolLeft(param1_02);
  }
  return;
}


/* Library Function - Single Match
    aiGxFn_80018d60
   
   Library: KioskDefault 0 0 */

void AISetStreamVolRight(uint param1) { //80018D60
  uint uVar1;
  
  if (false) {
                    
    OSPanic("ai.c",0x3a3,"GX Internal: Register field out of range");
  }
  uVar1 = ai_VR;
  ai_VR = uVar1 & 0xffffff00 | param1 & 0xff;
  return;
}


/* Library Function - Single Match
    aiFn_80018dd8
   
   Library: KioskDefault 0 0 */

void AISetStreamVolLeft(uint param1) { //80018DD8
  uint uVar1;
  
  if (false) {
                    
    OSPanic("ai.c",0x3cc,"GX Internal: Register field out of range");
  }
  uVar1 = ai_VR;
  ai_VR = (param1 & 0xff) << 8 | uVar1 & 0xffff00ff;
  return;
}


/* Library Function - Single Match
    AIInit
   
   Library: KioskDefault 0 0 */

void AIInit(u8 *stack) { //80018E50
  if (audio_aiIsInit != TRUE) {
    audioRate31524._4_4_ = ((busClockMhz / 500000) * 0x7b24) / 8000;
    audioRate31524._0_4_ = 0;
    audioRate42042._4_4_ = ((busClockMhz / 500000) * 0xa428) / 8000;
    audioRate42042._0_4_ = 0;
    audioRate42000._4_4_ = ((busClockMhz / 500000) * 42000) / 8000;
    audioRate42000._0_4_ = 0;
    audioRate63000._4_4_ = ((busClockMhz / 500000) * 63000) / 8000;
    audioRate63000._0_4_ = 0;
    audioRate3000._4_4_ = ((busClockMhz / 500000) * 3000) / 8000;
    audioRate3000._0_4_ = 0;
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    FUN_80018988(0);
    FUN_8001896c();
    __AI_set_stream_sample_rate(1);
    AISetDSPSampleRate(0);
    OSReport("AIInit(): DSP is 32KHz");
    DAT_803983c8 = 0;
    PTR_FUN_803983cc = (undefined *)0x0;
    audio_aiStack = stack;
    if ((stack != (u8 *)0x0) && (((uint)stack & 7) == 0)) {
                    
      OSPanic("ai.c",0x444,"AIInit: stack must be 8-byte aligned");
    }
    __OSSetInterruptHandler(5,irq_DSP);
    __OSUnmaskInterrupts(0x4000000);
    __OSSetInterruptHandler(8,__AISHandler);
    __OSUnmaskInterrupts(0x800000);
    audio_aiIsInit = TRUE;
  }
  return;
}

