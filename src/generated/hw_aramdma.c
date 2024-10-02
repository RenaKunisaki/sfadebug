
void aramDmaFn_80058964(undefined4 param1,undefined4 param2,undefined4 param3,int param4) { //80058964
  BOOL_ level;
  
  do {
  } while (0xf < DAT_803986ad);
  level = OSDisableInterrupts();
  *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb481c) = 0x2a;
  *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb4818) = 0;
  *(uint *)((uint)DAT_803986ac * 0x20 + -0x7fcb4814) = (uint)(param4 != 0);
  *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb4810) = param1;
  *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb480c) = param2;
  *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb4808) = param3;
  *(undefined **)((uint)DAT_803986ac * 0x20 + -0x7fcb4804) = &LAB_80058954;
  arqFn_8001a228((undefined4 *)(&DAT_8034b7e0 + (uint)DAT_803986ac * 0x20),
                 *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb481c),
                 *(int *)((uint)DAT_803986ac * 0x20 + -0x7fcb4818),
                 *(int *)((uint)DAT_803986ac * 0x20 + -0x7fcb4814),
                 *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb4810),
                 *(undefined4 *)((uint)DAT_803986ac * 0x20 + -0x7fcb480c),
                 *(uint *)((uint)DAT_803986ac * 0x20 + -0x7fcb4808),
                 *(int *)((uint)DAT_803986ac * 0x20 + -0x7fcb4804));
  DAT_803986ad = DAT_803986ad + 1;
  DAT_803986ac = (char)(DAT_803986ac + 1) + (char)((int)(DAT_803986ac + 1) >> 4) * -0x10;
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    musyxInitAramHandler_
   
   Library: KioskDefault 0 0 */

void musyxInitAramHandler_(uint aramSize) { //80058B18
  int param2;
  void *addr;
  uint uVar1;
  
  if (aramSize < 0x501) {
                    
    OSPanic("hw_aramdma.c",0x81,"ARAM size is too small");
  }
  param2 = ret0x4000_8001976C();
  addr = audioAlloc(0x500);
  if (addr == (void *)0x0) {
                    
    OSPanic("hw_aramdma.c",0x8a,"Could not allocate temporary storage");
  }
  for (uVar1 = 0; uVar1 < 0x280; uVar1 = uVar1 + 1) {
    *(undefined2 *)((int)addr + uVar1 * 2) = 0;
  }
  DCFlushRange(addr,0x500);
  FUN_80058944();
  aramDmaFn_80058964(addr,param2,0x500,0);
  FUN_80058b08();
  FUN_80059390(addr);
  aramSizeVar_803986a0 = param2 + aramSize;
  uVar1 = getAramSize();
  if (uVar1 < aramSizeVar_803986a0) {
    aramSizeVar_803986a0 = getAramSize();
  }
  aramNextUploadDest = param2 + 0x500;
  FUN_80058d5c();
  OSReport("MusyX ARAM handler initialized");
  return;
}


/* Library Function - Single Match
    aramUpload
   
   Library: KioskDefault 0 0 */

int aramUpload(void *src,int size) { //80058C24
  uint size_00;
  int iVar1;
  
  size_00 = size + 0x1fU & 0xffffffe0;
  if (aramMaxSize < aramNextUploadDest + size_00) {
                    
    OSPanic("hw_aramdma.c",0xbf,"Data will not fit in remaining ARAM space");
  }
  OSReport("Uploading %d bytes to ARAM from %08x to %08x...",size_00,src,aramNextUploadDest);
  if (((uint)src & 0x1f) != 0) {
                    
    OSPanic("hw_aramdma.c",0xc3,"MRAM address is not aligned properly");
  }
  DCFlushRange(src,size_00);
  aramDmaFn_80058964(src,aramNextUploadDest,size_00,0);
  iVar1 = aramNextUploadDest;
  aramNextUploadDest = aramNextUploadDest + size_00;
  return iVar1;
}


/* Library Function - Single Match
    aramFree
   
   Library: KioskDefault 0 0 */

void aramFree(void *addr,int size) { //80058CF0
  aramNextUploadDest = (void *)((int)aramNextUploadDest - (size + 0x1fU & 0xffffffe0));
  if (addr != aramNextUploadDest) {
                    
    OSPanic("hw_aramdma.c",0xfa,"Current ARAM address does not match originally allocated one");
  }
  return;
}


/* Library Function - Single Match
    aramDmaStreamFn_80058ddc
   
   Library: KioskDefault 0 0 */

undefined4 aramDmaStreamFn_80058ddc(byte streamBufId,undefined4 *param2) { //80058DDC
  if (streamBufId == 0xff) {
                    
    OSPanic("hw_aramdma.c",0x182,"Stream buffer ID is invalid");
  }
  if (param2 != (undefined4 *)0x0) {
    *param2 = *(undefined4 *)(&DAT_8034b9e8 + (uint)streamBufId * 0x10);
  }
  return *(undefined4 *)(&DAT_8034b9e4 + (uint)streamBufId * 0x10);
}

