//many of these are from final version and might
//not be correct for debug version
typedef struct {
    /* 0x0 */ Vec pos;
    /* 0xC */ s8 rotX;
    /* 0xD */ s8 layer;
} CharPos;

typedef struct {
    /* 0x0 */ s8 curHealth;	//in 1/4 hearts
    /* 0x1 */ s8 maxHealth;
    /* 0x2 */ s8 field_02;
    /* 0x3 */ s8 field_03;
    /* 0x4 */ u16 curMagic;
    /* 0x6 */ u16 maxMagic;
    /* 0x8 */ u8 money;
    /* 0x9 */ s8 curBafomDads;
    /* 0xa */ s8 maxBafomDads;
    /* 0xb */ s8 field_0B; //probably padding
} PlayerCharState;

typedef struct {
    /* 0x0 */ s8 energy;
    /* 0x1 */ s8 maxEnergy;
    /* 0x2 */ s8 playCount; //+1 when return ball, wrap at 240, transform every 10
    /* 0x3 */ s8 _03;
} SavedTrickyState;

typedef struct {
    int id; //object unique ID
    Vec pos; //world coordinates
} SaveGameObjectPos;
#define SAVEGAME_MAX_SAVED_OBJS 63

typedef struct {
    /* 0x00 */	PlayerCharState charState[2];
    /* 0x18 */ SavedTrickyState tricky;
    /* 0x1c */ char	saveFileName[4]; //null terminated, but game does use strncpy properly
    /* 0x20 */ s8 character; //current character: 0:Krystal 1:Fox
    /* 0x21 */ u8 flags21; //80=erase me; 60=save slot
    /* 0x22 */ u8 bDontReplaceCurrent;
    /* 0x23 */ s8 _23;
    /* 0x24 */ u8 gameBits2[324];
    /* 0x168 */	SaveGameObjectPos objs[SAVEGAME_MAX_SAVED_OBJS];
    /* 0x558 */	u8 texts[5]; //hint texts
    /* 0x55d */	u8 completion; //percent = (this / 187) * 100
    /* 0x55e */	u8 numTexts;
    /* 0x55f */	s8 _55F;
    /* 0x560 */	float playTime; //frame count (so why float!?)
    /* 0x564 */	u8	gameBits1[116];
} SaveGamePart1;

typedef struct {
    /* 0x0 */ float timeOfDay;
    /* 0x4 */ s16 envFxActIdx[5];
    /* 0xe */ s16 envFxActIdx2[3];
    /* 0x14 */ S16Vec skyObjPos[3];
    /* 0x38 */ s8 _38;
    /* 0x39 */ s8 _39;
    /* 0x3a */ s8 _3a;
    /* 0x3b */ s8 _3b;
    /* 0x3c */ s8 _3c;
    /* 0x3d */ s8 _3d;
    /* 0x3e */ s8 _3e;
    /* 0x3f */ s8 _3f;
    /* 0x40 */ u8 flags40; //1:enable clouds+lights; 8:enable lights; 20:heat FX
    /* 0x41 */ s8 skyObjIdx[3];
} SaveGameEnvState;

#if VERSION == VERSION_DEBUG
//debug version, very little is known
typedef struct {
    /* 0x0000 */ u8 unk[0x12D4];
    /* 0x12D4 */ u8 gameBits2[0x100]; //strange order
    /* 0x13D4 */ u8 gameBits1[0x200];
    /* 0x15D4 */ u8 gameBits3[0x1D8]; //might be 0x100 followed by other data
    /* 0x17AC */ u8 gameBits0[1]; //unknown size - this table isn't saved in final
} SaveGame;

#else //VERSION
typedef struct {
    /* 0x0000 */ SaveGamePart1 part1;
    /* 0x05D8 */ u8 gameBits3[172]; //from here on are not saved by gplaySavePoint
    /* 0x0684 */ CharPos charPos[2];
    /* 0x06A4 */ s16 camAction;
    /* 0x06A6 */ s8 _unk0; //probably padding
    /* 0x06A7 */ s8 _unk1;
    /* 0x06A8 */ SaveGameEnvState env; //environment settings
    /* 0x06EC end */
} SaveGame;

#endif //VERSION
