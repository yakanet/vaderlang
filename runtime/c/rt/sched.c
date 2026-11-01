/* rt/sched.c: the cooperative async scheduler. */

#include "internal.h"

/* See vader.h. A virtual `now` (ms, from 0) + a min-heap of pending wake
 * deadlines. `park` waits for the nearest (real time, unless virtual), advances
 * `now` to it and drops every timer then due. Single-threaded: no locking. */
static int64_t  g_sched_now = 0;
static int64_t* g_sched_heap = NULL;
static size_t   g_sched_len = 0;
static size_t   g_sched_cap = 0;
static int      g_sched_virtual = -1;   /* -1 = probe env on first park */

static int vader_sched_is_virtual(void) {
    if (g_sched_virtual < 0) {
        g_sched_virtual = getenv("VADER_ASYNC_VIRTUAL_CLOCK") ? 1 : 0;
    }
    return g_sched_virtual;
}

vader_i64_t vader_sched_now(void) { return g_sched_now; }

void vader_sched_arm(vader_i64_t deadline) {
    if (g_sched_len == g_sched_cap) {
        size_t cap = g_sched_cap ? g_sched_cap * 2 : 8;
        /* Through a temporary: `realloc` returning NULL leaves the old block
         * allocated, and assigning straight into `g_sched_heap` would both leak
         * it and NULL the only handle the sift below writes through. */
        int64_t* grown = (int64_t*) realloc(g_sched_heap, cap * sizeof(int64_t));
        if (grown == NULL) vader_trap("vader_sched_arm: realloc failed");
        g_sched_heap = grown;
        g_sched_cap  = cap;
    }
    size_t i = g_sched_len++;
    g_sched_heap[i] = deadline;
    while (i > 0) {                        /* sift up */
        size_t parent = (i - 1) / 2;
        if (g_sched_heap[parent] <= g_sched_heap[i]) { break; }
        int64_t t = g_sched_heap[parent]; g_sched_heap[parent] = g_sched_heap[i]; g_sched_heap[i] = t;
        i = parent;
    }
}

static void vader_sched_pop(void) {
    g_sched_heap[0] = g_sched_heap[--g_sched_len];
    size_t i = 0;                          /* sift down */
    for (;;) {
        size_t l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < g_sched_len && g_sched_heap[l] < g_sched_heap[smallest]) { smallest = l; }
        if (r < g_sched_len && g_sched_heap[r] < g_sched_heap[smallest]) { smallest = r; }
        if (smallest == i) { break; }
        int64_t t = g_sched_heap[i]; g_sched_heap[i] = g_sched_heap[smallest]; g_sched_heap[smallest] = t;
        i = smallest;
    }
}

/* A timer already due carries nothing: the program re-drives every task after
 * a park, so each of them sees the clock it waited for. */
static void vader_sched_drop_due(void) {
    while (g_sched_len > 0 && g_sched_heap[0] <= g_sched_now) { vader_sched_pop(); }
}

vader_i32_t vader_sched_park(void) {
    vader_sched_drop_due();
    if (g_sched_len == 0) { return 1; }    /* deadlock: nothing pending */
    int64_t deadline = g_sched_heap[0];
    if (!vader_sched_is_virtual()) {
        int64_t delta = deadline - g_sched_now;
#ifdef _WIN32
        Sleep((DWORD) delta);
#else
        struct timespec ts;
        ts.tv_sec = (time_t) (delta / 1000);
        ts.tv_nsec = (long) ((delta % 1000) * 1000000);
        nanosleep(&ts, NULL);
#endif
    }
    g_sched_now = deadline;
    vader_sched_drop_due();
    return 0;
}
