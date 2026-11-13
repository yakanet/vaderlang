/* rt/arrays.c: arrays: allocation, growth, slices, bulk copies, and the lend
 * of their bytes to C. */

#include "internal.h"

/* `sizeof(vader_array_buf_t) + capacity * element_size(kind)`, and the one
 * place that refuses a capacity an array header cannot say: every buffer an
 * array is created with or grows into is sized here. Under that bound the
 * product fits a `size_t`. */
static size_t vader_array_buf_bytes(size_t capacity, uint8_t element_kind) {
    if (capacity > VADER_ARRAY_MAX_LENGTH) {
        vader_trap("vader_array: more elements than an array holds");
    }
    return sizeof(vader_array_buf_t) + capacity * vader_array_element_size(element_kind);
}

/* Allocate a fresh array buffer of `capacity` slots with the ARRAY_BUF
 * sentinel as its type tag: the GC scan loop dispatches on that to walk
 * `length` slots dynamically. The struct itself plus its trailing slot
 * area land in a single GC arena allocation. */
static vader_array_buf_t* vader_array_buf_alloc(size_t capacity, uint8_t element_kind, uint32_t element_tag) {
    size_t bytes = vader_array_buf_bytes(capacity, element_kind);
    vader_array_buf_t* buf = (vader_array_buf_t*) vader_gc_alloc_slot_aligned(bytes);
    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity     = capacity;
    buf->length       = 0;
    buf->element_kind = element_kind;
    buf->element_tag  = element_tag;
    return buf;
}

/* Forward decl: the allocator taking an explicit length and capacity, defined
 * with the array construction ops further down. */
static vader_array_t* vader_array_alloc_cap(uint32_t type_index, size_t length, size_t capacity, uint8_t element_kind, uint32_t element_tag);

vader_array_t* vader_array_new(uint32_t type_index, size_t length, uint8_t element_kind, uint32_t element_tag) {
    /* `cap = length`, or 4 for an empty array. The single-block alloc + GC-orphan
     * rationale lives on `vader_array_alloc_cap`. */
    return vader_array_alloc_cap(type_index, length, length > 0 ? length : 4, element_kind, element_tag);
}

/* Store a primitive-kind slot: writes the matching primitive width directly
 * to `buf->slots` ; the boxed kind routes through `vader_array_box_slots`.
 * Emitted code open-codes its element accesses (typed slots inline, boxed via
 * `vader_array_box_slots`, u8 via `vader_array_read_u8`): this store serves the
 * runtime's own `push`, `push_all` and `copy`. */
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
        case VADER_ARRAY_KIND_REF:  ((void**)    base)[i] = vader_box_to_ref(v); return;
        default: vader_trap("vader_array_store_slot: unknown element kind");
    }
}

vader_array_t* vader_array_slice(vader_array_t* a, int64_t lo_bound, int64_t hi_bound) {
    a = vader_array_resolve(a);
    /* Clamp bounds against the header length (independent of `buf`, so it's
     * valid for both the owning, view, and borrowed cases). */
    size_t lo = vader_count_or_zero(lo_bound);
    size_t hi = vader_count_or_zero(hi_bound);
    if (lo > vader_array_length(a)) lo = vader_array_length(a);
    if (hi < lo)        hi = lo;
    if (hi > vader_array_length(a)) hi = vader_array_length(a);
    size_t len = hi - lo;
    vader_array_resolve_buf(a);
    /* Root the parent array across the alloc: a collection inside
     * `vader_gc_alloc` would forward it otherwise. */
    void** roots[1] = { (void**) &a };
    VADER_GC_PUSH_RAW(frame, roots, 1);
    vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
    VADER_GC_POP_FRAME(frame);
    vader_obj_header_init(view, a->header.type_index);
    view->offset = a->offset + lo;
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Another borrowed view over the same owner atom: `buf` stays NULL. */
        vader_array_make_borrowed(view, vader_array_borrowed_owner(a), len);
        view->buf = NULL;
        return view;
    }
    /* A second header now shares this buffer: mark it, and once a callback has
     * escaped, make it still. Only a young buffer can move. An immortal one
     * stays unmarked, since it may sit in read-only memory: the compiler copies
     * a constant before any code that could shrink it. Invariants: vader.h,
     * `vader_array_t` and `VADER_ARRAY_RESOLVE_BUF`. */
    int young = vader_in_young_from(a->buf);
    if (young && vader_ffi_callback_escaped) {
        a->buf = (vader_array_buf_t*) vader_gc_force_tenure(a->buf);
    }
    if (young || vader_in_old(a->buf)) {
        vader_array_buf_mark_shared(a->buf);
    }
    vader_array_set_extent(view, len, len);
    view->buf = a->buf;
    return view;
}

/* Follow any forwarding pointer on an array header a helper was handed, on
 * entry, before the helper can collect. It cannot recover a pointer held across
 * a collection (docs/adr/0107): a helper that collects roots its arrays on the
 * shadow stack, which the collection rewrites, and reads them back from there. */
static vader_array_t* vader_array_resolve(vader_array_t* a) {
    void* to;
    while ((to = vader_obj_forwarded_to(a)) != NULL) a = (vader_array_t*) to;
    return a;
}

/* Lend an array's raw bytes to a foreign callee, see the contract in vader.h. */
vader_slice_t vader_array_bytes(vader_array_t* a) {
    vader_slice_t s = { NULL, 0 };
    if (a == NULL) return s;
    a = vader_array_resolve(a);
    if (vader_array_length(a) == 0) return s;

    if (vader_array_is_borrowed(a)) {
        /* A borrowed view is always a BYTE view over an interned atom, so
         * `offset` and `length` are already byte quantities. */
        const uint8_t* src = (const uint8_t*) vader_atom_data(vader_array_borrowed_owner(a));
        s.ptr = src + a->offset;
        s.len = vader_array_length(a);
        return s;
    }

    vader_array_resolve_buf(a);
    if (a->buf == NULL) return s;
    if (a->buf->element_kind == VADER_ARRAY_KIND_BOXED
        || a->buf->element_kind == VADER_ARRAY_KIND_REF) {
        vader_trap("vader_array_bytes: array of refs cannot cross the C ABI");
    }
    /* C holds this pointer for the whole call. If a Vader function address has
     * ever crossed into C, any foreign call can re-enter and collect, so the
     * buffer has to stop moving. Rewriting `a->buf` is the whole move while `a`
     * is its only header; a shared buffer is never moved here (invariant:
     * vader.h, `VADER_ARRAY_RESOLVE_BUF`). Until a callback has escaped, no
     * callee can call back and the lend moves nothing. */
    if (vader_ffi_callback_escaped
        && !vader_array_buf_is_shared(a->buf)) {
        a->buf = (vader_array_buf_t*) vader_gc_force_tenure(a->buf);
    }
    size_t esz = vader_array_element_size(a->buf->element_kind);
    s.ptr = (const uint8_t*) a->buf->slots + a->offset * esz;
    s.len = vader_array_length(a) * esz;
    return s;
}

/* Out-of-line half of the runtime's buf resolve, see the contract
 * on the declaration in `vader.h`. The caller has already established that
 * `buf` is non-NULL and carries a live forward, so the first iteration always
 * advances; the loop then drains a chain longer than one link. */
VADER_PURE VADER_NOINLINE vader_array_buf_t* vader_array_buf_forward(vader_array_buf_t* buf) {
    void* to;
    while ((to = vader_obj_forwarded_to(buf)) != NULL) buf = (vader_array_buf_t*) to;
    return buf;
}

/* Give `a` a buffer of its own with room for `need` elements: its elements
 * copied to the front of a fresh buffer of twice its capacity, at least 4 and
 * at least `need`. Every append that finds no room comes here, which is also
 * where every view and every header that shrank over a shared buffer stands
 * (`vader_array_t`).
 *
 * `vader_array_buf_alloc` may collect, once or more (minor, then a major when
 * the minor doesn't free enough), and a forward does not outlive its collection
 * (docs/adr/0107). So `a` is boxed and rooted, `vader_gc_scan_box` re-updating
 * `a_box.payload.obj` through every cycle, and comes back reloaded; `keep` is
 * a box the caller still reads afterwards, rooted the same way. */
static vader_array_t* vader_array_detach(vader_array_t* a, size_t need, vader_box_t* keep) {
    uint8_t kind      = a->buf->element_kind;
    size_t  elem_size = vader_array_element_size(kind);
    vader_box_t a_box = vader_box_obj(a->header.type_index, a);
    vader_box_t* roots[2] = { &a_box, keep };
    vader_gc_frame_t frame = { vader_gc_top, 2u, 0u, roots };
    vader_gc_top = &frame;
    size_t cap = vader_array_capacity(a) == 0 ? 4 : vader_array_capacity(a) * 2;
    if (cap > VADER_ARRAY_MAX_LENGTH) cap = VADER_ARRAY_MAX_LENGTH;
    if (cap < need) cap = need;
    vader_array_buf_t* fresh = vader_array_buf_alloc(cap, kind, a->buf->element_tag);
    a = (vader_array_t*) a_box.payload.obj;
    vader_array_buf_t* old = a->buf;
    if (vader_obj_forwarded_to(old) != NULL) {
        old = vader_array_buf_forward(old);
    }
    if (vader_array_length(a) > 0) {
        memcpy(fresh->slots, old->slots + a->offset * elem_size, vader_array_length(a) * elem_size);
    }
    fresh->length = vader_array_length(a);
    a->buf      = fresh;
    vader_array_set_capacity(a, cap);
    a->offset   = 0;
    /* `a` may be old while `fresh` is young: mark the card holding `a`. */
    VADER_WRITE_BARRIER(a);
    vader_gc_top = frame.prev;
    return a;
}

void vader_array_push_slow(vader_array_t* a, vader_box_t v) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Defensive : T3072 refuses to modify a view of a string's bytes. */
        vader_trap("cannot push to a borrowed `const u8[]` byte view");
    }
    if (vader_array_length(a) >= vader_array_capacity(a)) {
        a = vader_array_detach(a, vader_array_length(a) + 1, &v);
    }
    size_t n = vader_array_length(a);
    vader_array_store_slot(a->buf, n, v);
    vader_array_bump_length(a);
    a->buf->length = n + 1;
    VADER_WRITE_BARRIER(a->buf);
}

/* The out-of-line half of `vader_array_push_ref`: the pointer goes in as the box
 * its header gives, through the general append. Never inlined: it is the cold
 * branch of every inline call site. */
VADER_NOINLINE void vader_array_push_ref_slow(vader_array_t* a, void* obj) {
    vader_array_push(a, vader_ref_box(obj));
}

/* Allocate an owning array with an explicit `length` AND `capacity`. The single
 * source of truth for array construction: `vader_array_new`,
 * `vader_array_reserve` and `vader_array_repeat` each pick the two.
 *
 * Single-block alloc: the struct is followed by an inline buf in the same GC
 * alloc. A two-step alloc has a window where one half is unreachable from the
 * shadow stack: a collection mid-construction would lose the orphan; the
 * combined block sidesteps it. (Push later allocates a *separate* fresh buf and
 * rebinds `a->buf`; the GC then relocates the two halves independently.)
 *
 * Slots `[0, length)` are left uninitialised: the caller fills them with no
 * intervening allocation (memcpy is not a safepoint), so the GC never scans a
 * garbage slot; `buf->length` is set to `length` so a BOXED tail beyond
 * `length` is never walked. */
static vader_array_t* vader_array_alloc_cap(uint32_t type_index, size_t length, size_t capacity, uint8_t element_kind, uint32_t element_tag) {
    if (capacity < length) capacity = length;
    size_t struct_bytes = vader_gc_align(sizeof(vader_array_t));
    size_t buf_bytes    = vader_array_buf_bytes(capacity, element_kind);
    char* block = (char*) vader_gc_alloc_slot_aligned(struct_bytes + buf_bytes);
    vader_array_t* a = (vader_array_t*) block;
    vader_array_buf_t* buf = (vader_array_buf_t*) (block + struct_bytes);
    vader_obj_header_init(a, type_index);
    vader_array_set_extent(a, length, capacity);
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
        tag  = vader_type_info_table[src->header.type_index].element_tag;
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

vader_array_t* vader_array_reserve(uint32_t type_index, int64_t n, uint8_t element_kind, uint32_t element_tag) {
    size_t cap = vader_count_or_zero(n);
    if (cap < 4) cap = 4;
    return vader_array_alloc_cap(type_index, 0, cap, element_kind, element_tag);
}

/* `src * n`: fresh array repeating `src`'s elements `n` times, `length =
 * src.length * n`. The result reuses `src`'s array type / element kind / tag.
 * For a ref element the SAME reference is repeated n times (shallow, evaluate-
 * once: the documented semantics). */
vader_array_t* vader_array_repeat(vader_array_t* src, int64_t times) {
    size_t n = vader_count_or_zero(times);
    src = vader_array_resolve(src);
    uint32_t type_index = src->header.type_index;
    size_t src_len = vader_array_length(src);
    if (src_len != 0 && n > VADER_ARRAY_MAX_LENGTH / src_len) {
        vader_trap("vader_array: more elements than an array holds");
    }
    size_t out_len = src_len * n;
    size_t cap = out_len;
    if (cap < 4) cap = 4;
    /* Read the element metadata before the alloc (it may relocate `src`). */
    uint8_t kind; uint32_t tag; size_t esz;
    vader_array_src_region(src, 0, &kind, &tag, &esz);
    /* Root `src` across the result allocation: a collection there forwards it. */
    vader_box_t src_box; src_box.tag = type_index; src_box._pad = 0; src_box.payload.obj = src;
    VADER_GC_PUSH1(src_box);
    vader_array_t* out = vader_array_alloc_cap(type_index, out_len, cap, kind, tag);
    VADER_GC_POP();
    src = (vader_array_t*) src_box.payload.obj;
    if (out_len == 0) return out;
    /* Recompute the source region after the possible relocation, then stamp the
     * src block into the result n times: once, then the filled prefix copied onto
     * the rest, doubling each time, so `[0] * 65536` is 17 copies. Each copy reads
     * a prefix the write never reaches. No safepoint between here and return. */
    const uint8_t* src_data = vader_array_src_region(src, 0, &kind, &tag, &esz);
    uint8_t* dst_data = out->buf->slots;
    size_t total = out_len * esz;
    size_t filled = src_len * esz;
    memcpy(dst_data, src_data, filled);
    while (filled <= total - filled) {
        memcpy(dst_data + filled, dst_data, filled);
        filled *= 2;
    }
    memcpy(dst_data + filled, dst_data, total - filled);
    if (kind == VADER_ARRAY_KIND_BOXED || kind == VADER_ARRAY_KIND_REF) {
        VADER_WRITE_BARRIER(out->buf);   /* coarse card covers the whole buf */
    }
    return out;
}

/* Load slot `i` of `buf` as a box: the symmetric read of
 * `vader_array_store_slot`. Access sites normally open-code their reads (see that
 * function's note), so this exists for the cases that cannot: copying between
 * two arrays whose element representations differ (`vader_array_src_slot`, from
 * `vader_array_push_all` and `vader_array_copy`), and the element
 * `vader_array_remove_last` hands back. */
static vader_box_t vader_array_load_slot(vader_array_buf_t* buf, size_t i) {
    uint32_t tag = buf->element_tag;
    uint8_t* base = buf->slots;
    vader_box_t out;
    out._pad = 0;
    switch (buf->element_kind) {
        case VADER_ARRAY_KIND_BOXED: out = vader_array_box_slots(buf)[i]; break;
        case VADER_ARRAY_KIND_U8:   out.tag = tag; out.payload.i = ((uint8_t*)  base)[i]; break;
        case VADER_ARRAY_KIND_U16:  out.tag = tag; out.payload.i = ((uint16_t*) base)[i]; break;
        case VADER_ARRAY_KIND_U32:  out.tag = tag; out.payload.i = ((uint32_t*) base)[i]; break;
        case VADER_ARRAY_KIND_U64:  out.tag = tag; out.payload.i = (vader_i64_t) ((uint64_t*) base)[i]; break;
        case VADER_ARRAY_KIND_I8:   out.tag = tag; out.payload.i = ((int8_t*)   base)[i]; break;
        case VADER_ARRAY_KIND_I16:  out.tag = tag; out.payload.i = ((int16_t*)  base)[i]; break;
        case VADER_ARRAY_KIND_I32:  out.tag = tag; out.payload.i = ((int32_t*)  base)[i]; break;
        case VADER_ARRAY_KIND_I64:  out.tag = tag; out.payload.i = ((int64_t*)  base)[i]; break;
        case VADER_ARRAY_KIND_F32:  out.tag = tag; out.payload.f = (vader_f64_t) ((float*) base)[i]; break;
        case VADER_ARRAY_KIND_F64:  out.tag = tag; out.payload.f = ((double*)   base)[i]; break;
        case VADER_ARRAY_KIND_CHAR: out.tag = tag; out.payload.i = ((uint32_t*) base)[i]; break;
        case VADER_ARRAY_KIND_BOOL: out.tag = tag; out.payload.b = ((uint8_t*)  base)[i] != 0; break;
        case VADER_ARRAY_KIND_REF:  out = vader_ref_box(((void**) base)[i]); break;
        default: vader_trap("vader_array_load_slot: unknown element kind");
    }
    return out;
}

/* One element of a COPY SOURCE, boxed, whatever shape that source has: a packed
 * buffer, a boxed one, or a BORROWED `const u8[]` view whose bytes live in the
 * atom table and whose `buf` is NULL.
 *
 * `vader_array_load_slot` reads `buf->element_kind` on entry, so it cannot serve
 * the borrowed case ; that one is read straight from the region pointer
 * `vader_array_src_region` handed back, which already folds in the offset.
 * `base` is the absolute element index of that region for every other shape.
 *
 * Allocates nothing, so a caller inside a no-safepoint window stays safe. */
static vader_box_t vader_array_src_slot(vader_array_t* src, const uint8_t* src_data,
                                        uint32_t stag, size_t base, size_t i) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(src))) {
        vader_box_t out;
        out._pad = 0;
        out.tag = stag;
        out.payload.i = src_data[i];      /* borrowed views are const u8[] */
        return out;
    }
    return vader_array_load_slot(src->buf, base + i);
}

/* `dst.push_all(src)`: append every element of `src` to `dst`, growing `dst`
 * once if needed (`vader_array_detach`, which keeps `src` rooted). Handles
 * `push_all(x, x)` : after a grow `src` reads the fresh buf whose head holds the
 * copied originals, and the append range never overlaps the source range. */
void vader_array_push_all(vader_array_t* dst, vader_array_t* src) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(dst))) {
        vader_trap("cannot push_all to a borrowed `const u8[]` byte view");
    }
    dst = vader_array_resolve(dst);
    src = vader_array_resolve(src);
    size_t add = vader_array_length(src);
    if (add == 0) return;
    size_t need = vader_array_length(dst) + add;
    if (need > vader_array_capacity(dst)) {
        vader_box_t s_box = vader_box_obj(src->header.type_index, src);
        dst = vader_array_detach(dst, need, &s_box);
        src = (vader_array_t*) s_box.payload.obj;
    }
    /* Append src[0..add) at dst[length..). Recompute the source region after any
     * relocation. No safepoint from here to return, so the pointers are stable. */
    uint8_t kind; uint32_t tag; size_t esz;
    const uint8_t* src_data = vader_array_src_region(src, 0, &kind, &tag, &esz);
    size_t base = vader_array_length(dst);
    if (kind == dst->buf->element_kind) {
        uint8_t* dst_data = dst->buf->slots + base * esz;
        memcpy(dst_data, src_data, add * esz);
    } else {
        /* The two arrays store their elements differently, so a memcpy would
         * write source-shaped slots at source-shaped strides into a buffer laid
         * out for the destination's: 16-byte `vader_box_t`s into 8-byte raw-ref
         * slots, say, overrunning the buffer and leaving the reader to treat
         * boxes as pointers. It happens for real: a module const materialises
         * BOXED while a freshly allocated array of the same element type is
         * KIND_REF, so `all.push_all(some_const)` meets both.
         *
         * Go through the boxed form instead, which is what the per-element `push`
         * path does. Neither helper allocates, so the no-safepoint contract above
         * still holds. */
        for (size_t i = 0; i < add; i++) {
            vader_box_t v = vader_array_src_slot(src, src_data, tag, src->offset, i);
            vader_array_store_slot(dst->buf, base + i, v);
        }
    }
    vader_array_set_length(dst, need);
    dst->buf->length = need;
    if (dst->buf->element_kind == VADER_ARRAY_KIND_BOXED ||
        dst->buf->element_kind == VADER_ARRAY_KIND_REF) {
        VADER_WRITE_BARRIER(dst->buf);
    }
}

/* `src.copy_to(src_start, dst, dst_start, len)`: positional, overlap-safe
 * (`memmove`) copy of `len` elements from `src[src_start..]` into an EXISTING
 * `dst[dst_start..]` region. `dst` must already be long enough (traps otherwise):
 * this overwrites, it does not grow. No allocation anywhere, hence no GC / no
 * rooting : the argument pointers are stable for the whole call. */
void vader_array_copy(vader_array_t* src, int64_t src_from, vader_array_t* dst, int64_t dst_from, int64_t count) {
    size_t src_start = vader_count_or_zero(src_from);
    size_t dst_start = vader_count_or_zero(dst_from);
    size_t len = vader_count_or_zero(count);
    if (len == 0) return;
    if (VADER_UNLIKELY(vader_array_is_borrowed(dst))) {
        vader_trap("cannot copy into a borrowed `const u8[]` byte view");
    }
    src = vader_array_resolve(src);
    dst = vader_array_resolve(dst);
    if (src_start > vader_array_length(src) || len > vader_array_length(src) - src_start) {
        vader_trap("vader_array_copy: source range out of bounds");
    }
    if (dst_start > vader_array_length(dst) || len > vader_array_length(dst) - dst_start) {
        vader_trap("vader_array_copy: destination range out of bounds (dst must already be long enough)");
    }
    vader_array_resolve_buf(dst);
    uint8_t  kind = dst->buf->element_kind;
    size_t   esz  = vader_array_element_size(kind);
    uint8_t  skind; uint32_t stag; size_t sesz;
    const uint8_t* src_data = vader_array_src_region(src, src_start, &skind, &stag, &sesz);
    if (skind == kind) {
        /* One layout on both sides, so the raw move is exact, and it is a
         * `memmove` because this is the one array op whose ranges may overlap
         * (`a.copy_to(0, a, 1, n)` shifts `n` elements of `a` up by one). */
        uint8_t* dst_data = dst->buf->slots + (dst->offset + dst_start) * esz;
        memmove(dst_data, src_data, len * esz);
    } else {
        /* Same divergence `vader_array_push_all` documents above, and the same
         * cure. Copying raw here would stride the SOURCE at the DESTINATION's
         * width : `esz` bytes read out of `sesz`-byte slots, so a BOXED source
         * into a REF destination writes box headers where pointers are expected
         * and the first reader dereferences a tag word, while a REF source into
         * a BOXED one reads twice the bytes its slots hold.
         *
         * Two different kinds mean two different buffers, so no overlap is
         * possible in this branch and a forward walk is enough. Neither helper
         * allocates, so the no-safepoint contract holds. */
        for (size_t i = 0; i < len; i++) {
            vader_box_t v = vader_array_src_slot(src, src_data, stag, src->offset + src_start, i);
            vader_array_store_slot(dst->buf, dst->offset + dst_start + i, v);
        }
    }
    if (kind == VADER_ARRAY_KIND_BOXED || kind == VADER_ARRAY_KIND_REF) {
        VADER_WRITE_BARRIER(dst->buf);
    }
}

/* After the length of `a` dropped. A buffer only `a` sees follows it, so a collection
 * frees what the dropped slots held. A shared one keeps its scan bound, since a
 * view may still read those slots, and `a` gives up its room instead: its next
 * push copies rather than overwrite them. See `vader_array_t`. */
static void vader_array_after_shrink(vader_array_t* a) {
    if (vader_array_buf_is_shared(a->buf)) {
        vader_array_set_capacity(a, vader_array_length(a));
    } else {
        a->buf->length = a->offset + vader_array_length(a);
    }
}

/* `arr.remove_last()`: pop the last element, shrink the length by one, and
 * return the element as a pre-tagged box (the boxed kind's slot box verbatim ;
 * a primitive read boxed with the static `element_tag`). Returns `vader_box_null`
 * on an empty array: the `T | null` null variant. Rejects borrowed views (a
 * view of a string's bytes is read-only, T3072). No allocation, so no rooting. */
vader_box_t vader_array_remove_last(vader_array_t* a) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        vader_trap("cannot remove_last from a borrowed `const u8[]` byte view");
    }
    a = vader_array_resolve(a);
    if (vader_array_length(a) == 0) return vader_box_null();
    vader_array_resolve_buf(a);
    vader_array_buf_t* buf = a->buf;
    size_t last = vader_array_length(a) - 1;
    vader_box_t out = vader_array_load_slot(buf, a->offset + last);
    vader_array_set_length(a, last);
    vader_array_after_shrink(a);
    return out;
}

/* `arr.clear()`: drop every element (length 0), keeping the buf + capacity for
 * reuse. Rejects borrowed views (read-only, T3072). */
void vader_array_clear(vader_array_t* a) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        vader_trap("cannot clear a borrowed `const u8[]` byte view");
    }
    a = vader_array_resolve(a);
    vader_array_resolve_buf(a);
    vader_array_set_length(a, 0);
    vader_array_after_shrink(a);
}
