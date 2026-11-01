/* rt/gc_heap.c: where objects live: the young semi-spaces, the old slab,
 * allocation and sizing.
 *
 * Allocation bumps the young from-space; its slow path collects or grows young:
 * an allocation never lands in old directly. The `VADER_GC_*` sizes are read at
 * `vader_gc_init`. */

#include "internal.h"

/* The old generation is a non-moving mark-sweep slab, NOT a copying semi-space
 * pair. It is a single big address-space reservation (mmap / VirtualAlloc,
 * lazily committed: untouched pages cost ~0 RSS) carved into class-homogeneous
 * regions by a global bump.
 * Objects never move, so:
 *   - membership is one range check over [g_old_block, g_old_bump);
 *   - there is no 2x to-space and no survivor-copy major pause;
 *   - the card table covers the fixed reservation once: no grow-time reslice.
 *
 * Small objects (<= VADER_OLD_SMALL_MAX) use 16 B size classes; each class owns
 * regions (bump-carved) + a free list threaded through freed slots' `forward`
 * field. Large objects get a one-object region each, `madvise`-released on free
 * and kept for reuse in bins by size (`vader_old_large_bin`). Reclamation is
 * mark (toggle `g_mark_value`, trace from roots + young survivors via a gray
 * worklist) + sweep (rebuild the free lists from unmarked slots). See
 * `vader_major_collect`. */

#define VADER_OLD_CLASS_GRAN   16u
#define VADER_OLD_SMALL_MAX_LOG2 10u
#define VADER_OLD_SMALL_MAX    (1u << VADER_OLD_SMALL_MAX_LOG2)               /* 1024 */
#define VADER_OLD_NUM_CLASSES  (VADER_OLD_SMALL_MAX / VADER_OLD_CLASS_GRAN)  /* 64 */
#define VADER_OLD_REGION_BYTES (256u * 1024u)   /* small-class region granularity */
#define VADER_OLD_MADVISE_MIN  (64u * 1024u)    /* only madvise freed large regions >= this */
/* Freed large regions are binned by size, VADER_OLD_LARGE_SUBBINS bins per power
 * of two above VADER_OLD_SMALL_MAX, up to the widest `size_t`. */
#define VADER_OLD_LARGE_SUB_LOG2 3u
#define VADER_OLD_LARGE_SUBBINS  (1u << VADER_OLD_LARGE_SUB_LOG2)
#define VADER_OLD_LARGE_BINS     ((64u - VADER_OLD_SMALL_MAX_LOG2) * VADER_OLD_LARGE_SUBBINS)
#define VADER_OLD_LARGE_SCAN     32u   /* regions a large allocation inspects in its own bin */
_Static_assert(VADER_OLD_CLASS_GRAN % VADER_ARRAY_SLOT_ALIGN == 0,
               "a promoted array buffer keeps its slots on the slot alignment");

typedef struct {
    char*               free_head;   /* free list: link via each slot's `forward` */
    vader_old_region_t* current;     /* region we bump-allocate from */
} vader_old_class_t;

static vader_gen_t g_young = { {NULL,NULL,NULL}, {NULL,NULL,NULL}, NULL, 0 };

static char*  g_old_block     = NULL;   /* reservation base */
static char*  g_old_bump      = NULL;   /* global region-carve cursor (never retreats) */
static char*  g_old_block_end = NULL;   /* g_old_block + reservation capacity */
static size_t g_old_capacity  = 0;      /* reservation size in bytes (== the cap) */
static size_t g_old_live_bytes = 0;     /* slot bytes held by live old objects (accumulates promotions; recomputed exact at sweep) */
static size_t g_old_live_after_major = 0;  /* g_old_live_bytes right after the last sweep: the reclamation-trigger baseline */
static int    g_old_alloc_failed_at_cap = 0;  /* set when a carve hit the cap with empty free lists */

static vader_old_class_t   g_old_classes[VADER_OLD_NUM_CLASSES];
static vader_old_region_t* g_old_regions    = NULL;   /* all regions, carve order */
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
static size_t        g_total_collections = 0;
static size_t        g_total_copied = 0;
/* Allocation volume: every vader_gc_alloc request, surviving or not. Distinct
 * from g_total_copied (which counts only bytes that SURVIVED a collection):
 * short-lived garbage is invisible to total_copied but shows up here. The
 * per-pass profiler uses this to attribute raw allocation pressure. Only the
 * slow path counts, so the totals are complete only while the profiler routes
 * every allocation there. */
static size_t        g_total_alloc_bytes = 0;
static size_t        g_total_alloc_count = 0;

/* Hard caps: the size of the old reservation and of one young semi-space.
 * Env-tunable (VADER_GC_OLD_MAX / VADER_GC_YOUNG_MAX) so a too-large live set
 * traps at a deliberate ceiling instead of exhausting RAM. Set once in
 * `vader_gc_init`, where the old default is derived from physical RAM. */
static size_t        g_old_max_bytes = 0;
static size_t        g_young_max_bytes = 0;

/* Adaptive young sizing: the divisor `k` in `young_target = old_live / k`. A
 * minor collect conservatively re-scans the whole old card table, so its cost
 * is O(old size). With a fixed young, total scan work over a run is
 * (churn / young) * old: quadratic in the old live set. Sizing young
 * proportional to old keeps it linear in churn. 0 disables the heuristic
 * (fixed young). Env-tunable via VADER_GC_YOUNG_RATIO; set once in
 * `vader_gc_init`. */
static size_t        g_young_ratio = 2;

/* Ceiling on the adaptive young target: young proportional to old overshoots
 * the young working set, and growing past it buys little and costs RSS.
 * 0 = uncapped, which only the compile-time default can say: VADER_GC_YOUNG_CAP
 * takes a positive byte size. Set once in `vader_gc_init`. */
static size_t        g_young_cap = 0;

/* The bound the inline bump of `vader_gc_alloc` tests against: the young
 * from-space end, or NULL to send every allocation to the slow path: before
 * init, and under the stress modes and the profiler, which act on or count
 * every allocation. Refreshed whenever `g_young.from` moves and when the
 * profiler turns on; the stress flags are set before the first carve. */
static char* g_alloc_limit = NULL;

static void vader_alloc_limit_refresh(void) {
    if (g_gc_stress || g_gc_stress_major || g_prof_enabled > 0) {
        g_alloc_limit = NULL;
    } else {
        g_alloc_limit = g_young.from.end;
    }
}

static size_t vader_gc_align(size_t n) {
    return (n + (VADER_GC_ALIGN - 1u)) & ~(size_t)(VADER_GC_ALIGN - 1u);
}

static int vader_in_young_from(const void* p) {
    return (const char*)p >= g_young.from.base && (const char*)p < g_young.from.end;
}

/* Membership in either half of the young generation : `to` is where a minor
 * forwards a referent it does not promote, and a major leaves young referents
 * in `from`. An immortal (`.rodata`) or off-heap pointer is in neither. */
static int vader_in_young(const void* p) {
    return ((const char*)p >= g_young.to.base && (const char*)p < g_young.to.end)
        || vader_in_young_from(p);
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

/* Read the whole number in `env_name`. `fallback` when unset or empty; a trap
 * for anything else that is not digits alone. */
static size_t vader_gc_env_count(const char* env_name, size_t fallback, const char* expected) {
    const char* raw = getenv(env_name);
    if (raw == NULL || raw[0] == '\0') return fallback;
    unsigned long long count = 0;
    const char* end = vader_gc_read_digits(raw, &count);
    if (end == NULL || *end != '\0') vader_gc_env_refuse(env_name, raw, expected);
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
 * `slot_size` (class_idx >= 0 for small, -1 for a one-object large region).
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
    /* Large: a freed region that fits, else a fresh one. Its size stays a multiple
     * of the class granularity, so every region, and every slot in it, starts on
     * the slot alignment an array buffer needs. */
    aligned = (aligned + VADER_OLD_CLASS_GRAN - 1u) & ~(size_t) (VADER_OLD_CLASS_GRAN - 1u);
    vader_old_region_t** fit = vader_old_large_fit(aligned);
    if (fit != NULL) {
        vader_old_region_t* r = *fit;
        *fit = r->free_next;
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

/* Walk every LIVE old object (mark == g_mark_value) and invoke `fn`. Used by the
 * atom-GC heap walk, the histogram, and the profiler: every consumer that needs
 * to enumerate the old live set, which spans several regions. */
static void vader_old_foreach_live(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx) {
    for (vader_old_region_t* r = g_old_regions; r != NULL; r = r->next) {
        for (char* slot = r->base; slot < r->cur; slot += r->slot_size) {
            vader_obj_header_t* h = (vader_obj_header_t*) slot;
            if (h->mark == g_mark_value) fn(slot, h->type_index, ctx);
        }
    }
}

/* Invoke `fn` on every object of young from-space, one contiguous run, stepping
 * over the fillers. */
static void vader_young_foreach(void (*fn)(char* obj, uint32_t type_index, void* ctx), void* ctx) {
    char* scan = g_young.from.base;
    while (scan < g_young.from.cur) {
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

/* Sweep: rebuild every free list from the unmarked slots. A slot survives iff
 * `mark == g_mark_value` (set during the mark phase). Dead small slots are
 * stamped FREE (mark 0) and pushed to their class free list; dead large regions
 * are madvise-released and queued in their size bin for reuse. Recomputes
 * g_old_live_bytes. */
static void vader_old_sweep(void) {
    for (size_t i = 0; i < VADER_OLD_NUM_CLASSES; i++) g_old_classes[i].free_head = NULL;
    memset(g_old_large_bins, 0, sizeof g_old_large_bins);
    g_old_large_top_bin = 0;
    size_t live = 0;
    for (vader_old_region_t* r = g_old_regions; r != NULL; r = r->next) {
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
                if (!r->freed && r->slot_size >= VADER_OLD_MADVISE_MIN) vader_old_madvise_region(r);
                r->freed = 1u;
                size_t bin = vader_old_large_bin(r->slot_size);
                r->free_next = g_old_large_bins[bin];
                g_old_large_bins[bin] = r;
                if (bin > g_old_large_top_bin) g_old_large_top_bin = bin;
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

/* ---- init and shutdown --------------------------------------------------- */

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

/* Lay both young halves out over `block`: from-space first, allocation resuming
 * at `from_cur`, then an empty to-space. */
static void vader_young_carve(char* block, size_t half, char* from_cur) {
    g_young.block      = block;
    g_young.half_bytes = half;
    g_young.from.base  = block;
    g_young.from.cur   = from_cur;
    g_young.from.end   = block + half;
    g_young.to.base    = block + half;
    g_young.to.cur     = g_young.to.base;
    g_young.to.end     = g_young.to.base + half;
    vader_alloc_limit_refresh();
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
    g_gc_check_box    = vader_gc_env_bool("VADER_GC_CHECK_BOX");
    g_gc_scan_all_old = vader_gc_env_bool("VADER_GC_SCAN_ALL_OLD");
    g_gc_poison       = vader_gc_env_bool("VADER_GC_POISON");
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
     * read. Young is NOT scaled (its cap is a per-minor cost cliff, not a
     * memory limit). */
    size_t ram = vader_physical_ram_bytes();
    size_t old_max_default  = (size_t) VADER_GC_OLD_MAX;
    double pct = vader_gc_env_percent("VADER_GC_RAM_PERCENT", (double) VADER_GC_RAM_PERCENT);
    if (ram > 0) {
        /* budget = the committed ceiling the GC may reach. The old gen is a
         * single non-moving reservation (lazily committed: untouched pages cost
         * no RSS) and needs no to-space: reserve young's worst-case commit (its
         * cap x 2) then give the rest to the old reservation. */
        size_t budget        = (size_t) ((double) ram * pct / 100.0);
        size_t young_reserve = (size_t) VADER_GC_YOUNG_CAP_DEFAULT * 2u;
        size_t old_budget    = budget > young_reserve ? budget - young_reserve : budget / 2u;
        old_max_default  = vader_clamp_size(old_budget, VADER_GC_OLD_CAP_MIN, (size_t) VADER_GC_OLD_MAX);
    }

    /* Auto-grow ceilings (env-tunable, default to the RAM-derived / compile-time caps). */
    g_old_max_bytes   = vader_gc_env_bytes("VADER_GC_OLD_MAX",   old_max_default);
    g_young_max_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_MAX", (size_t) VADER_GC_YOUNG_MAX);

    /* Adaptive young-sizing divisor (young_target = old_live / ratio). Default
     * 2 (young ~ half the old live set); 0 turns the heuristic off. */
    g_young_ratio = vader_gc_env_count("VADER_GC_YOUNG_RATIO", g_young_ratio,
        "a whole number, 0 to turn adaptive young sizing off");

    /* Ceiling on the adaptive young target (byte size). */
    g_young_cap = vader_gc_env_bytes("VADER_GC_YOUNG_CAP", VADER_GC_YOUNG_CAP_DEFAULT);

    /* Young: one malloc spanning both semi-spaces. */
    size_t young_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_BYTES", (size_t)VADER_GC_YOUNG_BYTES);
    char* young_block = (char*) malloc(young_bytes * 2u);
    if (young_block == NULL) vader_trap("vader_gc_init: young arena malloc failed");
    vader_young_carve(young_block, young_bytes, young_block);

    /* Old: a single non-moving reservation at the cap, lazily committed. Objects
     * are bump-carved into class regions and never move, so there is no to-space
     * and no grow-time relocation. The reservation size IS the cap; untouched
     * pages stay uncommitted, so RSS tracks the live working set, not the
     * reservation. */
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
    memset(g_old_large_bins, 0, sizeof g_old_large_bins);
    g_old_large_top_bin = 0;
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
    vader_alloc_limit_refresh();
    g_old_block = g_old_bump = g_old_block_end = NULL;
    g_old_capacity = g_old_live_bytes = g_old_live_after_major = 0;
    g_old_regions = NULL;
    memset(g_old_large_bins, 0, sizeof g_old_large_bins);
    g_old_large_top_bin = 0;
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

/* ---- allocation ---------------------------------------------------------- */

/* Internal bump in the young from-space. Caller must have ensured capacity. */
static void* vader_gc_alloc_young_unchecked(size_t aligned) {
    void* p = g_young.from.cur;
    g_young.from.cur += aligned;
    return p;
}

/* Grow the young generation to `new_half` per semi-space: point `g_young.to` at
 * a fresh, larger block and run a minor, which copies into it every live young
 * object that does not promote (forwarding fixes the pointers). Then free the
 * old block and carve both halves out of the new one. Young carries no card
 * table or write-barrier bounds. NULL malloc is the real RAM ceiling. */
static void vader_young_grow_to(size_t new_half) {
    char* new_block = (char*) malloc(new_half * 2u);
    if (new_block == NULL) {
        fprintf(stderr,
            "vader_young_grow: malloc failed growing young arena to %zu MB x 2 "
            "(cap VADER_GC_YOUNG_MAX = %zu MB), out of RAM\n",
            new_half / (1024u * 1024u),
            g_young_max_bytes / (1024u * 1024u));
        vader_trap("vader_young_grow: out of memory (RAM ceiling)");
    }
    char* old_block = g_young.block;
    g_young.to.base = new_block;
    g_young.to.cur  = new_block;
    g_young.to.end  = new_block + new_half;
    vader_minor_collect();
    /* With survivors, the minor swapped and g_young.from is the new block's
     * first half; without, that half is empty and g_young.from still names the
     * old block, freed below. */
    char* survivors_end = new_block;
    if (g_young.from.base == new_block) survivors_end = g_young.from.cur;
    free(old_block);
    vader_young_carve(new_block, new_half, survivors_end);
}

/* Pick a new young semi-space size large enough that, after a relocating
 * minor, the from-space can still bump-allocate `aligned`. Survivors are
 * bounded by the current occupancy, so `occupancy + aligned` is a safe target;
 * grow geometrically (x2) past it. Caps at VADER_GC_YOUNG_MAX: trap there is
 * the real ceiling. Returns without growing if the current half already fits. */
static void vader_young_grow_for(size_t aligned) {
    size_t occupancy = (size_t)(g_young.from.cur - g_young.from.base);
    size_t want = occupancy + aligned;
    size_t new_half = g_young.half_bytes * 2u;
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
    if (new_half > g_young.half_bytes) vader_young_grow_to(new_half);
}

/* Adaptive young sizing: call after a standalone minor collect from the
 * allocator. Grows the young semi-space toward `old_live / g_young_ratio` so
 * the (churn / young) * old card-scan cost stays linear in churn instead of
 * quadratic in old. Hysteresis (target >= 1.5x current) avoids repeated
 * reallocations; growth never shrinks, so an explicit VADER_GC_YOUNG_BYTES
 * floor is preserved. Disabled when the ratio is 0. `vader_young_grow_to`
 * relocates survivors via an internal minor collect, so this MUST run outside
 * `vader_minor_collect` (hence the call site is the allocator, not the
 * collector: calling it from within a collect would recurse). */
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
    if (g_old_live_bytes > threshold) {
        vader_major_collect();
    }
}

/* Everything the fast path of `vader_gc_alloc` leaves out: init, counters,
 * stress, collection and growth. Out of line so the fast path needs no stack
 * frame. */
static VADER_NOINLINE void* vader_gc_alloc_slow(size_t bytes) {
    if (VADER_UNLIKELY(!g_gc_initialized)) vader_gc_init();
    /* Count raw requested bytes (same basis as g_total_copied) so the profiler
     * can report an alloc'd-vs-survived ratio. One increment per call. */
    g_total_alloc_bytes += bytes;
    g_total_alloc_count += 1;
    size_t aligned = vader_gc_align(bytes);
    /* A single object bigger than a young semi-space can never fit, however
     * much we collect: grow young to hold it (relocating the live set into a
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
            /* Minor didn't free enough: young still holds survivors that did
             * not promote, because the old slab was full or they have not
             * reached tenure. Force a major to open promotion room and retry. */
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
                vader_young_grow_for(aligned);
            }
        }
        /* A collect just ran: re-size young toward old so the next round of
         * churn triggers far fewer (expensive, O(old)) minors. */
        vader_young_maybe_grow_adaptive();
        /* Reclaim dead old in place once it has grown past live x headroom (the
         * non-moving slab never compacts, so nothing else frees it). */
        vader_old_maybe_major();
    }
    return vader_gc_alloc_young_unchecked(aligned);
}

/* The test is strict, so the uninitialised state (cursor and limit both NULL)
 * fails it even for zero bytes. Kept out of line: link-time optimisation would
 * otherwise copy it into every allocation site. */
VADER_NOINLINE void* vader_gc_alloc(size_t bytes) {
    size_t aligned = vader_gc_align(bytes);
    if (VADER_LIKELY((uintptr_t) g_young.from.cur + aligned < (uintptr_t) g_alloc_limit)) {
        return vader_gc_alloc_young_unchecked(aligned);
    }
    return vader_gc_alloc_slow(bytes);
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
    size_t aligned = vader_gc_align(bytes);
    char*  cur     = g_young.from.cur;
    size_t pad     = vader_gc_slot_pad(cur);
    if (VADER_LIKELY((uintptr_t) cur + pad + aligned < (uintptr_t) g_alloc_limit)) {
        if (pad != 0u) vader_gc_put_filler(cur);
        g_young.from.cur = cur + pad + aligned;
        return cur + pad;
    }
    /* The slow path bumps the young cursor last, so a block that lands on the
     * boundary hands its spare filler back. */
    char* block = (char*) vader_gc_alloc_slow(bytes + VADER_GC_ALIGN);
    if (vader_gc_slot_pad(block) == 0u) {
        g_young.from.cur    -= VADER_GC_ALIGN;
        g_total_alloc_bytes -= VADER_GC_ALIGN;
        return block;
    }
    vader_gc_put_filler(block);
    return block + VADER_GC_ALIGN;
}
