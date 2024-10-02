
/* Library Function - Single Match
    dimExplosionFn_80229f1c
   
   Library: KioskDefault 0 0 */

void dimExplosionFn_80229f1c(double param1,int param2) { //80229F1C
  undefined2 uVar1;
  int iVar2;
  ObjDef *def;
  short local_28;
  undefined2 local_26;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  longlong local_10;
  
  local_18 = *(undefined4 *)(param2 + 0x4c);
  local_24 = 0.0;
  local_20 = 0.0;
  local_1c = 0.0;
  if (param2 == 0) {
                    
    OSPanic("DIMexplosion.c",0xe1,"Failed assertion obj");
  }
  local_20 = *(float *)(param2 + 8) * 10.0;
  iVar2 = randInt(0,0x8000);
  local_28 = (short)iVar2;
  iVar2 = randInt(0,0x8000);
  local_26 = (undefined2)iVar2;
  local_24 = (float)((uint)local_24 & 0xffff);
  FUN_8007a878(&local_28,&local_24);
  def = objAlloc(0x24,DIMExplosio);
  def->loadFlags = isManualLoad;
  def->mapStates2 = 1;
  (def->pos).x = *(float *)(param2 + 0xc) + local_24;
  (def->pos).y = *(float *)(param2 + 0x10) + local_20;
  (def->pos).z = *(float *)(param2 + 0x14) + local_1c;
  iVar2 = (int)((float)param1 * 0.5 * 256.0 + 512.0);
  local_10 = (longlong)iVar2;
  uVar1 = (undefined2)iVar2;
  def[1].allocatedSize = (char)((ushort)uVar1 >> 8);
  def[1].mapStates1 = (char)uVar1;
  objInstantiateCharacter(def,5,(int)*(char *)(param2 + 0xac),-1,*(ObjInstance **)(param2 + 0x30));
  return;
}

