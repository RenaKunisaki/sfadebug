
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIM2flameburst_initialise(undefined4 param) { //8022B628
  return;
}


/* @description Called when DLL is unloaded */

void DIM2flameburst_release(void) { //8022B62C
  return;
}


/* Library Function - Single Match
    dll_216_func03
   
   Library: KioskDefault 0 0 */

void DIM2flameburst_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8022B630
  uint uVar1;
  undefined uVar3;
  void *pvVar2;
  uint unaff_r26;
  Mtx44 *pMVar4;
  int iVar5;
  void **ppvVar6;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  ppvVar6 = (void **)this->state;
  pMVar4 = this->modelInstances->mtxs[(char)this->curModel + -3];
  vtxAnimFn_800279cc(0.0,(int *)pMVar4,0,-1,0,0);
  FUN_80080bdc(1.0,(int *)pMVar4,0);
  *(undefined2 *)(ppvVar6 + 6) = *(undefined2 *)&objDef[1].allocatedSize;
  if (*(short *)(ppvVar6 + 6) < 0xf) {
    *(undefined2 *)(ppvVar6 + 6) = 0xf;
  }
  *(undefined2 *)((int)ppvVar6 + 0x1a) = *(undefined2 *)&objDef[1].loadFlags;
  if (*(short *)((int)ppvVar6 + 0x1a) < 0xf) {
    *(undefined2 *)((int)ppvVar6 + 0x1a) = 0xf;
  }
  ppvVar6[2] = (void *)((float)((double)CONCAT44(0x43300000,unaff_r26 ^ 0x80000000) -
                               4503601774854144.0) * (this->pos).scale);
  ppvVar6[2] = (void *)((float)ppvVar6[2] * (float)ppvVar6[2]);
  ppvVar6[3] = (void *)((float)((double)CONCAT44(0x43300000,unaff_r26 ^ 0x80000000) -
                               4503601774854144.0) * 5.0 * (this->pos).scale);
  ppvVar6[3] = (void *)((float)ppvVar6[3] * (float)ppvVar6[3]);
  uVar1 = mainGetBit(0x1f0);
  if (uVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  *(undefined *)((int)ppvVar6 + 0x1d) = uVar3;
  for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
    if ((&DAT_80397d38)[iVar5] == '\0') {
      (&DAT_80397d38)[iVar5] = 1;
      *(char *)((int)ppvVar6 + 0x1f) = (char)iVar5;
      iVar5 = 4;
    }
  }
  pvVar2 = mmAlloc(0x28,LFX_COL,"flameburst:light1");
  *ppvVar6 = pvVar2;
  loadAsset_fileWithOffsetLength
            (*ppvVar6,LACTIONS.bin,
             *(short *)((int)&PTR_DAT_80397d30 + (uint)*(byte *)((int)ppvVar6 + 0x1f) * 2) * 0x28,
             0x28);
  pvVar2 = mmAlloc(0x28,LFX_COL,"flameburst:light2");
  ppvVar6[1] = pvVar2;
  loadAsset_fileWithOffsetLength
            (ppvVar6[1],LACTIONS.bin,
             (*(short *)((int)&PTR_DAT_80397d30 + (uint)*(byte *)((int)ppvVar6 + 0x1f) * 2) + 1) *
             0x28,0x28);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_216_func04
   
   Library: KioskDefault 0 0 */

void DIM2flameburst_update(ObjInstance *this) { //8022B84C
  int iVar1;
  ObjInstance *pOVar2;
  uint uVar3;
  ObjDef *pOVar4;
  Mtx44 *pMVar5;
  short sVar6;
  undefined *puVar7;
  float local_a4;
  float local_a0;
  float local_9c;
  Mtx44 MStack_98;
  vec3s local_58 [2];
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  pOVar4 = this->def;
  puVar7 = this->state;
  if ((puVar7[0x1d] & 1) == 0) {
    pMVar5 = this->modelInstances->mtxs[(char)this->curModel + -3];
    if ((puVar7[0x1d] & 4) != 0) {
      if (1.0 <= *(float *)pMVar5->m31) {
        puVar7[0x1d] = puVar7[0x1d] & 0xfb;
      }
    }
    *(ushort *)(puVar7 + 0x18) = *(short *)(puVar7 + 0x18) - (ushort)framesThisStep;
    if (*(short *)(puVar7 + 0x18) < 1) {
      vtxAnimFn_800279cc(-0.1000000014901161,(int *)pMVar5,0,-1,0,0x10);
      *(undefined2 *)(puVar7 + 0x1a) = *(undefined2 *)&pOVar4[1].loadFlags;
      if (*(short *)(puVar7 + 0x1a) < 0xf) {
        *(undefined2 *)(puVar7 + 0x1a) = 0xf;
      }
      puVar7[0x1d] = puVar7[0x1d] | 1;
      audioTryStartSfx((int *)this,1,0x39,0x7f,"DIM2flameburst.c",0x106);
      puVar7[0x1c] = 0x14;
    }
  }
  else {
    if ((puVar7[0x1d] & 4) == 0) {
      puVar7[0x1d] = puVar7[0x1d] | 4;
      uStack_34 = randInt(0x14,0x28);
      uStack_34 = uStack_34 ^ 0x80000000;
      local_38 = 0x43300000;
      *(float *)(puVar7 + 0x10) =
           (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0);
      uStack_3c = randInt(6,10);
      uStack_3c = uStack_3c ^ 0x80000000;
      local_40 = 0x43300000;
      *(float *)(puVar7 + 0x14) =
           (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) / 20.0;
    }
    *(ushort *)(puVar7 + 0x1a) = *(short *)(puVar7 + 0x1a) - (ushort)framesThisStep;
    puVar7[0x1c] = puVar7[0x1c] - framesThisStep;
    if ((char)puVar7[0x1c] < '\x01') {
      audioTryStartSfx((int *)this,0xc0,0x6e,0x7f,"DIM2flameburst.c",0xe1);
    }
    if (*(short *)(puVar7 + 0x1a) < 1) {
      vtxAnimFn_800279cc(0.1000000014901161,
                         (int *)this->modelInstances->mtxs[(char)this->curModel + -3],0,-1,0,0x10);
      *(undefined2 *)(puVar7 + 0x18) = *(undefined2 *)&pOVar4[1].allocatedSize;
      if (*(short *)(puVar7 + 0x18) < 0xf) {
        *(undefined2 *)(puVar7 + 0x18) = 0xf;
      }
      puVar7[0x1d] = puVar7[0x1d] & 0xfe;
      audioTryStartSfx((int *)this,0x40,0x38,0x7f,"DIM2flameburst.c",0xef);
    }
  }
  iVar1 = FUN_80094400((int)this,0);
  sVar6 = -*(short *)(iVar1 + 10) + 0x100;
  if (0x800 < sVar6) {
    sVar6 = -*(short *)(iVar1 + 10) + -0x700;
  }
  *(short *)(iVar1 + 10) = -sVar6;
  iVar1 = FUN_80094400((int)this,1);
  sVar6 = -*(short *)(iVar1 + 10) + 0xa0;
  if (0x800 < sVar6) {
    sVar6 = -*(short *)(iVar1 + 10) + -0x760;
  }
  *(short *)(iVar1 + 10) = -sVar6;
  pOVar2 = Object_objGetMain();
  local_4c = -(this->pos).pos.x;
  local_48 = -(this->pos).pos.y;
  local_44 = -(this->pos).pos.z;
  local_58[0].x = -(this->pos).rotation.x;
  local_58[0].y = 0;
  local_58[0].z = 0;
  mtxRotateByVec3s(&MStack_98,local_58);
  multVectorByMatrix((double)(pOVar2->pos).pos.x,(double)(pOVar2->pos).pos.y,
                     (double)(pOVar2->pos).pos.z,&MStack_98,&local_9c,&local_a0,&local_a4);
  if ((puVar7[0x1d] & 2) != 0) {
    local_a0 = (this->pos).pos.y - (pOVar2->pos).pos.y;
    if (local_a0 < 0.0) {
      local_a0 = -local_a0;
    }
    if (local_a0 < 50.0) {
      local_a4 = local_a4 * local_a4;
      if (local_a4 <= *(float *)(puVar7 + 8)) {
        pMVar5 = this->modelInstances->mtxs[(char)this->curModel + -3];
        uStack_3c = (int)*(short *)(*(int *)((int)&pMVar5->m12 + (*(ushort *)&pMVar5->m23 & 2) * 2)
                                   + (uint)(byte)puVar7[0x1e] * 0x10) ^ 0x80000000;
        local_40 = 0x43300000;
        if (local_9c <=
            (this->pos).scale * (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0)
           ) {
          FUN_80088818((int)pOVar2,(int)this,'\v',4,0);
        }
      }
    }
  }
  if ((puVar7[0x1d] & 4) != 0) {
    *(float *)(puVar7 + 0x10) = *(float *)(puVar7 + 0x14) * timeDelta + *(float *)(puVar7 + 0x10);
    if (*(float *)(puVar7 + 0x10) <= 40.0) {
      if (*(float *)(puVar7 + 0x10) < 20.0) {
        uStack_3c = randInt(6,10);
        uStack_3c = uStack_3c ^ 0x80000000;
        local_40 = 0x43300000;
        *(float *)(puVar7 + 0x14) =
             (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) / 20.0;
        *(float *)(puVar7 + 0x10) = 20.0;
      }
    }
    else {
      uStack_3c = randInt(6,10);
      uStack_3c = uStack_3c ^ 0x80000000;
      local_40 = 0x43300000;
      *(float *)(puVar7 + 0x14) =
           -(float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) / 20.0;
      *(float *)(puVar7 + 0x10) = 40.0;
    }
    nop_8022BE4C();
  }
  uVar3 = mainGetBit(0x1f0);
  if (uVar3 == 0) {
    puVar7[0x1d] = puVar7[0x1d] & 0xfd;
  }
  else {
    puVar7[0x1d] = puVar7[0x1d] | 2;
  }
  return;
}


/* @description Override hit detection */

void DIM2flameburst_hitDetect(ObjInstance *this) { //8022BD74
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIM2flameburst_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8022BD78
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
    dll_216_func07
   
   Library: KioskDefault 0 0 */

void DIM2flameburst_free(ObjInstance *this,int param2) { //8022BDD4
  void **ppvVar1;
  
  ppvVar1 = (void **)this->state;
  if ((*(byte *)((int)ppvVar1 + 0x1d) & 4) != 0) {
    *(byte *)((int)ppvVar1 + 0x1d) = *(byte *)((int)ppvVar1 + 0x1d) & 0xfb;
  }
  mm_free(*ppvVar1);
  mm_free(ppvVar1[1]);
  (&DAT_80397d38)[*(byte *)((int)ppvVar1 + 0x1f)] = 0;
  return;
}


undefined4 DIM2flameburst_func08(ObjInstance *this) { //8022BE3C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIM2flameburst_getExtraSize(void) { //8022BE44
  return 0x20;
}

