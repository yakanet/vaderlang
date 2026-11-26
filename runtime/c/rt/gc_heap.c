/* rt/gc_heap.c: where objects live: the young semi-spaces, the old slab,
 * allocation and sizing.
 *
 * Allocation bumps the young from-space; its slow path collects or grows young:
 * an allocation never lands in old directly. The `VADER_GC_*` sizes are read at
 * `vader_gc_init`. */

#include "internal.h"

/* The old generation is a non-moving mark-sweep slab, NOT a copying semi-space
 * pair. It is a single big address-space reservation (`vader_os_reserve`,
 * lazily committed: untouched pages cost ~0 RSS) carved into class-homogeneous
 * regions by a global bump.
 * Objects never move, so:
 *   - membership is one range check over [g_old_block, g_old_bump);
 *   - there is no 2x to-space and no survivor-copy major pause;
 *   - the card table covers the fixed reservation once: no grow-time reslice.
 *
 * Small objects (<= VADER_OLD_SMALL_MAX) use 16 B size classes. A region of one
 * class (bump-carved) keeps its free slots in a list threaded through the word
 * after a freed slot's header, and belongs to at most one worker, which
 * allocates in it without a lock; the regions with room no worker owns wait in
 * the pool of their class (docs/adr/0166). Large objects get a one-object region
 * each, whose pages go back on free and kept for reuse in bins by size
 * (`vader_old_large_bin`). Reclamation is mark (toggle `g_mark_value`, trace
 * from roots + young survivors via a gray worklist) + sweep (rebuild the free
 * lists from unmarked slots, fill the pools). See `vader_major_collect`. */

#define VADER_OLD_CLASS_GRAN   16u
#define VADER_OLD_SMALL_MAX_LOG2 10u
#define VADER_OLD_SMALL_MAX    (1u << VADER_OLD_SMALL_MAX_LOG2)               /* 1024 */
#define VADER_OLD_REGION_BYTES (256u * 1024u)   /* small-class region granularity */
#define VADER_OLD_COMMIT_STEP  (4u * 1024u * 1024u)  /* how much of the reservation one commit takes */
#define VADER_OLD_REGION_TABLE_STEP 4096u             /* how many entries of the region table one commit takes */
#define VADER_OLD_DISCARD_MIN  (64u * 1024u)    /* only discard freed large regions >= this */
/* Freed large regions are binned by size, VADER_OLD_LARGE_SUBBINS bins per power
 * of two above VADER_OLD_SMALL_MAX, up to the widest `size_t`. */
#define VADER_OLD_LARGE_SUB_LOG2 3u
#define VADER_OLD_LARGE_SUBBINS  (1u << VADER_OLD_LARGE_SUB_LOG2)
#define VADER_OLD_LARGE_BINS     ((64u - VADER_OLD_SMALL_MAX_LOG2) * VADER_OLD_LARGE_SUBBINS)
#define VADER_OLD_LARGE_SCAN     32u   /* regions a large allocation inspects in its own bin */
_Static_assert(VADER_OLD_NUM_CLASSES == VADER_OLD_SMALL_MAX / VADER_OLD_CLASS_GRAN,
               "one class per step of the granularity up to the largest small object");
_Static_assert(VADER_OLD_CLASS_GRAN >= VADER_OBJ_MIN_BYTES,
               "a free slot holds its header and the link of its free list");
_Static_assert(VADER_OLD_CLASS_GRAN % VADER_ARRAY_SLOT_ALIGN == 0,
               "a promoted array buffer keeps its slots on the slot alignment");



static char*  g_old_block     = NULL;   /* reservation base */
static char*  g_old_bump      = NULL;   /* global region-carve cursor (never retreats) */
static char*  g_old_committed = NULL;   /* end of the committed prefix, >= g_old_bump */
static char*  g_old_block_end = NULL;   /* g_old_block + reservation capacity */
static size_t g_old_capacity  = 0;      /* reservation size in bytes (== the cap) */
static size_t g_old_live_bytes = 0;     /* slot bytes held by live old objects (accumulates the workers' reports; recomputed exact at sweep) */
static size_t g_old_live_after_major = 0;  /* g_old_live_bytes right after the last sweep: the reclamation-trigger baseline */
static int    g_old_alloc_failed_at_cap = 0;  /* set when a carve hit the cap with no region to reuse */

/* By class, the regions with room that no worker allocates in, linked by
 * `free_next`: a sweep fills them, a worker takes one under the lock. */
static vader_old_region_t* g_old_pools[VADER_OLD_NUM_CLASSES];
/* Every region, by increasing base: each carve takes the next extent of the
 * bump, so the regions partition [g_old_block, g_old_bump) in this order. The
 * table is reserved at init for as many regions as the smallest ones would
 * make, and never moves. Only the carve appends, under the lock, and it
 * publishes a region by the count, released: a minor of another worker reads
 * the table without the lock. */
static vader_old_region_t* g_old_region_table     = NULL;
static size_t              g_old_region_count     = 0;
static size_t              g_old_region_limit     = 0;   /* entries reserved */
static size_t              g_old_region_committed = 0;   /* entries committed */
/* Freed large regions by size bin: every region of a bin is at least as large as
 * every region of a lower one. Rebuilt by each sweep (`vader_old_sweep`), which
 * also records the highest bin it filled: no bin above it holds a region. */
static vader_old_region_t* g_old_large_bins[VADER_OLD_LARGE_BINS];
static size_t              g_old_large_top_bin = 0;

/* The bin of a large region of `size` bytes (more than VADER_OLD_SMALL_MAX): its
 * power of two, then the VADER_OLD_LARGE_SUB_LOG2 bits below the leading one. */
static size_t vader_old_large_bin(size_t size) {
    int lg = 63 - __builtin_clzll((unsigned long long) size);
    size_t sub = (size >> (lg - (int) VADER_OLD_LARGE_SUB_LOG2)) & (VADER_OLD_LARGE_SUBBINS - 1u);
    return (size_t) (lg - (int) VADER_OLD_SMALL_MAX_LOG2) * VADER_OLD_LARGE_SUBBINS + sub;
}

/* A freed large region that can hold `aligned` bytes, as the link that points at
 * it, or NULL. First fit among at most VADER_OLD_LARGE_SCAN regions of the
 * request's own bin, else the head of the first non-empty higher bin, which fits
 * by construction. The search must stay bounded: the bins hold every dead large
 * region, and nothing but a reuse takes one out. */
static vader_old_region_t** vader_old_large_fit(size_t aligned) {
    size_t bin = vader_old_large_bin(aligned);
    vader_old_region_t** pp = &g_old_large_bins[bin];
    for (unsigned scanned = 0u; *pp != NULL && scanned < VADER_OLD_LARGE_SCAN; scanned++) {
        if ((*pp)->slot_size >= aligned) return pp;
        pp = &(*pp)->free_next;
    }
    for (size_t higher = bin + 1u; higher <= g_old_large_top_bin; higher++) {
        if (g_old_large_bins[higher] != NULL) return &g_old_large_bins[higher];
    }
    return NULL;
}

static int           g_gc_initialized = 0;

/* Every worker whose heap the collector knows, the main thread's first. */
static vader_worker_t* g_workers[VADER_WORKERS_MAX];
static size_t          g_worker_count = 0;

/* The size of a young semi-space (`VADER_GC_YOUNG_BYTES`). Set once in
 * `vader_gc_init`. */
static size_t        g_young_bytes = 0;

/* Hard caps: the size of the old reservation and of one young semi-space.
 * Env-tunable (VADER_GC_OLD_MAX / VADER_GC_YOUNG_MAX) so a too-large live set
 * traps at a deliberate ceiling instead of exhausting RAM. Set once in
 * `vader_gc_init`, where the old default is derived from physical RAM. */
static size_t        g_old_max_bytes = 0;
static size_t        g_young_max_bytes = 0;

/* Set by `vader_gc_count_allocations`, never cleared. */
static int g_count_allocations = 0;

/* Set `w->alloc_limit`: NULL before init, under the stress modes, once
 * allocations are counted, which act on or count every allocation, while the
 * worker allocates in old under the monitor, and while a major waits for the
 * workers to stop at the slow path. Refreshed
 * whenever `w->young.from` moves and when counting turns on; the stress flags
 * are set before the first carve. */
static void vader_alloc_limit_refresh(vader_worker_t* w) {
    char* limit = w->young.from.end;
    if (g_gc_stress || g_gc_stress_major || g_count_allocations || w->in_monitor) limit = NULL;
    atomic_store(&w->alloc_limit, limit);
    /* After the store: a major that asked before it sets the limit to NULL
     * after it, or is seen here. */
    if (atomic_load(&g_gc_stop_requested)) atomic_store(&w->alloc_limit, NULL);
}

/* The bound of the inline bump, as its owner reads it. */
static inline char* vader_alloc_limit_of(vader_worker_t* w) {
    return atomic_load_explicit(&w->alloc_limit, memory_order_relaxed);
}

/* `vader_alloc_limit_refresh` on every worker. */
static void vader_alloc_limit_refresh_all(void) {
    for (size_t i = 0; i < g_worker_count; i++) vader_alloc_limit_refresh(g_workers[i]);
}

void vader_gc_count_allocations(void) {
    g_count_allocations = 1;
    vader_alloc_limit_refresh_all();
}

static size_t vader_gc_align(size_t n) {
    return (n + (VADER_GC_ALIGN - 1u)) & ~(size_t)(VADER_GC_ALIGN - 1u);
}

static int vader_in_young_from(const vader_worker_t* w, const void* p) {
    return (const char*)p >= w->young.from.base && (const char*)p < w->young.from.end;
}

/* Membership in either half of the young generation : `to` is where a minor
 * forwards a referent it does not promote, and a major leaves young referents
 * in `from`. An immortal (`.rodata`) or off-heap pointer is in neither. */
static int vader_in_young(const vader_worker_t* w, const void* p) {
    return ((const char*)p >= w->young.to.base && (const char*)p < w->young.to.end)
        || vader_in_young_from(w, p);
}

/* Membership in the non-moving old gen: a pointer is an old object iff it falls
 * in the carved span [g_old_block, g_old_bump). Pointers in [g_old_bump,
 * g_old_block_end) address uncommitted reservation tail (never a live object)
 * so they're correctly excluded (a stray ref there is treated as immortal, not
 * marked/written). Old objects never move, so there is no from/to distinction:
 * one predicate covers both the minor (old is stable) and the major (old is
 * sweepable). */
static int vader_in_old(const void* p) {
    return (const char*)p >= g_old_block && (const char*)p < g_old_bump;
}

/* Stop the program over a GC setting it cannot read whole: a heap sized from
 * half a value would differ from what the user asked, with nothing to say so. */
static VADER_NORETURN void vader_gc_env_refuse(const char* env_name, const char* raw,
                                               const char* expected) {
    char msg[512];
    snprintf(msg, sizeof msg, "%s=%s: expected %s", env_name, raw, expected);
    vader_trap(msg);
}

/* Read the decimal digits at the front of `raw` into `*out`. Returns the byte
 * after them, or NULL when `raw` does not start with a digit or the count
 * overflows: unlike a bare `strtoull`, no sign and no leading space. */
static const char* vader_gc_read_digits(const char* raw, unsigned long long* out) {
    if (!isdigit((unsigned char) raw[0])) return NULL;
    errno = 0;
    char* end = NULL;
    *out = strtoull(raw, &end, 10);
    if (errno == ERANGE) return NULL;
    return end;
}

/* The power of two a size suffix stands for: 0 for none, 10 for `k`, 20 for
 * `m`, 30 for `g`, either case; -1 for anything else. */
static int vader_gc_size_shift(const char* suffix) {
    if (suffix[0] == '\0') return 0;
    if (suffix[1] != '\0') return -1;
    switch (suffix[0]) {
        case 'k': case 'K': return 10;
        case 'm': case 'M': return 20;
        case 'g': case 'G': return 30;
        default:            return -1;
    }
}

/* Read the byte size in `env_name`: digits, optionally followed by `k`, `m` or
 * `g` for KiB, MiB, GiB. `fallback` when unset or empty; a trap for anything
 * else that is not a positive size. */
static size_t vader_gc_env_bytes(const char* env_name, size_t fallback) {
    const char* raw = getenv(env_name);
    if (raw == NULL || raw[0] == '\0') return fallback;
    unsigned long long count = 0;
    const char* suffix = vader_gc_read_digits(raw, &count);
    int shift = -1;
    if (suffix != NULL) shift = vader_gc_size_shift(suffix);
    if (shift < 0 || count == 0 || count > (SIZE_MAX >> shift)) {
        vader_gc_env_refuse(env_name, raw,
            "a positive byte size: digits, optionally followed by k, m or g");
    }
    return (size_t) count << shift;
}

/* Read the whole number in `env_name`, from `min` to `max`. `fallback` when
 * unset or empty; a trap naming `expected` for anything else. */
static size_t vader_gc_env_count(const char* env_name, size_t fallback, size_t min, size_t max,
                                 const char* expected) {
    const char* raw = getenv(env_name);
    if (raw == NULL || raw[0] == '\0') return fallback;
    unsigned long long count = 0;
    const char* end = vader_gc_read_digits(raw, &count);
    if (end == NULL || *end != '\0' || count < min || count > max) {
        vader_gc_env_refuse(env_name, raw, expected);
    }
    return (size_t) count;
}

/* Read the percentage in `env_name`, above 0 and at most 100. `fallback` when
 * unset or empty; a trap for anything else. */
static double vader_gc_env_percent(const char* env_name, double fallback) {
    const char* raw = getenv(env_name);
    if (raw == NULL || raw[0] == '\0') return fallback;
    char* end = NULL;
    double v = strtod(raw, &end);
    if (end == raw || *end != '\0' || !(v > 0.0 && v <= 100.0)) {
        vader_gc_env_refuse(env_name, raw, "a percentage above 0 and at most 100");
    }
    return v;
}

/* Read a boolean toggle from `env_name`: true when set to a non-empty value
 * other than "0". Used for the GC debug knobs (stress / box-check / scan-all). */
static int vader_gc_env_bool(const char* env_name) {
    const char* raw = getenv(env_name);
    return raw != NULL && raw[0] != '\0' && raw[0] != '0';
}

/* ---- slab old-gen: reservation, allocation, sweep ------------------------ */

/* Commit the reservation up to `needed` at least, a whole step at a time: a large
 * object takes a region of its own, and one system call per region is thousands
 * of them in a compile. */
static void vader_old_commit_to(char* needed) {
    if (needed <= g_old_committed) return;
    size_t steps = ((size_t)(needed - g_old_block) + VADER_OLD_COMMIT_STEP - 1u) / VADER_OLD_COMMIT_STEP;
    char* end = g_old_block + steps * VADER_OLD_COMMIT_STEP;
    if (end > g_old_block_end) end = g_old_block_end;
    if (!vader_os_commit(g_old_committed, (size_t)(end - g_old_committed))) {
        vader_trap("vader_old_commit_to: could not commit the old generation (out of commit charge)");
    }
    g_old_committed = end;
}

/* Commit the region table up to `entries` at least, a whole step at a time. */
static void vader_old_region_table_commit(size_t entries) {
    if (entries <= g_old_region_committed) return;
    size_t steps = (entries + VADER_OLD_REGION_TABLE_STEP - 1u) / VADER_OLD_REGION_TABLE_STEP;
    size_t upto = steps * VADER_OLD_REGION_TABLE_STEP;
    if (upto > g_old_region_limit) upto = g_old_region_limit;
    char* from = (char*) (g_old_region_table + g_old_region_committed);
    if (!vader_os_commit(from, (upto - g_old_region_committed) * sizeof(vader_old_region_t))) {
        vader_trap("vader_old_carve_region: could not commit the region table (out of commit charge)");
    }
    g_old_region_committed = upto;
}

/* Carve a fresh region of `region_bytes` from the global bump and dedicate it to
 * `slot_size` (class_idx >= 0 for small, -1 for a one-object large region).
 * Returns NULL when the reservation is exhausted (the real OOM ceiling). */
static vader_old_region_t* vader_old_carve_region(size_t region_bytes, size_t slot_size, int class_idx) {
    if (g_old_bump + region_bytes > g_old_block_end) return NULL;
    size_t n = g_old_region_count;
    vader_old_region_table_commit(n + 1u);
    vader_old_region_t* r = &g_old_region_table[n];
    vader_old_commit_to(g_old_bump + region_bytes);
    r->base      = g_old_bump;
    r->cur       = g_old_bump;
    r->end       = g_old_bump + region_bytes;
    r->slot_size = slot_size;
    r->class_idx = class_idx;
    r->freed     = 0u;
    r->free_head = NULL;
    r->free_next = NULL;
    /* A large region holds its one object from the start. */
    if (class_idx < 0) r->cur = r->end;
    /* The bump first, then the count, released: a minor of another worker
     * reads the table without the lock (`vader_gc_scan_old_dirty_cards`), and
     * finds every region it counts whole and under the bump. */
    __atomic_store_n(&g_old_bump, g_old_bump + region_bytes, __ATOMIC_RELAXED);
    __atomic_store_n(&g_old_region_count, n + 1u, __ATOMIC_RELEASE);
    return r;
}

/* Serialises what the workers share of old: the carve, the pools of the
 * classes, the large bins. NULL with one worker. */
static vader_os_lock_t* g_old_guard = NULL;

static void vader_old_pool_start(void) {
    g_old_guard = vader_os_lock_new();
}

static void vader_old_lock(void) {
    if (g_old_guard != NULL) vader_os_lock(g_old_guard);
}

static void vader_old_unlock(void) {
    if (g_old_guard != NULL) vader_os_unlock(g_old_guard);
}

static size_t vader_old_live(void) {
    return __atomic_load_n(&g_old_live_bytes, __ATOMIC_RELAXED);
}

static void vader_old_report(vader_worker_t* w) {
    if (w->old_allocated == 0u) return;
    __atomic_fetch_add(&g_old_live_bytes, w->old_allocated, __ATOMIC_RELAXED);
    w->old_allocated = 0u;
}

/* Whether the small region `r` can take one more object. */
static int vader_old_region_has_room(const vader_old_region_t* r) {
    return r->free_head != NULL || r->cur + r->slot_size <= r->end;
}

/* A slot of the small region `r`: a free one, else the next never used; NULL
 * when it is full. The bump stays an atomic store: a minor of another worker
 * reads `r->cur` without the lock. */
static char* vader_old_region_take(vader_old_region_t* r) {
    if (!vader_old_region_has_room(r)) return NULL;
    char* slot = r->free_head;
    if (slot != NULL) {
        r->free_head = (char*) vader_obj_link(slot);
        return slot;
    }
    slot = r->cur;
    __atomic_store_n(&r->cur, slot + r->slot_size, __ATOMIC_RELAXED);
    return slot;
}

/* A region of class `ci` with room, for a worker to own: one of the pool of
 * the class, else a fresh one. NULL at the cap. Under the lock. */
static vader_old_region_t* vader_old_region_for(size_t ci) {
    vader_old_region_t* r = g_old_pools[ci];
    if (r != NULL) {
        g_old_pools[ci] = r->free_next;
        r->free_next = NULL;
        return r;
    }
    r = vader_old_carve_region(VADER_OLD_REGION_BYTES, (ci + 1u) * VADER_OLD_CLASS_GRAN, (int) ci);
    if (r == NULL) g_old_alloc_failed_at_cap = 1;
    return r;
}

/* A large region of `aligned` bytes: a freed one that fits, else a fresh one.
 * Its size stays a multiple of the class granularity, so every region, and
 * every slot in it, starts on the slot alignment an array buffer needs. NULL at
 * the cap. Under the lock. */
static vader_old_region_t* vader_old_large_for(size_t aligned) {
    vader_old_region_t** fit = vader_old_large_fit(aligned);
    if (fit != NULL) {
        vader_old_region_t* r = *fit;
        *fit = r->free_next;
        r->free_next = NULL;
        r->freed = 0u;
        return r;   /* pages re-fault on the caller's memcpy */
    }
    vader_old_region_t* r = vader_old_carve_region(aligned, aligned, -1);
    if (r == NULL) g_old_alloc_failed_at_cap = 1;
    return r;
}

/* Allocate `bytes` of old-gen storage for `w`. Returns raw, uninitialised slot
 * memory (caller writes the object + header) or NULL when the reservation is
 * exhausted at the cap (caller keeps the object in young). A small object goes
 * to the region `w` owns for its class, without the lock; only taking a new
 * region, or a large object, takes it. */
static void* vader_old_alloc(vader_worker_t* w, size_t bytes) {
    size_t aligned = vader_gc_align(bytes);
    if (aligned <= VADER_OLD_SMALL_MAX) {
        size_t ci = (aligned - 1u) / VADER_OLD_CLASS_GRAN;     /* 0..NUM_CLASSES-1 */
        vader_old_region_t* r = w->old_current[ci];
        char* slot = NULL;
        if (r != NULL) slot = vader_old_region_take(r);
        if (slot == NULL) {
            vader_old_lock();
            r = vader_old_region_for(ci);
            vader_old_unlock();
            if (r == NULL) return NULL;
            w->old_current[ci] = r;
            vader_old_report(w);
            slot = vader_old_region_take(r);
        }
        w->old_allocated += r->slot_size;
        return slot;
    }
    aligned = (aligned + VADER_OLD_CLASS_GRAN - 1u) & ~(size_t) (VADER_OLD_CLASS_GRAN - 1u);
    vader_old_lock();
    vader_old_region_t* r = vader_old_large_for(aligned);
    vader_old_unlock();
    if (r == NULL) return NULL;
    w->old_allocated += r->slot_size;
    vader_old_report(w);
    return r->base;
}

/* Walk every LIVE old object (mark == g_mark_value) and invoke `fn`. Used by the
 * atom-GC heap walk, the histogram, and the profiler: every consumer that needs
 * to enumerate the old live set, which spans several regions. */
static void vader_old_foreach_live(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx) {
    for (size_t i = g_old_region_count; i-- > 0;) {
        const vader_old_region_t* r = &g_old_region_table[i];
        for (char* slot = r->base; slot < r->cur; slot += r->slot_size) {
            vader_obj_header_t* h = (vader_obj_header_t*) slot;
            if (h->mark == g_mark_value) fn(slot, h->type_index, ctx);
        }
    }
}

/* Invoke `fn` on every object of the young from-space of every worker, one
 * contiguous run each, stepping over the fillers. */
static void vader_young_foreach(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx) {
    for (size_t i = 0; i < g_worker_count; i++) {
        const vader_arena_t* from = &g_workers[i]->young.from;
        char* scan = from->base;
        while (scan < from->cur) {
            vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
            if (hdr->type_index == VADER_TYPE_INDEX_FILLER) {
                scan += VADER_GC_ALIGN;
                continue;
            }
            size_t bytes = vader_gc_obj_size(scan, hdr->type_index);
            if (bytes == 0) break;
            fn(scan, hdr->type_index, ctx);
            scan += vader_gc_align(bytes);
        }
    }
}

/* Sweep: rebuild every free list from the unmarked slots. A slot survives iff
 * `mark == g_mark_value` (set during the mark phase). Dead small slots are
 * stamped FREE (mark 0) and pushed to the free list of their region, and a
 * region with room joins the pool of its class: the workers own no region
 * after a sweep. Dead large regions give their pages back and are queued in
 * their size bin for reuse. Recomputes g_old_live_bytes. Runs with the world
 * stopped. */
static void vader_old_sweep(void) {
    memset(g_old_pools, 0, sizeof g_old_pools);
    for (size_t i = 0; i < g_worker_count; i++) {
        vader_worker_t* w = g_workers[i];
        memset(w->old_current, 0, sizeof w->old_current);
        w->old_allocated = 0u;
    }
    memset(g_old_large_bins, 0, sizeof g_old_large_bins);
    g_old_large_top_bin = 0;
    size_t live = 0;
    /* The newest region first: it ends up deepest in its pool or bin. */
    for (size_t i = g_old_region_count; i-- > 0;) {
        vader_old_region_t* r = &g_old_region_table[i];
        if (r->class_idx < 0) {
            /* Large: one object at r->base, if any (r->cur > r->base). */
            if (r->cur == r->base) continue;
            vader_obj_header_t* h = (vader_obj_header_t*) r->base;
            if (h->mark == g_mark_value) {
                r->freed = 0u;
                live += r->slot_size;
            } else {
                h->mark = 0u;
                h->type_index = VADER_TYPE_INDEX_FREE;
                if (!r->freed && r->slot_size >= VADER_OLD_DISCARD_MIN) vader_os_discard(r->base, r->end);
                r->freed = 1u;
                size_t bin = vader_old_large_bin(r->slot_size);
                r->free_next = g_old_large_bins[bin];
                g_old_large_bins[bin] = r;
                if (bin > g_old_large_top_bin) g_old_large_top_bin = bin;
            }
            continue;
        }
        r->free_head = NULL;
        for (char* slot = r->base; slot < r->cur; slot += r->slot_size) {
            vader_obj_header_t* h = (vader_obj_header_t*) slot;
            if (h->mark == g_mark_value) {
                live += r->slot_size;
            } else {
                h->mark = 0u;
                h->type_index = VADER_TYPE_INDEX_FREE;
                vader_obj_set_link(slot, r->free_head);
                r->free_head = slot;
            }
        }
        if (vader_old_region_has_room(r)) {
            r->free_next = g_old_pools[r->class_idx];
            g_old_pools[r->class_idx] = r;
        }
    }
    __atomic_store_n(&g_old_live_bytes, live, __ATOMIC_RELAXED);
}

/* ---- init and shutdown --------------------------------------------------- */

static size_t vader_clamp_size(size_t x, size_t lo, size_t hi) {
    return x < lo ? lo : (x > hi ? hi : x);
}

/* Lay both halves of `w`'s young generation out over `block`: from-space first,
 * allocation resuming at `from_cur`, then an empty to-space. */
static void vader_young_carve(vader_worker_t* w, char* block, size_t half, char* from_cur) {
    vader_gen_t* young = &w->young;
    young->block      = block;
    young->half_bytes = half;
    young->from.base  = block;
    young->from.cur   = from_cur;
    young->from.end   = block + half;
    young->to.base    = block + half;
    young->to.cur     = young->to.base;
    young->to.end     = young->to.base + half;
    vader_alloc_limit_refresh(w);
}

/* Give `w` a heap of its own: a young generation and a card table over the old
 * reservation, which it dirties alone. Untouched, the table costs no memory. */
static void vader_gc_worker_init(vader_worker_t* w) {
    if (g_worker_count == VADER_WORKERS_MAX) vader_trap("vader_gc: too many workers");
    char* young_block = (char*) malloc(g_young_bytes * 2u);
    if (young_block == NULL) vader_trap("vader_gc_init: young arena malloc failed");
    vader_young_carve(w, young_block, g_young_bytes, young_block);
    /* The card tables end on a whole group, which a minor copies at once. */
    size_t groups = vader_card_groups_of(g_card_count);
    w->cards = (uint8_t*) calloc(groups * VADER_CARD_GROUP, 1u);
    if (w->cards == NULL) vader_trap("vader_gc_init: card-table calloc failed");
    w->card_shadow = (uint8_t*) malloc(groups * VADER_CARD_GROUP);
    if (w->card_shadow == NULL) vader_trap("vader_gc_init: card-shadow malloc failed");
    w->card_groups = (uint8_t*) calloc(groups, 1u);
    if (w->card_groups == NULL) vader_trap("vader_gc_init: card-group calloc failed");
    w->card_group_shadow = (uint8_t*) calloc(groups, 1u);
    if (w->card_group_shadow == NULL) vader_trap("vader_gc_init: card-group-shadow calloc failed");
    g_workers[g_worker_count++] = w;
}

void vader_gc_init(void) {
    if (g_gc_initialized) return;

    /* Stack-object roots (vader_gc_frame_t.stack_objs) depend on type_index 0
     * being a scan no-op. A hoisted stack storage is zero-init'd (type 0) and may
     * be handed to vader_gc_scan_object in the window before its `struct.new`
     * writes the real header: that scan must trace no fields. Type 0 is reserved
     * for the `null` primitive (VADER_BOX_TAG_NULL) and a BcScalar emits no
     * info row, so slot 0 stays KIND_NONE with no pointer/ref fields. Assert the
     * contract here: a future seed that put a pointer-bearing type at index 0
     * would make that pre-init scan walk past the storage (silent OOB). */
    if (vader_type_info_count > 0
        && (vader_type_info_table[0].ptr_count != 0
            || vader_type_info_table[0].ref_count != 0)) {
        vader_trap("vader_gc_init: type_info_table[0] must be a scan no-op "
                   "(reserved null slot): stack-object rooting relies on it");
    }
    /* A fn or array row lists its one pointer in `ref_offsets`: the scans read
     * every `ptr_offsets` entry as a box, so a raw pointer listed there would
     * never be forwarded. */
    for (size_t i = 0; i < vader_type_info_count; i++) {
        const vader_type_info_t* info = &vader_type_info_table[i];
        if ((info->kind == VADER_TYPE_KIND_FN || info->kind == VADER_TYPE_KIND_ARRAY)
            && info->ptr_count != 0) {
            vader_trap("vader_gc_init: a fn or array type lists its pointer as a box "
                       "field; its C comes from an older compiler");
        }
    }

    g_gc_stress       = vader_gc_env_bool("VADER_GC_STRESS");
    g_gc_stress_major = vader_gc_env_bool("VADER_GC_STRESS_MAJOR");
    g_gc_stress_switch = vader_gc_env_bool("VADER_GC_STRESS_SWITCH");
    g_gc_check_box    = vader_gc_env_bool("VADER_GC_CHECK_BOX");
    g_gc_scan_all_old = vader_gc_env_bool("VADER_GC_SCAN_ALL_OLD");
    g_gc_poison       = vader_gc_env_bool("VADER_GC_POISON");
    g_gc_verify       = vader_gc_env_bool("VADER_GC_VERIFY");
    g_gc_no_cstack_scan = vader_gc_env_bool("VADER_GC_NO_CSTACK_SCAN");

    /* VADER_GC_PROFILE : at exit, walk young and old and dump the live set
     * bucketed by type_index: sorted by total bytes, top-20. Useful to
     * answer "what's filling my GC arena?". OOM paths abort() so atexit
     * doesn't fire ; the OOM trap dumps inline before aborting. */
    const char* gc_prof_env = getenv("VADER_GC_PROFILE");
    if (gc_prof_env != NULL && gc_prof_env[0] != '\0' && gc_prof_env[0] != '0') {
        g_gc_profile = 1;
        atexit(vader_gc_profile_dump);
    }

    /* VADER_ALLOC_BY_TYPE : count every allocation by type_index and dump the
     * table at exit. The static report says which SITES stayed on the heap;
     * this says how often each one fires, which is what decides whether a site
     * is worth a change. */
    const char* abt_env = getenv("VADER_ALLOC_BY_TYPE");
    if (abt_env != NULL && abt_env[0] != '\0' && abt_env[0] != '0') {
        vader_alloc_by_type_on = 1;
        atexit(vader_alloc_by_type_dump);
    }

    /* RAM-proportional defaults (the zero-tuning primary interface; the absolute
     * VADER_GC_OLD_MAX env var below still overrides). Derive the old reservation
     * cap from physical RAM; fall back to the fixed #defines when RAM can't be
     * read. Young is not scaled: it keeps its size unless an object needs more. */
    g_young_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_BYTES", (size_t) VADER_GC_YOUNG_BYTES);
    size_t ram = vader_os_physical_ram();
    size_t old_max_default  = (size_t) VADER_GC_OLD_MAX;
    double pct = vader_gc_env_percent("VADER_GC_RAM_PERCENT", (double) VADER_GC_RAM_PERCENT);
    if (ram > 0) {
        /* budget = the committed ceiling the GC may reach. The old gen is a
         * single non-moving reservation (lazily committed: untouched pages cost
         * no RSS) and needs no to-space: reserve young's two semi-spaces, then
         * give the rest to the old reservation. */
        size_t budget        = (size_t) ((double) ram * pct / 100.0);
        size_t young_reserve = g_young_bytes * 2u;
        size_t old_budget    = budget > young_reserve ? budget - young_reserve : budget / 2u;
        old_max_default  = vader_clamp_size(old_budget, VADER_GC_OLD_CAP_MIN, (size_t) VADER_GC_OLD_MAX);
    }

    /* Auto-grow ceilings (env-tunable, default to the RAM-derived / compile-time caps). */
    g_old_max_bytes   = vader_gc_env_bytes("VADER_GC_OLD_MAX",   old_max_default);
    g_young_max_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_MAX", (size_t) VADER_GC_YOUNG_MAX);

    /* Old: a single non-moving reservation at the cap, lazily committed. Objects
     * are bump-carved into class regions and never move, so there is no to-space
     * and no grow-time relocation. The reservation size IS the cap; untouched
     * pages stay uncommitted, so RSS tracks the live working set, not the
     * reservation. */
    g_old_capacity  = g_old_max_bytes;
    g_old_block     = vader_os_reserve(g_old_capacity);
    if (g_old_block == NULL) vader_trap("vader_gc_init: old-gen reservation failed (out of address space)");
    g_old_bump      = g_old_block;
    g_old_committed = g_old_block;
    g_old_block_end = g_old_block + g_old_capacity;
    memset(g_old_pools, 0, sizeof g_old_pools);
    g_old_region_limit = g_old_capacity / (VADER_OLD_SMALL_MAX + VADER_OLD_CLASS_GRAN) + 1u;
    g_old_region_table = (vader_old_region_t*) vader_os_reserve(g_old_region_limit * sizeof(vader_old_region_t));
    if (g_old_region_table == NULL) vader_trap("vader_gc_init: region table reservation failed (out of address space)");
    g_old_region_count = 0;
    g_old_region_committed = 0;
    memset(g_old_large_bins, 0, sizeof g_old_large_bins);
    g_old_large_top_bin = 0;
    g_old_live_bytes = 0;
    g_old_live_after_major = 0;
    g_mark_value     = 1u;

    /* A card table covers the whole reservation, one byte per VADER_CARD_BYTES.
     * Old objects never move, so it is sized once and never relocated. */
    g_card_count = (g_old_capacity + VADER_CARD_BYTES - 1u) / VADER_CARD_BYTES;
    vader_old_base = (uintptr_t) g_old_block;
    vader_old_end  = (uintptr_t) g_old_block_end;

    vader_gc_worker_init(&vader_worker);
    g_gc_initialized = 1;
}

void vader_gc_shutdown(void) {
    if (!g_gc_initialized) return;
    for (size_t i = 0; i < g_worker_count; i++) {
        vader_worker_t* w = g_workers[i];
        free(w->young.block);
        memset(&w->young, 0, sizeof w->young);
        vader_alloc_limit_refresh(w);
        free(w->cards);
        free(w->card_shadow);
        free(w->card_groups);
        free(w->card_group_shadow);
        free(w->gray_stack);
        memset(w->old_current, 0, sizeof w->old_current);
        w->old_allocated = 0u;
        w->cards = NULL;
        w->card_shadow = NULL;
        w->card_groups = NULL;
        w->card_group_shadow = NULL;
        w->gray_stack = NULL;
        w->gray_len = w->gray_cap = 0;
    }
    g_worker_count = 0;
    /* Release the old-gen reservation and its region metadata. */
    if (g_old_block != NULL) {
        vader_os_release(g_old_block, g_old_capacity);
    }
    if (g_old_region_table != NULL) {
        vader_os_release((char*) g_old_region_table, g_old_region_limit * sizeof(vader_old_region_t));
    }
    g_old_region_table = NULL;
    g_old_region_count = g_old_region_limit = g_old_region_committed = 0;
    g_old_block = g_old_bump = g_old_committed = g_old_block_end = NULL;
    g_old_capacity = g_old_live_bytes = g_old_live_after_major = 0;
    memset(g_old_large_bins, 0, sizeof g_old_large_bins);
    g_old_large_top_bin = 0;
    memset(g_old_pools, 0, sizeof g_old_pools);
    vader_old_base    = 0;
    vader_old_end     = 0;
    g_card_count      = 0;
    g_gc_initialized  = 0;
}

/* ---- allocation ---------------------------------------------------------- */

/* Internal bump in `w`'s young from-space. Caller must have ensured capacity. */
static void* vader_gc_alloc_young_unchecked(vader_worker_t* w, size_t aligned) {
    void* p = w->young.from.cur;
    w->young.from.cur += aligned;
    return p;
}

/* Grow the young generation to `new_half` per semi-space: point its to-space at
 * a fresh, larger block and run a minor, which copies into it every live young
 * object that does not promote (forwarding fixes the pointers). Then free the
 * old block and carve both halves out of the new one. Young carries no card
 * table or write-barrier bounds. NULL malloc is the real RAM ceiling. */
static void vader_young_grow_to(vader_worker_t* w, size_t new_half) {
    vader_gen_t* young = &w->young;
    char* new_block = (char*) malloc(new_half * 2u);
    if (new_block == NULL) {
        fprintf(stderr,
            "vader_young_grow: malloc failed growing young arena to %zu MB x 2 "
            "(cap VADER_GC_YOUNG_MAX = %zu MB), out of RAM\n",
            new_half / (1024u * 1024u),
            g_young_max_bytes / (1024u * 1024u));
        vader_trap("vader_young_grow: out of memory (RAM ceiling)");
    }
    char* old_block = young->block;
    young->to.base = new_block;
    young->to.cur  = new_block;
    young->to.end  = new_block + new_half;
    vader_gc_minor(w);
    /* With survivors, the minor swapped and `from` is the new block's first
     * half; without, that half is empty and `from` still names the old block,
     * freed below. */
    char* survivors_end = new_block;
    if (young->from.base == new_block) survivors_end = young->from.cur;
    free(old_block);
    vader_young_carve(w, new_block, new_half, survivors_end);
}

/* Pick a new young semi-space size large enough that, after a relocating
 * minor, the from-space can still bump-allocate `aligned`. Survivors are
 * bounded by the current occupancy, so `occupancy + aligned` is a safe target;
 * grow geometrically (x2) past it. Caps at VADER_GC_YOUNG_MAX: trap there is
 * the real ceiling. Returns without growing if the current half already fits. */
static void vader_young_grow_for(vader_worker_t* w, size_t aligned) {
    size_t occupancy = (size_t)(w->young.from.cur - w->young.from.base);
    size_t want = occupancy + aligned;
    size_t new_half = w->young.half_bytes * 2u;
    if (new_half < want) new_half = want;
    if (new_half > g_young_max_bytes) new_half = g_young_max_bytes;
    if (new_half < want) {
        fprintf(stderr,
            "vader_young_grow: live young %zu MB + object %zu MB exceeds cap "
            "VADER_GC_YOUNG_MAX %zu MB\n",
            occupancy / (1024u * 1024u), aligned / (1024u * 1024u),
            g_young_max_bytes / (1024u * 1024u));
        /* abort() skips atexit handlers: dump the live set inline so
         * VADER_GC_PROFILE works on the OOM cases we most want to diagnose. */
        if (g_gc_profile) vader_gc_profile_dump();
        vader_trap("vader_young_grow: object + live set exceeds young cap");
    }
    if (new_half > w->young.half_bytes) vader_young_grow_to(w, new_half);
}

/* Reclamation trigger for the non-moving old gen: call after a minor from the
 * allocator (a safe point: not re-entrant into a collect). The slab never
 * compacts, so without this the old footprint would equal the TOTAL promotion
 * volume (dead never swept) instead of the live set. Fire a major (which
 * sweeps dead old) once the old footprint has grown past
 * `live_after_last_major x HEADROOM`, never below VADER_GC_OLD_MAJOR_FLOOR (so
 * small programs never major). */
static void vader_old_maybe_major(void) {
    size_t threshold = g_old_live_after_major
        * (size_t) VADER_GC_OLD_HEADROOM_NUM / (size_t) VADER_GC_OLD_HEADROOM_DEN;
    if (threshold < (size_t) VADER_GC_OLD_MAJOR_FLOOR) threshold = (size_t) VADER_GC_OLD_MAJOR_FLOOR;
    if (vader_old_live() > threshold) {
        vader_major_collect();
    }
}

/* Run a major to free room in the old generation, and forget that a carve hit
 * its cap before. */
static void vader_old_make_room(void) {
    vader_major_collect();
    g_old_alloc_failed_at_cap = 0;
}

/* `bytes` in the old generation for `w`, which holds the monitor, and which a
 * major makes room in when it is full. An old slot starts on the alignment of
 * an array buffer. The object stays unmarked until `w` lets the monitor go
 * (`vader_gc_mark_monitor_born`). */
static void* vader_gc_alloc_old(vader_worker_t* w, size_t bytes) {
    void* p = vader_old_alloc(w, bytes);
    if (p == NULL) {
        vader_old_make_room();
        p = vader_old_alloc(w, bytes);
    }
    if (p == NULL) vader_trap("vader_gc_alloc: old reservation exhausted at cap (VADER_GC_OLD_MAX)");
    if (w->monitor_born_len == w->monitor_born_cap) {
        size_t cap = 64u;
        if (w->monitor_born_cap != 0u) cap = w->monitor_born_cap * 2u;
        char** grown = (char**) realloc(w->monitor_born, cap * sizeof(char*));
        if (grown == NULL) vader_trap("vader_gc_alloc: out of memory");
        w->monitor_born = grown;
        w->monitor_born_cap = cap;
    }
    w->monitor_born[w->monitor_born_len++] = (char*) p;
    return p;
}

/* Mark live what `w` allocated under the monitor, whole by now: from here on a
 * minor scans them under a dirty card, and their writes go through the
 * barrier as any old object's. */
static void vader_gc_mark_monitor_born(vader_worker_t* w) {
    for (size_t i = 0; i < w->monitor_born_len; i++) {
        vader_obj_publish_mark((vader_obj_header_t*) w->monitor_born[i]);
    }
    w->monitor_born_len = 0u;
}

/* Leave the young generation of `w` empty: a minor promotes every survivor,
 * unless the old generation is full, which a major makes room in. */
static void vader_gc_empty_young(vader_worker_t* w) {
    if (!g_gc_initialized || w->young.from.cur == w->young.from.base) return;
    vader_gc_minor(w);
    if (w->young.from.cur == w->young.from.base) return;
    vader_old_make_room();
    vader_gc_minor(w);
    if (w->young.from.cur != w->young.from.base) {
        vader_trap("vader_gc: the old reservation is full, a value cannot pass to another worker");
    }
}

/* Everything the fast path of `vader_gc_alloc` leaves out: init, counters,
 * stress, collection and growth. Out of line so the fast path needs no stack
 * frame. */
static VADER_NOINLINE void* vader_gc_alloc_slow(vader_worker_t* w, size_t bytes) {
    if (VADER_UNLIKELY(!g_gc_initialized)) vader_gc_init();
    vader_gc_safepoint(NULL);
    vader_arena_t* from = &w->young.from;
    /* Count raw requested bytes (same basis as `copied`) so the profiler can
     * report an alloc'd-vs-survived ratio. One increment per call. */
    w->counts.alloc_bytes += bytes;
    w->counts.alloc_count += 1;
    if (VADER_UNLIKELY(w->in_monitor)) return vader_gc_alloc_old(w, bytes);
    size_t aligned = vader_gc_align(bytes);
    /* A single object bigger than a young semi-space can never fit, however
     * much we collect: grow young to hold it (relocating the live set into a
     * larger block) before proceeding. */
    if (VADER_UNLIKELY(aligned > w->young.half_bytes)) {
        vader_young_grow_for(w, aligned);
    }
    /* Major-stress forces a full mark+sweep at every safepoint (debug-only). */
    if (VADER_UNLIKELY(g_gc_stress_major)) vader_major_collect();
    int young_full = (from->cur + aligned > from->end);
    if (VADER_UNLIKELY(young_full || g_gc_stress)) {
        vader_gc_minor(w);
        if (VADER_UNLIKELY(from->cur + aligned > from->end)) {
            /* Minor didn't free enough: young still holds survivors that did
             * not promote, because the old slab was full or they have not
             * reached tenure. Force a major to open promotion room and retry. */
            vader_major_collect();
            /* The major sweeps dead old objects, opening promotion room. Retry a
             * minor (now that old has room) to drain the survivors that couldn't
             * promote during the major's preliminary minor. Reset the cap-failure
             * flag first so it reflects only this post-sweep promotion attempt. */
            g_old_alloc_failed_at_cap = 0;
            if (VADER_UNLIKELY(from->cur + aligned > from->end)) {
                vader_gc_minor(w);
            }
            if (VADER_UNLIKELY(from->cur + aligned > from->end)) {
                /* Even a full collection left no room. Two causes: a young
                 * working set larger than the semi-space (grow young), or the old
                 * reservation exhausted at its cap so survivors can't promote and
                 * pile up in young (the real ceiling: trap, don't grow young
                 * forever). The flag distinguishes them: it is set when a
                 * post-sweep promotion failed to carve at the reservation cap. */
                if (VADER_UNLIKELY(g_old_alloc_failed_at_cap)) {
                    fprintf(stderr,
                        "vader_gc_alloc: out of memory, old reservation full at cap %zu MB "
                        "(VADER_GC_OLD_MAX); survivors cannot promote\n",
                        g_old_capacity / (1024u * 1024u));
                    if (g_gc_profile) vader_gc_profile_dump();
                    vader_trap("vader_gc_alloc: old reservation exhausted at cap");
                }
                /* Otherwise the young working set genuinely exceeds the semi-
                 * space: grow young to fit it (capped) rather than failing. */
                vader_young_grow_for(w, aligned);
            }
        }
        /* Reclaim dead old in place once it has grown past live x headroom (the
         * non-moving slab never compacts, so nothing else frees it). */
        vader_old_maybe_major();
    }
    return vader_gc_alloc_young_unchecked(w, aligned);
}

/* The test is strict, so the uninitialised state (cursor and limit both NULL)
 * fails it even for zero bytes. Kept out of line: link-time optimisation would
 * otherwise copy it into every allocation site. */
VADER_NOINLINE void* vader_gc_alloc(size_t bytes) {
    vader_worker_t* w = &vader_worker;
    bytes = vader_obj_bytes(bytes);
    size_t aligned = vader_gc_align(bytes);
    if (VADER_LIKELY((uintptr_t) w->young.from.cur + aligned < (uintptr_t) vader_alloc_limit_of(w))) {
        return vader_gc_alloc_young_unchecked(w, aligned);
    }
    return vader_gc_alloc_slow(w, bytes);
}

_Static_assert(VADER_ARRAY_SLOT_ALIGN == 2u * VADER_GC_ALIGN,
               "one filler moves a block onto the slot alignment");

/* The bytes to leave at `at` ahead of an array buffer for its slots to land on
 * `VADER_ARRAY_SLOT_ALIGN`: none, or one filler. */
static inline size_t vader_gc_slot_pad(const char* at) {
    return (uintptr_t) at & (VADER_ARRAY_SLOT_ALIGN - 1u);
}

static inline void vader_gc_put_filler(char* at) {
    ((vader_obj_header_t*) at)->type_index = VADER_TYPE_INDEX_FILLER;
}

/* `vader_gc_alloc` for an array buffer, or for a new array's header and buffer
 * in one block: the block starts on `VADER_ARRAY_SLOT_ALIGN`, behind a filler
 * when the cursor is off it. */
static VADER_NOINLINE void* vader_gc_alloc_slot_aligned(size_t bytes) {
    vader_worker_t* w = &vader_worker;
    size_t aligned = vader_gc_align(bytes);
    char*  cur     = w->young.from.cur;
    size_t pad     = vader_gc_slot_pad(cur);
    if (VADER_LIKELY((uintptr_t) cur + pad + aligned < (uintptr_t) vader_alloc_limit_of(w))) {
        if (pad != 0u) vader_gc_put_filler(cur);
        w->young.from.cur = cur + pad + aligned;
        return cur + pad;
    }
    /* An old slot is aligned already. */
    if (VADER_UNLIKELY(w->in_monitor)) return vader_gc_alloc_slow(w, bytes);
    /* The slow path bumps the young cursor last, so a block that lands on the
     * boundary hands its spare filler back. */
    char* block = (char*) vader_gc_alloc_slow(w, bytes + VADER_GC_ALIGN);
    if (vader_gc_slot_pad(block) == 0u) {
        w->young.from.cur       -= VADER_GC_ALIGN;
        w->counts.alloc_bytes   -= VADER_GC_ALIGN;
        return block;
    }
    vader_gc_put_filler(block);
    return block + VADER_GC_ALIGN;
}
