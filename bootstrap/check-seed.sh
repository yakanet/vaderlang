#!/usr/bin/env bash
# Is bootstrap/bootstrap.c what the current sources would emit?
#
# Exit codes — callers branch on these, so they are the contract:
#   0  FRESH    the committed seed matches a fresh re-emission
#   1  STALE    it does not ; a reseed is due
#   2  UNKNOWN  could not tell (no usable compiler, or emission failed).
#               Deliberately distinct from STALE: "I don't know" must never be
#               reported as "it's broken", nor silently as "it's fine".
#
# Split out of .githooks/pre-push and bootstrap/push.sh so exactly one place
# knows how to answer the question, and so it can be run on its own.
set -euo pipefail
cd "$(dirname "$0")/.."

quiet=0
for arg in "$@"; do
  case "$arg" in
    -q|--quiet) quiet=1 ;;
    *) echo "check-seed.sh: unknown argument: $arg (only --quiet is supported)" >&2; exit 2 ;;
  esac
done
note() { [ "$quiet" = 1 ] || printf '%s\n' "$*" >&2; }

# ---- locate a compiler ----------------------------------------------------

VADER="${VADER:-}"
if [ -z "$VADER" ]; then
  if [ -x ./build/vader ]; then
    VADER=./build/vader
  elif command -v vader >/dev/null 2>&1; then
    VADER="$(command -v vader)"
  fi
fi
if [ -z "$VADER" ]; then
  note "no vader binary (./build/vader or on PATH) — cannot check seed freshness."
  exit 2
fi
# An explicit $VADER that isn't runnable deserves its own message — otherwise it
# surfaces further down as a confusing "re-emitting the seed failed".
if [ ! -x "$VADER" ]; then
  note "$VADER is not an executable — cannot check seed freshness."
  exit 2
fi

# A compiler older than the sources would compare its own stale output against
# itself and report FRESH — a self-consistent lie, and the one answer that must
# never be given. `bun run build` (bootstrap/build.sh) rebuilds ./build/vader
# from the current tree, which is what makes the check meaningful.
if [ -n "$(find vader stdlib -name '*.vader' -newer "$VADER" -print -quit 2>/dev/null)" ]; then
  note "$VADER is older than the .vader sources — cannot conclude on seed freshness."
  note "  rebuild it first:  bun run build"
  exit 2
fi

# ---- re-emit and compare --------------------------------------------------

# The flags MUST match bootstrap/regenerate.sh exactly — `--release` is what
# keeps `#line` directives out of the seed, and emitting with a different set
# here would report STALE forever.
mkdir -p build
if ! "$VADER" build --release --target=c --out=build/bootstrap.check.c \
       vader/bootstrap/bootstrap.vader >/dev/null 2>&1; then
  note "re-emitting the seed failed — cannot check freshness."
  exit 2
fi

if cmp -s build/bootstrap.check.c bootstrap/bootstrap.c; then
  note "seed is fresh."
  exit 0
fi

note "seed is STALE — bootstrap/bootstrap.c no longer matches bootstrap.vader."
note "  the fresh emission is at build/bootstrap.check.c if you want to diff it."
exit 1
