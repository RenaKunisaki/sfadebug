
/* Library Function - Single Match
    GXInitIndTexture
   
   Library: KioskDefault 0 0 */

void GXInitIndTexture(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                     uint param_7,uint param_8,byte param_9,uint param_10) { //80027EEC
  uint uVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0x7f,"'GXInitIndTexture' is not allowed between GXBegin/GXEnd");
  }
  if ((param_2 & 0xfffffffc) != 0) {
                    
    OSPanic("GXBump.c",0x81,"GX Internal: Register field out of range");
  }
  if ((param_3 & 0xfffffffc) != 0) {
                    
    OSPanic("GXBump.c",0x82,"GX Internal: Register field out of range");
  }
  if ((param_4 & 0xfffffff8) != 0) {
                    
    OSPanic("GXBump.c",0x83,"GX Internal: Register field out of range");
  }
  if ((param_10 & 0xfffffffc) != 0) {
                    
    OSPanic("GXBump.c",0x84,"GX Internal: Register field out of range");
  }
  if ((param_5 & 0xfffffff0) != 0) {
                    
    OSPanic("GXBump.c",0x85,"GX Internal: Register field out of range");
  }
  if ((param_6 & 0xfffffff8) != 0) {
                    
    OSPanic("GXBump.c",0x86,"GX Internal: Register field out of range");
  }
  if ((param_7 & 0xfffffff8) != 0) {
                    
    OSPanic("GXBump.c",0x87,"GX Internal: Register field out of range");
  }
  if ((param_9 & 0xfe) != 0) {
                    
    OSPanic("GXBump.c",0x88,"GX Internal: Register field out of range");
  }
  if ((param_8 & 0xfe) != 0) {
                    
    OSPanic("GXBump.c",0x89,"GX Internal: Register field out of range");
  }
  if ((param_1 + 0x10U & 0xffffff00) != 0) {
                    
    OSPanic("GXBump.c",0x8a,"GX Internal: Register field out of range");
  }
  uVar1 = (param_1 + 0x10) * 0x1000000;
  uVar2 = uVar1 | ((((((((param_2 & 0xfffffff3 | param_3 << 2) & 0xffffff8f | param_4 << 4) &
                        0xfffffe7f | param_10 << 7) & 0xffffe1ff | param_5 << 9) & 0xffff1fff |
                     param_6 << 0xd) & 0xfff8ffff | param_7 << 0x10) & 0xfff7ffff |
                   (uint)param_9 << 0x13) & 0xffefffff | (param_8 & 0xff) << 0x14) & 0xffffff;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar2;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetIndTexMtx
   
   Library: KioskDefault 0 0 */

void GXSetIndTexMtx(int param1,float *param2,char param3) { //80028124
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0xa7,"'GXSetIndTexMtx' is not allowed between GXBegin/GXEnd");
  }
  if (param1 != 8) {
    if (param1 < 8) {
      if (param1 != 4) {
        if (3 < param1) {
          iVar3 = param1 + -5;
          goto LAB_800281b4;
        }
        if (0 < param1) {
          iVar3 = param1 + -1;
          goto LAB_800281b4;
        }
      }
    }
    else if (param1 < 0xc) {
      iVar3 = param1 + -9;
      goto LAB_800281b4;
    }
  }
  iVar3 = 0;
LAB_800281b4:
  cVar2 = param3 + '\x11';
  if (false) {
                    
    OSPanic("GXBump.c",0xbd,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXBump.c",0xbe,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXBump.c",0xbf,"GX Internal: Register field out of range");
  }
  if ((iVar3 * 3 + 6U & 0xffffff00) != 0) {
                    
    OSPanic("GXBump.c",0xc0,"GX Internal: Register field out of range");
  }
  uVar1 = (iVar3 * 3 + 6) * 0x1000000;
  uVar4 = uVar1 | ((int)cVar2 & 3U) << 0x16 |
                  (int)(*param2 * 1024.0) & 0x7ffU | ((int)(param2[3] * 1024.0) & 0x7ffU) << 0xb;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar4;
  *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar4;
  if (false) {
                    
    OSPanic("GXBump.c",0xc6,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXBump.c",199,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXBump.c",200,"GX Internal: Register field out of range");
  }
  if ((iVar3 * 3 + 7U & 0xffffff00) == 0) {
    uVar1 = (iVar3 * 3 + 7) * 0x1000000;
    uVar4 = uVar1 | ((int)cVar2 & 0xcU) << 0x14 |
                    (int)(param2[1] * 1024.0) & 0x7ffU | ((int)(param2[4] * 1024.0) & 0x7ffU) << 0xb
    ;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar4;
    *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar4;
    if (false) {
                    
      OSPanic("GXBump.c",0xcf,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXBump.c",0xd0,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXBump.c",0xd1,"GX Internal: Register field out of range");
    }
    if ((iVar3 * 3 + 8U & 0xffffff00) == 0) {
      uVar1 = (iVar3 * 3 + 8) * 0x1000000;
      uVar4 = uVar1 | ((int)cVar2 & 0x30U) << 0x12 |
                      (int)(param2[2] * 1024.0) & 0x7ffU |
                      ((int)(param2[5] * 1024.0) & 0x7ffU) << 0xb;
      GXFIFO._0_1_ = 0x61;
      GXFIFO = uVar4;
      *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar4;
      gx->field2_0x2 = 1;
      return;
    }
                    
    OSPanic("GXBump.c",0xd2,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXBump.c",0xc9,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXSetIndTexScale
   
   Library: KioskDefault 0 0 */

void GXSetIndTexScale(int param1,uint param2,uint param3) { //80028544
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0xe6,"'GXSetIndTexScale' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == 2) {
    if ((param2 & 0xfffffff0) != 0) {
                    
      OSPanic("GXBump.c",0xf6,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x12c = *(uint *)&gx->field_0x12c & 0xfffffff0 | param2;
    if ((param3 & 0xfffffff0) != 0) {
                    
      OSPanic("GXBump.c",0xf7,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x12c = *(uint *)&gx->field_0x12c & 0xffffff0f | param3 << 4;
    *(uint *)&gx->field_0x12c = *(uint *)&gx->field_0x12c & 0xffffff | 0x26000000;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = *(undefined4 *)&gx->field_0x12c;
    *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x12c >> 0x16 & 0x3fc) + 0xc00) =
         *(undefined4 *)&gx->field_0x12c;
  }
  else if (param1 < 2) {
    if (param1 == 0) {
      if ((param2 & 0xfffffff0) != 0) {
                    
        OSPanic("GXBump.c",0xea,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x128 = *(uint *)&gx->field_0x128 & 0xfffffff0 | param2;
      if ((param3 & 0xfffffff0) != 0) {
                    
        OSPanic("GXBump.c",0xeb,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x128 = *(uint *)&gx->field_0x128 & 0xffffff0f | param3 << 4;
      *(uint *)&gx->field_0x128 = *(uint *)&gx->field_0x128 & 0xffffff | 0x25000000;
      GXFIFO._0_1_ = 0x61;
      GXFIFO = *(undefined4 *)&gx->field_0x128;
      *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x128 >> 0x16 & 0x3fc) + 0xc00) =
           *(undefined4 *)&gx->field_0x128;
    }
    else {
      if (param1 < 0) goto LAB_800288cc;
      if ((param2 & 0xfffffff0) != 0) {
                    
        OSPanic("GXBump.c",0xf0,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x128 = *(uint *)&gx->field_0x128 & 0xfffff0ff | param2 << 8;
      if ((param3 & 0xfffffff0) != 0) {
                    
        OSPanic("GXBump.c",0xf1,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x128 = *(uint *)&gx->field_0x128 & 0xffff0fff | param3 << 0xc;
      *(uint *)&gx->field_0x128 = *(uint *)&gx->field_0x128 & 0xffffff | 0x25000000;
      GXFIFO._0_1_ = 0x61;
      GXFIFO = *(undefined4 *)&gx->field_0x128;
      *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x128 >> 0x16 & 0x3fc) + 0xc00) =
           *(undefined4 *)&gx->field_0x128;
    }
  }
  else {
    if (3 < param1) {
LAB_800288cc:
                    
      OSPanic("GXBump.c",0x102,"GXSetIndTexCoordScale: Invalid Indirect Stage Id");
    }
    if ((param2 & 0xfffffff0) != 0) {
                    
      OSPanic("GXBump.c",0xfc,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x12c = *(uint *)&gx->field_0x12c & 0xfffff0ff | param2 << 8;
    if ((param3 & 0xfffffff0) != 0) {
                    
      OSPanic("GXBump.c",0xfd,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x12c = *(uint *)&gx->field_0x12c & 0xffff0fff | param3 << 0xc;
    *(uint *)&gx->field_0x12c = *(uint *)&gx->field_0x12c & 0xffffff | 0x26000000;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = *(undefined4 *)&gx->field_0x12c;
    *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x12c >> 0x16 & 0x3fc) + 0xc00) =
         *(undefined4 *)&gx->field_0x12c;
  }
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetIndTexOrder
   
   Library: KioskDefault 0 0 */

void GXSetIndTexOrder(int param1,uint param2,uint param3) { //80028900
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0x11b,"'GXSetIndTexOrder' is not allowed between GXBegin/GXEnd");
  }
  if (7 < (int)param3) {
                    
    OSPanic("GXBump.c",0x11d,"GXSetIndTexOrder: Invalid direct texture Id");
  }
  if (7 < (int)param2) {
                    
    OSPanic("GXBump.c",0x11e,"GXSetIndTexOrder: Invalid texture coord");
  }
  if (param1 == 2) {
    if ((param3 & 0xfffffff8) != 0) {
                    
      OSPanic("GXBump.c",0x12a,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xffff8fff | param3 << 0xc;
    if ((param2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXBump.c",299,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xfffc7fff | param2 << 0xf;
  }
  else if (param1 < 2) {
    if (param1 == 0) {
      if ((param3 & 0xfffffff8) != 0) {
                    
        OSPanic("GXBump.c",0x122,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xfffffff8 | param3;
      if ((param2 & 0xfffffff8) != 0) {
                    
        OSPanic("GXBump.c",0x123,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xffffffc7 | param2 << 3;
    }
    else {
      if (param1 < 0) goto LAB_80028b74;
      if ((param3 & 0xfffffff8) != 0) {
                    
        OSPanic("GXBump.c",0x126,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xfffffe3f | param3 << 6;
      if ((param2 & 0xfffffff8) != 0) {
                    
        OSPanic("GXBump.c",0x127,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xfffff1ff | param2 << 9;
    }
  }
  else {
    if (3 < param1) {
LAB_80028b74:
                    
      OSPanic("GXBump.c",0x132,"GXSetIndTexOrder: Invalid Indirect Stage Id");
    }
    if ((param3 & 0xfffffff8) != 0) {
                    
      OSPanic("GXBump.c",0x12e,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xffe3ffff | param3 << 0x12;
    if ((param2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXBump.c",0x12f,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xff1fffff | param2 << 0x15;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x120;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x120 >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x120;
  gx->flags4F0 = gx->flags4F0 | 3;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetNumIndStages
   
   Library: KioskDefault 0 0 */

void GXSetNumIndStages(byte param1) { //80028BF4
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0x144,"'GXSetNumIndStages' is not allowed between GXBegin/GXEnd");
  }
  if (4 < param1) {
                    
    OSPanic("GXBump.c",0x146,"GXSetNumIndStages: Exceeds max. number of indirect texture stages");
  }
  if ((param1 & 0xf8) != 0) {
                    
    OSPanic("GXBump.c",0x147,"GX Internal: Register field out of range");
  }
  gx->field491_0x204 = gx->field491_0x204 & 0xfff8ffff | (uint)param1 << 0x10;
  gx->flags4F0 = gx->flags4F0 | 6;
  return;
}


/* Library Function - Single Match
    GXSetTevDirect
   
   Library: KioskDefault 0 0 */

void GXSetTevDirect(int param1) { //80028CAC
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0x158,"'GXSetTevDirect' is not allowed between GXBegin/GXEnd");
  }
  GXInitIndTexture(param1,0,0,0,0,0,0,0,0,0);
  return;
}


/* Library Function - Single Match
    GXSetTevIndRepeat
   
   Library: KioskDefault 0 0 */

void GXSetTevIndRepeat(int param1) { //80028D28
  if (isInGxBegin) {
                    
    OSPanic("GXBump.c",0x231,"'GXSetTevIndRepeat' is not allowed between GXBegin/GXEnd");
  }
  GXInitIndTexture(param1,0,0,0,0,6,6,1,0,0);
  return;
}


/* Library Function - Single Match
    GXSetTevOrder
   
   Library: KioskDefault 0 0 */

void GXSetTevOrder(void) { //80028DA4
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void **ppvVar4;
  uint uVar5;
  
  ppvVar4 = &gxDlist_80327478;
  uVar3 = 0;
  uVar2 = 0;
  for (uVar5 = 0; uVar5 < (gx->field491_0x204 >> 0x10 & 7); uVar5 = uVar5 + 1) {
    if (uVar5 == 2) {
      ppvVar4 = (void **)(*(uint *)&gx->field_0x120 >> 0xc & 7);
    }
    else if ((int)uVar5 < 2) {
      if (uVar5 == 0) {
        ppvVar4 = (void **)(*(uint *)&gx->field_0x120 & 7);
      }
      else if (-1 < (int)uVar5) {
        ppvVar4 = (void **)(*(uint *)&gx->field_0x120 >> 6 & 7);
      }
    }
    else if ((int)uVar5 < 4) {
      ppvVar4 = (void **)(*(uint *)&gx->field_0x120 >> 0x12 & 7);
    }
    uVar3 = uVar3 | 1 << (int)ppvVar4;
  }
  for (uVar5 = 0; uVar5 < (gx->field491_0x204 >> 10 & 0xf) + 1; uVar5 = uVar5 + 1) {
    uVar1 = gx->field1083_0x47c[uVar5 + 8] & 0xfffffeff;
    if (uVar1 != 0xff) {
      uVar2 = uVar2 | 1 << uVar1;
    }
  }
  if ((uVar3 & uVar2) == 0) {
    if ((*(uint *)&gx->field_0x124 & 0xff) != uVar3) {
      if ((uVar3 & 0xffffff00) != 0) {
                    
        OSPanic("GXBump.c",0x26e,"GX Internal: Register field out of range");
      }
      *(uint *)&gx->field_0x124 = *(uint *)&gx->field_0x124 & 0xffffff00 | uVar3;
      GXFIFO._0_1_ = 0x61;
      GXFIFO = *(undefined4 *)&gx->field_0x124;
      *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x124 >> 0x16 & 0x3fc) + 0xc00) =
           *(undefined4 *)&gx->field_0x124;
      gx->field2_0x2 = 1;
    }
    return;
  }
                    
  OSPanic("GXBump.c",0x269,"GXSetTevOrder/GXSetIndTexOrder: Same texture map cannot be specified in both");
}

