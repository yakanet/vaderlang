/* rt/gc_collect.c: the collections: a minor copies young and promotes its
 * survivors, a major marks and sweeps old.
 *
 * Forwarding, scanning, the card table, the roots (shadow stack, defer stack,
 * C stack), and the tenure that moves a young object out of a minor's reach
 * before C holds its address. */

#include "internal.h"

/* Old-gen mark bit value for the CURRENT epoch. Toggles 1<->2 each major so a
 * previous epoch's marks read as "unmarked" without a clear pass; a FREE slot
 * carries 0 (never equal to g_mark_value). `vader_gc_promote` stamps it on a
 * promoted object. */
static uint8_t g_mark_value = 1u;

/* Set the first time a Vader function's ADDRESS is handed to C (`fn.addr`).
 * Until then no foreign callee can re-enter Vader, so no foreign call is a
 * safepoint and nothing lent to one can move. It never clears: once C holds the
 * address it may call it at any later point, through any other function. */
uint8_t vader_ffi_callback_escaped = 0u;

/* Set for the one minor `vader_ffi_callback_first_escape` runs: a shared array
 * buffer is promoted, whatever its age. */
static uint8_t g_minor_promote_shared = 0u;

/* The old-gen reservation the card tables cover, one byte per VADER_CARD_BYTES
 * in each worker's table (`vader_worker_t.cards`). The old gen is non-moving,
 * so a table is sized once over the whole reservation and never relocated.
 * Exposed (non-static) because the inline `VADER_WRITE_BARRIER` macro reads
 * the bounds from emitted C code. */
uintptr_t  vader_old_base   = 0;
uintptr_t  vader_old_end    = 0;
static size_t g_card_count = 0;

/* Cards spanning the carved old prefix [g_old_block, g_old_bump): the live part
 * of the table. The minor scan bounds its table sweep to this (the uncommitted
 * reservation tail holds no objects). */
static inline size_t vader_old_used_cards(void) {
    char* bump = __atomic_load_n(&g_old_bump, __ATOMIC_RELAXED);
    return ((size_t)(bump - g_old_block) + VADER_CARD_BYTES - 1u) / VADER_CARD_BYTES;
}

/* Grow the gray worklist geometrically. Out of line, so that the push it serves
 * costs no stack frame in the collector's loops. */
static VADER_NOINLINE void vader_gray_grow(vader_worker_t* w) {
    size_t new_cap = w->gray_cap == 0u ? 4096u : w->gray_cap * 2u;
    char** ns = (char**) realloc(w->gray_stack, new_cap * sizeof(char*));
    if (ns == NULL) vader_trap("vader_gray_push: realloc failed");
    w->gray_stack = ns;
    w->gray_cap   = new_cap;
}

/* A worker's gray worklist holds the objects whose slots a collection it runs
 * still has to scan: a minor pushes freshly-promoted old objects (to forward
 * their young refs); a major pushes freshly-marked old objects (to mark their
 * children). */
static inline void vader_gray_push(vader_worker_t* w, char* obj) {
    if (VADER_UNLIKELY(w->gray_len == w->gray_cap)) vader_gray_grow(w);
    w->gray_stack[w->gray_len++] = obj;
}

/* The pop of `vader_gray_push`: false once the worklist is empty. */
static inline bool vader_gray_pop(vader_worker_t* w, char** obj) {
    if (w->gray_len == 0u) return false;
    *obj = w->gray_stack[--w->gray_len];
    return true;
}

/* Mark dirty, in `w`'s card table, the card of `slot` when it lies in old and
 * points into `w`'s young generation after forwarding. Not in the mark of a
 * major: the minor that drained young left every card exact, and a young
 * referent there may be another worker's, whose card table is its own. */
static inline void vader_gc_dirty_card(vader_worker_t* w, const void* slot) {
    if (w->cycle == VADER_CYCLE_MAJOR) return;
    VADER_CARD_MARK(w->cards, slot);
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
 * conservatively: flush callee-saved registers (setjmp), then walk the C stacks
 * of every worker and of every thread that waits (`vader_gc_each_stack`)
 * word-by-word and MARK every old object any word points at (interior pointers
 * map to their slot). Old objects never move, so a false positive merely
 * retains a dead object: no pinning, no correctness risk. Found objects are
 * gray-pushed so their closure is marked too.
 *
 * Young is deliberately NOT scanned conservatively: its rooting is already
 * precise (minors require it) and young objects MOVE, which a conservative
 * (maybe-not-a-pointer) root cannot tolerate. */
static void vader_gc_mark_stack_range(vader_worker_t* w, char* lo, char* base) {
    if (lo == NULL || base == NULL || lo >= base) return;
    /* Align down to a pointer boundary, then scan word-aligned slots. */
    lo = (char*) ((uintptr_t) lo & ~(uintptr_t)(sizeof(void*) - 1u));
    for (char* p = lo; p + sizeof(void*) <= base; p += sizeof(void*)) {
        void* word = *(void* volatile*) p;
        if ((char*) word < g_old_block || (char*) word >= g_old_bump) continue;
        char* slot = vader_old_slot_of(word);
        if (slot == NULL) continue;
        vader_obj_header_t* h = (vader_obj_header_t*) slot;
        if (h->mark != g_mark_value && h->type_index != VADER_TYPE_INDEX_FREE) {
            h->mark = g_mark_value;
            vader_gray_push(w, slot);
        }
    }
}

/* What `vader_gc_each_stack` calls back, with the range of one stack. */
typedef struct {
    void (*fn)(char* lo, char* hi, void* ctx);
    void* ctx;
} vader_gc_stack_visit_t;

/* A thread that is not running: its switch stored its registers at `sp`. */
static void vader_gc_visit_waiting_stack(const vader_virtual_thread_roots_t* r, void* raw) {
    const vader_gc_stack_visit_t* visit = (const vader_gc_stack_visit_t*) raw;
    visit->fn(r->sp, r->hi, visit->ctx);
}

static VADER_NOINLINE void vader_gc_each_stack(void (*fn)(char* lo, char* hi, void* ctx), void* ctx) {
    jmp_buf regs;
    VADER_SPILL_REGISTERS(regs);
    vader_gc_stack_visit_t visit = { fn, ctx };
    for (size_t i = 0; i < g_worker_count; i++) {
        vader_worker_t* x = g_workers[i];
        /* The collector's own stack from its spilled registers up; another
         * worker's from where it stopped. */
        char* lo = x->stop_sp;
        if (x == &vader_worker) lo = (char*) &regs;
        fn(lo, vader_virtual_thread_stack_top(x), ctx);
        vader_virtual_thread_each_waiting(x, vader_gc_visit_waiting_stack, &visit);
    }
}

static void vader_gc_mark_range(char* lo, char* hi, void* w) {
    vader_gc_mark_stack_range((vader_worker_t*) w, lo, hi);
}

/* What `vader_gc_each_root_thread` calls back, with the roots of one thread. */
typedef struct {
    void (*fn)(vader_gc_frame_t* top, vader_box_t* defers, size_t ndefers, void* ctx);
    void* ctx;
} vader_gc_root_visit_t;

static void vader_gc_visit_waiting_roots(const vader_virtual_thread_roots_t* r, void* raw) {
    const vader_gc_root_visit_t* visit = (const vader_gc_root_visit_t*) raw;
    visit->fn(r->top, r->defers, r->ndefers, visit->ctx);
}

static void vader_gc_each_root_thread(const vader_worker_t* x,
                                      void (*fn)(vader_gc_frame_t* top, vader_box_t* defers,
                                                 size_t ndefers, void* ctx),
                                      void* ctx) {
    const vader_thread_state_t* running = &x->running;
    fn(running->gc_top, running->defer_stack, running->defer_len, ctx);
    vader_gc_root_visit_t visit = { fn, ctx };
    vader_virtual_thread_each_waiting(x, vader_gc_visit_waiting_roots, &visit);
}

/* ---- generational GC: copying young, mark-sweep old ---------------------- */

/* Size of a heap object, in bytes. For variable-length buffers (ARRAY_BUF
 * sentinel) the size is read off the object itself; for everything else the
 * type info table provides a static size. TRAPS on a non-heap kind or an
 * out-of-range index, so it never returns 0: the `bytes == 0` guards at the
 * call sites are unreachable and kept only as defence. */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index) {
    /* The two kinds below keep their size in the word a forward takes: read it
     * on the copy, which has the same. A struct's is in the table. */
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        void* copy = vader_obj_forwarded_to(obj);
        vader_array_buf_t* buf = (vader_array_buf_t*) (copy != NULL ? copy : obj);
        return sizeof(vader_array_buf_t) + buf->capacity * vader_array_element_size(buf->element_kind);
    }
    if (type_index == VADER_TYPE_INDEX_BUFFER) {
        void* copy = vader_obj_forwarded_to(obj);
        vader_buffer_t* b = (vader_buffer_t*) (copy != NULL ? copy : obj);
        return sizeof(vader_buffer_t) + b->byte_count;
    }
    /* A heap object the GC cannot size is a CODEGEN bug: the emitter stamped a
     * header with a type index carrying no `vader_type_info` entry (the table
     * covers Struct / Fn / Array only, so an erased `ref` gets none).
     *
     * A 0 would carry the damage away from the object: the minor would leave
     * it unmoved in the from-space it abandons, and the young walk would stop
     * there, so the atom mark would free the bytes of strings still in use.
     * Trap at the object instead. */
    if (type_index >= vader_type_info_count) {
        vader_trap("vader_gc: heap object with a type index past the info table");
    }
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    if (info->kind == VADER_TYPE_KIND_NONE) {
        vader_trap("vader_gc: heap object whose type has no info entry, the "
                   "emitter stamped a header the collector cannot size");
    }
    return vader_obj_bytes(info->size);
}

/* Place a copy of `obj` in `target` and return the new address, then forward
 * the source to it: the copy is made first, so it does not carry the flag. The
 * caller sets the destination's age. Returns NULL if `target` doesn't have room.
 *
 * Never leaves a filler ahead of an array buffer, unlike its allocation: the
 * copies then take no more room than the from-space held, which the size of the
 * to-space counts on. */
static void* vader_gc_copy_into(vader_worker_t* w, void* obj, size_t bytes, vader_arena_t* target) {
    size_t aligned = vader_gc_align(bytes);
    if (target->cur + aligned > target->end) return NULL;
    void* dst = target->cur;
    target->cur += aligned;
    memcpy(dst, obj, bytes);
    w->counts.copied += bytes;
    vader_obj_forward_to(obj, dst);
    return dst;
}

/* Copy a young object into the non-moving old gen and forward the original to
 * it. Returns NULL when the old reservation is at its cap: the caller decides
 * what that means. The caller also PUBLISHES the copy: a collection gray-pushes
 * it, an out-of-cycle tenure marks its card. */
static void* vader_gc_promote(void* obj, size_t bytes, uint8_t age) {
    void* dst = vader_old_alloc(bytes);
    if (dst == NULL) return NULL;
    memcpy(dst, obj, bytes);
    vader_obj_forward_to(obj, dst);
    vader_obj_header_t* dh = (vader_obj_header_t*) dst;
    dh->age  = age;
    vader_obj_publish_mark(dh);                      /* live in the current old epoch */
    return dst;
}

/* Move a young object a minor has not moved yet: promote it or copy it into
 * young.to. Out of line, so the checks of `vader_gc_forward` that send most
 * referents back unchanged need no stack frame. */
static VADER_NOINLINE void* vader_gc_evacuate(vader_worker_t* w, void* obj, vader_obj_header_t* hdr, uint32_t type_index) {
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
        void* dst = vader_gc_promote(obj, bytes, (uint8_t)(hdr->age + 1u));
        if (dst != NULL) {
            w->counts.copied += bytes;
            vader_gray_push(w, (char*) dst);                /* scan its slots for young refs */
            return dst;
        }
        /* else: old full, keep in young.to this cycle. */
    }

    void* dst = vader_gc_copy_into(w, obj, bytes, &w->young.to);
    if (dst == NULL) vader_trap("vader_gc: young to-space overflow during minor");
    ((vader_obj_header_t*) dst)->age = (uint8_t)(hdr->age + 1u);
    return dst;
}

/* Forward-process `obj` (typed by `type_index`) following `w->cycle`:
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
 * dead-end). The C emitter places the comptime data pool there.
 * Constraint: a static object MUST NOT contain any pointer to a dynamic
 * (arena-allocated) object: the trace never visits it, so any inner dynamic
 * ref would be missed and freed under your feet. */
static inline void* vader_gc_forward(vader_worker_t* w, void* obj, uint32_t type_index) {
    if (obj == NULL) return NULL;
    if (VADER_UNLIKELY(g_gc_check_box)) vader_gc_check_object_alignment(obj, type_index);

    if (w->cycle >= VADER_CYCLE_MAJOR) {
        if (VADER_UNLIKELY(w->cycle == VADER_CYCLE_VERIFY)) {
            vader_gc_verify_reach(w, obj);
            return obj;
        }
        /* Mark phase: only old objects are sweepable. Young survivors and
         * immortals are dead-ends here (young is kept whole during the old
         * pass; immortals are read-only, never write a mark to them). */
        if (!vader_in_old(obj)) return obj;
        vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
        if (hdr->mark == g_mark_value) return obj;      /* already marked */
        hdr->mark = g_mark_value;
        vader_gray_push(w, (char*) obj);
        return obj;
    }

    /* An old object does not move during a minor, and an immortal never does. */
    if (!vader_in_young_from(w, obj)) return obj;

    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    void* copy = vader_obj_forwarded_to(obj);
    if (copy != NULL) return copy;
    return vader_gc_evacuate(w, obj, hdr, type_index);
}

/* Forward the referent of `boxp`, of type `type_index`, and write the slot back
 * only when the referent moved. A minor scans the dirty cards of its worker
 * while another worker, holding the monitor, may store into the same shared old
 * object: writing back the value read would undo that store. */
static void vader_gc_forward_box(vader_worker_t* w, vader_box_t* boxp, uint32_t type_index) {
    void* obj = boxp->payload.obj;
    void* moved = vader_gc_forward(w, obj, type_index);
    if (moved != obj) boxp->payload.obj = moved;
    if (vader_in_young(w, moved)) vader_gc_dirty_card(w, boxp);
}

/* Scan a `vader_box_t` slot: if the tag identifies a heap-allocated kind and
 * the payload holds a pointer, forward it and update the slot in place.
 *
 * If `boxp` lives in an old-gen object and the forwarded ref ends up in young,
 * mark its card dirty in `w`'s table: future minors must rescan this slot, and
 * neither the mutator's write barrier (fired on a store, not on this Cheney
 * write) nor scan_old_dirty_cards covers it. */
static void vader_gc_scan_box(vader_worker_t* w, vader_box_t* boxp) {
    if (boxp == NULL) return;
    if (boxp->tag == VADER_TYPE_INDEX_BUFFER) {
        /* Buffer box : the sentinel tag has no type-info row, so the generic
         * `>= count` skip below would treat it as a primitive and never
         * forward the referent: a moving collection would then leave the box
         * pointing at the stale (reclaimed) location. Forward via the
         * sentinel (sizes off the header) and apply the same old->young card
         * barrier as the ordinary ref path. A buffer holds no inner refs, so
         * there is nothing further to scan. */
        vader_gc_forward_box(w, boxp, VADER_TYPE_INDEX_BUFFER);
        return;
    }
    if (boxp->tag >= vader_type_info_count) {
        if (VADER_UNLIKELY(g_gc_check_box)) vader_gc_box_tag_corrupt(boxp);
        return;
    }
    const vader_type_info_t* info = &vader_type_info_table[boxp->tag];
    if (info->kind == VADER_TYPE_KIND_NONE) return;
    vader_gc_forward_box(w, boxp, boxp->tag);
}

/* Scan a raw `void*` slot whose pointee is a heap object. Reads the pointee's
 * header to get its type, forwards, updates. Same write-barrier rule as
 * `vader_gc_scan_box`.
 *
 * Membership BEFORE the header read: a slot may hold a non-heap address (a
 * `.text` one in `fn.addr`), whose bytes are no header and must not be written
 * back as a forwarding pointer. An old object only matters to the major. */
static void vader_gc_scan_raw(vader_worker_t* w, void** slot) {
    if (slot == NULL || *slot == NULL) return;
    void* obj = *slot;
    if (VADER_UNLIKELY(w->cycle == VADER_CYCLE_VERIFY)) {
        vader_gc_verify_reach(w, obj);
    } else if (vader_in_young_from(w, obj)) {
        void* moved = vader_gc_forward(w, obj, ((vader_obj_header_t*) obj)->type_index);
        *slot = moved;
        if (vader_in_young(w, moved)) vader_gc_dirty_card(w, slot);
    } else if (w->cycle == VADER_CYCLE_MAJOR && vader_in_old(obj)) {
        (void) vader_gc_forward(w, obj, ((vader_obj_header_t*) obj)->type_index);
    }
}

/* TRAPS on a type index past the info table. A `VADER_TYPE_KIND_NONE` entry
 * still yields 0, and the `step == 0` guards at the call sites stop the walk on
 * it: the one silent-stop path left, and the one `vader_gc_obj_size` traps on.
 *
 * Scan one heap object's pointer-bearing slots and forward whatever they
 * reference. Returns the byte length of the object so a Cheney scan can
 * advance its cursor. */
static size_t vader_gc_scan_object(vader_worker_t* w, char* scan) {
    vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
    uint32_t type_index = hdr->type_index;
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) scan;
        size_t elem_size = vader_array_element_size(buf->element_kind);
        if (buf->element_kind == VADER_ARRAY_KIND_BOXED) {
            vader_box_t* slots = vader_array_box_slots(buf);
            for (size_t i = 0; i < buf->length; i++) {
                vader_gc_scan_box(w, &slots[i]);
            }
        } else if (buf->element_kind == VADER_ARRAY_KIND_REF) {
            /* 8-byte raw-ref slots: forward each via scan_raw (handles
             * NULL slots + the old->young write barrier). */
            void** slots = (void**) buf->slots;
            for (size_t i = 0; i < buf->length; i++) {
                vader_gc_scan_raw(w, &slots[i]);
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
        vader_gc_scan_box(w, (vader_box_t*) (scan + info->ptr_offsets[i]));
    }
    for (uint16_t i = 0; i < info->ref_count; i++) {
        vader_gc_scan_raw(w, (void**) (scan + info->ref_offsets[i]));
    }
    return vader_gc_align(vader_obj_bytes(info->size));
}

/* Forward every root cell of one thread: its shadow stack from `top`, then its
 * pending defers. */
static void vader_gc_scan_thread(vader_worker_t* w, vader_gc_frame_t* top, vader_box_t* defers, size_t ndefers) {
    for (vader_gc_frame_t* fr = top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs != NULL) {
            for (uint32_t i = 0; i < fr->nrefs; i++) {
                vader_gc_scan_box(w, fr->ptrs[i]);
            }
        }
        // Raw-ref roots: `void*` locals carrying a concrete ref unboxed. NULL /
        // 0 in a frame with none.
        if (fr->raw != NULL) {
            for (uint32_t i = 0; i < fr->nraw; i++) {
                vader_gc_scan_raw(w, fr->raw[i]);
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
                    (void) vader_gc_scan_object(w, (char*) fr->stack_objs[i]);
                }
            }
        }
    }
    /* Defer-stack: every entry's `payload.obj` is a vader_fn_t* whose env
     * captures heap-promoted cells. Without rooting here, a GC between
     * defer.push and defer.pop_exec would collect the captures. */
    for (size_t i = 0; i < ndefers; i++) {
        vader_gc_scan_box(w, &defers[i]);
    }
}

static void vader_gc_scan_root_thread(vader_gc_frame_t* top, vader_box_t* defers, size_t ndefers,
                                      void* w) {
    vader_gc_scan_thread((vader_worker_t*) w, top, defers, ndefers);
}

/* Walk the shadow stack of every thread of `x` and forward every root cell, as
 * the collection `w` runs: `x` itself for a minor, every worker for the mark
 * of a major. */
static void vader_gc_scan_roots(vader_worker_t* w, const vader_worker_t* x) {
    vader_gc_each_root_thread(x, vader_gc_scan_root_thread, w);
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

/* Forward every old->young pointer, then leave the card table holding EXACTLY
 * the cards whose old objects still point young: the write barrier MARKS, the
 * minor CLEANS + REDIRTIES.
 *
 * Snapshot the live dirty set into `w->card_shadow`, clear the live table, and
 * card-drive the scan: per region, skip clean (snapshot) cards without touching
 * their slots, and scan only the live objects under dirty cards. Forwarding a
 * slot that still references young re-dirties its LIVE card via the barrier in
 * `vader_gc_scan_box`/`_raw`; a slot whose referent tenured to old leaves its
 * card clean. So after the scan a card is dirty iff a live old object in it
 * still holds a young pointer.
 *
 * Snapshot-then-scan (rather than clear-as-you-go) is load-bearing: an object
 * can span two cards, and a redirty written while scanning the first card must
 * not be wiped when the second card is cleared. Reading the immutable snapshot
 * while only ever SETTING the live table removes that race; a per-region cursor
 * scans each spanning object at most once.
 *
 * Invariant: the mutator write barrier dirties a field's card on every
 * old->young store, so before the minor every live old->young field sits under
 * a dirty snapshot card: none is missed. `VADER_GC_SCAN_ALL_OLD` skips the
 * snapshot and the clear, and scans every card. */
static void vader_gc_scan_old_dirty_cards(vader_worker_t* w) {
    /* Other workers carve and fill old meanwhile, each region published whole
     * under the bump (`vader_old_carve_region`) and each object by its mark
     * (`vader_obj_publish_mark`): a slot read here is scanned only once its
     * mark says the object in it is written. */
    vader_old_region_t* regions = __atomic_load_n(&g_old_regions, __ATOMIC_ACQUIRE);
    if (regions == NULL) return;
    size_t used_cards = vader_old_used_cards();

    /* Snapshot, then clear. Clearing here is safe because the only forwarding
     * done earlier in the minor (vader_gc_scan_roots) touches off-heap root /
     * defer cells (outside the barrier's [old_base, old_end) guard), so it
     * cannot dirty a card the clear would wipe; every card-redirtying forward
     * (this scan + the gray drain that follows it) runs at or after this
     * clear. */
    const uint8_t* dirty = NULL;
    if (!g_gc_scan_all_old) {
        memcpy(w->card_shadow, w->cards, used_cards);
        memset(w->cards, 0, used_cards);
        dirty = w->card_shadow;                         /* what to scan; live table = redirty target */
    }

    for (vader_old_region_t* r = regions; r != NULL; r = r->next) {
        char* used_end = __atomic_load_n(&r->cur, __ATOMIC_RELAXED);
        if (used_end == r->base) continue;              /* nothing carved yet */
        uintptr_t rbase_off = (uintptr_t) r->base - vader_old_base;
        size_t    card_lo   = rbase_off / VADER_CARD_BYTES;
        size_t    card_hi   = ((uintptr_t) used_end - 1u - vader_old_base) / VADER_CARD_BYTES;
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
            for (; s < card_end && s < used_end; s += r->slot_size) {
                vader_obj_header_t* hdr = (vader_obj_header_t*) s;
                if (vader_obj_is_published(hdr)) (void) vader_gc_scan_object(w, s);
            }
            cursor = s;
        }
    }
}

/* Forward every pointer slot of every object in `[scan, arena->cur)`. Re-
 * reads `arena->cur` each iteration so objects appended by forwarding
 * during the scan are picked up before the loop ends. Returns the final
 * scan position. */
static char* vader_gc_drain(vader_worker_t* w, char* scan, const vader_arena_t* arena) {
    while (scan < arena->cur) {
        size_t step = vader_gc_scan_object(w, scan);
        if (step == 0) break;
        scan += step;
    }
    return scan;
}

static void vader_gc_minor(vader_worker_t* w) {
    if (!g_gc_initialized) return;
    vader_gen_t* young = &w->young;
    vader_cycle_t saved = w->cycle;
    if (saved == VADER_CYCLE_NONE) w->cycle = VADER_CYCLE_MINOR;
    /* MAJOR_DRAIN is preserved if the caller is `vader_major_collect`. */

    young->to.cur = young->to.base;
    char* young_scan = young->to.base;
    w->gray_len = 0;                                     /* promotions queue here */

    vader_gc_scan_roots(w, w);
    vader_gc_scan_old_dirty_cards(w);

    /* Drain young.to and the gray worklist until neither advances: forwarding a
     * young root can promote into the (scattered, non-contiguous) slab, and
     * scanning a promoted object can pull more young objects across, so the two
     * sources feed each other. Promoted objects can't be drained by a cursor
     * (they're spread across class regions), so they go through the gray stack. */
    for (;;) {
        char* y0 = young_scan;
        young_scan = vader_gc_drain(w, young_scan, &young->to);
        int drained_gray = 0;
        char* obj = NULL;
        while (vader_gray_pop(w, &obj)) {
            (void) vader_gc_scan_object(w, obj);         /* forward its young refs into young.to */
            drained_gray = 1;
        }
        if (young_scan == y0 && !drained_gray) break;
    }

    /* The halves swap only when to-space received survivors; otherwise
     * from-space is reused from its base, and the next allocation lands on what
     * the minor abandoned. So a forwarding header does not outlive the minor
     * that wrote it: a pointer read after a collection must come from a root the
     * collection rewrote, never from a forward (docs/adr/0107). */
    vader_arena_t abandoned = young->from;
    if (young->to.cur != young->to.base) {
        young->from   = young->to;
        young->to     = abandoned;
        young->to.cur = young->to.base;
    } else {
        young->from.cur = young->from.base;
    }
    vader_alloc_limit_refresh(w);
    if (VADER_UNLIKELY(g_gc_poison)) {
        memset(abandoned.base, VADER_GC_POISON_BYTE, (size_t)(abandoned.cur - abandoned.base));
    }

    /* A preliminary minor inside a major counts as part of that major. */
    if (saved == VADER_CYCLE_NONE) w->counts.collections++;
    w->cycle = saved;

    /* Atoms are collected by the MAJOR cycle only (`vader_atom_gc_collect`, called
     * from `vader_major_collect`): a minor never touches them. A string is a
     * `u32` atom id, plain data to the GC, which the conservative scan
     * ignores. */
}

void vader_minor_collect(void) {
    vader_gc_minor(&vader_worker);
}

/* ---- stopping the world -------------------------------------------------- */

/* With several workers, a major first stops every other one: at the slow path
 * of an allocation, or in a wait of the runtime (`vader_gc_blocking`). NULL
 * with one worker. */
static vader_os_lock_t* g_gc_stop_guard = NULL;
/* The collector waits on `stopped` for the others, which wait on `resumed`. */
static vader_os_cond_t* g_gc_stopped = NULL;
static vader_os_cond_t* g_gc_resumed = NULL;
static _Atomic int g_gc_stop_requested = 0;
/* The workers that count as stopped. */
static size_t g_gc_outside = 0;
/* The majors run so far: a worker that waited through another's needs none. */
static size_t g_gc_majors = 0;

static void vader_gc_pool_start(void) {
    vader_old_pool_start();
    g_gc_stop_guard = vader_os_lock_new();
    g_gc_stopped = vader_os_cond_new();
    g_gc_resumed = vader_os_cond_new();
}

static VADER_NOINLINE void vader_gc_blocking(void (*op)(void* arg), void* arg, vader_os_lock_t* held) {
    if (g_gc_stop_guard == NULL) {
        if (op != NULL) op(arg);
        return;
    }
    vader_worker_t* w = &vader_worker;
    jmp_buf regs;
    VADER_SPILL_REGISTERS(regs);
    vader_os_lock(g_gc_stop_guard);
    w->stop_sp = (char*) &regs;
    g_gc_outside++;
    if (atomic_load(&g_gc_stop_requested)) vader_os_cond_signal(g_gc_stopped);
    vader_os_unlock(g_gc_stop_guard);
    if (op != NULL) op(arg);
    vader_os_lock(g_gc_stop_guard);
    while (atomic_load(&g_gc_stop_requested)) {
        /* Never wait for a major holding `held`: a worker that waits to take it
         * would never stop. It is taken back before the guard, in the order
         * every other taker follows. */
        if (held != NULL) vader_os_unlock(held);
        while (atomic_load(&g_gc_stop_requested)) vader_os_cond_wait(g_gc_resumed, g_gc_stop_guard, -1);
        if (held == NULL) break;
        vader_os_unlock(g_gc_stop_guard);
        vader_os_lock(held);
        vader_os_lock(g_gc_stop_guard);
    }
    g_gc_outside--;
    w->stop_sp = NULL;
    vader_os_unlock(g_gc_stop_guard);
}

static void vader_gc_safepoint(vader_os_lock_t* held) {
    if (atomic_load_explicit(&g_gc_stop_requested, memory_order_relaxed)) {
        vader_gc_blocking(NULL, NULL, held);
    }
}

/* Stop every other worker; false, with none stopped, when another worker
 * collected while this one waited for it to finish, so that no major is due.
 * With one worker there is nothing to stop. */
static bool vader_gc_stop_world(void) {
    if (g_gc_stop_guard == NULL) return true;
    vader_os_lock(g_gc_stop_guard);
    size_t seen = g_gc_majors;
    while (atomic_load(&g_gc_stop_requested)) {
        vader_os_unlock(g_gc_stop_guard);
        vader_gc_safepoint(NULL);
        vader_os_lock(g_gc_stop_guard);
    }
    if (g_gc_majors != seen) {
        vader_os_unlock(g_gc_stop_guard);
        return false;
    }
    atomic_store(&g_gc_stop_requested, 1);
    /* A worker that allocates without leaving the inline path takes the slow
     * one, where it stops. */
    vader_alloc_limit_refresh_all();
    while (g_gc_outside + 1u < g_worker_count) {
        vader_os_cond_wait(g_gc_stopped, g_gc_stop_guard, -1);
    }
    vader_os_unlock(g_gc_stop_guard);
    return true;
}

static void vader_gc_resume_world(void) {
    if (g_gc_stop_guard == NULL) return;
    vader_os_lock(g_gc_stop_guard);
    g_gc_majors++;
    atomic_store(&g_gc_stop_requested, 0);
    vader_alloc_limit_refresh_all();
    vader_os_cond_broadcast(g_gc_resumed);
    vader_os_unlock(g_gc_stop_guard);
}

/* The roots of the threads no worker started yet: their entries, which a
 * worker that collects young never sees, since they are old. */
static void vader_gc_scan_unstarted(vader_worker_t* w) {
    vader_gc_root_visit_t visit = { vader_gc_scan_root_thread, w };
    vader_virtual_thread_each_unstarted(vader_gc_visit_waiting_roots, &visit);
}

/* ---- verification (VADER_GC_VERIFY) -------------------------------------- */

/* A walk of what one worker reaches, or the unstarted threads (`owner` NULL),
 * which any worker may adopt: the objects seen so far, in an open-addressing
 * set. The objects left to scan wait on the gray worklist of the collector. */
typedef struct {
    const vader_worker_t* owner;
    char**                seen;
    size_t                seen_len;
    size_t                seen_cap;
} vader_gc_verify_walk_t;

static vader_gc_verify_walk_t g_verify_walk;

/* The index of `x` among the workers, or the worker count for NULL. */
static size_t vader_gc_verify_worker_index(const vader_worker_t* x) {
    for (size_t i = 0; i < g_worker_count; i++) {
        if (g_workers[i] == x) return i;
    }
    return g_worker_count;
}

static VADER_NORETURN void vader_gc_verify_fail(const vader_worker_t* young_of, const void* obj) {
    fprintf(stderr, "VADER_GC_VERIFY: walk %zu (%zu: the unstarted threads) reaches %p, "
            "young in worker %zu\n", vader_gc_verify_worker_index(g_verify_walk.owner),
            g_worker_count, obj, vader_gc_verify_worker_index(young_of));
    vader_trap("VADER_GC_VERIFY: a worker reaches the young generation of another");
}

/* The home slot of `obj` in a set of `log2_cap` bits: the high bits of the
 * product, which every bit of the address reaches. */
static size_t vader_gc_verify_slot_of(const char* obj, unsigned log2_cap) {
    return (size_t) ((((uintptr_t) obj >> 4) * UINT64_C(0x9E3779B97F4A7C15)) >> (64u - log2_cap));
}

static unsigned vader_gc_verify_log2(size_t cap) {
    unsigned bits = 0u;
    while (((size_t) 1u << bits) < cap) bits++;
    return bits;
}

/* Add `obj` to the set: 1 when it was not in it. */
static int vader_gc_verify_first_visit(char* obj) {
    vader_gc_verify_walk_t* v = &g_verify_walk;
    if (2u * (v->seen_len + 1u) > v->seen_cap) {
        size_t cap = 1024u;
        if (v->seen_cap != 0u) cap = v->seen_cap * 2u;
        unsigned bits = vader_gc_verify_log2(cap);
        char** grown = (char**) calloc(cap, sizeof(char*));
        if (grown == NULL) vader_trap("VADER_GC_VERIFY: out of memory");
        for (size_t i = 0; i < v->seen_cap; i++) {
            char* o = v->seen[i];
            if (o == NULL) continue;
            size_t at = vader_gc_verify_slot_of(o, bits);
            while (grown[at] != NULL) at = (at + 1u) & (cap - 1u);
            grown[at] = o;
        }
        free(v->seen);
        v->seen = grown;
        v->seen_cap = cap;
    }
    size_t at = vader_gc_verify_slot_of(obj, vader_gc_verify_log2(v->seen_cap));
    while (v->seen[at] != NULL) {
        if (v->seen[at] == obj) return 0;
        at = (at + 1u) & (v->seen_cap - 1u);
    }
    v->seen[at] = obj;
    v->seen_len++;
    return 1;
}

/* What the walk does with each slot `w` reads: trap on the young generation of
 * another worker, and queue an old or own young object once. An immortal or
 * off-heap pointer ends the walk there. */
static void vader_gc_verify_reach(vader_worker_t* w, void* p) {
    if (p == NULL) return;
    if (!vader_in_old(p)) {
        int young = 0;
        for (size_t i = 0; i < g_worker_count && !young; i++) {
            const vader_worker_t* x = g_workers[i];
            if (!vader_in_young(x, p)) continue;
            if (x != g_verify_walk.owner) vader_gc_verify_fail(x, p);
            young = 1;
        }
        if (!young) return;
    }
    if (vader_gc_verify_first_visit((char*) p)) vader_gray_push(w, (char*) p);
}

/* Forget the objects seen by the walk before, for a walk of what `owner`
 * reaches. */
static void vader_gc_verify_begin(const vader_worker_t* owner) {
    vader_gc_verify_walk_t* v = &g_verify_walk;
    v->owner = owner;
    v->seen_len = 0u;
    if (v->seen != NULL) memset(v->seen, 0, v->seen_cap * sizeof(char*));
}

/* Scan everything the roots queued, and what it reaches in turn. */
static void vader_gc_verify_drain(vader_worker_t* w) {
    char* obj = NULL;
    while (vader_gray_pop(w, &obj)) (void) vader_gc_scan_object(w, obj);
}

/* What a worker reaches lies in no young generation of another, and the
 * unstarted threads reach none: what passes between workers is old, since
 * each door of std/task publishes it. Run by `w` with the world stopped, no
 * minor under way and its gray worklist empty. The conservative scan of the
 * C stacks is left out: a stale word there is no reference. */
static void vader_gc_verify_workers(vader_worker_t* w) {
    vader_cycle_t saved = w->cycle;
    w->cycle = VADER_CYCLE_VERIFY;
    for (size_t i = 0; i < g_worker_count; i++) {
        vader_gc_verify_begin(g_workers[i]);
        vader_gc_scan_roots(w, g_workers[i]);
        vader_gc_verify_drain(w);
    }
    vader_gc_verify_begin(NULL);
    vader_gc_scan_unstarted(w);
    vader_gc_verify_drain(w);
    w->cycle = saved;
}

/* ---- the major ----------------------------------------------------------- */

void vader_major_collect(void) {
    if (!g_gc_initialized) return;
    vader_worker_t* w = &vader_worker;
    if (!vader_gc_stop_world()) return;
    /* Before the drain: each young generation still holds all it made. */
    if (VADER_UNLIKELY(g_gc_verify)) vader_gc_verify_workers(w);

    /* 1. Drain every young generation (a minor each, with its own roots).
     * Survivors that earned tenure promote into the slab via vader_old_alloc;
     * the rest, and any the slab cannot take, stay in young.from. */
    for (size_t i = 0; i < g_worker_count; i++) {
        vader_worker_t* x = g_workers[i];
        x->cycle = VADER_CYCLE_MAJOR_DRAIN;
        vader_gc_minor(x);
        x->cycle = VADER_CYCLE_NONE;
    }

    /* 2. Toggle the epoch mark value. Last epoch's live objects carry the old
     * value, so they now read as "unmarked" with no clear pass; the mark phase
     * re-marks every reachable old object to the new value. (Objects promoted in
     * step 1 carry the pre-toggle value and are likewise re-marked below.) */
    g_mark_value = (g_mark_value == 1u) ? 2u : 1u;

    /* 3. Mark. Old objects don't move: vader_gc_forward sets the mark bit and
     * pushes to the gray worklist instead of copying. Seed from the roots of
     * every worker + every young survivor (kept whole during the old pass;
     * scanning them marks the old objects they reference), then drain the gray
     * worklist for the transitive old->old closure. */
    w->cycle = VADER_CYCLE_MAJOR;
    w->gray_len = 0;
    for (size_t i = 0; i < g_worker_count; i++) {
        vader_worker_t* x = g_workers[i];
        vader_gc_scan_roots(w, x);
        (void) vader_gc_drain(w, x->young.from.base, &x->young.from);
    }
    vader_gc_scan_unstarted(w);
    /* Conservatively mark old objects reachable only from C locals / registers
     * (the shadow stack doesn't precisely root old refs, see the function).
     * `VADER_GC_NO_CSTACK_SCAN=1` skips it so the gaps in the PRECISE rooting
     * surface as failures instead of being papered over, see the flag. */
    if (!g_gc_no_cstack_scan) {
        vader_gc_each_stack(vader_gc_mark_range, w);
    }
    char* gray = NULL;
    while (vader_gray_pop(w, &gray)) (void) vader_gc_scan_object(w, gray);

    /* 4. Sweep: rebuild every free list from the unmarked slots. What a worker
     * allocated under the monitor is marked now, or freed. */
    vader_old_sweep();
    for (size_t i = 0; i < g_worker_count; i++) g_workers[i]->monitor_born_len = 0u;
    g_old_live_after_major = g_old_live_bytes;   /* reclamation-trigger baseline */
    vader_gc_old_histogram();

    /* The card table stays as it is. Step 1's minor left a card dirty exactly
     * where an old object points young, and the mark moves nothing. Dirtying
     * more would make the next minor rescan every live old object. */

    w->cycle = VADER_CYCLE_NONE;
    w->counts.collections++;
    vader_atom_gc_collect();
    vader_gc_resume_world();
}

/* Public alias. `runtime.collect()` in Vader maps here; tests rely on it
 * forcing a full collection (mark-sweep over old, not just minor). */
void vader_gc_collect(void) {
    vader_major_collect();
}

vader_gc_stats_t vader_gc_get_stats(void) {
    vader_gc_stats_t s = {0};
    s.arena_size = g_old_capacity;
    /* Old live bytes plus each young generation's allocation high-water, NOT a
     * live count, see `bytes_used`'s note in vader.h for what the two halves
     * mean and why they differ. */
    s.bytes_used = g_old_live_bytes;
    for (size_t i = 0; i < g_worker_count; i++) {
        const vader_worker_t* w = g_workers[i];
        s.bytes_used += (size_t)(w->young.from.cur - w->young.from.base);
        s.total_collections += w->counts.collections;
        s.total_copied += w->counts.copied;
        s.total_alloc_bytes += w->counts.alloc_bytes;
        s.total_alloc_count += w->counts.alloc_count;
    }
    return s;
}

/* From here on a lend may collect, so every shared buffer must be still: the
 * ones sliced before now are promoted, inside a collection that rewrites every
 * header of them. Invariant: vader.h, `VADER_ARRAY_RESOLVE_BUF`. */
void vader_ffi_callback_first_escape(void) {
    vader_ffi_callback_escaped = 1u;
    g_minor_promote_shared = 1u;
    vader_gc_minor(&vader_worker);
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
 * cap: the object then stays movable. */
static void* vader_gc_force_tenure(void* obj) {
    if (!vader_in_young_from(&vader_worker, obj)) return obj;   /* old or immortal: already still */
    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    void* copy = vader_obj_forwarded_to(obj);
    if (copy != NULL) return copy;
    size_t bytes = vader_gc_obj_size(obj, hdr->type_index);
    if (bytes == 0) return obj;
    void* dst = vader_gc_promote(obj, bytes, VADER_TENURE_AGE);
    if (dst == NULL) return obj;
    /* No cycle is running to trace the copy, so mark its card: the next minor
     * scans it for old->young edges. */
    VADER_WRITE_BARRIER(dst);
    return dst;
}
