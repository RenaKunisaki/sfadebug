
/* Library Function - Single Match
    audioPlayStream
   
   Library: KioskDefault 0 0 */

void audioPlayStream(uint id,undefined *callback) { //80068C20
  char **ppcVar1;
  BOOL BVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  AudioNameStruct *stream;
  char acStack_58 [68];
  
  stream = debugAudioStreams;
  iVar5 = -1;
  iVar4 = 0x15;
  do {
    bVar3 = iVar4 == 0;
    iVar4 = iVar4 + -1;
    if (bVar3) {
LAB_80068c80:
      if (iVar5 == -1) {
        OSReport("ERROR: audio.c: audioPlayStream(%d), SequenceID not found!",id);
      }
      else {
        BVar2 = audioIsStreamBlocked();
        if (BVar2 == FALSE) {
          bAudioPrepareStreamCalled = false;
          bAudioShouldPlayStream = false;
          debugAudioCurStream2 = '\0';
          bAudioStreamPlaying = false;
          bVar3 = concatThreeStrings(acStack_58,0x40,"/streams/",stream->name,
                                     ".adp");
          if ((bVar3) &&
             (BVar2 = DVDOpen(acStack_58,(DVDFileInfo *)(audioGroupIds + 0x20)), BVar2 != FALSE)) {
            bAudioShouldPlayStream = SUB41(iVar5,0);
            audioPlayStreamCallback = callback;
            DVDPrepareStreamAsync
                      ((undefined **)(audioGroupIds + 0x20),(undefined *)0x0,(undefined *)0x0,
                       audioStreamCb_80068bc8);
          }
        }
      }
      return;
    }
    if ((ushort)stream->id == id) {
      ppcVar1 = &stream[0xffa300b].name;
      iVar5 = ((int)ppcVar1 >> 3) + (uint)((int)ppcVar1 < 0 && ((uint)ppcVar1 & 7) != 0);
      goto LAB_80068c80;
    }
    stream = stream + 1;
  } while( true );
}

