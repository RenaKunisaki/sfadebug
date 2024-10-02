
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFlog_initialise(undefined4 param) { //80270724
  return;
}


/* @description Called when DLL is unloaded */

void DFlog_release(void) { //80270728
  return;
}


/* Library Function - Single Match
    dll_18C_func03
   
   Library: KioskDefault 0 0 */

void DFlog_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //8027072C
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  DAT_8039a008 = runlinkDownloadCode(0x1020,1);
  Object_objAddObjectType(this,0xb);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80270a44;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  puVar1 = puVar3 + 0x28c;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar1,0,&DAT_00040002,1);
                    /* {@symbol 8012ab74} */
  (**(code **)(*(int *)pDll1A + 8))(puVar1,2,&DAT_8031ca50,&DAT_80397f64,8);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar1,2,&DAT_8031ca38,&DAT_80397f58,&PTR_DAT_80397f60);
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(this,puVar1);
  this->hitstate->flags = this->hitstate->flags | 1;
  this->hitstate->flags = this->hitstate->flags | 4;
  puVar3[0x4ec] = 0;
  puVar3[0x4ed] = 0;
  puVar3[0x4ee] = 0;
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    *(float *)(puVar3 + iVar2 * 0xc + 0x240) = (this->pos).pos.x;
    *(float *)(puVar3 + iVar2 * 0xc + 0x244) = (this->pos).pos.y;
    *(float *)(puVar3 + iVar2 * 0xc + 0x248) = (this->pos).pos.z;
  }
  FUN_80270fe4((short *)this);
  *(undefined2 *)(puVar3 + 0x4f0) = 0;
  *(undefined2 *)(puVar3 + 0x4f2) = 0;
  *(float *)(puVar3 + 0x288) = 0.0;
  return;
}


/* Library Function - Single Match
    dll_18C_func04
   
   Library: KioskDefault 0 0 */

void DFlog_update(ObjInstance *this) { //80270908
  double dVar1;
  
  FUN_80088d3c((int)this);
  FUN_80270fe4((short *)this);
  dVar1 = (double)FUN_802710dc((int)this);
  FUN_802713ac(dVar1,this);
  return;
}


/* @description Override hit detection */

void DFlog_hitDetect(ObjInstance *this) { //80270998
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DFlog_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //8027099C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_18C_func07
   
   Library: KioskDefault 0 0 */

void DFlog_free(ObjInstance *this,int param2) { //802709F8
  DLL_free(DAT_8039a008);
  DAT_8039a008 = (LoadedDll *)0x0;
  Object_removePlayerObj(this,0xb);
  return;
}


undefined4 DFlog_func08(ObjInstance *this) { //80270A34
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int DFlog_getExtraSize(void) { //80270A3C
  return 0x4f8;
}


/* Library Function - Multiple Matches With Different Base Names
    BWlog_func0A
    dll_18C_func0A
   
   Library: KioskDefault 0 0 */

void DFlog_setScale(ObjInstance *this,float scale) { //80270A70
  ObjInstance *in_r4;
  
  if ((this->state[0x4ec] == '\0') && (*(int *)(this->state + 0x4f4) != 0)) {
    objDistObj2Obj(in_r4,this);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    BWlog_func0B
    dll_18C_func0B
   
   Library: KioskDefault 0 0 */

void DFlog_func0B(short *param1) { //80270ADC
  ObjInstance *pOVar1;
  float local_7c;
  float local_78;
  float local_74;
  Mtx44 MStack_70;
  ObjPos local_30;
  
  _savefpr_30();
  pOVar1 = Object_objGetMain();
  if (pOVar1 != (ObjInstance *)0x0) {
    local_30.rotation.x = *param1 + 0x4000;
    local_30.rotation.y = param1[1];
    local_30.rotation.z = param1[2];
    local_30.scale = 1.0;
    local_30.pos.x = 0.0;
    local_30.pos.y = 0.0;
    local_30.pos.z = 0.0;
    mtxSetFromObjPos(&MStack_70,&local_30);
    multVectorByMatrix(0.0,0.0,1.0,&MStack_70,&local_74,&local_78,&local_7c);
  }
  _restfpr_30();
  return;
}


void DFlog_modelMtxFn(ObjInstance *this,float *param2,vec3f *param3) { //80270BEC
  float *in_r6;
  
  *param2 = (this->pos).pos.x;
  param3->x = (this->pos).pos.y;
  *in_r6 = (this->pos).pos.z;
  return;
}


/* Library Function - Single Match
    dll_18C_func0D
   
   Library: KioskDefault 0 0 */

uint DFlog_render2(ObjInstance *this) { //80270C08
  float fVar1;
  int iVar2;
  N64Button32 NVar3;
  int in_r4;
  undefined *puVar4;
  double dVar5;
  double dVar6;
  
  puVar4 = this->state;
                    /* {@symbol 80153978} */
                    /* {@symbol 8016db64} */
  if ((((*(int *)(puVar4 + 0x4f4) != 0) && (puVar4[0x4ec] == '\x02')) &&
      (iVar2 = (**(code **)(*(int *)pDll_ObjSeq + 0x10))(), iVar2 != 0x52)) &&
     (((iVar2 != 0x5c && (iVar2 = (**(code **)(*pdll_camcontrol + 0x1c))(), iVar2 == 0)) &&
      (NVar3 = n64GetEnabledButtonsPressed(0), (NVar3 & N64_BUTTON_B) != 0)))) {
    fVar1 = 0.0;
    for (iVar2 = 0; dVar6 = (double)fVar1, iVar2 < 2; iVar2 = iVar2 + 1) {
      dVar5 = sqrt((double)(*(float *)(puVar4 + iVar2 * 0xc + 600) *
                            *(float *)(puVar4 + iVar2 * 0xc + 600) +
                           *(float *)(puVar4 + iVar2 * 0xc + 0x260) *
                           *(float *)(puVar4 + iVar2 * 0xc + 0x260)));
      fVar1 = (float)(dVar6 + dVar5);
    }
    return ((uint)(byte)((dVar6 < 2.0) << 3) << 0x1c) >> 0x1f;
  }
  FUN_801a7dc8(in_r4,1);
  return 0;
}


undefined4 DFlog_func0E(void) { //80270D2C
  return 0;
}


/* Library Function - Single Match
    dll_18C_func0F
   
   Library: KioskDefault 0 0 */

void DFlog_func0F(short *param1,float *param2,float *param3,float *param4) { //80270D34
  ObjPos local_68;
  Mtx44 MStack_50;
  
  local_68.pos.x = *(float *)(param1 + 6);
  local_68.pos.y = *(float *)(param1 + 8);
  local_68.pos.z = *(float *)(param1 + 10);
  local_68.rotation.x = *param1;
  local_68.rotation.y = param1[1];
  local_68.rotation.z = param1[2];
  local_68.scale = 1.0;
  mtxSetFromObjPos(&MStack_50,&local_68);
  multVectorByMatrix(0.0,1.5,-1.0,&MStack_50,param2,param3,param4);
  *param2 = *(float *)(param1 + 6);
  *param3 = *(float *)(param1 + 8) + 30.0;
  *param4 = *(float *)(param1 + 10);
  return;
}


undefined DFlog_func10(int param1) { //80270DEC
  return *(undefined *)(*(int *)(param1 + 0xb8) + 0x4ec);
}


/* Library Function - Single Match
    dll_18C_func11
   
   Library: KioskDefault 0 0 */

void DFlog_func11(int param1,int param2) { //80270E08
  ObjInstance *pOVar1;
  int iVar2;
  
  iVar2 = *(int *)(param1 + 0xb8);
  pOVar1 = Object_objGetMain();
  *(char *)(iVar2 + 0x4ec) = (char)param2;
  if (param2 == 0) {
    FUN_801a7dfc((int)pOVar1,1);
                    /* {@symbol 80153bd4} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x24))(0,1);
  }
  else {
    FUN_801a7dc8((int)pOVar1,1);
                    /* {@symbol 80153bd4} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x24))(0,0x2b);
  }
  return;
}


/* Library Function - Single Match
    dll_18C_func12
   
   Library: KioskDefault 0 0 */

void DFlog_func12(int param1,float *param2,uint *param3) { //80270EA4
  double dVar1;
  
  dVar1 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)*(short *)(param1 + 2)
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  *param3 = (uint)(*(short *)(param1 + 2) < 1);
  if (dVar1 < 0.0) {
    dVar1 = -dVar1;
  }
  *param2 = (float)dVar1;
  return;
}


/* Library Function - Single Match
    dll_18C_func13
   
   Library: KioskDefault 0 0 */

double DFlog_func13(int param1,float *param2) { //80270F54
  float fVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = *(int *)(param1 + 0xb8);
  dVar3 = (double)(*(float *)(iVar2 + 0x288) * 1.2);
  if (*(float *)(iVar2 + 0x288) < 0.0) {
    fVar1 = -*(float *)(iVar2 + 0x288);
  }
  else {
    fVar1 = *(float *)(iVar2 + 0x288);
  }
  *param2 = FLOAT_803a23fc * fVar1;
  if (dVar3 < -1.0) {
    dVar3 = -1.0;
  }
  if (1.0 < dVar3) {
    dVar3 = 1.0;
  }
  return dVar3;
}


undefined4 DFlog_func14(void) { //80270FD4
  return 0;
}


void DFlog_func15(void) { //80270FDC
  return;
}


void DFlog_func16(void) { //80270FE0
  return;
}


void DFlog_func17(void) { //802725A4
  return;
}

