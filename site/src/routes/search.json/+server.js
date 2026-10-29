import { content_search_entries } from '#lib/server/content.js';
import { learn_chapters } from '#lib/server/learn.js';
import { spec_chapters } from '#lib/server/spec.js';

export const prerender = true;

// Every heading of the site, fetched by the search at its first use.
export const GET = () => Response.json({
	entries: [
		...content_search_entries,
		...learn_chapters.search_entries,
		...spec_chapters.search_entries
	]
});
