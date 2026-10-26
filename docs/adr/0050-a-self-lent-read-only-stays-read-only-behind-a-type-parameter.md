# 0050: A `Self` lent read-only stays read-only behind a type parameter

## Status

Accepted (2026-10-08). Closes the hole 0049 left open.

**Superseded by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: a type carries no rights any more.

## Context

A type parameter carried no rights of its own. `with_immutable(T, _)` changed
nothing, and a `T` was mutable wherever its bound was marked (`T: Bump!`). Only some
bindings froze it: a fn parameter without `!`, and a local copied from one.

So a `Self` that a trait member lends read-only became mutable once a `T` stood for
it. At `995a7fc57`, `check` accepted each of the following under `T: Visit & Bump!`
when the impl hands out a module const:

- **a callback:** `t.visit((x) -> x.bump())`;
- **a `-> Self` return:** `t.get().bump()` and `t.clone().bump()`. The same calls on
  a concrete receiver are refused;
- **a generic return:** `build :: fn<S: Shape>(n: i32) -> S = S.unit(n)`, which
  hands the read-only result back at the caller's rights;
- **storage:** `xs.push(t.get())` into a `T[]!` that the caller holds mutable.

Natively, each wrote into `.rodata` and died with SIGBUS. Separately, a lambda
parameter `(y: T) -> y.bump()` was accepted where `fn(y: T)` is refused.

**First direction measured, then rejected.** It gave every written type parameter the
read-only default of other types: `T` read-only, `T!` at the rights of what it stands
for. It closed every hole, but it changed the meaning of all generic code:

- a user-written `identity :: fn<X>(x: X) -> X` handed back `Cfg` for a `Cfg!`;
- the standard library needed `!` on nearly every type parameter, as
  `MutableMap<K!, V!>`, `Iterator<T!>!` and `fn(T!) -> U!`, in 51 of its 83 generic
  functions;
- the compiler tree failed on 76 sites on the first round.

Inferring `!` will settle what a generic does with its `T`.

## Decision

**A written `T` keeps the rights of what it stands for. A `Self` lent read-only becomes
a read-only *view* of the `T` that stands for it.**

- **The view.** `TypeParamType.immutable` marks it, and only `Self` substitution
  produces it:
  - `self_slot_type` substitutes a type parameter's `Self` as the view, and only a
    written `Self!` lifts it (`type_param_default`);
  - in a fn type, `fn(Self)` lends the view and `fn(Self!)` the `T` (`substitute_self`).

  `with_immutable` leaves a type parameter alone, as before. That keeps a written or
  inferred `T` transparent. Substituting `T := Cfg!` turns the view into `Cfg`
  (`instance_of`).
- **Where the view holds.** It survives a join (`bound_rights`: `if`, `match`,
  literals, the binding of a `T`) and an `is T` narrowing (`narrowed_with_rights`).
- **What refuses the view.** No `self!` member takes it (T3071), and no `!`
  parameter (T3072). A slot of the same `T`, which stands at its instance's rights,
  refuses it too (`mutability_widens`, `lends_view`), whatever the bound. So
  `build` above is T3077, and `xs.push(t.get())` is T3072.
- **Constructors.** A member whose caller owns what it returns writes `-> Self!`. In
  std this is `Clone.clone`, `Step.step`, `Zero.zero` and `One.one`.
- **Lambda parameters.** A lambda parameter not written `!` is a read-only borrow,
  as a fn's is (`mark_param_borrow`).
- **Storing an argument.** A non-view argument goes into a `T` slot unchecked unless
  the body can mutate through that `T` (`slot_may_grant_mutation`). Under an unmarked
  bound nothing can mutate it there, so `MutableMap.put` keeps its read-only key.
- **T3075 and substitution.** T3075 skips a `!` whose inner type was written
  elsewhere (`written_inside`). Substitution puts the type a `Self!` or `T!` stands
  for under the marker, so `i8 implements Step -> self + 1` reads `-> i8!`. The marker
  itself stays, since on a parameter it is the "may mutate" contract.
- **Display.** Diagnostics show the view as `readonly T`; it has no surface spelling.

## Consequences

Measured on 2026-10-08 against `995a7fc57`:

- **The compiler tree needs no edit. On 848 programs, one diagnostic message changes:**
  `t3017_bounded_comparison_free_literal` now reads "expects `readonly T`".
- **Two snippets now write `-> Self!` on their constructors**:
  `trait_static_member` and `several_impls_of_one_trait`. Their generics returned the
  constructed value at the caller's rights.
- **User impls of `Clone`, `Step`, `Zero` and `One` on a struct must return the type
  marked.** `zero :: fn() -> Money` is T3095.
- **An unannotated lambda parameter filling a `fn(U!)` slot is read-only**, as on a
  concrete type.
- **The behaviour probes and the reviewers' probes:**
  - 149 behaviour probes, which run `check`, then build and run each program, give
    the same results as before;
  - of the 141 probes from the review, every `.rodata` write is refused except the
    two families listed below.
- **The seed needs regenerating, in a commit of its own.** The committed seed rejects
  `-> Self!` on primitives with T3075.

Still open:

- **Operators.** Under `T: Add & Bump!`, `(a + b).bump()` writes `.rodata` when an
  impl returns a frozen value: the `Out = Self` default reaches a `T` transparent.
  Closing it means `Out = Self!` in std, so roughly fifteen struct operator impls
  would return their type marked.
- **A call on a `T` receiver binds the enclosing `T` from its arguments.** It
  predates this change. Under `T: Visit & Bump!`, `t.visit((y: T!) -> y.bump())`
  passes, and `t.visit((y: string) -> …)` reports T3006 for `string`. That `T` should
  be rigid at the call.
- **A borrowed `x: T` stored without a call** escapes the store rule:
  `xs[0] = x`, `h.v = x`, `[x]`, `Holder { .v = x }`. The concrete twins are
  refused. A `T: Bump!` bound keeps frozen values out, so this breaks the borrow
  contract without reaching `.rodata`.
- **The method form on a trait value** keeps the hazards 0047 lists.
