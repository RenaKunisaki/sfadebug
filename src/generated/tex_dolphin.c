
/* Library Function - Single Match
    gxTextureFn_800a47fc
   
   Library: KioskDefault 0 0 */

Texture * gxTextureFn_800a47fc(uint param1,uint param2,int param3,char param4,byte param5) { //800A47FC
  int iVar1;
  Texture *tex_created;
  
  iVar1 = GXGetTexBufferSize(param1,param2,param3,param4,param5);
  if (iVar1 + 0x60U == 0) {
                    
    OSPanic("tex_dolphin.c",0xc6,"Failed assertion allocSize");
  }
  tex_created = (Texture *)mmAlloc(iVar1 + 0x60U,TEX_COL,"tex:created");
  if (tex_created == (Texture *)0x0) {
                    
    OSPanic("tex_dolphin.c",0xc9,"Failed assertion texture");
  }
  memset_(tex_created,0,100);
  tex_created->field15_0x16 = (byte)param3;
  tex_created->width = (ushort)param1;
  tex_created->height = (ushort)param2;
  tex_created->field10_0x10 = 1;
  tex_created->usage = 0;
  tex_created->field16_0x17 = 0;
  tex_created->field17_0x18 = 0;
  gxTextureFn_800a56cc(tex_created);
  return tex_created;
}

