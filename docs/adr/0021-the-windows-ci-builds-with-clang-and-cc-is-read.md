# 0021 — The Windows CI builds with clang, and `CC` is read by `vader build`

## Status

Accepted (2026-09-24).

## Context

The Windows job took about twice as long as the Linux one. Probes on the runner
located the gap in the C compiler, not in Vader's runtime: the self-compile front
end ran at 1.16× Linux and the type checker at 1.01×, while MinGW's gcc was
1.6–1.9× slower per compilation unit.

The runner image already ships LLVM 20.1.8, which targets MSVC by default. A copy
of it named `x86_64-w64-mingw32-clang.exe`, plus a config file pointing it at the
image's MinGW sysroot and at lld, builds the compiler with no download. On the
same runner, `bootstrap/build.ps1` took:

| stage      | gcc     | clang   |
|------------|---------|---------|
| stage0     | 35.7 s  | 20.9 s  |
| stage1     | 90.9 s  | 53.4 s  |
| stage2     | 87.0 s  | 50.8 s  |
| **total**  | 213.6 s | 125.2 s |

The bootstrap scripts already honoured `CC`. `vader build` did not: it read only
`--cc`, and `vader doctor` warned when `CC` was set. So the test suite, which
builds through `vader build`, would have stayed on gcc. The critical path of the
Windows test run is `hook_driver.test.ts`, which is driver builds.

## Decision

`vader build` reads `CC` when `--cc` is absent, and falls back to the host
default after that: `cc`, or `gcc` on Windows. The value names one program, not
a command line. `vader doctor` reports it as information, not as a warning.

The Windows job sets up the MinGW-targeting clang (`tools/ci/mingw-clang.ps1`)
and exports it as `CC`. The build, `vader build` and the test helpers that spawn
a compiler all pick it up.

## Consequences

`CC` behaves the way it does in every other Unix build tool, and the CI needs no
per-step flag.

The Windows job no longer exercises MinGW's gcc. The user-facing install
procedure (WinLibs gcc) keeps working, but nothing tests it on push any more. A
gcc-only break on Windows would surface in a user report, not in CI.
