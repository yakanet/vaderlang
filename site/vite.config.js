// The site of the language: its specification, one page per chapter, and the way
// to the two API references `vader doc` writes, published beside it under `lib/`
// and `vader/`.

import fs from 'node:fs';
import path from 'node:path';
import adapter from '@sveltejs/adapter-static';
import { sveltekit } from '@sveltejs/kit/vite';
import { defineConfig } from 'vite';

const base = /** @type {'' | `/${string}`} */ (process.env.BASE_PATH ?? '');
const OUT = 'build';

// The static adapter, then the files it writes for a client router: the data of
// each page and the router itself. No page loads them, since the root layout
// sets `csr = false`.
/** @returns {import('@sveltejs/kit').Adapter} */
function static_pages() {
	const inner = adapter({ pages: OUT, assets: OUT });
	return {
		...inner,
		async adapt(builder) {
			await inner.adapt(builder);
			const files = /** @type {string[]} */ (fs.readdirSync(OUT, { recursive: true }));
			for (const file of files.filter((f) => path.basename(f) === '__data.json')) {
				fs.rmSync(path.join(OUT, file));
			}
			for (const dir of ['entry', 'chunks', 'nodes']) {
				fs.rmSync(path.join(OUT, '_app', 'immutable', dir), { recursive: true, force: true });
			}
			fs.rmSync(path.join(OUT, '_app', 'version.json'), { force: true });
		}
	};
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
			adapter: static_pages(),
			// Absolute, for `404.html`: the host serves it at any depth.
			paths: { base, relative: false }
		})
	]
});
