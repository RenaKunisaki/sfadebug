
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBcloudball_initialise(undefined4 param) { //80264774
  return;
}


/* @description Called when DLL is unloaded */

void SBcloudball_release(void) { //80264778
  return;
}


/* Library Function - Single Match
    dll_230_func03
   
   Library: KioskDefault 0 0 */

void SBcloudball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8026477C
  undefined *puVar1;
  
  puVar1 = this->state;
  this->hitstate->flags = this->hitstate->flags & 0xfffe;
  *(undefined4 *)(puVar1 + 4) = 0;
  return;
}


/* Library Function - Single Match
    dll_230_func04
   
   Library: KioskDefault 0 0 */

void SBcloudball_update(ObjInstance *this) { //802647AC
  int *piVar1;
  undefined2 uVar4;
  ObjDef *def;
  ObjInstance *pOVar2;
  int iVar3;
  dword *pdVar5;
  undefined auStack_30 [4];
  undefined auStack_2c [4];
  undefined local_28;
  float local_24;
  
  local_24 = 0.0;
  local_28 = 0;
  pdVar5 = (dword *)this->state;
  if (*pdVar5 == 0) {
    *pdVar5 = this->flags_0xf8;
    piVar1 = (int *)(**(code **)(**(int **)(*pdVar5 + 0x68) + 0x24))(*pdVar5);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(this,0,0,&DAT_00010004,0xffffffff,0);
    }
  }
  if (*pdVar5 != 0) {
    (this->oldPos).x = (this->pos).pos.x;
    (this->oldPos).y = (this->pos).pos.y;
    (this->oldPos).z = (this->pos).pos.z;
    uVar4 = (**(code **)(**(int **)(*pdVar5 + 0x68) + 0x28))(*pdVar5);
    (**(code **)(**(int **)(*pdVar5 + 0x68) + 0x2c))(*pdVar5,auStack_2c,auStack_30);
    if (*(char *)(pdVar5 + 0xc) == '\0') {
      pdVar5[2] = (dword)(this->vel).x;
      pdVar5[3] = (dword)(this->vel).y;
      pdVar5[4] = (dword)(this->vel).z;
      *(undefined *)(pdVar5 + 0xc) = 1;
      pdVar5[5] = (dword)(this->pos).pos.x;
      pdVar5[6] = (dword)(this->pos).pos.y;
      pdVar5[7] = (dword)(this->pos).pos.z;
      *(undefined2 *)((int)pdVar5 + 0x2e) = uVar4;
      pdVar5[8] = *(dword *)(*pdVar5 + 0xc);
      pdVar5[9] = *(dword *)(*pdVar5 + 0x10);
      pdVar5[10] = *(dword *)(*pdVar5 + 0x14);
    }
    if (pdVar5[1] == 0) {
      def = objAlloc(0x28,LFXEmitter);
      def->loadFlags = isBlockObject;
      def->cullDist = 0xff;
      (def->pos).x = (this->pos).pos.x;
      (def->pos).y = (this->pos).pos.y;
      (def->pos).z = (this->pos).pos.z;
      *(undefined2 *)&def[1].pos.x = 2000;
      def[1].bound = 0;
      def[1].cullDist = 0x5e;
      *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
      def[1].objType = Sabre;
      def[1].allocatedSize = 0;
      def[1].mapStates1 = 0;
      def[1].loadFlags = 0;
      def[1].mapStates2 = 0;
      *(undefined *)&def[1].pos.y = 0;
      pOVar2 = objInstantiateCharacter
                         (def,5,(int)(char)this->mapId,-1,*(ObjInstance **)(*pdVar5 + 0x30));
      pdVar5[1] = (dword)pOVar2;
    }
    pdVar5[5] = (dword)((float)pdVar5[2] * timeDelta + (float)pdVar5[5]);
    pdVar5[6] = (dword)((float)pdVar5[3] * timeDelta + (float)pdVar5[6]);
    pdVar5[7] = (dword)((float)pdVar5[4] * timeDelta + (float)pdVar5[7]);
    (this->pos).pos.x = (float)pdVar5[5] + (*(float *)(*pdVar5 + 0xc) - (float)pdVar5[8]);
    (this->pos).pos.y = (float)pdVar5[6] + (*(float *)(*pdVar5 + 0x10) - (float)pdVar5[9]);
    (this->pos).pos.z = (float)pdVar5[7] + (*(float *)(*pdVar5 + 0x14) - (float)pdVar5[10]);
    *(float *)(pdVar5[1] + 0xc) = (this->pos).pos.x;
    *(float *)(pdVar5[1] + 0x10) = (this->pos).pos.y;
    *(float *)(pdVar5[1] + 0x14) = (this->pos).pos.z;
    this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
    if ((int)this->field76_0xf4 < 0) {
      Object_objFreeObject(this);
    }
    iVar3 = getAngle();
    (this->pos).rotation.x = (short)iVar3;
    (this->pos).rotation.x = (this->pos).rotation.x + 0x4000;
    iVar3 = getAngle();
    (this->pos).rotation.y = (short)iVar3;
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
                          (double)(this->prevPos).z,0x1f1,0x7f,(char *)&PTR_DAT_8031bec8,(int *)0xb3
                         );
      Object_objFreeObject(this);
    }
    *(ushort *)(pdVar5 + 0xb) = *(short *)(pdVar5 + 0xb) + (ushort)framesThisStep;
  }
  return;
}


/* Library Function - Single Match
    dll_230_func05
   
   Library: KioskDefault 0 0 */

void SBcloudball_hitDetect(ObjInstance *this) { //80264BDC
  int iVar1;
  
  iVar1 = 0x14;
  if (this->hitstate->field13_0x48 != 0) {
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x1f1,0x7f,(char *)&PTR_DAT_8031bec8,(int *)0xc3);
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa7,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa7,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa7,0,1,0xffffffff,0);
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0xaa,0,1,0xffffffff,0);
    }
    Object_objFreeObject(this);
  }
  return;
}


/* @description Override render */

void SBcloudball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80264D18
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_22F_func07
    dll_230_func07
    dll_2AC_func07
   
   Library: KioskDefault 0 0 */

void SBcloudball_free(ObjInstance *this,int param2) { //80264D1C
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


undefined4 SBcloudball_func08(ObjInstance *this) { //80264DA4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SBcloudball_getExtraSize(void) { //80264DAC
  return 0x34;
}

