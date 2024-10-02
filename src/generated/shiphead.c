
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBshiphead_initialise(undefined4 param) { //802623C4
  return;
}


/* @description Called when DLL is unloaded */

void SBshiphead_release(void) { //802623C8
  return;
}


/* Library Function - Single Match
    dll_22B_func03
   
   Library: KioskDefault 0 0 */

void SBshiphead_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802623CC
  Object_objAddObjectType(this,4);
  objAllocMsgQueue(this,10);
  return;
}


/* Library Function - Single Match
    dll_22B_func04
   
   Library: KioskDefault 0 0 */

void SBshiphead_update(ObjInstance *this) { //8026240C
  ObjInstance **ppOVar1;
  int iVar2;
  LoadedDll *dll;
  ObjDef *pOVar3;
  ObjInstance *pOVar4;
  int iVar5;
  ObjInstance **ppOVar6;
  ObjInstance *pOVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  uint uStack_8c;
  undefined *local_88;
  int local_84;
  uint uStack_80;
  int local_7c;
  int local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  
  _savefpr_28();
  iVar5 = 0;
  pOVar7 = this->pMatrix;
  if (pOVar7 != (ObjInstance *)0x0) {
    iVar8 = pOVar7->field76_0xf4;
    if (pOVar7->romdefno == WM_Galleon) {
      if (this->curModel != 1) {
        objSetModelNo(this,1);
      }
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
      if (iVar8 == 10) {
        FUN_80086488(0.0,(int)this);
      }
      else {
        objRunAnimation(0.004999999888241291,(double)timeDelta,(int)this,(float *)0x0);
      }
    }
    else {
      ppOVar6 = (ObjInstance **)this->state;
      if (*ppOVar6 == (ObjInstance *)0x0) {
        ppOVar1 = Object_getObjects(&local_78,&local_7c);
        for (; local_78 < local_7c; local_78 = local_78 + 1) {
          if (ppOVar1[local_78]->romdefno == SB_Cloudrun) {
            *ppOVar6 = ppOVar1[local_78];
            local_78 = local_7c;
          }
        }
      }
      iVar2 = FUN_80091100((int)this,(uint *)&local_88,&uStack_80,&uStack_8c);
      if (iVar2 != 0) {
        if (local_88 == &DAT_00130002) {
          iVar5 = 1;
        }
        else if ((int)local_88 < 0x130002) {
          if (0x130000 < (int)local_88) {
            dll = (LoadedDll *)runlinkDownloadCode(0x2008,1);
            (**(code **)(dll->id + 4))(this,0,0,1,0xffffffff,8,0);
            if (dll != (LoadedDll *)0x0) {
              DLL_free(dll);
            }
          }
        }
        else if ((int)local_88 < 0x130004) {
          iVar5 = 2;
        }
      }
      if (((int)this->flags_0xf8 < 1) &&
         ((((iVar8 == 3 || (iVar8 == 4)) || (iVar8 == 5)) &&
          ((iVar2 = FUN_800883e4((int)this,&local_84,(int *)0x0,(uint *)0x0), iVar2 != 0 &&
           (*(short *)(local_84 + 0x46) != 0x114)))))) {
        *(undefined2 *)(ppOVar6 + 1) = 0xff;
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,5,0x7f,"shiphead.c",(int *)0xa7);
        (*(code *)pOVar7->dll->ptrs2->setScale)(pOVar7);
        this->flags_0xf8 = 300;
      }
      if (0 < (int)this->flags_0xf8) {
        this->flags_0xf8 = this->flags_0xf8 - (uint)framesThisStep;
      }
      if (7 < iVar8) {
        objSetModelNo(this,1);
      }
      if ((iVar8 == 8) &&
         (this->field76_0xf4 = this->field76_0xf4 + 1, 10 < (int)this->field76_0xf4)) {
        this->field76_0xf4 = 0;
      }
      if ((iVar8 == 5) && (DAT_80399fc8 != 5)) {
        this->field76_0xf4 = this->field76_0xf4 + (uint)framesThisStep;
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,10,0x7f,"shiphead.c",(int *)0xc1);
        (this->pos).pos.y = (this->pos).pos.y + 50.0;
        (this->pos).pos.z = (this->pos).pos.z - 300.0;
        objMultPosByMtx(this,&local_6c,&local_70,&local_74);
        (this->pos).pos.y = (this->pos).pos.y - 50.0;
        (this->pos).pos.z = (this->pos).pos.z + 300.0;
        pOVar3 = objAlloc(0x18,SB_FireBall_0114);
        pOVar3->bound = 0xff;
        pOVar3->cullDist = 0xff;
        pOVar3->loadFlags = isManualLoad;
        pOVar3->mapStates2 = 1;
        (pOVar3->pos).x = local_6c;
        (pOVar3->pos).y = local_70;
        (pOVar3->pos).z = local_74;
        pOVar7 = objInstantiateCharacter(pOVar3,5,-1,-1,(ObjInstance *)0x0);
        pOVar4 = Object_objGetMain();
        dVar12 = (double)((pOVar4->prevPos).x - (pOVar7->pos).pos.x);
        dVar11 = (double)(((pOVar4->prevPos).y - 30.0) - (pOVar7->pos).pos.y);
        dVar10 = (double)((pOVar4->prevPos).z - (pOVar7->pos).pos.z);
        dVar9 = sqrt((double)(float)(dVar10 * dVar10 +
                                    (double)(float)(dVar12 * dVar12 +
                                                   (double)(float)(dVar11 * dVar11))));
        dVar9 = (double)(float)(30.0 / dVar9);
        (pOVar7->vel).x = (float)(dVar12 * dVar9);
        (pOVar7->vel).y = (float)(dVar11 * dVar9);
        (pOVar7->vel).z = (float)(dVar10 * dVar9);
        pOVar7->field76_0xf4 = 0x78;
        pOVar7->flags_0xf8 = (dword)*ppOVar6;
      }
      if (iVar5 == 1) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,10,0x7f,"shiphead.c",(int *)0xe7);
        pOVar7 = Object_objGetMain();
        pOVar3 = objAlloc(0x18,SB_MiniFire);
        (pOVar3->pos).x = (pOVar7->prevPos).x + 100.0;
        uStack_5c = randInt(-6,6);
        uStack_5c = uStack_5c ^ 0x80000000;
        local_60 = 0x43300000;
        (pOVar3->pos).y =
             (pOVar7->prevPos).y +
             (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) + 50.0;
        uStack_64 = randInt(-6,6);
        uStack_64 = uStack_64 ^ 0x80000000;
        local_68 = 0x43300000;
        (pOVar3->pos).z =
             (pOVar7->prevPos).z +
             (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) + 45.0;
        pOVar3->loadFlags = isManualLoad;
        pOVar3->mapStates2 = 1;
        pOVar3->bound = 0xff;
        pOVar3->cullDist = 0xff;
        objInstantiateCharacter(pOVar3,5,-1,-1,(ObjInstance *)0x0);
      }
      objRunAnimation(0.004999999888241291,(double)timeDelta,(int)this,(float *)0x0);
      DAT_80399fc8 = iVar8;
    }
  }
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    dll_22B_func05
   
   Library: KioskDefault 0 0 */

void SBshiphead_hitDetect(ObjInstance *this) { //80262968
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((0 < *(short *)(puVar1 + 4)) &&
     (*(ushort *)(puVar1 + 4) = *(short *)(puVar1 + 4) + (ushort)framesThisStep * -3,
     *(short *)(puVar1 + 4) < 0)) {
    *(undefined2 *)(puVar1 + 4) = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_22B_func06
   
   Library: KioskDefault 0 0 */

void SBshiphead_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //802629B4
  bool bVar2;
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  float fStack_1c;
  float fStack_18;
  float afStack_14 [2];
  
  if (shouldRender) {
    puVar3 = this->state;
    if (*(short *)(puVar3 + 4) != 0) {
      FUN_80096afc(0xff,0xff - *(short *)(puVar3 + 4),0xff - *(short *)(puVar3 + 4));
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (this->pMatrix != (ObjInstance *)0x0) {
      if ((((this->pMatrix->romdefno == SB_Galleon) &&
           (bVar2 = checkSomeDebugFlags_8017c4f8(), !bVar2)) &&
          (iVar1 = (*(code *)this->pMatrix->dll->ptrs2->render2C)(this->pMatrix), iVar1 != 0)) &&
         (iVar1 != 2)) {
        objGetAttachPointWorldPos(this,2,&fStack_1c,&fStack_18,afStack_14,FALSE);
        if (true) {
                    /* WARNING: Could not recover jumptable at 0x80262ae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)PTR_LAB_8031bd70)();
          return;
        }
      }
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_22B_func07
    dll_253_func07
    dll_294_func07
    dll_2D3_func07
   
   Library: KioskDefault 0 0 */

void SBshiphead_free(ObjInstance *this,int param2) { //80262E18
  Object_removePlayerObj(this,4);
  return;
}


undefined4 SBshiphead_func08(ObjInstance *this) { //80262E44
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int SBshiphead_getExtraSize(void) { //80262E4C
  return 8;
}

