# Bootstrap — `bootstrap.c` seed

> **Implemented (2026-06-06) — read before the per-Phase prose below.** The build is now a
> **3-stage bootstrap**: `cc` the seed → `build/stage0`, stage0 → `build/stage1`, then
> `stage1 build --target=native` → `build/vader` (stage2, the shipped compiler). The built
> compiler resolves `stdlib/` + `runtime/c/` **next to its own executable** (the `std/io`
> intrinsics `current_executable_location` / `current_working_dir`, with a cwd fallback), so a
> `bash bootstrap/build.sh --dist` bundle runs from any directory. `bootstrap/{build.sh,build.ps1,verify.sh}`
> are the source of truth. **The per-Phase prose below predates this**: it still calls the *seed
> binary* `stage1` (now `stage0`) and describes cwd-relative resolution.

This document plans the move to a **C-seed bootstrap** : a committed,
versioned, gzip-compressed `bootstrap/bootstrap.c.gz` file produced by the
**self-hosted** Vader compiler, which any C compiler can build into a working
`vader` binary without needing Bun, the TS toolchain, or a pre-existing Vader
toolchain.

The seed is **not** the whole CLI compiler. It is the C mirror of a dedicated
build-only entrypoint, **`vader/bootstrap/bootstrap.vader`** (see *Architecture*
and its dedicated phase below). This keeps the seed small and — more importantly —
**stable** : it only re-bumps when the compilation pipeline changes, never when
the lsp, the formatter, or the rest of the CLI grows.

This is the doc referenced by TODO §2.8 ("Freeze the TS compiler") and
the plan that operationalises §2.7 ("Bootstrap success check").
**Committing the seed + green CI is the precondition for deleting `src/`.**

**Goal** : a contributor (or a CI job) clones the repo, runs
`bash bootstrap/build.sh` (gunzip → `cc` with the external runtime), and gets a
compiler capable of rebuilding itself from `vader/cli/main.vader`.

**Why this approach** : aligns the in-repo bootstrap with the backend
we already maintain (C emit), removes the Bun/TS dependency from the
cold-start path, and matches the proven Nim / Chicken Scheme pattern.

---

## Status (2026-06-05)

| Item | State |
|---|---|
| Self-host port §2.1-2.7 + fixed-point byte-identical | ✅ done (via `dump --stage=c` + external `cc`) |
| Codegen determinism (Phase 0) | ✅ effective (byte-identical proves it) |
| **`cmd_build` self-hosted (`vader build`)** | ✅ wired — `--target=c` + `--target=native` (commit 2c055e00) |
| `--target=c` wired in `cmd_build` | ✅ done (`build_c`, `--out=-` streams to stdout) |
| Cleanliness: `op.vader → vader/bytecode` | ✅ done (commits 77030406 + 544838eb) — went further: one-way `vm → bytecode` layering |
| `vader/bootstrap/bootstrap.vader` (seed source) | ✅ created (commit 5aede7e9) |
| `bootstrap/` layout + scripts (`build`/`regenerate`/`verify`) + `.gitattributes` | ✅ done (commit 7655e1dc) — validated end-to-end (755 KB seed, `verify.sh` green) |
| `--bundle-runtime` flag | ❌ later (optional improvement, runtime linked externally for now) |
| **Commit the seed blob `bootstrap.c.gz`** | ✅ sealed (commit 5f718b89, 755 KB) — from HEAD aa48e9f3, fixed-point verified |
| CI integration (Phase 3) | ✅ done — merged into `.github/workflows/build.yml` (the CI workflow): a Bun-free `seed-rebuild` job every push + a gated `fixed-point` job |
| README narrative / §2.8 `src/` deletion | ❌ later |
| 3-stage build + next-to-exe resolution | ✅ done (2026-06-06) — see the note at the top of this file |

## Blocking prerequisite : wire `cmd_build` — ✅ DONE (commit 2c055e00)

The seed is emitted with **`vader build`**, the proper command — **not**
`dump --stage=c` (a debug tool). `cmd_build` was a stub ; it is now wired :

- **`--target=c`** — `build_c` writes the generated C to `--out` (default
  `<file>.c` ; `--out=-` streams to stdout for the gzip pipe). ✅
- **`--target=native`** — emits the `.c` next to the binary, then invokes `cc`
  (`--cc`, `--ldflags`) to link against the external `runtime/c/`. ✅
- `ir` / `ir-text` / `wasm` stay recognised-but-stubbed (`return 2`, with TODOs).

Diagnostics go to stderr ; an error-severity diagnostic aborts with exit 1.

## Cleanliness prerequisite : `op.vader → vader/bytecode` — ✅ DONE (commits 77030406 + 544838eb)

`op.vader` turned out to be a 160-export mega-file mixing three concerns
(opcodes + VM runtime values + the parsed-`.virt` module shape), not "the 127
opcodes". It was first split into three cohesive files (`op` / `value` /
`module`, all `module "vader/vm"`), then the opcode set (`Op`, op structs,
`ConstOp`, `const_op_of`, `ConvertTarget`) was moved into
`vader/bytecode/op.vader`, establishing a **one-way `vm → bytecode`** layering
(verified: nothing in `vader/bytecode` imports `vader/vm`).

Getting there required more than the naive `git mv` first assumed:

- `peephole.vader` (rewrites the VM's `BytecodeFunction.ops`) and the `.virt`
  writer moved **into** `vader/vm` — they operate on VM types, so leaving them
  in `vader/bytecode` would re-form a `bytecode ↔ vm` cycle. Renamed
  `parser.vader → virt_reader.vader`, `text.vader → virt_writer.vader`.
- The VM runtime values (`value.vader`) and parsed-module shape (`module.vader`)
  **stay** in `vader/vm` — moving them to `vader/bytecode` collides their generic
  names (`PrimitiveType`, `StructType`, `ArrayType`, …) with the compiler's own
  Type IR used inside `vader/bytecode`.
- `quote_string` + `write_op` (shared by the bytecode dumper and the vm writer)
  live in `vader/bytecode/dump.vader`, exported. VM files import the opcode set
  via a `bc :: import "vader/bytecode"` namespace alias.

See the memory note `vader_vm_bytecode_layering` for the full rationale (don't
re-attempt moving the values / parsed-module into `vader/bytecode`).

---

## Prerequisite : self-host complete

This plan **cannot be executed** before the self-host port is functional.
Required state on TODO.md :

- §2.1 (parser) — done
- §2.2 (C emitter port) — done
- §2.3 (bytecode emitter port) — done
- §2.4 (VM port) — done (or stubbed if not needed by `vader/cli/main.vader`)
- §2.5b (comptime port) — done
- §2.5c (lowerer port) — done
- §2.6 (typer port) — done
- §2.7 (fixed-point check : compiler_v1 == compiler_v2 == compiler_v3 with
  the TS compiler as the v0 anchor) — **passes**

In short : the self-hosted compiler must emit correct C for
`vader/cli/main.vader` and reproduce itself. This already holds today via
`dump --stage=c` + `cc` (fixed-point byte-identical). Exposing that emission as
`vader build --target=c` is the *Blocking prerequisite* above.

While the port is in progress, the TS compiler in `src/` remains the
development driver. `bootstrap.c.gz` is **only** generated and committed
once the self-hosted compiler is the source of truth.

---

## Architecture (post-bootstrap)

```
┌──────────────────────────────┐
│ vader/bootstrap/bootstrap.vader  (build-only entrypoint, seed source)
└────────────┬─────────────────┘
             │
             ▼  vader build --target=c --out=- | gzip -9   (cmd_build wired)
┌──────────────────────────────┐
│ bootstrap/bootstrap.c.gz  (committed seed, ~790 KB)
└────────────┬─────────────────┘
             │
             ▼  gunzip | cc -O2 - runtime/c/vader_runtime.c -Iruntime/c -o stage1
┌──────────────────────────────┐
│ stage1  (mini build-only compiler)
└────────────┬─────────────────┘
             │
             ▼  stage1 vader/cli/main.vader → main.c → cc
┌──────────────────────────────┐
│ build/vader  (FULL compiler, release candidate)
└──────────────────────────────┘
```

- **`bootstrap/bootstrap.c.gz`** — gzip-compressed C translation unit, the
  mirror of `vader/bootstrap/bootstrap.vader`, generated by the current Vader
  compiler. Committed in-tree, marked `binary` via `.gitattributes`. The runtime
  is linked **externally** (`runtime/c/`), not bundled (see Phase 2).
- **stage1** — a build-only compiler produced by compiling the decompressed seed
  with a plain C compiler. It carries the entire pipeline, so it can compile any
  `.vader` — including `vader/cli/main.vader`.
- **build/vader** — the full compiler, produced by stage1 rebuilding the current
  source.

Why a dedicated `bootstrap.vader` rather than seeding from `main.vader` : the seed
then **decouples from the CLI**. Growing the lsp / formatter / `run` no longer
bumps the seed — only pipeline changes do. Smaller size is a side benefit (~3 % ;
the dominant size lever is gzip, 11×). See *Alternatives considered*.

Storage strategy is **same-repo with `.gitattributes`** (decided over
separate-repo / release-artefact alternatives — see *Migration paths*
for escape hatches if growth pressure ever flips that decision).

---

## The seed source : `vader/bootstrap/bootstrap.vader`

The seed compiles from a **dedicated build-only entrypoint**, not from
`vader/cli/main.vader`. This is the central piece of the new design.

**Role** — a minimal compiler (~30-50 LoC) whose only job is
`<input.vader> → <output.c>`. It reuses the exact pipeline of the full compiler
(`prepare_cfg_bytecode` + `emit_c`, duplicated from `main.vader` since the project
keeps the two entrypoints separate rather than extracting a shared module).

**Imports** — pipeline only :
`resolver`, `typecheck`, `comptime`, `lower`, `midir`, `bytecode`, `c_emit`,
`diagnostics`. It **must not** import `vader/vm`, `vader/fmt`, or `vader/lsp` —
that exclusion is the whole point (it is what decouples the seed from the CLI and
keeps it stable as those modules grow).

**Capability** — because it carries the full pipeline, `stage1` (compiled from it)
can compile *any* `.vader`, including `main.vader` → the full compiler. "Mini"
refers to its CLI surface, not its compilation capability.

Skeleton :

```vader
module "vader/bootstrap"

import "vader/midir"  { ... }
import "vader/c_emit" { emit_c, EmitOptions }
// pipeline imports only — NOT vader/vm, vader/fmt, vader/lsp

main :: fn(args: string[]) -> i32 {
    // args : <input.vader> <output.c>
    b :: prepare_cfg_bytecode(args[0])   // pipeline duplicated from main.vader
    write_file(args[1], emit_c(b.module, EmitOptions { .entry_mangled = b.entry }))
    return 0
}
```

Note : the pipeline helpers (`lower_to_entry`, `prepare_cfg_bytecode`,
`prepare_evaluated_project`, `entry_main_name`, `gather_pipeline_diags`,
`module_name_from_file`) currently live in `vader/cli/main.vader`. The duplication
they require is a deliberate trade-off (no shared `driver` module) ; `verify.sh`
(self-reproduction) catches a stale `bootstrap.vader`.

---

## Phase 0 — Codegen determinism prerequisites

A committed seed is only viable if the C codegen is **stable** : small
source changes must produce small textual changes in `bootstrap.c`.
Without this, every bump produces a near-complete rewrite and git's
delta compression cannot reclaim the bytes.

JS/TS `Map` and `Set` already guarantee insertion-order iteration, so
there is no true non-determinism — but several iteration sites in
`src/c_emit/` produce textually fragile output when the upstream
bytecode reorders inputs. The four fixes below convert insertion-order
fragility into canonical (sorted) order.

### Timeline

These fixes have a **two-stage rollout** :

1. **Now (in TS, before §2.2 port)** — apply to `src/c_emit/`. Two
   wins : the current TS-generated C becomes stable (useful for
   reproducibility today, and shrinks future diff noise when comparing
   ports against the TS reference), and the §2.2 port lands against a
   clean canonical design rather than copying a fragile one.
2. **After §2.2 (in Vader)** — verify the same canonicalisations are
   present in `vader/c_emit/`. Mirror, don't re-audit. Snapshot parity
   tests catch regressions either way.

### Fix 1 — vtable signature anchor (CRITICAL)

**Location** : `src/c_emit/ops.ts:126, 142, 170` (and the Vader port's
equivalent post-§2.2)

```typescript
const firstFnIdx = table.values().next().value;
```

Picks the first-inserted impl in each vtable as the canonical
signature source. Adding any new impl earlier in the bytecode pipeline
flips this anchor and rewrites every dispatcher's signature.

**Fix** : pick the impl with the smallest `fnIdx` (stable, independent
of insertion order) :

```typescript
const firstFnIdx = Math.min(...table.values());
```

### Fix 2 — vtable dispatcher case order (HIGH)

**Location** : `src/c_emit/ops.ts:180`

```typescript
for (const [tag, fnIdx] of table) { /* emits switch cases */ }
```

`case` arm order in the generated `switch` follows insertion order.
Inserting a new impl mid-list shifts all subsequent cases.

**Fix** : sort by tag before emitting :

```typescript
const entries = [...table].sort((a, b) => a[0] - b[0]);
for (const [tag, fnIdx] of entries) { … }
```

### Fix 3 — trait check tag lists (LOW)

**Location** : `src/c_emit/emit.ts:117-122`

`structIdxsByTrait` lists are built from `implTable` iteration order.
The resulting `tag == X || tag == Y` chains in `traitCheckExpr` change
order whenever upstream insertion order changes.

**Fix** : sort each list after construction :

```typescript
for (const list of structIdxsByTrait.values()) list.sort((a, b) => a - b);
```

### Fix 4 — local declaration grouping (LOW)

**Location** : `src/c_emit/body.ts:200-210`

`buckets: Map<ValType, number[]>` iterates in first-appearance order.
A signature change that introduces a new type earlier reorders the
local prologue.

**Fix** (optional, cosmetic) : iterate `ValType` in a canonical order :

```typescript
const ORDER: ValType[] = ["i32", "i64", "f32", "f64", "ref", "any"];
for (const val of ORDER) {
  const slots = buckets.get(val); if (!slots) continue;
  /* emit */
}
```

### Acceptance

- The same input bytecode compiled twice produces byte-identical C
  (locked-in invariant ; already true today).
- Adding a new trivial Vader function to a leaf module changes
  `bootstrap.c` by **at most that function's emission** — no cascading
  reordering of vtables, dispatchers, or trait checks elsewhere.

---

## Phase 1 — Directory layout

The seed **source** lives under the compiler tree at
`vader/bootstrap/bootstrap.vader` (see *The seed source* above). The `bootstrap/`
directory at the repo root holds the generated seed and the tooling :

```
bootstrap/
├── bootstrap.c.gz     — the seed (generated, gzip-compressed, committed)
├── VERSION            — metadata about the seed
├── regenerate.sh      — regenerate bootstrap.c.gz from vader/bootstrap/bootstrap.vader
├── build.sh           — gunzip + cc (external runtime) → ./build/stage1
├── verify.sh          — fixed-point check (Phase 4, on-demand)
└── README.md          — terse usage, points to docs/BOOTSTRAP.md
```

`VERSION` contents :

```
vader_source_sha: <git rev-parse HEAD when regenerated>
vader_version:    <contents of vader/version.vader at regen time>
regenerated_at:   <ISO date>
generator:        <vader binary path + --version output>
```

`.gitattributes` at repo root :

```
bootstrap/bootstrap.c.gz   binary linguist-generated=true
```

The `binary` macro expands to `-diff -merge -text` :
- `-diff` hides the seed in `git diff` and PR views
- `-merge` skips 3-way merge attempts (meaningless on a generated blob)
- `-text` disables line-ending normalisation across platforms

---

## Phase 2 — Regeneration tooling

### Decision : external runtime link to start (bundling is a later improvement)

The seed links the C runtime **externally** to begin with —
`cc bootstrap.c runtime/c/vader_runtime.c -Iruntime/c -o stage1`. This needs
**zero new compiler code** (no `--bundle-runtime` flag), and `runtime/c/` is
already in the repo. Trade-offs :

| Aspect | External link (chosen to start) | Bundled (later) |
|---|---|---|
| Build command | `cc bootstrap.c runtime/c/vader_runtime.c -Iruntime/c -o stage1` | `cc bootstrap.c -o stage1` |
| New compiler code | none | `--bundle-runtime` to write |
| Truly standalone | no (needs `runtime/c/`) | yes |
| Size | smaller .c | larger (one-shot full TU) |
| Drift risk | seed can desync from runtime sources | none |

The "one file, no flags" bundled form stays the eventual target (it de-risks the
§2.8 deletion of `src/`), but it is reclassified as an *Improvement* — **not** a
blocker for the first seed.

### `bootstrap/regenerate.sh`

```sh
#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

# Require a clean working tree on vader/ so the recorded SHA is meaningful.
if ! git diff-index --quiet HEAD -- vader/; then
  echo "error: vader/ has uncommitted changes — commit first" >&2
  exit 1
fi

# Requires a working `vader` binary on PATH (or in ./build/). Build one
# from sources if needed via the existing toolchain.
if ! command -v vader >/dev/null && [ ! -x ./build/vader ]; then
  echo "error: no vader binary available. Build one first." >&2
  echo "  pre-bootstrap path : bun src/index.ts build vader/cli/main.vader --release --out=build/vader" >&2
  echo "  post-bootstrap path: bootstrap/build.sh && build/stage1 vader/cli/main.vader build/main.c && cc build/main.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/vader" >&2
  exit 1
fi
VADER="${VADER:-$(command -v vader || echo ./build/vader)}"

# Emit the seed source (build-only entrypoint) to C, then gzip it.
# `cmd_build --target=c` must be wired — see the Blocking prerequisite.
mkdir -p build
"$VADER" build vader/bootstrap/bootstrap.vader --target=c --out=build/bootstrap.c
gzip -9 -c build/bootstrap.c > bootstrap/bootstrap.c.gz

cat > bootstrap/VERSION <<EOF
vader_source_sha: $(git rev-parse HEAD)
vader_version:    $(grep -E '^[[:space:]]*VERSION' vader/version.vader | head -1)
regenerated_at:   $(date -u +%Y-%m-%dT%H:%M:%SZ)
generator:        $VADER ($("$VADER" --version))
EOF

echo "seed regenerated. review the decompressed diff:"
echo "  diff <(git show HEAD:bootstrap/bootstrap.c.gz | gunzip -c) build/bootstrap.c"
echo "confirm it's localised, then commit:"
echo "  git add bootstrap/bootstrap.c.gz bootstrap/VERSION"
echo "  git commit -m 'chore(bootstrap): bump seed'"
```

Implementation note : the seed source is `vader/bootstrap/bootstrap.vader`
(build-only), **not** `vader/cli/main.vader`. `vader build --target=c --out=<path>`
must be wired in `cmd_build` first (Blocking prerequisite). The runtime stays
**external** (no bundling) — `build.sh` links `runtime/c/` at `cc` time.

### `bootstrap/build.sh`

```sh
#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

mkdir -p build
gunzip -c bootstrap/bootstrap.c.gz > build/bootstrap.c
cc -O2 -o build/stage1 build/bootstrap.c runtime/c/vader_runtime.c -Iruntime/c -lm

echo "stage1 built at build/stage1"
echo "smoke test (stage1 compiles a trivial snippet to C):"
./build/stage1 tests/snippets/return_42/_main.vader build/_smoke.c && echo "  ok"
```

The contract : `gunzip -c bootstrap/bootstrap.c.gz | cc -O2 -x c -
runtime/c/vader_runtime.c -Iruntime/c -lm -o stage1`. `runtime/c/` is the only
sidecar required (external link — see the Phase 2 decision). `stage1` is the
build-only compiler : it takes `<input.vader> <output.c>`, so the smoke test
compiles a snippet rather than running `--version`.

### The very first seed (transition step)

The first time `bootstrap.c.gz` is generated, you need a working Vader binary
**with `cmd_build` wired**. At that point the TS compiler is still present
(deletion happens at §2.8, **after** this plan succeeds). Sequence :

0. (Prerequisite) Wire `cmd_build --target=c` in `vader/cli/main.vader`, and
   create `vader/bootstrap/bootstrap.vader`.
1. Build a Vader binary via TS one last time (now carries the wired `cmd_build`) :
   `bun src/index.ts build vader/cli/main.vader --release --out=build/vader-via-ts`
2. Emit the first seed from the build-only entrypoint :
   `VADER=./build/vader-via-ts bootstrap/regenerate.sh`
   (or, equivalently, emit straight from TS :
   `bun src/index.ts build vader/bootstrap/bootstrap.vader --target=c --out=build/bootstrap.c && gzip -9 -c build/bootstrap.c > bootstrap/bootstrap.c.gz`).
3. Build stage1 from that seed : `bootstrap/build.sh`.
4. Run §2.7 fixed-point checks (Phase 4 / `bootstrap/verify.sh`) and
   confirm the seed and `main.c` reproduce byte-identical.
5. Commit `bootstrap/bootstrap.c.gz` + `bootstrap/VERSION`.
6. Subsequent regenerations use `bootstrap/build.sh` output (stage1) or a
   previously-installed `vader` — the TS compiler is never the generator again.

---

## Phase 3 — CI integration — ✅ DONE (`.github/workflows/build.yml`)

CI lives in the unified `.github/workflows/build.yml` workflow. A Bun-free
`seed-rebuild` job runs on each push — it turns the seed into the full compiler
(3-stage bootstrap) and smoke-tests it — plus a heavier `fixed-point` job
(`verify.sh`) gated to `workflow_dispatch` and release tags. Neither installs
Bun, Node, or a pre-installed `vader` — only a C compiler and `gzip`. (The Bun
`test` / `dist` jobs in the same file are separate, isolated jobs.)

The `rebuild` job, running on each push :

1. `gunzip -c bootstrap/bootstrap.c.gz > build/bootstrap.c`
2. `cc -O2 build/bootstrap.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/stage1`
3. `./build/stage1 vader/cli/main.vader build/main.c` — stage1 emits the FULL compiler's C
4. `cc -O2 build/main.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/vader`
5. `./build/vader --version` smoke test
6. (Optional gate) `./build/vader test …` — sanity check against the
   snippet suite

This validates two invariants on every push :
- The committed seed still compiles with a stock C toolchain.
- The seed is functionally complete enough to rebuild the compiler.

A drift between source and seed (e.g., bytecode-format change without
seed regeneration, runtime ABI break) makes CI fail loudly at step 3.

The CI **does not** require Bun, Node, or any pre-installed `vader`.
Only a C compiler and `gzip`. That is the whole point.

---

## Phase 4 — Fixed-point verification

This formalises TODO §2.7 as a script.

`bootstrap/verify.sh` — not run on every push, available on demand
and on releases :

```sh
#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

./bootstrap/build.sh                                       # build/stage1 (from seed)

# stage1 (build-only) emits the FULL compiler's C, then we cc it.
./build/stage1 vader/cli/main.vader build/main1.c
cc -O2 -o build/vader build/main1.c runtime/c/vader_runtime.c -Iruntime/c -lm

# (a) full-compiler self-reproduction : vader re-emits main.vader, must match.
./build/vader build vader/cli/main.vader --target=c --out=build/main2.c
if ! cmp -s build/main1.c build/main2.c; then
  echo "FIXED-POINT FAILED — full compiler is not self-reproducing"
  diff -u build/main1.c build/main2.c | head -200
  exit 1
fi

# (b) seed freshness : vader re-emits bootstrap.vader, must match the committed seed.
./build/vader build vader/bootstrap/bootstrap.vader --target=c --out=build/bootstrap.new.c
if ! cmp -s build/bootstrap.new.c <(gunzip -c bootstrap/bootstrap.c.gz); then
  echo "STALE SEED — bootstrap.c.gz no longer matches bootstrap.vader; run regenerate.sh"
  exit 1
fi

echo "fixed-point OK : main.c reproduced byte-identical, seed up to date"
```

Invariants verified :
- The compiler is **self-reproducing** : a compiler built from the seed, used to
  rebuild `main.vader`, produces the same C as a fresh re-emit (`main1.c == main2.c`).
- The committed seed is **fresh** : re-emitting `bootstrap.vader` matches
  `bootstrap.c.gz` (decompressed) — no silent drift.
- The seed is not "lucky" — it represents a real fixed point of the pipeline.

Trigger :
- **Mandatory before committing the very first seed** (Phase 2 step 4).
- Manually before tagged releases.
- On `release/*` branch pushes via a separate `verify-bootstrap` workflow.

Too slow for every PR run.

### Validation log

- **2026-06-20** — compact-dict `MutableMap` + 4 follow-up chantiers. `verify.sh`
  green (`fixed-point OK : stage1 == stage2, seed up to date`) at all three reseed
  gates: (1) compact-dict + `Box` op, (2) legacy `emit_project` / chaining
  for-in fast-path removal, (3) generic struct field-default boxed-vs-raw fix.
  Full suite **2283 pass / 0 fail / 5 skip** at each gate. The 5 skips are all
  justified, none a regression: `defer_on_panic` / `defer_in_lambda` (VM
  defer-unwind deferred), `extern_native_basic` (VM has no `@extern` host-fn
  registry — permanent), and `vader/bytecode` (43/43) / `vader/lsp` (52/52)
  whose native `@test`s pass — only their VM run is skipped for the CI time
  budget.

---

## Seed lifecycle management

### When to bump

Regenerate `bootstrap.c.gz` when a change affects **the C that
`vader/bootstrap/bootstrap.vader` emits** — i.e. the compilation pipeline
reachable from it :

- `vader/{lexer,parser,resolver,typecheck,comptime,lower,midir,bytecode,c_emit}`
  gains or modifies behaviour exercised when compiling a `.vader` file
- `vader/c_emit/` changes the shape of generated C (output format, ABI,
  runtime call conventions)
- Bytecode / IR format changes
- the pipeline helpers duplicated inside `bootstrap.vader` itself change

The runtime is linked externally, so a `runtime/c/` change only forces a seed
bump when it changes the **emitted call shape** (a pure `.c` body change does not).

### When **not** to bump

- Tests-only changes (`tests/`, `vader/typecheck/*tests*.vader`, …)
- Documentation, comments, formatting
- **`vader/lsp/`, `vader/fmt/`, `vader/vm/`, and the parts of `vader/cli/` that
  `bootstrap.vader` does not import** — excluded from the seed by design, so
  growing them (e.g. the lsp) **never** bumps it. This is the whole point of a
  dedicated build-only entrypoint.
- Bug fixes that don't change emitted C — verify with a dry-run :
  if `regenerate.sh` produces a byte-identical seed, no bump needed.

### Who bumps

The contributor whose PR triggers the need. CI failure on step 3 (see
Phase 3) is the signal. If a PR changes the compiler such that the
seed becomes stale :

1. Run `bootstrap/regenerate.sh` locally (uses your installed `vader`
   or the one in `./build/`).
2. Inspect the decompressed diff (the seed is a gzip blob, so the textual
   diff must be on its expanded form) :
   `diff <(git show HEAD:bootstrap/bootstrap.c.gz | gunzip -c) build/bootstrap.c`.
   Confirm the change looks **localised and proportional** to your source change.
3. Commit the seed bump as a **separate commit** from the source
   change, with subject `chore(bootstrap): bump seed`. Easier to
   review and easier to revert if regen was premature.

### Bump frequency expectations

Early post-bootstrap, expect **several seed bumps per week** while the
compiler is still maturing. As the compiler stabilises, expect bumps
on the order of **once per release**.

### Repo growth budget

With Phase 0 fixes applied (and mirrored in the Vader port), expect
each bump to delta to **10-50 KB** in packfile size after `git gc`. At
200 bumps/year, that is 2-10 MB/y. If actual growth significantly
exceeds this — say, > 50 MB/year — the codegen has regressed on
stability ; revisit Phase 0 before falling back to a separate-repo
storage strategy (see *Migration paths* below).

---

## TS compiler deletion (§2.8)

Once Phases 0-4 are green and `bootstrap.c.gz` is committed, §2.8 is
unblocked. The deletion is a single PR :

1. Delete `src/` entirely.
2. Delete TS-only dev tooling : `tsconfig.json`, `@types/bun`,
   `typescript` from `package.json`.
3. Rewrite `package.json` scripts to drop `bun src/index.ts` references
   (or keep `package.json` only for the cloc / npm-script ergonomics
   even though there is no TS left — decide at deletion time).
4. Update README : replace "compiler bootstrapped in TypeScript" with
   a self-host narrative pointing to `bootstrap/`.
5. Remove TS-only test scaffolding under `tests/` (keep the Vader-side
   snippet harness).
6. Tag a release before deletion (`vN-final-ts`) for archeology.

Post-deletion, the **only** ways to acquire a `vader` binary are :

- Download a prebuilt release (a `dist/vader-<os>-<arch>/` bundle packaged
  via `bootstrap/build.sh --dist`).
- Build from source yourself via `bootstrap/build.sh` → stage1 → full `vader`.

There is no third path. That is the whole guarantee the seed provides.

---

## README documentation

`README.md` gets two updates :

### Replace the bootstrap narrative

The existing line "The compiler is being bootstrapped in TypeScript
and will later self-host in Vader." becomes :

> Vader is self-hosted. A committed, gzip-compressed C seed at
> `bootstrap/bootstrap.c.gz` lets any machine with a C compiler build the
> toolchain from source — see [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md).

### New subsection under `## Build from source`

> ### From the C seed (no Vader binary needed)
>
> ```sh
> bash bootstrap/build.sh                           # gunzip + cc → ./build/stage1
> ./build/stage1 vader/cli/main.vader build/main.c  # stage1 emits the full compiler's C
> cc -O2 build/main.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/vader
> ```
>
> The seed is the C of `vader/bootstrap/bootstrap.vader` (a build-only
> entrypoint) that `vader build --target=c` produces, gzip-compressed ; it is
> committed periodically when the compilation pipeline changes. CI validates on
> every push that the seed still builds and can rebuild the compiler. To
> regenerate the seed (contributor flow), see `docs/BOOTSTRAP.md` §
> *Seed lifecycle management*.

A contributing section (or `CONTRIBUTING.md`) should reference
`docs/BOOTSTRAP.md` for the bump procedure.

---

## Alternatives considered (and why they were dropped)

Measured 2026-06-05 on `build/vader.c` (the emitted C of the full compiler) :

| Lever | Effect on the seed | Verdict |
|---|---|---|
| **gzip -9** | 8.9 MB → ~790 KB (11×) | ✅ adopted — the size lever |
| mini-VM + committed bytecode | gzipped bytecode ≈ gzipped C ; **+~3000 LoC of C** to write/maintain ; `stage1` would be *interpreted* (slow) | ❌ no size win, more work |
| seed = full `vader/cli/main.vader` | +~3 % size ; **re-bumps on every lsp/fmt/cli change** | ❌ unstable seed |
| better stdlib DCE | stdlib = 4.4 % of the C and **already DCE'd** (`is_stdlib_path`) ; headroom < 4 % | ❌ essentially already done |

Why the format and the pruning barely matter : the seed is **dominated by the
build pipeline** (parser / typecheck / lower / midir / comptime / c_emit), which
is irreducible by construction ; compressed, C and bytecode weigh the same ; and
gzip reabsorbs removed code. So the dedicated build-only entrypoint
(`bootstrap.vader`) is chosen for **stability and traceability** of the seed, not
for bytes — while **gzip** does the size work.

## Migration paths (if growth becomes a problem)

If pack-file size grows beyond the budget above, escape hatches are
non-breaking for the user-facing `bootstrap/build.sh` contract — only
`bootstrap.c.gz` *acquisition* changes :

1. **Separate repo** (`vaderlang2-seed`) — Nim's `csources_v2` pattern.
   Main repo references a SHA in `bootstrap/VERSION`, `bootstrap/build.sh`
   curls the tarball. Migration : `git filter-repo` purges
   `bootstrap.c.gz` history from this repo, moves it to the new repo.

2. **GitHub Release artefact** — `bootstrap.c.gz` published as an asset
   on a `bootstrap-v<N>` tag, `bootstrap/build.sh` downloads it. No
   second repo, GC-able by deleting old releases. Trade-off : harder
   offline / air-gapped builds.

---

## Order of work

Strictly sequential (each step gates the next) :

1. **Self-host port + fixed-point** (TODO §2.1-2.7) — ✅ done. Phase 0 codegen
   determinism is effective (byte-identical proves it).
2. **Wire `cmd_build`** (`--target=c` minimum) in `vader/cli/main.vader` —
   **blocking prerequisite** ; promote `run_c_stage` into a real `build` command
   writing `--out`.
3. **Cleanliness refactor** `op.vader → vader/bytecode` — recommended, ~1 file
   moved + ~15 import edits.
4. **Create `vader/bootstrap/bootstrap.vader`** (build-only entrypoint, pipeline
   duplicated, no `vm`/`fmt`/`lsp`).
5. **Phase 1 layout** (`bootstrap/` + scripts) + `.gitattributes` on the `.gz`.
6. **First seed generation + verify** (Phase 2 *very first seed* + Phase 4
   verify) — emit via `vader build --target=c`, gzip, external runtime.
7. **Phase 3 CI job** — once `build.sh` works.
8. **README update** — alongside Phase 3 going green.
9. **§2.8 TS deletion PR** — separate PR, mechanical.

(`--bundle-runtime` one-file seed is an optional improvement, not on this path.)
