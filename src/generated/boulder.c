
/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func00
    dll_2FA_func00
    dll_2FB_func00
   
   Library: KioskDefault 0 0 */

void boulder2FB_initialise(undefined4 param) { //802CE6D0
  if (DAT_8039a198 == (DLL_func **)0x0) {
    DAT_8039a198 = DLL_setup(0x1002,1,FALSE);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func01
    dll_184_func01
    dll_210_func07
    dll_243_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void boulder2FB_release(void) { //802CE70C
  if (DAT_8039a198 != (LoadedDll *)0x0) {
    DLL_free(DAT_8039a198);
    DAT_8039a198 = (LoadedDll *)0x0;
  }
  return;
}


/* Library Function - Single Match
    dll_2FB_func03
   
   Library: KioskDefault 0 0 */

void boulder2FB_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802CE744
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  if (objDef[1].mapStates1 != 0) {
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,(uint)objDef[1].mapStates1) - 4503599627370496.0) /
         255.0;
    if ((this->pos).scale == 0.0) {
      (this->pos).scale = 1.0;
    }
    objHitFn_80089354(this,(short)(int)((float)((double)CONCAT44(0x43300000,
                                                                 (int)(short)this->hitstate->
                                                                             field16_0x52 ^
                                                                 0x80000000) - 4503601774854144.0) *
                                       (this->pos).scale));
    (this->pos).scale = (this->pos).scale * this->data->scale;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_2FB_func04
   
   Library: KioskDefault 0 0 */

void boulder2FB_update(ObjInstance *this) { //802CE84C
  int iVar1;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  float local_3c;
  float local_38;
  undefined4 uStack_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint uStack_1c;
  int iStack_18;
  int local_14 [3];
  
  local_2c = 8;
  local_28 = 0xb4;
  local_24 = 0xf0;
  local_20 = 0xff;
  iVar1 = FUN_800884c8((int)this,local_14,&iStack_18,&uStack_1c,&local_38,&uStack_34,&local_30);
  if ((iVar1 != 0) && (iVar1 != 0x11)) {
    if ((*(int *)(local_14[0] + 0xc4) != 0) &&
       (*(short *)(*(int *)(local_14[0] + 0xc4) + 0x44) == 1)) {
      FUN_801a83d0();
    }
    audioTryStartSfx((int *)this,1,0x226,0x7f,"boulder.c",0x59);
    local_38 = local_38 + playerMapOffsetX;
    local_30 = local_30 + playerMapOffsetZ;
    local_3c = 1.0;
    local_40 = 0;
    local_42 = 0;
    local_44 = 0;
    (**(code **)(*DAT_8039a198 + 4))(0,1,&local_44,0x401,0xffffffff,&local_2c);
  }
  return;
}


/* @description Override hit detection */

void boulder2FB_hitDetect(ObjInstance *this) { //802CE984
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void boulder2FB_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //802CE988
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void boulder2FB_free(ObjInstance *this,int param2) { //802CE9D4
  return;
}


undefined4 boulder2FB_func08(ObjInstance *this) { //802CE9D8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int boulder2FB_getExtraSize(void) { //802CE9E0
  return 0;
}

