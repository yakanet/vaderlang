<script>
	import '../fonts.css';
	import '../app.css';
	import { resolve } from '$app/paths';
	import { page } from '$app/state';
	import { module_href } from '#lib/anchors.js';
	import Search from '#lib/Search.svelte';
	import ThemeSwitch from '#lib/ThemeSwitch.svelte';

	let { data, children } = $props();

	let menu_open = $state(false);
	let current = $derived(/** @type {string} */ (page.data.path ?? ''));

	// `aria-current` for the link to the module `path`: on the page of that one.
	/** @param {string} path */
	function current_marker(path) {
		if (path !== current) return undefined;
		return 'page';
	}
</script>

<header class="site-head">
	<button
		class="menu-btn"
		type="button"
		aria-expanded={menu_open}
		aria-controls="side"
		onclick={() => (menu_open = !menu_open)}>Modules</button
	>
	<a class="logo" href={resolve('/')}>
		<svg viewBox="0 0 16 16" aria-hidden="true"
			><path d="M1 1 L4 1 L8 8 L12 1 L15 1 L8 15 Z" fill="var(--logo)" /></svg
		>
		Vader <span class="title">{data.title}</span>
	</a>
	<Search />
	<ThemeSwitch />
</header>

<div class="site-body">
	<nav id="side" class="side" class:open={menu_open} aria-label="Modules">
		<ul>
			{#each data.tree as group (group.head)}
				<li>
					{#if group.modules.length === 1 && group.modules[0].path === group.head}
						{@render module_link(group.modules[0])}
					{:else}
						<span class="grp">{group.head}</span>
						<ul>
							{#each group.modules as m (m.path)}
								<li>{@render module_link(m)}</li>
							{/each}
						</ul>
					{/if}
				</li>
			{/each}
		</ul>
	</nav>

	<main class="main">
		{@render children()}
		<footer class="foot">
			Written by <code>vader doc</code>. Icons:
			<a href="https://github.com/microsoft/vscode-codicons">Codicons</a>, CC BY 4.0. Fonts:
			Atkinson Hyperlegible, JetBrains Mono, OFL.
		</footer>
	</main>
</div>

{#snippet module_link(/** @type {{ path: string, label: string }} */ m)}
	<a
		href={module_href(m.path)}
		aria-current={current_marker(m.path)}
		onclick={() => (menu_open = false)}>{m.label}</a
	>
{/snippet}

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
	.title {
		font-weight: 400;
		color: var(--muted);
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
	}
	.site-body {
		display: grid;
		grid-template-columns: 15rem minmax(0, 1fr);
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
	.side ul {
		list-style: none;
		margin: 0;
		padding: 0;
		display: grid;
		grid-template-columns: minmax(0, 1fr);
		gap: 1px;
	}
	.side ul ul {
		padding-left: var(--s3);
		border-left: var(--hair) solid var(--line);
		margin: 2px 0 var(--s2) var(--s2);
	}
	.side a {
		display: block;
		color: var(--fg);
		text-decoration: none;
		font-family: var(--font-code);
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
	.grp {
		font-family: var(--font-code);
		color: var(--muted);
		padding: 2px var(--s2);
		display: block;
	}
	.main {
		min-width: 0;
		padding: var(--s6) var(--s6) var(--s7);
	}
	.foot {
		margin-top: var(--s7);
		padding-top: var(--s4);
		border-top: var(--hair) solid var(--line);
		font-size: var(--step--1);
		color: var(--muted);
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
		.menu-btn {
			display: inline-block;
		}
		.site-body {
			grid-template-columns: minmax(0, 1fr);
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
