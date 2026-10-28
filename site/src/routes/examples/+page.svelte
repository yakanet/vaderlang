<script>
	import { page_href } from '#lib/links.js';

	let { data } = $props();
</script>

<svelte:head>
	<title>Examples &middot; Vader</title>
</svelte:head>

<main class="page examples">
	<h1>Examples</h1>
	<p class="lede">
		Whole programs from the repository, with what they print. Each one runs in the test suite, so
		the output shown is the output the program gives today.
	</p>
	<div class="grid">
		{#each data.examples as example (example.name)}
			<section class="card">
				<h2><a href={page_href(`examples/${example.name}`)}>{example.name}</a></h2>
				{@html example.caption}
			</section>
		{/each}
	</div>
</main>

<style>
	.examples {
		--page-w: 64rem;
	}
	.lede {
		max-width: 46rem;
		margin: 0 0 var(--s6);
		color: var(--muted);
	}
	.grid {
		display: grid;
		grid-template-columns: repeat(auto-fit, minmax(min(100%, 18rem), 1fr));
		gap: var(--s4);
	}
	h2 {
		margin: 0 0 var(--s2);
		font-family: var(--font-code);
		font-size: var(--step-1);
	}
</style>
