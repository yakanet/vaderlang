# 0006 — The fixed-point gate runs on every push

## Status

Accepted (2026-08-30), implemented in `0a45ee489`.

## Context

The `fixed-point` job (`bootstrap/verify.sh`) was gated to `workflow_dispatch` and
release tags, on the stated grounds that it was too slow for every PR.

It is also the only job that would notice a stale seed. `test-posix` and
`test-windows` build stage0 from the seed and then self-compile stage1 from
current sources, so both pass with a seed that no longer matches. Nothing on push
checked the fixed point or build reproducibility either.

The timings contradict the premise. The job measured **257 s and 286 s** the two
times it had actually run, against **10 m 59 s** for the Windows job that sets a
run's total (11 m 3 s). Jobs run in parallel, so a four-minute Linux job finishes
inside that shadow: the wall clock is unchanged and the cost is runner minutes.

## Decision

Drop the `if:` gate. The job runs on push and pull request like the others.

## Consequences

Confirmed on the first green run after the change: fixed-point **4 m 41 s**,
Windows **11 m 2 s**, total **11 m 7 s** — the prediction held.

The gate found a real fixed-point failure on its first push (ADR 0004) and a real
seed divergence on its second, both of which had been invisible until then.

A standing risk is accepted: the reproducibility assertion is a `cmp` between two
builds. Should it ever prove flaky it would block `main`, which is information
worth having rather than a reason to gate the job again.
