// The lines of a Vader example that set it up without being shown: a lone `#`,
// or `# ` and code, past the indentation. vaderdoc's `@example` reads them the
// same way (`lib/toolchain/ast/vaderdoc.vader`). `tests/site_content.test.ts`
// imports this file to compile what the site shows: it imports nothing.

const HIDDEN = /^([ \t]*)#(?: |$)/;

/**
 * What a reader sees of `code`: its lines but the hidden ones, without the
 * indentation they share and the blank lines around them.
 * @param {string} code
 */
export function shown_code(code) {
	const shown = code.split('\n').filter((line) => !HIDDEN.test(line));
	const filled = shown.filter((line) => line.trim() !== '');
	const indent = Math.min(...filled.map((line) => line.length - line.trimStart().length));
	return shown
		.map((line) => line.slice(indent))
		.join('\n')
		.replace(/^(?:[ \t]*\n)+/, '')
		.trimEnd();
}

/**
 * `code` as it is compiled: its hidden lines without their mark.
 * @param {string} code
 */
export const compiled_code = (code) =>
	code
		.split('\n')
		.map((line) => line.replace(HIDDEN, '$1'))
		.join('\n');
