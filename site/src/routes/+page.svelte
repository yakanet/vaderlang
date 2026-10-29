<script>
	import { GITHUB, page_href } from '#lib/links.js';
	import Showcase from '#lib/Showcase.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>Vader</title>
	<meta
		name="description"
		content="Vader, a general-purpose language with type inference, compiled to native code by a compiler written in Vader."
	/>
</svelte:head>

<main class="page home">
	<section class="hero">
		<div class="pitch">
			<h1>Vader</h1>
			<p class="tagline">The discipline of static typing, the ergonomics of a script.</p>
			<p class="lede">
				A general-purpose language with type inference, compiled to native code by a compiler
				written in Vader.
			</p>
			<div class="actions">
				<a class="button primary" href={page_href('download')}>Download</a>
				<a class="button" href={page_href('start')}>Get started</a>
				<a class="github" href={GITHUB}>GitHub</a>
			</div>
			<p class="callout status">
				An experiment: the compiler compiles itself and runs the examples on both back ends, the
				VM and native code. The language still changes from one version to the next.
			</p>
		</div>
		<Showcase examples={data.showcase} />
	</section>

	<section aria-labelledby="why">
		<h2 id="why">Why Vader</h2>
		<div class="grid tiles">
			{#each data.why as tile (tile.id)}
				<div class="box">
					<h3>{tile.title}</h3>
					{@html tile.html}
				</div>
			{/each}
		</div>
	</section>

	<section class="toolchain" aria-labelledby="toolchain">
		<h2 id="toolchain">One command for everything</h2>
		{@html data.toolchain}
	</section>

	<section aria-labelledby="read-on">
		<h2 id="read-on">Read on</h2>
		<div class="grid">
			<section class="card">
				<h3><a href={page_href('learn')}>Learn</a></h3>
				<p>
					The language one construct at a time, each shown by a short program and what it prints.
				</p>
			</section>
			<section class="card">
				<h3><a href={page_href('spec')}>Language reference</a></h3>
				<p>
					The rules of the language, chapter by chapter: its types, functions, control flow, modules,
					decorators and compile-time execution.
				</p>
			</section>
			<section class="card">
				<h3><a href={page_href('lib')} rel="external">Library</a></h3>
				<p>
					The standard library and the packages beside it: I/O, strings, collections, iterators,
					JSON, the build contract.
				</p>
				<div class="stats">{data.stats.lib}</div>
			</section>
			<section class="card">
				<h3><a href={page_href('vader')} rel="external">Compiler</a></h3>
				<p>
					The self-hosted compiler: its lexer and parser, the type checker, lowering, the back ends,
					and the tools around it.
				</p>
				<div class="stats">{data.stats.vader}</div>
			</section>
		</div>
	</section>
</main>

<style>
	.home {
		--page-w: 76rem;
	}
	.hero {
		display: grid;
		grid-template-columns: minmax(0, 5fr) minmax(0, 7fr);
		gap: var(--s6);
		align-items: start;
	}
	.pitch {
		display: grid;
		gap: var(--s4);
		align-content: start;
		padding-top: var(--s5);
	}
	h1 {
		font-size: clamp(2.5rem, 6vw, 3.75rem);
		line-height: 1;
		letter-spacing: -0.02em;
	}
	.tagline {
		font-size: var(--step-2);
		line-height: 1.25;
		font-weight: 700;
		text-wrap: balance;
	}
	.lede {
		color: var(--muted);
		font-size: var(--step-1);
	}
	.actions {
		display: flex;
		flex-wrap: wrap;
		align-items: center;
		gap: var(--s3);
		margin-top: var(--s2);
	}
	.github {
		margin-left: var(--s2);
	}
	.status {
		margin: var(--s3) 0 0;
		font-size: var(--step--1);
		color: var(--muted);
	}
	.home > section + section {
		margin-top: var(--s7);
	}
	h2 {
		font-size: var(--step-2);
		margin: 0 0 var(--s4);
	}
	h3 {
		margin: 0 0 var(--s2);
		font-size: var(--step-1);
	}
	.grid {
		display: grid;
		grid-template-columns: repeat(auto-fit, minmax(min(100%, 18rem), 1fr));
		gap: var(--s4);
	}
	.tiles {
		grid-template-columns: repeat(auto-fit, minmax(min(100%, 20rem), 1fr));
	}
	.tiles :global(p) {
		color: var(--muted);
	}
	.toolchain :global(ul) {
		display: grid;
		grid-template-columns: repeat(auto-fit, minmax(min(100%, 28rem), 1fr));
		gap: var(--s2) var(--s6);
		padding: 0;
		list-style: none;
	}
	.toolchain :global(li) {
		color: var(--muted);
	}
	.toolchain :global(li .ic:first-child) {
		color: var(--fg);
	}
	.stats {
		margin-top: var(--s3);
		font-family: var(--font-code);
		font-size: var(--step--1);
		color: var(--accent-ink);
	}
	@media (max-width: 900px) {
		.hero {
			grid-template-columns: minmax(0, 1fr);
		}
		.pitch {
			padding-top: 0;
		}
	}
</style>
