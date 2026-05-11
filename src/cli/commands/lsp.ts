// The Language Server lives in Vader (`vader/lsp/`) — this shim locates
// the entry point through `runtimeRoots().vaderRoot` and runs
// `vader/cli/main.vader lsp <args…>` through the VM. Editors invoke
// `vader lsp` (the compiled native binary) directly in production ; the
// VM path is the dev convenience for `bun src/index.ts lsp …`.

import { existsSync } from "node:fs";
import { resolve } from "node:path";

import type { GlobalOpts } from "../options.ts";
import { pipelineBytecode } from "../../pipeline.ts";
import { renderAllTextSingle, renderAllJson } from "../../diagnostics/render.ts";
import { runtimeRoots } from "../../runtime-resources.ts";
import { defaultHostIO, makeBindings, runProgram, VmError } from "../../vm/index.ts";

export async function cmdLsp(opts: GlobalOpts, args: string[]): Promise<number> {
  // Dedicated entry point — narrower module surface than `cli/main.vader`,
  // avoids a generic-mono conflict that the unified CLI triggers when the
  // LSP server runs through it. Editors invoke this directly via the
  // compiled `vader` binary's `lsp` subcommand ; the TS shim mirrors the
  // same shape for `bun src/index.ts lsp …`.
  const entry = resolve(runtimeRoots().vaderRoot, "lsp", "main_entry.vader");
  if (!existsSync(entry)) {
    console.error(`vader lsp: cannot locate LSP entry at ${entry}`);
    console.error("  (re-extract the dist archive or run from a checkout)");
    return 1;
  }

  const argv = [entry, ...args];

  try {
    const r = await pipelineBytecode(entry, {
      allowEnv: opts.allowEnv,
      bytecodeOpt: opts.bytecodeOpt,
    });
    const diags = r.diagnostics.sorted();
    if (diags.length > 0) {
      if (opts.diagnostics === "json") {
        process.stderr.write(renderAllJson(diags) + "\n");
      } else {
        process.stderr.write(renderAllTextSingle(diags, r.file, r.source) + "\n");
      }
    }
    if (diags.some((d) => d.severity === "error")) return 1;

    // The LSP server is long-running ; the VM's optional op-limit is
    // intentionally left unset so message processing can continue for as
    // long as the editor keeps the connection open.
    const result = runProgram(r.bytecode, {
      host: makeBindings(defaultHostIO()),
      argv,
    });
    return result.exitCode;
  } catch (e) {
    if (e instanceof VmError) {
      console.error(`vader lsp: ${e.message}`);
      if (e.debug !== undefined) console.error(`  at ${e.debug}`);
      return 1;
    }
    const msg = e instanceof Error ? e.message : String(e);
    console.error(`vader lsp: ${msg}`);
    return 1;
  }
}
