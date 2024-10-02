
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void curve_initialise(undefined4 param) { //8012436C
  return;
}


/* @description Called when DLL is unloaded */

void curve_release(void) { //80124370
  return;
}


void curve_clear(void) { //80124374
  nRomCurves = 0;
  return;
}


/* Library Function - Single Match
    curve_addCurveDef
   
   Library: KioskDefault 0 0 */

void curve_addCurveDef(ObjDef_RomCurve *param1) { //80124380
  int iVar1;
  int iVar2;
  
  if (nRomCurves == 1300) {
    OSReport("curves.c: MAX_ROMCURVES exceeded!!");
  }
  else {
    iVar2 = 0;
    while ((iVar1 = nRomCurves, iVar2 < nRomCurves &&
           (*(uint *)((&romCurves)[iVar2] + 0x14) < (uint)(param1->def).id))) {
      iVar2 = iVar2 + 1;
    }
    for (; iVar2 < iVar1; iVar1 = iVar1 + -1) {
      (&romCurves)[iVar1] = (&romCurves)[iVar1 + -1];
    }
    nRomCurves = nRomCurves + 1;
    if (nRomCurves == 1300) {
      printf("addCurveDef: max curves reached %d/%d",1300,0x514);
    }
    (&romCurves)[iVar2] = param1;
  }
  return;
}


/* Library Function - Single Match
    curve_func05
   
   Library: KioskDefault 0 0 */

void curve_remove(int param1) { //80124460
  int iVar1;
  
  iVar1 = 0;
  while ((iVar1 < nRomCurves && (*(int *)(param1 + 0x14) != *(int *)((&romCurves)[iVar1] + 0x14))))
  {
    iVar1 = iVar1 + 1;
  }
  if (iVar1 < nRomCurves) {
    nRomCurves = nRomCurves + -1;
    for (; iVar1 < nRomCurves; iVar1 = iVar1 + 1) {
      (&romCurves)[iVar1] = (&romCurves)[iVar1 + 1];
    }
  }
  return;
}


undefined4 * curve_getCurves(int *outNum) { //801244EC
  *outNum = nRomCurves;
  return &romCurves;
}


/* Library Function - Single Match
    curve_func07
   
   Library: KioskDefault 0 0 */

int curve_find(double x,double y,double z,int *types,int nTypes,int action) { //80124500
  float fVar1;
  float fVar2;
  float fVar3;
  int res;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  _savefpr_27();
  dVar9 = 5000000.0;
  iVar5 = 0;
  res = 0;
  dVar10 = dVar9;
  for (iVar4 = 0; iVar4 < nRomCurves; iVar4 = iVar4 + 1) {
    iVar7 = (&romCurves)[iVar4];
    iVar6 = 0;
    do {
      if ((nTypes < 1) || ((int)*(char *)(iVar7 + 0x19) == types[iVar6])) {
        fVar1 = *(float *)(iVar7 + 8) - (float)x;
        fVar2 = *(float *)(iVar7 + 0xc) - (float)y;
        fVar3 = *(float *)(iVar7 + 0x10) - (float)z;
        dVar8 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
        if (dVar8 < dVar10) {
          iVar5 = iVar7;
          dVar10 = dVar8;
        }
        iVar6 = nTypes;
        if ((*(char *)(iVar7 + 0x18) == action) && (dVar8 < dVar9)) {
          res = iVar7;
          dVar9 = dVar8;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < nTypes);
  }
  if (res != 0) {
    iVar5 = res;
  }
  if (iVar5 == 0) {
    res = -1;
  }
  else {
    res = *(int *)(iVar5 + 0x14);
  }
  _restfpr_27();
  return res;
}


/* Library Function - Single Match
    curve_func09
   
   Library: KioskDefault 0 0 */

undefined4 RomCurve_getById(uint param1) { //8012464C
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (-1 < (int)param1) {
    iVar2 = nRomCurves + -1;
    iVar1 = 0;
    while (iVar1 <= iVar2) {
      iVar3 = iVar2 + iVar1 >> 1;
      if (*(uint *)((&romCurves)[iVar3] + 0x14) < param1) {
        iVar1 = iVar3 + 1;
      }
      else {
        if (*(uint *)((&romCurves)[iVar3] + 0x14) <= param1) {
          return (&romCurves)[iVar3];
        }
        iVar2 = iVar3 + -1;
      }
    }
  }
  return 0;
}


/* choose one of (prev, next, id24, id28) whose ID isn't `exceptThis`, at random. */

int curve_getRandomPoint(ObjDef_RomCurve *curve,int exceptThis) { //801246E0
  uint flag;
  int nPoints;
  int iPoint;
  int points [4];
  
  nPoints = 0;
  flag = 1;
  for (iPoint = 0; iPoint < 4; iPoint = iPoint + 1) {
    if (((-1 < (&curve->idPrev)[iPoint]) && (((int)(char)curve->flags & flag) == 0)) &&
       ((&curve->idPrev)[iPoint] != exceptThis)) {
      points[nPoints] = (&curve->idPrev)[iPoint];
      nPoints = nPoints + 1;
    }
    flag = flag << 1;
  }
  if (nPoints == 0) {
    nPoints = -1;
  }
  else {
    nPoints = randInt(0,nPoints + -1);
    nPoints = points[nPoints];
  }
  return nPoints;
}


/* Library Function - Single Match
    curve_func18
   
   Library: KioskDefault 0 0 */

int curve_getIds_18(int param1,int param2,int param3) { //801247B0
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    if ((-1 < *(int *)(param1 + iVar2 * 4 + 0x1c)) &&
       (*(int *)(param1 + iVar2 * 4 + 0x1c) != param2)) {
      *(undefined4 *)(param3 + iVar1 * 4) = *(undefined4 *)(param1 + iVar2 * 4 + 0x1c);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


/* Library Function - Single Match
    curve_func1A
   
   Library: KioskDefault 0 0 */

undefined4 curve_getRandomPoint1A(int param1,int param2) { //80124828
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_20 [4];
  
  iVar3 = 0;
  uVar2 = 1;
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    if (((-1 < *(int *)(param1 + iVar4 * 4 + 0x1c)) &&
        (((int)*(char *)(param1 + 0x1b) & uVar2) != 0)) &&
       (*(int *)(param1 + iVar4 * 4 + 0x1c) != param2)) {
      local_20[iVar3] = *(undefined4 *)(param1 + iVar4 * 4 + 0x1c);
      iVar3 = iVar3 + 1;
    }
    uVar2 = uVar2 << 1;
  }
  if (iVar3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar3 = randInt(0,iVar3 + -1);
    uVar1 = local_20[iVar3];
  }
  return uVar1;
}


/* Library Function - Single Match
    curve_func19
   
   Library: KioskDefault 0 0 */

void curve_func19(double param1,double param2,double param3,int param4,int param5) { //80124A7C
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58 [2];
  int local_50 [3];
  
  _savefpr_26();
  local_50[1] = 0xffffffff;
  local_50[0] = -1;
  local_58[1] = 0.0;
  local_58[0] = 0.0;
  local_7c = *(float *)(param4 + 8);
  local_78 = *(undefined4 *)(param4 + 0xc);
  local_74 = *(undefined4 *)(param4 + 0x10);
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    if ((-1 < *(int *)(param4 + iVar4 * 4 + 0x1c)) &&
       (iVar3 = RomCurve_getById(*(uint *)(param4 + iVar4 * 4 + 0x1c)), iVar3 != 0)) {
      uVar2 = countLeadingZeros(param5 - *(int *)(param4 + iVar4 * 4 + 0x1c));
      uVar2 = uVar2 >> 5;
      local_70 = *(undefined4 *)(iVar3 + 8);
      local_6c = *(undefined4 *)(iVar3 + 0xc);
      local_68 = *(undefined4 *)(iVar3 + 0x10);
      FUN_801248f8(param1,param2,param3,&local_7c);
      fVar1 = (float)((double)local_5c - param3) * (float)((double)local_5c - param3) +
              (float)((double)local_64 - param1) * (float)((double)local_64 - param1) +
              (float)((double)local_60 - param2) * (float)((double)local_60 - param2);
      if (local_58[uVar2] < fVar1) {
        local_58[uVar2] = fVar1;
        local_50[uVar2] = *(int *)(param4 + iVar4 * 4 + 0x1c);
      }
    }
  }
  _restfpr_26();
  return;
}


/* Library Function - Single Match
    curve_func1D
   
   Library: KioskDefault 0 0 */

void curve_getIds_1D(int param1,undefined4 *param2) { //80124C10
  int iVar1;
  int iVar2;
  
  *param2 = 0xffffffff;
  param2[1] = 0xffffffff;
  param2[2] = 0xffffffff;
  param2[3] = 0xffffffff;
  if (param1 != 0) {
    param2[1] = *(undefined4 *)(param1 + 0x14);
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      if (*(int *)(param1 + iVar1 * 4 + 0x1c) != -1) {
        if (((int)*(char *)(param1 + 0x1b) & 1 << iVar1) == 0) {
          if (((int)*(char *)(param1 + 0x1b) & 1 << iVar1) == 0) {
            param2[2] = *(undefined4 *)(param1 + iVar1 * 4 + 0x1c);
          }
        }
        else {
          *param2 = *(undefined4 *)(param1 + iVar1 * 4 + 0x1c);
        }
      }
    }
    if ((-1 < (int)param2[2]) && (iVar1 = RomCurve_getById(param2[2]), iVar1 != 0)) {
      for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
        if ((*(int *)(iVar1 + iVar2 * 4 + 0x1c) != -1) &&
           (((int)*(char *)(iVar1 + 0x1b) & 1 << iVar2) == 0)) {
          param2[3] = *(undefined4 *)(iVar1 + iVar2 * 4 + 0x1c);
        }
      }
    }
  }
  return;
}


/* Library Function - Single Match
    curve_func1E
   
   Library: KioskDefault 0 0 */

undefined4 curve_func1E(int param1,float *param2,float *param3,float *param4) { //80124D58
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_28 [5];
  
  iVar3 = 0;
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    iVar1 = RomCurve_getById(*(uint *)(param1 + iVar4 * 4));
    local_28[iVar4] = iVar1;
    if (local_28[iVar4] != 0) {
      param2[iVar4] = *(float *)(local_28[iVar4] + 8);
      param3[iVar4] = *(float *)(local_28[iVar4] + 0xc);
      param4[iVar4] = *(float *)(local_28[iVar4] + 0x10);
      iVar3 = iVar3 + 1;
    }
  }
  if (((iVar3 < 2) || (local_28[1] == 0)) || (local_28[2] == 0)) {
    uVar2 = 0;
  }
  else {
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
      if (local_28[iVar3] == 0) {
        if (iVar3 == 0) {
          *param2 = *(float *)(local_28[1] + 8) +
                    (*(float *)(local_28[1] + 8) - *(float *)(local_28[2] + 8));
          *param3 = *(float *)(local_28[1] + 0xc) +
                    (*(float *)(local_28[1] + 0xc) - *(float *)(local_28[2] + 0xc));
          *param4 = *(float *)(local_28[1] + 0x10) +
                    (*(float *)(local_28[1] + 0x10) - *(float *)(local_28[2] + 0x10));
        }
        else if (iVar3 == 3) {
          param2[3] = *(float *)(local_28[2] + 8) +
                      (*(float *)(local_28[2] + 8) - *(float *)(local_28[1] + 8));
          param3[3] = *(float *)(local_28[2] + 0xc) +
                      (*(float *)(local_28[2] + 0xc) - *(float *)(local_28[1] + 0xc));
          param4[3] = *(float *)(local_28[2] + 0x10) +
                      (*(float *)(local_28[2] + 0x10) - *(float *)(local_28[1] + 0x10));
        }
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* Library Function - Single Match
    curve_func1F
   
   Library: KioskDefault 0 0 */

int curve_countRandomPoints(ObjDef_RomCurve *this) { //80124F78
  ObjDef_RomCurve *id;
  int iVar1;
  int count;
  
  count = 1;
  while ((this != (ObjDef_RomCurve *)0x0 && (iVar1 = isNotPoint((int)this), iVar1 == 0))) {
    id = (ObjDef_RomCurve *)getRandomPoint(this,0);
    this = (ObjDef_RomCurve *)RomCurve_getById((uint)id);
    if (this != (ObjDef_RomCurve *)0x0) {
      count = count + 1;
    }
  }
  return count;
}


/* Library Function - Single Match
    curve_func20
   
   Library: KioskDefault 0 0 */

int curve_func20(int param1,int param2,int param3,int param4,int param5) { //80124FE4
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ObjDef_RomCurve *curve;
  double dVar5;
  
  iVar1 = isNotPoint(param1);
  iVar4 = 0;
  if (iVar1 == 0) {
    while ((curve = (ObjDef_RomCurve *)param1, curve != (ObjDef_RomCurve *)0x0 &&
           (iVar1 = isNotPoint((int)curve), iVar1 == 0))) {
      uVar2 = getRandomPoint(curve,0);
      param1 = RomCurve_getById(uVar2);
      if ((ObjDef_RomCurve *)param1 != (ObjDef_RomCurve *)0x0) {
        if (param5 != 0) {
          *(byte *)(param5 + (iVar4 >> 2)) = curve->type;
        }
        *(float *)(param2 + iVar4 * 4) = (curve->def).pos.x;
        *(float *)(param3 + iVar4 * 4) = (curve->def).pos.y;
        *(float *)(param4 + iVar4 * 4) = (curve->def).pos.z;
        iVar1 = iVar4 + 1;
        *(float *)(param2 + iVar1 * 4) = (((ObjDef *)param1)->pos).x;
        *(float *)(param3 + iVar1 * 4) = (((ObjDef *)param1)->pos).y;
        *(float *)(param4 + iVar1 * 4) = (((ObjDef *)param1)->pos).z;
        iVar1 = iVar4 + 2;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)(char)curve->
                                                  rotZ << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
        *(float *)(param2 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)curve->rotX) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)(char)curve->
                                                  rotY << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
        *(float *)(param3 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)curve->rotX) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)(char)curve->rotZ <<
                                                                           8 ^ 0x80000000) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
        ;
        *(float *)(param4 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)curve->rotX) -
                                    4503599627370496.0) * dVar5) * 2.0;
        iVar1 = iVar4 + 3;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)(char)*(byte *)(
                                                  param1 + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
        *(float *)(param2 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)(char)*(byte *)(
                                                  param1 + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
        *(float *)(param3 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)(char)*(byte *)(
                                                  param1 + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
        *(float *)(param4 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        iVar4 = iVar4 + 4;
      }
    }
  }
  else {
    while ((iVar1 = param1, iVar1 != 0 && (iVar3 = isPoint(iVar1), iVar3 == 0))) {
      uVar2 = getRandomPoint1A(iVar1,0);
      param1 = RomCurve_getById(uVar2);
      if (param1 != 0) {
        if (param5 != 0) {
          *(undefined *)(param5 + (iVar4 >> 2)) = *(undefined *)(iVar1 + 0x19);
        }
        *(undefined4 *)(param2 + iVar4 * 4) = *(undefined4 *)(iVar1 + 8);
        *(undefined4 *)(param3 + iVar4 * 4) = *(undefined4 *)(iVar1 + 0xc);
        *(undefined4 *)(param4 + iVar4 * 4) = *(undefined4 *)(iVar1 + 0x10);
        iVar3 = iVar4 + 1;
        *(undefined4 *)(param2 + iVar3 * 4) = *(undefined4 *)(param1 + 8);
        *(undefined4 *)(param3 + iVar3 * 4) = *(undefined4 *)(param1 + 0xc);
        *(undefined4 *)(param4 + iVar3 * 4) = *(undefined4 *)(param1 + 0x10);
        iVar3 = iVar4 + 2;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)*(char *)(iVar1 
                                                  + 0x2c) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
        *(float *)(param2 + iVar3 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(iVar1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)*(char *)(iVar1 
                                                  + 0x2d) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
        *(float *)(param3 + iVar3 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(iVar1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)(iVar1 + 
                                                  0x2c) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                 3.141593) / 32767.0));
        *(float *)(param4 + iVar3 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(iVar1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        iVar1 = iVar4 + 3;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)*(char *)(param1
                                                                                             + 0x2c)
                                                                               << 8 ^ 0x80000000) -
                                                             4503601774854144.0) * 3.141593) /
                                                    32767.0));
        *(float *)(param2 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)*(char *)(param1
                                                                                             + 0x2d)
                                                                               << 8 ^ 0x80000000) -
                                                             4503601774854144.0) * 3.141593) /
                                                    32767.0));
        *(float *)(param3 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)(param1 + 
                                                  0x2c) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                 3.141593) / 32767.0));
        *(float *)(param4 + iVar1 * 4) =
             (float)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param1 + 0x2e)) -
                                    4503599627370496.0) * dVar5) * 2.0;
        iVar4 = iVar4 + 4;
      }
    }
  }
  return iVar4;
}


/* Library Function - Single Match
    curveLinkFn_80125760
   
   Library: KioskDefault 0 0 */

void curve_func2D(Gfx **param1,short **param2,astruct_4 **param3) { //80125760
  int iVar1;
  int iVar2;
  Camera *pCVar3;
  ObjInstance **ppOVar4;
  ObjDef *pOVar5;
  ushort uVar9;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar10;
  int iVar11;
  int iVar12;
  ObjDef *unaff_r22;
  ushort uVar13;
  int iVar14;
  astruct_4 *paVar15;
  ObjDef *param1_00;
  uint uVar16;
  ObjDef *pOVar17;
  uint uVar18;
  int iVar19;
  byte bVar20;
  short *psVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float local_ca0;
  float local_c9c;
  float local_c98;
  ushort local_c94;
  short local_c90;
  short local_c8e;
  short local_c8c;
  float local_c88;
  float local_c84;
  float local_c80;
  float local_c7c;
  float local_c78;
  float local_c74;
  float local_c70;
  float local_c6c;
  float local_c68;
  float local_c64;
  float local_c60;
  float local_c5c;
  float local_c58;
  float local_c54;
  float local_c50;
  float local_c4c [25];
  float local_be8 [25];
  float local_b84 [25];
  ObjDef *local_b20 [512];
  char local_320 [512];
  astruct_4 *local_120;
  Gfx *local_11c;
  short local_118;
  short local_116;
  short local_114;
  int local_110;
  int local_10c;
  uint local_108;
  int local_104;
  ObjInstance *local_100;
  double local_f8;
  double local_f0;
  double local_e8;
  longlong local_e0;
  double local_d8;
  double local_d0;
  longlong local_c8;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  double local_78;
  
  _savefpr_27();
  local_100 = Object_getSidekicksLoaded();
  pCVar3 = getCurCamera();
  FUN_800a4fa4(param1,(undefined4 *)0x0,(undefined4 *)0x0,0x80000002,0,0,1);
  curveFn_80126360((uint **)param1,param2,param3);
  local_11c = *param1;
  psVar21 = *param2;
  paVar15 = *param3;
  ppOVar4 = Object_getObjects(&local_104,&local_110);
  iVar12 = 0;
  for (local_104 = 0; local_104 < local_110; local_104 = local_104 + 1) {
    uVar16 = FUN_80181d50((int)ppOVar4[local_104]);
    if ((((uVar16 & 0xff) != 0) && (ppOVar4[local_104]->objId == 0x2e)) &&
       ((*(char *)((int)&ppOVar4[local_104]->def[1].objType + 1) != '\b' &&
        (*(char *)((int)&ppOVar4[local_104]->def[1].objType + 1) != '\x1a')))) {
      local_320[iVar12] = '\0';
      local_b20[iVar12] = ppOVar4[local_104]->def;
      iVar12 = iVar12 + 1;
    }
  }
  if (0x1ff < iVar12) {
    printf("MAX_CURVE overflow!!");
  }
  local_10c = 0;
  do {
    for (local_104 = 0; (local_104 < iVar12 && (local_320[local_104] != '\0'));
        local_104 = local_104 + 1) {
    }
    if (local_104 < iVar12) {
      local_320[local_104] = '\x01';
      pOVar17 = local_b20[local_104];
      if (*(char *)((int)&pOVar17[1].objType + 1) != '&') {
        if (*(char *)((int)&pOVar17[1].objType + 1) == '$') {
          param1_00 = pOVar17;
          if (local_100 == (ObjInstance *)0x0) {
            param1_00 = (ObjDef *)0x0;
          }
        }
        else {
          param1_00 = (ObjDef *)0x0;
        }
        local_108 = 1;
        for (iVar14 = 0; iVar14 < 4; iVar14 = iVar14 + 1) {
          uVar13 = 0;
          if ((-1 < *(int *)(&pOVar17[1].loadFlags + iVar14 * 4)) &&
             (((int)(char)pOVar17[1].mapStates1 & local_108) == 0)) {
            pOVar5 = (ObjDef *)RomCurve_getById(*(uint *)(&pOVar17[1].loadFlags + iVar14 * 4));
            if (param1_00 != (ObjDef *)0x0) {
              unaff_r22 = pOVar5;
            }
            if (pOVar5 != (ObjDef *)0x0) {
              dVar22 = (double)FUN_8007aecc(&(pOVar17->pos).x,&(pCVar3->pos).x);
              dVar23 = (double)FUN_8007aecc(&(pOVar5->pos).x,&(pCVar3->pos).x);
              if (dVar23 < dVar22) {
                dVar22 = dVar23;
              }
              uVar16 = (uint)((1.0 - (float)(dVar22 / 750.0)) * 24.0);
              local_78 = (double)(longlong)(int)uVar16;
              if ((int)uVar16 < 8) {
                uVar16 = 8;
              }
              if (*(int *)(&pOVar17[1].loadFlags + iVar14 * 4) == 0x94) {
                iVar19._0_1_ = pOVar5[1].loadFlags;
                iVar19._1_1_ = pOVar5[1].mapStates2;
                iVar19._2_1_ = pOVar5[1].bound;
                iVar19._3_1_ = pOVar5[1].cullDist;
                printf("Actual links  %i ,%i ,%i, %i ",iVar19,(int)pOVar5[1].pos.x,
                       (int)pOVar5[1].pos.y,(int)pOVar5[1].pos.z);
              }
              local_78 = (double)CONCAT44(0x43300000,(uint)*(byte *)((int)&pOVar17[1].id + 2));
              dVar24 = (double)((float)(local_78 - 4503599627370496.0) * 2.0);
              uStack_7c = (uint)*(byte *)((int)&pOVar5[1].id + 2);
              local_80 = 0x43300000;
              dVar23 = (double)((float)((double)CONCAT44(0x43300000,uStack_7c) - 4503599627370496.0)
                               * 2.0);
              local_c5c = (pOVar17->pos).x;
              uStack_84 = (int)*(char *)&pOVar17[1].id << 8 ^ 0x80000000;
              local_88 = 0x43300000;
              dVar22 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                      uStack_84) -
                                                                    4503601774854144.0) * 3.141593)
                                                           / 32767.0));
              local_c54 = (float)(dVar24 * dVar22);
              local_c58 = (pOVar5->pos).x;
              uStack_8c = (int)*(char *)&pOVar5[1].id << 8 ^ 0x80000000;
              local_90 = 0x43300000;
              dVar22 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                      uStack_8c) -
                                                                    4503601774854144.0) * 3.141593)
                                                           / 32767.0));
              local_c50 = (float)(dVar23 * dVar22);
              local_c6c = (pOVar17->pos).y;
              uStack_94 = (int)*(char *)((int)&pOVar17[1].id + 1) << 8 ^ 0x80000000;
              local_98 = 0x43300000;
              dVar22 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                      uStack_94) -
                                                                    4503601774854144.0) * 3.141593)
                                                           / 32767.0));
              local_c64 = (float)(dVar24 * dVar22);
              local_c68 = (pOVar5->pos).y;
              uStack_9c = (int)*(char *)((int)&pOVar5[1].id + 1) << 8 ^ 0x80000000;
              local_a0 = 0x43300000;
              dVar22 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                      uStack_9c) -
                                                                    4503601774854144.0) * 3.141593)
                                                           / 32767.0));
              local_c60 = (float)(dVar23 * dVar22);
              local_c7c = (pOVar17->pos).z;
              uStack_a4 = (int)*(char *)&pOVar17[1].id << 8 ^ 0x80000000;
              local_a8 = 0x43300000;
              dVar22 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                                  uStack_a4) -
                                                                4503601774854144.0) * 3.141593) /
                                                       32767.0));
              local_c74 = (float)(dVar24 * dVar22);
              local_c78 = (pOVar5->pos).z;
              uStack_ac = (int)*(char *)&pOVar5[1].id << 8 ^ 0x80000000;
              local_b0 = 0x43300000;
              dVar22 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                                  uStack_ac) -
                                                                4503601774854144.0) * 3.141593) /
                                                       32767.0));
              local_c70 = (float)(dVar23 * dVar22);
              local_c90 = (short)((int)*(char *)&pOVar17[1].id << 8);
              local_c8e = (short)((int)*(char *)((int)&pOVar17[1].id + 1) << 8);
              local_c8c = (short)((int)*(char *)&pOVar17[1].id << 8);
              uStack_b4 = *(char *)&pOVar5[1].id * 0x100 + *(char *)&pOVar17[1].id * -0x100 ^
                          0x80000000;
              local_b8 = 0x43300000;
              uStack_bc = uVar16 ^ 0x80000000;
              local_c0 = 0x43300000;
              iVar19 = (int)((float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0) /
                            (float)((double)CONCAT44(0x43300000,uStack_bc) - 4503601774854144.0));
              local_c8 = (longlong)iVar19;
              local_d0 = (double)CONCAT44(0x43300000,
                                          *(char *)((int)&pOVar5[1].id + 1) * 0x100 +
                                          *(char *)((int)&pOVar17[1].id + 1) * -0x100 ^ 0x80000000);
              local_d8 = (double)CONCAT44(0x43300000,uVar16 ^ 0x80000000);
              iVar1 = (int)((float)(local_d0 - 4503601774854144.0) /
                           (float)(local_d8 - 4503601774854144.0));
              local_e0 = (longlong)iVar1;
              local_e8 = (double)CONCAT44(0x43300000,
                                          *(char *)&pOVar5[1].id * 0x100 +
                                          *(char *)&pOVar17[1].id * -0x100 ^ 0x80000000);
              local_f0 = (double)CONCAT44(0x43300000,uVar16 ^ 0x80000000);
              iVar2 = (int)((float)(local_e8 - 4503601774854144.0) /
                           (float)(local_f0 - 4503601774854144.0));
              local_f8 = (double)(longlong)iVar2;
              local_11c->cmd = (uVar16 + 1) * 0x2000 & 0xfe000 | 0x1000000 | (uVar16 + 1) * 4 & 0xfc
              ;
              local_11c->param = (u32)psVar21;
              iVar11 = 0;
              iVar10 = 0xff;
              uVar18 = 0;
              dVar22 = 0.0;
              local_120 = paVar15;
              local_11c = local_11c + 1;
              do {
                dVar23 = FUN_8006bba0(dVar22,&local_c5c,(float *)0x0);
                local_b84[uVar18] = (float)dVar23;
                dVar23 = FUN_8006bba0(dVar22,&local_c6c,(float *)0x0);
                local_be8[uVar18] = (float)dVar23;
                dVar23 = FUN_8006bba0(dVar22,&local_c7c,(float *)0x0);
                local_c4c[uVar18] = (float)dVar23;
                local_f8 = (double)CONCAT44(0x43300000,uVar16 ^ 0x80000000);
                dVar22 = (double)(float)(dVar22 + (double)(1.0 / (float)(local_f8 -
                                                                        4503601774854144.0)));
                local_c88 = 0.0;
                local_c84 = 1.0;
                local_c80 = 0.0;
                FUN_8007a878(&local_c90,&local_c88);
                local_f0 = (double)(longlong)(int)(local_b84[uVar18] - playerMapOffsetX);
                local_114 = (short)(int)(local_b84[uVar18] - playerMapOffsetX);
                local_e8 = (double)(longlong)(int)local_be8[uVar18];
                local_116 = (short)(int)local_be8[uVar18];
                local_e0 = (longlong)(int)(local_c4c[uVar18] - playerMapOffsetZ);
                local_118 = (short)(int)(local_c4c[uVar18] - playerMapOffsetZ);
                local_d8 = (double)(longlong)(int)(local_c88 * 5.0);
                *psVar21 = local_114 + (short)(int)(local_c88 * 5.0);
                local_d0 = (double)(longlong)(int)(local_c84 * 5.0);
                psVar21[1] = local_116 + (short)(int)(local_c84 * 5.0);
                local_c8 = (longlong)(int)(local_c80 * 5.0);
                psVar21[2] = local_118 + (short)(int)(local_c80 * 5.0);
                *(char *)(psVar21 + 6) = (char)iVar11;
                *(undefined *)((int)psVar21 + 0xd) = 0;
                *(char *)(psVar21 + 7) = (char)iVar10;
                *(undefined *)((int)psVar21 + 0xf) = 0xff;
                psVar21[4] = 0;
                psVar21[5] = 0;
                psVar21[3] = 0;
                if ((((7 < (int)uVar16) && (param1_00 != (ObjDef *)0x0)) && (uVar13 == 0)) &&
                   (((int)(char)param1_00[1].mapStates1 & 1 << iVar14 + 4) == 0)) {
                  local_ca0 = local_b84[uVar18];
                  local_c9c = local_be8[uVar18];
                  local_c98 = local_c4c[uVar18];
                    /* {@symbol 80121f7c} */
                  uVar9 = (**(code **)(*(int *)pDll_curve + 8))(&local_ca0,0);
                  local_c94 = uVar9;
                  if ((uVar18 == uVar16) || (uVar9 != 0)) {
                    if (uVar9 != (&param1_00->loadFlags)[iVar14]) {
                      iVar6 = mapFindFn_800a9114(unaff_r22);
                      iVar7 = mapFindFn_800a9114(param1_00);
                      if (iVar7 == iVar6) {
                        printf("Assigning curve node link between %d and %d to walkgroup %d",param1_00->id,
                               unaff_r22->id,(int)(short)uVar9);
                        (&param1_00->loadFlags)[iVar14] = (RomListObjLoadFlags)uVar9;
                      }
                    }
                    for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
                      if (*(int *)(&unaff_r22[1].loadFlags + iVar6 * 4) == param1_00->id) {
                        if (uVar9 != (&unaff_r22->loadFlags)[iVar6]) {
                          iVar7 = mapFindFn_800a9114(unaff_r22);
                          iVar8 = mapFindFn_800a9114(param1_00);
                          if (iVar8 == iVar7) {
                            printf("Assigning curve node link between %d and %d to walkgroup %d",unaff_r22->id,
                                   param1_00->id,(int)(short)uVar9);
                            (&unaff_r22->loadFlags)[iVar6] = (RomListObjLoadFlags)uVar9;
                          }
                        }
                        break;
                      }
                    }
                    param1_00[1].mapStates1 = param1_00[1].mapStates1 | (byte)(1 << iVar14 + 4);
                    uVar13 = uVar9;
                  }
                }
                local_c88 = 0.0;
                local_c84 = -1.0;
                local_c80 = 0.0;
                FUN_8007a878(&local_c90,&local_c88);
                local_c90 = local_c90 + (short)iVar19;
                local_c8e = local_c8e + (short)iVar1;
                local_c8c = local_c8c + (short)iVar2;
                local_f8 = (double)(longlong)(int)(local_c88 * 5.0);
                psVar21[8] = local_114 + (short)(int)(local_c88 * 5.0);
                local_f0 = (double)(longlong)(int)(local_c84 * 5.0);
                psVar21[9] = local_116 + (short)(int)(local_c84 * 5.0);
                local_e8 = (double)(longlong)(int)(local_c80 * 5.0);
                psVar21[10] = local_118 + (short)(int)(local_c80 * 5.0);
                *(char *)(psVar21 + 0xe) = (char)iVar11;
                *(undefined *)((int)psVar21 + 0x1d) = 0xb4;
                *(char *)(psVar21 + 0xf) = (char)iVar10;
                *(undefined *)((int)psVar21 + 0x1f) = 0xff;
                psVar21[0xc] = 0;
                psVar21[0xd] = 0;
                psVar21[0xb] = 0;
                psVar21 = psVar21 + 0x10;
                iVar11 = iVar11 + 0xf0 / (int)uVar16;
                iVar10 = iVar10 - 0xf0 / (int)uVar16;
                uVar18 = uVar18 + 1;
              } while ((int)uVar18 <= (int)uVar16);
              iVar19 = 0;
              do {
                *(undefined *)paVar15 = 0x40;
                bVar20 = (byte)iVar19;
                paVar15->field1_0x1 = bVar20;
                paVar15->field2_0x2 = bVar20 + 2;
                paVar15->field3_0x3 = bVar20 + 1;
                paVar15->field_0x10 = 0x40;
                paVar15->field17_0x11 = bVar20 + 1;
                paVar15->field18_0x12 = bVar20 + 2;
                paVar15->field19_0x13 = bVar20 + 3;
                paVar15 = paVar15 + 1;
                iVar19 = iVar19 + 2;
              } while (iVar19 < (int)(uVar16 << 1));
              FUN_800a6d88((uint **)&local_11c,local_120,uVar16 << 1);
            }
          }
          local_108 = local_108 << 1;
        }
      }
    }
    else {
      local_10c = 1;
    }
    if (local_10c != 0) {
      *param1 = local_11c;
      *param2 = psVar21;
      *param3 = paVar15;
      _restfpr_27();
      return;
    }
  } while( true );
}


void curve_func0D(undefined4 *param1,undefined4 *param2) { //801268F4
  *param1 = DAT_80399384;
  *param2 = DAT_80399388;
  return;
}


/* Library Function - Single Match
    curve_func0A
   
   Library: KioskDefault 0 0 */

void curve_func0A(double param1,double param2,double param3,int param4,int param5,float *param6,
                  float *param7,float *param8) { //80126908
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  
  _savefpr_30();
  *param8 = 0.0;
  *param7 = 0.0;
  *param6 = 0.0;
  dVar8 = 5000000.0;
  for (iVar2 = 0; iVar2 < nRomCurves; iVar2 = iVar2 + 1) {
    iVar4 = (&romCurves)[iVar2];
    if ((*(char *)(iVar4 + 0x18) == param5) && (*(char *)(iVar4 + 0x19) == param4)) {
      local_58 = *(float *)(iVar4 + 8);
      local_54 = *(undefined4 *)(iVar4 + 0xc);
      local_50 = *(undefined4 *)(iVar4 + 0x10);
      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        if ((((int)*(char *)(iVar4 + 0x1b) & 1 << iVar3) == 0) &&
           (iVar1 = RomCurve_getById(*(uint *)(iVar4 + iVar3 * 4 + 0x1c)), iVar1 != 0)) {
          local_4c = *(undefined4 *)(iVar1 + 8);
          local_48 = *(undefined4 *)(iVar1 + 0xc);
          local_44 = *(undefined4 *)(iVar1 + 0x10);
          dVar6 = (double)FUN_801248f8((double)(float)param1,(double)(float)param2,
                                       (double)(float)param3,&local_58);
          dVar7 = dVar6;
          if (dVar6 < 0.0) {
            dVar7 = -dVar6;
          }
          dVar5 = dVar8;
          if (dVar8 < 0.0) {
            dVar5 = -dVar8;
          }
          if (dVar7 < dVar5) {
            DAT_80399384 = iVar4;
            DAT_80399388 = iVar1;
            *param6 = local_40;
            *param7 = local_3c;
            *param8 = local_38;
            dVar8 = dVar6;
          }
        }
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    curve_func0B
   
   Library: KioskDefault 0 0 */

double curve_distFn0B(vec3f *param1,uint id) { //80126AB4
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  double dVar5;
  
  _savefpr_29();
  iVar4 = RomCurve_getById(id);
  if ((iVar4 == 0) || (param1 == (vec3f *)0x0)) {
    dVar5 = -1.0;
  }
  else {
    fVar1 = *(float *)(iVar4 + 8) - param1[1].x;
    fVar2 = *(float *)(iVar4 + 0xc) - param1[1].y;
    fVar3 = *(float *)(iVar4 + 0x10) - param1[1].z;
    dVar5 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
  }
  _restfpr_29();
  return dVar5;
}


/* Library Function - Single Match
    curve_func0C
   
   Library: KioskDefault 0 0 */

double curve_distXZ(double x,double z,uint id) { //80126B48
  ObjDef_RomCurve *curve;
  double result;
  float dx;
  float dz;
  
  _savefpr_30();
  curve = (ObjDef_RomCurve *)RomCurve_getById(id);
  if (curve == (ObjDef_RomCurve *)0x0) {
    result = -1.0;
  }
  else {
    dx = (curve->def).pos.x - (float)x;
    dz = (curve->def).pos.z - (float)z;
    result = sqrt((double)(dx * dx + dz * dz));
  }
  _restfpr_30();
  return result;
}


/* Library Function - Single Match
    curve_func0E
   
   Library: KioskDefault 0 0 */

undefined4 curve_isPoint(int param1) { //80126BC8
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (3 < iVar1) {
      return 1;
    }
    if ((*(int *)(param1 + iVar1 * 4 + 0x1c) != -1) &&
       (((int)*(char *)(param1 + 0x1b) & 1 << iVar1) != 0)) break;
    iVar1 = iVar1 + 1;
  }
  return 0;
}


/* Library Function - Single Match
    curve_func0F
   
   Library: KioskDefault 0 0 */

undefined4 curve_isNotPoint(int param1) { //80126C28
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (3 < iVar1) {
      return 1;
    }
    if ((*(int *)(param1 + iVar1 * 4 + 0x1c) != -1) &&
       (((int)*(char *)(param1 + 0x1b) & 1 << iVar1) == 0)) break;
    iVar1 = iVar1 + 1;
  }
  return 0;
}


/* Library Function - Single Match
    curve_func10
   
   Library: KioskDefault 0 0 */

int curve_findFn10(int param1,int param2,int param3,int *param4) { //80126C88
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_30 [5];
  
  if (param1 == 0) {
    local_30[0] = -1;
  }
  else {
    iVar3 = 0;
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
      if (-1 < *(int *)(param1 + iVar4 * 4 + 0x1c)) {
        iVar1 = RomCurve_getById(*(uint *)(param1 + iVar4 * 4 + 0x1c));
        for (iVar2 = 0; iVar2 < param3; iVar2 = iVar2 + 1) {
          if ((int)*(char *)(iVar1 + 0x19) == *(int *)(param2 + iVar2 * 4)) {
            local_30[iVar3] = *(int *)(param1 + iVar4 * 4 + 0x1c);
            iVar3 = iVar3 + 1;
            iVar2 = param3;
          }
        }
      }
    }
    if (iVar3 == 0) {
      local_30[0] = -1;
    }
    else if (iVar3 == 1) {
      *param4 = *(int *)(param1 + 0x14);
    }
    else if (iVar3 < 2) {
      local_30[0] = -1;
    }
    else {
      for (iVar4 = 0; iVar4 < iVar3; iVar4 = iVar4 + 1) {
        if (*param4 == local_30[iVar4]) {
          for (; iVar4 < iVar3 + -1; iVar4 = iVar4 + 1) {
            local_30[iVar4] = local_30[iVar4 + 1];
          }
          iVar3 = iVar3 + -1;
        }
      }
      *param4 = *(int *)(param1 + 0x14);
      iVar3 = randInt(0,iVar3 + -1);
      local_30[0] = local_30[iVar3];
    }
  }
  return local_30[0];
}


/* Library Function - Single Match
    curve_func11
   
   Library: KioskDefault 0 0 */

void curve_func11(int param1,int param2,int param3,int *param4) { //80126E18
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  float local_6c8 [40];
  int local_628 [40];
  char local_588 [1300];
  float local_74 [4];
  int local_64;
  int local_60;
  int local_5c [6];
  
  _savefpr_30();
  if (param1 != 0) {
    FUN_801256b8(*(uint *)(param1 + 0x14),&local_64);
    iVar7 = 0;
    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
      if (-1 < *(int *)(param1 + iVar5 * 4 + 0x1c)) {
        for (iVar9 = 0; iVar9 < 0x514; iVar9 = iVar9 + 1) {
          local_588[iVar9] = '\0';
        }
        local_588[local_64] = '\x01';
        iVar9 = FUN_801256b8(*(uint *)(param1 + iVar5 * 4 + 0x1c),&local_60);
        local_6c8[0] = (*(float *)(iVar9 + 0x10) - *(float *)(param1 + 0x10)) *
                       (*(float *)(iVar9 + 0x10) - *(float *)(param1 + 0x10)) +
                       (*(float *)(iVar9 + 8) - *(float *)(param1 + 8)) *
                       (*(float *)(iVar9 + 8) - *(float *)(param1 + 8)) +
                       (*(float *)(iVar9 + 0xc) - *(float *)(param1 + 0xc)) *
                       (*(float *)(iVar9 + 0xc) - *(float *)(param1 + 0xc));
        local_628[0] = local_60;
        iVar9 = 1;
        local_588[local_60] = '\x01';
        bVar2 = false;
        do {
          if (iVar9 < 1) {
            bVar2 = true;
          }
          else {
            iVar9 = iVar9 + -1;
            local_60 = local_628[iVar9];
            iVar8 = (&romCurves)[local_628[iVar9]];
            dVar10 = (double)local_6c8[iVar9];
            if ((*(char *)(iVar8 + 0x19) == param2) &&
               ((param3 == -1 || (param3 == *(char *)(iVar8 + 0x18))))) {
              bVar2 = true;
              *(float *)(local_588 + iVar7 * 4 + 0x514) = local_6c8[iVar9];
              local_5c[iVar7] = *(int *)(param1 + iVar5 * 4 + 0x1c);
              iVar7 = iVar7 + 1;
            }
            else {
              for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
                if ((((-1 < *(int *)(iVar8 + iVar4 * 4 + 0x1c)) &&
                     (iVar3 = FUN_801256b8(*(uint *)(iVar8 + iVar4 * 4 + 0x1c),&local_60),
                     iVar3 != 0)) && (local_588[local_60] == '\0')) && (iVar9 < 0x28)) {
                  fVar1 = (*(float *)(iVar8 + 0x10) - *(float *)(iVar3 + 0x10)) *
                          (*(float *)(iVar8 + 0x10) - *(float *)(iVar3 + 0x10)) +
                          (*(float *)(iVar8 + 0xc) - *(float *)(iVar3 + 0xc)) *
                          (*(float *)(iVar8 + 0xc) - *(float *)(iVar3 + 0xc)) +
                          (float)((double)(*(float *)(iVar8 + 8) - *(float *)(iVar3 + 8)) *
                                  (double)(*(float *)(iVar8 + 8) - *(float *)(iVar3 + 8)) + dVar10);
                  for (iVar3 = 0; (iVar6 = iVar9, iVar3 < iVar9 && (fVar1 < local_6c8[iVar3]));
                      iVar3 = iVar3 + 1) {
                  }
                  for (; iVar3 < iVar6; iVar6 = iVar6 + -1) {
                    local_628[iVar6] = local_628[iVar6 + -1];
                    local_6c8[iVar6] = local_6c8[iVar6 + -1];
                  }
                  iVar9 = iVar9 + 1;
                  local_6c8[iVar3] = fVar1;
                  local_628[iVar3] = local_60;
                  local_588[local_60] = '\x01';
                }
              }
            }
          }
        } while (!bVar2);
      }
    }
    if (iVar7 != 0) {
      if (iVar7 == 1) {
        *param4 = *(int *)(param1 + 0x14);
      }
      else if (1 < iVar7) {
        for (iVar5 = 0; iVar5 < iVar7; iVar5 = iVar5 + 1) {
          if (*param4 == local_5c[iVar5]) {
            for (; iVar5 < iVar7 + -1; iVar5 = iVar5 + 1) {
              local_5c[iVar5] = local_5c[iVar5 + 1];
              *(undefined4 *)(local_588 + iVar5 * 4 + 0x514) =
                   *(undefined4 *)(local_588 + (iVar5 + 1) * 4 + 0x514);
            }
            iVar7 = iVar7 + -1;
          }
        }
        *param4 = *(int *)(param1 + 0x14);
        iVar5 = 0;
        for (iVar9 = 0; iVar9 < iVar7; iVar9 = iVar9 + 1) {
          if (*(float *)(local_588 + iVar9 * 4 + 0x514) < *(float *)(local_588 + iVar5 * 4 + 0x514))
          {
            iVar5 = iVar9;
          }
        }
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    curve_func12
   
   Library: KioskDefault 0 0 */

int curve_findByAction(int param1) { //80127284
  int iCurve;
  ObjDef_RomCurve *curve;
  
  printf(" Curve Id %i ",param1);
  iCurve = 0;
  while( true ) {
    if (nRomCurves <= iCurve) {
      return -1;
    }
    curve = (ObjDef_RomCurve *)(&romCurves)[iCurve];
    if ((curve->type == 0x15) &&
       (printf(" CI %i ",(int)(short)curve[1].def.objType),
       (short)curve[1].def.objType == param1)) break;
    iCurve = iCurve + 1;
  }
  return (curve->def).id;
}


/* Library Function - Single Match
    curve_func13
   
   Library: KioskDefault 0 0 */

void curve_func13(uint param1,int param2,uint param3,int *param4) { //80127320
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  char local_6c8 [4];
  float local_6c4 [40];
  int local_624 [40];
  char local_584 [1300];
  float local_70 [4];
  int local_60;
  int local_5c;
  undefined4 local_58 [4];
  
  _savefpr_30();
  iVar3 = FUN_801256b8(param1,&local_60);
  if (iVar3 != 0) {
    iVar8 = 0;
    for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
      if (-1 < *(int *)(iVar3 + iVar6 * 4 + 0x1c)) {
        for (iVar9 = 0; iVar9 < 0x514; iVar9 = iVar9 + 1) {
          local_584[iVar9] = '\0';
        }
        local_584[local_60] = '\x01';
        iVar9 = FUN_801256b8(*(uint *)(iVar3 + iVar6 * 4 + 0x1c),&local_5c);
        local_6c4[0] = (*(float *)(iVar9 + 0x10) - *(float *)(iVar3 + 0x10)) *
                       (*(float *)(iVar9 + 0x10) - *(float *)(iVar3 + 0x10)) +
                       (*(float *)(iVar9 + 8) - *(float *)(iVar3 + 8)) *
                       (*(float *)(iVar9 + 8) - *(float *)(iVar3 + 8)) +
                       (*(float *)(iVar9 + 0xc) - *(float *)(iVar3 + 0xc)) *
                       (*(float *)(iVar9 + 0xc) - *(float *)(iVar3 + 0xc));
        local_624[0] = local_5c;
        iVar9 = 1;
        local_584[local_5c] = '\x01';
        bVar2 = false;
        do {
          if (iVar9 < 1) {
            bVar2 = true;
          }
          else {
            iVar9 = iVar9 + -1;
            local_5c = local_624[iVar9];
            iVar10 = (&romCurves)[local_624[iVar9]];
            dVar11 = (double)local_6c4[iVar9];
            if (((*(char *)(iVar10 + 0x19) == param2) || (param2 == -1)) &&
               ((*(byte *)(iVar10 + 0x31) == param3 ||
                ((*(byte *)(iVar10 + 0x32) == param3 || (*(byte *)(iVar10 + 0x33) == param3)))))) {
              bVar2 = true;
              *(float *)(local_584 + iVar8 * 4 + 0x514) = local_6c4[iVar9];
              if (iVar8 < 4) {
                local_58[iVar8] = *(undefined4 *)(iVar10 + 0x14);
                local_6c8[iVar8] = (char)iVar6;
                iVar8 = iVar8 + 1;
              }
            }
            else {
              for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
                if ((((-1 < *(int *)(iVar10 + iVar5 * 4 + 0x1c)) &&
                     (iVar4 = FUN_801256b8(*(uint *)(iVar10 + iVar5 * 4 + 0x1c),&local_5c),
                     iVar4 != 0)) && (local_584[local_5c] == '\0')) && (iVar9 < 0x28)) {
                  fVar1 = (*(float *)(iVar10 + 0x10) - *(float *)(iVar4 + 0x10)) *
                          (*(float *)(iVar10 + 0x10) - *(float *)(iVar4 + 0x10)) +
                          (*(float *)(iVar10 + 0xc) - *(float *)(iVar4 + 0xc)) *
                          (*(float *)(iVar10 + 0xc) - *(float *)(iVar4 + 0xc)) +
                          (float)((double)(*(float *)(iVar10 + 8) - *(float *)(iVar4 + 8)) *
                                  (double)(*(float *)(iVar10 + 8) - *(float *)(iVar4 + 8)) + dVar11)
                  ;
                  for (iVar4 = 0; (iVar7 = iVar9, iVar4 < iVar9 && (fVar1 < local_6c4[iVar4]));
                      iVar4 = iVar4 + 1) {
                  }
                  for (; iVar4 < iVar7; iVar7 = iVar7 + -1) {
                    local_624[iVar7] = local_624[iVar7 + -1];
                    local_6c4[iVar7] = local_6c4[iVar7 + -1];
                  }
                  iVar9 = iVar9 + 1;
                  local_6c4[iVar4] = fVar1;
                  local_624[iVar4] = local_5c;
                  local_584[local_5c] = '\x01';
                }
              }
            }
          }
        } while (!bVar2);
      }
    }
    if (0 < iVar8) {
      iVar3 = 0;
      for (iVar6 = 0; iVar6 < iVar8; iVar6 = iVar6 + 1) {
        if (*(float *)(local_584 + iVar6 * 4 + 0x514) < *(float *)(local_584 + iVar3 * 4 + 0x514)) {
          iVar3 = iVar6;
        }
      }
      if (param4 != (int *)0x0) {
        *param4 = (int)local_6c8[iVar3];
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    curve_func14
   
   Library: KioskDefault 0 0 */

int curve_distanceToNearestOfType16(double param1,double param2,double param3,int param4) { //80127718
  float fVar1;
  float fVar2;
  float fVar3;
  ObjInstance **objs;
  ObjDef_RomCurve *curve;
  int iObj;
  ObjInstance *obj;
  double dVar4;
  double dPrev;
  double result;
  int nObjs;
  int iObj_unused;
  double local_48;
  
  _savefpr_26();
  objs = Object_getObjects(&iObj_unused,&nObjs);
  result = -1.0;
  dPrev = 0.0;
  for (iObj = 0; iObj < nObjs; iObj = iObj + 1) {
    obj = objs[iObj];
    if ((((obj->objId == 0x2e) && ((char)obj->mapId != param4)) &&
        (curve = (ObjDef_RomCurve *)obj->def, curve != (ObjDef_RomCurve *)0x0)) &&
       ((curve->type == 0x16 &&
        ((fVar1 = (obj->prevPos).x - (float)param1, fVar2 = (obj->prevPos).y - (float)param2,
         fVar3 = (obj->prevPos).z - (float)param3,
         dVar4 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2)), result == -1.0 ||
         (dVar4 < dPrev)))))) {
      local_48 = (double)CONCAT44(0x43300000,(curve->def).id);
      result = (double)(float)(local_48 - 4503599627370496.0);
      dPrev = dVar4;
    }
  }
  iObj = (int)result;
  local_48 = (double)(longlong)iObj;
  _restfpr_26();
  return iObj;
}


/* Library Function - Single Match
    curve_func15
   
   Library: KioskDefault 0 0 */

void curve_distFn15(double param1,double param2,double param3,uint param4,float *param5) { //80127844
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint param1_00;
  double dVar8;
  
  _savefpr_26();
  iVar4 = RomCurve_getById(param4);
  *param5 = 200000.0;
  uVar6 = param4;
  do {
    param1_00 = 0xffffffff;
    iVar7 = 0;
    while ((iVar7 < 4 && (param1_00 == 0xffffffff))) {
      if (((int)*(char *)(iVar4 + 0x1b) & 1 << iVar7) == 0) {
        param1_00 = *(uint *)(iVar4 + iVar7 * 4 + 0x1c);
      }
      iVar7 = iVar7 + 1;
    }
    iVar7 = iVar4;
    if (param1_00 != 0xffffffff) {
      iVar7 = RomCurve_getById(param1_00);
      iVar5 = FUN_80127980();
      uVar6 = param1_00;
      if ((iVar5 != 0) &&
         (fVar1 = (float)((double)*(float *)(iVar4 + 8) - param1),
         fVar2 = (float)((double)*(float *)(iVar4 + 0xc) - param2),
         fVar3 = (float)((double)*(float *)(iVar4 + 0x10) - param3),
         dVar8 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2)),
         dVar8 < (double)*param5)) {
        *param5 = (float)dVar8;
      }
    }
  } while ((uVar6 != param4) && (iVar4 = iVar7, param1_00 != 0xffffffff));
  _restfpr_26();
  return;
}


/* Library Function - Single Match
    curve_func21
   
   Library: KioskDefault 0 0 */

void curve_func21(double param1,double param2,double param3,int param4,float *param5,float *param6,
                  float *param7) { //80127A74
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  int local_7c [6];
  
  _savefpr_20();
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    iVar3 = RomCurve_getById(*(uint *)(param4 + iVar4 * 4));
    local_7c[iVar4] = iVar3;
  }
  dVar8 = (double)(*(float *)(local_7c[2] + 8) - *(float *)(local_7c[1] + 8));
  dVar6 = (double)(*(float *)(local_7c[2] + 0x10) - *(float *)(local_7c[1] + 0x10));
  dVar5 = dVar6;
  dVar10 = dVar8;
  if (local_7c[0] != 0) {
    dVar5 = (double)(*(float *)(local_7c[1] + 0x10) - *(float *)(local_7c[0] + 0x10));
    dVar10 = (double)(*(float *)(local_7c[1] + 8) - *(float *)(local_7c[0] + 8));
  }
  dVar11 = (double)((float)(dVar10 + dVar8) * 0.5);
  dVar10 = (double)((float)(dVar5 + dVar6) * 0.5);
  dVar5 = sqrt((double)(float)(dVar11 * dVar11 + (double)(float)(dVar10 * dVar10)));
  if (dVar5 != 0.0) {
    dVar11 = (double)(float)(dVar11 / dVar5);
    dVar10 = (double)(float)(dVar10 / dVar5);
  }
  fVar1 = (float)dVar11;
  fVar2 = (float)dVar10;
  dVar5 = (double)(float)((double)fVar1 * dVar8 + (double)(float)((double)fVar2 * dVar6));
  if (dVar5 != 0.0) {
    dVar5 = (double)(float)(-(double)(-(fVar1 * *(float *)(local_7c[1] + 8) +
                                       fVar2 * *(float *)(local_7c[1] + 0x10)) +
                                     (float)((double)fVar1 * param1 +
                                            (double)(float)((double)fVar2 * param3))) / dVar5);
  }
  dVar9 = (double)(*(float *)(local_7c[2] + 8) - *(float *)(local_7c[1] + 8));
  dVar7 = (double)(*(float *)(local_7c[2] + 0x10) - *(float *)(local_7c[1] + 0x10));
  dVar10 = dVar7;
  dVar11 = dVar9;
  if (local_7c[3] != 0) {
    dVar10 = (double)(*(float *)(local_7c[3] + 0x10) - *(float *)(local_7c[2] + 0x10));
    dVar11 = (double)(*(float *)(local_7c[3] + 8) - *(float *)(local_7c[2] + 8));
  }
  dVar12 = (double)((float)(dVar11 + dVar9) * 0.5);
  dVar11 = (double)((float)(dVar10 + dVar7) * 0.5);
  dVar10 = sqrt((double)(float)(dVar12 * dVar12 + (double)(float)(dVar11 * dVar11)));
  if (dVar10 != 0.0) {
    dVar12 = (double)(float)(dVar12 / dVar10);
    dVar11 = (double)(float)(dVar11 / dVar10);
  }
  fVar1 = (float)dVar12;
  fVar2 = (float)dVar11;
  dVar10 = (double)(float)((double)fVar1 * dVar8 + (double)(float)((double)fVar2 * dVar6));
  if (dVar10 != 0.0) {
    dVar10 = (double)(float)(-(double)(-(fVar1 * *(float *)(local_7c[2] + 8) +
                                        fVar2 * *(float *)(local_7c[2] + 0x10)) +
                                      (float)((double)fVar1 * param1 +
                                             (double)(float)((double)fVar2 * param3))) / dVar10);
  }
  dVar5 = (double)(float)(-dVar5 / (double)(float)(dVar10 - dVar5));
  if ((0.0 <= dVar5) && (dVar5 < 1.0)) {
    dVar11 = (double)(*(float *)(local_7c[2] + 0xc) - *(float *)(local_7c[1] + 0xc));
    dVar10 = sqrt((double)(float)(dVar7 * dVar7 +
                                 (double)(float)(dVar9 * dVar9 + (double)(float)(dVar11 * dVar11))))
    ;
    if (0.0 < dVar10) {
      dVar8 = (double)(float)(-dVar9 * (double)(float)(1.0 / dVar10));
      dVar6 = (double)(float)(-dVar7 * (double)(float)(1.0 / dVar10));
    }
    fVar1 = *(float *)(local_7c[1] + 0xc);
    *param5 = -(float)((double)(float)(dVar9 * dVar5 + (double)*(float *)(local_7c[1] + 8)) * dVar6
                      - (double)(float)((double)(float)(dVar7 * dVar5 +
                                                       (double)*(float *)(local_7c[1] + 0x10)) *
                                       dVar8)) +
              (float)(param1 * dVar6 - (double)(float)(param3 * dVar8));
    *param6 = (float)param2 - (float)(dVar11 * dVar5 + (double)fVar1);
    *param7 = (float)dVar5;
  }
  _restfpr_20();
  return;
}


/* Library Function - Single Match
    curve_func22
   
   Library: KioskDefault 0 0 */

int curve_func22(double param1,double param2,double param3,int param4,float *param5) { //80127DEC
  uint param1_00;
  int iVar1;
  undefined4 auStack_24 [4];
  float local_14;
  float local_10;
  float local_c;
  
  while( true ) {
    iVar1 = isNotPoint(param4);
    if (iVar1 != 0) {
      *param5 = 0.0;
      return (int)(ObjDef_RomCurve *)param4;
    }
    getIds_1D(param4,auStack_24);
    iVar1 = func21((double)(float)param1,(double)(float)param2,(double)(float)param3,(int)auStack_24
                   ,&local_c,&local_10,&local_14);
    if ((((iVar1 != 0) && (-300.0 < local_c)) && (local_c < 300.0)) &&
       ((-100.0 < local_10 && (local_10 < 100.0)))) break;
    param1_00 = getRandomPoint((ObjDef_RomCurve *)param4,0);
    param4 = RomCurve_getById(param1_00);
  }
  *param5 = local_14;
  return (int)(ObjDef_RomCurve *)param4;
}


/* Library Function - Single Match
    curve_func23
   
   Library: KioskDefault 0 0 */

void curve_getPos(double scale,ObjDef_RomCurve *this,float *outX,float *outY,float *outZ) { //80127EDC
  uint param1;
  ObjDef_RomCurve *that;
  float thatY;
  float thatZ;
  float thisY;
  float thisZ;
  
  _savefpr_28();
  param1 = getRandomPoint(this,0);
  that = (ObjDef_RomCurve *)RomCurve_getById(param1);
  if (that == (ObjDef_RomCurve *)0x0) {
    *outX = (this->def).pos.x;
    *outY = (this->def).pos.y;
    *outZ = (this->def).pos.z;
  }
  else {
    thatY = (that->def).pos.y;
    thisY = (this->def).pos.y;
    thatZ = (that->def).pos.z;
    thisZ = (this->def).pos.z;
    *outX = (float)((double)((that->def).pos.x - (this->def).pos.x) * scale +
                   (double)(this->def).pos.x);
    *outY = (float)((double)(thatY - thisY) * scale + (double)(this->def).pos.y);
    *outZ = (float)((double)(thatZ - thisZ) * scale + (double)(this->def).pos.z);
  }
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    curve_func24
   
   Library: KioskDefault 0 0 */

void curve_func24(int param1,int param2,float *param3,float *param4) { //80127FA4
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  ObjDef_RomCurve *pOVar7;
  uint uVar8;
  ObjDef_RomCurve *curve;
  ObjDef_RomCurve *pOVar9;
  float *pfVar10;
  
  _savefpr_28();
  if (param1 == param2) {
    sqrt((double)((param4[2] - param3[2]) * (param4[2] - param3[2]) +
                 (*param4 - *param3) * (*param4 - *param3) +
                 (param4[1] - param3[1]) * (param4[1] - param3[1])));
  }
  else {
    bVar5 = false;
    bVar4 = false;
    pOVar7 = (ObjDef_RomCurve *)param1;
    while (!bVar4) {
      iVar6 = isNotPoint((int)pOVar7);
      if (iVar6 == 0) {
        uVar8 = getRandomPoint(pOVar7,0);
        pOVar7 = (ObjDef_RomCurve *)RomCurve_getById(uVar8);
        if (pOVar7 == (ObjDef_RomCurve *)param2) {
          bVar4 = true;
          bVar5 = true;
        }
      }
      else {
        bVar4 = true;
        bVar5 = false;
      }
    }
    pOVar7 = (ObjDef_RomCurve *)param2;
    pfVar10 = param3;
    if (!bVar5) {
      pOVar7 = (ObjDef_RomCurve *)param1;
      pfVar10 = param4;
      param4 = param3;
      param1 = param2;
    }
    uVar8 = getRandomPoint((ObjDef_RomCurve *)param1,0);
    curve = (ObjDef_RomCurve *)RomCurve_getById(uVar8);
    fVar1 = (curve->def).pos.x - *pfVar10;
    fVar2 = (curve->def).pos.y - pfVar10[1];
    fVar3 = (curve->def).pos.z - pfVar10[2];
    sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
    bVar4 = false;
    while (!bVar4) {
      if (curve == pOVar7) {
        bVar4 = true;
        fVar1 = *param4 - (curve->def).pos.x;
        fVar2 = param4[1] - (curve->def).pos.y;
        fVar3 = param4[2] - (curve->def).pos.z;
        sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
      }
      else {
        uVar8 = getRandomPoint(curve,0);
        pOVar9 = (ObjDef_RomCurve *)RomCurve_getById(uVar8);
        fVar1 = (pOVar9->def).pos.x - (curve->def).pos.x;
        fVar2 = (pOVar9->def).pos.y - (curve->def).pos.y;
        fVar3 = (pOVar9->def).pos.z - (curve->def).pos.z;
        sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
        curve = pOVar9;
      }
    }
  }
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    curve_func16
   
   Library: KioskDefault 0 0 */

uint curve_func16(double param1,double param2,double param3) { //801281C4
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_64;
  uint local_60 [20];
  
  iVar3 = 0;
  iVar4 = 0;
  while ((iVar4 < nRomCurves && (iVar3 < 0x14))) {
    if (*(char *)((&romCurves)[iVar4] + 0x19) == '\x17') {
      local_60[iVar3] = *(uint *)((&romCurves)[iVar4] + 0x14);
      iVar3 = iVar3 + 1;
    }
    iVar4 = iVar4 + 1;
  }
  while( true ) {
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    iVar4 = distFn15((double)(float)param1,(double)(float)param2,(double)(float)param3,local_60[0],
                     &local_64);
    if (iVar4 != 0) break;
    iVar4 = RomCurve_getById(local_60[0]);
    cVar1 = *(char *)(iVar4 + 0x18);
    iVar4 = 0;
    while (iVar4 < iVar3) {
      iVar2 = RomCurve_getById(local_60[iVar4]);
      if (*(char *)(iVar2 + 0x18) == cVar1) {
        iVar3 = iVar3 + -1;
        local_60[iVar4] = local_60[iVar3];
      }
      else {
        iVar4 = iVar4 + 1;
      }
    }
  }
  return local_60[0];
}


/* Library Function - Single Match
    curve_func1B
   
   Library: KioskDefault 0 0 */

void curve_func1B(double param1,double param2,double param3,int param4,int param5) { //801282F0
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58 [2];
  int local_50 [3];
  
  _savefpr_26();
  local_50[1] = 0xffffffff;
  local_50[0] = -1;
  local_58[1] = 5000000.0;
  local_58[0] = 5000000.0;
  local_7c = *(float *)(param4 + 8);
  local_78 = *(undefined4 *)(param4 + 0xc);
  local_74 = *(undefined4 *)(param4 + 0x10);
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    if ((-1 < *(int *)(param4 + iVar4 * 4 + 0x1c)) &&
       (iVar3 = RomCurve_getById(*(uint *)(param4 + iVar4 * 4 + 0x1c)), iVar3 != 0)) {
      uVar2 = countLeadingZeros(param5 - *(int *)(param4 + iVar4 * 4 + 0x1c));
      uVar2 = uVar2 >> 5;
      local_70 = *(undefined4 *)(iVar3 + 8);
      local_6c = *(undefined4 *)(iVar3 + 0xc);
      local_68 = *(undefined4 *)(iVar3 + 0x10);
      FUN_801248f8(param1,param2,param3,&local_7c);
      fVar1 = (float)((double)local_5c - param3) * (float)((double)local_5c - param3) +
              (float)((double)local_64 - param1) * (float)((double)local_64 - param1) +
              (float)((double)local_60 - param2) * (float)((double)local_60 - param2);
      if (fVar1 < local_58[uVar2]) {
        local_58[uVar2] = fVar1;
        local_50[uVar2] = *(int *)(param4 + iVar4 * 4 + 0x1c);
      }
    }
  }
  _restfpr_26();
  return;
}


/* Library Function - Single Match
    curve_func1C
   
   Library: KioskDefault 0 0 */

void curve_func1C(int param1,undefined4 param_2,undefined4 param_3,int *param4) { //80128484
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int param1_00;
  int iVar7;
  int iVar8;
  double dVar9;
  float local_6c8 [40];
  int local_628 [40];
  char local_588 [1300];
  float local_74 [4];
  int local_64;
  int local_60;
  int local_5c [6];
  
  _savefpr_30();
  if (param1 != 0) {
    printf("Search");
    FUN_801256b8(*(uint *)(param1 + 0x14),&local_64);
    param1_00 = 0;
    for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
      if (-1 < *(int *)(param1 + iVar6 * 4 + 0x1c)) {
        printf("link:(%d) %d",iVar6,*(int *)(param1 + iVar6 * 4 + 0x1c));
        for (iVar8 = 0; iVar8 < 0x514; iVar8 = iVar8 + 1) {
          local_588[iVar8] = '\0';
        }
        local_588[local_64] = '\x01';
        iVar8 = FUN_801256b8(*(uint *)(param1 + iVar6 * 4 + 0x1c),&local_60);
        local_6c8[0] = (*(float *)(iVar8 + 0x10) - *(float *)(param1 + 0x10)) *
                       (*(float *)(iVar8 + 0x10) - *(float *)(param1 + 0x10)) +
                       (*(float *)(iVar8 + 8) - *(float *)(param1 + 8)) *
                       (*(float *)(iVar8 + 8) - *(float *)(param1 + 8)) +
                       (*(float *)(iVar8 + 0xc) - *(float *)(param1 + 0xc)) *
                       (*(float *)(iVar8 + 0xc) - *(float *)(param1 + 0xc));
        local_628[0] = local_60;
        iVar8 = 1;
        local_588[local_60] = '\x01';
        bVar2 = false;
        do {
          if (iVar8 < 1) {
            bVar2 = true;
          }
          else {
            iVar8 = iVar8 + -1;
            local_60 = local_628[iVar8];
            iVar7 = (&romCurves)[local_628[iVar8]];
            dVar9 = (double)local_6c8[iVar8];
            if (*(char *)(iVar7 + 0x34) == '\x01') {
              bVar2 = true;
              *(float *)(local_588 + param1_00 * 4 + 0x514) = local_6c8[iVar8];
              local_5c[param1_00] = *(int *)(param1 + iVar6 * 4 + 0x1c);
              param1_00 = param1_00 + 1;
              printf("Found: %d",*(int *)(iVar7 + 0x14));
            }
            else {
              for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
                if ((((-1 < *(int *)(iVar7 + iVar4 * 4 + 0x1c)) &&
                     (iVar3 = FUN_801256b8(*(uint *)(iVar7 + iVar4 * 4 + 0x1c),&local_60),
                     iVar3 != 0)) && (local_588[local_60] == '\0')) && (iVar8 < 0x28)) {
                  fVar1 = (*(float *)(iVar7 + 0x10) - *(float *)(iVar3 + 0x10)) *
                          (*(float *)(iVar7 + 0x10) - *(float *)(iVar3 + 0x10)) +
                          (*(float *)(iVar7 + 0xc) - *(float *)(iVar3 + 0xc)) *
                          (*(float *)(iVar7 + 0xc) - *(float *)(iVar3 + 0xc)) +
                          (float)((double)(*(float *)(iVar7 + 8) - *(float *)(iVar3 + 8)) *
                                  (double)(*(float *)(iVar7 + 8) - *(float *)(iVar3 + 8)) + dVar9);
                  for (iVar3 = 0; (iVar5 = iVar8, iVar3 < iVar8 && (fVar1 < local_6c8[iVar3]));
                      iVar3 = iVar3 + 1) {
                  }
                  for (; iVar3 < iVar5; iVar5 = iVar5 + -1) {
                    local_628[iVar5] = local_628[iVar5 + -1];
                    local_6c8[iVar5] = local_6c8[iVar5 + -1];
                  }
                  iVar8 = iVar8 + 1;
                  local_6c8[iVar3] = fVar1;
                  local_628[iVar3] = local_60;
                  local_588[local_60] = '\x01';
                }
              }
            }
          }
        } while (!bVar2);
      }
    }
    printf("%d",param1_00);
    if (param1_00 != 0) {
      if (param1_00 == 1) {
        *param4 = *(int *)(param1 + 0x14);
      }
      else if (1 < param1_00) {
        for (iVar6 = 0; iVar6 < param1_00; iVar6 = iVar6 + 1) {
          if (*param4 == local_5c[iVar6]) {
            for (; iVar6 < param1_00 + -1; iVar6 = iVar6 + 1) {
              local_5c[iVar6] = local_5c[iVar6 + 1];
              *(undefined4 *)(local_588 + iVar6 * 4 + 0x514) =
                   *(undefined4 *)(local_588 + (iVar6 + 1) * 4 + 0x514);
            }
            param1_00 = param1_00 + -1;
          }
        }
        *param4 = *(int *)(param1 + 0x14);
        iVar6 = 0;
        for (iVar8 = 0; iVar8 < param1_00; iVar8 = iVar8 + 1) {
          if (*(float *)(local_588 + iVar8 * 4 + 0x514) < *(float *)(local_588 + iVar6 * 4 + 0x514))
          {
            iVar6 = iVar8;
          }
        }
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    curve_func08
   
   Library: KioskDefault 0 0 */

void curve_findNearObj(ObjInstance *param1,int param2,int param3,int param4,byte param5) { //8012891C
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  ObjInstance *apOStack_c4 [21];
  char local_70 [4];
  vec3f local_6c;
  vec3s vStack_60;
  vec3s avStack_58 [2];
  
  _savefpr_27();
  dVar10 = 5000000.0;
  local_6c.x = (param1->pos).pos.x;
  local_6c.y = (param1->pos).pos.y + 10.0;
  local_6c.z = (param1->pos).pos.z;
  dVar11 = dVar10;
  vec3f_toNearest10(&local_6c,&vStack_60);
  for (iVar6 = 0; iVar6 < nRomCurves; iVar6 = iVar6 + 1) {
    iVar8 = (&romCurves)[iVar6];
    iVar7 = 0;
    do {
      if (((int)*(char *)(iVar8 + 0x19) == *(int *)(param2 + iVar7 * 4)) || (param3 < 1)) {
        fVar1 = *(float *)(iVar8 + 8) - (param1->pos).pos.x;
        fVar2 = *(float *)(iVar8 + 0xc) - (param1->pos).pos.y;
        fVar3 = *(float *)(iVar8 + 0x10) - (param1->pos).pos.z;
        dVar9 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
        if (dVar9 < dVar11) {
          local_6c.x = *(float *)(iVar8 + 8);
          local_6c.y = *(float *)(iVar8 + 0xc) + 10.0;
          local_6c.z = *(float *)(iVar8 + 0x10);
          vec3f_toNearest10(&local_6c,avStack_58);
          uVar4 = FUN_8006dd10((undefined4 *)avStack_58,(undefined4 *)&vStack_60,(undefined4 *)0x0,
                               local_70,'\0');
          if (((local_70[0] == '\x01') || ((uVar4 & 0xff) != 0)) &&
             (iVar7 = FUN_800bb7e0(1.0,&(param1->pos).pos.x,&local_6c.x,0,apOStack_c4,param1,param5,
                                   -1,0,'\0'), iVar7 == 0)) {
            dVar11 = dVar9;
          }
        }
        iVar7 = param3;
        if ((*(char *)(iVar8 + 0x18) == param4) && (dVar9 < dVar10)) {
          local_6c.x = *(float *)(iVar8 + 8);
          local_6c.y = *(float *)(iVar8 + 0xc) + 10.0;
          local_6c.z = *(float *)(iVar8 + 0x10);
          vec3f_toNearest10(&local_6c,avStack_58);
          uVar4 = FUN_8006dd10((undefined4 *)avStack_58,(undefined4 *)&vStack_60,(undefined4 *)0x0,
                               local_70,'\0');
          if (((local_70[0] == '\x01') || ((uVar4 & 0xff) != 0)) &&
             (iVar5 = FUN_800bb7e0(1.0,&(param1->pos).pos.x,&local_6c.x,0,apOStack_c4,param1,param5,
                                   -1,0,'\0'), iVar5 == 0)) {
            dVar10 = dVar9;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param3);
  }
  _restfpr_27();
  return;
}


/* Library Function - Single Match
    curve_func25
   
   Library: KioskDefault 0 0 */

void curve_func25(double param1,float *param2,ObjInstance *param3,int param4,int param5) { //80128BB8
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  double dVar5;
  
  _savefpr_29();
  if (((Curve *)param2 != (Curve *)0x0) &&
     (uVar3 = findNearObj(param3,param4,1,param5,0xc), uVar3 != 0xffffffff)) {
    if (*(float *)((int)param2 + 0x80) != 0.0) {
      fVar4 = (float)RomCurve_getById(uVar3);
      ((Curve *)((int)param2 + 0x9c))->field1_0x4 = fVar4;
      uVar3 = getRandomPoint((ObjDef_RomCurve *)((Curve *)((int)param2 + 0x9c))->field1_0x4,-1);
      if (uVar3 == 0xffffffff) goto LAB_801290b8;
    }
    fVar4 = (float)RomCurve_getById(uVar3);
    ((Curve *)((int)param2 + 0x9c))->field1_0x4 = fVar4;
    if (fVar4 == 0.0) {
      ((Curve *)((int)param2 + 0x9c))->field1_0x4 = 0.0;
    }
    else {
      if (*(float *)((int)param2 + 0x80) == 0.0) {
        uVar3 = getRandomPoint((ObjDef_RomCurve *)((Curve *)((int)param2 + 0x9c))->field1_0x4,-1);
      }
      else {
        uVar3 = getRandomPoint1A((int)((Curve *)((int)param2 + 0x9c))->field1_0x4,-1);
      }
      if (uVar3 != 0xffffffff) {
        fVar4 = (float)RomCurve_getById(uVar3);
        ((Curve *)((int)param2 + 0x9c))->field2_0x8 = fVar4;
        if (fVar4 == 0.0) {
          ((Curve *)((int)param2 + 0x9c))->field2_0x8 = 0.0;
        }
        else {
          if (*(float *)((int)param2 + 0x80) == 0.0) {
            fVar4 = *(float *)((int)((Curve *)((int)param2 + 0x9c))->field1_0x4 + 8) -
                    (param3->pos).pos.x;
            fVar1 = *(float *)((int)((Curve *)((int)param2 + 0x9c))->field1_0x4 + 0xc) -
                    (param3->pos).pos.y;
            fVar2 = *(float *)((int)((Curve *)((int)param2 + 0x9c))->field1_0x4 + 0x10) -
                    (param3->pos).pos.z;
          }
          else {
            fVar4 = *(float *)((int)((Curve *)((int)param2 + 0x9c))->field2_0x8 + 8) -
                    (param3->pos).pos.x;
            fVar1 = *(float *)((int)((Curve *)((int)param2 + 0x9c))->field2_0x8 + 0xc) -
                    (param3->pos).pos.y;
            fVar2 = *(float *)((int)((Curve *)((int)param2 + 0x9c))->field2_0x8 + 0x10) -
                    (param3->pos).pos.z;
          }
          dVar5 = sqrt((double)(fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1));
          if (dVar5 <= (double)(float)param1) {
            *(undefined4 *)&((Curve *)((int)param2 + 0x9c))->field_0x1c =
                 *(undefined4 *)((int)((Curve *)((int)param2 + 0x9c))->field1_0x4 + 8);
            *(undefined4 *)&((Curve *)((int)param2 + 0x9c))->field_0x20 =
                 *(undefined4 *)((int)((Curve *)((int)param2 + 0x9c))->field2_0x8 + 8);
            dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                   (int)*(char *)((
                                                  int)((Curve *)((int)param2 + 0x9c))->field1_0x4 +
                                                  0x2c) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
            *(float *)&((Curve *)((int)param2 + 0x9c))->field_0x24 =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          (uint)*(byte *)((int)((Curve *)
                                                                               ((int)param2 + 0x9c))
                                                                               ->field1_0x4 + 0x2e))
                                        - 4503599627370496.0) * dVar5) * 2.0;
            dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                   (int)*(char *)((
                                                  int)((Curve *)((int)param2 + 0x9c))->field2_0x8 +
                                                  0x2c) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
            *(float *)&((Curve *)((int)param2 + 0x9c))->field_0x28 =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          (uint)*(byte *)((int)((Curve *)
                                                                               ((int)param2 + 0x9c))
                                                                               ->field2_0x8 + 0x2e))
                                        - 4503599627370496.0) * dVar5) * 2.0;
            *(undefined4 *)&((Curve *)((int)param2 + 0x9c))->field_0x3c =
                 *(undefined4 *)((int)((Curve *)((int)param2 + 0x9c))->field1_0x4 + 0xc);
            *(undefined4 *)&((Curve *)((int)param2 + 0x9c))->field_0x40 =
                 *(undefined4 *)((int)((Curve *)((int)param2 + 0x9c))->field2_0x8 + 0xc);
            dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                   (int)*(char *)((
                                                  int)((Curve *)((int)param2 + 0x9c))->field1_0x4 +
                                                  0x2d) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
            *(float *)&((Curve *)((int)param2 + 0x9c))->field_0x44 =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          (uint)*(byte *)((int)((Curve *)
                                                                               ((int)param2 + 0x9c))
                                                                               ->field1_0x4 + 0x2e))
                                        - 4503599627370496.0) * dVar5) * 2.0;
            dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                   (int)*(char *)((
                                                  int)((Curve *)((int)param2 + 0x9c))->field2_0x8 +
                                                  0x2d) << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
            *(float *)&((Curve *)((int)param2 + 0x9c))->field_0x48 =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          (uint)*(byte *)((int)((Curve *)
                                                                               ((int)param2 + 0x9c))
                                                                               ->field2_0x8 + 0x2e))
                                        - 4503599627370496.0) * dVar5) * 2.0;
            *(undefined4 *)&((Curve *)((int)param2 + 0x9c))->field_0x5c =
                 *(undefined4 *)((int)((Curve *)((int)param2 + 0x9c))->field1_0x4 + 0x10);
            *(undefined4 *)&((Curve *)((int)param2 + 0x9c))->field_0x60 =
                 *(undefined4 *)((int)((Curve *)((int)param2 + 0x9c))->field2_0x8 + 0x10);
            dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)*(char *)((int)(
                                                  (Curve *)((int)param2 + 0x9c))->field1_0x4 + 0x2c)
                                                  << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
            ((Curve *)((int)param2 + 0x9c))->field82_0x64 =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          (uint)*(byte *)((int)((Curve *)
                                                                               ((int)param2 + 0x9c))
                                                                               ->field1_0x4 + 0x2e))
                                        - 4503599627370496.0) * dVar5) * 2.0;
            dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                               (int)*(char *)((int)(
                                                  (Curve *)((int)param2 + 0x9c))->field2_0x8 + 0x2c)
                                                  << 8 ^ 0x80000000) - 4503601774854144.0) *
                                                  3.141593) / 32767.0));
            ((Curve *)((int)param2 + 0x9c))->field83_0x68 =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          (uint)*(byte *)((int)((Curve *)
                                                                               ((int)param2 + 0x9c))
                                                                               ->field2_0x8 + 0x2e))
                                        - 4503599627370496.0) * dVar5) * 2.0;
            uVar3 = func26(param2);
            if ((uVar3 & 0xff) == 0) {
              *(code **)((int)param2 + 0x94) = FUN_8006bba0;
              *(code **)((int)param2 + 0x98) = curveFn_80010d54;
              *(float **)((int)param2 + 0x84) = &((Curve *)((int)param2 + 0x9c))->field3_0xc;
              *(undefined **)((int)param2 + 0x88) = &((Curve *)((int)param2 + 0x9c))->field_0x2c;
              *(undefined **)((int)param2 + 0x8c) = &((Curve *)((int)param2 + 0x9c))->field_0x4c;
              *(float *)((int)param2 + 0x90) = 1.121039e-44;
              curvesMove((Curve *)param2);
            }
          }
        }
      }
    }
  }
LAB_801290b8:
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    curve_func26
   
   Library: KioskDefault 0 0 */

undefined4 curve_func26(float *param1) { //801290D4
  uint param1_00;
  float fVar1;
  double dVar2;
  
  if (((param1 != (float *)0x0) && (param1[0x28] != 0.0)) && (param1[0x29] != 0.0)) {
    param1[0x27] = param1[0x28];
    param1[0x28] = param1[0x29];
    memcpy(param1 + 0x2a,param1 + 0x2e,0x10);
    memcpy(param1 + 0x32,param1 + 0x36,0x10);
    memcpy(param1 + 0x3a,param1 + 0x3e,0x10);
    if (param1[0x20] == 0.0) {
      param1_00 = getRandomPoint((ObjDef_RomCurve *)param1[0x28],-1);
    }
    else {
      param1_00 = getRandomPoint1A((int)param1[0x28],-1);
    }
    if (param1_00 == 0xffffffff) {
      param1[0x29] = 0.0;
    }
    else {
      fVar1 = (float)RomCurve_getById(param1_00);
      param1[0x29] = fVar1;
      if (param1[0x29] != 0.0) {
        if (param1[0x20] == 0.0) {
          param1[0x2e] = *(float *)((int)param1[0x28] + 8);
          param1[0x2f] = *(float *)((int)param1[0x29] + 8);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x30] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x31] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x36] = *(float *)((int)param1[0x28] + 0xc);
          param1[0x37] = *(float *)((int)param1[0x29] + 0xc);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x38] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x29] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x39] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x3e] = *(float *)((int)param1[0x28] + 0x10);
          param1[0x3f] = *(float *)((int)param1[0x29] + 0x10);
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x40] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x41] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
        }
        else {
          param1[0x2e] = *(float *)((int)param1[0x28] + 8);
          param1[0x2f] = *(float *)((int)param1[0x27] + 8);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x30] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x27] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x31] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x27]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x36] = *(float *)((int)param1[0x28] + 0xc);
          param1[0x37] = *(float *)((int)param1[0x27] + 0xc);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x38] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x27] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x39] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x27]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x3e] = *(float *)((int)param1[0x28] + 0x10);
          param1[0x3f] = *(float *)((int)param1[0x27] + 0x10);
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x40] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x27] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x41] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x27]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
        }
        if (param1[0x24] != 0.0) {
          curvesMoveSetupNetworkCurve((int)param1);
        }
        if (param1[0x20] == 0.0) {
          FUN_8006c2c8(1.0,param1);
        }
        else {
          FUN_8006c2c8(-1.0,param1);
        }
        return 0;
      }
    }
  }
  return 1;
}


/* Library Function - Single Match
    curve_func27
   
   Library: KioskDefault 0 0 */

undefined4 RomCurve_setClosed(float *param1,float param2) { //801297EC
  undefined4 uVar1;
  uint uVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  if (param2 == param1[0x20]) {
    uVar1 = 0;
  }
  else if ((param1[0x28] == 0.0) || (param1[0x27] == 0.0)) {
    uVar1 = 1;
  }
  else {
    dVar5 = (double)*param1;
    param1[0x20] = param2;
    fVar3 = param1[0x27];
    param1[0x27] = param1[0x29];
    param1[0x29] = fVar3;
    param1[0x2e] = *(float *)((int)param1[0x28] + 8);
    param1[0x2f] = *(float *)((int)param1[0x29] + 8);
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)((int)
                                                  param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    param1[0x30] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)((int)param1[0x28] + 0x2e
                                                                           )) - 4503599627370496.0)
                          * dVar4) * 2.0;
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)((int)
                                                  param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    param1[0x31] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)((int)param1[0x29] + 0x2e
                                                                           )) - 4503599627370496.0)
                          * dVar4) * 2.0;
    param1[0x36] = *(float *)((int)param1[0x28] + 0xc);
    param1[0x37] = *(float *)((int)param1[0x29] + 0xc);
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)((int)
                                                  param1[0x28] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    param1[0x38] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)((int)param1[0x28] + 0x2e
                                                                           )) - 4503599627370496.0)
                          * dVar4) * 2.0;
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)((int)
                                                  param1[0x29] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    param1[0x39] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)((int)param1[0x29] + 0x2e
                                                                           )) - 4503599627370496.0)
                          * dVar4) * 2.0;
    param1[0x3e] = *(float *)((int)param1[0x28] + 0x10);
    param1[0x3f] = *(float *)((int)param1[0x29] + 0x10);
    dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)*(char *)((int)param1[
                                                  0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    param1[0x40] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)((int)param1[0x28] + 0x2e
                                                                           )) - 4503599627370496.0)
                          * dVar4) * 2.0;
    dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)*(char *)((int)param1[
                                                  0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    param1[0x41] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)((int)param1[0x29] + 0x2e
                                                                           )) - 4503599627370496.0)
                          * dVar4) * 2.0;
    uVar2 = curve_func26(param1);
    if ((uVar2 & 0xff) == 0) {
      param1[0x25] = (float)FUN_8006bba0;
      param1[0x26] = (float)curveFn_80010d54;
      param1[0x21] = (float)(param1 + 0x2a);
      param1[0x22] = (float)(param1 + 0x32);
      param1[0x23] = (float)(param1 + 0x3a);
      param1[0x24] = 1.121039e-44;
      curvesMove((Curve *)param1);
      *param1 = (float)dVar5;
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* Library Function - Single Match
    curve_func28
   
   Library: KioskDefault 0 0 */

void RomCurve_setA4(int param1,int param2) { //80129BB4
  double dVar1;
  
  if ((param2 != 0) && (param2 != *(int *)(param1 + 0xa4))) {
    *(int *)(param1 + 0xa4) = param2;
    *(undefined4 *)(param1 + 0xbc) = *(undefined4 *)(*(int *)(param1 + 0xa4) + 8);
    dVar1 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)(*(int *)(
                                                  param1 + 0xa4) + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    *(float *)(param1 + 0xc4) =
         (float)((double)(float)((double)CONCAT44(0x43300000,
                                                  (uint)*(byte *)(*(int *)(param1 + 0xa4) + 0x2e)) -
                                4503599627370496.0) * dVar1) * 2.0;
    *(undefined4 *)(param1 + 0xdc) = *(undefined4 *)(*(int *)(param1 + 0xa4) + 0xc);
    dVar1 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*(char *)(*(int *)(
                                                  param1 + 0xa4) + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    *(float *)(param1 + 0xe4) =
         (float)((double)(float)((double)CONCAT44(0x43300000,
                                                  (uint)*(byte *)(*(int *)(param1 + 0xa4) + 0x2e)) -
                                4503599627370496.0) * dVar1) * 2.0;
    *(undefined4 *)(param1 + 0xfc) = *(undefined4 *)(*(int *)(param1 + 0xa4) + 0x10);
    dVar1 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)*(char *)(*(int *)(
                                                  param1 + 0xa4) + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
    *(float *)(param1 + 0x104) =
         (float)((double)(float)((double)CONCAT44(0x43300000,
                                                  (uint)*(byte *)(*(int *)(param1 + 0xa4) + 0x2e)) -
                                4503599627370496.0) * dVar1) * 2.0;
  }
  return;
}


/* Library Function - Single Match
    curve_func29
   
   Library: KioskDefault 0 0 */

undefined4 curve_func29(float *param1,int param2) { //80129D6C
  uint param1_00;
  float fVar1;
  double dVar2;
  
  if (((param1 != (float *)0x0) && (param1[0x28] != 0.0)) && (param1[0x29] != 0.0)) {
    param1[0x27] = param1[0x28];
    param1[0x28] = param1[0x29];
    memcpy(param1 + 0x2a,param1 + 0x2e,0x10);
    memcpy(param1 + 0x32,param1 + 0x36,0x10);
    memcpy(param1 + 0x3a,param1 + 0x3e,0x10);
    if (param1[0x20] == 0.0) {
      param1_00 = func2A((int)param1[0x28],-1,param2);
    }
    else {
      param1_00 = func2B((int)param1[0x28],-1,param2);
    }
    if (param1_00 == 0xffffffff) {
      param1[0x29] = 0.0;
    }
    else {
      fVar1 = (float)RomCurve_getById(param1_00);
      param1[0x29] = fVar1;
      if (param1[0x29] != 0.0) {
        if (param1[0x20] == 0.0) {
          param1[0x2e] = *(float *)((int)param1[0x28] + 8);
          param1[0x2f] = *(float *)((int)param1[0x29] + 8);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x30] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x31] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x36] = *(float *)((int)param1[0x28] + 0xc);
          param1[0x37] = *(float *)((int)param1[0x29] + 0xc);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x38] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x29] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x39] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x3e] = *(float *)((int)param1[0x28] + 0x10);
          param1[0x3f] = *(float *)((int)param1[0x29] + 0x10);
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x40] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x41] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
        }
        else {
          param1[0x2e] = *(float *)((int)param1[0x28] + 8);
          param1[0x2f] = *(float *)((int)param1[0x27] + 8);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x30] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x27] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x31] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x27]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x36] = *(float *)((int)param1[0x28] + 0xc);
          param1[0x37] = *(float *)((int)param1[0x27] + 0xc);
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x38] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x27] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x39] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x27]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          param1[0x3e] = *(float *)((int)param1[0x28] + 0x10);
          param1[0x3f] = *(float *)((int)param1[0x27] + 0x10);
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x40] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
          dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x27] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x41] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x27]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar2) * 2.0;
        }
        if (param1[0x24] != 0.0) {
          curvesMoveSetupNetworkCurve((int)param1);
        }
        if (param1[0x20] == 0.0) {
          FUN_8006c2c8(1.0,param1);
        }
        else {
          FUN_8006c2c8(-1.0,param1);
        }
        return 0;
      }
    }
  }
  return 1;
}


/* Library Function - Single Match
    curve_func2A
   
   Library: KioskDefault 0 0 */

int curve_func2A(int param1,int param2,int param3) { //8012A490
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_2c [6];
  
  iVar2 = 0;
  uVar1 = 1;
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (((-1 < *(int *)(param1 + iVar3 * 4 + 0x1c)) &&
        (((int)*(char *)(param1 + 0x1b) & uVar1) == 0)) &&
       (*(int *)(param1 + iVar3 * 4 + 0x1c) != param2)) {
      local_2c[iVar2] = *(int *)(param1 + iVar3 * 4 + 0x1c);
      iVar2 = iVar2 + 1;
    }
    uVar1 = uVar1 << 1;
  }
  if (iVar2 == 0) {
    iVar2 = -1;
  }
  else {
    if (param3 != -1) {
      printf(" list Branch No %i ",local_2c[param3]);
    }
    if (iVar2 + -1 < param3) {
      param3 = iVar2 + -1;
    }
    if (param3 == -1) {
      param3 = randInt(0,iVar2 + -1);
    }
    iVar2 = local_2c[param3];
  }
  return iVar2;
}


/* Library Function - Single Match
    curve_func2B
   
   Library: KioskDefault 0 0 */

int curve_func2B(int param1,int param2,int param3) { //8012A5A0
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_2c [6];
  
  iVar3 = 0;
  uVar1 = 1;
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    if (((-1 < *(int *)(param1 + iVar2 * 4 + 0x1c)) &&
        (((int)*(char *)(param1 + 0x1b) & uVar1) != 0)) &&
       (*(int *)(param1 + iVar2 * 4 + 0x1c) != param2)) {
      local_2c[iVar3] = *(int *)(param1 + iVar2 * 4 + 0x1c);
      iVar3 = iVar3 + 1;
    }
    uVar1 = uVar1 << 1;
  }
  if (iVar3 == 0) {
    iVar2 = -1;
  }
  else {
    if (param3 != -1) {
      printf(" list Branch %i Max %i Branch No %i ",param3,iVar3 + -1,local_2c[param3]);
    }
    if (iVar3 + -1 < param3) {
      param3 = iVar3 + -1;
    }
    if (param3 == -1) {
      param3 = randInt(0,iVar3 + -1);
    }
    iVar2 = local_2c[param3];
  }
  return iVar2;
}


/* Library Function - Single Match
    curve_func2C
   
   Library: KioskDefault 0 0 */

undefined4 curve_func2C(float *param1,undefined4 param_2,uint param3) { //8012A6B8
  undefined4 uVar1;
  float fVar2;
  uint uVar3;
  double dVar4;
  
  if (param1 == (float *)0x0) {
    uVar1 = 1;
  }
  else if (param3 == 0xffffffff) {
    uVar1 = 1;
  }
  else {
    if (param1[0x20] != 0.0) {
      fVar2 = (float)RomCurve_getById(param3);
      param1[0x28] = fVar2;
      param3 = getRandomPoint((ObjDef_RomCurve *)param1[0x28],-1);
      if (param3 == 0xffffffff) {
        return 1;
      }
    }
    fVar2 = (float)RomCurve_getById(param3);
    param1[0x28] = fVar2;
    if (fVar2 == 0.0) {
      param1[0x28] = 0.0;
      uVar1 = 1;
    }
    else {
      if (param1[0x20] == 0.0) {
        uVar3 = getRandomPoint((ObjDef_RomCurve *)param1[0x28],-1);
      }
      else {
        uVar3 = getRandomPoint1A((int)param1[0x28],-1);
      }
      if (uVar3 == 0xffffffff) {
        uVar1 = 1;
      }
      else {
        fVar2 = (float)RomCurve_getById(uVar3);
        param1[0x29] = fVar2;
        if (fVar2 == 0.0) {
          param1[0x29] = 0.0;
          uVar1 = 1;
        }
        else {
          param1[0x2e] = *(float *)((int)param1[0x28] + 8);
          param1[0x2f] = *(float *)((int)param1[0x29] + 8);
          dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x30] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar4) * 2.0;
          dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x31] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar4) * 2.0;
          param1[0x36] = *(float *)((int)param1[0x28] + 0xc);
          param1[0x37] = *(float *)((int)param1[0x29] + 0xc);
          dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x28] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x38] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar4) * 2.0;
          dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                 (int)*(char *)((int
                                                  )param1[0x29] + 0x2d) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x39] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar4) * 2.0;
          param1[0x3e] = *(float *)((int)param1[0x28] + 0x10);
          param1[0x3f] = *(float *)((int)param1[0x29] + 0x10);
          dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x28] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x40] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x28]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar4) * 2.0;
          dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)*(char *)((int)
                                                  param1[0x29] + 0x2c) << 8 ^ 0x80000000) -
                                                  4503601774854144.0) * 3.141593) / 32767.0));
          param1[0x41] = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)((int)param1[0x29]
                                                                                 + 0x2e)) -
                                                4503599627370496.0) * dVar4) * 2.0;
          uVar3 = func26(param1);
          if ((uVar3 & 0xff) == 0) {
            param1[0x25] = (float)FUN_8006bba0;
            param1[0x26] = (float)curveFn_80010d54;
            param1[0x21] = (float)(param1 + 0x2a);
            param1[0x22] = (float)(param1 + 0x32);
            param1[0x23] = (float)(param1 + 0x3a);
            param1[0x24] = 1.121039e-44;
            curvesMove((Curve *)param1);
            uVar1 = 0;
          }
          else {
            uVar1 = 1;
          }
        }
      }
    }
  }
  return uVar1;
}

