import { search_entries } from '#lib/server/spec.js';

export const prerender = true;

// Every chapter and heading of the specification, fetched by the search box at its
// first use.
export const GET = () => Response.json({ entries: search_entries });
