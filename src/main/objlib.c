#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/gbi.h"
#include "cmath.h"
#include "macros.h"
#include "obj/ObjInstance.h"

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
	if(result >  0x8000) result += -0xffff;
	if(result < -0x8000) result +=  0xffff;
	return result;
}
