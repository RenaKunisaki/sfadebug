#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/models/shaders.h"
#include "gfx/textures.h"
#include "macros.h"
#include "types.h"
#include "debug/debug.h"
#include "sys/alloc.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "gfx/models/models.h"
#include "sys/dll.h"
#include "obj/Objects.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "sys/files.h"
#include <stddef.h>

//strings at 802eb690 - 802ec988
//1280 -> 7c

//x, y, z but not S16Vec or array
s16 objAnimVar_8039872c_x;
s16 objAnimVar_8039872c_y;
s16 objAnimVar_8039872c_z;

int DAT_80398a10;
int DWORD_80398a14;
int DWORD_80398a18;

#define TILTLIST_MAX 44
s16 Tiltlist[TILTLIST_MAX]; //80357698

int maxModelNum; //80398a20
s16 *globalModAnimBuffer; //80398a24
int *pAmapTab; //s16[16] @ 80398a28, also accessed as int
u32 *animOffsetTbl; //80398a2c
UNKTYPE *globalModAnimBufferPlus0x810; //80398a30
BOOL bHaveAnimTab; //80398a34
SparseArray *modelsLoadedTable; //80398a38
SparseArray *animsLoadedTable; //80398a3c

void debugPrint(char *fmt,...);
Texture * textureLoad(int id,int param_2);
void * getTable(DataFileId32 file);
void loadModelsBin(uint offset,int *outNAnimations,uint *outAnimCacheSize,
	BOOL *outNoAmap,int *outSize,int id);
void FUN_80065ff8(Mtx44 **pjMtx,Mtx44Ptr modelMatrix,AnimInstance *animInstance,Bone *joints,int numJoints,undefined2 *tiltList,int param_7,u32 flags);
Animation * loadModelAnimation(Model *model,short id,short id2,void *dest);
void * loadDataFileWithLength(DataFileId32 file,void *dest,uint offset,u32 len);
int loadAndDecompressDataFile(DataFileId32 file,void *dest,uint offset,size_t length,uint *outSize,int index,s8 flags);

void *loadModelInstanceAsset(int id, void *buf);
ModelInstance *createModelInstance(Model *model, int flags, BOOL bIsNew);
int Model_setupAnimInstance(Model *model,int flags,AnimUnk *anim,BOOL bAlways0);
int modelGetAmapSize(uint id, BOOL bypassAmapTab, int nAnimations);
BOOL makeModelAnimation(Model *model,uint animId,void *hits);
void modelSetupAnims(ModelInstance *modelInstance,AnimInstance *animInstance);
void* fn_8007D174(short param_1,short param_2,undefined4 param_3,undefined4 param_4);
void fn_8007D1C4(Mtx44Ptr modelMatrix, ModelInstance *modelInstance,AnimInstance *animInstance, float frame, int param_5);
void tiltListFn_8007d678(Mtx44Ptr modelMatrix, ModelInstance *modelInstance,AnimInstance *animInstance,float frame,undefined4 param_5, u8 param_6, u8 param_7,u8 iJoint, u8 flags, short param_10);
void fn_8007d8e4(Model *model,AnimInstance *animInstance,int count);
void initModels(void);
ModelInstance * loadModelInstance(int id,uint flags);
void modelInstanceFree(ModelInstance *modelInstance);
uint Model_checksumHeader(Model *model);
Model* Model_load(int id);
void Model_loadTextures(Model *model);
void Model_freeTextures(Model *model);
void Model_freeAnimations(Model *model);
int Model_lookupModelInd(int id);
void Model_setOffsets(Model *model);
void Model_initSkinningWeights(Model *model,ModelInstance *mInst);
void Model_initShaders(Model *model);
void modelAnimFn_8007e974(ModelInstance *modelInstance,Model *model,ObjInstance *object,Mtx44 *modelMatrix);
void tiltListFn_8007ebe8(ObjInstance *object,ModelInstance *modelInstance,Model *model);
void ModelInstance_loadShaders(ModelInstance *minst,ObjInstance *obj);
void ModelInstance_unloadShaders(ModelInstance *model);
TexturePtr* ModelInstance_getShaderTexture(ModelInstance *modelInstance,int shaderNum);
Mtx44* modelInstGetjMtx(ModelInstance *modelInstance,int iMtx);
void modelInstSwapJmtxs(ModelInstance *modelInstance);
void ModelInstance_setTexFuncPtr(ModelInstance *modelInstance,TexFuncPtr cb);
TexFuncPtr ModelInstance_getTexFuncPtr(ModelInstance *modelInstance);
//void freezeModelFn_8007f184(undefined4 param_1,undefined4 param_2,char param3);
void ModelInstance_freeField48(ModelInstance *modelInstance);
u16 modelGetFieldA4(Model *model);
Shader* modelGetShader(Model *model,int shaderNum);
S16Vec* modelGetVtxPos(Model *model,int positionNum);
Texture* modelGetGCTexture(Model *model,int textureNum);
Bone * modelGetJoint(Model *model,int jointNum);
DisplayList * modelGetDisplayList(Model *model,int listNum);
PolygonGroup * modelGetPolyGroup(Model *model,int groupNum);
GCPolygon* modelGetGCPoly(Model *model,int polygonNum);
Animation * loadAnimation(Model *model,short id,short id2,void *dest);
Animation * modelLoadAnimation(Model *model,int index,int id,void *dest);
Animation * getAnimation(short id);
void unloadAnimation(Animation *anim);
void objAnimFn_8008045c(ModelInstance *mInst, int which, int iJoint, float inScale, float outPosScale, Vec *outPos, S16Vec *outRot);
void fn_80080734(ModelInstance *modelInstance,Model *model,ObjInstance *object,Mtx44 *mtx,ObjInstance *parent);
void vtxAnimFn80080A50(ModelInstance *modelInstance);
void vtxAnimFn_80080adc(ModelInstance *modelInstance,int idx,int animIdx1,int animIdx2,float speed,s8 flags);
void LAB_80080c00(double param_1,int *param_2,int param_3);
void modelFn_80080c28(float scale, ModelInstance *modelInstance);
void copyVtxsToModelInstance(ModelInstance *modelInstance);
void fn_8008102C(ModelInstance *modelInstance, MtxPtr mtx, u8 *mtxBuf);
void modelApplyBoneTransforms(S16Vec *vtxs,S16Vec *vtxs2,uint numPositions,short *anims1,short *anims2,int pos);
BOOL countModels(void);
//void modelApplyBoneTransform(undefined4 *param_1,undefined4 *param_2,int param_3,short **param_4,short **param_5,int param_6,undefined4 param_7,int param_8);
void LAB_80081578(void);
void modelGetVtxPosFloat(Model *model,int positionNum,Vec *posVec);

void *loadModelInstanceAsset(int id, void *buf) { // 8007C57C
	void *result;
	loadAsset_modelInstance(&result, id, buf);
	return result;
}

//flags: CreateModelInstanceFlags
ModelInstance *createModelInstance(Model *model, int flags, BOOL bIsNew) { // 8007C5B4
	ModelInstance *minst;
	uint size;
    uint resultSize;
	int ii;
	AnimInstance *anim;
	ModelInstanceField20 *unk20;
	void *next;
    AnimUnk animUnk;

	if(!model) {
		printf("WARNING :: createModelInstance called with NULL pointer\n");
		return NULL;
	}
	size = setupAnimInstance(model, flags, &animUnk, 0);
	minst = (ModelInstance *)mmAlloc(
	    size, ALLOC_TAG_MODEL_INSTANCE, (volatile u32) "minst");
	if(!minst) return NULL;

	memclr(minst, size);
	next = (void*)(minst + 1);
    next = mmAlign16(next);
	minst->jMtxs[0] = next; ADVANCE_PTR(next,animUnk.mtxSize >> 1);
	minst->jMtxs[1] = next; ADVANCE_PTR(next,animUnk.mtxSize >> 1);
	minst->jMtxs4C = minst->jMtxs[0];

	if(model->bCopyVtxsToModelInst
    || model->skin2Matrices) {
		next = (void *)((int)next + 0x1f & ~0x1f);
		minst->vertexPositions  = next; ADVANCE_PTR_BY(next,model->numPositions,S16Vec);
		minst->vertexPositions2 = next; ADVANCE_PTR_BY(next,model->numPositions,S16Vec);
		memcpy(minst->vertexPositions,
		    model->vertexPositions,
		    (uint)model->numPositions * sizeof(S16Vec));
		DCFlushRange(minst->vertexPositions,
            (uint)model->numPositions * sizeof(S16Vec));
	} else {
		minst->vertexPositions  = model->vertexPositions;
		minst->vertexPositions2 = model->vertexPositions;
	}

	next = mmAlign4(next);
	minst->animInstances[0] = next; ADVANCE_PTR_BY(next,1,AnimInstance);

	if(flags & CreateModelInstanceFlags_DoubleBufferAnims) {
		minst->animInstances[1] = next; ADVANCE_PTR_BY(next,1,AnimInstance);
	}

	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		next = (void *)alignTo64(next);
		anim = minst->animInstances[0];
		anim->cache0[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
        anim->cache0[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		anim->cache1[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		anim->cache1[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		if(minst->animInstances[1]) {
			anim = minst->animInstances[1];
			anim->cache0[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->cache0[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->cache1[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->cache1[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		}
	}

	if(model->bCopyVtxsToModelInst) {
		next = mmAlign4(next);
		minst->unk20 = next; ADVANCE_PTR_BY(next,3,ModelInstanceField20);
		for(ii = 0; ii < 3; ii = ii + 1) {
			unk20 = &minst->unk20[ii];
			unk20->animsIdx1 = -1;
            unk20->animsIdx2 = -1;
            unk20->pos       = 0.0f;
            unk20->prevPos   = 0.0f;
            unk20->speed     = 0.0f;
		}
	}

	if(animUnk.hitSphereDataSize > 0) {
		next = mmAlign4(next);
		minst->hitSpheres[0] = next; ADVANCE_PTR_BY(next,model->numHitSpheres,RamHitSphere);
		minst->hitSpheres[1] = next; ADVANCE_PTR_BY(next,model->numHitSpheres,RamHitSphere);
		minst->activeHitSphere = minst->hitSpheres[0];
	}

	if(model->joints && model->numJoints && model->radi && model->exT) {
		next = mmAlign4(next);
		minst->skeleton            = next; ADVANCE_PTR_BY(next,1,ModelSkeletonStruct);
		minst->skeleton->joints    = next; ADVANCE_PTR_BY(next,model->numJoints,Vec);
		minst->skeleton->scale     = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->unk08     = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->jointDist = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->totalDist = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->unk18     = next; ADVANCE_PTR_BY(next,model->numJoints,u8);
	} else {
        minst->skeleton = NULL;
	}

	if(model->skin2Matrices) {
		next = mmAlign4(next);
		minst->skinVtxs = next; ADVANCE_PTR_BY(next,model->skin.numPieces,VertexPosition*);
	}

	next = mmAlign4(next);
	minst->shaderDefs = next; ADVANCE_PTR_BY(next,model->numShaders,ShaderDef);

	if(flags & CreateModelInstanceFlags_TexturedShadow) {
		next = mmAlign2(next);
		minst->shadow = next; ADVANCE_PTR_BY(next,1,TexturedShadow);
		minst->shadow->state = 0;
	}

    resultSize = (int)next - (int)minst;
	if((int)resultSize >= (int)size) {
		printf("DANGER: createModelInstance: Actual size exceeded totalsize!!!\n");
	}

	minst->unk48 = NULL;
	minst->mod = model;
	minst->bUseVertexPositions1C = 0;
	return minst;
}

int Model_setupAnimInstance(
Model *model, int flags, AnimUnk *anim, BOOL bAlways0) { // 8007C9C0
	int result;

	if(model->numAnims) {
		/* final: mtxSize = (model->nBones + model->nVtxGroups) * 0x80 */
		anim->mtxSize = model->numJoints * sizeof(Mtx44) * 2;
	}
	else {
		anim->mtxSize = 0x80;
	}

	if(model->bCopyVtxsToModelInst || model->skin2Matrices) {
		/* final: +0x20 => +0x60 */
		anim->unk00 = model->numPositions * 2 * sizeof(S16Vec) + 0x20;
	} else {
		anim->unk00 = 0;
	}

	anim->hitSphereDataSize = model->numHitSpheres * sizeof(HitSpherePos) * 2;
	anim->nAnims = 0;
	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		anim->animCacheSize = model->animCacheSize;
		while(anim->animCacheSize & 7) anim->animCacheSize++;
		anim->nAnims = anim->animCacheSize * 4;
	}
	anim->size10 = sizeof(AnimInstance);
	if(flags & 0x80) {
		anim->size10 *= 2;
		anim->nAnims *= 2;
	}
	if((flags & 1) || model->bCopyVtxsToModelInst || bAlways0) {
		anim->size10 += 0x30; //sizeof(Mtx)? but these are Mtx44?
		result = 0x54; //probably sizeof(ModelInstance)
		result += anim->nAnims + anim->size10;
		result += anim->mtxSize + anim->hitSphereDataSize + 8;
	} else {
		//same as above but ordered different. why!?
		result = 0x54;
		result += anim->size10;
		result += anim->nAnims + anim->mtxSize + anim->hitSphereDataSize + 8;
	}
	result += anim->unk00;
	if(model->joints && model->numJoints && model->radi) {
		result += (model->numJoints * 2) + (model->numJoints * 7) * 4 +
			0x1c; //possibly sizeof(AnimUnk)
	}
	if(model->skin2Matrices) {
		result += model->skin.numPieces * 4 + 4;
	}
	result += model->numShaders * 8;
	if(flags & 0x8000) result += 0x1a;

	result = (result + 0x2f & ~0xf) + 0x10;
	return result;
}

int modelGetAmapSize(uint id, BOOL bypassAmapTab, int nAnimations) {
	int result;
    int idx;
    int ent;

    result = 0;
	if(bypassAmapTab) {
        result += nAnimations * 2 + 8;
        while(result & 7) result++;
	} else {
		result += nAnimations * 4;
        while(result & 7) result++;
        loadDataFileWithLength(FILE_AMAP_TAB,
            pAmapTab, (id & ~3) * 4, sizeof(int)*8);
        idx = id & 3;
        ent = pAmapTab[idx+1] - pAmapTab[idx];
        result += ent;
	}
	return result;
}

BOOL makeModelAnimation(Model *model, uint animId, void *hits) { //8007CC94
	s16 *amap;
	int bank;
	int thisId;
	int nextId;
	int offset;
	int offsNext;
	int animBank;
	int nAnims;
	int size;
	int ii;
	int totalSize;

	totalSize = 0;
	amap = (s16*)pAmapTab;
	loadDataFileWithLength(FILE_MODANIM_TAB, amap, animId * 2, 0x10);
	offset = amap[0];
	offsNext = amap[1];
	size = offset;
	nAnims = (offsNext - offset) >> 1;
	if(nAnims != model->numAnims) {
		printf("makeModelAnimation() size mismatch!! (%d,%d)\n", model->numAnims, nAnims);
		model->numAnims = nAnims;
	}
	if(!model->numAnims) return FALSE;

	nAnims = model->numAnims * 2 + 8;
	if(nAnims > 0x800) {
		debugPrint("Warning: Model animation buffer overflow!! size=%d\n", nAnims);
	}
	loadDataFileWithLength(FILE_AMAP_TAB, pAmapTab, (animId & ~3) * 4, 0x20);
	bank = animId & 3;
	model->animOffset = pAmapTab[bank];
	thisId = pAmapTab[bank];
	nextId = pAmapTab[bank + 1] - thisId;
	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		model->animIds = (s16 *)hits;
		while(nAnims & 7) nAnims++;
		totalSize += nAnims;
		hits = (void*)((intptr_t)hits + nAnims);
		//sus, using size as offset here
		loadDataFileWithLength(FILE_MODANIM_BIN, model->animIds, size, nAnims);
	} else {
		loadDataFileWithLength(FILE_MODANIM_BIN, globalModAnimBuffer, size, nAnims);
		model->animIds = globalModAnimBuffer;
	}
	animBank = 0;
	model->animBank[animBank++] = 0;
	for(ii = 0; ii < model->numAnims; ii += 1) {
		if(model->animIds[ii] == -1) {
			model->animBank[animBank++] = ii + 1;
		}
	}
	if(8 < animBank) printf("ANIMBANK overflow\n");
	if(!(model->flags & ModelDataFlags2_UseLocalModAnimTab)) {
		model->animIds = NULL;
		model->anims = (struct Animation **)hits;
		hits = (void*)((intptr_t)hits + model->numAnims * 4);
		for(totalSize += model->numAnims * 4; totalSize & 7; totalSize += 1) {
			hits = (void*)((intptr_t)hits + 1);
		}
		model->amap = hits;
		hits = (void*)((intptr_t)hits+nextId);
		totalSize += nextId;
		loadDataFileWithLength(FILE_AMAP_BIN, model->amap,
			model->animOffset, nextId);
		nAnims = 0;
		do {
			if(globalModAnimBuffer[nAnims] != -1) {
				model->anims[nAnims] = (struct Animation*)loadModelAnimation(
					model, globalModAnimBuffer[nAnims], (short)nAnims, NULL);
				if(!model->anims[nAnims]) {
					for(bank = 0; bank < nAnims; bank++) {
						unloadAnimation((Animation*)model->anims[bank]);
					}
					model->anims = NULL;
					return TRUE;
				}
			} else {
				model->anims[nAnims] = NULL;
			}
			nAnims += 1;
		} while(nAnims < model->numAnims);
	}
	else {
		model->anims = NULL;
	}
	return FALSE;
}

void modelSetupAnims(
    ModelInstance *modelInstance, AnimInstance *animInstance) { // 8007CFA4
	AnimCache *anim;
	Model *model;

	animInstance->iJoint[0] = 0;
	animInstance->unk5e = 0;
	animInstance->unk58 = 0;
	animInstance->unk5a = 0;
	animInstance->unk5c = 0;
	animInstance->hitboxSize[1][0] = 0.0;
	animInstance->hitboxSize[0][0] = 0.0;
	animInstance->hitboxSize[2][0] = 0.0;
	animInstance->unk60[0] = 0;
	model = modelInstance->mod;
	if(model->numAnims != 0) {
		if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
			loadModelAnimation(model, *model->animIds, 0, animInstance->cache0[0]);
			loadModelAnimation(model, *model->animIds, 0, animInstance->cache0[1]);
			loadModelAnimation(model, *model->animIds, 0, animInstance->cache1[0]);
			loadModelAnimation(model, *model->animIds, 0, animInstance->cache1[1]);
			animInstance->iJoint[0] = 0;
			anim = (AnimCache *)&animInstance->cache0[animInstance->iJoint[0]][1];
		} else {
			anim = (AnimCache*)model->anims[animInstance->iJoint[0]];
		}
		animInstance->joints[0] = (Bone *)&anim->animMap[6];
		animInstance->unk60[0] = anim->animMap[1] & 0xf0;
		animInstance->hitboxSize[2][0] = animInstance->joints[0]->idx[1];
		if(animInstance->unk60[0] == 0) {
			animInstance->hitboxSize[2][0] -= 1.0f;
		}
		animInstance->unk60[1] = animInstance->unk60[0];
		animInstance->joints[1] = animInstance->joints[0];
		animInstance->iJoint[1] = animInstance->iJoint[0];
		animInstance->hitboxSize[0][1] = animInstance->hitboxSize[0][0];
		animInstance->hitboxSize[2][1] = animInstance->hitboxSize[2][0];
		animInstance->hitboxSize[1][1] = animInstance->hitboxSize[1][0];
		animInstance->joints[2] = animInstance->joints[0];
		animInstance->iJoint[2] = animInstance->iJoint[0];
		animInstance->joints[3] = animInstance->joints[0];
		animInstance->iJoint[3] = animInstance->iJoint[0];
	}
}

void* fn_8007D174(short param_1,short param_2,undefined4 param_3,undefined4 param_4) { //8007D174
	void *result;

	result = NULL;
	loadAsset_Animation(&result,param_1,param_2,param_3,param_4);
	return result;
}

void fn_8007D1C4(Mtx44Ptr modelMatrix, ModelInstance *modelInstance,
AnimInstance *animInstance, float frame, int param_5) { //8007D1C4 regswap
	int flags2;
	int flags;
	int ii;
	int iSrc;
	int unk5a;
	Mtx44 *jMtx;
	Model *model;
	AnimInstance animInst;

	model = modelInstance->mod;
	jMtx  = modelInstance->jMtxs[modelInstance->flags & 1];
	animInstance->hitboxSize[0][0] = frame * animInstance->hitboxSize[2][0];
	flags = 0;
	if(model->flags & 8) {
		animInst.cache0[0] = animInstance->cache0[0];
		animInst.cache0[1] = animInstance->cache0[1];
		animInst.cache1[0] = animInstance->cache1[0];
		animInst.cache1[1] = animInstance->cache1[1];
		for(ii = 0; ii < 2; ii++) {
			iSrc = animInstance->unk58 ? ii : 0;
			animInst.iJoint[ii] = animInstance->iJoint[iSrc];
			animInst.unk60[ii] = animInstance->unk60[iSrc];
			animInst.hitboxSize[2][ii] = animInstance->hitboxSize[2][iSrc];
			animInst.hitboxSize[0][ii] = animInstance->hitboxSize[0][iSrc];
			animInst.joints[ii] = animInstance->joints[iSrc];
		}
		animInst.unk58 = animInstance->unk58;
		fn_8007d8e4(model, &animInst, 2);
		if(animInstance->flags63 & 1) flags |= 0x10;
		if(animInstance->flags63 & 4) flags |= 0x20;
		FUN_80065ff8(&jMtx, modelMatrix, &animInst,
		    model->joints, model->numJoints,
		    Tiltlist, param_5, flags | 0x40);
	} else {
		for(ii = 0; ii < 2; ii++) {
			if(ii) unk5a = animInstance->unk5c;
			else   unk5a = animInstance->unk5a;
			if(unk5a) {
				if(animInstance->unk58) flags2 = 4 << ii;
				else flags2 = 0;
				animInst.unk60[0] = animInstance->unk60[ii];
				animInst.hitboxSize[2][0] = animInstance->hitboxSize[2][ii];
				animInst.hitboxSize[0][0] = animInstance->hitboxSize[0][ii];
				animInst.joints[0] = animInstance->joints[ii];
				animInst.unk60[1] = animInstance->unk60[ii];
				animInst.hitboxSize[2][1] = animInstance->hitboxSize[2][ii];
				animInst.hitboxSize[0][1] = animInstance->hitboxSize[0][ii];
				animInst.joints[1] = animInstance->joints[ii + 2];
				if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
					animInst.iJoint[0] = 0;
					animInst.iJoint[1] = 1;
					animInst.cache0[0] = animInstance->cache0[animInstance->iJoint[ii]];
					animInst.cache0[1] = animInstance->cache1[animInstance->iJoint[ii + 2]];
				} else {
					animInst.iJoint[0] = animInstance->iJoint[ii];
					animInst.iJoint[1] = animInstance->iJoint[ii + 2];
				}
				animInst.unk58 = unk5a;
				fn_8007d8e4(model, &animInst, 2);
				FUN_80065ff8(&jMtx, modelMatrix, &animInst,
				    model->joints, model->numJoints,
				    Tiltlist, param_5, flags2);
				if(flags2) flags |= 1 << ii;
			}
		}
		if(((!animInstance->unk5a) && (!animInstance->unk5c)) || flags) {
			iSrc = 1;
			if(animInstance->unk58) iSrc = 2;
			animInst.cache0[0] = animInstance->cache0[0];
			animInst.cache0[1] = animInstance->cache0[1];
			animInst.cache1[0] = animInstance->cache1[0];
			animInst.cache1[1] = animInstance->cache1[1];
			for(ii = 0; ii < iSrc; ii += 1) {
				animInst.iJoint[ii] = animInstance->iJoint[ii];
				animInst.unk60[ii] = animInstance->unk60[ii];
				animInst.hitboxSize[2][ii] = animInstance->hitboxSize[2][ii];
				animInst.hitboxSize[0][ii] = animInstance->hitboxSize[0][ii];
				animInst.joints[ii] = animInstance->joints[ii];
			}
			animInst.unk58 = animInstance->unk58;
			fn_8007d8e4(model, &animInst, iSrc);
			if(animInstance->flags63 & 1) flags |= 0x10;
			if(animInstance->flags63 & 4) flags |= 0x20;
			FUN_80065ff8(&jMtx, modelMatrix, &animInst,
			    model->joints, model->numJoints,
			    Tiltlist, param_5, flags);
		}
	}
}

void tiltListFn_8007d678(Mtx44Ptr modelMatrix, ModelInstance *modelInstance,
AnimInstance *animInstance, float frame, undefined4 param_5, u8 iJoint1, u8 iJoint2,
u8 iJoint3, u8 flags, short unk58) { // 8007D678
	Model *model;
	Mtx44 *jMtx;
	AnimInstance anim2;

	model = modelInstance->mod;
	jMtx = modelInstance->jMtxs[modelInstance->flags & 1];
	if(flags & 0x10) {
		animInstance->hitboxSize[0][0] = frame * animInstance->hitboxSize[2][0];
	}
	anim2.unk60[0] = animInstance->unk60[iJoint1];
	anim2.hitboxSize[2][0] = animInstance->hitboxSize[2][iJoint1];
	anim2.hitboxSize[0][0] = animInstance->hitboxSize[0][iJoint1];
	anim2.joints[0] = animInstance->joints[iJoint1];
	anim2.unk60[1] = animInstance->unk60[iJoint2];
	anim2.hitboxSize[2][1] = animInstance->hitboxSize[2][iJoint2];
	anim2.hitboxSize[0][1] = animInstance->hitboxSize[0][iJoint2];
	anim2.joints[1] = animInstance->joints[iJoint3];
	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		anim2.iJoint[0] = 0;
		anim2.iJoint[1] = 1;
		anim2.cache0[0] = animInstance->cache0[animInstance->iJoint[iJoint1]];
		if(iJoint3 < 2) {
			anim2.cache0[1] = animInstance->cache0[animInstance->iJoint[iJoint3]];
		} else {
			anim2.cache1[1] = animInstance->cache1[animInstance->iJoint[iJoint3]];
		}
	} else {
		anim2.iJoint[0] = animInstance->iJoint[iJoint1];
		anim2.iJoint[1] = animInstance->iJoint[iJoint3];
	}
	if(!unk58) unk58 = 1;
	anim2.unk58 = unk58;
	fn_8007d8e4(model, &anim2, 2);
	flags &= 0xf;
	if(!(flags & 0xc)) {
		if(animInstance->flags63 & 1) flags |= 0x10;
		if(animInstance->flags63 & 4) flags |= 0x20;
	}
	FUN_80065ff8(&jMtx, modelMatrix, &anim2,
	    model->joints, model->numJoints,
	    Tiltlist, param_5, flags);
}

void fn_8007D8E4(Model *model, AnimInstance *animInst, int count) { // 8007D8E4
	float hitboxSize;
	Bone *bone;
    AnimCache *animCache;
	Animation *anim;
	int ii;
	int iJoint;
	int joint;

	for(ii = 0; ii < count; ii++) {
		if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
            animCache = animInst->cache0[animInst->iJoint[ii]];
			anim = (Animation *)&animInst->cache0[animInst->iJoint[ii]][1];
		} else {
			animCache = (AnimCache *)((int)&model->amap
			    + (uint)animInst->iJoint[ii]
			        * ((model->numJoints - 1 & ~7) + 8));
			anim = (Animation*)model->anims[animInst->iJoint[ii]];
		}
		for(iJoint = 0; iJoint < model->numJoints; iJoint++) {
			model->joints[iJoint].idx2[ii] = animCache->animMap[iJoint];
		}
		joint = animInst->joints[ii]->idx2[0];
		hitboxSize = (int)animInst->hitboxSize[0][ii];
		if(hitboxSize != animInst->hitboxSize[0][ii]) {
            animInst->sizeVar4c[ii] = (s16)joint;
		} else {
			animInst->sizeVar4c[ii] = 0;
		}
		if(animInst->unk60[ii]
        && (hitboxSize == animInst->hitboxSize[2][ii] - 1.0f)) {
			animInst->sizeVar4c[ii] = -joint * (int)hitboxSize;
		}
		animInst->joints[ii] = (Bone *)(&anim->usage
		    + anim->keyframeOffset * (int)hitboxSize);
		    //+ (int)anim->sizeVar02[joint] * (int)hitboxSize);
	}
}

void initModels(void) { //8007DAB0
	void *mem;

	modelsLoadedTable = SparseArray_create(140, 4);
    BADASSERTLINE(164, modelsLoadedTable);

    animsLoadedTable = SparseArray_create(196, 4);
    BADASSERTLINE(169, animsLoadedTable);

    mem = mmAlloc(0x830, ALLOC_TAG_ANIMS_COL,
        (volatile u32)"mod:globalAnimBuffer");
    BADASSERTLINE(174, mem);

	globalModAnimBuffer = mem;
	pAmapTab = (int *)((uint)mem + 0x800);
	globalModAnimBufferPlus0x810 = (void*)((uint)mem + 0x810);
	countModels();
}

#ifdef __MWERKS__
#pragma peephole on
#endif
ModelInstance * loadModelInstance(int id,uint flags) { //8007DB84
	int modelNum;
	ModelInstance *modelInstance;
	Model *model;

	/* final:
	   loadDataFileWithLength(MODELIND.bin,globalModAnimBuffer,id << 1,8);
	   modelNum = (uint)*globalModAnimBuffer; */
	modelNum = Model_lookupModelInd(id);
    BADASSERTLINE(210, modelNum>=0 && modelNum<maxModelNum);

    if(!SparseArray_get(modelsLoadedTable,
    modelNum, &model)) {
		model = Model_load(modelNum);
        BADASSERTLINE(218, model);
		if(isModelAnimDisabled()) {
            model->flags |= ModelDataFlags2_NoAnimations;
        }
		Model_setOffsets(model);
		Model_loadTextures(model);
		Model_initShaders(model);
		makeModelAnimation(model, modelNum,
		    (HitSpherePos *)((int)model->animBank + model->size - 0x58));
		SparseArray_set(modelsLoadedTable,
            (short)modelNum, &model);
	} else {
		model->usage++;
        BADASSERTLINE(237, model->usage<UCHAR_MAX);
	}
	modelInstance = createModelInstance(model, flags,
        (int)model->usage == 1);
    BADASSERTLINE(243, modelInstance);

	modelSetupAnims(modelInstance, modelInstance->animInstances[0]);
	if(modelInstance->animInstances[1]) {
		modelSetupAnims(modelInstance, modelInstance->animInstances[1]);
	}
	Model_initSkinningWeights(model, modelInstance);
	model->headerCksum = Model_checksumHeader(model);
	DCStoreRange(model, model->size);
	return modelInstance;
}

void modelInstanceFree(ModelInstance *modelInstance) { // 8007DD68
	Model *model;

    BADASSERTLINE(285, modelInstance);
	ModelInstance_unloadShaders(modelInstance);
	model = modelInstance->mod;
    BADASSERTLINE(292, model);
	if(modelInstance->unk48) {
		mmFree(modelInstance->unk48);
	}
	mmFree(modelInstance);
	if(!(--model->usage)) {
		SparseArray_remove(modelsLoadedTable, model->cacheModNo);
		Model_freeTextures(model);
		Model_freeAnimations(model);
		mmFree(model);
	}
}

uint Model_checksumHeader(Model *model) { //8007DE30
	uint result;
	u8 *end;
    u8 *data;

	result = 0;
	data = (u8*)model;
	end = (u8*)model + model->size;
	for(; data < end; data++) {
		result += *data;
	}
	return result;
}

#ifdef __MWERKS__
#pragma peephole off
#endif

Model* Model_load(int id) { //8007DE70
	int dummy;
	int realId;
	uint *modelsTab;
	uint amapSize;
	int size;
	int size2;
	int nAnimations;
	uint animCacheSize;
	BOOL bNoAmap;
	Model *model;

	realId = id;
	modelsTab = (uint *)getTable(FILE_MODELS_tab);
	loadModelsBin(modelsTab[realId], &nAnimations,
		&animCacheSize, &bNoAmap, &size, realId);
	animCacheSize = (uint)mmAlign8((void*)animCacheSize);
	animCacheSize += 0xb0;

	size2 = size + modelGetAmapSize(realId, bNoAmap, nAnimations) + 500;
	model = (Model *)mmAlloc(size2,
		ALLOC_TAG_MODELS_COL, (volatile u32)"mod");
	//something odd with strings here.
	BADASSERTLINE(491, model);
	model = (Model *)mmAlign16(model);

	loadAndDecompressDataFile(FILE_MODELS_bin, model,
		modelsTab[realId], size, NULL,
		realId, 0);

	model->animCacheSize = animCacheSize;
	model->cacheModNo    = realId;
	model->numAnims      = nAnimations;
	model->flags        &= ~ModelDataFlags2_UseLocalModAnimTab;
	model->usage         = 1;

	if(!model->numAnims) model->flags |= ModelDataFlags2_NoAnimations;
	if(bNoAmap) model->flags |= ModelDataFlags2_UseLocalModAnimTab;
	return model;
}

#ifdef __MWERKS__
#pragma peephole on
#endif

void Model_loadTextures(Model *model) { // 8007DFF4
	int iTex;
    BADASSERTLINE(541, model);
	for(iTex = 0; iTex < model->numTextures; iTex++) {
		model->GCtextures[iTex] = textureLoad(
            -((uint)model->GCtextures[iTex] | 0x8000), 0);
		BADASSERTLINE(546, model->GCtextures[iTex]);
	}
}

void Model_freeTextures(Model *model) { //8007E0A8
	int ii;
	for(ii = 0; ii < model->numTextures; ii++) {
		texFreeTexture(model->GCtextures[ii]);
	}
}

void Model_freeAnimations(Model *model) { //8007E0F8
	int ii;
	if(model->anims && model->numAnims) {
		for(ii = 0; ii < model->numAnims; ii++) {
			unloadAnimation((Animation*)model->anims[ii]);
		}
	}
}

int Model_lookupModelInd(int id) { // 8007E160
	if(id < 0) id = -id;
	else {
		loadDataFileWithLength(FILE_MODELIND_bin,
            globalModAnimBuffer, id * sizeof(s16), 8);
		id = globalModAnimBuffer[0];
	}
	return id;
}

/**
 * @brief Convert the offsets in a model to pointers.
 *  Used after loading the model.
 *
 *  @param model The model.
 */
void Model_setOffsets(Model *model) { // 8007E1B8
	int i;
	void *modelEnd;
	void *modelBase;

	modelBase = (void*)model;
	modelEnd  = (void *)((intptr_t)model + model->size);
	ASSERTLINE(650, model);

	if(model->sphereHits) {
		OFFSET_TO_PTR2(HitSphere, model, sphereHits, modelBase);
		ASSERTLINE(655, model->sphereHits>=modelBase && model->sphereHits<modelEnd);
	}

	if(model->joints) {
		OFFSET_TO_PTR2(Bone, model, joints, modelBase);
		ASSERTLINE(675, model->joints>=modelBase && model->joints<modelEnd);
		if(model->radi) {
			OFFSET_TO_PTR2(float, model, radi, modelBase);
		    ASSERTLINE(679, model->radi>=modelBase && model->radi<modelEnd);
		}
		if(model->exT) {
			OFFSET_TO_PTR2(float, model, exT, modelBase);
		    ASSERTLINE(684, model->exT>=modelBase && model->exT<modelEnd);
		}
	}

	if(model->GCtextures) {
		OFFSET_TO_PTR2(Texture*, model, GCtextures, modelBase);
	    ASSERTLINE(691, model->GCtextures>=modelBase && model->GCtextures<modelEnd);
	}

	OFFSET_TO_PTR2(S16Vec, model, vertexPositions, modelBase);
	ASSERTLINE(694, model->vertexPositions>=modelBase && model->vertexPositions<modelEnd);

	if(model->vertexNormals) {
		OFFSET_TO_PTR2(S16Vec, model, vertexNormals, modelBase);
	    ASSERTLINE(699, model->vertexNormals>=modelBase && model->vertexNormals<modelEnd);
	}

	if(model->vertexColours) {
		OFFSET_TO_PTR2(u16, model, vertexColours, modelBase);
	    ASSERTLINE(705, model->vertexColours>=modelBase && model->vertexColours<modelEnd);
	}

	OFFSET_TO_PTR2(S16Vec, model, vertexTexCoords, modelBase);
	ASSERTLINE(709, model->vertexTexCoords>=modelBase && model->vertexTexCoords<modelEnd);

	OFFSET_TO_PTR2(BitStream, model, renderStream, modelBase);
	ASSERTLINE(711, model->renderStream>=modelBase && model->renderStream<modelEnd);

	OFFSET_TO_PTR2(DisplayList, model, displayLists, modelBase);
	ASSERTLINE(713, model->displayLists>=modelBase && model->displayLists<modelEnd);

	if(model->vertexAnims) {
		OFFSET_TO_PTR2(UNKTYPE*, model, vertexAnims, modelBase);
	    ASSERTLINE(718, model->vertexAnims>=modelBase && model->vertexAnims<modelEnd);
	}

	if(model->skin2Matrices) {
		OFFSET_TO_PTR2(FineSkinningPiece, model, skin2Matrices, modelBase);
		ASSERTLINE(723, model->skin2Matrices>=modelBase && model->skin2Matrices<modelEnd);
	}

	if(model->skinWeights) {
		OFFSET_TO_PTR2(UNKTYPE*, model, skinWeights, modelBase);
	    ASSERTLINE(728, model->skinWeights>=modelBase && model->skinWeights<modelEnd);
	}

	if(model->shaders) {
		OFFSET_TO_PTR2(Shader, model, shaders, modelBase);
	    ASSERTLINE(733, model->shaders>=modelBase && model->shaders<modelEnd);
	}

	for(i = 0; i < model->numDisplayLists; i++) {
		OFFSET_TO_PTR2(void, model, displayLists[i].displayList, modelBase);
		ASSERTLINE(739, model->displayLists[i].displayList>=modelBase && model->displayLists [i].displayList<modelEnd);
		ASSERTLINE(740, ((int)model->displayLists[i].displayList&0x1f)==0);
	}
	for(i = 0; i < model->bCopyVtxsToModelInst; i++) {
		OFFSET_TO_PTR2(UNKTYPE**, model, vertexAnims[i], modelBase);
		ASSERTLINE(745, model->vertexAnims[i]>=modelBase && model->vertexAnims[i]<modelEnd);
	}
	if(model->GCpolygons) {
		OFFSET_TO_PTR2(GCPolygon, model, GCpolygons, modelBase);
		ASSERTLINE(751, model->GCpolygons>=modelBase && model->GCpolygons<modelEnd);
	}
	if(model->polygonGroups) {
		OFFSET_TO_PTR2(PolygonGroup, model, polygonGroups, modelBase);
		ASSERTLINE(757, model->polygonGroups>=modelBase && model->polygonGroups<modelEnd);
	}
}

void Model_initSkinningWeights(Model *model, ModelInstance *mInst) { // 8007E76C
	int ii;

	if(!(model->flags & ModelDataFlags2_CopyVtxsOnLoad)) return;
	model->skin.sk2ListArray = model->skin2Matrices;
	for(ii = 0; ii < model->skin.numPieces; ii++) {
		mInst->skinVtxs[ii] = (VertexPosition *)
			((uint)mInst->vertexPositions + model->skin2Matrices[ii].vertSrc);
		if(model->skin2Matrices[ii].weightsSrc < model->skinWeights) { //sus
			model->skin2Matrices[ii].weightsSrc =
				(UNKTYPE*)((uint)model->skinWeights +
					(uint)model->skin2Matrices[ii].weightsSrc);
		}
	}
}


void Model_initShaders(Model *model) { // 8007e814
	Shader *shader;
	int iShader;
	int iLayer;

	for(iShader = 0; iShader < model->numShaders; iShader++) {
		shader = &model->shaders[iShader];
		for(iLayer = 0; iLayer < shader->numMaterialLayers; iLayer++) {
			if(shader->layer[iLayer].tex.id != -1) {
				shader->layer[iLayer].tex.ptr =
					model->GCtextures[shader->layer[iLayer].tex.id];
			}
			else shader->layer[iLayer].tex.ptr = NULL;
		}

		if(shader->tex34.id != -1) shader->tex34.ptr = model->GCtextures[shader->tex34.id];
		else shader->tex34.ptr = NULL;

		if(shader->tex1C.id != -1) {
			if(shader->tex1C.id == -2) shader->tex1C.ptr = NULL;
			else shader->tex1C.ptr = model->GCtextures[shader->tex1C.id];
		}
		else shader->tex1C.ptr = NULL;

		if(shader->tex18.id != -1) shader->tex18.ptr = model->GCtextures[shader->tex18.id];
		else shader->tex18.ptr = NULL;

		if(!(model->shaderFlags & 0xc)) shader->unk08 = 0;
		if(!(model->shaderFlags & 0xe00)) shader->unk14 = 0;
	}
}

void modelAnimFn_8007e974(ModelInstance *modelInstance, Model *model,
ObjInstance *object, Mtx44 *modelMatrix) { // 8007E974
	AnimInstance *animInstance2;
	AnimInstance *animInstance;
	Vec VStack_30;
	S16Vec local_38;

	ASSERTLINE(915, modelInstance);
	ASSERTLINE(916, model);
	ASSERTLINE(917, modelMatrix);
	ASSERTLINE(918, object);
	tiltListFn_8007ebe8(object, modelInstance, model);
	modelInstSwapJmtxs(modelInstance);
	animInstance = modelInstance->animInstances[0];
	ASSERTLINE(924, animInstance);
	if(animInstance->flags63 & 4) {
		objAnimFn_8008045c(modelInstance, 0, 0,
			object->frame1, object->pos.scale,
		    &VStack_30, &local_38);
		objAnimVar_8039872c_x = local_38.x;
		objAnimVar_8039872c_y = local_38.y;
		objAnimVar_8039872c_z = local_38.z;
	}
	if(modelInstance->mod->flags & 8) {
		fn_8007D1C4((Mtx44Ptr)modelMatrix,
		    modelInstance, modelInstance->animInstances[0],
		    object->frame1, 0x7f);
	} else {
		if(modelInstance->animInstances[0]->flags63 & 8) {
			animInstance2 = modelInstance->animInstances[1];
			tiltListFn_8007d678((Mtx44Ptr)modelMatrix, modelInstance,
				animInstance, object->frame1,
				0x7f, 0, 0, 2, 0x14,
				animInstance->unk5a);
			tiltListFn_8007d678((Mtx44Ptr)modelMatrix, modelInstance,
				animInstance2, object->frame2,
				0x7f, 0, 0, 2, 0x18,
				animInstance2->unk5a);
			tiltListFn_8007d678((Mtx44Ptr)modelMatrix, modelInstance,
				animInstance, object->frame1,
				0x7f, 0, 0, 0, 7,
				animInstance2->unk58);
			tiltListFn_8007d678((Mtx44Ptr)modelMatrix, modelInstance,
				animInstance, object->frame1,
				0x7f, 0, 1, 1, 1,
				animInstance->unk58);
		} else {
			fn_8007D1C4((Mtx44Ptr)modelMatrix, modelInstance,
				modelInstance->animInstances[0],
			    object->frame1, 0x7f);
			if(modelInstance->animInstances[1] && (-1 < object->curAnimId)) {
				fn_8007D1C4((Mtx44Ptr)modelMatrix, modelInstance,
				    modelInstance->animInstances[1],
				    object->frame2,-1);
			}
		}
	}
}

void tiltListFn_8007ebe8(ObjInstance *object, ModelInstance *modelInstance,
Model *model) { //8007EBE8
	int offsJoint;
	u8 jointId;
	ObjData *objdata;
	int iList;
	int offsList;
	Joint *joint;
	AnimCache *cache;
	int iJoint;

	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		cache = modelInstance->animInstances[0]->cache0[
			modelInstance->animInstances[0]->iJoint[0]];
	} else {
		cache = (AnimCache *)(
			(int)model->amap +
			(uint)modelInstance->animInstances[0]->iJoint[0] *
				((model->numJoints - 1 & ~7) + 8)
			);
	}
	objdata = object->objdata;
	offsJoint = 0;
	iList = 0;
	for(iJoint = 0; iJoint < objdata->nJoints; iJoint += 1) {
		jointId = objdata->joints[offsJoint + object->modelno + 1];
		if(jointId != 0xff) {
			joint = &object->joints[iJoint];
			offsList = cache->animMap[jointId] * 64;
			if(joint->unk00.x != 0) {
				Tiltlist[iList++] = offsList;
				Tiltlist[iList++] = (joint->unk00).x;
			}
			if(joint->unk00.y != 0) {
				Tiltlist[iList++] = offsList + 2;
				Tiltlist[iList++] = (joint->unk00).y;
			}
			if(joint->unk00.z != 0) {
				Tiltlist[iList++] = offsList + 4;
				Tiltlist[iList++] = (joint->unk00).z;
			}
			if(joint->unk06 != 0) {
				Tiltlist[iList++] = offsList + 0xc;
				Tiltlist[iList++] = joint->unk06;
			}
			if(joint->unk08 != 0) {
				Tiltlist[iList++] = offsList + 0xe;
				Tiltlist[iList++] = joint->unk08;
			}
			if(joint->unk0a != 0) {
				Tiltlist[iList++] = offsList + 0x10;
				Tiltlist[iList++] = joint->unk0a;
			}
			if(joint->unk0c != 0) {
				Tiltlist[iList++] = offsList + 0x18;
				Tiltlist[iList++] = joint->unk0c;
			}
			if(joint->unk0e != 0) {
				Tiltlist[iList++] = offsList + 0x1a;
				Tiltlist[iList++] = joint->unk0e;
			}
			if(joint->unk10 != 0) {
				Tiltlist[iList++] = offsList + 0x1c;
				Tiltlist[iList++] = joint->unk10;
			}
		}
		offsJoint += objdata->noframes + 1;
	}
	Tiltlist[iList] = 0x1000;
	if(iList >= TILTLIST_MAX+1) { printf("Warning! Tiltlist overflow!!\n"); }
	return;
}

void ModelInstance_loadShaders(ModelInstance *minst, ObjInstance *obj) { // 8007EE90
    int iShader;
    Model *model;

	model = minst->mod;
	if(minst->flags & ModelFlags18_ShadersLoaded) return;
    minst->flags |= ModelFlags18_ShadersLoaded;
    for(iShader = 0; iShader < minst->mod->numShaders; iShader++) {
        shaderInit(model->shaders + iShader,
            (Texture **)(&minst->shaderDefs->texture + iShader * 2),
            obj, model->shaderFlags);
    }
}

void ModelInstance_unloadShaders(ModelInstance *modelInstance) { // 8007EF18
	int iShader;

	if(!(modelInstance->flags & ModelFlags18_ShadersLoaded)) return;
    modelInstance->flags &= ~ModelFlags18_ShadersLoaded;
    for(iShader = 0; iShader < modelInstance->mod->numShaders; iShader++) {
        shaderFree(
            (Shader *)(&modelInstance->shaderDefs->texture + iShader * 2));
    }
}

TexturePtr* ModelInstance_getShaderTexture(ModelInstance *modelInstance, int shaderNum) { // 8007EF84
    BADASSERTLINE(1146, shaderNum>=0 && shaderNum<modelInstance->mod->numShaders);
	return &modelInstance->shaderDefs[shaderNum].texture; //sus
}

Mtx44* modelInstGetjMtx(ModelInstance *modelInstance, int iMtx) { // 8007EFF0
	int nJoints;

    BADASSERTLINE(1169, modelInstance);
	if(modelInstance->mod->numJoints) {
		nJoints = modelInstance->mod->numJoints;
	} else {
		nJoints = 1;
	}
	if(iMtx >= nJoints) { iMtx = 0; }
	return modelInstance->jMtxs[modelInstance->flags & 1] + iMtx;
}

void modelInstSwapJmtxs(ModelInstance *modelInstance) { // 8007F084
    BADASSERTLINE(1203, modelInstance);
	modelInstance->flags ^= ModelFlags18_UseOtherMtxs;
}

void ModelInstance_setTexFuncPtr(ModelInstance *modelInstance,TexFuncPtr cb) { //8007F0DC
    BADASSERTLINE(1224, modelInstance);
    modelInstance->texFuncPtr = cb;
}

TexFuncPtr ModelInstance_getTexFuncPtr(ModelInstance *modelInstance) { //8007F134
    BADASSERTLINE(1243, modelInstance);
    return modelInstance->texFuncPtr;
}

//void freezeModelFn_8007f184(undefined4 param_1,undefined4 param_2,char param3) { //8007F184

void ModelInstance_freeField48(ModelInstance *modelInstance) { //8007FCF8
	if(modelInstance->unk48) {
		mmFree(modelInstance->unk48);
		modelInstance->unk48 = NULL;
	}
}

u16 modelGetFieldA4(Model *model) { //8007FD3C
    BADASSERTLINE(1627, model);
    return model->unka4;
}

Shader* modelGetShader(Model *model, int shaderNum) { // 8007FD8C
    BADASSERTLINE(1648, model);
    BADASSERTLINE(1649, shaderNum>=0 && shaderNum<model->numShaders);
	return &model->shaders[shaderNum];
}

S16Vec *modelGetVtxPos(Model *model, int positionNum) { // 8007FE10
    BADASSERTLINE(1671, model);
    BADASSERTLINE(1672, positionNum>=0 && positionNum<model->numPositions);
	return &model->vertexPositions[positionNum];
}

Texture *modelGetGCTexture(Model *model, int textureNum) { // 8007FE94
    BADASSERTLINE(1768, model);
    BADASSERTLINE(1769, textureNum>=0 && textureNum<model->numTextures);
	return model->GCtextures[textureNum];
}

Bone *modelGetJoint(Model *model, int jointNum) { // 8007FF18
    BADASSERTLINE(1791, model);
    BADASSERTLINE(1792, jointNum>=0 && jointNum<model->numJoints);
	return &model->joints[jointNum];
}

DisplayList *modelGetDisplayList(Model *model, int listNum) { // 8007FF9C
    BADASSERTLINE(1814, model);
    BADASSERTLINE(1815, listNum>=0 && listNum<model->numDisplayLists);
	return &model->displayLists[listNum];
}

PolygonGroup *modelGetPolyGroup(Model *model, int groupNum) { // 80080020
    BADASSERTLINE(1906, model);
    BADASSERTLINE(1907, groupNum>=0 && groupNum<model->numGroups);
	return &model->polygonGroups[groupNum];
}

GCPolygon* modelGetGCPoly(Model *model, int polygonNum) { // 800800A4
    //missing: BADASSERTLINE(1926, model);
    BADASSERTLINE(1927, polygonNum>=0 && polygonNum<model->numPolygons);
	return &model->GCpolygons[polygonNum];
}

Animation *loadAnimation(
    Model *model, short id, short id2, void *dest) { // 8008010C
	if(!dest) {
		return getAnimation(id);
	} else {
		return modelLoadAnimation(model, id, id2, dest);
	}
}

Animation *modelLoadAnimation(
Model *model, int index, int id, void *dest) { // 80080168
	uint offset;
	u32 len;
	Animation *anim;
	uint animSize;

	offset = animOffsetTbl[index];
	loadAndDecompressDataFile(FILE_ANIM_BIN, NULL, offset,
        0, &animSize, index, 1);
    BADASSERTLINE(2150, animSize<model->animCacheSize-ANIMMAP_SIZE);
	anim = (Animation *)((uint)dest + ANIMMAP_SIZE);
    BADASSERTLINE(2155, anim);
	loadAndDecompressDataFile(
	    FILE_ANIM_BIN, anim, offset, animSize, NULL, index, 0);
	len = ((model->numJoints - 1) & ~7) + 8;
	loadDataFileWithLength(FILE_AMAP_BIN, dest,
        model->animOffset + id * len, len);
	return anim;
}

Animation *getAnimation(short id) { // 80080270
    int dummy;
	Animation *anim;
    int dummy2;
	uint offset;
	uint size;

	if(!SparseArray_get(animsLoadedTable, id, &anim)) {
        //anim isn't loaded; load it now
		offset = animOffsetTbl[id];
		loadAndDecompressDataFile(FILE_ANIM_BIN, NULL, offset, 0, &size, id, 1);
		anim = (Animation *)mmAlloc(size,
            ALLOC_TAG_ANIMS_COL, (volatile u32)"mod:anim");
        BADASSERTLINE(2203, anim);
		loadAndDecompressDataFile(FILE_ANIM_BIN, &anim->usage, offset,
            size, NULL, id, 0);
		anim->usage = 1;
		SparseArray_set(animsLoadedTable, id, &anim);
	} else {
		anim->usage++;
        BADASSERTLINE(2216, anim->usage<UCHAR_MAX);
	}
	return anim;
}


void unloadAnimation(Animation *anim) { // 8008039C
	bool success;
    int dummy;
	int key;

    if(!anim) {
        STUBBED_OP(anim);
        return;
    }
    BADASSERTLINE(2248, anim);
    if((--anim->usage) <= 0) {
        success = SparseArray_find(animsLoadedTable,
            &anim, &key);
        BADASSERTLINE(2258, success);
        SparseArray_remove(animsLoadedTable, key);
        mmFree(anim);
    }
}

void objAnimFn_8008045c(ModelInstance *mInst, int which, int iJoint,
float inScale, float outPosScale, Vec *outPos, S16Vec *outRot) { //8008045C
	Bone *joint;
	Animation *anim;
	AnimInstance *animInstance;
	S16Vec local_5c;
	uint iJoint1;
	int size;
	float size2;

	if(mInst->mod->numAnims == 0) {
		outPos->x = 0.0;
		outPos->y = 0.0;
		outPos->z = 0.0;
		outRot->x = 0;
		outRot->y = 0;
		outRot->z = 0;
	}
	if(which) animInstance = mInst->animInstances[1];
	else      animInstance = mInst->animInstances[0];
	joint = animInstance->joints[0];
	animInstance->joints[0] = animInstance->joints[iJoint];

	if(mInst->mod->flags & ModelDataFlags2_UseLocalModAnimTab) {
		if(iJoint > 1) {
			anim = animInstance->cache1[animInstance->iJoint[iJoint]]->animData;
		} else {
			anim = animInstance->cache0[animInstance->iJoint[iJoint]]->animData;
		}
	} else {
		anim = (Animation*)mInst->mod->anims[animInstance->iJoint[iJoint]];
	}
	animInstance->hitboxSize[0][0] = inScale *
		animInstance->hitboxSize[2][0];
	//XXX this is out of bounds, we probably have a wrong type
	iJoint1 = animInstance->joints[0]->idx[2];
	size = animInstance->hitboxSize[0][0];
	size2 = size;
	if(size2 != animInstance->hitboxSize[0][0]) {
		animInstance->sizeVar4c[0] = (s16)iJoint1;
	} else {
		animInstance->sizeVar4c[0] = 0;
	}

	if(animInstance->unk60[0] &&
	(size2 == animInstance->hitboxSize[2][0] - 1.0f)) {
		animInstance->sizeVar4c[0] = -iJoint1 * size;
	}
	animInstance->unk2c = (UNKTYPE*)((uint)anim +
		anim->keyframeOffset + iJoint1 * size);

	LAB_800658d0(animInstance, &local_5c, outRot);
	animInstance->joints[0] = joint;
	outPos->x = local_5c.x * (1.0f / 512.0f);
	outPos->y = local_5c.y * (1.0f / 512.0f);
	outPos->z = local_5c.z * (1.0f / 512.0f);
	outPos->x = outPos->x + (mInst->mod->joints->translation).x;
	outPos->y = outPos->y + (mInst->mod->joints->translation).y;
	outPos->z = outPos->z + (mInst->mod->joints->translation).z;
	outPos->x = (outPos->x * outPosScale);
	outPos->y = (outPos->y * outPosScale);
	outPos->z = (outPos->z * outPosScale);
}

void fn_80080734(ModelInstance *modelInstance, Model *model,
ObjInstance *object, Mtx44 *mtx, ObjInstance *parent) { // 80080734
	ObjHitsEntry *hits;
	int frameMax;
	uint curMtx; //set but not used
	uint curSphere;
	int frame;
	int frame2;
	int iSphere;
	Vec pos;
	Mtx44 *mtxTmp;
	float radius;

	frame2 = 0;
	if(parent->hits && parent->objdata->bDisableHits) {
	    frameMax = parent->hits->objHitsSize >> 2;
		if(frameMax > 0) {
			hits = parent->hits->objHits;
			frame = parent->frame1 * frameMax;
			if(frame >= frameMax) frame = frameMax - 1;
			frame = hits->frame[frame];
			frame2 = frame;
		}
	}
	if(object->hits) {
		object->hits->state2--;
		if(object->hits->state2 < 0) object->hits->state2 = 0;
		object->hits->prevFrame = object->hits->frame;
		object->hits->frame = frame2;
	}
	modelInstance->flags ^= ModelFlags18_UseOtherHitboxes;
	curSphere = modelInstance->flags >> 2 & 1; //ModelFlags18_UseOtherHitboxes
	curMtx = modelInstance->flags & ModelFlags18_UseOtherMtxs;
	modelInstance->activeHitSphere = modelInstance->hitSpheres[curSphere];
	mtxTmp = mtx;
	for(iSphere = 0; iSphere < model->numHitSpheres; iSphere++) {
		if(!mtx) {
			mtxTmp = modelInstGetjMtx(
			    modelInstance, model->sphereHits[iSphere].bone);
		}
		if(iSphere == 0 && parent != object) {
			pos.x = 0.0f;
			pos.y = 0.0f;
			pos.z = 0.0f;
			MTXMultVec(*mtxTmp, &pos, &pos);
			object->pos.pos.x = pos.x + playerMapOffsetX;
			object->pos.pos.y = pos.y;
			object->pos.pos.z = pos.z + playerMapOffsetZ;
			objMultPosByMtx(object,
			    &(object->prevPos).x,
			    &(object->prevPos).y,
			    &(object->prevPos).z);
		}
		pos.x  = model->sphereHits[iSphere].pos.x;
		pos.y  = model->sphereHits[iSphere].pos.y;
		pos.z  = model->sphereHits[iSphere].pos.z;
		radius = model->sphereHits[iSphere].radius;
		modelInstance->activeHitSphere[iSphere].radius =
			radius * parent->pos.scale;
		MTXMultVec(*mtxTmp, &pos,
			&(modelInstance->activeHitSphere[iSphere].pos));
		if(parent->heldBy) {
			multVectorByObjMtx(
			    modelInstance->activeHitSphere[iSphere].pos.x,
			    modelInstance->activeHitSphere[iSphere].pos.y,
			    modelInstance->activeHitSphere[iSphere].pos.z,
			    &modelInstance->activeHitSphere[iSphere].pos.x,
			    &modelInstance->activeHitSphere[iSphere].pos.y,
			    &modelInstance->activeHitSphere[iSphere].pos.z,
			    parent->heldBy);
			modelInstance->activeHitSphere[iSphere].pos.x -= playerMapOffsetX;
			modelInstance->activeHitSphere[iSphere].pos.z -= playerMapOffsetX;
		}
	}
}

void vtxAnimFn80080A50(ModelInstance *modelInstance) {
	if(!modelInstance->mod->vertexAnims) return;
    vtxAnimFn_80080adc(modelInstance, 0, -1, -1, 0.0f, 7);
    vtxAnimFn_80080adc(modelInstance, 1, -1, -1, 0.0f, 7);
    vtxAnimFn_80080adc(modelInstance, 2, -1, -1, 0.0f, 7);
}

void vtxAnimFn_80080adc(ModelInstance *modelInstance, int idx,
int animIdx1, int animIdx2, float speed, s8 flags) { // 80080ADC
	ModelInstanceField20 *field20;

	if(idx > 2) return;
	if(!modelInstance->mod->vertexAnims) {
		STUBBED_OP(modelInstance);
		return;
	}
	if(animIdx1 < -1) return;
	if(animIdx2 < -1) return;
	if(animIdx1 >= modelInstance->mod->bCopyVtxsToModelInst) return;
	if(animIdx2 >= modelInstance->mod->bCopyVtxsToModelInst) {
		STUBBED_OP(modelInstance);
		return;
	}

	field20 = &modelInstance->unk20[idx];
	if(animIdx1 != -1 || animIdx2 != -1) {
		/* do nothing */
	}
	else if(field20->animsIdx1 != -1 || field20->animsIdx2 != -1) {
		flags |= 6;
	}
	else {
		return;
	}
	if((field20->animsIdx1 != animIdx1)
	|| (field20->animsIdx2 != animIdx2)) {
		field20->animsIdx1 = animIdx1;
		field20->animsIdx2 = animIdx2;
		if((flags & 0x10) == 0) { field20->pos = 0.0f; }
		field20->prevPos = -1.0f;
		field20->speed = speed;
		field20->flags = flags | 4;
	}
}

void fn_80080bdc(float pos, ModelInstance *modelInstance, int idx) { // 80080BDC
	ModelInstanceField20 *field20;

    if(idx > (ModelInstanceField20_MAX_NUM-1)
    || !modelInstance->mod->vertexAnims) return;
    field20 = &modelInstance->unk20[idx];
    field20->pos = pos;
    field20->flags = field20->flags | 4;
}

void modelFn_80080c28(float scale, ModelInstance *modelInstance) { //80080C28
	int ii;
	ModelInstanceField20 *field20;

	if(!modelInstance->mod->vertexAnims) return;
	for(ii = 0; ii < 3; ii += 1) {
		field20 = &modelInstance->unk20[ii];
		if(field20->animsIdx1 == -1) {
			if(field20->animsIdx2 != -1) goto LAB_80080c74;
		} else {
LAB_80080c74:
			if(!(field20->flags & 1)) {
				field20->pos += field20->speed * scale;
				if(field20->pos > 1.0f) {
					field20->pos = 0.99f;
					field20->speed = 0.001f;
					field20->flags &= ~4;
				} else if(field20->pos < 0.0f) {
					field20->pos = 0.002f;
					field20->speed = 0.001f;
					field20->flags &= ~4;
				}
			}
		}
	}
}

typedef struct { int val[3]; } int3_80080D04;
int3_80080D04 DWORD_ARRAY_802cf000 = {0};
int3_80080D04 DWORD_ARRAY_802cf00c = {0};

void copyVtxsToModelInstance(ModelInstance *modelInstance) { // 80080D04
	short endPos;
	int3_80080D04 flags0;
	int3_80080D04 flags1;
	short *anims1;
	short *anims2;
	S16Vec *vtxs;
	Model *model;
	int ii;
	ModelInstanceField20 *field20;

	flags0 = DWORD_ARRAY_802cf000;
	flags1 = DWORD_ARRAY_802cf00c;
	model = modelInstance->mod;
	if(model->vertexAnims) {
		endPos = model->numPositions + 1;
		for(ii = 0; ii < 3; ii++) {
			field20 = modelInstance->unk20 + ii;
			if(field20->pos != field20->prevPos) {
				field20->flags &= ~0xc;
				field20->flags |= 4;
			}
			flags1.val[ii] = field20->flags & 0xc;
			if(field20->animsIdx1 == -1) {
				if((field20->animsIdx2 != -1) || field20->flags & 0xc)
					goto LAB_80080df0;
			} else {
LAB_80080df0:
				flags0.val[ii] = 1;
			}
			if(flags1.val[ii] & 4) {
				field20->flags &= ~4;
				field20->flags |= 8;
			} else if(flags1.val[ii] & 8) {
				field20->flags &= ~8;
			}
		}
		if(flags0.val[0] || flags0.val[1] || flags0.val[2]) {
			if(flags0.val[1]) flags0.val[0] = 0;
			if(flags1.val[2]) {
				flags1.val[0] = 1;
				flags1.val[1] = 1;
			}
			for(ii=0; ii < 3; ii++) {
				field20 = modelInstance->unk20 + ii;
				if(field20->flags & 2) {
					field20->flags &= ~2;
					field20->pos = 0.0f;
				}
				if(flags0.val[ii] && flags1.val[ii]) {
					if(field20->animsIdx1 > -1) {
						anims1 = (short *)model->vertexAnims[field20->animsIdx1];
					} else anims1 = &endPos;

					if(field20->animsIdx2 > -1) {
						anims2 = (short *)model->vertexAnims[field20->animsIdx2];
					} else anims2 = &endPos;

					if(ii == 2) {
						if(!flags0.val[0] && !flags0.val[1]) {
							vtxs = model->vertexPositions;
						} else vtxs = modelInstance->vertexPositions;
					} else vtxs = model->vertexPositions;

					if(field20->pos > 1.0f) field20->pos = 1.0f;
					else if(field20->pos < 0.0f) field20->pos = 0.0f;
					modelApplyBoneTransforms(vtxs,
					    modelInstance->vertexPositions,
					    (uint)model->numPositions,
					    anims1, anims2, field20->pos * 65536.0f);
				}
				field20->prevPos = field20->pos;
			}
			modelInstance->bUseVertexPositions1C = 1;
		}
	}
}

void fn_8008102C(ModelInstance *modelInstance, MtxPtr mtx, u8 *mtxBuf) { // 8008102C
	MtxPtr jMtx;
	Model *model;
	uint iMtx;
	Mtx mTmp;

	model = modelInstance->mod;
	if(model->numJoints == 0) {
		jMtx = (MtxPtr)modelInstGetjMtx(modelInstance, 0);
		MTXConcat(mtx, jMtx, jMtx);
	} else {
		for(iMtx = 0; iMtx < model->numJoints; iMtx += 1) {
			jMtx = (MtxPtr)modelInstGetjMtx(modelInstance, iMtx);
			MTXTrans(mTmp,
				-model->joints[iMtx].bindTranslation.x,
			    -model->joints[iMtx].bindTranslation.y,
			    -model->joints[iMtx].bindTranslation.z);
			MTXConcat(jMtx, mTmp, mTmp);
			mtxTranspose43(&mTmp, &mtxBuf[iMtx*4*12]);
			MTXConcat(mtx, jMtx, jMtx);
		}
	}
}

//void modelApplyBoneTransforms(S16Vec *vtxs,S16Vec *vtxs2,uint numPositions,
// short *anims1,short *anims2,int pos) { //80081134

BOOL countModels(void) { // 800812A0
	int *modelsTab;

    STUBBED_OP("models_dolphin.c");
	modelsTab = getTable(FILE_MODELS_tab);
	if(!modelsTab) return FALSE;

    maxModelNum = 0;
    while(modelsTab[maxModelNum] != -1) maxModelNum++;
    maxModelNum--;

    //looks like a bug, but maxModelNum is int, not short.
    BADASSERTLINE(3301, maxModelNum<=SHRT_MAX);
    animOffsetTbl = (u32 *)getTable(FILE_ANIM_TAB);
    if(!animOffsetTbl) return FALSE;
    bHaveAnimTab = FALSE; //XXX wrong name?
    return TRUE;
}

//void modelApplyBoneTransform
//               (undefined4 *param_1,undefined4 *param_2,int param_3,short **param_4,short **param_5,
//               int param_6,undefined4 param_7,int param_8) { //8008136C

#ifdef __MWERKS__
#pragma peephole off
#endif

void modelGetVtxPosFloat(Model *model, int positionNum, Vec *posVec) { // 8008157C
	S16Vec *vp;
	int dummy;

	ASSERTLINE(3642, posVec);
	ASSERTLINE(3643, positionNum>=0 && positionNum<model->numPositions);
	vp = modelGetVtxPos(model, positionNum);
	posVec->x = vp->x / 256.0f;
	posVec->y = vp->y / 256.0f;
	posVec->z = vp->z / 256.0f;
}
