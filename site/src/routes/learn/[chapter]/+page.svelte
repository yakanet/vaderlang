<script>
	import ChapterPage from '#lib/ChapterPage.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>{data.title} &middot; {data.set_title}</title>
</svelte:head>

<ChapterPage {...data} />
