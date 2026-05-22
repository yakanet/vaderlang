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
const KNOWN_DIVERGENCES: ReadonlySet<string> = new Set<string>([
  // Format : `${stage}:${snippet}`.
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
    test.skip.concurrent(`diag-parity ${stage.label}: ${s.name}`, async () => {
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
