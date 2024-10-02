
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRyoutube_initialise(undefined4 param) { //802B5A10
  return;
}


/* @description Called when DLL is unloaded */

void DRyoutube_release(void) { //802B5A14
  return;
}


/* Library Function - Single Match
    dll_2B0_func03
   
   Library: KioskDefault 0 0 */

void DRyoutube_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802B5A18
  uint uVar1;
  undefined4 *puVar2;
  short **ppsVar3;
  
  ppsVar3 = (short **)this->state;
  *(byte *)((int)ppsVar3 + 5) =
       *(char *)((int)&objDef[1].objType + 1) << 4 | *(byte *)((int)ppsVar3 + 5) & 0xf;
  *ppsVar3 = (short *)((uint)(*(byte *)((int)ppsVar3 + 5) >> 4) * 6 + -0x7fcdc598);
  uVar1 = FUN_802b5dd4(*ppsVar3);
  *(char *)(ppsVar3 + 1) = (char)uVar1;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  for (uVar1 = 0; (int)uVar1 < 3; uVar1 = uVar1 + 1) {
    puVar2 = (undefined4 *)FUN_80094400((int)this,uVar1);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0;
    }
  }
  uVar1 = mainGetBit(0x5ff);
  DAT_8039a158 = (char)uVar1;
  if (DAT_8039a158 != '\0') {
    audioTryStartSfx((int *)this,0x40,1,0x7f,"DRyoutube.c",0x6d);
  }
  return;
}


/* Library Function - Single Match
    dll_2B0_func04
   
   Library: KioskDefault 0 0 */

void DRyoutube_update(ObjInstance *this) { //802B5B08
  uint uVar1;
  short **ppsVar2;
  
  ppsVar2 = (short **)this->state;
  if (DAT_8039a158 == '\0') {
    if (*(char *)(ppsVar2 + 1) != '\0') {
      audioTryStartSfx((int *)this,0xc0,0x6f,0x7f,"DRyoutube.c",0x83);
    }
    uVar1 = FUN_802b5dd4(*ppsVar2);
    *(char *)(ppsVar2 + 1) = (char)uVar1;
    FUN_802b5ca4((int)this,(uint)*(byte *)(ppsVar2 + 1));
  }
  else {
    if (this->animId != 0) {
      Object_ObjAnimSetMove(0.0,this,0,0);
    }
    objRunAnimation(0.009999999776482582,(double)timeDelta,(int)this,(float *)0x0);
    FUN_802b5ca4((int)this,7);
  }
  if (((*(byte *)((int)ppsVar2 + 5) >> 4 == 0) && (DAT_8039a158 == '\0')) &&
     (uVar1 = FUN_802b5dd4((short *)&DAT_803981b0), 6 < (uVar1 & 0xff))) {
    mainSetBits(0x5ff,1);
    DAT_8039a158 = '\x01';
    audioTryStartSfx((int *)this,0x40,0x6f,0x7f,"DRyoutube.c",0x8d);
  }
  return;
}


/* @description Override hit detection */

void DRyoutube_hitDetect(ObjInstance *this) { //802B5C30
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRyoutube_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802B5C34
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

void DRyoutube_free(ObjInstance *this,int param2) { //802B5C90
  return;
}


undefined4 DRyoutube_func08(ObjInstance *this) { //802B5C94
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRyoutube_getExtraSize(void) { //802B5C9C
  return 8;
}

