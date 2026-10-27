import { icons } from '@iconify-json/codicon';

// A route that serves a file does not inherit the layout's options.
export const prerender = true;

// The icon of each kind of entry: the codicons of the outline of VS Code. One
// sprite, which every page refers to, and nothing loaded from elsewhere.
const KIND_ICONS = {
	module: 'symbol-namespace',
	fn: 'symbol-method',
	method: 'symbol-method',
	struct: 'symbol-structure',
	enum: 'symbol-enum',
	variant: 'symbol-enum-member',
	trait: 'symbol-interface',
	type: 'symbol-class',
	const: 'symbol-constant',
	field: 'symbol-field',
	impl: 'plug'
};

export const GET = () => {
	const size = icons.width ?? 16;
	const symbols = Object.entries(KIND_ICONS).map(
		([kind, name]) =>
			`<symbol id="${kind}" viewBox="0 0 ${size} ${size}">${icons.icons[name].body}</symbol>`
	);
	const svg = `<svg xmlns="http://www.w3.org/2000/svg">${symbols.join('')}</svg>`;
	return new Response(svg, { headers: { 'content-type': 'image/svg+xml' } });
};
