#include "dolphin.h"
#include "types.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/dll.h"
#include "debug/debug.h"
#include "debug/dimenu.h"

#define MAX_MENU_DEPTH   10
#define MAX_MENU_STRINGS 50
#define MENU_ANALOG_DEADZONE 50

/* 80306F20 */ extern DiMenuButtonCmds DiMenuButtonCmds_ARRAY_80306f20[4];

/* 80390508 */ DiMenuStruct3 diMenuStruct3_80390508[1]; // wtf
/* 80390534 */ DiMenuStruct3 diMenuStack[MAX_MENU_DEPTH];
/* 803906EC */ DiMenuStrings diMenuStrings[MAX_MENU_STRINGS];
/* 80390944 */ bool diMenuStringIsUsed[MAX_MENU_STRINGS];

// 80398240: .sbss
/* 80399860 */ extern s8 diMenuItemFlag_80399860;
/* 80399864 */ extern Gfx *diMenuGfx;
/* 80399868 */ extern Mtx *diMenuMtx;
/* 8039986C */ extern N64Vertex *diMenuVtx;
/* 80399870 */ extern Pol *diMenuPol;
/* 80399874 */ extern int diMenuFrameCount80399874;
/* 80399878 */ extern DiMenuStruct3 *diMenuCur;
/* 8039987C */ extern int diMenuStackDepth;
/* 80399880 */ extern N64Button32 debugN64ButtonsPressed;
/* 80399884 */ extern bool diMenuVisible;
/* 80399885 */ extern bool
    diMenuCanOpen; // true: do not allow Start/Z+Start to hide/show menu
/* 80399886 */ extern bool disableMenus;
/* 80399888 */ extern DiMenuItem *diMenuPendingPush;
/* 8039988C */ extern int diMenuSpace;
/* 80399890 */ extern u8 diMenuPendingPopCnt;
/* 80399894 */ extern u32 diMenuPrevButtons;
/* 80399898 */ extern u8 diMenuItemSelectDelay;
/* 80399899 */ extern u8 diMenuItemAdjustDelay;

static void dummy() {
	// force variable order
	diMenuStruct3_80390508;
	diMenuStack;
	diMenuStrings;
	diMenuStringIsUsed;
}

N64Button n64GetEnabledButtonsHeld(int pad);
s8 getStickX2(int pad);
s8 getStickY2(int pad);
uint getScreenResolution();
/* 8017a870 */ void diMenuInit(void (*callback)(void), int param_2);
/* 8017a8d0 */ void diMenuPush(DiMenuItem *items, uint space);
/* 8017ad58 */ void diMenuPop(void);
/* 8017ae58 */ void diMenuPopAll(void);
/* 8017ae88 */ void diMenuUpdate(
    Gfx *gfx, Mtx *mtx, N64Vertex *vtx, Pol *pol, int framesTimes65536);
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
/* 8017bd08 */ void diMenuCurGoNextItem(void);
/* 8017bddc */ void diMenuCurGoPrevItem(void);
/* 8017bee8 */ void diMenuItemIncrementCurrent(void);
/* 8017bf74 */ void diMenuItemDecrementCurrent(void);

void diMenuInit(void (*callback)(void), int param_2) { // 8017A870
	int iVar1;

	for(iVar1 = 0; iVar1 < 0x32; iVar1 += 1) {
		diMenuStringIsUsed[iVar1] = false;
	}
	ObjEdit_init();
	(*callback)();
}

void diMenuPush(DiMenuItem *items, uint space) { // 8017a8d0
	int tmpWidth;
	int screenRes;
	int width;
	int ii;
	int i2;
	int widest;
	DiMenuItemStrings *strs;

	screenRes = getScreenResolution();
	if(disableMenus) {
		diMenuPendingPush = items;
		diMenuSpace = space;
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
	for(; items->type != End; items++) {
		if(items->type == Adjustable) diMenuStringInit(items);
	}

	diMenuCur->lastItem = items;
	items = diMenuCur->items;

	// measure string dimensions
	diMenuCur->minW = 0;
	diMenuCur->minH = 0;
	diMenuCur->maxH = SCREEN_HEIGHT;
	diMenuCur->maxW = SCREEN_WIDTH;

	while(items < diMenuCur->lastItem) {
		items->heightFlags18 = 0;
		width = debugPrintMeasureStr(items->text);
		switch(items->type) {
			case Header: {
				if(items->strs.iStrs != 0) {
					width += debugPrintMeasureStr(items->strs.str)
					    + debugPrintMeasureStr(" ");
				}
				break;
			}
			case CBoostRelated:
				width += 10;
				// fall thru
			case Unk0: width += debugPrintMeasureStr("00000"); break;
			case Adjustable: {
				strs = &diMenuStrings[items->strs.iStrs].strs;
				widest = 0;
				for(i2 = 0; strs->pStr[i2]; i2++) {
					tmpWidth = debugPrintMeasureStr(strs->pStr[i2]);
					if(tmpWidth > widest) widest = tmpWidth;
				}
				width += widest;
				break;
			}
		}
		if(items->width == 0xFFFF) ii = (SCREEN_WIDTH / 2) - (width / 2);
		else if(items->width != 0)
			ii = items->width;

		if((items->width != 0) || (0 < items->height)) {
			if(ii < diMenuCur->maxW) diMenuCur->maxW = ii;
			if((items->width != 0xFFFF) || (0 < items->height)) {
				if(items->height < diMenuCur->maxH) {
					diMenuCur->maxH = items->height;
				}
				if(items->height > diMenuCur->minH) {
					diMenuCur->minH = items->height;
				}
			}
		}

		if(items->width == 0xFFFF) {
			items->heightFlags18 = 1;
			items->width = (SCREEN_WIDTH / 2) - (width / 2);
		}
		if(items->width + width > diMenuCur->minW) {
			diMenuCur->minW = items->width + width;
		}
		if((width + diMenuCur->maxW) > diMenuCur->minW) {
			diMenuCur->minW = width + diMenuCur->maxW;
		}

		items++;
		if(diMenuCur->minH < (SCREEN_HEIGHT - 10)) { diMenuCur->minH += 11; }
	}

	if(diMenuCur->maxW >= 20) {
		diMenuCur->maxW -= 20;
	} else {
		diMenuCur->maxW = 0;
	}
	diMenuCur->minW += 20;

	if(SCREEN_WIDTH < (screenRes & 0xffff)) {
		diMenuCur->maxW <<= 1;
		diMenuCur->minW <<= 1;
	}
	if(SCREEN_HEIGHT < (screenRes >> 0x10)) {
		diMenuCur->maxH <<= 1;
		diMenuCur->minH <<= 1;
	}
	if(diMenuCur->curItem->type == Header) { diMenuCurGoNextItem(); }

	diMenuCur->firstDispItem = diMenuCur->items;
	if(space) {
		if(diMenuItemFlag_80399860) {
			// this is just a memcpy
			u8 *dst = (u8 *)diMenuCur;
			u8 *src = (u8 *)&diMenuStruct3_80390508;
			for(ii = 0; ii < sizeof(DiMenuStruct3); ii++) { dst[ii] = src[ii]; }
		}
		diMenuCur->spaceFlag28 = 1;
	}
	diMenuStackDepth += 1;
	diMenuItemActivate(diMenuCur->items, DiMenuOpcode_MenuEnter);
	!diMenuStruct3_80390508;
}

void diMenuPop(void) { // 8017AD58
	DiMenuItem *item;

	if(disableMenus) {
		diMenuPendingPopCnt++;
		return;
	}
	if(diMenuStackDepth <= 0) return;

	for(item = diMenuCur->items; item < diMenuCur->lastItem; item++) {
		diMenuItemActivate(item, DiMenuOpcode_MenuExit);
		if(item->type == Adjustable) {
			diMenuStringIsUsed[(item->strs).iStrs] = false;
			item->strs = diMenuStrings[(item->strs).iStrs].strs;
		}
	}
	item = diMenuCur->items;
	diMenuItemActivate(item, DiMenuOpcode_Unk29);
	diMenuStackDepth--;
	if(diMenuStackDepth == 0) diMenuCur = NULL;
	else
		diMenuCur = &diMenuStack[diMenuStackDepth - 1];
}

void diMenuPopAll(void) { // 8017AE58
	while(diMenuStackDepth != 0) { diMenuPop(); }
}

void diMenuUpdate(Gfx *gfx, Mtx *mtx, N64Vertex *vtx, Pol *pol,
    int framesTimes65536) { // 8017AE88
	N64Button bHeld;
	uint ii;

	if(!diMenuCur) return;
	diMenuGfx = gfx;
	diMenuMtx = mtx;
	diMenuVtx = vtx;
	diMenuPol = pol;
	if((int)diMenuCur->spaceFlag28 != 0) {
		u8 *src;
		u8 *dst;
		diMenuItemFlag_80399860 = 1;
		src = (u8 *)&diMenuCur->curItem;
		dst = (u8 *)&diMenuStruct3_80390508;
		for(ii = 0; ii < sizeof(DiMenuStruct3); ii++) { dst[ii] = src[ii]; }
	}
	diMenuFrameCount80399874 = framesTimes65536;
	debugN64ButtonsPressed = n64GetEnabledButtonsPressed(0) & 0xffff;
	bHeld = n64GetEnabledButtonsHeld(0);
	if(!diMenuCanOpen) {
		// Start: hide menu
		// Hold Z, press Start: show menu
		if((debugN64ButtonsPressed & N64_BUTTON_START) && diMenuVisible) {
			diMenuVisible = 0;
		} else if((debugN64ButtonsPressed & N64_BUTTON_START)
		    && (bHeld & N64_BUTTON_Z) && !diMenuVisible) {
			diMenuVisible = 1;
		}
	}
	if(diMenuVisible) {
		diMenuDrawCur();
		diMenuItemDoControls(diMenuCur->items);
	}
}

BOOL diMenuIsVisible(void) { // 8017AFC4
	return diMenuVisible;
}

void diMenuShow(void) { // 8017AFCC
	diMenuVisible = true;
}

void diMenuHide(void) { // 8017AFD8
	diMenuVisible = false;
}

void diMenuEnable(void) { // 8017AFE4
	diMenuCanOpen = true;
}

void diMenuDisable(void) { // 8017AFF0
	diMenuCanOpen = false;
}

void diMenuStringInit(DiMenuItem *item) { // 8017affc
	int iVar2;
	int iStr;
	DiMenuStrings *strEnt;

	iStr = -1;
	if(item->strs.iStrs > MAX_MENU_STRINGS) {
		for(iVar2 = 0; iVar2 < MAX_MENU_STRINGS && iStr == -1; iVar2++) {
			if(diMenuStringIsUsed[iVar2] == 0) {
				iStr = iVar2;
				diMenuStringIsUsed[iVar2] = 1;
			}
		}
		if(iStr != -1) {
			strEnt = &diMenuStrings[iStr];
			strEnt->strs = item->strs;
			strEnt->nStrs = 0;
			while(strEnt->strs.pStr[strEnt->nStrs] != 0) { strEnt->nStrs++; }
			strEnt->nStrs--;
			(item->strs).iStrs = iStr;
		} else {
			printf("diMenuStringInit: Run out of string structures!\n");
			return;
		}
	} else {
		strEnt = &diMenuStrings[item->strs.iStrs];
	}
	strEnt->iStr = diMenuItemActivate(item, 3);
}

void diMenuItemDoControls(DiMenuItem *item) { // 8017b10c
	int sy;
	int sx;
	N64Button32 bHeld;
	DiMenuButtonCmds *pDVar1;

	sy = getStickY2(0);
	sx = getStickX2(0);
	bHeld = n64GetEnabledButtonsHeld(0);
	if((n64GetEnabledButtonsHeld(2) & N64_BUTTON_Z) != 0) {
		sy = getStickY2(2);
		sx = getStickX2(2);
		bHeld = n64GetEnabledButtonsHeld(2);
	}
	disableMenus = 1;
	while(item->type != End) {
		diMenuItemActivate(item, 0);
		for(pDVar1 = DiMenuButtonCmds_ARRAY_80306f20;
		pDVar1->buttons != 999999; pDVar1++) {
			if(item == diMenuCur->curItem) {
				if(((bHeld & pDVar1->buttons))
				&& ((diMenuPrevButtons & pDVar1->buttons) == 0)) {
					diMenuItemActivate(item, (uint)pDVar1->onPress);
				}
				else if((bHeld & pDVar1->buttons)) {
					diMenuItemActivate(item, (uint)pDVar1->onHold);
				} else if((diMenuPrevButtons & pDVar1->buttons)) {
					diMenuItemActivate(item, (uint)pDVar1->onRelease);
				}
			}
		}
		if(item == diMenuCur->curItem) {
			if(sx < -MENU_ANALOG_DEADZONE) {
				if((diMenuItemAdjustDelay == 0)
				|| (diMenuItemAdjustDelay > 10)) {
					diMenuItemDecrementCurrent();
				}
				diMenuItemAdjustDelay++;
			} else if(sx > MENU_ANALOG_DEADZONE) {
				if((diMenuItemAdjustDelay == 0)
				    || (diMenuItemAdjustDelay > 10)) {
					diMenuItemIncrementCurrent();
				}
				diMenuItemAdjustDelay += 1;
			} else {
				diMenuItemAdjustDelay = 0;
			}
		}
		item = item + 1;
	}

	if(sy > MENU_ANALOG_DEADZONE) {
		if((diMenuItemSelectDelay == 0)
			|| (10 < diMenuItemSelectDelay)) {
			diMenuCurGoPrevItem();
		}
		diMenuItemSelectDelay++;

	}
	else if(sy < -MENU_ANALOG_DEADZONE) {
		if((diMenuItemSelectDelay == 0)
			|| (diMenuItemSelectDelay > 10)) {
			diMenuCurGoNextItem();
		}
		//holding the stick for 10 frames will activate auto repeat
		diMenuItemSelectDelay++;
	} else {
		diMenuItemSelectDelay = 0;
	}
	diMenuPrevButtons = bHeld;
	disableMenus = 0;
	for(; diMenuPendingPopCnt; diMenuPendingPopCnt--) {
		diMenuPop();
	}
	if(diMenuPendingPush) {
		diMenuPush(diMenuPendingPush, diMenuSpace);
		diMenuPendingPush = NULL;
	}
}

void diMenuDrawCur(void) { // 8017b384
	uint *puVar1;
	char *itemStr;
	int iVar2;
	int iVar3;
	uint uVar4;
	Gfx *puVar6;
	Gfx *puVar2;
	Gfx *puVar5;
	Gfx *puVar10;
	Gfx *puVar9;
	u32 *cmd;
	Gfx *rsp;
	uint width;
	uint x;
	uint y;
	DiMenuItem *items;
	DiMenuItem *item;
	double fltVal;
	uint height;
	bool needPrintMore;
	DiMenuItem **pItems;

#if 0
  x = 0;
  height = 0;
  y = getScreenResolution();
  GXSetScissor(0,0,y & 0xffff,y >> 0x10);
  rsp = (Gfx *)diMenuGfx->cmd;
  diMenuGfx->cmd = (u32)(rsp + 1);
  rsp->cmd = G_SETSCISSOR;
  fltVal = 4503599627370496.0;
  rsp->param = ((int)((float)((double)CONCAT44(0x43300000,y & 0xffff) - 4503599627370496.0) * 4.0) &
               0xfffU) << 0xc |
               (int)((float)((double)CONCAT44(0x43300000,y >> 0x10) - 4503599627370496.0) * 4.0) &
               0xfffU;
  cmd = (u32 *)diMenuGfx->cmd;
  diMenuGfx->cmd = (u32)(cmd + 2);
  *cmd = G_RDPPIPESYNC;
  cmd[1] = G_MW_MATRIX_or_G_MW_MATRIX;
  puVar9 = (Gfx *)diMenuGfx->cmd;
  puVar9->cmd = ~G_MOVEMEM;
  puVar9->param = 0xfffdf6fb;
  RSP::pipeSync(diMenuGfx);
  puVar10 = (Gfx *)diMenuGfx->cmd;
  puVar10->cmd = 0xef002c00;
  puVar10->param = (u32)&DAT_00504240;
  LAB_800a697c((Gfx **)diMenuGfx);
  RSP::setTevColor1(diMenuGfx,0xff,0xff,0xff,0xff);
  RSP::setTevColor2(diMenuGfx,0x1f,0x1f,0x1f,0x90);
  puVar1 = (uint *)diMenuGfx->cmd;
  diMenuGfx->cmd = (u32)(puVar1 + 2);
  *puVar1 = (diMenuCur->minW & 0x3ff) << 0xe | 0xf6000000 | (diMenuCur->minH & 0x3ffU) << 2;
  puVar1[1] = (diMenuCur->maxH & 0x3ff) << 0xe | (diMenuCur->maxW & 0x3ffU) << 2;
  RSP::pState->bNeedPipeSync = true;
  dprintSetBgColor(0x1f,0x1f,0x1f,0);
  pItems = &diMenuCur->items;
  needPrintMore = diMenuCur->firstDispItem != diMenuCur->items;
  diMenuCur->bWrap = FALSE;
  items = *pItems;
  do {
    item = items;
    if (item->type == End) {
      return;
    }
    y = height;
    if (((item->heightFlags18 & 1U) == 0) || (0 < item->width)) {
      if ((item->height != 0) || (0 < item->width)) {
        x = (uint)(ushort)item->height;
        y = (uint)(ushort)item->width;
      }
    }
    else {
      x = (uint)(ushort)item->height;
    }
    if (needPrintMore) {
      width = debugPrintMeasureStr(item->text);
      if ((item->strs).iStrs != 0) {
        itemStr = diMenuItemPrintVal(fltVal,item);
        iVar2 = debugPrintMeasureStr(itemStr);
        iVar3 = debugPrintMeasureStr(" ");
        width = iVar3 + iVar2 + width;
      }
      uVar4 = debugPrintMeasureStr("More");
      dprintSetPos((x + ((int)width >> 1) + (uint)((int)width < 0 && (width & 1) != 0)) -
                   (((int)uVar4 >> 1) + (uint)((int)uVar4 < 0 && (uVar4 & 1) != 0)),y - 0xb);
      dprintSetColor(0xff,0xff,0xff,0xff);
      puVar6 = (Gfx *)diMenuGfx->cmd;
      diMenuGfx->cmd = (u32)(puVar6 + 1);
      puVar6->cmd = G_RDPPIPESYNC;
      puVar6->param = 0;
      RSP::setTevColor2(diMenuGfx,0x1f,0x7f,0x1f,0x90);
      puVar2 = (Gfx *)diMenuGfx->cmd;
      diMenuGfx->cmd = (u32)(puVar2 + 1);
      puVar2->cmd = (diMenuCur->minW & 0x3ff) << 0xe | 0xf6000000 | (diMenuCur->maxW & 0x3ffU) << 2;
      puVar2->param = (diMenuCur->maxH & 0x3ff) << 0xe | (diMenuCur->maxW + -0xb) * 4 & 0xffcU;
      RSP::pState->bNeedPipeSync = true;
      diPrintf("More\n");
      needPrintMore = false;
      diMenuCur->bWrap = TRUE;
    }
    dprintSetPos(x,y);
    if (item == diMenuCur->curItem) {
      dprintSetColor(0xff,0xff,0xff,0xff);
    }
    else if (((uint)item->color & 0xff |
             (uint)item->color >> 8 & 0xff |
             (uint)item->color >> 0x18 | (uint)item->color >> 0x10 & 0xff) != 0) {
      dprintSetColor((item->color).r,(item->color).g,(item->color).b,(item->color).a);
    }
    height = y;
    if (diMenuCur->firstDispItem <= item) {
      diMenuCur->lastDispItem = item;
      if (item->type == Header) {
        if ((item->strs).iStrs == 0) {
          diPrintf("%s\n",item->text);
        }
        else {
          diPrintf("%s %s\n",item->text,(item->strs).iStrs);
        }
      }
      else {
        iVar2 = strlen(item->text);
        if (iVar2 == 0) {
          itemStr = diMenuItemPrintVal(fltVal,item);
          diPrintf("%s\n",itemStr);
        }
        else {
          itemStr = diMenuItemPrintVal(fltVal,item);
          diPrintf("%s %s\n",item->text,itemStr);
        }
      }
      height = y + 0xb;
      if (item->width == -1) {
        height = y + 0x10;
      }
    }
    items = item + 1;
  } while (((height & 0xffff) + 0xb < 231) || (items->type == End));
  diMenuCur->bWrap = TRUE;
  dprintSetPos(x,height);
  dprintSetColor(0xff,0xff,0xff,0xff);
  puVar5 = (Gfx *)diMenuGfx->cmd;
  diMenuGfx->cmd = (u32)(puVar5 + 1);
  puVar5->cmd = G_RDPPIPESYNC;
  puVar5->param = 0;
  RSP::setTevColor2(diMenuGfx,0x1f,0x7f,0x1f,0x90);
  puVar1 = (uint *)diMenuGfx->cmd;
  diMenuGfx->cmd = (u32)(puVar1 + 2);
  *puVar1 = (diMenuCur->minW & 0x3ff) << 0xe | 0xf6000000 | (diMenuCur->minH + 0xb) * 4 & 0xffcU;
  puVar1[1] = (diMenuCur->maxH & 0x3ff) << 0xe | (diMenuCur->minH & 0x3ffU) << 2;
  RSP::pState->bNeedPipeSync = true;
  y = debugPrintMeasureStr(item->text);
  if ((item->strs).iStrs != 0) {
    itemStr = diMenuItemPrintVal(fltVal,item);
    iVar2 = debugPrintMeasureStr(itemStr);
    iVar3 = debugPrintMeasureStr(" ");
    y = iVar3 + iVar2 + y;
  }
  width = debugPrintMeasureStr("More");
  dprintSetPos((x + ((int)y >> 1) + (uint)((int)y < 0 && (y & 1) != 0)) -
               (((int)width >> 1) + (uint)((int)width < 0 && (width & 1) != 0)),height);
  diPrintf("More\n");
#endif
}

int diMenuItemActivate(DiMenuItem *item, /* DiMenuOpcode */ int op) { // 8017ba10
	int iStr;
	undefined4 uVar1;
	DiMenuOp oper;

	if(item->func == NULL) {
		uVar1 = 0;
	} else {
		oper.op = op;
		oper.gfx = diMenuGfx;
		oper.mtx = diMenuMtx;
		oper.vtx = diMenuVtx;
		oper.pol = diMenuPol;
		oper.frameCount = diMenuFrameCount80399874;
		oper.item1C = (DiMenuItem *)(((int)item - (int)diMenuCur->items)
		    / sizeof(DiMenuItem));
		oper.item20
		    = (DiMenuItem *)(((int)diMenuCur->curItem - (int)diMenuCur->items)
		        / sizeof(DiMenuItem));
		oper.item24 = item;
		if(op == 0x29) {
			uVar1 = item->func(&item->strs, &oper);
		} else if(item->type == Adjustable) {
			iStr = (item->strs).iStrs;
			oper.str = *(char **)(diMenuStrings[iStr].strs.str
			    + diMenuStrings[iStr].iStr * 4);
			// uVar1 = item->func(iStr * 0xc + -0x7fc6f910,&oper);
		} else {
			oper.str = NULL;
			uVar1 = item->func(&item->strs, &oper);
		}
	}
	return uVar1;
}

void diMenuCurGoNextItem(void) { // 8017bd08
	DiMenuItem *start;
	bool done;

	done = false;
	start = diMenuCur->curItem;
	while(true) {
		if(done) { return; }
		diMenuCur->curItem = diMenuCur->curItem + 1;
		done = true;
		if(diMenuCur->curItem->type == End) {
			if(diMenuCur->bWrap == FALSE) {
				diMenuCur->curItem = diMenuCur->items;
			} else {
				diMenuCur->curItem = start;
			}
		}
		if(diMenuCur->lastDispItem < diMenuCur->curItem) {
			diMenuCur->firstDispItem = diMenuCur->firstDispItem + 1;
		}
		if(diMenuCur->curItem == start) break;
		if(diMenuCur->curItem->type == Header) { done = false; }
	}
	return;
}

void diMenuCurGoPrevItem(void) { // 8017bddc
	DiMenuItem *start;
	bool done;

	done = false;
	start = diMenuCur->curItem;
	while(true) {
		if(done) { return; }
		done = true;
		if(diMenuCur->curItem == diMenuCur->items) {
			if(diMenuCur->bWrap == FALSE) {
				while(diMenuCur->curItem->type != End) {
					diMenuCur->curItem = diMenuCur->curItem + 1;
				}
				diMenuCur->curItem = diMenuCur->curItem + -1;
			} else {
				diMenuCur->curItem = start;
			}
		} else {
			diMenuCur->curItem = diMenuCur->curItem + -1;
		}
		if(diMenuCur->curItem < diMenuCur->firstDispItem) {
			diMenuCur->firstDispItem = diMenuCur->firstDispItem + -1;
		}
		if(diMenuCur->curItem == start) break;
		if(diMenuCur->curItem->type == Header) { done = false; }
	}
	return;
}

void diMenuItemIncrementCurrent(void) { // 8017bee8
	int iVar1;

	if(diMenuCur->curItem->type == Adjustable) {
		iVar1 = (diMenuCur->curItem->strs).iStrs;
		if((int)diMenuStrings[iVar1].iStr < (int)diMenuStrings[iVar1].nStrs) {
			diMenuStrings[iVar1].iStr = diMenuStrings[iVar1].iStr + 1;
		} else {
			diMenuStrings[iVar1].iStr = 0;
		}
	}
	diMenuItemActivate(diMenuCur->curItem, 1);
	return;
}

void diMenuItemDecrementCurrent(void) { // 8017bf74
	int iVar1;

	if(diMenuCur->curItem->type == Adjustable) {
		iVar1 = (diMenuCur->curItem->strs).iStrs;
		if((int)diMenuStrings[iVar1].iStr < 1) {
			diMenuStrings[iVar1].iStr = diMenuStrings[iVar1].nStrs;
		} else {
			diMenuStrings[iVar1].iStr = diMenuStrings[iVar1].iStr - 1;
		}
	}
	diMenuItemActivate(diMenuCur->curItem, 2);
	return;
}
