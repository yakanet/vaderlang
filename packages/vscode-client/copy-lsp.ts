import fs from "node:fs"
import path from "node:path"

fs.mkdirSync('build/lsp/build', {recursive: true});
fs.copyFileSync(
    path.resolve(import.meta.dir, '../lsp-server/build/index.js'), 
    path.resolve(import.meta.dir, './build/lsp/build/index.js'),
)

fs.copyFileSync(
    path.resolve(import.meta.dir, '../lsp-server/package.json'), 
    path.resolve(import.meta.dir, './build/lsp/package.json'),
)