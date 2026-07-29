#!/usr/bin/env bash
# Regenerate bootstrap/bootstrap.c from vader/bootstrap/bootstrap.vader, using an
# existing `vader` binary (on PATH or ./build/vader). The seed is the plain C of
# the build-only entrypoint — stored uncompressed so git can delta successive
# reseeds; see docs/BOOTSTRAP.md § "Seed lifecycle management".
#
# The emission itself belongs to bootstrap/check-seed.sh, which this script calls:
# it resolves the compiler, emits, and compares in one pass, so a reseed costs one
# compile rather than two and the flags cannot drift between checker and writer.
set -euo pipefail
cd "$(dirname "$0")/.."

# Require a clean working tree on vader/ so the recorded SHA is meaningful.
if ! git diff-index --quiet HEAD -- vader/; then
  echo "error: vader/ has uncommitted changes — commit first" >&2
  exit 1
fi

# check-seed.sh prints the compiler it used on stdout and the diagnosis on stderr;
# --full skips its git short-circuit, since a reseed must compare real output.
set +e
VADER="$(./bootstrap/check-seed.sh --full)"
verdict=$?
set -e

case "$verdict" in
  0)
    echo "seed already fresh — byte-identical, nothing to commit (VERSION left alone)."
    echo "(rewriting VERSION would manufacture a diff for a seed that did not move.)"
    exit 0
    ;;
  2)
    echo "error: cannot determine seed freshness, so refusing to write one." >&2
    echo "  Reseeding with an out-of-date or missing compiler would commit its old codegen." >&2
    exit 1
    ;;
esac

# STALE: build/bootstrap.check.c is the fresh emission check-seed.sh just made.
mv build/bootstrap.check.c bootstrap/bootstrap.c

cat > bootstrap/VERSION <<META
vader_source_sha: $(git rev-parse HEAD)
vader_version:    $(grep -E '^export CLI_VERSION' vader/version/version.vader | head -1 | sed -E 's/.*"([^"]*)".*/\1/')
regenerated_at:   $(date -u +%Y-%m-%dT%H:%M:%SZ)
generator:        $VADER
META

echo "seed regenerated ($(wc -c < bootstrap/bootstrap.c | tr -d ' ') bytes)."
# The seed carries `-diff` in .gitattributes, so `git diff` reports it as binary;
# ask git for the two versions explicitly to see the actual change.
echo "review the diff vs the committed seed:"
echo "  diff <(git show HEAD:bootstrap/bootstrap.c) bootstrap/bootstrap.c"
echo "then commit the bump separately:"
echo "  git add bootstrap/bootstrap.c bootstrap/VERSION"
echo "  git commit -m 'chore(bootstrap): bump seed'"
