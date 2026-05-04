import { expect, test } from "bun:test";
import { dumpLexer, dumpParser, listScenarios, snapshotEquals } from "./snapshot.ts";

function runScenarios(
  rootDir: string,
  snapName: string,
  dump: (source: string, file: string) => string,
  label: string,
): void {
  const scenarios = listScenarios(rootDir);
  test(`${label} snapshot: at least one scenario discovered`, () => {
    expect(scenarios.length).toBeGreaterThan(0);
  });
  for (const s of scenarios) {
    test(`${label} snapshot: ${s.name}`, () => {
      const actual = dump(s.inputSource, "input.vader");
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

runScenarios("tests/snapshots/lexer",  "tokens.snap", dumpLexer,  "lexer");
runScenarios("tests/snapshots/parser", "ast.snap",    dumpParser, "parser");
