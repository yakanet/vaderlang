# LSP code actions framework — design note

The Vader LSP (`vader/lsp/`) currently ships read-only language services :
semanticTokens, definition, hover, inlayHint, signatureHelp. There is no
`textDocument/codeAction` handler and no `codeActionProvider` capability
declared in `vader/lsp/lifecycle.vader:81-113`. This note captures the
design for adding a **general code-actions framework**, with `match ↔ if`
conversion as the first concrete action.

**Status** — backlog, post-MVP. Documented now so the work is ready to
pick up cleanly once the self-host port closes. No compiler / LSP code
gets touched until then.

## Why a framework, not a one-off

The new `.claude/CLAUDE.md` §6 idiomatic-patterns rules
(`if` for ≤ 2 cases, `match` for ≥ 3 ; plain `if` for null narrowing)
naturally surface as cursor-driven refactorings. Two more candidates
are visible from the stdlib + self-host porting work :

- **Convert `match` → `if`** for arms ≤ 2 reducible to boolean predicates.
- **Convert `if`/`else-if` chain → `match`** when ≥ 3 branches discriminate
  the same scrutinee.
- **Null-narrow rewrite** — `match x { is null → … _ → … }` ⇒ `if x == null`.
- Future obvious refactorings : extract-fn, inline-let, rename-symbol,
  organize-imports, expand-fn-body to one-liner and vice versa.

Each new action reuses the same scaffolding (position resolver, registry
dispatch, edit emitter, printer adapter). One-off code per action would
churn the LSP layer every time. A small framework pays back from action
#2 onward.

## Current LSP state — what's missing

Findings from exploration (cite-only, file:line) :

- `vader/lsp/main.vader:85-165` — JSON-RPC dispatch. No `textDocument/codeAction`
  arm ; unknown methods fall through to `MethodNotFound`.
- `vader/lsp/lifecycle.vader:81-113` — `initialize` response does not
  declare `codeActionProvider`.
- `vader/lsp/hover.vader:320-475` — position-resolution walker exists,
  but stops at identifier granularity (`DocIndex.find_at`). **No generic
  `Expr`-at-position function.**
- `vader/parser/ast.vader:532-561` — `IfExpr` + `MatchExpr` AST nodes
  are well-formed and structurally close enough for the simple-pattern
  cases.
- `vader/fmt/printer.vader:1380-1429` — `emit_if` / `emit_match` already
  exist, but only via the program-level `format_source(source, path)`.
  No `emit_expr(e: Expr) -> string` is exposed.

## Framework components

### 1. Capability declaration
`vader/lsp/lifecycle.vader` adds `codeActionProvider` to the `initialize`
response. Mirror the shape used for `inlayHintProvider` (see TODO §3.7).

### 2. Position → expression walker
New file `vader/lsp/expr_at.vader` (~150 LoC). Top-down AST traversal
returning the innermost `Expr` enclosing a `(line, column)`. Independent
of the hover walker for now ; a later refactor can merge if both walkers
converge on the same pre-order shape.

### 3. Action registry
New file `vader/lsp/code_actions.vader`. A registry of `CodeAction`
records :

- `kind: string` — matches LSP `CodeActionKind` (`"refactor.rewrite"`,
  `"quickfix"`, …).
- `title: string` — human-readable label.
- `is_applicable :: fn(node: Expr, ctx: ActionCtx) -> bool`
- `apply :: fn(node: Expr, ctx: ActionCtx) -> TextEdit[]`

`handle_codeAction` walks the registry, runs each predicate against the
node returned by `expr_at`, and returns the union of titles + edits.

### 4. Edit production
Server-side `TextEdit[]` ranges (no `executeCommand` round-trip). Each
action computes the replacement text by re-emitting the transformed
node through the printer.

### 5. Expression printer adapter
Expose `emit_expr(e: Expr) -> string` from `vader/fmt/printer.vader`.
Refactor `emit_program` to factor out a single-expr path, rather than
building a synthetic-program wrapper. The refactor touches the
formatter's test surface and should be split off as its own commit
before the first action lands on top.

## First actions to ship

1. **`match` → `if`** when arms ≤ 2 and patterns reduce to boolean
   predicates (literals, `is Type as alias`, `null` checks).
2. **`if` → `match`** when an `if`/`else if` chain has ≥ 3 branches
   all discriminating the same scrutinee.
3. **Null-narrow rewrite** — special case of #1, surfaced independently
   so it appears as a quick-fix on `match x { is null … }`.

Each lives under `vader/lsp/actions/<action_name>.vader` and
self-registers into the registry via an init-time entry.

## Open architectural questions

To resolve when implementation starts (per `.claude/CLAUDE.md` §8
"Review architectural choices with the user") :

1. **Registry shape** — array of records vs. trait-dispatched
   `CodeActionProvider`. Lean toward records for MVP simplicity.
2. **Printer adapter scope** — full refactor of `emit_program` vs. a
   thin synthetic-program wrapper. Refactor is cleaner long-term but
   touches more test surface.
3. **Action discovery** — central registration file, vs. each action
   file self-registers via init-time side effect, vs. comptime-generated
   table. Tied to whether comptime supports init-time effects by then.
4. **Position walker reuse** — does `expr_at` subsume the hover walker,
   or do they stay independent ?
5. **Lossy-conversion policy** — when a `match` has patterns that can't
   be lowered (struct destructuring, guards), do we (a) refuse to offer
   the action, (b) offer it with a warning in the title, (c) emit a
   partial conversion ?

## Diagnostic-driven companion (post-v1)

Once the framework lands, the compiler can emit advisory diagnostics
("this 2-case match would be clearer as `if`") whose `relatedInformation`
points at the matching code action. Cross-references TODO §3.7's
"Structured `repair.id` field on diagnostics" entry — the same
infrastructure powers compiler-driven quick-fixes. Deferred until after
v1 of the framework validates the action set.

## Implementation order

Three sprints when work picks up :

| Sprint | Deliverable |
|---|---|
| 1 | Capability declaration + `expr_at` walker + registry skeleton + first stub action (no-op edit) — proves the dispatch path end-to-end. |
| 2 | `match` → `if` action + printer adapter refactor for `emit_expr`. |
| 3 | `if` → `match` + null-narrow + snapshot test corpus under `tests/snippets/code_action_*`. |

## Verification (when implementation lands)

- Unit tests on `expr_at` — snapshot `(snippet, line, col) → expected
  Expr kind` over a small corpus.
- Snapshot tests per action — `(source, cursor) → expected TextEdit[]`.
- Round-trip — apply `match→if` then `if→match` (when ≥ 3 branches),
  confirm the result reparses + typechecks.
- Manual editor test — VS Code extension, place cursor on a 2-case
  `match`, confirm the lightbulb shows the action and applies correctly.
