#include "dolphin.h"
#include "types.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/dll.h"
#include "debug/debug.h"
#include "debug/dimenu.h"

#define MAX_MENU_DEPTH 10

u8 diMenuVar_80390944[50];
/* 80399878 */ DiMenuStruct3 *diMenuCur;

void ObjEdit_init(void);

void diMenuInit(void (*callback)(void), int param_2) { // 8017A870
	int iVar1;

	for(iVar1 = 0; iVar1 < 0x32; iVar1 += 1) {
		(&diMenuVar_80390944)[iVar1] = 0;
	}
	ObjEdit_init();
	(*callback)();
}


void diMenuPush(DiMenuItem *items, int space) {
	int iVar1;
	uint screenRes;
	uint width;
	int iVar2;
	int iVar3;
	uint unaff_r29;
	uint ii;
	DiMenuItem *item;
	DiMenuStruct3 *items2;
	DiMenuItem *items_;
	int space_;
	DiMenuType type;

	screenRes = getScreenResolution();
	items_ = items;
	space_ = space;
	if(disableMenus == 0) {
		if(diMenuStackDepth == 10) {
			printf("diMenu: Menu stack full! Increase MAX_MENU_DEPTH\n");
			items_ = diMenuPendingPush;
			space_ = diMenuSpace;
		} else {
			diMenuCur = diMenuStack + diMenuStackDepth;
			diMenuStack[diMenuStackDepth].spaceFlag28 = 0;
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
				if(type == Header) {
					if((item->strs).iStrs != 0) {
						space_ = debugPrintMeasureStr(" ");
						iVar1 = debugPrintMeasureStr((item->strs).str);
						width = iVar1 + space_ + width;
					}
				} else if(type < Header) {
					if(type == Adjustable) {
						iVar1 = (item->strs).iStrs;
						space_ = 0;
						for(iVar3 = 0;
						    *(int *)(diMenuStrings[iVar1].strs.str + iVar3 * 4)
						    != 0;
						    iVar3 += 1) {
							iVar2 = debugPrintMeasureStr(
							    *(char **)(diMenuStrings[iVar1].strs.str
							        + iVar3 * 4));
							if(space_ < iVar2) { space_ = iVar2; }
						}
						width += space_;
					} else if(type == Unk0)
						goto LAB_8017aa50;
				} else if(type < 6) {
					width += 10;
				LAB_8017aa50:
					space_ = debugPrintMeasureStr("00000");
					width += space_;
				}
				if(item->height == -1) {
					unaff_r29 = 160
					    - (((int)width >> 1)
					        + (uint)((int)width < 0 && (width & 1) != 0));
				} else if(item->height != 0) {
					unaff_r29 = (uint)(ushort)item->height;
				}
				if((item->height != 0) || (0 < item->width)) {
					if((int)unaff_r29 < (int)diMenuCur->maxH) {
						diMenuCur->maxH = unaff_r29;
					}
					if((item->height != -1) || (0 < item->width)) {
						if((int)item->width < diMenuCur->maxW) {
							diMenuCur->maxW = (int)item->width;
						}
						if(diMenuCur->minH < (int)item->width) {
							diMenuCur->minH = (int)item->width;
						}
					}
				}
				if(item->height == -1) {
					item->heightFlags18 = 1;
					item->height = 160
					    - ((short)((int)width >> 1)
					        + (ushort)((int)width < 0 && (width & 1) != 0));
				}
				if((int)diMenuCur->minW < (int)((ushort)item->height + width)) {
					diMenuCur->minW = (ushort)item->height + width;
				}
				if((int)diMenuCur->minW < (int)(width + diMenuCur->maxH)) {
					diMenuCur->minW = width + diMenuCur->maxH;
				}
				item = item + 1;
				if(diMenuCur->minH < 230) {
					diMenuCur->minH = diMenuCur->minH + 11;
				}
			}
			if((int)diMenuCur->maxH < 20) {
				diMenuCur->maxH = 0;
			} else {
				diMenuCur->maxH = diMenuCur->maxH - 20;
			}
			diMenuCur->minW = diMenuCur->minW + 20;
			if(320 < (screenRes & 0xffff)) {
				diMenuCur->maxH = diMenuCur->maxH << 1;
				diMenuCur->minW = diMenuCur->minW << 1;
			}
			if(240 < (int)screenRes >> 0x10) {
				diMenuCur->maxW = diMenuCur->maxW << 1;
				diMenuCur->minH = diMenuCur->minH << 1;
			}
			if(diMenuCur->curItem->type == Header) { diMenuCurGoNextItem(); }
			diMenuCur->firstDispItem = diMenuCur->items;
			items2 = diMenuCur;
			if(space != 0) {
				if(diMenuItemFlag_80399860 != 0) {
					for(ii = 0; ii < 0x2c; ii += 1) {
						*(byte *)((int)&items2->curItem + ii)
						    = BYTE_ARRAY_80390508[ii];
					}
				}
				diMenuCur->spaceFlag28 = 1;
			}
			diMenuStackDepth += 1;
			diMenuItemActivate(diMenuCur->items, 0x28);
			items_ = diMenuPendingPush;
			space_ = diMenuSpace;
		}
	}
	diMenuSpace = space_;
	diMenuPendingPush = items_;
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
	return debugPrintFlag_80399884;
}

void set_debugPrintFlag_80399884(void) { // 8017AFCC
	debugPrintFlag_80399884 = 1;
}
