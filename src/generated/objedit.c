
undefined4 debugEnterObjEdit(undefined4 param1,DebugMenuState *menu,int param3) { //8017FB1C
  if (menu->command == ENTER) {
    objEditFn_80181e70(6);
    debugMenuPush(diMenu_objEdit,0);
    DAT_80399990 = param3;
    if (param3 != 0) {
      objEditFn_801846b4();
    }
  }
  return 0;
}

