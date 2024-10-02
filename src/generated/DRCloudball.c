
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRCloudball_initialise(undefined4 param) { //802B39A4
  return;
}


/* @description Called when DLL is unloaded */

void DRCloudball_release(void) { //802B39A8
  return;
}


/* Library Function - Single Match
    dll_2AC_func03
   
   Library: KioskDefault 0 0 */

void DRCloudball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802B39AC
  undefined *puVar1;
  
  puVar1 = this->state;
  this->hitstate->flags = this->hitstate->flags & 0xfffe;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined2 *)(puVar1 + 0x2c) = 0;
  return;
}


/* Library Function - Single Match
    dll_2AC_func04
   
   Library: KioskDefault 0 0 */

void DRCloudball_update(ObjInstance *this) { //802B39E4
  int iVar1;
  LoadedDll *dll;
  undefined *puVar2;
  
  puVar2 = this->state;
  (this->oldPos).x = (this->pos).pos.x;
  (this->oldPos).y = (this->pos).pos.y;
  (this->oldPos).z = (this->pos).pos.z;
  (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
  (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
  (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
  iVar1 = getAngle();
  (this->pos).rotation.x = (short)iVar1;
  (this->pos).rotation.x = (this->pos).rotation.x + -0x8000;
  iVar1 = getAngle();
  (this->pos).rotation.y = (short)iVar1;
  iVar1 = 0;
  if (*(short *)(puVar2 + 0x2c) < 0x10) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
  }
  else {
    *(undefined *)((int)&this->hitstate->sizeX2 + 1) = 5;
    *(undefined *)&this->hitstate->flags_0x60 = 1;
    (this->hitstate->field12_0x3c).y = 2.242078e-44;
    (this->hitstate->field12_0x3c).z = 2.242078e-44;
    iVar1 = ret0_8008D09C();
    if (-1 < (char)puVar2[0x33]) {
      dll = (LoadedDll *)runlinkDownloadCode(0x1035,1);
      if (dll != (LoadedDll *)0x0) {
        (**(code **)(dll->id + 4))(this,0,0,&DAT_00010404,0xffffffff,0);
      }
      DLL_free(dll);
      puVar2[0x33] = puVar2[0x33] & 0x7f | 0x80;
    }
    this->hitstate->flags = this->hitstate->flags | 1;
  }
  if ((int)this->field76_0xf4 < (int)*(short *)(puVar2 + 0x2c)) {
    iVar1 = 1;
  }
  if (iVar1 != 0) {
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x1f1,0x7f,"DRCloudball.c",(int *)0x84);
    Object_objFreeObject(this);
  }
  *(ushort *)(puVar2 + 0x2c) = *(short *)(puVar2 + 0x2c) + (ushort)framesThisStep;
  return;
}


/* Library Function - Single Match
    dll_2AC_func05
   
   Library: KioskDefault 0 0 */

void DRCloudball_hitDetect(ObjInstance *this) { //802B3C2C
  int iVar1;
  
  iVar1 = 0x14;
  if (this->hitstate->field13_0x48 != 0) {
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x1f1,0x7f,"DRCloudball.c",(int *)0x90);
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

void DRCloudball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802B3D68
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_22F_func07
    dll_230_func07
    dll_2AC_func07
   
   Library: KioskDefault 0 0 */

void DRCloudball_free(ObjInstance *this,int param2) { //802B3D6C
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


undefined4 DRCloudball_func08(ObjInstance *this) { //802B3DF4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRCloudball_getExtraSize(void) { //802B3DFC
  return 0x34;
}

