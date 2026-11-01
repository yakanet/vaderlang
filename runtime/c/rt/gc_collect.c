/* rt/gc_collect.c: the collections: a minor copies young and promotes its
 * survivors, a major marks and sweeps old.
 *
 * Forwarding, scanning, the card table, the roots (shadow stack, defer stack,
 * C stack), and the tenure that moves a young object out of a minor's reach
 * before C holds its address. */

#include "internal.h"

/* Old-gen mark bit value for the CURRENT epoch. Toggles 1↔2 each major so a
 * previous epoch's marks read as "unmarked" without a clear pass; a FREE slot
 * carries 0 (never equal to g_mark_value). `vader_old_alloc` stamps live=this. */
static uint8_t g_mark_value = 1u;

/* Set the first time a Vader function's ADDRESS is handed to C (`fn.addr`).
 * Until then no foreign callee can re-enter Vader, so no foreign call is a
 * safepoint and nothing lent to one can move. It never clears: once C holds the
 * address it may call it at any later point, through any other function. */
uint8_t vader_ffi_callback_escaped = 0u;

/* Set for the one minor `vader_ffi_callback_first_escape` runs: a shared array
 * buffer is promoted, whatever its age. */
static uint8_t g_minor_promote_shared = 0u;

/* Gray worklist: objects whose slots still need scanning. Reused by both
 * cycles: minor pushes freshly-promoted old objects (to forward their young
 * refs); major pushes freshly-marked old objects (to mark their children). */
static char**  g_gray_stack = NULL;
static size_t  g_gray_len   = 0;
static size_t  g_gray_cap   = 0;
static vader_cycle_t g_cycle = VADER_CYCLE_NONE;

/* Card table: one byte per VADER_CARD_BYTES of the old-gen reservation. The old
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
 * object spans, see `vader_gc_scan_old_dirty_cards`. */
static uint8_t* g_card_shadow = NULL;

/* Cards spanning the carved old prefix [g_old_block, g_old_bump): the live part
 * of the table. The minor scan bounds its table sweep to this (the uncommitted
 * reservation tail holds no objects). */
static inline size_t vader_old_used_cards(void) {
    return ((size_t)(g_old_bump - g_old_block) + VADER_CARD_BYTES - 1u) / VADER_CARD_BYTES;
}

/* Shadow-stack head. Each emitted C function pushes/pops a frame chained
 * through `prev`; the GC walks this list at collection time to enumerate
 * precise roots. */
vader_gc_frame_t* vader_gc_top = NULL;

/* Grow the gray worklist geometrically. Out of line, so that the push it serves
 * costs no stack frame in the collector's loops. */
static VADER_NOINLINE void vader_gray_grow(void) {
    size_t new_cap = g_gray_cap == 0u ? 4096u : g_gray_cap * 2u;
    char** ns = (char**) realloc(g_gray_stack, new_cap * sizeof(char*));
    if (ns == NULL) vader_trap("vader_gray_push: realloc failed");
    g_gray_stack = ns;
    g_gray_cap   = new_cap;
}

/* Push an object onto the gray worklist. */
static inline void vader_gray_push(char* obj) {
    if (VADER_UNLIKELY(g_gray_len == g_gray_cap)) vader_gray_grow();
    g_gray_stack[g_gray_len++] = obj;
}

/* Highest address of the current (main) thread's C stack: the scan upper bound.
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
 * regions: only reached for the few stack words that point into old. */
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
 * safepoint: a live old ref can sit only in a C local / register. The old gen
 * reuses freed slots eagerly, so the major must find those refs. We do it
 * conservatively: flush callee-saved registers (setjmp), then walk the C stack
 * word-by-word and MARK every old object any word points at (interior pointers
 * map to their slot). Old objects never move, so a false positive merely
 * retains a dead object: no pinning, no correctness risk. Found objects are
 * gray-pushed so their closure is marked too.
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

/* ---------- generational GC: copying young, mark-sweep old ---------- */

/* Size of an object in a from-space, in bytes. For variable-length buffers
 * (ARRAY_BUF sentinel) the size is read off the object itself; for
 * everything else the type info table provides a static size. TRAPS on a
 * non-heap kind or an out-of-range index: a zero size would be silently
 * skipped, leaving a mis-stamped object invisible to three heap walks at once.
 * The `bytes == 0` guards left at the call sites are unreachable and kept only
 * as defence. */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index) {
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) obj;
        return sizeof(vader_array_buf_t) + buf->capacity * vader_array_element_size(buf->element_kind);
    }
    if (type_index == VADER_TYPE_INDEX_BUFFER) {
        vader_buffer_t* b = (vader_buffer_t*) obj;
        return sizeof(vader_buffer_t) + b->byte_count;
    }
    /* A heap object the GC cannot size is a CODEGEN bug: the emitter stamped a
     * header with a type index carrying no `vader_type_info` entry (the table
     * covers Struct / Fn / Array only, so an erased `ref` gets none).
     *
     * Every caller reads a 0 as "stop": the Cheney drain would stop forwarding,
     * the major's survivor walk would stop marking (so live OLD objects would go
     * unmarked and be swept), and the atom mark would stop, freeing the bytes of
     * strings still in use. One un-sizeable object would become corruption
     * somewhere else entirely, so trap at the object. */
    if (type_index >= vader_type_info_count) {
        vader_trap("vader_gc: heap object with a type index past the info table");
    }
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    if (info->kind == VADER_TYPE_KIND_NONE) {
        vader_trap("vader_gc: heap object whose type has no info entry, the "
                   "emitter stamped a header the collector cannot size");
    }
    return info->size;
}

/* Place a copy of `obj` in `target` and return the new address. Updates the
 * source header's `forward` slot, clears the destination's so the freshly
 * copied object looks live (not yet forwarded) within this cycle. The
 * destination's age is overwritten by the caller to reflect promotion
 * semantics. Returns NULL if `target` doesn't have room: the caller is
 * expected to react (promotion overflow → escalate to major).
 *
 * Never leaves a filler ahead of an array buffer, unlike its allocation: the
 * copies then take no more room than the from-space held, which the size of the
 * to-space counts on. */
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

/* Copy a young object into the non-moving old gen and forward the original to
 * it. Returns NULL when the old reservation is at its cap: the caller decides
 * what that means. The caller also PUBLISHES the copy: a collection gray-pushes
 * it, an out-of-cycle tenure marks its card. */
static void* vader_gc_promote(void* obj, vader_obj_header_t* hdr, size_t bytes, uint8_t age) {
    void* dst = vader_old_alloc(bytes);
    if (dst == NULL) return NULL;
    memcpy(dst, obj, bytes);
    hdr->forward = dst;                              /* source forwards to promoted */
    vader_obj_header_t* dh = (vader_obj_header_t*) dst;
    dh->forward = NULL;                              /* the memcpy carried the source's */
    dh->age  = age;
    dh->mark = g_mark_value;                         /* live in the current old epoch */
    return dst;
}

/* Move a young object a minor has not moved yet: promote it or copy it into
 * young.to. Out of line, so the checks of `vader_gc_forward` that send most
 * referents back unchanged need no stack frame. */
static VADER_NOINLINE void* vader_gc_evacuate(void* obj, vader_obj_header_t* hdr, uint32_t type_index) {
    size_t bytes = vader_gc_obj_size(obj, type_index);
    if (bytes == 0) return obj;

    /* Promote into the slab old gen once the object has earned its tenure, or is
     * a shared buffer the first callback escape needs still. If the
     * old reservation is exhausted, fall back to surviving another cycle in
     * young.to: the retry path in vader_gc_alloc escalates to a major (whose
     * sweep frees old room) and traps only at the true cap. */
    if (hdr->age + 1u >= VADER_TENURE_AGE
        || (VADER_UNLIKELY(g_minor_promote_shared) && type_index == VADER_TYPE_INDEX_ARRAY_BUF
            && vader_array_buf_is_shared((vader_array_buf_t*) obj))) {
        void* dst = vader_gc_promote(obj, hdr, bytes, (uint8_t)(hdr->age + 1u));
        if (dst != NULL) {
            g_total_copied += bytes;
            vader_gray_push((char*) dst);                /* scan its slots for young refs */
            return dst;
        }
        /* else: old full, keep in young.to this cycle. */
    }

    void* dst = vader_gc_copy_into(obj, bytes, &g_young.to);
    if (dst == NULL) vader_trap("vader_gc: young to-space overflow during minor");
    ((vader_obj_header_t*) dst)->age = (uint8_t)(hdr->age + 1u);
    return dst;
}

/* Forward-process `obj` (typed by `type_index`) following `g_cycle`:
 *
 *   minor or major-drain : young objects promote into the slab old gen via
 *     `vader_old_alloc` once their age reaches tenure, and move to young.to
 *     otherwise; old objects are stable (non-moving) and returned unchanged.
 *   major : the mark phase. An old object is MARKED (mark = g_mark_value) and
 *     enqueued on the gray worklist (so its children get scanned); it does not
 *     move, so the slot value is returned unchanged.
 *
 * Pointers outside any GC arena are immortal: static compile-time data
 * (lookup tables, interned constants) lives in the C data segment and is never
 * copied or marked (it carries no refs into the arena, so it's a trace
 * dead-end). The C-emit may emit such tables for fns matching the
 * `match enum -> StructLit constant` pattern.
 * Constraint: a static object MUST NOT contain any pointer to a dynamic
 * (arena-allocated) object: the trace never visits it, so any inner dynamic
 * ref would be missed and freed under your feet. */
static inline void* vader_gc_forward(void* obj, uint32_t type_index) {
    if (obj == NULL) return NULL;
    if (VADER_UNLIKELY(g_gc_check_box)) vader_gc_check_object_alignment(obj, type_index);

    if (g_cycle == VADER_CYCLE_MAJOR) {
        /* Mark phase: only old objects are sweepable. Young survivors and
         * immortals are dead-ends here (young is kept whole during the old
         * pass; immortals are read-only, never write a mark to them). */
        if (!vader_in_old(obj)) return obj;
        vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
        if (hdr->mark == g_mark_value) return obj;      /* already marked */
        hdr->mark = g_mark_value;
        vader_gray_push((char*) obj);
        return obj;
    }

    /* An old object does not move during a minor, and an immortal never does. */
    if (!vader_in_young_from(obj)) return obj;

    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    if (hdr->forward != NULL) return hdr->forward;
    return vader_gc_evacuate(obj, hdr, type_index);
}

/* Scan a `vader_box_t` slot: if the tag identifies a heap-allocated kind and
 * the payload holds a pointer, forward it and update the slot in place.
 *
 * If `boxp` lives in an old-gen object (`VADER_WRITE_BARRIER` tests it) and the
 * forwarded ref ends up in young, mark the card dirty: future minors must
 * rescan this slot, and neither the original `array_push` write barrier (fired
 * on user mutation, not on this Cheney write) nor scan_old_dirty_cards covers
 * it. */
static void vader_gc_scan_box(vader_box_t* boxp) {
    if (boxp == NULL) return;
    if (boxp->tag == VADER_TYPE_INDEX_BUFFER) {
        /* Buffer box : the sentinel tag has no type-info row, so the generic
         * `>= count` skip below would treat it as a primitive and never
         * forward the referent: a moving collection would then leave the box
         * pointing at the stale (reclaimed) location. Forward via the
         * sentinel (sizes off the header) and apply the same old->young card
         * barrier as the ordinary ref path. A buffer holds no inner refs, so
         * there is nothing further to scan. */
        boxp->payload.obj = vader_gc_forward(boxp->payload.obj, VADER_TYPE_INDEX_BUFFER);
        if (vader_in_young(boxp->payload.obj)) {
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
    boxp->payload.obj = vader_gc_forward(boxp->payload.obj, boxp->tag);
    if (vader_in_young(boxp->payload.obj)) {
        VADER_WRITE_BARRIER(boxp);
    }
}

/* Scan a raw `void*` slot whose pointee is a heap object. Reads the pointee's
 * header to get its type, forwards, updates. Same write-barrier rule as
 * `vader_gc_scan_box`.
 *
 * Membership BEFORE the header read: a slot may hold a non-heap address (a
 * `.text` one in `fn.addr`), whose bytes are no header and must not be written
 * back as a forwarding pointer. An old object only matters to the major. */
static void vader_gc_scan_raw(void** slot) {
    if (slot == NULL || *slot == NULL) return;
    void* obj = *slot;
    if (vader_in_young_from(obj)) {
        void* moved = vader_gc_forward(obj, ((vader_obj_header_t*) obj)->type_index);
        *slot = moved;
        if (vader_in_young(moved)) {
            VADER_WRITE_BARRIER(slot);
        }
    } else if (g_cycle == VADER_CYCLE_MAJOR && vader_in_old(obj)) {
        (void) vader_gc_forward(obj, ((vader_obj_header_t*) obj)->type_index);
    }
}

/* TRAPS on a type index past the info table. A `VADER_TYPE_KIND_NONE` entry
 * still yields 0, and the `step == 0` guards at the call sites stop the walk on
 * it: the one silent-stop path left, and the one `vader_gc_obj_size` traps on.
 *
 * Scan one heap object's pointer-bearing slots and forward whatever they
 * reference. Returns the byte length of the object so a Cheney scan can
 * advance its cursor. */
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
            /* 8-byte raw-ref slots: forward each via scan_raw (handles
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
        vader_gc_scan_box((vader_box_t*) (scan + info->ptr_offsets[i]));
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
        // Raw-ref roots: `void*` locals carrying a concrete ref unboxed. NULL /
        // 0 in a frame with none.
        if (fr->raw != NULL) {
            for (uint32_t i = 0; i < fr->nraw; i++) {
                vader_gc_scan_raw(fr->raw[i]);
            }
        }
        // Stack-object roots: GC structs the escape analysis stack-allocated.
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
    /* Defer-stack: every entry's `payload.obj` is a vader_fn_t* whose env
     * captures heap-promoted cells. Without rooting here, a GC between
     * defer.push and defer.pop_exec would collect the captures. */
    for (size_t i = 0; i < g_defer_len; i++) {
        vader_gc_scan_box(&g_defer_stack[i]);
    }
}

/* The first card in [c, hi] marked in `dirty`, or hi + 1. Steps over clean
 * cards eight at a time: most of the old generation is clean at every minor. */
static inline size_t vader_next_dirty_card(const uint8_t* dirty, size_t c, size_t hi) {
    while (c + 8u <= hi + 1u) {
        uint64_t word;
        memcpy(&word, dirty + c, sizeof word);
        if (word != 0u) break;
        c += 8u;
    }
    while (c <= hi && dirty[c] == 0u) c++;
    return c;
}

/* Forward every old→young pointer, then leave the card table holding EXACTLY
 * the cards whose old objects still point young: the second half of the
 * standard generational card protocol (HotSpot Serial/Parallel, .NET CoreCLR,
 * GC Handbook): the write barrier MARKS, the minor CLEANS + REDIRTIES.
 *
 * Snapshot the live dirty set into `g_card_shadow`, clear the live table, and
 * card-drive the scan: per region, skip clean (snapshot) cards without touching
 * their slots, and scan only the live objects under dirty cards. Forwarding a
 * slot that still references young re-dirties its LIVE card via the barrier in
 * `vader_gc_scan_box`/`_raw`; a slot whose referent tenured to old leaves its
 * card clean. So after the scan a card is dirty iff a live old object in it
 * still holds a young pointer: the dirty set collapses to the true old→young
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
 * dirty snapshot card: none is missed. (VADER_GC_SCAN_ALL_OLD keeps every card
 * dirty and skips the clear: the missing-barrier A/B probe scans all of old.) */
static void vader_gc_scan_old_dirty_cards(void) {
    if (g_old_regions == NULL || g_old_bump == g_old_block) return;
    size_t used_cards = vader_old_used_cards();

    /* Snapshot, then clear. Clearing here is safe because the only forwarding
     * done earlier in the minor (vader_gc_scan_roots) touches off-heap root /
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
            if (dirty != NULL) {                        /* clean cards: skip their slots wholesale */
                c = vader_next_dirty_card(dirty, c, card_hi);
                if (c > card_hi) break;
            }

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

    /* Drain young.to and the gray worklist until neither advances: forwarding a
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

    /* The halves swap only when to-space received survivors; otherwise
     * from-space is reused from its base, and the next allocation lands on what
     * the minor abandoned. So a forwarding header does not outlive the minor
     * that wrote it: a pointer read after a collection must come from a root the
     * collection rewrote, never from a forward (docs/adr/0107). */
    vader_arena_t abandoned = g_young.from;
    if (g_young.to.cur != g_young.to.base) {
        g_young.from   = g_young.to;
        g_young.to     = abandoned;
        g_young.to.cur = g_young.to.base;
    } else {
        g_young.from.cur = g_young.from.base;
    }
    vader_alloc_limit_refresh();
    if (VADER_UNLIKELY(g_gc_poison)) {
        memset(abandoned.base, VADER_GC_POISON_BYTE, (size_t)(abandoned.cur - abandoned.base));
    }

    /* A preliminary minor inside a major counts as part of that major. */
    if (saved == VADER_CYCLE_NONE) g_total_collections++;
    g_cycle = saved;

    /* Atoms are collected by the MAJOR cycle only (`vader_atom_gc_collect`, called
     * from `vader_major_collect`): a minor never touches them. A string is a
     * `u32` atom id, plain data to the GC, which the conservative scan
     * ignores. */
}

void vader_major_collect(void) {
    if (!g_gc_initialized) return;

    /* 1. Drain young (a minor). Survivors that earned tenure promote into the
     * slab via vader_old_alloc; the rest, and any the slab cannot take, stay in
     * young.from. */
    g_cycle = VADER_CYCLE_MAJOR_DRAIN;
    vader_minor_collect();

    /* 2. Toggle the epoch mark value. Last epoch's live objects carry the old
     * value, so they now read as "unmarked" with no clear pass; the mark phase
     * re-marks every reachable old object to the new value. (Objects promoted in
     * step 1 carry the pre-toggle value and are likewise re-marked below.) */
    g_mark_value = (g_mark_value == 1u) ? 2u : 1u;

    /* 3. Mark. Old objects don't move: vader_gc_forward sets the mark bit and
     * pushes to the gray worklist instead of copying. Seed from roots + every
     * young survivor (kept whole during the old pass; scanning them marks the
     * old objects they reference), then drain the gray worklist for the
     * transitive old→old closure. */
    g_cycle = VADER_CYCLE_MAJOR;
    g_gray_len = 0;
    vader_gc_scan_roots();
    (void) vader_gc_drain(g_young.from.base, &g_young.from);
    /* Conservatively mark old objects reachable only from C locals / registers
     * (the shadow stack doesn't precisely root old refs, see the function).
     * `VADER_GC_NO_CSTACK_SCAN=1` skips it so the gaps in the PRECISE rooting
     * surface as failures instead of being papered over, see the flag. */
    if (!g_gc_no_cstack_scan) {
        vader_gc_mark_cstack_conservative();
    }
    while (g_gray_len > 0) {
        char* obj = g_gray_stack[--g_gray_len];
        (void) vader_gc_scan_object(obj);
    }

    /* 4. Sweep: rebuild every free list from the unmarked slots. */
    vader_old_sweep();
    g_old_live_after_major = g_old_live_bytes;   /* reclamation-trigger baseline */
    vader_gc_old_histogram();

    /* The card table stays as it is. Step 1's minor left a card dirty exactly
     * where an old object points young; the mark moves nothing, and its scans
     * re-dirty those cards anyway (`vader_gc_scan_box`/`_raw`). Dirtying more
     * would make the next minor rescan every live old object. */

    g_cycle = VADER_CYCLE_NONE;
    g_total_collections++;
    vader_atom_gc_collect();
}

/* Public alias. `runtime.collect()` in Vader maps here; tests rely on it
 * forcing a full collection (mark-sweep over old, not just minor). */
void vader_gc_collect(void) {
    vader_major_collect();
}

vader_gc_stats_t vader_gc_get_stats(void) {
    vader_gc_stats_t s;
    s.arena_size = g_old_capacity;
    if (g_gc_initialized) {
        /* Allocation high-water, NOT a live count, see `bytes_used`'s note in
         * vader.h for what the two halves mean and why they differ. */
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

/* From here on a lend may collect, so every shared buffer must be still: the
 * ones sliced before now are promoted, inside a collection that rewrites every
 * header of them. Invariant: vader.h, `VADER_ARRAY_RESOLVE_BUF`. */
void vader_ffi_callback_first_escape(void) {
    vader_ffi_callback_escaped = 1u;
    g_minor_promote_shared = 1u;
    vader_minor_collect();
    g_minor_promote_shared = 0u;
}

/* Force a young object into the NON-MOVING old generation so a pointer into it
 * survives a foreign call, leaving a forwarding pointer behind.
 *
 * NOT a pin: the object MOVES, outside any collection, so the caller must
 * rewrite every reference to it. For an array data buffer that is the one header
 * the caller holds: a buffer with a second header was sliced and marked shared
 * (`vader_array_slice`), and the lend leaves it alone. An object
 * Vader holds directly is NOT safe to move this way: the caller's own local
 * would keep addressing the evacuated copy until the next minor rewrote it, and
 * every write in between would be lost. Those root the pointer across the call
 * instead.
 *
 * Tenuring is permanent: the old generation is non-moving, so the object never
 * returns to young and only a major reclaims it. That is why the caller gates on
 * `vader_ffi_callback_escaped` rather than doing this on every lend.
 *
 * Returns the tenured address, or the original when the old generation is at its
 * cap: a lend that could not be secured, which is the pre-existing hazard and
 * not a new one. */
static void* vader_gc_force_tenure(void* obj) {
    if (!vader_in_young_from(obj)) return obj;   /* old or immortal: already still */
    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    if (hdr->forward != NULL) return hdr->forward;
    size_t bytes = vader_gc_obj_size(obj, hdr->type_index);
    if (bytes == 0) return obj;
    void* dst = vader_gc_promote(obj, hdr, bytes, VADER_TENURE_AGE);
    if (dst == NULL) return obj;
    /* No cycle is running to trace the copy, so mark its card: the next minor
     * scans it for old->young edges. The buffers this tenures today are
     * scalar-element (`vader_array_bytes` traps on BOXED and REF above), so it
     * finds none: the mark is what keeps the helper correct for a caller that
     * tenures something with reference slots. */
    VADER_WRITE_BARRIER(dst);
    return dst;
}
