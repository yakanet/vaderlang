#!/usr/bin/env bash
# Regenerate bootstrap/bootstrap.c.gz from vader/bootstrap/bootstrap.vader,
# using an existing `vader` binary (on PATH or ./build/vader). The seed is the
# gzip-compressed C of the build-only entrypoint; see docs/BOOTSTRAP.md
# § "Seed lifecycle management".
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

mkdir -p build
"$VADER" build vader/bootstrap/bootstrap.vader --target=c --out=build/bootstrap.c
gzip -9 -c build/bootstrap.c > bootstrap/bootstrap.c.gz

cat > bootstrap/VERSION <<META
vader_source_sha: $(git rev-parse HEAD)
vader_version:    $(grep -E '^export CLI_VERSION' vader/version/version.vader | head -1 | sed -E 's/.*"([^"]*)".*/\1/')
regenerated_at:   $(date -u +%Y-%m-%dT%H:%M:%SZ)
generator:        $VADER
META

echo "seed regenerated ($(wc -c < bootstrap/bootstrap.c.gz | tr -d ' ') bytes gzipped)."
echo "review the decompressed diff vs the committed seed:"
echo "  diff <(git show HEAD:bootstrap/bootstrap.c.gz | gunzip -c) build/bootstrap.c"
echo "then commit the bump separately:"
echo "  git add bootstrap/bootstrap.c.gz bootstrap/VERSION"
echo "  git commit -m 'chore(bootstrap): bump seed'"
