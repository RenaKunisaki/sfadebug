
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void animobjD2_initialise(undefined4 param) { //801C8AC4
  return;
}


/* @description Called when DLL is unloaded */

void animobjD2_release(void) { //801C8AC8
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_193_func03
    dll_D2_func03
   
   Library: KioskDefault 0 0 */

void animobjD2_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //801C8ACC
  undefined *puVar1;
  
  Object_setPriority(this,100);
  puVar1 = this->state;
  *(undefined2 *)(puVar1 + 0x62) = *(undefined2 *)&objDef[1].allocatedSize;
  *(undefined2 *)(puVar1 + 0x66) = 0xffff;
  *(float *)(puVar1 + 0x24) =
       1.0 / ((float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].pos.y) -
                     4503599627370496.0) + 1.0);
  *(undefined4 *)(puVar1 + 0x28) = 0xffffffff;
  if ((this->field76_0xf4 == 0) && (objDef[1].objType != 1)) {
                    /* {@symbol 800cf6cc} */
    (**(code **)(*(int *)pDll_checkpoint + 0x1c))(puVar1,objDef);
    this->field76_0xf4 = (short)objDef[1].objType + 1;
  }
  else if ((this->field76_0xf4 != 0) && ((int)(short)objDef[1].objType != this->field76_0xf4 + -1))
  {
                    /* {@symbol 800cf980} */
    (**(code **)(*(int *)pDll_checkpoint + 0x24))(puVar1);
    if (objDef[1].objType != None) {
                    /* {@symbol 800cf6cc} */
      (**(code **)(*(int *)pDll_checkpoint + 0x1c))(puVar1,objDef);
    }
    this->field76_0xf4 = (short)objDef[1].objType + 1;
  }
  if (this->shadow != (Shadow *)0x0) {
    (this->shadow->color).b = 100;
    (this->shadow->color).a = 0x96;
  }
  return;
}


/* Library Function - Single Match
    dll_D2_func04
   
   Library: KioskDefault 0 0 */

void animobjD2_update(ObjInstance *this) { //801C8C24
  char cVar1;
  int iVar2;
  ObjInstance **ppOVar3;
  ObjInstance *pOVar4;
  ObjInstance *pOVar5;
  int local_2c;
  int local_28 [2];
  
  if ((this->def != (ObjDef *)0x0) && (this->def[1].objType != None)) {
                    /* {@symbol 800c8b14} */
    local_28[0] = (**(code **)(*(int *)pDll_checkpoint + 0x14))(this,framesThisStep);
    if ((local_28[0] != 0) && ((iVar2 = isModelAnimDisabled(), iVar2 == 0 && (this->curSeq == -2))))
    {
      cVar1 = this->state[0x4f];
      pOVar4 = (ObjInstance *)0x0;
      ppOVar3 = Object_getObjects(local_28,&local_2c);
      iVar2 = 0;
      for (local_28[0] = 0; local_28[0] < local_2c; local_28[0] = local_28[0] + 1) {
        pOVar5 = ppOVar3[local_28[0]];
        if (pOVar5->curSeq == (short)cVar1) {
          pOVar4 = pOVar5;
        }
        if (((pOVar5->curSeq == -2) && (pOVar5->objId == 0x10)) &&
           ((int)(short)cVar1 == (int)(char)pOVar5->state[0x4f])) {
          iVar2 = iVar2 + 1;
        }
      }
      if (((iVar2 < 2) && (pOVar4 != (ObjInstance *)0x0)) && (pOVar4->curSeq != -1)) {
        pOVar4->curSeq = -1;
                    /* {@symbol 800d0958} */
        (**(code **)(*(int *)pDll_checkpoint + 0x4c))((int)(short)cVar1);
      }
      this->curSeq = -1;
    }
  }
  return;
}


/* @description Override hit detection */

void animobjD2_hitDetect(ObjInstance *this) { //801C8D8C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void animobjD2_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //801C8D90
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


/* Library Function - Single Match
    dll_D2_func07
   
   Library: KioskDefault 0 0 */

void animobjD2_free(ObjInstance *this,int param2) { //801C8DEC
                    /* {@symbol 800cf980} */
  (**(code **)(*(int *)pDll_checkpoint + 0x24))(this->state);
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))(this,0xffff,&PTR_DAT_80310bf8,0x7d,"-1");
  FUN_80068a9c((uint)this,0x7f);
  return;
}


undefined4 animobjD2_func08(ObjInstance *this) { //801C8E78
  return 0xb;
}


/* @description Get extra size for object (size of State struct) */

int animobjD2_getExtraSize(void) { //801C8E80
  return 0x130;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void animobj1C0_initialise(undefined4 param) { //8023E79C
  return;
}


/* @description Called when DLL is unloaded */

void animobj1C0_release(void) { //8023E7A0
  return;
}


/* Library Function - Single Match
    dll_1C0_func03
   
   Library: KioskDefault 0 0 */

void MMSH_Scales_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8023E7A4
  ObjDef *def;
  ObjInstance *pOVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  *(undefined2 *)(puVar2 + 0x62) = *(undefined2 *)&objDef[1].allocatedSize;
  *(undefined2 *)(puVar2 + 0x66) = 0xffff;
  *(float *)(puVar2 + 0x24) =
       1.0 / ((float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].pos.y) -
                     4503599627370496.0) + 1.0);
  *(undefined4 *)(puVar2 + 0x28) = 0xffffffff;
  if ((this->field76_0xf4 == 0) && (objDef[1].objType != 1)) {
                    /* {@symbol 800cf6cc} */
    (**(code **)(*(int *)pDll_checkpoint + 0x1c))(puVar2,objDef);
    this->field76_0xf4 = (short)objDef[1].objType + 1;
  }
  else if ((this->field76_0xf4 != 0) && ((int)(short)objDef[1].objType != this->field76_0xf4 + -1))
  {
                    /* {@symbol 800cf980} */
    (**(code **)(*(int *)pDll_checkpoint + 0x24))(puVar2);
    if (objDef[1].objType != None) {
                    /* {@symbol 800cf6cc} */
      (**(code **)(*(int *)pDll_checkpoint + 0x1c))(puVar2,objDef);
    }
    this->field76_0xf4 = (short)objDef[1].objType + 1;
  }
  def = objAlloc(0x24,scalessword);
  (def->pos).x = (this->pos).pos.x;
  (def->pos).y = (this->pos).pos.y;
  (def->pos).z = (this->pos).pos.z;
  def->loadFlags = isBlockObject;
  def->mapStates2 = 4;
  def->cullDist = 0xff;
  pOVar1 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
  this->child[0] = pOVar1;
  (this->child[0]->pos).scale = (this->child[0]->pos).scale * 2.0;
  return;
}


/* Library Function - Single Match
    dll_1C0_func04
   
   Library: KioskDefault 0 0 */

void animobj1C0_update(ObjInstance *this) { //8023E93C
  char cVar1;
  int iVar2;
  ObjInstance **ppOVar3;
  ObjInstance *pOVar4;
  ObjInstance *pOVar5;
  int local_2c;
  int local_28 [2];
  
  if ((this->def != (ObjDef *)0x0) && (this->def[1].objType != None)) {
                    /* {@symbol 800c8b14} */
    local_28[0] = (**(code **)(*(int *)pDll_checkpoint + 0x14))(this,framesLastStep);
    if ((local_28[0] != 0) && ((iVar2 = isModelAnimDisabled(), iVar2 == 0 && (this->curSeq == -2))))
    {
      cVar1 = this->state[0x4f];
      pOVar4 = (ObjInstance *)0x0;
      ppOVar3 = Object_getObjects(local_28,&local_2c);
      iVar2 = 0;
      for (local_28[0] = 0; local_28[0] < local_2c; local_28[0] = local_28[0] + 1) {
        pOVar5 = ppOVar3[local_28[0]];
        if (pOVar5->curSeq == (short)cVar1) {
          pOVar4 = pOVar5;
        }
        if (((pOVar5->curSeq == -2) && (pOVar5->objId == 0x10)) &&
           ((int)(short)cVar1 == (int)(char)pOVar5->state[0x4f])) {
          iVar2 = iVar2 + 1;
        }
      }
      if (((iVar2 < 2) && (pOVar4 != (ObjInstance *)0x0)) && (pOVar4->curSeq != -1)) {
        pOVar4->curSeq = -1;
                    /* {@symbol 800d0958} */
        (**(code **)(*(int *)pDll_checkpoint + 0x4c))((int)(short)cVar1);
      }
      this->curSeq = -1;
      Object_objFreeObject(this);
    }
  }
  return;
}


/* @description Override hit detection */

void animobj1C0_hitDetect(ObjInstance *this) { //8023EAAC
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void animobj1C0_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8023EAB0
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


/* Library Function - Single Match
    dll_1C0_func07
   
   Library: KioskDefault 0 0 */

void MMSH_Scales_free(ObjInstance *this,int param2) { //8023EB0C
                    /* {@symbol 800cf980} */
  (**(code **)(*(int *)pDll_checkpoint + 0x24))(this->state);
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))(this,0xffff,"animobj.c",0x97,"-1");
  if ((this->child[0] != (ObjInstance *)0x0) && (param2 == 0)) {
    Object_objFreeObject(this->child[0]);
  }
  return;
}


undefined4 animobj1C0_func08(ObjInstance *this) { //8023EBA4
  return 0xb;
}


/* @description Get extra size for object (size of State struct) */

int animobj1C0_getExtraSize(void) { //8023EBAC
  return 0x130;
}

