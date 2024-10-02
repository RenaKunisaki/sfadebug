
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void sfxplayer_initialise(undefined4 param) { //801D0F88
  return;
}


/* @description Called when DLL is unloaded */

void sfxplayer_release(void) { //801D0F8C
  return;
}


/* Library Function - Single Match
    dll_EF_func03
   
   Library: KioskDefault 0 0 */

void sfxplayer_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //801D0F90
  short sVar1;
  uint uVar2;
  ObjDef *pOVar3;
  float *pfVar4;
  
  pfVar4 = (float *)this->state;
  pOVar3 = this->def;
  uVar2 = mainGetBit((int)(short)objDef[1].objType);
  *(char *)(pfVar4 + 2) = (char)uVar2;
  if ((pOVar3[1].loadFlags & isLevelObject) != 0) {
    if ((*(char *)(pfVar4 + 2) == '\0') && ((pOVar3[1].loadFlags & OnlyLoadIfNearPlayer) != 0)) {
      *(undefined *)(pfVar4 + 2) = 1;
    }
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  *pfVar4 = (float)((double)CONCAT44(0x43300000,(uint)objDef[1].mapStates2 << 1 ^ 0x80000000) -
                   4503601774854144.0);
  pfVar4[1] = *pfVar4 + 10.0;
  *pfVar4 = *pfVar4 * *pfVar4;
  pfVar4[1] = pfVar4[1] * pfVar4[1];
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  if (sVar1 == 0) {
    objDef[1].bound = 1;
    objDef[1].cullDist = 0x2c;
  }
  return;
}


/* Library Function - Single Match
    dll_EF_func04
   
   Library: KioskDefault 0 0 */

void sfxplayer_update(ObjInstance *this) { //801D1074
  ushort param3;
  ushort param3_00;
  ushort uVar1;
  ushort param3_01;
  ushort param3_02;
  ushort param3_03;
  uint uVar2;
  ObjInstance *pOVar3;
  bool bVar5;
  int iVar4;
  float *pfVar6;
  uint uVar7;
  ObjDef *pOVar8;
  double dVar9;
  
  pfVar6 = (float *)this->state;
  pOVar8 = this->def;
  uVar7 = 0;
  if (pOVar8[1].objType != Sabre) {
    uVar7 = mainGetBit((int)(short)pOVar8[1].objType);
    uVar7 = uVar7 & 0xff;
  }
  if ((pOVar8[1].loadFlags & isLevelObject) == 0) {
    if ((pOVar8[1].loadFlags & AllocatedByCode) == 0) {
      if (uVar7 != *(byte *)(pfVar6 + 2)) {
        if ((uVar7 == 1) && ((pOVar8[1].loadFlags & isManualLoad) != 0)) {
          param3_02._0_1_ = pOVar8[1].allocatedSize;
          param3_02._1_1_ = pOVar8[1].mapStates1;
          audioTryStartSfx((int *)this,1,param3_02,0x7f,(char *)&PTR_DAT_80311120,0x6a);
        }
        else if ((uVar7 == 0) && ((pOVar8[1].loadFlags & OnlyLoadIfNearPlayer) != 0)) {
          param3_03._0_1_ = pOVar8[1].allocatedSize;
          param3_03._1_1_ = pOVar8[1].mapStates1;
          audioTryStartSfx((int *)this,1,param3_03,0x7f,(char *)&PTR_DAT_80311120,0x6d);
        }
      }
    }
    else {
      pOVar3 = Object_objGetMain();
      dVar9 = (double)objDistSqObj2Obj(this,pOVar3);
      uVar1._0_1_ = pOVar8[1].bound;
      uVar1._1_1_ = pOVar8[1].cullDist;
      iVar4 = randInt(0,(uint)uVar1);
      if ((iVar4 == 0) && (dVar9 < (double)*pfVar6)) {
        param3_01._0_1_ = pOVar8[1].allocatedSize;
        param3_01._1_1_ = pOVar8[1].mapStates1;
        audioTryStartSfx((int *)this,1,param3_01,0x7f,(char *)&PTR_DAT_80311120,100);
      }
    }
  }
  else if (pOVar8[1].objType == None) {
    if ((pOVar8[1].loadFlags & (isManualLoad|OnlyLoadIfNearPlayer)) != 0) {
      pOVar3 = Object_objGetMain();
      dVar9 = (double)objDistSqObj2Obj(this,pOVar3);
      if (((double)*pfVar6 <= dVar9) || (bVar5 = FUN_80068b20((int)this,1), bVar5)) {
        if ((double)pfVar6[1] < dVar9) {
          FUN_80068a9c((uint)this,1);
        }
      }
      else {
        param3_00._0_1_ = pOVar8[1].allocatedSize;
        param3_00._1_1_ = pOVar8[1].mapStates1;
        audioTryStartSfx((int *)this,1,param3_00,0x7f,(char *)&PTR_DAT_80311120,0x5a);
      }
    }
  }
  else if (uVar7 != *(byte *)(pfVar6 + 2)) {
    if ((pOVar8[1].loadFlags & (isManualLoad|OnlyLoadIfNearPlayer)) != 0) {
      uVar2 = countLeadingZeros(4 - (pOVar8[1].loadFlags & 4));
      if (uVar2 >> 5 == uVar7) {
        FUN_80068a9c((uint)this,1);
      }
      else {
        param3._0_1_ = pOVar8[1].allocatedSize;
        param3._1_1_ = pOVar8[1].mapStates1;
        audioTryStartSfx((int *)this,1,param3,0x7f,(char *)&PTR_DAT_80311120,0x4e);
      }
    }
  }
  *(char *)(pfVar6 + 2) = (char)uVar7;
  return;
}


/* @description Override hit detection */

void sfxplayer_hitDetect(ObjInstance *this) { //801D12D4
  return;
}


/* Library Function - Single Match
    dll_EF_func06
   
   Library: KioskDefault 0 0 */

void sfxplayer_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //801D12D8
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar1;
  double dVar2;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  pfVar1 = (float *)this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (((this->pos).flags & 0x100) != 0) {
      dVar2 = sqrt((double)*pfVar1);
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   dVar2,30.0,param2_00,param3_00,0xff,0xff,0xff);
      dVar2 = sqrt((double)pfVar1[1]);
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   dVar2,15.0,param2_00,param3_00,0xcc,0xcc,0xcc);
    }
  }
  return;
}


/* @description Free object instance */

void sfxplayer_free(ObjInstance *this,int param2) { //801D13B4
  return;
}


undefined4 sfxplayer_func08(ObjInstance *this) { //801D13B8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int sfxplayer_getExtraSize(void) { //801D13C0
  return 0xc;
}

