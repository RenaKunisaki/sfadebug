
/* Library Function - Single Match
    GXBeginDisplayList
   
   Library: KioskDefault 0 0 */

void GXBeginDisplayList(void *list,uint size) { //8002C494
  void **param1;
  
  param1 = (void **)FUN_8001d294();
  if (isInGxBegin != false) {
                    
    OSPanic("GXDisplayList.c",0x7c,"'GXBeginDisplayList' is not allowed between GXBegin/GXEnd");
  }
  if (gx->isDlistInProgress != false) {
                    
    OSPanic("GXDisplayList.c",0x7d,"GXBeginDisplayList: display list already in progress");
  }
  if ((size & 0x1f) != 0) {
                    
    OSPanic("GXDisplayList.c",0x7e,"GXBeginDisplayList: size is not 32 byte aligned");
  }
  if (((uint)list & 0x1f) != 0) {
                    
    OSPanic("GXDisplayList.c",0x7f,"GXBeginDisplayList: list is not 32 byte aligned");
  }
  if (gx->flags4F0 != 0) {
    __GXSetDirtyState();
  }
  if (gx->field_0x4ed != '\0') {
    memcpy(&DAT_8032749c,gx,0x4f4);
  }
  gxDlistEnd_8032747c = (int)list + (size - 4);
  gxDlistMaybePos_80327494 = 0;
  gxDlist_80327478 = list;
  gxDlistSize_80327480 = size;
  gxDlist_8032748c = list;
  gxDlist_80327490 = list;
  gx->isDlistInProgress = true;
  GXSaveCPUFifo(param1);
  DAT_803984b8 = param1;
  _gxFifoSubmitDlist((uint *)&gxDlist_80327478);
  return;
}


/* Library Function - Single Match
    GXEndDisplayList
   
   Library: KioskDefault 0 0 */

undefined4 GXEndDisplayList(void) { //8002C5CC
  BOOL_ level;
  undefined4 uVar1;
  uint uVar2;
  
  if (isInGxBegin) {
                    
    OSPanic("GXDisplayList.c",0xb5,"'GXEndDisplayList' is not allowed between GXBegin/GXEnd");
  }
  if (gx->isDlistInProgress == true) {
    if (gx->flags4F0 != 0) {
      __GXSetDirtyState();
    }
    uVar2 = *(uint *)(PTR_pi_INTSR_8039846c + 0x14);
    _GXSaveCPUFifo(&gxDlist_80327478);
    if ((uVar2 >> 0x1a & 1) == 0) {
      _gxFifoSubmitDlist(DAT_803984b8);
      if (gx->field_0x4ed != '\0') {
        level = OSDisableInterrupts();
        uVar1 = *(undefined4 *)&gx->field_0x8;
        memcpy(gx,&DAT_8032749c,0x4f4);
        *(undefined4 *)&gx->field_0x8 = uVar1;
        OSRestoreInterrupts(level);
      }
      gx->isDlistInProgress = false;
      uVar1 = gxDlistMaybePos_80327494;
      if (false) {
        uVar1 = 0;
      }
      return uVar1;
    }
                    
    OSPanic("GXDisplayList.c",0xc3,"GXEndDisplayList: display list commands overflowed buffer");
  }
                    
  OSPanic("GXDisplayList.c",0xb6,"GXEndDisplayList: no display list in progress");
}


/* Library Function - Single Match
    GXCallDisplayList
   
   Library: KioskDefault 0 0 */

void GXCallDisplayList(void *list,uint nbytes) { //8002C6F0
  int iVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXDisplayList.c",0xec,"'GXCallDisplayList' is not allowed between GXBegin/GXEnd");
  }
  if (gx->isDlistInProgress != false) {
                    
    OSPanic("GXDisplayList.c",0xed,"GXCallDisplayList: display list already in progress");
  }
  if ((nbytes & 0x1f) != 0) {
                    
    OSPanic("GXDisplayList.c",0xee,"GXCallDisplayList: nbytes is not 32 byte aligned");
  }
  if (((uint)list & 0x1f) != 0) {
                    
    OSPanic("GXDisplayList.c",0xef,"GXCallDisplayList: list is not 32 byte aligned");
  }
  if (gx->flags4F0 != 0) {
    __GXSetDirtyState();
  }
  _GXCallDisplayList(list,nbytes);
  iVar1._0_1_ = gx->needBegin;
  iVar1._1_1_ = gx->field_0x1;
  iVar1._2_2_ = gx->field2_0x2;
  if (iVar1 != 0) {
    _gxBegin();
  }
  GXFIFO._0_1_ = 0x40;
  GXFIFO = list;
  GXFIFO = nbytes;
  return;
}

