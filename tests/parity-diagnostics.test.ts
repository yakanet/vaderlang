// Diagnostic-code parity — TS vs Vader, per stage, set-based.
//
// `parity.test.ts` matches full stdout byte-for-byte ; this suite is
// stricter on *codes* and looser on everything else. It extracts the
// `error[XXXX]` / `warning[XXXX]` set (with span) from both the TS dump
// and the Vader CLI dump for each snippet, and asserts the two sets
// agree.
//
// Goal : surface cases where TS and Vader disagree on *which code* to
// emit at the same source location — the C4xxx renumbering between
// `src/diagnostics/codes.ts` and `vader/diagnostics/codes.vader` is the
// motivating example. Wording / formatting differences are tolerated.
//
// Negative R-snippets under `tests/diag_corpus/resolver/` exercise the
// R2xxx codes that the broader snippet corpus doesn't naturally hit, so
// the resolver port has a concrete checklist of what's still missing.

import { test, expect } from "bun:test";
import { readdirSync } from "node:fs";
import { join } from "node:path";

import {
  dumpResolver, dumpTypecheck, dumpComptime, dumpLower, listSnippets, type Scenario,
} from "./snapshot.ts";
import { LONG_BUILD, MEDIUM_BUILD, runCli } from "./cli-bin.ts";

interface Stage {
  readonly label: string;
  /** CLI `--stage=` value */
  readonly cliStage: string;
  /** TS in-process dumper. Returns the same text shape the Vader CLI emits. */
  readonly tsDump: (source: string, entryPath: string) => string;
}

const STAGES: readonly Stage[] = [
  { label: "resolver",  cliStage: "resolved-ast",  tsDump: dumpResolver },
  { label: "typecheck", cliStage: "typed-ast",     tsDump: dumpTypecheck },
  { label: "comptime",  cliStage: "evaluated-ast", tsDump: dumpComptime },
  { label: "lower",     cliStage: "lowered-ast",   tsDump: dumpLower },
];

interface DiagRef { readonly span: string; readonly severity: "error" | "warning"; readonly code: string }

// Match `[L:C]  error[XXXX]` / `[L:C]  warning[XXXX]`. Spaces are flexible
// because the TS / Vader formatters use slightly different padding.
const DIAG_RE = /\[(\d+:\d+)\]\s+(error|warning)\[([A-Z]\d{4})\]/g;

function extractDiags(output: string): DiagRef[] {
  const out: DiagRef[] = [];
  for (const m of output.matchAll(DIAG_RE)) {
    out.push({ span: m[1]!, severity: m[2]! as "error" | "warning", code: m[3]! });
  }
  // Sort so set-comparison is order-independent (TS and Vader sometimes
  // walk decls in different orders).
  out.sort((a, b) => (a.span + a.code).localeCompare(b.span + b.code));
  return out;
}

function diagKey(d: DiagRef): string { return `${d.span} ${d.severity}[${d.code}]` }

function diffSets(a: DiagRef[], b: DiagRef[]): { onlyA: string[]; onlyB: string[] } {
  const aKeys = new Set(a.map(diagKey));
  const bKeys = new Set(b.map(diagKey));
  const onlyA: string[] = [], onlyB: string[] = [];
  for (const k of aKeys) if (!bKeys.has(k)) onlyA.push(k);
  for (const k of bKeys) if (!aKeys.has(k)) onlyB.push(k);
  onlyA.sort(); onlyB.sort();
  return { onlyA, onlyB };
}

// Snippets / stages where TS↔Vader diagnostic-code parity is known to
// diverge and the divergence is *tracked elsewhere* (a TODO in the port
// plan, an open ticket, …). Each entry has a comment with the reason so
// we don't accidentally hide a fresh regression behind an old bypass.
//
// IMPORTANT : the goal of this suite is to surface divergence, not to
// paper over it. Add entries grudgingly ; prefer fixing the port.
//
// Categories (see TODO.md §2.6 resolver port follow-ups) :
//   - R2006-resolver-stage : Vader emits R2006 at typecheck-time
//     (`vader/typecheck/expr.vader:107`) because the body walker has
//     no view on `core_symbols` / `imports_to`. TS emits it at
//     resolver-time. Moving emission earlier needs a `core_symbols`
//     seed in the body walker scope.
//   - R2018-orphan-rule : the orphan-rule check on `Type implements
//     Trait` needs module-ownership of `forType` AND `traitName`,
//     i.e. the `wire_imports` redirect table threaded into the
//     pre-resolve pass. Not ported yet.
//   - C4xxx-renum : Vader's C4001-C4007 carry different meanings than
//     TS's. Renumbering Vader to align with `src/diagnostics/codes.ts`
//     is its own chantier (touches every `comptime/` snapshot under
//     `tests/diag_corpus/comptime/` and the `KNOWN_DIVERGENT` set
//     in `tests/vader_vm.test.ts`).
//   - typecheck-coverage : Vader's `check_project_with_bodies`
//     doesn't yet populate `expr_types` for every node TS does, so
//     downstream stages occasionally miss a cascading `T3001` / `T3028`
//     that TS emits.
//   - lower-divergence : tail of typecheck-coverage at the lower
//     stage ; same root cause.
const KNOWN_DIVERGENCES: ReadonlySet<string> = new Set<string>([
  // Format : `${stage}:${snippet}`.
  // R2006-resolver-stage
  "resolver:errors_parser",
  "resolver:interpolation_tokens",
  "resolver:unknown_ident",
  // R2018-orphan-rule
  "resolver:non_exported_violation",
  "resolver:orphan_impl_forbidden",
  "typecheck:orphan_impl_forbidden",
  "comptime:orphan_impl_forbidden",
  "lower:orphan_impl_forbidden",
  // C4xxx-renum (Vader codes still carry pre-strict meaning)
  "comptime:bad_div_zero",
  "comptime:cycle",
  "comptime:square_call",
  "comptime:tuple_comptime",
  "lower:bad_div_zero",
  "lower:cycle",
  "lower:square_call",
  "lower:tuple_comptime",
  // typecheck-coverage (cascading from incomplete `expr_types`)
  "typecheck:iter_defaults",
  "typecheck:sam_impl_bad",
  "typecheck:selfhost_lexer_basic",
  "comptime:iter_defaults",
  "comptime:sam_impl_bad",
  "comptime:selfhost_lexer_basic",
  "comptime:interp_string_comptime",
  "lower:iter_defaults",
  "lower:sam_impl_bad",
  "lower:selfhost_lexer_basic",
  "lower:interp_string_comptime",
  // lower-divergence (Into-coercion path missing T3001 emit-site)
  "lower:for_in_into_iter",
  // p1014_unknown_decorator_placement : Vader's resolver body-walker
  // emits R2006 on the implicit ident a misplaced @decorator wraps
  // ; TS suppresses the cascade past P1014. Tracked alongside the
  // R2006-resolver-stage move.
  "typecheck:parser/p1014_unknown_decorator_placement",
  "comptime:parser/p1014_unknown_decorator_placement",
  "lower:parser/p1014_unknown_decorator_placement",
  // T3013 non-exhaustive match : Vader's typechecker doesn't yet
  // emit T3013 on this snippet's shape (return-position match
  // missing a `false` arm). Tracked as typecheck-coverage.
  "resolver:typecheck/t3013_non_exhaustive_match",
  "typecheck:typecheck/t3013_non_exhaustive_match",
  "comptime:typecheck/t3013_non_exhaustive_match",
  "lower:typecheck/t3013_non_exhaustive_match",
  // T3015 break-outside-loop : Vader emits at expression-position
  // but TS also flags the early-exit at top level. Tracked under
  // typecheck-coverage.
  "typecheck:typecheck/t3015_break_outside_loop",
  "comptime:typecheck/t3015_break_outside_loop",
  "lower:typecheck/t3015_break_outside_loop",
  // T3051 extern-must-not-have-body : Vader doesn't yet validate
  // @extern decls (T3050 / T3051 are defined but not emitted).
  "typecheck:typecheck/t3051_extern_must_not_have_body",
  "comptime:typecheck/t3051_extern_must_not_have_body",
  "lower:typecheck/t3051_extern_must_not_have_body",
  // l0001 / l0007 : TS chains an R2006 (unresolved ident) on the
  // recovered identifier after the lexer error. Vader skips that
  // cascade — same `R2006-resolver-stage` divergence as above.
  "resolver:lexer/l0001_unexpected_character",
  "resolver:lexer/l0007_stray_backslash",
  "typecheck:lexer/l0001_unexpected_character",
  "comptime:lexer/l0001_unexpected_character",
  "lower:lexer/l0001_unexpected_character",
]);

function collectScenarios(): Scenario[] {
  const main = listSnippets("tests/snippets");
  // Optional `tests/diag_corpus/<bucket>/` directories — same shape as
  // `tests/snippets/<name>/` so `listSnippets` works on them.
  const extra: Scenario[] = [];
  try {
    for (const bucket of readdirSync("tests/diag_corpus", { withFileTypes: true })) {
      if (!bucket.isDirectory()) continue;
      const bucketPath = join("tests/diag_corpus", bucket.name);
      for (const s of listSnippets(bucketPath)) {
        extra.push({ ...s, name: `${bucket.name}/${s.name}` });
      }
    }
  } catch { /* dir absent — OK, the negative corpus is optional. */ }
  return [...main, ...extra];
}

const scenarios = collectScenarios();
// `namespace_alias_dedupe` is the same ~40s outlier called out in
// `parity.test.ts` ; reuse its budget here.
const SLOW_TYPECHECK_SNIPPETS = new Set(["namespace_alias_dedupe"]);

test("diag-parity: at least one snippet", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const stage of STAGES) {
  for (const s of scenarios) {
    const key = `${stage.label}:${s.name}`;
    if (KNOWN_DIVERGENCES.has(key)) {
      test.skip(`diag-parity ${stage.label}: ${s.name} (known divergence)`, () => {});
      continue;
    }
    const timeout = SLOW_TYPECHECK_SNIPPETS.has(s.name) ? LONG_BUILD : MEDIUM_BUILD;
    test.concurrent(`diag-parity ${stage.label}: ${s.name}`, async () => {
      let tsText: string;
      try { tsText = stage.tsDump(s.source, s.mainPath); }
      catch (e) { tsText = `# TS dump threw: ${e instanceof Error ? e.message : String(e)}`; }
      const { stdout: vaderText } = await runCli(["dump", `--stage=${stage.cliStage}`, s.mainPath]);

      const tsDiags = extractDiags(tsText);
      const vaderDiags = extractDiags(vaderText);
      const { onlyA: tsOnly, onlyB: vaderOnly } = diffSets(tsDiags, vaderDiags);
      // Symmetric set-diff : both sides must be empty for the codes to
      // agree. `expect.toEqual` on the diff record gives a readable diff
      // when they don't ; the test name already carries the stage/snippet.
      expect({ tsOnly, vaderOnly }).toEqual({ tsOnly: [], vaderOnly: [] });
    }, { timeout });
  }
}
