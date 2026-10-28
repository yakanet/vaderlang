import { error } from '@sveltejs/kit';
import { examples } from '#lib/server/content.js';

export const entries = () => examples.map((e) => ({ name: e.name }));

/** @param {{ params: { name: string } }} event */
export const load = ({ params }) => {
	const example = examples.find((e) => e.name === params.name);
	if (!example) error(404, `no example ${params.name}`);
	return example;
};
