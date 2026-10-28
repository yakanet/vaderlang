// Where a page of the site is: shared by the pages, the search and the links the
// specification's cross-references become, which must agree.

import { resolve } from '$app/paths';

// The site is built with `trailingSlash: 'always'`: a link without the slash
// costs a redirect on every full page load.

/** The index of the specification. */
export const spec_href = () => resolve('/spec') + '/';

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
 * One of the API references `vader doc` writes, published beside this site: an
 * other build, which a link reaches with `rel="external"`.
 * @param {'lib' | 'vader'} site
 */
export const api_href = (site) => `${resolve('/')}${site}/`;

/**
 * How a chapter is named in a list: its number, then its title.
 * @param {{ number: string, title: string }} chapter
 */
export function chapter_label(chapter) {
	if (chapter.number === '') return chapter.title;
	return `${chapter.number}. ${chapter.title}`;
}
