#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/gbi.h"
#include "cmath.h"
#include "macros.h"
#include "obj/ObjInstance.h"
#include "obj/Objects.h"

float sqrt(float v);

float objDistObj2Obj(ObjInstance *self, ObjInstance *other) {
	float dx, dy, dz;
	if(!(self && other)) {
		ASSERTLINE(43, 0);
		printf("objDistObj2Obj: check your pointers\n");
		return 0.0f;
	}
	dx = self->prevPos.x - other->prevPos.x;
	dy = self->prevPos.y - other->prevPos.y;
	dz = self->prevPos.z - other->prevPos.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

float objDistSqObj2Obj(ObjInstance *self, ObjInstance *other) {
	float dx, dy, dz;
	if(!(self && other)) {
		ASSERTLINE(57, 0);
		printf("objDistSqObj2Obj: check your pointers\n");
		return 0.0f;
	}
	dx = self->prevPos.x - other->prevPos.x;
	dy = self->prevPos.y - other->prevPos.y;
	dz = self->prevPos.z - other->prevPos.z;
	return dx * dx + dy * dy + dz * dz;
}

float objDistObj2ObjXZ(ObjInstance *self, ObjInstance *other) {
	float dx, dz;
	if(!(self && other)) {
		ASSERTLINE(73, 0);
		printf("objDistObj2ObjXZ: check your pointers\n");
		return 0.0f;
	}
	dx = self->prevPos.x - other->prevPos.x;
	dz = self->prevPos.z - other->prevPos.z;
	return sqrt(dx * dx + dz * dz);
}

float gobjDistSqObj2ObjXZ(ObjInstance *self, ObjInstance *other) {
	float dx, dz;
	if(!(self && other)) {
		ASSERTLINE(73, 0);
		printf("objDistObj2ObjXZ: check your pointers\n");
		return 0.0f;
	}
	dx = self->prevPos.x - other->prevPos.x;
	dz = self->prevPos.z - other->prevPos.z;
	return dx * dx + dz * dz;
}

float objDistSqObj2DefXZ(ObjInstance *self, ObjDef *odef) {
	float dx;
	float dz;

	if(!(self && odef)) {
		ASSERTLINE(117, 0);
		printf("objDistSqObj2DefXZ: check your pointers\n");
		if(self) ASSERTLINE(119, 0);
		printf("objDistSqObj2DefXZ: obj 1 type %d\n", self->objtype);
		if(odef) ASSERTLINE(121, 0);
		printf("objDistSqObj2DefXZ: def 2 type %d\n", odef->objType);
		return 0.0f;
	}
	dx = (self->prevPos).x - (odef->pos).x;
	dz = (self->prevPos).z - (odef->pos).z;
	return dx * dx + dz * dz;
}

float objDistSqObj2Def(ObjInstance *self, ObjDef *odef) {
	float dx;
	float dy;
	float dz;

	if(!(self && odef)) {
		ASSERTLINE(136, 0);
		printf("objDistSqObj2Def: check your pointers \n");
		return 0.0f;
	}
	dx = (self->prevPos).x - (odef->pos).x;
	dy = (self->prevPos).y - (odef->pos).y;
	dz = (self->prevPos).z - (odef->pos).z;
	return dx * dx + dy * dy + dz * dz;
}

float objDistObj2DefXZ(ObjInstance *self, ObjDef *odef) {
	float dx;
	float dy;

	if(!(self && odef)) {
		ASSERTLINE(150, 0);
		printf("objDistObj2DefXZ: check your pointers\n");
		return 0.0f;
	}
	dx = (self->prevPos).x - (odef->pos).x;
	dy = (self->prevPos).z - (odef->pos).z;
	return sqrt(dx * dx + dy * dy);
}

u16 getAngle(float x, float y);
s16 objDistFn_80091a84(ObjInstance *obj1, ObjInstance *obj2, float *outDist) {
	float x;
	float y;
	u16 angle;
	int result;

	ASSERTLINE(233, obj1 && obj2);
	x = (obj1->pos).pos.x - (obj2->pos).pos.x;
	y = (obj1->pos).pos.z - (obj2->pos).pos.z;
	angle = getAngle(x, y);
	if(outDist) *outDist = sqrt(x * x + y * y);
	result = (s16)angle - (obj1->pos.rotation.x & 0xffff);
	if(result > 0x8000) result += -0xffff;
	if(result < -0x8000) result += 0xffff;
	return result;
}

Mtx *objGetJointMtx(ObjInstance *obj, int placeNum) {
	ModelInstance *modelIns;
	int jointNum;

	ASSERTLINE(379, placeNum >= 0 && placeNum < obj->objdata->noplacements);
	modelIns = objGetModelInstance(obj);
	jointNum = obj->objdata->pAttachPoints[placeNum].bone[obj->modelno];
	ASSERTLINE(388, jointNum >= 0 && jointNum < modelIns->mod->numJoints);
	return modelInstGetjMtx(modelIns, jointNum);
}

void objGetAttachPoint(
    ObjInstance *obj, int idx, float *outX, float *outY, float *outZ) {
	*outX = obj->objdata->pAttachPoints[idx].pos.x;
	*outY = obj->objdata->pAttachPoints[idx].pos.y;
	*outZ = obj->objdata->pAttachPoints[idx].pos.z;
}

void objGetAttachPointWorldPos(ObjInstance *object, int placeNum, float *outX,
    float *outY, float *outZ, BOOL noRotate) {
	Mtx MStack_58;
	ModelInstance *modelInstance;
	Mtx *joint;
	int jointNum;
	Mtx MStack_88;
	ObjPos xf;
	S16Vec unused;
	S16Vec unused2;
	Mtx MStack_e0;

	(void)modelInstance; // for regswap
	(void)outX;
	//(void)outY;
	//(void)outZ;
	ASSERTLINE(291, placeNum >= 0 && placeNum < object->objdata->noplacements);
	modelInstance = objGetModelInstance(object);
	jointNum = object->objdata->pAttachPoints[placeNum].bone[object->modelno];
	ASSERTLINE(385, jointNum >= 0 && jointNum < modelInstance->mod->numJoints);
	if(jointNum < 0 || jointNum >= modelInstance->mod->numJoints) {
		*outX = (object->pos).pos.x;
		*outY = (object->pos).pos.y;
		*outZ = (object->pos).pos.z;
		return;
	}

	joint = modelInstGetjMtx(modelInstance, jointNum);
	if(noRotate) {
		xf.pos.x = *outX;
		xf.pos.y = *outY;
		xf.pos.z = *outZ;
		xf.rotation.x = 0;
		xf.rotation.y = 0;
		xf.rotation.z = 0;
	} else {
		xf.pos.x = object->objdata->pAttachPoints[placeNum].pos.x;
		xf.pos.y = object->objdata->pAttachPoints[placeNum].pos.y;
		xf.pos.z = object->objdata->pAttachPoints[placeNum].pos.z;
		xf.rotation.x = object->objdata->pAttachPoints[placeNum].rot.x;
		xf.rotation.y = object->objdata->pAttachPoints[placeNum].rot.y;
		xf.rotation.z = object->objdata->pAttachPoints[placeNum].rot.z;
	}
	mtxRotateByVec3s(MStack_e0, &xf.rotation);
	mtxTranspose(MStack_e0, MStack_58);
	MTXConcat(*joint, MStack_58, MStack_88);
	*outX = MStack_88[0][3];
	*outY = MStack_88[1][3];
	*outZ = MStack_88[2][3];
	if(!object->heldBy) {
		*outX = *outX + playerMapOffsetX;
		*outZ = *outZ + playerMapOffsetZ;
	}
}


/** Update the positions of the feet, starting at the given placement index */
void objUpdateFeet(ObjInstance *obj, int placeno, int nofeet, foot_vol_t *foot) {
	Mtx *mtx;
	int iBone;
	int iFoot;
	ModelInstance *frame;
	ObjData *data;

	ASSERTLINE(418, nofeet > 0 && nofeet < 16);
	ASSERTLINE(419, obj->objdata->noplacements > placeno+nofeet);

	data = obj->objdata;
	frame = obj->frames[obj->modelno];
	for(iFoot = 0; iFoot < nofeet; iFoot++) {
		iBone = data->pAttachPoints[placeno+iFoot].bone[obj->modelno];
		mtx = modelInstGetjMtx(frame, iBone);
		foot[iFoot].pos.x = (*mtx)[0][3];
		foot[iFoot].pos.y = (*mtx)[1][3];
		foot[iFoot].pos.z = (*mtx)[2][3];
		if(!obj->heldBy) {
			foot[iFoot].pos.x += playerMapOffsetX;
			foot[iFoot].pos.z += playerMapOffsetZ;
		}
	}
}
