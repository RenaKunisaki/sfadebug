
/* Library Function - Single Match
    musicVoiceFn_80055560
   
   Library: KioskDefault 0 0 */

void musicVoiceFn_80055560(byte nMusic,byte nSound) { //80055560
  if (maxVoices < nMusic) {
                    
    OSPanic("snd_init.c",0x6e,"Music voices are above maximum voice number.");
  }
  if (maxVoices < nSound) {
                    
    OSPanic("snd_init.c",0x6f,"Sfx voices are above maximum voice number.");
  }
  numMusicVoices = nMusic;
  numSfxVoices = nSound;
  return;
}

