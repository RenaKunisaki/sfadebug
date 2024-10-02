
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SPscarab_initialise(undefined4 param) { //80269784
  return;
}


/* @description Called when DLL is unloaded */

void SPscarab_release(void) { //80269788
  return;
}


/* Library Function - Single Match
    dll_2CE_func03
   
   Library: KioskDefault 0 0 */

void SPscarab_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8026978C
  short sVar1;
  uint uVar2;
  float *pfVar3;
  double dVar4;
  
  pfVar3 = (float *)this->state;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  (this->vel).x = (float)-dVar4;
  dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)(this->pos).rotation.x ^
                                                                     0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  (this->vel).z = (float)-dVar4;
  this->curModel = *(byte *)((int)&objDef[1].objType + 1);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *pfVar3 = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  uVar2 = randInt(0,100);
  pfVar3[1] = (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - 4503601774854144.0) / 100.0
              + 0.4;
  pfVar3[2] = (float)objDef->id;
  objDef->id = -1;
  return;
}


/* Library Function - Single Match
    dll_2CE_func04
   
   Library: KioskDefault 0 0 */

void SPscarab_update(ObjInstance *this) { //802698CC
  int iVar1;
  ObjInstance *param1;
  float *pfVar2;
  double dVar3;
  float local_6c [2];
  float local_64;
  ObjInstance *apOStack_60 [7];
  float afStack_44 [15];
  
  pfVar2 = (float *)this->state;
  if (*pfVar2 < (this->pos).pos.y) {
    (this->vel).y = -(timeDelta * 0.1 - (this->vel).y);
  }
  objMove((double)(timeDelta * (this->vel).x * pfVar2[1]),(double)((this->vel).y * timeDelta),
          (double)(timeDelta * (this->vel).z * pfVar2[1]),this);
  if ((this->pos).pos.y < *pfVar2) {
    (this->pos).pos.y = *pfVar2;
    (this->vel).y = 0.0;
  }
  iVar1 = FUN_800bb7e0(3.0,&(this->oldPos).x,&(this->pos).pos.x,0,apOStack_60,this,8,-1,0xff,'\0');
  if (iVar1 != 0) {
    FUN_8007b2d0(afStack_44,&(this->vel).x,local_6c);
    (this->vel).x = local_6c[0];
    (this->vel).z = local_64;
    iVar1 = getAngle();
    (this->pos).rotation.x = (short)iVar1;
  }
  param1 = Object_objGetMain();
  dVar3 = (double)objDistSqObj2ObjXZ(param1,this);
  if (dVar3 < 100.0) {
    audioTryStartSfx((int *)this,1,0x49,0x7f,(char *)&PTR_DAT_8031c670,0x71);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
    this->flags_0xb0 = this->flags_0xb0 | DontUpdate;
    (this->pos).flags = (this->pos).flags | Invisible;
    (**(code **)(**(int **)((int)pfVar2[2] + 0x68) + 0x50))
              (pfVar2[2],this->curModel != 0,this->curModel == 0);
  }
  return;
}


/* @description Override hit detection */

void SPscarab_hitDetect(ObjInstance *this) { //80269B0C
  return;
}


/* @description Override render */

void SPscarab_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80269B10
  return;
}


/* @description Free object instance */

void SPscarab_free(ObjInstance *this,int param2) { //80269B14
  return;
}


undefined4 SPscarab_func08(ObjInstance *this) { //80269B18
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SPscarab_getExtraSize(void) { //80269B20
  return 0xc;
}

