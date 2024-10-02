
undefined4 * FUN_800080b8(undefined4 *param_1,undefined4 *param_2) { //800080B8
  param_2[1] = param_1;
  *param_2 = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  return param_2;
}


int FUN_800080d8(int param_1,int *param_2) { //800080D8
  if (param_2[1] != 0) {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 == 0) {
    return param_2[1];
  }
  *(int *)(*param_2 + 4) = param_2[1];
  return param_1;
}


undefined4 FUN_80008118(uint param_1,uint param_2,uint param_3) { //80008118
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    if (((param_2 <= param_1) && (param_1 < param_3)) ||
       ((param_2 < param_1 + *(int *)(param_1 + 8) && (param_1 + *(int *)(param_1 + 8) <= param_3)))
       ) break;
    param_1 = *(uint *)(param_1 + 4);
  }
  return 1;
}


/* Library Function - Single Match
    OSAllocFromHeap
   
   Library: KioskDefault 0 0 */

void * OSAllocFromHeap(OSHeapHandle heap,u32 size) { //8000817C
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  if (OSHeapHandle_80398258 == 0) {
                    
    OSPanic("OSAlloc.c",0x14d,"OSAllocFromHeap(): heap is not initialized.");
  }
  if ((int)size < 1) {
                    
    OSPanic("OSAlloc.c",0x14e,"OSAllocFromHeap(): invalid size.");
  }
  if ((heap < 0) || (OSHeapHandle_8039825c <= heap)) {
                    
    OSPanic("OSAlloc.c",0x14f,"OSAllocFromHeap(): invalid heap handle.");
  }
  if (*(int *)(OSHeapHandle_80398258 + heap * 0x18) < 0) {
                    
    OSPanic("OSAlloc.c",0x150,"OSAllocFromHeap(): invalid heap handle.");
  }
  iVar5 = OSHeapHandle_80398258 + heap * 0x18;
  uVar1 = size + 0x3f & 0xffffffe0;
  for (piVar6 = *(int **)(iVar5 + 4); (piVar6 != (int *)0x0 && (piVar6[2] < (int)uVar1));
      piVar6 = (int *)piVar6[1]) {
  }
  if (piVar6 == (int *)0x0) {
    OSReport("OSAllocFromHeap: Warning- failed to allocate %d bytes",uVar1);
    piVar6 = (int *)0x0;
  }
  else {
    if (((uint)piVar6 & 0x1f) != 0) {
                    
      OSPanic("OSAlloc.c",0x168,"OSAllocFromHeap(): heap is broken.");
    }
    if (piVar6[3] != 0) {
                    
      OSPanic("OSAlloc.c",0x169,"OSAllocFromHeap(): heap is broken.");
    }
    iVar2 = piVar6[2];
    if (iVar2 - uVar1 < 0x40) {
      iVar2 = FUN_800080d8(*(int *)(iVar5 + 4),piVar6);
      *(int *)(iVar5 + 4) = iVar2;
    }
    else {
      piVar6[2] = uVar1;
      piVar4 = (int *)((int)piVar6 + uVar1);
      piVar4[2] = iVar2 - uVar1;
      piVar4[3] = 0;
      *piVar4 = *piVar6;
      piVar4[1] = piVar6[1];
      if (piVar4[1] != 0) {
        *(int **)piVar4[1] = piVar4;
      }
      if (*piVar4 == 0) {
        if (*(int **)(iVar5 + 4) != piVar6) {
                    
          OSPanic("OSAlloc.c",0x186,"OSAllocFromHeap(): heap is broken.");
        }
        *(int **)(iVar5 + 4) = piVar4;
      }
      else {
        *(int **)(*piVar4 + 4) = piVar4;
      }
    }
    puVar3 = FUN_800080b8(*(undefined4 **)(iVar5 + 8),piVar6);
    *(undefined4 **)(iVar5 + 8) = puVar3;
    piVar6[3] = iVar5;
    piVar6[4] = size;
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 0x20;
    *(u32 *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + (piVar6[2] - (size + 0x20));
    *(u32 *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + size;
    piVar6 = piVar6 + 8;
  }
  return piVar6;
}


/* Library Function - Single Match
    OSSetCurrentHeap
   
   Library: KioskDefault 0 0 */

OSHeapHandle OSSetCurrentHeap(OSHeapHandle heap) { //800083CC
  OSHeapHandle OVar1;
  
  OVar1 = DAT_80396730;
  if (OSHeapHandle_80398258 == 0) {
                    
    OSPanic("OSAlloc.c",0x267,"OSSetCurrentHeap(): heap is not initialized.");
  }
  if ((-1 < heap) && (heap < OSHeapHandle_8039825c)) {
    if (*(int *)(OSHeapHandle_80398258 + heap * 0x18) < 0) {
                    
      OSPanic("OSAlloc.c",0x269,"OSSetCurrentHeap(): invalid heap handle.");
    }
    DAT_80396730 = heap;
    return OVar1;
  }
                    
  OSPanic("OSAlloc.c",0x268,"OSSetCurrentHeap(): invalid heap handle.");
}


/* Library Function - Single Match
    OSInitAlloc
   
   Library: KioskDefault 0 0 */

void * OSInitAlloc(void *arenaStart,void *arenaEnd,int maxHeaps) { //80008478
  int iVar1;
  undefined4 *puVar2;
  
  if (maxHeaps < 1) {
                    
    OSPanic("OSAlloc.c",0x283,"OSInitAlloc(): invalid number of heaps.");
  }
  if (arenaEnd <= arenaStart) {
                    
    OSPanic("OSAlloc.c",0x285,"OSInitAlloc(): invalid range.");
  }
  if ((uint)((int)arenaEnd - (int)arenaStart) / 0x18 < (uint)maxHeaps) {
                    
    OSPanic("OSAlloc.c",0x288,"OSInitAlloc(): too small range.");
  }
  OSHeapHandle_80398258 = (OSHeapHandle)arenaStart;
  OSHeapHandle_8039825c = maxHeaps;
  for (iVar1 = 0; iVar1 < OSHeapHandle_8039825c; iVar1 = iVar1 + 1) {
    puVar2 = (undefined4 *)(OSHeapHandle_80398258 + iVar1 * 0x18);
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    puVar2[1] = 0;
    puVar2[5] = 0;
    puVar2[4] = 0;
    puVar2[3] = 0;
  }
  DAT_80396730 = 0xffffffff;
  PTR_PTR_80398260 = (undefined *)(OSHeapHandle_80398258 + maxHeaps * 0x18 + 0x1fU & 0xffffffe0);
  PTR_DAT_80398264 = (undefined *)((uint)arenaEnd & 0xffffffe0);
  if ((uint)((int)PTR_DAT_80398264 - (int)PTR_PTR_80398260) < 0x40) {
                    
    OSPanic("OSAlloc.c",0x2a4,"OSInitAlloc(): too small range.");
  }
  return PTR_PTR_80398260;
}


/* Library Function - Single Match
    OSCreateHeap
   
   Library: KioskDefault 0 0 */

OSHeapHandle OSCreateHeap(void *start,void *end) { //800085B4
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (OSHeapHandle_80398258 == 0) {
                    
    OSPanic("OSAlloc.c",0x2bd,"OSCreateHeap(): heap is not initialized.");
  }
  if (end <= start) {
                    
    OSPanic("OSAlloc.c",0x2be,"OSCreateHeap(): invalid range.");
  }
  puVar1 = (undefined4 *)((int)start + 0x1fU & 0xffffffe0);
  puVar2 = (undefined4 *)((uint)end & 0xffffffe0);
  if (puVar2 <= puVar1) {
                    
    OSPanic("OSAlloc.c",0x2c1,"OSCreateHeap(): invalid range.");
  }
  if ((PTR_PTR_80398260 <= puVar1) && (puVar2 <= PTR_DAT_80398264)) {
    if ((uint)((int)puVar2 - (int)puVar1) < 0x40) {
                    
      OSPanic("OSAlloc.c",0x2c5,"OSCreateHeap(): too small range.");
    }
    iVar5 = 0;
    do {
      if (OSHeapHandle_8039825c <= iVar5) {
        iVar5 = 0;
        while( true ) {
          if (OSHeapHandle_8039825c <= iVar5) {
            OSReport("OSCreateHeap: Warning - Failed to find free heap descriptor.");
            return -1;
          }
          piVar4 = (int *)(OSHeapHandle_80398258 + iVar5 * 0x18);
          if (*piVar4 < 0) break;
          iVar5 = iVar5 + 1;
        }
        *piVar4 = (int)puVar2 - (int)puVar1;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = *piVar4;
        puVar1[3] = 0;
        piVar4[1] = (int)puVar1;
        piVar4[2] = 0;
        piVar4[5] = 0;
        piVar4[4] = 0;
        piVar4[3] = 0;
        return iVar5;
      }
      if (-1 < *(int *)(OSHeapHandle_80398258 + iVar5 * 0x18)) {
        iVar3 = FUN_80008118(*(uint *)(OSHeapHandle_80398258 + iVar5 * 0x18 + 4),(uint)puVar1,
                             (uint)puVar2);
        if (iVar3 != 0) {
                    
          OSPanic("OSAlloc.c",0x2cf,"OSCreateHeap(): invalid range.");
        }
        iVar3 = FUN_80008118(*(uint *)(OSHeapHandle_80398258 + iVar5 * 0x18 + 8),(uint)puVar1,
                             (uint)puVar2);
        if (iVar3 != 0) {
                    
          OSPanic("OSAlloc.c",0x2d1,"OSCreateHeap(): invalid range.");
        }
      }
      iVar5 = iVar5 + 1;
    } while( true );
  }
                    
  OSPanic("OSAlloc.c",0x2c3,"OSCreateHeap(): invalid range.");
}

