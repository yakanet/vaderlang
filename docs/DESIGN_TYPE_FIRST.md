# Type-First Design Exploration

> **Status**: prospective. This document is a thinking aid, not a commitment.
> The goal is to surface the trade-offs of moving Vader toward a type-first
> language so the decision can be made consciously, with full sight of what
> changes and what stays. Started as a follow-up to the "Default-init for
> generic param" discussion (see `TODO.md` §1.5b deferred).

---

## 0. Why this document exists

While planning a `Default` trait to fix `arr.sum()`-style ergonomics, we
realised the bottleneck isn't a missing trait — it's the **type system
itself**. In Vader today, types and values live in two separate worlds.
You can't write a function that returns "a value of `T`" without sample-T
or hardcoded magic, because `T` is a phantom, not a thing you can
manipulate.

Several other features on the roadmap (reflection, `@derive`, arbitrary
comptime predicates on types, user-defined code generation) are blocked
by the same wall.

Two ways out :

1. **Patch the wall locally** — add `Default` trait, add `T()` syntax,
   add intrinsic `@zero`, accumulate one bandage per feature.
2. **Remove the wall** — let types be values, evaluate type expressions
   at comptime, expose reflection, derive everything from one consistent
   substrate.

Path 2 is "type-first". It's Zig's design. It's also a multi-month
chantier that touches everything from the parser to the VM. Hence the
document.

---

## 0.5. État réel — refresh 2026-05-26

The original session ran on 2026-05-09 and the doc had not been
revisited since. Several decisions affecting the type-first framing
landed in the interval ; this section captures them so the rest of
the doc reads against the current codebase rather than the pre-session
one.

**Type-param syntax converged on `<T>`.** The doc proposes `[T]`
brackets (§11 L4 sugar / L5a). The actual migration ran
`$T → [T] → (T) → <T>` (commits `d1966f14` → `020be07d` → `9180e9ff`
→ `dbae05fc`). Reasoning : alignment with Rust / C++ / Kotlin / Java
(all of which use `<T>`, contrary to the §11 L5a claim about a
"`[]`/`()` Rust/Kotlin/Java convention"), lexer monomorphism. `$T`
is gone — Path 2's "no more phantoms" half-decision was taken de
facto. **Read every `[T]` in §11-14 as `<T>` against the current
codebase.**

**Reflection intrinsics partially shipped.** `@type_of` and runtime
`@size_of` landed via `9f44e281` (originally tagged "Layer 4 §1.19
B.2"). `@fields(T)` landed via `58b4fdfa` as an intrinsic fold in
the lowerer. Dynamic `@field(T, name)` and
`@comptime for f in @fields(T)` from §12 are NOT shipped. The
reflection row of §1's table ("Reflection : None") is therefore out
of date.

**Erasure as the runtime answer to mono.** Phases 0/1/2 (path γ) of
`STDLIB_GENERIC_COLLAPSE.md` shipped : the lowered IR sees a single
non-generic body per generic, with auto-boxing at generic sites and
auto-cast at returns. The monomorphisation pass survives but only
specialises decorated decls (`@specialize`). This is a **different
answer** to the question Path 2 Layer 2 was solving ("types live
exclusively at comptime ; mono survives but moves into the comptime
engine") — Vader's answer is "types are erased at runtime via `Any`
+ vtable, not reified". It discharges the same need without exposing
`type` to users.

**AST mirror, not fusion.** Layer 3 calls for fusing `Expr` and
`TypeExpr` into a single family. The implementation kept them split
but mirrored the structure in `vader/parser/ast.vader` (commit
`7b92f011`). The dual-resolver walk still exists.

**Runtime carrier collateral.** Atom interning
(`vader_string_t = u32`) shipped 2026-05-25 (see `ATOM_INTERNING.md`).
Not type-first by itself but reshapes §9's perf-cost analysis :
`vader_box_t` shrank 24 B → 16 B, every type-tagged union is cheaper
than the doc assumed.

**What did NOT change.** The `Default` trait need (`arr.sum()`
ergonomics, §0 motivation) remains open — `TODO.md` §1.5b still
tracks it unchecked. The ground-truth list of §1 ("`T` cannot be
assigned to a variable, passed as a function argument, compared,
inspected, constructed from") is still mostly true at the user
surface : `@type_of` enables some inspection from the lowerer, but
no user-level code can write `let U: type = T`.

See §10bis for the actual decision-point this state surfaces.

---

## 1. Current state — types in Vader

Vader's type system is **TypeScript / Java / Kotlin** in spirit :

| Aspect | Today |
|---|---|
| Are types values? | No |
| Type-typed variables? | No (no `let T = i32`) |
| Generic params | `$T` phantoms, substituted at monomorphisation |
| Reflection | None (no `@type_of`, `@field_names`, `@size_of`) |
| Comptime types | Limited — `@comptime` consts evaluate values, not types |
| Compile-time predicates on types | Only `where T: Trait` (and even that is half-validated, see TODO §1.4) |
| Type-of-a-type | No (no kind system) |

Generic functions and structs:

```vader
// $T is a phantom. The compiler tracks "this fn is parameterised by T".
sum_with :: fn(arr: $T[], init: T) -> T where T: Add { ... }

// Mono pass materialises one specialisation per concrete (T, ...) tuple
// observed at call sites.
```

`T` cannot be:
- assigned to a variable;
- passed as a function argument;
- compared (`if T == i32 { ... }`);
- inspected (`size_of(T)`, `field_names(T)`);
- constructed from (`T()`).

Anywhere these capabilities are needed, we have to invent a syntactic
or semantic special case.

---

## 2. What "type-first" means

Concretely, four things change.

**(a) `type` is a first-class type.**
A value of static type `type` *is* a Vader type at runtime (or, more
typically, at comptime). You can store types in variables, pass them as
arguments, return them from functions:

```vader
let T: type = i32

let pair_type: type = pair(i32, string)        // pair returns a type

fn maybe(comptime T: type) -> type {
    return T | null
}
```

**(b) Generic parameters are explicit comptime values.**
`$T` becomes sugar (or alternative syntax) for `comptime T: type` :

```vader
// Zig-style explicit form:
sum :: fn(comptime T: type, arr: T[]) -> T where T: Add { ... }

// Sugared form (compiler synthesises the comptime param) :
sum :: fn(arr: $T[]) -> T where T: Add { ... }
```

These two forms are equivalent. The sugared one is what Vader users
already write; the desugared form is what enables the rest.

**(c) Type expressions can be computed at comptime.**

```vader
default :: fn(comptime T: type) -> T = T.zero       // T is a value with members

@comptime
ARRAY_KIND :: pair(i32, i32)                        // type computed at comptime
```

The comptime engine (which already exists, runs on the bytecode VM)
evaluates type-valued expressions just like any other comptime expression.

**(d) Reflection becomes possible.**

```vader
fn debug_print(x: $T) {
    for field in @field_names(T) {
        println("${field} = ${x.${field}}")
    }
}

@assert size_of(MyStruct) <= 32                    // compile-time assertion

derive_eq :: fn(comptime T: type) -> type {
    // Generate an Eq impl from T's fields at comptime
    // Returns a new type that wraps T with the impl
}
```

These four things together transform what's possible. They're also
**deeply entangled** — you can't have (d) without (c), can't have (c)
without (b), can't have (b) without (a). It's an all-or-nothing axis,
modulo the migration strategy (see §7).

---

## 3. Reference — how Zig handles it

Zig is the reference design for "type-first compiled language with
manual memory management". Comparing to Vader's design space :

```zig
// Zig
fn ArrayList(comptime T: type) type {
    return struct {
        items: []T,
        len: usize,
    };
}

fn fold(comptime T: type, comptime U: type, arr: []T, init: U, f: fn(U, T) U) U {
    var acc = init;
    for (arr) |x| acc = f(acc, x);
    return acc;
}

const list_i32 = ArrayList(i32);              // a TYPE bound to a const
var x: list_i32 = .{ .items = ..., .len = 0 };

// Reflection :
@compileLog(@typeName(list_i32));             // "ArrayList(i32)"
inline for (@typeInfo(list_i32).Struct.fields) |field| { ... }
```

Two things to note:
- Zig requires `comptime` keyword on type-typed parameters. Implicit
  `$T` doesn't exist — you write the comptime param explicitly.
- Zig's `inline for` is comptime iteration. It's how `@derive`-style
  features get implemented in user code without compiler magic.

Other languages worth pointing at :
- **Nim** — types-as-values via `type` keyword + heavy comptime macros.
- **D** — `static if`, `__traits`, comptime function evaluation.
- **C++** templates — types are template parameters but the comptime
  evaluation language is its own dialect (`constexpr`, `if constexpr`).
- **Idris/Agda** — full dependent types ; types depend on runtime values.
  Probably overkill for Vader's goals.

---

## 4. Vader's stdlib under each model

### `MutableMap` — today

```vader
export MutableMap :: struct($K, $V) {
    buckets: (Entry(K, V) | null)[]
    size:    usize
}

export put :: fn(self: MutableMap($K, $V), key: K, value: V) -> void where K: Hash + Eq { ... }
export get :: fn(self: MutableMap($K, $V), key: K) -> V | null where K: Hash + Eq { ... }
// ... 6 more methods, each repeating `where K: Hash + Eq`
```

### `MutableMap` — under type-first (Zig style)

```vader
export MutableMap :: fn(comptime K: type, comptime V: type) -> type where K: Hash + Eq {
    return struct {
        buckets: (Entry(K, V) | null)[]
        size:    usize
    }
}

// Methods are simply functions with the bound expressed once on the
// generator. Or we keep the sugared $K $V form and a sugar transform.
```

The bound moves to the type-generator function. No repetition. The
typecheck happens once at instantiation time.

### `std/iter::sum` — today (specialised)

```vader
export sum :: fn(arr: i32[]) -> i32 {
    s := 0
    for x in arr { s = s + x }
    return s
}
// Plus duplicate sum_i64, sum_f64, sum_u64 if desired.
```

### `std/iter::sum` — under type-first

```vader
export sum :: fn(arr: $T[]) -> T where T: Add + Zero {
    acc := T.zero                       // works because T is a value
    for x in arr { acc = acc + x }
    return acc
}

// Or via fold + a type method :
export sum :: fn(arr: $T[]) -> T where T: Add + Zero {
    return arr.fold(T.zero, +)
}
```

### `@derive(Eq)` — today

Compiler magic decorator. Has to be hardcoded.

### `@derive(Eq)` — under type-first

User-writable, in stdlib :

```vader
@derive_macro
export Eq :: fn(comptime T: type) -> impl_block {
    let fields = @field_names(T)
    return impl_block {
        fn equals(self: T, other: T) -> bool {
            for f in fields {
                if self.${f} != other.${f} { return false }
            }
            return true
        }
    }
}
```

This is a much bigger feature surface than today's compiler-known
`@derive`s. It's user-extensible.

### Reflection over fields — today

Impossible. Compiler intrinsics only know what's hardcoded.

### Reflection — under type-first

```vader
fn to_json(x: $T) -> string {
    let sb = new_builder()
    sb.append("{")
    for (i, f) in @fields(T).enumerate() {
        if i > 0 { sb.append(",") }
        sb.append("\"${f.name}\": ")
        sb.append(json_serialize(x.${f.name}))     // recursive, dispatched per type
    }
    sb.append("}")
    return sb.to_string()
}
```

`std/json::stringify` could be written entirely in Vader user code,
with no compiler help.

---

## 5. Roadmap features under each model

Going through `TODO.md` §3.8 and §3.4 :

| Feature | TypeScript++ path | Type-first path |
|---|---|---|
| `Default` for generic param | Approach (A) + trait + impls. ~1d. | `T.zero` falls out. ~0d if type-first lands. |
| `@derive(Eq, Display)` | Compiler-hardcoded list. ~3d for Eq, ~3d for Display, etc. | User-writable in `std/derive`. ~0d marginal. |
| `where size_of(T) <= 16` | Needs an intrinsic + comptime predicate language. ~5-7d. | Falls out of comptime evaluator. ~1-2d. |
| Operator overloading via traits | `Add`/`Sub`/`Mul` traits + dispatch. 5-10d. | Same — traits don't disappear, they just become comptime predicates. 5-10d. |
| `Iterable($T) + auto-.iter()` | Trait + lower pass. 3-5d. | Same. 3-5d. |
| Reflection (field walks, type names) | Impossible without massive intrinsic surface. | Built-in. ~0d once type-first lands. |
| Conditional types (`maybe(T, opt)`) | Impossible cleanly. | Trivial. |
| Implicit `void` return | Parser/typecheck. ~1d. | Same. |
| `where T: A & B` | Parser + typecheck. ~1d. | Same. |
| Static-size arrays `[T; N]` | Parser + typecheck + lower. 5-7d. | Same — array sizes aren't types-as-values. |
| Spread destructuring | Parser + lower. 2-3d. | Same. |
| Struct spread `{ ...other }` | Parser + typecheck + lower. 2d. | Same. |
| Process spawn intrinsic | Stdlib + runtime. 1d. | Same. |
| LSP server | Independent. ~weeks. | Independent. |
| Self-host suite | Substantial. ~months. | Substantial. ~months *plus* migration of $T uses. |

**Observations**:

- The features that **most clearly benefit** from type-first :
  `@derive`, reflection, conditional types, comptime predicates. These
  are deeply expressive features that are awkward-to-impossible without
  type-first.
- Many other roadmap items are **orthogonal** to the type-first
  question. Operator overloading, traits, struct spread, process spawn,
  static-size arrays, etc. — they need work either way.
- A few items get **smaller** under type-first :
  `Default`, comptime predicates on size/kind. These are the original
  "Default" question and friends.

---

## 6. Migration / breaking changes

What breaks if Vader becomes type-first :

**Source-level :**

- `$T` syntax can be **kept as sugar** for `comptime T: type`. So
  most existing fn signatures don't change. Nice.
- Types become **values** — the keyword `type` is now reserved (it
  already is, see `TypeAliasDecl`).
- `where T: Trait` clauses **stay**, but they're reinterpreted as
  comptime predicates : `where @impl(T, Trait)` or similar.
- Reflection intrinsics added : `@type_of`, `@field_names`, `@size_of`,
  `@kind`, `@type_args`, etc.
- Existing snapshots / parser tests don't break (no syntax change for
  user code that doesn't use the new features).

**Compiler-level :**

- Resolver learns `type` as a builtin type.
- Typechecker learns to type-check expressions of static type `type`.
- Comptime engine evaluates type expressions.
- Mono pass disappears or becomes "comptime evaluation of type-args at
  call sites" — the substitution machinery moves into comptime.
- Reflection intrinsics need backend support (per type-info table at
  comptime ; possibly a runtime side-table for some uses).

**Stdlib :**

- Generic structs (`MutableMap`, `MutableSet`, etc.) get refactored to
  the type-generator pattern *or* keep their `$K $V` sugar. Choice.
- New `std/derive`, `std/reflect` modules become possible.
- `@derive` decorator's hardcoded list eventually migrates to user-
  writable derive macros.

**Tests :**

- Snapshots regenerate (mono + lower output changes).
- Estimated hit : maybe 30-50% of existing snapshots redo.

---

## 7. Three paths

### Path 1 — TypeScript++ (status quo + bandages)

Stay structural and erased. Add features one bandage at a time :
`Default` trait, intrinsic `@zero`, hardcoded `@derive`, etc.

- **Effort** : 0 strategic redesign. Each feature pays its own cost.
- **Outcome** : Vader stays comfortable for users who like TypeScript.
  Hits a ceiling around reflection / derive / comptime predicates ;
  those features have clunky forms or remain unimplementable.
- **Risk** : the bandage count grows. Each new generic feature adds
  its own intrinsic. Stdlib stays specialised by type.
- **Identity** : "TypeScript modernisé pour le natif".

### Path 2 — Full type-first (all-in, multi-month)

Redesign the type system to make types first-class values.

- **Effort** : ~2-3 months for the core (type-as-value, comptime types,
  basic reflection). +1 month for stdlib migration. +months for
  ecosystem (LSP, formatter, examples) catching up.
- **Outcome** : Vader becomes a Zig-class language with its own
  comptime story. Reflection, `@derive`, conditional types are
  user-writable.
- **Risk** : compiler complexity goes up. Type-checking time goes up.
  Some user code breaks (rare, but the model shift may surface
  edge cases). The self-host port has to be redone if started before
  type-first.
- **Identity** : "Zig with Vader's syntax and trait system".

### Path 3 — Incremental type-first

Introduce `type` as a builtin alongside the current system. Both
coexist. Existing `$T` keeps working (it's now sugar). New features
opt into the type-first machinery.

- **Effort** : ~1 month for the parallel infrastructure. Then features
  added incrementally.
- **Outcome** : same as path 2, eventually, but spread over a longer
  timeline. Less risk of breaking things in flight.
- **Risk** : two systems coexisting create the worst-of-both-worlds
  pitfall (TypeScript's any vs strict modes). Need clear migration
  story.
- **Identity** : "evolving from TS-style to Zig-style".

---

## 8. Open questions (decide before committing)

These are the questions whose answers shape the design. None has an
obvious answer.

**Type representation**

1. Are types **erased at runtime** (TypeScript-style) or **carried**
   (Zig keeps them at comptime, but they're erased at codegen) ?
2. Does `type` need a runtime representation (e.g. for `is T` checks
   on traits) ? Today Vader has tags ; how do they relate to
   comptime-known types ?

**Generics syntax**

3. Do we **keep `$T` sugar** or migrate to explicit `comptime T: type` ?
   The sugar is friendly but hides what's happening.
4. Do we add **explicit type-args at call sites** (`foo[i32, string]()`) ?
   Useful when inference fails ; AST node already exists.

**Trait / where**

5. Are trait bounds still `where T: Trait` (predicate) or do they
   become comptime predicates (`where @impl(T, Trait)`) ?
6. Do traits stay as a special concept, or become functions returning
   `bool` that the typechecker calls at comptime ?

**Comptime semantics**

7. Can a `comptime T: type` parameter depend on a runtime value ? (No,
   in Zig — comptime is comptime.) How do we express that boundary ?
8. What's the comptime evaluation budget ? (Zig has a "branches
   evaluated" budget. We don't have equivalent today.)

**Reflection scope**

9. What's the minimum reflection surface ? `@type_name`, `@field_names`,
   `@size_of`, `@align_of`, `@type_kind`, `@type_args`, `@is_struct`,
   `@is_enum` — which of these are first-class, which are derived ?
10. Can users write **hygienic macros** (Lisp-style code-gen) or just
    type-level `if`s à la Zig's `inline for` ?

**Migration**

11. Phase the migration : feature-by-feature (Path 3) or big-bang
    (Path 2) ?
12. Where does mono live in the new world ? Today it's a separate
    pass ; under type-first it merges into comptime.

---

## 9. Estimation per path

**Path 1 (TypeScript++)** : per-feature cost.
- Default trait + auto-impls + (A) + return-type inference : ~3d.
- `@derive(Eq)` hardcoded : ~3d.
- `@derive(Display)` hardcoded : ~3d.
- Comptime predicate on `size_of(T)` : ~5-7d.
- Reflection : not feasible without massive intrinsic surface.
- **Total to feature-parity with type-first** : weeks to months,
  feature-by-feature, never reaching the full surface.

**Path 2 (Full type-first)** :
- Core (type-as-value, comptime types, basic intrinsics) : ~6 weeks.
- Stdlib migration : ~2 weeks.
- Test snapshot churn : ~1 week.
- Self-host port adaptation : ~2 weeks (since the resolver already started).
- **Total** : ~3 months.

**Path 3 (Incremental type-first)** :
- Parallel `type` infrastructure : ~3 weeks.
- Migrate features as needed : N weeks per feature.
- Sustained migration cost over ~6 months.
- **Total** : same 3 months of work, spread over 6.

---

## 10. Recommendation

**Don't decide today.** This is a strategic call that affects every
roadmap item below it. Sleep on it.

**My honest read** :

- If Vader is a personal hobby compiler that aims for a comfortable
  language with native compilation, **Path 1** is fine. It's tactical,
  pay-as-you-go.

- If Vader has ambition to compete in the "modern compiled language"
  space (Zig, Nim, Crystal, Odin) and offer something distinctive on
  the type system / reflection / derive axis, **Path 2 or 3** is
  necessary. The roadmap items that need type-first are the ones that
  set Vader apart.

- The **clincher** is what you, as designer, find joy in. Type-first
  redesigns are intellectually demanding but rewarding. Bandages are
  fast but they accumulate.

Before deciding, consider :

1. Spend a week prototyping in a branch — write a `type-first/` folder
   with parallel module signatures and see how the syntax feels for
   `MutableMap`, `std/iter`, `std/json`.
2. Look at three real-world Vader programs you'd want to write
   (e.g. a JSON serialiser, a config-file parser, a mini-ORM). Sketch
   them under both paths. Whichever feels more natural is your answer.
3. Talk to the use case where Default-init was originally needed
   (`arr.sum()`). Is the cost of (A)+(Default trait) really blocking
   you, or is it the canary for a deeper question ?

This document is the canary. The deeper question is whether Vader's
type system is the right tool for the language you want to build.

---

## 10bis. Décision implicite — Path 3 partiel (refresh 2026-05-26)

§10 closed on *"don't decide today"* in 2026-05-09. In the year since,
decisions were made through implementation rather than through a
returning conversation. Here is what the project effectively committed
to, what it didn't, and the actual open question.

### Taken from Path 2 (de facto)

- **`$T` phantom retired.** Migration ran `$T → [T] → (T) → <T>` in
  four steps. Path 2's "type-params are explicit, not sigils" half-
  decision is in.
- **Reflection intrinsics partial surface.** `@type_of`, `@size_of`,
  `@fields(T)` shipped. Path 2 Layer 6 partial.
- **AST mirrored.** `vader/parser/ast.vader` mirrors the unified `Expr`
  family used internally. Doesn't fully fuse like Layer 3 proposes,
  but moves toward it.
- **Erasure as the runtime answer.** Path γ erasure (`Any` IR type,
  vtable runtime, auto-box / auto-cast) ships in
  `STDLIB_GENERIC_COLLAPSE.md`. Vader's answer to the "types at
  runtime" question : types are erased, not reified. More
  conservative than Layer 1 ("hybrid : opaque + intrinsic access")
  but discharges the need without exposing `type` to users.

### NOT taken from Path 2

- **Layer 1 user-facing `type`.** No `let T: type = i32`, no `T` as
  argument or return type at the user level. The compiler internally
  has a `Type` union and an `AnyType` IR kind, but user code cannot
  mention them.
- **Layer 3 AST fusion.** Mirrored, not fused. The dual-resolver walk
  for type position vs. value position is still in place.
- **Layer 4 purity + memoisation contract.** No formal language-level
  contract that type-producing expressions are deterministic and
  memoised. The current generic engine memoises by `(decl, type-args)`
  tuple but there's no user-relyable guarantee.
- **Layer 7 trait desugar.** `where T: Foo` stays as-is, not desugared
  to `@satisfies(T, Foo)`. No `&`-composition surface for bounds yet.
- **Layer 8 impl coherence + orphan rule.** Coherence is enforced by
  the resolver but not specified in SPEC ; no explicit orphan rule.

### The real decision now

Not *"Path 1 vs Path 2 vs Path 3"* — the project **is in** Path 3
partial. The decision is :

**Do we finish Path 3, or freeze the current surface as the
destination ?**

- *Finish Path 3* means : commit to Layer 7 (`where` desugar +
  `&`-composition for bounds), Layer 8 (orphan rule spec), and the
  remaining Layer 6 reflection items (`@field` dynamic, `@comptime
  for`). Probably 2-3 chantiers de 1-2 semaines.
- *Freeze* means : declare `<T>` + (`@fields`/`@type_of`/`@size_of`)
  + path-γ erasure as the canonical Vader type model. SPEC.md gets
  the lock. Address `Default` ergonomics with a bandage
  (`zero<T>()` intrinsic or trait) rather than as a milestone on the
  way to type-first.

The question is whether the remaining Path 3 layers buy something a
hobby pre-MVP language actually needs, or whether they are
perfectionism. The §0 motivation (`arr.sum()` blocked by missing
`Default`) is still open and small enough that either path resolves
it ; that ergonomic question alone doesn't force either decision.

---

## 11. Path 2 — design sketch (working draft)

> **Status**: design notes from the 2026-05-09 session exploring what
> Path 2 concretely looks like. Not a commitment to Path 2 yet — this
> records the *shape* of Path 2 if chosen, so the §10 comparison can
> be made on substance rather than abstraction.

The headline : Path 2's surface stays close to current Vader. Heavy
machinery moves into the compiler, not into user-facing syntax.
`comptime`, `: type`, `-> type` **never appear in user code** — they
exist as internal desugaring only. Users keep writing the `struct($T)`
and `$T`-phantom forms they already know.

### Decisions, by layer

| # | Layer | Decision | Closes §8 |
|---|---|---|---|
| 1 | `type` semantic model | Hybrid : opaque at language level ; member access (`T.zero`, `T.size`) resolves to intrinsics | Q1 |
| 2 | Runtime existence | Comptime-only ; mono pass survives but migrates into the comptime engine | Q1, Q2, Q12 |
| 3 | AST | Fuse `Expr` and `TypeExpr` into one `Expr` family | — |
| 4 | Type-producing fns | Pure + memoised by `(generator, args)` | — |
| 4 (sugar) | User-facing syntax | Type-params declared in `[]` brackets : `struct[T]`, `type Foo[T] = ...`, `fn[T]() = expr` ; bounds attach inline (`[T: Bound]`) ; `&` composes ; never expose `comptime`/`: type`/`-> type` | Q3 |
| 5a | Explicit type-args | Uniform `[]` for type-args at both declaration and call site : `MutableMap[i32, string]`, `sum[i64](arr)` | Q4 |
| 5b | Comptime contagion | `type`-typed expressions must be comptime-evaluable ; the static type carries the contagion | Q7 |
| 5c | `is` operator | Stays syntactic and lowers to a tag comparison ; not coupled to comptime type-values | — |

### Layer 1 — `type` semantic model

A value of static type `type` is opaque. The compiler reserves
member-access syntax on it (`T.zero`, `T.size`) and lowers each access
to a dedicated intrinsic. The internal type-table representation stays
free to evolve without breaking user source.

### Layer 2 — comptime-only

Types live exclusively at comptime. No runtime `type` values, no RTTI.
The current mono pass is **not deleted** : it moves into the comptime
engine. Calling `fn($T, ...)` at a site partially-evaluates the fn
with `T` bound, producing a specialised version. Caching by
`(fn, args)` tuple = same dedup as today's mono.

### Layer 3 — fused AST

Single `Expr` family. `i32 | string` becomes the value-level `|`
applied to two `type` values. The parser stops switching modes between
type and value contexts ; the typechecker uses position to demand
`type`-typed expressions where required (`:`, `where`, generic arg
slot).

This is the **largest compiler-side chantier** in Path 2 — it
eliminates the `TypeExpr` dual resolver walk entirely.

### Layer 4 — purity + memoisation

Any expression producing a `type` value is :
- **deterministic** in its inputs (no I/O, no global mutable state) ;
- **memoised** by `(generator, args)` so `MutableMap[i32, string]`
  called from two sites yields the *same* type.

Without memoisation, structural identity breaks and interop is lost.
Without purity, memoisation is ill-defined.

### Layer 4 (sugar) — surface syntax

> *Refresh 2026-05-26 :* the 2026-05-09 draft chose `[T]` brackets.
> Implementation landed on `<T>` chevrons (see §0.5). The substance
> below — locality, `&` composes, fn-form only when logic is needed
> — is unchanged ; only the bracket style is corrected. The
> Rust/C++/Kotlin/Java rationale for chevrons is the lexer
> monomorphism Path 2 was already aiming for, and the alignment
> bonus against those languages.

Type-params are declared in `<>` chevrons at the declaration site
(locality : the bound sits with its param). The `&` operator composes
constraints — same operator as Vader's existing type-intersection,
which is sound because composing trait bounds *is* an intersection of
satisfaction sets.

```vader
MutableMap :: struct<K: Hash & Eq, V> {
    buckets: (Entry<K, V> | null)[]
    size: usize
}
```

Computed type aliases (existing `TypeAliasDecl`, slightly extended) :

```vader
type Maybe<T> = T | null
type Pair<A, B> = struct { first: A, second: B }
```

Fn-form, only when logic is required :

```vader
boxed :: fn<T>() = if size_of(T) > 16 { Heap<T> } else { Stack<T> }
derive_eq :: fn<T>() = impl_block { fn equals(a: T, b: T) -> bool { ... } }
```

Return-type inference eliminates `-> type`. The chevron type-param
position implies `comptime`. Side-by-side with Zig :

```zig
// Zig
fn ArrayList(comptime T: type) type {
    return struct { items: []T, len: usize };
}
```

```vader
// Vader Path 2 (with chevrons as actually shipped)
ArrayList :: struct<T> { items: T[], len: usize }
```

Same semantics. One line. No `comptime`, no `type` return, no
`return`, no `fn` ceremony.

The previous Vader `$T` phantom syntax does **not** survive — all
type-params are explicit in `<>`. The migration cost was paid in
2026 via the `$T → [T] → (T) → <T>` chain documented in §0.5.

### Layer 5a — uniform `<>` for type-args

Single regime : type-args always go in `<>`, both at declaration and
at call site. No second slot to remember.

- **Type generators** : `MutableMap<i32, string>`, `Maybe<i32>`,
  `Pair<i32, string>`.
- **Mixed-param fns** : inference covers ~95 % of call sites. When it
  fails, the override stays `<>` : `sum<i64>(arr)`.

The `<>`/`()` split mirrors the Rust / C++ / Kotlin / Java convention :
chevrons for type-arg positions, parens for value-arg positions. The
single rule applies uniformly to declarations and call sites — no
asymmetry between defining `MutableMap<K, V>` and instantiating it as
`MutableMap<i32, string>`.

### Layer 5b — comptime contagion

A value of static type `type` **must** be comptime-evaluable. The
typechecker rejects runtime-dependent type expressions :

```vader
let t: type = if user_input == "fast" { i32 } else { i64 }   // ERROR
sum[t](arr)
```

and accepts comptime-known ones :

```vader
@comptime IDX_TYPE :: if TARGET_PTR_SIZE == 64 { i64 } else { i32 }
sum[IDX_TYPE](arr)   // OK
```

Consequence : `let T: type = ...` is implicitly comptime by virtue of
its type. No new "runtime type" category to spec.

### Layer 5c — `is` operator unchanged

`if x is SomeVariant` keeps its current semantics : the RHS is a type
name resolved at compile time and lowered to a tag comparison. **Not
coupled to comptime type-values.** Reason : `is` operates on runtime
tags ; types are erased at runtime (Layer 2) ; coupling them would
resurrect RTTI for no real gain. Users who want dispatch on a
comptime-computed type go through `match` or a dispatch table.

### Open after Layer 5

§8 questions still unanswered after these decisions :
- **Q5, Q6** — trait/`where` as comptime predicates, or kept as a
  distinct concept ?
- **Q8** — comptime evaluation budget (Zig has one ; Vader doesn't).
- **Q9** — reflection scope. Layer 6 — next session.
- **Q10** — hygienic macros vs `inline for`-only.
- **Q11** — migration phasing (Path 2 big-bang vs Path 3 incremental).

---

## 12. Layer 6 — reflection scope

> Decisions from the same 2026-05-09 session, continuing §11.

### 6a — Iteration syntax : `@comptime for`

```vader
@comptime for f in @fields(T) {
    println("${f.name}: ${f.type}")
}
```

Reuses the existing `@comptime` annotation. Marks the structural shift
from runtime loop to comptime unroll without inventing a new keyword
(unlike Zig's `inline for`).

**Generalisation rule** : `@comptime` is a statement-level prefix
meaning « I require comptime evaluation here, fail otherwise ». For
`for` it is structurally necessary because a bare `for` reads as
runtime. For `if` it is not — Layer 5b's contagion already makes an
`if` over a comptime condition evaluate at comptime. `@comptime if`
can be added later as an explicit assertion form if real demand
appears.

### 6b — `@fields(T)` returns `Field[]`

A `Field` struct is declared once in `std/reflect` :

```vader
type Field = struct {
    name: string
    type: type
    offset: usize
}
```

`@fields(T)` returns a comptime-known `Field[]` ; the `@comptime for`
loop unrolls it. Choosing a struct over bare strings means each piece
of metadata travels together — no need for `@field_type(T, name)`,
`@field_offset(T, name)`, etc. — and `Field` becomes a reusable type
that user comptime code can pass around.

### 6c — Dynamic field access via `@field`

```vader
@comptime for f in @fields(T) {
    let value = @field(x, f.name)
    ...
}
```

Use the `@field(x, name)` intrinsic, not a `x.${name}` interpolation
syntax. Reasons :
- `${...}` is already the string interpolation form ; reusing it
  inside an access expression forces contextual lookahead in the
  parser.
- The intrinsic is explicit — a reader sees that this is reflective
  access, not a static field read.
- Compositional : `@field` accepts any comptime string expression.

If the pattern becomes pervasive, sugar can be layered on top later.
We start with the primitive.

### Reflection surface — primitive vs derived

**Primitive** (compiler intrinsics) :

| Intrinsic | Returns | Role |
|---|---|---|
| `@type_of(x)` | `type` | Static type of an expression |
| `@type_name(T)` | `string` | Printable name |
| `@type_kind(T)` | `TypeKind` | struct / enum / union / primitive / ... |
| `@size_of(T)` | `usize` | Size in bytes |
| `@align_of(T)` | `usize` | Alignment |
| `@fields(T)` | `Field[]` | Field introspection |
| `@field(x, name)` | depends | Dynamic field access |
| `@type_args(T)` | `type[]` | Generic args ; `MutableMap[i32, string]` → `[i32, string]` |

**Derived** (in stdlib, written in Vader) :
- `is_struct(T)`, `is_enum(T)`, `is_union(T)`, ... — wrappers over
  `@type_kind`.
- Type equality `type_eq(T, U)` — direct comparison on `type` values.
- Field search by predicate — `@comptime for` over `@fields`.
- `@derive(Eq)`, `@derive(Display)`, etc. — user-writable now,
  not compiler-magic.

### Open after Layer 6

§8 questions still unanswered :
- **Q5, Q6** — trait/`where` as comptime predicates. Next layer.
- **Q8** — comptime evaluation budget.
- **Q10** — hygienic macros vs `@comptime for`-only.
- **Q11** — migration phasing.

---

## 13. Layer 7 — traits & `where` (Q5, Q6)

> Decisions from the same 2026-05-09 session, continuing §12. Note :
> the surface form here uses the bracketed `[T: Bound]` syntax chosen
> in §11 Layer 5a (revised) — `$T` does not exist in Path 2.

### 7a — `trait` stays declarative ; bounds are comptime predicates

A `trait` declaration bundles three things :
1. An **obligation** — « T must support these methods with these
   signatures ».
2. A **method namespace** — when `T: Foo` holds, `x.foo()` resolves.
3. Optionally, **default impls**.

Of these, (1) is exactly a comptime predicate on `T`. (2) and (3)
remain attached to the `trait` declaration as organisation. Therefore :
- `trait` stays a declarable concept (sugar, namespace, defaults).
- `T: Foo` is sugar for a comptime predicate the typechecker
  evaluates.
- No new sub-system — bounds are predicates, predicates are comptime
  fns returning `bool`.

### 7b — Bound surface : inline in `[]`, composed with `&`

Bounds attach to the type-param at declaration site. `&` composes
constraints (intersection of satisfaction sets — same operator as
Vader's existing type-intersection) :

```vader
sum :: fn[T: Numeric](arr: T[]) -> T = arr.fold(T.zero, +)

fast_sum :: fn[T: Add & Zero](arr: T[]) -> T { ... }

zip :: fn[T: Eq, U: Eq](a: T[], b: U[]) -> Pair[T, U][] { ... }

MutableMap :: struct[K: Hash & Eq, V] {
    buckets: (Entry[K, V] | null)[]
    size: usize
}
```

### 7c — Composition primitives : `trait Foo = A & B`

Two declaration shapes :

```vader
// Pure alias — Foo is just shorthand for the conjunction
trait Numeric[T] = Add & Sub & Mul & Zero
trait Hashable[T] = Hash & Eq

// Trait with own methods that also requires others
trait Numeric[T] : Add & Sub & Mul & Zero {
    fn sign(self: T) -> i8
}
```

Both desugar to a comptime predicate. The pure-alias form is just a
fn returning `bool`. The with-methods form additionally registers a
method-set in the typechecker. Composition is unbounded — a trait can
require a previously-composed trait, etc.

### 7d — `where` : escape hatch for non-trait predicates

`where` keeps its place but its role narrows : it carries comptime
predicates that don't fit the `T: Bound` pattern. Typically size /
alignment / kind constraints, or predicates relating multiple params :

```vader
fast :: fn[T: Numeric](arr: T[]) -> T
    where @size_of(T) <= 64
{ ... }

is_pod :: fn[T]() -> bool = @type_kind(T) == TypeKind.struct and ...

fast_copy :: fn[T](src: T[], dst: T[])
    where is_pod(T)
{ ... }
```

Combined surface : trait bounds inline in `[]`, complex predicates in
`where`. Most signatures will not need `where` at all.

### 7e — Desugar : `T: Foo` → `@satisfies(T, Foo)`

The compiler translates the bound surface into a uniform comptime
predicate evaluation. Conceptually :

```vader
fn[T: Numeric](arr: T[]) -> T
// is internally :
fn[T](arr: T[]) -> T where @satisfies(T, Numeric)
```

`@satisfies(T, Trait)` is the intrinsic that, at comptime :
1. For each method required by `Trait`, verifies T provides one with
   matching signature.
2. Returns `true`/`false`.

The typechecker, in addition to enforcing the predicate, registers the
trait's method-set — so inside the body, `x.foo()` (with `x: T`)
resolves through the trait obligation. This dual role is local to the
typechecker, not a separate semantic category.

### Decisions table

| # | Decision | Closes §8 |
|---|---|---|
| 7a | `trait` stays declarative ; bounds are comptime predicates | Q6 |
| 7b | Bounds attach to type-params in `[T: Bound]` ; `&` composes | Q5 |
| 7c | `trait Foo[T] = A & B` (alias) and `trait Foo[T] : A & B { ... }` (with methods) | — |
| 7d | `where` reserved for non-trait predicates and multi-param relations | Q5 |
| 7e | All bounds desugar to `@satisfies` comptime check | — |

### Open after Layer 7

§8 questions still unanswered :
- **Q8** — comptime evaluation budget.
- **Q10** — hygienic macros vs `@comptime for`-only.
- **Q11** — migration phasing (still : Path 2 big-bang vs Path 3
  incremental).

Fresh sub-question raised by the bracketed surface : **impl &
coherence** (next layer). How does `impl Trait for Type` look ?
Orphan rules ? Default impl resolution ? Resolution order when
multiple impls match ?

---

## 14. Layer 8 — impl & coherence

> Decisions from the same 2026-05-09 session, continuing §13.

### 8a — `Type implements Trait[Args]` keeps Vader's existing form

Vader already has `Type implements Trait(Args)`. Path 2 keeps the
exact form, only migrating `()` to `[]` in line with §11 Layer 5a :

```vader
// Today (pre-Path 2) :
StringChars implements Iterator(char)

// Path 2 :
StringChars implements Iterator[char]
```

Natural reading order — « the type implements the trait » — preserved.
No Rust-style `impl Trait for Type { ... }` block.

### 8b — Methods are inherent ; `implements` verifies at declaration

`implements` is **not** a block. Methods live inherently on the type ;
the `implements` line is a declarative conformance assertion the
compiler verifies :

```vader
type Vec3 = struct { x: f32, y: f32, z: f32 }

fn add(self: Vec3, other: Vec3) -> Vec3 = ...
fn zero() -> Vec3 = ...
fn dot(self: Vec3, other: Vec3) -> f32 = ...

Vec3 implements Add
Vec3 implements Zero
Vec3 implements Numeric
```

At each `implements` line, the compiler checks the type provides every
required method with matching signature. Missing or mismatched
methods → error localised at the `implements` line.

Three consequences :
- **Mutualised methods** — one `add` definition can satisfy any number
  of traits whose requirement matches.
- **No impl duplication** — single method namespace per type.
- **Localised errors** — conformance verified once, at declaration.

### 8c — Explicit conformance, no structural inference

Without `Vec3 implements Add`, the type does **not** satisfy an `Add`
bound, even if structurally it has a matching `add`. Intent is
declared, not guessed. Kills the « accidental satisfaction » failure
mode of pure structural matching :

```vader
sum :: fn[T: Add](arr: T[]) -> T = ...
sum(my_vec3_array)   // ERROR if `Vec3 implements Add` is absent
```

### 8d — Default methods inject as inherent at `implements` site

Trait defaults synthesise inherent methods on the type when the
`implements` line is processed :

```vader
trait Eq[T] {
    fn equals(self: T, other: T) -> bool
    fn not_equals(self: T, other: T) -> bool = !self.equals(other)
}

type Vec3 = ...
fn equals(self: Vec3, other: Vec3) -> bool = ...

Vec3 implements Eq
// `v.not_equals(w)` valid after this line — synthesised from default
```

Override : declare an inherent method with the same name before
`implements`. The user-provided method shadows the default.

### 8e — Orphan rule (light) : own `Type` or own `Trait`

`Type implements Trait[Args]` is legal only in the module that owns
`Type` or the module that owns `Trait`. Third-party impls — where
neither side is owned — are forbidden.

Sufficient to prevent :
- Multiple conflicting impls from different modules.
- Surprise impls appearing through transitive imports.

Rust's blanket-impl coherence is more elaborate ; not needed for
Path 2.

### 8f — Method conflict resolution

If two traits both require a method `foo` :
- **Same signature** → no conflict. One inherent method satisfies
  both. This mutualisation is a feature.
- **Different signatures** → genuine conflict. The type cannot
  satisfy both simultaneously. Error at the second `implements`.

Precedence : inherent methods always win over synthesised defaults —
the user explicitly overrode.

### 8g — No dyn dispatch in Path 2

Trait objects (`dyn Trait` à la Rust) are deferred. Vader's tagged
unions (`A | B | C`) cover the closed-set runtime polymorphism case ;
open-set dyn dispatch is added later if real demand surfaces.

### Decisions table

| # | Decision |
|---|---|
| 8a | `Type implements Trait[Args]` (existing Vader form, `()` → `[]`) |
| 8b | Methods inherent on type ; `implements` verifies at declaration |
| 8c | Explicit conformance required ; no structural inference |
| 8d | Defaults inject as inherent methods at `implements` site |
| 8e | Orphan rule (light) — own Type or own Trait |
| 8f | Same-signature method satisfies multiple traits ; mutualisation |
| 8g | No dyn dispatch in Path 2 ; tagged unions cover closed-set case |

### Open after Layer 8

§8 questions still unanswered :
- **Q8** — comptime evaluation budget.
- **Q10** — hygienic macros vs `@comptime for`-only.
- **Q11** — migration phasing (Path 2 big-bang vs Path 3 incremental).

---

## 15. Closing — §8 remaining open questions

> Decisions from the same 2026-05-09 session, closing the §8 list.

### Q8 — Comptime evaluation budget

Instruction-count budget on the comptime VM, default 1M instructions
per comptime fn, overridable via `@eval_budget(N)` annotation on a
fn or block.

Why instruction-count over wall-clock : deterministic, reproducible
across machines, stable for tests and CI. Wall-clock is non-portable.

Default 1M is generous — enough for `@derive` over structs with ~50
fields, deeply recursive type generators, etc. Cases that need more
raise the budget locally :

```vader
@eval_budget(10_000_000)
big_derive :: fn[T]() -> impl_block { ... }
```

Error at exhaustion is explicit : « comptime budget exhausted in fn
`derive_eq` after 1000000 instructions ; raise via `@eval_budget(N)` ».

### Q10 — No hygienic macros ; structured comptime values instead

No AST-level macros in Path 2. Reflection + comptime + structured
comptime values cover the realistic cases (`@derive`, serialisation,
hashing, pretty-printing).

Mechanism : a builtin `impl_block` comptime value type. A fn returning
`impl_block` is integrated by the compiler as if it were a textual
`Type implements Trait { ... }` declaration :

```vader
@derive(Eq)
type Vec3 = struct { x: f32, y: f32, z: f32 }
```

Desugars to :

```vader
Eq_for_Vec3 :: fn() -> impl_block {
    return impl_block[Vec3] {
        @comptime for f in @fields(Vec3) {
            // synthesise per-field equality
        }
    }
}
```

No AST manipulation — just comptime evaluation producing a structured
value the compiler accepts. Stays clean. True hygienic macros, if
ever needed, are an additive feature beyond Path 2.

### Q11 — Work directly on `main`

No dedicated branch. Vader has no external users yet ; leaving `main`
intermediate during migration costs nothing. Branching adds overhead
(rebase load, double test infra, merge friction) without benefit in
this context.

Concrete ordering — each step makes the next evaluable in isolation :
1. Fuse `Expr` / `TypeExpr` AST (Layer 3) — foundation.
2. `type` builtin + reflection intrinsics (Layers 1-2).
3. Comptime engine extended for type-as-value (Layer 4).
4. Migrate surface syntax to `[]` (Layers 4-sugar, 5a).
5. Desugar traits to `@satisfies` (Layers 7-8).
6. Migrate stdlib + tests + snapshots.

If a step stalls, fallback is Path 3 (parallel infrastructure) — but
it's not the first-order strategy.

### §8 — final state

All §8 open questions are now closed :

| § | Question | Closing layer |
|---|---|---|
| Q1 | Type representation (erased / carried) | Layer 1, 2 |
| Q2 | Runtime representation of `type` | Layer 2 |
| Q3 | `$T` sugar vs explicit | Layer 4-sugar (revised) — `[T: Bound]` instead |
| Q4 | Explicit type-args at call sites | Layer 5a |
| Q5 | Trait bounds form | Layer 7 |
| Q6 | Traits as special concept vs predicates | Layer 7 |
| Q7 | Comptime / runtime boundary | Layer 5b |
| Q8 | Comptime budget | Layer 9 (this section) |
| Q9 | Reflection scope | Layer 6 |
| Q10 | Macros vs `@comptime for` only | Layer 9 (this section) |
| Q11 | Migration phasing | Layer 9 (this section) |
| Q12 | Where mono lives | Layer 2 |

The Path 2 design is now specified end-to-end in §11–15. From here,
implementation can begin against the ordering listed in Q11.

---

*Last updated 2026-05-09. §11–15 added during the design session
exploring full type-first ; §8 fully closed. §11 Layer 4-sugar and
5a revised when the bracketed `[T: Bound]` surface was chosen over
the `$T` + `where` form.*
