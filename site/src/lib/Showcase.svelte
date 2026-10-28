<script>
	// The programs of the home page, one tab each: what the program shows, its
	// code, and what it prints.
	import Tabs from './Tabs.svelte';

	/** @typedef {{ label: string, caption: string, code: string, output: string }} Example */

	/** @type {{ examples: Example[] }} */
	let { examples } = $props();
</script>

<Tabs labels={examples.map((e) => e.label)} label="Examples">
	{#snippet panel(/** @type {number} */ i)}
		<div class="caption">{@html examples[i].caption}</div>
		<pre class="code program"><code>{@html examples[i].code}</code></pre>
		<pre class="output" aria-label="Output">{examples[i].output}</pre>
	{/snippet}
</Tabs>

<style>
	.caption {
		padding: var(--s3) var(--s4) 0;
		font-size: var(--step--1);
		color: var(--muted);
	}
	.caption :global(p) {
		margin: 0;
	}
	.program {
		margin: var(--s3) var(--s4);
		max-height: 26rem;
		overflow: auto;
	}
	.output {
		border-top: var(--hair) solid var(--line);
		white-space: pre-wrap;
	}
	.output::before {
		content: '$ vader run';
		display: block;
		color: var(--muted);
	}
</style>
