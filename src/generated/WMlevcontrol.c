
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WMlevcontrol_initialise(undefined4 param) { //80283F78
  return;
}


/* @description Called when DLL is unloaded */

void WMlevcontrol_release(void) { //80283F7C
  return;
}


/* @description Set up object instance
   Library Function - Single Match
    dll_24B_func03
   
   Library: KioskDefault 0 0 */

void WMlevcontrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80283F80
  undefined uVar2;
  undefined4 uVar1;
  undefined extraout_r4;
  undefined extraout_r4_00;
  undefined uVar3;
  undefined uVar5;
  int iVar4;
  undefined uVar6;
  undefined in_r7;
  undefined in_r8;
  undefined in_r9;
  undefined in_r10;
  undefined4 unaff_r30;
  undefined2 *puVar7;
  undefined4 in_LR;
  undefined in_stack_ffffffeb;
  undefined in_stack_ffffffef;
  
  uVar5 = (undefined)flags;
  uVar3 = SUB41(obj2,0);
  Object_objAddObjectType(this,10);
  puVar7 = (undefined2 *)this->state;
  *(undefined *)((int)puVar7 + 7) = 0;
  puVar7[1] = 0x1e;
                    /* {@symbol 8012dfa8} */
  uVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
                    /* {@symbol 8028410c} */
  switch(uVar2) {
  case 0:
  case 2:
  case 3:
    goto code_r0x8028410c;
  case 1:
                    /* {@symbol 8012decc} */
    (**(code **)(*(int *)pDll_SaveGame + 0x44))(0xe,1);
    uVar3 = 1;
    iVar4 = *(int *)pDll_SaveGame;
                    /* {@symbol 8012e228} */
    uVar2 = (**(code **)(iVar4 + 0x50))(0xe,0);
    dll_24A_setScale(uVar2,extraout_r4_00,uVar3,(char)iVar4,in_r7,in_r8,in_r9,in_r10,
                     in_stack_ffffffeb,in_stack_ffffffef,unaff_r30,in_LR);
    return;
  case 4:
    loadEnvfxAction(this,this,0xa5,0);
    uVar2 = 0xa6;
    uVar3 = 0;
    uVar1 = loadEnvfxAction(this,this,0xa6,0);
    *puVar7 = 0xffff;
    dll_24A_setScale((char)uVar1,(char)this,uVar2,uVar3,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffeb,
                     in_stack_ffffffef,unaff_r30,in_LR);
    return;
  case 5:
    loadEnvfxAction(this,this,0xe4,0);
    uVar2 = 0xe5;
    uVar3 = 0;
    uVar1 = loadEnvfxAction(this,this,0xe5,0);
    dll_24A_setScale((char)uVar1,(char)this,uVar2,uVar3,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffeb,
                     in_stack_ffffffef,unaff_r30,in_LR);
    return;
  case 6:
    loadEnvfxAction(this,this,0xa5,0);
    uVar5 = 0xa6;
    uVar6 = 0;
    loadEnvfxAction(this,this,0xa6,0);
    uVar2 = 100;
    uVar3 = 1;
    mainSetBits(0x164,1);
    dll_24A_setScale(uVar2,uVar3,uVar5,uVar6,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffeb,
                     in_stack_ffffffef,unaff_r30,in_LR);
    return;
  case 7:
    loadEnvfxAction(this,this,0xe4,0);
    loadEnvfxAction(this,this,0xe5,0);
    puVar7[2] = 700;
    *(undefined *)(puVar7 + 3) = 0x1e;
    puVar7[1] = (ushort)*(byte *)(puVar7 + 3);
code_r0x8028410c:
    return;
  default:
    dll_24A_setScale(uVar2,extraout_r4,uVar3,uVar5,in_r7,in_r8,in_r9,in_r10,in_stack_ffffffeb,
                     in_stack_ffffffef,unaff_r30,in_LR);
    return;
  }
}


/* Library Function - Single Match
    dll_24B_func04
   
   Library: KioskDefault 0 0 */

void WMlevcontrol_update(ObjInstance *this) { //80284120
  undefined uVar1;
  
                    /* {@symbol 8012dfa8} */
  uVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  if (true) {
                    /* {@symbol 802841c4} */
    switch(uVar1) {
    case 1:
      FUN_8028449c((int)this);
      break;
    case 2:
      FUN_802845b8(this);
      break;
    case 3:
      FUN_802847e0(this);
      break;
    case 4:
      FUN_80284924((int)this);
      break;
    case 5:
      FUN_80284ae8(this);
      break;
    case 6:
      FUN_80284d54();
      break;
    case 7:
      FUN_80284f44((int)this);
    }
  }
  return;
}


/* @description Override hit detection */

void WMlevcontrol_hitDetect(ObjInstance *this) { //802841D8
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WMlevcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802841DC
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
    dll_24B_func07
   
   Library: KioskDefault 0 0 */

void WMlevcontrol_free(ObjInstance *this,int param2) { //80284238
  Object_removePlayerObj(this,10);
  return;
}


undefined4 WMlevcontrol_func08(ObjInstance *this) { //80284278
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WMlevcontrol_getExtraSize(void) { //80284280
  return 10;
}

