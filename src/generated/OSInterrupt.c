
/* Library Function - Single Match
    OSDisableInterrupts
   
   Library: KioskDefault 0 0 */

BOOL_ OSDisableInterrupts(void) { //8000B2F8
  uint in_MSR;
  
  return in_MSR >> 0xf & 1;
}


/* Library Function - Single Match
    OSEnableInterrupts
   
   Library: KioskDefault 0 0 */

BOOL_ OSEnableInterrupts(void) { //8000B30C
  uint in_MSR;
  
  return in_MSR >> 0xf & 1;
}


/* Library Function - Single Match
    OSRestoreInterrupts
   
   Library: KioskDefault 0 0 */

BOOL_ OSRestoreInterrupts(BOOL_ level) { //8000B320
  return level;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __OSSetInterruptHandler
   
   Library: KioskDefault 0 0 */

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt,__OSInterruptHandler handler) { //8000B344
  __OSInterruptHandler p_Var1;
  
  if (_isOsInit == 0) {
                    
    OSPanic("OSInterrupt.c",0x188,"__OSSetInterruptHandler(): OSInit() must be called in advance.");
  }
  if (0x1f < interrupt) {
                    
    OSPanic("OSInterrupt.c",0x18a,"__OSSetInterruptHandler(): unknown interrupt.");
  }
  p_Var1 = *(__OSInterruptHandler *)(_isOsInit + interrupt * 4);
  *(__OSInterruptHandler *)(_isOsInit + interrupt * 4) = handler;
  return p_Var1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __OSGetInterruptHandler
   
   Library: KioskDefault 0 0 */

__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt) { //8000B408
  if (_isOsInit == 0) {
                    
    OSPanic("OSInterrupt.c",0x19e,"__OSGetInterruptHandler(): OSInit() must be called in advance.");
  }
  if (0x1f < interrupt) {
                    
    OSPanic("OSInterrupt.c",0x1a0,"__OSGetInterruptHandler(): unknown interrupt.");
  }
  return *(__OSInterruptHandler *)(_isOsInit + interrupt * 4);
}


uint __OSMaskInterrupts(uint interruptFlags) { //8000B818
  BOOL_ level;
  uint *puVar1;
  uint uVar2;
  uint param1;
  uint uVar3;
  
  level = OSDisableInterrupts();
  puVar1 = (uint *)OSPhysicalToCached(0xc4);
  uVar3 = *puVar1;
  puVar1 = (uint *)OSPhysicalToCached(200);
  uVar2 = *puVar1;
  puVar1 = (uint *)OSPhysicalToCached(0xc4);
  *puVar1 = interruptFlags | uVar3;
  for (param1 = interruptFlags & ~(uVar3 | uVar2); param1 != 0;
      param1 = SetInterruptMask(param1,interruptFlags | uVar3 | uVar2)) {
  }
  OSRestoreInterrupts(level);
  return uVar3;
}


uint __OSUnmaskInterrupts(uint interruptFlags) { //8000B8A0
  BOOL_ level;
  uint *puVar1;
  uint uVar2;
  uint param1;
  uint uVar3;
  
  level = OSDisableInterrupts();
  puVar1 = (uint *)OSPhysicalToCached(0xc4);
  uVar3 = *puVar1;
  puVar1 = (uint *)OSPhysicalToCached(200);
  uVar2 = *puVar1;
  puVar1 = (uint *)OSPhysicalToCached(0xc4);
  *puVar1 = uVar3 & ~interruptFlags;
  for (param1 = interruptFlags & (uVar3 | uVar2); param1 != 0;
      param1 = SetInterruptMask(param1,uVar3 & ~interruptFlags | uVar2)) {
  }
  OSRestoreInterrupts(level);
  return uVar3;
}

