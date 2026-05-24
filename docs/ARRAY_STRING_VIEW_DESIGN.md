# A7 — Unified `T[]` / `string` with view aliasing + codepoint string slicing

Status: design frozen — Phase 1 (array view aliasing) landed.

## Goal

Make `arr[r]` and `string[r]` zero-copy by default, without introducing
a second user-facing type (no `Slice[T]`, no `StringView`). The runtime
representation supports both *owning* and *view* states ; views share
the backing buffer with their parent. Writes through a view alias the
parent (Go-style) ; `push` detaches into a fresh buffer to avoid
clobbering tail slots aliased by sibling views.

## Decisions (frozen)

| Question | Choice | Rationale |
|----------|--------|-----------|
| User-facing type for slice result | `T[]` (no `Slice[T]`) | Single type, no migration, no API to learn |
| `string[r]` indexing unit | **Codepoint** | "Codepoint-first" intent ; impossible to produce malformed UTF-8 |
| `string[i]` single index | **Codepoint** | Same logic ; returns `char` at codepoint index `i` |
| `string.slice()` (public method) | **Removed** | `s[r]` covers the codepoint case ; byte-level via `s.bytes()[r]` |
| `string.bytes()` return type | `u8[]` (view on UTF-8 buffer) | Was an iterator, becomes a view ; iterable + indexable |
| Lifetime tracking | GC anchor via shared backing buf | Simple ; GC scan already follows `buf` pointer |
| **Mutation on a view** | **Go-style aliasing** | `arr[r][i] = v` writes through to the parent. Predictable perf, no hidden allocs. User opts out by copying explicitly. |
| `push` on a view | **Always detaches** (CoW for grow) | Prevents silent clobbering of tail slots held by sibling views — that's the Go-`append` footgun we explicitly avoid. |
| Codepoint indexing perf | **O(n) walk** at MVP | Cursor cache optional follow-up if profiling shows it's hot |
| Migration breaking? | **Yes — stdlib + self-host audited** | Site count ~131 ; one-time pain, language stays consistent |

## Comparison : aliasing vs CoW (rejected alternative)

The other candidate model was *Copy-on-Write transparent* (every mutation
on a view detaches before writing). It was rejected because :

1. **Hidden alloc** on the first write to any view ; surprising perf.
2. **`arr[r][i] = v` doing nothing visible to `arr`** is itself a
   surprise — users coming from Go / C / Python lists expect either an
   alias or a compile error, not a silent silent-no-op.
3. The view representation already requires the offset/length plumbing
   ; CoW adds a detach hot path on top.

Go-style aliasing is the dominant memory model for slice-like types
(Go, Rust mut-borrowed slices, C array+length). It's an explicit
trade-off : **performance + predictability over safety**. Users disown
the aliasing by allocating a fresh array (today via `arr.push` on a
view, which detaches ; once `T[] implements Clone` lands,
`arr[r].clone()` will be the canonical form).

## Audit — current state (pre-A7)

### Arrays (T[])

Already mostly there :

- `runtime/c/vader.h:243-252` — `vader_array_t = { header, length, capacity, offset, buf }`. The `offset` field is exactly what a view needs.
- `runtime/c/vader_runtime.c:1213` — `vader_array_slice(a, lo, hi)` returns a fresh `vader_array_t` whose `buf` is shared with `a` and `offset = a.offset + lo`. **Zero-copy already**.
- `runtime/c/vader_runtime.c:1255` — `vader_array_push` detects a view (`offset != 0 || offset+length < buf->length`) and detaches into a fresh buf. **Detach-on-grow already**.
- `runtime/c/vader_runtime.c:1199` — `vader_array_set` writes through `a->buf` directly with the offset — **Go-style aliasing, already in place**. (My initial Phase 1 added CoW-on-set and the user reverted it.)
- `src/typecheck/passes/expr.ts:374-386` — `arr[r]` where `r : Range[<int>]` typechecks to `target` (= `T[]`). No `Slice` type involved.
- Bytecode op `array.slice` exists ; midir `ArraySlice` instr exists ; VM TS handler existed (but copied) ; C-emit handler exists.

Gap (closed by A7 P1) :
- VM TS and Vader VM both **copied** on `array.slice` ; with Go-style aliasing they must share the backing buffer instead. Phase 1 refactors both VMs : `ArrayValue` / `ArrayVal` gains `offset` + `length` ; `array.slice` shares `elements` and adjusts bounds ; `array.set` writes through ; `array.push` detaches on view.

### Strings

Already zero-copy by construction :

- `runtime/c/vader.h:70-73` — `vader_string_t = { ptr, len }`. Fat pointer ; no `offset` needed because `ptr` itself can point anywhere into a shared buffer.
- `runtime/c/vader_runtime.c:1312` — `vader_string_slice(s, start, end)` returns `(s.ptr + start, end - start)`. **Byte-range, zero-copy**.
- `stdlib/std/string/string.vader:32` — `slice(s, start, end) -> string` documented as byte-indexed.
- `stdlib/std/core/core.vader:463` — `@intrinsic string implements Index(usize, char)` — `s[i]` returns the char at BYTE offset `i`.

**Gaps for strings** :

- `string[r]` (range index) isn't wired today.
- `s[i]` semantics is byte-indexed ; we want codepoint-indexed.
- `s.slice()` is byte-indexed ; we delete it. `s.bytes()` returns an iterator today ; we change it to return `u8[]` view.
- Migration scope: `grep -rn "\.slice(" stdlib vader` → ~131 sites ; `grep -rn "\.byte_at" stdlib vader` → ~158 sites (already byte-intent, no change).

## Target semantics

### Arrays

```vader
arr := [1, 2, 3, 4, 5]   // owning ; (elements=arr_buf, offset=0, length=5)
v   := arr[1..<4]        // view ; (elements=arr_buf, offset=1, length=3) — [2,3,4]

println(v[1])            // → 3 — reads parent's buf[2], zero copy
v[1] = 99                // ALIASES ! Writes parent.buf[2] = 99
                         //   arr is now [1,2,99,4,5]
                         //   v is still (parent buf, offset=1, length=3)
println(arr[2])          // → 99 — visible aliasing
```

Push :

```vader
v.push(0)                // detach : v allocates a fresh elements buffer
                         // copying [2,99,4] into it, then pushes 0
                         //   → v = (fresh_buf, offset=0, length=4) = [2,99,4,0]
                         //   arr unchanged at [1,2,99,4,5]
```

Clone (once `T[] implements Clone` is wired) :

```vader
copy := arr[1..<4].clone()   // fresh owning T[] — [2,99,4]
                              // explicit way to disown the aliasing
```

Today, before Clone-on-T[] lands, the same effect is achievable via
`push` (which detaches) but it's a coincidence rather than an idiom.

### Strings — codepoint slicing (Phase 2)

```vader
s   := "héllo"           // (5 codepoints, 6 UTF-8 bytes)
sub := s[0..<2]          // codepoint-range → byte boundaries [0..3) → "hé"
println(sub)             // → "hé"
println(sub.byte_len())  // → 3 (the é is 2 bytes)
println(sub.len())       // → 2 (codepoints — Phase 4 adds `len()`)
```

### Strings — single codepoint indexing (Phase 3)

```vader
c :: s[1]                // codepoint at codepoint-index 1 → 'é'
                         // (was : byte offset 1 → mid-é, returns U+FFFD)
```

### Strings — byte access via `s.bytes()` (Phase 4)

```vader
b :: s.bytes()           // u8[] view on the UTF-8 buffer (zero copy)
println(b[0])            // → 0x68 ('h')
println(b[1])            // → 0xC3 (first byte of é)
println(b.len())         // → 6 (byte count)

// Writes through `b` alias the underlying buffer of `s`, but `s` is
// immutable user-side : mutating `b` is undefined for the user's view
// of `s`. Phase 4 may choose to either (a) forbid mutating u8 views
// derived from strings at compile time, or (b) defer detachment via
// push as the only legal mutation. TBD.
```

This makes `s.bytes()` substitute for the removed `s.byte_slice(b1, b2)` :
```vader
old: s.slice(b1, b2)       // was : returned string from byte range
new: s.bytes()[b1..<b2]    // returns u8[] (view) — convert to string if needed
```

## Implementation phases

### Phase 1 — Array view aliasing (LANDED, ~2h)

- `vader_array_set` left as Go-style aliasing (reverted my initial CoW
  attempt) — the C runtime was already correct.
- TS VM `ArrayValue` gains `{ elements, offset, length }`. All ops
  (`get`/`set`/`len`/`push`/`slice`/`data.const`/argv) updated.
- Vader VM `ArrayVal` same refactor in `vader/vm/op.vader` +
  `vader/vm/exec.vader`. Host iteration sites updated for
  offset/length-bounded walks.
- Snippet `tests/snippets/array_view_aliasing/` validates the
  aliasing-on-set + detach-on-push contract on all three targets.

### Phase 2 — Strings: `string[r]` codepoint slice (3-4 h)

Typecheck : extend `src/typecheck/passes/expr.ts:374-386` (the array
slice branch) with a parallel `target.kind === "Primitive" && target.name === "string"` arm that accepts `Range[<int>]` and returns `string`.

Lower : `string[r]` lowers to a new `LoweredStringSlice` node carrying
`(target, lo, hi)`.

Bytecode op : `string.slice_codepoints` (operand: 0 ; consumes string +
2 usize from stack, pushes the resulting string).

Runtime impl :

```c
vader_string_t vader_string_slice_codepoints(vader_string_t s, size_t cp_lo, size_t cp_hi) {
    size_t byte_lo = utf8_byte_offset_for_codepoint(s, cp_lo);
    size_t byte_hi = utf8_byte_offset_for_codepoint(s, cp_hi);
    return vader_string_new(s.ptr + byte_lo, byte_hi - byte_lo);
}
```

(Already landed in `runtime/c/vader_runtime.c::vader_string_slice_codepoints`
alongside Phase 1 ; the bytecode plumbing and lower path are what
remain.)

Out-of-bounds : if `cp_lo > codepoint_count(s)`, clamp ; same for
`cp_hi`. Mid-buffer codepoint scan is O(n).

### Phase 3 — Strings: `s[i]` codepoint shift (LANDED, ~1 h)

`string implements Index(usize, char)` flipped so `s[i]` interprets `i`
as a codepoint index :

```c
vader_char_t vader_string_codepoint_at(vader_string_t s, size_t cp_index) {
    size_t byte_off = utf8_byte_offset_for_codepoint(s, cp_index);
    if (byte_off >= s.len) vader_trap("string codepoint index out of bounds");
    return vader_string_char_at(s, byte_off);
}
```

Host dispatch swap landed in :
- C emit : `src/c_emit/emit.ts` (`std_core$string$Index$at -> vader_string_codepoint_at`)
- TS VM bridge : `src/vm/host.ts` (`for...of` codepoint walk)
- Vader VM host : `vader/vm/host.vader` (UTF-8 walk via `decode_codepoint`)

For byte-cursor sites, the new export `byte_decode_at(s, i) -> char`
decodes the UTF-8 codepoint at byte offset `i` (declared `@intrinsic` in
`stdlib/std/string/string.vader`, backed by `vader_string_char_at`).
Existing `byte_at(i: usize) -> u8` stays unchanged.

### Phase 4 — Stdlib renames + `bytes()` returns `u8[]` (LANDED, ~3 h)

Implemented as three sub-phases (P4a, P4b, P4c) :

- **P4a** — Rename `slice` → `byte_slice` (109 callers). Naming
  consistency with the `byte_at` / `byte_decode_at` family ; semantics
  unchanged (byte-indexed substring). Callers wanting codepoint
  slicing already moved to `s[r]` in P2.
- **P4b** — Rename `count_chars` → `len`. Aligns the codepoint count
  with `arr.len()`. UFCS overload with `std/collections::len` is
  disjoint (receiver types `string` vs `MutableMap` / `MutableSet`).
- **P4c** — `bytes() -> u8[]`. Returns a fresh `u8[]` copy of the
  UTF-8 bytes (O(n) copy, no aliasing). `StringBytes` struct + its
  `Iterator(u8)` impl deleted ; iteration goes through the array's
  built-in iterator. A zero-copy view sharing the string's buffer is
  a planned optimisation — out of scope for this phase.

`StringChars` (codepoint iterator) stays — useful for explicit
codepoint walks without materialising all positions.

### Phase 5 — Migration audit (LANDED, ~3 h — `s[i]` byte-intent portion)

`s[i]` byte-intent audit complete (14 sites + 2 missed-then-found in
review) — all flipped to `s.byte_decode_at(i)` where the cursor is a
byte offset and the value is needed as `char`, or to `s.byte_at(i)`
where the comparison is against a raw byte (lexer BOM check, JSON
ASCII keyword match) :

- `stdlib/std/string/string.vader` — `StringChars.next`, `decode_codepoint`
- `stdlib/std/json/json.vader` — `peek_byte`, `match_keyword`, hex escape
- `vader/lexer/lexer.vader` — `peek`, `peek_at`, unicode escape decoder, BOM check
- `vader/lsp/transport.vader` — `trim_ascii`
- `vader/lsp/semantic_tokens.vader` — `scan_ident_end`, `collect_doc_line_tokens`, `@param` skip loop

`.slice()` callers (131 sites) and `s.bytes()` semantics remain Phase 4.

The test suite was the canonical safety net : every snippet that exercised `s[i]` byte-intent failed loudly until migrated, then the bytecode snapshots reflected the new dispatch.

### Phase 6 — Self-host port (Vader VM) (LANDED, ~1 h)

New `StringSliceCodepoints` op variant in `vader/vm/op.vader`, with
handler in `vader/vm/exec.vader` that walks UTF-8 to find the byte
offsets for the codepoint indices and clamps out-of-bounds ranges
(matching the TS VM contract). Text-IR encode/decode plumbed through
`vader/bytecode/text.vader`, `vader/bytecode/dump.vader`, and
`vader/vm/parser.vader`. The `s[i]` codepoint semantic shift for
`std_core$string$Index$at` was already covered in Phase 3
(`vader/vm/host.vader`).

`string_codepoint_slice` removed from
`tests/vader_vm.test.ts::KNOWN_DIVERGENT` ; vader-vm parity passes.

### Phase 7 — Tests (LANDED)

- ✅ `tests/snippets/array_view_aliasing/` — Phase 1.
- ✅ `tests/snippets/string_codepoint_slice/` — `"héllo"[0..<2]` → `"hé"` ; clamping, ASCII parity, empty-range cases. Active under both TS VM and Vader VM (Phase 6).
- ✅ `tests/snippets/std_string/` covers the codepoint `s[i]` form post-P3 (`"你好嗎？"[0]` → `你`).
- ✅ `tests/snippets/string_bytes/` — exercises `for b in s.bytes()` iteration plus the new `u8[]` surface (`.len()`, random `bs[i]` indexing) introduced by P4c.
- ✅ `tests/snippets/string_codepoints/` — exercises `len()` (renamed from `count_chars` in P4b).

### Phase 8 — SPEC.md sync (LANDED across P3/P4/P5)

§4 (type system) and §11 (stdlib listing) updated incrementally with
each phase :
- P3 — `s[i]` codepoint-indexed (§4 Strings, §11).
- P4a — `slice` → `byte_slice` (§4, §11).
- P4b — `count_chars` → `len` (§4, §11).
- P4c — `bytes()` returns `u8[]` ; `StringBytes` type removed (§4, §11).
- P5 — `byte_decode_at` documented alongside `byte_at` (§11).

The array view aliasing model (§4 Arrays) was already in place ;
no extra prose needed.

## Effort estimate

| Phase | Status | Effort |
|-------|--------|--------|
| 1. Array view aliasing | ✅ done | 2 h |
| 2. Strings codepoint slice op + lower + emit | ✅ done | 3 h |
| 3. `s[i]` codepoint shift | ✅ done | 1 h |
| 4. Stdlib renames + `bytes()` → u8[] (P4a/P4b/P4c) | ✅ done | 3 h |
| 5. Migration (`s[i]` byte-intent audit) | ✅ done | 3 h |
| 6. Vader self-host VM port | ✅ done | 1 h |
| 7. Tests | ✅ done | 2 h |
| 8. SPEC sync | ✅ done | 30 min |
| **Status** | | **complete** |

## Open questions

1. **Converting `s.bytes()[lo..<hi]` back to `string`**: when an existing call site had `s.slice(b1, b2) -> string` byte-intent, the natural replacement is `s.bytes()[b1..<b2]` → `u8[]`. Some callers will want to feed this back as a `string`. Options :
   - `string::from_bytes(bytes: u8[]) -> string!` (returns `string | Error`, validates UTF-8)
   - Direct intrinsic `string(bytes)` via existing `Into` coerce mechanism
   - Refactor every such site to a codepoint-equivalent

   Recommendation : MVP avoids this need by ensuring every byte-intent
   slice has a codepoint equivalent in the self-host. If a site genuinely needs `u8[]` → `string`, ship `string::from_bytes` in a follow-up.

2. **Mutation through `s.bytes()`**: Phase 4 question. If writes through the view alias the underlying string buffer, strings stop being immutable user-side — surprising. Options : (a) compile-time error on `u8[]` writes when the array came from `s.bytes()`, (b) push always detaches (consistent with view semantics elsewhere), (c) document the aliasing and let users discover it. Default plan : (b) consistent with array push detach.

3. **Performance of codepoint walk**: `s[100]` walks 100 codepoints worth
   of UTF-8 bytes. For most uses fine ; a cursor cache or pre-computed
   offset table is a follow-up if profiling shows it's hot.

4. **Range type for `s[r]` / `arr[r]`** : both `Range[usize]` and
   `Range[i32]` ? Today `string implements Index(usize, char)` uses
   `usize`. Stick with `Range[usize]` for indices. Free-int literals
   default to `usize` in this context via the existing context-typing
   mechanism.

5. **`Clone` on `T[]`**: not wired today (only stdlib free fn `iter::clone`).
   Wiring `T[] implements Clone` would make `arr[r].clone()` the
   canonical disown-aliasing idiom — currently users must rely on push
   detach as the side effect. Worth doing alongside Phase 4 stdlib
   cleanup.

## Out of scope

- Borrow checker / static lifetime tracking — GC anchor is sufficient.
- Mutable string views — strings stay immutable user-side.
- Mutable explicit `MutableSlice[T]` type — the unified view model
  covers the same need.
- Optimized cursor cache for repeated codepoint access — follow-up.
- WASM target adjustments — `usize` width question independent of A7.
