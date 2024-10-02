
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCtumbleweedmeter_initialise(undefined4 param) { //8025C77C
  return;
}


/* @description Called when DLL is unloaded */

void SCtumbleweedmeter_release(void) { //8025C780
  return;
}


/* Library Function - Single Match
    dll_1FC_func03
   
   Library: KioskDefault 0 0 */

void SCtumbleweedmeter_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8025C784
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *(float *)(puVar3 + 8) =
       171.0 / (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  uVar2 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  *(short *)(puVar3 + 0xc) = (short)uVar2;
  (this->pos).pos.y =
       (float)((double)CONCAT44(0x43300000,(int)*(short *)(puVar3 + 0xc) ^ 0x80000000) -
              4503601774854144.0) * *(float *)(puVar3 + 8) + (this->pos).pos.y;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  mainSetBits(0x642,0);
  return;
}


/* Library Function - Single Match
    dll_1FC_func04
   
   Library: KioskDefault 0 0 */

void SCtumbleweedmeter_update(ObjInstance *this) { //8025C838
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  ObjDef *pOVar6;
  undefined *puVar7;
  
  puVar7 = this->state;
  pOVar6 = this->def;
  sVar1._0_1_ = pOVar6[1].bound;
  sVar1._1_1_ = pOVar6[1].cullDist;
  uVar5 = mainGetBit((int)sVar1);
  if ((((uVar5 != 0) &&
       (sVar2._0_1_ = pOVar6[1].loadFlags, sVar2._1_1_ = pOVar6[1].mapStates2,
       uVar5 = mainGetBit((int)sVar2), uVar5 == 0)) &&
      (sVar3._0_1_ = pOVar6[1].allocatedSize, sVar3._1_1_ = pOVar6[1].mapStates1,
      *(short *)(puVar7 + 0xc) < sVar3)) && (uVar5 = mainGetBit(0x642), uVar5 != 0)) {
    mainSetBits(0x642,0);
    mainSetBits((int)*(short *)&pOVar6[1].pos.x,(int)*(short *)(puVar7 + 0xc));
    (this->pos).pos.y = (this->pos).pos.y + *(float *)(puVar7 + 8);
    *(short *)(puVar7 + 0xc) = *(short *)(puVar7 + 0xc) + 1;
    sVar4._0_1_ = pOVar6[1].allocatedSize;
    sVar4._1_1_ = pOVar6[1].mapStates1;
    if (*(short *)(puVar7 + 0xc) < sVar4) {
      mainSetBits(0x647,0);
    }
    else {
      audioStartSfx((int **)0x0,0x161,0x7f,0x40,(char *)&PTR_DAT_8031ba38,0x54);
      mainSetBits(0x647,1);
    }
  }
  return;
}


/* @description Override hit detection */

void SCtumbleweedmeter_hitDetect(ObjInstance *this) { //8025C92C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SCtumbleweedmeter_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8025C930
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


/* Library Function - Single Match
    dll_1FC_func07
   
   Library: KioskDefault 0 0 */

void SCtumbleweedmeter_free(ObjInstance *this,int param2) { //8025C98C
  mainSetBits((int)*(short *)&this->def[1].pos.x,(int)*(short *)(this->state + 0xc));
  return;
}


undefined4 SCtumbleweedmeter_func08(ObjInstance *this) { //8025C9C8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SCtumbleweedmeter_getExtraSize(void) { //8025C9D0
  return 0x10;
}

