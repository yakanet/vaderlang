import { error } from '@sveltejs/kit';
import { learn_chapters, learn_introduction } from '#lib/server/learn.js';

export const entries = () => learn_chapters.slugs.map((chapter) => ({ chapter }));

/** @param {{ params: { chapter: string } }} event */
export const load = ({ params }) => ({
	...(learn_chapters.page(params.chapter) ?? error(404, `no chapter ${params.chapter}`)),
	set_title: learn_introduction.title
});
