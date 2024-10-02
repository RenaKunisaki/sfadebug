
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void objfsa_initialise(undefined4 param) { //8011BD20
  return;
}


/* @description Called when DLL is unloaded */

void objfsa_release(void) { //8011BD24
  return;
}


/* Library Function - Single Match
    dll_10_func03
   
   Library: KioskDefault 0 0 */

void objfsa_func03(ObjInstance *this,ObjState_Player *state,undefined2 param3,undefined2 param4) { //8011BD28
  uint uVar1;
  
  *(undefined *)state = 0;
  for (uVar1 = 0; uVar1 < 0x34c; uVar1 = uVar1 + 1) {
    (&state->field_0x0)[uVar1] = 0;
  }
  state->field612_0x264 = param3;
  state->field613_0x266 = param4;
  state->field614_0x268 = 0;
  state->curState = 0;
  state->field622_0x272 = 1;
  state->field623_0x273 = 1;
  state->field681_0x2b0 = 10.0;
  state->field806_0x330 = 0xffffffff;
  state->field807_0x334 = 0xffffffff;
  *(undefined4 *)state = 0;
  return;
}


/* Library Function - Single Match
    dll_10_func04
   
   Library: KioskDefault 0 0 */

void objfsa_tick(double param1,double param2,ObjInstance *param3,uint *param4,int param5,int param6
                 ) { //8011BDB4
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  _savefpr_25();
  diProfStart();
  dummiedProfFn_8017a59c(0xff00ff);
  DAT_803992c2 = 0;
  cVar1 = *(char *)((int)param4 + 0x341);
  if (param4[0xb2] == 0) {
    param4[0xae] = (uint)0.0;
  }
  else {
    fVar2 = *(float *)(param4[0xb2] + 0xc) - (param3->pos).pos.x;
    fVar3 = *(float *)(param4[0xb2] + 0x14) - (param3->pos).pos.z;
    dVar5 = sqrt((double)(fVar2 * fVar2 + fVar3 * fVar3));
    param4[0xae] = (uint)(float)dVar5;
  }
  if (((*param4 & 0x8000) != 0) && (param3->pObj_0xc0 == (ObjInstance *)0x0)) {
    FUN_8011c7ac(param1,param3,(int)param4,param6);
    *(short *)((int)param4 + 0x322) =
         (short)(int)((double)(float)((double)CONCAT44(0x43300000,
                                                       (int)*(short *)((int)param4 + 0x322) ^
                                                       0x80000000) - 4503601774854144.0) + param1);
    if (10000.0 < (float)((double)CONCAT44(0x43300000,
                                           (int)*(short *)((int)param4 + 0x322) ^ 0x80000000) -
                         4503601774854144.0)) {
      *(undefined2 *)((int)param4 + 0x322) = 10000;
    }
  }
  *param4 = *param4 | 0x8000;
  if (param4[0x9d] != 0) {
    FUN_8011d884((short *)param3,(int)param4);
  }
  _player_updateStickAngle((ushort *)param3,(int)param4);
  *param4 = *param4 & 0xffdfffff;
  *(undefined *)((int)param4 + 0x341) = 0;
  DAT_803992e0 = 0;
  *param4 = *param4 & 0xfff7ffff;
  *(undefined *)(param4 + 0xd0) = 0;
  DAT_803992c1 = 0;
  playerRunStateMachine(param1,param3,param4,param5);
  *(short *)(param4 + 0xcb) =
       (short)(int)((double)(float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(param4 + 0xcb) ^ 0x80000000) -
                                   4503601774854144.0) + param1);
  if (10000.0 < (float)((double)CONCAT44(0x43300000,(int)*(short *)(param4 + 0xcb) ^ 0x80000000) -
                       4503601774854144.0)) {
    *(undefined2 *)(param4 + 0xcb) = 10000;
  }
  DAT_803992c8 = (param3->pos).pos.x;
  DAT_803992cc = (param3->pos).pos.z;
  if ((*param4 & 0x1000000) == 0) {
    playerUpdateTransform(param1,param3,param4);
  }
  iVar4 = DAT_803992d0;
  if (DAT_803992d0 != 0) {
    dVar8 = (double)(*(float *)(DAT_803992d0 + 0xc) - DAT_803992c8);
    dVar7 = (double)(*(float *)(DAT_803992d0 + 0x14) - DAT_803992cc);
    dVar5 = sqrt((double)(float)(dVar8 * dVar8 + (double)(float)(dVar7 * dVar7)));
    if (dVar5 < 10.0) {
      fVar2 = (param3->pos).pos.x - DAT_803992c8;
      fVar3 = (param3->pos).pos.z - DAT_803992cc;
      dVar6 = sqrt((double)(fVar2 * fVar2 + fVar3 * fVar3));
      if (dVar6 < 0.1000000014901161) {
        dVar6 = 0.1000000014901161;
      }
      if (1.0 <= dVar5) {
        if (dVar5 < dVar6) {
          dVar6 = dVar5;
        }
        (param3->pos).pos.x = (float)((double)(float)(dVar8 / dVar5) * dVar6 + (double)DAT_803992c8)
        ;
        (param3->pos).pos.z = (float)((double)(float)(dVar7 / dVar5) * dVar6 + (double)DAT_803992cc)
        ;
      }
      else {
        (param3->pos).pos.x = *(float *)(iVar4 + 0xc);
        (param3->pos).pos.z = *(float *)(iVar4 + 0x14);
      }
    }
  }
  DAT_803992d0 = 0;
  if (((*param4 & 0x1000000) == 0) && ((*param4 & 0x400000) == 0)) {
                    /* {@symbol 8012ac30} */
    (**(code **)(*(int *)pDll1A + 0x10))(param1,param3,param4 + 1);
                    /* {@symbol 8012b0e4} */
    (**(code **)(*(int *)pDll1A + 0x14))(param3,param4 + 1);
                    /* {@symbol 8012b170} */
    (**(code **)(*(int *)pDll1A + 0x18))((double)(float)param2,param3,param4 + 1);
    if ((*(byte *)(param4 + 0x98) & 0x10) == 0) {
      *param4 = *param4 & 0xfffbffff;
    }
    else {
      *param4 = *param4 | 0x40000;
    }
    if ((*param4 & 0x800000) != 0) {
      if (((*(byte *)(param4 + 0x98) & 2) != 0) || (*(char *)((int)param4 + 0x25e) != '\0')) {
        (param3->vel).x =
             (float)((double)((param3->pos).pos.x - (param3->hitstate->pos).x) / param1);
        (param3->vel).z =
             (float)((double)((param3->pos).pos.z - (param3->hitstate->pos).z) / param1);
      }
      *param4 = *param4 & 0xff7fffff;
    }
  }
  if ((param4[0xb2] != 0) && (cVar1 != *(char *)((int)param4 + 0x341))) {
    objSendMsg(param4[0xb2],0xb,(uint)param3,(int)*(char *)((int)param4 + 0x341));
  }
  dummiedProfFn_8017a59c(0xff);
  diProfEnd(1,"fsaTick");
  _restfpr_25();
  return;
}


/* Library Function - Single Match
    dll_10_func05
   
   Library: KioskDefault 0 0 */

void objfsa_func05(ObjInstance *param1,uint *param2,int param3) { //8011C220
  double dVar1;
  double dVar2;
  
  _savefpr_30();
  if ((*(byte *)(param2 + 0xd0) & 1) != 0) {
    dummiedProfFn_8017a59c(0xff00ff);
    dVar1 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)(param1->pos).
                                                                                rotation.x ^
                                                                           0x80000000) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)(param1->pos).rotation.x
                                                                       ^ 0x80000000) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    if ((*(byte *)(param2 + 0xd0) & 8) == 0) {
      param2[0x9f] = (uint)(float)((double)(param1->vel).x * dVar2 -
                                  (double)(float)((double)(param1->vel).z * dVar1));
      param2[0x9e] = (uint)(float)(-(double)(param1->vel).z * dVar2 -
                                  (double)(float)((double)(param1->vel).x * dVar1));
      if ((*(byte *)(param2 + 0xd0) & 4) != 0) {
        dVar1 = sqrt((double)((param1->vel).x * (param1->vel).x + (param1->vel).z * (param1->vel).z)
                    );
        param2[0xa3] = (uint)(float)dVar1;
      }
    }
    else {
      param2[0x9e] = (uint)(float)(-(double)(param1->vel).z * dVar2 -
                                  (double)(float)((double)(param1->vel).x * dVar1));
      param2[0xa3] = param2[0x9e];
    }
    *(undefined *)(param2 + 0xd0) = 0;
    *param2 = *param2 | 0x80000;
    DAT_803992e0 = 1;
    DAT_803992c1 = 0;
    DAT_803992c2 = 1;
    playerRunStateMachine((double)timeDelta,param1,param2,param3);
    dummiedProfFn_8017a59c(0xff);
  }
  _restfpr_30();
  return;
}


void objfsa_func06(undefined4 param1) { //8011C3B8
  DAT_803992d0 = param1;
  return;
}


/* Library Function - Single Match
    dll_10_func07
   
   Library: KioskDefault 0 0 */

void objfsa_func07(int param1,int param2,int param3) { //8011C3C0
  if (*(short *)(param2 + 0x26c) != param3) {
    *(undefined2 *)(param2 + 0x26e) = *(undefined2 *)(param2 + 0x26c);
    *(short *)(param2 + 0x26c) = (short)param3;
    if (*(int *)(param2 + 0x2fc) != 0) {
      (**(code **)(param2 + 0x2fc))(param1,param2);
      *(undefined4 *)(param2 + 0x2fc) = 0;
    }
  }
  *(undefined2 *)(param2 + 0x32c) = 0;
  *(undefined *)(param2 + 0x272) = 1;
  *(undefined *)(param2 + 0x341) = 0;
  *(undefined *)(param2 + 0x340) = 0;
  *(undefined *)(param2 + 0x34a) = 0;
  *(undefined2 *)(param2 + 0x270) = 0;
  if (*(int *)(param1 + 0x54) != 0) {
    *(undefined *)(*(int *)(param1 + 0x54) + 0x61) = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_10_func0A
   
   Library: KioskDefault 0 0 */

void objfsa_func0A(double param1,ObjInstance *param2,uint *param3,uint param4) { //8011C91C
  undefined uVar1;
  int iVar2;
  float local_38;
  float local_34;
  float local_30;
  short local_2a;
  char local_26;
  char acStack_25 [8];
  char local_1d;
  
  local_26 = '\0';
  uVar1 = objRunAnimation((double)(float)param3[0xa6],param1,(int)param2,&local_38);
  *(undefined *)((int)param3 + 0x33a) = uVar1;
  param3[0xc2] = 0;
  for (iVar2 = 0; iVar2 < local_1d; iVar2 = iVar2 + 1) {
    param3[0xc2] = param3[0xc2] | 1 << (int)acStack_25[iVar2];
  }
  objAnimFn_80087d88(param2,(int)&local_38);
  *param3 = *param3 & 0xfffeffff;
  if (local_26 == '\0') {
    param3[0x9e] = (uint)0.0;
    param3[0x9f] = (uint)0.0;
  }
  else if ((param4 & 0x10) == 0) {
    if ((param4 & 1) != 0) {
      param3[0x9e] = (uint)(float)(-(double)local_30 / param1);
    }
    if ((param4 & 2) != 0) {
      param3[0x9f] = (uint)(float)((double)local_38 / param1);
    }
    if ((param4 & 8) != 0) {
      (param2->pos).rotation.x = (param2->pos).rotation.x + local_2a;
    }
    if ((param4 & 4) != 0) {
      param3[0xa0] = (uint)(float)((double)local_34 / param1);
      *param3 = *param3 | 0x10000;
    }
  }
  else {
    if ((param4 & 1) != 0) {
      param3[0xab] = (uint)-local_30;
    }
    if ((param4 & 2) != 0) {
      param3[0xab] = (uint)local_38;
    }
    if ((param4 & 4) != 0) {
      param3[0xab] = (uint)local_34;
    }
    if ((param4 & 8) != 0) {
      (param2->pos).rotation.x = (param2->pos).rotation.x + local_2a;
    }
  }
  DAT_803992d4 = 1;
  return;
}


/* Library Function - Single Match
    dll_10_func0B
   
   Library: KioskDefault 0 0 */

void objfsa_func0B(double param1,double param2,double param3,short *param4,int param5) { //8011CAC4
  if (0.1 < *(float *)(param5 + 0x290)) {
    *param4 = (short)(int)((float)((double)(float)(param2 * param1) / param3) * 182.0 +
                          (float)((double)CONCAT44(0x43300000,(int)*param4 ^ 0x80000000) -
                                 4503601774854144.0));
  }
  return;
}


/* Library Function - Single Match
    dll_10_func0C
   
   Library: KioskDefault 0 0 */

void objfsa_func0C(double param1,double param2,int param3,int param4) { //8011CB20
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(param2 * param1 + (double)*(float *)(param4 + 0x2a4));
  if (1.0 < fVar1) {
    fVar1 = 1.0;
  }
  fVar2 = fVar1 - *(float *)(param4 + 0x2a4);
  if (0.0 < fVar2) {
    *(float *)(param3 + 0xc) = *(float *)(param4 + 0x2ec) * fVar2 + *(float *)(param3 + 0xc);
    *(float *)(param3 + 0x10) = *(float *)(param4 + 0x2f0) * fVar2 + *(float *)(param3 + 0x10);
    *(float *)(param3 + 0x14) = *(float *)(param4 + 0x2f4) * fVar2 + *(float *)(param3 + 0x14);
    *(float *)(param4 + 0x2a4) = fVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_10_func0D
   
   Library: KioskDefault 0 0 */

void objfsa_func0D(double param1,double param2,short *param3,int param4) { //8011CB9C
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(param2 * param1 + (double)*(float *)(param4 + 0x2a0));
  if (1.0 < fVar1) {
    fVar1 = 1.0;
  }
  fVar2 = fVar1 - *(float *)(param4 + 0x2a0);
  if (0.0 < fVar2) {
    *param3 = *param3 + (short)(int)(*(float *)(param4 + 0x2f8) * fVar2);
    *(float *)(param4 + 0x2a0) = fVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_10_func0E
   
   Library: KioskDefault 0 0 */

void objfsa_func0E(ushort *param1,int param2,uint param3) { //8011CC08
  uint uVar1;
  
  _savefpr_30();
  if (*(int *)(param2 + 0x2c8) != 0) {
    uVar1 = getAngle();
    uVar1 = (uVar1 & 0xffff) - (uint)*param1;
    if (0x8000 < (int)uVar1) {
      uVar1 = uVar1 - 0xffff;
    }
    if ((int)uVar1 < -0x8000) {
      uVar1 = uVar1 + 0xffff;
    }
    *param1 = *param1 + (short)(int)(((float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                                             4503601774854144.0) * timeDelta) /
                                    ((float)((double)CONCAT44(0x43300000,param3 ^ 0x80000000) -
                                            4503601774854144.0) * 3.0));
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    dll_10_func0F
   
   Library: KioskDefault 0 0 */

void objfsa_func0F(int *param1,int param2,int param3,int param4,int param5) { //8011CD58
  if ((*(uint *)(param2 + 0x308) & 1 << param3) != 0) {
    *(uint *)(param2 + 0x308) = *(uint *)(param2 + 0x308) & ~(1 << param3);
    audioTryStartSfx(param1,1,(ushort)*(undefined4 *)(param5 + param4 * 4),0x7f,"objfsa.c",
                     0x3a9);
  }
  return;
}


/* Library Function - Single Match
    dll_10_func10
   
   Library: KioskDefault 0 0 */

void objfsa_func10(int *param1,int param2,int param3,int param4,int param5,byte param6) { //8011CDE8
  if ((*(uint *)(param2 + 0x308) & 1 << param3) != 0) {
    *(uint *)(param2 + 0x308) = *(uint *)(param2 + 0x308) & ~(1 << param3);
    audioTryStartSfx(param1,1,(ushort)*(undefined4 *)(param5 + param4 * 4),param6,
                     "objfsa.c",0x3b9);
  }
  return;
}


/* Library Function - Single Match
    dll_10_func11
   
   Library: KioskDefault 0 0 */

void objfsa_func11(int param1,int param2,undefined4 param3) { //8011CE84
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  local_10[0] = param3;
                    /* {@symbol 80124500} */
  uVar1 = (**(code **)(*(int *)pDll_RomCurve + 0x14))
                    ((double)*(float *)(param1 + 0xc),(double)*(float *)(param1 + 0x10),
                     (double)*(float *)(param1 + 0x14),local_10,1,(int)*(char *)(param2 + 0x338));
  *(undefined4 *)(param2 + 0x330) = uVar1;
  return;
}


/* Library Function - Single Match
    dll_10_func12
   
   Library: KioskDefault 0 0 */

void player_updateCurve(double param1,int param2,uint *param3) { //8011CEE8
  int iVar1;
  
  if (param3[0xcc] == 0xffffffff) {
    param3[0xad] = (uint)0.0;
  }
  else {
                    /* {@symbol 8012464c} */
    iVar1 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))(param3[0xcc]);
    if (iVar1 == 0) {
      param3[0xad] = (uint)0.0;
    }
    else {
      followCurve((double)*(float *)(iVar1 + 8),(double)*(float *)(iVar1 + 0x10),
                  (double)(float)param1,param2,param3);
      if ((float)param3[0xad] < 20.0) {
        objfsa_func19();
      }
    }
  }
  return;
}


void objfsa_func19(void) { //8011CF98
  return;
}


/* Library Function - Single Match
    dll_10_func13
   
   Library: KioskDefault 0 0 */

void objfsa_func13(double param1,double param2,short *param3,int param4) { //8011CF9C
  float fVar1;
  double dVar2;
  double dVar3;
  
  _savefpr_26();
  *(byte *)(param4 + 0x340) = *(byte *)(param4 + 0x340) | 1;
  if (DAT_803992e0 == '\0') {
    dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)DAT_803992c4 ^
                                                                           0x80000000) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    dVar3 = (double)(float)(param2 * (double)(float)((double)*(float *)(param4 + 0x290) * -dVar2));
    dVar2 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)DAT_803992c4 ^
                                                                       0x80000000) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    fVar1 = (float)(param2 * (double)(float)((double)*(float *)(param4 + 0x290) * -dVar2));
    if (*(float *)(param4 + 0x290) < 0.02) {
      dVar3 = 0.0;
      fVar1 = 0.0;
    }
    *(float *)(param3 + 0x12) =
         *(float *)(param3 + 0x12) +
         (float)(param1 * (double)(float)(dVar3 - (double)*(float *)(param3 + 0x12))) /
         *(float *)(param4 + 0x2b0);
    *(float *)(param3 + 0x16) =
         *(float *)(param3 + 0x16) +
         (float)(param1 * (double)(fVar1 - *(float *)(param3 + 0x16))) / *(float *)(param4 + 0x2b0);
  }
  else {
    *(byte *)(param4 + 0x340) = *(byte *)(param4 + 0x340) & 0xfe;
  }
  dVar2 = sqrt((double)(*(float *)(param3 + 0x12) * *(float *)(param3 + 0x12) +
                       *(float *)(param3 + 0x16) * *(float *)(param3 + 0x16)));
  *(float *)(param4 + 0x28c) = (float)dVar2;
  if (*(float *)(param4 + 0x28c) < 0.04) {
    *(float *)(param4 + 0x28c) = 0.0;
    *(float *)(param3 + 0x12) = 0.0;
    *(float *)(param3 + 0x16) = 0.0;
  }
  dVar2 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)*param3 ^ 0x80000000)
                                                       - 4503601774854144.0) * 3.141593) / 32767.0))
  ;
  dVar3 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)*param3 ^ 0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  *(float *)(param4 + 0x27c) =
       (float)((double)*(float *)(param3 + 0x12) * dVar3 -
              (double)(float)((double)*(float *)(param3 + 0x16) * dVar2));
  *(float *)(param4 + 0x278) =
       (float)(-(double)*(float *)(param3 + 0x16) * dVar3 -
              (double)(float)((double)*(float *)(param3 + 0x12) * dVar2));
  _restfpr_26();
  return;
}


void objfsa_func14(int param1,int param2) { //8011D1CC
  *(float *)(param1 + 0x24) = 0.0;
  *(float *)(param1 + 0x2c) = 0.0;
  *(float *)(param2 + 0x28c) = 0.0;
  *(float *)(param2 + 0x278) = 0.0;
  *(float *)(param2 + 0x27c) = 0.0;
  return;
}


void objfsa_func15(undefined4 param_1,undefined4 param_2,undefined4 param3,undefined4 param4) { //8011D1F8
  DAT_803992d8 = param3;
  DAT_803992dc = param4;
  return;
}


/* Library Function - Single Match
    dll_10_func16
   
   Library: KioskDefault 0 0 */

void objfsa_func16(ObjInstance *param1,int param2,uint param3,uint param4) { //8011D204
  int iVar1;
  uint uVar2;
  double param1_00;
  float local_28 [2];
  double local_20;
  
  if (DAT_803992e0 != '\0') {
    if ((*(float *)(param2 + 0x278) <= 0.0) || ((int)(short)param1->animId == DAT_803992d8)) {
      if ((*(float *)(param2 + 0x278) < 0.0) && ((int)(short)param1->animId != DAT_803992dc)) {
        Object_ObjAnimSetMove((double)param1->animTimer,param1,DAT_803992dc,0);
        *(undefined *)(param2 + 0x33a) = 0;
      }
    }
    else {
      Object_ObjAnimSetMove((double)param1->animTimer,param1,DAT_803992d8,0);
      *(undefined *)(param2 + 0x33a) = 0;
    }
    param1_00 = sqrt((double)(*(float *)(param2 + 0x278) * *(float *)(param2 + 0x278) +
                             *(float *)(param2 + 0x27c) * *(float *)(param2 + 0x27c)));
    iVar1 = objGetAnimChange(param1_00,(int)param1,local_28);
    if (iVar1 != 0) {
      *(float *)(param2 + 0x298) = local_28[0];
    }
    if (param1_00 == 0.0) {
      local_28[0] = 0.0;
    }
    else {
      local_28[0] = (float)((double)*(float *)(param2 + 0x27c) / param1_00);
    }
    uVar2 = (uint)(local_28[0] * 16384.0);
    if ((int)uVar2 < 0) {
      uVar2 = -uVar2;
    }
    local_20 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
    if (16384.0 < (float)(local_20 - 4503601774854144.0)) {
      uVar2 = 0x4000;
    }
    if (*(float *)(param2 + 0x27c) <= 0.0) {
      FUN_80087afc((int)param1,param3,(short)uVar2);
    }
    else {
      FUN_80087afc((int)param1,param4,(short)uVar2);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_10_func17
   
   Library: KioskDefault 0 0 */

void player_doProjGfx(undefined4 param1,undefined4 param_2,short param3,int param4,
                      undefined4 param_5,int param6) { //8011D3B0
  LoadedDll *dll;
  
  dll = (LoadedDll *)runlinkDownloadCode(param3 + 0x1000,1);
  for (; param4 != 0; param4 = param4 + -1) {
    if (param6 == 0) {
      (**(code **)(dll->id + 4))(param1,0,0,1,0xffffffff,0);
    }
    else if (param6 == 1) {
      (**(code **)(dll->id + 4))(param1,0,0,2,0xffffffff,0);
    }
    else if (param6 == 2) {
      (**(code **)(dll->id + 4))(param1,0,0,4,0xffffffff,0);
    }
  }
  DLL_free(dll);
  return;
}


/* Library Function - Single Match
    dll_10_func18
   
   Library: KioskDefault 0 0 */

void player_updateParticles(int param1,undefined4 param_2,undefined4 param3,int param4,int param5) { //8011D4A8
  while ((param4 != 0 && (param1 != 0))) {
    if (param5 == 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param1,param3,0,2,0xffffffff,0);
    }
    else if (param5 == 1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param1,param3,0,2,0xffffffff,0);
    }
    else if (param5 == 2) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param1,param3,0,4,0xffffffff,0);
    }
    param4 = param4 + -1;
  }
  return;
}


/* Library Function - Single Match
    dll_10_func08
   
   Library: KioskDefault 0 0 */

void player_followCurve(double param1,double param2,double param3,int param4,uint *param5) { //8011D974
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  _savefpr_27();
  *param5 = *param5 & 0xffefffff;
  dVar4 = (double)(*(float *)(param4 + 0xc) - (float)param1);
  dVar3 = (double)(*(float *)(param4 + 0x14) - (float)param2);
  dVar2 = sqrt((double)(float)(dVar4 * dVar4 + (double)(float)(dVar3 * dVar3)));
  param5[0xad] = (uint)(float)dVar2;
  fVar1 = 65.0;
  if ((float)param5[0xad] < 15.0) {
    fVar1 = (float)param5[0xad] * 3.0;
    param5[0xa3] = (uint)((float)param5[0xa3] * 0.9);
  }
  if ((double)fVar1 < dVar2) {
    dVar2 = (double)(float)(dVar2 / (double)fVar1);
    dVar4 = (double)(float)(dVar4 / dVar2);
    dVar3 = (double)(float)(dVar3 / dVar2);
  }
  param5[0xa2] = (uint)(float)dVar4;
  param5[0xa1] = (uint)(float)-dVar3;
  param5[0xa2] = (uint)(float)((double)(float)param5[0xa2] * param3);
  param5[0xa1] = (uint)(float)((double)(float)param5[0xa1] * param3);
  if (65.0 < (float)param5[0xa2]) {
    param5[0xa2] = (uint)65.0;
  }
  if ((float)param5[0xa2] < -65.0) {
    param5[0xa2] = (uint)-65.0;
  }
  if (65.0 < (float)param5[0xa1]) {
    param5[0xa1] = (uint)65.0;
  }
  if ((float)param5[0xa1] < -65.0) {
    param5[0xa1] = (uint)-65.0;
  }
  _restfpr_27();
  return;
}


/* Library Function - Single Match
    dll_10_func09
   
   Library: KioskDefault 0 0 */

void objfsa_func09(double param1,double param2,double param3,double param4,double param5,int param6
                   ,int param7) { //8011DABC
  double dVar1;
  double dVar2;
  double dVar3;
  
  _savefpr_28();
  dVar3 = (double)(*(float *)(param6 + 0xc) - (float)param1);
  dVar2 = (double)(*(float *)(param6 + 0x14) - (float)param2);
  dVar1 = sqrt((double)(float)(dVar3 * dVar3 + (double)(float)(dVar2 * dVar2)));
  *(float *)(param7 + 0x2b4) = (float)dVar1;
  if (dVar1 != 0.0) {
    dVar3 = (double)(float)(dVar3 / dVar1);
    dVar2 = (double)(float)(dVar2 / dVar1);
  }
  if (*(float *)(param7 + 0x2b4) <= (float)param3 + (float)param4) {
    *(float *)(param7 + 0x28c) = *(float *)(param7 + 0x28c) * 0.9;
    *(float *)(param7 + 0x288) = 0.0;
    *(float *)(param7 + 0x284) = 0.0;
  }
  else {
    *(float *)(param7 + 0x288) = (float)(dVar3 * param5);
    *(float *)(param7 + 0x284) = (float)(-dVar2 * param5);
  }
  if (65.0 < *(float *)(param7 + 0x288)) {
    *(float *)(param7 + 0x288) = 65.0;
  }
  if (*(float *)(param7 + 0x288) < -65.0) {
    *(float *)(param7 + 0x288) = -65.0;
  }
  if (65.0 < *(float *)(param7 + 0x284)) {
    *(float *)(param7 + 0x284) = 65.0;
  }
  if (*(float *)(param7 + 0x284) < -65.0) {
    *(float *)(param7 + 0x284) = -65.0;
  }
  _restfpr_28();
  return;
}

