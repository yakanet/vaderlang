// What a set of chapters, the specification's or the tour's, gives its pages:
// the list on its index and beside each chapter, each chapter's page with the
// chapters around it, and the entries of the search.

import { chapter_label } from '../links.js';

/**
 * @typedef {import('./markdown.js').Heading} Heading
 * @typedef {{
 *   number: string, title: string, slug: string, html: string,
 *   headings: Heading[], outline: Heading[]
 * }} Chapter
 */

/**
 * @param {Chapter[]} chapters  in order; `headings` go to the search, `outline`
 *                              on top of the page.
 * @param {(slug: string) => string} href_of  where a chapter is.
 * @param {(chapter: Chapter) => string} where_of  how the search names a
 *                              chapter its entries come from.
 */
export function chapter_set(chapters, href_of, where_of) {
	const links = chapters.map((c) => ({ href: href_of(c.slug), label: chapter_label(c) }));
	return {
		links,
		slugs: chapters.map((c) => c.slug),
		/**
		 * What `ChapterPage` shows for the chapter `slug` ; null for a slug no
		 * chapter has.
		 * @param {string} slug
		 */
		page(slug) {
			const index = chapters.findIndex((c) => c.slug === slug);
			if (index < 0) return null;
			return {
				chapters: links,
				current: links[index].href,
				title: links[index].label,
				outline: chapters[index].outline,
				html: chapters[index].html,
				previous: links[index - 1] ?? null,
				next: links[index + 1] ?? null
			};
		},
		search_entries: chapters.flatMap((c) => {
			const where = where_of(c);
			const href = href_of(c.slug);
			return [
				{ title: c.title, where, href },
				...c.headings.map((h) => ({ title: h.title, where, href: `${href}#${h.id}` }))
			];
		})
	};
}
