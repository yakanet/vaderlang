import fs from "node:fs";
import process from "node:process";
import {BundleContext, FileResolver, locationToString, WasmEmitter} from "@vaderlang/compiler";
import {parseProgram} from "@vaderlang/compiler";
import {resolve} from "@vaderlang/compiler";
const [_runtime, _script, vader_path] = process.argv;
if (!vader_path) {
    console.error(`missing location of a vader file`);
    process.exit(1);
}


const resolver = new FileResolver(process.cwd(), ['./modules']);
const context = new BundleContext(resolver);
let program = parseProgram(vader_path, context);
if(context.diagnostic.getDiagnostics().length > 0) {
    for(const diagnostic of context.diagnostic.getDiagnostics()) {
        console.error(`${diagnostic.type}:${locationToString(diagnostic.location)}: ${diagnostic.message}`)
        process.exit(1);
    }
}
program = resolve(program, context);
const module = new WasmEmitter(true).emit(program)

function serveContent(content: string, contentType: string) {
    return new Response(content, {
        headers: {
            'Content-type': contentType
        }
    })
}

function serveStatic(path: string, contentType: string) {
    return serveContent(fs.readFileSync(path, {encoding: 'utf-8'}), contentType)
}

function serveStaticBinary(content: Uint8Array, contentType: string) {
    return new Response(content, {
        headers: {
            'Content-type': contentType
        }
    })
}

const server = Bun.serve({
    async fetch(request) {
        const url = new URL(request.url);
        if (url.pathname === '/') return serveStatic('packages/tools/debug-wasm/index.html', 'text/html')
        if (url.pathname === '/module.wasm') return serveStaticBinary(module.emitBinary(), 'application/wasm')
        return new Response(undefined, {
            status: 404
        })
    }
})

console.log(`Listening on http://localhost:${server.port}`);