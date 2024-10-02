
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void shrine1C2_initialise(undefined4 param) { //8023F438
  return;
}


/* @description Called when DLL is unloaded */

void shrine1C2_release(void) { //8023F43C
  return;
}


/* Library Function - Single Match
    dll_1C2_func03
   
   Library: KioskDefault 0 0 */

void shrine1C2_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8023F440
  short sVar1;
  LoadedDll *dll;
  short sVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  (this->pos).rotation.x = 0;
  *psVar3 = 10;
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  if (0 < sVar2) {
    sVar1._0_1_ = objDef[1].allocatedSize;
    sVar1._1_1_ = objDef[1].mapStates1;
    *psVar3 = sVar1 >> 8;
  }
  *(undefined *)((int)psVar3 + 0x1b) = 0;
  *(undefined *)(psVar3 + 0xe) = 0;
  psVar3[1] = 0;
  psVar3[2] = 0;
  psVar3[8] = 0;
  psVar3[9] = 0;
  psVar3[0xb] = 0;
  psVar3[0xc] = -1;
  *(undefined *)(psVar3 + 0xd) = 0;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80240610;
  objAllocMsgQueue(this,4);
  mainSetBits(0x129,1);
  mainSetBits(0x143,0);
  mainSetBits(0x126,1);
  mainSetBits(0x127,1);
  mainSetBits(0x12d,0);
  psVar3[3] = 0xc;
  psVar3[5] = 0x1e;
  psVar3[1] = 200;
                    /* {@symbol 8011bc7c} */
  (**(code **)(*pDll05 + 0x18))(2,0x2b,0x50,1,0);
  psVar3[4] = 0;
  psVar3[6] = 0;
  *(undefined *)((int)psVar3 + 0x1d) = 0;
  dll = (LoadedDll *)runlinkDownloadCode(0x1012,1);
  sVar2 = (**(code **)(dll->id + 4))(this,2,0,0x402,0xffffffff,0);
  psVar3[7] = sVar2;
  DLL_free(dll);
  DAT_80399f04 = this;
  Object_objAddObjectType(this,0xd);
  return;
}


/* Library Function - Single Match
    dll_1C2_func04
   
   Library: KioskDefault 0 0 */

void shrine1C2_update(ObjInstance *this) { //8023F5E4
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  ObjInstance *this_00;
  ObjInstance *pOVar9;
  int iVar10;
  byte bVar13;
  LoadedDll *pLVar11;
  short sVar12;
  uint uVar14;
  short *psVar15;
  double dVar16;
  double dVar17;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  double local_40;
  double local_38;
  
  psVar15 = (short *)this->state;
  this_00 = Object_objGetMain();
  local_48 = 0;
  local_44 = 0;
  local_4c = 1000.0;
  dVar16 = (double)FUN_802408a4((int)this);
  mainSetBits(0x127,1);
  if (psVar15[4] != 0) {
    psVar15[3] = psVar15[3] + psVar15[4];
    if (psVar15[3] < 0xd) {
      psVar15[3] = 0xc;
      psVar15[4] = 0;
    }
    else if (0x45 < psVar15[3]) {
      psVar15[3] = 0x46;
      psVar15[4] = 0;
    }
                    /* {@symbol 8011bcac} */
    dVar16 = (double)(**(code **)(*pDll05 + 0x38))(2,psVar15[3] & 0xff);
  }
  if (psVar15[6] != 0) {
    psVar15[5] = psVar15[5] + psVar15[6];
    if ((psVar15[5] < 2) && (psVar15[6] < 1)) {
      psVar15[5] = 1;
      psVar15[6] = 0;
    }
    else if ((0x45 < psVar15[5]) && (-1 < psVar15[6])) {
      psVar15[5] = 0x46;
      psVar15[6] = 0;
    }
                    /* {@symbol 8011bcac} */
    dVar16 = (double)(**(code **)(*pDll05 + 0x38))(3,psVar15[5] & 0xff);
  }
  if (psVar15[1] < 1) {
    pOVar9 = getSeqObj(0x10,this_00,&local_4c);
    if (((pOVar9 != (ObjInstance *)0x0) && (dVar16 = (double)local_4c, dVar16 < 300.0)) &&
       (dVar16 = (double)local_4c, 100.0 < dVar16)) {
      dVar16 = (double)(pOVar9->pos).pos.z;
      dVar17 = (double)(float)(dVar16 - (double)(this_00->pos).pos.z);
      if (dVar17 <= 0.0) {
        if (dVar17 < 0.0) {
          dVar17 = (double)(float)(dVar17 * -1.0);
        }
        if (psVar15[5] != 0x1e) {
          psVar15[5] = 0x1e;
        }
        local_38 = (double)CONCAT44(0x43300000,(int)psVar15[5] ^ 0x80000000);
        uVar14 = (uint)((float)(local_38 - 4503601774854144.0) * ((float)(dVar17 - 100.0) / 200.0));
        local_40 = (double)(longlong)(int)uVar14;
        if ((short)uVar14 < 1) {
          uVar14 = 1;
        }
                    /* {@symbol 8011bcac} */
        (**(code **)(*pDll05 + 0x38))(3,uVar14 & 0xff);
        local_40 = (double)CONCAT44(0x43300000,(int)psVar15[3] ^ 0x80000000);
        uVar14 = (uint)((float)(local_40 - 4503601774854144.0) *
                       ((200.0 - (float)(dVar17 - 100.0)) / 200.0));
        local_38 = (double)(longlong)(int)uVar14;
        if ((short)uVar14 < 1) {
          uVar14 = 1;
        }
                    /* {@symbol 8011bcac} */
        dVar16 = (double)(**(code **)(*pDll05 + 0x38))(2,uVar14 & 0xff);
      }
    }
    if (true) {
                    /* {@symbol 8023f938} */
      switch(*(undefined *)((int)psVar15 + 0x1b)) {
      case 0:
        objDistObj2Obj(this,this_00);
        local_40 = (double)CONCAT44(0x43300000,(int)*psVar15 ^ 0x80000000);
        if (dVar16 < (double)(float)(local_40 - 4503601774854144.0)) {
          *(undefined *)((int)psVar15 + 0x1b) = 1;
          mainSetBits(0x129,0);
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
          pLVar11 = (LoadedDll *)runlinkDownloadCode(0x102b,1);
          (**(code **)(pLVar11->id + 4))(this,2,0,1,0xffffffff,0);
          DLL_free(pLVar11);
          pLVar11 = (LoadedDll *)runlinkDownloadCode(0x102c,1);
          (**(code **)(pLVar11->id + 4))(this,0,0,1,0xffffffff,0);
          DLL_free(pLVar11);
          mainSetBits(0x126,0);
                    /* {@symbol 800e3b54} */
          (**(code **)(*(int *)pDll_projgfx + 0x20))(psVar15 + 7);
        }
        break;
      case 1:
        if (*(char *)(psVar15 + 0xe) == '\x01') {
          *(undefined *)((int)psVar15 + 0x1b) = 2;
          psVar15[1] = 200;
          psVar15[0xb] = 6;
          audioTryStartSfx((int *)this,1,0x239,0x7f,"shrine.c",0x12d);
          psVar15[2] = 0;
        }
        break;
      case 2:
        *(undefined *)((int)psVar15 + 0x1b) = 3;
        psVar15[1] = 0x50;
        psVar15[0xb] = 8;
        psVar15[2] = 0x28;
        psVar15[9] = 0x10;
        iVar10 = randInt(0,5);
        *(char *)(psVar15 + 0xd) = (char)iVar10;
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(3,this,0xffffffff);
        break;
      case 3:
      case 4:
      case 5:
        if (psVar15[2] < 1) {
          if (true) {
                    /* {@symbol 8023fe30} */
            switch(psVar15[0xb]) {
            case 0:
              psVar15[0xb] = 1;
              psVar15[2] = 0xc;
              break;
            case 1:
              psVar15[0xb] = 4;
              psVar15[2] = 0;
              break;
            case 2:
              psVar15[9] = psVar15[9] + -1;
              if (psVar15[9] < 1) {
                psVar15[0xb] = 5;
                psVar15[10] = 1000;
              }
              else {
                psVar15[0xb] = 0;
                psVar15[2] = 2;
                if (*(char *)((int)psVar15 + 0x1b) == '\x03') {
                  iVar10 = randInt(0,1);
                }
                else if (*(char *)((int)psVar15 + 0x1b) == '\x04') {
                  iVar10 = randInt(0,5);
                }
                else {
                  iVar10 = randInt(0,7);
                }
                uVar8 = DAT_80319932;
                uVar7 = DAT_80319930;
                uVar6 = DAT_8031992a;
                uVar5 = DAT_80319928;
                uVar4 = DAT_80319924;
                uVar3 = DAT_80319920;
                uVar2 = DAT_80319904;
                uVar1 = DAT_80319900;
                if (iVar10 == 0) {
                  for (iVar10 = 0; iVar10 < 6; iVar10 = iVar10 + 1) {
                    (&DAT_80319928)[iVar10] = (&DAT_80319928)[iVar10] + 1;
                    if (5 < (short)(&DAT_80319928)[iVar10]) {
                      (&DAT_80319928)[iVar10] = 0;
                    }
                  }
                }
                else if (iVar10 == 1) {
                  for (iVar10 = 0; iVar10 < 6; iVar10 = iVar10 + 1) {
                    (&DAT_80319928)[iVar10] = (&DAT_80319928)[iVar10] + -1;
                    if ((short)(&DAT_80319928)[iVar10] < 0) {
                      (&DAT_80319928)[iVar10] = 5;
                    }
                  }
                }
                else if (iVar10 == 2) {
                  DAT_80319928 = DAT_8031992c;
                  DAT_8031992c = DAT_80319930;
                  DAT_80319930 = uVar5;
                }
                else if (iVar10 == 3) {
                  DAT_80319930 = DAT_80319928;
                  DAT_80319928 = DAT_8031992c;
                  DAT_8031992c = uVar7;
                }
                else if (iVar10 == 4) {
                  DAT_8031992a = DAT_8031992e;
                  DAT_8031992e = DAT_80319932;
                  DAT_80319932 = uVar6;
                }
                else if (iVar10 == 5) {
                  DAT_80319932 = DAT_8031992a;
                  DAT_8031992a = DAT_8031992e;
                  DAT_8031992e = uVar8;
                }
                else if (iVar10 == 6) {
                  DAT_80319900 = DAT_80319908;
                  DAT_80319904 = DAT_8031990c;
                  DAT_80319908 = DAT_80319918;
                  DAT_8031990c = DAT_8031991c;
                  DAT_80319918 = DAT_80319920;
                  DAT_8031991c = DAT_80319924;
                  DAT_80319920 = uVar1;
                  DAT_80319924 = uVar2;
                }
                else if (iVar10 == 7) {
                  DAT_80319920 = DAT_80319918;
                  DAT_80319924 = DAT_8031991c;
                  DAT_80319918 = DAT_80319908;
                  DAT_8031991c = DAT_8031990c;
                  DAT_80319908 = DAT_80319900;
                  DAT_8031990c = DAT_80319904;
                  DAT_80319900 = uVar3;
                  DAT_80319904 = uVar4;
                }
              }
              break;
            case 4:
              psVar15[0xb] = 2;
              psVar15[2] = 0;
              break;
            case 5:
              if (psVar15[0xc] == 0) {
                *(undefined *)((int)psVar15 + 0x1b) = 9;
                    /* {@symbol 8011bc7c} */
                (**(code **)(*pDll05 + 0x18))(3,0x35,0x50,psVar15[5] & 0xff,0);
                psVar15[6] = 1;
                    /* {@symbol 800d022c} */
                (**(code **)(*(int *)pDll_checkpoint + 0x48))(2,this,0xffffffff);
                psVar15[1] = 10;
                psVar15[0xb] = 7;
                audioTryStartSfx((int *)this,1,0x239,0x7f,"shrine.c",0x1c0);
              }
              else if (psVar15[0xc] == 1) {
                if (*(char *)((int)psVar15 + 0x1b) == '\x03') {
                  iVar10 = randInt(0,5);
                  *(char *)(psVar15 + 0xd) = (char)iVar10;
                  *(undefined *)((int)psVar15 + 0x1b) = 4;
                  psVar15[0xb] = 9;
                  psVar15[1] = 0x96;
                  psVar15[2] = 0xc;
                  psVar15[9] = 10;
                  psVar15[0xc] = -1;
                  audioTryStartSfx((int *)this,1,0x15f,0x7f,"shrine.c",0x1cb);
                    /* {@symbol 800d022c} */
                  (**(code **)(*(int *)pDll_checkpoint + 0x48))(3,this,0xffffffff);
                }
                else if (*(char *)((int)psVar15 + 0x1b) == '\x04') {
                  iVar10 = randInt(0,5);
                  *(char *)(psVar15 + 0xd) = (char)iVar10;
                  *(undefined *)((int)psVar15 + 0x1b) = 5;
                  psVar15[0xb] = 9;
                  psVar15[1] = 0x96;
                  psVar15[2] = 0xc;
                  psVar15[9] = 0x10;
                  psVar15[0xc] = -1;
                  audioTryStartSfx((int *)this,1,0x15f,0x7f,"shrine.c",0x1d6);
                    /* {@symbol 800d022c} */
                  (**(code **)(*(int *)pDll_checkpoint + 0x48))(3,this,0xffffffff);
                }
                else {
                  psVar15[1] = 0x82;
                  *(undefined *)((int)psVar15 + 0x1b) = 6;
                  psVar15[0xb] = 3;
                  psVar15[0xc] = 0;
                  psVar15[0xb] = 7;
                  audioTryStartSfx((int *)this,1,0x15f,0x7f,"shrine.c",0x1df);
                  audioTryStartSfx((int *)this,2,0x239,0x7f,"shrine.c",0x1e0);
                }
              }
              else {
                psVar15[10] = psVar15[10] - (ushort)framesThisStep;
                if (psVar15[10] < 1) {
                  psVar15[1] = 0x82;
                  *(undefined *)((int)psVar15 + 0x1b) = 6;
                  psVar15[0xb] = 3;
                  psVar15[0xc] = 0;
                  psVar15[0xb] = 7;
                  audioTryStartSfx((int *)this,1,0x15f,0x7f,"shrine.c",0x1eb);
                  audioTryStartSfx((int *)this,2,0x239,0x7f,"shrine.c",0x1ec);
                }
              }
              break;
            case 7:
              psVar15[0xb] = 3;
              psVar15[2] = 0x28;
              psVar15[1] = 0x3c;
              break;
            case 8:
              psVar15[0xb] = 2;
              psVar15[2] = 0x28;
              psVar15[1] = 0x3c;
              break;
            case 9:
              psVar15[0xb] = 8;
              psVar15[2] = 0x28;
              psVar15[1] = 0x3c;
            }
          }
        }
        else {
          psVar15[2] = psVar15[2] + -1;
          if (psVar15[2] < 0) {
            psVar15[2] = 0;
          }
        }
        break;
      case 6:
        bVar13 = FUN_801a80e8((int)this_00,2);
        if (bVar13 == 0) {
          mainSetBits(0x126,0);
                    /* {@symbol 8011bc7c} */
          (**(code **)(*pDll05 + 0x18))(3,0x2c,0x50,psVar15[5] & 0xff,0);
          psVar15[6] = 1;
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
          *(undefined *)((int)psVar15 + 0x1b) = 7;
        }
        else {
          psVar15[5] = 1;
                    /* {@symbol 8011bc7c} */
          (**(code **)(*pDll05 + 0x18))(3,0x2c,0x50,psVar15[5] & 0xff,0);
          psVar15[6] = 1;
          mainSetBits(0x129,1);
          *(undefined *)((int)psVar15 + 0x1b) = 8;
        }
        break;
      case 7:
        mainSetBits(0x143,0);
        *(undefined *)((int)psVar15 + 0x1b) = 8;
        FUN_801a8108((int)this_00,8,1);
                    /* {@symbol 8012decc} */
        (**(code **)(*(int *)pDll_SaveGame + 0x44))(0xb,5);
        break;
      case 8:
        uVar14 = mainGetBit(0xfd);
        if (uVar14 == 0) {
          mainSetBits(0xfd,1);
        }
        mainSetBits(0x127,0);
        mainSetBits(0x129,0);
        *(undefined *)((int)psVar15 + 0x1b) = 10;
        break;
      case 9:
        *(undefined *)((int)psVar15 + 0x1b) = 0;
        psVar15[2] = 0;
        psVar15[8] = 0;
        psVar15[9] = 0;
        psVar15[0xb] = 0;
        psVar15[0xc] = -1;
        psVar15[2] = 0;
        *(undefined *)(psVar15 + 0xd) = 0;
        *(undefined *)(psVar15 + 0xe) = 0;
        psVar15[1] = 400;
        mainSetBits(0x129,1);
        mainSetBits(0x126,1);
        mainSetBits(0x127,1);
        pLVar11 = (LoadedDll *)runlinkDownloadCode(0x1012,1);
        sVar12 = (**(code **)(pLVar11->id + 4))(this,2,0,0x402,0xffffffff,0);
        psVar15[7] = sVar12;
        DLL_free(pLVar11);
      }
    }
  }
  else {
    psVar15[1] = psVar15[1] - (ushort)framesThisStep;
    if ((psVar15[1] < 1) && (psVar15[1] = 0, *(char *)((int)psVar15 + 0x1d) == '\0')) {
                    /* {@symbol 8011bc7c} */
      (**(code **)(*pDll05 + 0x18))(3,0x2c,0x50,(int)psVar15[5],0);
      *(undefined *)((int)psVar15 + 0x1d) = 1;
    }
  }
  return;
}


/* @description Override hit detection */

void shrine1C2_hitDetect(ObjInstance *this) { //80240350
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19C_func06
    dll_1C2_func06
    dll_1C5_func06
    dll_1D3_func06
     6 names - too many to list
   
   Library: KioskDefault 0 0 */

void shrine1C2_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //80240354
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  short *psVar1;
  
  psVar1 = (short *)this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(int)*psVar1 ^ 0x80000000) -
                                  4503601774854144.0),25.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1C2_func07
   
   Library: KioskDefault 0 0 */

void shrine1C2_free(ObjInstance *this,int param2) { //80240410
  Object_removePlayerObj(this,0xd);
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 8011bcac} */
  (**(code **)(*pDll05 + 0x38))(3,0);
                    /* {@symbol 8011bcac} */
  (**(code **)(*pDll05 + 0x38))(2,0);
  return;
}


undefined4 shrine1C2_func08(ObjInstance *this) { //80240494
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int shrine1C2_getExtraSize(void) { //8024049C
  return 0x1e;
}


/* Library Function - Single Match
    dll_1C2_func0A
   
   Library: KioskDefault 0 0 */

void shrine1C2_setScale(ObjInstance *this,float scale) { //802404A4
  if (DAT_80399f04 != 0) {
    (this->pos).rotation.x = *(short *)(*(int *)(DAT_80399f04 + 0xb8) + 0x10);
  }
  return;
}


/* Library Function - Single Match
    dll_1C2_func0B
   
   Library: KioskDefault 0 0 */

void shrine1C2_func0B(uint param1,undefined4 *param2,undefined4 *param3) { //802404D4
  if (DAT_80399f04 != 0) {
    *param2 = (&PTR_803198f8)[(short)(&DAT_80319928)[param1 & 0xff] * 2];
    *param3 = (&PTR_803198f8)[(short)(&DAT_80319928)[param1 & 0xff] * 2 + 1];
  }
  return;
}


/* Library Function - Single Match
    dll_1C2_func0C
   
   Library: KioskDefault 0 0 */

void shrine1C2_modelMtxFn(ObjInstance *this,undefined *param2,vec3f *param3) { //80240534
  int iVar1;
  
  if (DAT_80399f04 != 0) {
    iVar1 = *(int *)(DAT_80399f04 + 0xb8);
    *param2 = *(undefined *)(iVar1 + 0x1a);
    iVar1 = (int)*(short *)(iVar1 + 0x16);
    (this->pos).rotation.x = (short)((uint)iVar1 >> 0x10);
    (this->pos).rotation.y = (short)iVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_1C2_func0D
   
   Library: KioskDefault 0 0 */

void shrine1C2_render2(ObjInstance *this) { //8024056C
  double in_f1;
  double in_f2;
  
  if (DAT_80399f04 != 0) {
    (&PTR_803198f8)[(short)(&DAT_80319928)[(uint)this & 0xff] * 2] = (undefined *)(float)in_f1;
    (&PTR_803198f8)[(short)(&DAT_80319928)[(uint)this & 0xff] * 2 + 1] = (undefined *)(float)in_f2;
  }
  return;
}


/* Library Function - Single Match
    dll_1C2_func0E
   
   Library: KioskDefault 0 0 */

void shrine1C2_func0E(char param1) { //802405C4
  int iVar1;
  
  if (DAT_80399f04 != 0) {
    iVar1 = *(int *)(DAT_80399f04 + 0xb8);
    if (param1 == *(char *)(iVar1 + 0x1a)) {
      *(undefined2 *)(iVar1 + 0x18) = 1;
    }
    else {
      *(undefined2 *)(iVar1 + 0x18) = 0;
    }
  }
  return;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void shrine1CE_initialise(undefined4 param) { //80245D80
  return;
}


/* @description Called when DLL is unloaded */

void shrine1CE_release(void) { //80245D84
  return;
}


/* Library Function - Single Match
    dll_1CE_func03
   
   Library: KioskDefault 0 0 */

void shrine1CE_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //80245D88
  short sVar1;
  LoadedDll *dll;
  short sVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  (this->pos).rotation.x = 0;
  *psVar3 = 10;
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  if (0 < sVar2) {
    sVar1._0_1_ = objDef[1].allocatedSize;
    sVar1._1_1_ = objDef[1].mapStates1;
    *psVar3 = sVar1 >> 2;
  }
  *(undefined *)(psVar3 + 9) = 0;
  *(undefined *)((int)psVar3 + 0x13) = 0;
  psVar3[1] = 0;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80246780;
  objAllocMsgQueue(this,4);
  mainSetBits(0x129,1);
  mainSetBits(0x15f,0);
  mainSetBits(0x126,1);
  mainSetBits(0x127,1);
  mainSetBits(0x128,0);
  *(undefined *)((int)psVar3 + 0x17) = 0;
  psVar3[2] = 0xc;
  psVar3[4] = 0x1e;
  psVar3[1] = 200;
                    /* {@symbol 8011bc7c} */
  (**(code **)(*pDll05 + 0x18))(2,0x2b,0x50,1,0);
  psVar3[3] = 0;
  psVar3[5] = 0;
  *(undefined *)((int)psVar3 + 0x15) = 0;
  *(undefined *)(psVar3 + 0xb) = 0;
  psVar3[7] = 300;
  psVar3[8] = 0x514;
  dll = (LoadedDll *)runlinkDownloadCode(0x1012,1);
  sVar2 = (**(code **)(dll->id + 4))(this,3,0,0x402,0xffffffff,0);
  psVar3[6] = sVar2;
  DLL_free(dll);
  return;
}


/* Library Function - Single Match
    dll_1CE_func04
   
   Library: KioskDefault 0 0 */

void shrine1CE_update(ObjInstance *this) { //80245F0C
  ObjInstance *this_00;
  ObjInstance *pOVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  double dVar5;
  double dVar6;
  float local_34;
  double local_30;
  double local_28;
  
  psVar4 = (short *)this->state;
  this_00 = Object_objGetMain();
  local_34 = 1000.0;
  (this->prevPos).x = (this->pos).pos.x;
  (this->prevPos).y = (this->pos).pos.y;
  (this->prevPos).z = (this->pos).pos.z;
  dVar5 = (double)FUN_80246b08((int)this);
  mainSetBits(0x127,1);
  if (psVar4[3] != 0) {
    psVar4[2] = psVar4[2] + psVar4[3];
    if (psVar4[2] < 0xd) {
      psVar4[2] = 0xc;
      psVar4[3] = 0;
    }
    else if (0x45 < psVar4[2]) {
      psVar4[2] = 0x46;
      psVar4[3] = 0;
    }
                    /* {@symbol 8011bcac} */
    dVar5 = (double)(**(code **)(*pDll05 + 0x38))(2,psVar4[2] & 0xff);
  }
  if (psVar4[5] != 0) {
    psVar4[4] = psVar4[4] + psVar4[5];
    if ((psVar4[4] < 2) && (psVar4[5] < 1)) {
      psVar4[4] = 1;
      psVar4[5] = 0;
    }
    else if ((0x45 < psVar4[4]) && (-1 < psVar4[5])) {
      psVar4[4] = 0x46;
      psVar4[5] = 0;
    }
                    /* {@symbol 8011bcac} */
    dVar5 = (double)(**(code **)(*pDll05 + 0x38))(3,psVar4[4] & 0xff);
  }
  if (psVar4[1] < 1) {
    pOVar1 = getSeqObj(0x10,this_00,&local_34);
    if (((pOVar1 != (ObjInstance *)0x0) && (dVar5 = (double)local_34, dVar5 < 300.0)) &&
       (dVar5 = (double)local_34, 100.0 < dVar5)) {
      dVar5 = (double)(pOVar1->pos).pos.z;
      dVar6 = (double)(float)(dVar5 - (double)(this_00->pos).pos.z);
      if (dVar6 <= 0.0) {
        if (dVar6 < 0.0) {
          dVar6 = (double)(float)(dVar6 * -1.0);
        }
        if (psVar4[4] != 0x1e) {
          psVar4[4] = 0x1e;
        }
        local_28 = (double)CONCAT44(0x43300000,(int)psVar4[4] ^ 0x80000000);
        uVar3 = (uint)((float)(local_28 - 4503601774854144.0) * ((float)(dVar6 - 100.0) / 200.0));
        local_30 = (double)(longlong)(int)uVar3;
        if ((short)uVar3 < 1) {
          uVar3 = 1;
        }
                    /* {@symbol 8011bcac} */
        (**(code **)(*pDll05 + 0x38))(3,uVar3 & 0xff);
        local_30 = (double)CONCAT44(0x43300000,(int)psVar4[2] ^ 0x80000000);
        uVar3 = (uint)((float)(local_30 - 4503601774854144.0) *
                      ((200.0 - (float)(dVar6 - 100.0)) / 200.0));
        local_28 = (double)(longlong)(int)uVar3;
        if ((short)uVar3 < 1) {
          uVar3 = 1;
        }
                    /* {@symbol 8011bcac} */
        dVar5 = (double)(**(code **)(*pDll05 + 0x38))(2,uVar3 & 0xff);
      }
    }
    if (true) {
                    /* {@symbol 8024628c} */
      switch(*(undefined *)(psVar4 + 9)) {
      case 0:
        if (psVar4[7] < 1) {
          mainSetBits(0x176,1);
          dVar5 = (double)FUN_8006ae50(1.0);
          iVar2 = randInt(100,0x96);
          psVar4[7] = (short)iVar2;
          psVar4[8] = 0x91;
        }
        else {
          if (psVar4[8] != -999) {
            if (psVar4[8] < 0) {
              dVar5 = 127.0;
              audioTryStartSfx((int *)this,1,0x3b,0x7f,"shrine.c",0x10e);
              psVar4[8] = -999;
            }
            else {
              psVar4[8] = psVar4[8] - (ushort)framesThisStep;
            }
          }
          mainSetBits(0x176,0);
          psVar4[7] = psVar4[7] - (ushort)framesThisStep;
        }
        objDistObj2Obj(this,this_00);
        local_30 = (double)CONCAT44(0x43300000,(int)*psVar4 ^ 0x80000000);
        if (dVar5 < (double)(float)(local_30 - 4503601774854144.0)) {
          mainSetBits(0x5c6,1);
          *(undefined *)(psVar4 + 9) = 1;
          mainSetBits(0x129,0);
          *(undefined *)((int)psVar4 + 0x13) = 1;
                    /* {@symbol 800e3b54} */
          (**(code **)(*(int *)pDll_projgfx + 0x20))(psVar4 + 6);
        }
        break;
      case 1:
        if (*(char *)((int)psVar4 + 0x13) == '\x01') {
          *(undefined *)(psVar4 + 9) = 2;
        }
        break;
      case 2:
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(3,this,0xffffffff);
        *(undefined *)(psVar4 + 9) = 3;
        break;
      case 4:
        uVar3 = mainGetBit(0x15e);
        if (uVar3 == 0) {
          mainSetBits(0x126,0);
                    /* {@symbol 8011bc7c} */
          (**(code **)(*pDll05 + 0x18))(3,0x34,0x50,psVar4[4] & 0xff,0);
          psVar4[5] = 1;
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
          *(undefined *)(psVar4 + 9) = 5;
        }
        else {
          psVar4[4] = 1;
                    /* {@symbol 8011bc7c} */
          (**(code **)(*pDll05 + 0x18))(3,0x34,0x50,psVar4[4] & 0xff,0);
          psVar4[5] = 1;
          mainSetBits(0x129,1);
          *(undefined *)(psVar4 + 9) = 6;
        }
        break;
      case 5:
        uVar3 = mainGetBit(0xfd);
        if (uVar3 == 0) {
          mainSetBits(0xfd,1);
        }
        mainSetBits(0x15f,0);
        mainSetBits(0x127,0);
        mainSetBits(0x129,1);
        *(undefined *)(psVar4 + 9) = 6;
        mainSetBits(0x126,1);
        mainSetBits(0x15e,1);
                    /* {@symbol 8012decc} */
        (**(code **)(*(int *)pDll_SaveGame + 0x44))(0xb,9);
        break;
      case 6:
        uVar3 = mainGetBit(0x5c2);
        if (uVar3 == 0) {
          mainSetBits(0x5c2,1);
        }
        mainSetBits(0x5c6,0);
        break;
      case 7:
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(4,this,0xffffffff);
        break;
      case 8:
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(5,this,0xffffffff);
                    /* {@symbol 8011bc7c} */
        (**(code **)(*pDll05 + 0x18))(3,0x35,0x50,psVar4[4] & 0xff,0);
        mainSetBits(0x15f,0);
        mainSetBits(0x127,0);
        mainSetBits(0x129,1);
        mainSetBits(0x5be,0);
        mainSetBits(0x1cb,0);
        mainSetBits(0x5c6,0);
        *(undefined *)(psVar4 + 9) = 6;
      }
    }
  }
  else {
    psVar4[1] = psVar4[1] - (ushort)framesThisStep;
    if ((psVar4[1] < 1) && (psVar4[1] = 0, *(char *)((int)psVar4 + 0x15) == '\0')) {
                    /* {@symbol 8011bc7c} */
      (**(code **)(*pDll05 + 0x18))(3,0x34,0x50,(int)psVar4[4],0);
      *(undefined *)((int)psVar4 + 0x15) = 1;
    }
    if (((*(char *)(psVar4 + 9) == '\x02') && (psVar4[1] < 0x29)) &&
       (*(char *)(psVar4 + 0xb) == '\0')) {
      *(undefined *)(psVar4 + 0xb) = 1;
    }
  }
  return;
}


/* @description Override hit detection */

void shrine1CE_hitDetect(ObjInstance *this) { //80246650
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1CA_func06
    dll_1CE_func06
   
   Library: KioskDefault 0 0 */

void shrine1CE_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //80246654
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  short *psVar1;
  
  psVar1 = (short *)this->state;
  objRenderCurrentModel
            (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
             (int *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  if (((this->pos).flags & 0x100) != 0) {
    FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)(float)((double)CONCAT44(0x43300000,(int)*psVar1 ^ 0x80000000) -
                                4503601774854144.0),25.0,
                 (Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19C_func07
    dll_1C5_func07
    dll_1CE_func07
    dll_1D3_func07
   
   Library: KioskDefault 0 0 */

void shrine1CE_free(ObjInstance *this,int param2) { //80246700
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 8011bcac} */
  (**(code **)(*pDll05 + 0x38))(3,0);
                    /* {@symbol 8011bcac} */
  (**(code **)(*pDll05 + 0x38))(2,0);
  return;
}


undefined4 shrine1CE_func08(ObjInstance *this) { //80246770
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int shrine1CE_getExtraSize(void) { //80246778
  return 0x18;
}

