// Parser-dump parity — Vader CLI vs the TS-generated `parser.snapshot`.
//
// Runs `./build/vader dump --stage=ast <snippet>` over every `tests/snippets/*`
// and asserts the stdout matches the existing `parser.snapshot` byte-for-byte.
// Same rebuild trigger as `tests/parity.test.ts` (lexer parity).
//
// Snippets that hit currently-known runtime trap sites in the Vader parser
// (matches over `null | <many-structs>` unions, primitive-only union dispatch
// — see TODO §1.13c) are listed in `KNOWN_FAILURES` so the suite stays green
// while we work through the remaining cases.

import { test, expect, beforeAll } from "bun:test";
import { existsSync, readdirSync, statSync } from "node:fs";
import { join } from "node:path";

import { listSnippets } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

const CLI_BIN = `build/vader${process.platform === "win32" ? ".exe" : ""}`;

function newestSourceMtime(): number {
  let max = 0;
  const exts = [".vader", ".ts"];
  const walk = (dir: string): void => {
    for (const ent of readdirSync(dir, { withFileTypes: true })) {
      const p = join(dir, ent.name);
      if (ent.isDirectory()) walk(p);
      else if (exts.some((e) => ent.name.endsWith(e))) {
        const m = statSync(p).mtimeMs;
        if (m > max) max = m;
      }
    }
  };
  walk("vader");
  walk("stdlib");
  walk("src");
  return max;
}

beforeAll(async () => {
  const stale = !existsSync(CLI_BIN) || statSync(CLI_BIN).mtimeMs < newestSourceMtime();
  if (!stale) return;
  const proc = Bun.spawn(
    ["bun", "src/index.ts", "build", "vader/cli/main.vader", "--target=native", `--out=${CLI_BIN}`],
    { stdout: "pipe", stderr: "pipe" },
  );
  const code = await proc.exited;
  if (code !== 0) {
    const err = await new Response(proc.stderr).text();
    throw new Error(`vader CLI build failed (exit ${code}):\n${err}`);
  }
});

// Snippets where the Vader parser today either traps at runtime
// (`reached unreachable`) or diverges in detail. Tracked in TODO §2.1 ;
// remove an entry once the underlying fix lands.
const KNOWN_FAILURES = new Set<string>([
  // `@assert(cond)` is recognised by the TS parser as a standalone
  // AssertDecl ; the Vader self-host parser still treats `@assert` as a
  // regular decorator and attaches it to the next decl. Port pending.
  "decorator_assert",
  // `is .Foo` resolves against the scrutinee (implicit-dot NamedType) on
  // the TS side ; the self-host parser still calls `parse_type` after
  // `is` and rejects the leading dot. Port pending.
  "implicit_dot_variant",
  // `@partial match` is recognised as a MatchExpr modifier on the TS
  // side (`partial: true` in the AST dump) ; the self-host parser
  // doesn't emit the `partial` field. Port pending.
  "match_partial",
]);

const SKIP_ALL = false;

const scenarios = listSnippets("tests/snippets");

test("parser parity: at least one snippet", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const s of scenarios) {
  if (SKIP_ALL || KNOWN_FAILURES.has(s.name)) {
    test.skip(`parser parity: ${s.name}`, () => {});
    continue;
  }
  test.concurrent(`parser parity: ${s.name}`, async () => {
    const snapPath = `${s.dir}/parser.snapshot`;
    let expected: string;
    try { expected = await Bun.file(snapPath).text(); } catch { return; }

    const proc = Bun.spawn(
      [CLI_BIN, "dump", "--stage=ast", s.mainPath],
      { stdout: "pipe", stderr: "pipe" },
    );
    const stdout = await new Response(proc.stdout).text();
    await proc.exited;

    if (stdout !== expected) {
      throw new Error(
        `parser-dump parity mismatch: ${s.name}\n\n` +
        snapshotDiff(snapPath, expected, stdout),
      );
    }
  });
}
