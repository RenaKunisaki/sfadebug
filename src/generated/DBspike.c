
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBspike_initialise(undefined4 param) { //80293B20
  return;
}


/* @description Called when DLL is unloaded */

void DBspike_release(void) { //80293B24
  return;
}


/* Library Function - Single Match
    dll_26E_func03
   
   Library: KioskDefault 0 0 */

void DBspike_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //80293B28
  undefined *puVar1;
  
  puVar1 = this->state;
  (this->pos).rotation.z = (short)((int)*(char *)&objDef[1].objType << 8);
  (this->pos).rotation.x = *(short *)&objDef[1].allocatedSize;
  puVar1[8] = 200;
  *(short *)(puVar1 + 4) = (this->pos).rotation.z;
  puVar1[6] = 0;
  puVar1[7] = 0;
  FUN_80088d3c((int)this);
  return;
}


/* Library Function - Single Match
    dll_26E_func04
   
   Library: KioskDefault 0 0 */

void DBspike_update(ObjInstance *this) { //80293B9C
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  char cVar5;
  uint uVar6;
  ObjDef *pOVar7;
  undefined *puVar8;
  
  puVar8 = this->state;
  pOVar7 = this->def;
  if ((puVar8[7] & 1) == 0) {
    if ((this->pos).rotation.z != *(short *)(puVar8 + 4)) {
      (this->pos).rotation.z =
           (short)((int)*(short *)(puVar8 + 4) + (int)(this->pos).rotation.z >> 1);
    }
    if (this->curModel != 0) {
      cVar5 = puVar8[8] - framesThisStep;
      puVar8[8] = cVar5;
      if (cVar5 < '\0') {
        objSetModelNo(this,0);
      }
    }
    sVar1._0_1_ = pOVar7[1].bound;
    sVar1._1_1_ = pOVar7[1].cullDist;
    uVar6 = mainGetBit((int)sVar1);
    if ((byte)puVar8[6] != uVar6) {
      sVar2._0_1_ = pOVar7[1].bound;
      sVar2._1_1_ = pOVar7[1].cullDist;
      uVar6 = mainGetBit((int)sVar2);
      puVar8[6] = (char)uVar6;
      puVar8[7] = puVar8[7] | 1;
      *(short *)(puVar8 + 4) =
           (this->pos).rotation.z + *(short *)(&DAT_80398038 + (uint)(byte)puVar8[6] * 2);
      if (puVar8[6] == '\0') {
        audioTryStartSfx((int *)this,2,0x82,0x7f,(char *)&PTR_DAT_80321118,0x6f);
      }
      else {
        objSetModelNo(this,1);
        puVar8[8] = 200;
        audioTryStartSfx((int *)this,1,0x200,0x7f,(char *)&PTR_DAT_80321118,0x6d);
      }
    }
  }
  else {
    objHitFn_80089074(this,8,1,0);
    objHitFn_80089074(this,8,1,1);
    (this->pos).rotation.z =
         (this->pos).rotation.z + *(short *)(&DAT_8039803c + (uint)(byte)puVar8[6] * 2);
    if (((int)(this->pos).rotation.z < *(short *)(puVar8 + 4) + 0x500) &&
       (*(short *)(puVar8 + 4) + -0x500 < (int)(this->pos).rotation.z)) {
      FUN_80068a9c((uint)this,2);
      puVar8[7] = puVar8[7] & 0xfe;
    }
    sVar3._0_1_ = pOVar7[1].bound;
    sVar3._1_1_ = pOVar7[1].cullDist;
    uVar6 = mainGetBit((int)sVar3);
    if ((byte)puVar8[6] != uVar6) {
      sVar4._0_1_ = pOVar7[1].bound;
      sVar4._1_1_ = pOVar7[1].cullDist;
      mainSetBits((int)sVar4,(uint)(byte)puVar8[6]);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_26E_func05
   
   Library: KioskDefault 0 0 */

void DBspike_hitDetect(ObjInstance *this) { //80293D94
  int iVar1;
  
  iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar1 != 0) {
    audioTryStartSfx((int *)this,1,0x222,0x7f,(char *)&PTR_DAT_80321118,0x8b);
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DBspike_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //80293DFC
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DBspike_free(ObjInstance *this,int param2) { //80293E58
  return;
}


undefined4 DBspike_func08(ObjInstance *this) { //80293E5C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBspike_getExtraSize(void) { //80293E64
  return 0xc;
}

