import { error } from '@sveltejs/kit';
import { index, module_paths, read_module } from '#lib/server/data.js';
import { module_page } from '#lib/server/page.js';

export const entries = () => index.modules.map((m) => ({ module: m.path }));

/** @param {{ params: { module: string } }} event */
export const load = ({ params }) => {
	// With `trailingSlash: 'always'`, the rest parameter keeps the final slash.
	const path = params.module.replace(/\/$/, '');
	if (!module_paths.has(path)) error(404, `no module ${path}`);
	return module_page(read_module(path));
};
