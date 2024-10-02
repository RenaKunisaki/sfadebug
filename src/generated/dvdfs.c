
/* Library Function - Single Match
    fsInit
   
   Library: KioskDefault 0 0 */

void __DVDFSInit(void) { //80010FF8
  pGameCode = (char *)OSPhysicalToCached(0);
  pDvdFst = *(undefined **)(pGameCode + 0x38);
  if (pDvdFst != (undefined *)0x0) {
    dvdMaxEntryNum = *(int *)(pDvdFst + 8);
    pDvdFstEnd = pDvdFst + dvdMaxEntryNum * 0xc;
  }
  return;
}


BOOL pathCompare(char *path,char *str) { //80011058
  uint cl;
  uint uVar1;
  char c;
  
  while (*str != '\0') {
    c = *str;
    str = str + 1;
    cl = chrToLower((int)c);
    c = *path;
    path = path + 1;
    uVar1 = chrToLower((int)c);
    if (uVar1 != cl) {
      return FALSE;
    }
  }
  if ((*path != '/') && (*path != '\0')) {
    return FALSE;
  }
  return TRUE;
}


/* Library Function - Single Match
    DVDConvertPathToEntrynum
   
   Library: KioskDefault 0 0 */

uint DVDConvertPathToEntrynum(char *param1) { //800110EC
  char cVar1;
  bool bVar2;
  bool bVar3;
  BOOL BVar4;
  char *unaff_r21;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *path;
  
  uVar6 = dvdCurDirEntryNum;
  path = param1;
  if (param1 == (char *)0x0) {
                    
    OSPanic("dvdfs.c",0x126,"DVDConvertPathToEntrynum(): null pointer is specified  ");
  }
  do {
    while( true ) {
      while( true ) {
        if (*path == '\0') {
          return uVar6;
        }
        if (*path != '/') break;
        uVar6 = 0;
        path = path + 1;
      }
      if (*path != '.') break;
      if (path[1] == '.') {
        if (path[2] != '/') {
          if (path[2] == '\0') {
            return *(uint *)(pDvdFst + uVar6 * 0xc + 4);
          }
          break;
        }
        uVar6 = *(uint *)(pDvdFst + uVar6 * 0xc + 4);
        path = path + 3;
      }
      else {
        if (path[1] != '/') {
          if (path[1] == '\0') {
            return uVar6;
          }
          break;
        }
        path = path + 2;
      }
    }
    pcVar7 = path;
    if (bSupportLongFileNames == FALSE) {
      bVar2 = false;
      bVar3 = false;
LAB_8001123c:
      if ((*pcVar7 == '\0') || (*pcVar7 == '/')) goto LAB_80011254;
      if (*pcVar7 != '.') {
        if (*pcVar7 == ' ') {
          bVar3 = true;
        }
LAB_80011238:
        pcVar7 = pcVar7 + 1;
        goto LAB_8001123c;
      }
      if (((int)pcVar7 - (int)path < 9) && (!bVar2)) {
        bVar2 = true;
        unaff_r21 = pcVar7 + 1;
        goto LAB_80011238;
      }
      bVar3 = true;
LAB_80011254:
      if ((bVar2) && (3 < (int)pcVar7 - (int)unaff_r21)) {
        bVar3 = true;
      }
      if (bVar3) {
                    
        OSPanic("dvdfs.c",0x16b,"DVDConvertEntrynumToPath(possibly DVDOpen or DVDChangeDir or DVDOpenDir): specified directory or file (%s) doesn't match standard 8.3 format. This is a temporary restriction and will be removed soon",param1);
      }
    }
    else {
      for (; (*pcVar7 != '\0' && (*pcVar7 != '/')); pcVar7 = pcVar7 + 1) {
      }
    }
    cVar1 = *pcVar7;
    uVar5 = uVar6 + 1;
    while( true ) {
      if (*(uint *)(pDvdFst + uVar6 * 0xc + 8) <= uVar5) {
        return 0xffffffff;
      }
      if ((((*(uint *)(pDvdFst + uVar5 * 0xc) & 0xff000000) != 0) || (cVar1 == '\0')) &&
         (BVar4 = pathCompare(path,pDvdFstEnd + (*(uint *)(pDvdFst + uVar5 * 0xc) & 0xffffff)),
         BVar4 == TRUE)) break;
      if ((*(uint *)(pDvdFst + uVar5 * 0xc) & 0xff000000) == 0) {
        uVar5 = uVar5 + 1;
      }
      else {
        uVar5 = *(uint *)(pDvdFst + uVar5 * 0xc + 8);
      }
    }
    if (cVar1 == '\0') {
      return uVar5;
    }
    uVar6 = uVar5;
    path = pcVar7 + 1;
  } while( true );
}


/* Library Function - Single Match
    DVDOpen
   
   Library: KioskDefault 0 0 */

BOOL DVDOpen(char *name,DVDFileInfo *fileInfo) { //800113D0
  uint uVar1;
  BOOL result;
  char acStack_90 [128];
  
  if (name == (char *)0x0) {
                    
    OSPanic("dvdfs.c",0x1d3,"DVDOpen(): null pointer is specified to file name  ");
  }
  if (fileInfo == (DVDFileInfo *)0x0) {
                    
    OSPanic("dvdfs.c",0x1d4,"DVDOpen(): null pointer is specified to file info address  ");
  }
  uVar1 = DVDConvertPathToEntrynum(name);
  if ((int)uVar1 < 0) {
    DVDGetCurrentDir(acStack_90,0x80);
    OSReport("Warning: DVDOpen(): file '%s' was not found under %s.",name,acStack_90);
    result = FALSE;
  }
  else if ((*(uint *)(pDvdFst + uVar1 * 0xc) & 0xff000000) == 0) {
    (fileInfo->cb).id = *(DVDDiskID **)(pDvdFst + uVar1 * 0xc + 4);
    (fileInfo->cb).callback = *(void **)(pDvdFst + uVar1 * 0xc + 8);
    fileInfo[1].startAddr = 0;
    (fileInfo->cb).next = (DVDCommandBlock *)0x0;
    result = TRUE;
  }
  else {
    if ((*(uint *)(pDvdFst + uVar1 * 0xc) & 0xff000000) != 0) {
                    
      OSPanic("dvdfs.c",0x1e2,"DVDOpen(): directory '%s' is specified as a filename  ",name);
    }
    result = FALSE;
  }
  return result;
}


/* Library Function - Single Match
    DVDClose
   
   Library: KioskDefault 0 0 */

BOOL DVDClose(DVDFileInfo *file) { //80011524
  if (file == (DVDFileInfo *)0x0) {
                    
    OSPanic("dvdfs.c",0x1fa,"DVDClose(): null pointer is specified to file info address  ");
  }
  _DVDClose(file);
  return TRUE;
}


/* Library Function - Single Match
    DVDConvertEntrynumToPath
   
   Library: KioskDefault 0 0 */

BOOL DVDConvertEntrynumToPath(uint entryNum,char *dst,uint maxlen) { //8001166C
  uint uVar1;
  BOOL result;
  
  if (((int)entryNum < 0) || (dvdMaxEntryNum <= entryNum)) {
                    
    OSPanic("dvdfs.c",0x255,"DVDConvertEntrynumToPath: specified entrynum(%d) is out of range  ",entryNum);
  }
  if (maxlen < 2) {
                    
    OSPanic("dvdfs.c",599,"DVDConvertEntrynumToPath: maxlen should be more than 1 (%d is specified)",maxlen);
  }
  if ((*(uint *)(pDvdFst + entryNum * 0xc) & 0xff000000) != 0) {
    uVar1 = FUN_800115c0(entryNum,(int)dst,maxlen);
    if (uVar1 == maxlen) {
      dst[maxlen - 1] = '\0';
      result = FALSE;
    }
    else {
      if ((*(uint *)(pDvdFst + entryNum * 0xc) & 0xff000000) != 0) {
        if (uVar1 == maxlen - 1) {
          dst[uVar1] = '\0';
          return FALSE;
        }
        dst[uVar1] = '/';
        uVar1 = uVar1 + 1;
      }
      dst[uVar1] = '\0';
      result = TRUE;
    }
    return result;
  }
                    
  OSPanic("dvdfs.c",0x25c,"DVDConvertEntrynumToPath: cannot convert an entry num for a file to path  ");
}


/* Library Function - Single Match
    DVDGetCurrentDir
   
   Library: KioskDefault 0 0 */

BOOL DVDGetCurrentDir(char *path,u32 maxlen) { //800117B8
  BOOL BVar1;
  
  if (maxlen < 2) {
                    
    OSPanic("dvdfs.c",0x286,"DVDGetCurrentDir: maxlen should be more than 1 (%d is specified)",maxlen);
  }
  BVar1 = DVDConvertEntrynumToPath(dvdCurDirEntryNum,path,maxlen);
  return BVar1;
}


/* Library Function - Single Match
    DVDReadAsync
   
   Library: KioskDefault 0 0 */

BOOL DVDReadAsync(DVDFileInfo *file,void *addr,uint length,uint offset,u32 param5,int param6) { //80011818
  if (file == (DVDFileInfo *)0x0) {
                    
    OSPanic("dvdfs.c",0x2c7,"DVDReadAsync(): null pointer is specified to file info address  ");
  }
  if (addr == (void *)0x0) {
                    
    OSPanic("dvdfs.c",0x2c8,"DVDReadAsync(): null pointer is specified to addr  ");
  }
  if (((uint)addr & 0x1f) != 0) {
                    
    OSPanic("dvdfs.c",0x2cc,"DVDReadAsync(): address must be aligned with 32 byte boundaries  ");
  }
  if ((length & 0x1f) != 0) {
                    
    OSPanic("dvdfs.c",0x2ce,"DVDReadAsync(): length must be  multiple of 32 byte  ");
  }
  if ((offset & 3) != 0) {
                    
    OSPanic("dvdfs.c",0x2d0,"DVDReadAsync(): offset must be multiple of 4 byte  ");
  }
  if ((-1 < (int)offset) && (offset < (file->cb).callback)) {
    if ((-1 < (int)(offset + length)) && (offset + length < (int)(file->cb).callback + 0x20U)) {
      file[1].startAddr = param5;
      DVDReadAbsAsync((undefined **)file,(undefined *)addr,(undefined *)length,
                      ((file->cb).id)->gameName + offset,dvdReadCb,param6);
      return TRUE;
    }
                    
    OSPanic("dvdfs.c",0x2db,"DVDReadAsync(): specified area is out of the file  ");
  }
                    
  OSPanic("dvdfs.c",0x2d5,"DVDReadAsync(): specified area is out of the file  ");
}


/* Library Function - Single Match
    dvdReadCb_80011970
   
   Library: KioskDefault 0 0 */

void dvdReadCb(undefined4 param1,int param2) { //80011970
  if (false) {
                    
    OSPanic("dvdfs.c",0x2ed,"Failed assertion (void*) &fileInfo->cb == (void*) block");
  }
  if (*(int *)(param2 + 0x38) != 0) {
    (**(code **)(param2 + 0x38))(param1,param2);
  }
  return;
}


/* Library Function - Single Match
    DVDRead
   
   Library: KioskDefault 0 0 */

undefined *
DVDRead(undefined **param1,undefined *param2,undefined *param3,undefined *param4,int param5) { //800119E0
  int iVar1;
  undefined *puVar2;
  BOOL_ level;
  
  if (param1 == (undefined **)0x0) {
                    
    OSPanic("dvdfs.c",0x30d,"DVDRead(): null pointer is specified to file info address  ");
  }
  if (param2 == (undefined *)0x0) {
                    
    OSPanic("dvdfs.c",0x30e,"DVDRead(): null pointer is specified to addr  ");
  }
  if (((uint)param2 & 0x1f) != 0) {
                    
    OSPanic("dvdfs.c",0x312,"DVDRead(): address must be aligned with 32 byte boundaries  ");
  }
  if (((uint)param3 & 0x1f) != 0) {
                    
    OSPanic("dvdfs.c",0x314,"DVDRead(): length must be  multiple of 32 byte  ");
  }
  if (((uint)param4 & 3) != 0) {
                    
    OSPanic("dvdfs.c",0x316,"DVDRead(): offset must be multiple of 4 byte  ");
  }
  if (((int)param4 < 0) || (param1[0xd] <= param4)) {
                    
    OSPanic("dvdfs.c",0x31b,"DVDRead(): specified area is out of the file  ");
  }
  if (((int)(param4 + (int)param3) < 0) || (param1[0xd] + 0x20 <= param4 + (int)param3)) {
                    
    OSPanic("dvdfs.c",0x321,"DVDRead(): specified area is out of the file  ");
  }
  iVar1 = DVDReadAbsAsync(param1,param2,param3,param1[0xc] + (int)param4,&LAB_80011b94,param5);
  if (iVar1 == 0) {
    puVar2 = (undefined *)0xffffffff;
  }
  else {
    level = OSDisableInterrupts();
    while (puVar2 = param1[3], puVar2 != (undefined *)0x0) {
      if (puVar2 == (undefined *)0xffffffff) {
        puVar2 = (undefined *)0xffffffff;
        goto LAB_80011b74;
      }
      if (puVar2 == (undefined *)0xa) {
        puVar2 = (undefined *)0xfffffffa;
        goto LAB_80011b74;
      }
      OSSleepThread(&OSThreadQueue_803982e8);
    }
    puVar2 = param1[8];
LAB_80011b74:
    OSRestoreInterrupts(level);
  }
  return puVar2;
}


/* Library Function - Single Match
    DVDPrepareStreamAsync
   
   Library: KioskDefault 0 0 */

void DVDPrepareStreamAsync(undefined **param1,undefined *param2,undefined *param3,undefined *param4) { //80011BC0
  if (param1 == (undefined **)0x0) {
                    
    OSPanic("dvdfs.c",0x46c,"DVDPrepareStreamAsync(): NULL file info was specified");
  }
  if (((uint)(param1[0xc] + (int)param3) & 0x7fff) != 0) {
                    
    OSPanic("dvdfs.c",0x472,"DVDPrepareStreamAsync(): Specified start address (filestart(0x%x) + offset(0x%x)) is not 32KB aligned",param1[0xc],param3)
    ;
  }
  if (param2 == (undefined *)0x0) {
    param2 = param1[0xd] + -(int)param3;
  }
  if (((uint)param2 & 0x7fff) != 0) {
                    
    OSPanic("dvdfs.c",0x47c,"DVDPrepareStreamAsync(): Specified length (0x%x) is not a multiple of 32768(32*1024)",param2);
  }
  if ((param3 < param1[0xd]) && (param3 + (int)param2 <= param1[0xd])) {
    param1[0xe] = param4;
    FUN_80013978(param1,param2,param1[0xc] + (int)param3,dvdMaybeStreamCb_80011cd0);
    return;
  }
                    
  OSPanic("dvdfs.c",0x484,"DVDPrepareStreamAsync(): The area specified (offset(0x%x), length(0x%x)) is out of the file",param3,param2);
}


/* Library Function - Single Match
    dvdFn_80011cd0
   
   Library: KioskDefault 0 0 */

void dvdMaybeStreamCb_80011cd0(undefined4 param1,int param2) { //80011CD0
  if (false) {
                    
    OSPanic("dvdfs.c",0x497,"Failed assertion (void*) &fileInfo->cb == (void*) block");
  }
  if (*(int *)(param2 + 0x38) != 0) {
    (**(code **)(param2 + 0x38))(param1,param2);
  }
  return;
}

