
/* Library Function - Single Match
    lightFn_800750ac
   
   Library: KioskDefault 0 0 */

Light * lightCreateAndAdd(ObjInstance *obj,bool bAdd) { //800750AC
  Light *pOVar1;
  uint uVar1;
  
  pOVar1 = lightCreateForObject(obj);
  if (bAdd) {
    if (0x31 < numLightsInList) {
                    
      OSPanic("light.c",0x7c,"Failed assertion numLightsInList<MAX_LIGHTS_IN_LIST");
    }
    uVar1 = (uint)numLightsInList;
    numLightsInList = numLightsInList + 1;
    (&lights)[uVar1] = pOVar1;
  }
  return pOVar1;
}


/* Library Function - Single Match
    lightFn_80075138
   
   Library: KioskDefault 0 0 */

void lightFreeAndRemove(Light *light) { //80075138
  int iVar1;
  
  for (iVar1 = 0; (iVar1 < (int)(uint)numLightsInList && ((&lights)[iVar1] != light));
      iVar1 = iVar1 + 1) {
  }
  if (iVar1 < (int)(uint)numLightsInList) {
    for (; iVar1 < (int)(numLightsInList - 1); iVar1 = iVar1 + 1) {
      (&lights)[iVar1] = (&lights)[iVar1 + 1];
    }
    numLightsInList = numLightsInList - 1;
    lightFree(light);
    return;
  }
                    
  OSPanic("light.c",0xa6,s_Failed_assertion_i<numLightsInLi_802ea85c);
}


/* Library Function - Single Match
    lightFn_800751f8
   
   Library: KioskDefault 0 0 */

void lightMtxFn_800751f8(void) { //800751F8
  Mtx44 *m;
  Mtx44 *b;
  int iVar1;
  Light *light;
  Mtx43 aMStack_90 [2];
  
  m = getCameraMtxs();
  iVar1 = 0;
  do {
    if ((int)(uint)numLightsInList <= iVar1) {
      return;
    }
    light = (&lights)[iVar1];
    if (light->field15_0x4c != 0) {
      if ((undefined *)light->type != &DAT_00000004) {
        if (light->parent != (ObjInstance *)0x0) {
          FUN_80085be4(light->parent,&light->field1_0x4,&light->field2_0x10);
        }
        MTXMultVecMapCoord(&light->field2_0x10,&light->field3_0x1c,(Mtx43 *)m);
      }
      if (light->parent != (ObjInstance *)0x0) {
        lightVecFn_80085c50(light->parent,&light->field4_0x28,&light->field5_0x34);
      }
      FUN_80077224(&(light->field5_0x34).x,(float *)&light->field6_0x40,&m->m11);
      if (light->animType != 0) {
        lightRandFn_8001d168((int)light);
      }
      if (light->type == 8) {
        if (light->parent == (ObjInstance *)0x0) {
                    
          OSPanic("light.c",0xed,s_Failed_assertion_light_>parent_802ea880);
        }
        objModelMtxFn_80085ab8(light->parent,&light->modelMatrix);
        b = FUN_80069260();
        MTXConcat(&light->modelMatrix,(Mtx43 *)b,aMStack_90);
        MTXConcat((Mtx43 *)&light->field231_0x198,aMStack_90,(Mtx43 *)&light->field_0x1d8);
      }
    }
    iVar1 = iVar1 + 1;
  } while( true );
}


/* Library Function - Single Match
    lightFn_80075370
   
   Library: KioskDefault 0 0 */

void lightControlGetLightsNearObject(int param1,int param2,int maxLights,int *param4,uint param5) { //80075370
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int numContributingLights;
  int iVar5;
  Light *unaff_r31;
  double dVar6;
  int local_b8;
  Light *contributing [21];
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_27();
  if (8 < maxLights) {
                    
    OSPanic("light.c",0x141,s_Failed_assertion_maxLights<_MAX__802ea8d4);
  }
  numContributingLights = 0;
  iVar5 = 0;
  do {
    if ((int)(uint)numLightsInList <= iVar5) {
      local_b8 = maxLights;
      if (numContributingLights < maxLights) {
        local_b8 = numContributingLights;
      }
      *param4 = 0;
      while (*param4 < local_b8) {
        fVar3 = 0.0;
        for (iVar5 = 0; iVar5 < numContributingLights; iVar5 = iVar5 + 1) {
          if (fVar3 < *(float *)&contributing[iVar5]->field_0x120) {
            fVar3 = *(float *)&contributing[iVar5]->field_0x120;
            unaff_r31 = contributing[iVar5];
          }
        }
        iVar5 = *param4;
        *param4 = iVar5 + 1;
        *(Light **)(param2 + iVar5 * 4) = unaff_r31;
        *(float *)&unaff_r31->field_0x120 = 0.0;
      }
      _restfpr_27();
      return;
    }
    unaff_r31 = (&lights)[iVar5];
    if ((unaff_r31->field15_0x4c != 0) && ((unaff_r31->type & param5) != 0)) {
      if (unaff_r31->type == 4) {
        *(float *)&unaff_r31->field_0x120 = 1000.0;
      }
      else if (unaff_r31->type == 8) {
        uVar4 = FUN_800774f8((int)unaff_r31,param1);
        if ((uVar4 & 0xff) == 0) {
          *(float *)&unaff_r31->field_0x120 = 0.0;
        }
        else {
          *(float *)&unaff_r31->field_0x120 = 1000.0;
        }
      }
      else {
        dVar6 = (double)FUN_800773a0((int)unaff_r31,param1);
        uStack_44 = (uint)unaff_r31->field85_0x98;
        local_48 = 0x43300000;
        fVar3 = (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)unaff_r31->field85_0x98) -
                                               4503599627370496.0));
        if (0.0 <= fVar3) {
          if (255.0 < fVar3) {
            fVar3 = 255.0;
          }
        }
        else {
          fVar3 = 0.0;
        }
        uStack_4c = (uint)unaff_r31->field86_0x99;
        local_50 = 0x43300000;
        fVar1 = (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)unaff_r31->field86_0x99) -
                                               4503599627370496.0));
        if (0.0 <= fVar1) {
          if (255.0 < fVar1) {
            fVar1 = 255.0;
          }
        }
        else {
          fVar1 = 0.0;
        }
        uStack_54 = (uint)unaff_r31->field87_0x9a;
        local_58 = 0x43300000;
        fVar2 = (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)unaff_r31->field87_0x9a) -
                                               4503599627370496.0));
        if (0.0 <= fVar2) {
          if (255.0 < fVar2) {
            fVar2 = 255.0;
          }
        }
        else {
          fVar2 = 0.0;
        }
        if (fVar1 < fVar3) {
          fVar1 = fVar3;
        }
        *(float *)&unaff_r31->field_0x120 = fVar1;
        if (fVar2 < *(float *)&unaff_r31->field_0x120) {
          fVar2 = *(float *)&unaff_r31->field_0x120;
        }
        *(float *)&unaff_r31->field_0x120 = fVar2;
      }
      if (20.0 < *(float *)&unaff_r31->field_0x120) {
        if (0x13 < numContributingLights) {
                    
          OSPanic("light.c",0x171,"Failed assertion numContributingLights<MAX_LIGHTS_CONTRIBUTING");
        }
        contributing[numContributingLights] = unaff_r31;
        numContributingLights = numContributingLights + 1;
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}


/* Library Function - Single Match
    lightFn_800756a0
   
   Library: KioskDefault 0 0 */

void lightFn_800756a0(void) { //800756A0
  uint mask;
  int param1;
  
  mask = 0;
  param1 = 0;
  while( true ) {
    if (5 < param1) break;
    if ((&channelInfo)[param1 * 0x10] != '\0') {
      if ((&DAT_80352e90)[param1 * 4] == 0) {
        GXSetChanCtrl(param1,(uint)((&DAT_80352e8c)[param1 * 4] != 0),0,(&DAT_80352e94)[param1 * 4],
                      (&DAT_80352e8c)[param1 * 4],2,1);
      }
      else {
        GXSetChanCtrl(param1,(uint)((&DAT_80352e8c)[param1 * 4] != 0),0,(&DAT_80352e94)[param1 * 4],
                      (&DAT_80352e8c)[param1 * 4],0,0);
      }
      mask = mask | 1 << param1;
    }
    param1 = param1 + 1;
  }
  if ((mask & 0x2a) == 0) {
    if ((mask & 0x15) == 0) {
      GXSetNumChans(0);
    }
    else {
      GXSetNumChans(1);
    }
  }
  else {
    if ((mask & 0x15) == 0) {
                    
      OSPanic("light.c",0x1da,"Failed assertion mask&channelOneMask");
    }
    GXSetNumChans(2);
  }
  return;
}


/* Library Function - Single Match
    lightFn_800757ec
   
   Library: KioskDefault 0 0 */

void lightFn_800757ec(int channelID,undefined4 param2,undefined4 param3) { //800757EC
  if ((channelID < 0) || (5 < channelID)) {
                    
    OSPanic("light.c",0x1f8,s_Failed_assertion_channelID>_GX_C_802ea9a0);
  }
  if ((&channelInfo)[channelID * 0x10] != '\0') {
                    
    OSPanic("light.c",0x1f9,"Failed assertion !channelInfo[channelID].set");
  }
  if (channelID != 3) {
    if (2 < channelID) {
      if (channelID == 5) {
        if (DAT_80352e98 != '\0') {
                    
          OSPanic("light.c",0x20a,"Failed assertion !channelInfo[GX_COLOR1].set");
        }
        if (DAT_80352eb8 != '\0') {
                    
          OSPanic("light.c",0x20b,"Failed assertion !channelInfo[GX_ALPHA1].set");
        }
      }
      else if (channelID < 5) {
        if (channelInfo != '\0') {
                    
          OSPanic("light.c",0x206,"Failed assertion !channelInfo[GX_COLOR0].set");
        }
        if (DAT_80352ea8 != '\0') {
                    
          OSPanic("light.c",0x207,"Failed assertion !channelInfo[GX_ALPHA0].set");
        }
      }
      goto LAB_80075964;
    }
    if (channelID != 1) {
      if (((0 < channelID) || (-1 < channelID)) && (DAT_80352ec8 != '\0')) {
                    
        OSPanic("light.c",0x1ff,"Failed assertion !channelInfo[GX_COLOR0A0].set");
      }
      goto LAB_80075964;
    }
  }
  if (DAT_80352ed8 != '\0') {
                    
    OSPanic("light.c",0x203,"Failed assertion !channelInfo[GX_COLOR1A1].set");
  }
LAB_80075964:
  (&DAT_80352e90)[channelID * 4] = param2;
  (&DAT_80352e8c)[channelID * 4] = 0;
  (&DAT_80352e94)[channelID * 4] = param3;
  (&channelInfo)[channelID * 0x10] = 1;
  return;
}


/* Library Function - Single Match
    lightFn_800759b8
   
   Library: KioskDefault 0 0 */

void lightFn_800759b8(int channelID,int param2,ObjInstance *param3) { //800759B8
  if (0x80 < (int)lightId_803988cc) {
                    
    OSPanic("light.c",0x229,s_Failed_assertion_lightID<_GX_LIG_802eab30);
  }
  if ((-1 < channelID) && (channelID < 6)) {
    if ((&channelInfo)[channelID * 0x10] == '\0') {
                    
      OSPanic("light.c",0x22b,"Failed assertion channelInfo[channelID].set");
    }
    if ((&DAT_80352e90)[channelID * 4] == 0) {
      lightFn_80075ac0(param2,param3,lightId_803988cc);
    }
    else {
      lightFn_80075c54(param2,param3,lightId_803988cc);
    }
    (&DAT_80352e8c)[channelID * 4] = (&DAT_80352e8c)[channelID * 4] | lightId_803988cc;
    lightId_803988cc = lightId_803988cc << 1;
    return;
  }
                    
  OSPanic("light.c",0x22a,s_Failed_assertion_channelID>_GX_C_802ea9a0);
}


/* Library Function - Single Match
    lightFn_80075ac0
   
   Library: KioskDefault 0 0 */

void lightFn_80075ac0(int param1,ObjInstance *object,int param3) { //80075AC0
  int iVar1;
  Mtx44 *m;
  undefined4 local_24;
  vec3f local_20;
  
  m = getCameraMtxs();
  iVar1 = *(int *)(param1 + 0x50);
  if (iVar1 == 4) {
    if (object == (ObjInstance *)0x0) {
      local_20.x = 0.0;
      local_20.y = 0.0;
      local_20.z = 0.0;
    }
    else {
      MTXMultVecMapCoord(&(object->pos).pos,&local_20,(Mtx43 *)m);
    }
    VECScale(-100000.0,(float *)(param1 + 0x40),(float *)(param1 + 0x1c));
    VECAdd((float *)(param1 + 0x1c),&local_20.x,&local_20.x);
    GXInitLightPos((double)local_20.x,(double)local_20.y,(double)local_20.z,param1 + 0x58);
  }
  else {
    if (iVar1 < 4) {
      if (iVar1 != 2) {
LAB_80075c08:
                    
        OSPanic("light.c",0x274,"Failed assertion 0");
      }
    }
    else if (iVar1 != 8) goto LAB_80075c08;
    if (DAT_803988d4 == '\0') {
      GXInitLightPos((double)*(float *)(param1 + 0x1c),(double)*(float *)(param1 + 0x20),
                     (double)*(float *)(param1 + 0x24),param1 + 0x58);
    }
    else {
      if (object == (ObjInstance *)0x0) {
                    
        OSPanic("light.c",0x256,"Failed assertion object");
      }
      MTXMultVecMapCoord(&(object->pos).pos,&local_20,(Mtx43 *)m);
      VECSubtract((float *)(param1 + 0x1c),&local_20.x,&local_20.x);
      GXInitLightPos((double)local_20.x,(double)local_20.y,(double)local_20.z,param1 + 0x58);
    }
    gxLightFn_8002321c((double)*(float *)(param1 + 0x40),(double)*(float *)(param1 + 0x44),
                       (double)*(float *)(param1 + 0x48),param1 + 0x58);
  }
  local_24 = *(undefined4 *)(param1 + 0x98);
  GXInitLightColor(param1 + 0x58,(byte *)&local_24);
  GXLoadLightObjImm(param1 + 0x58,param3);
  return;
}


/* Library Function - Single Match
    lightFn_80075c54
   
   Library: KioskDefault 0 0 */

void lightFn_80075c54(int param1,ObjInstance *object,int param3) { //80075C54
  int iVar1;
  Mtx44 *pMVar2;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float afStack_1c [4];
  
  pMVar2 = getCameraMtxs();
  iVar1 = *(int *)(param1 + 0x50);
  if (iVar1 != 3) {
    if (iVar1 < 3) {
      if (1 < iVar1) {
        if (object == (ObjInstance *)0x0) {
                    
          OSPanic("light.c",0x298,"Failed assertion object");
        }
        VECSubtract(&(object->pos).pos.x,(float *)(param1 + 0x10),afStack_1c);
        VECNormalize(afStack_1c,afStack_1c);
        FUN_80077224(afStack_1c,&local_28,&pMVar2->m11);
        GXInitSpecularDir((double)local_28,(double)local_24,(double)local_20,param1 + 0xb0);
LAB_80075d34:
        local_2c = *(undefined4 *)(param1 + 0xf0);
        GXInitLightColor(param1 + 0xb0,(byte *)&local_2c);
        GXLoadLightObjImm(param1 + 0xb0,param3);
        return;
      }
    }
    else if (iVar1 < 5) {
      GXInitSpecularDir((double)*(float *)(param1 + 0x40),(double)*(float *)(param1 + 0x44),
                        (double)*(float *)(param1 + 0x48),param1 + 0xb0);
      goto LAB_80075d34;
    }
  }
                    
  OSPanic("light.c",0x2a4,"Failed assertion 0");
}


/* Library Function - Single Match
    lightCreateForObject
   
   Library: KioskDefault 0 0 */

Light * lightCreateForObject(ObjInstance *obj) { //80075D68
  Light *light;
  
  light = (Light *)mmAlloc(0x2a0,TEST_COL,"light");
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x2c2,"Failed assertion light");
  }
  memset_(light,0,0x2a0);
  light->parent = obj;
  lightFn_80076074(0.0,0.0,1.0,light);
  lightFn_80076324(light,1);
  lightSetType(light,4);
  FUN_800763d4((int)light,1);
  lightFn_800761b4(0.0,0.0,light,0);
  lightFn_800763e4(light,0);
  lightFn_80076438(light,0xff,0xff,0xff,0xff);
  lightFn_800765c0(90.0,light,0);
  lightFn_800766e8(light,0);
  lightFn_8007673c(light,0xff,0xff,0xff,0xff);
  lightSetEccentricityAndRollOff(4.0,255.0,light);
  lightAnimFn_80076cdc(light,0,0);
  lightFn_80076548(light,0xff,0xff,0xff,0xff);
  lightFn_800767c4(light,0xff,0xff,0xff,0xff);
  if (light->parent != (ObjInstance *)0x0) {
    objModelMtxFn_80085ab8(light->parent,&light->modelMatrix);
  }
  light->field_0x29c = 0;
  light->field464_0x290 = 0;
  return light;
}


/* Library Function - Single Match
    lightFree
   
   Library: KioskDefault 0 0 */

void lightFree(Light *light) { //80075EFC
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x2fd,"Failed assertion light");
  }
  mm_free(light);
  return;
}


/* Library Function - Single Match
    lightFn_80075f4c
   
   Library: KioskDefault 0 0 */

void lightFn_80075f4c(double x,double y,double z,Light *light) { //80075F4C
  Mtx44 *m;
  
  _savefpr_29();
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x31d,"Failed assertion light");
  }
  if (light->parent == (ObjInstance *)0x0) {
    (light->field2_0x10).x = (float)x;
    (light->field2_0x10).y = (float)y;
    (light->field2_0x10).z = (float)z;
  }
  else {
    (light->field1_0x4).x = (float)x;
    (light->field1_0x4).y = (float)y;
    (light->field1_0x4).z = (float)z;
    FUN_80085be4(light->parent,&light->field1_0x4,&light->field2_0x10);
  }
  m = getCameraMtxs();
  MTXMultVecMapCoord(&light->field2_0x10,&light->field3_0x1c,(Mtx43 *)m);
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    lightFn_80075ffc
   
   Library: KioskDefault 0 0 */

void lightFn_80075ffc(Light *light,float *outX,float *outY,float *outZ) { //80075FFC
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x348,"Failed assertion light");
  }
  *outX = (light->field2_0x10).x;
  *outY = (light->field2_0x10).y;
  *outZ = (light->field2_0x10).z;
  return;
}


/* Library Function - Single Match
    lightFn_80076074
   
   Library: KioskDefault 0 0 */

void lightFn_80076074(double x,double y,double z,Light *light) { //80076074
  Mtx44 *pMVar1;
  
  _savefpr_29();
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x365,"Failed assertion light");
  }
  if (light->parent == (ObjInstance *)0x0) {
    (light->field5_0x34).x = (float)x;
    (light->field5_0x34).y = (float)y;
    (light->field5_0x34).z = (float)z;
    vec3f_normalize(&light->field5_0x34,&light->field5_0x34);
  }
  else {
    (light->field4_0x28).x = (float)x;
    (light->field4_0x28).y = (float)y;
    (light->field4_0x28).z = (float)z;
    vec3f_normalize(&light->field4_0x28,&light->field4_0x28);
    lightVecFn_80085c50(light->parent,&light->field4_0x28,&light->field5_0x34);
  }
  pMVar1 = getCameraMtxs();
  FUN_80077224(&(light->field5_0x34).x,(float *)&light->field6_0x40,&pMVar1->m11);
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    lightFn_8007613c
   
   Library: KioskDefault 0 0 */

void lightFn_8007613c(Light *light,float *outX,float *outY,float *outZ) { //8007613C
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x393,"Failed assertion light");
  }
  *outX = (light->field5_0x34).x;
  *outY = (light->field5_0x34).y;
  *outZ = (light->field5_0x34).z;
  return;
}


/* Library Function - Single Match
    lightFn_800761b4
   
   Library: KioskDefault 0 0 */

void lightFn_800761b4(double referenceDistance,double referenceBrightness,Light *light,int param4) { //800761B4
  _savefpr_30();
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x3b1,"Failed assertion light");
  }
  if (referenceDistance < 0.0) {
                    
    OSPanic("light.c",0x3b2,"Failed assertion referenceDistance>=0");
  }
  if ((0.0 <= referenceBrightness) && (referenceBrightness <= 1.0)) {
    light->referenceDistance = (float)referenceDistance;
    light->referenceBrightness = (float)referenceBrightness;
    light->field197_0x12c = param4;
    GXInitLightDistAttn((double)light->referenceDistance,(double)light->referenceBrightness,
                        (int)&light->field_0x58,light->field197_0x12c);
    GXGetLightAttnK((int)&light->field_0x58,&light->field188_0x114,&light->field189_0x118,
                    &light->field190_0x11c);
    _restfpr_30();
    return;
  }
                    
  OSPanic("light.c",0x3b3,"Failed assertion referenceBrightness>=0 && referenceBrightness<=1.0F");
}


/* Library Function - Single Match
    lightFn_800762ac
   
   Library: KioskDefault 0 0 */

void lightFn_800762ac(Light *light,float *outDist,float *outBright,undefined4 *out4) { //800762AC
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x3cf,"Failed assertion light");
  }
  *outDist = light->referenceDistance;
  *outBright = light->referenceBrightness;
  *out4 = light->field197_0x12c;
  return;
}


/* Library Function - Single Match
    lightFn_80076324
   
   Library: KioskDefault 0 0 */

void lightFn_80076324(Light *light,byte param2) { //80076324
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",1000,"Failed assertion light");
  }
  light->field15_0x4c = param2;
  return;
}


/* Library Function - Single Match
    lightSetType
   
   Library: KioskDefault 0 0 */

void lightSetType(Light *light,int lightType) { //80076378
  if (8 < lightType) {
                    
    OSPanic("light.c",0x410,s_Failed_assertion_lightType<LIGHT_802eac34);
  }
  light->type = lightType;
  return;
}


/* Library Function - Single Match
    lightFn_800763e4
   
   Library: KioskDefault 0 0 */

void lightFn_800763e4(Light *light,byte param2) { //800763E4
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x460,"Failed assertion light");
  }
  light->field99_0xac = param2;
  return;
}


/* Library Function - Single Match
    lightFn_80076438
   
   Library: KioskDefault 0 0 */

void lightFn_80076438(Light *light,byte param2,byte param3,byte param4,byte param5) { //80076438
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x48d,"Failed assertion light");
  }
  light->field89_0x9c = param2;
  light->field85_0x98 = param2;
  light->field90_0x9d = param3;
  light->field86_0x99 = param3;
  light->field91_0x9e = param4;
  light->field87_0x9a = param4;
  light->field92_0x9f = param5;
  light->field88_0x9b = param5;
  return;
}


/* Library Function - Single Match
    lightFn_800764c0
   
   Library: KioskDefault 0 0 */

void lightFn_800764c0(Light *light,undefined *out98,undefined *out99,undefined *out9A,
                     undefined *out9B) { //800764C0
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x4a8,"Failed assertion light");
  }
  *out98 = light->field85_0x98;
  *out99 = light->field86_0x99;
  *out9A = light->field87_0x9a;
  *out9B = light->field88_0x9b;
  return;
}


/* Library Function - Single Match
    lightFn_80076548
   
   Library: KioskDefault 0 0 */

void lightFn_80076548(Light *param1,byte param2,byte param3,byte param4,byte param5) { //80076548
  if (param1 == (Light *)0x0) {
                    
    OSPanic("light.c",0x4c6,"Failed assertion light");
  }
  param1->field93_0xa0 = param2;
  param1->field94_0xa1 = param3;
  param1->field95_0xa2 = param4;
  param1->field96_0xa3 = param5;
  return;
}


/* Library Function - Single Match
    lightFn_800765c0
   
   Library: KioskDefault 0 0 */

void lightFn_800765c0(double angleCutOff,Light *light,undefined4 param3) { //800765C0
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x4fc,"Failed assertion light");
  }
  if ((0.0 <= angleCutOff) && (angleCutOff <= 90.0)) {
    light->angleCutOff = (float)angleCutOff;
    light->field98_0xa8 = param3;
    GXInitLightSpot((double)light->angleCutOff,(int)&light->field_0x58,light->field98_0xa8);
    GXGetLightAttnA((int)&light->field_0x58,&light->field185_0x108,&light->field186_0x10c,
                    &light->field187_0x110);
    return;
  }
                    
  OSPanic("light.c",0x4fd,s_Failed_assertion_angleCutOff>_0___802eac60);
}


/* Library Function - Single Match
    lightFn_80076680
   
   Library: KioskDefault 0 0 */

void lightFn_80076680(Light *light,float *outAngleCutOff,undefined4 *outA8) { //80076680
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x517,"Failed assertion light");
  }
  *outAngleCutOff = light->angleCutOff;
  *outA8 = light->field98_0xa8;
  return;
}


/* Library Function - Single Match
    lightFn_800766e8
   
   Library: KioskDefault 0 0 */

void lightFn_800766e8(Light *light,byte param2) { //800766E8
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x532,"Failed assertion light");
  }
  light->field181_0x104 = param2;
  return;
}


/* Library Function - Single Match
    lightFn_8007673c
   
   Library: KioskDefault 0 0 */

void lightFn_8007673c(Light *light,byte param2,byte param3,byte param4,byte param5) { //8007673C
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x55f,"Failed assertion light");
  }
  light->field171_0xf4 = param2;
  light->field167_0xf0 = param2;
  light->field172_0xf5 = param3;
  light->field168_0xf1 = param3;
  light->field173_0xf6 = param4;
  light->field169_0xf2 = param4;
  light->field174_0xf7 = param5;
  light->field170_0xf3 = param5;
  return;
}


/* Library Function - Single Match
    lightFn_800767c4
   
   Library: KioskDefault 0 0 */

void lightFn_800767c4(Light *light,byte param2,byte param3,byte param4,byte param5) { //800767C4
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x596,"Failed assertion light");
  }
  light->field175_0xf8 = param2;
  light->field176_0xf9 = param3;
  light->field177_0xfa = param4;
  light->field178_0xfb = param5;
  return;
}


/* Library Function - Single Match
    lightSetEccentricityAndRollOff
   
   Library: KioskDefault 0 0 */

void lightSetEccentricityAndRollOff(double eccentricity,double rollOff,Light *light) { //8007683C
  _savefpr_30();
  if (light == (Light *)0x0) {
                    
    OSPanic("light.c",0x5cc,"Failed assertion light");
  }
  if ((1.0 <= eccentricity) && (eccentricity <= 256.0)) {
    if ((0.0 <= rollOff) && (rollOff <= 255.0)) {
      light->eccentricity = (float)eccentricity;
      light->rollOff = (float)rollOff;
      GXInitLightAttn(0.0,0.0,1.0,(double)(light->eccentricity * 0.5),0.0,
                      -(double)(light->eccentricity * 0.5 - 1.0),(int)&light->field_0xb0);
      _restfpr_30();
      return;
    }
                    
    OSPanic("light.c",0x5ce,s_Failed_assertion_rollOff>_0_0F___802eacd4);
  }
                    
  OSPanic("light.c",0x5cd,s_Failed_assertion_eccentricity>_1_802eac98);
}


/* Library Function - Single Match
    lightSetTexture
   
   Library: KioskDefault 0 0 */

void lightSetTexture(Light *light,Texture *texture) { //8007694C
  if (texture == (Texture *)0x0) {
                    
    OSPanic("light.c",0x614,"Failed assertion texture");
  }
  if (light->parent == (ObjInstance *)0x0) {
                    
    OSPanic("light.c",0x615,s_Failed_assertion_light_>parent_802ea880);
  }
  light->texture = texture;
  return;
}


/* Library Function - Single Match
    lightFn_800769c8
   
   Library: KioskDefault 0 0 */

void lightFn_800769c8(double param1,double param2,double param3,double param4,Light *light) { //800769C8
  if (light->parent == (ObjInstance *)0x0) {
                    
    OSPanic("light.c",0x643,s_Failed_assertion_light_>parent_802ea880);
  }
  light->field200_0x138 = (float)param1;
  light->field201_0x13c = (float)param2;
  light->field202_0x140 = (float)param3;
  light->field203_0x144 = (float)param4;
  light->field212_0x150 = 0;
  MTXLightOrtho((double)light->field200_0x138,(double)light->field201_0x13c,
                (double)light->field202_0x140,(double)light->field203_0x144,0.5,0.5,0.5,0.5,
                &light->field231_0x198);
  return;
}


/* Library Function - Single Match
    lightFn_80076a74
   
   Library: KioskDefault 0 0 */

void lightFn_80076a74(Light *param1,undefined4 *out138,undefined4 *out13C,undefined4 *out140,
                     undefined4 *out144) { //80076A74
  if (param1 == (Light *)0x0) {
                    
    OSPanic("light.c",0x661,"Failed assertion light");
  }
  *out138 = param1->field200_0x138;
  *out13C = param1->field201_0x13c;
  *out140 = param1->field202_0x140;
  *out144 = param1->field203_0x144;
  return;
}


/* Library Function - Single Match
    lightSetAspect
   
   Library: KioskDefault 0 0 */

void lightSetAspect(double fovY,double aspect,Light *light) { //80076AFC
  _savefpr_30();
  if ((fovY <= 0.0) || (90.0 < fovY)) {
                    
    OSPanic("light.c",0x67b,s_Failed_assertion_fovY>0____fovY<_802ead24);
  }
  if ((0.0 < aspect) && (aspect < 10.0)) {
    if (light->parent == (ObjInstance *)0x0) {
                    
      OSPanic("light.c",0x67d,s_Failed_assertion_light_>parent_802ea880);
    }
    light->fovY = (float)fovY;
    light->aspect = (float)aspect;
    light->field212_0x150 = 1;
    MTXLightPerspective((double)light->fovY,(double)light->aspect,0.5,0.5,0.5,0.5,
                        &light->field231_0x198);
    _restfpr_30();
    return;
  }
                    
  OSPanic("light.c",0x67c,s_Failed_assertion_aspect>0_0F____a_802ead4c);
}


/* Library Function - Single Match
    lightFn_80076c6c
   
   Library: KioskDefault 0 0 */

int * lightFn_80076c6c(Light *light) { //80076C6C
  if (light->parent == (ObjInstance *)0x0) {
                    
    OSPanic("light.c",0x6f6,s_Failed_assertion_light_>parent_802ea880);
  }
  return (int *)&light->field_0x1d8;
}


/* Library Function - Single Match
    lightFn_80076cdc
   
   Library: KioskDefault 0 0 */

void lightAnimFn_80076cdc(Light *light,int animType,short param3) { //80076CDC
  float fVar1;
  
  if (3 < animType) {
                    
    OSPanic("light.c",0x73d,s_Failed_assertion_animType<LIGHT__802ead7c);
  }
  light->animType = animType;
  if (animType != 0) {
    if (param3 == 0) {
      fVar1 = 1.0;
    }
    else {
      fVar1 = (float)((double)CONCAT44(0x43300000,(int)param3 ^ 0x80000000) - 4503601774854144.0);
    }
    light->field461_0x284 = 1.0 / fVar1;
    light->field89_0x9c = light->field85_0x98;
    light->field90_0x9d = light->field86_0x99;
    light->field91_0x9e = light->field87_0x9a;
    light->field171_0xf4 = light->field167_0xf0;
    light->field172_0xf5 = light->field168_0xf1;
    light->field173_0xf6 = light->field169_0xf2;
    light->field462_0x288 = 0.0;
    light->field463_0x28c = 0.0;
  }
  return;
}

