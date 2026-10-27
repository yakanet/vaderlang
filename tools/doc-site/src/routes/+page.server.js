import { index, stats } from '#lib/server/data.js';
import { inline_html } from '#lib/server/markdown.js';

export const load = () => ({
	modules: index.modules.map((m) => ({ path: m.path, summary_html: inline_html(m.summary) })),
	exports: stats.exports
});
