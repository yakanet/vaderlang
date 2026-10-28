import { content_search_entries } from '#lib/server/content.js';
import { search_entries } from '#lib/server/spec.js';

export const prerender = true;

// Every heading of the site, fetched by the search at its first use.
export const GET = () => Response.json({ entries: [...content_search_entries, ...search_entries] });
