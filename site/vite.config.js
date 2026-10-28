// The site of the language: its specification, one page per chapter, and the way
// to the two API references `vader doc` writes, published beside it under `lib/`
// and `vader/`.

import adapter from '@sveltejs/adapter-static';
import { sveltekit } from '@sveltejs/kit/vite';
import { defineConfig } from 'vite';

const base = /** @type {'' | `/${string}`} */ (process.env.BASE_PATH ?? '');

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
			adapter: adapter({ pages: 'build', assets: 'build', fallback: '404.html' }),
			paths: { base }
		})
	]
});
