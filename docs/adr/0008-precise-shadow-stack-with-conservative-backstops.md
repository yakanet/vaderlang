# 0008 — Precise shadow stack, with conservative backstops

## Status

Accepted, and **the backstops are provisional**. Written 2026-08-30.

## Context

The old generation is non-moving and reuses freed slots eagerly (ADR 0007), so
every live old reference must be found at a major or its slot is handed to
someone else.

The C emitter issues a shadow stack: each function pushes a `vader_gc_frame_t`
listing its box roots (`ptrs`), its raw ref locals (`raw`), and the GC structs the
escape analysis put on the C stack (`stack_objs`). That is the precise root set.

It is not complete. A live old ref can sit only in a C local or a register, which
no frame lists. And a `vader_string_t` is a bare `u32` atom id — it never appears
as a heap pointer or in a box, so it is invisible to both the frame chain and the
heap walk.

## Decision

Keep the precise shadow stack as the primary root set, and cover the two known
holes with conservative scans at a major:

- **objects**: `setjmp` to spill callee-saved registers, then walk the C stack
  word-aligned and mark every old object any word points at. Old objects never
  move, so a false positive only retains garbage.
- **atoms**: the same walk at 4-byte stride, since a `u32` local need not be
  8-aligned, marking every value that bounds-checks as an atom id.

Frames are walked list by list, never skipped whole: a frame carrying stack
objects and no box roots must still be visited.

## Consequences

⚠️ **A conservative scan has a false-NEGATIVE class the comments long ignored.**
Both scans reason only about false positives ("merely retains a dead object — no
correctness risk"). A live ref the scan *cannot see* is swept, and the slot is
reused immediately. On 2026-08-30 that produced C that does not parse: an
18-character expression emitted as 18 NUL bytes, a string freed under a live
handle. See ADR 0003 and 0005.

The scans are therefore a **backstop to be removed**, not a design to build on.
`VADER_GC_NO_CSTACK_SCAN=1` (ADR 0002) exists to drive that: with the object scan
off, every failure names a reference the precise rooting misses. When nothing
breaks, the scan goes, and the false-negative class with it.

Known open as of 2026-08-30: `VADER_GC_STRESS_MAJOR=1` breaks the compiler on a
snippet in seconds, locally, 3 runs out of 3 — a rooting gap that predates the
fix in ADR 0009 and is not the misaligned-candidate variety, since the alignment
guard does not fire on it.
