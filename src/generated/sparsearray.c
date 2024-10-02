
/* Library Function - Single Match
    sparseArrayCreate
   
   Library: KioskDefault 0 0 */

SparseArray * SparseArray_create(int capacity,int itemSize) { //800706E8
  SparseArray *sparseArray;
  
  sparseArray = (SparseArray *)
                mmAlloc(capacity * (itemSize + 2) + 0x10,TEST_COL,"dtype:sparseArray");
  if (sparseArray == (SparseArray *)0x0) {
                    
    OSPanic("sparsearray.c",0x2b,"Failed assertion sparseArray");
  }
  sparseArray->items = (SparseArrayItem *)((int)&sparseArray[1].items + 2);
  sparseArray->keySize = (byte)itemSize;
  sparseArray->elemSize = (byte)(itemSize + 2U >> 1);
  sparseArray->lastElem = &sparseArray->items->key;
  sparseArray->highPtr = &sparseArray->items[capacity * (uint)sparseArray->elemSize].key;
  memset_(sparseArray->items,-1,capacity * (uint)sparseArray->elemSize * 2);
  return sparseArray;
}


/* Library Function - Single Match
    spareArraySet
   
   Library: KioskDefault 0 0 */

void SpareArray_set(SparseArray *sparseArray,short key,void *newElement) { //800707AC
  SparseArrayItem *elem;
  
  if (sparseArray == (SparseArray *)0x0) {
                    
    OSPanic("sparsearray.c",0x5f,"Failed assertion sparseArray");
  }
  if (newElement == (void *)0x0) {
                    
    OSPanic("sparsearray.c",0x60,"Failed assertion newElement");
  }
  for (elem = sparseArray->items;
      (elem < (SparseArrayItem *)sparseArray->lastElem && (elem->key != -1));
      elem = elem + sparseArray->elemSize) {
  }
  if ((SparseArrayItem *)sparseArray->highPtr <= elem) {
                    
    OSPanic("sparsearray.c",0x6e,s_Failed_assertion_keyPtr<sparseAr_802e8ad0);
  }
  elem->key = key;
  memcpy(elem + 1,newElement,(uint)sparseArray->keySize);
  if (elem == (SparseArrayItem *)sparseArray->lastElem) {
    sparseArray->lastElem = sparseArray->lastElem + sparseArray->elemSize;
  }
  return;
}


/* Library Function - Single Match
    sparseArrayRemove
   
   Library: KioskDefault 0 0 */

void sparseArrayRemove(short **param1,int param2) { //800708A0
  short *psVar1;
  
  if (param1 == (short **)0x0) {
                    
    OSPanic("sparsearray.c",0x90,"Failed assertion sparseArray");
  }
  psVar1 = *param1;
  do {
    if (param1[1] <= psVar1) {
LAB_80070918:
      if (psVar1 == param1[1]) {
                    
        OSPanic("sparsearray.c",0x9d,"Failed assertion keyPtr!=sparseArray->highPtr");
      }
      while ((*param1 < param1[1] && (param1[1][-1] == -1))) {
        param1[1] = param1[1] + -(uint)*(byte *)((int)param1 + 0xd);
      }
      return;
    }
    if (*psVar1 == param2) {
      *psVar1 = -1;
      goto LAB_80070918;
    }
    psVar1 = psVar1 + *(byte *)((int)param1 + 0xd);
  } while( true );
}


/* Library Function - Single Match
    sparseArrayGet
   
   Library: KioskDefault 0 0 */

BOOL SparseArray_get(SparseArray *sparseArray,int id,void *element) { //80070984
  SparseArrayItem *val;
  
  if (sparseArray == (SparseArray *)0x0) {
                    
    OSPanic("sparsearray.c",0xbc,"Failed assertion sparseArray");
  }
  if (element != (void *)0x0) {
    val = sparseArray->items;
    while( true ) {
      if ((SparseArrayItem *)sparseArray->lastElem <= val) {
        return FALSE;
      }
      if (val->key == id) break;
      val = val + sparseArray->elemSize;
    }
    memcpy(element,val + 1,(uint)sparseArray->keySize);
    return TRUE;
  }
                    
  OSPanic("sparsearray.c",0xbd,"Failed assertion element");
}


/* Library Function - Single Match
    sparseArrayFindElem
   
   Library: KioskDefault 0 0 */

BOOL sparseArrayFindElem(SparseArray *sparseArray,void *element,int *key) { //80070A40
  int iVar1;
  SparseArrayItem *pSVar2;
  
  if (sparseArray == (SparseArray *)0x0) {
                    
    OSPanic("sparsearray.c",0xe2,"Failed assertion sparseArray");
  }
  if (element != (void *)0x0) {
    if (key == (int *)0x0) {
                    
      OSPanic("sparsearray.c",0xe4,"Failed assertion key");
    }
    pSVar2 = sparseArray->items;
    while( true ) {
      if ((SparseArrayItem *)sparseArray->lastElem <= pSVar2) {
        return FALSE;
      }
      iVar1 = memcmp(pSVar2 + 1,element,(uint)sparseArray->keySize);
      if (iVar1 == 0) break;
      pSVar2 = pSVar2 + sparseArray->elemSize;
    }
    *key = (int)pSVar2->key;
    return TRUE;
  }
                    
  OSPanic("sparsearray.c",0xe3,"Failed assertion element");
}

