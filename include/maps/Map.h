#ifndef _MAPS_MAP_H_
#define _MAPS_MAP_H_

#include "../types.h"

typedef int mapId32;
typedef enum {
    MapId_frontend = 0,
    MapId_frontend2 = 1,
    MapId_dragrock = 2,
    MapId_krazoapalace = 3,
    MapId_temple = 4,
    MapId_hightop = 5,
    MapId_discovery = 6,
    MapId_hollow = 7,
    MapId_hollow2 = 8,
    MapId_mazecave = 9,
    MapId_wastes = 10,
    MapId_warlock = 11,
    MapId_fortress = 12,
    MapId_wallcity = 13,
    MapId_swapcircle = 14,
    MapId_cloudtreasure = 15,
    MapId_clouddungeon = 16,
    MapId_cloudtrap = 17,
    MapId_moonpass = 18,
    MapId_snowmines = 19,
    MapId_krashrin2 = 20,
    MapId_kraztest = 21,
    MapId_krazchamber = 22,
    MapId_newicemount = 23,
    MapId_newicemount2 = 24,
    MapId_newicemount3 = 25,
    MapId_animtest = 26,
    MapId_snowmines2 = 27,
    MapId_snowmines3 = 28,
    MapId_capeclaw = 29,
    MapId_insidegal = 30,
    MapId_dfshrine = 31,
    MapId_mmshrine = 32,
    MapId_ecshrine = 33,
    MapId_gpshrine = 34,
    MapId_diamondbay = 35,
    MapId_earthwalker = 36,
    MapId_willow = 37,
    MapId_arwing = 38,
    MapId_dbshrine = 39,
    MapId_nwshrine = 40,
    MapId_ccshrine = 41,
    MapId_wgshrine = 42,
    MapId_cloudrace = 43,
    MapId_finalboss = 44,
    MapId_wminsert = 45,
    MapId_snowmines4 = 46,
    MapId_snowmines5 = 47,
    MapId_trexboss = 48,
    MapId_mikelava = 49,
    MapId_dfptop = 50,
    MapId_swapstore = 51,
    MapId_dragbot = 52,
    MapId_kamdrag = 53,
    MapId_magicave = 54,
    MapId_duster = 55,
    MapId_linkb = 56,
    MapId_cloudjoin = 57,
    MapId_arwingtoplanet = 58,
    MapId_arwingdarkice = 59,
    MapId_arwingcloud = 60,
    MapId_arwingcity = 61,
    MapId_arwingdragon = 62,
    MapId_gamefront = 63,
    MapId_linklevel = 64,
    MapId_greatfox = 65,
    MapId_linka = 66,
    MapId_linkc = 67,
    MapId_linkd = 68,
    MapId_linke = 69,
    MapId_linkf = 70,
    MapId_linkg = 71,
    MapId_linkh = 72,
    MapId_linkj = 73,
    MapId_linki = 74,
    MapId_dfpodium = 75,
    MapId_dfcradle = 76,
    MapId_dfcavehatch1 = 77,
    MapId_dfcavehatch2 = 78,
    MapId_scstatue = 79,
    MapId_galleonship = 80,
    MapId_cfgalleon = 81,
    MapId_cfgangplank = 82,
    MapId_nwtreebridge = 83,
    MapId_cfdungeonblock = 84,
    MapId_cloudrunnermap = 85,
    MapId_ccbridge = 86,
    MapId_cfcolumn = 87,
    MapId_nwboulder = 88,
    MapId_cfprisondoor = 89,
    MapId_cfprisoncage = 90,
    MapId_nwtreebridge2 = 91,
    MapId_dim2iceblock1 = 92,
    MapId_dimpushblock = 93,
    MapId_dim2iceblock2 = 94,
    MapId_dimhornplinth = 95,
    MapId_nwshcolpush = 96,
    MapId_dim2lift = 97,
    MapId_dim2icefloe = 98,
    MapId_dim2icefloe1 = 99,
    MapId_dim2icefloe2 = 100,
    MapId_cfliftplat = 101,
    MapId_imspacecraft = 102,
    MapId_dimbossgut = 103,
    MapId_wmcolrise = 104,
    MapId_vfpslide1 = 105,
    MapId_vfpslide2 = 106,
    MapId_drpushcart = 107,
    MapId_drliftplat = 108,
    MapId_dim2stonepillar = 109,
    MapId_bossdrakorflatr = 110,
    MapId_wcbouncycrate = 111,
    MapId_wcpushblock = 112,
    MapId_wctemplelift = 113,
    MapId_KamColumn = 114,
    MapId_dbstepstone = 115,
    MapId_vfppushblock = 116,
    MapId_None = -1,
} MapId;

typedef struct {
    /* 0x00 */ int sig; //SIG_UNCOMPRESSED_FILE or SIG_LZO_COMPRESSED_FILE
    /* 0x04 */ int len;
    /* 0x08 */ int offset;
    /* 0x0C */ int compLen;
    /* 0x10 */ int unk10;
    /* 0x14 */ int unk14;
} DbMapsBinEntry;

typedef struct {
    /* 0x00 */ undefined unk00;
    /* 0x01 */ undefined unk01;
    /* 0x02 */ undefined unk02;
    /* 0x03 */ undefined unk03;
    /* 0x04 */ undefined unk04;
    /* 0x05 */ undefined unk05;
    /* 0x06 */ undefined unk06;
    /* 0x07 */ undefined unk07;
    /* 0x08 */ undefined unk08;
    /* 0x09 */ undefined unk09;
    /* 0x0a */ undefined unk0a;
    /* 0x0b */ undefined unk0b;
    /* 0x0c */ undefined unk0c;
    /* 0x0d */ undefined unk0d;
    /* 0x0e */ undefined unk0e;
    /* 0x0f */ undefined unk0f;
    /* 0x10 */ undefined unk10;
    /* 0x11 */ undefined unk11;
    /* 0x12 */ undefined unk12;
    /* 0x13 */ undefined unk13;
    /* 0x14 */ undefined unk14;
    /* 0x15 */ undefined unk15;
    /* 0x16 */ undefined unk16;
    /* 0x17 */ undefined unk17;
    /* 0x18 */ undefined unk18;
    /* 0x19 */ undefined unk19;
    /* 0x1a */ undefined unk1a;
    /* 0x1b */ undefined unk1b;
    /* 0x1c */ s16 nBlocks;
    /* 0x1e */ s16 unk1e;
} MapsBinEntry0;

typedef struct {
    /* 0x0 */ undefined unk0;
    /* 0x1 */ undefined unk1;
    /* 0x2 */ undefined unk2;
    /* 0x3 */ undefined unk3;
    /* 0x4 */ int unk4;
    /* 0x8 */ int unk8;
    /* 0xc */ int unkc;
} astruct_6;

#endif //_MAPS_MAP_H_
