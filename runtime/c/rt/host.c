/* rt/host.c: what a program asks of its host: its arguments, binary stdio,
 * the target it runs on, and the accessors `system/posix` and `system/windows`
 * bind. */

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

/* ---- I/O ----------------------------------------------------------------- */


/* Switch stdin/stdout/stderr to binary mode on Windows. The CRT default is
 * text mode, which silently translates `\r\n` <-> `\n` and breaks any
 * length-prefixed binary transport (LSP, MCP, custom RPC) AND every `dump` /
 * `build` / `fmt` stdout (LF on disk, CRLF on the wire). stderr matters too:
 * the VM's runtime-error / panic messages are diffed byte-for-byte by the
 * snapshot suite, and text-mode `\n` -> `\r\n` on stderr makes every such line
 * mismatch by an invisible trailing `\r` on Windows. Called at program startup
 * (`vader_atom_init_with_comptime`); idempotent via the static flag. POSIX has
 * no such concept: the helper is a no-op there. */
static int g_stdio_binary_ready = 0;

static void vader_ensure_stdio_binary(void) {
    if (g_stdio_binary_ready) return;
    g_stdio_binary_ready = 1;
#if defined(_WIN32)
    _setmode(_fileno(stdin),  _O_BINARY);
    _setmode(_fileno(stdout), _O_BINARY);
    _setmode(_fileno(stderr), _O_BINARY);
#endif
}

/* The process environment, as `posix_spawnp` wants it.
 *
 * `environ` is a VARIABLE, not a function, and the FFI calls functions, so this
 * is the accessor that names it. Passing NULL instead would hand the child an
 * EMPTY environment, which is not what a subprocess inherits and would strip
 * PATH from everything the build spawns.
 *
 * `VADER_HOST_EXPORT` for the reason at the accessors below: the interpreter
 * resolves it by name at run time. */
#if !defined(_WIN32)
VADER_HOST_EXPORT
char** vader_environ(void) {
    return environ;
}
#endif

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
 * the struct-member accessors below: `cc` resolves what Vader cannot, and the
 * result crosses as a plain value.
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

/* What KIND of thing `path` is. Ordinals must match
 * `lib/system/posix/posix.vader`'s `PATH_*` constants.
 *
 * Here rather than in Vader because `struct stat` is not mirrorable at all: a
 * mirror is only valid as a contiguous leading prefix, `st_mode` leads on no
 * arch, and the arches disagree on field order.
 * See `docs/adr/0013-what-the-ffi-boundary-cannot-express.md`. */
#if !defined(_WIN32)
#include <sys/stat.h>
VADER_HOST_EXPORT
int32_t vader_path_kind(const char* path) {
    struct stat st;
    if (stat(path, &st) != 0) return 0;
    if (S_ISREG(st.st_mode))  return 1;
    if (S_ISDIR(st.st_mode))  return 2;
    return 3;
}

/* When `path` was last modified, in nanoseconds since the Unix epoch, or -1 when
 * `stat` fails. Here for the reason `vader_path_kind` gives, and because Darwin
 * names the member `st_mtimespec` where Linux says `st_mtim`. */
VADER_HOST_EXPORT
int64_t vader_path_mtime(const char* path) {
    struct stat st;
    if (stat(path, &st) != 0) return -1;
#  if defined(__APPLE__)
    return (int64_t) st.st_mtimespec.tv_sec * INT64_C(1000000000) + st.st_mtimespec.tv_nsec;
#  else
    return (int64_t) st.st_mtim.tv_sec * INT64_C(1000000000) + st.st_mtim.tv_nsec;
#  endif
}

/* The size of the regular file the `FILE*` `stream` reads, or -1 for anything
 * else (a pipe, a device) or when `fstat` fails: only a regular file's size says
 * how much a read will find. Here for the reason `vader_path_kind` gives. */
VADER_HOST_EXPORT
int64_t vader_stream_size(void* stream) {
    struct stat st;
    if (fstat(fileno((FILE*) stream), &st) != 0 || !S_ISREG(st.st_mode)) return -1;
    return (int64_t) st.st_size;
}
#endif

/* ---- directory-entry accessors ------------------------------------------- */

/* Reading a NAMED member of a C struct is the one step a Vader FFI call cannot
 * take for itself, and it is all these accessors do: `std/io::read_dir` drives
 * `opendir` / `readdir` / `FindFirstFileW` from Vader and calls one of these for
 * the name. Only `cc` resolves the offset, and only from the real header:
 * `d_name` sits at 21 on Darwin against 19 on glibc.
 *
 * They have to be CALLS and not struct reads: the interpreter has no C layout,
 * but it can call a C function and resolve one by name out of its own process.
 * `VADER_HOST_EXPORT` is what keeps that possible, see the macro. */

#if defined(_WIN32)


/* It carries the UTF-16 conversion as well: `cFileName` is `WCHAR[MAX_PATH]`
 * and a Vader string is UTF-8, so the encoding difference belongs on this side
 * of the boundary.
 *
 * The result lives in a static buffer, valid until the next call: the same
 * contract `cFileName` itself has, since `FindNextFileW` overwrites it. The shim
 * interns before either happens. */
VADER_HOST_EXPORT
const char* vader_find_data_name(const void* fd) {
    static char utf8[MAX_PATH * 4];
    const WIN32_FIND_DATAW* d = (const WIN32_FIND_DATAW*) fd;
    int n = WideCharToMultiByte(CP_UTF8, 0, d->cFileName, -1,
                                utf8, (int) sizeof(utf8), NULL, NULL);
    if (n <= 0) {
        utf8[0] = '\0';
    }
    return utf8;
}

#else  /* POSIX */

#include <dirent.h>

/* The bytes belong to the C library and die at the next `readdir`; the shim
 * interns them before then. */
VADER_HOST_EXPORT
const char* vader_dirent_name(const void* ent) {
    return ((const struct dirent*) ent)->d_name;
}

#endif  /* _WIN32 / POSIX */


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
