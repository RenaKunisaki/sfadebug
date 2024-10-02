
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void ladders_initialise(undefined4 param) { //801EBC9C
  return;
}


/* @description Called when DLL is unloaded */

void ladders_release(void) { //801EBCA0
  return;
}


/* Library Function - Single Match
    dll_114_func03
   
   Library: KioskDefault 0 0 */

void ladders_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //801EBCA4
  short sVar1;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *(undefined2 *)((int)pfVar2 + 6) = *(undefined2 *)&objDef[1].pos.x;
  *(undefined2 *)(pfVar2 + 1) = *(undefined2 *)&objDef[1].bound;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801ebfdc;
  (this->pos).pos.y = (objDef->pos).y + *pfVar2;
  objSetModelNo(this,(int)*(char *)((int)&objDef[1].objType + 1));
  *(undefined2 *)(pfVar2 + 2) = 0;
  return;
}


/* Library Function - Single Match
    dll_114_func04
   
   Library: KioskDefault 0 0 */

void ladders_update(ObjInstance *this) { //801EBD5C
  float fVar1;
  uint uVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  pOVar3 = this->def;
  puVar4 = this->state;
  if (this->romdefno == VFP_Ladders) {
    FUN_801ebf30((int)this);
  }
  else if (*(short *)(puVar4 + 10) == 0) {
    if ((*(short *)(puVar4 + 8) == 0) &&
       (uVar2 = mainGetBit((int)*(short *)(puVar4 + 6)), uVar2 != 0)) {
      *(undefined2 *)(puVar4 + 10) = 10;
    }
    if (*(short *)(puVar4 + 8) == 1) {
      if ((pOVar3->pos).y <= (this->pos).pos.y) {
        (this->vel).y = (this->vel).y - 0.9;
        (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
        if ((this->pos).pos.y <= (pOVar3->pos).y) {
          (this->pos).pos.y = (pOVar3->pos).y;
          (this->vel).y = -(this->vel).y * 0.3;
          if ((this->vel).y < 0.0) {
            fVar1 = -(this->vel).y;
          }
          else {
            fVar1 = (this->vel).y;
          }
          if (fVar1 < 0.01) {
            *(undefined2 *)(puVar4 + 8) = 2;
          }
        }
      }
    }
  }
  else {
    *(short *)(puVar4 + 10) = *(short *)(puVar4 + 10) - (short)(int)timeDelta;
    if (*(short *)(puVar4 + 10) < 1) {
      *(undefined2 *)(puVar4 + 8) = 1;
      audioTryStartSfx((int *)this,1,0xf0,0x7f,"ladders.c",0x6a);
      *(undefined2 *)(puVar4 + 10) = 0;
    }
  }
  return;
}


/* @description Override hit detection */

void ladders_hitDetect(ObjInstance *this) { //801EBEE0
  return;
}


/* @description Override render */

void ladders_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //801EBEE4
  return;
}


/* @description Free object instance */

void ladders_free(ObjInstance *this,int param2) { //801EBEE8
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 ladders_func08(ObjInstance *this) { //801EBF20
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int ladders_getExtraSize(void) { //801EBF28
  return 0xc;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void ladders25D_initialise(undefined4 param) { //8028C954
  return;
}


/* @description Called when DLL is unloaded */

void ladders25D_release(void) { //8028C958
  return;
}


/* Library Function - Single Match
    dll_25D_func03
   
   Library: KioskDefault 0 0 */

void ladders25D_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8028C95C
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  puVar1[1] = *(undefined2 *)&objDef[1].pos.x;
  *puVar1 = *(undefined2 *)&objDef[1].bound;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8028cc20;
  return;
}


/* Library Function - Single Match
    dll_25D_func04
   
   Library: KioskDefault 0 0 */

void ladders25D_update(ObjInstance *this) { //8028C9B0
  uint uVar1;
  ObjDef *pOVar2;
  undefined *puVar3;
  
  pOVar2 = this->def;
  puVar3 = this->state;
  if (this->romdefno == VFP_Ladders) {
    FUN_8028cb40((int)this);
  }
  else if (*(short *)(puVar3 + 6) == 0) {
    if ((*(short *)(puVar3 + 4) == 0) &&
       (uVar1 = mainGetBit((int)*(short *)(puVar3 + 2)), uVar1 != 0)) {
      *(undefined2 *)(puVar3 + 6) = 0x5a;
    }
    if (((*(short *)(puVar3 + 4) == 1) && ((pOVar2->pos).y - 150.0 < (this->pos).pos.y)) &&
       ((this->pos).pos.y = -(timeDelta * 2.0 - (this->pos).pos.y),
       (this->pos).pos.y < (pOVar2->pos).y - 150.0)) {
      (this->pos).pos.y = (pOVar2->pos).y - 150.0;
      *(undefined2 *)(puVar3 + 4) = 2;
    }
  }
  else {
    *(short *)(puVar3 + 6) = *(short *)(puVar3 + 6) - (short)(int)timeDelta;
    if (*(short *)(puVar3 + 6) < 1) {
      *(undefined2 *)(puVar3 + 4) = 1;
      audioTryStartSfx((int *)this,1,0xf0,0x7f,"ladders.c",0x53);
      *(undefined2 *)(puVar3 + 6) = 0;
    }
  }
  return;
}


/* @description Override hit detection */

void ladders25D_hitDetect(ObjInstance *this) { //8028CAF0
  return;
}


/* @description Override render */

void ladders25D_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8028CAF4
  return;
}


/* @description Free object instance */

void ladders25D_free(ObjInstance *this,int param2) { //8028CAF8
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 ladders25D_func08(ObjInstance *this) { //8028CB30
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int ladders25D_getExtraSize(void) { //8028CB38
  return 8;
}

