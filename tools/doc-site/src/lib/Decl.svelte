<script>
	import Icon from './Icon.svelte';

	/** @type {{ decl: any }} */
	let { decl } = $props();
</script>

<section class="decl">
	<div class="decl-head" id={decl.anchor}>
		<h3><a href="#{encodeURI(decl.anchor)}">{decl.name}</a></h3>
		<span class="chip kind"><Icon kind={decl.kind} />{decl.kind}</span>
		{#if decl.forms.length > 1}
			<span class="chip over">{decl.forms.length} overloads</span>
		{:else}
			{@render place(decl.forms[0])}
		{/if}
	</div>

	{#each decl.forms as form, i (i)}
		<div class="form">
			{#if decl.forms.length > 1}
				<div class="form-head" id={form.anchor}>{@render place(form)}</div>
			{/if}
			{#if form.signature_html}
				<pre class="code sig"><code>{@html form.signature_html}</code></pre>
			{/if}
			{@render detail(form)}
		</div>
	{/each}

	{#if decl.members.length > 0}
		<div class="fields">
			<h4 class="eyebrow">{decl.members_title}</h4>
			<div class="members">
				{#each decl.members as m (m.anchor)}
					<div class="member" id={m.anchor}>
						<code>{@html m.signature_html}</code>
						{#if m.doc_html}
							<div class="doc prose">{@html m.doc_html}</div>
						{:else}
							<div class="doc none">No description.</div>
						{/if}
					</div>
				{/each}
			</div>
		</div>
	{/if}

	{#each decl.impls as impl, i (i)}
		<div class="implements" id={impl.anchor || undefined}>
			<span class="eyebrow">Implements</span>
			{#if impl.href}
				<a class="ic" href={impl.href}>{impl.trait}</a>
				<span class="elsewhere">in {impl.module}</span>
			{:else}
				<code class="ic">{@html impl.signature_html}</code>
				{#each impl.members as m (m.anchor)}
					<code class="ic" id={m.anchor}>{@html m.signature_html}</code>
				{/each}
			{/if}
		</div>
	{/each}
</section>

{#snippet place(/** @type {any} */ form)}
	{#if form.inferred}<span class="chip derived">type inferred</span>{/if}
	{#if form.targets.length > 0}
		<span class="chip plat">{form.targets.join(' · ')}</span>
	{/if}
	{#if form.source.href}
		<a class="src" href={form.source.href} title={form.source.title}>{form.source.label}</a>
	{:else}
		<span class="src" title={form.source.title}>{form.source.label}</span>
	{/if}
{/snippet}

{#snippet detail(/** @type {any} */ form)}
	{#if form.prose_html}<div class="prose">{@html form.prose_html}</div>{/if}

	{#if form.generated}
		<div class="generated">
			<p>No vaderdoc yet. The parameters and the return come from the signature.</p>
			{#if form.parameters.length > 0}{@render parameters(form, false)}{/if}
			{#if form.returns}
				<div class="returns">
					<span class="eyebrow">Returns</span>
					<code class="ic">{@html form.returns.type_html}</code>
				</div>
			{/if}
		</div>
	{:else}
		{#if form.parameters.length > 0}
			<div class="fields">
				<h4 class="eyebrow">Parameters</h4>
				{@render parameters(form, true)}
			</div>
		{/if}
		{#if form.returns}
			<div class="fields">
				<h4 class="eyebrow">Returns</h4>
				<div class="prose">
					<code class="ic">{@html form.returns.type_html}</code>
					{@html form.returns.text_html}
				</div>
			</div>
		{/if}
	{/if}

	{#if form.errors_html.length > 0}
		<div class="fields">
			<h4 class="eyebrow">Errors</h4>
			<ul class="prose">
				{#each form.errors_html as e, i (i)}<li>{@html e}</li>{/each}
			</ul>
		</div>
	{/if}

	{#if form.example}
		<div class="fields">
			<h4 class="eyebrow">Example</h4>
			<div class="example">
				{#if form.example.full_html}
					<details class="ex-full">
						<summary>expand</summary>
						<pre class="code"><code>{@html form.example.full_html}</code></pre>
					</details>
				{/if}
				<pre class="code ex-short"><code>{@html form.example.short_html}</code></pre>
			</div>
		</div>
	{/if}
{/snippet}

{#snippet parameters(/** @type {any} */ form, /** @type {boolean} */ described)}
	<table class="ptable">
		<tbody>
			{#each form.parameters as p (p.name)}
				<tr>
					<td class="nm">{p.name}</td>
					<td class="ty">
						<code>{@html p.type_html}</code>
						{#if p.default_html}<span class="def">= <code>{@html p.default_html}</code></span>{/if}
					</td>
					{#if described}
						{#if p.text_html}<td>{@html p.text_html}</td>{:else}<td class="none">No description.</td>{/if}
					{/if}
				</tr>
			{/each}
		</tbody>
	</table>
{/snippet}

<style>
	.decl {
		border-top: var(--hair) solid var(--line);
		padding-top: var(--s5);
		margin-top: var(--s5);
	}
	.decl,
	.form {
		display: grid;
		gap: var(--s3);
	}
	/* What a link lands on is the row that carries its `id`: the title of a
	   declaration or of one of its forms, a member, an impl. The shadow widens
	   the band without moving the row. */
	.decl :target {
		background: var(--accent-wash);
		box-shadow: 0 0 0 var(--s2) var(--accent-wash);
		border-radius: var(--r1);
	}
	.decl-head,
	.form-head {
		display: flex;
		flex-wrap: wrap;
		align-items: baseline;
		gap: var(--s1) var(--s3);
	}
	h3 {
		margin: 0;
		font-family: var(--font-code);
		font-size: var(--step-1);
		font-weight: 700;
		overflow-wrap: anywhere;
	}
	h3 a {
		color: var(--fg);
		text-decoration: none;
	}
	h3 a:hover {
		text-decoration: underline;
	}
	.src {
		margin-left: auto;
		font-size: var(--step--1);
		color: var(--muted);
		font-family: var(--font-code);
	}
	.form + .form {
		border-top: var(--hair) dashed var(--line);
		padding-top: var(--s4);
		margin-top: var(--s2);
	}
	.fields {
		display: grid;
		gap: var(--s2);
	}
	h4 {
		margin: 0;
	}
	.ptable {
		width: 100%;
		border-collapse: collapse;
		font-size: 0.9375rem;
	}
	.ptable td {
		padding: var(--s2) var(--s3) var(--s2) 0;
		border-top: var(--hair) solid var(--line);
		vertical-align: top;
	}
	.ptable tr:first-child td {
		border-top: 0;
	}
	.ptable td.nm {
		font-family: var(--font-code);
		font-size: 0.875rem;
		white-space: nowrap;
		font-weight: 500;
	}
	.ptable td.ty {
		font-size: 0.8125rem;
		color: var(--muted);
	}
	.ptable td.none,
	.def {
		color: var(--muted);
	}
	/* The signatures take the room they need up to half the width, then wrap: a
	   long one would leave its description a word per line. */
	.members {
		display: grid;
		grid-template-columns: fit-content(50%) minmax(0, 1fr);
		border: var(--hair) solid var(--line);
		border-radius: var(--r2);
		overflow: hidden;
	}
	.member {
		grid-column: 1 / -1;
		display: grid;
		grid-template-columns: subgrid;
		column-gap: var(--s4);
		row-gap: var(--s1);
		padding: var(--s2) var(--s3);
		border-top: var(--hair) solid var(--line);
		background: var(--surface);
	}
	.member:first-child {
		border-top: 0;
	}
	.member code {
		font-size: 0.85rem;
		overflow-wrap: anywhere;
	}
	.member .doc {
		font-size: 0.9375rem;
	}
	.member .doc.none {
		color: var(--muted);
	}
	.implements {
		display: flex;
		flex-wrap: wrap;
		align-items: baseline;
		gap: var(--s2);
		font-size: var(--step--1);
		color: var(--muted);
	}
	.elsewhere {
		font-family: var(--font-code);
	}
	.generated {
		border: var(--hair) dashed var(--derived);
		background: var(--derived-wash);
		border-radius: var(--r2);
		padding: var(--s3) var(--s4);
		display: grid;
		gap: var(--s2);
	}
	.generated > p {
		margin: 0;
		font-size: var(--step--1);
		color: var(--derived);
		font-weight: 700;
	}
	.generated .ptable td {
		border-top-color: color-mix(in srgb, var(--derived) 25%, transparent);
	}
	.returns {
		display: flex;
		gap: var(--s2);
		align-items: baseline;
	}
	.example {
		position: relative;
	}
	.ex-full > summary {
		position: absolute;
		top: 6px;
		right: 10px;
		z-index: 1;
		list-style: none;
		cursor: pointer;
		font-size: 0.75rem;
		color: var(--accent-ink);
		text-decoration: underline;
		text-underline-offset: 2px;
	}
	.ex-full > summary::-webkit-details-marker {
		display: none;
	}
	.ex-full[open] + .ex-short {
		display: none;
	}
	.ex-full[open] > summary {
		font-size: 0;
	}
	.ex-full[open] > summary::after {
		content: 'collapse';
		font-size: 0.75rem;
	}
	.example .ex-short,
	.example .ex-full pre {
		padding-right: 5.5rem;
	}
	@media (max-width: 560px) {
		.members {
			grid-template-columns: minmax(0, 1fr);
		}
	}
</style>
