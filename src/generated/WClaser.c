
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WClaser_initialise(undefined4 param) { //802C5A28
  return;
}


/* @description Called when DLL is unloaded */

void WClaser_release(void) { //802C5A2C
  return;
}


/* Library Function - Single Match
    dll_2E0_func03
   
   Library: KioskDefault 0 0 */

void WClaser_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //802C5A30
  short sVar1;
  short sVar2;
  int iVar3;
  Texture *pTVar4;
  uint uVar5;
  Texture **ppTVar6;
  
  ppTVar6 = (Texture **)this->state;
  objAllocMsgQueue(this,2);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  iVar3 = randInt(-0x50,0x50);
  ppTVar6[1] = (Texture *)
               (float)((double)CONCAT44(0x43300000,iVar3 + 400U ^ 0x80000000) - 4503601774854144.0);
  DAT_8039a180 = runlinkDownloadCode(0x1029,1);
  *(undefined2 *)((int)ppTVar6 + 0x36) = 0x118;
  if (*ppTVar6 == (Texture *)0x0) {
    pTVar4 = textureLoadAsset(0x2e);
    *ppTVar6 = pTVar4;
  }
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  uVar5 = randInt(0,(int)sVar1);
  ppTVar6[2] = (Texture *)
               (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - 4503601774854144.0);
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  uVar5 = randInt(0,(int)sVar2);
  ppTVar6[3] = (Texture *)
               (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - 4503601774854144.0);
  return;
}


/* Library Function - Single Match
    dll_2E0_func04
   
   Library: KioskDefault 0 0 */

void WClaser_update(ObjInstance *this) { //802C5B38
  float fVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  ObjInstance *param1;
  int iVar9;
  ObjInstance *pOVar10;
  undefined4 uVar11;
  ObjDef *pOVar12;
  undefined *puVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double local_78;
  
  _savefpr_21();
  pOVar12 = this->def;
  puVar13 = this->state;
  *(float *)(puVar13 + 4) = *(float *)(puVar13 + 4) - timeDelta;
  if ((*(char *)((int)&pOVar12[1].objType + 1) != '\0') && (uVar8 = mainGetBit(0x338), uVar8 != 0))
  {
    sVar3._0_1_ = pOVar12[1].bound;
    sVar3._1_1_ = pOVar12[1].cullDist;
    mainSetBits((int)sVar3,0);
  }
  sVar4._0_1_ = pOVar12[1].bound;
  sVar4._1_1_ = pOVar12[1].cullDist;
  uVar8 = mainGetBit((int)sVar4);
  if (uVar8 == 0) {
    *(float *)(puVar13 + 0xc) = 0.0;
    *(float *)(puVar13 + 4) = 0.0;
    puVar13[0x50] = 0;
    puVar13[0x52] = 0;
    *(float *)(puVar13 + 0x28) = 0.0;
  }
  else if ((puVar13[0x53] & 1) == 0) {
    if (*(char *)((int)&pOVar12[1].objType + 1) == '\0') {
      puVar13[0x53] = puVar13[0x53] | 1;
    }
    else {
      *(float *)(puVar13 + 0xc) = *(float *)(puVar13 + 0xc) - timeDelta;
      if (*(float *)(puVar13 + 0xc) <= 0.0) {
        sVar6._0_1_ = pOVar12[1].loadFlags;
        sVar6._1_1_ = pOVar12[1].mapStates2;
        local_78 = (double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000);
        *(float *)(puVar13 + 8) = (float)(local_78 - 4503601774854144.0);
        puVar13[0x53] = puVar13[0x53] | 1;
        *(float *)(puVar13 + 4) = 0.0;
        puVar13[0x50] = 0;
        puVar13[0x52] = 0;
        *(float *)(puVar13 + 0x28) = 0.0;
      }
    }
  }
  else {
    if (*(char *)((int)&pOVar12[1].objType + 1) != '\0') {
      *(float *)(puVar13 + 8) = *(float *)(puVar13 + 8) - timeDelta;
    }
    if (0.0 <= *(float *)(puVar13 + 8)) {
      if (0.0 <= *(float *)(puVar13 + 4)) {
        local_78 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar13 + 0x36) ^ 0x80000000);
        if (*(float *)(puVar13 + 4) < (float)(local_78 - 4503601774854144.0)) {
          if (puVar13[0x50] == '\0') {
            audioTryStartSfx((int *)this,0xc0,0x6a,0x7f,"WClaser.c",0x9b);
            if (puVar13[0x52] == '\0') {
              puVar13[0x52] = 1;
              audioTryStartSfx((int *)this,0x20,0x208,0x7f,"WClaser.c",0xa0);
            }
            puVar13[0x50] = 1;
            if (DAT_8039a180 != (int *)0x0) {
              if (*(char *)((int)&pOVar12[1].objType + 1) == '\x01') {
                uVar11 = 0xd;
              }
              else {
                uVar11 = 0xf;
              }
              (**(code **)(*DAT_8039a180 + 4))(this,uVar11,0,&DAT_00010004,0xffffffff,0);
            }
          }
          if (140.0 <= *(float *)(puVar13 + 4)) {
            if (*(float *)(puVar13 + 0x28) <= 1.0) {
              *(float *)(puVar13 + 0x28) = timeDelta * 0.052 + *(float *)(puVar13 + 0x28);
            }
          }
          else if (puVar13[0x50] == '\x01') {
            puVar13[0x50] = 2;
            if (DAT_8039a180 != (int *)0x0) {
              if (*(char *)((int)&pOVar12[1].objType + 1) == '\x01') {
                uVar11 = 0xd;
              }
              else {
                uVar11 = 0x10;
              }
              (**(code **)(*DAT_8039a180 + 4))(this,uVar11,0,&DAT_00010004,0xffffffff,0);
            }
          }
        }
      }
      else {
        *(float *)(puVar13 + 4) = 275.0;
        puVar13[0x50] = 0;
      }
    }
    else {
      sVar5._0_1_ = pOVar12[1].allocatedSize;
      sVar5._1_1_ = pOVar12[1].mapStates1;
      local_78 = (double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000);
      *(float *)(puVar13 + 0xc) = (float)(local_78 - 4503601774854144.0);
      puVar13[0x53] = puVar13[0x53] & 0xfe;
      FUN_80068a9c((uint)this,0x7f);
                    /* {@symbol 800e2b88} */
      (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
      audioTryStartSfx((int *)this,0x20,0x208,0x7f,"WClaser.c",0x94);
    }
  }
  FUN_800689dc(127.0,(int)this,0x40,(byte)(int)(*(float *)(puVar13 + 0x28) * 127.0));
  dVar17 = 170.0;
  dVar14 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                          (int)(this->pos).rotation.
                                                                               x ^ 0x80000000) -
                                                        4503601774854144.0) * 3.141593) / 32767.0));
  dVar15 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                      (int)(this->pos).rotation.x ^
                                                                      0x80000000) -
                                                    4503601774854144.0) * 3.141593) / 32767.0));
  dVar16 = -(double)(float)((double)(this->pos).pos.x * dVar14 +
                           (double)(float)((double)(this->pos).pos.z * dVar15));
  param1 = Object_objGetMain();
  puVar13[0x33] = puVar13[0x33] - framesThisStep;
  if ((char)puVar13[0x33] < '\0') {
    puVar13[0x33] = 0;
  }
  if ((puVar13[0x30] != '\0') &&
     (*(ushort *)(puVar13 + 0x34) = *(short *)(puVar13 + 0x34) + (ushort)framesThisStep,
     0x3c < *(short *)(puVar13 + 0x34))) {
    *(undefined2 *)(puVar13 + 0x34) = 0x3c;
    puVar13[0x31] = 1;
  }
  if (puVar13[0x31] == '\0') {
    puVar13[0x30] = puVar13[0x50] & 3;
  }
  else {
    puVar13[0x30] = 1;
  }
  sVar7._0_1_ = pOVar12[1].bound;
  sVar7._1_1_ = pOVar12[1].cullDist;
  uVar8 = mainGetBit((int)sVar7);
  if ((uVar8 == 0) || ((puVar13[0x53] & 1) == 0)) {
    puVar13[0x30] = 0;
  }
  if (((param1 != (ObjInstance *)0x0) && (puVar13[0x33] == '\0')) && (puVar13[0x30] != '\0')) {
    fVar2 = (float)((double)CONCAT44(0x43300000,(int)(char)puVar13[0x32] ^ 0x80000000) -
                   4503601774854144.0) + 5.0;
    fVar1 = (param1->pos).pos.y - (this->pos).pos.y;
    if ((fVar1 < fVar2) && (-(fVar2 + 25.0) < fVar1)) {
      dVar19 = -dVar15;
      dVar18 = -(double)(float)((double)(this->pos).pos.x * dVar19 +
                               (double)(float)((double)(this->pos).pos.z * dVar14));
      fVar1 = (float)(dVar18 + (double)(float)(dVar19 * (double)(param1->pos).pos.x +
                                              (double)(float)(dVar14 * (double)(param1->pos).pos.z))
                     );
      if (((fVar1 < fVar2) &&
          ((-fVar2 < fVar1 &&
           (dVar15 = (double)(float)(dVar16 + (double)(float)(dVar14 * (double)(param1->pos).pos.x +
                                                             (double)(float)(dVar15 * (double)(
                                                  param1->pos).pos.z))), 0.0 < dVar15)))) &&
         (dVar15 < dVar17)) {
        iVar9 = FUN_801a7998((int)param1);
        if (iVar9 == 0x1d7) {
          mainSetBits(0x468,1);
        }
        else {
          audioTryStartSfx((int *)this,1,0x1f8,0x7f,"WClaser.c",0x109);
          for (iVar9 = 0; iVar9 < 4; iVar9 = iVar9 + 1) {
            pOVar10 = Object_objGetMain();
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(pOVar10,0x28b,0,4,0xffffffff,0);
          }
          if (0.0 <= (float)(dVar18 + (double)(float)(dVar19 * (double)(param1->oldPos).x +
                                                     (double)(float)(dVar14 * (double)(param1->
                                                  oldPos).z)))) {
            fVar2 = 20.0;
          }
          else {
            fVar2 = -20.0;
          }
          *(float *)(puVar13 + 0x44) = (float)(dVar19 * (double)fVar2 + (double)(param1->pos).pos.x)
          ;
          *(float *)(puVar13 + 0x4c) = (float)(dVar14 * (double)fVar2 + (double)(param1->pos).pos.z)
          ;
          if ((puVar13[0x51] == '\0') || (puVar13[0x51] == '\x01')) {
            objSendMsg((int)param1,0x60003,(uint)(puVar13 + 0x38),0);
          }
          puVar13[0x33] = 0x14;
        }
      }
    }
  }
  _restfpr_21();
  return;
}


/* @description Override hit detection */

void WClaser_hitDetect(ObjInstance *this) { //802C6240
  return;
}


/* @description Override render */

void WClaser_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //802C6244
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19F_func07
    dll_23E_func07
    dll_2E0_func07
   
   Library: KioskDefault 0 0 */

void WClaser_free(ObjInstance *this,int param2) { //802C6248
  Texture **ppTVar1;
  
  ppTVar1 = (Texture **)this->state;
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_8039a180);
  DAT_8039a180 = (LoadedDll *)0x0;
  if (*ppTVar1 != (Texture *)0x0) {
    texFreeTexture(*ppTVar1);
  }
  *ppTVar1 = (Texture *)0x0;
  return;
}


undefined4 WClaser_func08(ObjInstance *this) { //802C62B8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WClaser_getExtraSize(void) { //802C62C0
  return 0x54;
}

