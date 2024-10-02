
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMbosstonsil_initialise(undefined4 param) { //80232538
  FUN_80233630();
  return;
}


/* @description Called when DLL is unloaded */

void DIMbosstonsil_release(void) { //80232558
  return;
}


/* Library Function - Single Match
    dll_222_func03
   
   Library: KioskDefault 0 0 */

void DIMbosstonsil_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8023255C
  uint uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  uVar2 = 6;
  if (obj2 != (ObjInstance *)0x0) {
    uVar2 = 7;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar3,2,2,0x102,uVar2)
  ;
  this->fptr_0xbc = objSeqFn_801be44c;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar3,0);
  *(undefined2 *)(puVar3 + 0x268) = 0;
  uVar1 = mainGetBit(0x20c);
  DAT_80399ec0 = (char)uVar1;
  if (DAT_80399ec0 < '\x03') {
    puVar3[0x348] = '\x03' - DAT_80399ec0;
  }
  else {
    puVar3[0x348] = '\a' - DAT_80399ec0;
  }
  this->shadow->flags = this->shadow->flags | 0x10000;
  this->shadow->flags = this->shadow->flags & 0xfffffff7;
  DAT_80399eb0 = 0.0;
  DAT_80399eb4 = 0.0;
  DAT_80399ebc = 0.0;
  DAT_80399eb8 = 30.0;
  return;
}


/* Library Function - Single Match
    dll_222_func04
   
   Library: KioskDefault 0 0 */

void DIMbosstonsil_update(ObjInstance *this) { //8023268C
  int iVar1;
  ObjInstance *pOVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  pOVar3 = this->def;
  if (this->field76_0xf4 == 0) {
    if (this->flags_0xf8 == 0) {
      (this->pos).pos.x = (pOVar3->pos).x;
      (this->pos).pos.y = (pOVar3->pos).y;
      (this->pos).pos.z = (pOVar3->pos).z;
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))
                ((int)*(char *)((int)&pOVar3[1].id + 2),this,0xffffffff);
      this->flags_0xf8 = 1;
    }
    else {
      if ((*(ushort *)(puVar4 + 0x3ae) & 2) != 0) {
        DAT_80399eb0 = 780.0;
                    /* {@symbol 80162f2c} */
        (**(code **)(*(int *)pDll_partfx1F + 0x28))
                  (this,puVar4,puVar4 + 0x34c,(int)*(short *)(puVar4 + 0x39e),puVar4 + 0x3b0,0,0,0,1
                  );
        *(ushort *)(puVar4 + 0x3ae) = *(ushort *)(puVar4 + 0x3ae) & 0xfffd;
      }
                    /* {@symbol 80162ab0} */
      iVar1 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar4,1);
      if (iVar1 != 0) {
        pOVar2 = Object_objGetMain();
        *(ObjInstance **)(puVar4 + 0x2c8) = pOVar2;
        FUN_80232d60((int *)this,0,(int)puVar4,(int)puVar4);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_222_func05
   
   Library: KioskDefault 0 0 */

void DIMbosstonsil_hitDetect(ObjInstance *this) { //802327C0
                    /* {@symbol 8011c220} */
  (**(code **)(*(int *)pDll11 + 0xc))(this,this->state,&DAT_80399ea0);
  return;
}


/* Library Function - Single Match
    dll_222_func06
   
   Library: KioskDefault 0 0 */

void DIMbosstonsil_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80232808
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined auStack_38 [12];
  float local_2c;
  float local_28;
  float local_24;
  undefined *local_20;
  undefined4 local_18;
  uint uStack_14;
  
  local_20 = this->state;
  if ((shouldRender) && (this->field76_0xf4 == 0)) {
    this->shadow->opacityChange = 0x20;
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      uStack_14 = (uint)*(ushort *)(this->state + 0x3de);
      local_18 = 0x43300000;
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,uStack_14) - 4503599627370496.0),32.0
                   ,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xc0,0xc0,0x20);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    objGetAttachPointWorldPos(this,1,&local_2c,&local_28,&local_24,FALSE);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x4bd,auStack_38,&DAT_00200001,0xffffffff,0);
    objGetAttachPointWorldPos(this,0,&local_2c,&local_28,&local_24,FALSE);
    FUN_800b26dc((double)local_2c,(double)local_28,(double)local_24,(int)this);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x4bd,auStack_38,&DAT_00200001,0xffffffff,0);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_197_func07
    dll_222_func07
    dll_D6_func07
   
   Library: KioskDefault 0 0 */

void DIMbosstonsil_free(ObjInstance *this,int param2) { //802329A8
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


undefined4 DIMbosstonsil_func08(ObjInstance *this) { //80232A1C
  return 0x4b;
}


/* @description Get extra size for object (size of State struct) */

int DIMbosstonsil_getExtraSize(void) { //80232A24
  return 0x3f8;
}


void DIMbosstonsil_setScale(ObjInstance *this,float scale) { //80232A2C
  return;
}


void DIMbosstonsil_func0B(void) { //80232A4C
  return;
}

