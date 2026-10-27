<script>
	import { module_href } from '#lib/anchors.js';
	import Icon from '#lib/Icon.svelte';

	let { data } = $props();
</script>

<svelte:head><title>{data.title}</title></svelte:head>

<div class="home">
	<h1>{data.title}</h1>
	<p class="lede">{data.modules.length} modules, {data.entries} exports.</p>
	<ul class="modules">
		{#each data.modules as m (m.path)}
			<li>
				<a href={module_href(m.path)}><Icon kind="module" /> {m.path}</a>
				<span class="sum">{@html m.summary_html}</span>
			</li>
		{/each}
	</ul>
</div>

<style>
	.home {
		max-width: 52rem;
	}
	h1 {
		font-size: var(--step-3);
		line-height: 1.15;
		margin: 0 0 var(--s2);
	}
	.lede {
		color: var(--muted);
		margin: 0 0 var(--s5);
	}
	.modules {
		list-style: none;
		margin: 0;
		padding: 0;
		display: grid;
		gap: 0;
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		overflow: hidden;
	}
	.modules li {
		display: grid;
		grid-template-columns: minmax(10rem, 16rem) minmax(0, 1fr);
		gap: var(--s1) var(--s4);
		padding: var(--s2) var(--s3);
		border-top: var(--hair) solid var(--line);
		background: var(--surface);
	}
	.modules li:first-child {
		border-top: 0;
	}
	.modules a {
		font-family: var(--font-code);
		font-size: 0.9rem;
		display: inline-flex;
		align-items: center;
		gap: 6px;
		overflow-wrap: anywhere;
	}
	.sum {
		font-size: 0.9375rem;
	}
	@media (max-width: 560px) {
		.modules li {
			grid-template-columns: minmax(0, 1fr);
		}
	}
</style>
