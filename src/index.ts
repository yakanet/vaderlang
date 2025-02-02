import { parseProgram } from "./parser";
import { WasmEmitter } from "./emit/wasm-emitter.ts";
import process from "node:process";
import fs from "node:fs";
import util from 'node:util'
import { parseCommandLine } from "./cli.ts";
import { resolve } from "./resolver/resolver.ts";

const cli = parseCommandLine(process.argv);
for (const source_path of cli.positionalArgument) {
  const source = fs.readFileSync(source_path, { encoding: "utf-8" });
  const program = parseProgram(source, source_path);
  const resolvedProgram = resolve(program);
  console.log(util.inspect(resolvedProgram, {depth: null, colors: true}))

  const emitter = new WasmEmitter();
  emitter.emit(resolvedProgram, 'build')
}
process.exit(0);

//console.log(util.inspect(root, {depth: null}));

//emitter.emit(root, "build");
