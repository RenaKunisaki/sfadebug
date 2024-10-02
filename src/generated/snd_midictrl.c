
/* Library Function - Single Match
    midiFn_800557a0
   
   Library: KioskDefault 0 0 */

bool midiFn_800557a0(uint param1,byte midiSet,uint param3) { //800557A0
  bool bVar1;
  
  if (midiSet == 0xff) {
                    
    OSPanic("snd_midictrl.c",0x43,"Failed assertion midiSet!=SYNTH_FX_MIDISET");
  }
  bVar1 = (param3 & (&DAT_8034b520)[(uint)midiSet * 0x10 + (param1 & 0xff)]) != 0;
  if (bVar1) {
    (&DAT_8034b520)[(uint)midiSet * 0x10 + (param1 & 0xff)] =
         (&DAT_8034b520)[(uint)midiSet * 0x10 + (param1 & 0xff)] & ~param3;
  }
  return bVar1;
}


/* Library Function - Single Match
    midiFn_80055854
   
   Library: KioskDefault 0 0 */

void midiFn_80055854(byte param1,byte midiSet,uint param3) { //80055854
  if (midiSet == 0xff) {
                    
    OSPanic("snd_midictrl.c",0x4d,"Failed assertion midiSet!=SYNTH_FX_MIDISET");
  }
  (&DAT_8034b520)[(uint)midiSet * 0x10 + (uint)param1] =
       (&DAT_8034b520)[(uint)midiSet * 0x10 + (uint)param1] | param3;
  return;
}

