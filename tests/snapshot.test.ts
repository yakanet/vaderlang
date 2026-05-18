import { expect, test } from "bun:test";
import {
  LEXER_PARSER_CORPUS, MAIN_FILE, dumpBytecode, dumpCfg, dumpComptimeViaVader,
  dumpLexer, dumpLower, dumpParser, dumpTypecheckViaVader, errMsg, listSnippets,
  loadConfig, snapshotEquals,
} from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

// Each phase entry describes one compilation stage to snapshot:
//   name    — label used in test names and error messages.
//   snap    — filename of the snapshot written inside tests/snippets/{name}/.
//   dump    — function that runs the stage and returns the text to snapshot.
//   usePath — true: pass the absolute file path to dump (it reads from disk to
//             resolve imports); false: pass the logical filename and let dump
//             use the source string directly (no import resolution needed).
const PHASES = [
  { name: "lexer",     snap: "lexer.snapshot",     dump: dumpLexer,     usePath: false },
  { name: "parser",    snap: "parser.snapshot",    dump: dumpParser,    usePath: false },
  { name: "typecheck", snap: "typecheck.snapshot", dump: dumpTypecheckViaVader, usePath: true  },
  { name: "comptime",  snap: "comptime.snapshot",  dump: dumpComptimeViaVader,  usePath: true  },
  { name: "lower",     snap: "lower.snapshot",     dump: dumpLower,     usePath: true  },
  { name: "cfg",       snap: "cfg.snapshot",       dump: dumpCfg,       usePath: true  },
  // `.virt` suffix : the bytecode snapshot is the `.virt` text-IR dump and
  // is consumed verbatim by the Vader CLI (`./build/vader run`) in the
  // `tests/vader_vm.test.ts` parity test.
  { name: "bytecode",  snap: "bytecode.snapshot.virt",  dump: dumpBytecode,  usePath: true  },
] as const;

const scenarios = listSnippets("tests/snippets");

test("snippets: at least one discovered", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const s of scenarios) {
  const config = loadConfig(s.dir);
  const activePhases = config.phases ? PHASES.filter((p) => config.phases!.includes(p.name)) : PHASES;
  for (const p of activePhases) {
    test(`${p.name}: ${s.name}`, () => {
      const file = p.usePath ? s.mainPath : MAIN_FILE;
      let actual: string;
      try {
        actual = p.dump(s.source, file);
      } catch (e) {
        actual = `# internal error\n${errMsg(e)}\n`;
      }
      const result = snapshotEquals(s.dir, p.snap, actual);
      if (!result.ok) {
        throw new Error(
          `Snapshot mismatch: ${p.name}/${s.name} (${result.snapPath})\n` +
          `Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
          snapshotDiff(result.snapPath, result.expected, actual),
        );
      }
    }, { timeout: 60_000 });
  }
}
