<script>
	import { goto } from '$app/navigation';
	import { resolve } from '$app/paths';
	import { entry_href } from './anchors.js';
	import { search } from './search.js';

	const LIMIT = 12;

	let query = $state('');
	let selected = $state(0);
	let open = $state(false);
	/** @type {import('./search.js').Entry[] | null} */
	let entries = $state(null);
	let failed = $state(false);
	/** @type {HTMLInputElement | undefined} */
	let input = $state();
	let hits = $derived(search(entries ?? [], query, LIMIT));

	// The index is fetched once, at the first use of the box.
	async function load_index() {
		if (entries || failed) return;
		const response = await fetch(resolve('/search-index.json'));
		if (!response.ok) {
			failed = true;
			return;
		}
		entries = (await response.json()).entries;
	}

	/** @param {import('./search.js').Hit} hit */
	function go(hit) {
		open = false;
		query = '';
		input?.blur();
		goto(entry_href(hit.entry.m, hit.entry.a));
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

	/** @param {KeyboardEvent} event */
	function on_page_key(event) {
		const target = /** @type {HTMLElement | null} */ (event.target);
		if (event.key !== '/' || target?.closest('input, textarea, [contenteditable]')) return;
		event.preventDefault();
		input?.focus();
	}

	/**
	 * `text` with the first place `q` is found in bold.
	 * @param {string} text
	 * @param {string} q
	 */
	function marked_parts(text, q) {
		const at = text.toLowerCase().indexOf(q.trim().toLowerCase());
		if (at < 0 || q.trim() === '') return [text, '', ''];
		const end = at + q.trim().length;
		return [text.slice(0, at), text.slice(at, end), text.slice(end)];
	}
</script>

<svelte:window onkeydown={on_page_key} />

<div class="search">
	<input
		bind:this={input}
		bind:value={query}
		type="search"
		placeholder="Search"
		aria-label="Search the reference"
		role="combobox"
		aria-expanded={open && query.trim() !== ''}
		aria-controls="search-results"
		aria-activedescendant={active_option()}
		autocomplete="off"
		spellcheck="false"
		onfocus={() => {
			open = true;
			load_index();
		}}
		oninput={() => {
			open = true;
			selected = 0;
			load_index();
		}}
		onkeydown={on_key}
		onblur={() => setTimeout(() => (open = false), 120)}
	/>
	<kbd aria-hidden="true">/</kbd>
	{#if open && query.trim() !== ''}
		<ul id="search-results" class="results" role="listbox">
			{#if failed}
				<li class="none">The search index could not be read.</li>
			{:else if entries === null}
				<li class="none">Reading the index...</li>
			{:else}
				{#each hits as hit, i (`${hit.entry.m}/${hit.base}`)}
					{@const [before, found, after] = marked_parts(hit.base, query)}
					<li
						id="hit-{i}"
						role="option"
						aria-selected={i === selected}
						onmousedown={(event) => {
							event.preventDefault();
							go(hit);
						}}
					>
						<span class="chip kind">{hit.entry.k}</span>
						<span class="q"
							>{hit.entry.m} · {before}<b>{found}</b>{after}{#if hit.count > 1}
								<small>({hit.count} overloads)</small>{/if}</span
						>
						<span class="sum">{hit.entry.s.replaceAll('`', '')}</span>
					</li>
				{:else}
					<li class="none">Nothing is named “{query.trim()}”.</li>
				{/each}
			{/if}
		</ul>
	{/if}
</div>

<style>
	.search {
		position: relative;
		flex: 1 1 18rem;
		max-width: 30rem;
		margin-left: auto;
		min-width: 0;
	}
	input {
		width: 100%;
		font: inherit;
		font-size: var(--step--1);
		color: var(--fg);
		background: var(--bg);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		padding: var(--s2) 2.4rem var(--s2) var(--s3);
	}
	input::placeholder {
		color: var(--muted);
	}
	kbd {
		position: absolute;
		right: var(--s2);
		top: 50%;
		transform: translateY(-50%);
		font-size: 0.75rem;
		color: var(--muted);
		border: var(--hair) solid var(--line);
		border-radius: var(--r1);
		padding: 0 5px;
		background: var(--surface);
	}
	.results {
		position: absolute;
		z-index: 6;
		left: 0;
		right: 0;
		top: calc(100% + 4px);
		max-height: 22rem;
		overflow: auto;
		background: var(--surface);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		box-shadow: 0 14px 30px -16px rgba(0, 0, 0, 0.45);
		margin: 0;
		padding: var(--s1);
		list-style: none;
	}
	li {
		display: grid;
		grid-template-columns: 4.2rem minmax(0, 1fr);
		gap: 0 var(--s2);
		padding: var(--s2);
		border-radius: var(--r1);
		cursor: pointer;
	}
	li[aria-selected='true'] {
		background: var(--accent-wash);
	}
	li > .chip {
		grid-row: span 2;
		align-self: start;
		justify-self: start;
	}
	.q {
		font-family: var(--font-code);
		font-size: var(--step--1);
		overflow-wrap: anywhere;
	}
	.q b {
		color: var(--accent-ink);
	}
	.sum {
		font-size: 0.8rem;
		color: var(--muted);
		overflow: hidden;
		text-overflow: ellipsis;
		white-space: nowrap;
	}
	.none {
		display: block;
		color: var(--muted);
		font-size: var(--step--1);
		cursor: default;
	}
	@media (max-width: 760px) {
		.search {
			flex-basis: 100%;
			max-width: none;
			order: 3;
		}
	}
</style>
