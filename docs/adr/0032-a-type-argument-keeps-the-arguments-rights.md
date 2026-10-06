# 0032 — A type argument keeps the argument's rights

## Status

Accepted (2026-10-06). Resolves the `unify_type_param` item that 0017 left open;
amends 0022, whose generic paragraph assumed the erasure. The nominal-argument item
left open below is resolved by 0033.

## Context

`unify_type_param` bound a type parameter to its argument with the read-only bit
cleared — `with_immutable(arg, false)`, the MAXIMAL rights — so that a generic
instantiated from a borrow and from a local would not become two types. Every
gate that judged a substituted parameter then had to undo the claim:
`substituted_element_fiction` cleared the element bits on both sides of the
argument check, and `align_callback_bits` copied a callback's own bits back into
the positions the callee wrote as a bare `T`.

What was left over was wrong in both directions:

- **Refused**: a read-only value into a bare `T`. `show<T>(v: T)` called with a
  read-only `Point` was T3077 — the substituted slot read `Point!`.
- **Invented**: whatever came back claimed mutation the argument never had.
  `peek<T>(xs: T[]) -> T` over a module-const array handed out a `Point!`, so
  `bump(peek(TABLE))` wrote into `.rodata`; `wrap(ORIGIN).v` the same. And
  `xs.map(f).collect()` returned `X![]!` even when `f` returned read-only values —
  which, once element rights became invariant through a mutable array, refused it
  into any `X[]!` slot.

0017 had measured normalising to read-only instead: no better, since a factory's
product (`filled(3, () -> [])`) silently lost its rights. Both directions fail
because erasing at all does.

## Decision

Bind the argument as it is, rights included. A fn type rebuilt from one whose
parameter was written as a bare `T` relays the bound rights into
`params_mutable` (`mk_fn_like`), so `fn(T)` bound to `Cfg!` is a fn that may
mutate its argument. `Self` is not relayed: `substitute_self` puts the impl's type
there with no rights of its own, so a `fn(Self)` callback stays read-only.

The fear behind the erasure does not materialise. `equals_type` leaves the
struct / tuple bit out of identity, so two `Cfg` remain one type; it does keep an
array's bit, but an instance is keyed by `display_type_key`, which drops every
marker — `T := i32[]` and `T := i32[]!` share one instance.

## Consequences

Measured on 2026-10-06, after the `.rodata` fixes of `98a0464d4`:

- the compiler's emitted C is identical byte for byte with and without the
  change;
- with the binding in place, `check` gives the same diagnostics on 825 programs
  (every snippet, every diagnostic fixture, the examples, the benchmarks and the
  tools) with and without the two compensations — they were only undoing the
  erasure, and they are gone;
- 20 snippet snapshots moved, `typecheck` and `lower` only, every changed line
  identical but for its `!` markers (418 → 126): generic results no longer claim
  rights their sources lacked. No `vm`, `bytecode` or C snapshot moved.

`show(p)` on a read-only `p` is accepted; `bump(peek(TABLE))` and
`bump(wrap(ORIGIN).v)` are T3072; `kept.map(f).collect()` fills a `X[]!` again
when `f` hands out read-only values.

Binding the result slot's rights exposed an older hole: an expression-bodied
lambda's trailing value was never checked for rights, so
`x: Cfg! = make(() -> ORIGIN)` wrote into `.rodata`. It is now held to the promised
return type as a named fn's is.

Still open:

- the first argument to bind `T` wins, so `assert_eq(got, EXPECTED)` is refused
  where `assert_eq(EXPECTED, got)` passes. Nothing leaks — every later argument is
  checked against the binding — but binding to the fewest rights among the
  covariant occurrences would make the order irrelevant;
- **resolved by 0033** — the argument path clears the bits inside a NOMINAL type
  argument (`arg_mutability_cleared`), so `gen_mut(h: Holder<Box!>)` accepts a
  `Holder<Box>` — the invariance of a type argument under a mutable struct is the
  same question as element invariance under a mutable array, and has not been
  measured yet.
