
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void MMP_cratercritter_initialise(undefined4 param) { //801C687C
  FUN_801c8430();
  return;
}


/* @description Called when DLL is unloaded */

void MMP_cratercritter_release(void) { //801C689C
  return;
}


/* Library Function - Single Match
    dll_E0_func03
   
   Library: KioskDefault 0 0 */

void MMP_cratercritter_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801C68A0
  uint uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  float *pfVar4;
  
  puVar3 = this->state;
  uVar2 = 6;
  if (obj2 != (ObjInstance *)0x0) {
    uVar2 = 7;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar3,6,6,0,uVar2);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)0x0;
  pfVar4 = *(float **)(puVar3 + 0x3f0);
  Object_ObjAnimSetMove(0.0,this,4,0);
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar3,0);
  *(undefined2 *)(puVar3 + 0x268) = 0;
  puVar3[0x25b] = 0;
  FUN_80088da4((int)this);
  uVar1 = randInt(0x9f,300);
  *pfVar4 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0);
  uVar1 = randInt(0,499);
  pfVar4[1] = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0);
  pfVar4[2] = 0.0;
  pfVar4[5] = 0.0;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_E0_func04
   
   Library: KioskDefault 0 0 */

void MMP_cratercritter_update(ObjInstance *this) { //801C69FC
  int iVar1;
  ObjDef *pOVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  pOVar2 = this->def;
  if (this->field76_0xf4 == 0) {
                    /* {@symbol 80162ab0} */
    iVar1 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar3,0);
    if (iVar1 == 0) {
      *(undefined2 *)(puVar3 + 0x3b2) = 0;
    }
    else {
      FUN_801c6d9c((int *)this,(int)puVar3,(int)puVar3);
      if (*(short *)(puVar3 + 0x3b2) == 0) {
        FUN_801c73d4((int *)this,(int)puVar3,(int)puVar3);
      }
      else {
        FUN_801c71a0(this,(int)puVar3,(int)puVar3);
      }
    }
  }
  else {
                    /* {@symbol 8012dc1c} */
    if ((*(short *)(puVar3 + 0x268) != 3) &&
       (iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar2->id), iVar1 != 0)) {
                    /* {@symbol 8016386c} */
      (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,pOVar2,puVar3,6,6,0,0x26);
      *(undefined2 *)(puVar3 + 0x3b2) = 0;
      audioTryStartSfx((int *)this,1,0x23,0x7f,"MMP_cratercritter.c",0x133);
      Object_ObjAnimSetMove(0.0,this,4,0x10);
      puVar3[0x33a] = 0;
      this->newOpacity = 0xff;
      *(undefined2 *)(puVar3 + 0x3b2) = 0;
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    }
  }
  return;
}


/* @description Override hit detection */

void MMP_cratercritter_hitDetect(ObjInstance *this) { //801C6B78
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    babySnowWorm_func06
    dll_E0_func06
   
   Library: KioskDefault 0 0 */

void MMP_cratercritter_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801C6B7C
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  double local_18;
  
  puVar3 = this->state;
  iVar1 = FUN_8018d744();
  if ((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) {
    if (((this->pos).flags & 0x100) != 0) {
      local_18 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar3 + 0x3de));
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)(local_18 - 4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0,0xc0,0x20);
    }
  }
  else {
    if (!shouldRender) {
      return;
    }
    if (this->field76_0xf4 != 0) {
      return;
    }
    if (*(short *)(puVar3 + 0x3b2) == 0) {
      return;
    }
  }
  if (*(float *)(puVar3 + 0x3e4) != 0.0) {
    FUN_80096b14(200,0,0,(char)(int)*(float *)(puVar3 + 0x3e4));
  }
  objRenderCurrentModel
            (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
             (int *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  if ((*(ushort *)(puVar3 + 0x3ae) & 0x60) != 0) {
    if ((*(ushort *)(puVar3 + 0x3ae) & 0x20) != 0) {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar3 + 0x3e4);
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar3 + 0x3e4);
    }
                    /* {@symbol 800ea278} */
    (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,puVar3 + 0x3e4);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1F3_func07
    dll_1F4_func07
    dll_E0_func07
   
   Library: KioskDefault 0 0 */

void MMP_cratercritter_free(ObjInstance *this,int param2) { //801C6D10
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,0x20);
  return;
}


undefined4 MMP_cratercritter_func08(ObjInstance *this) { //801C6D68
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int MMP_cratercritter_getExtraSize(void) { //801C6D70
  return 0x410;
}


void MMP_cratercritter_setScale(ObjInstance *this,float scale) { //801C6D78
  return;
}


void MMP_cratercritter_func0B(void) { //801C6D98
  return;
}

