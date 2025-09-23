#ifndef _DOLPHIN_CMATH_H_
#define _DOLPHIN_CMATH_H_
#include "types.h"
#include "dolphin/mtx.h"

f32 powf(f32 x, f32 y);
f32 sinf(f32);
f32 cosf(f32);
f32 tanf(f32);

float VECLength(Vec *vec);
void VECSubtract(Vec *a,Vec *b,Vec *a_b);

#endif // _DOLPHIN_CMATH_H_
