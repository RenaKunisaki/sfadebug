
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WMcrystal_initialise(undefined4 param) { //802873D8
  return;
}


/* @description Called when DLL is unloaded */

void WMcrystal_release(void) { //802873DC
  return;
}


/* Library Function - Single Match
    dll_250_func03
   
   Library: KioskDefault 0 0 */

void WMcrystal_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802873E0
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  char cVar10;
  uint uVar6;
  DLL_func **ppDVar7;
  int iVar8;
  void *pvVar9;
  short sVar11;
  undefined *puVar12;
  undefined4 in_register_00004008;
  undefined4 in_register_00004010;
  
  puVar12 = this->state;
                    /* {@symbol 8012dfa8} */
  cVar10 = (**(code **)(*(int *)pDll_SaveGame + 0x40))
                     (CONCAT44(in_register_00004008,x),CONCAT44(in_register_00004010,y),
                      (int)(char)this->mapId);
  if ((cVar10 == '\x03') && (uVar6 = mainGetBit(0x21b), uVar6 == 0)) {
    mainSetBits(0x21b,1);
  }
  *(undefined4 *)(puVar12 + 8) = 0;
  *(undefined4 *)(puVar12 + 0xc) = 0;
  puVar12[0x11] = 1;
  if (this->romdefno == WM_Crystal) {
    (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
    *(undefined2 *)(puVar12 + 2) = 100;
    sVar1._0_1_ = objDef[1].loadFlags;
    sVar1._1_1_ = objDef[1].mapStates2;
    if (sVar1 < 1000) {
      (this->pos).scale = 1.0;
    }
    else {
      sVar2._0_1_ = objDef[1].loadFlags;
      sVar2._1_1_ = objDef[1].mapStates2;
      (this->pos).scale =
           (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0) /
           1000.0;
    }
  }
  else if (this->romdefno == WM_sun) {
    DAT_8039a084 = 800;
    DAT_8039a086 = 800;
    DAT_8039a088 = 800;
    DAT_8039a08a = 800;
    DAT_8039a08c = 800;
    (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
    sVar3._0_1_ = objDef[1].loadFlags;
    sVar3._1_1_ = objDef[1].mapStates2;
    if (sVar3 < 0) {
      (this->pos).scale = 1.0;
    }
    else {
      sVar4._0_1_ = objDef[1].loadFlags;
      sVar4._1_1_ = objDef[1].mapStates2;
      (this->pos).scale =
           (float)((double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000) - 4503601774854144.0) /
           1000.0;
    }
    this->curModel = *(byte *)((int)&objDef[1].objType + 1);
    if (this->curModel == 0) {
      ppDVar7 = runlinkDownloadCode(0x2012,1);
      *(DLL_func ***)(puVar12 + 0xc) = ppDVar7;
      iVar8 = randInt(300,600);
      *(short *)(puVar12 + 2) = (short)iVar8;
      iVar8 = randInt(300,600);
      *(short *)(puVar12 + 4) = (short)iVar8;
      DAT_8039a080 = runlinkDownloadCode(0x1036,1);
    }
    else if (this->curModel == 1) {
      iVar8 = randInt(500,800);
      *(short *)(puVar12 + 2) = (short)iVar8;
      iVar8 = randInt(500,800);
      *(short *)(puVar12 + 4) = (short)iVar8;
    }
    else if (this->curModel == 2) {
      ppDVar7 = runlinkDownloadCode(0x2012,1);
      *(DLL_func ***)(puVar12 + 0xc) = ppDVar7;
      iVar8 = randInt(700,1000);
      *(short *)(puVar12 + 2) = (short)iVar8;
      iVar8 = randInt(700,1000);
      *(short *)(puVar12 + 4) = (short)iVar8;
    }
    this->newOpacity = 0;
  }
  else if (this->romdefno == 0x2c2) {
    pvVar9 = mmAlloc(0xa0,OBJECTS_COL,"wmsun:alist");
    *(void **)(puVar12 + 8) = pvVar9;
    sVar11 = 0x14;
    while (sVar11 != 0) {
      sVar11 = sVar11 + -1;
      *(undefined2 *)(*(int *)(puVar12 + 8) + (sVar11 + 0x14) * 2) = 0;
      iVar8 = randInt(10,0x14);
      *(short *)(*(int *)(puVar12 + 8) + (sVar11 + 0x28) * 2) = (short)iVar8;
      iVar8 = randInt(0x50,0xff);
      *(short *)(*(int *)(puVar12 + 8) + (sVar11 + 0x3c) * 2) = (short)iVar8;
    }
    this->newOpacity = 0;
    sVar11._0_1_ = objDef[1].loadFlags;
    sVar11._1_1_ = objDef[1].mapStates2;
    if (sVar11 != 0) {
      sVar5._0_1_ = objDef[1].loadFlags;
      sVar5._1_1_ = objDef[1].mapStates2;
      (this->pos).scale =
           1.0 / ((float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - 4503601774854144.0)
                 / 1000.0);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_250_func04
   
   Library: KioskDefault 0 0 */

void WMcrystal_update(ObjInstance *this) { //8028774C
  short sVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  undefined *puVar5;
  short unaff_r30;
  double dVar6;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_30;
  uint uStack_2c;
  
  puVar5 = this->state;
  sVar4 = 0;
  sVar1 = 1;
  dVar6 = 0.0;
  if (this->romdefno == WM_Crystal) {
    uVar2 = mainGetBit(0x38f);
    if (uVar2 != 0) {
      Object_objFreeObject(this);
    }
    iVar3 = FUN_80094400((int)this,1);
    if ((iVar3 != 0) &&
       (*(short *)(iVar3 + 10) = *(short *)(iVar3 + 10) + -0x10, *(short *)(iVar3 + 10) < -0x3e0)) {
      *(undefined2 *)(iVar3 + 10) = 0;
    }
    uVar2 = mainGetBit(0x21b);
    if (uVar2 != 0) {
      sVar4 = 100;
    }
    uVar2 = mainGetBit(0x21c);
    if (uVar2 != 0) {
      sVar4 = 200;
    }
    uVar2 = mainGetBit(0x21d);
    if (uVar2 != 0) {
      sVar4 = 400;
    }
    uVar2 = mainGetBit(0x21f);
    if (uVar2 != 0) {
      sVar4 = 800;
    }
    uVar2 = mainGetBit(0x221);
    if (uVar2 != 0) {
      sVar4 = 0x640;
    }
    uVar2 = mainGetBit(0x222);
    if (uVar2 != 0) {
      sVar4 = 0x1900;
      sVar1 = 3;
      dVar6 = 0.003749999916180968;
    }
    if (*(short *)(puVar5 + 2) < sVar4) {
      *(ushort *)(puVar5 + 2) = *(short *)(puVar5 + 2) + (ushort)framesThisStep * sVar1;
      (this->pos).scale = -(float)(dVar6 * (double)timeDelta - (double)(this->pos).scale);
      (this->pos).pos.y = (float)(dVar6 * (double)timeDelta) * 50.0 + (this->pos).pos.y;
    }
    else {
      uVar2 = mainGetBit(0x222);
      if (uVar2 != 0) {
        uVar2 = mainGetBit(0x38d);
        if (uVar2 == 0) {
          mainSetBits(0x38d,1);
          mainSetBits(0x370,0);
          puVar5[0x11] = 0;
        }
      }
    }
    uVar2 = mainGetBit(0x38d);
    if (uVar2 == 0) {
      if ((0x960 < *(short *)(puVar5 + 2)) && (iVar3 = randInt(0,100), iVar3 == 0)) {
        uStack_2c = (int)*(short *)(puVar5 + 2) - 0x960U ^ 0x80000000;
        local_30 = 0x43300000;
        FUN_8006ae50((double)(((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0)
                              / 2400.0) * 0.8));
        mainSetBits(0x370,1);
      }
    }
    (this->pos).rotation.x = (this->pos).rotation.x + *(short *)(puVar5 + 2);
    if (puVar5[0x11] == '\0') {
      Object_objFreeObject(this);
    }
  }
  else if (this->romdefno == 0x2c2) {
    uVar2 = mainGetBit(0x38f);
    if (uVar2 != 0) {
      if (this->newOpacity < 0xfa) {
        unaff_r30 = (ushort)this->newOpacity + (ushort)framesThisStep;
      }
      if (0xfa < unaff_r30) {
        unaff_r30 = 0xfa;
      }
      this->newOpacity = (u8)unaff_r30;
      iVar3 = FUN_80094400((int)this,0);
      if ((iVar3 != 0) &&
         (*(ushort *)(iVar3 + 8) = *(short *)(iVar3 + 8) + (ushort)framesThisStep * -8,
         *(short *)(iVar3 + 8) < -0x3e0)) {
        *(undefined2 *)(iVar3 + 8) = 0;
      }
    }
  }
  else {
    uVar2 = mainGetBit(0x38f);
    if (uVar2 == 0) {
      (this->pos).rotation.z = (this->pos).rotation.z + *(short *)(puVar5 + 4);
      (this->pos).rotation.x = (this->pos).rotation.x + *(short *)(puVar5 + 2);
      uVar2 = mainGetBit(0x38d);
      if (uVar2 != 0) {
        if (this->curModel == 0) {
          if (DAT_8039a08a == 0) {
            if ((600 < DAT_8039a08c) && (iVar3 = randInt(0,10), iVar3 == 0)) {
              FUN_8006ae50(2.799999952316284);
            }
            if ((DAT_8039a08c < 700) && (iVar3 = randInt(0,5), iVar3 == 0)) {
              (**(code **)(**(int **)(puVar5 + 0xc) + 4))(this,0,0,0x10000,0xffffffff,0x12,0);
            }
            if (0 < DAT_8039a08c) {
              DAT_8039a08c = DAT_8039a08c - (ushort)framesThisStep;
              if ((DAT_8039a08c < 200) && (iVar3 = randInt(0,1), iVar3 == 0)) {
                uStack_2c = (int)DAT_8039a08c ^ 0x80000000;
                local_30 = 0x43300000;
                local_40 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) /
                           200.0 + 0.1;
                    /* {@symbol 800ed30c} */
                (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1b1,&local_4c,0x10000,0xffffffff,0);
              }
              if (DAT_8039a08c < 1) {
                DAT_8039a08c = 0;
                for (sVar1 = 200; sVar1 != 0; sVar1 = sVar1 + -1) {
                    /* {@symbol 800ed30c} */
                  (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1b2,0,0x10000,0xffffffff,0);
                }
                mainSetBits(0x38d,0);
                mainSetBits(0x38f,1);
                loadEnvfxAction(this,this,0x31,0);
                FUN_8006ae50(4.800000190734863);
              }
            }
          }
          if (DAT_8039a084 == 0) {
            iVar3 = randInt(0,(DAT_8039a086 + 2) / 200);
            if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ae,&local_4c,0x10000,0xffffffff,0);
            }
            iVar3 = randInt(0,(int)DAT_8039a086 / 0x46);
            if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ab,&local_4c,0x10000,0xffffffff,0);
            }
            iVar3 = randInt(0,(int)DAT_8039a086 / 0x46);
            if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ab,&local_4c,0x10000,0xffffffff,0);
            }
            iVar3 = randInt(0,(int)DAT_8039a086 / 0x46);
            if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ab,&local_4c,0x10000,0xffffffff,0);
            }
            iVar3 = randInt(0,(int)DAT_8039a086 / 0x46);
            if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ab,&local_4c,0x10000,0xffffffff,0);
            }
            iVar3 = randInt(0,(int)DAT_8039a086 / 0x46);
            if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ab,&local_4c,0x10000,0xffffffff,0);
            }
            if ((0 < DAT_8039a086) &&
               (DAT_8039a086 = DAT_8039a086 - (ushort)framesThisStep, DAT_8039a086 < 0)) {
              DAT_8039a086 = 0;
            }
          }
          else {
            local_40 = 0.1;
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1b0,&local_4c,0x10000,0xffffffff,0);
            if ((0x32 < DAT_8039a084) && (iVar3 = randInt(0,1), iVar3 == 0)) {
              uStack_2c = (int)DAT_8039a084 - 0x32U ^ 0x80000000;
              local_30 = 0x43300000;
              local_40 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) /
                         750.0 + 0.1;
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1b0,&local_4c,0x10000,0xffffffff,0);
            }
            if (DAT_8039a084 < 700) {
              for (sVar1 = DAT_8039a084 / 0x3c; sVar1 != 0; sVar1 = sVar1 + -1) {
                uStack_2c = (int)DAT_8039a084 ^ 0x80000000;
                local_30 = 0x43300000;
                local_40 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) /
                           300.0;
                    /* {@symbol 800ed30c} */
                (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1af,&local_4c,0x10000,0xffffffff,0);
              }
            }
            if ((0 < DAT_8039a084) &&
               (DAT_8039a084 = DAT_8039a084 - (ushort)framesThisStep, DAT_8039a084 < 1)) {
              DAT_8039a084 = 0;
              loadEnvfxAction(this,this,0x30,0);
              loadEnvfxAction(this,this,0x34,0);
            }
            iVar3 = randInt(0,8);
            if (iVar3 == 0) {
              FUN_8006ae50(2.799999952316284);
            }
          }
        }
        if ((this->curModel == 1) && (DAT_8039a086 == 0)) {
          iVar3 = randInt(0,(int)DAT_8039a088 / 0x3c);
          if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ac,0,0x10000,0xffffffff,0);
          }
          iVar3 = randInt(0,(int)DAT_8039a088 / 0x3c);
          if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ac,0,0x10000,0xffffffff,0);
          }
          iVar3 = randInt(0,(int)DAT_8039a088 / 0x3c);
          if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ac,0,0x10000,0xffffffff,0);
          }
          if ((0 < DAT_8039a088) &&
             (DAT_8039a088 = DAT_8039a088 - (ushort)framesThisStep, DAT_8039a088 < 0)) {
            DAT_8039a088 = 0;
          }
        }
        if (((this->curModel == 2) && (DAT_8039a086 < 1)) && (DAT_8039a088 < 1)) {
          iVar3 = randInt(0,(int)DAT_8039a08a / 0x3c);
          if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ad,0,0x10000,0xffffffff,0);
          }
          iVar3 = randInt(0,(int)DAT_8039a08a / 0x3c);
          if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1ad,0,0x10000,0xffffffff,0);
          }
          if ((0 < DAT_8039a08a) &&
             (DAT_8039a08a = DAT_8039a08a - (ushort)framesThisStep, DAT_8039a08a < 1)) {
            DAT_8039a08a = 0;
          }
        }
      }
    }
    else {
      if ((this->curModel == 0) && (this->newOpacity != 0xff)) {
        if (this->newOpacity != 0xff) {
          unaff_r30 = (ushort)this->newOpacity + (ushort)framesThisStep;
        }
        if (0xff < unaff_r30) {
          unaff_r30 = 0xff;
        }
        this->newOpacity = (u8)unaff_r30;
      }
      else if ((this->curModel == 1) && (this->newOpacity != 0x55)) {
        if (this->newOpacity < 0x55) {
          unaff_r30 = (ushort)this->newOpacity + (ushort)framesThisStep;
        }
        if (0x55 < unaff_r30) {
          unaff_r30 = 0x55;
        }
        this->newOpacity = (u8)unaff_r30;
      }
      else if (this->curModel == 2) {
        if (this->newOpacity != 0x19) {
          if (this->newOpacity < 0x19) {
            unaff_r30 = (ushort)this->newOpacity + (ushort)framesThisStep;
          }
          if (0x19 < unaff_r30) {
            unaff_r30 = 0x19;
          }
          this->newOpacity = (u8)unaff_r30;
        }
      }
      if (this->curModel == 0) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a9,0,0x10000,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a9,0,0x10000,0xffffffff,0);
        iVar3 = randInt(0,4);
        if (iVar3 == 0) {
          (**(code **)(*DAT_8039a080 + 4))(this,0,0,1,0xffffffff,0);
        }
        iVar3 = randInt(0,0x96);
        if (iVar3 == 0) {
          local_40 = 0.0;
          local_3c = 0.0;
          local_38 = 0.0;
          local_44 = 1.0;
          iVar3 = randInt(0,0xffff);
          local_48 = (undefined2)iVar3;
          iVar3 = randInt(0,0xffff);
          local_4a = (undefined2)iVar3;
          iVar3 = randInt(0,0xffff);
          local_4c = (undefined2)iVar3;
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x44,0x43,"wmcrystal.c",
                              (int *)0x14e);
          for (sVar1 = 0x32; sVar1 != 0; sVar1 = sVar1 + -1) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1aa,&local_4c,0x10000,0xffffffff,0);
          }
        }
        FUN_80288564((short *)this);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void WMcrystal_hitDetect(ObjInstance *this) { //8028842C
  return;
}


/* Library Function - Single Match
    dll_250_func06
   
   Library: KioskDefault 0 0 */

void WMcrystal_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //80288430
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  if ((shouldRender) && (this->state[0x11] != '\0')) {
    FUN_800a6ad4((int *)param2_00,0x10000);
    objRenderCurrentModel
              (this,param2_00,(undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_800a6a84((int *)param2_00,0x10000);
  }
  return;
}


/* Library Function - Single Match
    dll_250_func07
   
   Library: KioskDefault 0 0 */

void WMcrystal_free(ObjInstance *this,int param2) { //802884BC
  undefined *puVar1;
  
  puVar1 = this->state;
  if (DAT_8039a080 != (LoadedDll *)0x0) {
    if ((this->romdefno == WM_sun) && (this->curModel == 0)) {
      DLL_free(DAT_8039a080);
      DAT_8039a080 = (LoadedDll *)0x0;
    }
  }
  if (*(int *)(puVar1 + 8) != 0) {
    mm_free(*(void **)(puVar1 + 8));
  }
  *(undefined4 *)(puVar1 + 8) = 0;
  if (*(int *)(puVar1 + 0xc) != 0) {
    DLL_free(*(LoadedDll **)(puVar1 + 0xc));
  }
  *(undefined4 *)(puVar1 + 0xc) = 0;
  return;
}


undefined4 WMcrystal_func08(ObjInstance *this) { //80288554
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WMcrystal_getExtraSize(void) { //8028855C
  return 0x14;
}

