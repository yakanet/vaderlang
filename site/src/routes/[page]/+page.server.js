import { error } from '@sveltejs/kit';
import { content_page, MARKDOWN_PAGES } from '#lib/server/content.js';

export const entries = () => MARKDOWN_PAGES.map((page) => ({ page }));

/** @param {{ params: { page: string } }} event */
export const load = ({ params }) => {
	if (!MARKDOWN_PAGES.includes(params.page)) error(404, `no page ${params.page}`);
	return content_page(`${params.page}.md`);
};
