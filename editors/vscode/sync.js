#!/usr/bin/env node
const fs = require('node:fs');
const path = require('node:path');

const HERE = __dirname;
const COMMON = path.resolve(HERE, '../common');

// Where each kind of shared file lands in the extension — the same layout
// `editors/intellij/build.gradle.kts` gives the plugin's bundle.
const destination = (name) =>
  name.endsWith('.tmLanguage.json') ? `syntaxes/${name}` :
  name.endsWith('language-configuration.json') ? name :
  name.endsWith('.svg') ? `icons/${name}` :
  null;

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
