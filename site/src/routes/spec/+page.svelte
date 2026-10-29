<script>
	import ChapterIndex from '#lib/ChapterIndex.svelte';

	let { data } = $props();
</script>

<svelte:head>
	<title>Vader specification</title>
</svelte:head>

<ChapterIndex title="Vader Language Specification" introduction={data.introduction} chapters={data.chapters} />
