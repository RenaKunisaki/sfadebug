
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBshipgun_initialise(undefined4 param) { //80262FE8
  return;
}


/* @description Called when DLL is unloaded */

void SBshipgun_release(void) { //80262FEC
  return;
}


/* Library Function - Single Match
    dll_22D_func03
   
   Library: KioskDefault 0 0 */

void SBshipgun_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //80262FF0
  undefined *puVar1;
  
  puVar1 = this->state;
  puVar1[0xf] = 0;
  puVar1[0xe] = 2;
  puVar1[0x10] = 0;
  return;
}


/* Library Function - Single Match
    dll_22D_func04
   
   Library: KioskDefault 0 0 */

void SBshipgun_update(ObjInstance *this) { //80263020
  char cVar1;
  ObjInstance *pOVar2;
  undefined2 *puVar3;
  ObjInstance **ppOVar4;
  int iVar5;
  int iVar6;
  ObjDef *def;
  ObjectFuncPtrs2 *pOVar7;
  vec3f *in_r5;
  vec3f *pvVar8;
  ObjDef *pOVar9;
  char *pcVar10;
  ObjInstance *this_00;
  ObjInstance **ppOVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  short local_c4;
  undefined2 local_c2;
  undefined2 local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  undefined4 local_ac;
  int local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c [11];
  undefined4 local_60;
  uint uStack_5c;
  
  _savefpr_29();
  pcVar10 = "shipgun.c";
  pOVar2 = Object_objGetMain();
  ppOVar11 = (ObjInstance **)this->state;
  pOVar9 = this->def;
  local_ac = 0;
  puVar3 = (undefined2 *)objGetJoint((int)this,0);
  if (this->pMatrix->romdefno == WM_Galleon) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    *(undefined *)((int)ppOVar11 + 0xf) = 0;
  }
  else {
    if (*ppOVar11 == (ObjInstance *)0x0) {
      ppOVar4 = Object_getObjects(&local_a4,&local_a8);
      for (; local_a4 < local_a8; local_a4 = local_a4 + 1) {
        if (ppOVar4[local_a4]->romdefno == SB_Cloudrun) {
          *ppOVar11 = ppOVar4[local_a4];
          local_a4 = local_a8;
        }
      }
    }
    this_00 = this->pMatrix;
    if ((this_00 == (ObjInstance *)0x0) || (this_00->romdefno != SB_Galleon)) {
      iVar5 = 0;
      *(undefined *)(ppOVar11 + 3) = 4;
    }
    else {
      iVar5 = (*(code *)this_00->dll->ptrs2->field9_0x24)(this_00);
    }
    *(undefined *)((int)ppOVar11 + 0xf) = 1;
    cVar1 = *(char *)(ppOVar11 + 3);
    if (cVar1 == '\x02') {
      if (this->animId != 0) {
        Object_ObjAnimSetMove(0.5,this,0,0);
      }
      this->hitstate->flags = this->hitstate->flags | 1;
      pvVar8 = (vec3f *)0x0;
      iVar5 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
      if (iVar5 != 0) {
        *(undefined2 *)((int)ppOVar11 + 10) = 0xff;
        pvVar8 = (vec3f *)pcVar10;
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x211,0x7f,"shipgun.c",(int *)0xac);
        *(char *)((int)ppOVar11 + 0xd) = *(char *)((int)ppOVar11 + 0xd) + '\x01';
        if (*(char *)((int)ppOVar11 + 0xd) == '\x02') {
          *(undefined *)(ppOVar11 + 3) = 3;
          if (this_00 != (ObjInstance *)0x0) {
            (*(code *)this_00->dll->ptrs2->setScale)(this_00);
          }
        }
        else if (*(char *)((int)ppOVar11 + 0xd) == '\x04') {
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x1f7,0x7f,"shipgun.c",(int *)0xb2)
          ;
          *(undefined *)(ppOVar11 + 3) = 3;
          pvVar8 = (vec3f *)pcVar10;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            pvVar8 = (vec3f *)0x0;
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x9b,0,2,0xffffffff,0);
          }
          if (this_00 != (ObjInstance *)0x0) {
            (*(code *)this_00->dll->ptrs2->setScale)(this_00);
          }
        }
      }
      if ((this_00 != (ObjInstance *)0x0) &&
         (pOVar7 = this_00->dll->ptrs2, iVar5 = (*pOVar7->modelMtxFn_0x28)(this_00,pOVar7,pvVar8),
         iVar5 != 0)) {
        *(undefined *)(ppOVar11 + 3) = 3;
      }
      dVar12 = (double)((pOVar2->prevPos).x - (this->prevPos).x);
      dVar14 = (double)((pOVar2->prevPos).z - (this->prevPos).z);
      iVar5 = getAngle();
      (this->pos).rotation.x = (short)(iVar5 << 1);
      sqrt((double)(float)(dVar12 * dVar12 + (double)(float)(dVar14 * dVar14)));
      iVar5 = getAngle();
      *(short *)((int)ppOVar11 + 6) = (short)iVar5;
      if (*(short *)((int)ppOVar11 + 6) < 0x1f41) {
        if (*(short *)((int)ppOVar11 + 6) < -8000) {
          *(undefined2 *)((int)ppOVar11 + 6) = 0xe0c0;
        }
      }
      else {
        *(undefined2 *)((int)ppOVar11 + 6) = 8000;
      }
      *puVar3 = *(undefined2 *)((int)ppOVar11 + 6);
      *(ushort *)(ppOVar11 + 2) = *(short *)(ppOVar11 + 2) - (ushort)framesThisStep;
      if (*(short *)(ppOVar11 + 2) < 0) {
        objMultPosByMtx(this,local_8c,&local_90,&local_94);
        local_b8 = 0.0;
        local_b4 = 0.0;
        local_b0 = 0.0;
        local_bc = 1.0;
        local_c4 = (this->pos).rotation.x;
        local_c2 = 0;
        local_c0 = 0;
        local_a0 = 100.0;
        local_9c = 135.0;
        local_98 = 0.0;
        FUN_8007a878(&local_c4,&local_a0);
        pOVar9 = objAlloc(0x18,SB_CannonBa);
        (pOVar9->pos).x = local_8c[0] + local_a0;
        (pOVar9->pos).y = local_90 + local_9c;
        (pOVar9->pos).z = local_94 + local_98;
        pOVar9->loadFlags = isManualLoad;
        pOVar9->mapStates2 = 1;
        pOVar9->bound = 0xff;
        pOVar9->cullDist = 0xff;
        pOVar2 = objInstantiateCharacter(pOVar9,5,-1,-1,(ObjInstance *)0x0);
        dVar13 = (double)(((*ppOVar11)->prevPos).x - (this->prevPos).x);
        dVar14 = (double)(((*ppOVar11)->prevPos).y - ((this->prevPos).y + 100.0));
        dVar15 = (double)(((*ppOVar11)->prevPos).z - (this->prevPos).z);
        dVar12 = sqrt((double)(float)(dVar15 * dVar15 +
                                     (double)(float)(dVar13 * dVar13 +
                                                    (double)(float)(dVar14 * dVar14))));
        local_8c[0] = 10.0 / (float)dVar12;
        (pOVar2->vel).x = (float)(dVar13 * (double)local_8c[0]);
        (pOVar2->vel).y = (float)(dVar14 * (double)local_8c[0]);
        (pOVar2->vel).z = (float)(dVar15 * (double)local_8c[0]);
        (pOVar2->pos).pos.x = (pOVar2->vel).x * 8.0 + (pOVar2->pos).pos.x;
        (pOVar2->pos).pos.y = (pOVar2->vel).y * 8.0 + (pOVar2->pos).pos.y;
        (pOVar2->pos).pos.z = (pOVar2->vel).z * 8.0 + (pOVar2->pos).pos.z;
        iVar5 = getAngle();
        (pOVar2->pos).rotation.x = (short)iVar5;
        pOVar2->field76_0xf4 = 0xb4;
        pOVar2->flags_0xf8 = (dword)*ppOVar11;
        enableCameraYOffset();
        FUN_8006ae50(0.1000000014901161);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x96,0x7f,"shipgun.c",(int *)0x107);
        *(char *)(ppOVar11 + 4) = *(char *)(ppOVar11 + 4) + '\x01';
        if (*(char *)(ppOVar11 + 4) == '\x03') {
          *(undefined2 *)(ppOVar11 + 2) = 0x10e;
          *(undefined *)(ppOVar11 + 4) = 0;
        }
        else {
          *(undefined2 *)(ppOVar11 + 2) = 0xa0;
        }
      }
    }
    else if (cVar1 < '\x02') {
      if (cVar1 == '\0') {
        *(undefined *)((int)ppOVar11 + 0xf) = 0;
        if (this->animId != 1) {
          in_r5 = (vec3f *)0x0;
          Object_ObjAnimSetMove(0.0,this,1,0);
        }
        uStack_5c = (uint)framesThisStep;
        local_60 = 0x43300000;
        objRunAnimation(0.0,(double)(float)((double)CONCAT44(0x43300000,uStack_5c) -
                                           4503599627370496.0),(int)this,(float *)0x0);
        if ((this_00 != (ObjInstance *)0x0) &&
           (pOVar7 = this_00->dll->ptrs2, iVar6 = (*pOVar7->modelMtxFn_0x28)(this_00,pOVar7,in_r5),
           iVar6 == 0)) {
          if (*(char *)((int)&pOVar9[1].objType + 1) == '\0') {
            if ((iVar5 == 0) || (iVar5 == 3)) {
              *(undefined *)(ppOVar11 + 3) = 1;
            }
          }
          else if ((iVar5 == 1) || (iVar5 == 4)) {
            *(undefined *)(ppOVar11 + 3) = 1;
          }
        }
        if (*(char *)(ppOVar11 + 3) == '\x01') {
          audioTryStartSfx((int *)this,1,0xf0,0x7f,"shipgun.c",0x93);
        }
        this->hitstate->flags = this->hitstate->flags & 0xfffe;
      }
      else if (-1 < cVar1) {
        if ((this_00 != (ObjInstance *)0x0) &&
           (pOVar7 = this_00->dll->ptrs2, iVar5 = (*pOVar7->modelMtxFn_0x28)(this_00,pOVar7,in_r5),
           iVar5 != 0)) {
          *(undefined *)(ppOVar11 + 3) = 3;
        }
        this->hitstate->flags = this->hitstate->flags & 0xfffe;
        if (this->animId != 1) {
          Object_ObjAnimSetMove(0.0,this,1,0);
        }
        uStack_5c = (uint)framesThisStep;
        local_60 = 0x43300000;
        iVar5 = objRunAnimation(0.009999999776482582,
                                (double)(float)((double)CONCAT44(0x43300000,uStack_5c) -
                                               4503599627370496.0),(int)this,(float *)0x0);
        if (iVar5 != 0) {
          *(undefined *)(ppOVar11 + 3) = 2;
        }
        *(undefined2 *)(ppOVar11 + 2) = 0x50;
      }
    }
    else if (cVar1 == '\x04') {
      Object_objFreeObject(this);
    }
    else if (cVar1 < '\x04') {
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
      objMultPosByMtx(this,local_8c,&local_90,&local_94);
      if (this->animId != 1) {
        for (iVar5 = 0; iVar5 < 6; iVar5 = iVar5 + 1) {
          if (*(char *)((int)ppOVar11 + 0xe) == '\x01') {
            def = objAlloc(0x18,SH_YellowWh);
            (def->pos).x = local_8c[0];
            (def->pos).y = local_90 + 135.0;
            (def->pos).z = local_94;
            def->loadFlags = isManualLoad;
            def->mapStates2 = 2;
            def->bound = 0xff;
            def->cullDist = 0xff;
            objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
          }
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x9b,0,2,0xffffffff,0);
          mainSetBits(*(char *)((int)&pOVar9[1].objType + 1) + 0x906,1);
        }
        if ('\0' < *(char *)((int)ppOVar11 + 0xe)) {
          *(char *)((int)ppOVar11 + 0xe) = *(char *)((int)ppOVar11 + 0xe) + -1;
        }
        Object_ObjAnimSetMove(1.0,this,1,0);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0xf0,0x7f,"shipgun.c",(int *)0x12a);
      }
      uStack_5c = (uint)framesThisStep;
      local_60 = 0x43300000;
      iVar5 = objRunAnimation(-0.009999999776482582,
                              (double)(float)((double)CONCAT44(0x43300000,uStack_5c) -
                                             4503599627370496.0),(int)this,(float *)0x0);
      if (iVar5 != 0) {
        *(undefined *)(ppOVar11 + 3) = 0;
      }
    }
  }
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    dll_22D_func05
   
   Library: KioskDefault 0 0 */

void SBshipgun_hitDetect(ObjInstance *this) { //80263934
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((0 < *(short *)(puVar1 + 10)) &&
     (*(ushort *)(puVar1 + 10) = *(short *)(puVar1 + 10) + (ushort)framesThisStep * -3,
     *(short *)(puVar1 + 10) < 0)) {
    *(undefined2 *)(puVar1 + 10) = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_22D_func06
   
   Library: KioskDefault 0 0 */

void SBshipgun_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //80263980
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  
  puVar2 = this->state;
  if ((this->pMatrix != (ObjInstance *)0x0) && (this->pMatrix->romdefno == WM_Galleon)) {
    return;
  }
  if ((((!shouldRender) || (puVar2[0xe] == '\0')) || (puVar2[0xf] == '\0')) &&
     (bVar1 = checkSomeDebugFlags_8017c4f8(), !bVar1)) {
    return;
  }
  if (*(short *)(puVar2 + 10) != 0) {
    FUN_80096afc(0xff,0xff - *(short *)(puVar2 + 10),0xff - *(short *)(puVar2 + 10));
  }
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void SBshipgun_free(ObjInstance *this,int param2) { //80263A4C
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 SBshipgun_func08(ObjInstance *this) { //80263A84
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SBshipgun_getExtraSize(void) { //80263A8C
  return 0x14;
}

