
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFBaby_initialise(undefined4 param) { //80206668
  return;
}


/* @description Called when DLL is unloaded */

void CFBaby_release(void) { //8020666C
  return;
}


/* Library Function - Single Match
    CFBaby_func03
   
   Library: KioskDefault 0 0 */

void CFBaby_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //80206670
  uint uVar1;
  undefined2 *param1;
  
  FUN_80088d3c((int)this);
  objAllocMsgQueue(this,4);
  this->fptr_0xbc = FUN_80206ab0;
  (this->pos).rotation.x = (ushort)objDef[1].mapStates2 << 8;
  Object_objAddObjectType(this,0x22);
  Object_objAddObjectType(this,4);
  param1 = (undefined2 *)this->state;
  *(undefined4 *)(param1 + 0x4c) = 0;
  *(undefined4 *)(param1 + 0x4e) = 0;
  *(undefined4 *)(param1 + 0x50) = 0;
  *(undefined4 *)(param1 + 0x52) = 0;
  *(undefined4 *)(param1 + 0x54) = 0;
  *(uint *)(param1 + 0x56) = (uint)objDef[1].loadFlags;
  *(undefined4 *)(param1 + 0x5a) = 0;
  timerReset(param1);
  *(undefined4 *)(param1 + 0x7e) = 0;
  param1[0x5c] = (this->pos).rotation.x;
  *(undefined *)(param1 + 0x10a) = 0;
  *(float *)(param1 + 0x48) = 0.01;
  uVar1 = mainGetBit((int)*(short *)((int)&objDef[1].pos.x + 2));
  if (uVar1 != 0) {
    FUN_80088da4((int)this);
    (this->pos).flags = (this->pos).flags | Invisible;
    *(byte *)(param1 + 0x10a) = *(byte *)(param1 + 0x10a) & 0xfe;
    objFreeFn_80083b54(this);
    Object_removePlayerObj(this,0x22);
    Object_removePlayerObj(this,4);
  }
  return;
}


/* Library Function - Single Match
    CFBaby_func04
   
   Library: KioskDefault 0 0 */

void CFBaby_update(ObjInstance *this) { //80206798
  short sVar1;
  int iVar2;
  uint uVar3;
  ObjInstance *pOVar4;
  ObjDef *pOVar5;
  short *param1;
  
  pOVar5 = this->def;
  param1 = (short *)this->state;
  Object_objGetMain();
  Object_getSidekicksLoaded();
  iVar2 = timerGetTime(param1);
  if (iVar2 == 0) {
    pOVar4 = Object_objGetMain();
    FUN_80206eec(this,(int)pOVar4,(int)param1);
    iVar2 = objRunAnimation((double)*(float *)(param1 + 0x48),(double)timeDelta,(int)this,
                            (float *)0x0);
    if (iVar2 != 0) {
      uVar3 = timerRand(2);
      if (uVar3 == 0) {
        Object_ObjAnimSetMove(0.0,this,0,0);
      }
      else {
        Object_ObjAnimSetMove(0.0,this,2,0);
      }
    }
    uVar3 = timerRand(0x3c);
    if (uVar3 != 0) {
      iVar2 = randInt(0,3);
      FUN_8009457c((int *)this,(undefined *)(param1 + 0x30),*(ushort *)(&DAT_80397c88 + iVar2 * 2));
    }
    exprFn_800945c0((uint)this,(char *)(param1 + 0x30));
  }
  else {
    *(byte *)(param1 + 0x10a) = *(byte *)(param1 + 0x10a) | 1;
    if ((*param1 < 0x1e) && (this->field76_0xf4 != 0)) {
      (this->pos).rotation.x = param1[0x5c];
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(4,this,0xffffffff);
      *param1 = 5;
                    /* {@symbol 80172e94} */
      (**(code **)(*pdll_camcontrol + 0x54))(0,4,0x571,0x572,4);
      uVar3 = mainGetBit(0x901);
                    /* {@symbol 8017305c} */
      (**(code **)(*pdll_camcontrol + 0x58))(4 - uVar3);
      mainIncBit(0x901);
      *(undefined4 *)(param1 + 0x56) = 0xc;
      sVar1._0_1_ = pOVar5[1].bound;
      sVar1._1_1_ = pOVar5[1].cullDist;
      mainSetBits((int)sVar1,1);
      this->field76_0xf4 = 0;
    }
    else {
      *(undefined4 *)(param1 + 0x56) = 0;
      iVar2 = timerTickDown(param1);
      if (iVar2 != 0) {
        if (*(short *)((int)&pOVar5[1].pos.x + 2) != -1) {
          mainSetBits((int)*(short *)((int)&pOVar5[1].pos.x + 2),1);
        }
        printf(" The Birdy End is Nigh ");
        FUN_80088da4((int)this);
        (this->pos).flags = (this->pos).flags | Invisible;
        *(byte *)(param1 + 0x10a) = *(byte *)(param1 + 0x10a) & 0xfe;
        objFreeFn_80083b54(this);
        Object_removePlayerObj(this,0x22);
        Object_removePlayerObj(this,4);
                    /* {@symbol 80173394} */
        (**(code **)(*pdll_camcontrol + 0x60))();
        (this->pos).flags = (this->pos).flags | Invisible;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void CFBaby_hitDetect(ObjInstance *this) { //80206A00
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void CFBaby_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //80206A04
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


/* Library Function - Single Match
    CFBaby_func07
   
   Library: KioskDefault 0 0 */

void CFBaby_free(ObjInstance *this,int param2) { //80206A60
  Object_removePlayerObj(this,0x22);
  Object_removePlayerObj(this,4);
  return;
}


undefined4 CFBaby_func08(ObjInstance *this) { //80206AA0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CFBaby_getExtraSize(void) { //80206AA8
  return 0x218;
}


/* Library Function - Single Match
    CFBaby_func0A
   
   Library: KioskDefault 0 0 */

void CFBaby_setScale(ObjInstance *this,float scale) { //80206E0C
  countLeadingZeros((byte)this->state[0x214] & 1);
  return;
}


/* Library Function - Single Match
    CFBaby_flyAway
   
   Library: KioskDefault 0 0 */

bool CFBaby_flyAway(ObjInstance *param1) { //80206E34
  short sVar1;
  ObjInstance *param1_00;
  ObjDef *pOVar2;
  short *param1_01;
  bool bVar3;
  double in_f1;
  
  param1_01 = (short *)param1->state;
  param1_00 = Object_objGetMain();
  pOVar2 = param1->def;
  objDistObj2Obj(param1_00,param1);
  sVar1._0_1_ = pOVar2[1].allocatedSize;
  sVar1._1_1_ = pOVar2[1].mapStates1;
  bVar3 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0)
          <= in_f1;
  if (bVar3) {
    exprFn_8009446c((int *)param1,(undefined *)(param1_01 + 0x30),0x23b,0x1000,0xffffffff,'\x01');
  }
  else {
    timerSet(param1_01,0x3c);
    param1->field76_0xf4 = 1;
    printf(" FLYING AWAY");
  }
  return !bVar3;
}

