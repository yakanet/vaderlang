<script>
	import ContentPage from '#lib/ContentPage.svelte';

	let { data } = $props();
</script>

<ContentPage {...data} />
