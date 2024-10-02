
/* Library Function - Single Match
    MtxIdentity
   
   Library: KioskDefault 0 0 */

void MtxIdentity(Mtx43 *m) { //8000E938
  if (m == (Mtx43 *)0x0) {
                    
    OSPanic("mtx.c",0xa1,"MtxIdentity():  NULL Mtx 'm' ");
  }
  m->m11 = 1.0;
  m->m12 = 0.0;
  m->m13 = 0.0;
  m->m14 = 0.0;
  m->m21 = 0.0;
  m->m22 = 1.0;
  m->m23 = 0.0;
  m->m24 = 0.0;
  m->m31 = 0.0;
  m->m32 = 0.0;
  m->m33 = 1.0;
  m->m34 = 0.0;
  return;
}


/* Library Function - Single Match
    MTXCopy
   
   Library: KioskDefault 0 0 */

void MTXCopy(Mtx43 *src,Mtx43 *dst) { //8000E9E0
  if (src == (Mtx43 *)0x0) {
                    
    OSPanic("mtx.c",0xde,"MTXCopy():  NULL MtxPtr 'src' ");
  }
  if (dst == (Mtx43 *)0x0) {
                    
    OSPanic("mtx.c",0xdf,"MTXCopy():  NULL MtxPtr 'dst' ");
  }
  if (src != dst) {
    dst->m11 = src->m11;
    dst->m12 = src->m12;
    dst->m13 = src->m13;
    dst->m14 = src->m14;
    dst->m21 = src->m21;
    dst->m22 = src->m22;
    dst->m23 = src->m23;
    dst->m24 = src->m24;
    dst->m31 = src->m31;
    dst->m32 = src->m32;
    dst->m33 = src->m33;
    dst->m34 = src->m34;
  }
  return;
}


/* Library Function - Single Match
    MTXConcat
   
   Library: KioskDefault 0 0 */

void MTXConcat(Mtx43 *a,Mtx43 *b,Mtx43 *ab) { //8000EAB4
  Mtx43 *out;
  Mtx43 local_4c;
  
  if (a == (Mtx43 *)0x0) {
                    
    OSPanic("mtx.c",0x128,"MTXConcat():  NULL MtxPtr 'a'  ");
  }
  if (b != (Mtx43 *)0x0) {
    if (ab != (Mtx43 *)0x0) {
      if ((ab == a) || (out = ab, ab == b)) {
        out = &local_4c;
      }
      out->m11 = a->m13 * b->m31 + a->m11 * b->m11 + a->m12 * b->m21;
      out->m12 = a->m13 * b->m32 + a->m11 * b->m12 + a->m12 * b->m22;
      out->m13 = a->m13 * b->m33 + a->m11 * b->m13 + a->m12 * b->m23;
      out->m14 = a->m14 + a->m13 * b->m34 + a->m11 * b->m14 + a->m12 * b->m24;
      out->m21 = a->m23 * b->m31 + a->m21 * b->m11 + a->m22 * b->m21;
      out->m22 = a->m23 * b->m32 + a->m21 * b->m12 + a->m22 * b->m22;
      out->m23 = a->m23 * b->m33 + a->m21 * b->m13 + a->m22 * b->m23;
      out->m24 = a->m24 + a->m23 * b->m34 + a->m21 * b->m14 + a->m22 * b->m24;
      out->m31 = a->m33 * b->m31 + a->m31 * b->m11 + a->m32 * b->m21;
      out->m32 = a->m33 * b->m32 + a->m31 * b->m12 + a->m32 * b->m22;
      out->m33 = a->m33 * b->m33 + a->m31 * b->m13 + a->m32 * b->m23;
      out->m34 = a->m34 + a->m33 * b->m34 + a->m31 * b->m14 + a->m32 * b->m24;
      if (out == &local_4c) {
        MTXCopy(&local_4c,ab);
      }
      return;
    }
                    
    OSPanic("mtx.c",0x12a,"MTXConcat():  NULL MtxPtr 'ab' ");
  }
                    
  OSPanic("mtx.c",0x129,"MTXConcat():  NULL MtxPtr 'b'  ");
}


/* Library Function - Single Match
    MTXInverse
   
   Library: KioskDefault 0 0 */

undefined4 MTXInverse(Mtx43 *param1,Mtx43 *param2) { //8000EE08
  float fVar1;
  undefined4 uVar2;
  Mtx43 *pMVar3;
  Mtx43 local_48;
  
  if (param1 == (Mtx43 *)0x0) {
                    
    OSPanic("mtx.c",0x290,"MTXInverse():  NULL MtxPtr 'src' ");
  }
  if (param2 != (Mtx43 *)0x0) {
    pMVar3 = param2;
    if (param1 == param2) {
      pMVar3 = &local_48;
    }
    fVar1 = (((param1->m32 * param1->m13 * param1->m21 +
              param1->m33 * param1->m11 * param1->m22 + param1->m31 * param1->m12 * param1->m23) -
             param1->m13 * param1->m31 * param1->m22) - param1->m33 * param1->m21 * param1->m12) -
            param1->m23 * param1->m11 * param1->m32;
    if (fVar1 == 0.0) {
      uVar2 = 0;
    }
    else {
      fVar1 = 1.0 / fVar1;
      pMVar3->m11 = fVar1 * (param1->m22 * param1->m33 - param1->m32 * param1->m23);
      pMVar3->m12 = fVar1 * -(param1->m12 * param1->m33 - param1->m32 * param1->m13);
      pMVar3->m13 = fVar1 * (param1->m12 * param1->m23 - param1->m22 * param1->m13);
      pMVar3->m21 = fVar1 * -(param1->m21 * param1->m33 - param1->m31 * param1->m23);
      pMVar3->m22 = fVar1 * (param1->m11 * param1->m33 - param1->m31 * param1->m13);
      pMVar3->m23 = fVar1 * -(param1->m11 * param1->m23 - param1->m21 * param1->m13);
      pMVar3->m31 = fVar1 * (param1->m21 * param1->m32 - param1->m31 * param1->m22);
      pMVar3->m32 = fVar1 * -(param1->m11 * param1->m32 - param1->m31 * param1->m12);
      pMVar3->m33 = fVar1 * (param1->m11 * param1->m22 - param1->m21 * param1->m12);
      pMVar3->m14 = (-pMVar3->m11 * param1->m14 - pMVar3->m12 * param1->m24) -
                    pMVar3->m13 * param1->m34;
      pMVar3->m24 = (-pMVar3->m21 * param1->m14 - pMVar3->m22 * param1->m24) -
                    pMVar3->m23 * param1->m34;
      pMVar3->m34 = (-pMVar3->m31 * param1->m14 - pMVar3->m32 * param1->m24) -
                    pMVar3->m33 * param1->m34;
      if (pMVar3 == &local_48) {
        MTXCopy(&local_48,param2);
      }
      uVar2 = 1;
    }
    return uVar2;
  }
                    
  OSPanic("mtx.c",0x291,"MTXInverse():  NULL MtxPtr 'inv' ");
}


/* Library Function - Single Match
    MTXRotRad
   
   Library: KioskDefault 0 0 */

void MTXRotRad(double param1,float *param2,char param3) { //8000F16C
  double param1_00;
  double param2_00;
  
  _savefpr_29();
  if (param2 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x48b,"MTXRotRad():  NULL MtxPtr 'm' ");
  }
  param1_00 = mathFn_80063544(param1);
  param2_00 = mathFn_800633b0(param1);
  MTXRotTrig(param1_00,param2_00,param2,param3);
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    MTXRotTrig
   
   Library: KioskDefault 0 0 */

void MTXRotTrig(double param1,double param2,float *param3,char param4) { //8000F20C
  _savefpr_30();
  if (param3 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x4af,"MTXRotTrig():  NULL MtxPtr 'm' ");
  }
  if (param4 == 'x') {
LAB_8000f2b0:
    *param3 = 1.0;
    param3[1] = 0.0;
    param3[2] = 0.0;
    param3[3] = 0.0;
    param3[4] = 0.0;
    param3[5] = (float)param2;
    param3[6] = (float)-param1;
    param3[7] = 0.0;
    param3[8] = 0.0;
    param3[9] = (float)param1;
    param3[10] = (float)param2;
    param3[0xb] = 0.0;
  }
  else {
    if (param4 < 'x') {
      if (param4 != 'Y') {
        if ('X' < param4) {
          if ('Z' < param4) goto LAB_8000f3b8;
          goto LAB_8000f360;
        }
        if (param4 < 'X') {
LAB_8000f3b8:
                    
          OSPanic("mtx.c",0x4cb,"MTXRotTrig():  invalid 'axis' value ");
        }
        goto LAB_8000f2b0;
      }
    }
    else {
      if (param4 == 'z') {
LAB_8000f360:
        *param3 = (float)param2;
        param3[1] = (float)-param1;
        param3[2] = 0.0;
        param3[3] = 0.0;
        param3[4] = (float)param1;
        param3[5] = (float)param2;
        param3[6] = 0.0;
        param3[7] = 0.0;
        param3[8] = 0.0;
        param3[9] = 0.0;
        param3[10] = 1.0;
        param3[0xb] = 0.0;
        goto LAB_8000f3e4;
      }
      if ('y' < param4) goto LAB_8000f3b8;
    }
    *param3 = (float)param2;
    param3[1] = 0.0;
    param3[2] = (float)param1;
    param3[3] = 0.0;
    param3[4] = 0.0;
    param3[5] = 1.0;
    param3[6] = 0.0;
    param3[7] = 0.0;
    param3[8] = (float)-param1;
    param3[9] = 0.0;
    param3[10] = (float)param2;
    param3[0xb] = 0.0;
  }
LAB_8000f3e4:
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    MTXRotAxisRad
   
   Library: KioskDefault 0 0 */

void MTXRotAxisRad(double param1,float *param2,float *param3) { //8000F400
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float local_64;
  float local_60;
  float local_5c;
  
  _savefpr_22();
  if (param2 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x50b,"MTXRotAxisRad():  NULL MtxPtr 'm' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x50c,"MTXRotAxisRad():  NULL VecPtr 'axis' ");
  }
  dVar1 = mathFn_80063544(param1);
  dVar2 = mathFn_800633b0(param1);
  dVar6 = (double)(float)(1.0 - dVar2);
  VECNormalize(param3,&local_64);
  dVar5 = (double)local_64;
  dVar4 = (double)local_60;
  dVar3 = (double)local_5c;
  *param2 = (float)(dVar2 + (double)(float)(dVar6 * (double)(float)(dVar5 * dVar5)));
  param2[1] = (float)(dVar4 * (double)(float)(dVar6 * dVar5)) - (float)(dVar1 * dVar3);
  param2[2] = (float)(dVar3 * (double)(float)(dVar6 * dVar5)) + (float)(dVar1 * dVar4);
  param2[3] = 0.0;
  param2[4] = (float)(dVar4 * (double)(float)(dVar6 * dVar5)) + (float)(dVar1 * dVar3);
  param2[5] = (float)(dVar2 + (double)(float)(dVar6 * (double)(float)(dVar4 * dVar4)));
  param2[6] = (float)(dVar3 * (double)(float)(dVar6 * dVar4)) - (float)(dVar1 * dVar5);
  param2[7] = 0.0;
  param2[8] = (float)(dVar3 * (double)(float)(dVar6 * dVar5)) - (float)(dVar1 * dVar4);
  param2[9] = (float)(dVar3 * (double)(float)(dVar6 * dVar4)) + (float)(dVar1 * dVar5);
  param2[10] = (float)(dVar2 + (double)(float)(dVar6 * (double)(float)(dVar3 * dVar3)));
  param2[0xb] = 0.0;
  _restfpr_22();
  return;
}


/* Library Function - Single Match
    MTXTrans
   
   Library: KioskDefault 0 0 */

void MTXTrans(double param1,double param2,double param3,float *param4) { //8000F5A0
  if (param4 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x547,"MTXTrans():  NULL MtxPtr 'm' ");
  }
  *param4 = 1.0;
  param4[1] = 0.0;
  param4[2] = 0.0;
  param4[3] = (float)param1;
  param4[4] = 0.0;
  param4[5] = 1.0;
  param4[6] = 0.0;
  param4[7] = (float)param2;
  param4[8] = 0.0;
  param4[9] = 0.0;
  param4[10] = 1.0;
  param4[0xb] = (float)param3;
  return;
}


/* Library Function - Single Match
    MTXScale
   
   Library: KioskDefault 0 0 */

void MTXScale(double param1,double param2,double param3,float *param4) { //8000F668
  if (param4 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x58a,"MTXScale():  NULL MtxPtr 'm' ");
  }
  *param4 = (float)param1;
  param4[1] = 0.0;
  param4[2] = 0.0;
  param4[3] = 0.0;
  param4[4] = 0.0;
  param4[5] = (float)param2;
  param4[6] = 0.0;
  param4[7] = 0.0;
  param4[8] = 0.0;
  param4[9] = 0.0;
  param4[10] = (float)param3;
  param4[0xb] = 0.0;
  return;
}


/* Library Function - Single Match
    MTXLightPerspective
   
   Library: KioskDefault 0 0 */

void MTXLightPerspective(double param1,double param2,double param3,double param4,double param5,
                        double param6,float *param7) { //8000F730
  double dVar1;
  
  _savefpr_28();
  if (param7 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x6df,"MTXLightPerspective():  NULL MtxPtr 'm' ");
  }
  if ((0.0 < param1) && (param1 < 180.0)) {
    if (param2 == 0.0) {
                    
      OSPanic("mtx.c",0x6e1,"MTXLightPerspective():  'aspect' is 0 ");
    }
    dVar1 = mathFn_802947cc((double)((float)(param1 * 0.5) * 0.01745329));
    *param7 = (float)param3 * (float)((double)(float)(1.0 / dVar1) / param2);
    param7[1] = 0.0;
    param7[2] = -(float)param5;
    param7[3] = 0.0;
    param7[4] = 0.0;
    param7[5] = (float)((double)(float)(1.0 / dVar1) * (double)(float)param4);
    param7[6] = -(float)param6;
    param7[7] = 0.0;
    param7[8] = 0.0;
    param7[9] = 0.0;
    param7[10] = -1.0;
    param7[0xb] = 0.0;
    _restfpr_28();
    return;
  }
                    
  OSPanic("mtx.c",0x6e0,"MTXLightPerspective():  'fovY' out of range ");
}


/* Library Function - Single Match
    MTXLightOrtho
   
   Library: KioskDefault 0 0 */

void MTXLightOrtho(double param1,double param2,double param3,double param4,double param5,
                  double param6,double param7,double param8,float *param9) { //8000F8C0
  float fVar1;
  
  _savefpr_25();
  if (param9 == (float *)0x0) {
                    
    OSPanic("mtx.c",0x720,"MTXLightOrtho():  NULL MtxPtr 'm' ");
  }
  if (param1 == param2) {
                    
    OSPanic("mtx.c",0x721,"MTXLightOrtho():  't' and 'b' clipping planes are equal ");
  }
  if (param3 == param4) {
                    
    OSPanic("mtx.c",0x722,"MTXLightOrtho():  'l' and 'r' clipping planes are equal ");
  }
  fVar1 = 1.0 / (float)(param4 - param3);
  *param9 = (float)((double)(fVar1 * 2.0) * param5);
  param9[1] = 0.0;
  param9[2] = 0.0;
  param9[3] = (float)param7 + (float)(param5 * (double)(fVar1 * -(float)(param4 + param3)));
  fVar1 = 1.0 / (float)(param1 - param2);
  param9[4] = 0.0;
  param9[5] = (float)((double)(fVar1 * 2.0) * param6);
  param9[6] = 0.0;
  param9[7] = (float)param8 + (float)(param6 * (double)(fVar1 * -(float)(param1 + param2)));
  param9[8] = 0.0;
  param9[9] = 0.0;
  param9[10] = 0.0;
  param9[0xb] = 1.0;
  _restfpr_25();
  return;
}

