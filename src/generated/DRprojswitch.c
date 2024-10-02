
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRprojswitch_initialise(undefined4 param) { //802BC4D4
  return;
}


/* @description Called when DLL is unloaded */

void DRprojswitch_release(void) { //802BC4D8
  return;
}


/* Library Function - Single Match
    dll_2BF_func03
   
   Library: KioskDefault 0 0 */

void DRprojswitch_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //802BC578
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  byte *pbVar7;
  
  pbVar7 = this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  (this->pos).rotation.y = (short)((int)sVar1 << 8);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  if (sVar2 == 0) {
    objDef[1].loadFlags = 0;
    objDef[1].mapStates2 = 0x40;
  }
  sVar3._0_1_ = objDef[1].loadFlags;
  sVar3._1_1_ = objDef[1].mapStates2;
  (this->pos).scale =
       (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0) *
       this->data->scale * 0.015625;
  sVar4._0_1_ = objDef[1].loadFlags;
  sVar4._1_1_ = objDef[1].mapStates2;
  uVar6 = (int)sVar4 * (uint)this->data->hitbox_flagsB6;
  this->hitstate->field16_0x52 =
       (short)((int)uVar6 >> 6) + (ushort)((int)uVar6 < 0 && (uVar6 & 0x3f) != 0);
  if ('\x01' < *(char *)((int)&objDef[1].objType + 1)) {
    *(undefined *)((int)&objDef[1].objType + 1) = 1;
  }
  sVar5._0_1_ = objDef[1].bound;
  sVar5._1_1_ = objDef[1].cullDist;
  uVar6 = mainGetBit((int)sVar5);
  *pbVar7 = (byte)(uVar6 << 6) & 0x40 | *pbVar7 & 0xbf;
  uVar6 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  *pbVar7 = (byte)(uVar6 << 7) | *pbVar7 & 0x7f;
  if ((*pbVar7 >> 6 & 1) == 0) {
    FUN_802bc4dc((int)this,0,0);
  }
  else {
    FUN_802bc4dc((int)this,
                 ((uint)(*pbVar7 >> 7) ^ (int)*(char *)((int)&objDef[1].objType + 1)) + 1 & 1,0);
  }
  return;
}


/* Library Function - Single Match
    dll_2BF_func04
   
   Library: KioskDefault 0 0 */

void DRprojswitch_update(ObjInstance *this) { //802BC6D0
  bool bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  ObjDef *pOVar5;
  byte *pbVar6;
  
  pOVar5 = this->def;
  pbVar6 = this->state;
  if ((*pbVar6 >> 6 & 1) == 0) {
    sVar2._0_1_ = pOVar5[1].bound;
    sVar2._1_1_ = pOVar5[1].cullDist;
    uVar3 = mainGetBit((int)sVar2);
    *pbVar6 = (byte)(uVar3 << 6) & 0x40 | *pbVar6 & 0xbf;
  }
  else {
    iVar4 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if (iVar4 == 0xe) {
      mainSetBits((int)*(short *)&pOVar5[1].pos.x,*pbVar6 >> 7 ^ 1);
    }
    uVar3 = mainGetBit((int)*(short *)&pOVar5[1].pos.x);
    bVar1 = *pbVar6 >> 7 != uVar3;
    if (bVar1) {
      *pbVar6 = (byte)((*pbVar6 >> 7 ^ 1) << 7) | *pbVar6 & 0x7f;
    }
    iVar4 = randInt(0,6);
    if (iVar4 == 0) {
      FUN_802bc4dc((int)this,0,0);
    }
    else {
      FUN_802bc4dc((int)this,
                   (((uint)(*pbVar6 >> 7) ^ (int)*(char *)((int)&pOVar5[1].objType + 1)) & 1) + 1,
                   (uint)bVar1);
    }
  }
  return;
}


/* @description Override hit detection */

void DRprojswitch_hitDetect(ObjInstance *this) { //802BC7E0
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRprojswitch_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802BC7E4
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

void DRprojswitch_free(ObjInstance *this,int param2) { //802BC840
  return;
}


undefined4 DRprojswitch_func08(ObjInstance *this) { //802BC844
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRprojswitch_getExtraSize(void) { //802BC84C
  return 4;
}

