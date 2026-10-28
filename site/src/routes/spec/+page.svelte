<script>
	import { chapter_href, chapter_label } from '#lib/links.js';

	let { data } = $props();
</script>

<svelte:head>
	<title>Vader specification</title>
</svelte:head>

<main class="spec-home">
	<article class="doc">
		<h1>Vader Language Specification</h1>
		{@html data.introduction}
		<ol class="toc">
			{#each data.chapters as chapter (chapter.slug)}
				<li><a href={chapter_href(chapter.slug)}>{chapter_label(chapter)}</a></li>
			{/each}
		</ol>
	</article>
</main>

<style>
	.spec-home {
		max-width: 64rem;
		margin: 0 auto;
		padding: var(--s6) var(--s4) var(--s7);
	}
	.toc {
		list-style: none;
		padding: 0;
		columns: 2 16rem;
	}
	.toc a {
		text-decoration: none;
	}
</style>
