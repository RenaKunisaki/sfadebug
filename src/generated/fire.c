
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void fire_initialise(undefined4 param) { //801EFB8C
  return;
}


/* @description Called when DLL is unloaded */

void fire_release(void) { //801EFB90
  return;
}


/* Library Function - Single Match
    dll_133_func03
   
   Library: KioskDefault 0 0 */

void fire_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801EFB94
  short sVar1;
  short sVar2;
  float fVar3;
  uint uVar4;
  LoadedDll *dll;
  short *psVar5;
  
  psVar5 = (short *)this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f0218;
  objAllocMsgQueue(this,2);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 < 1) {
    (this->pos).scale = 0.1;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    fVar3 = (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0) /
            8092.0;
    (this->pos).scale = this->data->scale * fVar3;
    this->hitstate->field16_0x52 =
         (ushort)(int)((float)((double)CONCAT44(0x43300000,(uint)this->data->hitbox_flagsB6) -
                              4503599627370496.0) * fVar3);
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->field76_0xf4 = 0;
  this->flags_0xf8 = 1;
  *psVar5 = *(short *)&objDef[1].bound;
  uVar4 = mainGetBit((int)*psVar5);
  psVar5[1] = (short)uVar4;
  dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
  (**(code **)(dll->id + 4))(this,0,0,&DAT_00010004,0xffffffff,0);
  DLL_free(dll);
  return;
}


/* Library Function - Single Match
    dll_133_func04
   
   Library: KioskDefault 0 0 */

void fire_update(ObjInstance *this) { //801EFCEC
  char cVar1;
  ObjDef *pOVar2;
  
  pOVar2 = this->def;
  FUN_801efe48((int *)this);
  cVar1 = *(char *)((int)&pOVar2[1].objType + 1);
  if (cVar1 == '\x01') {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    if (this->field76_0xf4 == 0) {
      objSendMsg((int)this,0x50001,(uint)this,0);
      this->field76_0xf4 = 1;
    }
  }
  else if (((cVar1 < '\x01') && (-1 < cVar1)) && (this->field76_0xf4 != 0)) {
                    /* {@symbol 800e3c34} */
    (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
  }
  return;
}


/* @description Override hit detection */

void fire_hitDetect(ObjInstance *this) { //801EFDA0
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void fire_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                 undefined param5,bool shouldRender) { //801EFDA4
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

void fire_free(ObjInstance *this,int param2) { //801EFE00
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  return;
}


undefined4 fire_func08(ObjInstance *this) { //801EFE38
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int fire_getExtraSize(void) { //801EFE40
  return 8;
}

