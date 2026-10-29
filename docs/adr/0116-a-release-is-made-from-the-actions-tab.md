# 0116: A release is made from the Actions tab

## Status

Accepted (2026-10-29).

## Context

A release was a `v*` tag pushed by hand: the CI then built the three bundles and
created the GitHub release with `--generate-notes`. Three gaps:

- the version (`CLI_VERSION`) had to be bumped by hand, and match the tag;
- the generated notes list merged pull requests, and the project pushes
  straight to `main` (2 merges since August): they held a compare link only;
- the release path could only be tried by making a release.

Making the release in the Releases tab instead publishes it before its archives
exist. The download page links `releases/latest/download/<name>`, which would
answer 404 in the meantime, or for good after a failed build, and the tagged
commit would still carry the old version.

`vader --version` and the language server's `serverInfo` printed two copies of
the number, and the server could not import the CLI's: the CLI imports the
server.

## Decision

- The version is the file `vader/support/version/VERSION`, read when the
  compiler is built by `vader/support/version` (`VADER_VERSION`), which the CLI
  and the server both import. `bootstrap/VERSION`, which recorded where the seed
  came from and which nothing read, goes: git holds that (`git log -1 --
  bootstrap/seed`, whose parent is the tree the seed was emitted from).
- `release.yml`, run from the Actions tab with `patch`, `minor`, `major` or
  `X.Y.Z`:
  1. refuses unless the CI of the head of `main` is green;
  2. commits the new version alone, on a temporary branch;
  3. builds the three bundles of that commit with the CI's composite action,
     without the fixed point, which the green head has passed;
  4. moves `main` onto the commit, tags it and drops the branch, in one atomic,
     unforced push; then drafts the release with the archives and notes grouped
     by conventional-commit type (`tools/ci/release-notes.sh`).
- The release commit is not tested again: it changes only the version file.
  The bundle action checks, on every build, that the binary reports the version
  of that file. Publishing the draft starts a CI run on `main`, which tests the
  commit and publishes the site, whose download page names the release: the
  site is published from `main` only.

## Consequences

- A release takes about the time of the bundles, not a full CI run.
- `main` gains a commit made by the CI: pull before the next push. If `main`
  moved during the release, the push is refused and nothing is published.
- The first release names its version (`0.1.0`): a keyword bumps the latest
  `vX.Y.Z` tag, and there is none yet. Its notes are written by hand in the
  draft.
