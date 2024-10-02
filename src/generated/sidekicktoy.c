
/* @description Set up object instance */

void sidekickToy_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //801D8D34
  ObjInstance *pOVar1;
  undefined *param1;
  undefined local_1c [4];
  undefined4 local_18;
  uint uStack_14;
  
  param1 = this->state;
  local_1c[0] = 5;
  memclr(param1,0x278);
  pOVar1 = Object_objGetMain();
  param1[0x26c] = 0;
  *(float *)(param1 + 0x264) = 0.0;
  *(float *)(param1 + 0x268) = 0.0;
  (this->pos).flags = (this->pos).flags | Invisible;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  if (pOVar1 != (ObjInstance *)0x0) {
    FUN_801a7ed4((int)pOVar1,this);
  }
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  uStack_14 = (int)(short)this->hitstate->field16_0x52 ^ 0x80000000;
  local_18 = 0x43300000;
  *(float *)(param1 + 0x260) = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0);
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(param1,0,&DAT_00040002,1);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(param1,1,&DAT_803116c8,param1 + 0x260,local_1c);
  FUN_80088da4((int)this);
  param1[599] = 0;
  objAllocMsgQueue(this,1);
  mainSetBits(0x3f8,0);
  return;
}


/* @description Update object instance */

void sidekickToy_update(ObjInstance *this) { //801D91B0
  byte bVar1;
  int iVar2;
  undefined uVar3;
  ObjInstance *param1;
  undefined *puVar4;
  undefined *local_14;
  longlong local_10;
  
  puVar4 = this->state;
  if ((*(float *)(puVar4 + 0x268) != 0.0) &&
     (*(float *)(puVar4 + 0x268) = *(float *)(puVar4 + 0x268) - timeDelta,
     *(float *)(puVar4 + 0x268) <= 0.0)) {
    *(float *)(puVar4 + 0x268) = 0.0;
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    FUN_80088d3c((int)this);
    puVar4[599] = 1;
  }
  while (iVar2 = FUN_80091100((int)this,(uint *)&local_14,(uint *)0x0,(uint *)0x0), iVar2 != 0) {
    if (local_14 == &DAT_0007000b) {
      *(float *)(puVar4 + 0x264) = 0.0;
      puVar4[0x26c] = 4;
    }
  }
  if (((puVar4[0x26c] == '\x02') || (puVar4[0x26c] == '\x01')) &&
     (*(float *)(puVar4 + 0x264) = *(float *)(puVar4 + 0x264) + timeDelta,
     120.0 <= *(float *)(puVar4 + 0x264))) {
    *(float *)(puVar4 + 0x264) = 0.0;
    puVar4[0x26c] = 4;
  }
  bVar1 = puVar4[0x26c];
  if (bVar1 == 2) {
    uVar3 = sidekickToyFn_801d8ef8(this);
    puVar4[0x26c] = uVar3;
  }
  else {
    if (bVar1 < 2) {
      if (((bVar1 != 0) && (true)) && ((this->flags_0xaf & CanPressAToTalk) != 0)) {
                    /* {@symbol 800d1668} */
        (**(code **)(*(int *)pDll_checkpoint + 0x7c))(0x5ba,0,0);
        *(undefined2 *)(puVar4 + 0x270) = 0x95;
        *(undefined2 *)(puVar4 + 0x272) = 0;
        *(float *)(puVar4 + 0x274) = 1.0;
        param1 = Object_objGetMain();
        objSendMsg((int)param1,0x7000a,(uint)this,(uint)(puVar4 + 0x270));
        puVar4[0x26c] = 3;
      }
    }
    else if (bVar1 == 4) {
      *(float *)(puVar4 + 0x264) = *(float *)(puVar4 + 0x264) + timeDelta;
      if (60.0 <= *(float *)(puVar4 + 0x264)) {
        Object_objFreeObject(this);
        return;
      }
      iVar2 = (int)((*(float *)(puVar4 + 0x264) * 255.0) / 60.0);
      local_10 = (longlong)iVar2;
      this->newOpacity = -(char)iVar2 - 1;
    }
    FUN_801d8e70(this,puVar4);
  }
  return;
}


/* @description Free object instance */

void sidekickToy_unload(ObjInstance *this,int param2) { //801D93C8
  ObjInstance *pOVar1;
  ObjInstance *local_10 [3];
  
  pOVar1 = Object_objGetMain();
  if ((pOVar1 != (ObjInstance *)0x0) && (FUN_801a7ea0((int)pOVar1,local_10), local_10[0] == this)) {
    FUN_801a7ed4((int)pOVar1,0);
  }
  mainSetBits(0x3f8,1);
  printf("the side kick toy is unloading");
  return;
}


/* @description Get extra size for object (size of State struct) */

int sidekickToy_getExtraSize(void) { //801D9440
  return 0x278;
}

