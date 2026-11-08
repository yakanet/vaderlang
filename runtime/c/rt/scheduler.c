/* rt/scheduler.c: the scheduler of virtual threads: which thread runs, the ones
 * that sleep, and the ones cancelled.
 *
 * A thread runs until it parks, sleeps or ends; the scheduler then runs the
 * ready threads in the order they became ready. With none ready, it waits for
 * the nearest sleep to end or for what a thread watches (a descriptor to read,
 * a child to end), and gives the stacks freed meanwhile back to the OS; with
 * neither, every thread waits on another and the program stops. While threads
 * are ready, the OS is asked what it has once they have all run and
 * VADER_SCHEDULER_ASK_EVERY_NS has passed since it was last asked, so that
 * threads that never park do not starve the ones that watch. The scheduler
 * runs on a thread of its own (rt/virtual_threads.c), which runs no Vader code.
 *
 * A cancelled thread unwinds at its next run: it cancels the threads it
 * launched that have not ended and waits for their ends, then runs its pending
 * defers on its own stack, then ends. A defer may park meanwhile, and the
 * cancellation goes on where it stood. A thread that returns leaves the threads
 * it launched running, and so does the end of a cancellation: what its defers
 * launch runs on. A thread cancelled before it starts runs its entry all the
 * same, which `vader_scheduler_is_cancelled` tells, and unwinds at its first
 * park.
 *
 * Under `VADER_VIRTUAL_CLOCK`, the clock counts the sleeps alone: it
 * jumps to the end of the nearest one instead of waiting for it, once the OS
 * has nothing ready. */

#include "internal.h"

/* What the scheduler keeps of a thread, at the thread's index. */
typedef struct {
    uint64_t number;        /* how a report names it; 0 for the main thread */
    int64_t  parent;        /* the thread that launched it */
    uint32_t children;      /* the threads it launched that have not ended */
    uint32_t sleep;         /* a timer armed under another value wakes nothing */
    uint8_t  queued;        /* in the ready queue */
    uint8_t  cancelled;
    uint8_t  unwinding;     /* cancelling its children, then running its defers */
    uint8_t  reaping;       /* waits for its children to end */
    uint8_t  outlives;      /* launched by a defer of its launcher's cancellation */
} vader_scheduler_slot_t;

typedef struct {
    int64_t  deadline;
    uint64_t began;         /* the order its sleep began in */
    int64_t  thread;
    uint32_t sleep;
} vader_scheduler_timer_t;

/* A thread waiting for the OS to report `id`, a descriptor or a child. It
 * wakes the park of `sleep`, the thread's next one when it was set. */
typedef struct {
    int64_t  id;
    int64_t  thread;
    uint32_t sleep;
    uint8_t  kind;          /* VADER_WATCH_READABLE or VADER_WATCH_EXIT */
} vader_scheduler_watch_t;

static int      g_scheduler_started = 0;
static int      g_scheduler_clock_read = 0;
static int      g_scheduler_virtual_clock = 0;
static int64_t  g_scheduler_virtual_now = 0;
static uint64_t g_scheduler_numbered = 0;
/* `main` returned and waits for the threads it cancelled. */
static int      g_scheduler_exiting = 0;
/* Some thread was still running, not cancelled, when `main` returned. */
static int      g_scheduler_left_running = 0;

static vader_scheduler_slot_t* g_scheduler_slots = NULL;
static size_t g_scheduler_slot_cap = 0;

/* The ready threads, a ring of handles whose capacity is a power of two. A
 * thread that ended while queued leaves its handle behind, skipped. */
static int64_t* g_scheduler_ready = NULL;
static size_t g_scheduler_ready_head = 0;
static size_t g_scheduler_ready_len = 0;
static size_t g_scheduler_ready_cap = 0;

/* The sleeps, a min-heap on the deadline: of two sleeps ending together, the
 * one that began first wakes first. */
static vader_scheduler_timer_t* g_scheduler_timers = NULL;
static size_t g_scheduler_timer_len = 0;
static size_t g_scheduler_timer_cap = 0;
static uint64_t g_scheduler_sleeps_begun = 0;

/* The watches, in no order. One the OS will not take is a sleep instead, of
 * VADER_SCHEDULER_REFUSED_WATCH_NS, after which the thread checks again. */
static vader_scheduler_watch_t* g_scheduler_watches = NULL;
static size_t g_scheduler_watch_len = 0;
static size_t g_scheduler_watch_cap = 0;
#define VADER_SCHEDULER_REFUSED_WATCH_NS 2000000
/* While threads are ready, how long at least between two questions to the OS:
 * one costs microseconds, a switch tens of nanoseconds. */
#define VADER_SCHEDULER_ASK_EVERY_NS 1000000
/* Switches left before the end of a turn, when the clock says whether the OS is
 * due. */
static size_t g_scheduler_turn_left = 0;
/* When the OS last answered, on the system clock. */
static int64_t g_scheduler_asked_at = 0;

/* ---- the slots ------------------------------------------------------------- */

/* The slot of the live thread `thread`. */
static vader_scheduler_slot_t* vader_scheduler_slot_of(int64_t thread) {
    return &g_scheduler_slots[vader_virtual_thread_index(thread)];
}

/* Give `thread` a fresh slot, numbered `number`. */
static void vader_scheduler_fresh_slot(int64_t thread, uint64_t number) {
    size_t index = vader_virtual_thread_index(thread);
    if (index >= g_scheduler_slot_cap) {
        size_t cap = 64u;
        while (cap <= index) cap *= 2u;
        vader_scheduler_slot_t* grown = (vader_scheduler_slot_t*) realloc(
            g_scheduler_slots, cap * sizeof(vader_scheduler_slot_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        memset(grown + g_scheduler_slot_cap, 0,
               (cap - g_scheduler_slot_cap) * sizeof(vader_scheduler_slot_t));
        g_scheduler_slots = grown;
        g_scheduler_slot_cap = cap;
    }
    vader_scheduler_slot_t* s = &g_scheduler_slots[index];
    memset(s, 0, sizeof(vader_scheduler_slot_t));
    s->number = number;
}

/* ---- the ready queue ------------------------------------------------------- */

static void vader_scheduler_grow_ready(void) {
    size_t cap = 64u;
    if (g_scheduler_ready_cap != 0u) cap = g_scheduler_ready_cap * 2u;
    int64_t* grown = (int64_t*) malloc(cap * sizeof(int64_t));
    if (grown == NULL) vader_trap("virtual threads: out of memory");
    for (size_t i = 0; i < g_scheduler_ready_len; i++) {
        grown[i] = g_scheduler_ready[(g_scheduler_ready_head + i) & (g_scheduler_ready_cap - 1u)];
    }
    free(g_scheduler_ready);
    g_scheduler_ready = grown;
    g_scheduler_ready_head = 0;
    g_scheduler_ready_cap = cap;
}

/* Make the live thread `thread` ready, once. */
static void vader_scheduler_enqueue(int64_t thread) {
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
    if (s->queued) return;
    s->queued = 1;
    if (g_scheduler_ready_len == g_scheduler_ready_cap) vader_scheduler_grow_ready();
    size_t tail = (g_scheduler_ready_head + g_scheduler_ready_len) & (g_scheduler_ready_cap - 1u);
    g_scheduler_ready[tail] = thread;
    g_scheduler_ready_len++;
}

/* The next ready thread that has not ended, into `*thread`; 0 when none is. */
static int vader_scheduler_pop_ready(int64_t* thread) {
    while (g_scheduler_ready_len > 0u) {
        int64_t next = g_scheduler_ready[g_scheduler_ready_head];
        g_scheduler_ready_head = (g_scheduler_ready_head + 1u) & (g_scheduler_ready_cap - 1u);
        g_scheduler_ready_len--;
        if (!vader_virtual_thread_is_live(next)) continue;
        vader_scheduler_slot_of(next)->queued = 0;
        *thread = next;
        return 1;
    }
    return 0;
}

/* ---- the clock and the sleeps ---------------------------------------------- */

static int64_t vader_scheduler_now(void) {
    if (g_scheduler_virtual_clock) return g_scheduler_virtual_now;
    return vader_os_monotonic_ns();
}

static int vader_scheduler_timer_before(const vader_scheduler_timer_t* a,
                                        const vader_scheduler_timer_t* b) {
    if (a->deadline != b->deadline) return a->deadline < b->deadline;
    return a->began < b->began;
}

static void vader_scheduler_arm(vader_scheduler_timer_t timer) {
    if (g_scheduler_timer_len == g_scheduler_timer_cap) {
        size_t cap = 64u;
        if (g_scheduler_timer_cap != 0u) cap = g_scheduler_timer_cap * 2u;
        vader_scheduler_timer_t* grown = (vader_scheduler_timer_t*) realloc(
            g_scheduler_timers, cap * sizeof(vader_scheduler_timer_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        g_scheduler_timers = grown;
        g_scheduler_timer_cap = cap;
    }
    size_t i = g_scheduler_timer_len++;
    while (i > 0u) {
        size_t parent = (i - 1u) / 2u;
        if (!vader_scheduler_timer_before(&timer, &g_scheduler_timers[parent])) break;
        g_scheduler_timers[i] = g_scheduler_timers[parent];
        i = parent;
    }
    g_scheduler_timers[i] = timer;
}

static void vader_scheduler_drop_first_timer(void) {
    vader_scheduler_timer_t last = g_scheduler_timers[--g_scheduler_timer_len];
    if (g_scheduler_timer_len == 0u) return;
    size_t i = 0;
    for (;;) {
        size_t child = 2u * i + 1u;
        if (child >= g_scheduler_timer_len) break;
        if (child + 1u < g_scheduler_timer_len
            && vader_scheduler_timer_before(&g_scheduler_timers[child + 1u],
                                            &g_scheduler_timers[child])) {
            child++;
        }
        if (!vader_scheduler_timer_before(&g_scheduler_timers[child], &last)) break;
        g_scheduler_timers[i] = g_scheduler_timers[child];
        i = child;
    }
    g_scheduler_timers[i] = last;
}

/* Whether `timer` still wakes its thread: the thread has not ended, nor slept
 * or parked again since. */
static int vader_scheduler_timer_wakes(const vader_scheduler_timer_t* timer) {
    if (!vader_virtual_thread_is_live(timer->thread)) return 0;
    return vader_scheduler_slot_of(timer->thread)->sleep == timer->sleep;
}

/* The deadline of the nearest sleep, into `*deadline`; 0 when no thread
 * sleeps. The timers that wake nothing go first. */
static int vader_scheduler_next_deadline(int64_t* deadline) {
    while (g_scheduler_timer_len > 0u && !vader_scheduler_timer_wakes(&g_scheduler_timers[0])) {
        vader_scheduler_drop_first_timer();
    }
    if (g_scheduler_timer_len == 0u) return 0;
    *deadline = g_scheduler_timers[0].deadline;
    return 1;
}

/* Make ready the threads whose sleep is over. */
static void vader_scheduler_fire_due_timers(void) {
    int64_t deadline = 0;
    if (!vader_scheduler_next_deadline(&deadline)) return;
    int64_t now = vader_scheduler_now();
    while (deadline <= now) {
        int64_t thread = g_scheduler_timers[0].thread;
        vader_scheduler_drop_first_timer();
        vader_scheduler_enqueue(thread);
        if (!vader_scheduler_next_deadline(&deadline)) return;
    }
}

/* Nanoseconds from now on the OS's clock until `deadline`, 0 once it passed. */
static int64_t vader_scheduler_nanos_until(int64_t deadline) {
    int64_t now = vader_os_monotonic_ns();
    if (deadline > now) return deadline - now;
    return 0;
}

static void vader_scheduler_wait_until(int64_t deadline) {
    if (g_scheduler_virtual_clock) {
        if (deadline > g_scheduler_virtual_now) g_scheduler_virtual_now = deadline;
        return;
    }
    int64_t nanos = vader_scheduler_nanos_until(deadline);
    if (nanos > 0) vader_os_sleep_ns(nanos);
}

/* The deadline `nanos` from now, INT64_MAX past the end of the clock. */
static int64_t vader_scheduler_deadline_in(int64_t nanos) {
    int64_t now = vader_scheduler_now();
    if (nanos < INT64_MAX - now) return now + nanos;
    return INT64_MAX;
}

/* ---- what the OS reports --------------------------------------------------- */

static int vader_scheduler_watch_wakes(const vader_scheduler_watch_t* watch) {
    if (!vader_virtual_thread_is_live(watch->thread)) return 0;
    return vader_scheduler_slot_of(watch->thread)->sleep == watch->sleep;
}

static void vader_scheduler_on_event(int kind, int64_t id) {
    size_t i = 0;
    while (i < g_scheduler_watch_len) {
        vader_scheduler_watch_t* w = &g_scheduler_watches[i];
        if (w->kind != kind || w->id != id) {
            i++;
            continue;
        }
        if (vader_scheduler_watch_wakes(w)) vader_scheduler_enqueue(w->thread);
        g_scheduler_watches[i] = g_scheduler_watches[--g_scheduler_watch_len];
    }
}

/* Whether a watch still wakes a thread. The ones met that wake none go. */
static int vader_scheduler_watching(void) {
    while (g_scheduler_watch_len > 0u) {
        if (vader_scheduler_watch_wakes(&g_scheduler_watches[0])) return 1;
        g_scheduler_watches[0] = g_scheduler_watches[--g_scheduler_watch_len];
    }
    return 0;
}

/* Ask the OS what it has, waiting at most `timeout_ns`. The threads it makes
 * ready, with those already ready, run before it is asked again. */
static void vader_scheduler_ask_os(int64_t timeout_ns) {
    vader_os_wait_events(timeout_ns);
    g_scheduler_asked_at = vader_os_monotonic_ns();
    g_scheduler_turn_left = g_scheduler_ready_len;
}

/* Every ready thread has run: ask the OS without waiting when it is due, else
 * begin another turn. */
static void vader_scheduler_end_turn(void) {
    if (vader_os_monotonic_ns() - g_scheduler_asked_at >= VADER_SCHEDULER_ASK_EVERY_NS) {
        vader_scheduler_ask_os(0);
        return;
    }
    g_scheduler_turn_left = g_scheduler_ready_len;
}

/* With no thread ready: wait for the nearest sleep to end, when `sleeping`, or
 * for what a thread watches, when `watching`, whichever comes first. */
static void vader_scheduler_idle(int sleeping, int64_t deadline, int watching) {
    if (!watching) {
        vader_scheduler_wait_until(deadline);
        return;
    }
    if (!sleeping) {
        vader_scheduler_ask_os(-1);
        return;
    }
    if (g_scheduler_virtual_clock) {
        vader_scheduler_ask_os(0);
        if (g_scheduler_ready_len == 0u) vader_scheduler_wait_until(deadline);
        return;
    }
    vader_scheduler_ask_os(vader_scheduler_nanos_until(deadline));
}

/* ---- reports --------------------------------------------------------------- */

static char   g_scheduler_report[512];
static size_t g_scheduler_report_len = 0;

static void vader_scheduler_report_append(const char* text) {
    size_t room = sizeof(g_scheduler_report) - g_scheduler_report_len;
    int n = snprintf(g_scheduler_report + g_scheduler_report_len, room, "%s", text);
    if (n < 0) return;
    if ((size_t) n >= room) {
        g_scheduler_report_len = sizeof(g_scheduler_report) - 1u;
        return;
    }
    g_scheduler_report_len += (size_t) n;
}

/* How a report names `thread`: `main`, or `task #N`, since every thread a
   program starts is a task. */
static void vader_scheduler_name(int64_t thread, char* out, size_t room) {
    uint64_t number = vader_scheduler_slot_of(thread)->number;
    if (number == 0u) {
        snprintf(out, room, "main");
        return;
    }
    snprintf(out, room, "task #%llu", (unsigned long long) number);
}

/* How many threads the report names so far. */
static size_t g_scheduler_report_names = 0;

static void vader_scheduler_report_thread(int64_t thread) {
    char name[32];
    vader_scheduler_name(thread, name, sizeof(name));
    if (g_scheduler_report_names > 0u) vader_scheduler_report_append(",");
    vader_scheduler_report_append(" ");
    vader_scheduler_report_append(name);
    g_scheduler_report_names++;
}

/* The live threads `vader_scheduler_each_by_number` walks. */
static int64_t* g_scheduler_by_number = NULL;
static size_t   g_scheduler_by_number_len = 0;

static void vader_scheduler_collect(int64_t thread) {
    g_scheduler_by_number[g_scheduler_by_number_len++] = thread;
}

static int vader_scheduler_compare_numbers(const void* a, const void* b) {
    uint64_t x = vader_scheduler_slot_of(*(const int64_t*) a)->number;
    uint64_t y = vader_scheduler_slot_of(*(const int64_t*) b)->number;
    return (x > y) - (x < y);
}

/* Call `fn` on each live thread, main first, then the tasks in the order they
 * started: a report reads the same on every run, and as the VM writes it. */
static void vader_scheduler_each_by_number(void (*fn)(int64_t thread)) {
    /* The tasks, and main. */
    size_t live = vader_virtual_thread_count() + 1u;
    g_scheduler_by_number = (int64_t*) malloc(live * sizeof(int64_t));
    if (g_scheduler_by_number == NULL) vader_trap("virtual threads: out of memory");
    g_scheduler_by_number_len = 0;
    vader_virtual_thread_each_live(vader_scheduler_collect);
    qsort(g_scheduler_by_number, g_scheduler_by_number_len, sizeof(int64_t),
          vader_scheduler_compare_numbers);
    for (size_t i = 0; i < g_scheduler_by_number_len; i++) fn(g_scheduler_by_number[i]);
    free(g_scheduler_by_number);
}

/* Every thread waits on another and none sleeps: name them and stop. */
static void vader_scheduler_deadlock(void) {
    g_scheduler_report_len = 0;
    g_scheduler_report[0] = '\0';
    g_scheduler_report_names = 0;
    vader_scheduler_report_append(
        "virtual threads: a deadlock, every task waits and nothing will wake one:");
    vader_scheduler_each_by_number(vader_scheduler_report_thread);
    vader_trap(g_scheduler_report);
}

/* ---- the loop -------------------------------------------------------------- */

static void vader_scheduler_loop(void) {
    for (;;) {
        vader_scheduler_fire_due_timers();
        if (g_scheduler_turn_left == 0u && g_scheduler_ready_len > 0u
            && vader_scheduler_watching()) {
            vader_scheduler_end_turn();
        }
        int64_t next = 0;
        if (vader_scheduler_pop_ready(&next)) {
            if (g_scheduler_turn_left > 0u) g_scheduler_turn_left--;
            vader_virtual_thread_switch(next);
            continue;
        }
        if (g_scheduler_exiting && vader_virtual_thread_count() == 0u) {
            vader_scheduler_enqueue(vader_virtual_thread_main());
            continue;
        }
        int64_t deadline = 0;
        int sleeping = vader_scheduler_next_deadline(&deadline);
        int watching = vader_scheduler_watching();
        if (!sleeping && !watching) vader_scheduler_deadlock();
        vader_virtual_thread_give_back_cold();
        vader_scheduler_idle(sleeping, deadline, watching);
    }
}

static void vader_scheduler_read_clock(void) {
    if (g_scheduler_clock_read) return;
    g_scheduler_clock_read = 1;
    g_scheduler_virtual_clock = getenv("VADER_VIRTUAL_CLOCK") != NULL;
}

static void vader_scheduler_start(void) {
    if (g_scheduler_started) return;
    g_scheduler_started = 1;
    vader_scheduler_read_clock();
    vader_virtual_thread_start_scheduler();
    vader_scheduler_fresh_slot(vader_virtual_thread_main(), 0u);
}

/* ---- parking and cancelling ------------------------------------------------ */

/* The thread whose children `vader_scheduler_cancel_child` cancels. */
static int64_t g_scheduler_launcher = 0;

static void vader_scheduler_cancel_child(int64_t thread) {
    if (vader_scheduler_slot_of(thread)->parent == g_scheduler_launcher) {
        vader_scheduler_cancel(thread);
    }
}

/* Cancel the threads that `thread`, the running one, launched and that have
 * not ended, then wait for their ends: their defers run before its own. */
static void vader_scheduler_cancel_children(int64_t thread) {
    if (vader_scheduler_slot_of(thread)->children == 0u) return;
    g_scheduler_launcher = thread;
    vader_virtual_thread_each_live(vader_scheduler_cancel_child);
    vader_scheduler_slot_of(thread)->reaping = 1;
    while (vader_scheduler_slot_of(thread)->children > 0u) vader_scheduler_park();
    vader_scheduler_slot_of(thread)->reaping = 0;
}

/* Cancel the running thread's children, run its pending defers, then end it. */
static void vader_scheduler_unwind(void) {
    int64_t thread = vader_virtual_thread_current();
    vader_scheduler_slot_of(thread)->unwinding = 1;
    vader_scheduler_cancel_children(thread);
    vader_run_pending_defers();
    vader_virtual_thread_end();
}

/* Whether the thread of slot `s` was cancelled and has not begun to unwind. */
static int vader_scheduler_must_unwind(const vader_scheduler_slot_t* s) {
    return s->cancelled && !s->unwinding;
}

/* Leave the running thread, whose slot is `s`, for the scheduler; back when it
 * runs again. A thread cancelled before it started unwinds instead of leaving,
 * one cancelled meanwhile instead of returning. The slots move when a thread
 * is launched, so the slot is read again after the switch. */
static void vader_scheduler_block(vader_scheduler_slot_t* s) {
    if (vader_scheduler_must_unwind(s)) vader_scheduler_unwind();
    vader_virtual_thread_switch_to_scheduler();
    if (vader_scheduler_must_unwind(vader_scheduler_slot_of(vader_virtual_thread_current()))) {
        vader_scheduler_unwind();
    }
}

static void vader_scheduler_ending(void) {
    int64_t parent = vader_scheduler_slot_of(vader_virtual_thread_current())->parent;
    if (!vader_virtual_thread_is_live(parent)) return;
    vader_scheduler_slot_t* p = vader_scheduler_slot_of(parent);
    p->children--;
    if (p->children == 0u && p->reaping) vader_scheduler_enqueue(parent);
}

/* ---- what Vader calls ------------------------------------------------------ */

int64_t vader_scheduler_spawn(vader_fn_t* entry) {
    vader_scheduler_start();
    int64_t launcher = vader_virtual_thread_current();
    int64_t thread = vader_virtual_thread_create(entry);
    vader_scheduler_fresh_slot(thread, ++g_scheduler_numbered);
    vader_scheduler_slot_of(thread)->parent = launcher;
    vader_scheduler_slot_of(thread)->outlives = vader_scheduler_slot_of(launcher)->unwinding;
    vader_scheduler_slot_of(launcher)->children++;
    vader_scheduler_enqueue(thread);
    return thread;
}

void vader_scheduler_park(void) {
    vader_scheduler_start();
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(vader_virtual_thread_current());
    s->sleep++;
    vader_scheduler_block(s);
}

void vader_scheduler_wake(int64_t thread) {
    vader_scheduler_start();
    if (vader_virtual_thread_is_live(thread)) vader_scheduler_enqueue(thread);
}

/* A sleep with no other thread to run meanwhile, which needs no switch: a
   target without one sleeps too. */
static void vader_scheduler_sleep_alone(int64_t nanos) {
    vader_scheduler_read_clock();
    if (!g_scheduler_virtual_clock) {
        vader_os_sleep_ns(nanos);
        return;
    }
    g_scheduler_virtual_now = vader_scheduler_deadline_in(nanos);
}

void vader_scheduler_sleep_for(int64_t nanos) {
    if (nanos <= 0) return;
    if (vader_virtual_thread_count() == 0u) {
        vader_scheduler_sleep_alone(nanos);
        return;
    }
    vader_scheduler_start();
    int64_t thread = vader_virtual_thread_current();
    int64_t deadline = vader_scheduler_deadline_in(nanos);
    uint64_t began = ++g_scheduler_sleeps_begun;
    /* A wake ends the park, not the sleep. */
    do {
        vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
        s->sleep++;
        vader_scheduler_arm((vader_scheduler_timer_t) { deadline, began, thread, s->sleep });
        vader_scheduler_block(s);
    } while (vader_scheduler_now() < deadline);
}

/* Wake the running thread's next park once the OS reports `id`. */
static void vader_scheduler_watch(int kind, int64_t id) {
    vader_scheduler_start();
    int64_t thread = vader_virtual_thread_current();
    uint32_t sleep = vader_scheduler_slot_of(thread)->sleep + 1u;
    if (!vader_os_watch(kind, id)) {
        int64_t deadline = vader_scheduler_deadline_in(VADER_SCHEDULER_REFUSED_WATCH_NS);
        vader_scheduler_arm(
            (vader_scheduler_timer_t) { deadline, ++g_scheduler_sleeps_begun, thread, sleep });
        return;
    }
    /* A thread watches the same `id` again at each park of a loop, woken
     * meanwhile by another watch: its entry moves to the new park. */
    for (size_t i = 0; i < g_scheduler_watch_len; i++) {
        vader_scheduler_watch_t* w = &g_scheduler_watches[i];
        if (w->kind == kind && w->id == id && w->thread == thread) {
            w->sleep = sleep;
            return;
        }
    }
    if (g_scheduler_watch_len == g_scheduler_watch_cap) {
        size_t cap = 16u;
        if (g_scheduler_watch_cap != 0u) cap = g_scheduler_watch_cap * 2u;
        vader_scheduler_watch_t* grown = (vader_scheduler_watch_t*) realloc(
            g_scheduler_watches, cap * sizeof(vader_scheduler_watch_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        g_scheduler_watches = grown;
        g_scheduler_watch_cap = cap;
    }
    g_scheduler_watches[g_scheduler_watch_len++] =
        (vader_scheduler_watch_t) { id, thread, sleep, (uint8_t) kind };
}

void vader_scheduler_watch_readable(int64_t fd) {
    vader_scheduler_watch(VADER_WATCH_READABLE, fd);
}

void vader_scheduler_watch_exit(int64_t child) {
    vader_scheduler_watch(VADER_WATCH_EXIT, child);
}

bool vader_scheduler_wait_readable_for(int64_t fd, int64_t nanos) {
    if (vader_virtual_thread_count() == 0u) return true;
    vader_scheduler_start();
    int64_t thread = vader_virtual_thread_current();
    int timed = nanos >= 0;
    int64_t deadline = vader_scheduler_deadline_in(nanos);
    uint64_t began = ++g_scheduler_sleeps_begun;
    while (!vader_os_readable_now(fd)) {
        if (timed && vader_scheduler_now() >= deadline) return false;
        vader_scheduler_watch(VADER_WATCH_READABLE, fd);
        /* The timer ends the park the watch ends, whichever comes first. */
        if (timed) {
            uint32_t sleep = vader_scheduler_slot_of(thread)->sleep + 1u;
            vader_scheduler_arm((vader_scheduler_timer_t) { deadline, began, thread, sleep });
        }
        vader_scheduler_park();
    }
    return true;
}

void vader_scheduler_wait_readable(int64_t fd) {
    (void) vader_scheduler_wait_readable_for(fd, -1);
}

void vader_scheduler_cancel(int64_t thread) {
    if (thread == vader_virtual_thread_main()) {
        vader_trap("virtual threads: the main thread cannot be cancelled");
    }
    if (!vader_virtual_thread_is_live(thread)) return;
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
    /* Already on its way out: queued, or parked in its cancellation, which a
     * wake would cut short. */
    if (s->cancelled) return;
    s->cancelled = 1;
    if (thread != vader_virtual_thread_current()) {
        vader_scheduler_enqueue(thread);
        return;
    }
    vader_scheduler_unwind();
}

int64_t vader_scheduler_current(void) {
    return vader_virtual_thread_current();
}

bool vader_scheduler_is_cancelled(void) {
    if (!g_scheduler_started) return false;
    return vader_scheduler_slot_of(vader_virtual_thread_current())->cancelled != 0;
}

bool vader_scheduler_is_leaving(int64_t thread) {
    if (!g_scheduler_started) return false;
    while (thread != vader_virtual_thread_main() && vader_virtual_thread_is_live(thread)) {
        vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
        if (s->cancelled) return true;
        if (s->outlives) return false;
        thread = s->parent;
    }
    return false;
}

static void vader_scheduler_name_at_exit(int64_t thread) {
    if (thread == vader_virtual_thread_main() || vader_scheduler_is_leaving(thread)) return;
    char name[32];
    vader_scheduler_name(thread, name, sizeof(name));
    const char* what = " still runs when main returns: cancelled";
    vader_os_report_fatal(name, what, strlen(what));
    g_scheduler_left_running = 1;
}

static void vader_scheduler_cancel_at_exit(int64_t thread) {
    if (thread != vader_virtual_thread_main()) vader_scheduler_cancel(thread);
}

int vader_scheduler_exit(int code) {
    if (!g_scheduler_started || vader_virtual_thread_count() == 0u) return code;
    /* Every name before any cancel, which would make the threads it launched
     * leave. */
    vader_scheduler_each_by_number(vader_scheduler_name_at_exit);
    vader_scheduler_each_by_number(vader_scheduler_cancel_at_exit);
    g_scheduler_exiting = 1;
    vader_scheduler_slot_of(vader_virtual_thread_main())->sleep++;
    while (vader_virtual_thread_count() > 0u) {
        vader_scheduler_block(vader_scheduler_slot_of(vader_virtual_thread_main()));
    }
    g_scheduler_exiting = 0;
    if (code != 0 || !g_scheduler_left_running) return code;
    return 1;
}
