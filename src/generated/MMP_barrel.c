
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void mmp_barrel_initialise(undefined4 param) { //80219E20
  DAT_80399e58 = 0;
  return;
}


/* @description Called when DLL is unloaded */

void mmp_barrel_release(void) { //80219E2C
  return;
}


/* Library Function - Single Match
    dll_1A3_func03
   
   Library: KioskDefault 0 0 */

void mmp_barrel_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80219E30
  short sVar1;
  short sVar2;
  void *pvVar3;
  DLL_func **ppDVar4;
  Shadow *pSVar5;
  undefined *puVar6;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  puVar6 = this->state;
  local_2c = 0x15;
  local_28 = 0;
  objDef->id = -1;
  FUN_80088d3c((int)this);
  objHitFn_80089354(this,(ushort)this->data->hitbox_flagsB6);
  objHitFn_80089074(this,4,2,1);
  (this->pos).rotation.z = 0x4000;
  (this->pos).pos.x = (objDef->pos).x;
  (this->prevPos).x = (objDef->pos).x;
  (this->pos).pos.y = (objDef->pos).y;
  (this->prevPos).y = (objDef->pos).y;
  (this->pos).pos.z = (objDef->pos).z;
  (this->prevPos).z = (objDef->pos).z;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  uStack_14 = (int)sVar1 ^ 0x80000000;
  local_18 = 0x43300000;
  *(float *)(puVar6 + 0x10c) =
       (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 10.0;
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  uStack_1c = (int)sVar2 ^ 0x80000000;
  local_20 = 0x43300000;
  *(float *)(puVar6 + 0x108) =
       (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) / 10.0;
  puVar6[0x110] = 0;
  puVar6[0x111] = 1;
  *(float *)(puVar6 + 0x114) = 0.0;
                    /* {@symbol 80128bb8} */
  (**(code **)(*(int *)pDll_RomCurve + 0x8c))(0x4059000000000000,puVar6,this,&local_2c,0xffffffff);
  pSVar5 = this->shadow;
  if (pSVar5 != (Shadow *)0x0) {
    pSVar5->flags = pSVar5->flags | 0x830;
    pSVar5->flags = pSVar5->flags & 0xfffdffff;
    (pSVar5->pos).x = (this->pos).pos.x;
    (pSVar5->pos).y = (this->pos).pos.y;
    (pSVar5->pos).z = (this->pos).pos.z;
    pSVar5->opacity = 0;
  }
  if (obj2 == (ObjInstance *)0x0) {
    pvVar3 = mmAlloc(0x28,LFX_COL,"mmp_barrel:lightSetup");
    *(void **)(puVar6 + 0x11c) = pvVar3;
    loadAsset_fileWithOffsetLength(*(void **)(puVar6 + 0x11c),LACTIONS.bin,19000,0x28);
    ppDVar4 = runlinkDownloadCode(0x1003,1);
    *(DLL_func ***)(puVar6 + 0x118) = ppDVar4;
  }
  return;
}


/* Library Function - Single Match
    dll_1A3_func04
   
   Library: KioskDefault 0 0 */

void mmp_barrel_update(ObjInstance *this) { //8021A004
  byte bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  ObjInstance *pOVar5;
  Shadow *pSVar6;
  ObjInstance *pOVar7;
  float *pfVar8;
  double local_30;
  double local_28;
  
  pSVar6 = this->shadow;
  pfVar8 = (float *)this->state;
  bVar1 = *(byte *)(pfVar8 + 0x44);
  if (bVar1 == 2) {
    pfVar8[0x45] = pfVar8[0x45] + timeDelta;
    if (60.0 <= pfVar8[0x45]) {
      Object_objAddObjectType(this,0x31);
      DAT_80399e58 = DAT_80399e58 + -1;
      *(undefined *)(pfVar8 + 0x44) = 3;
      pfVar8[0x45] = pfVar8[0x45] - 60.0;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      iVar3 = FUN_8006c2c8((double)pfVar8[0x42],pfVar8);
      if ((iVar3 == 0) && (pfVar8[4] != 0.0)) {
                    /* {@symbol 801290d4} */
        (**(code **)(*(int *)pDll_RomCurve + 0x90))(pfVar8);
      }
      fVar2 = pfVar8[0x1b];
      pfVar8[0x43] = timeDelta * -0.1 + pfVar8[0x43];
      (this->pos).pos.y = pfVar8[0x43] * timeDelta + (this->pos).pos.y;
      if ((this->pos).pos.y < fVar2 + 5.0) {
        pfVar8[0x43] = pfVar8[0x43] * -0.6;
        (this->pos).pos.y = (fVar2 + 5.0) * 2.0 - (this->pos).pos.y;
      }
      (this->pos).pos.x = pfVar8[0x1a];
      (this->pos).pos.z = pfVar8[0x1c];
      iVar4 = getAngle();
      (this->pos).rotation.x = (short)iVar4;
      if (*(char *)((int)pfVar8 + 0x111) == '\0') {
        local_30 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.z ^ 0x80000000);
        (this->pos).rotation.z =
             (short)(int)-(timeDelta * 32.0 - (float)(local_30 - 4503601774854144.0));
        if ((this->pos).rotation.z < 0x3a00) {
          *(undefined *)((int)pfVar8 + 0x111) = 1;
        }
      }
      else {
        local_28 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.z ^ 0x80000000);
        (this->pos).rotation.z =
             (short)(int)(timeDelta * 32.0 + (float)(local_28 - 4503601774854144.0));
        if (0x5000 < (this->pos).rotation.z) {
          *(undefined *)((int)pfVar8 + 0x111) = 0;
        }
      }
      local_30 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000);
      (this->pos).rotation.y =
           (short)(int)(timeDelta * 512.0 * pfVar8[0x42] + (float)(local_30 - 4503601774854144.0));
      (pSVar6->pos).x = (this->pos).pos.x;
      (pSVar6->pos).z = (this->pos).pos.z;
      (pSVar6->pos).y = pfVar8[0x1b] + 7.0;
      pOVar7 = (ObjInstance *)this->hitstate->field13_0x48;
      if (((iVar3 != 0) || (pOVar5 = Object_objGetMain(), pOVar7 == pOVar5)) ||
         (iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0), iVar3 != 0)) {
        if ((pOVar7 == (ObjInstance *)0x0) || (pOVar7->romdefno != MMP_barrel)) {
          iVar3 = randInt(0,2);
          FUN_8021a4f0(this,iVar3);
        }
        else if (this < pOVar7) {
          FUN_8021a4f0(this,3);
        }
        else {
          iVar3 = randInt(0,2);
          FUN_8021a4f0(this,iVar3);
        }
      }
    }
    else if (true) {
      FUN_80088da4((int)this);
      pfVar8[0x45] = pfVar8[0x45] + timeDelta;
      if (30.0 <= pfVar8[0x45]) {
        *(undefined *)(pfVar8 + 0x44) = 2;
        pfVar8[0x45] = pfVar8[0x45] - 30.0;
      }
    }
  }
  else if ((bVar1 < 4) && (pfVar8[0x45] = pfVar8[0x45] + timeDelta, 3000.0 <= pfVar8[0x45])) {
    Object_objFreeObject(this);
  }
  return;
}


/* @description Override hit detection */

void mmp_barrel_hitDetect(ObjInstance *this) { //8021A3C0
  return;
}


/* Library Function - Single Match
    dll_1A3_func06
   
   Library: KioskDefault 0 0 */

void mmp_barrel_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8021A3C4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->state[0x110] == '\0')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_1A3_func07
   
   Library: KioskDefault 0 0 */

void mmp_barrel_free(ObjInstance *this,int param2) { //8021A43C
  ObjInstance **ppOVar1;
  int iVar2;
  undefined *puVar3;
  int local_18 [2];
  
  puVar3 = this->state;
  ppOVar1 = Object_playerGetObject(0x31,local_18);
  iVar2 = 0;
  do {
    if (local_18[0] <= iVar2) {
LAB_8021a49c:
      if (puVar3[0x110] == '\x01') {
        DAT_80399e58 = DAT_80399e58 + -1;
      }
      mm_free(*(void **)(puVar3 + 0x11c));
      DLL_free(*(LoadedDll **)(puVar3 + 0x118));
      *(undefined4 *)(puVar3 + 0x118) = 0;
      return;
    }
    if (ppOVar1[iVar2] == this) {
      Object_removePlayerObj(this,0x31);
      goto LAB_8021a49c;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


undefined4 mmp_barrel_func08(ObjInstance *this) { //8021A4E0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int mmp_barrel_getExtraSize(void) { //8021A4E8
  return 0x120;
}

