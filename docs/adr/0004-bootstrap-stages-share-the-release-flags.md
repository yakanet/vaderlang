# 0004 — stage1 carries the release flags in both bootstrap modes

## Status

Accepted (2026-08-30), implemented in `9501db2bb` (`build.sh` and `build.ps1`).

## Context

`bootstrap/build.sh --three-stage` built stage1 at `-O1` — it is a throwaway
there, and skipping `-O3` saved about 11 s — while stage2 is built `-O3 -DNDEBUG`
plus LTO.

`verify.sh` compares the C emitted by stage1 against the C emitted by stage2. With
those flags, it was comparing an `-O1` binary's output to an `-O3+LTO` binary's,
folding "does the compiler behave the same at either optimisation level" into a
gate that only claims to test the fixed point.

On the first push after the gate was enabled, it reported a fixed-point failure on
linux-x86_64. With matched flags the fixed point holds there, byte for byte. The
red was true about something else entirely — the same C at two optimisation levels
really did emit differently — and it sent the reader hunting the wrong bug for
three rounds.

## Decision

stage1 is built with the release flags in both modes. Only the output path differs
between them.

More generally: a gate tests one thing. When a comparison has two variables, its
verdict names neither.

## Consequences

`--three-stage` costs a few seconds more. `verify.sh` now answers the question its
name promises.

The `-O` sensitivity the mismatch exposed is a real compiler bug and was tracked
separately; its root cause is ADR 0003.
