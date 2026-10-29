// The tour of the language: `learn.md` says what it is, and each file of
// `site/content/learn/`, `<n>-<name>.md`, is a chapter, in the order of `n`. A
// chapter's `##` sections each show one construct by a program; its title is
// its `#` heading.

import fs from 'node:fs';
import path from 'node:path';
import { learn_href } from '../links.js';
import { chapter_set } from './chapters.js';
import { content_page } from './content.js';
import { REPO } from './repo.js';

const LEARN = path.join(REPO, 'site', 'content', 'learn');
const FILE = /^((\d+)-[a-z0-9-]+)\.md$/;

function read_chapters() {
	const files = fs.readdirSync(LEARN).filter((f) => f.endsWith('.md'));
	const named = files.map((file) => ({ file, match: FILE.exec(file) }));
	const misnamed = named.filter((n) => !n.match).map((n) => n.file);
	if (misnamed.length > 0) throw new Error(`learn/: name a chapter <n>-<name>.md, not ${misnamed.join(', ')}`);
	return named
		.map(({ file, match }) => {
			const [, slug, number] = /** @type {RegExpExecArray} */ (match);
			const page = content_page(path.join('learn', file));
			return { number, title: page.title, slug, html: page.html, headings: page.outline, outline: page.outline };
		})
		.sort((a, b) => Number(a.number) - Number(b.number));
}

/** The chapters of the tour, as its pages and the search show them. */
export const learn_chapters = chapter_set(read_chapters(), learn_href, (c) => `Learn ${c.number}`);

/** What the tour says of itself, above the list of its chapters. */
export const learn_introduction = content_page('learn.md');
