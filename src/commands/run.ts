import type { GlobalOpts } from "../cli/options.ts";
import { pipelineBytecode } from "../pipeline.ts";
import { parseVir } from "../bytecode/text.ts";
import { renderAllTextSingle, renderAllJson } from "../diagnostics/render.ts";
import { defaultHostIO, makeBindings, runProgram, VmError } from "../vm/index.ts";

export async function cmdRun(opts: GlobalOpts, args: string[]): Promise<number> {
  const file = args[0];
  if (file === undefined) {
    console.error("vader run: expected a file argument");
    return 1;
  }

  const isIr = file.endsWith(".vir");
  const bindings = makeBindings(defaultHostIO());
  // argv[0] is the script path, the rest is forwarded — mirrors the C target
  // where main captures the OS-level argv (incl. argv[0]).
  const argv = [file, ...args.slice(1)];

  try {
    const bc = isIr
      ? parseVir(await Bun.file(file).text())
      : await compileToBytecode(file, opts);
    if (bc === null) return 1;
    const result = runProgram(bc, { host: bindings, argv });
    return result.exitCode;
  } catch (e) {
    if (e instanceof VmError) {
      console.error(`vader run: ${e.message}`);
      return 1;
    }
    const msg = e instanceof Error ? e.message : String(e);
    if (msg.includes("ENOENT")) console.error(`vader run: file not found: ${file}`);
    else console.error(`vader run: ${msg}`);
    return 1;
  }
}

async function compileToBytecode(file: string, opts: GlobalOpts) {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv, bytecodeOpt: opts.bytecodeOpt });
  const diags = r.diagnostics.sorted();
  if (diags.length > 0) {
    if (opts.diagnostics === "json") {
      process.stderr.write(renderAllJson(diags) + "\n");
    } else {
      process.stderr.write(renderAllTextSingle(diags, r.file, r.source) + "\n");
    }
  }
  if (diags.some((d) => d.severity === "error")) return null;
  return r.bytecode;
}
