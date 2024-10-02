
/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func00
    dll_2FA_func00
    dll_2FB_func00
   
   Library: KioskDefault 0 0 */

void tree2FA_initialise(undefined4 param) { //802CD7C8
  if (DAT_8039a190 == (DLL_func **)0x0) {
    DAT_8039a190 = DLL_setup(0x1002,1,FALSE);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func01
    dll_184_func01
    dll_210_func07
    dll_243_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void tree2FA_release(void) { //802CD804
  if (DAT_8039a190 != (LoadedDll *)0x0) {
    DLL_free(DAT_8039a190);
    DAT_8039a190 = (LoadedDll *)0x0;
  }
  return;
}


/* Library Function - Single Match
    dll_2FA_func03
   
   Library: KioskDefault 0 0 */

void tree2FA_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //802CD83C
  float fVar1;
  float *pfVar2;
  float afStack_34 [7];
  undefined4 local_18;
  uint uStack_14;
  
  pfVar2 = (float *)this->state;
  *pfVar2 = 0.0025;
  pfVar2[1] = 0.0;
  *(undefined2 *)(pfVar2 + 5) = 200;
  *(undefined *)(pfVar2 + 6) = 0x21;
  pfVar2[3] = 0.0;
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  if (objDef[1].mapStates1 == 0) {
    pfVar2[2] = 1.0;
  }
  else {
    uStack_14 = (uint)objDef[1].mapStates1;
    local_18 = 0x43300000;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503599627370496.0) / 255.0;
    pfVar2[2] = fVar1;
    (this->pos).scale = fVar1;
    if ((this->pos).scale == 0.0) {
      (this->pos).scale = 1.0;
    }
    (this->pos).scale = (this->pos).scale * this->data->scale;
  }
  Object_ObjAnimSetMove(0.0,this,0,0);
  objRunAnimation(1.0,1.0,(int)this,afStack_34);
  this->flags_0xf8 = 0;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_2FA_func04
   
   Library: KioskDefault 0 0 */

void tree2FA_update(ObjInstance *this) { //802CD97C
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ObjInstance *pOVar7;
  byte bVar8;
  uint uVar9;
  short sVar10;
  float *pfVar11;
  double dVar12;
  undefined2 local_c4;
  undefined2 local_c2;
  undefined2 local_c0;
  float local_bc;
  float local_b8;
  undefined4 uStack_b4;
  float local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  float afStack_9c [7];
  uint uStack_80;
  int iStack_7c;
  undefined2 local_78;
  undefined auStack_74 [6];
  undefined2 local_6e;
  float local_68;
  float local_64;
  float local_60;
  int local_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  longlong local_48;
  longlong local_40;
  
  _savefpr_30();
  pfVar11 = (float *)this->state;
  local_ac = 8;
  local_a8 = 0xff;
  local_a4 = 0xff;
  local_a0 = 0x78;
  objRunAnimation((double)*pfVar11,(double)timeDelta,(int)this,afStack_9c);
  uVar4 = ~(uint)*(byte *)(pfVar11 + 6) & 0xf;
  if (uVar4 == 0) goto LAB_802cdf0c;
  if (0.0 < pfVar11[3]) {
    pfVar11[3] = pfVar11[3] - timeDelta;
  }
  if (0.0025 < *pfVar11) {
    *pfVar11 = *pfVar11 - 0.001;
  }
  if ((*(byte *)(pfVar11 + 6) & 0x80) != 0) {
    FUN_802ce4ac((int)this,(int)pfVar11);
  }
  bVar8 = (byte)uVar4;
  if ((*(byte *)(pfVar11 + 6) & 0x20) != 0) {
    if (0.0 <= pfVar11[4]) {
      pfVar11[4] = pfVar11[4] - timeDelta;
    }
    iVar5 = FUN_800884c8((int)this,&local_5c,&iStack_7c,&uStack_80,&local_b8,&uStack_b4,&local_b0);
    if (iVar5 != 0) {
      if (iVar5 == 0x11) {
        if (0.0 < pfVar11[4]) goto LAB_802cdc78;
        pfVar11[4] = 60.0;
      }
      if ((*(int *)(local_5c + 0xc4) != 0) && (*(short *)(*(int *)(local_5c + 0xc4) + 0x44) == 1)) {
        FUN_801a83d0();
      }
      local_b8 = local_b8 + playerMapOffsetX;
      local_b0 = local_b0 + playerMapOffsetZ;
      local_bc = 1.0;
      local_c0 = 0;
      local_c2 = 0;
      local_c4 = 0;
      (**(code **)(*DAT_8039a190 + 4))(0,1,&local_c4,0x401,0xffffffff,&local_ac);
      if ((*(byte *)(pfVar11 + 6) & 0x40) == 0) {
        audioTryStartSfx((int *)this,1,499,0x7f,"tree.c",0x100);
        audioTryStartSfx((int *)this,2,0x43,0x7f,"tree.c",0x101);
        local_40 = (longlong)(int)(pfVar11[2] * 132.0);
        FUN_802ce084(this,(int)pfVar11,0x32,bVar8,(short)(int)(pfVar11[2] * 132.0),0);
        *pfVar11 = 0.0225;
      }
      else {
        FUN_802ce2c0((int *)this,pfVar11,bVar8);
      }
      if ((*(byte *)(pfVar11 + 6) & 0x80) != 0) {
        for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
          if ((pfVar11[iVar5 + 7] != 0.0) &&
             (iVar6 = (**(code **)(**(int **)((int)pfVar11[iVar5 + 7] + 0x68) + 0x28))
                                (pfVar11[iVar5 + 7]), 1 < iVar6)) {
            FUN_80088818((int)pfVar11[iVar5 + 7],(int)this,'\x0e',1,0);
            break;
          }
        }
      }
    }
  }
LAB_802cdc78:
  pOVar7 = Object_objGetMain();
  fVar2 = (this->pos).pos.x - (pOVar7->pos).pos.x;
  fVar3 = (this->pos).pos.z - (pOVar7->pos).pos.z;
  dVar12 = sqrt((double)(fVar2 * fVar2 + fVar3 * fVar3));
  uVar1 = (uint)dVar12;
  local_40 = (longlong)(int)uVar1;
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(pfVar11 + 5)) {
    if ((((*(byte *)(pfVar11 + 6) & 0x10) != 0) &&
        (*(ushort *)(pfVar11 + 5) <= *(ushort *)((int)pfVar11 + 0x16))) && (pfVar11[3] <= 0.0)) {
      local_40 = (longlong)(int)(pfVar11[2] * 10.0);
      FUN_802ce084(this,(int)pfVar11,10,bVar8,(short)(int)(pfVar11[2] * 10.0),1);
      pfVar11[3] = 340.0;
    }
    pfVar11[1] = pfVar11[1] - timeDelta;
    if (pfVar11[1] <= 0.0) {
      local_40 = (longlong)(int)(pfVar11[2] * 40.0);
      local_48 = (longlong)(int)(pfVar11[2] * 40.0);
      local_78 = (undefined2)(int)(pfVar11[2] * 40.0);
      sVar10 = (short)(int)(pfVar11[2] * 40.0);
      uStack_4c = randInt(-(int)sVar10,(int)sVar10);
      uStack_4c = uStack_4c ^ 0x80000000;
      local_50 = 0x43300000;
      local_68 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
      local_64 = 120.0;
      uStack_54 = randInt(-(int)sVar10,(int)sVar10);
      uStack_54 = uStack_54 ^ 0x80000000;
      local_58 = 0x43300000;
      local_60 = (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
      local_6e = 0;
      for (uVar9 = 0; uVar9 == 0; uVar9 = uVar4 & uVar9) {
        uVar9 = randInt(1,0xf);
      }
      if (uVar9 == 3) {
LAB_802cdecc:
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41d,auStack_74,2,0xffffffff,0);
      }
      else if (uVar9 < 3) {
        if (uVar9 == 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41a,auStack_74,2,0xffffffff,0);
        }
        else {
          if (uVar9 == 0) goto LAB_802cdecc;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41b,auStack_74,2,0xffffffff,0);
        }
      }
      else {
        if (4 < uVar9) goto LAB_802cdecc;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41c,auStack_74,2,0xffffffff,0);
      }
      pfVar11[1] = pfVar11[1] + 30.0;
    }
  }
  *(short *)((int)pfVar11 + 0x16) = (short)uVar1;
LAB_802cdf0c:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void tree2FA_hitDetect(ObjInstance *this) { //802CDF28
  return;
}


/* Library Function - Single Match
    dll_2FA_func06
   
   Library: KioskDefault 0 0 */

void tree2FA_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //802CDF2C
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  pOVar3 = this->def;
  puVar4 = this->state;
  if (shouldRender) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this->state + 0x14)
                                                   ) - 4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
    FUN_80096afc((ushort)*(byte *)&pOVar3[1].pos.x,(ushort)*(byte *)((int)&pOVar3[1].pos.x + 1),
                 (ushort)*(byte *)((int)&pOVar3[1].pos.x + 2));
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((puVar4[0x18] & 0x80) != 0) {
      for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
        objGetAttachPointWorldPos
                  (this,iVar1,(float *)(puVar4 + iVar1 * 0xc + 0x28),
                   (float *)(puVar4 + iVar1 * 0xc + 0x2c),(float *)(puVar4 + iVar1 * 0xc + 0x30),
                   FALSE);
      }
    }
    this->flags_0xf8 = 1;
    return;
  }
  return;
}


/* @description Free object instance */

void tree2FA_free(ObjInstance *this,int param2) { //802CE070
  return;
}


undefined4 tree2FA_func08(ObjInstance *this) { //802CE074
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int tree2FA_getExtraSize(void) { //802CE07C
  return 0x4c;
}

