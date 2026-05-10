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

#if defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#else
#  include <spawn.h>
#  include <sys/wait.h>
#  include <unistd.h>
extern char** environ;
#endif

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
    if (VADER_UNLIKELY(!g_gc_initialized)) vader_gc_init();
    size_t aligned = vader_gc_align(bytes);
    if (VADER_UNLIKELY(g_from_space.cur + aligned > g_from_space.end)) {
        vader_gc_collect();
        if (VADER_UNLIKELY(g_from_space.cur + aligned > g_from_space.end)) {
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
 * NULL inputs round-trip as NULL.
 *
 * Pointers outside the from-space arena are treated as immortal — static
 * compile-time data (lookup tables, interned constants) lives in the C data
 * segment and is never copied. The C-emit may emit such tables for fns
 * matching the `match enum -> StructLit constant` pattern (TODO §3.5 Prop 2).
 * Constraint: a static object MUST NOT contain any pointer to a dynamic
 * (arena-allocated) object — the Cheney scan never visits it, so any inner
 * dynamic ref would be missed and freed under your feet. */
static void* vader_gc_forward(void* obj, uint32_t type_index) {
    if (obj == NULL) return NULL;
    if ((char*) obj < g_from_space.base || (char*) obj >= g_from_space.end) {
        return obj;                                    /* static / immortal */
    }
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
    if ((char*) *slot < g_from_space.base || (char*) *slot >= g_from_space.end) {
        return;                                        /* static / immortal */
    }
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
 * trade-off and leaks string buffers outside the arena.
 *
 * Zero-length requests return a process-lifetime sentinel rather than a
 * fresh 1-byte allocation: the caller never writes (every write site is a
 * `memcpy` of `bytes` bytes, which is a no-op for zero) so const aliasing
 * is safe, and we save one malloc per empty-string operation. */
static char vader_string_empty_sentinel[1] = { 0 };
static void* vader_string_alloc(size_t bytes) {
    if (bytes == 0) return vader_string_empty_sentinel;
    void* p = malloc(bytes);
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

/* `sizeof(vader_array_buf_t) + capacity * sizeof(vader_box_t)` without
 * silent integer overflow. With user-controllable `capacity` (e.g. via
 * `array.push` reaching into the gigabytes), the multiplication can wrap
 * `size_t` and produce an under-allocation followed by an OOB write. Trap
 * before the alloc with a clear message instead. */
static size_t vader_array_buf_bytes(size_t capacity) {
    const size_t per_slot = sizeof(vader_box_t);
    if (capacity > (SIZE_MAX - sizeof(vader_array_buf_t)) / per_slot) {
        vader_trap("vader_array: capacity overflows size_t");
    }
    return sizeof(vader_array_buf_t) + capacity * per_slot;
}

/* Allocate a fresh array buffer of `capacity` slots with the ARRAY_BUF
 * sentinel as its type tag — the GC scan loop dispatches on that to walk
 * `length` slots dynamically. The struct itself plus its trailing slot
 * area land in a single GC arena allocation. */
static vader_array_buf_t* vader_array_buf_alloc(size_t capacity) {
    size_t bytes = vader_array_buf_bytes(capacity);
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
    size_t buf_bytes    = vader_array_buf_bytes(cap);
    if (struct_bytes > SIZE_MAX - buf_bytes) {
        vader_trap("vader_array: total alloc size overflows size_t");
    }
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

vader_box_t vader_array_get(vader_array_t* a, size_t i) {
    if (VADER_UNLIKELY(i >= a->length)) vader_trap("array index out of bounds");
    return a->buf->slots[i];
}

void vader_array_set(vader_array_t* a, size_t i, vader_box_t v) {
    if (VADER_UNLIKELY(i >= a->length)) vader_trap("array index out of bounds");
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

size_t vader_string_byte_len(vader_string_t s) {
    return s.len;
}

vader_string_t vader_string_slice(vader_string_t s, size_t start, size_t end) {
    if (end > s.len) end = s.len;
    if (start >= end) return vader_string_new("", 0);
    return vader_string_new(s.ptr + start, end - start);
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

vader_char_t vader_string_char_at(vader_string_t s, size_t i) {
    /* Trap on OOB to match `vader_array_get`'s contract — silently returning
     * 0 made callers confuse "real NUL byte" with "out of bounds". The
     * truncated-UTF-8 returns below stay as `0` / `0xFFFD` because they
     * surface mid-codepoint encoding errors, not access violations. */
    if (i >= s.len) vader_trap("string index out of bounds");
    const uint8_t* p = (const uint8_t*)(s.ptr + i);
    size_t rem = s.len - i;
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

vader_u8_t vader_string_byte_at(vader_string_t s, size_t i) {
    if (i >= s.len) vader_trap("string index out of bounds");
    return (vader_u8_t)(uint8_t) s.ptr[i];
}

/* Box the host argv into a `[string]` Vader array. Called from emitted main
 * when the user's `main` takes an `[string]` parameter. The caller passes the
 * BcType indices for the array type and the string element type (the emitter
 * knows them at codegen time).
 *
 * Each `vader_array_push` may collect; the shadow-stack frame keeps `arr_box`
 * reachable so its `payload.obj` tracks the array across moves. */
vader_array_t* vader_runtime_argv(int argc, char** argv, uint32_t arr_type, uint32_t str_type) {
    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0));
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

vader_array_t* vader_string_split(vader_string_t s, vader_string_t sep,
                                  uint32_t arr_type, uint32_t str_type) {
    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0));
    VADER_GC_PUSH1(arr_box);
    if (sep.len == 0) {
        for (size_t i = 0; i < s.len; i++) {
            vader_array_push((vader_array_t*) arr_box.payload.obj,
                             vader_box_string(str_type, vader_string_new(s.ptr + i, 1)));
        }
    } else {
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
            vader_array_push((vader_array_t*) arr_box.payload.obj,
                             vader_box_string(str_type, vader_string_new(p, piece_len)));
            if (found == NULL) break;
            p = found + sep.len;
        }
    }
    vader_array_t* result = (vader_array_t*) arr_box.payload.obj;
    VADER_GC_POP();
    return result;
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
     * callers). The previous buf is private until finish — no aliases — so we
     * `free` it after copying the contents to the fresh allocation. */
    char* fresh = (char*) vader_string_alloc(cap);
    if (b->len > 0) memcpy(fresh, b->buf, b->len);
    free(b->buf);
    b->buf = fresh;
    b->cap = cap;
}

vader_builder_t* vader_builder_new(void) {
    /* The builder struct is purely transient — allocated, populated, then
     * `vader_builder_finish` lends out the payload buf and the struct itself
     * goes unused. Using `malloc` (not `vader_string_alloc`) lets us `free`
     * it at finish without leaking the 24-byte header. */
    vader_builder_t* b = (vader_builder_t*) malloc(sizeof(vader_builder_t));
    if (b == NULL) vader_trap("vader_builder_new: malloc failed");
    b->buf = NULL; b->len = 0; b->cap = 0;
    return b;
}

void vader_builder_append_str(vader_builder_t* b, vader_string_t s) {
    builder_reserve(b, s.len);
    memcpy(b->buf + b->len, s.ptr, s.len);
    b->len += s.len;
}

static void builder_append_fmt(vader_builder_t* b, const char* fmt, ...) {
    /* Two-pass: first call sizes the formatted output (vsnprintf returns the
     * would-have-been length), reserve the builder slot, then format
     * directly into it. Avoids the OOB-read footgun where a caller passing
     * a format that produces ≥ 64 bytes would `memcpy` past the stack
     * buffer. We still keep a small stack scratch for the common case. */
    char stack_buf[64];
    va_list ap;
    va_start(ap, fmt);
    va_list ap2;
    va_copy(ap2, ap);
    int n = vsnprintf(stack_buf, sizeof(stack_buf), fmt, ap);
    va_end(ap);
    if (n < 0) { va_end(ap2); return; }

    if ((size_t) n < sizeof(stack_buf)) {
        builder_reserve(b, (size_t) n);
        memcpy(b->buf + b->len, stack_buf, (size_t) n);
        b->len += (size_t) n;
        va_end(ap2);
        return;
    }
    /* Output didn't fit in the stack scratch — format straight into the
     * builder's own buffer at the reserved offset. */
    builder_reserve(b, (size_t) n + 1);     /* +1 for vsnprintf's trailing NUL */
    int n2 = vsnprintf(b->buf + b->len, (size_t) n + 1, fmt, ap2);
    va_end(ap2);
    if (n2 < 0) return;
    b->len += (size_t) n2;
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
    /* Lend the buffer (still owned by the string-arena leak budget — see
     * `vader_string_alloc`'s comment) and free the builder struct itself,
     * which has no other use after finish. */
    vader_string_t out = vader_string_new(b->buf, b->len);
    free(b);
    return out;
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

    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f); return vader_box_string(err_tag, vader_string_new("fseek failed", 12));
    }
    long size = ftell(f);
    if (size < 0) { fclose(f); return vader_box_string(err_tag, vader_string_new("ftell failed", 12)); }
    /* Refuse files we can't safely allocate. The `SIZE_MAX/2` headroom keeps
     * downstream `(size_t) size` arithmetic from wrapping anywhere we add a
     * small offset (e.g. NUL terminators in scratch buffers). */
    if ((unsigned long) size > SIZE_MAX / 2) {
        fclose(f); return vader_box_string(err_tag, vader_string_new("file too large", 14));
    }
    if (fseek(f, 0, SEEK_SET) != 0) {
        fclose(f); return vader_box_string(err_tag, vader_string_new("fseek failed", 12));
    }

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

/* `is_dir` / `read_dir` — directory traversal split across POSIX (`dirent.h`,
 * `sys/stat.h`) and Windows (`FindFirstFileA` / `GetFileAttributesA`). Same
 * `vader_string_alloc` discipline as the rest of the IO surface: any owned
 * char buffer escaping the function lives off the GC arena. */

#if defined(_WIN32)

vader_bool_t vader_is_dir(vader_string_t path) {
    char* p = (char*) vader_string_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    DWORD attr = GetFileAttributesA(p);
    free(p);
    return attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY);
}

vader_box_t vader_read_dir(vader_string_t path, uint32_t arr_type,
                           uint32_t str_type, uint32_t err_tag) {
    /* FindFirstFileA expects a glob — append "\\*". */
    char* pat = (char*) vader_string_alloc(path.len + 3);
    memcpy(pat, path.ptr, path.len);
    size_t pat_len = path.len;
    if (pat_len > 0 && pat[pat_len - 1] != '\\' && pat[pat_len - 1] != '/') {
        pat[pat_len++] = '\\';
    }
    pat[pat_len++] = '*';
    pat[pat_len] = '\0';

    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pat, &fd);
    free(pat);
    if (h == INVALID_HANDLE_VALUE) {
        return vader_box_string(err_tag, vader_string_new("read_dir failed", 15));
    }

    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0));
    VADER_GC_PUSH1(arr_box);
    do {
        const char* name = fd.cFileName;
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))) continue;
        size_t n = strlen(name);
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

vader_bool_t vader_is_dir(vader_string_t path) {
    char* p = (char*) vader_string_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    struct stat st;
    int rc = stat(p, &st);
    free(p);
    return rc == 0 && S_ISDIR(st.st_mode);
}

vader_box_t vader_read_dir(vader_string_t path, uint32_t arr_type,
                           uint32_t str_type, uint32_t err_tag) {
    char* p = (char*) vader_string_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    DIR* d = opendir(p);
    free(p);
    if (d == NULL) {
        return vader_box_string(err_tag, vader_string_new("read_dir failed", 15));
    }

    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0));
    VADER_GC_PUSH1(arr_box);
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        const char* name = ent->d_name;
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))) continue;
        size_t n = strlen(name);
        vader_array_push((vader_array_t*) arr_box.payload.obj,
                         vader_box_string(str_type, vader_string_new(name, n)));
    }
    closedir(d);
    vader_box_t result = arr_box;
    VADER_GC_POP();
    return result;
}

#endif  /* _WIN32 / POSIX */

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

#if defined(_WIN32)

/* Win32 spawn : pipes via CreatePipe, child via CreateProcessA. Pipes are
 * drained concurrently by two worker threads — serial reads would deadlock if
 * the child saturates one pipe buffer (~4 KB by default) while we're blocked
 * waiting on the other. */

typedef struct {
    HANDLE read_end;
    char*  buf;     /* malloc'd; caller frees */
    size_t len;
    int    failed;
} win_drain_ctx_t;

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

vader_i32_t vader_spawn_run(vader_array_t* argv) {
    if (argv == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    size_t n = vader_array_len(argv);
    if (n == 0) return VADER_SPAWN_LAUNCH_FAIL;

    /* Build the command-line string. Upper bound per arg : 2*len + 3 (quotes
     * + worst-case escape doubling + space separator). */
    size_t cap = 1;  /* terminator */
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = vader_array_get(argv, i);
        cap += b.payload.s.len * 2 + 3;
    }
    char* cmdline = (char*) malloc(cap);
    if (cmdline == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    size_t pos = 0;
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = vader_array_get(argv, i);
        vader_string_t s = b.payload.s;
        char* z = (char*) malloc(s.len + 1);
        if (z == NULL) { free(cmdline); return VADER_SPAWN_LAUNCH_FAIL; }
        memcpy(z, s.ptr, s.len); z[s.len] = '\0';
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
    if (!CreatePipe(&out_read, &out_write, &sa, 0)) {
        free(cmdline);
        return VADER_SPAWN_LAUNCH_FAIL;
    }
    if (!CreatePipe(&err_read, &err_write, &sa, 0)) {
        CloseHandle(out_read); CloseHandle(out_write);
        free(cmdline);
        return VADER_SPAWN_LAUNCH_FAIL;
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
        NULL,        /* application : NULL → parse first token of cmdline, search %PATH% */
        cmdline,
        NULL,        /* process security */
        NULL,        /* thread security */
        TRUE,        /* inherit handles (the three std redirections) */
        0,           /* creation flags */
        NULL,        /* env : inherit parent's */
        NULL,        /* cwd : inherit parent's */
        &si, &pi
    );
    free(cmdline);

    /* Parent closes the write ends — only the child holds them now. */
    CloseHandle(out_write);
    CloseHandle(err_write);

    if (!ok) {
        CloseHandle(out_read);
        CloseHandle(err_read);
        capture_spawn_output(&g_spawn_stdout_buf, &g_spawn_stdout_len, NULL, 0);
        capture_spawn_output(&g_spawn_stderr_buf, &g_spawn_stderr_len, NULL, 0);
        return VADER_SPAWN_LAUNCH_FAIL;
    }

    /* Drain both pipes concurrently to avoid the saturated-pipe deadlock. */
    win_drain_ctx_t out_ctx = { out_read, NULL, 0, 0 };
    win_drain_ctx_t err_ctx = { err_read, NULL, 0, 0 };
    HANDLE out_th = CreateThread(NULL, 0, win_drain_pipe, &out_ctx, 0, NULL);
    HANDLE err_th = CreateThread(NULL, 0, win_drain_pipe, &err_ctx, 0, NULL);

    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD exit_code = 0;
    GetExitCodeProcess(pi.hProcess, &exit_code);

    if (out_th != NULL) { WaitForSingleObject(out_th, INFINITE); CloseHandle(out_th); }
    if (err_th != NULL) { WaitForSingleObject(err_th, INFINITE); CloseHandle(err_th); }

    CloseHandle(out_read);
    CloseHandle(err_read);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    capture_spawn_output(&g_spawn_stdout_buf, &g_spawn_stdout_len, out_ctx.buf, out_ctx.len);
    capture_spawn_output(&g_spawn_stderr_buf, &g_spawn_stderr_len, err_ctx.buf, err_ctx.len);

    /* NTSTATUS abnormal-termination codes (0xC0000000+) flag a crash ; the
     * normal exit-code range is 0..0x7FFFFFFF. Map crashes onto the SIGNALED
     * sentinel so callers can distinguish them from a normal exit. */
    if ((exit_code & 0xC0000000u) == 0xC0000000u) return VADER_SPAWN_SIGNALED;
    return (vader_i32_t) (int32_t) exit_code;
}

#else  /* POSIX */

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

fail_close_both:
    close(err_pipe[0]); close(err_pipe[1]);
fail_close_out:
    close(out_pipe[0]); close(out_pipe[1]);
fail_free_cargv:
    for (size_t j = 0; j < n; j++) free(cargv[j]);
    free(cargv);
    return VADER_SPAWN_LAUNCH_FAIL;
}

#endif  /* _WIN32 / POSIX */

vader_string_t vader_spawn_last_stdout(void) {
    /* Before any spawn ran, both buf and len are 0 — hand back the empty
     * sentinel so callers can safely `memcpy` / `fwrite` zero bytes from
     * `.ptr` without dereferencing NULL. */
    return vader_string_new(g_spawn_stdout_buf != NULL ? g_spawn_stdout_buf : "",
                            g_spawn_stdout_len);
}

vader_string_t vader_spawn_last_stderr(void) {
    return vader_string_new(g_spawn_stderr_buf != NULL ? g_spawn_stderr_buf : "",
                            g_spawn_stderr_len);
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
