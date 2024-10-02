
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFguardian_initialise(undefined4 param) { //802025D0
  return;
}


/* @description Called when DLL is unloaded */

void CFguardian_release(void) { //802025D4
  return;
}


/* Library Function - Single Match
    guardian_func03
   
   Library: KioskDefault 0 0 */

void CFguardian_init(ObjInstance *param1,int param2,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802025D8
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 in_register_00004008;
  undefined4 in_register_00004010;
  undefined4 in_register_00004018;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined2 local_20;
  undefined *local_1c;
  
  puVar3 = param1->state;
  local_1c = &DAT_00010606;
  local_28 = &DAT_0005000f;
  local_24 = &DAT_000f0000;
  local_20 = 0;
  local_2c = &DAT_01010101;
  if (puVar3 != (undefined *)0x0) {
    objAllocMsgQueue(param1,4);
    Object_objAddObjectType(param1,0x18);
    uVar1 = mainGetBit(0x4b);
    puVar3[0x8f4] = (char)uVar1;
    printf(" Initalise Guardian State %i ",(uint)(byte)puVar3[0x8f4]);
    printf(" GUARDIAN POS : %f %f %f ",(double)CONCAT44(in_register_00004008,x),
           (double)CONCAT44(in_register_00004010,y),(double)CONCAT44(in_register_00004018,z));
    param1->field76_0xf4 = 1;
    param1->fptr_0xbc = FUN_802029c0;
    (param1->pos).rotation.x = (short)((int)*(char *)(param2 + 0x18) << 8);
    *(undefined4 *)(puVar3 + 0x908) = 0;
    *(float *)(puVar3 + 0x678) = 0.0;
    *(undefined4 *)(puVar3 + 0x904) = 6;
    puVar3[0x90f] = 0;
    puVar2 = puVar3 + 0x67c;
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar2,0x2000000,0x42083,1);
                    /* {@symbol 8012abb0} */
    (**(code **)(*(int *)pDll1A + 0xc))(puVar2,4,&DAT_803147ec,&DAT_8031481c,&local_2c);
                    /* {@symbol 8012ab74} */
    (**(code **)(*(int *)pDll1A + 8))(puVar2,4,&DAT_803147ec,&DAT_8031481c,8);
    puVar3[0x4a9] = puVar3[0x4a9] | 0x28;
    puVar3[0x90c] = 1;
    puVar3[0x90d] = 0;
    puVar3[0x90e] = 0;
    uVar1 = mainGetBit(0x57);
    if (uVar1 != 0) {
      puVar3[0x8f4] = 6;
    }
    uVar1 = mainGetBit(0x4c1);
    if (uVar1 != 0) {
      puVar3[0x8f4] = 0xc;
    }
    FUN_80088d3c((int)param1);
    DLL_createTempDll(0x33);
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
              (param1,puVar3,0xffffe001,0x2800,4);
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x18))(puVar3,300,100);
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x1c))
              (puVar3,0,&local_28,4);
  }
  return;
}


/* Library Function - Single Match
    guardian_func04
   
   Library: KioskDefault 0 0 */

void CFguardian_update(ObjInstance *this) { //80202844
  double in_f1;
  
  guardianLandFn_80202b08(in_f1,this);
  return;
}


/* @description Override hit detection */

void CFguardian_hitDetect(ObjInstance *this) { //8020286C
  (this->oldPos).x = (this->pos).pos.x;
  (this->oldPos).y = (this->pos).pos.y;
  (this->oldPos).z = (this->pos).pos.z;
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_2D2_func06
    foodRelated02AF_func06
    guardian_func06
   
   Library: KioskDefault 0 0 */

void CFguardian_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80202888
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))(this,puVar1,0);
  }
  return;
}


/* Library Function - Single Match
    guardian_func07
   
   Library: KioskDefault 0 0 */

void CFguardian_free(ObjInstance *this,int param2) { //80202918
  undefined *puVar1;
  int iVar2;
  
  puVar1 = this->state;
  if (param2 == 0) {
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      if (*(int *)(puVar1 + iVar2 * 4 + 0x508) != 0) {
        Object_objFreeObject(*(ObjInstance **)(puVar1 + iVar2 * 4 + 0x508));
      }
    }
  }
  printf(" FREEING GUARDIAN ");
  Object_removePlayerObj(this,0x18);
  DLL_removeTempDll(0x33);
  return;
}


undefined4 CFguardian_func08(ObjInstance *this) { //802029B0
  return 0x41;
}


/* @description Get extra size for object (size of State struct) */

int CFguardian_getExtraSize(void) { //802029B8
  return 0x910;
}


/* Library Function - Single Match
    guardian_func0A
   
   Library: KioskDefault 0 0 */

void CFguardian_setScale(ObjInstance *this,float scale) { //802046DC
  countLeadingZeros((byte)this->state[0x90f] & 2);
  return;
}

