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

*Last updated 2026-05-09. Update this when the conversation resumes.*
