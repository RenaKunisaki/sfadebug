#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/textures.h"
#include "macros.h"
#include "types.h"
#include "global.h"
#include "sys/n64.h"
#include "sys/files.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/alloc.h"
#include "obj/Objects.h"
#include "obj/ObjInstance.h"
#include "obj/Camera.h"
#include "sys/dll.h"
#include "gfx/models/models.h"
#include "save/SaveGame.h"


s16 *contNoBuf; //80398a44
ObjListStruct objList_80398a88;
ObjData **objDefNoList; //80398a60
u8 *objDefNoUsage; //80398a64

/**
 * @brief Reset nVisibleObjs.
 */
void clearNVisibleObjs(void) {
	nVisibleObjs = 0;
}

/**
 * @brief Get the number of visible objects.
 *
 *  @param outNumObjs Receives number of loaded objects.
 *  @return int Number of visible objects.
 *  @note Caches the result.
 */
int getNumVisibleObjects(s32 *outNumObjs) {
	int result;
	s32 nObjs;
	s32 stop;
	s32 nObjsStart;
	s32 nObjsStart2;
	ObjInstance *obj;

	*outNumObjs = ObjListSize;
	if(isModelAnimDisabled()) {
		nVisibleObjs = 0;
		return 0;
	}
	if(nVisibleObjs) return nVisibleObjs;
	result = 0;
	nObjs = ObjListSize - 1;
	nObjsStart = result;
	nObjsStart2 = nObjs;

	while(result <= nObjs) {
		stop = 0;
		while(result <= nObjsStart2 && !stop) {
			if(Object_loadedObjs[result]->objdata->flags & 1) {
				result++;
			} else
				stop = -1;
		}

		stop = 0;
		while(nObjs >= nObjsStart && !stop) {
			if(!(Object_loadedObjs[nObjs]->objdata->flags & 1)) {
				nObjs--;
			} else
				stop = -1;
		}

		if(result < nObjs) { // swap
			obj = Object_loadedObjs[result];
			Object_loadedObjs[result] = Object_loadedObjs[nObjs];
			Object_loadedObjs[nObjs] = obj;
			result++;
			nObjs--;
		}
	}

	nVisibleObjs = result;
	return result;
}

void depthSortObjects_doSort(s32 arg0, s32 arg1) {
	ObjInstance *obj;
	BOOL done;
	s32 ii;

	if(arg0 > arg1) return;

	for(ii = arg0; ii <= arg1; ii++) {
		obj = Object_loadedObjs[ii];
		if(obj->objdata->flags & ObjData_Flag_FixedDepth) {
			obj->depth = obj->objdata->fixedDepth * 100;
		} else {
			obj->depth = -getCameraDepth(
			    obj->prevPos.x, obj->prevPos.y, obj->prevPos.z);
		}
	}

	done = false;
	while(!done) {
		done = true;
		for(ii = arg0; ii < arg1; ii++) {
			if(Object_loadedObjs[ii + 1]->depth
			    < Object_loadedObjs[ii]->depth) {
				obj = Object_loadedObjs[ii];
				Object_loadedObjs[ii] = Object_loadedObjs[ii + 1];
				Object_loadedObjs[ii + 1] = obj;
				done = false;
			}
		}
	}
}

// maybe better name is "objUpdateHolders"
void updateObjMtxs(void) {
	ObjInstance *obj1;
	ObjInstance *obj2;
	s32 ii;

	for(ii = 0; ii < ObjListSize; ii++) {
		obj1 = Object_loadedObjs[ii];
		if(obj1->pObj_0xc0) {
			obj2 = obj1->pObj_0xc0;
			if(!obj1->heldBy && obj2->heldBy) { obj1->heldBy = obj2->heldBy; }
			obj1->pObj_0xc0 = NULL;
		}
	}
}

/**
 * @brief Get the global object list.
 *
 *  @param outFirstObj (optional) Receives index of first object (always 0).
 *  @param outNumObjs (optional) Receives number of objects.
 *  @return ObjInstance** The object list.
 */
ObjInstance **Object_getObjects(s32 *outFirstObj, s32 *outNumObjs) {
	if(outFirstObj) *outFirstObj = 0;
	if(outNumObjs) *outNumObjs = ObjListSize;
	return Object_loadedObjs;
}

/**
 * @brief Get the specified object from the global object list.
 *
 *  @param idx Object index.
 *  @return ObjInstance* The object, or NULL if idx is invalid.
 */
ObjInstance *Object_getObject(s32 idx) {
	if((idx < 0) || (idx >= ObjListSize)) { return NULL; }
	return Object_loadedObjs[idx];
}

/**
 * @brief Find an object by its unique ID.
 *
 *  @param id The ID.
 *  @return ObjInstance* The object, or NULL if not found.
 */
ObjInstance *Object_findByUniqueId(u32 id) {
	s32 ii;
	s32 nObjs;
	ObjInstance *obj;

	ii = 0;
	nObjs = ObjListSize;
	while(ii < nObjs) {
		obj = Object_loadedObjs[ii];
		if(obj->def && obj->def->id == id) { return obj; }
		ii++;
	}
	return NULL;
}

s32 Object_getObjListSize(void) {
	return ObjListSize;
}

s32 Object_getFirstLoadedObj(void) {
	return 0;
}

s32 *getTablesBinEntry(s32 idx) {
	// why is this here?
	if((idx < 0) || (idx >= nTablesTab)) { return tables_bin; }
	return (s32 *)((u32)tables_bin + tables_tab[idx] * 4);
}

ObjInstance *objInstantiateCharacter(ObjDef *def, uint flags, int mapId,
int objNo, ObjInstance *heldBy) {
	ObjInstance *obj;

	obj = NULL;
	if(getPiLockedFlags() & 1) STUBBED_OP(obj);

	loadAsset_Character(&obj, def, flags, mapId, objNo, heldBy, 0);
	if(obj) objSetup(obj, flags);

	if(getPiLockedFlags() & 1) STUBBED_OP(obj);
	return obj;
}

ObjInstance *Object_objSetupObjectActual(ObjDef *def, s32 flags, s32 mapId,
s32 romDefNo, struct ObjInstance *heldBy) {
	// should be down to regswap and string offsets
	ObjInstance objTmp;
	ObjData *objData;
	ObjInstance *result;
	s32 oType;
	s32 realType;
	s32 iModelInst;
	s32 iLock;
	s32 ii;
	s8 bModelFailed;
	u32 totalSize;
	u32 modelFlags; // ModelFlags_loadCharacter
	int nModels;
	void *next;

	oType = def->objType;
	if(flags & 2) realType = oType;
	else {
		if(oType > Object_maxObjType) {
			printf("objSetupObjectActual objtype out of range %d/%d\n",
			    oType, Object_maxObjType);
			return NULL;
		}
		realType = Object_pObjIndex[oType];
	}

	memclr(&objTmp, sizeof(ObjInstance));
	result = &objTmp;
	objData = Object_objLoadData(realType);
	result->objdata = objData;
	if((!objData) || ((s32)objData == -1)) {
		debugPrint("Warning: Unknown object type '%d/%d romdefno %d', using "
		    "DummyObject (128)\n",
		    oType, def->objType, result->romdefno);
		if((s32)objData == -1) {
			//@bug missing newline in message
			debugPrint("Warning: Object romdefno is -1, check the object is in "
			    "objects.spec");
		}
		return NULL;
	}

	result->objId = objData->objId;
	result->pos.scale = objData->scale;
	if(0.0f == result->pos.scale) result->pos.scale = 1.0f;
	result->pos.flags = 2;
	if(objData->flags & 0x80) result->pos.flags |= 0x80;
	if(objData->flags & 0x40000) result->flags_0xb0 |= ObjInstance_FlagsB0_LockAnimsAndControls;
	if(flags & 4) result->pos.flags |= ObjInstance_Flags06_DontSave;

	result->pos.pos.x = def->pos.x;
	result->pos.pos.y = def->pos.y;
	result->pos.pos.z = def->pos.z;
	result->realType = realType;
	result->def = def;
	result->romdefno = oType;
	result->romDefNo = romDefNo;
	result->mapId = mapId;
	result->animVal_a2 = -1;
	result->curSeqSlot = -1;
	result->newOpacity = 0xFF;
	result->msgQueue = NULL;
	result->bound = def->bound * 8;
	result->cullDist = def->cullDist * 8;

	result->dll = NULL;
	if(objData->dll_id) {
		// probably wrong return type here
		result->dll = (struct LoadedDLL *)DLL_setup((u32)objData->dll_id, 6U, 1);
		if(!result->dll) printf("OBJECTS: warning DLL load failed\n");
	}

	if(result->romdefno == 0xF7) { STUBBED_OP(result); }
	modelFlags = Object_getModelFlags(result);
	if(objData->flags & 0x20) modelFlags &= ~1;
	else modelFlags |= 1;
	if(objData->shadowType != 0) modelFlags |= 2;
	else modelFlags &= ~2;
	if(objData->shadowType == 3) modelFlags |= 0x8000; // HasShadow

	totalSize = objGetTotalDataSize(result, objData, def, modelFlags);
	result = (ObjInstance *)mmAlloc(totalSize,
		ALLOC_TAG_OBJECTS_COL, (volatile u32) "obj");
	if(!result) {
		printf("ObjSetupObject(3) Memory fail!!\n");
		objFreeObjdef(realType);
		return NULL;
	}
	memcpy_src_dst_len(&objTmp, result, sizeof(ObjInstance));
	memclr(result + 1, totalSize - sizeof(ObjInstance));
	nModels = objData->noframes;
	result->frames = (ModelInstance **)&result[1];

	ii = 0;
	bModelFailed = false;
	if(!(modelFlags & 0x200)) { // objFileHasModels
		if(modelFlags & 0x400) { // OnlyLoadOneModel
			iModelInst = (modelFlags >> 0xBU) & 0xF;
			if(iModelInst < nModels) {
				result->frames[iModelInst] = loadModelInstance(
				    -objData->pModelList[iModelInst], modelFlags);
				if(!(s32)result->frames[iModelInst]) bModelFailed = true;
				else {
					ModelInstance_loadShaders(
					    result->frames[iModelInst], result);
					modelInitSkeleton(result->pos.scale,
						result->frames[iModelInst]);
					if(result->objdata->flags & 0x800) {
						Modelnstance_setTexFuncPtr(result->frames[iModelInst],
						    modelLoadCb_800c5b80);
					}
				}
			}
		} else {
			while(ii < nModels) {
				result->frames[ii] = loadModelInstance(
				    -(s32)objData->pModelList[ii], modelFlags);
				if((s32)result->frames[ii] == 0) bModelFailed = true;
				else {
					ModelInstance_loadShaders(result->frames[ii], result);
					modelInitSkeleton(result->pos.scale, result->frames[ii]);
					if(result->objdata->flags & 0x800) {
						Modelnstance_setTexFuncPtr(
						    result->frames[ii], modelLoadCb_800c5b80);
					}
				}
				ii += 1;
			}
		}
	}
	if(bModelFailed) {
		Object_freeModels(result, nModels);
		objFreeObjdef(realType);
		return NULL;
	}
	next = &result->frames[objData->noframes];
	next = Object_objInitState(result, next);
	if(modelFlags & 0x40) {
		next = Object_objSetupEvents((s32)result->romdefno,
			result, next);
	}
	if(modelFlags & 0x100) {
		next = Object_objSetupModels(
		    result->romdefno, result->frames[0]->mod, result, next);
	}
	if((modelFlags & 2) && ((s16)objData->shadowType != 0)) {
		next = Object_objLoadShadow(result, next, 0);
	}
	result->cullDistance = result->pos.scale * objModelFn_800839d4(result);
	if((u8)objData->maybeNumHits != 0) {
		next = (void *)Object_objSetupHitState(result, next);
		if((u8)objData->flags93 & 8) {
			next = (void *)Object_objSetupField58(result, next);
		}
	}
	if((u8)objData->nJoints != 0) {
		next = alignTo4(next);
		result->joints = next;
		next = (void *)((s32)next + ((u8)objData->nJoints * sizeof(Joint)));
	}
	if((u8)objData->nTextures != 0) {
		next = alignTo4(next);
		result->pTextures = next;
		next = (void *)((s32)next + ((u8)objData->nTextures * 0x10));
	}
	if((u8)objData->numLockData != 0) {
		next = alignTo4(next);
		result->romLockdata = next;
		next = (void *)((s32)next
		    + ((u8)objData->numLockData * sizeof(RomLockData)));
	}
	if(((u8)objData->maybeNumHits != 0) && ((u8)objData->bDisableHits != 0)) {
		next = alignTo4(next);
		next = Object_objSetupHits((s32)result->romdefno,
		    (ModelInstance *)result->frames[0],
		    result->hits,
		    next,
		    result);
	}
	if(objData->numLockData != 0) {
		next = alignTo4(next);
		result->lockdata = next;
		for(iLock = 0; iLock < objData->numLockData; iLock++) {
			result->lockdata[iLock].flags = objData->lockdata[iLock].flags;
			result->lockdata[iLock].fieldC = objData->lockdata[iLock].fieldC;
			result->lockdata[iLock].fieldF = objData->lockdata[iLock].fieldF;
			result->lockdata[iLock].combatCamDist
			    = objData->lockdata[iLock].combatCamDist;
			result->lockdata[iLock].maxDist = objData->lockdata[iLock].maxDist;
		}
		next = (void *)((u32)next
		    + (u32)(objData->numLockData * sizeof(RamLockData)));
	}
	if((s32)totalSize != ((s32)next - (s32)result)) {
		printf("objects.c: objSetupObject: sizes do not match\n");
	}
	result->heldBy = heldBy;
	Object_streamFn_8018fa50(result, (s32)result->romdefno);
	return result;
}

void objSetup(ObjInstance *object, uint bAddToLoadedObjs) {
	if(object->heldBy) multVectorByObjMtx(object->pos.pos.x,
		object->pos.pos.y,
		object->pos.pos.z,
		&(object->prevPos).x,
		&(object->prevPos).y,
		&(object->prevPos).z,
		object->heldBy);
	else {
		object->prevPos.x = object->pos.pos.x;
		object->prevPos.y = object->pos.pos.y;
		object->prevPos.z = object->pos.pos.z;
	}
	object->pos_0x8c.x = object->prevPos.x;
	object->pos_0x8c.y = object->prevPos.y;
	object->pos_0x8c.z = object->prevPos.z;
	object->oldPos.x = object->pos.pos.x;
	object->oldPos.y = object->pos.pos.y;
	object->oldPos.z = object->pos.pos.z;
	objSetupDll(object, object->def, 0);
	if(object->hits) {
		object->hits->pos.x = object->pos.pos.x;
		object->hits->pos.y = object->pos.pos.y;
		object->hits->pos.z = object->pos.pos.z;
		object->hits->prevPos.y = object->pos.pos.x;
		object->hits->prevPos.z = object->pos.pos.y;
		object->hits->size = object->pos.pos.z;
	}
	if(-1 < object->objdata->unka0) {
		worldMapListFn_800aac60(
		    (int)*(short *)&object->objdata->unka0, (int)object);
	}
	if((object->objdata->flags & ObjFileStructFlags44_IsWorldObj)) {
		Object_objAddObjectType(object, ObjCat_StaticCamera);
		if(object->priority != OBJ_PRIORITY_WORLD) {
			Object_setPriority(object, OBJ_PRIORITY_WORLD);
		}
	} else if(object->priority == 0) {
		Object_setPriority(object, OBJ_PRIORITY_DEFAULT);
	}
	if(bAddToLoadedObjs & 1) {
		object->flags_0xb0 |= ObjInstance_FlagsB0_IsInGlobalObjList;
		Object_loadedObjs[ObjListSize++] = object;
		ASSERTLINE(1202, ObjListSize < MAX_OBJECTS);
		LAB_80083bd4(object);
	}
	if(0 < object->objdata->numSeqs) {
		objAddObjectType(object, ObjCat_LevelControl);
	}
	if(object->objdata->flags & ObjFileStructFlags44_HaveModels) {
		clearNVisibleObjs();
	}
	if(object->objdata->flags & ObjFileStructFlags44_DifferentLightColor) {
		objAddObjectType(object, 0x38);
	}
}

int objGetExtraSize(ObjInstance *object, void *state) {
	switch(object->romdefno) {
		case ObjDefNo_Krystal:
		case ObjDefNo_Sabre: return 0x8c4; // sizeof(PlayerState)

		default:
			if(object->dll && ((LoadedDLL*)object->dll)->funcs->Object.getExtraSize) {
				return (*((LoadedDLL*)object->dll)->funcs->Object.getExtraSize)(object, state);
			}
			return 0;
	}
}

uint objGetTotalDataSize(
    ObjInstance *obj, ObjData *objData, ObjDef *objDef, uint flags) {
	uint size;

	size = sizeof(ObjInstance);
	size += objData->noframes * 4;
	size += objGetExtraSize(obj, (void*)size);
	if(flags & 0x40) {
		size = (int)alignTo4((void *)size);
		size += 8;
		size = alignTo8(size);
		size += 0x50;
	}
	if(flags & 0x100) {
		size = (int)alignTo4((void *)size);
		size += 8;
		size = alignTo8(size);
		size += 0x400;
	}
	if(flags & 2 && objData->shadowType != ObjShadowType_None) {
		size = (int)alignTo4((void *)size);
		size += sizeof(Shadow);
	}
	if(objData->maybeNumHits) {
		size = (uint)alignTo4((void *)size);
		size += 0xa4;
		if((objData->flags93 & 8) != 0) { size += 0x110; }
	}
	if(objData->nJoints) {
		size = (int)alignTo4((void *)size);
		size += (uint)objData->nJoints * sizeof(Joint);
	}
	if(objData->nTextures) {
		size = (int)alignTo4((void *)size);
		size += (uint)objData->nTextures * 0x10;
	}
	if(objData->numLockData) {
		size = (int)alignTo4((void *)size);
		size += (uint)objData->numLockData * sizeof(RomLockData);
	}
	if(objData->maybeNumHits && objData->bDisableHits) {
		size = alignTo8(size);
		size += 300;
	}
	if(objData->numLockData) {
		size = (int)alignTo4((void *)size);
		size += (uint)objData->numLockData * sizeof(RamLockData);
	}
	return size;
}

void modelInitSkeleton(float scale, ModelInstance *modelInstance) {
	int iParent;
	float *radi;
	Model *model;
	ModelSkeletonStruct *skel;
	int iJoint;
	float dist;
	Vec distV;
	float distances[MAX_JOINTS];

	model = modelInstance->mod;
	if(!modelInstance->mod->numJoints) return;
	radi = modelInstance->mod->radi;
	if(!radi) return;
	if(!modelInstance->skeleton) return;

	skel = modelInstance->skeleton;
	skel->scale[0] = radi[0] * scale;
	if(!skel->scale[0]) skel->scale[0] = radi[1] * scale;

	skel->unk08[0] = skel->scale[0] * skel->scale[0];
	skel->jointDist[0] = 0.01;
	skel->totalDist[0] = skel->scale[0];
	distances[0] = 0.0;

	for(iJoint = 1; iJoint < modelInstance->mod->numJoints; iJoint++) {
		skel->scale[iJoint] = scale * radi[iJoint];
		skel->unk08[iJoint] = skel->scale[iJoint] * skel->scale[iJoint];

		iParent = model->joints[iJoint].parent;
		distV.x = model->joints[iJoint].translation.x;
		distV.y = model->joints[iJoint].translation.y;
		distV.z = model->joints[iJoint].translation.z;
		dist = distV.x * distV.x + distV.y * distV.y + distV.z * distV.z;
		skel->jointDist[iJoint] = scale * sqrt(dist);

		if(!skel->jointDist[iJoint]) skel->jointDist[iJoint] = 0.1;
		if(model->exT[iJoint] >= 1.0f) skel->jointDist[iJoint] *= model->exT[iJoint];
		distances[iJoint] = distances[iParent] + skel->jointDist[iJoint];
		if(!radi[iJoint]) skel->totalDist[iJoint] = -100.0;
		else skel->totalDist[iJoint] = distances[iJoint] + skel->scale[iJoint];
	}
}

float objModelFn_800839d4(ObjInstance *object) {
	ModelInstance *mInst;
	float result;
	s32 ii;

	result = 10.0f;
	for(ii = 0; ii < object->objdata->noframes; ii++) {
		if((int)object->frames[ii]) {
			mInst = object->frames[ii];
			if(modelGetFieldA4(mInst->mod) > result) {
				result = modelGetFieldA4(mInst->mod);
			}
		}
	}
	if(result < object->objdata->unk9c) { result = 16.0f * object->objdata->unk9c; }
	return result;
}

void Object_freeModels(ObjInstance *object, int count) {
	s32 spC;
	s32 ii;

	for(ii = 0; ii < count; ii++) {
		if((int)object->frames[ii]) {
			modelInstanceFree(object->frames[ii]);
		}
	}
}

void objFreeFn_80083b54(ObjInstance *object) {
    if(object->flags_0xb0 & ObjInstance_FlagsB0_IsInGlobalObjList) {
        objRemoveFromList(&objList_80398a88, object);
    }
}

//something like "add to global(?) object list"
void fn_80083B94(ObjInstance *object) {
	ObjInstance *r30;
	ObjInstance *r31;
	ObjInstance *sp10;
	volatile s16 size; //spC

	if(!(object->flags_0xb0 & ObjInstance_FlagsB0_IsInGlobalObjList)) return;

	size = objList_80398a88.objSize;
	r30 = NULL;
	r31 = objList_80398a88.obj;
	sp10 = r31;
	while((int)r31 && object->priority < r31->priority) {
		r30 = r31;
		//sp10 = *(ObjInstance **)((int)r31 + size);
		//use of r3 for list is suspicious, maybe inlining?
		r31 = *(ObjInstance **)((int)r31 + size);
	}
	objListAdd(&objList_80398a88, r30, object);
}

void objFreeObject(ObjInstance *obj) {
	int ii, jj;

	ASSERTLINE(1467, obj);
	if(obj->flags_0xb0 & ObjInstance_FlagsB0_IsFreed) return;
	objStopSounds(obj, 0x7f, __FILE__, 1474);

	if(obj->flags_0xb0 & ObjInstance_FlagsB0_IsInGlobalObjList) {
		// find this object's index in the global object list
		for(ii = 0; ii < ObjListSize; ii++) {
			if(Object_loadedObjs[ii] == obj) break;
		}
		if(ii < ObjListSize) {
			// shift all following entries down
			ObjListSize--;
			for(jj = ii; jj < ObjListSize; jj++) {
				Object_loadedObjs[jj] = Object_loadedObjs[jj + 1];
			}
		}
		objFreeFn_80083b54(obj);
		clearNVisibleObjs();
	}
	obj->flags_0xb0 |= ObjInstance_FlagsB0_IsFreed;

	LAB_8018fb20(obj, obj->romdefno);
	if(obj->lockedFreeTick) {
		// add to the lock list if not already present
		for(ii = 0; ii < ObjListSize; ii++) {
			if(Object_loadedObjs[ii] == obj) break;
		}
		if(ii == Object_lockListLen) {
			Object_lockList[Object_lockListLen] = obj;
			Object_lockListLen++;
		} else {
			printf("objFreeTick %08x locked %d,already on list\n",
			    obj,
			    obj->lockedFreeTick);
		}
	} else if(var_80396D08 == 2) {
		// add to delete list if not already present
		ii = Object_objDelListCount;
		if(Object_objDelListCount != 0) {
			for(ii = 0; ii < ObjListSize; ii++) {
				if(Object_loadedObjs[ii] == obj) break;
			}
		}
		if(ii == Object_objDelListCount) {
			Object_delList[Object_objDelListCount] = obj;
			Object_objDelListCount += 1;
			if(Object_objDelListCount == 200) {
				printf("objFreeObject: delete list size overrun\n");
				Object_objDelListCount -= 1;
			}
		}
	}
	// else delete it now
	else
		Object_worldProcessObjFreeList(obj, var_80396D08 == 0);
}

void objSetupDll(ObjInstance *object,ObjDef *def,void *param) {
    ObjDefEnum sVar1;

    switch(object->romdefno) {
		case ObjDefNo_Krystal:
		case ObjDefNo_Sabre:
            playerOnLoad(object, def, param);
            break;

        default:
            if(object->dll) {
                (*((LoadedDLL*)object->dll)->funcs->Object_onLoad)(object, def, param);
            }
    }
    if(object->shadow) object->shadow->flags |= 8;
    object->oldPos.x   = object->pos.pos.x;
    object->oldPos.y   = object->pos.pos.y;
    object->oldPos.z   = object->pos.pos.z;
    object->pos_0x8c.x = object->pos.pos.x;
    object->pos_0x8c.y = object->pos.pos.y;
    object->pos_0x8c.z = object->pos.pos.z;
}

void fn_80083F50(ObjInstance *object) {
	if(object->flags_0xb0 & ObjInstance_FlagsB0_IsFreed) return;

	if((object->objId == 0x1D) && (BYTE_80398a91 & 1)) {
		if(object->hits) {
			object->hits->unk48 = 0;
			object->hits->nSpheres = 0;
		}
		return;
	} else if((object->objId == 2) && (BYTE_80398a91 & 2)) {
		if(object->hits) {
			object->hits->unk48 = 0;
			object->hits->nSpheres = 0;
		}
		return;
	} else if(object->pObj_0xc0) {
		if(object->child[0] && object->child[0]->hits) {
			object->child[0]->hits->unk48 = 0;
			object->child[0]->hits->nSpheres = 0;
		}
		if(!object->hits) return;
		object->hits->unk48 = 0;
		object->hits->nSpheres = 0;
		return;
	}
	if(!(object->pos.flags & ObjInstance_Flags06_DontTrackOldPositions)) {
		(object->oldPos).x = (object->pos).pos.x;
		(object->oldPos).y = (object->pos).pos.y;
		(object->oldPos).z = (object->pos).pos.z;
		(object->pos_0x8c).x = (object->prevPos).x;
		(object->pos_0x8c).y = (object->prevPos).y;
		(object->pos_0x8c).z = (object->prevPos).z;
	}
	if(object->stateFlags) {
		if(!object->parent) {
			if(object->stateFlags & 1) fn_80085dc8(object);
			if(object->stateFlags & 2) objFn_8002aac8(object);
		}
	}
	if(getPiLockedFlags() & 2) STUBBED_OP(object);
	if(!(object->flags_0xb0 & ObjInstance_FlagsB0_DontUpdate)) {
		switch(object->romdefno) {
			case ObjDefNo_Krystal:
			case ObjDefNo_Sabre:
				playerFn801925a0(object);
				break;
			default:
				if(!object->dll) goto l953;
				(*((LoadedDLL*)object->dll)->funcs->Player.func08)(object);
				break;
		}
		objMultPosByMtx(object,
		    &object->prevPos.x,
		    &object->prevPos.y,
		    &object->prevPos.z);
	}

l953:
	if(getPiLockedFlags() & 2) STUBBED_OP(object);
	if(object->hits) {
		if(object->child[0] && object->child[0]->hits) {
			object->child[0]->hits->unk48 = 0;
			object->child[0]->hits->nSpheres = 0;
		}
		object->hits->unk4c = 0;
		object->hits->unk48 = 0;
		object->hits->nSpheres = 0;
	}
	if(object->polyHits) object->polyHits->unk10f = 0;
	object->flags_0xaf = object->flags_0xaf & ~7;
}

void Object_objLoadWeaponData(ObjInstance *object, int objType,
int *outData, int id, bool loadAsync) {
	int ii;
	int offset;
	s16 *data;

	data = (s16*)object->objdata->pWeaponDa; //ObjWeaponData*
	*outData = 0;
	if(data) {
		for(ii = 0; data[ii] != -1; ii += 3) {
			if(id == data[ii]) {
				offset = data[ii+1]; //.offset;
				*outData = data[ii+2]; //.size;
				if(0x400 < *outData) {
					*outData = 0x400;
					printf("Weapon data array size overflow\n");
				}
				if(loadAsync) loadAsset_fileWithOffsetLength(
						(void *)outData[1], FILE_WEAPONDA_bin,
					    (int)offset, *outData);
				else loadDataFileWithLength(
				    FILE_WEAPONDA_bin, (void *)outData[1], (int)offset, *outData);
				return;
			}
		}
	}
}

ObjData *Object_objLoadData(int objType) {
	ObjData *objData;
	uint offset;
	uint size;

	if(objType >= (int)Object_maxObjId) return NULL;
	if(objDefNoUsage[objType] != 0) {
		objDefNoUsage[objType]++;
		objData = objDefNoList[objType];
		return objData;
	}
	offset = Object_pObjectsTab[objType];
	size = Object_pObjectsTab[objType + 1] - offset;
	objData = (ObjData *)mmAlloc(size,
		ALLOC_TAG_OBJECTS_COL, (volatile u32)"obj:def");
	if(objData) {
		loadDataFileWithLength(FILE_OBJECTS_bin, objData, offset, size);
		if(objData->pEvent) OFFSET_TO_PTR(s16, objData, pEvent);
		if(objData->pHits) OFFSET_TO_PTR(UNKTYPE, objData, pHits);
		if(objData->pWeaponDa) OFFSET_TO_PTR(ObjWeaponData, objData, pWeaponDa);
		OFFSET_TO_PTR(u32, objData, pModelList);
		OFFSET_TO_PTR(Texture, objData, textures.ptr);
		OFFSET_TO_PTR(Joint, objData, joints);
		if(objData->offset_0x18) OFFSET_TO_PTR(ObjSeqCmd, objData, offset_0x18);
		if(objData->lockdata) OFFSET_TO_PTR(RomLockData, objData, lockdata);
		if(objData->pSeq) OFFSET_TO_PTR(u16, objData, pSeq);
		OFFSET_TO_PTR(AttachPoint, objData, pAttachPoints);
		objData->pModLines = NULL;
		objData->wObjList = NULL;

		if(objData->modLineNo > -1) {
			printf("ob %d fileno %d\n", objType, (int)objData->modLineNo);
			objData->pModLines = loadModLine((int)objData->modLineNo,
				&objData->modLineCount);
			intersectModLineBuild(objData);
		}
		objDefNoList[objType] = objData;
		objDefNoUsage[objType] = 1;
	}
	else {
		printf("Objects out of ram(1) !!\n");
		return NULL;
	}
	return objData;
}

//probably objMove or such
void fn_80084238(ObjInstance *object) {
    ObjDefEnum OVar1;

    if ((object->flags_0xb0 & ObjInstance_FlagsB0_DontMove) == 0) {
        switch(object->romdefno) {
            case ObjDefNo_Krystal:
            case ObjDefNo_Sabre:
                LAB_801929c4(object);
                break;

            default:
                if(!object->dll) return;
                (*((LoadedDLL*)object->dll)->funcs->Object.hitDetect)(object);
        }
        objMultPosByMtx(object,
            &object->prevPos.x,&object->prevPos.y,&object->prevPos.z);
    }
}

void* Object_objInitState(ObjInstance *object,void *state) {
    int size;

    state = (void *)alignTo4(state);
    size = objGetExtraSize(object, state);
    if(size) {
        object->state = (undefined *)state;
        state = (void *)((int)state + size);
    }
    else {
        object->state = NULL;
    }
    return state;
}

//return: ModelFlags_loadCharacter
u32 Object_getModelFlags(ObjInstance *object) {
    switch(object->romdefno) {
        case ObjDefNo_Krystal:
        case ObjDefNo_Sabre:
            return 0x1cb;

        default:
            if(object->dll && ((LoadedDLL*)object->dll)->funcs->Object.getModelFlags) {
				return (*((LoadedDLL*)object->dll)->funcs->Object.getModelFlags)(object);
			}
			else return 0;
    }
}

void* Object_objSetupEvents(int romdefno, ObjInstance *object, void *ptr) {
    ptr = (ObjEventData *)alignTo4(ptr);
    object->pEventName = ptr;

    ptr = (void*)((uint)ptr + sizeof(ObjEventData));
    ptr = (void *)alignTo8(ptr);
    object->pEventName->data = (ObjEventData2*)ptr;

    ptr = (void *)((uint)ptr + sizeof(ObjEventData2));
    objLoadEventData(object,romdefno,object->pEventName,0,true);
    return ptr;
}

void Object_objLoadEventData(ObjInstance *object,int romdefno,
ObjEventData *event,int animId,bool bImmediate) {
    int offset;
    int ii;
    s16 *evtData;

    evtData = (s16 *)object->objdata->pEvent;
    event->size = 0;
    if(!evtData) return;

    for(ii = 0; evtData[ii] != -1; ii += 3) {
        if(animId == evtData[ii]) {
            offset = evtData[ii + 1];
            event->size = evtData[ii + 2];
            //0x50 might be sizeof(ObjEventData2)
            if(event->size > 0x50) {
                printf("objects.c: event data size overflow\n");
                event->size = 0x50;
            }
            if(!bImmediate) loadAsset_fileWithOffsetLength(event->data,
                FILE_OBJEVENT_bin, offset, event->size);
            else loadDataFileWithLength(FILE_OBJEVENT_bin,
                event->data,offset,event->size);
            return;
        }
    }
}


void* Object_objSetupModels(int romdefno, Model *model,
ObjInstance *object,void *ptr) {
    if(!model) return ptr;

    ptr = alignTo4(ptr);
    object->models = ptr;
    ptr = (void*)((uint)ptr + 8);
    ptr = (void*)alignTo8(ptr);
    *(uint *)&object->models->cacheModNo = (uint)ptr;
    ptr = (void *)((uint)ptr + 0x400);
    return ptr;
}


void objFreeObjdef(int defNo) {
    ObjData *data;

    if(objDefNoUsage[defNo] == 0) {
        debugPrint("objFreeObjdef: Error!! (%d)\n",defNo);
    }
    else {
        objDefNoUsage[defNo]--;
        if(!objDefNoUsage[defNo]) {
            data = objDefNoList[defNo];
            if(data->pModLines) mmFree(data->pModLines);
            if(data->wObjList) mmFree(data->wObjList);
            mmFree(data);
        }
    }
}

ModLine* loadModLine(int lineNo, s16 *outCount) { //regswap
    ModLine *dest;
    uint offset;
    uint *tempIdx;
    uint size;
    int fileSize;

    dest = NULL;
    fileSize = (getLoadedDataFileSize(FILE_MODLINES_tab) - 4) >> 2;
    if(lineNo > fileSize) return NULL;

    tempIdx = mmAlloc(0x10,ALLOC_TAG_TEST_COL,(volatile u32)"obj:tempindex");
    lineNo *= 4;
    loadDataFileWithLength(FILE_MODLINES_tab, tempIdx, lineNo, 8);

    offset = tempIdx[0];
    size = tempIdx[1] - tempIdx[0];
    if((int)size > 0) {
        dest = mmAlloc(size, ALLOC_TAG_TRACK_COL, (volatile u32)"obj:templine");
        loadDataFileWithLength(FILE_MODLINES_bin, dest, offset, size);
    }
    mmFree(tempIdx);
    *outCount = size / 0x14;
    return dest;
}

void nop_800849FC() {
}

int Object_getMaxObjType() {
	return Object_maxObjType;
}

BOOL ObjEdit_isObjIndexNotEmpty(int idx) {
	if(idx > Object_maxObjType) return false;
	return Object_pObjIndex[idx] != -1;
}

int Object_objGetControlNo(int objType) { //regalloc
	u8 wat[180];
	uint ii;
	uint offset;
	int count;
	int index;

	if (objType > Object_maxObjType) {
		printf("objGetControlNo objtype out of range %d/%d\n",
			objType, Object_maxObjType);
		return 0;
	}
	index = Object_pObjIndex[objType];
	if(index == -1) return 0;

	//wtf is this?
	count = 0;
	for (ii = &wat[90] - &wat[0]; (ii & 1) != 0; count++) {
		ii--;
	}

	offset = Object_pObjectsTab[index] + ii;
	loadAsset_fileWithOffsetLength(
		contNoBuf, FILE_OBJECTS_bin,
		offset,
		8);
	index = contNoBuf[count];
	return index;
}

ObjFileStructFlags44 Object_objTypeGetFlags(int objType) {
	ObjData *data;

	if(objType > Object_maxObjType) {
		printf("objTypeGetFlags objtype out of range %d/%d\n",
			objType, Object_maxObjType);
		return 0;
	}
	objType = Object_pObjIndex[objType];
	if(objType >= Object_maxObjId) return 0;

	data = (ObjData*)((u32)Object_objTypes + Object_pObjectsTab[objType]);
	return data->flags;
}

u8 Object_objTypeGetClass(int objType) {
	ObjData *data;

	if(objType > Object_maxObjType) {
		printf("objTypeGetClass objtype out of range %d/%d\n",
			objType, Object_maxObjType);
		return 0;
	}
	objType = Object_pObjIndex[objType];
	if(objType >= Object_maxObjId) return 0;

	data = (ObjData*)((u32)Object_objTypes + Object_pObjectsTab[objType]);
  	return data->class_;
}

void Object_worldProcessObjFreeList(ObjInstance *obj, int param2) {
	int noframes;
	int ii;
	int jj;
	int kk;
	ObjInstance **state;
	ObjInstance *that;
	ObjInstance *freelist[50];

	ASSERTLINE(2275, obj);
	ASSERTLINE(2276, obj->objdata);
	if(obj->nTouchCallbacks) freeFn_80092460(obj);

	switch(obj->romdefno) {
        case ObjDefNo_Krystal:
        	krystalFree(obj, param2);
			break;
		default:
			if(obj->dll) {
			if(((LoadedDLL*)obj->dll)->funcs->Object.onFreeObjDef) {
				(*((LoadedDLL*)obj->dll)->funcs->Object.onFreeObjDef)(obj, param2);
			}
			DLL_free(((LoadedDLL*)obj->dll));
			obj->dll = NULL;
		}
	}
	pDll_Dummy04->funcs->Dummy04.func14_nop(obj);
	pDll_expgfx->funcs->expgfx.ownerFree3(obj);
	if(obj->objdata
	&& obj->objdata->flags & ObjFileStructFlags44_DifferentLightColor) {
		objRemoveObjectType(obj, 0x38);
	}
	if(obj->objdata->flags & ObjFileStructFlags44_IsWorldObj) {
		objRemoveObjectType(obj, 7);
		if(!param2) {
			ii = 0;
			for(jj = 0; jj < (int)ObjListSize; jj += 1) {
				that = Object_loadedObjs[jj];
				if(PTR_EQ(that->heldBy, obj)) {
					that->heldBy = NULL;
					if(that->def) {
						freelist[ii] = that;
						ii += 1;
						//no idea where this number comes from
						//typo? since the list is 50 elements
						if(ii >= 40) printf("world free obj list overflow\n");
					}
				}
			}
			for(jj = 0; jj < ii; jj += 1) {
				objFreeObject(freelist[jj]);
			}
			trackFreeMap((uint)obj->map);
		}
	}
	if(param2 == 0 && obj->objId == 0x10) {
		for(jj = 0; jj < (int)ObjListSize; jj += 1) {
			that = Object_loadedObjs[jj];
			if(PTR_EQ(that->pObj_0xc0, obj)) {
				that->pObj_0xc0 = NULL;
			}
		}
	}
	for(kk = 0; kk < ObjListSize; kk++) {
		that = Object_loadedObjs[kk];
		if(that->objId == 0x10) {
			state = that->state; //XXX type
			if(*state == obj) {
				*state = NULL;
				*(undefined *)(state + 0x22) = 1;
			}
		}
	}
	if(obj->objdata->numSeqs > 0) objRemoveObjectType(obj, 9);
	if(obj->shadow) {
		if(obj->objdata->shadowType == ObjShadowType_BigBoxShadow) {
			setShadowFlag_803db658(1);
		}
		if(obj->shadow->texture) texFreeTexture(obj->shadow->texture);
		if(obj->shadow->texture2) texFreeTexture(obj->shadow->texture2);
		if((obj->shadow->unk10) && ((uint)obj->shadow->unk10 != -1)) {
			mmFree(obj->shadow->unk10);
		}
	}
	if(obj->msgQueue) {
		mmFree(obj->msgQueue);
		obj->msgQueue = NULL;
	}
	noframes = obj->objdata->noframes;
	for(kk = 0; noframes < kk; kk++) {
		if((int)obj->frames[kk]) {
			modelInstanceFree(obj->frames[kk]);
		}
	}
	if(obj->stateFlags & 1) fn_80085DDC(obj);
	if(obj->stateFlags & 2) LAB_800860ac(obj);
	objFreeObjdef(obj->realType);
	if((obj->curSeqSlot > -1) && (param2 == 0)) {
		pDll_checkpoint->funcs->anim.endObjSequence(obj->curSeqSlot);
		obj->curSeqSlot = -1;
	}
	if((obj->pos.flags & ObjInstance_Flags06_DontSave) && obj->def) {
		mmFree(obj->def);
	}
	memclr(obj, 0xfc);
	mmFree(obj);
}

ObjDef * objAlloc(uint size,ObjDefEnum type) {
	ObjDef *odef;

	odef = (ObjDef *)mmAlloc(size,
		ALLOC_TAG_OBJECTS_COL,(volatile u32)"romdef");
	memclr(odef,size);
	odef->id         = -1;
	odef->bound      = 100;
	odef->cullDist   = 50;
	odef->loadFlags  = RomListLoadFlag_AllocatedByCode;
	odef->mapStates2 = 4;
	odef->objType    = type;
	return odef;
}

ObjDef ObjDef_802eca98;
LoadedDLL *pDll_camcontrol;
LoadedDLL *pDll_dummy04;
ObjInstance *playerHeldBy; //80398a94
float sinf(float);
float cosf(float);

void mapSetupPlayer(void) {
	ObjInstance *heldBy; //r31
	CharPos *charPos; //r29
	int ii; //r28
	ObjDefEnum playerType; //r26
	Camera *cam; //r25
	ObjInstance *charObj; //r24
	float x, y, z;
	ObjDef chrDef;
	int whichObjs; //sp10
	volatile int playerIdx; //sp0C
	volatile int mapType; //sp08

	mapType = getCurMapType();
	if(mapType == 2 || mapType == 3) {
		objFreeAll();
		return;
	}
	heldBy = NULL;
	playerType = mapGetPlayerObjType(&whichObjs);
	if(playerType != ObjDefNo_Sabre) {
		chrDef.pos.x = 0.0f;
		chrDef.pos.y = 0.0f;
		chrDef.pos.z = 0.0f;
		chrDef.objType = playerType;
		chrDef.loadFlags = RomListLoadFlag_isLevelObject;
		chrDef.mapStates2 = 4;
		chrDef.bound = 0xff;
		chrDef.cullDist = 0xff;
		heldBy = objInstantiateCharacter(&chrDef,
			ObjSpawnFlags_KeepLoaded, -1, -1, NULL);
		heldBy->def = NULL;
		heldBy->pos.pos.x = 0.0f;
		heldBy->pos.pos.y = 0.0f;
		heldBy->pos.pos.z = 0.0f;
		heldBy->pos.rotation.x = 0;
		heldBy->pos.rotation.y = 0;
		heldBy->pos.rotation.z = 0;
		Camera_setPlayerNo(0);
		cam = getCurCamera();
		cam->obj40 = heldBy;
		for(ii = 0; ii < (int)ObjListSize; ii += 1) {
			if(Object_loadedObjs[ii] != heldBy) {
				Object_loadedObjs[ii]->heldBy = heldBy;
			}
		}
		//game is using r0 instead of r3 as temporary here
		heldBy->mtxIdx = Camera_addWorldMtx(&heldBy->pos);
	}
	playerIdx = 1;
	charPos = (CharPos *)pDll_gplay->funcs->gplay.getCurCharPos();
	x = charPos->pos.x;
	y = charPos->pos.y;
	z = charPos->pos.z;
	charObj = NULL;
	if(playerIdx > -1 && mapType != 4) {
		memclr(&chrDef, sizeof(ObjDef));
		chrDef.id = -1;
		chrDef.mapStates1 = 0;
		chrDef.loadFlags = RomListLoadFlag_isLevelObject;
		chrDef.mapStates2 = 4;
		chrDef.bound = 0xff;
		chrDef.cullDist = 100;
		chrDef.objType = playerObjIds[playerIdx];
		chrDef.allocatedSize = sizeof(ObjDef);
		chrDef.pos.x = x;
		chrDef.pos.y = y;
		chrDef.pos.z = z;
		charObj = objInstantiateCharacter(&chrDef,
			ObjSpawnFlags_KeepLoaded, -1, -1,
			heldBy);
	}
	ObjDef_802eca98.pos.x = sinf(((charPos->rotX << 8) * PI) / 32767.0f) * 60.0f + x;
	ObjDef_802eca98.pos.y = y + 40.0f;
	ObjDef_802eca98.pos.z = cosf(((charPos->rotX << 8) * PI) / 32767.0f) * 60.0f + z;
	pDll_camcontrol->funcs->camcontrol.func03(charObj,
		ObjDef_802eca98.pos.x, ObjDef_802eca98.pos.y, ObjDef_802eca98.pos.z);
	pDll_camcontrol->funcs->camcontrol.setupCamControl1(
		0x50, 0, 0, 0x20, &ObjDef_802eca98, 0, 0xff);
	pDll_camcontrol->funcs->camcontrol.func04(1);
	pDll_dummy04->funcs->Dummy04.func06_nop(charObj);
	playerHeldBy = heldBy;
	playerUpdateFn_800ae404();
}

//unsure what object this is
typedef struct {
	ObjDef def;
	u8 param0, param1;
	//probably more...
} ObjDef_802ed010_t;

void fn_80085448(ObjInstance *object, int objType) { //reloc
	static ObjDef_802ed010_t ObjDef_802ed010;
	ObjDef_802ed010_t *objdef = (ObjDef_802ed010_t*)object->def;
	ObjDef_802ed010.def.objType = objType;
	ObjDef_802ed010.def.pos.x = (object->prevPos).x;
	ObjDef_802ed010.def.pos.y = (object->prevPos).y;
	ObjDef_802ed010.def.pos.z = (object->prevPos).z;
	ObjDef_802ed010.param0 = objdef->param0;
	ObjDef_802ed010.param1 = objdef->param1;
	objInstantiateCharacter(&ObjDef_802ed010.def,
		ObjSpawnFlags_KeepLoaded,-1,-1,NULL);
}

ObjInstance* Object_objGetMain(void) {
	ObjInstance **objs;
	int nObj;

	objs = Object_playerGetObject(0,&nObj);
	if (1 < nObj) {
		printf(" ERROR : Error in Get Main More Players Loaded ");
	}
	if(nObj) return *objs;
	else return NULL;
}

ObjInstance* Object_getSidekicksLoaded(void) {
	ObjInstance **objs;
	int nObj;

	objs = Object_playerGetObject(1,&nObj);
	if (1 < nObj) {
		printf(" ERROR : ERROR : Error in Get Sidekicks Loaded  ");
	}
	if(nObj) return *objs;
	else return NULL;
}

/**
 * @brief Set the object's map ID to -1.
 *
 *  @param object The object.
 */
void objClearMapId(ObjInstance *object) {
	object->mapId = -1;
}

/**
 * @brief Set the object's map ID to the map it's in.
 *
 *  @param object The object.
 */
void objResetMapId(ObjInstance *object) {
	object->mapId = mapCoordsToId(object->pos.pos.x, object->pos.pos.z);
}

/**
 * @brief Add specified values to object's position.
 *
 *  @param obj The object.
 *  @param x X value to add.
 *  @param y Y value to add.
 *  @param z Z value to add.
 *  @return int Always zero.
 */
int objMove(ObjInstance *obj, float x, float y, float z) {
	obj->pos.pos.x += x;
	obj->pos.pos.y += y;
	obj->pos.pos.z += z;
	return 0;
}

void Object_setPriority(ObjInstance *obj, s8 priority) {
	if((priority == OBJ_PRIORITY_WORLD)
	&& ((obj->objdata->flags & ObjFileStructFlags44_IsWorldObj) == 0)) {
		printf("WARNING Cannot set priority Level to WORLD if not world object  \n");
	}
	else obj->priority = priority;
}

void objSetModelNo(ObjInstance *object,int modelNo) {
	if (modelNo != object->modelno) {
		if (modelNo < 0) modelNo = 0;
		else if(modelNo >= object->objdata->noframes) {
			modelNo = object->objdata->noframes + -1;
		}
		//unload previous shaders and load new ones
		ModelInstance_unloadShaders(
			object->frames[object->modelno]);
		ModelInstance_loadShaders(
			object->frames[modelNo],object);
		object->modelno = modelNo;
	}
}

void Object_objAddEffectBox(ObjInstance *object) {
	effectBoxes[numEffectBoxes++] = object;
	if(numEffectBoxes == MAX_EFFECT_BOXES) {
		printf("warning: objAddEffectBox max effect boxes\n");
	}
}

void Object_objFreeEffectBox(ObjInstance *box) {
	int ii;
	ObjInstance **boxes;

	boxes = effectBoxes;
	ii = 0;
	while(ii < numEffectBoxes && (boxes[ii] != box)) {
		ii++;
	}
	if (ii == numEffectBoxes) {
		printf("objFreeEffectBox: Not found\n");
	}
	else {
		for (; ii < numEffectBoxes-1; ii++) {
			boxes[ii] = boxes[ii + 1];
		}
		numEffectBoxes--;
	}
}

void objTargetFn_8002b6d8(ObjInstance *object, int fieldC, int maxDist,
int combatCamDist, u8 fieldF, u8 flags) {
	RamLockData *lock;

	if(object) {
		lock = object->lockdata;
		if(lock) {
			lock += object->lockCountE4;
			if(fieldC) lock->fieldC = fieldC >> 2;
			if(combatCamDist) lock->combatCamDist = combatCamDist >> 2;
			if(maxDist) lock->maxDist = maxDist >> 2;
			if(fieldF) lock->fieldF = fieldF;
			if(flags) lock->flags = flags;
		}
	}
}

//something like "copy latest ROM lockdata to RAM lockdata"
void objFn_800858B0(ObjInstance *object) {
	RomLockData *rom;
	RamLockData *ram;
	u8 iLock;

	if(object) {
		ram = object->lockdata;
		if(ram) {
			rom = object->objdata->lockdata + object->lockCountE4;
			ram += object->lockCountE4;
			ram->fieldC = rom->fieldC;
			ram->combatCamDist = rom->combatCamDist;
			ram->maxDist = rom->maxDist;
			ram->fieldF = rom->fieldF;
			ram->flags = rom->flags;
		}
	}
}

void objInstantiateCharacterAtObj(ObjInstance *object, ObjDef *odef) {
	objInstantiateCharacter(odef, 5,
		object->mapId, -1, object->heldBy);
}

ModelInstance* objGetModelInstance(ObjInstance *object) {
	ASSERTLINE(3178, object->modelno>=0 && object->modelno<object->objdata->noframes);
	return object->frames[object->modelno];
}

void vecToObjSpace(ObjInstance *object,Vec *vIn,Vec *vOut) {
	Mtx44 mtx;

	objModelMtxFn_800859e8(object, (Mtx*)&mtx);
	MTXMultVec(mtx, vIn, vOut);
	vOut->x = vOut->x + playerMapOffsetX;
	vOut->z = vOut->z + playerMapOffsetZ;
}

void objModelMtxFn_800859e8(ObjInstance *object, Mtx *modelMatrix) {
	int dummy;
	ASSERTLINE(0xc98, object);
	ASSERTLINE(0xc99, modelMatrix);
	if(!object->heldBy) {
		object->pos.pos.x -= playerMapOffsetX;
		object->pos.pos.z -= playerMapOffsetZ;
	}
	objModelMtxFn_8007b0c0(object, *modelMatrix);
	if(!object->heldBy) {
		object->pos.pos.x += playerMapOffsetX;
		object->pos.pos.z += playerMapOffsetZ;
	}
}

void objModelMtxFn_80085ab8(ObjInstance *object, Mtx *modelMatrix) {
	int dummy;
	Mtx44 mtx;
	ObjPos xf;

	ASSERTLINE(0xcc4, object);
	ASSERTLINE(0xcc5, modelMatrix);
	if(!object->heldBy) {
		object->pos.pos.x -= playerMapOffsetX;
		object->pos.pos.z -= playerMapOffsetZ;
	}
	xf.pos.x = -object->pos.pos.x;
	xf.pos.y = -object->pos.pos.y;
	xf.pos.z = -object->pos.pos.z;
	xf.rotation.x = -object->pos.rotation.x;
	xf.rotation.y = -object->pos.rotation.y;
	xf.rotation.z = -object->pos.rotation.z;
	xf.scale = 1.0;
	mtxRotateByVec3s(&mtx, &xf.rotation);
	mtx44Transpose(&mtx, (Mtx44 *)modelMatrix);
	if(!object->heldBy) {
		object->pos.pos.x += playerMapOffsetX;
		object->pos.pos.z += playerMapOffsetZ;
	}
}

void lightVecFn_80085c50(ObjInstance *obj, Vec *vIn, Vec *vOut) {
	Mtx44 mtx;
	objModelMtxFn_800859e8(obj,(Mtx*)&mtx);
	MTXMultVecSR(mtx,vIn,vOut);
}


void fn_80085d10(ObjInstance *object, int timerE6) {
	int dummy[4];
	Mtx mtx;

	if(object->objdata->unkb4 & ObjDataFlagsB4_CanFreeze) {
		if(object->impendingFreezeTimer < 10) {
			object->impendingFreezeTimer++;
			objSetFrozen(object, 30, 0xa0, 0xff, 0xff, 0);
		}
		if(object->impendingFreezeTimer == 10) {
			if(object->stateFlags & 2) LAB_800860ac(object);
			object->freezeTimer = timerE6;
			object->stateFlags |= OBJ_STATE_ISFROZEN;
			objModelMtxFn_800859e8(object, &mtx);
			freezeModelFn_8007f184(objGetModelInstance(object),
				&mtx, true);
		}
	}
}

u8 objIsFrozen(ObjInstance *object) {
	return object->stateFlags & OBJ_STATE_ISFROZEN;
}

void fn_80085dc8(ObjInstance *object) {
	object->freezeTimer -= timeDelta;
	if(object->freezeTimer <= 0) fn_80085DDC(object);
}

void fn_80085DDC(ObjInstance *object) {
	object->freezeTimer = 0;
	object->stateFlags &= ~OBJ_STATE_ISFROZEN;
	object->impendingFreezeTimer = 0;
	ModelInstance_freeField48(objGetModelInstance(object));
	return;
}

void objSetFrozen(ObjInstance *object, int freezeTimer,
u8 r, u8 g, u8 b, u8 a) {
	int ii;

	ASSERTLINE(0xd9f, !(object->stateFlags&OBJ_STATE_ISFROZEN));
	object->freezeTimer = (short)freezeTimer;
	object->stateFlags &= ~4;
	object->stateFlags |= 2;
	object->freezeColor.r = r;
	object->freezeColor.g = g;
	object->freezeColor.b = b;
	if(a) object->freezeColor.a = 180;
	else object->freezeColor.a = 0;
	for(ii = 0; ii < object->nChildren; ii++) {
		objSetFrozen(object->child[ii], freezeTimer, r, g, b, a);
	}
	return;
}
