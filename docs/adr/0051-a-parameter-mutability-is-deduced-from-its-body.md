# 0051 — A parameter's `!` is deduced from its function's body

## Status

Accepted (2026-10-08).

**Superseded by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: a type carries no rights any more.

## Context

Before this change a parameter that its body mutates had to carry `!`:
`fill :: fn(buf: i32[]!, …)`. The marker is per level, so the author also had to
pick the level: `Box![]` for the elements, `Box[]!` for the spine, `Box![]!` for
both. An omission was an error in the callee, at the mutation, with a hint
pointing back at the parameter.

Two costs followed:

- **The author of a generic could not tell when to write `!`.** The answer
  depends on what the body does with the value, which the compiler already knows.
- **The markers drifted.** At `e613df8d0` the compiler tree and the standard library
  wrote 2 504 `!` on parameters of functions with a body. 758 of them were needed
  by nothing.

The mutability direction (plan P2) asked the compiler to deduce this marker and to
keep written markers for contracts only.

## Decision

**A parameter of a function with a body takes `!` at a level when the body mutates
it there, or hands it at that level to a parameter that takes `!`.** The compiler
deduces this over the whole project.

### What is deduced

- **Deduced:** typed parameters of free functions, local functions bound with
  `::`, impl members and generic functions.
- **Kept as written:** trait members, `fn(...)` types, `@extern` and intrinsic
  functions, and lambdas.
- **Levels:**
  - the parameter's type itself;
  - an array's element, recursively;
  - each variant of a union written `A | B`.
- **Not deduced:** a nominal type's arguments (`MutableMap<K, V!>`).

### Rounds (`param_inference.vader`, `check_project_with_bodies`)

The project is typechecked in rounds over the same loaded AST.

1. **Before round 1**, the `!` written on deduced levels are removed from the AST.
2. **During a round:**
   - a rights refusal whose lever is a deduced parameter becomes a **need**;
   - an argument rooted at a deduced parameter and passed to another becomes an
     **edge**.
3. **Between rounds**, the closure of the needs and the written `!` along the
   edges is written into the AST as `MutableTypeExpr` nodes.
4. **The first round that marks nothing new is the result.**

Each round restarts the symbol factory at the same id, so a symbol keeps its id
from one round to the next.

### Edges

- **When they are recorded:** only in round 1. Later rounds make the same calls.
- **Exactness:** an edge exists only when it is exact. The argument fills the
  parameter level for level and goes through no conversion. A missed edge costs
  one more round; it never costs a wrong mark.
- **Element invariance:** an array element is invariant under a spine the callee
  grows. The closure therefore aligns the callee's element with the argument's,
  whether the argument's type writes that `!` or its root's mark does.
- **Stores into an element:** an edge one level up connects the container's
  element to the stored value. This covers `xs[i] = v`, a `!` parameter typed as
  the receiver's element (`push`), and a parameter typed as that element under k
  arrays, whose argument's levels k down are what is stored (`push_all`, ADR 0052).
- **Through a field:** a field is as read-only as its struct and as its declared
  type. A refused value read through a field of a parameter is therefore a need on
  the parameter's own level only where the field's declared type does not withhold
  the level reached. It is never an edge: the field's own type may grant mutation
  whatever the parameter's level is.

### Written `!` and diagnostics

- **A written `!` is kept:** the marks are the written ones plus the deduced ones.
- **W0017** fires when the body demands the `!` anyway.
- **W0018** fires when nothing demands it. A `!` on a type with no interior gets
  T3075 instead, as before.
- **`vader fix`** removes both. Each warning's span is the `!` itself.
- **A refusal at the caller** (T3072, T3071, T3095) names the chain of calls down
  to the mutation.
- **The editor** shows a deduced `!` as an inlay hint, with the same chain on
  hover.

## Consequences

Measured on 2026-10-08 against `e613df8d0`, on the self-check (`vader check vader/tools/cli/main.vader`):

- **Two rounds**, whether the written markers are in place or removed.
- **The deduced marks are a subset of the written ones:** of the 2 504 written,
  1 746 are deduced and 758 are needed by nothing.
- **With every written parameter marker removed, the tree checks clean.**
- **`vader fix` and the bootstrap:** `vader fix` removes the 2 504 markers in 215
  files. Built from the fixed tree, stage 1 and stage 2 emit the same C. That C is
  byte-identical to the C of the tree with its markers.
- **Typecheck time** goes from about 560 ms to about 1 140 ms. The second round is
  a full typecheck; recording the edges in round 1 and closing them between rounds
  costs the rest.
- **A program that mutates no parameter and writes no `!` takes one round.**

A refusal moves from the callee, where the mutation is, to the caller that hands
in what cannot be mutated. The diagnostic fixtures that pinned the old place move
with it.

Still open:

- ~~**A local function keeps its written `!`.**~~ Closed by ADR 0052: its markers
  come off when the first round reaches its binding.
- ~~**The AST holds the deduced markers after the check.**~~ Closed by ADR 0052: a
  deduced marker is flagged `deduced`, and the printer leaves it out.
- **The second round costs a full typecheck.** Re-checking only the functions whose
  signatures changed would remove most of it.
- **Returns and fields are later phases.** For now their `!` stays written. Locals
  are ADR 0052.
- **The lever walk mirrors the read-only rule.** `levers_of` follows the access
  paths `walk_levels` judges — a field, an element, a conversion — but as a second
  walk. A gap between the two turns a needed written `!` into W0018. One walk that
  reports the lever it reached would close that class.
- **A lambda's parameter without a type does not take the `!` of its slot.** In
  `apply(b, x -> { x.v = 2 })` with `f: fn(Box!) -> void`, the write through `x` is
  refused. This predates the deduction; until it is fixed, such a parameter writes
  its type: `(x: Box!) -> …`.
