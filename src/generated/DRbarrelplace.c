
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRbarrelplace_initialise(undefined4 param) { //8020B96C
  return;
}


/* @description Called when DLL is unloaded */

void DRbarrelplace_release(void) { //8020B970
  return;
}


/* Library Function - Single Match
    DRbarrelplace_func03
   
   Library: KioskDefault 0 0 */

void DRbarrelplace_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8020B974
  undefined *puVar1;
  undefined *puVar2;
  undefined4 in_register_00004008;
  
  puVar2 = this->state;
  puVar1 = this->state;
  puVar1[7] = puVar1[7] | 2;
                    /* {@symbol 8012f580} */
  (**(code **)(*(int *)pDll_projLib + 4))(CONCAT44(in_register_00004008,x),this,puVar1,5);
  Object_objAddObjectType(this,0x1b);
  Object_objAddObjectType(this,0x18);
  objAllocMsgQueue(this,8);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->flags_0xf8 = 0;
  *(undefined2 *)(puVar2 + 0x38) = 0;
  *(undefined2 *)(puVar2 + 0x3a) = 0;
  puVar2[0x11] = 0;
  *(undefined2 *)(puVar2 + 0x30) = 0;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0;
  puVar2[0x32] = 0;
  *(undefined4 *)(puVar2 + 0x34) = 0;
  *(float *)(puVar2 + 0x28) = 0.0;
  puVar2[0x3d] = 0;
  timerReset((undefined2 *)(puVar2 + 0x14));
  puVar2[0x3d] = puVar2[0x3d] | 1;
  puVar2[0x3c] = (*(char *)((int)&objDef[1].objType + 1) < '\x01') << 7 | puVar2[0x3c] & 0x7f;
  FUN_80088d3c((int)this);
  *(float *)(puVar2 + 0x24) =
       (float)((double)CONCAT44(0x43300000,(int)(short)this->hitstate->field16_0x52 ^ 0x80000000) -
              4503601774854144.0);
  DLL_createTempDll(0x33);
  return;
}


/* Library Function - Single Match
    DRbarrelplace_func04
   
   Library: KioskDefault 0 0 */

void DRbarrelplace_update(ObjInstance *this) { //8020BAD8
  ObjInstance *pOVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  double param2;
  double param3;
  
  puVar4 = this->state;
  pOVar1 = Object_objGetMain();
  iVar2 = timerGetTime((short *)(puVar4 + 0x14));
  if (iVar2 != 0) {
    iVar2 = timerTickDown((short *)(puVar4 + 0x14));
    if (iVar2 == 0) {
      return;
    }
    puVar4[0x13] = 0;
    puVar4[0x12] = 0;
    puVar4[0x3d] = puVar4[0x3d] | 1;
    (this->pos).flags = (this->pos).flags & ~Invisible;
    FUN_80088d3c((int)this);
    objHitUpdatePos(this);
    return;
  }
  FUN_8020cf88(this);
  if ((this->pMatrix == (ObjInstance *)0x0) || (this->pMatrix->romdefno != DR_PushCart)) {
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
  }
  else {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  if (puVar4[0x13] == '\0') {
                    /* {@symbol 8012f5bc} */
    if (((puVar4[0x3d] & 2) == 0) &&
       (iVar2 = (**(code **)(*(int *)pDll_projLib + 8))(this,puVar4), iVar2 != 0)) {
      Object_objAddObjectType(this,0x18);
      puVar4[0x3d] = puVar4[0x3d] | 1;
      puVar4[0x11] = 1;
      puVar4[0x3e] = puVar4[0x3e] & 0xbf | 0x40;
    }
    else {
      if (puVar4[0x11] != '\0') {
        puVar4[0x11] = 0;
        FUN_80088d3c((int)this);
        uVar3 = FUN_801a7fa8((int)pOVar1);
        if (uVar3 == 0) {
          uVar3 = FUN_801a7f78((int)pOVar1);
          if (uVar3 == 0) {
            puVar4[0x13] = 0x14;
            *(float *)(puVar4 + 0x2c) = 2.2;
            return;
          }
          Object_objAddObjectType(this,0x18);
        }
        else {
          Object_objAddObjectType(this,0x18);
          FUN_8020d14c((int)this);
        }
      }
      if ((puVar4[0x3d] & 1) != 0) {
        FUN_8020c3c0(this);
      }
      FUN_8020c9a0(this);
    }
    if ((((char)puVar4[0x3e] < '\0') &&
        (this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08,
        ((byte)puVar4[0x3e] >> 6 & 1) != 0)) && ((char)puVar4[0x3e] < '\0')) {
      *(float *)(puVar4 + 0x18) = (this->vel).x;
      *(float *)(puVar4 + 0x1c) = (this->vel).y;
      *(float *)(puVar4 + 0x20) = (this->vel).z;
      *(float *)(puVar4 + 0x1c) = 0.0;
      puVar4[0x3e] = puVar4[0x3e] & 0xbf;
    }
    if ((char)puVar4[0x3c] < '\0') {
      objRomDefMove_800af9d8
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 this->def,(short)(char)this->mapId);
    }
    return;
  }
  puVar4[0x13] = puVar4[0x13] + framesThisStep;
  param3 = (double)*(float *)(puVar4 + 0x2c);
  *(float *)(puVar4 + 0x24) =
       (float)(param3 * (double)(float)((double)CONCAT44(0x43300000,(uint)(byte)puVar4[0x13]) -
                                       4503599627370496.0) + 1.0);
  objHitFn_80089188(this,(short)(int)*(float *)(puVar4 + 0x24),
                    (short)(int)(-*(float *)(puVar4 + 0x24) * 0.5),
                    (short)(int)(*(float *)(puVar4 + 0x24) * 0.5));
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,0x353,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,0x353,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
  param2 = (double)(**(code **)(*(int *)pDll_objfsa + 8))(this,0x353,0,0,0xffffffff,0);
  if ((byte)puVar4[0x13] < 0x15) {
    return;
  }
  if ((char)puVar4[0x3e] < '\0') {
    param2 = (double)elevatorFn_8020d030(this,'\0');
  }
  pOVar1 = getSeqObj(0x3c,this,(float *)0x0);
  if (pOVar1 == (ObjInstance *)0x0) {
    printf(" ERROR : no barrel generator found ");
    objFreeFn_80083b54(this);
    FUN_80088da4((int)this);
    (this->pos).flags = (this->pos).flags | Invisible;
    timerSet((short *)(puVar4 + 0x14),0x3c);
    return;
  }
  printf(" Should has Set position  %i %f %f ",0x1a,param2,param3);
  memclr(puVar4 + 0x18,0xc);
  memclr(&this->vel,0xc);
  puVar4[0x3d] = puVar4[0x3d] & 0xfd;
  Object_objUpdateHitState(this);
  if ((char)puVar4[0x3c] < '\0') {
    objRomDefMove_800af9d8
              ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
               this->def,(short)(char)this->mapId);
    timerSet((short *)(puVar4 + 0x14),0x3c);
    FUN_802bf428((int)pOVar1,(int)this,0x46);
    objHitFn_80089114(this);
    FUN_80088da4((int)this);
    (this->pos).flags = (this->pos).flags | Invisible;
    return;
  }
  objFreeFn_80083b54(this);
  FUN_80088da4((int)this);
  (this->pos).flags = (this->pos).flags | Invisible;
  return;
}


/* Library Function - Single Match
    DRbarrelplace_func05
   
   Library: KioskDefault 0 0 */

void DRbarrelplace_hitDetect(ObjInstance *param1) { //8020BF88
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined *puVar5;
  ObjInstance *apOStack_7c [7];
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  char local_2b;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  puVar5 = param1->state;
  if ((puVar5[0x13] == '\0') && (iVar4 = timerGetTime((short *)(puVar5 + 0x14)), iVar4 == 0)) {
    if (*(int *)(puVar5 + 0xc) != 0) {
      objBecomeHeldBy((short *)param1,*(ObjInstance **)(puVar5 + 0xc),1);
      *(undefined4 *)(puVar5 + 0xc) = 0;
    }
    if ((char)puVar5[0x3e] < '\0') {
      fVar1 = (param1->pos).pos.y;
      fVar2 = (param1->oldPos).y;
      local_1c = ((param1->pos).pos.x - (param1->oldPos).x) * (1.0 / timeDelta) * 0.99;
      fVar3 = 1.0 / timeDelta;
      local_14 = ((param1->pos).pos.z - (param1->oldPos).z) * (1.0 / timeDelta) * 0.99;
      *(float *)(puVar5 + 0x18) = local_1c + *(float *)(puVar5 + 0x18);
      *(float *)(puVar5 + 0x1c) = (fVar1 - fVar2) * fVar3 * 0.99 + *(float *)(puVar5 + 0x1c);
      *(float *)(puVar5 + 0x20) = local_14 + *(float *)(puVar5 + 0x20);
      local_18 = 0.0;
      *(float *)(puVar5 + 0x18) = *(float *)(puVar5 + 0x18) * 0.5;
      *(float *)(puVar5 + 0x1c) = *(float *)(puVar5 + 0x1c) * 0.5;
      *(float *)(puVar5 + 0x20) = *(float *)(puVar5 + 0x20) * 0.5;
      *(float *)(puVar5 + 0x1c) = 0.0;
      puVar5[0x3d] = puVar5[0x3d] | 1;
    }
    if ((puVar5[0x11] == '\0') &&
       (iVar4 = FUN_800bb7e0(8.0,&(param1->oldPos).x,&(param1->pos).pos.x,1,apOStack_7c,param1,8,-1,
                             0xff,'\0'), iVar4 != 0)) {
      printf(" Line IDNO %i ",(int)local_2b);
      if (((char)puVar5[0x3e] < '\0') && (local_2b == '\x03')) {
        elevatorFn_8020d030(param1,'\0');
      }
      else {
        local_28 = local_60;
        local_24 = local_5c;
        local_20 = local_58;
        FUN_8007b2d0(&local_28,&(param1->vel).x,&(param1->vel).x);
        FUN_8007b2d0(&local_28,(float *)(puVar5 + 0x18),(float *)(puVar5 + 0x18));
        (param1->vel).x = (param1->vel).x * 0.3;
        (param1->vel).y = (param1->vel).y * 0.3;
        (param1->vel).z = (param1->vel).z * 0.3;
        *(float *)(puVar5 + 0x18) = *(float *)(puVar5 + 0x18) * 0.3;
        *(float *)(puVar5 + 0x1c) = *(float *)(puVar5 + 0x1c) * 0.3;
        *(float *)(puVar5 + 0x20) = *(float *)(puVar5 + 0x20) * 0.3;
        audioTryStartSfx((int *)param1,1,499,0x7f,"CFbarrel.c",0x189);
        printf(" Hit Line ");
      }
    }
    (param1->oldPos).x = (param1->pos).pos.x;
    (param1->oldPos).y = (param1->pos).pos.y;
    (param1->oldPos).z = (param1->pos).pos.z;
  }
  return;
}


/* Library Function - Single Match
    DRbarrelplace_func06
   
   Library: KioskDefault 0 0 */

void DRbarrelplace_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8020C274
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (this->state[0x13] == '\0') {
    if (this->state[0x11] != '\0') {
      (this->pos).rotation.z = 0;
      (this->pos).rotation.y = 0;
    }
                    /* {@symbol 8012f938} */
    iVar1 = (**(code **)(*(int *)pDll_projLib + 0xc))(this,(int)shouldRender);
    if ((iVar1 != 0) || (shouldRender == true)) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
  }
  return;
}


/* Library Function - Single Match
    DRbarrelplace_func07
   
   Library: KioskDefault 0 0 */

void DRbarrelplace_free(ObjInstance *this,int param2) { //8020C328
  undefined *puVar1;
  
  puVar1 = this->state;
                    /* {@symbol 8012f9ac} */
  (**(code **)(*(int *)pDll_projLib + 0x10))(this);
  Object_removePlayerObj(this,0x1b);
  Object_removePlayerObj(this,0x18);
  if (puVar1[0x13] != '\0') {
                    /* {@symbol 800dc2d8} */
    (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  }
  DLL_removeTempDll(0x33);
  return;
}


undefined4 DRbarrelplace_func08(ObjInstance *this) { //8020C3B0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRbarrelplace_getExtraSize(void) { //8020C3B8
  return 0x40;
}


/* Library Function - Single Match
    DRbarrelplace_func0A
   
   Library: KioskDefault 0 0 */

void DRbarrelplace_setScale(ObjInstance *obj,vec3f *force,float scale) { //8020CEF0
  undefined *puVar1;
  undefined4 in_register_00004008;
  double in_f2;
  double in_f3;
  
  puVar1 = obj->state;
  if (puVar1[0x11] == '\0') {
    printf(" Force Applied x %f y %f z%f ",(double)CONCAT44(in_register_00004008,scale),
           in_f2,in_f3);
    *(float *)(puVar1 + 0x1c) = *(float *)(puVar1 + 0x1c) + force->y;
    *(float *)(puVar1 + 0x18) = *(float *)(puVar1 + 0x18) + force->x;
    *(float *)(puVar1 + 0x20) = *(float *)(puVar1 + 0x20) + force->z;
    puVar1[0x3d] = puVar1[0x3d] | 1;
  }
  return;
}


void FUN_802bf428(int param_1,int param_2,short param_3) { //802BF428
  int *piVar1;
  
  if (param_1 == 0) {
                    
    OSPanic("DRbarrelplace.c",0x17f,"Failed assertion obj");
  }
  piVar1 = *(int **)(param_1 + 0xb8);
  if (piVar1 == (int *)0x0) {
                    
    OSPanic("DRbarrelplace.c",0x182,"Failed assertion genobj");
  }
  if (param_2 == 0) {
                    
    OSPanic("DRbarrelplace.c",0x184,"Failed assertion barrelobj");
  }
  *piVar1 = param_2;
  *(undefined *)(piVar1 + 1) = 0;
  timerReset((undefined2 *)((int)piVar1 + 6));
  timerSet((short *)((int)piVar1 + 6),param_3 + -10);
  return;
}

