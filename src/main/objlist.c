#include "macros.h"
#include "types.h"
#include "obj/Objects.h"


void objListInit(ObjListStruct *list, short size) { //800705d8
	list->obj = NULL;
	list->objSize = size;
}


void objListAdd(ObjListStruct *list, ObjInstance *obj1, ObjInstance *obj2) { //800705e8
	ObjInstance *prev;

	if(!list->obj) { //first slot is empty, put it there
		list->obj = obj2;
	} else {
		if(!obj1) { //insert at beginning
			prev = list->obj;
			list->obj = obj2;
		} else {
			prev = *(ObjInstance **)((int)obj1 + (int)list->objSize);
			*(ObjInstance **)((int)obj1 + (int)list->objSize) = obj2;
		}
		*(ObjInstance **)((int)obj2 + (int)list->objSize) = prev;
	}
	list->usage++;
}


void objListRemove(ObjListStruct *entry, ObjInstance *obj) { //80070648
	ObjInstance *pOVar1;
	ObjInstance *pOVar2;
	ObjInstance *pOVar3;

	if(entry->obj == obj) {
		entry->obj = *(ObjInstance **)((int)&(entry->obj->pos).rotation.x
		    + (int)entry->objSize);
		entry->usage = entry->usage + -1;
	} else {
		pOVar2 = entry->obj;
		for(pOVar3 = entry->obj; pOVar3 != NULL && (pOVar3 != obj);
		    pOVar3 = *(ObjInstance **)((int)&(pOVar3->pos).rotation.x
		        + (int)entry->objSize)) {
			pOVar2 = pOVar3;
		}
		if(pOVar3 != NULL) {
			pOVar1 = *(ObjInstance **)((int)&(pOVar3->pos).rotation.x
			    + (int)entry->objSize);
			if(pOVar3 == entry->obj) {
				entry->obj = pOVar1;
			} else {
				*(ObjInstance **)((int)&(pOVar2->pos).rotation.x
				    + (int)entry->objSize)
				    = pOVar1;
			}
			entry->usage = entry->usage + -1;
		}
	}
	return;
}
