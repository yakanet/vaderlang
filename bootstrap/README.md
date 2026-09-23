# bootstrap/ — C-seed bootstrap

Full design: [docs/BOOTSTRAP.md](../docs/BOOTSTRAP.md).

`bootstrap.c` is the C of `vader/bootstrap/bootstrap.vader` — a build-only
`<input.vader> → <output.c>` compiler — produced by `vader build --emit=c`.
Any C compiler turns it into **stage0**, which carries the full compilation
pipeline; the build then bootstraps in three stages to the shipped compiler. No
pre-existing `vader` toolchain needed — only a C compiler.

It is committed **uncompressed**, which is what lets git delta successive
reseeds: two consecutive seeds differ by ~0.1 % as C but 100 % as gzip bytes, so
the compressed form cost a full megabyte of history per reseed. Measured on four
real consecutive seeds, the pack goes from 4.3 MB to 1.6 MB.

## Build from the C seed

```sh
bash bootstrap/build.sh --dist     # seed → stage0 → stage1 → vader (stage2), + dist bundle
dist/vader-*/vader --version       # self-contained — runs from anywhere
```

Stages: `cc` the seed → `build/stage0`; stage0 emits the full compiler's C and the
script links it → `build/stage1`; `stage1 build --emit=executable` → `build/vader`
(= stage2, the deliverable). Override the compiler with `CC=clang`. The GC arenas
auto-grow, so self-compiling needs no env tuning.

## Scripts

- `build.sh` — the 3-stage bootstrap in one shot (logs each stage). Honours `$CC`
  (default `cc`, resolved to an absolute path and passed to stage1 via `--cc`).
  stage0 is a throwaway built `-O1` (`$STAGE0_CFLAGS`); stage1 and stage2 are built
  `-O3`+LTO, identically, because `verify.sh` compares their emission. `build/vader`
  is stage2. `--dist` bundles `dist/vader-<os>-<arch>/` (binary + lib/ + runtime/c)
  — a self-contained toolchain that runs from any directory (the binary resolves
  `lib/` + `runtime/c/` next to its own executable).
- `build.ps1` — Windows counterpart (mingw-w64 gcc/clang). Run with
  `powershell -ExecutionPolicy Bypass -File bootstrap\build.ps1` ; `-CC clang`
  picks a different compiler, `-Dist` bundles `dist\vader-windows-<arch>\`.
- `verify.sh` — fixed-point check: builds the toolchain via `build.sh`, then
  confirms stage1 and stage2 emit identical C for `main.vader` (release and debug)
  and that two builds of the same input are byte-identical.
- `seed.sh` — the seed's lifecycle, in two subcommands.
  - `seed.sh check [--quiet]` — **owns** the question "does the committed seed
    still bootstrap HEAD?". It exports HEAD under `build/seed.viability/` and runs
    `verify.sh` there (~1 min), so neither an uncommitted edit nor the checkout's
    `build/vader` is involved. Exit `0` viable, `1` broken, `2` could-not-tell (no
    C compiler, a tree missing — never reported as "broken"). A viable verdict
    is stamped in `build/seed.viable` with the git objects it depends on (the
    seed's sources, the seed, `build.sh`, `verify.sh`); while they do not move,
    `check` answers at once.
  - `seed.sh regenerate` — re-emit the seed from `bootstrap.vader` (needs a
    `vader` binary + a clean tree across every source dir the seed depends on, not
    just `vader/`: the seed embeds the stdlib it compiled). A binary older than
    the sources first builds the tree, and the seed is emitted from the result —
    which is also the way out when the committed seed no longer bootstraps. Commit the bump as a separate `chore(bootstrap): bump seed` commit.
    A no-op when the seed comes out byte-identical — it leaves `VERSION` untouched
    rather than manufacturing a diff. `VERSION`'s `vader_source_sha` is the commit
    the seed was emitted at, i.e. its age.

## Reseed only when the seed stops working

The seed is a bootstrap tool: it has to build the current tree, not to be what
the current tree would emit. `build.sh` ships stage2 — the tree compiled by the
tree — so the seed's age never reaches the shipped binary. A seed two weeks old
produces a byte-identical compiler; see
`.claude/plans/2026-09-23-seed-viability.md` for the measurements.

A reseed is due when `seed.sh check` says `1` — typically after a breaking change
the old stage0 cannot compile. Enable the safety net once per clone:

```sh
git config core.hooksPath .githooks     # activates .githooks/pre-push
```

The hook runs `seed.sh check` and blocks the push on `1` (`--no-verify` bypasses
it); `bootstrap/seed.sh regenerate` then reseeds from the last `build/vader`,
even when `build.sh` can no longer produce one from the old seed.

The lsp / formatter / interpreter are outside `bootstrap.vader`'s closure by
design, so growing them never breaks the seed.
