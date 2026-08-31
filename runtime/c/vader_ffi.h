/* vader_ffi — dynamic foreign calls for the VM.
 *
 * The native backend never needs this: `@extern` there becomes a real C call
 * that the linker resolves, and `c_emit` writes the cast itself. The VM cannot,
 * because it discovers a signature by reading bytecode, and C requires a call's
 * signature at compile time.
 *
 * Two halves. `vader_ffi_open` / `vader_ffi_symbol` find the function;
 * `vader_ffi_call_*` invoke it through a TRAMPOLINE — a call site written here,
 * ahead of time, one per SHAPE of signature rather than one per function.
 *
 * The shapes are coarse on purpose. Every ABI we target (System V AMD64,
 * AAPCS64, Win64) passes integers and pointers of any width in the same general
 * registers, in the same order, so a single `int64_t` slot carries an `int`, a
 * `size_t` or a `void*` alike. Floats travel in other registers and are NOT
 * covered: `vader_ffi_call_f64` accepts a floating RESULT, never a floating
 * argument. Structs by value are not covered either — their classification is
 * per-field, which no fixed shape can express.
 *
 * An uncovered signature must be rejected by the caller before it gets here.
 *
 * Included once, by vader_runtime.c. It is a header rather than its own
 * translation unit because the runtime builds as a single TU
 * (`bootstrap/build.sh`, `build.ps1`, `cli/cmd_build.vader`), and a second `.c`
 * would mean teaching all three.
 */

#ifndef VADER_FFI_H
#define VADER_FFI_H

#include <stdint.h>
#include <stddef.h>

#ifdef _WIN32
#  include <windows.h>
#else
#  include <dlfcn.h>
#endif

/* Largest arity a trampoline covers. Six is the point where every ABI we target
 * stops passing integer arguments in registers; eight leaves room without
 * making the switch unwieldy. */
#define VADER_FFI_MAX_ARGS 8

/* Open a shared library by BARE name — `"sqlite3"`, not `"libsqlite3.so"` —
 * decorating it per platform. A NULL or empty name yields a handle onto the
 * running process, which is what a libc symbol needs.
 *
 * Returns NULL when the library cannot be found. The handle is never closed:
 * a library backing a live foreign call must outlive it, and the VM has no
 * point at which it can prove none remain. */
void* vader_ffi_open(const char* name);

/* Resolve `symbol` in `lib`. NULL when absent. */
void* vader_ffi_symbol(void* lib, const char* symbol);

/* Call `fn` with `nargs` integer-or-pointer arguments.
 *
 * `_int` reads the result as an integer, `_void` discards it, `_f64` reads it
 * as a double. All three TRAP when `nargs > VADER_FFI_MAX_ARGS` rather than
 * calling with a truncated argument list. */
int64_t vader_ffi_call_int(void* fn, const int64_t* args, size_t nargs);
void    vader_ffi_call_void(void* fn, const int64_t* args, size_t nargs);
double  vader_ffi_call_f64(void* fn, const int64_t* args, size_t nargs);

/* ---- implementation ---------------------------------------------------- */

void* vader_ffi_open(const char* name) {
#ifdef _WIN32
    if (name == NULL || name[0] == '\0') {
        return (void*) GetModuleHandleW(NULL);
    }
    {
        char buf[256];
        int  n = snprintf(buf, sizeof buf, "%s.dll", name);
        if (n < 0 || (size_t) n >= sizeof buf) { return NULL; }
        return (void*) LoadLibraryA(buf);
    }
#else
    if (name == NULL || name[0] == '\0') {
        /* The running process: where a libc symbol lives. */
        return dlopen(NULL, RTLD_LAZY);
    }
    {
        char buf[256];
        int  n;
#  ifdef __APPLE__
        n = snprintf(buf, sizeof buf, "lib%s.dylib", name);
#  else
        n = snprintf(buf, sizeof buf, "lib%s.so", name);
#  endif
        if (n < 0 || (size_t) n >= sizeof buf) { return NULL; }
        return dlopen(buf, RTLD_LAZY);
    }
#endif
}

void* vader_ffi_symbol(void* lib, const char* symbol) {
    if (lib == NULL || symbol == NULL) { return NULL; }
#ifdef _WIN32
    return (void*) GetProcAddress((HMODULE) lib, symbol);
#else
    return dlsym(lib, symbol);
#endif
}

/* The trampolines.
 *
 * One arm per arity, with the cast written HERE so `cc` emits a call that obeys
 * the platform ABI. Silencing -Wcast-function-type is the point of the pragma:
 * the mismatch is deliberate and is what the file exists to do. */
#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wcast-function-type"
#endif

#define VADER_FFI_DISPATCH(RET)                                                       \
    switch (nargs) {                                                                  \
    case 0: return ((RET (*)(void)) fn)();                                            \
    case 1: return ((RET (*)(int64_t)) fn)(args[0]);                                   \
    case 2: return ((RET (*)(int64_t, int64_t)) fn)(args[0], args[1]);                 \
    case 3: return ((RET (*)(int64_t, int64_t, int64_t)) fn)(args[0], args[1], args[2]);\
    case 4: return ((RET (*)(int64_t, int64_t, int64_t, int64_t)) fn)                  \
                (args[0], args[1], args[2], args[3]);                                  \
    case 5: return ((RET (*)(int64_t, int64_t, int64_t, int64_t, int64_t)) fn)         \
                (args[0], args[1], args[2], args[3], args[4]);                         \
    case 6: return ((RET (*)(int64_t, int64_t, int64_t, int64_t, int64_t, int64_t)) fn)\
                (args[0], args[1], args[2], args[3], args[4], args[5]);                \
    case 7: return ((RET (*)(int64_t, int64_t, int64_t, int64_t, int64_t, int64_t,     \
                             int64_t)) fn)                                             \
                (args[0], args[1], args[2], args[3], args[4], args[5], args[6]);       \
    case 8: return ((RET (*)(int64_t, int64_t, int64_t, int64_t, int64_t, int64_t,     \
                             int64_t, int64_t)) fn)                                    \
                (args[0], args[1], args[2], args[3], args[4], args[5], args[6],        \
                 args[7]);                                                             \
    default: break;                                                                    \
    }

int64_t vader_ffi_call_int(void* fn, const int64_t* args, size_t nargs) {
    VADER_FFI_DISPATCH(int64_t)
    vader_trap("vader_ffi: more than 8 arguments in a foreign call");
    return 0;
}

double vader_ffi_call_f64(void* fn, const int64_t* args, size_t nargs) {
    VADER_FFI_DISPATCH(double)
    vader_trap("vader_ffi: more than 8 arguments in a foreign call");
    return 0.0;
}

void vader_ffi_call_void(void* fn, const int64_t* args, size_t nargs) {
    /* The integer arm discards its result; a void callee leaves the return
     * register undefined, which reading it as an integer never observes. */
    (void) vader_ffi_call_int(fn, args, nargs);
}

#undef VADER_FFI_DISPATCH

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif

#endif /* VADER_FFI_H */
