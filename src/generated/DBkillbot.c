
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void killbot_initialise(undefined4 param) { //8029EB4C
  return;
}


/* @description Called when DLL is unloaded */

void killbot_release(void) { //8029EB50
  return;
}


/* Library Function - Single Match
    killbot_func03
   
   Library: KioskDefault 0 0 */

void killbot_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //8029EB54
  short sVar1;
  uint uVar2;
  undefined uVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  *(int *)(puVar4 + 0x1c4) = *(char *)((int)&objDef[1].objType + 1) * 3;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 5;
  }
  puVar4[0x1cf] = uVar3;
  *(undefined4 *)(puVar4 + 0x1c8) = 10;
  puVar4[0x1d0] = 0;
  *(float *)(puVar4 + 0x1ac) = 0.2;
  return;
}


/* Library Function - Single Match
    killbot_func04
   
   Library: KioskDefault 0 0 */

void killbot_update(ObjInstance *this) { //8029EBD0
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  bool bVar5;
  char cVar6;
  ObjDef *pOVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  undefined *puVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  Mtx44 MStack_d0;
  double local_90;
  double local_88;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  longlong local_70;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_30();
  puVar12 = this->state;
  pOVar7 = this->def;
  iVar9 = -1;
  local_dc = 1;
  local_d8 = 0;
  dVar15 = 1.0;
  diPrintf((char *)&PTR_DAT_80321ff0,(uint)(byte)puVar12[0x1cf],*(undefined4 *)(puVar12 + 0x1b0));
  bVar1 = puVar12[0x1cf];
  if (bVar1 == 3) {
    *(uint *)(puVar12 + 0x1c0) = *(int *)(puVar12 + 0x1c0) - (uint)framesThisStep;
    if (*(int *)(puVar12 + 0x1c0) < 0) {
      puVar12[0x1ce] = (char)*(undefined4 *)(puVar12 + 0x1b8);
      puVar12[0x1cf] = 4;
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      uStack_44 = *(uint *)(puVar12 + 0x1bc) ^ 0x80000000;
      local_48 = 0x43300000;
      dVar15 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_44)
                                                            - 4503601774854144.0) * 3.141593) /
                                                   32767.0));
      uStack_4c = *(int *)(puVar12 + 0x1b0) + 5U ^ 0x80000000;
      local_50 = 0x43300000;
      iVar10 = (int)((float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) *
                    (float)(dVar15 * 600.0));
      local_58 = (longlong)iVar10;
      uStack_5c = (int)(short)iVar10 ^ 0x80000000;
      local_60 = 0x43300000;
      dVar16 = (double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0);
      uStack_64 = (int)(this->pos).rotation.x ^ 0x80000000;
      local_68 = 0x43300000;
      iVar10 = (int)((double)(float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) +
                    dVar16);
      local_70 = (longlong)iVar10;
      (this->pos).rotation.x = (short)iVar10;
      uStack_74 = 3U - *(int *)(puVar12 + 0x1b0) ^ 0x80000000;
      local_78 = 0x43300000;
      dVar15 = dVar16;
      if (dVar16 < 0.0) {
        dVar15 = -dVar16;
      }
      uStack_7c = *(int *)(puVar12 + 0x1b0) + 1U ^ 0x80000000;
      local_80 = 0x43300000;
      dVar15 = (double)((float)((double)CONCAT44(0x43300000,uStack_74) - 4503601774854144.0) * 0.1 +
                       (float)(dVar15 / (double)((float)((double)CONCAT44(0x43300000,uStack_7c) -
                                                        4503601774854144.0) * 1000.0)) * 0.7 + 0.1);
      local_88 = (double)CONCAT44(0x43300000,*(int *)(puVar12 + 0x1bc) << 3 ^ 0x80000000);
      dVar13 = (double)mathFn_80294204((double)(((float)(local_88 - 4503601774854144.0) * 3.141593)
                                               / 32767.0));
      dVar14 = dVar16;
      if (dVar16 < 0.0) {
        dVar14 = -dVar16;
      }
      iVar10 = (int)((1.0 - (float)(dVar14 / 1000.0)) * (float)(dVar13 * 5000.0));
      local_90 = (double)(longlong)iVar10;
      (this->pos).rotation.y = (short)iVar10;
      mtxSetFromObjPos(&MStack_d0,&this->pos);
      psVar11 = (short *)(puVar12 + 0x2c);
      for (iVar10 = 0; iVar10 < *(int *)(puVar12 + 0x1b4); iVar10 = iVar10 + 1) {
        if ((*(int *)(puVar12 + iVar10 * 4) != 0) &&
           ((*(ushort *)(*(int *)(puVar12 + iVar10 * 4) + 0xb0) & 0x1000) == 0)) {
          iVar4 = (**(code **)(**(int **)(*(int *)(puVar12 + iVar10 * 4) + 0x68) + 0x24))
                            (*(undefined4 *)(puVar12 + iVar10 * 4));
          if (iVar4 == 0) {
            psVar8 = *(short **)(puVar12 + iVar10 * 4);
            multVectorByMatrix((double)*(float *)(psVar11 + 6),(double)*(float *)(psVar11 + 8),
                               (double)*(float *)(psVar11 + 10),&MStack_d0,(float *)(psVar8 + 6),
                               (float *)(psVar8 + 8),(float *)(psVar8 + 10));
            dVar14 = dVar16;
            if (dVar16 < 0.0) {
              dVar14 = -dVar16;
            }
            local_90 = (double)CONCAT44(0x43300000,*(int *)(puVar12 + 0x1b0) * 0x300 ^ 0x80000000);
            if ((double)(float)(local_90 - 4503601774854144.0) < dVar14) {
              diPrintf(&DAT_803980c0);
              local_90 = (double)CONCAT44(0x43300000,(int)*psVar11 ^ 0x80000000);
              iVar4 = (int)((double)(float)(local_90 - 4503601774854144.0) + dVar16);
              local_88 = (double)(longlong)iVar4;
              sVar2 = (short)iVar4;
              sVar2 = sVar2 - (short)((int)sVar2 / (*(int *)(puVar12 + 0x1b0) * 0x4b60)) *
                              (short)(*(int *)(puVar12 + 0x1b0) * 0x4b60);
              sVar3 = *psVar11 -
                      (short)((int)*psVar11 / (*(int *)(puVar12 + 0x1b0) * 0x4b60)) *
                      (short)(*(int *)(puVar12 + 0x1b0) * 0x4b60);
              if (((0x1554 < sVar2) && (*psVar11 <= sVar3)) ||
                 ((sVar2 < 0x1556 && (sVar3 <= *psVar11)))) {
                iVar9 = iVar10;
              }
            }
            *psVar8 = *psVar11 + (this->pos).rotation.x;
          }
          else {
            *(undefined4 *)(puVar12 + iVar10 * 4) = 0;
            *(int *)(puVar12 + 0x1b0) = *(int *)(puVar12 + 0x1b0) + -1;
            *(int *)(puVar12 + 0x1c4) = *(int *)(puVar12 + 0x1c4) + -10;
            if (*(int *)(puVar12 + 0x1b0) < 1) {
              puVar12[0x1cf] = 5;
            }
          }
        }
        psVar11 = psVar11 + 0xc;
      }
      if ((iVar9 != -1) &&
         (iVar10 = (**(code **)(**(int **)(*(int *)(puVar12 + iVar9 * 4) + 0x68) + 0x20))
                             (*(undefined4 *)(puVar12 + iVar9 * 4)), iVar10 != 0)) {
        *(undefined4 *)(puVar12 + iVar9 * 4) = 0;
        *(int *)(puVar12 + 0x1b0) = *(int *)(puVar12 + 0x1b0) + -1;
        *(int *)(puVar12 + 0x1c4) = *(int *)(puVar12 + 0x1c4) + -10;
        if (*(int *)(puVar12 + 0x1b0) < 1) {
          puVar12[0x1cf] = 5;
        }
      }
      bVar5 = FUN_80068b20((int)this,0x40);
      if (bVar5) {
        FUN_800689dc((double)((float)(dVar16 / 1000.0) + 1.0),(int)this,0x40,0x7f);
      }
      else {
        audioTryStartSfx((int *)this,0x40,0x67,0x7f,"DBKillbot.c",0xe4);
      }
    }
    else if (bVar1 == 0) {
      if (((true) &&
          (Object_playerGetObject(0x2b,&local_d4), sVar3._0_1_ = pOVar7[1].loadFlags,
          sVar3._1_1_ = pOVar7[1].mapStates2, local_d4 == sVar3)) && (local_d4 != 0)) {
        FUN_8029f3d4((short *)this);
        puVar12[0x1cf] = 1;
        *(short *)(puVar12 + 0x1cc) = (this->pos).rotation.y >> 3;
                    /* {@symbol 80128bb8} */
        cVar6 = (**(code **)(*(int *)pDll_RomCurve + 0x8c))
                          (0x4072c00000000000,puVar12 + 0xa4,this,&local_dc,1);
        if (cVar6 == '\0') {
          puVar12[0x1d0] = puVar12[0x1d0] | 1;
        }
      }
    }
    else {
      *(float *)(puVar12 + 0x1ac) = 1.0;
      FUN_8029f52c(this,puVar12 + 0x14,(int *)(puVar12 + 0x1b8));
      *(undefined4 *)(puVar12 + 0x1c0) = 600;
      puVar12[0x1cf] = 3;
    }
  }
  else if (bVar1 == 5) {
    puVar12[0x1d0] = puVar12[0x1d0] & 0xfe;
    objFreeFn_80083b54(this);
    sVar2._0_1_ = pOVar7[1].bound;
    sVar2._1_1_ = pOVar7[1].cullDist;
    mainSetBits((int)sVar2,1);
    FUN_80068a9c((uint)this,0x40);
  }
  else if (bVar1 < 5) {
    printf(" Fireing ");
    iVar9 = randInt(0,4);
    if (iVar9 == 0) {
      FUN_8029f588(this,(int)(puVar12 + 0x14),*(int *)(puVar12 + 0x1b8));
      cVar6 = puVar12[0x1ce];
      puVar12[0x1ce] = cVar6 + -1;
      if ((char)(cVar6 + -1) == '\0') {
        puVar12[0x1cf] = 3;
        *(undefined4 *)(puVar12 + 0x1c0) = 600;
      }
    }
  }
  if ((puVar12[0x1d0] & 1) != 0) {
    iVar9 = FUN_8006c2c8((double)*(float *)(puVar12 + 0x1ac),(float *)(puVar12 + 0xa4));
                    /* {@symbol 801290d4} */
    if (((iVar9 != 0) || (*(int *)(puVar12 + 0xb4) != 0)) &&
       (cVar6 = (**(code **)(*(int *)pDll_RomCurve + 0x90))(puVar12 + 0xa4), cVar6 != '\0')) {
      puVar12[0x1d0] = puVar12[0x1d0] & 0xfe;
    }
    (this->pos).pos.x = *(float *)(puVar12 + 0x10c);
    (this->pos).pos.y = *(float *)(puVar12 + 0x110);
    (this->pos).pos.z = *(float *)(puVar12 + 0x114);
  }
  local_90 = (double)CONCAT44(0x43300000,*(uint *)(puVar12 + 0x1c4) ^ 0x80000000);
  iVar9 = (int)(dVar15 * (double)((float)(local_90 - 4503601774854144.0) * timeDelta));
  local_88 = (double)(longlong)iVar9;
  *(int *)(puVar12 + 0x1bc) = *(int *)(puVar12 + 0x1bc) + (int)(short)iVar9;
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    killbot_func05
   
   Library: KioskDefault 0 0 */

void killbot_hitDetect(ObjInstance *this) { //8029F334
  short sVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  if (((1 < (byte)puVar3[0x1cf]) &&
      (iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0), iVar2 == 0xe)) &&
     (*(int *)(puVar3 + 0x1c8) = *(int *)(puVar3 + 0x1c8) + -1, *(int *)(puVar3 + 0x1c8) < 1)) {
    sVar1._0_1_ = this->def[1].bound;
    sVar1._1_1_ = this->def[1].cullDist;
    mainSetBits((int)sVar1,1);
    puVar3[0x1cf] = 5;
  }
  return;
}


/* @description Override render */

void killbot_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //8029F3BC
  return;
}


/* @description Free object instance */

void killbot_free(ObjInstance *this,int param2) { //8029F3C0
  return;
}


undefined4 killbot_func08(ObjInstance *this) { //8029F3C4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int killbot_getExtraSize(void) { //8029F3CC
  return 0x1d4;
}

