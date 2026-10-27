<script>
	import { resolve } from '$app/paths';

	/** @type {{ kind: string }} */
	let { kind } = $props();
</script>

<svg class="ki ki-{kind}" aria-hidden="true"><use href="{resolve('/icons.svg')}#{kind}" /></svg>
