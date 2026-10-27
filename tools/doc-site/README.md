# The site of `vader doc`

The SvelteKit project `vader doc -o <folder>` builds: one prerendered page per
module of the data `vader doc` writes, with a search over all of them. The
command copies this folder next to an installed `node_modules` and runs the
build with these variables:

| Variable | What it names | Without it |
|---|---|---|
| `VADER_DOC_DATA` | the folder of the data (`index.json`, `modules/`) | `../../build/doc` |
| `VADER_DOC_GRAMMAR` | the TextMate grammar of Vader | `../../editors/common/vader.tmLanguage.json` |
| `VADER_DOC_OUT` | the folder the site is written to | `build` |
| `VADER_DOC_TITLE` | the title of the site | `API reference` |
| `VADER_DOC_SOURCE_URL` | the prefix a file of the data is appended to, to read it online | places as text |
| `BASE_PATH` | the path the site is served under (`/repo`) | `/` |

To work on it from a checkout, with the data of the repository's `lib/`:

```sh
./build/vader doc lib
cd tools/doc-site
npm ci
npm run dev
```

`npm run check` type-checks the sources. The data format is described in
`docs/TOOLING.md` (*`vader doc`*); a version this site does not read stops
the build.
