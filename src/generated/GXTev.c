
/* Library Function - Single Match
    GXSetTevOp
   
   Library: KioskDefault 0 0 */

void GXSetTevOp(int param1,int param2) { //80028FAC
  uint param4;
  uint param2_00;
  
  param2_00 = 10;
  param4 = 5;
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x72,"'GXSetTevOp' is not allowed between GXBegin/GXEnd");
  }
  if (param1 != 0) {
    param2_00 = 0;
    param4 = 0;
  }
  if (param2 == 2) {
    GXSetTevColorIn(param1,param2_00,0xc,8,0xf);
    GXSetTevAlphaIn(param1,7,4,param4,7);
  }
  else if (param2 < 2) {
    if (param2 == 0) {
      GXSetTevColorIn(param1,0xf,8,param2_00,0xf);
      GXSetTevAlphaIn(param1,7,4,param4,7);
    }
    else {
      if (param2 < 0) {
LAB_80029134:
                    
        OSPanic("GXTev.c",0x8f,"GXSetTevOp: Invalid Tev Mode");
      }
      GXSetTevColorIn(param1,param2_00,8,9,0xf);
      GXSetTevAlphaIn(param1,7,7,7,param4);
    }
  }
  else if (param2 == 4) {
    GXSetTevColorIn(param1,0xf,0xf,0xf,param2_00);
    GXSetTevAlphaIn(param1,7,7,7,param4);
  }
  else {
    if (3 < param2) goto LAB_80029134;
    GXSetTevColorIn(param1,0xf,0xf,0xf,8);
    GXSetTevAlphaIn(param1,7,7,7,4);
  }
  GXSetTevColorOp(param1,0,0,0,1,0);
  GXSetTevAlphaOp(param1,0,0,0,1,0);
  return;
}


/* Library Function - Single Match
    GXSetTevColorIn
   
   Library: KioskDefault 0 0 */

void GXSetTevColorIn(int param1,uint param2,uint param3,uint param4,uint param5) { //80029198
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0xe5,"'GXSetTevColorIn' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < param1) {
                    
    OSPanic("GXTev.c",0xe6,"GXSetTevColor: Invalid Tev Stage Index");
  }
  if (0xf < (int)param2) {
                    
    OSPanic("GXTev.c",0xe7,"GXSetTev*In: A/B/C/D argument out of range");
  }
  if (0xf < (int)param3) {
                    
    OSPanic("GXTev.c",0xe8,"GXSetTev*In: A/B/C/D argument out of range");
  }
  if (0xf < (int)param4) {
                    
    OSPanic("GXTev.c",0xe9,"GXSetTev*In: A/B/C/D argument out of range");
  }
  if (0xf < (int)param5) {
                    
    OSPanic("GXTev.c",0xea,"GXSetTev*In: A/B/C/D argument out of range");
  }
  puVar1 = (uint *)(&gx->field_0x130 + param1 * 4);
  if ((param2 & 0xfffffff0) != 0) {
                    
    OSPanic("GXTev.c",0xed,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xffff0fff | param2 << 0xc;
  if ((param3 & 0xfffffff0) != 0) {
                    
    OSPanic("GXTev.c",0xee,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffff0ff | param3 << 8;
  if ((param4 & 0xfffffff0) != 0) {
                    
    OSPanic("GXTev.c",0xef,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xffffff0f | param4 << 4;
  if ((param5 & 0xfffffff0) != 0) {
                    
    OSPanic("GXTev.c",0xf0,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffff0 | param5;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevAlphaIn
   
   Library: KioskDefault 0 0 */

void GXSetTevAlphaIn(int param1,uint param2,uint param3,uint param4,uint param5) { //8002938C
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x108,"'GXSetTevAlphaIn' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < param1) {
                    
    OSPanic("GXTev.c",0x109,"GXSetTevAlpha: Invalid Tev Stage Index");
  }
  if (7 < (int)param2) {
                    
    OSPanic("GXTev.c",0x10a,"GXSetTev*In: A/B/C/D argument out of range");
  }
  if (7 < (int)param3) {
                    
    OSPanic("GXTev.c",0x10b,"GXSetTev*In: A/B/C/D argument out of range");
  }
  if (7 < (int)param4) {
                    
    OSPanic("GXTev.c",0x10c,"GXSetTev*In: A/B/C/D argument out of range");
  }
  if (7 < (int)param5) {
                    
    OSPanic("GXTev.c",0x10d,"GXSetTev*In: A/B/C/D argument out of range");
  }
  puVar1 = (uint *)(&gx->field_0x170 + param1 * 4);
  if ((param2 & 0xfffffff8) != 0) {
                    
    OSPanic("GXTev.c",0x110,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xffff1fff | param2 << 0xd;
  if ((param3 & 0xfffffff8) != 0) {
                    
    OSPanic("GXTev.c",0x111,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xffffe3ff | param3 << 10;
  if ((param4 & 0xfffffff8) != 0) {
                    
    OSPanic("GXTev.c",0x112,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffc7f | param4 << 7;
  if ((param5 & 0xfffffff8) != 0) {
                    
    OSPanic("GXTev.c",0x113,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xffffff8f | param5 << 4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevColorOp
   
   Library: KioskDefault 0 0 */

void GXSetTevColorOp(int param1,uint param2,uint param3,uint param4,uint param5,uint param6) { //80029584
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x12e,"'GXSetTevColorOp' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < param1) {
                    
    OSPanic("GXTev.c",0x12f,"GXSetTevColor: Invalid Tev Stage Index");
  }
  puVar1 = (uint *)(&gx->field_0x130 + param1 * 4);
  if (false) {
                    
    OSPanic("GXTev.c",0x137,"GX Internal: Register field out of range");
  }
  *puVar1 = (param2 & 1) << 0x12 | *puVar1 & 0xfffbffff;
  if ((int)param2 < 2) {
    if ((param4 & 0xfffffffc) != 0) {
                    
      OSPanic("GXTev.c",0x139,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xffcfffff | param4 << 0x14;
    if ((param3 & 0xfffffffc) != 0) {
                    
      OSPanic("GXTev.c",0x13a,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xfffcffff | param3 << 0x10;
  }
  else {
    if (false) {
                    
      OSPanic("GXTev.c",0x13c,"GX Internal: Register field out of range");
    }
    *puVar1 = (param2 & 6) << 0x13 | *puVar1 & 0xffcfffff;
    *puVar1 = *puVar1 & 0xfffcffff | 0x30000;
  }
  if ((param5 & 0xfe) != 0) {
                    
    OSPanic("GXTev.c",0x140,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfff7ffff | (param5 & 0xff) << 0x13;
  if ((param6 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x141,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xff3fffff | param6 << 0x16;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevAlphaOp
   
   Library: KioskDefault 0 0 */

void GXSetTevAlphaOp(int param1,uint param2,uint param3,uint param4,uint param5,uint param6) { //8002978C
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x15a,"'GXSetTevAlphaOp' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < param1) {
                    
    OSPanic("GXTev.c",0x15b,"GXSetTevAlpha: Invalid Tev Stage Index");
  }
  puVar1 = (uint *)(&gx->field_0x170 + param1 * 4);
  if (false) {
                    
    OSPanic("GXTev.c",0x163,"GX Internal: Register field out of range");
  }
  *puVar1 = (param2 & 1) << 0x12 | *puVar1 & 0xfffbffff;
  if ((int)param2 < 2) {
    if ((param4 & 0xfffffffc) != 0) {
                    
      OSPanic("GXTev.c",0x165,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xffcfffff | param4 << 0x14;
    if ((param3 & 0xfffffffc) != 0) {
                    
      OSPanic("GXTev.c",0x166,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xfffcffff | param3 << 0x10;
  }
  else {
    if (false) {
                    
      OSPanic("GXTev.c",0x168,"GX Internal: Register field out of range");
    }
    *puVar1 = (param2 & 6) << 0x13 | *puVar1 & 0xffcfffff;
    *puVar1 = *puVar1 & 0xfffcffff | 0x30000;
  }
  if ((param5 & 0xfe) != 0) {
                    
    OSPanic("GXTev.c",0x16c,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfff7ffff | (param5 & 0xff) << 0x13;
  if ((param6 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x16d,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xff3fffff | param6 << 0x16;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevColor
   
   Library: KioskDefault 0 0 */

void GXSetTevColor(int param1,byte *param2) { //80029994
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x182,"'GXSetTevColor' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x185,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x186,"GX Internal: Register field out of range");
  }
  if ((param1 * 2 + 0xe0U & 0xffffff00) != 0) {
                    
    OSPanic("GXTev.c",0x187,"GX Internal: Register field out of range");
  }
  uVar1 = (param1 * 2 + 0xe0) * 0x1000000;
  uVar3 = uVar1 | (uint)param2[3] << 0xc | (uint)*param2;
  if (false) {
                    
    OSPanic("GXTev.c",0x18a,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x18b,"GX Internal: Register field out of range");
  }
  if ((param1 * 2 + 0xe1U & 0xffffff00) != 0) {
                    
    OSPanic("GXTev.c",0x18c,"GX Internal: Register field out of range");
  }
  uVar2 = (param1 * 2 + 0xe1) * 0x1000000;
  uVar4 = uVar2 | (uint)param2[1] << 0xc | (uint)param2[2];
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar3;
  *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar3;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar4;
  *(uint *)(pGxDebug->isRegInit + (uVar2 >> 0x16) + 0xc00) = uVar4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar4;
  *(uint *)(pGxDebug->isRegInit + (uVar2 >> 0x16) + 0xc00) = uVar4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar4;
  *(uint *)(pGxDebug->isRegInit + (uVar2 >> 0x16) + 0xc00) = uVar4;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevKColor
   
   Library: KioskDefault 0 0 */

void GXSetTevKColor(int param1,byte *param2) { //80029BA4
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x1dd,"'GXSetTevKColor' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x1e0,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x1e1,"GX Internal: Register field out of range");
  }
  if ((param1 * 2 + 0xe0U & 0xffffff00) != 0) {
                    
    OSPanic("GXTev.c",0x1e3,"GX Internal: Register field out of range");
  }
  uVar1 = (param1 * 2 + 0xe0) * 0x1000000;
  uVar4 = uVar1 | (uint)param2[3] << 0xc | (uint)*param2 | 0x800000;
  if (false) {
                    
    OSPanic("GXTev.c",0x1e6,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x1e7,"GX Internal: Register field out of range");
  }
  if ((param1 * 2 + 0xe1U & 0xffffff00) != 0) {
                    
    OSPanic("GXTev.c",0x1e9,"GX Internal: Register field out of range");
  }
  uVar2 = (param1 * 2 + 0xe1) * 0x1000000;
  uVar3 = uVar2 | (uint)param2[1] << 0xc | (uint)param2[2] | 0x800000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar4;
  *(uint *)(pGxDebug->isRegInit + (uVar1 >> 0x16) + 0xc00) = uVar4;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar3;
  *(uint *)(pGxDebug->isRegInit + (uVar2 >> 0x16) + 0xc00) = uVar3;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevKColorSel
   
   Library: KioskDefault 0 0 */

void GXSetTevKColorSel(uint param1,uint param2) { //80029D7C
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x204,"'GXSetTevKColorSel' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < (int)param1) {
                    
    OSPanic("GXTev.c",0x205,"GXSetTevKColor*: Invalid Tev Stage Index");
  }
  puVar1 = (uint *)(&gx->field_0x1b0 + ((int)param1 >> 1) * 4);
  if ((param1 & 1) == 0) {
    if ((param2 & 0xffffffe0) != 0) {
                    
      OSPanic("GXTev.c",0x20c,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xfffffe0f | param2 << 4;
  }
  else {
    if ((param2 & 0xffffffe0) != 0) {
                    
      OSPanic("GXTev.c",0x20a,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xfff83fff | param2 << 0xe;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevKAlphaSel
   
   Library: KioskDefault 0 0 */

void GXSetTevKAlphaSel(uint param1,uint param2) { //80029EA8
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x225,"'GXSetTevKAlphaSel' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < (int)param1) {
                    
    OSPanic("GXTev.c",0x226,"GXSetTevKColor*: Invalid Tev Stage Index");
  }
  puVar1 = (uint *)(&gx->field_0x1b0 + ((int)param1 >> 1) * 4);
  if ((param1 & 1) == 0) {
    if ((param2 & 0xffffffe0) != 0) {
                    
      OSPanic("GXTev.c",0x22d,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xffffc1ff | param2 << 9;
  }
  else {
    if ((param2 & 0xffffffe0) != 0) {
                    
      OSPanic("GXTev.c",0x22b,"GX Internal: Register field out of range");
    }
    *puVar1 = *puVar1 & 0xff07ffff | param2 << 0x13;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevSwapMode
   
   Library: KioskDefault 0 0 */

void GXSetTevSwapMode(int param1,uint param2,uint param3) { //80029FD4
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x24a,"'GXSetTevSwapMode' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < param1) {
                    
    OSPanic("GXTev.c",0x24b,"GXSetTevSwapMode: Invalid Tev Stage Index");
  }
  puVar1 = (uint *)(&gx->field_0x170 + param1 * 4);
  if ((param2 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x24e,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffffc | param2;
  if ((param3 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x24f,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffff3 | param3 << 2;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetTevSwapModeTable
   
   Library: KioskDefault 0 0 */

void GXSetTevSwapModeTable(int param1,uint param2,uint param3,uint param4,uint param5) { //8002A0F0
  uint *puVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x26e,"'GXSetTevSwapModeTable' is not allowed between GXBegin/GXEnd");
  }
  if (3 < param1) {
                    
    OSPanic("GXTev.c",0x26f,"GXSetTevSwapModeTable: Invalid Swap Selection Index");
  }
  puVar1 = (uint *)(&gx->field_0x1b0 + param1 * 8);
  if ((param2 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x272,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffffc | param2;
  if ((param3 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x273,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffff3 | param3 << 2;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  puVar1 = (uint *)(&gx->field_0x1b4 + param1 * 8);
  if ((param4 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x277,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffffc | param4;
  if ((param5 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x278,"GX Internal: Register field out of range");
  }
  *puVar1 = *puVar1 & 0xfffffff3 | param5 << 2;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar1;
  *(uint *)(pGxDebug->isRegInit + (*puVar1 >> 0x16 & 0x3fc) + 0xc00) = *puVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetAlphaCompare
   
   Library: KioskDefault 0 0 */

void GXSetAlphaCompare(uint param1,uint param2,uint param3,uint param4,uint param5) { //8002A2B8
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x2b2,"'GXSetAlphaCompare' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x2b4,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x2b5,"GX Internal: Register field out of range");
  }
  if ((param1 & 0xfffffff8) != 0) {
                    
    OSPanic("GXTev.c",0x2b6,"GX Internal: Register field out of range");
  }
  if ((param4 & 0xfffffff8) != 0) {
                    
    OSPanic("GXTev.c",0x2b7,"GX Internal: Register field out of range");
  }
  if ((param3 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTev.c",0x2b8,"GX Internal: Register field out of range");
  }
  uVar1 = (((param5 & 0xff) << 8 | param2 & 0xff | (param1 & 0xffc7) << 0x10 | param4 << 0x13) &
           0xff3fffff | param3 << 0x16) & 0xffffff | 0xf3000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar1;
  *(uint *)(pGxDebug->isRegInit + 0xfcc) = uVar1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetZTexture
   
   Library: KioskDefault 0 0 */

void GXSetZTexture(uint param1,int param2,uint param3) { //8002A41C
  uint uVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x2d1,"'GXSetZTexture' is not allowed between GXBegin/GXEnd");
  }
  if ((param3 & 0xff000000) != 0) {
                    
    OSPanic("GXTev.c",0x2d4,"GX Internal: Register field out of range");
  }
  uVar2 = param3 & 0xffffff | 0xf4000000;
  if (param2 == 0x13) {
    uVar1 = 1;
  }
  else if (param2 < 0x13) {
    if (param2 != 0x11) {
LAB_8002a4d4:
                    
      OSPanic("GXTev.c",0x2dd,"GXSetZTexture: Invalid z-texture format");
    }
    uVar1 = 0;
  }
  else {
    if (param2 != 0x16) goto LAB_8002a4d4;
    uVar1 = 2;
  }
  if (false) {
                    
    OSPanic("GXTev.c",0x2e0,"GX Internal: Register field out of range");
  }
  if ((param1 & 0xfffffffc) == 0) {
    uVar1 = uVar1 | (param1 & 0x3fffff) << 2 | 0xf5000000;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar2;
    *(uint *)(pGxDebug->isRegInit + 0xfd0) = uVar2;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar1;
    *(uint *)(pGxDebug->isRegInit + 0xfd4) = uVar1;
    gx->field2_0x2 = 1;
    return;
  }
                    
  OSPanic("GXTev.c",0x2e1,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXSetTevOrder
   
   Library: KioskDefault 0 0 */

void GXSetTevOrder(uint param1,uint param2,uint param3,int param4) { //8002A5A8
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x307,"'GXSetTevOrder' is not allowed between GXBegin/GXEnd");
  }
  if (0xf < (int)param1) {
                    
    OSPanic("GXTev.c",0x308,"GXSetTevColor: Invalid Tev Stage Index");
  }
  puVar3 = (uint *)(&gx->field_0x100 +
                   (((int)param1 >> 1) + (uint)((int)param1 < 0 && (param1 & 1) != 0)) * 4);
  gx->field1083_0x47c[param1 + 8] = param3;
  uVar2 = param3 & 0xfffffeff;
  if (7 < uVar2) {
    uVar2 = 0;
  }
  if (7 < (int)param2) {
    param2 = 0;
  }
  if ((param1 & 1) == 0) {
    if ((uVar2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXTev.c",0x31c,"GX Internal: Register field out of range");
    }
    *puVar3 = *puVar3 & 0xfffffff8 | uVar2;
    if ((param2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXTev.c",0x31d,"GX Internal: Register field out of range");
    }
    *puVar3 = *puVar3 & 0xffffffc7 | param2 << 3;
    if (param4 == 0xff) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(&DAT_802db2cc + param4 * 4);
    }
    if ((uVar2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXTev.c",799,"GX Internal: Register field out of range");
    }
    if (param4 == 0xff) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)(&DAT_802db2cc + param4 * 4);
    }
    *puVar3 = *puVar3 & 0xfffffc7f | iVar1 << 7;
    if (false) {
                    
      OSPanic("GXTev.c",0x321,"GX Internal: Register field out of range");
    }
    iVar1 = 0;
    if ((param3 != 0xff) && ((param3 & 0x100) == 0)) {
      iVar1 = 1;
    }
    *puVar3 = *puVar3 & 0xffffffbf | iVar1 << 6;
  }
  else {
    if ((uVar2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXTev.c",0x314,"GX Internal: Register field out of range");
    }
    *puVar3 = *puVar3 & 0xffff8fff | uVar2 << 0xc;
    if ((param2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXTev.c",0x315,"GX Internal: Register field out of range");
    }
    *puVar3 = *puVar3 & 0xfffc7fff | param2 << 0xf;
    if (param4 == 0xff) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(&DAT_802db2cc + param4 * 4);
    }
    if ((uVar2 & 0xfffffff8) != 0) {
                    
      OSPanic("GXTev.c",0x317,"GX Internal: Register field out of range");
    }
    if (param4 == 0xff) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)(&DAT_802db2cc + param4 * 4);
    }
    *puVar3 = *puVar3 & 0xffc7ffff | iVar1 << 0x13;
    if (false) {
                    
      OSPanic("GXTev.c",0x319,"GX Internal: Register field out of range");
    }
    iVar1 = 0;
    if ((param3 != 0xff) && ((param3 & 0x100) == 0)) {
      iVar1 = 1;
    }
    *puVar3 = *puVar3 & 0xfffbffff | iVar1 << 0x12;
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *puVar3;
  *(uint *)(pGxDebug->isRegInit + (*puVar3 >> 0x16 & 0x3fc) + 0xc00) = *puVar3;
  gx->field2_0x2 = 1;
  gx->flags4F0 = gx->flags4F0 | 1;
  return;
}


/* Library Function - Single Match
    GXSetNumTevStages
   
   Library: KioskDefault 0 0 */

void GXSetNumTevStages(byte param1) { //8002A910
  if (isInGxBegin) {
                    
    OSPanic("GXTev.c",0x331,"'GXSetNumTevStages' is not allowed between GXBegin/GXEnd");
  }
  if (param1 != 0) {
    if (param1 < 0x11) {
      if ((param1 - 1 & 0xfffffff0) != 0) {
                    
        OSPanic("GXTev.c",0x334,"GX Internal: Register field out of range");
      }
      gx->field491_0x204 = gx->field491_0x204 & 0xffffc3ff | (param1 - 1) * 0x400;
      gx->flags4F0 = gx->flags4F0 | 4;
      return;
    }
  }
                    
  OSPanic("GXTev.c",0x333,"GXSetNumTevStages: Exceed max number of tex stages");
}

