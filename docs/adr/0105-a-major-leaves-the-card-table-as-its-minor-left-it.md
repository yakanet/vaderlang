# 0105: A major leaves the card table as its minor left it

## Status

Accepted (2026-10-21). Amends
[0104](0104-a-young-survivor-is-promoted-at-its-first-collection.md): its cost on
`vader test vader` is gone.

## Context

A major ended by dirtying every card of the used old span. That dates from when
the old generation was copied at each major: the copy could leave an old-to-young
reference under a card nothing had dirtied, and dirtying them all was the safe
answer.

Neither reason holds any more. The old generation does not move (0007). A minor
cleans its cards and re-dirties the ones whose old object still points young, so
the table it leaves is exact, and a major starts with such a minor. The mark moves
nothing, and scanning a live old object re-dirties the card of any slot that
points young, whatever the cycle. What was left was the price: the minor after
each major scanned every live old object, and age 1 runs more majors (39 against
26 on `vader test vader`).

Measured on 2026-10-21 (Mac M-series, release builds, one compiler C linked
against both runtimes, alternated runs, emitted C identical):

| Workload | Re-armed | Left |
|---|---|---|
| Self-compile, instructions | 32.2 G | 30.2 G (−6.3 %) |
| Self-compile, user time | 2.50 s | 2.36 s |
| `vader test vader`, instructions | 262.4 G | 242.0 G (−7.8 %) |
| `vader test vader`, user time | 20.2 s | 18.8 s |

Peak RSS is unchanged on both. Under age 2, `vader test vader` took 250.6 G
instructions.

## Decision

A major does not touch the card table.

## Consequences

- The minor after a major scans the cards the mutator dirtied since, like any
  other minor.
- The re-arm also covered a missing write barrier, but only for the first minor
  after a major. `VADER_GC_SCAN_ALL_OLD=1` stays the probe for one.
