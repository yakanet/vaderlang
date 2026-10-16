# 0068 — A module keeps state in a singleton

## Status

Accepted (2026-10-16). Replaces the module variable (`NAME: T[]!: value`) once the
six sites of `lib/std` are migrated; follows 0067, where `!` stopped granting
anything.

## Context

With 0067 the `!` decides nothing, and it is leaving the syntax. One form still
needed it: `NAME: T[]!: value`, a module constant marked writable, the only state a
module could hold. Only an array could be state, so a counter, a map or a lazily
built object went through a one-slot box (`RAW_ACTIVE: bool[]!: [false]`), and an
initialiser the data pool could not bake was evaluated again at each read, losing
its writes.

A reassignable module variable (`NAME := value`) was considered on 2026-10-15 and
set aside: it needs a global written by the user, a rule for who reassigns it
from another module, an initialisation baked at build time or ordered at start-up,
and a kind the folding sites (`fold_const_value`, the comptime bake) must tell from
a constant.

## Decision

- **A module holds constants and functions, no variable.** Its state lives in the
  instance of a `@singleton` function: `@singleton log :: fn() -> string[] = []`.
  The first call runs the body and keeps the result; every later call hands back
  the same instance. The instance is ordinary heap state, not a frozen value.
- **A singleton takes no parameter, has no type parameter, and neither awaits nor
  yields** (T3103): an argument or a type argument would ask for one instance per
  value, a cache rather than a singleton, and a body that suspends would let
  another call see it half built. Anywhere but a free function the decorator is
  P1014, and on a `@target` body R2037 (the declaration carries it). A call that
  comes back into the singleton while its body runs traps. A singleton that
  returns `void`, or never returns, runs its body once and keeps no instance.
- **It cannot run at comptime** (C4018): only the program's run builds the
  instance. The tree-walking evaluator refuses the call; the VM path refuses the
  global slots it would reach.
- **The IR gains global slots** (`global.get`, `global.set`, a `global` directive
  per slot): storage that outlives every call, at its type's zero value until
  written, written only by code the compiler generates. Each target defines it: a
  static variable in C, rooted in the permanent GC frame by what it holds (a box,
  a raw reference, an atom id); a per-module table in the VM. The bytecode DCE
  drops a slot no surviving op names.
- **The singleton is built in the lowering.** Its body is lowered as an init with
  an identity of its own, as a lifted lambda has, and the function becomes an
  accessor over two slots, its state and its instance: ready, the instance;
  initialising, a trap; otherwise run the init, keep the instance, mark it ready.
  Before the lowering it is one ordinary function, read for its decorator by two
  checks only: the typecheck (T3103) and the effect summary, where its result is
  kept rather than returned, so a constant it hands back is copied and a view of
  a string's bytes is T3071.

## Consequences

- No new syntax: a decorator on a function, an ordinary call to read the state.
- The singleton's semantics are written once, in the lowering, for every target.
  With threads, the state slot is what a "once" protocol needs (an atomic
  transition, a wait for another thread's initialisation, a trap only on a
  re-entry of the same thread), generated there without touching the language.
- Set aside: a hidden data-pool entry as the instance's storage (a state disguised
  as a one-slot array in a table made for constants); a dedicated "instance or
  init" operation (each target would implement the state test and the trap).
- A singleton's state is shared by the tests of a run, as any global is.
- The module variable form, `Symbol.module_variable`, `declares_module_variable`
  and the writable storage class of the data pool leave once `lib/std` migrates.
