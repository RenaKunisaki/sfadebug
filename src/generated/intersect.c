
void trackIntersect(void) { //800BACD8
  bool bVar1;
  s8 (*paasVar2) [16] [16];
  MapBlock *pMVar3;
  LineHit *pLVar4;
  undefined2 uVar6;
  int iVar5;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  short *psVar13;
  int iVar14;
  ModLineStruct1 *pMVar15;
  double dVar16;
  double dVar17;
  short asStack_d08 [1600];
  undefined2 local_88;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  
  _savefpr_27();
  didTrackIntersect = 0;
  if (bModLinesNeedUpdate == '\x01') {
    DAT_80398ddd = '\x01';
    bModLinesNeedUpdate = '\0';
  }
  else if (DAT_80398ddd != '\0') {
    DAT_80398ddd = '\0';
    maxModLine = 0;
    modLinePointCount = 0;
    for (iVar7 = 0; iVar7 < 5; iVar7 = iVar7 + 1) {
      paasVar2 = FUN_800a93c0(iVar7);
      for (uVar8 = 0; (int)uVar8 < 0x10; uVar8 = uVar8 + 1) {
        for (uVar9 = 0; (int)uVar9 < 0x10; uVar9 = uVar9 + 1) {
          if (-1 < (*paasVar2)[uVar8][uVar9]) {
            pMVar3 = mapGetBlockByIdx((int)(*paasVar2)[uVar8][uVar9]);
            for (iVar14 = 0; iVar14 < (int)(uint)pMVar3->numLineHits; iVar14 = iVar14 + 1) {
              pLVar4 = pMVar3->linehits;
              pMVar15 = int_linelist + maxModLine;
              *(undefined *)pMVar15 = pLVar4[iVar14].field_0xc;
              pMVar15->field1_0x1 = pLVar4[iVar14].field_0xd;
              pMVar15->field3_0x3 = pLVar4[iVar14].field11_0xf;
              pMVar15->field2_0x2 = pLVar4[iVar14].field_0xe;
              pMVar15->field10_0xc = *(short *)&pLVar4[iVar14].field_0x10;
              uStack_6c = uVar9 ^ 0x80000000;
              local_70 = 0x43300000;
              dVar17 = (double)((float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) -
                                       4503601774854144.0) * 640.0 + playerMapOffsetX);
              uStack_74 = uVar8 ^ 0x80000000;
              local_78 = 0x43300000;
              dVar16 = (double)((float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) -
                                       4503601774854144.0) * 640.0 + playerMapOffsetZ);
              for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
                uStack_74 = (int)(&pLVar4[iVar14].field0_0x0)[iVar5] ^ 0x80000000;
                local_78 = 0x43300000;
                uStack_6c = (int)*(short *)(&pLVar4[iVar14].field_0x4 + iVar5 * 2) ^ 0x80000000;
                local_70 = 0x43300000;
                uStack_7c = (int)(&pLVar4[iVar14].field6_0x8)[iVar5] ^ 0x80000000;
                local_80 = 0x43300000;
                uVar6 = intersectFn_800bbda0
                                  ((double)(float)(dVar17 + (double)(float)((double)CONCAT44(
                                                  0x43300000,uStack_74) - 4503601774854144.0)),
                                   (double)(float)((double)CONCAT44(0x43300000,uStack_6c) -
                                                  4503601774854144.0),
                                   (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                                    uStack_7c) -
                                                                  4503601774854144.0) + dVar16),
                                   maxModLine,(int)asStack_d08);
                *(undefined2 *)(&pMVar15->field_0x4 + iVar5 * 2) = uVar6;
              }
              maxModLine = maxModLine + 1;
            }
          }
        }
      }
    }
    for (iVar7 = 0; pMVar15 = int_linelist, iVar7 < maxModLine; iVar7 = iVar7 + 1) {
      for (iVar14 = 0; iVar14 < 2; iVar14 = iVar14 + 1) {
        iVar5 = (int)*(short *)(&pMVar15[iVar7].field_0x4 + iVar14 * 2);
        psVar13 = asStack_d08 + iVar5 * 2;
        if ((*psVar13 < 0) || (*psVar13 == iVar7)) {
          if ((asStack_d08[iVar5 * 2 + 1] < 0) || (asStack_d08[iVar5 * 2 + 1] == iVar7)) {
            (&pMVar15[iVar7].field8_0x8)[iVar14] = 0xffff;
          }
          else {
            (&pMVar15[iVar7].field8_0x8)[iVar14] = asStack_d08[iVar5 * 2 + 1];
          }
        }
        else {
          (&pMVar15[iVar7].field8_0x8)[iVar14] = *psVar13;
        }
      }
    }
    for (iVar7 = 0; iVar7 < maxModLine; iVar7 = iVar7 + 1) {
      *(short *)(int_lineindex + iVar7 * 2) = (short)iVar7;
    }
    bVar1 = false;
    while (!bVar1) {
      bVar1 = true;
      for (iVar7 = 0; iVar7 < maxModLine + -1; iVar7 = iVar7 + 1) {
        if ((int_linelist[*(short *)(int_lineindex + iVar7 * 2)].field3_0x3 & 0x3f) <
            (int_linelist[*(short *)(int_lineindex + (iVar7 + 1) * 2)].field3_0x3 & 0x3f)) {
          local_88 = *(undefined2 *)(int_lineindex + iVar7 * 2);
          *(undefined2 *)(int_lineindex + iVar7 * 2) =
               *(undefined2 *)(int_lineindex + (iVar7 + 1) * 2);
          *(undefined2 *)(int_lineindex + (iVar7 + 1) * 2) = local_88;
          bVar1 = false;
        }
      }
    }
    for (iVar7 = 0; iVar7 < 0x26; iVar7 = iVar7 + 1) {
      (&DAT_8037d700)[iVar7] = 0xffff;
    }
    uVar12 = 0xffff;
    for (iVar7 = 0; iVar7 < maxModLine; iVar7 = iVar7 + 1) {
      uVar10 = int_linelist[*(short *)(int_lineindex + iVar7 * 2)].field3_0x3 & 0x3f;
      if (0x12 < uVar10) {
        uVar10 = 1;
        debugPrint("trackIntersect: FUNC OVERFLOW %d",1);
      }
      uVar11 = uVar12;
      if (uVar12 != uVar10) {
        (&DAT_8037d700)[(short)uVar10 * 2] = (short)iVar7;
        uVar11 = uVar10;
        if (uVar12 != 0xffff) {
          (&DAT_8037d700)[(short)uVar12 * 2 + 1] = (short)iVar7;
        }
      }
      uVar12 = uVar11;
    }
    if (uVar12 != 0xffff) {
      (&DAT_8037d700)[(short)uVar12 * 2 + 1] = maxModLine;
    }
    if (0xffff < maxModLine) {
      debugPrint("trackIntersect: linefunctable overflow!!!");
    }
    if (800 < maxModLine) {
      debugPrint("trackIntersect() MAX_LINES overflow!!!");
                    
      OSPanic("intersect.c",0x9f1,"Failed assertion 0");
    }
    if (800 < modLinePointCount) {
      debugPrint("trackIntersect() MAX_LINEPOINTS overflow!!!");
                    
      OSPanic("intersect.c",0x9f5,"Failed assertion 0");
    }
    if (peakMaxModLine < maxModLine) {
      peakMaxModLine = maxModLine;
    }
    if (peakModLinePointCount < modLinePointCount) {
      peakModLinePointCount = modLinePointCount;
    }
    didTrackIntersect = 1;
  }
  _restfpr_27();
  return;
}


void intersectModLineBuild(ObjData *data) { //800BB288
  ModLineStruct1 *pMVar1;
  undefined2 uVar3;
  int iVar2;
  undefined *wObjList;
  ModLine *modLines;
  uint size;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short *psVar7;
  ModLineStruct1 *pMVar8;
  int iVar8;
  int iLine;
  short asStack_cec [1602];
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  short lineCount;
  
  _savefpr_29();
  bModLinesNeedUpdate = 1;
  maxModLine = 0;
  modLinePointCount = 0;
  modLines = data->pModLines;
  lineCount = data->modLineCount;
  iLine = 0;
  while( true ) {
    if (lineCount <= iLine) {
      for (iLine = 0; pMVar1 = int_linelist, iLine < maxModLine; iLine = iLine + 1) {
        for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
          iVar2 = (int)*(short *)(&pMVar1[iLine].field_0x4 + iVar8 * 2);
          psVar7 = asStack_cec + iVar2 * 2;
          if ((*psVar7 < 0) || (*psVar7 == iLine)) {
            if ((asStack_cec[iVar2 * 2 + 1] < 0) || (asStack_cec[iVar2 * 2 + 1] == iLine)) {
              (&pMVar1[iLine].field8_0x8)[iVar8] = 0xffff;
            }
            else {
              (&pMVar1[iLine].field8_0x8)[iVar8] = asStack_cec[iVar2 * 2 + 1];
            }
          }
          else {
            (&pMVar1[iLine].field8_0x8)[iVar8] = *psVar7;
          }
        }
      }
      size = maxModLine * 0x10 + modLinePointCount * 0xc + 0x26;
      if (size != 0) {
        wObjList = (undefined *)mmAlloc(size,INTERSECT_POINT,"int:wobjlist");
        data->wObjList = wObjList;
        data->nextIntersectLine = data->wObjList + maxModLine * 0x10;
        data->nextIntersectPoint = data->nextIntersectLine + modLinePointCount * 0xc;
        for (iLine = 0; iLine < 0x26; iLine = iLine + 1) {
          data->nextIntersectPoint[iLine] = 0xff;
        }
        uVar6 = 0xffff;
        for (iLine = 0; iLine < maxModLine; iLine = iLine + 1) {
          lineCount = 0;
          for (iVar8 = 0; iVar8 < maxModLine; iVar8 = iVar8 + 1) {
            if ((int_linelist[iVar8].field3_0x3 & 0x3f) <
                (int_linelist[lineCount].field3_0x3 & 0x3f)) {
              lineCount = (short)iVar8;
            }
          }
          uVar4 = int_linelist[lineCount].field3_0x3 & 0x3f;
          if (0x12 < uVar4) {
            uVar4 = 1;
            debugPrint("trackIntersect: FUNC OVERFLOW %d",1);
          }
          uVar5 = uVar6;
          if (uVar4 != uVar6) {
            data->nextIntersectPoint[(short)uVar4 * 2] = (char)iLine;
            uVar5 = uVar4;
            if (uVar6 != 0xffff) {
              data->nextIntersectPoint[(short)uVar6 * 2 + 1] = (char)iLine;
            }
          }
          for (iVar8 = 0; uVar3 = (undefined2)iLine, iVar8 < iLine; iVar8 = iVar8 + 1) {
            if (lineCount == *(short *)(data->wObjList + iVar8 * 0x10 + 8)) {
              *(undefined2 *)(data->wObjList + iVar8 * 0x10 + 8) = uVar3;
            }
            if (lineCount == *(short *)(data->wObjList + iVar8 * 0x10 + 10)) {
              *(undefined2 *)(data->wObjList + iVar8 * 0x10 + 10) = uVar3;
            }
          }
          for (iVar8 = 0; iVar8 < maxModLine; iVar8 = iVar8 + 1) {
            if (int_linelist[iVar8].field3_0x3 != 0x13) {
              if (lineCount == int_linelist[iVar8].field8_0x8) {
                int_linelist[iVar8].field8_0x8 = uVar3;
              }
              if (lineCount == int_linelist[iVar8].field9_0xa) {
                int_linelist[iVar8].field9_0xa = uVar3;
              }
            }
          }
          memcpy_src_dst_len(int_linelist + lineCount,data->wObjList + iLine * 0x10,0x10);
          int_linelist[lineCount].field3_0x3 = 0x13;
          uVar6 = uVar5;
        }
        if (uVar6 != 0xffff) {
          data->nextIntersectPoint[(short)uVar6 * 2 + 1] = (char)maxModLine;
        }
        memcpy_src_dst_len(int_pointlist,data->nextIntersectLine,modLinePointCount * 0xc);
        maxModLine = 0;
        modLinePointCount = 0;
      }
      _restfpr_29();
      return;
    }
    pMVar8 = int_linelist + maxModLine;
    *(byte *)pMVar8 = modLines[iLine].field12_0xc;
    pMVar8->field1_0x1 = modLines[iLine].field13_0xd;
    pMVar8->field3_0x3 = modLines[iLine].field15_0xf;
    pMVar8->field2_0x2 = modLines[iLine].field14_0xe;
    pMVar8->field10_0xc = modLines[iLine].field16_0x10;
    for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
      uStack_54 = (int)*(short *)(&modLines[iLine].field_0x0 + iVar8 * 2) ^ 0x80000000;
      local_58 = 0x43300000;
      uStack_5c = (int)*(short *)(&modLines[iLine].field_0x4 + iVar8 * 2) ^ 0x80000000;
      local_60 = 0x43300000;
      uStack_64 = (int)*(short *)(&modLines[iLine].field_0x8 + iVar8 * 2) ^ 0x80000000;
      local_68 = 0x43300000;
      uVar3 = intersectFn_800bbda0
                        ((double)(float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0
                                        ),
                         (double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0
                                        ),
                         (double)(float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0
                                        ),maxModLine,(int)asStack_cec);
      *(undefined2 *)(&pMVar8->field_0x4 + iVar8 * 2) = uVar3;
    }
    if (799 < modLinePointCount) break;
    maxModLine = maxModLine + 1;
    iLine = iLine + 1;
  }
  debugPrint("intersectModLineBuild point list overflow, %d/%d",(int)modLinePointCount,800);
                    
  OSPanic("intersect.c",0xa2e,"Failed assertion 0");
}


void intersectFn_800bbda0(double param1,double param2,double param3,undefined2 param4,int param5) { //800BBDA0
  int iVar1;
  
  _savefpr_29();
  iVar1 = 0;
  do {
    if (modLinePointCount <= iVar1) {
      *(float *)(int_pointlist + modLinePointCount * 0xc) = (float)param1;
      *(float *)(int_pointlist + modLinePointCount * 0xc + 4) = (float)param2;
      *(float *)(int_pointlist + modLinePointCount * 0xc + 8) = (float)param3;
      *(undefined2 *)(param5 + modLinePointCount * 4) = param4;
      *(undefined2 *)(param5 + (modLinePointCount * 2 + 1) * 2) = 0xffff;
      modLinePointCount = modLinePointCount + 1;
      if (modLinePointCount == 800) {
        debugPrint("insertPoint array overrun %d/%d",800,800);
                    
        OSPanic("intersect.c",0xb34,"Failed assertion 0");
      }
LAB_800bbf00:
      _restfpr_29();
      return;
    }
    if (((param1 == (double)*(float *)(int_pointlist + iVar1 * 0xc)) &&
        (param2 == (double)*(float *)(int_pointlist + iVar1 * 0xc + 4))) &&
       (param3 == (double)*(float *)(int_pointlist + iVar1 * 0xc + 8))) {
      *(undefined2 *)(param5 + (iVar1 * 2 + 1) * 2) = param4;
      goto LAB_800bbf00;
    }
    iVar1 = iVar1 + 1;
  } while( true );
}


IntLastLineStruct * intersectFn_800bcd50(undefined4 param1,undefined4 param2,undefined param3) { //800BCD50
  short sVar1;
  IntLastLineStruct *pIVar2;
  
  sVar1 = 0;
  do {
    pIVar2 = int_lastlines + sVar1;
    if (pIVar2->field20_0x14 == 0) {
      *(undefined4 *)pIVar2 = param1;
      *(undefined4 *)&pIVar2->field_0x4 = param2;
      pIVar2->field_0x15 = param3;
      pIVar2->field20_0x14 = 2;
      return pIVar2;
    }
    sVar1 = sVar1 + 1;
  } while (sVar1 < 0x14);
  debugPrint("NO FREE LAST LINE");
                    
  OSPanic("intersect.c",0xcc8,"Failed assertion 0");
}

