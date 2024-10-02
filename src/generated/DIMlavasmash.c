
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMlavasmash_initialise(undefined4 param) { //80229428
  return;
}


/* @description Called when DLL is unloaded */

void DIMlavasmash_release(void) { //8022942C
  return;
}


/* Library Function - Single Match
    dll_209_func03
   
   Library: KioskDefault 0 0 */

void DIMlavasmash_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80229430
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  undefined *puVar5;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = DIMLavaSmash_SeqFn;
  puVar5 = this->state;
  uVar1._0_1_ = objDef[1].allocatedSize;
  uVar1._1_1_ = objDef[1].mapStates1;
  puVar5[1] = (char)uVar1;
  uVar2._0_1_ = objDef[1].loadFlags;
  uVar2._1_1_ = objDef[1].mapStates2;
  *puVar5 = (char)uVar2;
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  uVar4 = mainGetBit((int)sVar3);
  puVar5[2] = (char)uVar4;
  if (puVar5[2] == '\x01') {
    nop_80229710();
  }
  this->curModel = *(byte *)((int)&objDef[1].objType + 1);
  this->hitstate->flags = this->hitstate->flags & 0xfffe;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_209_func04
   
   Library: KioskDefault 0 0 */

void DIMlavasmash_update(ObjInstance *this) { //802294DC
  char *pcVar1;
  
  pcVar1 = this->state;
  if (pcVar1[2] == '\x01') {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
  }
  else if (this->field76_0xf4 == 0) {
    if (*pcVar1 != -1) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)*pcVar1,this,0xffffffff);
    }
    this->field76_0xf4 = 1;
  }
  return;
}


/* @description Override hit detection */

void DIMlavasmash_hitDetect(ObjInstance *this) { //80229570
  return;
}


/* Library Function - Single Match
    dll_209_func06
   
   Library: KioskDefault 0 0 */

void DIMlavasmash_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80229574
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  
  puVar2 = this->state;
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if ((!bVar1) && (puVar2[2] != '\x02')) {
    return;
  }
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

void DIMlavasmash_free(ObjInstance *this,int param2) { //802295F4
  return;
}


undefined4 DIMlavasmash_func08(ObjInstance *this) { //802295F8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIMlavasmash_getExtraSize(void) { //80229600
  return 3;
}

