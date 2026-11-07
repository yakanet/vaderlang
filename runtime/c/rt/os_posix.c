/* rt/os_posix.c: what the runtime asks of a POSIX system (Linux, Darwin).
 *
 * The `vader_os_*` functions rt/internal.h lists, then what vader.h declares
 * and each OS provides its own way: the accessors `system/posix` binds and the
 * library loader of the VM's FFI. rt/os_windows.c defines the same set, and the
 * unity includes the one of the OS it builds for. */

#include "internal.h"

#include <dirent.h>
#include <dlfcn.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#ifndef MAP_ANONYMOUS
#  define MAP_ANONYMOUS MAP_ANON
#endif

#if defined(__linux__)
/* GNU, so left undeclared by the `_DEFAULT_SOURCE` rt/internal.h sets. */
int pthread_getattr_np(pthread_t thread, pthread_attr_t* attr);
#endif

extern char** environ;

/* ---- memory -------------------------------------------------------------- */

static char* vader_os_reserve(size_t bytes) {
    void* p = mmap(NULL, bytes, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) return NULL;
    return (char*) p;
}

/* An anonymous mapping is demand-paged: a page is committed at its first write. */
static int vader_os_commit(char* base, size_t bytes) {
    (void) base; (void) bytes;
    return 1;
}

/* `madvise` takes whole pages, so only the page-aligned interior of the range
 * goes back: its edges may share a page with a neighbour. */
static void vader_os_discard(char* base, char* end) {
    size_t page = (size_t) sysconf(_SC_PAGESIZE);
    if (page == 0u) return;
    uintptr_t a = ((uintptr_t) base + page - 1u) & ~(uintptr_t)(page - 1u);
    uintptr_t b = (uintptr_t) end & ~(uintptr_t)(page - 1u);
    if (b <= a) return;
#if defined(MADV_FREE)
    madvise((void*) a, (size_t)(b - a), MADV_FREE);
#elif defined(MADV_DONTNEED)
    madvise((void*) a, (size_t)(b - a), MADV_DONTNEED);
#endif
}

static void vader_os_release(char* base, size_t bytes) {
    munmap(base, bytes);
}

static int64_t vader_os_monotonic_ns(void) {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) return 0;
    return (int64_t) ts.tv_sec * 1000000000 + (int64_t) ts.tv_nsec;
}

static void vader_os_sleep_ns(int64_t ns) {
    struct timespec req;
    struct timespec rem;
    req.tv_sec = (time_t) (ns / 1000000000);
    req.tv_nsec = (long) (ns % 1000000000);
    /* A signal cuts the wait short and leaves what is left in `rem`. */
    while (nanosleep(&req, &rem) != 0 && errno == EINTR) req = rem;
}

static size_t vader_os_physical_ram(void) {
    long pages = sysconf(_SC_PHYS_PAGES);
    long psize = sysconf(_SC_PAGESIZE);
    if (pages > 0 && psize > 0) return (size_t) pages * (size_t) psize;
    return 0;
}

/* ---- stack --------------------------------------------------------------- */

static char* vader_os_stack_base(void) {
#if defined(__APPLE__)
    return (char*) pthread_get_stackaddr_np(pthread_self());
#else
    pthread_attr_t attr;
    if (pthread_getattr_np(pthread_self(), &attr) != 0) return NULL;
    void* addr = NULL; size_t size = 0;
    pthread_attr_getstack(&attr, &addr, &size);
    pthread_attr_destroy(&attr);
    if (addr == NULL) return NULL;
    return (char*) addr + size;
#endif
}

/* ---- standard streams ---------------------------------------------------- */

/* A POSIX stream carries its bytes as they are: there is no text mode. */
static void vader_os_ensure_stdio_binary(void) {
}

static void vader_os_report_fatal(const char* what, const char* detail, size_t detail_len) {
    fprintf(stderr, "vader: %s%.*s\n", what, (int) detail_len, detail);
}

/* ---- accessors ----------------------------------------------------------- */

/* The process environment, as `posix_spawnp` wants it.
 *
 * `environ` is a VARIABLE, not a function, and the FFI calls functions, so this
 * is the accessor that names it. Passing NULL instead would hand the child an
 * EMPTY environment, which is not what a subprocess inherits and would strip
 * PATH from everything the build spawns.
 *
 * `VADER_HOST_EXPORT` for the reason at the accessors below: the interpreter
 * resolves it by name at run time. */
VADER_HOST_EXPORT
char** vader_environ(void) {
    return environ;
}

/* What KIND of thing `path` is. Ordinals must match
 * `lib/system/posix/posix.vader`'s `PATH_*` constants.
 *
 * Here rather than in Vader because `struct stat` is not mirrorable at all: a
 * mirror is only valid as a contiguous leading prefix, `st_mode` leads on no
 * arch, and the arches disagree on field order.
 * See `docs/adr/0013-what-the-ffi-boundary-cannot-express.md`. */
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
#if defined(__APPLE__)
    return (int64_t) st.st_mtimespec.tv_sec * INT64_C(1000000000) + st.st_mtimespec.tv_nsec;
#else
    return (int64_t) st.st_mtim.tv_sec * INT64_C(1000000000) + st.st_mtim.tv_nsec;
#endif
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

/* Reading a NAMED member of a C struct is the one step a Vader FFI call cannot
 * take for itself, and it is all this accessor does: `std/io::read_dir` drives
 * `opendir` / `readdir` from Vader and calls it for the name. Only `cc` resolves
 * the offset, and only from the real header: `d_name` sits at 21 on Darwin
 * against 19 on glibc.
 *
 * It has to be a CALL and not a struct read: the interpreter has no C layout,
 * but it can call a C function and resolve one by name out of its own process.
 * `VADER_HOST_EXPORT` is what keeps that possible, see the macro.
 *
 * The bytes belong to the C library and die at the next `readdir`; the shim
 * interns them before then. */
VADER_HOST_EXPORT
const char* vader_dirent_name(void* ent) {
    return ((const struct dirent*) ent)->d_name;
}

/* ---- library loader ------------------------------------------------------ */

void* vader_ffi_open_path(const char* path) {
    return dlopen(path, RTLD_NOW | RTLD_LOCAL);
}

void* vader_ffi_open(const char* name) {
    if (name == NULL || name[0] == '\0') {
        /* The running process: where a libc symbol lives. */
        return dlopen(NULL, RTLD_LAZY);
    }
    char buf[256];
#if defined(__APPLE__)
    int n = snprintf(buf, sizeof buf, "lib%s.dylib", name);
#else
    int n = snprintf(buf, sizeof buf, "lib%s.so", name);
#endif
    if (n < 0 || (size_t) n >= sizeof buf) { return NULL; }
    return dlopen(buf, RTLD_LAZY);
}

void* vader_ffi_symbol(void* lib, const char* symbol) {
    if (lib == NULL || symbol == NULL) { return NULL; }
    return dlsym(lib, symbol);
}
