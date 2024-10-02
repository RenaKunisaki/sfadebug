
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CRsnowbike_initialise(undefined4 param) { //80276F88
  return;
}


/* @description Called when DLL is unloaded */

void CRsnowbike_release(void) { //80276F8C
  return;
}


/* Library Function - Single Match
    bike_func03
   
   Library: KioskDefault 0 0 */

void CRsnowbike_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80276F90
  short sVar1;
  uint uVar2;
  ObjDef *pOVar3;
  undefined *param1;
  undefined4 local_24 [2];
  
  local_24[0] = 0x5050505;
  pOVar3 = this->def;
  param1 = this->state;
  memclr(param1,1000);
  *(ushort *)(param1 + 0x3d0) = (ushort)*(byte *)&objDef[1].objType << 8;
  *(undefined4 *)(param1 + 0x2f4) = 0;
  *(undefined4 *)(param1 + 0x2f8) = 0;
  (this->pos).rotation.x = *(short *)(param1 + 0x3d0);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80279f54;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(param1 + 0x4c,0,0x1040007,1);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(param1 + 0x4c,4,&DAT_8031cd1c,&DAT_8031cd4c,local_24);
  if (*(char *)((int)&objDef[1].objType + 1) == '\0') {
    param1[0x3de] = 5;
  }
  else {
    param1[0x3de] = 3;
  }
  FUN_8027a5e4((int)this,(int)param1);
  FUN_80278b50(this,(int)(param1 + 0x2ac));
  Object_ObjAnimSetMove(0.0,this,0,0);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x4a10;
  }
  if (*(char *)((int)&objDef[1].objType + 1) != '\0') {
    param1[0x3df] = param1[0x3df] | 0x20;
  }
  *(undefined4 *)(param1 + 0x28) = 0xffffffff;
  *(undefined4 *)(param1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param1 + 0x30) = 0xffffffff;
  param1[0x48] = objDef[1].loadFlags;
  param1[0x49] = objDef[1].mapStates2;
  *(float *)(param1 + 0xc) = (this->pos).pos.x;
  *(float *)(param1 + 0x10) = (this->pos).pos.y;
  *(float *)(param1 + 0x14) = (this->pos).pos.z;
  if (*(char *)&pOVar3[1].pos.x == '\0') {
    *(undefined *)&pOVar3[1].pos.x = 0x1c;
  }
  Object_objAddObjectType(this,0xb);
  DAT_8039a018 = textureLoadAsset(0x186);
  DAT_8039a01c = textureLoadAsset(0x89);
  DAT_8039a020 = textureLoadAsset(0x3c);
  sVar1._0_1_ = pOVar3[1].bound;
  sVar1._1_1_ = pOVar3[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  param1[0x3df] = param1[0x3df] | uVar2 != 0;
  *(uint *)(param1 + 0x2fc) = (int)&PTR_DAT_8031ccf8 + (uint)objDef[1].loadFlags * 6;
  return;
}


/* Library Function - Single Match
    bike_func04
   
   Library: KioskDefault 0 0 */

void CRsnowbike_update(ObjInstance *this) { //802771A8
  int iVar1;
  char cVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  float fVar7;
  uint uVar8;
  ObjInstance *param1;
  byte bVar10;
  int iVar9;
  undefined uVar11;
  ObjDef *pOVar12;
  undefined *puVar13;
  double dVar14;
  float local_c0;
  float fStack_bc;
  float local_b8;
  Mtx44 MStack_b4;
  float local_74;
  double local_70;
  undefined4 local_68;
  uint uStack_64;
  double local_60;
  double local_58;
  undefined4 local_50;
  uint uStack_4c;
  double local_48;
  
  _savefpr_29();
  pOVar12 = this->def;
  puVar13 = this->state;
  local_74 = 0.0;
  if ((puVar13[0x3df] & 1) == 0) {
    sVar4._0_1_ = pOVar12[1].bound;
    sVar4._1_1_ = pOVar12[1].cullDist;
    uVar8 = mainGetBit((int)sVar4);
    if (uVar8 == 0) {
      dVar14 = (double)dummiedProfFn_8017a59c(&DAT_808080ff);
      param1 = Object_objGetMain();
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      *(float *)(puVar13 + 0x3a0) = (this->pos).pos.x;
      *(float *)(puVar13 + 0x3a4) = (this->pos).pos.y;
      *(float *)(puVar13 + 0x3a8) = (this->pos).pos.z;
      if (((puVar13[0x3df] & 0x10) != 0) &&
         (puVar13[0x3df] = puVar13[0x3df] & 0xef, (puVar13[0x3df] & 0x20) == 0)) {
        *(float *)(puVar13 + 0x2b8) = 0.0;
        *(float *)(puVar13 + 700) = 0.0;
        *(float *)(puVar13 + 0x2c0) = -2.0;
        *(undefined2 *)(puVar13 + 0x3cc) = 0;
        *(undefined2 *)(puVar13 + 0x3ce) = 0;
        puVar13[0x3e2] = 0;
        *(undefined2 *)(puVar13 + 0x3d6) = 0;
        *(short *)(puVar13 + 0x3d0) = (this->pos).rotation.x;
        *(short *)(puVar13 + 0x3d2) = (this->pos).rotation.y;
        *(short *)(puVar13 + 0x3d4) = (this->pos).rotation.z;
        dVar14 = (double)FUN_8027a5e4((int)this,(int)puVar13);
      }
      cVar2 = puVar13[0x3e0];
      if (cVar2 != '\x01') {
        if (cVar2 < '\x01') {
          if (-1 < cVar2) {
            if ((puVar13[0x3df] & 0x20) == 0) {
              this->hitstate->field21_0x5b = 0;
              this->hitstate->sizeX1 = 0;
              puVar13[0x3dd] = 0;
              this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
              sVar5._0_1_ = pOVar12[1].allocatedSize;
              sVar5._1_1_ = pOVar12[1].mapStates1;
              if ((sVar5 == -1) ||
                 (sVar6._0_1_ = pOVar12[1].allocatedSize, sVar6._1_1_ = pOVar12[1].mapStates1,
                 uVar8 = mainGetBit((int)sVar6), uVar8 != 0)) {
                this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
              }
              else {
                this->flags_0xaf = this->flags_0xaf | PlayerIsDisguised;
              }
              if ((param1 != (ObjInstance *)0x0) && (objDistObj2Obj(param1,this), dVar14 < 40.0)) {
                puVar13[0x3dd] = 1;
                FUN_80279da0((int)this,(int)puVar13,&MStack_b4,0,1,1);
                multVectorByMatrix((double)DAT_8031cde8,(double)DAT_8031cdec,(double)DAT_8031cdf0,
                                   &MStack_b4,&local_b8,&fStack_bc,&local_c0);
                fVar3 = (param1->pos).pos.x - local_b8;
                fVar7 = (param1->pos).pos.z - local_c0;
                if (100.0 <= fVar3 * fVar3 + fVar7 * fVar7) {
                  multVectorByMatrix((double)DAT_8031cdf4,(double)DAT_8031cdf8,(double)DAT_8031cdfc,
                                     &MStack_b4,&local_b8,&fStack_bc,&local_c0);
                  local_b8 = (param1->pos).pos.x - local_b8;
                  local_c0 = (param1->pos).pos.z - local_c0;
                  if (local_b8 * local_b8 + local_c0 * local_c0 < 100.0) {
                    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
                    puVar13[0x3dd] = 1;
                  }
                }
                else {
                  this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
                  puVar13[0x3dd] = 2;
                }
              }
            }
            FUN_80068a9c((uint)this,2);
            FUN_80068a9c((uint)this,4);
            FUN_80068a9c((uint)this,8);
            if (*(int *)(puVar13 + 0x2f4) != 0) {
              DLL_free(*(LoadedDll **)(puVar13 + 0x2f4));
              *(undefined4 *)(puVar13 + 0x2f4) = 0;
            }
            if (*(int *)(puVar13 + 0x2f8) != 0) {
              DLL_free(*(LoadedDll **)(puVar13 + 0x2f8));
              *(undefined4 *)(puVar13 + 0x2f8) = 0;
            }
            puVar13[0x3df] = puVar13[0x3df] & 0xf7;
          }
        }
        else if (cVar2 < '\x03') {
          if ((puVar13[0x3df] & 8) == 0) {
            *(undefined4 *)(puVar13 + 0x28) = 0xffffffff;
            *(undefined4 *)(puVar13 + 0x2c) = 0xffffffff;
            *(undefined4 *)(puVar13 + 0x30) = 0xffffffff;
            *(undefined4 *)(puVar13 + 0x34) = 0;
            uVar8 = mainGetBit((int)**(short **)(puVar13 + 0x2fc));
            if (uVar8 == 0) {
              bVar10 = 0;
            }
            else {
              bVar10 = 8;
            }
            puVar13[0x3df] = puVar13[0x3df] | bVar10;
            if ((puVar13[0x3df] & 8) != 0) {
              if ((puVar13[0x3df] & 0x20) == 0) {
                    /* {@symbol 80118c60} */
                (**(code **)(*(int *)pDll_Dummy04 + 0x10))(this,puVar13 + 0x18,pOVar12[1].loadFlags)
                ;
              }
              else {
                func15((short *)this);
              }
                    /* {@symbol 801197ec} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x28))(puVar13 + 0x18);
            }
          }
          else {
            uVar8 = mainGetBit((int)*(short *)(*(int *)(puVar13 + 0x2fc) + 2));
            if (uVar8 != 0) {
              puVar13[0x3df] = puVar13[0x3df] & 0xf7;
            }
          }
          FUN_80279e6c((int)this,(int)puVar13);
          if ((puVar13[0x3df] & 0x20) == 0) {
            this->hitstate->field21_0x5b = 10;
            this->hitstate->sizeX1 = 10;
          }
          else {
            if ((puVar13[0x3df] & 8) == 0) goto LAB_80277dd8;
            iVar9 = getBlockIdxAtCoords((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                                        (double)(this->pos).pos.z);
            if (iVar9 < 0) {
              iVar9 = FUN_80276edc((double)(timeDelta * 2.8),(int)this,(int)puVar13);
                    /* {@symbol 8011935c} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x14))(this,puVar13 + 0x18);
                    /* {@symbol 801197c0} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x2c))(puVar13 + 0x18);
              if (iVar9 == 0) {
                iVar9 = getAngle();
                (this->pos).rotation.x = (short)iVar9;
                (this->pos).pos.x = *(float *)(puVar13 + 0xc);
                (this->pos).pos.y = *(float *)(puVar13 + 0x10);
                (this->pos).pos.z = *(float *)(puVar13 + 0x14);
                puVar13[0x3df] = puVar13[0x3df] | 2;
              }
              else {
                printf(" FInished Is SEt for Some Reason ");
              }
              goto LAB_80277dd8;
            }
            if ((puVar13[0x3df] & 2) != 0) {
              local_48 = (double)CONCAT44(0x43300000,(uint)*(byte *)&pOVar12[1].pos.x);
              iVar9 = FUN_80276edc((double)(timeDelta * 2.8),(int)this,(int)puVar13);
                    /* {@symbol 8011935c} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x14))(this,puVar13 + 0x18);
                    /* {@symbol 801197c0} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x2c))(puVar13 + 0x18);
              if (iVar9 == 0) {
                iVar9 = getAngle();
                (this->pos).rotation.x = (short)iVar9;
                (this->pos).pos.x = *(float *)(puVar13 + 0xc);
                (this->pos).pos.y = *(float *)(puVar13 + 0x10);
                (this->pos).pos.z = *(float *)(puVar13 + 0x14);
                *(float *)(puVar13 + 0x2b8) = 0.0;
                *(float *)(puVar13 + 700) = 0.0;
                *(float *)(puVar13 + 0x2c0) = -2.0;
                *(undefined2 *)(puVar13 + 0x3cc) = 0;
                *(undefined2 *)(puVar13 + 0x3ce) = 0;
                puVar13[0x3e2] = 0;
                *(undefined2 *)(puVar13 + 0x3d6) = 0;
                *(short *)(puVar13 + 0x3d0) = (this->pos).rotation.x;
                *(short *)(puVar13 + 0x3d2) = (this->pos).rotation.y;
                *(short *)(puVar13 + 0x3d4) = (this->pos).rotation.z;
                FUN_8027a5e4((int)this,(int)puVar13);
                FUN_800ba478((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                             (double)(this->pos).pos.z,(int)this,&local_74,0);
                (this->pos).pos.y = (this->pos).pos.y - local_74;
                puVar13[0x3df] = puVar13[0x3df] & 0xfd;
              }
              else {
                printf(" FInished Is SEt for Some Reason ");
              }
              goto LAB_80277dd8;
            }
            iVar9 = FUN_8027a3e4((ushort *)this,puVar13,(int)puVar13,(int)(puVar13 + 0x2e0));
            if (iVar9 != 0) goto LAB_80277dd8;
          }
          if ((puVar13[0x3df] & 0x20) == 0) {
            if ((puVar13[0x3df] & 8) != 0) {
                    /* {@symbol 8011935c} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x14))(this,puVar13 + 0x18);
                    /* {@symbol 801197c0} */
              (**(code **)(*(int *)pDll_Dummy04 + 0x2c))(puVar13 + 0x18);
                    /* {@symbol 80119974} */
              uVar11 = (**(code **)(*(int *)pDll_Dummy04 + 0x34))(puVar13 + 0x18);
              puVar13[0x3e1] = uVar11;
            }
            for (iVar9 = 0; iVar9 < (int)(uint)framesThisStep; iVar9 = iVar9 + 1) {
              FUN_80279d50(this,(int)(puVar13 + 0x2e0),0);
              uVar8 = countLeadingZeros((framesThisStep - 1) - iVar9);
              FUN_80278bcc((double)timeDelta,this,(int)puVar13,(float *)(puVar13 + 0x2ac),uVar8 >> 5
                          );
              local_48 = (double)CONCAT44(0x43300000,-(int)(char)puVar13[0x2ee] ^ 0x80000000);
              uStack_4c = (int)*(short *)(puVar13 + 0x3cc) ^ 0x80000000;
              local_50 = 0x43300000;
              iVar1 = (int)((float)(local_48 - 4503601774854144.0) * 60.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0));
              local_58 = (double)(longlong)iVar1;
              *(short *)(puVar13 + 0x3cc) = *(short *)(puVar13 + 0x3cc) + ((short)iVar1 >> 4);
              local_60 = (double)CONCAT44(0x43300000,-(int)(char)puVar13[0x2ee] ^ 0x80000000);
              uStack_64 = (int)*(short *)(puVar13 + 0x3ce) ^ 0x80000000;
              local_68 = 0x43300000;
              iVar1 = (int)((float)(local_60 - 4503601774854144.0) * 105.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0));
              local_70 = (double)(longlong)iVar1;
              *(short *)(puVar13 + 0x3ce) = *(short *)(puVar13 + 0x3ce) + ((short)iVar1 >> 4);
              (this->pos).rotation.x = *(short *)(puVar13 + 0x3d0) + *(short *)(puVar13 + 0x3cc);
              (this->pos).rotation.z = *(short *)(puVar13 + 0x3d4) + *(short *)(puVar13 + 0x3ce);
            }
            if (*(int *)(puVar13 + 0x3b8) < 0) {
              if (0.1 < *(float *)(puVar13 + 0x3bc)) {
                iVar9 = randInt(0,10);
                if (iVar9 == 0) {
                  audioStartSfx((int **)0x0,0x1da,0x7f,0x40,"CRsnowbike.c",0x241);
                }
                *(float *)(puVar13 + 0x3bc) = *(float *)(puVar13 + 0x3bc) * 0.95;
                *(float *)(puVar13 + 0x3c0) = *(float *)(puVar13 + 0x3c0) * 0.95;
                *(float *)(puVar13 + 0x3c4) = *(float *)(puVar13 + 0x3c4) * 0.95;
                if (*(float *)(puVar13 + 0x3bc) < 0.1) {
                    /* {@symbol 80173318} */
                  (**(code **)(*pdll_camcontrol + 0x5c))();
                    /* {@symbol 800d022c} */
                  (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
                  *(float *)(puVar13 + 0x3bc) = 0.01;
                  *(float *)(puVar13 + 0x3c0) = 0.01;
                  *(float *)(puVar13 + 0x3c4) = 0.01;
                }
              }
            }
            else {
              dVar14 = sqrt((double)(*(float *)(puVar13 + 0x2c0) * *(float *)(puVar13 + 0x2c0) +
                                    *(float *)(puVar13 + 0x2b8) * *(float *)(puVar13 + 0x2b8) +
                                    *(float *)(puVar13 + 700) * *(float *)(puVar13 + 700)));
              iVar9 = (int)((float)((double)timeDelta * dVar14) * 1.5);
              local_70 = (double)(longlong)iVar9;
              *(uint *)(puVar13 + 0x3b8) =
                   *(int *)(puVar13 + 0x3b8) - ((uint)framesThisStep + iVar9);
                    /* {@symbol 8017305c} */
              (**(code **)(*pdll_camcontrol + 0x58))(*(undefined4 *)(puVar13 + 0x3b8));
            }
          }
          else {
            for (iVar9 = 0; iVar9 < (int)(uint)framesThisStep; iVar9 = iVar9 + 1) {
              uVar8 = countLeadingZeros((framesThisStep - 1) - iVar9);
              FUN_80279650((double)timeDelta,this,(int)puVar13,(float *)(puVar13 + 0x2ac),uVar8 >> 5
                          );
              local_70 = (double)CONCAT44(0x43300000,-(int)(char)puVar13[0x2ee] ^ 0x80000000);
              uStack_64 = (int)*(short *)(puVar13 + 0x3cc) ^ 0x80000000;
              local_68 = 0x43300000;
              iVar1 = (int)((float)(local_70 - 4503601774854144.0) * 60.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0));
              local_60 = (double)(longlong)iVar1;
              *(short *)(puVar13 + 0x3cc) = *(short *)(puVar13 + 0x3cc) + ((short)iVar1 >> 4);
              local_58 = (double)CONCAT44(0x43300000,-(int)(char)puVar13[0x2ee] ^ 0x80000000);
              uStack_4c = (int)*(short *)(puVar13 + 0x3ce) ^ 0x80000000;
              local_50 = 0x43300000;
              iVar1 = (int)((float)(local_58 - 4503601774854144.0) * 105.0 -
                           (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0));
              local_48 = (double)(longlong)iVar1;
              *(short *)(puVar13 + 0x3ce) = *(short *)(puVar13 + 0x3ce) + ((short)iVar1 >> 4);
              (this->pos).rotation.x = *(short *)(puVar13 + 0x3d0) + *(short *)(puVar13 + 0x3cc);
              (this->pos).rotation.z = *(short *)(puVar13 + 0x3d4) + *(short *)(puVar13 + 0x3ce);
            }
          }
          if ((puVar13[0x3df] & 0x20) == 0) {
            FUN_8027a6e0((double)*(float *)(puVar13 + 0x2c0),(int *)this,(int)puVar13,
                         (int)(char)puVar13[0x2ef],puVar13 + 0x2f0,7);
          }
          else {
            FUN_80068a9c((uint)this,1);
            FUN_80068a9c((uint)this,2);
            FUN_80068a9c((uint)this,4);
            FUN_80068a9c((uint)this,8);
          }
        }
      }
      if (((puVar13[0x3df] & 0x20) == 0) && (puVar13[0x3e0] == '\x02')) {
        if (*(float *)(puVar13 + 0x39c) < 0.0) {
          fVar3 = -*(float *)(puVar13 + 0x39c);
        }
        else {
          fVar3 = *(float *)(puVar13 + 0x39c);
        }
        if (2.0 < fVar3) {
          *(undefined *)((int)&this->hitstate->sizeX2 + 1) = 0x15;
          *(undefined *)&this->hitstate->flags_0x60 = 1;
          this->hitstate->flags = this->hitstate->flags | 1;
          (this->hitstate->field12_0x3c).y = 2.242078e-44;
          this->hitstate->flags = this->hitstate->flags | 4;
          (this->pos).flags = (this->pos).flags & ~Invisible;
        }
      }
      dummiedProfFn_8017a59c(0xff);
    }
    else {
      puVar13[0x3df] = puVar13[0x3df] | 1;
    }
  }
LAB_80277dd8:
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    bike_func05
   
   Library: KioskDefault 0 0 */

void CRsnowbike_hitDetect(ObjInstance *this) { //80277DF4
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  Mtx44 MStack_ac;
  Mtx44 MStack_6c;
  float local_2c;
  float local_28;
  float local_24;
  
  puVar4 = this->state;
  if (this->hitstate->field13_0x48 != 0) {
    iVar3 = this->hitstate->field13_0x48;
    printf(" HIT OBJECT %i ",(int)*(short *)(iVar3 + 0x46));
    if (*(short *)(iVar3 + 0x46) != 0x389) {
      if (*(short *)(iVar3 + 0x46) != 0x38a) goto LAB_80277f40;
    }
    enableCameraYOffset();
    FUN_8006ae50(1.0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x551,0,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x552,0,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x554,0,4,0xffffffff,0);
    uVar2 = 0x32 / framesThisStep;
    while( true ) {
      bVar1 = uVar2 == 0;
      uVar2 = uVar2 - 1;
      if (bVar1) break;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x553,0,2,0xffffffff,0);
    }
    puVar4[0x3dc] = 5;
    *(float *)(puVar4 + 900) = 0.2;
  }
LAB_80277f40:
  if ((puVar4[0x3df] & 0x20) == 0) {
    vec3s_803964b0.x = -*(short *)(puVar4 + 0x3d0);
    vec3s_803964b0.y = -*(short *)(puVar4 + 0x3d2);
    vec3s_803964b0.z = -*(short *)(puVar4 + 0x3d4);
    mtxRotateByVec3s(&MStack_6c,&vec3s_803964b0);
    (this->vel).x = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
    (this->vel).y = prevOneOverTimeDelta * ((this->pos).pos.y - (this->oldPos).y);
    (this->vel).z = prevOneOverTimeDelta * ((this->pos).pos.z - (this->oldPos).z);
    local_2c = (this->vel).x * 0.9374999;
    local_28 = (this->vel).y * 0.9374999;
    local_24 = (this->vel).z * 0.9374999;
    multVectorByMatrix((double)local_2c,(double)local_28,(double)local_24,&MStack_6c,
                       (float *)(puVar4 + 0x2b8),(float *)(puVar4 + 700),(float *)(puVar4 + 0x2c0));
    FUN_80279da0((int)this,(int)puVar4,&MStack_ac,0,0,0);
    multVectorByMatrix(0.0,0.0,-10.0,&MStack_ac,(float *)(puVar4 + 0x3ac),(float *)(puVar4 + 0x3b0),
                       (float *)(puVar4 + 0x3b4));
  }
  return;
}


/* Library Function - Single Match
    bike_func06
   
   Library: KioskDefault 0 0 */

void CRsnowbike_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80278064
  char cVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  undefined *puVar3;
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  puVar3 = this->state;
  if ((puVar3[0x3df] & 1) == 0) {
    if (shouldRender == true) {
                    /* {@symbol 800dd420} */
      cVar1 = (**(code **)(*(int *)pDll_modgfx + 0x2c))(this);
      bVar2 = checkSomeDebugFlags_8017c4f8();
      if ((!bVar2) && ((puVar3[0x3df] & 0x20) == 0)) {
        FUN_80278790((int)this,(int)puVar3,(F3DEXcommand *)param2_00,param3_00,param4_00,param5_00);
      }
      objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
      objGetAttachPointWorldPos
                (this,0,(float *)(puVar3 + 0x388),(float *)(puVar3 + 0x38c),
                 (float *)(puVar3 + 0x390),FALSE);
      if (cVar1 != '\0') {
                    /* {@symbol 800dc300} */
        (**(code **)(*(int *)pDll_modgfx + 0x1c))(this,param2_00,param3_00,0,0,0,0);
      }
    }
    else if (puVar3[0x3e0] == '\x02') {
      *(float *)(puVar3 + 0x388) = (this->pos).pos.x;
      *(float *)(puVar3 + 0x38c) = (this->pos).pos.y;
      *(float *)(puVar3 + 0x390) = (this->pos).pos.z;
    }
    else if (shouldRender) {
      objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
      objGetAttachPointWorldPos
                (this,0,(float *)(puVar3 + 0x388),(float *)(puVar3 + 0x38c),
                 (float *)(puVar3 + 0x390),FALSE);
    }
  }
  return;
}


/* Library Function - Single Match
    bike_func07
   
   Library: KioskDefault 0 0 */

void CRsnowbike_free(ObjInstance *this,int param2) { //802781E8
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
  Object_removePlayerObj(this,0xb);
  if ((puVar1[0x3df] & 0x20) == 0) {
                    /* {@symbol 80173318} */
    (**(code **)(*pdll_camcontrol + 0x5c))();
  }
  texFreeTexture(DAT_8039a018);
  texFreeTexture(DAT_8039a01c);
  texFreeTexture(DAT_8039a020);
  DAT_8039a018 = (Texture *)0x0;
  DAT_8039a01c = (Texture *)0x0;
  DAT_8039a020 = (Texture *)0x0;
  return;
}


undefined4 CRsnowbike_func08(ObjInstance *this) { //802782A8
  return 3;
}


/* @description Get extra size for object (size of State struct) */

int CRsnowbike_getExtraSize(void) { //802782B0
  return 1000;
}


/* Library Function - Single Match
    bike_mount
   
   Library: KioskDefault 0 0 */

void CRsnowbike_mount(ObjInstance *this,float scale) { //802782B8
  short sVar1;
  short sVar2;
  uint uVar3;
  ObjDef *pOVar4;
  undefined *puVar5;
  
  pOVar4 = this->def;
  puVar5 = this->state;
  if (((puVar5[0x3df] & 0x20) == 0) &&
     (((sVar1._0_1_ = pOVar4[1].allocatedSize, sVar1._1_1_ = pOVar4[1].mapStates1, sVar1 == -1 ||
       (sVar2._0_1_ = pOVar4[1].allocatedSize, sVar2._1_1_ = pOVar4[1].mapStates1,
       uVar3 = mainGetBit((int)sVar2), uVar3 != 0)) && (puVar5[0x3dd] != '\0')))) {
    printf(" Bike Can Mount %i ",(uint)(byte)puVar5[0x3dd]);
  }
  return;
}


undefined CRsnowbike_func0B(int param1) { //80278344
  return *(undefined *)(*(int *)(param1 + 0xb8) + 0x3dd);
}


void CRsnowbike_modelMtxFn(ObjInstance *this,undefined4 *param2,vec3f *param3) { //80278360
  undefined4 *in_r6;
  undefined *puVar1;
  
  puVar1 = this->state;
  *param2 = *(undefined4 *)(puVar1 + 0x388);
  param3->x = *(float *)(puVar1 + 0x38c);
  *in_r6 = *(undefined4 *)(puVar1 + 0x390);
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    bike_func0D
    dll_29E_func0D
   
   Library: KioskDefault 0 0 */

undefined4 CRsnowbike_render2(ObjInstance *this) { //80278390
  undefined4 uVar1;
  N64Button32 NVar2;
  
  if ((this->state[0x3df] & 8) == 0) {
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


undefined4 CRsnowbike_func0E(void) { //802783F0
  return 2;
}


void CRsnowbike_func0F(int param1,undefined4 *param2,undefined4 *param3,undefined4 *param4) { //802783F8
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = *(undefined4 *)(iVar1 + 0x3ac);
  *param3 = *(undefined4 *)(iVar1 + 0x3b0);
  *param4 = *(undefined4 *)(iVar1 + 0x3b4);
  return;
}


int CRsnowbike_func10(int param1) { //80278428
  return (int)*(char *)(*(int *)(param1 + 0xb8) + 0x3e0);
}


/* Library Function - Single Match
    bike_func11
   
   Library: KioskDefault 0 0 */

void CRsnowbike_func11(int param1,int param2) { //80278448
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(char *)(iVar1 + 0x3e0) = (char)param2;
  if ((param2 == 2) && ((*(byte *)(iVar1 + 0x3df) & 0x20) == 0)) {
    *(undefined **)(iVar1 + 0x3b8) = &DAT_00003a98;
    *(float *)(iVar1 + 0x3bc) = 2.0;
    *(float *)(iVar1 + 0x3c0) = 4.0;
    *(float *)(iVar1 + 0x3c4) = 4.6;
                    /* {@symbol 80172e94} */
    (**(code **)(*pdll_camcontrol + 0x54))(0,&DAT_00004e20,0x569,0x56a,1);
                    /* {@symbol 801733e8} */
    (**(code **)(*pdll_camcontrol + 100))(0x4010000000000000);
  }
  return;
}


/* Library Function - Single Match
    bike_func12
   
   Library: KioskDefault 0 0 */

void CRsnowbike_func12(int param1,float *param2,uint *param3) { //802784F8
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar1 + 0x3cc) ^ 0x80000000) -
                   4503601774854144.0) / 2500.0;
  if (*param2 <= 1.0) {
    if (*param2 < -1.0) {
      *param2 = -1.0;
    }
  }
  else {
    *param2 = 1.0;
  }
  *param3 = 1U - (~(int)*(short *)(iVar1 + 0x3cc) >> 0x1f) & 1;
  return;
}


/* Library Function - Single Match
    bike_func13
   
   Library: KioskDefault 0 0 */

double CRsnowbike_func13(int param1,float *param2) { //80278594
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


int CRsnowbike_func14(int param1) { //80278628
  return (int)*(char *)(*(int *)(param1 + 0xb8) + 0x3e1);
}


/* Library Function - Single Match
    bike_func15
   
   Library: KioskDefault 0 0 */

void CRsnowbike_func15(short *param1) { //80278648
  short sVar1;
  ObjDef *pOVar2;
  undefined *param1_00;
  int iVar3;
  short *psVar4;
  
  iVar3 = *(int *)(param1 + 0x26);
  psVar4 = *(short **)(param1 + 0x5c);
  printf("tracks %d",(uint)*(byte *)(iVar3 + 0x1c));
  sVar1 = param1[0x23];
  if (sVar1 == 0x38e) {
    param1_00 = (&PTR_DAT_8031cd08)[(uint)*(byte *)(iVar3 + 0x1c) * 3];
  }
  else if ((sVar1 < 0x38e) || (sVar1 != 0x4d4)) {
    param1_00 = (&PTR_DAT_8031cd04)[(uint)*(byte *)(iVar3 + 0x1c) * 3];
  }
  else {
    param1_00 = (&PTR_DAT_8031cd0c)[(uint)*(byte *)(iVar3 + 0x1c) * 3];
  }
  printf("ident %d",(int)param1_00);
  pOVar2 = mapObjFindFn_800a8cb4((int)param1_00,(int *)0x0,(int *)0x0,(int *)0x0,(uint *)0x0);
  if (pOVar2 != (ObjDef *)0x0) {
    *(float *)(param1 + 6) = (pOVar2->pos).x;
    *(float *)(param1 + 8) = (pOVar2->pos).y;
    *(float *)(param1 + 10) = (pOVar2->pos).z;
    *param1 = (ushort)*(byte *)((int)&pOVar2[1].pos.z + 1) << 8;
    FUN_8027a5e4((int)param1,(int)psVar4);
                    /* {@symbol 80118c60} */
    (**(code **)(*(int *)pDll_Dummy04 + 0x10))(param1,psVar4 + 0xc,*(undefined *)(iVar3 + 0x1c));
    *(undefined4 *)(psVar4 + 6) = *(undefined4 *)(param1 + 6);
    *(undefined4 *)(psVar4 + 8) = *(undefined4 *)(param1 + 8);
    *(undefined4 *)(psVar4 + 10) = *(undefined4 *)(param1 + 10);
    *psVar4 = *param1;
  }
  return;
}


void CRsnowbike_func16(void) { //8027878C
  return;
}


void CRsnowbike_func17(void) { //8027AB48
  return;
}

