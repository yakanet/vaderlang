# bootstrap/ — C-seed bootstrap

Full design: [docs/BOOTSTRAP.md](../docs/BOOTSTRAP.md).

`bootstrap.c` is the C of `vader/bootstrap/bootstrap.vader` — a build-only
`<input.vader> → <output.c>` compiler — produced by `vader build --target=c`.
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
script links it → `build/stage1`; `stage1 build --target=native` → `build/vader`
(= stage2, the deliverable). Override the compiler with `CC=clang`. The GC arenas
auto-grow, so self-compiling needs no env tuning.

## Scripts

- `build.sh` — the 3-stage bootstrap in one shot (logs each stage). Honours `$CC`
  (default `cc`, resolved to an absolute path and passed to stage1 via `--cc`).
  stage0 & stage1 are throwaways built `-O0` (`$STAGE0_CFLAGS`); only stage2/`vader`
  is `-O3`. `--dist` bundles `dist/vader-<os>-<arch>/` (binary + stdlib + runtime/c) —
  a self-contained toolchain that runs from any directory (the binary resolves
  `stdlib/` + `runtime/c/` next to its own executable).
- `build.ps1` — Windows counterpart (mingw-w64 gcc/clang). Run with
  `powershell -ExecutionPolicy Bypass -File bootstrap\build.ps1` ; `-CC clang`
  picks a different compiler, `-Dist` bundles `dist\vader-windows-<arch>\`.
- `regenerate.sh` — re-emit the seed from `bootstrap.vader` (needs a `vader`
  binary + a clean `vader/` tree). Commit the bump as a separate
  `chore(bootstrap): bump seed` commit. A no-op when the seed comes out
  byte-identical — it leaves `VERSION` untouched rather than manufacturing a diff.
- `check-seed.sh` — is the committed seed what the current sources would emit?
  `0` fresh, `1` stale, `2` could-not-tell (no usable compiler). ~4 s.
- `push.sh` — push, reseeding and committing first if the seed is stale. The
  one-command path for the per-push reseed cadence; arguments go to `git push`.
- `verify.sh` — fixed-point check: builds the toolchain via `build.sh`, then
  confirms stage1 and stage2 emit identical C for `main.vader` and the committed
  seed is fresh.

## Reseed cadence — once per push

Reseed at the **push** boundary, not after every chantier: batching that way takes
the accumulated history from 460 KB to 60 KB over the same development interval
(−87 %, measured on 8 real consecutive seeds). Use `push.sh`, and enable the
safety net once per clone:

```sh
git config core.hooksPath .githooks     # activates .githooks/pre-push
```

The hook blocks a plain `git push` when the seed is stale (`--no-verify` bypasses
it). Full rationale in docs/BOOTSTRAP.md § "Who bumps, and when".

Regenerate the seed only when the compilation pipeline reachable from
`bootstrap.vader` changes — see docs/BOOTSTRAP.md § "Seed lifecycle management".
The lsp / formatter / interpreter are excluded by design, so growing them never
bumps the seed.
