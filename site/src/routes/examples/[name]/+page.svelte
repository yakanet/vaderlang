<script>
	import { GITHUB, page_href } from '#lib/links.js';
	import Tabs from '#lib/Tabs.svelte';

	let { data } = $props();

	let views = $derived(views_of(data.output));

	// The source first; the output beside it, for an example that prints one.
	/** @param {string} output */
	function views_of(output) {
		if (output === '') return ['Source'];
		return ['Source', 'Output'];
	}
</script>

<svelte:head>
	<title>{data.name} &middot; Vader examples</title>
</svelte:head>

<main class="page">
	<p class="back"><a href={page_href('examples')}>&larr; Examples</a></p>
	<h1>{data.name}</h1>
	<div class="caption">{@html data.caption}</div>
	<p class="where">
		<a href="{GITHUB}/tree/main/examples/{data.name}">examples/{data.name}</a> in the repository.
	</p>
	<div class="views">
		<Tabs labels={views} label="Example">
			{#snippet panel(/** @type {number} */ i)}
				{#if i === 0}
					<pre class="code"><code>{@html data.code}</code></pre>
				{:else}
					<pre class="output">{data.output}</pre>
				{/if}
			{/snippet}
		</Tabs>
	</div>
</main>

<style>
	.page {
		padding-top: var(--s5);
	}
	.back {
		margin: 0 0 var(--s3);
		font-size: var(--step--1);
	}
	h1 {
		font-family: var(--font-code);
	}
	.caption :global(p) {
		margin: 0 0 var(--s3);
		font-size: var(--step-1);
	}
	.where {
		color: var(--muted);
		font-size: var(--step--1);
	}
	.views {
		margin-top: var(--s5);
	}
	.code {
		border: 0;
		border-radius: 0;
	}
</style>
