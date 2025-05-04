#ifndef _DEBUG_DIMENU_H_
#define _DEBUG_DIMENU_H_

enum DiMenuType {
    Unk0 = 0,
    Adjustable = 1, //Choose a value
    Selectable = 3, //Selecting it calls a function
    Header = 4, //Not selectable
    CBoostRelated = 5,
    End = 10 //End of list
};

typedef struct {
    /* 0x0 */ DiMenuItem *curItem;
    /* 0x4 */ DiMenuItem *items;
    /* 0x8 */ DiMenuItem *lastItem;
    /* 0xc */ BOOL bWrap; //wrap from last item to first
    /* 0x10 */ int minH;
    /* 0x14 */ uint minW;
    /* 0x18 */ int maxW;
    /* 0x1c */ uint maxH;
    /* 0x20 */ DiMenuItem *firstDispItem; //first item that fits on screen
    /* 0x24 */ DiMenuItem *lastDispItem; //last item that fits on screen
    /* 0x28 */ uint spaceFlag28;
} DiMenuStruct3;

typedef union {
    int iStrs; //for Adjustable type; index into diMenuStrings
    char *str; //for Header type
    int *pInt; //for Unk0 type
} DiMenuItemStrings;

typedef struct {
    /*0x0 */ s8 type; //DiMenuType
    /*0x2 */ short height; //0=auto, -1=centre?
    /*0x4 */ short width;
    /*0x8 */ Color4b color; //if 0, don't set
    /*0xc */ char *text;
    /*0x10 */ DiMenuItemStrings	strs;
    /*0x14 */ void *func; //XXX type
    /*0x18 */ s8 heightFlags18; //maybe bool
    //struct size: 0x1C
} DiMenuItem;

#endif //_DEBUG_DIMENU_H_
