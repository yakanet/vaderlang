// The page of one module, as the data gives it: its declarations grouped by
// kind, the overloads of a name under one title, the impls of a type under it.
// Every piece of code and prose is HTML here, at build time: the page itself
// only places it.

import path from 'node:path';
import { anchor_of, entry_href, overloads_anchor } from '#lib/anchors.js';
import { code_html, code_lines_html } from './highlight.js';
import { block_html, inline_html } from './markdown.js';
import { index, module_paths, source_url } from './data.js';

/**
 * @typedef {import('./data.js').Segment} Segment
 * @typedef {import('./highlight.js').Link} Link
 */

// The kinds of each group, in the order the page shows them.
const GROUPS = [
	['Types', ['struct', 'enum', 'trait', 'type']],
	['Functions', ['fn']],
	['Constants', ['const']]
];

// What the members of a declaration are called on its page.
const MEMBER_TITLES = new Map([
	['struct', 'Fields'],
	['enum', 'Variants'],
	['trait', 'Methods'],
	['impl', 'Methods']
]);

/**
 * The text of `segments` and a link over each name a reader can follow into
 * this site.
 * @param {Segment[]} segments
 * @returns {{ text: string, links: Link[] }}
 */
function linked(segments) {
	let text = '';
	/** @type {Link[]} */
	const links = [];
	for (const s of segments) {
		const start = text.length;
		text += s.text;
		if (s.module && s.name && module_paths.has(s.module)) {
			const href = entry_href(s.module, s.name);
			links.push({ start, end: text.length, href, title: `${s.module}.${s.name}` });
		}
	}
	return { text, links };
}

/** @param {Segment[]} segments */
function segments_html(segments) {
	const { text, links } = linked(segments);
	return code_html(text, links);
}

/**
 * `segments` without the `export` they open with.
 * @param {Segment[]} segments
 */
function without_export(segments) {
	const [first, ...rest] = segments;
	if (!first?.text.startsWith('export ')) return segments;
	return [{ text: first.text.slice('export '.length) }, ...rest];
}

/**
 * The head of a constant, `segments`, with the type typing gave it written
 * before its ` :: `.
 * @param {Segment[]} segments
 * @param {Segment[]} type
 */
function with_type(segments, type) {
	const at = segments.findIndex((s) => !s.module && s.text.includes(' :: '));
	if (at < 0 || type.length === 0) return segments;
	const text = segments[at].text;
	const cut = text.indexOf(' :: ');
	return [
		...segments.slice(0, at),
		{ text: `${text.slice(0, cut)}: ` },
		...type,
		{ text: text.slice(cut) },
		...segments.slice(at + 1)
	];
}

/**
 * The last `length` characters of `segments`, a segment cut in two keeping its
 * end as text: an impl's head ends with the trait it implements.
 * @param {Segment[]} segments
 * @param {number} length
 */
function tail_of(segments, length) {
	/** @type {Segment[]} */
	const out = [];
	let left = length;
	for (let i = segments.length - 1; i >= 0 && left > 0; i--) {
		const s = segments[i];
		if (s.text.length <= left) {
			out.unshift(s);
			left -= s.text.length;
		} else {
			out.unshift({ text: s.text.slice(s.text.length - left) });
			left = 0;
		}
	}
	return out;
}

/**
 * Where `decl` is declared: its file and line, a link when the site knows
 * where its sources are read online.
 * @param {{ file: string, line: number }} decl
 */
function source_of(decl) {
	const label = `${path.posix.basename(decl.file)}:${decl.line}`;
	if (!source_url || path.isAbsolute(decl.file)) {
		return { label, title: decl.file, href: '' };
	}
	return { label, title: decl.file, href: `${source_url}${decl.file}#L${decl.line}` };
}

/**
 * The line `html` of an example, greyed when it sets the example up.
 * @param {string} html
 * @param {boolean} hidden
 */
function greyed(html, hidden) {
	if (!hidden) return html;
	return `<span class="hid">${html}</span>`;
}

/**
 * The example of `doc`: its shown lines, and the whole of it when it has
 * lines that set it up; null without one.
 * @param {any} doc
 */
function example_of(doc) {
	/** @type {{ text: string, hidden?: boolean }[]} */
	const lines = doc?.example ?? [];
	if (lines.length === 0) return null;
	const shown = lines.filter((l) => !l.hidden);
	const short_html = code_html(shown.map((l) => l.text).join('\n'));
	if (shown.length === lines.length) return { short_html, full_html: '' };
	const full = code_lines_html(lines.map((l) => l.text).join('\n'));
	return { short_html, full_html: full.map((html, i) => greyed(html, Boolean(lines[i].hidden))).join('\n') };
}

/**
 * The name of the parameter `p` as its head writes it.
 * @param {{ name: string, variadic?: boolean }} p
 */
function parameter_name(p) {
	if (p.variadic) return `...${p.name}`;
	return p.name;
}

/**
 * The parameters of `fn` with what its vaderdoc says of each; none for another
 * declaration.
 * @param {any} fn
 * @param {any} doc
 */
function parameters_of(fn, doc) {
	/** @type {Map<string, string>} */
	const said = new Map((doc?.params ?? []).map((/** @type {any} */ p) => [p.name, p.text]));
	return (fn?.parameters ?? []).map((/** @type {any} */ p) => ({
		name: parameter_name(p),
		type_html: segments_html(p.type),
		default_html: segments_html(p.default ?? []),
		text_html: inline_html(said.get(p.name))
	}));
}

/**
 * What `fn` returns, with what its vaderdoc says; null for nothing a reader
 * would be told, and for another declaration.
 * @param {any} fn
 * @param {any} doc
 */
function returns_of(fn, doc) {
	if (!fn) return null;
	const type = fn.return_type.map((/** @type {Segment} */ s) => s.text).join('');
	if (type === '' || type === 'void') return null;
	return {
		type_html: segments_html(fn.return_type),
		text_html: inline_html((doc?.returns ?? []).join(' '))
	};
}

/**
 * A member: its anchor, its head and its vaderdoc.
 * @param {string} module
 * @param {any} member
 */
const member_view = (module, member) => ({
	anchor: anchor_of(module, member.id),
	signature_html: segments_html(member.signature),
	doc_html: block_html(member.doc?.prose)
});

/**
 * What every declaration's view starts with: its title and its place.
 * @param {string} module
 * @param {any} decl
 * @param {{ entry: any, decl: any }[]} impls  the impls for it
 */
function head_view(module, decl, impls) {
	return {
		anchor: overloads_anchor(anchor_of(module, decl.id)),
		name: decl.name,
		kind: decl.kind,
		inferred: Boolean(decl.inferred_type?.length || decl.function?.return_inferred),
		targets: decl.targets,
		source: source_of(decl),
		impls: impls.map((impl) => impl_view(module, impl))
	};
}

// The parts of a view an overloaded name leaves empty.
const NO_DETAIL = {
	overloads: [],
	prose_html: '',
	parameters: [],
	returns: null,
	errors_html: [],
	example: null,
	generated: false,
	members_title: '',
	members: []
};

/**
 * The overloads of one name: their signatures, each under its anchor, and the
 * summary of each.
 * @param {string} module
 * @param {any[]} group
 * @param {{ entry: any, decl: any }[]} impls
 */
const overloaded_view = (module, group, impls) => ({
	...head_view(module, group[0], impls),
	...NO_DETAIL,
	signatures: group.map((d) => ({ anchor: anchor_of(module, d.id), html: signature_html(d) })),
	overloads: group.map((d) => ({
		anchor: anchor_of(module, d.id),
		summary_html: inline_html(d.doc?.summary)
	}))
});

/**
 * One declaration with its vaderdoc, its parameters and return, its members.
 * @param {string} module
 * @param {any} decl
 * @param {{ entry: any, decl: any }[]} impls
 */
function decl_view(module, decl, impls) {
	const doc = decl.doc;
	const fn = decl.function;
	return {
		...head_view(module, decl, impls),
		signatures: [{ anchor: '', html: signature_html(decl) }],
		overloads: [],
		prose_html: block_html(doc?.prose),
		parameters: parameters_of(fn, doc),
		returns: returns_of(fn, doc),
		errors_html: (doc?.errors ?? []).map(inline_html),
		example: example_of(doc),
		generated: Boolean(fn) && !doc,
		members_title: MEMBER_TITLES.get(decl.kind) ?? 'Members',
		members: decl.members.map((/** @type {any} */ m) => member_view(module, m))
	};
}

/**
 * The signature of `decl` as the page shows it: without `export`, and a
 * constant with the type typing gave it written in.
 * @param {any} decl
 */
const signature_html = (decl) =>
	segments_html(with_type(without_export(decl.signature), decl.inferred_type ?? []));

/**
 * An impl under the type it is for: its trait, and its methods when this module
 * declares it; a link to it otherwise.
 * @param {string} module
 * @param {{ entry: any, decl: any }} impl
 */
function impl_view(module, { entry, decl }) {
	const trait = entry.name.slice(entry.name.indexOf(': ') + 2);
	if (!decl) {
		return {
			anchor: '',
			trait,
			href: entry_href(entry.module, anchor_of(entry.module, entry.id)),
			module: entry.module,
			signature_html: '',
			members: []
		};
	}
	return {
		anchor: anchor_of(module, decl.id),
		trait,
		href: '',
		module: '',
		signature_html: segments_html(tail_of(decl.signature, decl.trait.length)),
		members: decl.members.map((/** @type {any} */ m) => member_view(module, m))
	};
}

/**
 * An impl no type of this module owns: for `T[]`, or for a type declared
 * elsewhere. Its head is its title.
 * @param {string} module
 * @param {any} decl
 */
const loose_impl_view = (module, decl) => ({
	...decl_view(module, decl, []),
	name: decl.signature.map((/** @type {Segment} */ s) => s.text).join(''),
	signatures: []
});

/**
 * The page of the module `data` holds.
 * @param {any} data
 */
export function module_page(data) {
	const module = data.path;
	/** @type {any[]} */
	const decls = data.decls;
	const declared = new Map(decls.map((d) => [d.id, d]));
	const impls = index.entries
		.filter((e) => e.kind === 'impl' && declared.has(e.owner))
		.map((entry) => ({ entry, decl: declared.get(entry.id) ?? null }));
	const impls_for = Map.groupBy(impls, (impl) => impl.entry.owner);
	const attached = new Set(impls.map((impl) => impl.entry.id));
	const by_name = Map.groupBy(
		decls.filter((d) => d.kind !== 'impl'),
		(d) => d.name
	);
	const groups = [];
	for (const [title, kinds] of GROUPS) {
		const items = [...by_name.values()]
			.filter((group) => kinds.includes(group[0].kind))
			.map((group) => group_view(module, group, impls_for.get(group[0].id) ?? []));
		if (items.length > 0) groups.push({ title, items });
	}
	const loose = decls
		.filter((d) => d.kind === 'impl' && !attached.has(d.id))
		.map((d) => loose_impl_view(module, d));
	if (loose.length > 0) groups.push({ title: 'Implementations', items: loose });
	return {
		path: module,
		summary_html: inline_html(capitalized(data.summary)),
		header_html: block_html(header_body(data.header)),
		files: data.files,
		export_count: decls.filter((d) => d.kind !== 'impl').length,
		groups
	};
}

/**
 * The view of the declarations that share a name: one, or its overloads.
 * @param {string} module
 * @param {any[]} group
 * @param {{ entry: any, decl: any }[]} impls
 */
function group_view(module, group, impls) {
	if (group.length > 1) return overloaded_view(module, group, impls);
	return decl_view(module, group[0], impls);
}

// The header of a module without the `path: summary` line it opens with,
// which the page shows as its title and lede.
/** @param {string} header */
const header_body = (header) => header.split('\n\n').slice(1).join('\n\n');

/** @param {string} text */
const capitalized = (text) => text.charAt(0).toUpperCase() + text.slice(1);
