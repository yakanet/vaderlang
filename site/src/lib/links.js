// Where a page of the site is: shared by the pages, the search and the links the
// specification's cross-references become, which must agree.

import { resolve } from '$app/paths';

/** The repository of the language. */
export const GITHUB = 'https://github.com/yakanet/vaderlang';

// The site is built with `trailingSlash: 'always'`: a link without the slash
// costs a redirect on every full page load.

/**
 * A path written from the root of the site (`/download/#linux`), under the base
 * path the site is served from.
 * @param {string} path
 */
export const site_href = (path) => `${resolve('/')}${path.slice(1)}`;

/**
 * A page of the site at its root, `download` for `/download/`.
 * @param {string} name
 */
export const page_href = (name) => site_href(`/${name}/`);

/**
 * The API references `vader doc` writes, published beside this site under
 * these names: other builds, which a link reaches with `rel="external"`.
 */
export const API_SITES = ['lib', 'vader'];

/** The sections of the site the header lists, by the name of their page. */
export const SECTIONS = [
	{ name: 'start', label: 'Get started' },
	{ name: 'examples', label: 'Examples' },
	{ name: 'spec', label: 'Specification' }
];

/** @param {string} slug */
export const chapter_href = (slug) => resolve('/spec/[chapter]', { chapter: slug }) + '/';

/**
 * @param {string} slug
 * @param {string} id  a heading's id, or "" for the chapter itself.
 */
export function heading_href(slug, id) {
	if (id === '') return chapter_href(slug);
	return `${chapter_href(slug)}#${id}`;
}

/**
 * How a chapter is named in a list: its number, then its title.
 * @param {{ number: string, title: string }} chapter
 */
export function chapter_label(chapter) {
	if (chapter.number === '') return chapter.title;
	return `${chapter.number}. ${chapter.title}`;
}
