#include "Runtime.PPCEABI.H/NMWException.h"
#include "Runtime.PPCEABI.H/__ppc_eabi_linker.h"

#if __MWERKS__
#pragma exceptions off
#pragma internal on
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void __init_cpp_exceptions(void);
extern void __fini_cpp_exceptions(void);

#ifdef __cplusplus
}
#endif

static int fragmentID = -2;

/**
 * @todo HACK: Should be @c _eti_init_info. We can't use the appropriate
 * name yet due to the linker not being able to generate it.
 */
extern __eti_init_info _eti_init_info_[];

/* clang-format off */
static asm char* GetR2() {
  nofralloc;
  mr r3, r2
  blr
}
/* clang-format on */

void __fini_cpp_exceptions(void) {
    if (fragmentID != -2) {
        __unregister_fragment(fragmentID);
        fragmentID = -2;
    }
}

void __init_cpp_exceptions(void) {
    if (fragmentID == -2) {
        fragmentID = __register_fragment(_eti_init_info, GetR2());
    }
}

/* clang-format off */
__declspec(section ".ctors")
static void* const __init_cpp_exceptions_reference = __init_cpp_exceptions;
__declspec(section ".dtors")
static void* const __destroy_global_chain_reference = __destroy_global_chain;
__declspec(section ".dtors")
static void* const __fini_cpp_exceptions_reference = __fini_cpp_exceptions;
/* clang-format on */
