
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMcannon_initialise(undefined4 param) { //80227F00
  return;
}


/* @description Called when DLL is unloaded */

void DIMcannon_release(void) { //80227F04
  return;
}


/* Library Function - Single Match
    dll_208_func03
   
   Library: KioskDefault 0 0 */

void DIMcannon_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //80227F08
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined *puVar4;
  
  objAllocMsgQueue(this,4);
  if (this->romdefno == DIMCannonBa) {
    FUN_80229044((short *)this,(int)objDef);
  }
  else {
    Object_setPriority(this,0x5a);
    puVar4 = this->state;
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    this->fptr_0xbc = FUN_80228798;
    (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].pos.z << 8);
    DAT_80399e78 = runlinkDownloadCode(0x1021,1);
    sVar1._0_1_ = objDef[1].allocatedSize;
    sVar1._1_1_ = objDef[1].mapStates1;
    uVar3 = mainGetBit((int)sVar1);
    if (uVar3 == 0) {
      sVar2._0_1_ = objDef[1].loadFlags;
      sVar2._1_1_ = objDef[1].mapStates2;
      uVar3 = mainGetBit((int)sVar2);
      if (uVar3 != 0) {
        puVar4[0x24] = 4;
      }
    }
    else {
      puVar4[0x27] = 0x3c;
      puVar4[0x24] = 5;
    }
  }
  Object_objAddObjectType(this,4);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_208_func04
   
   Library: KioskDefault 0 0 */

void DIMcannon_update(ObjInstance *this) { //80227FFC
  byte bVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  ObjInstance *pOVar8;
  uint uVar9;
  N64Button32 NVar10;
  undefined uVar12;
  ObjInstance *pOVar11;
  ObjDef *pOVar13;
  ObjInstance **ppOVar14;
  double dVar15;
  ObjInstance *local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  _savefpr_30();
  pOVar13 = this->def;
  pOVar8 = Object_getSidekicksLoaded();
  if (this->romdefno == DIMCannonBa) {
    FUN_802291c8(this);
  }
  else {
    if (((this->flags_0xaf & ModelDisableFlag08) != 0) &&
       (sVar3._0_1_ = pOVar13[1].allocatedSize, sVar3._1_1_ = pOVar13[1].mapStates1,
       uVar9 = mainGetBit((int)sVar3), uVar9 != 0)) {
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    }
    ppOVar14 = (ObjInstance **)this->state;
    if ((*(char *)((int)ppOVar14 + 0x26) == '\0') &&
       (NVar10 = n64GetEnabledButtonsPressed(0), (NVar10 & N64_BUTTON_DOWN) != 0)) {
      *(undefined *)((int)ppOVar14 + 0x26) = 1;
    }
    if (pOVar8 == (ObjInstance *)0x0) {
      *(undefined *)((int)ppOVar14 + 0x26) = 0;
    }
    else {
      uVar12 = (*pOVar8->dll->ptrs2[2].onLoad)(pOVar8);
      *(undefined *)((int)ppOVar14 + 0x26) = uVar12;
      if (*(char *)(ppOVar14 + 9) == '\x06') {
        if (*(char *)((int)ppOVar14 + 0x26) != '\0') {
          (*pOVar8->dll->ptrs2[1].modelMtxFn_0x28)(pOVar8,0,(vec3f *)0x0);
          *(undefined *)((int)ppOVar14 + 0x26) = 0;
        }
      }
      else {
        (*pOVar8->dll->ptrs2[1].hitDetect)(pOVar8);
      }
    }
    if (*(char *)((int)ppOVar14 + 0x26) == '\0') {
      pOVar8 = Object_objGetMain();
      pOVar11 = playerGetRidingObj(pOVar8);
      if (pOVar11 == (ObjInstance *)0x0) {
        *ppOVar14 = pOVar8;
      }
      else {
        *ppOVar14 = (ObjInstance *)0x0;
      }
    }
    else {
      *ppOVar14 = pOVar8;
    }
    if ((this->animId == 1) && (1.0 <= this->animTimer)) {
      Object_ObjAnimSetMove(0.0,this,0,0);
    }
    (this->pos).flags = (this->pos).flags & ~Invisible;
    bVar1 = *(byte *)(ppOVar14 + 9);
    if (bVar1 == 4) {
      FUN_80228b48((double)(float)ppOVar14[1],(double)(float)ppOVar14[2],(double)(float)ppOVar14[3],
                   (double)(float)ppOVar14[4],(ushort *)this);
      sVar4._0_1_ = pOVar13[1].allocatedSize;
      sVar4._1_1_ = pOVar13[1].mapStates1;
      uVar9 = mainGetBit((int)sVar4);
      if (uVar9 == 0) {
        if ((*ppOVar14 != (ObjInstance *)0x0) &&
           (sVar5._0_1_ = pOVar13[1].bound, sVar5._1_1_ = pOVar13[1].cullDist,
           uVar9 = mainGetBit((int)sVar5), uVar9 == 0)) {
          dVar15 = (double)objDistSqObj2ObjXZ(this,*ppOVar14);
          uStack_2c = (int)*(short *)((int)&pOVar13[1].pos.y + 2) ^ 0x80000000;
          local_30 = 0x43300000;
          if (dVar15 < (double)(((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0
                                        ) * 250000.0) / 100.0)) {
            *(undefined *)(ppOVar14 + 9) = 1;
          }
        }
      }
      else {
        *(undefined *)(ppOVar14 + 9) = 5;
      }
      *(undefined *)((int)ppOVar14 + 0x25) = 0;
      *(undefined2 *)(ppOVar14 + 8) = 0;
      *(undefined2 *)((int)ppOVar14 + 0x22) = 0;
    }
    else if (bVar1 < 4) {
      if (bVar1 == 2) {
        uStack_2c = (uint)*(byte *)((int)&pOVar13[1].pos.z + 3) *
                    (uint)*(byte *)((int)&pOVar13[1].pos.z + 3) ^ 0x80000000;
        local_30 = 0x43300000;
        if (((float)ppOVar14[4] <
             (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0)) &&
           (*(char *)((int)ppOVar14 + 0x26) == '\0')) {
          pOVar8 = Object_getSidekicksLoaded();
          if (pOVar8 != (ObjInstance *)0x0) {
            (*pOVar8->dll->ptrs2[1].modelMtxFn_0x28)(pOVar8,0,(vec3f *)0x0);
          }
          mainSetBits((int)*(short *)&pOVar13[1].pos.x,1);
          *(undefined *)(ppOVar14 + 9) = 6;
        }
      }
      else if ((bVar1 < 2) && (bVar1 != 0)) {
        sVar6._0_1_ = pOVar13[1].allocatedSize;
        sVar6._1_1_ = pOVar13[1].mapStates1;
        uVar9 = mainGetBit((int)sVar6);
        if (uVar9 == 0) {
          sVar7._0_1_ = pOVar13[1].bound;
          sVar7._1_1_ = pOVar13[1].cullDist;
          uVar9 = mainGetBit((int)sVar7);
          if (uVar9 == 0) {
            if (*ppOVar14 == (ObjInstance *)0x0) {
              *(undefined *)(ppOVar14 + 9) = 4;
            }
            else {
              ppOVar14[1] = (ObjInstance *)((*ppOVar14)->pos).pos.x;
              ppOVar14[2] = (ObjInstance *)((*ppOVar14)->pos).pos.y;
              ppOVar14[3] = (ObjInstance *)((*ppOVar14)->pos).pos.z;
              if (0 < *(short *)(ppOVar14 + 8)) {
                *(ushort *)(ppOVar14 + 8) = *(short *)(ppOVar14 + 8) - (ushort)framesThisStep;
              }
              if (0 < *(short *)((int)ppOVar14 + 0x22)) {
                *(ushort *)((int)ppOVar14 + 0x22) =
                     *(short *)((int)ppOVar14 + 0x22) - (ushort)framesThisStep;
              }
              dVar15 = (double)objDistSqObj2ObjXZ(this,*ppOVar14);
              ppOVar14[4] = (ObjInstance *)(float)dVar15;
              uStack_2c = (uint)*(byte *)((int)&pOVar13[1].pos.z + 3) *
                          (uint)*(byte *)((int)&pOVar13[1].pos.z + 3) ^ 0x80000000;
              local_30 = 0x43300000;
              if (((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) <=
                   (float)ppOVar14[4]) || (*(char *)((int)ppOVar14 + 0x26) != '\0')) {
                FUN_80228b48((double)(float)ppOVar14[1],(double)(float)ppOVar14[2],
                             (double)(float)ppOVar14[3],(double)(float)ppOVar14[4],(ushort *)this);
                FUN_80228e60(this);
                uStack_2c = (int)*(short *)((int)&pOVar13[1].pos.y + 2) ^ 0x80000000;
                local_30 = 0x43300000;
                if (((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 260100.0
                    ) / 100.0 < (float)ppOVar14[4]) {
                  *(undefined *)(ppOVar14 + 9) = 4;
                }
              }
              else {
                pOVar8 = Object_getSidekicksLoaded();
                if (pOVar8 != (ObjInstance *)0x0) {
                  (*pOVar8->dll->ptrs2[1].modelMtxFn_0x28)(pOVar8,0,(vec3f *)0x0);
                }
                mainSetBits((int)*(short *)&pOVar13[1].pos.x,1);
                *(undefined *)(ppOVar14 + 9) = 6;
              }
            }
          }
          else {
            *(undefined *)(ppOVar14 + 9) = 4;
          }
        }
        else {
          *(undefined *)(ppOVar14 + 9) = 5;
        }
      }
    }
    else if (bVar1 == 6) {
      if (*ppOVar14 != (ObjInstance *)0x0) {
        ppOVar14[1] = (ObjInstance *)((*ppOVar14)->pos).pos.x;
        ppOVar14[2] = (ObjInstance *)((*ppOVar14)->pos).pos.y;
        ppOVar14[3] = (ObjInstance *)((*ppOVar14)->pos).pos.z;
        dVar15 = (double)objDistSqObj2ObjXZ(this,*ppOVar14);
        ppOVar14[4] = (ObjInstance *)(float)dVar15;
        uStack_2c = (int)*(short *)((int)&pOVar13[1].pos.y + 2) ^ 0x80000000;
        local_30 = 0x43300000;
        if (((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 90000.0) / 100.0
            < (float)ppOVar14[4]) {
          mainSetBits((int)*(short *)((int)&pOVar13[1].pos.x + 2),1);
          *(undefined *)(ppOVar14 + 9) = 1;
        }
      }
    }
    else if (bVar1 < 6) {
      if (*(char *)((int)ppOVar14 + 0x27) < '\x01') {
        if ((this->flags_0xaf & CanPressAToTalk) != 0) {
          local_34 = this;
                    /* {@symbol 801539f0} */
          (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x5f,1,0,4,&local_34,0x32,0xff);
          *(undefined *)(ppOVar14 + 9) = 3;
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
          *(undefined *)((int)ppOVar14 + 0x27) = 0x3c;
          this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
        }
      }
      else {
        *(u8 *)((int)ppOVar14 + 0x27) = *(char *)((int)ppOVar14 + 0x27) - framesThisStep;
      }
      *(undefined *)((int)ppOVar14 + 0x25) = 0;
      *(undefined2 *)(ppOVar14 + 8) = 0;
      *(undefined2 *)((int)ppOVar14 + 0x22) = 0;
    }
    if (this->animId == 1) {
      fVar2 = 0.025;
    }
    else {
      fVar2 = 0.01;
    }
    objRunAnimation((double)fVar2,(double)timeDelta,(int)this,(float *)0x0);
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void DIMcannon_hitDetect(ObjInstance *this) { //8022864C
  return;
}


/* Library Function - Single Match
    dll_208_func06
   
   Library: KioskDefault 0 0 */

void DIMcannon_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //80228650
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  if (this->romdefno == DIMCannonBa) {
    if (shouldRender) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
  }
  else {
    puVar1 = this->state;
    if (shouldRender) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
      objGetAttachPointWorldPos
                (this,1,(float *)(puVar1 + 0x14),(float *)(puVar1 + 0x18),(float *)(puVar1 + 0x1c),
                 FALSE);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_208_func07
   
   Library: KioskDefault 0 0 */

void DIMcannon_free(ObjInstance *this,int param2) { //80228704
  if (this->romdefno == DIMCannonBa) {
    FUN_80229340(this);
  }
  else {
    DLL_free(DAT_80399e78);
    DAT_80399e78 = (LoadedDll *)0x0;
  }
  Object_removePlayerObj(this,4);
  return;
}


undefined4 DIMcannon_func08(ObjInstance *this) { //80228760
  if (this->romdefno == DIMCannonBa) {
    return 0;
  }
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIMcannon_getExtraSize(int param1) { //8022877C
  if (*(short *)(param1 + 0x46) == 0x1d6) {
    return 1;
  }
  return 0x30;
}

