// The pages of the site other than the specification, written in Markdown under
// `site/content/`, and the examples of the repository.
//
// A link to a page of the site is written from its root (`/download/`) and takes
// the base path the site is served under. One to an API reference carries
// `rel="external"`, which the prerenderer does not follow; one to another page
// is followed, and the build fails on a page that does not exist.
//
// Every Vader block of the content runs in `tests/site_content.test.ts`, and the
// `text` block right after one is what it prints.

import fs from 'node:fs';
import path from 'node:path';
import { Marked } from 'marked';
import { API_SITES, page_href, site_href } from '../links.js';
import { escape_html } from './highlight.js';
import { assign_heading_ids, code_body, code_renderers, heading_html, heading_id, plain } from './markdown.js';
import { REPO } from './repo.js';

/** @typedef {import('marked').Token} Token */
/** @typedef {import('marked').Tokens.Heading} Heading */

const CONTENT = path.join(REPO, 'site', 'content');
const EXAMPLES = path.join(REPO, 'examples');
const EXAMPLE_OUTPUTS = path.join(REPO, 'tests', 'fixtures', 'examples');

/** The pages written in Markdown, `start` for `start.md`, served at the root. */
export const MARKDOWN_PAGES = ['start'];

/** @param {string} href */
function link_html_attributes(href) {
	if (!href.startsWith('/')) return `href="${escape_html(href)}"`;
	const attributes = `href="${escape_html(site_href(href))}"`;
	if (API_SITES.some((site) => href.startsWith(`/${site}/`))) return `${attributes} rel="external"`;
	return attributes;
}

const markdown = new Marked({
	renderer: {
		heading(token) {
			return heading_html(this.parser.parseInline(token.tokens), token.depth, heading_id(token));
		},
		link(token) {
			return `<a ${link_html_attributes(token.href)}>${this.parser.parseInline(token.tokens)}</a>`;
		},
		...code_renderers
	}
});

/** @param {string} name  a file under `site/content/`. */
const tokens_of = (name) => markdown.lexer(fs.readFileSync(path.join(CONTENT, name), 'utf8'));

/** @param {Token[]} tokens */
const html_of = (tokens) => /** @type {string} */ (markdown.parser(tokens));

/**
 * `token` as a heading at `depth`, null when it is not one.
 * @param {Token} token
 * @param {number} depth
 */
function heading_at(token, depth) {
	if (token.type !== 'heading') return null;
	const heading = /** @type {Heading} */ (token);
	if (heading.depth !== depth) return null;
	return heading;
}

/**
 * The first heading at `depth` among `tokens`.
 * @param {Token[]} tokens
 * @param {number} depth
 */
const first_heading = (tokens, depth) => tokens.map((t) => heading_at(t, depth)).find((h) => h !== null);

/**
 * A page: the title its `#` heading gives, and the rest of it, with the `##`
 * headings an outline lists.
 * @param {string} name
 */
export function content_page(name) {
	const tokens = tokens_of(name);
	const headings = assign_heading_ids(tokens);
	const title = first_heading(tokens, 1);
	return {
		title: plain(title?.text ?? ''),
		html: html_of(tokens.filter((t) => t !== title)),
		outline: headings.filter((h) => h.depth === 2)
	};
}

/**
 * A file read as a list of parts, one per `##` heading: its id, its title, and
 * what follows it.
 * @param {string} name
 */
export function content_sections(name) {
	const tokens = tokens_of(name);
	assign_heading_ids(tokens);
	/** @type {{ id: string, title: string, tokens: Token[] }[]} */
	const sections = [];
	for (const token of tokens) {
		const start = heading_at(token, 2);
		if (start) sections.push({ id: heading_id(start), title: plain(start.text), tokens: [] });
		else sections.at(-1)?.tokens.push(token);
	}
	return sections.map((s) => ({ id: s.id, title: s.title, html: html_of(s.tokens) }));
}

/**
 * The file `name` with the `##` sections whose ids `apart` lists taken out: what
 * each of those says, without its heading, and the rest rendered whole.
 * @param {string} name
 * @param {string[]} apart
 */
export function content_parts(name, apart) {
	const tokens = tokens_of(name);
	assign_heading_ids(tokens);
	/** @type {Map<string, Token[]>} */
	const parts = new Map();
	/** @type {Token[]} */
	const rest = [];
	let current = rest;
	for (const token of tokens) {
		const start = heading_at(token, 2);
		if (start && apart.includes(heading_id(start))) {
			current = [];
			parts.set(heading_id(start), current);
			continue;
		}
		if (start) current = rest;
		current.push(token);
	}
	return {
		parts: new Map([...parts].map(([id, part]) => [id, html_of(part)])),
		rest: html_of(rest)
	};
}

/**
 * A file rendered whole.
 * @param {string} name
 */
export const content_html = (name) => html_of(tokens_of(name));

/**
 * The examples of the home page, one file each under `showcase/`, in the order
 * of their names: its `#` heading names the tab, a paragraph says what it
 * shows, then the program, and right after it what it prints.
 */
export function showcase() {
	const files = fs.readdirSync(path.join(CONTENT, 'showcase')).filter((f) => f.endsWith('.md')).sort();
	return files.map((file) => {
		const tokens = tokens_of(path.join('showcase', file)).filter((t) => t.type !== 'space');
		const heading = first_heading(tokens, 1);
		const at = tokens.findIndex((t) => t.type === 'code' && t.lang === 'vader');
		const program = /** @type {import('marked').Tokens.Code | undefined} */ (tokens[at]);
		const output = /** @type {import('marked').Tokens.Code | undefined} */ (tokens[at + 1]);
		if (!heading || !program || output?.type !== 'code' || output.lang !== 'text') {
			throw new Error(`showcase/${file}: a heading, then a vader block and its text block`);
		}
		return {
			label: plain(heading.text),
			caption: html_of(tokens.filter((t) => t.type === 'paragraph')),
			code: code_body(program.text, 'vader'),
			output: output.text
		};
	});
}

/**
 * What the example `name` printed when the test suite last ran it, from the
 * snapshot `formatRun` (`tests/snapshot.ts`) writes; "" for one that prints
 * nothing there or that the suite does not run (it opens a window).
 * @param {string} name
 */
function example_output(name) {
	const file = path.join(EXAMPLE_OUTPUTS, `${name}.run.snapshot`);
	if (!fs.existsSync(file)) return '';
	const stdout = /^# stdout\n([\s\S]*?)^# (?:stderr|exit)$/m.exec(fs.readFileSync(file, 'utf8'));
	return stdout?.[1] ?? '';
}

/**
 * The examples of the repository, in the order `examples.md` gives them, which
 * must name every folder of `examples/`.
 */
function read_examples() {
	const captions = content_sections('examples.md');
	const folders = fs.readdirSync(EXAMPLES, { withFileTypes: true }).filter((e) => e.isDirectory());
	const missing = folders.filter((f) => !captions.some((c) => c.title === f.name)).map((f) => f.name);
	if (missing.length > 0) throw new Error(`examples.md says nothing of ${missing.join(', ')}`);
	return captions.map((section) => {
		const name = section.title;
		const source = path.join(EXAMPLES, name, `${name}.vader`);
		if (!fs.existsSync(source)) throw new Error(`examples.md names ${name}, which has no ${source}`);
		return {
			name,
			caption: section.html,
			code: code_body(fs.readFileSync(source, 'utf8'), 'vader'),
			output: example_output(name)
		};
	});
}

export const examples = read_examples();

/**
 * The page `page` and its `##` sections, as the search reads them; `file` is
 * the Markdown it is written in, if any.
 * @param {string} page
 * @param {string} title
 * @param {string} [file]
 */
function page_to_search(page, title, file) {
	const entry = { title, where: 'Page', href: page_href(page) };
	if (!file) return [entry];
	const sections = assign_heading_ids(tokens_of(file)).filter((h) => h.depth === 2);
	return [entry, ...sections.map((h) => ({ title: h.title, where: title, href: `${page_href(page)}#${h.id}` }))];
}

/** The pages written in Markdown and the examples, as the search reads them. */
export const content_search_entries = [
	...MARKDOWN_PAGES.flatMap((page) => page_to_search(page, content_page(`${page}.md`).title, `${page}.md`)),
	...page_to_search('download', 'Download', 'download.md'),
	...page_to_search('examples', 'Examples'),
	...examples.map((e) => ({ title: e.name, where: 'Example', href: page_href(`examples/${e.name}`) }))
];
