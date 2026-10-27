import { json } from '@sveltejs/kit';
import { anchor_of } from '#lib/anchors.js';
import { index } from '#lib/server/data.js';

// A route that serves a file does not inherit the layout's options.
export const prerender = true;

// What the search box reads, once, at its first use: short keys, since every
// entry of the data is in it.
export const GET = () =>
	json({
		entries: index.entries.map((e) => ({
			m: e.module,
			n: e.name,
			k: e.kind,
			a: anchor_of(e.module, e.id),
			s: e.summary
		}))
	});
