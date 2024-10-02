
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void cannontargetControl_initialise(undefined4 param) { //80222214
  return;
}


/* @description Called when DLL is unloaded */

void cannontargetControl_release(void) { //80222218
  return;
}


/* Library Function - Single Match
    dll_1BE_func03
   
   Library: KioskDefault 0 0 */

void cannontargetControl_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8022221C
  mainSetBits(0x8d,0);
  mainSetBits(0x94,0);
  mainSetBits(0x8f,0);
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_1BE_func04
   
   Library: KioskDefault 0 0 */

void cannontargetControl_update(ObjInstance *this) { //80222270
  ObjInstance *pOVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  double dVar5;
  
  _savefpr_30();
  pcVar4 = this->state;
  if (*(int *)(pcVar4 + 0x28) == 0) {
    pOVar1 = Object_objGetMain();
    *(ObjInstance **)(pcVar4 + 0x28) = pOVar1;
  }
  if (*(int *)(pcVar4 + 0x2c) == 0) {
    pOVar1 = getSeqObj(4,this,(float *)0x0);
    *(ObjInstance **)(pcVar4 + 0x2c) = pOVar1;
  }
  if ((*(int *)(pcVar4 + 0x28) != 0) && (*(int *)(pcVar4 + 0x2c) != 0)) {
    dVar5 = (double)objDistObj2ObjXZ(*(ObjInstance **)(pcVar4 + 0x28),
                                     *(ObjInstance **)(pcVar4 + 0x2c));
    dVar5 = (double)((float)(dVar5 - 10.0) * 0.25 + 45.0);
    if (dVar5 <= 60.0) {
      if (dVar5 < 45.0) {
        dVar5 = 45.0;
      }
    }
    else {
      dVar5 = 60.0;
    }
                    /* {@symbol 80153970} */
    iVar2 = (**(code **)(*(int *)pDll_ObjSeq + 0xc))();
    *(float *)(iVar2 + 0xb0) = (float)dVar5;
    if (*pcVar4 == '\x01') {
      mainSetBits(0x8d,0);
      mainSetBits(0x94,0);
      mainSetBits(0x8f,0);
      *pcVar4 = '\0';
      *(float *)(pcVar4 + 4) = 0.0;
    }
    else if ((*pcVar4 == '\0') && (true)) {
      *(float *)(pcVar4 + 4) = *(float *)(pcVar4 + 4) + timeDelta;
      uVar3 = mainGetBit(0x8d);
      if ((uVar3 != 0) &&
         ((uVar3 = mainGetBit(0x94), uVar3 != 0 && (uVar3 = mainGetBit(0x8f), uVar3 != 0)))) {
        audioTryStartSfx((int *)this,1,0x160,0x7f,"cannontargetControl.c",0x68);
        if ((1800.0 <= *(float *)(pcVar4 + 4)) || (uVar3 = mainGetBit(0x90), uVar3 != 0)) {
          FUN_802224e0((int)this,(int)pcVar4);
        }
        else {
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
        }
        *pcVar4 = '\x01';
      }
    }
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void cannontargetControl_hitDetect(ObjInstance *this) { //8022246C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void cannontargetControl_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80222470
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


/* @description Free object instance */

void cannontargetControl_free(ObjInstance *this,int param2) { //802224CC
  return;
}


undefined4 cannontargetControl_func08(ObjInstance *this) { //802224D0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int cannontargetControl_getExtraSize(void) { //802224D8
  return 0x30;
}

