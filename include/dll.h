//XXX file here is DLL*
typedef int (*DLL_func)(void *file);

typedef struct {
    /* 0x0 */ union {
        //possibly the onLoad signature is only newer game versions?
        int (*onLoad)(void *thisdll);
        void (*func0)(void);
    } _0;
    /* 0x4 */ union {
        int (*onUnload)(void *thisdll);
        void (*func1)(void);
    } _4;
    /* 0x8 */ int (*func[0])(); //func 0 is a model callback
} DLL_funcs;

typedef struct DLL {
    /* 0x0 */ struct DLL *prev;
    /* 0x4 */ struct DLL *next;
    /* 0x8 */ int (*_08)(void *thisdll);
    /* 0xc */ ushort nFuncs; //includes onUnload but not onLoad
    /* 0xe */ ushort _0E;
    /* 0x10 */ DLL_funcs funcs;
} DLL;

typedef struct {
    /* 0x0 */ DLL_funcs *funcs;
    /* 0x4 */ UNKTYPE *_0C; //maybe rodata? seems to be set by uninitialized var
    /* 0x8 */ int id;
    /* 0xc */ int refCount;
} LoadedDLL;

BOOL DLL_free(LoadedDLL *dll);
LoadedDLL* runlinkDownloadCode(ushort id, ushort param);
