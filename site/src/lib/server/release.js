// The latest release of Vader, read from GitHub when the site is built: the
// download page names it, and says so when there is none yet. The release job
// of the CI publishes the site again once a release is out.

import { GITHUB } from '../links.js';
import { slugify } from './markdown.js';

const API = `https://api.github.com/repos/${new URL(GITHUB).pathname.slice(1)}/releases/latest`;

/**
 * The latest release, null when the repository has none.
 * @returns {Promise<{ version: string, date: string, notes: string } | null>}
 */
export async function latest_release() {
	/** @type {Record<string, string>} */
	const headers = { accept: 'application/vnd.github+json' };
	if (process.env.GITHUB_TOKEN) headers.authorization = `Bearer ${process.env.GITHUB_TOKEN}`;
	const response = await fetch(API, { headers });
	if (response.status === 404) return null;
	if (!response.ok) throw new Error(`${API} answered ${response.status}`);
	const release = await response.json();
	return { version: release.tag_name, date: release.published_at.slice(0, 10), notes: release.html_url };
}

/**
 * The archives each release holds, by platform, with the section of
 * `download.md` that says how to install each (`## macOS` for macOS). Their
 * names carry no version, so a link to the latest release's always reaches the
 * newest.
 */
export const PLATFORMS = [
	{ id: 'darwin-arm64', os: 'macOS', archive: 'vader-darwin-arm64.tar.gz' },
	{ id: 'linux-x64', os: 'Linux', archive: 'vader-linux-x64.tar.gz' },
	{ id: 'windows-x64', os: 'Windows', archive: 'vader-windows-x64.zip' }
].map((p) => ({
	...p,
	section: slugify(p.os),
	href: `${GITHUB}/releases/latest/download/${p.archive}`
}));
