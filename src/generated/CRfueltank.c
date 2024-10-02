
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CRfueltank_initialise(undefined4 param) { //802AAE70
  return;
}


/* @description Called when DLL is unloaded */

void CRfueltank_release(void) { //802AAE74
  return;
}


/* Library Function - Single Match
    dll_2A6_func03
   
   Library: KioskDefault 0 0 */

void CRfueltank_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802AAE78
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short *param1;
  
  param1 = (short *)this->state;
  this->flags_0xb0 = this->flags_0xb0 | DontUseRenderCallback;
  FUN_80088d3c((int)this);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  objHitFn_80089074(this,0x1d,(char)((int)sVar1 / 10),0);
  timerReset(param1);
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  if ((sVar2 != -1) &&
     (sVar3._0_1_ = objDef[1].bound, sVar3._1_1_ = objDef[1].cullDist,
     uVar4 = mainGetBit((int)sVar3), uVar4 != 0)) {
    timerSet(param1,0x708);
    FUN_80088da4((int)this);
    (this->pos).flags = (this->pos).flags | Invisible;
    this->newOpacity = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_2A6_func04
   
   Library: KioskDefault 0 0 */

void CRfueltank_update(ObjInstance *this) { //802AAF24
  short sVar1;
  int iVar2;
  ObjDef *pOVar3;
  short *param1;
  
  pOVar3 = this->def;
  param1 = (short *)this->state;
  iVar2 = timerTickDown(param1);
  if (iVar2 == 0) {
    if (this->newOpacity < 0xff) {
      if (framesThisStep < this->newOpacity) {
        this->newOpacity = this->newOpacity + framesThisStep * -2;
        (this->pos).scale = (this->pos).scale * 1.1;
        this->flags_0xf8 = 0;
      }
      else {
        (this->pos).flags = (this->pos).flags | Invisible;
        timerSet(param1,0x708);
      }
    }
    else {
      sVar1._0_1_ = pOVar3[1].allocatedSize;
      sVar1._1_1_ = pOVar3[1].mapStates1;
      objHitFn_80089074(this,0x1d,(char)((int)sVar1 / 10),0);
    }
  }
  else {
    FUN_80088d3c((int)this);
    (this->pos).flags = (this->pos).flags & ~Invisible;
    this->newOpacity = 0xff;
  }
  return;
}


/* Library Function - Single Match
    dll_2A6_func05
   
   Library: KioskDefault 0 0 */

void CRfueltank_hitDetect(ObjInstance *this) { //802AB008
  short sVar1;
  short sVar2;
  ObjDef *pOVar3;
  HitState *pHVar4;
  
  pHVar4 = this->hitstate;
  pOVar3 = this->def;
  if (((pHVar4 != (HitState *)0x0) && (pHVar4->field13_0x48 != 0)) &&
     (*(short *)(pHVar4->field13_0x48 + 0x46) == 0x38c)) {
    FUN_80088da4((int)this);
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x1eb,0x7f,"CRfueltank.c",(int *)0x7f);
    this->newOpacity = 0xfa;
    this->flags_0xf8 = 1;
    sVar1._0_1_ = pOVar3[1].bound;
    sVar1._1_1_ = pOVar3[1].cullDist;
    if (sVar1 != -1) {
      sVar2._0_1_ = pOVar3[1].bound;
      sVar2._1_1_ = pOVar3[1].cullDist;
      mainSetBits((int)sVar2,1);
    }
  }
  return;
}


/* @description Override render */

void CRfueltank_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //802AB0B4
  return;
}


/* @description Free object instance */

void CRfueltank_free(ObjInstance *this,int param2) { //802AB0B8
  return;
}


undefined4 CRfueltank_func08(ObjInstance *this) { //802AB0BC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CRfueltank_getExtraSize(void) { //802AB0C4
  return 2;
}

