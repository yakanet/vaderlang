# Post-Typecheck Generic Type Erasure

> **Status**: shipped (2026-05-20). Phases 0, 1, and 2 (path γ) all closed.
> Erasure infrastructure is live with `erasureDedupe` enabled by default ;
> native suite 252/252, VM suite 251/251 (4 skip). See child plans :
> [`STDLIB_GENERIC_COLLAPSE_PHASE0.md`](./STDLIB_GENERIC_COLLAPSE_PHASE0.md),
> [`STDLIB_GENERIC_COLLAPSE_PHASE1.md`](./STDLIB_GENERIC_COLLAPSE_PHASE1.md),
> [`STDLIB_GENERIC_COLLAPSE_PHASE2.md`](./STDLIB_GENERIC_COLLAPSE_PHASE2.md).
> Phase 6 (`Any` user exposure) remains deferred indefinitely — revisit only
> if FFI or reflection demands it.
>
> This document plans an **erasure pass between typecheck and lower** that
> removes generic type parameters from the lowered IR — mirroring
> Java / Kotlin / Scala's model. The user-facing language and the stdlib
> source remain unchanged. The lowered IR sees a single non-generic body
> per generic declaration, with auto-boxing at generic call sites and
> auto-cast at generic returns.
>
> An earlier draft proposed a manual stdlib Core/Shell pattern around an
> `Any` primitive; that approach is recorded in §7 as the alternative
> considered and discarded.
>
> **Cross-refs**: TODO §3.5 (native build wall-time), §3.6 (memory model
> extensions), §3.8 (`Into[Target]` auto-coerce, trait-object boxing);
> `docs/DESIGN_TYPE_FIRST.md` (Zig-style `fn(comptime K: type) -> type`
> direction for generics — a *different* answer to the monomorphisation
> question, worth reading alongside);
> `docs/STDLIB_GENERIC_COLLAPSE_POC.md` (hand-written POC plan that
> precedes Phase 0 and gates the whole effort).

---

## Decision log

Decisions taken during the planning phase, in chronological order.

- **2026-05-19 — `Any` is the IR-internal universal pointer type, *and*
  the future user-facing name.** The earlier draft separated
  `ErasedReference` (IR-only) from `Any` (potential user surface). Since
  both denote the same thing — a `vader_box_t*` with a runtime type tag —
  the doc now uses `Any` throughout. The compiler uses `Any` for the
  erasure boundary; user code may use `Any` later for heterogeneous
  containers / FFI / reflection. Diagnostic output like
  `vader dump --stage=erased-ast` will show `Any` everywhere — acceptable
  because the surface language enforces the original generic types at
  typecheck. See §3.
- **2026-05-19 — A POC precedes Phase 0.** Investigation surfaced three
  prerequisites that the original doc downplayed: no vtable exists today
  (trait dispatch is direct post-monomorphisation), no `box_to_any` /
  `checkcast` runtime helpers exist in `runtime/c/vader.h`, and
  `src/comptime/specialize.ts` is 376 LoC (not the 180 originally
  estimated) with 4 direct + 14 indirect lower-side consumers via
  `LowerProjectCtx`. A 3–5 day hand-written POC on
  `MutableMap(string, User)` precedes Phase 0 to validate the model
  against five measurable success criteria before committing to ~14
  weeks of TS work. See `docs/STDLIB_GENERIC_COLLAPSE_POC.md`.
- **2026-05-19 — Vtable runtime is its own phase (Phase 0).** Because
  trait method dispatch on generic params is direct post-mono today,
  the erasure pass cannot "reuse" an existing indirect dispatch — it
  must build one. Phase 0 adds the vtable layout, the trait-method-slot
  registry, and the `vader_virtual_dispatch` C helper. Estimated 1–2
  weeks. See §2.0.
- **2026-05-19 — TS first, then port to Vader self-host.** The TS
  compiler lands the erasure pass; the Vader self-host port (currently
  at 181/226 lower-snapshot parity) absorbs it later. During TS work,
  the self-host port continues in parallel on `c_emit` (the next
  sequential step), which is independent of the IR-shape change.
- **2026-05-19 — `Into` ↔ `checkcast` interaction: distinct IR node on
  TS, unification on port.** The TS lower currently lacks
  `try_emit_into_coercion` at return / struct-lit / let sites (the
  Vader self-host has it, added by commit 8f371c22). To avoid blocking
  Phase 3 on a TS-side `Into` alignment, the `checkcast` is inserted as
  a distinct IR node on the TS side. When porting to Vader, the
  alignment of `Into` between TS and Vader is done first, then
  `checkcast` is folded into `try_emit_into_coercion` as one of its
  coercion strategies (option (a) of the original three).
- **2026-05-19 — Self-host port not paused.** The port continues on
  `c_emit` in parallel with TS erasure work. When Phase 5 measurement
  completes on TS, the port absorbs the erasure pass as a follow-up.
- **2026-05-19 — Stage dump `--stage=erased-ast` deferred to Phase 4.**
  Nice-to-have for debugging, not needed for Phase 2 implementation.
- **2026-05-19 — Naming of `@specialize` vs structural heuristic for
  iterator skip: deferred.** The erasure pass needs a way to mark
  `ArrayIterator(T)`, `Yield(T)`, and similar types as "do not erase"
  so for-in fusion (`src/lower/passes/for-in.ts`) can keep inlining
  them. Two options on the table: an explicit `@specialize` decorator
  (clean, predictable, one new keyword) or a structural heuristic
  (magic, no new surface). Decision deferred until the POC; default
  during POC is to *not* implement the skip (POC scope = one
  collection, no iterators).
- **2026-05-19 — Baseline `cc -O3` wall-time = 161 s.** Carried over
  from TODO §3.5 measurement. Re-measure during POC for a fresh
  reference point.
- **2026-05-19 — No bytecode cache exists today.** Confirmed: the IR
  shape change does not invalidate any persisted artefact.
- **2026-05-19 — Proceed to Phase 0 after POC.** The hand-written POC
  (`docs/STDLIB_GENERIC_COLLAPSE_POC.md`) scored
  3 PASS / 1 FAIL / 1 DEFERRED. The fail (criterion #2, get runtime
  1.15-1.20× mono vs ≤ 1.10× target) is intrinsic to indirect dispatch
  and only ~5-10 pp above threshold on a synthetic micro-bench. The
  pass on criterion #3 (cc -O3 wall-time -44 % at 45 instantiations)
  is large and directly addresses the primary motivation. User chose
  option (A): proceed to Phase 0 (vtable runtime) with the explicit
  exit criterion that pivot-test real-world `get` regression must be
  ≤ 15 % after Phase 0 lands. Detailed plan in
  `docs/STDLIB_GENERIC_COLLAPSE_PHASE0.md`.
- **2026-05-19 — Vtable layout: external table (per POC criterion #5).**
  External table indexed by tag is the chosen layout. Inline-vt variant
  measured in the POC (vtable function pointers stored directly on the
  map struct) was not faster — the larger map struct offset the saved
  load. `vader_box_t` stays at 24 bytes.
- **2026-05-19 (post-Phase-0-kickoff) — `Any` is compiler-internal
  only.** Earlier "Any is IR-internal *and* future user-facing"
  decision rolled back. Phase 0 (and any subsequent phase until
  explicitly re-decided) does **not** expose `Any` in the parser, in
  the surface language, or in LSP-facing types. User-facing API: only
  generics. The compiler's internal IR still uses a Type kind named
  `Any` (visible in `--stage=lowered-ast` dumps), but no source
  program can mention it. Consequence for Phase 0:

  - Drop the parser change (no `Any` keyword).
  - Drop the sink/source typing rules (no user-visible `T(any)` cast).
  - Keep the internal Type kind, populated only by the erasure pass.
  - The compiler inserts checkcasts mechanically at internal boundaries;
    user code never writes them.
  - Phase 6 (`Any` user exposure) is deferred indefinitely. Revisit
    only if FFI or reflection demands it.
- **2026-05-19 (end of session) — Phase 2 paused via option (Φ).**
  After ~12 hours of empirical exploration, Phase 2 (automatic erasure
  pass) revealed a fundamental cascade : every `@specialize`d generic
  reachable from an erased decl receives Any-bearing queries against
  its concrete-arg registry, which doesn't have entries for those
  shapes. Local mitigations (per-decl `@specialize`) just push the
  cascade one step out — see `STDLIB_GENERIC_COLLAPSE_PHASE2.md` §9
  Issue 9. Two paths were considered :
  - **(γ)** Synthesise Any-bearing instances for every `@specialize`d
    generic reachable from an erased field. Bounded recursion. ~3-5 d.
  - **(Φ)** Accept the `cc -O3` cost. Ship Phase 0 vtable + Phase 1
    inline-box + β raw-array for-in + Phase 2 plumbing as the actual
    deliverables. Defer full automatic erasure.

  **Chosen : Φ.** The cascade exploration surfaced too many structural
  assumptions in the compiler for a confidence-bound Phase 2 ship.
  The partial deliverables stand on their own : Phase 0 + Phase 1
  ship independent perf and infra wins ; the β fix removes a brittle
  ArrayIterator dependency ; the Phase 2 plumbing (erasure-dedupe,
  symbol-redirects, lower Any dispatch, @specialize decorator) is
  dormant code paths the future investigation can re-enable.

  **Status of dormant infrastructure** (kept committed, gated off in
  `src/comptime/evaluate.ts`):
  - `erasureDedupe` post-pass in `src/comptime/erasure-dedupe.ts`
  - `symbolRedirects` plumbing through Mono/Lowered/CFG → bytecode
  - `Any` Type kind in `src/typecheck/types.ts` (no producer)
  - lower-side `Any` dispatch branch in `src/lower/passes/expr.ts`
    (no consumer)

  **What survives operationally**:
  - Phase 0 vtable runtime + slot registry — emits 130 vtables on
    self-host, used eventually by Phase 2 (γ) or any future erasure
    investigation.
  - Phase 1 packed inline-box — multi-field POD ≤ 16B pack into the
    existing `payload.packed[16]` view, **already live** ; no perf
    regression.
  - β raw-array for-in — `lowerForInRawArray` skips
    `ArrayIterator(T)` wrap for raw `T[]` iteration, **already live**.
  - η `observeFnCall` Any-substitution — independently-valid bug fix
    for comptime instance registration, **already live**.

  **For the Vader self-host port** : skip Phase 2's automatic erasure
  entirely. The TS-side exploration surfaced 9 distinct cascade
  issues ; doing the same exploration on Vader would be wasted
  effort. Re-investigate with a different design when there's a
  concrete user-facing need (currently the cc -O3 baseline of 177 s
  isn't blocking any workflow). Phase 0 + Phase 1 + β should be
  ported as-is.
- **2026-05-19 — Phase 1 closed.** Inline-box generalisation
  (`docs/STDLIB_GENERIC_COLLAPSE_PHASE1.md`) shipped in ~3 hours of
  work, well under the 1-2 week original estimate. Key insight: the
  existing `vader_box_t.payload` union is already 16 bytes wide
  (because `vader_string_t` is a 16-byte fat pointer), so a new view
  `uint8_t packed[16]` costs nothing in struct size. Multi-field POD
  structs ≤ 16 bytes with all-primitive fields (no string, no refs)
  now pack into the payload via a header-less mirror struct
  `vader_packed_<name>_t` that the C emit overlays onto the byte
  array. Validated on `Pair { x: i32, y: i32 }` — mirror emitted, no heap alloc,
  binary runs correctly. 252/252 native tests pass. Ref-bearing
  packed payloads deferred (would need a GC scanner extension).
  Phase 2 can now erase generic value slots holding small PODs
  without inducing per-op allocs.
- **2026-05-19 — Phase 0 closed.** 5/5 active tasks done (P0-1 runtime
  helper, P0-2 slot registry, P0-3 C emit vtables, P0-4 internal `Any`
  Type kind, P0-6 validation). P0-5 (lower dispatch on `Any` receivers)
  deferred to Phase 2 as it has no isolated test path. Exit criterion
  met — compiler emits
  per-tag vtables in `vader_virtual_dispatch`-compatible format ; a
  Vader binary using a user-defined trait impl compiles and runs.
  Self-host build re-measured: **168 s** (vs 177 s pre-Phase-0
  baseline) — no regression from vtable emit despite 130 vtables /
  840 tags being added to the output. Phase 1 (inline-box generalisation)
  and Phase 2 (automatic erasure pass) can start next.
- **2026-05-19 (later) — `@erase` decorator scaffolding removed.**
  Earlier Phase 0 draft introduced an `@erase` decorator as a
  per-decl opt-in for testing the vtable dispatch path before the
  full automatic erasure pass (Phase 2) lands. This contradicted the
  "user-facing API: only generics" principle: even temporary user
  surface that we'd remove later is wrong direction. Phase 0 scope
  narrowed to **C-level infrastructure only** — runtime vtable + slot
  registry + C emit vtables + internal `Any` Type kind + dormant
  lower dispatch — validated via an extension consuming
  compiler-emitted vtables. End-to-end Vader-level
  validation (`get` regression ≤ 15 %, stdlib `MutableMap_erased`,
  pivot-test bench, etc.) moves to Phase 2, where automatic erasure
  actually runs on real Vader code. Phase 0 remaining effort cut from
  ~7.5-9.5 d to ~3-4 d.

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
- **Compiler-internal `Any` IR type — no new user surface.** `Any`
  exists only inside the compiler (typecheck / lower / IR dumps) as a
  single runtime representation (`vader_box_t*`). User code keeps
  writing generics; the erasure pass and `@erase` decorator are the
  only producers of `Any` types. User exposure (Phase 6) is deferred
  indefinitely.
- **Documented precedent for the soundness model.** Erased generics with
  typecheck-at-boundary discipline are implemented in Java, Kotlin, and
  Scala; the design is referenceable from public sources.

### Cons

- **Significant compiler work.** ~11–14 weeks of focused effort (TS only;
  add 30–40 % for porting to the Vader self-host). Larger commitment than
  the manual Core/Shell alternative (~2 weeks), with deeper code-paths
  touched. Earlier "4–5 weeks" estimates underestimated the vtable
  prerequisite (§2.0), the inline-box design (§2.1) and the comptime
  entanglement (§8.5).
- **Vtable must be built from scratch.** Trait method dispatch on generic
  params is direct post-monomorphisation today
  (`src/lower/passes/expr.ts:190-205`, case `"trait-method"`). The
  erasure pass cannot reuse an existing indirect dispatch — Phase 0
  builds the vtable layout, the slot registry, and the
  `vader_virtual_dispatch` C helper. ~1–2 weeks.
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
  shows `Any` instead of `K` / `V`. User-friendly diagnostics from any
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
uniform `Any` (an IR-only universal pointer type, never user-visible).
At generic call sites, the lower wraps arguments with `box_to_any(...)`.
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
    key:   Any
    value: Any
    next:  Entry__erased | null
}

put__erased :: fn(self: MutableMap__erased, key: Any, value: Any) -> void {
    self.ensure_buckets()
    key_hash        :: virtual_dispatch(key, hash)         // indirect dispatch via box header
    bucket_position :: bucket_index(key_hash)
    // walk the chain via virtual_dispatch(key, equals, candidate.key) ...
}
```

### 1.4 What the lower emits at call sites

```vader
// Pseudocode — users.put("mathieu", User { ... }) becomes:
put__erased(users, box_to_any("mathieu"), box_to_any(user_instance))

// users.get("mathieu") becomes:
boxed_value :: get__erased(users, box_to_any("mathieu"))    // boxed_value : Any | null
match boxed_value {
    is null             -> { found = null }
    is Any  -> { found = User(boxed_value) }           // checkcast
}
```

The `User(raw)` cast at the boundary is the same type-call cast the user
already writes for numeric conversions (`i32(x)`, `usize(16)`). The erasure
pass uses the same machinery for struct downcasts from `Any`.

---

## 2. Required compiler work

### 2.0 Vtable runtime — PREREQUISITE (new phase, not in the original draft)

Investigation (2026-05-19) of `src/lower/passes/expr.ts:190-205` confirms
that trait method dispatch on generic params is **direct after
monomorphisation**: a call `key.hash()` on `key: K` where `K: Hash &
Equals` becomes a static call to the monomorphised
`i32_hash` / `string_hash` / `User_hash` once `K` is substituted. No
vtable, no indirection.

Once the erasure pass replaces `K` with `Any`, this direct dispatch can
no longer fire — the lower no longer knows which concrete `hash` impl to
call. The erasure pass must produce
`vader_virtual_dispatch(boxed_key, HASH_SLOT)` instead, dispatched at
runtime via a per-tag vtable.

Phase 0 builds this dispatch infrastructure:

- **Vtable layout.** Two options to choose between during Phase 0:
  - **(a) External table indexed by tag.** A global
    `vader_vtable_t* vader_vtables_by_tag[]` lookup; box stays 24 bytes.
    Cost: one extra indirection per virtual call.
  - **(b) In-box vtable pointer.** `vader_box_t` grows from 24 to 32
    bytes; box stores a direct vtable pointer. Cost: 33 % memory
    overhead per box, GC scanner unchanged otherwise.
  - **Decision deferred to POC** (`docs/STDLIB_GENERIC_COLLAPSE_POC.md`
    §5 criterion #5).
- **Trait method slot registry.** Compiler assigns a stable integer slot
  to each trait method: `Hash::hash → 0`, `Equals::equals → 1`,
  `Ord::compare → 2`, etc. Persisted in a side-table shared by the
  vtable emitter and the lower's call-site rewriter.
- **`vader_virtual_dispatch` C helper.** Minimal C function that takes a
  boxed value and a slot index and returns a function pointer. Inlined
  by `cc` in `-O3`.
- **Lower pass rewriting.** When a trait method is called on a value
  whose type was erased to `Any`, the lower rewrites
  `key.hash()` → `(*vader_virtual_dispatch(key, HASH_SLOT))(key)`. The
  rewrite is mechanical given the slot registry.

**Risk**: if option (b) is chosen and `vader_box_t` grows to 32 bytes,
every inline-box gain measured today shifts. POC must measure both
layouts.

**Estimated cost**: ~1–2 weeks. Layout decision + slot registry + C
helper + lower pass + GC scanner update if option (b).

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

- Replaces each generic type parameter position with `Any`.
- Collapses `Foo(A, B)` and `Foo(C, D)` instantiations into a single
  `Foo__erased` definition.
- Records, at each generic boundary (call site, return, field access), the
  original concrete type for the next pass.

`Any` is an IR-internal type — it does not appear in user source, in
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
flowing into erased parameter slots are wrapped with `box_to_any(...)`. The
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

`Any` is a uniform pointer to a `vader_box_t`. The existing GC
scanner follows it like any other pointer; the per-instance type tag in
the box header drives the precise field scan. **No new GC surface.**

A single round of `VADER_GC_STRESS=1` validation against the new pass is
sufficient — same harness the existing collections already run through.

**Estimated cost**: ~2 days for the harness runs and any fixups surfaced.

---

## 3. `Any` — IR type and future user-facing type

`Any` is **one type with one runtime representation** (`vader_box_t*`)
used in two contexts:

1. **IR-internal (always).** The erasure pass replaces every generic
   type parameter position with `Any`. The lower receives an AST where
   former generic slots contain `Any`. User code never directly types
   `Any` in this mode — the typecheck enforces the original generic
   types, the erasure happens after typecheck.

2. **User-facing (future, optional).** When FFI or reflection demands
   it, `Any` is exposed as a user-writable type for:
   - **Heterogeneous containers** — `MutableMap(string, Any)` for
     caches, message buses, configuration trees.
   - **FFI** — receive an opaque pointer from a C library without
     committing to a specific Vader type.
   - **Reflection / visitors** — `fn inspect(value: Any) -> string`.

   In this mode, `Any` is a sink (implicit coercion from any `T`) and a
   source (requires `T(value)` to use). No new runtime needed beyond
   what the erasure pass already provides.

**Naming consequence**: `vader dump --stage=erased-ast` shows `Any`
everywhere. This is acceptable because:

- The surface language (user source, typed AST, LSP, diagnostics from
  pre-erasure passes) shows the original generic types.
- Lower-AST dumps are a low-level diagnostic, not a user-facing
  artefact.

**User-facing exposure**: ~0.5 day work, deferred until FFI or
reflection actually demands it. Independent of Phases 0–5.

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

### Phase POC — Hand-written erased map (~3–5 days)

Validate the model before committing to deeper phases. See
`docs/STDLIB_GENERIC_COLLAPSE_POC.md` for the detailed plan.

**Exit criterion**: 5/5 success criteria pass on the hand-written POC.

### Phase 0 — Vtable runtime (~1–2 weeks)

Add the runtime indirection that erasure requires (§2.0). Build:

- Vtable layout decision (external table vs in-box pointer; POC informs).
- Trait method slot registry shared by emitter and lower.
- `vader_virtual_dispatch` C helper in `runtime/c/`.
- Lower pass rewrite for trait method calls on erased values.

**Exit criterion**: a hand-rolled snippet that calls
`(key as Any).hash()` correctly dispatches to the right concrete
`hash` impl via the vtable.

### Phase 1 — Inline-box generalisation (~1–2 weeks)

Design and implement the packed-payload variant of `vader_box_t` so any
≤ 8-byte (or longer-term ≤ 16-byte) payload inlines regardless of field
count. See §2.1 for the scope. Add `bench/map_pair_value.vader` exercising
100k inserts of a multi-field POD and confirm zero per-op allocations.

**Exit criterion**: `MutableMap(Pair, i64)` insertions allocate only the
entry node, never an extra box for the payload.

### Phase 2 — Erasure pass (~6–8 weeks)

Implement the new pass between typecheck and lower. Build:
- `Any` IR type.
- AST rewriting for generic decls and instantiations.
- Side-table recording original types at each generic boundary.
- Integration with existing DCE and hash-cons.

**Exit criterion**: lower receives an AST with no generic types, and a
side-table sufficient to reconstruct boundary types.

### Phase 3 — Auto-box / auto-cast in lower (~1.5 weeks)

Patch `src/lower/passes/call.ts` and the return / field-load paths to
insert `box_to_any` and `checkcast` using the side-table from Phase 2.
On TS, `checkcast` is a **distinct IR node** (the TS lower lacks
`try_emit_into_coercion` at return / struct-lit / let sites; aligning
that is deferred to Phase 7 during the Vader port). Verify that the
user-level `T(value)` cast still works as a synonym for `checkcast` so
user code is consistent with compiler-inserted casts.

**Exit criterion**: full test suite green; `MutableMap` snippets produce
correct values end-to-end. 3 pivot tests for smoke-test:
- `tests/snippets/for_in_into_iter/_main.vader` (collections + iterators + desugar)
- `bench/map_iter.vader` (`Entry(K, V)` generic + 1M `Yield` allocations)
- `tests/snippets/custom_iter_generic/_main.vader` (generic struct + trait bound)

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

When FFI or reflection demands it, expose `Any` as a user-writable type.
The runtime representation is unchanged from Phases 0–5 (`vader_box_t*`);
the only work is opening the user-facing typing rules (sink coercion
from any `T`, source requires `T(value)` to use). Independent of the
rest; can be added or deferred freely.

### Phase 7 — Port erasure pass to Vader self-host (+30–40 % of Phases 0–5)

Mirror Phases 0–5 in `vader/comptime/` and `vader/lower/`. Starts with
aligning `Into` between TS and Vader: bring TS up to parity with
`vader/lower/lower_expr.vader` (add `try_emit_into_coercion` at
return / struct-lit / let sites in `src/lower/passes/block.ts` and
`expr.ts`). Then refactor the TS-side `checkcast` distinct IR node
into `try_emit_into_coercion` as one of its coercion strategies
(option (a) from the original three-way design). Port the unified
result to Vader.

**Exit criterion**: Vader self-host emits the same erased lowered AST
as TS for the full snippet suite; lower-snapshot parity reaches
226/226.

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
8-byte-or-less type stored in an `Any` slot, `MutableMap(i64, i64)`
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

`vader dump --stage=lowered-ast` will show `Any` instead of `K`/`V`.
Diagnostics from a backend that operates on the lowered AST need to
re-attach the original type via the side-table for user-friendly messages.

### 8.5 Interaction with comptime — significant entanglement

Comptime today **is** the source-of-truth for monomorphisation. The pass
`monomorphizeProject` lives in `src/comptime/specialize.ts` (**376
LoC** — measured 2026-05-19, larger than the 180 LoC originally
estimated). It is called from
`src/comptime/evaluate.ts:evaluateProject`. It walks
`(generic decl, typeArgs)` pairs, substitutes types throughout the body,
and chains transitive specialisation via `genericFnCalls` (defined in
`src/typecheck/typed-ast.ts`,
`readonly genericFnCalls: ReadonlyMap<A.CallExpr, readonly Type[]>`).
Every later pass (lower, C-emit) consumes the monomorphised `MonoEntry`
records via `LowerProjectCtx.mono: MonoProject` in `src/lower/ctx.ts`.

**Consumers**: 4 files in `src/lower/` import `MonoEntry` / `MonoProject`
directly (`ctx.ts`, `lower.ts`, `lowered-ast.ts`, `entry-types.ts`); all
other 14 lower-side files consume them indirectly through
`LowerProjectCtx`. `src/c_emit/` does **not** import `specialize.ts`
directly — it consumes the bytecode produced after lowering. The
critical surface to redesign is therefore lower-side, not c-emit-side.

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

1. **Naming `Any`** — *decided 2026-05-19.* The IR-internal universal
   pointer type and the future user-facing universal pointer type share
   one name and one runtime representation (`vader_box_t*`). See
   "Decision log" near the top.
2. **`Any` user-facing exposure timing** — deferred to demand (FFI,
   reflection). Independent ~0.5 day work, not blocking.
3. **Iterator-skip mechanism (`@specialize` decorator vs structural
   heuristic)** — *deferred to POC.* The erasure pass needs a way to
   mark `ArrayIterator(T)`, `Yield(T)`, and similar types as "do not
   erase" so for-in fusion (`src/lower/passes/for-in.ts`) can keep
   inlining them. POC scope does not exercise iterators; decision made
   during Phase 1.
4. **Vtable layout (external table vs in-box pointer)** — *deferred to
   POC.* See §2.0. The POC measures both layouts and picks one based on
   the 5-criterion grid (`docs/STDLIB_GENERIC_COLLAPSE_POC.md` §5).

---

## 10. Effort and ordering

| Phase | Effort | Blocker |
|---|---|---|
| **POC** — hand-written erased `MutableMap` + dispatch helper + bench | **3–5 days** | none |
| 0 — Vtable runtime (layout + slot registry + C helper + lower rewrite) | ~1–2 weeks | POC pass |
| 1 — Inline-box generalisation (design + impl) | ~1–2 weeks | POC pass |
| 2 — Erasure pass (rewrites `specialize.ts` 376 LoC + 14 consumers) | ~6–8 weeks | Phase 0 & 1 |
| 3 — Auto-box / auto-cast in lower (distinct IR node on TS) | ~1.5 weeks | Phase 2 |
| 4 — GC + bench validation + `--stage=erased-ast` dump | ~1 week | Phase 3 |
| 5 — Measure on self-host | ~2 days | Phase 4 |
| 6 — `Any` user-facing exposure | ~0.5 day | independent |
| 7 — Port erasure pass to Vader self-host + unify `Into` ↔ `checkcast` | +30–40 % of Phases 0–5 | Phase 5 |

**Total realistic work**:
- POC: 3–5 days (gate before any deeper work)
- Phases 0–5 (TS only): **~11–14 weeks**
- Phases 0–5 + Phase 7 (TS + Vader parity): **~15–18 weeks**

Earlier "4–5 weeks" estimates underestimated the vtable prerequisite
(§2.0, not in original plan), the inline-box design task (§2.1), and
the comptime entanglement (§8.5: 376 LoC, not 180). Phase 6 is
independent and deferrable. Phase 7 is sequential on Phase 5 but its
internal sub-phases can pipeline against any remaining self-host port
work on `c_emit` happening in parallel.

This plan is independent of §3.5 levers (a) split-per-module and (b)
precompiled stdlib, and combines multiplicatively with both. Combined
with lever (a), the wall-time picture changes qualitatively from 161 s
toward the tens of seconds; the exact landing point is for Phase 5 to
measure.

**Self-host port during Phases 0–5**: the Vader self-host (currently at
181/226 lower-snapshot byte parity) continues its sequential port on
`c_emit` (the next step that is not yet ported) in parallel with TS
erasure work. The IR-shape change does not block port progress on
c_emit — the IR shape `c_emit` consumes is unchanged. When Phase 5
measurement completes, Phase 7 absorbs the erasure pass into the Vader
self-host.
