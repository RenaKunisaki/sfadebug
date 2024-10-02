
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CRsnowClaw_initialise(undefined4 param) { //802A99AC
  return;
}


/* @description Called when DLL is unloaded */

void CRsnowClaw_release(void) { //802A99B0
  return;
}


/* Library Function - Single Match
    CRsnowClaw_func03
   
   Library: KioskDefault 0 0 */

void CRsnowClaw_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802A99B4
  undefined4 *puVar1;
  
  this->fptr_0xbc = FUN_802aa190;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x4000;
    (this->shadow->color).b = 100;
    (this->shadow->color).a = 0x96;
  }
  puVar1 = (undefined4 *)this->state;
  *puVar1 = 0;
  *(undefined *)(puVar1 + 0xd) = *(undefined *)((int)&objDef[1].pos.y + 3);
  *(undefined *)((int)puVar1 + 0x36) = 4;
  *(undefined *)((int)puVar1 + 0x37) = 0xff;
  puVar1[1] = &DAT_80398108 + *(char *)((int)&objDef[1].pos.y + 2) * 4;
  timerSet((short *)(puVar1 + 0xc),200);
  return;
}


/* Library Function - Single Match
    CRsnowClaw_func04
   
   Library: KioskDefault 0 0 */

void CRsnowClaw_update(ObjInstance *param1) { //802A9A68
  float fVar1;
  ObjDefEnum OVar2;
  char cVar3;
  ObjInstance **ppOVar4;
  uint uVar5;
  ObjInstance *param2;
  int unaff_r27;
  int iVar6;
  ObjInstance **ppOVar7;
  double dVar8;
  int local_34;
  longlong local_30;
  
  _savefpr_30();
  ppOVar7 = (ObjInstance **)param1->state;
  *(undefined *)((int)ppOVar7 + 0x33) = 0;
  *(undefined *)((int)ppOVar7 + 0x32) = 0xff;
  if (*(char *)((int)ppOVar7 + 0x36) < '\0') {
    cVar3 = *(char *)((int)ppOVar7 + 0x36) + -1;
    *(char *)((int)ppOVar7 + 0x36) = cVar3;
    if (cVar3 < -2) {
      objFreeFn_80083b54(param1);
      (param1->pos).flags = (param1->pos).flags | Invisible;
      objFreeFn_80083b54(*ppOVar7);
      ((*ppOVar7)->pos).flags = ((*ppOVar7)->pos).flags | Invisible;
    }
    else {
      *(char *)((int)ppOVar7 + 0x36) = *(char *)((int)ppOVar7 + 0x36) + -1;
    }
    goto LAB_802a9d04;
  }
  dVar8 = (double)FUN_802aa688();
  if (*ppOVar7 == (ObjInstance *)0x0) {
    ppOVar4 = Object_playerGetObject(0xb,&local_34);
    if (ppOVar4 == (ObjInstance **)0x0) {
      printf((char *)&PTR_DAT_80323058);
    }
    OVar2 = param1->romdefno;
    if (OVar2 == CRSnowClaw2) {
      unaff_r27 = 0x38e;
    }
    else if ((short)OVar2 < 0x38a) {
      if ((short)OVar2 < 0x389) {
LAB_802a9b7c:
        printf(" Not A Bike Riding Object ");
      }
      else {
        unaff_r27 = 0x38d;
      }
    }
    else {
      if (OVar2 != CRSnowClaw3) goto LAB_802a9b7c;
      unaff_r27 = 0x4d4;
    }
    for (iVar6 = 0; iVar6 < local_34; iVar6 = iVar6 + 1) {
      if (unaff_r27 == (short)ppOVar4[iVar6]->romdefno) {
        *ppOVar7 = ppOVar4[iVar6];
        iVar6 = local_34;
      }
    }
  }
  uVar5 = mainGetBit((int)(ppOVar7[1]->pos).rotation.x);
  if (uVar5 != 0) {
    if (((param1->romdefno != CRSnowClaw) && (*ppOVar7 != (ObjInstance *)0x0)) &&
       (iVar6 = timerTickDown((short *)(ppOVar7 + 0xc)), iVar6 != 0)) {
      iVar6 = randInt(0,2);
      FUN_802aa6b4((int)*ppOVar7,(byte)iVar6);
      dVar8 = (double)timerSet((short *)(ppOVar7 + 0xc),200);
    }
    if (*ppOVar7 != (ObjInstance *)0x0) {
      dVar8 = (double)FUN_802aa564(param1,(int)*ppOVar7);
    }
    if (*ppOVar7 == (ObjInstance *)0x0) {
      *(undefined *)((int)ppOVar7 + 0x32) = 0xff;
      if (param1->shadow != (Shadow *)0x0) {
        param1->shadow->flags = param1->shadow->flags & 0xffffefff;
      }
    }
    else {
      param2 = Object_objGetMain();
      objDistObj2Obj(*ppOVar7,param2);
      fVar1 = (float)(dVar8 - 600.0) / 50.0;
      if (0.0 <= fVar1) {
        if (1.0 < fVar1) {
          fVar1 = 1.0;
        }
      }
      else {
        fVar1 = 0.0;
      }
      iVar6 = (int)((1.0 - fVar1) * 255.0);
      local_30 = (longlong)iVar6;
      *(char *)((int)ppOVar7 + 0x32) = (char)iVar6;
      if (param1->shadow != (Shadow *)0x0) {
        param1->shadow->flags = param1->shadow->flags | 0x1000;
      }
    }
    *(undefined *)((int)ppOVar7 + 0x32) = 0xff;
  }
LAB_802a9d04:
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    CRsnowClaw_func05
   
   Library: KioskDefault 0 0 */

void CRsnowClaw_hitDetect(ObjInstance *this) { //802A9D20
  int iVar1;
  ObjInstance *pOVar2;
  int *piVar3;
  double dVar4;
  undefined4 uStack_34;
  float local_30 [2];
  undefined4 local_28;
  uint uStack_24;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  piVar3 = (int *)this->state;
  local_30[0] = 500.0;
  iVar1 = FUN_800883e4((int)this,&uStack_34,(int *)0x0,(uint *)0x0);
  if (iVar1 == 0x15) {
    if (*(char *)((int)piVar3 + 0x37) < '\0') {
      *(char *)((int)piVar3 + 0x36) = *(char *)((int)piVar3 + 0x36) + -1;
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x58,0x7f,"CRsnowclaw.c",(int *)0x143);
      audioTryStartSfx((int *)this,1,0x1ca,0x7f,"CRsnowclaw.c",0x144);
      *(undefined *)((int)piVar3 + 0x37) = 0x14;
      if (*(char *)((int)piVar3 + 0x36) < '\0') {
        FUN_80088da4((int)this);
        if (*piVar3 != 0) {
          (**(code **)(**(int **)(*piVar3 + 0x68) + 0x3c))(*piVar3,0);
        }
        if ((this->romdefno == CRSnowClaw) &&
           (pOVar2 = getSeqObj(0x20,this,local_30), pOVar2 != (ObjInstance *)0x0)) {
          (*(code *)pOVar2->dll->ptrs2->setScale)(pOVar2,2);
        }
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,3);
        uStack_14 = (int)(this->pos).rotation.x ^ 0x80000000;
        local_18 = 0x43300000;
        dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_14)
                                                             - 4503601774854144.0) * 3.141593) /
                                                    32767.0));
        piVar3[9] = (int)(float)(dVar4 * 0.1000000014901161);
        uStack_1c = randInt(0x28,100);
        uStack_1c = uStack_1c ^ 0x80000000;
        local_20 = 0x43300000;
        piVar3[10] = (int)((float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) *
                          0.01);
        uStack_24 = (int)(this->pos).rotation.x ^ 0x80000000;
        local_28 = 0x43300000;
        dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
        ;
        piVar3[0xb] = (int)(float)(dVar4 * 0.1000000014901161);
      }
    }
  }
  if (*piVar3 != 0) {
    iVar1 = (**(code **)(**(int **)(*piVar3 + 0x68) + 0x38))(*piVar3);
    if (iVar1 == 2) {
      FUN_802aa414((undefined2 *)this,(undefined2 *)*piVar3,0,0,0,0,'\0',0,0);
    }
  }
  if (-1 < *(char *)((int)piVar3 + 0x37)) {
    *(u8 *)((int)piVar3 + 0x37) = *(char *)((int)piVar3 + 0x37) - framesThisStep;
  }
  return;
}


/* Library Function - Single Match
    CRsnowClaw_func06
   
   Library: KioskDefault 0 0 */

void CRsnowClaw_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //802A9FAC
  u8 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjInstance *pOVar5;
  ObjInstance **ppOVar6;
  float local_38 [3];
  
  local_38[0] = 5000.0;
  ppOVar6 = (ObjInstance **)this->state;
  pOVar5 = *ppOVar6;
  bVar2 = false;
  if (((-1 < *(char *)((int)ppOVar6 + 0x36)) && (pOVar5 != (ObjInstance *)0x0)) &&
     (iVar3 = (*pOVar5->dll->ptrs2[1].update)(pOVar5), iVar3 == 2)) {
    bVar2 = true;
  }
  if (bVar2) {
    (this->pos).flags = (this->pos).flags | DontTrackOldPositions;
    shouldRender = (bool)objUpdateOpacity(pOVar5);
    FUN_802aa414((undefined2 *)this,(undefined2 *)pOVar5,
                 (Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5),shouldRender,
                 (uint)*(byte *)((int)ppOVar6 + 0x32),1);
  }
  else {
    (this->pos).flags = (this->pos).flags & ~DontTrackOldPositions;
  }
  this->child[0] = (ObjInstance *)0x0;
  if ((shouldRender != false) && (*(char *)((int)ppOVar6 + 0x32) != '\0')) {
    uVar1 = this->opacity;
    if (bVar2) {
      this->opacity = *(u8 *)((int)ppOVar6 + 0x32);
    }
    if (this->romdefno == CRSnowClaw) {
      uVar4 = mainGetBit((int)(ppOVar6[1]->pos).rotation.x);
      if (((uVar4 != 0) && (pOVar5 = getSeqObj(0x20,this,local_38), pOVar5 != (ObjInstance *)0x0))
         && ((iVar3 = (*(code *)pOVar5->dll->ptrs2->field9_0x24)(pOVar5), iVar3 != 0 &&
             (iVar3 = (*(code *)pOVar5->dll->ptrs2->setScale)(pOVar5,0), iVar3 != 0)))) {
        this->child[0] = pOVar5;
      }
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    objGetAttachPointWorldPos
              (this,1,(float *)(ppOVar6 + 6),(float *)(ppOVar6 + 7),(float *)(ppOVar6 + 8),FALSE);
    this->opacity = uVar1;
  }
  return;
}


/* @description Free object instance */

void CRsnowClaw_free(ObjInstance *this,int param2) { //802AA17C
  return;
}


undefined4 CRsnowClaw_func08(ObjInstance *this) { //802AA180
  return 3;
}


/* @description Get extra size for object (size of State struct) */

int CRsnowClaw_getExtraSize(void) { //802AA188
  return 0x38;
}


void FUN_802aa6b4(int param_1,byte param_2) { //802AA6B4
  ObjDef *def;
  int iVar1;
  
  Object_objGetMain();
  if (param_1 == 0) {
                    
    OSPanic("CRsnowclaw.c",0x290,"Failed assertion obj");
  }
  if (param_2 < 3) {
    def = objAlloc(0x24,CRDropBomb);
    def->objType = CRDropBomb;
    def->loadFlags = isManualLoad;
    def->bound = 0xff;
    def->mapStates2 = 1;
    def->cullDist = 0xff;
    *(byte *)((int)&def[1].objType + 1) = param_2;
    (def->pos).x = *(float *)(param_1 + 0xc);
    (def->pos).y = *(float *)(param_1 + 0x10) + 4.0;
    (def->pos).z = *(float *)(param_1 + 0x14);
    iVar1 = getAngle();
    *(char *)&def[1].objType = (char)((uint)iVar1 >> 8);
    if (param_2 == 1) {
      iVar1 = getAngle();
      *(short *)&def[1].allocatedSize = (short)iVar1 + -0x8000;
    }
    else if ((param_2 == 0) && (true)) {
      def[1].allocatedSize = 0;
      def[1].mapStates1 = 0x96;
    }
    objInstantiateCharacter(def,5,-1,-1,*(ObjInstance **)(param_1 + 0x30));
    return;
  }
                    
  OSPanic("CRsnowclaw.c",0x291,s_Failed_assertion_type>_0____type_80323100);
}

