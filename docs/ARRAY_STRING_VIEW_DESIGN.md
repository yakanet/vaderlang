# A7 — Unified `T[]` / `string` with CoW Views

Status: design frozen — implementation in progress.

## Goal

Make `arr[r]` and `string[r]` zero-copy by default, without introducing a
second user-facing type (no `Slice[T]`, no `StringView`). The runtime
representation supports both *owning* and *view* states transparently ;
mutations on a view trigger Copy-on-Write detachment so users never see
aliasing surprises.

## Decisions (frozen)

| Question | Choice | Rationale |
|----------|--------|-----------|
| User-facing type for slice result | `T[]` (no `Slice[T]`) | Single type, no migration, no API to learn |
| `string[r]` indexing unit | **Codepoint** | "Codepoint-first" intent ; impossible to produce malformed UTF-8 by slicing |
| `string[i]` single index | **Codepoint** | Same logic ; returns `char` at codepoint index `i` |
| `string.slice()` (public method) | **Removed** | `s[r]` covers the codepoint case ; byte-level via `s.bytes()[r]` |
| `string.bytes()` return type | `u8[]` (view on UTF-8 buffer) | Was an iterator, becomes a CoW array view ; iterable + indexable |
| Lifetime tracking | GC anchor via shared backing buf | Simple ; GC scan already follows `buf` pointer |
| Mutation on a view | **Copy-on-Write (transparent)** | No aliasing footguns ; cost paid on first write only |
| `Clone` on a view | Same as on owning (returns owning `T[]`) | Clone trait stays canonical (Self → Self) ; CoW makes "view" invisible |
| Codepoint indexing perf | **O(n) walk** at MVP | Cursor cache optional follow-up if profiling shows it's hot |
| Array `arr[i] = v` aliasing | **Switch to CoW immediately** | Fail-fast ; aliasing bugs are silent and hard to find |
| Migration breaking? | **Yes — call sites in stdlib + self-host audited** | One-time pain ; rest of the language stays consistent |

## Audit — current state

### Arrays (T[])

Already mostly there :

- `runtime/c/vader.h:243-252` — `vader_array_t = { header, length, capacity, offset, buf }`. The `offset` field is exactly what a view needs.
- `runtime/c/vader_runtime.c:1213` — `vader_array_slice(a, lo, hi)` returns a fresh `vader_array_t` whose `buf` is shared with `a` and `offset = a.offset + lo`. **Zero-copy already**.
- `runtime/c/vader_runtime.c:1255` — `vader_array_push` detects a view (`offset != 0 || offset+length < buf->length`) and detaches into a fresh buf. **CoW on grow already**.
- `src/typecheck/passes/expr.ts:374-386` — `arr[r]` where `r : Range[<int>]` typechecks to `target` (= `T[]`). No `Slice` type involved.
- Bytecode op `array.slice` exists ; midir `ArraySlice` instr exists ; VM TS handler exists ; C-emit handler exists.

The only **gap** for arrays :

- `vader_array_set` (runtime/c/vader_runtime.c:1199) does NOT detach on a view. A write through a view mutates the parent's backing buffer — **Go-style aliasing**, not CoW. This is the only place where the current behavior diverges from the "no surprises" model.

### Strings

Already zero-copy by construction :

- `runtime/c/vader.h:70-73` — `vader_string_t = { ptr, len }`. Fat pointer ; no `offset` needed because `ptr` itself can point anywhere into a shared buffer.
- `runtime/c/vader_runtime.c:1312` — `vader_string_slice(s, start, end)` returns `(s.ptr + start, end - start)`. **Byte-range, zero-copy**.
- `stdlib/std/string/string.vader:32` — `slice(s, start, end) -> string` documented as byte-indexed.
- `stdlib/std/core/core.vader:463` — `@intrinsic string implements Index(usize, char)` — `s[i]` returns the char at BYTE offset `i`.

**Gaps for strings** :

- `string[r]` (range index) isn't wired today. `s[i]` returns a char ; there's no `Range[usize]` index variant.
- The current `s[i]` semantics is byte-indexed ; we want codepoint-indexed.
- The current `s.slice()` is byte-indexed ; we delete it. `s.bytes()` returns an iterator today ; we change it to return `u8[]` (a CoW view on the UTF-8 buffer).
- Migration scope: `grep -rn "\.slice(" stdlib vader` → ~131 sites ; `grep -rn "\.byte_at" stdlib vader` → ~158 sites (already byte-intent, no change).

## Target semantics

### Arrays

```vader
arr := [1, 2, 3, 4, 5]   // owning
v   := arr[1..<4]        // view : (buf shared, offset=1, len=3, cap=3) — [2,3,4]

println(v[1])            // → 3 — reads parent's buf[2], zero copy
v[1] = 99                // CoW : v detaches, allocates fresh buf [2,3,4], writes 99
                         //   → v is now (buf fresh, offset=0, len=3, cap=3) — [2,99,4]
                         //   arr remains [1,2,3,4,5] — write didn't propagate
println(arr[2])          // → 3 — parent unchanged
```

Push :

```vader
v.push(0)                // CoW on grow (already implemented)
                         // v's buf is fresh ; len=4, cap=6 ; [2,99,4,0]
```

Clone :

```vader
copy := arr[1..<4].clone()   // fresh owning T[] — [2,3,4]
                              // (clone always materializes ; same Clone trait as today)
```

### Strings — codepoint slicing

```vader
s   := "héllo"           // (5 codepoints, 6 UTF-8 bytes)
sub := s[0..<2]          // codepoint-range → byte boundaries [0..3) → "hé"
println(sub)             // → "hé"
println(sub.byte_len())  // → 3 (the é is 2 bytes)
println(sub.len())       // → 2 (codepoints — see Phase 4 below)
```

### Strings — single codepoint indexing

```vader
c :: s[1]                // codepoint at codepoint-index 1 → 'é'
                         // (was : byte offset 1 → mid-é, returns U+FFFD)
```

### Strings — byte access via `s.bytes()`

```vader
b :: s.bytes()           // u8[] view on the UTF-8 buffer (zero copy)
println(b[0])            // → 0x68 ('h')
println(b[1])            // → 0xC3 (first byte of é)
println(b.len())         // → 6 (byte count)

// Mutation triggers CoW :
b[0] = 0x48              // 'H' ; detaches into a fresh buffer, s remains "héllo"
```

This makes `s.bytes()` substitute for the missing `s.byte_slice(b1, b2)` :
```vader
old: s.slice(b1, b2)       // was : returned string from byte range
new: s.bytes()[b1..<b2]    // returns u8[] (view) — convert to string if needed
```

## Implementation phases

### Phase 1 — Arrays: enforce CoW on `array.set` (1-2 h)

Mutate `vader_array_set` (and the C-emit path for `array.set`) to
detect a view and detach before writing :

```c
void vader_array_set(vader_array_t* a, size_t i, vader_box_t v) {
    a = vader_array_resolve(a);
    // ...existing forward-resolve...
    if (VADER_UNLIKELY(i >= a->length)) vader_trap("array index out of bounds");
    if (vader_array_is_view(a)) {
        vader_array_detach(a);   // alloc fresh buf, copy, clear offset
    }
    vader_array_store_slot(a->buf, a->offset + i, v);
    // ...write barrier...
}

static inline bool vader_array_is_view(const vader_array_t* a) {
    return a->offset != 0 || a->offset + a->length < a->buf->length;
}
```

`vader_array_detach` factors the existing push-detach path so both push
and set share the logic.

Mirror in the TS VM (`src/vm/exec.ts` array.set handler) and the Vader
VM (`vader/vm/exec.vader`). Both today mutate the underlying buffer
directly — they need the same detach check.

**Risk** : performance regression on `arr[i] = v` against an owning
array if the is-view check is mispredicted. Branch is fully predictable
in practice (each call site is consistently owning OR view).

**Test** : `tests/snippets/array_view_cow_isolation/` — `arr[r][i] = v`
should NOT mutate `arr`.

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

Out-of-bounds : if `cp_lo > codepoint_count(s)`, clamp ; same for
`cp_hi`. Mid-buffer codepoint scan is O(n).

### Phase 3 — Strings: `s[i]` codepoint shift (1 h)

Change the `string implements Index(usize, char)` intrinsic so `s[i]`
interprets `i` as a codepoint index :

```c
vader_char_t vader_string_codepoint_at(vader_string_t s, size_t cp_index) {
    size_t byte_off = utf8_byte_offset_for_codepoint(s, cp_index);
    if (byte_off >= s.len) vader_trap("string codepoint index out of bounds");
    return utf8_decode_one(s.ptr + byte_off);
}
```

Existing `byte_at(i: usize) -> u8` stays unchanged and serves the
byte-offset use case.

### Phase 4 — Stdlib: `bytes()` returns `u8[]`, drop `slice()` (1-2 h)

In `stdlib/std/string/string.vader` :

- Remove `export slice :: fn(s: string, start: usize, end: usize) -> string`.
- Change `export bytes :: fn(s: string) -> StringBytes` to return `u8[]` (a CoW view on the UTF-8 buffer).
- Delete the `StringBytes` iterator struct (the `u8[]` array already implements `Iterator(u8)` via `T[] implements Into(Iterator(T))`).
- Add `export len :: fn(s: string) -> usize` that returns the codepoint count (walks UTF-8 ; O(n)).

`StringChars` (codepoint iterator) stays — useful for explicit codepoint
walks without materializing all positions.

### Phase 5 — Migration audit (3-5 h)

Sites to flip :

- **131 `.slice()` callers** — each one needs either :
  - `s[lo..<hi]` if intent is codepoint
  - `s.bytes()[lo..<hi]` if intent is byte (returns u8[], not string)
  - If the caller needs a `string` from byte range, route through `s.bytes()[lo..<hi]` then a fresh string construction (TBD — see Open question 3 below).

- **Audit `s[i]` byte-intent sites** — the `s[i]` semantic shift to codepoint is silent (signature unchanged). Manual review of the self-host lexer (`vader/lexer/lexer.vader`), parser, and any code that does byte-level walks. Recommended pattern : if the intent is byte, refactor to `s.bytes()[i]` ; if the intent is codepoint, leave as-is.

- Existing `s.byte_at(i)` (158 sites) is already byte-intent ; no change.

The test suite is the canonical safety net : every snippet that exercised `s.slice()` or `s[i]` byte-intent will fail until migrated.

### Phase 6 — Self-host port (Vader VM) (1-2 h)

Mirror Phase 1 + 2 + 3 in `vader/vm/exec.vader` :

- `array.set` op handler : detach-on-view (port of vader_array_set).
- New `string.slice_codepoints` op handler.
- `s[i]` codepoint semantic shift in the host `string_index` intrinsic.

Plus parser changes for the new bytecode op (vader/vm/parser.vader).

### Phase 7 — Tests (2-3 h)

- `tests/snippets/array_view_cow_isolation/` : `arr[r][i] = v` doesn't mutate parent.
- `tests/snippets/string_codepoint_slice/` : `"héllo"[0..<2]` → `"hé"`.
- `tests/snippets/string_codepoint_index/` : `"héllo"[1]` → `'é'`.
- `tests/snippets/string_bytes_view/` : `s.bytes()[i]` zero-copy reads ; CoW on write.
- `tests/snippets/array_view_iteration_zero_copy/` : verify no extra alloc on `for x in arr[r] { ... }` via the gc bytes-allocated probe.

### Phase 8 — SPEC.md sync (30 min)

Update §4 (type system) — clarify that `T[]` has internal owning / view
states with CoW. Update §9 (strings) — `string[r]` and `s[i]` are
codepoint-indexed ; `s.bytes()` returns `u8[]` view ; `s.slice()` is
gone.

## Effort estimate

| Phase | Effort |
|-------|--------|
| 1. Arrays CoW on set | 1-2 h |
| 2. Strings codepoint slice op + lower + emit | 3-4 h |
| 3. `s[i]` codepoint shift | 1 h |
| 4. Stdlib (`bytes()` returns u8[], drop `slice()`, add `len()`) | 1-2 h |
| 5. Migration (131 `.slice()` sites + `s[i]` audit) | 3-5 h |
| 6. Vader self-host port | 1-2 h |
| 7. Tests | 2-3 h |
| 8. SPEC sync | 30 min |
| **Total** | **12-18 h** |

## Commit-by-commit plan

To keep each commit a green checkpoint :

1. **C1 — Arrays CoW on set** (Phase 1). VM TS + C-emit. Test :
   `array_view_cow_isolation`.
2. **C2 — Vader VM array.set CoW** (Phase 6 partial). Self-host green.
3. **C3 — string[r] codepoint slice** (Phase 2). New bytecode op +
   runtime helper + lower + VM + C-emit. Test : `string_codepoint_slice`.
4. **C4 — s[i] codepoint shift + bytes()→u8[] + delete slice()**
   (Phase 3 + 4). All three together because they're entangled : a
   single migration round handles them. Stdlib + self-host audit done
   here. Test : `string_codepoint_index`, `string_bytes_view`.
5. **C5 — Vader VM port + tests + SPEC** (Phase 6 finish + 7 + 8).

If a commit can't be made green in one session, fold its scope down
(e.g. C4 can split per migration sub-target : stdlib first, vader/ next).

## Open questions

1. **Converting `s.bytes()[lo..<hi]` back to `string`**: when an existing call site had `s.slice(b1, b2) -> string` byte-intent, the natural replacement is `s.bytes()[b1..<b2]` → `u8[]`. Some callers will want to feed this back as a `string`. Options :
   - `string::from_bytes(bytes: u8[]) -> string!` (returns `string | Error`, validates UTF-8)
   - Direct intrinsic `string(bytes)` via existing `Into` coerce mechanism
   - Refactor every such site to a codepoint-equivalent

   Recommendation : MVP avoids this need by ensuring every byte-intent
   slice has a codepoint equivalent in the self-host. If a site genuinely needs `u8[]` → `string`, ship `string::from_bytes` in a follow-up.

2. **Mutation through `s.bytes()`**: CoW transparency means `s.bytes()[i] = v` detaches the u8[] view but doesn't mutate the string. The user might expect either : (a) error (strings are immutable), or (b) silent CoW (my current choice). Going with (b) — consistent with the array CoW model.

3. **Performance of codepoint walk**: `s[100]` walks 100 codepoints worth
   of UTF-8 bytes. For most uses fine ; a cursor cache or pre-computed
   offset table is a follow-up if profiling shows it's hot. The
   self-host lexer doesn't do random codepoint access (it's a streaming
   walk via `chars()` / `bytes()`), so probably no impact.

4. **Range type for `s[r]` / `arr[r]`** : both `Range[usize]` and
   `Range[i32]` ? Today `string implements Index(usize, char)` uses
   `usize`. Stick with `Range[usize]` for indices. Free-int literals
   default to `usize` in this context via the existing context-typing
   mechanism.

## Out of scope

- Borrow checker / static lifetime tracking — GC anchor is sufficient.
- Mutable string views — strings stay immutable.
- Mutable explicit `MutableSlice[T]` type — not needed with CoW transparent.
- Optimized cursor cache for repeated codepoint access — follow-up.
- WASM target adjustments — `usize` width question independent of A7.
