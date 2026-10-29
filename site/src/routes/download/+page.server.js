import { content_parts } from '#lib/server/content.js';
import { PLATFORMS } from '#lib/server/platforms.js';

export const load = () => {
	const { parts, rest } = content_parts(
		'download.md',
		PLATFORMS.map((p) => p.section)
	);
	const platforms = PLATFORMS.map((platform) => {
		const install = parts.get(platform.section);
		if (install === undefined) throw new Error(`download.md has no section for ${platform.os}`);
		return { ...platform, install };
	});
	return { platforms, rest };
};
