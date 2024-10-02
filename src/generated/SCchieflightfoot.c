
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCchieflightfoot_initialise(undefined4 param) { //8025875C
  FUN_80259720();
  return;
}


/* @description Called when DLL is unloaded */

void SCchieflightfoot_release(void) { //8025877C
  return;
}


/* Library Function - Single Match
    dll_1F4_func03
   
   Library: KioskDefault 0 0 */

void SCchieflightfoot_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //80258780
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  uVar3 = 0x16;
  if (obj2 != (ObjInstance *)0x0) {
    uVar3 = 0x17;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar4,3,2,0x108,uVar3)
  ;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80258af0;
  *(undefined2 *)(puVar4 + 0x26c) = 0;
  uVar1 = mainGetBit(0x61c);
                    /* {@symbol 8012dfa8} */
  if ((uVar1 == 0) && (cVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x40))(0xe), cVar2 != '\x06')) {
    *(undefined2 *)(puVar4 + 0x268) = 0;
  }
  else {
    *(undefined2 *)(puVar4 + 0x268) = 1;
  }
  if (this->shadow != (Shadow *)0x0) {
    (this->shadow->color).b = 100;
    (this->shadow->color).a = 0x96;
  }
  if (this->field76_0xf4 != 0) {
    FUN_80088da4((int)this);
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_1F4_func04
   
   Library: KioskDefault 0 0 */

void SCchieflightfoot_update(ObjInstance *this) { //802588AC
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  if (this->field76_0xf4 == 0) {
    if ((*(ushort *)(puVar2 + 0x3ae) & 2) != 0) {
      if ((puVar2[0x3ac] & 1) != 0) {
        puVar2[0x3ac] = puVar2[0x3ac] & 0xfe;
        mainSetBits(0x2b3,1);
      }
      if ((puVar2[0x3ac] & 2) != 0) {
        puVar2[0x3ac] = puVar2[0x3ac] & 0xfd;
        FUN_80258e94(this,5);
      }
      if ((puVar2[0x3ac] & 4) != 0) {
        puVar2[0x3ac] = puVar2[0x3ac] & 0xfb;
        mainSetBits(0x781,1);
      }
      *(ushort *)(puVar2 + 0x3ae) = *(ushort *)(puVar2 + 0x3ae) & 0xfffd;
    }
                    /* {@symbol 80162ab0} */
    iVar1 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar2,1);
    if (iVar1 != 0) {
      FUN_80258c30((int *)this,(int)puVar2,(int)puVar2);
    }
  }
  return;
}


/* @description Override hit detection */

void SCchieflightfoot_hitDetect(ObjInstance *this) { //802589A4
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1F3_func06
    dll_1F4_func06
   
   Library: KioskDefault 0 0 */

void SCchieflightfoot_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802589A8
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
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1F3_func07
    dll_1F4_func07
    dll_E0_func07
   
   Library: KioskDefault 0 0 */

void SCchieflightfoot_free(ObjInstance *this,int param2) { //80258A88
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,0x20);
  return;
}


undefined4 SCchieflightfoot_func08(ObjInstance *this) { //80258AE0
  return 0x4b;
}


/* @description Get extra size for object (size of State struct) */

int SCchieflightfoot_getExtraSize(void) { //80258AE8
  return 0x402;
}

