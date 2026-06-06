# bootstrap/ — C-seed bootstrap

Full design: [docs/BOOTSTRAP.md](../docs/BOOTSTRAP.md).

`bootstrap.c.gz` is the gzip-compressed C of `vader/bootstrap/bootstrap.vader`
— a build-only `<input.vader> → <output.c>` compiler — produced by
`vader build --target=c`. Any C compiler can turn it into `stage1`, which
carries the full compilation pipeline and rebuilds the whole compiler from
`vader/cli/main.vader`. No pre-existing `vader` toolchain needed — only a C
compiler and `gzip`.

## Build from the C seed

```sh
bash bootstrap/build.sh     # seed → stage1 → full compiler at build/vader (override cc with CC=clang)
./build/vader --version
```

(The GC arenas auto-grow, so compiling `vader/cli/main.vader` — the largest
self-input — needs no special environment tuning.)

## Scripts

- `build.sh` — the whole chain in one shot: decompress the seed, compile
  `stage1`, then have `stage1` rebuild the full compiler → `build/vader`.
  Step-by-step logs ; honours `$CC` / `$CFLAGS` (defaults `cc` / `-O2`).
- `build.ps1` — Windows counterpart of `build.sh` (mingw-w64 gcc/clang ;
  decompresses the seed via .NET `GZipStream`, so no `gzip` is needed). Run with
  `powershell -ExecutionPolicy Bypass -File bootstrap\build.ps1` ; `-CC clang`
  picks a different compiler.
- `regenerate.sh` — re-emit the seed from `bootstrap.vader` (needs a `vader`
  binary). Commit the bump as a separate `chore(bootstrap): bump seed` commit.
- `verify.sh` — fixed-point check: builds the full compiler via `build.sh`, then
  checks it reproduces itself + the seed byte-for-byte.

Regenerate the seed only when the compilation pipeline reachable from
`bootstrap.vader` changes — see docs/BOOTSTRAP.md § "Seed lifecycle management".
The lsp / formatter / interpreter are excluded by design, so growing them never
bumps the seed.
