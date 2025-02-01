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
  console.log(util.inspect(program, {depth: 99, colors: true}))
  const resolvedProgram = resolve(program);

  const emitter = new WasmEmitter();
  emitter.emit(resolvedProgram, 'build')
}
process.exit(0);

//console.log(util.inspect(root, {depth: null}));

//emitter.emit(root, "build");
