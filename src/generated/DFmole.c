
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFmole_initialise(undefined4 param) { //80239100
  FUN_8023a554();
  return;
}


/* @description Called when DLL is unloaded */

void DFmole_release(void) { //80239120
  return;
}


/* Library Function - Single Match
    dll_197_func03
   
   Library: KioskDefault 0 0 */

void DFmole_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //80239124
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = this->state;
  uVar2 = 0x16;
  if (obj2 != (ObjInstance *)0x0) {
    uVar2 = 0x17;
  }
  if ((*(byte *)((int)&objDef[1].pos.z + 3) & 1) == 0) {
    uVar2 = uVar2 | 8;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar1,9,6,0x102,uVar2)
  ;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8023943c;
  *(undefined2 *)(puVar1 + 0x26c) = 1;
  *(undefined2 *)(puVar1 + 0x268) = 0;
  puVar1[0x33a] = 0;
  return;
}


/* Library Function - Single Match
    dll_197_func04
   
   Library: KioskDefault 0 0 */

void DFmole_update(ObjInstance *this) { //802391D8
  undefined *puVar1;
  
  puVar1 = this->state;
                    /* {@symbol 8011bdb4} */
  (**(code **)(*(int *)pDll11 + 8))
            (0x3ff0000000000000,0x3ff0000000000000,this,puVar1,DFmoleFuncPtrs,0x80396304);
  FUN_80239444(this,(int)puVar1,(int)puVar1);
  if ((*(int *)(puVar1 + 0x2c8) == 0) && (puVar1[0x348] != '\0')) {
    FUN_80239678((int)this,(int)puVar1,(int)puVar1);
  }
  else {
    FUN_802395d4((int)this,0,(int)puVar1,(int)puVar1);
  }
  return;
}


/* Library Function - Single Match
    dll_197_func05
   
   Library: KioskDefault 0 0 */

void DFmole_hitDetect(ObjInstance *this) { //8023928C
                    /* {@symbol 8011c220} */
  (**(code **)(*(int *)pDll11 + 0xc))(this,this->state,DFmoleFuncPtrs);
  return;
}


/* Library Function - Single Match
    dll_197_func06
   
   Library: KioskDefault 0 0 */

void DFmole_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //802392D8
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->field76_0xf4 == 0)) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (uint)*(ushort *)(this->state + 0x3de)) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xc0,0xc0,0x20);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_197_func07
    dll_222_func07
    dll_D6_func07
   
   Library: KioskDefault 0 0 */

void DFmole_free(ObjInstance *this,int param2) { //802393B8
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objFreeObject(this->child[0]);
    this->child[0] = (ObjInstance *)0x0;
  }
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,1);
  return;
}


undefined4 DFmole_func08(ObjInstance *this) { //8023942C
  return 0x14b;
}


/* @description Get extra size for object (size of State struct) */

int DFmole_getExtraSize(void) { //80239434
  return 0x408;
}

