/* rt/host.c: what a program asks of its host: its arguments, the target it
 * runs on, and the accessors every host defines, whichever OS binds them. The
 * accessors of one OS are in rt/os_posix.c and rt/os_windows.c. */

#include "internal.h"

/* Box the host argv into a `string[]` Vader array. Called from emitted main
 * when the user's `main` takes a `string[]` parameter. The caller passes the
 * BcType indices for the array type and the string element type (the emitter
 * knows them at codegen time).
 *
 * Each `vader_array_push` may collect; the shadow-stack frame keeps `arr_box`
 * reachable so its `payload.obj` tracks the array across moves. */
vader_array_t* vader_runtime_argv(int argc, char** argv, uint32_t arr_type, uint32_t str_type) {
    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
    VADER_GC_PUSH1(arr_box);
    for (int i = 0; i < argc; i++) {
        const char* a = argv[i];
        size_t len = strlen(a);
        vader_array_push((vader_array_t*) arr_box.payload.obj,
                         vader_box_string(str_type, vader_string_new(a, len)));
    }
    vader_array_t* result = (vader_array_t*) arr_box.payload.obj;
    VADER_GC_POP();
    return result;
}

/* The `i`-th pointer-sized word at `base`.
 *
 * For an out-parameter a callee fills with a HANDLE (`CreatePipe` writes two)
 * where the Vader side lends a buffer and has no way to read a pointer back out
 * of it: `CPointer` cannot be built from an integer (T3010), and a lent array
 * yields integers.
 *
 * @param base  the lent buffer.
 * @param i     the word index.
 */
VADER_HOST_EXPORT
void* vader_ptr_at(const void* base, int64_t i) {
    return ((void* const*) base)[i];
}

/* The calling thread's `errno`.
 *
 * Here because `errno` is a MACRO, not a symbol (`*__error()` on Darwin,
 * `*__errno_location()` on glibc) so no `@extern` can name it. Same escape as
 * the struct-member accessors of rt/os_posix.c: `cc` resolves what Vader
 * cannot, and the result crosses as a plain value.
 * See `docs/adr/0013-what-the-ffi-boundary-cannot-express.md`.
 *
 * NOT guarded by `#if !defined(_WIN32)`, though only the POSIX bodies call it.
 * `errno` is standard C and the Windows CRT has it, and the interpreter runs a
 * PINNED target's bodies on whatever host it is on: a `--target=linux-x86_64`
 * bytecode executed on Windows calls this, and a guard would make the symbol
 * missing there. */
VADER_HOST_EXPORT
int32_t vader_last_errno(void) {
    return (int32_t) errno;
}

/* ---- target -------------------------------------------------------------- */

/* Ordinals must match `std/target::Os`, declaration order. An unsupported
 * platform is a build error rather than a guess: the OS set is closed, and a
 * silent fallback would make `current_os()` lie exactly where it is trusted. */
int32_t vader_current_os(void) {
#if defined(_WIN32)
    return 0;   /* Os.Windows */
#elif defined(__linux__)
    return 1;   /* Os.Linux */
#elif defined(__APPLE__)
    return 2;   /* Os.Darwin */
#elif defined(__wasi__)
    return 3;   /* Os.Wasi */
#elif defined(__wasm__)
    return 4;   /* Os.Browser */
#else
#  error "vader_current_os: unsupported platform - add it to std/target::Os first"
#endif
}

/* Ordinals must match `std/target::Arch`, declaration order. Unsupported is a
 * build error for the same reason as the OS: guessing an architecture would be
 * wrong in the one place the answer is trusted. */
int32_t vader_current_arch(void) {
#if defined(__wasm32__) || defined(__wasm__)
    return 2;   /* Arch.Wasm32 */
#elif defined(__aarch64__) || defined(_M_ARM64)
    return 1;   /* Arch.Arm64 */
#elif defined(__x86_64__) || defined(_M_X64)
    return 0;   /* Arch.X86_64 */
#else
#  error "vader_current_arch: unsupported architecture - add it to std/target::Arch first"
#endif
}
