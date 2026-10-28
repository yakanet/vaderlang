<script>
	import { afterNavigate } from '$app/navigation';
	import { GITHUB } from '#lib/links.js';
	import { client_platform } from '#lib/platform.js';
	import Tabs from '#lib/Tabs.svelte';

	let { data } = $props();

	let selected = $state(0);

	// A link to a platform's section (`#linux`) opens its tab, from another page
	// or from this one; otherwise the visitor's own platform is open.
	afterNavigate(({ type }) => {
		const named = data.platforms.findIndex((p) => `#${p.section}` === location.hash);
		if (named >= 0) {
			selected = named;
			return;
		}
		if (type !== 'enter') return;
		const detected = data.platforms.findIndex((p) => p.id === client_platform());
		if (detected >= 0) selected = detected;
	});
</script>

<svelte:head>
	<title>Download &middot; Vader</title>
</svelte:head>

<main class="page">
	<h1>Download Vader</h1>
	{#if data.release}
		<p class="release">
			{data.release.version}, released {data.release.date}:
			<a href={data.release.notes}>what changed</a>.
		</p>
	{:else}
		<p class="callout release">
			There is no release yet: the first one is on its way. Until then, build Vader from source
			with a C compiler, <a href="#build-from-source">below</a>, or follow the
			<a href="{GITHUB}/releases">releases</a> on GitHub.
		</p>
	{/if}

	<div class="platforms">
		<Tabs labels={data.platforms.map((p) => p.os)} label="Platforms" bind:selected>
			{#snippet panel(/** @type {number} */ i)}
				{@const platform = data.platforms[i]}
				<div class="install doc">
					{#if data.release}
						<a class="button primary" href={platform.href}>Download {platform.archive}</a>
					{/if}
					{@html platform.install}
				</div>
			{/snippet}
		</Tabs>
	</div>

	<article class="doc">
		{@html data.rest}
	</article>
</main>

<style>
	.release {
		margin: 0 0 var(--s5);
		color: var(--muted);
	}
	.callout.release {
		color: var(--fg);
	}
	.platforms {
		margin-bottom: var(--s6);
	}
	.install {
		padding: var(--s4) var(--s5) var(--s2);
	}
	.install .button {
		margin-bottom: var(--s4);
	}
</style>
