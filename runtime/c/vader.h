/* Vader native runtime — public API consumed by the C emitter (§1.9).
 *
 * Memory: generational Cheney copying GC backs structs, arrays, fn closures.
 * See `vader_gc_*` below and the implementation header in `vader_runtime.c`
 * for the two-generation arena layout, shadow-stack root enumeration, card
 * table, and the per-module `vader_type_info_table` the scanner consults.
 *
 * String buffers (the `char*` behind every `vader_string_t`) live OUTSIDE
 * the GC arenas — a moving GC would need a back-mapping from char-ptr to
 * header on every scan, and `vader_string_t` is a fat ptr-len value copied
 * at every assignment. They're tracked separately in a non-moving mark-
 * sweep arena that runs after each Cheney cycle (see `vader_string_alloc`
 * in the implementation).
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

/* glibc gates POSIX clocks (`CLOCK_REALTIME`, `CLOCK_MONOTONIC`) and GNU
 * pthread extensions (`pthread_getattr_np`) behind feature-test macros.
 * Under `-std=c11` ISO mode neither is exposed by default. Define
 * `_GNU_SOURCE` before any system include so the runtime compiles cleanly
 * on Linux ; Darwin / BSD expose these APIs unconditionally so the macro
 * is a no-op there. */
#if defined(__linux__) && !defined(_GNU_SOURCE)
#  define _GNU_SOURCE
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Branch-prediction hints. Hot paths put `VADER_LIKELY` on the taken
 * branch and `VADER_UNLIKELY` on the trap branch ; the compiler then
 * lays out the cold path past the function epilogue and keeps the
 * hot path in-line for the I-cache. GCC and clang both accept these. */
#if defined(__GNUC__) || defined(__clang__)
#  define VADER_LIKELY(x)   __builtin_expect(!!(x), 1)
#  define VADER_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#  define VADER_LIKELY(x)   (x)
#  define VADER_UNLIKELY(x) (x)
#endif

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

/* Atom type — forward-declared here so `vader_string_t` (defined below
 * as an alias) doesn't depend on the full atom-API section further down.
 * The struct + function declarations for the table follow after the
 * box / array sections. See `docs/ATOM_INTERNING.md`. */
typedef vader_u32_t vader_atom_t;

/* ----------------------------------------------------------------- string */

/* `vader_string_t` *is* an atom id — `==` is `u32 ==`, hash is identity,
 * `data` and `len` go through `vader_atom_data` / `vader_atom_len`. The
 * legacy {ptr, len} fat-ptr layout is gone ; the runtime mark-sweep
 * arena that backed it has been removed alongside.
 *
 * The bytes behind a string atom live in the global `vader_atom_table_t`
 * (see further down). Comptime literals are PERM-flagged and never
 * collected ; runtime-minted atoms (concat, format, read_file) are
 * tracked by the Cheney major cycle's atom mark phase. */
typedef vader_atom_t vader_string_t;

vader_string_t vader_string_new(const char* p, size_t n);
vader_string_t vader_string_concat(vader_string_t a, vader_string_t b);
bool           vader_string_eq(vader_string_t a, vader_string_t b);

/* `@extern` ABI helpers — return a NUL-terminated `const char*` view of
 * the atom's bytes. For owner atoms the runtime returns `data` directly
 * (no allocation) ; for slice atoms a heap dup is returned. Caller
 * pairs every `_to_cstr` with a `_cstr_free` — the latter no-ops on
 * owner pointers and frees the dup otherwise. */
const char*    vader_string_to_cstr(vader_string_t s);
void           vader_cstr_free(const char* p);

/* ------------------------------------------------------------------ atom */

/* Atom-based string interning — see `docs/ATOM_INTERNING.md`. The
 * `vader_atom_t` typedef is declared at the top of this file because
 * `vader_string_t` is its alias ; the struct + API live here. */

/* Reserved atom id : the empty string. Always installed at index 0 by
 * `vader_atom_init` and flagged PERM. Tests can compare directly against
 * this constant rather than interning `""`. */
#define VADER_ATOM_EMPTY  ((vader_atom_t) 0u)

/* Entry flags — packed into `vader_atom_entry_t.flags`. */
#define VADER_ATOM_FLAG_PERM  ((vader_u16_t) 0x0001u)  /* never collected */
#define VADER_ATOM_FLAG_MARK  ((vader_u16_t) 0x0002u)  /* transient GC bit */

/* Layout : 24 bytes on 64-bit (4 + 4 + 4 + 2 + 2 + 8). The `data` field
 * is materialised at insert time — for an owner atom it points at a
 * dedicated malloc'd buffer ; for a slice atom it points into the parent's
 * buffer at `parent_offset`. Owner buffers carry an inline NUL at
 * `data[len]` so `vader_atom_to_cstr` can return `data` directly without
 * a dup ; slice atoms do not provide that guarantee. */
typedef struct {
    vader_u32_t parent;          /* 0 if owner, else parent atom id */
    vader_u32_t parent_offset;   /* byte offset within parent.data (slice only) */
    vader_u32_t len;             /* string length in bytes */
    vader_u16_t flags;           /* VADER_ATOM_FLAG_* */
    vader_u16_t _pad;
    const char* data;            /* materialised pointer (owner buf or parent.data + offset) */
} vader_atom_entry_t;

/* Lookup helpers — inline, hot path. Bounds-checking on the atom id is
 * the caller's responsibility ; an invalid id reads garbage. */
const vader_atom_entry_t* vader_atom_entry(vader_atom_t a);
const char*               vader_atom_data(vader_atom_t a);
size_t                    vader_atom_len(vader_atom_t a);

/* Intern canonical bytes — returns the atom whose bytes equal `data[0..len]`.
 * On a hash miss, copies the bytes into a fresh owner buffer.
 *
 * `_take` variant : on miss, transfers ownership of the passed buffer
 *  into the new entry (no extra copy). The buffer MUST be malloc'd with
 *  `len + 1` bytes ; the runtime writes `buf[len] = '\0'` for the inline
 *  NUL contract. On hit, `_take` frees the passed buffer and returns the
 *  canonical atom. Phase 0 stubs return VADER_ATOM_EMPTY until the
 *  intern table is implemented in 0.b. */
vader_atom_t vader_atom_intern(const char* data, size_t len);
vader_atom_t vader_atom_intern_take(char* buf, size_t len);

/* Slice — installs (or finds) an atom whose bytes equal
 * `entry(parent).data[offset..offset+len]`. Dedupe runs against the
 * existing hash bucket ; on a hit, returns the canonical atom regardless
 * of its ownership (which may itself be an owner). Phase 0 stub. */
vader_atom_t vader_atom_slice(vader_atom_t parent, size_t offset, size_t len);

/* FFI helper — returns a NUL-terminated `const char*` view of the atom's
 * bytes. Owners return their `data` directly (no allocation). Slices
 * allocate a duplicated NUL-terminated copy ; pair every slice call with
 * `vader_atom_cstr_free`. The owner path returns a stable pointer that
 * remains valid until the atom is collected. */
const char* vader_atom_to_cstr(vader_atom_t a);
void        vader_atom_cstr_free(const char* p);

/* Lifecycle — `vader_atom_init` installs `VADER_ATOM_EMPTY` and prepares
 * an empty dynamic table. `vader_atom_init_with_comptime` additionally
 * copies a codegen-emitted block of compile-time atoms (typically the
 * module's string literal pool) into the table and rehashes them. The
 * codegen wires the latter into the emitted `main` ; tests / tools that
 * don't care about comptime atoms call the bare `_init`.
 *
 * `comptime_table` is a constant array of `count` entries — typically a
 * `.rodata` static emitted at the top of the user `.c`. The runtime
 * memcpys into its own dynamic storage so the user-side array does not
 * have to outlive program startup ; the byte buffers each entry points
 * at do need to remain valid for the program lifetime (the codegen
 * emits them as `.rodata` next to the entry array).
 *
 * `vader_atom_shutdown` releases owner buffers allocated *after* init
 * — comptime-supplied buffers are NOT freed (they live in `.rodata`).
 * Intended for tests / tools wanting a clean teardown ; the normal
 * program exit path leaks freely. */
void vader_atom_init(void);
void vader_atom_init_with_comptime(const vader_atom_entry_t* comptime_table, vader_u32_t count);
void vader_atom_shutdown(void);

/* Profiling — emitted to stderr when `VADER_ATOM_PROFILE=1` is set in
 * the environment at program start. Reports atom count, byte total
 * (owner buffers), bucket load factor, and the top-N most-referenced
 * atoms. Called automatically at exit via `atexit` when the env var is
 * set ; can also be called manually from tests. */
void vader_atom_profile_dump(void);

/* GC hook — invoked by the major Cheney cycle. Marks atoms reachable
 * from the shadow stack, defer stack, and live heap objects (using
 * `vader_type_info.string_offsets[]` for precision and a conservative
 * pass over `ptr_offsets[]` boxes), then sweeps unmarked non-PERM
 * atoms : frees their owner buffer and tombstones the slot for reuse
 * by the next `vader_atom_intern`. */
void vader_atom_gc_collect(void);

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
        /* Multi-field POD packed payload. `vader_string_t` already makes
         * this union 16 bytes wide, so the new view costs nothing. The C
         * emit overlays a header-less mirror struct
         * (`struct vader_packed_<name>_t`) at byte offset 0 of this
         * array to read/write fields with natural C layout. */
        uint8_t        packed[16];
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
    /* Zero the 8-byte obj alias first so `vader_box_eq`'s `payload.obj ==`
     * compare doesn't read garbage from the upper 4 bytes — `vader_string_t`
     * is a u32 atom and only writes the low 4. */
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.obj = NULL; bx.payload.s = v; return bx;
}
static inline vader_box_t vader_box_obj(uint32_t tag, void* v) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0; bx.payload.obj = v; return bx;
}
static inline vader_box_t vader_box_null(void) {
    vader_box_t bx; bx.tag = VADER_BOX_TAG_NULL; bx._pad = 0; bx.payload.obj = NULL; return bx;
}

/* Identity equality between two boxes — tag plus the raw 8-byte payload slot
 * (which aliases every union member, so it covers refs, primitives, and
 * string fat-ptrs that occupy the first word). Emitted by the C codegen for
 * `ref.eq` / `ref.ne` because direct `==` on a `vader_box_t` struct is not
 * legal C. */
static inline bool vader_box_eq(vader_box_t a, vader_box_t b) {
    return a.tag == b.tag && a.payload.obj == b.payload.obj;
}

/* B1 (nullable-ref inline rep) helpers — used at fn signature boundaries
 * when a `T | null` union with T a single heap struct flows through. The
 * value passes as a raw `void*` (NULL = null variant, non-NULL = ref to
 * T) instead of a 24-byte `vader_box_t`. The two helpers below shift
 * between the wire form and the boxed form at the call boundary. */
static inline vader_box_t vader_b1_to_box(void* p, uint32_t variant_tag) {
    return p == NULL ? vader_box_null() : vader_box_obj(variant_tag, p);
}
static inline void* vader_box_to_b1(vader_box_t b) {
    /* Null-variant tags (or any non-ref payload) collapse to NULL ;
     * non-null variants forward their object pointer. */
    return (b.tag == VADER_BOX_TAG_NULL) ? NULL : b.payload.obj;
}

/* ----------------------------------------------------------------- struct */

/* Each emitted struct decl produces a C struct with a header and per-field
 * slots. Only the header layout is fixed by the runtime; everything else is
 * code-generated.
 *
 * GC convention (generational Cheney copying):
 *   - `type_index` identifies the layout (size + pointer offsets) via the
 *     per-module type info table emitted alongside.
 *   - `age` counts the number of minor cycles the object has survived in
 *     the young generation. Once it reaches VADER_TENURE_AGE the next minor
 *     promotes the object to the old generation.
 *   - `mark` is reserved for future use (string-GC currently keeps its own
 *     mark bit on its arena headers).
 *   - `forward` is NULL for live objects in from-space and non-NULL when the
 *     object has been copied to to-space during a collection. The GC walks
 *     forwards transparently when scanning roots. */
typedef struct {
    uint32_t type_index;
    uint8_t  age;
    uint8_t  mark;
    uint16_t _reserved;
    void*    forward;
} vader_obj_header_t;

static inline void vader_obj_header_init(void* obj, uint32_t type_index) {
    vader_obj_header_t* h = (vader_obj_header_t*) obj;
    h->type_index = type_index;
    h->age        = 0;
    h->mark       = 0;
    h->_reserved  = 0;
    h->forward    = NULL;
}

/* ----------------------------------------------------------------- array */

/* Element-storage discriminator. Primitive arrays store raw values (1-8 byte
 * slots) so a `u32[64]` lookup table fits in 4 cache lines instead of 16
 * once unboxed. `BOXED` arrays keep one `vader_box_t` per slot for refs /
 * unions / structs. */
typedef enum {
    VADER_ARRAY_KIND_BOXED = 0,
    VADER_ARRAY_KIND_U8    = 1,
    VADER_ARRAY_KIND_U16   = 2,
    VADER_ARRAY_KIND_U32   = 3,
    VADER_ARRAY_KIND_U64   = 4,
    VADER_ARRAY_KIND_I8    = 5,
    VADER_ARRAY_KIND_I16   = 6,
    VADER_ARRAY_KIND_I32   = 7,
    VADER_ARRAY_KIND_I64   = 8,
    VADER_ARRAY_KIND_F32   = 9,
    VADER_ARRAY_KIND_F64   = 10,
    VADER_ARRAY_KIND_CHAR  = 11,
    VADER_ARRAY_KIND_BOOL  = 12,
} vader_array_kind_t;

static inline size_t vader_array_element_size(uint8_t kind) {
    switch (kind) {
        case VADER_ARRAY_KIND_BOXED: return sizeof(vader_box_t);
        case VADER_ARRAY_KIND_U8:    /* fallthrough */
        case VADER_ARRAY_KIND_I8:    /* fallthrough */
        case VADER_ARRAY_KIND_BOOL:  return 1;
        case VADER_ARRAY_KIND_U16:   /* fallthrough */
        case VADER_ARRAY_KIND_I16:   return 2;
        case VADER_ARRAY_KIND_U32:   /* fallthrough */
        case VADER_ARRAY_KIND_I32:   /* fallthrough */
        case VADER_ARRAY_KIND_F32:   /* fallthrough */
        case VADER_ARRAY_KIND_CHAR:  return 4;
        case VADER_ARRAY_KIND_U64:   /* fallthrough */
        case VADER_ARRAY_KIND_I64:   /* fallthrough */
        case VADER_ARRAY_KIND_F64:   return 8;
        default: return sizeof(vader_box_t);   /* unreachable, defensive */
    }
}

/* Array data buffer — a separate GC object so `push` can reallocate without
 * breaking aliases to the array header. The buf carries its own
 * `element_kind` so the GC scanner can decide whether to walk slots for refs
 * (BOXED) or skip them entirely (primitive). */
struct vader_array_buf;

typedef struct {
    vader_obj_header_t       header;
    size_t                   length;
    size_t                   capacity;
    /* First buf slot this array exposes. Zero for fresh arrays ; non-zero
     * for slice views that share the parent's buf. `offset + length`
     * never exceeds `buf->length`. */
    size_t                   offset;
    struct vader_array_buf*  buf;
} vader_array_t;

/* `capacity` / `length` are mirrored from the parent vader_array_t — the
 * GC needs them at scan time and there's no back-pointer to the array.
 * `slots` is byte-typed ; the actual width is `element_size(element_kind)`.
 *
 * `element_tag` is the BcType index of the array's static element type. For
 * BOXED kind the per-slot box already carries its own tag (one slot may hold
 * different concrete types under an `Any[]` view) ; element_tag is unused.
 * For primitive kinds (I32, F64, BOOL, ...) all elements share the same tag —
 * `vader_array_load_slot` stamps it onto the returned box so virtual-dispatch
 * call sites that observe the array through an erased `Any[]` view get a
 * properly-tagged receiver. */
typedef struct vader_array_buf {
    vader_obj_header_t       header;
    size_t                   capacity;
    size_t                   length;
    uint32_t                 element_tag;
    uint8_t                  element_kind;
    uint8_t                  _pad[3];
    uint8_t                  slots[];
} vader_array_buf_t;

/* Typed slot access for the BOXED case. Primitive arrays use direct casts
 * `((uint32_t*)buf->slots)[i]` etc. at the access site. */
static inline vader_box_t* vader_array_box_slots(vader_array_buf_t* buf) {
    return (vader_box_t*) (void*) buf->slots;
}

/* Sentinel index for buffers — distinct from any user BcType. The scan loop
 * dispatches on it because the type info table doesn't carry a static layout
 * for variable-length objects. */
#define VADER_TYPE_INDEX_ARRAY_BUF UINT32_C(0xFFFFFFFE)

vader_array_t* vader_array_new(uint32_t type_index, size_t length, uint8_t element_kind, uint32_t element_tag);
vader_box_t    vader_array_get(vader_array_t* a, size_t i);
void           vader_array_set(vader_array_t* a, size_t i, vader_box_t v);
void           vader_array_push(vader_array_t* a, vader_box_t v);
/* Zero-copy view into `a[lo..hi)`. The returned array shares `a->buf` ;
 * pushing into the view detaches into a fresh buf so concurrent views
 * don't see the growth. Bounds are clamped (lo to `[0,len]`, hi to
 * `[lo,len]`). */
vader_array_t* vader_array_slice(vader_array_t* a, size_t lo, size_t hi);

/* `len` is hot enough — and trivial enough — to live in the header so
 * every translation unit can fold the indirection. Callers usually
 * follow `len()` with an iteration whose bounds the compiler can then
 * keep in registers. */
static inline size_t vader_array_len(vader_array_t* a) { return a->length; }

/* Generational Cheney copying GC.
 *
 * Two generations: a small young (Eden + Survivor) collected often by minor
 * cycles, and a larger old collected rarely by major cycles. Each generation
 * is its own Cheney semi-space pair, so the algorithmic core stays uniform.
 * Allocation always lands in young from-space; on minor, surviving objects
 * are forwarded to young to-space (or promoted to old once they've reached
 * `VADER_TENURE_AGE`). A major runs a minor first to drain young, then
 * Cheney-collects old. Roots are enumerated via the shadow stack emitted by
 * the C codegen (see `vader_gc_frame_t` below).
 *
 * Cross-generation references from old to young are tracked by a card
 * table: every write of a pointer field into an old object marks the card
 * containing that object, so the next minor scans only marked cards as
 * additional roots instead of the entire old space. */

/* Heap sizing — tunable at compile time via `-D` flags. */
#ifndef VADER_GC_YOUNG_BYTES
#define VADER_GC_YOUNG_BYTES (16u * 1024u * 1024u)   /* 16 MB per young semi-space */
#endif
#ifndef VADER_GC_OLD_BYTES
#define VADER_GC_OLD_BYTES   (64u * 1024u * 1024u)   /* 64 MB per old semi-space */
#endif
#ifndef VADER_TENURE_AGE
#define VADER_TENURE_AGE     2u                      /* minor cycles before promotion */
#endif
#ifndef VADER_CARD_BYTES
#define VADER_CARD_BYTES     512u                    /* one card per 512 bytes of old */
#endif

void vader_gc_init(void);
void vader_gc_shutdown(void);

/* Run a full collection (minor + Cheney on old). Exposed to user Vader code
 * via the `runtime.collect()` intrinsic, and used by stress tests that want
 * to force reclamation between allocations. */
void vader_gc_collect(void);

/* Minor: collect the young generation only, using the shadow stack and any
 * marked cards in old as roots. Promotes survivors that have aged past
 * `VADER_TENURE_AGE` into old. */
void vader_minor_collect(void);

/* Major: drain young (via a minor) then Cheney-collect old. Triggered when
 * promotion would overflow old, and when the user explicitly calls collect. */
void vader_major_collect(void);

/* Allocate `bytes` from the young from-space. May trigger a minor collection
 * if young is full, and a major if promotion during that minor would overflow
 * old. Returned memory is uninitialised — caller is responsible for writing
 * the header (when the allocation represents a typed object).
 *
 * Used by the C emit for typed allocations (structs, fn objects). For arrays,
 * see `vader_array_new` which lays out the struct + initial buf in a single
 * call and writes the headers. Strings stay off the GC arena entirely
 * (see `vader_string_alloc` in the implementation). */
void* vader_gc_alloc(size_t bytes);

/* Card-table write barrier — called by the C-emit after every store of a
 * pointer-bearing field into a heap object. No-op for objects outside the
 * old generation (young objects can freely point anywhere; minor scans
 * young fully). Inlined as a macro so the hot path is two loads + a compare
 * + an optional byte store. */
extern uint8_t*   vader_card_table;
extern uintptr_t  vader_old_base;
extern uintptr_t  vader_old_end;

#define VADER_WRITE_BARRIER(obj) do {                                          \
    uintptr_t __vb = (uintptr_t)(obj);                                         \
    if (__vb >= vader_old_base && __vb < vader_old_end) {                      \
        vader_card_table[(__vb - vader_old_base) / VADER_CARD_BYTES] = 1u;     \
    }                                                                          \
} while (0)

/* Stats — exposed for tests / `runtime_gc_stats()` in stdlib. */
typedef struct {
    size_t arena_size;        /* size of each old semi-space, in bytes */
    size_t bytes_used;        /* live bytes across young+old (post-collection) */
    size_t total_collections; /* full + minor cycles run since process start */
    size_t total_copied;      /* cumulative bytes copied across all cycles */
} vader_gc_stats_t;
vader_gc_stats_t vader_gc_get_stats(void);

/* Type information for the GC scanner. Indexed by `vader_obj_header_t.type_index`
 * (which is the same index space as `vader_box_t.tag` and the BcType table).
 *
 * The C emit generates a per-module `vader_type_info_table[]` whose entries
 * describe each BcType: its allocation kind, the size of an instance (for
 * heap kinds), and the byte offsets of `vader_box_t` (or other reference)
 * fields inside the object that the GC must scan and possibly forward. */
typedef enum {
    VADER_TYPE_KIND_NONE        = 0,   /* primitive / non-heap, or inline-variant struct
                                          with empty / primitive payload (lives entirely
                                          inside vader_box_t — the GC skips the slot). */
    VADER_TYPE_KIND_STRUCT      = 1,
    VADER_TYPE_KIND_ARRAY       = 2,   /* vader_array_t — single ref to its buf */
    VADER_TYPE_KIND_FN          = 3,
    VADER_TYPE_KIND_INLINE_REF  = 4,   /* inline-variant wrapper struct with one ref
                                          field. `vader_box_t.payload.obj` IS the
                                          referent (not a pointer to a wrapper); the
                                          GC traces it via `scan_raw` using the
                                          referent's own type tag from its header. */
} vader_type_kind_t;

typedef struct {
    vader_type_kind_t   kind;
    size_t              size;          /* sizeof(object) incl. header; 0 if non-heap */
    const uint16_t*     ptr_offsets;   /* byte offsets of vader_box_t fields */
    uint16_t            ptr_count;
    uint16_t            string_count;  /* byte offsets count of raw vader_string_t fields */
    const uint16_t*     string_offsets;/* byte offsets of raw vader_string_t fields */
    /* `T | null` fields stored as a raw `void*` (NULL = null variant, non-null
     * = pointer to the T variant's vader_obj_header_t). Saves 16 B per field
     * vs the equivalent vader_box_t slot. The GC scans these via
     * `vader_gc_scan_raw` ; they may also be NULL, which the helper handles. */
    uint16_t            ref_count;
    const uint16_t*     ref_offsets;
} vader_type_info_t;

/* Provided by the per-module C emit. The runtime reads it via these externs. */
extern const vader_type_info_t  vader_type_info_table[];
extern const size_t             vader_type_info_count;

/* ------------------------------------------------------------------ vtable
 *
 * Per-tag method dispatch table used by `Any` method calls and (post Phase 2)
 * by the erasure pass for trait method dispatch on generic params. Two
 * separate index spaces meet here:
 *   - TAGS  index `vader_vtable_table[]` and identify the receiver's
 *     concrete type. Tag values are `BcType` indices, same as in box headers.
 *     `vader_vtable_table[0]` is reserved for the null tag and is always NULL.
 *   - SLOTS index `vader_vtable_t.slots[]` and identify a trait method
 *     within a vtable. Slot assignment is deterministic via the typecheck's
 *     `TraitSlotRegistry` (`src/typecheck/trait-slots.ts`). Stdlib trait
 *     methods are pinned: `Hash.hash`=0, `Equals.equals`=1, `Ord.compare`=2,
 *     `Display.display`=3. User-defined trait methods start at slot 8,
 *     sorted alphabetically.
 *
 * Unimplemented (type, trait) pairs leave the slot as NULL. The typecheck
 * guarantees no well-typed code calls through a NULL slot — bound checks on
 * `Any` method calls ensure the receiver's tag implements the trait whose
 * method is being dispatched. */

#define VADER_MAX_TRAIT_SLOTS 64u

typedef struct {
    void* slots[VADER_MAX_TRAIT_SLOTS];
} vader_vtable_t;

/* Provided by the per-module C emit. `vader_vtable_table[tag]` returns the
 * vtable for the type with that tag, or NULL if the type registered no
 * trait impls. */
extern const vader_vtable_t* const vader_vtable_table[];
extern const size_t                vader_vtable_count;

/* Resolve a trait-method function pointer for a runtime tag. Returns NULL
 * if the type has no vtable or the slot is unfilled — callers are expected
 * to be typecheck-protected, so a NULL return signals a compiler bug. */
static inline void* vader_virtual_dispatch(uint32_t tag, uint32_t slot) {
    if (VADER_UNLIKELY(tag >= vader_vtable_count)) return NULL;
    const vader_vtable_t* vt = vader_vtable_table[tag];
    if (VADER_UNLIKELY(vt == NULL)) return NULL;
    return vt->slots[slot];
}

/* Shadow stack frame — emitted at the entry of every C function generated by
 * the C emit. The frame chains through `prev` to form the precise root list
 * the GC walks at collection time.
 *
 * Indirect layout: each frame holds a `ptrs` array pointing to the calling
 * C function's ref-typed locals/tmps. This avoids restructuring the body's
 * local naming (locals stay as `lN`/`tN`) at the cost of one extra
 * dereference per root during scanning. The address-taken locals are pinned
 * to the C stack, which is what we need for precise GC anyway. */
typedef struct vader_gc_frame {
    struct vader_gc_frame* prev;
    uint32_t               nrefs;
    uint32_t               _pad;
    vader_box_t**          ptrs;
} vader_gc_frame_t;

extern vader_gc_frame_t* vader_gc_top;

/* Push a one-slot shadow-stack frame around a `vader_box_t` on the C stack.
 * Used by runtime helpers that allocate (and thus may collect) after binding
 * a fresh ref. Pair with `VADER_GC_POP()` on every return path. The block
 * scopes `__roots`/`__frame` so multiple pushes nest cleanly. */
#define VADER_GC_PUSH1(box_lvalue)                                               \
    vader_box_t* __roots[1] = { &(box_lvalue) };                                 \
    vader_gc_frame_t __frame = { vader_gc_top, 1u, 0u, __roots };                \
    vader_gc_top = &__frame
#define VADER_GC_POP() (vader_gc_top = __frame.prev)

/* ----------------------------------------------------------------- fn */

/* Function value — fat pointer `{ code, env }`. Pushed by `fn.ref`, consumed
 * by `call.indirect`. `env == NULL` for non-capturing global fn refs; closures
 * (Phase 3) will allocate an env struct and store a pointer to it.
 *
 * `code` always points to a function whose first parameter is `void* env`,
 * even when the underlying fn doesn't use it — the C emitter generates a
 * trampoline per fn that drops the env arg and forwards to the user fn. */
typedef struct {
    vader_obj_header_t header;
    void*              code;
    void*              env;
} vader_fn_t;

/* ----------------------------------------------------------------- defer
 *
 * Single-track defer model — every `defer X` lowers to a `defer.push`
 * that appends a closure to the global defer-stack, and every normal
 * exit (return / break / continue / block fall-through) emits a
 * matching `defer.pop_exec N` that drains and executes the last N
 * entries in LIFO order. The GC scan treats the stack as a root so
 * captures stay live between push and pop_exec.
 *
 * MVP : panic-unwind is NOT wired on the C target — `vader_trap` skips
 * the defer-stack and exits the process directly. The VM target (TS
 * + Vader self-host) does unwind. The discrepancy is tracked alongside
 * the setjmp/longjmp work in TODO §3.8 "defer unwinds on panic". */
void vader_defer_push(vader_box_t closure);
void vader_defer_pop_exec(uint32_t count);

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

void           vader_write(int32_t stream_tag, vader_string_t s);
vader_box_t    vader_read_file(vader_string_t path, uint32_t ok_tag, uint32_t err_tag);
vader_box_t    vader_write_file(vader_string_t path, vader_string_t content,
                                uint32_t ok_tag, uint32_t err_tag);
vader_box_t    vader_read_line(uint32_t ok_tag, uint32_t err_tag);
vader_bool_t   vader_exists(vader_string_t path);
vader_bool_t   vader_is_dir(vader_string_t path);
/* Read EXACTLY `n` bytes from stdin into a fresh string. Boxes the result
 * (success or `Error`). EOF before `n` bytes is reported as an error —
 * the LSP transport's Content-Length framing relies on this contract. */
vader_box_t    vader_read_stdin(size_t n, uint32_t ok_tag, uint32_t err_tag);
/* `read_dir` lists the immediate entries of `path` as a `[string]`. Entries
 * are returned in OS-provided order (POSIX `readdir`, Windows `FindNextFileA`)
 * minus `.` and `..`. On failure, boxes an Error variant carrying a short
 * diagnostic string. */
vader_box_t    vader_read_dir(vader_string_t path, uint32_t arr_type,
                              uint32_t str_type, uint32_t err_tag);

/* ----------------------------------------------------------------- process
 * `spawn_run` blocks on the child, stashes captured stdout/stderr into
 * runtime-owned buffers, and returns the exit status (>= 0) or one of the
 * negative sentinels below. `spawn_last_stdout/_stderr` surface those
 * buffers as `vader_string_t`. Non-reentrant — last call wins. The Vader
 * wrapper in `std/process` glues all three into a `ProcessResult`. */

#define VADER_SPAWN_LAUNCH_FAIL (-1)
#define VADER_SPAWN_SIGNALED    (-2)

vader_i32_t    vader_spawn_run(vader_array_t* argv);
vader_string_t vader_spawn_last_stdout(void);
vader_string_t vader_spawn_last_stderr(void);

/* ----------------------------------------------------------------- string */

size_t         vader_string_byte_len(vader_string_t s);
vader_string_t vader_string_slice(vader_string_t s, size_t start, size_t end);
vader_bool_t   vader_string_contains(vader_string_t s, vader_string_t sub);
vader_bool_t   vader_string_starts_with(vader_string_t s, vader_string_t prefix);
vader_bool_t   vader_string_ends_with(vader_string_t s, vader_string_t suffix);
vader_string_t vader_string_trim(vader_string_t s);
vader_string_t vader_string_to_upper(vader_string_t s);
vader_string_t vader_string_to_lower(vader_string_t s);
/* parse_int / parse_float return a box: ok_tag on success, err_tag on failure. */
vader_box_t    vader_string_parse_int(vader_string_t s, uint32_t ok_tag, uint32_t err_tag);
vader_box_t    vader_string_parse_float(vader_string_t s, uint32_t ok_tag, uint32_t err_tag);
vader_char_t   vader_string_char_at(vader_string_t s, size_t i);
vader_u8_t     vader_string_byte_at(vader_string_t s, size_t i);
/* Codepoint-indexed counterparts. `vader_string_codepoint_at` traps
 * on OOB ; `vader_string_slice_codepoints` clamps. Both walk UTF-8
 * from the start (O(n) in the target index). */
vader_char_t   vader_string_codepoint_at(vader_string_t s, size_t cp_index);
vader_string_t vader_string_slice_codepoints(vader_string_t s, size_t cp_lo, size_t cp_hi);
vader_u64_t    vader_string_hash(vader_string_t s);
vader_string_t vader_string_concat_all(vader_array_t* parts);
vader_array_t* vader_string_split(vader_string_t s, vader_string_t sep,
                                  uint32_t arr_type, uint32_t str_type);

/* Process-level argv plumbing — emitted `main` calls this to materialise its
 * `[string]` argument from the host argv. */
vader_array_t* vader_runtime_argv(int argc, char** argv,
                                  uint32_t arr_type, uint32_t str_type);

/* ----------------------------------------------------------------- time */

#include <time.h>

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#endif

/* Wall-clock milliseconds since the Unix epoch. POSIX takes
 * `clock_gettime(CLOCK_REALTIME)` ; Windows reads
 * `GetSystemTimePreciseAsFileTime` which counts 100-ns ticks from
 * 1601-01-01 (subtract the 11_644_473_600 second offset to reach
 * the Unix epoch). */
static inline vader_i64_t vader_clock_realtime_ms(void) {
#ifdef _WIN32
    FILETIME ft;
    GetSystemTimePreciseAsFileTime(&ft);
    /* 100-ns ticks since 1601 -> ms since 1970. */
    vader_i64_t ticks = ((vader_i64_t) ft.dwHighDateTime << 32) | (vader_i64_t) ft.dwLowDateTime;
    return ticks / 10000 - 11644473600000LL;
#else
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (vader_i64_t) ts.tv_sec * 1000 + (vader_i64_t) (ts.tv_nsec / 1000000);
#endif
}

/* Monotonic nanoseconds since an arbitrary process-stable epoch. POSIX
 * routes through `CLOCK_MONOTONIC` ; Windows uses
 * `QueryPerformanceCounter` scaled by the cached tick frequency. */
static inline vader_i64_t vader_clock_monotonic_ns(void) {
#ifdef _WIN32
    static LARGE_INTEGER freq = { .QuadPart = 0 };
    if (freq.QuadPart == 0) {
        QueryPerformanceFrequency(&freq);
    }
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    /* Avoid `now * 1_000_000_000` overflow by splitting via the
     * frequency divisor — preserves resolution to the granularity
     * of the underlying counter (~100 ns on modern Intel/AMD). */
    vader_i64_t whole_sec_ns = (vader_i64_t) (now.QuadPart / freq.QuadPart) * 1000000000;
    vader_i64_t remainder = (vader_i64_t) (now.QuadPart % freq.QuadPart);
    vader_i64_t sub_sec_ns = (remainder * 1000000000) / freq.QuadPart;
    return whole_sec_ns + sub_sec_ns;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (vader_i64_t) ts.tv_sec * 1000000000 + (vader_i64_t) ts.tv_nsec;
#endif
}

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

#ifdef __GNUC__
__attribute__((noreturn))
#endif
void vader_panic(vader_string_t msg);

#endif /* VADER_H */
