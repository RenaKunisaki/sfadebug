typedef struct {
    /* 0x00 */ s8 parent; //high bit is a flag?
    /* 0x01 */ s8 idx[3]; //idx to write to?
    /* 0x04 */ Vec translation;
    /* 0x10 */ Vec bindTranslation;
} Bone;
