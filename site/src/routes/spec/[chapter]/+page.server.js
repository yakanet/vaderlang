import { error } from '@sveltejs/kit';
import { spec_chapters, spec_title } from '#lib/server/spec.js';

export const entries = () => spec_chapters.slugs.map((chapter) => ({ chapter }));

/** @param {{ params: { chapter: string } }} event */
export const load = ({ params }) => ({
	...(spec_chapters.page(params.chapter) ?? error(404, `no chapter ${params.chapter}`)),
	set_title: spec_title
});
