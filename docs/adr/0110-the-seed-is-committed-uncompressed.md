# 0110: The seed is committed uncompressed

## Status

Accepted (2026-07-28). Written 2026-10-25 from the bootstrap design plan, which
this record replaces as the place of the reasoning.

## Context

The seed was committed as `bootstrap.c.gz`. Compressing it made one seed eleven
times smaller (8.9 MB of C, about 790 KB gzipped), which is what was measured
when the format was chosen.

The quantity that matters is the cost of the history, not of one seed. Two
consecutive seeds are 99.86 % identical as C (296 lines out of 215 530) and 100 %
different as gzip bytes, so git cannot store one as a delta of the other: each
reseed added a fresh blob of about 1 MB, forever. On 2026-07-28 the 453 seed
blobs weighed 429.6 MB, 81 % of the repository.

Options weighed:

- **Keep fewer seeds**, one a week: about 7 MB, but only 7 of the 453 seeded
  commits could still bootstrap themselves, and that is what a seed is for.
- **Move the seed out of the repository**, to a repository of its own or to a
  release asset that `build.sh` downloads: the build needs the network, and the
  seed of a commit is no longer in the commit.
- **Store the C as is**: git deltas consecutive seeds against each other.

## Decision

The seed is committed as plain C. `.gitattributes` marks `bootstrap/seed/**`
`-diff -merge linguist-generated`: what governs delta compression is the `delta`
attribute, not `text` or `binary`, and none of these turns it off.

The history was rewritten the same day: every historical `bootstrap.c.gz` became
the `bootstrap.c` it held, verified by comparing the SHA-256 of each
decompressed original with the rewritten blob. `build.sh`, `verify.sh` and
`.gitattributes` were repointed in the history too, so that an old commit still
finds its seed. `build.ps1` was not, so the Windows build of a commit before the
rewrite fails.

## Consequences

- Packed after `git gc --aggressive`, four consecutive real seeds take 1.6 MB as
  C against 4.3 MB gzipped: about 60 KB a reseed instead of 1 MB.
- `.git` went from 535 MB to 61 MB locally; a fresh clone from GitHub is 83 MB.
  The rewrite alone only reached 452 MB: the aggressive repack is where the gain
  was, because hundreds of large blobs arriving at once defeat the default delta
  window. Ordinary reseeds need no special repack.
- Every SHA of the history changed, the `v0.0.0-pre-mvp-final-ts` tag included.
- The working tree carries the seed as text, and `gzip` is no longer a build
  dependency.
- The seed has since become one file per module: a unit that does not change
  between two seeds is the same blob, stored once.
- If the history grows too large again, the two other options above remain open
  and do not change how `build.sh` is run.
