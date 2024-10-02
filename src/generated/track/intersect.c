
/* Library Function - Single Match
    trackIntersectFn_800b8ef8
   
   Library: KioskDefault 0 0 */

void trackIntersectFn_800b8ef8
               (double param1,float *param2,float *param3,float *param4,float *param5,float *param6,
               uint param7) { //800B8EF8
  float fVar1;
  int iVar2;
  short sVar3;
  double dVar4;
  double dVar5;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_40;
  uint uStack_3c;
  
  _savefpr_29();
  if (((param7 & 0xff) == 3) || ((param7 & 0xff) == 6)) {
    *param4 = *param5;
    param4[1] = param5[1];
    param4[2] = param5[2];
    local_5c = *param4 - *param3;
    local_58 = param4[1] - param3[1];
    local_54 = param4[2] - param3[2];
    vec3f_normalize_8002282c(&local_5c);
    sVar3 = 0;
    do {
      if (param1 <= (double)(param6[3] +
                            param4[2] * param6[2] + *param4 * *param6 + param4[1] * param6[1]))
      break;
      *param4 = -(local_5c * 0.1 - *param4);
      param4[1] = -(local_58 * 0.1 - param4[1]);
      param4[2] = -(local_54 * 0.1 - param4[2]);
      sVar3 = sVar3 + 1;
    } while (sVar3 < 0x65);
  }
  else if (0.707 <= param6[1]) {
    if ((param7 & 0xff) != 2) {
      param4[1] = param5[1];
      dVar4 = (double)(float)(param1 - (double)(param6[3] +
                                               param4[2] * param6[2] +
                                               *param4 * *param6 + param4[1] * param6[1]));
      if (0.0 < dVar4) {
        sqrt((double)(*param6 * *param6 + param6[2] * param6[2]));
        iVar2 = getAngle();
        uStack_3c = (int)(short)iVar2 ^ 0x80000000;
        local_40 = 0x43300000;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_3c)
                                                             - 4503601774854144.0) * 3.141593) /
                                                    32767.0));
        param4[1] = (float)(dVar4 / dVar5) * param6[1] + param4[1];
      }
    }
  }
  else if ((param7 & 0xff) == 4) {
    *param4 = *param5;
    param4[1] = param5[1];
    param4[2] = param5[2];
    local_5c = *param4 - *param3;
    local_58 = param4[1] - param3[1];
    local_54 = param4[2] - param3[2];
    dVar4 = sqrt((double)(local_5c * local_5c + local_54 * local_54));
    if (dVar4 <= 0.0) {
      local_5c = 1.0;
      local_54 = 0.0;
    }
    else {
      local_5c = (float)((double)local_5c / dVar4);
      local_54 = (float)((double)local_54 / dVar4);
    }
    sVar3 = 0;
    do {
      if (param1 <= (double)(param6[3] +
                            param4[2] * param6[2] + *param4 * *param6 + param4[1] * param6[1]))
      goto LAB_800b93cc;
      *param4 = -(local_5c * 0.1 - *param4);
      param4[2] = -(local_54 * 0.1 - param4[2]);
      sVar3 = sVar3 + 1;
    } while (sVar3 < 0x65);
    printf("1: track/intersect.c: OVERFLOW error");
  }
  else {
    fVar1 = (param6[3] + param4[2] * param6[2] + *param4 * *param6 + param4[1] * param6[1]) * 2.0;
    *param4 = -(fVar1 * *param6 - *param4);
    param4[1] = -(fVar1 * param6[1] - param4[1]);
    param4[2] = -(fVar1 * param6[2] - param4[2]);
    fVar1 = (param4[2] * param2[8] + *param4 * param2[6] + param4[1] * param2[7]) -
            (param2[8] * param2[2] + param2[6] * *param2 + param2[7] * param2[1]);
    local_50 = *param2 + param2[6] * fVar1;
    local_4c = param2[1] + param2[7] * fVar1;
    local_48 = param2[2] + param2[8] * fVar1;
    local_5c = *param4 - local_50;
    local_58 = param4[1] - local_4c;
    local_54 = param4[2] - local_48;
    vec3f_normalize_8002282c(&local_5c);
    local_5c = (float)((double)local_5c * param1);
    local_58 = (float)((double)local_58 * param1);
    local_54 = (float)((double)local_54 * param1);
    *param4 = local_50 + local_5c;
    param4[1] = local_4c + local_58;
    param4[2] = local_48 + local_54;
  }
LAB_800b93cc:
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    trackIntersectFn_800b93e8
   
   Library: KioskDefault 0 0 */

void trackIntersectFn_800b93e8
               (double param1,double param2,float *param3,float *param4,float *param5,float *param6,
               uint param7) { //800B93E8
  float fVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  double dVar5;
  double dVar6;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  uint uStack_3c;
  
  _savefpr_28();
  if (((param7 & 0xff) == 3) || ((param7 & 0xff) == 6)) {
    *param4 = *param5;
    param4[1] = param5[1];
    param4[2] = param5[2];
    local_4c = *param4 - *param3;
    local_48 = param4[1] - param3[1];
    local_44 = param4[2] - param3[2];
    vec3f_normalize_8002282c(&local_4c);
    sVar4 = 0;
    do {
      if (param2 <= (double)(param6[3] +
                            param4[2] * param6[2] + *param4 * *param6 + param4[1] * param6[1]))
      break;
      *param4 = -(local_4c * 0.1 - *param4);
      param4[1] = -(local_48 * 0.1 - param4[1]);
      param4[2] = -(local_44 * 0.1 - param4[2]);
      sVar4 = sVar4 + 1;
    } while (sVar4 < 0x65);
  }
  else if (0.707 <= param6[1]) {
    uVar2 = param7 & 0xff;
    if (uVar2 == 5) {
      *param4 = -(float)(param1 * (double)*param6 - (double)*param4);
      param4[1] = -(float)(param1 * (double)param6[1] - (double)param4[1]);
      param4[2] = -(float)(param1 * (double)param6[2] - (double)param4[2]);
      fVar1 = (float)(param2 - (double)(param6[3] +
                                       param4[2] * param6[2] +
                                       *param4 * *param6 + param4[1] * param6[1]));
      *param4 = fVar1 * *param6 + *param4;
      param4[1] = fVar1 * param6[1] + param4[1];
      param4[2] = fVar1 * param6[2] + param4[2];
    }
    else if ((4 < uVar2) || (uVar2 != 2)) {
      param4[1] = param5[1];
      dVar6 = (double)(float)(param2 - (double)(param6[3] +
                                               param4[2] * param6[2] +
                                               *param4 * *param6 + param4[1] * param6[1]));
      if (0.0 < dVar6) {
        sqrt((double)(*param6 * *param6 + param6[2] * param6[2]));
        iVar3 = getAngle();
        uStack_3c = (int)(short)iVar3 ^ 0x80000000;
        local_40 = 0x43300000;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_3c)
                                                             - 4503601774854144.0) * 3.141593) /
                                                    32767.0));
        param4[1] = (float)(dVar6 / dVar5) * param6[1] + param4[1];
      }
    }
  }
  else {
    uVar2 = param7 & 0xff;
    if (uVar2 == 4) {
      *param4 = *param5;
      param4[1] = param5[1];
      param4[2] = param5[2];
      local_4c = *param4 - *param3;
      local_48 = param4[1] - param3[1];
      local_44 = param4[2] - param3[2];
      dVar6 = sqrt((double)(local_4c * local_4c + local_44 * local_44));
      if (dVar6 <= 0.0) {
        local_4c = 1.0;
        local_44 = 0.0;
      }
      else {
        local_4c = (float)((double)local_4c / dVar6);
        local_44 = (float)((double)local_44 / dVar6);
      }
      sVar4 = 0;
      do {
        if (param2 <= (double)(param6[3] +
                              param4[2] * param6[2] + *param4 * *param6 + param4[1] * param6[1]))
        goto LAB_800b9960;
        *param4 = -(local_4c * 0.1 - *param4);
        param4[2] = -(local_44 * 0.1 - param4[2]);
        sVar4 = sVar4 + 1;
      } while (sVar4 < 0x65);
      printf("2: track/intersect.c: OVERFLOW error");
    }
    else if ((uVar2 < 4) && (uVar2 == 1)) {
      *param4 = -(float)(param1 * (double)*param6 - (double)*param4);
      param4[2] = -(float)(param1 * (double)param6[2] - (double)param4[2]);
      dVar6 = (double)(float)(param2 - (double)(param6[3] +
                                               param4[2] * param6[2] +
                                               *param4 * *param6 + param4[1] * param6[1]));
      if (0.0 < dVar6) {
        sqrt((double)(*param6 * *param6 + param6[2] * param6[2]));
        iVar3 = getAngle();
        uStack_3c = (int)(short)iVar3 ^ 0x80000000;
        local_40 = 0x43300000;
        dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_3c) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
        ;
        if (0.0 < dVar5) {
          dVar6 = (double)(float)(dVar6 / dVar5);
        }
        *param4 = (float)(dVar6 * (double)*param6 + (double)*param4);
        param4[2] = (float)(dVar6 * (double)param6[2] + (double)param4[2]);
      }
    }
    else {
      *param4 = -(float)(param1 * (double)*param6 - (double)*param4);
      param4[1] = -(float)(param1 * (double)param6[1] - (double)param4[1]);
      param4[2] = -(float)(param1 * (double)param6[2] - (double)param4[2]);
      fVar1 = (float)(param2 - (double)(param6[3] +
                                       param4[2] * param6[2] +
                                       *param4 * *param6 + param4[1] * param6[1]));
      *param4 = fVar1 * *param6 + *param4;
      param4[1] = fVar1 * param6[1] + param4[1];
      param4[2] = fVar1 * param6[2] + param4[2];
    }
  }
LAB_800b9960:
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    trackIntersectFn_800b997c
   
   Library: KioskDefault 0 0 */

void trackIntersectFn_800b997c
               (undefined8 param_1,double param2,float *param3,float *param4,float *param5,
               float *param6,float *param7,uint param8) { //800B997C
  float fVar1;
  int iVar2;
  short sVar3;
  double dVar4;
  double dVar5;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_30();
  if (((param8 & 0xff) == 3) || ((param8 & 0xff) == 6)) {
    *param5 = *param6;
    param5[1] = param6[1];
    param5[2] = param6[2];
    local_48 = *param5 - *param4;
    local_44 = param5[1] - param4[1];
    local_40 = param5[2] - param4[2];
    vec3f_normalize_8002282c(&local_48);
    sVar3 = 0;
    do {
      if (param2 <= (double)(param7[3] +
                            param5[2] * param7[2] + *param5 * *param7 + param5[1] * param7[1]))
      break;
      *param5 = -(local_48 * 0.1 - *param5);
      param5[1] = -(local_44 * 0.1 - param5[1]);
      param5[2] = -(local_40 * 0.1 - param5[2]);
      sVar3 = sVar3 + 1;
    } while (sVar3 < 0x65);
  }
  else if (0.707 <= param7[1]) {
    if ((param8 & 0xff) != 2) {
      param5[1] = param6[1];
      dVar4 = (double)(float)(param2 - (double)(param7[3] +
                                               param5[2] * param7[2] +
                                               *param5 * *param7 + param5[1] * param7[1]));
      if (0.0 < dVar4) {
        sqrt((double)(*param7 * *param7 + param7[2] * param7[2]));
        iVar2 = getAngle();
        uStack_34 = (int)(short)iVar2 ^ 0x80000000;
        local_38 = 0x43300000;
        dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_34)
                                                             - 4503601774854144.0) * 3.141593) /
                                                    32767.0));
        param5[1] = (float)(dVar4 / dVar5) * param7[1] + param5[1];
      }
    }
  }
  else if ((param8 & 0xff) == 4) {
    *param5 = *param6;
    param5[1] = param6[1];
    param5[2] = param6[2];
    local_48 = *param5 - *param4;
    local_44 = param5[1] - param4[1];
    local_40 = param5[2] - param4[2];
    dVar4 = sqrt((double)(local_48 * local_48 + local_40 * local_40));
    if (dVar4 <= 0.0) {
      local_48 = 1.0;
      local_40 = 0.0;
    }
    else {
      local_48 = (float)((double)local_48 / dVar4);
      local_40 = (float)((double)local_40 / dVar4);
    }
    sVar3 = 0;
    do {
      if (param2 <= (double)(param7[3] +
                            param5[2] * param7[2] + *param5 * *param7 + param5[1] * param7[1]))
      goto LAB_800b9db0;
      *param5 = -(local_48 * 0.1 - *param5);
      param5[2] = -(local_40 * 0.1 - param5[2]);
      sVar3 = sVar3 + 1;
    } while (sVar3 < 0x65);
    printf("3: track/intersect.c: OVERFLOW error");
  }
  else {
    fVar1 = (param7[3] + param5[2] * param7[2] + *param5 * *param7 + param5[1] * param7[1]) * 2.0;
    *param5 = -(fVar1 * *param7 - *param5);
    param5[1] = -(fVar1 * param7[1] - param5[1]);
    param5[2] = -(fVar1 * param7[2] - param5[2]);
    local_48 = *param5 - *param3;
    local_44 = param5[1] - param3[1];
    local_40 = param5[2] - param3[2];
    vec3f_normalize_8002282c(&local_48);
    local_48 = (float)((double)local_48 * param2);
    local_44 = (float)((double)local_44 * param2);
    local_40 = (float)((double)local_40 * param2);
    *param5 = *param3 + local_48;
    param5[1] = param3[1] + local_44;
    param5[2] = param3[2] + local_40;
  }
LAB_800b9db0:
  _restfpr_30();
  return;
}

