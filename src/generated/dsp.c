
/* Library Function - Single Match
    DSPAddTask
   
   Library: KioskDefault 0 0 */

undefined4 * DSPAddTask(undefined4 *param1,undefined4 param_2,char *param3) { //8001A4EC
  BOOL_ level;
  undefined4 extraout_r4;
  undefined4 uVar1;
  
  if (dspDriverIsInit != TRUE) {
                    
    OSPanic("dsp.c",0x21e,"DSPAddTask(): DSP driver not initialized!");
  }
  level = OSDisableInterrupts();
  __DSP_insert_task((undefined *)param1);
  *param1 = 0;
  param1[2] = 1;
  uVar1 = extraout_r4;
  OSRestoreInterrupts(level);
  if (param1 == (undefined4 *)PTR_DAT_80398458) {
    __DSP_boot_task((int)param1,uVar1,param3);
  }
  return param1;
}

