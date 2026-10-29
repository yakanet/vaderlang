#!/usr/bin/env bash
# tools/ci/release-notes.sh: the notes of a release, in Markdown on stdout.
#
#   tools/ci/release-notes.sh <release tag>
#
# The commits since the previous `vX.Y.Z` tag, grouped by their
# conventional-commit type: breaking changes, features, fixes, performance,
# reverts, then the subjects that follow no convention. Other types (chore,
# refactor, test, docs...) are left out. The first release gets a line to
# replace by hand.
set -euo pipefail

release="${1:?usage: release-notes.sh <release tag>}"
previous="$(git describe --tags --abbrev=0 --match 'v[0-9]*' --exclude '*-*' "$release^" 2>/dev/null || true)"

if [ -z "$previous" ]; then
  echo "The first release of Vader."
  exit 0
fi

subjects="$(git log --no-merges --format='%s' "$previous..$release")"
scope='(\([^)]*\))?'

# section <title> <grep arguments...>
section() {
  local title="$1" lines
  shift
  lines="$(printf '%s\n' "$subjects" | grep "$@" || true)"
  if [ -n "$lines" ]; then
    printf '## %s\n\n' "$title"
    printf '%s\n' "$lines" | sed 's/^/- /'
    printf '\n'
  fi
}

section "Breaking changes" -E "^[a-z]+$scope!: "
section "Features" -E "^feat$scope: "
section "Fixes" -E "^fix$scope: "
section "Performance" -E "^perf$scope: "
section "Reverts" -E "^(revert$scope: |Revert \")"
section "Other changes" -vE "^[a-z]+$scope!?: |^Revert \""

if [ -n "${GITHUB_REPOSITORY:-}" ]; then
  printf 'Full list: https://github.com/%s/compare/%s...%s\n' "$GITHUB_REPOSITORY" "$previous" "$release"
fi
