// What every Markdown page of the site renders the same way: the ids of its
// headings, its code (Vader highlighted, without the lines that only set an
// example up; the rest escaped), and the raw HTML it may hold, shown as text.

import { shown_code } from './hidden_lines.js';
import { code_html, escape_html } from './highlight.js';

/**
 * @typedef {{ id: string, title: string, depth: number }} Heading
 */

/**
 * A title as a reader sees it, the marks of its Markdown left out.
 * @param {string} text
 */
export const plain = (text) => text.replaceAll('`', '').replaceAll('*', '').trim();

/**
 * The id a heading takes: its plain text in lower case, words joined by `-`.
 * @param {string} text
 */
export const slugify = (text) =>
	plain(text)
		.toLowerCase()
		.replace(/[^\p{L}\p{N}]+/gu, '-')
		.replace(/^-|-$/g, '');

/**
 * Gives each heading of `tokens` an id unique among them, on its token for the
 * renderer, and returns the headings in order.
 * @param {import('marked').Token[]} tokens
 * @returns {Heading[]}
 */
export function assign_heading_ids(tokens) {
	/** @type {Map<string, number>} */
	const seen = new Map();
	/** @type {Heading[]} */
	const headings = [];
	for (const token of tokens) {
		if (token.type !== 'heading') continue;
		const base = slugify(token.text);
		const count = (seen.get(base) ?? 0) + 1;
		seen.set(base, count);
		let id = base;
		if (count > 1) id = `${base}-${count}`;
		/** @type {{ id?: string }} */ (token).id = id;
		headings.push({ id, title: plain(token.text), depth: token.depth });
	}
	return headings;
}

/**
 * A heading at `level`, with the anchor that links to it.
 * @param {string} inner  its rendered text.
 * @param {number} level
 * @param {string} id
 */
export function heading_html(inner, level, id) {
	const self = `<a class="self" href="#${id}" aria-label="Link to this section">#</a>`;
	return `<h${level} id="${id}">${inner}${self}</h${level}>\n`;
}

/**
 * The id `assign_heading_ids` gave `token`, or one from its text.
 * @param {import('marked').Tokens.Heading} token
 */
export const heading_id = (token) => /** @type {{ id?: string }} */ (token).id ?? slugify(token.text);

/** The renderers of code and raw HTML every page shares. */
export const code_renderers = {
	/** @param {{ text: string }} token */
	html: ({ text }) => escape_html(text),
	/** @param {{ text: string }} token */
	codespan: ({ text }) => `<code class="ic">${escape_html(text)}</code>`,
	/** @param {{ text: string, lang?: string }} token */
	code: ({ text, lang }) => `<pre class="code"><code>${code_body(text, lang)}</code></pre>\n`
};

/**
 * The HTML inside a code block: Vader highlighted, anything else escaped.
 * @param {string} text
 * @param {string | undefined} lang
 */
export function code_body(text, lang) {
	if (lang === 'vader') return code_html(shown_code(text));
	return escape_html(text);
}
