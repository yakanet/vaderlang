# 0005 — `seed.sh regenerate` refuses to write a seed containing NUL bytes

## Status

Accepted (2026-08-30), implemented in `8b075899c`.

## Context

The compiler could emit C that does not parse. A live string collected out from
under its handle writes `length` bytes of recycled memory, so an expression comes
out as NUL bytes of exactly its own width. Observed on one of the eight per-target
emissions of a single run.

The seed is the C the cold bootstrap builds from. Committing a corrupt one breaks
that bootstrap for everyone, and the damage is discovered far from the commit that
caused it.

## Decision

`regenerate` scans the fresh emission and refuses to write when any unit holds a
NUL byte. Emitted C is text and never legitimately contains one.

The message tells the operator **not to retry until it passes**, and points at
`VADER_GC_CHECK_BOX=1`, which traps upstream of the damage.

Detection is `tr -d` piped into `cmp`, not grep: a NUL cannot survive command
substitution, and `grep -P '\x00'` is GNU-only.

## Consequences

One pass over the fresh emission per reseed.

This is a canary, not a cure: corruption landing on printable bytes walks straight
past it. It bounds the worst outcome, and that is all it claims.
