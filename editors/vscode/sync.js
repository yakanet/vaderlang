#!/usr/bin/env node
const fs = require('node:fs');
const path = require('node:path');

const HERE = __dirname;
const COMMON = path.resolve(HERE, '../common');

// The folder each kind of shared file lands in, by the end of its name.
const FOLDERS = [
  ['.tmLanguage.json', 'syntaxes'],
  ['language-configuration.json', '.'],
  ['.svg', 'icons'],
  ['.schema.json', 'schemas'],
];

const destination = (name) => {
  const kind = FOLDERS.find(([suffix]) => name.endsWith(suffix));
  if (kind === undefined) return null;
  const [, folder] = kind;
  return path.posix.join(folder, name);
};

const files = fs.readdirSync(COMMON)
  .map((name) => [name, destination(name)])
  .filter(([, dst]) => dst !== null);

for (const [src, dst] of files) {
  const from = path.join(COMMON, src);
  const to = path.join(HERE, dst);
  fs.mkdirSync(path.dirname(to), { recursive: true });
  fs.copyFileSync(from, to);
  console.log(`  ${dst}`);
}

// The project LICENSE lives at the repo root ; copy it in so the packaged
// extension carries a LICENSE file (vsce flags its absence otherwise).
fs.copyFileSync(path.resolve(HERE, '../../LICENSE'), path.join(HERE, 'LICENSE'));
console.log('  LICENSE');

console.log(`synced ${files.length + 1} files (${COMMON} + repo LICENSE)`);
