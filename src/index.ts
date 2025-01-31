import { parseProgram } from "./parser";
import { WasmEmitter } from "./emit/wasm-emitter.ts";
import process from "node:process";
import fs from "node:fs";
import { parseCommandLine } from "./cli.ts";

const cli = parseCommandLine(process.argv);
for (const source_path of cli.positionalArgument) {
  const source = fs.readFileSync(source_path, { encoding: "utf-8" });
  const program = parseProgram(source, source_path);
  console.log(program)

  const emitter = new WasmEmitter();

}
process.exit(0);

//console.log(util.inspect(root, {depth: null}));

//emitter.emit(root, "build");
