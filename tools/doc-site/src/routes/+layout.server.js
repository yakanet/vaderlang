import { index, site_title } from '#lib/server/data.js';

/**
 * What the side bar shows of the module `path` under `head`: the rest of its
 * path, or the whole of it when it is `head`.
 * @param {string} path
 * @param {string} head
 */
function label_of(path, head) {
	if (path === head) return head;
	return path.slice(head.length + 1);
}

// The modules the side bar lists, under the first part of their path: `std/io`
// under `std`. Every page carries them, so they hold what the side bar shows and
// nothing more.
export const load = () => {
	const tree = Map.groupBy(index.modules, (m) => m.path.split('/')[0]);
	return {
		title: site_title,
		tree: [...tree].map(([head, modules]) => ({
			head,
			modules: modules.map((m) => ({ path: m.path, label: label_of(m.path, head) }))
		}))
	};
};
