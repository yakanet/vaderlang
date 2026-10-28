<script>
	import '../fonts.css';
	import '../app.css';
	import { resolve } from '$app/paths';
	import { page } from '$app/state';
	import { GITHUB, page_href, SECTIONS } from '#lib/links.js';
	import Search from '#lib/Search.svelte';
	import ThemeSwitch from '#lib/ThemeSwitch.svelte';

	let { children } = $props();

	// `aria-current` for the link to the section `name`: on one of its pages. A
	// link is relative while the server renders, so it is resolved first.
	/** @param {string} name */
	function section_marker(name) {
		const section = new URL(page_href(name), page.url).pathname;
		if (!page.url.pathname.startsWith(section)) return undefined;
		return 'page';
	}
</script>

<header class="site-head">
	<a class="logo" href={resolve('/')}>
		<svg viewBox="0 0 16 16" aria-hidden="true"
			><path d="M1 1 L4 1 L8 8 L12 1 L15 1 L8 15 Z" fill="var(--logo)" /></svg
		>
		Vader
	</a>
	<nav class="nav" aria-label="Site">
		{#each SECTIONS as section (section.name)}
			<a href={page_href(section.name)} aria-current={section_marker(section.name)}>{section.label}</a>
		{/each}
		<a href={page_href('lib')} rel="external">Library</a>
	</nav>
	<Search />
	<a class="button primary download" href={page_href('download')} aria-current={section_marker('download')}
		>Download</a
	>
	<ThemeSwitch />
</header>

{@render children()}

<footer class="foot">
	<a href={GITHUB}>The sources on GitHub</a> &middot;
	<a href={page_href('vader')} rel="external">The compiler's reference</a> &middot; Fonts: Atkinson
	Hyperlegible, JetBrains Mono, OFL.
</footer>

<style>
	.site-head {
		position: sticky;
		top: 0;
		z-index: 5;
		display: flex;
		align-items: center;
		gap: var(--s4);
		padding: var(--s2) var(--s4);
		border-bottom: var(--hair) solid var(--line);
		background: var(--surface);
		min-width: 0;
	}
	.logo {
		display: flex;
		align-items: center;
		gap: var(--s2);
		font-weight: 700;
		color: var(--fg);
		text-decoration: none;
		white-space: nowrap;
	}
	.logo svg {
		width: 20px;
		height: 20px;
	}
	.nav {
		display: flex;
		flex-wrap: wrap;
		gap: var(--s1) var(--s3);
		font-size: var(--step--1);
	}
	.nav a {
		white-space: nowrap;
		color: var(--fg);
		text-decoration: none;
		padding: 2px var(--s2);
		border-radius: var(--r1);
	}
	.nav a:hover {
		background: var(--sunken);
	}
	.nav a[aria-current='page'] {
		background: var(--accent-wash);
		color: var(--accent-ink);
		font-weight: 700;
	}
	/* Download and the theme sit against the right edge, whatever the width. */
	.download {
		margin-left: auto;
		padding: 2px var(--s3);
		font-size: var(--step--1);
		white-space: nowrap;
	}
	.foot {
		padding: var(--s5) var(--s4) var(--s6);
		border-top: var(--hair) solid var(--line);
		font-size: var(--step--1);
		color: var(--muted);
		text-align: center;
	}
	@media (max-width: 760px) {
		/* The header wraps, and scrolls away with the page: kept in place, it
		   would hide the title a link lands on. Nothing is left to clear. */
		.site-head {
			flex-wrap: wrap;
			position: static;
		}
		:global(:root) {
			--head-h: 0rem;
		}
	}
</style>
