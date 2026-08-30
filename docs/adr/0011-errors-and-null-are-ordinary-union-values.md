# 0011 — Errors and null are ordinary values in a union

## Status

Accepted, shipped 2026-07-13. Distilled 2026-08-30 from `docs/ERROR_HANDLING.md`,
which this record replaces.

## Context

The error/null strategy was left explicitly undecided when async was designed —
no `Try` trait, no `?` operator, the question parked. The language meanwhile
carried a `?` (try) operator that had grown by accretion rather than by decision.

## Decision

Errors and null are **ordinary values in a union**: `T | SomeError`, `T | null`.
No exceptions, no `throw`/`catch`, no `Try` trait, and the `?` operator is
**removed from the language**.

Two mechanisms handle them, split by what they actually are:

**Control flow** — branching, early-returning, exhausting — is **narrowing**, with
plain `if` and `match`. `if x == null`, `if x is Error as e`. This is the only
mechanism that can early-return the bad case, because that is a control-flow
effect no function call can perform on its caller's behalf.

**Value handling** — defaulting, transforming, chaining — is **stdlib
combinators**, ordinary functions called on the value.

Which shape a fallible function returns is chosen by what the caller needs to
know. `T | null` is the default, for when the absence alone is actionable.
`T | SomeError` is for when the failure carries information the caller must
surface or branch on — a message, an offset, a kind. Neither is for user-facing
compiler errors: a pass that detects bad *source* pushes a diagnostic and returns
a recovery value, so one run reports more than one problem.

## Consequences

There is no `Result` type and none is wanted: a union plus narrowing covers it
without a wrapper to unwrap.

A bare sentinel (`-1`, `""`, an empty array) to signal failure is a defect, and so
is widening to `T | null` when an error value was already available — the union
costs nothing and the null loses the reason.

Removing `?` was a breaking change taken freely under the pre-1.0 rule; user code
migrated to narrowing in the same pass.
