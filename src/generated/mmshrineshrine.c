
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void mmshrine_initialise(undefined4 param) { //8023DDF8
  return;
}


/* @description Called when DLL is unloaded */

void mmshrine_release(void) { //8023DDFC
  return;
}


/* Library Function - Single Match
    mmshrine_func03
   
   Library: KioskDefault 0 0 */

void mmshrine_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8023DE00
  short sVar1;
  short sVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  (this->pos).rotation.x = 0;
  *psVar3 = 10;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (0 < sVar1) {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    *psVar3 = sVar2 >> 8;
  }
  *(undefined *)((int)psVar3 + 9) = 0;
  *(undefined *)(psVar3 + 5) = 0;
  this->fptr_0xbc = shrineFn_8023e4d0;
  objAllocMsgQueue(this,4);
  mainSetBits(0x129,1);
  mainSetBits(299,0);
  mainSetBits(0x126,1);
  mainSetBits(0x127,1);
  mainSetBits(0x12d,0);
  psVar3[1] = 200;
  mainSetBits(0x40,1);
  return;
}


/* Library Function - Single Match
    mmshrine_func04
   
   Library: KioskDefault 0 0 */

void mmshrine_update(ObjInstance *this) { //8023DED4
  ObjInstance *param2;
  LoadedDll *pLVar1;
  short sVar3;
  uint uVar2;
  short *psVar4;
  double dVar5;
  
  psVar4 = (short *)this->state;
  param2 = Object_objGetMain();
  if (PTR_DAT_80397da8._0_1_ != '\0') {
    (this->prevPos).x = (this->pos).pos.x;
    (this->prevPos).y = (this->pos).pos.y;
    (this->prevPos).z = (this->pos).pos.z;
    audioPlaySong(9,2);
    mainSetBits(0x127,1);
    pLVar1 = (LoadedDll *)runlinkDownloadCode(0x1012,1);
    sVar3 = (**(code **)(pLVar1->id + 4))(this,1,0,0x402,0xffffffff,0);
    psVar4[2] = sVar3;
    DLL_free(pLVar1);
    PTR_DAT_80397da8._0_1_ = '\0';
  }
  uVar2 = mainGetBit(0x58c);
  if ((((uVar2 == 0) && (uVar2 = mainGetBit(0x96d), uVar2 != 0)) &&
      (uVar2 = mainGetBit(0x96e), uVar2 != 0)) && (uVar2 = mainGetBit(0x96f), uVar2 != 0)) {
    mainSetBits(0x58c,1);
  }
  dVar5 = (double)FUN_8023e734((int)this);
  if (0 < psVar4[1]) {
    psVar4[1] = psVar4[1] - (ushort)framesThisStep;
    if ((psVar4[1] < 1) && (psVar4[1] = 0, psVar4[3] == 0)) {
      psVar4[3] = 1;
    }
    if (*(char *)((int)psVar4 + 9) != '\x02') {
      return;
    }
    if (0x28 < psVar4[1]) {
      return;
    }
    if (*(char *)(psVar4 + 6) != '\0') {
      return;
    }
    *(undefined *)(psVar4 + 6) = 1;
    return;
  }
  if (false) {
switchD_8023e098_caseD_3:
    OSReport(s_<objControl>_mmshrineshrine_c_WA_80319790);
  }
  else {
                    /* {@symbol 8023e09c} */
    switch(*(undefined *)((int)psVar4 + 9)) {
    case 0:
      objDistObj2Obj(this,param2);
      if (dVar5 < (double)(float)((double)CONCAT44(0x43300000,(int)*psVar4 ^ 0x80000000) -
                                 4503601774854144.0)) {
        *(undefined *)((int)psVar4 + 9) = 1;
        mainSetBits(0x129,0);
                    /* {@symbol 800ce728} */
        (**(code **)(*(int *)pDll_checkpoint + 0x50))(0x5a,0,0,0);
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
        pLVar1 = (LoadedDll *)runlinkDownloadCode(0x102b,1);
        (**(code **)(pLVar1->id + 4))(this,1,0,1,0xffffffff,0);
        DLL_free(pLVar1);
        pLVar1 = (LoadedDll *)runlinkDownloadCode(0x102c,1);
        (**(code **)(pLVar1->id + 4))(this,0,0,1,0xffffffff,0);
        DLL_free(pLVar1);
        mainSetBits(0x126,0);
      }
      break;
    case 1:
      if (*(char *)(psVar4 + 5) == '\x01') {
        *(undefined *)((int)psVar4 + 9) = 2;
        psVar4[1] = 0;
      }
      break;
    case 2:
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(3,this,0xffffffff);
      *(undefined *)((int)psVar4 + 9) = 8;
      break;
    default:
      goto switchD_8023e098_caseD_3;
    case 4:
      uVar2 = mainGetBit(0x12a);
      if (uVar2 == 0) {
        mainSetBits(0x126,0);
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
      }
      else {
        *(undefined *)((int)psVar4 + 9) = 6;
      }
      break;
    case 5:
      uVar2 = mainGetBit(0xfd);
      if (uVar2 == 0) {
        mainSetBits(0xfd,1);
      }
      mainSetBits(299,0);
      mainSetBits(0x127,0);
      *(undefined *)((int)psVar4 + 9) = 6;
      mainSetBits(0x126,1);
      mainSetBits(0x12a,1);
                    /* {@symbol 8012decc} */
      (**(code **)(*(int *)pDll_SaveGame + 0x44))(0xb,4);
      break;
    case 6:
      break;
    case 7:
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(4,this,0xffffffff);
      *(undefined *)((int)psVar4 + 9) = 9;
      psVar4[1] = 0;
      break;
    case 8:
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(5,this,0xffffffff);
      *(undefined *)((int)psVar4 + 9) = 4;
      break;
    case 9:
      *(undefined *)((int)psVar4 + 9) = 0;
      *(undefined *)(psVar4 + 5) = 0;
      psVar4[1] = 400;
      mainSetBits(299,0);
      mainSetBits(0x126,1);
      pLVar1 = (LoadedDll *)runlinkDownloadCode(0x1012,1);
      sVar3 = (**(code **)(pLVar1->id + 4))(this,0,0,0x402,0xffffffff,0);
      psVar4[2] = sVar3;
      DLL_free(pLVar1);
    }
  }
  return;
}


/* @description Override hit detection */

void mmshrine_hitDetect(ObjInstance *this) { //8023E3C0
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_19C_func06
    dll_1C2_func06
    dll_1C5_func06
    dll_1D3_func06
     6 names - too many to list
   
   Library: KioskDefault 0 0 */

void mmshrine_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8023E3C4
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
    mmshrine_func07
   
   Library: KioskDefault 0 0 */

void mmshrine_free(ObjInstance *this,int param2) { //8023E480
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  audioStopSong(9);
  return;
}


undefined4 mmshrine_func08(ObjInstance *this) { //8023E4C0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int mmshrine_getExtraSize(void) { //8023E4C8
  return 0xe;
}

