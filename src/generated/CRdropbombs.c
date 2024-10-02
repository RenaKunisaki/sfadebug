
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void zBomb02A7_initialise(undefined4 param) { //802AB0CC
  return;
}


/* @description Called when DLL is unloaded */

void zBomb02A7_release(void) { //802AB0D0
  return;
}


/* Library Function - Single Match
    zBomb02A7_func03
   
   Library: KioskDefault 0 0 */

void zBomb02A7_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802AB0D4
  char cVar1;
  short param2;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  (this->pos).rotation.x = 0;
  if (this->hitstate != (HitState *)0x0) {
    (this->hitstate->field12_0x3c).z = 2.242078e-44;
    (this->hitstate->field12_0x3c).y = 2.242078e-44;
    FUN_80088da4((int)this);
  }
  *(undefined *)(pfVar2 + 4) = 0;
  timerReset((undefined2 *)(pfVar2 + 2));
  timerReset((undefined2 *)(pfVar2 + 3));
  timerReset((undefined2 *)((int)pfVar2 + 0xe));
  timerSet((short *)((int)pfVar2 + 0xe),5);
  timerReset((undefined2 *)((int)pfVar2 + 10));
  (this->pos).rotation.x = (short)((int)(short)*(char *)&objDef[1].objType << 8);
  *(undefined *)((int)pfVar2 + 0x12) = 0xff;
  *(undefined *)((int)pfVar2 + 0x13) = 0;
  *pfVar2 = 50.0;
  cVar1 = *(char *)((int)&objDef[1].objType + 1);
  if (cVar1 == '\x01') {
    timerSet((short *)((int)pfVar2 + 10),800);
    (this->pos).rotation.x = *(short *)&objDef[1].allocatedSize;
    *(undefined *)(pfVar2 + 4) = 0xff;
  }
  else if ((cVar1 < '\x01') && (-1 < cVar1)) {
    param2._0_1_ = objDef[1].allocatedSize;
    param2._1_1_ = objDef[1].mapStates1;
    timerSet((short *)(pfVar2 + 3),param2);
    *(undefined *)(pfVar2 + 4) = 2;
  }
  return;
}


/* Library Function - Single Match
    zBomb02A7_func04
   
   Library: KioskDefault 0 0 */

void zBomb02A7_update(ObjInstance *this) { //802AB1F0
  char cVar1;
  int iVar2;
  ObjInstance *param2;
  uint uVar3;
  undefined *puVar4;
  double dVar5;
  double dVar6;
  short local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  
  puVar4 = this->state;
  iVar2 = timerGetTime((short *)(puVar4 + 0xc));
  if (iVar2 != 0) {
    audioTryStartSfx((int *)this,0xc0,0x68,0x39,"CRdropbombs.c",0xea);
    iVar2 = timerTickDown((short *)(puVar4 + 0xc));
    if (iVar2 != 0) {
      FUN_802ab778(this);
      return;
    }
  }
  cVar1 = puVar4[0x10];
  if (cVar1 == '\x01') {
LAB_802ab394:
    iVar2 = timerTickDown((short *)(puVar4 + 10));
    if (iVar2 != 0) {
      FUN_802ab708((int)this);
      return;
    }
    if (-10.0 < (this->vel).y) {
      (this->vel).y = timeDelta * -0.12 + (this->vel).y;
    }
    (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * 0x200;
    (this->pos).rotation.y = (this->pos).rotation.y + (ushort)framesThisStep * 0x100;
    (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
    (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
    (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
    (this->prevPos).x = (this->pos).pos.x;
    (this->prevPos).y = (this->pos).pos.y;
    (this->prevPos).z = (this->pos).pos.z;
  }
  else {
    if (cVar1 < '\x01') {
      if (cVar1 != -1) {
        if ((-2 < cVar1) && (iVar2 = timerGetTime((short *)(puVar4 + 8)), iVar2 != 0)) {
          FUN_80068a9c((uint)this,0x40);
          iVar2 = timerTickDown((short *)(puVar4 + 8));
          if (iVar2 != 0) {
            Object_objFreeObject(this);
          }
        }
        goto LAB_802ab4b8;
      }
      param2 = Object_objGetMain();
      dVar5 = (double)objDistObj2ObjXZ(this,param2);
      puVar4[0x10] = 1;
      (this->vel).x = 0.0;
      dVar6 = sqrt(dVar5);
      (this->vel).y = (float)(dVar6 / 15.0) + 2.2;
      dVar5 = sqrt(dVar5);
      (this->vel).z = -2.2 - (float)(dVar5 / 15.0);
      local_30 = 0.0;
      local_2c = 0.0;
      local_28 = 0.0;
      local_34 = 1.0;
      local_38 = 0;
      local_3a = 0;
      local_3c = (this->pos).rotation.x;
      FUN_8007a878(&local_3c,&(this->vel).x);
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x59,0x7f,"CRdropbombs.c",(int *)0x11a)
      ;
      goto LAB_802ab394;
    }
    if ('\x02' < cVar1) goto LAB_802ab4b8;
  }
  uVar3 = timerRand(2);
  if (uVar3 != 0) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51c,0,1,0xffffffff,0);
  }
  iVar2 = timerTickDown((short *)(puVar4 + 0xe));
  if (iVar2 != 0) {
    FUN_80088d3c((int)this);
  }
  objHitFn_80089074(this,0xd,3,0);
LAB_802ab4b8:
  iVar2 = getBlockIdxAtCoords((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                              (double)(this->pos).pos.z);
  if (iVar2 == -1) {
    FUN_802ab708((int)this);
  }
  return;
}


/* Library Function - Single Match
    zBomb02A7_func05
   
   Library: KioskDefault 0 0 */

void zBomb02A7_hitDetect(ObjInstance *this) { //802AB4F0
  int iVar1;
  
  iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if ((this->hitstate->field54_0x9d != 0) || (iVar1 != 0)) {
    FUN_802ab708((int)this);
  }
  return;
}


/* Library Function - Single Match
    zBomb02A7_func06
   
   Library: KioskDefault 0 0 */

void zBomb02A7_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802AB550
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  iVar1 = timerGetTime((short *)(pfVar2 + 2));
  if (iVar1 == 0) {
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)*pfVar2,35.0,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
    if (*(short *)(pfVar2 + 3) != 0) {
      if (*(short *)(pfVar2 + 3) < 0x3c) {
        *(u8 *)((int)pfVar2 + 0x12) = *(char *)((int)pfVar2 + 0x12) + framesThisStep * '\n';
        if (0x80 < *(byte *)((int)pfVar2 + 0x12)) {
          *(undefined *)((int)pfVar2 + 0x12) = 0;
        }
        FUN_80096b14(200,0x1e,0x1e,*(undefined *)((int)pfVar2 + 0x12));
      }
      else if (*(short *)(pfVar2 + 3) < 0xf0) {
        *(u8 *)((int)pfVar2 + 0x12) = *(char *)((int)pfVar2 + 0x12) + framesThisStep * '\x05';
        if (0x80 < *(byte *)((int)pfVar2 + 0x12)) {
          *(undefined *)((int)pfVar2 + 0x12) = 0;
        }
        FUN_80096b14(200,0x1e,0x1e,*(undefined *)((int)pfVar2 + 0x12));
      }
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    zBomb02A7_func07
    zBomb_func07
   
   Library: KioskDefault 0 0 */

void zBomb02A7_free(ObjInstance *this,int param2) { //802AB690
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_8039a128);
  DAT_8039a128 = (LoadedDll *)0x0;
  DLL_free(DAT_8039a12c);
  DAT_8039a12c = (LoadedDll *)0x0;
  return;
}


undefined4 zBomb02A7_func08(ObjInstance *this) { //802AB6F8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int zBomb02A7_getExtraSize(void) { //802AB700
  return 0x18;
}


/* Library Function - Single Match
    CRdropbombsFn_802ab86c
   
   Library: KioskDefault 0 0 */

void CRdropbombsFn_802ab86c(int param1) { //802AB86C
  ObjDef *def;
  
  if (param1 == 0) {
                    
    OSPanic("CRdropbombs.c",0x1f9,"Failed assertion obj");
  }
  def = objAlloc(0x24,DIMExplosio);
  def->loadFlags = isManualLoad;
  def->mapStates2 = 1;
  (def->pos).x = *(float *)(param1 + 0xc);
  (def->pos).y = *(float *)(param1 + 0x10);
  (def->pos).z = *(float *)(param1 + 0x14);
  def[1].allocatedSize = 0xc;
  def[1].mapStates1 = 0;
  objInstantiateCharacter(def,5,(int)*(char *)(param1 + 0xac),-1,*(ObjInstance **)(param1 + 0x30));
  return;
}

