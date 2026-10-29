import { introduction, spec_chapters, spec_title } from '#lib/server/spec.js';

export const load = () => ({ title: spec_title, introduction, chapters: spec_chapters.links });
