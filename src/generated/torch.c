
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void torch1C1_initialise(undefined4 param) { //8023EBB4
  return;
}


/* @description Called when DLL is unloaded */

void torch1C1_release(void) { //8023EBB8
  return;
}


/* Library Function - Single Match
    dll_1C1_func03
   
   Library: KioskDefault 0 0 */

void torch1C1_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8023EBBC
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  bool bVar7;
  DLL_func **ppDVar6;
  int *piVar8;
  undefined auStack_34 [16];
  float local_24;
  undefined4 local_18;
  uint uStack_14;
  
  piVar8 = (int *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 10);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 < 1) {
    (this->pos).scale = 0.1;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uStack_14 = (int)sVar2 ^ 0x80000000;
    local_18 = 0x43300000;
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 8192.0;
  }
  *(undefined *)((int)piVar8 + 9) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined *)((int)piVar8 + 10) = 0;
  *(undefined *)((int)piVar8 + 0xd) = 0;
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  *piVar8 = (int)sVar3;
  bVar7 = checkSomeDebugFlags_8017c4f8();
  if (!bVar7) {
    local_24 = -2.0;
    if (*(char *)((int)piVar8 + 9) == '\x01') {
      uVar5._0_1_ = objDef[1].loadFlags;
      uVar5._1_1_ = objDef[1].mapStates2;
      *(char *)((int)piVar8 + 0xd) = (char)uVar5;
      *(undefined *)((int)piVar8 + 0xb) = 0;
      *(undefined *)(piVar8 + 3) = 0;
    }
    else if ((*(char *)((int)piVar8 + 9) == '\0') && (true)) {
      *(undefined *)((int)piVar8 + 10) = 1;
      ppDVar6 = runlinkDownloadCode(0x1011,1);
      sVar4._0_1_ = objDef[1].loadFlags;
      sVar4._1_1_ = objDef[1].mapStates2;
      if (sVar4 == 0) {
        (**(code **)(*ppDVar6 + 4))(this,0,auStack_34,&DAT_00010004,0xffffffff,0);
      }
    }
  }
  *(undefined2 *)(piVar8 + 1) = 0;
  return;
}


/* Library Function - Single Match
    dll_1C1_func04
   
   Library: KioskDefault 0 0 */

void DFP_Torch_update(ObjInstance *this) { //8023ED30
  int iVar1;
  LoadedDll *dll;
  uint uVar2;
  int *piVar3;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined auStack_34 [16];
  float local_24;
  
  piVar3 = (int *)this->state;
  local_44 = 999;
  local_40 = 0x8c;
  local_3c = 0x8d;
  local_38 = 0x28;
  audioTryStartSfx((int *)this,0x40,300,0x7f,"torch.c",0x71);
  objUpdateOpacity(this);
  if (*(char *)((int)piVar3 + 9) == '\x01') {
    local_24 = -2.0;
    *(undefined *)(piVar3 + 3) = *(undefined *)((int)piVar3 + 10);
    iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if ((iVar1 != 0) &&
       (*(char *)((int)piVar3 + 10) = '\x01' - *(char *)((int)piVar3 + 10),
       *(char *)((int)piVar3 + 10) != '\0')) {
      *(undefined2 *)((int)piVar3 + 6) = 700;
    }
    if (((*(char *)((int)piVar3 + 10) != '\0') && (*(short *)((int)piVar3 + 6) != 0)) &&
       (*(ushort *)((int)piVar3 + 6) = *(short *)((int)piVar3 + 6) - (ushort)framesThisStep,
       *(short *)((int)piVar3 + 6) < 1)) {
      *(undefined2 *)((int)piVar3 + 6) = 0;
      *(undefined *)((int)piVar3 + 10) = 0;
    }
    if (((*(char *)((int)piVar3 + 10) != '\0') && (*(short *)(piVar3 + 1) < 1)) &&
       (*(char *)((int)piVar3 + 0xb) != '\0')) {
      *(undefined *)((int)piVar3 + 0xb) = 0;
      audioTryStartSfx((int *)this,1,0x37,0x7f,"torch.c",0x94);
    }
    if (*(char *)((int)piVar3 + 10) != *(char *)(piVar3 + 3)) {
      if (*(char *)((int)piVar3 + 10) == '\0') {
        FUN_80068a9c((uint)this,0x40);
                    /* {@symbol 800e2b88} */
        (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        if ((*piVar3 != -1) && (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          mainSetBits(*piVar3,0);
        }
        if ((DAT_80399ef8 == '\x01') && (*(char *)((int)piVar3 + 0xd) == '\0')) {
          DAT_80399ef8 = '\0';
        }
        if ((DAT_80399ef8 == '\x03') && (*(char *)((int)piVar3 + 0xd) == '\x01')) {
          mainSetBits(0x58c,0);
          DAT_80399ef8 = '\0';
        }
      }
      else {
        dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
        local_40 = (uint)*(byte *)((int)piVar3 + 0xd) * 2 + 0x19d;
        local_3c = (uint)*(byte *)((int)piVar3 + 0xd) * 2 + 0x19e;
        (**(code **)(dll->id + 4))(this,1,auStack_34,&DAT_00010004,0xffffffff,&local_44);
        DLL_free(dll);
        for (iVar1 = 0; iVar1 < 200; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a3,0,0,0xffffffff,0);
        }
        if ((*piVar3 != -1) && (uVar2 = mainGetBit(*piVar3), uVar2 == 0)) {
          mainSetBits(*piVar3,1);
        }
        if (((DAT_80399ef8 == '\0') && (*(char *)((int)piVar3 + 0xd) == '\0')) &&
           (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          DAT_80399ef8 = '\x01';
        }
        if (((DAT_80399ef8 == '\x01') && (*(char *)((int)piVar3 + 0xd) == '\x01')) &&
           (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          DAT_80399ef8 = '\x02';
        }
        if (((DAT_80399ef8 == '\x02') && (*(char *)((int)piVar3 + 0xd) == '\x01')) &&
           (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          mainSetBits(0x58c,1);
          DAT_80399ef8 = '\x03';
        }
        *(undefined *)((int)piVar3 + 0xb) = 1;
        *(undefined2 *)(piVar3 + 1) = 1;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void torch1C1_hitDetect(ObjInstance *this) { //8023F0F0
  return;
}


/* Library Function - Single Match
    dll_1C1_func06
   
   Library: KioskDefault 0 0 */

void torch1C1_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8023F0F4
  float fVar1;
  bool bVar4;
  Camera *pCVar2;
  int iVar3;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar5;
  double dVar6;
  undefined auStack_70 [12];
  float local_64;
  float local_60;
  float local_5c;
  vec3f local_58;
  vec3f local_4c;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 auStack_34 [2];
  vec3s vStack_2c;
  vec3s avStack_24 [2];
  
  puVar5 = this->state;
  if (shouldRender) {
    bVar4 = checkSomeDebugFlags_8017c4f8();
    if (bVar4) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    if (puVar5[10] != '\0') {
      puVar5[8] = 1;
      pCVar2 = getCurCamera();
      local_40 = (pCVar2->pos).x - (this->pos).pos.x;
      local_3c = (pCVar2->pos).y - (this->pos).pos.y;
      local_38 = (pCVar2->pos).z - (this->pos).pos.z;
      dVar6 = sqrt((double)(local_38 * local_38 + local_40 * local_40 + local_3c * local_3c));
      if (50.0 < dVar6) {
        fVar1 = (float)(1.0 / dVar6);
        local_40 = local_40 * fVar1;
        local_3c = local_3c * fVar1;
        local_38 = local_38 * fVar1;
        local_4c.x = local_40 * 32.0 + (this->pos).pos.x;
        local_4c.y = local_3c * 32.0 + (this->pos).pos.y;
        local_4c.z = local_38 * 32.0 + (this->pos).pos.z;
        local_58.x = local_40 * -20.0 + (pCVar2->pos).x;
        local_58.y = local_3c * -20.0 + (pCVar2->pos).y;
        local_58.z = local_38 * -20.0 + (pCVar2->pos).z;
        vec3f_toNearest10(&local_4c,avStack_24);
        vec3f_toNearest10(&local_58,&vStack_2c);
        iVar3 = FUN_8006dd10((undefined4 *)avStack_24,(undefined4 *)&vStack_2c,auStack_34,
                             (undefined *)0x0,'\0');
        if (iVar3 == 0) {
          puVar5[8] = 0;
                    /* {@symbol 800dc1d4} */
          (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        }
      }
      if (*(short *)(puVar5 + 4) < 1) {
        if (puVar5[8] != '\0') {
          local_64 = 0.0;
          local_60 = 5.0;
          local_5c = 0.0;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1f7,auStack_70,0x12,0xffffffff,0);
        }
        iVar3 = randInt(-10,10);
        *(short *)(puVar5 + 4) = (short)iVar3 + 0x3c;
      }
      else {
        *(ushort *)(puVar5 + 4) = *(short *)(puVar5 + 4) - (ushort)framesThisStep;
      }
    }
  }
  else {
    *(undefined2 *)(puVar5 + 4) = 0;
    puVar5[8] = 0;
  }
  return;
}


/* @description Free object instance */

void torch1C1_free(ObjInstance *this,int param2) { //8023F3D0
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 torch1C1_func08(ObjInstance *this) { //8023F428
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int torch1C1_getExtraSize(void) { //8023F430
  return 0x10;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void torch1CD_initialise(undefined4 param) { //802453D4
  return;
}


/* @description Called when DLL is unloaded */

void torch1CD_release(void) { //802453D8
  return;
}


/* Library Function - Single Match
    dll_1CD_func03
   
   Library: KioskDefault 0 0 */

void torch1CD_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802453DC
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  bool bVar7;
  DLL_func **ppDVar6;
  int *piVar8;
  undefined auStack_34 [16];
  float local_24;
  undefined4 local_18;
  uint uStack_14;
  
  piVar8 = (int *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 10);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 < 1) {
    (this->pos).scale = 0.1;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uStack_14 = (int)sVar2 ^ 0x80000000;
    local_18 = 0x43300000;
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 8192.0;
  }
  *(undefined *)((int)piVar8 + 0xb) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined *)(piVar8 + 3) = 0;
  *(undefined *)((int)piVar8 + 0xf) = 0;
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  *piVar8 = (int)sVar3;
  bVar7 = checkSomeDebugFlags_8017c4f8();
  if (!bVar7) {
    local_24 = -2.0;
    if (*(char *)((int)piVar8 + 0xb) == '\x01') {
      uVar5._0_1_ = objDef[1].loadFlags;
      uVar5._1_1_ = objDef[1].mapStates2;
      *(char *)((int)piVar8 + 0xf) = (char)uVar5;
      *(undefined *)((int)piVar8 + 0xd) = 0;
      *(ushort *)(piVar8 + 2) = (ushort)*(byte *)((int)piVar8 + 0xf) * 0x28 + 0x398;
      *(undefined *)((int)piVar8 + 0xe) = 0;
    }
    else if ((*(char *)((int)piVar8 + 0xb) == '\0') && (true)) {
      *(undefined *)(piVar8 + 3) = 1;
      ppDVar6 = runlinkDownloadCode(0x1011,1);
      sVar4._0_1_ = objDef[1].loadFlags;
      sVar4._1_1_ = objDef[1].mapStates2;
      if (sVar4 == 0) {
        (**(code **)(*ppDVar6 + 4))(this,0,auStack_34,&DAT_00010004,0xffffffff,0);
      }
    }
  }
  *(undefined2 *)(piVar8 + 1) = 0;
  return;
}


/* Library Function - Single Match
    dll_1CD_func04
   
   Library: KioskDefault 0 0 */

void dll_WGSH_Torch_update(ObjInstance *this) { //80245560
  ObjInstance *param1;
  bool bVar3;
  int iVar1;
  LoadedDll *dll;
  uint uVar2;
  int *piVar4;
  double in_f1;
  undefined auStack_4c [16];
  float local_3c;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  
  piVar4 = (int *)this->state;
  local_34 = 999;
  local_30 = 0x8c;
  local_2c = 0x8d;
  local_28 = 0x28;
  param1 = Object_objGetMain();
  objDistObj2Obj(param1,this);
  bVar3 = FUN_80068b20((int)this,0x40);
  if (bVar3) {
    if ((90.0 <= in_f1) && (*(char *)(piVar4 + 3) != '\0')) {
      FUN_80068a9c((uint)this,0x40);
    }
  }
  else if ((in_f1 < 90.0) && (*(char *)(piVar4 + 3) != '\0')) {
    audioTryStartSfx((int *)this,0x40,0x1d3,0x7f,"torch.c",0x83);
  }
  objUpdateOpacity(this);
  if (0 < *(short *)(piVar4 + 2)) {
    *(ushort *)(piVar4 + 2) = *(short *)(piVar4 + 2) - (ushort)framesThisStep;
  }
  if (*(char *)((int)piVar4 + 0xb) == '\x01') {
    local_3c = -2.0;
    *(undefined *)((int)piVar4 + 0xe) = *(undefined *)(piVar4 + 3);
    iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if ((iVar1 != 0) || ((*(short *)(piVar4 + 2) != 0 && (*(short *)(piVar4 + 2) < 0x15)))) {
      *(char *)(piVar4 + 3) = '\x01' - *(char *)(piVar4 + 3);
      if (*(char *)(piVar4 + 3) != '\0') {
        *(undefined2 *)((int)piVar4 + 6) = 1000;
      }
      if (*(short *)(piVar4 + 2) != 0) {
        *(undefined2 *)(piVar4 + 2) = 0;
        DAT_80399f38 = '\x03';
        *(undefined2 *)((int)piVar4 + 6) = 300;
        if (*(char *)((int)piVar4 + 0xf) == '\x02') {
          mainSetBits(0x472,1);
        }
      }
    }
    if (((*(char *)(piVar4 + 3) != '\0') && (*(short *)((int)piVar4 + 6) != 0)) &&
       (*(ushort *)((int)piVar4 + 6) = *(short *)((int)piVar4 + 6) - (ushort)framesThisStep,
       *(short *)((int)piVar4 + 6) < 1)) {
      *(undefined2 *)((int)piVar4 + 6) = 0;
      *(undefined *)(piVar4 + 3) = 0;
    }
    if (((*(char *)(piVar4 + 3) != '\0') && (*(short *)(piVar4 + 1) < 1)) &&
       (*(char *)((int)piVar4 + 0xd) != '\0')) {
      *(undefined *)((int)piVar4 + 0xd) = 0;
      audioTryStartSfx((int *)this,1,0x424,0x7f,"torch.c",0xb1);
    }
    if (*(char *)(piVar4 + 3) != *(char *)((int)piVar4 + 0xe)) {
      if (*(char *)(piVar4 + 3) == '\0') {
        FUN_80068a9c((uint)this,0x7f);
                    /* {@symbol 800e2b88} */
        (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        if ((*piVar4 != -1) && (uVar2 = mainGetBit(*piVar4), uVar2 != 0)) {
          mainSetBits(*piVar4,0);
        }
        if ((DAT_80399f38 == '\x01') && (*(char *)((int)piVar4 + 0xf) == '\0')) {
          DAT_80399f38 = '\0';
        }
        if ((DAT_80399f38 == '\x02') && (*(char *)((int)piVar4 + 0xf) == '\x01')) {
          DAT_80399f38 = '\0';
        }
        if (((DAT_80399f38 == '\x03') && (*(char *)((int)piVar4 + 0xf) == '\x02')) &&
           (uVar2 = mainGetBit(0x474), uVar2 == 0)) {
          mainSetBits(0x472,0);
          DAT_80399f38 = '\0';
        }
      }
      else {
        dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
        local_30 = (uint)*(byte *)((int)piVar4 + 0xf) * 2 + 0x19d;
        local_2c = (uint)*(byte *)((int)piVar4 + 0xf) * 2 + 0x19e;
        (**(code **)(dll->id + 4))(this,1,auStack_4c,&DAT_00010004,0xffffffff,&local_34);
        DLL_free(dll);
        for (iVar1 = 0; iVar1 < 200; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a3,0,0,0xffffffff,0);
        }
        if ((*piVar4 != -1) && (uVar2 = mainGetBit(*piVar4), uVar2 == 0)) {
          mainSetBits(*piVar4,1);
        }
        if (((DAT_80399f38 == '\0') && (*(char *)((int)piVar4 + 0xf) == '\0')) &&
           (uVar2 = mainGetBit(*piVar4), uVar2 != 0)) {
          DAT_80399f38 = '\x01';
        }
        if (((DAT_80399f38 == '\x01') && (*(char *)((int)piVar4 + 0xf) == '\x01')) &&
           (uVar2 = mainGetBit(*piVar4), uVar2 != 0)) {
          DAT_80399f38 = '\x02';
        }
        if (((DAT_80399f38 == '\x02') && (*(char *)((int)piVar4 + 0xf) == '\x02')) &&
           (uVar2 = mainGetBit(*piVar4), uVar2 != 0)) {
          mainSetBits(0x472,1);
          DAT_80399f38 = '\x03';
        }
        *(undefined *)((int)piVar4 + 0xd) = 1;
        *(undefined2 *)(piVar4 + 1) = 1;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void torch1CD_hitDetect(ObjInstance *this) { //80245A38
  return;
}


/* Library Function - Single Match
    dll_1CD_func06
   
   Library: KioskDefault 0 0 */

void torch1CD_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80245A3C
  float fVar1;
  bool bVar4;
  Camera *pCVar2;
  int iVar3;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar5;
  double dVar6;
  undefined auStack_70 [12];
  float local_64;
  float local_60;
  float local_5c;
  vec3f local_58;
  vec3f local_4c;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 auStack_34 [2];
  vec3s vStack_2c;
  vec3s avStack_24 [2];
  
  puVar5 = this->state;
  if (shouldRender) {
    bVar4 = checkSomeDebugFlags_8017c4f8();
    if (bVar4) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    if (puVar5[0xc] != '\0') {
      puVar5[10] = 1;
      pCVar2 = getCurCamera();
      local_40 = (pCVar2->pos).x - (this->pos).pos.x;
      local_3c = (pCVar2->pos).y - (this->pos).pos.y;
      local_38 = (pCVar2->pos).z - (this->pos).pos.z;
      dVar6 = sqrt((double)(local_38 * local_38 + local_40 * local_40 + local_3c * local_3c));
      if (50.0 < dVar6) {
        fVar1 = (float)(1.0 / dVar6);
        local_40 = local_40 * fVar1;
        local_3c = local_3c * fVar1;
        local_38 = local_38 * fVar1;
        local_4c.x = local_40 * 32.0 + (this->pos).pos.x;
        local_4c.y = local_3c * 32.0 + (this->pos).pos.y;
        local_4c.z = local_38 * 32.0 + (this->pos).pos.z;
        local_58.x = local_40 * -20.0 + (pCVar2->pos).x;
        local_58.y = local_3c * -20.0 + (pCVar2->pos).y;
        local_58.z = local_38 * -20.0 + (pCVar2->pos).z;
        vec3f_toNearest10(&local_4c,avStack_24);
        vec3f_toNearest10(&local_58,&vStack_2c);
        iVar3 = FUN_8006dd10((undefined4 *)avStack_24,(undefined4 *)&vStack_2c,auStack_34,
                             (undefined *)0x0,'\0');
        if (iVar3 == 0) {
          puVar5[10] = 0;
                    /* {@symbol 800dc1d4} */
          (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        }
      }
      if (*(short *)(puVar5 + 4) < 1) {
        if (puVar5[10] != '\0') {
          local_64 = 0.0;
          local_60 = 5.0;
          local_5c = 0.0;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1f7,auStack_70,0x12,0xffffffff,0);
        }
        iVar3 = randInt(-10,10);
        *(short *)(puVar5 + 4) = (short)iVar3 + 0x3c;
      }
      else {
        *(ushort *)(puVar5 + 4) = *(short *)(puVar5 + 4) - (ushort)framesThisStep;
      }
    }
  }
  else {
    *(undefined2 *)(puVar5 + 4) = 0;
    puVar5[10] = 0;
  }
  return;
}


/* @description Free object instance */

void torch1CD_free(ObjInstance *this,int param2) { //80245D18
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 torch1CD_func08(ObjInstance *this) { //80245D70
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int torch1CD_getExtraSize(void) { //80245D78
  return 0x10;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void torch1D9_initialise(undefined4 param) { //8024AEBC
  return;
}


/* @description Called when DLL is unloaded */

void torch1D9_release(void) { //8024AEC0
  return;
}


/* Library Function - Single Match
    dll_1D9_func03
   
   Library: KioskDefault 0 0 */

void torch1D9_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8024AEC4
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  bool bVar7;
  DLL_func **ppDVar6;
  int *piVar8;
  undefined auStack_34 [16];
  float local_24;
  undefined4 local_18;
  uint uStack_14;
  
  piVar8 = (int *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 10);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 < 1) {
    (this->pos).scale = 0.1;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uStack_14 = (int)sVar2 ^ 0x80000000;
    local_18 = 0x43300000;
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 8192.0;
  }
  *(undefined *)((int)piVar8 + 0xb) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined *)(piVar8 + 3) = 0;
  *(undefined *)((int)piVar8 + 0xf) = 0;
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  *piVar8 = (int)sVar3;
  bVar7 = checkSomeDebugFlags_8017c4f8();
  if (!bVar7) {
    local_24 = -2.0;
    if (*(char *)((int)piVar8 + 0xb) == '\x01') {
      uVar5._0_1_ = objDef[1].loadFlags;
      uVar5._1_1_ = objDef[1].mapStates2;
      *(char *)((int)piVar8 + 0xf) = (char)uVar5;
      *(undefined *)((int)piVar8 + 0xd) = 0;
      *(ushort *)(piVar8 + 2) = (ushort)*(byte *)((int)piVar8 + 0xf) * 0x28 + 0x398;
      *(undefined *)((int)piVar8 + 0xe) = 0;
    }
    else if ((*(char *)((int)piVar8 + 0xb) == '\0') && (true)) {
      *(undefined *)(piVar8 + 3) = 1;
      ppDVar6 = runlinkDownloadCode(0x1011,1);
      sVar4._0_1_ = objDef[1].loadFlags;
      sVar4._1_1_ = objDef[1].mapStates2;
      if (sVar4 == 0) {
        (**(code **)(*ppDVar6 + 4))(this,0,auStack_34,&DAT_00010004,0xffffffff,0);
      }
    }
  }
  *(undefined2 *)(piVar8 + 1) = 0;
  return;
}


/* Library Function - Single Match
    dll_1D9_func04
   
   Library: KioskDefault 0 0 */

void dll_WGSH_Torch_update(ObjInstance *this) { //8024B048
  int iVar1;
  LoadedDll *dll;
  uint uVar2;
  int *piVar3;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined auStack_34 [16];
  float local_24;
  
  piVar3 = (int *)this->state;
  local_44 = 999;
  local_40 = 0x8c;
  local_3c = 0x8d;
  local_38 = 0x28;
  audioTryStartSfx((int *)this,0x40,300,0x7f,"torch.c",0x6d);
  objUpdateOpacity(this);
  if (0 < *(short *)(piVar3 + 2)) {
    *(ushort *)(piVar3 + 2) = *(short *)(piVar3 + 2) - (ushort)framesThisStep;
  }
  if (*(char *)((int)piVar3 + 0xb) == '\x01') {
    local_24 = -2.0;
    *(undefined *)((int)piVar3 + 0xe) = *(undefined *)(piVar3 + 3);
    iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if ((iVar1 != 0) || ((*(short *)(piVar3 + 2) != 0 && (*(short *)(piVar3 + 2) < 0x15)))) {
      *(char *)(piVar3 + 3) = '\x01' - *(char *)(piVar3 + 3);
      if (*(char *)(piVar3 + 3) != '\0') {
        *(undefined2 *)((int)piVar3 + 6) = 1000;
      }
      if (*(short *)(piVar3 + 2) != 0) {
        *(undefined2 *)(piVar3 + 2) = 0;
        DAT_80399f70 = '\x03';
        *(undefined2 *)((int)piVar3 + 6) = 300;
        if (*(char *)((int)piVar3 + 0xf) == '\x02') {
          mainSetBits(0x1d1,1);
        }
      }
    }
    if (((*(char *)(piVar3 + 3) != '\0') && (*(short *)((int)piVar3 + 6) != 0)) &&
       (*(ushort *)((int)piVar3 + 6) = *(short *)((int)piVar3 + 6) - (ushort)framesThisStep,
       *(short *)((int)piVar3 + 6) < 1)) {
      *(undefined2 *)((int)piVar3 + 6) = 0;
      *(undefined *)(piVar3 + 3) = 0;
    }
    if (((*(char *)(piVar3 + 3) != '\0') && (*(short *)(piVar3 + 1) < 1)) &&
       (*(char *)((int)piVar3 + 0xd) != '\0')) {
      *(undefined *)((int)piVar3 + 0xd) = 0;
      audioTryStartSfx((int *)this,1,0x37,0x7f,"torch.c",0x90);
    }
    if (*(char *)(piVar3 + 3) != *(char *)((int)piVar3 + 0xe)) {
      if (*(char *)(piVar3 + 3) == '\0') {
        FUN_80068a9c((uint)this,0x40);
                    /* {@symbol 800e2b88} */
        (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        if ((*piVar3 != -1) && (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          mainSetBits(*piVar3,0);
        }
        if ((DAT_80399f70 == '\x01') && (*(char *)((int)piVar3 + 0xf) == '\0')) {
          DAT_80399f70 = '\0';
        }
        if ((DAT_80399f70 == '\x02') && (*(char *)((int)piVar3 + 0xf) == '\x01')) {
          DAT_80399f70 = '\0';
        }
        if (((DAT_80399f70 == '\x03') && (*(char *)((int)piVar3 + 0xf) == '\x02')) &&
           (uVar2 = mainGetBit(0x1d5), uVar2 == 0)) {
          mainSetBits(0x1d1,0);
          DAT_80399f70 = '\0';
        }
      }
      else {
        dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
        local_40 = (uint)*(byte *)((int)piVar3 + 0xf) * 2 + 0x19d;
        local_3c = (uint)*(byte *)((int)piVar3 + 0xf) * 2 + 0x19e;
        (**(code **)(dll->id + 4))(this,1,auStack_34,&DAT_00010004,0xffffffff,&local_44);
        DLL_free(dll);
        for (iVar1 = 0; iVar1 < 100; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a3,0,0,0xffffffff,0);
        }
        if (*piVar3 != -1) {
          uVar2 = mainGetBit(*piVar3);
          if (uVar2 == 0) {
            mainSetBits(*piVar3,1);
          }
        }
        if (((DAT_80399f70 == '\0') && (*(char *)((int)piVar3 + 0xf) == '\0')) &&
           (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          DAT_80399f70 = '\x01';
        }
        if (((DAT_80399f70 == '\x01') && (*(char *)((int)piVar3 + 0xf) == '\x01')) &&
           (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          DAT_80399f70 = '\x02';
        }
        if (((DAT_80399f70 == '\x02') && (*(char *)((int)piVar3 + 0xf) == '\x02')) &&
           (uVar2 = mainGetBit(*piVar3), uVar2 != 0)) {
          mainSetBits(0x1d1,1);
          DAT_80399f70 = '\x03';
        }
        *(undefined *)((int)piVar3 + 0xd) = 1;
        *(undefined2 *)(piVar3 + 1) = 1;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void torch1D9_hitDetect(ObjInstance *this) { //8024B4A0
  return;
}


/* Library Function - Single Match
    dll_1D9_func06
   
   Library: KioskDefault 0 0 */

void dll_WGSH_Torch_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8024B4A4
  float fVar1;
  Camera *pCVar2;
  int iVar3;
  undefined *puVar4;
  double dVar5;
  undefined auStack_70 [12];
  float local_64;
  float local_60;
  float local_5c;
  vec3f local_58;
  vec3f local_4c;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 auStack_34 [2];
  vec3s vStack_2c;
  vec3s avStack_24 [2];
  
  puVar4 = this->state;
  if (shouldRender) {
    if (puVar4[0xc] != '\0') {
      puVar4[10] = 1;
      pCVar2 = getCurCamera();
      local_40 = (pCVar2->pos).x - (this->pos).pos.x;
      local_3c = (pCVar2->pos).y - (this->pos).pos.y;
      local_38 = (pCVar2->pos).z - (this->pos).pos.z;
      dVar5 = sqrt((double)(local_38 * local_38 + local_40 * local_40 + local_3c * local_3c));
      if (50.0 < dVar5) {
        fVar1 = (float)(1.0 / dVar5);
        local_40 = local_40 * fVar1;
        local_3c = local_3c * fVar1;
        local_38 = local_38 * fVar1;
        local_4c.x = local_40 * 32.0 + (this->pos).pos.x;
        local_4c.y = local_3c * 32.0 + (this->pos).pos.y;
        local_4c.z = local_38 * 32.0 + (this->pos).pos.z;
        local_58.x = local_40 * -20.0 + (pCVar2->pos).x;
        local_58.y = local_3c * -20.0 + (pCVar2->pos).y;
        local_58.z = local_38 * -20.0 + (pCVar2->pos).z;
        vec3f_toNearest10(&local_4c,avStack_24);
        vec3f_toNearest10(&local_58,&vStack_2c);
        iVar3 = FUN_8006dd10((undefined4 *)avStack_24,(undefined4 *)&vStack_2c,auStack_34,
                             (undefined *)0x0,'\0');
        if (iVar3 == 0) {
          puVar4[10] = 0;
                    /* {@symbol 800dc1d4} */
          (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        }
      }
      if (*(short *)(puVar4 + 4) < 1) {
        if (puVar4[10] != '\0') {
          local_64 = 0.0;
          local_60 = 5.0;
          local_5c = 0.0;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1f7,auStack_70,0x12,0xffffffff,0);
        }
        iVar3 = randInt(-10,10);
        *(short *)(puVar4 + 4) = (short)iVar3 + 0x3c;
      }
      else {
        *(ushort *)(puVar4 + 4) = *(short *)(puVar4 + 4) - (ushort)framesThisStep;
      }
    }
  }
  else {
    *(undefined2 *)(puVar4 + 4) = 0;
    puVar4[10] = 0;
  }
  return;
}


/* @description Free object instance */

void torch1D9_free(ObjInstance *this,int param2) { //8024B748
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 torch1D9_func08(ObjInstance *this) { //8024B7A0
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int torch1D9_getExtraSize(void) { //8024B7A8
  return 0x10;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void torch246_initialise(undefined4 param) { //80282870
  return;
}


/* @description Called when DLL is unloaded */

void torch246_release(void) { //80282874
  return;
}


/* Library Function - Single Match
    dll_246_func03
   
   Library: KioskDefault 0 0 */

void WM_Torch_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //80282878
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  LoadedDll *dll;
  undefined *puVar5;
  undefined auStack_34 [16];
  float local_24;
  undefined4 local_18;
  uint uStack_14;
  
  puVar5 = this->state;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 == 0) {
    *(float *)(puVar5 + 4) = 75.0;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uStack_14 = (int)sVar2 ^ 0x80000000;
    local_18 = 0x43300000;
    *(float *)(puVar5 + 4) = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0);
  }
  sVar3._0_1_ = objDef[1].loadFlags;
  sVar3._1_1_ = objDef[1].mapStates2;
  if (sVar3 == 0) {
    *(undefined2 *)(puVar5 + 10) = 0x8c;
  }
  else {
    *(undefined2 *)(puVar5 + 10) = *(undefined2 *)&objDef[1].loadFlags;
  }
  bVar4 = checkSomeDebugFlags_8017c4f8();
  if (!bVar4) {
    puVar5[0xc] = *(undefined *)((int)&objDef[1].objType + 1);
    local_24 = -2.0;
    if (puVar5[0xc] == '\0') {
      dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
      (this->pos).scale = (this->pos).scale * 0.5;
      (**(code **)((DLL_func *)dll->id + 4))(this,1,auStack_34,&DAT_00010004,0xffffffff,0);
    }
    else if (puVar5[0xc] == '\x7f') {
      dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
      (this->pos).scale = (this->pos).scale * 0.5;
      (**(code **)((DLL_func *)dll->id + 4))(this,2,auStack_34,&DAT_00010004,0xffffffff,0);
    }
    else {
      dll = (LoadedDll *)runlinkDownloadCode(0x100b,1);
      (this->pos).scale = (this->pos).scale * 0.5;
      (**(code **)((DLL_func *)dll->id + 4))(this,2,auStack_34,&DAT_00010004,0xffffffff,0);
    }
    (this->pos).scale = (this->pos).scale * 2.0;
    DLL_free(dll);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_246_func04
   
   Library: KioskDefault 0 0 */

void torch246_update(ObjInstance *this) { //80282A48
  ObjInstance *param1;
  u32 uVar1;
  BOOL BVar2;
  undefined *puVar3;
  double in_f1;
  double dVar4;
  double z;
  double y;
  double x;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  undefined auStack_50 [12];
  float local_44;
  float local_40;
  float local_3c;
  
  _savefpr_27();
  puVar3 = this->state;
  if (puVar3[0xc] == '\x02') {
    (this->pos).rotation.x = (this->pos).rotation.x + 0x32;
  }
  param1 = Object_objGetMain();
  objDistObj2Obj(param1,this);
  if (90.0 <= in_f1) {
    FUN_80068a9c((uint)this,0x40);
  }
  else {
    audioTryStartSfx((int *)this,0x40,300,0x7f,"torch.c",0x8c);
  }
  if (puVar3[0xc] != '\x02') {
    x = (double)((this->pos).pos.x - playerMapOffsetX);
    y = (double)(this->pos).pos.y;
    z = (double)((this->pos).pos.z - playerMapOffsetZ);
    vecMultByPerspectiveMtx(x,y,z,&local_60,&local_64,&local_68);
    viewportCoordsToPixel
              ((double)local_60,(double)local_64,(double)local_68,(int *)&local_54,(int *)&local_58,
               (int *)0x0);
    uVar1 = gxGetPixel_(local_54,local_58);
    FUN_8006abcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 &local_6c,&local_70,&local_74);
    dVar4 = (double)(-0.75 / local_68);
    vecMultByPerspectiveMtx
              ((double)(float)((double)local_6c * dVar4 + x),
               (double)(float)((double)local_70 * dVar4 + y),
               (double)(float)((double)local_74 * dVar4 + z),&local_60,&local_64,&local_68);
    viewportCoordsToPixel
              ((double)local_60,(double)local_64,(double)local_68,(int *)0x0,(int *)0x0,&local_5c);
    if (*(short *)(puVar3 + 8) < 1) {
      BVar2 = isPixelOnScreen(local_54,local_58);
      if (((BVar2 != FALSE) && (0 < local_5c)) && (local_5c < (int)uVar1)) {
        local_44 = 0.0;
        local_40 = 13.0;
        local_3c = 0.0;
        if (puVar3[0xc] == '\x7f') {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x741,auStack_50,0x12,0xffffffff,0);
        }
        else {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1f7,auStack_50,0x12,0xffffffff,0);
        }
      }
      *(undefined2 *)(puVar3 + 8) = 0x3c;
    }
    else {
      *(ushort *)(puVar3 + 8) = *(short *)(puVar3 + 8) - (ushort)framesThisStep;
    }
  }
  _restfpr_27();
  return;
}


/* @description Override hit detection */

void torch246_hitDetect(ObjInstance *this) { //80282CB0
  return;
}


/* @description Override render */

void torch246_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80282CB4
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (bVar1 = checkSomeDebugFlags_8017c4f8(), bVar1)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_246_func07
   
   Library: KioskDefault 0 0 */

void WM_Torch_free(ObjInstance *this,int param2) { //80282D1C
  if ((param2 == 0) && (*(ObjInstance **)this->state != (ObjInstance *)0x0)) {
    Object_objFreeObject(*(ObjInstance **)this->state);
  }
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
  return;
}


undefined4 torch246_func08(ObjInstance *this) { //80282D9C
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int torch246_getExtraSize(void) { //80282DA4
  return 0x10;
}

