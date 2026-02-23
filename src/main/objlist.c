#include "macros.h"
#include "types.h"
#include "obj/Objects.h"


/**
 * @brief Initialize an object list.
 *
 *  @param list The list.
 *  @param stride Size of each element (must be >= sizeof(ObjInstance*)).
 */
void objListInit(ObjectList *list, short stride) { //800705d8
	list->obj = NULL;
	list->stride = stride;
    //@bug? list->count is not initialized.
    //this is true in the final too, maybe it's fine?
}


/**
 * @brief Add an object to an object list.
 *
 *  @param list The list.
 *  @param addAfter Add the object after this one. If NULL, add it to
 *    the beginning of the list. (Used for priority sorting.) This
 *    object must be in the list!
 *  @param obj The object to add.
 */
void objListAdd(ObjectList *list, ObjInstance *addAfter, ObjInstance *obj) { //800705e8
	ObjInstance *prev;

	if(!(int)list->obj) { //first slot is empty, put it there
		list->obj = obj;
	} else {
		if(!(int)addAfter) { //insert at beginning
			prev = list->obj;
			list->obj = obj;
		} else {
			prev = *(ObjInstance **)((int)addAfter + list->stride);
			*(ObjInstance **)((int)addAfter + list->stride) = obj;
		}
		*(ObjInstance **)((int)obj + list->stride) = prev;
	}
	list->count++;
}

/**
 * @brief Remove an object from an object list.
 *
 *  @param list The list.
 *  @param obj The object.
 *  @note Does nothing if the object isn't in the list.
 */
void objListRemove(ObjectList *list, ObjInstance *obj) { //80070648
	ObjInstance *newNext;
	int iter;
	int iter2;

	if((int)list->obj == (int)obj) { //remove first element
		list->obj = *(ObjInstance **)((int)list->obj + list->stride);
		list->count--;
	} else { //find this element in the list
		iter2 = (int)list->obj;
		iter = iter2;
        STUBBED_OP(iter);
        while(iter2 && iter2 != (int)obj) {
            iter = iter2;
            iter2 = *(int*)(iter2 + list->stride);
		}
		if(iter2) { //remove it
			newNext = *(ObjInstance **)(iter2 + list->stride);
			if(iter2 == (int)list->obj) {
				list->obj = newNext;
			} else {
				*(ObjInstance **)(iter + list->stride) = newNext;
			}
			list->count--;
		}
	}
}
