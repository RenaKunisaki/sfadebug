//Compression-related types and declarations
#ifndef _SYS_COMPRESS_H_
#define _SYS_COMPRESS_H_

#include "../types.h"

#define SIG_UNCOMPRESSED_FILE 0xe0e0e0e0
#define SIG_LZO_COMPRESSED_FILE 0xf0f0f0f0

typedef struct {
    /* 0x0 */ char signature[4]; //"ZLB\0"
    /* 0x4 */ u32 version;
    /* 0x8 */ u32 decLen;
    /* 0xc */ u32 compLen;
} ZlbHeader;

#endif //_SYS_COMPRESS_H_
