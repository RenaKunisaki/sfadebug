
/* Library Function - Single Match
    camera_func00
   
   Library: KioskDefault 0 0 */

void camcontrol_initialise(undefined4 param) { //801534B8
  PTR_DAT_803993e8 = (undefined *)&DAT_80389d60;
  memclr(&DAT_80389d60,0x120);
  initVoxMaps();
  DAT_803993f4 = 0xffffffff;
  DAT_803993f8 = 0xffffffff;
  DAT_803993fc = 0xffffffff;
  DAT_80399440 = 0;
  DAT_80399444 = 0xff;
  DAT_8039723a = 0xffff;
  return;
}


/* @description Called when DLL is unloaded */

void camcontrol_release(void) { //80153524
  FUN_8006d1e8();
  DAT_80399444 = 0xff;
  return;
}


/* Library Function - Single Match
    camera_func03
   
   Library: KioskDefault 0 0 */

void camcontrol_func03(double param1,double param2,double param3,undefined4 param4) { //8015354C
  _savefpr_29();
  memclr(PTR_DAT_803993e8,0x120);
  *(float *)(PTR_DAT_803993e8 + 0xc) = (float)param1;
  *(float *)(PTR_DAT_803993e8 + 0x10) = (float)param2;
  *(float *)(PTR_DAT_803993e8 + 0x14) = (float)param3;
  *(float *)(PTR_DAT_803993e8 + 0x18) = (float)param1;
  *(float *)(PTR_DAT_803993e8 + 0x1c) = (float)param2;
  *(float *)(PTR_DAT_803993e8 + 0x20) = (float)param3;
  *(float *)(PTR_DAT_803993e8 + 0xa4) = (float)param1;
  *(float *)(PTR_DAT_803993e8 + 0xa8) = (float)param2;
  *(float *)(PTR_DAT_803993e8 + 0xac) = (float)param3;
  *(undefined4 *)(PTR_DAT_803993e8 + 0xa0) = param4;
  *(float *)(PTR_DAT_803993e8 + 0xb0) = 60.0;
  if (pObjInteractIcon == (ObjInstance *)0x0) {
    loadObjInteractIcons();
  }
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    camera_func04
   
   Library: KioskDefault 0 0 */

void camcontrol_func04(void) { //80153604
  float fVar1;
  int iVar2;
  bool bVar5;
  int iVar3;
  undefined4 uVar4;
  short *psVar6;
  
  iVar2 = FUN_800739e8();
  bVar5 = checkSomeDebugFlags_8017c4f8();
  if (((((!bVar5) && (iVar3 = isModelAnimDisabled(), iVar3 == 0)) &&
       (iVar3 = FUN_8018d744(), iVar3 == 0)) || (bDisableModelRendering != 0)) &&
     (psVar6 = *(short **)(PTR_DAT_803993e8 + 0xa0), psVar6 != (short *)0x0)) {
    FUN_8006e924(*(int *)(psVar6 + 0x18));
    FUN_80154c84((int)psVar6);
    FUN_80154d0c();
    if (PTR_DAT_803993e8[0x11b] != '\0') {
      *(undefined4 *)(psVar6 + 6) = *(undefined4 *)(PTR_DAT_803993e8 + 0xcc);
      *(undefined4 *)(psVar6 + 8) = *(undefined4 *)(PTR_DAT_803993e8 + 0xd0);
      *(undefined4 *)(psVar6 + 10) = *(undefined4 *)(PTR_DAT_803993e8 + 0xd4);
      *(undefined4 *)(psVar6 + 0xc) = *(undefined4 *)(PTR_DAT_803993e8 + 0xcc);
      *(undefined4 *)(psVar6 + 0xe) = *(undefined4 *)(PTR_DAT_803993e8 + 0xd0);
      *(undefined4 *)(psVar6 + 0x10) = *(undefined4 *)(PTR_DAT_803993e8 + 0xd4);
      PTR_DAT_803993e8[0x11b] = 0;
    }
    if (*(int *)(psVar6 + 0x18) != 0) {
      multVectorByObjMtx((double)*(float *)(psVar6 + 6),(double)*(float *)(psVar6 + 8),
                         (double)*(float *)(psVar6 + 10),(float *)(psVar6 + 6),(float *)(psVar6 + 8)
                         ,(float *)(psVar6 + 10),*(ObjInstance **)(psVar6 + 0x18));
      *psVar6 = *psVar6 + **(short **)(psVar6 + 0x18);
    }
    if (DAT_8039940c != '\0') {
      if ((int)DAT_80399410 < 2) {
        *(float *)(PTR_DAT_803993e8 + 0xe4) = 0.0;
        PTR_DAT_803993e8[0x11d] = 0;
      }
      else {
        fVar1 = 1.0 / (float)((double)CONCAT44(0x43300000,DAT_80399410 ^ 0x80000000) -
                             4503601774854144.0);
        if ((fVar1 <= 0.0) || (1.0 < fVar1)) {
          fVar1 = 1.0;
        }
        *(float *)(PTR_DAT_803993e8 + 0xe4) = 1.0;
        *(float *)(PTR_DAT_803993e8 + 0xe8) = fVar1;
        PTR_DAT_803993e8[0x11d] = DAT_80399414;
      }
      if (*(float *)(PTR_DAT_803993e8 + 0xe4) == 1.0) {
        *(undefined4 *)(PTR_DAT_803993e8 + 0xfc) = *(undefined4 *)(PTR_DAT_803993e8 + 0xc);
        *(undefined4 *)(PTR_DAT_803993e8 + 0x100) = *(undefined4 *)(PTR_DAT_803993e8 + 0x10);
        *(undefined4 *)(PTR_DAT_803993e8 + 0x104) = *(undefined4 *)(PTR_DAT_803993e8 + 0x14);
        *(undefined2 *)(PTR_DAT_803993e8 + 0xf6) = *(undefined2 *)PTR_DAT_803993e8;
        *(undefined2 *)(PTR_DAT_803993e8 + 0xf8) = *(undefined2 *)(PTR_DAT_803993e8 + 2);
        *(undefined2 *)(PTR_DAT_803993e8 + 0xfa) = *(undefined2 *)(PTR_DAT_803993e8 + 4);
        *(undefined4 *)(PTR_DAT_803993e8 + 0x108) = *(undefined4 *)(PTR_DAT_803993e8 + 0xb0);
      }
      DAT_80399418 = DAT_803993f4;
      DAT_8039941c = DAT_80399400;
      DAT_80399420 = DAT_80399404;
      camDllFn_80154b40((ushort)DAT_803993fc,DAT_80399408);
      DAT_8039940c = '\0';
      if (DAT_80399408 != (void *)0x0) {
        mm_free(DAT_80399408);
        DAT_80399408 = (void *)0x0;
      }
    }
    if (DAT_803993f0 != 0) {
      (**(code **)(**(int **)(DAT_803993f0 + 4) + 8))(PTR_DAT_803993e8);
      FUN_80154734((short *)PTR_DAT_803993e8);
    }
    if (iVar2 != 4) {
      if (*(int *)(PTR_DAT_803993e8 + 0x10c) == 0) {
        uVar4 = FUN_80154e04((int)PTR_DAT_803993e8,psVar6);
        *(undefined4 *)(PTR_DAT_803993e8 + 0x114) = uVar4;
      }
      if (DAT_803993f4 != 0x51) {
        PTR_DAT_803993e8[0x11f] = PTR_DAT_803993e8[0x11f] & 0xfe;
      }
    }
    *(undefined4 *)(PTR_DAT_803993e8 + 0xa4) = *(undefined4 *)(PTR_DAT_803993e8 + 0xc);
    *(undefined4 *)(PTR_DAT_803993e8 + 0xa8) = *(undefined4 *)(PTR_DAT_803993e8 + 0x10);
    *(undefined4 *)(PTR_DAT_803993e8 + 0xac) = *(undefined4 *)(PTR_DAT_803993e8 + 0x14);
    PTR_DAT_803993e8[0x11e] = 0;
    FUN_80154cb8(psVar6);
  }
  return;
}


undefined * camcontrol_func05(void) { //80153970
  return PTR_DAT_803993e8;
}


undefined4 camcontrol_func06(void) { //80153978
  return DAT_803993f4;
}


undefined4 camcontrol_func07(void) { //80153980
  return DAT_803993f0;
}


/* Library Function - Single Match
    camera_func08
   
   Library: KioskDefault 0 0 */

undefined4 camcontrol_func08(void) { //80153988
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)DAT_803993ec <= iVar1) {
      return 0;
    }
    if (*(short *)(&DAT_80389e80)[iVar1] == 0x50) break;
    iVar1 = iVar1 + 1;
  }
  return (&DAT_80389e80)[iVar1];
}


/* Library Function - Single Match
    camera_func09
   
   Library: KioskDefault 0 0 */

void camcontrol_func09(undefined4 param1,undefined param2,undefined param3,uint param4,void *param5
                       ,undefined4 param6,undefined param7) { //801539F0
  if (DAT_80399408 != (void *)0x0) {
    mm_free(DAT_80399408);
    DAT_80399408 = (void *)0x0;
    DAT_8039940c = 0;
  }
  DAT_803993fc = param1;
  DAT_80399410 = param6;
  if (param5 == (void *)0x0) {
    DAT_80399408 = (void *)0x0;
  }
  else {
    DAT_80399408 = mmAlloc(param4,CAM_COL,"camcontrol1" + 1);
    memcpy_src_dst_len(param5,DAT_80399408,param4);
  }
  DAT_8039940e = param2;
  DAT_8039940d = param3;
  DAT_8039940c = 1;
  DAT_80399414 = param7;
  return;
}


void camcontrol_func1E(undefined4 param1,undefined param2) { //80153AC8
  if (DAT_80399418 != -1) {
    camcontrol_func09(DAT_80399418,(char)DAT_8039941c,(char)DAT_80399420,0,(void *)0x0,param1,
                       param2);
  }
  return;
}


void camcontrol_func1A(undefined4 param1,undefined4 param2) { //80153B18
  if (DAT_803993f0 != 0) {
    (**(code **)(**(int **)(DAT_803993f0 + 4) + 0x10))(param1,param2);
  }
  return;
}


/* Library Function - Single Match
    camera_func0A
   
   Library: KioskDefault 0 0 */

void * camcontrol_func0A(int param1) { //80153B68
  void *dest;
  
  if (param1 == 0) {
    dest = (void *)0x0;
  }
  else {
    dest = mmAlloc(0x10,CAM_COL,"camcontrol2");
    loadAsset_fileWithOffsetLength(dest,CAMACTIO.bin,(param1 + -1) * 0x10,0x10);
  }
  return dest;
}


/* Library Function - Single Match
    camera_func0B
   
   Library: KioskDefault 0 0 */

void camcontrol_func0B(int param1,uint param2) { //80153BD4
  int iVar1;
  char *unaff_r30;
  uint local_20;
  byte local_1c;
  uint local_18;
  byte local_14;
  
  if (param1 == 2) {
    local_20 = param2 & 0x7f;
    local_1c = (byte)param2 & 0x80;
    func09(0x55,1,0,8,&local_20,0x78,0xff);
    return;
  }
  if (param1 < 2) {
    if ((param1 != 0) && (-1 < param1)) {
      local_18 = param2 & 0x7f;
      local_14 = (byte)param2 & 0x80;
      func09(0x56,1,0,8,&local_18,0x78,0xff);
      return;
    }
  }
  else {
    if (param1 == 4) {
      func09(param2 + 0x50,1,0,0,(void *)0x0,0x78,0xff);
      return;
    }
    if (param1 < 4) {
      func09(0x50,0,1,0,(void *)0x0,0x78,0xff);
      return;
    }
  }
  if (param2 != 0) {
    unaff_r30 = (char *)func0A(param2);
  }
  if (unaff_r30 != (char *)0x0) {
                    /* {@symbol 8012da70} */
    iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x98))();
    *(short *)(iVar1 + 0x12) = (short)param2;
    if ((DAT_803993f4 == 0x57) || (DAT_803993f4 == 0x5a)) {
      iVar1 = func08();
      (**(code **)(**(int **)(iVar1 + 4) + 0x10))(unaff_r30,0x10);
    }
    else if (*unaff_r30 == '\x01') {
      func09(0x59,1,2,0x10,unaff_r30,0,0xff);
    }
    else {
      func09(0x50,0,2,0x10,unaff_r30,0,0xff);
    }
    mm_free(unaff_r30);
  }
  return;
}


void camcontrol_func0C(int param1) { //80153DB8
  if (param1 == *(int *)(PTR_DAT_803993e8 + 0xa0)) {
    return;
  }
  *(int *)(PTR_DAT_803993e8 + 0xa0) = param1;
  return;
}


void camcontrol_func0D(double param1,double param2,double param3) { //80153DD4
  PTR_DAT_803993e8[0x11b] = 1;
  *(float *)(PTR_DAT_803993e8 + 0xcc) = (float)param1;
  *(float *)(PTR_DAT_803993e8 + 0xd0) = (float)param2;
  *(float *)(PTR_DAT_803993e8 + 0xd4) = (float)param3;
  return;
}


void Camera_moveBy(double param1,double param2,double param3) { //80153DFC
  *(float *)(PTR_DAT_803993e8 + 0xc) = (float)((double)*(float *)(PTR_DAT_803993e8 + 0xc) + param1);
  *(float *)(PTR_DAT_803993e8 + 0x10) =
       (float)((double)*(float *)(PTR_DAT_803993e8 + 0x10) + param2);
  *(float *)(PTR_DAT_803993e8 + 0x14) =
       (float)((double)*(float *)(PTR_DAT_803993e8 + 0x14) + param3);
  return;
}


/* Library Function - Single Match
    camera_func0F
   
   Library: KioskDefault 0 0 */

void camcontrol_func0F(double param1,double param2,double param3,double param4,double param5,
                       float *param6) { //80153E30
  double dVar1;
  
  dVar1 = (double)(float)(param1 / param2);
  if ((double)(float)(param1 / param2) < param3) {
    dVar1 = param3;
  }
  *param6 = (float)dVar1;
  param6[1] = (float)param4;
  param6[2] = 0.0;
  param6[3] = (float)param5;
  return;
}


/* Library Function - Single Match
    camera_func10
   
   Library: KioskDefault 0 0 */

void camcontrol_func10(double param1,int param2,float *param3,float *param4,float *param5,
                       float *param6) { //80153E68
  int iVar1;
  double dVar2;
  
  iVar1 = *(int *)(PTR_DAT_803993e8 + 0xa0);
  *param3 = *(float *)(param2 + 0xc) - *(float *)(iVar1 + 0xc);
  *param4 = *(float *)(param2 + 0x10) - (*(float *)(iVar1 + 0x10) + (float)param1);
  *param5 = *(float *)(param2 + 0x14) - *(float *)(iVar1 + 0x14);
  if (param6 != (float *)0x0) {
    *param6 = *param3 * *param3 + *param5 * *param5;
    if (0.0 < *param6) {
      dVar2 = sqrt((double)*param6);
      *param6 = (float)dVar2;
    }
    if (*param6 < 5.0) {
      *param6 = 5.0;
    }
  }
  return;
}


undefined4 camcontrol_func11(void) { //80153F40
  return *(undefined4 *)(PTR_DAT_803993e8 + 0x10c);
}


undefined4 camcontrol_func12(void) { //80153F4C
  return *(undefined4 *)(PTR_DAT_803993e8 + 0x114);
}


void camcontrol_func14(Camera *param1) { //80153F58
  *(Camera **)(PTR_DAT_803993e8 + 0x10c) = param1;
  *(Camera **)(PTR_DAT_803993e8 + 0x114) = param1;
  return;
}


void camcontrol_func15(undefined4 param1) { //80153F6C
  *(undefined4 *)(PTR_DAT_803993e8 + 0x110) = param1;
  return;
}


uint camcontrol_func16(void) { //80153F78
  return ((uint)(byte)((0.0 < *(float *)(PTR_DAT_803993e8 + 0xe4)) << 2) << 0x1c) >> 0x1e;
}


/* Library Function - Single Match
    camera_func17
   
   Library: KioskDefault 0 0 */

void camcontrol_func17(void) { //80153F94
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ObjInstance *pOVar5;
  ObjInstance *pOVar6;
  int iVar7;
  N64Button32 NVar8;
  int iVar9;
  
  _savefpr_27();
  pOVar5 = pObjInteractIcon;
  iVar9 = *(int *)(PTR_DAT_803993e8 + 0x114);
  pOVar6 = Object_objGetMain();
  if ((pOVar5 == (ObjInstance *)0x0) || (iVar7 = FUN_800739e8(), iVar7 == 4)) goto LAB_80154438;
  PTR_DAT_803993e8[0x11f] = PTR_DAT_803993e8[0x11f] & 0xfb;
  if ((pOVar6 == (ObjInstance *)0x0) || ((pOVar6->flags_0xb0 & SeqActive) != 0)) {
    DAT_80399446 = '\0';
    goto LAB_80154438;
  }
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x78) != 0)) {
    fVar1 = (float)((double)CONCAT44(0x43300000,
                                     (uint)*(byte *)(*(int *)(iVar9 + 0x78) +
                                                    (uint)*(byte *)(iVar9 + 0xe4) * 5) << 2 ^
                                     0x80000000) - 4503601774854144.0);
    fVar3 = (pOVar6->prevPos).x -
            *(float *)(*(int *)(iVar9 + 0x74) + (uint)*(byte *)(iVar9 + 0xe4) * 0x18 + 0xc);
    fVar4 = (pOVar6->prevPos).z -
            *(float *)(*(int *)(iVar9 + 0x74) + (uint)*(byte *)(iVar9 + 0xe4) * 0x18 + 0x14);
    if ((*(byte *)(iVar9 + 0xaf) & 0x80) == 0) {
      fVar2 = (pOVar6->prevPos).y -
              *(float *)(*(int *)(iVar9 + 0x74) + (uint)*(byte *)(iVar9 + 0xe4) * 0x18 + 0x10);
    }
    else {
      fVar2 = 0.0;
    }
    if (((fVar3 * fVar3 + fVar4 * fVar4 < fVar1 * fVar1) && (-100.0 < fVar2)) && (fVar2 < 100.0)) {
      *(byte *)(iVar9 + 0xaf) = *(byte *)(iVar9 + 0xaf) | 4;
      PTR_DAT_803993e8[0x11f] = PTR_DAT_803993e8[0x11f] | 4;
    }
    if (((*(byte *)(iVar9 + 0xaf) & 4) != 0) &&
       (((uint)DAT_8039723a & 1 << (*(byte *)(*(int *)(*(int *)(iVar9 + 0x50) + 0x40) + 0x10) & 0xf)
        ) != 0)) {
      if ((*(byte *)(iVar9 + 0xaf) & 0x10) == 0) {
        NVar8 = n64GetEnabledButtonsPressed(0);
        if ((NVar8 & N64_BUTTON_A) != 0) {
          *(byte *)(iVar9 + 0xaf) = *(byte *)(iVar9 + 0xaf) | 1;
        }
      }
      else {
        NVar8 = n64GetEnabledButtonsPressed(0);
        if ((NVar8 & N64_BUTTON_A) != 0) {
          audioStartSfx((int **)0x0,0x16c,0x7f,0x40,"camcontrol.c",0x2e4);
        }
      }
    }
  }
  if (DAT_80399446 == '\x02') {
    DAT_80399448 = 0;
    pOVar5->newOpacity = 0xff;
    DAT_80399446 = '\x03';
    audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"camcontrol.c",0x2fa);
  }
  else if (DAT_80399446 < '\x02') {
    if ((DAT_80399446 == '\0') || (DAT_80399446 < '\0')) {
LAB_801541c0:
      DAT_80399448 = 0;
      pOVar5->newOpacity = 0xff;
      if (iVar9 != 0) {
        DAT_80399446 = '\x02';
      }
    }
    else {
      iVar7 = (uint)pOVar5->newOpacity + (uint)framesThisStep * -0xc;
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      pOVar5->newOpacity = (u8)iVar7;
      if (pOVar5->newOpacity == 0) {
        DAT_80399446 = '\0';
      }
      else {
        DAT_80399445 = DAT_80399445 - framesThisStep;
        (pOVar5->pos).pos.y = timeDelta * 2.0 + (pOVar5->pos).pos.y;
        (pOVar5->prevPos).y = timeDelta * 2.0 + (pOVar5->prevPos).y;
      }
      if (iVar9 != 0) {
        DAT_80399446 = '\x02';
      }
    }
  }
  else if (DAT_80399446 == '\x04') {
    if ((iVar9 == 0) || ((*(byte *)(iVar9 + 0xaf) & 0x28) != 0)) {
      audioStartSfx((int **)0x0,0x15a,0x7f,0x40,"camcontrol.c",0x313);
      DAT_80399446 = '\x01';
    }
    else {
      if (DAT_803993f4 != 0x57) {
        DAT_80399446 = '\x03';
      }
      *(byte *)(iVar9 + 0xaf) = *(byte *)(iVar9 + 0xaf) | 2;
      if (DAT_80399445 < '\x01') {
        if (0x200 < DAT_80399448) {
          DAT_80399448 = DAT_80399448 + (ushort)framesThisStep * -8;
        }
        if (DAT_80399448 < 0x200) {
          DAT_80399448 = 0x200;
        }
      }
      else {
        DAT_80399445 = DAT_80399445 - framesThisStep;
        DAT_80399448 = 0x400;
      }
    }
  }
  else {
    if ('\x03' < DAT_80399446) goto LAB_801541c0;
    if (((iVar9 == 0) || (DAT_803993f4 == 0x52)) || ((*(byte *)(iVar9 + 0xaf) & 0x28) != 0)) {
      audioStartSfx((int **)0x0,0x15a,0x7f,0x40,"camcontrol.c",0x301);
      DAT_80399446 = '\x01';
    }
    else {
      if (DAT_803993f4 == 0x57) {
        audioStartSfx((int **)0x0,0x158,0x7f,0x40,"camcontrol.c",0x308);
        DAT_80399446 = '\x04';
        DAT_80399445 = '<';
      }
      if (0 < DAT_80399448) {
        DAT_80399448 = DAT_80399448 + (ushort)framesThisStep * -8;
      }
    }
  }
  if (DAT_80399448 < 0) {
    DAT_80399448 = 0;
  }
  (pOVar5->pos).rotation.x = (pOVar5->pos).rotation.x + DAT_80399448 * (ushort)framesThisStep;
LAB_80154438:
  _restfpr_27();
  return;
}


/* Library Function - Single Match
    camera_func18
   
   Library: KioskDefault 0 0 */

void camcontrol_func18(Gfx **param1,undefined4 *param2,undefined4 *param3,undefined4 *param4) { //80154454
  uint uVar1;
  int iVar2;
  
  iVar2 = FUN_800739e8();
  if (iVar2 != 4) {
    DAT_80397238 = 0xffff;
    uVar1 = countLeadingZeros(0x57 - DAT_803993f4);
    drawObjInteractIcon(*(int *)(PTR_DAT_803993e8 + 0x114),uVar1 >> 5,param1,param2,param3,param4);
    *(undefined4 *)(PTR_DAT_803993e8 + 0x110) = 0;
  }
  return;
}


/* Library Function - Single Match
    camera_func19
   
   Library: KioskDefault 0 0 */

void camcontrol_func19(int param1,int param2) { //801544D0
  if ((char)PTR_DAT_803993e8[0x119] < param1) {
    PTR_DAT_803993e8[0x119] = (char)param1;
    PTR_DAT_803993e8[0x11a] = 2;
    if (param2 != 0) {
      FUN_8006901c((short)param1);
    }
  }
  return;
}


void camcontrol_func1C(byte param1) { //8015453C
  PTR_DAT_803993e8[0x11e] = PTR_DAT_803993e8[0x11e] | param1;
  return;
}


/* Library Function - Single Match
    camera_func13
   
   Library: KioskDefault 0 0 */

void camcontrol_func13(int param1) { //80154550
  if (param1 != 0) {
    PTR_DAT_803993e8[0x11f] = PTR_DAT_803993e8[0x11f] | 2;
    return;
  }
  PTR_DAT_803993e8[0x11f] = PTR_DAT_803993e8[0x11f] & 0xfd;
  return;
}


void camcontrol_func1D(int param1) { //80154580
  PTR_DAT_803993e8[0x11f] = PTR_DAT_803993e8[0x11f] | (byte)(param1 << 3) & 0x18;
  return;
}


int camcontrol_func1B(void) { //801553B4
  return (int)DAT_80397238;
}

