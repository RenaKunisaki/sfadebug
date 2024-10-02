
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMExplosion_initialise(undefined4 param) { //80229CA4
  return;
}


/* @description Called when DLL is unloaded */

void DIMExplosion_release(void) { //80229CA8
  return;
}


/* Library Function - Single Match
    DIMExplosion_func03
   
   Library: KioskDefault 0 0 */

void DIMExplosion_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80229CAC
  short sVar1;
  short sVar2;
  undefined *puVar3;
  double local_18;
  
  puVar3 = this->state;
  *(float *)(puVar3 + 8) = 0.01;
  (this->pos).scale = *(float *)(puVar3 + 8);
  audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,(double)(this->prevPos).z,
                      0x213,0x7f,"DIMexplosion.c",(int *)0x42);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 == 0) {
    *(float *)(puVar3 + 0xc) = 16.0;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    local_18 = (double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000);
    *(float *)(puVar3 + 0xc) = (float)(local_18 - 4503601774854144.0) * 0.00390625;
  }
  this->newOpacity = (u8)(int)((16.0 / *(float *)(puVar3 + 0xc)) * 180.0);
  return;
}


/* Library Function - Single Match
    DIMExplosion_func04
   
   Library: KioskDefault 0 0 */

void DIMExplosion_update(ObjInstance *this) { //80229D88
  int iVar1;
  undefined *puVar2;
  double local_18;
  
  iVar1 = FUN_80094400((int)this,0);
  puVar2 = this->state;
  if (iVar1 != 0) {
    *(short *)(iVar1 + 8) = *(short *)(iVar1 + 8) + 1;
    if (0x1f < *(short *)(iVar1 + 8)) {
      *(undefined2 *)(iVar1 + 8) = 0;
    }
    *(short *)(iVar1 + 10) = *(short *)(iVar1 + 10) + -0x80;
    if (*(short *)(iVar1 + 10) < -0x3e0) {
      *(undefined2 *)(iVar1 + 10) = 0;
    }
  }
  local_18 = (double)CONCAT44(0x43300000,(uint)framesThisStep);
  (this->pos).scale = (float)(local_18 - 4503599627370496.0) * 0.4 + (this->pos).scale;
  if (*(float *)(puVar2 + 0xc) < (this->pos).scale) {
    Object_objFreeObject(this);
  }
  (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * 400;
  iVar1 = randInt(0,(int)-(*(float *)(puVar2 + 0xc) * 3.0 - 51.0));
  if (iVar1 == 0) {
    dimExplosionFn_80229f1c((double)*(float *)(puVar2 + 0xc),(int)this);
  }
  return;
}


/* @description Override hit detection */

void DIMExplosion_hitDetect(ObjInstance *this) { //80229EA8
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIMExplosion_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80229EAC
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

void DIMExplosion_free(ObjInstance *this,int param2) { //80229F08
  return;
}


undefined4 DIMExplosion_func08(ObjInstance *this) { //80229F0C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIMExplosion_getExtraSize(void) { //80229F14
  return 0x10;
}

