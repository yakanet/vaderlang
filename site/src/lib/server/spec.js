// SPEC.md as the site reads it: one chapter per `## ` heading, rendered to HTML
// with an anchor on each heading below it and its Vader code highlighted.
//
// A cross-reference, `§N` or `§N *Title*`, becomes a link to the chapter, or to
// the heading of that title in it ; a title may stop at its colon (`*Identity*` for
// "Identity: `===` and `!==`"). A link to a file of the repository leads to its
// source. One that names nothing stops the build: `tests/spec_references.test.ts`
// checks the citations of the whole repository, this the links the site writes.

import fs from 'node:fs';
import path from 'node:path';
import { Marked } from 'marked';
import { chapter_href, GITHUB, heading_href } from '../links.js';
import { escape_html } from './highlight.js';
import { assign_heading_ids, code_renderers, heading_html, heading_id, plain, slugify } from './markdown.js';
import { REPO } from './repo.js';

/**
 * @typedef {import('./markdown.js').Heading} Heading
 * @typedef {{
 *   number: string, title: string, slug: string,
 *   tokens: import('marked').Token[], headings: Heading[], html: string
 * }} Chapter
 */

// Where the files of the repository are read online.
const SOURCE_URL = process.env.SITE_SOURCE_URL ?? `${GITHUB}/blob/main/`;
const SPEC = path.join(REPO, 'SPEC.md');

const CHAPTER = /^(?:(\d+)\. )?(.+)$/;
// A title may hold code, whose `*` does not end it.
const REFERENCE = /^§(\d+)(?: \*((?:`[^`]*`|[^*`])+)\*)?/;

/** @type {import('marked').TokenizerAndRendererExtension} */
const reference = {
	name: 'reference',
	level: 'inline',
	start(src) {
		const at = src.indexOf('§');
		if (at < 0) return undefined;
		return at;
	},
	tokenizer(src) {
		const match = REFERENCE.exec(src);
		if (!match) return undefined;
		return {
			type: 'reference',
			raw: match[0],
			number: match[1],
			title: match[2],
			href: '',
			// The title, rendered after the `§N` the link starts with.
			tokens: this.lexer.inlineTokens(match[0].slice(1 + match[1].length))
		};
	},
	renderer(token) {
		const title = this.parser.parseInline(token.tokens ?? []);
		return `<a href="${escape_html(token.href)}">§${token.number}${title}</a>`;
	}
};

const markdown = new Marked({
	extensions: [reference],
	renderer: {
		// The chapter's title is the page's `h1`: its sections start at `h2`.
		heading(token) {
			return heading_html(this.parser.parseInline(token.tokens), token.depth - 1, heading_id(token));
		},
		...code_renderers
	}
});

const tokens = markdown.lexer(fs.readFileSync(SPEC, 'utf8'));

/** @type {import('marked').Token[]} */
const intro = [];
/** @type {Chapter[]} */
const chapters = [];
for (const token of tokens) {
	if (token.type === 'heading' && token.depth === 1) continue;
	if (token.type === 'heading' && token.depth === 2) {
		const [, number = '', title] = /** @type {RegExpExecArray} */ (CHAPTER.exec(token.text));
		const slug = slugify(`${number} ${title}`);
		chapters.push({ number, title, slug, tokens: [], headings: [], html: '' });
		continue;
	}
	const current = chapters.at(-1);
	if (current) current.tokens.push(token);
	else intro.push(token);
}

// Each heading of a chapter takes an id unique in it.
for (const chapter of chapters) chapter.headings = assign_heading_ids(chapter.tokens);

const BY_NUMBER = new Map(chapters.filter((c) => c.number).map((c) => [c.number, c]));

/**
 * Where a reference to chapter `number`, at the heading `title` when it names
 * one, leads ; null when no such heading exists.
 * @param {string} number
 * @param {string | undefined} title
 */
function target_of(number, title) {
	const chapter = BY_NUMBER.get(number);
	if (!chapter) return null;
	if (!title) return chapter_href(chapter.slug);
	const cited = plain(title);
	if (cited === chapter.title) return chapter_href(chapter.slug);
	const heading = chapter.headings.find((h) => h.title === cited || h.title.split(': ')[0] === cited);
	if (!heading) return null;
	return heading_href(chapter.slug, heading.id);
}

/**
 * Where the link `href` of the specification leads on the site: a file of the
 * repository, relative to the specification, to its source ; null for one that
 * does not exist.
 * @param {string} href
 */
function site_href(href) {
	if (/^([a-z][a-z+.-]*:|#|\/)/i.test(href)) return href;
	const file = path.resolve(path.dirname(SPEC), href);
	if (!fs.existsSync(file)) return null;
	return SOURCE_URL + path.relative(REPO, file).split(path.sep).join('/');
}

/** @type {string[]} */
const broken = [];
markdown.walkTokens(tokens, (token) => {
	if (token.type === 'reference') {
		token.href = target_of(token.number, token.title) ?? '';
		if (token.href === '') broken.push(token.raw);
	} else if (token.type === 'link') {
		const href = site_href(token.href);
		if (href === null) broken.push(token.href);
		token.href = href ?? token.href;
	}
});
if (broken.length > 0) {
	throw new Error(`SPEC.md names what it lacks: ${[...new Set(broken)].join(', ')}`);
}

for (const chapter of chapters) {
	chapter.html = /** @type {string} */ (markdown.parser(chapter.tokens));
}

/** The chapters, in order, as the side bar and the index list them. */
export const chapter_list = chapters.map(({ number, title, slug }) => ({ number, title, slug }));

/** What the specification says before its first chapter. */
export const introduction = /** @type {string} */ (markdown.parser(intro));

/**
 * The page of the chapter `slug` ; null for a slug no chapter has.
 * @param {string} slug
 */
export function chapter_page(slug) {
	const index = chapters.findIndex((c) => c.slug === slug);
	if (index < 0) return null;
	const chapter = chapters[index];
	return {
		number: chapter.number,
		title: chapter.title,
		html: chapter.html,
		outline: chapter.headings.filter((h) => h.depth === 3),
		previous: chapter_list[index - 1] ?? null,
		next: chapter_list[index + 1] ?? null
	};
}

/**
 * Where the search shows a chapter's entries come from: `§N`, or the title of a
 * chapter without a number.
 * @param {Chapter} chapter
 */
function search_label(chapter) {
	if (chapter.number === '') return chapter.title;
	return `§${chapter.number}`;
}

/** Every chapter and every heading, as the search reads them. */
export const search_entries = chapters.flatMap((c) => {
	const where = search_label(c);
	return [
		{ title: c.title, where, href: chapter_href(c.slug) },
		...c.headings.map((h) => ({ title: h.title, where, href: heading_href(c.slug, h.id) }))
	];
});
