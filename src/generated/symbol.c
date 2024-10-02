
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void symbol_initialise(undefined4 param) { //802444FC
  return;
}


/* @description Called when DLL is unloaded */

void symbol_release(void) { //80244500
  return;
}


/* Library Function - Single Match
    dll_1CB_func03
   
   Library: KioskDefault 0 0 */

void symbol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //80244504
  bool bVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)this->state;
  puVar2[1] = 0.0;
  puVar2[2] = 0.0;
  puVar2[4] = 0;
  puVar2[3] = (this->pos).pos.y;
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if (!bVar1) {
    (this->pos).pos.y = (this->pos).pos.y - 50.0;
  }
  *(undefined2 *)(puVar2 + 7) = 0;
  *(undefined2 *)((int)puVar2 + 0x1a) = 0;
  *(undefined2 *)((int)puVar2 + 0x1e) = 0;
  (this->pos).scale = 1.0;
  *puVar2 = 0;
  *(undefined *)((int)puVar2 + 0x22) = 0;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80244a4c;
  return;
}


/* Library Function - Single Match
    dll_1CB_func04
   
   Library: KioskDefault 0 0 */

void dll_DBSH_Symbol_update(ObjInstance *this) { //802445A8
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)this->state;
  uVar1 = mainGetBit(0x16a);
  if (uVar1 == 0) {
    *(undefined2 *)(puVar3 + 8) = 4000;
    *(undefined2 *)(puVar3 + 7) = 0;
    *puVar3 = 0;
    mainSetBits(0x16c,0);
    DAT_80399f28 = 0;
    DAT_80399f2c = 0;
  }
  else if (*(short *)((int)puVar3 + 0x1a) == 0) {
    if (*(short *)(puVar3 + 7) == 0) {
      *(undefined2 *)((int)puVar3 + 0x1e) = 10;
      *(undefined2 *)(puVar3 + 7) = 1;
    }
    else if (*(short *)(puVar3 + 7) == 2) {
      *(undefined2 *)(puVar3 + 7) = 3;
      *(undefined2 *)((int)puVar3 + 0x1a) = 0x14;
                    /* {@symbol 800d022c} */
      uVar2 = (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      puVar3[5] = uVar2;
      FUN_80073bd8(0x1d,0x42);
      frontFn_80073c58();
    }
    else if (*(short *)(puVar3 + 7) == 1) {
      if (PTR_DAT_80397dd0._0_1_ != '\0') {
        PTR_DAT_80397dd0._0_1_ = '\0';
        audioTryStartSfx((int *)this,1,0x239,0x7f,"symbol.c",0x87);
      }
      if ((float)puVar3[3] <= (this->pos).pos.y) {
        *(undefined2 *)(puVar3 + 7) = 2;
        *(undefined2 *)((int)puVar3 + 0x1a) = 0x14;
        PTR_DAT_80397dd0._0_1_ = '\x01';
      }
      else {
        (this->pos).pos.y = timeDelta * 0.5 + (this->pos).pos.y;
      }
      *(ushort *)((int)puVar3 + 0x1e) = *(short *)((int)puVar3 + 0x1e) - (ushort)framesThisStep;
      if (*(short *)((int)puVar3 + 0x1e) < 0xb) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
      }
    }
    else if (*(short *)(puVar3 + 7) == 3) {
      if (PTR_DAT_80397dd0._0_1_ == '\0') {
        if ((float)puVar3[3] - 50.0 < (this->pos).pos.y) {
          (this->pos).pos.y = -(timeDelta * 0.5 - (this->pos).pos.y);
          if (((float)puVar3[3] - 50.0 < (this->pos).pos.y) || (0 < *(short *)(puVar3 + 8))) {
            if ((this->pos).pos.y <= (float)puVar3[3] - 50.0) {
              mainSetBits(0x16b,1);
            }
          }
          else {
            mainSetBits(0x16c,1);
          }
          *(ushort *)((int)puVar3 + 0x1e) = *(short *)((int)puVar3 + 0x1e) - (ushort)framesThisStep;
          if (*(short *)((int)puVar3 + 0x1e) < 0xb) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x279,0,0,0xffffffff,0);
          }
          FUN_80068a9c((uint)this,0x7f);
        }
      }
      else {
        PTR_DAT_80397dd0._0_1_ = '\0';
        audioTryStartSfx((int *)this,1,0x239,0x7f,"symbol.c",0xa5);
      }
    }
  }
  else {
    *(ushort *)((int)puVar3 + 0x1a) = *(short *)((int)puVar3 + 0x1a) - (ushort)framesThisStep;
    if (*(short *)((int)puVar3 + 0x1a) < 1) {
      *(undefined2 *)((int)puVar3 + 0x1a) = 0;
    }
  }
  return;
}


/* @description Override hit detection */

void symbol_hitDetect(ObjInstance *this) { //802449CC
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void symbol_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //802449D0
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void symbol_free(ObjInstance *this,int param2) { //80244A1C
  FUN_80073dcc();
  return;
}


undefined4 symbol_func08(ObjInstance *this) { //80244A3C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int symbol_getExtraSize(void) { //80244A44
  return 0x24;
}

