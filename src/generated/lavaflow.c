
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void lavaflow_initialise(undefined4 param) { //8029027C
  return;
}


/* @description Called when DLL is unloaded */

void lavaflow_release(void) { //80290280
  return;
}


/* Library Function - Single Match
    dll_267_func03
   
   Library: KioskDefault 0 0 */

void lavaflow_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //80290284
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8029041c;
  *(undefined2 *)(puVar4 + 4) = 0x18;
  *(undefined2 *)(puVar4 + 6) = 0x10;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 == 0) {
    objDef[1].allocatedSize = 1;
    objDef[1].mapStates1 = 0xf4;
  }
  uVar3 = randInt(100,1000);
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  (this->pos).scale =
       1.0 / ((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - 4503601774854144.0));
  *(float *)(puVar4 + 8) = (this->pos).scale;
  uVar3 = randInt(0x32,100);
  *(float *)(puVar4 + 0x10) =
       (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - 4503601774854144.0);
  return;
}


/* @description Update object instance */

void lavaflow_update(ObjInstance *this) { //80290370
  FUN_80290424((int *)this);
  return;
}


/* @description Override hit detection */

void lavaflow_hitDetect(ObjInstance *this) { //80290398
  return;
}


/* @description Override render */

void lavaflow_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8029039C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    FUN_80096afc(0xff,0xe6,0xd7);
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void lavaflow_free(ObjInstance *this,int param2) { //80290408
  return;
}


undefined4 lavaflow_func08(ObjInstance *this) { //8029040C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int lavaflow_getExtraSize(void) { //80290414
  return 0x18;
}

