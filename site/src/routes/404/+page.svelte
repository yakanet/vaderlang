<script>
	import { resolve } from '$app/paths';
	import { page_href } from '#lib/links.js';
</script>

<svelte:head>
	<title>Not found &middot; Vader</title>
</svelte:head>

<main class="page">
	<h1>Not found</h1>
	<p>
		No page of the site is at this address. Start from the <a href={resolve('/')}>home page</a>, the
		<a href={page_href('spec')}>language reference</a>, or search with the button above.
	</p>
</main>
