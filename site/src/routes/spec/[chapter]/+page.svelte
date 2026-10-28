<script>
	import { chapter_href, chapter_label } from '#lib/links.js';
	import Outline from '#lib/Outline.svelte';

	let { data } = $props();

	let menu_open = $state(false);

	// `aria-current` for the link to the chapter `slug`: on its page.
	/** @param {string} slug */
	function current_marker(slug) {
		if (slug !== data.slug) return undefined;
		return 'page';
	}
</script>

<svelte:head>
	<title>{chapter_label(data)} &middot; Vader specification</title>
</svelte:head>

<div class="chapter">
	<nav id="chapters" class="side" class:open={menu_open} aria-label="Chapters">
		<!-- A chapter weighs its whole text: fetched on a tap, not on each hover. -->
		<ol data-sveltekit-preload-data="tap">
			{#each data.chapters as chapter (chapter.slug)}
				<li>
					<a
						href={chapter_href(chapter.slug)}
						aria-current={current_marker(chapter.slug)}
						onclick={() => (menu_open = false)}>{chapter_label(chapter)}</a
					>
				</li>
			{/each}
		</ol>
	</nav>

	<main class="main">
		<button
			class="menu-btn"
			type="button"
			aria-expanded={menu_open}
			aria-controls="chapters"
			onclick={() => (menu_open = !menu_open)}>Chapters</button
		>
		<article class="doc">
			<h1>{chapter_label(data)}</h1>
			{#if data.outline.length > 1}
				<Outline headings={data.outline} />
			{/if}
			{@html data.html}
		</article>
		<nav class="pager" aria-label="Chapter">
			{#if data.previous}
				<a href={chapter_href(data.previous.slug)} rel="prev">&larr; {chapter_label(data.previous)}</a>
			{:else}
				<span></span>
			{/if}
			{#if data.next}
				<a href={chapter_href(data.next.slug)} rel="next">{chapter_label(data.next)} &rarr;</a>
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
		margin: 0;
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
		font: inherit;
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
		.side.open {
			display: block;
		}
		.main {
			padding: var(--s5) var(--s4) var(--s6);
		}
	}
</style>
