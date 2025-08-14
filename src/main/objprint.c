#include "dolphin.h"
#include "dolphin/gx/GXStruct.h"
#include "gfx/models/models.h"
#include "macros.h"
#include "types.h"
#include "sys/n64.h"
#include "gfx/render.h"
#include "obj/Objects.h"
#include "obj/ObjInstance.h"

s8 debugRenderMode;
s8 BYTE_80398afc;
int DAT_80398aec;
u8 framesThisStep;

u8 *Color4b_ARRAY_802ee504;
u8 BYTE_802ee2b8;
u8 BYTE_802ee158;

void playerRender(ObjInstance *object, Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx, bool shouldRender);
void objRenderCurrentModel(ObjInstance *obj);
void objRenderCurrentModel2(ObjInstance *object, Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx, float);
void drawCircle(Gfx_ **gfx,Mtx44 **mtx,float x,float y,float z,float radius,float param_7,u8 r,u8 g, u8 b);
void LAB_8006a790(Gfx_ **gfx,Mtx44 **mtx,ObjPos *pos,float x,float y,Mtx44 *mtx2);

s8 areModelsEnabled(); //maybe areModelsDisabled - not bool
s8 isMainCharacterEnabled(); //maybe isMainCharacterDisabled

void objRender(Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx,
ObjInstance *obj, s8 shouldRender) {
	ObjInstance *child;
	ObjDef *odef;
    ModelInstance *frame;

	if(obj->flags_0xb0 & ObjInstance_FlagsB0_IsFreed) return;
    if(!shouldRender && obj->hits
    && (obj->hits->flags5A & 0x30)) {
        obj->hits->state2 = 2;
    }

    if(!isModelAnimDisabled()) {
        if(obj->pos.flags & ObjInstance_Flags06_Invisible) return;
        if(obj->heldBy && obj->heldBy->pos.flags & ObjInstance_Flags06_Invisible) return;
    }

    if(obj->dll) {
        if(!(obj->flags_0xb0 & ObjInstance_FlagsB0_DontRender)) {
            (((LoadedDLL*)obj->dll)->funcs->Object.func06)(
                obj, gfx, mtx, pol, vtx, shouldRender);
        }
        else if(shouldRender) {
            objRenderCurrentModel2(obj, gfx, mtx, pol, vtx, 1.0f);
        }
    }
    else if(shouldRender) {
        switch(obj->romdefno) {
            case ObjDefNo_Krystal:
            case ObjDefNo_Sabre:
                playerRender(obj, gfx, mtx, pol, vtx, shouldRender);
                break;
            default:
                objRenderCurrentModel2(obj, gfx, mtx, pol, vtx, shouldRender);
        }
    }

    if(obj->nChildren && obj->child[0]) {
        child = obj->child[0];
        frame = child->frames[child->modelno];
        if(child->objId == 0x2f) {
            //not passing vtx here?
            objPrintModelFn_80095044(child, obj, frame, gfx, mtx, pol);
            if(child->objdata->noplacements >= 2) {
                ((LoadedDLL*)child->dll)->funcs->Object.render2C(
                    child, gfx, mtx, pol, vtx);
            }
        }
    }
    if(obj->pos.flags & 0x100) {
        odef = obj->def;
        if(odef && odef->objType != ObjDefNo_curve) {
            if((odef->loadFlags & RomListLoadFlag_loadForOtherMap) == 0) {
                drawCircle(gfx, mtx,
                    odef->pos.x, odef->pos.y, odef->pos.z,
                    (float)(odef->bound * 8), 32.0f, 0, 0, 0);
            }
            drawCircle(gfx, mtx,
                odef->pos.x, odef->pos.y, odef->pos.z,
                (float)(odef->cullDist * 8),
                32.0f, 0, 0xff, 0);
        }
    }
    if(((debugRenderMode == 1 || debugRenderMode == 2)) && shouldRender) {
        LAB_80095968(gfx, mtx, pol, vtx, obj);
    }
    if(((BYTE_80398afc == 1) && shouldRender)
    && obj->objdata->unkac) {
        drawCircle(gfx, mtx,
            obj->pos.pos.x, obj->pos.pos.y, obj->pos.pos.z,
            obj->objdata->unkac * 0.1f, 32.0f,
            0, 0, 0);
        drawCircle(gfx, mtx,
            obj->pos.pos.x, obj->pos.pos.y, obj->pos.pos.z,
            obj->objdata->unkae * 0.1f, 32.0f,
            0x80, 0x80, 0x80);
    }
}

void fn_80094B08(undefined4 param_1) {
    DAT_80398aec = param_1;
}

void objRenderCurrentModel2(ObjInstance *obj, Gfx_ **gfx, Mtx44 **mtx,
Pol **pol, N64Vertex **vtx, float param_6) {
	Gfx_ *gfx2;
	Pol *pol2;
	Mtx44 *mtx2;
    N64Vertex *vtx2;
    Model *mod;
	ModelInstance *frame;
    char pad[120];
    int dummy = 0;
    int dummy2, dummy3;

	if(areModelsEnabled() && obj->objId != 1) return;
    if(isMainCharacterEnabled() && obj->objId == 1) return;
    gfx2 = *gfx;
    mtx2 = *mtx;
    pol2 = *pol;
    if(vtx) vtx2 = *vtx;
    ASSERTLINE(599, obj->frames);
    frame = obj->frames[obj->modelno];
    if(!frame) return;

    mod = frame->mod;
    if(mod->flags & ModelDataFlags2_CopyVtxsOnLoad) {
        RSP_sync(gfx);
        if(obj->shadow && obj->shadow->unk0c) {
            modelAnimFn_800b2af4(obj, 0, 0, framesThisStep);
        }
        objprintDrawGCModel(obj);
        if(obj->romLockdata) renderGCModel(obj);
    } else {
        *gfx = gfx2;
        *mtx = mtx2;
        *pol = pol2;
        if(vtx) *vtx = vtx2;
    }
}

void objRenderCurrentModel(ObjInstance *obj) {
    ModelInstance *frame;
    Model *mod;
    int dummy[4];

    frame = obj->frames[obj->modelno];
    if(!frame) return;
    mod = frame->mod;
    if(mod->flags & ModelDataFlags2_CopyVtxsOnLoad) {
        modelExecRenderStream_(obj,mod);
    }
}

void fn_80095AEC(Gfx_ **gfx, Mtx44 **mtx, u8 iColor,
float x, float y, float z, float scale) {
	ObjPos pos;
    u8 *color;

    color = Color4b_ARRAY_802ee504;
	pos.rotation.x = 0;
	pos.rotation.y = 0;
	pos.rotation.z = 0;
	pos.scale = scale;
	pos.pos.x = x;
	pos.pos.y = y;
	pos.pos.z = z;
	LAB_8006a790(gfx, mtx, &pos, 1.0f, 0.0f, NULL);

    RSP_setTevColor2(gfx,
        color[iColor*3+0],
        color[iColor*3+1],
        color[iColor*3+2],
        0xff);

    LAB_800a5074(gfx, NULL, NULL, 6, 0, 0, 1);
    RSP_CMD(gfx, 0x0100c018, &BYTE_802ee2b8);
	LAB_800a6d9c(gfx, &BYTE_802ee158, 0x14);
}

void fn_80095cc0(Gfx_ **gfx,Mtx44 **mtx,Pol **pol,N64Vertex **vtx,
ModelInstance *mInst, UNKTYPE *param_6) {
    int unk[0x9c]; //0x270 bytes

    unk[0x99] = (int)*pol; //offset 0x284
    unk[0x98] = (int)*vtx; //offset 0x280
    if(mInst->skeleton && (*(u8 *)((int)param_6 + 0xb7))) {
        fn_800BFBBC(*mtx);
        RSP_CMD(gfx, GX_LOADMTXS | 0x380002, ++*mtx);
        ((Vec*)&unk[0x91])->x = //offset 0x26c
        ((Vec*)&unk[0x91])->y = //offset 0x268
        ((Vec*)&unk[0x91])->z = 65536.0f; //offset 0x264

        objPrintFn_80095cd4(gfx,mtx,pol,vtx,param_6,mInst);
    }
}
