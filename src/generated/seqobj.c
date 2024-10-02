
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void seqObj_initialise(undefined4 param) { //801DBEB8
  return;
}


/* @description Called when DLL is unloaded */

void seqObj_release(void) { //801DBEBC
  return;
}


/* Library Function - Single Match
    seqObj_func03
   
   Library: KioskDefault 0 0 */

void seqObj_init(ObjInstance *param1,short *param2,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801DBEC0
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = param1->state;
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0xe) << 8;
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801dc25c;
  param1->curModel = *(byte *)((int)param2 + 0x1f);
  if (param1->data->nModels <= (char)param1->curModel) {
    param1->curModel = 0;
    printf("SEQOBJ.c: modelno out of range romdefno=%d",(int)*param2);
  }
  Object_objAddObjectType(param1,0x11);
  *pbVar2 = 0;
  if (((param2[0xc] != -1) && (uVar1 = mainGetBit((int)param2[0xc]), uVar1 != 0)) &&
     (*pbVar2 = *pbVar2 | 1, param2[0x10] != 0)) {
    *pbVar2 = *pbVar2 | 2;
  }
  pbVar2[1] = 0;
  param1->flags_0xb0 = param1->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    seqObj_func04
   
   Library: KioskDefault 0 0 */

void seqObj_update(ObjInstance *this) { //801DBFB4
  short sVar1;
  short sVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  ObjDef *pOVar6;
  
  pbVar5 = this->state;
  pOVar6 = this->def;
  if (pOVar6[1].bound != 0xff) {
    if ((*pbVar5 & 4) != 0) {
      if ((pOVar6[1].mapStates2 & 1) == 0) {
        if ((pOVar6[1].mapStates2 & 8) != 0) {
          mainSetBits((int)(short)pOVar6[1].objType,1);
        }
        *pbVar5 = *pbVar5 | 1;
      }
      else if ((pOVar6[1].mapStates2 & 4) == 0) {
        sVar1._0_1_ = pOVar6[1].allocatedSize;
        sVar1._1_1_ = pOVar6[1].mapStates1;
        mainSetBits((int)sVar1,0);
      }
      *pbVar5 = *pbVar5 & 0xfb;
    }
    if ((*pbVar5 & 1) == 0) {
      uVar3 = mainGetBit((int)(short)pOVar6[1].objType);
      if (uVar3 != 0) {
        *pbVar5 = *pbVar5 | 1;
      }
      sVar2._0_1_ = pOVar6[1].allocatedSize;
      sVar2._1_1_ = pOVar6[1].mapStates1;
      uVar3 = mainGetBit((int)sVar2);
      bVar4 = (byte)uVar3;
      if ((bVar4 != pbVar5[1]) && (pbVar5[1] = bVar4, bVar4 != 0)) {
        if (pOVar6[1].bound != 0xff) {
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)(char)pOVar6[1].bound,this,0xffffffff);
        }
        if (((pOVar6[1].mapStates2 & 1) == 0) && ((pOVar6[1].mapStates2 & 10) == 0)) {
          mainSetBits((int)(short)pOVar6[1].objType,1);
        }
      }
    }
    else if ((*pbVar5 & 2) == 0) {
      if (((pOVar6[1].mapStates2 & 1) != 0) &&
         (uVar3 = mainGetBit((int)(short)pOVar6[1].objType), uVar3 == 0)) {
        *pbVar5 = *pbVar5 & 0xfe;
      }
    }
    else {
                    /* {@symbol 800d0a70} */
      (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)*(short *)&pOVar6[1].pos.x);
      if ((pOVar6[1].mapStates2 & 0x10) == 0) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))((int)(char)pOVar6[1].bound,this,1);
      }
      else {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))
                  ((int)(char)pOVar6[1].bound,this,*(undefined2 *)((int)&pOVar6[1].pos.x + 2));
      }
      *pbVar5 = *pbVar5 & 0xfd;
    }
  }
  return;
}


/* @description Override hit detection */

void seqObj_hitDetect(ObjInstance *this) { //801DC1C0
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void seqObj_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801DC1C4
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


/* Library Function - Multiple Matches With Different Base Names
    dll_115_func07
    dll_20A_func07
    newSeqObj_func07
    seqObj11D_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void seqObj_free(ObjInstance *this,int param2) { //801DC220
  Object_removePlayerObj(this,0x11);
  return;
}


undefined4 seqObj_func08(ObjInstance *this) { //801DC24C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int seqObj_getExtraSize(void) { //801DC254
  return 2;
}

