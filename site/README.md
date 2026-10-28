# The site of the language

The SvelteKit project behind the published site: a home page and the
specification, one prerendered page per chapter of `SPEC.md`, with a search
over its headings. The API references `vader doc` writes are other builds,
published beside it under `lib/` and `vader/` (`.github/workflows/docs.yml`).

A cross-reference of the specification, `§N` or `§N *Title*`, becomes a link
to that chapter or to the heading of that title in it, and a link to a file of
the repository leads to its source. One that names nothing stops the build.

| Variable | What it names | Without it |
|---|---|---|
| `SITE_REPO` | the repository: its `SPEC.md` and the TextMate grammar of Vader | `..` |
| `SITE_SOURCE_URL` | the prefix a file of the repository is read at online | the GitHub repository's `main` |
| `SITE_API_DIR` | where the API references were built, for the size the home page gives | no size |
| `BASE_PATH` | the path the site is served under (`/repo`) | `/` |

To work on it from a checkout:

```sh
cd site
npm ci
npm run dev
```

`npm run check` type-checks the sources.
