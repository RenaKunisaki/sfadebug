#ifndef _DEBUG_DEBUG_H_
#define _DEBUG_DEBUG_H_
//exists in final but unused
typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ int time;
} PlayerPrevPosition;
#define NUM_PLAYER_PREV_POSITIONS 60

typedef struct {
	/* 0x0 */ s16 nItems;
	/* 0x2 */ s16 max;
	/* 0x4 */ s16 itemSize;
	/* 0x6 */ s8 _06;
	/* 0x7 */ s8 _07;
	/* 0x8 */ s16 count;
	/* 0xa */ s8 _0a;
	/* 0xb */ s8 _0b;
	/* 0xc */ s16 *data;
} DiStack;

#define DIPROFSTRUCT_MAX_NUM  0x200
#define DIPROFSTRUCT_NAME_LEN 23
typedef struct {
	/* 0x0 */ char name[DIPROFSTRUCT_NAME_LEN + 1];
	/* 0x18 */ undefined4 _18;
	/* 0x1c */ undefined4 time;
	/* 0x20 */ u8 _20;
	/* 0x21 */ undefined1 _21; // probably padding
	/* 0x22 */ undefined1 _22;
	/* 0x23 */ undefined1 _23;
} DiProfStruct;

typedef struct {
	/* 0x0 */ s8 type;
	/* 0x2 */ ushort unk02;
	/* 0x4 */ short unk04;
	/* 0x6 */ s8 unk06;
	/* 0x7 */ s8 unk07;
	/* 0x8 */ s8 unk08;
	/* 0x9 */ s8 unk09;
	/* 0xa */ s8 unk0a;
	/* 0xb */ s8 unk0b;
	/* 0xc */ char *text;
	/* 0x10 */ char **values;
	/* 0x14 */ UNKTYPE *func;
	/* 0x18 */ s8 unk18;
	/* 0x19 */ s8 unk19;
	/* 0x1a */ s8 unk1a;
	/* 0x1b */ s8 unk1b;
} DiMenuStruct;

typedef struct {
	/* 0x0 */ undefined4 unk0;
	/* 0x4 */ undefined4 unk4;
	/* 0x8 */ Vec charPos;
	/* 0x14 */ uint unk14;
	/* 0x18 */ char codeVersion[64];
	/* 0x58 */ char buildDate[64];
	/* 0x98 */ char buildAuthor[64];
	/* 0xd8 */ char fullVersionString[64];
	/* 0x118 */ undefined4 unk118;
	/* 0x11c */ undefined unk11c;
	/* 0x11d */ undefined unk11d;
	/* 0x11e */ undefined unk11e;
	/* 0x11f */ undefined unk11f;
	/* 0x120 */ undefined unk120;
	/* 0x121 */ undefined unk121;
	/* 0x122 */ undefined unk122;
	/* 0x123 */ undefined unk123;
} DebugSaveStruct;

#endif //_DEBUG_DEBUG_H_
