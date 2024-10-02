MEMORY
{
    text : origin = $ORIGIN
}

SECTIONS
{
    GROUP:
    {
        .init ALIGN(0x4):{}
        extab ALIGN(0x20):{}
        extabindex ALIGN(0x4):{}
        .text ALIGN(0x4):{}
        .ctors ALIGN(0x20):{}
        .dtors ALIGN(0x20):{}
        .rodata ALIGN(0x20):{}
        .data ALIGN(0x20):{}
        .bss ALIGN(0x8):{}
        .sdata ALIGN(0x20):{}
        .sbss ALIGN(0x20):{}
        .sdata2 ALIGN(0x8):{}
        .stack ALIGN(0x100):{}
    } > text

    _stack_end = _f_sdata2 + SIZEOF(.sdata2);
    _stack_addr = (_stack_end + 0x10000 + 0x7) & ~0x7;
    _db_stack_addr = (_stack_addr + 0x2000);
    _db_stack_end = _stack_addr;
    __ArenaLo = (_db_stack_addr + 0x1f) & ~0x1f;
    __ArenaHi = $ARENAHI;
}

FORCEACTIVE
{
    $FORCEACTIVE
}
