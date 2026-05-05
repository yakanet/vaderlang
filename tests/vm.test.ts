import { test } from "bun:test";
import { readFileSync, writeFileSync } from "node:fs";

import { errMsg, formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { pipelineBytecode } from "../src/pipeline.ts";
import { VmError, runProgram, makeBindings, type HostIO } from "../src/vm/index.ts";

interface Captured {
  readonly out: string[];
  readonly err: string[];
  readonly io: HostIO;
}

function captureIO(): Captured {
  const out: string[] = [];
  const err: string[] = [];
  return {
    out, err,
    io: {
      write(s)        { out.push(s); },
      writeError(s)   { err.push(s); },
      readLine()      { return null; },
      readFile(path)  { return readFileSync(path, "utf8"); },
      writeFile(p, c) { writeFileSync(p, c, "utf8"); },
      exists(p) {
        try { readFileSync(p); return true; } catch { return false; }
      },
    },
  };
}

async function dumpVm(mainPath: string): Promise<string> {
  let r: Awaited<ReturnType<typeof pipelineBytecode>>;
  try {
    r = await pipelineBytecode(mainPath);
  } catch (e) {
    return `# pipeline error\n${errMsg(e)}\n`;
  }
  const errors = r.diagnostics.sorted().filter((d) => d.severity === "error");
  if (errors.length > 0) {
    return "# compile errors\n" + errors.map((e) => `[${e.code}] ${e.message}`).join("\n") + "\n";
  }
  try {
    const cap = captureIO();
    const result = runProgram(r.bytecode, { host: makeBindings(cap.io), opLimit: 1_000_000 });
    return formatRun(cap.out.join(""), cap.err.join(""), result.exitCode);
  } catch (e) {
    if (e instanceof VmError && e.message.startsWith("vm: no main function")) return "# no main function\n";
    return `# runtime error\n${errMsg(e)}\n`;
  }
}

const scenarios = listSnippets("tests/snippets");

for (const s of scenarios) {
  test(`vm: ${s.name}`, async () => {
    const actual = await dumpVm(s.mainPath);
    const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `vm snapshot mismatch: ${s.name}\n` +
        `  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  });
}
