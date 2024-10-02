
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRhightop_initialise(undefined4 param) { //802B8528
  FUN_802ba000();
  return;
}


/* @description Called when DLL is unloaded */

void DRhightop_release(void) { //802B8548
  return;
}


/* Library Function - Single Match
    dll_2BA_func03
   
   Library: KioskDefault 0 0 */

void DRhightop_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802B854C
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 auStack_4c [2];
  undefined4 local_44 [2];
  undefined2 local_3c [2];
  undefined4 auStack_38 [2];
  undefined4 local_30 [2];
  undefined2 local_28 [6];
  undefined *local_1c;
  
  puVar7 = this->state;
  local_1c = &DAT_01010101;
  iVar8 = 2;
  puVar1 = &DAT_802d0c88;
  puVar2 = auStack_38;
  do {
    puVar5 = puVar2;
    puVar4 = puVar1;
    uVar3 = puVar4[3];
    puVar5[2] = puVar4[2];
    puVar5[3] = uVar3;
    iVar8 = iVar8 + -1;
    puVar1 = puVar4 + 2;
    puVar2 = puVar5 + 2;
  } while (iVar8 != 0);
  *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(puVar4 + 4);
  iVar8 = 2;
  puVar1 = &DAT_802d0c9c;
  puVar2 = auStack_4c;
  do {
    puVar5 = puVar2;
    puVar4 = puVar1;
    uVar3 = puVar4[3];
    puVar5[2] = puVar4[2];
    puVar5[3] = uVar3;
    iVar8 = iVar8 + -1;
    puVar1 = puVar4 + 2;
    puVar2 = puVar5 + 2;
  } while (iVar8 != 0);
  *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(puVar4 + 4);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802b9080;
  puVar7[0xa70] = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined2 *)(puVar7 + 0xa5e) = 5;
  puVar7[0xa75] = 0xff;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa10;
  }
                    /* {@symbol 8011bd28} */
  (**(code **)(*(int *)pDll11 + 4))(this,puVar7,9,1);
  *(float *)(puVar7 + 0x29c) = 0.17;
  puVar6 = puVar7 + 4;
  puVar7[0x25b] = 0;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar6,0x6000004,0,0);
                    /* {@symbol 8012ab74} */
  (**(code **)(*(int *)pDll1A + 8))(puVar6,2,&DAT_80323db0,&DAT_803981cc,8);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar6,4,&DAT_80323d70,&DAT_80323da0,&local_1c);
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(this,puVar6);
  DLL_createTempDll(0x33);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (this,puVar7 + 0x3b8,0xffffee39,0x5c71,9);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x18))
            (puVar7 + 0x3b8,300,0x78);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x1c))
            (puVar7 + 0x3b8,local_44,local_30,9);
  puVar7[0x861] = puVar7[0x861] | 2;
  puVar7[0x861] = puVar7[0x861] | 8;
  *(undefined2 *)(puVar7 + 0xa60) = 5;
  puVar7[0x861] = puVar7[0x861] | 1;
  this->data->field_0x9a = 0x7f;
  return;
}


/* Library Function - Single Match
    dll_2BA_func04
   
   Library: KioskDefault 0 0 */

void DRhightop_update(ObjInstance *this) { //802B87DC
  uint uVar1;
  int iVar2;
  char cVar3;
  uint *puVar4;
  double dVar5;
  double dVar6;
  undefined4 uStack_4c;
  float local_48;
  float local_40;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  
  _savefpr_30();
  puVar4 = (uint *)this->state;
  dVar6 = 3.0;
  *(undefined2 *)((int)puVar4 + 0xa5e) = 5;
  uVar1 = countLeadingZeros(*(byte *)(puVar4 + 0x29d) >> 3 & 1);
  *(char *)((int)puVar4 + 0x25b) = (char)(uVar1 >> 5);
  *(undefined *)(puVar4 + 0xd2) = 0;
  *puVar4 = *puVar4 & 0xffff7fff;
  if ((*(ushort *)(puVar4 + 0x29b) & 0x40) == 0) {
    puVar4[0xa2] = (uint)0.0;
    puVar4[0xa1] = (uint)0.0;
    puVar4[0xc4] = 0;
    puVar4[0xc3] = 0;
    *(undefined2 *)(puVar4 + 0xc9) = 0;
    goto LAB_802b8a1c;
  }
  local_48 = (float)puVar4[0x236] - (this->pos).pos.x;
  local_40 = (float)puVar4[0x238] - (this->pos).pos.z;
  dVar5 = sqrt((double)(local_48 * local_48 + local_40 * local_40));
  if (70.0 <= dVar5) {
    if (70.0 <= dVar5) {
      dVar6 = 8.0;
    }
    else {
      dVar6 = 0.0;
    }
  }
  else {
    iVar2 = FUN_8006c2c8(1.899999976158142,(float *)(puVar4 + 0x21c));
    if (iVar2 == 0) {
      if (puVar4[0x220] == 0) goto LAB_802b8920;
    }
                    /* {@symbol 801290d4} */
    cVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x90))(puVar4 + 0x21c);
    if (cVar3 == '\0') {
      FUN_802b9848((int)this,*(undefined *)(puVar4[0x243] + 0x18));
    }
    else {
      *(ushort *)(puVar4 + 0x29b) = *(ushort *)(puVar4 + 0x29b) & 0xfebf;
      *(byte *)((int)puVar4 + 0x861) = *(byte *)((int)puVar4 + 0x861) & 0xfd;
    }
  }
LAB_802b8920:
  local_48 = (this->pos).pos.x - (float)puVar4[0x236];
  local_40 = (this->pos).pos.z - (float)puVar4[0x238];
  iVar2 = getAngle();
  uStack_2c = -(int)(short)iVar2 ^ 0x80000000;
  local_30 = 0x43300000;
  dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_2c) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  puVar4[0xa2] = (uint)(float)(dVar6 * -dVar5);
  uStack_34 = -(int)(short)iVar2 ^ 0x80000000;
  local_38 = 0x43300000;
  dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_34) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  puVar4[0xa1] = (uint)(float)(dVar6 * -dVar5);
  *(undefined2 *)(puVar4 + 0xc9) = 0;
  puVar4[0xc4] = 0;
  puVar4[0xc3] = 0;
LAB_802b8a1c:
  *puVar4 = *puVar4 & 0xffbfffff;
  uStack_34 = (uint)framesThisStep;
  local_38 = 0x43300000;
                    /* {@symbol 8011bdb4} */
  (**(code **)(*(int *)pDll11 + 8))
            ((double)(float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0),
             (double)timeDelta,this,puVar4,&DAT_80396610,&DAT_8039a160);
  FUN_802b8ebc((int *)this,(int)puVar4,(int)puVar4);
  FUN_8008b5f8((undefined *)this);
  FUN_800928ac((int)this,(int)(puVar4 + 0xdc));
  exprFn_800945c0((uint)this,(char *)(puVar4 + 0xe5));
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 4))(this,puVar4 + 0xee);
  if (((this->flags_0xaf & CanPressAToTalk) != 0) &&
     (disableButtons(0,PAD_BUTTON_A), *(char *)((int)puVar4 + 0xa75) != -1)) {
    if (*(char *)((int)puVar4 + 0xa75) < '\n') {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))
                ((int)*(char *)((int)puVar4 + 0xa75),this,0xffffffff);
    }
    else {
      mainSetBits((int)*(short *)(&DAT_803981c0 + (*(char *)((int)puVar4 + 0xa75) + -10) * 2),1);
    }
  }
  iVar2 = randInt(0,0x28);
  if (iVar2 == 0) {
    iVar2 = randInt(0,3);
    FUN_8009452c((int *)this,(undefined *)(puVar4 + 0xe5),(ushort *)(iVar2 * 4 + -0x7fcdc2b0),'\0');
  }
  iVar2 = FUN_800883e4((int)this,&uStack_4c,(int *)0x0,(uint *)0x0);
  if (iVar2 != 0) {
    if (*(short *)(puVar4 + 0x9b) != 3) {
      puVar4[0x29a] = (int)*(short *)(puVar4 + 0x9b);
    }
    iVar2 = randInt(0,0);
    FUN_8009452c((int *)this,(undefined *)(puVar4 + 0xe5),(ushort *)(&PTR_DAT_803981b8 + iVar2),
                 '\x01');
                    /* {@symbol 8011c3c0} */
    (**(code **)(*(int *)pDll11 + 0x14))(this,puVar4,3);
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void DRhightop_hitDetect(ObjInstance *this) { //802B8C18
  return;
}


/* Library Function - Single Match
    dll_2BA_func06
   
   Library: KioskDefault 0 0 */

void DRhightop_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802B8C1C
  ObjInstance **ppOVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  undefined *puVar4;
  int iVar5;
  int local_30 [2];
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  puVar4 = this->state;
  if (shouldRender) {
    objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
    objGetAttachPointWorldPos
              (this,2,(float *)(puVar4 + 0x9b4),(float *)(puVar4 + 0x9b8),(float *)(puVar4 + 0x9bc),
               FALSE);
    objFootFn_80091ec4((int)this,3,4,(int)(puVar4 + 0x978));
    objGetAttachPointWorldPos
              (this,0,(float *)(puVar4 + 0x9c0),(float *)(puVar4 + 0x9c4),(float *)(puVar4 + 0x9c8),
               FALSE);
    puVar4[0xa74] = puVar4[0xa74] & 0xfb | 4;
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))
              (this,puVar4 + 0x3b8,0);
    if (((byte)puVar4[0xa74] >> 6 & 1) != 0) {
      ppOVar1 = Object_playerGetObject(0x39,local_30);
      for (iVar5 = 0; iVar5 < local_30[0]; iVar5 = iVar5 + 1) {
        iVar2 = (*(code *)ppOVar1[iVar5]->dll->ptrs2->field9_0x24)(ppOVar1[iVar5]);
        (*(code *)ppOVar1[iVar5]->dll->ptrs2->setScale)
                  (ppOVar1[iVar5],this,*(undefined4 *)(&DAT_80323d60 + iVar2 * 4),param2_00,
                   param3_00,param4_00,param5_00);
      }
    }
    ppOVar1 = Object_playerGetObject(0x3a,local_30);
    for (iVar5 = 0; iVar5 < local_30[0]; iVar5 = iVar5 + 1) {
      iVar2 = (*(code *)ppOVar1[iVar5]->dll->ptrs2->field9_0x24)(ppOVar1[iVar5]);
      if (((iVar2 != -1) &&
          ((*(code *)ppOVar1[iVar5]->dll->ptrs2->setScale)
                     (ppOVar1[iVar5],this,*(undefined4 *)(&DAT_803981c4 + iVar2 * 4),param2_00,
                      param3_00,param4_00,param5_00), iVar2 == 0)) &&
         (puVar3 = (undefined2 *)objGetJoint((int)this,1), puVar3 != (undefined2 *)0x0)) {
        *puVar3 = 0xe000;
      }
    }
  }
  else {
    puVar4[0xa74] = puVar4[0xa74] & 0xfb;
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    birdOrMenu_func07
    dll_2BA_func07
   
   Library: KioskDefault 0 0 */

void DRhightop_free(ObjInstance *this,int param2) { //802B8E88
  DLL_removeTempDll(0x33);
  return;
}


undefined4 DRhightop_func08(ObjInstance *this) { //802B8EAC
  return 0x43;
}


/* @description Get extra size for object (size of State struct) */

int DRhightop_getExtraSize(void) { //802B8EB4
  return 0xa78;
}


/* Library Function - Single Match
    dll_2BA_func0A
   
   Library: KioskDefault 0 0 */

void DRhightop_setScale(ObjInstance *this,float scale) { //802B9EE4
  float *in_r4;
  double dVar1;
  
  dVar1 = (double)mathFn_80293464((this->pos).rotation.x + 0x8000);
  *in_r4 = (float)(dVar1 * 260.0 + (double)(this->prevPos).x);
  in_r4[1] = (this->prevPos).y + 205.0;
  dVar1 = (double)FUN_80064b04((this->pos).rotation.x + 0x8000);
  in_r4[2] = (float)(dVar1 * 260.0 + (double)(this->prevPos).z);
  return;
}

