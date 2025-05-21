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
    /* 0x04 */ s16 height; //why is one signed and the other not?
    /* 0x08 */ u32 color; //if 0, don't set
    /* 0x0c */ char *text;
    /* 0x10 */ DiMenuItemStrings strs;
    /* 0x14 */ int (*func)(DiMenuItemStrings*, /* DiMenuOp* */ void*);
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
    /* 0x08 */ Gfx *gfx;
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
int debugPrintMeasureStr(char *param1, ...);
int diMenuItemActivate(DiMenuItem *item, /* DiMenuOpcode */ int op);
void diMenuInit(void (*callback)(void), int param_2);
//void diMenuPush(DiMenuItem *items, uint space);
//void diMenuPop(void);
void diMenuPopAll(void);
void diMenuUpdate(Gfx *gfx, Mtx *mtx, N64Vertex *vtx, Pol *pol, int framesTimes65536);
BOOL diMenuIsVisible(void);
void diMenuShow(void);
void diMenuHide(void);
void diMenuEnable(void);
void diMenuDisable(void);

#endif //_DEBUG_DIMENU_H_
