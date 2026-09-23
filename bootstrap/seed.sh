#!/usr/bin/env bash
# The committed C seed's lifecycle — one script, because it is one artefact.
#
#   bootstrap/seed.sh check [--quiet]   does the committed seed still bootstrap HEAD?
#   bootstrap/seed.sh regenerate        write a new one
#
# The seed is a bootstrap tool: it only has to be able to build the current tree,
# not to be what the current tree would emit. `build.sh` ships stage2 — the tree
# compiled by the tree — so the seed's age never reaches the shipped binary, and a
# reseed is due only when the seed stops working. See docs/BOOTSTRAP.md § "Seed
# lifecycle management".
#
# `check` OWNS the viability question; .githooks/pre-push defers to it. `verify.sh`
# is what answers it — the same gate the CI `fixed-point` job runs — so a seed that
# builds the tree but breaks the fixed point is not viable either.
#
# NEITHER answers whether the compiler is CORRECT. `verify.sh` compares stage1 to
# stage2, and a compiler that mis-compiles itself stably passes that: both stages
# are wrong the same way, which is what a fixed point preserves. The suite is the
# check, and a reseed changes the stage0 that builds the binary under test — so it
# has to run AFTER.
#
# CHECK CONTRACT:
#   exit 0  VIABLE   the committed seed, with HEAD's runtime/c, bootstraps HEAD and
#                    `verify.sh` passes on it
#   exit 1  BROKEN   it does not. Usually a reseed is due; the log says which step
#                    failed, and a fixed-point break can also be the tree's own
#   exit 2  UNKNOWN  could not tell (no C compiler, a source tree missing, not a git
#           checkout). Deliberately distinct from BROKEN: "I don't know" must never
#           be reported as "it's broken", nor silently as "it's fine".
#   stderr  the human-readable diagnosis (silenced by --quiet), and on BROKEN the
#           tail of the `verify.sh` log.
set -euo pipefail

cd "$(dirname "$0")/.."

# ---- what the seed depends on ---------------------------------------------

# Every source tree the emitted seed can depend on. Deliberately BROADER than
# bootstrap.vader's real import closure — a hand-maintained closure list would rot
# the day an import changes, and a seed written from a stale compiler, or a
# viability verdict reused for a tree that moved, is the failure this must never
# allow.
SEED_SOURCE_DIRS="vader/ lib/ runtime/c/"

# Every target that has a backend. `wasi-wasm32` and `browser-wasm32` are out:
# emitting for a platform nothing can compile does not make the seed more
# portable, and it makes every `@target` group answer for a case that cannot be
# written yet — a write syscall needs `fd_write` and an iovec array on WASI, and
# has no meaning at all in a browser. They come back with the WASM emitter.
# One arch per OS. What lands in a per-target directory is chosen by `@target`,
# whose granularity is the OS and never the arch, so a second arch of the same OS
# emits the same bytes and needs no seed of its own: `bootstrap/build.sh` and
# `build.ps1` fall back to the OS sibling, and say so on the way past. Adding an
# arch here would store a second copy of bytes that are already committed.
# Cross-compiling stays available through `--target`; only the seed is narrower.
SEED_TARGETS="darwin-arm64,linux-x86_64,windows-x86_64"

# The subset of SEED_SOURCE_DIRS that no longer exists, space-separated; empty
# when the layout is intact.
#
# Load-bearing rather than defensive noise. The tests below are no-ops on a path
# that is absent: `git diff-index --quiet HEAD -- gone/` exits 0, and `find gone/
# -name '*.vader'` prints nothing while writing to stderr. So moving or renaming a
# source tree makes each test answer "nothing changed" with no source left to
# check — the self-consistent lie, in its worst form.
seed_missing_dirs() {
    local missing="" d
    for d in $SEED_SOURCE_DIRS; do
        [ -d "$d" ] || missing="$missing $d"
    done
    printf '%s' "${missing# }"
}

# ---- check ----------------------------------------------------------------

# What the verdict reads at HEAD, beyond the seed's sources: the seed itself, the
# two scripts that run, and the snippet `verify.sh` emits in debug mode. Anything
# else under `bootstrap/` (README, build.ps1, VERSION) cannot change the verdict.
VIABILITY_EXTRA_PATHS="bootstrap/seed bootstrap/build.sh bootstrap/verify.sh tests/snippets/return_42"

# The git object ids of every path the verdict depends on, at HEAD. Two commits
# with the same key get the same verdict. Empty when any path is missing: one
# `rev-parse` fails as a whole, so no partial key can match a stamp.
viability_key() {
    local d specs=""
    for d in $SEED_SOURCE_DIRS $VIABILITY_EXTRA_PATHS; do
        specs="$specs HEAD:${d%/}"
    done
    git rev-parse $specs 2>/dev/null | tr '\n' ' ' || true
}

cmd_check() {
    local quiet=0 arg
    for arg in "$@"; do
        case "$arg" in
            -q|--quiet) quiet=1 ;;
            *) echo "seed.sh check: unknown argument: $arg (--quiet)" >&2; exit 2 ;;
        esac
    done
    note() { [ "$quiet" = 1 ] || printf '%s\n' "$*" >&2; }

    local key
    key="$(viability_key)"
    if [ -z "$key" ]; then
        note "cannot read HEAD's trees ($SEED_SOURCE_DIRS $VIABILITY_EXTRA_PATHS)."
        note "  not a git checkout, or the layout moved — update the lists in bootstrap/seed.sh."
        note "  cannot conclude on seed viability."
        exit 2
    fi

    # Fast path: a previous run found these exact trees viable. One key per line,
    # so switching between branches does not re-run a verdict already given. The
    # stamp lives under build/, so a fresh clone pays for one full run.
    if [ -f build/seed.viable ] && grep -qxF "$key" build/seed.viable; then
        note "seed is viable (these trees already passed)."
        exit 0
    fi

    # HEAD, not the working tree: the hook vets what is being pushed, and an
    # uncommitted edit must neither fail nor pass it. The export also keeps the
    # run away from the checkout's build/vader.
    local root=build/seed.viability
    rm -rf "$root"
    mkdir -p "$root"
    if ! git archive HEAD | tar -x -C "$root"; then
        note "exporting HEAD failed — cannot check seed viability."
        exit 2
    fi

    note "checking that the seed bootstraps HEAD (bootstrap/verify.sh, ~1 min)…"
    local log="$PWD/build/seed.viability.log" verdict
    set +e
    ( cd "$root" && bash bootstrap/verify.sh ) >"$log" 2>&1
    verdict=$?
    set -e

    case "$verdict" in
      0)
        rm -rf "$root"
        printf '%s\n' "$key" >> build/seed.viable
        note "seed is viable."
        exit 0
        ;;
      2)
        note "verify.sh could not conclude — the seed may be fine. Log: $log"
        [ "$quiet" = 1 ] || tail -20 "$log" >&2
        exit 2
        ;;
    esac
    note "HEAD does not pass verify.sh from its own seed (exit $verdict). Log: $log"
    [ "$quiet" = 1 ] || tail -30 "$log" >&2
    exit 1
}

# ---- regenerate -----------------------------------------------------------

# Regenerate bootstrap/seed/ from vader/bootstrap/bootstrap.vader, using an
# existing `vader` binary (./build/vader, else on PATH). The seed is the plain C
# of the build-only entrypoint — stored uncompressed so git can delta successive
# reseeds; see docs/BOOTSTRAP.md § "Seed lifecycle management".
cmd_regenerate() {
    [ "$#" -eq 0 ] || { echo "seed.sh regenerate: takes no arguments" >&2; exit 2; }

    local missing
    missing="$(seed_missing_dirs)"
    if [ -n "$missing" ]; then
        echo "error: seed source tree(s) missing: $missing — refusing to write a seed." >&2
        exit 1
    fi

    local VADER="${VADER:-}"
    if [ -z "$VADER" ]; then
        if [ -x ./build/vader ]; then
            VADER=./build/vader
        elif command -v vader >/dev/null 2>&1; then
            VADER="$(command -v vader)"
        fi
    fi
    if [ -z "$VADER" ] || [ ! -x "$VADER" ]; then
        echo "error: no vader binary (./build/vader or on PATH) — refusing to write a seed." >&2
        exit 1
    fi

    # Require a clean working tree across ALL of them so the recorded SHA is
    # meaningful: the emission reads the working tree, and VERSION records HEAD, so
    # an uncommitted edit anywhere in the seed's sources makes the two disagree.
    # vader/ alone was not enough — the seed embeds the stdlib it was compiled with.
    if ! git diff-index --quiet HEAD -- $SEED_SOURCE_DIRS; then
        echo "error: $SEED_SOURCE_DIRS has uncommitted changes — commit first" >&2
        exit 1
    fi

    # A compiler older than the sources would write ITS codegen into the seed, and
    # nothing downstream would notice: the seed only has to bootstrap. So build
    # the tree with it first, and emit from the result. This is also the way out
    # when the committed seed no longer bootstraps: `build.sh` cannot produce a
    # compiler then, but the last one that built is far newer than the seed and
    # usually still compiles the tree.
    if [ -n "$(find $SEED_SOURCE_DIRS -name '*.vader' -newer "$VADER" -print -quit)" ]; then
        echo "$VADER is older than the .vader sources — building the tree with it first."
        if ! "$VADER" build --release --emit=executable --out=build/vader.next vader/cli/main.vader; then
            echo "error: $VADER cannot build the tree — refusing to write a seed." >&2
            exit 1
        fi
        mv build/vader.next build/vader
        VADER=./build/vader
    fi

    # `--release` keeps `#line` out of the seed, and `--seed-targets` emits every
    # target against ONE atom table so the units that do not depend on the target
    # come out byte-identical and are stored once. This is the ONLY place the
    # emission is spelled out.
    rm -rf build/seed.new
    mkdir -p build/seed.new
    if ! "$VADER" build --release --emit=c --seed-targets="$SEED_TARGETS" \
           --out=build/seed.new/bootstrap \
           vader/bootstrap/bootstrap.vader >/dev/null; then
        echo "error: emitting the seed failed." >&2
        exit 1
    fi

    # `diff -r` and not a per-file loop: it also catches a file that EXISTS on one
    # side only, which is what a new per-target unit looks like the first time
    # `@target` reaches the closure.
    if diff -r -q build/seed.new bootstrap/seed >/dev/null 2>&1; then
        rm -rf build/seed.new
        echo "seed already byte-identical — nothing to commit (VERSION left alone)."
        exit 0
    fi

    # Corruption gate. The compiler can emit C that does not even parse: a live
    # string collected out from under its handle writes `length` bytes of recycled
    # memory, so an expression comes out as NUL bytes of exactly its own width
    # (`__vret = vader_ref_box(t3)` → `__vret = ` + 18 NULs). Seen on 2026-08-30
    # under ubuntu-24.04 / gcc 13.3.0, on ONE of the eight per-target emissions of
    # a single run.
    #
    # Emitted C is text and never legitimately contains a NUL, so this costs one
    # grep and turns the worst outcome — committing a seed that cannot build, which
    # breaks the cold bootstrap for everyone — into a refusal. It is a canary for a
    # bug still open, not a fix: a corruption that lands on printable bytes walks
    # straight past it. When it fires, do NOT retry until it passes; re-run the
    # emission under `VADER_GC_CHECK_BOX=1`, which traps upstream of the damage.
    # `tr -d` then `cmp` and not `grep`: a NUL cannot survive command substitution,
    # and `grep -P '\x00'` is GNU-only — this pair is POSIX and behaves the same on
    # the BSD tools macOS ships.
    local corrupt
    corrupt="$(find build/seed.new -type f \( -name '*.c' -o -name '*.h' \) -exec sh -c '
        for f do
            tr -d "\000" < "$f" | cmp -s - "$f" || printf "%s\n" "$f"
        done' sh {} +)"
    if [ -n "$corrupt" ]; then
        echo "error: the fresh emission contains NUL bytes — refusing to write a corrupt seed." >&2
        echo "$corrupt" | sed 's/^/  /' >&2
        echo "  Emitted C is text; a NUL means a string was collected while still live." >&2
        echo "  Do NOT retry until it passes. Re-run under VADER_GC_CHECK_BOX=1 — it traps upstream." >&2
        exit 1
    fi

    # Replace the directory wholesale — a per-file copy would leave behind a unit that
    # the new emission no longer produces, and a stale unit still compiles.
    rm -rf bootstrap/seed
    mv build/seed.new bootstrap/seed

    cat > bootstrap/VERSION <<META
vader_source_sha: $(git rev-parse HEAD)
vader_version:    $(grep -E '^export CLI_VERSION' vader/version/version.vader | head -1 | sed -E 's/.*"([^"]*)".*/\1/')
regenerated_at:   $(date -u +%Y-%m-%dT%H:%M:%SZ)
generator:        $VADER
META

    shared=$(find bootstrap/seed -maxdepth 1 -name '*.c' | wc -l | tr -d ' ')
    per_target=$(find bootstrap/seed -mindepth 2 -name '*.c' 2>/dev/null | wc -l | tr -d ' ')
    echo "seed regenerated ($(du -sh bootstrap/seed | cut -f1), ${shared} shared unit(s), ${per_target} per-target)."
    echo "review the diff vs the committed seed:"
    echo "  git diff --stat bootstrap/seed"
    echo "RE-RUN THE SUITE before committing — this seed builds the stage0 that"
    echo "builds everything, so it changes the binary under test:"
    echo "  bun run build:cli && bun run test"
    echo "then commit the bump separately:"
    echo "  git add bootstrap/seed bootstrap/VERSION"
    echo "  git commit -m 'chore(bootstrap): bump seed'"
}

# ---- dispatch -------------------------------------------------------------

usage() {
    cat >&2 <<'USAGE'
usage: bootstrap/seed.sh <command> [args]

  check [--quiet]   does the committed seed still bootstrap HEAD?
                    exit 0 viable / 1 broken / 2 cannot tell
  regenerate        write a new seed (requires a clean tree)
USAGE
    exit 2
}

[ "$#" -ge 1 ] || usage
cmd="$1"; shift
case "$cmd" in
    check)      cmd_check "$@" ;;
    regenerate) cmd_regenerate "$@" ;;
    -h|--help)  usage ;;
    *) echo "seed.sh: unknown command: $cmd" >&2; usage ;;
esac
