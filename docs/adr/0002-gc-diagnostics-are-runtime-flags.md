# 0002 — GC diagnostics are runtime flags, not compile-time ones

## Status

Accepted (2026-08-30). Applies to `VADER_GC_CHECK_BOX`, `VADER_GC_NO_CSTACK_SCAN`,
and any GC diagnostic added later.

## Context

The GC bug class hunted on 2026-08-30 is codegen-sensitive: stack layout decides
which stray bytes a conservative scan sees, so **any edit to the compiler moves
the bug**. Four probes were added during an earlier hunt; the bug vanished four
times, and two of those negatives proved nothing.

A `#ifdef` diagnostic produces two different binaries. A failure in the
instrumented one then confounds "the check found something" with "the layout
moved", which is exactly the confusion that cost the earlier hunt its day.

The same argument rules out `#ifndef NDEBUG`: the divergence these guards explain
appears only in `-O3 -DNDEBUG -flto` builds, so a debug-only guard would never
fire where the bug lives.

## Decision

GC diagnostics are read from the environment in `vader_gc_init` and branch at
runtime. One binary, one branch, and the only delta between a passing and a
failing run is the check itself.

They are off by default and must be safe to compile into a release binary.

A flag that changes GC behaviour rather than only observing it —
`VADER_GC_NO_CSTACK_SCAN` drops live objects by construction — says so where it
is defined, and is documented as a work-list generator, never a tuning knob.

## Consequences

Every major collection pays a global load and a predictable branch per flag.
Measured against the alternative it buys a sound experiment, and the cost is per
collection, not per object.

CI can sweep flag combinations without rebuilding.
