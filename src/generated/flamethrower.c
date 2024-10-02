
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void flamethrower_initialise(undefined4 param) { //801CD018
  return;
}


/* @description Called when DLL is unloaded */

void flamethrower_release(void) { //801CD01C
  return;
}


/* Library Function - Single Match
    dll_EA_func03
   
   Library: KioskDefault 0 0 */

void flamethrower_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //801CD020
  ObjDef *def;
  uint uVar1;
  ObjInstance *pOVar2;
  int iVar3;
  undefined *puVar4;
  
  if (this->romdefno == FlameBall) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
  }
  else {
    puVar4 = this->state;
    puVar4[0x40] = 1;
    for (iVar3 = 0; iVar3 < 1; iVar3 = iVar3 + 1) {
      def = objAlloc(0x24,FlameBall);
      pOVar2 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
      *(ObjInstance **)(puVar4 + iVar3 * 4) = pOVar2;
      *(undefined2 *)(puVar4 + iVar3 * 2 + 4) = 0x28;
      *(undefined2 *)(puVar4 + iVar3 * 2 + 6) = 0x28;
      *(undefined2 *)(puVar4 + iVar3 * 2 + 8) = 0;
      *(undefined2 *)(puVar4 + iVar3 * 2 + 10) = 0;
      uVar1 = randInt(-500,500);
      *(float *)(puVar4 + iVar3 * 4 + 0xc) =
           (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0) / 50.0;
      uVar1 = randInt(-200,200);
      *(float *)(puVar4 + iVar3 * 4 + 0x10) =
           (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0) / 50.0;
      *(float *)(puVar4 + iVar3 * 4 + 0x14) = 0.0;
      *(float *)(puVar4 + iVar3 * 4 + 0x18) = 0.0;
      *(float *)(puVar4 + iVar3 * 4 + 0x1c) = 0.0;
      puVar4[iVar3 + 0x20] = 0;
      puVar4[0x3e] = 4;
      puVar4[0x3d] = 0;
      puVar4[iVar3 + 0x22] = 10;
    }
    pOVar2 = Object_getSidekicksLoaded();
    if (pOVar2 != (ObjInstance *)0x0) {
      (this->pos).rotation.x = (pOVar2->pos).rotation.x;
      (this->pos).rotation.y = (pOVar2->pos).rotation.y;
      (this->pos).rotation.z = (pOVar2->pos).rotation.z;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_EA_func04
   
   Library: KioskDefault 0 0 */

void flamethrower_update(ObjInstance *this) { //801CD1EC
  float fVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  undefined2 *puVar7;
  short *psVar8;
  double dVar9;
  ObjPos local_144;
  float local_12c;
  float local_128;
  float local_124;
  Mtx44 MStack_120;
  Mtx44 MStack_e0;
  Mtx44 MStack_a0;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_30();
  if (this->romdefno != FlameBall) {
    puVar6 = this->state;
    local_144.pos.x = (this->pos).pos.x;
    local_144.pos.y = (this->pos).pos.y;
    local_144.pos.z = (this->pos).pos.z;
    local_144.rotation.x = (this->pos).rotation.x;
    local_144.rotation.y = (this->pos).rotation.y;
    local_144.rotation.z = 0;
    local_144.scale = 1.0;
    mtxSetFromObjPos(&MStack_a0,&local_144);
    local_144.pos.x = 0.0;
    local_144.pos.y = 0.0;
    local_144.pos.z = 0.0;
    mtxSetFromObjPos(&MStack_e0,&local_144);
    if (puVar6[0x40] == '\0') {
      FUN_80068a9c((uint)this,0x40);
    }
    else {
      audioTryStartSfx((int *)this,0xc0,0x235,0x7f,(char *)&PTR_DAT_80310ea8,0xb5);
    }
    if ((puVar6[0x40] != '\0') &&
       (cVar2 = puVar6[0x3e] - framesThisStep, puVar6[0x3e] = cVar2, cVar2 < '\x01')) {
      for (iVar5 = 0; (iVar3 = -1, iVar5 < 1 && (iVar3 = iVar5, puVar6[iVar5 + 0x20] != '\0'));
          iVar5 = iVar5 + 1) {
      }
      if (iVar3 != -1) {
        puVar7 = *(undefined2 **)(puVar6 + iVar3 * 4);
        puVar6[iVar3 + 0x20] = 1;
        uStack_34 = randInt(-500,500);
        uStack_34 = uStack_34 ^ 0x80000000;
        local_38 = 0x43300000;
        dVar9 = (double)((float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) /
                        100.0);
        uStack_3c = randInt(-200,200);
        uStack_3c = uStack_3c ^ 0x80000000;
        local_40 = 0x43300000;
        multVectorByMatrix(dVar9,(double)((float)((double)CONCAT44(0x43300000,uStack_3c) -
                                                 4503601774854144.0) / 100.0 + 2.0),0.0,&MStack_a0,
                           (float *)(puVar7 + 6),(float *)(puVar7 + 8),(float *)(puVar7 + 10));
        multVectorByMatrix(0.0,0.0,-1.0,&MStack_e0,(float *)(puVar7 + 0x12),(float *)(puVar7 + 0x14)
                           ,(float *)(puVar7 + 0x16));
        uStack_44 = randInt(-100,100);
        uStack_44 = uStack_44 ^ 0x80000000;
        local_48 = 0x43300000;
        fVar1 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0) / 400.0 + 1.0;
        *(float *)(puVar7 + 0x12) = *(float *)(puVar7 + 0x12) * fVar1;
        *(float *)(puVar7 + 0x14) = *(float *)(puVar7 + 0x14) * fVar1;
        *(float *)(puVar7 + 0x16) = *(float *)(puVar7 + 0x16) * fVar1;
        uStack_4c = randInt(0,100);
        uStack_4c = uStack_4c ^ 0x80000000;
        local_50 = 0x43300000;
        *(float *)(puVar7 + 4) =
             0.024 - (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) / 10000.0;
        iVar5 = getAngle();
        *puVar7 = (short)iVar5;
        sqrt((double)(*(float *)(puVar7 + 0x12) * *(float *)(puVar7 + 0x12) +
                     *(float *)(puVar7 + 0x16) * *(float *)(puVar7 + 0x16)));
        iVar5 = getAngle();
        puVar7[1] = -(short)iVar5;
        puVar7[2] = 0;
        *(undefined *)(puVar7 + 0x1b) = 0;
        *(ushort *)(*(int *)(puVar7 + 0x2a) + 0x58) =
             *(ushort *)(*(int *)(puVar7 + 0x2a) + 0x58) & 0xfffe;
        *(undefined2 *)(puVar6 + iVar3 * 2 + 6) = 0;
        *(undefined2 *)(puVar6 + iVar3 * 2 + 8) = 0;
        iVar5 = randInt(0,0xffff);
        *(short *)(puVar6 + iVar3 * 2 + 10) = (short)iVar5;
        uStack_54 = randInt(-500,500);
        uStack_54 = uStack_54 ^ 0x80000000;
        local_58 = 0x43300000;
        *(float *)(puVar6 + iVar3 * 4 + 0xc) =
             (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) / 50.0;
        uStack_5c = randInt(-100,100);
        uStack_5c = uStack_5c ^ 0x80000000;
        local_60 = 0x43300000;
        *(float *)(puVar6 + iVar3 * 4 + 0x10) =
             (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) / 50.0;
        *(undefined4 *)(puVar6 + iVar3 * 4 + 0x14) = *(undefined4 *)(puVar7 + 6);
        *(undefined4 *)(puVar6 + iVar3 * 4 + 0x18) = *(undefined4 *)(puVar7 + 8);
        *(undefined4 *)(puVar6 + iVar3 * 4 + 0x1c) = *(undefined4 *)(puVar7 + 10);
        puVar6[iVar3 + 0x21] = puVar6[0x3d];
        puVar6[0x3d] = puVar6[0x3d] ^ 1;
        puVar6[iVar3 + 0x22] = 10;
        *(undefined4 *)(puVar7 + 0xc) = *(undefined4 *)(puVar7 + 6);
        *(undefined4 *)(puVar7 + 0xe) = *(undefined4 *)(puVar7 + 8);
        *(undefined4 *)(puVar7 + 0x10) = *(undefined4 *)(puVar7 + 10);
        if ((puVar6[0x40] != '\0') && ((char)puVar6[0x3f] < '\x01')) {
          uStack_5c = randInt(-100,100);
          uStack_5c = uStack_5c ^ 0x80000000;
          local_60 = 0x43300000;
          audioTryStartSfx((int *)this,1,0x206,0x7f,(char *)&PTR_DAT_80310ea8,0xef);
          puVar6[0x3f] = 10;
        }
      }
      puVar6[0x3e] = 4;
    }
    if ('\0' < (char)puVar6[0x3f]) {
      puVar6[0x3f] = puVar6[0x3f] - framesThisStep;
    }
    for (iVar5 = 0; iVar5 < 1; iVar5 = iVar5 + 1) {
      if (puVar6[iVar5 + 0x20] != '\0') {
        psVar8 = *(short **)(puVar6 + iVar5 * 4);
        if ((char)puVar6[iVar5 + 0x22] < '\0') {
          *(ushort *)(*(int *)(psVar8 + 0x2a) + 0x58) =
               *(ushort *)(*(int *)(psVar8 + 0x2a) + 0x58) | 1;
          puVar6[iVar5 + 0x22] = 0;
        }
        else if (puVar6[iVar5 + 0x22] == '\0') {
          *(undefined4 *)(*(int *)(psVar8 + 0x2a) + 0x44) = 0x10;
          *(undefined4 *)(*(int *)(psVar8 + 0x2a) + 0x40) = 0x10;
          *(undefined *)(*(int *)(psVar8 + 0x2a) + 0x60) = 1;
          *(undefined *)(*(int *)(psVar8 + 0x2a) + 0x5f) = 0x1a;
        }
        else {
          puVar6[iVar5 + 0x22] = puVar6[iVar5 + 0x22] - framesThisStep;
          if (puVar6[iVar5 + 0x22] == '\0') {
            puVar6[iVar5 + 0x22] = puVar6[iVar5 + 0x22] + -1;
          }
          *(ushort *)(*(int *)(psVar8 + 0x2a) + 0x58) =
               *(ushort *)(*(int *)(psVar8 + 0x2a) + 0x58) & 0xfffe;
        }
        if (*(short *)(puVar6 + iVar5 * 2 + 6) < *(short *)(puVar6 + iVar5 * 2 + 4)) {
          uVar4 = (uint)*(byte *)(psVar8 + 0x1b) + (uint)framesThisStep * 0x10;
          if (0xff < uVar4) {
            uVar4 = 0xff;
          }
          *(char *)(psVar8 + 0x1b) = (char)uVar4;
          iVar3 = iVar5 * 2 + 6;
          *(ushort *)(puVar6 + iVar3) = *(short *)(puVar6 + iVar3) + (ushort)framesThisStep;
        }
        else {
          iVar3 = (uint)*(byte *)(psVar8 + 0x1b) + (uint)framesThisStep * -0x10;
          if (iVar3 < 0) {
            iVar3 = 0;
          }
          *(char *)(psVar8 + 0x1b) = (char)iVar3;
          if (*(char *)(psVar8 + 0x1b) == '\0') {
            puVar6[iVar5 + 0x20] = 0;
            *(ushort *)(*(int *)(psVar8 + 0x2a) + 0x58) =
                 *(ushort *)(*(int *)(psVar8 + 0x2a) + 0x58) & 0xfffe;
            goto LAB_801cda30;
          }
        }
        iVar3 = iVar5 * 2 + 8;
        *(ushort *)(puVar6 + iVar3) = *(short *)(puVar6 + iVar3) + (ushort)framesThisStep * 0x200;
        iVar3 = iVar5 * 2 + 10;
        *(ushort *)(puVar6 + iVar3) = *(short *)(puVar6 + iVar3) + (ushort)framesThisStep * 0x400;
        *(undefined4 *)(psVar8 + 0x40) = *(undefined4 *)(psVar8 + 6);
        *(undefined4 *)(psVar8 + 0x42) = *(undefined4 *)(psVar8 + 8);
        *(undefined4 *)(psVar8 + 0x44) = *(undefined4 *)(psVar8 + 10);
        iVar3 = iVar5 * 4 + 0x14;
        *(float *)(puVar6 + iVar3) =
             *(float *)(psVar8 + 0x12) * timeDelta + *(float *)(puVar6 + iVar3);
        iVar3 = iVar5 * 4 + 0x18;
        *(float *)(puVar6 + iVar3) =
             *(float *)(psVar8 + 0x14) * timeDelta + *(float *)(puVar6 + iVar3);
        iVar3 = iVar5 * 4 + 0x1c;
        *(float *)(puVar6 + iVar3) =
             *(float *)(psVar8 + 0x16) * timeDelta + *(float *)(puVar6 + iVar3);
        local_144.pos.x = 0.0;
        local_144.pos.y = 0.0;
        local_144.pos.z = 0.0;
        local_144.rotation.x = *psVar8;
        local_144.rotation.y = psVar8[1];
        local_144.rotation.z = 0;
        local_144.scale = 1.0;
        mtxSetFromObjPos(&MStack_120,&local_144);
        uStack_5c = (uint)*(ushort *)(puVar6 + iVar5 * 2 + 8);
        local_60 = 0x43300000;
        dVar9 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_5c)
                                                             - 4503599627370496.0) * 3.141593) /
                                                    32767.0));
        local_124 = (float)((double)*(float *)(puVar6 + iVar5 * 4 + 0xc) * dVar9);
        uStack_54 = (uint)*(ushort *)(puVar6 + iVar5 * 2 + 10);
        local_58 = 0x43300000;
        dVar9 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_54)
                                                             - 4503599627370496.0) * 3.141593) /
                                                    32767.0));
        local_128 = (float)((double)*(float *)(puVar6 + iVar5 * 4 + 0x10) * dVar9);
        multVectorByMatrix((double)local_124,(double)local_128,0.0,&MStack_120,&local_124,&local_128
                           ,&local_12c);
        *(float *)(psVar8 + 6) = *(float *)(puVar6 + iVar5 * 4 + 0x14) + local_124;
        *(float *)(psVar8 + 8) = *(float *)(puVar6 + iVar5 * 4 + 0x18) + local_128;
        *(float *)(psVar8 + 10) = *(float *)(puVar6 + iVar5 * 4 + 0x1c) + local_12c;
        psVar8[2] = psVar8[2] + (ushort)framesThisStep * 0x400;
        *(undefined4 *)(psVar8 + 0xc) = *(undefined4 *)(psVar8 + 6);
        *(undefined4 *)(psVar8 + 0xe) = *(undefined4 *)(psVar8 + 8);
        *(undefined4 *)(psVar8 + 0x10) = *(undefined4 *)(psVar8 + 10);
      }
LAB_801cda30:
    }
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void flamethrower_hitDetect(ObjInstance *this) { //801CDA60
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void flamethrower_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801CDA64
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* Library Function - Single Match
    dll_EA_func07
   
   Library: KioskDefault 0 0 */

void flamethrower_free(ObjInstance *this,int param2) { //801CDAB0
  undefined *puVar1;
  int iVar2;
  
  if (this->romdefno == FlameBall) {
                    /* {@symbol 800dc2d8} */
    (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  }
  else {
    puVar1 = this->state;
    if (param2 == 0) {
      for (iVar2 = 0; iVar2 < 1; iVar2 = iVar2 + 1) {
        Object_objFreeObject(*(ObjInstance **)(puVar1 + iVar2 * 4));
      }
    }
  }
  return;
}


undefined4 flamethrower_func08(ObjInstance *this) { //801CDB34
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int flamethrower_getExtraSize(int param1) { //801CDB3C
  if (*(short *)(param1 + 0x46) == 0x1b7) {
    return 0;
  }
  return 0x44;
}


void flamethrower_setScale(ObjInstance *this,float scale) { //801CDB58
  short in_r4;
  short in_r5;
  undefined4 in_register_00004008;
  double in_f2;
  double in_f3;
  
  (this->pos).pos.x = (float)(double)CONCAT44(in_register_00004008,scale);
  (this->pos).pos.y = (float)in_f2;
  (this->pos).pos.z = (float)in_f3;
  (this->pos).rotation.y = in_r4;
  (this->pos).rotation.x = in_r5;
  return;
}


void flamethrower_func0B(int param1,undefined param2) { //801CDB70
  *(undefined *)(*(int *)(param1 + 0xb8) + 0x40) = param2;
  return;
}


void flamethrower_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //801CDB8C
  return;
}

