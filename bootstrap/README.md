# bootstrap/

The committed C seed, and the scripts that build the compiler from it with only a
C compiler. [`docs/BOOTSTRAP.md`](../docs/BOOTSTRAP.md) describes them.

```sh
bash bootstrap/build.sh --dist   # seed → stage0 → stage1 → build/vader, and a bundle in dist/
bash bootstrap/verify.sh         # the fixed point: stage1 and stage2 emit the same C
bootstrap/seed.sh check          # does the committed seed still bootstrap HEAD?
bootstrap/seed.sh regenerate     # emit a new seed, when check says the old one is broken
```

On Windows, `bootstrap\build.ps1` does the same: see [`README.md`](../README.md),
*On Windows*.

`git config core.hooksPath .githooks` enables the pre-push hook, which runs
`seed.sh check` and blocks a push the committed seed cannot bootstrap.

| File | Role |
|---|---|
| `seed/` | the seed: the units every target shares, and under `<os>-<arch>/` those that differ |
| `VERSION` | the commit the seed was emitted from |
| `build.sh`, `build.ps1` | the three-stage build |
| `verify.sh` | the fixed-point check |
| `seed.sh` | `check` and `regenerate` |
| `dist-exclude.txt` | the directories of `vader/` a bundle leaves out |
