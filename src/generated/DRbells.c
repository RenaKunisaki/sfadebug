
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRbells_initialise(undefined4 param) { //802BA094
  return;
}


/* @description Called when DLL is unloaded */

void DRbells_release(void) { //802BA098
  return;
}


/* Library Function - Single Match
    dll_2B8_func03
   
   Library: KioskDefault 0 0 */

void DRbells_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //802BA09C
  undefined2 *puVar1;
  float local_14 [2];
  
  puVar1 = (undefined2 *)this->state;
  local_14[0] = 500.0;
  *puVar1 = 0xffff;
  puVar1[1] = (short)*(char *)((int)&objDef[1].objType + 1);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->flags_0xb0 = this->flags_0xb0 | DontUseRenderCallback;
  if (DAT_8039a16c == (ObjInstance *)0x0) {
    DAT_8039a16c = objDistFn_800920b4(this,0x484,local_14);
  }
  return;
}


/* Library Function - Single Match
    dll_2B8_func04
   
   Library: KioskDefault 0 0 */

void DRbells_update(ObjInstance *this) { //802BA128
  int iVar1;
  short sVar2;
  ushort uVar3;
  undefined2 *puVar4;
  bool bVar5;
  ObjDef *pOVar6;
  short *psVar7;
  double dVar8;
  float local_34;
  double local_30;
  undefined4 local_28;
  uint uStack_24;
  double local_20;
  
  psVar7 = (short *)this->state;
  pOVar6 = this->def;
  local_34 = 1000.0;
  if (*psVar7 == -1) {
    FUN_80068a9c((uint)this,(byte)psVar7[1]);
    psVar7 = (short *)objGetJoint((int)this,0);
    if ((psVar7 != (short *)0x0) && (*psVar7 != 0)) {
      *psVar7 = *psVar7 >> 1;
    }
    if (DAT_8039a169 != '\0') {
      DAT_8039a169 = DAT_8039a169 + -1;
    }
  }
  else {
    if (DAT_8039a169 != '\0') {
      *psVar7 = -1;
      DAT_8039a169 = DAT_8039a169 + -1;
      DAT_8039a168 = DAT_8039a168 + -1;
      if (DAT_8039a16c == (ObjInstance *)0x0) {
        return;
      }
      DAT_8039a16c->flags_0xaf = DAT_8039a16c->flags_0xaf & ~ModelDisableFlag08;
      return;
    }
    puVar4 = (undefined2 *)objGetJoint((int)this,0);
    if (puVar4 != (undefined2 *)0x0) {
      local_20 = (double)CONCAT44(0x43300000,(int)*psVar7 << 9 ^ 0x80000000);
      dVar8 = (double)distanceFn_80293e80((double)(((float)(local_20 - 4503601774854144.0) *
                                                   3.141593) / 32767.0));
      uStack_24 = *psVar7 * 6 ^ 0x80000000;
      local_28 = 0x43300000;
      iVar1 = (int)((double)(float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) *
                   dVar8);
      local_30 = (double)(longlong)iVar1;
      *puVar4 = (short)iVar1;
    }
    bVar5 = FUN_80068b20((int)this,(byte)psVar7[1]);
    if (!bVar5) {
      local_30 = (double)CONCAT44(0x43300000,(int)*psVar7 ^ 0x80000000);
      sVar2._0_1_ = pOVar6[1].allocatedSize;
      sVar2._1_1_ = pOVar6[1].mapStates1;
      uStack_24 = (int)sVar2 ^ 0x80000000;
      local_28 = 0x43300000;
      iVar1 = (int)(((float)(local_30 - 4503601774854144.0) /
                    (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0)) * 63.0 +
                   64.0);
      local_20 = (double)(longlong)iVar1;
      audioTryStartSfx((int *)this,(byte)psVar7[1],
                       *(ushort *)((int)&PTR_DAT_803981d8 + psVar7[1] * 2),(byte)iVar1,
                       (char *)&PTR_DAT_80323e48,0x77);
    }
    sVar2 = *psVar7;
    uVar3 = (ushort)framesThisStep;
    *psVar7 = sVar2 - uVar3;
    if ((short)(sVar2 - uVar3) < 0) {
      *psVar7 = -1;
      if (DAT_8039a16c != (ObjInstance *)0x0) {
        DAT_8039a16c->flags_0xaf = DAT_8039a16c->flags_0xaf & ~ModelDisableFlag08;
      }
      DAT_8039a168 = DAT_8039a168 + -1;
    }
  }
  if (DAT_8039a16c == (ObjInstance *)0x0) {
    DAT_8039a16c = objDistFn_800920b4(this,0x484,&local_34);
  }
  return;
}


/* Library Function - Single Match
    dll_2B8_func05
   
   Library: KioskDefault 0 0 */

void DRbells_hitDetect(ObjInstance *this) { //802BA3C0
  short sVar1;
  int iVar2;
  ObjDef *pOVar3;
  undefined2 *puVar4;
  uint uStack_14;
  
  pOVar3 = this->def;
  puVar4 = (undefined2 *)this->state;
  iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,&uStack_14);
  if (iVar2 != 0) {
    if ((puVar4[1] == (ushort)DAT_8039a168) || ((int)(short)puVar4[1] == DAT_8039a168 - 1)) {
      DAT_8039a168 = (char)puVar4[1] + 1;
      audioTryStartSfx((int *)this,(byte)puVar4[1],
                       *(ushort *)((int)&PTR_DAT_803981d8 + (short)puVar4[1] * 2),0x7f,
                       (char *)&PTR_DAT_80323e48,0xa1);
      if (DAT_8039a168 == 4) {
        sVar1._0_1_ = pOVar3[1].bound;
        sVar1._1_1_ = pOVar3[1].cullDist;
        mainSetBits((int)sVar1,1);
      }
      *puVar4 = *(undefined2 *)&pOVar3[1].allocatedSize;
      if (DAT_8039a16c != 0) {
        *(byte *)(DAT_8039a16c + 0xaf) = *(byte *)(DAT_8039a16c + 0xaf) | 8;
      }
    }
    else {
      DAT_8039a169 = 4;
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x32,0x7f,(char *)&PTR_DAT_80323e48,(int *)0xa8)
      ;
    }
    this->newOpacity = 0xfd;
  }
  return;
}


/* @description Override render */

void DRbells_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //802BA4EC
  return;
}


/* @description Free object instance */

void DRbells_free(ObjInstance *this,int param2) { //802BA4F0
  return;
}


undefined4 DRbells_func08(ObjInstance *this) { //802BA4F4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRbells_getExtraSize(void) { //802BA4FC
  return 4;
}

