# 0007 — Generational GC: copying young, non-moving mark-sweep old

## Status

Accepted. Records a design the runtime already implements; written 2026-08-30
from `runtime/c/vader_runtime.c` and `runtime/c/vader.h`, where the reasoning had
been living in comments.

⚠️ Reconstructed after the fact. The consequences below are observed; the
alternatives are those the code names, not necessarily every one weighed at the
time.

## Context

Vader compiles to C and ships its own runtime, so the collector is ours to choose.
The workload that matters most is the compiler compiling itself: a large,
long-lived object graph (AST, types, lowered IR) with heavy short-lived churn
around it.

## Decision

Two generations with different collectors, because they face different problems.

**Young is a copying (Cheney) semi-space pair.** Allocation is a bump; a minor
copies survivors to to-space, or promotes them to the old gen once `age` reaches
`VADER_TENURE_AGE` (2 minors). Churn is where a copying collector is strongest —
it pays per survivor, not per allocation.

**Old is a NON-MOVING mark-sweep slab.** One lazily-committed reservation carved
into size-class regions; a major marks the live set and sweeps the dead in place.
Old objects never move. The predecessor was a copying old gen, and the trade it
was carrying is why it went: a copying old gen needs a 2× to-space and relocates a
live set that, in a self-compile, barely dies.

**Cross-generation refs use a card table**, one card per 512 bytes of old,
written by the `VADER_WRITE_BARRIER` macro the C emitter issues, and read as
additional roots by a minor. The alternative — scanning the whole old space on
every minor — is quadratic in the old live set, which is exactly the shape a
self-compile has.

**Sizing is RAM-proportional, not absolute.** The old reservation cap is a
fraction of detected physical RAM (`VADER_GC_RAM_PERCENT`, default 50 %), so the
same binary self-compiles on an 8 GB laptop and a 64 GB workstation. This is the
model the JVM (`MaxRAMPercentage`) and Go (`GOMEMLIMIT`) converged on after
absolute `Xms`/`Xmx` sizes proved too fiddly per machine. Young is deliberately
NOT RAM-scaled: its 192 MB ceiling is a per-minor cost cliff, not a memory limit.

A major fires when the old footprint exceeds `live_after_last_major × 1.5`, and
never below a 64 MB floor — so small programs never pay one.

## Consequences

Old objects never move, so an interior or stale pointer into the old gen is
*stable*, which the conservative root scans below rely on.

The mark-sweep old gen **reuses freed slots eagerly**, where the copying
predecessor masked missed roots through deferred reuse. Rooting therefore has to
be right, and a gap that used to be invisible now corrupts memory. That is the
ground ADR 0008 stands on.

Untouched reservation pages do not reside on POSIX and are reserved-not-committed
on Windows, so a large cap costs nothing until it is used.

Every constant is `-D`-tunable and several have env overrides, which exist for
diagnosis; the defaults are the interface.
