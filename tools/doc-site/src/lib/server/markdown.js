// Vaderdoc prose to HTML. It is CommonMark, but carries no HTML: a bare
// `Iterator<T>` in a sentence stays visible instead of being read as a tag. A
// fenced block without a language is Vader.

import { Marked } from 'marked';
import { code_html, escape_html } from './highlight.js';

const markdown = new Marked({
	renderer: {
		html: ({ text }) => escape_html(text),
		codespan: ({ text }) => `<code class="ic">${escape_html(text)}</code>`,
		code: ({ text, lang }) => {
			if (lang && lang !== 'vader') return false;
			return `<pre class="code"><code>${code_html(text)}</code></pre>`;
		}
	}
});

/** @param {string | undefined} text */
export function block_html(text) {
	if (!text) return '';
	return /** @type {string} */ (markdown.parse(text));
}

/** @param {string | undefined} text */
export function inline_html(text) {
	if (!text) return '';
	return /** @type {string} */ (markdown.parseInline(text));
}
