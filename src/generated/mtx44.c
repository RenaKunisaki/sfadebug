
/* Library Function - Single Match
    MTXPerspective
   
   Library: KioskDefault 0 0 */

void MTXPerspective(double param1,double param2,double param3,double param4,float *param5) { //8000FA60
  double dVar1;
  
  _savefpr_25();
  if (param5 == (float *)0x0) {
                    
    OSPanic("mtx44.c",0x93,"MTXPerspective():  NULL Mtx44Ptr 'm' ");
  }
  if ((0.0 < param1) && (param1 < 180.0)) {
    if (param2 == 0.0) {
                    
      OSPanic("mtx44.c",0x95,"MTXPerspective():  'aspect' is 0 ");
    }
    dVar1 = mathFn_802947cc((double)((float)(param1 * 0.5) * 0.01745329));
    *param5 = (float)((double)(float)(1.0 / dVar1) / param2);
    param5[1] = 0.0;
    param5[2] = 0.0;
    param5[3] = 0.0;
    param5[4] = 0.0;
    param5[5] = (float)(1.0 / dVar1);
    param5[6] = 0.0;
    param5[7] = 0.0;
    param5[8] = 0.0;
    param5[9] = 0.0;
    dVar1 = (double)(1.0 / (float)(param4 - param3));
    param5[10] = (float)(-param3 * dVar1);
    param5[0xb] = (float)(dVar1 * -(double)(float)(param4 * param3));
    param5[0xc] = 0.0;
    param5[0xd] = 0.0;
    param5[0xe] = -1.0;
    param5[0xf] = 0.0;
    _restfpr_25();
    return;
  }
                    
  OSPanic("mtx44.c",0x94,"MTXPerspective():  'fovY' out of range ");
}


/* Library Function - Single Match
    MTXOrtho
   
   Library: KioskDefault 0 0 */

void C_MTXOrtho(double t,double b,double l,double r,double n,double f,Mtx44 *m) { //8000FBCC
  float fVar1;
  double dVar2;
  
  _savefpr_25();
  if (m == (Mtx44 *)0x0) {
                    
    OSPanic("mtx44.c",0xdb,"MTXOrtho():  NULL Mtx44Ptr 'm' ");
  }
  if (t == b) {
                    
    OSPanic("mtx44.c",0xdc,"MTXOrtho():  't' and 'b' clipping planes are equal ");
  }
  if (l == r) {
                    
    OSPanic("mtx44.c",0xdd,"MTXOrtho():  'l' and 'r' clipping planes are equal ");
  }
  if (n == f) {
                    
    OSPanic("mtx44.c",0xde,"MTXOrtho():  'n' and 'f' clipping planes are equal ");
  }
  fVar1 = 1.0 / (float)(r - l);
  m->m11 = fVar1 * 2.0;
  m->m12 = 0.0;
  m->m13 = 0.0;
  m->m14 = fVar1 * -(float)(r + l);
  fVar1 = 1.0 / (float)(t - b);
  m->m21 = 0.0;
  m->m22 = fVar1 * 2.0;
  m->m23 = 0.0;
  m->m24 = fVar1 * -(float)(t + b);
  m->m31 = 0.0;
  m->m32 = 0.0;
  dVar2 = (double)(1.0 / (float)(f - n));
  m->m33 = (float)(dVar2 * -1.0);
  m->m34 = (float)(-f * dVar2);
  m->m41 = 0.0;
  m->m42 = 0.0;
  m->m43 = 0.0;
  m->m44 = 1.0;
  _restfpr_25();
  return;
}

