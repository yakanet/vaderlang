<script>
	import ChapterIndex from '#lib/ChapterIndex.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>{data.title}</title>
</svelte:head>

<ChapterIndex title={data.title} introduction={data.introduction} chapters={data.chapters} />
