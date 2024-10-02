
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void backpack_initialise(undefined4 param) { //801EC290
  return;
}


/* @description Called when DLL is unloaded */

void backpack_release(void) { //801EC294
  return;
}


/* Library Function - Single Match
    backpack_func03
   
   Library: KioskDefault 0 0 */

void backpack_init(ObjInstance *param1,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801EC298
  undefined4 uVar1;
  ObjInstance *param1_00;
  BOOL BVar2;
  int iVar3;
  ObjState_Backpack *back;
  undefined4 in_register_00004008;
  
  back = (ObjState_Backpack *)param1->state;
  back->type = 4;
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    if ((undefined *)(int)(short)param1->romdefno == (&PTR_80312a98)[iVar3]) {
      back->type = (byte)iVar3;
      iVar3 = 4;
    }
  }
  if (back->type == 4) {
                    
    OSPanic("backpack.c",0xac,s_Failed_assertion_back_>type____B_80312ab4,
            CONCAT44(in_register_00004008,x));
  }
  back->field39_0x30 = 1;
  back->field38_0x2c = 0.05;
  back->field41_0x35 = back->field41_0x35 & 0xbf;
  back->field41_0x35 = back->field41_0x35 & 0x7f;
  back->field44_0x38 = 0;
  back->field45_0x3c = back->field45_0x3c & 0x7f;
  back->field45_0x3c = back->field45_0x3c & 0xbf | 0x40;
  back->field37_0x28 = 0;
  Object_ObjAnimSetMove(0.0,param1,0,0);
  if (*(char *)((int)&PTR_DAT_80397c14 + (uint)back->type) == '\0') {
    back->field36_0x24 = 0;
  }
  else {
                    /* {@symbol 80153f40} */
    uVar1 = (**(code **)(*(int *)pDll_ObjSeq + 0x3c))();
    back->field36_0x24 = uVar1;
  }
  DAT_80395a50 = FUN_801ec7d8;
  DAT_80395a54 = &LAB_801ec7f4;
  DAT_80395a58 = FUN_801ec928;
  DAT_80395a5c = FUN_801ec944;
  param1_00 = Object_objGetMain();
  BVar2 = krystalIsClaw(param1_00);
  if (BVar2 != FALSE) {
                    
    OSPanic("backpack.c",0xcc,"Failed assertion !krystalIsClaw(objGetMain())");
  }
  return;
}


/* Library Function - Single Match
    backpack_func04
   
   Library: KioskDefault 0 0 */

void backpack_update(ObjInstance *this) { //801EC42C
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  iVar3 = objRunAnimation((double)*(float *)(puVar4 + 0x2c),(double)timeDelta,(int)this,(float *)0x0
                         );
  iVar1 = *(int *)(puVar4 + 0x30);
  if (iVar1 == 1) {
    iVar1 = (*(code *)(&DAT_80395a50)[(byte)puVar4[0x34]])(this,*(undefined4 *)(puVar4 + 0x24));
    if (iVar1 != 0) {
      FUN_801ec778(this);
    }
    puVar4[0x3c] = puVar4[0x3c] & 0xbf;
  }
  else if (iVar1 < 1) {
    if (-1 < iVar1) {
      if (((-1 < (char)puVar4[0x35]) && (0.7 < this->animTimer)) &&
         (*(char *)((int)&PTR_DAT_80397c14 + (uint)(byte)puVar4[0x34]) != '\0')) {
        puVar4[0x35] = puVar4[0x35] & 0x7f | 0x80;
      }
      if (iVar3 != 0) {
        *(undefined4 *)(puVar4 + 0x30) = 1;
        if (*(int *)(puVar4 + 0x38) == 0) {
          uVar2 = 1;
        }
        else {
          uVar2 = 2;
        }
        *(undefined4 *)(puVar4 + 0x30) = uVar2;
      }
    }
  }
  else if ((iVar1 < 3) && (iVar3 != 0)) {
    puVar4[0x35] = puVar4[0x35] & 0xbf | 0x40;
  }
  return;
}


/* @description Override hit detection */

void backpack_hitDetect(ObjInstance *this) { //801EC56C
  return;
}


/* Library Function - Single Match
    backpack_func06
   
   Library: KioskDefault 0 0 */

void backpack_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801EC570
  ObjInstance *obj;
  BOOL BVar1;
  ObjInstance *pOVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  obj = Object_objGetMain();
  if (shouldRender == true) {
    (this->pos).rotation.x = (obj->pos).rotation.x;
    if ((this->newOpacity != 0) && (BVar1 = krystalIsClaw(this), BVar1 == FALSE)) {
      objGetAttachPointWorldPos
                (obj,(uint)(byte)(&DAT_80397c10)[(byte)puVar4[0x34]],&(this->pos).pos.x,
                 &(this->pos).pos.y,&(this->pos).pos.z,FALSE);
    }
    BVar1 = krystalIsClaw(this);
    if (BVar1 != FALSE) {
      (this->pos).pos.x = (obj->pos).pos.x;
      (this->pos).pos.y = (obj->pos).pos.y;
      (this->pos).pos.z = (obj->pos).pos.z;
    }
    if (*(int *)(puVar4 + 0x28) != 0) {
      iVar3 = *(int *)(puVar4 + 0x28);
      *(float *)(iVar3 + 0xc) = (obj->pos).pos.x;
      *(float *)(iVar3 + 0x10) = (obj->pos).pos.y;
      *(float *)(iVar3 + 0x14) = (obj->pos).pos.z;
    }
    pOVar2 = FUN_801eca0c(this,0x62e);
    if (pOVar2 != (ObjInstance *)0x0) {
      (pOVar2->pos).pos.x = (obj->pos).pos.x;
      (pOVar2->pos).pos.y = (obj->pos).pos.y;
      (pOVar2->pos).pos.z = (obj->pos).pos.z;
    }
  }
  return;
}


/* @description Free object instance */

void backpack_free(ObjInstance *this,int param2) { //801EC680
  return;
}


undefined4 backpack_func08(ObjInstance *this) { //801EC684
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int backpack_getExtraSize(void) { //801EC68C
  return 0x40;
}


/* Library Function - Single Match
    backpackFn_801ec694
   
   Library: KioskDefault 0 0 */

undefined4 backpackFn_801ec694(int *param1) { //801EC694
  if (*param1 == 0) {
                    
    OSPanic("backpack.c",0x154,"Failed assertion *obj");
  }
  *(undefined4 *)(*(int *)(*param1 + 0xb8) + 0x38) = 1;
  return 1;
}


/* Library Function - Single Match
    backpackFn_801ec6f8
   
   Library: KioskDefault 0 0 */

bool backpackFn_801ec6f8(ObjInstance **param1) { //801EC6F8
  bool bVar1;
  
  if (*param1 != (ObjInstance *)0x0) {
    bVar1 = ((byte)(*param1)->state[0x35] >> 6 & 1) == 0;
    if (!bVar1) {
      Object_objFreeObject(*param1);
      *param1 = (ObjInstance *)0x0;
    }
    return bVar1;
  }
                    
  OSPanic("backpack.c",0x166,"Failed assertion *obj");
}

