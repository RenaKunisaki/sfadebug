
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void LGTDirectionallight_initialise(undefined4 param) { //802CC360
  return;
}


/* @description Called when DLL is unloaded */

void LGTDirectionallight_release(void) { //802CC364
  return;
}


/* Library Function - Single Match
    LGTDirectional_func03
   
   Library: KioskDefault 0 0 */

void LGTDirectionallight_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802CC368
  Light *pLVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  if (*(int *)(puVar2 + 8) == 0) {
    pLVar1 = lightCreateAndAdd(this,true);
    *(Light **)(puVar2 + 8) = pLVar1;
    if (*(int *)(puVar2 + 8) == 0) {
                    
      OSPanic("LGTdirectionallight.c",0x77,s_Failed_assertion_lightData_>ligh_803259d8);
    }
    lightSetType(*(Light **)(puVar2 + 8),4);
  }
  lightFn_80076074(0.0,0.0,1.0,*(Light **)(puVar2 + 8));
  lightFn_80076438(*(Light **)(puVar2 + 8),objDef[1].allocatedSize,objDef[1].mapStates1,
                   objDef[1].loadFlags,0xff);
  lightFn_8007673c(*(Light **)(puVar2 + 8),objDef[1].mapStates2,objDef[1].bound,objDef[1].cullDist,
                   0xff);
  lightAnimFn_80076cdc
            (*(Light **)(puVar2 + 8),(uint)*(byte *)((int)&objDef[1].pos.y + 2),
             *(short *)((int)&objDef[1].id + 2));
  lightFn_80076548(*(Light **)(puVar2 + 8),*(undefined *)((int)&objDef[1].pos.y + 3),
                   *(undefined *)&objDef[1].pos.z,*(undefined *)((int)&objDef[1].pos.z + 1),0xff);
  lightFn_800767c4(*(Light **)(puVar2 + 8),*(byte *)((int)&objDef[1].pos.z + 2),
                   *(byte *)((int)&objDef[1].pos.z + 3),*(byte *)&objDef[1].id,0xff);
  return;
}


/* Library Function - Single Match
    LGTDirectional_func04
   
   Library: KioskDefault 0 0 */

void LGTDirectionallight_update(ObjInstance *this) { //802CC4AC
  short sVar1;
  short sVar2;
  byte *pbVar3;
  ObjDef *pOVar4;
  
  pbVar3 = this->state;
  pOVar4 = this->def;
  sVar1._0_1_ = pOVar4[2].allocatedSize;
  sVar1._1_1_ = pOVar4[2].mapStates1;
  (this->pos).rotation.x =
       (short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                           4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000) -
                          4503601774854144.0));
  sVar2._0_1_ = pOVar4[2].loadFlags;
  sVar2._1_1_ = pOVar4[2].mapStates2;
  (this->pos).rotation.y =
       (short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) -
                           4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000) -
                          4503601774854144.0));
  debugLightAdjust((short *)this,pbVar3);
  return;
}


/* @description Override hit detection */

void LGTDirectionallight_hitDetect(ObjInstance *this) { //802CC598
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void LGTDirectionallight_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802CC59C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* Library Function - Single Match
    LGTDirectional_func07
   
   Library: KioskDefault 0 0 */

void LGTDirectionallight_free(ObjInstance *this,int param2) { //802CC5E8
  lightFreeAndRemove(*(Light **)(this->state + 8));
  return;
}


undefined4 LGTDirectionallight_func08(ObjInstance *this) { //802CC620
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int LGTDirectionallight_getExtraSize(void) { //802CC628
  return 0x10;
}

