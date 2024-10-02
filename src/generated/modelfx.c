
/* Library Function - Single Match
    dll_1D_func00
   
   Library: KioskDefault 0 0 */

void modelfx_initialise(undefined4 param) { //800E9FCC
  int iVar1;
  int iVar2;
  
  PTR_Texture_8039912c = (undefined *)textureLoadAsset(0x16b);
  PTR_Texture_80399130 = (undefined *)textureLoadAsset(0x201);
  PTR_DAT_80385cc0 = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  PTR_DAT_80385cc4 = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  PTR_DAT_80385cc8 = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  PTR_DAT_80385ccc = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  PTR_DAT_80385cd0 = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  PTR_DAT_80385cd4 = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  PTR_DAT_80385cd8 = (undefined *)mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
  for (iVar1 = 0; iVar1 < 7; iVar1 = iVar1 + 1) {
    for (iVar2 = 0; iVar2 < 0x14; iVar2 = iVar2 + 1) {
      *(undefined2 *)((&PTR_DAT_80385cc0)[iVar1] + iVar2 * 0x10) = (&DAT_802f5cb0)[iVar2 * 8];
      *(undefined2 *)((&PTR_DAT_80385cc0)[iVar1] + iVar2 * 0x10 + 2) = (&DAT_802f5cb2)[iVar2 * 8];
      *(undefined2 *)((&PTR_DAT_80385cc0)[iVar1] + iVar2 * 0x10 + 4) = (&DAT_802f5cb4)[iVar2 * 8];
      *(undefined2 *)((&PTR_DAT_80385cc0)[iVar1] + iVar2 * 0x10 + 8) = (&DAT_802f5cb8)[iVar2 * 8];
      *(undefined2 *)((&PTR_DAT_80385cc0)[iVar1] + iVar2 * 0x10 + 10) = (&DAT_802f5cba)[iVar2 * 8];
      (&PTR_DAT_80385cc0)[iVar1][iVar2 * 0x10 + 0xc] = (&DAT_802f5cbc)[iVar2 * 0x10];
      (&PTR_DAT_80385cc0)[iVar1][iVar2 * 0x10 + 0xd] = (&DAT_802f5cbd)[iVar2 * 0x10];
      (&PTR_DAT_80385cc0)[iVar1][iVar2 * 0x10 + 0xe] = (&DAT_802f5cbe)[iVar2 * 0x10];
      (&PTR_DAT_80385cc0)[iVar1][iVar2 * 0x10 + 0xf] = 0xff;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1D_func01
   
   Library: KioskDefault 0 0 */

void modelfx_release(void) { //800EA1E0
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 7; iVar1 = iVar1 + 1) {
    if ((&PTR_DAT_80385cc0)[iVar1] != (undefined *)0x0) {
      mm_free((&PTR_DAT_80385cc0)[iVar1]);
    }
    (&PTR_DAT_80385cc0)[iVar1] = (undefined *)0x0;
  }
  if (PTR_Texture_8039912c != (undefined *)0x0) {
    texFreeTexture((Texture *)PTR_Texture_8039912c);
  }
  if (PTR_Texture_80399130 != (undefined *)0x0) {
    texFreeTexture((Texture *)PTR_Texture_80399130);
  }
  return;
}


void modelfx_func03(void) { //800EA270
  return;
}


void modelfx_func04(void) { //800EA274
  return;
}


/* Library Function - Single Match
    dll_1D_func05
   
   Library: KioskDefault 0 0 */

void modelfx_func05(int param1,undefined4 param2,undefined4 param3) { //800EA278
  int iVar1;
  int *piVar2;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  float local_24;
  vec3f local_20;
  
  piVar2 = *(int **)(*(int *)(param1 + 0x7c) + *(char *)(param1 + 0xad) * 4);
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(*piVar2 + 0xb7); iVar1 = iVar1 + 1) {
    local_20.x = 1.0;
    local_20.y = 0.0;
    local_20.z = 0.0;
    local_24 = 1.0;
    local_28 = 0;
    local_2a = 0;
    local_2c = 0;
    MTXMultVec((Mtx43 *)(piVar2[(*(ushort *)(piVar2 + 6) & 1) + 3] + iVar1 * 0x100),&local_20,
               &local_20);
    local_20.y = local_20.y - *(float *)(param1 + 0x10);
    local_20.x = (local_20.x - *(float *)(param1 + 0xc)) + playerMapOffsetX;
    local_20.z = (local_20.z - *(float *)(param1 + 0x14)) + playerMapOffsetZ;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(param1,param2,&local_2c,0,0xffffffff,param3);
  }
  return;
}


void modelfx_func06(void) { //800EA3D4
  return;
}


/* Library Function - Single Match
    dll_1D_func07
   
   Library: KioskDefault 0 0 */

void modelfx_func07(Gfx *param1,int *param2,int *param3) { //800EA3D8
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int *piVar7;
  Mtx44 *m;
  int iVar8;
  int iVar9;
  short sVar10;
  short sVar11;
  float local_60;
  ObjPos local_58;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
  uVar6 = mainGetBit(0x468);
  if (uVar6 != 0) {
    mainSetBits(0x468,0);
    DAT_80399144 = 0xf;
    audioTryStartSfx(param3,1,0x1f8,0x7f,"modelfx.c",0x20b);
  }
  piVar7 = *(int **)(param3[0x1f] + *(char *)((int)param3 + 0xad) * 4);
  if (6 < DAT_8039913c) {
    DAT_8039913c = 0;
  }
  if ((int)(*(byte *)(*piVar7 + 0xb7) - 1) < DAT_80399138) {
    DAT_80399138 = 0;
  }
  DAT_80399140 = DAT_80399140 + (uint)framesThisStep;
  if (0x1f < DAT_80399140) {
    DAT_80399140 = DAT_80399140 + -0x1f;
  }
  DAT_80399134 = FLOAT_80396fa0 * timeDelta + DAT_80399134;
  if (DAT_80399134 <= 500.0) {
    if (DAT_80399134 < -500.0) {
      FLOAT_80396fa0 = FLOAT_80396fa0 * -1.0;
      DAT_80399134 = -500.0;
      audioTryStartSfx(param3,1,0x214,0x7f,"modelfx.c",0x246);
    }
  }
  else {
    FLOAT_80396fa0 = FLOAT_80396fa0 * -1.0;
    DAT_80399134 = 500.0;
    audioTryStartSfx(param3,1,0x214,0x7f,"modelfx.c",0x242);
  }
  for (iVar9 = 0; iVar9 < 7; iVar9 = iVar9 + 1) {
    if (iVar9 != 5) {
      DAT_8039913c = (short)iVar9;
      iVar8 = 0;
      for (sVar11 = 0; sVar11 < 5; sVar11 = sVar11 + 1) {
        local_58.pos.x = 0.0;
        local_58.pos.y = 0.0;
        local_58.pos.z = 0.0;
        local_58.scale = 1.0;
        local_58.rotation.z = 0;
        local_58.rotation.y = 0;
        local_58.rotation.x = 0;
        m = (Mtx44 *)(piVar7[(*(ushort *)(piVar7 + 6) & 1) + 3] +
                     (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11) *
                     0x100);
        fVar4 = m->m41 + playerMapOffsetX;
        fVar5 = m->m43 + playerMapOffsetZ;
        fVar2 = (float)param3[3];
        local_60 = m->m42 - (float)param3[4];
        fVar3 = (float)param3[5];
        if ((*(char *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11) == '\x1d') ||
           (*(char *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11) == '\x1d')) {
          local_60 = local_60 + 8.0;
        }
        local_60 = local_60 * 20.02;
        multVectorByMatrix(0.0,0.0,0.0,m,&local_58.pos.x,&local_58.pos.y,&local_58.pos.z);
        for (sVar10 = 0; sVar10 < 4; sVar10 = sVar10 + 1) {
          if (*(char *)((int)&PTR_DAT_802f6090 +
                       (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)) ==
              '\0') {
            local_58.pos.x =
                 (float)(&DAT_802f5b90)[sVar10 * 3] *
                 *(float *)(&DAT_802f60d8 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
            local_58.pos.y =
                 (float)(&DAT_802f5b90)[sVar10 * 3 + 1] *
                 *(float *)(&DAT_802f60d8 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
            local_58.pos.z =
                 (float)(&DAT_802f5b90)[sVar10 * 3 + 2] *
                 *(float *)(&DAT_802f6164 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
          }
          else if (*(char *)((int)&PTR_DAT_802f6090 +
                            (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                            ) == '\x01') {
            local_58.pos.x =
                 (float)(&PTR_DAT_802f5b00)[sVar10 * 3] *
                 *(float *)(&DAT_802f60d8 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
            local_58.pos.y =
                 (float)(&PTR_DAT_802f5b00)[sVar10 * 3 + 1] *
                 *(float *)(&DAT_802f60d8 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
            local_58.pos.z =
                 (float)(&PTR_DAT_802f5b00)[sVar10 * 3 + 2] *
                 *(float *)(&DAT_802f6164 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
          }
          else if (*(char *)((int)&PTR_DAT_802f6090 +
                            (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                            ) == '\x02') {
            local_58.pos.x =
                 (float)(&DAT_802f5c20)[sVar10 * 3] *
                 *(float *)(&DAT_802f60d8 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
            local_58.pos.y =
                 (float)(&DAT_802f5c20)[sVar10 * 3 + 1] *
                 *(float *)(&DAT_802f60d8 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
            local_58.pos.z =
                 (float)(&DAT_802f5c20)[sVar10 * 3 + 2] *
                 *(float *)(&DAT_802f6164 +
                           (uint)*(byte *)((int)&PTR_DAT_802f60b4 + DAT_8039913c * 5 + (int)sVar11)
                           * 4);
          }
          multVectorByMatrix((double)local_58.pos.x,(double)local_58.pos.y,(double)local_58.pos.z,m,
                             &local_58.pos.x,&local_58.pos.y,&local_58.pos.z);
          local_58.pos.x = local_58.pos.x + playerMapOffsetX;
          local_58.pos.z = local_58.pos.z + playerMapOffsetZ;
          iVar1 = (int)((fVar4 - fVar2) * 20.02 + (local_58.pos.x - (float)param3[3]));
          local_30 = (longlong)iVar1;
          *(short *)((&PTR_DAT_80385cc0)[iVar9] + (sVar10 + iVar8) * 0x10) = (short)iVar1;
          iVar1 = (int)(local_60 + (local_58.pos.y - (float)param3[4]));
          local_38 = (longlong)iVar1;
          *(short *)((&PTR_DAT_80385cc0)[iVar9] + (sVar10 + iVar8) * 0x10 + 2) = (short)iVar1;
          iVar1 = (int)((fVar5 - fVar3) * 20.02 + (local_58.pos.z - (float)param3[5]));
          local_40 = (longlong)iVar1;
          *(short *)((&PTR_DAT_80385cc0)[iVar9] + (sVar10 + iVar8) * 0x10 + 4) = (short)iVar1;
          (&PTR_DAT_80385cc0)[iVar9][(sVar10 + iVar8) * 0x10 + 0xf] = 0x9b;
          *(short *)((&PTR_DAT_80385cc0)[iVar9] + (sVar10 + iVar8) * 0x10 + 10) =
               (&DAT_802f5cba)[(sVar10 + iVar8) * 8] - (short)(DAT_80399140 << 2);
        }
        iVar8 = iVar8 + 4;
      }
    }
  }
  local_58.pos.x = (float)param3[3];
  local_58.pos.y = (float)param3[4];
  local_58.pos.z = (float)param3[5];
  local_58.scale = 0.0495;
  RSP_setTevColor2(param1,0xff,0xff,0xff,0xff);
  if (DAT_80399144 == 0) {
    FUN_800a4fa4((Gfx **)param1,(undefined4 *)PTR_Texture_8039912c,(undefined4 *)0x0,0,0,0,0);
  }
  else {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(param3,0x28c,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(param3,0x28c,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(param3,0x28c,0,1,0xffffffff,0);
    iVar9 = randInt(0,1);
    if (iVar9 == 0) {
      FUN_800a4fa4((Gfx **)param1,(undefined4 *)PTR_Texture_80399130,(undefined4 *)0x0,0,0,0,0);
    }
    else {
      FUN_800a4fa4((Gfx **)param1,(undefined4 *)PTR_Texture_8039912c,(undefined4 *)0x0,0,0,0,0);
    }
    DAT_80399144 = DAT_80399144 - (ushort)framesThisStep;
    if (DAT_80399144 < 0) {
      DAT_80399144 = 0;
    }
  }
  FUN_8006a754(1.0,&param1->cmd,param2,&local_58,(Mtx44 *)0x0);
  GXSetCullMode(GX_CULL_NONE);
  RSP_setTevColor1(param1,0xff,0xff,0xff,0xff);
  FUN_800c41d0();
  FUN_800c428c();
  FUN_800c4610();
  gxSetTevFn_800c420c();
  gxResetBlendFn_800c4ce8();
  for (iVar9 = 0; iVar9 < 7; iVar9 = iVar9 + 1) {
    FUN_800a6e50((int)(&PTR_DAT_80385cc0)[iVar9],-0x7fd0a210,0x20);
  }
  DAT_80399128 = 1 - DAT_80399128;
  return;
}


void modelfx_func08(void) { //800EAD40
  return;
}

