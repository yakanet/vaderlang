<script>
	// A search over the headings of the site: its pages, its examples and the
	// chapters of the specification, fetched at the first use. Cmd+K (Ctrl+K off
	// macOS) opens it from anywhere, as the button in the header does.
	import { onMount } from 'svelte';
	import { goto } from '$app/navigation';
	import { resolve } from '$app/paths';
	import { client_platform } from './platform.js';

	const LIMIT = 12;

	/** @typedef {{ title: string, where: string, href: string }} Entry */

	let query = $state('');
	let selected = $state(0);
	/** @type {Entry[] | null} */
	let entries = $state(null);
	let failed = $state(false);
	/** @type {HTMLDialogElement | undefined} */
	let dialog = $state();
	/** @type {HTMLInputElement | undefined} */
	let input = $state();
	// The shortcut as the visitor's keyboard writes it, once the browser says which.
	let shortcut = $state('');
	let hits = $derived(search(entries ?? [], query));

	onMount(() => {
		shortcut = shortcut_of(client_platform());
	});

	/** @param {string} platform */
	function shortcut_of(platform) {
		if (platform === 'darwin-arm64') return '\u2318K';
		return 'Ctrl K';
	}

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

	function open() {
		if (!dialog || dialog.open) return;
		dialog.showModal();
		input?.focus();
		load_index();
	}

	function close() {
		dialog?.close();
	}

	/** @param {KeyboardEvent} event */
	function on_window_key(event) {
		if (event.key.toLowerCase() !== 'k' || !(event.metaKey || event.ctrlKey)) return;
		event.preventDefault();
		if (dialog?.open) close();
		else open();
	}

	/** @param {Entry} entry */
	function go(entry) {
		close();
		goto(entry.href);
	}

	/** @param {KeyboardEvent} event */
	function on_key(event) {
		if (event.key === 'ArrowDown' && hits.length > 0) {
			selected = (selected + 1) % hits.length;
		} else if (event.key === 'ArrowUp' && hits.length > 0) {
			selected = (selected - 1 + hits.length) % hits.length;
		} else if (event.key === 'Enter' && hits[selected]) {
			go(hits[selected]);
		} else {
			return;
		}
		event.preventDefault();
	}

	// A click on the backdrop, outside the panel, closes the search.
	/** @param {MouseEvent} event */
	function on_dialog_click(event) {
		if (event.target === dialog) close();
	}

	// The option the keyboard is on, none without any.
	function active_option() {
		if (hits.length === 0) return undefined;
		return `hit-${selected}`;
	}
</script>

<svelte:window onkeydown={on_window_key} />

<button class="trigger" type="button" onclick={open} aria-keyshortcuts="Meta+K Control+K">
	<span>Search</span>
	{#if shortcut}<kbd>{shortcut}</kbd>{/if}
</button>

<!-- svelte-ignore a11y_click_events_have_key_events, a11y_no_noninteractive_element_interactions -->
<dialog bind:this={dialog} aria-label="Search" onclick={on_dialog_click} onclose={() => (query = '')}>
	<div class="panel">
		<input
			bind:this={input}
			bind:value={query}
			type="search"
			placeholder="Search the site"
			aria-label="Search the site"
			role="combobox"
			aria-expanded={hits.length > 0}
			aria-controls="hits"
			aria-activedescendant={active_option()}
			oninput={() => (selected = 0)}
			onkeydown={on_key}
		/>
		{#if hits.length > 0}
			<ul id="hits" role="listbox">
				{#each hits as hit, i (hit.href)}
					<li id="hit-{i}" role="option" aria-selected={i === selected}>
						<button type="button" onclick={() => go(hit)} onmouseenter={() => (selected = i)}>
							<span class="label">{hit.title}</span>
							<span class="where">{hit.where}</span>
						</button>
					</li>
				{/each}
			</ul>
		{:else if query.trim() !== '' && entries}
			<p class="empty">No heading matches.</p>
		{:else if failed}
			<p class="empty">The search index could not be read.</p>
		{/if}
	</div>
</dialog>

<style>
	.trigger {
		display: flex;
		align-items: center;
		justify-content: space-between;
		gap: var(--s4);
		flex: 1;
		max-width: 22rem;
		min-width: 7rem;
		font: inherit;
		font-size: var(--step--1);
		color: var(--muted);
		background: var(--bg);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		padding: var(--s2) var(--s3);
		cursor: pointer;
	}
	.trigger:hover {
		border-color: var(--accent);
	}
	kbd {
		font-family: var(--font-code);
		font-size: 0.75rem;
		padding: 0 var(--s1);
		border: var(--hair) solid var(--line);
		border-radius: var(--r1);
		background: var(--surface);
	}
	dialog {
		width: min(40rem, calc(100vw - 2rem));
		margin: 12vh auto auto;
		padding: 0;
		color: var(--fg);
		background: var(--surface);
		border: var(--hair) solid var(--line);
		border-radius: 10px;
		box-shadow: 0 24px 60px -24px rgba(0, 0, 0, 0.6);
	}
	dialog::backdrop {
		background: rgba(0, 0, 0, 0.45);
	}
	.panel {
		padding: var(--s3);
	}
	input {
		width: 100%;
		font: inherit;
		color: var(--fg);
		background: var(--sunken);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		padding: var(--s2) var(--s3);
	}
	ul {
		margin: var(--s2) 0 0;
		padding: 0;
		list-style: none;
		max-height: 60vh;
		overflow-y: auto;
	}
	li button {
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
		padding: var(--s2) var(--s3);
		cursor: pointer;
	}
	li[aria-selected='true'] button {
		background: var(--accent-wash);
		color: var(--accent-ink);
	}
	.where {
		color: var(--muted);
		white-space: nowrap;
	}
	.empty {
		margin: var(--s3) var(--s2) var(--s1);
		color: var(--muted);
		font-size: var(--step--1);
	}
</style>
