
/* Library Function - Single Match
    GXFlush
   
   Library: KioskDefault 0 0 */

void GXFlush(void) { //8001F930
  int iVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0xf0,"'GXFlush' is not allowed between GXBegin/GXEnd");
  }
  if (gx->flags4F0 != 0) {
    __GXSetDirtyState();
  }
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    GXFIFO._0_1_ = 0;
  }
  syscall_0();
  return;
}


/* Library Function - Single Match
    GXSetDrawSync
   
   Library: KioskDefault 0 0 */

void GXSetDrawSync(uint param1) { //8001F9B4
  BOOL_ level;
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x162,"'GXSetDrawSync' is not allowed between GXBegin/GXEnd");
  }
  level = OSDisableInterrupts();
  uVar1 = param1 & 0xffff | 0x48000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xd20) = uVar1;
  if (false) {
                    
    OSPanic("GXMisc.c",0x16f,"GX Internal: Register field out of range");
  }
  uVar1 = param1 & 0xffff | 0x47000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xd1c) = uVar1;
  GXFlush();
  OSRestoreInterrupts(level);
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXPixModeSync
   
   Library: KioskDefault 0 0 */

void GXPixModeSync(void) { //8001FAC4
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x20d,"'GXPixModeSync' is not allowed between GXBegin/GXEnd");
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = gx->field454_0x1dc;
  *(uint *)(pGxDebug->isRegInit + (gx->field454_0x1dc >> 0x16 & 0x3fc) + 0xc00) = gx->field454_0x1dc
  ;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXTexModeSync
   
   Library: KioskDefault 0 0 */

void GXTexModeSync(void) { //8001FB50
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x225,"'GXTexModeSync' is not allowed between GXBegin/GXEnd");
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x63000000;
  *(undefined4 *)(pGxDebug->isRegInit + 0xd8c) = 0x63000000;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXPokeAlphaMode
   
   Library: KioskDefault 0 0 */

void GXPokeAlphaMode(int param1,byte param2) { //8001FBD0
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x25f,"'GXPokeAlphaMode' is not allowed between GXBegin/GXEnd");
  }
  *(ushort *)(PTR_pe_Z_80398474 + 6) = (ushort)(param1 << 8) | (ushort)param2;
  return;
}


/* Library Function - Single Match
    GXPokeAlphaRead
   
   Library: KioskDefault 0 0 */

void GXPokeAlphaRead(uint param1) { //8001FC38
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x26a,"'GXPokeAlphaRead' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfffffffc) != 0) {
                    
    OSPanic("GXMisc.c",0x26d,"GX Internal: Register field out of range");
  }
  *(ushort *)(PTR_pe_Z_80398474 + 8) = (ushort)param1 & 0xfffb | 4;
  return;
}


/* Library Function - Single Match
    GXPokeAlphaUpdate
   
   Library: KioskDefault 0 0 */

void GXPokeAlphaUpdate(uint param1) { //8001FCC0
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x277,"'GXPokeAlphaUpdate' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXMisc.c",0x27a,"GX Internal: Register field out of range");
  }
  *(ushort *)(PTR_pe_Z_80398474 + 2) =
       *(ushort *)(PTR_pe_Z_80398474 + 2) & 0xffef | (ushort)(param1 << 4) & 0xff0;
  return;
}


/* Library Function - Single Match
    GXPokeBlendUpdate
   
   Library: KioskDefault 0 0 */

void GXPokeBlendUpdate(int param1,uint param2,uint param3,uint param4) { //8001FD48
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x284,"'GXPokeBlendUpdate' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXMisc.c",0x28c,"GX Internal: Register field out of range");
  }
  uVar1 = 0;
  if ((param1 == 1) || (param1 == 3)) {
    uVar1 = 1;
  }
  uVar2 = countLeadingZeros(3 - param1);
  if ((uVar2 >> 5 & 0x7fffffe) != 0) {
                    
    OSPanic("GXMisc.c",0x28d,"GX Internal: Register field out of range");
  }
  iVar3 = countLeadingZeros(3 - param1);
  uVar2 = countLeadingZeros(2 - param1);
  if ((uVar2 >> 5 & 0x7fffffe) != 0) {
                    
    OSPanic("GXMisc.c",0x28f,"GX Internal: Register field out of range");
  }
  uVar2 = countLeadingZeros(2 - param1);
  if ((param4 & 0xfffffff0) == 0) {
    if ((param2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXMisc.c",0x291,"GX Internal: Register field out of range");
    }
    if ((param3 & 0xfffffff8) == 0) {
      *(ushort *)(PTR_pe_Z_80398474 + 2) =
           (*(ushort *)(PTR_pe_Z_80398474 + 2) & 0xf7fc | uVar1 | (ushort)(iVar3 << 6) & 0xf800 |
           (ushort)(uVar2 >> 4) & 0xfffe) & 0x81f | (ushort)(param4 << 0xc) | (ushort)(param2 << 8)
           | (ushort)(param3 << 5);
      return;
    }
                    
    OSPanic("GXMisc.c",0x292,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXMisc.c",0x290,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXPokeColorUpdate
   
   Library: KioskDefault 0 0 */

void GXPokeColorUpdate(uint param1) { //8001FF08
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x29d,"'GXPokeColorUpdate' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXMisc.c",0x2a0,"GX Internal: Register field out of range");
  }
  *(ushort *)(PTR_pe_Z_80398474 + 2) =
       *(ushort *)(PTR_pe_Z_80398474 + 2) & 0xfff7 | (ushort)(param1 << 3) & 0x7f8;
  return;
}


/* Library Function - Single Match
    GXPokeDstAlpha
   
   Library: KioskDefault 0 0 */

void GXPokeDstAlpha(uint param1,ushort param2) { //8001FF90
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x2a9,"'GXPokeDstAlpha' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXMisc.c",0x2ab,"GX Internal: Register field out of range");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXMisc.c",0x2ac,"GX Internal: Register field out of range");
  }
  *(ushort *)(PTR_pe_Z_80398474 + 4) = param2 & 0xff | (ushort)(param1 << 8);
  return;
}


/* Library Function - Single Match
    GXPokeDither
   
   Library: KioskDefault 0 0 */

void GXPokeDither(uint param1) { //80020040
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x2b5,"'GXPokeDither' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXMisc.c",0x2b8,"GX Internal: Register field out of range");
  }
  *(ushort *)(PTR_pe_Z_80398474 + 2) =
       *(ushort *)(PTR_pe_Z_80398474 + 2) & 0xfffb | (ushort)(param1 << 2) & 0x3fc;
  return;
}


/* Library Function - Single Match
    GXPokeZMode
   
   Library: KioskDefault 0 0 */

void GXPokeZMode(ushort param1,uint param2,uint param3) { //800200C8
  if (isInGxBegin) {
                    
    OSPanic("GXMisc.c",0x2c1,"'GXPokeZMode' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXMisc.c",0x2c3,"GX Internal: Register field out of range");
  }
  if ((param2 & 0xfffffff8) != 0) {
                    
    OSPanic("GXMisc.c",0x2c4,"GX Internal: Register field out of range");
  }
  if ((param3 & 0xfe) != 0) {
                    
    OSPanic("GXMisc.c",0x2c5,"GX Internal: Register field out of range");
  }
  *(ushort *)PTR_pe_Z_80398474 =
       (param1 & 0xf1 | (ushort)(param2 << 1)) & 0xffef | (ushort)(param3 << 4) & 0xff0;
  return;
}


/* Library Function - Single Match
    gxMiscFn_800201a4
   
   Library: KioskDefault 0 0 */

void gxSetPixel(uint x,uint y,undefined4 color) { //800201A4
  u32 *frameBuf;
  
                    /* this is NOT a framebuffer... */
  frameBuf = (u32 *)OSPhysicalToUncached(0x8000000);
  if ((x & 0xfc00) != 0) {
                    
    OSPanic("GXMisc.c",0x2e6,"GX Internal: Register field out of range");
  }
  if ((y & 0xfc00) != 0) {
                    
    OSPanic("GXMisc.c",0x2e7,"GX Internal: Register field out of range");
  }
  *(undefined4 *)
   ((((uint)frameBuf & 0xfffff003 | (x & 0xffff) << 2) & 0xffc00fff | (y & 0xffff) << 0xc) &
   0xff3fffff) = color;
  return;
}


/* Library Function - Single Match
    gxMiscFn_80020244
   
   Library: KioskDefault 0 0 */

void gxGetPixel(uint x,uint y,u32 *out) { //80020244
  void *pvVar1;
  
  pvVar1 = OSPhysicalToUncached(0x8000000);
  if ((x & 0xfc00) != 0) {
                    
    OSPanic("GXMisc.c",0x2f0,"GX Internal: Register field out of range");
  }
  if ((y & 0xfc00) != 0) {
                    
    OSPanic("GXMisc.c",0x2f1,"GX Internal: Register field out of range");
  }
  *out = *(u32 *)((((uint)pvVar1 & 0xfffff003 | (x & 0xffff) << 2) & 0xffc00fff |
                  (y & 0xffff) << 0xc) & 0xff3fffff | 0x400000);
  return;
}

