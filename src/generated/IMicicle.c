
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void IMicicle_initialise(undefined4 param) { //80223288
  DAT_80399e70 = 0;
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func01
    dll_184_func01
    dll_210_func07
    dll_243_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void IMicicle_release(void) { //80223294
  if (DAT_80399e70 != (LoadedDll *)0x0) {
    DLL_free(DAT_80399e70);
  }
  DAT_80399e70 = (LoadedDll *)0x0;
  return;
}


/* Library Function - Single Match
    dll_184_func03
   
   Library: KioskDefault 0 0 */

void IMicicle_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802232CC
  undefined *puVar1;
  HitState *pHVar2;
  Shadow *pSVar3;
  
  puVar1 = this->state;
  puVar1[8] = 0;
  *(float *)(puVar1 + 4) = (this->pos).pos.y;
  *(undefined2 *)(puVar1 + 0xc) = *(undefined2 *)&objDef[1].bound;
  (this->pos).scale =
       (float)((double)CONCAT44(0x43300000,(uint)objDef[1].mapStates1) - 4503599627370496.0) / 127.0
  ;
  pHVar2 = this->hitstate;
  if (pHVar2 != (HitState *)0x0) {
    pHVar2->field16_0x52 =
         (ushort)(int)((float)((double)CONCAT44(0x43300000,
                                                (int)(short)pHVar2->field16_0x52 ^ 0x80000000) -
                              4503601774854144.0) * (this->pos).scale);
    pHVar2->field18_0x56 =
         (short)(int)((float)((double)CONCAT44(0x43300000,(int)pHVar2->field18_0x56 ^ 0x80000000) -
                             4503601774854144.0) * (this->pos).scale);
    pHVar2->field17_0x54 =
         (short)(int)((float)((double)CONCAT44(0x43300000,(int)pHVar2->field17_0x54 ^ 0x80000000) -
                             4503601774854144.0) * (this->pos).scale);
    pHVar2->flags = pHVar2->flags & 0xfffe;
  }
  pSVar3 = this->shadow;
  if (pSVar3 != (Shadow *)0x0) {
    pSVar3->flags = pSVar3->flags | 0xb0;
    pSVar3->flags = pSVar3->flags | 0xc00;
    (pSVar3->pos).x = (this->pos).pos.x;
    (pSVar3->pos).z = (this->pos).pos.z;
    pSVar3->field0_0x0 = pSVar3->field0_0x0 * (this->pos).scale;
  }
  return;
}


/* Library Function - Single Match
    dll_184_func04
   
   Library: KioskDefault 0 0 */

void IMicicle_update(ObjInstance *this) { //80223428
  byte bVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ObjInstance *pOVar6;
  uint uVar7;
  int iVar8;
  ObjDef *pOVar9;
  Shadow *pSVar10;
  HitState *pHVar11;
  float *pfVar12;
  double dVar13;
  double dVar14;
  
  _savefpr_30();
  pfVar12 = (float *)this->state;
  pHVar11 = this->hitstate;
  pSVar10 = this->shadow;
  pOVar9 = this->def;
  if (DAT_80399e70 == (DLL_func **)0x0) {
    DAT_80399e70 = runlinkDownloadCode(0x1003,1);
  }
  if (*(char *)((int)pfVar12 + 10) == '\0') {
    dVar13 = (double)FUN_80223894((int)this);
    *pfVar12 = (float)dVar13;
    if (*(char *)((int)pfVar12 + 10) != '\0') {
      (pSVar10->pos).y = *pfVar12;
      FUN_800b2858();
    }
  }
  else {
    if (pSVar10 != (Shadow *)0x0) {
      dVar13 = (double)pfVar12[1];
      fVar2 = ((this->pos).pos.y - *pfVar12) / (float)(dVar13 - (double)*pfVar12);
      if (fVar2 <= 1.0) {
        if (fVar2 < 0.0) {
          fVar2 = 0.0;
        }
      }
      else {
        fVar2 = 1.0;
      }
      dVar14 = (double)(1.0 - fVar2);
      pOVar6 = Object_objGetMain();
      if (pOVar6 == (ObjInstance *)0x0) {
        dVar13 = 350.0;
      }
      else {
        objDistObj2Obj(this,pOVar6);
        if (dVar13 <= 350.0) {
          if (dVar13 < 250.0) {
            dVar13 = 250.0;
          }
        }
        else {
          dVar13 = 350.0;
        }
      }
      pSVar10->opacity =
           (u8)(int)(((float)((double)CONCAT44(0x43300000,(uint)this->opacity) - 4503599627370496.0)
                     / 255.0) *
                    (float)((double)CONCAT44(0x43300000,(int)(dVar14 * 120.0) + 0x40U ^ 0x80000000)
                           - 4503601774854144.0) * (1.0 - (float)(dVar13 - 250.0) / 100.0));
    }
    sVar4._0_1_ = pOVar9[1].loadFlags;
    sVar4._1_1_ = pOVar9[1].mapStates2;
    if ((sVar4 == -1) ||
       (sVar3._0_1_ = pOVar9[1].loadFlags, sVar3._1_1_ = pOVar9[1].mapStates2,
       uVar7 = mainGetBit((int)sVar3), uVar7 != 0)) {
      bVar1 = *(byte *)(pfVar12 + 2);
      if (bVar1 == 2) {
        (pHVar11->field12_0x3c).y = 2.242078e-44;
        (pHVar11->field12_0x3c).z = 2.242078e-44;
        *(undefined *)&pHVar11->flags_0x60 = 1;
        *(undefined *)((int)&pHVar11->sizeX2 + 1) = 0xd;
      }
      else if (bVar1 < 2) {
        if (bVar1 == 0) {
          pOVar6 = Object_objGetMain();
          iVar8 = FUN_8022398c(this,pOVar6);
          if ((iVar8 != 0) &&
             (sVar4 = *(short *)(pfVar12 + 3), uVar5 = (ushort)framesThisStep,
             *(ushort *)(pfVar12 + 3) = sVar4 - uVar5, (short)(sVar4 - uVar5) < 1)) {
            *(undefined *)(pfVar12 + 2) = 1;
          }
        }
        else if (true) {
          if (*(char *)((int)pfVar12 + 9) == '\0') {
            *(undefined *)((int)pfVar12 + 9) = 1;
            (this->vel).y = 0.0;
            audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                                (double)(this->prevPos).z,0xfd,0x7f,"IMicicle.c",
                                (int *)0xbd);
            audioTryStartSfx((int *)this,8,0x22e,0x7f,"IMicicle.c",0xbe);
            pHVar11->flags = pHVar11->flags | 1;
          }
          (pHVar11->field12_0x3c).y = 2.242078e-44;
          (pHVar11->field12_0x3c).z = 2.242078e-44;
          *(undefined *)&pHVar11->flags_0x60 = 1;
          *(undefined *)((int)&pHVar11->sizeX2 + 1) = 0xd;
          (this->vel).y = timeDelta * -0.15 + (this->vel).y;
          (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
          if ((this->pos).pos.y < *pfVar12 + 20.0) {
            (this->pos).pos.y = *pfVar12 + 20.0;
            *(undefined *)(pfVar12 + 2) = 2;
          }
        }
      }
      if (pHVar11->field13_0x48 != 0) {
        pHVar11->flags = pHVar11->flags & 0xfffe;
        *(undefined *)(pfVar12 + 2) = 3;
        FUN_80068a9c((uint)this,8);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0xfe,0x7f,"IMicicle.c",(int *)0xef);
        (**(code **)(*DAT_80399e70 + 4))(this,0xe,0,0x10000002,0xffffffff,0);
      }
      (this->vel).x = 0.0;
      (this->vel).z = 0.0;
    }
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void IMicicle_hitDetect(ObjInstance *this) { //80223808
  return;
}


/* Library Function - Single Match
    dll_184_func06
   
   Library: KioskDefault 0 0 */

void IMicicle_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8022380C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((this->state[8] != '\x03') && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void IMicicle_free(ObjInstance *this,int param2) { //80223880
  return;
}


undefined4 IMicicle_func08(ObjInstance *this) { //80223884
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int IMicicle_getExtraSize(void) { //8022388C
  return 0x10;
}

