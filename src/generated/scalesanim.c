
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void scalesanim_initialise(undefined4 param) { //8026616C
  return;
}


/* @description Called when DLL is unloaded */

void scalesanim_release(void) { //80266170
  return;
}


/* Library Function - Single Match
    dll_237_func03
   
   Library: KioskDefault 0 0 */

void scalesanim_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80266174
  undefined *puVar1;
  
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
  DAT_80399fd0 = 0.0;
  DAT_80399fd4 = 0;
  return;
}


/* Library Function - Single Match
    dll_237_func04
   
   Library: KioskDefault 0 0 */

void scalesanim_update(ObjInstance *this) { //802662B0
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
    FUN_80266560((int)this);
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

void scalesanim_hitDetect(ObjInstance *this) { //80266428
  return;
}


/* Library Function - Single Match
    dll_237_func06
   
   Library: KioskDefault 0 0 */

void scalesanim_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8026642C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (!shouldRender) {
    return;
  }
  if (DAT_80399fd4 != '\x01') {
    if ((DAT_80399fd4 == '\x02') || (DAT_80399fd4 == '\x03')) {
      FUN_80266700((short *)this,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),
                   (undefined4 *)CONCAT31(in_register_00000018,param4));
    }
    if (shouldRender) {
      objRenderCurrentModel
                (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    return;
  }
  return;
}


/* Library Function - Single Match
    dll_237_func07
   
   Library: KioskDefault 0 0 */

void scalesanim_free(ObjInstance *this,int param2) { //802664DC
                    /* {@symbol 800cf980} */
  (**(code **)(*(int *)pDll_checkpoint + 0x24))(this->state);
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))(this,0xffff,&PTR_DAT_8031c038,0xfc,"-1");
  return;
}


undefined4 scalesanim_func08(ObjInstance *this) { //80266550
  return 0xb;
}


/* @description Get extra size for object (size of State struct) */

int scalesanim_getExtraSize(void) { //80266558
  return 0x130;
}

