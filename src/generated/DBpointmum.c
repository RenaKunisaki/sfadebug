
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBpointmum_initialise(undefined4 param) { //802918A4
  return;
}


/* @description Called when DLL is unloaded */

void DBpointmum_release(void) { //802918A8
  return;
}


/* Library Function - Single Match
    birdOrMenu_func03
   
   Library: KioskDefault 0 0 */

void DBpointmum_init(ObjInstance *param1,int param2,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802918AC
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = param1->state;
  iVar2 = 0;
  puVar5[0x520] = 0;
  uVar1 = mainGetBit(0x3ee);
  printf(" ACt Number %i ",uVar1);
  uVar1 = mainGetBit(0x3ee);
  if (uVar1 == 2) {
    DAT_8039a0d8 = &DAT_80320e9c;
    DAT_80320ea8 = &LAB_80292220;
    DAT_80320eb8 = &LAB_80292220;
    DAT_80320ec8 = &LAB_80292220;
    iVar4 = 3;
  }
  else if (((int)uVar1 < 2) || (3 < (int)uVar1)) {
    DAT_8039a0d8 = &DAT_80320e0c;
    DAT_80320e18 = &LAB_80292144;
    DAT_80320e28 = &LAB_80292220;
    DAT_80320e38 = &LAB_80292220;
    DAT_80320e48 = &LAB_80292220;
    iVar4 = 4;
  }
  else {
    DAT_8039a0d8 = &DAT_80320e4c;
    DAT_80320e58 = &LAB_80292220;
    DAT_80320e68 = &LAB_80292598;
    DAT_80320e78 = &LAB_80292494;
    DAT_80320e88 = buttonFn_802927c4;
    DAT_80320e98 = &LAB_80292220;
    iVar4 = 5;
  }
  printf(" Running Mummy ");
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80291d60;
  (param1->pos).rotation.x = (short)((int)*(char *)(param2 + 0x18) << 8);
  DLL_createTempDll(0x33);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (param1,puVar5,0xffffe001,0x5554,3);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x18))(puVar5,300,0x78);
  puVar5[0x4a9] = puVar5[0x4a9] | 0x2a;
  *(float *)(puVar5 + 0x524) = 0.004;
  puVar3 = puVar5 + 0x684;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar3,0,&DAT_00040007,1);
                    /* {@symbol 8012ab74} */
  (**(code **)(*(int *)pDll1A + 8))(puVar3,2,&DAT_80320df4,&DAT_80398020,9);
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(param1,puVar3);
  for (; (uVar1 = mainGetBit((int)*(short *)(DAT_8039a0d8 + iVar2 * 0x10 + 4)), uVar1 != 0 &&
         (iVar2 < iVar4)); iVar2 = iVar2 + 1) {
    puVar5[0x520] = puVar5[0x520] + '\x01';
  }
  return;
}


/* Library Function - Single Match
    birdOrMenu_func04
   
   Library: KioskDefault 0 0 */

void DBpointmum_update(ObjInstance *this) { //80291B80
  undefined *puVar1;
  
  puVar1 = this->state;
  menuOperationFn_80291e44((int *)this);
                    /* {@symbol 8012ac30} */
  (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar1 + 0x684);
                    /* {@symbol 8012b0e4} */
  (**(code **)(*(int *)pDll1A + 0x14))(this,puVar1 + 0x684);
                    /* {@symbol 8012b170} */
  (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar1 + 0x684);
  return;
}


/* @description Override hit detection */

void DBpointmum_hitDetect(ObjInstance *this) { //80291C14
  return;
}


/* Library Function - Single Match
    birdOrMenu_func06
   
   Library: KioskDefault 0 0 */

void DBpointmum_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80291C18
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  undefined auStack_28 [8];
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  puVar2 = this->state;
  local_20 = 0.005;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))(this,puVar2,0);
    uVar1 = *(uint *)(puVar2 + 0x51c);
    if (uVar1 != 0) {
      iVar3 = 0;
      while( true ) {
        if (3 < iVar3) break;
        if ((uVar1 & 1 << iVar3) != 0) {
          objGetAttachPointWorldPos(this,iVar3 + 2,&fStack_1c,&fStack_18,&fStack_14,FALSE);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x676,auStack_28,&DAT_00210001,0xffffffff,0);
        }
        iVar3 = iVar3 + 1;
      }
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    birdOrMenu_func07
    dll_2BA_func07
   
   Library: KioskDefault 0 0 */

void DBpointmum_free(ObjInstance *this,int param2) { //80291D2C
  DLL_removeTempDll(0x33);
  return;
}


undefined4 DBpointmum_func08(ObjInstance *this) { //80291D50
  return 0xc9;
}


/* @description Get extra size for object (size of State struct) */

int DBpointmum_getExtraSize(void) { //80291D58
  return 0x91c;
}

