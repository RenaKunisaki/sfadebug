//Compression-related types and declarations
#ifndef _SYS_COMPRESS_H_
#define _SYS_COMPRESS_H_

#include "../types.h"

typedef struct {
    /* 0x0 */ char signature[4]; //"ZLB\0"
    /* 0x4 */ u32 version;
    /* 0x8 */ u32 decLen;
    /* 0xc */ u32 compLen;
} ZlbHeader;

#endif //_SYS_COMPRESS_H_
