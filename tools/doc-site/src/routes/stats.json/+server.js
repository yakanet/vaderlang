import { json } from '@sveltejs/kit';
import { stats } from '#lib/server/data.js';

// A route that serves a file does not inherit the layout's options.
export const prerender = true;

// The size of the site, for a page that links to it: `{ modules, exports }`.
export const GET = () => json(stats);
