
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void projball_initialise(undefined4 param) { //801CBBC0
  return;
}


/* @description Called when DLL is unloaded */

void projball_release(void) { //801CBBC4
  return;
}


/* Library Function - Single Match
    dll_E9_func03
   
   Library: KioskDefault 0 0 */

void projball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801CBBC8
  short sVar1;
  int iVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  pOVar3 = this->def;
  iVar2 = randInt(600,900);
  *(short *)(puVar4 + 0x34) = (short)iVar2;
  iVar2 = randInt(-600,600);
  *(short *)(puVar4 + 0x36) = (short)iVar2;
  sVar1._0_1_ = pOVar3[1].allocatedSize;
  sVar1._1_1_ = pOVar3[1].mapStates1;
  if (sVar1 != 0) {
    puVar4[0x3e] = puVar4[0x3e] | 4;
  }
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field58_0xa1 = 1;
  }
  return;
}


/* Library Function - Single Match
    dll_E9_func04
   
   Library: KioskDefault 0 0 */

void projball_update(ObjInstance *this) { //801CBC50
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined param3;
  ObjDef *pOVar4;
  dword dVar5;
  undefined *puVar6;
  double dVar7;
  float local_3c;
  undefined auStack_38 [8];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  puVar6 = this->state;
  dVar5 = this->flags_0xf8;
  pOVar4 = this->def;
  if (*(float *)(puVar6 + 0x18) == 0.0) {
    dVar7 = (double)FUN_8007b0fc(&(this->vel).x);
    *(float *)(puVar6 + 0x14) = (float)(60.0 / dVar7);
  }
  *(float *)(puVar6 + 0x18) = *(float *)(puVar6 + 0x18) + timeDelta;
  if (*(float *)(puVar6 + 0x14) < *(float *)(puVar6 + 0x18)) {
    if (*(char *)((int)&pOVar4[1].objType + 1) == '\0') {
      param3 = 1;
    }
    else {
      param3 = 3;
    }
    objHitFn_80089074(this,0xe,param3,0);
  }
  local_2c = 0.0;
  local_28 = 0.0;
  local_24 = 0.0;
  uStack_14 = (int)*(char *)((int)&pOVar4[1].objType + 1) ^ 0x80000000;
  local_18 = 0x43300000;
  local_30 = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0);
  if ((puVar6[0x3e] & 1) == 0) {
    *(float *)(puVar6 + 8) = (this->pos).pos.x;
    *(float *)(puVar6 + 0xc) = (this->pos).pos.y;
    *(float *)(puVar6 + 0x10) = (this->pos).pos.z;
    puVar6[0x3e] = puVar6[0x3e] | 1;
  }
  if (this->hitstate->field54_0x9d != 0) {
    if (this->hitstate->field53_0x9c == 0xe) {
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x11b,0x7f,(char *)&PTR_DAT_80310e10,(int *)0x9f
                         );
                    /* {@symbol 800dac04} */
      (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,0);
                    /* {@symbol 800db230} */
      (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,0,
                 (int)(this->pos).rotation.x,2);
    }
    else {
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x163,0x7f,(char *)&PTR_DAT_80310e10,(int *)0x9d
                         );
    }
    *(undefined2 *)(puVar6 + 0x3a) = 0x32;
  }
  if (*(short *)(puVar6 + 0x3a) == 0) {
    (this->oldPos).x = (this->pos).pos.x;
    (this->oldPos).y = (this->pos).pos.y;
    (this->oldPos).z = (this->pos).pos.z;
    (this->pos).rotation.x =
         (this->pos).rotation.x + *(short *)(puVar6 + 0x36) * (ushort)framesThisStep;
    (this->pos).rotation.z =
         (this->pos).rotation.z + *(short *)(puVar6 + 0x34) * (ushort)framesThisStep;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x514,auStack_38,4,0xffffffff,0);
    sVar1 = *(short *)(puVar6 + 0x38);
    uVar2 = (ushort)framesThisStep;
    *(ushort *)(puVar6 + 0x38) = sVar1 - uVar2;
    if ((short)(sVar1 - uVar2) < 1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x515,auStack_38,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x516,auStack_38,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x518,auStack_38,4,0xffffffff,0);
      *(undefined2 *)(puVar6 + 0x38) = 0x32;
    }
    if (dVar5 != 0) {
      if ((*(ushort *)(dVar5 + 0xb0) & 0x40) == 0) {
        FUN_801cc380((int)this,(int)puVar6,dVar5);
      }
      else {
        this->flags_0xf8 = 0;
      }
    }
    *(float *)(puVar6 + 8) = (this->vel).x * timeDelta + *(float *)(puVar6 + 8);
    *(float *)(puVar6 + 0xc) = (this->vel).y * timeDelta + *(float *)(puVar6 + 0xc);
    *(float *)(puVar6 + 0x10) = (this->vel).z * timeDelta + *(float *)(puVar6 + 0x10);
    *(ushort *)(puVar6 + 0x3c) = *(short *)(puVar6 + 0x3c) + (ushort)framesThisStep * 0x5dc;
    if ((puVar6[0x3e] & 4) != 0) {
      *(float *)(puVar6 + 0xc) = -(timeDelta * 2.0 - *(float *)(puVar6 + 0xc));
      iVar3 = FUN_800ba478((double)*(float *)(puVar6 + 8),(double)*(float *)(puVar6 + 0xc),
                           (double)*(float *)(puVar6 + 0x10),(int)this,&local_3c,0);
      if (((iVar3 == 0) && (local_3c = local_3c - 10.0, local_3c < 0.0)) && (-15.0 < local_3c)) {
        *(float *)(puVar6 + 0xc) = *(float *)(puVar6 + 0xc) - local_3c;
      }
    }
    (this->pos).pos.x = *(float *)(puVar6 + 8);
    (this->pos).pos.y = *(float *)(puVar6 + 0xc);
    (this->pos).pos.z = *(float *)(puVar6 + 0x10);
    if (dVar5 != 0) {
      uStack_14 = (uint)*(ushort *)(puVar6 + 0x3c);
      local_18 = 0x43300000;
      dVar7 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_14) -
                                                           4503599627370496.0) * 3.141593) / 32767.0
                                                  ));
      (this->pos).pos.x = (float)(dVar7 * 8.0 + (double)(this->pos).pos.x);
      uStack_1c = (uint)*(ushort *)(puVar6 + 0x3c);
      local_20 = 0x43300000;
      dVar7 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_1c) -
                                                       4503599627370496.0) * 3.141593) / 32767.0));
      (this->pos).pos.z = (float)(dVar7 * 8.0 + (double)(this->pos).pos.z);
    }
    iVar3 = this->field76_0xf4 - (uint)framesThisStep;
    this->field76_0xf4 = iVar3;
    if (iVar3 < 0) {
      Object_objFreeObject(this);
    }
  }
  else {
    if ((puVar6[0x3e] & 2) == 0) {
      puVar6[0x3e] = puVar6[0x3e] | 2;
    }
    (this->vel).x = 0.0;
    (this->vel).y = 0.0;
    (this->vel).z = 0.0;
    objHitFn_80089114(this);
    *(short *)(puVar6 + 0x3a) = *(short *)(puVar6 + 0x3a) + -1;
    if (*(short *)(puVar6 + 0x3a) < 1) {
      Object_objFreeObject(this);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_E9_func05
   
   Library: KioskDefault 0 0 */

void projball_hitDetect(ObjInstance *this) { //801CC16C
  undefined *puVar1;
  undefined auStack_34 [8];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_18;
  uint uStack_14;
  
  puVar1 = this->state;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  uStack_14 = (int)*(char *)((int)&this->def[1].objType + 1) ^ 0x80000000;
  local_18 = 0x43300000;
  local_2c = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0);
  if (this->hitstate->field13_0x48 != 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x517,auStack_34,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x517,auStack_34,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x517,auStack_34,1,0xffffffff,0);
    *(undefined2 *)(puVar1 + 0x3a) = 0x32;
  }
  return;
}


/* @description Override render */

void projball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801CC278
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if ((bVar1) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_E9_func07
   
   Library: KioskDefault 0 0 */

void projball_free(ObjInstance *this,int param2) { //801CC2E0
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((puVar1[0x3e] & 2) == 0) {
    loadLfxAction(this,this,1);
    puVar1[0x3e] = puVar1[0x3e] | 2;
  }
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 projball_func08(ObjInstance *this) { //801CC370
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int projball_getExtraSize(void) { //801CC378
  return 0x40;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void projball1D8_initialise(undefined4 param) { //8024A858
  return;
}


/* @description Called when DLL is unloaded */

void projball1D8_release(void) { //8024A85C
  return;
}


/* Library Function - Single Match
    dll_1D8_func03
   
   Library: KioskDefault 0 0 */

void projball1D8_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8024A860
  undefined param3;
  ObjDef *pOVar1;
  
  pOVar1 = this->def;
  if (*(char *)((int)&pOVar1[1].objType + 1) == '\0') {
    param3 = 1;
  }
  else {
    param3 = 3;
  }
  objHitFn_80089074(this,0xe,param3,0);
  if (*(char *)((int)&pOVar1[1].objType + 1) == '\x01') {
    loadLfxAction(this,this,0x203);
  }
  else if (*(char *)((int)&pOVar1[1].objType + 1) == '\x02') {
    loadLfxAction(this,this,0x204);
  }
  else {
    loadLfxAction(this,this,0x201);
  }
  return;
}


/* Library Function - Single Match
    dll_1D8_func04
   
   Library: KioskDefault 0 0 */

void dll_WGSH_projball_update(ObjInstance *this) { //8024A928
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined *puVar4;
  undefined auStack_34 [8];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_18;
  uint uStack_14;
  
  puVar4 = this->state;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  uStack_14 = (int)*(char *)((int)&this->def[1].objType + 1) ^ 0x80000000;
  local_18 = 0x43300000;
  local_2c = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0);
  if ((puVar4[0x36] & 1) == 0) {
    *(float *)(puVar4 + 8) = (this->pos).pos.x;
    *(float *)(puVar4 + 0xc) = (this->pos).pos.y;
    *(float *)(puVar4 + 0x10) = (this->pos).pos.z;
    puVar4[0x36] = puVar4[0x36] | 1;
  }
  if (this->hitstate->field54_0x9d != 0) {
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x163,0x7f,"projball.c",(int *)0x81);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a0,auStack_34,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a0,auStack_34,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a0,auStack_34,1,0xffffffff,0);
    *(undefined2 *)(puVar4 + 0x32) = 0x32;
  }
  if (*(short *)(puVar4 + 0x32) == 0) {
    (this->oldPos).x = (this->pos).pos.x;
    (this->oldPos).y = (this->pos).pos.y;
    (this->oldPos).z = (this->pos).pos.z;
    (this->pos).rotation.x =
         (this->pos).rotation.x + *(short *)(puVar4 + 0x2e) * (ushort)framesThisStep;
    (this->pos).rotation.z =
         (this->pos).rotation.z + *(short *)(puVar4 + 0x2c) * (ushort)framesThisStep;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x29d,auStack_34,4,0xffffffff,0);
    sVar1 = *(short *)(puVar4 + 0x30);
    uVar2 = (ushort)framesThisStep;
    *(ushort *)(puVar4 + 0x30) = sVar1 - uVar2;
    if ((short)(sVar1 - uVar2) < 1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x29e,auStack_34,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x29f,auStack_34,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a1,auStack_34,4,0xffffffff,0);
      *(undefined2 *)(puVar4 + 0x30) = 0x32;
    }
    *(float *)(puVar4 + 8) = (this->vel).x * timeDelta + *(float *)(puVar4 + 8);
    *(float *)(puVar4 + 0xc) = (this->vel).y * timeDelta + *(float *)(puVar4 + 0xc);
    *(float *)(puVar4 + 0x10) = (this->vel).z * timeDelta + *(float *)(puVar4 + 0x10);
    *(ushort *)(puVar4 + 0x34) = *(short *)(puVar4 + 0x34) + (ushort)framesThisStep * 0x5dc;
    (this->pos).pos.x = *(float *)(puVar4 + 8);
    (this->pos).pos.y = *(float *)(puVar4 + 0xc);
    (this->pos).pos.z = *(float *)(puVar4 + 0x10);
    iVar3 = this->field76_0xf4 - (uint)framesThisStep;
    this->field76_0xf4 = iVar3;
    if (iVar3 < 0) {
      Object_objFreeObject(this);
    }
  }
  else {
    if ((puVar4[0x36] & 2) == 0) {
      loadLfxAction(this,this,1);
      puVar4[0x36] = puVar4[0x36] | 2;
    }
    (this->vel).x = 0.0;
    (this->vel).y = 0.0;
    (this->vel).z = 0.0;
    objHitFn_80089114(this);
    *(short *)(puVar4 + 0x32) = *(short *)(puVar4 + 0x32) + -1;
    if (*(short *)(puVar4 + 0x32) < 1) {
      Object_objFreeObject(this);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1D8_func05
   
   Library: KioskDefault 0 0 */

void projball1D8_hitDetect(ObjInstance *this) { //8024ACAC
  undefined *puVar1;
  undefined auStack_34 [8];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_18;
  uint uStack_14;
  
  puVar1 = this->state;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  uStack_14 = (int)*(char *)((int)&this->def[1].objType + 1) ^ 0x80000000;
  local_18 = 0x43300000;
  local_2c = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0);
  if ((this->hitstate->field13_0x48 != 0) &&
     (*(short *)(this->hitstate->field13_0x48 + 0x46) != 0x248)) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a0,auStack_34,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a0,auStack_34,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2a0,auStack_34,1,0xffffffff,0);
    *(undefined2 *)(puVar1 + 0x32) = 0x32;
  }
  return;
}


/* @description Override render */

void projball1D8_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //8024ADCC
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if ((bVar1) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_1D8_func07
   
   Library: KioskDefault 0 0 */

void projball1D8_free(ObjInstance *this,int param2) { //8024AE34
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((puVar1[0x36] & 2) == 0) {
    loadLfxAction(this,this,1);
    puVar1[0x36] = puVar1[0x36] | 2;
  }
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 projball1D8_func08(ObjInstance *this) { //8024AEAC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int projball1D8_getExtraSize(void) { //8024AEB4
  return 0x38;
}

