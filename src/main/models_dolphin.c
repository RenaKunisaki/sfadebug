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

/* 80398a24 */ s16 *globalModAnimBuffer;
/* 80398a28 */ u32 *pAmapTab;


void *loadModelInstanceAsset(int id,void *buf) { //80077a78 types may be wrong
	void *result;
	loadAsset_modelInstance(&result,id,buf);
	return result;
}

int Model_setupAnimInstance(
    Model *model, uint flags, AnimInstance *anim, int param4);

void *loadModelInstance(int id, uint flags) { // 8007C57C
	void *result;
	loadAsset_modelInstance(&result, id, flags);
	return result;
}

ModelInstance *createModelInstance(Model *model, uint flags) { // 8007C5B4
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
	AnimInstance *pAVar6;
	S16Vec *psVar7;
	void *pvVar8;
	S16Vec *pvVar9;
	AnimInstance *anim2;
	Texture **param1;
	int local_40;
	int local_30;
	uint local_2c;

	if(!model) {
		printf("WARNING :: createModelInstance called with NULL pointer\n");
		return NULL;
	}
	size = Model_setupAnimInstance(model, flags, anim, 0);
	minst = (ModelInstance *)mmAlloc(
	    size, ALLOC_TAG_MODEL_INSTANCE, (volatile u32) "minst");
	if(!minst) return NULL;

	memclr(minst, size);
	field54 = (ModelInstanceField54 *)alignTo16(&minst->field54);
	minst->jMtxs[0] = field54->jMtxs[0];
	minst->jMtxs[1] = field54->jMtxs[1];
	psVar7 = &field54->unk;
	minst->unk4c = minst->jMtxs[0];
	if((model->bCopyVtxsToModelInst == 0) && (model->skin2Matrices == NULL)) {
		pvVar9 = (S16Vec *)((int)psVar7 + 0x1fU & 0xffffffe0);
		minst->vertexPositions[0] = pvVar9;
		psVar7 = &pvVar9[model->numPositions * 3];
		minst->vertexPositions2 = psVar7;
		psVar7 = &psVar7[model->numPositions * 3];
		memcpy(minst->vertexPositions[0],
		    model->vertexPositions,
		    (uint)model->numPositions * 6);
		DCFlushRange(minst->vertexPositions[0], (uint)model->numPositions * 6);
	} else {
		minst->vertexPositions[0] = model->vertexPositions;
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
		buf3 = (float*)alignTo64((uint)pvVar9);
		buf4 = minst->animInstances[0];
		buf4->unk1c = (void *)buf3;
		buf4->unk20 = (void *)(buf3 + local_30);
		pvVar8 = (void *)((int)(void *)(buf3 + local_30) + local_30);
		buf4->unk24 = pvVar8;
		pvVar8 = (void *)((int)pvVar8 + local_30);
		buf4->unk28 = pvVar8;
		pvVar9 = (S16Vec *)((int)pvVar8 + local_30);
		if(minst->animInstances[1] != (AnimInstance *)0x0) {
			pAVar6 = minst->animInstances[1];
			pAVar6->unk1c = (float*)pvVar9;
			pvVar8 = (void *)((int)&pvVar9->x + local_30);
			pAVar6->unk20 = pvVar8;
			pvVar8 = (void *)((int)pvVar8 + local_30);
			pAVar6->unk24 = pvVar8;
			pvVar8 = (void *)((int)pvVar8 + local_30);
			pAVar6->unk28 = pvVar8;
			pvVar9 = (S16Vec *)((int)pvVar8 + local_30);
		}
	}
	if(model->bCopyVtxsToModelInst != 0) {
		pvVar9 = (S16Vec *)alignTo4((uint)pvVar9);
		minst->vertexPositions[1] = pvVar9;
		pvVar9 = pvVar9 + 8;
		for(iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
			psVar7 = &minst->vertexPositions[1][iVar5 * 8];
			*(undefined *)(psVar7 + 6) = 0xff;
			*(undefined *)((int)psVar7 + 0xd) = 0xff;
			*(float *)psVar7 = 0.0;
			*(float *)(psVar7 + 2) = 0.0;
			*(float *)(psVar7 + 4) = 0.0;
		}
	}
	if(0 < local_40) {
		uVar2 = alignTo4((uint)pvVar9);
		minst->unk38 = uVar2;
		iVar5 = uVar2 + (uint)model->nHitSpheres * 0x10;
		minst->unk3c = iVar5;
		pvVar9 = (S16Vec *)(iVar5 + (uint)model->nHitSpheres * 0x10);
		minst->unk40 = minst->unk38;
	}
	if((((model->joints == (Bone *)0x0) || (model->numJoints == 0))
	       || (model->radi == NULL))
	    || (model->exT == (u32 *)0x0)) {
		minst->unk14 = NULL;
	} else {
		pfVar3 = (float **)alignTo4((uint)pvVar9);
		minst->unk14 = pfVar3;
		pfVar3 = pfVar3 + 7;
		minst->unk14[0] = (float *)pfVar3;
		pfVar3 = pfVar3 + (uint)model->numJoints * 3;
		minst->unk14[1] = (float *)pfVar3;
		pfVar3 = pfVar3 + model->numJoints;
		minst->unk14[2] = (float *)pfVar3;
		pfVar3 = pfVar3 + model->numJoints;
		minst->unk14[3] = (float *)pfVar3;
		pfVar3 = pfVar3 + model->numJoints;
		minst->unk14[4] = (float *)pfVar3;
		bVar1 = model->numJoints;
		minst->unk14[6] = (float *)(pfVar3 + bVar1);
		pvVar9 = (S16Vec *)((int)(pfVar3 + bVar1) + (uint)model->numJoints);
	}
	if(model->skin2Matrices != NULL) {
		uVar2 = alignTo4((uint)pvVar9);
		minst->unk34 = uVar2;
		pvVar9 = (S16Vec *)(uVar2 + (uint)model->unk72 * 4);
	}
	pSVar4 = (ShaderDef *)alignTo4((uint)pvVar9);
	minst->shaderDefs = pSVar4;
	param1 = &pSVar4->texture + (uint)model->numShaders * 2;
	if((flags & 0x8000) != 0) {
		uVar2 = alignTo2((uint)param1);
		minst->unk44 = uVar2;
		param1 = (Texture **)(uVar2 + 0x1a);
		*(undefined *)(minst->unk44 + 0x18) = 0;
	}
	if((int)size <= (int)param1 - (int)minst) {
		printf(
		    "DANGER: createModelInstance: Actual size exceeded totalsize!!!\n");
	}
	minst->unk48 = NULL;
	minst->mod = model;
	minst->unk50 = 0;
	return minst;
}

int modelGetAmapSize(uint id,BOOL noAmap,int nAnimations) { //8007cbd0 regswap
	int count;
	int result;

	result = 0;
	if(noAmap) {
		result += nAnimations * 2 + 8;
		while(result & 7) result++;
	}
	else {
		result += nAnimations * 4;
		while(result & 7) result++;
		loadDataFileWithLength(FILE_AMAP_TAB, pAmapTab, (id & ~3) * 4, 32);
		id &= 3;
		count = pAmapTab[id+1] - pAmapTab[id];
		result += count;
	}
	return result;
}

int fn_8007D174(short param_1,short param_2,
uint param_3,Model *model) {
  int result;

  result = 0;
  loadAsset_Animation(&result,param_1,param_2,param_3,model);
  return result;
}


int Model_checksumHeader(Model *model) {
	u8 *data;
	int result;
	u8 *pEnd;

	result = 0;
	data = (u8*)model;
	pEnd = (u8*)((uint)model + model->dataSize);
	for (; data < pEnd; data++) {
		result += *data;
	}
	return result;
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
		for (ii = 0; ii < model->numAnims; ii++) {
			unloadAnimation(model->anims[ii]);
		}
	}
}

int Model_lookupModelInd(int id) {
	if(id < 0) id = -id;
	else {
		loadDataFileWithLength(FILE_MODELIND_bin,
			globalModAnimBuffer, id << 1, 8);
		id = globalModAnimBuffer[0];
	}
	return id;
}

#pragma peephole on

void ModelInstance_loadShaders(ModelInstance *minst,ObjInstance *obj) {
	register int iShader;
	Model *model;

	model = minst->mod;
	if(!(minst->flags & ModelFlags18_ShadersLoaded)) {
		minst->flags = minst->flags | ModelFlags18_ShadersLoaded;
		for(iShader = 0; iShader < minst->mod->numShaders; iShader++) {
			shaderInit(&model->shaders[iShader],
				&minst->shaderDefs[iShader],
				obj, model->shaderFlags);
		}
	}
}

void ModelInstance_unloadShaders(ModelInstance *minst) {
	register int ii;
	if(minst->flags & ModelFlags18_ShadersLoaded) {
		minst->flags = minst->flags & ~ModelFlags18_ShadersLoaded;
		for(ii = 0; ii < minst->mod->numShaders; ii++) {
			shaderFree(&minst->shaderDefs[ii]);
		}
	}
}

int Model_getShaderTexture(ModelInstance *modelInstance,int shaderNum) {
	ASSERTLINE(1146, shaderNum>=0 && shaderNum<modelInstance->mod->numShaders);
	return (int)(&modelInstance->shaderDefs->texture + shaderNum * 2);
}

Mtx44 * modelInstGetjMtx(ModelInstance *modelInstance,int iMtx) {
	int nMtxs;

	ASSERTLINE(1169, modelInstance);
	if(modelInstance->mod->numJoints) {
		nMtxs = (uint)modelInstance->mod->numJoints;
	}
	else nMtxs = 1;
	if(iMtx >= nMtxs) iMtx = 0;

	return (Mtx44 *)(
		&modelInstance->jMtxs[modelInstance->flags & 1][iMtx]);
}

void modelInstSwapJmtxs(ModelInstance *modelInstance) {
	ASSERTLINE(1203, modelInstance);
	modelInstance->flags = modelInstance->flags ^ ModelFlags18_UseOtherMtxs;
}

//XXX type
void ModelInstance_setTexFuncPtr(ModelInstance *modelInstance,UNKTYPE *cb) {
	ASSERTLINE(1224, modelInstance);
	modelInstance->texFuncPtr = cb;
}

UNKTYPE * ModelInstance_getTexFuncPtr(ModelInstance *modelInstance) {
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

Shader * modelGetShader(Model *model, int shaderNum) { //str offsets
	ASSERTLINE(1648, model);
	ASSERTLINE(1649, shaderNum>=0 && shaderNum<model->numShaders);
	return &model->shaders[shaderNum];
}

S16Vec * modelGetVtxPos(Model *model,int positionNum) { //str offsets
	ASSERTLINE(1671, model);
	ASSERTLINE(1672, positionNum>=0 && positionNum<model->numPositions);
	return &model->vertexPositions[positionNum];
}

S16Vec * modelGetNormal(Model *model, int normalNum) {
	//function was optimized out, line numbers unknown
	ASSERTLINE(0, model);
	ASSERTLINE(0, normalNum>=0 && normalNum<model->numNormals);
	return &model->vertexNormals[normalNum];
}

u16 * modelGetColour(Model *model, int colourNum) {
	//function was optimized out, line numbers unknown
	ASSERTLINE(0, model);
	ASSERTLINE(0, colourNum>=0 && colourNum<model->numColours);
	return &model->vertexColours[colourNum];
}

S16Vec * modelGetTexCoord(Model *model, int coordNum) {
	//function was optimized out, line numbers unknown
	ASSERTLINE(0, model);
	//@bug comparing to numColours instead of numTexCoords
	ASSERTLINE(0, coordNum>=0 && coordNum<model->numColours);
	return &model->vertexTexCoords[coordNum];
}

Texture * modelGetGCTexture(Model *model,int textureNum) { //str offsets
	ASSERTLINE(1768, model);
	ASSERTLINE(1769, textureNum>=0 && textureNum<model->numTextures);
	return model->GCtextures[textureNum];
}

Bone * modelGetJoint(Model *model,int jointNum) { //str offsets
	ASSERTLINE(1791, model);
	ASSERTLINE(1792, jointNum>=0 && jointNum<model->numJoints);
	return &model->joints[jointNum];
}

DisplayList * modelGetDisplayList(Model *model,int listNum) { //str offsets
	ASSERTLINE(1814, model);
	ASSERTLINE(1815, listNum>=0 && listNum<model->numDisplayLists);
	return &model->displayLists[listNum];
}

PolygonGroup * modelGetPolyGroup(Model *model,int groupNum) { //str offsets
	ASSERTLINE(1906, model);
	ASSERTLINE(1907, groupNum>=0 && groupNum<model->numGroups);
	return &model->polygonGroups[groupNum];
}

GCPolygon * modelGetGCPoly(Model *model,int polygonNum) {
	ASSERTLINE(1927, polygonNum>=0 && polygonNum<model->numPolygons);
	return &model->GCpolygons[polygonNum];
}
