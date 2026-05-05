/* Vader native runtime — implementation. See `vader.h` for the public API.
 *
 * MVP: every allocation leaks (no GC). 1.11 replaces this with mark-sweep.
 */

#include "vader.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

/* ----------------------------------------------------------------- alloc */

void* vader_alloc(size_t bytes) {
    void* p = malloc(bytes);
    if (p == NULL) vader_trap("vader_alloc: out of memory");
    return p;
}

/* ----------------------------------------------------------------- string */

vader_string_t vader_string_concat(vader_string_t a, vader_string_t b) {
    char* buf = (char*) vader_alloc(a.len + b.len);
    memcpy(buf,         a.ptr, a.len);
    memcpy(buf + a.len, b.ptr, b.len);
    return vader_string_new(buf, a.len + b.len);
}

bool vader_string_eq(vader_string_t a, vader_string_t b) {
    return a.len == b.len && memcmp(a.ptr, b.ptr, a.len) == 0;
}

/* ----------------------------------------------------------------- array */

vader_array_t* vader_array_new(uint32_t type_index, size_t length) {
    vader_array_t* a = (vader_array_t*) vader_alloc(sizeof(vader_array_t));
    a->type_index = type_index;
    a->_pad = 0;
    a->length = length;
    a->capacity = length > 0 ? length : 4;
    a->data = (vader_box_t*) vader_alloc(a->capacity * sizeof(vader_box_t));
    return a;
}

size_t vader_array_len(vader_array_t* a) { return a->length; }

vader_box_t vader_array_get(vader_array_t* a, size_t i) {
    if (i >= a->length) vader_trap("array index out of bounds");
    return a->data[i];
}

void vader_array_set(vader_array_t* a, size_t i, vader_box_t v) {
    if (i >= a->length) vader_trap("array index out of bounds");
    a->data[i] = v;
}

void vader_array_push(vader_array_t* a, vader_box_t v) {
    if (a->length >= a->capacity) {
        size_t cap = a->capacity == 0 ? 4 : a->capacity * 2;
        vader_box_t* fresh = (vader_box_t*) vader_alloc(cap * sizeof(vader_box_t));
        if (a->length > 0) memcpy(fresh, a->data, a->length * sizeof(vader_box_t));
        a->data = fresh;
        a->capacity = cap;
    }
    a->data[a->length++] = v;
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
    char* buf = (char*) vader_alloc(s.len);
    for (size_t i = 0; i < s.len; i++) buf[i] = (char) toupper((unsigned char) s.ptr[i]);
    return vader_string_new(buf, s.len);
}

vader_string_t vader_string_to_lower(vader_string_t s) {
    char* buf = (char*) vader_alloc(s.len);
    for (size_t i = 0; i < s.len; i++) buf[i] = (char) tolower((unsigned char) s.ptr[i]);
    return vader_string_new(buf, s.len);
}

vader_box_t vader_string_parse_int(vader_string_t s, uint32_t ok_tag, uint32_t err_tag) {
    char* p = (char*) vader_alloc(s.len + 1);
    memcpy(p, s.ptr, s.len); p[s.len] = '\0';
    char* end;
    long v = strtol(p, &end, 10);
    if (end == p || *end != '\0') {
        return vader_box_string(err_tag, vader_string_new("invalid integer", 15));
    }
    return vader_box_i32(ok_tag, (vader_i32_t) v);
}

vader_box_t vader_string_parse_float(vader_string_t s, uint32_t ok_tag, uint32_t err_tag) {
    char* p = (char*) vader_alloc(s.len + 1);
    memcpy(p, s.ptr, s.len); p[s.len] = '\0';
    char* end;
    double v = strtod(p, &end);
    if (end == p || *end != '\0') {
        return vader_box_string(err_tag, vader_string_new("invalid float", 13));
    }
    return vader_box_f64(ok_tag, v);
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
    char* fresh = (char*) vader_alloc(cap);
    if (b->len > 0) memcpy(fresh, b->buf, b->len);
    b->buf = fresh;
    b->cap = cap;
}

vader_builder_t* vader_builder_new(void) {
    vader_builder_t* b = (vader_builder_t*) vader_alloc(sizeof(vader_builder_t));
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
    char* p = (char*) vader_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    FILE* f = fopen(p, "rb");
    if (f == NULL) return vader_box_string(err_tag, vader_string_new("file not found", 14));

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size < 0) { fclose(f); return vader_box_string(err_tag, vader_string_new("ftell failed", 12)); }

    char* buf = (char*) vader_alloc((size_t) size);
    size_t n = fread(buf, 1, (size_t) size, f);
    fclose(f);
    if (n != (size_t) size) return vader_box_string(err_tag, vader_string_new("short read", 10));
    return vader_box_string(ok_tag, vader_string_new(buf, (size_t) size));
}

vader_box_t vader_write_file(vader_string_t path, vader_string_t content,
                             uint32_t ok_tag, uint32_t err_tag) {
    char* p = (char*) vader_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    FILE* f = fopen(p, "wb");
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
    char* copy = (char*) vader_alloc(n);
    memcpy(copy, buf, n);
    return vader_box_string(ok_tag, vader_string_new(copy, n));
}

vader_bool_t vader_exists(vader_string_t path) {
    char* p = (char*) vader_alloc(path.len + 1);
    memcpy(p, path.ptr, path.len); p[path.len] = '\0';
    FILE* f = fopen(p, "rb");
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
