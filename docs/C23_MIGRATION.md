# C11 → C23 Migration — Cost Analysis

Source: investigation of warnings raised by `cc -Wall -Wextra` on the C output
of `vader/cli/main.vader` (2026-05-12). Scope: the `-std=c11` flag pinned in
the build chain, the hand-written runtime in `runtime/c/`, the C emitter in
`src/c_emit/`, and the CI workflow.

Decision: **deferred**. This document records the cost so a later decision
has a baseline. Nothing is changed by this doc.

> *Refresh 2026-05-26* — the analysis below still stands. Two changes
> since 2026-05-12 worth noting :
>
> - **Runtime grew but stayed C99-compatible.** `runtime/c/vader.h` is now
>   802 LOC (was 451) and `vader_runtime.c` is 2659 LOC (was 1848), most
>   of the growth from atom interning (`ATOM_INTERNING.md`, 2026-05-25)
>   and the GC/erasure infrastructure. Re-audit confirmed : no
>   `_Generic`, `_Atomic`, `_Static_assert`, `_Alignas`, anonymous union,
>   or `<stdatomic.h>` use added. The runtime stays C99 + GCC extensions
>   on the new code paths, so the §"Surface concerned" verdict ("project
>   is already running below the C11 floor, label is essentially free to
>   change") still holds.
> - **The label-noise priority is still untouched.** The 2352
>   `-Wunused-label` warnings on the §"Trigger" section are still
>   emitted. The §"Recommendation" Priority 1 (patch `end_NN:;` labels
>   with `__attribute__((unused))` or post-pass elision) remains the
>   highest-yield-per-hour action ; nothing else has subsumed it.
>
> Decision unchanged : C23 bump still deferrable, no urgency. The doc
> reads as a cost baseline.

## Trigger

Compiling the Vader-emitted C with `cc -Wall -Wextra` (Apple clang 21 / clang
22 upstream) produces:

- **0 warnings** with the build script's flags (`cc -std=c11 -O3 -DNDEBUG`).
- **2362 warnings** with `-Wall -Wextra` on clang upstream:
  - 2352 × `-Wunused-label` — the `end_NN:;` labels the emitter drops at the
    close of every nested block, kept even when no surviving `goto` points to
    them.
  - 9 × `-Wunused-function` — 8 vtable trampolines (`vader_vt_Contains__contains`,
    `vader_vt_Iterator__next`, `vader_vt_Comparable__{compare,gt,gte,lt,lte}`,
    `vader_vt_Step__step`) and 1 runtime helper (`vader_gc_alloc_in_old` in
    `runtime/c/vader_runtime.c:191`).
  - 1 × `-Wunused-but-set-variable` — dead temporary `t9` in a multi-init.

Apple clang at `-O3` reports only 72 of the label warnings because its DCE
runs before late diagnostics; at `-O0` it agrees with upstream clang exactly
(2362). So the underlying surface is the upstream-clang figure.

The question this doc answers: would a bump to `-std=c23` help, and what
would it cost?

## Surface concerned

The `-std=c11` flag is pinned in exactly three places:

| File | Line | Use |
|---|---|---|
| `src/cli/commands/build.ts` | 104 | flag passed to `cc` for native builds |
| `tests/native.test.ts` | 51 | native parity suite |
| `tests/leaks_check.ts` | 69 | leak-detection script |

The C code itself is small and already sub-C11 in practice:

- **Hand-written runtime** — `runtime/c/vader.h` (451 LOC) + `runtime/c/vader_runtime.c`
  (1848 LOC) = **2299 LOC**. Audited: no C11-specific feature used (`_Generic`,
  `_Atomic`, `_Static_assert`, `_Alignas`, anonymous unions, `<stdatomic.h>`
  — none of them). The runtime is C99 + portable GCC extensions
  (`__builtin_expect`, `__attribute__((noreturn))`).
- **C emitter** — `src/c_emit/emit.ts` + `body.ts` + `ops.ts` + `static_table.ts`.
  Emits C99-compatible output: named structs with a header field,
  `switch`/`case`, `goto`/labels, tagged unions for boxes. No designated
  initializers, no compound literals, no `_Generic`.

There is no C11 technical debt to repay on the way to C23: the project is
already running below the C11 floor, so the standard label is essentially
free to change.

## C23 availability on the targeted toolchain matrix

| Compiler | `-std=c23` status |
|---|---|
| Apple clang 21 (`/usr/bin/cc` on dev machine) | OK (probe `exit:0` confirmed) |
| Homebrew clang 22 upstream | OK (probe `exit:0` confirmed) |
| gcc 12 | partial (`-std=c2x` accepted, features incomplete) |
| gcc 13 | OK (`-std=c2x` ≈ C23, broad coverage) |
| gcc ≥ 14 | OK (C23 ratified + complete coverage) |
| MinGW-w64 gcc ≥ 12 | OK (`-std=c2x` accepted; ≥13 recommended) |

### Project CI status

`.github/workflows/build.yml` has a single job that touches C:

- `test` (line 17), running on `ubuntu-latest`, executes `bun test` — which
  includes `tests/native.test.ts:51`, the only step that actually invokes
  `cc` against the runtime sources.
- `dist` (line 41), also on `ubuntu-latest`, compiles **no C** — it bundles
  Bun into a native binary and packages the runtime sources as-is for the
  end user.

GitHub `ubuntu-latest` resolves to **ubuntu-24.04** today (2026), which ships
**gcc 13.x** by default. So:

- `gcc ≥ 12` is trivially satisfied — no workflow change required.
- `gcc ≥ 13` is also met — the CI is already on a C23-capable toolchain.
- If a stricter pin is wanted later, the CI can `apt-get install -y gcc-13`
  and export `CC=gcc-13` for the test job.
- The end user's `cc` (which compiles the C that `vader build --target=native`
  produces) is out of the project's control; the README/SPEC can simply
  require "recent gcc/clang".

CI risk for a C23 bump: **none to very low**.

## Gains available if the bump happens

Pure modernization (cosmetic):

1. `[[noreturn]]`, `[[maybe_unused]]`, `[[nodiscard]]` standard attributes —
   replace `__attribute__((noreturn))` in the runtime.
2. `bool` / `true` / `false` keywords — drop `#include <stdbool.h>`.
3. `nullptr` keyword — replaces `NULL`.
4. `static_assert` (unprefixed) — replaces `_Static_assert`.
5. Standard `typeof`.
6. Standard `unreachable()` — replaces `vader_unreachable`.

Relevant to the warning study that triggered this analysis:

- `[[maybe_unused]]` standardized on labels — the emitter could prefix every
  `end_NN:;` with `[[maybe_unused]]` and **silence the 2352 `-Wunused-label`
  warnings** without a flag tweak and without a post-pass that tracks which
  labels survive.

However, the same effect is already available **without leaving C11** via
`__attribute__((unused))` (GCC/clang extension), accepted by every compiler
the project already supports. So C23 is **not a prerequisite** for cleaning
up the label noise.

## Execution cost

| Task | Effort | Risk |
|---|---|---|
| Bump the flag in 3 files (`build.ts:104`, `native.test.ts:51`, `leaks_check.ts:69`) | ~5 min | near-zero |
| Local probe + native parity tests under `-std=c23` | ~15 min | exposes only trivial incompatibilities if any |
| CI check (`ubuntu-latest` = gcc 13, already OK) | ~10 min | none |
| Optional: gradual modernization of the runtime to C23 idioms | 1–2h | none (cosmetic) |
| Optional: emit `[[maybe_unused]]` on labels in `src/c_emit/body.ts` | 1h | none |
| **Realistic total** | **~0.5 day** (CI already compatible) | |

## Recommendation

Two questions must not be conflated:

1. **Quiet the `-Wunused-label` noise** — tactical. Lowest-risk fix: patch
   the emitter (`src/c_emit/body.ts`) so every `end_NN:;` carries
   `__attribute__((unused))`, or do a post-pass that only emits a label when
   a `goto` actually points to it. Effort ≈ 1–2h, no standard change, no CI
   risk. Eliminates 2352 of 2362 warnings.

2. **Bump to C23** — strategic modernization. Marginal cost (~0.5 day; the
   CI is already on gcc 13), mostly cosmetic benefit (`[[noreturn]]`,
   `bool`, `nullptr`, `static_assert`). No real capability gain for the
   current Vader compiler, which uses no C11+ feature today. Can wait for
   the self-host phase, where the Vader bootstrap could emit idiomatic C23
   from day one if desired.

Suggested ordering:

- **Priority 1**: clean up the emitter's labels (and incidentally the 9
  vtable trampolines + the dead `t9` temporary) while staying on `-std=c11`.
  Highest yield per hour.
- **Priority 2 (deferrable)**: bump to `-std=c23` once the matrix is stable
  on gcc ≥ 13 across CI/cross-compile and other priorities are settled. No
  urgency, near-zero short-term gain.

## Files to touch if the bump is greenlit

- `src/cli/commands/build.ts:104` — `"-std=c11"` → `"-std=c23"`.
- `tests/native.test.ts:51` — same.
- `tests/leaks_check.ts:69` — same.
- `runtime/c/vader.h` — optional: swap `__attribute__((noreturn))` for
  `[[noreturn]]`, drop `<stdbool.h>`.
- `src/c_emit/body.ts` — optional: emit `[[maybe_unused]]` on labels
  (achievable in C11 via the GNU attribute too).

## End-to-end verification (when executed)

1. `bun run typecheck` — TS sanity.
2. `bun src/index.ts build vader/cli/main.vader --release --target=native --out=/tmp/vader_c23 --keep-c` — rebuild the compiler.
3. `cc -std=c23 -O3 -DNDEBUG -I runtime/c /tmp/vader_c23.c runtime/c/vader_runtime.c -o /tmp/vader_c23 -lm` — manual compile check.
4. `bun test tests/native.test.ts` — native parity suite under the new standard.
5. `bun test` — full suite (snapshots, parity, leaks).
6. Cross-build probe if relevant: `bun src/index.ts build … --cc=x86_64-w64-mingw32-gcc` and verify the distributed MinGW accepts `-std=c23`.
