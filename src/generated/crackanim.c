
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void crackanim_initialise(undefined4 param) { //801F8B80
  return;
}


/* @description Called when DLL is unloaded */

void crackanim_release(void) { //801F8B84
  return;
}


/* Library Function - Single Match
    dll_14B_func03
   
   Library: KioskDefault 0 0 */

void dll_CrackAnimator_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801F8B88
  uint uVar1;
  void *pvVar2;
  int unaff_r27;
  void **ppvVar3;
  
  ppvVar3 = (void **)this->state;
  *(undefined *)((int)ppvVar3 + 0x35) = 1;
  ppvVar3[4] = (void *)0.0;
  ppvVar3[6] = (void *)0.0;
  ppvVar3[5] = (void *)0.0;
  ppvVar3[7] = (void *)0.0;
  ppvVar3[8] = (void *)-50.0;
  *(undefined2 *)(ppvVar3 + 0xe) = 0;
  *(undefined2 *)((int)ppvVar3 + 0x3a) = *(undefined2 *)&objDef[1].bound;
  *(undefined2 *)(ppvVar3 + 0xf) = 0x28;
  *(undefined2 *)((int)ppvVar3 + 0x3e) = 9;
  uVar1 = randInt(1,5);
  ppvVar3[9] = (void *)((float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0
                               ) * 2.5);
  ppvVar3[10] = (void *)0.0;
  uVar1 = randInt(1,5);
  ppvVar3[0xb] = (void *)((float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                                 4503601774854144.0) * 2.5);
  ppvVar3[0xc] = (void *)0.0;
  *(short *)(ppvVar3 + 0x10) = (short)*(char *)((int)&objDef[1].objType + 1);
  if (*(short *)(ppvVar3 + 0x10) != 0) {
    mainSetBits(0x1c9,0);
  }
  if (*(short *)(ppvVar3 + 0x10) != 0) {
    mainSetBits(0x1cb,0);
  }
  if (unaff_r27 == 0) {
    *(undefined *)((int)ppvVar3 + 0x35) = 0;
  }
  if (*(char *)((int)ppvVar3 + 0x35) != '\0') {
    if (obj2 == (ObjInstance *)0x0) {
      pvVar2 = mmAlloc(unaff_r27 << 2,TRACK_COL,"crackanim");
      ppvVar3[2] = pvVar2;
      nop_801F8EB0();
    }
    pvVar2 = mmAlloc(0x28,LFX_COL,"crackanimfx:light1");
    *ppvVar3 = pvVar2;
    loadAsset_fileWithOffsetLength(*ppvVar3,LACTIONS.bin,(DAT_80399dc0 + 0xed) * 0x28,0x28);
    pvVar2 = mmAlloc(0x28,LFX_COL,"crackanimfx:light1");
    ppvVar3[1] = pvVar2;
    loadAsset_fileWithOffsetLength(ppvVar3[1],LACTIONS.bin,(DAT_80399dc0 + 0xef) * 0x28,0x28);
    if (DAT_80399dc0 == 0) {
      loadEnvfxAction(this,this,0xd6,0);
      DAT_80399dc0 = 1;
    }
    Object_objAddObjectType(this,0x13);
  }
  return;
}


/* @description Update object instance */

void crackanim_update(ObjInstance *this) { //801F8DA8
  return;
}


/* @description Override hit detection */

void crackanim_hitDetect(ObjInstance *this) { //801F8DAC
  return;
}


/* Library Function - Single Match
    dll_14B_func06
   
   Library: KioskDefault 0 0 */

void crackanim_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //801F8DB0
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  
  puVar2 = this->state;
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if (bVar1) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)*(float *)(puVar2 + 0x18),25.0,(Gfx *)CONCAT31(in_register_00000010,param2)
                 ,(int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
  }
  return;
}


/* Library Function - Single Match
    dll_14B_func07
   
   Library: KioskDefault 0 0 */

void crackanim_free(ObjInstance *this,int param2) { //801F8E40
  void **ppvVar1;
  
  ppvVar1 = (void **)this->state;
  if (ppvVar1[2] != (void *)0x0) {
    mm_free(ppvVar1[2]);
  }
  if (*ppvVar1 != (void *)0x0) {
    mm_free(*ppvVar1);
    *ppvVar1 = (void *)0x0;
  }
  return;
}


undefined4 crackanim_func08(ObjInstance *this) { //801F8EA0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int crackanim_getExtraSize(void) { //801F8EA8
  return 0x44;
}

