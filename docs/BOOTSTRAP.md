# Bootstrap — `bootstrap.c` seed

> **Reseed model changed (2026-09-23): the seed only has to WORK, not to be fresh.**
> § *Seed lifecycle management* and § *Phase 4* are current; anything elsewhere
> about a "byte-fresh" seed or a reseed per push predates this.
>
> **Storage format changed (2026-07-28).** The seed is committed **uncompressed**
> as `bootstrap/bootstrap.c`; it was `bootstrap.c.gz` until then. Nothing about the
> bootstrap *chain* changed — only how the artefact is stored, and `gzip` is no
> longer a build dependency. **Every `.gz` / `gunzip` mention in the per-Phase
> prose below predates this.** See § *Why the seed is stored uncompressed*.
>
> **Implemented (2026-06-06) — read before the per-Phase prose below.** The build is now a
> **3-stage bootstrap**: `cc` the seed → `build/stage0`, stage0 → `build/stage1`, then
> `stage1 build --emit=executable` → `build/vader` (stage2, the shipped compiler). The built
> compiler resolves `lib/` + `runtime/c/` **next to its own executable** (the `std/io`
> intrinsics `current_executable_location` / `current_working_dir`, with a cwd fallback), so a
> `bash bootstrap/build.sh --dist` bundle runs from any directory. `bootstrap/{build.sh,build.ps1,verify.sh}`
> are the source of truth. **The per-Phase prose below predates this**: it still calls the *seed
> binary* `stage1` (now `stage0`) and describes cwd-relative resolution.

This document plans the move to a **C-seed bootstrap** : a committed, versioned
`bootstrap/seed/` tree produced by the **self-hosted** Vader compiler,
which any C compiler can build into a working `vader` binary without needing
Bun, the TS toolchain, or a pre-existing Vader toolchain.

The seed is **not** the whole CLI compiler. It is the C mirror of a dedicated
build-only entrypoint, **`vader/bootstrap/bootstrap.vader`** (see *Architecture*
and its dedicated phase below). This keeps the seed small and — more importantly —
**stable** : it only re-bumps when the compilation pipeline changes, never when
the lsp, the formatter, or the rest of the CLI grows.

This is the doc referenced by TODO §2.8 ("Freeze the TS compiler") and
the plan that operationalises §2.7 ("Bootstrap success check").
**Committing the seed + green CI is the precondition for deleting `src/`.**

**Goal** : a contributor (or a CI job) clones the repo, runs
`bash bootstrap/build.sh` (`cc` with the external runtime), and gets a
compiler capable of rebuilding itself from `vader/cli/main.vader`.

> ⚠️ **NOTHING VERIFIES THIS AUTOMATICALLY ANY MORE** (2026-08-30). The
> `seed-rebuild` job that did was removed as a duplicate of `Test`'s own
> bootstrap — which it is on the surface: both run `bash bootstrap/build.sh`.
> What differed is the ENVIRONMENT. `seed-rebuild` installed nothing;
> `Test` runs `oven-sh/setup-bun@v2` first, and the Windows job needs Bun too.
> So the day the bootstrap starts depending on Bun, Node, or anything that
> setup drags in, every remaining job has it in hand and none of them notices.
>
> The goal above is now a claim this document makes and no job checks. Restoring
> it costs one job that installs nothing and runs `bash bootstrap/build.sh`.
> Until then, a contributor cloning with only a `cc` is trusting prose.

**Why this approach** : aligns the in-repo bootstrap with the backend
we already maintain (C emit), removes the Bun/TS dependency from the
cold-start path, and matches the proven Nim / Chicken Scheme pattern.

---

## Status (2026-06-05)

| Item | State |
|---|---|
| Self-host port §2.1-2.7 + fixed-point byte-identical | ✅ done (via `dump --stage=c` + external `cc`) |
| Codegen determinism (Phase 0) | ✅ effective (byte-identical proves it) |
| **`cmd_build` self-hosted (`vader build`)** | ✅ wired — `--emit=c` + `--emit=executable` (commit 2c055e00) |
| `--emit=c` wired in `cmd_build` | ✅ done (`build_c`, `--out=-` streams to stdout) |
| Cleanliness: `op.vader → vader/bytecode` | ✅ done (commits 77030406 + 544838eb) — went further: one-way `vm → bytecode` layering |
| `vader/bootstrap/bootstrap.vader` (seed source) | ✅ created (commit 5aede7e9) |
| `bootstrap/` layout + scripts (`build`/`regenerate`/`verify`) + `.gitattributes` | ✅ done (commit 7655e1dc) — validated end-to-end (755 KB seed, `verify.sh` green) |
| `--bundle-runtime` flag | ❌ later (optional improvement, runtime linked externally for now) |
| **Commit the seed blob `bootstrap.c.gz`** | ✅ sealed (commit 5f718b89, 755 KB) — from HEAD aa48e9f3, fixed-point verified |
| CI integration (Phase 3) | ⚠️ partial — the Bun-free `seed-rebuild` job was removed 2026-08-30; only the gated `fixed-point` job and `Test`'s own (Bun-installed) bootstrap remain |
| README narrative / §2.8 `src/` deletion | ❌ later |
| 3-stage build + next-to-exe resolution | ✅ done (2026-06-06) — see the note at the top of this file |

## Blocking prerequisite : wire `cmd_build` — ✅ DONE (commit 2c055e00)

The seed is emitted with **`vader build`**, the proper command — **not**
`dump --stage=c` (a debug tool). `cmd_build` was a stub ; it is now wired :

- **`--emit=c`** — `build_c` writes the generated C to `--out` (default
  `<file>.c` ; `--out=-` streams to stdout). ✅
- **`--emit=executable`** — emits the `.c` next to the binary, then invokes `cc`
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
`vader build --emit=c` is the *Blocking prerequisite* above.

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
             ▼  vader build --release --emit=c --seed-targets=<every target>
             ▼                --out=bootstrap/seed/bootstrap
┌──────────────────────────────┐
│ bootstrap/seed/  (committed seed, ~11 MB for EVERY target)
│   bootstrap.split.h            shared declarations
│   bootstrap.split.g.c          shared globals (holds the atom union)
│   bootstrap-<module>.c         one per module, shared when every target
│                                emitted the same bytes for it
│   bootstrap.<os>-<arch>-<module>.c    only the units that actually differ
└────────────┬─────────────────┘
             │
             ▼  cc -O0 <shared units> <this host's units> runtime/c/vader_runtime.c -o stage0
┌──────────────────────────────┐
│ stage1  (mini build-only compiler)
└────────────┬─────────────────┘
             │
             ▼  stage1 vader/cli/main.vader → main.c → cc
┌──────────────────────────────┐
│ build/vader  (FULL compiler, release candidate)
└──────────────────────────────┘
```

- **`bootstrap/seed/`** — plain C, the mirror of
  `vader/bootstrap/bootstrap.vader`, generated by the current Vader compiler.
  Committed in-tree, uncompressed (see § *Why the seed is stored uncompressed*).
  The runtime is linked **externally** (`runtime/c/`), not bundled (see Phase 2).

  It is a SET, not a file, and covers every supported target at once. That is
  what makes a `@target` body in the bootstrap closure possible: a seed emitted
  on macOS stays re-emittable byte-for-byte on Linux, because every seeded
  target is in it — one arch per OS (`darwin-arm64`, `linux-x86_64`,
  `windows-x86_64`). A second arch of the same OS carries no seed of its own:
  the emitted C is portable, `cc` targets the arch. Bootstrapping there is not
  supported; cross-compiling to it through `--target` still is. Two things
  make it affordable — the units are partitioned per MODULE (so one changed
  function does not reshuffle the rest) and every target is
  emitted against ONE atom table (so ids do not renumber). Measured with one
  `@target` body in the closure: 38 shared files and 25 KB per target, against
  11.7 MB per target without either.
- **stage1** — a build-only compiler produced by compiling the seed with a plain
  C compiler. It carries the entire pipeline, so it can compile any
  `.vader` — including `vader/cli/main.vader`.
- **build/vader** — the full compiler, produced by stage1 rebuilding the current
  source.

Why a dedicated `bootstrap.vader` rather than seeding from `main.vader` : the seed
then **decouples from the CLI**. Growing the lsp / formatter / `run` no longer
bumps the seed — only pipeline changes do. Smaller size is a side benefit (~3 %) ;
what actually governs the repository cost is not the size of one seed but how
well git can delta *successive* ones — see § *Why the seed is stored uncompressed*.

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

import "vader/midir"
import "vader/c_emit"
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
├── bootstrap.c        — the seed (generated, uncompressed, committed)
├── VERSION            — metadata about the seed
├── seed.sh            — the seed's lifecycle: check | regenerate
├── build.sh           — seed → stage0 → stage1 → ./build/vader (stage2)
├── build.ps1          — Windows counterpart (mingw-w64)
├── verify.sh          — fixed-point check (Phase 4, every push + PR)
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
bootstrap/seed/**   -diff -merge linguist-generated=true
```

- `-diff` hides the seed in `git diff`, `git log -p` and PR views. Measured on a
  real reseed: `git log -p -1` prints **9 lines** with it, **45 350** without.
  It also makes `git grep` report `Binary file … matches` instead of dumping
  every hit inside the seed — 1 line versus 3 581 for a runtime symbol. (This is
  deliberate, not a side effect: `grep_source_is_binary()` consults the diff
  driver resolved from gitattributes. `git grep -c` still counts normally.)
- `-merge` skips 3-way merge attempts. A *successful* text merge of two divergent
  seeds would produce C that is neither side's real output and would probably
  still compile ; forcing a conflict forces a regeneration instead.
- `linguist-generated=true` collapses it in GitHub PR views and keeps 11.5 MB of
  generated C out of the repository's language statistics.

**Deliberately *not* the `binary` macro** (`-diff -merge -text`), which is what
the seed carried while it was a `.gz`. Dropping `binary` lets it inherit
`*.c text eol=lf`. Note that this is a normalisation choice only — it is **not**
what makes the storage win work, contrary to what one might assume:

> Delta compression will not be attempted for blobs for paths with the attribute
> `delta` set to false. — gitattributes(5)

`delta` is the *only* attribute that governs delta compression; `text` / `binary`
have no bearing on it. Verified by measurement on four real consecutive seeds —
`.c` with `binary`, `.c` with `-diff -merge`, and `.c` with no attributes at all
all pack to **1.6 MB**, against 4.3 MB for the `.gz` form. The win comes entirely
from storing decompressed *content*, and the attributes above are purely about
day-to-day ergonomics.

The one setting that *would* break it is `core.bigFileThreshold` (default
**512 MiB**): files above it are "stored deflated in packfiles, without
attempting delta compression". At 11.5 MB the seed is two orders of magnitude
below that.

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

### `bootstrap/regenerate.sh` — HISTORICAL

> The script below is the Phase-2 design as first written. It no longer exists:
> the seed's lifecycle is now `bootstrap/seed.sh check | regenerate | push`, one
> script because it is one artefact. Kept as the record of what was designed, not
> as instructions — see `bootstrap/README.md` for the current commands.

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

# Emit the seed source (build-only entrypoint) straight to its tracked path.
# `cmd_build --emit=c` must be wired — see the Blocking prerequisite.
# --release keeps `#line` out of the seed (c-emit gates them on !release) — the
# seed is a bootstrap artifact and a populated debug table would otherwise bloat
# it with tens of thousands of `#line` lines. For --emit=c, --release only
# drops `#line`.
"$VADER" build vader/bootstrap/bootstrap.vader --release --emit=c \
    --seed-targets="$SEED_TARGETS" --out=bootstrap/seed/bootstrap

cat > bootstrap/VERSION <<EOF
vader_source_sha: $(git rev-parse HEAD)
vader_version:    $(grep -E '^[[:space:]]*VERSION' vader/version.vader | head -1)
regenerated_at:   $(date -u +%Y-%m-%dT%H:%M:%SZ)
generator:        $VADER ($("$VADER" --version))
EOF

echo "seed regenerated. review the diff:"
echo "  diff <(git show HEAD:bootstrap/bootstrap.c) bootstrap/bootstrap.c"
echo "confirm it's localised, then commit:"
echo "  git add bootstrap/bootstrap.c bootstrap/VERSION"
echo "  git commit -m 'chore(bootstrap): bump seed'"
```

Implementation note : the seed source is `vader/bootstrap/bootstrap.vader`
(build-only), **not** `vader/cli/main.vader`. `vader build --emit=c --out=<path>`
must be wired in `cmd_build` first (Blocking prerequisite). The runtime stays
**external** (no bundling) — `build.sh` links `runtime/c/` at `cc` time.

### `bootstrap/build.sh`

```sh
#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

mkdir -p build
cc -O2 -o build/stage1 bootstrap/seed/bootstrap.split.g.c bootstrap/seed/bootstrap-*.c runtime/c/vader_runtime.c -Iruntime/c -lm

echo "stage1 built at build/stage1"
echo "smoke test (stage1 compiles a trivial snippet to C):"
./build/stage1 tests/snippets/return_42/_main.vader build/_smoke.c && echo "  ok"
```

The contract : `cc -O2 bootstrap/seed/bootstrap.split.g.c bootstrap/seed/bootstrap-*.c
runtime/c/vader_runtime.c -Iruntime/c -lm -o stage1`. The glob picks up the
shared units; a host whose target has units of its own adds
`bootstrap/seed/bootstrap.<os>-<arch>-*.c` (see `bootstrap/build.sh`). `runtime/c/` is the only
sidecar required (external link — see the Phase 2 decision). `stage1` is the
build-only compiler : it takes `<input.vader> <output.c>`, so the smoke test
compiles a snippet rather than running `--version`.

### The very first seed (transition step)

The first time `bootstrap.c.gz` is generated, you need a working Vader binary
**with `cmd_build` wired**. At that point the TS compiler is still present
(deletion happens at §2.8, **after** this plan succeeds). Sequence :

0. (Prerequisite) Wire `cmd_build --emit=c` in `vader/cli/main.vader`, and
   create `vader/bootstrap/bootstrap.vader`.
1. Build a Vader binary via TS one last time (now carries the wired `cmd_build`) :
   `bun src/index.ts build vader/cli/main.vader --release --out=build/vader-via-ts`
2. Emit the first seed from the build-only entrypoint :
   `VADER=./build/vader-via-ts bootstrap/regenerate.sh`
   (or, equivalently, emit straight from TS :
   `bun src/index.ts build vader/bootstrap/bootstrap.vader --emit=c --out=build/bootstrap.c && gzip -9 -c build/bootstrap.c > bootstrap/bootstrap.c.gz`).
3. Build stage1 from that seed : `bootstrap/build.sh`.
4. Run §2.7 fixed-point checks (Phase 4 / `bootstrap/verify.sh`) and
   confirm the seed and `main.c` reproduce byte-identical.
5. Commit `bootstrap/bootstrap.c.gz` + `bootstrap/VERSION`.
6. Subsequent regenerations use `bootstrap/build.sh` output (stage1) or a
   previously-installed `vader` — the TS compiler is never the generator again.

---

## Phase 3 — CI integration — ✅ DONE (`.github/workflows/build.yml`)

CI lives in the unified `.github/workflows/build.yml` workflow. **The Bun-free
`seed-rebuild` job described below was REMOVED on 2026-08-30** (`1c19064b3`) —
see the warning at the top of this document for what went with it. What remains
is the `Test` job's own bootstrap, which runs after Bun is installed, plus the
`fixed-point` job (`verify.sh`), which runs on **every push and PR** since
2026-08-30. It used to be gated to `workflow_dispatch` and release tags as too
slow; it measured 257 s and 286 s the two times it actually ran, against the
10 m 59 s Windows job that sets a run's total, so it finishes inside that shadow
for no wall-clock cost. It is also the seed's viability gate, the same
`verify.sh` the pre-push hook runs; a seed that cannot build the tree fails the
test jobs as well, since they bootstrap from it. It installs neither Bun, Node,
nor a pre-installed `vader` — only a C compiler. (The Bun
`test` / `dist` jobs in the same file are separate, isolated jobs.)

The `rebuild` job, running on each push :

1. `cc -O2 bootstrap/seed/bootstrap.split.g.c bootstrap/seed/bootstrap-*.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/stage1`
2. `./build/stage1 vader/cli/main.vader build/main.c` — stage1 emits the FULL compiler's C
3. `cc -O2 build/main.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/vader`
4. `./build/vader --version` smoke test
5. (Optional gate) `./build/vader test …` — sanity check against the
   snippet suite

This validates two invariants on every push :
- The committed seed still compiles with a stock C toolchain.
- The seed is functionally complete enough to rebuild the compiler.

A drift between source and seed (e.g., bytecode-format change without
seed regeneration, runtime ABI break) makes CI fail loudly at step 2.

The CI **does not** require Bun, Node, or any pre-installed `vader`.
Only a C compiler. That is the whole point.

---

## Phase 4 — Fixed-point verification

This formalises TODO §2.7 as a script. `bootstrap/verify.sh` runs on every push
and PR (CI `fixed-point` job, ADR 0006) and is what `bootstrap/seed.sh check`
runs before a push. It builds the three stages with `build.sh`, then checks:

- **(a) fixed point** — stage2 re-emits `main.vader` in release mode, and the
  result must equal what stage1 emitted for stage2, unit for unit (`diff -r`).
  stage1's codegen is the seed's, so equality also shows the seed's age did not
  leak into the compiler's behaviour.
- **(a2) debug emission** — the same comparison on a snippet without `--release`,
  which covers `#line` and the per-op debug table.
- **(b) reproducibility** — stage1 builds stage2 a second time, to another path;
  the two binaries must be byte-identical.

Exit `0` pass, `1` a real failure, `2` could not conclude (a structural `diff`
error, a missing C compiler). A fixed point says nothing about correctness: a
compiler that mis-compiles itself stably passes it, which is why the suite has
to run after a reseed.

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

### When to bump — when the seed stops working

The seed is a bootstrap tool: it has to build the current tree, not to be what the
current tree would emit. The build runs three stages —

```
seed + runtime/c   ─cc→   stage0   (old compiler)
stage0 (tree)      ─cc→   stage1   (the tree's semantics, the seed's codegen)
stage1 (tree)      ─cc→   stage2   = build/vader   (the tree's semantics and codegen)
```

— and ships stage2, so the seed's age never reaches the shipped binary.
`verify.sh` proves stage1 and stage2 emit the same C; with an older seed that
check is stronger, not weaker, since the two stages no longer share a codegen.
Measured on 2026-09-23, a seed two weeks old, across the Box 24 → 16 B runtime
change, produced a byte-identical compiler: the seed's C reaches layout through
`vader.h` and `sizeof`, so it adapts to the runtime it is recompiled against.

So a reseed is due only when **`bootstrap/seed.sh check` says `1`**: the committed
seed, with HEAD's `runtime/c/`, no longer builds HEAD or no longer passes
`verify.sh`. In practice that is a breaking change the old stage0 cannot compile
(a core type it looks up by name, an intrinsic it does not know), or a runtime
function the seed calls being removed or re-signed.

The stage0 contract is frozen between reseeds: `build.sh` evolves with the tree
but calls an OLD stage0, as `stage0 <input.vader> <output-prefix>`
(`vader/bootstrap/bootstrap.vader::main`), and reads the split file layout it
writes. Changing either forces a reseed in the same commit.

### The check, and the hook

`bootstrap/seed.sh check` owns the question and answers in exit codes: `0`
viable, `1` broken, `2` could-not-tell (no C compiler, a seed source tree
missing). It exports HEAD under `build/seed.viability/` and runs `verify.sh`
there (~1 min on an M3 Max), so it vets exactly what is pushed: an uncommitted
edit can neither fail nor pass it, and the checkout's `build/vader` is left
alone. A viable verdict is stamped in `build/seed.viable` with the git object ids
of what it read — the seed's sources, the seed, `build.sh` and `verify.sh`; while
those do not move, the check answers in no time, so a push touching only docs,
tests or tooling compiles nothing.

`.githooks/pre-push` runs it when the push publishes HEAD. Enable it once per
clone with `git config core.hooksPath .githooks`; `git push --no-verify`
bypasses it. `1` blocks the push; `2` warns and lets it through, since the CI
`fixed-point` job runs the same gate on every push.

### Reseeding

```sh
bootstrap/seed.sh regenerate
bun run test                      # the new seed builds the stage0 under test
git commit -m 'chore(bootstrap): bump seed' bootstrap/seed bootstrap/VERSION
```

When the check fails because of the seed, `build.sh` cannot produce a compiler
from it — but the last `build/vader` that did build is much newer than the seed
and usually still compiles the tree. `regenerate` relies on that: given a
compiler older than the `.vader` sources, it builds the tree with it first and
emits the seed from the result. It requires a clean tree across every source dir
the seed depends on — not just `vader/`, since the seed embeds the stdlib it was
compiled with. It is a no-op
when the seed comes out byte-identical, leaving `VERSION` alone.
`VERSION`'s `vader_source_sha` is the commit the seed was emitted at — its age.

Inspect the diff before committing. The seed carries `-diff`, so `git diff`
reports it as binary; `git diff --stat` gives the byte delta. Commit the bump as
a **separate commit** from the source change: easier to review, easier to
revert.

### Bump frequency expectations

Only breaking changes reseed — rare next to the compiler's commit rate (the
measurements are in `.claude/plans/2026-09-23-seed-viability.md`).

### Repo growth budget

**Revised 2026-07-28 against measurements.** The original budget below assumed
each bump would delta to 10-50 KB. While the seed was stored gzipped that was
never achievable — git cannot delta a gzip stream, so *every* reseed cost a full
compressed blob (~1 MB) forever, and 453 of them had accumulated to **429.6 MB,
81 % of the repository**, at ~10 reseeds/day.

Storing the seed uncompressed restores the intended behaviour: measured on four
real consecutive seeds, the pack is **1.6 MB** instead of 4.3 MB, i.e. roughly
**~60 KB per reseed** rather than ~1 MB. The original 10-50 KB target is now the
right order of magnitude again.

The remaining lever is *frequency* — 294 reseeds in 30 days is habit, not
necessity, since a reseed is reflexively done at the end of each chantier because
`verify.sh` fails otherwise. At 60 KB a reseed it is no longer urgent. See
`.claude/plans/2026-07-28-seed-size.md` (Phases 2 and 3).

> Original text — With Phase 0 fixes applied (and mirrored in the Vader port),
> expect each bump to delta to **10-50 KB** in packfile size after `git gc`. At
> 200 bumps/year, that is 2-10 MB/y. If actual growth significantly exceeds this
> — say, > 50 MB/year — the codegen has regressed on stability ; revisit Phase 0
> before falling back to a separate-repo storage strategy (see *Migration paths*).

---

## Why the seed is stored uncompressed

Adopted 2026-07-28 (Phase 1 of `.claude/plans/2026-07-28-seed-size.md`). The seed
was committed as `bootstrap.c.gz` from the first seed until then.

**The finding.** Two consecutive seeds are **99.86 % identical as C** (296 lines
differing out of 215 530) and **100 % different as compressed bytes**. git cannot
delta a gzip stream, so each reseed stored a fresh ~1 MB blob, permanently. All
453 `bootstrap.c.gz` blobs totalled **429.6 MB — 81 % of the repository**.

**Measured**, packing the same four consecutive real seeds each way, after
`git gc --aggressive` :

| 4 seeds, stored as | pack |
|---|---|
| `.c.gz` (the old form) | **4.3 MB** |
| `.c`, uncompressed | **1.6 MB** |

A ~63 % reduction that **keeps every seed** — each commit stays individually
bootstrappable, which is the seed's entire reason to exist. That is what makes
this better than thinning history to one seed a week (~7 MB, but only 7 of 453
commits could bootstrap themselves).

**What it costs.** The working tree carries an 11.5 MB text file instead of a
1.1 MB blob, and `gzip` leaves the dependency list (`build.ps1` no longer needs
.NET's `GZipStream` either).

**What it does *not* depend on.** Not the `.gitattributes` attributes — see
Phase 1 above; `text` / `binary` have no bearing on delta compression, only the
`delta` attribute does. Not line length either: git's packfile delta operates on
bytes, not lines, so the seed's longest emitted line (55 000 characters, a
`UINT64_C` comptime table) is irrelevant to it. The same four seeds minified
(leading indentation and blank lines stripped, per § 6 of the plan) pack to
**1.4 MB** — so that idea composes with this one rather than competing.

---

## TS compiler deletion (§2.8)

> **Status — done (2026-06-22), branch `chore/delete-ts-compiler`.** `src/`
> (136 files), `tsconfig.json`, `tests/cli.test.ts`, and `bun.lock` removed;
> `package.json` devDeps emptied and the `vader` / `typecheck` scripts + the
> `module` field dropped; `tests/snapshot.ts` decoupled from the TS pipeline
> (the native CLI is the sole snapshot oracle); the CI `Typecheck` step
> removed; README updated. The pre-deletion state is tagged
> `v0.0.0-pre-mvp-final-ts`. The original plan follows, for the record.

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

> Vader is self-hosted. A committed C seed at
> `bootstrap/seed/` lets any machine with a C compiler build the
> toolchain from source — see [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md).

### New subsection under `## Build from source`

> ### From the C seed (no Vader binary needed)
>
> ```sh
> bash bootstrap/build.sh                           # cc the seed → ./build/stage1
> ./build/stage1 vader/cli/main.vader build/main.c  # stage1 emits the full compiler's C
> cc -O2 build/main.c runtime/c/vader_runtime.c -Iruntime/c -lm -o build/vader
> ```
>
> The seed is the C of `vader/bootstrap/bootstrap.vader` (a build-only
> entrypoint) that `vader build --emit=c` produces ; it is
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
| **gzip -9** | 8.9 MB → ~790 KB (11×) | ⛔️ **reversed 2026-07-28** — adopted at the time, but it optimised the wrong quantity: one seed got 11× smaller while *history* got ~14× bigger, because git cannot delta a gzip stream. See § *Why the seed is stored uncompressed*. |
| mini-VM + committed bytecode | gzipped bytecode ≈ gzipped C ; **+~3000 LoC of C** to write/maintain ; `stage1` would be *interpreted* (slow) | ❌ no size win, more work |
| seed = full `vader/cli/main.vader` | +~3 % size ; **re-bumps on every lsp/fmt/cli change** | ❌ unstable seed |
| better stdlib DCE | stdlib = 4.4 % of the C and **already DCE'd** (`is_stdlib_path`) ; headroom < 4 % | ❌ essentially already done |

Why the format and the pruning barely matter : the seed is **dominated by the
build pipeline** (parser / typecheck / lower / midir / comptime / c_emit), which
is irreducible by construction ; C and bytecode weigh the same once compressed.
So the dedicated build-only entrypoint (`bootstrap.vader`) is chosen for
**stability and traceability** of the seed, not for bytes.

The table above measures **one seed**, and that framing is what made the gzip row
look like a win. The quantity that actually matters is the cost of the *453rd*
seed, where compression is a net loss by an order of magnitude.

## Migration paths (if growth becomes a problem)

Growth *did* become a problem — 430 MB of it — and the fix was neither of the
two escape hatches below but the storage format itself (§ *Why the seed is stored
uncompressed*), which keeps the seed in-tree and every commit self-sufficient.
The ~400 MB already spent on gzipped blobs was recoverable only by rewriting
history, and **that was done on 2026-07-28** (Phase 3 of
`.claude/plans/2026-07-28-seed-size.md` — do not confuse it with this document's
own Phase 3, which is CI integration). Every historical `bootstrap.c.gz` blob
became its decompressed `bootstrap.c`, keeping all 400 seeds and all 2328 commits;
verified lossless by comparing the SHA-256 sets of the decompressed originals
against the rewritten blobs. `.git` went from **535 MB to 61 MB** locally, and a
fresh clone from GitHub is **83 MB** (GitHub repacks with its own settings, so
that is the figure a third party sees). Every SHA changed; `main` moved
`841cdd8f8` → `361ce4036` and the tag `v0.0.0-pre-mvp-final-ts`
`e2b434022` → `083fac484`.

Two things about that rewrite are worth carrying forward, because both would
otherwise be rediscovered the hard way:

- **The aggressive repack is where the win lives.** The rewrite alone took `.git`
  only 535 → 452 MB (−15 %); `git gc --aggressive --prune=now` then took it to
  61 MB, in 9 min 50 s. 400 large blobs arriving at once among 75 918 objects
  defeat the default `pack.window=10`. This is a one-off: a repo holding only the
  seeds packs identically under default and aggressive gc, so ordinary reseeds
  need no special treatment.
- **Renaming the seed in history breaks the scripts that read it.** Left alone,
  every pre-rewrite commit kept its seed but its `bootstrap/build.sh` still looked
  for a `.gz` — which would have destroyed the very property that justifies
  keeping all 400 seeds. The rewrite therefore also repointed `build.sh`,
  `verify.sh` and `.gitattributes` in history. `build.ps1` was deliberately left
  alone (a 4-line PowerShell block across 20 versions; a half-working regex is
  worse than a loud failure), so *historical* Windows builds fail. Confirmed by
  building the full 3-stage toolchain from four historical commits spanning
  2026-06-05 to 2026-07-14, including the oldest seed of all.

Should pressure return, the escape hatches are non-breaking for the user-facing
`bootstrap/build.sh` contract — only seed *acquisition* changes :

1. **Separate repo** (`vaderlang2-seed`) — Nim's `csources_v2` pattern.
   Main repo references a SHA in `bootstrap/VERSION`, `bootstrap/build.sh`
   curls the tarball. Migration : `git filter-repo` purges the
   seed history from this repo, moves it to the new repo.

2. **GitHub Release artefact** — the seed published as an asset
   on a `bootstrap-v<N>` tag, `bootstrap/build.sh` downloads it. No
   second repo, GC-able by deleting old releases. Trade-off : harder
   offline / air-gapped builds.

---

## Order of work

Strictly sequential (each step gates the next) :

1. **Self-host port + fixed-point** (TODO §2.1-2.7) — ✅ done. Phase 0 codegen
   determinism is effective (byte-identical proves it).
2. **Wire `cmd_build`** (`--emit=c` minimum) in `vader/cli/main.vader` —
   **blocking prerequisite** ; promote `run_c_stage` into a real `build` command
   writing `--out`.
3. **Cleanliness refactor** `op.vader → vader/bytecode` — recommended, ~1 file
   moved + ~15 import edits.
4. **Create `vader/bootstrap/bootstrap.vader`** (build-only entrypoint, pipeline
   duplicated, no `vm`/`fmt`/`lsp`).
5. **Phase 1 layout** (`bootstrap/` + scripts) + `.gitattributes` on the `.gz`.
6. **First seed generation + verify** (Phase 2 *very first seed* + Phase 4
   verify) — emit via `vader build --emit=c`, gzip, external runtime.
7. **Phase 3 CI job** — once `build.sh` works.
8. **README update** — alongside Phase 3 going green.
9. **§2.8 TS deletion PR** — separate PR, mechanical.

(`--bundle-runtime` one-file seed is an optional improvement, not on this path.)
