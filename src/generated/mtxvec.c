
/* Library Function - Single Match
    MTXMultVec
   
   Library: KioskDefault 0 0 */

void MTXMultVec(Mtx43 *m,vec3f *src,vec3f *dst) { //80010458
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  if (m == (Mtx43 *)0x0) {
                    
    OSPanic("mtxvec.c",0x39,"MTXMultVec():  NULL MtxPtr 'm' ");
  }
  if (src == (vec3f *)0x0) {
                    
    OSPanic("mtxvec.c",0x3a,"MTXMultVec():  NULL MtxPtr 'src' ");
  }
  if (dst == (vec3f *)0x0) {
                    
    OSPanic("mtxvec.c",0x3b,"MTXMultVec():  NULL MtxPtr 'dst' ");
  }
  fVar1 = m->m24;
  fVar2 = m->m23;
  fVar3 = src->z;
  fVar4 = m->m21;
  fVar5 = src->x;
  fVar6 = m->m22;
  fVar7 = src->y;
  fVar8 = m->m34;
  fVar9 = m->m33;
  fVar10 = src->z;
  fVar11 = m->m31;
  fVar12 = src->x;
  fVar13 = m->m32;
  fVar14 = src->y;
  dst->x = m->m14 + m->m13 * src->z + m->m11 * src->x + m->m12 * src->y;
  dst->y = fVar1 + fVar2 * fVar3 + fVar4 * fVar5 + fVar6 * fVar7;
  dst->z = fVar8 + fVar9 * fVar10 + fVar11 * fVar12 + fVar13 * fVar14;
  return;
}


/* Library Function - Single Match
    MTXMultVecArray
   
   Library: KioskDefault 0 0 */

void MTXMultVecArray(float *param1,float *param2,float *param3,uint param4) { //800105A4
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  
  if (param1 == (float *)0x0) {
                    
    OSPanic("mtxvec.c",0x9f,"MTXMultVecArray():  NULL MtxPtr 'm' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("mtxvec.c",0xa0,"MTXMultVecArray():  NULL MtxPtr 'srcBase' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("mtxvec.c",0xa1,"MTXMultVecArray():  NULL MtxPtr 'dstBase' ");
  }
  for (uVar15 = 0; uVar15 < param4; uVar15 = uVar15 + 1) {
    fVar1 = param1[7];
    fVar2 = param1[6];
    fVar3 = param2[2];
    fVar4 = param1[4];
    fVar5 = *param2;
    fVar6 = param1[5];
    fVar7 = param2[1];
    fVar8 = param1[0xb];
    fVar9 = param1[10];
    fVar10 = param2[2];
    fVar11 = param1[8];
    fVar12 = *param2;
    fVar13 = param1[9];
    fVar14 = param2[1];
    *param3 = param1[3] + param1[2] * param2[2] + *param1 * *param2 + param1[1] * param2[1];
    param3[1] = fVar1 + fVar2 * fVar3 + fVar4 * fVar5 + fVar6 * fVar7;
    param3[2] = fVar8 + fVar9 * fVar10 + fVar11 * fVar12 + fVar13 * fVar14;
    param2 = param2 + 3;
    param3 = param3 + 3;
  }
  return;
}


/* Library Function - Single Match
    MTXMultVecSR
   
   Library: KioskDefault 0 0 */

void MTXMultVecSR(float *param1,float *param2,float *param3) { //80010750
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  if (param1 == (float *)0x0) {
                    
    OSPanic("mtxvec.c",0x13a,"MTXMultVecSR():  NULL MtxPtr 'm' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("mtxvec.c",0x13b,"MTXMultVecSR():  NULL MtxPtr 'src' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("mtxvec.c",0x13c,"MTXMultVecSR():  NULL MtxPtr 'dst' ");
  }
  fVar1 = param1[6];
  fVar2 = param2[2];
  fVar3 = param1[4];
  fVar4 = *param2;
  fVar5 = param1[5];
  fVar6 = param2[1];
  fVar7 = param1[10];
  fVar8 = param2[2];
  fVar9 = param1[8];
  fVar10 = *param2;
  fVar11 = param1[9];
  fVar12 = param2[1];
  *param3 = param1[2] * param2[2] + *param1 * *param2 + param1[1] * param2[1];
  param3[1] = fVar1 * fVar2 + fVar3 * fVar4 + fVar5 * fVar6;
  param3[2] = fVar7 * fVar8 + fVar9 * fVar10 + fVar11 * fVar12;
  return;
}

