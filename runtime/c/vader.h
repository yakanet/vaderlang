/* Vader native runtime — public API consumed by the C emitter (§1.9).
 *
 * Memory: every allocation is leaked for MVP. The 1.11 phase adds a real
 * mark-sweep collector behind this same surface.
 *
 * Strings are fat values (ptr + len), copied at every assignment. UTF-8.
 *
 * Boxes (`vader_box_t`) carry a runtime tag that maps 1:1 to a `BcType` index
 * in the originating bytecode module. `type_check` pattern matches against
 * those tags.
 *
 * Naming: every public symbol starts with `vader_` so the emitter never
 * collides with user identifiers — emitted user fns use the bytecode mangled
 * names (`std_io$println` etc.) which can't begin with `vader_`.
 */

#ifndef VADER_H
#define VADER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ------------------------------------------------------ scalar primitives */

typedef int8_t   vader_i8_t;
typedef int16_t  vader_i16_t;
typedef int32_t  vader_i32_t;
typedef int64_t  vader_i64_t;
typedef uint8_t  vader_u8_t;
typedef uint16_t vader_u16_t;
typedef uint32_t vader_u32_t;
typedef uint64_t vader_u64_t;
typedef float    vader_f32_t;
typedef double   vader_f64_t;
typedef bool     vader_bool_t;
typedef uint32_t vader_char_t;          /* Unicode codepoint */

/* ----------------------------------------------------------------- string */

typedef struct {
    const char* ptr;
    size_t      len;
} vader_string_t;

static inline vader_string_t vader_string_new(const char* p, size_t n) {
    vader_string_t s; s.ptr = p; s.len = n; return s;
}

vader_string_t vader_string_concat(vader_string_t a, vader_string_t b);
bool           vader_string_eq(vader_string_t a, vader_string_t b);

/* ----------------------------------------------------------------- box */

/* Tag values shared with `BcType` indices from the bytecode module. The C
 * emitter drops a `VADER_BOX_TAG_*` macro per type at the top of the file. */
typedef struct {
    uint32_t tag;
    uint32_t _pad;
    union {
        vader_i64_t    i;       /* fits i8..i64 + u8..u64 + char */
        vader_f64_t    f;       /* fits f32 + f64 */
        vader_bool_t   b;
        vader_string_t s;
        void*          obj;     /* struct / array ref */
    } payload;
} vader_box_t;

/* The null tag is reserved at index 0 of every emitted module so unboxed
 * `null` slots are well-defined without consulting the type table. */
#define VADER_BOX_TAG_NULL 0u

/* Box constructors — the emitter calls these whenever a value flows into a
 * union slot. Tag is always provided (it's the BcType index). */
static inline vader_box_t vader_box_i32(uint32_t tag, vader_i32_t v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.i = (vader_i64_t)v; return bx;
}
static inline vader_box_t vader_box_i64(uint32_t tag, vader_i64_t v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.i = v; return bx;
}
static inline vader_box_t vader_box_f64(uint32_t tag, vader_f64_t v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.f = v; return bx;
}
static inline vader_box_t vader_box_bool(uint32_t tag, vader_bool_t v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.b = v; return bx;
}
static inline vader_box_t vader_box_string(uint32_t tag, vader_string_t v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.s = v; return bx;
}
static inline vader_box_t vader_box_obj(uint32_t tag, void* v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.obj = v; return bx;
}
static inline vader_box_t vader_box_null(void) {
    vader_box_t bx; bx.tag = VADER_BOX_TAG_NULL; bx._pad = 0; bx.payload.obj = NULL; return bx;
}

/* ----------------------------------------------------------------- array */

typedef struct {
    uint32_t      type_index;
    uint32_t      _pad;
    size_t        length;
    size_t        capacity;
    vader_box_t*  data;
} vader_array_t;

vader_array_t* vader_array_new(uint32_t type_index, size_t length);
size_t         vader_array_len(vader_array_t* a);
vader_box_t    vader_array_get(vader_array_t* a, size_t i);
void           vader_array_set(vader_array_t* a, size_t i, vader_box_t v);
void           vader_array_push(vader_array_t* a, vader_box_t v);

/* ----------------------------------------------------------------- struct */

/* Each emitted struct decl produces a C struct with a header and per-field
 * slots. Only the header layout is fixed by the runtime; everything else is
 * code-generated. */
typedef struct {
    uint32_t type_index;
    uint32_t _pad;
} vader_obj_header_t;

void* vader_alloc(size_t bytes);

/* ----------------------------------------------------------------- builder */

typedef struct vader_builder_s vader_builder_t;
vader_builder_t* vader_builder_new(void);
void             vader_builder_append_str(vader_builder_t* b, vader_string_t s);
void             vader_builder_append_display_i32(vader_builder_t* b, vader_i32_t v);
void             vader_builder_append_display_i64(vader_builder_t* b, vader_i64_t v);
void             vader_builder_append_display_u32(vader_builder_t* b, vader_u32_t v);
void             vader_builder_append_display_u64(vader_builder_t* b, vader_u64_t v);
void             vader_builder_append_display_f32(vader_builder_t* b, vader_f32_t v);
void             vader_builder_append_display_f64(vader_builder_t* b, vader_f64_t v);
void             vader_builder_append_display_bool(vader_builder_t* b, vader_bool_t v);
void             vader_builder_append_display_char(vader_builder_t* b, vader_char_t v);
void             vader_builder_append_display_string(vader_builder_t* b, vader_string_t v);
vader_string_t   vader_builder_finish(vader_builder_t* b);

/* ----------------------------------------------------------------- I/O */

void           vader_print(vader_string_t s);
void           vader_println(vader_string_t s);
vader_box_t    vader_read_file(vader_string_t path, uint32_t ok_tag, uint32_t err_tag);
vader_box_t    vader_write_file(vader_string_t path, vader_string_t content,
                                uint32_t ok_tag, uint32_t err_tag);
vader_box_t    vader_read_line(uint32_t ok_tag, uint32_t err_tag);
vader_bool_t   vader_exists(vader_string_t path);

/* ----------------------------------------------------------------- string */

vader_i32_t    vader_string_len(vader_string_t s);
vader_string_t vader_string_slice(vader_string_t s, vader_i32_t start, vader_i32_t end);
vader_bool_t   vader_string_contains(vader_string_t s, vader_string_t sub);
vader_bool_t   vader_string_starts_with(vader_string_t s, vader_string_t prefix);
vader_bool_t   vader_string_ends_with(vader_string_t s, vader_string_t suffix);
vader_string_t vader_string_trim(vader_string_t s);
vader_string_t vader_string_to_upper(vader_string_t s);
vader_string_t vader_string_to_lower(vader_string_t s);
/* parse_int / parse_float return a box: ok_tag on success, err_tag on failure. */
vader_box_t    vader_string_parse_int(vader_string_t s, uint32_t ok_tag, uint32_t err_tag);
vader_box_t    vader_string_parse_float(vader_string_t s, uint32_t ok_tag, uint32_t err_tag);

/* ----------------------------------------------------------------- math */

#include <math.h>

/* Wrappers that match the exact signature the emitter expects (single arg). */
static inline vader_f64_t vader_math_sqrt(vader_f64_t x)  { return sqrt(x);  }
static inline vader_f64_t vader_math_pow(vader_f64_t x, vader_f64_t n) { return pow(x, n); }
static inline vader_f64_t vader_math_floor(vader_f64_t x) { return floor(x); }
static inline vader_f64_t vader_math_ceil(vader_f64_t x)  { return ceil(x);  }
static inline vader_f64_t vader_math_round(vader_f64_t x) { return round(x); }
static inline vader_f64_t vader_math_sin(vader_f64_t x)   { return sin(x);   }
static inline vader_f64_t vader_math_cos(vader_f64_t x)   { return cos(x);   }
static inline vader_f64_t vader_math_tan(vader_f64_t x)   { return tan(x);   }

/* ----------------------------------------------------------------- traps */

#ifdef __GNUC__
__attribute__((noreturn))
#endif
void vader_unreachable(const char* where);

#ifdef __GNUC__
__attribute__((noreturn))
#endif
void vader_trap(const char* msg);

#endif /* VADER_H */
