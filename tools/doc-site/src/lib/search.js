// The search of the site, over the index `search-index.json` serves: pure, so
// it can be timed outside a page.

import { overloads_anchor } from './anchors.js';

/**
 * An entry of the index: its module, its name, its kind, its anchor in its
 * module's page, and its summary.
 * @typedef {{ m: string, n: string, k: string, a: string, s: string }} Entry
 * @typedef {{ entry: Entry, base: string, count: number }} Hit
 */

/**
 * The entries `query` names, best first, at most `limit`: a whole name or a
 * qualified one (`io.read_file_bytes`) first, then a name it starts, then one
 * it is part of. Case does not count, and the overloads of a name are one hit.
 * @param {Entry[]} entries
 * @param {string} query
 * @param {number} limit
 * @returns {Hit[]}
 */
export function search(entries, query, limit) {
	const q = query.trim().toLowerCase();
	if (q === '') return [];
	/** @type {{ entry: Entry, base: string, rank: number }[]} */
	const ranked = [];
	for (const entry of entries) {
		const base = overloads_anchor(entry.a);
		const rank = rank_of(entry, base, q);
		if (rank >= 0) ranked.push({ entry, base, rank });
	}
	ranked.sort(
		(a, b) =>
			a.rank - b.rank ||
			a.base.length - b.base.length ||
			a.entry.m.localeCompare(b.entry.m) ||
			a.base.localeCompare(b.base)
	);
	/** @type {Map<string, Hit>} */
	const hits = new Map();
	for (const { entry, base } of ranked) {
		const key = `${entry.m}/${base}`;
		const seen = hits.get(key);
		if (seen) {
			seen.count++;
		} else if (hits.size < limit) {
			hits.set(key, { entry, base, count: 1 });
		}
	}
	return [...hits.values()];
}

/**
 * @param {Entry} entry
 * @param {string} base  its anchor without an overload's `~n`
 * @param {string} q     the query, in lower case
 */
function rank_of(entry, base, q) {
	const name = entry.n.toLowerCase();
	const lower = base.toLowerCase();
	const qualified = `${entry.m}.${lower}`.toLowerCase();
	if (name === q || lower === q || qualified === q || qualified.endsWith(`/${q}`)) return 0;
	if (name.startsWith(q) || lower.startsWith(q)) return 1;
	if (qualified.includes(q)) return 2;
	return -1;
}
