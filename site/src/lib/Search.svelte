<script>
	// A search over the titles of the specification: its chapters and headings,
	// fetched at the first use of the box.
	import { goto } from '$app/navigation';
	import { resolve } from '$app/paths';
	import { heading_href } from './links.js';

	const LIMIT = 10;

	/** @typedef {{ title: string, chapter: string, slug: string, id: string }} Entry */

	let query = $state('');
	let selected = $state(0);
	let open = $state(false);
	/** @type {Entry[] | null} */
	let entries = $state(null);
	let failed = $state(false);
	/** @type {HTMLInputElement | undefined} */
	let input = $state();
	let hits = $derived(search(entries ?? [], query));

	/**
	 * The entries whose title holds every word of `text`, those that start with
	 * it first.
	 * @param {Entry[]} all
	 * @param {string} text
	 */
	function search(all, text) {
		const words = text.toLowerCase().split(/\s+/).filter(Boolean);
		if (words.length === 0) return [];
		const found = all.filter((e) => words.every((w) => e.title.toLowerCase().includes(w)));
		const head = words.join(' ');
		const starts = found.filter((e) => e.title.toLowerCase().startsWith(head));
		const rest = found.filter((e) => !e.title.toLowerCase().startsWith(head));
		return [...starts, ...rest].slice(0, LIMIT);
	}

	async function load_index() {
		if (entries || failed) return;
		const response = await fetch(resolve('/search.json'));
		if (!response.ok) {
			failed = true;
			return;
		}
		entries = (await response.json()).entries;
	}

	/** @param {Entry} entry */
	function go(entry) {
		open = false;
		query = '';
		input?.blur();
		goto(heading_href(entry.slug, entry.id));
	}

	/** @param {KeyboardEvent} event */
	function on_key(event) {
		if (event.key === 'ArrowDown' && hits.length > 0) {
			selected = (selected + 1) % hits.length;
		} else if (event.key === 'ArrowUp' && hits.length > 0) {
			selected = (selected - 1 + hits.length) % hits.length;
		} else if (event.key === 'Enter' && hits[selected]) {
			go(hits[selected]);
		} else if (event.key === 'Escape') {
			open = false;
			return;
		} else {
			return;
		}
		event.preventDefault();
	}

	// The option the keyboard is on, none without any.
	function active_option() {
		if (hits.length === 0) return undefined;
		return `hit-${selected}`;
	}

	/** @param {Entry} entry */
	function where(entry) {
		if (entry.chapter === '') return 'Appendices';
		return `§${entry.chapter}`;
	}
</script>

<div class="search">
	<input
		bind:this={input}
		bind:value={query}
		type="search"
		placeholder="Search the specification"
		aria-label="Search the specification"
		role="combobox"
		aria-expanded={open && hits.length > 0}
		aria-controls="hits"
		aria-activedescendant={active_option()}
		onfocus={() => {
			open = true;
			load_index();
		}}
		oninput={() => {
			open = true;
			selected = 0;
		}}
		onblur={() => setTimeout(() => (open = false), 150)}
		onkeydown={on_key}
	/>
	{#if open && hits.length > 0}
		<ul id="hits" role="listbox">
			{#each hits as hit, i (hit.slug + hit.id)}
				<li id="hit-{i}" role="option" aria-selected={i === selected}>
					<button type="button" onmousedown={() => go(hit)}>
						<span class="label">{hit.title}</span>
						<span class="w">{where(hit)}</span>
					</button>
				</li>
			{/each}
		</ul>
	{/if}
</div>

<style>
	.search {
		position: relative;
		flex: 1;
		max-width: 26rem;
		min-width: 8rem;
	}
	input {
		width: 100%;
		font: inherit;
		font-size: var(--step--1);
		color: var(--fg);
		background: var(--sunken);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		padding: var(--s1) var(--s3);
	}
	ul {
		position: absolute;
		z-index: 6;
		top: calc(100% + var(--s1));
		left: 0;
		right: 0;
		margin: 0;
		padding: var(--s1);
		list-style: none;
		background: var(--surface);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		box-shadow: 0 18px 40px -24px rgba(0, 0, 0, 0.5);
	}
	button {
		display: flex;
		width: 100%;
		gap: var(--s3);
		justify-content: space-between;
		font: inherit;
		font-size: var(--step--1);
		text-align: left;
		color: var(--fg);
		background: none;
		border: 0;
		border-radius: var(--r1);
		padding: var(--s1) var(--s2);
		cursor: pointer;
	}
	li[aria-selected='true'] button,
	button:hover {
		background: var(--accent-wash);
		color: var(--accent-ink);
	}
	.w {
		color: var(--muted);
		white-space: nowrap;
	}
</style>
