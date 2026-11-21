/* rt/scheduler.c: the scheduler of virtual threads: which thread runs, the ones
 * that sleep, and the ones cancelled.
 *
 * A thread runs until it parks, sleeps or ends; the scheduler then runs the
 * ready threads in the order they became ready. With none ready, it waits for
 * the nearest sleep to end or for what a thread watches (a descriptor to read
 * or to write, a child to end), and gives the stacks freed meanwhile back to
 * the OS; with neither, every thread waits on another and the program stops.
 * While threads
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
 * Under `VADER_VIRTUAL_CLOCK`, the clock counts the sleeps alone: with no
 * thread ready and none waiting on the OS, it jumps to the end of the nearest
 * one instead of waiting for it.
 *
 * `VADER_THREADS` workers run the threads, each a system thread with its own
 * scheduler and ready queue; a thread runs on the worker of the thread that
 * created it, from its start to its end. One lock guards every state here and
 * in rt/virtual_threads.c. A worker with nothing to run rests: on a condition
 * while another worker runs a thread, asking the OS now and then when a thread
 * watches it; the last one to rest keeps the program, as the one worker does
 * alone: it waits for the nearest sleep or for the OS, holding the lock, and
 * finds the deadlocks. */

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
    uint8_t  released;      /* the descriptor it waited for is no longer waited on */
    uint8_t  task_ended;    /* its task ended: it leaves the runtime, then ends */
    uint8_t  reported;      /* what the OS reported ended its last park */
    uint8_t  on_clock_or_os; /* parks for the clock or the OS, which a trap leaves running */
    uint8_t  shielded;      /* waits for a relayed call, which writes into its stack */
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
    uint8_t  kind;          /* one of VADER_WATCH_* */
} vader_scheduler_watch_t;

static int      g_scheduler_started = 0;
static int      g_scheduler_clock_read = 0;
static int      g_scheduler_virtual_clock = 0;
/* Set via `VADER_SCHEDULER_SLOW_END=1`: a thread whose entry returned waits a
 * millisecond before it leaves the runtime, for the tests of what `main`
 * returning sees of it meanwhile. */
static int      g_scheduler_slow_end = 0;
static int64_t  g_scheduler_virtual_now = 0;
/* `main` returned and waits for the threads it cancelled. */
static int      g_scheduler_exiting = 0;
/* Some thread was still running, not cancelled, when `main` returned. */
static int      g_scheduler_left_running = 0;

static vader_scheduler_slot_t* g_scheduler_slots = NULL;
static size_t g_scheduler_slot_cap = 0;

/* What the scheduler keeps of one worker, at its index, on a cache line of its
 * own. */
typedef struct {
    /* Its ready threads, a ring of handles whose capacity is a power of two. A
     * thread that ended while queued leaves its handle behind, skipped. */
    _Alignas(64) int64_t* ready;
    size_t   head;
    size_t   len;
    size_t   cap;
    /* Switches left before the end of a turn, when the clock says whether the
     * OS is due. */
    size_t   turn_left;
    /* What it rests on, with several workers. */
    vader_os_cond_t* wake;
    /* Its threads that have not ended, parked ones included. */
    uint32_t tasks;
    /* Its threads parked for the clock or the OS, which the watch on long calls
     * reads from another system thread. */
    uint32_t timed_parks;
    /* It has nothing to run. */
    uint8_t  resting;
    /* It was roused and has not looked for work since. */
    uint8_t  arriving;
    /* It holds the lock: taking it twice is a bug of the runtime, which would
     * hang. */
    uint8_t  holds_guard;
} vader_scheduler_worker_t;

static vader_scheduler_worker_t g_scheduler_workers[VADER_WORKERS_MAX];
/* The workers of the pool, the main thread's first, and how many rest. */
static uint32_t g_scheduler_threads = 1;
static uint32_t g_scheduler_resting = 0;
/* The workers other than the main thread's that have started. */
static uint32_t g_scheduler_joined = 0;
/* The resting worker that asks the OS and ends the sleeps while others work,
 * or none. */
#define VADER_SCHEDULER_NO_POLLER UINT32_MAX
static uint32_t g_scheduler_poller = VADER_SCHEDULER_NO_POLLER;
/* `main` has returned: the workers rest for good. */
static int g_scheduler_closed = 0;
/* A thread trapped: `g_scheduler_trapped` is the one thread left to run. */
static int g_scheduler_trapping = 0;
static int64_t g_scheduler_trapped = 0;

/* The trapping thread waits for what a stopped thread holds or would do: the
 * defers of the trap end here. */
static VADER_NORETURN void vader_scheduler_abort_after_trap(void) {
    static const char why[] = "it waits for a task that no longer runs";
    vader_os_report_fatal("the defers of the trap stop: ", why, sizeof(why) - 1u);
    abort();
}
/* NULL with one worker. */
static vader_os_lock_t* g_scheduler_guard = NULL;

/* Timers, a min-heap on the deadline, on the clock `now` reads: of two ending
 * together, the one that began first wakes first. */
typedef struct {
    vader_scheduler_timer_t* timers;
    size_t len;
    size_t cap;
    int64_t (*now)(void);
} vader_scheduler_heap_t;

static int64_t vader_scheduler_now(void);

/* The sleeps, on the program's clock. */
static vader_scheduler_heap_t g_scheduler_sleeps = { NULL, 0, 0, vader_scheduler_now };
/* What bounds a wait on the OS, on the OS's clock whatever the program's: the
 * deadline of a timed wait, and the next check of a thread whose watch the OS
 * would not take. */
static vader_scheduler_heap_t g_scheduler_bounds = { NULL, 0, 0, vader_os_monotonic_ns };
static uint64_t g_scheduler_sleeps_begun = 0;

/* The watches, in no order, one at most for an `id` watched as a `kind`. One
 * the OS will not take, or whose `id` another thread already watches as the
 * same `kind`, is a bound of VADER_SCHEDULER_REFUSED_WATCH_NS instead, after
 * which the thread checks again. */
static vader_scheduler_watch_t* g_scheduler_watches = NULL;
static size_t g_scheduler_watch_len = 0;
static size_t g_scheduler_watch_cap = 0;
/* Where each watch is: open addressing on `id` and `kind`, linear probing, a
 * cell holding the watch's index plus one and 0 when free. Its capacity is a
 * power of two, at least twice the watches. */
static uint32_t* g_scheduler_watch_cells = NULL;
static size_t g_scheduler_watch_cell_cap = 0;
#define VADER_SCHEDULER_REFUSED_WATCH_NS 2000000
/* While threads are ready, how long at least between two questions to the OS:
 * one costs microseconds, a switch tens of nanoseconds. */
#define VADER_SCHEDULER_ASK_EVERY_NS 1000000
/* When the OS last answered, on the system clock. */
static int64_t g_scheduler_asked_at = 0;

/* ---- the monitor ----------------------------------------------------------- */

/* NULL with one worker, where the monitor is nothing. */
static vader_os_lock_t* g_monitor_guard = NULL;

static void vader_monitor_take(void* unused) {
    (void) unused;
    vader_os_lock(g_monitor_guard);
}

/* How many times a worker tries the monitor before it waits in the kernel. */
#define VADER_MONITOR_SPINS 1000

/* Take the monitor if it comes free within a bounded spin: a door holds it for
 * a short body, while a wait in the kernel costs a sleep and a wake. */
static int vader_monitor_take_spinning(void) {
    for (int i = 0; i < VADER_MONITOR_SPINS; i++) {
        if (vader_os_try_lock(g_monitor_guard)) return 1;
        vader_os_spin_pause();
    }
    return 0;
}

/* Hold the monitor for the running thread. A worker that waits for it counts
 * as stopped for a major, which the holder may run. */
static void vader_monitor_hold(void) {
    vader_worker_t* w = &vader_worker;
    if (!vader_monitor_take_spinning()) {
        /* After a trap, a holder is stopped for good. */
        if (g_scheduler_trapping) vader_scheduler_abort_after_trap();
        vader_gc_blocking(vader_monitor_take, NULL, NULL);
    }
    w->in_monitor |= VADER_HOLDS_MONITOR;
    vader_alloc_limit_refresh(w);
}

static void vader_monitor_let_go(void) {
    vader_worker_t* w = &vader_worker;
    vader_gc_mark_monitor_born(w);
    w->in_monitor &= (uint8_t) ~VADER_HOLDS_MONITOR;
    vader_alloc_limit_refresh(w);
    vader_os_unlock(g_monitor_guard);
}

/* The running thread leaves its worker for another thread: it lets the
 * monitor go, and takes it back as it returns (`vader_scheduler_unlock`), not
 * before, since the holder may wait for the scheduler's lock. Whatever it holds
 * is old, so it takes it back with no minor. */
static void vader_monitor_step_away(void) {
    if (vader_worker.in_monitor & VADER_HOLDS_MUTEX) {
        vader_trap("virtual threads: a thread parked holding a mutex");
    }
    if (!(vader_worker.in_monitor & VADER_HOLDS_MONITOR)) return;
    vader_monitor_let_go();
    vader_worker.running.monitor_away = 1;
}

static size_t vader_scheduler_pool_size(void);
static void vader_scheduler_start(void);

/* Take the monitor for the running thread, first emptying the young generation
 * of the worker when `publishes`. */
void vader_scheduler_monitor_enter(bool publishes) {
    if (g_monitor_guard == NULL) {
        /* The pool starts here at the latest, so that the first task launched
         * can run on another worker. Else one worker runs all: no monitor. */
        if (g_scheduler_started || vader_scheduler_pool_size() == 1u) return;
        vader_scheduler_start();
    }
    if (vader_worker.in_monitor & VADER_HOLDS_MUTEX) {
        vader_trap("virtual threads: the monitor taken by a thread that holds a mutex");
    }
    vader_thread_state_t* r = &vader_worker.running;
    r->monitor_depth++;
    /* Held already, the worker allocates in old: its young generation holds
     * only what it made before. */
    if (publishes) vader_gc_empty_young(&vader_worker);
    if (!(vader_worker.in_monitor & VADER_HOLDS_MONITOR)) vader_monitor_hold();
}

/* Whether `value` leads into the young generation of the worker: young itself,
 * or old, whose fields may point there. Nothing that NULL or an immortal object
 * reaches is young. */
static int vader_scheduler_reaches_young(void* value) {
    return value != NULL && (vader_in_young(&vader_worker, value) || vader_in_old(value));
}

void vader_scheduler_monitor_give_ref(void* value) {
    vader_scheduler_monitor_enter(vader_scheduler_reaches_young(value));
}

void vader_scheduler_monitor_give_box(vader_box_t value) {
    if (!vader_box_holds_object(value)) {
        vader_scheduler_monitor_enter(false);
        return;
    }
    vader_scheduler_monitor_give_ref(value.payload.obj);
}

void vader_scheduler_monitor_exit(void) {
    if (g_monitor_guard == NULL) return;
    vader_thread_state_t* r = &vader_worker.running;
    if (r->monitor_depth == 0u) vader_trap("virtual threads: the monitor let go more often than taken");
    r->monitor_depth--;
    if (r->monitor_depth > 0u || !(vader_worker.in_monitor & VADER_HOLDS_MONITOR)) return;
    vader_monitor_let_go();
}

/* ---- publication and mutexes --------------------------------------------- */

void vader_scheduler_publish_ref(void* value) {
    if (g_monitor_guard == NULL) return;
    if (vader_scheduler_reaches_young(value)) vader_gc_empty_young(&vader_worker);
}

void vader_scheduler_publish_box(vader_box_t value) {
    if (!vader_box_holds_object(value)) return;
    vader_scheduler_publish_ref(value.payload.obj);
}

/* The word of a mutex: the field of the `Mutex` struct, right after its header.
 * 0 when free, 1 when held, 2 when held while another worker may wait. */
static _Atomic uint32_t* vader_mutex_word(void* mutex) {
    return (_Atomic uint32_t*) ((char*) mutex + sizeof(vader_obj_header_t));
}

/* Where the workers that wait for a mutex sleep: a bucket picked by the
 * address of its word, shared by the mutexes that land there. */
#define VADER_MUTEX_BUCKETS 64u

typedef struct {
    vader_os_lock_t* lock;
    vader_os_cond_t* cond;
} vader_mutex_bucket_t;

static vader_mutex_bucket_t g_mutex_buckets[VADER_MUTEX_BUCKETS];

static void vader_mutex_buckets_start(void) {
    for (uint32_t i = 0; i < VADER_MUTEX_BUCKETS; i++) {
        g_mutex_buckets[i].lock = vader_os_lock_new();
        g_mutex_buckets[i].cond = vader_os_cond_new();
    }
}

static vader_mutex_bucket_t* vader_mutex_bucket_of(_Atomic uint32_t* word) {
    uintptr_t at = (uintptr_t) word;
    return &g_mutex_buckets[(at >> 4 ^ at >> 10) & (VADER_MUTEX_BUCKETS - 1u)];
}

/* Sleep while the word reads 2, as `vader_gc_blocking` runs it: the word reads
 * again under the lock of the bucket, which the unlocker takes to wake it, so
 * no wake falls between the read and the sleep. */
static void vader_mutex_sleep(void* raw) {
    _Atomic uint32_t* word = (_Atomic uint32_t*) raw;
    vader_mutex_bucket_t* bucket = vader_mutex_bucket_of(word);
    vader_os_lock(bucket->lock);
    while (atomic_load_explicit(word, memory_order_relaxed) == 2u) {
        vader_os_cond_wait(bucket->cond, bucket->lock, -1);
    }
    vader_os_unlock(bucket->lock);
}

static int vader_mutex_try(_Atomic uint32_t* word) {
    uint32_t free_word = 0u;
    return atomic_compare_exchange_strong_explicit(word, &free_word, 1u, memory_order_acquire,
                                                   memory_order_relaxed);
}

/* Take the word: a bounded spin, then a sleep marked by 2, which the unlocker
 * sees. A worker that sleeps counts as stopped for a major. */
static void vader_mutex_take(_Atomic uint32_t* word) {
    for (int i = 0; i < VADER_MONITOR_SPINS; i++) {
        if (vader_mutex_try(word)) return;
        vader_os_spin_pause();
    }
    if (g_scheduler_trapping) vader_scheduler_abort_after_trap();
    while (atomic_exchange_explicit(word, 2u, memory_order_acquire) != 0u) {
        vader_gc_blocking(vader_mutex_sleep, (void*) word, NULL);
    }
}

/* Set once, as the pool starts, before any other worker runs. */
int vader_scheduler_pooled = 0;

void vader_scheduler_mutex_lock_pooled(void* mutex) {
    vader_worker_t* w = &vader_worker;
    if (w->in_monitor & VADER_HOLDS_MUTEX) {
        vader_trap("virtual threads: a mutex taken by a thread that holds one");
    }
    vader_mutex_take(vader_mutex_word(mutex));
    w->in_monitor |= VADER_HOLDS_MUTEX;
    vader_alloc_limit_refresh(w);
}

/* What the holder allocated is marked whole before another worker can take the
 * mutex and read it. */
void vader_scheduler_mutex_unlock_pooled(void* mutex) {
    vader_worker_t* w = &vader_worker;
    if (!(w->in_monitor & VADER_HOLDS_MUTEX)) {
        vader_trap("virtual threads: a mutex let go by a thread that does not hold it");
    }
    vader_gc_mark_monitor_born(w);
    w->in_monitor &= (uint8_t) ~VADER_HOLDS_MUTEX;
    vader_alloc_limit_refresh(w);
    _Atomic uint32_t* word = vader_mutex_word(mutex);
    if (atomic_exchange_explicit(word, 0u, memory_order_release) != 2u) return;
    vader_mutex_bucket_t* bucket = vader_mutex_bucket_of(word);
    vader_os_lock(bucket->lock);
    vader_os_cond_broadcast(bucket->cond);
    vader_os_unlock(bucket->lock);
}

/* The mutex sits in a root while the thread is away, since a minor may move it
 * meanwhile, and `mutex_away` names the root to the unwinding of a
 * cancellation (`vader_mutex_take_back`). */
void vader_scheduler_mutex_wait(void* mutex) {
    void** raw[1] = { &mutex };
    VADER_GC_PUSH_RAW(frame, raw, 1);
    vader_scheduler_mutex_unlock(mutex);
    vader_worker.running.mutex_away = &mutex;
    vader_scheduler_park();
    vader_worker.running.mutex_away = NULL;
    vader_scheduler_mutex_lock(mutex);
    VADER_GC_POP_FRAME(frame);
}

/* A thread cancelled in `vader_scheduler_mutex_wait` takes the mutex back
 * before its defers run: they unwind a body that held it. */
static void vader_mutex_take_back(void) {
    void** held = vader_worker.running.mutex_away;
    if (held == NULL) return;
    vader_worker.running.mutex_away = NULL;
    vader_scheduler_mutex_lock(*held);
}

/* ---- the lock -------------------------------------------------------------- */

/* The scheduler's part of the calling worker. */
static vader_scheduler_worker_t* vader_scheduler_me(void) {
    return &g_scheduler_workers[vader_worker.index];
}

/* A worker that waits for the lock does not stop for a major: an entry such as
 * `wake` holds young references the collector does not see. No worker waits
 * for a major holding the lock (`vader_gc_blocking`), so the wait is short. */
static void vader_scheduler_lock(void) {
    if (g_scheduler_guard == NULL) return;
    vader_scheduler_worker_t* me = vader_scheduler_me();
    if (me->holds_guard) vader_trap("virtual threads: the scheduler's lock taken twice");
    vader_os_lock(g_scheduler_guard);
    me->holds_guard = 1;
}

static void vader_scheduler_unlock(void) {
    if (g_scheduler_guard == NULL) return;
    vader_scheduler_me()->holds_guard = 0;
    vader_os_unlock(g_scheduler_guard);
    if (VADER_UNLIKELY(vader_worker.running.monitor_away)) {
        vader_worker.running.monitor_away = 0;
        vader_monitor_hold();
    }
}

/* A wait on the condition of a worker, as `vader_gc_blocking` runs it. */
typedef struct {
    vader_os_cond_t* cond;
    int64_t          timeout_ns;
} vader_scheduler_wait_t;

static void vader_scheduler_wait_cond(void* raw) {
    const vader_scheduler_wait_t* wait = (const vader_scheduler_wait_t*) raw;
    vader_os_cond_wait(wait->cond, g_scheduler_guard, wait->timeout_ns);
}

/* Let the lock go and wait on `w`'s condition, at most `timeout_ns` when not
 * negative, then take the lock again. A worker waiting counts as stopped for a
 * major. */
static void vader_scheduler_wait_on(vader_scheduler_worker_t* w, int64_t timeout_ns) {
    vader_scheduler_wait_t wait = { w->wake, timeout_ns };
    w->holds_guard = 0;
    vader_gc_blocking(vader_scheduler_wait_cond, &wait, g_scheduler_guard);
    w->holds_guard = 1;
}

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

static void vader_scheduler_grow_ready(vader_scheduler_worker_t* w) {
    size_t cap = 64u;
    if (w->cap != 0u) cap = w->cap * 2u;
    int64_t* grown = (int64_t*) malloc(cap * sizeof(int64_t));
    if (grown == NULL) vader_trap("virtual threads: out of memory");
    for (size_t i = 0; i < w->len; i++) grown[i] = w->ready[(w->head + i) & (w->cap - 1u)];
    free(w->ready);
    w->ready = grown;
    w->head = 0;
    w->cap = cap;
}

/* `w` stops resting, which it does while it has nothing to run. */
static void vader_scheduler_rouse(vader_scheduler_worker_t* w) {
    w->resting = 0;
    w->arriving = 1;
    g_scheduler_resting--;
    if (w->wake != NULL) vader_os_cond_signal(w->wake);
}

/* Make the live thread `thread` ready, once, on its worker, which stops
 * resting. */
static void vader_scheduler_enqueue(int64_t thread) {
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
    /* Queued already, or among the threads no worker started, which runs once
     * one takes it. */
    if (s->queued) return;
    vader_worker_t* owner = vader_virtual_thread_worker(thread);
    if (owner == NULL) vader_trap("virtual threads: a thread that has ended was made ready");
    s->queued = 1;
    vader_scheduler_worker_t* w = &g_scheduler_workers[owner->index];
    if (w->len == w->cap) vader_scheduler_grow_ready(w);
    w->ready[(w->head + w->len) & (w->cap - 1u)] = thread;
    w->len++;
    if (w->resting) vader_scheduler_rouse(w);
}

/* The first resting worker stops resting, if one rests. */
static void vader_scheduler_rouse_one(void) {
    for (uint32_t i = 0; i < g_scheduler_threads; i++) {
        vader_scheduler_worker_t* w = &g_scheduler_workers[i];
        if (!w->resting) continue;
        vader_scheduler_rouse(w);
        return;
    }
}

/* `thread`, which no worker started, waits among those any worker may take: a
 * resting worker stops resting to take it. */
static void vader_scheduler_offer(int64_t thread) {
    vader_scheduler_slot_of(thread)->queued = 1;
    vader_scheduler_rouse_one();
}

/* Whether `me` leaves the threads no worker started to a worker that has fewer
 * threads and nothing to run, or is on its way to look; a resting one is
 * roused. A thread stays on the worker that starts it: the first worker to look
 * must not take every thread launched together. */
static int vader_scheduler_leaves_unstarted(const vader_scheduler_worker_t* me) {
    for (uint32_t i = 0; i < g_scheduler_threads; i++) {
        vader_scheduler_worker_t* w = &g_scheduler_workers[i];
        if (w->tasks >= me->tasks) continue;
        if (w->arriving) return 1;
        if (!w->resting) continue;
        vader_scheduler_rouse(w);
        return 1;
    }
    return 0;
}

/* The oldest thread no worker started, made one of `me`'s, into `*thread`; 0
 * when none is, or when `me` leaves it to another worker. */
static int vader_scheduler_take_unstarted(vader_scheduler_worker_t* me, int64_t* thread) {
    if (g_scheduler_trapping || !vader_virtual_thread_has_unstarted()) return 0;
    if (vader_scheduler_leaves_unstarted(me)) return 0;
    *thread = vader_virtual_thread_adopt_unstarted();
    vader_scheduler_slot_of(*thread)->queued = 0;
    me->tasks++;
    return 1;
}

/* The next ready thread of `w` that has not ended, into `*thread`; 0 when none
 * is. */
static int vader_scheduler_pop_ready(vader_scheduler_worker_t* w, int64_t* thread) {
    while (w->len > 0u) {
        int64_t next = w->ready[w->head];
        w->head = (w->head + 1u) & (w->cap - 1u);
        w->len--;
        if (!vader_virtual_thread_is_live(next)) continue;
        if (g_scheduler_trapping && next != g_scheduler_trapped) continue;
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

static void vader_scheduler_arm(vader_scheduler_heap_t* heap, vader_scheduler_timer_t timer) {
    if (heap->len == heap->cap) {
        size_t cap = 64u;
        if (heap->cap != 0u) cap = heap->cap * 2u;
        vader_scheduler_timer_t* grown = (vader_scheduler_timer_t*) realloc(
            heap->timers, cap * sizeof(vader_scheduler_timer_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        heap->timers = grown;
        heap->cap = cap;
    }
    size_t i = heap->len++;
    while (i > 0u) {
        size_t parent = (i - 1u) / 2u;
        if (!vader_scheduler_timer_before(&timer, &heap->timers[parent])) break;
        heap->timers[i] = heap->timers[parent];
        i = parent;
    }
    heap->timers[i] = timer;
}

static void vader_scheduler_drop_first_timer(vader_scheduler_heap_t* heap) {
    vader_scheduler_timer_t last = heap->timers[--heap->len];
    if (heap->len == 0u) return;
    size_t i = 0;
    for (;;) {
        size_t child = 2u * i + 1u;
        if (child >= heap->len) break;
        if (child + 1u < heap->len
            && vader_scheduler_timer_before(&heap->timers[child + 1u], &heap->timers[child])) {
            child++;
        }
        if (!vader_scheduler_timer_before(&heap->timers[child], &last)) break;
        heap->timers[i] = heap->timers[child];
        i = child;
    }
    heap->timers[i] = last;
}

/* Whether `timer` still wakes its thread: the thread has not ended, nor slept
 * or parked again since. */
static int vader_scheduler_timer_wakes(const vader_scheduler_timer_t* timer) {
    if (!vader_virtual_thread_is_live(timer->thread)) return 0;
    return vader_scheduler_slot_of(timer->thread)->sleep == timer->sleep;
}

/* The nearest deadline of `heap`, into `*deadline`; 0 when it holds none. The
 * timers that wake nothing go first. */
static int vader_scheduler_next_deadline(vader_scheduler_heap_t* heap, int64_t* deadline) {
    while (heap->len > 0u && !vader_scheduler_timer_wakes(&heap->timers[0])) {
        vader_scheduler_drop_first_timer(heap);
    }
    if (heap->len == 0u) return 0;
    *deadline = heap->timers[0].deadline;
    return 1;
}

/* Make ready the threads whose timer of `heap` is due. */
static void vader_scheduler_fire_due_timers(vader_scheduler_heap_t* heap) {
    int64_t deadline = 0;
    if (!vader_scheduler_next_deadline(heap, &deadline)) return;
    int64_t now = heap->now();
    while (deadline <= now) {
        int64_t thread = heap->timers[0].thread;
        vader_scheduler_drop_first_timer(heap);
        vader_scheduler_enqueue(thread);
        if (!vader_scheduler_next_deadline(heap, &deadline)) return;
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

/* The deadline `nanos` from now on the clock of `heap`, INT64_MAX past its end. */
static int64_t vader_scheduler_deadline_in(const vader_scheduler_heap_t* heap, int64_t nanos) {
    int64_t now = heap->now();
    if (nanos < INT64_MAX - now) return now + nanos;
    return INT64_MAX;
}

/* ---- what the OS reports --------------------------------------------------- */

/* Whether `watch` still wakes its thread: parked in the park it was made for, or
 * not parked yet. Between a watch and its park, which are separate calls, another
 * worker may hear from the OS: the thread is then made ready ahead, and its park
 * returns at once. */
static int vader_scheduler_watch_wakes(const vader_scheduler_watch_t* watch) {
    if (!vader_virtual_thread_is_live(watch->thread)) return 0;
    uint32_t sleep = vader_scheduler_slot_of(watch->thread)->sleep;
    return watch->sleep == sleep || watch->sleep == sleep + 1u;
}

/* The cell a watch of `id` as `kind` is looked for from. */
static size_t vader_scheduler_watch_home(int kind, int64_t id) {
    uint64_t h = ((uint64_t) id * 4u + (uint64_t) kind) * 0x9E3779B97F4A7C15ull;
    return (size_t) (h >> 32) & (g_scheduler_watch_cell_cap - 1u);
}

/* The cell that holds the watch of `id` as `kind`, or the free cell it would
 * take. */
static size_t vader_scheduler_watch_cell(int kind, int64_t id) {
    size_t cell = vader_scheduler_watch_home(kind, id);
    while (g_scheduler_watch_cells[cell] != 0u) {
        const vader_scheduler_watch_t* w = &g_scheduler_watches[g_scheduler_watch_cells[cell] - 1u];
        if (w->kind == kind && w->id == id) break;
        cell = (cell + 1u) & (g_scheduler_watch_cell_cap - 1u);
    }
    return cell;
}

/* The watch of `id` as `kind`, NULL when there is none. */
static vader_scheduler_watch_t* vader_scheduler_watch_of(int kind, int64_t id) {
    if (g_scheduler_watch_len == 0u) return NULL;
    uint32_t held = g_scheduler_watch_cells[vader_scheduler_watch_cell(kind, id)];
    if (held == 0u) return NULL;
    return &g_scheduler_watches[held - 1u];
}

/* Free `cell`, and move back the watches a probe would no longer reach past it. */
static void vader_scheduler_free_watch_cell(size_t cell) {
    size_t mask = g_scheduler_watch_cell_cap - 1u;
    size_t next = cell;
    for (;;) {
        g_scheduler_watch_cells[cell] = 0u;
        for (;;) {
            next = (next + 1u) & mask;
            uint32_t held = g_scheduler_watch_cells[next];
            if (held == 0u) return;
            const vader_scheduler_watch_t* w = &g_scheduler_watches[held - 1u];
            size_t home = vader_scheduler_watch_home(w->kind, w->id);
            /* Stays when its home lies in (cell, next], going round. */
            if (((next - home) & mask) < ((next - cell) & mask)) continue;
            break;
        }
        g_scheduler_watch_cells[cell] = g_scheduler_watch_cells[next];
        cell = next;
    }
}

static void vader_scheduler_drop_watch(vader_scheduler_watch_t* w) {
    vader_scheduler_free_watch_cell(vader_scheduler_watch_cell(w->kind, w->id));
    vader_scheduler_watch_t* last = &g_scheduler_watches[--g_scheduler_watch_len];
    if (w == last) return;
    size_t cell = vader_scheduler_watch_cell(last->kind, last->id);
    *w = *last;
    g_scheduler_watch_cells[cell] = (uint32_t) (w - g_scheduler_watches) + 1u;
}

/* Room for one more watch, the cells at most half full. */
static void vader_scheduler_grow_watches(void) {
    if (g_scheduler_watch_len == g_scheduler_watch_cap) {
        size_t cap = 16u;
        if (g_scheduler_watch_cap != 0u) cap = g_scheduler_watch_cap * 2u;
        vader_scheduler_watch_t* grown = (vader_scheduler_watch_t*) realloc(
            g_scheduler_watches, cap * sizeof(vader_scheduler_watch_t));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        g_scheduler_watches = grown;
        g_scheduler_watch_cap = cap;
    }
    if ((g_scheduler_watch_len + 1u) * 2u <= g_scheduler_watch_cell_cap) return;
    size_t cells = g_scheduler_watch_cap * 2u;
    uint32_t* fresh = (uint32_t*) calloc(cells, sizeof(uint32_t));
    if (fresh == NULL) vader_trap("virtual threads: out of memory");
    free(g_scheduler_watch_cells);
    g_scheduler_watch_cells = fresh;
    g_scheduler_watch_cell_cap = cells;
    for (size_t i = 0; i < g_scheduler_watch_len; i++) {
        const vader_scheduler_watch_t* w = &g_scheduler_watches[i];
        g_scheduler_watch_cells[vader_scheduler_watch_cell(w->kind, w->id)] = (uint32_t) i + 1u;
    }
}

static void vader_scheduler_on_event(int kind, int64_t id) {
    vader_scheduler_watch_t* w = vader_scheduler_watch_of(kind, id);
    if (w == NULL) return;
    if (vader_scheduler_watch_wakes(w)) {
        vader_scheduler_slot_of(w->thread)->reported = 1;
        vader_scheduler_enqueue(w->thread);
    }
    vader_scheduler_drop_watch(w);
}

static int vader_scheduler_watched(int kind, int64_t id) {
    const vader_scheduler_watch_t* w = vader_scheduler_watch_of(kind, id);
    return w != NULL && vader_scheduler_watch_wakes(w);
}

/* Whether a watch still wakes a thread. The ones met that wake none go. */
static int vader_scheduler_watching(void) {
    while (g_scheduler_watch_len > 0u) {
        vader_scheduler_watch_t* last = &g_scheduler_watches[g_scheduler_watch_len - 1u];
        if (vader_scheduler_watch_wakes(last)) return 1;
        vader_scheduler_drop_watch(last);
    }
    return 0;
}

/* Whether a thread waits on the OS: it watches, or its wait has a bound. */
static int vader_scheduler_waits_on_os(void) {
    int64_t bound = 0;
    return vader_scheduler_watching() || vader_scheduler_next_deadline(&g_scheduler_bounds, &bound);
}

static void vader_scheduler_wait_events(void* timeout_ns) {
    vader_os_wait_events(*(const int64_t*) timeout_ns);
}

/* Ask the OS what it has, waiting at most `timeout_ns`. The threads it makes
 * ready, with those already ready on `w`, run before `w` asks again. A worker
 * that waits on the OS counts as stopped for a major: it holds the lock, but the
 * other workers all rest. */
static void vader_scheduler_ask_os(vader_scheduler_worker_t* w, int64_t timeout_ns) {
    if (timeout_ns == 0) {
        vader_os_wait_events(0);
    } else {
        vader_gc_blocking(vader_scheduler_wait_events, &timeout_ns, g_scheduler_guard);
    }
    g_scheduler_asked_at = vader_os_monotonic_ns();
    w->turn_left = w->len;
}

/* Every ready thread of `w` has run: ask the OS without waiting when it is due,
 * else begin another turn. */
static void vader_scheduler_end_turn(vader_scheduler_worker_t* w) {
    if (vader_os_monotonic_ns() - g_scheduler_asked_at >= VADER_SCHEDULER_ASK_EVERY_NS) {
        vader_scheduler_ask_os(w, 0);
        return;
    }
    w->turn_left = w->len;
}

/* The shorter of two waits, a negative one being without bound. */
static int64_t vader_scheduler_sooner(int64_t a, int64_t b) {
    if (a < 0) return b;
    if (b < 0 || a < b) return a;
    return b;
}

/* With no thread ready anywhere: wait for the nearest sleep to end, when
 * `sleeping`, or for the OS, when a thread waits on it, whichever comes first.
 * A thread that waits on the OS holds the virtual clock. */
static void vader_scheduler_idle(vader_scheduler_worker_t* w, int sleeping, int64_t deadline) {
    if (!vader_scheduler_waits_on_os()) {
        vader_scheduler_wait_until(deadline);
        return;
    }
    int64_t timeout_ns = -1;
    int64_t bound = 0;
    if (vader_scheduler_next_deadline(&g_scheduler_bounds, &bound)) {
        timeout_ns = vader_scheduler_nanos_until(bound);
    }
    if (sleeping && !g_scheduler_virtual_clock) {
        int64_t nanos = vader_scheduler_nanos_until(deadline);
        timeout_ns = vader_scheduler_sooner(timeout_ns, nanos);
    }
    vader_scheduler_ask_os(w, timeout_ns);
}

/* Wake a resting worker other than `w`, which polls in its place. */
static void vader_scheduler_hand_over_polling(const vader_scheduler_worker_t* w) {
    for (uint32_t i = 0; i < g_scheduler_threads; i++) {
        vader_scheduler_worker_t* other = &g_scheduler_workers[i];
        if (other == w || !other->resting) continue;
        vader_os_cond_signal(other->wake);
        return;
    }
}

/* With nothing to run on `w` while another worker runs a thread: wait until a
 * thread of `w` is made ready. One resting worker, the poller, also wakes when a
 * sleep or a bound ends, or when it is time to ask the OS for a thread that
 * watches it; it hands the polling over when it leaves for work. */
static void vader_scheduler_wait_for_work(vader_scheduler_worker_t* w) {
    uint32_t index = (uint32_t) (w - g_scheduler_workers);
    if (g_scheduler_poller != VADER_SCHEDULER_NO_POLLER) {
        vader_scheduler_wait_on(w, -1);
        return;
    }
    g_scheduler_poller = index;
    int64_t timeout_ns = -1;
    int watching = vader_scheduler_watching();
    if (watching) timeout_ns = VADER_SCHEDULER_ASK_EVERY_NS;
    int64_t deadline = 0;
    if (!g_scheduler_virtual_clock && vader_scheduler_next_deadline(&g_scheduler_sleeps, &deadline)) {
        timeout_ns = vader_scheduler_sooner(timeout_ns, vader_scheduler_nanos_until(deadline));
    }
    if (vader_scheduler_next_deadline(&g_scheduler_bounds, &deadline)) {
        timeout_ns = vader_scheduler_sooner(timeout_ns, vader_scheduler_nanos_until(deadline));
    }
    vader_scheduler_wait_on(w, timeout_ns);
    g_scheduler_poller = VADER_SCHEDULER_NO_POLLER;
    while (g_scheduler_closed) vader_scheduler_wait_on(w, -1);
    if (!w->resting) {
        vader_scheduler_hand_over_polling(w);
        return;
    }
    if (watching) vader_scheduler_ask_os(w, 0);
}

static void vader_scheduler_deadlock(void);

/* `w` has nothing to run: rest until it has. The last worker to rest keeps the
 * program: every thread waits, on a sleep, on the OS, or on another thread,
 * which is a deadlock. */
static void vader_scheduler_rest(vader_scheduler_worker_t* w) {
    while (g_scheduler_closed) vader_scheduler_wait_on(w, -1);
    w->resting = 1;
    g_scheduler_resting++;
    /* After a trap, the worker of the trapping thread keeps the program. */
    if (g_scheduler_resting < g_scheduler_threads && !g_scheduler_trapping) {
        vader_scheduler_wait_for_work(w);
    } else {
        int64_t deadline = 0;
        int sleeping = vader_scheduler_next_deadline(&g_scheduler_sleeps, &deadline);
        if (!sleeping && !vader_scheduler_waits_on_os()) vader_scheduler_deadlock();
        vader_virtual_thread_give_back_cold();
        vader_scheduler_idle(w, sleeping, deadline);
    }
    w->arriving = 0;
    if (!w->resting) return;
    w->resting = 0;
    g_scheduler_resting--;
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

/* Runs holding the lock. */
static void vader_scheduler_loop(void) {
    vader_scheduler_worker_t* me = vader_scheduler_me();
    for (;;) {
        /* A worker whose threads take turns without allocating stops here. */
        vader_gc_safepoint(g_scheduler_guard);
        vader_scheduler_fire_due_timers(&g_scheduler_sleeps);
        vader_scheduler_fire_due_timers(&g_scheduler_bounds);
        if (me->turn_left == 0u && me->len > 0u && vader_scheduler_watching()) {
            vader_scheduler_end_turn(me);
        }
        int64_t next = 0;
        if (vader_scheduler_pop_ready(me, &next)) {
            if (me->turn_left > 0u) me->turn_left--;
            /* A worker that left them to this one may rest by now, and the
             * thread may run without parking. */
            if (g_scheduler_resting > 0u && vader_virtual_thread_has_unstarted()) {
                vader_scheduler_rouse_one();
            }
            vader_virtual_thread_switch(next);
            continue;
        }
        if (vader_scheduler_take_unstarted(me, &next)) {
            vader_virtual_thread_switch(next);
            continue;
        }
        int64_t main = vader_virtual_thread_main();
        if (g_scheduler_exiting && vader_virtual_thread_count() == 0u
            && !vader_scheduler_slot_of(main)->queued) {
            vader_scheduler_enqueue(main);
            continue;
        }
        vader_scheduler_rest(me);
    }
}

/* What a worker of the pool other than the main thread runs: `arg` is its
 * index. It joins with the lock, which its scheduler holds from then on. */
static void vader_scheduler_worker_main(void* arg) {
    vader_worker.index = (uint32_t) (uintptr_t) arg;
    vader_virtual_thread_init_worker();
    vader_scheduler_lock();
    vader_gc_worker_init(&vader_worker);
    g_scheduler_joined++;
    vader_os_cond_signal(g_scheduler_workers[0].wake);
    vader_scheduler_loop();
}

/* The workers `VADER_THREADS` asks for, read once. */
static size_t vader_scheduler_pool_size(void) {
    static size_t threads = 0;
    if (threads == 0u) {
        threads = vader_gc_env_count("VADER_THREADS", 1u, 1u, VADER_WORKERS_MAX,
                                     "a whole number of workers, from 1 to 256");
    }
    return threads;
}

/* Start the workers `VADER_THREADS` asks for beside the main thread's, and
 * wait until each has joined. */
static void vader_scheduler_start_pool(void) {
    size_t threads = vader_scheduler_pool_size();
    if (threads == 1u) return;
    vader_gc_pool_start();
    vader_atom_pool_start((vader_u32_t) threads);
    g_scheduler_guard = vader_os_lock_new();
    g_monitor_guard = vader_os_lock_new();
    vader_mutex_buckets_start();
    vader_scheduler_pooled = 1;
    for (size_t i = 0; i < threads; i++) g_scheduler_workers[i].wake = vader_os_cond_new();
    g_scheduler_threads = (uint32_t) threads;
    vader_scheduler_lock();
    for (size_t i = 1; i < threads; i++) {
        vader_os_thread_start(vader_scheduler_worker_main, (void*) (uintptr_t) i);
    }
    while (g_scheduler_joined + 1u < g_scheduler_threads) {
        vader_scheduler_wait_on(&g_scheduler_workers[0], -1);
    }
    vader_scheduler_unlock();
}

/* ---- relayed calls --------------------------------------------------------- */

/* A system thread that makes the calls of `@c_blocking` C functions, one at a
 * time, while the task that made each parks on its bell. */
typedef struct vader_relay_helper {
    vader_os_lock_t*           lock;
    vader_os_cond_t*           work;
    /* The call to make, NULL while there is none. */
    void                     (*fn)(void* frame);
    void*                      frame;
    /* What the call left as its error. */
    int                        error;
    /* The bell's read end, which the task watches, and its write end. */
    int64_t                    bell;
    int64_t                    ringer;
    struct vader_relay_helper* next_idle;
} vader_relay_helper_t;

static bool vader_scheduler_wait_for(int kind, int64_t fd, int64_t nanos, int blocked);

/* Guards the idle helpers. */
static vader_os_lock_t* g_relay_guard = NULL;
static vader_relay_helper_t* g_relay_idle = NULL;

static void vader_relay_helper_main(void* raw) {
    vader_relay_helper_t* h = (vader_relay_helper_t*) raw;
    vader_os_lock(h->lock);
    for (;;) {
        while (h->fn == NULL) vader_os_cond_wait(h->work, h->lock, -1);
        void (*fn)(void* frame) = h->fn;
        void* frame = h->frame;
        vader_os_unlock(h->lock);
        fn(frame);
        int error = vader_os_error();
        vader_os_lock(h->lock);
        h->error = error;
        h->fn = NULL;
        vader_os_bell_ring(h->ringer);
    }
}

/* An idle helper, or a new one; NULL when no thread or bell can be made. */
static vader_relay_helper_t* vader_relay_take(void) {
    vader_os_lock(g_relay_guard);
    vader_relay_helper_t* h = g_relay_idle;
    if (h != NULL) g_relay_idle = h->next_idle;
    vader_os_unlock(g_relay_guard);
    if (h != NULL) return h;
    h = (vader_relay_helper_t*) calloc(1, sizeof(vader_relay_helper_t));
    if (h == NULL) return NULL;
    if (!vader_os_bell_new(&h->bell, &h->ringer)) {
        free(h);
        return NULL;
    }
    h->lock = vader_os_lock_new();
    h->work = vader_os_cond_new();
    vader_os_thread_start(vader_relay_helper_main, h);
    return h;
}

static void vader_relay_give_back(vader_relay_helper_t* h) {
    vader_os_lock(g_relay_guard);
    h->next_idle = g_relay_idle;
    g_relay_idle = h;
    vader_os_unlock(g_relay_guard);
}

/* Mark the running thread as waiting for a relayed call, or no longer. */
static void vader_relay_shield(uint8_t shielded) {
    vader_scheduler_lock();
    vader_scheduler_slot_of(vader_virtual_thread_current())->shielded = shielded;
    vader_scheduler_unlock();
}

int vader_relay_begin(int pins) {
    if (!g_scheduler_started) return 0;
    vader_scheduler_lock();
    int others = vader_virtual_thread_count() > 0u;
    vader_scheduler_unlock();
    if (!others) return 0;
    if (pins) vader_gc_empty_young(&vader_worker);
    return 1;
}

void vader_relay_call(int relay, void (*fn)(void* frame), void* frame) {
    vader_relay_helper_t* h = NULL;
    if (relay) h = vader_relay_take();
    if (h == NULL) {
        fn(frame);
        return;
    }
    /* Cancelled meanwhile, the thread would unwind and free the stack the
     * helper writes into. */
    vader_relay_shield(1);
    vader_os_lock(h->lock);
    h->frame = frame;
    h->fn = fn;
    vader_os_cond_signal(h->work);
    vader_os_unlock(h->lock);
    (void) vader_scheduler_wait_for(VADER_WATCH_READABLE, h->bell, -1, 0);
    vader_os_bell_take(h->bell);
    vader_os_lock(h->lock);
    int error = h->error;
    vader_os_unlock(h->lock);
    vader_relay_give_back(h);
    vader_relay_shield(0);
    vader_os_set_error(error);
}

/* ---- the watch on long calls ------------------------------------------------ */

/* How long, in milliseconds, a call into C may hold a worker whose other
 * threads wait before the runtime says so (`VADER_WARN_BLOCKING_MS`, 0 for
 * never). */
#define VADER_LONG_CALL_MS 100u
/* How many C functions it names at most, each once. */
#define VADER_LONG_CALL_NAMES 64u

static size_t g_long_call_ms = VADER_LONG_CALL_MS;

/* What the watch saw of each worker: the count of its calls into C, and when
 * that count last moved. */
static uint64_t g_long_call_seen[VADER_WORKERS_MAX];
static int64_t g_long_call_since[VADER_WORKERS_MAX];
static const char* g_long_call_named[VADER_LONG_CALL_NAMES];
static size_t g_long_call_named_len = 0;

/* Whether the watch named `name` already, which it then remembers. Compared by
 * its bytes: each unit of a split build spells it apart. */
static int vader_long_call_named(const char* name) {
    for (size_t i = 0; i < g_long_call_named_len; i++) {
        if (strcmp(g_long_call_named[i], name) == 0) return 1;
    }
    if (g_long_call_named_len == VADER_LONG_CALL_NAMES) return 1;
    g_long_call_named[g_long_call_named_len++] = name;
    return 0;
}

static void vader_long_call_report(const char* name, int64_t held_ms) {
    char detail[256];
    int n = snprintf(detail, sizeof detail,
                     "a call to `%s` has held its core for %lld ms while other tasks wait: "
                     "mark it `@c_blocking` if it waits on the world outside",
                     name, (long long) held_ms);
    if (n < 0) return;
    size_t len = (size_t) n;
    if (len >= sizeof detail) len = sizeof detail - 1u;
    vader_os_report_fatal("warning: ", detail, len);
}

/* Look at worker `w`, the `i`-th, at `now`: a call into C that has not moved
 * holds it up when another of its threads is ready, or waits for the clock or
 * the OS, which the worker no longer serves. Its fields are read without its
 * lock: a report may come one look late, never a wrong one. */
static void vader_long_call_look(size_t i, vader_worker_t* w, int64_t now) {
    int depth = __atomic_load_n(&w->foreign_depth, __ATOMIC_RELAXED);
    uint64_t calls = __atomic_load_n(&w->foreign_calls, __ATOMIC_RELAXED);
    if (depth <= 0 || calls != g_long_call_seen[i]) {
        g_long_call_seen[i] = calls;
        g_long_call_since[i] = now;
        return;
    }
    int64_t held_ms = (now - g_long_call_since[i]) / 1000000;
    if (held_ms < (int64_t) g_long_call_ms) return;
    vader_scheduler_worker_t* x = &g_scheduler_workers[w->index];
    size_t ready = __atomic_load_n(&x->len, __ATOMIC_RELAXED);
    uint32_t timed = __atomic_load_n(&x->timed_parks, __ATOMIC_RELAXED);
    if (ready == 0u && timed == 0u) return;
    const char* name = __atomic_load_n(&w->foreign_name, __ATOMIC_RELAXED);
    if (name == NULL || vader_long_call_named(name)) return;
    vader_long_call_report(name, held_ms);
}

static void vader_long_call_main(void* unused) {
    (void) unused;
    int64_t period_ns = (int64_t) g_long_call_ms * 1000000 / 2;
    for (;;) {
        vader_os_sleep_ns(period_ns);
        int64_t now = vader_os_monotonic_ns();
        size_t workers = __atomic_load_n(&g_worker_count, __ATOMIC_ACQUIRE);
        for (size_t i = 0; i < workers; i++) {
            vader_long_call_look(i, g_workers[i], now);
        }
    }
}

/* Start the watch, unless `VADER_WARN_BLOCKING_MS` is 0. */
static void vader_scheduler_watch_long_calls(void) {
    g_long_call_ms = vader_gc_env_count("VADER_WARN_BLOCKING_MS", VADER_LONG_CALL_MS, 0u,
                                        3600000u, "a number of milliseconds");
    if (g_long_call_ms == 0u) return;
    vader_os_thread_start(vader_long_call_main, NULL);
}

static void vader_scheduler_read_clock(void) {
    if (g_scheduler_clock_read) return;
    g_scheduler_clock_read = 1;
    g_scheduler_virtual_clock = getenv("VADER_VIRTUAL_CLOCK") != NULL;
}

/* Start the scheduler and the pool, once: on the main thread, before any lock
 * is taken. */
static void vader_scheduler_start(void) {
    if (g_scheduler_started) return;
    g_scheduler_started = 1;
    /* Lists the main thread's worker among the workers, whose threads the
     * scheduler walks. */
    if (!g_gc_initialized) vader_gc_init();
    vader_scheduler_read_clock();
    g_scheduler_slow_end = vader_gc_env_bool("VADER_SCHEDULER_SLOW_END");
    vader_virtual_thread_start_scheduler();
    vader_scheduler_fresh_slot(vader_virtual_thread_main(), 0u);
    vader_scheduler_start_pool();
    g_relay_guard = vader_os_lock_new();
    vader_scheduler_watch_long_calls();
}

/* Every entry of the scheduler from Vader takes the lock here, and lets it go
 * on its way out. */
static void vader_scheduler_enter(void) {
    vader_scheduler_start();
    vader_scheduler_lock();
}

/* ---- parking and cancelling ------------------------------------------------ */

static void vader_scheduler_park_locked(void);
static void vader_scheduler_cancel_locked(int64_t thread);
static void vader_scheduler_count_timed(int delta);

/* The thread whose children `vader_scheduler_cancel_child` cancels. */
static int64_t g_scheduler_launcher = 0;

static void vader_scheduler_cancel_child(int64_t thread) {
    if (vader_scheduler_slot_of(thread)->parent == g_scheduler_launcher) {
        vader_scheduler_cancel_locked(thread);
    }
}

/* Cancel the threads that `thread`, the running one, launched and that have
 * not ended, then wait for their ends: their defers run before its own. */
static void vader_scheduler_cancel_children(int64_t thread) {
    if (vader_scheduler_slot_of(thread)->children == 0u) return;
    g_scheduler_launcher = thread;
    vader_virtual_thread_each_live(vader_scheduler_cancel_child);
    vader_scheduler_slot_of(thread)->reaping = 1;
    while (vader_scheduler_slot_of(thread)->children > 0u) vader_scheduler_park_locked();
    vader_scheduler_slot_of(thread)->reaping = 0;
}

/* Cancel the running thread's children, run its pending defers, then end it.
 * The defers are Vader code, which runs without the lock. */
static void vader_scheduler_unwind(void) {
    int64_t thread = vader_virtual_thread_current();
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
    s->unwinding = 1;
    /* Cancelled in a timed park, it never comes back to the end of it, and its
     * defers may park otherwise. */
    s->on_clock_or_os = 0;
    vader_scheduler_cancel_children(thread);
    vader_scheduler_unlock();
    vader_mutex_take_back();
    vader_run_pending_defers();
    vader_scheduler_lock();
    vader_virtual_thread_end();
}

/* Whether the thread of slot `s` was cancelled and has not begun to unwind. One
 * that waits for a relayed call unwinds at its next park instead. */
static int vader_scheduler_must_unwind(const vader_scheduler_slot_t* s) {
    return s->cancelled && !s->unwinding && !s->shielded;
}

/* Leave the running thread, whose slot is `s`, for the scheduler; back when it
 * runs again. A thread cancelled before it started unwinds instead of leaving,
 * one cancelled meanwhile instead of returning. The slots move when a thread
 * is launched, so the slot is read again after the switch. */
static void vader_scheduler_block(vader_scheduler_slot_t* s) {
    if (g_scheduler_trapping && !s->queued && !s->on_clock_or_os) {
        vader_scheduler_abort_after_trap();
    }
    if (vader_scheduler_must_unwind(s)) vader_scheduler_unwind();
    int timed = s->on_clock_or_os;
    if (timed) vader_scheduler_count_timed(1);
    vader_monitor_step_away();
    vader_virtual_thread_switch_to_scheduler();
    if (timed) vader_scheduler_count_timed(-1);
    if (vader_scheduler_must_unwind(vader_scheduler_slot_of(vader_virtual_thread_current()))) {
        vader_scheduler_unwind();
    }
}

static void vader_scheduler_stop_for_trap(void) {
    /* A worker that waits for the lock does not stop. */
    if (g_scheduler_guard != NULL && vader_scheduler_me()->holds_guard) vader_scheduler_unlock();
    vader_gc_stop_for_trap();
    g_scheduler_trapped = vader_virtual_thread_current();
    g_scheduler_trapping = 1;
}

static void vader_scheduler_ending(void) {
    if (vader_worker.in_monitor & VADER_HOLDS_MUTEX) {
        vader_trap("virtual threads: a thread ended holding a mutex");
    }
    if (vader_worker.in_monitor) vader_trap("virtual threads: a thread ended holding the monitor");
    vader_scheduler_me()->tasks--;
    int64_t parent = vader_scheduler_slot_of(vader_virtual_thread_current())->parent;
    if (!vader_virtual_thread_is_live(parent)) return;
    vader_scheduler_slot_t* p = vader_scheduler_slot_of(parent);
    p->children--;
    if (p->children == 0u && p->reaping) vader_scheduler_enqueue(parent);
}

static void vader_scheduler_park_locked(void) {
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(vader_virtual_thread_current());
    s->sleep++;
    vader_scheduler_block(s);
}

/* Count a thread of the calling worker that parks for the clock or the OS, or
 * no longer does. */
static void vader_scheduler_count_timed(int delta) {
    vader_scheduler_worker_t* me = vader_scheduler_me();
    __atomic_store_n(&me->timed_parks, me->timed_parks + (uint32_t) delta, __ATOMIC_RELAXED);
}

/* Park the running thread, whose slot is `s`, for the clock or the OS. */
static void vader_scheduler_park_timed(vader_scheduler_slot_t* s) {
    int64_t thread = vader_virtual_thread_current();
    s->on_clock_or_os = 1;
    vader_scheduler_park_locked();
    vader_scheduler_slot_of(thread)->on_clock_or_os = 0;
}

static void vader_scheduler_cancel_locked(int64_t thread) {
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

/* Wake the running thread's next park once the OS reports `id`. */
static void vader_scheduler_watch(int kind, int64_t id) {
    int64_t thread = vader_virtual_thread_current();
    uint32_t sleep = vader_scheduler_slot_of(thread)->sleep + 1u;
    vader_scheduler_watch_t* held = vader_scheduler_watch_of(kind, id);
    /* Another thread waits for the same report, which wakes one thread. */
    int taken = held != NULL && held->thread != thread && vader_scheduler_watch_wakes(held);
    if (taken || !vader_os_watch(kind, id)) {
        int64_t deadline =
            vader_scheduler_deadline_in(&g_scheduler_bounds, VADER_SCHEDULER_REFUSED_WATCH_NS);
        vader_scheduler_arm(&g_scheduler_bounds, (vader_scheduler_timer_t) {
            deadline, ++g_scheduler_sleeps_begun, thread, sleep });
        return;
    }
    /* A thread watches the same `id` again at each park of a loop, woken
     * meanwhile by another watch: its entry moves to the new park. One left
     * by a thread that waits no more is taken over. */
    if (held != NULL) {
        held->thread = thread;
        held->sleep = sleep;
        return;
    }
    vader_scheduler_grow_watches();
    size_t cell = vader_scheduler_watch_cell(kind, id);
    g_scheduler_watches[g_scheduler_watch_len++] =
        (vader_scheduler_watch_t) { id, thread, sleep, (uint8_t) kind };
    g_scheduler_watch_cells[cell] = (uint32_t) g_scheduler_watch_len;
}

static int vader_scheduler_ready_now(int kind, int64_t fd) {
    if (kind == VADER_WATCH_WRITABLE) return vader_os_writable_now(fd);
    return vader_os_readable_now(fd);
}

/* Park until `fd` is as `kind` waits for, at most `nanos` when not negative:
 * false once they have passed. The wait ends too once `fd` is released
 * (`vader_scheduler_stop_waiting`): its number may name another descriptor by
 * then, which is not asked. `blocked` when the caller found `fd` would block. */
static bool vader_scheduler_wait_for_locked(int kind, int64_t fd, int64_t nanos, int blocked) {
    int64_t thread = vader_virtual_thread_current();
    vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
    int timed = nanos >= 0;
    int64_t deadline = vader_scheduler_deadline_in(&g_scheduler_bounds, nanos);
    uint64_t began = ++g_scheduler_sleeps_begun;
    int by_level = vader_os_reports_by_level(fd);
    int ask = !blocked || !by_level;
    s->released = 0;
    for (;;) {
        if (ask && vader_scheduler_ready_now(kind, fd)) return true;
        ask = 1;
        if (timed && g_scheduler_bounds.now() >= deadline) return false;
        s->reported = 0;
        vader_scheduler_watch(kind, fd);
        /* The timer ends the park the watch ends, whichever comes first. */
        if (timed) {
            uint32_t sleep = vader_scheduler_slot_of(thread)->sleep + 1u;
            vader_scheduler_arm(&g_scheduler_bounds,
                                (vader_scheduler_timer_t) { deadline, began, thread, sleep });
        }
        vader_scheduler_park_timed(s);
        /* The slot may have moved: a park lets other threads launch. */
        s = vader_scheduler_slot_of(thread);
        if (s->released) return true;
        if (s->reported && by_level) return true;
    }
}

/* With no other thread to run, a caller that found `fd` would block waits on
 * the system thread; any other then asks the system itself. */
static bool vader_scheduler_wait_alone(int kind, int64_t fd, int64_t nanos, int blocked) {
    if (!blocked) return true;
    return vader_os_block_until(kind, fd, nanos);
}

static bool vader_scheduler_wait_for(int kind, int64_t fd, int64_t nanos, int blocked) {
    /* Before the scheduler starts, no other thread runs. */
    if (!g_scheduler_started && !vader_os_only_reports(fd)) {
        return vader_scheduler_wait_alone(kind, fd, nanos, blocked);
    }
    vader_scheduler_enter();
    if (vader_virtual_thread_count() == 0u && !vader_os_only_reports(fd)) {
        vader_scheduler_unlock();
        return vader_scheduler_wait_alone(kind, fd, nanos, blocked);
    }
    bool ready = vader_scheduler_wait_for_locked(kind, fd, nanos, blocked);
    vader_scheduler_unlock();
    return ready;
}

/* ---- what Vader calls ------------------------------------------------------ */

int64_t vader_scheduler_spawn_numbered(vader_fn_t* entry, int64_t number) {
    vader_scheduler_enter();
    int64_t launcher = vader_virtual_thread_current();
    /* Launched under the monitor, its entry is old: any worker may run it. */
    int stealable = vader_worker.in_monitor;
    int64_t thread = 0;
    if (stealable) {
        /* Another worker may run it before the launcher lets the monitor go, and
         * write into what the launcher allocated under it: a minor of that worker
         * scans those objects only once they are marked whole. */
        vader_gc_mark_monitor_born(&vader_worker);
        thread = vader_virtual_thread_create_unstarted(entry);
    } else {
        thread = vader_virtual_thread_create(entry);
    }
    vader_scheduler_fresh_slot(thread, (uint64_t) number);
    vader_scheduler_slot_of(thread)->parent = launcher;
    vader_scheduler_slot_of(thread)->outlives = vader_scheduler_slot_of(launcher)->unwinding;
    vader_scheduler_slot_of(launcher)->children++;
    if (stealable) {
        vader_scheduler_offer(thread);
    } else {
        vader_scheduler_me()->tasks++;
        vader_scheduler_enqueue(thread);
    }
    vader_scheduler_unlock();
    return thread;
}

void vader_scheduler_park(void) {
    vader_scheduler_enter();
    vader_scheduler_park_locked();
    vader_scheduler_unlock();
}

void vader_scheduler_wake(int64_t thread) {
    vader_scheduler_enter();
    if (vader_virtual_thread_is_live(thread)) vader_scheduler_enqueue(thread);
    vader_scheduler_unlock();
}

/* A sleep with no other thread to run meanwhile, which needs no switch: a
   target without one sleeps too. */
static void vader_scheduler_sleep_alone(int64_t nanos) {
    vader_scheduler_read_clock();
    if (!g_scheduler_virtual_clock) {
        vader_os_sleep_ns(nanos);
        return;
    }
    g_scheduler_virtual_now = vader_scheduler_deadline_in(&g_scheduler_sleeps, nanos);
}

void vader_scheduler_sleep_for(int64_t nanos) {
    if (nanos <= 0) return;
    /* Before the scheduler starts, no other thread runs: nothing to start for. */
    if (!g_scheduler_started) {
        vader_scheduler_sleep_alone(nanos);
        return;
    }
    vader_scheduler_lock();
    if (vader_virtual_thread_count() == 0u) {
        vader_scheduler_unlock();
        vader_scheduler_sleep_alone(nanos);
        return;
    }
    int64_t thread = vader_virtual_thread_current();
    int64_t deadline = vader_scheduler_deadline_in(&g_scheduler_sleeps, nanos);
    uint64_t began = ++g_scheduler_sleeps_begun;
    /* A wake ends the park, not the sleep. */
    do {
        vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
        s->sleep++;
        vader_scheduler_arm(&g_scheduler_sleeps,
                            (vader_scheduler_timer_t) { deadline, began, thread, s->sleep });
        s->on_clock_or_os = 1;
        vader_scheduler_block(s);
        vader_scheduler_slot_of(thread)->on_clock_or_os = 0;
    } while (vader_scheduler_now() < deadline);
    vader_scheduler_unlock();
}

void vader_scheduler_watch_readable(int64_t fd) {
    vader_scheduler_enter();
    vader_scheduler_watch(VADER_WATCH_READABLE, fd);
    vader_scheduler_unlock();
}

void vader_scheduler_watch_exit(int64_t child) {
    vader_scheduler_enter();
    vader_scheduler_watch(VADER_WATCH_EXIT, child);
    vader_scheduler_unlock();
}

bool vader_scheduler_wait_readable_for(int64_t fd, int64_t nanos) {
    return vader_scheduler_wait_for(VADER_WATCH_READABLE, fd, nanos, 0);
}

void vader_scheduler_wait_readable(int64_t fd) {
    (void) vader_scheduler_wait_for(VADER_WATCH_READABLE, fd, -1, 0);
}

bool vader_scheduler_wait_writable_for(int64_t fd, int64_t nanos) {
    return vader_scheduler_wait_for(VADER_WATCH_WRITABLE, fd, nanos, 0);
}

void vader_scheduler_wait_writable(int64_t fd) {
    (void) vader_scheduler_wait_for(VADER_WATCH_WRITABLE, fd, -1, 0);
}

bool vader_scheduler_wait_blocked_read_for(int64_t fd, int64_t nanos) {
    return vader_scheduler_wait_for(VADER_WATCH_READABLE, fd, nanos, 1);
}

bool vader_scheduler_wait_blocked_write_for(int64_t fd, int64_t nanos) {
    return vader_scheduler_wait_for(VADER_WATCH_WRITABLE, fd, nanos, 1);
}

void vader_scheduler_stop_waiting(int64_t fd) {
    if (!g_scheduler_started) return;
    vader_scheduler_lock();
    static const int kinds[2] = { VADER_WATCH_READABLE, VADER_WATCH_WRITABLE };
    for (size_t i = 0; i < 2u; i++) {
        vader_scheduler_watch_t* w = vader_scheduler_watch_of(kinds[i], fd);
        if (w == NULL) continue;
        if (vader_scheduler_watch_wakes(w)) {
            vader_scheduler_slot_of(w->thread)->released = 1;
            vader_scheduler_enqueue(w->thread);
        }
        vader_scheduler_drop_watch(w);
    }
    vader_scheduler_unlock();
}

void vader_scheduler_cancel(int64_t thread) {
    vader_scheduler_enter();
    vader_scheduler_cancel_locked(thread);
    vader_scheduler_unlock();
}

int64_t vader_scheduler_current(void) {
    return vader_virtual_thread_current();
}

bool vader_scheduler_is_cancelled(void) {
    if (!g_scheduler_started) return false;
    vader_scheduler_lock();
    bool cancelled = vader_scheduler_slot_of(vader_virtual_thread_current())->cancelled != 0;
    vader_scheduler_unlock();
    return cancelled;
}

static bool vader_scheduler_is_leaving_locked(int64_t thread) {
    while (thread != vader_virtual_thread_main() && vader_virtual_thread_is_live(thread)) {
        vader_scheduler_slot_t* s = vader_scheduler_slot_of(thread);
        if (s->cancelled) return true;
        if (s->outlives) return false;
        thread = s->parent;
    }
    return false;
}

void vader_scheduler_task_ended(void) {
    vader_scheduler_enter();
    vader_scheduler_slot_of(vader_virtual_thread_current())->task_ended = 1;
    vader_scheduler_unlock();
}

bool vader_scheduler_is_leaving(int64_t thread) {
    if (!g_scheduler_started) return false;
    vader_scheduler_lock();
    bool leaving = vader_scheduler_is_leaving_locked(thread);
    vader_scheduler_unlock();
    return leaving;
}

/* A thread whose task ended may still run on another worker as `main` returns:
 * only what follows its task's end is left of it, and it is waited for. */
static void vader_scheduler_name_at_exit(int64_t thread) {
    if (thread == vader_virtual_thread_main() || vader_scheduler_is_leaving_locked(thread)) return;
    if (vader_scheduler_slot_of(thread)->task_ended) return;
    char name[32];
    vader_scheduler_name(thread, name, sizeof(name));
    const char* what = " still runs when main returns: cancelled";
    vader_os_report_fatal(name, what, strlen(what));
    g_scheduler_left_running = 1;
}

static void vader_scheduler_cancel_at_exit(int64_t thread) {
    if (thread != vader_virtual_thread_main()) vader_scheduler_cancel_locked(thread);
}

/* Once `main` returns, the other workers rest for good: the process tears down
 * what they would touch. */
int vader_scheduler_exit(int code) {
    if (!g_scheduler_started) return code;
    vader_scheduler_lock();
    if (vader_virtual_thread_count() == 0u) {
        g_scheduler_closed = 1;
        vader_scheduler_unlock();
        return code;
    }
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
    g_scheduler_closed = 1;
    vader_scheduler_unlock();
    if (code != 0 || !g_scheduler_left_running) return code;
    return 1;
}
