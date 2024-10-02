
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcloudrunner_initialise(undefined4 param) { //8027AB4C
  FUN_8027d8e0();
  return;
}


/* @description Called when DLL is unloaded */

void DRcloudrunner_release(void) { //8027AB6C
  return;
}


/* Library Function - Single Match
    dll_2A1_func03
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8027AB70
  uint uVar1;
  undefined *puVar2;
  short local_34 [6];
  float local_28;
  float local_24;
  float local_20;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8027bc30;
  Object_objAddObjectType(this,0xb);
  puVar2 = this->state;
  puVar2[0x910] = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined2 *)(puVar2 + 0x90a) = 5;
  uVar1 = mainGetBit(0x7aa);
  *(short *)(puVar2 + 0x90c) = (short)uVar1;
  puVar2[0x91f] = 0xff;
  DLL_createTempDll(0x33);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa10;
  }
  uVar1 = mainGetBit(0x7a9);
  if (uVar1 != 0) {
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x20))
              (uVar1 + 0x13,local_34);
    (this->pos).pos.x = local_28;
    (this->pos).pos.y = local_24;
    (this->pos).pos.z = local_20;
    (this->pos).rotation.x = local_34[0];
  }
                    /* {@symbol 8011bd28} */
  (**(code **)(*(int *)pDll11 + 4))(this,puVar2,8,1);
  *(float *)(puVar2 + 0x29c) = 0.17;
  FUN_8027d618(this,(int)puVar2,(byte)puVar2[0x91c] >> 5 & 1);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (this,puVar2 + 0x394,0xffffee39,&DAT_00001555,1);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x18))
            (puVar2 + 0x394,300,0x78);
  DAT_8039a02c = textureLoadAsset(0x156);
  DAT_8039a030 = textureLoadAsset(0x47);
  return;
}


/* Library Function - Single Match
    dll_2A1_func04
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_update(ObjInstance *this) { //8027AD20
  char cVar1;
  ObjInstance *param2;
  short sVar3;
  uint uVar2;
  ObjDef *pOVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  float fStack_24;
  
  param2 = Object_objGetMain();
  pOVar4 = this->def;
  puVar6 = this->state;
  puVar7 = this->state;
  *(undefined2 *)(puVar7 + 0x90a) = 5;
  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  if (puVar7[0x90e] == '\x02') {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    puVar6[0x25b] = 1;
    for (iVar5 = 0; iVar5 < (int)(uint)framesThisStep; iVar5 = iVar5 + 1) {
      FUN_8027b1f8((int *)this,1,iVar5);
    }
  }
  else {
    puVar6[0x25b] = 0;
    FUN_8027b1f8((int *)this,(uint)framesThisStep,-1);
  }
  FUN_8008b5f8((undefined *)this);
  if ((puVar7[0x91e] != '\0') &&
     (cVar1 = puVar7[0x91e] - framesThisStep, puVar7[0x91e] = cVar1, cVar1 < '\0')) {
    puVar7[0x91e] = 0;
  }
                    /* {@symbol 8012ac30} */
  (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar6 + 4);
                    /* {@symbol 8012b0e4} */
  (**(code **)(*(int *)pDll1A + 0x14))(this,puVar6 + 4);
                    /* {@symbol 8012b170} */
  (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar6 + 4);
  FUN_8027b180((int)this);
  if (puVar7[0x90e] == '\x02') {
    puVar7[0x83d] = puVar7[0x83d] | 1;
  }
  else {
    puVar7[0x83d] = puVar7[0x83d] & 0xfe;
  }
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 4))(this,puVar7 + 0x394);
  exprFn_800945c0((uint)this,puVar7 + 0x370);
  FUN_800927d4((short *)this,puVar7 + 0x34c);
  FUN_800928ac((int)this,(int)(puVar7 + 0x34c));
  if (((this->flags_0xaf & CanPressAToTalk) != 0) && (puVar7[0x90e] == '\0')) {
    if (((byte)puVar7[0x91c] >> 4 & 1) != 0) {
      disableButtons(0,PAD_BUTTON_A);
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(4,this,0xffffffff);
      *(undefined4 *)(puVar7 + 0x868) = 0;
      puVar7[0x912] = puVar7[0x912] | 4;
      puVar7[0x83d] = puVar7[0x83d] | 1;
                    /* {@symbol 8011c3c0} */
      (**(code **)(*(int *)pDll11 + 0x14))(this,puVar6,4);
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0xf9,"DRcloudrunner.c",0x195,"MUSIC_ONDINO");
      return;
    }
    disableButtons(0,PAD_BUTTON_A);
                    /* {@symbol 8016db80} */
    iVar5 = (**(code **)(*pdll_camcontrol + 0x20))(0xc1);
    if (iVar5 == 0) {
      if (puVar7[0x91f] != -1) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)(char)puVar7[0x91f],this,0xffffffff);
      }
    }
    else {
      if (*(short *)(puVar6 + 0x26c) == 3) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(5,this,0xffffffff);
      }
      else {
        sVar3 = objDistFn_80091a84((int)this,(int)param2,&fStack_24);
        (this->pos).rotation.x = (this->pos).rotation.x + sVar3;
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(6,this,0xffffffff);
      }
      puVar7[0x91c] = puVar7[0x91c] & 0xef | 0x10;
      *(short *)(puVar7 + 0x90c) = *(short *)(puVar7 + 0x90c) + 5;
    }
  }
  iVar5 = randInt(0,0x3c);
  if (iVar5 == 0) {
    iVar5 = randInt(0,2);
    FUN_8009452c((int *)this,puVar7 + 0x370,(ushort *)(&PTR_DAT_8031cee8 + iVar5),'\0');
  }
  sVar3._0_1_ = pOVar4[1].bound;
  sVar3._1_1_ = pOVar4[1].cullDist;
  uVar2 = mainGetBit((int)sVar3);
  if (uVar2 != 0) {
    FUN_8027b114(this);
  }
  return;
}


/* Library Function - Single Match
    dll_2A1_func05
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_hitDetect(ObjInstance *this) { //8027B3B4
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  short sVar4;
  short *local_14;
  
  puVar3 = this->state;
  puVar2 = this->state;
  if (((*(short *)(puVar3 + 0x90c) != 0) && (this->animId != 0xf)) &&
     (iVar1 = FUN_800883e4((int)this,&local_14,(int *)0x0,(uint *)0x0), iVar1 != 0)) {
    sVar4 = (this->pos).rotation.x - *local_14;
    if (0x8000 < sVar4) {
      sVar4 = sVar4 + 1;
    }
    if (sVar4 < -0x8000) {
      sVar4 = sVar4 + -1;
    }
    if ((sVar4 < 0x4001) && (-0x4001 < sVar4)) {
      puVar3[0x91c] = puVar3[0x91c] & 0xbf | 0x40;
    }
    else {
      puVar3[0x91c] = puVar3[0x91c] & 0xbf;
    }
                    /* {@symbol 8011c3c0} */
    (**(code **)(*(int *)pDll11 + 0x14))(this,puVar2,6);
  }
  return;
}


/* Library Function - Single Match
    dll_2A1_func06
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8027B4B8
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if (this->parent == (ObjInstance *)0x0) {
    if (shouldRender == true) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
      objGetAttachPointWorldPos
                (this,2,(float *)(puVar1 + 0x86c),(float *)(puVar1 + 0x870),
                 (float *)(puVar1 + 0x874),FALSE);
      objGetAttachPointWorldPos
                (this,3,(float *)(puVar1 + 0x84c),(float *)(puVar1 + 0x850),
                 (float *)(puVar1 + 0x854),FALSE);
    }
    if ((puVar1[0x90e] != '\x02') && (shouldRender)) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
      objGetAttachPointWorldPos
                (this,2,(float *)(puVar1 + 0x86c),(float *)(puVar1 + 0x870),
                 (float *)(puVar1 + 0x874),FALSE);
      (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))
                (this,puVar1 + 0x394,0);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2A1_func07
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_free(ObjInstance *this,int param2) { //8027B650
  mainSetBits(0x7aa,(int)*(short *)(this->state + 0x90c));
  Object_removePlayerObj(this,0xb);
  if (DAT_8039a02c != (Texture *)0x0) {
    texFreeTexture(DAT_8039a02c);
  }
  if (DAT_8039a030 != (Texture *)0x0) {
    texFreeTexture(DAT_8039a030);
  }
  DAT_8039a02c = (Texture *)0x0;
  DAT_8039a030 = (Texture *)0x0;
  DLL_removeTempDll(0x33);
  return;
}


undefined4 DRcloudrunner_func08(ObjInstance *this) { //8027B6D4
  return 0x43;
}


/* @description Get extra size for object (size of State struct) */

int DRcloudrunner_getExtraSize(void) { //8027B6DC
  return 0x920;
}


/* Library Function - Single Match
    dll_2A1_func0A
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_setScale(ObjInstance *this,float scale) { //8027B6E4
  ObjInstance *in_r4;
  undefined *puVar1;
  int iVar2;
  undefined4 in_register_00004008;
  
  puVar1 = this->state;
  if (((*(short *)(this->state + 0x26c) == 2) && (this->pObj_0xc0 == (ObjInstance *)0x0)) &&
     (objDistObj2Obj(in_r4,this), (double)CONCAT44(in_register_00004008,scale) < 80.0)) {
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0xf9,"DRcloudrunner.c",0x27c,"MUSIC_ONDINO");
    iVar2 = (int)(this->pos).rotation.x - (uint)(ushort)(in_r4->pos).rotation.x;
    if (0x8000 < iVar2) {
      iVar2 = iVar2 + -0xffff;
    }
    if (iVar2 < -0x8000) {
      iVar2 = iVar2 + 0xffff;
    }
    if ((iVar2 < 0x4001) && (-0x4001 < iVar2)) {
      puVar1[0x914] = 1;
    }
    else {
      puVar1[0x914] = 0;
    }
    puVar1[0x912] = puVar1[0x912] | 4;
  }
  return;
}


undefined4 DRcloudrunner_func0B(int param1) { //8027B7FC
  undefined4 uVar1;
  
  if (*(char *)(*(int *)(param1 + 0xb8) + 0x914) == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


void DRcloudrunner_modelMtxFn(ObjInstance *this,undefined4 *param2,vec3f *param3) { //8027B82C
  undefined4 *in_r6;
  undefined *puVar1;
  
  puVar1 = this->state;
  *param2 = *(undefined4 *)(puVar1 + 0x86c);
  param3->x = *(float *)(puVar1 + 0x870);
  *in_r6 = *(undefined4 *)(puVar1 + 0x874);
  return;
}


/* Library Function - Single Match
    dll_2A1_func0D
   
   Library: KioskDefault 0 0 */

uint DRcloudrunner_render2(ObjInstance *this) { //8027B85C
  N64Button32 NVar1;
  uint uVar2;
  ObjInstance *pOVar3;
  undefined *puVar4;
  undefined *puVar5;
  float local_18 [2];
  
  puVar4 = this->state;
  puVar5 = this->state;
  NVar1 = n64GetEnabledButtonsPressed(0);
  if (((NVar1 & N64_BUTTON_B) == 0) || (*(short *)(puVar4 + 0x26c) != 2)) {
    if (*(short *)(puVar5 + 0x90c) == 0) {
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0xf6,"DRcloudrunner.c",0x2be,"MUSIC_ALIENWORLD");
      FUN_80068a9c((uint)this,0x40);
    }
    if ((*(int *)(puVar5 + 0x868) == 0) &&
       (NVar1 = n64GetEnabledButtonsPressed(0), (NVar1 & N64_BUTTON_B) != 0)) {
      local_18[0] = 250.0;
      pOVar3 = getSeqObj(0x15,this,local_18);
      *(ObjInstance **)(puVar5 + 0x868) = pOVar3;
      if (*(int *)(puVar5 + 0x868) != 0) {
        FUN_80068a9c((uint)this,0x40);
                    /* {@symbol 8011bc64} */
        (**(code **)(*(int *)pDll05_2 + 4))
                  (this,0xf6,"DRcloudrunner.c",0x2ca,"MUSIC_ALIENWORLD");
                    /* {@symbol 8011c3c0} */
        (**(code **)(*(int *)pDll11 + 0x14))(this,puVar4,2);
        (**(code **)(**(int **)(*(int *)(puVar5 + 0x868) + 0x68) + 0x24))
                  (*(undefined4 *)(puVar5 + 0x868));
      }
      uVar2 = 0;
    }
    else {
      uVar2 = countLeadingZeros((int)*(short *)(puVar5 + 0x90c));
      uVar2 = uVar2 >> 5;
    }
  }
  else {
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0xf6,"DRcloudrunner.c",0x2b8,"MUSIC_ALIENWORLD");
    uVar2 = 1;
  }
  return uVar2;
}


undefined4 DRcloudrunner_func0E(int param1) { //8027B9F8
  undefined4 uVar1;
  
  if (*(char *)(*(int *)(param1 + 0xb8) + 0x913) == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_29F_func0F
    dll_2A0_func0F
    dll_2A1_func0F
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_func0F(short *param1,float *param2,float *param3,float *param4) { //8027BA28
  ObjPos local_60;
  Mtx44 MStack_48;
  
  local_60.pos.x = *(float *)(param1 + 6);
  local_60.pos.y = *(float *)(param1 + 8);
  local_60.pos.z = *(float *)(param1 + 10);
  local_60.rotation.x = *param1;
  local_60.rotation.y = param1[1];
  local_60.rotation.z = param1[2];
  local_60.scale = 1.0;
  mtxSetFromObjPos(&MStack_48,&local_60);
  multVectorByMatrix(0.0,16.0,-16.0,&MStack_48,param2,param3,param4);
  return;
}


undefined4 DRcloudrunner_func10(void) { //8027BAC0
  return 0;
}


/* Library Function - Single Match
    dll_2A1_func11
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_func11(int param1,int param2) { //8027BAC8
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(char *)(iVar1 + 0x90e) = (char)param2;
  if (param2 == 1) {
    *(undefined *)(iVar1 + 0x34c) = 0;
    if (*(short *)(param1 + 0xb4) != -1) {
                    /* {@symbol 800d0958} */
      (**(code **)(*(int *)pDll_checkpoint + 0x4c))((int)*(short *)(param1 + 0xb4));
    }
  }
  else {
    *(undefined *)(iVar1 + 0x34c) = 1;
  }
  return;
}


void DRcloudrunner_func12(undefined4 param_1,float *param2,undefined4 *param3) { //8027BB3C
  *param2 = 0.0;
  *param3 = 0;
  return;
}


double DRcloudrunner_func13(undefined4 param_1,float *param2) { //8027BB50
  *param2 = 5.0;
  return 0.0;
}


undefined4 DRcloudrunner_func14(void) { //8027BB60
  return 0;
}


void DRcloudrunner_func15(void) { //8027BB68
  return;
}


/* Library Function - Single Match
    dll_2A1_func16
   
   Library: KioskDefault 0 0 */

void DRcloudrunner_func16(double param1,ObjInstance *param2) { //8027BB6C
  float *pfVar1;
  ObjPos local_38;
  float local_20;
  float local_1c;
  float local_18 [3];
  
  pfVar1 = (float *)objJointFn_80091db4(param2,2);
  FUN_80091e7c((int)param2,2,local_18,&local_1c,&local_20);
  local_38.pos.x = local_18[0];
  local_38.pos.y = local_1c;
  local_38.pos.z = local_20;
  local_38.rotation.x = 0;
  local_38.rotation.y = 0;
  local_38.rotation.z = 0;
  local_38.scale = (float)param1 / param2->data->scale;
  mtxSetFromObjPos(&Mtx44_803964e8,&local_38);
  Mtx44VecMult(&Mtx44_803964e8.m11,pfVar1,&Mtx44_803964e8.m11);
  FUN_80094b08(&Mtx44_803964e8);
  return;
}


void DRcloudrunner_func17(void) { //8027D614
  return;
}

