# 0052 — An annotated local's `!` is deduced too

## Status

Accepted (2026-10-09). Extends ADR 0051.

**Superseded by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: a type carries no rights any more.

## Context

An unannotated local is owned: `out :: [s]` then `out.push(x)` needs no `!`. An
annotated local is a written slot, read-only unless marked, so an accumulator whose
initializer cannot give its type had to be written `out: Stmt[]!: []`. The
annotation then said two things at once: the shape, which `[]` cannot say, and the
rights, which the body already says.

At `6244ec385`, about 280 annotated locals of `vader/` and `lib/` wrote a `!`, 217 of
them on an empty literal.

## Decision

**An annotated local takes `!` at a level when the body mutates it there, or hands
it at that level to a slot that takes `!`.** The annotation gives the shape; the
rights are deduced, in the same rounds as the parameters' (ADR 0051).

### One mechanism for both

The deduction's unit is a **slot**: a parameter or an annotated local, whose written
type it reads and rewrites (`InferableSlot`, `owner: FnParam | LetStmt`). Needs,
edges, closure, W0017 / W0018, `vader fix`, the inlay hint and the hover are shared.

- **Registration:** a local is registered when the first round reaches its binding,
  before its annotation is typed, and its written `!` come off then. The same
  moment strips a local fn's parameters, which ADR 0051 left written.
- **Lever:** a deduced slot is its own lever, whatever it was bound to.
- **Edges into a local:** the value that fills a local — its initializer, or a value
  assigned to it — is tied to it as an argument to its parameter. When the local is
  marked, the value's lever is too, in the same round.
- **What a local stands for:** a local bound to a single name records the value it
  was bound to, whatever its rights (`local_bound_to`), so a lever walk follows it
  back — a slice (`s :: xs[0..<n]`) as a view of `xs`, an element as an element.
- **A fresh literal's own level** is no root's: `[f]` with `f` an element of `files`
  stands for `files`' levels below the literal's, never for its spine (`floor`).
- **A destructuring** `[x, y] = [p, q]` ties each target to the element that fills it,
  as an assignment does.
- **A union variant** carries a mark only to a value that fills it: a callee's
  `i32[] | string[]` marked at `i32[]` asks nothing of a `string[]` argument.

### Printing

A marker the compiler inserted is flagged `deduced` on the `MutableTypeExpr`, and
`vader/fmt`'s printer leaves it out; a written marker put back after the first round
is not flagged. A tool that prints a typed body — the LSP's rewrite actions do —
prints the source's markers only. Signature help shows the deduced ones: they are
the contract a caller meets.

### Warnings

W0017 and W0018 cover a local's written `!` with the same meaning; W0018's message
reads "this value" instead of "this parameter".

## Consequences

Measured on 2026-10-09 against `6244ec385`, on the self-check:

- `vader fix` removes 1 481 `!` from the compiler tree, plus about 90 from other
  entry points (bootstrap, `lib/` libraries, `@target` bodies, benchmarks,
  examples). Built twice from the fixed tree, stage 1 and stage 2 emit the same C.
- **Typecheck time** goes from about 1 140 ms to about 1 160 ms; still two rounds.

### Stores through a type parameter

A first version took three rounds. Three locals were filled by
`out.push_all(xs)` and then returned as `T![]`: the return marks `out`'s element
in round 1, and `push_all :: fn(self!, other: T[])` then binds `T` to that
element, so `xs`'s elements must grant mutation too — which only round 2's
refusal found.

On an array, a member's `T` is bound by the receiver alone: every `T` of its
signature becomes the receiver's element. A parameter that is `T` under k arrays
therefore stores the argument's levels k down into the receiver's element, and an
edge records it. That edge is read from the member's declared signature, not from
the shape of the substituted one. At k = 0, only a parameter that grants mutation
demands the element's rights, as `push`'s `value: T!`.

Nine diagnostic fixtures used an annotated local's written `!` as the slot that
demanded mutation; once deduced, nothing demanded it. They now mutate through the
local, so the `!` is demanded by the body.

Still open:

- **Type-parameter coupling beyond an array's members.** A generic fn whose `T` is
  bound by several arguments under a mutable level (`fn<T>(dst: T[]!, src: T[])`)
  links their rights, and so does an argument with another: no edge carries it,
  and a round finds it. A deduced callee's invariance is itself a mark, so the edge
  would have to wait for it.
- **The rounds re-check everything.** Re-checking only the functions a new mark
  reaches would make the extra rounds cheap.
- A written `!` that only a later round would find needed — a value filling a
  trait variant of a union — earns W0018. Removing it is safe: the deduction finds
  the need from the refusal.
- **A mark on one variant of a union reads as the whole union's** in the checker:
  a parameter written `i32[]! | string[]` is held as `i32[]! | string[]!`, so a
  read-only `string[]` handed to it is refused. This predates the deduction, which
  now marks one variant and meets that rule.
- A fn whose body is cloned per impl (a trait's default member) registers its locals
  once per clone, and its warnings repeat per clone.
