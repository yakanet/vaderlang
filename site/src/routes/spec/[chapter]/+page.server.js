import { error } from '@sveltejs/kit';
import { chapter_list, chapter_page } from '#lib/server/spec.js';

export const entries = () => chapter_list.map((c) => ({ chapter: c.slug }));

/** @param {{ params: { chapter: string } }} event */
export const load = ({ params }) => {
	const page = chapter_page(params.chapter);
	if (!page) error(404, `no chapter ${params.chapter}`);
	return { ...page, slug: params.chapter };
};
