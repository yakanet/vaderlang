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
- **Perf on the native target — measured, the move is a win, not a risk**
  (`poc/target-abi/`, 2026-06-07, Apple M3 Max / clang 21, release `-O3
  -DNDEBUG`). The POC links the real runtime and benchmarks `i32[]` get/set,
  boxed `string[]` get/set, StringBuilder append, and `i64→string` against
  hand-emitted memory-opcode variants. Findings :
  - The dominant cost in today's data-structure access is **not** call overhead
    per se — it is the 24-byte `vader_box_t` round-trip + the 13-way
    `element_kind` switch inside the out-of-line `vader_array_*` helpers. The
    generic memory opcodes delete both (the opcode carries the type ; a raw
    `i32` flows instead of a box). So **even with zero inlining** the ABI path
    is ~1.9× (read) / ~2.5× (write) faster than the current runtime call.
  - The "regresses unless the *lowerer* inlines" worry **does not hold for C** :
    the rewritten stdlib is Vader compiled into the *same translation unit* as
    its callers, so the **C compiler inlines it for free at `-O3`** (and then
    auto-vectorizes primitive loops, which an opaque per-element runtime call
    can never do). The Vader-side inliner becomes a nice-to-have, not a gate.
  - "Just enable LTO" is **not** a substitute — LTO barely moves the current
    path (the box + switch survive inlining) ; the ABI wins by removing that
    work. Boxed arrays gain less (box copy + write-barrier stay in both paths)
    but still don't regress. Phase 1 (number formatting) is ~2.2× faster as a
    plain Vader digit-emit.

  Not covered by the perf POC (still to weigh) : the **VM** backend (it indexes
  a boxed `Value[]` in both paths, so the gap is expected to be far smaller),
  **cold / main-memory-bandwidth-bound** data (the POC loops are cache-resident,
  so the vectorized read figure is a hot-data ceiling), and the perf of
  `array.push` growth / `string.hash` in Vader / `mem_copy` lowering to `memcpy`.

- **GC-safety of the memory opcodes — a lowering discipline, not a blocker**
  (verified, `poc/target-abi/gc_safety.c`). Raw pointers are never exposed on
  the frontend — they exist only inside the opcode lowering, which the compiler
  controls — so the safety rule below is enforceable *by construction*. Under
  the moving Cheney collector an interior pointer into a GC object (what
  `load_i32(obj, off)` computes) is valid only until the next safepoint. The POC forces a minor collection that relocates a
  rooted object and shows a hoisted interior pointer reading a *reused* region
  (the churn sentinel `0x5A5A5A`), while re-deriving the address from the rooted
  handle stays correct. **Design rule the lowering MUST enforce** : `load_*` /
  `store_*` / `mem_copy` re-derive their address from `obj` (the SSA value the
  c_emit already spills/reloads across calls) at point of use — never hoist the
  base into a Vader local that survives an allocation. The "frontend stays
  pointer-free" constraint makes this enforceable (a base can only leak via a
  lowerer/optimizer hoist). Corollary : base-hoisting is legal only in a
  provably **allocation-free** loop ; `push` / builder-grow / transform-into
  loops must re-resolve each iteration (so the bench's `v4`/`v4b` ceiling applies
  only to alloc-free loops — allocating loops land near `v3`).

- **`store_slot` must fire the write barrier** (verified G2,
  `poc/target-abi/gc_barrier.c`). A `store_slot` of a young ref into an old
  object is invisible to a minor collection unless the generational barrier marks
  the old object's card. The POC promotes a holder to old, stores a young cell
  into its slot, runs a minor : with the barrier the cell survives (111), without
  it is reclaimed and the slot reads the churn sentinel (use-after-free). This is
  the class of bug already shipped once (`project_selfhost_gc_rooting_bug`).
  Design rule : `store_slot(obj, i, box)` emits `VADER_WRITE_BARRIER(obj)` on the
  slot-holding object ; the typed primitive stores (`store_i32`/…) must NOT (no
  ref → no old→young edge) — the stdlib picks the opcode per element kind.

- **push / hash / mem_copy measured — no regression** (`poc/target-abi/bench_more.c`,
  `-O3`). `array.push` + growth : `vader_array_push` 9.9 ns/push → ABI
  obj_alloc+mem_copy+store **2.98 ns/push** (~3.3× — same box+switch+cross-TU
  saving as get/set ; push being a hot path is not a regression risk).
  `string.hash` : moving FNV-1a 64-bit to a Vader byte loop over `bytes()` is the
  identical algorithm and **parity** (9.1 → 8.6 ns/hash, identical results) — so
  MutableMap (~71% of the self-compile) is not at risk. `mem_copy` : at `-O3` the
  C compiler vectorizes even a naive byte loop (only 1.2× off `memcpy`), but lower
  it to `memcpy` anyway — the gap widens at `-O0` and with per-byte bounds checks.

- Still open (no POC) : G3 rooting of in-flight temporaries during a Vader
  `push`'s `obj_alloc` (the model re-resolves correctly but wasn't stressed under
  a real mid-grow collection), G4 `type_id`/`ptr_offsets` sync for a hand-laid-out
  `Buffer` (a discipline, not benchmarkable in isolation).
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
- Native perf POC : `poc/target-abi/` (`bench.c` + `run.sh` ; results +
  verdict in its `README.md`)
