<script>
	import Decl from '#lib/Decl.svelte';
	import Icon from '#lib/Icon.svelte';

	let { data } = $props();

	let parts = $derived(data.path.split('/'));

	/** @param {number} n */
	function files_label(n) {
		if (n === 1) return '1 file';
		return `${n} files`;
	}
</script>

<svelte:head><title>{data.path} · {data.title}</title></svelte:head>

<div class="page">
	<article class="content">
		<header>
			<h1 class="mod-title">
				{#if parts.length > 1}<span class="dim">{parts.slice(0, -1).join('/')}/</span>{/if}{parts.at(-1)}
			</h1>
			{#if data.summary_html}<p class="lede">{@html data.summary_html}</p>{/if}
			<div class="meta">
				<span>
					{files_label(data.files.length)}
					<code>{data.files.join(', ')}</code>
				</span>
				<span>{data.export_count} exports</span>
			</div>
		</header>

		{#if data.header_html}<div class="prose">{@html data.header_html}</div>{/if}

		{#each data.groups as group (group.title)}
			<section class="group">
				<h2>{group.title}</h2>
				{#each group.items as decl (decl.anchor)}
					<Decl {decl} />
				{/each}
			</section>
		{/each}
	</article>

	<nav class="toc" aria-label="On this page">
		<h4 class="eyebrow">On this page</h4>
		{#each data.groups as group (group.title)}
			<div class="g">{group.title}</div>
			<ul>
				{#each group.items as decl (decl.anchor)}
					<li>
						<a href="#{encodeURI(decl.anchor)}" title={decl.name}
							><Icon kind={decl.kind} /><span class="nm">{decl.name}</span></a
						>
					</li>
				{/each}
			</ul>
		{/each}
	</nav>
</div>

<style>
	.page {
		display: grid;
		grid-template-columns: minmax(0, 46rem) 12rem;
		gap: var(--s6);
		justify-content: start;
	}
	/* One column that never grows past the page: an `auto` track would take the
	   width of the longest code line, and the page would scroll sideways. */
	.content {
		display: grid;
		grid-template-columns: minmax(0, 1fr);
		gap: var(--s6);
		align-content: start;
	}
	.mod-title {
		margin: 0 0 var(--s2);
		font-family: var(--font-code);
		font-size: var(--step-3);
		line-height: 1.1;
		font-weight: 700;
		letter-spacing: -0.01em;
		overflow-wrap: anywhere;
	}
	.dim {
		color: var(--muted);
		font-weight: 400;
	}
	.lede {
		font-size: var(--step-1);
		margin: 0;
	}
	.meta {
		display: flex;
		flex-wrap: wrap;
		gap: var(--s2) var(--s4);
		font-size: var(--step--1);
		color: var(--muted);
		margin-top: var(--s3);
	}
	/* A path holds no space to wrap at: it breaks where it must. */
	.meta code {
		color: var(--fg);
		overflow-wrap: anywhere;
	}
	.group > h2 {
		font-size: var(--step-2);
		margin: 0 0 var(--s2);
		line-height: 1.2;
	}
	.toc {
		position: sticky;
		top: calc(var(--head-h) + var(--s4));
		align-self: start;
		max-height: calc(100vh - var(--head-h) - var(--s6));
		overflow: auto;
		border-left: var(--hair) solid var(--line);
		padding: 0 var(--s3);
		font-size: var(--step--1);
	}
	.toc h4 {
		margin: 0 0 var(--s2);
	}
	.toc ul {
		list-style: none;
		margin: 0 0 var(--s4);
		padding: 0;
		display: grid;
		grid-template-columns: minmax(0, 1fr);
		gap: 2px;
	}
	.toc a {
		color: var(--muted);
		text-decoration: none;
		font-family: var(--font-code);
		font-size: 0.78rem;
		display: flex;
		align-items: center;
		gap: 6px;
		min-width: 0;
	}
	.nm {
		overflow: hidden;
		text-overflow: ellipsis;
		white-space: nowrap;
	}
	.toc a:hover {
		color: var(--accent);
	}
	.g {
		font-weight: 700;
		color: var(--fg);
		margin-bottom: 2px;
	}
	@media (max-width: 1080px) {
		.page {
			grid-template-columns: minmax(0, 46rem);
		}
		.toc {
			display: none;
		}
	}
</style>
