# Atom-based string interning — migration plan (Option A)

`vader_string_t` becomes `u32` — every `string` in the language *is* an
atom indexing a global `AtomTable`. Carrier shrinks 16 B → 4 B
everywhere, `==` and hash become O(1) integer ops, the per-allocation
`vader_string_header_t` + mark-sweep machinery disappears, and the
`vader_box_t` payload shrinks 24 B → 16 B (collateral gain on every
tagged union in the runtime).

**Status** — designed and validated (2026-05-25), not yet implemented.
Architectural decisions are frozen ; phases pick up sequentially.

## Why

Profile evidence from
`VADER_GC_PROFILE=1 ./build/vader dump --stage=typed-ast vader/cli/main.vader`
(2026-05-25, after the morning's erasure-dedupe work) :

- **81 MB live working-set** at peak.
- `Position` (struct, 48 B) — **345k instances**, 16.5 MB. `file: string`
  field carries 16 B × 345k = ~5.5 MB despite pointing at ~200 distinct
  paths.
- Similar pattern on `Token.text` (510k × 16 B = ~8 MB for ~1k distinct
  identifiers), `IdentExpr.name` / `FieldExpr.name` (~70k × 16 B).
- `vader_box_t` is 24 B because its payload union accommodates the 16 B
  `vader_string_t` fat-ptr. Every union value, every `T | null`, every
  Result, pays that overhead.

The collateral consequences of going atomic are :

- `string == string` collapses to `u32 ==` — match-on-string-literal
  arms (already in SPEC.md §"Pattern matching") become idiomatic at
  enum-tag cost.
- `Box` shrinks 24 B → 16 B — gain compounds across every tagged union
  in the runtime, not just strings.
- The 300+ lines of `vader_string_*` GC infrastructure
  (`vader_string_alloc` / `vader_string_header_t` / `g_string_head` /
  `g_string_sorted_index` / `vader_string_prepare_marks` /
  `vader_string_mark_ptr` / `vader_string_gc_collect`) disappear from
  `runtime/c/vader_runtime.c`. Replaced by ~150 lines of atom-table
  infrastructure with a simpler ownership model.

Estimated total saving on the self-host typecheck baseline :
**~20-25 MB working-set** (combining string carrier compaction + box
shrink + dropped per-string headers).

## Goals

- `vader_string_t` is `u32` everywhere — runtime, codegen, AST.
- `==` and `hash` on `string` are O(1) integer ops, inline.
- `vader_box_t` shrinks 24 B → 16 B (audit cascade : ~30 sites).
- `match` arms on string literals dispatch as `u32 ==` chains (free
  upgrade, no lowerer change required).
- Comptime atom indices are **stable across builds** and emitted as
  C compile-time constants, enabling `static const vader_string_t
  ATOM_X = N;` in generated code.
- Slice-share : tokens that are substrings of `SourceFile.content`
  reuse the source's bytes (zero alloc per token).
- Long-running programs : GC reclaims runtime-allocated atoms that are
  no longer reachable (tombstone-based).
- Single-threaded MVP — concurrency support deferred to 1.0.

## Non-goals

- Compaction of atom indices. Tombstones reclaim bytes ; indices stay
  stable for the lifetime of the program (otherwise every `u32` in
  every variable would need rewriting on compaction).
- Refcount-based atom freeing. Per-copy increment/decrement cost
  defeats the carrier-size gain.
- Multi-threaded atom intern in MVP. Atom table is single-writer,
  single-reader.

## Architecture

### Type model

```c
typedef vader_u32_t vader_string_t;        /* was {const char*, size_t} */

typedef struct {
    vader_u32_t parent;          /* 0 = self-owned ; otherwise atom id whose
                                    bytes we slice into */
    vader_u32_t parent_offset;   /* byte offset within parent.data ; ignored
                                    if owner */
    vader_u32_t len;             /* string length in bytes */
    vader_u16_t flags;           /* bit 0 = PERM (never collected) ;
                                    bit 1 = MARK (transient GC bit) */
    vader_u16_t _pad;
    const char* data;            /* materialised pointer : owner = own malloc,
                                    slice = parent.data + parent_offset.
                                    Always NUL-terminated at data[len]. */
} vader_atom_entry_t;             /* 24 B */

typedef struct {
    vader_atom_entry_t* entries;
    vader_u32_t         count;
    vader_u32_t         capacity;

    /* Open-addressing hash : intern lookup */
    vader_u32_t* buckets;          /* atom id, 0 = empty slot */
    vader_u32_t  bucket_capacity;  /* power of two */

    /* Free list of tombstone indices, reused by intern_owner */
    vader_u32_t* free_list;
    vader_u32_t  free_count;
    vader_u32_t  free_capacity;
} vader_atom_table_t;

extern vader_atom_table_t g_atoms;
```

### Index layout

```
[0]              ""  (PERM sentinel — empty string)
[1 .. K]         pre-interned keywords + primitives (PERM, indices figés
                 par codegen et exposés en C par #define ATOM_KW_FN 1, etc.)
[K+1 .. N]       module comptime atoms (PERM, serialized into the binary)
[N+1 ..]         runtime-allocated atoms (collectable)
```

`PERM` atoms are never freed and never tombstoned. They cover the static
text of the program (keywords, primitives, every `StringLitExpr.value`
the codegen ever saw). Only atoms minted dynamically at runtime
(`concat`, `format`, user `read_file` results, etc.) can be GC'd.

### Bytes allocation — slice-share

Two ownership modes :

- **Owner atom** : `parent == 0`. `data` points at a `malloc(len + 1)`
  buffer (NUL-term inline at `data[len]`). Buffer is freed when the
  atom is collected.
- **Slice atom** : `parent != 0`. `data = entries[parent].data +
  parent_offset`. No allocation. NUL termination is *not* guaranteed at
  `data[len]` for a slice (it may be a different byte of the parent).

`vader_atom_to_cstr(a)` returns `entries[a].data` for owners (always
NUL-term) and does a per-call `strndup`-style dup for slices (rare path).

The slice path is what makes lexer token interning quasi-free :
`SourceFile.content` is one owner atom (malloc'd at file load) ; every
identifier / keyword / number token from the parse is a slice atom into
that content. Zero bytes allocated per token.

### Slicing rules

```
vader_atom_intern(data, len) :
    h = fnv1a(data, len)
    for atom in bucket_probe(h) :
        if entry(atom).len == len and memcmp(entry(atom).data, data, len) == 0 :
            return atom        /* dedupe : returns canonical atom */
    /* miss : install as owner */
    buf = malloc(len + 1); memcpy(buf, data, len); buf[len] = 0
    return push_entry({ parent=0, len, data=buf, flags=0 })

vader_atom_slice(parent_atom, offset, len) :
    candidate = entry(parent_atom).data + offset
    h = fnv1a(candidate, len)
    for atom in bucket_probe(h) :
        if entry(atom).len == len and memcmp(entry(atom).data, candidate, len) == 0 :
            return atom        /* dedupe : retours canonical, even if it's
                                  itself an owner — no double-storage */
    /* miss : install as slice (no allocation) */
    return push_entry({ parent=parent_atom, parent_offset=offset, len,
                        data=candidate, flags=0 })
```

**Dedup is independent of ownership** : two atoms with identical bytes
are always fused at intern time. Slice-share is purely a storage
optimisation : when the bytes already live in another atom that we keep
alive, we avoid copying them. Whether the canonical representative
ends up owner or slice depends on intern order — and that's fine, the
hash-based dedupe handles it.

### Garbage collection

Integrated into the existing major Cheney cycle in
`vader_runtime.c:1022 vader_string_gc_collect` — but the implementation
is replaced wholesale.

**Mark phase** (extension of the major cycle) :
1. Walk shadow-stack frames ; for each Vader-typed slot of kind
   `string`, mark the atom.
2. Walk every reachable GC object ; for each `string` field
   (`vader_type_info.string_offsets[]`), mark the atom.
3. Walk every reachable `vader_box_t` ; if `tag` is a string variant,
   mark `payload.s`.
4. Transitive closure : `mark(a)` also marks `entries[a].parent`
   recursively (slice → owner chain). Invariant : every marked child
   has a marked parent. **Audit this invariant after the mark
   phase.**
5. `PERM` atoms are always considered marked — no work.

**Sweep phase** :
- For each non-PERM atom not marked :
  - If owner : `free(entries[a].data)`.
  - Push `a` onto `free_list`.
  - Clear hash bucket entry (the canonical-atom slot for these bytes
    is gone — a future intern of identical bytes will install a new
    atom).
- Marked bits are cleared in the same pass.

**Tombstone reuse** : next `vader_atom_intern_owner` pulls from
`free_list` before growing `entries[]`. The atom id is reused with new
content. Indices remain stable for the duration any value holds them,
because reuse only happens after the GC has proven no value still
holds the old id.

**Capacity policy** :
- `entries[]` grows by doubling. Never shrinks.
- `buckets[]` grows on load factor > 0.75. Rehash by reinsert.

### Compile-time atom serialisation

The compiler aggregates *all* string literals reachable from the entry
module + every well-known atom (keywords, primitives) into a sorted,
deduplicated list. At codegen, this list is serialised into the
emitted C as :

```c
/* In <module>.c, top of file */

static const char vader_atom_blob[] =
    "\0"                              /* [0] : "" */
    "fn\0"                            /* [1] : ATOM_KW_FN */
    "struct\0"                        /* [2] : ATOM_KW_STRUCT */
    /* ... ~25 keywords, ~18 primitives, then module literals */
    "hello\0"                         /* [K+12] : ATOM_LIT_HELLO */
    "world\0"                         /* [K+13] : ATOM_LIT_WORLD */
    /* ... */
    ;

#define ATOM_KW_FN        1u
#define ATOM_KW_STRUCT    2u
/* ... */
#define ATOM_LIT_HELLO    (K + 12u)
#define ATOM_LIT_WORLD    (K + 13u)
/* ... */
#define VADER_COMPTIME_ATOM_COUNT  ((K + N) + 1u)

static const vader_atom_entry_t vader_atom_comptime_table[] = {
    { 0, 0, 0,  VADER_ATOM_PERM, &vader_atom_blob[0]  },
    { 0, 0, 2,  VADER_ATOM_PERM, &vader_atom_blob[1]  },
    { 0, 0, 6,  VADER_ATOM_PERM, &vader_atom_blob[4]  },
    /* ... one entry per comptime atom */
};
```

The blob lives in `.rodata` (no heap), the table is a constant array,
and `vader_atom_init()` does :

```c
g_atoms.entries  = malloc(initial_capacity * sizeof(vader_atom_entry_t));
g_atoms.capacity = initial_capacity;        /* VADER_COMPTIME_ATOM_COUNT * 2 */
memcpy(g_atoms.entries, vader_atom_comptime_table,
       VADER_COMPTIME_ATOM_COUNT * sizeof(vader_atom_entry_t));
g_atoms.count = VADER_COMPTIME_ATOM_COUNT;
vader_atom_rebuild_index();    /* scan + hash all comptime atoms */
```

Boot cost : a memcpy + one linear hash pass over ~10k atoms (~1 ms on
modern hardware).

**Index stability across builds** : the codegen sorts comptime atoms
in a deterministic order — well-known atoms first (fixed list), then
module atoms sorted by `(module_path, source_appearance_order)`.
Recompiling the same source yields identical indices. CI snapshot can
include `vader_atom_comptime_table` as a regression target.

**Multi-module aggregation** : only the entry module emits the
`vader_atom_blob` and `vader_atom_comptime_table`. Other modules
reference `ATOM_*` macros via `extern` / shared header. Codegen tracks
the union of comptime atoms across the import graph at link time.

### Pre-interned atoms (minimum policy)

Phase 0 publishes a fixed list :

- `ATOM_EMPTY = 0` (the empty string)
- All keywords from `vader/lexer/keywords.vader`
  (~25 entries : `fn`, `struct`, `trait`, `enum`, `match`, `is`, `if`,
  `else`, `for`, `in`, `return`, `defer`, `break`, `continue`,
  `import`, `module`, `export`, `as`, `true`, `false`, `null`,
  `self`, `Self`, `_`, …)
- All primitive type names (~18 entries : `i8` … `i64`, `u8` … `u64`,
  `f32`, `f64`, `bool`, `char`, `string`, `void`, `usize`, `isize`,
  `never`)

Extending the list later (well-known field names like `len`, common
method names like `to_string`, trait names like `Display`, …) is a
runtime-source-only change : add to `well_known_atoms.vader`, recompile.
No structural impact.

## Op cascades

### Literal `"hello"`

- **Parser** : `StringLitExpr.value: Atom` (interned in compile-time
  atom table).
- **Codegen** : emits `ATOM_LIT_HELLO` (a `#define` to a `u32`
  constant) wherever the literal is used.
- **Runtime** : `x = ATOM_LIT_HELLO;` is a single `u32` assignment.

### Equality `a == b`

```c
/* Old emit */ if (vader_string_eq(a, b)) { ... }    // strcmp loop
/* New emit */ if (a == b) { ... }                   // u32 compare, inline
```

`vader_string_eq` is kept for the FFI boundary (boxes, dynamic
dispatch) but the lowerer emits `u32 ==` inline for the common case.

### Concat `"hello " + name`

```c
greeting = vader_string_concat(ATOM_LIT_HELLO_SPACE, name);

vader_string_t vader_string_concat(vader_string_t a, vader_string_t b) {
    vader_atom_entry_t* ea = &g_atoms.entries[a];
    vader_atom_entry_t* eb = &g_atoms.entries[b];
    size_t total = ea->len + eb->len;
    char* buf = malloc(total + 1);
    memcpy(buf,           ea->data, ea->len);
    memcpy(buf + ea->len, eb->data, eb->len);
    buf[total] = 0;
    /* intern : dedupe + transfer ownership of buf if miss */
    return vader_atom_intern_take(buf, total);
}
```

`_take` variant : on hash miss, transfers ownership of `buf` into the
entry (no extra copy). On hit, frees `buf` and returns the canonical
atom.

### Codepoint indexing `s[i]`

```c
vader_char_t vader_string_codepoint_at(vader_string_t s, size_t i) {
    vader_atom_entry_t* e = &g_atoms.entries[s];        /* 1 indirection */
    return vader_decode_utf8_at(e->data, e->len, i);   /* unchanged */
}
```

### Slice `s[a..b]`

```c
vader_string_t vader_string_slice(vader_string_t s, size_t a, size_t b) {
    vader_atom_entry_t* e = &g_atoms.entries[s];
    return vader_atom_slice(s, a, b - a);              /* slice-share */
}
```

### `to_cstr` (FFI)

```c
const char* vader_string_to_cstr(vader_string_t s) {
    vader_atom_entry_t* e = &g_atoms.entries[s];
    if (e->parent == 0) {
        return e->data;            /* owner : NUL-term inline, no dup */
    }
    /* slice : data is in the middle of parent ; dup for NUL-term */
    char* dup = malloc(e->len + 1);
    memcpy(dup, e->data, e->len);
    dup[e->len] = 0;
    return dup;
}
```

`vader_cstr_free` becomes : free if heap, no-op if owner-data. Caller
discipline preserved.

### StringBuilder

`vader_builder_t` remains a distinct runtime type. It accumulates raw
bytes via `malloc/realloc`. At `.to_string()` :

```c
vader_string_t vader_builder_finish(vader_builder_t* b) {
    vader_string_t a = vader_atom_intern_take(b->buf, b->len);
    /* On hit, intern_take frees b->buf and returns the canonical atom.
       On miss, b->buf is now owned by the table. */
    b->buf = NULL;
    return a;
}
```

The builder is the escape valve : intermediate buffers from
`format` / `display` / large concatenation chains never pollute the
atom table — only the final string lands in it.

### `match` on string literal

```vader
match method {
    "GET"    -> 200
    "POST"   -> 201
    "DELETE" -> 204
    _        -> 405
}
```

The lowerer already emits `scrutinee == literal` for each arm
(SPEC.md l. 90 & l. 883). With `string = atom`, each arm becomes :

```c
if      (method == ATOM_LIT_GET)    return 200;
else if (method == ATOM_LIT_POST)   return 201;
else if (method == ATOM_LIT_DELETE) return 204;
else                                 return 405;
```

— a chain of `u32 ==`, branch-predicted. No lowerer change required.

## Phases

| Phase | Estimate | Output |
|---|---|---|
| 0 — AtomTable runtime + serializer codegen | 3-4 j | atom infra in C, compile-time atom emission, autonomous tests |
| 1 — Flip `vader_string_t = u32` + box shrink | 3-4 j | new type, box 24→16, all 53 `vader_string_t` runtime sites adapted |
| 2 — String ops runtime via atoms | 2-3 j | concat, slice, eq, contains, starts_with, ends_with, split, codepoint_at, byte_len, to_cstr, builder integration |
| 3 — Codegen ajusté | 1-2 j | `==` emitted as `u32 ==` inline, literals as `ATOM_*` macros, snapshot regen |
| 4 — GC scan-based intégré | 2-3 j | mark from shadow stack + struct fields + boxes, parent-chain transitive mark, tombstone sweep, free list |
| 5 — Pré-intern + mesure | 1 j | well-known atom freeze, multi-module aggregation, profile vs baseline |
| **Total** | **12-17 j** | |

### Phase 0 — AtomTable runtime + serializer codegen

Goal : standalone atom table in C + codegen emission of the comptime
blob & table. No `vader_string_t` change yet.

Files :
- `runtime/c/vader_runtime.c` — add `vader_atom_*` section (table,
  intern, slice, init, rebuild_index, profiling hooks). New file
  region, no removals.
- `runtime/c/vader.h` — declare `vader_atom_entry_t`, public
  `vader_atom_*` API.
- `src/c_emit/emit.ts` — collect comptime atoms during emit, deduplicate,
  emit `vader_atom_blob[]` + `vader_atom_comptime_table[]` +
  `#define ATOM_*` constants at top of entry module.
- Tests : a `tests/atom/` C harness driving intern/slice/dedupe/GC
  through synthetic scenarios.

Verification :
- C tests green via `runtime/c/test_atom.c`
- `bun run typecheck` and `bun test` unchanged (no language change yet)
- `./build/vader build hello.vader && ./hello` runs identically

### Phase 1 — Flip `vader_string_t = u32` + box shrink

Goal : type identity changes runtime-wide. Boxes shrink.

Files (estimated 30-40 sites in `vader_runtime.c`, ~10 in `vader.h`,
~5 in emit.ts) :
- `vader.h` — `typedef vader_u32_t vader_string_t`. `vader_box_t`
  payload union loses the `vader_string_t s` 16 B leg ; payload
  collapses to 8 B ; struct is 16 B.
- `vader_runtime.c` — remove `vader_string_header_t`, `g_string_head`,
  `g_string_sorted_index`, `vader_string_alloc/free/mark_ptr/
  prepare_marks`, `vader_string_gc_collect` body. Remove
  `string_offsets` from `vader_type_info` scan loop. Adapt every
  `vader_string_t` consumer (concat, eq, contains, split, builder
  append, write_file, to_cstr, box ctors, box payload reads, etc.).
- `src/c_emit/emit.ts` — adapt box layout assumptions, string field
  emit. The `string_offsets[]` table generated per type info is no
  longer needed (atoms are u32 POD, scanner ignores).

Verification :
- All C compiles cleanly (no `vader_string_t.ptr` / `.len` access left)
- Existing snapshot tests pass after regen
- `bun run bench` (mandelbrot + primes) within 10% of baseline

### Phase 2 — String ops runtime via atoms

Replace each `vader_string_*` op implementation against the new model.
Concat / format use `intern_take`. Slice uses `vader_atom_slice` for
share. `eq` is removed (lowerer emits `u32 ==` directly) but kept as
an extern symbol for FFI fallback.

### Phase 3 — Codegen ajusté

The C emitter :
- Emits string literals as `ATOM_LIT_*` macros (resolved by Phase 0
  serializer)
- Emits `==` / `!=` on `string` as `(a == b)` / `(a != b)` directly
  instead of `vader_string_eq(a, b)`
- Emits hash on string as identity (`(u32)a`)

Snapshot regen across `tests/snippets/`.

### Phase 4 — GC scan-based intégré

The major Cheney cycle gains an atom-mark pass after object marking :

1. After all objects are forwarded and the shadow stack is walked,
   collect every reachable `vader_string_t` slot value into a side
   set.
2. For each atom in the set : set MARK bit on entries[a], then walk
   parent chain marking each.
3. Iterate over all non-PERM entries : if !MARK and parent==0,
   free(data) ; clear bucket entry ; push id onto free_list.

GC stress tests (`VADER_GC_STRESS=1`) catch missing marks.

### Phase 5 — Pré-intern + mesure

- Freeze the well-known atom list in `runtime/c/vader_atom_wellknown.h`
  (or as macros).
- Multi-module aggregation : entry module collects atoms from all
  imports.
- Profile : `VADER_GC_PROFILE=1` baseline before/after on
  `vader/cli/main.vader`. Target : peak working-set down ~25 % from
  81 MB.
- Bench : `bun run bench` within ±5 % on string-light, expected
  improvement on string-heavy workloads.

## Decisions frozen (2026-05-25)

| # | Decision | Choice | Rationale |
|---|---|---|---|
| 1 | Byte allocation | slice-share (parent/owner relation) | zero-alloc tokens from source content |
| 2 | GC lifecycle | scan-based via Cheney major | works for long-running programs ; reuses infra |
| 3 | NUL-term | inline `data[len] = 0` | eliminates per-FFI-call dup for owners |
| 4 | Box payload | shrink 24 → 16 | compound gain on every tagged union |
| 5 | Comptime/runtime bridge | serialise arena in binary | stable indices = compile-time `#define ATOM_*` constants |
| 6 | Concurrency | single-thread MVP | lock added at 1.0 if needed |
| 7 | Pre-intern policy | keywords + primitives only | extend later by observation |
| 8 | Initial table capacity | 2 × comptime count | absorb first runtime interns without grow |
| 9 | Builder API | builder owns bytes, intern_take at finish | intermediates never pollute table |
| 10 | Slice → external buffer | not allowed | every slice atom has an atom parent ; SourceFile content is itself an atom |
| 11 | Atom len max | 2^32 - 1 bytes | runtime trap on overflow |

## Verification per phase (common)

- `bun run typecheck` green (TS bootstrap compiler)
- `bun test` green (all snapshot + parity + LSP suites)
- `tests/atom/*.c` standalone harness green (Phase 0+)
- `VADER_GC_STRESS=1 ./build/vader build vader/cli/main.vader && ./build/vader-self <demo>` runs (Phase 4+)
- `VADER_GC_PROFILE=1 ./build/vader dump --stage=typed-ast vader/cli/main.vader` shows expected drop (Phase 5)
- `bun run bench` (mandelbrot + primes) within 10% of baseline ; Phase 5 expects net positive on identifier-heavy workloads

## Risks

1. **Slice-share + GC trace incomplete** — missing the parent mark when
   a child slice is reachable produces a silent use-after-free.
   Mitigation : invariant audit after the mark phase, ASAN-enabled
   debug build, GC stress tests covering deeply-nested slice chains.
2. **Tombstone accumulation** — `entries[]` grows long-term even though
   bytes are reclaimed. Acceptable for compiler-class programs.
   For server-class workloads, compaction would require rewriting
   every `u32` in the heap — explicitly out of scope. Monitor via
   `VADER_ATOM_PROFILE` in Phase 5.
3. **Multi-module index conflicts** — if two modules independently
   serialise atom tables, indices clash. Mitigation : only the entry
   module emits the blob ; other modules reference via header. Lint
   in Phase 0.
4. **Comptime index instability across builds** — `#define ATOM_X N`
   only works if `N` is reproducible. Mitigation : deterministic sort
   (module path + source-appearance order) ; CI snapshot of the
   comptime table.
5. **Box shrink 24 → 16 cascade** — ~30 runtime sites assume 24-byte
   boxes (packed[16], array bumpers, FFI marshalling). Each must be
   audited. Mitigation : audit list compiled before Phase 1 ; ASAN
   build during migration.
6. **Hot path indirection** — `entries[a].data` is a memory hop per
   byte-level op. Bench in Phase 5 must show carrier-compaction gain
   > indirection cost. Worst case : revisit by caching `data` in a
   shadow array indexed by atom (still 1 hop, same cache line).

## Issues encountered

### Phase 1 (2026-05-25)

- **`vader_string_hash` distribution.** First pass returned the atom id
  directly as the u64 hash — atoms are monotonically assigned, so the
  resulting hash clusters in the low bits and `MutableMap` iteration
  order changes vs the legacy FNV1a-on-bytes implementation. Snapshot
  test `json_basics` failed with reordered object keys. Restored
  FNV1a-64 over the atom's data bytes (1 atom-table lookup + the
  standard loop). The atom id alone makes for a fine *equality* hash
  but a poor *bucket-distribution* hash. Vader port note : keep the
  byte-level FNV1a — it matches the VM-side hash, so `MutableMap` is
  bucket-stable across runtimes.

- **Box payload upper bytes.** `vader_box_string(tag, v)` used to
  write 16 B (the legacy `{ptr,len}`) into `payload.s`. With atoms
  it writes only 4 B at offset 0. `vader_box_eq`'s 8-byte
  `payload.obj` compare would then read 4 bytes of atom + 4 bytes of
  whatever was in the union before. Fix : zero `payload.obj = NULL`
  before writing `payload.s`. The lower 4 bytes get the atom id,
  upper 4 stay zero, and equality works correctly.

- **Builder buffer ownership.** Legacy builder used
  `vader_string_alloc` for its buf (tracked by the string sweep).
  Post-flip, plain malloc + `vader_atom_intern_take` at finish lets
  the table either adopt the buffer (miss) or free it (hit) — no
  separate tracking needed.

### Phase 4 (2026-05-25)

- **atexit LIFO ordering.** `vader_atom_init_with_comptime` initially
  registered `atexit(vader_atom_profile_dump)`. The emitted `main`
  then registered `atexit(vader_atom_shutdown)`. atexit runs LIFO →
  shutdown ran first, then profile-dump on a zeroed table (count=0).
  Fix : drop the atexit hook ; call `vader_atom_profile_dump` inline
  at the top of `vader_atom_shutdown` when the env flag is set.

- **GC-stress baseline failures.** Under `VADER_GC_STRESS=1` the two
  snippet tests `iter_zip_chain` and `json_basics` fail (output
  reshuffling indicating lost heap-object state). The failures
  predate Phase 4 — they surface after Phase 1's removal of the
  conservative string-buffer scan and are NOT caused by the atom
  GC. Investigation deferred to a separate change.

## Baselines (2026-05-25)

`VADER_ATOM_PROFILE=1 tests/snippets/json_basics/native` :
```
[atom-profile] count=124 capacity=256 bucket_load=12.01% owner_bytes=503 free_count=0
```
124 distinct atoms after running a JSON-heavy stdlib test ; 503 bytes
total in owner buffers ; bucket load well below the 0.75 grow
threshold. Slice atoms (zero-byte owners) are not visible in the
bytes total — they share parent buffers.
