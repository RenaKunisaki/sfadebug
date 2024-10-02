
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void creator19D_initialise(undefined4 param) { //8023CEA8
  return;
}


/* @description Called when DLL is unloaded */

void creator19D_release(void) { //8023CEAC
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19D_func03
    dll_1D4_func03
   
   Library: KioskDefault 0 0 */

void creator19D_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8023CEB0
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].bound << 8);
  this->flags_0xf8 = 0;
  *puVar1 = 100;
  puVar1[1] = 0;
  this->opacity = 0xff;
  this->newOpacity = 0xff;
  return;
}


/* Library Function - Single Match
    dll_19D_func04
   
   Library: KioskDefault 0 0 */

void creator19D_update(ObjInstance *this) { //8023CF04
  byte bVar1;
  uint uVar2;
  LoadedDll *dll;
  ObjDef *def;
  ObjInstance *pOVar3;
  undefined *puVar4;
  short *psVar5;
  ObjDef *pOVar6;
  
  pOVar6 = this->def;
  psVar5 = (short *)this->state;
  uVar2 = mainGetBit(0x589);
  if (uVar2 != 0) {
    this->flags_0xf8 = 0;
    return;
  }
  if ((this->flags_0xf8 == 0) && (uVar2 = mainGetBit((char)pOVar6[1].cullDist + 0xf6), uVar2 != 0))
  {
    dll = (LoadedDll *)runlinkDownloadCode(0x102a,1);
    (**(code **)(dll->id + 4))(this,0,0,1,0xffffffff,0);
    (**(code **)(dll->id + 4))(this,1,0,1,0xffffffff,0);
    audioTryStartSfx((int *)this,1,0x1fe,0x7f,"creator.c",0x5a);
    DLL_free(dll);
    psVar5[1] = 1;
    this->flags_0xf8 = 1;
  }
  if (psVar5[1] != 0) {
    *psVar5 = *psVar5 - psVar5[1] * (short)(int)timeDelta;
  }
  if (0 < *psVar5) {
    return;
  }
  def = objAlloc(0x38,sharpclawGr);
  (def->pos).x = (pOVar6->pos).x;
  (def->pos).y = (pOVar6->pos).y;
  (def->pos).z = (pOVar6->pos).z;
  def->loadFlags = pOVar6->loadFlags;
  def->mapStates2 = pOVar6->mapStates2;
  def->bound = pOVar6->bound;
  def->cullDist = pOVar6->cullDist;
  *(undefined *)((int)&def[1].pos.y + 3) = 3;
  def[1].objType = GPSH_Shrine;
  def[2].objType = None;
  *(char *)((int)&def[1].pos.z + 2) = (char)((ushort)(this->pos).rotation.x >> 8);
  *(undefined *)((int)&def[1].pos.z + 3) = 2;
  uVar2 = mainGetBit(0xfc);
  if (uVar2 == 0) {
    *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
  }
  else {
    *(undefined2 *)((int)&def[1].pos.x + 2) = 0x49;
  }
  *(undefined *)((int)&def[1].pos.z + 1) = 0xff;
  *(undefined *)((int)&def[1].id + 2) = 0xff;
  def[2].loadFlags = 0xff;
  def[2].mapStates2 = 0xff;
  bVar1 = pOVar6[1].cullDist;
  if (bVar1 == 2) {
    def[2].allocatedSize = 4;
  }
  else if ((char)bVar1 < '\x02') {
    if (bVar1 == 0) {
      def[2].allocatedSize = 5;
    }
    else {
      if ((char)bVar1 < '\0') goto LAB_8023d150;
      def[2].allocatedSize = 3;
    }
  }
  else if ((char)bVar1 < '\x04') {
    def[2].allocatedSize = 3;
  }
  else {
LAB_8023d150:
    def[2].allocatedSize = 3;
  }
  pOVar3 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
  if ((pOVar3 != (ObjInstance *)0x0) && (puVar4 = pOVar3->state, puVar4 != (undefined *)0x0)) {
    bVar1 = pOVar6[1].cullDist;
    if (bVar1 == 2) {
      puVar4[0x3ac] = 0xa0;
    }
    else {
      if ((char)bVar1 < '\x02') {
        if (bVar1 == 0) {
          puVar4[0x3ac] = 0x20;
          goto LAB_8023d1f4;
        }
        if (-1 < (char)bVar1) {
          puVar4[0x3ac] = 0x20;
          goto LAB_8023d1f4;
        }
      }
      else if ((char)bVar1 < '\x04') {
        puVar4[0x3ac] = 0xa0;
        goto LAB_8023d1f4;
      }
      puVar4[0x3ac] = 0x20;
    }
  }
LAB_8023d1f4:
  *psVar5 = 100;
  psVar5[1] = 0;
  return;
}


/* @description Override hit detection */

void creator19D_hitDetect(ObjInstance *this) { //8023D218
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void creator19D_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8023D21C
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


/* @description Free object instance */

void creator19D_free(ObjInstance *this,int param2) { //8023D278
  return;
}


undefined4 creator19D_func08(ObjInstance *this) { //8023D27C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int creator19D_getExtraSize(void) { //8023D284
  return 4;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void creator1C4_initialise(undefined4 param) { //80240938
  return;
}


/* @description Called when DLL is unloaded */

void creator1C4_release(void) { //8024093C
  return;
}


/* Library Function - Single Match
    dll_1C4_func03
   
   Library: KioskDefault 0 0 */

void ECSH_Creator_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80240940
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].bound << 8);
  this->flags_0xf8 = 0;
  *puVar1 = 100;
  puVar1[1] = 0;
  this->opacity = 0xff;
  this->newOpacity = 0xff;
  puVar1[2] = objDef[1].objType;
  puVar1[4] = 2;
  puVar1[4] = puVar1[4] + (ushort)*(byte *)&objDef[1].pos.x;
  return;
}


/* Library Function - Single Match
    dll_1C4_func04
   
   Library: KioskDefault 0 0 */

void ECSH_Creator_update(ObjInstance *this) { //802409B4
  uint uVar1;
  LoadedDll *dll;
  ObjDef *def;
  ObjInstance *pOVar2;
  ObjDef *pOVar3;
  short *psVar4;
  
  pOVar3 = this->def;
  psVar4 = (short *)this->state;
  if ((this->flags_0xf8 == 0) && (uVar1 = mainGetBit((int)psVar4[2]), uVar1 != 0)) {
    dll = (LoadedDll *)runlinkDownloadCode(0x102a,1);
    (**(code **)(dll->id + 4))(this,0,0,1,0xffffffff,0);
    (**(code **)(dll->id + 4))(this,1,0,1,0xffffffff,0);
    audioTryStartSfx((int *)this,1,0x1fe,0x7f,"creator.c",0x51);
    DLL_free(dll);
    psVar4[1] = 1;
    this->flags_0xf8 = 1;
  }
  if (psVar4[1] != 0) {
    *psVar4 = *psVar4 - psVar4[1] * (ushort)framesThisStep;
  }
  if (*psVar4 < 1) {
    def = (ObjDef *)mmAlloc(0x38,OBJECTS_COL,"creat:badd");
    (def->pos).x = (pOVar3->pos).x;
    (def->pos).y = (pOVar3->pos).y;
    (def->pos).z = (pOVar3->pos).z;
    def->objType = sharpclawGr;
    def->id = -1;
    def->loadFlags = pOVar3->loadFlags;
    def->mapStates2 = pOVar3->mapStates2;
    def->bound = pOVar3->bound;
    def->cullDist = pOVar3->cullDist;
    *(undefined *)((int)&def[1].pos.y + 3) = 3;
    *(undefined *)&def[1].pos.z = 0;
    def[1].objType = psVar4[2] + (short)(char)pOVar3[1].cullDist;
    def[2].objType = None;
    *(char *)((int)&def[1].pos.z + 2) = (char)((ushort)(this->pos).rotation.x >> 8);
    *(undefined *)((int)&def[1].pos.z + 3) = 2;
    *(undefined2 *)&def[1].pos.x = 0;
    def[1].bound = 0;
    def[1].cullDist = 0;
    *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
    *(undefined *)((int)&def[1].pos.z + 1) = 0xff;
    *(undefined *)((int)&def[1].id + 2) = 0xff;
    *(undefined2 *)&def[1].pos.y = 0;
    *(undefined2 *)&def[1].id = 0;
    def[2].loadFlags = 0xff;
    def[2].mapStates2 = 0xff;
    def[1].allocatedSize = 0;
    def[1].mapStates1 = 0;
    def[2].allocatedSize = (byte)psVar4[4];
    pOVar2 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
    if (pOVar2 != (ObjInstance *)0x0) {
      pOVar2->state[0x3ac] = 0x20;
    }
    *psVar4 = 100;
    psVar4[1] = 0;
  }
  return;
}


/* @description Override hit detection */

void creator1C4_hitDetect(ObjInstance *this) { //80240C08
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void creator1C4_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80240C0C
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


/* @description Free object instance */

void creator1C4_free(ObjInstance *this,int param2) { //80240C68
  return;
}


undefined4 creator1C4_func08(ObjInstance *this) { //80240C6C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int creator1C4_getExtraSize(void) { //80240C74
  return 10;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void creator1C6_initialise(undefined4 param) { //80241BB8
  return;
}


/* @description Called when DLL is unloaded */

void creator1C6_release(void) { //80241BBC
  return;
}


/* Library Function - Single Match
    dll_1C6_func03
   
   Library: KioskDefault 0 0 */

void creator1C6_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80241BC0
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].bound << 8);
  this->flags_0xf8 = 0;
  *puVar2 = 100;
  puVar2[1] = 0;
  uVar1._0_1_ = objDef[1].allocatedSize;
  uVar1._1_1_ = objDef[1].mapStates1;
  *(char *)(puVar2 + 2) = (char)uVar1;
  printf("type %d",(int)(short)(ushort)*(byte *)(puVar2 + 2));
  *(undefined *)((int)puVar2 + 5) = 0;
  this->opacity = 0xff;
  this->newOpacity = 0xff;
  return;
}


/* Library Function - Single Match
    dll_1C6_func04
   
   Library: KioskDefault 0 0 */

void creator1C6_update(ObjInstance *this) { //80241C54
  undefined uVar1;
  uint uVar2;
  LoadedDll *pLVar3;
  ObjInstance *pOVar4;
  ObjDef *def;
  ObjDef *pOVar5;
  short *psVar6;
  
  pOVar5 = this->def;
  psVar6 = (short *)this->state;
  uVar2 = mainGetBit(0x5af);
  if (uVar2 != 0) {
    this->flags_0xf8 = 0;
    *psVar6 = 100;
    psVar6[1] = 0;
    *(undefined *)((int)psVar6 + 5) = 0;
    this->opacity = 0xff;
    this->newOpacity = 0xff;
  }
  if (*(char *)((int)psVar6 + 5) == '\0') {
    if (((*(char *)(psVar6 + 2) == '\x06') && (this->flags_0xf8 == 0)) &&
       (uVar2 = mainGetBit(0x5ac), uVar2 != 0)) {
      pLVar3 = (LoadedDll *)runlinkDownloadCode(0x102a,1);
      (**(code **)(pLVar3->id + 4))(this,3,0,1,0xffffffff,0);
      (**(code **)(pLVar3->id + 4))(this,4,0,1,0xffffffff,0);
      audioStartSfx((int **)this,0x1fe,0x7f,0x40,"creator.c",0x7c);
      DLL_free(pLVar3);
      psVar6[1] = 1;
      this->flags_0xf8 = 1;
    }
    else if ((this->flags_0xf8 == 0) && (uVar2 = mainGetBit(0x148), uVar2 != 0)) {
      pLVar3 = (LoadedDll *)runlinkDownloadCode(0x102a,1);
      (**(code **)(pLVar3->id + 4))(this,3,0,1,0xffffffff,0);
      (**(code **)(pLVar3->id + 4))(this,4,0,1,0xffffffff,0);
      audioStartSfx((int **)this,0x1fe,0x7f,0x40,"creator.c",0x88);
      DLL_free(pLVar3);
      psVar6[1] = 1;
      this->flags_0xf8 = 1;
    }
    if (psVar6[1] != 0) {
      *psVar6 = *psVar6 - psVar6[1] * (ushort)framesThisStep;
    }
    if (*(char *)(psVar6 + 2) == '\x06') {
      if (*psVar6 < 1) {
        def = objAlloc(0x24,0x404);
        (def->pos).x = (pOVar5->pos).x;
        (def->pos).y = (pOVar5->pos).y + 50.0;
        (def->pos).z = (pOVar5->pos).z;
        def->objType = 0x404;
        def->id = -1;
        def->loadFlags = pOVar5->loadFlags;
        def->mapStates2 = pOVar5->mapStates2;
        def->bound = pOVar5->bound;
        def->cullDist = pOVar5->cullDist;
        def[1].allocatedSize = 0xff;
        def[1].mapStates1 = 0xc4;
        objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
        *psVar6 = 100;
        psVar6[1] = 0;
      }
    }
    else if (*psVar6 < 1) {
      pOVar5 = objAlloc(0x24,*(byte *)(psVar6 + 2) + GPSHpickobj);
      *(undefined *)((int)psVar6 + 5) = 1;
      pOVar5->cullDist = 0xff;
      pOVar5->loadFlags = isBlockObject;
      pOVar5->mapStates2 = 2;
      (pOVar5->pos).x = (this->pos).pos.x;
      (pOVar5->pos).y = (this->pos).pos.y;
      (pOVar5->pos).z = (this->pos).pos.z;
      pOVar5->objType = *(byte *)(psVar6 + 2) + GPSHpickobj;
      *(char *)&pOVar5[1].objType = (char)((ushort)(this->pos).rotation.x >> 8);
      uVar1 = *(undefined *)((int)(&DAT_80319b00 + (uint)*(byte *)(psVar6 + 2) * 2) + 1);
      pOVar5[1].allocatedSize = *(&DAT_80319b00 + (uint)*(byte *)(psVar6 + 2) * 2);
      pOVar5[1].mapStates1 = uVar1;
      pOVar4 = objInstantiateCharacter(pOVar5,5,(int)(char)this->mapId,-1,this->pMatrix);
      pOVar4->curModel = 0;
      *psVar6 = 100;
      psVar6[1] = 0;
    }
  }
  return;
}


/* @description Override hit detection */

void creator1C6_hitDetect(ObjInstance *this) { //80241FDC
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void creator1C6_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80241FE0
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


/* @description Free object instance */

void creator1C6_free(ObjInstance *this,int param2) { //8024203C
  return;
}


undefined4 creator1C6_func08(ObjInstance *this) { //80242040
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int creator1C6_getExtraSize(void) { //80242048
  return 6;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void creator1CF_initialise(undefined4 param) { //80246B9C
  return;
}


/* @description Called when DLL is unloaded */

void creator1CF_release(void) { //80246BA0
  return;
}


/* Library Function - Single Match
    dll_1CF_func03
   
   Library: KioskDefault 0 0 */

void creator1CF_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80246BA4
  short *psVar1;
  
  psVar1 = (short *)this->state;
  psVar1[1] = *(short *)&objDef[1].allocatedSize;
  psVar1[2] = *(short *)&objDef[1].loadFlags;
  *psVar1 = (short)*(char *)&objDef[1].objType;
  if (5 < *psVar1) {
    *psVar1 = 5;
  }
  *(undefined *)(psVar1 + 4) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined *)((int)psVar1 + 9) = 0;
  psVar1[3] = *(short *)&objDef[1].bound;
  this->opacity = 0xff;
  this->newOpacity = 0xff;
  (this->pos).scale = 0.25;
  return;
}


/* Library Function - Single Match
    dll_1CF_func04
   
   Library: KioskDefault 0 0 */

void creator1CF_update(ObjInstance *this) { //80246C1C
  uint uVar1;
  int iVar2;
  ObjDef *pOVar3;
  short sVar4;
  byte bVar5;
  short sVar6;
  ObjDef *pOVar7;
  short *psVar8;
  undefined auStack_54 [12];
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  pOVar7 = this->def;
  psVar8 = (short *)this->state;
  bVar5 = 0;
  if (((*(char *)((int)psVar8 + 9) == '\0') && (psVar8[3] != -1)) &&
     (uVar1 = mainGetBit((int)psVar8[3]), uVar1 != 0)) {
    if (*(byte *)(psVar8 + 4) < 2) {
      audioStartSfx((int **)0x0,0x211,0x7f,0x40,"creator.c",0x52);
      sVar6 = 0;
      while (sVar6 < *psVar8) {
        if ((*(char *)(psVar8 + 4) == '\0') && ((bVar5 < 5 || (iVar2 = randInt(0,3), iVar2 == 0))))
        {
          pOVar3 = objAlloc(0x24,0x221);
          uStack_24 = randInt(-(int)psVar8[1],(int)psVar8[1]);
          uStack_24 = uStack_24 ^ 0x80000000;
          local_28 = 0x43300000;
          (pOVar3->pos).x =
               (this->pos).pos.x +
               (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
          uStack_2c = randInt(0,0x3c);
          uStack_2c = uStack_2c ^ 0x80000000;
          local_30 = 0x43300000;
          (pOVar3->pos).y =
               (this->pos).pos.y + 140.0 +
               (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0);
          uStack_34 = randInt(-(int)psVar8[2],(int)psVar8[2]);
          uStack_34 = uStack_34 ^ 0x80000000;
          local_38 = 0x43300000;
          (pOVar3->pos).z =
               (this->pos).pos.z +
               (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0);
          pOVar3[1].allocatedSize = 0;
          pOVar3[1].mapStates1 = 0;
          pOVar3[1].loadFlags = 0;
          pOVar3[1].mapStates2 = 0;
          pOVar3->loadFlags = pOVar7->loadFlags;
          pOVar3->mapStates2 = pOVar7->mapStates2;
          pOVar3->bound = pOVar7->bound;
          pOVar3->cullDist = pOVar7->cullDist;
          pOVar3[1].bound = 0xff;
          pOVar3[1].cullDist = 0xff;
          *(char *)&pOVar3[1].objType = (char)((ushort)(this->pos).rotation.x >> 8);
          objInstantiateCharacter(pOVar3,5,(int)(char)this->mapId,-1,this->pMatrix);
          bVar5 = bVar5 + 1;
        }
        sVar6 = sVar6 + 1;
        iVar2 = randInt(0xc,0xf);
        sVar4 = (short)iVar2;
        iVar2 = randInt(0,3);
        if (iVar2 == 0) {
          for (; sVar4 != 0; sVar4 = sVar4 + -1) {
            uStack_34 = randInt(-(int)psVar8[1],(int)psVar8[1]);
            uStack_34 = uStack_34 ^ 0x80000000;
            local_38 = 0x43300000;
            local_48 = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0);
            uStack_2c = randInt(-(int)psVar8[2],(int)psVar8[2]);
            uStack_2c = uStack_2c ^ 0x80000000;
            local_30 = 0x43300000;
            local_40 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0);
            local_44 = (this->pos).pos.y + 160.0;
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x280,auStack_54,&DAT_00010002,0xffffffff,0)
            ;
          }
        }
      }
    }
    else {
      pOVar3 = objAlloc(0x24,0x412);
      (pOVar3->pos).x = (this->pos).pos.x;
      (pOVar3->pos).y = (this->pos).pos.y;
      (pOVar3->pos).z = (this->pos).pos.z;
      pOVar3[1].allocatedSize = 0;
      pOVar3[1].mapStates1 = 0;
      pOVar3[1].loadFlags = 0;
      pOVar3[1].mapStates2 = 0;
      pOVar3->loadFlags = pOVar7->loadFlags;
      pOVar3->mapStates2 = pOVar7->mapStates2;
      pOVar3->bound = pOVar7->bound;
      pOVar3->cullDist = pOVar7->cullDist;
      pOVar3[1].bound = 0xff;
      pOVar3[1].cullDist = 0xff;
      *(char *)&pOVar3[1].objType = (char)((ushort)(this->pos).rotation.x >> 8);
      objInstantiateCharacter(pOVar3,5,(int)(char)this->mapId,-1,this->pMatrix);
      *(undefined *)((int)psVar8 + 9) = 1;
    }
  }
  return;
}


/* @description Override hit detection */

void creator1CF_hitDetect(ObjInstance *this) { //80246F80
  return;
}


/* @description Override render */

void creator1CF_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80246F84
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (bVar1 = checkSomeDebugFlags_8017c4f8(), bVar1)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void creator1CF_free(ObjInstance *this,int param2) { //80246FEC
  return;
}


undefined4 creator1CF_func08(ObjInstance *this) { //80246FF0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int creator1CF_getExtraSize(void) { //80246FF8
  return 10;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void creator1D4_initialise(undefined4 param) { //80248B64
  return;
}


/* @description Called when DLL is unloaded */

void creator1D4_release(void) { //80248B68
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19D_func03
    dll_1D4_func03
   
   Library: KioskDefault 0 0 */

void creator1D4_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80248B6C
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].bound << 8);
  this->flags_0xf8 = 0;
  *puVar1 = 100;
  puVar1[1] = 0;
  this->opacity = 0xff;
  this->newOpacity = 0xff;
  return;
}


/* Library Function - Single Match
    dll_1D4_func04
   
   Library: KioskDefault 0 0 */

void creator1D4_update(ObjInstance *this) { //80248BC0
  uint uVar1;
  LoadedDll *dll;
  ObjDef *def;
  ObjInstance *pOVar2;
  short *psVar3;
  ObjDef *pOVar4;
  
  pOVar4 = this->def;
  psVar3 = (short *)this->state;
  uVar1 = mainGetBit(0x5b9);
  if (uVar1 == 0) {
    if ((this->flags_0xf8 == 0) &&
       (uVar1 = mainGetBit((char)pOVar4[1].cullDist + 0x1cd), uVar1 != 0)) {
      dll = (LoadedDll *)runlinkDownloadCode(0x102a,1);
      (**(code **)(dll->id + 4))(this,0,0,1,0xffffffff,0);
      (**(code **)(dll->id + 4))(this,1,0,1,0xffffffff,0);
      audioTryStartSfx((int *)this,1,0x1fe,0x7f,"creator.c",0x59);
      DLL_free(dll);
      psVar3[1] = 1;
      this->flags_0xf8 = 1;
    }
    if (psVar3[1] != 0) {
      *psVar3 = *psVar3 - psVar3[1] * (ushort)framesThisStep;
    }
    if (*psVar3 < 1) {
      def = objAlloc(0x38,0x2d0);
      (def->pos).x = (pOVar4->pos).x;
      (def->pos).y = (pOVar4->pos).y;
      (def->pos).z = (pOVar4->pos).z;
      def->loadFlags = pOVar4->loadFlags;
      def->mapStates2 = pOVar4->mapStates2;
      def->bound = pOVar4->bound;
      def->cullDist = pOVar4->cullDist;
      *(undefined *)((int)&def[1].pos.y + 3) = 1;
      def[1].objType = GPSH_Shrine;
      def[2].objType = None;
      *(char *)((int)&def[1].pos.z + 2) = (char)((ushort)(this->pos).rotation.x >> 8);
      *(undefined *)((int)&def[1].pos.z + 3) = 2;
      uVar1 = mainGetBit(0x1ce);
      if (uVar1 == 0) {
        *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
      }
      else {
        *(undefined2 *)((int)&def[1].pos.x + 2) = 0x49;
      }
      *(undefined *)((int)&def[1].pos.z + 1) = 0xff;
      *(undefined *)((int)&def[1].id + 2) = 0xff;
      def[2].allocatedSize = pOVar4[1].cullDist;
      pOVar2 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
      if ((pOVar2 != (ObjInstance *)0x0) && (pOVar2->state != (undefined *)0x0)) {
        pOVar2->state[0x3ac] = 0x20;
      }
      *psVar3 = 100;
      psVar3[1] = 0;
    }
  }
  else {
    this->flags_0xf8 = 0;
    *psVar3 = 100;
    psVar3[1] = 0;
    this->opacity = 0xff;
    this->newOpacity = 0xff;
  }
  return;
}


/* @description Override hit detection */

void creator1D4_hitDetect(ObjInstance *this) { //80248E20
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void creator1D4_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80248E24
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


/* @description Free object instance */

void creator1D4_free(ObjInstance *this,int param2) { //80248E80
  return;
}


undefined4 creator1D4_func08(ObjInstance *this) { //80248E84
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int creator1D4_getExtraSize(void) { //80248E8C
  return 4;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void creator1D6_initialise(undefined4 param) { //80249C28
  return;
}


/* @description Called when DLL is unloaded */

void creator1D6_release(void) { //80249C2C
  return;
}


/* Library Function - Single Match
    dll_1D6_func03
   
   Library: KioskDefault 0 0 */

void creator1D6_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80249C30
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].bound << 8);
  this->flags_0xf8 = 0;
  *(undefined2 *)(puVar1 + 1) = 100;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  *puVar1 = 0;
  this->opacity = 0xff;
  this->newOpacity = 0xff;
  return;
}


/* Library Function - Single Match
    dll_1D6_func04
   
   Library: KioskDefault 0 0 */

void creator1D6_update(ObjInstance *this) { //80249C8C
  uint uVar1;
  LoadedDll *dll;
  ObjDef *def;
  undefined *puVar2;
  ObjDef *pOVar3;
  
  pOVar3 = this->def;
  puVar2 = this->state;
  if ((this->flags_0xf8 != 0) && (uVar1 = mainGetBit(0x1d4), uVar1 != 0)) {
    this->flags_0xf8 = 0;
  }
  if ((this->flags_0xf8 == 0) && (uVar1 = mainGetBit(0x1d3), uVar1 != 0)) {
    dll = (LoadedDll *)runlinkDownloadCode(0x102a,1);
    (**(code **)(dll->id + 4))(this,0,0,1,0xffffffff,0);
    (**(code **)(dll->id + 4))(this,1,0,1,0xffffffff,0);
    audioStartSfx((int **)0x0,0x1fe,0x7f,0x40,"creator.c",0x51);
    DLL_free(dll);
    *(undefined2 *)(puVar2 + 6) = 1;
    this->flags_0xf8 = 1;
  }
  if (*(short *)(puVar2 + 6) != 0) {
    *(ushort *)(puVar2 + 4) =
         *(short *)(puVar2 + 4) - *(short *)(puVar2 + 6) * (ushort)framesThisStep;
  }
  if ((*(short *)(puVar2 + 4) < 1) && (pOVar3[1].cullDist == 0)) {
    def = objAlloc(0x18,0x248);
    (def->pos).x = (pOVar3->pos).x;
    (def->pos).y = (pOVar3->pos).y + 50.0;
    (def->pos).z = (pOVar3->pos).z;
    def->objType = 0x248;
    def->id = -1;
    def->loadFlags = pOVar3->loadFlags;
    def->mapStates2 = pOVar3->mapStates2;
    def->bound = pOVar3->bound;
    def->cullDist = pOVar3->cullDist;
    objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
    *(undefined2 *)(puVar2 + 4) = 100;
    *(undefined2 *)(puVar2 + 6) = 0;
  }
  return;
}


/* @description Override hit detection */

void creator1D6_hitDetect(ObjInstance *this) { //80249E64
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void creator1D6_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80249E68
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


/* @description Free object instance */

void creator1D6_free(ObjInstance *this,int param2) { //80249EC4
  return;
}


undefined4 creator1D6_func08(ObjInstance *this) { //80249EC8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int creator1D6_getExtraSize(void) { //80249ED0
  return 8;
}

