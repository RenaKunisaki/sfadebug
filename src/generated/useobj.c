
/* Library Function - Single Match
    useObj_func03
   
   Library: KioskDefault 0 0 */

void useObj_init(ObjInstance *param1,short *param2,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801DBA08
  uint uVar1;
  char *pcVar2;
  
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0xc) << 8;
  (param1->pos).rotation.y = (ushort)*(byte *)((int)param2 + 0x19) << 8;
  (param1->pos).rotation.z = (ushort)*(byte *)(param2 + 0xd) << 8;
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801dbe0c;
  param1->curModel = *(byte *)((int)param2 + 0x21);
  if (param1->data->nModels <= (char)param1->curModel) {
    param1->curModel = 0;
    printf((char *)&PTR_DAT_80311a78,(int)*param2);
  }
  pcVar2 = param1->state;
  uVar1 = mainGetBit((int)param2[0xe]);
  *pcVar2 = (char)uVar1;
  Object_objAddObjectType(param1,0x11);
  if (((*(byte *)((int)param2 + 0x1b) & 1) != 0) && (*pcVar2 != '\0')) {
    param1->newOpacity = 0;
  }
  return;
}


/* Library Function - Single Match
    useObj_func04
   
   Library: KioskDefault 0 0 */

void useObj_update(ObjInstance *this) { //801DBAEC
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  ObjDef *pOVar8;
  
  pcVar7 = this->state;
  pOVar8 = this->def;
  sVar1._0_1_ = pOVar8[1].loadFlags;
  sVar1._1_1_ = pOVar8[1].mapStates2;
  uVar5 = mainGetBit((int)sVar1);
  *pcVar7 = (char)uVar5;
  if (((pOVar8[1].mapStates1 & 1) != 0) && (*pcVar7 != '\0')) {
    this->newOpacity = 0;
  }
  if (*pcVar7 == '\0') {
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    if (*(short *)((int)&pOVar8[1].pos.x + 2) == -1) {
      this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
    }
    else {
      uVar5 = mainGetBit((int)*(short *)((int)&pOVar8[1].pos.x + 2));
      if (uVar5 == 0) {
        this->flags_0xaf = this->flags_0xaf | PlayerIsDisguised;
        if ((pOVar8[1].mapStates1 & 0x10) != 0) {
          this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
        }
      }
      else {
        this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
      }
    }
                    /* {@symbol 8016db80} */
    if (((this->flags_0xaf & CanPressAToTalk) != 0) &&
       ((sVar2._0_1_ = pOVar8[1].bound, sVar2._1_1_ = pOVar8[1].cullDist, sVar2 == -1 ||
        (sVar3._0_1_ = pOVar8[1].bound, sVar3._1_1_ = pOVar8[1].cullDist,
        iVar6 = (**(code **)(*pdll_camcontrol + 0x20))((int)sVar3), iVar6 != 0)))) {
      if (*(char *)&pOVar8[1].pos.x != -1) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))
                  ((int)*(char *)&pOVar8[1].pos.x,this,0xffffffff);
      }
      if ((pOVar8[1].mapStates1 & 4) == 0) {
        sVar4._0_1_ = pOVar8[1].loadFlags;
        sVar4._1_1_ = pOVar8[1].mapStates2;
        mainSetBits((int)sVar4,1);
      }
      if ((pOVar8[1].mapStates1 & 8) == 0) {
        *pcVar7 = '\x01';
        this->field76_0xf4 = 1;
      }
      else {
        mainSetBits((int)*(short *)((int)&pOVar8[1].pos.x + 2),0);
      }
      disableButtons(0,PAD_BUTTON_A);
    }
  }
  else {
    if (this->field76_0xf4 == 0) {
      if (*(char *)&pOVar8[1].pos.x != -1) {
        if (*(short *)&pOVar8[1].pos.y != 0) {
                    /* {@symbol 800d0a70} */
          (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)*(short *)&pOVar8[1].pos.y);
          uVar5 = 1;
          if ((pOVar8[1].mapStates1 & 0x20) != 0) {
            uVar5 = 3;
          }
          if ((pOVar8[1].mapStates1 & 0x40) != 0) {
            uVar5 = uVar5 | 4;
          }
          if ((pOVar8[1].mapStates1 & 0x80) != 0) {
            uVar5 = uVar5 | 8;
          }
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)*(char *)&pOVar8[1].pos.x,this,uVar5);
        }
      }
      this->field76_0xf4 = 1;
    }
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1AA_func05
    dll_28C_func05
    dll_2DD_func05
    interactObj_func05
     6 names - too many to list
   
   Library: KioskDefault 0 0 */

void useObj_hitDetect(ObjInstance *this) { //801DBD30
  if (((this->data->flags & HaveModels) != 0) && (this->field25_0x74 != (vec3f *)0x0)) {
    renderGCModel(this);
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void useObj_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801DBD7C
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


/* Library Function - Multiple Matches With Different Base Names
    dll_115_func07
    dll_20A_func07
    newSeqObj_func07
    seqObj11D_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void useObj_free(ObjInstance *this,int param2) { //801DBDD8
  Object_removePlayerObj(this,0x11);
  return;
}


/* @description Get extra size for object (size of State struct) */

int useObj_getExtraSize(void) { //801DBE04
  return 1;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void useobj28C_initialise(undefined4 param) { //802A57D0
  return;
}


/* @description Called when DLL is unloaded */

void useobj28C_release(void) { //802A57D4
  return;
}


/* Library Function - Single Match
    dll_28C_func03
   
   Library: KioskDefault 0 0 */

void useobj28C_init(ObjInstance *param1,short *param2,int param3,DllInitFlags flags,float x,float y
                    ,float z) { //802A57D8
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  printf("def bits %d %d %d",(int)param2[0xe],(int)param2[0xf],(int)param2[0x11]);
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0xc) << 8;
  (param1->pos).rotation.y = (ushort)*(byte *)((int)param2 + 0x19) << 8;
  (param1->pos).rotation.z = (ushort)*(byte *)(param2 + 0xd) << 8;
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802a5ca8;
  param1->curModel = *(byte *)((int)param2 + 0x21);
  if (param1->data->nModels <= (char)param1->curModel) {
    param1->curModel = 0;
    printf("USEOBJ.c: modelno out of range romdefno=%d",(int)*param2);
  }
  piVar5 = (int *)param1->state;
  uVar1 = mainGetBit((int)param2[0xe]);
  *(byte *)((int)piVar5 + 0xd) = (byte)(uVar1 << 7) | *(byte *)((int)piVar5 + 0xd) & 0x7f;
  uVar1 = mainGetBit(0x83f);
  *(char *)(piVar5 + 3) = (char)uVar1;
  if (param3 == 0) {
    iVar3 = 0;
    piVar4 = piVar5;
    while( true ) {
      if ((int)(uint)*(byte *)(piVar5 + 3) <= iVar3) break;
      iVar2 = FUN_802a5f40((int)param1);
      *piVar4 = iVar2;
      *(ushort *)(*piVar4 + 6) = *(ushort *)(*piVar4 + 6) | 0x4000;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    }
  }
  param1->field76_0xf4 = 0;
  Object_objAddObjectType(param1,0x11);
  if (((*(byte *)((int)param2 + 0x1b) & 1) != 0) && (*(char *)((int)piVar5 + 0xd) < '\0')) {
    param1->newOpacity = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_28C_func04
   
   Library: KioskDefault 0 0 */

void useobj28C_update(ObjInstance *this) { //802A5940
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  ObjDef *pOVar5;
  
  puVar4 = this->state;
  pOVar5 = this->def;
  sVar1._0_1_ = pOVar5[1].loadFlags;
  sVar1._1_1_ = pOVar5[1].mapStates2;
  uVar2 = mainGetBit((int)sVar1);
  puVar4[0xd] = (byte)(uVar2 << 7) | puVar4[0xd] & 0x7f;
  if (this->field76_0xf4 == 0) {
    if (*(short *)&pOVar5[1].pos.y != 0) {
      uVar3 = FUN_802a5f40((int)this);
      *(undefined4 *)(puVar4 + 8) = uVar3;
      *(ushort *)(*(int *)(puVar4 + 8) + 6) = *(ushort *)(*(int *)(puVar4 + 8) + 6) | 0x4000;
      if ((char)puVar4[0xd] < '\0') {
                    /* {@symbol 800d0a70} */
        (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)*(short *)&pOVar5[1].pos.y);
      }
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
    }
    this->field76_0xf4 = 1;
  }
  FUN_802a5e98((int)this);
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1AA_func05
    dll_28C_func05
    dll_2DD_func05
    interactObj_func05
     6 names - too many to list
   
   Library: KioskDefault 0 0 */

void useobj28C_hitDetect(ObjInstance *this) { //802A5A3C
  if (((this->data->flags & HaveModels) != 0) && (this->field25_0x74 != (vec3f *)0x0)) {
    renderGCModel(this);
  }
  return;
}


/* Library Function - Single Match
    dll_28C_func06
   
   Library: KioskDefault 0 0 */

void useobj28C_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802A5A88
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  int iVar1;
  ObjInstance **ppOVar2;
  ObjInstance **ppOVar3;
  Mtx44 MStack_68;
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  ppOVar3 = (ObjInstance **)this->state;
  if (shouldRender) {
    objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
    mtxSetFromObjPos(&MStack_68,&this->pos);
    if ((*(byte *)((int)ppOVar3 + 0xd) >> 5 & 1) != 0) {
      if (*(byte *)(ppOVar3 + 3) < 3) {
        multVectorByMatrix((double)(DAT_80322af0 * 6.4),(double)(DAT_80322af4 * 6.4),
                           (double)(DAT_80322af8 * 6.4),&MStack_68,&(ppOVar3[2]->pos).pos.x,
                           &(ppOVar3[2]->pos).pos.y,&(ppOVar3[2]->pos).pos.z);
        (ppOVar3[2]->pos).rotation.z = (this->pos).rotation.z + DAT_803980d4;
        (ppOVar3[2]->pos).rotation.x = (this->pos).rotation.x;
      }
    }
    if (((*(byte *)((int)ppOVar3 + 0xd) >> 6 & 1) == 0) && (ppOVar3[2] != (ObjInstance *)0x0)) {
      objRenderCurrentModel(ppOVar3[2],param2_00,param3_00,param4_00,param5_00);
    }
    ppOVar2 = ppOVar3;
    for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(ppOVar3 + 3); iVar1 = iVar1 + 1) {
      if (ppOVar2 != (ObjInstance **)0x0) {
        objRenderCurrentModel(*ppOVar2,param2_00,param3_00,param4_00,param5_00);
      }
      ppOVar2 = ppOVar2 + 1;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_28C_func07
   
   Library: KioskDefault 0 0 */

void useobj28C_free(ObjInstance *this,int param2) { //802A5BFC
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  if (param2 == 0) {
    for (iVar1 = 0; iVar1 < (int)(uint)(byte)puVar2[0xc]; iVar1 = iVar1 + 1) {
      if (*(int *)(puVar2 + iVar1 * 4) != 0) {
        Object_objFreeObject(*(ObjInstance **)(puVar2 + iVar1 * 4));
        *(undefined4 *)(puVar2 + iVar1 * 4) = 0;
      }
    }
    if (*(int *)(puVar2 + 8) != 0) {
      Object_objFreeObject(*(ObjInstance **)(puVar2 + 8));
    }
  }
  Object_removePlayerObj(this,0x11);
  return;
}


undefined4 useobj28C_func08(ObjInstance *this) { //802A5C98
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int useobj28C_getExtraSize(void) { //802A5CA0
  return 0x10;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void useobj2DD_initialise(undefined4 param) { //802C4368
  return;
}


/* @description Called when DLL is unloaded */

void useobj2DD_release(void) { //802C436C
  return;
}


/* Library Function - Single Match
    dll_2DD_func03
   
   Library: KioskDefault 0 0 */

void useobj2DD_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802C4370
  short sVar1;
  uint uVar2;
  char cVar4;
  undefined4 *puVar3;
  char *pcVar5;
  
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.z = (ushort)objDef[1].allocatedSize << 8;
  this->fptr_0xbc = sunTempleFn_80228478;
  this->curModel = *(byte *)((int)&objDef[1].pos.x + 1);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
    printf("USEOBJ.c: modelno out of range romdefno=%d",(int)(short)objDef->objType);
  }
  pcVar5 = this->state;
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  uVar2 = mainGetBit((int)sVar1);
  *pcVar5 = (char)uVar2;
                    /* {@symbol 8012dfa8} */
  cVar4 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  pcVar5[1] = cVar4;
  if (((objDef[1].mapStates1 & 1) != 0) && (*pcVar5 != '\0')) {
    this->newOpacity = 0;
  }
  if ((*pcVar5 != '\0') &&
     (puVar3 = (undefined4 *)FUN_80094400((int)this,0), puVar3 != (undefined4 *)0x0)) {
    *puVar3 = 0x100;
  }
  return;
}


/* Library Function - Single Match
    dll_2DD_func04
   
   Library: KioskDefault 0 0 */

void useobj2DD_update(ObjInstance *this) { //802C4498
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  ObjDef *pOVar9;
  
  pcVar8 = this->state;
  pOVar9 = this->def;
  sVar1._0_1_ = pOVar9[1].loadFlags;
  sVar1._1_1_ = pOVar9[1].mapStates2;
  uVar5 = mainGetBit((int)sVar1);
  *pcVar8 = (char)uVar5;
  if (*pcVar8 != '\0') {
    if ((this->field76_0xf4 == 0) && (*(char *)&pOVar9[1].pos.x != -1)) {
      if (*(short *)&pOVar9[1].pos.y != 0) {
                    /* {@symbol 800d0a70} */
        (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)*(short *)&pOVar9[1].pos.y);
        uVar5 = 1;
        if ((pOVar9[1].mapStates1 & 0x20) != 0) {
          uVar5 = 3;
        }
        if ((pOVar9[1].mapStates1 & 0x40) != 0) {
          uVar5 = 3;
        }
        if ((pOVar9[1].mapStates1 & 0x80) != 0) {
          uVar5 = uVar5 | 4;
        }
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)*(char *)&pOVar9[1].pos.x,this,uVar5);
      }
    }
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    goto LAB_802c47e4;
  }
  puVar6 = (undefined4 *)FUN_80094400((int)this,0);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0;
  }
  (this->pos).pos.x = (pOVar9->pos).x;
  (this->pos).pos.y = (pOVar9->pos).y;
  (this->pos).pos.z = (pOVar9->pos).z;
  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  if (*(short *)((int)&pOVar9[1].pos.x + 2) == -1) {
    this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
  }
  else {
    uVar5 = mainGetBit((int)*(short *)((int)&pOVar9[1].pos.x + 2));
    if (uVar5 == 0) {
      this->flags_0xaf = this->flags_0xaf | PlayerIsDisguised;
      if ((pOVar9[1].mapStates1 & 0x10) != 0) {
        this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      }
    }
    else {
      this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
    }
  }
                    /* {@symbol 8016db80} */
  if (((this->flags_0xaf & CanPressAToTalk) == 0) ||
     ((sVar2._0_1_ = pOVar9[1].bound, sVar2._1_1_ = pOVar9[1].cullDist, sVar2 != -1 &&
      (sVar3._0_1_ = pOVar9[1].bound, sVar3._1_1_ = pOVar9[1].cullDist,
      iVar7 = (**(code **)(*pdll_camcontrol + 0x20))((int)sVar3), iVar7 == 0)))) goto LAB_802c47e4;
  if (*(char *)&pOVar9[1].pos.x != -1) {
    if (this->romdefno == WCInvUseObj) {
      if (pcVar8[1] == '\x01') {
        uVar5 = mainGetBit(0x25a);
        if (uVar5 == 0) {
          uVar5 = mainGetBit(0x25b);
          if (uVar5 == 0) goto LAB_802c4620;
        }
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(*(char *)&pOVar9[1].pos.x + 2,this,0xffffffff)
        ;
      }
      else {
LAB_802c4620:
        if (pcVar8[1] == '\x02') {
          uVar5 = mainGetBit(0x202);
          if (uVar5 == 0) {
            uVar5 = mainGetBit(0x243);
            if (uVar5 == 0) goto LAB_802c4678;
          }
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))
                    (*(char *)&pOVar9[1].pos.x + 2,this,0xffffffff);
        }
        else {
LAB_802c4678:
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))
                    ((int)*(char *)&pOVar9[1].pos.x,this,0xffffffff);
        }
      }
    }
    else {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)*(char *)&pOVar9[1].pos.x,this,0xffffffff);
    }
  }
  if ((pOVar9[1].mapStates1 & 4) == 0) {
    sVar4._0_1_ = pOVar9[1].loadFlags;
    sVar4._1_1_ = pOVar9[1].mapStates2;
    mainSetBits((int)sVar4,1);
    puVar6 = (undefined4 *)FUN_80094400((int)this,0);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = 0x100;
    }
  }
  if ((pOVar9[1].mapStates1 & 8) == 0) {
    *pcVar8 = '\x01';
    this->field76_0xf4 = 1;
  }
  else {
    mainSetBits((int)*(short *)((int)&pOVar9[1].pos.x + 2),0);
  }
  disableButtons(0,PAD_BUTTON_A);
LAB_802c47e4:
  this->field76_0xf4 = 1;
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1AA_func05
    dll_28C_func05
    dll_2DD_func05
    interactObj_func05
     6 names - too many to list
   
   Library: KioskDefault 0 0 */

void useobj2DD_hitDetect(ObjInstance *this) { //802C4800
  if (((this->data->flags & HaveModels) != 0) && (this->field25_0x74 != (vec3f *)0x0)) {
    renderGCModel(this);
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void useobj2DD_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802C484C
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

void useobj2DD_free(ObjInstance *this,int param2) { //802C48A8
  return;
}


undefined4 useobj2DD_func08(ObjInstance *this) { //802C48AC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int useobj2DD_getExtraSize(void) { //802C48B4
  return 2;
}

