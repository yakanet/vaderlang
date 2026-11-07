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

static void vader_os_sleep_ns(int64_t ns) {
    /* `Sleep` counts milliseconds: round up, so the wait is never shorter. */
    int64_t ms = ns / 1000000;
    if (ns % 1000000 != 0) ms += 1;
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
