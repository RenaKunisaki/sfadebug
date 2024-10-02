
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void cannonball_initialise(undefined4 param) { //801CB904
  return;
}


/* @description Called when DLL is unloaded */

void cannonball_release(void) { //801CB908
  return;
}


/* @description Set up object instance */

void cannonball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801CB90C
  return;
}


/* Library Function - Single Match
    dll_E8_func04
   
   Library: KioskDefault 0 0 */

void cannonball_update(ObjInstance *this) { //801CB910
  int iVar1;
  uint uVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  if (this->flags_0xf8 == 1) {
    this->hitstate->field15_0x50 = 8;
    (this->vel).y = -(timeDelta * 0.07 - (this->vel).y);
    (this->vel).y = (this->vel).y * 0.97;
  }
  (this->oldPos).x = (this->pos).pos.x;
  (this->oldPos).y = (this->pos).pos.y;
  (this->oldPos).z = (this->pos).pos.z;
  (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
  (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
  (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
  this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
  if ((int)this->field76_0xf4 < 0) {
    Object_objFreeObject(this);
  }
  if (0xf < *psVar3) {
    objHitFn_80089074(this,5,1,0);
  }
  if ((this->flags_0xf8 == 1) && (this->hitstate->field54_0x9d != 0)) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,6,0,1,0xffffffff,0);
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x1f1,0x7f,"cannonball.c",(int *)0x47);
    Object_objFreeObject(this);
    if (this->flags_0xf8 == 1) {
      iVar1 = (int)((this->pos).pos.x - playerMapOffsetX);
      if ((iVar1 < 0x7fff) && (-0x8000 < iVar1)) {
        uVar2 = (uint)((this->pos).pos.z - playerMapOffsetZ);
        if (((int)uVar2 < 0x7fff) && (-0x8000 < (int)uVar2)) {
          FUN_80090ef4(0x1d,0,this,0xd0004,uVar2 & 0xffff | iVar1 << 0x10);
        }
      }
    }
  }
  *psVar3 = *psVar3 + (ushort)framesThisStep;
  return;
}


/* @description Override hit detection */

void cannonball_hitDetect(ObjInstance *this) { //801CBB18
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void cannonball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801CBB1C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void cannonball_free(ObjInstance *this,int param2) { //801CBB78
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 cannonball_func08(ObjInstance *this) { //801CBBB0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int cannonball_getExtraSize(void) { //801CBBB8
  return 2;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBcannonball_initialise(undefined4 param) { //80263A94
  return;
}


/* @description Called when DLL is unloaded */

void SBcannonball_release(void) { //80263A98
  return;
}


/* Library Function - Single Match
    dll_22F_func03
   
   Library: KioskDefault 0 0 */

void SBcannonball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80263A9C
  bool bVar1;
  LoadedDll *dll;
  
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if (!bVar1) {
    dll = (LoadedDll *)runlinkDownloadCode(0x1021,1);
    (**(code **)(dll->id + 4))(this,1,0,&DAT_00010002,0xffffffff,0);
    (**(code **)(dll->id + 4))(this,1,0,&DAT_00010002,0xffffffff,0);
    DLL_free(dll);
  }
  this->hitstate->flags = this->hitstate->flags & 0xfffe;
  (this->pos).scale = (this->pos).scale * 0.0125;
  return;
}


/* Library Function - Single Match
    dll_22F_func04
   
   Library: KioskDefault 0 0 */

void SBcannonball_update(ObjInstance *this) { //80263B68
  ushort uVar2;
  ObjDef *def;
  ObjInstance *pOVar1;
  int iVar3;
  uint uVar4;
  dword *pdVar5;
  double dVar6;
  double dVar7;
  undefined auStack_74 [4];
  float local_70;
  undefined local_6c;
  float local_68;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_25();
  local_68 = 0.0;
  local_6c = 0;
  pdVar5 = (dword *)this->state;
  if (*pdVar5 == 0) {
    *pdVar5 = this->flags_0xf8;
  }
  if (*pdVar5 != 0) {
    (this->pos).rotation.z = (this->pos).rotation.z + 0x2134;
    (this->oldPos).x = (this->pos).pos.x;
    (this->oldPos).y = (this->pos).pos.y;
    (this->oldPos).z = (this->pos).pos.z;
    uVar2 = (**(code **)(**(int **)(*pdVar5 + 0x68) + 0x28))(*pdVar5);
    (**(code **)(**(int **)(*pdVar5 + 0x68) + 0x2c))(*pdVar5,&local_70,auStack_74);
    if (*(char *)((int)pdVar5 + 0x32) == '\0') {
      pdVar5[2] = (dword)(this->vel).x;
      pdVar5[3] = (dword)(this->vel).y;
      pdVar5[4] = (dword)(this->vel).z;
      *(undefined *)((int)pdVar5 + 0x32) = 1;
      pdVar5[5] = (dword)(this->pos).pos.x;
      pdVar5[6] = (dword)(this->pos).pos.y;
      pdVar5[7] = (dword)(this->pos).pos.z;
      *(ushort *)((int)pdVar5 + 0x2e) = uVar2;
      pdVar5[8] = (dword)0.0;
      pdVar5[9] = (dword)0.0;
      pdVar5[10] = (dword)0.0;
      *(short *)(pdVar5 + 0xc) = (this->pos).rotation.x;
    }
    if (pdVar5[1] == 0) {
      def = objAlloc(0x28,LFXEmitter);
      def->bound = 0xff;
      def->cullDist = 0xff;
      (def->pos).x = (this->pos).pos.x;
      (def->pos).y = (this->pos).pos.y;
      (def->pos).z = (this->pos).pos.z;
      *(undefined2 *)&def[1].pos.x = 3000;
      def[1].bound = 1;
      def[1].cullDist = 0x8f;
      *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
      def[1].objType = Sabre;
      def[1].allocatedSize = 0;
      def[1].mapStates1 = 0;
      def[1].loadFlags = 0;
      def[1].mapStates2 = 0;
      *(undefined *)&def[1].pos.y = 0;
      pOVar1 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
      pdVar5[1] = (dword)pOVar1;
    }
    pdVar5[5] = (dword)((float)pdVar5[2] * timeDelta + (float)pdVar5[5]);
    pdVar5[6] = (dword)((float)pdVar5[3] * timeDelta + (float)pdVar5[6]);
    pdVar5[7] = (dword)((float)pdVar5[4] * timeDelta + (float)pdVar5[7]);
    if (pdVar5[1] != 0) {
      *(dword *)(pdVar5[1] + 0xc) = pdVar5[5];
      *(dword *)(pdVar5[1] + 0x10) = pdVar5[6];
      *(dword *)(pdVar5[1] + 0x14) = pdVar5[7];
    }
    uVar4 = (int)*(short *)((int)pdVar5 + 0x2e) - (uint)uVar2;
    if (0x8000 < (int)uVar4) {
      uVar4 = uVar4 - 0xffff;
    }
    if ((int)uVar4 < -0x8000) {
      uVar4 = uVar4 + 0xffff;
    }
    uStack_54 = uVar4 ^ 0x80000000;
    local_58 = 0x43300000;
    dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_54) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    uStack_5c = uVar4 ^ 0x80000000;
    local_60 = 0x43300000;
    dVar7 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_5c) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    pdVar5[8] = (dword)((float)(dVar6 * 8.0 + -8.0) * timeDelta + (float)pdVar5[8]);
    pdVar5[10] = (dword)((float)(dVar7 * 8.0) * timeDelta + (float)pdVar5[10]);
    local_70 = local_70 * 0.25;
    pdVar5[8] = (dword)((float)((double)local_70 * dVar7) * timeDelta + (float)pdVar5[8]);
    pdVar5[10] = (dword)((float)((double)local_70 * dVar6) * timeDelta + (float)pdVar5[10]);
    (this->pos).pos.x = (float)pdVar5[5];
    (this->pos).pos.y = (float)pdVar5[6];
    (this->pos).pos.z = (float)pdVar5[7];
    (this->pos).rotation.x = *(short *)(pdVar5 + 0xc) - (short)uVar4;
    this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
    if ((int)this->field76_0xf4 < 0) {
      Object_objFreeObject(this);
    }
    iVar3 = 0;
    if (*(short *)(pdVar5 + 0xb) < 0x10) {
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
    }
    else {
      *(undefined *)((int)&this->hitstate->sizeX2 + 1) = 5;
      *(undefined *)&this->hitstate->flags_0x60 = 1;
      (this->hitstate->field12_0x3c).y = 2.242078e-44;
      (this->hitstate->field12_0x3c).z = 2.242078e-44;
      iVar3 = ret0_8008D09C();
      this->hitstate->flags = this->hitstate->flags | 1;
    }
    if (iVar3 != 0) {
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x1f1,0x7f,"cannonball.c",(int *)0xe3);
      Object_objFreeObject(this);
    }
    *(ushort *)(pdVar5 + 0xb) = *(short *)(pdVar5 + 0xb) + (ushort)framesThisStep;
    if ((int)*(short *)(pdVar5 + 0xb) - 0x50U < (uint)framesThisStep) {
      audioTryStartSfx((int *)this,0x40,0x1d6,0x7f,"cannonball.c",0xeb);
    }
  }
  _restfpr_25();
  return;
}


/* Library Function - Single Match
    dll_22F_func05
   
   Library: KioskDefault 0 0 */

void SBcannonball_hitDetect(ObjInstance *this) { //80264044
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  if (puVar2[0x33] == '\0') {
    iVar1 = this->hitstate->field13_0x48;
    if (iVar1 != 0) {
      if ((*(short *)(iVar1 + 0x46) != 0x119) && (puVar2[0x33] == '\0')) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x1f1,0x7f,"cannonball.c",
                            (int *)0x103);
        this->hitstate->flags = this->hitstate->flags & 0xfffe;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,0,1,0xffffffff,0);
        for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa9,0,1,0xffffffff,0);
        }
        puVar2[0x33] = 100;
        this->newOpacity = 0x19;
        FUN_80068a9c((uint)this,0x40);
      }
    }
  }
  else {
    puVar2[0x33] = puVar2[0x33] - framesThisStep;
    if ((char)puVar2[0x33] < '\x01') {
      Object_objFreeObject(this);
    }
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SBcannonball_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8026421C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_22F_func07
    dll_230_func07
    dll_2AC_func07
   
   Library: KioskDefault 0 0 */

void SBcannonball_free(ObjInstance *this,int param2) { //80264278
  undefined *puVar1;
  
  puVar1 = this->state;
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  if ((param2 == 0) && (*(int *)(puVar1 + 4) != 0)) {
    Object_objFreeObject(*(ObjInstance **)(puVar1 + 4));
    *(undefined4 *)(puVar1 + 4) = 0;
  }
  return;
}


undefined4 SBcannonball_func08(ObjInstance *this) { //80264300
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SBcannonball_getExtraSize(void) { //80264308
  return 0x34;
}

