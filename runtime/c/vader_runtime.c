/* Vader native runtime — implementation. See `vader.h` for the public API.
 *
 * Memory model: Cheney semi-space copying GC. Two arenas of equal size; the
 * from-space is bump-allocated by `vader_gc_alloc`; when full, `vader_gc_collect`
 * copies live objects to to-space (driven by the shadow stack) and swaps.
 */

#include "vader.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

/* ----------------------------------------------------------------- gc arena */

#ifndef VADER_GC_ARENA_BYTES
#define VADER_GC_ARENA_BYTES (16u * 1024u * 1024u)   /* 16 MB per semi-space */
#endif

#define VADER_GC_ALIGN 8u

typedef struct {
    char* base;
    char* cur;
    char* end;
} vader_arena_t;

static vader_arena_t g_from_space = { NULL, NULL, NULL };
static vader_arena_t g_to_space   = { NULL, NULL, NULL };
static int           g_gc_initialized = 0;
static size_t        g_total_collections = 0;
static size_t        g_total_copied = 0;

/* Shadow-stack head. Each emitted C function pushes/pops a frame chained
 * through `prev`; the GC walks this list at collection time to enumerate
 * precise roots. */
vader_gc_frame_t* vader_gc_top = NULL;

static size_t vader_gc_align(size_t n) {
    return (n + (VADER_GC_ALIGN - 1u)) & ~(size_t)(VADER_GC_ALIGN - 1u);
}

void vader_gc_init(void) {
    if (g_gc_initialized) return;
    g_from_space.base = (char*) malloc(VADER_GC_ARENA_BYTES);
    g_to_space.base   = (char*) malloc(VADER_GC_ARENA_BYTES);
    if (g_from_space.base == NULL || g_to_space.base == NULL) {
        vader_trap("vader_gc_init: arena malloc failed");
    }
    g_from_space.cur = g_from_space.base;
    g_from_space.end = g_from_space.base + VADER_GC_ARENA_BYTES;
    g_to_space.cur   = g_to_space.base;
    g_to_space.end   = g_to_space.base + VADER_GC_ARENA_BYTES;
    g_gc_initialized = 1;
}

void vader_gc_shutdown(void) {
    if (!g_gc_initialized) return;
    free(g_from_space.base);
    free(g_to_space.base);
    g_from_space.base = g_from_space.cur = g_from_space.end = NULL;
    g_to_space.base   = g_to_space.cur   = g_to_space.end   = NULL;
    g_gc_initialized = 0;
}

void* vader_gc_alloc(size_t bytes) {
    if (!g_gc_initialized) vader_gc_init();
    size_t aligned = vader_gc_align(bytes);
    if (g_from_space.cur + aligned > g_from_space.end) {
        vader_gc_collect();
        if (g_from_space.cur + aligned > g_from_space.end) {
            vader_trap("vader_gc_alloc: out of memory after collection");
        }
    }
    void* p = g_from_space.cur;
    g_from_space.cur += aligned;
    return p;
}

/* ---------- Cheney semi-space copying GC ---------- */

/* Size of an object in the from-space, in bytes. For variable-length
 * buffers (ARRAY_BUF sentinel) the size is read off the object itself; for
 * everything else the type info table provides a static size. Returns 0
 * for non-heap kinds (caller skips). */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index) {
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) obj;
        return sizeof(vader_array_buf_t) + buf->capacity * sizeof(vader_box_t);
    }
    if (type_index >= vader_type_info_count) return 0;
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    if (info->kind == VADER_TYPE_KIND_NONE) return 0;
    return info->size;
}

/* Forward-copy `obj` (typed by `type_index`) to to-space. Returns the new
 * address, or the existing forwarding address if already copied this cycle.
 * NULL inputs round-trip as NULL. */
static void* vader_gc_forward(void* obj, uint32_t type_index) {
    if (obj == NULL) return NULL;
    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    if (hdr->forward != NULL) return hdr->forward;     /* already moved */
    size_t bytes = vader_gc_obj_size(obj, type_index);
    /* Defensive: a non-heap kind in the type info table (or an unknown
     * type_index) is a no-op forward — emitter-produced objects shouldn't
     * land here, but a future allocator that forgets the header init would. */
    if (bytes == 0) return obj;
    size_t aligned = vader_gc_align(bytes);
    if (g_to_space.cur + aligned > g_to_space.end) {
        vader_trap("vader_gc: to-space overflow during copy");
    }
    void* dst = g_to_space.cur;
    g_to_space.cur += aligned;
    memcpy(dst, obj, bytes);
    g_total_copied += bytes;
    /* Mark the original as forwarded; clear forward on the new copy so it
     * appears live (not yet forwarded) within this cycle. */
    hdr->forward = dst;
    ((vader_obj_header_t*) dst)->forward = NULL;
    return dst;
}

/* Scan a `vader_box_t` slot — if the tag identifies a heap-allocated kind and
 * the payload holds a pointer, forward it and update the slot in place. */
static void vader_gc_scan_box(vader_box_t* boxp) {
    if (boxp == NULL) return;
    if (boxp->tag >= vader_type_info_count) return;
    const vader_type_info_t* info = &vader_type_info_table[boxp->tag];
    if (info->kind == VADER_TYPE_KIND_NONE) return;
    /* For ARRAY-kind tags the payload is a vader_array_t* — forward it; the
     * Cheney scan will walk its `buf` ref afterwards. */
    boxp->payload.obj = vader_gc_forward(boxp->payload.obj, boxp->tag);
}

/* Scan a raw `void*` slot whose pointee is a heap object. Reads the pointee's
 * header to get its type, forwards, updates. Used for fn closure envs. */
static void vader_gc_scan_raw(void** slot) {
    if (slot == NULL || *slot == NULL) return;
    vader_obj_header_t* hdr = (vader_obj_header_t*) *slot;
    /* Watch for a forwarding pointer left over from this cycle. */
    if (hdr->forward != NULL) { *slot = hdr->forward; return; }
    *slot = vader_gc_forward(*slot, hdr->type_index);
}

void vader_gc_collect(void) {
    if (!g_gc_initialized) return;

    /* Reset to-space — last cycle's swap left it as the spare. */
    g_to_space.cur = g_to_space.base;
    char* scan = g_to_space.cur;

    /* 1. Walk the shadow stack to copy the root set. Each frame's `ptrs`
     *    array points to vader_box_t cells in the C-emit'd locals. */
    for (vader_gc_frame_t* fr = vader_gc_top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs == NULL) continue;
        for (uint32_t i = 0; i < fr->nrefs; i++) {
            vader_gc_scan_box(fr->ptrs[i]);
        }
    }

    /* 2. Cheney scan loop — walk objects newly-copied to to-space, scan their
     *    internal references via the per-type pointer maps, copy whatever
     *    they point to. The to-space `cur` advances as we discover and copy
     *    more reachable objects. */
    while (scan < g_to_space.cur) {
        vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
        uint32_t type_index = hdr->type_index;

        if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
            /* Variable-length object — scan the live slots, advance by the
             * full capacity since allocations are sized by capacity. */
            vader_array_buf_t* buf = (vader_array_buf_t*) scan;
            for (size_t i = 0; i < buf->length; i++) {
                vader_gc_scan_box(&buf->slots[i]);
            }
            scan += vader_gc_align(sizeof(vader_array_buf_t)
                                   + buf->capacity * sizeof(vader_box_t));
            continue;
        }

        if (type_index >= vader_type_info_count) {
            vader_trap("vader_gc: scanned object with unknown type_index");
        }
        const vader_type_info_t* info = &vader_type_info_table[type_index];
        for (uint16_t i = 0; i < info->ptr_count; i++) {
            char* field = scan + info->ptr_offsets[i];
            if (info->kind == VADER_TYPE_KIND_FN
                || info->kind == VADER_TYPE_KIND_ARRAY) {
                /* fn:   only `env` is a heap ref; raw void*.
                 * array: `buf` is a raw pointer to a vader_array_buf_t with
                 *        its own header — same scan_raw treatment. */
                vader_gc_scan_raw((void**) field);
            } else {
                vader_gc_scan_box((vader_box_t*) field);
            }
        }
        scan += vader_gc_align(info->size);
    }

    /* 3. Swap arenas. The new from-space is yesterday's to-space, fully
     *    populated with the live set; the new to-space is the old from-space,
     *    reset for next cycle. */
    vader_arena_t tmp = g_from_space;
    g_from_space    = g_to_space;
    g_to_space      = tmp;
    g_to_space.cur  = g_to_space.base;

    g_total_collections++;
}

vader_gc_stats_t vader_gc_get_stats(void) {
    vader_gc_stats_t s;
    s.arena_size = VADER_GC_ARENA_BYTES;
    s.bytes_used = g_gc_initialized ? (size_t)(g_from_space.cur - g_from_space.base) : 0;
    s.total_collections = g_total_collections;
    s.total_copied = g_total_copied;
    return s;
}

/* String char buffer allocator — strings are immutable value types {ptr,len}
 * passed by copy. Tracking those copies through the moving GC would require a
 * lookup from char-ptr to header on every scan; the MVP picks the pragmatic
 * trade-off and leaks string buffers outside the arena. */
static void* vader_string_alloc(size_t bytes) {
    void* p = malloc(bytes == 0 ? 1 : bytes);
    if (p == NULL) vader_trap("vader_string_alloc: malloc failed");
    return p;
}

/* ----------------------------------------------------------------- string */

vader_string_t vader_string_concat(vader_string_t a, vader_string_t b) {
    char* buf = (char*) vader_string_alloc(a.len + b.len);
    memcpy(buf,         a.ptr, a.len);
    memcpy(buf + a.len, b.ptr, b.len);
    return vader_string_new(buf, a.len + b.len);
}

bool vader_string_eq(vader_string_t a, vader_string_t b) {
    return a.len == b.len && memcmp(a.ptr, b.ptr, a.len) == 0;
}

/* ----------------------------------------------------------------- array */

/* Allocate a fresh array buffer of `capacity` slots with the ARRAY_BUF
 * sentinel as its type tag — the GC scan loop dispatches on that to walk
 * `length` slots dynamically. The struct itself plus its trailing slot
 * area land in a single GC arena allocation. */
static vader_array_buf_t* vader_array_buf_alloc(size_t capacity) {
    size_t bytes = sizeof(vader_array_buf_t) + capacity * sizeof(vader_box_t);
    vader_array_buf_t* buf = (vader_array_buf_t*) vader_gc_alloc(bytes);
    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity = capacity;
    buf->length   = 0;
    return buf;
}

vader_array_t* vader_array_new(uint32_t type_index, size_t length) {
    /* Single-block initial allocation: struct followed by an inline buf in
     * the same GC alloc. Two-step allocation has a window where one half is
     * unreachable from the shadow stack — a collection mid-construction
     * would lose the orphan. The combined block sidesteps it.
     *
     * Push later allocates a *separate* fresh buf and rebinds `a->buf`; from
     * the GC's point of view the two halves are independent objects (the
     * struct has kind=ARRAY pointing at a kind=ARRAY_BUF), so subsequent
     * cycles relocate them separately without surprise. */
    size_t cap = length > 0 ? length : 4;
    size_t struct_bytes = vader_gc_align(sizeof(vader_array_t));
    size_t buf_bytes    = sizeof(vader_array_buf_t) + cap * sizeof(vader_box_t);
    char* block = (char*) vader_gc_alloc(struct_bytes + buf_bytes);
    vader_array_t* a = (vader_array_t*) block;
    vader_array_buf_t* buf = (vader_array_buf_t*) (block + struct_bytes);

    vader_obj_header_init(a, type_index);
    a->length   = length;
    a->capacity = cap;
    a->buf      = buf;

    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity = cap;
    buf->length   = length;
    return a;
}

size_t vader_array_len(vader_array_t* a) { return a->length; }

vader_box_t vader_array_get(vader_array_t* a, size_t i) {
    if (i >= a->length) vader_trap("array index out of bounds");
    return a->buf->slots[i];
}

void vader_array_set(vader_array_t* a, size_t i, vader_box_t v) {
    if (i >= a->length) vader_trap("array index out of bounds");
    a->buf->slots[i] = v;
}

/* If `a` was relocated by a collection that fired during a recent allocation,
 * its old header carries a forwarding pointer to the new copy. Caller-side
 * code reloads `a` from a shadow-stack slot, but runtime helpers receive `a`
 * as a raw C pointer — after a GC mid-call the parameter is stale. Resolving
 * the forward keeps the helper sound. */
static vader_array_t* vader_array_resolve(vader_array_t* a) {
    if (a->header.forward != NULL) return (vader_array_t*) a->header.forward;
    return a;
}

void vader_array_push(vader_array_t* a, vader_box_t v) {
    if (a->length >= a->capacity) {
        size_t cap = a->capacity == 0 ? 4 : a->capacity * 2;
        vader_array_buf_t* fresh = vader_array_buf_alloc(cap);  /* may collect */
        a = vader_array_resolve(a);
        vader_array_buf_t* old = a->buf;
        if (old != NULL && old->header.forward != NULL) {
            old = (vader_array_buf_t*) old->header.forward;
        }
        if (a->length > 0 && old != NULL) {
            memcpy(fresh->slots, old->slots, a->length * sizeof(vader_box_t));
        }
        fresh->length = a->length;
        a->buf = fresh;
        a->capacity = cap;
    }
    a->buf->slots[a->length] = v;
    a->length += 1;
    a->buf->length = a->length;
}

/* ----------------------------------------------------------------- std/string */

vader_i32_t vader_string_len(vader_string_t s) {
    return (vader_i32_t) s.len;
}

vader_string_t vader_string_slice(vader_string_t s, vader_i32_t start, vader_i32_t end) {
    if (start < 0) start = 0;
    if (end < 0 || (size_t) end > s.len) end = (vader_i32_t) s.len;
    if (start >= end) return vader_string_new("", 0);
    return vader_string_new(s.ptr + start, (size_t) (end - start));
}

vader_bool_t vader_string_contains(vader_string_t s, vader_string_t sub) {
    if (sub.len == 0) return true;
    if (sub.len > s.len) return false;
    for (size_t i = 0; i <= s.len - sub.len; i++) {
        if (memcmp(s.ptr + i, sub.ptr, sub.len) == 0) return true;
    }
    return false;
}

vader_bool_t vader_string_starts_with(vader_string_t s, vader_string_t prefix) {
    if (prefix.len > s.len) return false;
    return memcmp(s.ptr, prefix.ptr, prefix.len) == 0;
}

vader_bool_t vader_string_ends_with(vader_string_t s, vader_string_t suffix) {
    if (suffix.len > s.len) return false;
    return memcmp(s.ptr + s.len - suffix.len, suffix.ptr, suffix.len) == 0;
}

vader_string_t vader_string_trim(vader_string_t s) {
    const char* p = s.ptr;
    size_t n = s.len;
    while (n > 0 && isspace((unsigned char) *p))    { p++; n--; }
    while (n > 0 && isspace((unsigned char) p[n-1])) { n--; }
    return vader_string_new(p, n);
}

vader_string_t vader_string_to_upper(vader_string_t s) {
    char* buf = (char*) vader_string_alloc(s.len);
    for (size_t i = 0; i < s.len; i++) buf[i] = (char) toupper((unsigned char) s.ptr[i]);
    return vader_string_new(buf, s.len);
}

vader_string_t vader_string_to_lower(vader_string_t s) {
    char* buf = (char*) vader_string_alloc(s.len);
    for (size_t i = 0; i < s.len; i++) buf[i] = (char) tolower((unsigned char) s.ptr[i]);
    return vader_string_new(buf, s.len);
}

vader_box_t vader_string_parse_int(vader_string_t s, uint32_t ok_tag, uint32_t err_tag) {
    /* The NUL-terminated copy is a scratch buffer (consumed before strtol
     * returns). It can sit on the stack for typical inputs but heap-fall-back
     * for very long strings keeps the implementation simple — leak the scratch
     * since it's transient. */
    char* p = (char*) vader_string_alloc(s.len + 1);
    memcpy(p, s.ptr, s.len); p[s.len] = '\0';
    char* end;
    long v = strtol(p, &end, 10);
    int ok = (end != p && *end == '\0');
    free(p);
    if (!ok) {
        return vader_box_string(err_tag, vader_string_new("invalid integer", 15));
    }
    return vader_box_i32(ok_tag, (vader_i32_t) v);
}

vader_box_t vader_string_parse_float(vader_string_t s, uint32_t ok_tag, uint32_t err_tag) {
    char* p = (char*) vader_string_alloc(s.len + 1);
    memcpy(p, s.ptr, s.len); p[s.len] = '\0';
    char* end;
    double v = strtod(p, &end);
    int ok = (end != p && *end == '\0');
    free(p);
    if (!ok) {
        return vader_box_string(err_tag, vader_string_new("invalid float", 13));
    }
    return vader_box_f64(ok_tag, v);
}

vader_char_t vader_string_char_at(vader_string_t s, vader_i32_t i) {
    if (i < 0 || (size_t)i >= s.len) return 0;
    const uint8_t* p = (const uint8_t*)(s.ptr + i);
    size_t rem = s.len - (size_t)i;
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

vader_array_t* vader_string_split(vader_string_t s, vader_string_t sep,
                                  uint32_t arr_type, uint32_t str_type) {
    vader_array_t* arr = vader_array_new(arr_type, 0);
    if (sep.len == 0) {
        for (size_t i = 0; i < s.len; i++) {
            vader_array_push(arr, vader_box_string(str_type, vader_string_new(s.ptr + i, 1)));
        }
        return arr;
    }
    const char* p   = s.ptr;
    const char* end = s.ptr + s.len;
    for (;;) {
        const char* found = NULL;
        if (sep.len == 1) {
            found = (const char*)memchr(p, (unsigned char)sep.ptr[0], (size_t)(end - p));
        } else {
            for (const char* q = p; q + sep.len <= end; q++) {
                if (memcmp(q, sep.ptr, sep.len) == 0) { found = q; break; }
            }
        }
        size_t piece_len = found ? (size_t)(found - p) : (size_t)(end - p);
        vader_array_push(arr, vader_box_string(str_type, vader_string_new(p, piece_len)));
        if (found == NULL) break;
        p = found + sep.len;
    }
    return arr;
}

/* ----------------------------------------------------------------- builder */

struct vader_builder_s {
    char*  buf;
    size_t len;
    size_t cap;
};

static void builder_reserve(vader_builder_t* b, size_t extra) {
    if (b->len + extra <= b->cap) return;
    size_t cap = b->cap == 0 ? 64 : b->cap;
    while (cap < b->len + extra) cap *= 2;
    /* The buf is handed out as a vader_string_t by `vader_builder_finish`, so
     * it must live off the GC arena (same constraint as `vader_string_alloc`
     * callers). Copy + leak the previous buffer. */
    char* fresh = (char*) vader_string_alloc(cap);
    if (b->len > 0) memcpy(fresh, b->buf, b->len);
    b->buf = fresh;
    b->cap = cap;
}

vader_builder_t* vader_builder_new(void) {
    /* The builder struct itself is short-lived (allocated, used, then the
     * resulting string outlives it). Using malloc keeps it off the GC arena
     * so a collection can't relocate the struct mid-build. */
    vader_builder_t* b = (vader_builder_t*) vader_string_alloc(sizeof(vader_builder_t));
    b->buf = NULL; b->len = 0; b->cap = 0;
    return b;
}

void vader_builder_append_str(vader_builder_t* b, vader_string_t s) {
    builder_reserve(b, s.len);
    memcpy(b->buf + b->len, s.ptr, s.len);
    b->len += s.len;
}

static void builder_append_fmt(vader_builder_t* b, const char* fmt, ...) {
    char tmp[64];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(tmp, sizeof(tmp), fmt, ap);
    va_end(ap);
    if (n < 0) return;
    builder_reserve(b, (size_t) n);
    memcpy(b->buf + b->len, tmp, (size_t) n);
    b->len += (size_t) n;
}

void vader_builder_append_display_i32(vader_builder_t* b, vader_i32_t v) { builder_append_fmt(b, "%" PRId32, v); }
void vader_builder_append_display_i64(vader_builder_t* b, vader_i64_t v) { builder_append_fmt(b, "%" PRId64, v); }
void vader_builder_append_display_u32(vader_builder_t* b, vader_u32_t v) { builder_append_fmt(b, "%" PRIu32, v); }
void vader_builder_append_display_u64(vader_builder_t* b, vader_u64_t v) { builder_append_fmt(b, "%" PRIu64, v); }
void vader_builder_append_display_f32(vader_builder_t* b, vader_f32_t v) {
    double d = (double) v;
    if (isfinite(d) && d == floor(d)) builder_append_fmt(b, "%.1f", d);
    else                              builder_append_fmt(b, "%g",   d);
}
void vader_builder_append_display_f64(vader_builder_t* b, vader_f64_t v) {
    if (isfinite(v) && v == floor(v)) builder_append_fmt(b, "%.1f", v);
    else                              builder_append_fmt(b, "%g",   v);
}
void vader_builder_append_display_bool(vader_builder_t* b, vader_bool_t v) {
    vader_string_t s = v ? vader_string_new("true", 4) : vader_string_new("false", 5);
    vader_builder_append_str(b, s);
}
void vader_builder_append_display_char(vader_builder_t* b, vader_char_t v) {
    /* Encode the codepoint as UTF-8. */
    if (v < 0x80) {
        builder_reserve(b, 1);
        b->buf[b->len++] = (char) v;
    } else if (v < 0x800) {
        builder_reserve(b, 2);
        b->buf[b->len++] = (char) (0xC0 | (v >> 6));
        b->buf[b->len++] = (char) (0x80 | (v & 0x3F));
    } else if (v < 0x10000) {
        builder_reserve(b, 3);
        b->buf[b->len++] = (char) (0xE0 | (v >> 12));
        b->buf[b->len++] = (char) (0x80 | ((v >> 6) & 0x3F));
        b->buf[b->len++] = (char) (0x80 | (v & 0x3F));
    } else {
        builder_reserve(b, 4);
        b->buf[b->len++] = (char) (0xF0 | (v >> 18));
        b->buf[b->len++] = (char) (0x80 | ((v >> 12) & 0x3F));
        b->buf[b->len++] = (char) (0x80 | ((v >> 6) & 0x3F));
        b->buf[b->len++] = (char) (0x80 | (v & 0x3F));
    }
}
void vader_builder_append_display_string(vader_builder_t* b, vader_string_t v) {
    vader_builder_append_str(b, v);
}

vader_string_t vader_builder_finish(vader_builder_t* b) {
    /* The buffer is already big enough; just expose its current view. The
     * builder itself isn't reused after finish so the buffer is safe to lend. */
    return vader_string_new(b->buf, b->len);
}

/* ----------------------------------------------------------------- I/O */

void vader_print(vader_string_t s)   { fwrite(s.ptr, 1, s.len, stdout); fflush(stdout); }
void vader_println(vader_string_t s) { fwrite(s.ptr, 1, s.len, stdout); fputc('\n', stdout); fflush(stdout); }

/* Tag-aware variants — the emitter passes the BcType indices for the success
 * and error variants. Caller-side boxing keeps the runtime tag-agnostic. */
vader_box_t vader_read_file(vader_string_t path, uint32_t ok_tag, uint32_t err_tag) {
    char* p = (char*) vader_string_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    FILE* f = fopen(p, "rb");
    free(p);
    if (f == NULL) return vader_box_string(err_tag, vader_string_new("file not found", 14));

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size < 0) { fclose(f); return vader_box_string(err_tag, vader_string_new("ftell failed", 12)); }

    char* buf = (char*) vader_string_alloc((size_t) size);
    size_t n = fread(buf, 1, (size_t) size, f);
    fclose(f);
    if (n != (size_t) size) return vader_box_string(err_tag, vader_string_new("short read", 10));
    return vader_box_string(ok_tag, vader_string_new(buf, (size_t) size));
}

vader_box_t vader_write_file(vader_string_t path, vader_string_t content,
                             uint32_t ok_tag, uint32_t err_tag) {
    char* p = (char*) vader_string_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    FILE* f = fopen(p, "wb");
    free(p);
    if (f == NULL) return vader_box_string(err_tag, vader_string_new("open failed", 11));
    size_t n = fwrite(content.ptr, 1, content.len, f);
    fclose(f);
    if (n != content.len) return vader_box_string(err_tag, vader_string_new("short write", 11));
    /* `void!` returns null on success per stdlib convention. */
    (void) ok_tag;
    return vader_box_null();
}

vader_box_t vader_read_line(uint32_t ok_tag, uint32_t err_tag) {
    char buf[4096];
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return vader_box_string(err_tag, vader_string_new("EOF", 3));
    }
    size_t n = strlen(buf);
    if (n > 0 && buf[n - 1] == '\n') n--;
    char* copy = (char*) vader_string_alloc(n);
    memcpy(copy, buf, n);
    return vader_box_string(ok_tag, vader_string_new(copy, n));
}

vader_bool_t vader_exists(vader_string_t path) {
    char* p = (char*) vader_string_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    FILE* f = fopen(p, "rb");
    free(p);
    if (f == NULL) return false;
    fclose(f);
    return true;
}

/* ----------------------------------------------------------------- traps */

void vader_unreachable(const char* where) {
    fprintf(stderr, "vader: reached unreachable at %s\n", where);
    abort();
}

void vader_trap(const char* msg) {
    fprintf(stderr, "vader: trap — %s\n", msg);
    abort();
}
