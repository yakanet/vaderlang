import { learn_chapters, learn_introduction } from '#lib/server/learn.js';

export const load = () => ({ introduction: learn_introduction, chapters: learn_chapters.links });
