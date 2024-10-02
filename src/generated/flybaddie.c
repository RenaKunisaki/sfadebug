
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void flybaddie_initialise(undefined4 param) { //802422DC
  return;
}


/* @description Called when DLL is unloaded */

void flybaddie_release(void) { //802422E0
  return;
}


/* Library Function - Single Match
    dll_1C8_func03
   
   Library: KioskDefault 0 0 */

void flybaddie_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802422E4
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  float *pfVar7;
  
  pfVar7 = (float *)this->state;
  pfVar7[0xe] = (this->pos).pos.x;
  pfVar7[0xf] = (this->pos).pos.y;
  pfVar7[0x10] = (this->pos).pos.z;
  fVar1 = (this->pos).pos.x;
  fVar2 = (this->pos).pos.y;
  fVar3 = (this->pos).pos.z;
  *pfVar7 = fVar1;
  pfVar7[4] = fVar2;
  pfVar7[8] = fVar3;
  pfVar7[1] = fVar1;
  pfVar7[5] = fVar2;
  pfVar7[9] = fVar3;
  pfVar7[2] = fVar1;
  pfVar7[6] = fVar2;
  pfVar7[10] = fVar3;
  pfVar7[3] = fVar1;
  pfVar7[7] = fVar2;
  pfVar7[0xb] = fVar3;
  pfVar7[0xd] = 0.0055;
  pfVar7[0xc] = 1.0;
  *(undefined *)((int)pfVar7 + 0x51) = 0;
  *(undefined *)(pfVar7 + 0x14) = 0;
  iVar6 = randInt(0,65000);
  *(short *)(pfVar7 + 0x12) = (short)iVar6;
  *(undefined2 *)((int)pfVar7 + 0x4a) = 10000;
  *(undefined *)((int)pfVar7 + 0x53) = 1;
  iVar6 = randInt(0,1000);
  *(short *)(pfVar7 + 0x13) = (short)iVar6 + 1000;
  iVar6 = randInt(0,1000);
  *(short *)((int)pfVar7 + 0x4e) = (short)iVar6;
  sVar4._0_1_ = objDef[1].allocatedSize;
  sVar4._1_1_ = objDef[1].mapStates1;
  if (sVar4 == 0) {
    pfVar7[0x11] = -130.0;
  }
  else {
    sVar5._0_1_ = objDef[1].allocatedSize;
    sVar5._1_1_ = objDef[1].mapStates1;
    pfVar7[0x11] = (float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - 4503601774854144.0
                          );
  }
  return;
}


/* Library Function - Single Match
    dll_1C8_func04
   
   Library: KioskDefault 0 0 */

void flybaddie_update(ObjInstance *this) { //80242450
  int iVar1;
  float *pfVar2;
  double dVar3;
  int local_1c;
  double local_18;
  
  pfVar2 = (float *)this->state;
  if (0 < *(short *)((int)pfVar2 + 0x4e)) {
    local_18 = (double)(longlong)(int)timeDelta;
    *(short *)((int)pfVar2 + 0x4e) = *(short *)((int)pfVar2 + 0x4e) - (short)(int)timeDelta;
  }
  if ((*(short *)((int)pfVar2 + 0x4e) != -999) && (*(short *)((int)pfVar2 + 0x4e) < 1)) {
    audioTryStartSfx((int *)this,1,0x6c,0x7f,"flybaddie.c",0x7a);
    *(undefined2 *)((int)pfVar2 + 0x4e) = 0xfc19;
  }
  (this->pos).rotation.x = (this->pos).rotation.x + *(short *)(pfVar2 + 0x12) / 10;
  (this->pos).rotation.y = (this->pos).rotation.y + *(short *)((int)pfVar2 + 0x4a) / 10;
  if (*(short *)(pfVar2 + 0x13) != 0) {
    local_18 = (double)(longlong)(int)timeDelta;
    *(short *)(pfVar2 + 0x13) = *(short *)(pfVar2 + 0x13) - (short)(int)timeDelta;
  }
  if (*(short *)(pfVar2 + 0x13) < 1) {
    FUN_802429d4((int)this);
    iVar1 = randInt(0,1000);
    *(short *)(pfVar2 + 0x13) = (short)iVar1 + 1000;
  }
  if (1.0 < pfVar2[0xc]) {
    pfVar2[0xc] = pfVar2[0xc] - 1.0;
    FUN_80242844((int)this);
  }
  dVar3 = FUN_8006b9dc((double)pfVar2[0xc],pfVar2,(float *)0x0);
  (this->pos).pos.x = (float)dVar3;
  dVar3 = FUN_8006b9dc((double)pfVar2[0xc],pfVar2 + 4,(float *)0x0);
  (this->pos).pos.y = (float)dVar3;
  dVar3 = FUN_8006b9dc((double)pfVar2[0xc],pfVar2 + 8,(float *)0x0);
  (this->pos).pos.z = (float)dVar3;
  local_18 = (double)CONCAT44(0x43300000,DAT_80399f10 + 1 ^ 0x80000000);
  pfVar2[0xc] = timeDelta * pfVar2[0xd] * (float)(local_18 - 4503601774854144.0) + pfVar2[0xc];
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,(char)this->curModel + 0x286,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,(char)this->curModel + 0x286,0,1,0xffffffff,0);
  iVar1 = FUN_800883e4((int)this,&local_1c,(int *)0x0,(uint *)0x0);
  if (((iVar1 == 0xe) && (local_1c != 0)) && (*(short *)(local_1c + 0x46) != 0x3fc)) {
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,(char)this->curModel + 0x286,0,1,0xffffffff,0);
    }
    *(char *)((int)pfVar2 + 0x52) = *(char *)((int)pfVar2 + 0x52) + '\x01';
    pfVar2[0xd] = pfVar2[0xd] * 1.2;
    if (*(byte *)((int)pfVar2 + 0x52) < 3) {
      objSetModelNo(this,(char)this->curModel + 1);
    }
    else {
      Object_objFreeObject(this);
      DAT_80399f10 = DAT_80399f10 + 1;
      if (2 < DAT_80399f10) {
        mainSetBits(0x5a9,1);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void flybaddie_hitDetect(ObjInstance *this) { //80242768
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1C8_func06
    dll_1D7_func06
   
   Library: KioskDefault 0 0 */

void flybaddie_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8024276C
  short sVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar2;
  
  pOVar2 = this->def;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((this != (ObjInstance *)0x0) && (((this->pos).flags & 0x100) != 0)) {
      sVar1._0_1_ = pOVar2[1].allocatedSize;
      sVar1._1_1_ = pOVar2[1].mapStates1;
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                                  4503601774854144.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
  }
  return;
}


/* @description Free object instance */

void flybaddie_free(ObjInstance *this,int param2) { //80242830
  return;
}


undefined4 flybaddie_func08(ObjInstance *this) { //80242834
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int flybaddie_getExtraSize(void) { //8024283C
  return 0x54;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void flybaddie1D7_initialise(undefined4 param) { //80249ED8
  return;
}


/* @description Called when DLL is unloaded */

void flybaddie1D7_release(void) { //80249EDC
  return;
}


/* Library Function - Single Match
    dll_1D7_func03
   
   Library: KioskDefault 0 0 */

void flybaddie1D7_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80249EE0
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  ObjInstance *pOVar6;
  int iVar7;
  float *pfVar8;
  
  pfVar8 = (float *)this->state;
  pOVar6 = Object_objGetMain();
  if (pOVar6 != (ObjInstance *)0x0) {
    pfVar8[0xe] = (pOVar6->pos).pos.x;
    pfVar8[0xf] = (pOVar6->pos).pos.y;
    pfVar8[0x10] = (pOVar6->pos).pos.z;
  }
  fVar1 = (this->pos).pos.x;
  fVar2 = (this->pos).pos.y;
  fVar3 = (this->pos).pos.z;
  *pfVar8 = fVar1;
  pfVar8[4] = fVar2;
  pfVar8[8] = fVar3;
  pfVar8[1] = fVar1;
  pfVar8[5] = fVar2;
  pfVar8[9] = fVar3;
  pfVar8[2] = fVar1;
  pfVar8[6] = fVar2;
  pfVar8[10] = fVar3;
  pfVar8[3] = fVar1;
  pfVar8[7] = fVar2;
  pfVar8[0xb] = fVar3;
  pfVar8[0xd] = 0.0055;
  pfVar8[0xc] = 1.0;
  *(undefined *)((int)pfVar8 + 0x51) = 0;
  *(undefined *)(pfVar8 + 0x14) = 0;
  iVar7 = randInt(0,65000);
  *(short *)(pfVar8 + 0x12) = (short)iVar7;
  *(undefined2 *)((int)pfVar8 + 0x4a) = 10000;
  *(undefined *)((int)pfVar8 + 0x53) = 1;
  iVar7 = randInt(0,1000);
  *(short *)(pfVar8 + 0x13) = (short)iVar7 + 1000;
  iVar7 = randInt(0,1000);
  *(short *)((int)pfVar8 + 0x4e) = (short)iVar7;
  sVar4._0_1_ = objDef[1].allocatedSize;
  sVar4._1_1_ = objDef[1].mapStates1;
  if (sVar4 == 0) {
    pfVar8[0x11] = -130.0;
  }
  else {
    sVar5._0_1_ = objDef[1].allocatedSize;
    sVar5._1_1_ = objDef[1].mapStates1;
    pfVar8[0x11] = (float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - 4503601774854144.0
                          );
  }
  return;
}


/* Library Function - Single Match
    dll_1D7_func04
   
   Library: KioskDefault 0 0 */

void dll_WGSH_flybaddie_update(ObjInstance *this) { //8024A05C
  ObjInstance *pOVar1;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  double dVar5;
  int local_24;
  double local_20;
  
  pfVar4 = (float *)this->state;
  local_24 = 0;
  pOVar1 = Object_objGetMain();
  if ((PTR_DAT_80397df0._0_1_ != '\0') && (pOVar1 != (ObjInstance *)0x0)) {
    pfVar4[0xe] = (pOVar1->pos).pos.x;
    pfVar4[0xf] = (pOVar1->pos).pos.y;
    pfVar4[0x10] = (pOVar1->pos).pos.z;
    PTR_DAT_80397df0._0_1_ = '\0';
  }
  uVar2 = mainGetBit(0x1d4);
  if (uVar2 == 0) {
    if (0 < *(short *)((int)pfVar4 + 0x4e)) {
      local_20 = (double)(longlong)(int)timeDelta;
      *(short *)((int)pfVar4 + 0x4e) = *(short *)((int)pfVar4 + 0x4e) - (short)(int)timeDelta;
    }
    if ((*(short *)((int)pfVar4 + 0x4e) != -999) && (*(short *)((int)pfVar4 + 0x4e) < 1)) {
      audioTryStartSfx((int *)this,0x40,0x6c,0x7f,"flybaddie.c",0x8b);
      *(undefined2 *)((int)pfVar4 + 0x4e) = 0xfc19;
    }
    (this->pos).rotation.x = (this->pos).rotation.x + *(short *)(pfVar4 + 0x12) / 10;
    (this->pos).rotation.y = (this->pos).rotation.y + *(short *)((int)pfVar4 + 0x4a) / 10;
    if (*(short *)(pfVar4 + 0x13) != 0) {
      local_20 = (double)(longlong)(int)timeDelta;
      *(short *)(pfVar4 + 0x13) = *(short *)(pfVar4 + 0x13) - (short)(int)timeDelta;
    }
    if (*(short *)(pfVar4 + 0x13) < 1) {
      FUN_8024a640((int)this);
      iVar3 = randInt(0,1000);
      *(short *)(pfVar4 + 0x13) = (short)iVar3 + 1000;
    }
    if (1.0 < pfVar4[0xc]) {
      pfVar4[0xc] = pfVar4[0xc] - 1.0;
      FUN_8024a4b0((int)this);
    }
    dVar5 = FUN_8006b9dc((double)pfVar4[0xc],pfVar4,(float *)0x0);
    (this->pos).pos.x = (float)dVar5;
    dVar5 = FUN_8006b9dc((double)pfVar4[0xc],pfVar4 + 4,(float *)0x0);
    (this->pos).pos.y = (float)dVar5;
    dVar5 = FUN_8006b9dc((double)pfVar4[0xc],pfVar4 + 8,(float *)0x0);
    (this->pos).pos.z = (float)dVar5;
    local_20 = (double)CONCAT44(0x43300000,DAT_80399f68 + 1 ^ 0x80000000);
    pfVar4[0xc] = timeDelta * pfVar4[0xd] * (float)(local_20 - 4503601774854144.0) + pfVar4[0xc];
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,(char)this->curModel + 0x286,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,(char)this->curModel + 0x286,0,1,0xffffffff,0);
    iVar3 = FUN_800883e4((int)this,&local_24,(int *)0x0,(uint *)0x0);
    if (((iVar3 == 0xe) && (local_24 != 0)) && (*(short *)(local_24 + 0x46) != 0x3fc)) {
      for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,(char)this->curModel + 0x286,0,1,0xffffffff,0);
      }
      *(char *)((int)pfVar4 + 0x52) = *(char *)((int)pfVar4 + 0x52) + '\x01';
      pfVar4[0xd] = pfVar4[0xd] * 1.2;
      if (*(byte *)((int)pfVar4 + 0x52) < 3) {
        objSetModelNo(this,(char)this->curModel + 1);
      }
      else {
        Object_objFreeObject(this);
        DAT_80399f68 = DAT_80399f68 + 1;
        if (2 < DAT_80399f68) {
          mainSetBits(0x1d8,1);
        }
      }
    }
  }
  else {
    Object_objFreeObject(this);
  }
  return;
}


/* @description Override hit detection */

void flybaddie1D7_hitDetect(ObjInstance *this) { //8024A3D4
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1C8_func06
    dll_1D7_func06
   
   Library: KioskDefault 0 0 */

void flybaddie1D7_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8024A3D8
  short sVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar2;
  
  pOVar2 = this->def;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((this != (ObjInstance *)0x0) && (((this->pos).flags & 0x100) != 0)) {
      sVar1._0_1_ = pOVar2[1].allocatedSize;
      sVar1._1_1_ = pOVar2[1].mapStates1;
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                                  4503601774854144.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
  }
  return;
}


/* @description Free object instance */

void flybaddie1D7_free(ObjInstance *this,int param2) { //8024A49C
  return;
}


undefined4 flybaddie1D7_func08(ObjInstance *this) { //8024A4A0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int flybaddie1D7_getExtraSize(void) { //8024A4A8
  return 0x54;
}

