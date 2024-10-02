
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void zBomb_initialise(undefined4 param) { //801E8CC4
  return;
}


/* @description Called when DLL is unloaded */

void zBomb_release(void) { //801E8CC8
  return;
}


/* Library Function - Single Match
    zBomb_func03
   
   Library: KioskDefault 0 0 */

void zBomb_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //801E8CCC
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)this->state;
  (this->pos).rotation.x = 0;
  (this->hitstate->field12_0x3c).z = 2.242078e-44;
  (this->hitstate->field12_0x3c).y = 2.242078e-44;
  FUN_80088da4((int)this);
  Object_objAddObjectType(this,0x12);
  *(undefined2 *)(puVar3 + 4) = 0;
  *(undefined *)((int)puVar3 + 0x23) = 0;
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  if (sVar1 == 0) {
    puVar3[1] = 0;
  }
  else {
    sVar2._0_1_ = objDef[1].loadFlags;
    sVar2._1_1_ = objDef[1].mapStates2;
    puVar3[1] = sVar2 * 0x34bc0;
  }
  *puVar3 = 0;
  *(undefined *)((int)puVar3 + 0x25) = 0;
  DAT_80399d70 = runlinkDownloadCode(0x1003,1);
  DAT_80399d74 = runlinkDownloadCode(0x1052,1);
  *(undefined2 *)((int)puVar3 + 0x16) = 100;
  *(undefined2 *)(puVar3 + 6) = 400;
  (this->pos).rotation.x = (short)((int)(short)*(char *)&objDef[1].objType << 8);
  *(undefined2 *)(puVar3 + 5) = *(undefined2 *)&objDef[1].bound;
  *(undefined2 *)((int)puVar3 + 0x12) = *(undefined2 *)&objDef[1].pos.x;
  if (*(short *)((int)puVar3 + 0x12) == 0) {
    *(undefined2 *)((int)puVar3 + 0x12) = 0x1e;
  }
  *(undefined2 *)((int)puVar3 + 0x1a) = 800;
  *(undefined2 *)((int)puVar3 + 0x1e) = 0;
  *(undefined *)((int)puVar3 + 0x26) = 0xff;
  *(undefined *)((int)puVar3 + 0x27) = 0;
  if (*(char *)((int)&objDef[1].objType + 1) == '\0') {
    puVar3[2] = 50.0;
  }
  else {
    puVar3[2] = (float)((double)CONCAT44(0x43300000,
                                         (int)*(char *)((int)&objDef[1].objType + 1) ^ 0x80000000) -
                       4503601774854144.0) * 10.0;
  }
  this->field76_0xf4 = 0;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x8000;
  }
  return;
}


/* Library Function - Single Match
    zBomb_func04
   
   Library: KioskDefault 0 0 */

void zBomb_update(ObjInstance *this) { //801E8E74
  ObjInstance *param1;
  int iVar1;
  undefined4 uVar2;
  N64Button32 NVar3;
  ObjDef *param2;
  undefined *puVar4;
  int *piVar5;
  double dVar6;
  float local_4c;
  short local_48;
  undefined2 local_46;
  undefined2 local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  double local_30;
  
  param2 = this->def;
  local_4c = 1.0;
                    /* {@symbol 800d24d8} */
  dVar6 = (double)(**(code **)(*(int *)pDll_newfog + 0x18))(&local_4c);
  piVar5 = (int *)this->state;
  param1 = Object_objGetMain();
  puVar4 = param1->state;
  objDistObj2Obj(param1,this);
  if (*(short *)((int)piVar5 + 0x1a) < 1) {
    *(undefined2 *)(piVar5 + 4) = 1;
    *(undefined *)((int)piVar5 + 0x23) = 0;
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    ret1_801E9804();
    (this->vel).x = 0.0;
    (this->vel).z = 0.0;
  }
  if (*(short *)((int)piVar5 + 0x1e) != 0) {
    audioTryStartSfx((int *)this,0xc0,0x68,0x39,"zbomb.c",0xbb);
    *(ushort *)((int)piVar5 + 0x1e) = *(short *)((int)piVar5 + 0x1e) - (ushort)framesThisStep;
    iVar1 = randInt(0,2);
    if (iVar1 == 2) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51c,0,1,0xffffffff,0);
    }
    if (*(short *)((int)piVar5 + 0x1e) < 1) {
      zBombExplodeFn_801e9884(dVar6,this);
      return;
    }
  }
  if (*piVar5 != 0) {
    local_30 = (double)(longlong)(int)(timeDelta * local_4c);
    *piVar5 = *piVar5 - (int)(short)(int)(timeDelta * local_4c);
    if (0 < *piVar5) {
      return;
    }
    *piVar5 = 0;
    *(undefined2 *)(piVar5 + 4) = 0;
    FUN_80088d3c((int)this);
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    this->field76_0xf4 = 0;
    return;
  }
  if (*(short *)(piVar5 + 4) != 0) {
    FUN_80068a9c((uint)this,0x40);
    *(ushort *)(piVar5 + 4) = *(short *)(piVar5 + 4) - (ushort)framesThisStep;
    if (*(short *)(piVar5 + 4) < 1) {
      if (piVar5[1] == 0) {
        *piVar5 = 1;
      }
      else {
        *piVar5 = piVar5[1];
      }
    }
    if (*(short *)(piVar5 + 4) < 0x33) {
      return;
    }
  }
  if (*(char *)((int)piVar5 + 0x23) == '\0') {
    if (*(char *)((int)piVar5 + 0x21) == '\0') {
      uVar2 = FUN_801e9764((int)this,(int)param1,(int)piVar5);
      *(char *)((int)piVar5 + 0x21) = (char)uVar2;
      if (*(char *)((int)piVar5 + 0x21) != '\0') {
        *(undefined *)((int)piVar5 + 0x22) = 1;
        *(undefined2 *)((int)piVar5 + 0x1e) = 600;
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
      (this->hitstate->pos).x = (this->pos).pos.x;
      (this->hitstate->pos).y = (this->pos).pos.y;
      (this->hitstate->pos).z = (this->pos).pos.z;
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      NVar3 = n64GetEnabledButtonsPressed(0);
      if ((NVar3 & N64_BUTTON_RIGHT) != 0) {
        *(undefined *)((int)piVar5 + 0x22) = 0;
      }
      if (*(char *)((int)piVar5 + 0x22) != '\0') {
        *(undefined2 *)(piVar5 + 4) = 0;
        *piVar5 = 0;
        objSendMsg((int)param1,0x100010,(uint)this,
                   CONCAT22(*(undefined2 *)((int)piVar5 + 0xe),*(undefined2 *)(piVar5 + 3)));
      }
      if (this->flags_0xf8 == 1) {
        *(undefined *)((int)piVar5 + 0x21) = 2;
      }
      if (((*(char *)((int)piVar5 + 0x21) == '\x02') && (this->flags_0xf8 == 0)) &&
         (param1->animId != 0x447)) {
        *(undefined *)((int)piVar5 + 0x21) = 0;
        *(undefined *)((int)piVar5 + 0x23) = 1;
        (this->vel).x = 0.0;
        (this->vel).y = *(float *)(puVar4 + 0x290) * 0.75 + 2.2;
        (this->vel).z = *(float *)(puVar4 + 0x290) * -0.75 + -2.2;
        local_3c = 0.0;
        local_38 = 0.0;
        local_34 = 0.0;
        local_40 = 1.0;
        local_44 = 0;
        local_46 = 0;
        local_48 = (param1->pos).rotation.x;
        FUN_8007a878(&local_48,&(this->vel).x);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x59,0x43,"zbomb.c",(int *)0x11b);
      }
      else if ((*(char *)((int)piVar5 + 0x21) == '\x02') && (this->flags_0xf8 == 0)) {
        *(undefined *)((int)piVar5 + 0x21) = 0;
        *(undefined *)((int)piVar5 + 0x23) = 2;
        (this->vel).x = 0.0;
        (this->vel).y = 0.0;
        (this->vel).z = 0.0;
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x59,0x43,"zbomb.c",(int *)0x12c);
      }
    }
  }
  if ((*(char *)((int)piVar5 + 0x23) == '\0') && (*(char *)((int)piVar5 + 0x21) == '\0')) {
    iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if (iVar1 != 0) {
      zBombExplodeFn_801e980c((int)this);
      return;
    }
  }
  else if (*(char *)((int)piVar5 + 0x23) != '\0') {
    *(ushort *)((int)piVar5 + 0x1a) = *(short *)((int)piVar5 + 0x1a) - (ushort)framesThisStep;
    if (*(char *)((int)piVar5 + 0x23) == '\x01') {
      objHitFn_80089074(this,0xe,3,0);
      if (-10.0 < (this->vel).y) {
        (this->vel).y = timeDelta * -0.12 + (this->vel).y;
      }
      FUN_80088d3c((int)this);
    }
    if ((this->hitstate->field54_0x9d != 0) && (*(char *)((int)piVar5 + 0x23) == '\x01')) {
      (this->vel).y = 0.0;
      *(undefined *)((int)piVar5 + 0x23) = 0;
      zBombExplodeFn_801e980c((int)this);
      return;
    }
    if ((this->hitstate->field54_0x9d != 0) && (*(char *)((int)piVar5 + 0x23) == '\x02')) {
      *(undefined *)((int)piVar5 + 0x23) = 0;
      zBombExplodeFn_801e980c((int)this);
      (this->vel).y = 0.0;
      return;
    }
    (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
    (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
    (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
  }
  (this->prevPos).x = (this->pos).pos.x;
  (this->prevPos).y = (this->pos).pos.y;
  (this->prevPos).z = (this->pos).pos.z;
  *(ushort *)((int)piVar5 + 0x16) = *(short *)((int)piVar5 + 0x16) - (ushort)framesThisStep;
  if (*(char *)((int)piVar5 + 0x21) != '\0') {
    dVar6 = (double)objDistObj2Def(this,param2);
    local_30 = (double)CONCAT44(0x43300000,
                                (int)*(short *)((int)piVar5 + 0x12) *
                                (int)*(short *)((int)piVar5 + 0x12) ^ 0x80000000);
    if ((double)(float)(local_30 - 4503601774854144.0) <= dVar6) {
      (this->vel).x = 0.0;
      (this->vel).z = 0.0;
      *(undefined2 *)(piVar5 + 4) = 500;
      *(undefined *)((int)piVar5 + 0x23) = 0;
      this->flags_0xf8 = 0;
      FUN_80088d3c((int)this);
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      objHitFn_80089114(this);
    }
  }
  return;
}


/* @description Override hit detection */

void zBomb_hitDetect(ObjInstance *this) { //801E9514
  return;
}


/* Library Function - Single Match
    zBomb_func06
   
   Library: KioskDefault 0 0 */

void zBomb_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //801E9518
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int *piVar1;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  piVar1 = (int *)this->state;
  if (((*(short *)(piVar1 + 4) == 0) || (0x32 < *(short *)(piVar1 + 4))) && (*piVar1 == 0)) {
    if (this->flags_0xf8 == 0) {
      if (!shouldRender) {
        return;
      }
    }
    else if (shouldRender != true) {
      return;
    }
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)*(short *)((int)piVar1 + 0x12) ^ 0x80000000
                                                   ) - 4503601774854144.0),35.0,param2_00,param3_00,
                   0xff,0xff,0xff);
    }
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)piVar1[2],35.0,param2_00,param3_00,0xff,0,0);
    }
    if (*(short *)((int)piVar1 + 0x1e) != 0) {
      if (*(short *)((int)piVar1 + 0x1e) < 0x3c) {
        *(u8 *)((int)piVar1 + 0x26) = *(char *)((int)piVar1 + 0x26) + framesThisStep * '\n';
        if (0x80 < *(byte *)((int)piVar1 + 0x26)) {
          *(undefined *)((int)piVar1 + 0x26) = 0;
        }
        FUN_80096b14(200,0x1e,0x1e,*(undefined *)((int)piVar1 + 0x26));
      }
      else if (*(short *)((int)piVar1 + 0x1e) < 0xf0) {
        *(u8 *)((int)piVar1 + 0x26) = *(char *)((int)piVar1 + 0x26) + framesThisStep * '\x05';
        if (0x80 < *(byte *)((int)piVar1 + 0x26)) {
          *(undefined *)((int)piVar1 + 0x26) = 0;
        }
        FUN_80096b14(200,0x1e,0x1e,*(undefined *)((int)piVar1 + 0x26));
      }
    }
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    zBomb02A7_func07
    zBomb_func07
   
   Library: KioskDefault 0 0 */

void zBomb_free(ObjInstance *this,int param2) { //801E96EC
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_80399d70);
  DAT_80399d70 = (LoadedDll *)0x0;
  DLL_free(DAT_80399d74);
  DAT_80399d74 = (LoadedDll *)0x0;
  return;
}


undefined4 zBomb_func08(ObjInstance *this) { //801E9754
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int zBomb_getExtraSize(void) { //801E975C
  return 0x2c;
}

