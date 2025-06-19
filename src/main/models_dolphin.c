#include "dolphin.h"
#include "types.h"
#include "debug/debug.h"
#include "sys/alloc.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "gfx/models/models.h"
#include "sys/dll.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "sys/files.h"

/* 80398a20 */ int maxModelNum;
/* 80398a24 */ s16 *globalModAnimBuffer;
/* 80398a28 */ int *pAmapTab;
/* 80398a2c */ u32 *animOffsetTbl;
/* 80398a34 */ BOOL bHaveAnimTab;
/* 80398a3c */ SparseArray *animsLoadedTable; // -> Animation*
SparseArray *modelsLoadedTable;
UNKTYPE *globalModAnimBufferPlus0x810;
/* 80398c68 */ extern float playerMapOffsetX;
/* 80398c6c */ extern float playerMapOffsetZ;

Model *Model_load(short id);
void Model_loadTextures(Model *model);
ModelInstance *createModelInstance(Model *model, uint flags, BOOL bIsNew);
void modelSetupAnims(ModelInstance *modelInstance, AnimInstance *animInstance);
Animation *getAnimation(short id);
Animation *modelLoadAnimation(Model *model, int index, int id, AnimCache *dest);
void unloadAnimation(Animation *anim);
void *getTable(DataFileId32 file);
Animation *loadAnimation(Model *model, short id, short id2, void *dest);
void debugPrint(const char *fmt, ...);
void ModelInstance_unloadShaders(ModelInstance *minst);
int Model_lookupModelInd(int id);
void Model_initSkinningWeights(Model *model, ModelInstance *mInst);
void Model_initShaders(Model *model);
void Model_freeTextures(Model *model);
void Model_freeAnimations(Model *model);
void modelInstSwapJmtxs(ModelInstance *modelInstance);

Texture *textureLoad(int id, int);

void *loadModelInstanceAsset(int id, void *buf) { // 8007c57c types may be wrong
	void *result;
	loadAsset_modelInstance(&result, id, buf);
	return result;
}

int Model_setupAnimInstance(Model *model, int flags, AnimUnk *anim, int param4);

void initModels(void) { // 8007dab0
	int *mem;
	modelsLoadedTable = SparseArray_create(0x8c, 4);
	BADASSERTLINE(164, modelsLoadedTable);

	animsLoadedTable = SparseArray_create(0xc4, 4);
	BADASSERTLINE(169, animsLoadedTable);

	mem = mmAlloc(
	    0x830, ALLOC_TAG_ANIMS_COL, (volatile u32) "mod:globalAnimBuffer");
	BADASSERTLINE(174, mem);

	globalModAnimBuffer = (s16 *)mem;
	pAmapTab = &mem[0x200];
	globalModAnimBufferPlus0x810 = (UNKTYPE *)&mem[0x200 + 4];
	countModels();
}

ModelInstance *loadModelInstance(int modelNum, uint flags) { // 8007db84
	ModelInstance *modelInstance;
	Model *model;
	uint modelIdx;
	uint dummy;

	/* final:
	loadDataFileWithLength(MODELIND.bin,globalModAnimBuffer,id << 1,8);
	modelIdx = (uint)*globalModAnimBuffer; */
	modelIdx = Model_lookupModelInd(modelNum);
	BADASSERTLINE(210, modelNum >= 0 && modelNum < maxModelNum);
	if(!SparseArray_get(modelsLoadedTable, modelIdx, &model)) {
		model = Model_load(modelIdx);
		BADASSERTLINE(218, model);
		if(isModelAnimDisabled()) model->flags |= ModelDataFlags2_NoAnimations;
		Model_setOffsets(model);
		Model_loadTextures(model);
		Model_initShaders(model);
		makeModelAnimation(model,
		    modelIdx,
		    (HitSpherePos *)((int)model->animBank + model->size + -0x58));
		SparseArray_set(modelsLoadedTable, (short)modelIdx, &model);
	} else {
		model->usage++;
		BADASSERTLINE(237, model->usage < UCHAR_MAX);
	}
	modelInstance = createModelInstance(model, flags, model->usage == 1);
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

#pragma peephole on
void modelInstanceFree(ModelInstance *modelInstance) {
	char cVar1;
	Model *model;

	BADASSERTLINE(285, modelInstance);
	ModelInstance_unloadShaders(modelInstance);
	model = modelInstance->mod;
	BADASSERTLINE(292, model);
	if(modelInstance->unk48) { mmFree(modelInstance->unk48); }
	mmFree(modelInstance);
	if(!--model->usage) {
		SparseArray_remove(modelsLoadedTable, model->cacheModNo);
		Model_freeTextures(model);
		Model_freeAnimations(model);
		mmFree(model);
	}
}
#pragma peephole off


ModelInstance *createModelInstance(
    Model *model, uint flags, BOOL bIsNew) { // 8007C5B4
	s8 bVar1;
	ModelInstance *minst;
	uint size;
	ModelInstanceField54 *field54;
	AnimInstance *anim;
	float *buf3;
	uint uVar2;
	float **pfVar3;
	ShaderDef *pSVar4;
	int iVar5;
	AnimInstance *buf4;
	AnimInstance *anim3;
	S16Vec *psVar7;
	void *pvVar8;
	S16Vec *pvVar9;
	ModelInstanceField20 *pField20;
	AnimInstanceField44 *pAnimField44;
	AnimInstance *anim2;
	Texture **param1;
	int local_40;
	int local_30;
	uint local_2c;

	if(!model) {
		printf("WARNING _ createModelInstance called with NULL pointer\n");
		return NULL;
	}
	size = Model_setupAnimInstance(model, flags, (AnimUnk *)anim, 0);
	minst = (ModelInstance *)mmAlloc(
	    size, ALLOC_TAG_MODEL_INSTANCE, (volatile u32) "minst");
	if(!minst) return NULL;

	memclr(minst, size);
	field54 = (ModelInstanceField54 *)alignTo16(&minst->field54);
	minst->jMtxs[0] = field54->jMtxs[0];
	minst->jMtxs[1] = field54->jMtxs[1];
	psVar7 = &field54->unk;
	minst->jMtxs4C = minst->jMtxs[0];
	if((model->bCopyVtxsToModelInst == 0)
	    && (model->posFineSkinningConfig == NULL)) {
		pvVar9 = (S16Vec *)((int)psVar7 + 0x1fU & 0xffffffe0);
		minst->vertexPositions = pvVar9;
		psVar7 = &pvVar9[model->numPositions * 3];
		minst->vertexPositions2 = psVar7;
		psVar7 = &psVar7[model->numPositions * 3];
		memcpy(minst->vertexPositions,
		    model->vertexPositions,
		    (uint)model->numPositions * 6);
		DCFlushRange(minst->vertexPositions, (uint)model->numPositions * 6);
	} else {
		minst->vertexPositions = model->vertexPositions;
		minst->vertexPositions2 = model->vertexPositions;
	}
	anim = (AnimInstance *)alignTo4((uint)psVar7);
	minst->animInstances[0] = anim;
	anim2 = &anim[1];
	if((flags & 0x80) != 0) {
		minst->animInstances[1] = (AnimInstance *)pvVar9;
		anim2 = &anim[2];
	}
	if((model->flags & ModelDataFlags2_UseLocalModAnimTab) != 0) {
		buf3 = (float *)alignTo64((uint)pvVar9);
		buf4 = minst->animInstances[0];
		buf4->animData[0] = (void *)buf3;
		buf4->animData[1] = (void *)(buf3 + local_30);
		pvVar8 = (void *)((int)(void *)(buf3 + local_30) + local_30);
		buf4->animData[2] = pvVar8;
		pvVar8 = (void *)((int)pvVar8 + local_30);
		buf4->animData[3] = pvVar8;
		pAnimField44 = (AnimInstanceField44 *)((int)pvVar8 + local_30);
		if(minst->animInstances[1] != (AnimInstance *)0x0) {
			anim3 = minst->animInstances[1];
			anim3->animData[0] = pAnimField44;
			pvVar8 = (void *)((int)pAnimField44 + local_30);
			anim3->animData[1] = pvVar8;
			pvVar8 = (void *)((int)pvVar8 + local_30);
			anim3->animData[2] = pvVar8;
			pvVar8 = (void *)((int)pvVar8 + local_30);
			anim3->animData[3] = pvVar8;
			pvVar9 = (S16Vec *)((int)pvVar8 + local_30);
		}
	}
	if(model->bCopyVtxsToModelInst != 0) {
		pvVar9 = (void *)alignTo4((uint)pvVar9);
		minst->unk20 = (ModelInstanceField20 *)pvVar9;
		pvVar9 = pvVar9 + 8;
		for(iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
			pField20 = &minst->unk20[iVar5 * 8];

			pField20->unk0c = 0xff;
			pField20->unk0d = 0xff;
			pField20->vec.x = 0.0;
			pField20->vec.y = 0.0;
			pField20->vec.z = 0.0;
		}
	}
	if(0 < local_40) {
		uVar2 = alignTo4((uint)pvVar9);
		minst->animInst38 = (AnimInstance *)uVar2;
		iVar5 = uVar2 + (uint)model->numHitSpheres * 0x10;
		minst->unk3c = iVar5;
		pvVar9 = (S16Vec *)(iVar5 + (uint)model->numHitSpheres * 0x10);
		minst->activeAnimInst = minst->animInst38;
	}
	if((((model->joints == (Bone *)0x0) || (model->numJoints == 0))
	       || (model->radi == NULL))
	    || (model->exT == (u32 *)0x0)) {
		minst->skeleton = NULL;
	} else {
		pfVar3 = (float **)alignTo4((uint)pvVar9);
		minst->skeleton = pfVar3;
		pfVar3 = pfVar3 + 7;
		minst->skeleton[0] = (float *)pfVar3;
		pfVar3 = pfVar3 + (uint)model->numJoints * 3;
		minst->skeleton[1] = (float *)pfVar3;
		pfVar3 = pfVar3 + model->numJoints;
		minst->skeleton[2] = (float *)pfVar3;
		pfVar3 = pfVar3 + model->numJoints;
		minst->skeleton[3] = (float *)pfVar3;
		pfVar3 = pfVar3 + model->numJoints;
		minst->skeleton[4] = (float *)pfVar3;
		bVar1 = model->numJoints;
		minst->skeleton[6] = (float *)(pfVar3 + bVar1);
		pvVar9 = (S16Vec *)((int)(pfVar3 + bVar1) + (uint)model->numJoints);
	}
	if(model->posFineSkinningConfig != NULL) {
		uVar2 = alignTo4((uint)pvVar9);
		minst->skinVtxs = (UNKTYPE *)uVar2;
		pvVar9 = (S16Vec *)(uVar2 + (uint)model->skin.numPieces);
	}
	pSVar4 = (ShaderDef *)alignTo4((uint)pvVar9);
	minst->shaderDefs = pSVar4;
	param1 = &pSVar4->texture + (uint)model->numShaders * 2;
	if((flags & 0x8000) != 0) {
		uVar2 = alignTo2((uint)param1);
		minst->shadow = (TexturedShadow *)uVar2;
		param1 = (Texture **)((TexturedShadow *)uVar2) + 1;
		minst->shadow->state = 0;
	}
	if((int)size <= (int)param1 - (int)minst) {
		printf(
		    "DANGER: createModelInstance: Actual size exceeded totalsize!!!\n");
	}
	minst->unk48 = NULL;
	minst->mod = model;
	minst->bUseVertexPositions1C = 0;
	return minst;
}

int Model_setupAnimInstance(
    Model *model, int flags, AnimUnk *anim, int param4) {
	int result;

	if(model->numAnims) {
		// final: mtxSize = (model->nBones + model->nVtxGroups) * 0x80
		anim->mtxSize = (model->numJoints * 64) * 2;
	} else
		anim->mtxSize = 0x80;

	if((model->bCopyVtxsToModelInst || model->posFineSkinningConfig)) {
		// final: +0x20 => +0x60
		anim->unk00 = ((model->numPositions * 2) * 6) + 0x20;
	} else
		anim->unk00 = 0;

	anim->hitSphereDataSize = (model->numHitSpheres * 16) * 2;
	anim->nAnims = 0;
	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		anim->animCacheSize = (int)model->animCacheSize;
		while((int)anim->animCacheSize & 7) anim->animCacheSize++;
		anim->nAnims = anim->animCacheSize * 4;
	}
	anim->unk10 = 0x68;
	if(flags & 0x80) {
		anim->unk10 *= 2;
		anim->nAnims *= 2;
	}
	if(flags & 1 || model->bCopyVtxsToModelInst || param4) {
		anim->unk10 += 0x30;
		result = 0x54;
		result += anim->nAnims + anim->unk10;
		result += anim->mtxSize + anim->hitSphereDataSize + 8;
	} else {
		result = 0x54;
		result += anim->unk10;
		result += anim->nAnims + anim->mtxSize + anim->hitSphereDataSize + 8;
	}
	result += anim->unk00;
	if(model->joints && model->numJoints && model->radi) {
		result += (uint)model->numJoints * 2 + model->numJoints * 7 * 4 + 0x1c;
	}
	if(model->posFineSkinningConfig) {
		result += model->skin.numPieces * 4 + 4;
	}
	result += model->numShaders * 8;
	if(flags & 0x8000) result += 0x1a;
	result = ((result + 0x2f) & ~0xf) + 0x10;
	return result;
}

int modelGetAmapSize(
    uint id, BOOL noAmap, int nAnimations) { // 8007cbd0 regswap
	int count;
	int result;

	result = 0;
	if(noAmap) {
		result += nAnimations * 2 + 8;
		while(result & 7) result++;
	} else {
		result += nAnimations * 4;
		while(result & 7) result++;
		loadDataFileWithLength(FILE_AMAP_TAB, pAmapTab, (id & ~3) * 4, 32);
		id &= 3;
		count = pAmapTab[id + 1] - pAmapTab[id];
		result += count;
	}
	return result;
}

int makeModelAnimation(Model *model, uint animId, HitSpherePos *hits) {
	// regswap + string offsets
	int r29; // r29
	int iVar2; // r23
	s16 *amap; // r22
	int animBank; // r24
	int r25; // r25
	int uVar1; // r28
	uint offset; // r20
	int iVar4; // r19
	int size; // r17
	int iVar6; // r4
	int uVar7; // r26

	uVar7 = 0;
	amap = (s16 *)pAmapTab;
	loadDataFileWithLength(FILE_MODANIM_TAB, amap, animId * 2, 0x10);
	offset = amap[0];
	size = amap[1];
	iVar4 = offset;
	iVar6 = (int)(size - offset) >> 1;
	if(iVar6 != model->numAnims) {
		printf("makeModelAnimation() size mismatch!! (%d,%d)\n",
		    model->numAnims,
		    iVar6);
		model->numAnims = (u16)iVar6;
	}
	if(!model->numAnims) return 0;

	iVar6 = model->numAnims * 2 + 8;
	if(0x800 < iVar6)
		debugPrint(
		    "Warning: Model animation buffer overflow!! size=%d\n", iVar6);
	loadDataFileWithLength(FILE_AMAP_TAB, pAmapTab, (animId & ~3) * 4, 0x20);

	uVar1 = animId & 3;
	model->animOffset = pAmapTab[uVar1];
	iVar2 = pAmapTab[uVar1 + 1] - pAmapTab[uVar1];
	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		model->animIds = (s16 *)hits;
		while(iVar6 & 7) iVar6++;
		uVar7 += iVar6;
		hits = (HitSpherePos *)((u8 *)hits + iVar6);
		loadDataFileWithLength(FILE_MODANIM_BIN, model->animIds, iVar4, iVar6);
	} else {
		loadDataFileWithLength(
		    FILE_MODANIM_BIN, globalModAnimBuffer, iVar4, iVar6);
		model->animIds = globalModAnimBuffer;
	}
	animBank = 0;
	model->animBank[animBank++] = 0;
	for(r25 = 0; r25 < model->numAnims; r25++) {
		if(model->animIds[r25] == -1) { model->animBank[animBank++] = r25 + 1; }
	}
	if(animBank > 8) printf("ANIMBANK overflow\n");
	if((model->flags & ModelDataFlags2_UseLocalModAnimTab) == 0) {
		model->animIds = NULL;
		model->anims = (struct Animation **)hits;
		hits = (HitSpherePos *)(&hits->radius + model->numAnims);
		for(uVar7 += model->numAnims * 4; uVar7 & 7; uVar7++) {
			hits = (HitSpherePos *)((int)&hits->radius + 1);
		}
		model->curHitSpherePos = hits;
		hits = (HitSpherePos *)((uint)hits + iVar2);
		uVar7 += iVar2; // why? it's never used again
		loadDataFileWithLength(
		    FILE_AMAP_BIN, model->curHitSpherePos, model->animOffset, iVar2);
		r29 = 0;
		do {
			if(globalModAnimBuffer[r29] != -1) {
				model->anims[r29] = (struct Animation *)loadAnimation(
				    model, globalModAnimBuffer[r29], r29, NULL);
				if(!model->anims[r29]) {
					for(uVar1 = 0; uVar1 < r29; uVar1++) {
						unloadAnimation((Animation *)model->anims[uVar1]);
					}
					model->anims = NULL;
					return 1;
				}
			} else
				model->anims[r29] = NULL;
			r29 += 1;
		} while(r29 < model->numAnims);
	} else
		model->anims = NULL;
	return 0;
}

void modelSetupAnims(ModelInstance *modelInstance, AnimInstance *animInstance) {
	Animation *anim;
	Model *model;

	animInstance->iAnim[0] = 0;
	animInstance->unk5e = 0;
	animInstance->unk58 = 0;
	animInstance->unk5a = 0;
	animInstance->unk5c = 0;
	animInstance->hitboxSize[1][0] = 0.0;
	animInstance->hitboxSize[0][0] = 0.0;
	animInstance->hitboxSize[2][0] = 0.0;
	animInstance->unk60[0] = 0;
	model = modelInstance->mod;
	if(model->numAnims) {
		if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
			loadAnimation(model, *model->animIds, 0, animInstance->animData[0]);
			loadAnimation(model, *model->animIds, 0, animInstance->animData[1]);
			loadAnimation(model, *model->animIds, 0, animInstance->animData[2]);
			loadAnimation(model, *model->animIds, 0, animInstance->animData[3]);
			animInstance->iAnim[0] = 0;
			anim = (Animation *)((
			    (u32)animInstance->animData[animInstance->iAnim[0]] + 0x80));
		} else {
			anim = (Animation *)model->anims[animInstance->iAnim[0]];
		}
		animInstance->anim[0] = anim + 1;
		animInstance->unk60[0] = anim->flags01 & 0xf0;
		animInstance->hitboxSize[2][0] = animInstance->anim[0]->flags01;
		if(animInstance->unk60[0] == 0) {
			animInstance->hitboxSize[2][0] -= 1.0f;
		}
		animInstance->unk60[1] = animInstance->unk60[0];
		animInstance->anim[1] = animInstance->anim[0];
		animInstance->iAnim[1] = animInstance->iAnim[0];
		animInstance->hitboxSize[0][1] = animInstance->hitboxSize[0][0];
		animInstance->hitboxSize[2][1] = animInstance->hitboxSize[2][0];
		animInstance->hitboxSize[1][1] = animInstance->hitboxSize[1][0];
		animInstance->anim[2] = animInstance->anim[0];
		animInstance->iAnim[2] = animInstance->iAnim[0];
		animInstance->anim[3] = animInstance->anim[0];
		animInstance->iAnim[3] = animInstance->iAnim[0];
	}
	return;
}

int fn_8007D174(short param_1, short param_2, uint param_3, Model *model) {
	int result;
	result = 0;
	loadAsset_Animation(&result, param_1, param_2, param_3, model);
	return result;
}

int Model_checksumHeader(Model *model) {
	u8 *data;
	int result;
	u8 *pEnd;

	result = 0;
	data = (u8 *)model;
	pEnd = (u8 *)((uint)model + model->size);
	for(; data < pEnd; data++) { result += *data; }
	return result;
}

Model *Model_load(short id) {
	uint *modelsTab;
	uint amapSize;
	uint offset;
	int noAmap;
	uint animCacheSize;
	ushort nAnimations;
	int size;
	Model *model;

	modelsTab = (uint *)getTable(FILE_MODELS_tab);
	offset = modelsTab[id];
	loadModelsBin(offset, &nAnimations, &animCacheSize, &noAmap, &size);
	animCacheSize = alignTo8(animCacheSize);
	animCacheSize += 0xb0;
	amapSize = modelGetAmapSize(id, noAmap, nAnimations);
	model = (Model *)mmAlloc(
	    size + amapSize + 500, ALLOC_TAG_MODELS_COL, (volatile u32) "mod");
	BADASSERTLINE(491, model);

	model = (Model *)alignTo16(model);
	loadAndDecompressDataFile(
	    FILE_MODELS_bin, (void *)model, offset, size, NULL, id, 0);
	model->animCacheSize = animCacheSize;
	model->cacheModNo = id;
	model->numAnims = nAnimations;
	model->flags &= ~ModelDataFlags2_UseLocalModAnimTab;
	model->usage = 1;
	if(!model->numAnims) { model->flags |= ModelDataFlags2_NoAnimations; }
	if(noAmap) { model->flags |= ModelDataFlags2_UseLocalModAnimTab; }
	return model;
}

void Model_loadTextures(Model *model) {
	int i;
	BADASSERTLINE(541, model);
	for(i = 0; i < model->numTextures; i++) {
		model->GCtextures[i]
		    = textureLoad(-((uint)model->GCtextures[i] | 0x8000), 0);
		BADASSERTLINE(546, model->GCtextures[i]);
	}
}


void Model_freeTextures(Model *model) {
	int ii;
	for(ii = 0; ii < model->numTextures; ii++) {
		texFreeTexture(model->GCtextures[ii]);
	}
}

void Model_freeAnimations(Model *model) {
	int ii;
	if(model->anims && model->numAnims) {
		for(ii = 0; ii < model->numAnims; ii++) {
			unloadAnimation((Animation *)model->anims[ii]);
		}
	}
}

int Model_lookupModelInd(int id) {
	if(id < 0) id = -id;
	else {
		loadDataFileWithLength(
		    FILE_MODELIND_bin, globalModAnimBuffer, id << 1, 8);
		id = globalModAnimBuffer[0];
	}
	return id;
}

#pragma peephole on

void Model_initSkinningWeights(Model *model, ModelInstance *mInst) {
	int ii;

	if(!(model->flags & ModelDataFlags2_CopyVtxsOnLoad)) return;
	model->skin.sk2ListArray = model->posFineSkinningConfig;
	for(ii = 0; ii < model->skin.numPieces; ii++) {
		mInst->skinVtxs[ii] = (S16Vec *)((uint)mInst->vertexPositions
		    + model->skin.sk2ListArray[ii].vertSrc);

		if(model->posFineSkinningConfig[ii].weightsSrc < model->skinWeights) {
			model->posFineSkinningConfig[ii].weightsSrc
			    = (UNKTYPE *)((uint)model->skinWeights
			        + (uint)model->posFineSkinningConfig[ii].weightsSrc);
		}
	}
}

void Model_initShaders(Model *model) {
	Shader *shader;
	int iShader;
	int iLayer;
	for(iShader = 0; iShader < model->numShaders; iShader++) {
		shader = &model->shaders[iShader];
		for(iLayer = 0; iLayer < shader->numMaterialLayers; iLayer++) {
			if(shader->layer[iLayer].tex.id != -1) {
				shader->layer[iLayer].tex.ptr
				    = model->GCtextures[shader->layer[iLayer].tex.id];
			} else
				shader->layer[iLayer].tex.ptr = NULL;
		}
		if(shader->tex34.id != -1) {
			shader->tex34.ptr = model->GCtextures[shader->tex34.id];
		} else
			shader->tex34.ptr = NULL;

		if(shader->tex1C.id != -1) {
			if(shader->tex1C.id == -2) shader->tex1C.ptr = NULL;
			else
				shader->tex1C.ptr = model->GCtextures[shader->tex1C.id];
		} else
			shader->tex1C.ptr = NULL;

		if(shader->tex18.id != -1) {
			shader->tex18.ptr = model->GCtextures[shader->tex18.id];
		} else
			shader->tex18.ptr = NULL;

		if((model->shaderFlags & 0x000c) == 0) shader->unk08 = 0;
		if((model->shaderFlags & 0x0e00) == 0) shader->unk14 = 0;
	}
}

s16 WORD_8039872c;
s16 WORD_8039872e;
s16 WORD_80398730;
void modelAnimFn_8007e974(ModelInstance *modelInstance, Model *model,
    ObjInstance *object, float *modelMatrix) {
	AnimInstance *animInstance_00;
	AnimInstance *animInstance;
	S16Vec local_38;
	Vec VStack_30;

	BADASSERTLINE(915, modelInstance);
	BADASSERTLINE(916, model);
	BADASSERTLINE(917, modelMatrix);
	BADASSERTLINE(918, object);
	tiltListFn_8007ebe8((int)object, (int)modelInstance, model);
	modelInstSwapJmtxs(modelInstance);
	animInstance = modelInstance->animInstances[0];
	BADASSERTLINE(924, animInstance);
	if((animInstance->flags63 & 4) != 0) {
		objAnimFn_8008045c(modelInstance,
		    0,
		    0,
		    object->animTimer,
		    object->pos.scale,
		    &VStack_30,
		    &local_38);
		WORD_8039872c = local_38.x;
		WORD_8039872e = local_38.y;
		WORD_80398730 = local_38.z;
	}
	if((modelInstance->mod->flags & 8)) {
		LAB_8007d540(modelMatrix,
		    modelInstance,
		    modelInstance->animInstances[0],
		    object->animTimer,
		    0x7f);
	} else if((modelInstance->animInstances[0]->flags63 & 8)) {
		animInstance_00 = modelInstance->animInstances[1];
		LAB_8007d6ec(modelMatrix,
		    modelInstance,
		    animInstance,
		    object->animTimer,
		    0x7f,
		    0,
		    0,
		    2,
		    0x14,
		    animInstance->unk5a);
		LAB_8007d6ec(modelMatrix,
		    modelInstance,
		    animInstance_00,
		    object->frame,
		    0x7f,
		    0,
		    0,
		    2,
		    0x18,
		    animInstance_00->unk5a);
		LAB_8007d6ec(modelMatrix,
		    modelInstance,
		    animInstance,
		    object->animTimer,
		    0x7f,
		    0,
		    0,
		    0,
		    7,
		    animInstance_00->unk58);
		LAB_8007d6ec(modelMatrix,
		    modelInstance,
		    animInstance,
		    object->animTimer,
		    0x7f,
		    0,
		    1,
		    1,
		    1,
		    animInstance->unk58);
	} else {
		LAB_8007d540(modelMatrix,
		    modelInstance,
		    modelInstance->animInstances[0],
		    object->animTimer,
		    0x7f);
		if((modelInstance->animInstances[1]) && (-1 < object->animVal_a2)) {
			LAB_8007d540(modelMatrix,
			    modelInstance,
			    modelInstance->animInstances[1],
			    object->frame,
			    -1);
		}
	}
}


void ModelInstance_loadShaders(ModelInstance *minst, ObjInstance *obj) {
	REGISTER int iShader;
	Model *model;

	// alternate match: remove REGISTER and add here: !iShader;

	model = minst->mod;
	if(!(minst->flags & ModelFlags18_ShadersLoaded)) {
		minst->flags = minst->flags | ModelFlags18_ShadersLoaded;
		for(iShader = 0; iShader < minst->mod->numShaders; iShader++) {
			shaderInit(&model->shaders[iShader],
			    &minst->shaderDefs[iShader],
			    obj,
			    model->shaderFlags);
		}
	}
}

void ModelInstance_unloadShaders(ModelInstance *minst) {
	REGISTER int ii;
	if(minst->flags & ModelFlags18_ShadersLoaded) {
		minst->flags = minst->flags & ~ModelFlags18_ShadersLoaded;
		for(ii = 0; ii < minst->mod->numShaders; ii++) {
			shaderFree(&minst->shaderDefs[ii]);
		}
	}
}

int Model_getShaderTexture(ModelInstance *modelInstance, int shaderNum) {
	ASSERTLINE(
	    1146, shaderNum >= 0 && shaderNum < modelInstance->mod->numShaders);
	return (int)(&modelInstance->shaderDefs->texture + shaderNum * 2);
}

Mtx44 *modelInstGetjMtx(ModelInstance *modelInstance, int iMtx) {
	int nMtxs;

	ASSERTLINE(1169, modelInstance);
	if(modelInstance->mod->numJoints) {
		nMtxs = (uint)modelInstance->mod->numJoints;
	} else
		nMtxs = 1;
	if(iMtx >= nMtxs) iMtx = 0;

	return &(modelInstance->jMtxs[modelInstance->flags & 1][iMtx]);
}

void modelInstSwapJmtxs(ModelInstance *modelInstance) {
	ASSERTLINE(1203, modelInstance);
	modelInstance->flags = modelInstance->flags ^ ModelFlags18_UseOtherMtxs;
}

// XXX type
void ModelInstance_setTexFuncPtr(ModelInstance *modelInstance, UNKTYPE *cb) {
	ASSERTLINE(1224, modelInstance);
	modelInstance->texFuncPtr = cb;
}

UNKTYPE *ModelInstance_getTexFuncPtr(ModelInstance *modelInstance) {
	ASSERTLINE(1243, modelInstance);
	return modelInstance->texFuncPtr;
}


void ModelInstance_freeField48(ModelInstance *modelInstance) {
	if(modelInstance->unk48) {
		mmFree(modelInstance->unk48);
		modelInstance->unk48 = NULL;
	}
}

u16 modelGetFieldA4(Model *model) {
	ASSERTLINE(1627, model);
	return model->unka4;
}

Shader *modelGetShader(Model *model, int shaderNum) { // str offsets
	ASSERTLINE(1648, model);
	ASSERTLINE(1649, shaderNum >= 0 && shaderNum < model->numShaders);
	return &model->shaders[shaderNum];
}

S16Vec *modelGetVtxPos(Model *model, int positionNum) { // str offsets
	ASSERTLINE(1671, model);
	ASSERTLINE(1672, positionNum >= 0 && positionNum < model->numPositions);
	return &model->vertexPositions[positionNum];
}

S16Vec *modelGetNormal(Model *model, int normalNum) {
	// function was optimized out, line numbers unknown
	ASSERTLINE(0, model);
	ASSERTLINE(0, normalNum >= 0 && normalNum < model->numNormals);
	return &model->vertexNormals[normalNum];
}

u16 *modelGetColour(Model *model, int colourNum) {
	// function was optimized out, line numbers unknown
	ASSERTLINE(0, model);
	ASSERTLINE(0, colourNum >= 0 && colourNum < model->numColours);
	return &model->vertexColours[colourNum];
}

S16Vec *modelGetTexCoord(Model *model, int coordNum) {
	// function was optimized out, line numbers unknown
	ASSERTLINE(0, model);
	//@bug comparing to numColours instead of numTexCoords
	ASSERTLINE(0, coordNum >= 0 && coordNum < model->numColours);
	return &model->vertexTexCoords[coordNum];
}

Texture *modelGetGCTexture(Model *model, int textureNum) { // str offsets
	ASSERTLINE(1768, model);
	ASSERTLINE(1769, textureNum >= 0 && textureNum < model->numTextures);
	return model->GCtextures[textureNum];
}

Bone *modelGetJoint(Model *model, int jointNum) { // str offsets
	ASSERTLINE(1791, model);
	ASSERTLINE(1792, jointNum >= 0 && jointNum < model->numJoints);
	return &model->joints[jointNum];
}

DisplayList *modelGetDisplayList(Model *model, int listNum) { // str offsets
	ASSERTLINE(1814, model);
	ASSERTLINE(1815, listNum >= 0 && listNum < model->numDisplayLists);
	return &model->displayLists[listNum];
}

PolygonGroup *modelGetPolyGroup(Model *model, int groupNum) { // str offsets
	ASSERTLINE(1906, model);
	ASSERTLINE(1907, groupNum >= 0 && groupNum < model->numGroups);
	return &model->polygonGroups[groupNum];
}

GCPolygon *modelGetGCPoly(Model *model, int polygonNum) {
	ASSERTLINE(1927, polygonNum >= 0 && polygonNum < model->numPolygons);
	return &model->GCpolygons[polygonNum];
}

Animation *loadAnimation(Model *model, short id, short id2, void *dest) {
	if(!dest) return getAnimation(id);
	else
		return modelLoadAnimation(model, id, id2, dest);
}

Animation *modelLoadAnimation(
    Model *model, int index, int id, AnimCache *dest) { // str offsets
	int len2;
	int len;
	int animSize;
	uint offset;
	Animation *anim;

	len = animOffsetTbl[index];
	loadAndDecompressDataFile(FILE_ANIM_BIN, NULL, len, 0, &animSize, index, 1);
	ASSERTLINE(2150, animSize < model->animCacheSize - ANIMMAP_SIZE);

	anim = dest->animData;
	ASSERTLINE(2155, anim);

	loadAndDecompressDataFile(
	    FILE_ANIM_BIN, anim, len, animSize, NULL, index, 0);
	len2 = (model->numJoints - 1 & ~7) + 8;
	offset = model->animOffset + id * len2;
	loadDataFileWithLength(FILE_AMAP_BIN, dest, offset, len2);
	return anim;
}

Animation *getAnimation(short id) {
	int unused1;
	Animation *anim;
	int unused2;
	uint offset;
	uint size;

	if(!SparseArray_get(animsLoadedTable, id, &anim)) {
		offset = animOffsetTbl[id];
		loadAndDecompressDataFile(
		    FILE_ANIM_BIN, NULL, offset, 0, &size, id, 1); // get size
		anim = (Animation *)mmAlloc(
		    size, ALLOC_TAG_ANIMS_COL, (volatile u32) "mod:anim");
		ASSERTLINE(2203, anim);

		loadAndDecompressDataFile(
		    FILE_ANIM_BIN, anim, offset, size, NULL, id, 0);
		anim->usage = 1;
		SparseArray_set(animsLoadedTable, id, &anim);
	} else {
		anim->usage++;
		ASSERTLINE(2216, anim->usage < UCHAR_MAX);
	}
	return anim;
}

void unloadAnimation(Animation *anim) {
	s8 unused;
	bool success;
	int key;

	if(!anim) STUBBED_OP(anim);
	else {
		ASSERTLINE(2248, anim); // why?
		if(--anim->usage > 0) return;

		success = SparseArray_find(animsLoadedTable, &anim, &key);
		ASSERTLINE(2258, success);
		SparseArray_remove(animsLoadedTable, key);
		mmFree(anim);
	}
}

void fn_80080734(ModelInstance *modelInstance, Model *model,
    ObjInstance *object, Mtx44 *mtx, ObjInstance *parent) {
	Mtx44 *m; // r24
	int nObjHits; // r25
	int frame; // r23
	int iSphere; // r31
	Vec local_5c;
	uint local_50;
	float radius;
	int animTimer; // r27
	ObjHitsEntry *objHits; // r22
	HitState *hits;

	frame = 0;
	if(parent->hits && parent->objdata->bDisableHits) {
		nObjHits = parent->hits->objHitsSize >> 2;
		if(nObjHits > 0) {
			objHits = parent->hits->objHits;
			animTimer = parent->animTimer * nObjHits;
			if(animTimer >= nObjHits) animTimer = nObjHits - 1;
			animTimer = objHits[animTimer].frame;
			frame = animTimer;
		}
	}
	if(object->hits) {
		hits = object->hits;
		hits->state2--;
		if(object->hits->state2 < 0) { object->hits->state2 = 0; }
		object->hits->prevFrame = object->hits->frame;
		object->hits->frame = frame;
	}
	modelInstance->flags ^= ModelFlags18_UseOtherHitboxes;
	frame = (modelInstance->flags >> 2) & 1;
	local_50 = modelInstance->flags & 1;
	modelInstance->activeAnimInst = modelInstance->animInstances[frame];
	m = mtx;
	for(iSphere = 0; iSphere < model->numHitSpheres; iSphere++) {
		if(!mtx) {
			m = modelInstGetjMtx(
			    modelInstance, (int)(short)model->sphereHits[iSphere].bone);
		}
		if((iSphere == 0) && (parent != object)) {
			local_5c.x = 0.0;
			local_5c.y = 0.0;
			local_5c.z = 0.0;
			MTXMultVec(*m, &local_5c, &local_5c);
			object->pos.pos.x = local_5c.x + playerMapOffsetX;
			object->pos.pos.y = local_5c.y;
			object->pos.pos.z = local_5c.z + playerMapOffsetZ;
			objMultPosByMtx(object,
			    &object->prevPos.x,
			    &object->prevPos.y,
			    &object->prevPos.z);
		}
		local_5c.x = model->sphereHits[iSphere].pos.x;
		local_5c.y = model->sphereHits[iSphere].pos.y;
		local_5c.z = model->sphereHits[iSphere].pos.z;
		radius = model->sphereHits[iSphere].radius;
		// something is wrong with the fields here
		// there's a random +4
		// it goes away if we move hitboxSize to offset 0
		// but there's no way that's right.
		modelInstance->activeAnimInst->hitboxSize[0][iSphere * 4]
		    = radius * parent->pos.scale;
		MTXMultVec(*m,
		    &local_5c,
		    (Vec *)(modelInstance->activeAnimInst->hitboxSize + iSphere * 4));
		if(parent->heldBy) {
			multVectorByObjMtx(
			    (modelInstance->activeAnimInst->hitboxSize[iSphere * 2][0]),
			    (modelInstance->activeAnimInst->hitboxSize[iSphere * 2][1]),
			    (modelInstance->activeAnimInst->hitboxSize[iSphere * 2][2]),
			    &(modelInstance->activeAnimInst->hitboxSize[iSphere * 2][0]),
			    &(modelInstance->activeAnimInst->hitboxSize[iSphere * 2][1]),
			    &(modelInstance->activeAnimInst->hitboxSize[iSphere * 2][2]),
			    parent->heldBy);
			modelInstance->activeAnimInst->hitboxSize[iSphere * 2][0]
			    -= playerMapOffsetX;
			modelInstance->activeAnimInst->hitboxSize[iSphere * 2][2]
			    -= playerMapOffsetZ;
		}
	}
}

void vtxAnimFn_800279cc(Model **pModel, int param_3, int param_4, int param_5,
    float param_1, s8 param_6);

void fn_80080ac8(Model **pModel) {
	if((*pModel)->vertexAnims) {
		vtxAnimFn_800279cc(pModel, 0, -1, -1, 0.0f, 7);
		vtxAnimFn_800279cc(pModel, 1, -1, -1, 0.0f, 7);
		vtxAnimFn_800279cc(pModel, 2, -1, -1, 0.0f, 7);
	}
}

void fn_80080c00(float param_1, ModelInstance *modelInstance, int idx) {
	ModelInstanceField20 *field20;

	if(idx <= 2) {
		if(!modelInstance->mod->vertexAnims) STUBBED_OP(modelInstance);
		else {
			field20 = &modelInstance->unk20[idx];
			field20->vec.x = param_1;
			field20->flags |= 4;
		}
	}
}

void modelFn_80080c28(float param1, ModelInstance *modelInstance) {
	int iVar1;
	ModelInstanceField20 *field20;

	if(!modelInstance->mod->vertexAnims) return;
	for(iVar1 = 0; iVar1 < 3; iVar1++) {
		field20 = &modelInstance->unk20[iVar1];
		if(!(field20->unk0c == -1 && field20->unk0d == -1)) {
			if((field20->flags & 1) == 0) {
				field20->vec.x = field20->vec.z * param1 + field20->vec.x;
				if(field20->vec.x > 1.0f) {
					field20->vec.x = 0.002f;
					field20->vec.z = 0.001f;
					field20->flags = field20->flags & ~4;
				} else if(field20->vec.x < 0.0f) {
					field20->vec.x = 0.99f;
					field20->vec.z = 0.001f;
					field20->flags = field20->flags & ~4;
				}
			}
		}
	}
}

void fn_80081084(ModelInstance *modelInstance, Mtx44 *mtx, undefined *param_3) {
	Mtx44 *m1;
	Mtx44 m2;
	Model *model;
	uint iMtx;

	model = modelInstance->mod;
	if(model->numJoints == 0) {
		m1 = modelInstGetjMtx(modelInstance, 0);
		MTXConcat(*mtx, *m1, *m1);
	} else {
		for(iMtx = 0; iMtx < model->numJoints; iMtx++) {
			m1 = modelInstGetjMtx(modelInstance, iMtx);
			MTXTrans(m2,
			    -model->joints[iMtx].bindTranslation.x,
			    -model->joints[iMtx].bindTranslation.y,
			    -model->joints[iMtx].bindTranslation.z);
			MTXConcat(*m1, m2, m2);
			// XXX figure out type
			mtxTranspose43(m2, (Mtx *)(param_3 + (iMtx * 4) * 12));
			MTXConcat(*mtx, *m1, *m1);
		}
	}
}

BOOL countModels(void) {
	int *modelsTab;

	modelsTab = getTable(FILE_MODELS_tab);
	if(!modelsTab) return FALSE;

	maxModelNum = 0;
	while(modelsTab[maxModelNum] != -1) maxModelNum++;
	maxModelNum--;
	ASSERTLINE(3301, maxModelNum <= SHRT_MAX);
	animOffsetTbl = getTable(FILE_ANIM_TAB);
	if(!animOffsetTbl) return FALSE;

	bHaveAnimTab = FALSE;
	return TRUE;
}

void modelGetVtxPosFloat(Model *model, int positionNum, Vec *posVec) {
	S16Vec *vp;

	// something bizarre goes on here involving comparing 0 to 0
	ASSERTLINE(3642, posVec);
	ASSERTLINE(3643, positionNum >= 0 && positionNum < model->numPositions);
	vp = modelGetVtxPos(model, positionNum);
	posVec->x = vp->x * 1.0f / 256.0f;
	posVec->y = vp->y * 1.0f / 256.0f;
	posVec->z = vp->z * 1.0f / 256.0f;
}
