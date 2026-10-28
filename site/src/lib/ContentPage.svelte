<script>
	// A page of the site written in Markdown: its title, what it says, and the
	// list of its sections when it has several.
	import Outline from './Outline.svelte';

	/** @type {{ title: string, html: string, outline: { id: string, title: string }[] }} */
	let { title, html, outline } = $props();
</script>

<svelte:head>
	<title>{title} &middot; Vader</title>
</svelte:head>

<main class="page">
	<article class="doc">
		<h1>{title}</h1>
		{#if outline.length > 2}
			<Outline headings={outline} />
		{/if}
		{@html html}
	</article>
</main>

<style>
	.page {
		--page-w: 48rem;
	}
</style>
