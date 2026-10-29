#!/usr/bin/env bash
# tools/ci/release-version.sh: the version a release takes, from what the
# release workflow was asked for.
#
#   tools/ci/release-version.sh <patch | minor | major | X.Y.Z>
#
# Prints `X.Y.Z`. A keyword bumps the latest `vX.Y.Z` tag, so the first release
# names its number. The version must be newer than that tag.
set -euo pipefail

asked="${1:?usage: release-version.sh <patch | minor | major | X.Y.Z>}"
latest="$(git tag --list 'v*' | grep -E '^v[0-9]+\.[0-9]+\.[0-9]+$' | sort -V | tail -1 || true)"

case "$asked" in
  patch|minor|major)
    if [ -z "$latest" ]; then
      echo "no release yet: name the first version (e.g. 0.1.0)" >&2
      exit 1
    fi
    IFS=. read -r major minor patch <<< "${latest#v}"
    case "$asked" in
      major) version="$((major + 1)).0.0" ;;
      minor) version="$major.$((minor + 1)).0" ;;
      patch) version="$major.$minor.$((patch + 1))" ;;
    esac
    ;;
  *)
    if ! [[ "$asked" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
      echo "not a version: $asked (patch, minor, major or X.Y.Z)" >&2
      exit 1
    fi
    version="$asked"
    ;;
esac

if [ -n "$latest" ] && [ "$(printf '%s\n%s\n' "${latest#v}" "$version" | sort -V | head -1)" = "$version" ]; then
  echo "$version is not newer than the latest release, $latest" >&2
  exit 1
fi

echo "$version"
