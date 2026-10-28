import path from 'node:path';

/** The repository the site is built from (`SITE_REPO`): its specification and grammar. */
export const REPO = path.resolve(process.env.SITE_REPO ?? '..');
