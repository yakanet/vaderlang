<script>
	// A chapter among others, of the specification or of the tour: the chapters
	// on the side (behind a button on a narrow screen), the page's sections at its
	// top, and the way to the chapters around it.
	import Outline from './Outline.svelte';

	/** @typedef {{ href: string, label: string }} Link */

	/**
	 * @type {{
	 *   chapters: Link[],
	 *   current: string,
	 *   title: string,
	 *   outline: { id: string, title: string }[],
	 *   html: string,
	 *   previous: Link | null,
	 *   next: Link | null
	 * }}
	 */
	let { chapters, current, title, outline, html, previous, next } = $props();

	// `aria-current` for the link to the chapter at `href`: on its page.
	/** @param {string} href */
	function current_marker(href) {
		if (href !== current) return undefined;
		return 'page';
	}
</script>

<div class="chapter">
	<nav id="chapters" class="side" aria-label="Chapters">
		<ol>
			{#each chapters as chapter (chapter.href)}
				<li><a href={chapter.href} aria-current={current_marker(chapter.href)}>{chapter.label}</a></li>
			{/each}
		</ol>
	</nav>

	<main class="main">
		<button class="menu-btn" type="button" aria-expanded="false" aria-controls="chapters" data-menu-toggle
			>Chapters</button
		>
		<article class="doc">
			<h1>{title}</h1>
			{#if outline.length > 1}
				<Outline headings={outline} />
			{/if}
			{@html html}
		</article>
		<nav class="pager" aria-label="Chapter">
			{#if previous}
				<a href={previous.href} rel="prev">&larr; {previous.label}</a>
			{:else}
				<span></span>
			{/if}
			{#if next}
				<a href={next.href} rel="next">{next.label} &rarr;</a>
			{/if}
		</nav>
	</main>
</div>

<style>
	.chapter {
		display: grid;
		grid-template-columns: 16rem minmax(0, 1fr);
	}
	.side {
		position: sticky;
		top: var(--head-h);
		align-self: start;
		height: calc(100vh - var(--head-h));
		overflow: auto;
		border-right: var(--hair) solid var(--line);
		padding: var(--s4) var(--s3) var(--s6);
		font-size: var(--step--1);
	}
	.side ol {
		list-style: none;
		padding: 0;
	}
	.side a {
		display: block;
		color: var(--fg);
		text-decoration: none;
		padding: 2px var(--s2);
		border-radius: var(--r1);
	}
	.side a:hover {
		background: var(--sunken);
	}
	.side a[aria-current='page'] {
		background: var(--accent-wash);
		color: var(--accent-ink);
		font-weight: 700;
	}
	.main {
		min-width: 0;
		padding: var(--s6) var(--s6) var(--s7);
	}
	.menu-btn {
		display: none;
		font-size: var(--step--1);
		background: var(--surface);
		color: var(--fg);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		padding: var(--s1) var(--s3);
		margin-bottom: var(--s4);
	}
	.pager {
		display: flex;
		justify-content: space-between;
		gap: var(--s4);
		max-width: 46rem;
		margin-top: var(--s7);
		padding-top: var(--s4);
		border-top: var(--hair) solid var(--line);
	}
	.pager a {
		text-decoration: none;
	}
	@media (max-width: 760px) {
		.chapter {
			grid-template-columns: minmax(0, 1fr);
		}
		.menu-btn {
			display: inline-block;
		}
		.side {
			display: none;
			position: fixed;
			z-index: 4;
			inset: 0 auto 0 0;
			width: min(18rem, 85%);
			background: var(--bg);
			box-shadow: 12px 0 30px -18px rgba(0, 0, 0, 0.5);
		}
		/* `site.js` flips the button. */
		.chapter:has(.menu-btn:global([aria-expanded='true'])) .side {
			display: block;
		}
		.main {
			padding: var(--s5) var(--s4) var(--s6);
		}
	}
</style>
