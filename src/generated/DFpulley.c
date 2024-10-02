
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFpulley_initialise(undefined4 param) { //80237A68
  return;
}


/* @description Called when DLL is unloaded */

void DFpulley_release(void) { //80237A6C
  return;
}


/* Library Function - Single Match
    dll_191_func03
   
   Library: KioskDefault 0 0 */

void DFpulley_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //80237A70
  uint uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)this->state;
  if (this->romdefno == 0x96) {
    Object_objAddObjectType(this,0x1a);
  }
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  (this->pos).scale = (this->pos).scale * *(float *)&objDef[1].loadFlags;
  this->flags_0xb0 = (ushort)objDef[1].mapStates1;
  uVar1 = mainGetBit(0x19);
  *(char *)(puVar3 + 1) = (char)uVar1;
  if (*(char *)(puVar3 + 1) == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x15e;
  }
  *puVar3 = uVar2;
  return;
}


/* Library Function - Single Match
    dll_191_func04
   
   Library: KioskDefault 0 0 */

void DFpulley_update(ObjInstance *this) { //80237B28
  byte bVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  ObjInstance *param2;
  undefined *puVar5;
  ushort *puVar6;
  double in_f1;
  double local_38;
  
  _savefpr_29();
  puVar6 = (ushort *)this->state;
  bVar1 = *(byte *)(puVar6 + 1);
  if (bVar1 == 1) {
    if (this->romdefno == 0xad) {
      *(undefined *)(puVar6 + 1) = 2;
      audioTryStartSfx((int *)this,1,0x85,0x7f,"DFpulley.c",0x58);
    }
    else if ((this->flags_0xb0 & 2) == 0) {
      param2 = Object_findByUniqueId(0x2ca7);
      puVar5 = param2->state;
      objDistObj2Obj(this,param2);
      if (120.0 <= in_f1) {
        FUN_80068a9c((uint)this,8);
      }
      else {
        audioTryStartSfx((int *)this,0x88,0x1e4,0x7f,"DFpulley.c",0x61);
        if (*(float *)(puVar5 + 0x9c) * 0.5 * 0.5 + 0.5 <= 1.0) {
          fVar2 = *(float *)(puVar5 + 0x9c) * 0.5 * 0.5 + 0.5;
        }
        else {
          fVar2 = 1.0;
        }
        if (puVar5[0xb6] == '\0') {
          fVar3 = ((float)(120.0 - in_f1) / 120.0) * (float)((double)fVar2 * 127.0);
        }
        else {
          fVar3 = 0.0;
        }
        FUN_800689dc((double)fVar2,(int)this,8,(byte)(int)fVar3);
      }
    }
  }
  else if (bVar1 == 0) {
    if (true) {
      uVar4 = mainGetBit(0x19);
      *(char *)(puVar6 + 1) = (char)uVar4;
    }
  }
  else if (bVar1 < 3) {
    if (*puVar6 < 0x15e) {
      *puVar6 = *puVar6 + 0x1e;
    }
    local_38 = (double)CONCAT44(0x43300000,(uint)*puVar6);
    (this->pos).rotation.y =
         (short)(int)-((float)(local_38 - 4503599627370496.0) * timeDelta -
                      (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000)
                             - 4503601774854144.0));
  }
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void DFpulley_hitDetect(ObjInstance *this) { //80237D54
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DFpulley_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80237D58
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


/* Library Function - Single Match
    dll_191_func07
   
   Library: KioskDefault 0 0 */

void DFpulley_free(ObjInstance *this,int param2) { //80237DB4
  if (this->romdefno == 0x96) {
    Object_removePlayerObj(this,0x1a);
  }
  return;
}


undefined4 DFpulley_func08(ObjInstance *this) { //80237DFC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DFpulley_getExtraSize(void) { //80237E04
  return 4;
}

