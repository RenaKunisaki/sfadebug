#!/bin/bash
# usage: m2c.sh src/some/file.c someFunction build/GSAP01-DEBUG/asm/some/file.s
. ./tools/decompctx2/venv/bin/activate
./tools/decompctx2/decompctx2.py --strip-at-address --m2c -o ctx.c.m2c $1
# TODO: strip the ": address" bits
../m2c/m2c.py -t ppc-mwcc-c --context ctx.c.m2c -f $2 $3
