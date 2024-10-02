
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void attentionCam_initialise(undefined4 param) { //80157AA4
  return;
}


/* @description Called when DLL is unloaded */

void attentionCam_release(void) { //80157AA8
  return;
}


/* @description Set up object instance */

void attentionCam_init(Camera *this,int mode,undefined *param3,DllInitFlags flags,float x,float y,
                       float z) { //80157AAC
  float fVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  ObjInstance *param1;
  short sVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  uint auStack_13c [6];
  undefined auStack_124 [64];
  float local_e4 [4];
  undefined local_d4;
  undefined local_d0;
  float local_b8;
  short asStack_b4 [4];
  vec3s vStack_ac;
  vec3s vStack_a4;
  float afStack_9c [3];
  float local_90;
  float local_8c;
  float local_88;
  vec3f local_84;
  undefined4 local_78;
  uint uStack_74;
  double local_70;
  
  _savefpr_24();
  if ((short *)param3 == (short *)0x0) {
    printf((char *)&PTR_DAT_80302060);
  }
  *(undefined *)((int)param3 + 3) = 1;
  param1 = this[1].obj40;
  DAT_80399460 = (float *)mmAlloc(0x1bc,CAM_COL,"attentioncam");
  memclr(DAT_80399460,0x1bc);
                    /* {@symbol 80153988} */
  iVar2 = (**(code **)(*(int *)pDll_ObjSeq + 0x18))();
  (**(code **)(**(int **)(iVar2 + 4) + 0x20))
            (DAT_80399460,DAT_80399460 + 1,DAT_80399460 + 2,0,DAT_80399460 + 3);
  *(undefined *)(DAT_80399460 + 0x6e) = 0;
  local_70 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.x ^ 0x80000000);
  dVar6 = (double)distanceFn_80293e80((double)(((float)(local_70 - 4503601774854144.0) * 3.141593) /
                                              32767.0));
  uStack_74 = (int)(param1->pos).rotation.x ^ 0x80000000;
  local_78 = 0x43300000;
  dVar7 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_74) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  iVar2 = getAngle();
  sVar5 = (param1->pos).rotation.x - (short)iVar2;
  if (0x8000 < sVar5) {
    sVar5 = sVar5 + 1;
  }
  if (sVar5 < -0x8000) {
    sVar5 = sVar5 + -1;
  }
  if (sVar5 < 0) {
    sVar5 = -sVar5;
  }
  uStack_74 = (int)*(short *)param3 ^ 0x80000000;
  local_78 = 0x43300000;
  iVar2 = (int)((float)((double)CONCAT44(0x43300000,uStack_74) - 4503601774854144.0) * 182.04);
  local_70 = (double)(longlong)iVar2;
  if (sVar5 < (short)iVar2) {
    *(undefined *)(DAT_80399460 + 0x6e) = 1;
  }
  else {
    dVar10 = (double)(*DAT_80399460 * *DAT_80399460 - DAT_80399460[2] * DAT_80399460[2]);
    if (dVar10 < 5.0) {
      dVar10 = 5.0;
    }
    dVar10 = sqrt(dVar10);
    local_84.x = (float)(dVar6 * dVar10 + (double)(param1->pos).pos.x);
    local_84.y = DAT_80399460[2] + (param1->pos).pos.y + DAT_80399460[3];
    local_84.z = (float)(dVar7 * dVar10 + (double)(param1->pos).pos.z);
    if (*(char *)((int)param3 + 3) != '\0') {
      (param1->pos).pos.y = (param1->pos).pos.y + DAT_80399460[3];
      vec3f_toNearest10(&(param1->pos).pos,&vStack_a4);
      vec3f_toNearest10(&local_84,&vStack_ac);
      FUN_8006db28(afStack_9c,asStack_b4);
      dVar9 = (double)(local_84.x - (param1->pos).pos.x);
      fVar4 = local_84.y - (param1->pos).pos.y;
      dVar8 = (double)(local_84.z - (param1->pos).pos.z);
      dVar10 = sqrt((double)(float)(dVar8 * dVar8 +
                                   (double)(float)(dVar9 * dVar9 + (double)(fVar4 * fVar4))));
      if (dVar10 != 0.0) {
        dVar9 = (double)(float)(dVar9 * (double)(float)(1.0 / dVar10));
        dVar8 = (double)(float)(dVar8 * (double)(float)(1.0 / dVar10));
      }
      local_90 = -(float)(dVar9 * 20.0 - (double)(param1->pos).pos.x);
      local_88 = -(float)(dVar8 * 20.0 - (double)(param1->pos).pos.z);
      local_8c = local_84.y;
      local_e4[0] = 4.5;
      local_d4 = 0xff;
      local_d0 = 3;
      mathFn_8006961c(auStack_13c,&(param1->pos).pos.x,&local_84.x,local_e4,1);
      pListFn_800b50cc((int)param1,(int *)auStack_13c,1);
      FUN_800b6f6c((int)param1,(int)&local_90,(int)&local_84,1,(int)auStack_124,0);
      (param1->pos).pos.y = (param1->pos).pos.y - DAT_80399460[3];
    }
    for (local_b8 = 0.0; (int)local_b8 < 3; local_b8 = (float)((int)local_b8 + 1)) {
      DAT_80399460[(int)local_b8 + 6] = (this->pos).x;
      DAT_80399460[(int)local_b8 + 0x1a] = (this->pos).y;
      DAT_80399460[(int)local_b8 + 0x2e] = (this->pos).z;
    }
    fVar4 = (this->pos).x - local_84.x;
    fVar1 = (this->pos).z - local_84.z;
    dVar10 = sqrt((double)(fVar4 * fVar4 + fVar1 * fVar1));
    dVar10 = (double)(float)(dVar10 * 0.5);
    iVar2 = getAngle();
    uVar3 = getAngle();
    iVar2 = iVar2 - (uVar3 & 0xffff);
    if (0x8000 < (short)iVar2) {
      iVar2 = iVar2 + -0xffff;
    }
    if ((short)iVar2 < -0x8000) {
      iVar2 = iVar2 + 0xffff;
    }
    sVar5 = (short)iVar2;
    if (sVar5 < 0) {
      iVar2 = -iVar2;
    }
    if ((short)iVar2 < 0x4001) {
      iVar2 = 0x4000 - iVar2;
    }
    else {
      iVar2 = 0;
    }
    if (sVar5 < 0) {
      sVar5 = -(short)(iVar2 << 1);
    }
    else {
      sVar5 = (short)(iVar2 << 1);
    }
    if ((short)iVar2 == 0) {
      fVar4 = 0.0;
    }
    else {
      uStack_74 = (int)(short)iVar2 ^ 0x80000000;
      local_78 = 0x43300000;
      dVar8 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_74) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      fVar4 = (float)(dVar10 / dVar8);
    }
    DAT_80399460[0x68] = (float)(DAT_80399460 + 6);
    DAT_80399460[0x69] = (float)(DAT_80399460 + 0x1a);
    DAT_80399460[0x6a] = (float)(DAT_80399460 + 0x2e);
    DAT_80399460[0x6c] = (float)FUN_8006b9dc;
    DAT_80399460[0x6d] = (float)&LAB_8006bad0;
    FUN_801584cc(-(double)(float)(dVar6 * (double)fVar4 - (double)local_84.x),
                 -(double)(float)(dVar7 * (double)fVar4 - (double)local_84.z),(double)(this->pos).x,
                 (double)(this->pos).y,(double)(this->pos).z,(double)local_84.y,sVar5,0x1555,
                 (int *)&local_b8);
    for (fVar4 = local_b8; (int)fVar4 < (int)local_b8 + 3; fVar4 = (float)((int)fVar4 + 1)) {
      DAT_80399460[(int)fVar4 + 6] = local_84.x;
      DAT_80399460[(int)fVar4 + 0x1a] = local_84.y;
      DAT_80399460[(int)fVar4 + 0x2e] = local_84.z;
    }
    DAT_80399460[0x6b] = fVar4;
    DAT_80399460[0x67] = 0.0;
    curvesMove((Curve *)(DAT_80399460 + 0x47));
    if (sVar5 < 0) {
      sVar5 = -sVar5;
    }
    if ((0x1fff < sVar5) && (*(char *)((int)param3 + 2) != '\0')) {
      audioStartSfx((int **)0x0,0x14b,0x7f,0x40,"attention.c",0x128);
    }
                    /* {@symbol 80153e30} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x34))
              ((double)DAT_80399460[0x4a],0x4034000000000000,0x3fe0000000000000,0x3ff0000000000000,
               0xc024000000000000,DAT_80399460 + 0x42);
    DAT_80399460[4] = -100000.0;
    DAT_80399460[5] = 100000.0;
  }
  _restfpr_24();
  return;
}


void attentionCam_update(Camera *this) { //8015818C
  uint uVar1;
  int iVar2;
  ObjInstance *pOVar3;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined local_1c [4];
  undefined auStack_18 [4];
  undefined local_14 [4];
  
  if (*(char *)(DAT_80399460 + 0x1b8) == '\0') {
    pOVar3 = this[1].obj40;
    local_28 = (this->pos).y;
    uVar1 = FUN_801587b4(&local_2c,&local_28,&local_24,pOVar3);
    uVar1 = uVar1 & 0xff;
    (this->pos).x = local_2c;
    (this->pos).z = local_24;
                    /* {@symbol 80153988} */
    iVar2 = (**(code **)(*(int *)pDll_ObjSeq + 0x18))();
    (**(code **)(**(int **)(iVar2 + 4) + 0x24))(this,3,3,DAT_80399460 + 0x10,DAT_80399460 + 0x14);
    if (*(short *)&this[1].field_0x3c != 0) {
      *(float *)(DAT_80399460 + 0x118) = *(float *)(DAT_80399460 + 0x118) + timeDelta;
    }
    if (10.0 < *(float *)(DAT_80399460 + 0x118)) {
      FUN_801589c8((int)this,(short *)pOVar3);
      uVar1 = 1;
    }
                    /* {@symbol 80153e68} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x38))(0,this,local_14,auStack_18,local_1c,&local_20);
    FUN_80158728((ushort *)this);
    (**(code **)(**(int **)(iVar2 + 4) + 0x18))((double)(pOVar3->pos).pos.y,(double)local_20,this);
    if (uVar1 != 0) {
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0,0xff);
    }
    FUN_80158380((int)this,(int)pOVar3);
  }
  else {
                    /* {@symbol 801539f0} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0,0xff);
  }
  return;
}


void attentionCam_func05(Camera *this) { //80158358
  mm_free(DAT_80399460);
  return;
}


void attentionCam_func06(Camera *this) { //8015837C
  return;
}

