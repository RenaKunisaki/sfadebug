
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void campfire_initialise(undefined4 param) { //801EEB3C
  return;
}


/* @description Called when DLL is unloaded */

void campfire_release(void) { //801EEB40
  return;
}


/* Library Function - Single Match
    dll_135_func03
   
   Library: KioskDefault 0 0 */

void campfire_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801EEB44
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)this->state;
  if (objDef[1].allocatedSize != 0) {
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,(uint)objDef[1].allocatedSize) - 4503599627370496.0) *
         0.01;
  }
  this->flags_0xf8 = 0;
  iVar2 = isModelAnimDisabled();
  if (iVar2 == 0) {
    this->flags_0xf8 = 0;
  }
  uVar3 = mainGetBit(0x8c);
  if (uVar3 != 0) {
    *(byte *)((int)puVar4 + 9) = *(byte *)((int)puVar4 + 9) | 1;
  }
  *(ObjDefEnum *)(puVar4 + 1) = objDef[1].objType;
  if ((*(short *)(puVar4 + 1) != -1) &&
     (uVar3 = mainGetBit((int)*(short *)(puVar4 + 1)), uVar3 != 0)) {
    *(byte *)((int)puVar4 + 9) = *(byte *)((int)puVar4 + 9) | 4;
  }
  *(byte *)(puVar4 + 2) = objDef[1].mapStates1;
  *puVar4 = 0;
  fVar1 = (this->pos).scale / this->data->scale;
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field16_0x52 =
         (ushort)(int)((float)((double)CONCAT44(0x43300000,
                                                (int)(short)this->hitstate->field16_0x52 ^
                                                0x80000000) - 4503601774854144.0) * fVar1);
    this->hitstate->field18_0x56 =
         (short)(int)((float)((double)CONCAT44(0x43300000,
                                               (int)this->hitstate->field18_0x56 ^ 0x80000000) -
                             4503601774854144.0) * fVar1);
    this->hitstate->field17_0x54 =
         (short)(int)((float)((double)CONCAT44(0x43300000,
                                               (int)this->hitstate->field17_0x54 ^ 0x80000000) -
                             4503601774854144.0) * fVar1);
  }
  audioTryStartSfx((int *)this,1,0x6e,0x7f,"campfire.c",0x65);
  audioTryStartSfx((int *)this,2,0x7a,0x7f,"campfire.c",0x66);
  return;
}


/* Library Function - Single Match
    dll_135_func04
   
   Library: KioskDefault 0 0 */

void campfire_update(ObjInstance *this) { //801EED34
  short sVar1;
  byte bVar2;
  ObjInstance *pOVar3;
  bool bVar6;
  LoadedDll *pLVar4;
  ObjDef *def;
  uint uVar5;
  ObjDef *pOVar7;
  ObjDef *pOVar8;
  ObjInstance **ppOVar9;
  double dVar10;
  
  ppOVar9 = (ObjInstance **)this->state;
  pOVar3 = Object_objGetMain();
  pOVar8 = this->def;
  dVar10 = (double)objHitFn_80089074(this,0xb,1,0);
  if ((this->flags_0xf8 == 0) && (bVar6 = checkSomeDebugFlags_8017c4f8(), !bVar6)) {
                    /* {@symbol 800e3c34} */
    (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
    pLVar4 = (LoadedDll *)runlinkDownloadCode(0x100c,1);
    bVar6 = pOVar8[1].mapStates2 != 0;
    (**(code **)(pLVar4->id + 4))(this,bVar6,0,&DAT_00010004,0xffffffff,0);
    DLL_free(pLVar4);
    pLVar4 = (LoadedDll *)runlinkDownloadCode(0x100b,1);
    (**(code **)(pLVar4->id + 4))(this,bVar6,0,&DAT_00010004,0xffffffff,0);
    DLL_free(pLVar4);
    pLVar4 = (LoadedDll *)runlinkDownloadCode(0x100a,1);
    dVar10 = (double)(**(code **)(pLVar4->id + 4))(this,bVar6,0,&DAT_00010004,0xffffffff,0);
    DLL_free(pLVar4);
    this->flags_0xf8 = 1;
  }
  objDistObj2Obj(pOVar3,this);
  if (*ppOVar9 == (ObjInstance *)0x0) {
    bVar6 = false;
    if (pOVar8[1].loadFlags == 0) {
      if (dVar10 < 100.0) {
        bVar6 = true;
      }
    }
    else {
      bVar6 = true;
    }
    if (bVar6) {
      def = objAlloc(0x28,LFXEmitter);
      pOVar7 = this->def;
      def->loadFlags = pOVar7->loadFlags;
      def->bound = pOVar7->bound;
      (def->pos).x = (this->pos).pos.x;
      uVar5 = randInt(0,0x1e);
      (def->pos).y = (this->pos).pos.y +
                     (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - 4503601774854144.0);
      (def->pos).z = (this->pos).pos.z;
      bVar2 = pOVar8[1].cullDist;
      def[1].bound = pOVar8[1].bound;
      def[1].cullDist = bVar2;
      sVar1._0_1_ = def[1].bound;
      sVar1._1_1_ = def[1].cullDist;
      if (sVar1 == 0) {
        def[1].bound = 0;
        def[1].cullDist = 0x59;
      }
      *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
      def[1].objType = 0x960;
      def[1].allocatedSize = 9;
      def[1].mapStates1 = 0x60;
      def[1].loadFlags = 0;
      def[1].mapStates2 = 200;
      pOVar3 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
      *ppOVar9 = pOVar3;
    }
  }
  else if ((pOVar8[1].loadFlags == 0) && (110.0 < dVar10)) {
    Object_objFreeObject(*ppOVar9);
    *ppOVar9 = (ObjInstance *)0x0;
  }
  return;
}


/* @description Override hit detection */

void campfire_hitDetect(ObjInstance *this) { //801EEFE0
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_135_func06
    dll_2BB_func06
   
   Library: KioskDefault 0 0 */

void campfire_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801EEFE4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((((this->pos).flags & 0x100) != 0) && (this->def != (ObjDef *)0x0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)this->def[1].mapStates1) -
                                  4503599627370496.0),5.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0,0,0xff);
    }
  }
  return;
}


/* @description Free object instance */

void campfire_free(ObjInstance *this,int param2) { //801EF0A4
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 campfire_func08(ObjInstance *this) { //801EF0FC
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int campfire_getExtraSize(void) { //801EF104
  return 0xc;
}

