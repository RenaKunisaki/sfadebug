
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void windlift_initialise(undefined4 param) { //80204860
  return;
}


/* @description Called when DLL is unloaded */

void windlift_release(void) { //80204864
  return;
}


/* Library Function - Single Match
    dll_15D_func03
   
   Library: KioskDefault 0 0 */

void windlift_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //80204868
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  piVar5[1] = (int)sVar1;
  *piVar5 = piVar5[1] + -0x58;
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  piVar5[2] = (int)sVar2;
  piVar5[4] = (int)2.0;
  piVar5[5] = 0;
  uVar3 = mainGetBit(0x57);
  if ((uVar3 != 0) || (3 < *piVar5)) {
    piVar5[5] = 0x3c;
  }
  for (iVar4 = 0; iVar4 < 0xe; iVar4 = iVar4 + 1) {
    FUN_8020536c(piVar5 + iVar4 * 6 + 6);
  }
  return;
}


/* Library Function - Single Match
    dll_15D_func04
   
   Library: KioskDefault 0 0 */

void windlift_update(ObjInstance *this) { //80204914
  short sVar1;
  uint uVar2;
  bool bVar6;
  ObjInstance *pOVar3;
  uint uVar4;
  ObjInstance **ppOVar5;
  ObjDef *pOVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  double dVar12;
  int local_44;
  undefined4 local_40;
  uint uStack_3c;
  
  _savefpr_30();
  puVar11 = (uint *)this->state;
  pOVar7 = this->def;
  uVar2 = mainGetBit(0x57);
  if ((uVar2 != 0) || (4 < (int)*puVar11)) {
    uVar2 = puVar11[5];
    puVar11[5] = uVar2 + 1;
    if (((int)uVar2 < 0x3c) && (uVar2 = mainGetBit(puVar11[1]), uVar2 == 0)) {
      (this->pos).rotation.x =
           (this->pos).rotation.x -
           (short)((int)((uint)framesThisStep * 100 * puVar11[5] * puVar11[5]) / 0x3c);
      uStack_3c = puVar11[5] ^ 0x80000000;
      local_40 = 0x43300000;
      dVar12 = (double)((float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) / 60.0
                       + 1.0);
      audioTryStartSfx((int *)this,0xc0,0x8e,0x7f,"windlift.c",0xa8);
      FUN_800689dc(dVar12,(int)this,0x40,0x7f);
      objSetModelNo(this,0);
    }
    else {
      objSetModelNo(this,1);
      uVar2 = mainGetBit(puVar11[2]);
      if (uVar2 == 0) {
        (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * -0xccc;
      }
      else {
        (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * -0x9f4;
      }
      bVar6 = FUN_80068b20((int)this,0x40);
      if (bVar6) {
        if (uVar2 == 0) {
          puVar11[4] = (uint)((2.0 - (float)puVar11[4]) * 0.03125 + (float)puVar11[4]);
        }
        else {
          puVar11[4] = (uint)((1.0 - (float)puVar11[4]) * 0.03125 + (float)puVar11[4]);
        }
        FUN_800689dc((double)(float)puVar11[4],(int)this,0x40,0x7f);
      }
      else {
        audioTryStartSfx((int *)this,0x40,0x8e,0x7f,"windlift.c",0xb5);
      }
      sVar1._0_1_ = pOVar7[1].allocatedSize;
      sVar1._1_1_ = pOVar7[1].mapStates1;
      uStack_3c = (int)sVar1 ^ 0x80000000;
      local_40 = 0x43300000;
      dVar12 = (double)(float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
      pOVar3 = Object_objGetMain();
      uVar4 = mainGetBit(puVar11[1]);
      if (uVar4 == 0) {
        if (*(char *)(puVar11 + 0x5b) < '\0') {
                    /* {@symbol 8011bc64} */
          (**(code **)(*(int *)pDll05_2 + 4))
                    (pOVar3,0x128,"windlift.c",0xc9,"AMB_WINDLIFTOUT");
          *(byte *)(puVar11 + 0x5b) = *(byte *)(puVar11 + 0x5b) & 0x7f;
        }
        if ((*(byte *)(puVar11 + 10) & 0xe0) != 0) {
          FUN_801a83b4(0.0,(int)pOVar3);
          if ((*(byte *)(puVar11 + 10) & 0xe) != 0) {
            *(byte *)(puVar11 + 10) = *(byte *)(puVar11 + 10) | 2;
          }
          puVar11[9] = (uint)0.0;
          *(undefined *)((int)puVar11 + 0x29) = 0;
          *(byte *)(puVar11 + 10) = *(byte *)(puVar11 + 10) & 0xe;
        }
      }
      else {
        if (-1 < *(char *)(puVar11 + 0x5b)) {
          *(byte *)(puVar11 + 0x5b) = *(byte *)(puVar11 + 0x5b) & 0x7f | 0x80;
                    /* {@symbol 8011bc64} */
          (**(code **)(*(int *)pDll05_2 + 4))
                    (pOVar3,0x11f,"windlift.c",0xc4,"AMB_WINDLIFT");
        }
        if (pOVar3 != (ObjInstance *)0x0) {
          FUN_80204e70(dVar12,this,pOVar3,(int)(puVar11 + 6),uVar2,1,*puVar11);
        }
      }
      ppOVar5 = Object_playerGetObject(0x18,&local_44);
      local_44 = local_44 + 1;
      if (0xe < local_44) {
        local_44 = 0xe;
      }
      for (iVar10 = 1; iVar10 < 0xe; iVar10 = iVar10 + 1) {
        puVar11[iVar10 * 6 + 0xb] = 0xffffffff;
      }
      for (iVar10 = 1; iVar10 < local_44; iVar10 = iVar10 + 1) {
        uVar4 = 0xffffffff;
        for (uVar8 = 1; (int)uVar8 < 0xe; uVar8 = uVar8 + 1) {
          if ((ObjInstance *)puVar11[uVar8 * 6 + 6] == *ppOVar5) {
            uVar4 = uVar8;
          }
        }
        if (uVar4 == 0xffffffff) {
          uVar8 = 1;
          while ((int)uVar8 < 0xe) {
            uVar9 = uVar8;
            if (puVar11[uVar8 * 6 + 6] == 0) {
              FUN_8020536c(puVar11 + uVar8 * 6 + 6);
              uVar9 = 2000;
              uVar4 = uVar8;
            }
            uVar8 = uVar9 + 1;
          }
          if (uVar4 == 0xffffffff) goto LAB_80204de0;
          puVar11[uVar4 * 6 + 6] = (uint)*ppOVar5;
        }
        puVar11[uVar4 * 6 + 0xb] = uVar4;
        if (((*ppOVar5)->flags_0xb0 & SeqActive) == 0) {
          if (*ppOVar5 != (ObjInstance *)0x0) {
            pOVar3 = *ppOVar5;
            ppOVar5 = ppOVar5 + 1;
            FUN_80204e70(dVar12,this,pOVar3,(int)(puVar11 + uVar4 * 6 + 6),uVar2,0,*puVar11);
          }
        }
        else {
          ppOVar5 = ppOVar5 + 1;
        }
      }
      for (iVar10 = 1; iVar10 < 0xe; iVar10 = iVar10 + 1) {
        if (puVar11[iVar10 * 6 + 0xb] == 0xffffffff) {
          puVar11[iVar10 * 6 + 6] = 0;
        }
      }
    }
  }
LAB_80204de0:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void windlift_hitDetect(ObjInstance *this) { //80204DFC
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void windlift_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80204E00
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void windlift_free(ObjInstance *this,int param2) { //80204E5C
  return;
}


undefined4 windlift_func08(ObjInstance *this) { //80204E60
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int windlift_getExtraSize(void) { //80204E68
  return 0x170;
}

