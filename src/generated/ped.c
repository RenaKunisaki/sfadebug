
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void ped_initialise(undefined4 param) { //802476B4
  return;
}


/* @description Called when DLL is unloaded */

void ped_release(void) { //802476B8
  return;
}


/* Library Function - Single Match
    dll_1D2_func03
   
   Library: KioskDefault 0 0 */

void ped_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,float y
              ,float z) { //802476BC
  uint uVar1;
  int iVar2;
  float *pfVar3;
  
  pfVar3 = (float *)this->state;
  *pfVar3 = 1.2;
  pfVar3[1] = 0.6;
  pfVar3[2] = 0.6;
  uVar1 = randInt(0x19,0x4b);
  pfVar3[6] = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0) * 0.01;
  uVar1 = randInt(0x28,0x46);
  pfVar3[7] = pfVar3[6] /
              (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0);
  pfVar3[8] = 0.0;
  pfVar3[9] = 0.0;
  pfVar3[4] = pfVar3[4] + pfVar3[1];
  if (pfVar3[4] <= 255.0) {
    if (pfVar3[4] < 0.0) {
      pfVar3[4] = 255.0;
    }
  }
  else {
    pfVar3[4] = 255.0;
  }
  pfVar3[5] = pfVar3[5] + pfVar3[2];
  if (pfVar3[5] <= 255.0) {
    if (pfVar3[5] < 0.0) {
      pfVar3[5] = 255.0;
    }
  }
  else {
    pfVar3[5] = 255.0;
  }
  iVar2 = FUN_80094400((int)this,0);
  if (iVar2 != 0) {
    *(undefined *)(iVar2 + 0xc) = 0x1e;
    *(undefined *)(iVar2 + 0xd) = 10;
    *(undefined *)(iVar2 + 0xe) = 0x1e;
  }
  (this->prevPos).x = (this->pos).pos.x;
  (this->prevPos).y = (this->pos).pos.y;
  (this->prevPos).z = (this->pos).pos.z;
  return;
}


/* Library Function - Single Match
    dll_1D2_func04
   
   Library: KioskDefault 0 0 */

void ped_update(ObjInstance *this) { //8024784C
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ObjInstance *param2;
  int iVar6;
  uint uVar7;
  N64Button NVar8;
  short sVar9;
  float *pfVar10;
  double in_f1;
  double local_38;
  double local_30;
  
  _savefpr_30();
  pfVar10 = (float *)this->state;
  param2 = Object_objGetMain();
  if (param2 != (ObjInstance *)0x0) {
    iVar6 = FUN_80094400((int)this,0);
    uVar7 = mainGetBit(0x5be);
    if (uVar7 == 0) {
      if (DAT_80399f50 < 1) {
        in_f1 = 127.0;
        audioTryStartSfx((int *)0x0,1,0x169,0x7f,"ped.c",0x61);
        DAT_80399f50 = 100;
      }
      DAT_80399f50 = DAT_80399f50 + (ushort)framesThisStep;
      NVar8 = n64GetEnabledButtonsHeld(0);
      if ((NVar8 & N64_BUTTON_A) != 0) {
        objDistObj2Obj(this,param2);
        if (in_f1 < 100.0) {
          mainSetBits(0x5be,1);
          goto LAB_80247bf4;
        }
      }
      sVar9 = 6;
      while( true ) {
        bVar1 = sVar9 == 0;
        sVar9 = sVar9 + -1;
        if (bVar1) break;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2aa,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x2ab,0,0,0xffffffff,0);
      }
      pfVar10[8] = pfVar10[7] * timeDelta + pfVar10[8];
      if (pfVar10[8] < pfVar10[6]) {
        if (pfVar10[8] < 0.0) {
          uVar7 = randInt(0x19,0x4b);
          local_30 = (double)CONCAT44(0x43300000,uVar7 ^ 0x80000000);
          pfVar10[6] = (float)(local_30 - 4503601774854144.0) * 0.01;
          uVar7 = randInt(0x28,0x46);
          local_38 = (double)CONCAT44(0x43300000,uVar7 ^ 0x80000000);
          pfVar10[7] = pfVar10[6] / (float)(local_38 - 4503601774854144.0);
          pfVar10[8] = 0.0;
        }
      }
      else {
        pfVar10[7] = pfVar10[7] * -1.0;
      }
      if (iVar6 != 0) {
        pfVar10[3] = *pfVar10 * timeDelta * 10.0 + pfVar10[3];
        if (pfVar10[3] < 245.0) {
          if (pfVar10[3] <= 140.0) {
            if (pfVar10[1] <= 0.0) {
              pfVar10[1] = pfVar10[1] * -1.0;
              pfVar10[2] = pfVar10[2] * -1.0;
              *pfVar10 = *pfVar10 * -1.0;
              goto LAB_80247bf4;
            }
          }
          pfVar10[4] = pfVar10[4] + pfVar10[1];
          if (pfVar10[4] <= 255.0) {
            if (pfVar10[4] < 0.0) {
              pfVar10[4] = 255.0;
            }
          }
          else {
            pfVar10[4] = 255.0;
          }
          pfVar10[5] = pfVar10[5] + pfVar10[2];
          if (pfVar10[5] <= 255.0) {
            if (pfVar10[5] < 0.0) {
              pfVar10[5] = 255.0;
            }
          }
          else {
            pfVar10[5] = 255.0;
          }
          fVar2 = pfVar10[4];
          fVar3 = pfVar10[8];
          fVar4 = pfVar10[5];
          fVar5 = pfVar10[8];
          *(char *)(iVar6 + 0xc) = (char)(int)pfVar10[3];
          *(char *)(iVar6 + 0xd) = (char)(int)(fVar2 * (fVar3 + 0.25));
          *(char *)(iVar6 + 0xe) = (char)(int)(fVar4 * (fVar5 + 0.25));
        }
        else {
          pfVar10[1] = pfVar10[1] * -1.0;
          pfVar10[2] = pfVar10[2] * -1.0;
          *pfVar10 = *pfVar10 * -1.0;
        }
      }
    }
  }
LAB_80247bf4:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void ped_hitDetect(ObjInstance *this) { //80247C10
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void ped_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                undefined param5,bool shouldRender) { //80247C14
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


/* @description Free object instance */

void ped_free(ObjInstance *this,int param2) { //80247C60
  return;
}


undefined4 ped_func08(ObjInstance *this) { //80247C64
  return 0x48;
}


/* @description Get extra size for object (size of State struct) */

int ped_getExtraSize(void) { //80247C6C
  return 0x28;
}


void ped_setScale(double param_1,undefined param_2,undefined param_3,undefined param_4,
                 undefined param_5,undefined param_6,undefined param_7,undefined param_8,
                 undefined param_9,undefined param_10,undefined8 param_11) { //80248148
  uint uVar1;
  LoadedDll *pLVar2;
  ObjInstance *unaff_r26;
  ObjInstance *unaff_r30;
  short *unaff_r31;
  
  uVar1 = mainGetBit(0x5b5);
  if ((uVar1 == 0) && (uVar1 = mainGetBit(0x594), uVar1 != 0)) {
    mainSetBits(0x5b5,1);
  }
  mainSetBits(0x5b9,0);
  objDistObj2Obj(unaff_r30,unaff_r26);
  if (param_1 < (double)(float)((double)CONCAT44(0x43300000,(int)*unaff_r31 ^ 0x80000000) -
                               4503601774854144.0)) {
    *(undefined *)((int)unaff_r31 + 0xf) = 1;
    mainSetBits(0x129,0);
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,unaff_r30,0xffffffff);
    pLVar2 = (LoadedDll *)runlinkDownloadCode(0x102b,1);
    (**(code **)(pLVar2->id + 4))(unaff_r30,0,0,1,0xffffffff,0);
    DLL_free(pLVar2);
    pLVar2 = (LoadedDll *)runlinkDownloadCode(0x102c,1);
    (**(code **)(pLVar2->id + 4))(unaff_r30,0,0,1,0xffffffff,0);
    DLL_free(pLVar2);
    mainSetBits(0x126,0);
                    /* {@symbol 800e3b54} */
    (**(code **)(*(int *)pDll_projgfx + 0x20))(unaff_r31 + 6);
  }
  return;
}

