// Vader code to HTML, coloured by the grammar the editors use
// (`editors/common/vader.tmLanguage.json`, named by `VADER_DOC_GRAMMAR`).
//
// Shiki tokenizes at build time with a theme whose colours are keys, not
// colours: each token takes the one-letter class its key stands for (`k`
// keyword, `t` type, `f` function, `s` string, `n` number or constant, `c`
// comment, `o` operator, `d` decorator), and the colours live in the site's
// stylesheet, light and dark. The theme's rules settle which scope wins, as in
// an editor.

import fs from 'node:fs';
import path from 'node:path';
import { createHighlighter } from 'shiki';

const grammar_path = path.resolve(
	process.env.VADER_DOC_GRAMMAR ?? '../../editors/common/vader.tmLanguage.json'
);
const grammar = JSON.parse(fs.readFileSync(grammar_path, 'utf8'));

// Each class, its key in the theme, and the scopes it colours.
const CLASSES = [
	{ cls: 'c', key: '#000001', scope: ['comment'] },
	{ cls: 's', key: '#000002', scope: ['string'] },
	{ cls: 'n', key: '#000003', scope: ['constant', 'variable.other.constant'] },
	{ cls: 'd', key: '#000004', scope: ['storage.modifier.decorator'] },
	{ cls: 'f', key: '#000005', scope: ['entity.name.function'] },
	{ cls: 't', key: '#000006', scope: ['entity.name.type', 'support.type'] },
	{ cls: 'o', key: '#000007', scope: ['keyword.operator', 'punctuation'] },
	{ cls: 'k', key: '#000008', scope: ['keyword', 'storage', 'variable.language'] }
];

const CLASS_OF_KEY = new Map(CLASSES.map((c) => [c.key, c.cls]));

/** @type {import('shiki').ThemeRegistration} */
const THEME = {
	name: 'vader-doc',
	type: 'light',
	fg: '#000000',
	bg: '#ffffff',
	settings: CLASSES.map((c) => ({ scope: c.scope, settings: { foreground: c.key } }))
};

const highlighter = await createHighlighter({
	themes: [THEME],
	langs: [{ ...grammar, name: 'vader' }]
});

/** @param {string} text */
export const escape_html = (text) =>
	text.replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('>', '&gt;').replaceAll('"', '&quot;');

/**
 * The class of each UTF-16 unit of `code`, "" for a line break and for text no
 * scope colours.
 * @param {string} code
 */
function classes_of(code) {
	const classes = new Array(code.length).fill('');
	const lines = highlighter.codeToTokensBase(code, {
		lang: /** @type {any} */ ('vader'),
		theme: /** @type {any} */ ('vader-doc')
	});
	for (const line of lines) {
		for (const token of line) {
			const cls = CLASS_OF_KEY.get(token.color?.toLowerCase() ?? '') ?? '';
			classes.fill(cls, token.offset, token.offset + token.content.length);
		}
	}
	return classes;
}

/**
 * @typedef {{ start: number, end: number, href: string, title: string }} Link
 */

/**
 * `code` as HTML: each run of one class in a span, each of `links` an anchor
 * over its range, which the colours run through.
 * @param {string} code
 * @param {Link[]} [links]
 */
export function code_html(code, links = []) {
	const classes = classes_of(code);
	const link_at = new Array(code.length).fill(-1);
	links.forEach((link, i) => link_at.fill(i, link.start, link.end));
	let html = '';
	let open = -1;
	for (let i = 0; i < code.length; ) {
		let j = i + 1;
		while (j < code.length && classes[j] === classes[i] && link_at[j] === link_at[i]) j++;
		if (link_at[i] !== open) {
			if (open >= 0) html += '</a>';
			if (link_at[i] >= 0) {
				const link = links[link_at[i]];
				html += `<a class="ref" href="${escape_html(link.href)}" title="${escape_html(link.title)}">`;
			}
			open = link_at[i];
		}
		html += span_of(classes[i], escape_html(code.slice(i, j)));
		i = j;
	}
	if (open >= 0) html += '</a>';
	return html;
}

/**
 * `html` in a span of the class `cls`, as it is without one.
 * @param {string} cls
 * @param {string} html
 */
function span_of(cls, html) {
	if (cls === '') return html;
	return `<span class="${cls}">${html}</span>`;
}

/**
 * `code` as HTML, one string per line: no span runs across a line break.
 * @param {string} code
 */
export const code_lines_html = (code) => code_html(code).split('\n');
