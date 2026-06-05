/* Vader native runtime — implementation. See `vader.h` for the public API.
 *
 * Memory model: generational Cheney copying GC. Two generations (young, old);
 * each is itself a pair of Cheney semi-spaces. `vader_gc_alloc` bumps the
 * young from-space; on overflow, `vader_minor_collect` copies young survivors
 * to young to-space (or to old if their `age` has reached the tenure
 * threshold). When promotion would overflow old, a `vader_major_collect`
 * drains young into old, then Cheney-collects old itself. Cross-generation
 * references are tracked by a card table written from the C-emit-issued
 * `VADER_WRITE_BARRIER` macro and consumed as additional roots by minor.
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
#  include <io.h>      /* _setmode, _fileno */
#  include <fcntl.h>   /* _O_BINARY */
#else
#  include <pthread.h> /* pthread_get_stackaddr_np / pthread_attr_getstack */
#  include <spawn.h>
#  include <sys/wait.h>
#  include <unistd.h>
extern char** environ;
#endif

/* ----------------------------------------------------------------- vtable
 *
 * Weak fallback definitions for the per-module vtable globals declared in
 * `vader.h`. Empty by default; the C emit will override with strong
 * symbols once it learns to emit vtables (Phase 0 task P0-3). Until then,
 * `vader_virtual_dispatch` returns NULL for every tag — safe because no
 * existing code calls it. */
__attribute__((weak)) const vader_vtable_t* const vader_vtable_table[1] = { NULL };
__attribute__((weak)) const size_t                vader_vtable_count    = 0;

/* ----------------------------------------------------------------- defer
 *
 * Global LIFO of pending `defer` closures. The C-emit appends to it via
 * `vader_defer_push` at every `defer X` site, then drains the last N
 * entries via `vader_defer_pop_exec` at each normal exit (return /
 * break / continue / block fall-through).
 *
 * GC roots — every entry's `payload.obj` is a `vader_fn_t*` whose env
 * pointer captures heap-promoted cells. The GC's frame-walking scan
 * also walks the defer stack so captures stay live between push and
 * exec.
 *
 * Panic-unwind status : the VM targets (TS + Vader self-host) drain the
 * defer stack when an op traps, before propagating the panic. The C
 * target does NOT — `vader_trap` exits the process directly without
 * draining. Closing that gap needs setjmp at fn entry + longjmp from
 * `vader_trap`, tracked in TODO §3.8. */
static vader_box_t* g_defer_stack = NULL;
static size_t       g_defer_len   = 0;
static size_t       g_defer_cap   = 0;

void vader_defer_push(vader_box_t closure) {
    if (g_defer_len == g_defer_cap) {
        size_t new_cap = g_defer_cap == 0 ? 16u : g_defer_cap * 2u;
        vader_box_t* new_stack = (vader_box_t*) realloc(g_defer_stack, new_cap * sizeof(vader_box_t));
        if (new_stack == NULL) vader_trap("vader_defer_push: realloc failed");
        g_defer_stack = new_stack;
        g_defer_cap   = new_cap;
    }
    g_defer_stack[g_defer_len++] = closure;
}

void vader_defer_pop_exec(uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        if (g_defer_len == 0u) vader_trap("vader_defer_pop_exec: stack underflow");
        vader_box_t c = g_defer_stack[--g_defer_len];
        vader_fn_t* fn = (vader_fn_t*) c.payload.obj;
        /* The defer thunk's lifted fn signature is `fn(env) -> void`. We
         * cast through a function pointer with the matching ABI ;
         * `vader_fn_erased_sig_0_t` from the per-module emit lines up
         * here (it returns vader_box_t, but the thunk's wrapper returns
         * a `null`-tagged box that we discard). */
        ((vader_box_t (*)(void*)) fn->code)(fn->env);
    }
}

/* ----------------------------------------------------------------- gc arena */

#define VADER_GC_ALIGN 8u

typedef struct {
    char* base;
    char* cur;
    char* end;
} vader_arena_t;

/* A generation is just a pair of semi-spaces. Both pairs are backed by a
 * single contiguous malloc per generation so the card table can index by
 * `(ptr - base) / VADER_CARD_BYTES` without worrying about the swap. */
typedef struct {
    vader_arena_t from;
    vader_arena_t to;
    char*         block;        /* malloc'd contiguous backing — span both semi-spaces */
    size_t        half_bytes;   /* size of one semi-space */
} vader_gen_t;

static vader_gen_t g_young = { {NULL,NULL,NULL}, {NULL,NULL,NULL}, NULL, 0 };
static vader_gen_t g_old   = { {NULL,NULL,NULL}, {NULL,NULL,NULL}, NULL, 0 };

static int           g_gc_initialized = 0;
static size_t        g_total_collections = 0;
static size_t        g_total_copied = 0;

/* Stress mode — set via `VADER_GC_STRESS=1`. When enabled, every
 * `vader_gc_alloc` triggers a minor collect (and the string sweep that
 * runs at minor end). Forces every safepoint to exercise the full
 * shadow-stack walk + conservative C-stack scan + string mark, which
 * turns intermittent rooting bugs into deterministic failures. Off by
 * default: the 100×–10000× slowdown is reserved for debugging sessions.
 * Captured once on init; the env var has no effect mid-run. */
static int g_gc_stress = 0;

/* Current cycle. Drives both `vader_gc_forward` (which arena to copy into)
 * and the collection counter (sub-cycles don't bump it independently). */
typedef enum {
    VADER_CYCLE_NONE = 0,         /* no cycle running */
    VADER_CYCLE_MINOR,            /* standalone minor */
    VADER_CYCLE_MAJOR_DRAIN,      /* minor running as the first step of a major */
    VADER_CYCLE_MAJOR,            /* old→old Cheney pass of a major */
} vader_cycle_t;
static vader_cycle_t g_cycle = VADER_CYCLE_NONE;

/* Card table — one byte per VADER_CARD_BYTES of contiguous old-gen memory.
 * Sized to cover both old semi-spaces so an entry indexes either side after
 * a swap. Exposed (non-static) because the inline `VADER_WRITE_BARRIER` macro
 * needs the address from emitted C code. */
uint8_t*   vader_card_table = NULL;
uintptr_t  vader_old_base   = 0;
uintptr_t  vader_old_end    = 0;
static size_t g_card_count = 0;

/* Shadow-stack head. Each emitted C function pushes/pops a frame chained
 * through `prev`; the GC walks this list at collection time to enumerate
 * precise roots. */
vader_gc_frame_t* vader_gc_top = NULL;

/* Builder layout + active-list head are declared up here so any pass
 * walking `g_builder_head` to keep partial buffers live (currently none
 * — atoms are tracked separately) can see the struct's `next` chain.
 * The op implementations themselves live alongside the rest of the
 * builder helpers further down. */
struct vader_builder_s {
    char*  buf;
    size_t len;
    size_t cap;
    /* Active builders chain through `next` so the string mark-sweep can
     * keep `buf` reachable while a Vader-side allocation (e.g. evaluating
     * an `${stringify(x)}` interp arg) triggers a collection between two
     * `append_*` calls. Without this root the builder's growing buffer
     * gets swept and subsequent appends scribble into freed memory. */
    struct vader_builder_s* next;
};

static vader_builder_t* g_builder_head = NULL;

static size_t vader_gc_align(size_t n) {
    return (n + (VADER_GC_ALIGN - 1u)) & ~(size_t)(VADER_GC_ALIGN - 1u);
}

static int vader_in_young_from(const void* p) {
    return (const char*)p >= g_young.from.base && (const char*)p < g_young.from.end;
}

static int vader_in_old_from(const void* p) {
    return (const char*)p >= g_old.from.base && (const char*)p < g_old.from.end;
}

static int vader_in_old_any(const void* p) {
    return (const char*)p >= (const char*)vader_old_base
        && (const char*)p < (const char*)vader_old_end;
}

/* Read a positive byte-count from `env_name`. Returns `fallback` when the
 * variable is unset, empty, non-numeric, or parses to zero. Lets users tune
 * the heap (e.g. `VADER_GC_OLD_BYTES=134217728` for 128 MB old) without
 * rebuilding the runtime. */
static size_t vader_gc_env_bytes(const char* env_name, size_t fallback) {
    const char* raw = getenv(env_name);
    if (raw == NULL || raw[0] == '\0') return fallback;
    char* end = NULL;
    unsigned long long v = strtoull(raw, &end, 10);
    if (end == raw || v == 0ull) return fallback;
    return (size_t)v;
}

static int g_gc_profile = 0;
void vader_gc_profile_dump(void);

/* ============================================================
 * Atom-based string interning — see `docs/ATOM_INTERNING.md`.
 *
 * Phase 0.a wires the table + API into the runtime alongside the
 * legacy `vader_string_t` machinery. The intern hash, slice-share,
 * and GC integration are stubbed and ship in 0.b / 0.c / Phase 4.
 *
 * The table is grow-only in indices : atoms minted at runtime can be
 * collected (their bytes freed, slot tombstoned) but the `entries[]`
 * array never shrinks — every `vader_atom_t` value ever observed in
 * a live slot stays a valid lookup target, just possibly with reused
 * content. Comptime atoms are PERM-flagged and never collected.
 * ============================================================ */

typedef struct {
    vader_atom_entry_t* entries;
    vader_u32_t         count;
    vader_u32_t         capacity;

    /* Open-addressing hash : intern lookup. `buckets[i]` holds the atom
     * id installed at hash slot `i`, or 0 (== VADER_ATOM_EMPTY) for an
     * empty slot. Slot 0 cannot collide with a real atom because we
     * pre-install the empty atom and skip it in probes. */
    vader_u32_t* buckets;
    vader_u32_t  bucket_capacity;
    vader_u32_t  bucket_count;     /* occupied slots — for load factor check */

    /* Free list of tombstone indices (atoms freed by GC). Reused by the
     * next owner-style intern before growing `entries[]`. */
    vader_u32_t* free_list;
    vader_u32_t  free_count;
    vader_u32_t  free_capacity;

    /* Total bytes held by owner atoms — for profiling. */
    size_t       owner_bytes;
} vader_atom_table_t;

static vader_atom_table_t g_atoms = {0};
static int  g_atoms_initialized = 0;
static int  g_atom_profile = 0;

/* Initial table capacity — 256 covers the keyword + primitive pre-intern
 * with room for early dynamic atoms. Grows by doubling. Phase 0.d will
 * size this from the comptime atom count emitted by codegen. */
#define VADER_ATOM_INITIAL_CAPACITY    256u
#define VADER_ATOM_INITIAL_BUCKETS     1024u   /* must be power of two */

/* Forward decls — implementations below cluster by concern. */
static void        vader_atom_install_empty(void);
static vader_u32_t vader_atom_hash(const char* data, size_t len);
static void        vader_atom_bucket_install(vader_atom_t a, vader_u32_t hash);

void vader_atom_init(void) {
    vader_atom_init_with_comptime(NULL, 0u);
}

void vader_atom_init_with_comptime(const vader_atom_entry_t* comptime_table,
                                   vader_u32_t count) {
    if (g_atoms_initialized) return;
    g_atoms_initialized = 1;

    const char* prof_env = getenv("VADER_ATOM_PROFILE");
    if (prof_env != NULL && prof_env[0] != '\0' && prof_env[0] != '0') {
        g_atom_profile = 1;
        /* `vader_atom_shutdown` dumps the profile before tearing down,
         * so no atexit hook is needed here — atexit's LIFO order would
         * fire the dump *after* shutdown has zeroed the table. */
    }

    /* Pick a capacity that absorbs the comptime atoms plus headroom for
     * the first wave of dynamic interns without an immediate grow.
     * Doubling the comptime size matches the markdown plan (decision §8). */
    vader_u32_t initial_cap = VADER_ATOM_INITIAL_CAPACITY;
    if (count > 0u) {
        /* count + 1 for the empty sentinel at index 0, then ×2 for
         * runtime headroom. Round up to the existing initial capacity
         * so very small modules still get a usable starting bucket
         * table. */
        vader_u32_t want = (count + 1u) * 2u;
        if (want > initial_cap) initial_cap = want;
    }
    g_atoms.entries = (vader_atom_entry_t*)
        malloc(initial_cap * sizeof(vader_atom_entry_t));
    if (g_atoms.entries == NULL) vader_trap("vader_atom_init: entries malloc failed");
    g_atoms.capacity = initial_cap;
    g_atoms.count    = 0;

    /* Bucket capacity scales with comptime count for the same reason —
     * a freshly initialised table should not immediately rehash on the
     * first user interns. Round up to a power of two ≥ 4 × (count+1). */
    vader_u32_t want_buckets = VADER_ATOM_INITIAL_BUCKETS;
    if (count > 0u) {
        vader_u32_t target = (count + 1u) * 4u;
        while (want_buckets < target) want_buckets *= 2u;
    }
    g_atoms.buckets = (vader_u32_t*)
        calloc(want_buckets, sizeof(vader_u32_t));
    if (g_atoms.buckets == NULL) vader_trap("vader_atom_init: buckets calloc failed");
    g_atoms.bucket_capacity = want_buckets;
    g_atoms.bucket_count    = 0;

    g_atoms.free_list     = NULL;
    g_atoms.free_count    = 0;
    g_atoms.free_capacity = 0;
    g_atoms.owner_bytes   = 0;

    vader_atom_install_empty();

    /* Comptime atoms come in PERM — never freed, rodata-backed. Their
     * `data` pointer is owned by the binary's `.rodata` section, so the
     * shutdown path must skip the `free(data)` step on these entries. */
    if (count > 0u && comptime_table != NULL) {
        memcpy(&g_atoms.entries[1], comptime_table,
               count * sizeof(vader_atom_entry_t));
        g_atoms.count = 1u + count;
        /* Force PERM on every comptime entry — the codegen-emitted
         * table sets it too, but enforcing here keeps the runtime
         * invariant local. */
        for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
            g_atoms.entries[i].flags |= VADER_ATOM_FLAG_PERM;
        }
        /* Build the bucket index over the comptime atoms in a single
         * pass — cheaper than running through `vader_atom_intern` and
         * its hash-lookup-then-install dance for each one. */
        for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
            const vader_atom_entry_t* e = &g_atoms.entries[i];
            vader_u32_t h = vader_atom_hash(e->data, e->len);
            vader_atom_bucket_install(i, h);
        }
    }
}

/* Install VADER_ATOM_EMPTY at index 0 with PERM flag. No bucket entry —
 * the empty string is reached by direct `a == 0` checks, never via hash
 * probe (it would collide with the "empty slot" sentinel). */
static void vader_atom_install_empty(void) {
    vader_atom_entry_t* e = &g_atoms.entries[0];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = 0;
    e->flags         = VADER_ATOM_FLAG_PERM;
    e->_pad          = 0;
    e->data          = "";
    g_atoms.count    = 1;
}

void vader_atom_shutdown(void) {
    if (!g_atoms_initialized) return;
    /* Dump the profile *before* tearing down — atexit LIFO ordering
     * runs shutdown ahead of the profile-dump handler registered in
     * `_init_with_comptime`, so the deferred dump would see a zeroed
     * table. Calling it inline here lets us read the live state. */
    if (g_atom_profile) vader_atom_profile_dump();
    for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
        vader_atom_entry_t* e = &g_atoms.entries[i];
        /* Free owner buffers from dynamic intern only — PERM entries
         * carry rodata pointers we must NOT free. Slice atoms borrow
         * from their parent ; no free either. The static empty-string
         * at index 0 is excluded by the loop bound. */
        if (e->parent == 0 && e->data != NULL && e->len > 0
            && (e->flags & VADER_ATOM_FLAG_PERM) == 0) {
            free((void*) e->data);
        }
    }
    free(g_atoms.entries);
    free(g_atoms.buckets);
    free(g_atoms.free_list);
    g_atoms.entries         = NULL;
    g_atoms.buckets         = NULL;
    g_atoms.free_list       = NULL;
    g_atoms.count           = 0;
    g_atoms.capacity        = 0;
    g_atoms.bucket_capacity = 0;
    g_atoms.bucket_count    = 0;
    g_atoms.free_count      = 0;
    g_atoms.free_capacity   = 0;
    g_atoms.owner_bytes     = 0;
    g_atoms_initialized     = 0;
}

const vader_atom_entry_t* vader_atom_entry(vader_atom_t a) {
    return &g_atoms.entries[a];
}

const char* vader_atom_data(vader_atom_t a) {
    return g_atoms.entries[a].data;
}

size_t vader_atom_len(vader_atom_t a) {
    return (size_t) g_atoms.entries[a].len;
}

/* ---- intern internals ---- */

/* FNV1a 32-bit — fine distribution on short ASCII identifiers, no SIMD
 * dependency, simple to reason about. Revisit if the Phase 5 profile
 * shows heavy bucket collisions on real corpora. */
static vader_u32_t vader_atom_hash(const char* data, size_t len) {
    vader_u32_t h = 2166136261u;
    for (size_t i = 0; i < len; ++i) {
        h ^= (vader_u8_t) data[i];
        h *= 16777619u;
    }
    return h;
}

/* Bucket probe — returns the matching atom id or VADER_ATOM_EMPTY (0)
 * on miss. The empty-slot sentinel in `buckets[]` is also 0 ; callers
 * short-circuit len==0 before reaching this so the sentinel can never
 * collide with a real hit. `bucket_capacity` is a power of two — mask
 * trick replaces a modulo. */
static vader_atom_t vader_atom_lookup(const char* data, size_t len, vader_u32_t hash) {
    const vader_u32_t mask = g_atoms.bucket_capacity - 1u;
    vader_u32_t idx = hash & mask;
    for (;;) {
        vader_atom_t a = g_atoms.buckets[idx];
        if (a == VADER_ATOM_EMPTY) return VADER_ATOM_EMPTY;
        const vader_atom_entry_t* e = &g_atoms.entries[a];
        if (e->len == len && memcmp(e->data, data, len) == 0) {
            return a;
        }
        idx = (idx + 1u) & mask;
    }
}

/* Install an atom id at its canonical bucket slot. Assumes free room —
 * the load-factor check in the intern entrypoint grows buckets before
 * any insert that would push it past the 0.75 threshold. */
static void vader_atom_bucket_install(vader_atom_t a, vader_u32_t hash) {
    const vader_u32_t mask = g_atoms.bucket_capacity - 1u;
    vader_u32_t idx = hash & mask;
    while (g_atoms.buckets[idx] != VADER_ATOM_EMPTY) {
        idx = (idx + 1u) & mask;
    }
    g_atoms.buckets[idx] = a;
    g_atoms.bucket_count++;
}

/* Bucket grow — double capacity, rehash every live atom. Called when
 * the load factor would exceed 0.75 after the most recent install. */
static void vader_atom_grow_buckets(void) {
    free(g_atoms.buckets);
    g_atoms.bucket_capacity *= 2u;
    g_atoms.buckets = (vader_u32_t*)
        calloc(g_atoms.bucket_capacity, sizeof(vader_u32_t));
    if (g_atoms.buckets == NULL) vader_trap("vader_atom_grow_buckets: calloc failed");
    g_atoms.bucket_count = 0;
    /* Reinsert every live atom except the empty sentinel at index 0.
     * Phase 4 will skip tombstones here too ; for now no tombstones
     * exist. */
    for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
        const vader_atom_entry_t* e = &g_atoms.entries[i];
        vader_u32_t h = vader_atom_hash(e->data, e->len);
        vader_atom_bucket_install(i, h);
    }
}

/* Entries grow — double capacity, realloc in place. Pointers into the
 * array are NOT stable across calls ; every reader rederefs through
 * `g_atoms.entries`, so a realloc that relocates the array is safe. */
static void vader_atom_grow_entries(void) {
    g_atoms.capacity *= 2u;
    vader_atom_entry_t* p = (vader_atom_entry_t*)
        realloc(g_atoms.entries, g_atoms.capacity * sizeof(vader_atom_entry_t));
    if (p == NULL) vader_trap("vader_atom_grow_entries: realloc failed");
    g_atoms.entries = p;
}

/* Allocate a fresh atom slot — reuses a tombstoned id from the free
 * list (Phase 4) when available, else grows `entries[]`. The entry is
 * left uninitialised ; the caller fills the fields. */
static vader_atom_t vader_atom_alloc_slot(void) {
    if (g_atoms.free_count > 0) {
        return g_atoms.free_list[--g_atoms.free_count];
    }
    if (g_atoms.count >= g_atoms.capacity) {
        vader_atom_grow_entries();
    }
    return g_atoms.count++;
}

/* Miss-path install : claim a slot, point it at `buf` (caller-owned heap
 * buffer with inline NUL at `buf[len]` already written), bucket-install,
 * grow buckets if load factor crossed. The caller is responsible for
 * ensuring `buf` is the canonical bytes for `hash` (i.e. they already
 * lost a lookup race). */
static vader_atom_t vader_atom_install_owner(char* buf, size_t len, vader_u32_t hash) {
    vader_atom_t a = vader_atom_alloc_slot();
    vader_atom_entry_t* e = &g_atoms.entries[a];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = (vader_u32_t) len;
    e->flags         = 0;
    e->_pad          = 0;
    e->data          = buf;
    g_atoms.owner_bytes += len;

    vader_atom_bucket_install(a, hash);

    /* Grow if past 0.75. Done after install so the just-inserted atom
     * rehashes with the rest into the new table. */
    if (g_atoms.bucket_count * 4u > g_atoms.bucket_capacity * 3u) {
        vader_atom_grow_buckets();
    }
    return a;
}

/* ---- public intern API ---- */

vader_atom_t vader_atom_intern(const char* data, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    vader_u32_t hash = vader_atom_hash(data, len);
    vader_atom_t found = vader_atom_lookup(data, len, hash);
    if (found != VADER_ATOM_EMPTY) return found;

    char* buf = (char*) malloc(len + 1u);
    if (buf == NULL) vader_trap("vader_atom_intern: buffer malloc failed");
    memcpy(buf, data, len);
    buf[len] = '\0';
    return vader_atom_install_owner(buf, len, hash);
}

vader_atom_t vader_atom_intern_take(char* buf, size_t len) {
    if (len == 0) {
        free(buf);
        return VADER_ATOM_EMPTY;
    }

    vader_u32_t hash = vader_atom_hash(buf, len);
    vader_atom_t found = vader_atom_lookup(buf, len, hash);
    if (found != VADER_ATOM_EMPTY) {
        free(buf);
        return found;
    }

    /* Caller MUST have allocated `buf` with `malloc(len + 1)` so the
     * inline NUL fits. */
    buf[len] = '\0';
    return vader_atom_install_owner(buf, len, hash);
}

vader_atom_t vader_atom_slice(vader_atom_t parent, size_t offset, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    /* Bounds validation against the parent's logical bytes. Invalid
     * arguments are a runtime contract violation — trap rather than
     * silently produce a corrupted slice. */
    if (parent >= g_atoms.count) {
        vader_trap("vader_atom_slice: parent atom id out of range");
    }
    const vader_atom_entry_t* pe = &g_atoms.entries[parent];
    if (offset > pe->len || len > pe->len - offset) {
        vader_trap("vader_atom_slice: range overflows parent length");
    }

    /* Flatten one hop : every slice atom enforces `parent.parent == 0`
     * at insert time (we never link a slice to another slice), so the
     * deepest chain we ever see is parent → owner. Keeps the GC mark
     * trivial (one hop, never recursive). */
    vader_atom_t root        = parent;
    size_t       root_offset = offset;
    if (g_atoms.entries[root].parent != 0) {
        root_offset += g_atoms.entries[root].parent_offset;
        root         = g_atoms.entries[root].parent;
    }

    /* Hash on the candidate bytes ; dedupe regardless of where the
     * canonical representative lives (might be owner, might be slice
     * sharing different bytes that happen to compare equal). */
    const char* candidate = g_atoms.entries[root].data + root_offset;
    vader_u32_t hash      = vader_atom_hash(candidate, len);
    vader_atom_t found    = vader_atom_lookup(candidate, len, hash);
    if (found != VADER_ATOM_EMPTY) return found;

    /* Miss — install as slice atom borrowing from the root owner. No
     * allocation. NUL-term at data[len] is NOT guaranteed (the byte
     * past the slice belongs to the parent buffer and may be any
     * value) — `vader_atom_to_cstr` handles slice atoms by duplicating
     * to a heap NUL-term copy. */
    vader_atom_t a = vader_atom_alloc_slot();
    vader_atom_entry_t* e = &g_atoms.entries[a];
    e->parent        = root;
    e->parent_offset = (vader_u32_t) root_offset;
    e->len           = (vader_u32_t) len;
    e->flags         = 0;
    e->_pad          = 0;
    e->data          = candidate;

    vader_atom_bucket_install(a, hash);

    if (g_atoms.bucket_count * 4u > g_atoms.bucket_capacity * 3u) {
        vader_atom_grow_buckets();
    }

    return a;
}

const char* vader_atom_to_cstr(vader_atom_t a) {
    const vader_atom_entry_t* e = &g_atoms.entries[a];
    if (e->parent == 0) {
        return e->data;     /* owner : NUL-term inline at data[len] */
    }
    /* Slice : duplicate for NUL termination. Caller frees via
     * `vader_atom_cstr_free`. */
    char* dup = (char*) malloc(e->len + 1u);
    if (dup == NULL) vader_trap("vader_atom_to_cstr: dup malloc failed");
    memcpy(dup, e->data, e->len);
    dup[e->len] = '\0';
    return dup;
}

void vader_atom_cstr_free(const char* p) {
    if (p == NULL) return;
    /* Distinguish owner-data (stable pointer into the table) from slice
     * dups (heap-allocated by `_to_cstr`). The owner path returns a
     * pointer into our own table — we can't `free` it. We detect by
     * scanning the table, which is O(N) but only matters for FFI
     * boundaries (cold). A faster discriminator (e.g. a header bit on
     * dup'd buffers) is a Phase 1 optimisation. */
    for (vader_u32_t i = 0; i < g_atoms.count; ++i) {
        if (g_atoms.entries[i].parent == 0 && g_atoms.entries[i].data == p) {
            return;  /* owner data — owned by table */
        }
    }
    free((void*) p);
}

void vader_atom_profile_dump(void) {
    fprintf(stderr, "[atom-profile] count=%u capacity=%u bucket_load=%.2f%% "
                    "owner_bytes=%zu free_count=%u\n",
            g_atoms.count, g_atoms.capacity,
            g_atoms.bucket_capacity == 0 ? 0.0
                : 100.0 * (double) g_atoms.bucket_count / (double) g_atoms.bucket_capacity,
            g_atoms.owner_bytes, g_atoms.free_count);
}

/* Forward decl for the heap-mark walker — defined further down. */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index);

/* ---- atom GC mark + sweep (Phase 4) ----
 *
 * Integrates with the Cheney major cycle. Reachable atoms are found
 * through three channels :
 *   - shadow stack `vader_box_t**` roots (conservative : the lower 4
 *     bytes of every box payload are treated as a candidate atom id)
 *   - heap objects, via `vader_type_info.string_offsets[]` (precise)
 *     plus a conservative pass over `ptr_offsets[]` boxes
 *   - defer stack
 * Unmarked non-PERM atoms have their data buffer freed and the slot
 * tombstoned ; the bucket index is rebuilt in one pass. */

static void vader_atom_mark(vader_atom_t a) {
    if (a == VADER_ATOM_EMPTY || a >= g_atoms.count) return;
    vader_atom_entry_t* e = &g_atoms.entries[a];
    if (e->flags & (VADER_ATOM_FLAG_PERM | VADER_ATOM_FLAG_MARK)) return;
    e->flags |= VADER_ATOM_FLAG_MARK;
    /* Slice → owner : keep the parent alive too. Chain depth is at
     * most 1 (the slice ctor flattens), so no recursion needed. */
    if (e->parent != 0 && e->parent < g_atoms.count) {
        vader_atom_entry_t* p = &g_atoms.entries[e->parent];
        if ((p->flags & VADER_ATOM_FLAG_PERM) == 0) {
            p->flags |= VADER_ATOM_FLAG_MARK;
        }
    }
}

static void vader_atom_mark_box(const vader_box_t* bp) {
    if (bp == NULL) return;
    /* Conservatively treat the lower 4 bytes of `payload.s` as an atom
     * id. False positives keep extra atoms alive ; no correctness
     * impact. The 8-byte `payload.i` alias is read once to avoid
     * union-field type-punning warnings. */
    vader_atom_mark((vader_atom_t) (uint32_t) bp->payload.i);
}

static void vader_atom_mark_roots(void) {
    for (vader_gc_frame_t* fr = vader_gc_top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs == NULL) continue;
        for (uint32_t i = 0; i < fr->nrefs; i++) {
            vader_atom_mark_box(fr->ptrs[i]);
        }
    }
    for (size_t i = 0; i < g_defer_len; i++) {
        vader_atom_mark_box(&g_defer_stack[i]);
    }
}

static void vader_atom_mark_heap(void) {
    const vader_arena_t* arenas[2] = { &g_young.from, &g_old.from };
    for (int g = 0; g < 2; g++) {
        char* scan = arenas[g]->base;
        while (scan < arenas[g]->cur) {
            vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
            uint32_t type_index = hdr->type_index;
            size_t bytes = vader_gc_obj_size(scan, type_index);
            if (bytes == 0) break;
            if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
                vader_array_buf_t* buf = (vader_array_buf_t*) scan;
                if (buf->element_kind == VADER_ARRAY_KIND_BOXED) {
                    vader_box_t* slots = vader_array_box_slots(buf);
                    for (size_t i = 0; i < buf->length; i++) {
                        vader_atom_mark_box(&slots[i]);
                    }
                }
            } else if (type_index < vader_type_info_count) {
                const vader_type_info_t* info = &vader_type_info_table[type_index];
                /* Precise : string fields from the type_info table. */
                for (uint16_t i = 0; i < info->string_count; i++) {
                    vader_string_t* sp = (vader_string_t*) (scan + info->string_offsets[i]);
                    vader_atom_mark(*sp);
                }
                /* Borrowed `const u8[]` byte view (`vader_string_bytes_view`) :
                 * the array header carries no string field, but its `capacity`
                 * low 32 bits hold the owner atom id whose interned bytes the
                 * view aliases. Mark it so the bytes aren't swept under us. */
                if (info->kind == VADER_TYPE_KIND_ARRAY) {
                    vader_array_t* arr = (vader_array_t*) scan;
                    if (vader_array_is_borrowed(arr)) {
                        vader_atom_mark(vader_array_borrowed_owner(arr));
                    }
                }
                /* Conservative : box fields. The payload's lower 4 bytes
                 * may be an atom (for string-tagged variants) or any
                 * other primitive ; conservativeness keeps the latter
                 * from accidentally collecting a live atom. */
                if (info->kind != VADER_TYPE_KIND_FN
                    && info->kind != VADER_TYPE_KIND_ARRAY) {
                    for (uint16_t i = 0; i < info->ptr_count; i++) {
                        vader_atom_mark_box((vader_box_t*) (scan + info->ptr_offsets[i]));
                    }
                }
            }
            scan += vader_gc_align(bytes);
        }
    }
}

static void vader_atom_free_list_push(vader_u32_t id) {
    if (g_atoms.free_count >= g_atoms.free_capacity) {
        size_t new_cap = g_atoms.free_capacity == 0 ? 64u : (size_t) g_atoms.free_capacity * 2u;
        vader_u32_t* p = (vader_u32_t*) realloc(g_atoms.free_list, new_cap * sizeof(vader_u32_t));
        if (p == NULL) vader_trap("vader_atom_free_list_push: realloc failed");
        g_atoms.free_list = p;
        g_atoms.free_capacity = (vader_u32_t) new_cap;
    }
    g_atoms.free_list[g_atoms.free_count++] = id;
}

static void vader_atom_sweep(void) {
    size_t freed_bytes = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        vader_atom_entry_t* e = &g_atoms.entries[i];
        if (e->flags & VADER_ATOM_FLAG_PERM) continue;
        /* Skip already-tombstoned slots (data NULL means reclaimed in a
         * previous sweep ; they live in the free list). */
        if (e->data == NULL && e->len == 0 && e->parent == 0) continue;
        if (e->flags & VADER_ATOM_FLAG_MARK) {
            e->flags &= ~VADER_ATOM_FLAG_MARK;
            continue;
        }
        if (e->parent == 0 && e->data != NULL && e->len > 0) {
            freed_bytes += e->len;
            free((void*) e->data);
        }
        e->parent        = 0;
        e->parent_offset = 0;
        e->len           = 0;
        e->flags         = 0;
        e->data          = NULL;
        vader_atom_free_list_push(i);
    }
    if (freed_bytes > g_atoms.owner_bytes) g_atoms.owner_bytes = 0;
    else g_atoms.owner_bytes -= freed_bytes;

    /* Rebuild the hash index. Bucket clears + linear reinsert keeps the
     * implementation simple ; incremental updates would need to track
     * each tombstone's original hash to clear specifically. */
    memset(g_atoms.buckets, 0, g_atoms.bucket_capacity * sizeof(vader_u32_t));
    g_atoms.bucket_count = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        const vader_atom_entry_t* e = &g_atoms.entries[i];
        if (e->data == NULL) continue;
        vader_u32_t h = vader_atom_hash(e->data, e->len);
        vader_atom_bucket_install(i, h);
    }
}

void vader_atom_gc_collect(void) {
    if (!g_atoms_initialized) return;
    vader_atom_mark_roots();
    vader_atom_mark_heap();
    vader_atom_sweep();
}

void vader_gc_init(void) {
    if (g_gc_initialized) return;

    const char* stress_env = getenv("VADER_GC_STRESS");
    g_gc_stress = (stress_env != NULL && stress_env[0] != '\0' && stress_env[0] != '0');

    /* VADER_GC_PROFILE : at exit, walk both arenas and dump the live set
     * bucketed by type_index — sorted by total bytes, top-20. Useful to
     * answer "what's filling my GC arena?". OOM paths abort() so atexit
     * doesn't fire ; the OOM trap dumps inline before aborting. */
    const char* gc_prof_env = getenv("VADER_GC_PROFILE");
    if (gc_prof_env != NULL && gc_prof_env[0] != '\0' && gc_prof_env[0] != '0') {
        g_gc_profile = 1;
        atexit(vader_gc_profile_dump);
    }

    /* Young: one malloc spanning both semi-spaces. */
    size_t young_bytes = vader_gc_env_bytes("VADER_GC_YOUNG_BYTES", (size_t)VADER_GC_YOUNG_BYTES);
    g_young.block = (char*) malloc(young_bytes * 2u);
    if (g_young.block == NULL) vader_trap("vader_gc_init: young arena malloc failed");
    g_young.half_bytes = young_bytes;
    g_young.from.base = g_young.block;
    g_young.from.cur  = g_young.block;
    g_young.from.end  = g_young.block + young_bytes;
    g_young.to.base   = g_young.block + young_bytes;
    g_young.to.cur    = g_young.to.base;
    g_young.to.end    = g_young.to.base + young_bytes;

    /* Old: one malloc spanning both semi-spaces, contiguous to ease the
     * card-table indexing. */
    size_t old_bytes = vader_gc_env_bytes("VADER_GC_OLD_BYTES", (size_t)VADER_GC_OLD_BYTES);
    g_old.block = (char*) malloc(old_bytes * 2u);
    if (g_old.block == NULL) vader_trap("vader_gc_init: old arena malloc failed");
    g_old.half_bytes = old_bytes;
    g_old.from.base = g_old.block;
    g_old.from.cur  = g_old.block;
    g_old.from.end  = g_old.block + old_bytes;
    g_old.to.base   = g_old.block + old_bytes;
    g_old.to.cur    = g_old.to.base;
    g_old.to.end    = g_old.to.base + old_bytes;

    /* Card table covers both old semi-spaces so an entry remains valid after
     * a major swap. Total old span = 2 * old_bytes, sized at one byte per
     * VADER_CARD_BYTES. */
    g_card_count = (old_bytes * 2u + VADER_CARD_BYTES - 1u) / VADER_CARD_BYTES;
    vader_card_table = (uint8_t*) calloc(g_card_count, 1u);
    if (vader_card_table == NULL) vader_trap("vader_gc_init: card-table malloc failed");
    vader_old_base = (uintptr_t) g_old.block;
    vader_old_end  = (uintptr_t) (g_old.block + old_bytes * 2u);

    g_gc_initialized = 1;
}

void vader_gc_shutdown(void) {
    if (!g_gc_initialized) return;
    free(g_young.block);
    free(g_old.block);
    free(vader_card_table);
    g_young.block = NULL;
    g_old.block   = NULL;
    g_young.from.base = g_young.from.cur = g_young.from.end = NULL;
    g_young.to.base   = g_young.to.cur   = g_young.to.end   = NULL;
    g_old.from.base   = g_old.from.cur   = g_old.from.end   = NULL;
    g_old.to.base     = g_old.to.cur     = g_old.to.end     = NULL;
    vader_card_table  = NULL;
    vader_old_base    = 0;
    vader_old_end     = 0;
    g_card_count      = 0;
    g_gc_initialized  = 0;
}

/* Internal bump in the young from-space. Caller must have ensured capacity. */
static void* vader_gc_alloc_young_unchecked(size_t aligned) {
    void* p = g_young.from.cur;
    g_young.from.cur += aligned;
    return p;
}

void* vader_gc_alloc(size_t bytes) {
    if (VADER_UNLIKELY(!g_gc_initialized)) vader_gc_init();
    size_t aligned = vader_gc_align(bytes);
    /* A single allocation that exceeds a young semi-space can never fit, so
     * no amount of collection will help. Trap early to avoid two wasted
     * cycles. Bump VADER_GC_YOUNG_BYTES if user code legitimately needs it. */
    if (VADER_UNLIKELY(aligned > g_young.half_bytes)) {
        vader_trap("vader_gc_alloc: requested size exceeds young semi-space");
    }
    int young_full = (g_young.from.cur + aligned > g_young.from.end);
    if (VADER_UNLIKELY(young_full || g_gc_stress)) {
        vader_minor_collect();
        if (VADER_UNLIKELY(g_young.from.cur + aligned > g_young.from.end)) {
            /* Minor didn't free enough — young is overcommitted by long-
             * lived young objects (tenuring will fix it on the next cycle).
             * Force a major to age survivors into old and retry. */
            vader_major_collect();
            if (VADER_UNLIKELY(g_young.from.cur + aligned > g_young.from.end)) {
                fprintf(stderr,
                    "vader_gc_alloc: out of memory after collection\n"
                    "  young arena %zu MB × 2 (raise via VADER_GC_YOUNG_BYTES, bytes per semi-space)\n"
                    "  old arena   %zu MB × 2 (raise via VADER_GC_OLD_BYTES)\n",
                    g_young.half_bytes / (1024u * 1024u),
                    g_old.half_bytes / (1024u * 1024u));
                /* abort() skips atexit handlers — dump the live set inline so
                 * VADER_GC_PROFILE works on OOM cases (the very ones we want
                 * to diagnose). */
                if (g_gc_profile) vader_gc_profile_dump();
                vader_trap("vader_gc_alloc: out of memory after collection");
            }
        }
    }
    return vader_gc_alloc_young_unchecked(aligned);
}

/* ---------- generational Cheney copying GC ---------- */

/* Size of an object in a from-space, in bytes. For variable-length buffers
 * (ARRAY_BUF sentinel) the size is read off the object itself; for
 * everything else the type info table provides a static size. Returns 0
 * for non-heap kinds (caller skips). */
static size_t vader_gc_obj_size(void* obj, uint32_t type_index) {
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) obj;
        return sizeof(vader_array_buf_t) + buf->capacity * vader_array_element_size(buf->element_kind);
    }
    if (type_index >= vader_type_info_count) return 0;
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    if (info->kind == VADER_TYPE_KIND_NONE) return 0;
    return info->size;
}

/* Place a copy of `obj` in `target` and return the new address. Updates the
 * source header's `forward` slot, clears the destination's so the freshly
 * copied object looks live (not yet forwarded) within this cycle. The
 * destination's age is overwritten by the caller to reflect promotion
 * semantics. Returns NULL if `target` doesn't have room — the caller is
 * expected to react (promotion overflow → escalate to major). */
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

/* Forward-copy `obj` (typed by `type_index`) following `g_cycle`:
 *
 *   minor or major-drain : young objects move to young.to (or promote to
 *     old.from once age ≥ tenure); old objects are stable.
 *   major (Cheney on old)  : old.from objects move to old.to.
 *
 * Pointers outside any GC arena are immortal — static compile-time data
 * (lookup tables, interned constants) lives in the C data segment and is
 * never copied. The C-emit may emit such tables for fns matching the
 * `match enum -> StructLit constant` pattern (TODO §3.5 Prop 2).
 * Constraint: a static object MUST NOT contain any pointer to a dynamic
 * (arena-allocated) object — the Cheney scan never visits it, so any inner
 * dynamic ref would be missed and freed under your feet. */
static void* vader_gc_forward(void* obj, uint32_t type_index) {
    if (obj == NULL) return NULL;

    if (g_cycle == VADER_CYCLE_MAJOR) {
        if (!vader_in_old_from(obj)) return obj;        /* immortal or stale young */
        vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
        if (hdr->forward != NULL) return hdr->forward;
        size_t bytes = vader_gc_obj_size(obj, type_index);
        if (bytes == 0) return obj;
        void* dst = vader_gc_copy_into(obj, bytes, &g_old.to);
        if (dst == NULL) vader_trap("vader_gc: old to-space overflow during major");
        return dst;
    }

    if (vader_in_old_any(obj)) return obj;              /* stable during minor */
    if (!vader_in_young_from(obj)) return obj;          /* immortal */

    vader_obj_header_t* hdr = (vader_obj_header_t*) obj;
    if (hdr->forward != NULL) return hdr->forward;

    size_t bytes = vader_gc_obj_size(obj, type_index);
    if (bytes == 0) return obj;

    /* Promote into old.from once the object has earned its tenure. If old
     * can't fit it, fall back to surviving another cycle in young.to — the
     * retry path in vader_gc_alloc will escalate to a major. */
    if (hdr->age + 1u >= VADER_TENURE_AGE) {
        void* promoted = vader_gc_copy_into(obj, bytes, &g_old.from);
        if (promoted != NULL) {
            ((vader_obj_header_t*) promoted)->age = (uint8_t)(hdr->age + 1u);
            return promoted;
        }
    }

    void* dst = vader_gc_copy_into(obj, bytes, &g_young.to);
    if (dst == NULL) vader_trap("vader_gc: young to-space overflow during minor");
    ((vader_obj_header_t*) dst)->age = (uint8_t)(hdr->age + 1u);
    return dst;
}

/* Forward decl — `scan_box` reaches into `scan_raw` for the inline-ref
 * wrapper case (payload.obj is the referent, not a wrapper-typed pointer). */
static void vader_gc_scan_raw(void** slot);

/* Scan a `vader_box_t` slot — if the tag identifies a heap-allocated kind and
 * the payload holds a pointer, forward it and update the slot in place.
 *
 * If `boxp` lives in an old-gen object and the forwarded ref ends up in
 * young, mark the card dirty: future minors must rescan this slot, and
 * neither the original `array_push` write barrier (fired on user mutation,
 * not on this Cheney write) nor scan_old_dirty_cards covers it. */
static void vader_gc_scan_box(vader_box_t* boxp) {
    if (boxp == NULL) return;
    if (boxp->tag >= vader_type_info_count) return;
    const vader_type_info_t* info = &vader_type_info_table[boxp->tag];
    if (info->kind == VADER_TYPE_KIND_NONE) return;
    /* Inline-ref wrapper : `payload.obj` is the referent itself (not a
     * pointer to a wrapper struct allocated under `boxp->tag`). Trace it
     * by reading the obj's own type tag from its header — scan_raw does
     * exactly that. The outer tag stays unchanged (`boxp->tag` is still
     * the wrapper's logical type, e.g. `Yield(Entry)`). */
    if (info->kind == VADER_TYPE_KIND_INLINE_REF) {
        vader_gc_scan_raw(&boxp->payload.obj);
        if ((uintptr_t)boxp >= vader_old_base && (uintptr_t)boxp < vader_old_end
            && boxp->payload.obj != NULL
            && !vader_in_old_any(boxp->payload.obj)) {
            VADER_WRITE_BARRIER(boxp);
        }
        return;
    }
    boxp->payload.obj = vader_gc_forward(boxp->payload.obj, boxp->tag);
    if ((uintptr_t)boxp >= vader_old_base && (uintptr_t)boxp < vader_old_end
        && boxp->payload.obj != NULL
        && !vader_in_old_any(boxp->payload.obj)) {
        VADER_WRITE_BARRIER(boxp);
    }
}

/* Scan a raw `void*` slot whose pointee is a heap object. Reads the pointee's
 * header to get its type, forwards, updates. Used for fn closure envs.
 * Same write-barrier rule as `vader_gc_scan_box`. */
static void vader_gc_scan_raw(void** slot) {
    if (slot == NULL || *slot == NULL) return;
    vader_obj_header_t* hdr = (vader_obj_header_t*) *slot;
    if (hdr->forward != NULL) { *slot = hdr->forward; }
    else { *slot = vader_gc_forward(*slot, hdr->type_index); }
    if ((uintptr_t)slot >= vader_old_base && (uintptr_t)slot < vader_old_end
        && *slot != NULL && !vader_in_old_any(*slot)) {
        VADER_WRITE_BARRIER(slot);
    }
}

/* Scan one heap object's pointer-bearing slots and forward whatever they
 * reference. Returns the byte length of the object so a Cheney scan can
 * advance its cursor. Returns 0 for malformed headers — callers treat that
 * as a stop condition. */
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
        }
        return vader_gc_align(sizeof(vader_array_buf_t) + buf->capacity * elem_size);
    }
    if (type_index >= vader_type_info_count) {
        vader_trap("vader_gc: scanned object with unknown type_index");
    }
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    for (uint16_t i = 0; i < info->ptr_count; i++) {
        char* field = scan + info->ptr_offsets[i];
        if (info->kind == VADER_TYPE_KIND_FN
            || info->kind == VADER_TYPE_KIND_ARRAY) {
            vader_gc_scan_raw((void**) field);
        } else {
            vader_gc_scan_box((vader_box_t*) field);
        }
    }
    for (uint16_t i = 0; i < info->ref_count; i++) {
        vader_gc_scan_raw((void**) (scan + info->ref_offsets[i]));
    }
    return vader_gc_align(info->size);
}

/* Walk the shadow stack and forward every root cell. Used by both cycles. */
static void vader_gc_scan_roots(void) {
    for (vader_gc_frame_t* fr = vader_gc_top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs == NULL) continue;
        for (uint32_t i = 0; i < fr->nrefs; i++) {
            vader_gc_scan_box(fr->ptrs[i]);
        }
    }
    /* Defer-stack — every entry's `payload.obj` is a vader_fn_t* whose env
     * captures heap-promoted cells. Without rooting here, a GC between
     * defer.push and defer.pop_exec would collect the captures. */
    for (size_t i = 0; i < g_defer_len; i++) {
        vader_gc_scan_box(&g_defer_stack[i]);
    }
}

/* Walk old.from and forward pointer-bearing slots of every object that
 * sits in (or spans) a dirty card. Clean cards are skipped wholesale: those
 * objects can't reference young, by the write-barrier invariant.
 *
 * The card table is *not* cleared by minor. A card stays dirty until the
 * next major resets the whole table — that's deliberate: scanning a still-
 * dirty card across multiple minors costs at most O(card_count) extra
 * memory reads, while clearing in minor would require rescanning to
 * decide whether the card still has a live old→young reference. */
static void vader_gc_scan_old_dirty_cards(void) {
    char*     base   = g_old.block;
    uintptr_t arena0 = (uintptr_t) base;
    char*     scan   = g_old.from.base;
    while (scan < g_old.from.cur) {
        vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
        uint32_t type_index = hdr->type_index;
        size_t bytes = vader_gc_obj_size(scan, type_index);
        if (bytes == 0) return;                         /* corrupt header — bail */
        size_t step = vader_gc_align(bytes);

        /* An object's slot writes mark whichever card holds the object header;
         * arrays whose buf lives elsewhere mark the buf separately. So the
         * relevant cards for this object are the ones spanning [scan, scan+bytes). */
        uintptr_t off_start = (uintptr_t) scan - arena0;
        uintptr_t off_end   = off_start + bytes - 1u;
        size_t card_start = off_start / VADER_CARD_BYTES;
        size_t card_end   = off_end   / VADER_CARD_BYTES;
        int dirty = 0;
        for (size_t c = card_start; c <= card_end; c++) {
            if (vader_card_table[c]) { dirty = 1; break; }
        }
        if (dirty) {
            (void) vader_gc_scan_object(scan);
        }
        scan += step;
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
    char* young_scan       = g_young.to.base;
    char* old_promote_scan = g_old.from.cur;            /* promotions land past here */

    vader_gc_scan_roots();
    vader_gc_scan_old_dirty_cards();

    /* Drain both cursors until neither advances — forwarding a young root
     * can promote into old, and forwarding an old promote can pull more
     * young objects across, so the two sources feed each other. */
    for (;;) {
        char* y0 = young_scan;
        char* o0 = old_promote_scan;
        young_scan       = vader_gc_drain(young_scan, &g_young.to);
        old_promote_scan = vader_gc_drain(old_promote_scan, &g_old.from);
        if (young_scan == y0 && old_promote_scan == o0) break;
    }

    vader_arena_t tmp = g_young.from;
    g_young.from   = g_young.to;
    g_young.to     = tmp;
    g_young.to.cur = g_young.to.base;

    /* A preliminary minor inside a major counts as part of that major. */
    if (saved == VADER_CYCLE_NONE) g_total_collections++;
    g_cycle = saved;

    /* Atom-table GC integration lands in Phase 4. The legacy string
     * mark-sweep that used to run here was removed when `vader_string_t`
     * flipped to `u32` ; atoms are POD now and the conservative scan
     * naturally ignores them. */
}

void vader_major_collect(void) {
    if (!g_gc_initialized) return;

    /* Drain young first so old can be Cheney-collected as a self-contained
     * set. Surviving young objects (those that didn't promote) are treated
     * as immortal during the old pass — old can only reach young via the
     * card table, which the minor consumed. */
    g_cycle = VADER_CYCLE_MAJOR_DRAIN;
    vader_minor_collect();

    g_cycle = VADER_CYCLE_MAJOR;
    g_old.to.cur = g_old.to.base;

    vader_gc_scan_roots();
    (void) vader_gc_drain(g_young.from.base, &g_young.from);
    (void) vader_gc_drain(g_old.to.base, &g_old.to);

    vader_arena_t tmp = g_old.from;
    g_old.from   = g_old.to;
    g_old.to     = tmp;
    g_old.to.cur = g_old.to.base;
    /* Conservatively mark all cards dirty rather than clearing. The drain
     * passes above may have forwarded young-pointing refs back into the
     * fresh old.from copies without writing a barrier, so any old→young
     * reference's card would be lost if we cleared. Scanning a few extra
     * cards on the next minor is far cheaper than missing a root. */
    memset(vader_card_table, 1, g_card_count);

    g_cycle = VADER_CYCLE_NONE;
    g_total_collections++;
    vader_atom_gc_collect();
}

/* Public alias. `runtime.collect()` in Vader maps here; tests rely on it
 * forcing a full collection (Cheney over old, not just minor). */
void vader_gc_collect(void) {
    vader_major_collect();
}

vader_gc_stats_t vader_gc_get_stats(void) {
    vader_gc_stats_t s;
    s.arena_size = VADER_GC_OLD_BYTES;
    if (g_gc_initialized) {
        size_t young_used = (size_t)(g_young.from.cur - g_young.from.base);
        size_t old_used   = (size_t)(g_old.from.cur   - g_old.from.base);
        s.bytes_used = young_used + old_used;
    } else {
        s.bytes_used = 0;
    }
    s.total_collections = g_total_collections;
    s.total_copied = g_total_copied;
    return s;
}

/* ----------------------------------------------------------------- string */

vader_string_t vader_string_new(const char* p, size_t n) {
    return vader_atom_intern(p, n);
}

vader_string_t vader_string_concat(vader_string_t a, vader_string_t b) {
    if (a == VADER_ATOM_EMPTY) return b;
    if (b == VADER_ATOM_EMPTY) return a;
    size_t la = vader_atom_len(a);
    size_t lb = vader_atom_len(b);
    /* Two-pass overflow check : the sum must fit, AND leave room for the
     * inline NUL byte. Splitting the conditions yields a precise trap
     * message rather than the ambiguous "length overflow" of the
     * combined `> SIZE_MAX - lb - 1` check. */
    if (la > SIZE_MAX - lb)     vader_trap("vader_string_concat: total length overflow");
    size_t total = la + lb;
    if (total > SIZE_MAX - 1u)  vader_trap("vader_string_concat: no room for NUL terminator");
    char* buf = (char*) malloc(total + 1u);
    if (buf == NULL) vader_trap("vader_string_concat: malloc failed");
    memcpy(buf,      vader_atom_data(a), la);
    memcpy(buf + la, vader_atom_data(b), lb);
    return vader_atom_intern_take(buf, total);
}

bool vader_string_eq(vader_string_t a, vader_string_t b) {
    return a == b;
}

const char* vader_string_to_cstr(vader_string_t s) {
    return vader_atom_to_cstr(s);
}

void vader_cstr_free(const char* p) {
    vader_atom_cstr_free(p);
}

/* FNV-1a 64-bit hash over the raw UTF-8 bytes of the string. Keeps
 * legacy iteration order for `MutableMap` buckets — atom ids are
 * monotonic, so using them directly as the hash would cluster low bits
 * and reshuffle every `for-in` snapshot. The byte-level hash matches
 * what the pre-atom runtime emitted and what the VM hash uses. */
vader_u64_t vader_string_hash(vader_string_t s) {
    const vader_atom_entry_t* e = vader_atom_entry(s);
    const uint8_t* p   = (const uint8_t*) e->data;
    size_t         len = e->len;
    uint64_t h = UINT64_C(14695981039346656037);
    for (size_t i = 0; i < len; i++) {
        h ^= (uint64_t) p[i];
        h *= UINT64_C(1099511628211);
    }
    return h;
}

/* ----------------------------------------------------------------- array */

/* `sizeof(vader_array_buf_t) + capacity * element_size(kind)` without silent
 * integer overflow. With user-controllable `capacity` (e.g. via
 * `array.push` reaching into the gigabytes), the multiplication can wrap
 * `size_t` and produce an under-allocation followed by an OOB write. Trap
 * before the alloc with a clear message instead. */
static size_t vader_array_buf_bytes(size_t capacity, uint8_t element_kind) {
    size_t per_slot = vader_array_element_size(element_kind);
    if (per_slot > 0 && capacity > (SIZE_MAX - sizeof(vader_array_buf_t)) / per_slot) {
        vader_trap("vader_array: capacity overflows size_t");
    }
    return sizeof(vader_array_buf_t) + capacity * per_slot;
}

/* Allocate a fresh array buffer of `capacity` slots with the ARRAY_BUF
 * sentinel as its type tag — the GC scan loop dispatches on that to walk
 * `length` slots dynamically. The struct itself plus its trailing slot
 * area land in a single GC arena allocation. */
static vader_array_buf_t* vader_array_buf_alloc(size_t capacity, uint8_t element_kind, uint32_t element_tag) {
    size_t bytes = vader_array_buf_bytes(capacity, element_kind);
    vader_array_buf_t* buf = (vader_array_buf_t*) vader_gc_alloc(bytes);
    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity     = capacity;
    buf->length       = 0;
    buf->element_kind = element_kind;
    buf->element_tag  = element_tag;
    return buf;
}

vader_array_t* vader_array_new(uint32_t type_index, size_t length, uint8_t element_kind, uint32_t element_tag) {
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
    size_t buf_bytes    = vader_array_buf_bytes(cap, element_kind);
    if (struct_bytes > SIZE_MAX - buf_bytes) {
        vader_trap("vader_array: total alloc size overflows size_t");
    }
    char* block = (char*) vader_gc_alloc(struct_bytes + buf_bytes);
    vader_array_t* a = (vader_array_t*) block;
    vader_array_buf_t* buf = (vader_array_buf_t*) (block + struct_bytes);

    vader_obj_header_init(a, type_index);
    a->length   = length;
    a->capacity = cap;
    a->offset   = 0;
    a->buf      = buf;

    vader_obj_header_init(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity     = cap;
    buf->length       = length;
    buf->element_kind = element_kind;
    buf->element_tag  = element_tag;
    return a;
}

static vader_array_t* vader_array_resolve(vader_array_t* a);

/* Box / unbox helpers for primitive-kind slots. Each kind reads or writes
 * the matching primitive width directly from `buf->slots` ; the boxed kind
 * routes through `vader_array_box_slots`. */
static vader_box_t vader_array_load_slot(vader_array_buf_t* buf, size_t i) {
    uint8_t* base = buf->slots;
    vader_box_t out;
    /* Tag from the buf's recorded element BcType so virtual dispatch on a
     * receiver coming from a primitive-storage array (i32[], bool[], ...)
     * observed through an erased `Any[]` view sees the right runtime tag.
     * BOXED kind returns the per-slot box verbatim — its tag was stamped
     * at store time and may differ slot-to-slot under a heterogeneous
     * `Any[]` view. */
    out.tag = buf->element_tag; out._pad = 0; out.payload.i = 0;
    switch (buf->element_kind) {
        case VADER_ARRAY_KIND_BOXED:
            return vader_array_box_slots(buf)[i];
        case VADER_ARRAY_KIND_U8:   out.payload.i = ((uint8_t*)  base)[i]; return out;
        case VADER_ARRAY_KIND_U16:  out.payload.i = ((uint16_t*) base)[i]; return out;
        case VADER_ARRAY_KIND_U32:  out.payload.i = ((uint32_t*) base)[i]; return out;
        case VADER_ARRAY_KIND_U64:  out.payload.i = (vader_i64_t)((uint64_t*)base)[i]; return out;
        case VADER_ARRAY_KIND_I8:   out.payload.i = ((int8_t*)   base)[i]; return out;
        case VADER_ARRAY_KIND_I16:  out.payload.i = ((int16_t*)  base)[i]; return out;
        case VADER_ARRAY_KIND_I32:  out.payload.i = ((int32_t*)  base)[i]; return out;
        case VADER_ARRAY_KIND_I64:  out.payload.i = ((int64_t*)  base)[i]; return out;
        case VADER_ARRAY_KIND_F32:  out.payload.f = ((float*)    base)[i]; return out;
        case VADER_ARRAY_KIND_F64:  out.payload.f = ((double*)   base)[i]; return out;
        case VADER_ARRAY_KIND_CHAR: out.payload.i = ((uint32_t*) base)[i]; return out;
        case VADER_ARRAY_KIND_BOOL: out.payload.b = ((uint8_t*)  base)[i] != 0; return out;
        default: vader_trap("vader_array_get: unknown element kind");
    }
}

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
        default: vader_trap("vader_array_set: unknown element kind");
    }
}

vader_box_t vader_array_get(vader_array_t* a, size_t i) {
    a = vader_array_resolve(a);
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Borrowed `const u8[]` byte view : read directly from the owner
         * atom's bytes (kept alive by `vader_atom_mark_heap`). */
        if (VADER_UNLIKELY(i >= a->length)) vader_trap("array index out of bounds");
        const uint8_t* data = (const uint8_t*) vader_atom_data(vader_array_borrowed_owner(a));
        vader_box_t out;
        out.tag = vader_array_borrowed_tag(a);
        out._pad = 0;
        out.payload.i = data[a->offset + i];
        return out;
    }
    while (a->buf != NULL && a->buf->header.forward != NULL) {
        a->buf = (vader_array_buf_t*) a->buf->header.forward;
    }
    if (VADER_UNLIKELY(i >= a->length)) vader_trap("array index out of bounds");
    return vader_array_load_slot(a->buf, a->offset + i);
}

void vader_array_set(vader_array_t* a, size_t i, vader_box_t v) {
    a = vader_array_resolve(a);
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Defensive : T3042 already rejects writes to a `const u8[]` at
         * compile time. Trapping here turns any bypass into a clean abort
         * rather than a NULL-`buf` segfault. */
        vader_trap("cannot mutate a borrowed `const u8[]` byte view");
    }
    while (a->buf != NULL && a->buf->header.forward != NULL) {
        a->buf = (vader_array_buf_t*) a->buf->header.forward;
    }
    if (VADER_UNLIKELY(i >= a->length)) vader_trap("array index out of bounds");
    /* A7 unified array+view : `arr[r][i] = v` deliberately writes through
     * to the parent's backing buffer (Go-style aliasing). Detachment
     * only happens on `push` (to avoid silently clobbering aliased tail
     * slots — see vader_array_push). Users opt out of aliasing by
     * materializing a fresh array — today via push-detach, eventually
     * `arr[r].clone()` once `T[] implements Clone` is wired. */
    vader_array_store_slot(a->buf, a->offset + i, v);
    /* Mark the card holding `a->buf` if it lives in old: subsequent minors
     * must treat that card as a root since the new slot may point at young. */
    if (a->buf->element_kind == VADER_ARRAY_KIND_BOXED) {
        VADER_WRITE_BARRIER(a->buf);
    }
}

vader_array_t* vader_array_slice(vader_array_t* a, size_t lo, size_t hi) {
    a = vader_array_resolve(a);
    /* Clamp bounds against the header length (independent of `buf`, so it's
     * valid for both the owning, view, and borrowed cases). */
    if (lo > a->length) lo = a->length;
    if (hi < lo)        hi = lo;
    if (hi > a->length) hi = a->length;
    size_t len = hi - lo;
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Slicing a borrowed byte view yields another borrowed view over the
         * same owner atom : carry `capacity` (element_tag + owner) verbatim,
         * advance `offset` by `lo`. `buf` stays NULL. The alloc may forward
         * `a`, so root it as a box (its `capacity`/`offset`/flag copy verbatim
         * on relocation — §borrowed) and reload after. */
        uint32_t tag = a->header.type_index;
        vader_box_t a_box; a_box.tag = tag; a_box._pad = 0; a_box.payload.obj = a;
        VADER_GC_PUSH1(a_box);
        vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
        VADER_GC_POP();
        a = (vader_array_t*) a_box.payload.obj;
        vader_obj_header_init(view, tag);
        view->length   = len;
        view->capacity = a->capacity;     /* (element_tag << 32) | owner — verbatim */
        view->header._reserved = VADER_ARRAY_FLAG_BORROWED;
        view->offset   = a->offset + lo;
        view->buf      = NULL;
        return view;
    }
    while (a->buf != NULL && a->buf->header.forward != NULL) {
        a->buf = (vader_array_buf_t*) a->buf->header.forward;
    }
    /* Root the parent array across the alloc — a collection inside
     * `vader_gc_alloc` would forward it otherwise. */
    uint32_t tag = a->header.type_index;
    vader_box_t a_box; a_box.tag = tag; a_box._pad = 0; a_box.payload.obj = a;
    vader_box_t* roots[1] = { &a_box };
    vader_gc_frame_t frame = { vader_gc_top, 1u, 0u, roots };
    vader_gc_top = &frame;
    vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
    vader_gc_top = frame.prev;
    a = (vader_array_t*) a_box.payload.obj;
    vader_obj_header_init(view, tag);
    view->length   = len;
    /* Views aren't growable in-place — push detaches into a fresh buf. */
    view->capacity = len;
    view->offset   = a->offset + lo;
    view->buf      = a->buf;
    return view;
}

/* If `a` was relocated by a collection that fired during a recent allocation,
 * its old header carries a forwarding pointer to the new copy. Caller-side
 * code reloads `a` from a shadow-stack slot, but runtime helpers receive `a`
 * as a raw C pointer — after a GC mid-call the parameter is stale. Resolving
 * the forward keeps the helper sound.
 *
 * A single `vader_gc_alloc` call may run a minor THEN a major (the major
 * runs its own internal minor as `MAJOR_DRAIN`), so an object can be
 * forwarded twice in one allocation site. Loop until the chain terminates. */
static vader_array_t* vader_array_resolve(vader_array_t* a) {
    while (a->header.forward != NULL) a = (vader_array_t*) a->header.forward;
    return a;
}

void vader_array_push(vader_array_t* a, vader_box_t v) {
    if (VADER_UNLIKELY(vader_array_is_borrowed(a))) {
        /* Defensive : T3042 rejects mutation of a `const u8[]` view. */
        vader_trap("cannot push to a borrowed `const u8[]` byte view");
    }
    /* Three reasons to detach into a fresh buf : (a) cap reached, (b) view
     * with non-zero offset, (c) view whose tail doesn't extend to the buf
     * end (another view aliases the tail slots — growing in place would
     * overwrite them). The owning array meets none of these. */
    bool is_view = a->offset != 0 || a->offset + a->length < a->buf->length;
    if (a->length >= a->capacity || is_view) {
        /* The grow path may run TWO GC cycles inside `vader_array_buf_alloc`
         * (minor → major when the minor doesn't free enough). Each cycle
         * forwards `a` and swaps young from/to halves ; by the second swap
         * the *original* `a` address has been recycled and its forward
         * pointer overwritten by a fresh allocation, so `vader_array_resolve`
         * can't walk the chain anymore. Box `a` here and root the box so
         * the GC's scan_box re-updates `a_box.payload.obj` through every
         * cycle, then reload `a` from the box afterwards. Same trick for
         * `v` whose payload may also need forwarding. */
        uint32_t tag       = a->header.type_index;
        uint8_t  kind      = a->buf->element_kind;
        size_t   elem_size = vader_array_element_size(kind);
        size_t   src_off   = a->offset;
        vader_box_t a_box; a_box.tag = tag; a_box._pad = 0; a_box.payload.obj = a;
        vader_box_t* roots[2] = { &a_box, &v };
        vader_gc_frame_t frame = { vader_gc_top, 2u, 0u, roots };
        vader_gc_top = &frame;
        size_t cap = a->capacity == 0 ? 4 : a->capacity * 2;
        if (cap <= a->length) cap = a->length + 1;
        vader_array_buf_t* fresh = vader_array_buf_alloc(cap, kind, a->buf->element_tag);
        a = (vader_array_t*) a_box.payload.obj;
        vader_array_buf_t* old = a->buf;
        while (old != NULL && old->header.forward != NULL) {
            old = (vader_array_buf_t*) old->header.forward;
        }
        if (a->length > 0 && old != NULL) {
            memcpy(fresh->slots, old->slots + src_off * elem_size, a->length * elem_size);
        }
        fresh->length = a->length;
        a->buf      = fresh;
        a->capacity = cap;
        a->offset   = 0;
        /* `a` may be old while `fresh` is young — mark the card holding `a`. */
        VADER_WRITE_BARRIER(a);
        vader_gc_top = frame.prev;
    }
    vader_array_store_slot(a->buf, a->offset + a->length, v);
    a->length += 1;
    if (a->offset + a->length > a->buf->length) {
        a->buf->length = a->offset + a->length;
    }
    VADER_WRITE_BARRIER(a->buf);
}

/* ----------------------------------------------------------------- std/string */

size_t vader_string_byte_len(vader_string_t s) {
    return vader_atom_len(s);
}

vader_string_t vader_string_slice(vader_string_t s, size_t start, size_t end) {
    size_t l = vader_atom_len(s);
    if (end > l) end = l;
    if (start >= end) return VADER_ATOM_EMPTY;
    return vader_atom_slice(s, start, end - start);
}

/* Walk the UTF-8 buffer counting codepoints ; return the byte offset of
 * the `cp_index`-th codepoint, clamped to the atom's length. Invalid
 * continuation bytes count as 1-byte codepoints (mirrors
 * `vader_string_char_at`'s truncated-UTF-8 handling). O(n) in `cp_index`. */
static size_t vader_string_codepoint_byte_offset(vader_string_t s, size_t cp_index) {
    const char* data = vader_atom_data(s);
    size_t len = vader_atom_len(s);
    size_t cp = 0;
    size_t i  = 0;
    while (i < len && cp < cp_index) {
        uint8_t b = (uint8_t) data[i];
        size_t step;
        if (b < 0x80u)       step = 1;
        else if (b < 0xC0u)  step = 1;   /* stray continuation byte */
        else if (b < 0xE0u)  step = 2;
        else if (b < 0xF0u)  step = 3;
        else                 step = 4;
        if (i + step > len) step = len - i;
        i  += step;
        cp += 1;
    }
    return i;
}

/* `string[lo..<hi]` semantic : `lo` and `hi` are codepoint indices.
 * Returns the canonical atom for the byte range (intern-deduped or
 * fresh slice atom borrowing into the parent buffer). */
vader_string_t vader_string_slice_codepoints(vader_string_t s, size_t cp_lo, size_t cp_hi) {
    if (cp_hi < cp_lo) cp_hi = cp_lo;
    size_t byte_lo = vader_string_codepoint_byte_offset(s, cp_lo);
    size_t byte_hi = vader_string_codepoint_byte_offset(s, cp_hi);
    if (byte_hi <= byte_lo) return VADER_ATOM_EMPTY;
    return vader_atom_slice(s, byte_lo, byte_hi - byte_lo);
}

/* `s[i]` semantic — codepoint at codepoint-index `i`. Traps on OOB.
 * Counterpart to `vader_string_byte_at` for the byte-indexed access. */
vader_char_t vader_string_codepoint_at(vader_string_t s, size_t cp_index) {
    size_t byte_off = vader_string_codepoint_byte_offset(s, cp_index);
    if (byte_off >= vader_atom_len(s)) vader_trap("string codepoint index out of bounds");
    return vader_string_char_at(s, byte_off);
}

vader_box_t vader_string_parse_float(vader_string_t s, uint32_t ok_tag, uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(s);
    char* end;
    double v = strtod(p, &end);
    int ok = (end != p && *end == '\0');
    vader_atom_cstr_free(p);
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
    size_t len = vader_atom_len(s);
    if (i >= len) vader_trap("string index out of bounds");
    const uint8_t* p = (const uint8_t*)(vader_atom_data(s) + i);
    size_t rem = len - i;
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
    if (i >= vader_atom_len(s)) vader_trap("string index out of bounds");
    return (vader_u8_t)(uint8_t) vader_atom_data(s)[i];
}

/* Zero-copy `const u8[]` view over `s`'s interned bytes — see the header
 * decl. Allocates only the array header ; `buf` stays NULL and reads route
 * through `vader_atom_data(s)` (`vader_array_get` / `_slice`). `capacity`
 * packs `(elem_tag << 32) | owner_atom_id` so reads box each byte with the
 * right element tag and `vader_atom_mark_heap` recovers the owner (low 32
 * bits). The view is flagged VADER_ARRAY_FLAG_BORROWED. 64-bit `capacity`
 * assumed (the runtime targets 64-bit throughout).
 *
 * `s` needs no extra rooting across the alloc : it is an atom id (a value,
 * not a heap pointer) and the caller holds the source string live on the
 * shadow stack, so any major cycle inside `vader_gc_alloc` keeps the atom
 * marked. No allocation runs between the alloc and the field writes, so
 * `view` cannot move before it is populated. */
vader_array_t* vader_string_bytes_view(vader_string_t s, uint32_t arr_type, uint32_t elem_tag) {
    size_t len = vader_atom_len(s);
    vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
    vader_obj_header_init(view, arr_type);
    view->length = len;
    view->offset = 0;
    view->buf    = NULL;
    vader_array_make_borrowed(view, elem_tag, s);   /* sets flag + packs capacity */
    return view;
}

/* Inverse of `vader_string_bytes_view` — see the header. A borrowed view
 * aliases `owner[offset .. offset+len]`, so `vader_atom_slice` reinterprets
 * those bytes as a string atom in O(1) (intern-deduped, no copy of the byte
 * storage). A materialised `u8[]` (rare — e.g. a built array) is gathered
 * byte-by-byte and interned. Bytes are taken verbatim ; no UTF-8 validation. */
vader_string_t vader_string_as_string(vader_array_t* a) {
    a = vader_array_resolve(a);
    size_t len = a->length;
    if (len == 0) return VADER_ATOM_EMPTY;
    if (vader_array_is_borrowed(a)) {
        return vader_atom_slice(vader_array_borrowed_owner(a), a->offset, len);
    }
    /* Materialised KIND_U8 buffer : gather via `vader_array_get` (no alloc, so
     * `buf` stays valid across the loop) and intern a copy. */
    char* buf = (char*) malloc(len + 1u);
    if (buf == NULL) vader_trap("vader_string_as_string: buffer malloc failed");
    for (size_t i = 0; i < len; i++) {
        buf[i] = (char) (uint8_t) vader_array_get(a, i).payload.i;
    }
    return vader_atom_intern_take(buf, len);
}

/* Box the host argv into a `[string]` Vader array. Called from emitted main
 * when the user's `main` takes an `[string]` parameter. The caller passes the
 * BcType indices for the array type and the string element type (the emitter
 * knows them at codegen time).
 *
 * Each `vader_array_push` may collect; the shadow-stack frame keeps `arr_box`
 * reachable so its `payload.obj` tracks the array across moves. */
vader_array_t* vader_runtime_argv(int argc, char** argv, uint32_t arr_type, uint32_t str_type) {
    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
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

/* ----------------------------------------------------------------- builder */

static void builder_reserve(vader_builder_t* b, size_t extra) {
    if (b->len + extra <= b->cap) return;
    size_t cap = b->cap == 0 ? 64 : b->cap;
    while (cap < b->len + extra) cap *= 2;
    /* Plain malloc/free — the buf is private to the builder until
     * `vader_builder_finish` hands it to `vader_atom_intern_take`, which
     * either adopts the buffer (on miss) or frees it (on hit). */
    char* fresh = (char*) malloc(cap + 1u);
    if (fresh == NULL) vader_trap("builder_reserve: malloc failed");
    if (b->len > 0) memcpy(fresh, b->buf, b->len);
    free(b->buf);
    b->buf = fresh;
    b->cap = cap;
}

vader_builder_t* vader_builder_new(void) {
    vader_builder_t* b = (vader_builder_t*) malloc(sizeof(vader_builder_t));
    if (b == NULL) vader_trap("vader_builder_new: malloc failed");
    b->buf = NULL; b->len = 0; b->cap = 0;
    b->next = g_builder_head;
    g_builder_head = b;
    return b;
}

/* Unlink a builder from the active-list. O(n) walk over currently-active
 * builders ; that list is short (one entry per nested interpolation in
 * flight), so a doubly-linked variant would be wasted complexity. */
static void vader_builder_unlink(vader_builder_t* b) {
    vader_builder_t** cursor = &g_builder_head;
    while (*cursor != NULL && *cursor != b) cursor = &(*cursor)->next;
    if (*cursor == NULL) vader_trap("vader_builder_unlink: builder not in active list");
    *cursor = b->next;
}

void vader_builder_append_str(vader_builder_t* b, vader_string_t s) {
    size_t n = vader_atom_len(s);
    if (n == 0) return;
    builder_reserve(b, n);
    memcpy(b->buf + b->len, vader_atom_data(s), n);
    b->len += n;
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
    /* Hand the buffer to `vader_atom_intern_take` — on miss it adopts
     * the buffer as the atom's owner data ; on hit it frees the buffer
     * and returns the canonical atom. The builder struct itself has no
     * use after finish. */
    size_t len = b->len;
    char* buf  = b->buf;
    vader_builder_unlink(b);
    free(b);
    if (len == 0) {
        if (buf != NULL) free(buf);
        return VADER_ATOM_EMPTY;
    }
    if (buf == NULL) return VADER_ATOM_EMPTY;
    return vader_atom_intern_take(buf, len);
}

/* Flatten an array of strings into a single string in one allocation. Used
 * by std/string_builder StringBuilder.to_string to avoid the O(N²) of repeated `+`. */
vader_string_t vader_string_concat_all(vader_array_t* parts) {
    if (parts->length == 0) return VADER_ATOM_EMPTY;
    vader_box_t* slots = vader_array_box_slots(parts->buf) + parts->offset;
    size_t total = 0;
    for (size_t i = 0; i < parts->length; i++) {
        total += vader_atom_len((vader_string_t) slots[i].payload.s);
    }
    if (total == 0) return VADER_ATOM_EMPTY;
    char* buf = (char*) malloc(total + 1u);
    if (buf == NULL) vader_trap("vader_string_concat_all: malloc failed");
    size_t pos = 0;
    for (size_t i = 0; i < parts->length; i++) {
        vader_string_t s = (vader_string_t) slots[i].payload.s;
        size_t n = vader_atom_len(s);
        if (n > 0) {
            memcpy(buf + pos, vader_atom_data(s), n);
            pos += n;
        }
    }
    return vader_atom_intern_take(buf, total);
}

/* ----------------------------------------------------------------- I/O */

/* `stream_tag` mirrors `std/io::Stream` ; anything outside {Stdout, Stderr}
 * traps. The `println` / `eprintln` newline emission lives in the Vader-side
 * wrappers, not here. */
#define VADER_STREAM_STDOUT ((int32_t) 0)
#define VADER_STREAM_STDERR ((int32_t) 1)

void vader_write(int32_t stream_tag, vader_string_t s) {
    FILE* f;
    if      (stream_tag == VADER_STREAM_STDOUT) f = stdout;
    else if (stream_tag == VADER_STREAM_STDERR) f = stderr;
    else    vader_trap("vader_write: invalid stream tag");
    fwrite(vader_atom_data(s), 1, vader_atom_len(s), f);
    fflush(f);
}

/* Tag-aware variants — the emitter passes the BcType indices for the success
 * and error variants. Caller-side boxing keeps the runtime tag-agnostic. */
vader_box_t vader_read_file(vader_string_t path, uint32_t ok_tag, uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(path);
    FILE* f = fopen(p, "rb");
    vader_atom_cstr_free(p);
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

    char* buf = (char*) malloc((size_t) size + 1u);
    if (buf == NULL) { fclose(f); vader_trap("read_file: malloc failed"); }
    size_t n = fread(buf, 1, (size_t) size, f);
    fclose(f);
    if (n != (size_t) size) {
        free(buf);
        return vader_box_string(err_tag, vader_string_new("short read", 10));
    }
    return vader_box_string(ok_tag, vader_atom_intern_take(buf, (size_t) size));
}

vader_box_t vader_write_file(vader_string_t path, vader_string_t content,
                             uint32_t ok_tag, uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(path);
    FILE* f = fopen(p, "wb");
    vader_atom_cstr_free(p);
    if (f == NULL) return vader_box_string(err_tag, vader_string_new("open failed", 11));
    size_t clen = vader_atom_len(content);
    size_t n = fwrite(vader_atom_data(content), 1, clen, f);
    fclose(f);
    if (n != clen) return vader_box_string(err_tag, vader_string_new("short write", 11));
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
    return vader_box_string(ok_tag, vader_string_new(buf, n));
}

/* Switch stdin/stdout to binary mode on Windows. The CRT default is
 * text mode, which silently translates `\r\n` ↔ `\n` and breaks any
 * length-prefixed binary transport (LSP, MCP, custom RPC). Called once
 * at the first `vader_read_stdin` invocation ; idempotent via the
 * static flag. POSIX has no such concept — the helper is a no-op there. */
static int g_stdio_binary_ready = 0;

static void vader_ensure_stdio_binary(void) {
    if (g_stdio_binary_ready) return;
    g_stdio_binary_ready = 1;
#if defined(_WIN32)
    _setmode(_fileno(stdin),  _O_BINARY);
    _setmode(_fileno(stdout), _O_BINARY);
#endif
}

/* Read EXACTLY `n` bytes from stdin into a fresh string. Loops over
 * `fread` until `n` bytes have been accumulated or EOF is reached. EOF
 * before `n` bytes is an error — the LSP transport relies on this
 * "exactly N bytes" contract for Content-Length framing. Forces binary
 * mode on first call so `\r\n` survives the read on Windows. */
vader_box_t vader_read_stdin(size_t n, uint32_t ok_tag, uint32_t err_tag) {
    vader_ensure_stdio_binary();
    if (n == 0) {
        return vader_box_string(ok_tag, vader_string_new("", 0));
    }
    char* buf = (char*) malloc(n + 1u);
    if (buf == NULL) vader_trap("read_stdin: malloc failed");
    size_t got = 0;
    while (got < n) {
        size_t r = fread(buf + got, 1, n - got, stdin);
        if (r == 0) {
            if (feof(stdin)) {
                free(buf);
                return vader_box_string(err_tag, vader_string_new("EOF", 3));
            }
            if (ferror(stdin)) {
                free(buf);
                return vader_box_string(err_tag, vader_string_new("stdin read error", 16));
            }
            /* No data, no EOF, no error — interrupted read. Retry. */
            continue;
        }
        got += r;
    }
    return vader_box_string(ok_tag, vader_atom_intern_take(buf, n));
}

/* `exists` / `is_dir` / `read_dir` — filesystem queries split across POSIX
 * (`dirent.h`, `sys/stat.h`) and Windows (`FindFirstFileA` /
 * `GetFileAttributesA`). `exists` must NOT be implemented via `fopen` : the
 * Windows CRT refuses to open a directory as a file, so an `fopen`-based
 * check reports every directory as missing. That silently empties the
 * module-discovery walk — `walk_root` (vader/resolver/discover.vader) guards
 * on `exists(dir)` and bails before indexing anything, so every compile on
 * Windows fails with R2001. Use the stat / attribute query instead. Path
 * arguments come as atom IDs ; we materialise a NUL-terminated C string via
 * `vader_atom_to_cstr` and intern dirent names back through `vader_string_new`. */

#if defined(_WIN32)

vader_bool_t vader_exists(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    DWORD attr = GetFileAttributesA(p);
    vader_atom_cstr_free(p);
    return attr != INVALID_FILE_ATTRIBUTES;
}

vader_bool_t vader_is_dir(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    DWORD attr = GetFileAttributesA(p);
    vader_atom_cstr_free(p);
    return attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY);
}

vader_box_t vader_read_dir(vader_string_t path, uint32_t arr_type,
                           uint32_t str_type, uint32_t err_tag) {
    /* FindFirstFileA expects a glob — append "\\*". */
    const char* p = vader_atom_to_cstr(path);
    size_t plen = vader_atom_len(path);
    char* pat = (char*) malloc(plen + 3);
    if (pat == NULL) {
        vader_atom_cstr_free(p);
        vader_trap("read_dir: malloc failed");
    }
    memcpy(pat, p, plen);
    size_t pat_len = plen;
    if (pat_len > 0 && pat[pat_len - 1] != '\\' && pat[pat_len - 1] != '/') {
        pat[pat_len++] = '\\';
    }
    pat[pat_len++] = '*';
    pat[pat_len] = '\0';
    vader_atom_cstr_free(p);

    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pat, &fd);
    free(pat);
    if (h == INVALID_HANDLE_VALUE) {
        return vader_box_string(err_tag, vader_string_new("read_dir failed", 15));
    }

    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
    VADER_GC_PUSH1(arr_box);
    do {
        const char* name = fd.cFileName;
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))) continue;
        size_t n = strlen(name);
        /* `fd.cFileName` lives on the stack and is overwritten by the
         * next FindNextFileA — intern via `vader_string_new` to copy the
         * bytes into the atom table before the next iteration. */
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

vader_bool_t vader_exists(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    struct stat st;
    int rc = stat(p, &st);
    vader_atom_cstr_free(p);
    return rc == 0;
}

vader_bool_t vader_is_dir(vader_string_t path) {
    const char* p = vader_atom_to_cstr(path);
    struct stat st;
    int rc = stat(p, &st);
    vader_atom_cstr_free(p);
    return rc == 0 && S_ISDIR(st.st_mode);
}

vader_box_t vader_read_dir(vader_string_t path, uint32_t arr_type,
                           uint32_t str_type, uint32_t err_tag) {
    const char* p = vader_atom_to_cstr(path);
    DIR* d = opendir(p);
    vader_atom_cstr_free(p);
    if (d == NULL) {
        return vader_box_string(err_tag, vader_string_new("read_dir failed", 15));
    }

    vader_box_t arr_box = vader_box_obj(arr_type, vader_array_new(arr_type, 0, VADER_ARRAY_KIND_BOXED, str_type));
    VADER_GC_PUSH1(arr_box);
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        const char* name = ent->d_name;
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))) continue;
        size_t n = strlen(name);
        /* Intern the dirent name directly — the buffer is reused on the
         * next readdir, so the atom dedupe/copy is the correct ownership
         * transfer. */
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
 * `vader_string_alloc`-ed and ownership is transferred to the caller when
 * it consumes `vader_spawn_last_stdout` / `_stderr` — the getter clears the
 * globals so the Vader-side `vader_string_t` becomes the sole reference.
 *
 * If a `spawn_run` fires before the previous capture was consumed (a caller
 * that drops the result on the floor), `capture_spawn_output` reclaims the
 * abandoned buffer via `vader_string_free`. This avoids the O(N) growth a
 * long-running process — LSP, watch-mode — would otherwise hit. The
 * transferred buffer in the consumed case stays alive in the tracked
 * string arena until it becomes unreachable, at which point the next sweep
 * collects it. */
static char*  g_spawn_stdout_buf = NULL;
static size_t g_spawn_stdout_len = 0;
static char*  g_spawn_stderr_buf = NULL;
static size_t g_spawn_stderr_len = 0;

static void capture_spawn_output(char** dst_buf, size_t* dst_len, char* src, size_t src_len) {
    /* Reclaim the previous capture if the caller never consumed it.
     * Safe because a consumer (`vader_spawn_last_stdout` / `_stderr`)
     * clears the slot to NULL on extraction — a non-NULL `*dst_buf` here
     * is guaranteed to be the unique reference. The captured buffer is
     * a plain malloc heap owned by this module (not an atom — atoms are
     * the canonical view ; this is the transit buffer). */
    if (*dst_buf != NULL) {
        free(*dst_buf);
        *dst_buf = NULL;
        *dst_len = 0;
    }
    if (src == NULL || src_len == 0) {
        if (src != NULL) free(src);
        return;
    }
    *dst_buf = src;
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
        cap += vader_atom_len((vader_string_t) b.payload.s) * 2 + 3;
    }
    char* cmdline = (char*) malloc(cap);
    if (cmdline == NULL) return VADER_SPAWN_LAUNCH_FAIL;
    size_t pos = 0;
    for (size_t i = 0; i < n; i++) {
        vader_box_t b = vader_array_get(argv, i);
        vader_string_t s = (vader_string_t) b.payload.s;
        size_t slen = vader_atom_len(s);
        char* z = (char*) malloc(slen + 1);
        if (z == NULL) { free(cmdline); return VADER_SPAWN_LAUNCH_FAIL; }
        memcpy(z, vader_atom_data(s), slen); z[slen] = '\0';
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
        vader_string_t s = (vader_string_t) b.payload.s;
        size_t slen = vader_atom_len(s);
        char* z = (char*) malloc(slen + 1);
        if (z == NULL) {
            for (size_t j = 0; j < i; j++) free(cargv[j]);
            free(cargv);
            return VADER_SPAWN_LAUNCH_FAIL;
        }
        memcpy(z, vader_atom_data(s), slen); z[slen] = '\0';
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

/* Transfer ownership of the captured buffer to the caller. The Vader-side
 * `vader_string_t` becomes the unique reference ; the next `spawn_run`
 * therefore won't touch this memory and the caller is free to keep it
 * around (it'll live under the same leak budget as every other
 * `vader_string_alloc` result — see the file-top comment on string memory).
 *
 * Before any spawn ran, both buf and len are 0 — hand back the empty
 * sentinel so callers can safely `memcpy` / `fwrite` zero bytes from
 * `.ptr` without dereferencing NULL. Calling the getter twice without an
 * intervening `spawn_run` yields the empty sentinel on the second call,
 * which matches the documented non-reentrant "last call wins" contract. */
vader_string_t vader_spawn_last_stdout(void) {
    char*  buf = g_spawn_stdout_buf;
    size_t len = g_spawn_stdout_len;
    g_spawn_stdout_buf = NULL;
    g_spawn_stdout_len = 0;
    return vader_string_new(buf != NULL ? buf : "", len);
}

vader_string_t vader_spawn_last_stderr(void) {
    char*  buf = g_spawn_stderr_buf;
    size_t len = g_spawn_stderr_len;
    g_spawn_stderr_buf = NULL;
    g_spawn_stderr_len = 0;
    return vader_string_new(buf != NULL ? buf : "", len);
}

/* ----------------------------------------------------------------- traps */

void vader_unreachable(const char* where) {
    fprintf(stderr, "vader: reached unreachable at %s\n", where);
    abort();
}

/* ---------- VADER_GC_PROFILE — live-set breakdown by type ---------- */

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

/* Walk both arenas' from-spaces and tally objects bucketed by type_index.
 * Sort by total bytes, print top-20. Called via atexit when
 * VADER_GC_PROFILE is set, and inline from the OOM trap (abort() skips
 * atexit). */
void vader_gc_profile_dump(void) {
    if (!g_gc_initialized) return;
    /* +1 for the ARRAY_BUF sentinel bucket. ARRAY_BUF objects (header tag
     * VADER_TYPE_INDEX_ARRAY_BUF) are tallied into this one extra bucket, just
     * past the real type indices [0, count) — see the bucketing + display below. */
    size_t nbuckets = vader_type_info_count + 1u;
    const size_t array_buf_bucket = vader_type_info_count;
    vader_gc_prof_entry_t* tally = (vader_gc_prof_entry_t*) calloc(nbuckets, sizeof(vader_gc_prof_entry_t));
    if (tally == NULL) return;
    for (size_t i = 0; i < nbuckets; i++) tally[i].type_index = (uint32_t) i;

    const vader_arena_t* gens[2] = { &g_young.from, &g_old.from };
    size_t totals[2] = { 0, 0 };
    for (int g = 0; g < 2; g++) {
        char* scan = gens[g]->base;
        while (scan < gens[g]->cur) {
            vader_obj_header_t* hdr = (vader_obj_header_t*) scan;
            uint32_t type_index = hdr->type_index;
            size_t bytes = vader_gc_obj_size(scan, type_index);
            if (bytes == 0) break;
            size_t bucket = (type_index == VADER_TYPE_INDEX_ARRAY_BUF)
                ? array_buf_bucket
                : (type_index < vader_type_info_count ? type_index : 0);
            tally[bucket].count += 1u;
            tally[bucket].bytes += bytes;
            totals[g] += bytes;
            scan += vader_gc_align(bytes);
        }
    }
    qsort(tally, nbuckets, sizeof(vader_gc_prof_entry_t), vader_gc_prof_cmp);

    fprintf(stderr, "\n=== vader_gc_profile : live-set breakdown ===\n");
    fprintf(stderr, "young from-space : %.2f MB live (of %zu MB arena)\n",
            (double) totals[0] / (1024.0 * 1024.0),
            g_young.half_bytes / (1024u * 1024u));
    fprintf(stderr, "old   from-space : %.2f MB live (of %zu MB arena)\n",
            (double) totals[1] / (1024.0 * 1024.0),
            g_old.half_bytes / (1024u * 1024u));
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
                case VADER_TYPE_KIND_INLINE_REF: kind_name = "INLINE_REF"; break;
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
}

void vader_trap(const char* msg) {
    fprintf(stderr, "vader: trap — %s\n", msg);
    abort();
}

void vader_panic(vader_string_t msg) {
    fprintf(stderr, "vader: panic — %.*s\n", (int) vader_atom_len(msg), vader_atom_data(msg));
    abort();
}
