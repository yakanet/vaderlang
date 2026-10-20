// tests/callee_verify — `$VADER_VERIFY_CALLEES`, the lowering's callee choices
// against the typecheck's record.
//
// The verifier lists each site where the lowering chose another callee than the
// one the typecheck recorded, as `<recorded> / <lowered>  [file:line:column]`.
// Two checks pin it. On the fixture of `tests/callee_sites.test.ts`, the exact
// list of its own sites, each a disagreement the record is right about. On the
// compiler itself, that every disagreement is one of the explained kinds below:
// a new kind fails until it is explained here, or fixed.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, LONG_BUILD, MEDIUM_BUILD } from "./cli-bin.ts";
import { join, relative } from "node:path";
import { mkdtempSync } from "node:fs";
import { tmpdir } from "node:os";

ensureCliBuilt();

const ROOT = join(import.meta.dir, "..");
const SITES = join(import.meta.dir, "fixtures", "callee", "sites.vader");
// The fixture as a report prints it from the repo root, `/` on every host.
const SITES_SHOWN = relative(ROOT, SITES).split("\\").join("/");
const VERIFY = { VADER_VERIFY_CALLEES: "1" };

/** The disagreements a report lists, as `<recorded> / <lowered>  [position]`. */
function disagreements(stderr: string): string[] {
  return stderr
    .split("\n")
    .map((l) => l.match(/^ {4}\d+ × (.*)$/)?.[1])
    .filter((l): l is string => l !== undefined);
}

test("the verifier lists the fixture's sites the lowering gets wrong", async () => {
  const r = await runCli(["dump", "--stage=lowered-ast", SITES], VERIFY, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  const own = disagreements(r.stderr)
    .filter((l) => l.includes(`${SITES_SHOWN}:`))
    .map((l) => l.replace(/\[\S*\//, "["));
  expect(own).toEqual([
    // The generators are fused into the loop: their `next` runs in place, and a
    // string's `into` is one.
    "virtual std_core$Iterator.next / no call fused chain  [sites.vader:154:14]",
    "fn evens / no call fused chain  [sites.vader:297:14]",
    "fn into / no call fused chain  [sites.vader:305:14]",
  ]);
}, MEDIUM_BUILD);

// Each kind of disagreement the compiler is known to hold, with the reason.
const EXPLAINED: [RegExp, string][] = [
  [/^fn mul( \(per instance\))? \/ no call array\.repeat$/, "`[x] * n` emitted as the `array.repeat` intrinsic"],
  [/ \/ no call fused chain$/, "a generator, or a generator `into`, fused into the loop"],
  [/^fn compare \/ no call primitive$/, "`char` ordering compared as a primitive"],
  [/^fn contains \/ no call bounds$/, "`x in lo..hi` over a literal range compared in place"],
  [/^fn \w+ \/ virtual std_core\$Iterator\.next$/, "a generator's state erased to `Iterator`"],
];

// The whole compiler is built: a long build.
test("every disagreement on the compiler itself is an explained one", async () => {
  const out = join(mkdtempSync(join(tmpdir(), "callee-verify-")), "self.c");
  const main = join(ROOT, "vader", "cli", "main.vader");
  const r = await runCli(["build", "--emit=c", `--out=${out}`, main], VERIFY, LONG_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stderr).toContain("[VADER_VERIFY_CALLEES]");
  const unexplained = disagreements(r.stderr)
    .map((l) => l.replace(/ {2}\[.*\]$/, ""))
    .filter((pair) => !EXPLAINED.some(([pattern]) => pattern.test(pair)));
  expect(unexplained).toEqual([]);
}, LONG_BUILD);
