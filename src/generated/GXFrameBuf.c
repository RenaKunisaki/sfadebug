
/* Library Function - Single Match
    GXSetDispCopySrc
   
   Library: KioskDefault 0 0 */

void GXSetDispCopySrc(uint param1,uint param2,uint param3,uint param4) { //80020C18
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x3b9,"'GXSetDispCopySrc' is not allowed between GXBegin/GXEnd");
  }
  *(undefined4 *)&gx->field_0x1e0 = 0;
  if ((param1 & 0xfc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3bc,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1e0 = *(uint *)&gx->field_0x1e0 & 0xfffffc00 | param1 & 0xffff;
  if ((param2 & 0xfc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3bd,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1e0 = *(uint *)&gx->field_0x1e0 & 0xfff003ff | (param2 & 0xffff) << 10;
  *(uint *)&gx->field_0x1e0 = *(uint *)&gx->field_0x1e0 & 0xffffff | 0x49000000;
  *(undefined4 *)&gx->field_0x1e4 = 0;
  if (((param3 & 0xffff) - 1 & 0xfffffc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3c1,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1e4 = *(uint *)&gx->field_0x1e4 & 0xfffffc00 | (param3 & 0xffff) - 1;
  if (((param4 & 0xffff) - 1 & 0xfffffc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3c2,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1e4 =
       *(uint *)&gx->field_0x1e4 & 0xfff003ff | ((param4 & 0xffff) - 1) * 0x400;
  *(uint *)&gx->field_0x1e4 = *(uint *)&gx->field_0x1e4 & 0xffffff | 0x4a000000;
  return;
}


/* Library Function - Single Match
    GXSetTexCopySrc
   
   Library: KioskDefault 0 0 */

void GXSetTexCopySrc(uint param1,uint param2,uint param3,uint param4) { //80020DB8
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x3d5,"'GXSetTexCopySrc' is not allowed between GXBegin/GXEnd");
  }
  *(undefined4 *)&gx->field_0x1f0 = 0;
  if ((param1 & 0xfc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3d8,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1f0 = *(uint *)&gx->field_0x1f0 & 0xfffffc00 | param1 & 0xffff;
  if ((param2 & 0xfc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3d9,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1f0 = *(uint *)&gx->field_0x1f0 & 0xfff003ff | (param2 & 0xffff) << 10;
  *(uint *)&gx->field_0x1f0 = *(uint *)&gx->field_0x1f0 & 0xffffff | 0x49000000;
  *(undefined4 *)&gx->field_0x1f4 = 0;
  if (((param3 & 0xffff) - 1 & 0xfffffc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3dd,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1f4 = *(uint *)&gx->field_0x1f4 & 0xfffffc00 | (param3 & 0xffff) - 1;
  if (((param4 & 0xffff) - 1 & 0xfffffc00) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3de,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1f4 =
       *(uint *)&gx->field_0x1f4 & 0xfff003ff | ((param4 & 0xffff) - 1) * 0x400;
  *(uint *)&gx->field_0x1f4 = *(uint *)&gx->field_0x1f4 & 0xffffff | 0x4a000000;
  return;
}


/* Library Function - Single Match
    GXSetDispCopyDst
   
   Library: KioskDefault 0 0 */

void GXSetDispCopyDst(uint param1) { //80020F58
  if ((param1 & 0xf) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3f3,"GXSetDispCopyDst: Width must be a multiple of 16");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x3f4,"'GXSetDispCopyDst' is not allowed between GXBegin/GXEnd");
  }
  *(undefined4 *)&gx->field_0x1e8 = 0;
  if (((param1 << 1) >> 5 & 0x400) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x3fa,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1e8 = *(uint *)&gx->field_0x1e8 & 0xfffffc00 | (param1 << 1) >> 5 & 0x7ff;
  *(uint *)&gx->field_0x1e8 = *(uint *)&gx->field_0x1e8 & 0xffffff | 0x4d000000;
  return;
}


/* Library Function - Single Match
    GXSetTexCopyDst
   
   Library: KioskDefault 0 0 */

void GXSetTexCopyDst(ushort param1,ushort param2,uint param3,uint param4) { //80021024
  uint uVar1;
  uint uVar2;
  int local_24;
  int iStack_20;
  int local_1c [2];
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x415,"'GXSetTexCopyDst' is not allowed between GXBegin/GXEnd");
  }
  gx->field_0x200 = 0;
  uVar2 = param3 & 0xf;
  if (0xc < uVar2) {
                    
    OSPanic("GXFrameBuf.c",0x434,"%s: invalid texture format",
            "GXSetTexCopyDst");
  }
  if (param3 == 0x13) {
    uVar2 = 0xb;
  }
  if ((param3 == 0x26) || ((((int)param3 < 0x26 && ((int)param3 < 4)) && (-1 < (int)param3)))) {
    *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffe7fff | 0x18000;
  }
  else {
    *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffe7fff | 0x10000;
  }
  uVar1 = countLeadingZeros(0x10 - (param3 & 0x10));
  gx->field_0x200 = (char)(uVar1 >> 5);
  if (false) {
                    
    OSPanic("GXFrameBuf.c",1099,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffffff7 | uVar2 & 0xfffffff8;
  FUN_80025ba0(param3,param1,param2,local_1c,&iStack_20,&local_24);
  *(undefined4 *)&gx->field_0x1f8 = 0;
  if ((local_1c[0] * local_24 & 0xfffffc00U) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x454,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1f8 = *(uint *)&gx->field_0x1f8 & 0xfffffc00 | local_1c[0] * local_24;
  *(uint *)&gx->field_0x1f8 = *(uint *)&gx->field_0x1f8 & 0xffffff | 0x4d000000;
  if ((param4 & 0xfe) == 0) {
    *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffffdff | (param4 & 0xff) << 9;
    if (true) {
      *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xffffff8f | (uVar2 & 7) << 4;
      return;
    }
                    
    OSPanic("GXFrameBuf.c",0x457,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXFrameBuf.c",0x456,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXSetDispCopyFrame2Field
   
   Library: KioskDefault 0 0 */

void GXSetDispCopyFrame2Field(uint param1) { //8002126C
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x468,"'GXSetDispCopyFrame2Field' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfffffffc) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x469,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xffffcfff | param1 << 0xc;
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xffffcfff;
  return;
}


/* Library Function - Single Match
    GXSetCopyClamp
   
   Library: KioskDefault 0 0 */

void GXSetCopyClamp(uint param1) { //80021308
  uint uVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x47d,"'GXSetCopyClamp' is not allowed between GXBegin/GXEnd");
  }
  uVar1 = countLeadingZeros(1 - (param1 & 1));
  uVar1 = uVar1 >> 5;
  uVar2 = countLeadingZeros(2 - (param1 & 2));
  uVar2 = uVar2 >> 5;
  if ((uVar1 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x481,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xfffffffe | uVar1 & 0xff;
  if ((uVar2 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x482,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xfffffffd | (uVar2 & 0xff) << 1;
  if ((uVar1 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x484,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffffffe | uVar1 & 0xff;
  if ((uVar2 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x485,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffffffd | (uVar2 & 0xff) << 1;
  return;
}


/* Library Function - Single Match
    GXSetDispCopyYScale
   
   Library: KioskDefault 0 0 */

void GXSetDispCopyYScale(double param1) { //80021460
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  _savefpr_30();
  if (isInGxBegin != false) {
                    
    OSPanic("GXFrameBuf.c",0x49b,"'GXSetDispCopyYScale' is not allowed between GXBegin/GXEnd");
  }
  if (param1 < 1.0) {
                    
    OSPanic("GXFrameBuf.c",0x49d,"GXSetDispCopyYScale: Vertical scale must be >= 1.0");
  }
  uVar2 = __cvt_fp2unsigned((double)(float)(256.0 / param1));
  uVar2 = uVar2 & 0x1ff;
  iVar3 = -uVar2 + 0x100;
  uVar1 = iVar3 + (-(-uVar2 + 0xff) - (uint)(iVar3 == 0));
  if (false) {
                    
    OSPanic("GXFrameBuf.c",0x4a6,"GX Internal: Register field out of range");
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2 | 0x4e000000;
  *(uint *)(pGxDebug->isRegInit + 0xd38) = uVar2 | 0x4e000000;
  gx->field2_0x2 = 1;
  if ((uVar1 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x4ab,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xfffffbff | (uVar1 & 0xff) << 10;
  __cvt_fp2unsigned((double)((float)((double)CONCAT44(0x43300000,
                                                      (*(uint *)&gx->field_0x1e4 >> 10 & 0x3ff) + 1)
                                    - 4503599627370496.0) *
                            (256.0 / (float)((double)CONCAT44(0x43300000,uVar2) - 4503599627370496.0
                                            ))));
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    GXSetCopyClear
   
   Library: KioskDefault 0 0 */

void GXSetCopyClear(undefined *param1,uint param2) { //800215F0
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x4c4,"'GXSetCopyClear' is not allowed between GXBegin/GXEnd");
  }
  if (0xffffff < param2) {
                    
    OSPanic("GXFrameBuf.c",0x4c6,"GXSetCopyClear: Z clear value is out of range");
  }
  if (false) {
                    
    OSPanic("GXFrameBuf.c",0x4c9,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXFrameBuf.c",0x4ca,"GX Internal: Register field out of range");
  }
  uVar1 = CONCAT11(param1[3],*param1) | 0x4f000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xd3c) = uVar1;
  if (false) {
                    
    OSPanic("GXFrameBuf.c",0x4cf,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXFrameBuf.c",0x4d0,"GX Internal: Register field out of range");
  }
  uVar1 = CONCAT11(param1[1],param1[2]) | 0x50000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xd40) = uVar1;
  if ((param2 & 0xff000000) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x4d5,"GX Internal: Register field out of range");
  }
  uVar1 = param2 & 0xffffff | 0x51000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xd44) = uVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetCopyFilter
   
   Library: KioskDefault 0 0 */

void GXSetCopyFilter(char param1,byte *param2,char param3,byte *param4) { //800217D8
  uint uVar1;
  uint uVar2;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x4f1,"'GXSetCopyFilter' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == '\0') {
    local_28 = 0x1666666;
    local_24 = 0x2666666;
    local_20 = 0x3666666;
    local_1c = 0x4666666;
  }
  else {
    if ((*param2 & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4f5,"GX Internal: Register field out of range");
    }
    if ((param2[1] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4f6,"GX Internal: Register field out of range");
    }
    if ((param2[2] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4f7,"GX Internal: Register field out of range");
    }
    if ((param2[3] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4f8,"GX Internal: Register field out of range");
    }
    if ((param2[4] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4f9,"GX Internal: Register field out of range");
    }
    if ((param2[5] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4fa,"GX Internal: Register field out of range");
    }
    local_28 = *param2 & 0xffffff0f | (param2[1] & 0xfffff0f) << 4 | (param2[2] & 0xffff0f) << 8 |
               (param2[3] & 0xfff0f) << 0xc | (param2[4] & 0xff0f) << 0x10 |
               (param2[5] & 0xf) << 0x14 | 0x1000000;
    if ((param2[6] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4fe,"GX Internal: Register field out of range");
    }
    if ((param2[7] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x4ff,"GX Internal: Register field out of range");
    }
    if ((param2[8] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x500,"GX Internal: Register field out of range");
    }
    if ((param2[9] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x501,"GX Internal: Register field out of range");
    }
    if ((param2[10] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x502,"GX Internal: Register field out of range");
    }
    if ((param2[0xb] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x503,"GX Internal: Register field out of range");
    }
    local_24 = param2[6] & 0xffffff0f | (param2[7] & 0xfffff0f) << 4 | (param2[8] & 0xffff0f) << 8 |
               (param2[9] & 0xfff0f) << 0xc | (param2[10] & 0xff0f) << 0x10 |
               (param2[0xb] & 0xf) << 0x14 | 0x2000000;
    if ((param2[0xc] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x507,"GX Internal: Register field out of range");
    }
    if ((param2[0xd] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x508,"GX Internal: Register field out of range");
    }
    if ((param2[0xe] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x509,"GX Internal: Register field out of range");
    }
    if ((param2[0xf] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x50a,"GX Internal: Register field out of range");
    }
    if ((param2[0x10] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x50b,"GX Internal: Register field out of range");
    }
    if ((param2[0x11] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x50c,"GX Internal: Register field out of range");
    }
    local_20 = param2[0xc] & 0xffffff0f | (param2[0xd] & 0xfffff0f) << 4 |
               (param2[0xe] & 0xffff0f) << 8 | (param2[0xf] & 0xfff0f) << 0xc |
               (param2[0x10] & 0xff0f) << 0x10 | (param2[0x11] & 0xf) << 0x14 | 0x3000000;
    if ((param2[0x12] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x510,"GX Internal: Register field out of range");
    }
    if ((param2[0x13] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x511,"GX Internal: Register field out of range");
    }
    if ((param2[0x14] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x512,"GX Internal: Register field out of range");
    }
    if ((param2[0x15] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x513,"GX Internal: Register field out of range");
    }
    if ((param2[0x16] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x514,"GX Internal: Register field out of range");
    }
    if ((param2[0x17] & 0xf0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x515,"GX Internal: Register field out of range");
    }
    local_1c = param2[0x12] & 0xffffff0f | (param2[0x13] & 0xfffff0f) << 4 |
               (param2[0x14] & 0xffff0f) << 8 | (param2[0x15] & 0xfff0f) << 0xc |
               (param2[0x16] & 0xff0f) << 0x10 | (param2[0x17] & 0xf) << 0x14 | 0x4000000;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = local_28;
  *(uint *)(pGxDebug->isRegInit + (local_28 >> 0x16 & 0x3fc) + 0xc00) = local_28;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = local_24;
  *(uint *)(pGxDebug->isRegInit + (local_24 >> 0x16 & 0x3fc) + 0xc00) = local_24;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = local_20;
  *(uint *)(pGxDebug->isRegInit + (local_20 >> 0x16 & 0x3fc) + 0xc00) = local_20;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = local_1c;
  *(uint *)(pGxDebug->isRegInit + (local_1c >> 0x16 & 0x3fc) + 0xc00) = local_1c;
  if (param3 == '\0') {
    uVar2 = 0x53595000;
    uVar1 = 0x54000015;
  }
  else {
    if ((*param4 & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x52e,"GX Internal: Register field out of range");
    }
    if ((param4[1] & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x52f,"GX Internal: Register field out of range");
    }
    if ((param4[2] & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x530,"GX Internal: Register field out of range");
    }
    if ((param4[3] & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x531,"GX Internal: Register field out of range");
    }
    uVar2 = *param4 & 0xfffff03f | 0x53000000 | (param4[1] & 0x3fff03f) << 6 |
            (param4[2] & 0xff03f) << 0xc | (uint)param4[3] << 0x12;
    if ((param4[4] & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x532,"GX Internal: Register field out of range");
    }
    if ((param4[5] & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x533,"GX Internal: Register field out of range");
    }
    if ((param4[6] & 0xc0) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x534,"GX Internal: Register field out of range");
    }
    uVar1 = param4[4] & 0xfffff03f | 0x54000000 | (param4[5] & 0x3fff03f) << 6 |
            (uint)param4[6] << 0xc;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + (uVar2 >> 0x16 & 0x3fc) + 0xc00) = uVar2;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetDispCopyGamma
   
   Library: KioskDefault 0 0 */

void GXSetDispCopyGamma(uint param1) { //800220B4
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x555,"'GXSetDispCopyGamma' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfffffffc) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x556,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xfffffe7f | param1 << 7;
  return;
}


/* Library Function - Single Match
    GXCopyDisp
   
   Library: KioskDefault 0 0 */

void GXCopyDisp(uint param1,char param2) { //8002213C
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x56a,"'GXCopyDisp' is not allowed between GXBegin/GXEnd");
  }
  uVar2 = (*(uint *)&gx->field_0x1e4 & 0x3ff) + 1;
  uVar1 = *(uint *)&gx->field_0x1e0 >> 10;
  uVar3 = (*(uint *)&gx->field_0x1e4 >> 10 & 0x3ff) + 1;
  if (((*(uint *)&gx->field_0x1ec & 1) == 0) && ((uVar1 & 0x3ff) == 0)) {
                    
    OSPanic("GXFrameBuf.c",0x574,"GXCopy: Have to set GX_CLAMP_TOP if source top == 0");
  }
  if (((*(uint *)&gx->field_0x1ec >> 1 & 1) == 0) && (0x210 < (uVar1 & 0x3ff) + uVar3)) {
                    
    OSPanic("GXFrameBuf.c",0x576,"GXCopy: Have to set GX_CLAMP_BOTTOM if source bottom > 528");
  }
  if (((gx->field454_0x1dc & 7) == 3) && (param2 != '\0')) {
                    
    OSPanic("GXFrameBuf.c",0x57b,"GXCopy: Can not do clear while pixel type is Z");
  }
  if ((gx->field454_0x1dc & 7) == 5) {
    if (param2 != '\0') {
                    
      OSPanic("GXFrameBuf.c",0x581,"GXCopy: Can not clear YUV framebuffer");
    }
    if ((*(uint *)&gx->field_0x1e0 & 3) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x583,"GXCopy: Source x is not multiple of 4 for YUV copy");
    }
    if ((uVar1 & 3) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x585,"GXCopy: Source y is not multiple of 4 for YUV copy");
    }
    if ((uVar2 & 3) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x587,"GXCopy: Source width is not multiple of 4 for YUV copy");
    }
    if ((uVar3 & 3) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x589,"GXCopy: Source height is not multiple of 4 for YUV copy");
    }
  }
  else {
    if ((*(uint *)&gx->field_0x1e0 & 1) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x58d,"GXCopy: Source x is not multiple of 2 for RGB copy");
    }
    if ((uVar1 & 1) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x58f,"GXCopy: Source y is not multiple of 2 for RGB copy");
    }
    if ((uVar2 & 1) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x591,"GXCopy: Source width is not multiple of 2 for RGB copy");
    }
    if ((uVar3 & 1) != 0) {
                    
      OSPanic("GXFrameBuf.c",0x593,"GXCopy: Source height is not multiple of 2 for RGB copy");
    }
  }
  if ((param1 & 0x1f) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x597,"GXCopy: Display destination address not 32B aligned");
  }
  return;
}


/* Library Function - Single Match
    GXCopyDisp2
   
   Library: KioskDefault 0 0 */

void GXCopyDisp2(void *frameBuf,byte param2) { //80022390
  bool bVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x5b1,"'GXCopyDisp' is not allowed between GXBegin/GXEnd");
  }
  GXCopyDisp((uint)frameBuf,param2);
  if (param2 != 0) {
    uVar2 = gx->field453_0x1d8 & 0xfffffff0 | 0xf;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + (gx->field453_0x1d8 >> 0x16 & 0x3fc) + 0xc00) = uVar2;
    uVar2 = *(uint *)&gx->field_0x1d0 & 0xfffffffc;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) = uVar2;
  }
  bVar1 = false;
  if (param2 == 0) {
    if ((gx->field454_0x1dc & 7) != 3) goto LAB_800224bc;
  }
  if ((gx->field454_0x1dc >> 6 & 1) == 1) {
    bVar1 = true;
    uVar2 = gx->field454_0x1dc & 0xffffffbf;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + (gx->field454_0x1dc >> 0x16 & 0x3fc) + 0xc00) = uVar2;
  }
LAB_800224bc:
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1e0;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1e0 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1e0;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1e4;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1e4 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1e4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1e8;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1e8 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1e8;
  if ((((uint)frameBuf & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x5d8,"GX Internal: Register field out of range");
  }
  uVar2 = ((uint)frameBuf & 0x3fffffff) >> 5 & 0xffffff | 0x4b000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + 0xd2c) = uVar2;
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x5dc,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xfffff7ff | (uint)param2 << 0xb;
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xffffbfff | 0x4000;
  *(uint *)&gx->field_0x1ec = *(uint *)&gx->field_0x1ec & 0xffffff | 0x52000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1ec;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1ec >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1ec;
  if (param2 != 0) {
    GXFIFO._0_1_ = 0x61;
    GXFIFO = gx->field453_0x1d8;
    *(uint *)(pGxDebug->isRegInit + (gx->field453_0x1d8 >> 0x16 & 0x3fc) + 0xc00) =
         gx->field453_0x1d8;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = *(undefined4 *)&gx->field_0x1d0;
    *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) =
         *(undefined4 *)&gx->field_0x1d0;
  }
  if (bVar1) {
    GXFIFO._0_1_ = 0x61;
    GXFIFO = gx->field454_0x1dc;
    *(uint *)(pGxDebug->isRegInit + (gx->field454_0x1dc >> 0x16 & 0x3fc) + 0xc00) =
         gx->field454_0x1dc;
  }
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXCopyTex
   
   Library: KioskDefault 0 0 */

void GXCopyTex(uint param1,byte param2) { //80022754
  bool bVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x604,"'GXCopyTex' is not allowed between GXBegin/GXEnd");
  }
  GXCopyDisp(param1,param2);
  if (param2 != 0) {
    uVar2 = gx->field453_0x1d8 & 0xfffffff0 | 0xf;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + (gx->field453_0x1d8 >> 0x16 & 0x3fc) + 0xc00) = uVar2;
    uVar2 = *(uint *)&gx->field_0x1d0 & 0xfffffffc;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) = uVar2;
  }
  bVar1 = false;
  uVar2 = gx->field454_0x1dc;
  if (gx->field_0x200 != '\0') {
    if ((uVar2 & 7) != 3) {
      bVar1 = true;
      uVar2 = uVar2 & 0xfffffff8 | 3;
    }
  }
  if (param2 == 0) {
    if ((uVar2 & 7) != 3) goto LAB_80022874;
  }
  if ((uVar2 >> 6 & 1) == 1) {
    bVar1 = true;
    uVar2 = uVar2 & 0xffffffbf;
  }
LAB_80022874:
  if (bVar1) {
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + (uVar2 >> 0x16 & 0x3fc) + 0xc00) = uVar2;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1f0;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1f0 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1f0;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1f4;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1f4 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1f4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1f8;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1f8 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1f8;
  if (((param1 & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x635,"GX Internal: Register field out of range");
  }
  uVar2 = (param1 & 0x3fffffff) >> 5 & 0xffffff | 0x4b000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + 0xd2c) = uVar2;
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXFrameBuf.c",0x639,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffff7ff | (uint)param2 << 0xb;
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xffffbfff;
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xffffff | 0x52000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1fc;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1fc >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1fc;
  if (param2 != 0) {
    GXFIFO._0_1_ = 0x61;
    GXFIFO = gx->field453_0x1d8;
    *(uint *)(pGxDebug->isRegInit + (gx->field453_0x1d8 >> 0x16 & 0x3fc) + 0xc00) =
         gx->field453_0x1d8;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = *(undefined4 *)&gx->field_0x1d0;
    *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) =
         *(undefined4 *)&gx->field_0x1d0;
  }
  if (bVar1) {
    GXFIFO._0_1_ = 0x61;
    GXFIFO = gx->field454_0x1dc;
    *(uint *)(pGxDebug->isRegInit + (gx->field454_0x1dc >> 0x16 & 0x3fc) + 0xc00) =
         gx->field454_0x1dc;
  }
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXClearBoundingBox
   
   Library: KioskDefault 0 0 */

void GXClearBoundingBox(void) { //80022B34
  if (isInGxBegin) {
                    
    OSPanic("GXFrameBuf.c",0x65b,"'GXClearBoundingBox' is not allowed between GXBegin/GXEnd");
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x550003ff;
  *(undefined4 *)(pGxDebug->isRegInit + 0xd54) = 0x550003ff;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x560003ff;
  *(undefined4 *)(pGxDebug->isRegInit + 0xd58) = 0x560003ff;
  gx->field2_0x2 = 1;
  return;
}

