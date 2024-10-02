
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void pressureSwitch_initialise(undefined4 param) { //801DA4C4
  return;
}


/* @description Called when DLL is unloaded */

void pressureSwitch_release(void) { //801DA4C8
  return;
}


/* Library Function - Single Match
    pressureSwitch_func03
   
   Library: KioskDefault 0 0 */

void pressureSwitch_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801DA4CC
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar3 = this->state;
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->curModel = *(byte *)((int)&objDef[1].objType + 1);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
    printf("PRESSURESWITCH.c: modelno out of range romdefno=%d",(int)(short)objDef->objType);
  }
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    (this->pos).pos.y =
         (objDef->pos).y -
         (float)((double)CONCAT44(0x43300000,(uint)objDef[1].loadFlags) - 4503599627370496.0);
    *puVar3 = 0x1e;
  }
  Object_objAddObjectType(this,0x33);
  for (iVar4 = 0; iVar4 < 10; iVar4 = iVar4 + 1) {
    *(undefined4 *)(puVar3 + iVar4 * 4 + 4) = 0;
  }
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801daad8;
  return;
}


/* Library Function - Single Match
    pressureSwitch_func04
   
   Library: KioskDefault 0 0 */

void pressureSwitch_update(ObjInstance *this) { //801DA5D4
  char cVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  float fVar6;
  bool bVar7;
  uint uVar8;
  ObjInstance *param2;
  ObjInstance *this_00;
  int iVar9;
  int iVar10;
  char *pcVar11;
  ObjDef *pOVar12;
  double dVar13;
  
  _savefpr_30();
  pOVar12 = this->def;
  pcVar11 = this->state;
  if (0 < *(short *)&pOVar12[1].pos.x) {
    uVar8 = mainGetBit((int)*(short *)&pOVar12[1].pos.x);
    if (uVar8 == 0) goto LAB_801da898;
  }
  cVar1 = *pcVar11;
  *pcVar11 = cVar1 + -1;
  if ((char)(cVar1 + -1) < '\0') {
    *pcVar11 = '\0';
  }
  if ('\0' < (char)this->field18_0x58->field144_0x10f) {
    for (iVar10 = 0; iVar10 < (char)this->field18_0x58->field144_0x10f; iVar10 = iVar10 + 1) {
      iVar9 = *(int *)((int)(this->field18_0x58->mtx + 2) + iVar10 * 4);
      if ((float)((double)CONCAT44(0x43300000,(uint)pOVar12[1].mapStates2) - 4503599627370496.0) <
          *(float *)(iVar9 + 0x10) - (this->pos).pos.y) {
        FUN_801da9bc((int)this,iVar9);
      }
    }
  }
  iVar10 = FUN_801daa2c((int)this);
  if (iVar10 != 0) {
    *pcVar11 = '\x05';
  }
  bVar7 = false;
  if (*pcVar11 == '\0') {
    (this->pos).pos.y = timeDelta * 0.125 + (this->pos).pos.y;
    if ((this->pos).pos.y <= (pOVar12->pos).y) {
      bVar7 = true;
    }
    else {
      (this->pos).pos.y = (pOVar12->pos).y;
      sVar4._0_1_ = pOVar12[1].allocatedSize;
      sVar4._1_1_ = pOVar12[1].mapStates1;
      mainSetBits((int)sVar4,0);
    }
  }
  else {
    fVar6 = (pOVar12->pos).y -
            (float)((double)CONCAT44(0x43300000,(uint)pOVar12[1].loadFlags) - 4503599627370496.0);
    if (fVar6 <= (this->pos).pos.y) {
      (this->pos).pos.y = -(timeDelta * 0.125 - (this->pos).pos.y);
      if (fVar6 <= (this->pos).pos.y) {
        bVar7 = true;
      }
      else {
        (this->pos).pos.y = fVar6;
        sVar3._0_1_ = pOVar12[1].allocatedSize;
        sVar3._1_1_ = pOVar12[1].mapStates1;
        mainSetBits((int)sVar3,1);
      }
    }
    else {
      (this->pos).pos.y = timeDelta * 0.25 + (this->pos).pos.y;
      if (fVar6 < (this->pos).pos.y) {
        (this->pos).pos.y = fVar6;
      }
      sVar2._0_1_ = pOVar12[1].allocatedSize;
      sVar2._1_1_ = pOVar12[1].mapStates1;
      mainSetBits((int)sVar2,1);
    }
  }
  if (bVar7) {
    audioTryStartSfx((int *)this,0x88,0x74,0x7f,"pressureswitch.c",0xb3);
  }
  else {
    FUN_80068a9c((uint)this,8);
  }
  sVar5._0_1_ = pOVar12[1].allocatedSize;
  sVar5._1_1_ = pOVar12[1].mapStates1;
  uVar8 = mainGetBit((int)sVar5);
  if ((uVar8 == 0) && (pOVar12[1].bound != 0)) {
    param2 = Object_objGetMain();
    this_00 = Object_getSidekicksLoaded();
    if (this_00 != (ObjInstance *)0x0) {
      dVar13 = (double)objDistSqObj2Obj(this,param2);
      if (dVar13 <= (double)(float)((double)CONCAT44(0x43300000,
                                                     (uint)pOVar12[1].bound * (uint)pOVar12[1].bound
                                                     ^ 0x80000000) - 4503601774854144.0)) {
        (*this_00->dll->ptrs2[1].hitDetect)(this_00);
      }
    }
  }
LAB_801da898:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void pressureSwitch_hitDetect(ObjInstance *this) { //801DA8B4
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    pressureSwitch02D9_func06
    pressureSwitch_func06
   
   Library: KioskDefault 0 0 */

void pressureSwitch_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801DA8B8
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((((this->pos).flags & 0x100) != 0) && (this->def != (ObjDef *)0x0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)((this->pos).pos.y + 25.0),
                   (double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)this->def[1].bound) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_10A_func07
    dll_10B_func07
    dll_266_func07
    dll_28B_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void pressureSwitch_free(ObjInstance *this,int param2) { //801DA980
  Object_removePlayerObj(this,0x33);
  return;
}


undefined4 pressureSwitch_func08(ObjInstance *this) { //801DA9AC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int pressureSwitch_getExtraSize(void) { //801DA9B4
  return 0x7c;
}

