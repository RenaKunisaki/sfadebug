
/* Library Function - Single Match
    weaponE6_func00
   
   Library: KioskDefault 0 0 */

void weaponE6_initialise(undefined4 param) { //801C8FD8
  char cVar2;
  Texture *pTVar1;
  int iVar3;
  
                    /* {@symbol 8012d9a0} */
  cVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x74))();
  if (cVar2 == '\0') {
    DAT_80399d28 = (undefined2 *)&DAT_80397ba4;
  }
  else {
    DAT_80399d28 = &DAT_80397ba0;
  }
  if (DAT_80399d20 == 0) {
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      pTVar1 = textureLoad((int)(short)DAT_80399d28[iVar3]);
      (&DAT_80399d20)[iVar3] = (int)pTVar1;
    }
  }
  if (DAT_80399d2c == (DLL_func **)0x0) {
    DAT_80399d2c = DLL_setup(0x1002,1,FALSE);
  }
  if (DAT_80399d30 == (DLL_func **)0x0) {
    DAT_80399d30 = DLL_setup(0x1040,1,FALSE);
  }
  return;
}


/* Library Function - Single Match
    weaponE6_func01
   
   Library: KioskDefault 0 0 */

void weaponE6_release(void) { //801C90AC
  int iVar1;
  
  if (DAT_80399d20 != 0) {
    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
      texFreeTexture((Texture *)(&DAT_80399d20)[iVar1]);
      (&DAT_80399d20)[iVar1] = 0;
    }
  }
  if (DAT_80399d2c != (LoadedDll *)0x0) {
    DLL_free(DAT_80399d2c);
    DAT_80399d2c = (LoadedDll *)0x0;
  }
  if (DAT_80399d30 != (LoadedDll *)0x0) {
    DLL_free(DAT_80399d30);
    DAT_80399d30 = (LoadedDll *)0x0;
  }
  return;
}


/* Library Function - Single Match
    weaponE6_func03
   
   Library: KioskDefault 0 0 */

void weaponE6_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801C9148
  ObjDefEnum OVar1;
  void *pvVar2;
  ObjDef *def;
  ObjInstance *pOVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  
  piVar8 = (int *)this->state;
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field58_0xa1 = 0x29;
  }
  if (this->romdefno == staff) {
    piVar8[0x16] = (int)-1.0;
    *(undefined2 *)(piVar8 + 0x1b) = 0xffff;
    *(undefined2 *)((int)piVar8 + 0x7e) = 0x10;
    piVar8[0x17] = (int)1.0;
    piVar8[0x18] = (int)1.0;
    OVar1 = this->romdefno;
    if (OVar1 == staff) {
      *(undefined2 *)((int)piVar8 + 0x86) = 2;
      *(undefined2 *)((int)piVar8 + 0x76) = 0xff;
      *(undefined2 *)(piVar8 + 0x1e) = 0xff;
      *(undefined2 *)((int)piVar8 + 0x7a) = 0xff;
      iVar6 = 0x96;
      iVar4 = 0x96;
      DAT_80399d34 = 0;
    }
    else if (((short)OVar1 < 0x69) && (OVar1 == sword)) {
      *(undefined2 *)((int)piVar8 + 0x86) = 1;
      *(undefined2 *)((int)piVar8 + 0x76) = 0xff;
      *(undefined2 *)(piVar8 + 0x1e) = 0xff;
      *(undefined2 *)((int)piVar8 + 0x7a) = 0xff;
      iVar6 = 0x96;
      iVar4 = 0x96;
    }
    else {
      iVar6 = 0;
      iVar4 = 0;
    }
    if (iVar6 == 0) {
      piVar8[2] = 0;
    }
    else {
      pvVar2 = mmAlloc(iVar6 * 0x44 + iVar4 * 0x20,TEST_COL,"weapons1");
      piVar8[2] = (int)pvVar2;
      piVar8[3] = piVar8[2] + iVar4 * 0x10;
      *piVar8 = piVar8[3] + iVar4 * 0x10;
      piVar8[1] = *piVar8 + iVar6 * 0x10;
      piVar8[4] = piVar8[1] + iVar6 * 0x10;
      for (uVar7 = 0; (int)uVar7 < iVar4 << 1; uVar7 = uVar7 + 1) {
        iVar5 = piVar8[2];
        if ((uVar7 & 1) == 0) {
          *(undefined *)(iVar5 + uVar7 * 0x10 + 1) = 0;
          *(undefined *)(iVar5 + uVar7 * 0x10 + 2) = 2;
          *(undefined *)(iVar5 + uVar7 * 0x10 + 3) = 1;
        }
        else {
          *(undefined *)(iVar5 + uVar7 * 0x10 + 1) = 1;
          *(undefined *)(iVar5 + uVar7 * 0x10 + 2) = 2;
          *(undefined *)(iVar5 + uVar7 * 0x10 + 3) = 3;
        }
        *(undefined *)(iVar5 + uVar7 * 0x10) = 0x40;
      }
    }
    if (this->hitstate != (HitState *)0x0) {
      this->hitstate->field58_0xa1 = 0x29;
    }
    *(short *)(piVar8 + 0x1f) = (short)iVar6;
    bGroundQuakeActive = 0;
    def = objAlloc(0x20,staffEnd);
    def->loadFlags = isManualLoad;
    pOVar3 = objInstantiateCharacter(def,4,-1,-1,(ObjInstance *)0x0);
    piVar8[0x23] = (int)pOVar3;
  }
  return;
}


/* Library Function - Single Match
    weaponE6_func04
   
   Library: KioskDefault 0 0 */

void weaponE6_update(ObjInstance *this) { //801C93C0
  ObjInstance *pOVar1;
  Model *pMVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  pOVar1 = Object_objGetMain();
  if (*(ObjInstance **)(puVar5 + 0x8c) != (ObjInstance *)0x0) {
    pMVar2 = objGetModelInstance(*(ObjInstance **)(puVar5 + 0x8c));
    *(ushort *)&pMVar2->radi = *(ushort *)&pMVar2->radi & 0xfff7;
    if (this->romdefno == staff) {
      objRunAnimation((double)*(float *)(puVar5 + 0x14),(double)timeDelta,(int)this,(float *)0x0);
      iVar4 = (int)*(short *)(puVar5 + 0x72);
      while( true ) {
        if (iVar4 == *(short *)(puVar5 + 0x74)) break;
        iVar3 = iVar4 * 0x24 + 0x1c;
        *(short *)(*(int *)(puVar5 + 0x10) + iVar3) =
             (short)(int)-(timeDelta *
                           (float)((double)CONCAT44(0x43300000,
                                                    (int)*(short *)(puVar5 + 0x7e) ^ 0x80000000) -
                                  4503601774854144.0) -
                          (float)((double)CONCAT44(0x43300000,
                                                   (int)*(short *)(*(int *)(puVar5 + 0x10) + iVar3)
                                                   ^ 0x80000000) - 4503601774854144.0));
        iVar3 = (iVar4 + 1) * 0x24 + 0x1c;
        *(short *)(*(int *)(puVar5 + 0x10) + iVar3) =
             (short)(int)-(timeDelta *
                           (float)((double)CONCAT44(0x43300000,
                                                    (int)*(short *)(puVar5 + 0x7e) ^ 0x80000000) -
                                  4503601774854144.0) -
                          (float)((double)CONCAT44(0x43300000,
                                                   (int)*(short *)(*(int *)(puVar5 + 0x10) + iVar3)
                                                   ^ 0x80000000) - 4503601774854144.0));
        if (*(short *)(*(int *)(puVar5 + 0x10) + iVar4 * 0x24 + 0x1c) < 0) {
          *(undefined2 *)(*(int *)(puVar5 + 0x10) + iVar4 * 0x24 + 0x1c) = 0;
        }
        if (*(short *)(*(int *)(puVar5 + 0x10) + (iVar4 + 1) * 0x24 + 0x1c) < 0) {
          *(undefined2 *)(*(int *)(puVar5 + 0x10) + (iVar4 + 1) * 0x24 + 0x1c) = 0;
        }
        iVar3 = iVar4 * 0x24 + 0x18;
        *(float *)(*(int *)(puVar5 + 0x10) + iVar3) =
             *(float *)(*(int *)(puVar5 + 0x10) + iVar3) - timeDelta;
        if (*(float *)(*(int *)(puVar5 + 0x10) + iVar4 * 0x24 + 0x18) < 0.0) {
          *(short *)(puVar5 + 0x84) = *(short *)(puVar5 + 0x84) + -2;
          if (*(short *)(puVar5 + 0x84) < 0) {
            *(undefined2 *)(puVar5 + 0x84) = 0;
          }
          *(short *)(puVar5 + 0x72) = *(short *)(puVar5 + 0x72) + 2;
          if (*(short *)(puVar5 + 0x7c) <= *(short *)(puVar5 + 0x72)) {
            *(undefined2 *)(puVar5 + 0x72) = 0;
          }
        }
        iVar4 = iVar4 + 2;
        if (*(short *)(puVar5 + 0x7c) <= iVar4) {
          iVar4 = 0;
        }
      }
      if (((puVar5[0x80] & 1) == 0) && (*(short *)(puVar5 + 0x84) == 0)) {
        *(undefined2 *)(puVar5 + 0x6c) = 0xffff;
        *(float *)(puVar5 + 0x58) = -1.0;
        *(undefined2 *)(puVar5 + 0x7e) = 0x10;
      }
      iVar4 = FUN_801a7998((int)pOVar1);
      if (iVar4 == 0x2d) {
        puVar5[0x91] = 1;
      }
      else {
        puVar5[0x91] = 0;
      }
      if (bGroundQuakeActive != '\0') {
        FUN_801cb01c();
      }
    }
  }
  return;
}


/* @description Override hit detection */

void weaponE6_hitDetect(ObjInstance *this) { //801C967C
  return;
}


/* @description Override render */

void weaponE6_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801C9680
  return;
}


/* Library Function - Single Match
    weaponE6_func07
   
   Library: KioskDefault 0 0 */

void weaponE6_free(ObjInstance *this,int param2) { //801C9684
  undefined *puVar1;
  
  puVar1 = this->state;
  if (this->romdefno == staff) {
    if (*(int *)(puVar1 + 0x8c) != 0) {
      Object_objFreeObject(*(ObjInstance **)(puVar1 + 0x8c));
    }
    if (*(int *)(puVar1 + 8) != 0) {
      mm_free(*(void **)(puVar1 + 8));
    }
                    /* {@symbol 800dc2d8} */
    (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  }
  return;
}


undefined4 weaponE6_func08(ObjInstance *this) { //801C96FC
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int weaponE6_getExtraSize(void) { //801C9704
  return 0x94;
}


/* Library Function - Single Match
    weaponE6_func0A
   
   Library: KioskDefault 0 0 */

void weaponE6_setScale(ObjInstance *this,float scale) { //801C970C
  undefined *puVar1;
  undefined4 in_register_00004008;
  
  puVar1 = this->state;
  if (this->romdefno == staff) {
    if (this->animTimer == 0.0) {
      audioTryStartSfx((int *)this,1,0x21e,0x7f,"weapons.c",0x231);
    }
    if (this->animId != 0) {
      Object_ObjAnimSetMove(0.0,this,0,0);
    }
    *(float *)(puVar1 + 0x14) = (float)(double)CONCAT44(in_register_00004008,scale);
  }
  return;
}


/* Library Function - Single Match
    weaponE6_func0B
   
   Library: KioskDefault 0 0 */

void weaponE6_func0B(ObjInstance *param1) { //801C97A4
  undefined *puVar1;
  
  puVar1 = param1->state;
  if (param1->romdefno == staff) {
    if (param1->animTimer == 1.0) {
      audioTryStartSfx((int *)param1,1,0x21a,0x7f,"weapons.c",0x245);
    }
    if (param1->animId != 0) {
      Object_ObjAnimSetMove(1.0,param1,0,0);
    }
    *(float *)(puVar1 + 0x14) = -0.15;
  }
  return;
}


/* Library Function - Single Match
    weaponE6_func0C
   
   Library: KioskDefault 0 0 */

void weaponE6_modelMtxFn(ObjInstance *this,short *param2,vec3f *param3) { //801C9838
  if ((this->state[0x80] & 1) != 0) {
    FUN_801c9cec(this,(int)this->state,(int)param3,param2);
  }
  return;
}


/* Library Function - Single Match
    weaponE6_func0D
   
   Library: KioskDefault 0 0 */

void weaponE6_render2(ObjInstance *param1) { //801C988C
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  HitState *pHVar4;
  int iVar5;
  undefined2 local_70;
  undefined2 local_6e;
  undefined2 local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58 [16];
  undefined *local_18;
  
  pHVar4 = param1->hitstate;
  local_18 = param1->state;
  iVar5 = 8;
  pfVar2 = (float *)&DAT_802d0240;
  pfVar3 = &local_60;
  do {
    fVar1 = pfVar2[3];
    pfVar3[2] = pfVar2[2];
    pfVar3[3] = fVar1;
    iVar5 = iVar5 + -1;
    pfVar2 = pfVar2 + 2;
    pfVar3 = pfVar3 + 2;
  } while (iVar5 != 0);
  if ((param1->romdefno != sword) && (param1->romdefno != staff)) {
    return;
  }
  if (pHVar4->field54_0x9d != 0) {
    iVar5 = (int)(char)pHVar4->field53_0x9c;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0x21 < iVar5) {
      iVar5 = 0x21;
    }
    local_68 = 1.0;
    local_6c = 0;
    local_6e = 0;
    local_70 = 0;
    local_64 = pHVar4->minSizeY;
    local_60 = pHVar4->sizeY;
    local_5c = (pHVar4->field12_0x3c).x;
    OSReport("mod: %08x mod2: %08x",DAT_80399d2c,DAT_80399d30);
    OSReport("mod: %08x mod2: %08x",*DAT_80399d2c,*DAT_80399d30);
    (**(code **)(*DAT_80399d2c + 4))
              (0,1,&local_70,0x401,0xffffffff,local_58 + (uint)(byte)(&DAT_80310cbc)[iVar5] * 4);
    audioSfxFn_800688bc((double)pHVar4->minSizeY,(double)pHVar4->sizeY,
                        (double)(pHVar4->field12_0x3c).x,
                        *(ushort *)((int)&PTR_DAT_80310c78 + iVar5 * 2),0x7f,"weapons.c",
                        (int *)0x283);
  }
  return;
}


void weaponE6_func0E(int param1) { //801C9A00
  *(byte *)(*(int *)(param1 + 0xb8) + 0x80) = *(byte *)(*(int *)(param1 + 0xb8) + 0x80) ^ 1;
  return;
}


/* Library Function - Single Match
    weaponE6_func0F
   
   Library: KioskDefault 0 0 */

void weaponE6_func0F(int param1,int param2) { //801C9A24
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  if (param2 == 0) {
    *(byte *)(iVar1 + 0x80) = *(byte *)(iVar1 + 0x80) & 0xfe;
  }
  else {
    *(byte *)(iVar1 + 0x80) = *(byte *)(iVar1 + 0x80) | 1;
  }
  return;
}


void weaponE6_func10(int param1,undefined2 param2) { //801C9A60
  *(undefined2 *)(*(int *)(param1 + 0xb8) + 0x88) = param2;
  return;
}


/* Library Function - Single Match
    weaponE6_func11
   
   Library: KioskDefault 0 0 */

void weaponE6_func11(int param1,int param2) { //801C9A80
  if (0xff < param2) {
    param2 = 0xff;
  }
  *(short *)(*(int *)(param1 + 0xb8) + 0x6e) = (short)param2;
  return;
}


void weaponE6_func15(double param1,double param2,int param3) { //801C9AAC
  int iVar1;
  
  iVar1 = *(int *)(param3 + 0xb8);
  *(float *)(iVar1 + 0x5c) = (float)param1;
  *(float *)(iVar1 + 0x60) = (float)param2;
  return;
}


/* Library Function - Single Match
    weaponE6_func12
   
   Library: KioskDefault 0 0 */

void weaponE6_func12(int param1,short param2) { //801C9ACC
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(short *)(iVar1 + 0x6e) = *(short *)(iVar1 + 0x6e) + param2;
  if (*(short *)(iVar1 + 0x6e) < 0) {
    *(undefined2 *)(iVar1 + 0x6e) = 0;
  }
  else if (0xff < *(short *)(iVar1 + 0x6e)) {
    *(undefined2 *)(iVar1 + 0x6e) = 0xff;
  }
  return;
}


int weaponE6_func13(int param1) { //801C9B1C
  return (int)*(short *)(*(int *)(param1 + 0xb8) + 0x6e);
}


int weaponE6_func16(int param1) { //801C9B38
  return (int)*(char *)(*(int *)(param1 + 0xb8) + 0x91);
}


/* Library Function - Single Match
    weaponE6_func14
   
   Library: KioskDefault 0 0 */

void weaponE6_func14(int param1,undefined4 *param2,undefined4 *param3) { //801C9B58
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = *(undefined4 *)(iVar1 + 0x18);
  param2[1] = *(undefined4 *)(iVar1 + 0x20);
  param2[2] = *(undefined4 *)(iVar1 + 0x28);
  *param3 = *(undefined4 *)(iVar1 + 0x30);
  param3[1] = *(undefined4 *)(iVar1 + 0x38);
  param3[2] = *(undefined4 *)(iVar1 + 0x40);
  return;
}

