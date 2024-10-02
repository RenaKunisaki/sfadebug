
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void flameblast_initialise(undefined4 param) { //801D7C40
  return;
}


/* @description Called when DLL is unloaded */

void flameblast_release(void) { //801D7C44
  return;
}


/* Library Function - Single Match
    dll_FC_func03
   
   Library: KioskDefault 0 0 */

void flameblast_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801D7C48
  undefined param3;
  
  *(undefined2 *)this->state = *(undefined2 *)&objDef[1].allocatedSize;
  if (*(char *)((int)&objDef[1].objType + 1) == '\0') {
    param3 = 1;
  }
  else {
    param3 = 3;
  }
  objHitFn_80089074(this,0x1a,param3,0);
  return;
}


/* Library Function - Single Match
    dll_FC_func04
   
   Library: KioskDefault 0 0 */

void flameblast_update(ObjInstance *this) { //801D7CA8
  ObjInstance *pOVar1;
  short *psVar2;
  short local_34;
  short local_32;
  short local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  longlong local_18;
  
  pOVar1 = Object_getSidekicksLoaded();
  psVar2 = (short *)this->state;
  if (pOVar1 != (ObjInstance *)0x0) {
    audioTryStartSfx((int *)this,0xc0,0x235,0x7f,(char *)&PTR_DAT_80311628,0x36);
    local_18 = (longlong)(int)timeDelta;
    *psVar2 = *psVar2 - (short)(int)timeDelta;
    if (*psVar2 < 1) {
      *psVar2 = 0x1e;
      (this->vel).x = 0.0;
      (this->vel).y = 0.0;
      (this->vel).z = -2.0;
      local_28 = 0.0;
      local_24 = 0.0;
      local_20 = 0.0;
      local_2c = 1.0;
      local_30 = (pOVar1->pos).rotation.z;
      local_32 = (pOVar1->pos).rotation.y;
      local_34 = (pOVar1->pos).rotation.x;
      FUN_8007a878(&local_34,&(this->vel).x);
      (this->pos).pos.x = (pOVar1->pos).pos.x;
      (this->pos).pos.y = (pOVar1->pos).pos.y;
      (this->pos).pos.z = (pOVar1->pos).pos.z;
      (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
      (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
      (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
    }
    (this->oldPos).x = (this->pos).pos.x;
    (this->oldPos).y = (this->pos).pos.y;
    (this->oldPos).z = (this->pos).pos.z;
    (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
    (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
    (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
  }
  return;
}


/* @description Override hit detection */

void flameblast_hitDetect(ObjInstance *this) { //801D7E3C
  return;
}


/* @description Override render */

void flameblast_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801D7E50
  return;
}


/* @description Free object instance */

void flameblast_free(ObjInstance *this,int param2) { //801D7E54
  return;
}


undefined4 flameblast_func08(ObjInstance *this) { //801D7E58
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int flameblast_getExtraSize(void) { //801D7E60
  return 4;
}


void flameblast_setScale(undefined param_1,undefined param_2,undefined param_3,undefined param_4,
                        undefined param_5,undefined param_6,undefined param_7,undefined param_8,
                        undefined param_9,undefined param_10,undefined8 param_11,undefined8 param_12
                        ,undefined4 param_13,undefined4 param_14) { //801D82E0
  byte bVar1;
  ObjDefEnum OVar2;
  uint uVar3;
  int iVar4;
  int unaff_r23;
  int unaff_r24;
  float *unaff_r27;
  int unaff_r28;
  dword unaff_r29;
  int unaff_r30;
  ObjInstance *unaff_r31;
  double dVar5;
  double dVar6;
  double in_f25;
  double in_f31;
  
  if ((in_f25 < 200.0) && (unaff_r28 != 0)) {
    uVar3 = (int)*(char *)(unaff_r30 + 0x18) << 8;
    param_12._4_4_ = uVar3 ^ 0x80000000;
    param_12._0_4_ = 0x43300000;
    dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,param_12._4_4_
                                                                          ) - 4503601774854144.0) *
                                                 3.141593) / 32767.0));
    param_11._4_4_ = uVar3 ^ 0x80000000;
    param_11._0_4_ = 0x43300000;
    dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,param_11._4_4_) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    in_f31 = (double)(-(float)((double)*(float *)(unaff_r30 + 8) * dVar5 +
                              (double)(float)((double)*(float *)(unaff_r30 + 0x10) * dVar6)) +
                     (float)(dVar5 * (double)*(float *)(unaff_r23 + 0xc) +
                            (double)(float)(dVar6 * (double)*(float *)(unaff_r23 + 0x14))));
    param_11 = CONCAT44(param_11._0_4_,param_11._4_4_);
    param_12 = CONCAT44(param_12._0_4_,param_12._4_4_);
    if ((in_f31 < 200.0) &&
       (param_11 = CONCAT44(param_11._0_4_,param_11._4_4_),
       param_12 = CONCAT44(param_12._0_4_,param_12._4_4_), -200.0 < in_f31)) {
      unaff_r29 = 1;
      param_11 = CONCAT44(param_11._0_4_,param_11._4_4_);
      param_12 = CONCAT44(param_12._0_4_,param_12._4_4_);
    }
  }
  if (unaff_r31->flags_0xf8 == 0) {
    if (unaff_r29 != 0) {
      *(byte *)(unaff_r24 + 0x89) = *(byte *)(unaff_r24 + 0x89) | 1;
    }
  }
  else if (unaff_r29 == 0) {
    *(byte *)(unaff_r24 + 0x89) = *(byte *)(unaff_r24 + 0x89) | 2;
  }
  unaff_r31->flags_0xf8 = unaff_r29;
  if (((unaff_r31->romdefno == WM_Door1) || (unaff_r31->romdefno == WM_WarpDoor)) &&
     (*(char *)((int)unaff_r27 + 0x19) != '\0')) {
    *(byte *)(unaff_r24 + 0x89) = *(byte *)(unaff_r24 + 0x89) | 1;
  }
  do {
    iVar4 = FUN_80091100((int)unaff_r31,(uint *)&stack0x00000020,(uint *)0x0,(uint *)0x0);
  } while (iVar4 != 0);
  for (iVar4 = 0; iVar4 < (int)(uint)*(byte *)(unaff_r24 + 0x84); iVar4 = iVar4 + 1) {
    if (*(char *)(unaff_r24 + iVar4 + 0x7a) != '\0') {
      bVar1 = *(byte *)(unaff_r24 + iVar4 + 0x7a);
      if (bVar1 == 2) {
        FUN_801d8c64(unaff_r27,unaff_r30);
        OVar2 = unaff_r31->romdefno;
        if (OVar2 == 0x205) {
          FUN_80091034(1000.0,DBSH_Shrine,0,unaff_r31,0x30005,0);
        }
        else if ((short)OVar2 < 0x205) {
          if (OVar2 == ECSH_Door1) {
            FUN_80091034(1000.0,ECSH_Shrine,0,unaff_r31,0x30005,0);
          }
          else if ((short)OVar2 < 0x1bb) {
            if (OVar2 == 0x1ad) {
              FUN_80091034(1000.0,MMSH_Shrine,0,unaff_r31,0x30005,0);
            }
            else if (((short)OVar2 < 0x1ad) && (OVar2 == DFSH_Door1)) {
              FUN_80091034(1000.0,DFSH_Shrine,0,unaff_r31,0x30005,0);
            }
          }
          else if (OVar2 == 0x1ea) {
            FUN_80091034(1000.0,GPSH_Shrine,0,unaff_r31,0x30005,0);
          }
        }
        else if (OVar2 == 0x238) {
          FUN_80091034(1000.0,0x233,0,unaff_r31,0x30005,0);
        }
        else if ((short)OVar2 < 0x238) {
          if (OVar2 == 0x21a) {
            FUN_80091034(1000.0,0x217,0,unaff_r31,0x30005,0);
          }
        }
        else if (OVar2 == 0x23f) {
          FUN_80091034(1000.0,0x23c,0,unaff_r31,0x30005,0);
        }
      }
      else if ((bVar1 < 2) && (bVar1 != 0)) {
        FUN_801d8c64(unaff_r27,unaff_r30);
        if (in_f31 <= 0.0) {
          OVar2 = unaff_r31->romdefno;
          if (OVar2 == 0x205) {
            FUN_80091034(1000.0,DBSH_Shrine,0,unaff_r31,0x30006,0);
          }
          else if ((short)OVar2 < 0x205) {
            if (OVar2 == ECSH_Door1) {
              FUN_80091034(1000.0,ECSH_Shrine,0,unaff_r31,0x30006,0);
            }
            else if ((short)OVar2 < 0x1bb) {
              if (OVar2 == 0x1ad) {
                FUN_80091034(1000.0,MMSH_Shrine,0,unaff_r31,0x30006,0);
              }
              else if (((short)OVar2 < 0x1ad) && (OVar2 == DFSH_Door1)) {
                FUN_80091034(1000.0,DFSH_Shrine,0,unaff_r31,0x30006,0);
              }
            }
            else if (OVar2 == 0x1ea) {
              FUN_80091034(1000.0,GPSH_Shrine,0,unaff_r31,0x30006,0);
            }
          }
          else if (OVar2 == 0x238) {
            FUN_80091034(1000.0,0x233,0,unaff_r31,0x30006,0);
          }
          else if ((short)OVar2 < 0x238) {
            if (OVar2 == 0x21a) {
              FUN_80091034(1000.0,0x217,0,unaff_r31,0x30006,0);
            }
          }
          else if (OVar2 == 0x23f) {
            FUN_80091034(1000.0,0x23c,0,unaff_r31,0x30006,0);
          }
        }
      }
      *(undefined *)(unaff_r24 + iVar4 + 0x7a) = 0;
    }
  }
  if (unaff_r31->field76_0xf4 != 0) {
    unaff_r31->field76_0xf4 = 0;
  }
  _restfpr_25();
  return;
}

