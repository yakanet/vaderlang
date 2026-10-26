// Guard against a feature snippet silently regressing to a COMPILER CRASH.
//
// Snapshot tests document *current* behaviour, so a feature snippet that
// regresses to an ICE / abort can have its snapshot "refreshed" to capture the
// crash: turning the suite green on broken code. This is exactly how a
// `for_in_iter_trait` regression hid for ~3.5 weeks: when POW5_128 switched on
// whole-project comptime staging (1cfc58ca), the snippet started aborting at
// midir/emit, and its lower/bytecode snapshots were updated to "vader: panic:
// ..." / "(exit 134)". The suite stayed green because the snapshots MATCHED the
// crash. Fixed in 5ca5b4ec; this guard stops the class from recurring.
//
// Scope: only COMPILE-stage snapshots. `vm.snapshot` (run output) is excluded:
// a RUNTIME panic can legitimately be a snippet's subject (panic_runs_defers).
// `_diag_` snippets are diagnostic-only by convention and excluded.
//
// The same scan keeps compile ERRORS out: a snippet pins what the pipeline emits
// for a program that compiles, and a diagnostic belongs in `tests/diag_corpus/`.
// A snippet that stops compiling records its errors in its stage snapshots on
// the next refresh, so this is the check that catches it.

import { test } from "bun:test";
import { readdirSync, readFileSync } from "node:fs";
import { join } from "node:path";
import { listSnippets } from "./snapshot.ts";

// Compiler-crash markers (ICE / abort / segv), never the intended output of a
// feature snippet's compile stages. Deliberately NOT the generic "vader CLI
// failed", which also covers a compile error; these three are unambiguous
// crashes.
const CRASH_MARKERS: readonly RegExp[] = [
  /vader: panic: /,      // "vader: panic: <ICE message>"
  /reached unreachable/, // an `@unreachable` arm was hit
  /exit 13[49]\)/,       // "(exit 134)" SIGABRT / "(exit 139)" SIGSEGV
];

// Escape hatch for a feature snippet whose COMPILE-time crash is genuinely the
// subject. Empty today. Add a name here only with a comment justifying why the
// compiler is expected to crash while compiling it.
const ALLOW: ReadonlySet<string> = new Set<string>();

// A diagnostic line of severity error, as the stage dumps write it.
const COMPILE_ERROR = /\berror\[[A-Z]\d{4}\]/;

// Every compile-stage snapshot of every feature snippet, as `[name/file, content]`.
function compileStageSnapshots(allow: ReadonlySet<string>): [string, string][] {
  const out: [string, string][] = [];
  for (const s of listSnippets("tests/snippets")) {
    if (s.name.startsWith("_diag_") || allow.has(s.name)) continue;
    for (const f of readdirSync(s.dir)) {
      if (f === "vm.snapshot") continue; // run output: runtime panic may be the subject
      if (!f.includes(".snapshot")) continue;
      out.push([`${s.name}/${f}`, readFileSync(join(s.dir, f), "utf8")]);
    }
  }
  return out;
}

test("no feature snippet reports a compile error", () => {
  const offenders = compileStageSnapshots(new Set())
    .filter(([, content]) => COMPILE_ERROR.test(content))
    .map(([path]) => path);
  if (offenders.length > 0) {
    throw new Error(
      `Feature snippet(s) whose compile-stage snapshots record a compile error:\n` +
      offenders.map((o) => `  ${o}`).join("\n") +
      `\n\nA snippet must compile. A diagnostic is pinned by a fixture under tests/diag_corpus/.`,
    );
  }
});

test("no feature snippet has a compiler-crash compile-stage snapshot", () => {
  const offenders = compileStageSnapshots(ALLOW)
    .filter(([, content]) => CRASH_MARKERS.some((m) => m.test(content)))
    .map(([path]) => path);
  if (offenders.length > 0) {
    throw new Error(
      `Feature snippet(s) regressed to a compiler crash: masked as passing by their snapshots:\n` +
      offenders.map((o) => `  ${o}`).join("\n") +
      `\n\nA feature snippet must compile without an ICE / abort / segv. Fix the COMPILER, not the ` +
      `snapshot. If the compile-time crash is genuinely the snippet's subject, add its name to ALLOW ` +
      `(in ${"tests/snippet_no_crash_snapshot.test.ts"}) with a justifying comment.`,
    );
  }
});
