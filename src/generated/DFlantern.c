
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFlantern_initialise(undefined4 param) { //8023AFD0
  return;
}


/* @description Called when DLL is unloaded */

void DFlantern_release(void) { //8023AFD4
  return;
}


/* Library Function - Single Match
    dll_19B_func03
   
   Library: KioskDefault 0 0 */

void DFlantern_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8023AFD8
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  *(byte *)(puVar1 + 5) = objDef[1].mapStates1;
  *(undefined *)((int)puVar1 + 0xb) = 0;
  if (*(char *)(puVar1 + 5) == '\0') {
    *puVar1 = 0x1ea;
    puVar1[1] = 0x1eb;
    puVar1[3] = 100;
    puVar1[4] = 0xfa;
  }
  else {
    *puVar1 = 0x1ec;
    puVar1[1] = 0x1ed;
    puVar1[3] = 100;
    puVar1[4] = 0xfa;
  }
  if ((*(byte *)((int)&objDef[1].pos.x + 3) & 0x20) != 0) {
    puVar1[4] = (short)(int)this->camDistVar40;
  }
  (this->pos).scale = *(float *)&objDef[1].loadFlags;
  (this->pos).rotation.z = (*(byte *)&objDef[1].objType - 0x7f) * 0x100;
  (this->pos).rotation.y = (*(byte *)((int)&objDef[1].objType + 1) - 0x7f) * 0x100;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  if ((*(byte *)((int)&objDef[1].pos.x + 3) & 1) != 0) {
    *(byte *)((int)puVar1 + 0xb) = *(byte *)((int)puVar1 + 0xb) | 1;
  }
  if ((*(byte *)((int)puVar1 + 0xb) & 1) == 0) {
    FUN_80088d3c((int)this);
  }
  else {
    FUN_80088da4((int)this);
  }
  return;
}


/* Library Function - Single Match
    dll_19B_func04
   
   Library: KioskDefault 0 0 */

void DFlantern_update(ObjInstance *this) { //8023B104
  bool bVar6;
  int iVar1;
  Camera *pCVar2;
  ObjInstance *pOVar3;
  u32 uVar4;
  BOOL BVar5;
  ObjDef *pOVar7;
  ushort *puVar8;
  double dVar9;
  double z;
  double y;
  double x;
  int local_7c;
  uint local_78;
  uint local_74;
  float local_70;
  float local_6c;
  float local_68 [2];
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  longlong local_50;
  longlong local_48;
  
  _savefpr_27();
  puVar8 = (ushort *)this->state;
  pOVar7 = this->def;
  bVar6 = checkSomeDebugFlags_8017c4f8();
  if (!bVar6) {
    *(byte *)((int)puVar8 + 0xb) = *(byte *)((int)puVar8 + 0xb) & 0xf1;
                    /* {@symbol 800d2604} */
    iVar1 = (**(code **)(*(int *)pDll_newfog + 0x24))(local_68);
    if ((iVar1 != 0) || ((*(byte *)((int)&pOVar7[1].pos.x + 3) & 0x10) != 0)) {
      pCVar2 = getCurCamera();
      local_68[0] = (this->pos).pos.x - (pCVar2->pos).x;
      local_6c = (this->pos).pos.y - (pCVar2->pos).y;
      local_70 = (this->pos).pos.z - (pCVar2->pos).z;
      dVar9 = sqrt((double)(local_70 * local_70 + local_68[0] * local_68[0] + local_6c * local_6c));
      local_48 = (longlong)(int)dVar9;
      puVar8[2] = (ushort)(int)dVar9;
      pOVar3 = Object_objGetMain();
      local_68[0] = (this->pos).pos.x - (pOVar3->pos).pos.x;
      local_70 = (this->pos).pos.z - (pOVar3->pos).pos.z;
      dVar9 = sqrt((double)(local_68[0] * local_68[0] + local_70 * local_70));
      local_50 = (longlong)(int)dVar9;
      uStack_54 = (int)dVar9 & 0xffff;
      local_58 = 0x43300000;
      uStack_5c = (uint)puVar8[3];
      local_60 = 0x43300000;
      if ((float)((double)CONCAT44(0x43300000,uStack_54) - 4503599627370496.0) <
          (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
        *(byte *)((int)puVar8 + 0xb) = *(byte *)((int)puVar8 + 0xb) | 10;
      }
      if (puVar8[2] < puVar8[4]) {
        *(byte *)((int)puVar8 + 0xb) = *(byte *)((int)puVar8 + 0xb) | 8;
        x = (double)((this->pos).pos.x - playerMapOffsetX);
        y = (double)(this->pos).pos.y;
        z = (double)((this->pos).pos.z - playerMapOffsetZ);
        vecMultByPerspectiveMtx(x,y,z,local_68,&local_6c,&local_70);
        viewportCoordsToPixel
                  ((double)local_68[0],(double)local_6c,(double)local_70,(int *)&local_74,
                   (int *)&local_78,(int *)0x0);
        uVar4 = gxGetPixel_(local_74,local_78);
        dVar9 = (double)(-0.75 / local_70);
        FUN_8006abcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                     local_68,&local_6c,&local_70);
        vecMultByPerspectiveMtx
                  ((double)(float)((double)local_68[0] * dVar9 + x),
                   (double)(float)((double)local_6c * dVar9 + y),
                   (double)(float)((double)local_70 * dVar9 + z),local_68,&local_6c,&local_70);
        viewportCoordsToPixel
                  ((double)local_68[0],(double)local_6c,(double)local_70,(int *)0x0,(int *)0x0,
                   &local_7c);
        BVar5 = isPixelOnScreen(local_74,local_78);
        if (((BVar5 != FALSE) && (0 < local_7c)) && (local_7c < (int)uVar4)) {
          *(byte *)((int)puVar8 + 0xb) = *(byte *)((int)puVar8 + 0xb) | 4;
        }
      }
    }
    if (*(char *)((int)puVar8 + 0xb) != *(char *)(puVar8 + 6)) {
      if (((*(byte *)((int)puVar8 + 0xb) & 2) == 0) || ((*(byte *)(puVar8 + 6) & 2) != 0)) {
        if (((*(byte *)((int)puVar8 + 0xb) & 2) == 0) && ((*(byte *)(puVar8 + 6) & 2) != 0)) {
          loadLfxAction(this,this,puVar8[1]);
        }
      }
      else {
        loadLfxAction(this,this,*puVar8);
      }
      if (((*(byte *)((int)puVar8 + 0xb) & 8) == 0) || ((*(byte *)(puVar8 + 6) & 8) != 0)) {
        if (((*(byte *)((int)puVar8 + 0xb) & 8) == 0) && ((*(byte *)(puVar8 + 6) & 8) != 0)) {
          FUN_80068a9c((uint)this,0x40);
        }
      }
      else {
        audioTryStartSfx((int *)this,0x40,0x231,0x7f,"DFlantern.c",0xb8);
      }
    }
    *(undefined *)(puVar8 + 6) = *(undefined *)((int)puVar8 + 0xb);
  }
  _restfpr_27();
  return;
}


/* @description Override hit detection */

void DFlantern_hitDetect(ObjInstance *this) { //8023B4BC
  return;
}


/* Library Function - Single Match
    dll_19B_func06
   
   Library: KioskDefault 0 0 */

void DFlantern_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8023B4C0
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  ushort local_2a;
  longlong local_28;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar3 = this->state;
  if (shouldRender) {
    iVar1 = FUN_8018d744();
    if ((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) {
      if (((this->pos).flags & 0x100) != 0) {
        uStack_14 = (uint)*(ushort *)(puVar3 + 6);
        local_18 = 0x43300000;
        FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                     (double)(float)((double)CONCAT44(0x43300000,uStack_14) - 4503599627370496.0),
                     32.0,param2_00,param3_00,0xff,0,0);
        uStack_1c = (uint)*(ushort *)(puVar3 + 8);
        local_20 = 0x43300000;
        FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                     (double)(float)((double)CONCAT44(0x43300000,uStack_1c) - 4503599627370496.0),
                     32.0,param2_00,param3_00,0,0,0xff);
      }
      objRenderCurrentModel
                (this,(Gfx **)param2_00,param3_00,
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    bVar2 = checkSomeDebugFlags_8017c4f8();
    if ((!bVar2) && ((puVar3[0xb] & 4) != 0)) {
      uStack_1c = (uint)*(ushort *)(puVar3 + 4);
      local_20 = 0x43300000;
      uStack_14 = (uint)*(ushort *)(puVar3 + 8);
      local_18 = 0x43300000;
      iVar1 = (int)((1.0 - (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503599627370496.0) /
                           (float)((double)CONCAT44(0x43300000,uStack_14) - 4503599627370496.0)) *
                   512.0);
      local_28 = (longlong)iVar1;
      local_2a = (ushort)iVar1;
      if (0xff < local_2a) {
        local_2a = 0xff;
      }
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x42b,0,0x12,0xffffffff,&local_2a);
    }
    return;
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19B_func07
    dll_1F8_func07
   
   Library: KioskDefault 0 0 */

void DFlantern_free(ObjInstance *this,int param2) { //8023B688
  if ((this->state[0xb] & 2) != 0) {
    loadLfxAction(this,this,*(ushort *)(this->state + 2));
  }
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 DFlantern_func08(ObjInstance *this) { //8023B6F4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DFlantern_getExtraSize(void) { //8023B6FC
  return 0xe;
}

