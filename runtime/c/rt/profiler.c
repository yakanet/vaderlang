/* rt/profiler.c: the compiler's per-pass profiler (`VADER_PROFILE`), as the
 * committed seeds call it. The compiler built from the tree runs the one in
 * `vader/support/profile`. */

#include "internal.h"

/* Per-pass self-compile profiler, gated by $VADER_PROFILE. The compiler
 * brackets each pass with vader_prof_begin/end(phase_id); we accumulate wall
 * time, peak-RSS growth, and GC churn per phase, then dump a table to stderr at
 * exit. Phase ids index g_prof_names[], in the order of the seeds' `ProfPhase`. */

/* Set via `VADER_PROFILE=1`, read lazily by `vader_prof_enabled`. -1 unknown,
 * 0 off, 1 on. */
static int g_prof_enabled = -1;

/* The profiler's own clock. Internal on purpose: `std/time` reads the OS
 * clocks itself through `@target` + `@extern`, so nothing outside this file
 * needs it and it stays off the FFI surface. */
static vader_i64_t prof_monotonic_ns(void) {
#ifdef _WIN32
    static LARGE_INTEGER freq = { .QuadPart = 0 };
    if (freq.QuadPart == 0) {
        QueryPerformanceFrequency(&freq);
    }
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    /* Avoid `now * 1_000_000_000` overflow by splitting via the
     * frequency divisor: preserves resolution to the granularity
     * of the underlying counter. */
    vader_i64_t whole_sec_ns = (vader_i64_t) (now.QuadPart / freq.QuadPart) * 1000000000;
    vader_i64_t remainder = (vader_i64_t) (now.QuadPart % freq.QuadPart);
    vader_i64_t sub_sec_ns = (remainder * 1000000000) / freq.QuadPart;
    return whole_sec_ns + sub_sec_ns;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (vader_i64_t) ts.tv_sec * 1000000000 + (vader_i64_t) ts.tv_nsec;
#endif
}

#define VADER_PROF_MAX_PHASES 16

/* Phase names: index = phase id. */
static const char* g_prof_names[VADER_PROF_MAX_PHASES] = {
    "load",       /* 0  */
    "typecheck",  /* 1  */
    "comptime",   /* 2  */
    "lower",      /* 3  */
    "prune",      /* 4  */
    "cfg-build",  /* 5  */
    "cfg-dce",    /* 6  */
    "escape",     /* 7  */
    "bytecode",   /* 8  */
    "c-emit",     /* 9  */
    "value-ret",  /* 10 */
    "ranges",     /* 11 */
    NULL, NULL, NULL, NULL,
};

static int       g_prof_atexit_armed = 0;
/* Accumulated per phase. */
static int64_t   g_prof_wall_ns[VADER_PROF_MAX_PHASES];
static int64_t   g_prof_rss_growth[VADER_PROF_MAX_PHASES]; /* peak-RSS delta, bytes */
static int64_t   g_prof_copied[VADER_PROF_MAX_PHASES];     /* GC bytes copied */
static int64_t   g_prof_alloc[VADER_PROF_MAX_PHASES];      /* bytes requested via gc_alloc */
static int64_t   g_prof_alloc_count[VADER_PROF_MAX_PHASES];/* gc_alloc calls */
static int64_t   g_prof_coll[VADER_PROF_MAX_PHASES];       /* GC cycles */
static int64_t   g_prof_calls[VADER_PROF_MAX_PHASES];      /* times entered */
/* In-flight snapshot: passes are sequential, so one slot suffices.
 * g_prof_current holds the phase id currently bracketed (-1 = idle) so a
 * nested prof_begin trips a loud warning rather than silently misattributing. */
static int64_t   g_prof_t0, g_prof_rss0, g_prof_copied0, g_prof_coll0;
static int64_t   g_prof_alloc0, g_prof_alloc_count0;
static int       g_prof_current = -1;

/* All query helpers are internal: the profiler is the only consumer. */

/* Peak resident set, bytes (getrusage). Process-wide, monotonic. */
static int64_t vader_prof_max_rss_bytes(void) {
#if defined(_WIN32)
    return 0;
#else
    struct rusage ru;
    if (getrusage(RUSAGE_SELF, &ru) != 0) return 0;
#  if defined(__APPLE__)
    return (int64_t) ru.ru_maxrss;          /* bytes on macOS */
#  else
    return (int64_t) ru.ru_maxrss * 1024;   /* kilobytes on Linux/BSD */
#  endif
#endif
}

/* Current resident set, bytes: best effort, falls back to the peak. */
static int64_t vader_prof_rss_now_bytes(void) {
#if defined(__APPLE__)
    mach_task_basic_info_data_t info;
    mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO,
                  (task_info_t) &info, &count) == KERN_SUCCESS) {
        return (int64_t) info.resident_size;
    }
    return vader_prof_max_rss_bytes();
#elif defined(__linux__)
    /* /proc/self/statm: size resident ... (in pages). */
    FILE* f = fopen("/proc/self/statm", "r");
    if (f) {
        long pages_total = 0, pages_res = 0;
        int got = fscanf(f, "%ld %ld", &pages_total, &pages_res);
        fclose(f);
        if (got == 2) return (int64_t) pages_res * (int64_t) sysconf(_SC_PAGESIZE);
    }
    return vader_prof_max_rss_bytes();
#else
    return vader_prof_max_rss_bytes();
#endif
}

/* Old-gen live bytes plus the young allocation: a live set only right after
 * a major, see `bytes_used` in vader.h. */
static int64_t vader_prof_bytes_used(void) { return (int64_t) vader_gc_get_stats().bytes_used; }

static int32_t vader_prof_enabled(void) {
    if (g_prof_enabled < 0) {
        g_prof_enabled = vader_gc_env_bool("VADER_PROFILE");
        if (g_prof_enabled) vader_gc_count_allocations();
    }
    return (int32_t) g_prof_enabled;
}

void vader_prof_begin(int32_t phase_id) {
    if (!vader_prof_enabled()) return;
    if (phase_id < 0 || phase_id >= VADER_PROF_MAX_PHASES) return;
    if (!g_prof_atexit_armed) { atexit(vader_prof_dump); g_prof_atexit_armed = 1; }
    if (g_prof_current >= 0) {
        fprintf(stderr, "[VADER_PROFILE] nested prof bracket (phase %d inside %d), "
                        "timings will misattribute\n", phase_id, g_prof_current);
    }
    g_prof_current = phase_id;
    /* One stats read serves every GC baseline. */
    vader_gc_stats_t s = vader_gc_get_stats();
    g_prof_rss0         = vader_prof_max_rss_bytes();
    g_prof_copied0      = (int64_t) s.total_copied;
    g_prof_coll0        = (int64_t) s.total_collections;
    g_prof_alloc0       = (int64_t) s.total_alloc_bytes;
    g_prof_alloc_count0 = (int64_t) s.total_alloc_count;
    g_prof_t0           = prof_monotonic_ns();   /* start the clock last */
}

void vader_prof_end(int32_t phase_id) {
    if (!vader_prof_enabled()) return;
    if (phase_id < 0 || phase_id >= VADER_PROF_MAX_PHASES) return;
    /* The baselines are a SINGLE global set, so only the phase `begin` opened can
     * be closed against them. An unpaired `end` (or the outer `end` of a nested
     * pair, which `begin` warns about and could otherwise do nothing about)
     * would charge its phase the whole span since some unrelated `begin`, and
     * that number reads like a measurement. */
    if (phase_id != g_prof_current) {
        fprintf(stderr, "[VADER_PROFILE] unmatched prof end (phase %d, open is %d), "
                        "sample dropped\n", phase_id, g_prof_current);
        return;
    }
    int64_t t1 = prof_monotonic_ns();       /* stop the clock first */
    vader_gc_stats_t s = vader_gc_get_stats();
    g_prof_wall_ns[phase_id]    += t1 - g_prof_t0;
    g_prof_rss_growth[phase_id] += vader_prof_max_rss_bytes() - g_prof_rss0;
    g_prof_copied[phase_id]      += (int64_t) s.total_copied - g_prof_copied0;
    g_prof_alloc[phase_id]       += (int64_t) s.total_alloc_bytes - g_prof_alloc0;
    g_prof_alloc_count[phase_id] += (int64_t) s.total_alloc_count - g_prof_alloc_count0;
    g_prof_coll[phase_id]        += (int64_t) s.total_collections - g_prof_coll0;
    g_prof_calls[phase_id]       += 1;
    g_prof_current = -1;
}

static int g_prof_dumped = 0;

void vader_prof_dump(void) {
    if (!vader_prof_enabled()) return;
    if (g_prof_dumped) return;   /* explicit call + atexit fallback must not double-print */
    g_prof_dumped = 1;
    int64_t total_wall = 0, total_copied = 0, total_coll = 0;
    int64_t total_alloc = 0, total_alloc_count = 0;
    for (int i = 0; i < VADER_PROF_MAX_PHASES; i++) {
        total_wall        += g_prof_wall_ns[i];
        total_copied      += g_prof_copied[i];
        total_alloc       += g_prof_alloc[i];
        total_alloc_count += g_prof_alloc_count[i];
        total_coll        += g_prof_coll[i];
    }
    if (total_wall == 0) return; /* nothing was bracketed */
    fprintf(stderr,
        "\n[VADER_PROFILE] per-pass self-compile profile\n"
        "  %-11s %9s %6s %10s %10s %10s %8s %6s %5s\n",
        "PASS", "WALL", "%WALL", "RSS-GROWTH", "GC-COPIED", "ALLOC'D", "OBJS/M", "CYCLE", "CALLS");
    for (int i = 0; i < VADER_PROF_MAX_PHASES; i++) {
        if (g_prof_calls[i] == 0) continue;
        double ms   = (double) g_prof_wall_ns[i] / 1.0e6;
        double pct  = total_wall > 0 ? 100.0 * (double) g_prof_wall_ns[i] / (double) total_wall : 0.0;
        double rss  = (double) g_prof_rss_growth[i] / (1024.0 * 1024.0);
        double cop  = (double) g_prof_copied[i] / (1024.0 * 1024.0);
        double alc  = (double) g_prof_alloc[i] / (1024.0 * 1024.0);
        double objs = (double) g_prof_alloc_count[i] / 1.0e6;
        fprintf(stderr,
            "  %-11s %7.1fms %5.1f%% %+9.1fM %9.1fM %9.1fM %7.2fM %6lld %5lld\n",
            g_prof_names[i] ? g_prof_names[i] : "?",
            ms, pct, rss, cop, alc, objs,
            (long long) g_prof_coll[i], (long long) g_prof_calls[i]);
    }
    fprintf(stderr,
        "  %-11s %7.1fms %5.1f%% %+9.1fM %9.1fM %9.1fM %7.2fM %6lld\n",
        "TOTAL", (double) total_wall / 1.0e6, 100.0,
        (double) vader_prof_max_rss_bytes() / (1024.0 * 1024.0),
        (double) total_copied / (1024.0 * 1024.0),
        (double) total_alloc / (1024.0 * 1024.0),
        (double) total_alloc_count / 1.0e6,
        (long long) total_coll);
    fprintf(stderr,
        "  peak-RSS %.1f MB | RSS-now %.1f MB | live-set %.1f MB\n",
        (double) vader_prof_max_rss_bytes() / (1024.0 * 1024.0),
        (double) vader_prof_rss_now_bytes() / (1024.0 * 1024.0),
        (double) vader_prof_bytes_used() / (1024.0 * 1024.0));
}
