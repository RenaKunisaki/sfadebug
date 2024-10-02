
/* Library Function - Single Match
    initHeaps
   
   Library: KioskDefault 0 0 */

void initHeaps(void) { //8007B3A4
  int iVar1;
  undefined *param1;
  size_t size;
  void *pvVar2;
  void *arenaEnd;
  OSHeapHandle heap;
  
  numHeaps = 0;
  pvVar2 = OSGetArenaLo();
  iVar1 = (curTvParams->fbWidth + 0xf & 0xfff0) * (uint)curTvParams->xfbHeight * 2;
  pFrameBuffer_80398b74 = (undefined *)((int)pvVar2 + 0x1fU & 0xffffffe0);
  pFrameBuffer_80398b70 = pFrameBuffer_80398b74 + iVar1;
  param1 = pFrameBuffer_80398b70 + iVar1;
  osSetArenaLo(param1);
  arenaEnd = OSGetArenaHi();
  pvVar2 = OSInitAlloc(param1,arenaEnd,1);
  osSetArenaLo(pvVar2);
  pvVar2 = (void *)((int)pvVar2 + 0x1fU & 0xffffffe0);
  heap = OSCreateHeap(pvVar2,(void *)((uint)arenaEnd & 0xffffffe0));
  OSSetCurrentHeap(heap);
  size = (int)(void *)((uint)arenaEnd & 0xffffffe0) + (-0x5a0000 - (int)pvVar2);
  pvVar2 = OSAllocFromHeap(DAT_80396730,size);
  memset_(pvVar2,0,size);
  DCFlushRange(pvVar2,size);
  heapInit(pvVar2,size,0x2ee);
  pvVar2 = OSAllocFromHeap(DAT_80396730,0x500000);
  memset_(pvVar2,0,0x500000);
  DCFlushRange(pvVar2,0x500000);
  heapInit(pvVar2,0x500000,0x5aa);
  pvVar2 = OSAllocFromHeap(DAT_80396730,0x9ffa0);
  if (pvVar2 == (void *)0x0) {
                    
    OSPanic("mm_dolphin.c",0x142,"Memory region setup is too big");
  }
  memset_(pvVar2,0,0x9ffa0);
  DCFlushRange(pvVar2,0x9ffa0);
  heapInit(pvVar2,0x9ffa0,0x76c);
  freeFn_8007bd28(2);
  heapCount_80398a0a = 0;
  return;
}

