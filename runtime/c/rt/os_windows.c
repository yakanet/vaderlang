/* rt/os_windows.c: what the runtime asks of Windows.
 *
 * The set rt/os_posix.c describes: the `vader_os_*` functions rt/internal.h
 * lists, the accessors `system/windows` binds and the library loader of the
 * VM's FFI. */

#include "internal.h"

#include <windows.h>
#include <fcntl.h>   /* _O_BINARY */
#include <io.h>      /* _setmode, _fileno */

/* ---- memory -------------------------------------------------------------- */

static char* vader_os_reserve(size_t bytes) {
    return (char*) VirtualAlloc(NULL, bytes, MEM_RESERVE, PAGE_READWRITE);
}

/* A reserved page takes no write until it is committed. */
static int vader_os_commit(char* base, size_t bytes) {
    return VirtualAlloc(base, bytes, MEM_COMMIT, PAGE_READWRITE) != NULL;
}

/* The pages stay committed: a freed range keeps its memory until it is reused. */
static void vader_os_discard(char* base, char* end) {
    (void) base; (void) end;
}

static void vader_os_release(char* base, size_t bytes) {
    (void) bytes;
    VirtualFree(base, 0, MEM_RELEASE);
}

static int64_t vader_os_monotonic_ns(void) {
    LARGE_INTEGER freq;
    LARGE_INTEGER counter;
    if (!QueryPerformanceFrequency(&freq) || freq.QuadPart == 0) return 0;
    if (!QueryPerformanceCounter(&counter)) return 0;
    /* Whole seconds apart from the rest: the plain product overflows. */
    int64_t seconds = counter.QuadPart / freq.QuadPart;
    int64_t rest = counter.QuadPart % freq.QuadPart;
    return seconds * 1000000000 + rest * 1000000000 / freq.QuadPart;
}

/* `ns` in the milliseconds Win32 waits count, rounded up so a wait is never
 * shorter. */
static int64_t vader_os_ms_rounded_up(int64_t ns) {
    int64_t ms = ns / 1000000;
    if (ns % 1000000 != 0) ms += 1;
    return ms;
}

static void vader_os_sleep_ns(int64_t ns) {
    int64_t ms = vader_os_ms_rounded_up(ns);
    while (ms > 0) {
        DWORD slice = 0x7FFFFFFFu;
        if (ms < (int64_t) slice) slice = (DWORD) ms;
        Sleep(slice);
        ms -= (int64_t) slice;
    }
}

static size_t vader_os_physical_ram(void) {
    MEMORYSTATUSEX s;
    s.dwLength = sizeof(s);
    if (GlobalMemoryStatusEx(&s)) return (size_t) s.ullTotalPhys;
    return 0;
}

/* ---- what the OS reports ------------------------------------------------- */

/* The most events one wait takes; the rest wait for the next. */
#define VADER_OS_EVENTS 64

/* Every report arrives on one completion port: the end of a read of a pipe,
 * the end of a child, which the thread pool posts, and what stdin's reader
 * brings. */
static HANDLE g_os_port = NULL;

static HANDLE vader_os_port(void) {
    if (g_os_port == NULL) g_os_port = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 1);
    return g_os_port;
}

/* A watch the OS has not reported yet. A report names it by its `OVERLAPPED`,
 * which comes first. */
typedef struct vader_os_wait {
    OVERLAPPED            overlapped;
    int                   kind;
    int64_t               id;
    HANDLE                process;     /* a child's end: the copy of its handle waited on */
    HANDLE                registered;  /* a child's end: the thread pool's wait */
    struct vader_os_wait* next;
} vader_os_wait_t;

static vader_os_wait_t* g_os_waits = NULL;

/* What a read of no byte reads into. */
static char g_os_nothing;

/* `NtQueryInformationFile`, which ntdll exports and no import library carries,
 * and what it fills. */
typedef struct {
    PVOID     status;
    ULONG_PTR information;
} vader_io_status_t;
typedef LONG (NTAPI* vader_query_file_t)(HANDLE, vader_io_status_t*, PVOID, ULONG, int);
#define VADER_FILE_MODE_INFORMATION 16
/* `FILE_SYNCHRONOUS_IO_ALERT | FILE_SYNCHRONOUS_IO_NONALERT`: the mode of a
 * handle opened without `FILE_FLAG_OVERLAPPED`. */
#define VADER_FILE_SYNCHRONOUS_IO 0x30u

/* Whether `h` was opened for overlapped I/O. */
static int vader_os_is_overlapped(HANDLE h) {
    static vader_query_file_t query = NULL;
    if (query == NULL) {
        query = (vader_query_file_t) (void*) GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtQueryInformationFile");
    }
    if (query == NULL) return 0;
    vader_io_status_t io;
    ULONG mode = 0;
    if (query(h, &io, &mode, sizeof mode, VADER_FILE_MODE_INFORMATION) != 0) return 0;
    return (mode & VADER_FILE_SYNCHRONOUS_IO) == 0;
}

/* A read of no byte ends once the pipe holds data or has lost its writer, and
 * takes nothing. On a handle opened without overlapped I/O it would block, so
 * that one is refused; the port takes the others at their first watch, and
 * fails on the ones it holds already. One another port holds reports there,
 * never here. A read that succeeds at once is reported through the port all
 * the same; one that fails at once is not, so it is posted here. */
static int vader_os_watch_pipe(vader_os_wait_t* w) {
    HANDLE h = (HANDLE) (intptr_t) w->id;
    if (!vader_os_is_overlapped(h)) return 0;
    CreateIoCompletionPort(h, g_os_port, 0, 0);
    if (ReadFile(h, &g_os_nothing, 0, NULL, &w->overlapped)) return 1;
    if (GetLastError() == ERROR_IO_PENDING) return 1;
    return PostQueuedCompletionStatus(g_os_port, 0, 0, &w->overlapped);
}

static VOID CALLBACK vader_os_child_ended(PVOID w, BOOLEAN timed_out) {
    (void) timed_out;
    PostQueuedCompletionStatus(g_os_port, 0, 0, &((vader_os_wait_t*) w)->overlapped);
}

/* The thread pool waits on a copy of the handle: the library closes its own
 * once the child is reaped, and a handle must outlive the wait on it. */
static int vader_os_watch_child(vader_os_wait_t* w) {
    HANDLE self = GetCurrentProcess();
    if (!DuplicateHandle(self, (HANDLE) (intptr_t) w->id, self, &w->process, SYNCHRONIZE, FALSE, 0)) return 0;
    if (RegisterWaitForSingleObject(&w->registered, w->process, vader_os_child_ended, w,
                                    INFINITE, WT_EXECUTEONLYONCE)) {
        return 1;
    }
    CloseHandle(w->process);
    return 0;
}

/* ---- stdin --------------------------------------------------------------- */

/* A console and an anonymous pipe take no overlapped read, so a wait on stdin
 * runs on a thread of its own, which posts to the port once it is over. On a
 * pipe it reads no byte. On a console it reads ahead, since a console echoes
 * what is typed only while a read is under way, and the text waits here for
 * `vader_console_read`; what it holds is shared with that thread, under the
 * lock. */

enum { VADER_STDIN_OTHER = 0, VADER_STDIN_PIPE = 1, VADER_STDIN_CONSOLE = 2 };

/* Units one console read asks for at most. */
#define VADER_CONSOLE_READ_UNITS 256
/* Ctrl-Z, which ends the input when typed at the start of a line. */
#define VADER_CTRL_Z 0x1A

static int              g_os_stdin_ready = 0;
/* What stdin is, asked once: the program does not swap it. */
static int              g_os_stdin_kind = VADER_STDIN_OTHER;
static CRITICAL_SECTION g_os_stdin_lock;
static HANDLE           g_os_stdin_go;      /* the reader has a wait to make */
static HANDLE           g_os_stdin_done;    /* the reader made one */
static HANDLE           g_os_stdin_reader = NULL;
static int              g_os_stdin_busy = 0;
static OVERLAPPED       g_os_stdin_report;

/* What console reads brought past what was taken, as UTF-8. */
static char*   g_os_typed = NULL;
static size_t  g_os_typed_len = 0;
static size_t  g_os_typed_at = 0;
/* A high surrogate whose low half the next read brings, 0 when none. */
static wchar_t g_os_typed_high = 0;
/* A read reached the end of the input, or failed with `g_os_typed_error`, and
 * no read has said so yet. */
static int     g_os_typed_end = 0;
static int     g_os_typed_failed = 0;
static DWORD   g_os_typed_error = 0;

static void vader_os_stdin_init(void) {
    if (g_os_stdin_ready) return;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    if (GetConsoleMode(h, &mode)) {
        g_os_stdin_kind = VADER_STDIN_CONSOLE;
    } else if (GetFileType(h) == FILE_TYPE_PIPE) {
        g_os_stdin_kind = VADER_STDIN_PIPE;
    }
    InitializeCriticalSection(&g_os_stdin_lock);
    g_os_stdin_go = CreateEventA(NULL, FALSE, FALSE, NULL);
    g_os_stdin_done = CreateEventA(NULL, FALSE, FALSE, NULL);
    g_os_stdin_ready = 1;
}

/* A pipe that fails a peek has lost its writer: a read then reports the end. */
static int vader_os_pipe_readable(HANDLE h) {
    DWORD avail = 0;
    if (!PeekNamedPipe(h, NULL, 0, NULL, &avail, NULL)) return 1;
    return avail > 0;
}

/* Hold `n` units as the typed text, which none is left of. Under the lock. */
static void vader_console_keep(const wchar_t* units, int n) {
    int bytes = 0;
    if (n > 0) bytes = WideCharToMultiByte(CP_UTF8, 0, units, n, NULL, 0, NULL, NULL);
    g_os_typed_len = 0;
    g_os_typed_at = 0;
    if (bytes <= 0) return;
    char* grown = (char*) realloc(g_os_typed, (size_t) bytes);
    if (grown == NULL) vader_trap("stdin: out of memory");
    g_os_typed = grown;
    g_os_typed_len = (size_t) WideCharToMultiByte(CP_UTF8, 0, units, n, g_os_typed, bytes, NULL, NULL);
}

/* Read what the console holds into the typed text. The end of the input is a
 * read that brings nothing, or a Ctrl-Z at the start of a line, as `ReadFile`
 * reads it from a console. */
static void vader_console_fill(void) {
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    /* One unit in front for a high surrogate held back. */
    wchar_t units[1 + VADER_CONSOLE_READ_UNITS];
    DWORD got = 0;
    BOOL ok = ReadConsoleW(h, units + 1, VADER_CONSOLE_READ_UNITS, &got, NULL);
    DWORD error = GetLastError();
    DWORD mode = 0;
    int lines = GetConsoleMode(h, &mode) && (mode & ENABLE_LINE_INPUT) != 0;
    EnterCriticalSection(&g_os_stdin_lock);
    if (!ok) {
        g_os_typed_failed = 1;
        g_os_typed_error = error;
    } else if (got == 0 || (units[1] == VADER_CTRL_Z && lines)) {
        g_os_typed_end = 1;
    } else {
        wchar_t* text = units + 1;
        int n = (int) got;
        if (g_os_typed_high != 0) {
            units[0] = g_os_typed_high;
            text = units;
            n++;
            g_os_typed_high = 0;
        }
        /* A high surrogate makes a character only with the next read's first unit. */
        if (IS_HIGH_SURROGATE(text[n - 1])) {
            g_os_typed_high = text[n - 1];
            n--;
        }
        vader_console_keep(text, n);
    }
    LeaveCriticalSection(&g_os_stdin_lock);
}

static DWORD WINAPI vader_os_stdin_wait(LPVOID unused) {
    (void) unused;
    for (;;) {
        WaitForSingleObject(g_os_stdin_go, INFINITE);
        if (g_os_stdin_kind == VADER_STDIN_CONSOLE) {
            vader_console_fill();
        } else {
            DWORD got = 0;
            ReadFile(GetStdHandle(STD_INPUT_HANDLE), &g_os_nothing, 0, &got, NULL);
        }
        EnterCriticalSection(&g_os_stdin_lock);
        g_os_stdin_busy = 0;
        LeaveCriticalSection(&g_os_stdin_lock);
        SetEvent(g_os_stdin_done);
        PostQueuedCompletionStatus(g_os_port, 0, 0, &g_os_stdin_report);
    }
}

static int vader_os_stdin_reading(void) {
    EnterCriticalSection(&g_os_stdin_lock);
    int busy = g_os_stdin_busy;
    LeaveCriticalSection(&g_os_stdin_lock);
    return busy;
}

/* On a pipe, a read of the reader outlives a wait given up, and a peek would
 * wait behind it until the pipe holds data. That read ends once it does, and
 * only this thread starts one, so none starts before the peek. */
static int vader_os_stdin_readable(void) {
    vader_os_stdin_init();
    if (g_os_stdin_kind == VADER_STDIN_PIPE) {
        if (vader_os_stdin_reading()) return 0;
        return vader_os_pipe_readable(GetStdHandle(STD_INPUT_HANDLE));
    }
    if (g_os_stdin_kind != VADER_STDIN_CONSOLE) return 1;
    EnterCriticalSection(&g_os_stdin_lock);
    int ready = g_os_typed_at < g_os_typed_len || g_os_typed_end || g_os_typed_failed;
    LeaveCriticalSection(&g_os_stdin_lock);
    return ready;
}

/* Readable already, stdin is reported at once. Otherwise the reader waits,
 * unless a wait is under way, whose report wakes as well. */
static int vader_os_watch_stdin(void) {
    if (vader_os_stdin_readable()) return PostQueuedCompletionStatus(g_os_port, 0, 0, &g_os_stdin_report);
    if (g_os_stdin_reader == NULL) {
        g_os_stdin_reader = CreateThread(NULL, 64 * 1024, vader_os_stdin_wait, NULL,
                                         STACK_SIZE_PARAM_IS_A_RESERVATION, NULL);
        if (g_os_stdin_reader == NULL) return 0;
    }
    EnterCriticalSection(&g_os_stdin_lock);
    int start = !g_os_stdin_busy;
    g_os_stdin_busy = 1;
    LeaveCriticalSection(&g_os_stdin_lock);
    if (start) SetEvent(g_os_stdin_go);
    return 1;
}

/* ---- the reactor --------------------------------------------------------- */

/* A watch of `id` already under way reports for this one too. Stdin is
 * descriptor 0, any other id a handle. */
static int vader_os_watch(int kind, int64_t id) {
    if (vader_os_port() == NULL) return 0;
    if (kind == VADER_WATCH_READABLE && id == 0) return vader_os_watch_stdin();
    for (vader_os_wait_t* w = g_os_waits; w != NULL; w = w->next) {
        if (w->kind == kind && w->id == id) return 1;
    }
    vader_os_wait_t* w = (vader_os_wait_t*) calloc(1, sizeof(vader_os_wait_t));
    if (w == NULL) return 0;
    w->kind = kind;
    w->id = id;
    int armed;
    if (kind == VADER_WATCH_EXIT) {
        armed = vader_os_watch_child(w);
    } else {
        armed = vader_os_watch_pipe(w);
    }
    if (!armed) {
        free(w);
        return 0;
    }
    w->next = g_os_waits;
    g_os_waits = w;
    return 1;
}

/* A packet whose `OVERLAPPED` is no watch's comes from a read other code
 * started on a handle the port knows: it reports nothing. */
static void vader_os_report(OVERLAPPED* overlapped) {
    if (overlapped == &g_os_stdin_report) {
        vader_scheduler_on_event(VADER_WATCH_READABLE, 0);
        return;
    }
    vader_os_wait_t** link = &g_os_waits;
    while (*link != NULL && &(*link)->overlapped != overlapped) link = &(*link)->next;
    vader_os_wait_t* w = *link;
    if (w == NULL) return;
    *link = w->next;
    if (w->kind == VADER_WATCH_EXIT) {
        UnregisterWaitEx(w->registered, INVALID_HANDLE_VALUE);
        CloseHandle(w->process);
    }
    int kind = w->kind;
    int64_t id = w->id;
    free(w);
    vader_scheduler_on_event(kind, id);
}

static void vader_os_wait_events(int64_t timeout_ns) {
    DWORD timeout_ms = INFINITE;
    if (timeout_ns >= 0) {
        int64_t ms = vader_os_ms_rounded_up(timeout_ns);
        timeout_ms = INFINITE - 1u;
        if (ms < (int64_t) timeout_ms) timeout_ms = (DWORD) ms;
    }
    OVERLAPPED_ENTRY events[VADER_OS_EVENTS];
    ULONG got = 0;
    if (!GetQueuedCompletionStatusEx(g_os_port, events, VADER_OS_EVENTS, &got, timeout_ms, FALSE)) return;
    for (ULONG i = 0; i < got; i++) vader_os_report(events[i].lpOverlapped);
}

static int vader_os_readable_now(int64_t fd) {
    if (fd == 0) return vader_os_stdin_readable();
    return vader_os_pipe_readable((HANDLE) (intptr_t) fd);
}

/* ---- stack --------------------------------------------------------------- */

static char* vader_os_stack_base(void) {
    ULONG_PTR lo = 0, hi = 0;
    GetCurrentThreadStackLimits(&lo, &hi);
    return (char*) hi;
}

/* ---- standard streams ---------------------------------------------------- */

/* The CRT opens the standard streams in text mode, which translates `\r\n` <->
 * `\n` and breaks any length-prefixed binary transport (LSP, MCP, custom RPC)
 * AND every `dump` / `build` / `fmt` stdout (LF on disk, CRLF on the wire).
 * stderr matters too: the VM's runtime-error / panic messages are diffed
 * byte-for-byte by the snapshot suite, and text-mode `\n` -> `\r\n` on stderr
 * makes every such line mismatch by an invisible trailing `\r`. */
static void vader_os_ensure_stdio_binary(void) {
    _setmode(_fileno(stdin),  _O_BINARY);
    _setmode(_fileno(stdout), _O_BINARY);
    _setmode(_fileno(stderr), _O_BINARY);
}

/* Write UTF-8 `text` to the console `h` as UTF-16, which it renders whatever its
 * code page; 0, with nothing written, when the conversion cannot be made. A
 * UTF-8 text never takes more UTF-16 units than it has bytes. */
static int vader_write_console(HANDLE h, const char* text, size_t len) {
    wchar_t* wide = (wchar_t*) malloc(len * sizeof(wchar_t));
    if (wide == NULL) return 0;
    int units = MultiByteToWideChar(CP_UTF8, 0, text, (int) len, wide, (int) len);
    if (units > 0) WriteConsoleW(h, wide, (DWORD) units, NULL, NULL);
    free(wide);
    return units > 0;
}

/* The report for a `detail` beyond ASCII on a console, whose code page, the OEM
 * one by default, would garble it: the line goes out as UTF-16, as `std/io`
 * writes `eprint`. 0, with nothing written, when that does not apply or cannot be
 * done. */
static int vader_report_fatal_console(const char* what, const char* detail, size_t detail_len) {
    DWORD mode;
    if (vader_atom_ascii_flag(detail, detail_len) != 0) return 0;
    HANDLE h = GetStdHandle(STD_ERROR_HANDLE);
    if (!GetConsoleMode(h, &mode)) return 0;
    size_t what_len = strlen(what);
    size_t len = 7 + what_len + detail_len + 1;
    char* line = (char*) malloc(len);
    if (line == NULL) return 0;
    memcpy(line, "vader: ", 7);
    memcpy(line + 7, what, what_len);
    memcpy(line + 7 + what_len, detail, detail_len);
    line[len - 1] = '\n';
    int written = vader_write_console(h, line, len);
    free(line);
    return written;
}

static void vader_os_report_fatal(const char* what, const char* detail, size_t detail_len) {
    if (vader_report_fatal_console(what, detail, detail_len)) return;
    fprintf(stderr, "vader: %s%.*s\n", what, (int) detail_len, detail);
}

/* ---- accessors ----------------------------------------------------------- */

/* Reading a NAMED member of a C struct is the one step a Vader FFI call cannot
 * take for itself, and it is all this accessor does: `std/io::read_dir` drives
 * `FindFirstFileW` / `FindNextFileW` from Vader and calls it for the name.
 *
 * It has to be a CALL and not a struct read: the interpreter has no C layout,
 * but it can call a C function and resolve one by name out of its own process.
 * `VADER_HOST_EXPORT` is what keeps that possible, see the macro.
 *
 * It carries the UTF-16 conversion as well: `cFileName` is `WCHAR[MAX_PATH]`
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

/* Up to `max` bytes of what was typed at the console, as UTF-8: what an earlier
 * read brought first, a read of the console otherwise, which waits for the
 * reader when it is reading. 0 at the end of the input, -1 on a failure, whose
 * error `GetLastError` then gives. */
VADER_HOST_EXPORT
int64_t vader_console_read(void* buf, int64_t max) {
    vader_os_stdin_init();
    EnterCriticalSection(&g_os_stdin_lock);
    for (;;) {
        if (g_os_typed_at < g_os_typed_len) {
            size_t n = g_os_typed_len - g_os_typed_at;
            if ((size_t) max < n) n = (size_t) max;
            memcpy(buf, g_os_typed + g_os_typed_at, n);
            g_os_typed_at += n;
            LeaveCriticalSection(&g_os_stdin_lock);
            return (int64_t) n;
        }
        if (g_os_typed_end) {
            g_os_typed_end = 0;
            LeaveCriticalSection(&g_os_stdin_lock);
            return 0;
        }
        if (g_os_typed_failed) {
            g_os_typed_failed = 0;
            LeaveCriticalSection(&g_os_stdin_lock);
            SetLastError(g_os_typed_error);
            return -1;
        }
        int busy = g_os_stdin_busy;
        LeaveCriticalSection(&g_os_stdin_lock);
        if (busy) {
            WaitForSingleObject(g_os_stdin_done, INFINITE);
        } else {
            vader_console_fill();
        }
        EnterCriticalSection(&g_os_stdin_lock);
    }
}

/* Wait for the reader's read of a stdin pipe to end, no longer than
 * `timeout_ms`, with no deadline when it is negative. That read takes no byte,
 * outlives a wait given up, and every peek of the pipe waits behind it; it ends
 * once the pipe holds data or has lost its writer, so stdin then reads. 0 at
 * the deadline with the read still under way, 1 otherwise, at once on a
 * console or with no read under way. The read is not cancelled: ADR 0130. */
VADER_HOST_EXPORT
int32_t vader_stdin_await_reader(int32_t timeout_ms) {
    vader_os_stdin_init();
    if (g_os_stdin_kind != VADER_STDIN_PIPE) return 1;
    int64_t deadline = 0;
    if (timeout_ms >= 0) deadline = vader_os_monotonic_ns() + (int64_t) timeout_ms * 1000000;
    while (vader_os_stdin_reading()) {
        DWORD wait = INFINITE;
        if (timeout_ms >= 0) {
            int64_t left = deadline - vader_os_monotonic_ns();
            if (left <= 0) return 0;
            wait = (DWORD) vader_os_ms_rounded_up(left);
        }
        /* An earlier read may have left the event set: the loop asks again. */
        WaitForSingleObject(g_os_stdin_done, wait);
    }
    return 1;
}

/* What a child's pipe holds before the child waits for a read. */
#define VADER_OS_PIPE_BYTES (64u * 1024u)

/* A pipe a child writes into and the scheduler can watch: the read end takes
 * overlapped reads, and the write end is inheritable. An anonymous pipe takes
 * no overlapped read, so this one is named, after the process and a count. 0
 * when it cannot be made. */
VADER_HOST_EXPORT
int32_t vader_overlapped_pipe(void* read_end, void* write_end) {
    static volatile LONG count = 0;
    char name[64];
    snprintf(name, sizeof name, "\\\\.\\pipe\\vader-%lu-%ld",
             (unsigned long) GetCurrentProcessId(), (long) InterlockedIncrement(&count));
    HANDLE r = CreateNamedPipeA(name, PIPE_ACCESS_INBOUND | FILE_FLAG_OVERLAPPED | FILE_FLAG_FIRST_PIPE_INSTANCE,
                                PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT | PIPE_REJECT_REMOTE_CLIENTS,
                                1, 0, VADER_OS_PIPE_BYTES, 0, NULL);
    if (r == INVALID_HANDLE_VALUE) return 0;
    SECURITY_ATTRIBUTES inherited = { sizeof inherited, NULL, TRUE };
    HANDLE w = CreateFileA(name, GENERIC_WRITE | FILE_READ_ATTRIBUTES, 0, &inherited,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (w == INVALID_HANDLE_VALUE) {
        CloseHandle(r);
        return 0;
    }
    ((HANDLE*) read_end)[0] = r;
    ((HANDLE*) write_end)[0] = w;
    return 1;
}

/* ---- library loader ------------------------------------------------------ */

void* vader_ffi_open_path(const char* path) {
    /* Wide, so a path outside the ANSI code page still opens. */
    wchar_t wide[1024];
    int     n = MultiByteToWideChar(CP_UTF8, 0, path, -1, wide, (int) (sizeof wide / sizeof wide[0]));
    if (n == 0) { return NULL; }
    return (void*) LoadLibraryW(wide);
}

void* vader_ffi_open(const char* name) {
    if (name == NULL || name[0] == '\0') {
        /* The C runtime, which is where a libc-shaped symbol lives. NOT the
         * process handle: an EXE exports only its `VADER_HOST_EXPORT`ed
         * symbols, so `GetProcAddress` on it finds no libc one. POSIX only gets
         * away with `dlopen(NULL)` because that exposes the whole global symbol
         * scope. */
        HMODULE h = GetModuleHandleA("ucrtbase.dll");
        if (h == NULL) { h = GetModuleHandleA("msvcrt.dll"); }
        if (h == NULL) { h = GetModuleHandleW(NULL); }
        return (void*) h;
    }
    char buf[256];
    int  n = snprintf(buf, sizeof buf, "%s.dll", name);
    if (n < 0 || (size_t) n >= sizeof buf) { return NULL; }
    return (void*) LoadLibraryA(buf);
}

void* vader_ffi_symbol(void* lib, const char* symbol) {
    if (lib == NULL || symbol == NULL) { return NULL; }
    void* p = (void*) GetProcAddress((HMODULE) lib, symbol);
    if (p == NULL && symbol[0] != '_') {
        /* The CRT exports its POSIX-shaped entry points with a leading
         * underscore: `write` is `_write`, `getpid` is `_getpid`. The
         * unprefixed spelling that the LINKER accepts is a compile-time
         * alias, absent from the export table. */
        char buf[128];
        int  n = snprintf(buf, sizeof buf, "_%s", symbol);
        if (n > 0 && (size_t) n < sizeof buf) {
            p = (void*) GetProcAddress((HMODULE) lib, buf);
        }
    }
    if (p == NULL) {
        /* Then the EXE's own export table. POSIX gets this for free
         * (`dlopen(NULL)` exposes the whole global scope, so a runtime symbol
         * like `vader_dirent_name` resolves there) while on Windows the CRT
         * handle above knows nothing of the running program. Anything the
         * interpreter must reach in ITSELF is `VADER_HOST_EXPORT`ed, which
         * is what puts it in this table. */
        p = (void*) GetProcAddress(GetModuleHandleW(NULL), symbol);
    }
    return p;
}
