// Where an entry of the data is found: its module's page, and the anchor of the
// entry in it. Shared by the pages and the search, which must agree.

import { resolve } from '$app/paths';

/**
 * The anchor of the entry `id` in the page of `module`: the id without its
 * module, without blanks (`Point: Shape` is `Point:Shape`).
 * @param {string} module
 * @param {string} id
 */
export const anchor_of = (module, id) => id.slice(module.length + 1).replaceAll(' ', '');

/**
 * The anchor the overloads of a name share: `min` for `min~1`.
 * @param {string} anchor
 */
export const overloads_anchor = (anchor) => anchor.replace(/~\d+$/, '');

// The site is built with `trailingSlash: 'always'`: a link without the slash
// costs a redirect on every full page load.

/** @param {string} module */
export const module_href = (module) => resolve('/[...module]', { module }) + '/';

/**
 * @param {string} module
 * @param {string} anchor
 */
export const entry_href = (module, anchor) => `${module_href(module)}#${encodeURI(anchor)}`;
