/* rt/defer_traps.c: the defer stack, and the traps that unwind it.
 *
 * `defer` pushes a closure that the end of its scope pops and runs. A trap or
 * a panic reports, runs every pending defer, then aborts. */

#include "internal.h"

/* Global LIFO of pending `defer` closures. The C-emit appends to it via
 * `vader_defer_push` at every `defer X` site, then drains the last N
 * entries via `vader_defer_pop_exec` at each normal exit (return /
 * break / continue / block fall-through).
 *
 * GC roots: every entry's `payload.obj` is a `vader_fn_t*` whose env
 * pointer captures heap-promoted cells. The GC's frame-walking scan
 * also walks the defer stack so captures stay live between push and
 * exec.
 *
 * Panic-unwind : a trap runs the pending defers before aborting. No
 * setjmp/longjmp is needed: `g_defer_stack` already holds exactly the
 * pending defers of the live call chain (pushed on scope entry, popped on
 * structured exit), so `vader_trap` / `vader_panic` drain the whole stack
 * LIFO, which is precisely unwind order. `g_unwinding` guards against a
 * defer that itself traps (double-panic) : the second trap aborts at once
 * without re-draining. */
static vader_box_t* g_defer_stack = NULL;
static size_t       g_defer_len   = 0;
static size_t       g_defer_cap   = 0;
static int          g_unwinding   = 0;

void vader_defer_push(vader_box_t closure) {
    if (g_defer_len == g_defer_cap) {
        size_t new_cap = g_defer_cap == 0 ? 16u : g_defer_cap * 2u;
        vader_box_t* new_stack = (vader_box_t*) realloc(g_defer_stack, new_cap * sizeof(vader_box_t));
        if (new_stack == NULL) vader_trap("vader_defer_push: realloc failed");
        g_defer_stack = new_stack;
        g_defer_cap   = new_cap;
    }
    g_defer_stack[g_defer_len++] = closure;
}

/* Pop and run the top defer thunk. The lifted fn signature is `fn(env) ->
 * void` ; we cast through a function pointer with the matching ABI
 * (`vader_fn_erased_sig_0_t` from the per-module emit lines up: it returns
 * a `vader_box_t`, but the thunk's wrapper returns a `null`-tagged box we
 * discard). Caller guarantees `g_defer_len > 0`. */
static void vader_run_one_defer(void) {
    vader_box_t c = g_defer_stack[--g_defer_len];
    vader_fn_t* fn = (vader_fn_t*) c.payload.obj;
    ((vader_box_t (*)(void*)) fn->code)(fn->env);
}

void vader_defer_pop_exec(uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        if (g_defer_len == 0u) vader_trap("vader_defer_pop_exec: stack underflow");
        vader_run_one_defer();
    }
}



/* ----------------------------------------------------------------- traps */

#if defined(_WIN32)
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

/* `vader_report_fatal` for a `detail` beyond ASCII on a console, whose code page,
 * the OEM one by default, would garble it: the line goes out as UTF-16, as
 * `std/io` writes `eprint`. 0, with nothing written, when that does not apply or
 * cannot be done, the caller then printing the bytes. */
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
#endif

/* `vader: <what><detail>` on its own line, on stderr. */
static void vader_report_fatal(const char* what, const char* detail, size_t detail_len) {
#if defined(_WIN32)
    if (vader_report_fatal_console(what, detail, detail_len)) return;
#endif
    fprintf(stderr, "vader: %s%.*s\n", what, (int) detail_len, detail);
}

void vader_unreachable(const char* where) {
    vader_report_fatal("reached unreachable at ", where, strlen(where));
    abort();
}

/* Drain every pending defer LIFO as a panic unwinds the live call chain.
 * The generated code balances push/pop on every structured exit, so the
 * stack only ever holds the frames between main and the trap site. */
static void vader_run_pending_defers(void) {
    while (g_defer_len > 0u) vader_run_one_defer();
}

void vader_trap(const char* msg) {
    vader_report_fatal("trap: ", msg, strlen(msg));
    if (!g_unwinding) { g_unwinding = 1; vader_run_pending_defers(); }
    abort();
}

void vader_panic(vader_string_t msg) {
    vader_report_fatal("panic: ", vader_atom_data(msg), (size_t) vader_atom_len(msg));
    if (!g_unwinding) { g_unwinding = 1; vader_run_pending_defers(); }
    abort();
}
