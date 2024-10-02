
/* Library Function - Single Match
    GXSetFog
   
   Library: KioskDefault 0 0 */

void GXSetFog(double param1,double param2,double nearz,double farz,uint param5,undefined *param6) { //8002A9E0
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  double dVar10;
  
  _savefpr_24();
  if (isInGxBegin != false) {
                    
    OSPanic("GXPixel.c",0x6e,"'GXSetFog' is not allowed between GXBegin/GXEnd");
  }
  if (farz < 0.0) {
                    
    OSPanic("GXPixel.c",0x70,"GXSetFog: The farz should be positive value");
  }
  if (farz < nearz) {
                    
    OSPanic("GXPixel.c",0x71,"GXSetFog: The farz should be larger than nearz");
  }
  if ((farz == nearz) || (param2 == param1)) {
    fVar1 = 0.0;
    fVar2 = 0.5;
    fVar3 = 0.0;
  }
  else {
    fVar1 = (float)(farz * nearz) / ((float)(farz - nearz) * (float)(param2 - param1));
    fVar2 = (float)(farz / (double)(float)(farz - nearz));
    fVar3 = (float)(param1 / (double)(float)(param2 - param1));
  }
  dVar10 = (double)fVar3;
  iVar5 = 0;
  for (; 1.0 < fVar2; fVar2 = fVar2 * 0.5) {
    iVar5 = iVar5 + 1;
  }
  for (; (0.0 < fVar2 && (fVar2 < 0.5)); fVar2 = fVar2 * 2.0) {
    iVar5 = iVar5 + -1;
  }
  fVar1 = fVar1 / (float)((double)CONCAT44(0x43300000,1 << iVar5 + 1 ^ 0x80000000) -
                         4503601774854144.0);
  uVar4 = __cvt_fp2unsigned((double)(fVar2 * 8388638.0));
  fVar2 = (float)dVar10;
  if ((uVar4 & 0xff000000) != 0) {
                    
    OSPanic("GXPixel.c",0x94,"GX Internal: Register field out of range");
  }
  uVar4 = uVar4 & 0xffffff | 0xef000000;
  if ((iVar5 + 1U & 0xffffffe0) != 0) {
                    
    OSPanic("GXPixel.c",0x98,"GX Internal: Register field out of range");
  }
  uVar6 = iVar5 + 1U & 0xffffff | 0xf0000000;
  if (false) {
                    
    OSPanic("GXPixel.c",0xa0,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXPixel.c",0xa1,"GX Internal: Register field out of range");
  }
  if (true) {
    uVar7 = (uint)fVar1 >> 0xc & 0x80000 | (uint)fVar1 >> 0xc & 0x7f800 | (uint)fVar1 >> 0xc & 0x7ff
            | 0xee000000;
    if (false) {
                    
      OSPanic("GXPixel.c",0xa6,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXPixel.c",0xa7,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXPixel.c",0xa8,"GX Internal: Register field out of range");
    }
    if ((param5 & 0xfffffff8) == 0) {
      uVar9 = (uint)fVar2 >> 0xc & 0x80000 |
              (uint)fVar2 >> 0xc & 0x7f800 | (uint)fVar2 >> 0xc & 0x7ff | (param5 & 7) << 0x15 |
              0xf1000000;
      if (false) {
                    
        OSPanic("GXPixel.c",0xae,"GX Internal: Register field out of range");
      }
      if (true) {
        if (true) {
          uVar8 = CONCAT12(*param6,CONCAT11(param6[1],param6[2])) | 0xf2000000;
          GXFIFO._0_1_ = 0x61;
          GXFIFO = uVar7;
          *(uint *)(pGxDebug->isRegInit + 0xfb8) = uVar7;
          GXFIFO._0_1_ = 0x61;
          GXFIFO = uVar4;
          *(uint *)(pGxDebug->isRegInit + 0xfbc) = uVar4;
          GXFIFO._0_1_ = 0x61;
          GXFIFO = uVar6;
          *(uint *)(pGxDebug->isRegInit + 0xfc0) = uVar6;
          GXFIFO._0_1_ = 0x61;
          GXFIFO = uVar9;
          *(uint *)(pGxDebug->isRegInit + 0xfc4) = uVar9;
          GXFIFO._0_1_ = 0x61;
          GXFIFO = uVar8;
          *(uint *)(pGxDebug->isRegInit + 0xfc8) = uVar8;
          gx->field2_0x2 = 1;
          _restfpr_24();
          return;
        }
                    
        OSPanic("GXPixel.c",0xb0,"GX Internal: Register field out of range");
      }
                    
      OSPanic("GXPixel.c",0xaf,"GX Internal: Register field out of range");
    }
                    
    OSPanic("GXPixel.c",0xaa,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXPixel.c",0xa2,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXSetFogRangeAdj
   
   Library: KioskDefault 0 0 */

void GXSetFogRangeAdj(byte param1,uint param2,int tablePtr) { //8002AE5C
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x106,"'GXSetFogRangeAdj' is not allowed between GXBegin/GXEnd");
  }
  if (param1 != 0) {
    if (tablePtr == 0) {
                    
      OSPanic("GXPixel.c",0x109,"GXSetFogRangeAdj: table pointer is null");
    }
    uVar2 = 0;
    while( true ) {
      if (9 < uVar2) break;
      if ((*(ushort *)(tablePtr + uVar2 * 2) & 0xf000) != 0) {
                    
        OSPanic("GXPixel.c",0x10d,"GX Internal: Register field out of range");
      }
      if ((*(ushort *)(tablePtr + (uVar2 + 1) * 2) & 0xf000) != 0) {
                    
        OSPanic("GXPixel.c",0x10e,"GX Internal: Register field out of range");
      }
      if (((uVar2 >> 1) + 0xe9 & 0xffffff00) != 0) {
                    
        OSPanic("GXPixel.c",0x10f,"GX Internal: Register field out of range");
      }
      uVar1 = ((uVar2 >> 1) + 0xe9) * 0x1000000;
      uVar3 = uVar1 | *(ushort *)(tablePtr + uVar2 * 2) & 0xff000fff |
                      (*(ushort *)(tablePtr + (uVar2 + 1) * 2) & 0xfff) << 0xc;
      GXFIFO._0_1_ = 0x61;
      GXFIFO = uVar3;
      *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar3;
      uVar2 = uVar2 + 2;
    }
  }
  if (((param2 & 0xffff) + 0x154 & 0xfffffc00) != 0) {
                    
    OSPanic("GXPixel.c",0x115,"GX Internal: Register field out of range");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x116,"GX Internal: Register field out of range");
  }
  uVar2 = (param2 & 0xffff) + 0x154 & 0xfffbff | (uint)param1 << 10 | 0xe8000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + 4000) = uVar2;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetBlendMode
   
   Library: KioskDefault 0 0 */

void GXSetBlendMode(int param1,uint param2,uint param3,uint param4) { //8002B058
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x12f,"'GXSetBlendMode' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXPixel.c",0x135,"GX Internal: Register field out of range");
  }
  uVar1 = 0;
  if ((param1 == 1) || (param1 == 3)) {
    uVar1 = 1;
  }
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xfffffffe | uVar1;
  uVar1 = countLeadingZeros(3 - param1);
  if ((uVar1 >> 5 & 0x7fffffe) != 0) {
                    
    OSPanic("GXPixel.c",0x136,"GX Internal: Register field out of range");
  }
  uVar1 = countLeadingZeros(3 - param1);
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xfffff7ff | (uVar1 & 0x3ffffe0) << 6;
  uVar1 = countLeadingZeros(2 - param1);
  if ((uVar1 >> 5 & 0x7fffffe) != 0) {
                    
    OSPanic("GXPixel.c",0x138,"GX Internal: Register field out of range");
  }
  uVar1 = countLeadingZeros(2 - param1);
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xfffffffd | uVar1 >> 4 & 0xffffffe;
  if ((param4 & 0xfffffff0) == 0) {
    *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xffff0fff | param4 << 0xc;
    if ((param2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXPixel.c",0x13a,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xfffff8ff | param2 << 8;
    if ((param3 & 0xfffffff8) == 0) {
      *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xffffff1f | param3 << 5;
      *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xffffff | 0x41000000;
      GXFIFO._0_1_ = 0x61;
      GXFIFO = *(undefined4 *)&gx->field_0x1d0;
      *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) =
           *(undefined4 *)&gx->field_0x1d0;
      gx->field2_0x2 = 1;
      return;
    }
                    
    OSPanic("GXPixel.c",0x13b,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXPixel.c",0x139,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXSetColorUpdate
   
   Library: KioskDefault 0 0 */

void GXSetColorUpdate(uint param1) { //8002B2C0
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x14f,"'GXSetColorUpdate' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x150,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xfffffff7 | (param1 & 0xff) << 3;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1d0;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1d0;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetAlphaUpdate
   
   Library: KioskDefault 0 0 */

void GXSetAlphaUpdate(uint param1) { //8002B390
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x158,"'GXSetAlphaUpdate' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x159,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xffffffef | (param1 & 0xff) << 4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1d0;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1d0;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetZMode
   
   Library: KioskDefault 0 0 */

void GXSetZMode(GXBool compare_enable,GXCompare func,GXBool update_enable) { //8002B460
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x170,"'GXSetZMode' is not allowed between GXBegin/GXEnd");
  }
  if ((compare_enable & 0xfeU) != 0) {
                    
    OSPanic("GXPixel.c",0x171,"GX Internal: Register field out of range");
  }
  gx->field453_0x1d8 = gx->field453_0x1d8 & 0xfffffffe | (uint)compare_enable;
  if ((func & 0xfffffff8) != 0) {
                    
    OSPanic("GXPixel.c",0x172,"GX Internal: Register field out of range");
  }
  gx->field453_0x1d8 = gx->field453_0x1d8 & 0xfffffff1 | func << 1;
  if ((update_enable & 0xfeU) != 0) {
                    
    OSPanic("GXPixel.c",0x173,"GX Internal: Register field out of range");
  }
  gx->field453_0x1d8 = gx->field453_0x1d8 & 0xffffffef | (uint)update_enable << 4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = gx->field453_0x1d8;
  *(uint *)(pGxDebug->isRegInit + (gx->field453_0x1d8 >> 0x16 & 0x3fc) + 0xc00) = gx->field453_0x1d8
  ;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetZCompLoc
   
   Library: KioskDefault 0 0 */

void GXSetZCompLoc(uint param1) { //8002B5A8
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x17c,"'GXSetZCompLoc' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x17d,"GX Internal: Register field out of range");
  }
  gx->field454_0x1dc = gx->field454_0x1dc & 0xffffffbf | (param1 & 0xff) << 6;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = gx->field454_0x1dc;
  *(uint *)(pGxDebug->isRegInit + (gx->field454_0x1dc >> 0x16 & 0x3fc) + 0xc00) = gx->field454_0x1dc
  ;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetPixelFmt
   
   Library: KioskDefault 0 0 */

void GXSetPixelFmt(int pixfmt,uint param2) { //8002B678
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x1a1,"'GXSetPixelFmt' is not allowed between GXBegin/GXEnd");
  }
  uVar1 = gx->field454_0x1dc;
  if ((pixfmt < 0) || (7 < pixfmt)) {
                    
    OSPanic("GXPixel.c",0x1a5,"Invalid Pixel format");
  }
  if ((*(uint *)(&DAT_802db660 + pixfmt * 4) & 0xfffffff8) != 0) {
                    
    OSPanic("GXPixel.c",0x1a7,"GX Internal: Register field out of range");
  }
  gx->field454_0x1dc = gx->field454_0x1dc & 0xfffffff8 | *(uint *)(&DAT_802db660 + pixfmt * 4);
  if ((param2 & 0xfffffff8) != 0) {
                    
    OSPanic("GXPixel.c",0x1a8,"GX Internal: Register field out of range");
  }
  gx->field454_0x1dc = gx->field454_0x1dc & 0xffffffc7 | param2 << 3;
  if (uVar1 != gx->field454_0x1dc) {
    GXFIFO._0_1_ = 0x61;
    GXFIFO = gx->field454_0x1dc;
    *(uint *)(pGxDebug->isRegInit + (gx->field454_0x1dc >> 0x16 & 0x3fc) + 0xc00) =
         gx->field454_0x1dc;
    if (false) {
                    
      OSPanic("GXPixel.c",0x1b1,"GX Internal: Register field out of range");
    }
    gx->field491_0x204 = gx->field491_0x204 & 0xfffffdff | (uint)(pixfmt == 2) << 9;
    gx->flags4F0 = gx->flags4F0 | 4;
  }
  if (*(int *)(&DAT_802db660 + pixfmt * 4) == 4) {
    if (false) {
                    
      OSPanic("GXPixel.c",0x1b8,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x1d4 =
         (pixfmt + -4) * 0x200 & 0x600U | *(uint *)&gx->field_0x1d4 & 0xfffff9ff;
    *(uint *)&gx->field_0x1d4 = *(uint *)&gx->field_0x1d4 & 0xffffff | 0x42000000;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = *(undefined4 *)&gx->field_0x1d4;
    *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d4 >> 0x16 & 0x3fc) + 0xc00) =
         *(undefined4 *)&gx->field_0x1d4;
  }
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetDither
   
   Library: KioskDefault 0 0 */

void GXSetDither(uint param1) { //8002B8D8
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x1cd,"'GXSetDither' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x1ce,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xfffffffb | (param1 & 0xff) << 2;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1d0;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d0 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1d0;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetDstAlpha
   
   Library: KioskDefault 0 0 */

void GXSetDstAlpha(uint param1,uint param2) { //8002B9A8
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x1e1,"'GXSetDstAlpha' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXPixel.c",0x1e2,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1d4 = *(uint *)&gx->field_0x1d4 & 0xffffff00 | param2 & 0xff;
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x1e3,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x1d4 = *(uint *)&gx->field_0x1d4 & 0xfffffeff | (param1 & 0xff) << 8;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x1d4;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x1d4 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x1d4;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetFieldMask
   
   Library: KioskDefault 0 0 */

void GXSetFieldMask(uint param1,uint param2) { //8002BAB4
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x1f9,"'GXSetFieldMask' is not allowed between GXBegin/GXEnd");
  }
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x1fb,"GX Internal: Register field out of range");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x1fc,"GX Internal: Register field out of range");
  }
  uVar1 = param2 & 0xfd | (param1 & 0xff) << 1 | 0x44000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xd10) = uVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetFieldMode
   
   Library: KioskDefault 0 0 */

void GXSetFieldMode(byte param1,uint param2) { //8002BB94
  if (isInGxBegin) {
                    
    OSPanic("GXPixel.c",0x216,"'GXSetFieldMode' is not allowed between GXBegin/GXEnd");
  }
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXPixel.c",0x21a,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x7c = *(uint *)&gx->field_0x7c & 0xffbfffff | (param2 & 0xff) << 0x16;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x7c;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x7c >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x7c;
  gxFn_80028f60();
  GXFIFO._0_1_ = 0x61;
  GXFIFO = param1 | 0x68000000;
  *(uint *)(pGxDebug->isRegInit + 0xda0) = param1 | 0x68000000;
  gxFn_80028f60();
  return;
}

