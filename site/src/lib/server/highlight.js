// Vader code to HTML, coloured by the grammar the editors use
// (`editors/common/vader.tmLanguage.json`).
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
import { REPO } from './repo.js';

const grammar_path = path.join(REPO, 'editors', 'common', 'vader.tmLanguage.json');
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
	name: 'vader-site',
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
 * `code` as HTML, each run of one class in a span.
 * @param {string} code
 */
export function code_html(code) {
	const lines = highlighter.codeToTokensBase(code, {
		lang: /** @type {any} */ ('vader'),
		theme: /** @type {any} */ ('vader-site')
	});
	return lines
		.map((line) =>
			line
				.map((token) => {
					const cls = CLASS_OF_KEY.get(token.color?.toLowerCase() ?? '') ?? '';
					const html = escape_html(token.content);
					if (cls === '') return html;
					return `<span class="${cls}">${html}</span>`;
				})
				.join('')
		)
		.join('\n');
}
