/* rt/internal.h: what the parts of the runtime share.
 *
 * Each part of rt/ includes this header first, and parses on its own against
 * it (tools/repo_checks/runtime_parts.vader): a part that reaches into another
 * without a declaration here fails that check. Declarations stay `static`, since the
 * parts end up in one translation unit (vader_runtime.c). */

#ifndef VADER_RT_INTERNAL_H
#define VADER_RT_INTERNAL_H

/* POSIX and glibc's default extras, not `_GNU_SOURCE` (which vader.h sets for
 * emitted code): it also turns on glibc's C23 bindings, under which glibc 2.38
 * and later resolve `strtoul`, `strtoull` and `fscanf` to `__isoc23_*` symbols,
 * and a binary calling those needs glibc 2.38 to start. The one GNU function
 * the runtime calls is declared by hand in rt/os_posix.c. */
#if defined(__linux__) && !defined(_DEFAULT_SOURCE)
#  define _DEFAULT_SOURCE
#endif

#include "../vader.h"

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>
#include <setjmp.h>   /* setjmp: flush callee-saved registers for the conservative old-gen stack scan */

/* A lock of the OS, and a condition a thread waits on under it
 * (rt/os_posix.c, rt/os_windows.c). */
typedef struct vader_os_lock vader_os_lock_t;
typedef struct vader_os_cond vader_os_cond_t;

/* ---- defer_traps.c ------------------------------------------------------- */

/* Run the running thread's pending defers, LIFO, until none is left. */
static void vader_run_pending_defers(void);

/* ---- gc_heap.c ----------------------------------------------------------- */

/* One carved extent of the reservation. Small regions hold many fixed-size
 * slots of one class; large regions hold exactly one object. */
typedef struct vader_old_region {
    char*  base;          /* region start within the reservation */
    char*  cur;           /* bump high-water: next never-used slot (== end of used run) */
    char*  end;           /* region end (base + capacity) */
    size_t slot_size;     /* class slot size; for large = the object's aligned size */
    int    class_idx;     /* small: 0..NUM_CLASSES-1 ; large: -1 */
    uint8_t freed;        /* large only: currently in a large free bin */
    struct vader_old_region* next;       /* global region list (sweep + walks) */
    struct vader_old_region* free_next;  /* large free bin link */
} vader_old_region_t;

/* The most workers a program runs, the main thread's included. */
#define VADER_WORKERS_MAX 256u

static char* g_old_block;
static char* g_old_bump;
static size_t g_old_capacity;
static size_t g_old_live_bytes;
static size_t g_old_live_after_major;
static vader_old_region_t* g_old_regions;
static int g_gc_initialized;
static vader_worker_t* g_workers[VADER_WORKERS_MAX];
static size_t g_worker_count;

static void vader_alloc_limit_refresh(vader_worker_t* w);
static void vader_alloc_limit_refresh_all(void);
/* Give `w` a heap of its own and list it among the workers. */
static void vader_gc_worker_init(vader_worker_t* w);
/* Read the whole number in `env_name`, from `min` to `max`; `fallback` when
 * unset or empty, a trap naming `expected` for anything else. */
static size_t vader_gc_env_count(const char* env_name, size_t fallback, size_t min, size_t max,
                                 const char* expected);
static size_t vader_gc_align(size_t n);
/* Whether `p` lies in the young generation of `w`: its from-space, or either
 * half. */
static int vader_in_young_from(const vader_worker_t* w, const void* p);
static int vader_in_young(const vader_worker_t* w, const void* p);
static int vader_in_old(const void* p);
static int vader_gc_env_bool(const char* env_name);
static void* vader_old_alloc(size_t bytes);
/* With several workers, promotions into old take a lock. */
static void vader_old_pool_start(void);
static void vader_old_foreach_live(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx);
static void vader_young_foreach(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx);
static void vader_old_sweep(void);
static VADER_NOINLINE void* vader_gc_alloc_slot_aligned(size_t bytes);

/* ---- gc_collect.c -------------------------------------------------------- */

static uint8_t g_mark_value;
static size_t g_card_count;
/* The groups of `cards` cards. */
static inline size_t vader_card_groups_of(size_t cards) {
    return (cards + VADER_CARD_GROUP - 1u) / VADER_CARD_GROUP;
}

/* Mark `h` live in the current epoch once its object is written whole: a
 * minor of another worker that reads the mark by `vader_obj_is_published` sees
 * every write made before. */
static inline void vader_obj_publish_mark(vader_obj_header_t* h) {
    __atomic_store_n(&h->mark, g_mark_value, __ATOMIC_RELEASE);
}

/* Whether `h` is marked in the current epoch, with the writes its publication
 * covers when it is. An acquire load and not a fence: ThreadSanitizer models
 * the one and not the other. */
static inline int vader_obj_is_published(const vader_obj_header_t* h) {
    return __atomic_load_n(&h->mark, __ATOMIC_ACQUIRE) == g_mark_value;
}

/* A minor over the young generation of `w`, with its roots. */
static void vader_gc_minor(vader_worker_t* w);
/* What the `VADER_GC_VERIFY` walk does with each slot it reads. */
static void vader_gc_verify_reach(vader_worker_t* w, void* p);
/* Make ready, once the pool starts, what a major needs to stop the other
 * workers. */
static void vader_gc_pool_start(void);
/* Run `op(arg)`, a wait of the runtime, as a stretch where the calling worker
 * counts as stopped for a major: its registers on its stack, which the
 * collector reads from there up. It returns once no major runs. `op` runs no
 * Vader code and allocates nothing. `held` is a lock `op` returns holding, or
 * NULL: it is let go while a major runs. With one worker it only runs `op`. */
static void vader_gc_blocking(void (*op)(void* arg), void* arg, vader_os_lock_t* held);
/* Store every callee-saved register of the calling frame on its stack, in
 * `regs` among others, for a conservative scan from `&regs` up: `setjmp`
 * alone mangles some. POSIX `_setjmp` leaves the signal mask alone, which
 * `setjmp` saves on Darwin by two system calls; Windows has no such mask. */
#if defined(_WIN32)
#  define VADER_SETJMP(regs) setjmp(regs)
#else
#  define VADER_SETJMP(regs) _setjmp(regs)
#endif
#define VADER_SPILL_REGISTERS(regs) do { __builtin_unwind_init(); (void) VADER_SETJMP(regs); } while (0)
/* Stop here if another worker collects, letting go of `held` meanwhile, a
 * lock the caller holds, or NULL (`vader_gc_blocking`). */
static void vader_gc_safepoint(vader_os_lock_t* held);
/* Leave the young generation of `w`, the calling worker, empty. */
static void vader_gc_empty_young(vader_worker_t* w);
/* Mark live what `w` allocated in old under the monitor, as it lets it go. */
static void vader_gc_mark_monitor_born(vader_worker_t* w);
/* Call `fn` with the range of each C stack a conservative scan reads during a
 * major: the stack each worker runs on (the collector's from its spilled
 * registers, another's from where it stopped), and each waiting thread's. */
static void vader_gc_each_stack(void (*fn)(char* lo, char* hi, void* ctx), void* ctx);
/* Call `fn` with the precise roots of each thread of `x`: the one it runs, then
 * those that wait. */
static void vader_gc_each_root_thread(const vader_worker_t* x,
                                      void (*fn)(vader_gc_frame_t* top, vader_box_t* defers,
                                                 size_t ndefers, void* ctx),
                                      void* ctx);
/* A major waits for every other worker to stop. Read without a lock by the
 * slow path of the allocation. */
static _Atomic int g_gc_stop_requested;

static size_t vader_gc_obj_size(void* obj, uint32_t type_index);
static void* vader_gc_force_tenure(void* obj);

/* ---- gc_diag.c ----------------------------------------------------------- */

#define VADER_GC_POISON_BYTE 0xA5

static int g_gc_stress;
static int g_gc_stress_major;
static int g_gc_stress_switch;
static int g_gc_check_box;
static int g_gc_no_cstack_scan;
static int g_gc_scan_all_old;
static int g_gc_poison;
static int g_gc_verify;
static int g_gc_profile;

static void vader_alloc_by_type_dump(void);
static VADER_NOINLINE void vader_gc_check_object_alignment(const void* obj, uint32_t type_index);
static void vader_gc_box_tag_corrupt(const vader_box_t* boxp);
static void vader_gc_old_histogram(void);
static void vader_gc_profile_dump(void);

/* ---- atoms.c ------------------------------------------------------------- */

/* The atom table, which interns strings (`docs/RUNTIME.md`). It is grow-only in
 * indices: atoms minted at runtime can be collected (their bytes freed, slot
 * tombstoned) but the `entries[]` array never shrinks, so every `vader_atom_t`
 * value ever observed in a live slot stays a valid lookup target, just possibly
 * with reused content. Comptime atoms are PERM-flagged and never collected. */

/* The hash index of the table: open addressing, linear probing. `slots[i]` holds
 * the atom id installed at slot `i` in its low 32 bits and the low 32 bits of
 * that atom's hash above them, or 0 for an empty slot. The empty atom (id 0) is
 * never installed, so an occupied slot is never 0. A slot is written once its
 * entry is whole, and read without a lock. */
typedef struct vader_atom_index {
    /* What `free` takes: the index sits on a 64-byte boundary inside it. */
    void*       block;
    /* The index this one replaced, which a reader may still probe: freed at the
     * next sweep, when no reader runs. */
    struct vader_atom_index* retired;
    vader_u32_t capacity;          /* a power of two */
    _Atomic uint64_t slots[];
} vader_atom_index_t;

/* What the writers of the index share, away from what readers read. */
typedef struct {
    /* The lock of a growth, one at a time. */
    _Alignas(64) _Atomic vader_u32_t busy;
    /* The slots of the index taken or reserved, the workers' batches included:
     * kept under 3/4 of its capacity, so a probe always meets an empty slot. */
    _Atomic vader_u32_t used;
    /* 1 while a growth copies the index: no writer enters it then. Read by
     * every writer, written by a growth alone: on a line of its own, apart from
     * `used`, which each new batch writes. */
    _Alignas(64) _Atomic vader_u32_t growing;
    /* Moves on at each growth and each sweep, which count `used` again from the
     * slots: a batch reserved before is void. */
    _Atomic vader_u32_t epoch;
} vader_atom_writer_t;

/* What one worker publishes with, on a line of its own. */
typedef struct {
    /* Raised while it publishes in the index: a growth waits for every flag to
     * fall. */
    _Alignas(64) _Atomic vader_u32_t inserting;
    /* The slots it reserved and has not taken yet, in the epoch `batch_epoch`
     * of the writers: void in a later one. Read and written by this worker
     * alone. */
    vader_u32_t batch;
    vader_u32_t batch_epoch;
} vader_atom_inserter_t;

typedef struct {
    /* Ids handed out so far, the tombstones and those workers hold included:
     * every id below it names an entry. Written under the lock of the ids. */
    vader_u32_t         count;
    vader_u32_t         capacity;

    /* The index, read without a lock, as one word: its address with the log2
     * of its capacity in the low six bits, which the alignment of the index
     * leaves free. A reader loads it apart from the hash it probes with, so the
     * two loads overlap. On a line of its own, away from `count`, which each
     * batch of ids writes. */
    _Alignas(64) _Atomic uintptr_t index;
    vader_atom_writer_t   writer;
    /* By `vader_worker.index`, with several workers. */
    vader_atom_inserter_t inserters[VADER_WORKERS_MAX];

    /* Free list of tombstone indices (atoms freed by GC), handed to the workers
     * by batches before `entries[]` grows. */
    vader_u32_t* free_list;
    vader_u32_t  free_count;
    vader_u32_t  free_capacity;
} vader_atom_table_t;

static vader_atom_table_t g_atoms;
static int g_atoms_initialized;

static vader_u16_t vader_atom_ascii_flag(const char* data, size_t len);
/* With several workers: entries that never move, a lock over the growths of
 * the index and one over the ids. */
static void vader_atom_pool_start(vader_u32_t workers);
static vader_atom_index_t* vader_atom_index_current(void);
static void vader_atom_index_put(vader_atom_index_t* index, vader_atom_t a, uint64_t hash);
static void vader_atom_index_free(vader_atom_index_t* index);

/* ---- arrays.c ------------------------------------------------------------ */

static vader_array_t* vader_array_resolve(vader_array_t* a);
static size_t vader_array_buf_bytes(size_t capacity, uint8_t element_kind);
static const uint8_t* vader_array_src_region(vader_array_t* src, size_t extra, uint8_t* out_kind, uint32_t* out_tag, size_t* out_elem_size);

/* ---- copy.c -------------------------------------------------------------- */

/* Whether a boxed value holds an object: a buffer, or a value of a heap kind. */
static int vader_box_holds_object(vader_box_t value);

/* ---- virtual_threads.c --------------------------------------------------- */

/* What the collector reads of a thread that is not running: its shadow-stack
 * frames, its pending defers, and the stack range [sp, hi) that holds its
 * frames and the registers its last switch stored. `sp` and `hi` are NULL for
 * a thread whose stack holds nothing yet. */
typedef struct {
    vader_gc_frame_t* top;
    vader_box_t*      defers;
    size_t            ndefers;
    char*             sp;
    char*             hi;
} vader_virtual_thread_roots_t;

/* The top of the stack of the thread `w` runs, where its conservative scan
 * stops. */
static char* vader_virtual_thread_stack_top(const vader_worker_t* w);
/* Call `fn` with the roots of each thread of `w` alive but the one it runs. */
static void vader_virtual_thread_each_waiting(const vader_worker_t* w,
                                              void (*fn)(const vader_virtual_thread_roots_t*, void* ctx),
                                              void* ctx);
/* Call `fn` with the roots of each thread no worker started yet. */
static void vader_virtual_thread_each_unstarted(void (*fn)(const vader_virtual_thread_roots_t*, void* ctx),
                                                void* ctx);

/* What rt/scheduler.c drives. A handle names a thread until it ends; the main
 * thread has one from the start. One thread is the scheduler's, which runs
 * `vader_scheduler_loop` and which a thread switches to when it ends. */

/* Make the scheduler's thread, once. */
static void vader_virtual_thread_start_scheduler(void);
/* On a system thread of the pool other than the main thread: its own stack
 * runs its scheduler. */
static void vader_virtual_thread_init_worker(void);
/* The worker that runs the live thread `handle`, NULL while no worker started it. */
static vader_worker_t* vader_virtual_thread_worker(int64_t handle);
/* A thread of the calling worker that runs `entry` from the first switch to
 * it; its handle. */
static int64_t vader_virtual_thread_create(vader_fn_t* entry);
/* A thread that runs `entry` and that no worker runs yet: the first to take it
 * runs it to its end. Its handle. */
static int64_t vader_virtual_thread_create_unstarted(vader_fn_t* entry);
/* Whether a thread waits that no worker started. */
static int vader_virtual_thread_has_unstarted(void);
/* Make the oldest thread no worker started one of the calling worker's: its
 * handle. One waits. */
static int64_t vader_virtual_thread_adopt_unstarted(void);
/* Leave the running thread for the live thread `to`. */
static void vader_virtual_thread_switch(int64_t to);
/* Leave the running thread for the scheduler's. */
static void vader_virtual_thread_switch_to_scheduler(void);
/* End the running thread, from as deep in its stack as it is: never returns. */
static void vader_virtual_thread_end(void);
/* The running thread's handle, and the main thread's. */
static int64_t vader_virtual_thread_current(void);
static int64_t vader_virtual_thread_main(void);
/* Whether `handle` names a thread that has not ended. */
static int vader_virtual_thread_is_live(int64_t handle);
/* The index of a handle's thread: from 0, dense, reused once it ends. */
static uint32_t vader_virtual_thread_index(int64_t handle);
/* How many threads have not ended, the main thread and the scheduler's aside. */
static size_t vader_virtual_thread_count(void);
/* Call `fn` with each thread that has not ended, the scheduler's aside. */
static void vader_virtual_thread_each_live(void (*fn)(int64_t handle));
/* Give back to the OS the stacks kept past the warm ones. */
static void vader_virtual_thread_give_back_cold(void);

/* ---- scheduler.c --------------------------------------------------------- */

/* The bits of `vader_worker_t.in_monitor`, one per kind of lock the running
 * thread holds. */
#define VADER_HOLDS_MONITOR 1u
#define VADER_HOLDS_MUTEX   2u

/* The scheduler's thread: runs the ready threads, never returns. */
static void vader_scheduler_loop(void);
/* On an ending thread's stack, once it has run its last defer. */
static void vader_scheduler_ending(void);
static int g_scheduler_slow_end;
/* Take and let go the scheduler's lock, which guards every state of the
 * scheduler and of the threads. A worker holds it from an entry of the
 * scheduler to its return, across the switches in between: a thread a switch
 * goes to lets it go once it returns to its own code. With one worker there is
 * no lock to take. */
static void vader_scheduler_lock(void);
static void vader_scheduler_unlock(void);

/* What a thread waits for the OS to report: a descriptor that reads without
 * blocking or has reached its end, a child process that has ended, a
 * descriptor that takes a write without blocking. */
enum { VADER_WATCH_READABLE = 0, VADER_WATCH_EXIT = 1, VADER_WATCH_WRITABLE = 2 };
/* The OS reports `id`, watched as `kind`: wake the thread that waits for it. */
static void vader_scheduler_on_event(int kind, int64_t id);
/* Whether a thread still waits for the OS to report `id`, watched as `kind`. */
static int vader_scheduler_watched(int kind, int64_t id);

/* ---- os_posix.c, os_windows.c -------------------------------------------- */

/* What the runtime asks of the OS it runs on. Each of the two parts defines all
 * of it, and the unity includes the part of the OS it builds for. A new target
 * defines these, the accessors vader.h declares for its OS, and the FFI's
 * library loader (`vader_ffi_open`, `vader_ffi_open_path`, `vader_ffi_symbol`). */

/* Reserve `bytes` of address space, whose pages cost no memory until committed
 * and written. NULL when the address space runs out. */
static char* vader_os_reserve(size_t bytes);
/* Make [base, base + bytes) of a reservation writable. 0 when the OS refuses. */
static int vader_os_commit(char* base, size_t bytes);
/* Hand the memory under [base, end) back to the OS where it can be, the range
 * staying reserved and writable. What it held is undefined afterwards. */
static void vader_os_discard(char* base, char* end);
/* Give back a whole reservation. */
static void vader_os_release(char* base, size_t bytes);
/* Physical RAM in bytes, 0 when the OS does not say. */
static size_t vader_os_physical_ram(void);
/* Nanoseconds on a clock that never goes back, from an origin of its own. */
static int64_t vader_os_monotonic_ns(void);
/* Block the process's thread for at least `ns` nanoseconds. */
static void vader_os_sleep_ns(int64_t ns);
/* Have the OS report once, through `vader_scheduler_on_event`, that `id` is as
 * `kind` waits for: the descriptor reads without blocking or has reached its
 * end, the child process has ended, the descriptor takes a write without
 * blocking. 0 when it will not watch `id`. */
static int vader_os_watch(int kind, int64_t id);
/* Wait at most `timeout_ns` for what the OS watches, not at all for 0 and
 * without bound for a negative one, and report what it has. */
static void vader_os_wait_events(int64_t timeout_ns);
/* Whether a read of `fd` would not block: it holds data, has reached its end,
 * or fails. */
static int vader_os_readable_now(int64_t fd);
/* Whether a write to `fd` would not block: it has room, or fails. */
static int vader_os_writable_now(int64_t fd);
/* Whether the OS only reports `id`, and cannot be asked whether it is ready: a
 * wait on it parks even when no other thread runs, since its caller has
 * nothing to wait on by itself. */
static int vader_os_only_reports(int64_t id);
/* Highest address of the calling system thread's C stack, NULL when unknown.
 * The stack grows down, so [current sp, base) covers every live frame. */
static char* vader_os_stack_base(void);
static vader_os_lock_t* vader_os_lock_new(void);
static void vader_os_lock(vader_os_lock_t* lock);
static void vader_os_unlock(vader_os_lock_t* lock);
/* Take `lock` when it is free: 1, else 0 at once. */
static int vader_os_try_lock(vader_os_lock_t* lock);
/* Give the processor to another thread, as a lock that spun too long does. */
static void vader_os_yield(void);
/* Tell the processor that this thread spins on a lock. */
static void vader_os_spin_pause(void);
static vader_os_cond_t* vader_os_cond_new(void);
/* Let `lock` go and wait for `cond`, at most `timeout_ns` when not negative,
 * then take `lock` again. It may return before either. */
static void vader_os_cond_wait(vader_os_cond_t* cond, vader_os_lock_t* lock, int64_t timeout_ns);
static void vader_os_cond_signal(vader_os_cond_t* cond);
static void vader_os_cond_broadcast(vader_os_cond_t* cond);
/* Run `entry(arg)` on a new system thread, which nothing joins. Its C stack,
 * `VADER_OS_THREAD_STACK_BYTES`, runs a worker's scheduler: the virtual threads
 * have stacks of their own. */
static void vader_os_thread_start(void (*entry)(void* arg), void* arg);
#define VADER_OS_THREAD_STACK_BYTES (1024u * 1024u)
/* What a thread of `vader_os_thread_start` runs. */
typedef struct {
    void (*entry)(void* arg);
    void* arg;
} vader_os_thread_start_t;
/* Put stdin, stdout and stderr in binary mode, on an OS that has another one.
 * Idempotent. */
static void vader_os_ensure_stdio_binary(void);
/* Catch SIGPIPE, on an OS that has it, with a handler that does nothing: a write
 * whose reader is gone then fails with EPIPE instead of ending the program.
 * Caught rather than ignored, so an `exec` gives a child the default back.
 * Idempotent. */
static void vader_os_catch_broken_pipes(void);
/* Write `vader: <what><detail>` on its own line, on stderr. */
static void vader_os_report_fatal(const char* what, const char* detail, size_t detail_len);

#endif
