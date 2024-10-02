
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBlightgo_initialise(undefined4 param) { //8029C2E0
  return;
}


/* @description Called when DLL is unloaded */

void DBlightgo_release(void) { //8029C2E4
  return;
}


/* Library Function - Single Match
    dll_27F_func03
   
   Library: KioskDefault 0 0 */

void DBlightgo_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8029C2E8
  int iVar1;
  undefined *puVar2;
  undefined auStack_34 [20];
  longlong local_20;
  
  Object_objAddObjectType(this,0x2a);
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  puVar2 = this->state;
  *puVar2 = 0;
  *(float *)(puVar2 + 0xc) = 100000.0;
  *(float *)(puVar2 + 8) = -100000.0;
  *(ushort *)(puVar2 + 0x2a) = (ushort)objDef[1].mapStates1;
  iVar1 = (int)(*(float *)&objDef[1].loadFlags * 100.0);
  local_20 = (longlong)iVar1;
  *(short *)(puVar2 + 0x2c) = (short)iVar1;
  printf(" Flow %f ",100.0);
  FUN_8029cd1c((int)this,(int)(puVar2 + 0x1c),(int)auStack_34);
  *(float *)(puVar2 + 0x10) = 22.0 / *(float *)(puVar2 + 0x1c);
  objSetModelNo(this,0);
  if (obj2 == (ObjInstance *)0x0) {
    FUN_8029ccec();
  }
  return;
}


/* Library Function - Single Match
    dll_27F_func04
   
   Library: KioskDefault 0 0 */

void DBlightgo_update(ObjInstance *this) { //8029C3FC
  int iVar1;
  ObjDef *pOVar2;
  byte *pbVar3;
  double dVar4;
  undefined auStack_4c [12];
  float local_40;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint uStack_24;
  undefined4 local_20;
  uint uStack_1c;
  
  local_34 = 0x41b40000;
  local_30 = 0x40800000;
  local_2c = 0x41b40000;
  pOVar2 = this->def;
  pbVar3 = this->state;
  n64GetEnabledButtonsPressed(0);
  if (((*(short *)(pbVar3 + 0x28) < 6) && (*pbVar3 < 3)) &&
     (*(undefined2 *)(pbVar3 + 0x28) = *(undefined2 *)(pbVar3 + 0x2c), *pbVar3 != 0)) {
    *pbVar3 = *pbVar3 + 1;
  }
  *(ushort *)(pbVar3 + 0x28) = *(short *)(pbVar3 + 0x28) - (ushort)framesThisStep;
  if ((*(short *)(pbVar3 + 0x28) < 0) && (*pbVar3 < 3)) {
    *(undefined2 *)(pbVar3 + 0x28) = 0;
  }
  FUN_8029cb3c((int)this);
                    /* {@symbol 8029c4fc} */
  switch(*pbVar3) {
  case 0:
    this->newOpacity = 0;
    break;
  case 1:
    this->newOpacity = 0xff;
    uStack_24 = (int)*(short *)(pbVar3 + 0x28) ^ 0x80000000;
    local_28 = 0x43300000;
    uStack_1c = (int)*(short *)(pbVar3 + 0x2a) ^ 0x80000000;
    local_20 = 0x43300000;
    FUN_8029cbcc();
    break;
  case 2:
    uStack_24 = (int)*(short *)(pbVar3 + 0x28) ^ 0x80000000;
    local_28 = 0x43300000;
    uStack_1c = (int)*(short *)(pbVar3 + 0x2c) ^ 0x80000000;
    local_20 = 0x43300000;
    FUN_8029cbcc();
    break;
  case 3:
    audioTryStartSfx((int *)this,2,0x5a,0x7f,"DBlightgo.c",0xef);
    *pbVar3 = 4;
    objSetModelNo(this,1);
    FUN_80088d3c((int)this);
    this->newOpacity = 0xff;
    *(float *)(pbVar3 + 0x18) = (this->pos).pos.y;
    *(float *)(pbVar3 + 0x14) = (this->pos).pos.y - 1.0;
    pbVar3[0x2f] = pbVar3[0x2f] & 0x7f;
    break;
  case 4:
    (this->pos).rotation.y = 0;
    iVar1 = FUN_8029cd70((short *)this);
    if (iVar1 == 0) {
      *(short *)(pbVar3 + 0x28) = *(short *)(pbVar3 + 0x28) + 0x400;
      uStack_24 = (int)*(short *)(pbVar3 + 0x28) ^ 0x80000000;
      local_28 = 0x43300000;
      dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      (this->pos).pos.y =
           (this->pos).pos.y * 0.8 +
           (float)(dVar4 * 0.8999999761581421 + (double)*(float *)(pbVar3 + 0x18)) * 0.2;
      pbVar3[0x2f] = pbVar3[0x2f] & 0x7f;
    }
    else {
      (this->pos).pos.y = (this->pos).pos.y * 0.8 + *(float *)(pbVar3 + 0x14) * 0.2;
      if (-1 < (char)pbVar3[0x2f]) {
        mainSetBits(0x82b,(uint)*(byte *)&pOVar2[1].objType);
      }
      pbVar3[0x2f] = pbVar3[0x2f] & 0x7f | 0x80;
    }
    FUN_8029cf08((int)this);
    break;
  case 5:
    FUN_8029ccbc();
    (this->pos).rotation.y = (ushort)*(byte *)((int)&pOVar2[1].objType + 1) << 8;
    objSetModelNo(this,0);
    audioTryStartSfx((int *)this,1,0x59,0x7f,"DBlightgo.c",0xe0);
    *pbVar3 = 1;
    *(undefined2 *)(pbVar3 + 0x28) = *(undefined2 *)(pbVar3 + 0x2a);
    uStack_1c = (int)*(short *)(pbVar3 + 0x28) ^ 0x80000000;
    local_20 = 0x43300000;
    uStack_24 = (int)*(short *)(pbVar3 + 0x2a) ^ 0x80000000;
    local_28 = 0x43300000;
    FUN_8029cbcc();
    break;
  case 6:
    if ((uint)this->newOpacity < (uint)framesThisStep * 3) {
      this->newOpacity = 0;
      *pbVar3 = 0;
      pbVar3[0x2f] = pbVar3[0x2f] & 0x7f;
      FUN_80088da4((int)this);
      objSetModelNo(this,0);
      (this->pos).pos.x = (pOVar2->pos).x;
      (this->pos).pos.y = (pOVar2->pos).y;
      (this->pos).pos.z = (pOVar2->pos).z;
    }
    else {
      uStack_24 = randInt(-0x1a,0x1a);
      uStack_24 = uStack_24 ^ 0x80000000;
      local_28 = 0x43300000;
      local_40 = (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
      uStack_1c = randInt(-0x1a,0x1a);
      uStack_1c = uStack_1c ^ 0x80000000;
      local_20 = 0x43300000;
      local_38 = (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0);
      for (iVar1 = 0; iVar1 < (int)(uint)framesThisStep; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3c2,auStack_4c,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3c0,auStack_4c,2,0xffffffff,0);
      }
      this->newOpacity = this->newOpacity + framesThisStep * -3;
    }
    FUN_8029cf08((int)this);
  }
  return;
}


/* @description Override hit detection */

void DBlightgo_hitDetect(ObjInstance *this) { //8029C950
  return;
}


/* Library Function - Single Match
    dll_27F_func06
   
   Library: KioskDefault 0 0 */

void DBlightgo_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8029C954
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  char *pcVar2;
  
  pcVar2 = this->state;
  if (shouldRender) {
    bVar1 = checkSomeDebugFlags_8017c4f8();
    if (bVar1) {
      objSetModelNo(this,1);
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    else if (*pcVar2 != '\0') {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
  }
  return;
}


/* Library Function - Single Match
    dll_27F_func07
   
   Library: KioskDefault 0 0 */

void DBlightgo_free(ObjInstance *this,int param2) { //8029CA00
  Object_removePlayerObj(this,0x2a);
  return;
}


undefined4 DBlightgo_func08(ObjInstance *this) { //8029CA2C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBlightgo_getExtraSize(void) { //8029CA34
  return 0x30;
}


/* Library Function - Single Match
    dll_27F_func0A
   
   Library: KioskDefault 0 0 */

void DBlightgo_setScale(ObjInstance *this,float scale) { //8029CA3C
  int in_r4;
  char *pcVar1;
  
  pcVar1 = this->state;
  if ((((*pcVar1 == '\0') || (*pcVar1 == '\x04')) &&
      ((*pcVar1 = (char)in_r4, in_r4 != 5 || (*pcVar1 != '\x04')))) && (in_r4 == 6)) {
    audioTryStartSfx((int *)this,4,0x22c,0x7f,"DBlightgo.c",0x16b);
  }
  return;
}


/* Library Function - Single Match
    dll_27F_func0B
   
   Library: KioskDefault 0 0 */

undefined4 DBlightgo_func0B(int param1) { //8029CADC
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((**(char **)(param1 + 0xb8) == '\x04') || (**(char **)(param1 + 0xb8) == '\x03')) {
    uVar1 = 1;
  }
  return uVar1;
}


/* Library Function - Single Match
    dll_27F_func0C
   
   Library: KioskDefault 0 0 */

void DBlightgo_modelMtxFn(ObjInstance *this,int param2,vec3f *param3) { //8029CB14
  countLeadingZeros(param2 - (uint)*(byte *)&this->def[1].objType);
  return;
}

