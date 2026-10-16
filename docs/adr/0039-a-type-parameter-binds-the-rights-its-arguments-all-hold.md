# 0039 — A type parameter binds the rights its arguments all hold

## Status

Accepted (2026-10-07).

## Context

A call infers its type parameters from its arguments, and `T` binds an argument
with its rights. When several arguments bound the same `T`, the first one kept it,
so the order of the arguments decided what `T` could mutate:

- `pick :: fn<T>(a: T, b: T) -> T`. `pick(local, CFG)` bound `T = Cfg!` and handed
  the module const back as mutable. A field write through the result reached
  `.rodata`: SIGBUS natively, and the VM wrote the const. `pick(CFG, local)` was
  refused (T3070).
- `apply :: fn<T>(f: fn(T) -> void, x: T)`. `apply(bump, CFG)` took `T = Cfg!`
  from `bump`, which then wrote into `CFG`. `apply(CFG, bump)` was refused (T3001).
- An array's bit is part of its type, so there the order gave a false refusal:
  `pick(got, LIST)` was T3001 and `pick(LIST, got)` was accepted.

Each argument was already checked against the final bindings, once every argument
had been unified. Only the binding depended on the order.

## Decision

**Arguments that bind one `T` to the same type at different rights bind it to the
rights they all hold, level by level.** `least_permissive` makes an array, struct,
tuple or trait level read-only when either binding has it read-only. It goes
through type arguments, tuple elements, a distinct's backing and union variants.

- **Bindings that differ by more than their rights** have no common binding. The
  first one stands, and the argument check reports the mismatch, as before.
- **A fn type is not lowered.** Its parameters take rights the other way round,
  so the first binding's fn type stands, and the argument check judges the
  other one against it. (0040 replaces this: a fn type takes the bound with its
  parameters reversed.)

Every argument is then checked against that binding. An argument that must keep
an array's rights is refused whichever order it comes in. For example,
`put(rows, LIST)` with `rows: i32[]![]!` against `dst: T[]!` is T3001. A
struct, tuple or trait value's own bit is not compared there: T3072 reads it
only for a parameter marked `!`. Under a lowered binding no argument has fewer
rights than `T`, so that gap stays closed for inferred bindings, but not for a
written one (see Still open).

Three sources bind a `T` without lowering its rights:

- **An explicit type argument** is a written type, so it is `held`.
  `pick<i32[]!>(got, LIST)` stays T3001 at `LIST`.
- **The slot the result flows into** still only fills a `T` that no argument
  bound, or tightens a free literal. Lowering an argument's binding to the slot's
  rights would refuse `x: i32[] = first_of(rows)`, with `rows: i32[]![]!` passed
  to `rows: T[]!`.
- **A fn type's parameters** say what the fn accepts, not what an argument holds.
  `pts.find((p) -> p.y > 14)` binds `T` to the elements' `Point!`, and the
  lambda's read-only `p` leaves it there, so `find` still hands back a
  `Point!`. A first rule that lowered there turned that result read-only.

The last two pass `lowers_rights = false` to the unification.

The lowerer's own unification is unchanged. It keeps the first binding to pick
the instance, and an instance's code does not depend on rights. The snippet
`type_param_bound_by_constant_and_local` runs such a call in the VM and natively.

## Consequences

Measured on 2026-10-07, at `1a5bf59e2`:

- **On 848 programs**, `check` reports exactly what it did before, and the
  typed AST, every expression's type included, is identical.
- **The compiler and `lib/`** needed no change.
- **The two leaks are refused** whichever order the arguments come in.
- **The array false refusal is gone.** `pick(got, LIST)` is accepted, as
  `pick(LIST, got)` was, and both hand back a read-only `i32[]`.
- **Typecheck time** is unchanged (release builds, minima 493.0 against
  492.8 ms).

Still open. The first three leaked, as they did before this change; 0040 closes
them, and leaves the UFCS order as a false refusal:

- **A UFCS call** binds `T` from its receiver alone and checks the other
  arguments against the substituted signature, without the generic path.
  `local.pick(CFG)` hands back a mutable `CFG`, and `got.pick(LIST)` is T3001
  where `LIST.pick(got)` is accepted.
- **An explicit type argument over a struct** is held but not enforced:
  `pick<Cfg!>(local, CFG)` accepts the read-only `CFG`, for the reason above.
  An array (`pick<i32[]!>(got, LIST)`) is refused.
- **A join of branches or elements** keeps the less permissive of two equal
  variants at their top level only (`collect_variant`). Over a `Box<Cfg>` and a
  `Box<Cfg!>`, both `if c { b1 } else { b2 }` and `[b1, b2]` hold a
  `Box<Cfg!>`.

- **A fn's parameter that binds `T` first** still sets the binding, and a later
  argument lowers it from there. Take `fn<T>(keep: fn(T) -> bool, x: T) -> T`
  with a lambda over a read-only `p`, called with a mutable `x`. It hands back a
  read-only value, as before, where `T` could have kept `x`'s rights. Telling a
  fn parameter's binding from an argument's would take a second record per `T`.
- **Two fn types bound at different rights**, on a parameter or on the return,
  kept the first binding. The order could turn a call into a false refusal
  there (`pick(make_mutable, get_const)` was T3077, the reverse accepted), but
  not a leak, since the argument check compares fn types strictly. 0040 closes
  it.
