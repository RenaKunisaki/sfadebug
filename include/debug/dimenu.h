#ifndef _DEBUG_DIMENU_H_
#define _DEBUG_DIMENU_H_

typedef enum {
    Unk0 = 0,
    Adjustable = 1, //Choose a value
    Selectable = 3, //Selecting it calls a function
    Header = 4, //Not selectable
    CBoostRelated = 5,
    End = 10 //End of list
} DiMenuType;

typedef union {
    unsigned int iStrs; //for Adjustable type; index into diMenuStrings
    char **pStr; //for Adjustable type
    char *str; //for Header type
    int *pInt; //for Unk0 type
} DiMenuItemStrings;

typedef struct {
    DiMenuItemStrings strs;
    int iStr;
    int nStrs;
} DiMenuStrings;

typedef struct {
    /*0x0 */ u8 type; //DiMenuType
    /*0x2 */ u16 width; //0=auto, 0xFFFF=centre?
    /*0x4 */ s16 height; //why is one signed and the other not?
    /*0x8 */ u32 color; //if 0, don't set
    /*0xc */ char *text;
    /*0x10 */ DiMenuItemStrings	strs;
    /*0x14 */ void *func; //XXX type
    /*0x18 */ s8 heightFlags18; //maybe bool
    //struct size: 0x1C
} DiMenuItem;

typedef struct {
    /* 0x0 */ DiMenuItem *curItem;
    /* 0x4 */ DiMenuItem *items;
    /* 0x8 */ DiMenuItem *lastItem;
    /* 0xc */ BOOL bWrap; //wrap from last item to first
    /* 0x10 */ int minH;
    /* 0x14 */ int minW;
    /* 0x18 */ int maxH;
    /* 0x1c */ int maxW;
    /* 0x20 */ DiMenuItem *firstDispItem; //first item that fits on screen
    /* 0x24 */ DiMenuItem *lastDispItem; //last item that fits on screen
    /* 0x28 */ uint spaceFlag28;
} DiMenuStruct3;

#endif //_DEBUG_DIMENU_H_
