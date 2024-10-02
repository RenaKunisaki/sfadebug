
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void door_initialise(undefined4 param) { //801DABDC
  return;
}


/* @description Called when DLL is unloaded */

void door_release(void) { //801DABE0
  return;
}


/* Library Function - Single Match
    dll_119_func03
   
   Library: KioskDefault 0 0 */

void door_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801DABE4
  short sVar1;
  short sVar2;
  char cVar4;
  uint uVar3;
  float *pfVar5;
  undefined4 in_register_00004008;
  double dVar6;
  undefined4 in_register_00004010;
  undefined4 in_register_00004018;
  
  pfVar5 = (float *)this->state;
                    /* {@symbol 8012dfa8} */
  cVar4 = (**(code **)(*(int *)pDll_SaveGame + 0x40))
                    (CONCAT44(in_register_00004008,x),CONCAT44(in_register_00004010,y),
                     CONCAT44(in_register_00004018,z),(int)(char)this->mapId);
  if (cVar4 == '\x02') {
    mainSetBits(0x816,1);
    mainSetBits(0x817,1);
    mainSetBits(0x7f7,1);
    mainSetBits(0x802,1);
    mainSetBits(0x7f8,1);
    mainSetBits(0x25b,1);
    mainSetBits(0x25a,1);
    mainSetBits(0x819,1);
  }
  *(undefined *)((int)pfVar5 + 0xd) = 1;
  (this->pos).rotation.x = (ushort)objDef[1].cullDist << 8;
  this->fptr_0xbc = FUN_801daf64;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  if (*(char *)((int)&objDef[1].pos.x + 1) == '\0') {
    *(undefined *)((int)&objDef[1].pos.x + 1) = 0x40;
  }
  if (*(char *)&objDef[1].pos.x == '\0') {
    *(undefined *)&objDef[1].pos.x = 1;
  }
  (this->pos).scale =
       (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].pos.x + 1)) -
              4503599627370496.0) * 0.015625;
  if ((this->pos).scale == 0.0) {
    (this->pos).scale = 1.0;
  }
  (this->pos).scale = (this->pos).scale * this->data->scale;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 == -1) {
    *(undefined *)(pfVar5 + 3) = 0;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uVar3 = mainGetBit((int)sVar2);
    *(char *)(pfVar5 + 3) = (char)uVar3;
  }
  dVar6 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  *pfVar5 = (float)dVar6;
  dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)(this->pos).rotation.x ^
                                                                     0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  pfVar5[1] = (float)dVar6;
  pfVar5[2] = -(*pfVar5 * (this->pos).pos.x + pfVar5[1] * (this->pos).pos.z);
  *(undefined *)((int)pfVar5 + 0xe) = 0;
  uVar3 = mainGetBit((int)(short)objDef[1].objType);
  if (uVar3 != 0) {
    *(byte *)((int)pfVar5 + 0xe) = *(byte *)((int)pfVar5 + 0xe) | 1;
  }
  uVar3 = mainGetBit((int)*(short *)((int)&objDef[1].pos.x + 2));
  if (uVar3 != 0) {
    *(byte *)((int)pfVar5 + 0xe) = *(byte *)((int)pfVar5 + 0xe) | 2;
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_119_func04
    dll_2C5_func04
   
   Library: KioskDefault 0 0 */

void door_update(ObjInstance *this) { //801DAE38
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined *puVar4;
  ObjDef *pOVar5;
  
  puVar4 = this->state;
  pOVar5 = this->def;
  if (puVar4[0xd] != '\0') {
    sVar1._0_1_ = pOVar5[1].loadFlags;
    sVar1._1_1_ = pOVar5[1].mapStates2;
    if ((sVar1 == 0) || (puVar4[0xc] == '\0')) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (uint)*(byte *)&pOVar5[1].pos.x;
      sVar2._0_1_ = pOVar5[1].loadFlags;
      sVar2._1_1_ = pOVar5[1].mapStates2;
                    /* {@symbol 800d0a70} */
      (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)sVar2);
    }
    if (pOVar5[1].bound != 0xff) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)(char)pOVar5[1].bound,this,uVar3);
    }
    puVar4[0xd] = 0;
  }
  return;
}


/* @description Override hit detection */

void door_hitDetect(ObjInstance *this) { //801DAEF0
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void door_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                 undefined param5,bool shouldRender) { //801DAEF4
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

void door_free(ObjInstance *this,int param2) { //801DAF50
  return;
}


undefined4 door_func08(ObjInstance *this) { //801DAF54
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int door_getExtraSize(void) { //801DAF5C
  return 0x10;
}

