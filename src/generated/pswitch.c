
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void pswitch_initialise(undefined4 param) { //802805E4
  return;
}


/* @description Called when DLL is unloaded */

void pswitch_release(void) { //802805E8
  return;
}


/* Library Function - Single Match
    dll_240_func03
   
   Library: KioskDefault 0 0 */

void pswitch_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //802805EC
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80280a90;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    (this->pos).pos.y = (objDef->pos).y - 25.0;
    *puVar3 = 0x1e;
  }
  puVar3[1] = 0;
  return;
}


/* Library Function - Single Match
    dll_240_func04
   
   Library: KioskDefault 0 0 */

void pswitch_update(ObjInstance *this) { //8028066C
  short sVar1;
  short sVar2;
  short sVar3;
  float fVar4;
  ObjInstance *pOVar5;
  char cVar7;
  uint uVar6;
  int iVar8;
  int iVar9;
  ObjDef *pOVar10;
  char *pcVar11;
  bool bVar12;
  double in_f1;
  double extraout_f1;
  double dVar13;
  
  pOVar5 = Object_objGetMain();
  pOVar10 = this->def;
  pcVar11 = this->state;
  objDistObj2Obj(this,pOVar5);
  *pcVar11 = *pcVar11 + -1;
  if (*pcVar11 < '\0') {
    *pcVar11 = '\0';
    pcVar11[1] = '\0';
  }
  if ((this->field18_0x58 == (ObjInstanceField58 *)0x0) ||
     ((char)this->field18_0x58->field144_0x10f < '\x01')) {
                    /* {@symbol 8012dfa8} */
    cVar7 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
    if ((cVar7 == '\x03') &&
       ((dVar13 = extraout_f1, pOVar5 = Object_getSidekicksLoaded(), pOVar5 != (ObjInstance *)0x0
        && (objDistObj2Obj(this,pOVar5), dVar13 < 50.0)))) {
      *pcVar11 = '\x05';
    }
  }
  else {
    for (iVar8 = 0; iVar8 < (char)this->field18_0x58->field144_0x10f; iVar8 = iVar8 + 1) {
      iVar9 = *(int *)((int)(this->field18_0x58->mtx + 2) + iVar8 * 4);
      if (8.9 < *(float *)(iVar9 + 0x10) - (this->pos).pos.y) {
        *pcVar11 = '\x05';
      }
      if (((pcVar11[1] == '\0') && (iVar9 != 0)) && (*(short *)(iVar9 + 0x46) == 0x146)) {
        if (in_f1 <= 100.0) {
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x161,0x7f,(char *)&PTR_DAT_8031d460,
                              (int *)0x67);
        }
        pcVar11[1] = '\x01';
      }
    }
  }
                    /* {@symbol 8012dfa8} */
  cVar7 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  if ((cVar7 == '\x01') && (in_f1 <= 100.0)) {
    if (*pcVar11 == '\0') {
      uVar6 = mainGetBit(0x905);
      if (uVar6 != 0) {
        mainSetBits(0x905,0);
      }
    }
    else {
      fVar4 = (pOVar10->pos).y - (this->pos).pos.y;
      if ((fVar4 <= 2.5) || (5.0 <= fVar4)) {
        uVar6 = mainGetBit(0x905);
        if (uVar6 != 0) {
          mainSetBits(0x905,0);
        }
      }
      else {
        mainSetBits(0x905,1);
      }
    }
  }
  bVar12 = false;
  if (*pcVar11 == '\0') {
    (this->pos).pos.y = timeDelta * 0.125 + (this->pos).pos.y;
    bVar12 = (this->pos).pos.y <= (pOVar10->pos).y;
    if (!bVar12) {
      (this->pos).pos.y = (pOVar10->pos).y;
    }
    sVar3._0_1_ = pOVar10[1].loadFlags;
    sVar3._1_1_ = pOVar10[1].mapStates2;
    mainSetBits((int)sVar3,0);
  }
  else {
    fVar4 = (pOVar10->pos).y - 5.0;
    if (fVar4 <= (this->pos).pos.y) {
      (this->pos).pos.y = -(timeDelta * 0.125 - (this->pos).pos.y);
      if (fVar4 <= (this->pos).pos.y) {
        bVar12 = true;
      }
      else {
        (this->pos).pos.y = fVar4;
        sVar2._0_1_ = pOVar10[1].loadFlags;
        sVar2._1_1_ = pOVar10[1].mapStates2;
        mainSetBits((int)sVar2,1);
      }
    }
    else {
      (this->pos).pos.y = timeDelta * 0.25 + (this->pos).pos.y;
      if (fVar4 < (this->pos).pos.y) {
        (this->pos).pos.y = fVar4;
      }
      sVar1._0_1_ = pOVar10[1].loadFlags;
      sVar1._1_1_ = pOVar10[1].mapStates2;
      mainSetBits((int)sVar1,1);
    }
  }
  if (bVar12) {
    audioTryStartSfx((int *)this,0x88,0x74,0x7f,(char *)&PTR_DAT_8031d460,0xa7);
  }
  else {
    FUN_80068a9c((uint)this,8);
  }
  return;
}


/* @description Override hit detection */

void pswitch_hitDetect(ObjInstance *this) { //802809DC
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1C3_func06
    dll_240_func06
   
   Library: KioskDefault 0 0 */

void pswitch_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //802809E0
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
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   50.0,25.0,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
    }
  }
  return;
}


/* @description Free object instance */

void pswitch_free(ObjInstance *this,int param2) { //80280A7C
  return;
}


undefined4 pswitch_func08(ObjInstance *this) { //80280A80
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int pswitch_getExtraSize(void) { //80280A88
  return 2;
}

