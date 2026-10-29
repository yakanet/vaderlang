<script>
	import ChapterPage from '#lib/ChapterPage.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>{data.title} &middot; Learn Vader</title>
</svelte:head>

<ChapterPage {...data} />
