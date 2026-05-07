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

#include <errno.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>

extern char** environ;

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

/* FNV-1a 64-bit hash over the raw UTF-8 bytes of the string. */
vader_u64_t vader_string_hash(vader_string_t s) {
    uint64_t h = UINT64_C(14695981039346656037);
    const uint8_t* p = (const uint8_t*) s.ptr;
    for (size_t i = 0; i < s.len; i++) {
        h ^= (uint64_t) p[i];
        h *= UINT64_C(1099511628211);
    }
    return h;
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

/* Box the host argv into a `[string]` Vader array. Called from emitted main
 * when the user's `main` takes an `[string]` parameter. The caller passes the
 * BcType indices for the array type and the string element type (the emitter
 * knows them at codegen time). */
vader_array_t* vader_runtime_argv(int argc, char** argv, uint32_t arr_type, uint32_t str_type) {
    vader_array_t* arr = vader_array_new(arr_type, 0);
    for (int i = 0; i < argc; i++) {
        const char* a = argv[i];
        size_t len = strlen(a);
        vader_array_push(arr, vader_box_string(str_type, vader_string_new(a, len)));
    }
    return arr;
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
/* Format a finite non-integer float as the shortest decimal that round-trips
 * back to the same double. Mirrors JS `Number.prototype.toString()` (and thus
 * the VM's `displayValue`) so VM and native produce identical output. */
static void append_shortest_double(vader_builder_t* b, double v) {
    char buf[64];
    int n = 0;
    for (int p = 1; p <= 17; p++) {
        n = snprintf(buf, sizeof buf, "%.*g", p, v);
        if (strtod(buf, NULL) == v) break;
    }
    if (n < 0) n = 0;
    if ((size_t) n >= sizeof buf) n = (int) sizeof buf - 1;
    builder_reserve(b, (size_t) n);
    memcpy(b->buf + b->len, buf, (size_t) n);
    b->len += (size_t) n;
}
void vader_builder_append_display_f32(vader_builder_t* b, vader_f32_t v) {
    double d = (double) v;
    if (isfinite(d) && d == floor(d)) builder_append_fmt(b, "%.1f", d);
    else if (!isfinite(d))            builder_append_fmt(b, "%g",   d);
    else                              append_shortest_double(b, d);
}
void vader_builder_append_display_f64(vader_builder_t* b, vader_f64_t v) {
    if (isfinite(v) && v == floor(v)) builder_append_fmt(b, "%.1f", v);
    else if (!isfinite(v))            builder_append_fmt(b, "%g",   v);
    else                              append_shortest_double(b, v);
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

/* Flatten an array of strings into a single string in one allocation. Used
 * by std/string_builder StringBuilder.to_string to avoid the O(N²) of repeated `+`. */
vader_string_t vader_string_concat_all(vader_array_t* parts) {
    if (parts->length == 0) {
        return vader_string_new("", 0);
    }
    size_t total = 0;
    for (size_t i = 0; i < parts->length; i++) {
        total += parts->buf->slots[i].payload.s.len;
    }
    char* buf = (char*) vader_string_alloc(total);
    size_t pos = 0;
    for (size_t i = 0; i < parts->length; i++) {
        vader_string_t s = parts->buf->slots[i].payload.s;
        memcpy(buf + pos, s.ptr, s.len);
        pos += s.len;
    }
    return vader_string_new(buf, total);
}

/* ----------------------------------------------------------------- I/O */

void vader_print(vader_string_t s)    { fwrite(s.ptr, 1, s.len, stdout); fflush(stdout); }
void vader_println(vader_string_t s)  { fwrite(s.ptr, 1, s.len, stdout); fputc('\n', stdout); fflush(stdout); }
void vader_eprint(vader_string_t s)   { fwrite(s.ptr, 1, s.len, stderr); fflush(stderr); }
void vader_eprintln(vader_string_t s) { fwrite(s.ptr, 1, s.len, stderr); fputc('\n', stderr); fflush(stderr); }

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

/* ----------------------------------------------------------------- process
 *
 * `vader_spawn_run` posix_spawn-s a child with stdout/stderr redirected to
 * pipes, drains both, waitpid()s, and stashes the captured output into
 * runtime-owned static buffers. Single-threaded by design — last-call wins,
 * follow-up `spawn_last_stdout` / `_stderr` calls fetch the buffers.
 *
 * Pipes are read fully into heap buffers before waitpid completes ; on a
 * deadlock-prone large output the buffer pumps grow with realloc. We use
 * `vader_string_alloc` for the final buffers so the strings live outside the
 * GC arena and persist for the lifetime of the program (matches the existing
 * convention for I/O-produced strings — see `read_file`).
 */

/* Captured pipes from the most recent `vader_spawn_run`. Buffers are
 * `vader_string_alloc`-ed (GC-arena-safe, leaks for the program's lifetime
 * — same convention as `vader_read_file`'s result). Each new spawn replaces
 * the buffers : `vader_string_alloc` is non-freeing so the previous strings
 * remain valid until the program exits, which dodges a use-after-free for
 * any Vader value still referencing the previous result. */
static char*  g_spawn_stdout_buf = NULL;
static size_t g_spawn_stdout_len = 0;
static char*  g_spawn_stderr_buf = NULL;
static size_t g_spawn_stderr_len = 0;

/* Drain a fd into a freshly-malloc'd buffer. Caller frees. NULL on read error. */
static char* drain_fd(int fd, size_t* out_len) {
    size_t cap = 4096, len = 0;
    char* buf = (char*) malloc(cap);
    if (buf == NULL) { *out_len = 0; return NULL; }
    for (;;) {
        if (len + 4096 > cap) {
            cap *= 2;
            char* grown = (char*) realloc(buf, cap);
            if (grown == NULL) { free(buf); *out_len = 0; return NULL; }
            buf = grown;
        }
        ssize_t n = read(fd, buf + len, cap - len);
        if (n < 0) {
            if (errno == EINTR) continue;
            free(buf); *out_len = 0; return NULL;
        }
        if (n == 0) break;
        len += (size_t) n;
    }
    *out_len = len;
    return buf;
}

static void capture_spawn_output(char** dst_buf, size_t* dst_len, char* src, size_t src_len) {
    if (src == NULL || src_len == 0) {
        *dst_buf = NULL; *dst_len = 0;
        if (src != NULL) free(src);
        return;
    }
    char* copy = (char*) vader_string_alloc(src_len);
    memcpy(copy, src, src_len);
    free(src);
    *dst_buf = copy;
    *dst_len = src_len;
}

vader_i32_t vader_spawn_run(vader_array_t* argv) {
    if (argv == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    size_t n = vader_array_len(argv);
    if (n == 0) return VADER_SPAWN_LAUNCH_FAIL;

    /* Build a NULL-terminated argv from the Vader [string] array — each slot
     * needs to be a 0-terminated C string. */
    char** cargv = (char**) calloc(n + 1, sizeof(char*));
    if (cargv == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = vader_array_get(argv, i);
        vader_string_t s = b.payload.s;
        char* z = (char*) malloc(s.len + 1);
        if (z == NULL) {
            for (size_t j = 0; j < i; j++) free(cargv[j]);
            free(cargv);
            return VADER_SPAWN_LAUNCH_FAIL;
        }
        memcpy(z, s.ptr, s.len); z[s.len] = '\0';
        cargv[i] = z;
    }

    int out_pipe[2] = {-1, -1};
    int err_pipe[2] = {-1, -1};
    if (pipe(out_pipe) != 0 || pipe(err_pipe) != 0) {
        for (size_t j = 0; j < n; j++) free(cargv[j]);
        free(cargv);
        if (out_pipe[0] >= 0) { close(out_pipe[0]); close(out_pipe[1]); }
        return VADER_SPAWN_LAUNCH_FAIL;
    }

    posix_spawn_file_actions_t fa;
    posix_spawn_file_actions_init(&fa);
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

    if (rc != 0) {
        close(out_pipe[0]);
        close(err_pipe[0]);
        capture_spawn_output(&g_spawn_stdout_buf, &g_spawn_stdout_len, NULL, 0);
        capture_spawn_output(&g_spawn_stderr_buf, &g_spawn_stderr_len, NULL, 0);
        return VADER_SPAWN_LAUNCH_FAIL;
    }

    size_t out_len = 0, err_len = 0;
    char* out_buf = drain_fd(out_pipe[0], &out_len);
    char* err_buf = drain_fd(err_pipe[0], &err_len);
    close(out_pipe[0]);
    close(err_pipe[0]);

    int status = 0;
    while (waitpid(pid, &status, 0) < 0) {
        if (errno != EINTR) { status = -1; break; }
    }

    capture_spawn_output(&g_spawn_stdout_buf, &g_spawn_stdout_len, out_buf, out_len);
    capture_spawn_output(&g_spawn_stderr_buf, &g_spawn_stderr_len, err_buf, err_len);

    if (WIFEXITED(status))   return (vader_i32_t) WEXITSTATUS(status);
    if (WIFSIGNALED(status)) return VADER_SPAWN_SIGNALED;
    return VADER_SPAWN_LAUNCH_FAIL;
}

vader_string_t vader_spawn_last_stdout(void) {
    return vader_string_new(g_spawn_stdout_buf, g_spawn_stdout_len);
}

vader_string_t vader_spawn_last_stderr(void) {
    return vader_string_new(g_spawn_stderr_buf, g_spawn_stderr_len);
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
