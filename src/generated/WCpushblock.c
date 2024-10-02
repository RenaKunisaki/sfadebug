
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WCpushblock_initialise(undefined4 param) { //802C0A70
  return;
}


/* @description Called when DLL is unloaded */

void WCpushblock_release(void) { //802C0A74
  return;
}


/* Library Function - Single Match
    dll_2DA_func03
   
   Library: KioskDefault 0 0 */

void WCpushblock_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802C0A78
  undefined2 uVar1;
  
  this->newOpacity = 0;
  this->curModel = *(byte *)((int)&objDef[1].objType + 1);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
  }
  uVar1._0_1_ = objDef[1].allocatedSize;
  uVar1._1_1_ = objDef[1].mapStates1;
  this->state[0x272] = (char)uVar1;
  return;
}


/* Library Function - Single Match
    dll_2DA_func04
   
   Library: KioskDefault 0 0 */

void WCpushblock_update(ObjInstance *this) { //802C0ACC
  float fVar1;
  bool bVar2;
  ObjInstance *pOVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined uVar7;
  undefined *puVar8;
  double dVar9;
  undefined auStack_3c [4];
  float local_38 [2];
  longlong local_30;
  
  puVar8 = this->state;
  pOVar3 = Object_objGetMain();
  local_38[0] = 100000.0;
  if (*(int *)(puVar8 + 0x260) == 0) {
    pOVar3 = getSeqObj(10,this,local_38);
    *(ObjInstance **)(puVar8 + 0x260) = pOVar3;
    this->newOpacity = 0;
  }
  else {
    puVar4 = (undefined4 *)FUN_80094400((int)this,0);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0;
    }
    if (puVar8[0x270] != '\x06') {
                    /* {@symbol 800d2604} */
      iVar5 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_3c);
      if (this->curModel == 1) {
        uVar6 = mainGetBit(0x812);
        if (uVar6 == 0) {
          if (iVar5 != 0) {
            puVar8[0x270] = 3;
          }
        }
        else {
          puVar8[0x270] = 6;
          (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x34))
                    (puVar8[0x272],puVar8 + 0x26c,puVar8 + 0x26e);
          (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x20))
                    (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                     &(this->pos).pos,&(this->pos).pos.z);
        }
      }
      else {
        uVar6 = mainGetBit(0x813);
        if (uVar6 == 0) {
          if (iVar5 == 0) {
            puVar8[0x270] = 3;
          }
        }
        else {
          puVar8[0x270] = 6;
          (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x50))
                    (puVar8[0x272],puVar8 + 0x26c,puVar8 + 0x26e);
          (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x3c))
                    (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                     &(this->pos).pos,&(this->pos).pos.z);
        }
      }
    }
                    /* {@symbol 802c0ca4} */
    switch(puVar8[0x270]) {
    case 0:
      if (this->curModel == 1) {
        (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x30))
                  (puVar8[0x272],puVar8 + 0x26c,puVar8 + 0x26e);
        (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x20))
                  (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                   &(this->pos).pos,&(this->pos).pos.z);
      }
      else {
        (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x4c))
                  (puVar8[0x272],puVar8 + 0x26c,puVar8 + 0x26e);
        (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x3c))
                  (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                   &(this->pos).pos,&(this->pos).pos.z);
      }
      puVar8[0x270] = 1;
      break;
    case 1:
      uVar6 = (uint)this->newOpacity + (uint)framesThisStep * 8;
      if (0xff < uVar6) {
        uVar6 = 0xff;
      }
      this->newOpacity = (u8)uVar6;
      (this->vel).x = 0.0;
      (this->vel).z = 0.0;
      uVar6 = FUN_801a8310((int)pOVar3,(int)this,puVar8 + 0x271);
      if ((uVar6 & 0xff) != 0) {
        if (this->curModel == 1) {
          if (puVar8[0x271] == '\0') {
            uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x38))
                              (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                               puVar8 + 0x264,puVar8 + 0x268,0xffffffff,0);
            puVar8[0x273] = uVar7;
          }
          else if (puVar8[0x271] == '\x01') {
            uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x38))
                              (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                               puVar8 + 0x264,puVar8 + 0x268,1,0);
            puVar8[0x273] = uVar7;
          }
          else if (puVar8[0x271] == '\x02') {
            uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x38))
                              (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                               puVar8 + 0x264,puVar8 + 0x268,0,0xffffffff);
            puVar8[0x273] = uVar7;
          }
          else if (puVar8[0x271] == '\x03') {
            uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x38))
                              (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                               puVar8 + 0x264,puVar8 + 0x268,0,1);
            puVar8[0x273] = uVar7;
          }
        }
        else if (puVar8[0x271] == '\0') {
          uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x54))
                            (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                             puVar8 + 0x264,puVar8 + 0x268,0xffffffff,0);
          puVar8[0x273] = uVar7;
        }
        else if (puVar8[0x271] == '\x01') {
          uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x54))
                            (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                             puVar8 + 0x264,puVar8 + 0x268,1,0);
          puVar8[0x273] = uVar7;
        }
        else if (puVar8[0x271] == '\x02') {
          uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x54))
                            (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                             puVar8 + 0x264,puVar8 + 0x268,0,0xffffffff);
          puVar8[0x273] = uVar7;
        }
        else if (puVar8[0x271] == '\x03') {
          uVar7 = (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x54))
                            (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                             puVar8 + 0x264,puVar8 + 0x268,0,1);
          puVar8[0x273] = uVar7;
        }
        if ((*(float *)(puVar8 + 0x264) != (this->pos).pos.x) ||
           (*(float *)(puVar8 + 0x268) != (this->pos).pos.y)) {
          audioTryStartSfx((int *)this,8,0x6b,1,"WCpushblock.c",0xcf);
          puVar8[0x270] = 2;
        }
      }
      break;
    case 2:
      dVar9 = sqrt((double)((this->vel).x * (this->vel).x + (this->vel).z * (this->vel).z));
      fVar1 = (float)(dVar9 - 0.25);
      if (fVar1 < 0.0) {
        fVar1 = 0.0;
      }
      fVar1 = (fVar1 * 126.0) / 1.25 + 1.0;
      if (127.0 < fVar1) {
        fVar1 = 127.0;
      }
      local_30 = (longlong)(int)fVar1;
      FUN_800689dc(127.0,(int)this,8,(byte)(int)fVar1);
      objMove((double)((this->vel).x * timeDelta),0.0,(double)((this->vel).z * timeDelta),this);
      bVar2 = false;
      if (puVar8[0x271] == '\0') {
        if ((this->vel).x < 1.5) {
          (this->vel).x = timeDelta * 0.05 + (this->vel).x;
        }
        if (*(float *)(puVar8 + 0x264) <= (this->pos).pos.x) {
          (this->pos).pos.x = *(float *)(puVar8 + 0x264);
          bVar2 = true;
        }
      }
      else if (puVar8[0x271] == '\x01') {
        if (-1.5 < (this->vel).x) {
          (this->vel).x = -(timeDelta * 0.05 - (this->vel).x);
        }
        if ((this->pos).pos.x <= *(float *)(puVar8 + 0x264)) {
          (this->pos).pos.x = *(float *)(puVar8 + 0x264);
          bVar2 = true;
        }
      }
      else if (puVar8[0x271] == '\x02') {
        if ((this->vel).z < 1.5) {
          (this->vel).z = timeDelta * 0.05 + (this->vel).z;
        }
        if (*(float *)(puVar8 + 0x268) <= (this->pos).pos.z) {
          (this->pos).pos.z = *(float *)(puVar8 + 0x268);
          bVar2 = true;
        }
      }
      else if (puVar8[0x271] == '\x03') {
        if (-1.5 < (this->vel).z) {
          (this->vel).z = -(timeDelta * 0.05 - (this->vel).z);
        }
        if ((this->pos).pos.z <= *(float *)(puVar8 + 0x268)) {
          (this->pos).pos.z = *(float *)(puVar8 + 0x268);
          bVar2 = true;
        }
      }
      if (1.5 < (this->vel).x) {
        (this->vel).x = 1.5;
      }
      if ((this->vel).x < -1.5) {
        (this->vel).x = -1.5;
      }
      if (1.5 < (this->vel).z) {
        (this->vel).z = 1.5;
      }
      if ((this->vel).z < -1.5) {
        (this->vel).z = -1.5;
      }
      if (bVar2) {
        FUN_80068a9c((uint)this,8);
        (this->vel).x = 0.0;
        (this->vel).z = 0.0;
        if (puVar8[0x273] == '\x02') {
          puVar8[0x270] = 4;
          audioTryStartSfx((int *)this,1,0x4a,0x7f,"WCpushblock.c",0x112);
          if (this->curModel == 1) {
            mainIncBit(0x810);
          }
          else {
            mainIncBit(0x811);
          }
        }
        else if (puVar8[0x273] == '\x01') {
          puVar8[0x270] = 1;
          audioTryStartSfx((int *)this,1,0xeb,0x7f,"WCpushblock.c",0x11b);
        }
        else {
          puVar8[0x270] = 3;
          audioTryStartSfx((int *)this,1,0xeb,0x7f,"WCpushblock.c",0x120);
        }
        if (puVar8[0x270] != '\x03') {
          if (this->curModel == 1) {
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x28))
                      (0,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e));
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x24))
                      ((double)(this->pos).pos.x,(double)(this->pos).pos.z,this,puVar8 + 0x26c,
                       puVar8 + 0x26e);
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x28))
                      (puVar8[0x272],(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e)
                      );
          }
          else {
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x44))
                      (0,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e));
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x40))
                      ((double)(this->pos).pos.x,(double)(this->pos).pos.z,this,puVar8 + 0x26c,
                       puVar8 + 0x26e);
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x44))
                      (puVar8[0x272],(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e)
                      );
          }
        }
      }
      break;
    case 3:
      FUN_80088da4((int)this);
      if (this->newOpacity == 0xff) {
        audioTryStartSfx((int *)this,1,0x38,0x7f,"WCpushblock.c",0x136);
      }
      iVar5 = (uint)this->newOpacity + (uint)framesThisStep * -8;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      this->newOpacity = (u8)iVar5;
      if (this->newOpacity == 0) {
        Object_objGetMain();
        iVar5 = FUN_802c16dc((int)this,(int)puVar8);
        if (iVar5 != 0) {
          if (this->curModel == 1) {
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x30))
                      (puVar8[0x272],puVar8 + 0x26c,puVar8 + 0x26e);
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x20))
                      (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                       &(this->pos).pos,&(this->pos).pos.z);
          }
          else {
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x4c))
                      (puVar8[0x272],puVar8 + 0x26c,puVar8 + 0x26e);
            (**(code **)(**(int **)(*(int *)(puVar8 + 0x260) + 0x68) + 0x3c))
                      (this,(int)*(short *)(puVar8 + 0x26c),(int)*(short *)(puVar8 + 0x26e),
                       &(this->pos).pos,&(this->pos).pos.z);
          }
          puVar8[0x270] = 5;
        }
      }
      break;
    case 5:
      if (this->newOpacity == 0) {
        FUN_80088d3c((int)this);
        audioTryStartSfx((int *)this,1,0x37,0x7f,"WCpushblock.c",0x156);
      }
      uVar6 = (uint)this->newOpacity + (uint)framesThisStep * 8;
      if (0xff < uVar6) {
        uVar6 = 0xff;
      }
      this->newOpacity = (u8)uVar6;
      if (this->newOpacity == 0xff) {
        puVar8[0x270] = 1;
      }
      break;
    case 6:
      this->newOpacity = 0xff;
    case 4:
      puVar4 = (undefined4 *)FUN_80094400((int)this,0);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = 0x100;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void WCpushblock_hitDetect(ObjInstance *this) { //802C1668
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WCpushblock_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802C166C
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

void WCpushblock_free(ObjInstance *this,int param2) { //802C16C8
  return;
}


undefined4 WCpushblock_func08(ObjInstance *this) { //802C16CC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WCpushblock_getExtraSize(void) { //802C16D4
  return 0x274;
}

