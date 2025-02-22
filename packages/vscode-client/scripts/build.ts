import fs from "node:fs"
import path from "node:path"

const isDev = Bun.argv.includes('--dev');
const LSP_LOCATION = isDev
    ? '../lsp-server/build/index.js'
    : './build/lsp/build/index.js'

// Copy LSP ?
if (!isDev) {
    fs.mkdirSync('build/lsp/build', { recursive: true });
    fs.copyFileSync(
        path.resolve(import.meta.dir, '../../lsp-server/build/index.js'),
        path.resolve(import.meta.dir, './../build/lsp/build/index.js'),
    )
    fs.copyFileSync(
        path.resolve(import.meta.dir, '../../lsp-server/package.json'),
        path.resolve(import.meta.dir, './../build/lsp/package.json'),
    )
}

// Build vscode extension
Bun.build({
    entrypoints: ['src/extension.ts'],
    format: 'cjs',
    target: 'node',
    external: ['vscode'],
    outdir: "build",
    define: {
        'LSP_LOCATION': JSON.stringify(LSP_LOCATION)
    }
})