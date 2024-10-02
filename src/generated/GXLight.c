
/* Library Function - Single Match
    GXInitLightAttn
   
   Library: KioskDefault 0 0 */

void GXInitLightAttn(double param1,double param2,double param3,double param4,double param5,
                    double param6,int param7) { //80022BE4
  if (param7 == 0) {
                    
    OSPanic("GXLight.c",0x62,"Light Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",99,"'GXInitLightAttn' is not allowed between GXBegin/GXEnd");
  }
  *(float *)(param7 + 0x10) = (float)param1;
  *(float *)(param7 + 0x14) = (float)param2;
  *(float *)(param7 + 0x18) = (float)param3;
  *(float *)(param7 + 0x1c) = (float)param4;
  *(float *)(param7 + 0x20) = (float)param5;
  *(float *)(param7 + 0x24) = (float)param6;
  return;
}


/* Library Function - Single Match
    GXGetLightAttnA
   
   Library: KioskDefault 0 0 */

void GXGetLightAttnA(int param1,undefined4 *param2,undefined4 *param3,undefined4 *param4) { //80022CA0
  if (param1 == 0) {
                    
    OSPanic("GXLight.c",0x7a,"Light Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x7b,"'GXGetLightAttnA' is not allowed between GXBegin/GXEnd");
  }
  *param2 = *(undefined4 *)(param1 + 0x10);
  *param3 = *(undefined4 *)(param1 + 0x14);
  *param4 = *(undefined4 *)(param1 + 0x18);
  return;
}


/* Library Function - Single Match
    GXGetLightAttnK
   
   Library: KioskDefault 0 0 */

void GXGetLightAttnK(int param1,undefined4 *param2,undefined4 *param3,undefined4 *param4) { //80022D44
  if (param1 == 0) {
                    
    OSPanic("GXLight.c",0x8e,"Light Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x8f,"'GXGetLightAttnK' is not allowed between GXBegin/GXEnd");
  }
  *param2 = *(undefined4 *)(param1 + 0x1c);
  *param3 = *(undefined4 *)(param1 + 0x20);
  *param4 = *(undefined4 *)(param1 + 0x24);
  return;
}


/* Library Function - Single Match
    GXInitLightSpot
   
   Library: KioskDefault 0 0 */

void GXInitLightSpot(double param1,int param2,undefined4 param3) { //80022DE8
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
  _savefpr_25();
  if (param2 == 0) {
                    
    OSPanic("GXLight.c",0xa7,"Light Object Pointer is null");
  }
  if (isInGxBegin != false) {
                    
    OSPanic("GXLight.c",0xa9,"'GXInitLightSpot' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 <= 0.0) || (90.0 < param1)) {
    param3 = 0;
  }
  dVar4 = mathFn_800633b0((double)((float)(param1 * 3.141592741012573) / 180.0));
  if (false) {
switchD_80022eb0_caseD_0:
    fVar1 = 1.0;
    fVar2 = 0.0;
    fVar3 = 0.0;
  }
  else {
                    /* {@symbol 80022fd4} */
    switch(param3) {
    default:
      goto switchD_80022eb0_caseD_0;
    case 1:
      fVar1 = (float)(dVar4 * -1000.0);
      fVar2 = 1000.0;
      fVar3 = 0.0;
      break;
    case 2:
      fVar1 = (float)(-dVar4 / (double)(float)(1.0 - dVar4));
      fVar2 = 1.0 / (float)(1.0 - dVar4);
      fVar3 = 0.0;
      break;
    case 3:
      fVar1 = 0.0;
      fVar2 = (float)(-dVar4 / (double)(float)(1.0 - dVar4));
      fVar3 = 1.0 / (float)(1.0 - dVar4);
      break;
    case 4:
      fVar3 = (float)(1.0 - dVar4) * (float)(1.0 - dVar4);
      fVar1 = (float)(dVar4 * (double)(float)(dVar4 - 2.0)) / fVar3;
      fVar2 = 2.0 / fVar3;
      fVar3 = -1.0 / fVar3;
      break;
    case 5:
      fVar3 = (float)(1.0 - dVar4) * (float)(1.0 - dVar4);
      fVar1 = (float)(dVar4 * -4.0) / fVar3;
      fVar2 = ((float)(dVar4 + 1.0) * 4.0) / fVar3;
      fVar3 = -4.0 / fVar3;
      break;
    case 6:
      fVar3 = (float)(1.0 - dVar4) * (float)(1.0 - dVar4);
      fVar1 = 1.0 - (float)((double)(float)(dVar4 * 2.0) * dVar4) / fVar3;
      fVar2 = (float)(dVar4 * 4.0) / fVar3;
      fVar3 = -2.0 / fVar3;
    }
  }
  *(float *)(param2 + 0x10) = fVar1;
  *(float *)(param2 + 0x14) = fVar2;
  *(float *)(param2 + 0x18) = fVar3;
  _restfpr_25();
  return;
}


/* Library Function - Single Match
    GXInitLightDistAttn
   
   Library: KioskDefault 0 0 */

void GXInitLightDistAttn(double param1,double param2,int param3,int param4) { //80023008
  float fVar1;
  float fVar2;
  
  _savefpr_27();
  if (param3 == 0) {
                    
    OSPanic("GXLight.c",0xf2,"Light Object Pointer is null");
  }
  if (isInGxBegin != false) {
                    
    OSPanic("GXLight.c",0xf4,"'GXInitLightDistAttn' is not allowed between GXBegin/GXEnd");
  }
  if (param1 < 0.0) {
    param4 = 0;
  }
  if ((param2 <= 0.0) || (1.0 <= param2)) {
    param4 = 0;
  }
  if (param4 == 2) {
    fVar1 = ((float)(1.0 - param2) * 0.5) / (float)(param2 * param1);
    fVar2 = ((float)(1.0 - param2) * 0.5) / (float)(param1 * (double)(float)(param2 * param1));
  }
  else {
    if (param4 < 2) {
      if ((param4 != 0) && (-1 < param4)) {
        fVar1 = (float)(1.0 - param2) / (float)(param2 * param1);
        fVar2 = 0.0;
        goto LAB_8002315c;
      }
    }
    else if (param4 < 4) {
      fVar1 = 0.0;
      fVar2 = (float)(1.0 - param2) / (float)(param1 * (double)(float)(param2 * param1));
      goto LAB_8002315c;
    }
    fVar1 = 0.0;
    fVar2 = 0.0;
  }
LAB_8002315c:
  *(float *)(param3 + 0x1c) = 1.0;
  *(float *)(param3 + 0x20) = fVar1;
  *(float *)(param3 + 0x24) = fVar2;
  _restfpr_27();
  return;
}


/* Library Function - Single Match
    GXInitLightPos
   
   Library: KioskDefault 0 0 */

void GXInitLightPos(double param1,double param2,double param3,int param4) { //80023184
  if (param4 == 0) {
                    
    OSPanic("GXLight.c",0x129,"Light Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",299,"'GXInitLightPos' is not allowed between GXBegin/GXEnd");
  }
  *(float *)(param4 + 0x28) = (float)param1;
  *(float *)(param4 + 0x2c) = (float)param2;
  *(float *)(param4 + 0x30) = (float)param3;
  return;
}


/* Library Function - Single Match
    gxLightFn_8002321c
   
   Library: KioskDefault 0 0 */

void gxLightFn_8002321c(double param1,double param2,double param3,int param4) { //8002321C
  if (param4 == 0) {
                    
    OSPanic("GXLight.c",0x149,"Light Object Pointer is null");
  }
  *(float *)(param4 + 0x34) = -(float)param1;
  *(float *)(param4 + 0x38) = -(float)param2;
  *(float *)(param4 + 0x3c) = -(float)param3;
  return;
}


/* Library Function - Single Match
    GXInitSpecularDir
   
   Library: KioskDefault 0 0 */

void GXInitSpecularDir(double param1,double param2,double param3,int param4) { //800232A0
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  _savefpr_25();
  if (param4 == 0) {
                    
    OSPanic("GXLight.c",0x16f,"Light Object Pointer is null");
  }
  if (isInGxBegin != false) {
                    
    OSPanic("GXLight.c",0x170,"'GXInitSpecularDir' is not allowed between GXBegin/GXEnd");
  }
  dVar4 = -param1;
  dVar3 = -param2;
  dVar2 = (double)(float)(-param3 + 1.0);
  dVar1 = FUN_800103cc((double)((float)(dVar2 * dVar2) +
                               (float)(dVar4 * dVar4) + (float)(dVar3 * dVar3)));
  dVar1 = (double)(float)(1.0 / dVar1);
  *(float *)(param4 + 0x34) = (float)(dVar4 * dVar1);
  *(float *)(param4 + 0x38) = (float)(dVar3 * dVar1);
  *(float *)(param4 + 0x3c) = (float)(dVar2 * dVar1);
  *(float *)(param4 + 0x28) = (float)(-param1 * 1048576.0);
  *(float *)(param4 + 0x2c) = (float)(-param2 * 1048576.0);
  *(float *)(param4 + 0x30) = (float)(-param3 * 1048576.0);
  _restfpr_25();
  return;
}


/* Library Function - Single Match
    GXInitLightColor
   
   Library: KioskDefault 0 0 */

void GXInitLightColor(int param1,byte *param2) { //800233AC
  if (param1 == 0) {
                    
    OSPanic("GXLight.c",0x1a8,"Light Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x1a9,"'GXInitLightColor' is not allowed between GXBegin/GXEnd");
  }
  *(uint *)(param1 + 0xc) =
       (uint)param2[3] | (uint)param2[2] << 8 | (uint)*param2 << 0x18 | (uint)param2[1] << 0x10;
  return;
}


/* Library Function - Single Match
    GXLoadLightObjImm
   
   Library: KioskDefault 0 0 */

void GXLoadLightObjImm(int param1,int param2) { //80023448
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int local_48;
  
  if (param1 == 0) {
                    
    OSPanic("GXLight.c",0x1c9,"Light Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x1ca,"'GXLoadLightObjImm' is not allowed between GXBegin/GXEnd");
  }
  if (param2 == 0x10) {
    local_48 = 4;
  }
  else if (param2 < 0x10) {
    if (param2 == 4) {
      local_48 = 2;
    }
    else if (param2 < 4) {
      if (param2 == 2) {
        local_48 = 1;
      }
      else {
        if ((1 < param2) || (param2 < 1)) goto LAB_80023584;
        local_48 = 0;
      }
    }
    else {
      if (param2 != 8) goto LAB_80023584;
      local_48 = 3;
    }
  }
  else if (param2 == 0x40) {
    local_48 = 6;
  }
  else if (param2 < 0x40) {
    if (param2 != 0x20) {
LAB_80023584:
                    
      OSPanic("GXLight.c",0x1da,"GXLoadLightStateImm: Invalid Light Id");
    }
    local_48 = 5;
  }
  else {
    if (param2 != 0x80) goto LAB_80023584;
    local_48 = 7;
  }
  iVar1 = local_48 * 0x10;
  uVar4 = iVar1 + 0x600;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = uVar4 | 0xf0000;
  GXFIFO = 0;
  if (uVar4 < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x775) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x545] = 1;
  }
  else if (uVar4 < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc80) = 0;
    (&DAT_00001418)[(int)(&pGxDebug->dprint + local_48 * 4)] = 1;
  }
  else if (uVar4 < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa00) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x1a5] = 1;
  }
  else if (uVar4 < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa00) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x1a5] = 1;
  }
  else {
    iVar3 = iVar1 + -0xa00;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = 0;
      pGxDebug->isRegInit[iVar1 + 0x600] = 1;
    }
  }
  GXFIFO = 0;
  if (iVar1 + 0x601U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x779) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x546] = 1;
  }
  else if (iVar1 + 0x601U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc84) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x246] = 1;
  }
  else if (iVar1 + 0x601U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa04) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x1a6] = 1;
  }
  else if (iVar1 + 0x601U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa04) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x1a6] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9ff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = 0;
      pGxDebug->isRegInit[iVar1 + 0x601] = 1;
    }
  }
  GXFIFO = 0;
  if (iVar1 + 0x602U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x77d) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x547] = 1;
  }
  else if (iVar1 + 0x602U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc88) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x247] = 1;
  }
  else if (iVar1 + 0x602U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa08) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x1a7] = 1;
  }
  else if (iVar1 + 0x602U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa08) = 0;
    pGxDebug[1].isRegInit[iVar1 + 0x1a7] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = 0;
      pGxDebug->isRegInit[iVar1 + 0x602] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0xc);
  GXFIFO = *(undefined4 *)(param1 + 0xc);
  if (iVar1 + 0x603U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x781) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x548] = 1;
  }
  else if (iVar1 + 0x603U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc8c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x248] = 1;
  }
  else if (iVar1 + 0x603U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa0c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1a8] = 1;
  }
  else if (iVar1 + 0x603U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa0c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1a8] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x603] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x10);
  GXFIFO = *(undefined4 *)(param1 + 0x10);
  if (iVar1 + 0x604U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x785) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x549] = 1;
  }
  else if (iVar1 + 0x604U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc90) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x249] = 1;
  }
  else if (iVar1 + 0x604U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa10) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1a9] = 1;
  }
  else if (iVar1 + 0x604U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa10) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1a9] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x604] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x14);
  GXFIFO = *(undefined4 *)(param1 + 0x14);
  if (iVar1 + 0x605U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x789) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x54a] = 1;
  }
  else if (iVar1 + 0x605U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc94) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x24a] = 1;
  }
  else if (iVar1 + 0x605U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa14) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1aa] = 1;
  }
  else if (iVar1 + 0x605U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa14) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1aa] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x605] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x18);
  GXFIFO = *(undefined4 *)(param1 + 0x18);
  if (iVar1 + 0x606U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x78d) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x54b] = 1;
  }
  else if (iVar1 + 0x606U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc98) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x24b] = 1;
  }
  else if (iVar1 + 0x606U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa18) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ab] = 1;
  }
  else if (iVar1 + 0x606U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa18) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ab] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x606] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x1c);
  GXFIFO = *(undefined4 *)(param1 + 0x1c);
  if (iVar1 + 0x607U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x791) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x54c] = 1;
  }
  else if (iVar1 + 0x607U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xc9c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x24c] = 1;
  }
  else if (iVar1 + 0x607U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa1c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ac] = 1;
  }
  else if (iVar1 + 0x607U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa1c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ac] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x607] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x20);
  GXFIFO = *(undefined4 *)(param1 + 0x20);
  if (iVar1 + 0x608U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x795) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x54d] = 1;
  }
  else if (iVar1 + 0x608U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xca0) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x24d] = 1;
  }
  else if (iVar1 + 0x608U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa20) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ad] = 1;
  }
  else if (iVar1 + 0x608U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa20) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ad] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x608] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x24);
  GXFIFO = *(undefined4 *)(param1 + 0x24);
  if (iVar1 + 0x609U < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x799) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x54e] = 1;
  }
  else if (iVar1 + 0x609U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xca4) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x24e] = 1;
  }
  else if (iVar1 + 0x609U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa24) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ae] = 1;
  }
  else if (iVar1 + 0x609U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa24) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1ae] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f7;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x609] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x28);
  GXFIFO = *(undefined4 *)(param1 + 0x28);
  if (iVar1 + 0x60aU < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x79d) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x54f] = 1;
  }
  else if (iVar1 + 0x60aU < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xca8) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x24f] = 1;
  }
  else if (iVar1 + 0x60aU < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa28) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1af] = 1;
  }
  else if (iVar1 + 0x60aU < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa28) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1af] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f6;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x60a] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x2c);
  GXFIFO = *(undefined4 *)(param1 + 0x2c);
  if (iVar1 + 0x60bU < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x7a1) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x550] = 1;
  }
  else if (iVar1 + 0x60bU < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xcac) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x250] = 1;
  }
  else if (iVar1 + 0x60bU < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa2c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b0] = 1;
  }
  else if (iVar1 + 0x60bU < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa2c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b0] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f5;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x60b] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x30);
  GXFIFO = *(undefined4 *)(param1 + 0x30);
  if (iVar1 + 0x60cU < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x7a5) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x551] = 1;
  }
  else if (iVar1 + 0x60cU < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xcb0) = uVar2;
    (&DAT_00001424)[(int)(&pGxDebug->dprint + local_48 * 4)] = 1;
  }
  else if (iVar1 + 0x60cU < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa30) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b1] = 1;
  }
  else if (iVar1 + 0x60cU < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa30) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b1] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f4;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x60c] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x34);
  GXFIFO = *(undefined4 *)(param1 + 0x34);
  if (iVar1 + 0x60dU < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x7a9) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x552] = 1;
  }
  else if (iVar1 + 0x60dU < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xcb4) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x252] = 1;
  }
  else if (iVar1 + 0x60dU < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa34) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b2] = 1;
  }
  else if (iVar1 + 0x60dU < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa34) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b2] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f3;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x60d] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x38);
  GXFIFO = *(undefined4 *)(param1 + 0x38);
  if (iVar1 + 0x60eU < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x7ad) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x553] = 1;
  }
  else if (iVar1 + 0x60eU < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xcb8) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x253] = 1;
  }
  else if (iVar1 + 0x60eU < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa38) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b3] = 1;
  }
  else if (iVar1 + 0x60eU < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa38) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b3] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f2;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x60e] = 1;
    }
  }
  uVar2 = *(undefined4 *)(param1 + 0x3c);
  GXFIFO = *(undefined4 *)(param1 + 0x3c);
  if (iVar1 + 0x60fU < 0x400) {
    *(undefined4 *)(pGxDebug[1].isRegInit + local_48 * 0x40 + 0x7b1) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x554] = 1;
  }
  else if (iVar1 + 0x60fU < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xcbc) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x254] = 1;
  }
  else if (iVar1 + 0x60fU < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa3c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b4] = 1;
  }
  else if (iVar1 + 0x60fU < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + local_48 * 0x40 + 0xa3c) = uVar2;
    pGxDebug[1].isRegInit[iVar1 + 0x1b4] = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f1;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar2;
      pGxDebug->isRegInit[iVar1 + 0x60f] = 1;
    }
  }
  gx->field2_0x2 = 0;
  return;
}


/* Library Function - Single Match
    GXSetChanAmbColor
   
   Library: KioskDefault 0 0 */

void GXSetChanAmbColor(int param1,byte *param2) { //8002490C
  int iVar1;
  float fVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x239,"'GXSetChanAmbColor' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == 3) {
    if (false) {
                    
      OSPanic("GXLight.c",0x256,"GX Internal: Register field out of range");
    }
    fVar2 = (float)(*(uint *)&gx->field_0xac & 0xffffff00 | (uint)param2[3]);
    iVar1 = 1;
  }
  else if (param1 < 3) {
    if (param1 == 1) {
      if (false) {
                    
        OSPanic("GXLight.c",0x247,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x248,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x249,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x24a,"GX Internal: Register field out of range");
      }
      fVar2 = (float)((uint)*param2 << 0x18 |
                     (uint)param2[1] << 0x10 |
                     (uint)param2[2] << 8 | *(uint *)&gx->field_0xac & 0xff);
      iVar1 = 1;
    }
    else if (param1 < 1) {
      if (param1 < 0) goto LAB_80024ce8;
      if (false) {
                    
        OSPanic("GXLight.c",0x23e,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x23f,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x240,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x241,"GX Internal: Register field out of range");
      }
      fVar2 = (float)((uint)*param2 << 0x18 |
                     (uint)param2[1] << 0x10 |
                     (uint)param2[2] << 8 | *(uint *)&gx->field_0xa8 & 0xff);
      iVar1 = 0;
    }
    else {
      if (false) {
                    
        OSPanic("GXLight.c",0x250,"GX Internal: Register field out of range");
      }
      fVar2 = (float)(*(uint *)&gx->field_0xa8 & 0xffffff00 | (uint)param2[3]);
      iVar1 = 0;
    }
  }
  else if (param1 == 5) {
    if (false) {
                    
      OSPanic("GXLight.c",0x263,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x264,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x265,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x266,"GX Internal: Register field out of range");
    }
    fVar2 = (float)CONCAT13(*param2,CONCAT12(param2[1],CONCAT11(param2[2],param2[3])));
    iVar1 = 1;
  }
  else {
    if (4 < param1) {
LAB_80024ce8:
                    
      OSPanic("GXLight.c",0x26b,"GXSetChanAmbColor: Invalid Channel Id");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x25b,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x25c,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x25d,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x25e,"GX Internal: Register field out of range");
    }
    fVar2 = (float)CONCAT13(*param2,CONCAT12(param2[1],CONCAT11(param2[2],param2[3])));
    iVar1 = 0;
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = &DAT_0000100a + iVar1;
  GXFIFO = fVar2;
  if ((true) && (iVar1 + 10U < 0x50)) {
    pGxDebug->projMtx[iVar1 + -0x16] = fVar2;
    pGxDebug->isRegInit[(int)(&DAT_0000100a + iVar1)] = 1;
  }
  gx->field2_0x2 = 0;
  *(float *)(&gx->field_0xa8 + iVar1 * 4) = fVar2;
  return;
}


/* Library Function - Single Match
    GXSetChanMatColor
   
   Library: KioskDefault 0 0 */

void GXSetChanMatColor(int param1,byte *param2) { //80024D84
  int iVar1;
  float fVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x28a,"'GXSetChanMatColor' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == 3) {
    if (false) {
                    
      OSPanic("GXLight.c",0x2a7,"GX Internal: Register field out of range");
    }
    fVar2 = (float)(*(uint *)&gx->field_0xb4 & 0xffffff00 | (uint)param2[3]);
    iVar1 = 1;
  }
  else if (param1 < 3) {
    if (param1 == 1) {
      if (false) {
                    
        OSPanic("GXLight.c",0x298,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x299,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x29a,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x29b,"GX Internal: Register field out of range");
      }
      fVar2 = (float)((uint)*param2 << 0x18 |
                     (uint)param2[1] << 0x10 |
                     (uint)param2[2] << 8 | *(uint *)&gx->field_0xb4 & 0xff);
      iVar1 = 1;
    }
    else if (param1 < 1) {
      if (param1 < 0) goto LAB_80025160;
      if (false) {
                    
        OSPanic("GXLight.c",0x28f,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x290,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x291,"GX Internal: Register field out of range");
      }
      if (false) {
                    
        OSPanic("GXLight.c",0x292,"GX Internal: Register field out of range");
      }
      fVar2 = (float)((uint)*param2 << 0x18 |
                     (uint)param2[1] << 0x10 |
                     (uint)param2[2] << 8 | *(uint *)&gx->field_0xb0 & 0xff);
      iVar1 = 0;
    }
    else {
      if (false) {
                    
        OSPanic("GXLight.c",0x2a1,"GX Internal: Register field out of range");
      }
      fVar2 = (float)(*(uint *)&gx->field_0xb0 & 0xffffff00 | (uint)param2[3]);
      iVar1 = 0;
    }
  }
  else if (param1 == 5) {
    if (false) {
                    
      OSPanic("GXLight.c",0x2b4,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2b5,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2b6,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2b7,"GX Internal: Register field out of range");
    }
    fVar2 = (float)CONCAT13(*param2,CONCAT12(param2[1],CONCAT11(param2[2],param2[3])));
    iVar1 = 1;
  }
  else {
    if (4 < param1) {
LAB_80025160:
                    
      OSPanic("GXLight.c",700,"GXSetChanMatColor: Invalid Channel Id");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2ac,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2ad,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2ae,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x2af,"GX Internal: Register field out of range");
    }
    fVar2 = (float)CONCAT13(*param2,CONCAT12(param2[1],CONCAT11(param2[2],param2[3])));
    iVar1 = 0;
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = &DAT_0000100c + iVar1;
  GXFIFO = fVar2;
  if ((true) && (iVar1 + 0xcU < 0x50)) {
    pGxDebug->projMtx[iVar1 + -0x14] = fVar2;
    pGxDebug->isRegInit[(int)(&DAT_0000100c + iVar1)] = 1;
  }
  gx->field2_0x2 = 0;
  *(float *)(&gx->field_0xb0 + iVar1 * 4) = fVar2;
  return;
}


/* Library Function - Single Match
    GXSetNumChans
   
   Library: KioskDefault 0 0 */

void GXSetNumChans(byte param1) { //800251FC
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x2d5,"'GXSetNumChans' is not allowed between GXBegin/GXEnd");
  }
  if (2 < param1) {
                    
    OSPanic("GXLight.c",0x2d6,s_GXSetNumChans__nChans_>_2_802d9e24);
  }
  if ((param1 & 0xf8) != 0) {
                    
    OSPanic("GXLight.c",0x2d8,"GX Internal: Register field out of range");
  }
  gx->field491_0x204 = gx->field491_0x204 & 0xffffff8f | (uint)param1 << 4;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x1009;
  GXFIFO = (uint)param1;
  if ((true) && (true)) {
    *(uint *)&pGxDebug->field_0x2c = (uint)param1;
    pGxDebug->isRegInit[0x1009] = 1;
  }
  gx->flags4F0 = gx->flags4F0 | 4;
  return;
}


/* Library Function - Single Match
    GXSetChanCtrl
   
   Library: KioskDefault 0 0 */

void GXSetChanCtrl(int param1,uint param2,uint param3,uint param4,uint param5,uint param6,int param7
                  ) { //80025310
  uint uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  if (isInGxBegin) {
                    
    OSPanic("GXLight.c",0x2f8,"'GXSetChanCtrl' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 < 0) || (5 < param1)) {
                    
    OSPanic("GXLight.c",0x2fb,"GXSetChanCtrl: Invalid Channel Id");
  }
  if (param1 == 4) {
    iVar3 = 0;
  }
  else {
    iVar3 = param1;
    if (param1 == 5) {
      iVar3 = 1;
    }
  }
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXLight.c",0x302,"GX Internal: Register field out of range");
  }
  if ((param4 & 0xfffffffe) != 0) {
                    
    OSPanic("GXLight.c",0x303,"GX Internal: Register field out of range");
  }
  if ((param3 & 0xfffffffe) != 0) {
                    
    OSPanic("GXLight.c",0x304,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXLight.c",0x305,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXLight.c",0x306,"GX Internal: Register field out of range");
  }
  if (false) {
                    
    OSPanic("GXLight.c",0x307,"GX Internal: Register field out of range");
  }
  if (true) {
    if (false) {
                    
      OSPanic("GXLight.c",0x309,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x30a,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXLight.c",0x30b,"GX Internal: Register field out of range");
    }
    if (true) {
      uVar1 = param6;
      if (param7 == 0) {
        uVar1 = 0;
      }
      if ((uVar1 & 0xfffffffc) != 0) {
                    
        OSPanic("GXLight.c",0x30e,"GX Internal: Register field out of range");
      }
      if (param7 == 0) {
        param6 = 0;
      }
      iVar2 = -param7 + 2;
      if ((iVar2 + (-(-param7 + 1) - (uint)(iVar2 == 0)) & 0xfffffffe) == 0) {
        iVar2 = -param7 + 2;
        if (true) {
          fVar4 = (float)(((((((((((param2 & 0xff) << 1 | param4) & 0xffffffbb | param3 << 6 |
                                 (uint)((param5 & 1) != 0) * 4) & 0xfffffff7 |
                                (uint)((param5 & 2) != 0) * 8) & 0xffffffef |
                               (uint)((param5 & 4) != 0) * 0x10) & 0xfffff7df |
                               (uint)((param5 & 8) != 0) * 0x20 |
                              (uint)((param5 & 0x10) != 0) * 0x800) & 0xffffefff |
                             (uint)((param5 & 0x20) != 0) * 0x1000) & 0xffffdfff |
                            (uint)((param5 & 0x40) != 0) * 0x2000) & 0xffffbe7f |
                            (uint)((param5 & 0x80) != 0) * 0x4000 | param6 << 7) & 0xfffffdff |
                          (iVar2 + (-(-param7 + 1) - (uint)(iVar2 == 0))) * 0x200) & 0xfffffbff |
                         (uint)(param7 != 0) * 0x400);
          GXFIFO._0_1_ = 0x10;
          GXFIFO = iVar3 + 0x100e;
          GXFIFO = fVar4;
          if ((-1 < iVar3 + 0xe) && (iVar3 + 0xe < 0x50)) {
            pGxDebug->projMtx[iVar3 + -0x12] = fVar4;
            pGxDebug->isRegInit[iVar3 + 0x100e] = 1;
          }
          gx->field2_0x2 = 0;
          if (param1 == 4) {
            GXFIFO._0_1_ = 0x10;
            GXFIFO = 0x1010;
            GXFIFO = fVar4;
            if ((true) && (true)) {
              *(float *)&pGxDebug->field_0x48 = fVar4;
              pGxDebug->isRegInit[0x1010] = 1;
            }
          }
          else if (param1 == 5) {
            GXFIFO._0_1_ = 0x10;
            GXFIFO = 0x1011;
            GXFIFO = fVar4;
            if ((true) && (true)) {
              *(float *)&pGxDebug->field_0x4c = fVar4;
              pGxDebug->isRegInit[0x1011] = 1;
            }
          }
          return;
        }
                    
        OSPanic("GXLight.c",0x310,"GX Internal: Register field out of range");
      }
                    
      OSPanic("GXLight.c",0x30f,"GX Internal: Register field out of range");
    }
                    
    OSPanic("GXLight.c",0x30c,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXLight.c",0x308,"GX Internal: Register field out of range");
}

