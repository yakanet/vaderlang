# 0070 — A generic call instantiates its callee afresh

## Status

Accepted (2026-10-17). Step 5 of the type-system charter (D1). Builds on the commit
that gave each type parameter one symbol (`type_param_symbols`).

## Context

A function type did not say which parameters it binds: "is this function generic"
was answered by looking for a `TypeParamType` in its signature, so a `T` named only
in the body or in a bound escaped every check. A call bound the declaration's own
symbols in a table. Inside `f<T>`, a call to `f` or to any function sharing a
symbol with the body met the body's `T` on both sides, and a set of patches kept
them apart: skipping `T := T` in the unifier, a rigid set of the type parameters in
scope (`hold_type_params_in_scope`), a "held" binding rule, four places where T3069
stayed silent, and a guess at whose parameter an unbound `T` was
(`collect_unbound_type_params`).

Two shapes were measured on a throwaway prototype of the typecheck before choosing:

- **(a)** the function type carries its quantifier (`FnType.type_params`), and each
  call instantiates it with fresh inference variables (`InferVar`), a type distinct
  from `TypeParamType`;
- **(c)** fresh `TypeParamType` symbols per call, and a set of the ids a unification
  may bind, passed down every call.

## Decision

- **(a).** `FnType.type_params` is the quantifier; a call replaces each quantified
  parameter by a fresh `InferVar`, binds only those, and keys the solutions back by
  the declared parameters once solved (`note_call_bindings`), which is what the
  later passes read. A type parameter met in an argument, the receiver or the result
  slot is rigid, whoever declared it.
- **No inference variable leaves the typecheck.** Each one is replaced by its
  solution (`zonk`); a module's tables are swept once its bodies are walked. A
  later pass that meets one stops the compiler (`leaked_infer_var`) instead of
  reading it as an erased type.
- **An explicit `<…>` fixes the callee's parameters in the order it declares them**,
  whatever module declares it.
- **A recursion that grows its type argument is refused** (T3104): monomorphization
  would not terminate. It is detected on the graph of instantiations, as a cycle
  holding an edge that nests a parameter inside a larger type (the "expanding
  cycle" rule), over the calls that record their bindings. A member called on a
  receiver binds the impl's parameters through the receiver's type. An array
  impl's member runs one instance per element type, so what its parameters take
  at an array receiver is recorded (`receiver_instances`) and `[self].depth(…)`
  inside `T[]`'s impl is refused too (added 2026-10-18). A generic struct's impl
  member runs once per instance the program writes and once, as a representative,
  for every other: a `Box<T[]>` built and called inside `Box<T>`'s impl asks for
  no new instance, and is accepted. A member reached through a bound adds no edge
  yet. Accepting a growing recursion when the body runs erased waits on the
  representation analysis (D3).

## Consequences

- The rigid set, the held-binding rule, `T := T`, four of the five T3069 silences,
  `fn_has_type_params`, `collect_unbound_type_params`, `seed_explicit_type_args` and
  `seed_ufcs_bindings` are gone. Only the arity-mismatch silence of T3069 remains.
- Measured on a self-compile (`check vader/cli/main.vader`): typecheck time +2 to
  3 %, bytes allocated +0.3 % (2 026 generic calls, 2 192 variables, none left
  unsolved). The peak resident memory moved from 727 to 848 MB with the same
  allocations and the same number of collections, and a smaller live set at the
  end: when the collections fall, not how much is allocated.
  Under (c), a fresh parameter that leaked would look like a real `T`, which is
  what the lowering's unresolved-callee panics were; an `InferVar` that leaks is
  found by its type alone.
- A variable prints as the parameter it instantiates, so diagnostics and dumps did
  not change.
- `type_contains_type_param` answers yes on an `InferVar`, so the heuristics that
  treat an abstract slot as carrying no information keep working unchanged. They
  are not audited one by one.
- A generic function used as a value (`g :: id`, `apply(name_of, 5)`) is not
  instantiated yet (charter F4).
