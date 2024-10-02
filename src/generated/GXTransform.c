
/* Library Function - Single Match
    GXSetProjection
   
   Library: KioskDefault 0 0 */

void GXSetProjection(undefined4 *param1,int param2) { //8002C8C4
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0xcd,"'GXSetProjection' is not allowed between GXBegin/GXEnd");
  }
  *(int *)&gx->field_0x420 = param2;
  *(undefined4 *)&gx->field_0x424 = *param1;
  *(undefined4 *)&gx->field_0x42c = param1[5];
  *(undefined4 *)&gx->field_0x434 = param1[10];
  *(undefined4 *)&gx->field_0x438 = param1[0xb];
  if (param2 == 1) {
    *(undefined4 *)&gx->field_0x428 = param1[3];
    *(undefined4 *)&gx->field_0x430 = param1[7];
  }
  else {
    *(undefined4 *)&gx->field_0x428 = param1[2];
    *(undefined4 *)&gx->field_0x430 = param1[6];
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x61020;
  GXFIFO = *(undefined4 *)&gx->field_0x424;
  if ((true) && (true)) {
    pGxDebug->projMtx[0] = *(float *)&gx->field_0x424;
    pGxDebug->isRegInit[0x1020] = 1;
  }
  GXFIFO = *(undefined4 *)&gx->field_0x428;
  if ((true) && (true)) {
    pGxDebug->projMtx[1] = *(float *)&gx->field_0x428;
    pGxDebug->isRegInit[0x1021] = 1;
  }
  GXFIFO = *(undefined4 *)&gx->field_0x42c;
  if ((true) && (true)) {
    pGxDebug->projMtx[2] = *(float *)&gx->field_0x42c;
    pGxDebug->isRegInit[0x1022] = 1;
  }
  GXFIFO = *(undefined4 *)&gx->field_0x430;
  if ((true) && (true)) {
    pGxDebug->projMtx[3] = *(float *)&gx->field_0x430;
    pGxDebug->isRegInit[0x1023] = 1;
  }
  GXFIFO = *(undefined4 *)&gx->field_0x434;
  if ((true) && (true)) {
    pGxDebug->projMtx[4] = *(float *)&gx->field_0x434;
    pGxDebug->isRegInit[0x1024] = 1;
  }
  GXFIFO = *(undefined4 *)&gx->field_0x438;
  if ((true) && (true)) {
    pGxDebug->projMtx[5] = *(float *)&gx->field_0x438;
    pGxDebug->isRegInit[0x1025] = 1;
  }
  GXFIFO = *(undefined4 *)&gx->field_0x420;
  if ((true) && (true)) {
    *(undefined4 *)&pGxDebug->field_0xa0 = *(undefined4 *)&gx->field_0x420;
    pGxDebug->isRegInit[0x1026] = 1;
  }
  gx->field2_0x2 = 0;
  return;
}


/* Library Function - Single Match
    gxGetFn_8002cc00
   
   Library: KioskDefault 0 0 */

void gxGetFn_8002cc00(GxStruct1 *param1) { //8002CC00
  if (param1 == (GxStruct1 *)0x0) {
                    
    OSPanic("GXTransform.c",0x12e,"GXGet*: invalid null pointer");
  }
  param1->field0_0x0 =
       (float)((double)CONCAT44(0x43300000,*(undefined4 *)&gx->field_0x420) - 4503599627370496.0);
  param1->field1_0x4 = *(undefined4 *)&gx->field_0x424;
  param1->field2_0x8 = *(undefined4 *)&gx->field_0x428;
  param1->field3_0xc = *(undefined4 *)&gx->field_0x42c;
  param1->field4_0x10 = *(undefined4 *)&gx->field_0x430;
  param1->field5_0x14 = *(undefined4 *)&gx->field_0x434;
  param1->field6_0x18 = *(undefined4 *)&gx->field_0x438;
  return;
}


/* Library Function - Single Match
    GXLoadPosMtxImm
   
   Library: KioskDefault 0 0 */

void GXLoadPosMtxImm(Mtx43 *mtx,int idx) { //8002CCB8
  float fVar1;
  uint uVar2;
  int iVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x1d8,"'GXLoadPosMtxImm' is not allowed between GXBegin/GXEnd");
  }
  uVar2 = idx * 4;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = uVar2 | 0xb0000;
  fVar1 = mtx->m11;
  GXFIFO = mtx->m11;
  if (uVar2 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x80) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x7b)) = 1;
  }
  else if (uVar2 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x400) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd50] = 1;
  }
  else if (uVar2 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x500) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb0] = 1;
  }
  else if (uVar2 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x600) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb0] = 1;
  }
  else {
    iVar3 = uVar2 - 0x1000;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2] = 1;
    }
  }
  fVar1 = mtx->m12;
  GXFIFO = mtx->m12;
  if (uVar2 + 1 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x84) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x7a)) = 1;
  }
  else if (uVar2 + 1 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3ff) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd51] = 1;
  }
  else if (uVar2 + 1 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4ff) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb1] = 1;
  }
  else if (uVar2 + 1 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5ff) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb1] = 1;
  }
  else {
    iVar3 = uVar2 - 0xfff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 1] = 1;
    }
  }
  fVar1 = mtx->m13;
  GXFIFO = mtx->m13;
  if (uVar2 + 2 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x88) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x79)) = 1;
  }
  else if (uVar2 + 2 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3fe) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd52] = 1;
  }
  else if (uVar2 + 2 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4fe) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb2] = 1;
  }
  else if (uVar2 + 2 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5fe) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb2] = 1;
  }
  else {
    iVar3 = uVar2 - 0xffe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 2] = 1;
    }
  }
  fVar1 = mtx->m14;
  GXFIFO = mtx->m14;
  if (uVar2 + 3 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x8c) = fVar1;
    *(undefined *)(pGxDebug[1].projMtx + idx + -0x1e) = 1;
  }
  else if (uVar2 + 3 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3fd) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd53] = 1;
  }
  else if (uVar2 + 3 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4fd) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb3] = 1;
  }
  else if (uVar2 + 3 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5fd) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb3] = 1;
  }
  else {
    iVar3 = uVar2 - 0xffd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 3] = 1;
    }
  }
  fVar1 = mtx->m21;
  GXFIFO = mtx->m21;
  if (uVar2 + 4 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x90) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x77)) = 1;
  }
  else if (uVar2 + 4 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3fc) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd54] = 1;
  }
  else if (uVar2 + 4 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4fc) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb4] = 1;
  }
  else if (uVar2 + 4 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5fc) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb4] = 1;
  }
  else {
    iVar3 = uVar2 - 0xffc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 4] = 1;
    }
  }
  fVar1 = mtx->m22;
  GXFIFO = mtx->m22;
  if (uVar2 + 5 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x94) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x76)) = 1;
  }
  else if (uVar2 + 5 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3fb) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd55] = 1;
  }
  else if (uVar2 + 5 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4fb) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb5] = 1;
  }
  else if (uVar2 + 5 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5fb) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb5] = 1;
  }
  else {
    iVar3 = uVar2 - 0xffb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 5] = 1;
    }
  }
  fVar1 = mtx->m23;
  GXFIFO = mtx->m23;
  if (uVar2 + 6 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x98) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x75)) = 1;
  }
  else if (uVar2 + 6 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3fa) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd56] = 1;
  }
  else if (uVar2 + 6 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4fa) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb6] = 1;
  }
  else if (uVar2 + 6 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5fa) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb6] = 1;
  }
  else {
    iVar3 = uVar2 - 0xffa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 6] = 1;
    }
  }
  fVar1 = mtx->m24;
  GXFIFO = mtx->m24;
  if (uVar2 + 7 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0x9c) = fVar1;
    *(undefined *)(pGxDebug[1].projMtx + idx + -0x1d) = 1;
  }
  else if (uVar2 + 7 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3f9) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd57] = 1;
  }
  else if (uVar2 + 7 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4f9) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb7] = 1;
  }
  else if (uVar2 + 7 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5f9) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb7] = 1;
  }
  else {
    iVar3 = uVar2 - 0xff9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 7] = 1;
    }
  }
  fVar1 = mtx->m31;
  GXFIFO = mtx->m31;
  if (uVar2 + 8 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0xa0) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x73)) = 1;
  }
  else if (uVar2 + 8 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3f8) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd58] = 1;
  }
  else if (uVar2 + 8 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4f8) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb8] = 1;
  }
  else if (uVar2 + 8 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5f8) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb8] = 1;
  }
  else {
    iVar3 = uVar2 - 0xff8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 8] = 1;
    }
  }
  fVar1 = mtx->m32;
  GXFIFO = mtx->m32;
  if (uVar2 + 9 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0xa4) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x72)) = 1;
  }
  else if (uVar2 + 9 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3f7) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd59] = 1;
  }
  else if (uVar2 + 9 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4f7) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb9] = 1;
  }
  else if (uVar2 + 9 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5f7) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcb9] = 1;
  }
  else {
    iVar3 = uVar2 - 0xff7;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 9] = 1;
    }
  }
  fVar1 = mtx->m33;
  GXFIFO = mtx->m33;
  if (uVar2 + 10 < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0xa8) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar2 - 0x71)) = 1;
  }
  else if (uVar2 + 10 < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3f6) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd5a] = 1;
  }
  else if (uVar2 + 10 < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4f6) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcba] = 1;
  }
  else if (uVar2 + 10 < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5f6) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcba] = 1;
  }
  else {
    iVar3 = uVar2 - 0xff6;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 10] = 1;
    }
  }
  fVar1 = mtx->m34;
  GXFIFO = mtx->m34;
  if (uVar2 + 0xb < 0x400) {
    *(float *)(pGxDebug->isRegInit + idx * 0x10 + 0xac) = fVar1;
    *(undefined *)(pGxDebug[1].projMtx + idx + -0x1c) = 1;
  }
  else if (uVar2 + 0xb < 0x500) {
    *(float *)((int)pGxDebug + (uVar2 - 0x3f5) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xd5b] = 1;
  }
  else if (uVar2 + 0xb < 0x600) {
    *(float *)((int)pGxDebug + (uVar2 - 0x4f5) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcbb] = 1;
  }
  else if (uVar2 + 0xb < 0x680) {
    *(float *)((int)pGxDebug + (uVar2 - 0x5f5) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar2 + 0xcbb] = 1;
  }
  else {
    iVar3 = uVar2 - 0xff5;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(float *)((int)pGxDebug + iVar3 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar2 + 0xb] = 1;
    }
  }
  return;
}


/* Library Function - Single Match
    GXLoadNrmMtxImm
   
   Library: KioskDefault 0 0 */

void GXLoadNrmMtxImm(undefined4 *param1,int param2) { //8002DB3C
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x229,"'GXLoadNrmMtxImm' is not allowed between GXBegin/GXEnd");
  }
  iVar2 = param2 * 3;
  uVar4 = iVar2 + 0x400;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = uVar4 | 0x80000;
  uVar1 = *param1;
  GXFIFO = *param1;
  if (uVar4 < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x4b) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x345] = 1;
  }
  else if (uVar4 < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x480) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x45] = 1;
  }
  else if (uVar4 < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x200) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x1b) = 1;
  }
  else if (uVar4 < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x200) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x1b) = 1;
  }
  else {
    iVar3 = iVar2 + -0xc00;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x400] = 1;
    }
  }
  uVar1 = param1[1];
  GXFIFO = param1[1];
  if (iVar2 + 0x401U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x47) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x346] = 1;
  }
  else if (iVar2 + 0x401U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x484) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x46] = 1;
  }
  else if (iVar2 + 0x401U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x204) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x1a) = 1;
  }
  else if (iVar2 + 0x401U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x204) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x1a) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x401] = 1;
    }
  }
  uVar1 = param1[2];
  GXFIFO = param1[2];
  if (iVar2 + 0x402U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x43) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x347] = 1;
  }
  else if (iVar2 + 0x402U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x488) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x47] = 1;
  }
  else if (iVar2 + 0x402U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x208) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x19) = 1;
  }
  else if (iVar2 + 0x402U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x208) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x19) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x402] = 1;
    }
  }
  uVar1 = param1[4];
  GXFIFO = param1[4];
  if (iVar2 + 0x403U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x3f) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x348] = 1;
  }
  else if (iVar2 + 0x403U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x48c) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x48] = 1;
  }
  else if (iVar2 + 0x403U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x20c) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x18) = 1;
  }
  else if (iVar2 + 0x403U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x20c) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x18) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x403] = 1;
    }
  }
  uVar1 = param1[5];
  GXFIFO = param1[5];
  if (iVar2 + 0x404U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x3b) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x349] = 1;
  }
  else if (iVar2 + 0x404U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x490) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x49] = 1;
  }
  else if (iVar2 + 0x404U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x210) = uVar1;
    (&DAT_0000117c)[(int)&pGxDebug->dprint + iVar2] = 1;
  }
  else if (iVar2 + 0x404U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x210) = uVar1;
    (&DAT_0000117c)[(int)&pGxDebug->dprint + iVar2] = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x404] = 1;
    }
  }
  uVar1 = param1[6];
  GXFIFO = param1[6];
  if (iVar2 + 0x405U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x37) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x34a] = 1;
  }
  else if (iVar2 + 0x405U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x494) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x4a] = 1;
  }
  else if (iVar2 + 0x405U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x214) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x16) = 1;
  }
  else if (iVar2 + 0x405U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x214) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x16) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x405] = 1;
    }
  }
  uVar1 = param1[8];
  GXFIFO = param1[8];
  if (iVar2 + 0x406U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x33) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x34b] = 1;
  }
  else if (iVar2 + 0x406U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x498) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x4b] = 1;
  }
  else if (iVar2 + 0x406U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x218) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x15) = 1;
  }
  else if (iVar2 + 0x406U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x218) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x15) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x406] = 1;
    }
  }
  uVar1 = param1[9];
  GXFIFO = param1[9];
  if (iVar2 + 0x407U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x2f) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x34c] = 1;
  }
  else if (iVar2 + 0x407U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x49c) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x4c] = 1;
  }
  else if (iVar2 + 0x407U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x21c) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x14) = 1;
  }
  else if (iVar2 + 0x407U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x21c) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x14) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbf9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x407] = 1;
    }
  }
  uVar1 = param1[10];
  GXFIFO = param1[10];
  if (iVar2 + 0x408U < 0x400) {
    *(undefined4 *)((int)pGxDebug[1].projMtx + param2 * 0xc + -0x2b) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x34d] = 1;
  }
  else if (iVar2 + 0x408U < 0x500) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x4a0) = uVar1;
    pGxDebug[1].isRegInit[iVar2 + 0x4d] = 1;
  }
  else if (iVar2 + 0x408U < 0x600) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x220) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x13) = 1;
  }
  else if (iVar2 + 0x408U < 0x680) {
    *(undefined4 *)(pGxDebug->isRegInit + param2 * 0xc + 0x220) = uVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + iVar2 + -0x13) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbf8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)((int)pGxDebug + iVar3 * 4 + 8) = uVar1;
      pGxDebug->isRegInit[iVar2 + 0x408] = 1;
    }
  }
  return;
}


/* Library Function - Single Match
    GXSetCurrentMtx
   
   Library: KioskDefault 0 0 */

void GXSetCurrentMtx(uint param1) { //8002E640
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x2a1,"'GXSetCurrentMtx' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xffffffc0) != 0) {
                    
    OSPanic("GXTransform.c",0x2a5,"GX Internal: Register field out of range");
  }
  gx->field118_0x80 = gx->field118_0x80 & 0xffffffc0 | param1;
  __GXSetMatrixIndex(0);
  return;
}


/* Library Function - Single Match
    GXLoadTexMtxImm
   
   Library: KioskDefault 0 0 */

void GXLoadTexMtxImm(Mtx43 *m,uint id,int type) { //8002E6F8
  float fVar1;
  int iVar2;
  uint uVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x2c2,"'GXLoadTexMtxImm' is not allowed between GXBegin/GXEnd");
  }
  if (id < 0x40) {
    uVar3 = id << 2;
  }
  else {
    uVar3 = (id - 0x40) * 4 + 0x500;
    if (type != 0) {
                    
      OSPanic("GXTransform.c",0x2cc,"GXLoadTexMtx: Invalid matrix type");
    }
  }
  if (type == 1) {
    iVar2 = 8;
  }
  else {
    iVar2 = 0xc;
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = uVar3 | (iVar2 + -1) * 0x10000;
  fVar1 = m->m11;
  GXFIFO = m->m11;
  if (uVar3 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x80) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x7b)) = 1;
  }
  else if (uVar3 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x400) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd50] = 1;
  }
  else if (uVar3 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x500) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb0] = 1;
  }
  else if (uVar3 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x600) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb0] = 1;
  }
  else {
    iVar2 = uVar3 - 0x1000;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3] = 1;
    }
  }
  fVar1 = m->m12;
  GXFIFO = m->m12;
  if (uVar3 + 1 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x84) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x7a)) = 1;
  }
  else if (uVar3 + 1 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3ff) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd51] = 1;
  }
  else if (uVar3 + 1 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4ff) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb1] = 1;
  }
  else if (uVar3 + 1 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5ff) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb1] = 1;
  }
  else {
    iVar2 = uVar3 - 0xfff;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 1] = 1;
    }
  }
  fVar1 = m->m13;
  GXFIFO = m->m13;
  if (uVar3 + 2 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x88) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x79)) = 1;
  }
  else if (uVar3 + 2 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3fe) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd52] = 1;
  }
  else if (uVar3 + 2 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4fe) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb2] = 1;
  }
  else if (uVar3 + 2 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5fe) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb2] = 1;
  }
  else {
    iVar2 = uVar3 - 0xffe;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 2] = 1;
    }
  }
  fVar1 = m->m14;
  GXFIFO = m->m14;
  if (uVar3 + 3 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x8c) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x78)) = 1;
  }
  else if (uVar3 + 3 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3fd) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd53] = 1;
  }
  else if (uVar3 + 3 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4fd) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb3] = 1;
  }
  else if (uVar3 + 3 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5fd) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb3] = 1;
  }
  else {
    iVar2 = uVar3 - 0xffd;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 3] = 1;
    }
  }
  fVar1 = m->m21;
  GXFIFO = m->m21;
  if (uVar3 + 4 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x90) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x77)) = 1;
  }
  else if (uVar3 + 4 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3fc) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd54] = 1;
  }
  else if (uVar3 + 4 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4fc) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb4] = 1;
  }
  else if (uVar3 + 4 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5fc) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb4] = 1;
  }
  else {
    iVar2 = uVar3 - 0xffc;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 4] = 1;
    }
  }
  fVar1 = m->m22;
  GXFIFO = m->m22;
  if (uVar3 + 5 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x94) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x76)) = 1;
  }
  else if (uVar3 + 5 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3fb) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd55] = 1;
  }
  else if (uVar3 + 5 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4fb) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb5] = 1;
  }
  else if (uVar3 + 5 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5fb) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb5] = 1;
  }
  else {
    iVar2 = uVar3 - 0xffb;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 5] = 1;
    }
  }
  fVar1 = m->m23;
  GXFIFO = m->m23;
  if (uVar3 + 6 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x98) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x75)) = 1;
  }
  else if (uVar3 + 6 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3fa) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd56] = 1;
  }
  else if (uVar3 + 6 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4fa) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb6] = 1;
  }
  else if (uVar3 + 6 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5fa) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb6] = 1;
  }
  else {
    iVar2 = uVar3 - 0xffa;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 6] = 1;
    }
  }
  fVar1 = m->m24;
  GXFIFO = m->m24;
  if (uVar3 + 7 < 0x400) {
    *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0x9c) = fVar1;
    *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x74)) = 1;
  }
  else if (uVar3 + 7 < 0x500) {
    *(float *)((int)pGxDebug + (uVar3 - 0x3f9) * 4 + 0x548) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xd57] = 1;
  }
  else if (uVar3 + 7 < 0x600) {
    *(float *)((int)pGxDebug + (uVar3 - 0x4f9) * 4 + 0x6c8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb7] = 1;
  }
  else if (uVar3 + 7 < 0x680) {
    *(float *)((int)pGxDebug + (uVar3 - 0x5f9) * 4 + 0xac8) = fVar1;
    pGxDebug->isRegInit[uVar3 + 0xcb7] = 1;
  }
  else {
    iVar2 = uVar3 - 0xff9;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 7] = 1;
    }
  }
  if (type == 0) {
    fVar1 = m->m31;
    GXFIFO = m->m31;
    if (uVar3 + 8 < 0x400) {
      *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0xa0) = fVar1;
      *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x73)) = 1;
    }
    else if (uVar3 + 8 < 0x500) {
      *(float *)((int)pGxDebug + (uVar3 - 0x3f8) * 4 + 0x548) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xd58] = 1;
    }
    else if (uVar3 + 8 < 0x600) {
      *(float *)((int)pGxDebug + (uVar3 - 0x4f8) * 4 + 0x6c8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcb8] = 1;
    }
    else if (uVar3 + 8 < 0x680) {
      *(float *)((int)pGxDebug + (uVar3 - 0x5f8) * 4 + 0xac8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcb8] = 1;
    }
    else {
      iVar2 = uVar3 - 0xff8;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
        pGxDebug->isRegInit[uVar3 + 8] = 1;
      }
    }
    fVar1 = m->m32;
    GXFIFO = m->m32;
    if (uVar3 + 9 < 0x400) {
      *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0xa4) = fVar1;
      *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x72)) = 1;
    }
    else if (uVar3 + 9 < 0x500) {
      *(float *)((int)pGxDebug + (uVar3 - 0x3f7) * 4 + 0x548) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xd59] = 1;
    }
    else if (uVar3 + 9 < 0x600) {
      *(float *)((int)pGxDebug + (uVar3 - 0x4f7) * 4 + 0x6c8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcb9] = 1;
    }
    else if (uVar3 + 9 < 0x680) {
      *(float *)((int)pGxDebug + (uVar3 - 0x5f7) * 4 + 0xac8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcb9] = 1;
    }
    else {
      iVar2 = uVar3 - 0xff7;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
        pGxDebug->isRegInit[uVar3 + 9] = 1;
      }
    }
    fVar1 = m->m33;
    GXFIFO = m->m33;
    if (uVar3 + 10 < 0x400) {
      *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0xa8) = fVar1;
      *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x71)) = 1;
    }
    else if (uVar3 + 10 < 0x500) {
      *(float *)((int)pGxDebug + (uVar3 - 0x3f6) * 4 + 0x548) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xd5a] = 1;
    }
    else if (uVar3 + 10 < 0x600) {
      *(float *)((int)pGxDebug + (uVar3 - 0x4f6) * 4 + 0x6c8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcba] = 1;
    }
    else if (uVar3 + 10 < 0x680) {
      *(float *)((int)pGxDebug + (uVar3 - 0x5f6) * 4 + 0xac8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcba] = 1;
    }
    else {
      iVar2 = uVar3 - 0xff6;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
        pGxDebug->isRegInit[uVar3 + 10] = 1;
      }
    }
    fVar1 = m->m34;
    GXFIFO = m->m34;
    if (uVar3 + 0xb < 0x400) {
      *(float *)(pGxDebug->isRegInit + uVar3 * 4 + 0xac) = fVar1;
      *(undefined *)((int)pGxDebug[1].projMtx + (uVar3 - 0x70)) = 1;
    }
    else if (uVar3 + 0xb < 0x500) {
      *(float *)((int)pGxDebug + (uVar3 - 0x3f5) * 4 + 0x548) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xd5b] = 1;
    }
    else if (uVar3 + 0xb < 0x600) {
      *(float *)((int)pGxDebug + (uVar3 - 0x4f5) * 4 + 0x6c8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcbb] = 1;
    }
    else if (uVar3 + 0xb < 0x680) {
      *(float *)((int)pGxDebug + (uVar3 - 0x5f5) * 4 + 0xac8) = fVar1;
      pGxDebug->isRegInit[uVar3 + 0xcbb] = 1;
    }
    else {
      iVar2 = uVar3 - 0xff5;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(float *)((int)pGxDebug + iVar2 * 4 + 8) = fVar1;
        pGxDebug->isRegInit[uVar3 + 0xb] = 1;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    GXSetViewport
   
   Library: KioskDefault 0 0 */

void GXSetViewport(double param1,double param2,double param3,double param4,double param5,
                  double param6,int param7) { //8002F604
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  _savefpr_18();
  if (isInGxBegin != false) {
                    
    OSPanic("GXTransform.c",0x340,"'GXSetViewport' is not allowed between GXBegin/GXEnd");
  }
  if (param7 == 0) {
    param2 = (double)(float)(param2 - 0.5);
  }
  dVar6 = (double)(float)(param3 * 0.5);
  dVar5 = (double)(float)(-param4 * 0.5);
  dVar3 = (double)((float)(param1 + (double)(float)(param3 * 0.5)) + 340.0);
  dVar2 = (double)((float)(param2 + (double)(float)(param4 * 0.5)) + 340.0);
  dVar1 = (double)(float)(param6 * 16777215.0);
  dVar4 = (double)(float)(dVar1 - (double)(float)(param5 * 16777215.0));
  *(float *)&gx->field_0x43c = (float)param1;
  *(float *)&gx->field_0x440 = (float)param2;
  *(float *)&gx->field_0x444 = (float)param3;
  *(float *)&gx->field_0x448 = (float)param4;
  *(float *)&gx->field_0x44c = (float)param5;
  *(float *)&gx->field_0x450 = (float)param6;
  if (gx->field_0x454 != '\0') {
    nop_8002C490();
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x5101a;
  GXFIFO = (float)dVar6;
  if ((true) && (true)) {
    (pGxDebug->viewportScale).x = (float)dVar6;
    pGxDebug->isRegInit[0x101a] = 1;
  }
  GXFIFO = (float)dVar5;
  if ((true) && (true)) {
    (pGxDebug->viewportScale).y = (float)dVar5;
    pGxDebug->isRegInit[0x101b] = 1;
  }
  GXFIFO = (float)dVar4;
  if ((true) && (true)) {
    (pGxDebug->viewportScale).z = (float)dVar4;
    pGxDebug->isRegInit[0x101c] = 1;
  }
  GXFIFO = (float)dVar3;
  if ((true) && (true)) {
    (pGxDebug->viewportOffset).x = (float)dVar3;
    pGxDebug->isRegInit[0x101d] = 1;
  }
  GXFIFO = (float)dVar2;
  if ((true) && (true)) {
    (pGxDebug->viewportOffset).y = (float)dVar2;
    pGxDebug->isRegInit[0x101e] = 1;
  }
  GXFIFO = (float)dVar1;
  if ((true) && (true)) {
    (pGxDebug->viewportOffset).z = (float)dVar1;
    pGxDebug->isRegInit[0x101f] = 1;
  }
  gx->field2_0x2 = 0;
  _restfpr_18();
  return;
}


/* Library Function - Single Match
    GXSetScissor
   
   Library: KioskDefault 0 0 */

void GXSetScissor(uint leftOrigin,uint topOrigin,int rightEdge,int bottomEdge) { //8002F95C
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x3b4,"'GXSetScissor' is not allowed between GXBegin/GXEnd");
  }
  if (0x6ab < leftOrigin) {
                    
    OSPanic("GXTransform.c",0x3b5,s_GXSetScissor__Left_origin_>_1708_802dbd94);
  }
  if (0x6ab < topOrigin) {
                    
    OSPanic("GXTransform.c",0x3b6,s_GXSetScissor__top_origin_>_1708_802dbdb8);
  }
  if (0x6ab < leftOrigin + rightEdge) {
                    
    OSPanic("GXTransform.c",0x3b7,s_GXSetScissor__right_edge_>_1708_802dbdd8);
  }
  if (0x6ab < topOrigin + bottomEdge) {
                    
    OSPanic("GXTransform.c",0x3b8,s_GXSetScissor__bottom_edge_>_1708_802dbdf8);
  }
  uVar4 = topOrigin + 0x154;
  uVar3 = leftOrigin + 0x154;
  uVar2 = uVar4 + bottomEdge + -1;
  uVar1 = uVar3 + rightEdge + -1;
  if ((uVar4 & 0xfffff800) != 0) {
                    
    OSPanic("GXTransform.c",0x3bf,"GX Internal: Register field out of range");
  }
  gx->field235_0xf8 = gx->field235_0xf8 & 0xfffff800 | uVar4;
  if ((uVar3 & 0xfffff800) != 0) {
                    
    OSPanic("GXTransform.c",0x3c0,"GX Internal: Register field out of range");
  }
  gx->field235_0xf8 = gx->field235_0xf8 & 0xff800fff | uVar3 * 0x1000;
  if ((uVar2 & 0xfffff800) != 0) {
                    
    OSPanic("GXTransform.c",0x3c2,"GX Internal: Register field out of range");
  }
  gx->field236_0xfc = gx->field236_0xfc & 0xfffff800 | uVar2;
  if ((uVar1 & 0xfffff800) != 0) {
                    
    OSPanic("GXTransform.c",0x3c3,"GX Internal: Register field out of range");
  }
  gx->field236_0xfc = gx->field236_0xfc & 0xff800fff | uVar1 * 0x1000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = gx->field235_0xf8;
  *(uint *)(pGxDebug->isRegInit + (gx->field235_0xf8 >> 0x18) * 4 + 0xc00) = gx->field235_0xf8;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = gx->field236_0xfc;
  *(uint *)(pGxDebug->isRegInit + (gx->field236_0xfc >> 0x18) * 4 + 0xc00) = gx->field236_0xfc;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    gxTransformGetFn_8002fc78
   
   Library: KioskDefault 0 0 */

void gxTransformGetFn_8002fc78(int *param1,int *param2,int *param3,int *param4) { //8002FC78
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((param1 != (int *)0x0) && (param2 != (int *)0x0)) && (param3 != (int *)0x0)) &&
     (param4 != (int *)0x0)) {
    uVar2 = gx->field235_0xf8 & 0x7ff;
    uVar1 = (gx->field235_0xf8 & 0x7ff000) >> 0xc;
    uVar3 = gx->field236_0xfc;
    uVar4 = gx->field236_0xfc;
    *param1 = uVar1 - 0x154;
    *param2 = uVar2 - 0x154;
    *param3 = (((uVar4 & 0x7ff000) >> 0xc) - uVar1) + 1;
    *param4 = ((uVar3 & 0x7ff) - uVar2) + 1;
    return;
  }
                    
  OSPanic("GXTransform.c",0x3dd,"GXGet*: invalid null pointer");
}


/* Library Function - Single Match
    GXSetScissorBoxOffset
   
   Library: KioskDefault 0 0 */

void GXSetScissorBoxOffset(int param1,int param2) { //8002FD5C
  uint uVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x3fb,"'GXSetScissorBoxOffset' is not allowed between GXBegin/GXEnd");
  }
  if (0x7ff < param1 + 0x154U) {
                    
    OSPanic("GXTransform.c",0x3fe,s_GXSetScissorBoxOffset__x_offset_>_802dbe5c);
  }
  if (0x7ff < param2 + 0x154U) {
                    
    OSPanic("GXTransform.c",0x400,s_GXSetScissorBoxOffset__y_offset_>_802dbe84);
  }
  uVar2 = param1 + 0x154U >> 1;
  uVar1 = param2 + 0x154U >> 1;
  if ((uVar2 & 0x7ffffc00) != 0) {
                    
    OSPanic("GXTransform.c",0x405,"GX Internal: Register field out of range");
  }
  if ((uVar1 & 0x7ffffc00) != 0) {
                    
    OSPanic("GXTransform.c",0x406,"GX Internal: Register field out of range");
  }
  uVar2 = (uVar2 & 0x7ff003ff | uVar1 << 10) & 0xffffff | 0x59000000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + 0xd64) = uVar2;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetClipMode
   
   Library: KioskDefault 0 0 */

void GXSetClipMode(undefined4 param1) { //8002FEFC
  if (isInGxBegin) {
                    
    OSPanic("GXTransform.c",0x41b,"'GXSetClipMode' is not allowed between GXBegin/GXEnd");
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x1005;
  GXFIFO = param1;
  if ((true) && (true)) {
    *(undefined4 *)&pGxDebug->field_0x1c = param1;
    pGxDebug->isRegInit[0x1005] = 1;
  }
  gx->field2_0x2 = 0;
  return;
}

