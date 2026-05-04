import { expect, test } from "bun:test";
import { dumpBytecode, dumpComptime, dumpLexer, dumpLower, dumpParser, dumpResolver, dumpTypecheck, listScenarios, snapshotEquals } from "./snapshot.ts";

function runScenarios(
  rootDir: string,
  snapName: string,
  dump: (source: string, fileOrPath: string) => string,
  label: string,
  fileArg: "logical" | "path",
): void {
  const scenarios = listScenarios(rootDir);
  test(`${label} snapshot: at least one scenario discovered`, () => {
    expect(scenarios.length).toBeGreaterThan(0);
  });
  for (const s of scenarios) {
    test(`${label} snapshot: ${s.name}`, () => {
      const file = fileArg === "logical" ? "input.vader" : s.inputPath;
      const actual = dump(s.inputSource, file);
      const result = snapshotEquals(s.dir, snapName, actual);
      if (!result.ok) {
        const expectedDisplay = result.expected ?? "(no snap file yet)";
        throw new Error(
          `Snapshot mismatch in ${s.name} (${result.snapPath}).\n` +
          `Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
          `--- expected ---\n${expectedDisplay}\n` +
          `--- actual ---\n${actual}`,
        );
      }
    });
  }
}

runScenarios("tests/snapshots/lexer",     "tokens.snap",   dumpLexer,     "lexer",     "logical");
runScenarios("tests/snapshots/parser",    "ast.snap",      dumpParser,    "parser",    "logical");
runScenarios("tests/snapshots/resolver",  "resolved.snap", dumpResolver,  "resolver",  "path");
runScenarios("tests/snapshots/typecheck", "types.snap",    dumpTypecheck, "typecheck", "path");
runScenarios("tests/snapshots/comptime",  "evaluated.snap", dumpComptime, "comptime",  "path");
runScenarios("tests/snapshots/lower",     "lowered.snap",   dumpLower,    "lower",     "path");
runScenarios("tests/snapshots/bytecode",  "bytecode.snap",  dumpBytecode, "bytecode",  "path");
