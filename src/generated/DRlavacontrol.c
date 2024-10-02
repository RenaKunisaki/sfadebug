
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRlavacontrol_initialise(undefined4 param) { //802B3E04
  return;
}


/* @description Called when DLL is unloaded */

void DRlavacontrol_release(void) { //802B3E08
  return;
}


/* Library Function - Single Match
    dll_2AD_func03
   
   Library: KioskDefault 0 0 */

void DRlavacontrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802B3E0C
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  ObjInstance **ppOVar4;
  
  ppOVar4 = (ObjInstance **)this->state;
  uVar1._0_1_ = objDef[1].allocatedSize;
  uVar1._1_1_ = objDef[1].mapStates1;
  *(char *)((int)ppOVar4 + 6) = (char)uVar1;
  *(undefined *)((int)ppOVar4 + 7) = *(undefined *)((int)ppOVar4 + 6);
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  uVar3 = mainGetBit((int)sVar2);
  *(byte *)(ppOVar4 + 2) = *(byte *)(ppOVar4 + 2) | uVar3 != 0;
  *(undefined2 *)(ppOVar4 + 1) =
       *(undefined2 *)(&DAT_80398190 + *(char *)((int)&objDef[1].objType + 1) * 2);
  if ((*(byte *)(ppOVar4 + 2) & 1) == 0) {
    FUN_802b41c0(this,ppOVar4,3);
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0x102,&PTR_DAT_803238f0,0x6d,"AMBIENT_LAVAPIT");
  }
  else {
    FUN_802b41c0(this,ppOVar4,0);
  }
  return;
}


/* Library Function - Single Match
    dll_2AD_func04
   
   Library: KioskDefault 0 0 */

void DRlavacontrol_update(ObjInstance *this) { //802B3EF0
  FUN_802b4430(this,(int)(char)this->state[9]);
  return;
}


/* Library Function - Single Match
    dll_2AD_func05
   
   Library: KioskDefault 0 0 */

void DRlavacontrol_hitDetect(ObjInstance *this) { //802B3F2C
  int iVar1;
  
  iVar1 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar1 == 0x10) {
    FUN_802b4058(this);
  }
  return;
}


/* @description Override render */

void DRlavacontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802B3F78
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if ((bVar1) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_2AD_func07
   
   Library: KioskDefault 0 0 */

void DRlavacontrol_free(ObjInstance *this,int param2) { //802B3FE0
  if ((*(ObjInstance **)this->state != (ObjInstance *)0x0) && (param2 == 0)) {
    Object_objFreeObject(*(ObjInstance **)this->state);
  }
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
  return;
}


undefined4 DRlavacontrol_func08(ObjInstance *this) { //802B4048
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRlavacontrol_getExtraSize(void) { //802B4050
  return 0xc;
}

