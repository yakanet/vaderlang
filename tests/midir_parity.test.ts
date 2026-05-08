// Mid-IR parity harness — runs every snippet through both codegen paths
// (legacy LoweredAST → bytecode and the new CFG → bytecode) and asserts the
// VM produces equal exit codes + stdout/stderr. Behind a feature flag while
// Phase 2 of the Mid-IR refactor stabilises ; once the legacy path is
// dropped (Phase 6) this harness goes away.
//
// We compare *behavior*, not bytecode bytes — the CFG path materialises
// every sub-expression as a named tmp local while the legacy path leaves
// them on the operand stack, so the wire format differs even when the
// observable behaviour is identical.

import { test } from "bun:test";
import { readFileSync, writeFileSync } from "node:fs";
import { basename } from "node:path";

import { listSnippets } from "./snapshot.ts";
import { pipelineDced } from "../src/pipeline.ts";
import { emitBytecode, type BytecodeModule } from "../src/bytecode/index.ts";
import { buildImplRegistry } from "../src/typecheck/impls.ts";
import { buildCFGProject } from "../src/midir/build.ts";
import { emitBytecodeFromCFG } from "../src/midir/emit.ts";
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

interface RunOutcome {
  readonly kind: "ok" | "compile-error" | "vm-error" | "no-main" | "pipeline-error";
  readonly exitCode: number;
  readonly stdout: string;
  readonly stderr: string;
}

function runBytecode(bc: BytecodeModule, mainPath: string): RunOutcome {
  try {
    const cap = captureIO();
    const result = runProgram(bc, { host: makeBindings(cap.io), opLimit: 1_000_000, argv: [mainPath] });
    return {
      kind: "ok", exitCode: result.exitCode,
      stdout: cap.out.join(""), stderr: cap.err.join(""),
    };
  } catch (e) {
    if (e instanceof VmError && e.message.startsWith("vm: no main function")) {
      return { kind: "no-main", exitCode: -1, stdout: "", stderr: "" };
    }
    return { kind: "vm-error", exitCode: -1, stdout: "", stderr: errMsg(e) };
  }
}

function errMsg(e: unknown): string {
  return e instanceof Error ? e.message : String(e);
}

const scenarios = listSnippets("tests/snippets");

for (const s of scenarios) {
  test(`midir parity: ${s.name}`, async () => {
    let dced: Awaited<ReturnType<typeof pipelineDced>>;
    try {
      dced = await pipelineDced(s.mainPath);
    } catch (e) {
      // Pipeline crash — both paths would equally fail upstream of emit, so
      // the parity test is vacuously satisfied. Surface it once for visibility.
      throw new Error(`pipeline error on ${s.name}: ${errMsg(e)}`);
    }
    const errors = dced.diagnostics.sorted().filter((d) => d.severity === "error");
    if (errors.length > 0) return;       // both paths skip emit identically

    const implRegistry = buildImplRegistry(dced.evaluated.typed.resolved);
    const name = basename(s.mainPath, ".vader");
    const opts = { optimize: true, implRegistry };

    const directBc = emitBytecode(dced.dced, name, opts);
    const midirBc = emitBytecodeFromCFG(dced.dced, buildCFGProject(dced.dced), name, opts);

    const direct = runBytecode(directBc, s.mainPath);
    const midir  = runBytecode(midirBc,  s.mainPath);

    // Normalise instruction-position annotations in VM traces — both paths
    // emit the same source-level error but at different bytecode offsets
    // because the CFG path uses named tmp locals where the legacy path
    // keeps values on the stack.
    const normErr = (s: string) => s.replace(/\+\d+ @/g, "@");
    if (direct.kind !== midir.kind
        || direct.exitCode !== midir.exitCode
        || direct.stdout !== midir.stdout
        || normErr(direct.stderr) !== normErr(midir.stderr)) {
      throw new Error(
        `midir parity mismatch on ${s.name}\n` +
        `  direct: kind=${direct.kind} exit=${direct.exitCode} stdout=${JSON.stringify(direct.stdout)} stderr=${JSON.stringify(direct.stderr)}\n` +
        `  midir : kind=${midir.kind} exit=${midir.exitCode} stdout=${JSON.stringify(midir.stdout)} stderr=${JSON.stringify(midir.stderr)}\n`,
      );
    }
  });
}
