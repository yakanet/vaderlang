# 0167: The young generation keeps its size

## Status

Accepted (2026-11-21). Supersedes the adaptive young sizing of 2026-06-20
(`docs/HISTORY.md`).

## Context

A young semi-space started at 32 MB and grew toward half the live old set, up
to 192 MB (`VADER_GC_YOUNG_RATIO`, `VADER_GC_YOUNG_CAP`). The growth answered a
cost of that time: every minor marked the whole old card table dirty, so a minor
cost as much as old was large, and a fixed young made the scans of a run grow
with the square of the old live set.

A minor no longer does that. It snapshots the dirty cards of its worker, by
groups, and scans only the objects under them: its cost follows what the program
wrote into old since the last minor, not the size of old. The growth still ran,
and the young halves it grew stayed resident.

Measured on an Apple M-series laptop, minimum of five runs:

| | 32 MB, adaptive | 64 MB, fixed |
|---|---|---|
| `vader check` of the compiler | 1337 ms, 692 MB peak | 1375 ms, 453 MB |
| `vader check` of the test runner | 1273 ms, 653 MB | 1270 ms, 426 MB |
| the compiler compiled to C | 2359 ms, 940 MB | 2289 ms, 696 MB |

On 2026-11-12, with the young size pinned at each value, a hello world stopped
collecting at 64 MB (10 % fewer instructions), and the compiler's check ran 7 %
faster with 240 MB less resident. Larger starts, 256 MB, cut the check of the
compiler by up to 7 % more in time but hold more memory per worker, and each
worker of a pool has its own young generation.

## Decision

A young semi-space is 64 MB (`VADER_GC_YOUNG_BYTES`) and keeps that size. It
grows only when one object does not fit, up to `VADER_GC_YOUNG_MAX`. The
adaptive growth and its two settings are removed.

## Consequences

- Programs with a large old generation hold about 240 MB less at their peak; the
  time of the compiler's own runs stays within the noise.
- The pages of a semi-space are touched as allocation reaches them, so a program
  that allocates less than 32 MB holds nothing more. One that allocates between
  32 and 64 MB of short-lived values touches fresh pages where it used to collect
  and reuse them: the `arr_push` bench takes 11.4 ms instead of 9.8, and 65 MB
  instead of 34. Across the 34 benches the median does not move, and
  `plb2_bedcov` runs 26 % faster.
- A pool of workers reserves two 64 MB halves per worker, against two halves of
  up to 192 MB before.
- `VADER_GC_YOUNG_BYTES` remains the knob for a program that wants another size.
