
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMboss_initialise(undefined4 param) { //8022EB78
  FUN_80232328();
  return;
}


/* @description Called when DLL is unloaded */

void DIMboss_release(void) { //8022EB98
  return;
}


/* Library Function - Single Match
    dll_220_func03
   
   Library: KioskDefault 0 0 */

void DIMboss_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //8022EB9C
  uint uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  float *pfVar4;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined2 local_20;
  
  puVar3 = this->state;
  local_2c = &DAT_000a0019;
  local_28 = &DAT_0019000a;
  local_24 = &DAT_00140014;
  local_20 = 0x14;
  this->field64_0xe4 = 2;
  mainSetBits(0x1dd,1);
  mainSetBits(0x969,1);
  mainSetBits(0x96a,1);
  mainSetBits(0x96b,1);
  mainSetBits(0x348,1);
  mainSetBits(0x969,1);
  mainSetBits(0x95e,1);
  mainSetBits(0x960,1);
  mainSetBits(0x961,1);
  mainSetBits(0x962,1);
  mainSetBits(0x963,1);
  mainSetBits(0x964,1);
  mainSetBits(0x965,1);
  mainSetBits(0x966,1);
  mainSetBits(0x967,1);
  mainSetBits(0x968,1);
  mainSetBits(0x25,0);
  mainSetBits(0x3f8,0);
  mainSetBits(0xdd,0);
  mainSetBits(0x245,0);
  mainSetBits(0x40,0);
  mainSetBits(0x777,0);
  mainSetBits(0x2c,0);
  mainSetBits(0x1d7,0);
  mainSetBits(0x107,0);
  mainSetBits(0x341,0);
  mainSetBits(0x5bd,0);
  mainSetBits(0x5ce,0);
  mainSetBits(0x5fc,0);
  mainSetBits(0x957,0);
  mainSetBits(0x958,0);
  uVar2 = 6;
  if (obj2 != (ObjInstance *)0x0) {
    uVar2 = 7;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))
            (0x4044000000000000,this,objDef,puVar3,0xc,6,0x102,uVar2);
  this->fptr_0xbc = bossFn_8022f47c;
  *(undefined2 *)(puVar3 + 0x3b2) = 0;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar3,0);
  *(undefined2 *)(puVar3 + 0x268) = 0;
  puVar3[0x348] = 3;
  *(undefined2 *)(puVar3 + 0x3b2) = 0;
  this->flags_0xaf = this->flags_0xaf | 0x88;
  uVar1 = mainGetBit(0x210);
  if (uVar1 != 0) {
    *(undefined2 *)(puVar3 + 0x3b2) = 4;
    this->field76_0xf4 = 1;
  }
  uVar1 = mainGetBit(0x20e);
  if (uVar1 != 0) {
    *(undefined2 *)(puVar3 + 0x3b2) = 3;
  }
  pfVar4 = *(float **)(puVar3 + 0x3f0);
  pfVar4[1] = 0.0;
  *pfVar4 = 0.0;
  *(undefined2 *)(pfVar4 + 2) = 0xc0c6;
  *(undefined2 *)((int)pfVar4 + 10) = 0;
  this->animVal_a2 = -1;
  pfVar4[4] = 0.0;
  DAT_80399e94 = 0;
  DAT_80399e90 = 0;
  mainSetBits(0x4e4,1);
  loadEnvfxAction(this,this,0xdb,0);
  DLL_createTempDll(0x33);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (this,&DAT_80395dd0,0xffffd8e4,&DAT_00001c71,6);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x1c))
            (&DAT_80395dd0,&local_2c,&local_2c,6);
  DAT_80396279 = DAT_80396279 & 0xfe | 8;
  *(undefined *)(pfVar4 + 0x2c) = 1;
  DAT_80399e98 = runlinkDownloadCode(0x1002,1);
  uVar1 = mainGetBit(0x1df);
  if (uVar1 == 0) {
    *(undefined *)((int)pfVar4 + 0xb1) = 2;
  }
  pfVar4[0x2d] = 0.0;
  return;
}


/* Library Function - Single Match
    dll_220_func04
   
   Library: KioskDefault 0 0 */

void DIMboss_update(ObjInstance *this) { //8022EF9C
  ObjInstance *pOVar1;
  uint uVar2;
  ObjDef *pOVar3;
  undefined *param10;
  
  param10 = this->state;
  pOVar3 = this->def;
  pOVar1 = Object_objGetMain();
  if (this->field76_0xf4 == 0) {
    FUN_8008b5f8((undefined *)this);
    if (this->flags_0xf8 == 0) {
      (this->pos).pos.x = (pOVar3->pos).x;
      (this->pos).pos.y = (pOVar3->pos).y;
      (this->pos).pos.z = (pOVar3->pos).z;
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))
                ((int)*(char *)((int)&pOVar3[1].id + 2),this,0xffffffff);
      this->flags_0xf8 = 1;
    }
    else {
      if ((*(ushort *)(param10 + 0x3ae) & 2) != 0) {
                    /* {@symbol 80162f2c} */
        (**(code **)(*(int *)pDll_partfx1F + 0x28))
                  (this,param10,param10 + 0x34c,(int)*(short *)(param10 + 0x39e),param10 + 0x3b0,0,0
                   ,0,1);
        *(ushort *)(param10 + 0x3ae) = *(ushort *)(param10 + 0x3ae) & 0xfffd;
        this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
        FUN_801a8378((int)pOVar1,1);
                    /* {@symbol 80154550} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x44))(1);
        this->flags_0xaf = this->flags_0xaf | 0x80;
        uVar2 = mainGetBit(0x20c);
        if (uVar2 < 3) {
          *(undefined2 *)(param10 + 0x3b2) = 1;
          param10[0x348] = 2;
          this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
          **(float **)(param10 + 0x3f0) = 1.0;
          mainSetBits(0x9e,1);
        }
        else {
          *(undefined2 *)(param10 + 0x3b2) = 2;
          param10[0x348] = 3;
          this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
          mainSetBits(0x9e,0);
        }
      }
      if ((*(short *)(param10 + 0x3b2) != 0) && (*(short *)(param10 + 0x3b2) != 3)) {
        if ((*(ushort *)(param10 + 0x3ae) & 4) == 0) {
          pOVar1 = Object_objGetMain();
          *(ObjInstance **)(param10 + 0x2c8) = pOVar1;
        }
        else {
          pOVar1 = Object_getSidekicksLoaded();
          *(ObjInstance **)(param10 + 0x2c8) = pOVar1;
        }
        FUN_8022f918((int)this);
        FUN_8022f934((vec3f *)this,0,(int)param10,(int)param10);
        (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 8))
                  (&DAT_80395dd0,*(undefined4 *)(param10 + 0x2c8));
        (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 4))
                  (this,&DAT_80395dd0);
        DIMboss_loadLevel((int *)this,(int)param10);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_220_func05
   
   Library: KioskDefault 0 0 */

void DIMboss_hitDetect(ObjInstance *this) { //8022F1FC
                    /* {@symbol 8011c220} */
  (**(code **)(*(int *)pDll11 + 0xc))(this,this->state,dimBossFuncPtrs);
  return;
}


/* Library Function - Single Match
    dll_220_func06
   
   Library: KioskDefault 0 0 */

void DIMboss_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //8022F248
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  
  puVar3 = this->state;
  if (((shouldRender) && (this->field76_0xf4 == 0)) && (*(short *)(puVar3 + 0x3b2) != 3)) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar3 + 0x3de)) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xc0,0xc0,0x20);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_80230a98(this,(int)puVar3);
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))
              (this,&DAT_80395dd0,0);
  }
  return;
}


/* Library Function - Single Match
    dll_220_func07
   
   Library: KioskDefault 0 0 */

void DIMboss_free(ObjInstance *this,int param2) { //8022F36C
  ObjInstance *pOVar1;
  undefined *puVar2;
  
  pOVar1 = Object_objGetMain();
  puVar2 = this->state;
  if (pOVar1 != (ObjInstance *)0x0) {
    FUN_801a8378((int)pOVar1,0);
                    /* {@symbol 80154550} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x44))(0);
  }
  this->flags_0xaf = this->flags_0xaf & 0x7f;
  FUN_80069038();
  Object_removePlayerObj(this,4);
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objFreeObject(this->child[0]);
    this->child[0] = (ObjInstance *)0x0;
  }
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar2,0x20);
  DLL_removeTempDll(0x33);
  if (DAT_80399e98 != (LoadedDll *)0x0) {
    DLL_free(DAT_80399e98);
  }
  DAT_80399e98 = (LoadedDll *)0x0;
  return;
}


undefined4 DIMboss_func08(ObjInstance *this) { //8022F448
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int DIMboss_getExtraSize(void) { //8022F450
  return 0x4b8;
}


void DIMboss_setScale(ObjInstance *this,float scale) { //8022F458
  return;
}


void DIMboss_func0B(void) { //8022F478
  return;
}

