
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRearthwalk_initialise(undefined4 param) { //802725A8
  FUN_80274e44();
  return;
}


/* @description Called when DLL is unloaded */

void DRearthwalk_release(void) { //802725C8
  return;
}


/* Library Function - Single Match
    dll_2A0_func03
   
   Library: KioskDefault 0 0 */

void DRearthwalk_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802725CC
  undefined *puVar1;
  undefined *puVar2;
  undefined *local_34;
  undefined4 local_30;
  undefined2 local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined *local_1c;
  
  local_1c = &DAT_01010101;
  local_28 = &DAT_000a000a;
  local_24 = 0;
  local_20 = 0;
  local_34 = &DAT_00140014;
  local_30 = 0;
  local_2c = 0;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80273d54;
  Object_objAddObjectType(this,0xb);
  puVar2 = this->state;
  puVar2[0xa5c] = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined2 *)(puVar2 + 0xa52) = 5;
  puVar2[0xa62] = 0xff;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa10;
  }
                    /* {@symbol 8011bd28} */
  (**(code **)(*(int *)pDll11 + 4))(this,puVar2,8,1);
  *(float *)(puVar2 + 0x29c) = 0.17;
  puVar1 = puVar2 + 4;
  puVar2[0x25b] = 0;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar1,0x6000004,0,0);
                    /* {@symbol 8012ab74} */
  (**(code **)(*(int *)pDll1A + 8))(puVar1,2,&DAT_8031cb28,&DAT_80397f80,8);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar1,4,&DAT_8031cae8,&DAT_8031cb18,&local_1c);
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(this,puVar1);
  FUN_80088d3c((int)this);
  DLL_createTempDll(0x33);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (this,puVar2 + 0x3b8,0xffffee39,&DAT_00001555,2);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x18))
            (puVar2 + 0x3b8,300,0x78);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x1c))
            (puVar2 + 0x3b8,&local_34,&local_28,2);
  if (*(char *)((int)&objDef[1].objType + 1) == '\x01') {
    *(undefined2 *)(puVar2 + 0xa56) = 1;
    *(ushort *)(puVar2 + 0xa58) = *(ushort *)(puVar2 + 0xa58) | 0x100;
    puVar2[0xa60] = puVar2[0xa60] & 0xbf | 0x40;
  }
  else {
    *(undefined2 *)(puVar2 + 0xa56) = 5;
    puVar2[0xa60] = puVar2[0xa60] & 0xf7 | 8;
  }
  puVar2[0xa61] = 0x1e;
  return;
}


/* Library Function - Single Match
    dll_2A0_func04
   
   Library: KioskDefault 0 0 */

void DRearthwalk_update(ObjInstance *this) { //80272864
  char cVar1;
  ObjInstance *pOVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  short sVar6;
  undefined *puVar7;
  int local_2c;
  undefined4 local_28 [3];
  
  puVar7 = this->state;
  puVar5 = this->state;
  local_28[0] = 1;
  pOVar2 = Object_objGetMain();
  *(undefined2 *)(puVar7 + 0xa52) = 5;
  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  if (puVar7[0xa5a] == '\x02') {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    puVar5[0x25b] = 1;
    this->hitstate->field21_0x5b = 0xf4;
    this->hitstate->sizeX1 = 0xf4;
    for (iVar4 = 0; iVar4 < (int)(uint)framesThisStep; iVar4 = iVar4 + 1) {
      FUN_80272de8((int *)this,1,iVar4);
    }
  }
  else {
    if (((*(ushort *)(puVar7 + 0xa58) & 0x20) == 0) && (uVar3 = mainGetBit(0x628), uVar3 == 0)) {
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      Object_playerGetObject(4,&local_2c);
      diPrintf(" num %i ",local_2c);
      if ((local_2c == 0) && (uVar3 = mainGetBit(0x789), uVar3 == 3)) {
        mainSetBits(0x628,1);
        puVar7[0xa62] = 9;
      }
    }
    puVar5[0x25b] = 1;
                    /* {@symbol 8012b80c} */
    (**(code **)(*(int *)pDll1A + 0x20))(this,puVar5 + 4);
    this->hitstate->field21_0x5b = 0;
    this->hitstate->sizeX1 = 0;
    FUN_80272de8((int *)this,(uint)framesThisStep,-1);
  }
  FUN_8008b5f8((undefined *)this);
  FUN_800928ac((int)this,(int)(puVar7 + 0x370));
  if ((((*(ushort *)(puVar7 + 0xa58) & 0x20) == 0) && (uVar3 = mainGetBit(0x5fe), uVar3 != 0)) &&
     (0 < *(short *)(puVar7 + 0xa56))) {
    mainSetBits(0x654,1);
    puVar7[0xa62] = 2;
    puVar7[0xa60] = puVar7[0xa60] & 0xbf;
  }
  if (((*(ushort *)(puVar7 + 0xa58) & 0x20) == 0) && (uVar3 = mainGetBit(0x655), uVar3 != 0)) {
    *(ushort *)(puVar7 + 0xa58) = *(ushort *)(puVar7 + 0xa58) | 0x40;
    puVar7[0xa62] = 2;
    *(ushort *)(puVar7 + 0xa58) = *(ushort *)(puVar7 + 0xa58) | 0x20;
    puVar7[0x861] = puVar7[0x861] | 2;
                    /* {@symbol 80128bb8} */
    (**(code **)(*(int *)pDll_RomCurve + 0x8c))
              (0x408f400000000000,puVar7 + 0x870,this,local_28,0xffffffff);
  }
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 4))(this,puVar7 + 0x3b8);
  puVar7[0xa60] = puVar7[0xa60] & 0xef;
  if ((this->flags_0xaf & CanPressAToTalk) != 0) {
    puVar7[0xa60] = puVar7[0xa60] & 0xef | 0x10;
    if ((((byte)puVar7[0xa60] >> 4 & 1) != 0) && (((byte)puVar7[0xa60] >> 3 & 1) != 0)) {
      disableButtons(0,PAD_BUTTON_A);
      sVar6 = (this->pos).rotation.x - (pOVar2->pos).rotation.x;
      if (0x8000 < sVar6) {
        sVar6 = sVar6 + 1;
      }
      if (sVar6 < -0x8000) {
        sVar6 = sVar6 + -1;
      }
      if (sVar6 < 1) {
        puVar7[0xa5f] = 1;
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(6,this,0xffffffff);
      }
      else {
        puVar7[0xa5f] = 0;
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(5,this,0xffffffff);
      }
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0xf9,"DRearthwalk.c",0x1e5,"MUSIC_ONDINO");
      *(ushort *)(puVar7 + 0xa58) = *(ushort *)(puVar7 + 0xa58) | 4;
      puVar7[0x861] = puVar7[0x861] | 1;
    }
                    /* {@symbol 8016db80} */
    iVar4 = (**(code **)(*pdll_camcontrol + 0x20))(0xc1);
    if (iVar4 == 0) {
                    /* {@symbol 8016db64} */
      if ((puVar7[0xa62] != -1) && (iVar4 = (**(code **)(*pdll_camcontrol + 0x1c))(), iVar4 == 0)) {
        if (((byte)puVar7[0xa60] >> 3 & 1) == 0) {
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)(char)puVar7[0xa62],this,0xffffffff);
          disableButtons(0,PAD_BUTTON_A);
        }
        else {
          puVar7[0xa60] = puVar7[0xa60] & 0xef | 0x10;
        }
      }
    }
    else {
      if (*(short *)(puVar5 + 0x26c) == 2) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
        disableButtons(0,PAD_BUTTON_A);
      }
      else {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
        disableButtons(0,PAD_BUTTON_A);
      }
      *(short *)(puVar7 + 0xa56) = *(short *)(puVar7 + 0xa56) + 0xc;
      uVar3 = mainGetBit(0xc1);
      mainSetBits(0xc1,uVar3 - 1);
    }
  }
  if ((puVar7[0xa61] == '\0') && (uVar3 = mainGetBit(0x7b6), uVar3 == 0)) {
    FUN_80272d80(this);
  }
  if ((puVar7[0xa61] != '\0') &&
     (cVar1 = puVar7[0xa61] - framesThisStep, puVar7[0xa61] = cVar1, cVar1 < '\0')) {
    puVar7[0xa61] = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_2A0_func05
   
   Library: KioskDefault 0 0 */

void DRearthwalk_hitDetect(ObjInstance *this) { //8027325C
  int iVar1;
  ObjInstance *pOVar2;
  undefined *puVar3;
  short sVar4;
  undefined *puVar5;
  ObjInstance *local_1c;
  
  puVar3 = this->state;
  puVar5 = this->state;
  if ((this->flags_0xb0 & SeqActive) == 0) {
    if ((*(short *)(puVar5 + 0x26c) != 6) &&
       (iVar1 = FUN_800883e4((int)this,&local_1c,(int *)0x0,(uint *)0x0), iVar1 != 0)) {
      if (iVar1 == 0x1a) {
        return;
      }
      pOVar2 = Object_objGetMain();
      if (local_1c == pOVar2) {
        return;
      }
      if (local_1c->romdefno == sword) {
        return;
      }
      sVar4 = (this->pos).rotation.x - (local_1c->pos).rotation.x;
      if (0x8000 < sVar4) {
        sVar4 = sVar4 + 1;
      }
      if (sVar4 < -0x8000) {
        sVar4 = sVar4 + -1;
      }
      if ((sVar4 < 0x4001) && (-0x4001 < sVar4)) {
        puVar3[0xa60] = puVar3[0xa60] & 0x7f | 0x80;
      }
      else {
        puVar3[0xa60] = puVar3[0xa60] & 0x7f;
      }
                    /* {@symbol 8011c3c0} */
      (**(code **)(*(int *)pDll11 + 0x14))(this,puVar5,6);
    }
    if (puVar5[0x25b] != '\0') {
      if (puVar5[0x25e] == '\0') {
        if ((*(float *)(puVar5 + 0x2b0) != 18.0) &&
           (*(float *)(puVar5 + 0x2b0) = *(float *)(puVar5 + 0x2b0) * 0.8,
           *(float *)(puVar5 + 0x2b0) <= 18.0)) {
          *(float *)(puVar5 + 0x2b0) = 18.0;
        }
      }
      else {
        *(float *)(puVar5 + 0x28c) = *(float *)(puVar5 + 0x28c) * DAT_803a2498;
        *(float *)(puVar5 + 0x2b0) = *(float *)(puVar5 + 0x2b0) * FLOAT_803a249c;
      }
      if (*(int *)(puVar5 + 0x144) != 0) {
        local_1c = *(ObjInstance **)(puVar5 + 0x144);
        if (((local_1c->romdefno == DR_PushCart) && (((byte)puVar3[0xa60] >> 2 & 1) != 0)) &&
           (this->animId == 0x14)) {
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x203,0x7f,"DRearthwalk.c",
                              (int *)0x2df);
          (*(code *)local_1c->dll->ptrs2->setScale)(0x4067c00000000000,local_1c,this);
          puVar3[0xa60] = puVar3[0xa60] & 0xfb;
        }
        *(undefined4 *)(puVar5 + 0x144) = 0;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2A0_func06
   
   Library: KioskDefault 0 0 */

void DRearthwalk_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802734A8
  ObjInstance **ppOVar1;
  int iVar2;
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  int iVar3;
  undefined *puVar4;
  int local_30 [2];
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  puVar4 = this->state;
  if (shouldRender == true) {
    objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
    objGetAttachPointWorldPos
              (this,2,(float *)(puVar4 + 0x9b4),(float *)(puVar4 + 0x9b8),(float *)(puVar4 + 0x9bc),
               FALSE);
    objFootFn_80091ec4((int)this,3,4,(int)(puVar4 + 0x978));
  }
  if ((puVar4[0xa5a] != '\x02') && (shouldRender)) {
    objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
    objGetAttachPointWorldPos
              (this,2,(float *)(puVar4 + 0x9b4),(float *)(puVar4 + 0x9b8),(float *)(puVar4 + 0x9bc),
               FALSE);
    objFootFn_80091ec4((int)this,3,4,(int)(puVar4 + 0x978));
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))
              (this,puVar4 + 0x3b8,0);
    if (((byte)puVar4[0xa60] >> 6 & 1) != 0) {
      ppOVar1 = Object_playerGetObject(0x39,local_30);
      for (iVar3 = 0; iVar3 < local_30[0]; iVar3 = iVar3 + 1) {
        iVar2 = (*(code *)ppOVar1[iVar3]->dll->ptrs2->field9_0x24)(ppOVar1[iVar3]);
        (*(code *)ppOVar1[iVar3]->dll->ptrs2->setScale)
                  (ppOVar1[iVar3],this,*(undefined4 *)(&DAT_8031cb40 + iVar2 * 4),param2_00,
                   param3_00,param4_00,param5_00);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2A0_func07
   
   Library: KioskDefault 0 0 */

void DRearthwalk_free(ObjInstance *this,int param2) { //80273670
  Object_removePlayerObj(this,0xb);
  DLL_removeTempDll(0x33);
  return;
}


undefined4 DRearthwalk_func08(ObjInstance *this) { //802736A4
  return 0x43;
}


/* @description Get extra size for object (size of State struct) */

int DRearthwalk_getExtraSize(void) { //802736AC
  return 0xa64;
}


void DRearthwalk_setScale(ObjInstance *this,float scale) { //802738D8
  return;
}


undefined4 DRearthwalk_func0B(int param1) { //802738E0
  undefined4 uVar1;
  
  if (*(char *)(*(int *)(param1 + 0xb8) + 0xa5f) == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


void DRearthwalk_modelMtxFn(ObjInstance *this,undefined4 *param2,vec3f *param3) { //80273910
  undefined4 *in_r6;
  undefined *puVar1;
  
  puVar1 = this->state;
  *param2 = *(undefined4 *)(puVar1 + 0x9b4);
  param3->x = *(float *)(puVar1 + 0x9b8);
  *in_r6 = *(undefined4 *)(puVar1 + 0x9bc);
  return;
}


/* Library Function - Single Match
    dll_2A0_func0D
   
   Library: KioskDefault 0 0 */

uint DRearthwalk_render2(ObjInstance *this) { //80273940
  uint uVar1;
  N64Button32 NVar2;
  int iVar3;
  undefined *puVar4;
  double dVar5;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  puVar4 = this->state;
  if ((*(short *)(puVar4 + 0xa56) != 0) &&
     (NVar2 = n64GetEnabledButtonsPressed(0), (NVar2 & N64_BUTTON_B) != 0)) {
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0xf6,"DRearthwalk.c",0x396,"MUSIC_ALIENWORLD");
    local_30 = (this->pos).pos.x;
    local_2c = (this->pos).pos.y;
    local_28 = (this->pos).pos.z;
    uStack_14 = (int)(this->pos).rotation.x - 0x4000U ^ 0x80000000;
    local_18 = 0x43300000;
    dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_14) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    local_30 = (float)(dVar5 * 100.0 + (double)local_30);
    uStack_1c = (int)(this->pos).rotation.x - 0x4000U ^ 0x80000000;
    local_20 = 0x43300000;
    dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_1c) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    local_28 = (float)(dVar5 * 100.0 + (double)local_28);
    iVar3 = FUN_800bb7e0(10.0,&(this->pos).pos.x,&local_30,1,(ObjInstance **)0x0,this,8,-1,0xff,'\0'
                        );
    if (iVar3 == 0) {
      puVar4[0xa5e] = 0;
    }
    else {
      puVar4[0xa5e] = 1;
    }
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))((byte)puVar4[0xa5e] + 7,this,0xffffffff);
  }
  if (*(short *)(puVar4 + 0xa56) == 0) {
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0xf6,"DRearthwalk.c",0x3a6,"MUSIC_ALIENWORLD");
  }
  uVar1 = countLeadingZeros((int)*(short *)(puVar4 + 0xa56));
  return uVar1 >> 5;
}


undefined4 DRearthwalk_func0E(int param1) { //80273B10
  undefined4 uVar1;
  
  if (*(char *)(*(int *)(param1 + 0xb8) + 0xa5e) == '\0') {
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

void DRearthwalk_func0F(short *param1,float *param2,float *param3,float *param4) { //80273B40
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
  multVectorByMatrix(0.0,50.0,-35.0,&MStack_48,param2,param3,param4);
  return;
}


undefined4 DRearthwalk_func10(void) { //80273BD8
  return 0;
}


/* Library Function - Single Match
    dll_2A0_func11
   
   Library: KioskDefault 0 0 */

void DRearthwalk_func11(int param1,int param2) { //80273BE0
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(char *)(iVar1 + 0xa5a) = (char)param2;
  if (param2 == 0) {
    mainSetBits(0x7bc,0);
    mainSetBits(0x7d4,1);
    *(byte *)(iVar1 + 0x861) = *(byte *)(iVar1 + 0x861) & 0xfe;
  }
  else {
    mainSetBits(0x7bc,1);
    mainSetBits(0x7d4,0);
  }
  return;
}


void DRearthwalk_func12(undefined4 param_1,float *param2,undefined4 *param3) { //80273C60
  *param2 = 0.0;
  *param3 = 0;
  return;
}


double DRearthwalk_func13(undefined4 param_1,float *param2) { //80273C74
  *param2 = 5.0;
  return 0.0;
}


undefined4 DRearthwalk_func14(void) { //80273C84
  return 0;
}


void DRearthwalk_func15(void) { //80273C8C
  return;
}


/* Library Function - Single Match
    dll_2A0_func16
   
   Library: KioskDefault 0 0 */

void DRearthwalk_func16(double param1,ObjInstance *param2) { //80273C90
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
  mtxSetFromObjPos(&Mtx44_80396470,&local_38);
  Mtx44VecMult(&Mtx44_80396470.m11,pfVar1,&Mtx44_80396470.m11);
  FUN_80094b08(&Mtx44_80396470);
  return;
}


/* Library Function - Single Match
    dll_2A0_func17
   
   Library: KioskDefault 0 0 */

void DRearthwalk_func17(int param1,int param2) { //80274E14
  if (param2 == 1) {
    *(short *)(*(int *)(param1 + 0xb8) + 0xa56) = *(short *)(*(int *)(param1 + 0xb8) + 0xa56) + 0xc;
  }
  return;
}

