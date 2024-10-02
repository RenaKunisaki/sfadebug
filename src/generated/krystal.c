
/* Library Function - Single Match
    krystal_objGetAnimChange
   
   Library: KioskDefault 0 0 */

void krystalFn_8019a5d0(double param1,ObjInstance *param2,uint *param3) { //8019A5D0
  char cVar1;
  float fVar2;
  uint uVar3;
  undefined4 uVar4;
  BOOL BVar5;
  int iVar6;
  undefined *puVar7;
  bool bVar8;
  double dVar9;
  double dVar10;
  double local_68;
  
  _savefpr_27();
  puVar7 = param2->state;
  if (*(char *)((int)param3 + 0x272) != '\0') {
    puVar7[0x8bd] = 0;
    *(float *)(puVar7 + 0x3c8) = 2.3994;
    *(undefined2 *)(puVar7 + 0x884) = 0;
    param3[0xbf] = (uint)FUN_8019abec;
  }
  BVar5 = krystalIsClaw(param2);
  if (BVar5 == FALSE) {
    if (*(int *)(puVar7 + 0x864) != 0) {
      *(undefined ***)(puVar7 + 0x3c0) = &PTR_DAT_8030e5c0;
      *(undefined **)(puVar7 + 0x3c4) = &DAT_8030e680;
      cVar1 = puVar7[0x86c];
      goto joined_r0x8019a6a8;
    }
    if (puVar7[0x8a4] == '\0') {
      *(undefined2 **)(puVar7 + 0x3c0) = &DAT_8030e560;
      *(undefined **)(puVar7 + 0x3c4) = &DAT_8030e680;
    }
    else {
      *(undefined **)(puVar7 + 0x3c0) = &DAT_8030e590;
      *(undefined **)(puVar7 + 0x3c4) = &DAT_8030e680;
    }
  }
  else if (*(int *)(puVar7 + 0x864) == 0) {
    *(undefined **)(puVar7 + 0x3c0) = &DAT_8030e620;
    *(undefined **)(puVar7 + 0x3c4) = &DAT_8030e680;
  }
  else {
    *(wchar_t **)(puVar7 + 0x3c0) = u_________________________8030e650;
    *(undefined **)(puVar7 + 0x3c4) = &DAT_8030e680;
    cVar1 = puVar7[0x86c];
joined_r0x8019a6a8:
    if (cVar1 == '\0') goto LAB_8019abd0;
  }
  puVar7[0x8ba] = puVar7[0x8ba] & 0xfe;
  *param3 = *param3 | 0x800000;
  iVar6 = FUN_8019b758(param2,(int)param3);
  if (((iVar6 == 0) && (((float)param3[0x6d] <= 25.0 || (120.0 <= (float)param3[0x6b])))) &&
     ((*(int *)(puVar7 + 0x864) != 0 ||
      ((iVar6 = FUN_8019b09c(param1,param2,(int)param3), iVar6 == 0 && (param3[0xb2] == 0)))))) {
    if ((*(char *)((int)param3 + 0x272) != '\0') &&
       ((*(short *)((int)param3 + 0x26e) != 10 && (*(short *)((int)param3 + 0x26e) != 0xc)))) {
      (param2->pos).rotation.x = (param2->pos).rotation.x + *(short *)((int)param3 + 0x32a) * 0xb6;
      *(undefined2 *)(param3 + 0xca) = 0;
      *(undefined2 *)((int)param3 + 0x32a) = 0;
    }
    if ((float)param3[0xa4] < 0.05) {
      *(undefined2 *)(param3 + 0xca) = 0;
      *(undefined2 *)((int)param3 + 0x32a) = 0;
      param3[0xa4] = (uint)0.0;
    }
    fVar2 = ((float)param3[0xa4] - 0.4) / 0.6;
    if (0.0 <= fVar2) {
      if (1.0 < fVar2) {
        fVar2 = 1.0;
      }
    }
    else {
      fVar2 = 0.0;
    }
    dVar10 = (double)(fVar2 * (*(float *)(puVar7 + 0x3c8) - 0.05));
    if (*(short *)(param3 + 0xca) < 0x5a) {
      (param2->pos).rotation.x =
           (short)(int)(((float)((double)(float)((double)CONCAT44(0x43300000,
                                                                  (int)*(short *)((int)param3 +
                                                                                 0x32a) ^ 0x80000000
                                                                 ) - 4503601774854144.0) * param1) /
                        9.0) * 182.0 +
                       (float)((double)CONCAT44(0x43300000,
                                                (int)(param2->pos).rotation.x ^ 0x80000000) -
                              4503601774854144.0));
    }
    else {
      dVar10 = -dVar10;
    }
    param3[0xa3] = (uint)(float)(param1 * (double)((float)(dVar10 - (double)(float)param3[0xa3]) /
                                                  (float)param3[0xac]) + (double)(float)param3[0xa3]
                                );
    if (*(short *)(param3 + 0x66) < 1) {
      local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(param3 + 0x66) ^ 0x80000000);
      dVar9 = (double)distanceFn_80293e80((double)(((float)(local_68 - 4503601774854144.0) *
                                                   3.141593) / 32767.0));
      dVar10 = dVar9 * 0.3499999940395355 - dVar10;
    }
    else {
      local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(param3 + 0x66) ^ 0x80000000);
      dVar9 = (double)distanceFn_80293e80((double)(((float)(local_68 - 4503601774854144.0) *
                                                   3.141593) / 32767.0));
      dVar10 = dVar9 * 0.6499999761581421 - dVar10;
    }
    fVar2 = -(float)dVar10;
    if (*(float *)(puVar7 + 0x3c8) < (float)param3[0xa3]) {
      param3[0xa3] = *(uint *)(puVar7 + 0x3c8);
    }
    if (fVar2 < *(float *)(*(int *)(puVar7 + 0x3c4) + 8)) {
      fVar2 = *(float *)(*(int *)(puVar7 + 0x3c4) + 8);
    }
    param3[0x9e] = (uint)(float)(param1 * (double)((fVar2 - (float)param3[0x9e]) /
                                                  (float)param3[0xac]) + (double)(float)param3[0x9e]
                                );
    if (*(float *)(puVar7 + 0x3c8) < (float)param3[0x9e]) {
      param3[0x9e] = *(uint *)(puVar7 + 0x3c8);
    }
    bVar8 = false;
    dVar10 = (double)param2->animTimer;
    uVar3 = (int)(char)puVar7[0x8bd] / 3;
    puVar7[0x8a1] = (char)((int)(uVar3 * 2 | uVar3 >> 0x1f) >> 1) + '\x01';
    if (4 < (byte)puVar7[0x8a1]) {
      puVar7[0x8a1] = 4;
    }
    if ((byte)puVar7[0x8a1] < 4) {
      uVar4 = *(undefined4 *)(puVar7 + 0x88c);
    }
    else {
      uVar4 = *(undefined4 *)(puVar7 + 0x890);
    }
    *(undefined4 *)(puVar7 + 0x898) = uVar4;
    if (*(float *)(*(int *)(puVar7 + 0x3c4) + uVar3 * 8) <= (float)param3[0xa3]) {
      if ((*(float *)(*(int *)(puVar7 + 0x3c4) + (uVar3 * 2 + 1) * 4) <= (float)param3[0xa3]) &&
         ((char)puVar7[0x8bd] < '\x0f')) {
        if (puVar7[0x8bd] == '\0') {
          dVar10 = 0.0;
        }
        puVar7[0x8bd] = puVar7[0x8bd] + '\x03';
        bVar8 = true;
      }
    }
    else {
      if (puVar7[0x8bd] == '\x03') goto LAB_8019abd0;
      puVar7[0x8bd] = puVar7[0x8bd] + -3;
      bVar8 = true;
    }
    if ((bVar8) || (*(int *)(puVar7 + 0x3c0) != *(int *)(puVar7 + 0x3c0))) {
      Object_ObjAnimSetMove
                (dVar10,param2,(int)*(short *)(*(int *)(puVar7 + 0x3c0) + (char)puVar7[0x8bd] * 2),0
                );
    }
    local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(param3 + 0x66) ^ 0x80000000);
    fVar2 = (float)(local_68 - 4503601774854144.0) / 8192.0;
    if (-1.0 <= fVar2) {
      if (1.0 < fVar2) {
        fVar2 = 1.0;
      }
    }
    else {
      fVar2 = -1.0;
    }
    bVar8 = 0.0 < fVar2;
    if (fVar2 < 0.0) {
      fVar2 = -fVar2;
    }
    FUN_80087afc((int)param2,
                 (int)*(short *)(*(int *)(puVar7 + 0x3c0) +
                                ((int)(char)puVar7[0x8bd] + bVar8 + 1) * 2),
                 (short)(int)(fVar2 * 16384.0));
    iVar6 = objGetAnimChange((double)(float)param3[0x9e],(int)param2,(float *)(param3 + 0xa6));
    if (iVar6 == 0) {
      diPrintf("krystal.c: objGetAnimChange Error");
    }
  }
LAB_8019abd0:
  _restfpr_27();
  return;
}

