
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBdustgeezer_initialise(undefined4 param) { //8029F78C
  return;
}


/* @description Called when DLL is unloaded */

void DBdustgeezer_release(void) { //8029F790
  return;
}


/* Library Function - Single Match
    dll_286_func03
   
   Library: KioskDefault 0 0 */

void DBdustgeezer_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8029F794
  uint uVar1;
  undefined uVar3;
  ObjInstance *pOVar2;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  uVar1 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  if (uVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  puVar5[0x2c] = uVar3;
  if (obj2 == (ObjInstance *)0x0) {
    for (iVar4 = 0; iVar4 < 8; iVar4 = iVar4 + 1) {
      pOVar2 = FUN_8029fd90((int)this,0x353);
      *(ObjInstance **)(puVar5 + iVar4 * 4) = pOVar2;
    }
  }
  Object_objAddObjectType(this,0x2c);
  Object_objAddObjectType(this,0x33);
  puVar5[0x2d] = 0;
  *(int *)(puVar5 + 0x20) = (int)*(char *)((int)&objDef[1].objType + 1);
  (this->pos).scale = this->data->scale * 0.5;
  Object_ObjAnimSetMove(0.0,this,0,0);
  return;
}


/* Library Function - Single Match
    dll_286_func04
   
   Library: KioskDefault 0 0 */

void DBdustgeezer_update(ObjInstance *this) { //8029F870
  short sVar1;
  ObjInstance *param2;
  ObjInstance *this_00;
  int iVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  double dVar5;
  undefined auStack_5c [12];
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  
  _savefpr_30();
  pOVar3 = this->def;
  puVar4 = this->state;
  if (puVar4[0x2c] == '\x01') {
    *(uint *)(puVar4 + 0x28) = *(int *)(puVar4 + 0x28) - (uint)framesThisStep;
    if (*(int *)(puVar4 + 0x28) < 0) {
      mainSetBits((int)*(short *)&pOVar3[1].pos.x,1);
      puVar4[0x2c] = 0;
    }
    if (this->data->scale * 0.5 < (this->pos).scale) {
      uStack_3c = (uint)framesThisStep;
      local_40 = 0x43300000;
      (this->pos).scale =
           (this->pos).scale *
           -((float)((double)CONCAT44(0x43300000,uStack_3c) - 4503599627370496.0) * 0.015 - 1.0);
      (this->pos).rotation.x = (this->pos).rotation.x + 0x200;
    }
  }
  else if ((puVar4[0x2c] == '\0') && (true)) {
    if ((puVar4[0x2d] & 1) == 0) {
      param2 = Object_objGetMain();
      this_00 = Object_getSidekicksLoaded();
      if ((this_00 != (ObjInstance *)0x0) &&
         (dVar5 = (double)objDistSqObj2Obj(this,param2), dVar5 <= 40000.0)) {
        (*this_00->dll->ptrs2[1].hitDetect)(this_00);
      }
    }
    else {
      iVar2 = randInt(0,5);
      if (iVar2 == 0) {
        audioTryStartSfx((int *)this,1,0x14d,0x7f,"DBdustgeezer.c",0xab);
        iVar2 = *(int *)(puVar4 + 0x24);
        *(int *)(puVar4 + 0x24) = iVar2 + -1;
        if (iVar2 + -1 == 0) {
          puVar4[0x2d] = puVar4[0x2d] & 0xfe;
          mainSetBits((int)*(short *)&pOVar3[1].pos.x,0);
          puVar4[0x2c] = 1;
          sVar1._0_1_ = pOVar3[1].allocatedSize;
          sVar1._1_1_ = pOVar3[1].mapStates1;
          *(int *)(puVar4 + 0x28) = (int)sVar1;
        }
      }
      uStack_2c = randInt(-0x14,0x14);
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      local_50 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 0.001;
      uStack_34 = randInt(0x14,0x50);
      uStack_34 = uStack_34 ^ 0x80000000;
      local_38 = 0x43300000;
      local_48 = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) * 0.01;
      uStack_3c = randInt(-0x14,0x14);
      uStack_3c = uStack_3c ^ 0x80000000;
      local_40 = 0x43300000;
      local_4c = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) * 0.001;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3c3,auStack_5c,0,0xffffffff,0);
    }
  }
  iVar2 = objRunAnimation(0.01200000010430813,(double)timeDelta,(int)this,(float *)0x0);
  if (iVar2 != 0) {
    (this->pos).scale = this->data->scale * 0.5;
    Object_ObjAnimSetMove(0.0,this,0,0);
    audioTryStartSfx((int *)this,1,0x14c,0x7f,"DBdustgeezer.c",0xd8);
  }
  iVar2 = randInt(0,10);
  if (iVar2 == 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3be,0,0,0xffffffff,0);
  }
  FUN_8029fe40((int)this);
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void DBdustgeezer_hitDetect(ObjInstance *this) { //8029FBB4
  return;
}


/* Library Function - Single Match
    dll_286_func06
   
   Library: KioskDefault 0 0 */

void DBdustgeezer_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8029FBB8
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->state[0x2c] != '\x02')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_286_func07
   
   Library: KioskDefault 0 0 */

void DBdustgeezer_free(ObjInstance *this,int param2) { //8029FC2C
  undefined *puVar1;
  int iVar2;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,0x2c);
  if (param2 == 0) {
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      Object_objFreeObject(*(ObjInstance **)(puVar1 + iVar2 * 4));
    }
  }
  Object_removePlayerObj(this,0x33);
  return;
}


undefined4 DBdustgeezer_func08(ObjInstance *this) { //8029FCA0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBdustgeezer_getExtraSize(void) { //8029FCA8
  return 0x30;
}


/* Library Function - Single Match
    dll_286_func0A
   
   Library: KioskDefault 0 0 */

void DBdustgeezer_setScale(ObjInstance *this,float scale) { //8029FCB0
  short sVar1;
  ObjDef *pOVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  pOVar2 = this->def;
  if ((*(int *)(puVar3 + 0x24) == 0) && (puVar3[0x2c] != '\x01')) {
    puVar3[0x2d] = puVar3[0x2d] | 1;
    Object_ObjAnimSetMove(0.0,this,1,0);
    audioTryStartSfx((int *)this,1,0x14c,0x7f,"DBdustgeezer.c",0x124);
    (this->pos).scale = (this->pos).scale * 1.5;
    sVar1._0_1_ = pOVar2[1].loadFlags;
    sVar1._1_1_ = pOVar2[1].mapStates2;
    *(int *)(puVar3 + 0x24) = (int)sVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_286_func0B
   
   Library: KioskDefault 0 0 */

uint DBdustgeezer_func0B(int param1) { //8029FD58
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - (uint)*(byte *)(*(int *)(param1 + 0xb8) + 0x2c));
  return uVar1 >> 5 & 0xff;
}


void DBdustgeezer_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //8029FD88
  return;
}

