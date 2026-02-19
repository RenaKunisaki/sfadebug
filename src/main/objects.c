#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/textures.h"
#include "macros.h"
#include "types.h"
#include "global.h"
#include "sys/n64.h"
#include "sys/pi.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/alloc.h"
#include "obj/Objects.h"
#include "obj/ObjInstance.h"
#include "obj/Camera.h"
#include "sys/dll.h"
#include "gfx/models/models.h"
#include "save/SaveGame.h"

extern u8 framesThisStep;

s16 *contNoBuf; //80398a44
ObjectList globalObjList;
ObjData **objDefNoList; //80398a60
u8 *objDefNoUsage; //80398a64
LoadedDLL *pDll_camcontrol;
LoadedDLL *pDll_dummy04;
ObjInstance *playerHeldBy; //80398a94
s8 objSeqEditFlag80399a74;
int bDisableModelRendering;

float sinf(float);
float cosf(float);
ObjInstance* objGetMain();

void clearPlayerObjIdxs();
void objInitLists(void);
void objInitHitLists();
void objFreeObject(ObjInstance *obj);
void objUpdateModels(void);
void objThaw(ObjInstance *object);
void objSetFreezing(ObjInstance *object);

//objlist.c
void objListInit(ObjectList *list, short stride);

static ObjDef_Player objdef_player = {
	0, //objType
	0, //allocatedSize
	0, //mapStates1
	0, //RomListObjLoadFlags
	0, //mapStates2
	0, //bound
	0, //cullDist
	0.0f, //pos.x
	0.0f, //pos.y
	0.0f, //pos.z
	0, //id
	0xff3c, 0x005c, 0x005a, 0x1e14
};

void Object_initObjects(void) {
	int iVar1;

	//alloc some lists
	Object_delList = mmAlloc(800, ALLOC_TAG_OBJECTS_COL,
		(volatile u32)"obj:dellist");
	objLockList = mmAlloc(0x60, ALLOC_TAG_OBJECTS_COL,
		(volatile u32)"obj:locklist");
	contNoBuf = (s16 *)mmAlloc(0x10, ALLOC_TAG_OBJECTS_COL,
		(volatile u32)"obj:contnobuf");

	//load objindex and count number of object types
	loadAsset_file(&Object_pObjIndex, FILE_OBJINDEX_bin);
	Object_maxObjType = (getLoadedDataFileSize(FILE_OBJINDEX_bin) >> 1) - 1;
	while(Object_pObjIndex[Object_maxObjType] == 0) Object_maxObjType--;

	//load objtab and find the max index
	loadAsset_file(&Object_pObjectsTab, FILE_OBJECTS_tab);
	Object_maxObjId = 0;
	while(Object_pObjectsTab[Object_maxObjId] != -1) Object_maxObjId++;
	Object_maxObjId--;

	//load object type index
	//XXX this should probably be FILE_OBJECTS_tab?
	//not sure if bug or we have wrong file IDs
	Object_objTypes = mmAlloc2(
	    Object_pObjectsTab[Object_maxObjId] + 0x10,
		ALLOC_TAG_OBJECTS_COL,
		"obj:objtypes");
	loadAsset_fileWithOffset(Object_objTypes, FILE_OBJECTS_bin);

	//alloc deflist and refcount
	objDefNoList = (ObjData **)mmAlloc(Object_maxObjId << 2, ALLOC_TAG_OBJECTS_COL,
		(volatile u32)"obj:deflist");
	objDefNoUsage = (u8 *)mmAlloc(Object_maxObjId, ALLOC_TAG_OBJECTS_COL,
		(volatile u32)"obj:defno");
	for(iVar1 = 0; iVar1 < (int)Object_maxObjId; iVar1++) { objDefNoUsage[iVar1] = 0; }

	//load tables and count entries
	loadAsset_file(&tables_bin, FILE_TABLES_bin);
	loadAsset_file(&tables_tab, FILE_TABLES_tab);
	nTablesTab = 0;
	while(tables_tab[nTablesTab] != -1) nTablesTab++;

	objLoadedObjs = (ObjInstance **)mmAlloc(MAX_LOADED_OBJECTS, ALLOC_TAG_OBJECTS_COL,
		(volatile u32)"obj:ObjList");
	allocHitLists();
	initLists();
	initCirclePols();
}

void objObjectsTick(void) {
	ObjInstance *player;
	ObjInstance *obj;
	short objListSize;

	objListSize = globalObjList.stride;
	LAB_800bac18();
	objUpdateModels();
	Object_updateHitModels(ObjListSize);

	//update high-priority objects
	for(obj = globalObjList.obj;
	obj && (obj->priority == 100);
	obj = *(ObjInstance **)((int)obj + objListSize)) {
		objUpdate(obj);
	}

	while(obj && obj->objdata->flags & ObjFileStructFlags44_IsWorldObj) {
		objUpdate(obj);
		obj->mtxIdx = Camera_addWorldMtx(&obj->pos);
		obj = *(ObjInstance **)((int)obj + objListSize);
	}
	updateHitModelObjs();

	while(obj) {
		if(!obj->hits) {
			objUpdate(obj);
		//@bug? probably should be !(obj->hits->flags5A & HitStateFlags5A_HasPolyHit)
		} else if((obj->hits->flags5A != HitStateFlags5A_HasPolyHit)
		|| !(obj->hits->flags & HitStateFlags58_HasPolyHit)) {
			objUpdate(obj);
		}
		obj = *(ObjInstance **)(obj + objListSize);
	}

	//update staff
	player = objGetMain();
	if(player && player->child[0]) {
		player->child[0]->heldBy = player->heldBy;
		objUpdate(player->child[0]);
	}

	//tick global objects
	Objects_buildHitList(ObjListSize);
	for(obj = globalObjList.obj; obj;
	obj = *(ObjInstance **)((int)obj + objListSize)) {
		objTick(obj);
	}

	//tick staff
	player = objGetMain();
	if(player && player->child[0]) {
		player->child[0]->heldBy = player->heldBy;
		objTick(player->child[0]);
	}

	pDll_waterfx->funcs->waterfx.func03(framesThisStep);
	if(!isModelAnimDisabled()) {
		pDll_projgfx->funcs->projgfx.func05(framesThisStep, 0);
		pDll_modgfx->funcs->ModGfx.func05(0, 0, 0);
		pDll_expgfx->funcs->expgfx.func05(0, framesThisStep, 0, 0);
	}

	LAB_8008d10c();
	pDll_anim->funcs->anim.func0C();
	pDll_anim->funcs->anim.func08();
	pDll_camcontrol->funcs->camcontrol.func04(framesThisStep);
	updateLightMtxs();
}


void objUpdateFn_80082238(void) {
	int nObjs;
	ObjInstance *obj;
	int iFlag;
	int flag;
	int iObj;

	objUpdateModels();
	pDll_anim->funcs->anim.func0C();
	nObjs = ObjListSize;
	for(iFlag = 1; iFlag < 3; iFlag++) {
		for(iObj = 0; iObj < nObjs; iObj++) {
			obj = objLoadedObjs[iObj];
			if(obj->objdata->flags & ObjFileStructFlags44_IsWorldObj) flag = 1;
			else flag = 2;
			if(!(flag & iFlag)) continue;

			if(obj->objId != 0x10) {
				STUBBED_OP(obj);
				goto lbl_94; //this can't be right.
			}
			else if(objSeqEditFlag80399a74) {
				objUpdate(obj);
			}
			else {
				goto lbl_ac;
				lbl_94:
				if(obj->objdata->flags & ObjFileStructFlags44_Unk0002_0000) {
					objUpdate(obj);
				}
			}
			lbl_ac:
			if(flag == 1) {
				obj->mtxIdx = (s8)Camera_addWorldMtx(&obj->pos);
			}
		}
	}
	obj = objGetMain();
	if(obj) {
		if(obj->pObj_0xc0 && checkSomeDebugFlags_8017c4f8() & 0xff) {
			objUpdate(obj);
		}
		if(obj->child[0]) { objUpdate(obj->child[0]); }
	}
	for(iObj = 0; iObj < (int)ObjListSize; iObj++) {
		obj = objLoadedObjs[iObj];
		objMultPosByMtx(obj,
		    &(obj->prevPos).x,
		    &(obj->prevPos).y,
		    &(obj->prevPos).z);
	}
	pDll_anim->funcs->anim.func08();
	if(bDisableModelRendering) {
		pDll_camcontrol->funcs->camcontrol.func04(framesThisStep);
	}
}


void objUpdateModels(void) {
	int iFrame;
	int iObj;
	int iChild;
	s8 *state;
	ObjInstance *obj;
	ObjInstance *child;
	ObjInstance *objC0;
	ModelInstance *model;

	for(iObj = 0; iObj < ObjListSize; iObj++) {
		obj = objLoadedObjs[iObj];
		if(obj && obj->objdata) {
			for(iFrame = 0; iFrame < obj->objdata->noframes; iFrame++) {
				model = obj->frames[iFrame];
				if(model) {
					model->flags &= ~ModelFlags18_MtxsLoaded;
					if(model->mod->bCopyVtxsToModelInst) {
						//TODO: fill in correct type for state
						objC0 = obj->pObj_0xc0;
						state = objC0 ? objC0->state : NULL;
						if(!objC0 || state && state[0x4e] == 0) {
							modelFn_80080c28(model, timeDelta);
						}
					}
				}
			}
			for(iChild = 0; iChild < obj->nChildren; iChild++) {
				child = obj->child[iChild];
				if(child && child->objdata) {
					for(iFrame = 0; iFrame < child->objdata->noframes; iFrame++) {
						model = child->frames[iFrame];
						if(model) {
							model->flags &= ~ModelFlags18_MtxsLoaded;
							if(model->mod->bCopyVtxsToModelInst) {
								//TODO: fill in correct type for state
								objC0 = child->pObj_0xc0;
								state = objC0 ? objC0->state : NULL;
								if(!objC0 || state && state[0x4e] == 0) {
									modelFn_80080c28(model, timeDelta);
								}
							}
						}
					}
				}
			}
		}
	}
}

void processObjDeleteList(void) {
	int iObj;

	for(iObj = 0; iObj < objDelListCount; iObj++) {
		worldProcessObjFreeList(Object_delList[iObj], 0);
		Object_delList[iObj] = NULL;
	}
	objDelListCount = 0;
}


void objFreeAll(void) {
	int iObj;

	processObjDeleteList();
	var_80396D08 = 0;
	for(iObj = ObjListSize-1; iObj >= 0; iObj--) {
		objFreeObject(objLoadedObjs[iObj]);
	}
	processObjDeleteList();
	var_80396D08 = 2;
	objDelListCount = 0;
	objLockListLen = 0;
	ObjListSize = 0;
	objListInit(&globalObjList, 0x38);
	objInitLists();
	pDll_camcontrol->funcs->camcontrol.setObjA0(NULL, 0);
	return;
}


void objInitLists(void) {
	//inlined in final
	objDelListCount = 0;
	objLockListLen = 0;
	playerHeldBy = NULL;
	ObjListSize = 0;
	objListInit(&globalObjList, 56);
	nVisibleObjs = 0;
	clearPlayerObjIdxs();
	objInitHitLists();
}

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
			if(objLoadedObjs[result]->objdata->flags & 1) {
				result++;
			} else
				stop = -1;
		}

		stop = 0;
		while(nObjs >= nObjsStart && !stop) {
			if(!(objLoadedObjs[nObjs]->objdata->flags & 1)) {
				nObjs--;
			} else
				stop = -1;
		}

		if(result < nObjs) { // swap
			obj = objLoadedObjs[result];
			objLoadedObjs[result] = objLoadedObjs[nObjs];
			objLoadedObjs[nObjs] = obj;
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
		obj = objLoadedObjs[ii];
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
			if(objLoadedObjs[ii + 1]->depth
			    < objLoadedObjs[ii]->depth) {
				obj = objLoadedObjs[ii];
				objLoadedObjs[ii] = objLoadedObjs[ii + 1];
				objLoadedObjs[ii + 1] = obj;
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
		obj1 = objLoadedObjs[ii];
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
	return objLoadedObjs;
}

/**
 * @brief Get the specified object from the global object list.
 *
 *  @param idx Object index.
 *  @return ObjInstance* The object, or NULL if idx is invalid.
 */
ObjInstance *Object_getObject(s32 idx) {
	if((idx < 0) || (idx >= ObjListSize)) { return NULL; }
	return objLoadedObjs[idx];
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
		obj = objLoadedObjs[ii];
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
	if((idx < 0) || (idx >= nTablesTab)) {
		//doesn't match if we include params
		STUBBED_PRINTF("objGetSequence objtype out of range %d/%d\n");
		return tables_bin;
	}
	return (s32 *)((u32)tables_bin + tables_tab[idx] * 4);
}

ObjInstance *objInstantiateCharacter(ObjDef *def, uint flags, int mapId,
int objNo, ObjInstance *heldBy) {
	ObjInstance *obj;

	obj = NULL;
	if(getPiLockedFlags() & 1) STUBBED_OP(def);

	loadAsset_Character(&obj, def, flags, mapId, objNo, heldBy, 0);
	if(obj) objSetup(obj, flags);

	if(getPiLockedFlags() & 1) STUBBED_OP(def);
	return obj;
}

ObjInstance *objSetupObjectActual(ObjDef *def, s32 flags, s32 mapId,
s32 romDefNo, struct ObjInstance *heldBy) {
	int nModels;
	u32 totalSize;
	ObjModelFlags modelFlags;
	ObjInstance objTmp;
	s32 dummy;
	ObjData *objData;
	ObjInstance *result;
	s32 realType;
	s32 oType;
	s32 iLock;
	s32 ii;
	s8 bModelFailed;
	void *next;

	STUBBED_PRINTF("objects/objects.c: OBJECT SETUP[%i]\n");
	//probably some debug stuff in here? these two messages are adjacent.
	STUBBED_PRINTF("objects/objects.c: OBJECT SETUP END[%i]\n");

	//look up the real object type
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

	//load the object data
	memclr(&objTmp, sizeof(ObjInstance));
	result = &objTmp;
	objData = Object_objLoadData(realType);
	result->objdata = objData;
	if((!objData) || ((s32)objData == -1)) {
		debugPrint("Warning: Unknown object type '%d/%d romdefno %d', "
			"using DummyObject (128)\n", realType, def->objType, result->objtype);
		if((s32)objData == -1) {
			//@bug missing newline in message
			debugPrint("Warning: Object romdefno is -1, check the object is in "
			    "objects.spec");
		}
		return NULL;
	}

	//set up the resulting object instance
	result->objId = objData->objId;
	result->pos.scale = objData->scale;
	if(result->pos.scale == 0.0f) result->pos.scale = 1.0f;
	result->pos.flags = 2;
	if(objData->flags & 0x80) result->pos.flags |= 0x80;
	if(objData->flags & 0x40000) result->flags_0xb0 |= ObjInstance_FlagsB0_LockAnimsAndControls;
	if(flags & 4) result->pos.flags |= ObjInstance_Flags06_DontSave;

	result->pos.pos.x = def->pos.x;
	result->pos.pos.y = def->pos.y;
	result->pos.pos.z = def->pos.z;
	result->realType = realType;
	result->def = def;
	result->objtype = oType;
	result->romdefno = romDefNo;
	result->mapId = mapId;
	result->curAnimId = -1;
	result->curSeqSlot = -1;
	result->newOpacity = 0xFF;
	result->msgQueue = NULL;
	result->bound = def->bound * 8;
	result->cullDist = def->cullDist * 8;

	//load the object's DLL
	result->dll = NULL;
	if(objData->dll_id) {
		// probably wrong return type here
		result->dll = (struct LoadedDLL *)DLL_setup(
			(u32)objData->dll_id, 6U, 1);
		if(!result->dll) printf("OBJECTS: warning DLL load failed\n");
	}
	if(result->objtype == ObjDefNo_SB_ShipHead) {
		//STUBBED_OP(result);
		STUBBED_PRINTF("GALLEON HEAD\n");
	}

	//get model flags
	modelFlags = Object_getModelFlags(result);
	if(objData->flags & ObjFileStructFlags44_ModelRelated) {
		modelFlags &= ~ObjModelFlags_Unk0000_0001;
	}
	else modelFlags |= ObjModelFlags_Unk0000_0001;

	if(objData->shadowType != ObjShadowType_None) {
		modelFlags |= ObjModelFlags_HasShadow;
	}
	else modelFlags &= ~ObjModelFlags_HasShadow;

	if(objData->shadowType == ObjShadowType_Textured) {
		modelFlags |= ObjModelFlags_TexturedShadow;
	}

	//allocate memory for object
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

	//load the models
	ii = 0;
	bModelFailed = false;
	if(!(modelFlags & ObjModelFlags_objFileHasModels)) { //related to debug models
		if(modelFlags & ObjModelFlags_OnlyLoadOneModel) {
			ii = (modelFlags >> 11) & 0xF;
			if(ii < nModels) {
				result->frames[ii] = loadModelInstance(
				    -objData->pModelList[ii], modelFlags);
				if(!(s32)result->frames[ii]) bModelFailed = true;
				else {
					ModelInstance_loadShaders(
					    result->frames[ii], result);
					modelInitSkeleton(result->pos.scale,
						result->frames[ii]);
					if(result->objdata->flags & 0x800) {
						Modelnstance_setTexFuncPtr(result->frames[ii],
						    modelTexFuncPtr_800c5b80);
					}
				}
			}
		} else {
			while(ii < nModels) {
				result->frames[ii] = loadModelInstance(
				    -(s32)objData->pModelList[ii], modelFlags);
				if(!(s32)result->frames[ii]) bModelFailed = true;
				else {
					ModelInstance_loadShaders(result->frames[ii], result);
					modelInitSkeleton(result->pos.scale, result->frames[ii]);
					if(result->objdata->flags & 0x800) {
						Modelnstance_setTexFuncPtr(
						    result->frames[ii], modelTexFuncPtr_800c5b80);
					}
				}
				ii++;
			}
		}
	}
	if(bModelFailed) {
		Object_freeModels(result, nModels, oType);
		objFreeObjdef(realType);
		return NULL;
	}

	//set up the object data following the object itself
	next = &result->frames[objData->noframes];
	next = Object_objInitState(result, next);
	if(modelFlags & ObjModelFlags_HasEvents) {
		next = Object_objSetupEvents((s32)result->objtype,
			result, next);
	}
	if(modelFlags & ObjModelFlags_HasModels) {
		next = Object_objSetupModels(result->objtype,
			result->frames[0], result, next);
	}
	if((modelFlags & ObjModelFlags_HasShadow)
	&& ((s16)objData->shadowType != ObjShadowType_None)) {
		next = Object_objLoadShadow(result, next, 0);
	}
	result->cullDistance = result->pos.scale * objGetDefaultCullDistance(result);
	if((u8)objData->maybeNumHits != 0) {
		next = (void *)Object_objSetupHitState(result, next);
		if((u8)objData->flags93 & 8) {
			next = (void *)Object_objSetupField58(result, next);
		}
	}
	if((u8)objData->nJoints != 0) {
		next = mmAlign4(next);
		result->joints = next;
		next = (void *)((s32)next + ((u8)objData->nJoints * sizeof(Joint)));
	}
	if((u8)objData->nTextures != 0) {
		next = mmAlign4(next);
		result->pTextures = next;
		next = (void *)((s32)next + ((u8)objData->nTextures * 0x10));
	}
	if((u8)objData->numLockData != 0) {
		next = mmAlign4(next);
		result->romLockdata = next;
		next = (void *)((s32)next
		    + ((u8)objData->numLockData * sizeof(RomLockData)));
	}
	if(((u8)objData->maybeNumHits != 0) && ((u8)objData->bDisableHits != 0)) {
		next = mmAlign4(next);
		next = Object_objSetupHits((s32)result->objtype,
		    (ModelInstance *)result->frames[0],
		    result->hits,
		    next,
		    result);
	}
	if(objData->numLockData != 0) {
		next = mmAlign4(next);
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
	Object_streamFn_8018fa50(result, (s32)result->objtype);
	return result;
}

void objSetup(ObjInstance *object, uint flags) {
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
	if(flags & ObjSetupFlags_Global) { //add to global obj list
		object->flags_0xb0 |= ObjInstance_FlagsB0_IsInGlobalObjList;
		objLoadedObjs[ObjListSize++] = object;
		ASSERTLINE(1202, ObjListSize<MAX_OBJECTS);
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
	switch(object->objtype) {
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
		size = (int)mmAlign4((void *)size);
		size += 8;
		size = (uint)mmAlign8((void*)size);
		size += 0x50;
	}
	if(flags & 0x100) {
		size = (int)mmAlign4((void *)size);
		size += 8;
		size = (uint)mmAlign8((void*)size);
		size += 0x400;
	}
	if(flags & 2 && objData->shadowType != ObjShadowType_None) {
		size = (int)mmAlign4((void *)size);
		size += sizeof(Shadow);
	}
	if(objData->maybeNumHits) {
		size = (uint)mmAlign4((void *)size);
		size += 0xa4;
		if((objData->flags93 & 8) != 0) { size += 0x110; }
	}
	if(objData->nJoints) {
		size = (int)mmAlign4((void *)size);
		size += (uint)objData->nJoints * sizeof(Joint);
	}
	if(objData->nTextures) {
		size = (int)mmAlign4((void *)size);
		size += (uint)objData->nTextures * 0x10;
	}
	if(objData->numLockData) {
		size = (int)mmAlign4((void *)size);
		size += (uint)objData->numLockData * sizeof(RomLockData);
	}
	if(objData->maybeNumHits && objData->bDisableHits) {
		size = (uint)mmAlign8((void*)size);
		size += 300;
	}
	if(objData->numLockData) {
		size = (int)mmAlign4((void *)size);
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

		iParent = model->joints[iJoint].idx[0];
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

float objGetDefaultCullDistance(ObjInstance *object) {
	ModelInstance *mInst;
	float result;
	s32 ii;

	result = 10.0f;
	for(ii = 0; ii < object->objdata->noframes; ii++) {
		if((int)object->frames[ii]) {
			mInst = object->frames[ii];
			if(modelGetCullDistance(mInst->mod) > result) {
				result = modelGetCullDistance(mInst->mod);
			}
		}
	}
	if(result < object->objdata->minCullDistance) {
		result = 16.0f * object->objdata->minCullDistance;
	}
	return result;
}

void Object_freeModels(ObjInstance *object, int count, int oType) {
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
        objListRemove(&globalObjList, object);
    }
}

void objAddToGlobalObjList(ObjInstance *object) {
	ObjInstance *newNext; //r30
	ObjInstance *prev; //r31
	volatile s16 stride; //spC
	ObjInstance *next; //sp10

	if(!(object->flags_0xb0 & ObjInstance_FlagsB0_IsInGlobalObjList)) return;

	stride = globalObjList.stride;
	prev = NULL;
	for(next = globalObjList.obj; (int)next && object->priority < prev->priority;
	next = *(ObjInstance **)((int)prev + stride)) {
		prev = next;
	}
	objListAdd(&globalObjList, prev, object);
}

void objFreeObject(ObjInstance *obj) {
	int ii, jj;

	ASSERTLINE(1467, obj);
	//weird this line is here...
	STUBBED_PRINTF("Tried to free non-existent object\n");
	if(obj->flags_0xb0 & ObjInstance_FlagsB0_IsFreed) return;
	objStopSounds(obj, 0x7f, __FILE__, 1474);

	if(obj->flags_0xb0 & ObjInstance_FlagsB0_IsInGlobalObjList) {
		// find this object's index in the global object list
		for(ii = 0; ii < ObjListSize; ii++) {
			if(objLoadedObjs[ii] == obj) break;
		}
		if(ii < ObjListSize) {
			// shift all following entries down
			ObjListSize--;
			for(jj = ii; jj < ObjListSize; jj++) {
				objLoadedObjs[jj] = objLoadedObjs[jj + 1];
			}
		}
		objFreeFn_80083b54(obj);
		clearNVisibleObjs();
	}
	obj->flags_0xb0 |= ObjInstance_FlagsB0_IsFreed;

	LAB_8018fb20(obj, obj->objtype);
	if(obj->lockedFreeTick) {
		// add to the lock list if not already present
		for(ii = 0; ii < ObjListSize; ii++) {
			if(objLoadedObjs[ii] == obj) break;
		}
		if(ii == objLockListLen) {
			objLockList[objLockListLen] = obj;
			objLockListLen++;
		} else {
			printf("objFreeTick %08x locked %d,already on list\n",
			    obj,
			    obj->lockedFreeTick);
		}
	} else if(var_80396D08 == 2) {
		// add to delete list if not already present
		ii = objDelListCount;
		if(objDelListCount != 0) {
			for(ii = 0; ii < ObjListSize; ii++) {
				if(objLoadedObjs[ii] == obj) break;
			}
		}
		if(ii == objDelListCount) {
			Object_delList[objDelListCount] = obj;
			objDelListCount += 1;
			if(objDelListCount == 200) {
				printf("objFreeObject: delete list size overrun\n");
				objDelListCount -= 1;
			}
		}
	}
	// else delete it now
	else
		Object_worldProcessObjFreeList(obj, var_80396D08 == 0);
}

void objSetupDll(ObjInstance *object,ObjDef *def,void *param) {
    ObjDefEnum sVar1;

	//not sure where these go
	STUBBED_PRINTF("objects.c: CONTROL[%d]\n");
	STUBBED_PRINTF("objects.c: CONTROL END[%d]\n");

    switch(object->objtype) {
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
            else piRomLoadAddr(FILE_OBJEVENT_bin,
                event->data,offset,event->size);
            return;
        }
    }
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
			if(object->stateFlags & OBJ_STATE_ISFROZEN) objUpdateWhileFrozen(object);
			if(object->stateFlags & OBJ_STATE_FREEZING) objFlashWhileFreezing(object);
		}
	}
	if(getPiLockedFlags() & 2) STUBBED_OP(object);
	if(!(object->flags_0xb0 & ObjInstance_FlagsB0_DontUpdate)) {
		switch(object->objtype) {
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
				else piRomLoadAddr(
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
		piRomLoadAddr(FILE_OBJECTS_bin, objData, offset, size);
		if(objData->pEvent) OFFSET_TO_PTR(s16, objData, pEvent);
		if(objData->pHits) OFFSET_TO_PTR(UNKTYPE, objData, pHits);
		if(objData->pWeaponDa) OFFSET_TO_PTR(ObjWeaponData, objData, pWeaponDa);
		OFFSET_TO_PTR(u32, objData, pModelList);
		OFFSET_TO_PTR(Texture, objData, textures.ptr);
		OFFSET_TO_PTR(u8, objData, joints);
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
        switch(object->objtype) {
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

    state = mmAlign4(state);
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

ObjModelFlags Object_getModelFlags(ObjInstance *object) {
    switch(object->objtype) {
        case ObjDefNo_Krystal:
        case ObjDefNo_Sabre:
            return 0x1cb;

        default:
            if(object->dll && ((LoadedDLL*)object->dll)->funcs->Object.getModelFlags) {
				return (*((LoadedDLL*)object->dll)->funcs->Object.getModelFlags)(object);
			} else return 0;
    }
}

void* Object_objSetupEvents(int romdefno, ObjInstance *object, void *ptr) {
    ptr = (ObjEventData *)mmAlign4(ptr);
    object->pEventName = ptr;

    ptr = (void*)((uint)ptr + sizeof(ObjEventData));
    ptr = (void *)mmAlign8(ptr);
    object->pEventName->data = (ObjEventData2*)ptr;

    ptr = (void *)((uint)ptr + sizeof(ObjEventData2));
    objLoadEventData(object,romdefno,object->pEventName,0,true);
    return ptr;
}

void* Object_objSetupModels(int romdefno, ModelInstance *modelnstance,
ObjInstance *object,void *ptr) {
    if(!modelnstance) return ptr;

    ptr = mmAlign4(ptr);
    object->models = ptr;
    ptr = (void*)((uint)ptr + 8);
    ptr = (void*)mmAlign8(ptr);
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

ModLine* loadModLine(int lineNo, s16 *outCount) {
	s16 size16;
    ModLine *dest;
    uint offset;
    uint *tempIdx;
    uint size;
    int fileSize;

    dest = NULL;
    fileSize = (getLoadedDataFileSize(FILE_MODLINES_tab) - 4) >> 2;
    if(lineNo > fileSize) return NULL;

    tempIdx = mmAlloc(0x10,ALLOC_TAG_TEST_COL,
		(volatile u32)"obj:tempindex");
    offset = lineNo * 4;
    piRomLoadAddr(FILE_MODLINES_tab,
		tempIdx, offset, 8);

    offset = tempIdx[0];
    size = tempIdx[1] - tempIdx[0];
    if((int)size > 0) {
        dest = mmAlloc(size, ALLOC_TAG_TRACK_COL,
			(volatile u32)"obj:templine");
        piRomLoadAddr(FILE_MODLINES_bin,
			dest, offset, size);
    }
    mmFree(tempIdx);
	size16 = size / 0x14;
    *outCount = size16;
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

int Object_objGetControlNo(int objType) {
	u8 wat[180];
	uint ii;
	uint offset;
	int count;
	int index;

	if(objType > Object_maxObjType) {
		printf("objGetControlNo objtype out of range %d/%d\n",
			objType, Object_maxObjType);
		return 0;
	}
	index = Object_pObjIndex[objType];
	if(index == -1) return 0;

	//likely an optimized-out clear of some struct
	//that's never referenced
	count = 0;
	for(ii=&wat[90] - &wat[0]; (ii & 1) != 0; count++) {
		ii--;
	}

	offset = Object_pObjectsTab[index] + ii;
	loadAsset_fileWithOffsetLength(
		contNoBuf, FILE_OBJECTS_bin,
		offset, 8);
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

const char* Object_objTypeName(int objType) { //not present in binary
	ObjData *data;

	if(objType > Object_maxObjType) {
		printf("objTypeName objtype out of range %d/%d\n",
			objType, Object_maxObjType);
		return 0;
	}
	objType = Object_pObjIndex[objType];
	if(objType >= Object_maxObjId) return 0;

	data = (ObjData*)((u32)Object_objTypes + Object_pObjectsTab[objType]);
  	return data->name;
}

int Object_objGetTypeNo(int objType) { //not present in binary
	ObjData *data;

	if(objType > Object_maxObjType) {
		printf("objGetTypeNo objtype out of range %d/%d\n",
			objType, Object_maxObjType);
		return 0;
	}
	objType = Object_pObjIndex[objType];
	if(objType >= Object_maxObjId) return 0;

	data = (ObjData*)((u32)Object_objTypes + Object_pObjectsTab[objType]);
  	return 0; //presumably data->something, but idk which
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

	switch(obj->objtype) {
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
				that = objLoadedObjs[jj];
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
			that = objLoadedObjs[jj];
			if(PTR_EQ(that->pObj_0xc0, obj)) {
				that->pObj_0xc0 = NULL;
			}
		}
	}
	for(kk = 0; kk < ObjListSize; kk++) {
		that = objLoadedObjs[kk];
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
	if(obj->stateFlags & 1) objThaw(obj);
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
	volatile int playerNo; //sp0C
	volatile int mapType; //sp08

	mapType = getCurMapType();
	if(mapType == 2 || mapType == 3) {
		STUBBED_PRINTF("=======  OBJFREEALL \n"); //becomes OSReport in final
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
			if(objLoadedObjs[ii] != heldBy) {
				objLoadedObjs[ii]->heldBy = heldBy;
			}
		}
		//game is using r0 instead of r3 as temporary here
		heldBy->mtxIdx = Camera_addWorldMtx(&heldBy->pos);
	}
	playerNo = 1;
	charPos = (CharPos *)pDll_gplay->funcs->gplay.getCurCharPos();
	x = charPos->pos.x;
	y = charPos->pos.y;
	z = charPos->pos.z;
	charObj = NULL;
	if(playerNo > -1 && mapType != 4) {
		//doesn't match with args
		//becomes OSReport in final
		STUBBED_PRINTF("\n\n\n\n\n\n\n    LOADING CHARACTER     maptype %d  playerno %d\n\n\n\n\n\n\n");
		memclr(&chrDef, sizeof(ObjDef));
		chrDef.id = -1;
		chrDef.mapStates1 = 0;
		chrDef.loadFlags = RomListLoadFlag_isLevelObject;
		chrDef.mapStates2 = 4;
		chrDef.bound = 0xff;
		chrDef.cullDist = 100;
		chrDef.objType = playerObjIds[playerNo];
		chrDef.allocatedSize = sizeof(ObjDef);
		chrDef.pos.x = x;
		chrDef.pos.y = y;
		chrDef.pos.z = z;
		charObj = objInstantiateCharacter(&chrDef,
			ObjSpawnFlags_KeepLoaded, -1, -1,
			heldBy);
	}
	objdef_player.odef.pos.x = sinf(((charPos->rotX << 8) * PI) / 32767.0f) * 60.0f + x;
	objdef_player.odef.pos.y = y + 40.0f;
	objdef_player.odef.pos.z = cosf(((charPos->rotX << 8) * PI) / 32767.0f) * 60.0f + z;
	pDll_camcontrol->funcs->camcontrol.func03(charObj,
		objdef_player.odef.pos.x,
		objdef_player.odef.pos.y,
		objdef_player.odef.pos.z);
	pDll_camcontrol->funcs->camcontrol.setupCamControl1(0x50, 0,
		0, 0x20, &objdef_player.odef, 0, 0xff);
	pDll_camcontrol->funcs->camcontrol.func04(1);
	pDll_dummy04->funcs->Dummy04.func06_nop(charObj);
	playerHeldBy = heldBy;
	playerUpdateFn_800ae404();
}

//unsure what object this is
typedef struct {
	ObjDef def;
	u8 param0, param1;
	//probably more... no more than 2 additional bytes, both zeros
} ObjDef_802ed010_t;

void fn_80085448(ObjInstance *object, int objType) { //reloc
	static ObjDef_802ed010_t ObjDef_802ed010 = {
		-1, //objtype
		7, //allocatedSize
		0, //mapStates1
		1, //loadFlags
		4, //mapStates2
		0xff, //bound
		0xff, //cullDist
		0.0f, //pos.x
		0.0f, //pos.y
		0.0f, //pos.z
		-1, //id
		0, 0,
	};
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
			STUBBED_PRINTF("locknum out of range\n");
			STUBBED_PRINTF("infonum out of range\n");
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

void objModelMtxFn_800859e8(ObjInstance *object, Mtx *modelMatrix) {
	int dummy;
	ASSERTLINE(0xc98, object);
	//this line doesn't belong here, but this message does
	//belong between these two assert messages
	STUBBED_PRINTF("Failed assertion instanceNum>=0 && instanceNum<object->objdata->noframes");
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

void vecToObjSpace(ObjInstance *object,Vec *vIn,Vec *vOut) {
	Mtx44 mtx;

	objModelMtxFn_800859e8(object, (Mtx*)&mtx);
	MTXMultVec(mtx, vIn, vOut);
	vOut->x = vOut->x + playerMapOffsetX;
	vOut->z = vOut->z + playerMapOffsetZ;
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
			objHandleIceBlast(object, 30, 0xa0, 0xff, 0xff, 0);
		}
		if(object->impendingFreezeTimer == 10) {
			if(object->stateFlags & 2) LAB_800860ac(object);
			object->thawTimer = timerE6;
			object->stateFlags |= OBJ_STATE_ISFROZEN;
			objModelMtxFn_800859e8(object, &mtx);
			modelApplyFrozenEffect(objGetModelInstance(object),
				&mtx, true);
		}
	}
}

u8 objIsFrozen(ObjInstance *object) {
	return object->stateFlags & OBJ_STATE_ISFROZEN;
}

void objUpdateWhileFrozen(ObjInstance *object) {
	//works much differently in final
	object->thawTimer -= timeDelta;
	if(object->thawTimer <= 0) { objThaw(object); }
}

void objThaw(ObjInstance *object) {
	object->thawTimer = 0;
	object->stateFlags &= ~OBJ_STATE_ISFROZEN;
	object->impendingFreezeTimer = 0;
	ModelInstance_freeFreezeModel(objGetModelInstance(object));
}

void objHandleIceBlast(ObjInstance *object, int thawTimer,
u8 r, u8 g, u8 b, u8 a) {
	//called when hit by ice blast
	int ii;

	ASSERTLINE(0xd9f, !(object->stateFlags&OBJ_STATE_ISFROZEN));
	object->thawTimer = (short)thawTimer;
	object->stateFlags &= ~OBJ_STATE_FLASHING;
	object->stateFlags |= OBJ_STATE_FREEZING;
	object->freezeColor.r = r;
	object->freezeColor.g = g;
	object->freezeColor.b = b;
	if(a) object->freezeColor.a = 180;
	else object->freezeColor.a = 0;
	for(ii = 0; ii < object->nChildren; ii++) {
		objHandleIceBlast(object->child[ii], thawTimer, r, g, b, a);
	}
}

void objFlashWhileFreezing(ObjInstance *object) {
	//while object is being hit by ice blast but hasn't yet frozen,
	//make it flash between normal and frozen colors.
	int iChild;
	float phase;

	if(object->stateFlags & OBJ_STATE_FLASHING) {
		phase = timeDelta * 12.0f + (float)(object->freezeColor).a;
	} else {
		phase = -(timeDelta * 12.0f - (float)(object->freezeColor).a);
	}
	if(phase < 0.0f) {
		phase = -phase;
		object->stateFlags = object->stateFlags ^ OBJ_STATE_FLASHING;
	} else if(phase > 180.0f) {
		phase = 180.0f - (phase - 180.0f);
		object->stateFlags = object->stateFlags ^ OBJ_STATE_FLASHING;
	}
	(object->freezeColor).a = phase;
	object->thawTimer -= timeDelta;
	if((object->thawTimer <= 0) && !object->parent) {
		objSetFreezing(object);
	}
	for(iChild = 0; iChild < object->nChildren; iChild++) {
		objFlashWhileFreezing(object->child[iChild]);
	}
}

void objSetFreezing(ObjInstance *object) {
	//apply the "hit by ice but not yet frozen" effect
	int iChild;

	object->thawTimer = 0;
	object->stateFlags &= ~(OBJ_STATE_FREEZING | OBJ_STATE_FLASHING);
	for(iChild = 0; iChild < object->nChildren; iChild++) {
		objSetFreezing(object->child[iChild]);
	}
}
