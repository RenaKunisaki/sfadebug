#include "dolphin.h"
#include "types.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/dll.h"
#include "debug/debug.h"
#include "debug/dimenu.h"

#define MAX_MENU_DEPTH 10
#define MAX_MENU_STRINGS 50

/* 80399878 */ DiMenuStruct3 *diMenuCur;
/* 80399886 */ bool disableMenus;
/* 8039987C */ int diMenuStackDepth;
/* 80399888 */ DiMenuItem *diMenuPendingPush;
/* 8039988C */ int diMenuSpace;
/* 80390534 */ DiMenuStruct3 diMenuStack[MAX_MENU_DEPTH];
/* 803906EC */ DiMenuStrings diMenuStrings[MAX_MENU_STRINGS];
/* 80399860 */ s8 diMenuItemFlag_80399860;
/* 80390508 */ DiMenuStruct3 diMenuStruct3_80390508;
/* 80390944 */ u8 diMenuVar_80390944[50];
/* 80399884 */ bool diMenuVisible;

void ObjEdit_init(void);
int debugPrintMeasureStr(char *param1,...);

void diMenuInit(void (*callback)(void), int param_2) { // 8017A870
	int iVar1;

	for(iVar1 = 0; iVar1 < 0x32; iVar1 += 1) {
		diMenuVar_80390944[iVar1] = 0;
	}
	ObjEdit_init();
	(*callback)();
}

void diMenuPush(DiMenuItem *items, uint space) {
	uint screenRes;
	uint height;
	int width;
	uint ii;
	DiMenuItem *item;
	uint widest;

	screenRes = getScreenResolution();
	widest = space;
	if(disableMenus) {
		diMenuSpace = widest;
		diMenuPendingPush = items;
		return;
	}
	if(diMenuStackDepth == MAX_MENU_DEPTH) {
		printf("diMenu: Menu stack full! Increase MAX_MENU_DEPTH\n");
		return;
	}
	diMenuCur = &diMenuStack[diMenuStackDepth];
	diMenuCur->spaceFlag28 = 0;
	diMenuCur->items = items;
	diMenuCur->curItem = items;
	for(; items->type != End; items = items + 1) {
		if(items->type == Adjustable) diMenuStringInit(items);
	}
	diMenuCur->lastItem = items;
	item = diMenuCur->items;

	// measure string dimensions
	diMenuCur->minW = 0;
	diMenuCur->minH = 0;
	diMenuCur->maxH = SCREEN_HEIGHT;
	diMenuCur->maxW = SCREEN_WIDTH;
	while(item < diMenuCur->lastItem) {
		item->heightFlags18 = 0;
		height = debugPrintMeasureStr(item->text);
		switch(item->type) {
			case Header: {
				if((item->strs).iStrs != 0) {
					height += debugPrintMeasureStr(item->strs.str) +
						debugPrintMeasureStr(" ");
				}
				break;
			}
			case CBoostRelated:
				height += 10;
				//fall thru
			case Unk0:
				height += debugPrintMeasureStr("00000");
				break;

			case Adjustable: {
				DiMenuItemStrings *strs;
				strs = &diMenuStrings[item->strs.iStrs].strs;
				widest = 0;
				for(ii = 0; strs->pStr[ii]; ii++) {
					uint w = debugPrintMeasureStr(strs->pStr[ii]);
					if((int)w > (int)widest) { widest = w; }
				}
				height += widest;
				break;
			}
		}

		if(item->width == 0xFFFF) {
			width = (SCREEN_WIDTH/2) - (((int)height / 2)
				+ (height < 0 && (height & 1) != 0));
		} else if(item->width != 0) {
			width = item->width;
		}
		if((item->width != 0) || (0 < item->height)) {
			if(width < diMenuCur->maxW) {
				diMenuCur->maxW = width;
			}
			if((item->width != 0xFFFF) || (0 < item->height)) {
				if(item->height < diMenuCur->maxH) {
					diMenuCur->maxH = item->height;
				}
				if(item->height > diMenuCur->minH) {
					diMenuCur->minH = item->height;
				}
			}
		}
		if(item->width == 0xFFFF) {
			item->heightFlags18 = 1;
			item->width = (SCREEN_WIDTH/2) - (((int)height / 2) +
				(height < 0 && (height & 1) != 0));
		}
		if(item->width + (int)height > diMenuCur->minW) {
			diMenuCur->minW = item->width + height;
		}
		if((int)(height + diMenuCur->maxW) > diMenuCur->minW) {
			diMenuCur->minW = height + diMenuCur->maxW;
		}
		item = item + 1;
		if(diMenuCur->minH < (SCREEN_HEIGHT-10)) {
			diMenuCur->minH += 11;
		}
	}
	if(diMenuCur->maxW >= 20) diMenuCur->maxW -= 20;
	else diMenuCur->maxW = 0;
	diMenuCur->minW += 20;
	if(SCREEN_WIDTH < (int)(screenRes & 0xffff)) {
		diMenuCur->maxW <<= 1;
		diMenuCur->minW <<= 1;
	}
	if(SCREEN_HEIGHT < (int)screenRes >> 0x10) {
		diMenuCur->maxH <<= 1;
		diMenuCur->minH <<= 1;
	}
	if(diMenuCur->curItem->type == Header) { diMenuCurGoNextItem(); }
	diMenuCur->firstDispItem = diMenuCur->items;

	if(widest) {
		if(diMenuItemFlag_80399860) {
			//this is just a memcpy
			u8 *dst = (u8*)diMenuCur;
			u8 *src = (u8*)&diMenuStruct3_80390508;
			for(ii = 0; ii < sizeof(DiMenuStruct3); ii++) {
				dst[ii] = src[ii];
			}
		}
		diMenuCur->spaceFlag28 = 1;
	}
	diMenuStackDepth += 1;
	diMenuItemActivate(diMenuCur->items, 0x28);
	return;
}

void diMenuPop(void) { // 8017AD58
}

void diMenuPopAll(void) { // 8017AE58
}

void fn_8017AF10(undefined *param_1,
    undefined *param_2,
    int param_3,
    undefined *param_4,
    int framesTimes65536) { // 8017AE88
}

s8 fn_8017AFC4(void) { // 8017AFC4
	return diMenuVisible;
}

void set_diMenuVisible(void) { // 8017AFCC
	diMenuVisible = 1;
}
