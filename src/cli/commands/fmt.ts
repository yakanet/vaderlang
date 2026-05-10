// The formatter lives in Vader (`vader/fmt/`) — this shim locates the entry
// point through `runtimeRoots().vaderRoot` and runs `vader/cli/main.vader fmt
// <args…>` through the VM. Same code path whether the host is the dev TS CLI
// (`bun src/index.ts fmt …`) or the compiled binary loading the sidecar tree.

import { existsSync } from "node:fs";
import { resolve } from "node:path";

import type { GlobalOpts } from "../options.ts";
import { pipelineBytecode } from "../../pipeline.ts";
import { renderAllTextSingle, renderAllJson } from "../../diagnostics/render.ts";
import { runtimeRoots } from "../../runtime-resources.ts";
import { defaultHostIO, makeBindings, runProgram, VmError } from "../../vm/index.ts";

export async function cmdFmt(opts: GlobalOpts, args: string[]): Promise<number> {
  const entry = resolve(runtimeRoots().vaderRoot, "cli", "main.vader");
  if (!existsSync(entry)) {
    console.error(`vader fmt: cannot locate self-host CLI at ${entry}`);
    console.error("  (re-extract the dist archive or run from a checkout)");
    return 1;
  }

  // The Vader CLI's dispatch expects `<command> [args…]` ; `fmt` is the
  // command, everything else flows through verbatim. argv[0] mirrors `run`'s
  // convention (script path) so any introspection on `argv` in the Vader
  // formatter sees the same shape as a freestanding `vader run`.
  const argv = [entry, "fmt", ...args];

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

    const result = runProgram(r.bytecode, {
      host: makeBindings(defaultHostIO()),
      argv,
    });
    return result.exitCode;
  } catch (e) {
    if (e instanceof VmError) {
      console.error(`vader fmt: ${e.message}`);
      if (e.debug !== undefined) console.error(`  at ${e.debug}`);
      return 1;
    }
    const msg = e instanceof Error ? e.message : String(e);
    console.error(`vader fmt: ${msg}`);
    return 1;
  }
}
