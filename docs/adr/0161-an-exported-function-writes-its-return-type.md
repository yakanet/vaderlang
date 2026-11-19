# 0161: An exported function writes its return type

## Status

Accepted (2026-11-19). Turns the warning on an inferred export return into an error.

## Context

An expression-bodied function may leave out its return type, which its body gives.
Exported, that type is what other modules read: it changed with every edit of the
body, and a warning said so. The compiler also had to settle those returns before
any other module could read them: two passes that type only these bodies, run in
the order of the modules, on copies of the types taken before them and taken again
after. The passes settle one level of forward reference, not two, so a chain of
inferred returns could still read as unresolved.

## Decision

- **An exported function writes its return type**, a trait default of an exported
  trait included: it is a contract for the other modules. One that leaves it out is
  an error, which names the type to write.
- **A function that never returns marks `@no_return`**, which fixes its type:
  `never` has no spelling.
- Inference stays for the functions of a module, private ones and defaults of
  private traits: what another module reads is final once declared.

Rejected: keeping the warning and settling the returns across modules on demand,
which keeps the copies, their refresh, and an order between modules for a feature
the contract argues against.

## Consequences

- No module reads a return another module infers: settling returns becomes a
  question inside one module, answered when a call needs it.
- An export with an inferred return in a library fails its build once, with the type
  to write in the message.
