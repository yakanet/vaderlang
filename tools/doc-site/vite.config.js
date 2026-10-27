// The site of `vader doc`: one page per module of the data `VADER_DOC_DATA`
// names, prerendered into `VADER_DOC_OUT`. `vader doc -o` copies this folder
// next to an installed `node_modules` and sets the variables; a checkout can
// run it in place for development, from the data of `vader doc` at the root.

import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import adapter from '@sveltejs/adapter-static';
import { sveltekit } from '@sveltejs/kit/vite';
import { defineConfig } from 'vite';

const data_dir = path.resolve(process.env.VADER_DOC_DATA ?? '../../build/doc');
const out = process.env.VADER_DOC_OUT ?? 'build';

// The same data gives the same site: SvelteKit's version names the build, and
// would be a timestamp otherwise.
function data_version() {
	const hash = createHash('sha256');
	const walk = (/** @type {string} */ dir) => {
		const entries = fs.readdirSync(dir, { withFileTypes: true });
		for (const entry of entries.sort((a, b) => a.name.localeCompare(b.name, 'en'))) {
			const file = path.join(dir, entry.name);
			if (entry.isDirectory()) walk(file);
			else if (entry.name.endsWith('.json')) hash.update(entry.name).update(fs.readFileSync(file));
		}
	};
	walk(data_dir);
	return hash.digest('hex').slice(0, 12);
}

// Runes for the site's own components; a library keeps the mode it was
// written in.
/** @param {{ filename: string }} file */
function runes_of({ filename }) {
	if (filename.split(/[/\\]/).includes('node_modules')) return undefined;
	return true;
}

export default defineConfig({
	plugins: [
		sveltekit({
			compilerOptions: { runes: runes_of },
			adapter: adapter({ pages: out, assets: out, fallback: '404.html' }),
			paths: { base: /** @type {'' | `/${string}`} */ (process.env.BASE_PATH ?? '') },
			version: { name: data_version() }
		})
	]
});
