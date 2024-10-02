
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void statueball_initialise(undefined4 param) { //8028BFC8
  return;
}


/* @description Called when DLL is unloaded */

void statueball_release(void) { //8028BFCC
  return;
}


/* Library Function - Single Match
    dll_25B_func03
   
   Library: KioskDefault 0 0 */

void statueball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8028BFD0
  undefined *puVar1;
  
  puVar1 = this->state;
  *(undefined2 *)(puVar1 + 4) = *(undefined2 *)&objDef[1].bound;
  *(undefined2 *)(puVar1 + 6) = 0x19;
  this->flags_0xb0 = this->flags_0xb0 | DontUseRenderCallback;
  return;
}


/* Library Function - Single Match
    dll_25B_func04
   
   Library: KioskDefault 0 0 */

void statueball_update(ObjInstance *this) { //8028C004
  uint uVar1;
  ObjInstance *pOVar2;
  bool bVar4;
  int iVar3;
  ObjDef *pOVar5;
  ObjInstance **ppOVar6;
  double in_f1;
  int local_44;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
  pOVar5 = this->def;
  ppOVar6 = (ObjInstance **)this->state;
  local_44 = 0;
  local_30 = (longlong)(int)timeDelta;
  *(short *)((int)ppOVar6 + 6) = *(short *)((int)ppOVar6 + 6) - (short)(int)timeDelta;
  if (*(short *)((int)ppOVar6 + 6) < 1) {
    *(undefined2 *)((int)ppOVar6 + 6) = 0x19;
    uVar1 = mainGetBit((int)*(short *)(ppOVar6 + 1));
    if (uVar1 == 0) {
                    /* {@symbol 800ed30c} */
      in_f1 = (double)(**(code **)(*(int *)pDll_objfsa + 8))(this,0x396,0,0,0xffffffff,0);
    }
    else {
                    /* {@symbol 800ed30c} */
      in_f1 = (double)(**(code **)(*(int *)pDll_objfsa + 8))(this,0x3a7,0,0,0xffffffff,0);
    }
  }
  pOVar2 = Object_objGetMain();
  objDistObj2Obj(pOVar2,this);
  bVar4 = FUN_80068b20((int)this,0x40);
  if (bVar4) {
    if ((in_f1 < 190.0) && (*(char *)((int)ppOVar6 + 9) != '\0')) {
      audioTryStartSfx((int *)this,0x40,300,0x7f,(char *)&PTR_DAT_8031e2d8,0x65);
    }
  }
  else if ((90.0 <= in_f1) && (*(char *)((int)ppOVar6 + 9) != '\0')) {
    FUN_80068a9c((uint)this,0x40);
  }
  local_30 = (longlong)(int)timeDelta;
  (this->pos).rotation.x = (this->pos).rotation.x + (short)(int)timeDelta * 0x82;
  local_38 = (longlong)(int)timeDelta;
  (this->pos).rotation.y = (this->pos).rotation.y + (short)(int)timeDelta * 0x6e;
  local_40 = (longlong)(int)timeDelta;
  (this->pos).rotation.z = (this->pos).rotation.z + (short)(int)timeDelta * 0x32;
  *(undefined *)((int)ppOVar6 + 0xb) = *(undefined *)((int)ppOVar6 + 9);
  iVar3 = FUN_800883e4((int)this,&local_44,(int *)0x0,(uint *)0x0);
  if ((((local_44 != 0) && (iVar3 != 0)) && (local_44 != 0)) &&
     (*(short *)(local_44 + 0x46) == 0x14b)) {
    *(char *)((int)ppOVar6 + 9) = '\x01' - *(char *)((int)ppOVar6 + 9);
  }
  if ((*(char *)((int)ppOVar6 + 9) != '\0') && (*(char *)((int)ppOVar6 + 10) != '\0')) {
    *(undefined *)((int)ppOVar6 + 10) = 0;
    audioTryStartSfx((int *)this,1,0x37,0x7f,(char *)&PTR_DAT_8031e2d8,0x7c);
  }
  uVar1 = mainGetBit((int)*(short *)(ppOVar6 + 1));
  if ((uVar1 == 0) || ((this->pos).pos.x <= (pOVar5->pos).x - 30.0)) {
    uVar1 = mainGetBit((int)*(short *)(ppOVar6 + 1));
    if ((uVar1 == 0) &&
       (((this->pos).pos.x < (pOVar5->pos).x &&
        ((this->pos).pos.x = (this->pos).pos.x + 0.4, (pOVar5->pos).x < (this->pos).pos.x)))) {
      (this->pos).pos.x = (pOVar5->pos).x;
    }
  }
  else {
    (this->pos).pos.x = (this->pos).pos.x - 0.2;
    if ((this->pos).pos.x < (pOVar5->pos).x - 30.0) {
      (this->pos).pos.x = (pOVar5->pos).x - 30.0;
    }
  }
  if (*ppOVar6 != (ObjInstance *)0x0) {
    ((*ppOVar6)->pos).pos.x = (this->pos).pos.x;
    ((*ppOVar6)->pos).pos.y = (this->pos).pos.y;
    ((*ppOVar6)->pos).pos.z = (this->pos).pos.z;
    ((*ppOVar6)->pos).rotation.x = (this->pos).rotation.x;
    ((*ppOVar6)->pos).rotation.y = (this->pos).rotation.y;
    ((*ppOVar6)->pos).rotation.z = (this->pos).rotation.z;
  }
  if (*(char *)((int)ppOVar6 + 9) != *(char *)((int)ppOVar6 + 0xb)) {
    if (*(char *)((int)ppOVar6 + 9) == '\0') {
      FUN_80068a9c((uint)this,0x40);
                    /* {@symbol 800dc1d4} */
      (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
      if ((*(short *)(ppOVar6 + 1) != -1) &&
         (uVar1 = mainGetBit((int)*(short *)(ppOVar6 + 1)), uVar1 != 0)) {
        mainSetBits((int)*(short *)(ppOVar6 + 1),0);
      }
      if (*ppOVar6 != (ObjInstance *)0x0) {
        Object_objFreeObject(*ppOVar6);
        *ppOVar6 = (ObjInstance *)0x0;
      }
    }
    else {
      for (iVar3 = 0; iVar3 < 0x28; iVar3 = iVar3 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x392,0,0,0xffffffff,0);
      }
      if ((*(short *)(ppOVar6 + 1) != -1) &&
         (uVar1 = mainGetBit((int)*(short *)(ppOVar6 + 1)), uVar1 == 0)) {
        mainSetBits((int)*(short *)(ppOVar6 + 1),1);
      }
      *(undefined *)((int)ppOVar6 + 10) = 1;
      if (*ppOVar6 == (ObjInstance *)0x0) {
        pOVar5 = objAlloc(0x28,LFXEmitter);
        pOVar5->bound = 0xaf;
        pOVar5->cullDist = 0xaf;
        pOVar5->loadFlags = OnlyLoadIfNearPlayer;
        pOVar5->mapStates2 = 2;
        (pOVar5->pos).x = (this->pos).pos.x;
        (pOVar5->pos).y = (this->pos).pos.y;
        (pOVar5->pos).z = (this->pos).pos.z;
        pOVar5[1].bound = 1;
        pOVar5[1].cullDist = 0x73;
        *(undefined2 *)((int)&pOVar5[1].pos.x + 2) = 0xffff;
        pOVar2 = objInstantiateCharacter(pOVar5,5,(int)(char)this->mapId,-1,this->pMatrix);
        *ppOVar6 = pOVar2;
        ((*ppOVar6)->pos).pos.x = (this->pos).pos.x;
        ((*ppOVar6)->pos).pos.y = (this->pos).pos.y;
        ((*ppOVar6)->pos).pos.z = (this->pos).pos.z;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_25B_func05
   
   Library: KioskDefault 0 0 */

void statueball_hitDetect(ObjInstance *this) { //8028C51C
  int *piVar1;
  
  piVar1 = (int *)this->state;
  if ((*piVar1 != 0) && ((*(ushort *)(*piVar1 + 6) & 0x40) != 0)) {
    *piVar1 = 0;
  }
  return;
}


/* @description Override render */

void statueball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8028C558
  return;
}


/* @description Free object instance */

void statueball_free(ObjInstance *this,int param2) { //8028C55C
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 statueball_func08(ObjInstance *this) { //8028C594
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int statueball_getExtraSize(void) { //8028C59C
  return 0x10;
}

