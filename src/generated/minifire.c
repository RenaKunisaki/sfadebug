
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void minifire_initialise(undefined4 param) { //8028B898
  return;
}


/* @description Called when DLL is unloaded */

void minifire_release(void) { //8028B89C
  return;
}


/* Library Function - Single Match
    dll_259_func03
   
   Library: KioskDefault 0 0 */

void minifire_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8028B8A0
  (this->vel).y = -15.0;
  (this->pos).pos.y = (objDef->pos).y + 400.0;
  (this->pos).scale = (this->pos).scale * 2.0;
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,0x38c,0,2,0xffffffff,0);
  audioTryStartSfx((int *)this,1,0x6e,0x7f,(char *)&PTR_DAT_8031e258,0x3e);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_259_func04
   
   Library: KioskDefault 0 0 */

void minifire_update(ObjInstance *this) { //8028B95C
  int iVar1;
  ObjDef *pOVar2;
  HitState *pHVar3;
  float *pfVar4;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  longlong local_40;
  
  _savefpr_29();
  pOVar2 = this->def;
  pfVar4 = (float *)this->state;
  if (*pfVar4 == 0.0) {
    FUN_800ba478((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (int)this,pfVar4,0);
    *pfVar4 = (this->pos).pos.y - *pfVar4;
  }
  if (-15.0 < (this->vel).y) {
    (this->vel).y = (this->vel).y + -0.03;
  }
  (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
  (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
  (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
  local_50 = 0.0;
  local_4c = 0.0;
  local_48 = 0.0;
  local_54 = 1.0;
  local_58 = 0;
  local_5a = 0;
  local_5c = 0;
  iVar1 = randInt(0,4);
  if (iVar1 == 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x38a,&local_5c,&DAT_00080001,0xffffffff,0);
  }
  local_50 = ((this->pos).pos.x - (this->oldPos).x) / 3.0;
  local_4c = ((this->pos).pos.y - (this->oldPos).y) / 3.0;
  local_48 = ((this->pos).pos.z - (this->oldPos).z) / 3.0;
  iVar1 = randInt(0,4);
  if (iVar1 == 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x38a,&local_5c,&DAT_00080001,0xffffffff,0);
  }
  local_50 = local_50 * 2.0;
  local_4c = local_4c * 2.0;
  local_48 = local_48 * 2.0;
  iVar1 = randInt(0,4);
  if (iVar1 == 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x38a,&local_5c,&DAT_00080001,0xffffffff,0);
  }
  iVar1 = randInt(0,2);
  if (iVar1 == 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x38b,&local_5c,1,0xffffffff,0);
  }
  pHVar3 = this->hitstate;
  if (pHVar3 == (HitState *)0x0) {
LAB_8028bc1c:
    if ((*pfVar4 <= (this->pos).pos.y) || (*(char *)((int)pfVar4 + 10) != '\0')) goto LAB_8028bcb4;
  }
  else {
    *(undefined *)((int)&pHVar3->sizeX2 + 1) = 0xb;
    *(undefined *)&pHVar3->flags_0x60 = 1;
    (pHVar3->field12_0x3c).y = 2.242078e-44;
    (pHVar3->field12_0x3c).z = 2.242078e-44;
    if (pHVar3->field13_0x48 == 0) goto LAB_8028bc1c;
  }
  *(undefined *)((int)pfVar4 + 10) = 1;
  FUN_80068a9c((uint)this,1);
  audioTryStartSfx((int *)this,2,0x3a,0x7f,(char *)&PTR_DAT_8031e258,0x8f);
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x38e,&local_5c,1,0xffffffff,0);
  }
LAB_8028bcb4:
  if (*(char *)((int)pfVar4 + 10) == '\0') {
    iVar1 = (int)(((this->pos).pos.y - (pOVar2->pos).y) / 600.0 + 0.25);
    local_40 = (longlong)iVar1;
    FUN_800689dc(127.0,(int)this,2,(byte)iVar1);
  }
  else {
    local_40 = (longlong)(int)timeDelta;
    iVar1 = (uint)this->newOpacity - (int)timeDelta;
    if ((short)iVar1 < 0) {
      iVar1 = 0;
    }
    this->newOpacity = (u8)iVar1;
  }
  if ((this->pos).pos.y < *pfVar4 - 360.0) {
    Object_objFreeObject(this);
  }
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void minifire_hitDetect(ObjInstance *this) { //8028BD68
  return;
}


/* Library Function - Single Match
    dll_259_func06
   
   Library: KioskDefault 0 0 */

void minifire_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8028BD6C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->newOpacity != 0)) {
    FUN_800a56ac(8);
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_800a56bc(8);
  }
  return;
}


/* @description Free object instance */

void minifire_free(ObjInstance *this,int param2) { //8028BDF0
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 minifire_func08(ObjInstance *this) { //8028BE28
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int minifire_getExtraSize(void) { //8028BE30
  return 0xc;
}

