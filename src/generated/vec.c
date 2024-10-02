
/* Library Function - Single Match
    VECAdd
   
   Library: KioskDefault 0 0 */

void VECAdd(float *param1,float *param2,float *param3) { //8000FD58
  if (param1 == (float *)0x0) {
                    
    OSPanic("vec.c",0x57,"VECAdd():  NULL VecPtr 'a' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("vec.c",0x58,"VECAdd():  NULL VecPtr 'b' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("vec.c",0x59,"VECAdd():  NULL VecPtr 'ab' ");
  }
  *param3 = *param1 + *param2;
  param3[1] = param1[1] + param2[1];
  param3[2] = param1[2] + param2[2];
  return;
}


/* Library Function - Single Match
    VECSubtract
   
   Library: KioskDefault 0 0 */

void VECSubtract(float *param1,float *param2,float *param3) { //8000FE14
  if (param1 == (float *)0x0) {
                    
    OSPanic("vec.c",0x9c,"VECSubtract():  NULL VecPtr 'a' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("vec.c",0x9d,"VECSubtract():  NULL VecPtr 'b' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("vec.c",0x9e,"VECSubtract():  NULL VecPtr 'a_b' ");
  }
  *param3 = *param1 - *param2;
  param3[1] = param1[1] - param2[1];
  param3[2] = param1[2] - param2[2];
  return;
}


/* Library Function - Single Match
    VECScale
   
   Library: KioskDefault 0 0 */

void VECScale(double param1,float *param2,float *param3) { //8000FF0C
  if (param2 == (float *)0x0) {
                    
    OSPanic("vec.c",0xe2,"VECScale():  NULL VecPtr 'src' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("vec.c",0xe3,"VECScale():  NULL VecPtr 'dst' ");
  }
  *param3 = (float)((double)*param2 * param1);
  param3[1] = (float)((double)param2[1] * param1);
  param3[2] = (float)((double)param2[2] * param1);
  return;
}


/* Library Function - Single Match
    VECNormalize
   
   Library: KioskDefault 0 0 */

void VECNormalize(float *param1,float *param2) { //8000FFD0
  float fVar1;
  double dVar2;
  
  if (param1 == (float *)0x0) {
                    
    OSPanic("vec.c",0x127,"VECNormalize():  NULL VecPtr 'src' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("vec.c",0x128,"VECNormalize():  NULL VecPtr 'unit' ");
  }
  dVar2 = (double)(param1[2] * param1[2] + *param1 * *param1 + param1[1] * param1[1]);
  if (dVar2 == 0.0) {
                    
    OSPanic("vec.c",0x12d,"VECNormalize():  zero magnitude vector ");
  }
  dVar2 = FUN_800103cc(dVar2);
  fVar1 = (float)(1.0 / dVar2);
  *param2 = *param1 * fVar1;
  param2[1] = param1[1] * fVar1;
  param2[2] = param1[2] * fVar1;
  return;
}


/* Library Function - Single Match
    VECMag
   
   Library: KioskDefault 0 0 */

double VECMag(float *param1) { //80010100
  if (param1 == (float *)0x0) {
                    
    OSPanic("vec.c",0x182,"VECMag():  NULL VecPtr 'v' ");
  }
  return (double)(param1[2] * param1[2] + *param1 * *param1 + param1[1] * param1[1]);
}


void vecFn_80010194(float *param1) { //80010194
  double dVar1;
  
  dVar1 = VECMag(param1);
  FUN_800103cc(dVar1);
  return;
}


/* Library Function - Single Match
    VECDotProduct
   
   Library: KioskDefault 0 0 */

double VECDotProduct(float *param1,float *param2) { //800101C0
  if (param1 == (float *)0x0) {
                    
    OSPanic("vec.c",0x1d1,"VECDotProduct():  NULL VecPtr 'a' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("vec.c",0x1d2,"VECDotProduct():  NULL VecPtr 'b' ");
  }
  return (double)(param1[2] * param2[2] + *param1 * *param2 + param1[1] * param2[1]);
}


/* Library Function - Single Match
    VECCrossProduct
   
   Library: KioskDefault 0 0 */

void VECCrossProduct(float *param1,float *param2,float *param3) { //8001028C
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if (param1 == (float *)0x0) {
                    
    OSPanic("vec.c",0x20f,"VECCrossProduct():  NULL VecPtr 'a' ");
  }
  if (param2 == (float *)0x0) {
                    
    OSPanic("vec.c",0x210,"VECCrossProduct():  NULL VecPtr 'b' ");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("vec.c",0x211,"VECCrossProduct():  NULL VecPtr 'axb' ");
  }
  fVar1 = param1[2];
  fVar2 = *param2;
  fVar3 = *param1;
  fVar4 = param2[2];
  fVar5 = *param1;
  fVar6 = param2[1];
  fVar7 = param1[1];
  fVar8 = *param2;
  *param3 = param1[1] * param2[2] - param1[2] * param2[1];
  param3[1] = fVar1 * fVar2 - fVar3 * fVar4;
  param3[2] = fVar5 * fVar6 - fVar7 * fVar8;
  return;
}

