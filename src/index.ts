import {parseProgram} from "./parser";
import {WasmEmitter} from "./emit/wasm-emitter.ts";
import process from "node:process";
import util from 'node:util'
import {parseCommandLine} from "./cli.ts";
import {resolve} from "./resolver/resolver.ts";
import child_process from 'node:child_process'
import {FileResolver} from "./resolver/module_resolver.ts";

const cli = parseCommandLine(process.argv);
for (const source_path of cli.positionalArgument) {
    const resolver = new FileResolver(process.cwd());
    const program = parseProgram(source_path, resolver);
    const resolvedProgram = resolve(program);
    if (!cli.options.has('run')) {
        console.log(util.inspect(resolvedProgram, {depth: null, colors: true}))
    }

    const emitter = new WasmEmitter({
        emitStdio: !cli.options.has('run')
    });
    emitter.emit(resolvedProgram, 'build')
}
if (cli.options.has('run')) {
    child_process.spawnSync('wasmtime', ['build/wasm/app.wasm'], {
        shell: true,
        stdio: 'inherit'
    });
}
process.exit(0);
