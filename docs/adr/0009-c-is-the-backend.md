# 0009 — C is the compiler's backend

## Status

Accepted. Re-examined 2026-08-30 against LLVM and libgccjit; unchanged.

## Context

The compiler emits C and hands it to `cc` — clang on macOS, gcc on Linux,
mingw-w64 on Windows. The recurring question is whether an integrated backend
would be better: it would remove a process boundary, a text serialisation, and a
dependency on whatever compiler the host happens to have.

## Decision

Keep C.

**The C is not the cost it looks like.** `cc` is where the optimisation happens,
and matching it means reimplementing it. An integrated backend replaces a
serialisation cost with an optimisation-quality cost, and the second is far larger
than the first.

**Portability is the point.** C reaches every target the seed lists — darwin,
linux, windows, wasi, browser, on both arm64 and x86_64 — through toolchains that
already exist there. libgccjit in particular is GCC-only, GPL-licensed, and not
meaningfully available on macOS or Windows, which is most of the matrix.

**The bootstrap depends on it.** A committed C seed is what lets a machine with
nothing but a C compiler build the toolchain. An integrated backend would have to
be bootstrapped by something, and that something would be C anyway.

## Consequences

Compile time is dominated by `cc`, which is why the emission is split into one
translation unit per module and compiled across cores — see `docs/BOOTSTRAP.md`.

The generated C's quality is the compiler's responsibility, and undefined
behaviour in it is a real hazard rather than a theoretical one: `cc` exploits UB
aggressively at `-O3`, and a signed-shift overflow in the emitted VM code was
found by UBSan on 2026-08-30 and remains open.

The host toolchain is part of the build's identity. Two `cc` versions are two
different compilers, and the fixed-point gate compares emissions, not binaries,
for exactly that reason (ADR 0004).
