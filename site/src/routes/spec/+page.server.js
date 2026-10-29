import { introduction, spec_chapters } from '#lib/server/spec.js';

export const load = () => ({ introduction, chapters: spec_chapters.links });
