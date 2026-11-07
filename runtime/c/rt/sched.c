/* rt/sched.c: the scheduler of virtual threads: which thread runs, the ones
 * that sleep, and the ones cancelled.
 *
 * A thread runs until it parks, sleeps or ends; the scheduler then runs the
 * ready threads in the order they became ready. With none ready, it waits for
 * the nearest sleep to end, and gives the stacks freed meanwhile back to the
 * OS; with no sleep either, every thread waits on another and the program
 * stops. The scheduler runs on a thread of its own (rt/vthreads.c), which runs
 * no Vader code.
 *
 * A cancelled thread unwinds at its next run: it runs its pending defers on
 * its own stack, then ends. A defer may park meanwhile, and the cancellation
 * goes on where it stood.
 *
 * Under `VADER_ASYNC_VIRTUAL_CLOCK`, the clock counts the sleeps alone: it
 * jumps to the end of the nearest one instead of waiting for it. */

#include "internal.h"

/* What the scheduler keeps of a thread, at the thread's index. */
typedef struct {
    uint64_t number;        /* how a report names it; 0 for the main thread */
    uint32_t sleep;         /* a timer armed under another value wakes nothing */
    uint8_t  queued;        /* in the ready queue */
    uint8_t  cancelled;
    uint8_t  unwinding;     /* running the defers of its cancellation */
} vader_sched_slot_t;

typedef struct {
    int64_t  deadline;
    int64_t  thread;
    uint32_t sleep;
} vader_sched_timer_t;

static int      g_sched_started = 0;
static int      g_sched_clock_read = 0;
static int      g_sched_virtual_clock = 0;
static int64_t  g_sched_virtual_now = 0;
static uint64_t g_sched_numbered = 0;
/* `main` returned and waits for the threads it cancelled. */
static int      g_sched_exiting = 0;
/* Some thread was still running, not cancelled, when `main` returned. */
static int      g_sched_left_running = 0;

static vader_sched_slot_t* g_sched_slots = NULL;
static size_t g_sched_slot_cap = 0;

/* The ready threads, a ring of handles whose capacity is a power of two. A
 * thread that ended while queued leaves its handle behind, skipped. */
static int64_t* g_sched_ready = NULL;
static size_t g_sched_ready_head = 0;
static size_t g_sched_ready_len = 0;
static size_t g_sched_ready_cap = 0;

/* The sleeps, a min-heap on the deadline. */
static vader_sched_timer_t* g_sched_timers = NULL;
static size_t g_sched_timer_len = 0;
static size_t g_sched_timer_cap = 0;

/* ---- the slots ------------------------------------------------------------- */

/* The slot of the live thread `thread`. */
static vader_sched_slot_t* vader_sched_slot_of(int64_t thread) {
    return &g_sched_slots[vader_vt_index(thread)];
}

/* Give `thread` a fresh slot, numbered `number`. */
static void vader_sched_fresh_slot(int64_t thread, uint64_t number) {
    size_t index = vader_vt_index(thread);
    if (index >= g_sched_slot_cap) {
        size_t cap = 64u;
        while (cap <= index) cap *= 2u;
        vader_sched_slot_t* grown = (vader_sched_slot_t*) realloc(g_sched_slots, cap * sizeof(vader_sched_slot_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        memset(grown + g_sched_slot_cap, 0, (cap - g_sched_slot_cap) * sizeof(vader_sched_slot_t));
        g_sched_slots = grown;
        g_sched_slot_cap = cap;
    }
    vader_sched_slot_t* s = &g_sched_slots[index];
    memset(s, 0, sizeof(vader_sched_slot_t));
    s->number = number;
}

/* ---- the ready queue ------------------------------------------------------- */

static void vader_sched_grow_ready(void) {
    size_t cap = 64u;
    if (g_sched_ready_cap != 0u) cap = g_sched_ready_cap * 2u;
    int64_t* grown = (int64_t*) malloc(cap * sizeof(int64_t));
    if (grown == NULL) vader_trap("virtual threads: out of memory");
    for (size_t i = 0; i < g_sched_ready_len; i++) {
        grown[i] = g_sched_ready[(g_sched_ready_head + i) & (g_sched_ready_cap - 1u)];
    }
    free(g_sched_ready);
    g_sched_ready = grown;
    g_sched_ready_head = 0;
    g_sched_ready_cap = cap;
}

/* Make the live thread `thread` ready, once. */
static void vader_sched_enqueue(int64_t thread) {
    vader_sched_slot_t* s = vader_sched_slot_of(thread);
    if (s->queued) return;
    s->queued = 1;
    if (g_sched_ready_len == g_sched_ready_cap) vader_sched_grow_ready();
    g_sched_ready[(g_sched_ready_head + g_sched_ready_len) & (g_sched_ready_cap - 1u)] = thread;
    g_sched_ready_len++;
}

/* The next ready thread that has not ended, into `*thread`; 0 when none is. */
static int vader_sched_pop_ready(int64_t* thread) {
    while (g_sched_ready_len > 0u) {
        int64_t next = g_sched_ready[g_sched_ready_head];
        g_sched_ready_head = (g_sched_ready_head + 1u) & (g_sched_ready_cap - 1u);
        g_sched_ready_len--;
        if (!vader_vt_is_live(next)) continue;
        vader_sched_slot_of(next)->queued = 0;
        *thread = next;
        return 1;
    }
    return 0;
}

/* ---- the clock and the sleeps ---------------------------------------------- */

static int64_t vader_sched_now(void) {
    if (g_sched_virtual_clock) return g_sched_virtual_now;
    return vader_os_monotonic_ns();
}

static void vader_sched_arm(int64_t deadline, int64_t thread, uint32_t sleep) {
    if (g_sched_timer_len == g_sched_timer_cap) {
        size_t cap = 64u;
        if (g_sched_timer_cap != 0u) cap = g_sched_timer_cap * 2u;
        vader_sched_timer_t* grown = (vader_sched_timer_t*) realloc(g_sched_timers, cap * sizeof(vader_sched_timer_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        g_sched_timers = grown;
        g_sched_timer_cap = cap;
    }
    size_t i = g_sched_timer_len++;
    while (i > 0u) {
        size_t parent = (i - 1u) / 2u;
        if (g_sched_timers[parent].deadline <= deadline) break;
        g_sched_timers[i] = g_sched_timers[parent];
        i = parent;
    }
    g_sched_timers[i].deadline = deadline;
    g_sched_timers[i].thread = thread;
    g_sched_timers[i].sleep = sleep;
}

static void vader_sched_drop_first_timer(void) {
    vader_sched_timer_t last = g_sched_timers[--g_sched_timer_len];
    if (g_sched_timer_len == 0u) return;
    size_t i = 0;
    for (;;) {
        size_t child = 2u * i + 1u;
        if (child >= g_sched_timer_len) break;
        if (child + 1u < g_sched_timer_len && g_sched_timers[child + 1u].deadline < g_sched_timers[child].deadline) {
            child++;
        }
        if (last.deadline <= g_sched_timers[child].deadline) break;
        g_sched_timers[i] = g_sched_timers[child];
        i = child;
    }
    g_sched_timers[i] = last;
}

/* Whether `timer` still wakes its thread: the thread has not ended, nor slept
 * or parked again since. */
static int vader_sched_timer_wakes(const vader_sched_timer_t* timer) {
    if (!vader_vt_is_live(timer->thread)) return 0;
    return vader_sched_slot_of(timer->thread)->sleep == timer->sleep;
}

/* The deadline of the nearest sleep, into `*deadline`; 0 when no thread
 * sleeps. The timers that wake nothing go first. */
static int vader_sched_next_deadline(int64_t* deadline) {
    while (g_sched_timer_len > 0u && !vader_sched_timer_wakes(&g_sched_timers[0])) {
        vader_sched_drop_first_timer();
    }
    if (g_sched_timer_len == 0u) return 0;
    *deadline = g_sched_timers[0].deadline;
    return 1;
}

/* Make ready the threads whose sleep is over. */
static void vader_sched_fire_due_timers(void) {
    int64_t deadline = 0;
    if (!vader_sched_next_deadline(&deadline)) return;
    int64_t now = vader_sched_now();
    while (deadline <= now) {
        int64_t thread = g_sched_timers[0].thread;
        vader_sched_drop_first_timer();
        vader_sched_enqueue(thread);
        if (!vader_sched_next_deadline(&deadline)) return;
    }
}

static void vader_sched_wait_until(int64_t deadline) {
    if (g_sched_virtual_clock) {
        if (deadline > g_sched_virtual_now) g_sched_virtual_now = deadline;
        return;
    }
    int64_t now = vader_os_monotonic_ns();
    if (deadline > now) vader_os_sleep_ns(deadline - now);
}

/* ---- reports --------------------------------------------------------------- */

static char   g_sched_report[512];
static size_t g_sched_report_len = 0;

static void vader_sched_report_append(const char* text) {
    size_t room = sizeof(g_sched_report) - g_sched_report_len;
    int n = snprintf(g_sched_report + g_sched_report_len, room, "%s", text);
    if (n < 0) return;
    if ((size_t) n >= room) {
        g_sched_report_len = sizeof(g_sched_report) - 1u;
        return;
    }
    g_sched_report_len += (size_t) n;
}

/* How a report names `thread`: `main`, or `task #N`, since every thread a
   program starts is a task. */
static void vader_sched_name(int64_t thread, char* out, size_t room) {
    uint64_t number = vader_sched_slot_of(thread)->number;
    if (number == 0u) {
        snprintf(out, room, "main");
        return;
    }
    snprintf(out, room, "task #%llu", (unsigned long long) number);
}

/* How many threads the report names so far. */
static size_t g_sched_report_names = 0;

static void vader_sched_report_thread(int64_t thread) {
    char name[32];
    vader_sched_name(thread, name, sizeof(name));
    if (g_sched_report_names > 0u) vader_sched_report_append(",");
    vader_sched_report_append(" ");
    vader_sched_report_append(name);
    g_sched_report_names++;
}

/* Every thread waits on another and none sleeps: name them and stop. */
static void vader_sched_deadlock(void) {
    g_sched_report_len = 0;
    g_sched_report[0] = '\0';
    g_sched_report_names = 0;
    vader_sched_report_append("virtual threads: a deadlock, every task waits and nothing will wake one:");
    vader_vt_each_live(vader_sched_report_thread);
    vader_trap(g_sched_report);
}

/* ---- the loop -------------------------------------------------------------- */

static void vader_sched_loop(void) {
    for (;;) {
        vader_sched_fire_due_timers();
        int64_t next = 0;
        if (vader_sched_pop_ready(&next)) {
            vader_vt_switch(next);
            continue;
        }
        if (g_sched_exiting && vader_vt_threads() == 0u) {
            vader_sched_enqueue(vader_vt_main());
            continue;
        }
        int64_t deadline = 0;
        if (!vader_sched_next_deadline(&deadline)) vader_sched_deadlock();
        vader_vt_give_back_cold();
        vader_sched_wait_until(deadline);
    }
}

static void vader_sched_read_clock(void) {
    if (g_sched_clock_read) return;
    g_sched_clock_read = 1;
    g_sched_virtual_clock = getenv("VADER_ASYNC_VIRTUAL_CLOCK") != NULL;
}

static void vader_sched_start(void) {
    if (g_sched_started) return;
    g_sched_started = 1;
    vader_sched_read_clock();
    vader_vt_start_scheduler();
    vader_sched_fresh_slot(vader_vt_main(), 0u);
}

/* ---- parking and cancelling ------------------------------------------------ */

/* Run the running thread's pending defers, then end it. */
static void vader_sched_unwind(void) {
    vader_sched_slot_of(vader_vt_current())->unwinding = 1;
    vader_run_pending_defers();
    vader_vt_end();
}

/* Leave the running thread for the scheduler; back when it runs again. A
 * thread cancelled meanwhile unwinds instead of returning. */
static void vader_sched_block(void) {
    vader_vt_switch_to_scheduler();
    vader_sched_slot_t* s = vader_sched_slot_of(vader_vt_current());
    if (s->cancelled && !s->unwinding) vader_sched_unwind();
}

static int vader_sched_starting(void) {
    return !vader_sched_slot_of(vader_vt_current())->cancelled;
}

/* ---- what Vader calls ------------------------------------------------------ */

int64_t vader_sched_spawn(vader_fn_t* entry) {
    vader_sched_start();
    int64_t thread = vader_vt_create(entry);
    vader_sched_fresh_slot(thread, ++g_sched_numbered);
    vader_sched_enqueue(thread);
    return thread;
}

void vader_sched_park(void) {
    vader_sched_start();
    vader_sched_slot_of(vader_vt_current())->sleep++;
    vader_sched_block();
}

void vader_sched_wake(int64_t thread) {
    vader_sched_start();
    if (vader_vt_is_live(thread)) vader_sched_enqueue(thread);
}

/* A sleep with no other thread to run meanwhile, which needs no switch: a
   target without one sleeps too. */
static void vader_sched_sleep_alone(int64_t nanos) {
    vader_sched_read_clock();
    if (!g_sched_virtual_clock) {
        vader_os_sleep_ns(nanos);
        return;
    }
    if (nanos < INT64_MAX - g_sched_virtual_now) {
        g_sched_virtual_now += nanos;
        return;
    }
    g_sched_virtual_now = INT64_MAX;
}

void vader_sched_sleep_for(int64_t nanos) {
    if (nanos <= 0) return;
    if (vader_vt_threads() == 0u) {
        vader_sched_sleep_alone(nanos);
        return;
    }
    vader_sched_start();
    int64_t thread = vader_vt_current();
    int64_t now = vader_sched_now();
    int64_t deadline = INT64_MAX;
    if (nanos < INT64_MAX - now) deadline = now + nanos;
    /* A wake ends the park, not the sleep. */
    do {
        vader_sched_slot_t* s = vader_sched_slot_of(thread);
        s->sleep++;
        vader_sched_arm(deadline, thread, s->sleep);
        vader_sched_block();
    } while (vader_sched_now() < deadline);
}

void vader_sched_cancel(int64_t thread) {
    if (thread == vader_vt_main()) vader_trap("virtual threads: the main thread cannot be cancelled");
    if (!vader_vt_is_live(thread)) return;
    vader_sched_slot_t* s = vader_sched_slot_of(thread);
    s->cancelled = 1;
    if (thread != vader_vt_current()) {
        vader_sched_enqueue(thread);
        return;
    }
    if (s->unwinding) return;
    vader_sched_unwind();
}

int64_t vader_sched_current(void) {
    return vader_vt_current();
}

/* A thread cancelled before `main` returned is on its way out: `main` waits
   for it without naming it. */
static void vader_sched_cancel_at_exit(int64_t thread) {
    if (thread == vader_vt_main()) return;
    if (vader_sched_slot_of(thread)->cancelled) return;
    char name[32];
    vader_sched_name(thread, name, sizeof(name));
    const char* what = " still runs when main returns: cancelled";
    vader_os_report_fatal(name, what, strlen(what));
    g_sched_left_running = 1;
    vader_sched_cancel(thread);
}

int vader_sched_exit(int code) {
    if (!g_sched_started || vader_vt_threads() == 0u) return code;
    vader_vt_each_live(vader_sched_cancel_at_exit);
    g_sched_exiting = 1;
    vader_sched_slot_of(vader_vt_main())->sleep++;
    while (vader_vt_threads() > 0u) vader_sched_block();
    g_sched_exiting = 0;
    if (code != 0 || !g_sched_left_running) return code;
    return 1;
}
