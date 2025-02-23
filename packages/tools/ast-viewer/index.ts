import {compile} from 'svelte/compiler'
import {BundleContext, FileResolver, locationToString} from "@vaderlang/compiler";
import process from "node:process";
import {parseProgram} from "@vaderlang/compiler";
import {resolve} from "@vaderlang/compiler";
import fs from "node:fs";
import path from 'node:path';

const [_runtime, _script, source_path, ...options] = process.argv;
if (!source_path) {
    console.error(`missing location of a vader file`);
    process.exit(1);
}
let no_resolve = false;
if (options.find(o => o === "--no-resolve")) {
    no_resolve = true;
}

const resolver = new FileResolver(process.cwd(), ['./modules']);
const context = new BundleContext(resolver);
let program = parseProgram(source_path, context);
if (!no_resolve) {
    program = resolve(program, context);
}
if(context.diagnostic.getDiagnostics().length > 0) {
    for(const diagnostic of context.diagnostic.getDiagnostics()) {
        console.error(`${diagnostic.type}:${locationToString(diagnostic.location)}: ${diagnostic.message}`)
        process.exit(1);
    }
}
const files = Object.fromEntries([...program.body.reduce((acc, node) => acc.add(node.location.file), new Set<string>()).values()].map(file => [file, fs.readFileSync(file, {encoding: 'utf-8'})]));
const compiledFiles = await buildSvelteFile(files, program)

function serveContent(content: string, contentType: string) {
    return new Response(content, {
        headers: {
            'Content-type': contentType
        }
    })
}

//console.log(compiledFiles.map(c => ({path: c.path, type: c.type})));
const server = Bun.serve({
    async fetch(request) {
        const url = new URL(request.url);
        let pathname = url.pathname
        if (pathname === '/') {
            pathname = '/index.html'
        }
        const file = compiledFiles.find(c => c.path === `.${pathname}`);
        if (!file) {
            return new Response(null, {status: 404})
        }
        return serveContent(await file.text(), file.type)
    }
})

async function buildSvelteFile(files: Record<string, string>, parsed: any) {
    const result = await Bun.build({
        entrypoints: [
            path.resolve(import.meta.dir, 'index.html')
        ],
        define: {
            PARSED_PROGRAM: JSON.stringify(parsed),
            PARSED_FILES: JSON.stringify(files)
        },
        plugins: [
            {
                name: 'Svelte Compiler',
                setup(builder): void | Promise<void> {
                    builder.onLoad({filter: /\.svelte(\?[^.]+)?$/}, ({path}) => {
                        try {
                            const source = fs.readFileSync(
                                path.substring(0, path.includes("?") ? path.indexOf("?") : path.length),
                                "utf-8"
                            );
                            const result = compile(source, {
                                filename: path,
                                generate: "client",
                                css: 'injected'
                            });
                            return {
                                contents: result.js.code,
                                loader: "js",
                            };
                        } catch (err) {
                            throw new Error(`Failed to compile Svelte component: ${err}`);
                        }
                    });
                }
            }
        ],
    })
    return result.outputs
}

console.log(`Listening on http://localhost:${server.port}`);