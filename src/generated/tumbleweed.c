
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void Tumbleweed_initialise(undefined4 param) { //801C2174
  return;
}


/* @description Called when DLL is unloaded */

void Tumbleweed_release(void) { //801C2178
  return;
}


/* Library Function - Single Match
    dll_DD_func03
   
   Library: KioskDefault 0 0 */

void Tumbleweed_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801C217C
  int iVar1;
  ObjInstance **ppOVar2;
  uint uVar3;
  undefined *puVar4;
  int local_34;
  int local_30 [2];
  undefined4 local_28;
  uint uStack_24;
  longlong local_20;
  
  puVar4 = this->state;
  *(float *)(puVar4 + 0x288) = (this->pos).pos.x;
  *(float *)(puVar4 + 0x28c) = (this->pos).pos.z;
  iVar1 = (int)(*(float *)&objDef[1].loadFlags * 2.0);
  local_20 = (longlong)iVar1;
  *(short *)(puVar4 + 0x262) = (short)iVar1;
  puVar4[0x271] = objDef[1].mapStates1;
  puVar4[0x272] = 0;
  *(float *)(puVar4 + 0x264) = (this->pos).scale;
  uStack_24 = randInt(200,500);
  uStack_24 = uStack_24 ^ 0x80000000;
  local_28 = 0x43300000;
  *(float *)(puVar4 + 0x268) =
       *(float *)(puVar4 + 0x264) /
       (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
  *(undefined4 *)(puVar4 + 0x280) = 0;
  (this->vel).x = 0.0;
  (this->vel).y = 0.0;
  (this->vel).z = 0.0;
  *(undefined2 *)(puVar4 + 0x296) = 0x32;
  if ((this->romdefno != Tumbleweed1_040A) && (this->romdefno != Tumbleweed2_040B)) {
    if (this->romdefno != Tumbleweed3_04BB) {
      (this->pos).scale = 0.001;
                    /* {@symbol 8012ab10} */
      (**(code **)(*(int *)pDll1A + 4))(puVar4,0,0x40000,1);
                    /* {@symbol 8012ab74} */
      (**(code **)(*(int *)pDll1A + 8))(puVar4,1,&PTR_80310850,&DAT_80397b80,4);
                    /* {@symbol 8012b80c} */
      (**(code **)(*(int *)pDll1A + 0x20))(this,puVar4);
      puVar4[0x270] = 0;
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      if ((puVar4[0x271] & 1) != 0) {
        ppOVar2 = Object_getObjects(local_30,&local_34);
        for (; local_30[0] < local_34; local_30[0] = local_30[0] + 1) {
          if (ppOVar2[local_30[0]]->romdefno == 0x27f) {
            *(ObjInstance **)(puVar4 + 0x27c) = ppOVar2[local_30[0]];
            *(undefined2 *)(puVar4 + 0x284) =
                 *(undefined2 *)(*(int *)(*(int *)(puVar4 + 0x27c) + 0x4c) + 0x24);
            uVar3 = mainGetBit((int)*(short *)(puVar4 + 0x284));
            if (uVar3 != 0) {
              *(undefined4 *)(puVar4 + 0x27c) = 0;
            }
            local_30[0] = local_34;
          }
        }
      }
      goto LAB_801c23a0;
    }
  }
  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  puVar4[0x270] = 3;
  *(float *)(puVar4 + 0x268) = 480.0;
  (this->pos).scale = *(float *)(puVar4 + 0x264);
LAB_801c23a0:
  Object_objAddObjectType(this,4);
  Object_objAddObjectType(this,0x33);
  FUN_80088da4((int)this);
  return;
}


/* Library Function - Single Match
    dll_DD_func04
   
   Library: KioskDefault 0 0 */

void Tumbleweed_update(ObjInstance *this) { //801C23D4
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((this->romdefno == Tumbleweed1) || (this->romdefno == Tumbleweed1_040A)) {
    Tumbleweed1_Update(this);
  }
  else {
    FUN_801c2a3c(this);
  }
  tumbleweedFn_801c2460((int *)this);
  if (*(int *)(puVar1 + 0x27c) != 0) {
    (**(code **)(**(int **)(*(int *)(puVar1 + 0x27c) + 0x68) + 0x24))
              (*(undefined4 *)(puVar1 + 0x27c),this);
  }
  return;
}


/* @description Override hit detection */

void Tumbleweed_hitDetect(ObjInstance *this) { //801C30DC
  return;
}


/* Library Function - Single Match
    dll_DD_func06
   
   Library: KioskDefault 0 0 */

void Tumbleweed_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801C30E0
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ('\0' < shouldRender) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (uint)*(ushort *)(this->state + 0x262)) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    return;
  }
  return;
}


/* Library Function - Single Match
    dll_DD_func07
   
   Library: KioskDefault 0 0 */

void Tumbleweed_free(ObjInstance *this,int param2) { //801C31B4
  ObjDefEnum OVar1;
  ObjInstance **ppOVar2;
  int unaff_r28;
  undefined *puVar3;
  int local_18;
  int local_14;
  
  puVar3 = this->state;
  OVar1 = this->romdefno;
  if (OVar1 == Tumbleweed1_040A) {
LAB_801c3214:
    unaff_r28 = 0x28d;
  }
  else {
    if ((short)OVar1 < 0x40a) {
      if (OVar1 != Tumbleweed2) {
        if ((0x3fa < (short)OVar1) || (OVar1 != Tumbleweed1)) goto LAB_801c3228;
        goto LAB_801c3214;
      }
    }
    else {
      if (0x4b9 < (short)OVar1) {
        if ((short)OVar1 < 0x4bc) {
          unaff_r28 = 0x4b9;
        }
        goto LAB_801c3228;
      }
      if (0x40b < (short)OVar1) goto LAB_801c3228;
    }
    unaff_r28 = 0x3fd;
  }
LAB_801c3228:
  ppOVar2 = Object_getObjects(&local_14,&local_18);
  for (; local_14 < local_18; local_14 = local_14 + 1) {
    if (unaff_r28 == (short)ppOVar2[local_14]->romdefno) {
      (*(code *)ppOVar2[local_14]->dll->ptrs2->setScale)(ppOVar2[local_14],this);
    }
  }
  if (*(int *)(puVar3 + 0x27c) != 0) {
    mainSetBits((int)*(short *)(puVar3 + 0x284),1);
    *(undefined4 *)(puVar3 + 0x27c) = 0;
  }
  Object_removePlayerObj(this,4);
  Object_removePlayerObj(this,0x33);
  return;
}


undefined4 Tumbleweed_func08(ObjInstance *this) { //801C32EC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int Tumbleweed_getExtraSize(void) { //801C32F4
  return 0x29c;
}


void Tumbleweed_setScale(ObjInstance *this,float scale) { //801C32FC
  return;
}


void Tumbleweed_func0B(double param1,double param2,int param3) { //801C3318
  int iVar1;
  
  iVar1 = *(int *)(param3 + 0xb8);
  *(float *)(iVar1 + 0x288) = (float)param1;
  *(float *)(iVar1 + 0x28c) = (float)param2;
  return;
}


/* Library Function - Single Match
    dll_DD_func0C
   
   Library: KioskDefault 0 0 */

void Tumbleweed_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //801C3338
  undefined *puVar1;
  
  puVar1 = this->state;
  if (puVar1[0x270] == '\x01') {
    FUN_80088d3c((int)this);
    puVar1[0x270] = 2;
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  }
  return;
}


/* Library Function - Single Match
    dll_DD_func0D
   
   Library: KioskDefault 0 0 */

void Tumbleweed_render2(ObjInstance *this) { //801C338C
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_r4;
  undefined *puVar5;
  
  puVar5 = this->state;
  fVar1 = in_r4[1];
  fVar2 = (this->pos).pos.y;
  fVar3 = in_r4[2];
  fVar4 = (this->pos).pos.z;
  (this->vel).x = (*in_r4 - (this->pos).pos.x) * 0.02;
  (this->vel).y = (fVar1 - fVar2) * 0.02;
  (this->vel).z = (fVar3 - fVar4) * 0.02;
  puVar5[0x270] = 5;
  *(float **)(puVar5 + 0x290) = in_r4;
  return;
}


/* Library Function - Single Match
    dll_DD_func0E
   
   Library: KioskDefault 0 0 */

uint Tumbleweed_func0E(int param1) { //801C3410
  uint uVar1;
  
  uVar1 = countLeadingZeros(5 - (uint)*(byte *)(*(int *)(param1 + 0xb8) + 0x270));
  return uVar1 >> 5;
}


void Tumbleweed_func0F(int param1,undefined4 param2) { //801C3440
  *(undefined4 *)(*(int *)(param1 + 0xb8) + 0x280) = param2;
  return;
}

