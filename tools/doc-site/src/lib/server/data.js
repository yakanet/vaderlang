// The data of `vader doc`, read once at build time from the folder
// `VADER_DOC_DATA` names. Its format is described in the toolchain's
// `docs/TOOLING.md` (*`vader doc`*); a version this site was not written for
// stops the build.

import fs from 'node:fs';
import path from 'node:path';

const FORMAT_VERSION = 2;

const data_dir = path.resolve(process.env.VADER_DOC_DATA ?? '../../build/doc');

/** @param {string} file */
function read_json(file) {
	const value = JSON.parse(fs.readFileSync(path.join(data_dir, file), 'utf8'));
	if (value.version !== FORMAT_VERSION) {
		throw new Error(
			`${path.join(data_dir, file)}: data at version ${value.version}, this site reads ${FORMAT_VERSION}`
		);
	}
	return value;
}

/**
 * @typedef {{ text: string, module?: string, name?: string }} Segment
 * @typedef {{ id: string, module: string, name: string, kind: string, signature: string, summary: string, owner: string }} Entry
 * @typedef {{ path: string, summary: string, files: string[] }} ModuleEntry
 */

/** @type {{ modules: ModuleEntry[], entries: Entry[] }} */
export const index = read_json('index.json');

export const module_paths = new Set(index.modules.map((m) => m.path));

/** @param {string} module_path */
export const read_module = (module_path) => read_json(`modules/${module_path}.json`);

// The title of the site, and where its files' sources are read online: a prefix
// a file of the data is appended to, `#L<line>` after it. Without one, a place
// is shown as text.
export const site_title = process.env.VADER_DOC_TITLE ?? 'API reference';
export const source_url = process.env.VADER_DOC_SOURCE_URL ?? '';
