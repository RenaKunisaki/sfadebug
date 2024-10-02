
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void LGTpointlight_initialise(undefined4 param) { //802CB828
  return;
}


/* @description Called when DLL is unloaded */

void LGTpointlight_release(void) { //802CB82C
  return;
}


/* Library Function - Single Match
    dll_2F5_func03
   
   Library: KioskDefault 0 0 */

void LGTpointlight_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802CB830
  ushort uVar1;
  uint uVar2;
  Light *pLVar3;
  Texture *pTVar4;
  Light **ppLVar5;
  
  ppLVar5 = (Light **)this->state;
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  if (*ppLVar5 == (Light *)0x0) {
    pLVar3 = lightCreateAndAdd(this,true);
    *ppLVar5 = pLVar3;
    if (*ppLVar5 == (Light *)0x0) {
                    
      OSPanic("LGTpointlight.c",0x78,s_Failed_assertion_lightData_>ligh_80325900);
    }
    lightSetType(*ppLVar5,2);
  }
  lightFn_80075f4c(0.0,0.0,0.0,*ppLVar5);
  lightFn_80076438(*ppLVar5,objDef[1].allocatedSize,objDef[1].mapStates1,objDef[1].loadFlags,0xff);
  lightFn_8007673c(*ppLVar5,objDef[1].mapStates2,objDef[1].bound,objDef[1].cullDist,0xff);
  lightFn_800761b4((double)(float)((double)CONCAT44(0x43300000,
                                                    (uint)*(ushort *)((int)&objDef[1].pos.x + 2)) -
                                  4503599627370496.0),
                   (double)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].pos.y) -
                                   4503599627370496.0) / 255.0),*ppLVar5,
                   (uint)*(byte *)((int)&objDef[1].pos.y + 1));
  if (*(byte *)&objDef[1].pos.x < 0x5a) {
    uVar2 = (uint)*(byte *)&objDef[1].pos.x;
  }
  else {
    uVar2 = 0x5a;
  }
  lightFn_800765c0((double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                                  4503601774854144.0),*ppLVar5,
                   (uint)*(byte *)((int)&objDef[1].pos.x + 1));
  lightFn_80076324(*ppLVar5,*(byte *)&objDef[2].objType);
  lightAnimFn_80076cdc
            (*ppLVar5,(uint)*(byte *)((int)&objDef[1].pos.y + 2),*(short *)((int)&objDef[1].id + 2))
  ;
  lightFn_80076548(*ppLVar5,*(undefined *)((int)&objDef[1].pos.y + 3),*(undefined *)&objDef[1].pos.z
                   ,*(undefined *)((int)&objDef[1].pos.z + 1),0xff);
  lightFn_800767c4(*ppLVar5,*(byte *)((int)&objDef[1].pos.z + 2),
                   *(byte *)((int)&objDef[1].pos.z + 3),*(byte *)&objDef[1].id,0xff);
  lightFn_80076074(0.0,0.0,1.0,*ppLVar5);
  if (*(char *)((int)&objDef[1].pos.x + 1) == '\0') {
    objSetModelNo(this,0);
  }
  else {
    objSetModelNo(this,1);
  }
  (*ppLVar5)->field_0x29c = *(undefined *)((int)&objDef[2].pos.y + 2);
  if (*(short *)&objDef[2].pos.x == 0) {
    getShadowTexture((Texture **)&(*ppLVar5)->field464_0x290);
  }
  else {
    pTVar4 = textureLoadAsset((uint)*(ushort *)&objDef[2].pos.x);
    (*ppLVar5)->field464_0x290 = pTVar4;
  }
  (*ppLVar5)->field_0x294 = *(undefined *)((int)&objDef[2].pos.x + 2);
  (*ppLVar5)->field_0x295 = *(undefined *)((int)&objDef[2].pos.x + 3);
  (*ppLVar5)->field_0x296 = *(undefined *)&objDef[2].pos.y;
  (*ppLVar5)->field_0x297 = *(undefined *)((int)&objDef[2].pos.y + 1);
  uVar1._0_1_ = objDef[2].bound;
  uVar1._1_1_ = objDef[2].cullDist;
  *(float *)&(*ppLVar5)->field_0x298 =
       (float)((double)CONCAT44(0x43300000,(uint)uVar1) - 4503599627370496.0);
  (*ppLVar5)->field_0x29d = 0xff;
  (*ppLVar5)->field_0x29e = 0;
  Object_objAddObjectType(this,0x37);
  return;
}


/* Library Function - Single Match
    dll_2F5_func04
   
   Library: KioskDefault 0 0 */

void LGTpointlight_update(ObjInstance *this) { //802CBAF8
  short sVar1;
  ObjDef *pOVar2;
  short sVar3;
  int *piVar4;
  
  pOVar2 = this->def;
  piVar4 = (int *)this->state;
  sVar3._0_1_ = pOVar2[2].allocatedSize;
  sVar3._1_1_ = pOVar2[2].mapStates1;
  (this->pos).rotation.x =
       (short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) -
                           4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000) -
                          4503601774854144.0));
  sVar1._0_1_ = pOVar2[2].loadFlags;
  sVar1._1_1_ = pOVar2[2].mapStates2;
  (this->pos).rotation.y =
       (short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                           4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000) -
                          4503601774854144.0));
  if (*(char *)(*piVar4 + 0x29c) != '\0') {
    if (*(char *)(*piVar4 + 0x4c) != '\0') {
      sVar3 = (ushort)*(byte *)(*piVar4 + 0x29d) + (short)*(char *)(*piVar4 + 0x29e);
      if (sVar3 < 0) {
        sVar3 = 0;
        *(undefined *)(*piVar4 + 0x29e) = 0;
      }
      else if (0xff < sVar3) {
        sVar3 = 0xff;
        *(undefined *)(*piVar4 + 0x29e) = 0;
      }
      *(char *)(*piVar4 + 0x29d) = (char)sVar3;
    }
  }
  return;
}


/* @description Override hit detection */

void LGTpointlight_hitDetect(ObjInstance *this) { //802CBC3C
  return;
}


/* Library Function - Single Match
    dll_2F5_func06
   
   Library: KioskDefault 0 0 */

void LGTpointlight_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802CBC40
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjState_LGTpointlight *glow;
  
  glow = (ObjState_LGTpointlight *)this->state;
  if ((glow->glow->field_0x29c != '\0') && (glow->glow->field_0x4c != '\0')) {
    lightGlowAdd(glow->glow);
  }
  iVar1 = isModelAnimDisabled();
  if (iVar1 != 0) {
    if (((this->pos).flags & 0x100) != 0) {
      FUN_802cbdd8(this);
      FUN_802cc22c((int)this,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3));
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_2F5_func07
   
   Library: KioskDefault 0 0 */

void LGTpointlight_free(ObjInstance *this,int param2) { //802CBCF0
  Light **ppLVar1;
  
  ppLVar1 = (Light **)this->state;
  if (*(short *)&this->def[2].pos.x != 0) {
    texFreeTexture((Texture *)(*ppLVar1)->field464_0x290);
  }
  lightFreeAndRemove(*ppLVar1);
  Object_removePlayerObj(this,0x37);
  return;
}


undefined4 LGTpointlight_func08(ObjInstance *this) { //802CBD4C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int LGTpointlight_getExtraSize(void) { //802CBD54
  return 4;
}


/* Library Function - Single Match
    LGTpointlightFn_802cbd5c
   
   Library: KioskDefault 0 0 */

void LGTpointlightFn_802cbd5c(int param1,byte param2) { //802CBD5C
  if (param1 == 0) {
                    
    OSPanic("LGTpointlight.c",0x160,"Failed assertion object");
  }
  if (*(Light ***)(param1 + 0xb8) == (Light **)0x0) {
                    
    OSPanic("LGTpointlight.c",0x161,"Failed assertion lightData");
  }
  lightFn_80076324(**(Light ***)(param1 + 0xb8),param2);
  return;
}

