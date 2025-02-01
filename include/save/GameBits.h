typedef struct {
    u16 iBit; //Bit (not byte) offset into table
    u8 flags;
    u8 hintTextIdx;
} BitTableEntry;

#define GAMEBIT_FLAG_MASK_SIZE 0x1F //number of bits (this+1)
#define GAMEBIT_FLAG_HAS_HINT_TEXT 0x20
//40, 80 are table index
#define GAMEBIT_FLAG_TABLE_IDX_SHIFT 6

#define GAMEBIT_ALWAYS_1 0x0095
#define GAMEBIT_ALWAYS_0 0x0096
