/* rt/gc_diag.c: the collector's debugging switches and reports.
 *
 * `VADER_GC_STRESS`, `VADER_GC_STRESS_MAJOR`, `VADER_GC_STRESS_SWITCH`,
 * `VADER_GC_CHECK_BOX`, `VADER_GC_POISON`, `VADER_GC_SCAN_ALL_OLD` and
 * `VADER_GC_NO_CSTACK_SCAN` change how the collector runs; `VADER_GC_PROFILE`,
 * `VADER_GC_HISTOGRAM` and `VADER_ALLOC_BY_TYPE` print what it saw. */

#include "internal.h"

/* Stress mode: set via `VADER_GC_STRESS=1`. When enabled, every
 * `vader_gc_alloc` triggers a minor collect. Forces every safepoint to
 * exercise the full shadow-stack walk, which turns intermittent rooting bugs
 * into deterministic failures. Atoms are collected only by a major:
 * `VADER_GC_STRESS_MAJOR` exercises them. Off by default: it slows a run by
 * orders of magnitude.
 * Captured once on init; the env var has no effect mid-run. */
static int g_gc_stress = 0;

/* Major-stress mode: set via `VADER_GC_STRESS_MAJOR=1`. The mark-sweep analog
 * of VADER_GC_STRESS: every `vader_gc_alloc` forces a FULL major (mark + sweep),
 * so the non-moving old gen's trace, free-list rebuild, and promotion-into-slab
 * paths run at every safepoint: turning intermittent old-gen rooting / sweep
 * bugs into deterministic failures. Even slower than STRESS; debug-only. */
static int g_gc_stress_major = 0;

/* Switch-stress mode: set via `VADER_GC_STRESS_SWITCH=1`. Every switch between
 * virtual threads (rt/virtual_threads.c) forces a full major first, so the
 * frames, defers and stack of each thread that is not running are walked while
 * that thread is parked. */
static int g_gc_stress_switch = 0;

/* Box-tag corruption check: set via `VADER_GC_CHECK_BOX=1`. When enabled,
 * `vader_gc_scan_box` traps the first time it meets a box whose `tag` is
 * neither NULL (0) nor a valid type index (< vader_type_info_count). Such a
 * tag can only be stray bytes (a heap-pointer's low 32 bits), so it pinpoints
 * which GC cycle first observes a corrupted box, and whether the box's
 * payload still points at a valid heap object (tag-only clobber) or not. Off
 * by default: the scan's existing `tag >= count` fast-path stays silent.
 *
 * The same switch also arms `vader_gc_check_object_alignment` below. */
static int g_gc_check_box = 0;

/* Skips `vader_gc_mark_cstack_conservative`: set via `VADER_GC_NO_CSTACK_SCAN=1`.
 *
 * That scan covers refs the precise shadow stack does not root: a live old ref
 * can sit only in a C local or a register. Skipping it therefore DROPS LIVE
 * OBJECTS. It is a diagnostic: with it on, a failure names a ref the precise
 * rooting misses, and never a tuning knob. */
static int g_gc_no_cstack_scan = 0;

/* Old-gen scan override: set via `VADER_GC_SCAN_ALL_OLD=1`. Forces
 * `vader_gc_scan_old_dirty_cards` to treat every card as dirty, i.e. to scan
 * and forward EVERY old object's slots on each minor. A/B probe: if a crash
 * disappears with this on, the bug is a missing card-mark (a write barrier
 * that didn't fire on an old->young edge), not the GC scan itself. Off by
 * default. */
static int g_gc_scan_all_old = 0;

/* Young poison mode, set via `VADER_GC_POISON=1`: at the end of every minor, the
 * young bytes it abandons are filled with VADER_GC_POISON_BYTE, so a read of an
 * abandoned object fails at once (docs/adr/0107). Off by default. */
static int g_gc_poison = 0;

static int g_gc_profile = 0;

/* ---- per-type allocation counter (VADER_ALLOC_BY_TYPE) ------------------- */

/* Storage + dump for the counter declared in vader.h. Sorted by count, since
 * the question it answers is "what does this run allocate MOST of". */
uint64_t vader_alloc_by_type[VADER_ALLOC_TYPES_MAX];
int      vader_alloc_by_type_on = 0;

static void vader_alloc_by_type_dump(void) {
    size_t limit = vader_type_info_count < VADER_ALLOC_TYPES_MAX
                 ? vader_type_info_count : VADER_ALLOC_TYPES_MAX;
    uint64_t total = 0;
    for (size_t i = 0; i < VADER_ALLOC_TYPES_MAX; i++) total += vader_alloc_by_type[i];
    if (total == 0) return;
    fprintf(stderr, "\n[VADER_ALLOC_BY_TYPE] %llu allocations\n",
            (unsigned long long) total);
    /* Selection sort over the top 25: the table is small and this runs once. */
    for (int rank = 0; rank < 25; rank++) {
        size_t best = 0;
        uint64_t best_n = 0;
        for (size_t i = 0; i < VADER_ALLOC_TYPES_MAX; i++) {
            if (vader_alloc_by_type[i] > best_n) { best_n = vader_alloc_by_type[i]; best = i; }
        }
        if (best_n == 0) break;
        const char* kind = "?";
        if (best < limit) {
            switch (vader_type_info_table[best].kind) {
                case VADER_TYPE_KIND_STRUCT: kind = "struct"; break;
                case VADER_TYPE_KIND_ARRAY:  kind = "array";  break;
                default: break;
            }
        }
        fprintf(stderr, "  type %3zu  %-7s %12llu  (%4.1f%%)\n",
                best, kind, (unsigned long long) best_n,
                100.0 * (double) best_n / (double) total);
        vader_alloc_by_type[best] = 0;   /* consumed */
    }
}

/* Root-candidate alignment check: same `VADER_GC_CHECK_BOX=1` switch, because
 * it catches the same disease one step earlier. Every arena hands out slots
 * through `vader_gc_align` (VADER_GC_ALIGN == 8), so a live object's address is
 * ALWAYS a multiple of 8. A root cell offering something else is not an object:
 * it is stray bytes that happen to land inside an arena's range, and the range
 * check alone waves it through.
 *
 * Letting it through is not a missed root, it is a WRITE: `vader_gc_forward`
 * reaches `vader_gc_copy_into`, which stores the forwarding pointer INTO the
 * source: 8 bytes at an arbitrary arena address, silently. This check catches
 * it in the shipped binary, on demand.
 *
 * Deliberately NOT `#ifndef NDEBUG`: stack layout decides which stray bytes are
 * visible, so the bug may show only in an optimised release build, where a
 * debug-only guard would not exist.
 *
 * Out of line: `vader_gc_forward` tests the flag itself, a single load-and-test
 * the branch predictor never misses. */
static VADER_NOINLINE void vader_gc_check_object_alignment(const void* obj, uint32_t type_index) {
    if (((uintptr_t) obj & (uintptr_t)(VADER_GC_ALIGN - 1u)) == 0u) return;
    fprintf(stderr,
        "\n[VADER_GC_CHECK_BOX] root candidate is not %u-aligned (cycle=%d)\n"
        "  address    : %p  (%u mod %u)\n"
        "  claimed tag: %u\n"
        "  in young   : %s\n"
        "  in old     : %s\n"
        "Every arena slot is %u-aligned, so this is stray bytes read from a root\n"
        "cell, not an object. Forwarding it would WRITE the forwarding pointer\n"
        "into it. Run under a debugger to see which root cell holds it.\n",
        VADER_GC_ALIGN, g_cycle,
        obj, (unsigned)((uintptr_t) obj & (uintptr_t)(VADER_GC_ALIGN - 1u)), VADER_GC_ALIGN,
        type_index,
        vader_in_young_from(obj) ? "yes" : "no",
        vader_in_old(obj)        ? "yes" : "no",
        VADER_GC_ALIGN);
    vader_trap("VADER_GC_CHECK_BOX: root candidate is not object-aligned");
}

/* VADER_GC_CHECK_BOX diagnostic. `boxp->tag` is out of the valid type-index
 * range: it can only be stray bytes (typically a heap pointer's low 32 bits).
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

/* ---- VADER_GC_PROFILE: live-set breakdown by type ------------------------ */

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

/* Per-object tally: shared by the young contiguous walk and the old region walk
 * (via vader_old_foreach_live), since the old gen spans several regions. */
typedef struct {
    vader_gc_prof_entry_t* tally;
    size_t  array_buf_bucket;
    size_t* arr_kind_bytes;
    size_t* arr_kind_count;
    size_t* arr_boxed_slots;
    /* Slots of BOXED bufs whose every live slot holds a ref or null (a STRUCT,
     * ARRAY or FN tag): a buf that could have been `VADER_ARRAY_KIND_REF`, its
     * tags recovered from the object headers. An `Any[]` mixing boxed
     * primitives is not counted. */
    size_t* arr_ref_slots;
    /* Sum of ptr_count over live STRUCT objects: their `vader_box_t` fields.
     * Upper bound on what riding those fields as raw refs would reclaim, since
     * a union holding a primitive has to stay boxed. */
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
                    k != VADER_TYPE_KIND_FN) {
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

/* Name of an ARRAY_BUF element kind, in `vader_array_kind_t` order: a kind
 * added there takes its name here. */
static const char* vader_array_kind_name(int kind) {
    static const char* names[] = {
        [VADER_ARRAY_KIND_BOXED] = "BOXED", [VADER_ARRAY_KIND_U8]   = "U8",
        [VADER_ARRAY_KIND_U16]   = "U16",   [VADER_ARRAY_KIND_U32]  = "U32",
        [VADER_ARRAY_KIND_U64]   = "U64",   [VADER_ARRAY_KIND_I8]   = "I8",
        [VADER_ARRAY_KIND_I16]   = "I16",   [VADER_ARRAY_KIND_I32]  = "I32",
        [VADER_ARRAY_KIND_I64]   = "I64",   [VADER_ARRAY_KIND_F32]  = "F32",
        [VADER_ARRAY_KIND_F64]   = "F64",   [VADER_ARRAY_KIND_CHAR] = "CHAR",
        [VADER_ARRAY_KIND_BOOL]  = "BOOL",  [VADER_ARRAY_KIND_REF]  = "REF",
    };
    if (kind < 0 || kind >= (int) (sizeof names / sizeof names[0]) || names[kind] == NULL) return "?";
    return names[kind];
}

/* Walk young's from-space and old's live slots and tally objects bucketed by
 * type_index. Sort by total bytes, print top-20. Called via atexit when
 * VADER_GC_PROFILE is set, and inline from the OOM trap (abort() skips
 * atexit). */
static void vader_gc_profile_dump(void) {
    if (!g_gc_initialized) return;
    /* +1 for the ARRAY_BUF sentinel bucket. ARRAY_BUF objects (header tag
     * VADER_TYPE_INDEX_ARRAY_BUF) are tallied into this one extra bucket, just
     * past the real type indices [0, count), see the bucketing + display below. */
    size_t nbuckets = vader_type_info_count + 1u;
    const size_t array_buf_bucket = vader_type_info_count;
    vader_gc_prof_entry_t* tally = (vader_gc_prof_entry_t*) calloc(nbuckets, sizeof(vader_gc_prof_entry_t));
    if (tally == NULL) return;
    for (size_t i = 0; i < nbuckets; i++) tally[i].type_index = (uint32_t) i;

    /* ARRAY_BUF element-kind breakdown, and the boxed slots that could ride as
     * raw refs. */
    size_t arr_kind_bytes[16] = { 0 };
    size_t arr_kind_count[16] = { 0 };
    size_t arr_boxed_slots = 0;
    size_t arr_ref_slots = 0;
    size_t struct_ptr_slots = 0;

    /* Young: one contiguous from-space walk. Old: the non-moving slab's live
     * slots, by region. The BUFFER sentinel has no dedicated bucket: it falls
     * into bucket 0 (a cosmetic miscount in this debug-only profile, never a
     * GC-correctness issue ; the size walk handles its bytes correctly). */
    size_t totals[2] = { 0, 0 };
    vader_gc_prof_ctx_t cy = { tally, array_buf_bucket, arr_kind_bytes, arr_kind_count, &arr_boxed_slots, &arr_ref_slots, &struct_ptr_slots, &totals[0] };
    vader_young_foreach(vader_gc_prof_tally, &cy);
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

    fprintf(stderr, "ARRAY_BUF by element_kind :\n");
    for (int k = 0; k < 16; k++) {
        if (arr_kind_count[k] == 0u) continue;
        fprintf(stderr, "  kind %-6s : %8.2f MB  (%llu bufs)\n",
                vader_array_kind_name(k),
                (double) arr_kind_bytes[k] / (1024.0 * 1024.0),
                (unsigned long long) arr_kind_count[k]);
    }
    fprintf(stderr, "  BOXED slots = %llu\n", (unsigned long long) arr_boxed_slots);

    /* A boxed slot holding a ref would shrink to a raw `void*`. */
    const size_t saving = sizeof(vader_box_t) - sizeof(void*);

    double arr_real_mb    = (double) (arr_ref_slots    * saving) / (1024.0 * 1024.0);
    double struct_real_mb = (double) (struct_ptr_slots * saving) / (1024.0 * 1024.0);
    fprintf(stderr, "reclaimable as raw refs (%zu B/slot) :\n", saving);
    fprintf(stderr, "  array all-ref slots = %llu  ->  %.2f MB (Any[] excluded)\n",
            (unsigned long long) arr_ref_slots, arr_real_mb);
    fprintf(stderr, "  struct box fields   = %llu  ->  %.2f MB (upper bound, a union of primitives stays boxed)\n",
            (unsigned long long) struct_ptr_slots, struct_real_mb);
    fprintf(stderr, "  combined            ->  %.2f MB\n", arr_real_mb + struct_real_mb);
}
