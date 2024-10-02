
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void laser_initialise(undefined4 param) { //80207048
  return;
}


/* @description Called when DLL is unloaded */

void laser_release(void) { //8020704C
  return;
}


/* Library Function - Single Match
    dll_161_func03
   
   Library: KioskDefault 0 0 */

void laser_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //80207050
  short sVar1;
  int *piVar2;
  
  piVar2 = (int *)this->state;
  objAllocMsgQueue(this,2);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  *piVar2 = (int)sVar1;
  return;
}


/* Library Function - Single Match
    dll_161_func04
   
   Library: KioskDefault 0 0 */

void laser_update(ObjInstance *this) { //802070A8
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  uint uVar6;
  char cVar10;
  ObjInstance **ppOVar7;
  ushort uVar9;
  ObjInstance *pOVar8;
  bool bVar11;
  Model *pMVar12;
  byte bVar13;
  ObjInstanceField58 *pOVar14;
  int iVar15;
  ObjDef *pOVar16;
  int *piVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double in_f19;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  int local_c4;
  float local_c0;
  float local_bc;
  double local_b8;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  
  _savefpr_18();
  pOVar16 = this->def;
  piVar17 = (int *)this->state;
  if (*piVar17 == -1) {
    cVar10 = '\x01';
  }
  else {
    uVar6 = mainGetBit(*piVar17);
    cVar10 = (char)uVar6;
  }
  sVar2._0_1_ = pOVar16[1].loadFlags;
  sVar2._1_1_ = pOVar16[1].mapStates2;
  if ((sVar2 == 0) || (cVar10 == '\0')) {
    sVar3._0_1_ = pOVar16[1].loadFlags;
    sVar3._1_1_ = pOVar16[1].mapStates2;
    if ((sVar3 != 0) || (cVar10 != '\0')) {
      audioTryStartSfx((int *)this,0xc0,0x1e0,0x7f,"laser.c",0x60);
      sVar4._0_1_ = pOVar16[1].allocatedSize;
      sVar4._1_1_ = pOVar16[1].mapStates1;
      uStack_a4 = (int)sVar4 ^ 0x80000000;
      local_a8 = 0x43300000;
      dVar23 = (double)(float)((double)CONCAT44(0x43300000,uStack_a4) - 4503601774854144.0);
      dVar22 = (double)(float)(dVar23 * dVar23);
      uStack_ac = (int)(this->pos).rotation.x ^ 0x80000000;
      local_b0 = 0x43300000;
      dVar18 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_ac) -
                                                        4503601774854144.0) * 3.141593) / 32767.0));
      local_b8 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
      dVar19 = (double)distanceFn_80293e80((double)(((float)(local_b8 - 4503601774854144.0) *
                                                    3.141593) / 32767.0));
      dVar21 = -(double)(float)((double)(this->pos).pos.x * dVar18 +
                               (double)(float)((double)(this->pos).pos.z * dVar19));
      dVar20 = (double)(float)(dVar23 * dVar19 + (double)(this->pos).pos.x);
      local_bc = (this->pos).pos.y;
      local_c0 = -(float)(dVar23 * dVar18 - (double)(this->pos).pos.z);
      ppOVar7 = Object_playerGetObject(6,&local_c4);
      iVar15 = 0;
      while( true ) {
        if (local_c4 <= iVar15) break;
        pOVar8 = ppOVar7[iVar15];
        local_b8 = (double)CONCAT44(0x43300000,(int)*(char *)(piVar17 + 8) ^ 0x80000000);
        dVar24 = (double)(float)(local_b8 - 4503601774854144.0);
        dVar25 = (double)((pOVar8->pos).pos.y - (this->pos).pos.y);
        pMVar12 = pOVar8->modelInstances->model;
        if (pMVar12 != (Model *)0x0) {
          uVar9 = modelGetFieldA4(*(Model **)pMVar12);
          local_b8 = (double)CONCAT44(0x43300000,(uint)uVar9);
          in_f19 = (double)(float)((double)(pOVar8->pos).scale *
                                   (double)((float)(local_b8 - 4503599627370496.0) * 0.8) + dVar24);
        }
        if ((((dVar25 < dVar24) && (-(double)(float)(dVar24 + 40.0) < dVar25)) &&
            (fVar1 = (pOVar8->pos).pos.x - (this->pos).pos.x,
            fVar5 = (pOVar8->pos).pos.z - (this->pos).pos.z,
            dVar25 = (double)(fVar1 * fVar1 + fVar5 * fVar5), dVar25 < dVar22)) &&
           ((dVar24 = (double)(float)(dVar21 + (double)(float)(dVar18 * (double)(pOVar8->pos).pos.x
                                                              + (double)(float)(dVar19 * (double)(
                                                  pOVar8->pos).pos.z))), dVar24 < in_f19 &&
            (-in_f19 < dVar24)))) {
          pOVar14 = pOVar8->field18_0x58;
          if ((pOVar14 == (ObjInstanceField58 *)0x0) || (pOVar14->field142_0x10d != 0)) {
            dVar22 = dVar25;
            dVar23 = sqrt(dVar25);
          }
          else {
            bVar13 = pOVar14->mtxIdx;
            multVectorByMatrix((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                               (double)(this->pos).pos.z,pOVar14->mtx + (bVar13 - 2),&fStack_d0,
                               &fStack_cc,&fStack_c8);
            multVectorByMatrix(dVar20,(double)local_bc,(double)local_c0,pOVar14->mtx + (bVar13 - 2),
                               &fStack_dc,&fStack_d8,&fStack_d4);
          }
        }
        iVar15 = iVar15 + 1;
      }
      pOVar8 = Object_objGetMain();
      *(u8 *)((int)piVar17 + 0x21) = *(char *)((int)piVar17 + 0x21) - framesThisStep;
      if (*(char *)((int)piVar17 + 0x21) < '\0') {
        *(undefined *)((int)piVar17 + 0x21) = 0;
      }
      iVar15 = 0;
      bVar13 = 0;
      if ((pOVar8 != (ObjInstance *)0x0) && (*(char *)((int)piVar17 + 0x21) == '\0')) {
        local_b8 = (double)CONCAT44(0x43300000,(int)*(char *)(piVar17 + 8) ^ 0x80000000);
        dVar25 = (double)((float)(local_b8 - 4503601774854144.0) + 5.0);
        dVar20 = (double)((pOVar8->pos).pos.y - (this->pos).pos.y);
        if ((dVar20 < dVar25) &&
           ((-(double)(float)(dVar25 + 25.0) < dVar20 &&
            (fVar1 = (pOVar8->pos).pos.x - (this->pos).pos.x,
            fVar5 = (pOVar8->pos).pos.z - (this->pos).pos.z,
            (double)(fVar1 * fVar1 + fVar5 * fVar5) < dVar22)))) {
          dVar22 = (double)(float)(dVar21 + (double)(float)(dVar18 * (double)(pOVar8->pos).pos.x +
                                                           (double)(float)(dVar19 * (double)(pOVar8
                                                  ->pos).pos.z)));
          bVar11 = FUN_80068b20((int)this,0x40);
          if (bVar11) {
            dVar20 = dVar22;
            if (dVar22 < 0.0) {
              dVar20 = -dVar22;
            }
            if (63.0 < dVar20) {
              dVar20 = 63.0;
            }
            iVar15 = (int)((float)(63.0 - dVar20) * 2.0);
            local_b8 = (double)(longlong)iVar15;
          }
          bVar13 = (byte)iVar15;
          if ((dVar22 < dVar25) && (-dVar25 < dVar22)) {
            if (0.0 <= (float)(dVar21 + (double)(float)(dVar18 * (double)(pOVar8->oldPos).x +
                                                       (double)(float)(dVar19 * (double)(pOVar8->
                                                  oldPos).z)))) {
              fVar1 = 20.0;
            }
            else {
              fVar1 = -20.0;
            }
            piVar17[0xc] = (int)(float)(dVar18 * (double)fVar1 + (double)(pOVar8->pos).pos.x);
            piVar17[0xe] = (int)(float)(dVar19 * (double)fVar1 + (double)(pOVar8->pos).pos.z);
            objSendMsg((int)pOVar8,0x60003,(uint)(piVar17 + 9),0);
            *(undefined *)((int)piVar17 + 0x21) = 0x14;
          }
        }
      }
      FUN_800689dc(127.0,(int)this,0x40,bVar13);
      *(undefined *)(piVar17 + 7) = 0xff;
      *(undefined *)((int)piVar17 + 0x1d) = 0;
      *(undefined *)((int)piVar17 + 0x1e) = 0;
      piVar17[1] = (int)0.0;
      piVar17[3] = (int)0.0;
      piVar17[5] = (int)0.0;
      piVar17[2] = piVar17[1];
      piVar17[4] = piVar17[3];
      piVar17[6] = (int)(float)((double)(float)piVar17[5] + dVar23);
      *(undefined *)(piVar17 + 8) = 4;
      *(undefined *)((int)piVar17 + 0x1f) = 1;
      goto LAB_802075b8;
    }
  }
  *(undefined *)((int)piVar17 + 0x1f) = 0;
  FUN_80068a9c((uint)this,0x40);
LAB_802075b8:
  _restfpr_18();
  return;
}


/* @description Override hit detection */

void laser_hitDetect(ObjInstance *this) { //802075D4
  return;
}


/* Library Function - Single Match
    dll_161_func06
   
   Library: KioskDefault 0 0 */

void laser_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //802075D8
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  short sVar9;
  short sVar10;
  bool bVar11;
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  short **param4_00;
  undefined3 in_register_0000001c;
  astruct_4 **param5_00;
  Gfx *pGVar12;
  short sVar13;
  undefined *puVar14;
  short *psVar15;
  ObjPos local_88 [3];
  
  param5_00 = (astruct_4 **)CONCAT31(in_register_0000001c,param5);
  param4_00 = (short **)CONCAT31(in_register_00000018,param4);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  puVar14 = this->state;
  if ((shouldRender) && (bVar11 = checkSomeDebugFlags_8017c4f8(), bVar11)) {
    objRenderCurrentModel
              (this,param2_00,(int *)CONCAT31(in_register_00000014,param3),param4_00,param5_00);
  }
  if (puVar14[0x1f] != '\0') {
    local_88[0].pos.x = (this->pos).pos.x;
    local_88[0].pos.y = (this->pos).pos.y;
    local_88[0].pos.z = (this->pos).pos.z;
    local_88[0].rotation.x = (this->pos).rotation.x;
    local_88[0].rotation.y = (this->pos).rotation.y;
    local_88[0].rotation.z = (this->pos).rotation.z;
    local_88[0].scale = 1.0;
    FUN_8006a754(1.0,param2_00,(int *)CONCAT31(in_register_00000014,param3),local_88,(Mtx44 *)0x0);
    FUN_800a4fa4(param2_00,(undefined4 *)0x0,(undefined4 *)0x0,0x17,0,0,1);
    psVar15 = *param4_00;
    memcpy_src_dst_len(&DAT_80314de8,*param5_00,0x80);
    uVar1 = puVar14[0x1c];
    uVar2 = puVar14[0x1d];
    uVar3 = puVar14[0x1e];
    pGVar12 = *param2_00;
    *param2_00 = pGVar12 + 1;
    pGVar12->cmd = (F3DEXcommand)&DAT_01008010;
    pGVar12->param = (u32)*param4_00;
    FUN_800a6d88((uint **)param2_00,*param5_00,8);
    *param5_00 = *param5_00 + 4;
    fVar4 = *(float *)(puVar14 + 0xc);
    fVar5 = *(float *)(puVar14 + 0x14);
    fVar6 = *(float *)(puVar14 + 8);
    fVar7 = *(float *)(puVar14 + 0x10);
    fVar8 = *(float *)(puVar14 + 0x18);
    sVar9 = (short)(int)*(float *)(puVar14 + 4);
    *psVar15 = sVar9 + (char)puVar14[0x20];
    sVar10 = (short)(int)fVar4;
    psVar15[1] = sVar10 + (char)puVar14[0x20];
    sVar13 = (short)(int)fVar5;
    psVar15[2] = sVar13;
    *(undefined *)(psVar15 + 6) = uVar1;
    *(undefined *)((int)psVar15 + 0xd) = uVar2;
    *(undefined *)(psVar15 + 7) = uVar3;
    *(undefined *)((int)psVar15 + 0xf) = 0x50;
    psVar15[8] = sVar9 - (char)puVar14[0x20];
    psVar15[9] = sVar10 + (char)puVar14[0x20];
    psVar15[10] = sVar13;
    *(undefined *)(psVar15 + 0xe) = uVar1;
    *(undefined *)((int)psVar15 + 0x1d) = uVar2;
    *(undefined *)(psVar15 + 0xf) = uVar3;
    *(undefined *)((int)psVar15 + 0x1f) = 0x50;
    psVar15[0x10] = sVar9 + (char)puVar14[0x20];
    psVar15[0x11] = sVar10 - (char)puVar14[0x20];
    psVar15[0x12] = sVar13;
    *(undefined *)(psVar15 + 0x16) = uVar1;
    *(undefined *)((int)psVar15 + 0x2d) = uVar2;
    *(undefined *)(psVar15 + 0x17) = uVar3;
    *(undefined *)((int)psVar15 + 0x2f) = 0x50;
    psVar15[0x18] = sVar9 - (char)puVar14[0x20];
    psVar15[0x19] = sVar10 - (char)puVar14[0x20];
    psVar15[0x1a] = sVar13;
    *(undefined *)(psVar15 + 0x1e) = uVar1;
    *(undefined *)((int)psVar15 + 0x3d) = uVar2;
    *(undefined *)(psVar15 + 0x1f) = uVar3;
    *(undefined *)((int)psVar15 + 0x3f) = 0x50;
    sVar9 = (short)(int)fVar6;
    psVar15[0x20] = sVar9 + (char)puVar14[0x20];
    sVar10 = (short)(int)fVar7;
    psVar15[0x21] = sVar10 + (char)puVar14[0x20];
    sVar13 = (short)(int)fVar8;
    psVar15[0x22] = sVar13;
    *(undefined *)(psVar15 + 0x26) = uVar1;
    *(undefined *)((int)psVar15 + 0x4d) = uVar2;
    *(undefined *)(psVar15 + 0x27) = uVar3;
    *(undefined *)((int)psVar15 + 0x4f) = 0x50;
    psVar15[0x28] = sVar9 - (char)puVar14[0x20];
    psVar15[0x29] = sVar10 + (char)puVar14[0x20];
    psVar15[0x2a] = sVar13;
    *(undefined *)(psVar15 + 0x2e) = uVar1;
    *(undefined *)((int)psVar15 + 0x5d) = uVar2;
    *(undefined *)(psVar15 + 0x2f) = uVar3;
    *(undefined *)((int)psVar15 + 0x5f) = 0x50;
    psVar15[0x30] = sVar9 + (char)puVar14[0x20];
    psVar15[0x31] = sVar10 - (char)puVar14[0x20];
    psVar15[0x32] = sVar13;
    *(undefined *)(psVar15 + 0x36) = uVar1;
    *(undefined *)((int)psVar15 + 0x6d) = uVar2;
    *(undefined *)(psVar15 + 0x37) = uVar3;
    *(undefined *)((int)psVar15 + 0x6f) = 0x50;
    psVar15[0x38] = sVar9 - (char)puVar14[0x20];
    psVar15[0x39] = sVar10 - (char)puVar14[0x20];
    psVar15[0x3a] = sVar13;
    *(undefined *)(psVar15 + 0x3e) = uVar1;
    *(undefined *)((int)psVar15 + 0x7d) = uVar2;
    *(undefined *)(psVar15 + 0x3f) = uVar3;
    *(undefined *)((int)psVar15 + 0x7f) = 0x50;
    *param4_00 = psVar15 + 0x40;
  }
  return;
}


/* @description Free object instance */

void laser_free(ObjInstance *this,int param2) { //80207970
  return;
}


undefined4 laser_func08(ObjInstance *this) { //80207974
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int laser_getExtraSize(void) { //8020797C
  return 0x3c;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void laser19F_initialise(undefined4 param) { //8023D28C
  return;
}


/* @description Called when DLL is unloaded */

void laser19F_release(void) { //8023D290
  return;
}


/* Library Function - Single Match
    dll_19F_func03
   
   Library: KioskDefault 0 0 */

void DFSH_LaserBeam_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8023D294
  int iVar1;
  Texture *pTVar2;
  Texture **ppTVar3;
  
  ppTVar3 = (Texture **)this->state;
  objAllocMsgQueue(this,2);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  iVar1 = randInt(-0x50,0x50);
  *(short *)(ppTVar3 + 0xb) = (short)iVar1 + 400;
  *(undefined *)((int)ppTVar3 + 0x49) = 0;
  DAT_80399ee8 = runlinkDownloadCode(0x1029,1);
  ppTVar3[7] = (Texture *)0.0;
  *(undefined *)((int)ppTVar3 + 0x4a) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined2 *)((int)ppTVar3 + 0x2e) = 0x118;
  if (*ppTVar3 == (Texture *)0x0) {
    pTVar2 = textureLoadAsset(0x2e);
    *ppTVar3 = pTVar2;
  }
  return;
}


/* Library Function - Single Match
    dll_19F_func04
   
   Library: KioskDefault 0 0 */

void DFSH_LaserBeam_update(ObjInstance *this) { //8023D340
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  uint uVar6;
  ObjInstance *param1;
  int iVar7;
  ObjInstance *pOVar8;
  ObjDef *pOVar9;
  undefined *puVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double local_90;
  double local_80;
  
  _savefpr_20();
  pOVar9 = this->def;
  puVar10 = this->state;
  *(ushort *)(puVar10 + 0x2c) = *(short *)(puVar10 + 0x2c) - (ushort)framesThisStep;
  sVar2._0_1_ = pOVar9[1].bound;
  sVar2._1_1_ = pOVar9[1].cullDist;
  uVar6 = mainGetBit((int)sVar2);
  if (uVar6 == 0) {
    if (*(short *)(puVar10 + 0x2c) < 0) {
      if (puVar10[0x25] == '\0') {
        *(undefined2 *)(puVar10 + 0x2c) = 400;
        audioTryStartSfx((int *)this,1,0x208,0x7f,"laser.c",0x66);
        *(float *)(puVar10 + 0x1c) = 0.0;
      }
      else {
        *(undefined2 *)(puVar10 + 0x2c) = 0x113;
      }
      puVar10[0x49] = 0;
    }
    else if (*(short *)(puVar10 + 0x2c) < *(short *)(puVar10 + 0x2e)) {
      if (puVar10[0x49] == '\0') {
        audioTryStartSfx((int *)this,0xc0,0x6a,0x7f,"laser.c",0x70);
        if (puVar10[0x25] == '\0') {
          audioTryStartSfx((int *)this,1,0x208,0x7f,"laser.c",0x73);
        }
        puVar10[0x49] = 1;
        if (DAT_80399ee8 != (int *)0x0) {
          (**(code **)(*DAT_80399ee8 + 4))(this,10,0,&DAT_00010004,0xffffffff,0);
        }
      }
      if (*(short *)(puVar10 + 0x2c) < 0x28) {
        FUN_80068a9c((uint)this,0x40);
        if ((0.0 <= *(float *)(puVar10 + 0x1c)) && (puVar10[0x25] == '\0')) {
          *(float *)(puVar10 + 0x1c) = -(timeDelta * 0.0026 - *(float *)(puVar10 + 0x1c));
        }
      }
      else if (*(short *)(puVar10 + 0x2c) < 0x8c) {
        if ((puVar10[0x49] == '\x01') && (puVar10[0x49] = 2, DAT_80399ee8 != (int *)0x0)) {
          (**(code **)(*DAT_80399ee8 + 4))(this,0xb,0,&DAT_00010004,0xffffffff,0);
        }
      }
      else if (*(float *)(puVar10 + 0x1c) <= 1.0) {
        *(float *)(puVar10 + 0x1c) = timeDelta * 0.052 + *(float *)(puVar10 + 0x1c);
      }
    }
  }
  if (puVar10[0x24] != '\0') {
    FUN_800689dc(127.0,(int)this,0x40,(byte)(int)(*(float *)(puVar10 + 0x1c) * 127.0));
  }
  sVar3._0_1_ = pOVar9[1].allocatedSize;
  sVar3._1_1_ = pOVar9[1].mapStates1;
  local_80 = (double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000);
  dVar16 = (double)(float)(local_80 - 4503601774854144.0);
  dVar13 = (double)(float)(dVar16 * dVar16);
  dVar11 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                      (int)(this->pos).rotation.x ^
                                                                      0x80000000) -
                                                    4503601774854144.0) * 3.141593) / 32767.0));
  local_90 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
  dVar12 = (double)distanceFn_80293e80((double)(((float)(local_90 - 4503601774854144.0) * 3.141593)
                                               / 32767.0));
  dVar15 = -(double)(float)((double)(this->pos).pos.x * dVar11 +
                           (double)(float)((double)(this->pos).pos.z * dVar12));
  param1 = Object_objGetMain();
  puVar10[0x27] = puVar10[0x27] - framesThisStep;
  if ((char)puVar10[0x27] < '\0') {
    puVar10[0x27] = 0;
  }
  if ((puVar10[0x4a] == '\x01') ||
     ((0.0 < (float)(dVar15 + (double)(float)(dVar11 * (double)(param1->pos).pos.x +
                                             (double)(float)(dVar12 * (double)(param1->pos).pos.z)))
      && (puVar10[0x4a] != '\0')))) {
    *(ushort *)(puVar10 + 0x2a) = *(short *)(puVar10 + 0x2a) - (ushort)framesThisStep;
    if (*(short *)(puVar10 + 0x2a) < 0) {
      *(undefined2 *)(puVar10 + 0x2a) = 0;
      puVar10[0x25] = 0;
    }
  }
  else {
    *(ushort *)(puVar10 + 0x2a) = *(short *)(puVar10 + 0x2a) + (ushort)framesThisStep;
    if (0x3c < *(short *)(puVar10 + 0x2a)) {
      *(undefined2 *)(puVar10 + 0x2a) = 0x3c;
      puVar10[0x25] = 1;
    }
  }
  if (puVar10[0x25] == '\0') {
    puVar10[0x24] = puVar10[0x49] & 3;
  }
  else {
    puVar10[0x24] = 1;
  }
  sVar4._0_1_ = pOVar9[1].bound;
  sVar4._1_1_ = pOVar9[1].cullDist;
  uVar6 = mainGetBit((int)sVar4);
  if (uVar6 != 0) {
    puVar10[0x24] = 0;
  }
  if (puVar10[0x27] == '\0') {
    *(undefined2 *)(puVar10 + 0x28) = 0;
  }
  if (((param1 != (ObjInstance *)0x0) && (puVar10[0x27] == '\0')) && (puVar10[0x24] != '\0')) {
    local_90 = (double)CONCAT44(0x43300000,(int)(char)puVar10[0x26] ^ 0x80000000);
    dVar17 = (double)((float)(local_90 - 4503601774854144.0) + 5.0);
    dVar14 = (double)((param1->pos).pos.y - (this->pos).pos.y);
    if (((dVar14 < dVar17) && (-(double)(float)(dVar17 + 25.0) < dVar14)) &&
       (fVar1 = (param1->pos).pos.x - (this->pos).pos.x,
       fVar5 = (param1->pos).pos.z - (this->pos).pos.z,
       (double)(fVar1 * fVar1 + fVar5 * fVar5) < dVar13)) {
      dVar14 = (double)(float)(dVar15 + (double)(float)(dVar11 * (double)(param1->pos).pos.x +
                                                       (double)(float)(dVar12 * (double)(param1->pos
                                                                                        ).pos.z)));
      dVar13 = dVar14;
      if (dVar14 < 0.0) {
        dVar13 = -dVar14;
      }
      if (63.0 < dVar13) {
        dVar13 = 63.0;
      }
      *(short *)(puVar10 + 0x28) = (short)(int)((float)(63.0 - dVar13) * 2.0);
      if (puVar10[0x48] == '\x01') {
                    /* {@symbol 800e2b88} */
        (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
        puVar10[0x48] = 0;
      }
      if ((dVar14 < dVar17) && (-dVar17 < dVar14)) {
        if (0.0 <= (float)(dVar15 + (double)(float)(dVar11 * (double)(param1->oldPos).x +
                                                   (double)(float)(dVar12 * (double)(param1->oldPos)
                                                                                    .z)))) {
          fVar1 = 20.0;
        }
        else {
          fVar1 = -20.0;
        }
        dVar13 = (double)fVar1;
        iVar7 = FUN_801a7998((int)param1);
        if (iVar7 == 0x1d7) {
          mainSetBits(0x468,1);
        }
        else {
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x1f8,0x7f,"laser.c",(int *)0xdd);
          for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
            pOVar8 = Object_objGetMain();
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(pOVar8,0x28b,0,4,0xffffffff,0);
          }
          *(float *)(puVar10 + 0x3c) = (float)(dVar11 * dVar13 + (double)(param1->pos).pos.x);
          *(float *)(puVar10 + 0x44) = (float)(dVar12 * dVar13 + (double)(param1->pos).pos.z);
          if ((puVar10[0x4a] == '\0') || (puVar10[0x4a] == '\x01')) {
            objSendMsg((int)param1,0x60003,(uint)(puVar10 + 0x30),0);
          }
          puVar10[0x27] = 0x14;
        }
      }
    }
  }
  if ((puVar10[0x24] == '\0') && (puVar10[0x48] == '\x01')) {
                    /* {@symbol 800e2b88} */
    (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
    puVar10[0x48] = 0;
  }
  *(float *)(puVar10 + 4) = 0.0;
  *(float *)(puVar10 + 0xc) = 0.0;
  *(float *)(puVar10 + 0x14) = 0.0;
  *(undefined4 *)(puVar10 + 8) = *(undefined4 *)(puVar10 + 4);
  *(undefined4 *)(puVar10 + 0x10) = *(undefined4 *)(puVar10 + 0xc);
  *(float *)(puVar10 + 0x18) = (float)((double)*(float *)(puVar10 + 0x14) + dVar16);
  puVar10[0x26] = 8;
  this->animTimer = timeDelta * 0.04 + this->animTimer;
  if (1.0 < this->animTimer) {
    this->animTimer = this->animTimer - 1.0;
  }
  _restfpr_20();
  return;
}


/* @description Override hit detection */

void laser19F_hitDetect(ObjInstance *this) { //8023DA5C
  return;
}


/* Library Function - Single Match
    dll_19F_func06
   
   Library: KioskDefault 0 0 */

void laser19F_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8023DA60
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  undefined3 in_register_00000010;
  Gfx *cmd;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  astruct_4 **param5_00;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined2 *puVar11;
  ObjPos local_90 [3];
  longlong local_48;
  
  param5_00 = (astruct_4 **)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  cmd = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar10 = (undefined4 *)this->state;
  if ((shouldRender) && (bVar8 = checkSomeDebugFlags_8017c4f8(), bVar8)) {
    objRenderCurrentModel
              (this,(Gfx **)cmd,(int *)CONCAT31(in_register_00000014,param3),param4_00,param5_00);
  }
  if (*(char *)(puVar10 + 9) != '\0') {
    local_90[0].pos.x = (this->pos).pos.x;
    local_90[0].pos.y = (this->pos).pos.y;
    local_90[0].pos.z = (this->pos).pos.z;
    local_90[0].rotation.x = (this->pos).rotation.x;
    local_90[0].rotation.y = (this->pos).rotation.y;
    local_90[0].rotation.z = (this->pos).rotation.z;
    local_90[0].scale = (float)puVar10[7];
    FUN_8006a754(1.0,(undefined4 *)cmd,(int *)CONCAT31(in_register_00000014,param3),local_90,
                 (Mtx44 *)0x0);
    iVar1 = (int)(this->animTimer * 8.0 * 65536.0);
    local_48 = (longlong)iVar1;
    RSP_setTevColor2(cmd,0xff,0xff,0xff,0xff);
    FUN_800a4fa4((Gfx **)cmd,(undefined4 *)*puVar10,(undefined4 *)0x0,0x80000007,iVar1,0,1);
    puVar11 = (undefined2 *)*param4_00;
    memcpy_src_dst_len(&DAT_80319738,*param5_00,0x40);
    puVar9 = (undefined4 *)cmd->cmd;
    cmd->cmd = (F3DEXcommand)(puVar9 + 2);
    *puVar9 = &DAT_01004008;
    puVar9[1] = *param4_00;
    FUN_800a6d88((uint **)cmd,*param5_00,2);
    *param5_00 = *param5_00 + 2;
    fVar2 = (float)puVar10[1];
    fVar3 = (float)puVar10[3];
    fVar4 = (float)puVar10[5];
    fVar5 = (float)puVar10[2];
    fVar6 = (float)puVar10[4];
    fVar7 = (float)puVar10[6];
    *puVar11 = (short)(int)fVar2;
    puVar11[1] = (short)(int)fVar3 + (short)*(char *)((int)puVar10 + 0x26);
    puVar11[2] = (short)(int)fVar4;
    *(undefined *)(puVar11 + 6) = 0xff;
    *(undefined *)((int)puVar11 + 0xd) = 0xff;
    *(undefined *)(puVar11 + 7) = 0xff;
    *(undefined *)((int)puVar11 + 0xf) = 0xff;
    puVar11[4] = 0;
    puVar11[5] = 0;
    puVar11[8] = (short)(int)fVar2;
    puVar11[9] = (short)(int)fVar3 - (short)*(char *)((int)puVar10 + 0x26);
    puVar11[10] = (short)(int)fVar4;
    *(undefined *)(puVar11 + 0xe) = 0xff;
    *(undefined *)((int)puVar11 + 0x1d) = 0xff;
    *(undefined *)(puVar11 + 0xf) = 0xff;
    *(undefined *)((int)puVar11 + 0x1f) = 0xff;
    puVar11[0xc] = 0;
    puVar11[0xd] = 0x400;
    puVar11[0x10] = (short)(int)fVar5;
    puVar11[0x11] = (short)(int)fVar6 + (short)*(char *)((int)puVar10 + 0x26);
    puVar11[0x12] = (short)(int)fVar7;
    *(undefined *)(puVar11 + 0x16) = 0xff;
    *(undefined *)((int)puVar11 + 0x2d) = 0xff;
    *(undefined *)(puVar11 + 0x17) = 0xff;
    *(undefined *)((int)puVar11 + 0x2f) = 0xff;
    puVar11[0x14] = 0x1400;
    puVar11[0x15] = 0;
    puVar11[0x18] = (short)(int)fVar5;
    puVar11[0x19] = (short)(int)fVar6 - (short)*(char *)((int)puVar10 + 0x26);
    puVar11[0x1a] = (short)(int)fVar7;
    *(undefined *)(puVar11 + 0x1e) = 0xff;
    *(undefined *)((int)puVar11 + 0x3d) = 0xff;
    *(undefined *)(puVar11 + 0x1f) = 0xff;
    *(undefined *)((int)puVar11 + 0x3f) = 0xff;
    puVar11[0x1c] = 0x1400;
    puVar11[0x1d] = 0x400;
    *param4_00 = puVar11 + 0x20;
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19F_func07
    dll_23E_func07
    dll_2E0_func07
   
   Library: KioskDefault 0 0 */

void laser19F_free(ObjInstance *this,int param2) { //8023DD78
  Texture **ppTVar1;
  
  ppTVar1 = (Texture **)this->state;
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_80399ee8);
  DAT_80399ee8 = (LoadedDll *)0x0;
  if (*ppTVar1 != (Texture *)0x0) {
    texFreeTexture(*ppTVar1);
  }
  *ppTVar1 = (Texture *)0x0;
  return;
}


undefined4 laser19F_func08(ObjInstance *this) { //8023DDE8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int laser19F_getExtraSize(void) { //8023DDF0
  return 0x4c;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void laser23E_initialise(undefined4 param) { //8027F844
  return;
}


/* @description Called when DLL is unloaded */

void laser23E_release(void) { //8027F848
  return;
}


/* Library Function - Single Match
    dll_23E_func03
   
   Library: KioskDefault 0 0 */

void LaserBeam_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8027F84C
  int iVar1;
  Texture *pTVar2;
  Texture **ppTVar3;
  
  ppTVar3 = (Texture **)this->state;
  objAllocMsgQueue(this,2);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  iVar1 = randInt(-0x50,0x50);
  *(short *)(ppTVar3 + 0xb) = (short)iVar1 + 400;
  *(undefined *)((int)ppTVar3 + 0x49) = 0;
  DAT_8039a050 = runlinkDownloadCode(0x1029,1);
  ppTVar3[7] = (Texture *)0.0;
  *(undefined *)((int)ppTVar3 + 0x4a) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined2 *)((int)ppTVar3 + 0x2e) = 0x118;
  if (*(char *)((int)ppTVar3 + 0x4a) == '\x1e') {
    if (*ppTVar3 == (Texture *)0x0) {
      pTVar2 = textureLoadAsset(0x3e9);
      *ppTVar3 = pTVar2;
    }
  }
  else if (*(char *)((int)ppTVar3 + 0x4a) == '\x01') {
    if (*ppTVar3 == (Texture *)0x0) {
      pTVar2 = textureLoadAsset(0x23d);
      *ppTVar3 = pTVar2;
    }
  }
  else if (*ppTVar3 == (Texture *)0x0) {
    pTVar2 = textureLoadAsset(0xd9);
    *ppTVar3 = pTVar2;
  }
  return;
}


/* Library Function - Single Match
    dll_23E_func04
   
   Library: KioskDefault 0 0 */

void LaserBeam_update(ObjInstance *this) { //8027F948
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  ObjInstance *param1;
  ObjInstance *pOVar8;
  ObjDef *pOVar9;
  undefined *puVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double local_98;
  
  _savefpr_20();
  pOVar9 = this->def;
  puVar10 = this->state;
  *(ushort *)(puVar10 + 0x2c) = *(short *)(puVar10 + 0x2c) - (ushort)framesThisStep;
  sVar2._0_1_ = pOVar9[1].bound;
  sVar2._1_1_ = pOVar9[1].cullDist;
  uVar6 = mainGetBit((int)sVar2);
  if (uVar6 != 0) {
    FUN_80068a9c((uint)this,0x40);
    goto LAB_8027fd04;
  }
  if (-1 < *(short *)(puVar10 + 0x2c)) {
    if (*(short *)(puVar10 + 0x2c) < *(short *)(puVar10 + 0x2e)) {
      if (puVar10[0x49] == '\0') {
        audioTryStartSfx((int *)this,0xc0,0x6a,0x7f,"laser.c",0x9b);
        if (puVar10[0x25] == '\0') {
          audioTryStartSfx((int *)this,1,0x208,0x7f,"laser.c",0x9f);
        }
        puVar10[0x49] = 1;
        if (puVar10[0x4a] == '\x01') {
          if (DAT_8039a050 != (int *)0x0) {
            (**(code **)(*DAT_8039a050 + 4))(this,2,0,&DAT_00010004,0xffffffff,0);
          }
        }
        else if (puVar10[0x4a] == '\x1e') {
          if (DAT_8039a050 != (int *)0x0) {
            (**(code **)(*DAT_8039a050 + 4))(this,0x1e,0,&DAT_00010004,0xffffffff,0);
          }
        }
        else if (DAT_8039a050 != (int *)0x0) {
          (**(code **)(*DAT_8039a050 + 4))(this,0,0,&DAT_00010004,0xffffffff,0);
        }
      }
      if (*(short *)(puVar10 + 0x2c) < 0x28) {
        if (puVar10[0x25] == '\x01') {
          FUN_80068a9c((uint)this,0x40);
        }
        if ((0.0 <= *(float *)(puVar10 + 0x1c)) && (puVar10[0x25] == '\0')) {
          *(float *)(puVar10 + 0x1c) = -(timeDelta * 0.0026 - *(float *)(puVar10 + 0x1c));
        }
      }
      else if (*(short *)(puVar10 + 0x2c) < 0x8c) {
        if (puVar10[0x49] == '\x01') {
          puVar10[0x49] = 2;
          if (puVar10[0x4a] == '\x01') {
            if (DAT_8039a050 != (int *)0x0) {
              (**(code **)(*DAT_8039a050 + 4))(this,3,0,&DAT_00010004,0xffffffff,0);
            }
          }
          else if (puVar10[0x4a] == '\x1e') {
            if (DAT_8039a050 != (int *)0x0) {
              (**(code **)(*DAT_8039a050 + 4))(this,0x1e,0,&DAT_00010004,0xffffffff,0);
            }
          }
          else if (DAT_8039a050 != (int *)0x0) {
            (**(code **)(*DAT_8039a050 + 4))(this,1,0,&DAT_00010004,0xffffffff,0);
          }
        }
      }
      else if (*(float *)(puVar10 + 0x1c) <= 1.0) {
        *(float *)(puVar10 + 0x1c) = timeDelta * 0.052 + *(float *)(puVar10 + 0x1c);
      }
    }
    goto LAB_8027fd04;
  }
  if (puVar10[0x25] == '\0') {
    if (puVar10[0x4a] == '\x03') {
LAB_8027f9c4:
      iVar7 = randInt(10,0x14);
      *(short *)(puVar10 + 0x2c) = (short)iVar7 * 0x1e;
    }
    else {
      if (puVar10[0x4a] == '\x1e') goto LAB_8027f9c4;
      *(undefined2 *)(puVar10 + 0x2c) = 400;
    }
    audioTryStartSfx((int *)this,1,0x208,0x7f,"laser.c",0x92);
    *(float *)(puVar10 + 0x1c) = 0.0;
  }
  else {
    *(undefined2 *)(puVar10 + 0x2c) = 0x113;
  }
  puVar10[0x49] = 0;
LAB_8027fd04:
  FUN_800689dc(127.0,(int)this,0x40,(byte)(int)(*(float *)(puVar10 + 0x1c) * 127.0));
  sVar3._0_1_ = pOVar9[1].allocatedSize;
  sVar3._1_1_ = pOVar9[1].mapStates1;
  dVar16 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0
                          );
  dVar13 = (double)(float)(dVar16 * dVar16);
  dVar11 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                      (int)(this->pos).rotation.x ^
                                                                      0x80000000) -
                                                    4503601774854144.0) * 3.141593) / 32767.0));
  local_98 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
  dVar12 = (double)distanceFn_80293e80((double)(((float)(local_98 - 4503601774854144.0) * 3.141593)
                                               / 32767.0));
  dVar15 = -(double)(float)((double)(this->pos).pos.x * dVar11 +
                           (double)(float)((double)(this->pos).pos.z * dVar12));
  param1 = Object_objGetMain();
  puVar10[0x27] = puVar10[0x27] - framesThisStep;
  if ((char)puVar10[0x27] < '\0') {
    puVar10[0x27] = 0;
  }
  if (((0.0 < (float)(dVar15 + (double)(float)(dVar11 * (double)(param1->pos).pos.x +
                                              (double)(float)(dVar12 * (double)(param1->pos).pos.z))
                     )) && (puVar10[0x4a] != '\x02')) || (puVar10[0x4a] == '\x1e')) {
    *(ushort *)(puVar10 + 0x2a) = *(short *)(puVar10 + 0x2a) - (ushort)framesThisStep;
    if (*(short *)(puVar10 + 0x2a) < 0) {
      *(undefined2 *)(puVar10 + 0x2a) = 0;
      puVar10[0x25] = 0;
    }
  }
  else {
    *(ushort *)(puVar10 + 0x2a) = *(short *)(puVar10 + 0x2a) + (ushort)framesThisStep;
    if (0x3c < *(short *)(puVar10 + 0x2a)) {
      *(undefined2 *)(puVar10 + 0x2a) = 0x3c;
      puVar10[0x25] = 1;
    }
  }
  if (puVar10[0x25] == '\0') {
    puVar10[0x24] = puVar10[0x49] & 3;
  }
  else {
    puVar10[0x24] = 1;
  }
  sVar4._0_1_ = pOVar9[1].bound;
  sVar4._1_1_ = pOVar9[1].cullDist;
  uVar6 = mainGetBit((int)sVar4);
  if (uVar6 != 0) {
    puVar10[0x24] = 0;
  }
  if (puVar10[0x27] == '\0') {
    *(undefined2 *)(puVar10 + 0x28) = 0;
  }
  if (((param1 != (ObjInstance *)0x0) && (puVar10[0x27] == '\0')) && (puVar10[0x24] != '\0')) {
    local_98 = (double)CONCAT44(0x43300000,(int)(char)puVar10[0x26] ^ 0x80000000);
    dVar17 = (double)((float)(local_98 - 4503601774854144.0) + 5.0);
    dVar14 = (double)((param1->pos).pos.y - (this->pos).pos.y);
    if (((dVar14 < dVar17) && (-(double)(float)(dVar17 + 25.0) < dVar14)) &&
       (fVar1 = (param1->pos).pos.x - (this->pos).pos.x,
       fVar5 = (param1->pos).pos.z - (this->pos).pos.z,
       (double)(fVar1 * fVar1 + fVar5 * fVar5) < dVar13)) {
      dVar14 = (double)(float)(dVar15 + (double)(float)(dVar11 * (double)(param1->pos).pos.x +
                                                       (double)(float)(dVar12 * (double)(param1->pos
                                                                                        ).pos.z)));
      dVar13 = dVar14;
      if (dVar14 < 0.0) {
        dVar13 = -dVar14;
      }
      if (63.0 < dVar13) {
        dVar13 = 63.0;
      }
      *(short *)(puVar10 + 0x28) = (short)(int)((float)(63.0 - dVar13) * 2.0);
      if (((70.0 <= dVar14) || (dVar14 <= -70.0)) && (puVar10[0x48] == '\x01')) {
                    /* {@symbol 800e2b88} */
        (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
        puVar10[0x48] = 0;
      }
      if ((dVar14 < dVar17) && (-dVar17 < dVar14)) {
        iVar7 = FUN_801a7998((int)param1);
        if ((iVar7 == 0x1d7) && (puVar10[0x4a] != '\x01')) {
          mainSetBits(0x468,1);
        }
        else {
          if (0.0 <= (float)(dVar15 + (double)(float)(dVar11 * (double)(param1->oldPos).x +
                                                     (double)(float)(dVar12 * (double)(param1->
                                                  oldPos).z)))) {
            fVar1 = 20.0;
          }
          else {
            fVar1 = -20.0;
          }
          dVar13 = (double)fVar1;
          audioSfxFn_800688bc((double)(param1->pos).pos.x,(double)(this->pos).pos.y,
                              (double)(param1->pos).pos.z,0x1f8,0x7f,"laser.c",(int *)0x12a
                             );
          for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
            pOVar8 = Object_objGetMain();
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(pOVar8,0x198,0,4,0xffffffff,0);
          }
          *(float *)(puVar10 + 0x3c) = (float)(dVar11 * dVar13 + (double)(param1->pos).pos.x);
          *(float *)(puVar10 + 0x44) = (float)(dVar12 * dVar13 + (double)(param1->pos).pos.z);
          if ((puVar10[0x4a] == '\0') || (puVar10[0x4a] == '\x01')) {
            objSendMsg((int)param1,0x60003,(uint)(puVar10 + 0x30),0);
          }
          else if ((puVar10[0x4a] == '\x02') ||
                  ((puVar10[0x4a] == '\x03' || (puVar10[0x4a] == '\x1e')))) {
            objSendMsg((int)param1,0x60004,(uint)(puVar10 + 0x30),2);
          }
          puVar10[0x27] = 0x14;
        }
      }
    }
  }
  if ((puVar10[0x24] == '\0') && (puVar10[0x48] == '\x01')) {
                    /* {@symbol 800e2b88} */
    (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
    puVar10[0x48] = 0;
  }
  *(float *)(puVar10 + 4) = 0.0;
  *(float *)(puVar10 + 0xc) = 0.0;
  *(float *)(puVar10 + 0x14) = 0.0;
  *(undefined4 *)(puVar10 + 8) = *(undefined4 *)(puVar10 + 4);
  *(undefined4 *)(puVar10 + 0x10) = *(undefined4 *)(puVar10 + 0xc);
  *(float *)(puVar10 + 0x18) = (float)((double)*(float *)(puVar10 + 0x14) + dVar16);
  puVar10[0x26] = 8;
  this->animTimer = timeDelta * 0.04 + this->animTimer;
  if (1.0 < this->animTimer) {
    this->animTimer = this->animTimer - 1.0;
  }
  _restfpr_20();
  return;
}


/* @description Override hit detection */

void laser23E_hitDetect(ObjInstance *this) { //80280268
  return;
}


/* Library Function - Single Match
    dll_23E_func06
   
   Library: KioskDefault 0 0 */

void laser23E_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8028026C
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  bool bVar8;
  undefined3 in_register_00000010;
  Gfx *cmd;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  int *param4_00;
  undefined3 in_register_0000001c;
  void **param5_00;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  ObjPos local_88;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  
  param5_00 = (void **)CONCAT31(in_register_0000001c,param5);
  param4_00 = (int *)CONCAT31(in_register_00000018,param4);
  cmd = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar11 = (undefined4 *)this->state;
  if ((shouldRender) && (bVar8 = checkSomeDebugFlags_8017c4f8(), bVar8)) {
    objRenderCurrentModel
              (this,(Gfx **)cmd,(int *)CONCAT31(in_register_00000014,param3),param4_00,param5_00);
  }
  if (*(char *)(puVar11 + 9) != '\0') {
    local_88.pos.x = (this->pos).pos.x;
    local_88.pos.y = (this->pos).pos.y;
    local_88.pos.z = (this->pos).pos.z;
    local_88.rotation.x = (this->pos).rotation.x;
    local_88.rotation.y = (this->pos).rotation.y;
    local_88.rotation.z = (this->pos).rotation.z;
    local_88.scale = (float)puVar11[7];
    FUN_8006a754(1.0,(undefined4 *)cmd,(int *)CONCAT31(in_register_00000014,param3),&local_88,
                 (Mtx44 *)0x0);
    iVar1 = (int)(this->animTimer * 8.0 * 65536.0);
    local_40 = (longlong)iVar1;
    RSP_setTevColor2(cmd,0xff,0xff,0xff,0xff);
    FUN_800a4fa4((Gfx **)cmd,(undefined4 *)*puVar11,(undefined4 *)0x0,0x80000007,iVar1,0,1);
    puVar12 = (undefined2 *)*param4_00;
    memcpy_src_dst_len(&DAT_8031d408,*param5_00,0x40);
    local_48 = (longlong)(int)(float)puVar11[1];
    fVar2 = (float)puVar11[3];
    local_50 = (longlong)(int)fVar2;
    fVar3 = (float)puVar11[5];
    local_58 = (longlong)(int)fVar3;
    fVar4 = (float)puVar11[2];
    local_60 = (longlong)(int)fVar4;
    fVar5 = (float)puVar11[4];
    local_68 = (longlong)(int)fVar5;
    fVar6 = (float)puVar11[6];
    local_70 = (longlong)(int)fVar6;
    uVar10 = (undefined2)(int)(float)puVar11[1];
    *puVar12 = uVar10;
    sVar7 = (short)(int)fVar2;
    puVar12[1] = sVar7 + *(char *)((int)puVar11 + 0x26);
    uVar9 = (undefined2)(int)fVar3;
    puVar12[2] = uVar9;
    *(undefined *)(puVar12 + 6) = 0xff;
    *(undefined *)((int)puVar12 + 0xd) = 0xff;
    *(undefined *)(puVar12 + 7) = 0xff;
    *(undefined *)((int)puVar12 + 0xf) = 0xff;
    puVar12[4] = 0;
    puVar12[5] = 0;
    puVar12[8] = uVar10;
    puVar12[9] = sVar7 - *(char *)((int)puVar11 + 0x26);
    puVar12[10] = uVar9;
    *(undefined *)(puVar12 + 0xe) = 0xff;
    *(undefined *)((int)puVar12 + 0x1d) = 0xff;
    *(undefined *)(puVar12 + 0xf) = 0xff;
    *(undefined *)((int)puVar12 + 0x1f) = 0xff;
    puVar12[0xc] = 0;
    puVar12[0xd] = 0x80;
    uVar10 = (undefined2)(int)fVar4;
    puVar12[0x10] = uVar10;
    sVar7 = (short)(int)fVar5;
    puVar12[0x11] = sVar7 + *(char *)((int)puVar11 + 0x26);
    uVar9 = (undefined2)(int)fVar6;
    puVar12[0x12] = uVar9;
    *(undefined *)(puVar12 + 0x16) = 0xff;
    *(undefined *)((int)puVar12 + 0x2d) = 0xff;
    *(undefined *)(puVar12 + 0x17) = 0xff;
    *(undefined *)((int)puVar12 + 0x2f) = 0xff;
    puVar12[0x14] = 0x280;
    puVar12[0x15] = 0;
    puVar12[0x18] = uVar10;
    puVar12[0x19] = sVar7 - *(char *)((int)puVar11 + 0x26);
    puVar12[0x1a] = uVar9;
    *(undefined *)(puVar12 + 0x1e) = 0xff;
    *(undefined *)((int)puVar12 + 0x3d) = 0xff;
    *(undefined *)(puVar12 + 0x1f) = 0xff;
    *(undefined *)((int)puVar12 + 0x3f) = 0xff;
    puVar12[0x1c] = 0x280;
    puVar12[0x1d] = 0x80;
    FUN_800a6e50(*param4_00,(int)*param5_00,2);
    *param5_00 = (void *)((int)*param5_00 + 0x40);
    *param4_00 = (int)(puVar12 + 0x20);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19F_func07
    dll_23E_func07
    dll_2E0_func07
   
   Library: KioskDefault 0 0 */

void laser23E_free(ObjInstance *this,int param2) { //80280564
  Texture **ppTVar1;
  
  ppTVar1 = (Texture **)this->state;
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_8039a050);
  DAT_8039a050 = (LoadedDll *)0x0;
  if (*ppTVar1 != (Texture *)0x0) {
    texFreeTexture(*ppTVar1);
    *ppTVar1 = (Texture *)0x0;
  }
  return;
}


undefined4 laser23E_func08(ObjInstance *this) { //802805D4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int laser23E_getExtraSize(void) { //802805DC
  return 0x4c;
}

