#ifndef _TYPES
#define _TYPES

#ifdef __cplusplus
#include "static_assert.hpp"

extern "C" {
#endif

#include "versions.h"
#include <dolphin/types.h>

typedef unsigned char bool;
#define true 1
#define false 0

typedef void UNKTYPE;
typedef char undefined;
typedef char undefined1;
typedef short undefined2;
typedef int undefined4;

// Dolphin u32 is unsigned long
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

// Pointer to unknown, to be determined at a later date.
typedef void* unkptr;

typedef int intptr_t;

#define SBig(x) x

#define ARRAY_SIZE(arr) static_cast< int >(sizeof(arr) / sizeof(arr[0]))

//there are many cases of pointer comparisons that
//use cmpw instead of cmplw, which seems to only
//happen if the pointers are cast to int.
//presumably this was some kind of macro which used
//to do additional validation?
#define PTR_EQ(a, b) ((intptr_t)(a) == (intptr_t)(b))

#ifdef __cplusplus
}
#endif

#endif // _TYPES
