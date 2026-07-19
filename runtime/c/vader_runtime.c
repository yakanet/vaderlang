/* Vader native runtime — implementation. See `vader.h` for the public API.
 *
 * Memory model: generational GC — a copying (Cheney) young generation and a
 * NON-MOVING mark-sweep old generation. Young is a pair of semi-spaces;
 * `vader_gc_alloc` bumps the young from-space; on overflow, `vader_minor_collect`
 * copies young survivors to young to-space (or promotes them, once `age` reaches
 * the tenure threshold, into the old slab — a single lazily-committed reservation
 * carved into size-class regions, see "slab old-gen" below). A
 * `vader_major_collect` drains young, then marks the live old set (roots + young
 * survivors + a conservative C-stack scan) and sweeps the dead in place — old
 * objects never move. `vader_old_maybe_major` fires a major once dead old
 * accumulates past a headroom factor. Cross-generation references are tracked by
 * a card table written from the C-emit-issued `VADER_WRITE_BARRIER` macro and
 * consumed as additional roots by minor.
 */

#include "vader.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <setjmp.h>   /* setjmp — flush callee-saved registers for the conservative old-gen stack scan */

#include <errno.h>

#if defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#  include <io.h>      /* _setmode, _fileno */
#  include <fcntl.h>   /* _O_BINARY */
#else
#  include <pthread.h> /* pthread_get_stackaddr_np / pthread_attr_getstack */
#  include <spawn.h>
#  include <sys/wait.h>
#  include <unistd.h>
#  include <fcntl.h>    /* fcntl F_SETFL O_NONBLOCK — non-blocking spawn poll */
#  include <poll.h>     /* poll — stdin readiness for the LSP debounce */
#  include <sys/resource.h> /* getrusage — peak RSS for the profiler */
#  include <sys/mman.h> /* mmap / munmap / madvise — non-moving old-gen reservation */
#  ifndef MAP_ANONYMOUS
#    define MAP_ANONYMOUS MAP_ANON
#  endif
#  if defined(__APPLE__)
#    include <mach-o/dyld.h> /* _NSGetExecutablePath */
#    include <mach/mach.h>   /* task_info — current RSS for the profiler */
#  endif
extern char** environ;
#endif

/* ----------------------------------------------------------------- vtable
 *
 * Weak fallback definitions for the per-module vtable globals declared in
 * `vader.h`. Empty by default; the C emit will override with strong
 * symbols once it learns to emit vtables (Phase 0 task P0-3). Until then,
 * `vader_virtual_dispatch` returns NULL for every tag — safe because no
 * existing code calls it. */
__attribute__((weak)) const vader_vtable_t* const vader_vtable_table[1] = { NULL };
__attribute__((weak)) const size_t                vader_vtable_count    = 0;

/* ----------------------------------------------------------------- defer
 *
 * Global LIFO of pending `defer` closures. The C-emit appends to it via
 * `vader_defer_push` at every `defer X` site, then drains the last N
 * entries via `vader_defer_pop_exec` at each normal exit (return /
 * break / continue / block fall-through).
 *
 * GC roots — every entry's `payload.obj` is a `vader_fn_t*` whose env
 * pointer captures heap-promoted cells. The GC's frame-walking scan
 * also walks the defer stack so captures stay live between push and
 * exec.
 *
 * Panic-unwind : a trap runs the pending defers before aborting. No
 * setjmp/longjmp is needed — `g_defer_stack` already holds exactly the
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
 * (`vader_fn_erased_sig_0_t` from the per-module emit lines up — it returns
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

/* ----------------------------------------------------------------- gc arena */

#define VADER_GC_ALIGN 8u

typedef struct {
    char* base;
    char* cur;
    char* end;
} vader_arena_t;

/* A generation is just a pair of semi-spaces. Both pairs are backed by a
 * single contiguous malloc per generation so the card table can index by
 * `(ptr - base) / VADER_CARD_BYTES` without worrying about the swap. */
typedef struct {
    vader_arena_t from;
    vader_arena_t to;
    char*         block;        /* malloc'd contiguous backing — span both semi-spaces */
    size_t        half_bytes;   /* size of one semi-space */
} vader_gen_t;

static vader_gen_t g_young = { {NULL,NULL,NULL}, {NULL,NULL,NULL}, NULL, 0 };

/* ---------- non-moving mark-sweep old generation (slab) ----------
 *
 * The old generation is NOT a copying semi-space pair. It is a single big
 * address-space reservation (mmap / VirtualAlloc, lazily committed: untouched
 * pages cost ~0 RSS) carved into class-homogeneous regions by a global bump.
 * Objects never move, so:
 *   - membership is one range check over [g_old_block, g_old_bump);
 *   - there is no 2× to-space and no survivor-copy major pause;
 *   - the card table covers the fixed reservation once — no grow-time reslice.
 *
 * Small objects (≤ VADER_OLD_SMALL_MAX) use 16 B size classes; each class owns
 * regions (bump-carved) + a free list threaded through freed slots' `forward`
 * field. Large objects get a one-object region each, reused best-fit and
 * `madvise`-released on free. Reclamation is mark (toggle `g_mark_value`,
 * trace from roots + young survivors via a gray worklist) + sweep (rebuild the
 * free lists from unmarked slots). See `vader_major_collect`. */

#define VADER_OLD_CLASS_GRAN   16u
#define VADER_OLD_SMALL_MAX    1024u
#define VADER_OLD_NUM_CLASSES  (VADER_OLD_SMALL_MAX / VADER_OLD_CLASS_GRAN)  /* 64 */
#define VADER_OLD_REGION_BYTES (256u * 1024u)   /* small-class region granularity */
#define VADER_OLD_MADVISE_MIN  (64u * 1024u)    /* only madvise freed large regions ≥ this */

/* One carved extent of the reservation. Small regions hold many fixed-size
 * slots of one class; large regions hold exactly one object. */
typedef struct vader_old_region {
    char*  base;          /* region start within the reservation */
    char*  cur;           /* bump high-water: next never-used slot (== end of used run) */
    char*  end;           /* region end (base + capacity) */
    size_t slot_size;     /* class slot size; for large = the object's aligned size */
    int    class_idx;     /* small: 0..NUM_CLASSES-1 ; large: -1 */
    uint8_t freed;        /* large only: currently on the large free list */
    struct vader_old_region* next;       /* global region list (sweep + walks) */
    struct vader_old_region* free_next;  /* large free list link */
} vader_old_region_t;

typedef struct {
    char*               free_head;   /* free list: link via each slot's `forward` */
    vader_old_region_t* current;     /* region we bump-allocate from */
} vader_old_class_t;

static char*  g_old_block     = NULL;   /* reservation base */
static char*  g_old_bump      = NULL;   /* global region-carve cursor (never retreats) */
static char*  g_old_block_end = NULL;   /* g_old_block + reservation capacity */
static size_t g_old_capacity  = 0;      /* reservation size in bytes (== the cap) */
static size_t g_old_live_bytes = 0;     /* slot bytes held by live old objects (accumulates promotions; recomputed exact at sweep) */
static size_t g_old_live_after_major = 0;  /* g_old_live_bytes right after the last sweep — the reclamation-trigger baseline */
static int    g_old_alloc_failed_at_cap = 0;  /* set when a carve hit the cap with empty free lists */

static vader_old_class_t   g_old_classes[VADER_OLD_NUM_CLASSES];
static vader_old_region_t* g_old_regions    = NULL;   /* all regions, carve order */
static vader_old_region_t* g_old_large_free = NULL;   /* freed large regions, best-fit reuse */

/* Old-gen mark bit value for the CURRENT epoch. Toggles 1↔2 each major so a
 * previous epoch's marks read as "unmarked" without a clear pass; a FREE slot
 * carries 0 (never equal to g_mark_value). `vader_old_alloc` stamps live=this. */
static uint8_t g_mark_value = 1u;

/* Gray worklist — objects whose slots still need scanning. Reused by both
 * cycles: minor pushes freshly-promoted old objects (to forward their young
 * refs); major pushes freshly-marked old objects (to mark their children). */
static char**  g_gray_stack = NULL;
static size_t  g_gray_len   = 0;
static size_t  g_gray_cap   = 0;

static int           g_gc_initialized = 0;
static size_t        g_total_collections = 0;
static size_t        g_total_copied = 0;
/* Allocation volume — every vader_gc_alloc request, surviving or not. Distinct
 * from g_total_copied (which counts only bytes that SURVIVED a collection):
 * short-lived garbage is invisible to total_copied but shows up here. The
 * per-pass profiler uses this to attribute raw allocation pressure. */
static size_t        g_total_alloc_bytes = 0;
static size_t        g_total_alloc_count = 0;

/* Hard caps on auto-grow, per semi-space. Default to the compile-time defines
 * but are env-tunable (VADER_GC_OLD_MAX / VADER_GC_YOUNG_MAX) so a too-large
 * live set traps at a deliberate ceiling instead of exhausting RAM. Set once
 * in `vader_gc_init`. */
static size_t        g_old_max_bytes = 0;
static size_t        g_young_max_bytes = 0;

/* Adaptive young sizing: the divisor `k` in `young_target = old_live / k`. A
 * minor collect conservatively re-scans the whole old card table, so its cost
 * is O(old size). With a fixed young, total scan work over a run is
 * (churn / young) × old — quadratic in the old live set. Sizing young ∝ old
 * keeps it linear in churn. 0 disables the heuristic (fixed young). Env-tunable
 * via VADER_GC_YOUNG_RATIO; set once in `vader_gc_init`. */
static size_t        g_young_ratio = 2;

/* Ceiling on the adaptive young target. `young ∝ old` overshoots a roughly
 * workload-independent working-set cliff (~128-160 MB for the self-compile):
 * growing past it buys little and costs RSS. Cap the target here. 0 = uncapped.
 * Env-tunable via VADER_GC_YOUNG_CAP (a byte size); set once in `vader_gc_init`. */
static size_t        g_young_cap = 0;

/* Stress mode — set via `VADER_GC_STRESS=1`. When enabled, every
 * `vader_gc_alloc` triggers a minor collect (and the string sweep that
 * runs at minor end). Forces every safepoint to exercise the full
 * shadow-stack walk + conservative C-stack scan + string mark, which
 * turns intermittent rooting bugs into deterministic failures. Off by
 * default: the 100×–10000× slowdown is reserved for debugging sessions.
 * Captured once on init; the env var has no effect mid-run. */
static int g_gc_stress = 0;

/* Major-stress mode — set via `VADER_GC_STRESS_MAJOR=1`. The mark-sweep analog
 * of VADER_GC_STRESS: every `vader_gc_alloc` forces a FULL major (mark + sweep),
 * so the non-moving old gen's trace, free-list rebuild, and promotion-into-slab
 * paths run at every safepoint — turning intermittent old-gen rooting / sweep
 * bugs into deterministic failures. Even slower than STRESS; debug-only. */
static int g_gc_stress_major = 0;

/* Box-tag corruption check — set via `VADER_GC_CHECK_BOX=1`. When enabled,
 * `vader_gc_scan_box` traps the first time it meets a box whose `tag` is
 * neither NULL (0) nor a valid type index (< vader_type_info_count). Such a
 * tag can only be stray bytes (a heap-pointer's low 32 bits), so it pinpoints
 * which GC cycle first observes a corrupted bucket box — and whether the box's
 * payload still points at a valid heap object (tag-only clobber) or not. Off
 * by default: the scan's existing `tag >= count` fast-path stays silent. */
static int g_gc_check_box = 0;

/* Old-gen scan override — set via `VADER_GC_SCAN_ALL_OLD=1`. Forces
 * `vader_gc_scan_old_dirty_cards` to treat every card as dirty, i.e. to scan
 * and forward EVERY old object's slots on each minor. A/B probe: if a
 * self-host crash that reproduces under tight young arenas disappears with
 * this on, the bug is a missing card-mark (a write barrier that didn't fire
 * on an old→young edge), not the GC scan itself. Off by default. */
static int g_gc_scan_all_old = 0;

/* Current cycle. Drives both `vader_gc_forward` (which arena to copy into)
 * and the collection counter (sub-cycles don't bump it independently). */
typedef enum {
    VADER_CYCLE_NONE = 0,         /* no cycle running */
    VADER_CYCLE_MINOR,            /* standalone minor */
    VADER_CYCLE_MAJOR_DRAIN,      /* minor running as the first step of a major */
    VADER_CYCLE_MAJOR,            /* mark phase of a major (old objects marked in place, never copied) */
} vader_cycle_t;
static vader_cycle_t g_cycle = VADER_CYCLE_NONE;

/* Card table — one byte per VADER_CARD_BYTES of the old-gen reservation. The old
 * gen is non-moving, so the table is sized once over the whole reservation and
 * never relocated. Exposed (non-static) because the inline `VADER_WRITE_BARRIER`
 * macro needs the address from emitted C code. */
uint8_t*   vader_card_table = NULL;
uintptr_t  vader_old_base   = 0;
uintptr_t  vader_old_end    = 0;
static size_t g_card_count = 0;

/* Per-minor snapshot of the card table (same size as `vader_card_table`). The
 * minor card scan copies the live dirty set here, clears the live table, and
 * scans the objects under cards marked dirty in this snapshot; the forwarding
 * path (`vader_gc_scan_box`/`_raw`) re-dirties the LIVE table for any slot that
 * still points young after forwarding. Snapshotting decouples the clear from
 * the scan so a redirty can never be wiped by clearing a later card the same
 * object spans — see `vader_gc_scan_old_dirty_cards`. */
static uint8_t* g_card_shadow = NULL;

/* Cards spanning the carved old prefix [g_old_block, g_old_bump) — the live part
 * of the table. The minor scan and the major's card re-arm both bound their
 * table sweeps to this (uncommitted reservation tail holds no objects). */
static inline size_t vader_old_used_cards(void) {
    return ((size_t)(g_old_bump - g_old_block) + VADER_CARD_BYTES - 1u) / VADER_CARD_BYTES;
}

/* Shadow-stack head. Each emitted C function pushes/pops a frame chained
 * through `prev`; the GC walks this list at collection time to enumerate
 * precise roots. */
vader_gc_frame_t* vader_gc_top = NULL;

static size_t vader_gc_align(size_t n) {
    return (n + (VADER_GC_ALIGN - 1u)) & ~(size_t)(VADER_GC_ALIGN - 1u);
}

static int vader_in_young_from(const void* p) {
    return (const char*)p >= g_young.from.base && (const char*)p < g_young.from.end;
}

/* Membership in the non-moving old gen: a pointer is an old object iff it falls
 * in the carved span [g_old_block, g_old_bump). Pointers in [g_old_bump,
 * g_old_block_end) address uncommitted reservation tail — never a live object —
 * so they're correctly excluded (a stray ref there is treated as immortal, not
 * marked/written). Old objects never move, so there is no from/to distinction —
 * one predicate covers both the minor (old is stable) and the major (old is
 * sweepable). */
static int vader_in_old(const void* p) {
    return (const char*)p >= g_old_block && (const char*)p < g_old_bump;
}

/* Read a positive byte-count from `env_name`. Returns `fallback` when the
 * variable is unset, empty, non-numeric, or parses to zero. Lets users tune
 * the heap (e.g. `VADER_GC_OLD_MAX=536870912` for a 512 MB old cap) without
 * rebuilding the runtime. */
static size_t vader_gc_env_bytes(const char* env_name, size_t fallback) {
    const char* raw = getenv(env_name);
    if (raw == NULL || raw[0] == '\0') return fallback;
    char* end = NULL;
    unsigned long long v = strtoull(raw, &end, 10);
    if (end == raw || v == 0ull) return fallback;
    return (size_t)v;
}

/* Read a boolean toggle from `env_name`: true when set to a non-empty value
 * other than "0". Used for the GC debug knobs (stress / box-check / scan-all). */
static int vader_gc_env_bool(const char* env_name) {
    const char* raw = getenv(env_name);
    return raw != NULL && raw[0] != '\0' && raw[0] != '0';
}

static int g_gc_profile = 0;
void vader_gc_profile_dump(void);

/* ---------- slab old-gen: reservation, allocation, sweep ----------
 *
 * Defined here (after the env helpers, before everything that uses them:
 * vader_gc_init, vader_gc_forward, vader_major_collect). Pure address-space
 * machinery — no dependency on the type-info table or vader_gc_obj_size. */

/* Reserve `bytes` of address space, lazily committed (untouched pages cost no
 * RSS). POSIX: MAP_ANONYMOUS mmap. Windows: VirtualAlloc MEM_RESERVE (pages are
 * committed per-region in vader_old_commit). Returns NULL on failure. */
static char* vader_old_reserve(size_t bytes) {
#if defined(_WIN32)
    return (char*) VirtualAlloc(NULL, bytes, MEM_RESERVE, PAGE_READWRITE);
#else
    void* p = mmap(NULL, bytes, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    return (p == MAP_FAILED) ? NULL : (char*) p;
#endif
}

/* Make [ptr, ptr+bytes) usable. POSIX mmap is demand-paged, so this is a no-op;
 * Windows must explicitly commit the reserved pages before first write. */
static void vader_old_commit(char* ptr, size_t bytes) {
#if defined(_WIN32)
    if (VirtualAlloc(ptr, bytes, MEM_COMMIT, PAGE_READWRITE) == NULL) {
        vader_trap("vader_old_commit: VirtualAlloc(MEM_COMMIT) failed (out of commit charge)");
    }
#else
    (void) ptr; (void) bytes;   /* demand-paged */
#endif
}

/* Release the physical pages backing a freed large region while keeping its
 * address range reserved for reuse. POSIX: madvise (RSS drops; next write
 * re-faults). Windows: no-op for now. Only the page-aligned interior is touched
 * so a non-page-aligned region base/end is handled cleanly. */
static void vader_old_madvise_region(vader_old_region_t* r) {
#if !defined(_WIN32)
    size_t page = (size_t) sysconf(_SC_PAGESIZE);
    if (page == 0u) return;
    uintptr_t a = ((uintptr_t) r->base + page - 1u) & ~(uintptr_t)(page - 1u);
    uintptr_t b = (uintptr_t) r->end & ~(uintptr_t)(page - 1u);
    if (b > a) {
#  if defined(MADV_FREE)
        madvise((void*) a, (size_t)(b - a), MADV_FREE);
#  elif defined(MADV_DONTNEED)
        madvise((void*) a, (size_t)(b - a), MADV_DONTNEED);
#  endif
    }
#else
    (void) r;
#endif
}

/* Carve a fresh region of `region_bytes` from the global bump and dedicate it to
 * `slot_size` (class_idx ≥ 0 for small, -1 for a one-object large region).
 * Returns NULL when the reservation is exhausted (the real OOM ceiling). */
static vader_old_region_t* vader_old_carve_region(size_t region_bytes, size_t slot_size, int class_idx) {
    if (g_old_bump + region_bytes > g_old_block_end) return NULL;
    vader_old_region_t* r = (vader_old_region_t*) malloc(sizeof(vader_old_region_t));
    if (r == NULL) vader_trap("vader_old_carve_region: region metadata malloc failed");
    vader_old_commit(g_old_bump, region_bytes);
    r->base      = g_old_bump;
    r->cur       = g_old_bump;
    r->end       = g_old_bump + region_bytes;
    r->slot_size = slot_size;
    r->class_idx = class_idx;
    r->freed     = 0u;
    r->free_next = NULL;
    r->next      = g_old_regions;
    g_old_regions = r;
    g_old_bump   += region_bytes;
    return r;
}

/* Allocate `bytes` of old-gen storage (the promotion path). Returns raw,
 * uninitialised slot memory (caller writes the object + header) or NULL when the
 * reservation is exhausted at the cap (caller keeps the object in young). */
static void* vader_old_alloc(size_t bytes) {
    size_t aligned = vader_gc_align(bytes);
    if (aligned <= VADER_OLD_SMALL_MAX) {
        size_t ci = (aligned - 1u) / VADER_OLD_CLASS_GRAN;     /* 0..NUM_CLASSES-1 */
        size_t slot_size = (ci + 1u) * VADER_OLD_CLASS_GRAN;
        vader_old_class_t* c = &g_old_classes[ci];
        if (c->free_head != NULL) {
            char* slot = c->free_head;
            c->free_head = (char*) ((vader_obj_header_t*) slot)->forward;
            g_old_live_bytes += slot_size;
            return slot;
        }
        if (c->current == NULL || c->current->cur + slot_size > c->current->end) {
            vader_old_region_t* r = vader_old_carve_region(VADER_OLD_REGION_BYTES, slot_size, (int) ci);
            if (r == NULL) { g_old_alloc_failed_at_cap = 1; return NULL; }
            c->current = r;
        }
        char* slot = c->current->cur;
        c->current->cur += slot_size;
        g_old_live_bytes += slot_size;
        return slot;
    }
    /* Large: best-fit over freed large regions (smallest with slot_size ≥ aligned). */
    vader_old_region_t** best = NULL;
    for (vader_old_region_t** pp = &g_old_large_free; *pp != NULL; pp = &(*pp)->free_next) {
        if ((*pp)->slot_size >= aligned &&
            (best == NULL || (*pp)->slot_size < (*best)->slot_size)) {
            best = pp;
        }
    }
    if (best != NULL) {
        vader_old_region_t* r = *best;
        *best = r->free_next;
        r->free_next = NULL;
        r->freed = 0u;
        g_old_live_bytes += r->slot_size;
        return r->base;   /* pages re-fault on the caller's memcpy */
    }
    vader_old_region_t* r = vader_old_carve_region(aligned, aligned, -1);
    if (r == NULL) { g_old_alloc_failed_at_cap = 1; return NULL; }
    r->cur = r->base + aligned;       /* the single slot is now in use */
    g_old_live_bytes += aligned;
    return r->base;
}

/* Push an object onto the gray worklist (geometric growth). */
static void vader_gray_push(char* obj) {
    if (g_gray_len == g_gray_cap) {
        size_t new_cap = g_gray_cap == 0u ? 4096u : g_gray_cap * 2u;
        char** ns = (char**) realloc(g_gray_stack, new_cap * sizeof(char*));
        if (ns == NULL) vader_trap("vader_gray_push: realloc failed");
        g_gray_stack = ns;
        g_gray_cap   = new_cap;
    }
    g_gray_stack[g_gray_len++] = obj;
}

/* Walk every LIVE old object (mark == g_mark_value) and invoke `fn`. Used by the
 * atom-GC heap walk, the histogram, and the profiler — every consumer that needs
 * to enumerate the old live set now that it is no longer one contiguous arena. */
static void vader_old_foreach_live(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx) {
    for (vader_old_region_t* r = g_old_regions; r != NULL; r = r->next) {
        for (char* slot = r->base; slot < r->cur; slot += r->slot_size) {
            vader_obj_header_t* h = (vader_obj_header_t*) slot;
            if (h->mark == g_mark_value) fn(slot, h->type_index, ctx);
        }
    }
}

/* Sweep: rebuild every free list from the unmarked slots. A slot survives iff
 * `mark == g_mark_value` (set during the mark phase). Dead small slots are
 * stamped FREE (mark 0) and pushed to their class free list; dead large regions
 * are madvise-released and queued for best-fit reuse. Recomputes g_old_live_bytes. */
static void vader_old_sweep(void) {
    for (size_t i = 0; i < VADER_OLD_NUM_CLASSES; i++) g_old_classes[i].free_head = NULL;
    g_old_large_free = NULL;
    size_t live = 0;
    for (vader_old_region_t* r = g_old_regions; r != NULL; r = r->next) {
        if (r->class_idx < 0) {
            /* Large: one object at r->base (live iff r->cur > r->base). */
            if (r->cur == r->base) continue;
            vader_obj_header_t* h = (vader_obj_header_t*) r->base;
            if (h->mark == g_mark_value) {
                r->freed = 0u;
                live += r->slot_size;
            } else {
                h->mark = 0u;
                h->type_index = VADER_TYPE_INDEX_FREE;
                if (!r->freed && r->slot_size >= VADER_OLD_MADVISE_MIN) vader_old_madvise_region(r);
                r->freed = 1u;
                r->free_next = g_old_large_free;
                g_old_large_free = r;
            }
            continue;
        }
        vader_old_class_t* c = &g_old_classes[r->class_idx];
        for (char* slot = r->base; slot < r->cur; slot += r->slot_size) {
            vader_obj_header_t* h = (vader_obj_header_t*) slot;
            if (h->mark == g_mark_value) {
                live += r->slot_size;
            } else {
                h->mark = 0u;
                h->type_index = VADER_TYPE_INDEX_FREE;
                h->forward = c->free_head;
                c->free_head = slot;
            }
        }
    }
    g_old_live_bytes = live;
}

/* Highest address of the current (main) thread's C stack — the scan upper bound.
 * The stack grows DOWN, so [current sp, base) covers every live frame. */
static char* vader_cstack_base(void) {
#if defined(_WIN32)
    ULONG_PTR lo = 0, hi = 0;
    GetCurrentThreadStackLimits(&lo, &hi);
    return (char*) hi;
#elif defined(__APPLE__)
    return (char*) pthread_get_stackaddr_np(pthread_self());
#else
    pthread_attr_t attr;
    if (pthread_getattr_np(pthread_self(), &attr) != 0) return NULL;
    void* addr = NULL; size_t size = 0;
    pthread_attr_getstack(&attr, &addr, &size);
    pthread_attr_destroy(&attr);
    if (addr == NULL) return NULL;
    return (char*) addr + size;
#endif
}

/* Map an interior old-gen pointer to the start of its containing slot, or NULL
 * if it falls in a region's never-used tail. Regions partition [g_old_block,
 * g_old_bump); within one, slots are fixed `slot_size`-strided. Linear over
 * regions — only reached for the few stack words that point into old. */
static char* vader_old_slot_of(void* p) {
    char* a = (char*) p;
    for (vader_old_region_t* r = g_old_regions; r != NULL; r = r->next) {
        if (a >= r->base && a < r->cur) {
            size_t off = (size_t)(a - r->base);
            return r->base + (off / r->slot_size) * r->slot_size;
        }
    }
    return NULL;
}

/* Conservative C-stack root scan for the OLD generation's major mark.
 *
 * The precise shadow stack does not root every live OLD pointer at every
 * safepoint (minors never free old, so the c-emit was never required to — a live
 * old ref can sit only in a C local / register). The copying old gen masked this
 * via deferred reuse; the non-moving mark-sweep gen reuses freed slots eagerly,
 * so it must find those refs. We do it conservatively: flush callee-saved
 * registers (setjmp), then walk the C stack word-by-word and MARK every old
 * object any word points at (interior pointers map to their slot). Old objects
 * never move, so a false positive merely retains a dead object — no pinning, no
 * correctness risk. Found objects are gray-pushed so their closure is marked too.
 *
 * Young is deliberately NOT scanned conservatively: its rooting is already
 * precise (minors require it) and young objects MOVE, which a conservative
 * (maybe-not-a-pointer) root cannot tolerate. */
static void vader_gc_mark_cstack_conservative(void) {
    jmp_buf regs;
    (void) setjmp(regs);                 /* spill callee-saved registers onto the stack */
    char* base = vader_cstack_base();
    if (base == NULL) return;
    char* lo = (char*) &regs;            /* approx current stack top (this frame) */
    if (lo >= base) return;
    /* Align down to a pointer boundary, then scan word-aligned slots. */
    lo = (char*) ((uintptr_t) lo & ~(uintptr_t)(sizeof(void*) - 1u));
    for (char* p = lo; p + sizeof(void*) <= base; p += sizeof(void*)) {
        void* w = *(void* volatile*) p;
        if ((char*) w < g_old_block || (char*) w >= g_old_bump) continue;
        char* slot = vader_old_slot_of(w);
        if (slot == NULL) continue;
        vader_obj_header_t* h = (vader_obj_header_t*) slot;
        if (h->mark != g_mark_value && h->type_index != VADER_TYPE_INDEX_FREE) {
            h->mark = g_mark_value;
            vader_gray_push(slot);
        }
    }
}

/* ============================================================
 * Atom-based string interning — see `docs/ATOM_INTERNING.md`.
 *
 * Phase 0.a wires the table + API into the runtime alongside the
 * legacy `vader_string_t` machinery. The intern hash, slice-share,
 * and GC integration are stubbed and ship in 0.b / 0.c / Phase 4.
 *
 * The table is grow-only in indices : atoms minted at runtime can be
 * collected (their bytes freed, slot tombstoned) but the `entries[]`
 * array never shrinks — every `vader_atom_t` value ever observed in
 * a live slot stays a valid lookup target, just possibly with reused
 * content. Comptime atoms are PERM-flagged and never collected.
 * ============================================================ */

typedef struct {
    vader_atom_entry_t* entries;
    vader_u32_t         count;
    vader_u32_t         capacity;

    /* Open-addressing hash : intern lookup. `buckets[i]` holds the atom
     * id installed at hash slot `i`, or 0 (== VADER_ATOM_EMPTY) for an
     * empty slot. Slot 0 cannot collide with a real atom because we
     * pre-install the empty atom and skip it in probes. */
    vader_u32_t* buckets;
    vader_u32_t  bucket_capacity;
    vader_u32_t  bucket_count;     /* occupied slots — for load factor check */

    /* Free list of tombstone indices (atoms freed by GC). Reused by the
     * next owner-style intern before growing `entries[]`. */
    vader_u32_t* free_list;
    vader_u32_t  free_count;
    vader_u32_t  free_capacity;

    /* Total bytes held by owner atoms — for profiling. */
    size_t       owner_bytes;
} vader_atom_table_t;

static vader_atom_table_t g_atoms = {0};
static int  g_atoms_initialized = 0;
static int  g_atom_profile = 0;

/* Initial table capacity — 256 covers the keyword + primitive pre-intern
 * with room for early dynamic atoms. Grows by doubling. Phase 0.d will
 * size this from the comptime atom count emitted by codegen. */
#define VADER_ATOM_INITIAL_CAPACITY    256u
#define VADER_ATOM_INITIAL_BUCKETS     1024u   /* must be power of two */

/* Forward decls — implementations below cluster by concern. */
static void        vader_atom_install_empty(void);
static uint64_t    vader_atom_hash64(const char* data, size_t len);
static void        vader_atom_bucket_install(vader_atom_t a, vader_u32_t hash);
static void        vader_ensure_stdio_binary(void);

void vader_atom_init(void) {
    vader_atom_init_with_comptime(NULL, 0u);
}

void vader_atom_init_with_comptime(const vader_atom_entry_t* comptime_table,
                                   vader_u32_t count) {
    /* Program-startup stdio setup : the emitted `main` calls atom-init first,
     * so this is the one place every C-emitted binary passes through at start.
     * On Windows the CRT defaults stdout to TEXT mode, which translates every
     * `\n` to `\r\n` — that corrupts `dump` / `build` / `fmt` output (LF on
     * disk, CRLF on the wire) and every snapshot comparison. Force binary here,
     * not just lazily in `vader_read_stdin` (which only `lsp` reaches). */
    vader_ensure_stdio_binary();
    if (g_atoms_initialized) return;
    g_atoms_initialized = 1;

    const char* prof_env = getenv("VADER_ATOM_PROFILE");
    if (prof_env != NULL && prof_env[0] != '\0' && prof_env[0] != '0') {
        g_atom_profile = 1;
        /* `vader_atom_shutdown` dumps the profile before tearing down,
         * so no atexit hook is needed here — atexit's LIFO order would
         * fire the dump *after* shutdown has zeroed the table. */
    }

    /* Pick a capacity that absorbs the comptime atoms plus headroom for
     * the first wave of dynamic interns without an immediate grow.
     * Doubling the comptime size matches the markdown plan (decision §8). */
    vader_u32_t initial_cap = VADER_ATOM_INITIAL_CAPACITY;
    if (count > 0u) {
        /* count + 1 for the empty sentinel at index 0, then ×2 for
         * runtime headroom. Round up to the existing initial capacity
         * so very small modules still get a usable starting bucket
         * table. */
        vader_u32_t want = (count + 1u) * 2u;
        if (want > initial_cap) initial_cap = want;
    }
    g_atoms.entries = (vader_atom_entry_t*)
        malloc(initial_cap * sizeof(vader_atom_entry_t));
    if (g_atoms.entries == NULL) vader_trap("vader_atom_init: entries malloc failed");
    g_atoms.capacity = initial_cap;
    g_atoms.count    = 0;

    /* Bucket capacity scales with comptime count for the same reason —
     * a freshly initialised table should not immediately rehash on the
     * first user interns. Round up to a power of two ≥ 4 × (count+1). */
    vader_u32_t want_buckets = VADER_ATOM_INITIAL_BUCKETS;
    if (count > 0u) {
        vader_u32_t target = (count + 1u) * 4u;
        while (want_buckets < target) want_buckets *= 2u;
    }
    g_atoms.buckets = (vader_u32_t*)
        calloc(want_buckets, sizeof(vader_u32_t));
    if (g_atoms.buckets == NULL) vader_trap("vader_atom_init: buckets calloc failed");
    g_atoms.bucket_capacity = want_buckets;
    g_atoms.bucket_count    = 0;

    g_atoms.free_list     = NULL;
    g_atoms.free_count    = 0;
    g_atoms.free_capacity = 0;
    g_atoms.owner_bytes   = 0;

    vader_atom_install_empty();

    /* Comptime atoms come in PERM — never freed, rodata-backed. Their
     * `data` pointer is owned by the binary's `.rodata` section, so the
     * shutdown path must skip the `free(data)` step on these entries. */
    if (count > 0u && comptime_table != NULL) {
        memcpy(&g_atoms.entries[1], comptime_table,
               count * sizeof(vader_atom_entry_t));
        g_atoms.count = 1u + count;
        /* Force PERM on every comptime entry — the codegen-emitted
         * table sets it too, but enforcing here keeps the runtime
         * invariant local. */
        for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
            g_atoms.entries[i].flags |= VADER_ATOM_FLAG_PERM;
        }
        /* Build the bucket index over the comptime atoms in a single
         * pass — cheaper than running through `vader_atom_intern` and
         * its hash-lookup-then-install dance for each one. */
        for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
            const vader_atom_entry_t* e = &g_atoms.entries[i];
            /* Codegen's positional comptime-table literals omit `hash` (it
             * zero-fills) — recompute it here so comptime atoms hash like any
             * interned string ; its low bits index the bucket. */
            uint64_t hash64 = vader_atom_hash64(e->data, e->len);
            g_atoms.entries[i].hash = hash64;
            vader_atom_bucket_install(i, (vader_u32_t) hash64);
        }
    }
}

/* Install VADER_ATOM_EMPTY at index 0 with PERM flag. No bucket entry —
 * the empty string is reached by direct `a == 0` checks, never via hash
 * probe (it would collide with the "empty slot" sentinel). */
static void vader_atom_install_empty(void) {
    vader_atom_entry_t* e = &g_atoms.entries[0];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = 0;
    e->flags         = VADER_ATOM_FLAG_PERM;
    e->_pad          = 0;
    e->data          = "";
    e->hash          = vader_atom_hash64("", 0);
    g_atoms.count    = 1;
}

void vader_atom_shutdown(void) {
    if (!g_atoms_initialized) return;
    /* Dump the profile *before* tearing down — atexit LIFO ordering
     * runs shutdown ahead of the profile-dump handler registered in
     * `_init_with_comptime`, so the deferred dump would see a zeroed
     * table. Calling it inline here lets us read the live state. */
    if (g_atom_profile) vader_atom_profile_dump();
    for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
        vader_atom_entry_t* e = &g_atoms.entries[i];
        /* Free owner buffers from dynamic intern only — PERM entries
         * carry rodata pointers we must NOT free. Slice atoms borrow
         * from their parent ; no free either. The static empty-string
         * at index 0 is excluded by the loop bound. */
        if (e->parent == 0 && e->data != NULL && e->len > 0
            && (e->flags & VADER_ATOM_FLAG_PERM) == 0) {
            free((void*) e->data);
        }
    }
    free(g_atoms.entries);
    free(g_atoms.buckets);
    free(g_atoms.free_list);
    g_atoms.entries         = NULL;
    g_atoms.buckets         = NULL;
    g_atoms.free_list       = NULL;
    g_atoms.count           = 0;
    g_atoms.capacity        = 0;
    g_atoms.bucket_capacity = 0;
    g_atoms.bucket_count    = 0;
    g_atoms.free_count      = 0;
    g_atoms.free_capacity   = 0;
    g_atoms.owner_bytes     = 0;
    g_atoms_initialized     = 0;
}

const vader_atom_entry_t* vader_atom_entry(vader_atom_t a) {
    return &g_atoms.entries[a];
}

const char* vader_atom_data(vader_atom_t a) {
    return g_atoms.entries[a].data;
}

size_t vader_atom_len(vader_atom_t a) {
    return (size_t) g_atoms.entries[a].len;
}

/* ---- intern internals ---- */

/* FNV1a 64-bit over the bytes — the atom table's ONE hash. Computed once at
 * insert: cached on the entry (returned O(1) by `vader_string_hash` for
 * `string`'s `Hash` trait) AND its low bits index the open-addressing bucket
 * table (an odd multiplier keeps the low bits a bijection, so no clustering
 * under the power-of-two mask). Byte-identical to the retired pure-Vader
 * `string_hash_fnv1a64`. */
static uint64_t vader_atom_hash64(const char* data, size_t len) {
    uint64_t h = 14695981039346656037ull;
    for (size_t i = 0; i < len; ++i) {
        h ^= (vader_u8_t) data[i];
        h *= 1099511628211ull;
    }
    return h;
}

/* String `Hash` — O(1) read of the cached FNV-1a-64 (computed once at intern).
 * See the `vader_atom_entry_t.hash` note in vader.h. */
uint64_t vader_string_hash(vader_string_t s) {
    return g_atoms.entries[s].hash;
}

/* Bucket probe — returns the matching atom id or VADER_ATOM_EMPTY (0)
 * on miss. The empty-slot sentinel in `buckets[]` is also 0 ; callers
 * short-circuit len==0 before reaching this so the sentinel can never
 * collide with a real hit. `bucket_capacity` is a power of two — mask
 * trick replaces a modulo. */
static vader_atom_t vader_atom_lookup(const char* data, size_t len, vader_u32_t hash) {
    const vader_u32_t mask = g_atoms.bucket_capacity - 1u;
    vader_u32_t idx = hash & mask;
    for (;;) {
        vader_atom_t a = g_atoms.buckets[idx];
        if (a == VADER_ATOM_EMPTY) return VADER_ATOM_EMPTY;
        const vader_atom_entry_t* e = &g_atoms.entries[a];
        if (e->len == len && memcmp(e->data, data, len) == 0) {
            return a;
        }
        idx = (idx + 1u) & mask;
    }
}

/* Install an atom id at its canonical bucket slot. `hash` is the low 32 bits of
 * the atom's FNV-64 (callers truncate `e->hash`). Assumes free room — the
 * load-factor check in the intern entrypoint grows buckets before any insert
 * that would push it past the 0.75 threshold. */
static void vader_atom_bucket_install(vader_atom_t a, vader_u32_t hash) {
    const vader_u32_t mask = g_atoms.bucket_capacity - 1u;
    vader_u32_t idx = hash & mask;
    while (g_atoms.buckets[idx] != VADER_ATOM_EMPTY) {
        idx = (idx + 1u) & mask;
    }
    g_atoms.buckets[idx] = a;
    g_atoms.bucket_count++;
}

/* Bucket grow — double capacity, rehash every live atom. Called when
 * the load factor would exceed 0.75 after the most recent install. */
static void vader_atom_grow_buckets(void) {
    free(g_atoms.buckets);
    g_atoms.bucket_capacity *= 2u;
    g_atoms.buckets = (vader_u32_t*)
        calloc(g_atoms.bucket_capacity, sizeof(vader_u32_t));
    if (g_atoms.buckets == NULL) vader_trap("vader_atom_grow_buckets: calloc failed");
    g_atoms.bucket_count = 0;
    /* Reinsert every live atom except the empty sentinel at index 0.
     * Phase 4 will skip tombstones here too ; for now no tombstones
     * exist. */
    for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
        /* Rehash from the cached FNV-64 (low bits) — no byte re-walk. */
        vader_atom_bucket_install(i, (vader_u32_t) g_atoms.entries[i].hash);
    }
}

/* Entries grow — double capacity, realloc in place. Pointers into the
 * array are NOT stable across calls ; every reader rederefs through
 * `g_atoms.entries`, so a realloc that relocates the array is safe. */
static void vader_atom_grow_entries(void) {
    g_atoms.capacity *= 2u;
    vader_atom_entry_t* p = (vader_atom_entry_t*)
        realloc(g_atoms.entries, g_atoms.capacity * sizeof(vader_atom_entry_t));
    if (p == NULL) vader_trap("vader_atom_grow_entries: realloc failed");
    g_atoms.entries = p;
}

/* Allocate a fresh atom slot — reuses a tombstoned id from the free
 * list (Phase 4) when available, else grows `entries[]`. The entry is
 * left uninitialised ; the caller fills the fields. */
static vader_atom_t vader_atom_alloc_slot(void) {
    if (g_atoms.free_count > 0) {
        return g_atoms.free_list[--g_atoms.free_count];
    }
    if (g_atoms.count >= g_atoms.capacity) {
        vader_atom_grow_entries();
    }
    return g_atoms.count++;
}

/* Miss-path install : claim a slot, point it at `buf` (caller-owned heap
 * buffer with inline NUL at `buf[len]` already written), bucket-install,
 * grow buckets if load factor crossed. The caller is responsible for
 * ensuring `buf` is the canonical bytes for `hash` (i.e. they already
 * lost a lookup race). */
static vader_atom_t vader_atom_install_owner(char* buf, size_t len, uint64_t hash) {
    vader_atom_t a = vader_atom_alloc_slot();
    vader_atom_entry_t* e = &g_atoms.entries[a];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = (vader_u32_t) len;
    e->flags         = 0;
    e->_pad          = 0;
    e->data          = buf;
    e->hash          = hash;
    g_atoms.owner_bytes += len;

    vader_atom_bucket_install(a, (vader_u32_t) hash);

    /* Grow if past 0.75. Done after install so the just-inserted atom
     * rehashes with the rest into the new table. */
    if (g_atoms.bucket_count * 4u > g_atoms.bucket_capacity * 3u) {
        vader_atom_grow_buckets();
    }
    return a;
}

/* ---- public intern API ---- */

vader_atom_t vader_atom_intern(const char* data, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    uint64_t hash = vader_atom_hash64(data, len);
    vader_atom_t found = vader_atom_lookup(data, len, (vader_u32_t) hash);
    if (found != VADER_ATOM_EMPTY) return found;

    char* buf = (char*) malloc(len + 1u);
    if (buf == NULL) vader_trap("vader_atom_intern: buffer malloc failed");
    memcpy(buf, data, len);
    buf[len] = '\0';
    return vader_atom_install_owner(buf, len, hash);
}

vader_atom_t vader_atom_intern_take(char* buf, size_t len) {
    if (len == 0) {
        free(buf);
        return VADER_ATOM_EMPTY;
    }

    uint64_t hash = vader_atom_hash64(buf, len);
    vader_atom_t found = vader_atom_lookup(buf, len, (vader_u32_t) hash);
    if (found != VADER_ATOM_EMPTY) {
        free(buf);
        return found;
    }

    /* Caller MUST have allocated `buf` with `malloc(len + 1)` so the
     * inline NUL fits. */
    buf[len] = '\0';
    return vader_atom_install_owner(buf, len, hash);
}

vader_atom_t vader_atom_slice(vader_atom_t parent, size_t offset, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    /* Bounds validation against the parent's logical bytes. Invalid
     * arguments are a runtime contract violation — trap rather than
     * silently produce a corrupted slice. */
    if (parent >= g_atoms.count) {
        vader_trap("vader_atom_slice: parent atom id out of range");
    }
    const vader_atom_entry_t* pe = &g_atoms.entries[parent];
    if (offset > pe->len || len > pe->len - offset) {
        vader_trap("vader_atom_slice: range overflows parent length");
    }

    /* Flatten one hop : every slice atom enforces `parent.parent == 0`
     * at insert time (we never link a slice to another slice), so the
     * deepest chain we ever see is parent → owner. Keeps the GC mark
     * trivial (one hop, never recursive). */
    vader_atom_t root        = parent;
    size_t       root_offset = offset;
    if (g_atoms.entries[root].parent != 0) {
        root_offset += g_atoms.entries[root].parent_offset;
        root         = g_atoms.entries[root].parent;
    }

    /* Hash on the candidate bytes ; dedupe regardless of where the
     * canonical representative lives (might be owner, might be slice
     * sharing different bytes that happen to compare equal). */
    const char* candidate = g_atoms.entries[root].data + root_offset;
    uint64_t hash         = vader_atom_hash64(candidate, len);
    vader_atom_t found    = vader_atom_lookup(candidate, len, (vader_u32_t) hash);
    if (found != VADER_ATOM_EMPTY) return found;

    /* Miss — install as slice atom borrowing from the root owner. No
     * allocation. NUL-term at data[len] is NOT guaranteed (the byte
     * past the slice belongs to the parent buffer and may be any
     * value) — `vader_atom_to_cstr` handles slice atoms by duplicating
     * to a heap NUL-term copy. */
    vader_atom_t a = vader_atom_alloc_slot();
    vader_atom_entry_t* e = &g_atoms.entries[a];
    e->parent        = root;
    e->parent_offset = (vader_u32_t) root_offset;
    e->len           = (vader_u32_t) len;
    e->flags         = 0;
    e->_pad          = 0;
    e->data          = candidate;
    e->hash          = hash;

    vader_atom_bucket_install(a, (vader_u32_t) hash);

    if (g_atoms.bucket_count * 4u > g_atoms.bucket_capacity * 3u) {
        vader_atom_grow_buckets();
    }

    return a;
}

const char* vader_atom_to_cstr(vader_atom_t a) {
    const vader_atom_entry_t* e = &g_atoms.entries[a];
    if (e->parent == 0) {
        return e->data;     /* owner : NUL-term inline at data[len] */
    }
    /* Slice : duplicate for NUL termination. Caller frees via
     * `vader_atom_cstr_free`. */
    char* dup = (char*) malloc(e->len + 1u);
    if (dup == NULL) vader_trap("vader_atom_to_cstr: dup malloc failed");
    memcpy(dup, e->data, e->len);
    dup[e->len] = '\0';
    return dup;
}

/* O(1) variant of `vader_atom_cstr_free` for callers that still hold the
 * atom id : owner atoms hand out their table-owned bytes (nothing to
 * free), slice atoms were dup'd by `_to_cstr`. The id-less form below
 * has to SCAN the table to discriminate — the extern-call shims free one
 * cstr per string arg per FFI call, which makes that scan hot. */
void vader_cstr_free_for(vader_string_t s, const char* p) {
    if (p == NULL) return;
    if (g_atoms.entries[s].parent == 0) return;  /* owner : table-owned */
    free((void*) p);
}

void vader_atom_cstr_free(const char* p) {
    if (p == NULL) return;
    /* Distinguish owner-data (stable pointer into the table) from slice
     * dups (heap-allocated by `_to_cstr`). The owner path returns a
     * pointer into our own table — we can't `free` it. We detect by
     * scanning the table, which is O(N) but only matters for FFI
     * boundaries (cold). A faster discriminator (e.g. a header bit on
     * dup'd buffers) is a Phase 1 optimisation. */
    for (vader_u32_t i = 0; i < g_atoms.count; ++i) {
        if (g_atoms.entries[i].parent == 0 && g_atoms.entries[i].data == p) {
            return;  /* owner data — owned by table */
        }
    }
    free((void*) p);
}

void vader_atom_profile_dump(void) {
    fprintf(stderr, "[atom-profile] count=%u capacity=%u bucket_load=%.2f%% "
                    "owner_bytes=%zu free_count=%u\n",
            g_atoms.count, g_atoms.capacity,
            g_atoms.bucket_capacity == 0 ? 0.0
                : 100.0 * (double) g_atoms.bucket_count / (double) g_atoms.bucket_capacity,
            g_atoms.owner_bytes, g_atoms.free_count);
}

/* Forward decl for the heap-mark walker — defined further down. */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index);

/* ---- atom GC mark + sweep (Phase 4) ----
 *
 * Integrates with the major collection cycle. Reachable atoms are found
 * through three channels :
 *   - shadow stack `vader_box_t**` roots (conservative : the lower 4
 *     bytes of every box payload are treated as a candidate atom id)
 *   - heap objects, via `vader_type_info.string_offsets[]` (precise)
 *     plus a conservative pass over `ptr_offsets[]` boxes
 *   - defer stack
 * Unmarked non-PERM atoms have their data buffer freed and the slot
 * tombstoned ; the bucket index is rebuilt in one pass. */

static void vader_atom_mark(vader_atom_t a) {
    if (a == VADER_ATOM_EMPTY || a >= g_atoms.count) return;
    vader_atom_entry_t* e = &g_atoms.entries[a];
    if (e->flags & (VADER_ATOM_FLAG_PERM | VADER_ATOM_FLAG_MARK)) return;
    e->flags |= VADER_ATOM_FLAG_MARK;
    /* Slice → owner : keep the parent alive too. Chain depth is at
     * most 1 (the slice ctor flattens), so no recursion needed. */
    if (e->parent != 0 && e->parent < g_atoms.count) {
        vader_atom_entry_t* p = &g_atoms.entries[e->parent];
        if ((p->flags & VADER_ATOM_FLAG_PERM) == 0) {
            p->flags |= VADER_ATOM_FLAG_MARK;
        }
    }
}

static void vader_atom_mark_box(const vader_box_t* bp) {
    if (bp == NULL) return;
    /* Conservatively treat the lower 4 bytes of `payload.s` as an atom
     * id. False positives keep extra atoms alive ; no correctness
     * impact. The 8-byte `payload.i` alias is read once to avoid
     * union-field type-punning warnings. */
    vader_atom_mark((vader_atom_t) (uint32_t) bp->payload.i);
}

/* Conservatively mark atoms reachable only from a C local / register. A
 * `vader_string_t` is a bare `u32` atom id, so unlike object refs it never
 * appears in the shadow stack or as a heap pointer — held in a C local it is
 * invisible to the precise roots and the heap walk. Flush registers (setjmp),
 * then read every 4-byte-aligned stack word as a candidate atom id and mark it
 * (`vader_atom_mark` bounds-checks; false positives only retain a small atom).
 * The non-moving old gen reuses freed slots eagerly, so — as for objects — a
 * live atom held only in a C local must be found here or its bytes get reclaimed
 * under a still-live `bytes()` view (the copying gen masked this via deferred
 * reuse). Scanned 4-byte-aligned because a u32 local need not be 8-aligned. */
static void vader_atom_mark_cstack_conservative(void) {
    jmp_buf regs;
    (void) setjmp(regs);
    char* base = vader_cstack_base();
    if (base == NULL) return;
    char* lo = (char*) ((uintptr_t) &regs & ~(uintptr_t)3u);
    if (lo >= base) return;
    for (char* p = lo; p + sizeof(uint32_t) <= base; p += sizeof(uint32_t)) {
        vader_atom_mark((vader_atom_t) *(uint32_t volatile*) p);
    }
}

static void vader_atom_mark_roots(void) {
    for (vader_gc_frame_t* fr = vader_gc_top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs == NULL) continue;
        for (uint32_t i = 0; i < fr->nrefs; i++) {
            vader_atom_mark_box(fr->ptrs[i]);
        }
    }
    for (size_t i = 0; i < g_defer_len; i++) {
        vader_atom_mark_box(&g_defer_stack[i]);
    }
    vader_atom_mark_cstack_conservative();
}

/* Mark every atom referenced by one heap object's slots (string fields, borrowed
 * byte-view owner, conservative box payloads). Shared by the young contiguous
 * walk and the old region walk. */
static void vader_atom_mark_object(char* scan, uint32_t type_index, void* ctx) {
    (void) ctx;
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) scan;
        if (buf->element_kind == VADER_ARRAY_KIND_BOXED) {
            vader_box_t* slots = vader_array_box_slots(buf);
            for (size_t i = 0; i < buf->length; i++) {
                vader_atom_mark_box(&slots[i]);
            }
        }
    } else if (type_index < vader_type_info_count) {
        const vader_type_info_t* info = &vader_type_info_table[type_index];
        /* Precise : string fields from the type_info table. */
        for (uint16_t i = 0; i < info->string_count; i++) {
            vader_string_t* sp = (vader_string_t*) (scan + info->string_offsets[i]);
            vader_atom_mark(*sp);
        }
        /* Borrowed `const u8[]` byte view (`vader_string_bytes_view`) : the array
         * header carries no string field, but its `capacity` low 32 bits hold the
         * owner atom id whose interned bytes the view aliases. Mark it so the
         * bytes aren't swept under us. */
        if (info->kind == VADER_TYPE_KIND_ARRAY) {
            vader_array_t* arr = (vader_array_t*) scan;
            if (vader_array_is_borrowed(arr)) {
                vader_atom_mark(vader_array_borrowed_owner(arr));
            }
        }
        /* Conservative : box fields. The payload's lower 4 bytes may be an atom
         * (for string-tagged variants) or any other primitive ; conservativeness
         * keeps the latter from accidentally collecting a live atom. */
        if (info->kind != VADER_TYPE_KIND_FN
            && info->kind != VADER_TYPE_KIND_ARRAY) {
            for (uint16_t i = 0; i < info->ptr_count; i++) {
                vader_atom_mark_box((vader_box_t*) (scan + info->ptr_offsets[i]));
            }
        }
    }
}

static void vader_atom_mark_heap(void) {
    /* Young: one contiguous from-space walk. */
    char* scan = g_young.from.base;
    while (scan < g_young.from.cur) {
        vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
        size_t bytes = vader_gc_obj_size(scan, hdr->type_index);
        if (bytes == 0) break;
        vader_atom_mark_object(scan, hdr->type_index, NULL);
        scan += vader_gc_align(bytes);
    }
    /* Old: the non-moving slab is not one arena — walk live slots by region. */
    vader_old_foreach_live(vader_atom_mark_object, NULL);
}

static void vader_atom_free_list_push(vader_u32_t id) {
    if (g_atoms.free_count >= g_atoms.free_capacity) {
        size_t new_cap = g_atoms.free_capacity == 0 ? 64u : (size_t) g_atoms.free_capacity * 2u;
        vader_u32_t* p = (vader_u32_t*) realloc(g_atoms.free_list, new_cap * sizeof(vader_u32_t));
        if (p == NULL) vader_trap("vader_atom_free_list_push: realloc failed");
        g_atoms.free_list = p;
        g_atoms.free_capacity = (vader_u32_t) new_cap;
    }
    g_atoms.free_list[g_atoms.free_count++] = id;
}

static void vader_atom_sweep(void) {
    size_t freed_bytes = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        vader_atom_entry_t* e = &g_atoms.entries[i];
        if (e->flags & VADER_ATOM_FLAG_PERM) continue;
        /* Skip already-tombstoned slots (data NULL means reclaimed in a
         * previous sweep ; they live in the free list). */
        if (e->data == NULL && e->len == 0 && e->parent == 0) continue;
        if (e->flags & VADER_ATOM_FLAG_MARK) {
            e->flags &= ~VADER_ATOM_FLAG_MARK;
            continue;
        }
        if (e->parent == 0 && e->data != NULL && e->len > 0) {
            freed_bytes += e->len;
            free((void*) e->data);
        }
        e->parent        = 0;
        e->parent_offset = 0;
        e->len           = 0;
        e->flags         = 0;
        e->data          = NULL;
        vader_atom_free_list_push(i);
    }
    if (freed_bytes > g_atoms.owner_bytes) g_atoms.owner_bytes = 0;
    else g_atoms.owner_bytes -= freed_bytes;

    /* Rebuild the hash index. Bucket clears + linear reinsert keeps the
     * implementation simple ; incremental updates would need to track
     * each tombstone's original hash to clear specifically. */
    memset(g_atoms.buckets, 0, g_atoms.bucket_capacity * sizeof(vader_u32_t));
    g_atoms.bucket_count = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        const vader_atom_entry_t* e = &g_atoms.entries[i];
        if (e->data == NULL) continue;
        /* Reinsert from the cached FNV-64 (low bits) — no byte re-walk. */
        vader_atom_bucket_install(i, (vader_u32_t) e->hash);
    }
}

void vader_atom_gc_collect(void) {
    if (!g_atoms_initialized) return;
    vader_atom_mark_roots();
    vader_atom_mark_heap();
    vader_atom_sweep();
}

/* Total physical RAM in bytes, or 0 if it can't be determined (caller then
 * falls back to the fixed compile-time arena defaults). Portable: Win32
 * `GlobalMemoryStatusEx`, POSIX (Linux + macOS) `sysconf(_SC_PHYS_PAGES)`. */
static size_t vader_physical_ram_bytes(void) {
#if defined(_WIN32)
    MEMORYSTATUSEX s;
    s.dwLength = sizeof(s);
    if (GlobalMemoryStatusEx(&s)) return (size_t) s.ullTotalPhys;
    return 0;
#else
    long pages = sysconf(_SC_PHYS_PAGES);
    long psize = sysconf(_SC_PAGESIZE);
    if (pages > 0 && psize > 0) return (size_t) pages * (size_t) psize;
    return 0;
#endif
}

static size_t vader_clamp_size(size_t x, size_t lo, size_t hi) {
    return x < lo ? lo : (x > hi ? hi : x);
}

void vader_gc_init(void) {
    if (g_gc_initialized) return;

    /* Stack-object roots (vader_gc_frame_t.stack_objs) depend on type_index 0
     * being a scan no-op. A hoisted stack storage is zero-init'd (type 0) and may
     * be handed to vader_gc_scan_object in the window before its `struct.new`
     * writes the real header — that scan must trace no fields. Type 0 is reserved
     * for the `null` primitive (VADER_BOX_TAG_NULL) and a BcPrimitive emits no
     * info row, so slot 0 stays KIND_NONE with no pointer/ref fields. Assert the
     * contract here: a future seed that put a pointer-bearing type at index 0
     * would make that pre-init scan walk past the storage (silent OOB). */
    if (vader_type_info_count > 0
        && (vader_type_info_table[0].ptr_count != 0
            || vader_type_info_table[0].ref_count != 0)) {
        vader_trap("vader_gc_init: type_info_table[0] must be a scan no-op "
                   "(reserved null slot) — stack-object rooting relies on it");
    }

    g_gc_stress       = vader_gc_env_bool("VADER_GC_STRESS");
    g_gc_stress_major = vader_gc_env_bool("VADER_GC_STRESS_MAJOR");
    g_gc_check_box    = vader_gc_env_bool("VADER_GC_CHECK_BOX");
    g_gc_scan_all_old = vader_gc_env_bool("VADER_GC_SCAN_ALL_OLD");

    /* VADER_GC_PROFILE : at exit, walk both arenas and dump the live set
     * bucketed by type_index — sorted by total bytes, top-20. Useful to
     * answer "what's filling my GC arena?". OOM paths abort() so atexit
     * doesn't fire ; the OOM trap dumps inline before aborting. */
    const char* gc_prof_env = getenv("VADER_GC_PROFILE");
    if (gc_prof_env != NULL && gc_prof_env[0] != '\0' && gc_prof_env[0] != '0') {
        g_gc_profile = 1;
        atexit(vader_gc_profile_dump);
    }

    /* RAM-proportional defaults (the zero-tuning primary interface; the absolute
     * VADER_GC_OLD_MAX env var below still overrides). Derive the old reservation
     * cap from physical RAM, so the same
     * binary self-compiles on an 8 GB laptop and a 64 GB box. Fall back to the
     * fixed #defines when RAM can't be read. Young is NOT scaled (its cap is a
     * per-minor cost cliff, not a memory limit). */
    size_t ram = vader_physical_ram_bytes();
    size_t old_max_default  = (size_t) VADER_GC_OLD_MAX;
    if (ram > 0) {
        double pct = (double) VADER_GC_RAM_PERCENT;
        const char* pct_env = getenv("VADER_GC_RAM_PERCENT");
        if (pct_env != NULL && pct_env[0] != '\0') {
            double v = strtod(pct_env, NULL);
            if (v > 0.0 && v <= 100.0) pct = v;
        }
        /* budget = the committed ceiling the GC may reach. The old gen is now a
         * single non-moving reservation (lazily committed: untouched pages cost
         * no RSS), so it no longer needs a 2× to-space — reserve young's worst-
         * case commit (its cap × 2) then give the rest to the old reservation. */
        size_t budget        = (size_t) ((double) ram * pct / 100.0);
        size_t young_reserve = (size_t) VADER_GC_YOUNG_CAP_DEFAULT * 2u;
        size_t old_budget    = budget > young_reserve ? budget - young_reserve : budget / 2u;
        old_max_default  = vader_clamp_size(old_budget, VADER_GC_OLD_CAP_MIN, (size_t) VADER_GC_OLD_MAX);
    }

    /* Auto-grow ceilings (env-tunable, default to the RAM-derived / compile-time caps). */
    g_old_max_bytes   = vader_gc_env_bytes("VADER_GC_OLD_MAX",   old_max_default);
    g_young_max_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_MAX", (size_t) VADER_GC_YOUNG_MAX);

    /* Adaptive young-sizing divisor (young_target = old_live / ratio). Default
     * 2 (young ≈ half the old live set); 0 turns the heuristic off. A plain
     * integer, not a byte size — read it directly rather than via env_bytes. */
    {
        const char* ratio_env = getenv("VADER_GC_YOUNG_RATIO");
        if (ratio_env != NULL) g_young_ratio = (size_t) strtoul(ratio_env, NULL, 10);
    }
    /* Ceiling on the adaptive young target (byte size; 0 = uncapped). Default
     * 192 MB: past the self-compile's ~128-160 MB working-set cliff, growing
     * young further trades RSS for no speed (measured). */
    g_young_cap = vader_gc_env_bytes("VADER_GC_YOUNG_CAP", VADER_GC_YOUNG_CAP_DEFAULT);

    /* Young: one malloc spanning both semi-spaces. */
    size_t young_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_BYTES", (size_t)VADER_GC_YOUNG_BYTES);
    g_young.block = (char*) malloc(young_bytes * 2u);
    if (g_young.block == NULL) vader_trap("vader_gc_init: young arena malloc failed");
    g_young.half_bytes = young_bytes;
    g_young.from.base = g_young.block;
    g_young.from.cur  = g_young.block;
    g_young.from.end  = g_young.block + young_bytes;
    g_young.to.base   = g_young.block + young_bytes;
    g_young.to.cur    = g_young.to.base;
    g_young.to.end    = g_young.to.base + young_bytes;

    /* Old: a single non-moving reservation at the cap, lazily committed. Objects
     * are bump-carved into class regions and never move, so there is no to-space
     * and no grow-time relocation. The reservation size IS the cap (the old
     * auto-grow ceiling); untouched pages stay uncommitted, so RSS tracks the
     * live working set, not the reservation. VADER_GC_OLD_BYTES (the old initial
     * size) is obsolete under lazy commit — only the cap matters now. */
    g_old_capacity  = g_old_max_bytes;
    g_old_block     = vader_old_reserve(g_old_capacity);
    if (g_old_block == NULL) vader_trap("vader_gc_init: old-gen reservation failed (out of address space)");
    g_old_bump      = g_old_block;
    g_old_block_end = g_old_block + g_old_capacity;
    for (size_t i = 0; i < VADER_OLD_NUM_CLASSES; i++) {
        g_old_classes[i].free_head = NULL;
        g_old_classes[i].current   = NULL;
    }
    g_old_regions    = NULL;
    g_old_large_free = NULL;
    g_old_live_bytes = 0;
    g_old_live_after_major = 0;
    g_mark_value     = 1u;

    /* Card table covers the whole reservation, one byte per VADER_CARD_BYTES.
     * Old objects never move, so it is sized once and never relocated. */
    g_card_count = (g_old_capacity + VADER_CARD_BYTES - 1u) / VADER_CARD_BYTES;
    vader_card_table = (uint8_t*) calloc(g_card_count, 1u);
    if (vader_card_table == NULL) vader_trap("vader_gc_init: card-table calloc failed");
    g_card_shadow = (uint8_t*) malloc(g_card_count);
    if (g_card_shadow == NULL) vader_trap("vader_gc_init: card-shadow malloc failed");
    vader_old_base = (uintptr_t) g_old_block;
    vader_old_end  = (uintptr_t) g_old_block_end;

    g_gc_initialized = 1;
}

void vader_gc_shutdown(void) {
    if (!g_gc_initialized) return;
    free(g_young.block);
    /* Release the old-gen reservation and its region metadata. */
    if (g_old_block != NULL) {
#if defined(_WIN32)
        VirtualFree(g_old_block, 0, MEM_RELEASE);
#else
        munmap(g_old_block, g_old_capacity);
#endif
    }
    for (vader_old_region_t* r = g_old_regions; r != NULL; ) {
        vader_old_region_t* next = r->next;
        free(r);
        r = next;
    }
    free(g_gray_stack);
    free(vader_card_table);
    free(g_card_shadow);
    g_young.block = NULL;
    g_young.from.base = g_young.from.cur = g_young.from.end = NULL;
    g_young.to.base   = g_young.to.cur   = g_young.to.end   = NULL;
    g_old_block = g_old_bump = g_old_block_end = NULL;
    g_old_capacity = g_old_live_bytes = g_old_live_after_major = 0;
    g_old_regions = NULL;
    g_old_large_free = NULL;
    for (size_t i = 0; i < VADER_OLD_NUM_CLASSES; i++) {
        g_old_classes[i].free_head = NULL;
        g_old_classes[i].current   = NULL;
    }
    g_gray_stack = NULL;
    g_gray_len = g_gray_cap = 0;
    vader_card_table  = NULL;
    g_card_shadow     = NULL;
    vader_old_base    = 0;
    vader_old_end     = 0;
    g_card_count      = 0;
    g_gc_initialized  = 0;
}

/* Internal bump in the young from-space. Caller must have ensured capacity. */
static void* vader_gc_alloc_young_unchecked(size_t aligned) {
    void* p = g_young.from.cur;
    g_young.from.cur += aligned;
    return p;
}

/* Grow the young generation to `new_half` per semi-space, via the same flip-
 * with-resize trick as old: point `g_young.to` at a fresh, larger block and
 * run a minor, which relocates every live young object into it (forwarding
 * fixes the pointers) and swaps. Then free the old block and re-slice the
 * spare to-space onto the new block's second half. Young carries no card table
 * or write-barrier bounds, so this is simpler than `vader_old_grow_to`. NULL
 * malloc is the real RAM ceiling. */
static void vader_young_grow_to(size_t new_half) {
    char* new_block = (char*) malloc(new_half * 2u);
    if (new_block == NULL) {
        fprintf(stderr,
            "vader_young_grow: malloc failed growing young arena to %zu MB × 2 "
            "(cap VADER_GC_YOUNG_MAX = %zu MB) — out of RAM\n",
            new_half / (1024u * 1024u),
            g_young_max_bytes / (1024u * 1024u));
        vader_trap("vader_young_grow: out of memory (RAM ceiling)");
    }
    char* old_block = g_young.block;
    /* Relocate live young into the new block's first half: the minor copies
     * g_young.from → g_young.to (which we point here) and swaps. */
    g_young.to.base = new_block;
    g_young.to.cur  = new_block;
    g_young.to.end  = new_block + new_half;
    vader_minor_collect();
    /* Post-swap g_young.from is the new block's first half (survivors); the
     * spare g_young.to still points at the old block — re-slice it onto the
     * new block's second half and free the old block. */
    free(old_block);
    char* base       = g_young.from.base;            /* == new_block */
    g_young.block      = base;
    g_young.half_bytes = new_half;
    g_young.to.base    = base + new_half;
    g_young.to.cur     = g_young.to.base;
    g_young.to.end     = g_young.to.base + new_half;
}

/* Pick a new young semi-space size large enough that, after a relocating
 * minor, the from-space can still bump-allocate `aligned`. Survivors are
 * bounded by the current occupancy, so `occupancy + aligned` is a safe target;
 * grow geometrically (×2) past it. Caps at VADER_GC_YOUNG_MAX — trap there is
 * the real ceiling. Returns without growing if the current half already fits. */
static void vader_young_grow_for(size_t aligned) {
    size_t occupancy = (size_t)(g_young.from.cur - g_young.from.base);
    size_t want = occupancy + aligned;
    /* max(2 × current, want), clamped to the cap — same geometric/at-least-fit
     * shape as the old-arena grow in `vader_major_collect`. */
    size_t new_half = g_young.half_bytes * 2u;
    if (new_half < want) new_half = want;
    if (new_half > g_young_max_bytes) new_half = g_young_max_bytes;
    if (new_half < want) {
        fprintf(stderr,
            "vader_young_grow: live young %zu MB + object %zu MB exceeds cap "
            "VADER_GC_YOUNG_MAX %zu MB\n",
            occupancy / (1024u * 1024u), aligned / (1024u * 1024u),
            g_young_max_bytes / (1024u * 1024u));
        /* abort() skips atexit handlers — dump the live set inline so
         * VADER_GC_PROFILE works on the OOM cases we most want to diagnose. */
        if (g_gc_profile) vader_gc_profile_dump();
        vader_trap("vader_young_grow: object + live set exceeds young cap");
    }
    if (new_half > g_young.half_bytes) vader_young_grow_to(new_half);
}

/* Adaptive young sizing — call after a standalone minor collect from the
 * allocator. Grows the young semi-space toward `old_live / g_young_ratio` so
 * the (churn / young) × old card-scan cost stays linear in churn instead of
 * quadratic in old. Hysteresis (target ≥ 1.5× current) avoids repeated
 * reallocations; growth never shrinks, so an explicit VADER_GC_YOUNG_BYTES
 * floor is preserved. Disabled when the ratio is 0. `vader_young_grow_to`
 * relocates survivors via an internal minor collect, so this MUST run outside
 * `vader_minor_collect` (hence the call site is the allocator, not the
 * collector — calling it from within a collect would recurse). */
static void vader_young_maybe_grow_adaptive(void) {
    if (g_young_ratio == 0u) return;
    size_t old_live = g_old_live_bytes;
    size_t target = old_live / g_young_ratio;
    if (g_young_cap != 0u && target > g_young_cap) target = g_young_cap;
    if (target > g_young_max_bytes) target = g_young_max_bytes;
    if (target > g_young.half_bytes + g_young.half_bytes / 2u) {
        vader_young_grow_to(target);
    }
}

/* Reclamation trigger for the non-moving old gen — call after a minor from the
 * allocator (a safe point: not re-entrant into a collect). The slab never
 * compacts and `vader_major_collect`'s old auto-grow is gone, so without this the
 * old footprint would equal the TOTAL promotion volume (dead never swept) instead
 * of the live set — bounded for a one-shot self-compile, but unbounded for a
 * long-running program. Fire a major (which sweeps dead old) once the old
 * footprint has grown past `live_after_last_major × HEADROOM`, never below
 * VADER_GC_OLD_MAJOR_FLOOR (so small programs never major). This mirrors the
 * copying gen's auto-grow cadence but reclaims in place instead of growing. */
static void vader_old_maybe_major(void) {
    size_t threshold = g_old_live_after_major
        * (size_t) VADER_GC_OLD_HEADROOM_NUM / (size_t) VADER_GC_OLD_HEADROOM_DEN;
    if (threshold < (size_t) VADER_GC_OLD_MAJOR_FLOOR) threshold = (size_t) VADER_GC_OLD_MAJOR_FLOOR;
    if (g_old_live_bytes > threshold) {
        vader_major_collect();
    }
}

/* ---- per-call-site alloc profiler (VADER_PROFILE_ALLOC_SITES) -------------
 * Compile-time-gated dynamic alloc profiler : which call sites drive the
 * allocation count. Build with `-DVADER_PROFILE_ALLOC_SITES` (e.g. via
 * STAGE0_CFLAGS for a bootstrap stage) and run with VADER_ALLOC_SITES=1.
 * Keyed by the return-address OFFSET from vader_gc_alloc (slide-invariant →
 * ASLR-proof) at three stack depths so runtime wrappers (vader_array_new,
 * the bytes() trampoline, …) can be cracked to the real .vader site.
 * Symbolise offline against an `-O0` build's `nm -n`:
 *   site_static_addr = nm(vader_gc_alloc) + offset
 * Inert — zero code, zero static arrays, zero hot-path cost — unless the macro
 * is defined, so it lives in-tree permanently instead of being re-added per
 * measurement. */
#ifdef VADER_PROFILE_ALLOC_SITES
#define VADER_ASITE_SLOTS (1u << 16)
static int64_t  g_asite_off[3][VADER_ASITE_SLOTS];
static uint64_t g_asite_cnt[3][VADER_ASITE_SLOTS];
static int      g_asite_enabled = -1;
static int      g_asite_armed   = 0;
void vader_asite_dump(void);
static int vader_asite_on(void) {
    if (g_asite_enabled < 0) g_asite_enabled = vader_gc_env_bool("VADER_ALLOC_SITES");
    return g_asite_enabled;
}
static void vader_asite_tick(int depth, void* ra) {
    if (ra == NULL) return;
    int64_t off = (int64_t)((char*) ra - (char*) (void*) vader_gc_alloc);
    uint64_t h = ((uint64_t) off ^ 0x9e3779b97f4a7c15ULL) * 1099511628211ULL;
    int64_t* offs = g_asite_off[depth];
    uint64_t* cnts = g_asite_cnt[depth];
    for (uint32_t i = 0; i < VADER_ASITE_SLOTS; i++) {
        uint32_t s = (uint32_t)((h >> 16) + i) & (VADER_ASITE_SLOTS - 1u);
        if (cnts[s] == 0) { offs[s] = off; cnts[s] = 1; return; }
        if (offs[s] == off) { cnts[s] += 1; return; }
    }
}
/* Inlined at the alloc call site so the captured return addresses are measured
 * from vader_gc_alloc itself (a helper frame would shift every depth by one). */
#define VADER_ASITE_CAPTURE() do {                                           \
    if (VADER_UNLIKELY(vader_asite_on())) {                                  \
        if (!g_asite_armed) { atexit(vader_asite_dump); g_asite_armed = 1; } \
        vader_asite_tick(0, __builtin_return_address(0));                    \
        vader_asite_tick(1, __builtin_return_address(1));                    \
        vader_asite_tick(2, __builtin_return_address(2));                    \
    }                                                                        \
} while (0)
#else
#define VADER_ASITE_CAPTURE() ((void) 0)
#endif

void* vader_gc_alloc(size_t bytes) {
    if (VADER_UNLIKELY(!g_gc_initialized)) vader_gc_init();
    /* Count raw requested bytes (same basis as g_total_copied) so the profiler
     * can report an alloc'd-vs-survived ratio. One increment per call. */
    g_total_alloc_bytes += bytes;
    g_total_alloc_count += 1;
    VADER_ASITE_CAPTURE();
    size_t aligned = vader_gc_align(bytes);
    /* A single object bigger than a young semi-space can never fit, however
     * much we collect — grow young to hold it (relocating the live set into a
     * larger block) before proceeding. */
    if (VADER_UNLIKELY(aligned > g_young.half_bytes)) {
        vader_young_grow_for(aligned);
    }
    /* Major-stress forces a full mark+sweep at every safepoint (debug-only). */
    if (VADER_UNLIKELY(g_gc_stress_major)) vader_major_collect();
    int young_full = (g_young.from.cur + aligned > g_young.from.end);
    if (VADER_UNLIKELY(young_full || g_gc_stress)) {
        vader_minor_collect();
        if (VADER_UNLIKELY(g_young.from.cur + aligned > g_young.from.end)) {
            /* Minor didn't free enough — young is overcommitted by long-
             * lived young objects (tenuring will fix it on the next cycle).
             * Force a major to age survivors into old and retry. */
            vader_major_collect();
            /* The major sweeps dead old objects, opening promotion room. Retry a
             * minor (now that old has room) to drain the survivors that couldn't
             * promote during the major's preliminary minor. Reset the cap-failure
             * flag first so it reflects only this post-sweep promotion attempt. */
            g_old_alloc_failed_at_cap = 0;
            if (VADER_UNLIKELY(g_young.from.cur + aligned > g_young.from.end)) {
                vader_minor_collect();
            }
            if (VADER_UNLIKELY(g_young.from.cur + aligned > g_young.from.end)) {
                /* Even a full collection left no room. Two causes: a young
                 * working set larger than the semi-space (grow young), or the old
                 * reservation exhausted at its cap so survivors can't promote and
                 * pile up in young (the real ceiling — trap, don't grow young
                 * forever). The flag distinguishes them: it is set when a
                 * post-sweep promotion failed to carve at the reservation cap. */
                if (VADER_UNLIKELY(g_old_alloc_failed_at_cap)) {
                    fprintf(stderr,
                        "vader_gc_alloc: out of memory — old reservation full at cap %zu MB "
                        "(VADER_GC_OLD_MAX); survivors cannot promote\n",
                        g_old_capacity / (1024u * 1024u));
                    if (g_gc_profile) vader_gc_profile_dump();
                    vader_trap("vader_gc_alloc: old reservation exhausted at cap");
                }
                /* Otherwise the young working set genuinely exceeds the semi-
                 * space — grow young to fit it (capped) rather than failing. */
                vader_young_grow_for(aligned);
            }
        }
        /* A collect just ran — re-size young toward old so the next round of
         * churn triggers far fewer (expensive, O(old)) minors. */
        vader_young_maybe_grow_adaptive();
        /* Reclaim dead old in place once it has grown past live×headroom (the
         * non-moving slab never compacts, so nothing else frees it). */
        vader_old_maybe_major();
    }
    return vader_gc_alloc_young_unchecked(aligned);
}

/* ---------- generational GC: copying young, mark-sweep old ---------- */

/* Size of an object in a from-space, in bytes. For variable-length buffers
 * (ARRAY_BUF sentinel) the size is read off the object itself; for
 * everything else the type info table provides a static size. Returns 0
 * for non-heap kinds (caller skips). */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index) {
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) obj;
        return sizeof(vader_array_buf_t) + buf->capacity * vader_array_element_size(buf->element_kind);
    }
    if (type_index == VADER_TYPE_INDEX_BUFFER) {
        vader_buffer_t* b = (vader_buffer_t*) obj;
        return sizeof(vader_buffer_t) + b->byte_count;
    }
    if (type_index >= vader_type_info_count) return 0;
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    if (info->kind == VADER_TYPE_KIND_NONE) return 0;
    return info->size;
}

/* Place a copy of `obj` in `target` and return the new address. Updates the
 * source header's `forward` slot, clears the destination's so the freshly
 * copied object looks live (not yet forwarded) within this cycle. The
 * destination's age is overwritten by the caller to reflect promotion
 * semantics. Returns NULL if `target` doesn't have room — the caller is
 * expected to react (promotion overflow → escalate to major). */
static void* vader_gc_copy_into(void* obj, size_t bytes, vader_arena_t* target) {
    size_t aligned = vader_gc_align(bytes);
    if (target->cur + aligned > target->end) return NULL;
    void* dst = target->cur;
    target->cur += aligned;
    memcpy(dst, obj, bytes);
    g_total_copied += bytes;
    ((vader_obj_header_t*) obj)->forward = dst;
    ((vader_obj_header_t*) dst)->forward = NULL;
    return dst;
}

/* Forward-process `obj` (typed by `type_index`) following `g_cycle`:
 *
 *   minor or major-drain : young objects move to young.to (or promote into the
 *     slab old gen via `vader_old_alloc` once age ≥ tenure); old objects are
 *     stable (non-moving) — returned unchanged.
 *   major : the mark phase. An old object is MARKED (mark = g_mark_value) and
 *     enqueued on the gray worklist (so its children get scanned); it does not
 *     move, so the slot value is returned unchanged.
 *
 * Pointers outside any GC arena are immortal — static compile-time data
 * (lookup tables, interned constants) lives in the C data segment and is never
 * copied or marked (it carries no refs into the arena, so it's a trace
 * dead-end). The C-emit may emit such tables for fns matching the
 * `match enum -> StructLit constant` pattern (TODO §3.5 Prop 2).
 * Constraint: a static object MUST NOT contain any pointer to a dynamic
 * (arena-allocated) object — the trace never visits it, so any inner dynamic
 * ref would be missed and freed under your feet. */
static void* vader_gc_forward(void* obj, uint32_t type_index) {
    if (obj == NULL) return NULL;

    if (g_cycle == VADER_CYCLE_MAJOR) {
        /* Mark phase: only old objects are sweepable. Young survivors and
         * immortals are dead-ends here (young is kept whole during the old
         * pass; immortals are read-only — never write a mark to them). */
        if (!vader_in_old(obj)) return obj;
        vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
        if (hdr->mark == g_mark_value) return obj;      /* already marked */
        hdr->mark = g_mark_value;
        vader_gray_push((char*) obj);
        return obj;
    }

    if (vader_in_old(obj)) return obj;                 /* non-moving — stable during minor */
    if (!vader_in_young_from(obj)) return obj;          /* immortal */

    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    if (hdr->forward != NULL) return hdr->forward;

    size_t bytes = vader_gc_obj_size(obj, type_index);
    if (bytes == 0) return obj;

    /* Promote into the slab old gen once the object has earned its tenure. If the
     * old reservation is exhausted, fall back to surviving another cycle in
     * young.to — the retry path in vader_gc_alloc escalates to a major (whose
     * sweep frees old room) and traps only at the true cap. */
    if (hdr->age + 1u >= VADER_TENURE_AGE) {
        void* dst = vader_old_alloc(bytes);
        if (dst != NULL) {
            memcpy(dst, obj, bytes);
            hdr->forward = dst;                          /* source forwards to promoted */
            vader_obj_header_t* dh = (vader_obj_header_t*) dst;
            dh->forward = NULL;
            dh->age  = (uint8_t)(hdr->age + 1u);
            dh->mark = g_mark_value;                     /* live in the current old epoch */
            g_total_copied += bytes;
            vader_gray_push((char*) dst);                /* scan its slots for young refs */
            return dst;
        }
        /* else: old full — keep in young.to this cycle. */
    }

    void* dst = vader_gc_copy_into(obj, bytes, &g_young.to);
    if (dst == NULL) vader_trap("vader_gc: young to-space overflow during minor");
    ((vader_obj_header_t*) dst)->age = (uint8_t)(hdr->age + 1u);
    return dst;
}

/* Forward decl — `scan_box` reaches into `scan_raw` for the inline-ref
 * wrapper case (payload.obj is the referent, not a wrapper-typed pointer). */
static void vader_gc_scan_raw(void** slot);

/* VADER_GC_CHECK_BOX diagnostic. `boxp->tag` is out of the valid type-index
 * range — it can only be stray bytes (typically a heap pointer's low 32 bits).
 * Dump where the box lives and, crucially, whether `payload.obj` still points
 * at a live arena object: if so this is a TAG-ONLY clobber (a 4-byte write into
 * the box's tag while the payload survived), which narrows the culprit write. */
static void vader_gc_box_tag_corrupt(const vader_box_t* boxp) {
    const char* box_loc =
        vader_in_young_from(boxp) ? "young-from" :
        vader_in_old(boxp)        ? "old"        : "off-heap (root/stack)";
    void* payload = boxp->payload.obj;
    int pl_live = payload != NULL
        && (vader_in_young_from(payload) || vader_in_old(payload));
    const char* pl_loc =
        payload == NULL              ? "NULL" :
        vader_in_young_from(payload) ? "young-from" :
        vader_in_old(payload)        ? "old" : "off-heap/garbage";
    fprintf(stderr,
        "\n[VADER_GC_CHECK_BOX] corrupt box tag during scan (cycle=%d)\n"
        "  box @ %p (%s)\n"
        "  tag = %u (0x%08x)  [valid range 0..%zu)\n"
        "  payload bits = 0x%016llx -> %p (%s)\n",
        (int) g_cycle, (const void*) boxp, box_loc,
        boxp->tag, boxp->tag, (size_t) vader_type_info_count,
        (unsigned long long) boxp->payload.i, payload, pl_loc);
    if (pl_live) {
        const vader_obj_header_t* h = (const vader_obj_header_t*) payload;
        fprintf(stderr,
            "  -> referent header: type_index = %u, age = %u, forward = %p\n"
            "     => TAG-ONLY clobber: payload still references a live object;\n"
            "        the box tag SHOULD have been this referent's BcType index.\n",
            h->type_index, (unsigned) h->age, h->forward);
    }
    vader_trap("VADER_GC_CHECK_BOX: box tag is not a valid type index");
}

/* Scan a `vader_box_t` slot — if the tag identifies a heap-allocated kind and
 * the payload holds a pointer, forward it and update the slot in place.
 *
 * If `boxp` lives in an old-gen object and the forwarded ref ends up in
 * young, mark the card dirty: future minors must rescan this slot, and
 * neither the original `array_push` write barrier (fired on user mutation,
 * not on this Cheney write) nor scan_old_dirty_cards covers it. */
static void vader_gc_scan_box(vader_box_t* boxp) {
    if (boxp == NULL) return;
    if (boxp->tag == VADER_TYPE_INDEX_BUFFER) {
        /* Buffer box : the sentinel tag has no type-info row, so the generic
         * `>= count` skip below would treat it as a primitive and never
         * forward the referent — a moving collection would then leave the box
         * pointing at the stale (reclaimed) location (G1). Forward via the
         * sentinel (sizes off the header) and apply the same old->young card
         * barrier as the ordinary ref path. A buffer holds no inner refs, so
         * there is nothing further to scan. */
        boxp->payload.obj = vader_gc_forward(boxp->payload.obj, VADER_TYPE_INDEX_BUFFER);
        if ((uintptr_t)boxp >= vader_old_base && (uintptr_t)boxp < vader_old_end
            && boxp->payload.obj != NULL
            && !vader_in_old(boxp->payload.obj)) {
            VADER_WRITE_BARRIER(boxp);
        }
        return;
    }
    if (boxp->tag >= vader_type_info_count) {
        if (VADER_UNLIKELY(g_gc_check_box)) vader_gc_box_tag_corrupt(boxp);
        return;
    }
    const vader_type_info_t* info = &vader_type_info_table[boxp->tag];
    if (info->kind == VADER_TYPE_KIND_NONE) return;
    /* Inline-ref wrapper : `payload.obj` is the referent itself (not a
     * pointer to a wrapper struct allocated under `boxp->tag`). Trace it
     * by reading the obj's own type tag from its header — scan_raw does
     * exactly that. The outer tag stays unchanged (`boxp->tag` is still
     * the wrapper's logical type, e.g. `Yield(Entry)`). */
    if (info->kind == VADER_TYPE_KIND_INLINE_REF) {
        vader_gc_scan_raw(&boxp->payload.obj);
        if ((uintptr_t)boxp >= vader_old_base && (uintptr_t)boxp < vader_old_end
            && boxp->payload.obj != NULL
            && !vader_in_old(boxp->payload.obj)) {
            VADER_WRITE_BARRIER(boxp);
        }
        return;
    }
    boxp->payload.obj = vader_gc_forward(boxp->payload.obj, boxp->tag);
    if ((uintptr_t)boxp >= vader_old_base && (uintptr_t)boxp < vader_old_end
        && boxp->payload.obj != NULL
        && !vader_in_old(boxp->payload.obj)) {
        VADER_WRITE_BARRIER(boxp);
    }
}

/* Scan a raw `void*` slot whose pointee is a heap object. Reads the pointee's
 * header to get its type, forwards, updates. Used for fn closure envs.
 * Same write-barrier rule as `vader_gc_scan_box`. */
static void vader_gc_scan_raw(void** slot) {
    if (slot == NULL || *slot == NULL) return;
    vader_obj_header_t* hdr = (vader_obj_header_t*) *slot;
    if (hdr->forward != NULL) { *slot = hdr->forward; }
    else { *slot = vader_gc_forward(*slot, hdr->type_index); }
    if ((uintptr_t)slot >= vader_old_base && (uintptr_t)slot < vader_old_end
        && *slot != NULL && !vader_in_old(*slot)) {
        VADER_WRITE_BARRIER(slot);
    }
}

/* Scan one heap object's pointer-bearing slots and forward whatever they
 * reference. Returns the byte length of the object so a Cheney scan can
 * advance its cursor. Returns 0 for malformed headers — callers treat that
 * as a stop condition. */
static size_t vader_gc_scan_object(char* scan) {
    vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
    uint32_t type_index = hdr->type_index;
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) scan;
        size_t elem_size = vader_array_element_size(buf->element_kind);
        if (buf->element_kind == VADER_ARRAY_KIND_BOXED) {
            vader_box_t* slots = vader_array_box_slots(buf);
            for (size_t i = 0; i < buf->length; i++) {
                vader_gc_scan_box(&slots[i]);
            }
        } else if (buf->element_kind == VADER_ARRAY_KIND_REF) {
            /* T12 : 8-byte raw-ref slots — forward each via scan_raw (handles
             * NULL slots + the old→young write barrier). */
            void** slots = (void**) buf->slots;
            for (size_t i = 0; i < buf->length; i++) {
                vader_gc_scan_raw(&slots[i]);
            }
        }
        return vader_gc_align(sizeof(vader_array_buf_t) + buf->capacity * elem_size);
    }
    if (type_index == VADER_TYPE_INDEX_BUFFER) {
        // All-bytes buffer : no boxed slots to forward, just advance past it.
        vader_buffer_t* b = (vader_buffer_t*) scan;
        return vader_gc_align(sizeof(vader_buffer_t) + b->byte_count);
    }
    if (type_index >= vader_type_info_count) {
        vader_trap("vader_gc: scanned object with unknown type_index");
    }
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    for (uint16_t i = 0; i < info->ptr_count; i++) {
        char* field = scan + info->ptr_offsets[i];
        if (info->kind == VADER_TYPE_KIND_FN
            || info->kind == VADER_TYPE_KIND_ARRAY) {
            vader_gc_scan_raw((void**) field);
        } else {
            vader_gc_scan_box((vader_box_t*) field);
        }
    }
    for (uint16_t i = 0; i < info->ref_count; i++) {
        vader_gc_scan_raw((void**) (scan + info->ref_offsets[i]));
    }
    return vader_gc_align(info->size);
}

/* Walk the shadow stack and forward every root cell. Used by both cycles. */
static void vader_gc_scan_roots(void) {
    for (vader_gc_frame_t* fr = vader_gc_top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs != NULL) {
            for (uint32_t i = 0; i < fr->nrefs; i++) {
                vader_gc_scan_box(fr->ptrs[i]);
            }
        }
        // T12 raw-ref roots — `void*` locals carrying a concrete ref unboxed.
        // NULL / 0 until the T12 codegen populates them (this loop then runs).
        if (fr->raw != NULL) {
            for (uint32_t i = 0; i < fr->nraw; i++) {
                vader_gc_scan_raw(fr->raw[i]);
            }
        }
        // Stack-object roots — GC structs the escape analysis stack-allocated.
        // Scan their FIELDS in place: the object never moves (it's off-arena on
        // the C stack), but its captured heap pointers must be forwarded across
        // this collection, else they dangle. NULL until codegen registers the
        // object post-init (a fully-initialised header + slots). See
        // vader_gc_frame_t.stack_objs.
        if (fr->stack_objs != NULL) {
            for (uint32_t i = 0; i < fr->nstack; i++) {
                if (fr->stack_objs[i] != NULL) {
                    (void) vader_gc_scan_object((char*) fr->stack_objs[i]);
                }
            }
        }
    }
    /* Defer-stack — every entry's `payload.obj` is a vader_fn_t* whose env
     * captures heap-promoted cells. Without rooting here, a GC between
     * defer.push and defer.pop_exec would collect the captures. */
    for (size_t i = 0; i < g_defer_len; i++) {
        vader_gc_scan_box(&g_defer_stack[i]);
    }
}

/* Forward every old→young pointer, then leave the card table holding EXACTLY
 * the cards whose old objects still point young — the second half of the
 * standard generational card protocol (HotSpot Serial/Parallel, .NET CoreCLR,
 * GC Handbook): the write barrier MARKS, the minor CLEANS + REDIRTIES.
 *
 * Snapshot the live dirty set into `g_card_shadow`, clear the live table, and
 * card-drive the scan: per region, skip clean (snapshot) cards without touching
 * their slots, and scan only the live objects under dirty cards. Forwarding a
 * slot that still references young re-dirties its LIVE card via the barrier in
 * `vader_gc_scan_box`/`_raw`; a slot whose referent tenured to old leaves its
 * card clean. So after the scan a card is dirty iff a live old object in it
 * still holds a young pointer — the dirty set collapses to the true old→young
 * edges instead of accreting until the next major (the old "rescan most of the
 * old heap every minor" cost: O(old slots) → O(dirty cards + live edges)).
 *
 * Snapshot-then-scan (rather than clear-as-you-go) is load-bearing: an object
 * can span two cards, and a redirty written while scanning the first card must
 * not be wiped when the second card is cleared. Reading the immutable snapshot
 * while only ever SETTING the live table removes that race; a per-region cursor
 * scans each spanning object at most once.
 *
 * Invariant: the mutator write barrier dirties a field's card on every
 * old→young store, so before the minor every live old→young field sits under a
 * dirty snapshot card — none is missed. (VADER_GC_SCAN_ALL_OLD keeps every card
 * dirty and skips the clear — the missing-barrier A/B probe scans all of old.) */
static void vader_gc_scan_old_dirty_cards(void) {
    if (g_old_regions == NULL || g_old_bump == g_old_block) return;
    size_t used_cards = vader_old_used_cards();

    /* Snapshot, then clear. Clearing here is safe because the only forwarding
     * done earlier in the minor — vader_gc_scan_roots — touches off-heap root /
     * defer cells (below the barrier's [old_base, old_end) guard), so it cannot
     * dirty a card the clear would wipe; every card-redirtying forward (this
     * scan + the gray drain that follows it) runs at or after this clear. */
    const uint8_t* dirty = NULL;
    if (!g_gc_scan_all_old) {
        memcpy(g_card_shadow, vader_card_table, used_cards);
        memset(vader_card_table, 0, used_cards);
        dirty = g_card_shadow;                          /* what to scan; live table = redirty target */
    }

    for (vader_old_region_t* r = g_old_regions; r != NULL; r = r->next) {
        if (r->cur == r->base) continue;                /* nothing carved yet */
        uintptr_t rbase_off = (uintptr_t) r->base - vader_old_base;
        size_t    card_lo   = rbase_off / VADER_CARD_BYTES;
        size_t    card_hi   = ((uintptr_t) r->cur - 1u - vader_old_base) / VADER_CARD_BYTES;
        char*     cursor    = r->base;                  /* slots below are already scanned */
        for (size_t c = card_lo; c <= card_hi; c++) {
            if (dirty != NULL && !dirty[c]) continue;   /* clean card — skip its slots wholesale */

            /* First slot of `r` overlapping card c, clamped past already-scanned
             * slots. Slots start at r->base + k*slot_size, so the slot covering
             * the card's first byte may have begun in an earlier card. */
            uintptr_t card_start_off = (uintptr_t) c * VADER_CARD_BYTES;
            size_t into = card_start_off > rbase_off ? (size_t)(card_start_off - rbase_off) : 0u;
            char* s = r->base + (into / r->slot_size) * r->slot_size;
            if (s < cursor) s = cursor;
            char* card_end = (char*)(vader_old_base + card_start_off + VADER_CARD_BYTES);
            for (; s < card_end && s < r->cur; s += r->slot_size) {
                vader_obj_header_t* hdr = (vader_obj_header_t*) s;
                if (hdr->mark == g_mark_value) (void) vader_gc_scan_object(s);
            }
            cursor = s;
        }
    }
}

/* Forward every pointer slot of every object in `[scan, arena->cur)`. Re-
 * reads `arena->cur` each iteration so objects appended by forwarding
 * during the scan are picked up before the loop ends. Returns the final
 * scan position. */
static char* vader_gc_drain(char* scan, const vader_arena_t* arena) {
    while (scan < arena->cur) {
        size_t step = vader_gc_scan_object(scan);
        if (step == 0) break;
        scan += step;
    }
    return scan;
}

void vader_minor_collect(void) {
    if (!g_gc_initialized) return;
    vader_cycle_t saved = g_cycle;
    if (saved == VADER_CYCLE_NONE) g_cycle = VADER_CYCLE_MINOR;
    /* MAJOR_DRAIN is preserved if the caller is `vader_major_collect`. */

    g_young.to.cur = g_young.to.base;
    char* young_scan = g_young.to.base;
    g_gray_len = 0;                                      /* promotions queue here */

    vader_gc_scan_roots();
    vader_gc_scan_old_dirty_cards();

    /* Drain young.to and the gray worklist until neither advances — forwarding a
     * young root can promote into the (scattered, non-contiguous) slab, and
     * scanning a promoted object can pull more young objects across, so the two
     * sources feed each other. Promoted objects can't be drained by a cursor
     * (they're spread across class regions), so they go through the gray stack. */
    for (;;) {
        char* y0 = young_scan;
        young_scan = vader_gc_drain(young_scan, &g_young.to);
        int drained_gray = 0;
        while (g_gray_len > 0) {
            char* obj = g_gray_stack[--g_gray_len];
            (void) vader_gc_scan_object(obj);           /* forward its young refs into young.to */
            drained_gray = 1;
        }
        if (young_scan == y0 && !drained_gray) break;
    }

    vader_arena_t tmp = g_young.from;
    g_young.from   = g_young.to;
    g_young.to     = tmp;
    g_young.to.cur = g_young.to.base;

    /* A preliminary minor inside a major counts as part of that major. */
    if (saved == VADER_CYCLE_NONE) g_total_collections++;
    g_cycle = saved;

    /* Atom-table GC integration lands in Phase 4. The legacy string
     * mark-sweep that used to run here was removed when `vader_string_t`
     * flipped to `u32` ; atoms are POD now and the conservative scan
     * naturally ignores them. */
}

/* VADER_GC_HISTOGRAM : before/after measurement of the old live set. Walks the
 * non-moving slab's live slots (mark == g_mark_value) after a sweep and reports
 * object count + byte distribution across size buckets, plus the address-space
 * bump high-water vs the reservation. Prints only when the live set hits a new
 * high, so the LAST line is the steady-state worst case. Read-only. */
static const size_t VADER_HISTO_EDGES[7] = { 32, 64, 128, 256, 512, 1024, 4096 };
typedef struct { size_t bcount[8]; size_t bbytes[8]; size_t total_objs; size_t total_bytes; } vader_histo_ctx_t;
static void vader_histo_tally(char* slot, uint32_t type_index, void* vctx) {
    vader_histo_ctx_t* c = (vader_histo_ctx_t*) vctx;
    size_t sz = vader_gc_obj_size(slot, type_index);
    if (sz == 0) return;
    c->total_objs++; c->total_bytes += sz;
    int bi = 7;
    for (int i = 0; i < 7; i++) { if (sz <= VADER_HISTO_EDGES[i]) { bi = i; break; } }
    c->bcount[bi]++; c->bbytes[bi] += sz;
}
static int    g_histo_enabled = -1;
static size_t g_histo_max_occ = 0;
static void vader_gc_old_histogram(void) {
    if (g_histo_enabled < 0) g_histo_enabled = vader_gc_env_bool("VADER_GC_HISTOGRAM");
    if (!g_histo_enabled) return;
    if (g_old_live_bytes <= g_histo_max_occ) return;
    g_histo_max_occ = g_old_live_bytes;

    static const char* labels[8] = { "<=32","<=64","<=128","<=256","<=512","<=1K","<=4K",">4K" };
    vader_histo_ctx_t ctx = {0};
    vader_old_foreach_live(vader_histo_tally, &ctx);
    size_t total_objs = ctx.total_objs, total_bytes = ctx.total_bytes;
    size_t* bcount = ctx.bcount; size_t* bbytes = ctx.bbytes;
    if (total_bytes == 0) return;
    size_t bump_used = (size_t)(g_old_bump - g_old_block);
    fprintf(stderr, "[GC-HISTO] old live-set: %zu objs, %.1f MB live ; bump=%.1f MB / reservation %.0f MB ; collections=%zu\n",
            total_objs, total_bytes / 1048576.0, bump_used / 1048576.0,
            g_old_capacity / 1048576.0, g_total_collections);
    for (int i = 0; i < 8; i++) {
        if (bcount[i] == 0) continue;
        fprintf(stderr, "[GC-HISTO]   %-5s : %8zu objs  %7.1f MB  (%.1f%% bytes)\n",
                labels[i], bcount[i], bbytes[i] / 1048576.0, 100.0 * bbytes[i] / total_bytes);
    }
}

void vader_major_collect(void) {
    if (!g_gc_initialized) return;

    /* 1. Drain young (a minor). Survivors that earned tenure promote into the
     * slab via vader_old_alloc; the rest stay in young.from. */
    g_cycle = VADER_CYCLE_MAJOR_DRAIN;
    vader_minor_collect();

    /* 2. Toggle the epoch mark value. Last epoch's live objects carry the old
     * value, so they now read as "unmarked" with no clear pass; the mark phase
     * re-marks every reachable old object to the new value. (Objects promoted in
     * step 1 carry the pre-toggle value and are likewise re-marked below.) */
    g_mark_value = (g_mark_value == 1u) ? 2u : 1u;

    /* 3. Mark. Old objects don't move — vader_gc_forward sets the mark bit and
     * pushes to the gray worklist instead of copying. Seed from roots + every
     * young survivor (kept whole during the old pass; scanning them marks the
     * old objects they reference), then drain the gray worklist for the
     * transitive old→old closure. */
    g_cycle = VADER_CYCLE_MAJOR;
    g_gray_len = 0;
    vader_gc_scan_roots();
    {
        char* scan = g_young.from.base;
        while (scan < g_young.from.cur) {
            size_t step = vader_gc_scan_object(scan);   /* marks this survivor's old refs */
            if (step == 0) break;
            scan += step;
        }
    }
    /* Conservatively mark old objects reachable only from C locals / registers
     * (the shadow stack doesn't precisely root old refs — see the function). */
    vader_gc_mark_cstack_conservative();
    while (g_gray_len > 0) {
        char* obj = g_gray_stack[--g_gray_len];
        (void) vader_gc_scan_object(obj);
    }

    /* 4. Sweep: rebuild every free list from the unmarked slots. */
    vader_old_sweep();
    g_old_live_after_major = g_old_live_bytes;   /* reclamation-trigger baseline */
    vader_gc_old_histogram();

    /* 5. Re-arm cards over the USED old span only. The mark pass may have observed
     * old→young edges (a marked old object referencing a young survivor) without
     * our separately recording each card; clearing would risk losing such a root,
     * so conservatively dirty every in-use card. Only the carved prefix
     * [g_old_block, g_old_bump) holds objects (the minor walks slots, never the
     * uncommitted reservation tail), so memset just that prefix — touching the
     * whole-reservation table would needlessly commit pages for cards that are
     * never read. */
    memset(vader_card_table, 1, vader_old_used_cards());

    g_cycle = VADER_CYCLE_NONE;
    g_total_collections++;
    vader_atom_gc_collect();
}

/* Public alias. `runtime.collect()` in Vader maps here; tests rely on it
 * forcing a full collection (mark-sweep over old, not just minor). */
void vader_gc_collect(void) {
    vader_major_collect();
}

/* ---- cooperative async scheduler ------------------------------------------
 * See vader.h. A virtual `now` (ms, from 0) + a min-heap of pending wake
 * deadlines. `park` pops the nearest, optionally waits real time for it, and
 * advances `now`. Single-threaded — no locking. */
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
        g_sched_cap = g_sched_cap ? g_sched_cap * 2 : 8;
        g_sched_heap = (int64_t*) realloc(g_sched_heap, g_sched_cap * sizeof(int64_t));
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

vader_i32_t vader_sched_park(void) {
    if (g_sched_len == 0) { return 1; }    /* deadlock: nothing pending */
    int64_t deadline = g_sched_heap[0];
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
    if (deadline > g_sched_now) {
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
    }
    return 0;
}

vader_gc_stats_t vader_gc_get_stats(void) {
    vader_gc_stats_t s;
    /* Old "arena size" now reports the lazily-committed reservation (the cap). */
    s.arena_size = g_gc_initialized ? g_old_capacity : (size_t) VADER_GC_OLD_BYTES;
    if (g_gc_initialized) {
        size_t young_used = (size_t)(g_young.from.cur - g_young.from.base);
        s.bytes_used = young_used + g_old_live_bytes;
    } else {
        s.bytes_used = 0;
    }
    s.total_collections = g_total_collections;
    s.total_copied = g_total_copied;
    s.total_alloc_bytes = g_total_alloc_bytes;
    s.total_alloc_count = g_total_alloc_count;
    return s;
}

/* ----------------------------------------------------------------- profiler
 *
 * Per-pass self-compile profiler, gated by $VADER_PROFILE. The compiler
 * (vader/profile) brackets each pass with vader_prof_begin/end(phase_id);
 * we accumulate wall time, peak-RSS growth, and GC churn per phase, then
 * dump a table to stderr at exit. Phase ids index g_prof_names[] — that
 * table is the single source of truth and is mirrored by the PHASE_*
 * constants in vader/profile/profile.vader. Keep the two in lockstep. */

#define VADER_PROF_MAX_PHASES 16

/* Phase names — index = phase id. Mirror in vader/profile/profile.vader. */
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
    NULL, NULL, NULL, NULL, NULL, NULL,
};

static int       g_prof_enabled = -1;   /* -1 unknown, 0 off, 1 on */
static int       g_prof_atexit_armed = 0;
/* Accumulated per phase. */
static int64_t   g_prof_wall_ns[VADER_PROF_MAX_PHASES];
static int64_t   g_prof_rss_growth[VADER_PROF_MAX_PHASES]; /* peak-RSS delta, bytes */
static int64_t   g_prof_copied[VADER_PROF_MAX_PHASES];     /* GC bytes copied */
static int64_t   g_prof_alloc[VADER_PROF_MAX_PHASES];      /* bytes requested via gc_alloc */
static int64_t   g_prof_alloc_count[VADER_PROF_MAX_PHASES];/* gc_alloc calls */
static int64_t   g_prof_coll[VADER_PROF_MAX_PHASES];       /* GC cycles */
static int64_t   g_prof_calls[VADER_PROF_MAX_PHASES];      /* times entered */
/* In-flight snapshot — passes are sequential, so one slot suffices.
 * g_prof_current holds the phase id currently bracketed (-1 = idle) so a
 * nested prof_begin trips a loud warning rather than silently misattributing. */
static int64_t   g_prof_t0, g_prof_rss0, g_prof_copied0, g_prof_coll0;
static int64_t   g_prof_alloc0, g_prof_alloc_count0;
static int       g_prof_current = -1;

/* All query helpers are internal — the profiler is the only consumer. The
 * Vader-visible GC stats live on the std/runtime intrinsic shims (i32). */

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

/* Current resident set, bytes — best effort, falls back to the peak. */
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

/* Live bytes across young+old (post-collection). */
static int64_t vader_prof_bytes_used(void) { return (int64_t) vader_gc_get_stats().bytes_used; }

static int32_t vader_prof_enabled(void) {
    if (g_prof_enabled < 0) g_prof_enabled = vader_gc_env_bool("VADER_PROFILE");
    return (int32_t) g_prof_enabled;
}

void vader_prof_begin(int32_t phase_id) {
    if (!vader_prof_enabled()) return;
    if (phase_id < 0 || phase_id >= VADER_PROF_MAX_PHASES) return;
    if (!g_prof_atexit_armed) { atexit(vader_prof_dump); g_prof_atexit_armed = 1; }
    if (g_prof_current >= 0) {
        fprintf(stderr, "[VADER_PROFILE] nested prof bracket (phase %d inside %d) — "
                        "timings will misattribute\n", phase_id, g_prof_current);
    }
    g_prof_current = phase_id;
    /* One stats read serves both GC deltas (copied + collections). */
    vader_gc_stats_t s = vader_gc_get_stats();
    g_prof_rss0         = vader_prof_max_rss_bytes();
    g_prof_copied0      = (int64_t) s.total_copied;
    g_prof_coll0        = (int64_t) s.total_collections;
    g_prof_alloc0       = (int64_t) s.total_alloc_bytes;
    g_prof_alloc_count0 = (int64_t) s.total_alloc_count;
    g_prof_t0           = vader_clock_monotonic_ns();   /* start the clock last */
}

void vader_prof_end(int32_t phase_id) {
    if (!vader_prof_enabled()) return;
    if (phase_id < 0 || phase_id >= VADER_PROF_MAX_PHASES) return;
    int64_t t1 = vader_clock_monotonic_ns();       /* stop the clock first */
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

/* ----------------------------------------------------------------- string */

vader_string_t vader_string_new(const char* p, size_t n) {
    return vader_atom_intern(p, n);
}

const char* vader_string_to_cstr(vader_string_t s) {
    return vader_atom_to_cstr(s);
}

void vader_cstr_free(const char* p) {
    vader_atom_cstr_free(p);
}

/* ----------------------------------------------------------------- array */

/* `sizeof(vader_array_buf_t) + capacity * element_size(kind)` without silent
 * integer overflow. With user-controllable `capacity` (e.g. via
 * `array.push` reaching into the gigabytes), the multiplication can wrap
 * `size_t` and produce an under-allocation followed by an OOB write. Trap
 * before the alloc with a clear message instead. */
static size_t vader_array_buf_bytes(size_t capacity, uint8_t element_kind) {
    size_t per_slot = vader_array_element_size(element_kind);
    if (per_slot > 0 && capacity > (SIZE_MAX - sizeof(vader_array_buf_t)) / per_slot) {
        vader_trap("vader_array: capacity overflows size_t");
    }
    return sizeof(vader_array_buf_t) + capacity * per_slot;
}

/* Allocate a fresh array buffer of `capacity` slots with the ARRAY_BUF
 * sentinel as its type tag — the GC scan loop dispatches on that to walk
 * `length` slots dynamically. The struct itself plus its trailing slot
 * area land in a single GC arena allocation. */
static vader_array_buf_t* vader_array_buf_alloc(size_t capacity, uint8_t element_kind, uint32_t element_tag) {
    size_t bytes = vader_array_buf_bytes(capacity, element_kind);
    vader_array_buf_t* buf = (vader_array_buf_t*) vader_gc_alloc(bytes);
    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity     = capacity;
    buf->length       = 0;
    buf->element_kind = element_kind;
    buf->element_tag  = element_tag;
    return buf;
}

/* Forward decl — the explicit length≠capacity allocator (defined with the array
 * construction ops further down). `vader_array_new` is its `cap = max(length, 4)`
 * special case. */
static vader_array_t* vader_array_alloc_cap(uint32_t type_index, size_t length, size_t capacity, uint8_t element_kind, uint32_t element_tag);

vader_array_t* vader_array_new(uint32_t type_index, size_t length, uint8_t element_kind, uint32_t element_tag) {
    /* `cap = max(length, 4)` — the historical default. The single-block alloc +
     * GC-orphan rationale lives on `vader_array_alloc_cap`. */
    return vader_array_alloc_cap(type_index, length, length > 0 ? length : 4, element_kind, element_tag);
}

static vader_array_t* vader_array_resolve(vader_array_t* a);
static void vader_array_resolve_buf(vader_array_t* a);

/* Store a primitive-kind slot — writes the matching primitive width directly
 * to `buf->slots` ; the boxed kind routes through `vader_array_box_slots`. The
 * symmetric LOAD is no longer an out-of-line helper : reads are open-coded at
 * each c-emit access site (typed slots inline, boxed via `vader_array_box_slots`,
 * u8 via `vader_array_read_u8`). Only `push` still needs the out-of-line store. */
static void vader_array_store_slot(vader_array_buf_t* buf, size_t i, vader_box_t v) {
    uint8_t* base = buf->slots;
    switch (buf->element_kind) {
        case VADER_ARRAY_KIND_BOXED: vader_array_box_slots(buf)[i] = v; return;
        case VADER_ARRAY_KIND_U8:   ((uint8_t*)  base)[i] = (uint8_t)  v.payload.i; return;
        case VADER_ARRAY_KIND_U16:  ((uint16_t*) base)[i] = (uint16_t) v.payload.i; return;
        case VADER_ARRAY_KIND_U32:  ((uint32_t*) base)[i] = (uint32_t) v.payload.i; return;
        case VADER_ARRAY_KIND_U64:  ((uint64_t*) base)[i] = (uint64_t) v.payload.i; return;
        case VADER_ARRAY_KIND_I8:   ((int8_t*)   base)[i] = (int8_t)   v.payload.i; return;
        case VADER_ARRAY_KIND_I16:  ((int16_t*)  base)[i] = (int16_t)  v.payload.i; return;
        case VADER_ARRAY_KIND_I32:  ((int32_t*)  base)[i] = (int32_t)  v.payload.i; return;
        case VADER_ARRAY_KIND_I64:  ((int64_t*)  base)[i] = (int64_t)  v.payload.i; return;
        case VADER_ARRAY_KIND_F32:  ((float*)    base)[i] = (float)    v.payload.f; return;
        case VADER_ARRAY_KIND_F64:  ((double*)   base)[i] = (double)   v.payload.f; return;
        case VADER_ARRAY_KIND_CHAR: ((uint32_t*) base)[i] = (uint32_t) v.payload.i; return;
        case VADER_ARRAY_KIND_BOOL: ((uint8_t*)  base)[i] = v.payload.b ? 1 : 0; return;
        case VADER_ARRAY_KIND_REF:  ((void**)    base)[i] = vader_box_to_b1(v); return;  /* T12 raw ref */
        default: vader_trap("vader_array_store_slot: unknown element kind");
    }
}

/* vader_array_get / vader_array_set were the out-of-line, element-kind-
 * dispatched accessors the C emitter called for every `arr[i]` / `arr[i] = v`.
 * Both are now open-coded at the c-emit access site over the kept layout (typed
 * slots inline, boxed via `vader_array_box_slots` + the write barrier, u8 via
 * `vader_array_read_u8`), so neither is emitted any more and both are deleted —
 * the Target-ABI Array-accessor retirement. `push` / `slice` / `new` stay (the
 * GC-coupled construction primitives). */

vader_array_t* vader_array_slice(vader_array_t* a, size_t lo, size_t hi) {
    a = vader_array_resolve(a);
    /* Clamp bounds against the header length (independent of `buf`, so it's
     * valid for both the owning, view, and borrowed cases). */
    if (lo > a->length) lo = a->length;
    if (hi < lo)        hi = lo;
    if (hi > a->length) hi = a->length;
    size_t len = hi - lo;
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Slicing a borrowed byte view yields another borrowed view over the
         * same owner atom : carry `capacity` (element_tag + owner) verbatim,
         * advance `offset` by `lo`. `buf` stays NULL. The alloc may forward
         * `a`, so root it as a box (its `capacity`/`offset`/flag copy verbatim
         * on relocation — §borrowed) and reload after. */
        uint32_t tag = a->header.type_index;
        vader_box_t a_box; a_box.tag = tag; a_box._pad = 0; a_box.payload.obj = a;
        VADER_GC_PUSH1(a_box);
        vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
        VADER_GC_POP();
        a = (vader_array_t*) a_box.payload.obj;
        vader_obj_header_init(view, tag);
        view->length   = len;
        view->capacity = a->capacity;     /* (element_tag << 32) | owner — verbatim */
        view->header._reserved = VADER_ARRAY_FLAG_BORROWED;
        view->offset   = a->offset + lo;
        view->buf      = NULL;
        return view;
    }
    vader_array_resolve_buf(a);
    /* Root the parent array across the alloc — a collection inside
     * `vader_gc_alloc` would forward it otherwise. */
    uint32_t tag = a->header.type_index;
    vader_box_t a_box; a_box.tag = tag; a_box._pad = 0; a_box.payload.obj = a;
    vader_box_t* roots[1] = { &a_box };
    vader_gc_frame_t frame = { vader_gc_top, 1u, 0u, roots };
    vader_gc_top = &frame;
    vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
    vader_gc_top = frame.prev;
    a = (vader_array_t*) a_box.payload.obj;
    vader_obj_header_init(view, tag);
    view->length   = len;
    /* Views aren't growable in-place — push detaches into a fresh buf. */
    view->capacity = len;
    view->offset   = a->offset + lo;
    view->buf      = a->buf;
    return view;
}

/* If `a` was relocated by a collection that fired during a recent allocation,
 * its old header carries a forwarding pointer to the new copy. Caller-side
 * code reloads `a` from a shadow-stack slot, but runtime helpers receive `a`
 * as a raw C pointer — after a GC mid-call the parameter is stale. Resolving
 * the forward keeps the helper sound.
 *
 * A single `vader_gc_alloc` call may run a minor THEN a major (the major
 * runs its own internal minor as `MAJOR_DRAIN`), so an object can be
 * forwarded twice in one allocation site. Loop until the chain terminates. */
static vader_array_t* vader_array_resolve(vader_array_t* a) {
    while (a->header.forward != NULL) a = (vader_array_t*) a->header.forward;
    return a;
}

/* Resolve a pending forward on the array's DATA BUFFER. The buf is a separate
 * GC object from the header (which `vader_array_resolve` resolves), so a
 * mid-call collection may forward it independently — and twice in one alloc
 * (minor THEN major-drain), hence the loop. A NULL buf (borrowed view) is left
 * untouched. Sites that read `a->buf->slots` after a possible safepoint call
 * this; the symmetric counterpart of `vader_array_resolve`. */
static void vader_array_resolve_buf(vader_array_t* a) {
    while (a->buf != NULL && a->buf->header.forward != NULL) {
        a->buf = (vader_array_buf_t*) a->buf->header.forward;
    }
}

void vader_array_push(vader_array_t* a, vader_box_t v) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Defensive : T3042 rejects mutation of a `const u8[]` view. */
        vader_trap("cannot push to a borrowed `const u8[]` byte view");
    }
    /* Three reasons to detach into a fresh buf : (a) cap reached, (b) view
     * with non-zero offset, (c) view whose tail doesn't extend to the buf
     * end (another view aliases the tail slots — growing in place would
     * overwrite them). The owning array meets none of these. */
    bool is_view = a->offset != 0 || a->offset + a->length < a->buf->length;
    if (a->length >= a->capacity || is_view) {
        /* The grow path may run TWO GC cycles inside `vader_array_buf_alloc`
         * (minor → major when the minor doesn't free enough). Each cycle
         * forwards `a` and swaps young from/to halves ; by the second swap
         * the *original* `a` address has been recycled and its forward
         * pointer overwritten by a fresh allocation, so `vader_array_resolve`
         * can't walk the chain anymore. Box `a` here and root the box so
         * the GC's scan_box re-updates `a_box.payload.obj` through every
         * cycle, then reload `a` from the box afterwards. Same trick for
         * `v` whose payload may also need forwarding. */
        uint32_t tag       = a->header.type_index;
        uint8_t  kind      = a->buf->element_kind;
        size_t   elem_size = vader_array_element_size(kind);
        size_t   src_off   = a->offset;
        vader_box_t a_box; a_box.tag = tag; a_box._pad = 0; a_box.payload.obj = a;
        vader_box_t* roots[2] = { &a_box, &v };
        vader_gc_frame_t frame = { vader_gc_top, 2u, 0u, roots };
        vader_gc_top = &frame;
        size_t cap = a->capacity == 0 ? 4 : a->capacity * 2;
        if (cap <= a->length) cap = a->length + 1;
        vader_array_buf_t* fresh = vader_array_buf_alloc(cap, kind, a->buf->element_tag);
        a = (vader_array_t*) a_box.payload.obj;
        vader_array_buf_t* old = a->buf;
        while (old != NULL && old->header.forward != NULL) {
            old = (vader_array_buf_t*) old->header.forward;
        }
        if (a->length > 0 && old != NULL) {
            memcpy(fresh->slots, old->slots + src_off * elem_size, a->length * elem_size);
        }
        fresh->length = a->length;
        a->buf      = fresh;
        a->capacity = cap;
        a->offset   = 0;
        /* `a` may be old while `fresh` is young — mark the card holding `a`. */
        VADER_WRITE_BARRIER(a);
        vader_gc_top = frame.prev;
    }
    vader_array_store_slot(a->buf, a->offset + a->length, v);
    a->length += 1;
    if (a->offset + a->length > a->buf->length) {
        a->buf->length = a->offset + a->length;
    }
    VADER_WRITE_BARRIER(a->buf);
}

/* Allocate an owning array with an explicit `length` AND `capacity`. The single
 * source of truth for array construction — `vader_array_new` is the
 * `cap = max(length, 4)` case, `vader_array_repeat` passes `length 0, capacity n`
 * for `[] * n` reserve.
 *
 * Single-block alloc: the struct is followed by an inline buf in the same GC
 * alloc. A two-step alloc has a window where one half is unreachable from the
 * shadow stack — a collection mid-construction would lose the orphan; the
 * combined block sidesteps it. (Push later allocates a *separate* fresh buf and
 * rebinds `a->buf`; the GC then relocates the two halves independently.)
 *
 * Slots `[0, length)` are left uninitialised — the caller fills them with no
 * intervening allocation (memcpy is not a safepoint), so the GC never scans a
 * garbage slot; `buf->length` is set to `length` so a BOXED tail beyond
 * `length` is never walked. */
static vader_array_t* vader_array_alloc_cap(uint32_t type_index, size_t length, size_t capacity, uint8_t element_kind, uint32_t element_tag) {
    if (capacity < length) capacity = length;
    size_t struct_bytes = vader_gc_align(sizeof(vader_array_t));
    size_t buf_bytes    = vader_array_buf_bytes(capacity, element_kind);
    if (struct_bytes > SIZE_MAX - buf_bytes) {
        vader_trap("vader_array: total alloc size overflows size_t");
    }
    char* block = (char*) vader_gc_alloc(struct_bytes + buf_bytes);
    vader_array_t* a = (vader_array_t*) block;
    vader_array_buf_t* buf = (vader_array_buf_t*) (block + struct_bytes);
    vader_obj_header_init(a, type_index);
    a->length   = length;
    a->capacity = capacity;
    a->offset   = 0;
    a->buf      = buf;
    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity     = capacity;
    buf->length       = length;
    buf->element_kind = element_kind;
    buf->element_tag  = element_tag;
    return a;
}

/* Resolve `src` to a contiguous source byte region + its element metadata,
 * unifying the owning and borrowed-view cases : a `const u8[]` view reads the
 * owner atom's bytes (1-byte slots), an owning array reads its buf slots at the
 * view offset. Both are contiguous, so a single `memcpy` per repetition serves
 * primitive AND boxed kinds (boxes copy verbatim). `extra` advances the start
 * by `extra` elements (for `copy_to`'s `src_start`). Caller must have resolved
 * any pending forward on `src` first ; this does NOT cross a safepoint. */
static const uint8_t* vader_array_src_region(vader_array_t* src, size_t extra, uint8_t* out_kind, uint32_t* out_tag, size_t* out_elem_size) {
    uint8_t  kind;
    uint32_t tag;
    size_t   esz;
    const uint8_t* data;
    if (vader_array_is_borrowed(src)) {
        kind = VADER_ARRAY_KIND_U8;          /* borrowed views are const u8[] */
        tag  = vader_array_borrowed_tag(src);
        esz  = 1;
        data = (const uint8_t*) vader_atom_data(vader_array_borrowed_owner(src)) + (src->offset + extra);
    } else {
        vader_array_resolve_buf(src);
        kind = src->buf->element_kind;
        tag  = src->buf->element_tag;
        esz  = vader_array_element_size(kind);
        data = src->buf->slots + (src->offset + extra) * esz;
    }
    *out_kind = kind;
    *out_tag  = tag;
    *out_elem_size = esz;
    return data;
}

/* `[lhs] * n` — fresh array repeating `src`'s elements `n` times. `length =
 * src.length * n`, `capacity = max(length, n)` so `[] * n` (src.length 0) yields
 * an empty array with n slots reserved (the preallocation case — no named
 * `with_capacity`). The result reuses `src`'s array type / element kind / tag.
 * For a ref element the SAME reference is repeated n times (shallow, evaluate-
 * once — the documented semantics). */
vader_array_t* vader_array_repeat(vader_array_t* src, size_t n) {
    src = vader_array_resolve(src);
    uint32_t type_index = src->header.type_index;
    size_t src_len = src->length;
    if (src_len != 0 && n > SIZE_MAX / src_len) {
        vader_trap("vader_array: repeat length overflows size_t");
    }
    size_t out_len = src_len * n;
    size_t cap = out_len > n ? out_len : n;
    /* Read the element metadata before the alloc (it may relocate `src`). */
    uint8_t kind; uint32_t tag; size_t esz;
    vader_array_src_region(src, 0, &kind, &tag, &esz);
    /* Root `src` across the result allocation — a collection there forwards it. */
    vader_box_t src_box; src_box.tag = type_index; src_box._pad = 0; src_box.payload.obj = src;
    VADER_GC_PUSH1(src_box);
    vader_array_t* out = vader_array_alloc_cap(type_index, out_len, cap, kind, tag);
    VADER_GC_POP();
    src = (vader_array_t*) src_box.payload.obj;
    if (out_len == 0) return out;          /* `[] * n` reserve-only, or n == 0 */
    /* Recompute the source region after the possible relocation, then stamp the
     * src block into the result n times. No safepoint between here and return. */
    const uint8_t* src_data = vader_array_src_region(src, 0, &kind, &tag, &esz);
    uint8_t* dst_data = out->buf->slots;
    size_t block = src_len * esz;
    for (size_t i = 0; i < n; i++) {
        memcpy(dst_data + i * block, src_data, block);
    }
    if (kind == VADER_ARRAY_KIND_BOXED || kind == VADER_ARRAY_KIND_REF) {
        VADER_WRITE_BARRIER(out->buf);   /* coarse card covers the whole buf */
    }
    return out;
}

/* `dst.push_all(src)` — append every element of `src` to `dst`, growing `dst`
 * once if needed. Mirrors `vader_array_push`'s grow + rooting (the buf alloc may
 * collect twice, forwarding both arrays and `dst`'s old buf). Handles
 * `push_all(x, x)` : after a grow `src` reads the fresh buf whose head holds the
 * copied originals, and the append range never overlaps the source range. */
void vader_array_push_all(vader_array_t* dst, vader_array_t* src) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(dst))) {
        vader_trap("cannot push_all to a borrowed `const u8[]` byte view");
    }
    dst = vader_array_resolve(dst);
    src = vader_array_resolve(src);
    size_t add = src->length;
    if (add == 0) return;
    size_t need = dst->length + add;
    if (need < dst->length) vader_trap("vader_array: push_all length overflows size_t");
    bool is_view = dst->offset != 0 || dst->offset + dst->length < dst->buf->length;
    if (need > dst->capacity || is_view) {
        uint32_t dtag    = dst->header.type_index;
        uint8_t  kind    = dst->buf->element_kind;
        size_t   esz     = vader_array_element_size(kind);
        uint32_t btag    = dst->buf->element_tag;
        size_t   src_off = dst->offset;
        vader_box_t d_box; d_box.tag = dtag; d_box._pad = 0; d_box.payload.obj = dst;
        vader_box_t s_box; s_box.tag = src->header.type_index; s_box._pad = 0; s_box.payload.obj = src;
        vader_box_t* roots[2] = { &d_box, &s_box };
        vader_gc_frame_t frame = { vader_gc_top, 2u, 0u, roots };
        vader_gc_top = &frame;
        size_t cap = dst->capacity == 0 ? 4 : dst->capacity * 2;
        if (cap < need) cap = need;
        vader_array_buf_t* fresh = vader_array_buf_alloc(cap, kind, btag);
        dst = (vader_array_t*) d_box.payload.obj;
        src = (vader_array_t*) s_box.payload.obj;
        vader_array_buf_t* old = dst->buf;
        while (old != NULL && old->header.forward != NULL) old = (vader_array_buf_t*) old->header.forward;
        if (dst->length > 0 && old != NULL) {
            memcpy(fresh->slots, old->slots + src_off * esz, dst->length * esz);
        }
        fresh->length = dst->length;
        dst->buf      = fresh;
        dst->capacity = cap;
        dst->offset   = 0;
        VADER_WRITE_BARRIER(dst);
        vader_gc_top = frame.prev;
    }
    /* Append src[0..add) at dst[length..). Recompute the source region after any
     * relocation. No safepoint from here to return, so the pointers are stable. */
    uint8_t kind; uint32_t tag; size_t esz;
    const uint8_t* src_data = vader_array_src_region(src, 0, &kind, &tag, &esz);
    uint8_t* dst_data = dst->buf->slots + (dst->offset + dst->length) * esz;
    memcpy(dst_data, src_data, add * esz);
    dst->length += add;
    if (dst->offset + dst->length > dst->buf->length) {
        dst->buf->length = dst->offset + dst->length;
    }
    if (dst->buf->element_kind == VADER_ARRAY_KIND_BOXED ||
        dst->buf->element_kind == VADER_ARRAY_KIND_REF) {
        VADER_WRITE_BARRIER(dst->buf);
    }
}

/* `src.copy_to(src_start, dst, dst_start, len)` — positional, overlap-safe
 * (`memmove`) copy of `len` elements from `src[src_start..]` into an EXISTING
 * `dst[dst_start..]` region. `dst` must already be long enough (traps otherwise)
 * — this overwrites, it does not grow. The basis for future `insert`/`remove`.
 * No allocation anywhere, hence no GC / no rooting : the argument pointers are
 * stable for the whole call. */
void vader_array_copy(vader_array_t* src, size_t src_start, vader_array_t* dst, size_t dst_start, size_t len) {
    if (len == 0) return;
    if (VADER_UNLIKELY(vader_array_is_borrowed(dst))) {
        vader_trap("cannot copy into a borrowed `const u8[]` byte view");
    }
    src = vader_array_resolve(src);
    dst = vader_array_resolve(dst);
    if (src_start > src->length || len > src->length - src_start) {
        vader_trap("vader_array_copy: source range out of bounds");
    }
    if (dst_start > dst->length || len > dst->length - dst_start) {
        vader_trap("vader_array_copy: destination range out of bounds (dst must already be long enough)");
    }
    vader_array_resolve_buf(dst);
    uint8_t  kind = dst->buf->element_kind;
    size_t   esz  = vader_array_element_size(kind);
    uint8_t  skind; uint32_t stag; size_t sesz;
    const uint8_t* src_data = vader_array_src_region(src, src_start, &skind, &stag, &sesz);
    uint8_t* dst_data = dst->buf->slots + (dst->offset + dst_start) * esz;
    memmove(dst_data, src_data, len * esz);
    if (kind == VADER_ARRAY_KIND_BOXED || kind == VADER_ARRAY_KIND_REF) {
        VADER_WRITE_BARRIER(dst->buf);
    }
}

/* `arr.remove_last()` — pop the last element, shrink the length by one, and
 * return the element as a pre-tagged box (the boxed kind's slot box verbatim ;
 * a primitive read boxed with the static `element_tag`). Returns `vader_box_null`
 * on an empty array — the `T | null` null variant. Rejects borrowed views (a
 * `const u8[]` is read-only, T3042). No allocation, so no rooting. */
vader_box_t vader_array_remove_last(vader_array_t* a) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        vader_trap("cannot remove_last from a borrowed `const u8[]` byte view");
    }
    a = vader_array_resolve(a);
    if (a->length == 0) return vader_box_null();
    vader_array_resolve_buf(a);
    size_t idx = a->offset + a->length - 1;
    vader_array_buf_t* buf = a->buf;
    uint32_t tag = buf->element_tag;
    uint8_t* base = buf->slots;
    vader_box_t out;
    out._pad = 0;
    switch (buf->element_kind) {
        case VADER_ARRAY_KIND_BOXED: out = vader_array_box_slots(buf)[idx]; break;
        case VADER_ARRAY_KIND_U8:   out.tag = tag; out.payload.i = ((uint8_t*)  base)[idx]; break;
        case VADER_ARRAY_KIND_U16:  out.tag = tag; out.payload.i = ((uint16_t*) base)[idx]; break;
        case VADER_ARRAY_KIND_U32:  out.tag = tag; out.payload.i = ((uint32_t*) base)[idx]; break;
        case VADER_ARRAY_KIND_U64:  out.tag = tag; out.payload.i = (vader_i64_t) ((uint64_t*) base)[idx]; break;
        case VADER_ARRAY_KIND_I8:   out.tag = tag; out.payload.i = ((int8_t*)   base)[idx]; break;
        case VADER_ARRAY_KIND_I16:  out.tag = tag; out.payload.i = ((int16_t*)  base)[idx]; break;
        case VADER_ARRAY_KIND_I32:  out.tag = tag; out.payload.i = ((int32_t*)  base)[idx]; break;
        case VADER_ARRAY_KIND_I64:  out.tag = tag; out.payload.i = ((int64_t*)  base)[idx]; break;
        case VADER_ARRAY_KIND_F32:  out.tag = tag; out.payload.f = (vader_f64_t) ((float*)  base)[idx]; break;
        case VADER_ARRAY_KIND_F64:  out.tag = tag; out.payload.f = ((double*)   base)[idx]; break;
        case VADER_ARRAY_KIND_CHAR: out.tag = tag; out.payload.i = ((uint32_t*) base)[idx]; break;
        case VADER_ARRAY_KIND_BOOL: out.tag = tag; out.payload.b = ((uint8_t*)  base)[idx] != 0; break;
        case VADER_ARRAY_KIND_REF:  out = vader_ref_box(((void**) base)[idx]); break;  /* T12 : tag from header */
        default: vader_trap("vader_array_remove_last: unknown element kind");
    }
    /* If this array OWNS its buffer (offset 0, tail flush with the buffer end),
     * shrink the buffer length alongside the array length. Otherwise the owner
     * keeps `offset + length < buf->length` and the next `vader_array_push`
     * mistakes it for a slice view, detaching into a fresh capacity-DOUBLED
     * buffer — so a `remove_last` + `push` worklist loop grows the backing store
     * exponentially (correct on the VM, OOM on native). Genuine views (offset
     * != 0, or a shorter prefix) don't match, so slice isolation is unchanged. */
    bool owns_tail = (a->offset == 0 && a->offset + a->length == buf->length);
    a->length -= 1;
    if (owns_tail) { buf->length -= 1; }
    return out;
}

/* `arr.clear()` — drop every element (length 0), keeping the buf + capacity for
 * reuse. Rejects borrowed views (read-only, T3042). */
void vader_array_clear(vader_array_t* a) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        vader_trap("cannot clear a borrowed `const u8[]` byte view");
    }
    a = vader_array_resolve(a);
    a->length = 0;
}

/* ----------------------------------------------------------------- std/string */

size_t vader_string_byte_len(vader_string_t s) {
    return vader_atom_len(s);
}

/* Walk the UTF-8 buffer counting codepoints ; return the byte offset of
 * the `cp_index`-th codepoint, clamped to the atom's length. Invalid
 * continuation bytes count as 1-byte codepoints (mirrors
 * `vader_string_char_at`'s truncated-UTF-8 handling). O(n) in `cp_index`. */
static size_t vader_string_codepoint_byte_offset(vader_string_t s, size_t cp_index) {
    const char* data = vader_atom_data(s);
    size_t len = vader_atom_len(s);
    size_t cp = 0;
    size_t i  = 0;
    while (i < len && cp < cp_index) {
        uint8_t b = (uint8_t) data[i];
        size_t step;
        if (b < 0x80u)       step = 1;
        else if (b < 0xC0u)  step = 1;   /* stray continuation byte */
        else if (b < 0xE0u)  step = 2;
        else if (b < 0xF0u)  step = 3;
        else                 step = 4;
        if (i + step > len) step = len - i;
        i  += step;
        cp += 1;
    }
    return i;
}

/* `string[lo..<hi]` semantic : `lo` and `hi` are codepoint indices.
 * Returns the canonical atom for the byte range (intern-deduped or
 * fresh slice atom borrowing into the parent buffer). */
vader_string_t vader_string_slice_codepoints(vader_string_t s, size_t cp_lo, size_t cp_hi) {
    if (cp_hi < cp_lo) cp_hi = cp_lo;
    size_t byte_lo = vader_string_codepoint_byte_offset(s, cp_lo);
    size_t byte_hi = vader_string_codepoint_byte_offset(s, cp_hi);
    if (byte_hi <= byte_lo) return VADER_ATOM_EMPTY;
    return vader_atom_slice(s, byte_lo, byte_hi - byte_lo);
}

/* `s[i]` semantic — codepoint at codepoint-index `i`. Traps on OOB. */
vader_char_t vader_string_codepoint_at(vader_string_t s, size_t cp_index) {
    size_t byte_off = vader_string_codepoint_byte_offset(s, cp_index);
    if (byte_off >= vader_atom_len(s)) vader_trap("string codepoint index out of bounds");
    return vader_string_char_at(s, byte_off);
}


vader_char_t vader_string_char_at(vader_string_t s, size_t i) {
    /* Trap on OOB to match the array-access bounds contract — silently returning
     * 0 made callers confuse "real NUL byte" with "out of bounds". The
     * truncated-UTF-8 returns below stay as `0` / `0xFFFD` because they
     * surface mid-codepoint encoding errors, not access violations. */
    size_t len = vader_atom_len(s);
    if (i >= len) vader_trap("string index out of bounds");
    const uint8_t* p = (const uint8_t*)(vader_atom_data(s) + i);
    size_t rem = len - i;
    uint8_t b = *p;
    if (b < 0x80) return b;
    if (b < 0xC0) return 0xFFFDu;  /* continuation byte as lead: invalid UTF-8 */
    if (b < 0xE0) {
        if (rem < 2) return 0;
        return (vader_char_t)(((b & 0x1Fu) << 6) | (p[1] & 0x3Fu));
    }
    if (b < 0xF0) {
        if (rem < 3) return 0;
        return (vader_char_t)(((b & 0x0Fu) << 12) | ((p[1] & 0x3Fu) << 6) | (p[2] & 0x3Fu));
    }
    if (rem < 4) return 0;
    return (vader_char_t)(((b & 0x07u) << 18) | ((p[1] & 0x3Fu) << 12) | ((p[2] & 0x3Fu) << 6) | (p[3] & 0x3Fu));
}

/* Zero-copy `const u8[]` view over `s`'s interned bytes — see the header
 * decl. Allocates only the array header ; `buf` stays NULL and reads route
 * through `vader_atom_data(s)` (`vader_array_read_u8` / `_slice`). `capacity`
 * packs `(elem_tag << 32) | owner_atom_id` so reads box each byte with the
 * right element tag and `vader_atom_mark_heap` recovers the owner (low 32
 * bits). The view is flagged VADER_ARRAY_FLAG_BORROWED. 64-bit `capacity`
 * assumed (the runtime targets 64-bit throughout).
 *
 * `s` needs no extra rooting across the alloc : it is an atom id (a value,
 * not a heap pointer) and the caller holds the source string live on the
 * shadow stack, so any major cycle inside `vader_gc_alloc` keeps the atom
 * marked. No allocation runs between the alloc and the field writes, so
 * `view` cannot move before it is populated. */
vader_array_t* vader_string_bytes_view(vader_string_t s, uint32_t arr_type, uint32_t elem_tag) {
    size_t len = vader_atom_len(s);
    vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
    vader_obj_header_init(view, arr_type);
    view->length = len;
    view->offset = 0;
    view->buf    = NULL;
    vader_array_make_borrowed(view, elem_tag, s);   /* sets flag + packs capacity */
    return view;
}

/* Inverse of `vader_string_bytes_view` — see the header. A borrowed view
 * aliases `owner[offset .. offset+len]`, so `vader_atom_slice` reinterprets
 * those bytes as a string atom in O(1) (intern-deduped, no copy of the byte
 * storage). A materialised `u8[]` (rare — e.g. a built array) is gathered
 * byte-by-byte and interned. Bytes are taken verbatim ; no UTF-8 validation. */
vader_string_t vader_string_as_string(vader_array_t* a) {
    a = vader_array_resolve(a);
    size_t len = a->length;
    if (len == 0) return VADER_ATOM_EMPTY;
    if (vader_array_is_borrowed(a)) {
        return vader_atom_slice(vader_array_borrowed_owner(a), a->offset, len);
    }
    /* Materialised KIND_U8 buffer : read the slots directly and intern a copy.
     * No Vader alloc in the loop (`malloc` is host), so `a->buf` stays valid
     * once resolved (the header was already resolved above). */
    vader_array_resolve_buf(a);
    char* buf = (char*) malloc(len + 1u);
    if (buf == NULL) vader_trap("vader_string_as_string: buffer malloc failed");
    const uint8_t* src = (const uint8_t*) a->buf->slots;
    for (size_t i = 0; i < len; i++) {
        buf[i] = (char) src[a->offset + i];
    }
    return vader_atom_intern_take(buf, len);
}

/* Box the host argv into a `[string]` Vader array. Called from emitted main
 * when the user's `main` takes an `[string]` parameter. The caller passes the
 * BcType indices for the array type and the string element type (the emitter
 * knows them at codegen time).
 *
 * Each `vader_array_push` may collect; the shadow-stack frame keeps `arr_box`
 * reachable so its `payload.obj` tracks the array across moves. */
vader_array_t* vader_runtime_argv(int argc, char** argv, uint32_t arr_type, uint32_t str_type) {
    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
    VADER_GC_PUSH1(arr_box);
    for (int i = 0; i < argc; i++) {
        const char* a = argv[i];
        size_t len = strlen(a);
        vader_array_push((vader_array_t*) arr_box.payload.obj,
                         vader_box_string(str_type, vader_string_new(a, len)));
    }
    vader_array_t* result = (vader_array_t*) arr_box.payload.obj;
    VADER_GC_POP();
    return result;
}

/* ----------------------------------------------------------------- I/O */

/* `stream_tag` mirrors `std/io::Stream` ; anything outside {Stdout, Stderr}
 * traps. The `println` / `eprintln` newline emission lives in the Vader-side
 * wrappers, not here. */
#define VADER_STREAM_STDOUT ((int32_t) 0)
#define VADER_STREAM_STDERR ((int32_t) 1)

void vader_write(int32_t stream_tag, vader_string_t s) {
    FILE* f;
    if      (stream_tag == VADER_STREAM_STDOUT) f = stdout;
    else if (stream_tag == VADER_STREAM_STDERR) f = stderr;
    else    vader_trap("vader_write: invalid stream tag");
    fwrite(vader_atom_data(s), 1, vader_atom_len(s), f);
    fflush(f);
}

/* Byte-oriented file I/O. `read_file_bytes` reads the whole file into a fresh
 * owned `u8[]` (no intern, no UTF-8 reinterpretation) — `fread` lands directly
 * in the array's slots. No Vader allocation runs between `vader_array_new` and
 * the return, so `arr` cannot move before it is boxed. */
vader_box_t vader_read_file_bytes(vader_string_t path, uint32_t arr_type,
                                  uint32_t elem_tag, uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(path);
    FILE* f = fopen(p, "rb");
    vader_atom_cstr_free(p);
    if (f == NULL) return vader_box_string(err_tag, vader_string_new("file not found", 14));

    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f); return vader_box_string(err_tag, vader_string_new("fseek failed", 12));
    }
    long size = ftell(f);
    if (size < 0) { fclose(f); return vader_box_string(err_tag, vader_string_new("ftell failed", 12)); }
    if ((unsigned long) size > SIZE_MAX / 2) {
        fclose(f); return vader_box_string(err_tag, vader_string_new("file too large", 14));
    }
    if (fseek(f, 0, SEEK_SET) != 0) {
        fclose(f); return vader_box_string(err_tag, vader_string_new("fseek failed", 12));
    }

    vader_array_t* arr = vader_array_new(arr_type, (size_t) size, VADER_ARRAY_KIND_U8, elem_tag);
    size_t n = (size_t) size > 0 ? fread(arr->buf->slots, 1, (size_t) size, f) : 0;
    fclose(f);
    if (n != (size_t) size) {
        return vader_box_string(err_tag, vader_string_new("short read", 10));
    }
    return vader_box_obj(arr_type, arr);
}

/* Write a `u8[]`'s raw bytes verbatim. Handles both a borrowed view (bytes live
 * in the owner atom) and a materialised buffer — mirrors `vader_string_as_string`. */
vader_box_t vader_write_file_bytes(vader_string_t path, vader_array_t* content,
                                   uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(path);
    FILE* f = fopen(p, "wb");
    vader_atom_cstr_free(p);
    if (f == NULL) return vader_box_string(err_tag, vader_string_new("open failed", 11));

    content = vader_array_resolve(content);
    size_t len = content->length;
    size_t n = len;
    if (len > 0) {
        if (vader_array_is_borrowed(content)) {
            const uint8_t* src = (const uint8_t*) vader_atom_data(vader_array_borrowed_owner(content));
            n = fwrite(src + content->offset, 1, len, f);
        } else {
            vader_array_resolve_buf(content);
            const uint8_t* src = (const uint8_t*) content->buf->slots;
            n = fwrite(src + content->offset, 1, len, f);
        }
    }
    fclose(f);
    if (n != len) return vader_box_string(err_tag, vader_string_new("short write", 11));
    return vader_box_null();
}

vader_box_t vader_read_line(uint32_t ok_tag, uint32_t err_tag) {
    char buf[4096];
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return vader_box_string(err_tag, vader_string_new("EOF", 3));
    }
    size_t n = strlen(buf);
    if (n > 0 && buf[n - 1] == '\n') n--;
    return vader_box_string(ok_tag, vader_string_new(buf, n));
}

/* Switch stdin/stdout/stderr to binary mode on Windows. The CRT default is
 * text mode, which silently translates `\r\n` ↔ `\n` and breaks any
 * length-prefixed binary transport (LSP, MCP, custom RPC) AND every `dump` /
 * `build` / `fmt` stdout (LF on disk, CRLF on the wire). stderr matters too:
 * the VM's runtime-error / panic messages are diffed byte-for-byte by the
 * snapshot suite, and text-mode `\n`→`\r\n` on stderr makes every such line
 * mismatch by an invisible trailing `\r` on Windows. Called at program startup
 * (`vader_atom_init_with_comptime`) and at the first `vader_read_stdin` ;
 * idempotent via the static flag. POSIX has no such concept — the helper is a
 * no-op there. */
static int g_stdio_binary_ready = 0;

static void vader_ensure_stdio_binary(void) {
    if (g_stdio_binary_ready) return;
    g_stdio_binary_ready = 1;
#if defined(_WIN32)
    _setmode(_fileno(stdin),  _O_BINARY);
    _setmode(_fileno(stdout), _O_BINARY);
    _setmode(_fileno(stderr), _O_BINARY);
#endif
}

/* Read EXACTLY `n` bytes from stdin into a fresh string. Loops over
 * `fread` until `n` bytes have been accumulated or EOF is reached. EOF
 * before `n` bytes is an error — the LSP transport relies on this
 * "exactly N bytes" contract for Content-Length framing. Forces binary
 * mode on first call so `\r\n` survives the read on Windows. */
vader_box_t vader_read_stdin(size_t n, uint32_t ok_tag, uint32_t err_tag) {
    vader_ensure_stdio_binary();
    if (n == 0) {
        return vader_box_string(ok_tag, vader_string_new("", 0));
    }
    char* buf = (char*) malloc(n + 1u);
    if (buf == NULL) vader_trap("read_stdin: malloc failed");
    size_t got = 0;
    while (got < n) {
        size_t r = fread(buf + got, 1, n - got, stdin);
        if (r == 0) {
            if (feof(stdin)) {
                free(buf);
                return vader_box_string(err_tag, vader_string_new("EOF", 3));
            }
            if (ferror(stdin)) {
                free(buf);
                return vader_box_string(err_tag, vader_string_new("stdin read error", 16));
            }
            /* No data, no EOF, no error — interrupted read. Retry. */
            continue;
        }
        got += r;
    }
    return vader_box_string(ok_tag, vader_atom_intern_take(buf, n));
}

/* Switch stdin to unbuffered so `fread` (used by `vader_read_stdin`) issues an
 * exact `read()` with no readahead — keeping `poll(STDIN_FILENO)` consistent
 * with what the next `read_stdin` will consume. Without this, fread's userspace
 * buffer can swallow a queued frame and hide it from `poll()`, breaking the LSP
 * debounce (poll reports "idle" while a full frame already sits in the buffer).
 * A length-prefixed RPC server calls this once at startup, BEFORE any stdin
 * read — the streaming `vader run prog.virt` stdin path keeps its buffering. */
void vader_set_stdin_unbuffered(void) {
    setvbuf(stdin, NULL, _IONBF, 0);
}

/* Return true iff stdin has data ready within `timeout_ms` (0 = poll, no wait).
 * Used by the LSP event loop to detect a quiescent edit window: drain the burst
 * of `didChange` notifications, then run the typecheck once. Relies on stdin
 * being unbuffered (`vader_set_stdin_unbuffered`) so the raw fd reflects the real
 * pending bytes. A hangup (peer closed the pipe) reports ready so the caller's
 * next read observes EOF rather than spinning. */
vader_bool_t vader_poll_stdin(int32_t timeout_ms) {
#if defined(_WIN32)
    /* LSP stdin is a pipe (the editor's anonymous pipe). PeekNamedPipe reports
     * bytes available WITHOUT consuming them — it works on anonymous pipes too,
     * despite the name. It's instantaneous, so emulate the timeout by polling in
     * small Sleep slices; this loop only runs during the debounce settle window
     * (once per burst), never per byte. With unbuffered stdin
     * (`vader_set_stdin_unbuffered`) the kernel pipe PeekNamedPipe inspects matches
     * what the next `fread` will consume. */
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE || h == NULL) return 1; /* let the read attempt observe the state */
    DWORD waited = 0;
    for (;;) {
        DWORD avail = 0;
        if (!PeekNamedPipe(h, NULL, 0, NULL, &avail, NULL)) {
            /* Not a pipe (console / redirected file) or peer closed the pipe —
             * report ready so the next read proceeds or observes EOF, as the
             * pre-debounce code did. Never reports a false "idle" that could
             * spin. */
            return 1;
        }
        if (avail > 0) return 1;
        if (timeout_ms >= 0 && waited >= (DWORD) timeout_ms) return 0;
        DWORD slice = 5;
        if (timeout_ms >= 0) {
            DWORD remaining = (DWORD) timeout_ms - waited;
            if (remaining < slice) slice = remaining;
        }
        Sleep(slice);
        waited += slice;
    }
#else
    struct pollfd pfd;
    pfd.fd      = STDIN_FILENO;
    pfd.events  = POLLIN;
    pfd.revents = 0;
    int r = poll(&pfd, 1, timeout_ms);
    /* r < 0 (e.g. EINTR) → treat as "nothing pending": the caller proceeds to
     * flush, which is harmless. r == 0 → timeout. r > 0 → data or hangup. */
    return r > 0;
#endif
}

/* `exists` / `is_dir` / `read_dir` — filesystem queries split across POSIX
 * (`dirent.h`, `sys/stat.h`) and Windows (`FindFirstFileA` /
 * `GetFileAttributesA`). `exists` must NOT be implemented via `fopen` : the
 * Windows CRT refuses to open a directory as a file, so an `fopen`-based
 * check reports every directory as missing. That silently empties the
 * module-discovery walk — `walk_root` (vader/resolver/discover.vader) guards
 * on `exists(dir)` and bails before indexing anything, so every compile on
 * Windows fails with R2001. Use the stat / attribute query instead. Path
 * arguments come as atom IDs ; we materialise a NUL-terminated C string via
 * `vader_atom_to_cstr` and intern dirent names back through `vader_string_new`. */

#if defined(_WIN32)

vader_bool_t vader_exists(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    DWORD attr = GetFileAttributesA(p);
    vader_atom_cstr_free(p);
    return attr != INVALID_FILE_ATTRIBUTES;
}

vader_bool_t vader_is_dir(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    DWORD attr = GetFileAttributesA(p);
    vader_atom_cstr_free(p);
    return attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY);
}

vader_box_t vader_read_dir(vader_string_t path, uint32_t arr_type,
                           uint32_t str_type, uint32_t err_tag) {
    /* FindFirstFileA expects a glob — append "\\*". */
    const char* p = vader_atom_to_cstr(path);
    size_t plen = vader_atom_len(path);
    char* pat = (char*) malloc(plen + 3);
    if (pat == NULL) {
        vader_atom_cstr_free(p);
        vader_trap("read_dir: malloc failed");
    }
    memcpy(pat, p, plen);
    size_t pat_len = plen;
    if (pat_len > 0 && pat[pat_len - 1] != '\\' && pat[pat_len - 1] != '/') {
        pat[pat_len++] = '\\';
    }
    pat[pat_len++] = '*';
    pat[pat_len] = '\0';
    vader_atom_cstr_free(p);

    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pat, &fd);
    free(pat);
    if (h == INVALID_HANDLE_VALUE) {
        return vader_box_string(err_tag, vader_string_new("read_dir failed", 15));
    }

    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
    VADER_GC_PUSH1(arr_box);
    do {
        const char* name = fd.cFileName;
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))) continue;
        size_t n = strlen(name);
        /* `fd.cFileName` lives on the stack and is overwritten by the
         * next FindNextFileA — intern via `vader_string_new` to copy the
         * bytes into the atom table before the next iteration. */
        vader_array_push((vader_array_t*) arr_box.payload.obj,
                         vader_box_string(str_type, vader_string_new(name, n)));
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    vader_box_t result = arr_box;
    VADER_GC_POP();
    return result;
}

#else  /* POSIX */

#include <dirent.h>
#include <sys/stat.h>

vader_bool_t vader_exists(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    struct stat st;
    int rc = stat(p, &st);
    vader_atom_cstr_free(p);
    return rc == 0;
}

vader_bool_t vader_is_dir(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    struct stat st;
    int rc = stat(p, &st);
    vader_atom_cstr_free(p);
    return rc == 0 && S_ISDIR(st.st_mode);
}

vader_box_t vader_read_dir(vader_string_t path, uint32_t arr_type,
                           uint32_t str_type, uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(path);
    DIR* d = opendir(p);
    vader_atom_cstr_free(p);
    if (d == NULL) {
        return vader_box_string(err_tag, vader_string_new("read_dir failed", 15));
    }

    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
    VADER_GC_PUSH1(arr_box);
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        const char* name = ent->d_name;
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))) continue;
        size_t n = strlen(name);
        /* Intern the dirent name directly — the buffer is reused on the
         * next readdir, so the atom dedupe/copy is the correct ownership
         * transfer. */
        vader_array_push((vader_array_t*) arr_box.payload.obj,
                         vader_box_string(str_type, vader_string_new(name, n)));
    }
    closedir(d);
    vader_box_t result = arr_box;
    VADER_GC_POP();
    return result;
}

#endif  /* _WIN32 / POSIX */

/* ----------------------------------------------------------------- location
 *
 * `vader_current_executable_location` backs the `std/io` intrinsic the resolver
 * uses to find the stdlib + C-runtime next to the running binary (sidecar
 * layout). Returns a `/`-separated path, falling back to "." when the platform
 * query fails, so resolution degrades to cwd-relative rather than breaking. */

static void vader_path_to_slash(char* s, size_t n) {
    for (size_t i = 0; i < n; i++) { if (s[i] == '\\') s[i] = '/'; }
}

vader_string_t vader_current_executable_location(void) {
    char buf[4096];
    size_t n = 0;
#if defined(_WIN32)
    DWORD len = GetModuleFileNameA(NULL, buf, (DWORD) sizeof(buf));
    if (len > 0 && len < sizeof(buf)) n = (size_t) len;
#elif defined(__APPLE__)
    char raw[4096];
    uint32_t cap = (uint32_t) sizeof(raw);
    if (_NSGetExecutablePath(raw, &cap) == 0 && realpath(raw, buf) != NULL) {
        n = strlen(buf);
    }
#else  /* Linux + other /proc systems */
    ssize_t r = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (r > 0) { buf[(size_t) r] = '\0'; n = (size_t) r; }
#endif
    if (n == 0) return vader_string_new(".", 1);
    vader_path_to_slash(buf, n);
    return vader_string_new(buf, n);
}

/* `vader_temp_dir` backs the `std/io::temp_dir` intrinsic — the OS scratch
 * directory for temporary files, `/`-separated and WITHOUT a trailing
 * separator (callers join with "/name"). Honours $TMPDIR (POSIX) / GetTempPath
 * (Windows, which itself reads %TMP% / %TEMP% / %USERPROFILE%), so a sandboxed
 * CI runner's redirected temp is respected ; falls back to "/tmp" when unset. */
vader_string_t vader_temp_dir(void) {
    char buf[4096];
    size_t n = 0;
#if defined(_WIN32)
    /* GetTempPathA writes the directory plus a trailing backslash. */
    DWORD len = GetTempPathA((DWORD) sizeof(buf), buf);
    if (len > 0 && len < sizeof(buf)) n = (size_t) len;
#else
    const char* env = getenv("TMPDIR");
    if (env != NULL && env[0] != '\0') {
        n = strlen(env);
        if (n >= sizeof(buf)) n = sizeof(buf) - 1;
        memcpy(buf, env, n);
    }
#endif
    if (n == 0) { memcpy(buf, "/tmp", 4); n = 4; }
    vader_path_to_slash(buf, n);
    /* Drop any trailing separator so `temp_dir() + "/name"` stays clean. */
    while (n > 1 && buf[n - 1] == '/') n--;
    return vader_string_new(buf, n);
}

/* ----------------------------------------------------------------- terminal / env
 *
 * `vader_is_tty` backs `std/tty::is_tty`. It reports whether `stream` (0 =
 * stdout, 1 = stderr) is an interactive terminal that will render ANSI escapes;
 * on Windows it also enables virtual-terminal processing on first probe (and
 * reports false on a console too old for it, so callers fall back to plain
 * text). The result is cached per stream for the process lifetime — Vader has
 * no module-scope run-once, so the memo lives here. `vader_get_env` backs
 * `std/env::get_env`: it boxes the variable's value as a string (str_tag) or
 * returns a null box when the variable is unset.
 */
#if defined(_WIN32)
#  ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#    define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#  endif
/* True iff the Windows console behind `f` is interactive AND virtual-terminal
 * processing can be enabled on it — only then do ANSI escapes render rather
 * than print literally. Idempotent: re-enabling VT on an already-VT console is
 * a no-op, and the per-stream cache means it runs at most once. */
static int vader_win_console_supports_ansi(FILE* f) {
    if (!_isatty(_fileno(f))) return 0;
    HANDLE h = (HANDLE) _get_osfhandle(_fileno(f));
    if (h == INVALID_HANDLE_VALUE) return 0;
    DWORD mode = 0;
    if (!GetConsoleMode(h, &mode)) return 0;
    return SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING) ? 1 : 0;
}
#endif

vader_bool_t vader_is_tty(int32_t stream) {
    /* Index by Stream tag: Stdout = 0, Stderr = 1. */
    static int cache[2] = { -1, -1 };
    int i = (stream == 1) ? 1 : 0;
    if (cache[i] < 0) {
#if defined(_WIN32)
        cache[i] = vader_win_console_supports_ansi(i == 1 ? stderr : stdout);
#else
        cache[i] = isatty(i == 1 ? STDERR_FILENO : STDOUT_FILENO) ? 1 : 0;
#endif
    }
    return cache[i] != 0;
}

vader_box_t vader_get_env(vader_string_t name, uint32_t str_tag) {
    const char* key = vader_string_to_cstr(name);
    const char* val = getenv(key);
    vader_box_t out = (val == NULL)
        ? vader_box_null()
        : vader_box_string(str_tag, vader_string_new(val, strlen(val)));
    vader_cstr_free(key);
    return out;
}

/* ----------------------------------------------------------------- process
 *
 * Non-blocking subprocess primitives backing `std/process::spawn_async` (and,
 * through `block_on`, the blocking `spawn`). A child is launched by
 * `vader_spawn_start` (records a handle into the child table, never waits),
 * advanced by `vader_spawn_poll` (drains its pipes + reaps WITHOUT blocking —
 * returns VADER_SPAWN_RUNNING while alive), and its captured output fetched by
 * `vader_spawn_take_stdout` / `_stderr` once done. Launching N children then
 * polling them concurrently is what the split build uses to compile in
 * parallel — the OS schedules the child processes across cores ; the caller's
 * single thread just orchestrates.
 *
 * Both branches capture stdout/stderr into per-child heap buffers. POSIX sets
 * the read ends non-blocking and drains on each poll ; Windows lets a
 * `win_drain_pipe` thread per pipe fill the buffers (the thread also solves the
 * saturated-pipe deadlock). On take, the buffer is interned via
 * `vader_string_new` (which copies) and the transit buffer freed. */

/* VADER_SPAWN_RUNNING / _LAUNCH_FAIL / _SIGNALED are defined in vader.h. */
#define VADER_MAX_CHILDREN  256

#if defined(_WIN32)
/* Drained by a worker thread — serial reads would deadlock if the child
 * saturates one pipe buffer (~4 KB) while we block on the other. */
typedef struct {
    HANDLE read_end;
    char*  buf;     /* malloc'd; moved into the child slot on reap */
    size_t len;
    int    failed;
} win_drain_ctx_t;
#endif

/* One tracked child. Shared fields hold the captured output ; the platform
 * fields hold the OS handles the poll needs. */
typedef struct {
    int      in_use;
    int      done;         /* poll has reaped it — exit_code is final */
    int32_t  exit_code;
    char*    out_buf; size_t out_len; size_t out_cap;
    char*    err_buf; size_t err_len; size_t err_cap;
#if defined(_WIN32)
    HANDLE   hProcess;
    HANDLE   out_th, err_th;
    win_drain_ctx_t out_ctx, err_ctx;
#else
    pid_t    pid;
    int      out_fd, err_fd;
    int      out_eof, err_eof;
#endif
} vader_child_t;

static vader_child_t g_children[VADER_MAX_CHILDREN];

/* Grab a free, zeroed child slot, or -1 when the table is full. */
static vader_i64_t vader_child_alloc(void) {
    for (int i = 0; i < VADER_MAX_CHILDREN; i++) {
        if (!g_children[i].in_use) {
            memset(&g_children[i], 0, sizeof(vader_child_t));
            g_children[i].in_use = 1;
            g_children[i].exit_code = VADER_SPAWN_RUNNING;
            return (vader_i64_t) i;
        }
    }
    return -1;
}

/* Resolve a caller handle to its slot, or NULL if out of range / freed. */
static vader_child_t* vader_child_at(vader_i64_t h) {
    if (h < 0 || h >= VADER_MAX_CHILDREN) return NULL;
    if (!g_children[(size_t) h].in_use) return NULL;
    return &g_children[(size_t) h];
}

#if defined(_WIN32)

static DWORD WINAPI win_drain_pipe(LPVOID arg) {
    win_drain_ctx_t* ctx = (win_drain_ctx_t*) arg;
    size_t cap = 4096, len = 0;
    char*  buf = (char*) malloc(cap);
    if (buf == NULL) { ctx->failed = 1; return 0; }
    for (;;) {
        if (len + 4096 > cap) {
            cap *= 2;
            char* grown = (char*) realloc(buf, cap);
            if (grown == NULL) { free(buf); ctx->failed = 1; return 0; }
            buf = grown;
        }
        DWORD n = 0;
        BOOL ok = ReadFile(ctx->read_end, buf + len, (DWORD)(cap - len), &n, NULL);
        if (!ok) {
            /* ERROR_BROKEN_PIPE = child closed its write end : normal EOF. */
            if (GetLastError() == ERROR_BROKEN_PIPE) break;
            free(buf); ctx->failed = 1; return 0;
        }
        if (n == 0) break;
        len += n;
    }
    ctx->buf = buf;
    ctx->len = len;
    return 0;
}

/* Quote a single argv element per the CommandLineToArgvW round-trip rules
 * (see Daniel Colascione's "Everyone quotes command line arguments the wrong
 * way" + MS docs). Writes to `dst` and returns the number of bytes written.
 * `dst` must have room for `2 + 2 * strlen(arg)` bytes worst case. */
static size_t win_argv_quote(char* dst, const char* arg) {
    size_t out = 0;
    int needs_quote = (arg[0] == '\0') || (strpbrk(arg, " \t\n\v\"") != NULL);
    if (!needs_quote) {
        size_t l = strlen(arg);
        memcpy(dst, arg, l);
        return l;
    }
    dst[out++] = '"';
    for (const char* p = arg; *p != '\0'; ) {
        size_t bs = 0;
        while (*p == '\\') { bs++; p++; }
        if (*p == '\0') {
            /* Trailing backslashes before the closing quote : double them so
             * the closing quote isn't escaped. */
            for (size_t i = 0; i < 2*bs; i++) dst[out++] = '\\';
            break;
        } else if (*p == '"') {
            /* Backslashes preceding a quote : each doubled, plus escape the quote. */
            for (size_t i = 0; i < 2*bs + 1; i++) dst[out++] = '\\';
            dst[out++] = '"';
            p++;
        } else {
            /* Mid-arg backslashes : literal. */
            for (size_t i = 0; i < bs; i++) dst[out++] = '\\';
            dst[out++] = *p;
            p++;
        }
    }
    dst[out++] = '"';
    return out;
}

vader_i64_t vader_spawn_start(vader_array_t* argv) {
    if (argv == NULL) return -1;
    argv = vader_array_resolve(argv);
    vader_array_resolve_buf(argv);
    size_t n = vader_array_len(argv);
    if (n == 0) return -1;

    /* argv is a `[string]` (KIND_BOXED) ; read its slots directly (no Vader
     * alloc in the loops, so the resolved buf stays valid). Build the command-
     * line string : upper bound per arg 2*len + 3 (quotes + escape + space). */
    const vader_box_t* slots = vader_array_box_slots(argv->buf);
    size_t cap = 1;  /* terminator */
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = slots[argv->offset + i];
        cap += vader_atom_len((vader_string_t) b.payload.s) * 2 + 3;
    }
    char* cmdline = (char*) malloc(cap);
    if (cmdline == NULL) return -1;
    size_t pos = 0;
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = slots[argv->offset + i];
        vader_string_t s = (vader_string_t) b.payload.s;
        size_t slen = vader_atom_len(s);
        char* z = (char*) malloc(slen + 1);
        if (z == NULL) { free(cmdline); return -1; }
        memcpy(z, vader_atom_data(s), slen); z[slen] = '\0';
        if (i > 0) cmdline[pos++] = ' ';
        pos += win_argv_quote(cmdline + pos, z);
        free(z);
    }
    cmdline[pos] = '\0';

    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    HANDLE out_read = NULL, out_write = NULL;
    HANDLE err_read = NULL, err_write = NULL;
    if (!CreatePipe(&out_read, &out_write, &sa, 0)) { free(cmdline); return -1; }
    if (!CreatePipe(&err_read, &err_write, &sa, 0)) {
        CloseHandle(out_read); CloseHandle(out_write); free(cmdline); return -1;
    }
    /* Parent's read ends must NOT be inherited by the child. */
    SetHandleInformation(out_read, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(err_read, HANDLE_FLAG_INHERIT, 0);

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = out_write;
    si.hStdError  = err_write;
    si.hStdInput  = GetStdHandle(STD_INPUT_HANDLE);

    BOOL ok = CreateProcessA(
        NULL, cmdline, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi
    );
    free(cmdline);
    /* Parent closes the write ends — only the child holds them now. */
    CloseHandle(out_write);
    CloseHandle(err_write);
    if (!ok) { CloseHandle(out_read); CloseHandle(err_read); return -1; }

    vader_i64_t h = vader_child_alloc();
    if (h < 0) {
        /* Table full — can't track it ; kill + reap to avoid an orphan. */
        TerminateProcess(pi.hProcess, 1);
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(out_read); CloseHandle(err_read);
        CloseHandle(pi.hProcess); CloseHandle(pi.hThread);
        return -1;
    }
    vader_child_t* c = &g_children[(size_t) h];
    c->hProcess = pi.hProcess;
    CloseHandle(pi.hThread);
    /* Drain both pipes concurrently (a thread each) so a saturated pipe can't
     * stall a child between polls. The ctxs live in the stable table slot. */
    c->out_ctx.read_end = out_read;
    c->err_ctx.read_end = err_read;
    c->out_th = CreateThread(NULL, 0, win_drain_pipe, &c->out_ctx, 0, NULL);
    c->err_th = CreateThread(NULL, 0, win_drain_pipe, &c->err_ctx, 0, NULL);
    return h;
}

vader_i32_t vader_spawn_poll(vader_i64_t handle) {
    vader_child_t* c = vader_child_at(handle);
    if (c == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    if (c->done) return c->exit_code;
    if (WaitForSingleObject(c->hProcess, 0) == WAIT_TIMEOUT) return VADER_SPAWN_RUNNING;

    /* Exited — join the drain threads (they finish when the child's pipe ends
     * close), collect the buffers, and read the exit code. */
    if (c->out_th != NULL) { WaitForSingleObject(c->out_th, INFINITE); CloseHandle(c->out_th); c->out_th = NULL; }
    if (c->err_th != NULL) { WaitForSingleObject(c->err_th, INFINITE); CloseHandle(c->err_th); c->err_th = NULL; }
    CloseHandle(c->out_ctx.read_end);
    CloseHandle(c->err_ctx.read_end);
    c->out_buf = c->out_ctx.buf; c->out_len = c->out_ctx.len; c->out_ctx.buf = NULL;
    c->err_buf = c->err_ctx.buf; c->err_len = c->err_ctx.len; c->err_ctx.buf = NULL;

    DWORD exit_code = 0;
    GetExitCodeProcess(c->hProcess, &exit_code);
    CloseHandle(c->hProcess); c->hProcess = NULL;
    c->done = 1;
    /* NTSTATUS abnormal-termination codes (0xC0000000+) flag a crash ; the
     * normal exit-code range is 0..0x7FFFFFFF. Map crashes onto SIGNALED. */
    c->exit_code = ((exit_code & 0xC0000000u) == 0xC0000000u)
        ? VADER_SPAWN_SIGNALED : (int32_t) exit_code;
    return c->exit_code;
}

#else  /* POSIX */

/* Append everything readable right now from a non-blocking fd into *buf,
 * growing it as needed. Stops at EAGAIN (no data yet, writer still alive) or
 * EOF (sets *eof). A read error is treated as EOF (best-effort capture). */
static void drain_nonblock(int fd, char** buf, size_t* len, size_t* cap, int* eof) {
    if (*eof) return;
    for (;;) {
        if (*cap == 0) {
            *cap = 4096;
            *buf = (char*) malloc(*cap);
            if (*buf == NULL) { *eof = 1; *cap = 0; return; }
        }
        if (*len + 4096 > *cap) {
            size_t ncap = *cap * 2;
            char* grown = (char*) realloc(*buf, ncap);
            if (grown == NULL) { *eof = 1; return; }
            *buf = grown; *cap = ncap;
        }
        ssize_t n = read(fd, *buf + *len, *cap - *len);
        if (n > 0) { *len += (size_t) n; continue; }
        if (n == 0) { *eof = 1; return; }
        if (errno == EINTR) continue;
        if (errno == EAGAIN || errno == EWOULDBLOCK) return;
        *eof = 1; return;
    }
}

vader_i64_t vader_spawn_start(vader_array_t* argv) {
    if (argv == NULL) return -1;
    argv = vader_array_resolve(argv);
    vader_array_resolve_buf(argv);
    size_t n = vader_array_len(argv);
    if (n == 0) return -1;

    /* Build a NULL-terminated argv from the Vader [string] array — each slot
     * needs to be a 0-terminated C string. argv is KIND_BOXED ; read its slots
     * directly (no Vader alloc in the loop, so the resolved buf stays valid). */
    char** cargv = (char**) calloc(n + 1, sizeof(char*));
    if (cargv == NULL) return -1;
    const vader_box_t* slots = vader_array_box_slots(argv->buf);
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = slots[argv->offset + i];
        vader_string_t s = (vader_string_t) b.payload.s;
        size_t slen = vader_atom_len(s);
        char* z = (char*) malloc(slen + 1);
        if (z == NULL) {
            for (size_t j = 0; j < i; j++) free(cargv[j]);
            free(cargv);
            return -1;
        }
        memcpy(z, vader_atom_data(s), slen); z[slen] = '\0';
        cargv[i] = z;
    }

    int out_pipe[2] = {-1, -1};
    int err_pipe[2] = {-1, -1};
    /* Open the pipes independently — short-circuiting `||` would leak
     * `out_pipe`'s ends if `err_pipe` is the failing call. */
    if (pipe(out_pipe) != 0) goto fail_free_cargv;
    if (pipe(err_pipe) != 0) goto fail_close_out;

    posix_spawn_file_actions_t fa;
    /* `posix_spawn_file_actions_init` can fail (e.g. ENOMEM) — using an
     * uninitialised actions struct is undefined. */
    if (posix_spawn_file_actions_init(&fa) != 0) goto fail_close_both;
    posix_spawn_file_actions_addclose(&fa, out_pipe[0]);
    posix_spawn_file_actions_addclose(&fa, err_pipe[0]);
    posix_spawn_file_actions_adddup2 (&fa, out_pipe[1], STDOUT_FILENO);
    posix_spawn_file_actions_adddup2 (&fa, err_pipe[1], STDERR_FILENO);
    posix_spawn_file_actions_addclose(&fa, out_pipe[1]);
    posix_spawn_file_actions_addclose(&fa, err_pipe[1]);

    pid_t pid;
    int rc = posix_spawnp(&pid, cargv[0], &fa, NULL, cargv, environ);
    posix_spawn_file_actions_destroy(&fa);

    /* Parent closes write ends — the child has them. */
    close(out_pipe[1]);
    close(err_pipe[1]);

    for (size_t j = 0; j < n; j++) free(cargv[j]);
    free(cargv);

    if (rc != 0) { close(out_pipe[0]); close(err_pipe[0]); return -1; }

    /* Read ends non-blocking so `vader_spawn_poll` never stalls. */
    fcntl(out_pipe[0], F_SETFL, O_NONBLOCK);
    fcntl(err_pipe[0], F_SETFL, O_NONBLOCK);

    vader_i64_t h = vader_child_alloc();
    if (h < 0) {
        /* Table full — reap synchronously (the child gets SIGPIPE once it
         * writes to the closed pipe, or runs to completion) to avoid a zombie. */
        close(out_pipe[0]); close(err_pipe[0]);
        int st; while (waitpid(pid, &st, 0) < 0 && errno == EINTR) {}
        return -1;
    }
    vader_child_t* c = &g_children[(size_t) h];
    c->pid    = pid;
    c->out_fd = out_pipe[0];
    c->err_fd = err_pipe[0];
    return h;

fail_close_both:
    close(err_pipe[0]); close(err_pipe[1]);
fail_close_out:
    close(out_pipe[0]); close(out_pipe[1]);
fail_free_cargv:
    for (size_t j = 0; j < n; j++) free(cargv[j]);
    free(cargv);
    return -1;
}

vader_i32_t vader_spawn_poll(vader_i64_t handle) {
    vader_child_t* c = vader_child_at(handle);
    if (c == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    if (c->done) return c->exit_code;

    drain_nonblock(c->out_fd, &c->out_buf, &c->out_len, &c->out_cap, &c->out_eof);
    drain_nonblock(c->err_fd, &c->err_buf, &c->err_len, &c->err_cap, &c->err_eof);

    int status = 0;
    pid_t r = waitpid(c->pid, &status, WNOHANG);
    if (r == 0) return VADER_SPAWN_RUNNING;
    if (r < 0 && errno == EINTR) return VADER_SPAWN_RUNNING;

    /* Reaped (or waitpid error). The child is dead → its write ends are closed,
     * so a final drain reads the tail to EOF without blocking. */
    if (r > 0) {
        drain_nonblock(c->out_fd, &c->out_buf, &c->out_len, &c->out_cap, &c->out_eof);
        drain_nonblock(c->err_fd, &c->err_buf, &c->err_len, &c->err_cap, &c->err_eof);
    }
    close(c->out_fd); c->out_fd = -1;
    close(c->err_fd); c->err_fd = -1;
    c->done = 1;
    if (r > 0 && WIFEXITED(status))        c->exit_code = (int32_t) WEXITSTATUS(status);
    else if (r > 0 && WIFSIGNALED(status)) c->exit_code = VADER_SPAWN_SIGNALED;
    else                                   c->exit_code = VADER_SPAWN_LAUNCH_FAIL;
    return c->exit_code;
}

#endif  /* _WIN32 / POSIX */

/* Intern a captured pipe buffer into a Vader string (`vader_string_new` copies
 * into the atom table), then free the transit buffer and clear the slot fields. */
static vader_string_t take_buf(char** buf, size_t* len, size_t* cap) {
    char*  b = *buf;
    size_t n = *len;
    *buf = NULL; *len = 0; *cap = 0;
    vader_string_t s = vader_string_new(b != NULL ? b : "", n);
    if (b != NULL) free(b);
    return s;
}

/* Intern the child's captured stdout. Must be called after `vader_spawn_poll`
 * reports done ; an invalid / freed handle yields the empty string. Documented
 * take order: stdout THEN stderr. */
vader_string_t vader_spawn_take_stdout(vader_i64_t handle) {
    vader_child_t* c = vader_child_at(handle);
    if (c == NULL) return vader_string_new("", 0);
    return take_buf(&c->out_buf, &c->out_len, &c->out_cap);
}

/* Intern the child's captured stderr, release its buffer, and — as the LAST
 * take — free the child slot for reuse (dropping any un-taken stdout). */
vader_string_t vader_spawn_take_stderr(vader_i64_t handle) {
    vader_child_t* c = vader_child_at(handle);
    if (c == NULL) return vader_string_new("", 0);
    vader_string_t s = take_buf(&c->err_buf, &c->err_len, &c->err_cap);
    if (c->out_buf != NULL) { free(c->out_buf); c->out_buf = NULL; }
    c->in_use = 0;
    return s;
}

/* ----------------------------------------------------------------- traps */

void vader_unreachable(const char* where) {
    fprintf(stderr, "vader: reached unreachable at %s\n", where);
    abort();
}

/* ---------- VADER_GC_PROFILE — live-set breakdown by type ---------- */

typedef struct {
    uint32_t type_index;
    uint64_t count;
    uint64_t bytes;
} vader_gc_prof_entry_t;

static int vader_gc_prof_cmp(const void* a, const void* b) {
    uint64_t bb = ((const vader_gc_prof_entry_t*) b)->bytes;
    uint64_t ba = ((const vader_gc_prof_entry_t*) a)->bytes;
    if (bb > ba) return 1;
    if (bb < ba) return -1;
    return 0;
}

/* Per-object tally — shared by the young contiguous walk and the old region walk
 * (via vader_old_foreach_live), since the old gen is no longer one arena. */
typedef struct {
    vader_gc_prof_entry_t* tally;
    size_t  array_buf_bucket;
    size_t* arr_kind_bytes;
    size_t* arr_kind_count;
    size_t* arr_boxed_slots;
    /* T12 measure-first (VADER_GC_PROFILE): slots of BOXED bufs whose every live
     * slot is a ref-or-null (STRUCT/ARRAY/FN/INLINE_REF tag). Such a buf — incl a
     * union-of-refs like Expr[]/Stmt[] — could become a raw 8-B void*[] (tag
     * recovered from each object header via scan_raw); only a true Any[] mixing
     * boxed primitives must stay 24-B boxed. This is the realistic array win. */
    size_t* arr_ref_slots;
    /* Sum of ptr_count over live STRUCT objects — their boxed ref fields (24 B).
     * Upper bound on the struct-field win (includes union fields that stay boxed). */
    size_t* struct_ptr_slots;
    size_t* total;
} vader_gc_prof_ctx_t;

static void vader_gc_prof_tally(char* scan, uint32_t type_index, void* vctx) {
    vader_gc_prof_ctx_t* c = (vader_gc_prof_ctx_t*) vctx;
    size_t bytes = vader_gc_obj_size(scan, type_index);
    if (bytes == 0) return;
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* abuf = (vader_array_buf_t*) scan;
        uint8_t ek = abuf->element_kind;
        if (ek < 16u) { c->arr_kind_bytes[ek] += bytes; c->arr_kind_count[ek] += 1u; }
        if (ek == VADER_ARRAY_KIND_BOXED) {
            *c->arr_boxed_slots += abuf->capacity;
            /* Realistic array win : is every live slot a ref-or-null? element_tag
             * is unused for BOXED, so sample the [0,length) slot tags. */
            vader_box_t* slots = vader_array_box_slots(abuf);
            int all_refs = 1, seen = 0;
            for (size_t i = 0; i < abuf->length; i++) {
                uint32_t t = slots[i].tag;
                if (t == VADER_BOX_TAG_NULL) continue;
                seen = 1;
                vader_type_kind_t k = (t < vader_type_info_count)
                    ? vader_type_info_table[t].kind : VADER_TYPE_KIND_NONE;
                if (k != VADER_TYPE_KIND_STRUCT && k != VADER_TYPE_KIND_ARRAY &&
                    k != VADER_TYPE_KIND_FN && k != VADER_TYPE_KIND_INLINE_REF) {
                    all_refs = 0; break;
                }
            }
            if (seen && all_refs) *c->arr_ref_slots += abuf->capacity;
        }
    } else if (type_index < vader_type_info_count &&
               vader_type_info_table[type_index].kind == VADER_TYPE_KIND_STRUCT) {
        *c->struct_ptr_slots += vader_type_info_table[type_index].ptr_count;
    }
    size_t bucket = (type_index == VADER_TYPE_INDEX_ARRAY_BUF)
        ? c->array_buf_bucket
        : (type_index < vader_type_info_count ? type_index : 0);
    c->tally[bucket].count += 1u;
    c->tally[bucket].bytes += bytes;
    *c->total += bytes;
}

/* Walk both arenas' from-spaces and tally objects bucketed by type_index.
 * Sort by total bytes, print top-20. Called via atexit when
 * VADER_GC_PROFILE is set, and inline from the OOM trap (abort() skips
 * atexit). */
void vader_gc_profile_dump(void) {
    if (!g_gc_initialized) return;
    /* +1 for the ARRAY_BUF sentinel bucket. ARRAY_BUF objects (header tag
     * VADER_TYPE_INDEX_ARRAY_BUF) are tallied into this one extra bucket, just
     * past the real type indices [0, count) — see the bucketing + display below. */
    size_t nbuckets = vader_type_info_count + 1u;
    const size_t array_buf_bucket = vader_type_info_count;
    vader_gc_prof_entry_t* tally = (vader_gc_prof_entry_t*) calloc(nbuckets, sizeof(vader_gc_prof_entry_t));
    if (tally == NULL) return;
    for (size_t i = 0; i < nbuckets; i++) tally[i].type_index = (uint32_t) i;

    /* ARRAY_BUF element-kind breakdown : sizing the win of an 8 B ref array
     * kind vs today's 24 B BOXED slots. `boxed_slots` × (24-8) is the upper
     * bound on what de-erasing pure-ref / pure-ref-union arrays could reclaim
     * (an over-count : BOXED also covers genuine `Any[]`, which can't shrink). */
    size_t arr_kind_bytes[16] = { 0 };
    size_t arr_kind_count[16] = { 0 };
    size_t arr_boxed_slots = 0;
    size_t arr_ref_slots = 0;      /* T12 : BOXED bufs that are all-refs (→ raw void*[]) */
    size_t struct_ptr_slots = 0;   /* T12 : boxed ref fields across live structs */

    /* Young: one contiguous from-space walk. Old: the non-moving slab's live
     * slots, by region. The BUFFER sentinel has no dedicated bucket — it falls
     * into bucket 0 (a cosmetic miscount in this debug-only profile, never a
     * GC-correctness issue ; the size walk handles its bytes correctly). */
    size_t totals[2] = { 0, 0 };
    vader_gc_prof_ctx_t cy = { tally, array_buf_bucket, arr_kind_bytes, arr_kind_count, &arr_boxed_slots, &arr_ref_slots, &struct_ptr_slots, &totals[0] };
    char* scan = g_young.from.base;
    while (scan < g_young.from.cur) {
        vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
        size_t bytes = vader_gc_obj_size(scan, hdr->type_index);
        if (bytes == 0) break;
        vader_gc_prof_tally(scan, hdr->type_index, &cy);
        scan += vader_gc_align(bytes);
    }
    vader_gc_prof_ctx_t co = { tally, array_buf_bucket, arr_kind_bytes, arr_kind_count, &arr_boxed_slots, &arr_ref_slots, &struct_ptr_slots, &totals[1] };
    vader_old_foreach_live(vader_gc_prof_tally, &co);
    qsort(tally, nbuckets, sizeof(vader_gc_prof_entry_t), vader_gc_prof_cmp);

    fprintf(stderr, "\n=== vader_gc_profile : live-set breakdown ===\n");
    fprintf(stderr, "young from-space : %.2f MB live (of %zu MB arena)\n",
            (double) totals[0] / (1024.0 * 1024.0),
            g_young.half_bytes / (1024u * 1024u));
    fprintf(stderr, "old   slab       : %.2f MB live (bump %.2f MB / reservation %.0f MB)\n",
            (double) totals[1] / (1024.0 * 1024.0),
            (double) (size_t)(g_old_bump - g_old_block) / (1024.0 * 1024.0),
            g_old_capacity / (1024.0 * 1024.0));
    fprintf(stderr, "top-20 buckets (by bytes) :\n");
    fprintf(stderr, "  %-12s %-10s %-12s %-12s %s\n",
            "type_index", "kind", "obj_size", "count", "total_bytes");
    size_t shown = 0;
    for (size_t i = 0; i < nbuckets && shown < 20u; i++) {
        if (tally[i].bytes == 0) break;
        uint32_t ti = tally[i].type_index;
        const char* kind_name = "?";
        size_t obj_size = 0;
        /* After bucketing, every ARRAY_BUF object sits in `array_buf_bucket` ;
         * the raw VADER_TYPE_INDEX_ARRAY_BUF header tag never reaches here. */
        if (ti == array_buf_bucket) {
            kind_name = "ARRAY_BUF";
        } else if (ti < vader_type_info_count) {
            const vader_type_info_t* info = &vader_type_info_table[ti];
            switch (info->kind) {
                case VADER_TYPE_KIND_NONE:       kind_name = "NONE"; break;
                case VADER_TYPE_KIND_STRUCT:     kind_name = "STRUCT"; break;
                case VADER_TYPE_KIND_ARRAY:      kind_name = "ARRAY"; break;
                case VADER_TYPE_KIND_FN:         kind_name = "FN"; break;
                case VADER_TYPE_KIND_INLINE_REF: kind_name = "INLINE_REF"; break;
            }
            obj_size = info->size;
        }
        fprintf(stderr, "  %-12u %-10s %-12zu %-12llu %llu\n",
                ti, kind_name, obj_size,
                (unsigned long long) tally[i].count,
                (unsigned long long) tally[i].bytes);
        shown++;
    }
    free(tally);

    /* ARRAY_BUF element-kind breakdown + Ref-kind ceiling. `kind_names` mirrors
     * the `vader_array_kind_t` enum (currently 0..12) — keep it in sync and grow
     * the array when a new kind lands (e.g. a future REF=13). */
    static const char* kind_names[13] = {
        "BOXED", "U8", "U16", "U32", "U64", "I8", "I16", "I32", "I64",
        "F32", "F64", "CHAR", "BOOL",
    };
    fprintf(stderr, "ARRAY_BUF by element_kind :\n");
    for (int k = 0; k < 16; k++) {
        if (arr_kind_count[k] == 0u) continue;
        fprintf(stderr, "  kind %-6s : %8.2f MB  (%llu bufs)\n",
                (k < 13 ? kind_names[k] : "?"),
                (double) arr_kind_bytes[k] / (1024.0 * 1024.0),
                (unsigned long long) arr_kind_count[k]);
    }
    fprintf(stderr,
        "  BOXED slots = %llu  →  max Ref-kind saving (24→8 B/slot) = %.2f MB "
        "(upper bound — includes un-shrinkable Any[])\n",
        (unsigned long long) arr_boxed_slots,
        (double) (arr_boxed_slots * 16u) / (1024.0 * 1024.0));

    /* T12 measure-first — realistic reclaimable (24→8 B/slot, saving 16 B each).
     * Array: only the all-refs bufs (a raw void*[] recovers each tag from the
     * object header; a true Any[] mixing boxed primitives is excluded). Struct:
     * boxed ref fields across live structs (upper bound — includes union fields
     * that must stay boxed). Both target the live-set → GC → compile-time lever
     * and the arr/str runtime gap vs Go. */
    double arr_real_mb    = (double) (arr_ref_slots    * 16u) / (1024.0 * 1024.0);
    double struct_real_mb = (double) (struct_ptr_slots * 16u) / (1024.0 * 1024.0);
    fprintf(stderr, "T12 reclaimable (realistic, 16 B/slot) :\n");
    fprintf(stderr, "  array all-ref slots = %llu  →  %.2f MB (Any[] excluded)\n",
            (unsigned long long) arr_ref_slots, arr_real_mb);
    fprintf(stderr, "  struct ref-fields   = %llu  →  %.2f MB (upper bound, incl union fields)\n",
            (unsigned long long) struct_ptr_slots, struct_real_mb);
    fprintf(stderr, "  combined            →  %.2f MB\n", arr_real_mb + struct_real_mb);
}

#ifdef VADER_PROFILE_ALLOC_SITES
typedef struct { int64_t off; uint64_t cnt; } vader_asite_row_t;
static int vader_asite_cmp(const void* a, const void* b) {
    uint64_t ca = ((const vader_asite_row_t*) a)->cnt, cb = ((const vader_asite_row_t*) b)->cnt;
    return (ca < cb) - (ca > cb);
}
static void vader_asite_dump_one(int depth, const char* label) {
    const int64_t* offs = g_asite_off[depth];
    const uint64_t* cnts = g_asite_cnt[depth];
    size_t n = 0; uint64_t total = 0;
    for (uint32_t i = 0; i < VADER_ASITE_SLOTS; i++) { if (cnts[i]) { n++; total += cnts[i]; } }
    if (n == 0) return;
    vader_asite_row_t* rows = (vader_asite_row_t*) malloc(n * sizeof(vader_asite_row_t));
    if (rows == NULL) return;
    size_t j = 0;
    for (uint32_t i = 0; i < VADER_ASITE_SLOTS; i++) { if (cnts[i]) { rows[j].off = offs[i]; rows[j].cnt = cnts[i]; j++; } }
    qsort(rows, n, sizeof(vader_asite_row_t), vader_asite_cmp);
    fprintf(stderr, "\n=== VADER_ALLOC_SITES (%s) : total=%llu across %zu sites ===\n",
            label, (unsigned long long) total, n);
    size_t top = n < 40u ? n : 40u;
    for (size_t i = 0; i < top; i++)
        fprintf(stderr, "  %14lld %14llu  %5.1f%%\n", (long long) rows[i].off,
                (unsigned long long) rows[i].cnt, 100.0 * (double) rows[i].cnt / (double) total);
    free(rows);
}
void vader_asite_dump(void) {
    if (!vader_asite_on()) return;
    static int dumped = 0;
    if (dumped) return;
    dumped = 1;
    vader_asite_dump_one(0, "depth0");
    vader_asite_dump_one(1, "depth1");
    vader_asite_dump_one(2, "depth2");
}
#endif /* VADER_PROFILE_ALLOC_SITES */

/* Drain every pending defer LIFO as a panic unwinds the live call chain.
 * The generated code balances push/pop on every structured exit, so the
 * stack only ever holds the frames between main and the trap site. */
static void vader_run_pending_defers(void) {
    while (g_defer_len > 0u) vader_run_one_defer();
}

void vader_trap(const char* msg) {
    fprintf(stderr, "vader: trap — %s\n", msg);
    if (!g_unwinding) { g_unwinding = 1; vader_run_pending_defers(); }
    abort();
}

void vader_panic(vader_string_t msg) {
    fprintf(stderr, "vader: panic — %.*s\n", (int) vader_atom_len(msg), vader_atom_data(msg));
    if (!g_unwinding) { g_unwinding = 1; vader_run_pending_defers(); }
    abort();
}
