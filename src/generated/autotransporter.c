
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void autoTransporter_initialise(undefined4 param) { //801F561C
  return;
}


/* @description Called when DLL is unloaded */

void autoTransporter_release(void) { //801F5620
  return;
}


/* Library Function - Single Match
    autoTransporter_func03
   
   Library: KioskDefault 0 0 */

void autoTransporter_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801F5624
  undefined4 *puVar1;
  
  (this->pos).rotation.x = 0;
  puVar1 = (undefined4 *)this->state;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined2 *)(puVar1 + 4) = 600;
  *(undefined2 *)((int)puVar1 + 0x12) = 600;
  *(undefined2 *)(puVar1 + 5) = 10;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)((int)puVar1 + 0x1a) = 10;
  *(undefined2 *)(puVar1 + 7) = 400;
  *(undefined2 *)(puVar1 + 8) = 0;
  *(undefined2 *)((int)puVar1 + 0x1e) = 2;
  puVar1[3] = 0.01;
  (this->pos).rotation.x =
       (short)(int)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].objType << 8 ^ 0x80000000)
                   - 4503601774854144.0);
  this->field76_0xf4 = 0;
  this->flags_0xf8 = 0x96;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f6074;
  return;
}


/* Library Function - Single Match
    autoTransporter_func04
   
   Library: KioskDefault 0 0 */

void autoTransporter_update(ObjInstance *this) { //801F56FC
  ObjInstance *param1;
  LoadedDll *pLVar1;
  uint uVar2;
  int iVar3;
  Camera *pCVar4;
  ObjDef *pOVar5;
  short sVar6;
  LoadedDll **ppLVar7;
  double dVar8;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  ppLVar7 = (LoadedDll **)this->state;
  pOVar5 = this->def;
  enableCameraYOffset();
  param1 = Object_objGetMain();
  if (param1 != (ObjInstance *)0x0) {
    dVar8 = (double)objDistObj2ObjXZ(param1,this);
    if (((*(char *)((int)ppLVar7 + 0x25) == '\0') && (*(char *)(ppLVar7 + 9) == '\0')) &&
       (dVar8 < 400.0)) {
      if (ppLVar7[2] == (LoadedDll *)0x0) {
        pLVar1 = (LoadedDll *)runlinkDownloadCode(0x1024,1);
        ppLVar7[2] = pLVar1;
      }
      if (warpIdx_80398d24 < 0) {
        uVar2 = mainGetBit(0xfd);
        if (uVar2 != 0) {
          printf("TRACE: '%s' {Line %d}","autotransporter.c",0x74);
          mainSetBits(0xfd,0);
          loadEnvfxAction(this,this,0xbb,0);
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
          *(undefined *)((int)ppLVar7 + 0x25) = 1;
          this->field76_0xf4 = (int)*(short *)(ppLVar7 + 7);
          if (*ppLVar7 == (LoadedDll *)0x0) {
            pLVar1 = (LoadedDll *)runlinkDownloadCode(0x1019,1);
            *ppLVar7 = pLVar1;
          }
          if (ppLVar7[1] == (LoadedDll *)0x0) {
            pLVar1 = (LoadedDll *)runlinkDownloadCode(0x101a,1);
            ppLVar7[1] = pLVar1;
          }
          *(undefined *)(ppLVar7 + 9) = 1;
          *(undefined *)((int)ppLVar7 + 0x26) = 1;
        }
      }
      else {
        *(undefined *)((int)ppLVar7 + 0x25) = 0;
        param1->newOpacity = 0;
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
        this->field76_0xf4 = (int)*(short *)(ppLVar7 + 7);
        if (*ppLVar7 == (LoadedDll *)0x0) {
          pLVar1 = (LoadedDll *)runlinkDownloadCode(0x1019,1);
          *ppLVar7 = pLVar1;
        }
        if (ppLVar7[1] == (LoadedDll *)0x0) {
          pLVar1 = (LoadedDll *)runlinkDownloadCode(0x101a,1);
          ppLVar7[1] = pLVar1;
        }
        *(undefined *)(ppLVar7 + 9) = 1;
        warpTimer_80398c70 = '\x02';
        *(undefined *)((int)ppLVar7 + 0x26) = 0;
      }
      iVar3 = randInt(0,0x28);
      if (iVar3 == 0) {
        iVar3 = randInt(0,5);
        (**(code **)(ppLVar7[2]->id + 4))(this,iVar3,0,1,0xffffffff,0);
      }
    }
    if ((*(char *)(ppLVar7 + 9) == '\0') || ((int)this->field76_0xf4 < 1)) {
      if ((*(char *)(ppLVar7 + 9) != '\0') && ((int)this->field76_0xf4 < 1)) {
        local_48 = (param1->prevPos).x;
        local_44 = (param1->prevPos).y;
        local_40 = (param1->prevPos).z;
        local_4c = 1.0;
        local_54 = 0;
        local_50 = 0;
        local_52 = 0;
        if (*(char *)((int)ppLVar7 + 0x25) == '\0') {
          audioTryStartSfx((int *)this,1,0x208,0x7f,"autotransporter.c",0xd8);
          for (sVar6 = 0; sVar6 < 100; sVar6 = sVar6 + 1) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x7a,0,0,0xffffffff,0);
          }
        }
        else {
          FUN_8006ae50(8.0);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x75,&local_54,1,0xffffffff,0);
          for (sVar6 = 0; sVar6 < 0x50; sVar6 = sVar6 + 1) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x77,0,0,0xffffffff,0);
          }
        }
        DLL_free(*ppLVar7);
        *ppLVar7 = (LoadedDll *)0x0;
        DLL_free(ppLVar7[1]);
        ppLVar7[1] = (LoadedDll *)0x0;
        this->field76_0xf4 = 0;
        this->flags_0xf8 = 0x96;
        *(undefined2 *)((int)ppLVar7 + 0x16) = 0;
        *(undefined2 *)(ppLVar7 + 6) = 0;
        *(undefined2 *)((int)ppLVar7 + 0x1a) = 10;
        *(undefined2 *)((int)ppLVar7 + 0x1e) = 2;
        ppLVar7[3] = (LoadedDll *)0.01;
        *(undefined *)(ppLVar7 + 9) = 0;
        *(undefined2 *)(ppLVar7 + 8) = 0x226;
        *(undefined2 *)((int)ppLVar7 + 0x22) = 0x226;
      }
    }
    else {
      *(ushort *)((int)ppLVar7 + 0x16) = *(short *)((int)ppLVar7 + 0x16) - (ushort)framesThisStep;
      *(ushort *)(ppLVar7 + 6) = *(short *)(ppLVar7 + 6) - (ushort)framesThisStep;
      if (*(short *)((int)ppLVar7 + 0x16) < 1) {
        (**(code **)((*ppLVar7)->id + 4))(this,0,0,1,0xffffffff,0);
        *(undefined2 *)((int)ppLVar7 + 0x16) = *(undefined2 *)(ppLVar7 + 4);
      }
      if ((*(char *)((int)ppLVar7 + 0x25) != '\0') && (*(short *)(ppLVar7 + 6) < 1)) {
        (**(code **)(ppLVar7[1]->id + 4))(this,0,0,1,0xffffffff,0);
        *(undefined2 *)(ppLVar7 + 6) = *(undefined2 *)((int)ppLVar7 + 0x12);
      }
      pCVar4 = getCurCamera();
      local_3c = (this->prevPos).x - (pCVar4->prevPos44).x;
      local_38 = (this->prevPos).y - (pCVar4->prevPos44).y;
      local_34 = (this->prevPos).z - (pCVar4->prevPos44).z;
      dVar8 = sqrt((double)(local_34 * local_34 + local_3c * local_3c + local_38 * local_38));
      if (dVar8 != 0.0) {
        local_3c = (float)((double)local_3c / dVar8) * 20.0;
        local_38 = (float)((double)local_38 / dVar8) * 20.0;
        local_34 = (float)((double)local_34 / dVar8) * 20.0;
      }
      local_48 = (param1->prevPos).x;
      local_44 = (param1->prevPos).y;
      local_40 = (param1->prevPos).z;
      local_4c = 1.0;
      local_54 = 0;
      local_50 = 0;
      local_52 = 0;
      if ((int)this->flags_0xf8 < 1) {
        if (*(char *)((int)ppLVar7 + 0x25) == '\0') {
          if ((*(char *)((int)ppLVar7 + 0x25) == '\0') && ((int)this->field76_0xf4 < 200)) {
            uStack_2c = randInt(0,10);
            uStack_2c = uStack_2c ^ 0x80000000;
            local_30 = 0x43300000;
            FUN_8006ae50((double)((float)((double)CONCAT44(0x43300000,uStack_2c) -
                                         4503601774854144.0) * 0.05));
          }
        }
        else {
          for (sVar6 = 0; sVar6 < *(short *)(ppLVar7 + 5); sVar6 = sVar6 + 1) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0x79,&local_54,1,0xffffffff,0);
          }
          uStack_2c = randInt(0,10);
          uStack_2c = uStack_2c ^ 0x80000000;
          local_30 = 0x43300000;
          FUN_8006ae50((double)((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0)
                               * 0.1));
        }
        local_48 = (this->prevPos).x + local_3c;
        local_44 = (this->prevPos).y + local_38;
        local_40 = (this->prevPos).z + local_34;
      }
      else {
        this->flags_0xf8 = this->flags_0xf8 - (uint)framesThisStep;
        if (((int)this->flags_0xf8 < 1) && (*(char *)((int)ppLVar7 + 0x25) == '\0')) {
          local_48 = (param1->prevPos).x;
          local_44 = (param1->prevPos).y;
          local_40 = (param1->prevPos).z;
          local_4c = 1.0;
          local_54 = 0;
          local_50 = 0;
          local_52 = 0;
          FUN_8006ae50(8.0);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x75,&local_54,1,0xffffffff,0);
        }
      }
      this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
    }
    if (((*(short *)((int)ppLVar7 + 0x22) != 0) && (*(char *)((int)ppLVar7 + 0x26) != '\0')) &&
       (*(ushort *)((int)ppLVar7 + 0x22) = *(short *)((int)ppLVar7 + 0x22) - (ushort)framesThisStep,
       *(short *)((int)ppLVar7 + 0x22) < 1)) {
      loadEnvfxAction(this,this,DAT_80396e18 & 0xffff,0);
      *(undefined2 *)((int)ppLVar7 + 0x22) = 0;
    }
    if (((*(short *)(ppLVar7 + 8) != 0) && (*(char *)((int)ppLVar7 + 0x26) != '\0')) &&
       (*(ushort *)(ppLVar7 + 8) = *(short *)(ppLVar7 + 8) - (ushort)framesThisStep,
       *(short *)(ppLVar7 + 8) < 1)) {
      warpToMap((int)(char)pOVar5[1].allocatedSize,false);
      *(undefined *)((int)ppLVar7 + 0x26) = 0;
      *(undefined2 *)(ppLVar7 + 8) = 0;
    }
    if (((param1 == (ObjInstance *)0x0) || (param1->child[0] == (ObjInstance *)0x0)) ||
       (0xfe < param1->newOpacity)) {
      if ((param1 != (ObjInstance *)0x0) && (param1->child[0] != (ObjInstance *)0x0)) {
        param1->child[0]->newOpacity = 0xff;
      }
    }
    else {
      param1->child[0]->newOpacity = 0;
    }
    (this->pos).rotation.x = (this->pos).rotation.x + 1000;
  }
  return;
}


/* @description Override hit detection */

void autoTransporter_hitDetect(ObjInstance *this) { //801F5F70
  return;
}


/* @description Override render */

void autoTransporter_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801F5F74
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if (bVar1) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    autoTransporter_func07
    dll_139_func07
   
   Library: KioskDefault 0 0 */

void autoTransporter_free(ObjInstance *this,int param2) { //801F5FCC
  LoadedDll **ppLVar1;
  
  ppLVar1 = (LoadedDll **)this->state;
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  if (*ppLVar1 != (LoadedDll *)0x0) {
    DLL_free(*ppLVar1);
  }
  if (ppLVar1[1] != (LoadedDll *)0x0) {
    DLL_free(ppLVar1[1]);
  }
  if (ppLVar1[2] != (LoadedDll *)0x0) {
    DLL_free(ppLVar1[2]);
  }
  *ppLVar1 = (LoadedDll *)0x0;
  ppLVar1[1] = (LoadedDll *)0x0;
  ppLVar1[2] = (LoadedDll *)0x0;
  return;
}


undefined4 autoTransporter_func08(ObjInstance *this) { //801F6064
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int autoTransporter_getExtraSize(void) { //801F606C
  return 0x28;
}

