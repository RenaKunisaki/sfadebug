
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void mediumbasket_initialise(undefined4 param) { //801E69B0
  return;
}


/* @description Called when DLL is unloaded */

void mediumbasket_release(void) { //801E69B4
  return;
}


/* Library Function - Single Match
    dll_10E_func03
   
   Library: KioskDefault 0 0 */

void mediumbasket_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //801E69B8
  short sVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_24;
  undefined *local_20;
  undefined4 local_1c;
  undefined *local_18;
  undefined *local_14;
  
  local_1c = 1;
  local_18 = &DAT_00020003;
  local_14 = &DAT_00040008;
  local_24 = 5;
  local_20 = &DAT_00060007;
  piVar7 = (int *)this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801e7244;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *(undefined2 *)((int)piVar7 + 0xe) = *(undefined2 *)&objDef[1].bound;
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  if (sVar1 == 0) {
    *piVar7 = 0;
  }
  else {
    sVar2._0_1_ = objDef[1].loadFlags;
    sVar2._1_1_ = objDef[1].mapStates2;
    if (sVar2 == 0xff) {
      *piVar7 = -1;
    }
    else {
      sVar3._0_1_ = objDef[1].loadFlags;
      sVar3._1_1_ = objDef[1].mapStates2;
      *piVar7 = sVar3 * 0x3c;
    }
  }
  uVar5 = mainGetBit((int)*(short *)((int)piVar7 + 0xe));
  if (uVar5 != 0) {
    piVar7[1] = (int)1.0;
    FUN_80088da4((int)this);
  }
  *(undefined *)((int)piVar7 + 0x11) = *(undefined *)((int)&objDef[1].objType + 1);
  DAT_80399d68 = DLL_setup(0x1003,1,FALSE);
  DAT_80399d6c = DLL_setup(0x1002,1,FALSE);
  iVar6 = randInt(0,100);
  *(short *)((int)piVar7 + 10) = (short)iVar6 + 300;
  *(undefined2 *)(piVar7 + 3) = 400;
  uVar4._0_1_ = objDef[1].allocatedSize;
  uVar4._1_1_ = objDef[1].mapStates1;
  *(char *)((int)piVar7 + 0x12) = (char)uVar4;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  (this->pos).rotation.x = (short)((int)(short)*(char *)&objDef[1].objType << 8);
  if (this->romdefno == LargeBasket) {
    *(char *)((int)piVar7 + 0x11) =
         (char)*(undefined2 *)((int)&local_1c + (uint)*(byte *)((int)piVar7 + 0x11) * 2);
    *(undefined2 *)(piVar7 + 5) = 0x120;
    *(undefined2 *)((int)piVar7 + 0x16) = 0x11f;
  }
  else if (this->romdefno == LargeCrate) {
    *(char *)((int)piVar7 + 0x11) =
         (char)*(undefined2 *)((int)&local_24 + (uint)*(byte *)((int)piVar7 + 0x11) * 2);
    *(undefined2 *)(piVar7 + 5) = 499;
    *(undefined2 *)((int)piVar7 + 0x16) = 500;
  }
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x8000;
  }
  return;
}


/* Library Function - Single Match
    dll_10E_func04
   
   Library: KioskDefault 0 0 */

void mediumbasket_update(ObjInstance *this) { //801E6B94
  ushort uVar1;
  short sVar2;
  ObjInstance *pOVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ObjDef *pOVar7;
  uint *puVar8;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined2 local_78;
  float local_74;
  float local_70;
  undefined4 uStack_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  double local_38;
  double local_30;
  
  pOVar7 = this->def;
  local_48 = 0;
  local_44 = 0x3f800000;
  local_40 = 0;
  local_4c = -1;
  local_54 = 1.0;
  local_64 = 8;
  local_60 = 0xff;
  local_5c = 0xff;
  local_58 = 0x78;
                    /* {@symbol 800d24d8} */
  (**(code **)(*(int *)pDll_newfog + 0x18))(&local_54);
  puVar8 = (uint *)this->state;
  pOVar3 = Object_objGetMain();
  if (((this->flags_0xaf & FieldB8TimeCanBeNegative) == 0) ||
     (uVar4 = mainGetBit(0x92a), uVar4 != 0)) {
                    /* {@symbol 8012dc1c} */
    iVar5 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar7->id);
    if (iVar5 != 0) {
      if ((float)puVar8[1] <= 0.0) {
        local_30 = (double)CONCAT44(0x43300000,(uint)this->newOpacity);
        iVar5 = (int)(timeDelta * 8.0 + (float)(local_30 - 4503599627370496.0));
        local_38 = (double)(longlong)iVar5;
        if (0xff < iVar5) {
          iVar5 = 0xff;
        }
        this->newOpacity = (u8)iVar5;
        if (*(short *)(puVar8 + 2) != 0) {
          FUN_80088da4((int)this);
          sVar2 = *(short *)(puVar8 + 2);
          uVar1 = (ushort)framesThisStep;
          *(ushort *)(puVar8 + 2) = sVar2 - uVar1;
          if ((short)(sVar2 - uVar1) < 1) {
            if ((int)*puVar8 < 1) {
              puVar8[1] = (uint)1.0;
            }
            else {
              puVar8[1] = (uint)1.0;
              local_38 = (double)CONCAT44(0x43300000,*puVar8 ^ 0x80000000);
                    /* {@symbol 8012db54} */
              (**(code **)(*(int *)pDll_SaveGame + 100))
                        ((double)(float)(local_38 - 4503601774854144.0),pOVar7->id);
            }
            (this->pos).pos.x = (pOVar7->pos).x;
            (this->pos).pos.y = (pOVar7->pos).y;
            (this->pos).pos.z = (pOVar7->pos).z;
            (this->oldPos).x = (pOVar7->pos).x;
            (this->oldPos).y = (pOVar7->pos).y;
            (this->oldPos).z = (pOVar7->pos).z;
            (this->vel).x = 0.0;
            (this->vel).y = 0.0;
            (this->vel).z = 0.0;
          }
          if (*(short *)(puVar8 + 2) < 0x33) {
            return;
          }
        }
        (this->pos).rotation.y = *(short *)(puVar8 + 6);
        local_38 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar8 + 6) ^ 0x80000000);
        iVar5 = (int)((float)(local_38 - 4503601774854144.0) * -0.5);
        local_30 = (double)(longlong)iVar5;
        *(short *)(puVar8 + 6) = (short)iVar5;
        if (((this->pos).rotation.y < 10) && (-10 < (this->pos).rotation.y)) {
          (this->pos).rotation.y = 0;
        }
        iVar5 = FUN_800884c8((int)this,&uStack_3c,&local_4c,&local_50,&local_70,&uStack_6c,&local_68
                            );
        if (iVar5 != 0) {
          *(char *)((int)puVar8 + 0x13) = *(char *)((int)puVar8 + 0x13) + (char)local_50;
          if (*(byte *)((int)puVar8 + 0x13) < 2) {
            objFreezeFn_80085e2c(this,0xf,200,0,0,1);
            audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                                (double)(this->prevPos).z,*(ushort *)(puVar8 + 5),0x7f,
                                "mediumbasket.c",(int *)0x156);
            if (this->romdefno == LargeBasket) {
              iVar6 = randInt(600,800);
              *(short *)(puVar8 + 6) = (short)iVar6;
            }
            if (iVar5 != 0xe) {
              local_70 = local_70 + playerMapOffsetX;
              local_68 = local_68 + playerMapOffsetZ;
              local_74 = 1.0;
              local_78 = 0;
              local_7a = 0;
              local_7c = 0;
              (**(code **)(*DAT_80399d6c + 4))(0,1,&local_7c,0x401,0xffffffff,&local_64);
            }
          }
          else {
            FUN_80068a9c((uint)this,0x7f);
            (**(code **)(*DAT_80399d68 + 4))(this,1,0,2,0xffffffff,0);
            audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                                (double)(this->prevPos).z,*(ushort *)((int)puVar8 + 0x16),0x7f,
                                "mediumbasket.c",(int *)0x16c);
            *(undefined2 *)(puVar8 + 2) = 0x32;
            *(undefined *)((int)puVar8 + 0x13) = 0;
            LargeCrate_spawnItem((int)this,(int)pOVar3,(int)puVar8);
            this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
          }
        }
        pOVar3 = Object_objGetMain();
        objDistSqObj2Obj(pOVar3,this);
        sVar2 = *(short *)((int)puVar8 + 10) - (ushort)framesThisStep;
        *(short *)((int)puVar8 + 10) = sVar2;
        if (sVar2 < 1) {
          iVar5 = randInt(0,100);
          *(short *)((int)puVar8 + 10) = (short)iVar5 + 300;
        }
      }
      else {
        this->newOpacity = 0;
        if (*puVar8 != 0xffffffff) {
          puVar8[1] = (uint)-(timeDelta * local_54 - (float)puVar8[1]);
          if ((double)(float)puVar8[1] <= 0.0) {
            uVar4 = FUN_801e799c((double)(float)puVar8[1],this);
            if (uVar4 == 0) {
              puVar8[1] = (uint)1.0;
            }
            else {
              puVar8[1] = (uint)0.0;
              *(undefined2 *)(puVar8 + 2) = 0;
              FUN_80088d3c((int)this);
              this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
            }
          }
        }
      }
    }
  }
  else {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
    mainSetBits(0x92a,1);
  }
  return;
}


/* @description Override hit detection */

void mediumbasket_hitDetect(ObjInstance *this) { //801E70FC
  return;
}


/* Library Function - Single Match
    dll_10E_func06
   
   Library: KioskDefault 0 0 */

void mediumbasket_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801E7100
  bool bVar2;
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  pOVar3 = this->def;
  puVar4 = this->state;
  bVar2 = checkSomeDebugFlags_8017c4f8();
  if (!bVar2) {
                    /* {@symbol 8012dc1c} */
    iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar3->id);
    if (iVar1 == 0) {
      return;
    }
    if ((*(short *)(puVar4 + 8) != 0) && (*(short *)(puVar4 + 8) < 0x33)) {
      return;
    }
    if (0.0 < *(float *)(puVar4 + 4)) {
      return;
    }
    if (this->flags_0xf8 == 0) {
      if (!shouldRender) {
        return;
      }
    }
    else if (shouldRender != true) {
      return;
    }
  }
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* Library Function - Single Match
    dll_10E_func07
   
   Library: KioskDefault 0 0 */

void mediumbasket_free(ObjInstance *this,int param2) { //801E71DC
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_80399d68);
  DLL_free(DAT_80399d6c);
  return;
}


undefined4 mediumbasket_func08(ObjInstance *this) { //801E7234
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int mediumbasket_getExtraSize(void) { //801E723C
  return 0x1c;
}

