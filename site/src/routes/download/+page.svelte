<script>
	import { GITHUB } from '#lib/links.js';
	import Tabs from '#lib/Tabs.svelte';

	let { data } = $props();
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
		<Tabs
			labels={data.platforms.map((p) => p.os)}
			label="Platforms"
			hashes={data.platforms.map((p) => p.section)}
			platforms={data.platforms.map((p) => p.id)}
		>
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
