//XXX this file isn't used
typedef enum {
    G_SPNOOP = 0,
    X_LOADVTXS = 16777216,
    G_MOVEMEM = 50331648,
    G_VTX = 67108864,
    X_DRAWTRI = 83886080,
    X_2TRI = 100663296,
    G_DL = 100663296,
    _Draw2Tris = 100663296,
    X_UNKFLOAT = 117440512,
    G_LOAD_UCODE = 2936012800,
    G_BRANCH_Z = 2952790016,
    G_TRI2 = 2969567232,
    G_MODIFYVTX = 2986344448,
    G_RDPHALF_2 = 3003121664,
    G_RDPHALF_1 = 3019898880,
    G_QUAD = 3036676096,
    G_CLEARGEOMETRYMODE = 3053453312,
    G_SETGEOMETRYMODE = 3070230528,
    G_ENDDL = 3087007744,
    G_SetOtherMode_L = 3103784960,
    G_SetOtherMode_H = 3120562176,
    G_TEXTURE = 3137339392,
    G_MOVEWORD = 3154116608,
    G_POPMTX = 3170893824,
    G_CULLDL = 3187671040,
    MtxCmd4 = 3203391149,
    G_TRI1 = 3204448256,
    G_NOOP = 3221225472,
    X_SETCULLMODE = 3640655872,
    X_LOADMTXS = 3657433088,
    X_MW_MATRIX = 3674210304,
    X_MTX_DB = 3690987520,
    X_SET_TEXMTX = 3735928559,
    X_INIT_TEV = 3736074974,
    X_SYNC = 3741319168,
    X_DRAW_IMG = 3825205248,
    G_TEXRECTFLIP = 3841982464,
    G_RDPLOADSYNC = 3858759680,
    G_RDPPIPESYNC = 3875536896,
    G_RDPTILESYNC = 3892314112,
    G_RDPFULLSYNC = 3909091328,
    G_SETKEYGB = 3925868544,
    G_SETKEYR = 3942645760,
    G_SETCONVERT = 3959422976,
    G_SETSCISSOR = 3976200192,
    G_SETPRIMDEPTH = 3992977408,
    G_RDPSetOtherMode = 4009754624,
    G_LOADTLUT = 4026531840,
    G_SETTILESIZE = 4060086272,
    G_LOADBLOCK = 4076863488,
    G_LOADTILE = 4093640704,
    G_SETTILE = 4110417920,
    G_FILLRECT = 4127195136,
    G_SETFILLCOLOR = 4143972352,
    G_SETFOGCOLOR = 4160749568,
    G_SETBLENDCOLOR = 4177526784,
    G_SETPRIMCOLOR = 4194304000,
    X_USE_TEXMTX = 4207869677,
    G_SETENVCOLOR = 4211081216,
    G_SETCOMBINE = 4227858432,
    G_SETTIMG = 4244635648,
    G_SETZIMG = 4261412864,
    X_RESET_TEV = 4277009102,
    G_SETCIMG = 4278190080,
} F3DEXcommand;

typedef struct {
	unsigned int w0;
	unsigned int w1;
} Gwords;

typedef union {
	Gwords		words;
    // ...
} Gfx;

#define RSP_CMD(BUFFER, COMMAND, PARAM) do { \
    Gfx *_buf = (BUFFER) + 1; \
    if(_buf) {} \
    (BUFFER) = _buf; \
    _buf->words.w0 = (COMMAND); \
    _buf->words.w1 = (PARAM); \
} while(0)

#define gDPNoParam(pkt, cmd)						\
{									\
	Gfx *_g = (Gfx *)(pkt);						\
									\
	_g->words.w0 = _SHIFTL(cmd, 24, 8);				\
	_g->words.w1 = 0;						\
}
#define	gDPPipeSync(pkt)	gDPNoParam(pkt, G_RDPPIPESYNC)

/*inline Gfx* RDP_PIPE_SYNC(Gfx *buf) {
    buf->cmd = G_RDPPIPESYNC;
    buf->param = 0;
    return buf + 1;
}*/

/* inline void _RSP_CMD(Gfx **buf, u32 cmd, u32 param) {
    Gfx *_buf = *(buf++);
    _buf->cmd = cmd;
    _buf->param = param;
}
#define RSP_CMD(BUFFER, COMMAND, PARAM) _RSP_CMD(&BUFFER, COMMAND, PARAM) */

/*#define RSP_CMD(BUFFER, COMMAND, PARAM) do { \
    Gfx *_buf = (BUFFER) + 2; \
    (BUFFER) = _buf; \
    _buf[0] = (COMMAND); \
    _buf[1] = (PARAM); \
} while(0)*/
