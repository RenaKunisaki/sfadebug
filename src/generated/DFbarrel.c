
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFbarrel_initialise(undefined4 param) { //80237E0C
  return;
}


/* @description Called when DLL is unloaded */

void DFbarrel_release(void) { //80237E10
  return;
}


/* Library Function - Single Match
    dll_192_func03
   
   Library: KioskDefault 0 0 */

void DFbarrel_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //80237E14
  Object_objAddObjectType(this,0x1b);
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
                    /* {@symbol 8012f580} */
  (**(code **)(*(int *)pDll_projLib + 4))(this,this->state,0x21);
  return;
}


/* Library Function - Single Match
    dll_192_func04
   
   Library: KioskDefault 0 0 */

void DFbarrel_update(ObjInstance *this) { //80237E8C
  char cVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  iVar2 = getBlockIdxAtCoords((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                              (double)(this->pos).pos.z);
  if (iVar2 == -1) {
    return;
  }
  cVar1 = puVar3[0xb];
  if (cVar1 == '\x01') {
    FUN_80088da4((int)this);
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    puVar3[0xb] = 0x14;
    return;
  }
  if (cVar1 == '\0') {
    if (true) {
                    /* {@symbol 8012f5bc} */
      iVar2 = (**(code **)(*(int *)pDll_projLib + 8))(this,puVar3);
      if (iVar2 != 0) {
        return;
      }
      FUN_80238054(this);
      FUN_80238468(this);
      return;
    }
  }
  else if (cVar1 == '\x14') goto LAB_80237f48;
  puVar3[0xb] = puVar3[0xb] + '\x01';
LAB_80237f48:
  Object_objFreeObject(this);
  return;
}


/* @description Override hit detection */

void DFbarrel_hitDetect(ObjInstance *this) { //80237F64
  return;
}


/* Library Function - Single Match
    dll_192_func06
   
   Library: KioskDefault 0 0 */

void DFbarrel_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80237F68
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
                    /* {@symbol 8012f938} */
  if ((this->state[0xb] == '\0') &&
     (iVar1 = (**(code **)(*(int *)pDll_projLib + 0xc))(this,(int)shouldRender), iVar1 != 0)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_192_func07
   
   Library: KioskDefault 0 0 */

void DFbarrel_free(ObjInstance *this,int param2) { //80237FF8
  Object_removePlayerObj(this,0x1b);
                    /* {@symbol 8012f9ac} */
  (**(code **)(*(int *)pDll_projLib + 0x10))(this);
  return;
}


undefined4 DFbarrel_func08(ObjInstance *this) { //80238044
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DFbarrel_getExtraSize(void) { //8023804C
  return 0x24;
}

