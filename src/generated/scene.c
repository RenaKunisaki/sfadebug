
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void scene1C7_initialise(undefined4 param) { //80242050
  return;
}


/* @description Called when DLL is unloaded */

void scene1C7_release(void) { //80242054
  return;
}


/* Library Function - Single Match
    dll_1C7_func03
   
   Library: KioskDefault 0 0 */

void dll_GPSH_Scene_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //80242058
  short sVar1;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  *(undefined2 *)(pfVar2 + 1) = *(undefined2 *)&objDef[1].bound;
  *(undefined *)((int)pfVar2 + 6) = *(undefined *)((int)&objDef[1].objType + 1);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)sVar1 / 100 ^ 0x80000000) - 4503601774854144.0)
  ;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  (this->prevPos).x = (this->pos).pos.x;
  (this->prevPos).y = (this->pos).pos.y;
  (this->prevPos).z = (this->pos).pos.z;
  return;
}


/* Library Function - Single Match
    dll_1C7_func04
   
   Library: KioskDefault 0 0 */

void scene1C7_update(ObjInstance *this) { //802420D8
  ObjInstance *pOVar1;
  ObjInstance *obj;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  float local_1c;
  
  pfVar4 = (float *)this->state;
  local_1c = 10000.0;
  (this->prevPos).x = (this->pos).pos.x;
  (this->prevPos).y = (this->pos).pos.y;
  (this->prevPos).z = (this->pos).pos.z;
  pOVar1 = Object_objGetMain();
  obj = getSeqObj(0x12,this,&local_1c);
  if ((((pOVar1 != (ObjInstance *)0x0) && (obj != (ObjInstance *)0x0)) &&
      ((int)(short)obj->romdefno == *(byte *)((int)pfVar4 + 6) + 500)) &&
     (((local_1c < *pfVar4 && (obj->state[5] == '\0')) &&
      (uVar2 = mainGetBit(*(byte *)((int)pfVar4 + 6) + 0x149), uVar2 == 0)))) {
    audioTryStartSfx((int *)this,1,0x37,0x7f,"scene.c",0x8a);
    mainSetBits(*(byte *)((int)pfVar4 + 6) + 0x149,1);
    Object_objFreeObject(obj);
    for (iVar3 = 0; iVar3 < 200; iVar3 = iVar3 + 1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x289,0,0,0xffffffff,0);
    }
  }
  return;
}


/* @description Override hit detection */

void scene1C7_hitDetect(ObjInstance *this) { //80242218
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1C7_func06
    dll_1D0_func06
    gfxEmit_func06
   
   Library: KioskDefault 0 0 */

void scene1C7_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8024221C
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  if (shouldRender) {
    bVar1 = checkSomeDebugFlags_8017c4f8();
    if (bVar1) {
      objRenderCurrentModel
                (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)*pfVar2,25.0,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
    }
  }
  return;
}


/* @description Free object instance */

void scene1C7_free(ObjInstance *this,int param2) { //802422C8
  return;
}


undefined4 scene1C7_func08(ObjInstance *this) { //802422CC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int scene1C7_getExtraSize(void) { //802422D4
  return 8;
}

