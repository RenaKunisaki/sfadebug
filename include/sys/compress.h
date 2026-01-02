//Compression-related types and declarations
#ifndef _SYS_COMPRESS_H_
#define _SYS_COMPRESS_H_

#include "../types.h"

#define SIG_UNCOMPRESSED_FILE 0xe0e0e0e0
#define SIG_LZO_COMPRESSED_FILE 0xf0f0f0f0

//in final version only ZLB is supported.
//in this version the signature can also be "LZO\0"
//which is a different compression but with the
//same header layout
typedef struct {
    /* 0x0 */ char signature[4]; //"ZLB\0"
    /* 0x4 */ u32 version;
    /* 0x8 */ u32 decLen;
    /* 0xc */ u32 compLen;
} ZlbHeader;

#endif //_SYS_COMPRESS_H_
