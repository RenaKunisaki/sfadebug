#ifndef _DEBUG_DIMENU_H_
#define _DEBUG_DIMENU_H_

typedef enum {
    Unk0 = 0,
    Adjustable = 1, //Choose a value
    Unk2 = 2,
    Selectable = 3, //Selecting it calls a function
    Header = 4, //Not selectable
    CBoostRelated = 5,
    End = 10 //End of list
} DiMenuType;

typedef enum {
    DiMenuOpcode_Tick           = 0x00,
    DiMenuOpcode_Increment      = 0x01,
    DiMenuOpcode_Decrement      = 0x02,
    DiMenuOpcode_AllocedStrings = 0x03,
    DiMenuOpcode_MenuExit       = 0x04, //exiting this menu
    DiMenuOpcode_APressed       = 0x0A,
    DiMenuOpcode_BPressed       = 0x0B,
    DiMenuOpcode_StartPressed   = 0x0C,
    DiMenuOpcode_AReleased      = 0x14,
    DiMenuOpcode_BReleased      = 0x15,
    DiMenuOpcode_StartReleased  = 0x16,
    DiMenuOpcode_AHeld          = 0x1E,
    DiMenuOpcode_BHeld          = 0x1F,
    DiMenuOpcode_StartHeld      = 0x20,
    DiMenuOpcode_MenuEnter      = 0x28,	//just entered this menu
    DiMenuOpcode_Unk29          = 0x29,
} DiMenuOpcode;

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
    /* 0x00 */ u8 type; //DiMenuType
    /* 0x02 */ u16 width; //0=auto, 0xFFFF=centre?
    /* 0x04 */ u16 height;
    /* 0x08 */ u32 color; //if 0, don't set
    /* 0x0c */ char *text;
    /* 0x10 */ DiMenuItemStrings strs;
    /* 0x14 */ union {
        int (*op29)(char**, /* DiMenuOp* */ void*);
        int (*activate)(char*, /* DiMenuOp* */ void*);
        int (*adjust)(int*, /* DiMenuOp* */ void*);
    };
    /* 0x18 */ s8 heightFlags18; //maybe bool
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

typedef struct {
    /* 0x00 */ u8 op; //DiMenuOpcode
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ char *str;
    /* 0x08 */ Gfx **gfx;
    /* 0x0c */ Mtx *mtx;
    /* 0x10 */ N64Vertex *vtx;
    /* 0x14 */ Pol *pol;
    /* 0x18 */ int frameCount;
    /* 0x1c */ DiMenuItem *item1C;
    /* 0x20 */ DiMenuItem *item20;
    /* 0x24 */ DiMenuItem *item24;
} DiMenuOp;

typedef struct {
    /* 0x0 */ /* N64Button32 */ u32 buttons; //999999 = end
    /* 0x4 */ /* DiMenuOpcode */ u8 onPress; //button was just pressed
    /* 0x5 */ /* DiMenuOpcode */ u8 onRelease; //button was just released
    /* 0x6 */ /* DiMenuOpcode */ u8 onHold; //button is held
    /* 0x7 */ u8 unk07;
} DiMenuButtonCmds;

void ObjEdit_init(void);
N64Button n64GetEnabledButtonsHeld(int pad);
s8 getStickX2(int pad);
s8 getStickY2(int pad);
uint getScreenResolution();
int debugPrintMeasureStr(char *param1,...);
int diPrintf(const char *fmt, ...);
void dprintSetColor(u8 r,u8 g,u8 b,u8 a);
/* 8017a870 */ void diMenuInit(void (*callback)(void), int param_2);
/* 8017a8d0 */ void diMenuPush(DiMenuItem *items, uint space);
/* 8017ad58 */ void diMenuPop(void);
/* 8017ae58 */ void diMenuPopAll(void);
/* 8017ae88 */ void diMenuUpdate(
    Gfx **gfx, Mtx *mtx, N64Vertex *vtx, Pol *pol, int framesTimes65536);
/* 8017afc4 */ BOOL diMenuIsVisible(void);
/* 8017afcc */ void diMenuShow(void);
/* 8017afd8 */ void diMenuHide(void);
/* 8017afe4 */ void diMenuEnable(void);
/* 8017aff0 */ void diMenuDisable(void);
/* 8017affc */ void diMenuStringInit(DiMenuItem *item);
/* 8017b10c */ void diMenuItemDoControls(DiMenuItem *item);
/* 8017b384 */ void diMenuDrawCur(void);
/* 8017ba10 */ int diMenuItemActivate(
    DiMenuItem *item, /* DiMenuOpcode */ int op);
/* 8017bb40 */ char *diMenuItemGetDisplayText(DiMenuItem *item);
/* 8017bd08 */ void diMenuCurGoNextItem(void);
/* 8017bddc */ void diMenuCurGoPrevItem(void);
/* 8017bee8 */ void diMenuItemIncrementCurrent(void);
/* 8017bf74 */ void diMenuItemDecrementCurrent(void);

#endif //_DEBUG_DIMENU_H_
