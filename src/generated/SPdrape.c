
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SPdrape_initialise(undefined4 param) { //80269B28
  return;
}


/* @description Called when DLL is unloaded */

void SPdrape_release(void) { //80269B2C
  return;
}


/* Library Function - Single Match
    dll_2CF_func03
   
   Library: KioskDefault 0 0 */

void SPdrape_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //80269B30
  int iVar1;
  ObjInstance *pOVar2;
  float *pfVar3;
  double dVar4;
  
  pfVar3 = (float *)this->state;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *pfVar3 = 0.0072;
  dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  pfVar3[1] = (float)dVar4;
  dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)(this->pos).rotation.x ^
                                                                     0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  pfVar3[2] = (float)dVar4;
  pfVar3[3] = -(pfVar3[1] * (this->pos).pos.x + pfVar3[2] * (this->pos).pos.z);
  iVar1 = randInt(0xb4,300);
  *(short *)(pfVar3 + 5) = (short)iVar1;
  pOVar2 = Object_objGetMain();
  FUN_8026a074((int)pOVar2,(int)pfVar3);
  return;
}


/* Library Function - Single Match
    dll_2CF_func04
   
   Library: KioskDefault 0 0 */

void SPdrape_update(ObjInstance *this) { //80269C38
  short sVar1;
  ushort uVar2;
  ObjInstance *param2;
  int iVar3;
  undefined uVar4;
  ObjDef *pOVar5;
  float *pfVar6;
  double dVar7;
  
  pfVar6 = (float *)this->state;
  param2 = Object_objGetMain();
  pOVar5 = this->def;
                    /* {@symbol 80269c88} */
  switch(this->animId) {
  case 0:
    sVar1 = *(short *)(pfVar6 + 5);
    uVar2 = (ushort)framesThisStep;
    *(ushort *)(pfVar6 + 5) = sVar1 - uVar2;
    if ((short)(sVar1 - uVar2) < 1) {
      audioTryStartSfx((int *)this,8,0x12d,0x7f,"SPdrape.c",0x7b);
      iVar3 = randInt(0xb4,300);
      *(short *)(pfVar6 + 5) = (short)iVar3;
    }
    dVar7 = (double)objDistSqObj2ObjXZ(this,param2);
    if (dVar7 < 4900.0) {
      FUN_8026a074((int)param2,(int)pfVar6);
      Object_ObjAnimSetMove(0.0,this,(uint)*(byte *)pfVar6[4],0);
      *pfVar6 = 0.0175;
      audioTryStartSfx((int *)this,1,0xf4,0x7f,"SPdrape.c",0x85);
      FUN_80269fb0((int)pfVar6,(int)pOVar5);
    }
    break;
  case 1:
  case 4:
    if (*(char *)((int)pfVar6 + 0x16) != '\0') {
      dVar7 = (double)objDistSqObj2ObjXZ(this,param2);
      if (dVar7 <= 8100.0) {
        Object_ObjAnimSetMove(0.0,this,(uint)*(byte *)((int)pfVar6[4] + 1),0);
        *pfVar6 = 0.0144;
      }
      else {
        Object_ObjAnimSetMove(0.0,this,(uint)*(byte *)((int)pfVar6[4] + 2),0);
        audioTryStartSfx((int *)this,1,0xf4,0x7f,"SPdrape.c",0x8e);
        *pfVar6 = 0.0165;
      }
    }
    break;
  case 2:
  case 5:
    audioTryStartSfx((int *)this,0xc0,0x124,0x7f,"SPdrape.c",0x98);
    dVar7 = (double)objDistSqObj2ObjXZ(this,param2);
    if (8100.0 < dVar7) {
      Object_ObjAnimSetMove(0.0,this,(uint)*(byte *)((int)pfVar6[4] + 2),0);
      FUN_80068a9c((uint)this,0x40);
      audioTryStartSfx((int *)this,8,0xf4,0x7f,"SPdrape.c",0x9c);
      *pfVar6 = 0.0165;
    }
    break;
  case 3:
  case 6:
    if ((this->animTimer <= f_0p6) ||
       (dVar7 = (double)objDistSqObj2ObjXZ(this,param2), 4900.0 <= dVar7)) {
      if (*(char *)((int)pfVar6 + 0x16) != '\0') {
        Object_ObjAnimSetMove(0.0,this,0,0);
        *pfVar6 = 0.0072;
        FUN_80269fb0((int)pfVar6,(int)pOVar5);
      }
    }
    else {
      FUN_8026a074((int)param2,(int)pfVar6);
      Object_ObjAnimSetMove(0.0,this,(uint)*(byte *)pfVar6[4],0);
      audioTryStartSfx((int *)this,1,0xf4,0x7f,"SPdrape.c",0xa5);
      *pfVar6 = 0.0175;
    }
  }
  uVar4 = objRunAnimation((double)*pfVar6,(double)timeDelta,(int)this,(float *)0x0);
  *(undefined *)((int)pfVar6 + 0x16) = uVar4;
  return;
}


/* @description Override hit detection */

void SPdrape_hitDetect(ObjInstance *this) { //80269F3C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SPdrape_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //80269F40
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

void SPdrape_free(ObjInstance *this,int param2) { //80269F9C
  return;
}


undefined4 SPdrape_func08(ObjInstance *this) { //80269FA0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SPdrape_getExtraSize(void) { //80269FA8
  return 0x18;
}

