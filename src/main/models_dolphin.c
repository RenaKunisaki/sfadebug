#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/models/shaders.h"
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

int DAT_80398a10;
int DWORD_80398a14;
int DWORD_80398a18;

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
	next = (void*)&minst->field54;
    next = (void*)alignTo16(next);
	minst->jMtxs[0] = next; ADVANCE_PTR(next,animUnk.mtxSize >> 1);
	minst->jMtxs[1] = next; ADVANCE_PTR(next,animUnk.mtxSize >> 1);
	minst->jMtxs4C = minst->jMtxs[0];

	if(model->bCopyVtxsToModelInst
    || model->posFineSkinningConfig) {
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

	next = (void*)alignTo4((uint)next);
	minst->animInstances[0] = next; ADVANCE_PTR_BY(next,1,AnimInstance);

	if(flags & CreateModelInstanceFlags_DoubleBufferAnims) {
		minst->animInstances[1] = next; ADVANCE_PTR_BY(next,1,AnimInstance);
	}

	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		next = (void *)alignTo64((uint)next);
		anim = minst->animInstances[0];
		anim->animData[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
        anim->animData[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		anim->animData[2] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		anim->animData[3] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		if(minst->animInstances[1]) {
			anim = minst->animInstances[1];
			anim->animData[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->animData[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->animData[2] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->animData[3] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		}
	}

	if(model->bCopyVtxsToModelInst) {
		next = (void*)alignTo4((uint)next);
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
		next = (void*)alignTo4((uint)next);
		minst->hitSpheres[0] = next; ADVANCE_PTR_BY(next,model->numHitSpheres,HitSphere);
		minst->hitSpheres[1] = next; ADVANCE_PTR_BY(next,model->numHitSpheres,HitSphere);
		minst->activeHitSphere = minst->hitSpheres[0];
	}

	if(model->joints && model->numJoints && model->radi && model->exT) {
		next = (void*)alignTo4((uint)next);
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

	if(model->posFineSkinningConfig) {
		next = (void*)alignTo4((uint)next);
		minst->skinVtxs = next; ADVANCE_PTR_BY(next,model->skin.numPieces,VertexPosition*);
	}

	next = (void *)alignTo4((uint)next);
	minst->shaderDefs = next; ADVANCE_PTR_BY(next,model->numShaders,ShaderDef);

	if(flags & CreateModelInstanceFlags_TexturedShadow) {
		next = (void*)alignTo2((uint)next);
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

//int Model_setupAnimInstance(Model *model,uint flags,AnimInstance *anim,int param4) { //8007C9C0


int *pAmapTab; //int[8]
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

//undefined4 Model_makeModelAnimation(Model *model,uint animId,HitSpherePos *hits) { //8007CC94

//void modelSetupAnims(ModelInstance *minst,AnimInstance *param2) { //8007CFA4

void* fn_8007D174(short param_1,short param_2,undefined4 param_3,undefined4 param_4) { //8007D174
  void *result;

  result = NULL;
  loadAsset_Animation(&result,param_1,param_2,param_3,param_4);
  return result;
}

//void LAB_8007d540(double animTimer,float *modelMatrix,ModelInstance *modelInstance,
//                 AnimInstance *animInstance,uint param_5) { //8007D1C4

//void LAB_8007d6ec(double param_1,undefined4 param_2,int *param_3,int param_4,uint param_5,
//                 uint param_6,uint param_7,s8 param_8,uint param_9,short param_10) { //8007D678

//void LAB_8007da34(int param_1,int param_2,int param_3) { //8007D8E4

//void initModels(void) { //8007DAB0

//ModelInstance * loadModelInstance(int id,uint flags) { //8007DB84

//void modelInstanceFree(ModelInstance *modelInstance) { //8007DD68

//int Model_checksumHeader(Model *model) { //8007DE30

//Model * Model_load(uint id) { //8007DE70

//void Model_loadTextures(Model *model) { //8007DFF4

//void texFreeFn_8007e0a8(int param1) { //8007E0A8

//void animUnloadFn_8007e0f8(int param1) { //8007E0F8

//int Model_lookupModelInd(int id) { //8007E160

//void Model_initPtrs(Model *model) { //8007E1B8

//void LAB_8007e7f8(Model *model,ModelInstance *minst) { //8007E76C

//void Model_loadShaderTextures(Model *model) { //8007E814

//void modelAnimFn_8007e974(ModelInstance *modelInstance,int model,int object,float *modelMatrix) { //8007E974

//void tiltListFn_8007ebe8(int param1,int param2,int param3) { //8007EBE8

//void ModelInstance_ModelInstance_loadShaders(ModelInstance *minst,ObjInstance *obj) { //8007EE90

//void ModelInstance_ModelInstance_unloadShaders(Model *model) { //8007EF18

//int Model_getShaderTexture(ModelInstance *param1,int shaderNum) { //8007EF84

//int modelInstGetjMtx(ModelInstance *modelInstance,int param2) { //8007EFF0

void modelInstance_toggleFlag18_1(ModelInstance *modelInstance) { //8007F084
  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x4b3,"Failed assertion modelInstance");
  }
  modelInstance->flags = modelInstance->flags ^ ModelFlags18_UseOtherMtxs;
  return;
}

void ModelInstance_ModelInstance_setField30(ModelInstance *modelInstance,TexFuncPtr cb) { //8007F0DC
  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x4c8,"Failed assertion modelInstance");
  }
  modelInstance->texFuncPtr = cb;
  return;
}

TexFuncPtr modelInstanceGetCallback30(ModelInstance *modelInstance) { //8007F134
  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x4db,"Failed assertion modelInstance");
  }
  return modelInstance->texFuncPtr;
}

//void freezeModelFn_8007f184(undefined4 param_1,undefined4 param_2,char param3) { //8007F184

//void LAB_8007fd28(int param_1) { //8007FCF8

//undefined2 modelGetFieldA4(Model *model) { //8007FD3C

//Shader * modelGetShader(Model *model,int shaderNum) { //8007FD8C

//S16Vec * modelGetVtxPos(Model *model,int positionNum) { //8007FE10

//undefined4 modelGetGCTexture(int param1,int textureNum) { //8007FE94

//int modelGetJoint(int param1,int jointNum) { //8007FF18

//DisplayList * modelGetDisplayList(Model *model,int listNum) { //8007FF9C

//PolygonGroup * modelGetPolyGroup(Model *model,int groupNum) { //80080020

//int modelGetGCPoly(Model *model,int polygonNum) { //800800A4

//Animation * loadAnimation(Model *model,short id,short id2,void *dest) { //8008010C

//Animation * modelLoadAnimation(Model *model,int index,int id,void *dest) { //80080168

//Animation * getAnimation(short id) { //80080270

//void unloadAnimation(s8 *anim) { //8008039C

//void objAnimFn_8008045c(double param_1,double scale,ModelInstance *mInst,int whichBuf,int animIdx,
//                       vec3f *outPos,S16Vec *outRot) { //8008045C

//void LAB_8008086c(ModelInstance *param_1,int param_2,ObjInstance *param_3,Mtx43 *param_4,
//                 ObjInstance *param_5) { //80080734

void LAB_80080ac8(int *param_1) { //80080A50
  if (*(int *)(*param_1 + 0xa0) != 0) {
    vtxAnimFn_800279cc(0.0,param_1,0,-1,-1,7);
    vtxAnimFn_800279cc(0.0,param_1,1,-1,-1,7);
    vtxAnimFn_800279cc(0.0,param_1,2,-1,-1,7);
  }
  return;
}

//void vtxAnimFn_800279cc(double param_1,int *param_2,int param_3,int param_4,int param_5,s8 param_6) { //80080ADC

//void LAB_80080c00(double param_1,int *param_2,int param_3) { //80080BDC

//void modelFn_80080c28(double param1,Model *model) { //80080C28

//void LAB_80081008(int *param_1) { //80080D04

//void LAB_80081084(ModelInstance *param_1,Mtx43 *param_2,int param_3) { //8008102C

//void modelApplyBoneTransforms
//               (void *param_1,int param_2,uint param_3,short *param_4,short *param_5,int param_6,
//               undefined4 param_7,int param_8) { //80081134

//BOOL countModels(void) { //800812A0

//void modelApplyBoneTransform
//               (undefined4 *param_1,undefined4 *param_2,int param_3,short **param_4,short **param_5,
//               int param_6,undefined4 param_7,int param_8) { //8008136C

void LAB_80081578(void) { //80081534
  return;
}

//void modelGetVtxPosFloat(Model *model,int positionNum,vec3f *posVec) { //8008157C
