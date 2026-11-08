/* rt/internal.h: what the parts of the runtime share.
 *
 * Each part of rt/ includes this header first, and parses on its own against
 * it (tests/runtime_parts.test.ts): a part that reaches into another without a
 * declaration here fails that check. Declarations stay `static`, since the
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
#include <setjmp.h>   /* setjmp: flush callee-saved registers for the conservative old-gen stack scan */

/* ---- defer_traps.c ------------------------------------------------------- */

static vader_box_t* g_defer_stack;
static size_t g_defer_len;
static size_t g_defer_cap;
static int g_unwinding;

/* Run the running thread's pending defers, LIFO, until none is left. */
static void vader_run_pending_defers(void);

/* ---- gc_heap.c ----------------------------------------------------------- */

typedef struct {
    char* base;
    char* cur;
    char* end;
} vader_arena_t;

/* The young generation: a pair of semi-spaces that swap roles at each minor. */
typedef struct {
    vader_arena_t from;
    vader_arena_t to;
    char*         block;        /* malloc'd contiguous backing: span both semi-spaces */
    size_t        half_bytes;   /* size of one semi-space */
} vader_gen_t;

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

static vader_gen_t g_young;
static char* g_old_block;
static char* g_old_bump;
static size_t g_old_capacity;
static size_t g_old_live_bytes;
static size_t g_old_live_after_major;
static vader_old_region_t* g_old_regions;
static int g_gc_initialized;
static size_t g_total_collections;
static size_t g_total_copied;
static size_t g_total_alloc_bytes;
static size_t g_total_alloc_count;

static void vader_alloc_limit_refresh(void);
static size_t vader_gc_align(size_t n);
static int vader_in_young_from(const void* p);
static int vader_in_young(const void* p);
static int vader_in_old(const void* p);
static int vader_gc_env_bool(const char* env_name);
static void* vader_old_alloc(size_t bytes);
static void vader_old_foreach_live(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx);
static void vader_young_foreach(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx);
static void vader_old_sweep(void);
static VADER_NOINLINE void* vader_gc_alloc_slot_aligned(size_t bytes);

/* ---- gc_collect.c -------------------------------------------------------- */

/* Current cycle. Drives both `vader_gc_forward` (which arena to copy into)
 * and the collection counter (sub-cycles don't bump it independently). */
typedef enum {
    VADER_CYCLE_NONE = 0,         /* no cycle running */
    VADER_CYCLE_MINOR,            /* standalone minor */
    VADER_CYCLE_MAJOR_DRAIN,      /* minor running as the first step of a major */
    VADER_CYCLE_MAJOR,            /* mark phase of a major (old objects marked in place, never copied) */
} vader_cycle_t;

static uint8_t g_mark_value;
static char** g_gray_stack;
static size_t g_gray_len;
static size_t g_gray_cap;
static vader_cycle_t g_cycle;
static size_t g_card_count;
static uint8_t* g_card_shadow;

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

typedef struct {
    vader_u32_t         count;
    vader_u32_t         capacity;

    /* Open-addressing hash : intern lookup. `buckets[i]` holds the atom id
     * installed at hash slot `i` in its low 32 bits and the high 32 bits of
     * that atom's hash above them, or 0 for an empty slot. The empty atom
     * (id 0) is never installed, so an occupied slot is never 0. */
    uint64_t*    buckets;
    vader_u32_t  bucket_capacity;
    vader_u32_t  bucket_count;     /* occupied slots: for load factor check */

    /* Free list of tombstone indices (atoms freed by GC). Reused by the
     * next owner-style intern before growing `entries[]`. */
    vader_u32_t* free_list;
    vader_u32_t  free_count;
    vader_u32_t  free_capacity;

    /* Total bytes held by owner atoms: for profiling. */
    size_t       owner_bytes;
} vader_atom_table_t;

static vader_atom_table_t g_atoms;
static int g_atoms_initialized;

static vader_u16_t vader_atom_ascii_flag(const char* data, size_t len);
static void vader_atom_bucket_install(vader_atom_t a);

/* ---- arrays.c ------------------------------------------------------------ */

static vader_array_t* vader_array_resolve(vader_array_t* a);
static size_t vader_array_buf_bytes(size_t capacity, uint8_t element_kind);
static const uint8_t* vader_array_src_region(vader_array_t* src, size_t extra, uint8_t* out_kind, uint32_t* out_tag, size_t* out_elem_size);

/* ---- vthreads.c ---------------------------------------------------------- */

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
} vader_vt_roots_t;

/* The top of the running thread's stack, where its conservative scan stops. */
static char* vader_vt_stack_top(void);
/* Call `fn` with the roots of each thread alive but the running one. */
static void vader_vt_each_waiting(void (*fn)(const vader_vt_roots_t* roots));

/* What rt/sched.c drives. A handle names a thread until it ends; the main
 * thread has one from the start. One thread is the scheduler's, which runs
 * `vader_sched_loop` and which a thread switches to when it ends. */

/* Make the scheduler's thread, once. */
static void vader_vt_start_scheduler(void);
/* A thread that runs `entry` from the first switch to it; its handle. */
static int64_t vader_vt_create(vader_fn_t* entry);
/* Leave the running thread for the live thread `to`. */
static void vader_vt_switch(int64_t to);
/* Leave the running thread for the scheduler's. */
static void vader_vt_switch_to_scheduler(void);
/* End the running thread, from as deep in its stack as it is: never returns. */
static void vader_vt_end(void);
/* The running thread's handle, and the main thread's. */
static int64_t vader_vt_current(void);
static int64_t vader_vt_main(void);
/* Whether `handle` names a thread that has not ended. */
static int vader_vt_is_live(int64_t handle);
/* The index of a handle's thread: from 0, dense, reused once it ends. */
static uint32_t vader_vt_index(int64_t handle);
/* How many threads have not ended, the main thread and the scheduler's aside. */
static size_t vader_vt_threads(void);
/* Call `fn` with each thread that has not ended, the scheduler's aside. */
static void vader_vt_each_live(void (*fn)(int64_t handle));
/* Give back to the OS the stacks kept past the warm ones. */
static void vader_vt_give_back_cold(void);

/* ---- sched.c ------------------------------------------------------------- */

/* The scheduler's thread: runs the ready threads, never returns. */
static void vader_sched_loop(void);
/* On a new thread's stack, before its entry: false when it was cancelled
 * before it ever ran, and runs nothing. */
static int vader_sched_starting(void);
/* On an ending thread's stack, once it has run its last defer. */
static void vader_sched_ending(void);

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
/* Highest address of the main thread's C stack, NULL when unknown. The stack
 * grows down, so [current sp, base) covers every live frame. */
static char* vader_os_stack_base(void);
/* Put stdin, stdout and stderr in binary mode, on an OS that has another one.
 * Idempotent. */
static void vader_os_ensure_stdio_binary(void);
/* Write `vader: <what><detail>` on its own line, on stderr. */
static void vader_os_report_fatal(const char* what, const char* detail, size_t detail_len);

#endif
