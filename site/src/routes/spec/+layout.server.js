import { chapter_list } from '#lib/server/spec.js';

// Every page of the specification lists the chapters ; loaded once for all.
export const load = () => ({ chapters: chapter_list });
