// @ts-check
// What the pages do in the browser. The site is rendered at build time and ships
// no framework: the components render the markup, its text and its first state,
// and this script only changes that state (`hidden`, `aria-*`, values), fills in
// the values it fetches, or clones what a component rendered. Each part is wired from the markup that carries it,
// so a page without that markup skips the part.

/**
 * The platform the visitor's browser says it runs on, as the id of a release
 * archive (`darwin-arm64`), or "" when none fits.
 */
function client_platform() {
	const agent = navigator.userAgent;
	if (/Windows/.test(agent)) return 'windows-x64';
	if (/Macintosh|Mac OS X/.test(agent)) return 'darwin-arm64';
	if (/Linux/.test(agent) && !/Android/.test(agent)) return 'linux-x64';
	return '';
}

// ---- theme ------------------------------------------------------------------

// The key `app.html` reads before the first paint.
const THEME_KEY = 'vader-doc-theme';

function wire_theme() {
	const buttons = /** @type {HTMLElement[]} */ ([...document.querySelectorAll('[data-theme-choice]')]);
	/** @param {string} choice */
	const show = (choice) => {
		for (const button of buttons) {
			button.setAttribute('aria-pressed', String(button.dataset.themeChoice === choice));
		}
	};
	show(document.documentElement.dataset.theme ?? 'system');
	for (const button of buttons) {
		button.addEventListener('click', () => {
			const choice = button.dataset.themeChoice ?? 'system';
			const root = document.documentElement;
			if (choice === 'system') delete root.dataset.theme;
			else root.dataset.theme = choice;
			try {
				localStorage.setItem(THEME_KEY, choice);
			} catch {}
			show(choice);
		});
	}
}

// ---- tabs -------------------------------------------------------------------

// Only the selected tab is in the tab order.
/** @param {boolean} selected */
function tab_index(selected) {
	if (selected) return 0;
	return -1;
}

// Panels behind a row of tabs, one visible at a time; the arrow keys move
// between the tabs. A tab may name a hash (`data-hash`), which a link to it
// opens, and a platform (`data-platform`), opened for a visitor on it when no
// hash names a tab.
/** @param {Element} tablist */
function wire_tabs(tablist) {
	const tabs = /** @type {HTMLElement[]} */ ([...tablist.querySelectorAll('[role="tab"]')]);
	const panels = tabs.map((tab) => document.getElementById(tab.getAttribute('aria-controls') ?? ''));
	let selected = 0;
	/** @param {number} index */
	const select = (index) => {
		selected = index;
		tabs.forEach((tab, i) => {
			tab.setAttribute('aria-selected', String(i === index));
			tab.tabIndex = tab_index(i === index);
			const panel = panels[i];
			if (panel) panel.hidden = i !== index;
		});
	};
	// Open the tab the URL's hash names; false when it names none.
	const select_named = () => {
		const index = tabs.findIndex((tab) => tab.dataset.hash && `#${tab.dataset.hash}` === location.hash);
		if (index >= 0) select(index);
		return index >= 0;
	};
	tablist.addEventListener('click', (event) => {
		const tab = /** @type {Element} */ (event.target).closest('[role="tab"]');
		if (tab) select(tabs.indexOf(/** @type {HTMLElement} */ (tab)));
	});
	tablist.addEventListener('keydown', (event) => {
		const key = /** @type {KeyboardEvent} */ (event).key;
		let next = selected;
		if (key === 'ArrowRight') next = (selected + 1) % tabs.length;
		if (key === 'ArrowLeft') next = (selected - 1 + tabs.length) % tabs.length;
		if (next === selected) return;
		event.preventDefault();
		select(next);
		tabs[next].focus();
	});
	window.addEventListener('hashchange', select_named);
	if (!select_named()) {
		const detected = tabs.findIndex((tab) => tab.dataset.platform === client_platform());
		if (detected >= 0) select(detected);
	}
}

// ---- search -----------------------------------------------------------------

const SEARCH_LIMIT = 12;

/** @typedef {{ title: string, where: string, href: string }} Entry */

/**
 * The entries whose title holds every word of `text`, those that start with it
 * first.
 * @param {Entry[]} all
 * @param {string} text
 */
function search(all, text) {
	const words = text.toLowerCase().split(/\s+/).filter(Boolean);
	if (words.length === 0) return [];
	const found = all.filter((e) => words.every((w) => e.title.toLowerCase().includes(w)));
	const head = words.join(' ');
	const starts = found.filter((e) => e.title.toLowerCase().startsWith(head));
	const rest = found.filter((e) => !e.title.toLowerCase().startsWith(head));
	return [...starts, ...rest].slice(0, SEARCH_LIMIT);
}

// A search over the headings of the site, fetched at the first use. Cmd+K
// (Ctrl+K off macOS) opens it from anywhere, as the button in the header does.
/** @param {HTMLDialogElement} dialog */
function wire_search(dialog) {
	const trigger = document.querySelector('[data-search-open]');
	const input = /** @type {HTMLInputElement} */ (dialog.querySelector('input'));
	const list = /** @type {HTMLUListElement} */ (dialog.querySelector('[role="listbox"]'));
	const row = /** @type {HTMLTemplateElement} */ (dialog.querySelector('template'));
	const no_match = /** @type {HTMLElement} */ (dialog.querySelector('[data-note="no-match"]'));
	const unreadable = /** @type {HTMLElement} */ (dialog.querySelector('[data-note="unreadable"]'));
	/** @type {Entry[] | null} */
	let entries = null;
	/** @type {Entry[]} */
	let hits = [];
	let selected = 0;

	const mac = client_platform() === 'darwin-arm64';
	trigger?.querySelectorAll('kbd').forEach((kbd) => {
		kbd.hidden = (kbd.dataset.shortcut === 'mac') !== mac;
	});

	/** @param {number} index */
	const move_to = (index) => {
		list.children[selected]?.setAttribute('aria-selected', 'false');
		selected = index;
		list.children[index].setAttribute('aria-selected', 'true');
		input.setAttribute('aria-activedescendant', `hit-${index}`);
	};

	const render = () => {
		hits = search(entries ?? [], input.value);
		selected = 0;
		list.replaceChildren(
			...hits.map((hit, i) => {
				const item = /** @type {HTMLElement} */ (row.content.firstElementChild?.cloneNode(true));
				item.id = `hit-${i}`;
				const link = /** @type {HTMLAnchorElement} */ (item.querySelector('a'));
				link.href = hit.href;
				link.prepend(hit.title);
				/** @type {HTMLElement} */ (item.querySelector('.where')).textContent = hit.where;
				return item;
			})
		);
		list.hidden = hits.length === 0;
		input.setAttribute('aria-expanded', String(hits.length > 0));
		if (hits.length > 0) move_to(0);
		else input.removeAttribute('aria-activedescendant');
		no_match.hidden = hits.length > 0 || input.value.trim() === '' || !entries;
	};

	const load_index = async () => {
		if (entries || !unreadable.hidden) return;
		const response = await fetch(dialog.dataset.index ?? '');
		if (response.ok) entries = (await response.json()).entries;
		else unreadable.hidden = false;
		render();
	};

	const open = () => {
		if (dialog.open) return;
		dialog.showModal();
		input.focus();
		load_index();
	};

	trigger?.addEventListener('click', open);
	window.addEventListener('keydown', (event) => {
		if (event.key.toLowerCase() !== 'k' || !(event.metaKey || event.ctrlKey)) return;
		event.preventDefault();
		if (dialog.open) dialog.close();
		else open();
	});
	input.addEventListener('input', render);
	input.addEventListener('keydown', (event) => {
		if (event.key === 'ArrowDown' && hits.length > 0) move_to((selected + 1) % hits.length);
		else if (event.key === 'ArrowUp' && hits.length > 0) move_to((selected - 1 + hits.length) % hits.length);
		else if (event.key === 'Enter' && hits[selected]) location.href = hits[selected].href;
		else return;
		event.preventDefault();
	});
	list.addEventListener('mouseover', (event) => {
		const item = /** @type {Element} */ (event.target).closest('[role="option"]');
		if (item) move_to([...list.children].indexOf(item));
	});
	// A click on the backdrop, outside the panel, closes the search.
	dialog.addEventListener('click', (event) => {
		if (event.target === dialog) dialog.close();
	});
	dialog.addEventListener('close', () => {
		input.value = '';
		render();
	});
	// A page left from a hit comes back closed from the history.
	window.addEventListener('pagehide', () => dialog.close());
}

// ---- latest release ---------------------------------------------------------

// The name and date of the latest release, from GitHub's API. The slot stays
// hidden when the API does not answer.
/** @param {Element} slot */
async function wire_latest_release(slot) {
	try {
		const response = await fetch(slot.getAttribute('data-latest-release') ?? '');
		if (!response.ok) return;
		const release = await response.json();
		const name = /** @type {HTMLElement} */ (slot.querySelector('[data-release="name"]'));
		const date = /** @type {HTMLTimeElement} */ (slot.querySelector('[data-release="date"]'));
		const day = release.published_at.slice(0, 10);
		name.textContent = release.tag_name;
		date.dateTime = day;
		date.textContent = day;
		slot.removeAttribute('hidden');
	} catch {}
}

// ---- chapter menu -----------------------------------------------------------

// On a narrow screen, the chapters of the specification hide behind a button;
// the page shows them from the button's `aria-expanded`.
/** @param {Element} button */
function wire_menu(button) {
	button.addEventListener('click', () => {
		button.setAttribute('aria-expanded', String(button.getAttribute('aria-expanded') !== 'true'));
	});
}

wire_theme();
document.querySelectorAll('[role="tablist"]').forEach(wire_tabs);
const search_dialog = document.querySelector('dialog[data-search]');
if (search_dialog instanceof HTMLDialogElement) wire_search(search_dialog);
document.querySelectorAll('[data-menu-toggle]').forEach(wire_menu);
document.querySelectorAll('[data-latest-release]').forEach(wire_latest_release);
