<script>
	import ChapterIndex from '#lib/ChapterIndex.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>{data.introduction.title}</title>
</svelte:head>

<ChapterIndex title={data.introduction.title} introduction={data.introduction.html} chapters={data.chapters} />
