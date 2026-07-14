// Guard against a feature snippet silently regressing to a COMPILER CRASH.
//
// Snapshot tests document *current* behaviour, so a feature snippet that
// regresses to an ICE / abort can have its snapshot "refreshed" to capture the
// crash — turning the suite green on broken code. This is exactly how a
// `for_in_iter_trait` regression hid for ~3.5 weeks: when POW5_128 switched on
// whole-project comptime staging (1cfc58ca), the snippet started aborting at
// midir/emit, and its lower/bytecode snapshots were updated to "vader: panic —
// …" / "(exit 134)". The suite stayed green because the snapshots MATCHED the
// crash. Fixed in 5ca5b4ec; this guard stops the class from recurring.
//
// Scope: only COMPILE-stage snapshots. `vm.snapshot` (run output) is excluded —
// a RUNTIME panic can legitimately be a snippet's subject (panic_runs_defers).
// `_diag_` snippets are diagnostic-only by convention and excluded.

import { test } from "bun:test";
import { readdirSync, readFileSync } from "node:fs";
import { join } from "node:path";
import { listSnippets } from "./snapshot.ts";

// Compiler-crash markers (ICE / abort / segv) — never the intended output of a
// feature snippet's compile stages. Deliberately NOT the generic "vader CLI
// failed", which also covers ordinary compile-ERROR (diagnostic) test snippets
// exiting non-zero; these three are unambiguous crashes.
const CRASH_MARKERS: readonly RegExp[] = [
  /panic —/,             // "vader: panic — <ICE message>"
  /reached unreachable/, // an `@unreachable` arm was hit
  /exit 13[49]\)/,       // "(exit 134)" SIGABRT / "(exit 139)" SIGSEGV
];

// Escape hatch for a feature snippet whose COMPILE-time crash is genuinely the
// subject. Empty today. Add a name here only with a comment justifying why the
// compiler is expected to crash while compiling it.
const ALLOW: ReadonlySet<string> = new Set<string>();

test("no feature snippet has a compiler-crash compile-stage snapshot", () => {
  const offenders: string[] = [];
  for (const s of listSnippets("tests/snippets")) {
    if (s.name.startsWith("_diag_") || ALLOW.has(s.name)) continue;
    for (const f of readdirSync(s.dir)) {
      if (f === "vm.snapshot") continue; // run output — runtime panic may be the subject
      if (!f.endsWith(".snapshot") && !f.endsWith(".snapshot.virt")) continue;
      const content = readFileSync(join(s.dir, f), "utf8");
      if (CRASH_MARKERS.some((m) => m.test(content))) offenders.push(`${s.name}/${f}`);
    }
  }
  if (offenders.length > 0) {
    throw new Error(
      `Feature snippet(s) regressed to a compiler crash — masked as passing by their snapshots:\n` +
      offenders.map((o) => `  ${o}`).join("\n") +
      `\n\nA feature snippet must compile without an ICE / abort / segv. Fix the COMPILER, not the ` +
      `snapshot. If the compile-time crash is genuinely the snippet's subject, add its name to ALLOW ` +
      `(in ${"tests/snippet_no_crash_snapshot.test.ts"}) with a justifying comment.`,
    );
  }
});
