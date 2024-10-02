
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SHrocketmushroom_initialise(undefined4 param) { //80250798
  return;
}


/* @description Called when DLL is unloaded */

void SHrocketmushroom_release(void) { //8025079C
  return;
}


/* Library Function - Single Match
    dll_1E5_func03
   
   Library: KioskDefault 0 0 */

void SHrocketmushroom_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802507A0
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].cullDist << 8);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802511ec;
  puVar4[3] = (this->pos).scale;
  if (obj2 == (ObjInstance *)0x0) {
    sVar1._0_1_ = objDef[1].loadFlags;
    sVar1._1_1_ = objDef[1].mapStates2;
    if ((sVar1 == -1) ||
       (sVar2._0_1_ = objDef[1].loadFlags, sVar2._1_1_ = objDef[1].mapStates2,
       uVar3 = mainGetBit((int)sVar2), uVar3 != 0)) {
      FUN_80251108(this,puVar4,0);
    }
    else {
      FUN_80251108(this,puVar4,1);
      *(undefined *)(puVar4 + 5) = 1;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1E5_func04
   
   Library: KioskDefault 0 0 */

void SHrocketmushroom_update(ObjInstance *this) { //8025085C
  byte bVar2;
  int iVar1;
  int iVar3;
  float *pfVar4;
  word *pwVar5;
  Mtx44 MStack_8c;
  float local_4c;
  float local_48;
  float local_44;
  ObjPos local_40;
  undefined4 uStack_28;
  uint local_24;
  int aiStack_20 [3];
  
  bVar2 = FUN_80085d5c((int)this);
  if (bVar2 != 0) {
    return;
  }
  pfVar4 = (float *)this->state;
  iVar3 = (uint)*(byte *)(pfVar4 + 5) * 0xc;
  pwVar5 = (word *)(&DAT_8031a8c0 + iVar3);
  bVar2 = *(byte *)(pfVar4 + 5);
  if (bVar2 == 2) {
    FUN_80250cfc(this,pwVar5,pfVar4);
  }
  else {
    if (bVar2 < 2) {
      if ((bVar2 != 0) && (true)) {
        FUN_80250c10(this,pwVar5,pfVar4);
        goto LAB_80250910;
      }
    }
    else if (bVar2 == 4) {
      FUN_80250de8((int *)this,pwVar5,(int)pfVar4);
      goto LAB_80250910;
    }
    FUN_80250e90((int)this,pwVar5,pfVar4);
  }
LAB_80250910:
  if (((((&DAT_8031a8c8)[iVar3] & 1) != 0) &&
      (iVar1 = FUN_800883e4((int)this,&uStack_28,aiStack_20,&local_24), iVar1 != 0)) &&
     (local_24 != 0)) {
    if (iVar1 == 0x10) {
      FUN_80085c94(this,300);
    }
    else {
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x10c,0x7f,"SHrocketmushroom.c",
                          (int *)0x109);
      FUN_80250f38((int)pfVar4,4);
      local_40.rotation.x = (this->pos).rotation.x;
      local_40.rotation.y = (this->pos).rotation.y;
      local_40.rotation.z = (this->pos).rotation.z;
      local_40.pos.x = 0.0;
      local_40.pos.y = 0.0;
      local_40.pos.z = 0.0;
      local_40.scale = 1.0;
      mtxSetFromObjPos(&MStack_8c,&local_40);
      multVectorByMatrix(0.0,1.0,0.0,&MStack_8c,&local_4c,&local_48,&local_44);
      local_40.pos.x = local_4c * 23.0 + (this->pos).pos.x;
      local_40.pos.y = local_48 * 23.0 + (this->pos).pos.y;
      local_40.pos.z = local_44 * 23.0 + (this->pos).pos.z;
      local_40.scale = 518.0;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x323,&local_40,&DAT_00200001,0xffffffff,0);
      local_40.pos.x = local_40.pos.x - (this->pos).pos.x;
      local_40.pos.y = local_40.pos.y - (this->pos).pos.y;
      local_40.pos.z = local_40.pos.z - (this->pos).pos.z;
      for (iVar1 = 0; iVar1 < 0x14; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x324,&local_40,2,0xffffffff,0);
      }
      objHitFn_80089188(this,this->data->hitbox_flagsB6 + 0x50,
                        *(short *)&this->data->field_0x94 + -0x50,
                        *(short *)&this->data->field_0x96 + 0x50);
    }
  }
  if (((&DAT_8031a8c8)[iVar3] & 8) == 0) {
    FUN_80088da4((int)this);
  }
  else {
    FUN_80088d3c((int)this);
  }
  if (((&DAT_8031a8c8)[iVar3] & 0x10) == 0) {
    objHitFn_80089114(this);
  }
  else {
    objHitFn_80089074(this,10,1,0);
  }
  if (((&DAT_8031a8c8)[iVar3] & 2) == 0) {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  else {
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  }
  if (((&DAT_8031a8c8)[iVar3] & 4) == 0) {
    (this->pos).flags = (this->pos).flags & ~Invisible;
  }
  else {
    (this->pos).flags = (this->pos).flags | Invisible;
  }
  if (this->animId != *pwVar5) {
    Object_ObjAnimSetMove(0.0,this,(int)(short)*pwVar5,0);
  }
  iVar3 = objRunAnimation((double)*(float *)(&DAT_8031a8c4 + iVar3),(double)timeDelta,(int)this,
                          (float *)0x0);
  if (iVar3 == 0) {
    *(byte *)((int)pfVar4 + 0x15) = *(byte *)((int)pfVar4 + 0x15) & 0xfe;
  }
  else {
    *(byte *)((int)pfVar4 + 0x15) = *(byte *)((int)pfVar4 + 0x15) | 1;
  }
  return;
}


/* @description Override hit detection */

void SHrocketmushroom_hitDetect(ObjInstance *this) { //80250F4C
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void SHrocketmushroom_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80250F50
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void SHrocketmushroom_free(ObjInstance *this,int param2) { //80250F9C
  return;
}


undefined4 SHrocketmushroom_func08(ObjInstance *this) { //80250FA0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SHrocketmushroom_getExtraSize(void) { //80250FA8
  return 0x18;
}

