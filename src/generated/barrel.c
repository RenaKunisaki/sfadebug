
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void barrel_initialise(undefined4 param) { //801EB8FC
  return;
}


/* @description Called when DLL is unloaded */

void barrel_release(void) { //801EB900
  return;
}


/* Library Function - Single Match
    dll_113_func03
   
   Library: KioskDefault 0 0 */

void barrel_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801EB904
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
                    /* {@symbol 8012f580} */
  (**(code **)(*(int *)pDll_projLib + 4))(this,this->state,0x21);
                    /* {@symbol 8012fa64} */
  (**(code **)(*(int *)pDll_projLib + 0x2c))(this->state,1);
  return;
}


/* Library Function - Single Match
    dll_113_func04
   
   Library: KioskDefault 0 0 */

void barrel_update(ObjInstance *this) { //801EB98C
  byte bVar1;
  int iVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  uint uStack_14;
  
  puVar4 = this->state;
  pOVar3 = this->def;
  bVar1 = puVar4[10];
  if (bVar1 == 1) {
    objHitFn_80089114(this);
    FUN_80088da4((int)this);
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    puVar4[10] = 2;
    *(float *)(puVar4 + 0xc) = 0.0;
    (this->pos).pos.x = (pOVar3->pos).x;
    (this->pos).pos.y = (pOVar3->pos).y;
    (this->pos).pos.z = (pOVar3->pos).z;
  }
  else if (bVar1 == 0) {
    if (true) {
                    /* {@symbol 8012f5bc} */
      (**(code **)(*(int *)pDll_projLib + 8))(this,puVar4);
      iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,&uStack_14);
      if (iVar2 != 0) {
                    /* {@symbol 8012fa8c} */
        (**(code **)(*(int *)pDll_projLib + 0x30))(this,puVar4);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,499,0x7f,"barrel.c",(int *)0x74);
        objHitFn_80089354(this,0x28);
        objHitFn_80089074(this,5,4,0);
        pOVar3 = objAlloc(0x24,DIMExplosio);
        (pOVar3->pos).x = (this->pos).pos.x;
        (pOVar3->pos).y = (this->pos).pos.y;
        (pOVar3->pos).z = (this->pos).pos.z;
        objInstantiateCharacter(pOVar3,5,(int)(char)this->mapId,-1,this->pMatrix);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x355,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x352,0,0,0xffffffff,0);
        puVar4[10] = 1;
      }
    }
  }
  else if (((bVar1 < 3) &&
           (*(float *)(puVar4 + 0xc) = *(float *)(puVar4 + 0xc) + timeDelta,
           300.0 < *(float *)(puVar4 + 0xc))) &&
          (iVar2 = FUN_800aa0f8((double)this->cullDistance,&(this->pos).pos.x), iVar2 == 0)) {
    FUN_80088d3c((int)this);
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    puVar4[10] = 0;
  }
  return;
}


/* @description Override hit detection */

void barrel_hitDetect(ObjInstance *this) { //801EBBC0
  return;
}


/* Library Function - Single Match
    dll_113_func06
   
   Library: KioskDefault 0 0 */

void barrel_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801EBBC4
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
                    /* {@symbol 8012f938} */
  if ((this->state[10] == '\0') &&
     (iVar1 = (**(code **)(*(int *)pDll_projLib + 0xc))(this,(int)shouldRender), iVar1 != 0)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void barrel_free(ObjInstance *this,int param2) { //801EBC54
                    /* {@symbol 8012f9ac} */
  (**(code **)(*(int *)pDll_projLib + 0x10))(this);
  return;
}


undefined4 barrel_func08(ObjInstance *this) { //801EBC8C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int barrel_getExtraSize(void) { //801EBC94
  return 0x10;
}

