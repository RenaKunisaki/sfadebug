
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBbonedust_initialise(undefined4 param) { //8029FEAC
  return;
}


/* @description Called when DLL is unloaded */

void DBbonedust_release(void) { //8029FEB0
  return;
}


/* Library Function - Single Match
    dll_287_func03
   
   Library: KioskDefault 0 0 */

void DBbonedust_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8029FEB4
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  *(undefined *)(pfVar2 + 2) = 0;
  *pfVar2 = (objDef->pos).y;
  (this->pos).pos.x = (objDef->pos).x;
  (this->pos).pos.y = (objDef->pos).y;
  (this->pos).pos.z = (objDef->pos).z;
  (this->vel).z = 0.0;
  (this->vel).x = 0.0;
  (this->vel).y = -4.0;
  fVar1 = (float)randInt(0,0xffff);
  pfVar2[1] = fVar1;
  return;
}


/* Library Function - Single Match
    dll_287_func04
   
   Library: KioskDefault 0 0 */

void DBbonedust_update(ObjInstance *this) { //8029FF34
  byte bVar1;
  float fVar2;
  ObjInstance *param2;
  float *pfVar3;
  double dVar4;
  double dVar5;
  undefined2 local_54;
  short local_52;
  undefined2 local_50;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  _savefpr_29();
  pfVar3 = (float *)this->state;
  param2 = Object_objGetMain();
  bVar1 = *(byte *)(pfVar3 + 2);
  if (bVar1 == 2) {
    uStack_2c = (uint)pfVar3[1] ^ 0x80000000;
    local_30 = 0x43300000;
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_2c) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    (this->vel).y = (float)(dVar4 * 0.300000011920929);
    dVar4 = (double)(this->vel).x;
    objMove(dVar4,(double)(this->vel).y,(double)(this->vel).z,this);
    objDistObj2Obj(this,param2);
    if (dVar4 < 100.0) {
      *(undefined *)(pfVar3 + 2) = 3;
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 != 0) && (true)) {
      if (0.0 < *pfVar3 - (this->pos).pos.y) {
        (this->vel).y = -(this->vel).y * 0.7;
        if ((this->vel).y < 0.0) {
          fVar2 = -(this->vel).y;
        }
        else {
          fVar2 = (this->vel).y;
        }
        if (fVar2 < 0.1) {
          *(undefined *)(pfVar3 + 2) = 2;
          (this->vel).x = 0.0;
          (this->vel).z = 0.0;
          goto LAB_802a0224;
        }
      }
      (this->vel).y = (this->vel).y + -0.4;
      objMove((double)(this->vel).x,(double)(this->vel).y,(double)(this->vel).z,this);
      local_50 = 0xff;
      local_52 = 0xff - (SUB42(pfVar3[1],0) + (short)((int)pfVar3[1] / 0x500) * -0x500);
      local_54 = 0xff;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x357,&local_54,0,0xffffffff,0);
    }
  }
  else if (bVar1 < 4) {
    dVar4 = (double)objDistObj2ObjXZ(this,param2);
    if (6.0 <= dVar4) {
      local_34 = (param2->pos).pos.x - (this->pos).pos.x;
      local_38 = (param2->pos).pos.y - ((this->pos).pos.y - 25.0);
      local_3c = (param2->pos).pos.z - (this->pos).pos.z;
      dVar5 = 4.0;
      if (dVar4 < 4.0) {
        dVar5 = dVar4;
      }
      normalize(&local_34,&local_38,&local_3c);
      (this->vel).x = (float)((double)local_34 * dVar5);
      (this->vel).y = (float)((double)local_38 * dVar5);
      (this->vel).z = (float)((double)local_3c * dVar5);
      objMove((double)(this->vel).x,(double)(this->vel).y,(double)(this->vel).z,this);
      local_50 = 0xff;
      local_52 = 0;
      local_54 = 0xff;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x357,&local_54,0,0xffffffff,0);
    }
    else {
      FUN_801a7b7c((int)param2,3);
      audioTryStartSfx((int *)this,1,0x15f,0x7f,"DBbonedust.c",0x8c);
      *(undefined *)(pfVar3 + 2) = 0;
    }
  }
LAB_802a0224:
  pfVar3[1] = (float)((int)pfVar3[1] + (uint)framesThisStep * 0x500);
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void DBbonedust_hitDetect(ObjInstance *this) { //802A0254
  return;
}


/* Library Function - Single Match
    dll_287_func06
   
   Library: KioskDefault 0 0 */

void DBbonedust_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //802A0258
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->state[8] != '\0')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DBbonedust_free(ObjInstance *this,int param2) { //802A02CC
  return;
}


undefined4 DBbonedust_func08(ObjInstance *this) { //802A02D0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBbonedust_getExtraSize(void) { //802A02D8
  return 0xc;
}


/* Library Function - Single Match
    dll_287_func0A
   
   Library: KioskDefault 0 0 */

void DBbonedust_setScale(ObjInstance *this,float scale) { //802A02E0
  countLeadingZeros(-(uint)(byte)this->state[8]);
  return;
}


/* Library Function - Single Match
    dll_287_func0B
   
   Library: KioskDefault 0 0 */

void DBbonedust_func0B(double param1,int param2,undefined4 *param3,float *param4) { //802A0310
  float *pfVar1;
  
  pfVar1 = *(float **)(param2 + 0xb8);
  if (param3 != (undefined4 *)0x0) {
    *(undefined4 *)(param2 + 0xc) = *param3;
    *(undefined4 *)(param2 + 0x10) = param3[1];
    *(undefined4 *)(param2 + 0x14) = param3[2];
  }
  if (param4 != (float *)0x0) {
    *(float *)(param2 + 0x24) = *param4 * 4.0;
    *(float *)(param2 + 0x28) = param4[1] * 4.0;
    *(float *)(param2 + 0x2c) = param4[2] * 4.0;
  }
  pfVar1[1] = 0.0;
  *pfVar1 = (float)param1;
  *(undefined *)(pfVar1 + 2) = 1;
  return;
}

