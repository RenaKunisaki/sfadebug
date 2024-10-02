
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCtotembondpuz_initialise(undefined4 param) { //8025C9D8
  return;
}


/* @description Called when DLL is unloaded */

void SCtotembondpuz_release(void) { //8025C9DC
  return;
}


/* Library Function - Single Match
    dll_1FD_func03
   
   Library: KioskDefault 0 0 */

void SCtotembondpuz_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8025C9E0
  *(short *)(this->state + 2) = (short)((int)(uint)(ushort)(this->pos).rotation.x >> 0xe);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8025cc2c;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_1FD_func04
   
   Library: KioskDefault 0 0 */

void SCtotembondpuz_update(ObjInstance *this) { //8025CA24
  ObjInstance *pOVar1;
  ObjInstance *this_00;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = this->state;
  pOVar1 = Object_objGetMain();
  this_00 = Object_getSidekicksLoaded();
  if ((*pbVar3 & 1) != 0) {
    FUN_8025cffc((short *)this,pbVar3);
  }
  if ((*pbVar3 & 2) != 0) {
    if (this_00 != (ObjInstance *)0x0) {
      (*this_00->dll->ptrs2[1].getExtraSize)(this_00,*(int *)(pbVar3 + 4));
    }
    FUN_801a83dc((undefined2 *)pOVar1,&(this->pos).pos.x,(undefined2 *)this);
    uVar2 = mainGetBit(0x64c);
    if (uVar2 != 0) {
      mainSetBits(0x64c,0);
      uVar2 = FUN_8025d1c4(this,(int)pbVar3);
      if ((uVar2 & 0xff) != 0) {
        *pbVar3 = *pbVar3 | 4;
      }
      audioTryStartSfx((int *)this,1,0xf2,0x7f,"SCtotembondpuz.c",0x96);
    }
    if ((int)(uint)(ushort)(this->pos).rotation.x >> 0xe != (int)*(short *)(pbVar3 + 2)) {
      (this->pos).rotation.x =
           (short)(int)-(timeDelta * 256.0 -
                        (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000
                                                ) - 4503601774854144.0));
      if ((int)(uint)(ushort)(this->pos).rotation.x >> 0xe == (int)*(short *)(pbVar3 + 2)) {
        mainSetBits((uint)*(ushort *)(&DAT_80397e98 + *(short *)(pbVar3 + 2) * 2),1);
      }
    }
    if ((*pbVar3 & 0xc) != 0) {
      FUN_8025d108((int)this,pbVar3);
    }
  }
  return;
}


/* @description Override hit detection */

void SCtotembondpuz_hitDetect(ObjInstance *this) { //8025CBB8
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SCtotembondpuz_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8025CBBC
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

void SCtotembondpuz_free(ObjInstance *this,int param2) { //8025CC18
  return;
}


undefined4 SCtotembondpuz_func08(ObjInstance *this) { //8025CC1C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SCtotembondpuz_getExtraSize(void) { //8025CC24
  return 8;
}

