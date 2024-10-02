
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void IMsnowbike_initialise(undefined4 param) { //8026A218
  return;
}


/* @description Called when DLL is unloaded */

void IMsnowbike_release(void) { //8026A21C
  return;
}


/* Library Function - Single Match
    dll_29E_func03
   
   Library: KioskDefault 0 0 */

void IMsnowbike_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8026A220
  short sVar1;
  uint uVar2;
  ObjDef *pOVar3;
  undefined *param1;
  undefined4 local_1c;
  
  param1 = this->state;
  pOVar3 = this->def;
  local_1c = 0x5050505;
  memclr(param1,0x3d4);
  *(ushort *)(param1 + 0x3bc) = (ushort)*(byte *)&objDef[1].objType << 8;
  *(undefined4 *)(param1 + 0x2f4) = 0;
  *(undefined4 *)(param1 + 0x2f8) = 0;
  DAT_80399ff0 = runlinkDownloadCode(0x1002,1);
  (this->pos).rotation.x = *(short *)(param1 + 0x3bc);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8026d080;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(param1 + 0x4c,0,&DAT_00040007,1);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(param1 + 0x4c,4,&DAT_8031c750,&DAT_8031c780,&local_1c);
  if (*(char *)((int)&objDef[1].objType + 1) == '\0') {
    param1[0x3cc] = 5;
  }
  else {
    param1[0x3cc] = 3;
  }
  FUN_8026d688((int)this,(int)param1);
  FUN_8026bb18(this,(int)(param1 + 0x2ac));
  Object_ObjAnimSetMove(0.0,this,0,0);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x4a10;
  }
  if (*(char *)((int)&objDef[1].objType + 1) != '\0') {
    param1[0x3cd] = param1[0x3cd] | 0x20;
  }
  *(undefined4 *)(param1 + 0x28) = 0xffffffff;
  *(undefined4 *)(param1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param1 + 0x30) = 0xffffffff;
  param1[0x48] = objDef[1].loadFlags;
  param1[0x49] = objDef[1].mapStates2;
  *(float *)(param1 + 0xc) = (this->pos).pos.x;
  *(float *)(param1 + 0x10) = (this->pos).pos.y;
  *(float *)(param1 + 0x14) = (this->pos).pos.z;
  Object_objAddObjectType(this,0xb);
  DAT_80399fe8 = textureLoadAsset(0x89);
  DAT_80399fec = textureLoadAsset(0x3c);
  sVar1._0_1_ = pOVar3[1].bound;
  sVar1._1_1_ = pOVar3[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  param1[0x3cd] = param1[0x3cd] | uVar2 != 0;
  return;
}


/* Library Function - Single Match
    dll_29E_func04
   
   Library: KioskDefault 0 0 */

void IMsnowbike_update(ObjInstance *this) { //8026A418
  int iVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  ObjInstance *param1;
  int iVar8;
  short sVar9;
  undefined uVar10;
  ObjDef *pOVar11;
  undefined *puVar12;
  double dVar13;
  float local_c4;
  float fStack_c0;
  float local_bc;
  Mtx44 MStack_b8;
  float local_78 [2];
  double local_70;
  undefined4 local_68;
  uint uStack_64;
  double local_60;
  double local_58;
  undefined4 local_50;
  uint uStack_4c;
  double local_48;
  
  _savefpr_29();
  puVar12 = this->state;
  pOVar11 = this->def;
  local_78[0] = 0.0;
  if ((puVar12[0x3cd] & 1) == 0) {
    sVar9._0_1_ = pOVar11[1].bound;
    sVar9._1_1_ = pOVar11[1].cullDist;
    uVar7 = mainGetBit((int)sVar9);
    if (uVar7 == 0) {
      if (this->field18_0x58 != (ObjInstanceField58 *)0x0) {
        if (puVar12[0x3ce] == '\0') {
          if (this->hitstate->flags5A != 8) {
            this->hitstate->field56_0x9f = 2;
            this->hitstate->flags5A = 8;
            FUN_800896d8(this);
            goto LAB_8026aeb4;
          }
        }
        else if (this->hitstate->flags5A != 1) {
          this->hitstate->field55_0x9e = 1;
          this->hitstate->flags5A = 1;
          goto LAB_8026aeb4;
        }
      }
      dVar13 = (double)dummiedProfFn_8017a59c(&DAT_808080ff);
      param1 = Object_objGetMain();
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      *(float *)(puVar12 + 0x39c) = (this->pos).pos.x;
      *(float *)(puVar12 + 0x3a0) = (this->pos).pos.y;
      *(float *)(puVar12 + 0x3a4) = (this->pos).pos.z;
      if (((puVar12[0x3cd] & 0x10) != 0) &&
         (puVar12[0x3cd] = puVar12[0x3cd] & 0xef, (puVar12[0x3cd] & 0x20) == 0)) {
        *(float *)(puVar12 + 0x2b8) = 0.0;
        *(float *)(puVar12 + 700) = 0.0;
        *(float *)(puVar12 + 0x2c0) = -2.0;
        *(undefined2 *)(puVar12 + 0x3b8) = 0;
        *(undefined2 *)(puVar12 + 0x3ba) = 0;
        puVar12[0x3d0] = 0;
        *(undefined2 *)(puVar12 + 0x3c2) = 0;
        *(short *)(puVar12 + 0x3bc) = (this->pos).rotation.x;
        *(short *)(puVar12 + 0x3be) = (this->pos).rotation.y;
        *(short *)(puVar12 + 0x3c0) = (this->pos).rotation.z;
        dVar13 = (double)FUN_8026d688((int)this,(int)puVar12);
      }
      cVar2 = puVar12[0x3ce];
      if (cVar2 != '\x01') {
        if (cVar2 < '\x01') {
          if (-1 < cVar2) {
            if ((puVar12[0x3cd] & 0x20) == 0) {
              this->hitstate->field21_0x5b = 0;
              this->hitstate->sizeX1 = 0;
              puVar12[0x3cb] = 0;
              sVar3._0_1_ = pOVar11[1].allocatedSize;
              sVar3._1_1_ = pOVar11[1].mapStates1;
              if ((sVar3 == -1) ||
                 (sVar4._0_1_ = pOVar11[1].allocatedSize, sVar4._1_1_ = pOVar11[1].mapStates1,
                 uVar7 = mainGetBit((int)sVar4), uVar7 != 0)) {
                this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
              }
              else {
                this->flags_0xaf = this->flags_0xaf | PlayerIsDisguised;
              }
              if ((param1 != (ObjInstance *)0x0) && (objDistObj2Obj(param1,this), dVar13 < 50.0)) {
                FUN_8026cf1c((int)this,(int)puVar12,&MStack_b8,0,1,1);
                multVectorByMatrix((double)DAT_8031c7e0,(double)DAT_8031c7e4,(double)DAT_8031c7e8,
                                   &MStack_b8,&local_bc,&fStack_c0,&local_c4);
                fVar5 = (param1->pos).pos.x - local_bc;
                fVar6 = (param1->pos).pos.z - local_c4;
                if (100.0 <= fVar5 * fVar5 + fVar6 * fVar6) {
                  multVectorByMatrix((double)DAT_8031c7ec,(double)DAT_8031c7f0,(double)DAT_8031c7f4,
                                     &MStack_b8,&local_bc,&fStack_c0,&local_c4);
                  local_bc = (param1->pos).pos.x - local_bc;
                  local_c4 = (param1->pos).pos.z - local_c4;
                  if (local_bc * local_bc + local_c4 * local_c4 < 100.0) {
                    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
                    puVar12[0x3cb] = 1;
                  }
                }
                else {
                  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
                  puVar12[0x3cb] = 2;
                }
              }
            }
            FUN_80068a9c((uint)this,2);
            FUN_80068a9c((uint)this,4);
            FUN_80068a9c((uint)this,8);
            if (*(int *)(puVar12 + 0x2f4) != 0) {
              DLL_free(*(LoadedDll **)(puVar12 + 0x2f4));
              *(undefined4 *)(puVar12 + 0x2f4) = 0;
            }
            if (*(int *)(puVar12 + 0x2f8) != 0) {
              DLL_free(*(LoadedDll **)(puVar12 + 0x2f8));
              *(undefined4 *)(puVar12 + 0x2f8) = 0;
            }
          }
        }
        else if (cVar2 < '\x03') {
          if ((puVar12[0x3cd] & 8) == 0) {
            *(undefined4 *)(puVar12 + 0x28) = 0xffffffff;
            *(undefined4 *)(puVar12 + 0x2c) = 0xffffffff;
            *(undefined4 *)(puVar12 + 0x30) = 0xffffffff;
            *(undefined4 *)(puVar12 + 0x34) = 0;
            uVar7 = mainGetBit(0x3a2);
            if (uVar7 == 0) {
              puVar12[0x3cd] = puVar12[0x3cd] & 0xf7;
            }
            else {
              puVar12[0x3cd] = puVar12[0x3cd] | 8;
            }
            if ((puVar12[0x3cd] & 8) != 0) {
              if ((puVar12[0x3cd] & 0x20) == 0) {
                    /* {@symbol 80118c60} */
                (**(code **)(*(int *)pDll_Dummy04 + 0x10))(this,puVar12 + 0x18,0);
              }
              else {
                func15((short *)this);
              }
                    /* {@symbol 801197ec} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x28))(puVar12 + 0x18);
            }
          }
          else {
            uVar7 = mainGetBit(0x3a3);
            if (uVar7 != 0) {
              puVar12[0x3cd] = puVar12[0x3cd] & 0xf7;
            }
          }
          FUN_8026cfe8((int)this,(int)puVar12);
          if ((puVar12[0x3cd] & 0x20) == 0) {
            this->hitstate->field21_0x5b = 10;
            this->hitstate->sizeX1 = 10;
          }
          else {
            if ((puVar12[0x3cd] & 8) == 0) goto LAB_8026aeb4;
            iVar8 = getBlockIdxAtCoords((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                                        (double)(this->pos).pos.z);
            if (iVar8 < 0) {
                    /* {@symbol 801199f8} */
              iVar8 = (**(code **)(*(int *)pDll_Dummy04 + 0x18))
                                ((double)(timeDelta * 2.8),puVar12,puVar12 + 0x18,1,1,0);
                    /* {@symbol 8011935c} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x14))(this,puVar12 + 0x18);
                    /* {@symbol 801197c0} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x2c))(puVar12 + 0x18);
              if (iVar8 == 0) {
                iVar8 = getAngle();
                (this->pos).rotation.x = (short)iVar8;
                (this->pos).pos.x = *(float *)(puVar12 + 0xc);
                (this->pos).pos.y = *(float *)(puVar12 + 0x10);
                (this->pos).pos.z = *(float *)(puVar12 + 0x14);
                puVar12[0x3cd] = puVar12[0x3cd] | 2;
              }
              goto LAB_8026aeb4;
            }
            if ((puVar12[0x3cd] & 2) != 0) {
                    /* {@symbol 801199f8} */
              iVar8 = (**(code **)(*(int *)pDll_Dummy04 + 0x18))
                                ((double)(timeDelta * 2.8),puVar12,puVar12 + 0x18,1,1,0);
                    /* {@symbol 8011935c} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x14))(this,puVar12 + 0x18);
                    /* {@symbol 801197c0} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x2c))(puVar12 + 0x18);
              if (iVar8 == 0) {
                iVar8 = getAngle();
                (this->pos).rotation.x = (short)iVar8;
                (this->pos).pos.x = *(float *)(puVar12 + 0xc);
                (this->pos).pos.y = *(float *)(puVar12 + 0x10);
                (this->pos).pos.z = *(float *)(puVar12 + 0x14);
                *(float *)(puVar12 + 0x2b8) = 0.0;
                *(float *)(puVar12 + 700) = 0.0;
                *(float *)(puVar12 + 0x2c0) = -2.0;
                *(undefined2 *)(puVar12 + 0x3b8) = 0;
                *(undefined2 *)(puVar12 + 0x3ba) = 0;
                puVar12[0x3d0] = 0;
                *(undefined2 *)(puVar12 + 0x3c2) = 0;
                *(short *)(puVar12 + 0x3bc) = (this->pos).rotation.x;
                *(short *)(puVar12 + 0x3be) = (this->pos).rotation.y;
                *(short *)(puVar12 + 0x3c0) = (this->pos).rotation.z;
                FUN_8026d688((int)this,(int)puVar12);
                FUN_800ba478((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                             (double)(this->pos).pos.z,(int)this,local_78,0);
                (this->pos).pos.y = (this->pos).pos.y - local_78[0];
                puVar12[0x3cd] = puVar12[0x3cd] & 0xfd;
              }
              else {
                printf("Finished Is SEt for Some Reason ");
              }
              goto LAB_8026aeb4;
            }
            iVar8 = FUN_8026d4b0((ushort *)this,puVar12,(int)puVar12,(int)(puVar12 + 0x2e0));
            if (iVar8 != 0) goto LAB_8026aeb4;
          }
          if ((puVar12[0x3cd] & 0x20) == 0) {
            if ((puVar12[0x3cd] & 8) != 0) {
                    /* {@symbol 8011935c} */
              sVar9 = (**(code **)(*(int *)pDll_Dummy04 + 0x14))(this,puVar12 + 0x18);
              *(int *)(puVar12 + 0x3b4) = (int)sVar9;
                    /* {@symbol 801197c0} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x2c))(puVar12 + 0x18);
                    /* {@symbol 80119974} */
              uVar10 = (**(code **)(*(int *)pDll_Dummy04 + 0x34))(puVar12 + 0x18);
              puVar12[0x3cf] = uVar10;
            }
            for (iVar8 = 0; iVar8 < (int)(uint)framesThisStep; iVar8 = iVar8 + 1) {
              FUN_8026cecc(this,(int)(puVar12 + 0x2e0),0);
              uVar7 = countLeadingZeros((framesThisStep - 1) - iVar8);
              FUN_8026bb94((double)timeDelta,this,(int)puVar12,(float *)(puVar12 + 0x2ac),uVar7 >> 5
                          );
              local_48 = (double)CONCAT44(0x43300000,-(int)(char)puVar12[0x2ee] ^ 0x80000000);
              uStack_4c = (int)*(short *)(puVar12 + 0x3b8) ^ 0x80000000;
              local_50 = 0x43300000;
              iVar1 = (int)((float)(local_48 - 4503601774854144.0) * 60.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0));
              local_58 = (double)(longlong)iVar1;
              *(short *)(puVar12 + 0x3b8) = *(short *)(puVar12 + 0x3b8) + ((short)iVar1 >> 4);
              local_60 = (double)CONCAT44(0x43300000,-(int)(char)puVar12[0x2ee] ^ 0x80000000);
              uStack_64 = (int)*(short *)(puVar12 + 0x3ba) ^ 0x80000000;
              local_68 = 0x43300000;
              iVar1 = (int)((float)(local_60 - 4503601774854144.0) * 105.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0));
              local_70 = (double)(longlong)iVar1;
              *(short *)(puVar12 + 0x3ba) = *(short *)(puVar12 + 0x3ba) + ((short)iVar1 >> 4);
              (this->pos).rotation.x = *(short *)(puVar12 + 0x3bc) + *(short *)(puVar12 + 0x3b8);
              (this->pos).rotation.z = *(short *)(puVar12 + 0x3c0) + *(short *)(puVar12 + 0x3ba);
            }
          }
          else {
            for (iVar8 = 0; iVar8 < (int)(uint)framesThisStep; iVar8 = iVar8 + 1) {
              uVar7 = countLeadingZeros((framesThisStep - 1) - iVar8);
              FUN_8026c770((double)timeDelta,this,(int)puVar12,(float *)(puVar12 + 0x2ac),uVar7 >> 5
                          );
              local_70 = (double)CONCAT44(0x43300000,-(int)(char)puVar12[0x2ee] ^ 0x80000000);
              uStack_64 = (int)*(short *)(puVar12 + 0x3b8) ^ 0x80000000;
              local_68 = 0x43300000;
              iVar1 = (int)((float)(local_70 - 4503601774854144.0) * 60.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0));
              local_60 = (double)(longlong)iVar1;
              *(short *)(puVar12 + 0x3b8) = *(short *)(puVar12 + 0x3b8) + ((short)iVar1 >> 4);
              local_58 = (double)CONCAT44(0x43300000,-(int)(char)puVar12[0x2ee] ^ 0x80000000);
              uStack_4c = (int)*(short *)(puVar12 + 0x3ba) ^ 0x80000000;
              local_50 = 0x43300000;
              iVar1 = (int)((float)(local_58 - 4503601774854144.0) * 105.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0));
              local_48 = (double)(longlong)iVar1;
              *(short *)(puVar12 + 0x3ba) = *(short *)(puVar12 + 0x3ba) + ((short)iVar1 >> 4);
              (this->pos).rotation.x = *(short *)(puVar12 + 0x3bc) + *(short *)(puVar12 + 0x3b8);
              (this->pos).rotation.z = *(short *)(puVar12 + 0x3c0) + *(short *)(puVar12 + 0x3ba);
            }
          }
          if ((puVar12[0x3cd] & 0x20) == 0) {
            FUN_8026d784((double)*(float *)(puVar12 + 0x2c0),(int *)this,(int)puVar12,
                         (int)(char)puVar12[0x2ef],puVar12 + 0x2f0,7);
          }
          else {
            FUN_80068a9c((uint)this,1);
            FUN_80068a9c((uint)this,2);
            FUN_80068a9c((uint)this,4);
            FUN_80068a9c((uint)this,8);
          }
        }
      }
      dummiedProfFn_8017a59c(0xff);
    }
    else {
      puVar12[0x3cd] = puVar12[0x3cd] | 1;
    }
  }
LAB_8026aeb4:
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    dll_29E_func05
   
   Library: KioskDefault 0 0 */

void IMsnowbike_hitDetect(ObjInstance *this) { //8026AED0
  undefined *puVar1;
  Mtx44 MStack_9c;
  Mtx44 MStack_5c;
  float local_1c;
  float local_18;
  float local_14;
  
  puVar1 = this->state;
  if ((puVar1[0x3cd] & 0x20) == 0) {
    ObjPos_803963c0.rotation.x = -*(short *)(puVar1 + 0x3bc);
    ObjPos_803963c0.rotation.y = -*(short *)(puVar1 + 0x3be);
    ObjPos_803963c0.rotation.z = -*(short *)(puVar1 + 0x3c0);
    mtxRotateByVec3s(&MStack_5c,&ObjPos_803963c0.rotation);
    (this->vel).x = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
    (this->vel).y = prevOneOverTimeDelta * ((this->pos).pos.y - (this->oldPos).y);
    (this->vel).z = prevOneOverTimeDelta * ((this->pos).pos.z - (this->oldPos).z);
    local_1c = (this->vel).x * 0.9374999;
    local_18 = (this->vel).y * 0.9374999;
    local_14 = (this->vel).z * 0.9374999;
    multVectorByMatrix((double)local_1c,(double)local_18,(double)local_14,&MStack_5c,
                       (float *)(puVar1 + 0x2b8),(float *)(puVar1 + 700),(float *)(puVar1 + 0x2c0));
    FUN_8026cf1c((int)this,(int)puVar1,&MStack_9c,0,0,0);
    multVectorByMatrix(0.0,0.0,-10.0,&MStack_9c,(float *)(puVar1 + 0x3a8),(float *)(puVar1 + 0x3ac),
                       (float *)(puVar1 + 0x3b0));
  }
  return;
}


/* Library Function - Single Match
    dll_29E_func06
   
   Library: KioskDefault 0 0 */

void IMsnowbike_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8026B018
  bool bVar2;
  uint uVar1;
  char cVar3;
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  undefined *puVar4;
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  puVar4 = this->state;
  if (((puVar4[0x3cd] & 1) == 0) &&
     (((bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2 || (uVar1 = mainGetBit(0x6e), uVar1 == 0)) ||
      (uVar1 = mainGetBit(0x382), uVar1 != 0)))) {
    if (shouldRender == true) {
                    /* {@symbol 800dd420} */
      cVar3 = (**(code **)(*(int *)pDll_modgfx + 0x2c))(this);
      bVar2 = checkSomeDebugFlags_8017c4f8();
      if ((!bVar2) && ((puVar4[0x3cd] & 0x20) == 0)) {
        FUN_8026b640((int)this,(int)puVar4,(F3DEXcommand *)param2_00,param3_00,param4_00,param5_00);
      }
      objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
      objGetAttachPointWorldPos
                (this,0,(float *)(puVar4 + 900),(float *)(puVar4 + 0x388),(float *)(puVar4 + 0x38c),
                 FALSE);
      if (cVar3 != '\0') {
                    /* {@symbol 800dc300} */
        (**(code **)(*(int *)pDll_modgfx + 0x1c))(this,param2_00,param3_00,0,0,0,0);
      }
    }
    else if (puVar4[0x3ce] == '\x02') {
      *(float *)(puVar4 + 900) = (this->pos).pos.x;
      *(float *)(puVar4 + 0x388) = (this->pos).pos.y;
      *(float *)(puVar4 + 0x38c) = (this->pos).pos.z;
    }
    else if (shouldRender) {
      objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
      objGetAttachPointWorldPos
                (this,0,(float *)(puVar4 + 900),(float *)(puVar4 + 0x388),(float *)(puVar4 + 0x38c),
                 FALSE);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_29E_func07
   
   Library: KioskDefault 0 0 */

void IMsnowbike_free(ObjInstance *this,int param2) { //8026B1C8
  undefined *puVar1;
  
  puVar1 = this->state;
  if (*(int *)(puVar1 + 0x2f4) != 0) {
    DLL_free(*(LoadedDll **)(puVar1 + 0x2f4));
  }
  *(undefined4 *)(puVar1 + 0x2f4) = 0;
  if (*(int *)(puVar1 + 0x2f8) != 0) {
    DLL_free(*(LoadedDll **)(puVar1 + 0x2f8));
  }
  *(undefined4 *)(puVar1 + 0x2f8) = 0;
  if (DAT_80399ff0 != (LoadedDll *)0x0) {
    DLL_free(DAT_80399ff0);
  }
  DAT_80399ff0 = (LoadedDll *)0x0;
  Object_removePlayerObj(this,0xb);
  texFreeTexture(DAT_80399fe8);
  texFreeTexture(DAT_80399fec);
  DAT_80399fe8 = (Texture *)0x0;
  DAT_80399fec = (Texture *)0x0;
  return;
}


undefined4 IMsnowbike_func08(ObjInstance *this) { //8026B274
  return 3;
}


/* @description Get extra size for object (size of State struct) */

int IMsnowbike_getExtraSize(void) { //8026B27C
  return 0x3d4;
}


/* Library Function - Single Match
    dll_29E_func0A
   
   Library: KioskDefault 0 0 */

void IMsnowbike_setScale(ObjInstance *this,float scale) { //8026B284
  return;
}


undefined IMsnowbike_func0B(int param1) { //8026B2B4
  return *(undefined *)(*(int *)(param1 + 0xb8) + 0x3cb);
}


void IMsnowbike_modelMtxFn(ObjInstance *this,undefined4 *param2,vec3f *param3) { //8026B2D0
  undefined4 *in_r6;
  undefined *puVar1;
  
  puVar1 = this->state;
  *param2 = *(undefined4 *)(puVar1 + 900);
  param3->x = *(float *)(puVar1 + 0x388);
  *in_r6 = *(undefined4 *)(puVar1 + 0x38c);
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    bike_func0D
    dll_29E_func0D
   
   Library: KioskDefault 0 0 */

undefined4 IMsnowbike_render2(ObjInstance *this) { //8026B300
  undefined4 uVar1;
  N64Button32 NVar2;
  
  if ((this->state[0x3cd] & 8) == 0) {
    NVar2 = n64GetEnabledButtonsPressed(0);
    if ((NVar2 & N64_BUTTON_B) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


undefined4 IMsnowbike_func0E(void) { //8026B360
  return 2;
}


void IMsnowbike_func0F(int param1,undefined4 *param2,undefined4 *param3,undefined4 *param4) { //8026B368
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = *(undefined4 *)(iVar1 + 0x3a8);
  *param3 = *(undefined4 *)(iVar1 + 0x3ac);
  *param4 = *(undefined4 *)(iVar1 + 0x3b0);
  return;
}


int IMsnowbike_func10(int param1) { //8026B398
  return (int)*(char *)(*(int *)(param1 + 0xb8) + 0x3ce);
}


/* Library Function - Single Match
    dll_29E_func11
   
   Library: KioskDefault 0 0 */

void IMsnowbike_func11(int param1,int param2) { //8026B3B8
  *(char *)(*(int *)(param1 + 0xb8) + 0x3ce) = (char)param2;
  if (param2 == 2) {
    mainSetBits(0x42d,1);
  }
  return;
}


/* Library Function - Single Match
    dll_29E_func12
   
   Library: KioskDefault 0 0 */

void IMsnowbike_func12(int param1,float *param2,uint *param3) { //8026B408
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar1 + 0x3b8) ^ 0x80000000) -
                   4503601774854144.0) / 2500.0;
  if (*param2 <= 1.0) {
    if (*param2 < -1.0) {
      *param2 = -1.0;
    }
  }
  else {
    *param2 = 1.0;
  }
  *param3 = 1U - (~(int)*(short *)(iVar1 + 0x3b8) >> 0x1f) & 1;
  return;
}


/* Library Function - Single Match
    dll_29E_func13
   
   Library: KioskDefault 0 0 */

double IMsnowbike_func13(int param1,float *param2) { //8026B4A4
  int iVar1;
  double dVar2;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = 5.0;
  dVar2 = sqrt((double)(*(float *)(iVar1 + 0x2c0) * *(float *)(iVar1 + 0x2c0) +
                       *(float *)(iVar1 + 0x2b8) * *(float *)(iVar1 + 0x2b8) +
                       *(float *)(iVar1 + 700) * *(float *)(iVar1 + 700)));
  dVar2 = (double)(float)(dVar2 * 0.2000000029802322);
  if (1.0 < dVar2) {
    dVar2 = 1.0;
  }
  return dVar2;
}


int IMsnowbike_func14(int param1) { //8026B538
  return (int)*(char *)(*(int *)(param1 + 0xb8) + 0x3cf);
}


/* Library Function - Single Match
    dll_29E_func15
   
   Library: KioskDefault 0 0 */

void IMsnowbike_func15(short *param1) { //8026B558
  ObjDef *pOVar1;
  int id;
  short *psVar2;
  
  psVar2 = *(short **)(param1 + 0x5c);
  if (param1[0x23] == 0x16f) {
    id = 0xcb3;
  }
  else {
    id = 0xca3;
  }
  pOVar1 = mapObjFindFn_800a8cb4(id,(int *)0x0,(int *)0x0,(int *)0x0,(uint *)0x0);
  if (pOVar1 != (ObjDef *)0x0) {
    *(float *)(param1 + 6) = (pOVar1->pos).x;
    *(float *)(param1 + 8) = (pOVar1->pos).y;
    *(float *)(param1 + 10) = (pOVar1->pos).z;
    *param1 = (ushort)*(byte *)((int)&pOVar1[1].pos.z + 1) << 8;
    FUN_8026d688((int)param1,(int)psVar2);
                    /* {@symbol 80118c60} */
    (**(code **)(*(int *)pDll_Dummy04 + 0x10))(param1,psVar2 + 0xc,0);
    *(undefined4 *)(psVar2 + 6) = *(undefined4 *)(param1 + 6);
    *(undefined4 *)(psVar2 + 8) = *(undefined4 *)(param1 + 8);
    *(undefined4 *)(psVar2 + 10) = *(undefined4 *)(param1 + 10);
    *psVar2 = *param1;
  }
  return;
}


void IMsnowbike_func16(void) { //8026B63C
  return;
}


void IMsnowbike_func17(void) { //8026DE18
  return;
}

