
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFforcecontrol_initialise(undefined4 param) { //8020E4E0
  return;
}


/* @description Called when DLL is unloaded */

void CFforcecontrol_release(void) { //8020E4E4
  return;
}


/* Library Function - Single Match
    dll_173_func03
   
   Library: KioskDefault 0 0 */

void CFforcecontrol_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8020E4E8
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  uVar1 = mainGetBit(0x2e1);
  if (uVar1 == 0) {
    FUN_80088d3c((int)this);
    objHitFn_80089074(this,7,0,-1);
    objHitGetFlag1(this);
    if (*(float *)&objDef[1].loadFlags != 0.0) {
      (this->pos).scale = this->data->scale * (*(float *)&objDef[1].loadFlags / 255.0);
      this->cullDistance = 400.0;
    }
    *(float *)(puVar2 + 0x3c) =
         (float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].objType) - 4503599627370496.0
                );
    *(int *)(puVar2 + 0x38) = (int)*(float *)&objDef[1].loadFlags;
    *(float *)(puVar2 + 0x4c) = 90.0;
    *(undefined4 *)(puVar2 + 0x34) = 1;
    *(undefined4 *)(puVar2 + 0x30) = 0x51;
    mainSetBits(0x30b,1);
    FUN_8020e8f8((int)puVar2);
  }
  else {
    (this->pos).flags = (this->pos).flags | Invisible;
    objFreeFn_80083b54(this);
  }
  return;
}


/* Library Function - Single Match
    dll_173_func04
   
   Library: KioskDefault 0 0 */

void CFforcecontrol_update(ObjInstance *this) { //8020E600
  uint uVar1;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  uVar1 = mainGetBit(0x2e1);
  if (uVar1 == 0) {
    if (pfVar2[0xc] != 0.0) {
      if (pfVar2[0xc] == (float)(((int)pfVar2[0xc] / 0x14) * 0x14)) {
        FUN_8020e8dc();
      }
      pfVar2[0xc] = (float)((int)pfVar2[0xc] + -1);
      if (pfVar2[0xc] == 0.0) {
        (this->pos).pos.y = (this->pos).pos.y - pfVar2[0xf];
      }
    }
    audioTryStartSfx((int *)this,0xc0,0x80,0x7f,"CFforcecontrol.c",0xaa);
    objHitFn_80089074(this,8,1,0);
    FUN_8020ea68(this,pfVar2);
  }
  else {
    mainSetBits(0x30b,0);
    objFreeFn_80083b54(this);
    FUN_80068a9c((uint)this,0x40);
    audioTryStartSfx((int *)this,1,0x56,0x7f,"CFforcecontrol.c",0x9e);
  }
  return;
}


/* Library Function - Single Match
    dll_173_func05
   
   Library: KioskDefault 0 0 */

void CFforcecontrol_hitDetect(ObjInstance *this) { //8020E724
  ObjInstance *param1;
  float *pfVar1;
  uint param2;
  double dVar2;
  double dVar3;
  double dVar4;
  
  _savefpr_29();
  pfVar1 = (float *)this->state;
  if ((this->hitstate->field13_0x48 != 0) && (param2 = this->hitstate->field13_0x48, param2 != 0)) {
    param1 = Object_getSidekicksLoaded();
    printf(" Side %x ObHit %x Romdef %i",(uint)param1,param2,(int)*(short *)(param2 + 0x46)
          );
    dVar4 = (double)(*(float *)(param2 + 0xc) - (this->pos).pos.x);
    dVar3 = (double)(*(float *)(param2 + 0x10) - (this->pos).pos.y);
    dVar2 = (double)(*(float *)(param2 + 0x14) - (this->pos).pos.z);
    if (*(short *)(pfVar1 + 1) == 0) {
      FUN_8020efc4((double)(float)(dVar4 / 100.0),(double)(float)(dVar3 / 100.0),
                   (double)(float)(dVar2 / 100.0),(int)this);
    }
    audioTryStartSfx((int *)this,1,0x55,0x7f,"CFforcecontrol.c",0xd0);
    FUN_8020e90c(dVar4,dVar3,dVar2,40.0,this,pfVar1);
  }
  _restfpr_29();
  return;
}


/* @description Override render */

void CFforcecontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8020E82C
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


/* @description Free object instance */

void CFforcecontrol_free(ObjInstance *this,int param2) { //8020E894
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 CFforcecontrol_func08(ObjInstance *this) { //8020E8CC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CFforcecontrol_getExtraSize(void) { //8020E8D4
  return 0x54;
}

