
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void dll_158_initialise(undefined4 param) { //8025E884
  return;
}


/* @description Called when DLL is unloaded */

void dll_158_release(void) { //8025E888
  return;
}


/* @description Set up object instance */

void dll_158_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //8025E88C
  (this->pos).rotation.x = 0;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8025e91c;
  return;
}


/* @description Update object instance */

void dll_158_update(ObjInstance *this) { //8025E8A4
  return;
}


/* @description Override hit detection */

void dll_158_hitDetect(ObjInstance *this) { //8025E8A8
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void dll_158_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //8025E8AC
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

void dll_158_free(ObjInstance *this,int param2) { //8025E908
  return;
}


undefined4 dll_158_func08(ObjInstance *this) { //8025E90C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int dll_158_getExtraSize(void) { //8025E914
  return 0;
}


undefined4
dll_158_setScale(undefined param_1,undefined param_2,undefined param_3,undefined param_4,
                undefined param_5,undefined param_6,undefined param_7,undefined param_8,
                undefined param_9,undefined param_10,undefined4 param_11,undefined4 param_12) { //8025F138
  undefined4 uVar1;
  N64Button32 NVar2;
  bool bVar3;
  int unaff_r27;
  int *piVar4;
  int unaff_r29;
  int unaff_r30;
  int unaff_r31;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  if (unaff_r30 + 1 < (int)(uint)*(byte *)(unaff_r27 + 0x84)) {
    uVar1 = dll_158_setScale(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9
                             ,param_10,in_stack_00000018,in_stack_0000001c);
    return uVar1;
  }
  if (*(char *)(unaff_r31 + 0x75) == '\0') {
    *(undefined4 *)(unaff_r29 + 0xf4) = 7;
  }
  else {
    *(undefined4 *)(unaff_r29 + 0xf4) = 8;
  }
  if (*(int *)(unaff_r29 + 0xf4) == 8) {
                    /* {@symbol 800d99a4} */
    (**(code **)(*(int *)pDll_expgfx + 0x28))(0xc039000000000000,0);
                    /* {@symbol 800d999c} */
    (**(code **)(*(int *)pDll_expgfx + 0x20))(0);
  }
  NVar2 = n64GetEnabledButtonsPressed(0);
  if ((NVar2 & N64_BUTTON_DOWN) == 0) {
    *(undefined2 *)(unaff_r27 + 0x66) = 0xffff;
    *(undefined *)(unaff_r27 + 0x4e) = 0;
    *(ushort *)(unaff_r31 + 0x7a) = *(short *)(unaff_r31 + 0x7a) - (ushort)framesThisStep;
    if ((*(short *)(unaff_r31 + 0x7a) < 1) && (*(int *)(unaff_r31 + 0x50) != 0)) {
      *(undefined2 *)(unaff_r31 + 0x7a) = 0x32;
      if (*(int *)(unaff_r31 + 0x4c) != 0) {
        piVar4 = *(int **)(unaff_r31 + 0x50);
        bVar3 = checkSomeDebugFlags_8017c4f8();
        if (!bVar3) {
          (**(code **)(*piVar4 + 4))
                    (*(undefined4 *)(unaff_r31 + 0x4c),0,0,&DAT_00010002,0xffffffff,0);
        }
      }
    }
    uVar1 = 0;
  }
  else {
    mainSetBits(0x75,1);
    uVar1 = 2;
  }
  return uVar1;
}

