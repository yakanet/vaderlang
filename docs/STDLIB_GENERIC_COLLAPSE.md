# Post-Typecheck Generic Type Erasure

> **Status**: prospective. This document plans an **erasure pass between
> typecheck and lower** that removes generic type parameters from the lowered
> IR — mirroring Java / Kotlin / Scala's model. The user-facing language and
> the stdlib source remain unchanged. The lowered IR sees a single
> non-generic body per generic declaration, with auto-boxing at generic call
> sites and auto-cast at generic returns.
>
> An earlier draft proposed a manual stdlib Core/Shell pattern around an
> `Any` primitive; that approach is recorded in §7 as the alternative
> considered and discarded.
>
> **Cross-refs**: TODO §3.5 (native build wall-time), §3.6 (memory model
> extensions), §3.8 (`Into[Target]` auto-coerce, trait-object boxing);
> `docs/DESIGN_TYPE_FIRST.md` (Zig-style `fn(comptime K: type) -> type`
> direction for generics — a *different* answer to the monomorphisation
> question, worth reading alongside).

---

## Pros and cons at a glance

### Pros

- **User language surface unchanged.** Existing user code compiles
  identically. No new keyword, no new type, no new decorator visible to
  callers of generic APIs.
- **Stdlib source unchanged.** `std/collections.vader` and every other
  generic module stay as written. The collapse is a compiler responsibility,
  not a stdlib-author responsibility.
- **Single mechanism for every generic.** `MutableMap`, `MutableSet`, `Vec`,
  user-defined containers, future stdlib additions — all collapsed by the
  same pass. No per-container rewrite effort accumulates over time.
- **LoC and `cc`-time gains expected, exact magnitudes unmeasured.**
  ~15–25 % shrink on the emitted C TU; `cc` wall-time gain likely tracks
  the LoC reduction since §3.5 line 702 shows `-O3` inliner-heavy passes
  add < 1 % over `-O2`. Combined with §3.5 lever (a) split-per-module, the
  picture changes qualitatively from 161 s toward the tens of seconds.
- **Possible compiler-internal runtime gain.** Consolidating 45 specialised
  map functions into one might improve I-cache locality and branch-predictor
  training on workloads (like the compiler itself) that touch multiple map
  types in the same hot loop. Hypothesis to validate in Phase 4, not a
  baked-in win.
- **Backend-friendly.** The lowered IR becomes smaller and more regular —
  beneficial for the future direct-ASM backend (§3.5 line 683) and WASM
  target (§3.10), which inherit fewer specialisations to translate.
- **`Any` becomes optional.** No new mandatory language surface; `Any` can
  be added later as a thin alias when FFI or reflection demands it.
- **Documented precedent for the soundness model.** Erased generics with
  typecheck-at-boundary discipline are implemented in Java, Kotlin, and
  Scala; the design is referenceable from public sources.

### Cons

- **Significant compiler work.** ~4–5 weeks of focused effort, mostly in the
  lower. Larger commitment than the manual Core/Shell alternative (~2
  weeks), with deeper code-paths touched.
- **IR-shape change is hard to reverse.** Once C-emit, WASM, and direct-ASM
  backends are written against the erased lowered IR, reverting to a
  monomorphising lower means rewriting those backends.
- **Inline-box coverage is a hard prerequisite.** If `vader_box_t` cannot
  hold any ≤ 8-byte value inline, `MutableMap(i64, i64)` heap-allocates per
  insertion and the proposal becomes a perf regression. Phase 1 must
  validate before deeper work starts.
- **Cold-path checkcast cost.** Every generic-return boundary inserts a
  ~2–3 cycle tag check. Negligible on cold paths, ~5–10 % regression on hot
  paths until an analysis pass elides provably-safe cases.
- **No specialisation escape hatch on day one.** A user with a genuinely
  hot generic on numeric types has only documented hand-written non-generic
  alternatives (`IntMap`-style). A `@specialize` decorator can be added
  later if demand surfaces, but is not part of this plan.
- **Debugger and dump experience regresses.** `vader dump --stage=lowered-ast`
  shows `ErasedReference` instead of `K` / `V`. User-friendly diagnostics from any
  pass operating on the lowered AST must re-attach the original type via
  the side-table.
- **Comptime interaction needs validation.** Generic functions called from
  comptime may need to skip erasure or run in a comptime-aware mode that
  preserves enough type info for the interpreter. To be verified during
  Phase 2.

### When to revisit the decision

If Phase 1 reveals that inline-box cannot be extended uniformly, or if
Phase 2 surfaces a comptime interaction that significantly complicates the
pass, fall back to the Core/Shell alternative documented in §7. That plan
is smaller-scope and ships in ~2 weeks at the cost of a per-container
rewrite obligation.

---

## 0. Why this document exists

The self-host build emits 39 MB of C (~400 k LoC) into a single TU that takes
~161 s to `cc -O3`. §3.5 instrumentation pinned a structural cause: heavy
monomorphisation of stdlib generic containers.

- 45× `MutableMap(K, V)` × ~600 LoC = ~27 k LoC of generated code
- 45× `Entry(K, V)` × ~80 LoC = ~3.6 k LoC
- 62× `ArrayIterator(T)`, 63× `Yield(T)` (iterator core, kept specialised on purpose)
- 82× `MutableMap.put` / `ensure_buckets` / `set_at` instances

Iterators are kept specialised because the for-in fusion pass relies on
inlining them (§3.5 line 696). Maps and sets are the wrong candidates for
full specialisation — most uses inside the compiler are cold symbol tables,
type registries, module caches. The cost of duplicating their bodies
dominates the perceived value.

Lever (c) in §3.5 proposed `@erase` / `@specialize` decorators; those were
discarded as decorator-vocabulary expansion. A manual stdlib Core/Shell
pattern was then explored (see §7) and discarded as well: it solves only the
collection-by-collection case, requires per-container rewrites, and demands
new language surface for a single perf concern.

This document records the chosen direction: **let the compiler do the
collapse, once, for all generics**.

---

## 1. The chosen approach: automatic erasure

A new pass runs between typecheck and lower. It rewrites generic instantiations
to a single erased form by replacing every type-parameter position with a
uniform `ErasedReference` (an IR-only universal pointer type, never user-visible).
At generic call sites, the lower wraps arguments with `box_to_reference(...)`.
At generic returns, the lower inserts a `checkcast(...)` to recover the
statically-known type — the same operation the user can already express as
`T(value)` in their own code.

### 1.1 What the user writes (unchanged)

```vader
users := MutableMap(string, User) { .buckets = [], .size = usize(0) }
users.put("mathieu", User { .name = "Mathieu" })
found := users.get("mathieu")    // found : User | null
```

### 1.2 What the stdlib writes (unchanged)

```vader
// std/collections.vader — exactly today's source

export MutableMap :: struct[K: Hash & Equals, V] {
    buckets: (Entry(K, V) | null)[]
    size:    usize
}

export put :: fn[K: Hash & Equals, V](self: MutableMap(K, V), key: K, value: V) -> void {
    self.ensure_buckets()
    key_hash        :: key.hash()
    bucket_position :: bucket_index(key_hash)
    // walk the chain via key.equals(...) ...
}
```

### 1.3 What the lower receives (after erasure pass)

```vader
// Pseudocode — one body, shared by every (K, V) instantiation
MutableMap__erased :: struct {
    buckets: (Entry__erased | null)[]
    size:    usize
}

Entry__erased :: struct {
    key:   ErasedReference
    value: ErasedReference
    next:  Entry__erased | null
}

put__erased :: fn(self: MutableMap__erased, key: ErasedReference, value: ErasedReference) -> void {
    self.ensure_buckets()
    key_hash        :: virtual_dispatch(key, hash)         // indirect dispatch via box header
    bucket_position :: bucket_index(key_hash)
    // walk the chain via virtual_dispatch(key, equals, candidate.key) ...
}
```

### 1.4 What the lower emits at call sites

```vader
// Pseudocode — users.put("mathieu", User { ... }) becomes:
put__erased(users, box_to_reference("mathieu"), box_to_reference(user_instance))

// users.get("mathieu") becomes:
boxed_value :: get__erased(users, box_to_reference("mathieu"))    // boxed_value : ErasedReference | null
match boxed_value {
    is null             -> { found = null }
    is ErasedReference  -> { found = User(boxed_value) }           // checkcast
}
```

The `User(raw)` cast at the boundary is the same type-call cast the user
already writes for numeric conversions (`i32(x)`, `usize(16)`). The erasure
pass uses the same machinery for struct downcasts from `ErasedReference`.

---

## 2. Required compiler work

### 2.1 Inline-box generalisation — PREREQUISITE (design task, not measurement)

Single-primitive `i64` / `f64` / `string` already inline into `vader_box_t`
with no extra allocation (`runtime/c/vader.h`). The §3.5 line 694
optimisation extends inline storage to **single-field structs and empty
payloads** (`src/bytecode/types.ts` shape gate). Multi-field structs return
`null` and heap-allocate.

For erasure to be perf-acceptable on user types like `Pair { x: i64, y: i64 }`
or any small POD passed as a generic value, the inline-box rule needs to
move from **shape-gated** to **size-and-layout-gated**: any payload of
≤ 8 bytes (or, longer-term, ≤ 16 bytes if `vader_box_t` grows) should
inline regardless of field count. This is a design task — it requires:

- Bit-packing layout for multi-field payloads into `payload.i` (or growing
  `vader_box_t` and updating every GC scan path).
- New per-type GC scan info for packed payloads so the scanner can find
  embedded references precisely.
- C-emit changes to pack / unpack on box / unbox.

Without this work, erasure causes heap allocation for any generic
instantiation whose key or value is a small multi-field POD — close to the
Java pre-Valhalla trap, scoped to user structs rather than primitives.

**Action**: design the packed-payload variant of `vader_box_t`, decide
between bit-pack-into-i64 vs grow-the-box, prototype on `MutableMap(Pair, V)`
and measure allocations.

**Estimated cost**: 1–2 weeks. Not a measurement task; the existing
optimisation is structurally one-field-only by design.

### 2.2 Erasure pass

A new pass between typecheck and lower. It walks the typed AST and:

- Replaces each generic type parameter position with `ErasedReference`.
- Collapses `Foo(A, B)` and `Foo(C, D)` instantiations into a single
  `Foo__erased` definition.
- Records, at each generic boundary (call site, return, field access), the
  original concrete type for the next pass.

`ErasedReference` is an IR-internal type — it does not appear in user source, in
the typed AST exposed to LSP, or in diagnostics. It exists strictly between
the erasure pass and codegen.

**Estimated cost**: ~4–6 weeks. The pass replaces or post-processes
`monomorphizeProject` (see §8.5), threads a new side-table through every
consumer, and rekeys the DCE + hash-cons registries (§3.5 line 691). The
TS compiler's `src/lower/` totals ~5 200 LoC across 13 files; the Vader
self-host mirror (`vader/lower/`) carries the same work. Earlier "2 weeks"
estimates assumed lower-only scope.

### 2.3 Auto-box at generic call sites

Lower walks the typed AST. At each call to a generic function, arguments
flowing into erased parameter slots are wrapped with `box_to_reference(...)`. The
box header carries the runtime type tag the GC and `checkcast` already use.

For arguments already boxed (struct types, strings) this is a no-op tag
verification. For inline-fitting primitives, the value is packed into a
`vader_box_t` with its type tag — no allocation.

**Estimated cost**: ~3 days. Touches `src/lower/passes/call.ts` and the
lowered-call IR shape.

### 2.4 Auto-cast at generic returns and reads

When a value flows out of an erased context back into a typed slot
(function return, field load, pattern match arm), lower inserts a
`checkcast(ref, ConcreteType)`. The concrete type is known from the
side-table populated in §2.2.

This is the same operation as the user-level cast `T(value)`. The IR node
is the same; the difference is who decides to insert it (compiler vs user).

**Estimated cost**: ~2 days. Mirror of §2.3 on the return path.

### 2.5 GC interaction

`ErasedReference` is a uniform pointer to a `vader_box_t`. The existing GC
scanner follows it like any other pointer; the per-instance type tag in
the box header drives the precise field scan. **No new GC surface.**

A single round of `VADER_GC_STRESS=1` validation against the new pass is
sufficient — same harness the existing collections already run through.

**Estimated cost**: ~2 days for the harness runs and any fixups surfaced.

---

## 3. The `Any` question

With automatic erasure, **`Any` is no longer required** for any container.
The compiler does the boxing internally; the stdlib never names an
"untyped" type.

`Any` remains useful for three independent use cases:

1. **Explicit heterogeneous containers** — `MutableMap(string, Any)` for
   caches with mixed value types, message buses, configuration trees.
2. **FFI** — receive an opaque pointer from a C library without committing
   to a specific Vader type.
3. **Reflection / visitors** — `fn inspect(value: Any) -> string`.

If `Any` is added later, it is simply a user-visible alias for `ErasedReference`
that the compiler treats as a sink (implicit coercion from any `T`) and a
source (requires `T(value)` to use). No further work needed beyond exposure.

**Decision deferred**: ship the erasure pass first; expose `Any` as a
separate, smaller follow-up once FFI or reflection actually demands it.
~0.5 day when needed.

---

## 4. Type-safety analysis

Identical guarantees to Java's erased generics, because the model is the
same. Static typing is enforced by the typechecker on the user-facing
source. The lowered IR is dynamically typed in generic positions, but
**every transition between the two is guarded by a `checkcast`** that the
compiler inserts deterministically.

| Threat | Defence |
|---|---|
| `users : MutableMap(string, User)` accepting a `Pig` | Typechecker rejects at call site. |
| Bypassing the shell to inject untyped values | No "shell" exists — the lowered IR is internal; user code only sees typed APIs. |
| `get` returning a wrong type at runtime | Compiler-inserted `checkcast` to `V` on the return path. Tag mismatch is a runtime fault (same class as out-of-bounds access). |
| Hetero containers via `Any` | Explicit opt-in by the user typing `Any`. |

### Residual cost: checkcast on returns

By construction, every `checkcast` inserted at a generic-return boundary
will succeed — the typechecker proved the contract. Cost: ~2–3 cycles per
boundary. Negligible on cold paths.

**Future optimisation**: an analysis pass that proves a `checkcast` is safe
(no aliasing across generic instantiations of the same type) could elide it.
Not required for the initial implementation.

---

## 5. Expected gains

### 5.1 Emitted LoC

| Component | Before | After |
|---|---|---|
| 45× `MutableMap(K, V)` bodies | ~27 k | 1× erased body (~500) |
| 45× `Entry(K, V)` | ~3.6 k | 1× `Entry__erased` (~80) |
| 45× `MapIterator(K, V)` (transitive) | ~2–3 k | 1× erased iterator |
| `MutableSet(T)` (free, no extra work) | ~3 k | 1× erased body |
| All other generic types (Vec, etc.) | varies | similarly collapsed |
| **Net on 400 k LoC TU** | | **~15–25 % shrink**, dependent on how generic-heavy the program is |

### 5.2 `cc -O3` wall-time — unmeasured estimate

The optimising C compiler invoked as `cc` (clang / LLVM on macOS, gcc on
many Linux distros — both exhibit similar patterns) is super-linear in TU
size for certain passes (mem2reg, SROA, simplifycfg). A 15–25 % LoC shrink
on a regular pattern *could* yield more than 15–25 % wall-time reduction
by also breaking the inter-instantiation call graph the inliner walks.

Important honesty caveat: TODO §3.5 line 702 reports that the `-O3`-only
passes (the inliner-heavy ones) add < 1 % over `-O2`. That measurement
suggests the structural passes (parsing, mem2reg, SROA) dominate, and
their cost is closer to linear-with-overhead in TU size than super-linear.
**The wall-time gain therefore likely tracks the LoC gain (~15–25 %)
rather than amplifying it.**

| Configuration | Today | Estimated range (unmeasured) |
|---|---|---|
| `cc -O3` (current monolithic TU) | 161 s | ~120–140 s |
| Combined with §3.5 lever (a) split-per-module + `cc -j8` | 161 s | ~30–45 s (multiplicative with parallelism) |

Numbers above are *predictions to validate in Phase 5*. They are not
measurements.

### 5.3 Runtime perf — unmeasured speculation

| Workload | Conjecture (unmeasured) |
|---|---|
| Compiler self-host (multiple cold containers, deep call sites) | Possible net positive from I-cache + branch-predictor consolidation, magnitude unknown |
| Mandelbrot / primes (no containers) | Neutral by construction |
| Existing `map_iter` bench | Likely ~5–10 % regression (indirect dispatch on `hash` / `equals`) |
| Hot integer-keyed maps | Regression bounded by indirect-call cost only if the §2.1 inline-box prerequisite covers the payload — otherwise heap allocation per insertion |

The compiler-internal regime is the most interesting open question: today
45 distinct `MutableMap_put_*` functions occupy 45 distinct addresses, and
several map types are touched in the same hot loop (typecheck, lowering).
Whether collapsing them improves I-cache locality enough to offset the
indirect dispatch is a hypothesis Phase 4 has to validate, not a result to
assume in advance.

### 5.4 Secondary effects

- Binary ~15 % smaller → faster `vader fmt` / `vader lsp` cold start
  (today ~2–3 s, dominated by parse + typecheck of the stdlib).
- `vader_type_info_t` table shorter → faster GC scan dispatch.
- Less RAM during `cc` → fewer swap stalls on memory-constrained machines.
- **Future direct-ASM backend** (§3.5 line 683) and **WASM target** (§3.10)
  inherit a smaller, regular IR — fewer specialisations to translate.

---

## 6. Migration plan

### Phase 1 — Inline-box generalisation (~1–2 weeks)

Design and implement the packed-payload variant of `vader_box_t` so any
≤ 8-byte (or longer-term ≤ 16-byte) payload inlines regardless of field
count. See §2.1 for the scope. Add `bench/map_pair_value.vader` exercising
100k inserts of a multi-field POD and confirm zero per-op allocations.

**Exit criterion**: `MutableMap(Pair, i64)` insertions allocate only the
entry node, never an extra box for the payload.

### Phase 2 — Erasure pass (~4–6 weeks)

Implement the new pass between typecheck and lower. Build:
- `ErasedReference` IR type.
- AST rewriting for generic decls and instantiations.
- Side-table recording original types at each generic boundary.
- Integration with existing DCE and hash-cons.

**Exit criterion**: lower receives an AST with no generic types, and a
side-table sufficient to reconstruct boundary types.

### Phase 3 — Auto-box / auto-cast in lower (~1 week)

Patch `src/lower/passes/call.ts` and the return / field-load paths to
insert `box_to_reference` and `checkcast` using the side-table from Phase 2.
Verify that the user-level `T(value)` cast still works as a synonym for
`checkcast` so user code is consistent with compiler-inserted casts.

**Exit criterion**: full test suite green; `MutableMap` snippets produce
correct values end-to-end.

### Phase 4 — GC + bench validation (~1 week)

Run `VADER_GC_STRESS=1` against the new pipeline. Run the full `bench/`
suite, compare against baseline. Acceptable regression on `map_iter`:
≤ 10 %. Acceptable wall-time improvement on `cc`: ≥ 20 %.

**Exit criterion**: stress harness green; bench within thresholds.

### Phase 5 — Stdlib left untouched, measure gains (~2 days)

Do **nothing** to the stdlib source. The erasure pass means today's
`std/collections.vader` is already in the right shape. Measure self-host
build wall-time, binary size, and `vader fmt` startup before and after.
Compare against the §5.2 / §5.3 ranges; record actuals in this doc.

### Phase 6 — `Any` as user-visible type (optional, ~0.5 day)

When FFI or reflection demands it, expose `Any` as a user-visible alias
for `ErasedReference`. Independent of the rest; can be added or deferred freely.

---

## 7. Alternative considered: manual Core / Shell pattern

A previous draft proposed splitting each generic container into:
- a non-exported `MutableMapCore` with `Hash & Equals` and `Any` fields,
- an exported `MutableMap(K, V)` shell forwarding to the core.

The pattern works but was discarded for four reasons:

1. **Stdlib author burden** — every container needs a hand-written rewrite.
   The compiler still monomorphises shells; the gain depends entirely on
   the stdlib author's discipline.
2. **New language surface for one perf problem** — `Any` and trait-
   intersection-in-value-position would be introduced primarily to enable
   the pattern. With automatic erasure, neither is strictly needed.
3. **Smaller gain** — ~8 % LoC shrink (maps and sets only) vs ~15–25 %
   (all generics) with automatic erasure.
4. **Wrong layer** — the duplication is a property of the lowered IR, not
   of how the stdlib is written. Solving it at the compiler level matches
   the cause.

The Core/Shell pattern remains a valid fallback if the erasure pass turns
out to be infeasible or too expensive to implement. It is recorded here so
that future revisits have the trade-off in context.

---

## 8. Risks and open questions

### 8.1 Inline-box coverage on small types

The single highest-impact risk. If the inline-box opt does not cover any
8-byte-or-less type stored in an `ErasedReference` slot, `MutableMap(i64, i64)`
heap-allocates per insertion and the whole proposal becomes a perf
regression. Phase 1 must validate this before Phase 2 starts.

### 8.2 IR-shape change is hard to reverse

Once the lowered IR has no generic types, every downstream pass (C-emit,
future WASM, future direct-ASM) is written against the erased shape.
Returning to a monomorphising lower later would require redoing those
backends. Not a problem if the design is correct; a risk if Phase 4
surfaces an unexpected blocker.

### 8.3 Specialisation escape hatch

If a user has a truly hot generic on numeric types that the inline-box
optimisation cannot save, they have no opt-out today. Options if this
becomes a problem:
- Hand-written `IntMap` non-generic structures (documented pattern, ~200
  LoC each).
- An `@specialize` decorator added later for explicit per-instantiation
  opt-out. Deferred until proven necessary.

### 8.4 Debugger and diagnostics

`vader dump --stage=lowered-ast` will show `ErasedReference` instead of `K`/`V`.
Diagnostics from a backend that operates on the lowered AST need to
re-attach the original type via the side-table for user-friendly messages.

### 8.5 Interaction with comptime — significant entanglement

Comptime today **is** the source-of-truth for monomorphisation. The pass
`monomorphizeProject` lives in `src/comptime/specialize.ts` (~180 LoC),
called from `src/comptime/evaluate.ts:evaluateProject`. It walks
`(generic decl, typeArgs)` pairs, substitutes types throughout the body,
and chains transitive specialisation via `genericFnCalls`. Every later
pass (lower, C-emit) consumes the monomorphised `MonoEntry` records.

The erasure pass cannot simply "run after" this — by the time
monomorphisation is done, the generic structure has been erased *the wrong
way* (45 specialised copies). Two viable integration paths:

- **(a)** Replace `monomorphizeProject` entirely. The new pass walks
  generic decls once and emits a single erased form per decl, with the
  side-table of original types per call site. Cleanest, but ~180 LoC
  rewrite in a load-bearing area + every dependent registry (lower call
  graph, DCE, hash-cons §3.5 line 691) gets new keying.
- **(b)** Let comptime monomorphise as today, then run a post-pass that
  re-deduplicates: collapse `MutableMap_string_User`, `MutableMap_string_Pig`,
  etc. back to a single `MutableMap__erased`. Mechanical but wasteful, and
  re-creates the original-type side-table from the already-substituted AST.

**(a)** is the principled choice. Either way, the work lives inside
`src/comptime/`, not in lower as the doc's earlier framing implied. Plan
Phase 2 around `specialize.ts` rewrite, not lower-only.

### 8.6 Existing benchmarks

The `map_iter` bench was tuned in §3.5 to 22.6 ms → 9.7 ms via for-in
inline. The erased iterator path must preserve that gain. The fast path
inlines on `Entry__erased`; the only added cost is the indirect dispatch
on `hash` / `equals`. Expected regression: 5–10 %, acceptable given the
global wins.

---

## 9. Decision points

1. **Naming of `ErasedReference`** — internal-only; will not appear in user
   source. Picked at implementation; `BoxedAny`, `OpaqueRef`, `GenericRef`
   are alternatives.
2. **`Any` exposure timing** — defer to demand. Not blocking.
3. **`@specialize` escape hatch** — defer until a real perf complaint
   surfaces. Not blocking.

---

## 10. Effort and ordering

| Phase | Effort | Blocker |
|---|---|---|
| 1 — Inline-box generalisation (design + impl) | ~1–2 weeks | none |
| 2 — Erasure pass (replaces or post-processes `monomorphizeProject`) | ~4–6 weeks | Phase 1 |
| 3 — Auto-box / auto-cast in lower | ~1 week | Phase 2 |
| 4 — GC + bench validation | ~1 week | Phase 3 |
| 5 — Measure on self-host | ~2 days | Phase 4 |
| 6 — `Any` exposure | ~0.5 day | independent |

**Total realistic work**: ~8–10 weeks for Phases 1–5. Earlier "4–5 weeks"
estimates underestimated the inline-box design task (§2.1) and the comptime
entanglement (§8.5). Phase 6 is independent and deferrable.

This plan is independent of §3.5 levers (a) split-per-module and (b)
precompiled stdlib, and combines multiplicatively with both. Combined with
lever (a), the wall-time picture changes qualitatively from 161 s toward
the tens of seconds; the exact landing point is for Phase 5 to measure.
