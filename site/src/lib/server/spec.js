// SPEC.md as the site reads it: one chapter per `## ` heading, rendered to HTML
// with an anchor on each heading below it and its Vader code highlighted.
//
// A cross-reference, `§N` or `§N *Title*`, becomes a link to the chapter, or to
// the heading of that title in it ; a title may stop at its colon (`*Identity*` for
// "Identity: `===` and `!==`"). The other pages of the site cite the specification
// the same way (`reference`, `resolve_references`). A link to a file of the
// repository leads to its source. One that names nothing stops the build:
// `tests/spec_references.test.ts` checks the citations of the whole repository,
// this the links the site writes.

import fs from 'node:fs';
import path from 'node:path';
import { Marked } from 'marked';
import { chapter_href, GITHUB, heading_href } from '../links.js';
import { chapter_set } from './chapters.js';
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

/**
 * A reference to the specification, `§N` or `§N *Title*`: a link whose `href`
 * `resolve_references` sets.
 * @type {import('marked').TokenizerAndRendererExtension}
 */
export const reference = {
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
 * Points each reference of `tokens` at its chapter or heading, and returns those
 * that name nothing, as written.
 * @param {import('marked').Token[]} tokens
 */
export function resolve_references(tokens) {
	/** @type {string[]} */
	const broken = [];
	markdown.walkTokens(tokens, (token) => {
		if (token.type !== 'reference') return;
		const href = target_of(token.number, token.title);
		if (href === null) broken.push(token.raw);
		else token.href = href;
	});
	return broken;
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

const broken = resolve_references(tokens);
markdown.walkTokens(tokens, (token) => {
	if (token.type !== 'link') return;
	const href = site_href(token.href);
	if (href === null) broken.push(token.href);
	else token.href = href;
});
if (broken.length > 0) {
	throw new Error(`SPEC.md names what it lacks: ${[...new Set(broken)].join(', ')}`);
}

for (const chapter of chapters) {
	chapter.html = /** @type {string} */ (markdown.parser(chapter.tokens));
}

/** What the specification says before its first chapter. */
export const introduction = /** @type {string} */ (markdown.parser(intro));

/**
 * Where the search shows a chapter's entries come from: `§N`, or the title of a
 * chapter without a number.
 * @param {{ number: string, title: string }} chapter
 */
function search_label(chapter) {
	if (chapter.number === '') return chapter.title;
	return `§${chapter.number}`;
}

/** The chapters of the specification, as its pages and the search show them. */
export const spec_chapters = chapter_set(
	chapters.map((c) => ({ ...c, outline: c.headings.filter((h) => h.depth === 3) })),
	chapter_href,
	search_label
);
