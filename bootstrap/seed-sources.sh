#!/usr/bin/env bash
# The source trees the emitted seed can depend on — the SINGLE definition.
#
# Deliberately BROADER than bootstrap.vader's real import closure: a
# hand-maintained closure list would rot the day an import changes, and a false
# FRESH is the one answer a seed check must never give.
#
# Sourced by bootstrap/check-seed.sh and bootstrap/regenerate.sh. Anything that
# reasons about seed freshness reads the list from here instead of re-typing it,
# because re-typing is how the checker and the writer drift apart.
SEED_SOURCE_DIRS="vader/ stdlib/ runtime/c/"

# The subset of SEED_SOURCE_DIRS that no longer exists, space-separated; empty
# when the layout is intact.
#
# Load-bearing rather than defensive noise. Every freshness test above is a
# no-op on a path that is absent: `git diff --quiet HEAD -- gone/` exits 0, and
# `find gone/ -name '*.vader'` prints nothing while writing to stderr. So moving
# or renaming a source tree makes each test answer "nothing changed" with no
# source left to check — the self-consistent lie, in its worst form. Callers
# must translate a non-empty result into UNKNOWN, never into FRESH.
seed_missing_dirs() {
    local missing="" d
    for d in $SEED_SOURCE_DIRS; do
        [ -d "$d" ] || missing="$missing $d"
    done
    printf '%s' "${missing# }"
}
