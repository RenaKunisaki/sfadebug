
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SClightfoot_initialise(undefined4 param) { //80256814
  FUN_80257ea4();
  return;
}


/* @description Called when DLL is unloaded */

void SClightfoot_release(void) { //80256834
  return;
}


/* Library Function - Single Match
    dll_1F2_func03
   
   Library: KioskDefault 0 0 */

void SClightfoot_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80256838
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  uVar3 = 0x16;
  if (obj2 != (ObjInstance *)0x0) {
    uVar3 = 0x17;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar5,6,3,0x108,uVar3)
  ;
  this->fptr_0xbc = FUN_80256c24;
  if (this->romdefno == 0x360) {
    *(undefined2 *)(puVar5 + 0x26c) = 4;
    *(undefined2 *)(puVar5 + 0x268) = 2;
    FUN_80088da4((int)this);
  }
  else {
    *(undefined2 *)(puVar5 + 0x26c) = 0;
    uVar1 = mainGetBit(0x61c);
    if (uVar1 == 0) {
      *(undefined2 *)(puVar5 + 0x268) = 0;
    }
    else {
      *(undefined2 *)(puVar5 + 0x268) = 1;
    }
  }
  iVar4 = *(int *)(puVar5 + 0x3f0);
  iVar2 = randInt(0,1);
  *(char *)(iVar4 + 9) = (char)iVar2;
  iVar2 = randInt(0,2);
  *(char *)(iVar4 + 0x14) = (char)iVar2;
  this->flags_0xf8 = 0;
  if (this->shadow != (Shadow *)0x0) {
    (this->shadow->color).b = 100;
    (this->shadow->color).a = 0x96;
  }
  *(float *)(iVar4 + 0x10) = 1.0;
  return;
}


/* Library Function - Single Match
    dll_1F2_func04
   
   Library: KioskDefault 0 0 */

void SClightfoot_update(ObjInstance *this) { //80256970
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  if (this->field76_0xf4 == 0) {
    if (this->flags_0xf8 != 0) {
      FUN_80256f80((int)this);
      this->flags_0xf8 = 0;
    }
                    /* {@symbol 80162ab0} */
    iVar1 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar2,1);
    if (iVar1 != 0) {
      FUN_80256c68((int *)this,(int)puVar2,(int)puVar2);
    }
  }
  return;
}


/* @description Override hit detection */

void SClightfoot_hitDetect(ObjInstance *this) { //80256A00
  return;
}


/* Library Function - Single Match
    dll_1F2_func06
   
   Library: KioskDefault 0 0 */

void SClightfoot_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80256A04
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  
  puVar3 = this->state;
  if ((shouldRender) && (this->field76_0xf4 == 0)) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar3 + 0x3de)) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0,0xc0,0x20);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((puVar3[0x3ac] & 1) != 0) {
      objGetAttachPointWorldPos(this,0,&FLOAT_80396368,&FLOAT_8039636c,&FLOAT_80396370,FALSE);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x425,&DAT_8039635c,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x425,&DAT_8039635c,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x426,&DAT_8039635c,&DAT_00200001,0xffffffff,0);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1F2_func07
   
   Library: KioskDefault 0 0 */

void SClightfoot_free(ObjInstance *this,int param2) { //80256BA4
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,0x20);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 SClightfoot_func08(ObjInstance *this) { //80256C14
  return 0x4b;
}


/* @description Get extra size for object (size of State struct) */

int SClightfoot_getExtraSize(void) { //80256C1C
  return 0x410;
}

