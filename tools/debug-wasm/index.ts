import fs from "node:fs";
import process from "node:process";

const [_runtime, _script, wasm_path] = process.argv;
if (!wasm_path) {
    console.error(`missing location of a wasm file`);
    process.exit(1);
}

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

function serveStaticBinary(path: string, contentType: string) {
    return new Response(fs.readFileSync(path), {
        headers: {
            'Content-type': contentType
        }
    })
}

const server = Bun.serve({
    async fetch(request) {
        const url = new URL(request.url);
        if (url.pathname === '/') return serveStatic('tools/debug-wasm/index.html', 'text/html')
        if (url.pathname === '/module.wasm') return serveStaticBinary(wasm_path, 'application/wasm')//'__snapshot__/examples/arraylists/arraylists.wasm', 'application/wasm')
        return new Response(undefined, {
            status: 404
        })
    }
})

console.log(`Listening on http://localhost:${server.port}`);