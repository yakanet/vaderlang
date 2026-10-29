<script>
	// The system's theme unless the reader picks one: `app.html` applies the
	// choice before the first paint, `site.js` switches it.
	const CHOICES = ['system', 'light', 'dark'];
</script>

<div class="seg" role="group" aria-label="Theme">
	{#each CHOICES as c (c)}
		<button type="button" aria-pressed={c === 'system'} data-theme-choice={c}>{c}</button>
	{/each}
</div>

<style>
	.seg {
		display: inline-flex;
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		overflow: hidden;
		flex: none;
	}
	button {
		font-size: var(--step--1);
		background: var(--surface);
		color: var(--muted);
		border: 0;
		padding: 2px var(--s3);
		cursor: pointer;
		text-transform: capitalize;
	}
	button + button {
		border-left: var(--hair) solid var(--line);
	}
	button[aria-pressed='true'] {
		background: var(--accent-wash);
		color: var(--accent-ink);
		font-weight: 700;
	}
</style>
