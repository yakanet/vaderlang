# Error & null handling — values, narrowing, and combinators

**Status:** DESIGN (2026-07-13), pre-implementation. Decided direction, open
sub-decisions flagged below. Supersedes the `?` (try) operator.

**Origin:** the error/null strategy was left explicitly *undecided* during the
async design (memory `project_async_concurrency_design`: "PAS de trait `Try`,
PAS de `?`, la simplification erreur/null reste un sujet ouvert"). This doc
settles it.

---

## 1. The model

Errors and null are **ordinary values in a union** — `T | SomeError`,
`T | null`. There are no exceptions, no `throw`/`catch`, no `Try` trait. Two
mechanisms handle them, split by *what they are*:

- **Control flow** (branch, early-return, exhaust) → **narrowing** with plain
  `if` / `match`. This already exists and covers both null and error uniformly
  (`if x == null`, `if x is Error as e`). It is the only thing that can
  *early-return* the bad case, because that is a control-flow effect no function
  call can perform on behalf of its caller.
- **Value handling** (default, transform, chain) → **stdlib combinators** called
  through UFCS on the union. These are ordinary generic free functions — no
  compiler magic, no new syntax, fully extensible in the library.

This removes the `?` operator (§4): its two jobs — *propagate* and *unwrap* —
split cleanly into narrowing (propagate) and combinators (unwrap/default).

### Why this is the Vader-native shape

- **Lightweight:** no operator, no keyword, no trait baked into the compiler.
  Value handling lives entirely in the stdlib.
- **Extensible:** combinators are free functions on unions; the stdlib ships a
  set, any module adds more. Contrast the current `?`, which is hard-coded to
  the `Error` trait in the typechecker (`expr_try.vader::is_error_like`) and
  cannot be extended or reused for null / user types.
- **Orthogonal:** one control-flow mechanism (narrowing) for every union;
  handling is just functions.

Proven to work today (VM + native) — the combinators dispatch through UFCS on
structural unions exactly like `sb.append()` / `arr.len()`:

```vader
maybe(true).or(0)            // 7        — method on `i32 | null`
risky(false).or(-1)          // -1       — same `or`, method on `i32 | Error`
```

---

## 2. The combinator vocabulary

Each combinator is a generic free function whose first parameter is the union
(so UFCS makes it a method) and whose *bad* type is **concrete** (`null`, or the
`Error` trait) so `T` is inferred from the rest of the union. Overload resolution
by receiver (shipped — see §"The naming decision") lets `or` / `or_else` carry
the same name across both nullable and fallible receivers.

```vader
// shared name, dispatched by receiver ("value, or the fallback")
or        :: fn<T>(x: T | null,  d: T) -> T                      // null    → d
or        :: fn<T>(x: T | Error, d: T) -> T                      // error   → d
or_else   :: fn<T>(x: T | null,  f: fn() -> T) -> T              // lazy, null
or_else   :: fn<T>(x: T | Error, f: fn(Error) -> T) -> T          // lazy, sees the error

// fallible-only ("failure")
map       :: fn<T, U>(x: T | Error, f: fn(T) -> U) -> U | Error          // transform ok
and_then  :: fn<T, U>(x: T | Error, f: fn(T) -> U | Error) -> U | Error  // chain
unwrap    :: fn<T>(x: T | Error) -> T                            // value, or panic
expect    :: fn<T>(x: T | Error, msg: string) -> T               // value, or panic(msg)
```

The set is deliberately small and additive — grow later as real code asks for it
(e.g. a nullable `map` / `unwrap` if wanted).

### The naming decision — RESOLVED

Vader unions are **structural**. Overload resolution now ranks candidates by
**receiver specificity** (`overload_specificity`, at the typer + lowerer UFCS
sites), so two same-name free fns distinguished by a concrete union member
(`x: T | null` vs `x: T | Error`) dispatch by the receiver's shape — `or` / `or_else`
read the same whether the value is nullable or fallible. (Nominal `Option` /
`Result` types were rejected — they'd abandon the "errors are values in a union"
model.)

### Multi-variant "unhappy" unions — `T | Error | null` (Strategy A)

A combinator handles ONE unhappy axis. A union carrying **both** `null` **and** an
`Error` (`T | Error | null`) fits neither the `T | null` nor the `T | Error`
overload, so `x.or(d)` is a **compile error** (T3008, with a message that points
here) — not a silent leak. This is by design: prefer **one unhappy axis per
function** — `T | Error` (model "absent" as a `NotFound`-style error if the caller
must handle it) or `T | null` (if absence is unremarkable). When three outcomes
are genuinely distinct (cache: miss / corrupt / hit), handle it with explicit
`if`/`match` narrowing — the universal base mechanism combinators sit on top of.

---

## 3. Propagation without `?`

`?`'s propagation is a two-line narrowing pattern — explicit, and needed far less
often once combinators cover default/transform/chain:

```vader
// before (with `?`)                    // after (narrowing)
process :: fn() -> i32 | Error {         process :: fn() -> i32 | Error {
    x :: fallible()?                         r :: fallible()
    return x + 1                             if r is Error as e { return e }
}                                            return r + 1          // r : i32
                                         }
```

The lost affordance is inline propagation (`return f(g()?)`), which becomes a
statement. In practice propagation is already statement-shaped; the cost is one
extra binding + guard line, paid only when you genuinely re-raise (not when you
default/transform — that is a combinator).

If that verbosity proves annoying in real code, the orthogonal escape hatch is a
general **`else`-guarded binding** (`x :: expr else is Error as e { return e }`,
a `guard`/let-else that works for *any* union) — deferred; narrowing first.

---

## 4. Removing `?` — the cascade

`?` / `TryExpr` currently spans ~22 files. Removal (pre-MVP, no back-compat) —
each is a deletion or an exhaustive-match arm drop:

- **Lexer / parser:** the `?` postfix token + `TryExpr` (`parser/ast.vader`,
  `parser.vader`, `assign_ids.vader`, `dump.vader`).
- **Typecheck:** `expr_try.vader` (incl. the just-added **T3067** gate — it goes
  with the operator), the `TryExpr` arm in `expr.vader`, `stmt.vader`,
  `dead_code.vader`.
- **Lower:** `lower_try.vader`, the `TryExpr`/`LoweredTry` arms in
  `lower_expr.vader`, `closure_analysis.vader`.
- **Resolver / comptime / fmt / LSP:** the `TryExpr` arms in `resolver/body.vader`,
  `substitute_body.vader`, `comptime/{deps,eval}.vader`, `fmt/printer.vader`, and
  the six LSP walkers.
- **SPEC:** delete §"`?` operator (try)" (line ~1810) + the precedence-table row;
  document the combinator model instead.
- **Snippets to migrate:** `try_op`, `try_defer_drain` → rewrite to narrowing +
  combinators. The `try_defer_drain` case (defer must still run on the error
  path) becomes a plain `if is Error { return }` inside the `defer` scope — the
  defer-drain machinery (CR-e) is orthogonal and stays.

> **Note:** removing `?` undoes the dx-6 / T3067 work committed at `e8a69cc3`.
> That is expected — T3067 only existed to make `?` sound; no operator, no gate.

---

## 5. Phasing

> **Status (2026-07-13): Phases 1–3 DONE + `and_then` unblocked.** Combinators
> shipped in full (`std/option`, incl. `and_then`); all `?` usage migrated to
> narrowing (std/json, std/time, mowitnow); the `?` operator + its `TryExpr`
> cascade + T3011/T3012/T3067 removed. `?` is gone from the language.
>
> The union-position inference gap that had deferred `and_then` is FIXED (root
> cause: a block-body lambda ending in `return` typed its block as `never`, so a
> type param inside a `U | Error` return position never bound — the mangle lost
> it → GATE B1. Fix: `FnContext.inferred_return` accumulates the lambda's `return`
> value types; `pick_final_return` uses it when the block diverges). This also
> improves inference for any block-body lambda passed to a generic HOF.
>
> Remaining (optional): the multi-param `U | E` union split still needs explicit
> type args (`try_all<U, E>` / `any<U, E>`) — genuinely ambiguous, left as-is; and
> the overload-by-receiver follow-up (Phase 4) for same-name combinators.


Each phase ends green (`verify.sh` fixed point, fresh seed, full suite), reviewed
before landing.

1. **Combinators (additive, zero risk).** Add the stdlib combinator module
   (vocabulary from §2, option A). No language change. Snippets + colocated
   tests. `?` still works alongside — nothing removed yet.
2. **Migrate `?` users.** Rewrite `try_op` / `try_defer_drain` (and any stdlib
   `?` sites) to narrowing + combinators. Prove behavior-identical.
3. **Remove `?`.** Delete the operator + its cascade (§4), incl. T3067. SPEC
   updated. This is the one big-diff phase (exhaustive-match churn), but purely
   mechanical once nothing uses `?`.
4. **(Optional, later) Overload-by-receiver (option B).** If the null/error name
   asymmetry bites, add UFCS receiver-overload resolution and unify the names.

---

## 6. Decisions (resolved 2026-07-13)

1. **Naming scope → UNIFIED (option B shipped).** Started as (A) distinct names
   (`or` for null, `unwrap_or` for error), then shipped overload-by-receiver
   (§"The naming decision") and unified: `or` / `or_else` carry the same name
   across `T | null` and `T | Error`. `map` / `and_then` / `unwrap` / `expect`
   stay fallible-only.
2. **Module home → single `std/option`** (the planned `std/result` was folded in).
   Explicitly imported ; `std/core` stays minimal. The name follows the Option
   *concept* ; the representation is still structural `T | null` / `T | Error` —
   no nominal types.
3. **`?` removal → in this initiative (Phase 3).** Full removal incl. T3067,
   after the combinators ship and existing `?` sites migrate.
4. **Guarded binding (`else`/`guard`) → deferred.** Narrowing is the propagation
   form for now ; revisit only if real code finds it too verbose.

Remaining to settle during Phase 1 implementation (low-stakes): the exact
combinator starting set (§2) — grow additively as snippets ask for it.
