
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void chukachuck_initialise(undefined4 param) { //801BE43C
  return;
}


/* @description Called when DLL is unloaded */

void chukachuck_release(void) { //801BE440
  return;
}


/* Library Function - Single Match
    dll_D8_func03
   
   Library: KioskDefault 0 0 */

void chukachuck_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801BE444
  this->field76_0xf4 = 0xb4;
  FUN_80088da4((int)this);
  this->newOpacity = 0xff;
  return;
}


/* Library Function - Single Match
    dll_D8_func04
   
   Library: KioskDefault 0 0 */

void chukachuck_update(ObjInstance *this) { //801BE484
  ObjInstance *pOVar1;
  
  this->field76_0xf4 =
       (int)((float)((double)CONCAT44(0x43300000,this->field76_0xf4 ^ 0x80000000) -
                    4503601774854144.0) - timeDelta);
  if ((int)this->field76_0xf4 < 0) {
    Object_objFreeObject(this);
    return;
  }
  if (this->newOpacity != 0) {
    (this->vel).y = -(timeDelta * 0.07 - (this->vel).y);
    (this->vel).y = (this->vel).y * 0.97;
    (this->pos).rotation.x = (this->pos).rotation.x + 0x38e;
    (this->pos).rotation.z = (this->pos).rotation.z + 0x38e;
    (this->pos).rotation.y = (this->pos).rotation.y + 0x38e;
    objMove((double)((this->vel).x * timeDelta),(double)((this->vel).y * timeDelta),
            (double)((this->vel).z * timeDelta),this);
    objHitFn_80089074(this,10,1,0);
    objHitFn_80089354(this,5);
    FUN_80088d3c((int)this);
    if ((this->hitstate->field13_0x48 == 0) ||
       ((pOVar1 = Object_objGetMain(), (ObjInstance *)this->hitstate->field13_0x48 != pOVar1 &&
        (pOVar1 = Object_getSidekicksLoaded(),
        (ObjInstance *)this->hitstate->field13_0x48 != pOVar1)))) {
      if (this->hitstate->field54_0x9d != 0) {
        FUN_801be8d0((int)this);
        this->newOpacity = 0;
        this->field76_0xf4 = 0x78;
        this->hitstate->flags = this->hitstate->flags & 0xfffe;
      }
    }
    else {
      FUN_801be6d0((int)this);
      this->newOpacity = 0;
      this->field76_0xf4 = 0x78;
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
    }
    return;
  }
  return;
}


/* @description Override hit detection */

void chukachuck_hitDetect(ObjInstance *this) { //801BE640
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void chukachuck_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801BE644
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

void chukachuck_free(ObjInstance *this,int param2) { //801BE6A0
  FUN_80069038();
  return;
}


undefined4 chukachuck_func08(ObjInstance *this) { //801BE6C0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int chukachuck_getExtraSize(void) { //801BE6C8
  return 2;
}

