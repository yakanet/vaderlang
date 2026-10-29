<script>
	// The system's theme unless the reader picks one, kept in the browser for
	// the next pages (`app.html` applies it before the first paint).
	const CHOICES = ['system', 'light', 'dark'];
	const KEY = 'vader-doc-theme';

	let choice = $state('system');

	// What `app.html` applied before the first paint.
	$effect(() => {
		choice = document.documentElement.dataset.theme ?? 'system';
	});

	/** @param {string} next */
	function pick(next) {
		choice = next;
		const root = document.documentElement;
		if (next === 'system') delete root.dataset.theme;
		else root.dataset.theme = next;
		try {
			localStorage.setItem(KEY, next);
		} catch {}
	}
</script>

<div class="seg" role="group" aria-label="Theme">
	{#each CHOICES as c (c)}
		<button type="button" aria-pressed={choice === c} onclick={() => pick(c)}>{c}</button>
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
