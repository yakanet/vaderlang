<script>
	// The first page of a set of chapters: what it is, then its chapters.

	/**
	 * @type {{
	 *   title: string,
	 *   introduction: string,
	 *   chapters: { href: string, label: string }[]
	 * }}
	 */
	let { title, introduction, chapters } = $props();
</script>

<main class="chapters-home">
	<article class="doc">
		<h1>{title}</h1>
		{@html introduction}
		<ol class="toc">
			{#each chapters as chapter (chapter.href)}
				<li><a href={chapter.href}>{chapter.label}</a></li>
			{/each}
		</ol>
	</article>
</main>

<style>
	.chapters-home {
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
