
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIM2snowball_initialise(undefined4 param) { //8022BE50
  return;
}


/* @description Called when DLL is unloaded */

void DIM2snowball_release(void) { //8022BE54
  return;
}


/* Library Function - Single Match
    DIM2snowball_func03
   
   Library: KioskDefault 0 0 */

void DIM2snowball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8022BE58
  ObjInstance *pOVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  *(int *)(puVar2 + 0xa0) = objDef->id;
  puVar2[0xac] = puVar2[0xac] | 4;
  objDef->id = -1;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->newOpacity = 0;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa10;
  }
  pOVar1 = Object_findByUniqueId(*(int *)(puVar2 + 0xa0));
  *(ObjInstance **)(puVar2 + 0x9c) = pOVar1;
  if (*(int *)(puVar2 + 0x9c) == 0) {
    printf("DIM2snowball: Lost generator");
  }
  else {
    this->flags_0xb0 = this->flags_0xb0 | DontMove;
  }
  return;
}


/* Library Function - Single Match
    DIM2snowball_func04
   
   Library: KioskDefault 0 0 */

void DIM2snowball_update(ObjInstance *this) { //8022BF14
  char cVar1;
  float fVar2;
  ObjInstance *pOVar3;
  int iVar4;
  int iVar5;
  HitState *pHVar6;
  uint uVar7;
  Curve *param1;
  undefined auStack_3c [12];
  float local_30;
  float local_2c;
  float local_28;
  int local_24 [2];
  
  param1 = (Curve *)this->state;
  if ((*(byte *)&param1[1].field4_0x10 & 4) == 0) {
    if ((*(byte *)&param1[1].field4_0x10 & 8) != 0) {
      iVar4 = (uint)this->newOpacity + (uint)framesThisStep * -2;
      if (iVar4 < 0) {
        iVar4 = 0;
        *(byte *)&param1[1].field4_0x10 = *(byte *)&param1[1].field4_0x10 & 0xf7;
      }
      this->newOpacity = (u8)iVar4;
    }
  }
  else {
    uVar7 = (uint)this->newOpacity + (uint)framesThisStep * 2;
    if (0xff < uVar7) {
      uVar7 = 0xff;
      *(byte *)&param1[1].field4_0x10 = *(byte *)&param1[1].field4_0x10 & 0xfb;
    }
    this->newOpacity = (u8)uVar7;
  }
  if ((*(byte *)&param1[1].field4_0x10 & 1) == 0) {
    fVar2 = (float)(**(code **)(**(int **)((int)param1[1].field0_0x0 + 0x68) + 0x20))
                             (param1[1].field0_0x0,&param1->field90_0x84,&param1->field91_0x88,
                              &param1->field92_0x8c,&param1[1].field3_0xc);
    param1->field93_0x90 = fVar2;
    param1->field89_0x80 = 0.0;
    param1->field94_0x94 = FUN_8006bba0;
    param1->field95_0x98 = curveFn_80010d54;
    curvesMove(param1);
    *(byte *)&param1[1].field4_0x10 = *(byte *)&param1[1].field4_0x10 | 1;
  }
  if ((*(byte *)&param1[1].field4_0x10 & 2) == 0) {
    iVar4 = FUN_8006c2c8(2.099999904632568,(float *)param1);
    (this->pos).pos.x = param1->field83_0x68;
    (this->pos).pos.y = param1->field84_0x6c + 30.0;
    (this->pos).pos.z = param1->field85_0x70;
    iVar5 = getAngle();
    (this->pos).rotation.x = (short)iVar5;
    (this->pos).rotation.y = (this->pos).rotation.y + (ushort)framesThisStep * 800;
    (this->vel).x = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
    (this->vel).y = 0.0;
    (this->vel).z = prevOneOverTimeDelta * ((this->pos).pos.z - (this->oldPos).z);
    if (iVar4 != 0) {
      Object_objFreeObject(this);
    }
    if ((*(char *)((int)param1[1].field3_0xc + ((int)param1->field4_0x10 >> 2)) == ' ') &&
       (uVar7 = mainGetBit(0x288), uVar7 != 0)) {
      *(byte *)&param1[1].field4_0x10 = *(byte *)&param1[1].field4_0x10 | 2;
      iVar4 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                           (double)(this->pos).pos.z,(int)this,local_24,0,0);
      param1[1].field2_0x8 = (this->pos).pos.y;
      while (0 < iVar4) {
        iVar4 = iVar4 + -1;
        if ((**(float **)(local_24[0] + iVar4 * 4) < (this->pos).pos.y) &&
           ((*(char *)(*(int *)(local_24[0] + iVar4 * 4) + 0x14) == '\x1a' ||
            (*(char *)(*(int *)(local_24[0] + iVar4 * 4) + 0x14) == '\b')))) {
          param1[1].field2_0x8 = **(float **)(local_24[0] + iVar4 * 4);
          iVar4 = 0;
        }
      }
      (this->vel).x = (this->vel).x * 0.75;
      (this->vel).z = (this->vel).z * 0.75;
    }
  }
  else if (param1[1].field2_0x8 <= (this->pos).pos.y) {
    (this->vel).x = (this->vel).x * 0.98;
    (this->vel).y = -(timeDelta * 0.1 - (this->vel).y);
    (this->vel).z = (this->vel).z * 0.98;
    objMove((double)((this->vel).x * timeDelta),(double)((this->vel).y * timeDelta),
            (double)((this->vel).z * timeDelta),this);
    iVar4 = FUN_800bb7e0(36.0,&(this->oldPos).x,&(this->pos).pos.x,0,(ObjInstance **)0x0,this,8,-1,0
                         ,'\0');
    if (iVar4 != 0) {
      (this->vel).x = -(this->vel).x;
      (this->vel).z = -(this->vel).z;
      (this->vel).x = (this->vel).x * 0.75;
      (this->vel).z = (this->vel).z * 0.75;
    }
  }
  else {
    (this->vel).x = (this->vel).x * 0.9;
    (this->vel).y = -0.1;
    (this->vel).z = (this->vel).z * 0.9;
    if ((*(byte *)&param1[1].field4_0x10 & 0x10) == 0) {
      (this->vel).x = (this->vel).x * 0.05;
      (this->vel).z = (this->vel).z * 0.05;
      *(byte *)&param1[1].field4_0x10 = *(byte *)&param1[1].field4_0x10 | 0x18;
      pOVar3 = FUN_8022c4e4();
      if (pOVar3 != (ObjInstance *)0x0) {
        (*(code *)pOVar3->dll->ptrs2->setScale)(pOVar3);
      }
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x52,0x7f,"DIM2snowball.c",
                          (int *)&DAT_000000b4);
    }
    local_30 = (this->pos).pos.x;
    local_2c = (this->pos).pos.y;
    local_28 = (this->pos).pos.z;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x206,auStack_3c,4,0xffffffff,0);
    if (this->newOpacity == 0) {
      Object_objFreeObject(this);
    }
    objMove((double)((this->vel).x * timeDelta),(double)((this->vel).y * timeDelta),
            (double)((this->vel).z * timeDelta),this);
  }
  if (this->newOpacity == 0xff) {
    pHVar6 = this->hitstate;
    if (pHVar6 != (HitState *)0x0) {
      pHVar6->flags = pHVar6->flags | 1;
      *(undefined *)((int)&pHVar6->sizeX2 + 1) = 4;
      *(undefined *)&pHVar6->flags_0x60 = 2;
      (pHVar6->field12_0x3c).y = 2.242078e-44;
      (pHVar6->field12_0x3c).z = 2.242078e-44;
    }
  }
  cVar1 = *(char *)((int)&param1[1].field4_0x10 + 1) - framesThisStep;
  *(char *)((int)&param1[1].field4_0x10 + 1) = cVar1;
  if (cVar1 < '\x01') {
    audioTryStartSfx((int *)this,0x40,0x40,0x7f,"DIM2snowball.c",0x10a);
    *(undefined *)((int)&param1[1].field4_0x10 + 1) = 0x78;
  }
  return;
}


/* @description Override hit detection */

void DIM2snowball_hitDetect(ObjInstance *this) { //8022C460
  return;
}


/* @description Override render */

void DIM2snowball_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8022C464
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    FUN_80096afc(0x23,0x17,0x19);
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DIM2snowball_free(ObjInstance *this,int param2) { //8022C4D0
  return;
}


undefined4 DIM2snowball_func08(ObjInstance *this) { //8022C4D4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIM2snowball_getExtraSize(void) { //8022C4DC
  return 0xb0;
}

