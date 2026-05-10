import type { GlobalOpts } from "../options.ts";
import { pipelineBytecode } from "../../pipeline.ts";
import { parseVir } from "../../bytecode/text.ts";
import { parseBinary } from "../../bytecode/binary.ts";
import { BytecodeFormatError, CompilerBugError, formatBytecodeWhere } from "../../diagnostics/errors.ts";
import { renderAllTextSingle, renderAllJson, renderRuntimeTrap } from "../../diagnostics/render.ts";
import { defaultHostIO, makeBindings, runProgram, VmError } from "../../vm/index.ts";

export async function cmdRun(opts: GlobalOpts, args: string[]): Promise<number> {
  const file = args[0];
  if (file === undefined) {
    console.error("vader run: expected a file argument");
    return 1;
  }

  const isBinary = file.endsWith(".vir");
  const isText = file.endsWith(".virt");
  const bindings = makeBindings(defaultHostIO());
  // argv[0] is the script path, the rest is forwarded — mirrors the C target
  // where main captures the OS-level argv (incl. argv[0]).
  const argv = [file, ...args.slice(1)];

  try {
    const bc = isBinary
      ? parseBinary(new Uint8Array(await Bun.file(file).arrayBuffer()), file)
      : isText
      ? parseVir(await Bun.file(file).text(), file)
      : await compileToBytecode(file, opts);
    if (bc === null) return 1;
    const result = runProgram(bc, { host: bindings, argv });
    return result.exitCode;
  } catch (e) {
    if (e instanceof VmError) {
      await renderVmError(e);
      return 1;
    }
    if (e instanceof BytecodeFormatError) {
      console.error(`vader run: ${formatBytecodeWhere(e)}: ${e.message}`);
      return 1;
    }
    if (e instanceof CompilerBugError) {
      console.error(`vader run: internal compiler error — please report:`);
      console.error(`  ${e.message}`);
      return 70;     // EX_SOFTWARE
    }
    const msg = e instanceof Error ? e.message : String(e);
    if (msg.includes("ENOENT")) console.error(`vader run: file not found: ${file}`);
    else console.error(`vader run: ${msg}`);
    return 1;
  }
}

/** Render a VM trap with source context. The `debug` field on VmError is
 *  shaped `<fnName>+<ip> @ <file>:<line>:<col>` (or just `<fnName>+<ip>`
 *  when the op carries no source mapping). When the source is reachable,
 *  surface a diagnostic-style snippet ; otherwise fall back to the raw
 *  message + fn name. */
async function renderVmError(e: VmError): Promise<void> {
  const dbg = e.debug;
  const at = dbg !== undefined ? dbg.match(/^([^@]+) @ (.+):(\d+):(\d+)$/) : null;
  if (at === null) {
    console.error(`vader run: ${e.message}`);
    if (dbg !== undefined) console.error(`  at ${dbg.split(" @ ")[0]?.trim() ?? dbg}`);
    return;
  }
  const [, fn, file, lineStr, colStr] = at as unknown as [string, string, string, string, string];
  const line = Number(lineStr);
  const column = Number(colStr);
  let source = "";
  try { source = await Bun.file(file).text(); } catch { /* file gone — render without snippet */ }
  console.error(renderRuntimeTrap(e.rawMessage, file, line, column, source));
  console.error(`  in ${fn.trim()}`);
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
