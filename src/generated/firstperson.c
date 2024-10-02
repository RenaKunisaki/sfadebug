
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void cam1stperson_initialise(undefined4 param) { //8015912C
  return;
}


/* @description Called when DLL is unloaded */

void cam1stperson_release(void) { //80159130
  return;
}


/* @description Set up object instance */

void cam1stperson_init(Camera *this,int mode,undefined *param3,DllInitFlags flags,float x,float y,
                       float z) { //80159134
  int iVar1;
  ObjInstance *param1;
  short sVar2;
  short sVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  _savefpr_25();
  param1 = this[1].obj40;
  DAT_80399470 = (undefined4 *)mmAlloc(0x124,CAM_COL,(char *)&PTR_DAT_80302108);
  *DAT_80399470 = *(undefined4 *)param3;
  DAT_80399470[0x45] =
       (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)param3 + 8)) - 4503599627370496.0)
  ;
  DAT_80399470[1] = *(undefined4 *)((int)param3 + 4);
  DAT_80399470[0x47] = 0.0;
  sVar2 = (-0x8000 - (this->rot).x) - (param1->pos).rotation.x;
  sVar3 = sVar2;
  if (sVar2 < 0) {
    sVar3 = -sVar2;
  }
  dVar7 = (double)((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0
                          ) / 50.0);
  dVar6 = (double)((float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0
                          ) / 90.0);
  DAT_80399470[0x3f] = DAT_80399470 + 4;
  DAT_80399470[0x40] = DAT_80399470 + 8;
  DAT_80399470[0x41] = DAT_80399470 + 0xc;
  DAT_80399470[0x42] = 4;
  DAT_80399470[0x3e] = 0;
  DAT_80399470[0x43] = FUN_8006bba0;
  DAT_80399470[0x44] = curveFn_80010d54;
  dVar9 = (double)((this->pos).x - (param1->pos).pos.x);
  dVar8 = (double)((this->pos).z - (param1->pos).pos.z);
  dVar4 = sqrt((double)(float)(dVar9 * dVar9 + (double)(float)(dVar8 * dVar8)));
  if (dVar4 != 0.0) {
    dVar9 = (double)(float)(dVar9 / dVar4);
    dVar8 = (double)(float)(dVar8 / dVar4);
  }
  dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(param1->pos).rotation
                                                                              .x ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  dVar4 = -dVar4;
  dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)(param1->pos).rotation.x ^
                                                                     0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  DAT_80399470[4] = (this->pos).x;
  DAT_80399470[5] = (param1->pos).pos.x;
  DAT_80399470[6] = (float)(-dVar8 * dVar7);
  DAT_80399470[7] = (float)(dVar4 * dVar6);
  DAT_80399470[8] = (this->pos).y;
  DAT_80399470[9] = (param1->pos).pos.y + 27.0;
  DAT_80399470[10] = 0.0;
  DAT_80399470[0xb] = 0.0;
  DAT_80399470[0xc] = (this->pos).z;
  DAT_80399470[0xd] = (param1->pos).pos.z;
  DAT_80399470[0xe] = (float)(dVar9 * dVar7);
  DAT_80399470[0xf] = (float)(-dVar5 * dVar6);
  DAT_80399470[6] = 0.0;
  DAT_80399470[7] = 0.0;
  DAT_80399470[10] = 0.0;
  DAT_80399470[0xb] = 0.0;
  DAT_80399470[0xe] = 0.0;
  DAT_80399470[0xf] = 0.0;
  curvesMove((Curve *)(DAT_80399470 + 0x1e));
  iVar1 = getAngle();
  sVar3 = (this->rot).x - (-0x8000 - (short)iVar1);
  if (0x8000 < sVar3) {
    sVar3 = sVar3 + 1;
  }
  if (sVar3 < -0x8000) {
    sVar3 = sVar3 + -1;
  }
  DAT_80399470[0x10] =
       (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0);
  DAT_80399470[0x11] = 0.0;
  DAT_80399470[0x12] = 0.0;
  DAT_80399470[0x13] = 0.0;
  if ((32768.0 < (float)DAT_80399470[0x10] - (float)DAT_80399470[0x11]) ||
     ((float)DAT_80399470[0x10] - (float)DAT_80399470[0x11] < -32768.0)) {
    if (0.0 <= (float)DAT_80399470[0x10]) {
      if ((float)DAT_80399470[0x11] < 0.0) {
        DAT_80399470[0x11] = (float)DAT_80399470[0x11] + 65535.0;
      }
    }
    else {
      DAT_80399470[0x10] = (float)DAT_80399470[0x10] + 65535.0;
    }
  }
  DAT_80399470[0x14] =
       (float)((double)CONCAT44(0x43300000,(int)(this->rot).y ^ 0x80000000) - 4503601774854144.0);
  DAT_80399470[0x15] = 0.0;
  DAT_80399470[0x16] = 0.0;
  DAT_80399470[0x17] = 0.0;
  if (mode == 1) {
    *(undefined *)(DAT_80399470 + 0x48) = 5;
  }
  else {
    *(undefined *)(DAT_80399470 + 0x48) = 0;
    audioTryStartSfx((int *)param1,1,0x14b,0x7f,"firstperson.c",0xca);
  }
  this[2].field_0x5c = 1;
  _restfpr_25();
  return;
}


void cam1stperson_update(Camera *this) { //80159648
  byte bVar1;
  float fVar2;
  float fVar3;
  undefined uVar6;
  u16 uVar5;
  int iVar4;
  ObjInstance *pOVar7;
  double dVar8;
  double local_38;
  
  _savefpr_28();
  pOVar7 = this[1].obj40;
  this[2].field_0x5e = this[2].field_0x5e | 2;
  n64GetEnabledButtonsPressed(0);
  bVar1 = *(byte *)(DAT_80399470 + 0x120);
  if (bVar1 == 3) {
    iVar4 = FUN_8006c2c8(1000.0,(float *)(DAT_80399470 + 0x78));
    (this->rot).x = (short)(int)*(float *)(DAT_80399470 + 0xe0);
    (this->rot).y = (short)(int)*(float *)(DAT_80399470 + 0xe4);
    if (iVar4 != 0) {
      FUN_8015a604((int)this);
      *(undefined *)(DAT_80399470 + 0x120) = 4;
    }
    this[2].field_0x5c = 1;
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      iVar4 = FUN_8006c2c8(1000.0,(float *)(DAT_80399470 + 0x78));
      if (iVar4 != 0) {
        *(float *)(DAT_80399470 + 8) = (this->pos).x - ((this[1].obj40)->pos).pos.x;
        *(float *)(DAT_80399470 + 0xc) = (this->pos).z - ((this[1].obj40)->pos).pos.z;
        *(undefined *)(DAT_80399470 + 0x120) = 2;
      }
      (this->rot).x = (short)(int)*(float *)(DAT_80399470 + 0xe0);
      this[2].field_0x5c = 1;
    }
    else if (bVar1 == 0) {
      if (true) {
        uVar6 = FUN_80159b08((short *)this,(short *)this[1].obj40);
        *(undefined *)(DAT_80399470 + 0x120) = uVar6;
        this[2].field_0x5c = 1;
      }
    }
    else {
      FUN_80159e30((short *)this);
      uVar5 = getEnabledButtonsPressed(0);
      if ((uVar5 & 0x240) != 0) {
        FUN_8015a07c((short *)this);
        *(undefined *)(DAT_80399470 + 0x120) = 3;
      }
      this[2].field_0x5c = 0;
    }
  }
  else if (bVar1 == 5) {
    (this->rot).x = -0x8000 - (pOVar7->pos).rotation.x;
    local_38 = (double)CONCAT44(0x43300000,(int)(pOVar7->pos).rotation.y ^ 0x80000000);
    (this->rot).y =
         (short)(int)(*(float *)(DAT_80399470 + 0x114) * 182.0 +
                     (float)(local_38 - 4503601774854144.0));
    (this->rot).z = (pOVar7->pos).rotation.z;
    (this->pos).x = (pOVar7->prevPos).x;
    (this->pos).y = (pOVar7->prevPos).y + *(float *)(DAT_80399470 + 4);
    (this->pos).z = (pOVar7->prevPos).z;
    *(float *)&this[1].prevRot = 80.0;
  }
  else if (bVar1 < 5) {
    fVar2 = *(float *)(DAT_80399470 + 0x78) - 0.2;
    if (fVar2 < 0.0) {
      fVar2 = 0.0;
    }
    (this[1].obj40)->newOpacity = (u8)(int)(fVar2 * 1.25 * 255.0);
    iVar4 = FUN_8006c2c8(5.0,(float *)(DAT_80399470 + 0x78));
    if (iVar4 != 0) {
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0,0xff);
      (this[1].obj40)->newOpacity = 0xff;
    }
    (this->pos).x = *(float *)(DAT_80399470 + 0xe0);
    (this->pos).z = *(float *)(DAT_80399470 + 0xe8);
                    /* {@symbol 80153988} */
    iVar4 = (**(code **)(*(int *)pDll_ObjSeq + 0x18))();
    (**(code **)(**(int **)(iVar4 + 4) + 0x24))(this,2,3,DAT_80399470 + 0x70,DAT_80399470 + 0x74);
    (**(code **)(**(int **)(iVar4 + 4) + 0x1c))
              ((double)*(float *)(DAT_80399470 + 0x70),(double)*(float *)(DAT_80399470 + 0x74),this,
               this[1].obj40);
    fVar2 = (this->pos).x - ((this[1].obj40)->pos).pos.x;
    fVar3 = (this->pos).z - ((this[1].obj40)->pos).pos.z;
    dVar8 = (double)(fVar2 * fVar2 + fVar3 * fVar3);
    if (100.0 <= dVar8) {
      dVar8 = sqrt(dVar8);
      (**(code **)(**(int **)(iVar4 + 4) + 0x18))((double)((this[1].obj40)->pos).pos.y,dVar8,this);
    }
    else {
      (this->rot).y = 0;
    }
    this[2].field_0x5c = 1;
  }
  iVar4 = FUN_800883e4((int)this[1].obj40,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar4 != 0) {
    FUN_8015a07c((short *)this);
    (this->pos).x = *(float *)(DAT_80399470 + 0x14);
    (this->pos).y = *(float *)(DAT_80399470 + 0x24);
    (this->pos).z = *(float *)(DAT_80399470 + 0x34);
                    /* {@symbol 801539f0} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0,0);
  }
  _restfpr_28();
  return;
}


void cam1stperson_func05(Camera *this) { //80159AB8
  ((this[1].obj40)->pos).flags = ((this[1].obj40)->pos).flags & 0xfdff;
  (this[1].obj40)->newOpacity = 0xff;
  mm_free(DAT_80399470);
  return;
}


void cam1stperson_func06(Camera *this) { //80159B04
  return;
}

