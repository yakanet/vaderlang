# 0069 — The marker leaves the grammar without a transition

## Status

Accepted (2026-10-16). Amends 0067, which planned a warning on the written `!` and
kept the read-only bit until the markers were gone, and closes the migration 0068
announced.

## Context

After 0067 a written `!` grants nothing: the frozen values decide, through the
effect summary. 0067 planned a transition: W0017 and W0018 would come back as one
warning on every `!` still written, with `vader fix` to remove them, and the
read-only bit would stay in the type IR until then. The tree no longer writes one
(the six module variables of `lib/std` moved to `@singleton`, 0068), and every
Vader source lives in this repository.

## Decision

- **`!` is no longer part of the syntax.** After a type, a parameter name or a
  module constant's type, it is a parse error like any unexpected token. No
  warning, no `vader fix`: nothing outside this repository writes one.
- **The type IR has no rights.** `StructType`, `TraitType`, `ArrayType`,
  `TupleType` and `TypeParamType` lose their `immutable` bit and `FnType` its
  `params_mutable`; two types are equal when their shapes are. A type prints as
  written, so `display_type` is the only rendering and the key of a union's
  variants.
- **A module constant is frozen without exception.** The writable form
  (`NAME: T[]!: value`) goes with the marker, and with it the module variable of
  the resolver and the writable class of the data pool.
- P1030, P1031, T3075, T3076, W0017 and W0018 are retired and not reused.
- `BcSignature.param_c_out` carries what C writes through, from `@c_out`: the only
  per-parameter write fact a backend reads.

## Consequences

- About 2 000 lines leave `vader/` and `lib/toolchain`: the marker in the AST and
  the parser, the rights layer of the typecheck, the writable data pool in the
  lowering, the bytecode, the VM and the C emitter, and `vader fix`.
- Every dump and every detail prints a type without `!`.
- The runtime keeps `vader_atom_roots_register` until the next reseed: the `main`
  the committed seed emitted still calls it.
- What the LSP should show of what a function may write is open; the effect
  summary has the answer, the types no longer do.
