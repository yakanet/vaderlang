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
static void* vader_ffi_resolve(void* lib, const char* symbol);

/* Call `fn` with `nargs` integer-or-pointer arguments.
 *
 * `_int` reads the result as an integer, `_void` discards it, `_f64` reads it
 * as a double. All three TRAP when `nargs > VADER_FFI_MAX_ARGS` rather than
 * calling with a truncated argument list. */
int64_t vader_ffi_call_int(void* fn, const int64_t* args, size_t nargs);

/* As `vader_ffi_call_int`, but slot `buf_slot` receives the ADDRESS of `bytes`
 * instead of the value in `args`.
 *
 * The address is taken here, immediately before the call, and never reaches
 * Vader. That is the point, and it is what `std/core/buffer.vader` asks of the
 * frontend ("never a machine address"): the array is GC-managed and may move,
 * and no Vader code — hence no allocation, hence no collection — runs between
 * the two statements below. A caller that took the address itself would leave
 * a window open for as long as it took to build the argument list. */
int64_t vader_ffi_call_int_bytes(void* fn, const int64_t* args, size_t nargs,
                                 size_t buf_slot, vader_array_t* bytes);
void    vader_ffi_call_void(void* fn, const int64_t* args, size_t nargs);
double  vader_ffi_call_f64(void* fn, const int64_t* args, size_t nargs);

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

/* Resolved-symbol memo. `dispatch_extern` resolves on EVERY foreign call, so a
 * VM-executed `println` paid a full `dlsym` symbol-table search each time — the
 * test suite went from 41 s to 153 s before this existed.
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

int64_t vader_ffi_call_int_bytes(void* fn, const int64_t* args, size_t nargs,
                                 size_t buf_slot, vader_array_t* bytes) {
    int64_t      slots[VADER_FFI_MAX_ARGS];
    size_t       i;
    vader_slice_t view;

    if (nargs > VADER_FFI_MAX_ARGS) {
        vader_trap("vader_ffi: more than 8 arguments in a foreign call");
    }
    if (buf_slot >= nargs) {
        vader_trap("vader_ffi: lent-bytes slot outside the argument list");
    }
    for (i = 0; i < nargs; i++) { slots[i] = args[i]; }

    /* `vader_array_bytes` owns the three cases — GC forward, borrowed view,
     * materialised buffer — and is the same helper the native shims use. */
    view = vader_array_bytes(bytes);
    slots[buf_slot] = (int64_t) (intptr_t) view.ptr;

    return vader_ffi_call_int(fn, slots, nargs);
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
