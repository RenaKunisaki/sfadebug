
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcloudcage_initialise(undefined4 param) { //802B6DAC
  return;
}


/* @description Called when DLL is unloaded */

void DRcloudcage_release(void) { //802B6DB0
  return;
}


/* Library Function - Single Match
    dll_2B5_func03
   
   Library: KioskDefault 0 0 */

void DRcloudcage_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802B6DB4
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  FUN_80088d3c((int)this);
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar4 = mainGetBit((int)sVar1);
  if (uVar4 == 0) {
    mainSetBits(0x7aa,5);
  }
  else {
    puVar5[0x10] = puVar5[0x10] & 0x7f | 0x80;
  }
  printf((char *)&PTR_DAT_80323bf8);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802b782c;
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  *(float *)(puVar5 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0);
  sVar3._0_1_ = objDef[1].allocatedSize;
  sVar3._1_1_ = objDef[1].mapStates1;
  *(float *)(puVar5 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0) / 10.0;
  *(undefined4 *)(puVar5 + 4) = 0;
  return;
}


/* Library Function - Single Match
    dll_2B5_func04
   
   Library: KioskDefault 0 0 */

void DRcloudcage_update(ObjInstance *this) { //802B6EA4
  float fVar1;
  float fVar2;
  short sVar3;
  ushort param3;
  ObjDef *def;
  ObjInstance *pOVar4;
  uint uVar5;
  ObjInstance **ppOVar6;
  uint uVar7;
  bool bVar8;
  ObjDef *pOVar9;
  short sVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  ObjInstance *pOVar14;
  ObjInstance **ppOVar15;
  double dVar16;
  double dVar17;
  float local_6c;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  
  ppOVar15 = (ObjInstance **)this->state;
  pOVar9 = this->def;
  local_6c = 300.0;
  if (*ppOVar15 == (ObjInstance *)0x0) {
    def = objAlloc(0x20,DRPerch);
    def->loadFlags = isManualLoad;
    def->mapStates2 = 1;
    (def->pos).x = (this->pos).pos.x;
    (def->pos).y = (this->pos).pos.y;
    (def->pos).z = (this->pos).pos.z;
    pOVar4 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
    (pOVar4->pos).flags = (pOVar4->pos).flags | Invisible;
    pOVar4->parent = this;
    *ppOVar15 = pOVar4;
  }
  if (-1 < *(char *)(ppOVar15 + 4)) {
    sVar10._0_1_ = pOVar9[1].bound;
    sVar10._1_1_ = pOVar9[1].cullDist;
    uVar5 = mainGetBit((int)sVar10);
    if (uVar5 == 0) {
      ppOVar6 = Object_playerGetObject(0x19,&local_68);
      if (1 < local_68) {
        if (((*ppOVar6)->pos).pos.y - (this->pos).pos.y < 0.0) {
          fVar1 = -(((*ppOVar6)->pos).pos.y - (this->pos).pos.y);
        }
        else {
          fVar1 = ((*ppOVar6)->pos).pos.y - (this->pos).pos.y;
        }
        if (fVar1 <= 10.0) {
          pOVar14 = ppOVar6[1];
          pOVar4 = *ppOVar6;
        }
        else {
          pOVar14 = *ppOVar6;
          pOVar4 = ppOVar6[1];
        }
        local_64 = (pOVar14->pos).pos.x - (this->pos).pos.x;
        local_60 = (pOVar14->pos).pos.y - (this->pos).pos.y;
        local_5c = (pOVar14->pos).pos.z - (this->pos).pos.z;
        dVar16 = sqrt((double)(local_5c * local_5c + local_64 * local_64 + local_60 * local_60));
        if (dVar16 != 0.0) {
          (this->vel).x = (this->vel).x * 0.97;
          uVar5 = getAngle();
          sVar11 = (short)uVar5;
          uStack_44 = (int)sVar11 ^ 0x80000000;
          local_48 = 0x43300000;
          dVar17 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                  uStack_44) -
                                                                4503601774854144.0) * 3.141593) /
                                                       32767.0));
          (this->vel).x = (float)((double)(float)ppOVar15[3] * dVar17) * 0.7 + (this->vel).x;
          (this->vel).z = (this->vel).z * 0.97;
          uVar7 = getAngle();
          sVar10 = (short)uVar7;
          uStack_4c = (int)sVar10 ^ 0x80000000;
          local_50 = 0x43300000;
          dVar17 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                  uStack_4c) -
                                                                4503601774854144.0) * 3.141593) /
                                                       32767.0));
          (this->vel).z = (float)((double)(float)ppOVar15[3] * dVar17) * 0.7 + (this->vel).z;
          (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
          (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
          local_64 = ((this->pos).pos.x - (pOVar14->pos).pos.x) *
                     (float)((double)(float)ppOVar15[2] / dVar16);
          local_60 = ((this->pos).pos.y - (pOVar14->pos).pos.y) *
                     (float)((double)(float)ppOVar15[2] / dVar16);
          local_5c = ((this->pos).pos.z - (pOVar14->pos).pos.z) *
                     (float)((double)(float)ppOVar15[2] / dVar16);
          (this->pos).pos.x = (pOVar14->pos).pos.x + local_64;
          (this->pos).pos.y = (pOVar14->pos).pos.y + local_60;
          (this->pos).pos.z = (pOVar14->pos).pos.z + local_5c;
          (pOVar4->pos).pos.x = (this->pos).pos.x;
          (pOVar4->pos).pos.y = (this->pos).pos.y;
          (pOVar4->pos).pos.z = (this->pos).pos.z;
          (this->pos).rotation.z = -((sVar11 >> 1) + (ushort)(sVar11 < 0 && (uVar5 & 1) != 0));
          (this->pos).rotation.y = (sVar10 >> 1) + (ushort)(sVar10 < 0 && (uVar7 & 1) != 0);
          if ((this->pos).rotation.z < -0xaaa) {
            sVar3 = -0xaaa;
          }
          else if ((this->pos).rotation.z < 0xaab) {
            sVar3 = (this->pos).rotation.z;
          }
          else {
            sVar3 = 0xaaa;
          }
          (this->pos).rotation.z = sVar3;
          if ((this->pos).rotation.y < -0xaaa) {
            sVar3 = -0xaaa;
          }
          else if ((this->pos).rotation.y < 0xaab) {
            sVar3 = (this->pos).rotation.y;
          }
          else {
            sVar3 = 0xaaa;
          }
          (this->pos).rotation.y = sVar3;
          if ((this->vel).x < 0.0) {
            fVar1 = -(this->vel).x;
          }
          else {
            fVar1 = (this->vel).x;
          }
          if ((this->vel).z < 0.0) {
            fVar2 = -(this->vel).z;
          }
          else {
            fVar2 = (this->vel).z;
          }
          iVar13 = (int)((fVar1 + fVar2) * 30.0);
          local_58 = (longlong)iVar13;
          iVar12 = iVar13 << 2;
          if (iVar12 < 0x14) {
            iVar12 = 0x14;
          }
          else if (0x7f < iVar12) {
            iVar12 = 0x7f;
          }
          bVar8 = FUN_80068b20((int)this,1);
          if (!bVar8) {
            audioTryStartSfx((int *)this,1,0xef,(byte)iVar12,"DRcloudcage.c",0xe5);
          }
          iVar13 = 0x32 - iVar13;
          if (iVar13 < 1) {
            iVar13 = 1;
          }
          else if (0x32 < iVar13) {
            iVar13 = 0x32;
          }
          iVar13 = randInt(0,iVar13);
          if (iVar13 == 0) {
            iVar13 = randInt(0,1);
            if (iVar13 == 0) {
              param3 = 0x109;
            }
            else {
              param3 = 0x108;
            }
            audioTryStartSfx((int *)this,2,param3,0x7f,"DRcloudcage.c",0xed);
          }
          ppOVar15[1] = (ObjInstance *)0x0;
          if (*ppOVar15 != (ObjInstance *)0x0) {
            ((*ppOVar15)->pos).pos.x = (this->pos).pos.x;
            ((*ppOVar15)->pos).pos.y = (this->pos).pos.y;
            ((*ppOVar15)->pos).pos.z = (this->pos).pos.z;
            ((*ppOVar15)->pos).rotation.z = (short)((sVar11 * -0x78) / 100);
            ((*ppOVar15)->pos).rotation.y = (short)((sVar10 * 0x78) / 100);
            pOVar4 = getSeqObj(0xb,this,&local_6c);
            if ((pOVar4 != (ObjInstance *)0x0) && (pOVar4->romdefno == DR_CloudRun)) {
              pOVar4->parent = *ppOVar15;
              ppOVar15[1] = pOVar4;
              (pOVar4->pos).rotation.y = ((*ppOVar15)->pos).rotation.y;
              (pOVar4->pos).rotation.z = ((*ppOVar15)->pos).rotation.z;
              (*ppOVar15)->parent = this;
            }
            if ((ppOVar15[1] != (ObjInstance *)0x0) && ((ppOVar15[1]->flags_0xb0 & IsFreed) != 0)) {
              ppOVar15[1] = (ObjInstance *)0x0;
            }
          }
        }
      }
    }
    else {
      *(byte *)(ppOVar15 + 4) = *(byte *)(ppOVar15 + 4) & 0x7f | 0x80;
      pOVar4 = getSeqObj(0xb,this,&local_6c);
      if ((pOVar4 != (ObjInstance *)0x0) && (pOVar4->romdefno == DR_CloudRun)) {
        pOVar4->parent = (ObjInstance *)0x0;
        ppOVar15[1] = (ObjInstance *)0x0;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2B5_func05
   
   Library: KioskDefault 0 0 */

void DRcloudcage_hitDetect(ObjInstance *this) { //802B750C
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  ObjInstance *pOVar5;
  ObjDef *pOVar6;
  undefined *puVar7;
  int local_20;
  uint auStack_1c [2];
  
  pOVar6 = this->def;
  puVar7 = this->state;
  if (-1 < (char)puVar7[0x10]) {
    puVar7[0x10] = puVar7[0x10] & 0xbf;
    iVar4 = FUN_800883e4((int)this,&local_20,(int *)0x0,auStack_1c);
    if (iVar4 == 0x1a) {
      sVar3._0_1_ = pOVar6[1].bound;
      sVar3._1_1_ = pOVar6[1].cullDist;
      mainSetBits((int)sVar3,1);
      pOVar5 = Object_objGetMain();
      puVar7[0x10] = (pOVar5 == (ObjInstance *)0x0) << 6 | puVar7[0x10] & 0xbf;
      printf(" HIT HIT HIT HIT Hit by Booldy Side Kick ");
    }
    else if ((iVar4 == 0xe) || (iVar4 == 0x10)) {
      printf(" HIT BY PROJ ");
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x1f7,0x7f,"DRcloudcage.c",(int *)0x122
                         );
      fVar1 = *(float *)(local_20 + 0x28);
      fVar2 = *(float *)(local_20 + 0x2c);
      (this->vel).x = (this->vel).x + *(float *)(local_20 + 0x24) * 0.3;
      (this->vel).y = (this->vel).y + fVar1 * 0.3;
      (this->vel).z = (this->vel).z + fVar2 * 0.3;
      puVar7[0x10] = puVar7[0x10] & 0xbf | 0x40;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2B5_func06
   
   Library: KioskDefault 0 0 */

void DRcloudcage_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802B76B8
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  ObjInstance *obj;
  ObjInstance **ppOVar1;
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  ppOVar1 = (ObjInstance **)this->state;
  if (shouldRender) {
    objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
    if (*ppOVar1 != (ObjInstance *)0x0) {
      objRenderCurrentModel(*ppOVar1,param2_00,param3_00,param4_00,param5_00);
      obj = ppOVar1[1];
      if (obj != (ObjInstance *)0x0) {
        (obj->pos).rotation.y = ((*ppOVar1)->pos).rotation.y;
        (obj->pos).rotation.z = ((*ppOVar1)->pos).rotation.z;
        objGetAttachPointWorldPos
                  (*ppOVar1,0,&(obj->pos).pos.x,&(obj->pos).pos.y,&(obj->pos).pos.z,FALSE);
        objRenderCurrentModel(obj,param2_00,param3_00,param4_00,param5_00);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2B5_func07
   
   Library: KioskDefault 0 0 */

void DRcloudcage_free(ObjInstance *this,int param2) { //802B77A4
  ObjInstance **ppOVar1;
  
  ppOVar1 = (ObjInstance **)this->state;
  if ((*ppOVar1 != (ObjInstance *)0x0) && (param2 == 0)) {
    if (ppOVar1[1] != (ObjInstance *)0x0) {
      ppOVar1[1]->parent = (ObjInstance *)0x0;
    }
    (*ppOVar1)->parent = (ObjInstance *)0x0;
    Object_objFreeObject(*ppOVar1);
  }
  return;
}


undefined4 DRcloudcage_func08(ObjInstance *this) { //802B781C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRcloudcage_getExtraSize(void) { //802B7824
  return 0x14;
}


void DRcloudcage_setScale(ObjInstance *this,float scale) { //802B7964
  return;
}

