#!/usr/bin/env bash
# Is bootstrap/bootstrap.c what the current sources would emit?
#
# This script OWNS that question. `.githooks/pre-push`, `bootstrap/push.sh` (via
# regenerate.sh) and `bootstrap/verify.sh` all defer to it rather than re-emitting
# the seed themselves — otherwise the emission flags, the compiler lookup and the
# definition of "stale" live in four places and drift silently.
#
# Contract:
#   exit 0  FRESH    the committed seed matches what the sources would emit
#   exit 1  STALE    it does not ; a reseed is due
#   exit 2  UNKNOWN  could not tell (no usable compiler, or emission failed).
#           Deliberately distinct from STALE: "I don't know" must never be
#           reported as "it's broken", nor silently as "it's fine".
#   stdout  the resolved compiler path — but only when a compiler was actually
#           used, i.e. NOT on the git-only fast path below. Callers that go on to
#           write the seed need the exact binary that produced the verdict
#           (resolving it a second time is how the two disagree), so they pass
#           --full and are guaranteed a path.
#   stderr  the human-readable diagnosis (silenced by --quiet).
#
# On exit 1 the fresh emission is LEFT at build/bootstrap.check.c: that file is
# the new seed, and regenerate.sh moves it into place rather than paying for a
# second ~4 s compile of the identical input.
set -euo pipefail
cd "$(dirname "$0")/.."

# The source trees the seed can depend on, and the probe for their absence.
. "$(dirname "$0")/seed-sources.sh"

quiet=0
full=0
for arg in "$@"; do
  case "$arg" in
    -q|--quiet) quiet=1 ;;
    --full)     full=1 ;;
    *) echo "check-seed.sh: unknown argument: $arg (--quiet, --full)" >&2; exit 2 ;;
  esac
done
note() { [ "$quiet" = 1 ] || printf '%s\n' "$*" >&2; }

# ---- the source trees must still be where the list says --------------------

# Checked before anything else, because every test below silently passes on an
# absent path (see seed-sources.sh). UNKNOWN, not STALE: the seed may well be
# fine — what is broken is this script's ability to tell.
missing="$(seed_missing_dirs)"
if [ -n "$missing" ]; then
    note "seed source tree(s) missing: $missing"
    note "  bootstrap/seed-sources.sh lists them — update it if the layout moved."
    note "  cannot conclude on seed freshness."
    exit 2
fi

# ---- cheap path: prove freshness from git alone, no compiler ---------------

# Sound only while BOTH hold: nothing affecting the seed has been committed since
# the last reseed, AND the working tree matches HEAD for those same paths plus the
# seed itself. The second half matters because the real check below emits from the
# WORKING TREE, not from HEAD — without it, an uncommitted source edit (or a
# hand-edited seed) would be short-circuited away as "fresh".
if [ "$full" = 0 ]; then
    last_reseed="$(git rev-list -1 HEAD -- bootstrap/bootstrap.c 2>/dev/null || true)"
    if [ -n "$last_reseed" ] &&
       git diff --quiet HEAD -- $SEED_SOURCE_DIRS bootstrap/bootstrap.c 2>/dev/null &&
       [ -z "$(git diff --name-only "$last_reseed" HEAD -- $SEED_SOURCE_DIRS)" ]; then
        note "seed is fresh (nothing affecting it changed since the last reseed)."
        exit 0
    fi
fi

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
if [ ! -x "$VADER" ]; then
    note "$VADER is not an executable — cannot check seed freshness."
    exit 2
fi

# A compiler older than the sources would compare its own stale output against
# itself and report FRESH — a self-consistent lie, and the one answer that must
# never be given. `bun run build` (bootstrap/build.sh) rebuilds ./build/vader from
# the current tree, which is what makes the check mean anything.
if [ -n "$(find $SEED_SOURCE_DIRS -name '*.vader' -newer "$VADER" -print -quit)" ]; then
    note "$VADER is older than the .vader sources — cannot conclude on seed freshness."
    note "  rebuild it first:  bun run build"
    exit 2
fi

# ---- re-emit and compare --------------------------------------------------

# `--release` is what keeps `#line` directives out of the seed. This is the ONLY
# place the emission is spelled out, so it cannot drift against the writer.
mkdir -p build
if ! "$VADER" build --release --target=c --out=build/bootstrap.check.c \
       vader/bootstrap/bootstrap.vader >/dev/null 2>&1; then
    note "re-emitting the seed failed — cannot check freshness."
    exit 2
fi

if cmp -s build/bootstrap.check.c bootstrap/bootstrap.c; then
    rm -f build/bootstrap.check.c
    note "seed is fresh."
    printf '%s\n' "$VADER"
    exit 0
fi

note "seed is STALE — bootstrap/bootstrap.c no longer matches bootstrap.vader."
note "  the fresh emission is at build/bootstrap.check.c."
printf '%s\n' "$VADER"
exit 1
