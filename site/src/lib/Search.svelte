<script>
	// A search over the headings of the site: its pages, its examples and the
	// chapters of the specification. `site.js` drives it: Cmd+K (Ctrl+K off macOS)
	// opens it from anywhere, as the button does, and it fills the list with
	// copies of the row below.
	import { resolve } from '$app/paths';
</script>

<button class="trigger" type="button" data-search-open aria-keyshortcuts="Meta+K Control+K">
	<span>Search</span>
	<kbd hidden data-shortcut="mac">&#x2318;K</kbd>
	<kbd hidden data-shortcut="other">Ctrl K</kbd>
</button>

<dialog data-search data-index={resolve('/search.json')} aria-label="Search">
	<div class="panel">
		<input
			type="search"
			placeholder="Search the site"
			aria-label="Search the site"
			role="combobox"
			aria-expanded="false"
			aria-controls="hits"
		/>
		<ul id="hits" role="listbox" hidden></ul>
		<template>
			<!-- The title goes before `.where`. -->
			<!-- svelte-ignore a11y_consider_explicit_label -->
			<li role="option" aria-selected="false"><a href="."><span class="where"></span></a></li>
		</template>
		<p class="empty" hidden data-note="no-match">No heading matches.</p>
		<p class="empty" hidden data-note="unreadable">The search index could not be read.</p>
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
	li a {
		display: flex;
		gap: var(--s3);
		justify-content: space-between;
		font-size: var(--step--1);
		color: var(--fg);
		text-decoration: none;
		border-radius: var(--r1);
		padding: var(--s2) var(--s3);
	}
	/* Set by `site.js`: the template's own `false` would leave it unused. */
	li:global([aria-selected='true']) a {
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
