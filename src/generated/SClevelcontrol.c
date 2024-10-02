
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SClevelcontrol_initialise(undefined4 param) { //80255934
  return;
}


/* @description Called when DLL is unloaded */

void SClevelcontrol_release(void) { //80255938
  return;
}


/* Library Function - Single Match
    dll_1F5_func03
   
   Library: KioskDefault 0 0 */

void SClevelcontrol_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8025593C
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  puVar2[4] = 0xff;
  *puVar2 = 0;
  puVar2[2] = 0;
  uVar1 = mainGetBit(0x2ba);
  puVar2[0xc] = (char)uVar1;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8025679c;
  return;
}


/* Library Function - Single Match
    dll_1F5_func04
   
   Library: KioskDefault 0 0 */

void SClevelcontrol_update(ObjInstance *this) { //80255998
  ObjInstance *pOVar1;
  uint uVar2;
  mapId32 mVar3;
  int iVar4;
  bool bVar5;
  char *pcVar6;
  
  pcVar6 = this->state;
  pOVar1 = Object_objGetMain();
  uVar2 = mainGetBit(0x4bd);
  bVar5 = uVar2 != 0;
  if (bVar5) {
    mainSetBits(0x4bd,0);
    pcVar6[0xc] = '\x0f';
  }
  if (pcVar6[4] != '\x0e') {
    mVar3 = mapCoordsToId(SUB84((double)(pOVar1->pos).pos.x,0),SUB84((double)(pOVar1->pos).pos.z,0))
    ;
    if (mVar3 != nwastes) {
      return;
    }
    FUN_80255fd8((int)this);
    bVar5 = false;
  }
  mVar3 = mapCoordsToId(SUB84((double)(pOVar1->pos).pos.x,0),SUB84((double)(pOVar1->pos).pos.z,0));
  pcVar6[4] = (char)mVar3;
  uVar2 = mainGetBit(0x7d);
  if (uVar2 == 0) {
    uVar2 = mainGetBit(0x7e);
    if (uVar2 == 0) {
      uVar2 = mainGetBit(0x7f);
      if (uVar2 != 0) {
        mainSetBits(0x7f,0);
        if (*(short *)((int)&PTR_DAT_80397e78 + (uint)(byte)pcVar6[1] * 2) == 0x7f) {
          pcVar6[1] = pcVar6[1] + '\x01';
        }
        else {
          pcVar6[1] = '\0';
        }
      }
    }
    else {
      mainSetBits(0x7e,0);
      if (*(short *)((int)&PTR_DAT_80397e78 + (uint)(byte)pcVar6[1] * 2) == 0x7e) {
        pcVar6[1] = pcVar6[1] + '\x01';
      }
      else {
        pcVar6[1] = '\0';
      }
    }
  }
  else {
    mainSetBits(0x7d,0);
    if (*(short *)((int)&PTR_DAT_80397e78 + (uint)(byte)pcVar6[1] * 2) == 0x7d) {
      pcVar6[1] = pcVar6[1] + '\x01';
    }
    else {
      pcVar6[1] = '\0';
    }
  }
  if (2 < (byte)pcVar6[1]) {
    mainSetBits(0x80,1);
    pcVar6[1] = '\0';
  }
  if (pcVar6[2] != '\0') {
    if (pcVar6[2] == '\x05') {
      iVar4 = FUN_80073e70();
      if (iVar4 != 0) {
        mainSetBits(1999,1);
      }
    }
    else {
      uVar2 = mainGetBit(0x89);
      if ((uVar2 != 0) && (iVar4 = FUN_80073e70(), iVar4 != 0)) {
        mainSetBits(0x87,0);
        if (*pcVar6 == '\0') {
                    /* {@symbol 8011bc64} */
          (**(code **)(*(int *)pDll05_2 + 4))
                    (this,0x12,"SClevelcontrol.c",0x13d,
                     "AMMUSICACTION_SC_MainTuneDay");
        }
        else {
                    /* {@symbol 8011bc64} */
          (**(code **)(*(int *)pDll05_2 + 4))
                    (this,0xec,"SClevelcontrol.c",0x13b,
                     "AMMUSICACTION_SC_MainTuneNight");
        }
        pcVar6[2] = '\0';
      }
    }
  }
  FUN_80256210((int)this,bVar5);
  FUN_80256708();
  return;
}


/* @description Override hit detection */

void SClevelcontrol_hitDetect(ObjInstance *this) { //80255C28
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SClevelcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80255C2C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_1F5_func07
   
   Library: KioskDefault 0 0 */

void SClevelcontrol_free(ObjInstance *this,int param2) { //80255C88
  ObjInstance *param2_00;
  char *pcVar1;
  
  pcVar1 = this->state;
  if (param2 == 0) {
    param2_00 = Object_objGetMain();
    loadEnvfxAction(this,param2_00,0x1c3,0);
  }
  mainSetBits(0x2ba,(uint)(byte)pcVar1[0xc]);
  FUN_80073dcc();
                    /* {@symbol 8011bc64} */
  (**(code **)(*(int *)pDll05_2 + 4))
            (this,0xbb,"SClevelcontrol.c",0x16e,"AMMUSICACTION_SC_MaintuneKill");
                    /* {@symbol 8011bc64} */
  (**(code **)(*(int *)pDll05_2 + 4))
            (this,0xda,"SClevelcontrol.c",0x16f,"AMMUSICACTION_SC_AmbienceKill");
  if (*pcVar1 == '\0') {
                    /* {@symbol 8011bc6c} */
    (**(code **)(*(int *)pDll05_2 + 8))
              (this,0x12,"SClevelcontrol.c",0x178,"AMMUSICACTION_SC_MainTuneDay");
                    /* {@symbol 8011bc6c} */
    (**(code **)(*(int *)pDll05_2 + 8))
              (this,0xb9,"SClevelcontrol.c",0x179,"AMMUSICACTION_SC_AmbienceDay");
  }
  else {
                    /* {@symbol 8011bc6c} */
    (**(code **)(*(int *)pDll05_2 + 8))
              (this,0xec,"SClevelcontrol.c",0x173,"AMMUSICACTION_SC_MainTuneNight"
              );
                    /* {@symbol 8011bc6c} */
    (**(code **)(*(int *)pDll05_2 + 8))
              (this,0xba,"SClevelcontrol.c",0x174,"AMMUSICACTION_SC_AmbienceNight"
              );
  }
  return;
}


undefined4 SClevelcontrol_func08(ObjInstance *this) { //80255DF8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SClevelcontrol_getExtraSize(void) { //80255E00
  return 0x10;
}


/* Library Function - Single Match
    dll_1F5_func0A
   
   Library: KioskDefault 0 0 */

void SClevelcontrol_setScale(ObjInstance *this,float scale) { //80255E08
  int iVar1;
  undefined in_r4;
  undefined *puVar2;
  undefined auStack_18 [12];
  
  puVar2 = this->state;
  puVar2[2] = in_r4;
  if (puVar2[2] == '\x01') {
    mainSetBits(0x87,1);
    mainSetBits(0x2b8,1);
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0xec,"SClevelcontrol.c",0x19e,"AMMUSICACTION_SC_MainTuneNight"
              );
    FUN_80073bd8(0x1d,0x2d);
    frontFn_80073c58();
  }
  else if (puVar2[2] == '\x03') {
                    /* {@symbol 800d2604} */
    iVar1 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_18);
    if (iVar1 == 0) {
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0x12,"SClevelcontrol.c",0x1ab,"AMMUSICACTION_SC_MainTuneDay"
                );
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0xb9,"SClevelcontrol.c",0x1ac,"AMMUSICACTION_SC_AmbienceDay"
                );
    }
    else {
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0xec,"SClevelcontrol.c",0x1a6,
                 "AMMUSICACTION_SC_MainTuneNight");
                    /* {@symbol 8011bc64} */
      (**(code **)(*(int *)pDll05_2 + 4))
                (this,0xba,"SClevelcontrol.c",0x1a7,
                 "AMMUSICACTION_SC_AmbienceNight");
    }
    puVar2[2] = 0;
  }
  else if (puVar2[2] == '\x05') {
    iVar1 = randInt(0,2);
    puVar2[0xd] = (char)iVar1;
    FUN_80073bd8(0x1d,(uint)(byte)(&DAT_8031b49c)[(uint)(byte)puVar2[0xd] * 5]);
    frontFn_80073c58();
  }
  return;
}


undefined SClevelcontrol_func0B(int param1) { //80255FBC
  return *(undefined *)(*(int *)(param1 + 0xb8) + 2);
}

