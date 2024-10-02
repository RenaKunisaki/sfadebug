
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCbirchtree_initialise(undefined4 param) { //8025977C
  return;
}


/* @description Called when DLL is unloaded */

void SCbirchtree_release(void) { //80259780
  return;
}


/* Library Function - Single Match
    dll_1F6_func03
   
   Library: KioskDefault 0 0 */

void SCbirchtree_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80259784
  float fVar1;
  float *pfVar2;
  float afStack_3c [7];
  longlong local_20;
  longlong local_18;
  
  pfVar2 = (float *)this->state;
  *pfVar2 = 0.0025;
  pfVar2[1] = 0.0;
  *(ushort *)(pfVar2 + 4) = (ushort)objDef[1].mapStates1 << 1;
  *(undefined *)(pfVar2 + 5) = *(undefined *)((int)&objDef[1].pos.x + 3);
  pfVar2[3] = 0.0;
  (this->pos).rotation.z = (*(byte *)&objDef[1].objType - 0x7f) * 0x80;
  (this->pos).rotation.y = (*(byte *)((int)&objDef[1].objType + 1) - 0x7f) * 0x80;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  fVar1 = *(float *)&objDef[1].loadFlags;
  pfVar2[2] = fVar1;
  (this->pos).scale = fVar1;
  Object_ObjAnimSetMove(0.0,this,0,0);
  objRunAnimation(1.0,1.0,(int)this,afStack_3c);
  local_18 = (longlong)(int)(pfVar2[2] * 15.0);
  local_20 = (longlong)(int)(pfVar2[2] * 255.0);
  objHitFn_80089188(this,(short)(int)(pfVar2[2] * 15.0),-5,(short)(int)(pfVar2[2] * 255.0));
  this->flags_0xf8 = 0;
  if ((*(byte *)(pfVar2 + 5) & 0xc0) == 0) {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_1F6_func04
   
   Library: KioskDefault 0 0 */

void SCbirchtree_update(ObjInstance *this) { //802598B4
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ObjInstance *pOVar7;
  byte bVar8;
  short sVar9;
  uint uVar10;
  short sVar11;
  float *pfVar12;
  double dVar13;
  float afStack_a4 [7];
  uint uStack_88;
  int iStack_84;
  undefined auStack_80 [6];
  undefined2 local_7a;
  float local_74;
  float local_70;
  float local_6c;
  undefined4 auStack_68 [2];
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  longlong local_48;
  longlong local_40;
  
  _savefpr_30();
  pfVar12 = (float *)this->state;
  objRunAnimation((double)*pfVar12,(double)timeDelta,(int)this,afStack_a4);
  uVar4 = ~(uint)*(byte *)(pfVar12 + 5) & 0xf;
  if (uVar4 == 0) goto LAB_80259d68;
  if (0.0 < pfVar12[3]) {
    pfVar12[3] = pfVar12[3] - timeDelta;
  }
  if (0.0025 < *pfVar12) {
    *pfVar12 = *pfVar12 - 0.001;
  }
  if ((*(byte *)(pfVar12 + 5) & 0x80) != 0) {
    FUN_8025a310((int)this,(int)pfVar12);
  }
  bVar8 = (byte)uVar4;
  if (((*(byte *)(pfVar12 + 5) & 0x20) != 0) &&
     (iVar5 = FUN_800883e4((int)this,auStack_68,&iStack_84,&uStack_88), iVar5 != 0)) {
    if ((*(byte *)(pfVar12 + 5) & 0x40) == 0) {
      audioTryStartSfx((int *)this,1,499,0x7f,(char *)&PTR_DAT_8031b7d0,0xb9);
      audioTryStartSfx((int *)this,2,0x43,0x7f,(char *)&PTR_DAT_8031b7d0,0xba);
      local_40 = (longlong)(int)(pfVar12[2] * 132.0);
      FUN_80259ee0(this,(int)pfVar12,0x32,bVar8,(short)(int)(pfVar12[2] * 132.0),0);
      *pfVar12 = 0.0225;
    }
    else {
      FUN_8025a11c((int *)this,pfVar12,bVar8);
    }
    if ((*(byte *)(pfVar12 + 5) & 0x80) != 0) {
      for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
        if ((pfVar12[iVar5 + 6] != 0.0) &&
           (iVar6 = (**(code **)(**(int **)((int)pfVar12[iVar5 + 6] + 0x68) + 0x28))
                              (pfVar12[iVar5 + 6]), 1 < iVar6)) {
          FUN_80088818((int)pfVar12[iVar5 + 6],(int)this,'\x0e',1,0);
        }
      }
    }
  }
  pOVar7 = Object_objGetMain();
  fVar2 = (this->pos).pos.x - (pOVar7->pos).pos.x;
  fVar3 = (this->pos).pos.z - (pOVar7->pos).pos.z;
  dVar13 = sqrt((double)(fVar2 * fVar2 + fVar3 * fVar3));
  uVar1 = (uint)dVar13;
  local_40 = (longlong)(int)uVar1;
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(pfVar12 + 4)) {
    if ((((*(byte *)(pfVar12 + 5) & 0x10) != 0) &&
        (*(ushort *)(pfVar12 + 4) <= *(ushort *)((int)pfVar12 + 0x12))) && (pfVar12[3] <= 0.0)) {
      local_40 = (longlong)(int)(pfVar12[2] * 10.0);
      FUN_80259ee0(this,(int)pfVar12,10,bVar8,(short)(int)(pfVar12[2] * 10.0),1);
      pfVar12[3] = 340.0;
    }
    pfVar12[1] = pfVar12[1] - timeDelta;
    if (pfVar12[1] <= 0.0) {
      local_40 = (longlong)(int)(pfVar12[2] * 60.0);
      fVar2 = pfVar12[2];
      local_48 = (longlong)(int)(fVar2 * 50.0);
      sVar11 = (short)(int)(pfVar12[2] * 60.0);
      uStack_4c = randInt(-(int)sVar11,(int)sVar11);
      uStack_4c = uStack_4c ^ 0x80000000;
      local_50 = 0x43300000;
      local_74 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
      sVar9 = (short)(int)(fVar2 * 50.0);
      uStack_54 = randInt(-(int)sVar9,(int)sVar9);
      uStack_54 = uStack_54 ^ 0x80000000;
      local_58 = 0x43300000;
      local_70 = pfVar12[2] * 200.0 +
                 (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
      uStack_5c = randInt(-(int)sVar11,(int)sVar11);
      uStack_5c = uStack_5c ^ 0x80000000;
      local_60 = 0x43300000;
      local_6c = (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0);
      local_7a = 0;
      for (uVar10 = 0; uVar10 == 0; uVar10 = uVar4 & uVar10) {
        uVar10 = randInt(1,0xf);
      }
      if (uVar10 == 3) {
LAB_80259d28:
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41d,auStack_80,2,0xffffffff,0);
      }
      else if (uVar10 < 3) {
        if (uVar10 == 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41a,auStack_80,2,0xffffffff,0);
        }
        else {
          if (uVar10 == 0) goto LAB_80259d28;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41b,auStack_80,2,0xffffffff,0);
        }
      }
      else {
        if (4 < uVar10) goto LAB_80259d28;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x41c,auStack_80,2,0xffffffff,0);
      }
      pfVar12[1] = pfVar12[1] + 30.0;
    }
  }
  *(short *)((int)pfVar12 + 0x12) = (short)uVar1;
LAB_80259d68:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void SCbirchtree_hitDetect(ObjInstance *this) { //80259D84
  return;
}


/* Library Function - Single Match
    dll_1F6_func06
   
   Library: KioskDefault 0 0 */

void SCbirchtree_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80259D88
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
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this->state + 0x10)
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
    if ((puVar4[0x14] & 0x80) != 0) {
      for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
        objGetAttachPointWorldPos
                  (this,iVar1,(float *)(puVar4 + iVar1 * 0xc + 0x24),
                   (float *)(puVar4 + iVar1 * 0xc + 0x28),(float *)(puVar4 + iVar1 * 0xc + 0x2c),
                   FALSE);
      }
    }
    this->flags_0xf8 = 1;
    return;
  }
  return;
}


/* @description Free object instance */

void SCbirchtree_free(ObjInstance *this,int param2) { //80259ECC
  return;
}


undefined4 SCbirchtree_func08(ObjInstance *this) { //80259ED0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SCbirchtree_getExtraSize(void) { //80259ED8
  return 0x48;
}

