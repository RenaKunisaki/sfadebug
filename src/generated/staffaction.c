
/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func00
    dll_2FA_func00
    dll_2FB_func00
   
   Library: KioskDefault 0 0 */

void staffAction_initialise(undefined4 param) { //801ED218
  if (DAT_80399d80 == (DLL_func **)0x0) {
    DAT_80399d80 = DLL_setup(0x1002,1,FALSE);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func01
    dll_184_func01
    dll_210_func07
    dll_243_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void staffAction_release(void) { //801ED254
  if (DAT_80399d80 != (LoadedDll *)0x0) {
    DLL_free(DAT_80399d80);
    DAT_80399d80 = (LoadedDll *)0x0;
  }
  return;
}


/* Library Function - Single Match
    dll_12D_func03
   
   Library: KioskDefault 0 0 */

void staffAction_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //801ED28C
  RomListObjLoadFlags RVar1;
  uint uVar2;
  byte bVar3;
  float *pfVar4;
  double dVar5;
  double local_28;
  
  pfVar4 = (float *)this->state;
  Object_objAddObjectType(this,0x43);
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  bVar3 = objDef[1].mapStates2;
  if (2 < bVar3) {
    bVar3 = 2;
  }
  if (bVar3 != 1) {
    if (bVar3 == 0) {
      if (true) {
        dVar5 = 0.75;
        goto LAB_801ed30c;
      }
    }
    else if (bVar3 < 3) {
      dVar5 = 1.25;
      goto LAB_801ed30c;
    }
  }
  dVar5 = 1.0;
LAB_801ed30c:
  if (this->hitstate != (HitState *)0x0) {
    objHitFn_80089354(this,(short)(int)((double)(float)((double)CONCAT44(0x43300000,
                                                                         (int)(short)this->hitstate
                                                                                     ->field16_0x52
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * dVar5));
  }
  (this->pos).scale = (float)((double)this->data->scale * dVar5);
  if ((this->pos).scale < 0.1) {
    (this->pos).scale = 0.1;
  }
  RVar1 = objDef[1].loadFlags;
  if (RVar1 == (isLevelObject|isManualLoad)) {
    local_28 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
    dVar5 = (double)distanceFn_80293e80((double)(((float)(local_28 - 4503601774854144.0) * 3.141593)
                                                / 32767.0));
    *pfVar4 = (this->pos).scale * (float)(dVar5 * 10.0) * 0.5 + (this->pos).pos.x;
    dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)(this->pos).rotation.x ^
                                                                       0x80000000) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    pfVar4[1] = (this->pos).scale * (float)(dVar5 * 10.0) * 0.5 + (this->pos).pos.z;
  }
  else if ((RVar1 < (isLevelObject|isManualLoad)) && (isLevelObject < RVar1)) {
    local_28 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
    dVar5 = (double)distanceFn_80293e80((double)(((float)(local_28 - 4503601774854144.0) * 3.141593)
                                                / 32767.0));
    *pfVar4 = -((this->pos).scale * (float)(dVar5 * 10.0) * 0.5 - (this->pos).pos.x);
    dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)(this->pos).rotation.x ^
                                                                       0x80000000) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    pfVar4[1] = -((this->pos).scale * (float)(dVar5 * 10.0) * 0.5 - (this->pos).pos.z);
  }
  else {
    *pfVar4 = (this->pos).pos.x;
    pfVar4[1] = (this->pos).pos.z;
  }
  if (*(short *)((int)&objDef[1].pos.x + 2) < 1) {
    *(undefined *)((int)pfVar4 + 0x19) = 1;
  }
  else {
    uVar2 = mainGetBit((int)*(short *)((int)&objDef[1].pos.x + 2));
    *(char *)((int)pfVar4 + 0x19) = (char)uVar2;
  }
  if (0 < *(short *)&objDef[1].pos.y) {
    uVar2 = mainGetBit((int)*(short *)&objDef[1].pos.y);
    *(char *)((int)pfVar4 + 0x1a) = (char)uVar2;
  }
  return;
}


/* Library Function - Single Match
    dll_12D_func04
   
   Library: KioskDefault 0 0 */

void staffAction_update(ObjInstance *this) { //801ED554
  RomListObjLoadFlags RVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  RVar1 = this->def[1].loadFlags;
  if (RVar1 == (isLevelObject|isManualLoad)) {
    FUN_801ee110(this,(int)puVar2);
  }
  else if (RVar1 < (isLevelObject|isManualLoad)) {
    if (isLevelObject < RVar1) {
      FUN_801eddd4((int *)this,(int)puVar2);
    }
  }
  else if (RVar1 < (isLevelObject|OnlyLoadIfNearPlayer)) {
    FUN_801ee068((int)this,(int)puVar2);
  }
  return;
}


/* @description Override hit detection */

void staffAction_hitDetect(ObjInstance *this) { //801ED5D8
  return;
}


/* Library Function - Single Match
    dll_12D_func06
   
   Library: KioskDefault 0 0 */

void staffAction_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //801ED5DC
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  objRenderCurrentModel
            (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
             (int *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if (bVar1) {
    FUN_800964d4((double)*pfVar2,(double)(this->pos).pos.y,(double)pfVar2[1],
                 (double)((this->pos).scale * 10.0),(Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),(this->pos).rotation.z,
                 (this->pos).rotation.y,(this->pos).rotation.x,0xff,0,0);
  }
  return;
}


/* Library Function - Single Match
    dll_12D_func07
   
   Library: KioskDefault 0 0 */

void staffAction_free(ObjInstance *this,int param2) { //801ED67C
  Object_removePlayerObj(this,0x43);
  return;
}


undefined4 staffAction_func08(ObjInstance *this) { //801ED6A8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int staffAction_getExtraSize(void) { //801ED6B0
  return 0x1c;
}


/* Library Function - Single Match
    staffActionTypeFn_801edce4
   
   Library: KioskDefault 0 0 */

undefined staffActionTypeFn_801edce4(int param1) { //801EDCE4
  if (*(char *)(*(int *)(param1 + 0x4c) + 0x1c) != '\x04') {
                    
    OSPanic("staffaction.c",0x281,s_Failed_assertion_def_>actionType_80312ca8);
  }
  return *(undefined *)(*(int *)(param1 + 0xb8) + 0x1b);
}


/* Library Function - Single Match
    staffActionTypeFn_801edd40
   
   Library: KioskDefault 0 0 */

void staffActionTypeFn_801edd40(ObjInstance *this,bool param2) { //801EDD40
  undefined *state;
  ObjDef *def;
  
  def = this->def;
  state = this->state;
  if (def[1].loadFlags != OnlyLoadIfNearPlayer) {
                    
    OSPanic("staffaction.c",0x298,s_Failed_assertion_def_>actionType_80312ca8);
  }
  if (param2) {
    mainSetBits((int)*(short *)&def[1].pos.y,1);
    state[0x1b] = 1;
  }
  else {
    mainSetBits((int)*(short *)&def[1].pos.y,0);
    state[0x1b] = 0;
  }
  return;
}

