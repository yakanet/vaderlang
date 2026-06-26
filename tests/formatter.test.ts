// Formatter end-to-end tests : invokes `vader fmt --stdout` over a curated
// subset of snippets to verify two contracts :
//
// 1. **Idempotency** — `fmt(fmt(src)) === fmt(src)` for every formatted file.
// 2. **Parse round-trip** — `parse(fmt(src))` is AST-equal to `parse(src)`
//    modulo spans. Demonstrates that the format pass doesn't change the
//    program's structural meaning.
//
// The formatter is a Vader program executed through the bytecode VM (cf.
// `src/cli/commands/fmt.ts` shim), so each `Bun.spawnSync` invocation pays a
// ~2-3 s VM-bootstrap cost. To keep `bun test` snappy this suite is gated
// behind `RUN_FMT_TESTS=1` ; the gate skips every test rather than declaring
// them failed when not set.

import { test, expect } from "bun:test";
import { existsSync } from "node:fs";
import { join } from "node:path";

import { CLI_BIN, MEDIUM_BUILD, runCli } from "./cli-bin.ts";

const ENABLED = process.env.RUN_FMT_TESTS === "1";

// A representative cross-section of the snippet corpus. Adding every
// snippet would push the runtime past 5 minutes — pick fixtures that
// exercise distinct AST shapes (decorators, generics, traits, match,
// multi-line strings, …).
const SNIPPETS = [
  "hello",
  "arith",
  "interpolation",
  "loop",
  "match_union",
  "defer_block",
  "try_op",
  "enum_basic",
  "enum_match",
  "generic_fn",
  "generic_struct",
  "trait_dispatch_bounded",
  "iter_combinators",
  "tuple_destructure_let",
  "struct_defaults",
  "struct_spread",
  "closure_simple",
  "expr_bodied_fn",
  "format_helpers",
  "implicit_dot_variant",
  "not_paren",
  "precedence_parens",
];

function fmtStdout(path: string): string {
  const proc = Bun.spawnSync({
    cmd: [CLI_BIN, "fmt", "--stdout", path],
    cwd: process.cwd(),
    stdout: "pipe",
    stderr: "pipe",
  });
  if (proc.exitCode !== 0) {
    throw new Error(
      `vader fmt failed on ${path} (exit ${proc.exitCode}) :\n` +
      new TextDecoder().decode(proc.stderr),
    );
  }
  return new TextDecoder().decode(proc.stdout);
}

// Round-trip a string through the formatter via a temp file (the formatter
// expects a path argument). Used for idempotency checks where we already
// have an in-memory string.
function fmtString(source: string): string {
  const tmp = join(process.cwd(), ".tmp-fmt-roundtrip.vader");
  Bun.write(tmp, source);
  try {
    return fmtStdout(tmp);
  } finally {
    try { Bun.file(tmp).delete?.(); } catch { /* ignore */ }
  }
}

// Structural AST via the Vader CLI. `dump --stage=ast` elides spans and
// embeds no file path, so two dumps are directly comparable ; the module
// name comes from the source `module "..."` decl, which formatting preserves.
async function astDump(path: string): Promise<string> {
  const { stdout, stderr, exit } = await runCli(["dump", "--stage=ast", path]);
  if (exit !== 0) {
    throw new Error(`vader dump --stage=ast failed on ${path} (exit ${exit}) :\n${stderr}`);
  }
  return stdout;
}

for (const name of SNIPPETS) {
  test(`fmt idempotency : ${name}`, async () => {
    if (!ENABLED) return;
    const path = join("tests", "snippets", name, "_main.vader");
    if (!existsSync(path)) {
      throw new Error(`snippet missing : ${path}`);
    }
    const f1 = fmtStdout(path);
    const f2 = fmtString(f1);
    expect(f2).toBe(f1);
  }, { timeout: MEDIUM_BUILD });

  test(`fmt parse round-trip : ${name}`, async () => {
    if (!ENABLED) return;
    const path = join("tests", "snippets", name, "_main.vader");
    if (!existsSync(path)) {
      throw new Error(`snippet missing : ${path}`);
    }
    const formatted = fmtStdout(path);
    const tmp = join(process.cwd(), `.tmp-fmt-ast-${name}.vader`);
    await Bun.write(tmp, formatted);
    try {
      expect(await astDump(tmp)).toBe(await astDump(path));
    } finally {
      try { Bun.file(tmp).delete?.(); } catch { /* ignore */ }
    }
  }, { timeout: MEDIUM_BUILD });
}
