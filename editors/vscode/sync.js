#!/usr/bin/env node
const fs = require('node:fs');
const path = require('node:path');

const HERE = __dirname;
const COMMON = path.resolve(HERE, '../common');

const files = [
  ['vader.tmLanguage.json',     'syntaxes/vader.tmLanguage.json'],
  ['language-configuration.json', 'language-configuration.json'],
  ['vader.svg',                 'icons/vader.svg'],
  ['vir.svg',                   'icons/vir.svg'],
];

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
