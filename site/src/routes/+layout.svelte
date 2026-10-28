<script>
	import '../fonts.css';
	import '../app.css';
	import { resolve } from '$app/paths';
	import { page } from '$app/state';
	import { api_href, spec_href } from '#lib/links.js';
	import Search from '#lib/Search.svelte';
	import ThemeSwitch from '#lib/ThemeSwitch.svelte';

	let { children } = $props();

	// `aria-current` for the link to the specification: on one of its pages.
	function spec_marker() {
		if (!page.route.id?.startsWith('/spec')) return undefined;
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
		<a href={spec_href()} aria-current={spec_marker()}>Specification</a>
		<a href={api_href('lib')} rel="external">Library</a>
		<a href={api_href('vader')} rel="external">Compiler</a>
	</nav>
	<Search />
	<ThemeSwitch />
</header>

{@render children()}

<footer class="foot">
	<a href="https://github.com/yakanet/vaderlang">The sources on GitHub</a> &middot; Fonts: Atkinson
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
		gap: var(--s3);
		font-size: var(--step--1);
	}
	.nav a {
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
