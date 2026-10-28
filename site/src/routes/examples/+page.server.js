import { examples } from '#lib/server/content.js';

export const load = () => ({
	examples: examples.map(({ name, caption }) => ({ name, caption }))
});
