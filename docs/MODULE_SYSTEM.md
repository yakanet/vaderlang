# Module system redesign

> Status : Phases 1-9 implemented (2026-05-22 → 2026-05-23). Phase 10
> (TS-vs-Vader byte-diff broad-parity) deferred — see §5 Phase 10 and
> §8 follow-ups. SPEC §11 rewritten in commit `dfef864f`.

## 0. Motivation

Today the resolver follows SPEC §11's "one folder = one module" rule
literally. The current `stdlib/std/` layout — 21 flat `.vader` files
where each file is conceptually an independent module (`import
"std/string"` designates one file) — breaks under that rule : sibling
files collide on names like `Parser` (defined in both `regex.vader` and
`json.vader`), `byte_len`, `slice`, etc. The Vader self-host masks the
collisions silently (first-wins on duplicate top-level decls, `:: ?`
fallback on type lookups) ; the TS reference compiler exposes them
(50+ collision-driven diagnostics per stdlib file under a folder-module
promotion patch).

The redesign decouples module identity from filesystem layout : every
file declares which module it belongs to via a `module "..."` keyword.
The filesystem is still the storage layer, but module names are first-
class and globally unique.

This unblocks the broad TS-vs-Vader parity rig (the original driver) :
once both compilers agree on what each module contains, byte-diffing
their typecheck dumps across real `vader/` and `stdlib/` modules
becomes meaningful coverage on top of the 251 snippet tests.

## 1. Semantics

### 1.1 Module declaration

Every `.vader` file must declare its module on its first non-trivial
line :

```vader
#!/usr/bin/env vader            // optional shebang
// optional leading comments

module "std/string"             // mandatory
```

Rules :

- One declaration per file. Repeating `module "..."` is a compile error.
- Must appear before any `import`, `export`, or top-level decl. Only
  shebang and comments may precede it.
- Missing declaration is a compile error (no implicit module name).
- The REPL injects `module "main"` implicitly so REPL fragments don't
  need to type it.

Syntax : `module` followed by a string literal in double quotes,
mirroring `import "..."`.

### 1.2 Granularity : one folder ≤ one module

A folder may contain **at most** one module. All `.vader` files in the
same folder must declare the **same** module name ; mixed declarations
raise a diagnostic at scan time.

A folder may also contain zero `.vader` files (treated as a non-module
folder, ignored by the scan).

### 1.3 Global uniqueness

Across every scanned source root (project whitelist + stdlib + future
deps), each module name appears in **exactly one** folder. Two folders
declaring the same module name is a compile error at scan time.

### 1.4 Discovery + index

At project load, the compiler performs a single pass that scans every
scoped source root and builds an in-memory index :

```
module-name → { folder-path, files: [...] }
```

The scan is recursive within each scoped root. Folders without `.vader`
files are skipped silently. Folders containing `.vader` files trigger
the contract checks of §1.2 and §1.3.

Symlinks are **not** followed during the scan, neither for `.vader`
files nor for folders that would contain them. A symlinked entry under
a scoped root is treated as if it did not exist.

The index is rebuilt on each compiler invocation (no on-disk cache in
MVP — caching is a post-MVP performance topic).

### 1.5 Imports

```vader
import "std/string"                // pure namespace import
str :: import "std/string"         // named namespace import (alias `str`)
import "std/string" { byte_len }   // destructured import
str :: import "std/string" { byte_len, slice }   // scoped namespace import
```

Resolution rules :

- The string passed to `import` is **strictly** a module name. It is
  looked up in the index. No filesystem fallback.
- Relative imports (`./foo`, `../foo`) are **removed** from the
  language. The path must be a module name.
- Bareword imports (`import "foo/bar"` without `./`) are also strictly
  index lookups — no project-root filesystem walk.
- Importing a module from a file that itself belongs to that module
  (self-import) is a compile error.
- `import` declarations are **file-scoped**. Names bound in one file of
  a multi-file module are not visible in sibling files of the same
  module ; each file declares its own imports.
- `std/core` is an **implicit prelude** : every `export` from `std/core`
  is automatically in scope in every other module, with no `import`
  required. `Range`, `Field`, `Display`, `Iterator`, etc. are usable
  directly. The prelude does not apply inside `std/core` itself (it
  can't import itself).
- Writing `import "std/core"` explicitly from another module is a
  compile error : the prelude already covers it, and a second import
  would be a redundant binding (treated identically to any other
  duplicate-import collision below).
- Two destructured bindings of the same name in the same file — whether
  from two distinct modules (`import "a" { foo } ; import "b" { foo }`)
  or from a destructure that shadows a prelude binding — are a compile
  error. No silent shadowing.
- **Import cycles are forbidden.** If module `A` imports `B` (directly
  or through a chain) and `B` imports `A`, the resolver emits a
  diagnostic. Cycles must be broken by extracting the shared decls into
  a third module or by inlining.
- **No re-exports.** A module cannot republish another module's
  bindings. `export import "..."` and similar forms are not part of the
  language. A façade module that wants to expose a curated surface must
  wrap each binding manually.

### 1.6 Visibility

Two levels :

- `export` — the decl is visible to importers via `import "<this-module>"`.
- default (no keyword) — the decl is private **to the module**, i.e.
  visible to every file of the same module without an import, and
  invisible to any other module.

No file-private level. If a decl needs to be private to a single file,
it lives in that file alone — but other files of the same module can
still see it ; this is by design.

**Intra-module collisions.** Two top-level decls with the same name in
the same module raise a compile error :

- Two structs / type aliases / consts / enums / traits with the same
  name across files of the module → hard error (cannot be resolved
  silently — there's no canonical "winner").
- Two `fn` decls with the same name across files of the module → join
  the same overload set, exactly like multiple `fn` decls inside one
  file today. T3032-style ambiguity surfaces only at the call site if
  the parameter shapes overlap.

**Visibility leak.** An `export`ed decl whose signature mentions a
module-private type, alias, const, enum, or trait is a compile error.
A public surface must be reachable through public types only — no
"effectively public via signature" leakage. The user has to either
`export` the referenced decl or refactor the signature.

### 1.7 Sub-modules

Two modules whose names share a prefix (`std/string` and
`std/string/utf8`) are **independent** logical modules. The compiler
treats them as two unrelated entries in the index. The shared prefix
has no semantics — no parent-child relationship, no implicit re-export,
no automatic visibility.

The filesystem may nest the folders (`stdlib/std/string/utf8/`) or not
(`stdlib/std-string-utf8/`) ; the compiler does not derive any meaning
from filesystem layout once the module name is declared.

### 1.8 Module name form

The grammar for a module name :

```
module-name ::= segment ('/' segment)*
segment     ::= [a-z] [a-z0-9_]*
```

Examples accepted : `main`, `std/string`, `std/string/utf8`,
`vader/lexer`, `my_app/util_2`.

Examples rejected : `Std/String` (uppercase), `std/1string` (segment
starts with digit), `std//string` (empty segment), `std/string/`
(trailing slash), `./relative` (special chars).

The `/` inside a name is a regular character ; segment-level parsing
exists only for the grammar check above.

## 2. Configuration

### 2.1 Stdlib resolution

The stdlib is resolved out-of-band from `vader.json` :

- **Release mode** — sidecar of the binary. The compiled `vader`
  executable ships in a tarball alongside `stdlib/` (already done by
  `scripts/dist.ts` — see `dist/vader-darwin-arm64/stdlib/`).
  Resolution : `<dir-of-binary>/stdlib/`.
- **Dev mode** — when running from source via `bun src/index.ts`, the
  stdlib path is hard-coded to `<workspace>/stdlib/` (already handled
  by `src/runtime-resources.ts`).

The stdlib's modules participate in the global index just like any
other scope ; they're simply discovered through a fixed path rather
than through `vader.json`.

### 2.2 `vader.json`

`vader.json` is **optional**. A project without external dependencies
(beyond stdlib) does not require one.

**Default whitelist when `vader.json` is absent or omits `modules`** :
the scan covers only the entry file's containing folder, plus the
stdlib (§2.1). This keeps single-file invocations and trivial projects
working without ceremony ; larger projects with multiple source roots
need a manifest.

The `modules` field accepts **literal folder paths only**. Glob
patterns (`src/**`, `vader/*/`) are not supported — each root is a
plain relative path resolved from the manifest's directory.

When present, a `modules` field declares the source roots to scan :

```json
{
  "name": "myapp",
  "version": "0.1.0",
  "modules": ["src/"]
}
```

For the `vaderlang2` repo itself, the manifest would declare :

```json
{
  "modules": ["src/", "vader/"]
}
```

Folders not listed (e.g. `tests/`, `bench/`, `examples/`, `build/`,
`dist/`, `node_modules/`, `.git/`) are excluded from the scan, even
when they contain `.vader` files. They cannot be imported by name.

Future post-MVP : an additional field for declaring external library
roots will land here. Out of scope for this redesign.

### 2.3 CLI fallback for out-of-scope files

To allow `vader dump tests/snippets/arith/_main.vader` and
`vader run examples/hello.vader` to work without forcing every
auxiliary folder into the whitelist, the compiler applies an
auto-fallback rule :

> If the file passed on the command line lives in a folder that is
> **not** covered by the active `modules` whitelist, the compiler
> implicitly adds that file's containing folder to the scan for this
> invocation only.

This keeps the whitelist strict for indexing purposes (the snippet
folder is not part of the project's normal module graph) while making
single-file invocations ergonomic.

## 3. Diagnostics

New resolver codes — concrete IDs assigned in commit `a3c6ce0c`,
mirrored on the Vader side in `33f16f0c` :

| Code  | Trigger | Severity |
|-------|---------|----------|
| R2020 | `module` declaration missing on first non-trivial line | error |
| R2021 | More than one `module` declaration in the same file | error |
| R2022 | Files in the same folder declare different module names | error |
| R2023 | Two folders declare the same module name globally | error |
| R2024 | `import "X"` from a file that belongs to module `X` (self-import) | error |
| R2025 | `import "./foo"` or `import "../foo"` (relative paths removed) | error |
| R2026 | Duplicate non-fn declaration across files of the same module | error |
| R2027 | Exported decl whose signature references a module-private decl | error |
| R2028 | Explicit `import "std/core"` from a non-`std/core` module (duplicate of prelude) | error |
| R2001 | `import "X"` and `X` does not exist in the index (reused from pre-existing code) | error |
| R2005 | Import cycle (`A → … → A`) (reused) | error |
| R2011 | Two destructured imports of the same name in the same file (reused) | error |

The R2023 "two folders declare the same module name" diagnostic is
emitted on the **second** folder encountered during scan, with a
secondary span pointing at the first occurrence's `module` declaration
(mirrors the secondary-span pattern of R2011). Scan order is **not**
guaranteed to be deterministic across platforms or filesystems —
diagnostics that depend on "first vs second" are stable within an
invocation but may swap roles between machines. Test fixtures must not
rely on a specific filesystem traversal order.

Parser-level codes (P10xx range) :

- P1028 — invalid module name (does not match the §1.8 grammar).
- P1029 — module declaration missing (reserved ; **not yet emitted** —
  the resolver's R2020 catches missing decls at scan time, which is
  sufficient today. P1029 is kept reserved for a future strict-flip of
  the parser if we want the diagnostic to surface earlier in the
  pipeline).
- P1030 — module declaration malformed : expected exactly one
  double-quoted string literal after `module` (reserved ; same status
  as P1029).

## 4. Compilation modes

Two modes, both rest on the same scan + index :

| Mode | Triggered by | Behaviour |
|------|---|---|
| **Focus** (default) | `vader run`, `vader build`, `vader dump <file>` | Scan everything in scope to build the index and validate §1.2 / §1.3. Typecheck **only** the entry's module + its transitive imports. |
| **Whole** (post-MVP, opt-in) | `vader check --all` (or equivalent, not in scope here) | Scan + typecheck every module reachable from the project's roots, including those not imported by any entry. Useful for CI / `vader test`. |

Focus mode aligns with the TS resolver's current BFS-over-imports
behaviour. It's faster on growing projects and tolerates work-in-progress
modules that aren't yet linked into the main graph.

The same scan + index applies to every other CLI subcommand —
`vader test`, `vader fmt`, `vader lsp`, `vader check`. The scan
contract (§1.2, §1.3) and the diagnostic surface (§3) are identical
across subcommands ; only the downstream work after indexing differs
(typecheck for `run`/`build`/`dump`/`test`/`check`, formatting for
`fmt`, request handling for `lsp`).

## 5. Phase plan

Sequencing rationale : both compilers (TS reference + Vader self-host)
must accept the new `module` keyword before any `.vader` file declares
one — otherwise migrating the stdlib or `vader/` would break the Vader
CLI build. So the order is **tolerant parsers first (TS + Vader)**,
then **mass migration**, then **strict enforcement (resolver +
parser-flips)**. Each phase is a green-build commit.

### Phase 1 — SPEC.md §11 rewrite ✅ done (`dfef864f`)

Replace the current "one folder = one module" wording with the
semantics from §1 of this document. Document the name form grammar
(§1.8), visibility rules (§1.6), and the `module` declaration syntax
(§1.1). Add a short rationale subsection noting that filesystem layout
no longer determines module identity.

### Phase 2 — Lexer + Parser TS (tolerant mode) ✅ done (`01f25c17`)

- Lexer (`src/lexer/`) : add `module` to the keyword table.
- Parser (`src/parser/`) : new `ModuleDecl { name: string, span: Span }`
  AST node on `Program`. `parseProgram` accepts the decl as the first
  non-comment, non-shebang token **if present**, otherwise leaves the
  AST's `module` field `null` (no error in this phase — strict
  enforcement comes in Phase 7).
- Validate the name against §1.8 grammar at parse time when present.
- Update `src/parser/ast.ts` types + `tests/snapshot.ts:formatProgram`
  to render the new node in the AST dump.

Verify : add positive snippets (`module_basic`, `module_with_shebang`,
`module_with_comments`). Negative fixtures (`module_missing`,
`module_invalid_name`, `module_repeated`) land in Phase 7 when the
strict mode activates.

### Phase 3 — Lexer + Parser Vader self-host (tolerant mode) ✅ done (`d60db39d`)

Mirror Phase 2 in `vader/lexer/` and `vader/parser/`. Same AST shape,
same diagnostic positions. Stays close to the TS source so snapshot
parity holds. Tolerant mode means the Vader binary built before
migration continues to parse stdlib and `vader/` files unchanged.

### Phase 4 — Migration stdlib ✅ done (`2fb60414`)

Reorganise `stdlib/std/` from flat-files into per-module folders :

```
stdlib/std/string.vader            →   stdlib/std/string/string.vader
stdlib/std/iter.vader              →   stdlib/std/iter/iter.vader
stdlib/std/json.vader              →   stdlib/std/json/json.vader
... 21 files in total
```

Each migrated file gets `module "std/<name>"` on its first line.

Where a former flat file is genuinely small and self-contained
(e.g. `path.vader`), a single-file folder is correct. Where the
content is large enough to benefit from splitting (`string.vader` is
the most likely candidate), the split can happen later — splitting
post-Phase 4 is a no-op refactor under the new model.

`stdlib/std/core.vader` stays as `stdlib/std/core/core.vader` with
`module "std/core"`. Prelude (§1.5) targets this module name, not the
filesystem path.

Verify : every existing `import "std/X"` across `vader/`, `tests/`,
`bench/`, `examples/` continues to resolve correctly under the
tolerant parser ; the resolver still uses the legacy promotion logic
(removed only in Phase 7).

### Phase 5 — Migration `vader/` self-host ✅ done (`83075a56`)

Add `module "vader/<segment>"` to every `.vader` file under `vader/` :

```
vader/lexer/*.vader        →   module "vader/lexer"
vader/parser/*.vader       →   module "vader/parser"
vader/typecheck/*.vader    →   module "vader/typecheck"
...
vader/cli/main.vader       →   module "vader/cli"
```

The `vader/fmt/` and `vader/lsp/` trees migrate together with the rest
for consistency, even though they're not on the self-host critical
path.

Around 117 files. Mechanical patch ; can be scripted from the existing
folder structure (`module "vader/" + basename(dirname(file))`).

Note : `vader/cli/main.vader` becomes `module "vader/cli"` (not
`"main"`) so it doesn't collide globally with `examples/*.vader` (each
of which uses `module "main"` per §6, scoped in via CLI fallback).

### Phase 6 — Migration snippets + examples + bench + vader.json ✅ done (`e6c88e2d`, `0d3b6ab3`)

- `tests/snippets/*/_main.vader` : prepend `module "snippet"` to every
  file. ~250 files. Single-file modules — no sibling collision risk
  since each snippet is invoked in isolation (CLI fallback, §2.3).
- `examples/*.vader` : prepend `module "main"` to every file.
- `bench/*.vader` : prepend appropriate module decls (`module "main"`
  for the runnable entries, `module "bench/<name>"` for shared helpers
  if any).
- Update `vader.json` at the repo root : add
  `"modules": ["src/", "vader/"]`. Confirms the active whitelist.

This phase can be automated by a one-shot migration script.

### Phase 7 — Resolver TS + strict parser flip ✅ done (`a3c6ce0c` → `68611417`)

This is the largest TS change. Strict mode activates here.

Resolution of the cycle blocker recorded in §8 : **Path C** (commit
`cce6cd1f`) extracted `vader/types` + `vader/resolver/symbol` as
standalone modules so the strict folder-module rule holds across the
former cyclic boundary. The parser-flip step (P1029/P1030) was
ultimately **not activated** : the resolver's R2020 catches missing
decls at scan time, which is sufficient ; P1029/P1030 stay reserved in
`codes.ts` for a future strict-flip if needed.

- New `src/resolver/discover.ts` : `discoverModules(roots: string[])`
  walks each root recursively, parses each `.vader` file's header to
  extract the module declaration, and returns an
  `Index<ModuleName, { folder: string, files: string[] }>`. Emits all
  diagnostics from §3.
- `src/resolver/module.ts::resolveImportPath` becomes a strict index
  lookup. Filesystem-based fallback is removed.
- `src/resolver/loader.ts::loadProject` is rewritten :
  1. Resolve stdlib root (§2.1).
  2. Read `vader.json` if present ; assemble the scoped roots
     (stdlib + manifest's `modules` + optional CLI fallback per §2.3).
  3. Call `discoverModules(scopedRoots)`.
  4. Locate the entry's module by looking up its folder in the index.
  5. BFS from the entry module through its `imports` (already
     file-scoped), loading each visited module's full file set.
- The folder-module promotion patch (`promoteToFolderModule` /
  silent R2011 / silent R2004) and the corresponding patch on
  `src/resolver/collect.ts` are removed — they become obsolete.
- Prelude injection : `std/core`'s exports are wired into every
  module's import scope by default (skip for `std/core` itself).
- Self-import detection (§1.5) lands here as well.
- Parser flip : `parseProgram` now emits the missing-declaration
  P-code when no `module` keyword is found. Negative fixtures
  (`module_missing`, `module_invalid_name`, `module_repeated`) land
  alongside.

Verify : snippet harness stays green on all 251 existing snippets ;
broad sweep over `vader/*` + `stdlib/*` shows zero collision
diagnostics.

### Phase 8 — Resolver Vader self-host + strict parser flip ✅ done (`09984ec9` → `a3e69534`)

Mirror Phase 7 in `vader/resolver/` and `vader/parser/`. The discovery
pass + index lookup replaces the legacy `promote_to_folder_module` /
`merge_collected` logic.

Resolution of the memory blocker recorded in §8 : the discover pass
uses a dedicated **header-only byte-scanner** (`parse_module_header`
in `vader/parser/`) that extracts just `module "..."` without
building a full AST. Full `parse_source` runs lazily when BFS visits
each module. Memory footprint drops from "every Program" to "module
header bytes only" — analogous to the TS version's behaviour under
V8's generational GC.

**Update 2026-05-24** : GC defaults bumped to 16 MB young / 64 MB old
(`runtime/c/vader.h`) so the env-var overrides are no longer required
for typical self-host workloads. The dual-semi-space arenas commit to
~160 MB virtual on init but RSS stays proportional to live set
(`malloc`-backed, not `calloc`-zeroed). Lazy indexing remains a
follow-up.

### Phase 9 — LSP ✅ done (`33b1af8d`)

- Recognise `module` as a keyword token in
  `vader/lsp/ast_tokens.vader` and `vader/lsp/semantic.vader`.
- Surface the parser-level diagnostic when the keyword is absent
  (currently the LSP would just show a parse error ; we want a clear
  "missing module declaration" message).
- Optionally : code action "insert `module \"<derived-name>\"`" based
  on filesystem path — convenience for new files. Out of scope MVP.

### Phase 10 — Broad parity TS-vs-Vader 🟡 deferred

The smoke version of the rig (`tests/parity-broad.test.ts`) is in place
and green : per module, the Vader CLI is invoked with
`dump --stage=typed-ast`, exit status checked, stderr scanned for
`error[`. No semantic divergence between TS and Vader can pass through
the design-time contract checks (R2020-R2028), but **byte-for-byte
diff vs TS is not yet implemented**.

The reason : remaining divergences trace to the Vader self-host
typechecker populating fewer `expr_types` entries than TS for several
syntactic forms (intra-block coerce sites, certain match arm
predicates). That gap is a separate chantier on the self-host
typechecker port, not a module-system issue. Running the byte-diff
today would surface dozens of failures whose root cause sits outside
this redesign's scope.

Planned shape when the typechecker gap closes :

1. Pick a representative file from the module's folder.
2. Invoke TS dump, capture stdout.
3. Invoke Vader self-host dump, capture stdout.
4. `expect(vader).toBe(ts)`.

The rig stays gated behind `RUN_BROAD_PARITY=1` until the byte-diff
becomes stable.

## 6. Surface impacted summary

| Layer | Change | Phase |
|---|---|---|
| `SPEC.md` §11 | Rewritten | 1 |
| `src/lexer/` | New `module` keyword | 2 |
| `src/parser/` | `ModuleDecl` AST + tolerant parse | 2 |
| `vader/lexer/` | New `module` keyword | 3 |
| `vader/parser/` | `ModuleDecl` AST + tolerant parse | 3 |
| `stdlib/std/*.vader` | Reorganised into per-module folders, `module` decl added | 4 |
| `vader/*` | `module` decl added to ~117 files | 5 |
| `tests/snippets/*` | `module "snippet"` prepended to ~250 files | 6 |
| `examples/*` | `module "main"` prepended | 6 |
| `bench/*` | `module` decls added | 6 |
| `vader.json` | `"modules": ["src/", "vader/"]` added | 6 |
| `src/resolver/` | `discoverModules` + index + R20xx + strict lookup ; legacy folder-module patches removed | 7 |
| `src/parser/` | Strict flip reserved (P1029/P1030 codes registered, not activated) | 7 |
| `src/diagnostics/codes.ts` | New R2020-R2028 + P1028-P1030 entries | 7 |
| `vader/types/` + `vader/resolver/symbol/` | Extracted as standalone modules to break the `vader/typecheck/types ↔ vader/resolver/symbol` cycle (Path C — decision #43) | 7 |
| `vader/resolver/discover.vader` | Header-only scanner using `parse_module_header` | 8 |
| `vader/resolver/loader.vader` | Strict-mode BFS with lazy `parse_source` (decision #44) | 8 |
| `vader/parser/parse_module_header` | Header-only byte scanner | 8 |
| `vader/diagnostics/codes.vader` | New R2020-R2028 + P1028-P1030 entries (mirror) | 8 |
| `vader/lsp/`, `vader/fmt/` | Keyword recognition + diagnostic | 9 |
| `tests/parity-broad.test.ts` | Byte-diff TS vs Vader on real modules | 10 |

## 7. Decision log

Open arbitrations from the design discussion, with the final call :

| # | Question | Decision |
|---|---|---|
| 1 | Module = folder or explicit declaration ? | **Explicit `module "..."` declaration** ; folder still constrains colocalisation but isn't the identity. |
| 2 | One module per folder, or multiple ? | **One module max per folder.** |
| 3 | Global uniqueness ? | **Yes**, collision is a compile error. |
| 4 | Imports : file-scoped or module-scoped ? | **File-scoped.** |
| 5 | Visibility levels ? | **Two only** : `export` (cross-module) and default (module-private). No file-private. |
| 6 | Sub-modules relationship ? | **Independent.** Prefix sharing has no semantics. |
| 7 | Name form ? | **`^[a-z][a-z0-9_]*(/[a-z][a-z0-9_]*)*$`** |
| 8 | Module decl position ? | **First non-trivial line.** Shebang + comments allowed before. One per file. |
| 9 | Module decl syntax ? | **String literal between quotes**, mirrors `import "..."`. |
| 10 | Relative imports `./`, `../` ? | **Removed.** |
| 11 | Bareword imports filesystem fallback ? | **Removed.** Strict index lookup. |
| 12 | Self-import ? | **Forbidden.** |
| 13 | Diagnostic file path format ? | **Filesystem path** (status quo). |
| 14 | `std/core` autoload ? | **Yes**, as an **implicit prelude** : every `std/core` export is in scope in every other module without `import`. The prelude doesn't apply to `std/core` itself. |
| 15 | REPL ? | **Implicit `module "main"`** injection. |
| 16 | `vader.json` required ? | **Optional.** Required only when external libs (post-MVP) need declaring. |
| 17 | Scan scope ? | **Whitelist** via `vader.json::modules`. Stdlib resolved separately (sidecar of binary in release, hard-coded path in dev). |
| 18 | Out-of-whitelist CLI files (snippets, examples) ? | **Auto-fallback** : the file's folder is added implicitly to the scan for that invocation only. |
| 19 | Snippet module name ? | **`module "snippet"`** everywhere. |
| 20 | Examples module name ? | **`module "main"`**. |
| 21 | Empty / non-`.vader` folder during scan ? | **Ignored silently.** |
| 22 | Diagnostic location on global-name conflict ? | **On the second occurrence**, secondary span on the first (R2011-like). |
| 23 | Compilation modes ? | **Focus** by default (typecheck reachable only) ; whole-project is post-MVP. |
| 24 | TS-first vs alternating with Vader port ? | **TS-first end-to-end** (Phases 1-6), then Vader port (Phases 7-8). |
| 25 | `vader/fmt/` `vader/lsp/` migration timing ? | **Same wave as the rest of `vader/`** (Phase 5). |
| 26 | Index cache on disk ? | **Out of scope MVP.** Cold scan on every invocation. |
| 27 | `vader/cli/main.vader` module name ? | **`module "vader/cli"`**, not `"main"`, to avoid global collision with `examples/*.vader` (which use `module "main"` via CLI fallback). |
| 28 | Intra-module duplicate decls ? | **Hard error** for non-fn decls (struct / type / const / enum / trait) across files of the same module ; **fn decls join the same overload set** (no error at decl ; T3032 surfaces only on ambiguous call sites). |
| 29 | Migration order with parser/resolver strictness ? | **Tolerant parser (TS + Vader) → migration of all `.vader` files → strict resolver + parser-flip.** Each phase is a green-build commit. |
| 30 | Re-exports ? | **Not supported.** No `export import "..."` form ; façade modules must wrap each binding manually. |
| 31 | Visibility leak (exported decl referencing a private type) ? | **Error.** Either `export` the referenced decl or refactor the signature. |
| 32 | User module shadowing `std/core` ? | **Error** via global uniqueness (§1.3). The stdlib's `std/core` folder claims the name first ; a second folder declaring `module "std/core"` raises the duplicate-name diagnostic. |
| 33 | Two destructured imports of the same name in the same file ? | **Error.** No silent shadowing across `import` lines, nor between a destructure and the `std/core` prelude. |
| 34 | Explicit `import "std/core"` from another module ? | **Error** : counted as a duplicate of the implicit prelude. |
| 35 | Import cycles (`A → … → A`) ? | **Forbidden.** Resolver-level diagnostic ; user must break the cycle. |
| 36 | Default whitelist when `vader.json` is absent or omits `modules` ? | **Entry file's containing folder + stdlib only.** Larger projects need an explicit manifest. |
| 37 | Malformed `module` decl (missing string, two strings, non-string token) ? | **Parser error.** `module` is always followed by exactly one double-quoted string literal. |
| 38 | Scan order determinism ? | **Not guaranteed.** Tests must not rely on which of two conflicting folders is the "first" vs "second" occurrence. |
| 39 | Follow symlinks during scan ? | **No.** Symlinked `.vader` files and symlinked folders are ignored. |
| 40 | Scope of the index across CLI subcommands ? | **Same scan + same diagnostics for every subcommand** (`run`, `build`, `dump`, `test`, `fmt`, `lsp`, `check`). Only the downstream work differs. |
| 41 | Glob patterns in `vader.json::modules` ? | **Not supported.** Literal folder paths only. |
| 42 | Multi-`vader.json` (monorepo with nested manifests) ? | **Out of scope MVP.** Single manifest at project root. |
| 43 | Phase 7 `vader/` folder-module cycle (`vader/typecheck/types ↔ vader/resolver/symbol`) ? | **Path C taken** (commit `cce6cd1f`) : extract `vader/types/` + `vader/resolver/symbol/` as standalone modules to break the cycle. Path A (rollback to per-file modules) and Path B (hybrid per-file for `vader/`) rejected as they'd erode SPEC §11's uniformity. |
| 44 | Phase 8 memory blocker (eager parse of every `.vader` OOMs the Vader GC) ? | **Header-only parse** (`parse_module_header` in `vader/parser/`) that extracts just the `module "..."` decl during discover ; full `parse_source` runs lazily on BFS visit. GC defaults bumped to 16 MB young / 64 MB old (2026-05-24) so the CLI handles the full `vader/` self-host typecheck out of the box ; lazy indexing remains a follow-up. |
| 45 | Parser strict-flip (P1029 / P1030 missing-decl + malformed-decl) ? | **Not activated.** Codes stay reserved in `codes.ts` / `codes.vader`. R2020 catches missing decls at resolver scan time, which is sufficient ; the parser-flip stays available for a future tightening if needed. |

This list freezes the design. Any deviation during implementation
needs to be brought back here as an amendment.

## 8. Issues encountered

> Both blockers below were **resolved** ; the entries are kept verbatim
> for traceability. See decision log entries #43 and #44 for the
> final calls.

### Phase 7 frozen (2026-05-22) → **resolved** (`cce6cd1f`, `68611417`) — `vader/` self-host architecturally incompatible with folder-modules

**Symptom.** Phases 1-6 landed clean (tolerant parsers, all .vader files
annotated with `module "..."`, examples + bench restructured into per-file
subfolders, codes registry + `discover.ts` foundation committed). Two sub-
commits of the Phase 7b strict flip landed (codes `a3c6ce0c`, discover
`9b43e33f`). The third sub-commit — wiring discover into the loader and
flipping `resolveImportPath` to strict index lookup — broke in cascade.

**Cause.** The Phase-5 decision to give every file under `vader/X/`
the same `module "vader/X"` declaration (one module per folder) is
incompatible with the self-host's actual dependency structure. Three
issues surfaced when strict mode activated :

1. **956 sub-path imports** — the existing self-host uses
   `import "vader/X/Y" { Z }` (a leftover of the legacy per-file
   resolver). Under folder-modules these names don't exist ; only
   `vader/X` does. Mechanical rewrite is possible (956 → 0) but reveals
   the next two issues.

2. **450 self-imports** — after rewriting `import "vader/X/Y"` to
   `import "vader/X"`, files inside `vader/X/` end up importing their
   own module. Strict mode emits R2024 ; in legacy mode the per-file
   modules made these legitimate cross-module imports. Cross-file
   references *within* the same folder-module need to drop the
   `import` line (visibility shared by §1.6) but the imported names
   must stay reachable — and the resolver's symbol merge in
   `collect.ts` first-wins (silent) when a sibling file's
   import-binding shadows a local export.

3. **Cross-folder cycle** — `vader/typecheck/types.vader` declares the
   `Type` union and imports `Symbol` from `vader/resolver/symbol.vader`.
   `vader/resolver/resolve.vader` and `vader/resolver/builtins.vader`
   reach back into `vader/typecheck/types.vader` for `Type` /
   `PRIMITIVE_NAMES`. Under per-file modules (legacy) the dependency
   stays at file granularity and is acyclic
   (`resolve.vader → types.vader → symbol.vader`). Under folder-modules
   (Phase 5) the dependency aggregates : `vader/resolver` and
   `vader/typecheck` become mutually dependent and the strict resolver
   emits R2005 ("import cycle detected"), per decision #4.

   Breaking this cycle requires either (a) co-locating `Symbol` and
   `Type` in the same module (architectural merge), or (b) decoupling
   via IDs / a type registry (`Symbol → TypeId`, lookup table outside).
   Both are multi-day refactors touching ~50+ files.

**Decision.** Phase 7 is frozen at sub-commit `9b43e33f` (discover.ts
landed but unwired). The strict-flip work (loader rewrite,
`resolveImportPath` strict, parser flip, prelude injection) sits behind
the architectural refactor. Three candidate paths to resume :

- **Path A — Rollback Phase 5 to per-file modules.** Each `vader/X/Y.vader`
  declares `module "vader/X/Y"`. Equivalent semantics to the legacy
  promote-to-folder-module patch. Existing imports stay valid. Cross-file
  private visibility *within* a folder disappears — every cross-file
  reference needs an explicit `export`. Cost : redo Phase 5 + audit
  missing exports (~1-2 h).
- **Path B — Hybrid : folder-modules for `stdlib/`, per-file for `vader/`.**
  `stdlib/std/*` keeps the Phase-4 layout (one file per module is a
  natural fit there ; flat sibling layout was the original pain point).
  `vader/*` reverts to per-file. SPEC §11 needs an amendment authorising
  the asymmetry. Same cost as Path A on the `vader/` side.
- **Path C — Architectural refactor of `vader/`.** Extract a `vader/types`
  module hosting `Type` + `PRIMITIVE_NAMES` (and any other Symbol-Type
  cross-references), keep folder-modules, follow with mass-rewrite of
  imports and self-import removal. Multi-day chantier touching 50+
  self-host files. Aligns the codebase with the design's folder-module
  rule but is the heaviest lift.

The 42 decisions in §7 stay frozen. The refactor path (whichever is
chosen) is its own chantier ; resuming Phase 7 strict-flip happens after
that work lands. Sub-commits `a3c6ce0c` + `9b43e33f` are additive
infrastructure and remain useful regardless of which path is chosen.

**Lessons (per `feedback_explore_before_commit_to_phase`).** The
Phase 1 design and Phase 7 plan agent both missed the
`Type ↔ Symbol` cycle — neither traced an actual cross-folder
dependency through the existing self-host before declaring the
folder-module rule applicable. A 30-minute walk of the `vader/`
dependency graph at design time would have surfaced the cycle and
re-routed Phase 5 (per-file vs per-folder) before the migration
phases ran. Future architecture-level work : run a `find imports |
folder-aggregate | check-DAG` pass on the existing codebase before
freezing decisions that assume specific aggregation rules.

### Phase 8 full port — blocked on eager parse memory (2026-05-22) → **resolved** (`a3e69534`)

A scratch port of `src/resolver/loader.ts`'s strict-mode BFS to
`vader/resolver/loader.vader` works end-to-end (38 modules indexed,
BFS reaches every transitive import) — but the compiled Vader CLI
OOMs under the default GC arenas (4 MB young / 16 MB old) on any
real entry because `discover_modules` parses every `.vader` file
in the scoped roots up-front (~170 files for stdlib + vader/* +
entry's folder). The TS pipeline runs in V8's heap and doesn't
notice ; the Vader self-host's GC arenas can't hold every parsed
`Program`.

Workarounds tested :
- bumping the GC arenas via `VADER_GC_YOUNG_BYTES` /
  `VADER_GC_OLD_BYTES` (16 / 128 MB) — works for broad-parity,
  unrealistic as a default for snippet runs.
- reverting `vader/resolver/loader.vader` to the legacy depth-1
  BFS — what ships today.

Resolution path : add a **header-only parse mode** to
`vader/parser/parse_source` that extracts just the `module "..."`
decl (and parser state needed to find it — shebang + comments
prelude + the `ident("module") + string` lookahead). `discover_modules`
calls the header-only path to build the name → folder index ; the
full `parse_source` runs lazily when BFS visits each module. Memory
footprint drops from "every Program" to "just the indexed file
list" — same shape as the TS version's behaviour under V8's
generational GC.

Estimated effort : ~2-3 h for the header-only parse infra +
re-port of `load_project`. Until then, Phase 8 ships with the
additive infrastructure committed (codes R2020-R2028 in
`vader/diagnostics/codes.vader`, `vader/resolver/discover.vader`
ready to wire), and the legacy depth-1 BFS continues to drive the
compiled Vader CLI.

**Resolved** (`a3e69534`). Header-only parse landed in
`vader/parser/` as `parse_module_header` ; `discover_modules` calls
it during the scan and the full `parse_source` runs lazily when BFS
visits each module. The Vader CLI now drives a strict resolver
end-to-end. **Update 2026-05-24** : GC defaults bumped to 16 MB
young / 64 MB old (`runtime/c/vader.h`), so the full `vader/` self-
host typecheck works without env-var overrides. Lazy indexing
remains a follow-up.

### Cross-file duplicate decls — silent first-wins still active (surfaced 2026-05-23)

**Symptom.** Decision #28 (and §1.6 "Intra-module collisions")
mandates a hard error (R2026) for non-fn cross-file duplicates :
two `struct Foo` in the same module across two files should fail
compile. In practice, `src/resolver/collect.ts` (and its Vader
mirror) silently first-wins this case — only intra-file duplicates
trigger R2004.

**Latent collisions today** (would surface as R2026 if the silencing
branches were removed) :

- `vader/vm/builder.vader` + `vader/vm/parser.vader` : `ScopeEntry`, `PendingBranch`
- `vader/typecheck/{enum_pass,decl}.vader` : `Color`
- `vader/typecheck/{field,struct_lit,dump,check,decl,impls}.vader` : `Point` (12 occurrences across 7 files — likely `@test` fixtures)
- `vader/typecheck/{dump,decl}.vader` : `Wrap`
- `vader/typecheck/{check,impls}.vader` : `Display`
- `vader/lower/{helpers,lower_expr}.vader` : `CellInit`

**Two ways out**, no decision taken yet :
- **(a)** Align code on spec : rename the latent collisions
  (`vm/ScopeEntry` → `vm/{BuilderScopeEntry,ParserScopeEntry}`, etc.)
  and remove the silencing branches in `collect.ts`. Re-emit R2026 for
  any future cross-file duplicate. The `Point` occurrences are probably
  per-test fixtures and can stay if `@test` fns are scope-isolated —
  needs a quick audit.
- **(b)** Accept the silent first-wins, revise decision #28 to
  document the actual behaviour (cross-file silent first-wins ;
  intra-file R2004). Update §1.6 to match.

Similar deviation on import-bindings (`collect.ts::bindImport`) :
two import-bindings of the same name across files of the same
module silently first-win, where §1.5 says imports are file-scoped
and the situation shouldn't arise (`collectModuleSymbols` should
either keep per-file symbol tables or fire R2011 on duplicates).
Same arbitrage : refactor to file-scoped, or revise the spec.

