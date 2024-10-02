
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void smallbasket_initialise(undefined4 param) { //801E4E1C
  return;
}


/* @description Called when DLL is unloaded */

void smallbasket_release(void) { //801E4E20
  return;
}


/* Library Function - Single Match
    dll_10D_func03
   
   Library: KioskDefault 0 0 */

void smallbasket_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //801E4E24
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)this->state;
  (this->hitstate->field12_0x3c).z = 2.242078e-44;
  (this->hitstate->field12_0x3c).y = 2.242078e-44;
  FUN_80088da4((int)this);
  Object_objAddObjectType(this,0x12);
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  if (sVar1 == 0) {
    puVar6[1] = 0;
  }
  else {
    sVar2._0_1_ = objDef[1].loadFlags;
    sVar2._1_1_ = objDef[1].mapStates2;
    puVar6[1] = sVar2 * 0x3c;
  }
  DAT_80399d60 = runlinkDownloadCode(0x1003,1);
  iVar4 = randInt(0,100);
  *(short *)(puVar6 + 4) = (short)iVar4 + 300;
  uVar3._0_1_ = objDef[1].allocatedSize;
  uVar3._1_1_ = objDef[1].mapStates1;
  *(char *)((int)puVar6 + 0x22) = (char)uVar3;
  (this->pos).rotation.x = (short)((int)(short)*(char *)&objDef[1].objType << 8);
  *(undefined2 *)((int)puVar6 + 0x1a) = *(undefined2 *)&objDef[1].bound;
  *(undefined2 *)((int)puVar6 + 0xe) = *(undefined2 *)&objDef[1].pos.x;
  if (*(short *)((int)puVar6 + 0xe) == 0) {
    *(undefined2 *)((int)puVar6 + 0xe) = 0x14;
  }
  *(undefined2 *)((int)puVar6 + 0x16) = 800;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  *(undefined *)((int)puVar6 + 0x21) = *(undefined *)((int)&objDef[1].objType + 1);
  (this->oldPos).x = (this->pos).pos.x;
  (this->oldPos).y = (this->pos).pos.y;
  (this->oldPos).x = (this->pos).pos.z;
  uVar5 = mainGetBit((int)*(short *)((int)puVar6 + 0x1a));
  if (uVar5 != 0) {
    *puVar6 = 1;
    FUN_80088da4((int)this);
  }
  if (this->romdefno == SmallBasket) {
    *(undefined2 *)((int)puVar6 + 0x12) = 0x11f;
  }
  else {
    *(undefined2 *)((int)puVar6 + 0x12) = 500;
  }
  return;
}


/* Library Function - Single Match
    dll_10D_func04
   
   Library: KioskDefault 0 0 */

void smallbasket_update(ObjInstance *this) { //801E4F80
  ObjInstance *param1;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  u16 uVar4;
  undefined *puVar5;
  ObjDef *param2;
  int *piVar6;
  double dVar7;
  float local_4c;
  short local_48;
  undefined2 local_46;
  undefined2 local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  double local_30;
  double local_28;
  
  param1 = Object_objGetMain();
  param2 = this->def;
  local_4c = 1.0;
  if (((this->flags_0xaf & FieldB8TimeCanBeNegative) != 0) &&
     (uVar1 = mainGetBit(0x92a), uVar1 == 0)) {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
    mainSetBits(0x92a,1);
    return;
  }
                    /* {@symbol 800d24d8} */
  (**(code **)(*(int *)pDll_newfog + 0x18))(&local_4c);
  piVar6 = (int *)this->state;
                    /* {@symbol 8012dc1c} */
  iVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(param2->id);
  if (iVar2 == 0) {
    return;
  }
  puVar5 = param1->state;
  if (*(short *)((int)piVar6 + 0x16) < 1) {
    *(undefined2 *)((int)piVar6 + 0x16) = 800;
    *(undefined2 *)(piVar6 + 3) = 1;
    *(undefined *)((int)piVar6 + 0x1f) = 0;
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    scarabFn_801816f8((int)this,param1,(int)piVar6);
    (this->vel).x = 0.0;
    (this->vel).z = 0.0;
  }
  if (*piVar6 == 0) {
    local_28 = (double)CONCAT44(0x43300000,(uint)this->newOpacity);
    iVar2 = (int)(timeDelta * 8.0 + (float)(local_28 - 4503599627370496.0));
    local_30 = (double)(longlong)iVar2;
    if (0xff < iVar2) {
      iVar2 = 0xff;
    }
    this->newOpacity = (u8)iVar2;
    if (*(short *)(piVar6 + 3) != 0) {
      FUN_80088da4((int)this);
      *(ushort *)(piVar6 + 3) = *(short *)(piVar6 + 3) - (ushort)framesThisStep;
      if (*(short *)(piVar6 + 3) < 1) {
        if (piVar6[1] == 0) {
          *piVar6 = 1;
        }
        else {
          *piVar6 = piVar6[1];
        }
        local_30 = (double)CONCAT44(0x43300000,piVar6[1] ^ 0x80000000);
                    /* {@symbol 8012db54} */
        (**(code **)(*(int *)pDll_SaveGame + 100))
                  ((double)(float)(local_30 - 4503601774854144.0),param2->id);
        (this->pos).pos.x = (param2->pos).x;
        (this->pos).pos.y = (param2->pos).y;
        (this->pos).pos.z = (param2->pos).z;
        (this->oldPos).x = (param2->pos).x;
        (this->oldPos).y = (param2->pos).y;
        (this->oldPos).z = (param2->pos).z;
        (this->vel).x = 0.0;
        (this->vel).y = 0.0;
        (this->vel).z = 0.0;
      }
      if (*(short *)(piVar6 + 3) < 0x33) {
        return;
      }
    }
    if (*(char *)((int)piVar6 + 0x1f) == '\x01') {
      if (*(char *)((int)piVar6 + 0x1f) != '\0') {
        *(ushort *)((int)piVar6 + 0x16) = *(short *)((int)piVar6 + 0x16) - (ushort)framesThisStep;
        if (*(char *)((int)piVar6 + 0x1f) == '\x01') {
          objHitFn_80089074(this,0xe,1,0);
          if (-10.0 < (this->vel).y) {
            (this->vel).y = timeDelta * -0.12 + (this->vel).y;
          }
          FUN_80088d3c((int)this);
        }
        (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
        (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
        (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
        FUN_801e5a84((int)this);
        if ((this->hitstate->field54_0x9d == 0) || (*(char *)((int)piVar6 + 0x1f) != '\x01')) {
          if ((this->hitstate->field54_0x9d != 0) && (*(char *)((int)piVar6 + 0x1f) == '\x02')) {
            (this->vel).x = 0.0;
            (this->vel).z = 0.0;
            *(undefined2 *)(piVar6 + 3) = 500;
            *(undefined *)((int)piVar6 + 0x1f) = 0;
            this->flags_0xf8 = 0;
            FUN_80088d3c((int)this);
            this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
            objHitFn_80089114(this);
          }
        }
        else {
          (**(code **)(*DAT_80399d60 + 4))(this,1,0,2,0xffffffff,0);
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,*(ushort *)((int)piVar6 + 0x12),0x7f,
                              "smallbasket.c",(int *)0x1be);
          *(undefined2 *)(piVar6 + 3) = 0x32;
          *(undefined *)((int)piVar6 + 0x1f) = 0;
          this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
          scarabFn_801816f8((int)this,param1,(int)piVar6);
          (this->vel).x = 0.0;
          (this->vel).z = 0.0;
          objHitFn_80089114(this);
        }
      }
    }
    else if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      uVar3 = FUN_801e5a10((int)this,param1,(int)piVar6);
      *(char *)((int)piVar6 + 0x1d) = (char)uVar3;
      if (*(char *)((int)piVar6 + 0x1d) != '\0') {
        *(undefined *)((int)piVar6 + 0x1e) = 1;
      }
      if (this->flags_0xf8 == 0) {
        FUN_80088d3c((int)this);
        this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      }
      (this->oldPos).x = (this->pos).pos.x;
      (this->oldPos).y = (this->pos).pos.z;
      (this->oldPos).z = (this->pos).pos.z;
    }
    else {
      FUN_80088da4((int)this);
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      uVar4 = getEnabledButtonsPressed(0);
      if ((uVar4 & 0x100) != 0) {
        uVar1 = FUN_801a8944((int)param1);
        if (uVar1 == 0) {
          audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"smallbasket.c",0x14b);
        }
        else {
          *(undefined *)((int)piVar6 + 0x1e) = 0;
        }
      }
      if (this->flags_0xf8 == 1) {
        *(undefined *)((int)piVar6 + 0x1d) = 2;
      }
      if ((*(char *)((int)piVar6 + 0x1d) == '\x02') && (this->flags_0xf8 == 0)) {
        uVar1 = FUN_801a7fa8((int)param1);
        if (uVar1 == 0) {
          uVar1 = FUN_801a7f78((int)param1);
          if (uVar1 == 0) {
            *(undefined *)((int)piVar6 + 0x1d) = 0;
            *(undefined *)((int)piVar6 + 0x1e) = 0;
            (**(code **)(*DAT_80399d60 + 4))(this,1,0,2,0xffffffff,0);
            audioTryStartSfx((int *)this,1,*(ushort *)((int)piVar6 + 0x12),0x7f,
                             "smallbasket.c",0x17c);
            *(undefined2 *)(piVar6 + 3) = 0x32;
            *(undefined *)((int)piVar6 + 0x1f) = 0;
            this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
            (this->vel).x = 0.0;
            (this->vel).z = 0.0;
            objHitFn_80089114(this);
          }
          else {
            *(undefined *)((int)piVar6 + 0x1d) = 0;
            *(undefined *)((int)piVar6 + 0x1f) = 2;
            (this->vel).x = 0.0;
            (this->vel).y = 0.0;
            (this->vel).z = 0.0;
            FUN_80088d3c((int)this);
            this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
            objHitFn_80089114(this);
          }
        }
        else {
          *(undefined *)((int)piVar6 + 0x1d) = 0;
          *(undefined *)((int)piVar6 + 0x1f) = 1;
          (this->vel).y = *(float *)(puVar5 + 0x290) * 0.75 + 2.2;
          (this->vel).z = *(float *)(puVar5 + 0x290) * -0.75 + -2.2;
          local_3c = 0.0;
          local_38 = 0.0;
          local_34 = 0.0;
          local_40 = 1.0;
          local_44 = 0;
          local_46 = 0;
          local_48 = (param1->pos).rotation.x;
          FUN_8007a878(&local_48,&(this->vel).x);
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x59,0x43,"smallbasket.c",
                              (int *)0x164);
        }
      }
      if (*(char *)((int)piVar6 + 0x1e) != '\0') {
        *(undefined2 *)(piVar6 + 3) = 0;
        *piVar6 = 0;
        objSendMsg((int)param1,0x100010,(uint)this,
                   CONCAT22(*(undefined2 *)((int)piVar6 + 10),*(undefined2 *)(piVar6 + 2)));
      }
    }
    *(ushort *)(piVar6 + 4) = *(short *)(piVar6 + 4) - (ushort)framesThisStep;
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      FUN_801e688c(this,param1,(int)piVar6);
    }
    else {
      dVar7 = (double)objDistObj2Def(this,param2);
      local_30 = (double)CONCAT44(0x43300000,
                                  (int)*(short *)((int)piVar6 + 0xe) *
                                  (int)*(short *)((int)piVar6 + 0xe) ^ 0x80000000);
      if ((double)(float)(local_30 - 4503601774854144.0) <= dVar7) {
        (this->vel).x = 0.0;
        (this->vel).z = 0.0;
        *(undefined2 *)(piVar6 + 3) = 500;
        *(undefined *)((int)piVar6 + 0x1f) = 0;
        this->flags_0xf8 = 0;
        FUN_80088d3c((int)this);
        this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
        objHitFn_80089114(this);
      }
    }
    if ((*(short *)(piVar6 + 4) < 1) && (*(char *)((int)piVar6 + 0x1d) != '\0')) {
      if ((*(char *)((int)piVar6 + 0x21) == '\x05') || (*(char *)((int)piVar6 + 0x21) == '\x06')) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x11e,0x39,"smallbasket.c",
                            (int *)0x1f3);
        iVar2 = randInt(0,100);
        *(short *)(piVar6 + 4) = (short)iVar2 + 300;
      }
      else if (((*(char *)((int)piVar6 + 0x21) == '\x01') ||
               (*(char *)((int)piVar6 + 0x21) == '\x02')) ||
              (*(char *)((int)piVar6 + 0x21) == '\x03')) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x121,0x39,"smallbasket.c",
                            (int *)0x1f7);
        iVar2 = randInt(0,100);
        *(short *)(piVar6 + 4) = (short)iVar2 + 300;
      }
    }
    return;
  }
  this->newOpacity = 0;
  dVar7 = (double)timeDelta;
  iVar2 = (int)(dVar7 * (double)local_4c);
  local_28 = (double)(longlong)iVar2;
  *piVar6 = *piVar6 - (int)(short)iVar2;
  if (0 < *piVar6) {
    return;
  }
  uVar1 = FUN_801e6970(dVar7,this);
  if (uVar1 == 0) {
    *piVar6 = 1;
    return;
  }
  *piVar6 = 0;
  *(undefined2 *)(piVar6 + 3) = 0;
  FUN_80088d3c((int)this);
  objHitUpdatePos(this);
  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  return;
}


/* @description Override hit detection */

void smallbasket_hitDetect(ObjInstance *this) { //801E5880
  return;
}


/* Library Function - Single Match
    dll_10D_func06
   
   Library: KioskDefault 0 0 */

void smallbasket_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //801E5884
  bool bVar2;
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar3;
  int *piVar4;
  
  pOVar3 = this->def;
  piVar4 = (int *)this->state;
  bVar2 = checkSomeDebugFlags_8017c4f8();
  if (!bVar2) {
                    /* {@symbol 8012dc1c} */
    iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar3->id);
    if (iVar1 == 0) {
      return;
    }
    if ((*(short *)(piVar4 + 3) != 0) && (*(short *)(piVar4 + 3) < 0x33)) {
      return;
    }
    if (*piVar4 != 0) {
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
  if (((this->pos).flags & 0x100) != 0) {
    FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)(float)((double)CONCAT44(0x43300000,
                                                  (int)*(short *)((int)piVar4 + 0xe) ^ 0x80000000) -
                                4503601774854144.0),35.0,
                 (Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
  }
  objRenderCurrentModel
            (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
             (int *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* Library Function - Single Match
    dll_10D_func07
   
   Library: KioskDefault 0 0 */

void smallbasket_free(ObjInstance *this,int param2) { //801E59B0
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_80399d60);
  return;
}


undefined4 smallbasket_func08(ObjInstance *this) { //801E5A00
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int smallbasket_getExtraSize(void) { //801E5A08
  return 0x24;
}

