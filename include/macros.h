#ifndef _H_MACROS_
#define _H_MACROS_

#ifdef DEBUG

//shame on whomever wrote this.
//use this if ASSERTLINE generates an extra "li r0, 0x0".
//don't use it otherwise because it's a single expression
//that expands to multiple expressions, which can lead to
//unexpected interactions.
#define BADASSERTLINE(line, cond) \
    if(!(cond)) OSPanic(__FILE__, line, "Failed assertion " #cond)

#define ASSERTLINE(line, cond) \
    ((cond) || (OSPanic(__FILE__, line, "Failed assertion " #cond), 0))

#define ASSERTMSGLINE(line, cond, msg) \
    ((cond) || (OSPanic(__FILE__, line, msg), 0))

// This is dumb but we dont have a Metrowerks way to do variadic macros in the macro to make this done in a not scrubby way.
#define ASSERTMSG1LINE(line, cond, msg, arg1) \
    ((cond) || (OSPanic(__FILE__, line, msg, arg1), 0))

#define ASSERTMSG2LINE(line, cond, msg, arg1, arg2) \
    ((cond) || (OSPanic(__FILE__, line, msg, arg1, arg2), 0))

#define ASSERTMSGLINEV(line, cond, ...) \
    ((cond) || (OSPanic(__FILE__, line, __VA_ARGS__), 0))

#else
#define ASSERTLINE(line, cond) (void)0
#define ASSERTMSGLINE(line, cond, msg) (void)0
#define ASSERTMSG1LINE(line, cond, msg, arg1) (void)0
#define ASSERTMSG2LINE(line, cond, msg, arg1, arg2) (void)0
#define ASSERTMSGLINEV(line, cond, ...) (void)0
#endif

#define ASSERT(cond) ASSERTLINE(__LINE__, cond)

#define STUBBED_PRINTF(...) (__VA_ARGS__);

//make this a macro so we can easily disable it if
//we want to use a newer compiler which no longer
//allows it.
#define REGISTER register

// there are multiple instances of:
// li  r0,0x0
// stb r0,0x0(0)
// used as a "poor man's assert"
#define CRASH() do { \
	*(u8 *)NULL = 0; \
} while(0)

/* sometimes there are instances of:
if(foo) {
    ???
}
where the block has to be non-empty, but any statement
placed in it matches, making the actual contents unknowable.
use this macro to indicate that we don't know what goes here
and have just arbitrarily chosen x to be the statement.
*/
#define STUBBED_OP(x) x

//really? this isn't defined?
#define UCHAR_MAX 255u
#define SHRT_MAX 32767
#define PI 3.141593f

/**
 * @brief Given an object, convert `field`
 *  from an offset (relative to the object)
 *  to a pointer.
 */
#define OFFSET_TO_PTR(type, obj, field) \
    (obj)->field = (type*)((uint)(obj) + (uint)(obj)->field)

/**
 * @brief Given an object and a base address,
 *  convert `field` from an offset (relative
 *  to `base`) to a pointer.
 * Used by model_setOffsets.
 */
#define OFFSET_TO_PTR2(type, obj, field, base) \
    (obj)->field = (type*)((intptr_t)(base) + (intptr_t)(obj)->field)

#define ADVANCE_PTR(ptr, size) \
    (ptr) = (void*)((uint)(ptr) + (size))

#define ADVANCE_PTR_BY(ptr, count, typ) \
    (ptr) = (void*)((uint)(ptr) + ((count) * sizeof(typ)))

#endif // _H_MACROS_
