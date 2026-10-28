import fs from 'node:fs';
import path from 'node:path';

// Where the API references were built (`SITE_API_DIR`), each in its own folder.
const API_DIR = process.env.SITE_API_DIR;

/**
 * The size the API reference `site` gives of itself, "" when it is not built.
 * @param {'lib' | 'vader'} site
 */
function stats_of(site) {
	if (!API_DIR) return '';
	const file = path.join(API_DIR, site, 'stats.json');
	if (!fs.existsSync(file)) return '';
	const { modules, exports } = JSON.parse(fs.readFileSync(file, 'utf8'));
	return `${modules} modules \u00b7 ${exports} exports`;
}

export const load = () => ({ stats: { lib: stats_of('lib'), vader: stats_of('vader') } });
