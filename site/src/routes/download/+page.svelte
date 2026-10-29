<script>
	import { GITHUB, LATEST_RELEASE, LATEST_RELEASE_API } from '#lib/links.js';
	import Tabs from '#lib/Tabs.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>Download &middot; Vader</title>
</svelte:head>

<main class="page">
	<h1>Download Vader</h1>
	<p class="release">
		<span data-latest-release={LATEST_RELEASE_API} hidden>
			<span data-release="name"></span>, released <time data-release="date"></time>:
		</span>
		<a href={LATEST_RELEASE}>Release notes</a> &middot;
		<a href="{GITHUB}/releases">all releases</a> on GitHub.
	</p>

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
					<a class="button primary" href={platform.href}>Download {platform.archive}</a>
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
