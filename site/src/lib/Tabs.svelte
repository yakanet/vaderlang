<script>
	// Panels behind a row of tabs, in one frame, one visible at a time. Only the
	// selected tab is in the tab order; the arrow keys move between them.

	/**
	 * @type {{
	 *   labels: string[],
	 *   label: string,
	 *   selected?: number,
	 *   panel: import('svelte').Snippet<[number]>
	 * }}
	 */
	let { labels, label, selected = $bindable(0), panel } = $props();

	const id = $props.id();

	/** @param {number} i */
	function tab_index(i) {
		if (i === selected) return 0;
		return -1;
	}

	/** @param {KeyboardEvent} event */
	function on_key(event) {
		let next = selected;
		if (event.key === 'ArrowRight') next = (selected + 1) % labels.length;
		if (event.key === 'ArrowLeft') next = (selected - 1 + labels.length) % labels.length;
		if (next === selected) return;
		event.preventDefault();
		selected = next;
		document.getElementById(`${id}-tab-${next}`)?.focus();
	}
</script>

<div class="tabbed">
	<div class="tabs" role="tablist" aria-label={label} tabindex="-1" onkeydown={on_key}>
		{#each labels as text, i (text)}
			<button
				id="{id}-tab-{i}"
				type="button"
				role="tab"
				aria-selected={i === selected}
				aria-controls="{id}-panel-{i}"
				tabindex={tab_index(i)}
				onclick={() => (selected = i)}>{text}</button
			>
		{/each}
	</div>
	{#each labels as text, i (text)}
		<div id="{id}-panel-{i}" role="tabpanel" aria-labelledby="{id}-tab-{i}" hidden={i !== selected}>
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
		font: inherit;
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
