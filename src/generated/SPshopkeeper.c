
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SPshopkeeper_initialise(undefined4 param) { //80267AD0
  FUN_802692a8();
  return;
}


/* @description Called when DLL is unloaded */

void SPshopkeeper_release(void) { //80267AF0
  return;
}


/* Library Function - Single Match
    dll_2CD_func03
   
   Library: KioskDefault 0 0 */

void SPshopkeeper_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80267AF4
  uint uVar1;
  DtypeStack *pDVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  this->fptr_0xbc = FUN_8026829c;
  this->shadow->flags = this->shadow->flags | 0x810;
  uVar1 = randInt(0xf,0x23);
  *(float *)(puVar3 + 0x830) =
       (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0) * 0.1;
  pDVar2 = stackCreate(4,4);
  *(DtypeStack **)(puVar3 + 0x828) = pDVar2;
  puVar3[0x84a] = 0xff;
  DLL_createTempDll(0x33);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (this,puVar3 + 0x34c,0xffffe38f,0x3554,2);
  puVar3[0x7f5] = puVar3[0x7f5] | 0x12;
  return;
}


/* Library Function - Single Match
    dll_2CD_func04
   
   Library: KioskDefault 0 0 */

void SPshopkeeper_update(ObjInstance *this) { //80267BE8
  ObjInstance *pOVar1;
  ObjInstance *pOVar2;
  undefined2 uVar3;
  undefined *puVar4;
  float local_14 [2];
  
  pOVar1 = Object_objGetMain();
  puVar4 = this->state;
  local_14[0] = 10000.0;
  if ((puVar4[0x848] & 4) != 0) {
    FUN_80268070((ushort *)this,(int)pOVar1,1);
  }
  (this->pos).scale = this->data->scale;
  if (*(int *)(puVar4 + 0x82c) == 0) {
    pOVar2 = getSeqObj(10,this,local_14);
    *(ObjInstance **)(puVar4 + 0x82c) = pOVar2;
  }
  uVar3 = FUN_801a7da8((int)pOVar1);
  *(undefined2 *)(puVar4 + 0x83c) = uVar3;
                    /* {@symbol 8011bdb4} */
  (**(code **)(*(int *)pDll11 + 8))
            ((double)timeDelta,(double)timeDelta,this,puVar4,&DAT_803963a0,&DAT_80399fe0);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 4))(this,puVar4 + 0x34c);
  FUN_800928ac((int)this,(int)(puVar4 + 0x804));
  return;
}


/* @description Override hit detection */

void SPshopkeeper_hitDetect(ObjInstance *this) { //80267CDC
  return;
}


/* Library Function - Single Match
    dll_2CD_func06
   
   Library: KioskDefault 0 0 */

void SPshopkeeper_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80267CE0
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  this->newOpacity = puVar1[0x84a];
  if ((*(short *)(puVar1 + 0x26c) != 7) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))
              (this,puVar1 + 0x34c,0);
  }
  return;
}


/* Library Function - Single Match
    dll_2CD_func07
   
   Library: KioskDefault 0 0 */

void SPshopkeeper_free(ObjInstance *this,int param2) { //80267D88
  FUN_80070394(*(void **)(this->state + 0x828));
  return;
}


undefined4 SPshopkeeper_func08(ObjInstance *this) { //80267DC0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SPshopkeeper_getExtraSize(void) { //80267DC8
  return 0x84c;
}

