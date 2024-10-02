
/* @description Set up object instance */

void landedArwing_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //801ED174
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* @description Update object instance */

void landedArwing_update(ObjInstance *this) { //801ED184
  int iVar1;
  ObjInstance *pOVar2;
  
  iVar1 = objLockFn_80092258((int)this);
  if (iVar1 != 0) {
    audioStopAllSongs();
    pOVar2 = getSeqObj(0x11,this,(float *)0x0);
    if (pOVar2 == (ObjInstance *)0x0) {
                    
      OSPanic("landedArwing.c",0x3a,"Failed assertion seqObj");
    }
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,pOVar2,0xffffffff);
  }
  return;
}

