
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void baddieControl_func03(undefined4 param) { //80161DA8
  return;
}


/* @description Called when DLL is unloaded */

void baddieControl_func04(void) { //80161DAC
  return;
}


/* Library Function - Single Match
    baddieControl_func08
   
   Library: KioskDefault 0 0 */

uint baddieControl_func08(double param1,ObjInstance *param2,int param3) { //80161DB0
  int iVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  double dVar6;
  ObjInstance *apOStack_a4 [21];
  char local_50 [4];
  vec3f local_4c;
  vec3s vStack_40;
  vec3s vStack_38;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  uVar2 = 0;
  local_4c.x = (param2->pos).pos.x;
  local_4c.y = (param2->pos).pos.y + 10.0;
  local_4c.z = (param2->pos).pos.z;
  vec3f_toNearest10(&local_4c,&vStack_40);
  if (param2->pMatrix == (ObjInstance *)0x0) {
    sVar3 = (param2->pos).rotation.x;
  }
  else {
    sVar3 = (param2->pos).rotation.x + (param2->pMatrix->pos).rotation.x;
  }
  for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {
    uStack_24 = (int)sVar3 + (uint)uVar5 * 0x4000 ^ 0x80000000;
    local_28 = 0x43300000;
    dVar6 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    local_4c.x = -(float)(param1 * dVar6 - (double)(param2->pos).pos.x);
    local_4c.y = (param2->pos).pos.y + 10.0;
    uStack_2c = (int)sVar3 + (uint)uVar5 * 0x4000 ^ 0x80000000;
    local_30 = 0x43300000;
    dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_2c) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    local_4c.z = -(float)(param1 * dVar6 - (double)(param2->pos).pos.z);
    vec3f_toNearest10(&local_4c,&vStack_38);
    if (param2->pMatrix == (ObjInstance *)0x0) {
      uVar4 = FUN_8006dd10((undefined4 *)&vStack_38,(undefined4 *)&vStack_40,(undefined4 *)0x0,
                           local_50,'\0');
      uVar4 = uVar4 & 0xff;
      if (local_50[0] == '\x01') {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 1;
    }
    if (uVar4 != 0) {
      iVar1 = FUN_800bb7e0(1.0,&(param2->pos).pos.x,&local_4c.x,0,apOStack_a4,param2,
                           *(byte *)(param3 + 0x25d),-1,0,'\0');
      if (iVar1 != 0) {
        uVar4 = 0;
      }
    }
    uVar2 = uVar2 | uVar4 << (uint)uVar5;
  }
  return uVar2;
}


undefined4 baddieControl_func09(void) { //80161FA0
  return 0;
}


/* Library Function - Single Match
    baddieControl_func07
   
   Library: KioskDefault 0 0 */

void baddieControl_func07
               (short *param1,int param2,byte param3,undefined2 *param4,undefined2 *param5,
               undefined2 *param6) { //80161FA8
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  double dVar7;
  
  iVar6 = *(int *)(param1 + 0x5c);
  if ((param1 == (short *)0x0) || (param2 == 0)) {
    *param4 = 0;
    *param5 = 0;
    *param6 = 0;
  }
  else {
    fVar1 = *(float *)(param2 + 0x18) - *(float *)(param1 + 0xc);
    fVar2 = *(float *)(param2 + 0x1c) - *(float *)(param1 + 0xe);
    fVar3 = *(float *)(param2 + 0x20) - *(float *)(param1 + 0x10);
    uVar4 = getAngle();
    if (*(int *)(param1 + 0x18) == 0) {
      uVar5 = (uint)*param1;
    }
    else {
      uVar5 = (int)*param1 + (int)**(short **)(param1 + 0x18);
    }
    uVar4 = (uVar4 & 0xffff) - (uVar5 & 0xffff);
    if (0x8000 < (int)uVar4) {
      uVar4 = uVar4 - 0xffff;
    }
    if ((int)uVar4 < -0x8000) {
      uVar4 = uVar4 + 0xffff;
    }
    *param5 = (short)uVar4;
    if (((uVar4 & 0xffff) < 0x31c4) || (0xce3b < (uVar4 & 0xffff))) {
      *(ushort *)(iVar6 + 0x3ae) = *(ushort *)(iVar6 + 0x3ae) & 0xffef;
    }
    else {
      *(ushort *)(iVar6 + 0x3ae) = *(ushort *)(iVar6 + 0x3ae) | 0x10;
    }
    *param4 = (short)((uVar4 & 0xffff) / (0x10000 / param3));
    dVar7 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
    *param6 = (short)(int)dVar7;
  }
  return;
}


/* Library Function - Single Match
    baddieControl_func05
   
   Library: KioskDefault 0 0 */

void baddieControl_func05(double param1,double param2,double param3,short *param4,int param5) { //80162138
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  _savefpr_21();
  fVar1 = (float)((double)*(float *)(param5 + 0x18) - param1);
  fVar2 = (float)((double)*(float *)(param5 + 0x20) - param2);
  dVar3 = sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
  if (dVar3 < param3) {
    dVar3 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)*param4 ^ 0x80000000
                                                                          ) - 4503601774854144.0) *
                                                 3.141593) / 32767.0));
    dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)*param4 ^ 0x80000000) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    fVar1 = -(float)(dVar3 * (double)(float)(param1 - dVar3) +
                    (double)(float)(dVar4 * (double)(float)(param2 - dVar4)));
    dVar5 = (double)(fVar1 + (float)(dVar3 * (double)*(float *)(param5 + 0x18) +
                                    (double)(float)(dVar4 * (double)*(float *)(param5 + 0x20))));
    if ((0.0 < dVar5) &&
       (fVar1 + (float)(dVar3 * (double)*(float *)(param5 + 0x8c) +
                       (double)(float)(dVar4 * (double)*(float *)(param5 + 0x94))) <= 1.0)) {
      *(float *)(param5 + 0x18) = -(float)(dVar3 * dVar5 - (double)*(float *)(param5 + 0x18));
      *(float *)(param5 + 0x20) = -(float)(dVar4 * dVar5 - (double)*(float *)(param5 + 0x20));
      multVectorByObjMtx2((double)*(float *)(param5 + 0x18),(double)*(float *)(param5 + 0x1c),
                          (double)*(float *)(param5 + 0x20),(float *)(param5 + 0xc),
                          (float *)(param5 + 0x10),(float *)(param5 + 0x14),*(int *)(param5 + 0x30))
      ;
    }
  }
  distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                         (int)*param4 + 0x4000U ^ 0x80000000) -
                                       4503601774854144.0) * 3.141593) / 32767.0));
  mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,(int)*param4 + 0x4000U ^ 0x80000000)
                                   - 4503601774854144.0) * 3.141593) / 32767.0));
  _restfpr_21();
  return;
}


/* Library Function - Single Match
    baddieControl_func06
   
   Library: KioskDefault 0 0 */

void baddieControl_func06(double param1,double param2,short *param3,int param4) { //80162370
  if (*(float *)(param4 + 0x290) < 0.005) {
    *(undefined2 *)(param4 + 0x328) = 0;
    *(undefined2 *)(param4 + 0x32a) = 0;
    *(float *)(param4 + 0x290) = 0.0;
    *(float *)(param4 + 0x278) = 0.0;
  }
  *(float *)(param4 + 0x27c) = 0.0;
  *param3 = (short)(int)((float)((double)((float)((double)CONCAT44(0x43300000,
                                                                   (int)*(short *)(param4 + 0x32a) ^
                                                                   0x80000000) - 4503601774854144.0)
                                         * timeDelta) / param2) * 182.0 +
                        (float)((double)CONCAT44(0x43300000,(int)*param3 ^ 0x80000000) -
                               4503601774854144.0));
  *(float *)(param4 + 0x28c) =
       timeDelta *
       ((*(float *)(param4 + 0x290) - *(float *)(param4 + 0x28c)) / *(float *)(param4 + 0x2b0)) +
       *(float *)(param4 + 0x28c);
  *(float *)(param4 + 0x278) =
       timeDelta *
       ((*(float *)(param4 + 0x290) - *(float *)(param4 + 0x278)) / *(float *)(param4 + 0x2b0)) +
       *(float *)(param4 + 0x278);
  if (param1 < (double)*(float *)(param4 + 0x28c)) {
    *(float *)(param4 + 0x28c) = (float)param1;
  }
  if (param1 < (double)*(float *)(param4 + 0x278)) {
    *(float *)(param4 + 0x278) = (float)param1;
  }
  return;
}


/* Library Function - Single Match
    baddieControl_func0A
   
   Library: KioskDefault 0 0 */

undefined2 baddieControl_func0A(int param1) { //80162480
  undefined2 uVar1;
  
  if (*(int *)(param1 + 0x4c) == 0) {
    uVar1 = 0xd2;
  }
  else {
    uVar1 = *(undefined2 *)(*(int *)(param1 + 0x4c) + 0x34);
  }
  return uVar1;
}


double baddieControl_func0B(int param1) { //801624AC
  return (double)*(float *)(*(int *)(param1 + 0xb8) + 0x3e0);
}


/* Library Function - Single Match
    baddieControl_func0F
   
   Library: KioskDefault 0 0 */

void baddieControl_func0F
               (short *param1,int param2,int param3,undefined4 param4,undefined4 param5,
               undefined2 param6) { //801624C8
  float fVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  _savefpr_25();
  *(undefined4 *)(param3 + 0x30c) = 0;
  *(undefined4 *)(param3 + 0x310) = 0;
  *(undefined2 *)(param3 + 0x324) = 0;
  *(float *)(param3 + 0x288) = 0.0;
  *(float *)(param3 + 0x284) = 0.0;
  if (*(char *)(param2 + 0x4e) != '\x01') {
    *(undefined4 *)(param2 + 0x38) = *(undefined4 *)(param1 + 6);
    *(undefined4 *)(param2 + 0x3c) = *(undefined4 *)(param1 + 8);
    *(undefined4 *)(param2 + 0x40) = *(undefined4 *)(param1 + 10);
    DAT_803994f0 = 10000.0;
    DAT_803994f4 = '\0';
  }
  *(undefined2 *)(param2 + 0x66) = 0;
  *(undefined *)(param2 + 0x4e) = 1;
  fVar1 = *(float *)(param2 + 0x38) - *(float *)(param1 + 6);
  fVar2 = *(float *)(param2 + 0x40) - *(float *)(param1 + 10);
  dVar4 = sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
  if (*(int *)(param3 + 0x2c8) != 0) {
    dVar7 = (double)(*(float *)(*(int *)(param3 + 0x2c8) + 0xc) - *(float *)(param2 + 0x38));
    dVar6 = (double)(*(float *)(*(int *)(param3 + 0x2c8) + 0x14) - *(float *)(param2 + 0x40));
    dVar5 = sqrt((double)(float)(dVar7 * dVar7 + (double)(float)(dVar6 * dVar6)));
    dVar8 = (double)(timeDelta * (float)(dVar5 - dVar4) * 0.25);
    if (dVar8 <= 50.0) {
      if (dVar8 < 15.0) {
        dVar8 = 15.0;
      }
    }
    else {
      dVar8 = 50.0;
    }
    if (dVar4 <= (double)DAT_803994f0) {
      DAT_803994f4 = DAT_803994f4 + '\x01';
    }
    if ((dVar5 <= dVar4) || ('\t' < DAT_803994f4)) {
      iVar3 = (int)*param1 - (uint)**(ushort **)(param3 + 0x2c8);
      if (0x8000 < iVar3) {
        iVar3 = iVar3 + -0xffff;
      }
      if (iVar3 < -0x8000) {
        iVar3 = iVar3 + 0xffff;
      }
      if (0x2000 < iVar3) {
        iVar3 = 0x2000;
      }
      if (iVar3 < -0x2000) {
        iVar3 = -0x2000;
      }
      *param1 = *param1 - (short)((int)(iVar3 * (uint)framesThisStep) >> 3);
      if ('\n' < DAT_803994f4) {
        iVar3 = 0;
      }
      if ((iVar3 < 0x100) && (-0x100 < iVar3)) {
        *(undefined *)(param2 + 0x4e) = 0;
        *(short *)(param2 + 0x52) = *(short *)(param2 + 0x50) + -1;
      }
      else {
                    /* {@symbol 8011bdb4} */
        (**(code **)(*(int *)pDll11 + 8))
                  ((double)timeDelta,(double)timeDelta,param1,param3,param4,param5);
      }
    }
    else {
      *(float *)(param3 + 0x288) = (float)(-(double)(float)(dVar7 / dVar5) * dVar8);
      *(float *)(param3 + 0x284) = (float)((double)(float)(dVar6 / dVar5) * dVar8);
      *(float *)(param1 + 6) =
           (float)(dVar4 * (double)(float)(dVar7 / dVar5) + (double)*(float *)(param2 + 0x38));
      *(float *)(param1 + 10) =
           (float)(dVar4 * (double)(float)(dVar6 / dVar5) + (double)*(float *)(param2 + 0x40));
                    /* {@symbol 8011bdb4} */
      (**(code **)(*(int *)pDll11 + 8))
                ((double)timeDelta,(double)timeDelta,param1,param3,param4,param5);
    }
    DAT_803994f0 = (float)dVar4;
    if (*(char *)(param2 + 0x4e) == '\0') {
      *(undefined *)(param3 + 0x3b0) = 0;
      *(undefined2 *)(param3 + 0x26c) = param6;
      *(undefined4 *)(param3 + 0x2c8) = 0;
      *(undefined2 *)(param2 + 0x66) = 0xffff;
      *(ushort *)(param2 + 0x66) = *(ushort *)(param2 + 0x66) & 0xffbf;
      *(undefined *)(param3 + 0x25b) = 0;
      mainSetBits((int)*(short *)(param3 + 0x39e),0);
    }
  }
  _restfpr_25();
  return;
}


/* Library Function - Single Match
    baddieControl_func10
   
   Library: KioskDefault 0 0 */

void baddieControl_func10
               (int param1,int param2,undefined4 param3,undefined4 param4,undefined2 param5,
               float *param6,float *param7,int *param8) { //801627E8
  double dVar1;
  double dVar2;
  double dVar3;
  
  _savefpr_29();
  if (*(char *)(param2 + 0x371) != '\0') {
    *(undefined4 *)(param2 + 0x30c) = 0;
    *(undefined4 *)(param2 + 0x310) = 0;
    *(undefined2 *)(param2 + 0x324) = 0;
    *(float *)(param2 + 0x288) = 0.0;
    *(float *)(param2 + 0x284) = 0.0;
    *param8 = 1;
    dVar3 = (double)(*param6 - *(float *)(param1 + 0xc));
    dVar2 = (double)(*param7 - *(float *)(param1 + 0x14));
    dVar1 = sqrt((double)(float)(dVar3 * dVar3 + (double)(float)(dVar2 * dVar2)));
    if (10.0 <= dVar1) {
      *(float *)(param2 + 0x288) = (float)(-(double)(float)(dVar3 / dVar1) * 50.0);
      *(float *)(param2 + 0x284) = (float)((double)(float)(dVar2 / dVar1) * 50.0);
      *(float *)(param1 + 0xc) =
           (float)(dVar1 * (double)(float)(dVar3 / dVar1) + (double)*(float *)(param1 + 0xc));
      *(float *)(param1 + 0x14) =
           (float)(dVar1 * (double)(float)(dVar2 / dVar1) + (double)*(float *)(param1 + 0x14));
                    /* {@symbol 8011bdb4} */
      (**(code **)(*(int *)pDll11 + 8))
                ((double)timeDelta,(double)timeDelta,param1,param2,param3,param4);
    }
    else {
      *param8 = 0;
    }
    if (*param8 == 0) {
      *(undefined *)(param2 + 0x3b0) = 0;
      *(undefined2 *)(param2 + 0x26c) = param5;
      *(undefined4 *)(param2 + 0x2c8) = 0;
      *(undefined *)(param2 + 0x25b) = 0;
      mainSetBits((int)*(short *)(param2 + 0x39e),0);
    }
  }
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    baddieControl_func0D
   
   Library: KioskDefault 0 0 */

void baddieControl_func0D(double param1,ObjInstance *param2,uint *param3,char param4) { //8016296C
  N64Button NVar2;
  Camera *pCVar1;
  s8 sVar3;
  N64Button32 NVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  
  _savefpr_30();
  dVar7 = 0.0;
  dVar6 = 0.0;
  uVar5 = 0;
  NVar4 = 0;
  *param3 = *param3 | 0x8000;
  *(undefined2 *)(param3 + 0xc9) = 0;
  NVar2 = n64GetEnabledButtonsHeld(2);
  if ((NVar2 & N64_BUTTON_R) != 0) {
    pCVar1 = getCurCamera();
    sVar3 = getStickX2(2);
    dVar7 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) -
                           4503601774854144.0);
    sVar3 = getStickY2(2);
    dVar6 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) -
                           4503601774854144.0);
    NVar2 = n64GetEnabledButtonsHeld(2);
    uVar5 = (uint)NVar2;
    NVar4 = n64GetEnabledButtonsPressed(2);
    NVar4 = NVar4 & 0xffff;
    *(short *)(param3 + 0xc9) = (pCVar1->rot).x;
    *param3 = *param3 & 0xffff7fff;
  }
  if (param2->hitstate != (HitState *)0x0) {
    objHitFn_80089074(param2,0,0,-1);
  }
  if (param4 != -1) {
    *(char *)((int)param3 + 0x25b) = param4;
  }
  param3[0xa7] = (uint)(float)param1;
  param3[0xa2] = (uint)(float)dVar7;
  param3[0xa1] = (uint)(float)dVar6;
  param3[0xc4] = NVar4;
  param3[0xc3] = uVar5;
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    baddieControl_func0E
   
   Library: KioskDefault 0 0 */

undefined4 baddieControl_func0E(int param1,int param2,char param3) { //80162AB0
  undefined4 uVar1;
  int iVar2;
  
  if (((param3 == '\0') || ('\0' < *(char *)(param2 + 0x348))) || (*(char *)(param1 + 0x36) != '\0')
     ) {
    if ((*(int *)(param1 + 0x30) == 0) &&
       (iVar2 = getBlockIdxAtCoords((double)*(float *)(param1 + 0xc),
                                    (double)*(float *)(param1 + 0x10),
                                    (double)*(float *)(param1 + 0x14)), iVar2 < 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* Library Function - Single Match
    baddieControl_func13
   
   Library: KioskDefault 0 0 */

undefined4 baddieControl_func13(double param1,ObjInstance *param2,int param3,int param4) { //80162B40
  ObjInstance *param1_00;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  float local_70;
  float local_6c;
  float local_68;
  ObjInstance *apOStack_64 [21];
  
  param1_00 = Object_objGetMain();
  uVar3 = 0;
  if (*(char *)(param3 + 0x33a) != '\0') {
    if ((*(ObjInstance **)(param3 + 0x2c8) == param1_00) && (*(char *)(param3 + 0x348) != '\0')) {
      if ((*(float *)(param3 + 0x2b8) <= (float)param1) || (param4 == 0)) {
        uVar1 = mainGet((int)param1_00,1);
        if (uVar1 == 0) {
          uVar3 = 1;
        }
        else {
          iVar2 = FUN_801a7aa8((int)param1_00);
          if (iVar2 < 1) {
            uVar3 = 1;
          }
          else {
            local_70 = (param1_00->pos).pos.x;
            local_6c = (param1_00->pos).pos.y + 10.0;
            local_68 = (param1_00->pos).pos.z;
            iVar2 = FUN_800bb7e0(1.0,&(param2->pos).pos.x,&local_70,0,apOStack_64,param2,4,-1,0,'\0'
                                );
            if (iVar2 != 0) {
              uVar3 = 1;
            }
          }
        }
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* Library Function - Single Match
    baddieControl_func14
   
   Library: KioskDefault 0 0 */

void baddieControl_func14(double param1,ObjInstance *param2,int param3,int param4) { //80162C64
  bool bVar1;
  uint uVar2;
  int iVar3;
  ObjInstance *param1_00;
  int iVar4;
  double dVar5;
  char local_c0 [4];
  ObjInstance *apOStack_bc [21];
  vec3f local_68;
  vec3s vStack_5c;
  vec3s vStack_54;
  float local_4c;
  float local_48;
  float local_44;
  ObjInstance *local_40 [5];
  
  _savefpr_30();
  bVar1 = false;
  local_40[0] = Object_objGetMain();
  local_40[1] = (ObjInstance *)0x0;
  for (iVar3 = 0; (!bVar1 && (param1_00 = local_40[iVar3], param1_00 != (ObjInstance *)0x0));
      iVar3 = iVar3 + 1) {
    local_4c = (param1_00->prevPos).x - (param2->prevPos).x;
    local_48 = (param1_00->prevPos).y - (param2->prevPos).y;
    local_44 = (param1_00->prevPos).z - (param2->prevPos).z;
    dVar5 = sqrt((double)(local_44 * local_44 + local_4c * local_4c + local_48 * local_48));
    if ((dVar5 < (double)(float)param1) && (*(char *)(param3 + 0x348) != '\0')) {
      dVar5 = FUN_801a84a8((int)param1_00);
      if (0.5 < dVar5) {
        bVar1 = true;
      }
      uVar2 = getAngle();
      if (param2->pMatrix == (ObjInstance *)0x0) {
        iVar4 = (uVar2 & 0xffff) - (uint)(ushort)(param2->pos).rotation.x;
        if (0x8000 < iVar4) {
          iVar4 = iVar4 + -0xffff;
        }
        if (iVar4 < -0x8000) {
          iVar4 = iVar4 + 0xffff;
        }
      }
      else {
        iVar4 = (uVar2 & 0xffff) -
                ((int)(param2->pos).rotation.x + (int)(param2->pMatrix->pos).rotation.x & 0xffffU);
        if (0x8000 < iVar4) {
          iVar4 = iVar4 + -0xffff;
        }
        if (iVar4 < -0x8000) {
          iVar4 = iVar4 + 0xffff;
        }
      }
      if ((iVar4 < param4) && (-param4 < iVar4)) {
        bVar1 = true;
      }
      uVar2 = mainGet((int)param1_00,1);
      if (uVar2 == 0) {
        bVar1 = false;
      }
      iVar4 = FUN_801a7aa8((int)param1_00);
      if (iVar4 < 1) {
        bVar1 = false;
      }
      else {
        local_68.x = (param2->pos).pos.x;
        local_68.y = (param2->pos).pos.y + 10.0;
        local_68.z = (param2->pos).pos.z;
        vec3f_toNearest10(&local_68,&vStack_5c);
        local_68.x = (param1_00->pos).pos.x;
        local_68.y = (param1_00->pos).pos.y + 10.0;
        local_68.z = (param1_00->pos).pos.z;
        vec3f_toNearest10(&local_68,&vStack_54);
        uVar2 = FUN_8006dd10((undefined4 *)&vStack_54,(undefined4 *)&vStack_5c,(undefined4 *)0x0,
                             local_c0,'\0');
        if ((local_c0[0] == '\x01') || ((uVar2 & 0xff) != 0)) {
          iVar4 = FUN_800bb7e0(1.0,&(param2->pos).pos.x,&local_68.x,0,apOStack_bc,param2,4,-1,0,'\0'
                              );
          if (iVar4 != 0) {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    baddieControl_func0C
   
   Library: KioskDefault 0 0 */

void baddieControl_func0C
               (ObjInstance *param_1,int param_2,int param_3,short param_4,undefined *param_5,
               short param_6,short param_7,uint param_8,char param_9) { //80162F2C
  if (param_3 != 0) {
    *(undefined *)(param_3 + 0x24) = 0;
    *(undefined *)(param_3 + 0x25) = 0;
    *(undefined *)(param_3 + 0x26) = 4;
    *(undefined *)(param_3 + 0x27) = 0x14;
  }
  if (param_6 != -1) {
    *(short *)(param_2 + 0x268) = param_6;
    *(undefined *)(param_2 + 0x273) = 1;
  }
  if (param_7 != -1) {
                    /* {@symbol 8011c3c0} */
    (**(code **)(*(int *)pDll11 + 0x14))(param_1,param_2,(int)param_7);
  }
  if (param_5 != (undefined *)0x0) {
    *param_5 = 2;
  }
  if (param_8 != 0) {
    Object_ObjAnimSetMove(0.0,param_1,param_8,0);
  }
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(param_1,param_2 + 4);
  if (param_9 != -1) {
    *(char *)(param_2 + 0x25b) = param_9;
  }
  if (param_4 != -1) {
    mainSetBits((int)param_4,1);
  }
  return;
}


void baddieControl_func15(ObjInstance *param1,undefined4 param2,int param3) { //80163050
  float fVar1;
  ObjDef *pOVar2;
  undefined uVar3;
  int iVar4;
  undefined in_r6;
  undefined in_r7;
  undefined in_r8;
  undefined in_r9;
  undefined in_r10;
  undefined4 unaff_r26;
  undefined4 in_LR;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined in_stack_ffffffbb;
  undefined in_stack_ffffffbf;
  undefined uVar8;
  float local_38 [2];
  
  _savefpr_29();
                    /* {@symbol 801630ac} */
  switch(param2) {
  case 1:
    uVar3 = 0xcd;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,MagicDustMi);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 2:
    uVar3 = 9;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,EnergyGem1);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 3:
    uVar3 = 0xb;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,EnergyEgg);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 4:
    break;
  case 5:
    dVar7 = (double)(param1->prevPos).x;
    dVar6 = (double)(param1->prevPos).y;
    dVar5 = (double)(param1->prevPos).z;
    pOVar2 = param1->def;
    if (pOVar2 != (ObjDef *)0x0) {
      (param1->prevPos).x = (pOVar2->pos).x;
      (param1->prevPos).y = (pOVar2->pos).y;
      (param1->prevPos).z = (pOVar2->pos).z;
    }
    local_38[0] = 750.0;
    DAT_803994f8 = getSeqObj(5,param1,local_38);
    (param1->prevPos).x = (float)dVar7;
    (param1->prevPos).y = (float)dVar6;
    (param1->prevPos).z = (float)dVar5;
    if (DAT_803994f8 != (ObjInstance *)0x0) {
      fVar1 = (param1->pos).pos.x;
      (DAT_803994f8->prevPos).x = fVar1;
      (DAT_803994f8->pos).pos.x = fVar1;
      fVar1 = (param1->pos).pos.y + 15.0;
      (DAT_803994f8->prevPos).y = fVar1;
      (DAT_803994f8->pos).pos.y = fVar1;
      fVar1 = (param1->pos).pos.z;
      (DAT_803994f8->prevPos).z = fVar1;
      (DAT_803994f8->pos).pos.z = fVar1;
    }
  default:
    _restfpr_29();
    return;
  case 6:
    uVar3 = 0xc4;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,MagicDustSm);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 7:
    uVar3 = 0xcd;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,MagicDustMi);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 8:
    uVar3 = 0xce;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,MagicDustLa);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 9:
    uVar3 = 0xcf;
    uVar8 = in_r6;
    pOVar2 = objAlloc(0x30,MagicDustHu);
    FUN_80163214((char)pOVar2,uVar3,(char)param3,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  case 0xbad1abe1:
    camDebug_func07();
    return;
  }
  uVar3 = 0xcd;
  iVar4 = param3;
  uVar8 = in_r6;
  pOVar2 = objAlloc(0x30,MagicDustMi);
  if (param3 != -1) {
    pOVar2[1].loadFlags = (char)((ushort)(short)param3 >> 8);
    pOVar2[1].mapStates2 = (char)(short)param3;
    FUN_80163214((char)pOVar2,uVar3,(char)iVar4,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
                 in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
    return;
  }
  FUN_80163214((char)pOVar2,uVar3,(char)iVar4,in_r6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffbb,
               in_stack_ffffffbf,uVar8,unaff_r26,in_LR);
  return;
}


/* Library Function - Single Match
    baddieControl_func16
   
   Library: KioskDefault 0 0 */

int baddieControl_func16
              (uint param1,int param2,undefined4 param_3,undefined4 param_4,int param5,int param6,
              undefined2 param7,int param8) { //801632D4
  ObjInstance *param1_00;
  int iVar1;
  uint uVar2;
  int iVar3;
  float local_48;
  undefined4 local_44;
  float local_40;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  iVar3 = *(int *)(param1 + 0xb8);
  param1_00 = Object_objGetMain();
  if (0.0 < *(float *)(iVar3 + 0x3e4)) {
    *(float *)(iVar3 + 0x3e4) = timeDelta * *(float *)(iVar3 + 1000) + *(float *)(iVar3 + 0x3e4);
    if ((*(ushort *)(iVar3 + 0x3ae) & 0x20) == 0) {
      if ((*(ushort *)(iVar3 + 0x3ae) & 0x40) == 0) {
        if (0.0 <= *(float *)(iVar3 + 0x3e4)) {
          if (120.0 < *(float *)(iVar3 + 0x3e4)) {
            *(float *)(iVar3 + 0x3e4) = 120.0 - (*(float *)(iVar3 + 0x3e4) - 120.0);
            *(float *)(iVar3 + 1000) = -*(float *)(iVar3 + 1000);
          }
        }
        else {
          *(float *)(iVar3 + 0x3e4) = 0.0;
        }
      }
      else if (2.0 < *(float *)(iVar3 + 0x3e4)) {
        iVar1 = *(int *)(param1 + 0x4c);
        *(float *)(iVar3 + 0x3e4) = 0.0;
        *(ushort *)(iVar3 + 0x3ae) = *(ushort *)(iVar3 + 0x3ae) & 0xffbf;
        *(undefined *)(param2 + 0x348) = 0;
        *(undefined *)(param1 + 0x36) = 0;
        *(undefined4 *)(param1 + 0xf4) = 1;
        uStack_2c = *(short *)(iVar1 + 0x2c) * 0x3c ^ 0x80000000;
        local_30 = 0x43300000;
                    /* {@symbol 8012db54} */
        (**(code **)(*(int *)pDll_SaveGame + 100))
                  ((double)(float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0),
                   *(undefined4 *)(iVar1 + 0x14));
      }
    }
    else {
      *(ushort *)(iVar3 + 0x3ae) = *(ushort *)(iVar3 + 0x3ae) & 0xffdf;
      *(ushort *)(iVar3 + 0x3ae) = *(ushort *)(iVar3 + 0x3ae) | 0x40;
      if (2.0 < *(float *)(iVar3 + 0x3e4)) {
        *(float *)(iVar3 + 0x3e4) = 0.0;
        *(ushort *)(iVar3 + 0x3ae) = *(ushort *)(iVar3 + 0x3ae) & 0xffbf;
      }
    }
  }
  if (*(char *)(param2 + 0x348) == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_800884c8(param1,&local_3c,&local_34,&local_38,&local_40,&local_44,&local_48);
    *(undefined *)(iVar3 + 0x3ec) = (undefined)local_34;
    if (iVar1 != 0) {
      local_38 = local_38 << 2;
      if (param8 != 0) {
        *(float *)(param8 + 0xc) = local_40 + playerMapOffsetX;
        *(undefined4 *)(param8 + 0x10) = local_44;
        *(float *)(param8 + 0x14) = local_48 + playerMapOffsetZ;
      }
      if (param6 == 0) {
        local_38 = 0;
      }
      else if (*(char *)(iVar1 + param6 + -2) != -1) {
        local_38 = (uint)*(char *)(iVar1 + param6 + -2);
      }
      printf("%s hit by type %d for %d points",(char *)(*(int *)(param1 + 0x50) + 0x5f),
             iVar1,local_38);
      *(char *)(param2 + 0x348) = *(char *)(param2 + 0x348) - (char)local_38;
      if (*(char *)(param2 + 0x348) < '\x01') {
        *(ushort *)(iVar3 + 0x3ae) = *(ushort *)(iVar3 + 0x3ae) | 0x20;
        *(float *)(iVar3 + 0x3e4) = 1.0;
        *(float *)(iVar3 + 1000) = 0.01;
        *(undefined2 *)(param2 + 0x268) = param7;
        *(undefined *)(param2 + 0x348) = 0;
      }
      else if (local_38 != 0) {
        if ((*(int *)(param2 + 0x2c8) == 0) && (uVar2 = mainGet((int)param1_00,1), uVar2 != 0)) {
          *(ObjInstance **)(param2 + 0x2c8) = param1_00;
          *(undefined *)(param2 + 0x33d) = 0;
        }
        *(float *)(iVar3 + 0x3e4) = 1.0;
        *(float *)(iVar3 + 1000) = 12.0;
        if ((param5 != 0) && (*(int *)(param5 + (iVar1 + -2) * 4) != -1)) {
                    /* {@symbol 8011c3c0} */
          (**(code **)(*(int *)pDll11 + 0x14))
                    (param1,param2,*(undefined4 *)(param5 + (iVar1 + -2) * 4));
          *(undefined2 *)(param2 + 0x268) = param7;
        }
        *(char *)(param2 + 0x343) = (char)iVar1;
      }
      FUN_80068a9c(param1,0x10);
      objSendMsg(local_3c,0xe0001,param1,0);
    }
  }
  return iVar1;
}


/* Library Function - Single Match
    baddieControl_func17
   
   Library: KioskDefault 0 0 */

undefined4
baddieControl_func17
          (ObjInstance *param1,int param2,int param3,short param4,undefined *param5,short param6,
          short param7,short param8) { //80163660
  int iVar1;
  uint local_1c;
  undefined *local_18;
  uint local_14;
  
  local_1c = 0;
LAB_80163804:
  do {
    while( true ) {
      while( true ) {
        iVar1 = FUN_80091100((int)param1,(uint *)&local_18,&local_14,&local_1c);
        if (iVar1 == 0) {
          return 0;
        }
        if (local_18 != (undefined *)0xb) break;
        *(char *)(param2 + 0x342) = (char)local_1c;
      }
      if ((int)local_18 < 0xb) break;
      if (local_18 == (undefined *)0xe0000) {
        if (local_14 == *(uint *)(param2 + 0x2c8)) {
          *(short *)(param2 + 0x268) = param6;
          *(undefined4 *)(param2 + 0x2c8) = 0;
          *(undefined *)(param2 + 0x33d) = 0;
        }
      }
      else if ((int)local_18 < 0xe0000) {
        if (local_18 == &DAT_000a0001) {
LAB_80163780:
          if (*(short *)(param2 + 0x268) != param7) {
            func0C(param1,param2,param3,param4,param5,param6,param8,0,'\x01');
            *(short *)(param2 + 0x268) = param7;
            *(undefined *)(param2 + 0x33d) = 0;
            *(uint *)(param2 + 0x2c8) = local_14;
            return 1;
          }
        }
      }
      else if (local_18 == (undefined *)0x140001) {
        audioTryStartSfx((int *)param1,0x10,0x1cb,0x7f,"baddieControl.c",0x4a9);
      }
    }
    if (local_18 != (undefined *)0x3) {
      if ((int)local_18 < 3) {
        if (local_18 == (undefined *)0x1) goto LAB_80163780;
      }
      else if ((int)local_18 < 5) {
        objSendMsg(local_14,5,(uint)param1,0);
      }
      goto LAB_80163804;
    }
    if (*(short *)(param2 + 0x268) == param7) {
      *(undefined *)(param2 + 0x33d) = 0;
      *(undefined4 *)(param2 + 0x2c8) = 0;
      *(short *)(param2 + 0x268) = param6;
      return 2;
    }
  } while( true );
}


/* Library Function - Single Match
    baddieControl_func11
   
   Library: KioskDefault 0 0 */

void baddieControl_func11(void) { //80163838
                    /* {@symbol 80153f40} */
  (**(code **)(*(int *)pDll_ObjSeq + 0x3c))();
  return;
}


/* Library Function - Single Match
    baddieControl_func18
   
   Library: KioskDefault 0 0 */

void baddieControl_func18
               (double param1,ObjInstance *param2,int param3,undefined4 *param4,undefined4 param5,
               undefined4 param6,uint param7,uint param8) { //8016386C
  uint uVar1;
  int iVar2;
  void *pvVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  uint uStack_24;
  
  local_2c = 2;
  local_30[0] = 1;
  param4[0xfc] = param4 + 0xfe;
  *(undefined2 *)((int)param4 + 0x3b2) = 0;
  if (((param8 & 1) == 0) && ((param8 & 0x20) == 0)) {
    Object_objAddObjectType(param2,4);
    objAllocMsgQueue(param2,4);
  }
                    /* {@symbol 8011bd28} */
  (**(code **)(*(int *)pDll11 + 4))(param2,param4,param5,param6);
  *param4 = 0;
  *(undefined *)((int)param4 + 0x33d) = 0;
  param4[0x9e] = 0.0;
  param4[0x9f] = 0.0;
  if (*(char *)(param3 + 0x32) == '\0') {
    *(undefined *)(param4 + 0xd2) = 0x18;
  }
  else {
    *(char *)(param4 + 0xd2) = *(char *)(param3 + 0x32) << 2;
  }
  *(undefined2 *)((int)param4 + 0x39e) = *(undefined2 *)(param3 + 0x30);
  *(undefined2 *)(param4 + 0xe8) = *(undefined2 *)(param3 + 0x1a);
  *(undefined2 *)((int)param4 + 0x3a2) = *(undefined2 *)(param3 + 0x1c);
  if (*(short *)((int)param4 + 0x39e) != -1) {
    mainSetBits((int)*(short *)((int)param4 + 0x39e),0);
  }
  puVar5 = param4 + 1;
  if ((param8 & 2) == 0) {
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar5,0,0,0);
  }
  else {
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar5,0,param7 | 0x200000,1);
  }
                    /* {@symbol 8012ab74} */
  (**(code **)(*(int *)pDll1A + 8))(puVar5,1,&DAT_803027b0,&DAT_80397280,4);
  if ((param8 & 4) != 0) {
                    /* {@symbol 8012abb0} */
    (**(code **)(*(int *)pDll1A + 0xc))(puVar5,1,&DAT_803027a4,&DAT_803994fc,local_30);
  }
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(param2,puVar5);
  *(undefined *)(param4 + 0xeb) = *(undefined *)(param3 + 0x2b);
  *(undefined2 *)(param4 + 0xf7) = *(undefined2 *)(param3 + 0x22);
  *(undefined *)(param4 + 0xed) = *(undefined *)(param3 + 0x2f);
  *(undefined *)((int)param4 + 0x3b5) = *(undefined *)(param3 + 0x27);
  *(undefined *)((int)param4 + 0x3b6) = *(undefined *)(param3 + 0x28);
  param2->flags_0xb0 = param2->flags_0xb0 | *(byte *)((int)param4 + 0x3b6) & 3;
  if ((param8 & 8) == 0) {
    *(undefined2 *)(param4 + 0xe9) = 0;
    *(undefined2 *)((int)param4 + 0x3a6) = 0;
  }
  else {
    *(undefined2 *)(param4 + 0xe9) = *(undefined2 *)(param3 + 0x20);
    *(undefined2 *)((int)param4 + 0x3a6) = *(undefined2 *)(param3 + 0x1e);
  }
  *(undefined2 *)((int)param4 + 0x3ae) = 0;
  *(ushort *)((int)param4 + 0x3de) = (ushort)*(byte *)(param3 + 0x29) << 3;
  *(undefined *)(param4 + 0xec) = 0;
  (param2->pos).pos.x = *(float *)(param3 + 8);
  (param2->pos).pos.y = *(float *)(param3 + 0xc);
  (param2->pos).pos.z = *(float *)(param3 + 0x10);
  param4[0xf8] = (float)param1;
  (param2->pos).rotation.x = (short)((int)*(char *)(param3 + 0x2a) << 8);
  param2->newOpacity = 0xff;
  param2->flags_0xaf = param2->flags_0xaf & ~ModelDisableFlag08;
  *(undefined2 *)(param4 + 0xe7) = *(undefined2 *)(param3 + 0x18);
  if (*(short *)(param4 + 0xe7) == -1) {
    param2->field76_0xf4 = 0;
  }
  else {
    uVar1 = mainGetBit((int)*(short *)(param4 + 0xe7));
    param2->field76_0xf4 = uVar1;
  }
                    /* {@symbol 8012dc1c} */
  iVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(*(undefined4 *)(param3 + 0x14));
  if (iVar2 == 0) {
    param2->field76_0xf4 = 1;
  }
  if (param2->field76_0xf4 == 0) {
    FUN_80088d3c((int)param2);
    if (*(char *)(param3 + 0x2e) == -1) {
      param2->flags_0xf8 = 1;
    }
    else {
      param2->flags_0xf8 = 0;
    }
    if (((param8 & 1) == 0) && ((param8 & 0x20) == 0)) {
      allocVoxRoute((VoxRoute **)(param4 + 0xdd));
      *(undefined *)((int)param4 + 0x372) = 4;
      *(undefined *)((int)param4 + 0x373) = 0x14;
    }
    if ((param8 & 0x10) == 0) {
      param4[0xfd] = 0;
    }
    else {
      if ((param4[0xfd] == 0) && ((param8 & 0x20) == 0)) {
        pvVar3 = mmAlloc(0x108,TEST_COL,"BaddieControlDLL");
        param4[0xfd] = pvVar3;
      }
      if (param4[0xfd] != 0) {
        memclr((void *)param4[0xfd],0x108);
      }
      uStack_24 = (uint)*(ushort *)((int)param4 + 0x3de);
      local_28 = 0x43300000;
                    /* {@symbol 80128bb8} */
      cVar4 = (**(code **)(*(int *)pDll_RomCurve + 0x8c))
                        ((double)(float)((double)CONCAT44(0x43300000,uStack_24) - 4503599627370496.0
                                        ),param4[0xfd],param2,&local_2c,0xffffffff);
      if (cVar4 == '\0') {
        *(ushort *)((int)param4 + 0x3ae) = *(ushort *)((int)param4 + 0x3ae) | 8;
      }
    }
  }
  else {
    FUN_80088da4((int)param2);
  }
  return;
}


/* Library Function - Single Match
    baddieControl_func12
   
   Library: KioskDefault 0 0 */

void baddieControl_func12(uint param1,int param2,byte param3) { //80163CA0
  FUN_80068a9c(param1,0x7f);
  if ((*(byte *)(param2 + 0x3ac) & param3) == 0) {
    if (*(short *)(param2 + 0x3a6) != 0) {
                    /* {@symbol 8011bc6c} */
      (**(code **)(*(int *)pDll05_2 + 8))
                (param1,*(undefined2 *)(param2 + 0x3a6),"baddieControl.c",0x5bf,
                 s_baddie_>fightlockbreakmusic_803027d0);
    }
    if (*(short *)(param2 + 0x3a4) != 0) {
                    /* {@symbol 8011bc6c} */
      (**(code **)(*(int *)pDll05_2 + 8))
                (param1,*(undefined2 *)(param2 + 0x3a4),"baddieControl.c",0x5c0,
                 s_baddie_>fightlockmusic_803027ec);
    }
  }
  FUN_8006e9b0((void **)(param2 + 0x374));
  if (*(int *)(param2 + 0x3f4) != 0) {
    mm_free(*(void **)(param2 + 0x3f4));
    *(undefined4 *)(param2 + 0x3f4) = 0;
  }
  return;
}


/* Library Function - Single Match
    baddieControl_func19
   
   Library: KioskDefault 0 0 */

void baddieControl_func19(int param1,int param2) { //80163D88
  ObjDef *def;
  ObjInstance *pOVar1;
  dword local_20;
  dword local_1c;
  undefined2 local_18;
  
  local_20 = 0x230069;
  local_1c = 0x330064;
  local_18 = 0x1d;
  if ((*(char *)(param2 + 0x3b5) != *(char *)(param2 + 0x3b7)) && (*(char *)(param1 + 0x36) != '\0')
     ) {
    if (*(int *)(param1 + 200) != 0) {
      Object_objFreeObject(*(ObjInstance **)(param1 + 200));
      *(undefined4 *)(param1 + 200) = 0;
    }
    if ('\0' < *(char *)(param2 + 0x3b5)) {
      def = objAlloc(0x18,*(ObjDefEnum *)((int)&local_20 + (*(char *)(param2 + 0x3b5) + -1) * 2));
      pOVar1 = objInstantiateCharacter(def,4,-1,-1,*(ObjInstance **)(param1 + 0x30));
      *(ObjInstance **)(param1 + 200) = pOVar1;
      *(ushort *)(*(int *)(param1 + 200) + 0xb0) = *(ushort *)(param1 + 0xb0) & 3;
    }
    *(undefined *)(param2 + 0x3b7) = *(undefined *)(param2 + 0x3b5);
  }
  return;
}


/* Library Function - Single Match
    baddieControl_func1A
   
   Library: KioskDefault 0 0 */

double baddieControl_func1A(int param1) { //80163E78
  float fVar1;
  
  if ((*(char *)(*(int *)(param1 + 0x4c) + 0x32) == '\0') ||
     (*(short *)(*(int *)(param1 + 0xb8) + 0x29c) == 0)) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(*(int *)(param1 + 0xb8) + 0x29c))
                   - 4503599627370496.0) /
            (float)((double)CONCAT44(0x43300000,
                                     (uint)*(byte *)(*(int *)(param1 + 0x4c) + 0x32) << 2 ^
                                     0x80000000) - 4503601774854144.0);
  }
  return (double)fVar1;
}

