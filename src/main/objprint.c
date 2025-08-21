#include "dolphin.h"
#include "dolphin/gx/GXStruct.h"
#include "dolphin/mtx.h"
#include "gfx/models/models.h"
#include "macros.h"
#include "sys/dll.h"
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
void objPrintFn_80095cd4(Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx, Model *mod, ModelInstance *mInst);
Mtx44Ptr modelInstGetjMtx(ModelInstance *modelInstance,int iMtx);
void debugRenderFn80095844(Gfx_ **gfx, Mtx44 **mtx, N64Vertex **vtx,
Pol **pol, ObjInstance *obj);

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
        debugRenderFn80095844(gfx, mtx, vtx, pol, obj);
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

Mtx44Ptr pMtx_80398ad8;

ModelInstance *playerBoneFn_80094cbc(Gfx_ **gfx, Mtx44 **mtx, Pol **pol,
N64Vertex **vtx, ObjInstance *obj, ModelInstance *mInst, Mtx44Ptr mtx2,
undefined4 param_8, ObjInstance *player, int iAttachPoint) {
	Mtx44Ptr jMtx;
	Model *model;
	int ii;
	ModelInstance *frame;
	ObjPos pos;
	int iBone;

	pMtx_80398ad8 = NULL;
	frame = player->frames[player->modelno];
	if(frame && ((mInst->flags & ModelFlags18_MtxsLoaded) == 0)) {
		model = frame->mod;
		if(obj->objdata->noplacements) {
			if(obj->modelno >= 6) printf("2: objprint.c: modelno overflow\n");
			iBone = (&obj->objdata->pAttachPoints[iAttachPoint].bone)[obj->modelno];
			pos.pos.x = obj->objdata->pAttachPoints[iAttachPoint].pos.x;
			pos.pos.y = obj->objdata->pAttachPoints[iAttachPoint].pos.y;
			pos.pos.z = obj->objdata->pAttachPoints[iAttachPoint].pos.z;
			pos.scale = 1.0f;
			pos.rotation.x = obj->objdata->pAttachPoints[iAttachPoint].rot.x;
			pos.rotation.y = obj->objdata->pAttachPoints[iAttachPoint].rot.y;
			pos.rotation.z = obj->objdata->pAttachPoints[iAttachPoint].rot.z;
			mtxSetFromObjPos(mtx2, &pos);
			Mtx44Mult(mtx2, mInst->jMtxs[mInst->flags & ModelFlags18_UseOtherMtxs] + iBone, mtx2);
		}
		if(model->numAnims) {
			pMtx_80398ad8 = mtx2;
			modelAnimFn_8007e974(frame, model, player, mtx2);
			playerBoneFn_80095044(player, obj, frame);
		} else {
            frame->flags ^= ModelFlags18_UseOtherMtxs;
			jMtx = *frame->jMtxs[frame->flags & ModelFlags18_UseOtherMtxs];
			for(ii = 0; ii < 0x10; ii += 1) {
                ((float*)jMtx)[ii] = ((float*)mtx2)[ii];
            }
			playerBoneFn_80095044(player, obj, frame);
			pMtx_80398ad8 = jMtx;
		}
		frame->flags ^= ModelFlags18_UseOtherMtxs;
		if(((player->objdata->flags & ObjFileStructFlags44_DifferentLightColor)
        || model->bCopyVtxsToModelInst) && model->bCopyVtxsToModelInst) {
			copyVtxsToModelInstance(frame);
		}
		(player->pos).pos.x = pMtx_80398ad8[3][0];
		(player->pos).pos.y = pMtx_80398ad8[3][1];
		(player->pos).pos.z = pMtx_80398ad8[3][2];
		if(player->heldBy) {
			multVectorByObjMtx((double)(player->pos).pos.x,
			    (double)(player->pos).pos.y,
			    (double)(player->pos).pos.z,
			    &(player->prevPos).x,
			    &(player->prevPos).y,
			    &(player->prevPos).z,
			    player->heldBy);
		} else {
            (player->pos).pos.x = (player->pos).pos.x + playerMapOffsetX;
			(player->pos).pos.z = (player->pos).pos.z + playerMapOffsetZ;
			(player->prevPos).x = (player->pos).pos.x;
			(player->prevPos).y = (player->pos).pos.y;
			(player->prevPos).z = (player->pos).pos.z;
		}
		if((player->objdata->noplacements >= 2) && (player->objId == 0x2f)) {
			if(player->heldBy) loadCamMtxFn_8006B318(gfx);
			((LoadedDLL*)player->dll)->funcs->Object.render2C(player, gfx, mtx, pol, vtx);
			if(player->heldBy) playerHeldByFn_8006b200(gfx, mtx, player->heldBy);
		}
	}
	return frame;
}

N64VertexIdxs N64VertexIdxs_ARRAY_802ee158[];

void debugRenderFn80095844(Gfx_ **gfx, Mtx44 **mtx, N64Vertex **vtx,
Pol **pol, ObjInstance *obj) {
	float fVar1;
	float fVar2;
	ModelInstance *mInst;
	int r, g, b;
	HitState *hits;
	ObjPos pos;

    if(obj->objId < 0) return;
    if(obj->hits) {
        hits = obj->hits;
        if(hits->flags5A & HitStateFlags5A_HaveSkeleton) {
            mInst = obj->frames[obj->modelno];
            objLoadSkelMtxFn_80095cc0(gfx, mtx, vtx, pol, mInst, mInst->mod);
        }
        if(hits->flags5A & HitStateFlags5A_RenderFlag2) {
            fVar1 = hits->unk54;
            fVar2 = (hits->unk56 - fVar1) / 2.0f;
            fVar1 = obj->prevPos.y + fVar2;
            r = 0xff; g = 0; b = 0;
            if(hits->flags & HitStateFlags58_AltColor) { r = 0; b = 0xff; }
            drawCircle(gfx, mtx,
                obj->prevPos.x,
                fVar1,
                obj->prevPos.z,
                hits->scale, fVar2,
                r, g, b);
        } else if(hits->flags5A & HitStateFlags5A_RenderFlag1) {
            pos.rotation.x = 0;
            pos.rotation.y = 0;
            pos.rotation.z = 0;
            pos.scale = hits->scale / 79.0;
            pos.pos.x = (obj->pos).pos.x;
            pos.pos.y = (obj->pos).pos.y;
            pos.pos.z = (obj->pos).pos.z;
            mtxLoadFn8006a790(gfx, mtx, &pos, NULL);
            if((hits->flags & HitStateFlags58_AltColor) == 0) {
                RSP_setTevColor2(gfx, 0xff, 0, 0, 0xff);
            } else {
                RSP_setTevColor2(gfx, 0, 0, 0xff, 0xff);
            }
            rspCullFn800a5074(gfx, NULL, NULL, 6, 0, 0, 1);
            RSP_CMD(gfx, 0x0100c018, &BYTE_802ee2b8);
            n64DrawTriangles(gfx, N64VertexIdxs_ARRAY_802ee158, 0x14);
        }
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
	n64DrawTriangles(gfx, &BYTE_802ee158, 0x14);
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

typedef struct {
    int ang[120]; //strange since MAX_JOINTS is 150
} JointAngleStruct;
JointAngleStruct DWORD_802cf020;
JointAngleStruct DWORD_802cf200;

typedef struct {
    int unk[30];
} JointStruct2;
JointStruct2 DWORD_802edf10;

N64VertexIdxs N64VertexIdxs_ARRAY_802edf50[10];
N64VertexIdxs N64VertexIdxs_ARRAY_802edff0[8];

void objPrintFn_80095cd4(Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx,
Model *mod, ModelInstance *mInst) {
    Mtx44 mtxTmp; //470
    Vec pos; //464..470
    ObjPos xf; //458..464
    JointAngleStruct jointXZ; //270
    JointAngleStruct jointY; //90
    JointStruct2 joint2; //18
	ModelSkeletonStruct *skel;
    BOOL bVar1;
    Mtx44Ptr jMtx;
    int ii;
	int jj;
	int iParent;
	float dxz;

	skel = mInst->skeleton;
	jointXZ = DWORD_802cf020;
	jointY = DWORD_802cf200;
    joint2 = DWORD_802edf10;

	for(ii = 1; ii < mod->numJoints; ii++) {
		dxz = sqrt(
            (mod->joints[ii].translation.x * mod->joints[ii].translation.x)
		    +  (mod->joints[ii].translation.z * mod->joints[ii].translation.z));
        jj = getAngle(dxz, mod->joints[ii].translation.y) & 0xffff;
		jointXZ.ang[ii] = jj;
        jj = getAngle(mod->joints[ii].translation.z,
            mod->joints[ii].translation.x) & 0xffff;
		jointY.ang[ii] = jj;
	}

	for(ii = 1; ii < mod->numJoints; ii++) {
		LAB_800a5074(gfx, NULL, NULL, 0x80000002, 0, 0, 1);
		for(jj = 0; jj < 2; jj++) {
			if(jj) iParent = ii;
            else iParent = mod->joints[ii].parent;
			jMtx = (Mtx44Ptr)modelInstGetjMtx(mInst, ii);
            ASSERTLINE(1990, jMtx);
			mtxTmp[3][1] = jMtx[0][3];
			mtxTmp[3][2] = jMtx[1][3];
			mtxTmp[3][3] = jMtx[2][3];
			xf.rotation.z = 0;
			xf.rotation.y = jointXZ.ang[iParent];
			xf.rotation.x = jointY .ang[iParent];
			xf.scale = skel->scale[iParent] / 16.0f;
			if(mod->exT[iParent] <= 1.0f) {
                xf.pos.x = mtxTmp[3][1];
				xf.pos.y = mtxTmp[3][2];
				xf.pos.z = mtxTmp[3][3];
                bVar1 = false;
            } else {
                xf.pos.x = mtxTmp[3][1];
				xf.pos.y = mtxTmp[3][2];
				xf.pos.z = mtxTmp[3][3];
				jMtx = (Mtx44Ptr)modelInstGetjMtx(mInst,
                    mod->joints[ii].parent);
                ASSERTLINE(2014, jMtx);
				mtxTmp[3][1] = jMtx[0][3];
				mtxTmp[3][2] = jMtx[1][3];
				mtxTmp[3][3] = jMtx[2][3];
				xf.pos.x = (xf.pos.x - mtxTmp[3][1]) * (mod->exT[ii] - 1.0f) + xf.pos.x;
				xf.pos.y = (xf.pos.y - mtxTmp[3][2]) * (mod->exT[ii] - 1.0f) + xf.pos.y;
				xf.pos.z = (xf.pos.z - mtxTmp[3][3]) * (mod->exT[ii] - 1.0f) + xf.pos.z;
				bVar1 = true;
			}
			mtxSetFromObjPos(&pos, &xf); //what?
			MTX44_Copy(&pos, *mtx);
            RSP_CMD(gfx, 0xda380002, (*mtx)++);
			if(skel->unk18[iParent] == 0) {
				RSP_setTevColor2(gfx, 0xff, 0xff, 0xff, 0xff);
			} else {
				RSP_setTevColor2(gfx, 0x00, 0x00, 0x00, 0xff);
			}
			if(jj == 0) {
                RSP_CMD(gfx, 0x01004008, &DWORD_802edf10);
			} else {
                RSP_CMD(gfx, 0x01004010, &DWORD_802edf10);
				if(bVar1) n64DrawTriangles(gfx, N64VertexIdxs_ARRAY_802edf50, 10);
				else      n64DrawTriangles(gfx, N64VertexIdxs_ARRAY_802edff0,  8);
			}
            RSP_CMD(gfx, 0xd8380002, 0x40);
		} //for jj
	} //for ii
}
