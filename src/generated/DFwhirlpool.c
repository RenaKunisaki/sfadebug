
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFwhirlpool_initialise(undefined4 param) { //8023A624
  return;
}


/* @description Called when DLL is unloaded */

void DFwhirlpool_release(void) { //8023A628
  return;
}


/* Library Function - Single Match
    dll_19A_func03
   
   Library: KioskDefault 0 0 */

void DFwhirlpool_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8023A62C
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  uVar1 = mainGetBit(0x106);
  if (uVar1 == 0) {
    audioTryStartSfx((int *)this,1,0x7d,0x7f,"DFwhirlpool.c",0x37);
  }
  else {
    *puVar2 = 2;
    (this->pos).pos.y = (this->pos).pos.y - 57.0;
  }
  return;
}


/* Library Function - Single Match
    dll_19A_func04
   
   Library: KioskDefault 0 0 */

void DFwhirlpool_update(ObjInstance *this) { //8023A6A8
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = this->state;
  bVar1 = *pbVar3;
  if (bVar1 == 1) {
    (this->pos).rotation.x =
         (this->pos).rotation.x - (*(short *)(pbVar3 + 2) + 0x1e) * (ushort)framesThisStep;
    *(ushort *)(pbVar3 + 2) = *(short *)(pbVar3 + 2) + (ushort)framesThisStep;
    (this->pos).pos.y =
         -((float)((double)CONCAT44(0x43300000,(uint)framesThisStep) - 4503599627370496.0) * 0.2 -
          (this->pos).pos.y);
    if (300 < *(short *)(pbVar3 + 2)) {
      FUN_80068a9c((uint)this,1);
      *pbVar3 = 2;
      *(undefined2 *)(pbVar3 + 2) = 0x140;
    }
  }
  else if (bVar1 == 0) {
    if (true) {
      (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * -0x1e;
      uVar2 = mainGetBit(0x105);
      if (uVar2 != 0) {
        *pbVar3 = 1;
        audioTryStartSfx((int *)this,1,0x7b,0x7f,"DFwhirlpool.c",0x49);
      }
    }
  }
  else if (bVar1 < 3) {
    if (*(short *)(pbVar3 + 2) < 1) {
      *(undefined2 *)(pbVar3 + 2) = 0;
    }
    else {
      *(ushort *)(pbVar3 + 2) = *(short *)(pbVar3 + 2) + (ushort)framesThisStep * -2;
    }
    (this->pos).rotation.x =
         (this->pos).rotation.x - (*(short *)(pbVar3 + 2) + 10) * (ushort)framesThisStep;
  }
  return;
}


/* @description Override hit detection */

void DFwhirlpool_hitDetect(ObjInstance *this) { //8023A828
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DFwhirlpool_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //8023A82C
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


/* @description Free object instance */

void DFwhirlpool_free(ObjInstance *this,int param2) { //8023A888
  return;
}


undefined4 DFwhirlpool_func08(ObjInstance *this) { //8023A88C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DFwhirlpool_getExtraSize(void) { //8023A894
  return 4;
}

