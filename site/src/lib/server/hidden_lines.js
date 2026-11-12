// The lines of a Vader example that set it up without being shown: a lone `#`,
// or `# ` and code, past the indentation. vaderdoc's `@example` reads them the
// same way (`compiled_example_line` in `lib/toolchain/ast/vaderdoc.vader`), and
// `tools/cli_tests/site` compiles what the site shows by it.

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
