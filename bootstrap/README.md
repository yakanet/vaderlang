# bootstrap/ — C-seed bootstrap

Full design: [docs/BOOTSTRAP.md](../docs/BOOTSTRAP.md).

`bootstrap.c.gz` is the gzip-compressed C of `vader/bootstrap/bootstrap.vader`
— a build-only `<input.vader> → <output.c>` compiler — produced by
`vader build --target=c`. Any C compiler can turn it into `stage1`, which
carries the full compilation pipeline and rebuilds the whole compiler from
`vader/cli/main.vader`. No Bun, no TypeScript, no pre-existing `vader` needed —
only a C compiler and `gzip`.

## Build from the C seed

```sh
bash bootstrap/build.sh                            # gunzip + cc → build/stage1
./build/stage1 vader/cli/main.vader build/main.c   # stage1 emits the full compiler's C
cc -O2 build/main.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/vader
```

(For self-input — compiling `vader/cli/main.vader` — raise the GC arenas, e.g.
`VADER_GC_YOUNG_BYTES=$((256*1024*1024)) VADER_GC_OLD_BYTES=$((1024*1024*1024))`.)

## Scripts

- `build.sh` — gunzip the seed + `cc` → `build/stage1` (+ smoke test).
- `regenerate.sh` — re-emit the seed from `bootstrap.vader` (needs a `vader`
  binary). Commit the bump as a separate `chore(bootstrap): bump seed` commit.
- `verify.sh` — fixed-point check: stage1 rebuilds the compiler, and the
  compiler reproduces itself + the seed byte-for-byte.

Regenerate the seed only when the compilation pipeline reachable from
`bootstrap.vader` changes — see docs/BOOTSTRAP.md § "Seed lifecycle management".
The lsp / formatter / interpreter are excluded by design, so growing them never
bumps the seed.
