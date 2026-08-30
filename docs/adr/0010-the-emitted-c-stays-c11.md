# 0010 — The emitted C stays `-std=c11`

## Status

Accepted (deferred bump, 2026-05-12; unchanged on re-audit 2026-05-26). Distilled
2026-08-30 from `docs/C23_MIGRATION.md`, which this record replaces.

⚠️ File paths below are from the TypeScript compiler, which no longer exists. The
argument survives the port; the line references do not.

## Context

Compiling the emitted C with `cc -Wall -Wextra` produced **2 362 warnings**, of
which 2 352 were `-Wunused-label`: the `end_NN:;` labels the emitter drops at the
close of every nested block, kept even when no surviving `goto` reaches them. The
remaining 9 were unused vtable trampolines and one runtime helper. With the build
chain's own flags (`-std=c11 -O3 -DNDEBUG`) the count is **0**.

The noise raised the question of whether to bump the standard.

## Decision

Stay on C11. The bump is deferred, not rejected.

The two questions must not be conflated. **The warning noise is tactical** and has
nothing to do with the standard: emitting a label only when a `goto` points at it,
or marking it unused, removes 2 352 of the 2 362 warnings while staying on C11.
That is the high-yield hour.

**The bump is strategic and buys nothing today.** Cost is around half a day since
CI is already on a compiler that accepts it. The benefit is cosmetic —
`[[noreturn]]`, `bool`, `nullptr`, `static_assert` — and the runtime uses no C11
feature at all: an audit found no `_Generic`, `_Atomic`, `_Static_assert`,
`_Alignas`, anonymous union, or `<stdatomic.h>`, and none appeared as the runtime
grew through atom interning and the GC work. The code sits below the C11 floor
already, so the label on the flag is close to free to change — and equally close
to pointless.

## Consequences

`-std=c11` is pinned in the build chain and the test harness.

The portability surface stays as wide as it can be: every toolchain in the target
matrix accepts C11, which is not yet true of C23 everywhere.

Since the runtime uses nothing above C99 plus a few GCC attributes, a later bump
stays cheap — the cost of deferring does not grow.
