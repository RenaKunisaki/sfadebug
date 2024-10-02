
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void cannon_initialise(undefined4 param) { //801CB100
  return;
}


/* @description Called when DLL is unloaded */

void cannon_release(void) { //801CB104
  return;
}


/* Library Function - Single Match
    cannon_func03
   
   Library: KioskDefault 0 0 */

void cannon_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801CB108
  int iVar1;
  float *pfVar2;
  
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  iVar1 = isModelAnimDisabled();
  if (iVar1 == 0) {
    (this->pos).pos.y = (this->pos).pos.y - 100.0;
  }
  this->field76_0xf4 = (uint)*(byte *)((int)&objDef[1].objType + 1);
  pfVar2 = (float *)this->state;
  *(undefined *)(pfVar2 + 6) = 0;
  if (*(char *)(pfVar2 + 6) == '\0') {
    *(short *)((int)pfVar2 + 0x12) = PTR_DAT_80397ba8._0_2_;
    PTR_DAT_80397ba8._0_2_ = 0x46 - PTR_DAT_80397ba8._0_2_;
    *(undefined *)((int)pfVar2 + 0x19) = *(undefined *)((int)&objDef[1].objType + 1);
    *pfVar2 = 0.0;
    *(undefined2 *)((int)pfVar2 + 0x16) = 0;
    pfVar2[1] = (this->pos).pos.x;
    pfVar2[2] = (this->pos).pos.y;
    pfVar2[3] = (this->pos).pos.z;
  }
  return;
}


/* Library Function - Single Match
    cannon_func04
   
   Library: KioskDefault 0 0 */

void cannon_update(ObjInstance *this) { //801CB1C4
  ObjDef *def;
  ObjInstance *pOVar1;
  int iVar2;
  short sVar3;
  float *pfVar4;
  double dVar5;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  pfVar4 = (float *)this->state;
  diPrintf("CANNON");
  sVar3 = *(short *)((int)pfVar4 + 0x16);
  if (sVar3 == 2) {
    if (*(short *)((int)pfVar4 + 0x12) < 0) {
      *(undefined2 *)((int)pfVar4 + 0x12) = 0;
      *(undefined2 *)((int)pfVar4 + 0x16) = 3;
    }
    else {
      *(short *)((int)pfVar4 + 0x12) = *(short *)((int)pfVar4 + 0x12) + -1;
      if ((((this != (ObjInstance *)0x0) && (this->hitstate != (HitState *)0x0)) &&
          (this->hitstate->field15_0x50 < 0x46)) &&
         ((pOVar1 = this->hitstate->curTouchedObject, pOVar1 != DAT_80399d38 &&
          (pOVar1->objId == 0x29)))) {
        if (((int)(this->pos).rotation.x & 0x8000U) == 0) {
                    /* {@symbol 800d0bec} */
          iVar2 = (**(code **)(*(int *)pDll_checkpoint + 0x6c))();
                    /* {@symbol 800d0bf4} */
          (**(code **)(*(int *)pDll_checkpoint + 0x70))(iVar2 + -1);
        }
        else {
                    /* {@symbol 800d0bdc} */
          iVar2 = (**(code **)(*(int *)pDll_checkpoint + 100))();
                    /* {@symbol 800d0be4} */
          (**(code **)(*(int *)pDll_checkpoint + 0x68))(iVar2 + -1);
        }
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,9,0,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,5,0,4,0xffffffff,0);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x40,0x7f,"cannon.c",(int *)0x8e);
        FUN_80090ef4(0x35,0,(ObjInstance *)0x0,0xe0000,(uint)this);
        Object_objFreeObject(pOVar1);
        Object_objFreeObject(this);
      }
    }
  }
  else if (sVar3 < 2) {
    if (sVar3 == 0) {
      if (*(short *)((int)pfVar4 + 0x12) < 0) {
        *(undefined2 *)((int)pfVar4 + 0x12) = 0x1e;
        *(undefined2 *)((int)pfVar4 + 0x16) = 1;
        *pfVar4 = 0.0;
        (this->pos).pos.x = pfVar4[1];
        (this->pos).pos.y = pfVar4[2];
        (this->pos).pos.z = pfVar4[3];
      }
      else {
        *(short *)((int)pfVar4 + 0x12) = *(short *)((int)pfVar4 + 0x12) + -1;
      }
    }
    else if (-1 < sVar3) {
      if (*(short *)((int)pfVar4 + 0x12) < 0) {
        *(undefined2 *)((int)pfVar4 + 0x16) = 2;
        *pfVar4 = 0.0;
        *(undefined2 *)((int)pfVar4 + 0x12) = 0x14;
      }
      else {
        (this->pos).pos.y = (this->pos).pos.y + 2.2;
        *(short *)((int)pfVar4 + 0x12) = *(short *)((int)pfVar4 + 0x12) + -1;
      }
    }
  }
  else if (sVar3 == 4) {
    if (*(short *)((int)pfVar4 + 0x12) < 0) {
      if (*(short *)(pfVar4 + 5) < 0) {
        *(undefined2 *)((int)pfVar4 + 0x16) = 0;
        *(undefined2 *)((int)pfVar4 + 0x12) = 0x14;
        *(undefined2 *)(pfVar4 + 5) = 0;
        *pfVar4 = 0.0;
      }
      else {
        (this->pos).pos.y = (this->pos).pos.y - 2.2;
        *(short *)(pfVar4 + 5) = *(short *)(pfVar4 + 5) + -1;
      }
    }
    else {
      *(short *)((int)pfVar4 + 0x12) = *(short *)((int)pfVar4 + 0x12) + -1;
      if (((this != (ObjInstance *)0x0) && (this->hitstate != (HitState *)0x0)) &&
         ((this->hitstate->field15_0x50 < 0x46 &&
          ((pOVar1 = this->hitstate->curTouchedObject, pOVar1 != DAT_80399d38 &&
           (pOVar1->objId == 0x29)))))) {
        if (((int)(this->pos).rotation.x & 0x8000U) == 0) {
                    /* {@symbol 800d0bec} */
          iVar2 = (**(code **)(*(int *)pDll_checkpoint + 0x6c))();
                    /* {@symbol 800d0bf4} */
          (**(code **)(*(int *)pDll_checkpoint + 0x70))(iVar2 + -1);
        }
        else {
                    /* {@symbol 800d0bdc} */
          iVar2 = (**(code **)(*(int *)pDll_checkpoint + 100))();
                    /* {@symbol 800d0be4} */
          (**(code **)(*(int *)pDll_checkpoint + 0x68))(iVar2 + -1);
        }
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,9,0,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,5,0,4,0xffffffff,0);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x40,0x7f,"cannon.c",(int *)0xd4);
        DAT_80399d38 = pOVar1;
        FUN_80090ef4(0x35,0,(ObjInstance *)0x0,0xe0000,(uint)this);
        Object_objFreeObject(pOVar1);
        Object_objFreeObject(this);
      }
    }
  }
  else if (sVar3 < 4) {
    objMultPosByMtx(this,&local_54,&local_58,&local_5c);
    def = objAlloc(0x18,0x2b);
    (def->pos).x = local_54;
    (def->pos).y = local_58 + 30.0;
    (def->pos).z = local_5c;
    pOVar1 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
    sVar3 = (this->pos).rotation.x;
    if (this->pMatrix != (ObjInstance *)0x0) {
      sVar3 = sVar3 + (this->pMatrix->pos).rotation.x;
    }
    sVar3 = sVar3 + 0x4000;
    uStack_34 = (int)sVar3 ^ 0x80000000;
    local_38 = 0x43300000;
    dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_34) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    (pOVar1->vel).x = (float)(dVar5 * 7.0);
    uStack_3c = (int)sVar3 ^ 0x80000000;
    local_40 = 0x43300000;
    dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_3c) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    (pOVar1->vel).z = (float)(dVar5 * 7.0);
    uStack_44 = (int)sVar3 ^ 0x80000000;
    local_48 = 0x43300000;
    dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_44) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    (pOVar1->pos).pos.x = (float)(dVar5 * 80.0 + (double)(pOVar1->pos).pos.x);
    uStack_4c = (int)sVar3 ^ 0x80000000;
    local_50 = 0x43300000;
    dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_4c) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    (pOVar1->pos).pos.z = (float)(dVar5 * 80.0 + (double)(pOVar1->pos).pos.z);
    pOVar1->field76_0xf4 = 300;
    enableCameraYOffset();
    FUN_8006ae50(0.8999999761581421);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x69,0,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,2,0,4,0xffffffff,0);
    audioTryStartSfx((int *)this,0x20,0x1f2,0x7f,"cannon.c",0xb7);
    *(undefined2 *)((int)pfVar4 + 0x16) = 4;
    *(undefined2 *)((int)pfVar4 + 0x12) = 0x14;
    *(undefined2 *)(pfVar4 + 5) = 0x1e;
    *pfVar4 = 0.0;
  }
  return;
}


/* @description Override hit detection */

void cannon_hitDetect(ObjInstance *this) { //801CB85C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void cannon_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801CB860
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

void cannon_free(ObjInstance *this,int param2) { //801CB8BC
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 cannon_func08(ObjInstance *this) { //801CB8F4
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int cannon_getExtraSize(void) { //801CB8FC
  return 0x1c;
}

