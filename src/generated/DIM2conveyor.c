
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIM2conveyor_initialise(undefined4 param) { //8022B408
  return;
}


/* @description Called when DLL is unloaded */

void DIM2conveyor_release(void) { //8022B40C
  return;
}


/* Library Function - Single Match
    dll_215_func03
   
   Library: KioskDefault 0 0 */

void DIM2conveyor_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8022B410
  short sVar1;
  float *pfVar2;
  double dVar3;
  double dVar4;
  
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  dVar4 = (double)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0
                          ) / 5.0);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  pfVar2 = (float *)this->state;
  dVar3 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  *pfVar2 = (float)(dVar4 * dVar3);
  dVar3 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)(this->pos).rotation.x ^
                                                                     0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  pfVar2[1] = (float)(dVar4 * dVar3);
  Object_objAddObjectType(this,0x18);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_215_func04
   
   Library: KioskDefault 0 0 */

void DIM2conveyor_update(ObjInstance *this) { //8022B514
  audioTryStartSfx((int *)this,0xc0,0x69,0x7f,"DIM2conveyor.c",0x48);
  return;
}


/* @description Override hit detection */

void DIM2conveyor_hitDetect(ObjInstance *this) { //8022B558
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIM2conveyor_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8022B55C
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

void DIM2conveyor_free(ObjInstance *this,int param2) { //8022B5B8
  return;
}


undefined4 DIM2conveyor_func08(ObjInstance *this) { //8022B5BC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIM2conveyor_getExtraSize(void) { //8022B5C4
  return 8;
}


/* Library Function - Single Match
    dll_215_func0A
   
   Library: KioskDefault 0 0 */

void DIM2conveyor_setScale(ObjInstance *this,float scale) { //8022B5CC
  ObjInstance *in_r4;
  undefined4 in_register_00004008;
  
  objMove((double)(float)((double)*(float *)this->state *
                         (double)CONCAT44(in_register_00004008,scale)),0.0,
          (double)(float)((double)*(float *)((int)this->state + 4) *
                         (double)CONCAT44(in_register_00004008,scale)),in_r4);
  return;
}

