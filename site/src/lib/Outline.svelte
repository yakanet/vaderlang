<script>
	// The sections of a page, listed at its top.

	/** @type {{ headings: { id: string, title: string }[] }} */
	let { headings } = $props();
</script>

<nav class="outline" aria-label="On this page">
	<ul>
		{#each headings as heading (heading.id)}
			<li><a href="#{heading.id}">{heading.title}</a></li>
		{/each}
	</ul>
</nav>

<style>
	.outline {
		margin: 0 0 var(--s6);
		padding: var(--s3) var(--s4);
		background: var(--sunken);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		font-size: var(--step--1);
	}
	ul {
		margin: 0;
		padding: 0;
		list-style: none;
		columns: 2 14rem;
	}
	li {
		padding: 1px 0;
		break-inside: avoid;
	}
	a {
		text-decoration: none;
	}
</style>
