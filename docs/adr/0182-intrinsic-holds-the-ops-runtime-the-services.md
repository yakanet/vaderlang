# 0182: `Intrinsic` holds the ops, `Runtime` the services

## Status

Accepted (2026-11-26).

## Context

`std/core`'s `Intrinsic` held 66 members of two kinds. Some are operations the
compiler performs itself: an op of the bytecode (`string_compare`, the bit
conversions, the buffer members, the five string reads) or a node of the
lowering (the array members). The others are services a backend provides with a
state the program does not see: the scheduler, the collector, `deep_copy`,
`bytes`, `panic`, `current_os`, the threads of the component model, the VM's
dynamic foreign calls.

One enum, `IntrinsicId`, named them all and carried what may happen during a
call (`DuringCall`). Only a service is ever called, though: an op never reaches a
backend. So every reader matched over both kinds and gave the ops an arm that
said "never reached": the VM's `dispatch_import`, the C emitter's `shim_body`,
the WASM emitter, the comptime gate, the guest threads. The ops also carried a
`DuringCall` that nothing read.

The question that sorts a member: does the backend serve the call with a state of
its own? Yes for every service, no for an op, whose meaning the compiler knows in
full.

## Decision

- Two traits in `std/core`: `Intrinsic` keeps the 22 ops
  (`lib/std/core/intrinsics.vader`), `Runtime` takes the 44 services
  (`lib/std/core/runtime.vader`), with `Readiness` and `CollectorStatistic`,
  which only services read.
- Two enums: `IntrinsicId` names the ops and carries nothing else,
  `RuntimeService` names the services with their `DuringCall`. An import carries
  both (`BcImport.intrinsic`, `BcImport.service`), and `.virt` writes them as
  `intrinsic=` and `service=`. Each backend matches over `RuntimeService` alone.
- No member of one trait shares a name with a member of the other, a test checks
  it: the lowered declaration names its member by name alone
  (`LoweredFnDecl.intrinsic`), and the mangle names the trait
  (`std_core$Runtime$park`).
- The type checker, the lowering and the effect summary recognise both traits
  the same way: a program implements neither (T3146), calls their members on the
  trait, and a function that only forwards to one is lowered as the member.
- The five string reads became ops of the bytecode first, so that no op is left
  served by a host.
- The services of the component model (`wasm_*`) and the VM's foreign calls
  (`ffi_*`) go to `Runtime` with the others, which leaves `Intrinsic` with ops
  alone. Where they finally belong is decided apart. `vader/vm/ffi.vader`, which
  wrapped the latter, is gone: the VM calls `Runtime.ffi_*` itself.

## Consequences

- A new op touches the selection and the lowering, and none of the backends. A
  new service touches every backend, the comptime gate and the effect summary,
  each of which T3013 points at.
- The members of both traits remain callable from any program
  (`Runtime.ffi_call`), as `Intrinsic`'s were: the surface stays unstable, and
  nothing yet keeps a program from naming it.
- Changing the traits took a new seed in between: the compiler learnt `Runtime`
  while the library still declared every member in `Intrinsic`, and the library
  moved once a seed knew the new trait.
