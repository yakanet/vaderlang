<script>
	// Panels behind a row of tabs, in one frame, the first one open. `site.js`
	// switches them, and opens the one a `hashes` entry or a `platforms` entry
	// names.

	/**
	 * @type {{
	 *   labels: string[],
	 *   label: string,
	 *   hashes?: string[],
	 *   platforms?: string[],
	 *   panel: import('svelte').Snippet<[number]>
	 * }}
	 */
	let { labels, label, hashes = [], platforms = [], panel } = $props();

	const id = $props.id();

	/** @param {number} i */
	function tab_index(i) {
		if (i === 0) return 0;
		return -1;
	}
</script>

<div class="tabbed">
	<div class="tabs" role="tablist" aria-label={label}>
		{#each labels as text, i (text)}
			<button
				id="{id}-tab-{i}"
				type="button"
				role="tab"
				aria-selected={i === 0}
				aria-controls="{id}-panel-{i}"
				tabindex={tab_index(i)}
				data-hash={hashes[i]}
				data-platform={platforms[i]}>{text}</button
			>
		{/each}
	</div>
	{#each labels as text, i (text)}
		<div id="{id}-panel-{i}" role="tabpanel" aria-labelledby="{id}-tab-{i}" hidden={i !== 0}>
			{@render panel(i)}
		</div>
	{/each}
</div>

<style>
	.tabbed {
		min-width: 0;
		background: var(--surface);
		border: var(--hair) solid var(--line);
		border-radius: var(--r3);
		overflow: hidden;
	}
	.tabs {
		display: flex;
		overflow-x: auto;
		border-bottom: var(--hair) solid var(--line);
		background: var(--sunken);
	}
	button {
		font-size: var(--step--1);
		white-space: nowrap;
		color: var(--muted);
		background: none;
		border: 0;
		border-bottom: 2px solid transparent;
		padding: var(--s2) var(--s4);
		cursor: pointer;
	}
	button:hover {
		color: var(--fg);
	}
	button[aria-selected='true'] {
		color: var(--accent-ink);
		border-bottom-color: var(--accent);
		font-weight: 700;
	}
</style>
