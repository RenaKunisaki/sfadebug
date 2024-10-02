
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRbullet_initialise(undefined4 param) { //802B3094
  return;
}


/* @description Called when DLL is unloaded */

void DRbullet_release(void) { //802B3098
  return;
}


/* Library Function - Single Match
    dll_2AB_func03
   
   Library: KioskDefault 0 0 */

void DRbullet_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802B309C
  undefined *puVar1;
  
  puVar1 = this->state;
  *(undefined *)((int)&this->hitstate->sizeX2 + 1) = 0x13;
  *(undefined *)&this->hitstate->flags_0x60 = 1;
  this->hitstate->flags = this->hitstate->flags & 0xfffe;
  (this->pos).pos.x = (objDef->pos).x;
  (this->pos).pos.y = (objDef->pos).y;
  (this->pos).pos.z = (objDef->pos).z;
  (this->vel).x =
       (float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].objType) - 4503599627370496.0);
  (this->vel).y =
       (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].objType + 1)) -
              4503599627370496.0);
  (this->vel).z =
       (float)((double)CONCAT44(0x43300000,(uint)objDef[1].allocatedSize) - 4503599627370496.0);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa10;
  }
  puVar1[4] = 0;
  puVar1[5] = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}


/* Library Function - Single Match
    dll_2AB_func04
   
   Library: KioskDefault 0 0 */

void DRbullet_update(ObjInstance *this) { //802B3188
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  bVar1 = puVar4[4];
  if (bVar1 == 1) {
    iVar2 = FUN_802b3720((int *)this);
    if (iVar2 != 0) {
      FUN_80088da4((int)this);
      puVar4[4] = 0;
    }
  }
  else if ((bVar1 != 0) && (bVar1 < 3)) {
    objMove((double)((this->vel).x * timeDelta),(double)((this->vel).y * timeDelta),
            (double)((this->vel).z * timeDelta),this);
    uVar3 = (uint)framesThisStep;
    iVar2 = *(int *)(puVar4 + 8);
    *(uint *)(puVar4 + 8) = iVar2 - uVar3;
    if (((int)(iVar2 - uVar3) < 0) || ((this->hitstate->flags & 8) != 0)) {
      puVar4[4] = 1;
      *(undefined4 *)(puVar4 + 8) = 0;
      if ((this->hitstate->flags & 8) != 0) {
        audioTryStartSfx((int *)this,1,0x1ee,0x7f,(char *)&PTR_DAT_80323850,0x8d);
      }
    }
    (this->hitstate->field12_0x3c).z = 2.242078e-44;
    (this->hitstate->field12_0x3c).y = 2.242078e-44;
  }
  return;
}


/* @description Override hit detection */

void DRbullet_hitDetect(ObjInstance *this) { //802B32A0
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_282_func06
    dll_2AB_func06
   
   Library: KioskDefault 0 0 */

void DRbullet_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802B32A4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->state[4] != '\0')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_2AB_func07
   
   Library: KioskDefault 0 0 */

void DRbullet_free(ObjInstance *this,int param2) { //802B3318
  if (*(ObjInstance **)this->state != (ObjInstance *)0x0) {
    Object_objFreeObject(*(ObjInstance **)this->state);
  }
  return;
}


undefined4 DRbullet_func08(ObjInstance *this) { //802B335C
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int DRbullet_getExtraSize(void) { //802B3364
  return 0xc;
}


void DRbullet_setScale(ObjInstance *this,float scale) { //802B336C
  countLeadingZeros(-(uint)(byte)this->state[4]);
  return;
}


/* Library Function - Single Match
    dll_2AB_func0B
   
   Library: KioskDefault 0 0 */

void DRbullet_func0B(double param1,int *param2,int param3,int param4) { //802B339C
  float fVar1;
  int iVar2;
  ObjInstance *pOVar3;
  ObjInstance **ppOVar4;
  double dVar5;
  undefined4 auStack_78 [2];
  vec3s vStack_70;
  vec3s vStack_68;
  vec3f local_60;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  longlong local_38;
  
  _savefpr_28();
  ppOVar4 = (ObjInstance **)param2[0x2e];
  local_48 = *(float *)(param4 + 0xc) - *(float *)(param3 + 0xc);
  local_44 = *(float *)(param4 + 0x10) - *(float *)(param3 + 0x10);
  local_40 = *(float *)(param4 + 0x14) - *(float *)(param3 + 0x14);
  dVar5 = sqrt((double)(local_40 * local_40 + local_48 * local_48 + local_44 * local_44));
  fVar1 = (float)(dVar5 / param1);
  if (fVar1 != 0.0) {
    local_48 = local_48 / fVar1;
    local_44 = local_44 / fVar1;
    local_40 = local_40 / fVar1;
  }
  param2[3] = *(int *)(param3 + 0xc);
  param2[4] = *(int *)(param3 + 0x10);
  param2[5] = *(int *)(param3 + 0x14);
  param2[9] = (int)local_48;
  param2[10] = (int)local_44;
  param2[0xb] = (int)local_40;
  sqrt((double)((float)param2[9] * (float)param2[9] + (float)param2[0xb] * (float)param2[0xb]));
  iVar2 = getAngle();
  *(short *)param2 = (short)iVar2;
  iVar2 = getAngle();
  *(short *)((int)param2 + 2) = -(short)iVar2;
  *(undefined2 *)(param2 + 1) = 0;
  FUN_80088d3c((int)param2);
  *(undefined *)(ppOVar4 + 1) = 2;
  audioTryStartSfx(param2,2,0x237,0x7f,(char *)&PTR_DAT_80323850,0xf1);
  local_60.x = (float)param2[3] + (float)param2[9] * 600.0;
  local_60.y = (float)param2[4] + (float)param2[10] * 600.0;
  local_60.z = (float)param2[5] + (float)param2[0xb] * 600.0;
  vec3f_toNearest10((vec3f *)(param2 + 3),&vStack_68);
  vec3f_toNearest10(&local_60,&vStack_70);
  iVar2 = FUN_8006dd10((undefined4 *)&vStack_68,(undefined4 *)&vStack_70,auStack_78,(undefined *)0x0
                       ,'\0');
  if (iVar2 == 0) {
    FUN_8006db28(&local_60.x,(short *)auStack_78);
    local_54 = local_60.x - (float)param2[3];
    local_50 = local_60.y - (float)param2[4];
    local_4c = local_60.z - (float)param2[5];
    dVar5 = sqrt((double)(local_4c * local_4c + local_54 * local_54 + local_50 * local_50));
    local_38 = (longlong)(int)(ObjInstance *)(int)(dVar5 / param1);
    ppOVar4[2] = (ObjInstance *)(int)(dVar5 / param1);
  }
  else {
    ppOVar4[2] = (ObjInstance *)0x258;
  }
  if (*ppOVar4 != (ObjInstance *)0x0) {
    Object_objFreeObject(*ppOVar4);
  }
  pOVar3 = (ObjInstance *)FUN_802b3918((int)param2,0x24b);
  *ppOVar4 = pOVar3;
  if (pOVar3 != (ObjInstance *)0x0) {
    ((*ppOVar4)->vel).x = (float)param2[9];
    ((*ppOVar4)->vel).y = (float)param2[10];
    ((*ppOVar4)->vel).z = (float)param2[0xb];
  }
  *(undefined *)((int)param2 + 0x36) = 0xff;
  param2[2] = *(int *)(param2[0x14] + 4);
  _restfpr_28();
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_282_func0C
    dll_2AB_func0C
   
   Library: KioskDefault 0 0 */

void DRbullet_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //802B36A8
  undefined *puVar1;
  
  puVar1 = this->state;
  puVar1[5] = puVar1[5] | 1;
  if (puVar1[4] == '\0') {
    Object_objFreeObject(this);
  }
  return;
}


void DRbullet_render2(ObjInstance *this) { //802B36F4
  if (this->state[4] == '\x02') {
    this->state[4] = 1;
  }
  return;
}

