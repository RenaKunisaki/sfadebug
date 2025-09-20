#ifndef _GFX_MODELS_BITSTREAM_H_
#define _GFX_MODELS_BITSTREAM_H_
#include "types.h"

typedef struct {
    /* 0x00 */ u8 *data;
    /* 0x04 */ int nBytes;
    /* 0x08 */ uint len;
    /* 0x0c */ uint len2;
    /* 0x10 */ int pos;
} BitStream;

#endif //_GFX_MODELS_BITSTREAM_H_
