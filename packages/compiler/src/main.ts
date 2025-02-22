import {parseProgram} from "./parser";
import {WasmEmitter} from "./emit/wasm-emitter.ts";
import process from "node:process";
import util from 'node:util'
import {parseCommandLine} from "./cli.ts";
import {resolve} from "./resolver/resolver.ts";
import child_process from 'node:child_process'
import {FileResolver} from "./resolver/module_resolver.ts";
import fs from "node:fs";

const cli = parseCommandLine(process.argv);
const debug = !cli.options.has('run');
for (const source_path of cli.positionalArgument) {
    const resolver = new FileResolver(process.cwd(), ['./modules']);
    const program = parseProgram(source_path, resolver);
    const resolvedProgram = resolve(program);
    if (debug) {
        console.log(util.inspect(resolvedProgram, {depth: null, colors: true}))
    }

    const emitter = new WasmEmitter();
    const module = emitter.emit(resolvedProgram)
    if (debug) {
        console.log(module.emitText());
    }
    fs.mkdirSync(`build/wasm`, {recursive: true});
    fs.writeFileSync(
        `build/wasm/app.wasm`,
        module.emitBinary()
    );
}
if (cli.options.has('run')) {
    const pid = child_process.spawnSync('wasmtime', ['--wasm=gc', 'build/wasm/app.wasm'], {
        shell: true,
        stdio: 'inherit',
    })
    process.exit(pid.status)
}