#!/usr/bin/env bash
# Regenerate bootstrap/bootstrap.c from vader/bootstrap/bootstrap.vader, using
# an existing `vader` binary (on PATH or ./build/vader). The seed is the plain C
# of the build-only entrypoint — stored uncompressed so git can delta successive
# reseeds; see docs/BOOTSTRAP.md § "Seed lifecycle management".
set -euo pipefail
cd "$(dirname "$0")/.."

# Require a clean working tree on vader/ so the recorded SHA is meaningful.
if ! git diff-index --quiet HEAD -- vader/; then
  echo "error: vader/ has uncommitted changes — commit first" >&2
  exit 1
fi

# Need a `vader` binary carrying the wired `cmd_build --target=c`.
if ! command -v vader >/dev/null && [ ! -x ./build/vader ]; then
  echo "error: no vader binary available. Build one first:" >&2
  echo "  bootstrap/build.sh                 # from the committed C seed" >&2
  exit 1
fi
VADER="${VADER:-$(command -v vader || echo ./build/vader)}"

# --release keeps `#line` directives OUT of the seed (c-emit gates them on
# !release). The seed is a bootstrap artifact — stage0 is a throwaway -O0
# binary, so source line info in it is useless, while a populated debug table
# (Phase 0 of the DAP debugger) would otherwise bloat the committed seed with
# tens of thousands of `#line` lines and churn its diff on every source edit.
# For --target=c, --release ONLY drops `#line` (the bytecode optimiser is always
# on), so the seed content is otherwise identical to a debug build.
"$VADER" build --release --target=c --out=bootstrap/bootstrap.c vader/bootstrap/bootstrap.vader

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
