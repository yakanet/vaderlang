# Target ABI — minimizing the per-target runtime surface

Vader compiles to several backends — the bytecode VM (`vader/vm/`), the C
emitter (`vader/c_emit/` → `runtime/c/`), and (planned) a WASM target
(§2.5 / §3.10). Today each backend re-implements the runtime: `runtime/c/`
alone exports **~200 `vader_*` symbols**. Every symbol that isn't a true
primitive is a per-target cost — it has to be re-written for the VM, for C, for
WASM, for any future target.

This doc defines the **Target ABI**: the small, irreducible set of primitives
each backend must provide. Everything above the ABI is written **once in
Vader** (stdlib) and compiled to the ABI, so a new target only implements the
primitives.

This is a design note / roadmap — no code is changed by it. Architectural
decisions here are reviewed with the user before implementation
(`.claude/CLAUDE.md` §8).

## Two kinds of "intrinsic"

The stdlib carries **101 `@intrinsic` impl members** (`grep -rn @intrinsic
stdlib/`). They split sharply :

1. **Op-backed intrinsics** — the bulk. Per-width arithmetic / comparison /
   bool / char / conversion / `ref ==` (`std/core/core.vader`, the `Add` /
   `Sub` / `Mul` / `Div` / `Equals` / `Compare` trait impls for `i8..i64`,
   `u8..u64`, `f32`, `f64`, `bool`, `char`). These route to **bytecode opcodes**
   (`I32Add`, `F64Lt`, `StringEq`, …) every backend already executes
   instruction-by-instruction — **no `vader_*` call, no per-target runtime
   code**. They are not the coupling problem ; leave them.
2. **Runtime-backed intrinsics** — route to a `vader_*` host function. This is
   the entire multi-target coupling cost.

Already decoupled, as proof the layered approach works :

- **`std/sort`, `std/utf8` are 100 % Vader** (zero `@intrinsic`) — pure logic
  over the op-backed primitives.
- **Comptime intrinsics** — `@size_of` / `@align_of` / `@type_name` /
  `@type_kind` (`vader/comptime/intrinsic.vader`) fold to constants at compile
  time. No runtime, no per-target burden.

## The Target ABI — irreducible primitives

A backend is complete once it provides these. Group by concern; anchors point
at the current C realization in `runtime/c/vader.h`.

### 1. Execution primitives (the opcode set)
`vader/bytecode/op.vader`. Arithmetic (`I32Add`…`F64Div`), comparison, bool,
char, conversions (`Convert`), refs (`RefEq`, `RefCast`), locals/consts, control
flow (`Block`/`Loop`/`If`/`Branch`/`Return`/`Drop`), and calls (`Call`,
`CallImport`, `FnRef`, `MakeClosure`, `CallIndirect`, `VirtualCall`). Each
backend lowers these directly — irreducible by definition.

### 2. Memory + GC
`vader_gc_alloc(size, type_id)`, `vader_write_barrier`, collect / minor / major,
the shadow-stack frame (`vader_gc_frame_t`), and the per-type GC metadata table
(`vader_type_info_table`). **The GC cannot trace itself in Vader** — it stays
primitive. This is the foundation every higher-level data structure allocates
through.

### 3. Value representation
`vader_box_t` (tagged union) + `vader_box_*` constructors, the nullable-ref
inline opt (`vader_b1_to_box` / `vader_box_to_b1`), and vtable dispatch
(`vader_vtable_t`, `vader_virtual_dispatch`). This is the calling convention /
ABI for values — primitive.

### 4. String interning
`vader_atom_*` (intern, slice, lookup, GC-collect). **Kept primitive on
purpose** : interning is what makes `string ==` an **O(1) atom-id compare**
(`RefEq`), not an O(n) byte compare. It's a value-representation decision, not
incidental coupling. Moving the intern *table* to Vader would regress every
string equality — don't.

### 5. Memory opcodes — `(object, offset)`  ← the pivot (NEW)
There is currently **no generic memory primitive and no pointer opcodes at all**
— `vader/bytecode/op.vader` has no `Load` / `Store` / `Deref` / `Addr` op, the
`rawptr` primitive type is declared but **entirely unused**, and all memory
access goes through the high-level data-structure ops (`Array*`, `Struct*`,
`String*`, `Builder*`). That's not an oversight : the GC is a **generational
Cheney *copying* collector** (`runtime/c/vader.h` — objects relocate and leave a
forward pointer), so a raw pointer into the heap goes stale after the next
cycle. **A moving GC forbids raw in-heap pointers**, which is why none exist.

Consequence for the design : the buffer primitive must be a **GC-managed object**
(a relocatable handle whose ops go through the object header — exactly what
`vader_array_buf_t` already is), **never** raw pointer arithmetic. `rawptr` +
`@extern` (the FFI path — `validate_extern`, T3050 / T3051) stay reserved for
**off-heap** memory only ; a `rawptr` must never point into a GC object.

The fix is **not** raw pointers — it's a small set of **GC-safe memory
opcodes** that address memory as `(GC-object-handle, integer-offset)`, never as
an absolute machine address:

```
obj_alloc  (size, type_id)        -> obj   // GC-allocate (generalizes StructNew / ArrayNew)
load_u8    (obj, off)             -> u8    // raw byte read at a byte offset
store_u8   (obj, off, v: u8)              // raw byte write
load_i32 / load_i64 / load_f64    (obj, off)         // typed reads at a byte offset
store_i32 / store_i64 / store_f64 (obj, off, v)      // typed writes
load_slot  (obj, i)              -> box    // boxed-slot read
store_slot (obj, i, v: box)               // boxed-slot write — fires the write-barrier
mem_copy   (dst, dst_off, src, src_off, n)           // bulk byte copy (obj→obj)
```

**These are GC-safe under the moving Cheney collector.** The base is always a
GC-traced object handle (relocated + rewritten by the collector), the offset is
a plain integer, and the real address is materialized *transiently* inside the
single opcode — never stored in a local across an allocation / safepoint. The
borrowed-view model already relies on exactly this : a slice holds
`(owner_obj, offset, len)`, not a raw pointer (`vader_array_make_borrowed`).
`store_slot` fires the write-barrier ; `obj_alloc` carries the `type_id` so the
GC traces boxed slots and skips primitive ones (the `vader_array_kind_t`
discriminator today).

**The frontend stays pointer-free** (your constraint). These opcodes are *not*
surfaced in the Vader language. The stdlib works against an abstract `Buffer`
type whose handful of primitive methods are `@intrinsic`-lowered to these
opcodes — the same mechanism that maps `i32 + i32` to `I32Add`. stdlib authors
and users write safe Vader ; only the lowerer emits memory opcodes. `rawptr` +
`@extern` remain the separate **off-heap** FFI path, never into a GC object.

**Why opcodes, not runtime functions** : an opcode *is* the per-target contract
— each backend implements it inline (VM: index into the object ; C-emit:
`((T*)hdr->buf)[i]` ; WASM: `i32.load` / `i32.store`). So `array` / `string` /
`builder` collapse to **zero** `vader_*` runtime functions rather than relocated
ones — strictly better for the multi-target surface than the runtime-function
form first sketched here.

### 6. One raw write + the platform syscalls
`vader_write(stream, ptr, len)` is the single output primitive. Everything else
in `std/io` / `std/process` / `std/time` is platform syscalls
(`vader_read_file`, `vader_spawn_run`, `vader_clock_*`, `vader_read_dir`, …) —
kept host, but **isolated behind a thin `Platform` layer** so a new target has
one obvious file to fill in. These are genuinely un-virtualizable (POSIX vs
WASI vs Windows differ).

### 7. Transcendental math
`vader_math_sqrt/pow/sin/cos/tan/floor/ceil/round` → libm. Kept host for
precision + speed. (Trade-off noted below.)

## Movable to Vader (above the ABI)

Once the memory opcodes exist, these stop being per-target runtime code:

| Operation | Current coupling | Risk | Payoff |
|-----------|------------------|------|--------|
| **Number → string** (`Display` for i32/i64/u*/f32/f64/bool/char) | 9 × `vader_builder_append_display_*` | **Low** — pure arithmetic + byte emit | every target stops re-implementing number formatting |
| **StringBuilder** | `Builder*` ops + `vader_builder_*` | Medium | growable byte buffer over the memory opcodes |
| **Array** push / get / set / len / slice | `Array*` ops + `vader_array_*` | Medium-high | bounds-check + `load_*`/`store_*` + grow ; slice = aliasing header |
| **String** concat / slice / hash | `StringConcat` op, `vader_string_hash`, `vader_string_slice` | Medium | byte ops over the memory opcodes + intern-on-finish ; keep `==` primitive |

`Display` for user types is *already* pure Vader (the `Display` trait) — only
the primitive-number formatters are host today, and `int→string` / `f64→string`
are plain arithmetic (emit digits). That's why it's the cheapest, highest-dedup
first move.

## Phased plan

Low risk first ; each phase is independently shippable.

- **Phase 0 — Document the ABI (this doc).** Freeze the primitive list. No code.
- **Phase 1 — Number formatting → Vader.** Reimplement `Display` for the
  primitive numerics (`i8..i64`, `u8..u64`, `f32`, `f64`, `bool`, `char`) in
  `std` over byte append. Collapses the `vader_builder_append_display_*` family.
  Pure arithmetic, no GC/ABI change — needs only string-concat or a byte sink.
  **Do this first.**
- **Phase 2 — Memory opcodes + StringBuilder.** Add the `(object, offset)`
  load/store opcodes to the ABI (VM + C-emit) + the abstract `Buffer` type whose
  `@intrinsic` methods lower to them. Reimplement `std/string_builder` in Vader
  over `Buffer`. Retire the `Builder*` opcodes + `vader_builder_*`.
- **Phase 3 — Array ops → Vader.** `push/get/set/len/slice` over the memory
  opcodes (+ bounds checks, grow, slice-as-aliasing-header). Retire the `Array*`
  opcodes + most `vader_array_*`. Gated on the inliner (see caveats).
- **Phase 4 — String ops → Vader.** `concat` / `slice` / `hash` over the memory
  opcodes and `bytes()`, interning the result on finish. Keep the atom table +
  `==` primitive.

End state : the per-target runtime drops from ~200 functions to the ABI (≈15
primitives + the opcode set + the platform-syscall file). A new target
implements the ABI and gets the whole stdlib for free.

## Caveats (decide before implementing)

- **GC tracing stays primitive.** `obj_alloc(…, type_id)` carries the type so
  the collector traces boxed slots and skips primitive ones — Vader code can't
  trace itself. `store_slot` must emit the write-barrier, exactly like
  `vader_array_store_slot` does today.
- **Perf depends on inlining.** The dedicated `Array*` / `Builder*` opcodes
  exist partly for **speed** (no call overhead on a hot path). Moving them to
  Vader fns regresses unless the lowerer **inlines** these stdlib hot fns.
  Phases 3-4 are gated on that inlining landing (cross-ref the iterator
  devirt / inliner work). Phase 1 is unaffected (formatting isn't that hot).
- **Don't move the intern table** — `string ==` is O(1) only because of atom
  interning. Keep §4 primitive ; only move string *operations* that don't
  touch intern internals.
- **Math precision vs reproducibility.** A Vader softfloat math impl would make
  results **bit-identical across targets** (a real plus for a compiler), but
  costs precision + speed vs libm. Recommendation : keep libm host for now,
  revisit if cross-target float divergence ever bites.
- **Borrowed / zero-copy slices.** `array.slice` and `string.bytes()` are
  zero-copy views today (`vader_array_make_borrowed`, `vader_string_bytes_view`).
  The Vader reimplementation must preserve aliasing (a slice header pointing
  into the parent buffer), not copy — or it regresses the string/array view
  model (`docs/ARRAY_STRING_VIEW_DESIGN.md`).

## Anchors

- Opcode set : `vader/bytecode/op.vader`
- C runtime surface : `runtime/c/vader.h`
- Op-backed intrinsics : `stdlib/std/core/core.vader`, mapping in
  `vader/bytecode/intrinsics.vader::intrinsic_op_for_mangled`
- Runtime-backed intrinsics : `stdlib/std/{io,abort,runtime,time,string_builder}`
- Comptime intrinsics : `vader/comptime/intrinsic.vader`
- Already-pure stdlib : `stdlib/std/sort`, `stdlib/std/utf8`
- View model (slice aliasing) : `docs/ARRAY_STRING_VIEW_DESIGN.md`
