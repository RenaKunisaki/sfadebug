
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void robotpatrol_initialise(undefined4 param) { //802088B8
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_167_func01
    dll_1A0_func01
   
   Library: KioskDefault 0 0 */

void robotpatrol_release(void) { //802088BC
  if (DAT_80399e10 != (Texture *)0x0) {
    texFreeTexture(DAT_80399e10);
    DAT_80399e10 = (Texture *)0x0;
  }
  if (DAT_80399e14 != (Texture *)0x0) {
    texFreeTexture(DAT_80399e14);
    DAT_80399e14 = (Texture *)0x0;
  }
  return;
}


/* Library Function - Single Match
    dll_167_func03
   
   Library: KioskDefault 0 0 */

void robotpatrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80208910
  byte *param1;
  
  if (DAT_80399e10 == (Texture *)0x0) {
    DAT_80399e10 = textureLoadAsset(0x127);
  }
  if (DAT_80399e14 == (Texture *)0x0) {
    DAT_80399e14 = textureLoadAsset(0x16f);
  }
  Object_objAddObjectType(this,4);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8020ad14;
  param1 = this->state;
  memclr(param1,0x1cc);
  objAllocMsgQueue(this,5);
  allocVoxRoute((VoxRoute **)(param1 + 0x24));
  param1[0x1c8] = 1;
  *(float *)(param1 + 0x1c4) = -0.02;
  FUN_802096f0((int)this,param1,(int)(param1 + 0x8c));
  FUN_80209ee0(this,param1,param1 + 0x11c);
  FUN_8020a650((int)this,param1,(int)(param1 + 0x1a4));
  FUN_8020a30c(this,param1,(int)(param1 + 0x150));
  *(undefined4 *)(param1 + 4) = 0xffffffff;
  *(undefined4 *)(param1 + 8) = 0xffffffff;
  *param1 = objDef[1].allocatedSize;
  param1[0x1e] = 0;
  param1[0x1f] = 0;
  param1[0x20] = 0;
  return;
}


/* Library Function - Single Match
    dll_167_func04
   
   Library: KioskDefault 0 0 */

void robotpatrol_update(ObjInstance *this) { //80208A30
  uint uVar1;
  undefined *puVar2;
  double dVar3;
  ObjPos local_7c;
  float fStack_64;
  Mtx44 MStack_60;
  undefined4 local_20;
  uint uStack_1c;
  
  puVar2 = this->state;
  FUN_8020ab74(this,(float *)(puVar2 + 0x7c),2);
  FUN_8020975c((int *)this,(int)puVar2,(float *)(puVar2 + 0x8c));
  local_7c.rotation.x = (this->pos).rotation.x;
  local_7c.rotation.y = 0;
  local_7c.rotation.z = 0;
  local_7c.scale = 1.0;
  local_7c.pos.x = 0.0;
  local_7c.pos.y = 0.0;
  local_7c.pos.z = 0.0;
  mtxSetFromObjPos(&MStack_60,&local_7c);
  multVectorByMatrix((double)*(float *)(puVar2 + 200),0.0,(double)*(float *)(puVar2 + 0xd0),
                     &MStack_60,&(this->vel).x,&fStack_64,&(this->vel).z);
  uStack_1c = (uint)*(ushort *)(puVar2 + 0x118);
  local_20 = 0x43300000;
  dVar3 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_1c) -
                                                       4503599627370496.0) * 3.141593) / 32767.0));
  (this->pos).pos.y =
       (float)((double)*(float *)(puVar2 + 0x114) * dVar3 + (double)*(float *)(puVar2 + 0x110));
  uVar1 = (uint)*(ushort *)(puVar2 + 0x118) + (uint)framesThisStep * 0x100;
  if (0xffff < uVar1) {
    uStack_1c = randInt(0xf,0x23);
    uStack_1c = uStack_1c ^ 0x80000000;
    local_20 = 0x43300000;
    *(float *)(puVar2 + 0x114) =
         (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) * 0.1;
  }
  *(short *)(puVar2 + 0x118) = (short)uVar1;
  (this->vel).x = (this->vel).x * 1.066667;
  (this->vel).z = (this->vel).z * 1.066667;
  objMove((double)((this->vel).x * timeDelta),0.0,(double)((this->vel).z * timeDelta),this);
  FUN_80209f3c((int)this,(int)puVar2,(int)(puVar2 + 0x11c));
  FUN_8020a7d0((int)this,puVar2,(float *)(puVar2 + 0x1a4));
  FUN_8020a320((int)this,puVar2,(int *)(puVar2 + 0x150));
  puVar2[0x1c8] = 0;
  return;
}


/* @description Override hit detection */

void robotpatrol_hitDetect(ObjInstance *this) { //80208BFC
  return;
}


/* Library Function - Single Match
    dll_167_func06
   
   Library: KioskDefault 0 0 */

void robotpatrol_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80208C00
  float fVar1;
  byte bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int iVar3;
  int iVar4;
  Mtx44 *pMVar5;
  undefined uVar6;
  undefined uVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  Shadow *pSVar11;
  ObjInstance *obj;
  double dVar12;
  undefined local_e3;
  undefined local_e2;
  undefined local_e1;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined local_d4;
  undefined local_d3;
  longlong local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  longlong local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  longlong local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  
  FUN_800d568c(&local_e1,&local_e2,&local_e3);
  puVar10 = this->state;
  pMVar5 = this->modelInstances->mtxs[(char)this->curModel + -3];
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  obj = *(ObjInstance **)(puVar10 + 0x1a8);
  iVar8 = (int)(&pMVar5->m14)[*(ushort *)&pMVar5->m23 & 1] +
          (&this->data->pAttachPoints->bone)[(char)this->curModel] * 0x100;
  (obj->pos).pos.x = *(float *)(iVar8 + 0x30) + playerMapOffsetX;
  (obj->pos).pos.y = *(float *)(iVar8 + 0x34);
  (obj->pos).pos.z = *(float *)(iVar8 + 0x38) + playerMapOffsetZ;
  objMultPosByMtx(obj,&(obj->prevPos).x,&(obj->prevPos).y,&(obj->prevPos).z);
  iVar8 = objUpdateOpacity(obj);
  if (iVar8 != 0) {
    pSVar11 = obj->shadow;
    bVar2 = puVar10[0x1e];
    if (bVar2 == 1) {
      iVar4 = 0xd0;
      iVar3 = 0;
      iVar8 = 0;
    }
    else if ((bVar2 == 0) || (2 < bVar2)) {
      iVar4 = 0xba;
      iVar3 = 0xff;
      iVar8 = 0xff;
    }
    else {
      iVar4 = 0xd0;
      iVar3 = 0;
      iVar8 = 0;
    }
    uStack_4c = iVar4 - 0xbaU ^ 0x80000000;
    local_50 = 0x43300000;
    uStack_54 = 0xba;
    local_58 = 0x43300000;
    iVar4 = (int)(*(float *)(puVar10 + 0x1a4) *
                  (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) + 0.0);
    local_60 = (longlong)iVar4;
    uStack_64 = iVar3 - 0xffU ^ 0x80000000;
    local_68 = 0x43300000;
    uStack_6c = 0xff;
    local_70 = 0x43300000;
    iVar3 = (int)(*(float *)(puVar10 + 0x1a4) *
                  (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) + 0.0);
    local_78 = (longlong)iVar3;
    uStack_7c = iVar8 - 0xffU ^ 0x80000000;
    local_80 = 0x43300000;
    uStack_84 = 0xff;
    local_88 = 0x43300000;
    iVar8 = (int)(*(float *)(puVar10 + 0x1a4) *
                  (float)((double)CONCAT44(0x43300000,uStack_7c) - 4503601774854144.0) + 0.0);
    local_90 = (longlong)iVar8;
    iVar9 = (int)(&pMVar5->m14)[*(ushort *)&pMVar5->m23 & 1] +
            (&this->data->pAttachPoints[3].bone)[(char)this->curModel] * 0x100;
    local_e0 = (obj->pos).pos.x - (*(float *)(iVar9 + 0x30) + playerMapOffsetX);
    local_dc = (obj->pos).pos.y - *(float *)(iVar9 + 0x34);
    local_d8 = (obj->pos).pos.z - (*(float *)(iVar9 + 0x38) + playerMapOffsetZ);
    dVar12 = sqrt((double)(local_d8 * local_d8 + local_e0 * local_e0 + local_dc * local_dc));
    fVar1 = (float)(1.0 / dVar12);
    *(float *)(puVar10 + 0x1ac) = local_e0 * fVar1;
    *(float *)(puVar10 + 0x1b0) = local_dc * fVar1;
    *(float *)(puVar10 + 0x1b4) = local_d8 * fVar1;
    (pSVar11->field8_0x14).x = -*(float *)(puVar10 + 0x1ac);
    (pSVar11->field8_0x14).y = -*(float *)(puVar10 + 0x1b0);
    (pSVar11->field8_0x14).z = -*(float *)(puVar10 + 0x1b4);
    (pSVar11->pos).x = (obj->pos).pos.x;
    (pSVar11->pos).y = (obj->pos).pos.y;
    (pSVar11->pos).z = (obj->pos).pos.z;
    local_e1 = (undefined)iVar4;
    pSVar11->field_0x3c = local_e1;
    uVar7 = (undefined)iVar3;
    pSVar11->field_0x3d = uVar7;
    uVar6 = (undefined)iVar8;
    pSVar11->field_0x3e = uVar6;
    (obj->oldPos).x = (obj->pos).pos.x;
    (obj->oldPos).y = (obj->pos).pos.y;
    (obj->oldPos).z = (obj->pos).pos.z;
    (obj->pos).rotation.x = *(short *)(puVar10 + 0x1ba);
    (obj->pos).rotation.y = 0;
    (obj->pos).rotation.z = 0;
    (obj->pos).scale = 0.2;
    obj->opacity = (u8)((uint)this->opacity * (obj->newOpacity + 1) >> 8);
    if (0xa0 < obj->opacity) {
      obj->opacity = 0xa0;
    }
    local_d3 = local_e2;
    local_d4 = local_e3;
    local_e3 = uVar6;
    local_e2 = uVar7;
    objRenderCurrentModel
              (obj,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    pMVar5 = obj->modelInstances->mtxs[(char)obj->curModel + -3];
    *(ushort *)&pMVar5->m23 = *(ushort *)&pMVar5->m23 & 0xfff7;
  }
  return;
}


/* Library Function - Single Match
    dll_167_func07
   
   Library: KioskDefault 0 0 */

void robotpatrol_free(ObjInstance *this,int param2) { //8020907C
  undefined *puVar1;
  
  Object_removePlayerObj(this,4);
  puVar1 = this->state;
  FUN_8006e9b0((void **)(puVar1 + 0x24));
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  FUN_8020ab20(this,puVar1,(int)(puVar1 + 0x1a4),param2);
  return;
}


undefined4 robotpatrol_func08(ObjInstance *this) { //802090EC
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int robotpatrol_getExtraSize(void) { //802090F4
  return 0x1cc;
}

