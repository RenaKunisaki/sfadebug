
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIM2projrock_initialise(undefined4 param) { //8022D080
  return;
}


/* @description Called when DLL is unloaded */

void DIM2projrock_release(void) { //8022D084
  return;
}


/* Library Function - Single Match
    dll_21A_func03
   
   Library: KioskDefault 0 0 */

void DIM2projrock_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8022D088
  *(float *)this->state = (this->pos).pos.y;
  (this->pos).pos.y = (this->pos).pos.y + 1.0;
  return;
}


/* Library Function - Single Match
    dll_21A_func04
   
   Library: KioskDefault 0 0 */

void DIM2projrock_update(ObjInstance *this) { //8022D0B8
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  double dVar5;
  ObjInstance *apOStack_8c [7];
  float local_70;
  float local_6c;
  float local_68;
  float local_38;
  float local_34;
  float local_30;
  int local_2c;
  
  _savefpr_29();
  pfVar4 = (float *)this->state;
  if (*(char *)(pfVar4 + 1) == '\0') {
    (this->vel).x = (this->vel).x * 0.9;
    (this->vel).z = (this->vel).z * 0.9;
  }
  else {
    (this->vel).x = (this->vel).x * 0.85;
    (this->vel).z = (this->vel).z * 0.85;
  }
  if (((((this->vel).x < 0.1) && (-0.1 < (this->vel).x)) && ((this->vel).z < 0.1)) &&
     (-0.1 < (this->vel).z)) {
    (this->vel).x = 0.0;
    (this->vel).z = 0.0;
  }
  objMove((double)((this->vel).x * timeDelta),0.0,(double)((this->vel).z * timeDelta),this);
  iVar2 = FUN_800bb7e0(6.5,&(this->oldPos).x,&(this->pos).pos.x,1,apOStack_8c,this,8,-1,0xff,'\0');
  if (iVar2 != 0) {
    local_38 = -(this->vel).x;
    local_34 = -(this->vel).y;
    local_30 = -(this->vel).z;
    dVar5 = sqrt((double)(local_30 * local_30 + local_38 * local_38 + local_34 * local_34));
    if (dVar5 != 0.0) {
      fVar1 = (float)(1.0 / dVar5);
      local_38 = local_38 * fVar1;
      local_34 = local_34 * fVar1;
      local_30 = local_30 * fVar1;
    }
    fVar1 = (local_30 * local_68 + local_38 * local_70 + local_34 * local_6c) * 2.0;
    (this->vel).x = local_70 * fVar1;
    (this->vel).y = local_6c * fVar1;
    (this->vel).z = local_68 * fVar1;
    (this->vel).x = (this->vel).x - local_38;
    (this->vel).y = (this->vel).y - local_34;
    (this->vel).z = (this->vel).z - local_30;
    (this->vel).x = (this->vel).x * (float)(dVar5 * 0.800000011920929);
    (this->vel).y = (this->vel).y * (float)(dVar5 * 0.5);
    (this->vel).z = (this->vel).z * (float)(dVar5 * 0.800000011920929);
  }
  (this->pos).pos.y = -(timeDelta * 0.2 - (this->pos).pos.y);
  iVar2 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z
                       ,(int)this,&local_2c,0,0x11);
  *(undefined *)(pfVar4 + 1) = 0;
  iVar3 = 0;
  do {
    if (iVar2 <= iVar3) {
LAB_8022d3c8:
      if ((this->pos).pos.y < *pfVar4) {
        (this->pos).pos.y = *pfVar4;
      }
      objRomDefMove_800af9d8
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 this->def,(short)(char)this->mapId);
      _restfpr_29();
      return;
    }
    if ((this->pos).pos.y < **(float **)(local_2c + iVar3 * 4) + 5.0) {
      (this->pos).pos.y = **(float **)(local_2c + iVar3 * 4);
      FUN_800885f0(*(int *)(*(int *)(local_2c + iVar3 * 4) + 0x10),(int)this);
      *(undefined *)(pfVar4 + 1) = 1;
      goto LAB_8022d3c8;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


/* Library Function - Single Match
    dll_21A_func05
   
   Library: KioskDefault 0 0 */

void DIM2projrock_hitDetect(ObjInstance *this) { //8022D418
  int iVar1;
  ObjInstance *param2;
  int local_24;
  undefined4 local_20;
  uint uStack_1c;
  
  _savefpr_30();
  iVar1 = FUN_800883e4((int)this,&local_24,(int *)0x0,(uint *)0x0);
  if (iVar1 == 0xe) {
    param2 = Object_objGetMain();
    objDistObj2Obj(this,param2);
    (this->vel).x = *(float *)(local_24 + 0x24) * 0.5;
    (this->vel).z = *(float *)(local_24 + 0x2c) * 0.5;
    uStack_1c = randInt(-0x32,0x32);
    uStack_1c = uStack_1c ^ 0x80000000;
    local_20 = 0x43300000;
    audioTryStartSfx((int *)this,0x40,0x2c,0x7f,"DIM2projrock.c",0xa7);
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIM2projrock_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8022D518
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

void DIM2projrock_free(ObjInstance *this,int param2) { //8022D574
  return;
}


undefined4 DIM2projrock_func08(ObjInstance *this) { //8022D578
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIM2projrock_getExtraSize(void) { //8022D580
  return 8;
}

