
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRpushcart_initialise(undefined4 param) { //802B0E2C
  return;
}


/* @description Called when DLL is unloaded */

void DRpushcart_release(void) { //802B0E30
  return;
}


/* Library Function - Single Match
    dll_2AA_func03
   
   Library: KioskDefault 0 0 */

void DRpushcart_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802B0E34
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *(float *)(puVar3 + 0x114) =
       (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  *(float *)(puVar3 + 0x10c) = 0.0;
  uVar2 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  puVar3[0x158] = (byte)(uVar2 << 5) & 0x20 | puVar3[0x158] & 0xdf;
  puVar3[0x158] = puVar3[0x158] & 0xdf | 0x20;
  puVar3[0x159] = puVar3[0x159] & 0xdf | 0x20;
  mainSetBits(0x649,1);
  if (obj2 == (ObjInstance *)0x0) {
    uVar2 = mainGetBit(0x683);
    FUN_802b1e58(this,uVar2);
  }
  return;
}


/* Library Function - Single Match
    dll_2AA_func04
   
   Library: KioskDefault 0 0 */

void DRpushcart_update(ObjInstance *this) { //802B0F08
  float fVar1;
  ObjInstance *pOVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  ObjDef *pOVar6;
  float *pfVar7;
  double dVar8;
  double dVar9;
  int local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  _savefpr_28();
  pfVar7 = (float *)this->state;
  pOVar6 = this->def;
  pOVar2 = Object_objGetMain();
  if ((*(byte *)((int)pfVar7 + 0x159) >> 5 & 1) != 0) {
    FUN_802b2fa8((int)this,pfVar7);
    *(byte *)((int)pfVar7 + 0x159) = *(byte *)((int)pfVar7 + 0x159) & 0xdf;
  }
  if (-1 < *(char *)((int)pfVar7 + 0x159)) {
    fVar3 = (float)FUN_802b1884((int)this,0x23b);
    pfVar7[0x42] = fVar3;
    *(float *)((int)pfVar7[0x42] + 0x24) = 0.0;
    *(float *)((int)pfVar7[0x42] + 0x28) = 0.0;
    *(float *)((int)pfVar7[0x42] + 0x2c) = 0.0;
    *(byte *)((int)pfVar7 + 0x159) = *(byte *)((int)pfVar7 + 0x159) & 0x7f | 0x80;
  }
  iVar4 = FUN_802b1f78((int)this);
  if (iVar4 == 0) {
    FUN_802b1da8(this,(byte *)(pfVar7 + 0x53));
    if ((*(byte *)(pfVar7 + 0x56) >> 5 & 1) == 0) {
      uVar5 = mainGetBit((int)*(short *)&pOVar6[1].pos.x);
      *(byte *)(pfVar7 + 0x56) = (byte)(uVar5 << 5) & 0x20 | *(byte *)(pfVar7 + 0x56) & 0xdf;
      pfVar7[0x44] = 0.0;
    }
    else {
      sqrt((double)(pfVar7[0x1d] * pfVar7[0x1d] + pfVar7[0x1f] * pfVar7[0x1f]));
      iVar4 = getAngle();
      uStack_3c = (int)(short)iVar4 ^ 0x80000000;
      local_40 = 0x43300000;
      dVar8 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_3c) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      dVar9 = (double)(float)(dVar8 * -0.699999988079071);
      uStack_44 = (int)(short)iVar4 ^ 0x80000000;
      local_48 = 0x43300000;
      dVar8 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_44) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      fVar3 = (float)(dVar8 * 0.699999988079071) * 0.1;
      if (((*(byte *)(pfVar7 + 0x56) >> 6 & 1) != 0) &&
         ((pfVar7[0x46] + 2.0 < pfVar7[0x43] || (pfVar7[0x43] < pfVar7[0x46] - 2.0)))) {
        fVar3 = fVar3 + 2.0;
      }
      if ((*(byte *)(pfVar7 + 0x56) >> 1 & 0xf) != 0) {
        fVar3 = fVar3 + 2.0;
      }
      pfVar7[0x43] = pfVar7[0x44] + (float)((double)pfVar7[0x43] + dVar9);
      if (pfVar7[0x43] < 0.0) {
        fVar1 = -pfVar7[0x43];
      }
      else {
        fVar1 = pfVar7[0x43];
      }
      if (fVar3 <= fVar1) {
        if (pfVar7[0x46] < pfVar7[0x43]) {
          fVar3 = -fVar3;
        }
        pfVar7[0x43] = pfVar7[0x43] + fVar3;
      }
      else {
        pfVar7[0x43] = pfVar7[0x46];
      }
      if (0.0 <= pfVar7[0x43]) {
                    /* {@symbol 801297ec} */
        (**(code **)(*(int *)pDll_RomCurve + 0x94))(pfVar7,0);
      }
      else {
                    /* {@symbol 801297ec} */
        (**(code **)(*(int *)pDll_RomCurve + 0x94))(pfVar7,1);
      }
      pfVar7[0x44] = 0.0;
      if (pfVar7[0x43] == 0.0) {
        objHitFn_80089114(this);
        FUN_80068a9c((uint)this,8);
      }
      else {
        if (pfVar7[0x43] < 0.0) {
          fVar3 = -pfVar7[0x43];
        }
        else {
          fVar3 = pfVar7[0x43];
        }
        if ((fVar3 <= 0.2) || (pOVar2->pMatrix == this)) {
          FUN_800bac34(0x14,(int)this->pMatrix,1);
        }
        else if ((*(byte *)(pfVar7 + 0x56) >> 6 & 1) != 0) {
          objHitFn_80089074(this,0xb,1,-1);
          FUN_800bac34(0x14,(int)this->pMatrix,0);
          (this->hitstate->field12_0x3c).y = 1.053776e-42;
          (this->hitstate->field12_0x3c).z = 1.053776e-42;
        }
        FUN_8006c2c8((double)pfVar7[0x43],pfVar7);
        if ((((pfVar7[0x20] == 0.0) && (pfVar7[4] != 0.0)) ||
            ((pfVar7[0x20] != 0.0 && (pfVar7[4] == 0.0)))) &&
           (iVar4 = FUN_802b1910(this,*(undefined *)((int)pfVar7[0x28] + 0x18),
                                 *(byte *)((int)pfVar7[0x29] + 0x18),&local_4c), iVar4 != 0)) {
          curveFn_800da23c(pfVar7,local_4c);
        }
        sqrt((double)(pfVar7[0x1d] * pfVar7[0x1d] + pfVar7[0x1f] * pfVar7[0x1f]));
        iVar4 = getAngle();
        (this->pos).rotation.x = (short)iVar4;
        (this->pos).rotation.y = 0;
        (this->pos).pos.x = pfVar7[0x1a];
        (this->pos).pos.y = pfVar7[0x1b];
        (this->pos).pos.z = pfVar7[0x1c];
        (this->pos).pos.y = (this->pos).pos.y + 3.0;
        audioTryStartSfx((int *)this,8,0x1df,0x7f,"DRpushcart.c",0x12f);
        objRomDefMove_800af9d8
                  ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   this->def,(short)(char)this->mapId);
      }
    }
  }
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    dll_2AA_func05
   
   Library: KioskDefault 0 0 */

void DRpushcart_hitDetect(ObjInstance *this) { //802B1400
  int iVar1;
  
  iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar1 == 5) {
    mainSetBits(0x822,0);
    mainSetBits(0x823,0);
    mainSetBits(0x824,0);
    mainSetBits(0x825,0);
    mainSetBits(0x826,0);
    mainSetBits(0x827,0);
  }
  return;
}


/* Library Function - Single Match
    dll_2AA_func06
   
   Library: KioskDefault 0 0 */

void DRpushcart_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //802B1490
  float fVar1;
  float fVar2;
  int idx;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined auStack_30 [8];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  double local_18;
  
  puVar5 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (((byte)puVar5[0x158] >> 5 & 1) != 0) {
      local_28 = 8.0;
      if (*(float *)(puVar5 + 0x10c) / 0.8 < 0.0) {
        fVar1 = -(*(float *)(puVar5 + 0x10c) / 0.8);
      }
      else {
        fVar1 = *(float *)(puVar5 + 0x10c) / 0.8;
      }
      uVar4 = (uint)fVar1;
      local_18 = (double)(longlong)(int)uVar4;
      if ((int)uVar4 < 0) {
        uVar4 = 0;
      }
      else if (6 < (int)uVar4) {
        uVar4 = 6;
      }
      for (iVar3 = 0; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
        idx = randInt(0,3);
        objGetAttachPointWorldPos(this,idx,&local_24,&local_20,&local_1c,FALSE);
        local_24 = local_24 - (this->pos).pos.x;
        local_20 = local_20 - (this->pos).pos.y;
        local_1c = local_1c - (this->pos).pos.z;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x678,auStack_30,2,0xffffffff,0);
      }
      if (*(int *)(puVar5 + 0x108) != 0) {
        local_18 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
        (**(code **)(**(int **)(*(int *)(puVar5 + 0x108) + 0x68) + 0x24))
                  ((double)((float)(local_18 - 4503601774854144.0) * 30.0),
                   *(undefined4 *)(puVar5 + 0x108));
        if (uVar4 == 0) {
          *(float *)(*(int *)(puVar5 + 0x108) + 0xc) = (this->pos).pos.x;
          *(float *)(*(int *)(puVar5 + 0x108) + 0x10) = (this->pos).pos.y;
          *(float *)(*(int *)(puVar5 + 0x108) + 0x14) = (this->pos).pos.z;
        }
        else {
          fVar1 = (this->pos).pos.y;
          fVar2 = (this->pos).pos.z;
          *(float *)(*(int *)(puVar5 + 0x108) + 0xc) = local_24 + (this->pos).pos.x;
          *(float *)(*(int *)(puVar5 + 0x108) + 0x10) = local_20 + fVar1;
          *(float *)(*(int *)(puVar5 + 0x108) + 0x14) = local_1c + fVar2;
        }
      }
    }
  }
  else if (*(int *)(puVar5 + 0x108) != 0) {
    *(float *)(*(int *)(puVar5 + 0x108) + 0xc) = (this->pos).pos.x;
    *(float *)(*(int *)(puVar5 + 0x108) + 0x10) = (this->pos).pos.y;
    *(float *)(*(int *)(puVar5 + 0x108) + 0x14) = (this->pos).pos.z;
  }
  return;
}


/* Library Function - Single Match
    dll_2AA_func07
   
   Library: KioskDefault 0 0 */

void DRpushcart_free(ObjInstance *this,int param2) { //802B170C
  undefined *puVar1;
  
  puVar1 = this->state;
  mainSetBits(0x683,(uint)(byte)puVar1[0x14c]);
  if ((param2 == 0) && (*(int *)(puVar1 + 0x108) != 0)) {
    Object_objFreeObject(*(ObjInstance **)(puVar1 + 0x108));
    *(undefined4 *)(puVar1 + 0x108) = 0;
  }
  return;
}


undefined4 DRpushcart_func08(ObjInstance *this) { //802B1774
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRpushcart_getExtraSize(void) { //802B177C
  return 0x15c;
}


/* Library Function - Single Match
    dll_2AA_func0A
   
   Library: KioskDefault 0 0 */

void DRpushcart_setScale(ObjInstance *this,float scale) { //802B1784
  float fVar1;
  short *in_r4;
  undefined *puVar2;
  short sVar3;
  undefined4 in_register_00004008;
  double dVar4;
  double in_f31;
  
  dVar4 = (double)CONCAT44(in_register_00004008,scale);
  _savefpr_30();
  puVar2 = this->state;
  if (*(float *)(puVar2 + 0x114) != 0.0) {
    in_f31 = (double)((float)dVar4 / *(float *)(puVar2 + 0x114));
  }
  sVar3 = (this->pos).rotation.x - *in_r4;
  if (0x8000 < sVar3) {
    sVar3 = sVar3 + 1;
  }
  if (sVar3 < -0x8000) {
    sVar3 = sVar3 + -1;
  }
  dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)sVar3 ^ 0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  if (0.0 <= -dVar4) {
    fVar1 = 1.0;
  }
  else {
    fVar1 = -1.0;
  }
  *(float *)(puVar2 + 0x110) = (float)(in_f31 * (double)fVar1);
  _restfpr_30();
  return;
}

