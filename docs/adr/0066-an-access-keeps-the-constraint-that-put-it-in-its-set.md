# 0066: An access keeps the constraint that put it in its set

## Status

Accepted (2026-10-15). Extends 0059: a frozen fault names what modifies the value.

## Context

A frozen fault (0059) says that a use of a constant is written through, or lent to
a callee that modifies it. Once the faults become the errors T3070 and T3072 (0053,
the switch of M1), the detail has to name the frozen value and what modifies it:
`bump` modifies `c`, through the calls the value is lent down, down to the write.
The summary knew that the access is there, not why.

A search after the fact was tried on 2026-10-14 and withdrawn before commit. It
walked back from the fault, skeleton by skeleton, to a mark that explains the
access:

- it is greedy, and loops in a recursive function that lends the value on before
  writing it (`fill(c, k)` calls `fill(c, k - 1)` before `set(c)`: "via fill, fill,
  fill…", never `set`);
- it repeats the rule of `apply_constraints` to tell which constraint could have
  produced an access, and reads facts that need not be in the state the fault came
  from;
- it settles each callee of the chain again for each fault, with no cache: 1,000
  faults over a chain of 8 with 100 bindings per function took `settle_frozen` from
  1 ms to 3.65 s and 2.9 GB, and the LSP would pay it on every keystroke.

## Decision

- **Each access keeps the constraint that first put it in its set**, recorded
  during the fixed point, when `include` adds it. Two words per access, beside it
  in `ParamEffects.origins`: a mark of the body (its own write or keep), or a call
  (the site, the target it ran, the callee's parameter) with the access of that
  parameter it carries. A set built by hand (an intrinsic's effects, anything at
  all for unseen code) has no constraint.
- **The first origin stays.** The access a call carries was in the callee's set
  before the call carried it. A cut path that drops accesses takes the origin of the
  first it drops, which was there before it: through a recursive walk of a tree, the
  cut path that stands for `.kids[]…` would otherwise carry the very access it drops,
  and a chain through it would never reach the write. Following the origins from a
  fault therefore goes back in the order the accesses arrived, down the calls to the
  write, and ends. A call that carries an access a cut path dropped since resolves to
  that cut path.
- **Positions sit on the constraints**, given where the walk creates them (a mark,
  a call), not in a dynamic state of the walk. A call keeps its callee, to name it.
- **A fault carries its chain** (`FrozenSite.chain`): each call with the parameter
  that takes the value, then the write, or the callee without a body that makes it
  (`push`). `vader dump --stage=effects` writes it under the fault.

## Consequences

- The chain of `fill` above is `via fill (c)`, `via set (c)`, `assigned c.n`; that of
  `clear(n)`, which writes each child and recurses on it, `via clear (n)`,
  `assigned n.kids[]…`. A chain past 4,096 calls is a fault of the summary: the pass
  stops with an internal error.
- Measured on 2026-10-15, `check` of the compiler: 17 MB more allocated (0.8 %),
  the time of the typecheck and the summary within noise.
- The faults are still observed only. The switch makes them T3070 and T3072 with
  this chain as their detail; the `breaking` access of T3102 and an LSP hover
  ("what this function does with `xs`, and where") can read the same origins.
