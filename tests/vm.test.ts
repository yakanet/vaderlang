import { test } from "bun:test";
import { readFileSync, readdirSync, statSync, writeFileSync } from "node:fs";
import { resolve } from "node:path";

import { errMsg, formatRun, formatRunWithError, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { pipelineBytecode } from "../src/pipeline.ts";
import { VmError, runProgram, makeBindings, type HostIO } from "../src/vm/index.ts";

// VM error messages embed the absolute path of the offending source file
// (`... @ /abs/path/_main.vader:LINE:COL`). Strip the project-root prefix so
// snapshots stay portable across machines and CI runners.
const PROJECT_ROOT = resolve(import.meta.dir, "..");
const stripRoot = (s: string): string => s.replaceAll(PROJECT_ROOT + "/", "");

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
      readStdin()     { throw new Error("EOF"); },
      readFile(path)  { return readFileSync(path, "utf8"); },
      writeFile(p, c) { writeFileSync(p, c, "utf8"); },
      exists(p) {
        try { readFileSync(p); return true; } catch { return false; }
      },
      isDir(p) {
        try { return statSync(p).isDirectory(); } catch { return false; }
      },
      readDir(p) {
        return readdirSync(p);
      },
    },
  };
}

async function dumpVm(mainPath: string): Promise<string> {
  let r: Awaited<ReturnType<typeof pipelineBytecode>>;
  try {
    r = await pipelineBytecode(mainPath);
  } catch (e) {
    return stripRoot(`# pipeline error\n${errMsg(e)}\n`);
  }
  const errors = r.diagnostics.sorted().filter((d) => d.severity === "error");
  if (errors.length > 0) {
    return stripRoot("# compile errors\n" + errors.map((e) => `[${e.code}] ${e.message}`).join("\n") + "\n");
  }
  const cap = captureIO();
  try {
    // Pass argv[0] (script path) so snippets that take `main(argv)` see at
    // least one element — mirrors the native binary which always gets argv[0].
    const result = runProgram(r.bytecode, { host: makeBindings(cap.io), opLimit: 1_000_000, argv: [mainPath] });
    return stripRoot(formatRun(cap.out.join(""), cap.err.join(""), result.exitCode));
  } catch (e) {
    if (e instanceof VmError && e.message.startsWith("vm: no main function")) return "# no main function\n";
    return stripRoot(formatRunWithError(cap.out.join(""), cap.err.join(""), errMsg(e)));
  }
}

const scenarios = listSnippets("tests/snippets");

for (const s of scenarios) {
  // Snippets with adjacent helper.c files are native-only — the VM has
  // no host-fn registry for user `@extern` symbols, so call.import
  // traps. The native runner is the source of truth ; skip VM here
  // rather than encoding a "VM-traps, native-works" divergence into
  // vm.snapshot.
  const fn = s.helperCFiles.length > 0 ? test.skip : test.concurrent;
  fn(`vm: ${s.name}`, async () => {
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
