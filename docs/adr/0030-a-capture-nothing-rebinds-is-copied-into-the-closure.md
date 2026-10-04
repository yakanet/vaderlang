# 0030 — A capture nothing rebinds is copied into the closure

## Status

Accepted (2026-10-04).

## Context

`closure_analysis` heap-promoted every binding a lambda or a `defer` body
captures to a `Cell<T>`: the binding's slot held the cell, the closure's env
held a ref to the same cell, and every read in the lifted body went
`env.cap_N` → cell → value. Sharing a cell is what lets a closure see an
assignment made after it was created, and lets an assignment inside the closure
reach the enclosing fn. A binding nothing reassigns needs neither, yet paid the
same: one allocation per captured binding each time the closure is made, and a
second load on every read.

The resolver already knows which bindings an assignment rebinds: it records them
for W0015 and exports the complement, `rebind_free`, every local and parameter
no assignment targets as a bare name. A local cannot be read in its own
initialiser (R2006), so no closure captures a binding before it holds its value.

Options weighed:

- **A.** Copy into the env every capture `rebind_free` lists; keep the cell for
  the others.
- **B.** Copy only `::` locals (`immutable_locals`). Narrower, and misses the
  common case of a captured parameter (`make_adder(n)`).

## Decision

A. `cell_symbols` — the set that decides heap promotion — receives a capture
only when an assignment rebinds it (`note_cell_capture`). Any other capture is
copied into the env when the closure is made:

- the env field takes the binding's declared type in the fn making the closure,
  the type of its own slot, instead of an opaque cell ref. `env_slots` computes
  each capture's field and type once per closure; the env struct, the env literal
  and the lifted body (`LiftedFnContext.captures`) all read those slots, so the
  field is written and read at the same type;
- the lifted body reads the field directly, and casts a narrowed use as it would
  for a slot.

The value a copy holds never changes after the closure is made, and a struct is a
reference, so the copy and the binding designate the same object: no program can
tell the two apart. A `for` variable is a fresh value each iteration, so a
closure made in the body copies that iteration's value, as its per-iteration cell
did. `.Binding` symbols (`as` aliases, pattern fields) are not in `rebind_free`
and keep their cell.

## Consequences

Measured 2026-10-04 against `16d1c9682`, alternating:

- VM: an indirect call to a closure with one capture, 95 → 62 ns per iteration;
  `closures` −23 %; `iter_chain` −3 %; `sort_by` and `vm_str` within noise.
- Native: `closures` −26 % (min), −14 % (median); `sort_by` and the indirect-call
  micro-benchmark within noise. Self-compile to C: 2 350 → 2 329 ms.
- Snapshots: 72 files over the lower, bytecode and emit-C stages, 532 lines
  fewer; no `vm.snapshot` moved.

A capture that some assignment rebinds still lives in a cell — a counter a
closure increments, an accumulator the enclosing fn keeps assigning.
