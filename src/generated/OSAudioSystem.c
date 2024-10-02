
/* Library Function - Single Match
    __OSInitAudioSystem
   
   Library: KioskDefault 0 0 */

void __OSInitAudioSystem(void) { //800088C4
  ushort uVar1;
  word wVar2;
  u32 uVar3;
  u32 uVar4;
  
  memcpy(&DAT_81000000,&DAT_802d2018,0x80);
  DCFlushRange(&DAT_81000000,0x80);
  dsp_AR_SIZE = 0x43;
  uVar1 = dsp_CSR;
  if ((uVar1 & 0x200) != 0) {
                    
    OSPanic("OSAudioSystem.c",0x67,"__OSInitAudioSystem(): ARAM DMA already in progress");
  }
  uVar1 = dsp_CSR;
  if ((uVar1 & 0x400) != 0) {
                    
    OSPanic("OSAudioSystem.c",0x6b,"__OSInitAudioSystem(): DSP DMA already in progress");
  }
  uVar1 = dsp_CSR;
  if ((uVar1 & 4) == 0) {
                    
    OSPanic("OSAudioSystem.c",0x6f,"__OSInitAudioSystem(): DSP already working");
  }
  dsp_CSR = 0x8ac;
  uVar1 = dsp_CSR;
  dsp_CSR = uVar1 | 1;
  do {
    uVar1 = dsp_CSR;
  } while ((uVar1 & 1) != 0);
  dsp_DSPMAIL_HI = 0;
  do {
    wVar2 = dsp_CPUMAIL_HI;
  } while ((wVar2 & 0x8000) != 0);
  dsp_AR_DMA_MMADDR_H = 0x1000000;
  dsp_AR_DMA_ARADDR_H = 0;
  dsp_AR_DMA_CNT_H = 0x20;
  uVar1 = dsp_CSR;
  while ((uVar1 & 0x20) == 0) {
    uVar1 = dsp_CSR;
  }
  dsp_CSR = uVar1;
  uVar3 = getTBLR();
  do {
    uVar4 = getTBLR();
  } while ((int)(uVar4 - uVar3) < 0x892);
  dsp_AR_DMA_MMADDR_H = 0x1000000;
  dsp_AR_DMA_ARADDR_H = 0;
  dsp_AR_DMA_CNT_H = 0x20;
  uVar1 = dsp_CSR;
  while ((uVar1 & 0x20) == 0) {
    uVar1 = dsp_CSR;
  }
  dsp_CSR = uVar1;
  uVar1 = dsp_CSR;
  dsp_CSR = uVar1 & 0xf7ff;
  do {
    uVar1 = dsp_CSR;
  } while ((uVar1 & 0x400) != 0);
  uVar1 = dsp_CSR;
  dsp_CSR = uVar1 & 0xfffb;
  uVar1 = dsp_CPUMAIL_HI;
  while ((uVar1 & 0x8000) == 0) {
    uVar1 = dsp_CPUMAIL_HI;
  }
  wVar2 = dsp_CPUMAIL_LO;
  if (CONCAT22(uVar1,wVar2) != -0x7fabbcb8) {
                    
    OSPanic("OSAudioSystem.c",0xb7,"__OSInitAudioSystem(): DSP returns invalid message");
  }
  uVar1 = dsp_CSR;
  dsp_CSR = uVar1 | 4;
  dsp_CSR = 0x8ac;
  uVar1 = dsp_CSR;
  dsp_CSR = uVar1 | 1;
  do {
    uVar1 = dsp_CSR;
  } while ((uVar1 & 1) != 0);
  return;
}

