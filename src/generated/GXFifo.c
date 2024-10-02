
/* Library Function - Single Match
    GXOverflowHandler
   
   Library: KioskDefault 0 0 */

void GXOverflowHandler(void) { //8001C334
  if (1 < pGxDebug->debugLevel) {
    OSReport("[GXOverflowHandler]");
  }
  if (DAT_80398488 != 0) {
                    
    OSPanic("GXFifo.c",0x15a,"Failed assertion !GXOverflowSuspendInProgress");
  }
  DAT_80398490 = DAT_80398490 + 1;
  gxFifoFn_8001d12c(0,1);
  gxFifoFn_8001d1e0(1,0);
  DAT_80398488 = 1;
  if (1 < pGxDebug->debugLevel) {
    OSReport("[GXOverflowHandler Sleeping]");
  }
  OSSuspendThread(PTR_OSThread_80398480);
  return;
}


/* Library Function - Single Match
    GXUnderflowHandler
   
   Library: KioskDefault 0 0 */

void GXUnderflowHandler(void) { //8001C3EC
  if (1 < pGxDebug->debugLevel) {
    OSReport("[GXUnderflowHandler]");
  }
  if (DAT_80398488 == 0) {
                    
    OSPanic("GXFifo.c",0x184,"Failed assertion GXOverflowSuspendInProgress");
  }
  OSResumeThread(PTR_OSThread_80398480);
  DAT_80398488 = 0;
  gxFifoFn_8001d1e0(1,1);
  gxFifoFn_8001d12c(1,0);
  return;
}


/* Library Function - Single Match
    GXInitFifoBase
   
   Library: KioskDefault 0 0 */

void GXInitFifoBase(uint *param1,uint param2,uint param3) { //8001C5B8
  if (param1 == (uint *)PTR_PTR_DAT_8039849c) {
                    
    OSPanic("GXFifo.c",0x1ff,"GXInitFifoBase: fifo is attached to CPU");
  }
  if (param1 == (uint *)PTR_PTR_DAT_80398498) {
                    
    OSPanic("GXFifo.c",0x201,"GXInitFifoBase: fifo is attached to GP");
  }
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("GXFifo.c",0x203,"GXInitFifoBase: base must be 32B aligned");
  }
  if (param2 == 0) {
                    
    OSPanic("GXFifo.c",0x205,"GXInitFifoBase: base pointer is NULL");
  }
  if ((param3 & 0x1f) != 0) {
                    
    OSPanic("GXFifo.c",0x207,"GXInitFifoBase: size must be 32B aligned");
  }
  if (param3 < 0x10000) {
                    
    OSPanic("GXFifo.c",0x209,"GXInitFifoBase: fifo is not large enough");
  }
  *param1 = param2;
  param1[1] = param2 + (param3 - 4);
  param1[2] = param3;
  param1[7] = 0;
  GXInitFifoLimits((int *)param1,param3 - 0x4000,param3 >> 1 & 0x7fffffe0);
  GXInitFifoPtrs(param1,param2,param2);
  return;
}


/* Library Function - Single Match
    GXInitFifoPtrs
   
   Library: KioskDefault 0 0 */

void GXInitFifoPtrs(uint *param1,uint param2,uint param3) { //8001C6E4
  BOOL_ level;
  
  if (param1 == (uint *)PTR_PTR_DAT_8039849c) {
                    
    OSPanic("GXFifo.c",0x231,"GXInitFifoPtrs: fifo is attached to CPU");
  }
  if (param1 == (uint *)PTR_PTR_DAT_80398498) {
                    
    OSPanic("GXFifo.c",0x233,"GXInitFifoPtrs: fifo is attached to GP");
  }
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("GXFifo.c",0x235,"GXInitFifoPtrs: readPtr not 32B aligned");
  }
  if ((param3 & 0x1f) != 0) {
                    
    OSPanic("GXFifo.c",0x237,"GXInitFifoPtrs: writePtr not 32B aligned");
  }
  if ((param2 < *param1) || (param1[1] <= param2)) {
                    
    OSPanic("GXFifo.c",0x23a,"GXInitFifoPtrs: readPtr not in fifo range");
  }
  if ((*param1 <= param3) && (param3 < param1[1])) {
    level = OSDisableInterrupts();
    param1[5] = param2;
    param1[6] = param3;
    param1[7] = param3 - param2;
    if ((int)param1[7] < 0) {
      param1[7] = param1[7] + param1[2];
    }
    OSRestoreInterrupts(level);
    return;
  }
                    
  OSPanic("GXFifo.c",0x23d,"GXInitFifoPtrs: writePtr not in fifo range");
}


/* Library Function - Single Match
    FXInitFifoLimits
   
   Library: KioskDefault 0 0 */

void GXInitFifoLimits(int *param1,uint param2,uint param3) { //8001C82C
  if (param1 == (int *)PTR_PTR_DAT_80398498) {
                    
    OSPanic("GXFifo.c",0x262,"GXInitFifoLimits: fifo is attached to GP");
  }
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("GXFifo.c",0x264,"GXInitFifoLimits: hiWatermark not 32B aligned");
  }
  if ((param3 & 0x1f) != 0) {
                    
    OSPanic("GXFifo.c",0x266,"GXInitFifoLimits: loWatermark not 32B aligned");
  }
  if ((uint)(param1[1] - *param1) <= param2) {
                    
    OSPanic("GXFifo.c",0x268,"GXInitFifoLimits: hiWatermark too large");
  }
  if (param2 <= param3) {
                    
    OSPanic("GXFifo.c",0x26a,"GXInitFifoLimits: hiWatermark below lo watermark");
  }
  param1[3] = param2;
  param1[4] = param3;
  return;
}


/* Library Function - Single Match
    gxFifoFn_8001c90c
   
   Library: KioskDefault 0 0 */

void _gxFifoSubmitDlist(uint *list) { //8001C90C
  BOOL_ level;
  
  level = OSDisableInterrupts();
  PTR_PTR_DAT_8039849c = (undefined *)list;
  if (list == (uint *)PTR_PTR_DAT_80398498) {
    *(uint *)(PTR_pi_INTSR_8039846c + 0xc) = *list & 0x3fffffff;
    *(uint *)(PTR_pi_INTSR_8039846c + 0x10) = list[1] & 0x3fffffff;
    if (((list[6] & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
                    
      OSPanic("GXFifo.c",0x294,"GX Internal: Register field out of range");
    }
    *(uint *)(PTR_pi_INTSR_8039846c + 0x14) = list[6] & 0x3bffffe0;
    DAT_80398484 = '\x01';
    gxFifoFn_8001d1e0(1,1);
    gxFifoFn_8001d12c(1,0);
    gxFifoFn_8001d08c('\x01');
  }
  else {
    if (DAT_80398484 != '\0') {
      gxFifoFn_8001d08c('\0');
      DAT_80398484 = '\0';
    }
    gxFifoFn_8001d12c(0,0);
    *(uint *)(PTR_pi_INTSR_8039846c + 0xc) = *list & 0x3fffffff;
    *(uint *)(PTR_pi_INTSR_8039846c + 0x10) = list[1] & 0x3fffffff;
    if (((list[6] & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
                    
      OSPanic("GXFifo.c",0x2b7,"GX Internal: Register field out of range");
    }
    *(uint *)(PTR_pi_INTSR_8039846c + 0x14) = list[6] & 0x3bffffe0;
  }
  sync(0);
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    GXSaveCPUFifo
   
   Library: KioskDefault 0 0 */

void GXSaveCPUFifo(void **param1) { //8001CC00
  if (param1 != (void **)PTR_PTR_DAT_8039849c) {
                    
    OSPanic("GXFifo.c",0x321,"GXSaveCPUFifo: fifo is not attached to CPU");
  }
  _GXSaveCPUFifo(param1);
  return;
}


/* Library Function - Single Match
    GXGetFifoPtrs
   
   Library: KioskDefault 0 0 */

void GXGetFifoPtrs(undefined *param1,undefined4 *param2,undefined4 *param3) { //8001CD48
  void *pvVar1;
  
  if ((param1 != PTR_PTR_DAT_8039849c) && (param1 != PTR_PTR_DAT_80398498)) {
                    
    OSPanic("GXFifo.c",0x3f2,"GXGetFifoPtrs: fifo is not CPU or GP fifo");
  }
  if (param1 == PTR_PTR_DAT_8039849c) {
    pvVar1 = OSPhysicalToCached(*(uint *)(PTR_pi_INTSR_8039846c + 0x14) & 0xfbffffff);
    *(void **)(param1 + 0x18) = pvVar1;
  }
  if (param1 == PTR_PTR_DAT_80398498) {
    pvVar1 = OSPhysicalToCached(CONCAT22(*(undefined2 *)(PTR_CP_SR_80398470 + 0x3a),
                                         *(undefined2 *)(PTR_CP_SR_80398470 + 0x38)));
    *(void **)(param1 + 0x14) = pvVar1;
    *(uint *)(param1 + 0x1c) =
         CONCAT22(*(undefined2 *)(PTR_CP_SR_80398470 + 0x32),
                  *(undefined2 *)(PTR_CP_SR_80398470 + 0x30));
  }
  else {
    *(int *)(param1 + 0x1c) = *(int *)(param1 + 0x18) - *(int *)(param1 + 0x14);
    if (*(int *)(param1 + 0x1c) < 0) {
      *(int *)(param1 + 0x1c) = *(int *)(param1 + 0x1c) + *(int *)(param1 + 8);
    }
  }
  *param2 = *(undefined4 *)(param1 + 0x14);
  *param3 = *(undefined4 *)(param1 + 0x18);
  return;
}


/* Library Function - Single Match
    GXEnableBreakPt
   
   Library: KioskDefault 0 0 */

void GXEnableBreakPt(uint param1) { //8001CEAC
  BOOL_ level;
  
  level = OSDisableInterrupts();
  FUN_8001d064();
  if ((*(uint *)PTR_PTR_DAT_80398498 <= param1) && (param1 <= *(uint *)(PTR_PTR_DAT_80398498 + 4)))
  {
    *(short *)(PTR_CP_SR_80398470 + 0x3c) = (short)param1;
    *(ushort *)(PTR_CP_SR_80398470 + 0x3e) = (ushort)(param1 >> 0x10) & 0x3fff;
    *(uint *)&gx->field_0x8 = *(uint *)&gx->field_0x8 & 0xfffffffd | 2;
    *(uint *)&gx->field_0x8 = *(uint *)&gx->field_0x8 & 0xffffffdf | 0x20;
    *(short *)(PTR_CP_SR_80398470 + 2) = (short)*(undefined4 *)&gx->field_0x8;
    DAT_80398494 = param1;
    FUN_8001d038();
    OSRestoreInterrupts(level);
    return;
  }
                    
  OSPanic("GXFifo.c",0x44a,"GXEnableBreakPt: Break point value not in fifo range");
}


/* Library Function - Single Match
    gxFifoFn_8001d08c
   
   Library: KioskDefault 0 0 */

void gxFifoFn_8001d08c(char param1) { //8001D08C
  if (false) {
                    
    OSPanic("GXFifo.c",0x4b0,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x8 = *(uint *)&gx->field_0x8 & 0xffffffef | (uint)(param1 != '\0') << 4;
  *(short *)(PTR_CP_SR_80398470 + 2) = (short)*(undefined4 *)&gx->field_0x8;
  return;
}


/* Library Function - Single Match
    gxFifoFn_8001d12c
   
   Library: KioskDefault 0 0 */

void gxFifoFn_8001d12c(uint param1,uint param2) { //8001D12C
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXFifo.c",0x4c6,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x8 = *(uint *)&gx->field_0x8 & 0xfffffffb | (param1 & 0xff) << 2;
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXFifo.c",0x4c7,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x8 = *(uint *)&gx->field_0x8 & 0xfffffff7 | (param2 & 0xff) << 3;
  *(short *)(PTR_CP_SR_80398470 + 2) = (short)*(undefined4 *)&gx->field_0x8;
  return;
}


/* Library Function - Single Match
    gxFifoFn_8001d1e0
   
   Library: KioskDefault 0 0 */

void gxFifoFn_8001d1e0(uint param1,uint param2) { //8001D1E0
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXFifo.c",0x4de,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x10 = *(uint *)&gx->field_0x10 & 0xfffffffe | param1 & 0xff;
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXFifo.c",0x4df,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x10 = *(uint *)&gx->field_0x10 & 0xfffffffd | (param2 & 0xff) << 1;
  *(short *)(PTR_CP_SR_80398470 + 4) = (short)*(undefined4 *)&gx->field_0x10;
  return;
}

