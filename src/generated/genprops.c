
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void genprops_initialise(undefined4 param) { //801F0290
  return;
}


/* @description Called when DLL is unloaded */

void genprops_release(void) { //801F0294
  return;
}


/* Library Function - Single Match
    dll_136_func03
   
   Library: KioskDefault 0 0 */

void genprops_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801F0298
  ObjDefEnum OVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  undefined *puVar10;
  
  OVar1 = objDef->objType;
  puVar10 = this->state;
  *(float *)(puVar10 + 0x2c) = 1.0;
  if (OVar1 == 0x221) {
LAB_801f0680:
    uVar8 = randInt(100,400);
    *(float *)(puVar10 + 0x18) =
         (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - 4503601774854144.0);
    uVar8 = randInt(100,400);
    *(float *)(puVar10 + 0x14) =
         (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - 4503601774854144.0);
    uVar8 = randInt(0,100);
    (this->vel).x =
         (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - 4503601774854144.0) * 0.04;
    uVar8 = randInt(0,100);
    (this->vel).z =
         (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - 4503601774854144.0) * 0.04;
    uVar8 = randInt(0,10);
    (this->pos).scale =
         (this->pos).scale *
         ((float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - 4503601774854144.0) * 0.01 + 0.3
         );
    *(undefined2 *)(puVar10 + 0x36) = 200;
    puVar10[0x3e] = 2;
    *(float *)(puVar10 + 0x2c) = 0.0;
    iVar9 = randInt(0,1);
    this->curModel = (byte)iVar9;
  }
  else {
    if ((short)OVar1 < 0x221) {
      if (OVar1 == SB_Lamp) {
        (this->pos).rotation.x = 0;
        (this->pos).rotation.y = 0;
        (this->pos).rotation.z = 0;
        (this->pos).scale = 1.0;
        this->field76_0xf4 = 0;
        this->flags_0xf8 = 0;
        *(float *)(puVar10 + 0x24) = 600.0;
        *(float *)(puVar10 + 0x1c) = 0.5;
        *(undefined2 *)(puVar10 + 0x32) = 0;
        iVar9 = randInt(1000,5000);
        *(short *)(puVar10 + 0x34) = (short)iVar9;
        puVar10[0x3f] = 1;
        this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
        return;
      }
      if ((short)OVar1 < 0x125) {
        if (OVar1 == 0xab) {
          *(float *)(puVar10 + 0x18) = 30.0;
          return;
        }
        if (0xaa < (short)OVar1) {
          if (OVar1 == DIM2IceFloe_010D) {
            this->hitstate = (HitState *)0x0;
            sVar7._0_1_ = objDef[1].allocatedSize;
            sVar7._1_1_ = objDef[1].mapStates1;
            if (sVar7 == 0) {
              *(undefined ***)(puVar10 + 0x44) = &PTR_DAT_80397c30;
              puVar10[0x40] = 4;
            }
            *(undefined2 *)(puVar10 + 0x48) = *(undefined2 *)&objDef[1].loadFlags;
            *(undefined2 *)(puVar10 + 0x3c) = *(undefined2 *)(puVar10 + 0x48);
            return;
          }
          if (0x10c < (short)OVar1) {
            return;
          }
          if (OVar1 != 0xd7) {
            return;
          }
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          (this->pos).scale = 1.0;
          puVar10[0x3e] = 0;
          *(float *)(puVar10 + 4) = (objDef->pos).x;
          *(float *)(puVar10 + 8) = (objDef->pos).y;
          *(float *)(puVar10 + 0xc) = (objDef->pos).z;
          *(float *)(puVar10 + 0x18) = 0.0;
          *(float *)(puVar10 + 0x14) = 0.0;
          *(float *)(puVar10 + 0x28) = 0.0;
          *(float *)(puVar10 + 0x20) = 0.0;
          *(float *)(puVar10 + 0x24) = 0.0;
          *(float *)(puVar10 + 0x1c) = 0.0;
          this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
          return;
        }
        if (OVar1 == CCqueen) {
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          (this->pos).rotation.y = *(short *)&objDef[1].allocatedSize;
          (this->pos).rotation.z = *(short *)&objDef[1].loadFlags;
          (this->pos).scale = 0.5;
          this->field76_0xf4 = 0;
          this->flags_0xf8 = 0;
          this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
          return;
        }
        if ((short)OVar1 < 0x86) {
          if ((short)OVar1 < 0x85) {
            return;
          }
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          (this->pos).rotation.y = *(short *)&objDef[1].allocatedSize;
          (this->pos).rotation.z = *(short *)&objDef[1].loadFlags;
          (this->pos).scale = 0.05;
          this->field76_0xf4 = 100;
          this->flags_0xf8 = 0;
          this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
          return;
        }
        if (OVar1 != SB_Galleon) {
          return;
        }
        (this->pos).rotation.x = 0;
        (this->pos).rotation.y = 0;
        sVar5._0_1_ = objDef[1].loadFlags;
        sVar5._1_1_ = objDef[1].mapStates2;
        if (sVar5 < 1000) {
          (this->pos).scale = 0.2;
        }
        else {
          sVar6._0_1_ = objDef[1].loadFlags;
          sVar6._1_1_ = objDef[1].mapStates2;
          (this->pos).scale =
               1.0 / ((float)((double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000) -
                             4503601774854144.0) / 1000.0);
        }
        puVar10[0x3e] = 0;
        *(float *)(puVar10 + 4) = (objDef->pos).x;
        *(float *)(puVar10 + 8) = (objDef->pos).y;
        *(float *)(puVar10 + 0xc) = (objDef->pos).z;
        *(float *)(puVar10 + 0x18) = 0.0;
        *(float *)(puVar10 + 0x14) = 0.0;
        *(float *)(puVar10 + 0x28) = 1000.0;
        *(float *)(puVar10 + 0x20) = 400.0;
        *(float *)(puVar10 + 0x24) = 0.5;
        *(float *)(puVar10 + 0x1c) = 0.5;
        (this->pos).rotation.z = 0;
        this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
        return;
      }
      if (OVar1 != 0x1e6) {
        if ((short)OVar1 < 0x1e6) {
          if (OVar1 != ECSHcol) {
            if (0x1d6 < (short)OVar1) {
              return;
            }
            if (0x1d1 < (short)OVar1) {
              return;
            }
            if ((short)OVar1 < 0x1d0) {
              return;
            }
          }
        }
        else {
          if (OVar1 == 0x216) {
            (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
            (this->pos).rotation.y = *(short *)&objDef[1].allocatedSize;
            return;
          }
          if (0x215 < (short)OVar1) {
            return;
          }
          if (OVar1 != 0x201) {
            return;
          }
        }
      }
    }
    else {
      if (OVar1 == WM_fallenco) {
        (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
        (this->pos).rotation.y = *(short *)&objDef[1].allocatedSize;
        (this->pos).rotation.z = *(short *)&objDef[1].loadFlags;
        (this->pos).scale = 1.0;
        return;
      }
      if ((short)OVar1 < 699) {
        if (OVar1 == WM_NoPassHo) {
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          sVar4._0_1_ = objDef[1].allocatedSize;
          sVar4._1_1_ = objDef[1].mapStates1;
          *(float *)(puVar10 + 0x2c) =
               (float)((double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000) - 4503601774854144.0);
          puVar10[0x41] = 2;
          *(undefined2 *)(puVar10 + 0x38) = *(undefined2 *)&objDef[1].pos.x;
          return;
        }
        if (0x28b < (short)OVar1) {
          if (OVar1 == WM_largeroc) {
            (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
            (this->pos).rotation.y = *(short *)&objDef[1].allocatedSize;
            (this->pos).rotation.z = *(short *)&objDef[1].loadFlags;
            (this->pos).scale = 1.0;
            this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
            *(undefined2 *)(puVar10 + 0x3a) = *(undefined2 *)&objDef[1].pos.x;
            *(undefined2 *)(puVar10 + 0x38) = *(undefined2 *)&objDef[1].bound;
            return;
          }
          if (0x2b6 < (short)OVar1) {
            return;
          }
          if (0x295 < (short)OVar1) {
            return;
          }
          if ((short)OVar1 < 0x293) {
            return;
          }
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          (this->pos).rotation.y = *(short *)&objDef[1].allocatedSize;
          *(undefined2 *)(puVar10 + 0x38) = *(undefined2 *)&objDef[1].bound;
          *(undefined2 *)(puVar10 + 0x3a) = *(undefined2 *)&objDef[1].pos.x;
          *(float *)(puVar10 + 0x10) = 0.0;
          *(float *)(puVar10 + 4) = (objDef->pos).x;
          *(float *)(puVar10 + 8) = (objDef->pos).y;
          *(float *)(puVar10 + 0xc) = (objDef->pos).z;
          *(undefined2 *)(puVar10 + 0x3c) = 500;
          *(undefined2 *)(puVar10 + 0x36) = 1;
          if ((OVar1 == 0x295) && (uVar8 = mainGetBit(0x322), uVar8 != 0)) {
            (this->pos).pos.x = 34022.0;
            (this->pos).pos.y = 457.0;
            (this->pos).pos.z = 22523.0;
          }
          else if ((OVar1 == 0x295) && (uVar8 = mainGetBit(0x369), uVar8 != 0)) {
            (this->pos).pos.x = 34022.0;
            (this->pos).pos.y = 457.0;
            (this->pos).pos.z = 22523.0;
          }
          this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f1c24;
          return;
        }
        if (OVar1 == WM_MoonSeed) {
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          sVar2._0_1_ = objDef[1].allocatedSize;
          sVar2._1_1_ = objDef[1].mapStates1;
          *(float *)(puVar10 + 0x2c) =
               (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0);
          return;
        }
        if (0x270 < (short)OVar1) {
          if (OVar1 != WM_NoPassVi) {
            return;
          }
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          sVar3._0_1_ = objDef[1].allocatedSize;
          sVar3._1_1_ = objDef[1].mapStates1;
          *(float *)(puVar10 + 0x2c) =
               (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0);
          puVar10[0x41] = 2;
          return;
        }
        if (OVar1 != 0x23b) {
          return;
        }
      }
      else {
        if (OVar1 == VFP_locksym) {
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          *(undefined2 *)(puVar10 + 0x38) = *(undefined2 *)&objDef[1].pos.x;
          return;
        }
        if (0x621 < (short)OVar1) {
          if (OVar1 == 0x65d) {
            (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
            *(undefined2 *)(puVar10 + 0x38) = *(undefined2 *)&objDef[1].pos.x;
            Object_ObjAnimSetMove(0.0,this,0,0);
            *(float *)(puVar10 + 0x10) = 1.0;
            return;
          }
          if (0x65c < (short)OVar1) {
            return;
          }
          if ((short)OVar1 < 0x65c) {
            return;
          }
          (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
          return;
        }
        if (OVar1 != DFP_dish) {
          if (0x491 < (short)OVar1) {
            if (OVar1 != DFP_blockwa) {
              return;
            }
            (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
            this->curModel = *(byte *)((int)&objDef[1].objType + 1);
            *(undefined2 *)(puVar10 + 0x38) = *(undefined2 *)&objDef[1].pos.x;
            uVar8 = mainGetBit((int)*(short *)(puVar10 + 0x38));
            if (uVar8 == 0) {
              return;
            }
            (this->pos).pos.y = (objDef->pos).y + 30.0;
            return;
          }
          if (700 < (short)OVar1) {
            return;
          }
          goto LAB_801f0680;
        }
      }
    }
    (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  }
  return;
}


/* Library Function - Single Match
    dll_136_func04
   
   Library: KioskDefault 0 0 */

void genprops_update(ObjInstance *this) { //801F0AE4
  char cVar1;
  ObjDefEnum OVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ObjInstance *pOVar6;
  Camera *pCVar7;
  int *piVar8;
  uint uVar9;
  LoadedDll *pLVar10;
  int iVar11;
  undefined *puVar12;
  double in_f1;
  double dVar13;
  double local_78;
  double local_70;
  double local_60;
  
  _savefpr_28();
  pOVar6 = Object_objGetMain();
  puVar12 = this->state;
  pCVar7 = getCurCamera();
  OVar2 = this->romdefno;
  if (OVar2 == WM_NoPassHo) {
    iVar11 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if ((iVar11 != 0) &&
       (cVar1 = puVar12[0x41], puVar12[0x41] = cVar1 + -1, (char)(cVar1 + -1) < '\0')) {
      mainSetBits((int)*(short *)(puVar12 + 0x38),1);
      Object_objFreeObject(this);
    }
    objDistObj2Obj(this,pOVar6);
    if (in_f1 < (double)*(float *)(puVar12 + 0x2c)) {
      diPrintf("NoPass Vine");
      diPrintf("The Player Burns it away!");
    }
    goto LAB_801f1c04;
  }
  if ((short)OVar2 < 0x28c) {
    if (OVar2 == DIM2IceFloe_010D) {
      *(ushort *)(puVar12 + 0x3c) = *(short *)(puVar12 + 0x3c) - (ushort)framesThisStep;
      if (*(short *)(puVar12 + 0x3c) < 0) {
        iVar11 = randInt(0,(uint)(byte)puVar12[0x40]);
        audioTryStartSfx((int *)this,1,*(ushort *)(*(int *)(puVar12 + 0x44) + iVar11 * 2),0x7f,
                         "genprops.c",0x2f5);
        *(undefined2 *)(puVar12 + 0x3c) = *(undefined2 *)(puVar12 + 0x48);
        iVar11 = randInt(0,(uint)*(ushort *)(puVar12 + 0x48));
        *(short *)(puVar12 + 0x3c) = *(short *)(puVar12 + 0x3c) + (short)iVar11;
      }
      goto LAB_801f1c04;
    }
    if ((short)OVar2 < 0x10d) {
      if (OVar2 == SB_Galleon) {
        *(float *)(puVar12 + 0x14) = *(float *)(puVar12 + 0x1c) * 3.0 + *(float *)(puVar12 + 0x14);
        if ((180.0 < *(float *)(puVar12 + 0x14)) || (*(float *)(puVar12 + 0x14) < -180.0)) {
          *(float *)(puVar12 + 0x1c) = -*(float *)(puVar12 + 0x1c);
        }
        if ((90.0 < *(float *)(puVar12 + 0x18)) || (*(float *)(puVar12 + 0x18) < -90.0)) {
          *(float *)(puVar12 + 0x24) = -*(float *)(puVar12 + 0x24);
        }
        *(float *)(puVar12 + 0x18) = *(float *)(puVar12 + 0x24) * 3.0 + *(float *)(puVar12 + 0x18);
      }
      else if ((short)OVar2 < 0x8e) {
        if (OVar2 == CCqueen) {
          pOVar6 = Object_objGetMain();
          if (pOVar6 != (ObjInstance *)0x0) {
            fVar3 = (pOVar6->prevPos).x - (this->prevPos).x;
            fVar4 = (pOVar6->prevPos).z - (this->prevPos).z;
            dVar13 = sqrt((double)(fVar3 * fVar3 + fVar4 * fVar4));
            if (this->field76_0xf4 == 0) {
              if (((10.0 < dVar13) || (DAT_80399d98 != (ObjInstance *)0x0)) ||
                 (this->flags_0xf8 != 0)) {
                if (((dVar13 < 40.0) && (this->flags_0xf8 == 0)) && (this->field76_0xf4 == 0)) {
                    /* {@symbol 800d022c} */
                  (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
                }
              }
              else {
                audioTryStartSfx((int *)this,1,10,0x7f,"genprops.c",0x2e7);
                DAT_80399d98 = this;
                this->field76_0xf4 = 0x46;
              }
            }
            else {
              this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
              if ((int)this->field76_0xf4 < 1) {
                pLVar10 = (LoadedDll *)runlinkDownloadCode(0x2009,1);
                (**(code **)(pLVar10->id + 4))(DAT_80399d98,0,0,1,0xffffffff,9,0);
                if (pLVar10 != (LoadedDll *)0x0) {
                  DLL_free(pLVar10);
                }
                DAT_80399d98 = (ObjInstance *)0x0;
                this->field76_0xf4 = 0;
                this->flags_0xf8 = 100;
              }
            }
            this->flags_0xf8 = this->flags_0xf8 - 1;
            if ((int)this->flags_0xf8 < 1) {
              this->flags_0xf8 = 0;
            }
          }
        }
        else if ((((short)OVar2 < 0x86) && (0x84 < (short)OVar2)) &&
                (pOVar6 = Object_objGetMain(), pOVar6 != (ObjInstance *)0x0)) {
          fVar3 = (pOVar6->prevPos).x - (this->prevPos).x;
          fVar4 = (pOVar6->prevPos).z - (this->prevPos).z;
          dVar13 = sqrt((double)(fVar3 * fVar3 + fVar4 * fVar4));
          if ((400.0 <= dVar13) || (0 < (int)this->field76_0xf4)) {
            if (dVar13 < 200.0) {
              this->field76_0xf4 = this->field76_0xf4 + -1;
            }
          }
          else {
            pLVar10 = (LoadedDll *)runlinkDownloadCode(0x1008,1);
            for (iVar11 = 1; iVar11 != 0; iVar11 = iVar11 + -1) {
              (**(code **)(pLVar10->id + 4))(this,0,0,1,0xffffffff,0);
            }
            DLL_free(pLVar10);
            iVar11 = randInt(100,200);
            this->field76_0xf4 = iVar11;
          }
          if ((DAT_80399d98 != (ObjInstance *)0x0) && (this->flags_0xf8 == 0)) {
            this->flags_0xf8 = 1;
            pLVar10 = (LoadedDll *)runlinkDownloadCode(0x200a,1);
            (**(code **)(pLVar10->id + 4))(this,0,0,1,0xffffffff,10,0);
            if (pLVar10 != (LoadedDll *)0x0) {
              DLL_free(pLVar10);
            }
          }
          if (DAT_80399d98 == (ObjInstance *)0x0) {
            this->flags_0xf8 = 0;
          }
        }
      }
      else if (OVar2 == 0xae) {
        if (((this->field76_0xf4 == 0) && (this->field18_0x58 != (ObjInstanceField58 *)0xffffff00))
           && (*(short *)&this->field18_0x58[1].field_0x36 == 0x2b)) {
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
          this->field76_0xf4 = 1;
        }
      }
      else if (((short)OVar2 < 0xae) && (OVar2 == 0xab)) {
        local_60 = (double)CONCAT44(0x43300000,(uint)framesThisStep);
        *(float *)(puVar12 + 0x18) =
             *(float *)(puVar12 + 0x18) - (float)(local_60 - 4503599627370496.0);
        if (*(float *)(puVar12 + 0x18) < 0.0) {
          pLVar10 = (LoadedDll *)runlinkDownloadCode(0x1003,1);
          (**(code **)(pLVar10->id + 4))(this,0,0,1,0xffffffff,0);
          DLL_free(pLVar10);
          *(float *)(puVar12 + 0x18) = 30.0;
        }
      }
      goto LAB_801f1c04;
    }
    if (OVar2 == WM_MoonSeed) {
      objDistObj2Obj(this,pOVar6);
      if (in_f1 < (double)*(float *)(puVar12 + 0x2c)) {
        diPrintf("MoonSeed Mound");
        diPrintf("The Player Guesses that a Seed goes here!");
      }
      goto LAB_801f1c04;
    }
    if (0x270 < (short)OVar2) {
      if (OVar2 == WM_NoPassVi) {
        iVar11 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
        if ((iVar11 != 0) &&
           (cVar1 = puVar12[0x41], puVar12[0x41] = cVar1 + -1, (char)(cVar1 + -1) < '\0')) {
          Object_objFreeObject(this);
        }
        objDistObj2Obj(this,pOVar6);
        if (in_f1 < (double)*(float *)(puVar12 + 0x2c)) {
          diPrintf("NoPass Vine");
          diPrintf("The Player Burns it away!");
        }
      }
      goto LAB_801f1c04;
    }
    if (OVar2 != 0x221) {
      if (((short)OVar2 < 0x221) && (OVar2 == SB_Lamp)) {
        local_78 = (double)CONCAT44(0x43300000,-(int)(pCVar7->rot).z ^ 0x80000000);
        (this->pos).rotation.z = (short)(int)((local_78 - 4503601774854144.0) * 1.5);
        pOVar6 = Object_objGetMain();
        fVar3 = (pOVar6->prevPos).x - (this->prevPos).x;
        fVar4 = (pOVar6->prevPos).z - (this->prevPos).z;
        fVar5 = (pOVar6->prevPos).y - (this->prevPos).y;
        dVar13 = sqrt((double)(fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4));
        if ((75.0 <= dVar13) || (puVar12[0x3f] != '\x01')) {
          if ((75.0 < dVar13) && (puVar12[0x3f] == '\0')) {
            puVar12[0x3f] = 1;
            loadLfxAction(this,this,0x5d);
          }
        }
        else {
          puVar12[0x3f] = 0;
          loadLfxAction(this,this,0x5c);
        }
      }
      goto LAB_801f1c04;
    }
  }
  else {
    if (OVar2 == DFP_blockwa) {
      if (((this->pos).pos.y < (this->def->pos).y + 30.0) &&
         (uVar9 = mainGetBit((int)*(short *)(puVar12 + 0x38)), uVar9 != 0)) {
        (this->pos).pos.y = (this->pos).pos.y + timeDelta;
      }
      goto LAB_801f1c04;
    }
    if (0x4be < (short)OVar2) {
      if (OVar2 == VFP_locksym) {
        piVar8 = (int *)FUN_80094400((int)this,0);
        uVar9 = mainGetBit((int)*(short *)(puVar12 + 0x38));
        if ((((uVar9 != 0) && (*piVar8 < 0x100)) && (piVar8 != (int *)0x0)) &&
           (*piVar8 = *piVar8 + 0x10, 0xff < *piVar8)) {
          audioSfxFn_800688bc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                              (double)(this->pos).pos.z,0x49,0x7f,"genprops.c",(int *)0x18e
                             );
          *piVar8 = 0x100;
        }
      }
      else if ((short)OVar2 < 0x622) {
        if (OVar2 == VFP_PowerBo) {
          this->flags_0xf8 = this->flags_0xf8 - (int)(short)(int)timeDelta;
          (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
          (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
          (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
                    /* {@symbol 800ed30c} */
          dVar13 = (double)(**(code **)(*(int *)pDll_objfsa + 8))
                                     (this,0x39d,0,&DAT_00010001,0xffffffff,0);
          objDistObj2Obj(this,pOVar6);
          if (dVar13 < 30.0) {
            diPrintf("Hit Krystal");
            objSendMsg((int)pOVar6,0x60004,(uint)this,1);
            Object_objFreeObject(this);
          }
          if ((int)this->flags_0xf8 < 1) {
            Object_objFreeObject(this);
          }
        }
        else if (((short)OVar2 < 0x549) && (OVar2 == DFP_PowerBo)) {
          this->flags_0xf8 = this->flags_0xf8 - (int)(short)(int)timeDelta;
          (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
          (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
          (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
                    /* {@symbol 800ed30c} */
          dVar13 = (double)(**(code **)(*(int *)pDll_objfsa + 8))
                                     (this,0x5f3,0,&DAT_00010001,0xffffffff,0);
          objDistObj2Obj(this,pOVar6);
          if (dVar13 < 30.0) {
            diPrintf("Hit Krystal");
            objSendMsg((int)pOVar6,0x60004,(uint)this,1);
            Object_objFreeObject(this);
          }
          if ((int)this->flags_0xf8 < 1) {
            Object_objFreeObject(this);
          }
        }
      }
      else if (OVar2 == 0x65d) {
        objRunAnimation(0.002000000094994903,(double)timeDelta,(int)this,(float *)0x0);
      }
      goto LAB_801f1c04;
    }
    if (OVar2 == WM_largeroc) {
      uVar9 = mainGetBit((int)*(short *)(puVar12 + 0x38));
      if (uVar9 == 0) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      }
      goto LAB_801f1c04;
    }
    if ((short)OVar2 < 0x2b7) {
      if (OVar2 == 0x295) {
        if (((*(short *)(puVar12 + 0x38) == -1) ||
            (uVar9 = mainGetBit((int)*(short *)(puVar12 + 0x38)), uVar9 == 0)) ||
           ((1.0 < *(float *)(puVar12 + 0x10) || (*(short *)(puVar12 + 0x3c) != 0)))) {
          if ((0 < *(short *)(puVar12 + 0x3c)) &&
             (*(ushort *)(puVar12 + 0x3c) = *(short *)(puVar12 + 0x3c) - (ushort)framesThisStep,
             *(short *)(puVar12 + 0x3c) < 1)) {
            *(undefined2 *)(puVar12 + 0x3c) = 0;
            uVar9 = mainGetBit(0x322);
            if (uVar9 == 0) {
              uVar9 = mainGetBit(0x369);
              if (uVar9 != 0) {
                mainSetBits(0x369,0);
              }
            }
            else {
              mainSetBits(0x322,0);
            }
          }
        }
        else {
          if ((*(short *)(puVar12 + 0x3a) != -1) &&
             (uVar9 = mainGetBit((int)*(short *)(puVar12 + 0x3a)), uVar9 != 0)) {
            *(undefined2 *)(puVar12 + 0x3c) = 400;
            mainSetBits((int)*(short *)(puVar12 + 0x3a),0);
          }
          local_60 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar12 + 0x36) ^ 0x80000000);
          *(float *)(puVar12 + 0x10) =
               (float)(local_60 - 4503601774854144.0) * 0.001 * timeDelta +
               *(float *)(puVar12 + 0x10);
          if (*(float *)(puVar12 + 0x10) <= 1.0) {
            if (*(float *)(puVar12 + 0x10) < 0.0) {
              *(float *)(puVar12 + 0x10) = 0.0;
              *(short *)(puVar12 + 0x36) = -*(short *)(puVar12 + 0x36);
              *(undefined2 *)(puVar12 + 0x3c) = 400;
              mainSetBits(0x322,0);
            }
          }
          else {
            *(float *)(puVar12 + 0x10) = 1.0;
            *(short *)(puVar12 + 0x36) = -*(short *)(puVar12 + 0x36);
            *(undefined2 *)(puVar12 + 0x3c) = 400;
            mainSetBits(0x322,1);
          }
          if (*(short *)(puVar12 + 0x38) == 0x319) {
            (this->pos).pos.x =
                 *(float *)(puVar12 + 0x10) * (14807.0 - *(float *)(puVar12 + 4)) +
                 *(float *)(puVar12 + 4);
            (this->pos).pos.y =
                 *(float *)(puVar12 + 0x10) * (457.0 - *(float *)(puVar12 + 8)) +
                 *(float *)(puVar12 + 8);
            (this->pos).pos.z =
                 *(float *)(puVar12 + 0x10) * (3305.0 - *(float *)(puVar12 + 0xc)) +
                 *(float *)(puVar12 + 0xc);
            (this->pos).rotation.x = (short)(int)((1.0 - *(float *)(puVar12 + 0x10)) * 8192.0);
          }
          else if (*(short *)(puVar12 + 0x38) == 0x363) {
            (this->pos).pos.x =
                 *(float *)(puVar12 + 0x10) * (14621.0 - *(float *)(puVar12 + 4)) +
                 *(float *)(puVar12 + 4);
            (this->pos).pos.y =
                 *(float *)(puVar12 + 0x10) * (457.0 - *(float *)(puVar12 + 8)) +
                 *(float *)(puVar12 + 8);
            (this->pos).pos.z =
                 *(float *)(puVar12 + 0x10) * (2453.0 - *(float *)(puVar12 + 0xc)) +
                 *(float *)(puVar12 + 0xc);
            (this->pos).rotation.x = (short)(int)((1.0 - *(float *)(puVar12 + 0x10)) * 8192.0);
          }
          (pOVar6->pos).pos.x = (this->pos).pos.x;
          (pOVar6->pos).pos.y = (this->pos).pos.y;
          (pOVar6->pos).pos.z = (this->pos).pos.z;
        }
      }
      else if (((((short)OVar2 < 0x295) && (0x292 < (short)OVar2)) &&
               (*(short *)(puVar12 + 0x38) != -1)) &&
              (uVar9 = mainGetBit((int)*(short *)(puVar12 + 0x38)), uVar9 != 0)) {
        if ((this->pos).rotation.y < 1) {
          (this->pos).rotation.y = (this->pos).rotation.y + 0x32;
        }
        else {
          (this->pos).rotation.y = 0;
        }
      }
      goto LAB_801f1c04;
    }
    if (OVar2 == 0x409) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      goto LAB_801f1c04;
    }
    if ((0x408 < (short)OVar2) || (OVar2 != WM_rock)) goto LAB_801f1c04;
  }
  this->hitstate->field_0x5d = 0xd;
  *(undefined *)&this->hitstate->sizeX2 = 2;
  this->hitstate->field16_0x52 = 10;
  this->hitstate->sizeXY_0C = 10.0;
  this->hitstate->field15_0x50 = 0x1e;
  this->hitstate->flags = this->hitstate->flags | 1;
  uVar9 = mainGetBit(0x1d9);
  if (uVar9 != 0) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
  }
  if (puVar12[0x3e] == '\x02') {
    audioTryStartSfx((int *)this,1,0x122,0x43,"genprops.c",0x26b);
    puVar12[0x3e] = puVar12[0x3e] + -1;
  }
  if ((puVar12[0x3e] != '\0') && ((this->pos).pos.y + (this->vel).y <= (pOVar6->pos).pos.y)) {
    puVar12[0x3e] = 0;
    (this->vel).y = (this->vel).y * -0.4;
    (this->vel).x = (this->vel).x * 2.0;
    (this->vel).z = (this->vel).z * 2.0;
    (this->pos).scale = (this->pos).scale * 0.5;
    *(float *)(puVar12 + 0x18) = *(float *)(puVar12 + 0x18) * 2.0;
    *(float *)(puVar12 + 0x14) = *(float *)(puVar12 + 0x14) * 2.0;
    audioTryStartSfx((int *)this,1,0x1ff,0x7f,"genprops.c",0x276);
    FUN_8006ae50(0.5);
  }
  if ((puVar12[0x3e] == '\0') && (*(float *)(puVar12 + 0x2c) <= 40000.0)) {
    *(float *)(puVar12 + 0x2c) = timeDelta * 2.0 + *(float *)(puVar12 + 0x2c);
    objHitFn_80089354(this,(short)(int)(*(float *)(puVar12 + 0x2c) / 10.0) + 0x14);
  }
  (this->vel).y = timeDelta * -0.15 + (this->vel).y;
  local_60 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.z ^ 0x80000000);
  (this->pos).rotation.z =
       (short)(int)((float)(local_60 - 4503601774854144.0) + *(float *)(puVar12 + 0x18));
  local_70 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000);
  (this->pos).rotation.y =
       (short)(int)((float)(local_70 - 4503601774854144.0) + *(float *)(puVar12 + 0x14));
  (this->pos).pos.y = (this->pos).pos.y + (this->vel).y;
  (this->pos).pos.x = (this->pos).pos.x + (this->vel).x;
  (this->pos).pos.z = (this->pos).pos.z + (this->vel).z;
  (this->prevPos).y = (this->pos).pos.y;
  (this->prevPos).x = (this->pos).pos.x;
  (this->prevPos).z = (this->pos).pos.z;
  *(ushort *)(puVar12 + 0x36) = *(short *)(puVar12 + 0x36) - (ushort)framesThisStep;
  if (((pOVar6->pos).pos.y < (this->pos).pos.y) && (iVar11 = randInt(0,2), iVar11 == 0)) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x27f,0,&DAT_00010001,0xffffffff,0);
  }
  if (*(short *)(puVar12 + 0x36) < 1) {
    Object_objFreeObject(this);
  }
LAB_801f1c04:
  _restfpr_28();
  return;
}


/* @description Override hit detection */

void genprops_hitDetect(ObjInstance *this) { //801F1C20
  return;
}


/* Library Function - Single Match
    dll_136_func06
   
   Library: KioskDefault 0 0 */

void genprops_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801F1D3C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((((shouldRender) && (this->romdefno != DFP_PowerBo)) && (shouldRender)) &&
     (((this->romdefno != VFP_PowerBo && (shouldRender)) &&
      ((this->romdefno != scalessword &&
       (objRenderCurrentModel
                  (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),
                   (undefined4 *)CONCAT31(in_register_00000018,param4),
                   (undefined4 *)CONCAT31(in_register_0000001c,param5)),
       ((this->pos).flags & 0x100) != 0)))))) {
    FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)*(float *)(puVar1 + 0x2c),25.0,(Gfx *)CONCAT31(in_register_00000010,param2)
                 ,(int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
  }
  return;
}


/* @description Free object instance */

void genprops_free(ObjInstance *this,int param2) { //801F1E18
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 genprops_func08(ObjInstance *this) { //801F1E50
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int genprops_getExtraSize(void) { //801F1E58
  return 0x4c;
}

