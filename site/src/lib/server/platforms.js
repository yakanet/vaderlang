import { LATEST_RELEASE } from '../links.js';
import { slugify } from './markdown.js';

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
	href: `${LATEST_RELEASE}/download/${p.archive}`
}));
