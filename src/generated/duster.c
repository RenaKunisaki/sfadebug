
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void duster_initialise(undefined4 param) { //801E3F6C
  return;
}


/* @description Called when DLL is unloaded */

void duster_release(void) { //801E3F70
  return;
}


/* Library Function - Single Match
    dll_127_func03
   
   Library: KioskDefault 0 0 */

void duster_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801E3F74
  int iVar1;
  uint uVar2;
  float *pfVar3;
  
  pfVar3 = (float *)this->state;
  iVar1 = randInt(0,0x32);
  *(short *)(pfVar3 + 1) = (short)iVar1;
  *pfVar3 = 0.02;
  *(undefined2 *)((int)pfVar3 + 10) = *(undefined2 *)&objDef[1].pos.y;
  if (*(short *)((int)pfVar3 + 10) < 0x6fe) {
    uVar2 = mainGetBit((int)*(short *)((int)pfVar3 + 10));
    *(char *)((int)pfVar3 + 0xf) = (char)uVar2;
    *(short *)(pfVar3 + 2) = *(short *)((int)pfVar3 + 10) + 100;
  }
  else {
    *(undefined *)((int)pfVar3 + 0xf) = 1;
    *(undefined2 *)(pfVar3 + 2) = *(undefined2 *)((int)pfVar3 + 10);
  }
  uVar2 = mainGetBit((int)*(short *)(pfVar3 + 2));
  *(char *)(pfVar3 + 4) = (char)uVar2;
  *(byte *)((int)pfVar3 + 0x11) = objDef[1].mapStates1;
  if ((this->hitstate != (HitState *)0x0) && (*(char *)((int)pfVar3 + 0xf) == '\0')) {
    this->hitstate->flags = this->hitstate->flags | 1;
  }
  if (((*(char *)(pfVar3 + 4) != '\0') || (*(char *)((int)pfVar3 + 0xf) == '\0')) &&
     (this->hitstate != (HitState *)0x0)) {
    FUN_80088da4((int)this);
  }
  return;
}


/* Library Function - Single Match
    dll_127_func04
   
   Library: KioskDefault 0 0 */

void duster_update(ObjInstance *this) { //801E4068
  ObjInstance *param1;
  uint uVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  double dVar5;
  int local_44;
  short local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  longlong local_28;
  
  pfVar4 = (float *)this->state;
  param1 = Object_objGetMain();
  if ((*(char *)((int)pfVar4 + 0xf) == '\0') || (*(char *)(pfVar4 + 4) == '\x01')) {
    if (*(char *)((int)pfVar4 + 0xf) == '\0') {
      uVar1 = mainGetBit((int)*(short *)((int)pfVar4 + 10));
      *(char *)((int)pfVar4 + 0xf) = (char)uVar1;
      *(undefined2 *)(pfVar4 + 1) = 0;
    }
  }
  else {
    if (-6.0 < (this->vel).y) {
      (this->vel).y = timeDelta * -0.05 + (this->vel).y;
    }
    *(undefined *)((int)pfVar4 + 0xe) = 0;
    iVar2 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                         (double)(this->pos).pos.z,(int)this,&local_44,0,0);
    for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
      if ((this->pos).pos.y - 1.0 < **(float **)(local_44 + iVar3 * 4)) {
        (this->pos).pos.y = **(float **)(local_44 + iVar3 * 4);
        (this->vel).y = 0.0;
        break;
      }
    }
    if ((*(short *)(pfVar4 + 1) == 0) && (*(short *)((int)pfVar4 + 6) == 0)) {
      iVar2 = objRunAnimation((double)*pfVar4,(double)timeDelta,(int)this,(float *)0x0);
      if ((iVar2 == 0) && (*(char *)((int)pfVar4 + 0xe) == '\0')) {
        (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
        (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
      }
      else {
        audioTryStartSfx((int *)this,8,0x48,0x25,"duster.c",0xa1);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51f,0,2,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51f,0,2,0xffffffff,0);
        iVar2 = randInt(0,4);
        *(char *)(pfVar4 + 3) = (char)iVar2;
        if (*(char *)((int)pfVar4 + 0x11) == '\0') {
          (this->vel).x = 0.0;
          (this->vel).z = 0.0;
        }
        else {
          (this->vel).x = 0.2;
          (this->vel).z = 0.0;
          local_34 = 0.0;
          local_30 = 0.0;
          local_2c = 0.0;
          local_38 = 1.0;
          local_3c = 0;
          local_3e = 0;
          local_40 = (this->pos).rotation.x;
          FUN_8007a878(&local_40,&(this->vel).x);
        }
        if (*(char *)((int)pfVar4 + 0xd) != '\0') {
          *(undefined2 *)((int)pfVar4 + 6) = 0xfa;
        }
      }
      iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
      if (iVar2 == 0xe) {
        *(undefined *)((int)pfVar4 + 0xd) = 1;
        audioTryStartSfx((int *)this,0x10,199,0x7f,"duster.c",0xc2);
      }
    }
    else {
      if (*(short *)(pfVar4 + 1) != 0) {
        local_28 = (longlong)(int)timeDelta;
        *(short *)(pfVar4 + 1) = *(short *)(pfVar4 + 1) - (short)(int)timeDelta;
        if (*(short *)(pfVar4 + 1) < 1) {
          *(undefined2 *)(pfVar4 + 1) = 0;
        }
      }
      if (*(short *)((int)pfVar4 + 6) != 0) {
        local_28 = (longlong)(int)timeDelta;
        *(short *)((int)pfVar4 + 6) = *(short *)((int)pfVar4 + 6) - (short)(int)timeDelta;
        if (*(short *)((int)pfVar4 + 6) < 1) {
          *(undefined2 *)((int)pfVar4 + 6) = 0;
          *(undefined *)((int)pfVar4 + 0xd) = 0;
        }
      }
    }
    if (*(char *)(pfVar4 + 3) == '\x04') {
      if (*(char *)((int)pfVar4 + 0xe) != '\0') {
        (this->pos).rotation.x = (this->pos).rotation.x + -0x7fff;
        *(undefined *)(pfVar4 + 3) = 0;
      }
      local_28 = (longlong)(int)timeDelta;
      (this->pos).rotation.x = (this->pos).rotation.x + (short)(int)timeDelta * 3000;
    }
    dVar5 = (double)objDistObj2ObjXZ(param1,this);
    if (dVar5 < 20.0) {
      audioTryStartSfx((int *)this,0x10,0x49,0x7f,"duster.c",0xdf);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
      mainSetBits((int)*(short *)(pfVar4 + 2),1);
      *(undefined *)(pfVar4 + 4) = 1;
      if (this->hitstate != (HitState *)0x0) {
        FUN_80088da4((int)this);
      }
                    /* {@symbol 8012da08} */
      iVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x8c))();
      *(char *)(iVar2 + 0xb) = *(char *)(iVar2 + 0xb) + '\x01';
    }
    (this->pos).pos.y = (this->pos).pos.y + (this->vel).y;
  }
  return;
}


/* Library Function - Single Match
    dll_127_hitWallFn05
   
   Library: KioskDefault 0 0 */

void duster_hitWallFn05(ObjInstance *this) { //801E4534
  int iVar1;
  undefined *puVar2;
  ObjInstance *apOStack_64 [22];
  
  puVar2 = this->state;
  iVar1 = FUN_800bb7e0(6.0,&(this->oldPos).x,&(this->pos).pos.x,2,apOStack_64,this,8,-1,0xff,'\0');
  if (iVar1 != 0) {
    printf("hit wall");
    puVar2[0xe] = 1;
  }
  (this->oldPos).x = (this->pos).pos.x;
  (this->oldPos).y = (this->pos).pos.y;
  (this->oldPos).z = (this->pos).pos.z;
  return;
}


/* Library Function - Single Match
    dll_127_func06
   
   Library: KioskDefault 0 0 */

void duster_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801E45CC
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  
  puVar2 = this->state;
  if ((shouldRender) &&
     ((bVar1 = checkSomeDebugFlags_8017c4f8(), bVar1 ||
      ((puVar2[0xf] != '\0' && (puVar2[0x10] == '\0')))))) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void duster_free(ObjInstance *this,int param2) { //801E465C
  return;
}


undefined4 duster_func08(ObjInstance *this) { //801E4660
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int duster_getExtraSize(void) { //801E4668
  return 0x14;
}

