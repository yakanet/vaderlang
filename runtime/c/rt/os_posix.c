/* rt/os_posix.c: what the runtime asks of a POSIX system (Linux, Darwin).
 *
 * The `vader_os_*` functions rt/internal.h lists, then what vader.h declares
 * and each OS provides its own way: the accessors `system/posix` binds and the
 * library loader of the VM's FFI. rt/os_windows.c defines the same set, and the
 * unity includes the one of the OS it builds for. */

#include "internal.h"

#include <dirent.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <poll.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#if defined(__APPLE__)
#  include <sys/event.h>
#elif defined(__linux__)
#  include <sys/epoll.h>
#  include <sys/syscall.h>
#  if !defined(SYS_pidfd_open)
#    define SYS_pidfd_open 434   /* the same on every architecture */
#  endif
#endif

#ifndef MAP_ANONYMOUS
#  define MAP_ANONYMOUS MAP_ANON
#endif

#if defined(__linux__)
/* GNU, so left undeclared by the `_DEFAULT_SOURCE` rt/internal.h sets. */
int pthread_getattr_np(pthread_t thread, pthread_attr_t* attr);
#endif

extern char** environ;

/* ---- memory -------------------------------------------------------------- */

/* The reservation stays out of a core dump until it is committed: Linux dumps a
 * written mapping whole, and through a pipe (apport, systemd-coredump) every page
 * never touched is a page of zeros, gigabytes of them. */
static char* vader_os_reserve(size_t bytes) {
    void* p = mmap(NULL, bytes, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) return NULL;
#if defined(MADV_DONTDUMP)
    madvise(p, bytes, MADV_DONTDUMP);
#endif
    return (char*) p;
}

/* An anonymous mapping is demand-paged: a page is committed at its first write.
 * `base` starts on a page, as `madvise` requires. */
static int vader_os_commit(char* base, size_t bytes) {
    (void) base; (void) bytes;
#if defined(MADV_DODUMP)
    madvise(base, bytes, MADV_DODUMP);
#endif
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

/* ---- what the OS reports ------------------------------------------------- */

/* The most events one wait takes; the rest wait for the next. */
#define VADER_OS_EVENTS 64

/* A read that fails is ready too: the read then reports the failure. */
static int vader_os_readable_now(int64_t fd) {
    struct pollfd probe;
    probe.fd = (int) fd;
    probe.events = POLLIN;
    probe.revents = 0;
    return poll(&probe, 1, 0) != 0;
}

#if defined(__APPLE__)

static int g_os_queue = -1;

static int vader_os_watch(int kind, int64_t id) {
    if (g_os_queue < 0) {
        g_os_queue = kqueue();
        if (g_os_queue < 0) return 0;
        fcntl(g_os_queue, F_SETFD, FD_CLOEXEC);
    }
    struct kevent change;
    if (kind == VADER_WATCH_EXIT) {
        EV_SET(&change, (uintptr_t) id, EVFILT_PROC, EV_ADD | EV_ONESHOT, NOTE_EXIT, 0, NULL);
    } else {
        EV_SET(&change, (uintptr_t) id, EVFILT_READ, EV_ADD | EV_ONESHOT, 0, 0, NULL);
    }
    return kevent(g_os_queue, &change, 1, NULL, 0, NULL) == 0;
}

static void vader_os_wait_events(int64_t timeout_ns) {
    struct timespec limit;
    struct timespec* until = NULL;
    if (timeout_ns >= 0) {
        limit.tv_sec = (time_t) (timeout_ns / 1000000000);
        limit.tv_nsec = (long) (timeout_ns % 1000000000);
        until = &limit;
    }
    struct kevent events[VADER_OS_EVENTS];
    int got = kevent(g_os_queue, NULL, 0, events, VADER_OS_EVENTS, until);
    for (int i = 0; i < got; i++) {
        int kind = VADER_WATCH_READABLE;
        if (events[i].filter == EVFILT_PROC) kind = VADER_WATCH_EXIT;
        vader_scheduler_on_event(kind, (int64_t) events[i].ident);
    }
}

#elif defined(__linux__)

static int g_os_queue = -1;

/* A child's end reads on a descriptor of its own, open until it is reported. */
typedef struct {
    int64_t child;
    int     fd;
} vader_os_pidfd_t;

static vader_os_pidfd_t* g_os_pidfds = NULL;
static size_t g_os_pidfd_len = 0;
static size_t g_os_pidfd_cap = 0;

/* Watch `fd` until it reads once, reported as `id` watched as `kind`. */
static int vader_os_arm(int fd, int kind, int64_t id) {
    if (g_os_queue < 0) {
        g_os_queue = epoll_create1(EPOLL_CLOEXEC);
        if (g_os_queue < 0) return 0;
    }
    struct epoll_event event;
    memset(&event, 0, sizeof event);
    event.events = EPOLLIN | EPOLLONESHOT;
    /* A descriptor and a pid both fit in 32 bits. */
    event.data.u64 = ((uint64_t) (uint32_t) kind << 32) | (uint64_t) (uint32_t) id;
    /* Watched before, it is armed again: a one-shot watch stays registered. */
    if (epoll_ctl(g_os_queue, EPOLL_CTL_MOD, fd, &event) == 0) return 1;
    return errno == ENOENT && epoll_ctl(g_os_queue, EPOLL_CTL_ADD, fd, &event) == 0;
}

/* Without a pidfd (a kernel before 5.3, a filter on system calls), the child
 * is not watched. */
static int vader_os_watch_child(int64_t child) {
    for (size_t i = 0; i < g_os_pidfd_len; i++) {
        if (g_os_pidfds[i].child == child) return vader_os_arm(g_os_pidfds[i].fd, VADER_WATCH_EXIT, child);
    }
    int fd = (int) syscall(SYS_pidfd_open, (pid_t) child, 0);
    if (fd < 0) return 0;
    if (g_os_pidfd_len == g_os_pidfd_cap) {
        size_t cap = 16u;
        if (g_os_pidfd_cap != 0u) cap = g_os_pidfd_cap * 2u;
        vader_os_pidfd_t* grown = (vader_os_pidfd_t*) realloc(g_os_pidfds, cap * sizeof(vader_os_pidfd_t));
        if (grown == NULL) {
            close(fd);
            return 0;
        }
        g_os_pidfds = grown;
        g_os_pidfd_cap = cap;
    }
    if (!vader_os_arm(fd, VADER_WATCH_EXIT, child)) {
        close(fd);
        return 0;
    }
    g_os_pidfds[g_os_pidfd_len++] = (vader_os_pidfd_t) { child, fd };
    return 1;
}

static int vader_os_watch(int kind, int64_t id) {
    if (kind == VADER_WATCH_EXIT) return vader_os_watch_child(id);
    return vader_os_arm((int) id, VADER_WATCH_READABLE, id);
}

static void vader_os_close_pidfd(int64_t child) {
    for (size_t i = 0; i < g_os_pidfd_len; i++) {
        if (g_os_pidfds[i].child != child) continue;
        close(g_os_pidfds[i].fd);
        g_os_pidfds[i] = g_os_pidfds[--g_os_pidfd_len];
        return;
    }
}

static void vader_os_wait_events(int64_t timeout_ns) {
    /* In milliseconds, rounded up so the wait is never shorter. */
    int timeout_ms = -1;
    if (timeout_ns >= 0) {
        int64_t ms = timeout_ns / 1000000;
        if (timeout_ns % 1000000 != 0) ms += 1;
        timeout_ms = 0x7FFFFFFF;
        if (ms < (int64_t) timeout_ms) timeout_ms = (int) ms;
    }
    struct epoll_event events[VADER_OS_EVENTS];
    int got = epoll_wait(g_os_queue, events, VADER_OS_EVENTS, timeout_ms);
    for (int i = 0; i < got; i++) {
        int kind = (int) (events[i].data.u64 >> 32);
        int64_t id = (int64_t) (uint32_t) events[i].data.u64;
        if (kind == VADER_WATCH_EXIT) vader_os_close_pidfd(id);
        vader_scheduler_on_event(kind, id);
    }
}

#else

/* No watch is taken: each is a short sleep instead. */
static int vader_os_watch(int kind, int64_t id) {
    (void) kind;
    (void) id;
    return 0;
}

static void vader_os_wait_events(int64_t timeout_ns) {
    if (timeout_ns > 0) vader_os_sleep_ns(timeout_ns);
}

#endif

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

/* The `index`-th `NAME=value` of `environ`, NULL past the last: the caller
 * stops there. A `setenv` may move the array, so it is read entry by entry,
 * never held. */
VADER_HOST_EXPORT
const char* vader_environ_entry(int64_t index) {
    return environ[index];
}

/* What KIND of file `mode` describes. Ordinals must match
 * `lib/system/posix/posix.vader`'s `PATH_*` constants.
 *
 * Here rather than in Vader because `struct stat` is not mirrorable at all: a
 * mirror is only valid as a contiguous leading prefix, `st_mode` leads on no
 * arch, and the arches disagree on field order.
 * See `docs/adr/0013-what-the-ffi-boundary-cannot-express.md`. */
static int32_t kind_of_mode(mode_t mode) {
    if (S_ISREG(mode)) return 1;
    if (S_ISDIR(mode)) return 2;
    if (S_ISLNK(mode)) return 4;
    return 3;
}

/* When `st` was last modified, in nanoseconds since the Unix epoch. Darwin
 * names the member `st_mtimespec` where Linux says `st_mtim`. */
static int64_t mtime_of_stat(const struct stat* st) {
#if defined(__APPLE__)
    return (int64_t) st->st_mtimespec.tv_sec * INT64_C(1000000000) + st->st_mtimespec.tv_nsec;
#else
    return (int64_t) st->st_mtim.tv_sec * INT64_C(1000000000) + st->st_mtim.tv_nsec;
#endif
}

/* The size of a regular file, -1 for anything else (a pipe, a device): only a
 * regular file's size says how much a read will find. */
static int64_t size_of_stat(const struct stat* st) {
    if (!S_ISREG(st->st_mode)) return -1;
    return (int64_t) st->st_size;
}

/* What KIND of thing `path` is, as `kind_of_mode` names it; 0 when `stat`
 * fails. */
VADER_HOST_EXPORT
int32_t vader_path_kind(const char* path) {
    struct stat st;
    if (stat(path, &st) != 0) return 0;
    return kind_of_mode(st.st_mode);
}

/* When `path` was last modified, as `mtime_of_stat` gives it, or -1 when `stat`
 * fails. Here for the reason `vader_path_kind` gives. No binding calls it: the
 * committed bootstrap seed does, and the seed's build fails without it. */
VADER_HOST_EXPORT
int64_t vader_path_mtime(const char* path) {
    struct stat st;
    if (stat(path, &st) != 0) return -1;
    return mtime_of_stat(&st);
}

/* What the file system records of `path`, in four cells of `out`: its kind as
 * `kind_of_mode` names it, its size, when it was last modified as
 * `mtime_of_stat` gives it, and its permission bits. Through `stat`, or `lstat`
 * when `follow_links` is 0, so that a link reports itself. 0 on success, -1 when
 * the call fails, `errno` saying why. Here for the reason `vader_path_kind`
 * gives. */
VADER_HOST_EXPORT
int32_t vader_path_stat(const char* path, int32_t follow_links, int64_t* out) {
    struct stat st;
    int failed = follow_links ? stat(path, &st) : lstat(path, &st);
    if (failed != 0) return -1;
    out[0] = kind_of_mode(st.st_mode);
    out[1] = (int64_t) st.st_size;
    out[2] = mtime_of_stat(&st);
    out[3] = (int64_t) (st.st_mode & 07777);
    return 0;
}

/* The size of the regular file the `FILE*` `stream` reads, as `size_of_stat`
 * gives it, or -1 when `fstat` fails. Here for the reason `vader_path_kind`
 * gives. No binding calls it: the committed bootstrap seed does, and the
 * seed's build fails without it. */
VADER_HOST_EXPORT
int64_t vader_stream_size(void* stream) {
    struct stat st;
    if (fstat(fileno((FILE*) stream), &st) != 0) return -1;
    return size_of_stat(&st);
}

/* What KIND of file the descriptor `fd` is open on, with `vader_path_kind`'s
 * ordinals; 0 when `fstat` fails. Here for the reason `vader_path_kind` gives. */
VADER_HOST_EXPORT
int32_t vader_fd_kind(int32_t fd) {
    struct stat st;
    if (fstat(fd, &st) != 0) return 0;
    return kind_of_mode(st.st_mode);
}

/* The size of the regular file the descriptor `fd` is open on, as
 * `size_of_stat` gives it, or -1 when `fstat` fails. Here for the reason
 * `vader_path_kind` gives. */
VADER_HOST_EXPORT
int64_t vader_fd_size(int32_t fd) {
    struct stat st;
    if (fstat(fd, &st) != 0) return -1;
    return size_of_stat(&st);
}

/* Reading a NAMED member of a C struct is the one step a Vader FFI call cannot
 * take for itself, and it is all this accessor does: `std/fs::read_dir` drives
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

/* What KIND of entry `ent` is, as `kind_of_mode` names it, from `d_type`
 * rather than a `stat`; 0 when the file system does not record it
 * (`DT_UNKNOWN`), and the caller then asks `vader_path_stat`. */
VADER_HOST_EXPORT
int32_t vader_dirent_kind(void* ent) {
    unsigned char type = ((const struct dirent*) ent)->d_type;
    if (type == DT_UNKNOWN) return 0;
    return kind_of_mode(DTTOIF(type));
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
