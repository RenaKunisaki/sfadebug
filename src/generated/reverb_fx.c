
/* Library Function - Single Match
    reverbFxFn_800593c4
   
   Library: KioskDefault 0 0 */

void reverbFxCb_800593c4(char param1,uint **param2,int param3) { //800593C4
  if (param1 != '\x01') {
    if ((param1 != '\0') || (false)) {
                    
      OSPanic("reverb_fx.c",0x22,"Failed assertion FALSE");
    }
    if (*(char *)(param3 + 0x1c4) == '\0') {
      FUN_80059fb0(*param2,param2[1],param2[2],param3);
    }
  }
  return;
}

