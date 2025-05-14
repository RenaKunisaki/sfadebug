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

u8 diMenuVar_80390944[50];
/* 80399878 */ DiMenuStruct3 *diMenuCur;
/* 80399886 */ bool disableMenus;
/* 8039987C */ int diMenuStackDepth;
/* 80399888 */ DiMenuItem *diMenuPendingPush;
/* 8039988C */ int diMenuSpace;
/* 80390534 */ DiMenuStruct3 diMenuStack[MAX_MENU_DEPTH];
/* 803906EC */ DiMenuStrings diMenuStrings[MAX_MENU_STRINGS];
/* 80399860 */ s8 diMenuItemFlag_80399860;
/* 80390508 */ u8 BYTE_ARRAY_80390508[44];
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
	int iVar1;
	uint screenRes;
	uint width;
	int iVar2;
	int iVar3;
	int unaff_r29;
	uint ii;
	DiMenuItem *item;
	DiMenuStruct3 *items2;
	DiMenuItem *items_;
	int space_;
	int type;

	screenRes = getScreenResolution();
	items_ = items;
	space_ = space;
	if(disableMenus) {
		diMenuSpace = space_;
		diMenuPendingPush = items_;
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
		if(items->type == Adjustable) { diMenuStringInit(items); }
	}
	diMenuCur->lastItem = items;
	item = diMenuCur->items;

	// measure string dimensions
	diMenuCur->minW = 0;
	diMenuCur->minH = 0;
	diMenuCur->maxW = 240;
	diMenuCur->maxH = 320;
	while(item < diMenuCur->lastItem) {
		item->heightFlags18 = 0;
		width = debugPrintMeasureStr(item->text);
		type = item->type;
		switch(type) {
			case Header: {
				if((item->strs).iStrs != 0) {
					width += debugPrintMeasureStr(item->strs.str) +
						debugPrintMeasureStr(" ");
				}
				break;
			}
			case CBoostRelated:
				width += 10;
				//fall thru
			case Unk0:
				width += debugPrintMeasureStr("00000");
				break;

			case Adjustable: {
				iVar1 = item->strs.iStrs;
				space_ = 0;
				for(iVar3 = 0;
				diMenuStrings[iVar1].strs.pStr[iVar3];
				iVar3 += 1) {
					iVar2 = debugPrintMeasureStr(
						(diMenuStrings[iVar1].strs.pStr[iVar3]));
					if(space_ > iVar2) { space_ = iVar2; }
				}
				width += space_;
				break;
			}
		}

		if(item->height == 0xFFFF) {
			unaff_r29 = 160 - (((int)width / 2)
				+ (width < 0 && (width & 1) != 0));
		} else if(item->height != 0) {
			unaff_r29 = item->height;
		}
		if((item->height != 0) || (0 < item->width)) {
			if(unaff_r29 < diMenuCur->maxH) {
				diMenuCur->maxH = unaff_r29;
			}
			if((item->height != 0xFFFF) || (0 < item->width)) {
				if(item->width < diMenuCur->maxW) {
					diMenuCur->maxW = item->width;
				}
				if(item->width > diMenuCur->minH) {
					diMenuCur->minH = item->width;
				}
			}
		}
		if(item->height == 0xFFFF) {
			item->heightFlags18 = 1;
			item->height = 160
				- (((int)width / 2)
					+ (width < 0 && (width & 1) != 0));
		}
		if(diMenuCur->minW > (item->height + width)) {
			diMenuCur->minW = item->height + width;
		}
		if(diMenuCur->minW > (int)(width + diMenuCur->maxH)) {
			diMenuCur->minW = width + diMenuCur->maxH;
		}
		item = item + 1;
		if(diMenuCur->minH < 230) {
			diMenuCur->minH += 11;
		}
	}
	if(diMenuCur->maxH >= 20) diMenuCur->maxH -= 20;
	else diMenuCur->maxH = 0;
	diMenuCur->minW += 20;
	if(320 < (int)(screenRes & 0xffff)) {
		diMenuCur->maxH <<= 1;
		diMenuCur->minW <<= 1;
	}
	if(240 < (int)screenRes >> 0x10) {
		diMenuCur->maxW <<= 1;
		diMenuCur->minH <<= 1;
	}
	if(diMenuCur->curItem->type == Header) { diMenuCurGoNextItem(); }
	diMenuCur->firstDispItem = diMenuCur->items;

	if(space != 0) {
		if(diMenuItemFlag_80399860 != 0) {
			for(ii = 0; ii < 0x2c; ii += 1) {
				*(u8 *)((int)&items2->curItem + ii)
					= BYTE_ARRAY_80390508[ii];
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
