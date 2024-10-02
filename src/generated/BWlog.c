
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void BWlog_initialise(undefined4 param) { //80274ECC
  return;
}


/* @description Called when DLL is unloaded */

void BWlog_release(void) { //80274ED0
  return;
}


/* Library Function - Single Match
    BWlog_func03
   
   Library: KioskDefault 0 0 */

void BWlog_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //80274ED4
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar2,0,0x8040023,1);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar2,2,&DAT_8031cc60,&DAT_80397f90,&PTR_DAT_80397f98);
  puVar2[0x254] = 100;
  Object_objAddObjectType(this,0xb);
  *(float *)(puVar2 + 0x2b4) = 15.0;
  *(undefined2 *)(puVar2 + 0x31a) = 0x2000;
  this->shadow->flags = this->shadow->flags | 0x40a50;
  this->shadow->field_0x3c = 0xff;
  this->shadow->field_0x3d = 0xff;
  this->shadow->field_0x3e = 0xff;
  this->shadow->field_0x3f = 0x7f;
  for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
    *(float *)(puVar2 + iVar1 * 0xc + 0x260) = (this->pos).pos.x;
    *(float *)(puVar2 + iVar1 * 0xc + 0x264) = (this->pos).pos.y;
    *(float *)(puVar2 + iVar1 * 0xc + 0x268) = (this->pos).pos.z;
  }
  return;
}


/* Library Function - Single Match
    BWlog_func04
   
   Library: KioskDefault 0 0 */

void BWlog_update(ObjInstance *this) { //80275008
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  ObjInstance *pOVar7;
  int iVar8;
  undefined *param2;
  double in_f1;
  double dVar9;
  float local_134;
  float fStack_130;
  Mtx44 MStack_12c;
  Mtx44 MStack_ec;
  Mtx44 MStack_ac;
  ObjPos local_6c;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40 [2];
  longlong local_38;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  param2 = this->state;
  local_134 = 10000.0;
  pOVar7 = getSeqObj(0x17,this,&local_134);
  *(ObjInstance **)(param2 + 0x334) = pOVar7;
  if (*(int *)(param2 + 0x334) != 0) {
    iVar8 = *(int *)(*(int *)(param2 + 0x334) + 0x4c);
    objDistObj2Obj(this,*(ObjInstance **)(param2 + 0x334));
    local_134 = (float)in_f1;
    if (param2[0x32a] == '\x02') {
      fVar2 = 0.95;
    }
    else {
      fVar2 = 0.5;
    }
    uStack_24 = (int)*(short *)(iVar8 + 0x1a) ^ 0x80000000;
    local_28 = 0x43300000;
    if ((float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) <= local_134) {
      *(undefined4 *)(param2 + 0x334) = 0;
    }
    else {
      for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
        iVar6 = iVar8 * 0xc + 0x278;
        *(float *)(param2 + iVar6) = *(float *)(param2 + iVar6) * fVar2;
        iVar6 = iVar8 * 0xc + 0x280;
        *(float *)(param2 + iVar6) = *(float *)(param2 + iVar6) * fVar2;
      }
    }
  }
  FUN_80276560(this,(int)param2);
  if (param2[0x32a] != '\x02') goto LAB_802751dc;
  FUN_80275fc8(this,(int)param2);
  bVar1 = param2[0x326];
  if (bVar1 < 3) {
    if (bVar1 == 0) {
LAB_80275160:
      FUN_80276380((int)this,(int)param2);
    }
    else {
      FUN_802761ac((int)this,(int)param2);
    }
  }
  else {
    if (4 < bVar1) goto LAB_80275160;
    nop_8027637C();
  }
  uStack_24 = (int)*(short *)(param2 + 0x31e) ^ 0x80000000;
  local_28 = 0x43300000;
  uStack_2c = (int)*(short *)(param2 + 800) ^ 0x80000000;
  local_30 = 0x43300000;
  iVar8 = (int)((float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) *
                -((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 0.05 - 60.0
                 ) * 0.2);
  local_38 = (longlong)iVar8;
  (this->pos).rotation.x = (this->pos).rotation.x - (short)iVar8;
LAB_802751dc:
  local_6c.rotation.x = (this->pos).rotation.x;
  local_6c.rotation.y = (this->pos).rotation.y;
  local_6c.rotation.z = (this->pos).rotation.z;
  local_6c.scale = 1.0;
  local_6c.pos.x = (this->pos).pos.x;
  local_6c.pos.y = (this->pos).pos.y;
  local_6c.pos.z = (this->pos).pos.z;
  mtxSetFromObjPos(&MStack_ac,&local_6c);
  local_6c.rotation.z = 0;
  local_6c.pos.x = 0.0;
  local_6c.pos.y = 0.0;
  local_6c.pos.z = 0.0;
  mtxSetFromObjPos(&MStack_ec,&local_6c);
  local_6c.rotation.x = -local_6c.rotation.x;
  local_6c.rotation.y = -local_6c.rotation.y;
  mtxRotateByVec3s(&MStack_12c,&local_6c.rotation);
  for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
    multVectorByMatrix((double)(float)(&DAT_8031cc60)[iVar8 * 3],
                       (double)(float)(&DAT_8031cc60)[iVar8 * 3 + 1],
                       (double)(float)(&DAT_8031cc60)[iVar8 * 3 + 2],&MStack_ac,
                       (float *)(param2 + iVar8 * 0xc + 0x260),
                       (float *)(param2 + iVar8 * 0xc + 0x264),
                       (float *)(param2 + iVar8 * 0xc + 0x268));
    BWlog_waterHeightFn_80275acc((int)this,(int)param2,iVar8);
    multVectorByMatrix((double)*(float *)(param2 + iVar8 * 4 + 0x2d0),0.0,
                       (double)*(float *)(param2 + iVar8 * 4 + 0x2e0),&MStack_12c,&local_48,
                       &local_44,local_40);
    local_48 = local_48 * -0.5;
    local_40[0] = local_40[0] * 0.5;
    dVar9 = sqrt((double)(local_48 * local_48 + local_40[0] * local_40[0]));
    *(float *)(param2 + 0x310) = (float)dVar9;
    local_40[0] = local_40[0] + *(float *)(param2 + 0x2fc);
    iVar6 = iVar8 * 4 + 0x290;
    *(float *)(param2 + iVar6) =
         timeDelta * (local_40[0] - *(float *)(param2 + iVar8 * 4 + 0x290)) * 0.1 +
         *(float *)(param2 + iVar6);
    if (param2[0x326] == '\0') {
      iVar6 = iVar8 * 4 + 0x298;
      *(float *)(param2 + iVar6) =
           timeDelta * (local_48 - *(float *)(param2 + iVar8 * 4 + 0x298)) * 0.1 +
           *(float *)(param2 + iVar6);
    }
    multVectorByMatrix((double)*(float *)(param2 + iVar8 * 4 + 0x298),0.0,
                       -(double)*(float *)(param2 + iVar8 * 4 + 0x290),&MStack_ec,
                       (float *)(param2 + iVar8 * 0xc + 0x278),&fStack_130,
                       (float *)(param2 + iVar8 * 0xc + 0x280));
    local_48 = *(float *)(param2 + iVar8 * 0xc + 0x278) * timeDelta;
    local_44 = *(float *)(param2 + iVar8 * 0xc + 0x27c) * timeDelta;
    local_40[0] = *(float *)(param2 + iVar8 * 0xc + 0x280) * timeDelta;
    *(float *)(param2 + iVar8 * 0xc + 0x260) = *(float *)(param2 + iVar8 * 0xc + 0x260) + local_48;
    *(float *)(param2 + iVar8 * 0xc + 0x264) = *(float *)(param2 + iVar8 * 0xc + 0x264) + local_44;
    *(float *)(param2 + iVar8 * 0xc + 0x268) =
         *(float *)(param2 + iVar8 * 0xc + 0x268) + local_40[0];
  }
  fVar2 = *(float *)(param2 + 0x264);
  fVar3 = *(float *)(param2 + 0x270);
  fVar4 = *(float *)(param2 + 0x268);
  fVar5 = *(float *)(param2 + 0x274);
  (this->pos).pos.x = (*(float *)(param2 + 0x260) + *(float *)(param2 + 0x26c)) * 0.5;
  (this->pos).pos.y = (fVar2 + fVar3) * 0.5;
  (this->pos).pos.z = (fVar4 + fVar5) * 0.5;
  local_54 = *(float *)(param2 + 0x26c) - *(float *)(param2 + 0x260);
  local_50 = *(float *)(param2 + 0x270) - *(float *)(param2 + 0x264);
  local_4c = *(float *)(param2 + 0x274) - *(float *)(param2 + 0x268);
  sqrt((double)(local_54 * local_54 + local_4c * local_4c));
  iVar8 = getAngle();
  (this->pos).rotation.y = -(short)iVar8;
                    /* {@symbol 8012ac30} */
  (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,param2);
                    /* {@symbol 8012b0e4} */
  (**(code **)(*(int *)pDll1A + 0x14))(this,param2);
                    /* {@symbol 8012b170} */
  (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,param2);
  FUN_8027694c((int *)this,(int)param2);
  FUN_80276c60((short *)this,(int)param2);
  return;
}


/* @description Override hit detection */

void BWlog_hitDetect(ObjInstance *this) { //80275618
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void BWlog_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //8027561C
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


/* Library Function - Multiple Matches With Different Base Names
    BWlog_func07
    dll_29F_func07
   
   Library: KioskDefault 0 0 */

void BWlog_free(ObjInstance *this,int param2) { //80275678
  Object_removePlayerObj(this,0xb);
  return;
}


undefined4 BWlog_func08(ObjInstance *this) { //802756A4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int BWlog_getExtraSize(void) { //802756AC
  return 0x338;
}


/* Library Function - Multiple Matches With Different Base Names
    BWlog_func0A
    dll_18C_func0A
   
   Library: KioskDefault 0 0 */

void BWlog_setScale(ObjInstance *this,float scale) { //802756B4
  ObjInstance *in_r4;
  
  if ((this->state[0x32a] == '\0') && (*(int *)(this->state + 0x334) != 0)) {
    objDistObj2Obj(in_r4,this);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    BWlog_func0B
    dll_18C_func0B
   
   Library: KioskDefault 0 0 */

void BWlog_func0B(short *param1) { //80275720
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


void BWlog_modelMtxFn(ObjInstance *this,float *param2,vec3f *param3) { //80275830
  float *in_r6;
  
  *param2 = (this->pos).pos.x;
  param3->x = (this->pos).pos.y;
  *in_r6 = (this->pos).pos.z;
  return;
}


/* Library Function - Single Match
    BWlog_func0D
   
   Library: KioskDefault 0 0 */

uint BWlog_render2(ObjInstance *this) { //8027584C
  float fVar1;
  N64Button32 NVar2;
  int iVar3;
  undefined *puVar4;
  double dVar5;
  double dVar6;
  
  puVar4 = this->state;
  if (((*(int *)(puVar4 + 0x334) != 0) && (puVar4[0x32a] == '\x02')) &&
     (NVar2 = n64GetEnabledButtonsPressed(0), (NVar2 & N64_BUTTON_B) != 0)) {
    fVar1 = 0.0;
    for (iVar3 = 0; dVar6 = (double)fVar1, iVar3 < 2; iVar3 = iVar3 + 1) {
      dVar5 = sqrt((double)(*(float *)(puVar4 + iVar3 * 0xc + 0x278) *
                            *(float *)(puVar4 + iVar3 * 0xc + 0x278) +
                           *(float *)(puVar4 + iVar3 * 0xc + 0x280) *
                           *(float *)(puVar4 + iVar3 * 0xc + 0x280)));
      fVar1 = (float)(dVar6 + dVar5);
    }
    return ((uint)(byte)((dVar6 < 2.0) << 3) << 0x1c) >> 0x1f;
  }
  return 0;
}


undefined4 BWlog_func0E(void) { //8027591C
  return 0;
}


/* Library Function - Single Match
    BWlog_func0F
   
   Library: KioskDefault 0 0 */

void BWlog_func0F(short *param1,float *param2,float *param3,float *param4) { //80275924
  ObjPos local_60;
  Mtx44 MStack_48;
  
  local_60.rotation.x = *param1;
  local_60.rotation.y = 0;
  local_60.rotation.z = 0;
  local_60.scale = 1.0;
  local_60.pos.x = *(float *)(param1 + 6);
  local_60.pos.y = *(float *)(param1 + 8);
  local_60.pos.z = *(float *)(param1 + 10);
  mtxSetFromObjPos(&MStack_48,&local_60);
  multVectorByMatrix(0.0,0.0,-10.0,&MStack_48,param2,param3,param4);
  return;
}


undefined BWlog_func10(int param1) { //802759BC
  return *(undefined *)(*(int *)(param1 + 0xb8) + 0x32a);
}


/* Library Function - Single Match
    BWlog_func11
   
   Library: KioskDefault 0 0 */

void BWlog_func11(int param1,int param2) { //802759D8
  ObjInstance *pOVar1;
  int iVar2;
  
  pOVar1 = Object_objGetMain();
  iVar2 = *(int *)(param1 + 0xb8);
  if (param2 == 0) {
    FUN_800855a8(param1);
    FUN_801a7dfc((int)pOVar1,1);
                    /* {@symbol 80153bd4} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x24))(0,1);
  }
  else {
    FUN_8008559c(param1);
    FUN_801a7dc8((int)pOVar1,1);
                    /* {@symbol 80153bd4} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x24))(0,0x2b);
  }
  *(char *)(iVar2 + 0x32a) = (char)param2;
  return;
}


/* Library Function - Single Match
    BWlog_func12
   
   Library: KioskDefault 0 0 */

void BWlog_func12(int param1,undefined4 *param2,uint *param3) { //80275A80
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = *(undefined4 *)(iVar1 + 0x2cc);
  *param3 = (uint)*(byte *)(iVar1 + 0x327);
  return;
}


double BWlog_func13(undefined4 param_1,float *param2) { //80275AA8
  *param2 = -0.006;
  return 0.0;
}


undefined4 BWlog_func14(void) { //80275AB8
  return 0;
}


void BWlog_func15(void) { //80275AC0
  return;
}


void BWlog_func16(void) { //80275AC4
  return;
}


void BWlog_func17(void) { //80275AC8
  return;
}

