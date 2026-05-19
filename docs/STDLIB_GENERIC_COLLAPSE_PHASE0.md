# Phase 0 — Vtable runtime + `Any` type

> **Status**: closed 2026-05-19. 5/5 active tasks done (P0-1 runtime
> helper, P0-2 slot registry, P0-3 C emit vtables, P0-4 internal Any
> Type kind, P0-6 validation). P0-5 (lower-side dispatch on Any
> receivers) deferred to Phase 2 — no producer of `Any` types yet
> makes the lower-side path untestable in isolation.
>
> Exit criterion met via `bench/poc_erasure/Makefile :: verify`:
> compiler emits per-tag vtables matching the runtime layout, and a
> Vader binary using a user-defined trait impl compiles, links, runs.
>
> **Next**: Phase 1 (inline-box generalisation) can start in parallel
> with Phase 2 (automatic erasure pass). The dispatch runtime is
> ready ; Phase 2 needs to produce `Any` types and reroute method
> calls through `virtual.call`.
>
> **Goal (original)**: build the runtime + compiler infrastructure
> that the erasure pass (Phase 2) will plug into. No erasure happens
> in Phase 0; we only make the **dispatch mechanism** that Phase 2
> will target. ACHIEVED.
>
> **Cross-refs**: `docs/STDLIB_GENERIC_COLLAPSE.md` §2.0 (the original
> framing of this phase), `docs/STDLIB_GENERIC_COLLAPSE_POC.md` §5
> (criterion #5 selected the external-table layout used here).

---

## 0. Scope and non-scope

Scope locked 2026-05-19 (post-pivot): Phase 0 builds **infrastructure
only**, no user-facing change. The original draft introduced an
`@erase` decorator as a testing scaffold; this was inconsistent with
the parent-doc principle "user-facing API: only generics, erasure
invisible". Removed. Validation is done at the C level only — Phase 0
proves the compiler can produce vtables and the runtime can dispatch
through them; the end-to-end Vader-level validation (`get` regression
≤ 15 % on pivot tests) shifts to Phase 2 where the actual erasure
pass runs.

**In scope**:
- Runtime helper `vader_virtual_dispatch` + per-tag vtable layout in
  `runtime/c/vader.h` (P0-1, done).
- Slot registry on the compiler side: stable integer slot per
  `(Trait, method)` pair (P0-2, done).
- C emit: one vtable per `(concrete-type, trait)` pair where the type
  implements the trait, plus `vader_vtable_table[]` and
  `vader_vtable_count` (P0-3).
- New **compiler-internal** Type kind `Any` (the universal box,
  runtime-tagged). NOT exposed to the parser, the surface language, or
  LSP. Produced only by the future erasure pass (Phase 2). Added now
  so Phase 2 has a stable contract to plug into (P0-4).
- Method dispatch on `Any` receivers in lower (P0-5). Dormant until
  Phase 2 produces `Any` types — kept here so Phase 2 only adds the
  erasure pass itself, not lower-side wiring.
- C-level validation via POC extension that consumes compiler-emitted
  vtables (P0-6).

**Not in scope** (moved to Phase 2 or deferred):
- `@erase` decorator — was a scaffolding mistake, removed.
- Test snippets exercising Vader-level erasure — Phase 2.
- Stdlib `MutableMap_erased` variant — Phase 2 (automatic erasure
  covers `MutableMap` naturally).
- Bench regression measurement `map_iter_erased` — Phase 2.
- Exit criterion ≤ 15 % regression verdict — Phase 2.
- The erasure pass itself (Phase 2).
- Auto-box / auto-cast at generic boundaries (Phase 3).
- Inline-box generalisation for multi-field structs (Phase 1).
- Vader self-host port (Phase 7).

---

## 1. Design

### 1.1 Runtime vtable

```c
/* runtime/c/vader.h additions */

typedef struct {
    void* slots[/* VADER_MAX_TRAIT_SLOTS */];   /* method-fn pointers */
} vader_vtable_t;

/* One table per emitted module — array indexed by box tag. */
extern const vader_vtable_t* vader_vtable_table[];
extern const size_t          vader_vtable_count;

static inline void* vader_virtual_dispatch(uint32_t tag, uint32_t slot) {
    return vader_vtable_table[tag]->slots[slot];
}
```

- One vtable per (concrete-type, trait) pair, indexed by the type's
  runtime tag (the `BcType` index already used by boxes).
- Slots are sparse arrays — most types implement few traits, so most
  slots are NULL. The compiler emits the slot indices used; an
  unimplemented trait's slot returns NULL and the call would crash
  (the typecheck guarantees this never happens for well-typed code).
- `VADER_MAX_TRAIT_SLOTS` set initially to 32. Grows as the number of
  trait methods grows. Trivial to bump.

### 1.2 Slot registry

A single side-table in `src/typecheck/`:

```ts
// src/typecheck/trait-slots.ts
export interface TraitMethodSlot {
    trait:  string;     // fully-qualified trait name (e.g. "std/core::Hash")
    method: string;     // method name (e.g. "hash")
    slot:   number;     // stable integer
}

export class TraitSlotRegistry {
    register(trait: string, method: string): number; // returns slot
    lookup(trait: string, method: string): number | null;
    all(): TraitMethodSlot[];
}
```

Slot assignment is **deterministic** (alphabetical by `trait::method`)
so that two independent compiles assign the same slots. Persisted in
the typecheck output and consumed by the c_emit.

### 1.3 `Any` Type kind (compiler-internal only)

`Any` is a **new internal Type kind** in `src/typecheck/types.ts`. It
is never produced from a user-written type expression — the parser
does not know the keyword `Any`, the typecheck never resolves an
`IdentExpr` to it. The only way to introduce an `Any` slot is:

- The `@erase` substitution (this phase): replaces each generic type
  parameter inside a `@erase`d decl with `Any`.
- The future erasure pass (Phase 2): the same substitution, applied
  automatically project-wide.

Lowered representation: `vader_box_t`.

Internal method dispatch rule: when a method call's receiver has
static type `Any`, the lower emits an indirect call through the
vtable. The slot is looked up from the typecheck's
`TraitSlotRegistry`. Cases where the called method has no registered
slot are a **compiler bug** by construction — the typecheck-side
`@erase` substitution preserves the bound (`K: Hash & Equals`), so
the method must be on a trait listed in the bound.

Diagnostics: `--stage=lowered-ast` dump shows `Any` where erased type
params used to appear. Side-table preserves the original type for
LSP / `vader fmt` / diagnostic re-attachment when these passes need
the surface type back.

### 1.4 ~~`@erase` decorator~~ — REMOVED

The earlier draft introduced an `@erase` decorator as a per-decl
testing scaffold. Removed 2026-05-19: it contradicts the parent-doc
principle "user-facing API: only generics, erasure invisible".

Erasure is **automatic** (Phase 2). User code never opts in or out
explicitly. Iterators stay specialised via a different mechanism
(`@specialize` or a structural heuristic — deferred decision).

### 1.5 Lower-side method dispatch

When lowering a method call `receiver.m(args)`:

1. If receiver type is `Any`, look up `m` in the slot registry. If
   not found, error.
2. Emit:
   ```c
   ((return_type (*)(args_types...))vader_virtual_dispatch(receiver.tag, M_SLOT))(receiver, args)
   ```
3. The function-pointer cast is opaque — the slot registry knows the
   signature.

### 1.6 C emit additions

Per emitted module:

- One `vader_vtable_t` per `(concrete-type, trait)` impl present in the
  module.
- One `vader_vtable_table[]` indexed by tag.
- One `vader_vtable_count` constant.

The emitter walks the impl registry (already maintained for trait
method routing), groups by concrete type, and emits one vtable per
group.

---

## 2. Task breakdown

| # | Task | Files | Status | Effort |
|---|------|-------|--------|-------:|
| P0-1 | Runtime helper + macros | `runtime/c/vader.h`, `runtime/c/vader_runtime.c` | ✅ done | 0.5 d |
| P0-2 | Trait slot registry | `src/typecheck/trait-slots.ts` (new) + integration in `typed-ast.ts` | ✅ done | 1 d |
| P0-3 | C emit vtables | `src/c_emit/emit-vtable.ts` (new) + wire into `src/c_emit/emit.ts` | pending | 1-1.5 d |
| P0-4 | `Any` Type kind (internal only) | `src/typecheck/types.ts`, `src/typecheck/dump-text.ts` | pending | 0.5 d |
| P0-5 | `Any` method dispatch in lower (dormant, ready for Phase 2) | `src/lower/passes/expr.ts` | pending | 1 d |
| P0-6 | Validate via POC extension consuming compiler vtables | `bench/poc_erasure/` (extension) | pending | 0.5-1 d |

**Total remaining: ~3-4 days.** Original 7.5-9.5 d estimate halved by
removing the `@erase` scaffolding (~3 d) and the Vader-level
validation suite (~1.5 d), both moved to Phase 2.

---

## 3. Exit criteria

Two checkpoints, both at the C level (Phase 0 does not exercise Vader
code through the vtable path — that's Phase 2's job):

1. **Compiler-emit**: building any small Vader file that uses a
   user-defined trait impl (e.g. `string implements Hash` from stdlib)
   produces a `vader_vtable_table[]` entry in the emitted `.c` file
   pointing to the right impl methods. Verified by inspecting the
   emitted C and grep'ing for `[VADER_STRING_TAG] = &vt_string_*`.
2. **Runtime dispatch**: the POC extension (P0-6) links the
   hand-written bench against a compiler-emitted vtable, calls
   `vader_virtual_dispatch(STRING_TAG, HASH_SLOT)`, and the dispatch
   returns the correct hash. Verified by the bench's assertion.

Both must pass before Phase 2 starts.

Phase 1 (inline-box generalisation) can start in parallel with the
exit-criterion check — they're independent.

The original ≤ 15 % `get` regression check shifts to Phase 2 exit,
where the automatic erasure pass actually runs on real Vader code.

---

## 4. Risks

- **Slot collision across modules.** Two modules independently compiled
  might assign different slot indices to the same trait method. Mitigation:
  deterministic slot assignment (alphabetical) + a stdlib-pinned registry
  for built-in traits (`Hash`, `Equals`, `Ord`, `Display`, ...). Module-
  level trait methods that don't appear in stdlib only matter if they
  cross module boundaries through `Any` — uncommon in practice; rebuild
  the world if they conflict (pre-MVP, free per
  `feedback_mvp_no_back_compat`).
- **Sparse vtables waste memory.** Each `vader_vtable_t` carries 32
  slots × 8 bytes = 256 bytes even for types implementing 1 trait
  method. Acceptable: ~50 types × 256 bytes = 12.5 KB total. Bump
  `VADER_MAX_TRAIT_SLOTS` only if profiling shows real cost.
- **`Any` user surface introduces type-system complexity.** Sink + source
  + method-dispatch resolution add ~3-5 typecheck rules. Mitigation:
  scope `Any` minimally in Phase 0 (no generics over `Any`, no `Any` in
  trait bounds yet — these become available naturally with the erasure
  pass in Phase 2).
- **`@erase` decorator changes lowering semantics.** Risk of subtle
  divergence between a regular generic and its `@erase`d variant.
  Mitigation: the test snippet at task 7 explicitly compares behaviour;
  divergence is a bug to fix before declaring Phase 0 done.

---

## 5. Open questions answered during Phase 0

Decided as work progresses, recorded in this doc:

1. Final value of `VADER_MAX_TRAIT_SLOTS` (initial 32, may grow).
2. Naming: `Any` user-facing — confirmed. Internal lowered type also
   uses `Any` per the parent doc Decision log entry from 2026-05-19.
3. `@erase` syntax: bare decorator (`@erase`) vs parameterised
   (`@erase(strategy: ...)`). Default: bare; parameterised is a future
   extension if multiple strategies emerge.

---

## 6. Out of scope follow-ups (post Phase 0)

These come in subsequent phases — listed here only so they are not
re-litigated during Phase 0:

- Inline-box generalisation for multi-field payloads (Phase 1).
- Automatic erasure pass replacing `monomorphizeProject` (Phase 2).
- Auto-box / auto-cast at generic boundaries in lower (Phase 3).
- GC + bench validation across the whole pipeline (Phase 4).
- Self-host port (Phase 7).
