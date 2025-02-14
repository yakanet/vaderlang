import {compile} from 'svelte/compiler'
import {FileResolver} from "../../src/resolver/module_resolver.ts";
import process from "node:process";
import {parseProgram} from "../../src/parser";
import {resolve} from "../../src/resolver/resolver.ts";
import fs from "node:fs";

const source_path = 'examples/arrays.vader'; // TODO Must be an input from cli

const resolver = new FileResolver(process.cwd(), ['./modules']);
const program = parseProgram(source_path, resolver);
const resolvedProgram = resolve(program);
const files = Object.fromEntries([...resolvedProgram.body.reduce((acc, node) => acc.add(node.location.file), new Set<string>()).values()].map(file => [file, fs.readFileSync(file, {encoding: 'utf-8'})]));
const compiledFiles = await buildSvelteFile(files, resolvedProgram)

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
            'tools/ast-viewer/index.html'
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