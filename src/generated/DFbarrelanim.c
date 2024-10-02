
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFbarrelanim_initialise(undefined4 param) { //8023862C
  return;
}


/* @description Called when DLL is unloaded */

void DFbarrelanim_release(void) { //80238630
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_193_func03
    dll_D2_func03
   
   Library: KioskDefault 0 0 */

void DFbarrelanim_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80238634
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
    dll_193_func04
   
   Library: KioskDefault 0 0 */

void DFbarrelanim_update(ObjInstance *this) { //8023878C
  char cVar1;
  int iVar2;
  ObjInstance **ppOVar3;
  ObjDef *def;
  ObjInstance *pOVar4;
  undefined *puVar5;
  ObjInstance *pOVar6;
  int local_34;
  int local_30 [2];
  
  if ((this->def != (ObjDef *)0x0) && (this->def[1].objType != None)) {
    puVar5 = this->state;
                    /* {@symbol 800c8b14} */
    local_30[0] = (**(code **)(*(int *)pDll_checkpoint + 0x14))(this,framesThisStep);
    if ((local_30[0] == 0) || ((iVar2 = isModelAnimDisabled(), iVar2 != 0 || (this->curSeq != -2))))
    {
      for (iVar2 = 0; iVar2 < (int)(uint)(byte)puVar5[0x84]; iVar2 = iVar2 + 1) {
        if (puVar5[iVar2 + 0x7a] == '\x01') {
          def = objAlloc(0x24,DIMExplosio);
          (this->pos).pos.y = (this->pos).pos.y + 12.0;
          (def->pos).x = (this->pos).pos.x;
          (def->pos).y = (this->pos).pos.y + 8.0;
          (def->pos).z = (this->pos).pos.z;
          objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x355,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x352,0,0,0xffffffff,0);
          (this->pos).pos.y = (this->pos).pos.y - 12.0;
        }
      }
    }
    else {
      cVar1 = puVar5[0x4f];
      pOVar4 = (ObjInstance *)0x0;
      ppOVar3 = Object_getObjects(local_30,&local_34);
      iVar2 = 0;
      for (local_30[0] = 0; local_30[0] < local_34; local_30[0] = local_30[0] + 1) {
        pOVar6 = ppOVar3[local_30[0]];
        if (pOVar6->curSeq == (short)cVar1) {
          pOVar4 = pOVar6;
        }
        if (((pOVar6->curSeq == -2) && (pOVar6->objId == 0x10)) &&
           ((int)(short)cVar1 == (int)(char)pOVar6->state[0x4f])) {
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

void DFbarrelanim_hitDetect(ObjInstance *this) { //802389E4
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DFbarrelanim_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802389E8
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
    dll_193_func07
   
   Library: KioskDefault 0 0 */

void DFbarrelanim_free(ObjInstance *this,int param2) { //80238A44
                    /* {@symbol 800cf980} */
  (**(code **)(*(int *)pDll_checkpoint + 0x24))(this->state);
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))(this,0xffff,"DFbarrelanim.c",0x9c,"-1");
  return;
}


undefined4 DFbarrelanim_func08(ObjInstance *this) { //80238AB8
  return 0xb;
}


/* @description Get extra size for object (size of State struct) */

int DFbarrelanim_getExtraSize(void) { //80238AC0
  return 0x130;
}

