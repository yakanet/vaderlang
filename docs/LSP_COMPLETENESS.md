# LSP completeness — plan

Single roadmap for taking `vader lsp` from "core navigation + diagnostics" to a
feature-complete language server : the read / navigate / format surface, the
shared analysis infrastructure underneath it, **and** the refactoring layer (the
code-actions framework, [§ Code actions framework](#code-actions-framework)).

The server lives under `vader/lsp/`. New capabilities are advertised in
`vader/lsp/lifecycle.vader::build_capabilities`, routed in
`vader/lsp/main.vader::dispatch`, and (almost always) reuse one of two caches
already built per request: the per-document AST index
(`vader/lsp/indexer.vader`, keyed by URI) and the typed-project cache
(`vader/lsp/state.vader::typed_project_for`, the load + typecheck of the
project rooted at the open file).

## Current state (implemented)

| Method | Handler | Notes |
|--------|---------|-------|
| `textDocument/didOpen` / `didChange` / `didClose` | `state.vader` | full-document sync (`TextDocumentSyncKind = 1`) |
| `textDocument/publishDiagnostics` (push) | `diagnostics.vader` | on open/change, **open file's project only** |
| `textDocument/hover` | `hover.vader` | typed hover + index decl + vaderdoc |
| `textDocument/definition` | `definition.vader` | local + cross-file (siblings + std/vader imports) |
| `textDocument/semanticTokens/full` | `semantic_tokens.vader` / `ast_tokens.vader` | |
| `textDocument/inlayHint` | `inlay_hint.vader` | inferred-type hints |
| `textDocument/signatureHelp` | `signature_help.vader` | |

Already on the TODO (Priority + §3.7): completion, rename, find-references,
code-actions framework, `repair.id` structured diagnostics, semantic-token /
grammar reconciliation.

## Value at a glance

Value rating across the **whole** plan (High value = *forte valeur*, Good value
= *bonne valeur*). The effort tiers + the 3.18 / additional sections below carry
the detail ; this is the one-look index.

**High value** — *forte valeur*
- `documentSymbol`, `formatting` (Tier 1) · `references`, `implementation`,
  `typeHierarchy` (Tier 2) · `codeLens` run-test (Tier 3) · file-operation
  auto-module/import rewrites, auto-import completion, organize-imports
  (Additional) · UTF-8 position encoding, IR virtual views
  (`workspace/textDocumentContent`) (3.18).

**Good value** — *bonne valeur*
- `documentHighlight`, `foldingRange`, `documentLink` (Tier 1) · `workspaceSymbol`,
  `typeDefinition`, `callHierarchy` (Tier 2) · completion docs,
  `linkedEditingRange` (Tier 3) · pull / workspace diagnostics, incremental sync
  (Tier 4) · diagnostic enrichments, completion snippets,
  `semanticTokens/range`+delta, `selectionRange` (Additional) · `SnippetTextEdit`,
  `rangesFormatting`, markup diagnostics, `Command.tooltip` (3.18).

**Infrastructure / UX** — enabling, not user-facing on its own
- reference index, workspace-symbol index, cross-file diagnostics, file-watch,
  incremental analysis (Shared infra) · `executeCommand` / `applyEdit`,
  `$/progress`, window messages, `configuration`, `willSaveWaitUntil` / `didSave`,
  dynamic registration, code-action enrichments (Additional).

**Deferred / out of scope**
- `inlineCompletion` (AI), `declaration`, `documentColor`, `inlineValue`,
  `moniker`, notebooks, relative-pattern filters.

## Shared infrastructure (build these first — several features depend on them)

### A. Project-wide reference index
A `Symbol → reference-spans` map across every file of the project, keyed on the
**resolved Symbol** (not the textual name) so a query never conflates shadowed
or unrelated identifiers of the same spelling. Built by walking each module's
AST and recording every `IdentExpr` use-site against the Symbol the resolver
bound it to. This is the keystone for **find-references**, **rename**,
**document-highlight**, **call-hierarchy**, and the "N references" **code lens**.
Cache it on the `ProjectCache` next to the typed result; invalidate with the
rest of the cache on any edit. Cost: one extra walk over the already-typed
project; bounded by project size.

### B. Workspace symbol index
A flat list of every top-level/exported decl across the project (`name`, kind,
file, span), for fuzzy `workspace/symbol` search and to seed completion's
scope-identifier set. Reuses the module discovery the loader already does
(`vader/resolver`); refresh on file add/remove (see infra D).

### C. Workspace / cross-file diagnostics
Today `typed_project_for` roots the analysis at the **open file**, so only that
file's transitive view is checked and a change in file X doesn't refresh
diagnostics in its dependents. Move to a project-rooted analysis (root at the
`vader.json` manifest, or the union of open documents) and republish
diagnostics for every affected file on change. Pairs naturally with infra E
(incremental analysis) so a whole-project recheck per keystroke stays cheap.

### D. File-watch + workspace folders
Handle `workspace/didChangeWatchedFiles` (react to git checkout / external
edits) and multi-root `workspace/workspaceFolders`. Invalidate the caches above
on watched-file events.

### E. Incremental analysis / caching
Every request re-parses + typechecks the full stdlib (~30 modules) behind the
per-edit cache. This is what the recurring "Plugin LSP4IJ might be slowing
things down" banner is about. Cache per-module `LoweredModule` / typed results
keyed by `(source_hash, compiler_version)` and only re-analyze the changed
module + its dependents. Cross-ref the **Bytecode cache on disk** TODO (§3.5) —
same mechanism, broader payoff. This is the single highest-impact item for
day-to-day responsiveness.

## Feature catalog

### Tier 1 — quick wins (reuse existing infra, no new index)

- **`textDocument/documentSymbol`** — outline / breadcrumbs / Cmd+F12. Map the
  per-document `DeclEntry[]` (indexer) to `DocumentSymbol[]` (name, kind, range,
  selectionRange, children for struct fields / enum variants / impl members).
  Capability: `documentSymbolProvider = true`.
- **`textDocument/formatting`** (+ `rangeFormatting`, opt. `onTypeFormatting`) —
  **the formatter already exists** (`vader/fmt/`). Run it on the document text,
  return one full-document `TextEdit`. Unlocks format-on-save. Capability:
  `documentFormattingProvider = true`. Lowest effort / highest ratio.
- **`textDocument/documentHighlight`** — highlight occurrences of the symbol
  under the cursor **within the open file** (read/write kinds). Needs only the
  in-file slice of infra A (or a local walk). Capability:
  `documentHighlightProvider = true`.
- **`textDocument/foldingRange`** — fold fn bodies, blocks, multi-line imports,
  `///` doc-comment runs. AST-driven (block spans) + a comment-run pass.
  Capability: `foldingRangeProvider = true`.
- **`textDocument/documentLink`** — make `import "path"` strings clickable
  (resolve to the module file, reuse `resolver.vader::module_path_to_absolute`).
  Capability: `documentLinkProvider`.

### Tier 2 — navigation (needs infra A / B)

- **`textDocument/references`** (infra A) — find-usages. Also the rename
  prerequisite. Capability: `referencesProvider = true`.
- **`workspace/symbol`** (infra B) — fuzzy project-wide symbol search (Cmd+T).
  Capability: `workspaceSymbolProvider = true`.
- **`textDocument/typeDefinition`** — jump to the **type** of the value at the
  cursor (vs its binding). Reuse the typed cache: inferred type → its decl span.
  Capability: `typeDefinitionProvider = true`.
- **`textDocument/implementation`** — from a trait (or trait method) to its
  impls, and vice-versa. High value in a trait-heavy compiler. Needs an
  impl index (trait → impls) over the typed project. Capability:
  `implementationProvider = true`.
- **`textDocument/prepareCallHierarchy`** + `callHierarchy/incomingCalls` /
  `outgoingCalls` (infra A) — who-calls-this / what-this-calls. Excellent for
  navigating the compiler. Capability: `callHierarchyProvider = true`.
- **`textDocument/prepareTypeHierarchy`** + `typeHierarchy/supertypes` /
  `subtypes` — trait → its impls (subtypes), type → traits it implements
  (supertypes), union → its members. High value in a trait / union language.
  Needs the impl index shared with `implementation`. Capability:
  `typeHierarchyProvider = true`.

### Tier 3 — productivity

- **`textDocument/codeLens`** — "▶ Run test" above every `@test` fn (wire to
  `cmd_test` / `vader test <file>`), and "N references" above decls (infra A).
  Capability: `codeLensProvider`.
- **Completion docs** (`completionItem/resolve`) — surface the signature +
  vaderdoc in the completion popup; lazy-resolved per item. Extends the
  completion TODO.
- **`textDocument/linkedEditingRange`** — rename-as-you-type for the local
  occurrences of the symbol under the cursor (lighter than full rename).

### Tier 4 — protocol modernization

- **Pull diagnostics** (`textDocument/diagnostic` + `workspace/diagnostic`,
  LSP 3.17) — let the client pull on demand; pairs with infra C for
  whole-project reporting.
- **Incremental sync** (`TextDocumentSyncKind = 2`) — apply ranged
  `contentChanges` instead of replacing the whole document. Matters for large
  files; requires a small text-buffer apply-edit helper in `state.vader`.

## Additional proposals (from the LSP 3.17 / 3.18 survey)

Cross-referenced against the full spec
([3.18](https://microsoft.github.io/language-server-protocol/specifications/lsp/3.18/specification/),
the current revision). Grouped by value, not effort — the tiers above stay the
effort/category view. The **LSP 3.18 additions** subsection below covers what's
new since 3.17.

### High value — Vader-specific

These exploit Vader's module system + explicit nominal imports : the highest
leverage beyond the stock surface.

- **File-operation events** (`workspace/willRenameFiles` / `didRenameFiles` /
  `willCreateFiles` / `didCreateFiles` / `willDeleteFiles`). Vader couples
  `module "path"` to the file's physical location, so a file move *is* a
  refactor :
  - on **rename / move** of a `.vader`, `willRenameFiles` returns a
    `WorkspaceEdit` that rewrites the file's `module "…"` decl **and** every
    `import "…"` that pointed at it across the project ;
  - on **create**, auto-insert the correct `module "…"` header (derived from
    the path) ;
  - on **delete**, flag the now-dangling imports.
  Reuses the project-wide reference index (infra A) + the `resolver`'s
  path↔module mapping. Capability: `workspace.fileOperations`.
- **Auto-import on completion** (`completionItem.additionalTextEdits`).
  Completing an unimported exported symbol also inserts its
  `import "path" { … }` (or merges the name into an existing block from that
  module), respecting the std → vader → third-party grouping. The single
  biggest productivity win for an explicit-nominal-import language. Extends the
  completion item.
- **Organize imports** (`source.organizeImports` code action +
  `workspace/executeCommand` companion). Sort the import blocks
  (std → vader → third-party), dedup, merge multiple blocks from the same
  module, and **drop unused names** (shares analysis with the *unused imports*
  warning). Offered as a `source.organizeImports`-kind action and on save when
  the client asks. Lives in `vader/lsp/actions/organize_imports.vader` (the
  code-actions framework) ; re-emits the block via `vader/fmt`.
- **Type hierarchy** — detailed in Tier 2 (`prepareTypeHierarchy` +
  `supertypes` / `subtypes`). Listed here too : trait ↔ impls ↔ union members
  is high-value navigation in a trait / union language.

### Good value — enrichments

- **Diagnostic enrichments** — the current `Diagnostic` (`vader/diagnostics`)
  carries only code + message + span ; the protocol allows more, and editors
  render it :
  - **`relatedInformation`** — secondary locations : R2004 duplicate points at
    **both** declarations, "field does not exist" points at the type's def, a
    type-mismatch points at the expected binding ;
  - **diagnostic tags `Unnecessary` (1) / `Deprecated` (2)** — the editor fades
    unused code / strikes deprecated ; wire `Unnecessary` to the *unused
    imports* warning + W0002 unreachable-code ;
  - **`codeDescription` (href)** — link each code (T3020, …) to its docs page ;
    pairs with the `repair.id` TODO + `vader/diagnostics/codes.vader`.
- **Completion snippets** (`insertTextFormat = Snippet`) — `fn` → fn skeleton,
  `match` → scaffold with arm placeholders, struct-literal with fields.
- **`semanticTokens/range` + `/full/delta`** — colour only the visible viewport
  (range) + ship incremental token diffs (delta) instead of re-tokenising the
  whole file each edit. Perf for large files (the "LSP4IJ slowing things down"
  banner). We only have `/full` today.
- **`textDocument/selectionRange`** — semantic expand / shrink selection
  (expr → stmt → block → fn). AST-driven, cheap. Capability:
  `selectionRangeProvider = true`.

### Infrastructure & UX

- **`workspace/executeCommand` + `workspace/applyEdit`** — server-invokable
  commands (organize-imports, run-test, regenerate) + server-initiated edits ;
  underpins the code-lens commands and the organize-imports companion.
- **`$/progress` + `window/workDoneProgress`** — progress UI for the initial
  project index + workspace-wide diagnostics (pairs with infra E).
- **`window/showMessage` / `showMessageRequest` / `showDocument`** — surface
  analysis failures, offer follow-up actions, open a target document.
- **`workspace/configuration` + `didChangeConfiguration`** — read user settings
  : toggle inlay hints, pick a format profile, enable / disable diagnostics.
- **`textDocument/willSaveWaitUntil` + `didSave`** — format-on-save through the
  protocol (server returns edits before save) + trigger the heavier
  whole-project analysis on save rather than on every keystroke.
- **Dynamic registration** (`client/registerCapability`) — register a
  capability only when actually available (e.g. formatting only if `vader fmt`
  is reachable).
- **Code-action enrichments** (see [§ Code actions framework](#code-actions-framework))
  — `isPreferred`, `disabled` with a reason, `data` + resolve for lazy edits.

### Out of scope (deliberately skipped)

- `textDocument/declaration` — no header/impl split, identical to `definition`.
- `documentColor` / `colorPresentation` — no colour literals.
- `textDocument/inlineValue` — needs a DAP debugger (none yet).
- `textDocument/moniker` — cross-repo symbol identity (Sourcegraph-style), niche.
- Notebook documents — N/A.

### LSP 3.18 additions

New in 3.18 (`@since 3.18.0`) on top of everything above :

**High value (Vader-aligned)**

- **UTF-8 position encoding** (`general.positionEncodings` negotiation). 3.17
  forced UTF-16 offsets ; 3.18 lets the server negotiate `utf-8`. Vader works in
  **bytes** internally, so advertising `utf-8` removes the byte ↔ UTF-16
  conversion the LSP does on every span — and kills a class of off-by-N bugs on
  multi-byte (accented / emoji) lines. Negotiated at `initialize` ; foundational
  and cheap, so do it early — it changes the offset model every handler uses.
- **`workspace/textDocumentContent`** — server-provided **virtual read-only
  documents**. Expose the compiler's own IR as openable views under a `vader:`
  URI : `dump --stage=typed-ast / lowered / cfg / bytecode / c` for the file
  being edited, without leaving the editor. A killer feature for a compiler.

**Good value**

- **`SnippetTextEdit`** (+ `workspace.workspaceEdit.snippetEditSupport`) — edits
  carrying snippet placeholders / a final cursor position. Lets **rename** and
  **code-actions** drop the cursor on the new name (e.g. after extract-fn) and
  tab through placeholders.
- **`textDocument/rangesFormatting`** — format several selected ranges at once
  (vs the single-range `rangeFormatting`).
- **Markup diagnostic messages** (`textDocument.diagnostic.markupMessageSupport`)
  — Markdown in diagnostic messages : inline code, a snippet of the offending
  type, a link. Richer than today's plain string.
- **`Command.tooltip`** — tooltip text on commands / code-lens entries.

**Lower / deferred**

- **`textDocument/inlineCompletion`** — inline ghost-text (Copilot-style) ;
  protocol hook only, needs an AI backend — deferred / out of scope for now.
- **Relative-pattern document filters** / file-watch globs, regex-engine
  announcement, new language ids — minor ; adopt opportunistically.

## Code actions framework

The refactoring layer — `textDocument/codeAction`. Merged here from the former
`LSP_CODE_ACTIONS.md` design note. **Status**: backlog, post-MVP — documented so
it can be picked up cleanly; no LSP code is touched until then. The
`CLAUDE.md` §6 idiomatic-patterns rules (`if` for ≤ 2 cases, `match` for ≥ 3;
plain `if` for null narrowing; method syntax when an impl exists) surface
naturally as cursor-driven refactorings, so a small framework pays back from
action #2 onward — one-off code per action would churn the LSP layer each time.

### Components

1. **Capability declaration** — add `codeActionProvider` to the `initialize`
   response in `lifecycle.vader` (mirror `inlayHintProvider`).
2. **Position → expression walker** — new `vader/lsp/expr_at.vader` (~150 LoC):
   top-down traversal returning the innermost `Expr` enclosing a `(line,
   column)`. Independent of the hover walker for now; merge later if both
   converge (open question #4).
3. **Action registry** — new `vader/lsp/code_actions.vader`: records of
   `{ kind: string (LSP `CodeActionKind`), title: string, is_applicable :: fn(node: Expr, ctx: ActionCtx) -> bool, apply :: fn(node: Expr, ctx: ActionCtx) -> TextEdit[] }`.
   `handle_codeAction` runs each predicate against the `expr_at` node and
   returns the union of titles + edits.
4. **Edit production** — server-side `TextEdit[]` (no `executeCommand`
   round-trip); each action re-emits the transformed node through the printer.
5. **Expression printer adapter** — expose `emit_expr(e: Expr) -> string` from
   `vader/fmt/printer.vader` (factor a single-expr path out of `emit_program`
   rather than wrapping a synthetic program). Land this refactor as its own
   commit before the first action.

### First actions to ship

1. **`match` → `if`** when arms ≤ 2 and patterns reduce to boolean predicates
   (literals, `is Type as alias`, `null` checks).
2. **`if` → `match`** when an `if` / `else if` chain has ≥ 3 branches all
   discriminating the same scrutinee.
3. **Null-narrow rewrite** — special case of #1, surfaced independently as a
   quick-fix on `match x { is null … }`.
4. **UFCS conversion** — `f(x, …)` ↔ `x.f(…)`, both directions, offered when the
   receiver type resolves `f` as a method (needs the typed cache). The
   mechanical way to apply the §6 "prefer method syntax when the impl exists"
   convention.
5. **Organize imports** — see the High-value subsection above
   (`source.organizeImports`): sort / dedup / merge / drop-unused, re-emitting
   the import block via `vader/fmt`.

Each action lives under `vader/lsp/actions/<action_name>.vader` and
self-registers into the registry.

### Open architectural questions

Resolve with the user when implementation starts (CLAUDE.md §8) :

1. **Registry shape** — array of records vs. trait-dispatched provider (lean
   records for MVP).
2. **Printer adapter scope** — full `emit_program` refactor vs. a thin
   synthetic-program wrapper.
3. **Action discovery** — central registration vs. per-file init-time
   self-registration vs. comptime-generated table (tied to comptime init-effect
   support).
4. **Position walker reuse** — does `expr_at` subsume the hover walker?
5. **Lossy-conversion policy** — when a `match` has patterns that can't be
   lowered (struct destructuring, guards): refuse, offer-with-warning, or emit a
   partial conversion?

Caveats (verify before acting): the `vader/lsp` file layout has shifted since
the original note — re-check line references in `ast_tokens.vader` /
`semantic_tokens.vader` / `printer.vader`. If `STRUCT_LIT_PAREN_GRAMMAR.md`
(`Foo(x = 1)`) lands, `expr_at` + the match-pattern actions must handle the new
struct-lit shape — sequence this work after that grammar decision.

### Diagnostic-driven companion (post-v1)

Once the framework lands, the compiler can emit advisory diagnostics ("this
2-case match would be clearer as `if`") whose `relatedInformation` points at the
matching code action — same infrastructure as the `repair.id` structured
diagnostics (TODO §3.7) and the diagnostic-enrichment item above. Deferred until
v1 validates the action set.

### Implementation order (code actions)

Four sprints when work picks up :

| Sprint | Deliverable |
|---|---|
| 1 | Capability declaration + `expr_at` walker + registry skeleton + first stub action (no-op edit) — proves the dispatch path end-to-end. |
| 2 | `match` → `if` action + printer adapter refactor for `emit_expr`. |
| 3 | `if` → `match` + null-narrow + snapshot corpus under `tests/snippets/code_action_*`. |
| 4 | UFCS conversion (`f(x)` ↔ `x.f()`) — needs the typed cache to confirm the receiver resolves the method. |

Verification: unit-test `expr_at` (`(snippet, line, col) → Expr kind`), snapshot
each action (`(source, cursor) → TextEdit[]`), round-trip `match→if` then
`if→match` (reparses + typechecks), and a manual editor lightbulb test.

## Suggested sequencing

0. **Foundational — negotiate UTF-8 position encoding** (3.18) at `initialize`,
   before adding more position-sensitive handlers : it changes the offset model
   every handler uses, and Vader is byte-native, so doing it first lets all the
   features below skip the byte ↔ UTF-16 dance.
1. **`documentSymbol` + `formatting`** — near-free (existing index / existing
   formatter), immediately visible. Ship first.
2. **Infra A (reference index)**, then **`references` + `documentHighlight` +
   rename** on top of it (rename already planned).
3. **Vader-specific high-value** — **organize-imports** (rides the formatter +
   the unused-imports analysis), then **file-operation auto-module / import
   rewrites** (rides infra A). Distinctive, high leverage.
4. **Infra E (incremental analysis)** + **`$/progress`** — the responsiveness
   win; unblocks comfortable whole-project features.
5. **Infra C + pull / workspace diagnostics** + **diagnostic enrichments**
   (`relatedInformation`, tags) — correct, richer cross-file errors.
6. **Navigation tier 2** (`workspaceSymbol`, `typeDefinition`, `implementation`,
   `callHierarchy`, `typeHierarchy`) and **`codeLens` run-test**.
7. **Completion polish** — **auto-import**, snippets, docs-in-completion.
8. **IR virtual views** (`workspace/textDocumentContent`) — open `vader:` views
   of `dump --stage=…` for the edited file. High-leverage for a compiler ;
   slot in once the typed cache is solid.
9. **Protocol modernization** (incremental sync, `semanticTokens/range`+delta,
   `selectionRange`, `SnippetTextEdit` cursor placement) + UX (window messages,
   configuration) as polish.

Each feature: advertise the capability in `lifecycle.vader`, add a
`handle_*` in a new `vader/lsp/<feature>.vader`, route it in `main.vader`, and
prefer reusing `typed_project_for` + the indexer over bespoke parsing.
