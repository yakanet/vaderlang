<script>
	import { asset } from '$app/paths';
	import { api_href, spec_href } from '#lib/links.js';

	let { data } = $props();
</script>

<svelte:head>
	<title>Vader</title>
	<meta
		name="description"
		content="Vader, a strongly typed language that compiles itself: its specification, and the API reference of its library and compiler."
	/>
</svelte:head>

<main class="home">
	<header class="hero">
		<img src={asset('favicon.svg')} width="72" height="72" alt="" />
		<h1>Vader</h1>
		<p class="lede">
			A strongly typed, general-purpose language with type inference, compiled to native code by
			a compiler written in Vader.
		</p>
	</header>

	<div class="cards">
		<section class="card">
			<h2><a href={spec_href()}>Specification</a></h2>
			<p>
				The language, chapter by chapter: its types, functions, control flow, modules, decorators
				and compile-time execution.
			</p>
		</section>

		<section class="card">
			<h2><a href={api_href('lib')} rel="external">Library</a></h2>
			<p>
				The standard library and the packages beside it: I/O, strings, collections, iterators,
				JSON, the build contract.
			</p>
			<div class="stats">{data.stats.lib}</div>
		</section>

		<section class="card">
			<h2><a href={api_href('vader')} rel="external">Compiler</a></h2>
			<p>
				The self-hosted compiler: its lexer and parser, the type checker, lowering, the back ends,
				and the tools around it.
			</p>
			<div class="stats">{data.stats.vader}</div>
		</section>
	</div>
</main>

<style>
	.home {
		width: 100%;
		max-width: 64rem;
		margin: 0 auto;
		padding: clamp(3rem, 10vh, 6rem) var(--s4) var(--s7);
	}
	.hero {
		display: grid;
		justify-items: center;
		text-align: center;
		gap: var(--s4);
		margin-bottom: var(--s7);
	}
	h1 {
		margin: 0;
		font-size: clamp(2.25rem, 6vw, 3.25rem);
		line-height: 1.05;
		letter-spacing: -0.02em;
	}
	.lede {
		margin: 0;
		max-width: 38rem;
		color: var(--muted);
		font-size: var(--step-1);
	}
	.cards {
		display: grid;
		grid-template-columns: repeat(auto-fit, minmax(min(100%, 18rem), 1fr));
		gap: var(--s5);
	}
	.card {
		position: relative;
		display: grid;
		gap: var(--s3);
		align-content: start;
		padding: var(--s5);
		background: var(--surface);
		border: var(--hair) solid var(--line);
		border-radius: 10px;
	}
	.card:hover,
	.card:focus-within {
		border-color: var(--accent);
	}
	.card h2 {
		margin: 0;
		font-size: var(--step-2);
	}
	/* The whole card follows its title's link. */
	.card h2 a {
		color: inherit;
		text-decoration: none;
	}
	.card h2 a::after {
		content: '';
		position: absolute;
		inset: 0;
		border-radius: 10px;
	}
	.card p {
		margin: 0;
		color: var(--muted);
	}
	.stats {
		font-family: var(--font-code);
		font-size: var(--step--1);
		color: var(--accent-ink);
		min-height: 1.3em;
	}
</style>
