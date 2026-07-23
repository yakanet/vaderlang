# Vader lint — design plan

> Status: **rev 3 — v1 (`unused-export`) implemented.** Rev 1 was reviewed by
> four adversarial passes (soundness / gaps / architecture / risk); rev 2 folded
> them in. **Rev 3 records the mechanism pivot forced during implementation: the
> §4 DCE input-vs-output diff is structurally entry-module-only (lazy lowering
> never materialises an unreached imported-module fn — see the Issues section),
> so v1 ships a name-based project-wide reachability instead.** The shipped slice
> is `vader lint <file>` → W0012, fn-exports only, **plus LSP surfacing** (inline
> faded squiggle, scoped to the open document — §9). Open decisions in §10 are the
> next round.

## 1. Why — offload hygiene out of the compiler

**The organizing idea: move hygiene / project-wide checks OUT of the default
`vader build` into a separate lint layer.** Two payoffs:

1. **A leaner compiler.** The default build should do one job — *compile, and
   flag likely bugs*. Anything that's hygiene/style is dead weight on the hot
   path. Concretely, `check_dead_code` (W0007) runs a **dedicated project-wide
   AST walk on every module of every build** (`orchestrate.vader:394` entry +
   `:437` every imported module — its own "entry-module-only" vaderdoc is
   **stale**). Offloading it to `vader lint` removes that walk from every build.
2. **A home for new project-wide lints** that must NOT touch the build — starting
   with `unused-export`, which catches things the per-module W0007 structurally
   can't (an `export` unreachable across the whole project, e.g. the dead
   `inherit_bounds` fn).

Same engine feeds `vader lint` (opt-in / CI) and — later — the LSP. The default
build only ever loses checks; it never gains one.

## 2. The two principles that must hold

- **P-lean (the point).** Moving a check to the lint layer must make the default
  build **do less**, never more. A check with its own dedicated pass (W0007) is a
  real offload — the build stops running it. A check that piggybacks a *needed*
  pass (shadow/redeclaration in the resolver body-walk; empty-import in
  `collect`; loop-label in the typecheck stmt-walk) offloads no compute — only its
  *emission* is re-categorized. Never add a project-wide walk to the default build.
- **P-safe (inherit dead_code's bias).** `dead_code.vader` commits to
  *"under-report, never false-positive — a false positive tells you to delete
  live code."* Every lint here adopts the same bias. **When in doubt, stay
  silent.** This is what makes the scoping in §5 non-negotiable, and why `--fix`
  never deletes (§7).

## 3. Warning vs lint — corrected classification

| Code | Flags | Nature | Verdict | Offload? |
|------|-------|--------|---------|----------|
| W0001 | use of `@deprecated` | migration | **warning** | — |
| W0002 | unreachable code after divergence | logic | warning (borderline, D-frontier) | piggybacks typecheck |
| W0005 | wildcard silences exhaustiveness | **safety** (caused the ref-collapse miscompile) | **warning — never demote** | — |
| W0007 | unused **private** declaration | hygiene | **lint** | **yes — dedicated walk, real build win** |
| W0008 | local shadows outer | style | **lint** | no (piggybacks resolver) |
| W0009 | redeclaration in a block | probable bug | warning (borderline, D-frontier) | piggybacks resolver |
| W0010 | prefer loop-var over label | idiom | **lint** | no (piggybacks typecheck) |
| W0011 | empty import modifier list | cleanliness | **lint** | no (piggybacks collect) |
| W0013 | `[<fresh>] * n` shares one element | **safety** (caused the `predecessors_of` SIGSEGV) | **warning — never demote** | no (piggybacks typecheck) |

Only **W0007** is a dedicated pass → the one existing check whose offload is a
genuine build saving. W0008/10/11 re-categorize (emission-gated) but stay
computed on their needed walks. **W0005 and W0013 stay warnings** (safety, not
hygiene — both fired on shapes that miscompiled or segfaulted).

## 4. First slice — `unused-export` (the payoff, shipped alone)

Do **this and only this** first. It stays tiny and forces us to confront the
real reachability shape before building any framework.

**Mechanism — name-based project-wide reachability (NOT the DCE diff).** The
originally-planned mechanism (diff `prune_unreachable_fns`' input vs output) is
**structurally entry-module-only** and was abandoned during implementation — see
the Issues section: lazy lowering never materialises an unreached
imported-module fn, so a dead `export` in an imported module is absent from
*both* sides of the diff. The motivating shape (`inherit_bounds`, since deleted)
lives in an imported module, so the diff could never have caught it.

The shipped mechanism reuses the **same name-reachability engine as W0007**
(`vader/typecheck/dead_code.vader`) — its `collect_*_names` collectors + BFS —
but:

- merges the top-level decls of **every (non-stdlib) module**, not one module;
- drops W0007's "an `export` is a root" clause, so a public fn unreachable
  across the whole project is *flaggable* (`is_export_lint_root` = `is_root_decl`
  minus the public clause: `main` + `@test`/`@extern`/`@intrinsic`/`@export`/
  `@allow_unused` stay roots, plain `export` does not);
- flags each public, non-root **fn** whose name no live decl reaches → W0012.

The driver is `dead_exports(decls: AST.Decl[]) -> DeadExport[]`, colocated in
`dead_code.vader`, sharing `collect_decl_refs` + `bfs_reachable` + the root
policy with W0007. It runs on **load + parse only** (a name walk needs no types),
so it is far cheaper than a lowering-based diff (~0.5 s self-lint vs ~12 s) and
immune to lazy lowering hiding a dead export.

- Stdlib is filtered by the retained `display_path` (`std/*` prefix). Stdlib is
  skipped entirely from the walk: it never references user code, so it can
  neither root nor keep-alive a user export.
- P-safe bias identical to W0007: a name collision across modules marks the name
  reachable → **under-report, never a false positive**. A fn is always named at
  every call / UFCS / value / generic-instantiation site, so a genuinely used
  export is never flagged (verified: 9-symbol spot-check of the self-lint's
  100+ findings, zero false positives).

**Surface:** `vader lint <file>` (new subcommand) only. `vader build --lint` was
dropped from v1 for a minimal surface (revisit under §6). A plain `vader build`
never runs the lint (P-lean holds — verified: `build --target=c` emits no W0012).

## 5. Scope — what `unused-export` v1 covers, and what it must NOT touch

Per P-safe, v1 is **deliberately narrow**. Everything below is a false-positive
vector the reviews found; each is handled by *excluding it from scope*, not by
guessing.

- **Fn exports only (a deliberate v1 scope, no longer a mechanism limit).** With
  the name-based walk, extending to exported *types / consts / traits* is
  trivial and safe (the collectors already record type-name references) — the
  old "DCE tracks the fn call graph only" reason is gone. Two reasons keep v1 to
  fns anyway: (1) the minimal "one rule first" posture (§9); (2) a real
  **false-positive hole on enums** — `dead_code.vader`'s `DotVariantExpr` arm
  collects nothing, so an enum used *only* via bare `.Variant` inference would be
  flagged dead (violates P-safe). A fn has no such hole (always named at its call
  site). Types/consts/traits are a safe follow-up **minus enums**; enums need a
  collector fix first.
- **Generic fn exports: now covered for free.** Name-based reachability marks a
  generic's *name* reachable at every instantiation site, so a dead generic
  export is flagged and a live one is not — no template→instance remap needed.
  (The abandoned DCE diff couldn't do this; the pivot is strictly better here.)
- **Roots — solved by construction with the name-based pivot.** Because the walk
  reuses W0007's own root policy (`is_export_lint_root` = `is_root_decl` minus
  the public clause) and runs on the **pre-bake, pre-prune AST**, the DCE's
  root gaps never arise:
  - `@test` — already a W0007 root; a fn used only by its colocated test stays
    live (no `keep_tests` flag needed — tests are just decls in the walked AST).
  - `@comptime` — the name walk runs *before* baking, so a fn referenced only
    inside a `@comptime` expression is still named in the AST → reachable. No
    special comptime root needed.
  - `@intrinsic` / `@allow_unused` / `@export` / `@extern` — all in
    `is_export_lint_root`, so they root exactly as W0007 intends.
  - **Multi-entry** — every fn named `main` (any module) is rooted, so a repo
    with several entries reaches all of them. A rootless library (no `main`) has
    no reachability seed → `vader lint` **warns and reports nothing** rather than
    false-flag its whole API (a proper entry policy is §10 D-roots, deferred).
- **Already safe (confirmed, no work needed):** `@extern`/`@export` fns are roots
  (`is_fn_root`) → not flagged; trait vtable / dynamic-dispatch targets are marked
  via `visit_virtual` + the `vtable_entries` fixpoint → not flagged.

## 6. Offloading the existing hygiene lints — gate at the emit boundary

To move W0007/8/10/11 off the default build, **do not build a registry that
"orchestrates" checks it can't invoke.** The checks are inline in the resolver /
typecheck / collect passes; a catalog can't gate them without threading config
through every site. Instead:

- **One filter at the single consumption boundary.** Every warning already funnels
  through `diags.push(warning(...))` → dedup → render, and each diagnostic carries
  its code. Add one predicate `is_optin_lint(code)` and drop opt-in-lint codes
  from the default output unless `--lint` / `vader.json` opts in. The piggybacked
  checks keep running (cheap, on a needed walk); only their *output* is filtered,
  centrally, by code.
- **The one production-side change:** skip `check_dead_code` (the dedicated walk)
  in the default build — one `if` at `orchestrate.vader:394/437`. That's the P-lean
  win; no registry involved.
- **Keep the `W####` codes.** Do NOT renumber to `L####`: it's a one-way rename
  that breaks every inline suppression, doc, and the message-agnostic CI corpus
  (`diagnostics-corpus.test.ts` snapshots by `[CODE]`; fixtures `w0007_*`, `w0008_*`,
  `w0010_*`, `w0011_*`). "Lint-ness" is a one-bit predicate over the code, not a new
  namespace.

## 7. `--fix` — never destructive

Auto-removing a dead export on a *precise* check whose precision is the very
source of the residual false positives (§5) = deleting live code on any miss.
Per P-safe:

- `--fix` **never** auto-deletes an export or declaration. For dead exports it
  emits a **reviewable** report/patch only.
- Autofix is capped to genuinely-local, information-preserving rules — W0011
  (drop an empty `{}` modifier), W0010 (label→loop-var) — and rides the **existing**
  LSP code-action registry (`vader/lsp/actions/`), not a new lint autofix engine.

## 8. Rollout — baseline first

The compiler's first `vader lint` run surfaces the *union* of whatever v1 can't
yet exclude. Even scoped to fn-exports it may list a handful. So:

- Ship with a **baseline / allowlist** (a committed list of known/accepted
  findings) so CI can gate on *new* findings without drowning in the initial set.
- Any commit that flips a default-output behavior (dropping W0007 from
  `dump --stage=lowered-ast` / build stderr) **regenerates the diag corpus in the
  same commit**.
- Migration cost of generalizing `@allow_unused` → `@allow(<rule>)` is **~nil**:
  there is exactly one in-tree `@allow_unused` (its own definition). Not a blocker.

## 9. Deferred — build only when a second rule forces it (YAGNI)

Rev 1 front-loaded a framework. Cut it. The following land **only** when a second
concrete rule or a real config request demands them — informed by two real rules,
not one imagined shape:

- A `vader/lint/` module + `LintRule` / `LintScope` registry.
- `LintCategory` as a **separate enum** — for now, "lint vs warning" is a one-bit
  predicate over `WarningCode`; the 3-way Correctness/Hygiene/Style split maps
  cleanly onto existing `Severity` (Warning vs Info/Hint) and earns no extra
  dimension yet.
- `vader.json` `lint` section + generalized `@allow(<rule>)` (needs precedence
  rules + decorator-arg parsing + unknown-rule handling — all unspecified today).
- ~~**Project-wide lints in the LSP.**~~ **DONE (2026-07-19).** The rev-2 fear —
  "the LSP would need lowering+DCE per `didSave` (~the self-compile cost)" — was
  a consequence of the abandoned DCE-diff mechanism. The shipped **name-based**
  W0012 needs no lowering, and the LSP **already loads + typechecks the whole
  project** on every debounced flush (`typed_project_for` → `check_file`). So
  W0012 is a bare name-walk over decls **already in memory** (`cached.project`) —
  the freeze concern is moot. `unused_export_diags` (`vader/lsp/analysis/
  state.vader`) runs the `vader lint` recipe over the cached project in the
  diagnostics path only (NOT at cache-build, so hover/completion never pay it);
  `publish_diagnostics_for_uri` merges it in and the existing per-file filter
  scopes findings to the open document, exactly as W0007. W0012 is faded
  (DiagnosticTag Unnecessary). Never touches the shared typecheck path → still
  invisible to `vader build` (P-lean).
- `unused-import`. It gets **nothing** from the DCE (imports aren't call-graph
  nodes) — it's the abandoned W0006 (`dead_code.vader:11-14`: span-keyed,
  `files[0]`-only). Treat as a separate, unproven effort — not "free with the DCE".

## 10. Open decisions

- **D-frontier.** W0002 (unreachable-code) and W0009 (redeclaration): keep as
  warnings, or demote to lints? (Marked borderline in §3.)
- **D-roots.** The exact root/entry policy for `vader lint`'s reachability
  (§5): union all subcommand entries? a `vader.json` `entries` set (empty today)?
  a `--entry` flag? This is the crux of correctness for a multi-entry repo.
- **D-baseline.** Baseline format + where it lives (`vader.json`? a
  `.vaderlint-baseline`?) and how CI diffs against it.
- **D-gate-point.** Filter at render (§6) vs at `diags.push` — render is simpler
  (one site) but a pushed-then-dropped diag still costs its allocation; confirm
  render-side is fine.

## 11. Non-goals

- No default-build slowdown (P-lean). Any regression there is an implementation
  bug, not the design.
- No destructive autofix (P-safe). Dead-export removal is always human-reviewed.
- No framework ahead of demand. Registry/category/config/LSP grow when a second
  rule justifies them, not before.
- No global-deadness oracle. `unused-export` reports "unreachable from the pinned
  roots," scoped to the project's own (non-stdlib) fn-exports — nothing more.

## 12. Issues encountered (2026-07-19)

**The §4 DCE input-vs-output diff cannot see imported-module dead exports.**

- **Symptom.** `vader lint vader/cli/main.vader` built on the DCE diff reported
  **0** findings — including the motivating `inherit_bounds`. The entry-module
  fixture (`orphan`) *was* flagged, so the mechanism half-worked.
- **Cause.** `vader/lower/lower.vader:92-141` lowers **only the entry module
  eagerly**; every imported module is lowered **lazily** (bodyless signatures up
  front, with-body fns materialised on demand from call sites, "the DCE culls
  the rest"). A dead `export` in an imported module is therefore **never
  lowered** → absent from `prune_unreachable_fns`' input *and* output → invisible
  to any input-vs-output diff. Confirmed: `dump --stage=lowered-ast … | grep
  inherit_bounds` → 0. The plan's §4 (and its four review passes) missed that
  lazy lowering pre-empts the diff for non-entry modules.
- **Fix.** Pivot to **name-based project-wide reachability** over the parsed AST
  (which retains *all* decls, dead or not), reusing `dead_code.vader`'s
  collectors + BFS with the plain-`export`-is-not-a-root policy. Runs on
  load+parse (~0.5 s self-lint vs ~12 s for the DCE path), catches
  imported-module dead exports (100+ real findings across the compiler, 9-symbol
  spot-check → zero false positives), and covers generic exports for free.
- **Vader-port note.** This is *the* load-bearing lesson: **for whole-project
  "is X ever used?" questions, walk the AST, not the lowered project** — lowering
  is lazy and deletes the very thing you are trying to detect. Any future
  project-wide lint (`unused-import`, dead types/consts) must start from the AST.

**`inherit_bounds` was deleted mid-session (staged deletion, origin unexplained).**
Noted for the record — the plan's canonical example no longer exists in the tree;
the lint's regression coverage uses synthetic fixtures instead, which don't
depend on any specific compiler symbol surviving.
