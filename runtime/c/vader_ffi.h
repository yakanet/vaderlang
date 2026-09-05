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
 * `size_t` or a `void*` alike. Floats travel in OTHER registers, so a call is
 * either all-word or all-double — the mixed shape has no slot layout a fixed
 * trampoline can express, and neither do structs by value, whose classification
 * is per-field. The all-double shape covers one or two arguments; see the
 * dispatch in `vader_ffi_call_n`.
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

/* Largest arity a trampoline covers. Past six, every ABI we target starts
 * passing integer arguments on the stack. */
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
static void* vader_ffi_resolve(void* lib, const char* symbol);

/* Call `fn` with `nargs` integer-or-pointer arguments.
 *
 * `_int` reads the result as an integer, `_void` discards it, `_f64` reads it
 * as a double. All three TRAP when `nargs > VADER_FFI_MAX_ARGS` rather than
 * calling with a truncated argument list. */
int64_t vader_ffi_call_int(void* fn, const int64_t* args, size_t nargs);

/* ---- implementation ---------------------------------------------------- */

/* Handle onto the process's own C runtime. Memoised because `dispatch_extern`
 * asks for it on EVERY foreign call — a `println` on the VM would otherwise pay
 * a `dlopen` each time, and each one bumps a refcount that is never dropped. */
static void* vader_ffi_self = NULL;

void* vader_ffi_open(const char* name) {
    if (name == NULL || name[0] == '\0') {
        if (vader_ffi_self != NULL) { return vader_ffi_self; }
    }
#ifdef _WIN32
    if (name == NULL || name[0] == '\0') {
        /* The C runtime, which is where a libc-shaped symbol lives. NOT the
         * process handle: an EXE's export table is empty, so `GetProcAddress`
         * on it finds nothing — POSIX only gets away with `dlopen(NULL)`
         * because that exposes the whole global symbol scope. */
        HMODULE h = GetModuleHandleA("ucrtbase.dll");
        if (h == NULL) { h = GetModuleHandleA("msvcrt.dll"); }
        if (h == NULL) { h = GetModuleHandleW(NULL); }
        vader_ffi_self = (void*) h;
        return vader_ffi_self;
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
        vader_ffi_self = dlopen(NULL, RTLD_LAZY);
        return vader_ffi_self;
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

/* Resolved-symbol memo. `dispatch_extern` resolves on EVERY foreign call, so
 * without this a VM-executed `println` pays a full `dlsym` symbol-table search
 * each time.
 *
 * Linear and small on purpose: a program reaches a handful of distinct foreign
 * symbols, and a scan of a few entries costs less than any hashing would. Names
 * are strdup'd because the caller's `const char*` is a marshalling temporary.
 * A full table simply stops memoising rather than evicting — correctness never
 * depends on the cache. */
#define VADER_FFI_MEMO_SIZE 64
static struct { void* lib; char* name; void* addr; } vader_ffi_memo[VADER_FFI_MEMO_SIZE];
static size_t vader_ffi_memo_len = 0;

void* vader_ffi_symbol(void* lib, const char* symbol) {
    size_t i;
    if (lib == NULL || symbol == NULL) { return NULL; }
    for (i = 0; i < vader_ffi_memo_len; i++) {
        if (vader_ffi_memo[i].lib == lib && strcmp(vader_ffi_memo[i].name, symbol) == 0) {
            return vader_ffi_memo[i].addr;
        }
    }
    {
        void* found = vader_ffi_resolve(lib, symbol);
        if (vader_ffi_memo_len < VADER_FFI_MEMO_SIZE) {
            size_t n = strlen(symbol) + 1;
            char*  copy = (char*) malloc(n);
            if (copy != NULL) {
                memcpy(copy, symbol, n);
                vader_ffi_memo[vader_ffi_memo_len].lib  = lib;
                vader_ffi_memo[vader_ffi_memo_len].name = copy;
                vader_ffi_memo[vader_ffi_memo_len].addr = found;
                vader_ffi_memo_len++;
            }
        }
        return found;
    }
}

/* The uncached lookup — the memo above is the only caller. */
static void* vader_ffi_resolve(void* lib, const char* symbol) {
#ifdef _WIN32
    {
        void* p = (void*) GetProcAddress((HMODULE) lib, symbol);
        if (p == NULL && symbol[0] != '_') {
            /* The CRT exports its POSIX-shaped entry points with a leading
             * underscore — `write` is `_write`, `getpid` is `_getpid`. The
             * unprefixed spelling that the LINKER accepts is a compile-time
             * alias, absent from the export table. */
            char buf[128];
            int  n = snprintf(buf, sizeof buf, "_%s", symbol);
            if (n > 0 && (size_t) n < sizeof buf) {
                p = (void*) GetProcAddress((HMODULE) lib, buf);
            }
        }
        if (p == NULL) {
            /* Then the EXE's own export table. POSIX gets this for free —
             * `dlopen(NULL)` exposes the whole global scope, so a runtime symbol
             * like `vader_dirent_name` resolves there — while on Windows the CRT
             * handle above knows nothing of the running program. Anything the
             * interpreter must reach in ITSELF is `VADER_HOST_EXPORT`ed, which
             * is what puts it in this table. */
            p = (void*) GetProcAddress(GetModuleHandleW(NULL), symbol);
        }
        return p;
    }
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

/* Argument / result classes for `vader_ffi_call`. Mirrored by
 * `vader/vm/host.vader::ffi_class_*` — the two must agree. */
#define VADER_FFI_VOID 0u
#define VADER_FFI_WORD 1u
#define VADER_FFI_F64  2u
#define VADER_FFI_ADDR 3u
#define VADER_FFI_STR  4u
#define VADER_FFI_STR_OPT 5u

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

/* Variadic dispatch, one entry per FIXED-argument count.
 *
 * A variadic callee cannot be called through a non-variadic prototype. On
 * x86-64 the two happen to agree — variadic arguments travel in the same
 * registers — which is why this went unnoticed on Linux. On darwin-arm64 they
 * do NOT: variadic arguments go on the STACK, so a cast to
 * `(int64_t (*)(int64_t, int64_t, int64_t))` puts the third argument in `x2`
 * while the callee's `va_arg` reads an uninitialised stack word. `ioctl(fd,
 * TIOCGWINSZ, &ws)` had the kernel write eight bytes to that stale address and
 * report success; `open(path, flags, mode)` created files with mode 0.
 *
 * The fixed count cannot be derived from the argument count — only the callee's
 * real prototype knows it — so it is declared, by `@c_variadic(N)`.
 *
 * One function per fixed count rather than one macro: the cast has to name the
 * fixed parameters, and C has no way to build a prototype from a count. */
static int64_t vader_ffi_call_va(void* fn, const int64_t* args, size_t nargs,
                                 size_t nfixed) {
    size_t nvar = nargs - nfixed;
    if (nfixed > nargs || nvar > 3) {
        vader_trap("vader_ffi: a variadic call needs 0..3 variadic arguments");
    }
    switch (nfixed) {
    case 1: {
        typedef int64_t (*f1_t)(int64_t, ...);
        switch (nvar) {
        case 0: return ((f1_t) fn)(args[0]);
        case 1: return ((f1_t) fn)(args[0], args[1]);
        case 2: return ((f1_t) fn)(args[0], args[1], args[2]);
        default: return ((f1_t) fn)(args[0], args[1], args[2], args[3]);
        }
    }
    case 2: {
        typedef int64_t (*f2_t)(int64_t, int64_t, ...);
        switch (nvar) {
        case 0: return ((f2_t) fn)(args[0], args[1]);
        case 1: return ((f2_t) fn)(args[0], args[1], args[2]);
        case 2: return ((f2_t) fn)(args[0], args[1], args[2], args[3]);
        default: return ((f2_t) fn)(args[0], args[1], args[2], args[3], args[4]);
        }
    }
    case 3: {
        typedef int64_t (*f3_t)(int64_t, int64_t, int64_t, ...);
        switch (nvar) {
        case 0: return ((f3_t) fn)(args[0], args[1], args[2]);
        case 1: return ((f3_t) fn)(args[0], args[1], args[2], args[3]);
        case 2: return ((f3_t) fn)(args[0], args[1], args[2], args[3], args[4]);
        default: return ((f3_t) fn)(args[0], args[1], args[2], args[3], args[4], args[5]);
        }
    }
    default: break;
    }
    vader_trap("vader_ffi: a variadic call needs 1..3 fixed arguments");
    return 0;
}

int64_t vader_ffi_call_int(void* fn, const int64_t* args, size_t nargs) {
    VADER_FFI_DISPATCH(int64_t)
    vader_trap("vader_ffi: more than 8 arguments in a foreign call");
    return 0;
}

/* One foreign call, described by DATA rather than by its shape.
 *
 * `desc` is one byte per slot: `desc[0]` classifies the RESULT, `desc[1+i]` the
 * i-th argument. `frame` holds the argument slots — eight bytes each, in order —
 * followed by whatever bytes a `VADER_FFI_ADDR` slot points into; the result is
 * written back over its first eight bytes.
 *
 * This is what lets ONE intrinsic serve every signature: adding a shape widens
 * the switch below and touches no Vader. What is not covered traps by name
 * rather than mis-marshalling a frame.
 *
 * The RESULT of a `VADER_FFI_STR` call is returned rather than written into the
 * frame: it is an atom id, and the VM has no way to build a `string` from one —
 * whereas a returned `vader_string_t` IS a Vader string. Every other shape
 * returns `VADER_ATOM_EMPTY`, which callers ignore. */
vader_string_t vader_ffi_call(void* fn, vader_array_t* desc, vader_array_t* frame) {
    return vader_ffi_call_n(fn, desc, frame, -1);
}

vader_string_t vader_ffi_call_n(void* fn, vader_array_t* desc, vader_array_t* frame,
                                int64_t nfixed) {
    vader_slice_t        dview = vader_array_bytes(desc);
    vader_slice_t        fview;
    const unsigned char* cls;
    int64_t              words[VADER_FFI_MAX_ARGS];
    double               reals[VADER_FFI_MAX_ARGS];
    size_t               nargs, i, nreal = 0, nword = 0;

    if (dview.len == 0) {
        vader_trap("vader_ffi: empty call descriptor");
    }
    cls   = (const unsigned char*) dview.ptr;
    nargs = dview.len - 1;
    if (nargs > VADER_FFI_MAX_ARGS) {
        vader_trap("vader_ffi: more than 8 arguments in a foreign call");
    }

    /* Last resolution before the call: nothing below allocates, so this address
     * is the one the callee reads. */
    fview = vader_array_bytes(frame);
    if (fview.len < nargs * sizeof(int64_t)) {
        vader_trap("vader_ffi: frame smaller than its argument list");
    }
    /* A value-returning call writes its result into the frame's first slot, so
     * the argument count alone does not size it: with no arguments the check
     * above is `0 < 0` and the store below would land on the NULL pointer an
     * empty array reports. Trapping names the contract instead of crashing. */
    if (cls[0] != VADER_FFI_VOID && fview.len < sizeof(int64_t)) {
        vader_trap("vader_ffi: frame has no slot for the result");
    }

    for (i = 0; i < nargs; i++) {
        int64_t raw = ((const int64_t*) fview.ptr)[i];
        switch (cls[i + 1]) {
        case VADER_FFI_WORD: words[nword++] = raw; break;
        case VADER_FFI_F64:  { double d; memcpy(&d, &raw, sizeof d); reals[nreal++] = d; break; }
        case VADER_FFI_ADDR:
            if (raw < 0 || (size_t) raw > fview.len) {
                vader_trap("vader_ffi: lent offset outside the frame");
            }
            words[nword++] = (int64_t) (intptr_t) ((unsigned char*) fview.ptr + raw);
            break;
        default: vader_trap("vader_ffi: unknown argument class");
        }
    }

    /* Shapes covered so far: all-word, and all-double with one or two arguments.
     * A MIX needs one form per combination of classes — the point at which
     * fabricating the call (libffi, or a thunk) starts to pay. */
    if (nreal == 0) {
        /* `nfixed >= 0` means the callee is VARIADIC and that many of its
         * parameters are fixed — declared, because only the real prototype knows
         * where the fixed ones end. The cast has to be variadic too: see
         * `vader_ffi_call_va`. */
        int64_t r = nfixed >= 0
            ? vader_ffi_call_va(fn, words, nargs, (size_t) nfixed)
            : vader_ffi_call_int(fn, words, nargs);
        if (cls[0] == VADER_FFI_F64) {
            vader_trap("vader_ffi: floating result from an integer call shape");
        }
        if (cls[0] == VADER_FFI_STR_OPT) {
            /* `char*` says "absent" with NULL, which `string` alone cannot carry.
             * The frame's first slot takes the presence flag; the atom is
             * returned like any other string. */
            const char* p = (const char*) (intptr_t) r;
            int64_t     present = p == NULL ? 0 : 1;
            memcpy((void*) fview.ptr, &present, sizeof present);
            return p == NULL ? VADER_ATOM_EMPTY : vader_atom_intern(p, strlen(p));
        }
        if (cls[0] == VADER_FFI_STR) {
            /* Borrowed: interned, never freed. The worst case of that default is
             * a leak on the C side, never a corruption — and it is right for the
             * library-owned pointers (`getenv`, `strerror`) it serves. NULL
             * becomes the empty string, `string` having no null variant. */
            const char* p = (const char*) (intptr_t) r;
            return p == NULL ? VADER_ATOM_EMPTY : vader_atom_intern(p, strlen(p));
        }
        if (cls[0] != VADER_FFI_VOID) {
            memcpy((void*) fview.ptr, &r, sizeof r);
        }
        return VADER_ATOM_EMPTY;
    }
    if (nword != 0) {
        vader_trap("vader_ffi: mixing floating and integer arguments is not covered");
    }
    if (cls[0] != VADER_FFI_F64) {
        vader_trap("vader_ffi: a floating call shape must return a double");
    }
    {
        double r;
        if (nreal == 1) {
            r = ((double (*)(double)) fn)(reals[0]);
        } else if (nreal == 2) {
            r = ((double (*)(double, double)) fn)(reals[0], reals[1]);
        } else {
            vader_trap("vader_ffi: more than two floating arguments is not covered");
            return VADER_ATOM_EMPTY;
        }
        memcpy((void*) fview.ptr, &r, sizeof r);
    }
    return VADER_ATOM_EMPTY;
}

#undef VADER_FFI_DISPATCH

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif

#endif /* VADER_FFI_H */
