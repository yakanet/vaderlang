#!/usr/bin/env bash
# The committed C seed's lifecycle — one script, because it is one artefact.
#
#   bootstrap/seed.sh check [--quiet] [--full]   is bootstrap/seed/ what the sources emit?
#   bootstrap/seed.sh regenerate                 write a new one
#   bootstrap/seed.sh push [git push args…]      reseed, commit the bump, push
#
# These three were four separate files, and the split is what let them drift: the
# list of directories the seed depends on declared itself "the single definition"
# and was re-typed twice anyway — once in a sibling, once inside its own file with
# a directory missing. A shared constant plus a shared function between four
# scripts wants to be one script, not a fifth file for them to source.
#
# `check` OWNS the freshness question. `regenerate`, `push`, bootstrap/verify.sh
# and .githooks/pre-push all defer to it rather than re-emitting the seed
# themselves — otherwise the emission flags, the compiler lookup and the
# definition of "stale" live in four places again.
#
# CHECK CONTRACT:
#   exit 0  FRESH    the committed seed matches what the sources would emit
#   exit 1  STALE    it does not ; a reseed is due
#   exit 2  UNKNOWN  could not tell (no usable compiler, a source tree missing,
#           or emission failed). Deliberately distinct from STALE: "I don't know"
#           must never be reported as "it's broken", nor silently as "it's fine".
#   stdout  the resolved compiler path — but only when a compiler was actually
#           used, i.e. NOT on the git-only fast path. Callers that go on to write
#           the seed need the exact binary that produced the verdict (resolving it
#           a second time is how the two disagree), so they pass --full and are
#           guaranteed a path.
#   stderr  the human-readable diagnosis (silenced by --quiet).
#
# On exit 1 the fresh emission is LEFT at build/seed.check/: that tree IS
# the new seed, and `regenerate` moves it into place rather than paying for a
# second ~4 s compile of the identical input.
set -euo pipefail

cd "$(dirname "$0")/.."

if [ -t 1 ]; then b='\033[1m'; g='\033[1;32m'; r='\033[0m'; else b=''; g=''; r=''; fi
step() { printf '%b==>%b %s\n' "$b" "$r" "$*"; }

# ---- what the seed depends on ---------------------------------------------

# Every source tree the emitted seed can depend on. Deliberately BROADER than
# bootstrap.vader's real import closure — a hand-maintained closure list would rot
# the day an import changes, and a false FRESH is the one answer this must never
# give.
SEED_SOURCE_DIRS="vader/ lib/ runtime/c/"

# Every target that has a backend. `wasi-wasm32` and `browser-wasm32` are out:
# emitting for a platform nothing can compile does not make the seed more
# portable, and it makes every `@target` group answer for a case that cannot be
# written yet — a write syscall needs `fd_write` and an iovec array on WASI, and
# has no meaning at all in a browser. They come back with the WASM emitter.
# One arch per OS: what lands in a per-target directory is chosen by `@target`,
# whose granularity is the OS and never the arch, so a second arch of the same OS
# emits the same bytes and needs no seed of its own — `bootstrap/build.sh` and
# `build.ps1` fall back to the OS sibling, and say so. Cross-compiling to the
# others stays available through `--target`; only the seed is narrower.
SEED_TARGETS="darwin-arm64,linux-x86_64,windows-x86_64"

# The subset of SEED_SOURCE_DIRS that no longer exists, space-separated; empty
# when the layout is intact.
#
# Load-bearing rather than defensive noise. Every freshness test below is a no-op
# on a path that is absent: `git diff --quiet HEAD -- gone/` exits 0, and `find
# gone/ -name '*.vader'` prints nothing while writing to stderr. So moving or
# renaming a source tree makes each test answer "nothing changed" with no source
# left to check — the self-consistent lie, in its worst form.
seed_missing_dirs() {
    local missing="" d
    for d in $SEED_SOURCE_DIRS; do
        [ -d "$d" ] || missing="$missing $d"
    done
    printf '%s' "${missing# }"
}

# ---- check ----------------------------------------------------------------

cmd_check() {
    local quiet=0 full=0 arg
    for arg in "$@"; do
        case "$arg" in
            -q|--quiet) quiet=1 ;;
            --full)     full=1 ;;
            *) echo "seed.sh check: unknown argument: $arg (--quiet, --full)" >&2; exit 2 ;;
        esac
    done
    note() { [ "$quiet" = 1 ] || printf '%s\n' "$*" >&2; }

    # The source trees must still be where the list says. Checked before anything
    # else, because every test after this one silently passes on an absent path.
    # UNKNOWN, not STALE: the seed may well be fine — what is broken is this
    # script's ability to tell.
    local missing
    missing="$(seed_missing_dirs)"
    if [ -n "$missing" ]; then
        note "seed source tree(s) missing: $missing"
        note "  SEED_SOURCE_DIRS in bootstrap/seed.sh lists them — update it if the layout moved."
        note "  cannot conclude on seed freshness."
        exit 2
    fi

    # Cheap path: prove freshness from git alone, no compiler. Sound only while
    # BOTH hold: nothing affecting the seed has been committed since the last
    # reseed, AND the working tree matches HEAD for those same paths plus the seed
    # itself. The second half matters because the real check below emits from the
    # WORKING TREE, not from HEAD — without it, an uncommitted source edit (or a
    # hand-edited seed) would be short-circuited away as "fresh".
    #
    # `status --porcelain` and not `diff --quiet HEAD`: only the former reports an
    # UNTRACKED file, and a new `.vader` is exactly the edit that changes the seed
    # while leaving every diff clean. It subsumes the diff, so one process covers
    # both.
    if [ "$full" = 0 ]; then
        local last_reseed
        last_reseed="$(git rev-list -1 HEAD -- bootstrap/seed 2>/dev/null || true)"
        if [ -n "$last_reseed" ] &&
           [ -z "$(git status --porcelain -- $SEED_SOURCE_DIRS bootstrap/seed)" ] &&
           [ -z "$(git diff --name-only "$last_reseed" HEAD -- $SEED_SOURCE_DIRS)" ]; then
            note "seed is fresh (nothing affecting it changed since the last reseed)."
            exit 0
        fi
    fi

    local VADER="${VADER:-}"
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
    # never be given. `bun run build` (bootstrap/build.sh) rebuilds ./build/vader
    # from the current tree, which is what makes the check mean anything.
    if [ -n "$(find $SEED_SOURCE_DIRS -name '*.vader' -newer "$VADER" -print -quit)" ]; then
        note "$VADER is older than the .vader sources — cannot conclude on seed freshness."
        note "  rebuild it first:  bun run build"
        exit 2
    fi

    # `--release` keeps `#line` out of the seed, and `--seed-targets` emits every
    # target against ONE atom table so the units that do not depend on the target
    # come out byte-identical and are stored once. This is the ONLY place the
    # emission is spelled out, so it cannot drift against the writer.
    rm -rf build/seed.check
    mkdir -p build/seed.check
    if ! "$VADER" build --release --emit=c --seed-targets="$SEED_TARGETS" \
           --out=build/seed.check/bootstrap \
           vader/bootstrap/bootstrap.vader >/dev/null 2>&1; then
        note "re-emitting the seed failed — cannot check freshness."
        exit 2
    fi

    # `diff -r` and not a per-file loop: it also catches a file that EXISTS on one
    # side only, which is what a new per-target unit looks like the first time
    # `@target` reaches the closure.
    if diff -r -q build/seed.check bootstrap/seed >/dev/null 2>&1; then
        rm -rf build/seed.check
        note "seed is fresh."
        printf '%s\n' "$VADER"
        exit 0
    fi

    note "seed is STALE — bootstrap/seed/ no longer matches bootstrap.vader."
    note "  the fresh emission is at build/seed.check/."
    printf '%s\n' "$VADER"
    exit 1
}

# ---- regenerate -----------------------------------------------------------

# Regenerate bootstrap/seed/ from vader/bootstrap/bootstrap.vader, using an
# existing `vader` binary (on PATH or ./build/vader). The seed is the plain C of
# the build-only entrypoint — stored uncompressed so git can delta successive
# reseeds; see docs/BOOTSTRAP.md § "Seed lifecycle management".
cmd_regenerate() {
    [ "$#" -eq 0 ] || { echo "seed.sh regenerate: takes no arguments" >&2; exit 2; }

    # Ask `check` rather than re-emitting: it prints the compiler it used on stdout
    # and the diagnosis on stderr, and --full skips its git short-circuit since a
    # reseed must compare real output. One compile for both the verdict and the
    # emission, and the flags cannot drift between checker and writer.
    #
    # FIRST, before the clean-tree test below: `check` already refuses when a seed
    # source tree is missing, and that case has to be caught before a test that
    # would pass vacuously on an absent path.
    #
    # A function in `$( )` runs in a subshell, so its `exit` reports as the
    # substitution's status instead of ending this script.
    local VADER verdict
    set +e
    VADER="$(cmd_check --full)"
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

    # Require a clean working tree across ALL of them so the recorded SHA is
    # meaningful: the emission reads the working tree, and VERSION records HEAD, so
    # an uncommitted edit anywhere in the seed's sources makes the two disagree.
    # vader/ alone was not enough — the seed embeds the stdlib it was compiled with.
    if ! git diff-index --quiet HEAD -- $SEED_SOURCE_DIRS; then
        echo "error: $SEED_SOURCE_DIRS has uncommitted changes — commit first" >&2
        exit 1
    fi

    # Corruption gate. The compiler can emit C that does not even parse: a live
    # string collected out from under its handle writes `length` bytes of recycled
    # memory, so an expression comes out as NUL bytes of exactly its own width
    # (`__vret = vader_ref_box(t3)` → `__vret = ` + 18 NULs). Seen on 2026-08-30
    # under ubuntu-24.04 / gcc 13.3.0, on ONE of the eight per-target emissions of
    # a single run — see .claude/plans/2026-08-30-gc-observable-conservative-scan.md.
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
    corrupt="$(find build/seed.check -type f \( -name '*.c' -o -name '*.h' \) -exec sh -c '
        for f do
            tr -d "\000" < "$f" | cmp -s - "$f" || printf "%s\n" "$f"
        done' sh {} +)"
    if [ -n "$corrupt" ]; then
        echo "error: the fresh emission contains NUL bytes — refusing to write a corrupt seed." >&2
        echo "$corrupt" | sed 's/^/  /' >&2
        echo "  Emitted C is text; a NUL means a string was collected while still live." >&2
        echo "  Do NOT retry until it passes. Re-run under VADER_GC_CHECK_BOX=1 — it traps upstream." >&2
        echo "  See .claude/plans/2026-08-30-gc-observable-conservative-scan.md" >&2
        exit 1
    fi

    # STALE: build/seed.check/ is the fresh emission `check` just made. Replace
    # the directory wholesale — a per-file copy would leave behind a unit that
    # the new emission no longer produces, and a stale unit still compiles.
    rm -rf bootstrap/seed
    mv build/seed.check bootstrap/seed

    cat > bootstrap/VERSION <<META
vader_source_sha: $(git rev-parse HEAD)
vader_version:    $(grep -E '^export CLI_VERSION' vader/version/version.vader | head -1 | sed -E 's/.*"([^"]*)".*/\1/')
regenerated_at:   $(date -u +%Y-%m-%dT%H:%M:%SZ)
generator:        $VADER
META

    shared=$(ls bootstrap/seed/bootstrap.split.g.c bootstrap/seed/bootstrap-*.c 2>/dev/null | wc -l | tr -d ' ')
    per_target=$(find bootstrap/seed -mindepth 2 -name '*.c' 2>/dev/null | wc -l | tr -d ' ')
    echo "seed regenerated ($(du -sh bootstrap/seed | cut -f1), ${shared} shared unit(s), ${per_target} per-target)."
    echo "review the diff vs the committed seed:"
    echo "  git diff --stat bootstrap/seed"
    echo "then commit the bump separately:"
    echo "  git add bootstrap/seed bootstrap/VERSION"
    echo "  git commit -m 'chore(bootstrap): bump seed'"
}

# ---- push -----------------------------------------------------------------

# Push, reseeding first if the committed C seed is stale.
#
# The one-command happy path for the "one reseed per push" cadence
# (docs/BOOTSTRAP.md § "Who bumps"). .githooks/pre-push is the safety net for a
# plain `git push`; this is what keeps that net from ever firing.
#
# Every argument is forwarded to `git push`, so `seed.sh push -u origin main`
# works as expected.
cmd_push() {
    # `regenerate` is a no-op when the seed is already fresh, and refuses outright
    # when it cannot tell — the asymmetry that matters here: unlike the pre-push
    # hook, which only *checks* and tolerates not knowing, this path is about to
    # WRITE the committed artefact, so an unusable compiler is a hard stop. Its own
    # guards carry the messages, so there is nothing to pre-check here.
    step "Reseeding if the committed seed is stale"
    # Parenthesised: `regenerate` exits 0 on "already fresh", and a subshell keeps
    # that from ending the push.
    ( cmd_regenerate )

    if git diff --quiet -- bootstrap/seed bootstrap/VERSION; then
        step "Nothing to commit"
    else
        step "Committing the bump"
        git commit -q -m 'chore(bootstrap): bump seed' \
          bootstrap/seed bootstrap/VERSION
        git --no-pager log --oneline -1
    fi

    step "Pushing"
    git push "$@"
    printf '%b==> done%b\n' "$g" "$r"
}

# ---- dispatch -------------------------------------------------------------

usage() {
    cat >&2 <<'USAGE'
usage: bootstrap/seed.sh <command> [args]

  check [--quiet] [--full]   is bootstrap.c what the sources would emit?
                             exit 0 fresh / 1 stale / 2 cannot tell
  regenerate                 write a new seed (requires a clean tree)
  push [git push args…]      reseed, commit the bump, then push
USAGE
    exit 2
}

[ "$#" -ge 1 ] || usage
cmd="$1"; shift
case "$cmd" in
    check)      cmd_check "$@" ;;
    regenerate) cmd_regenerate "$@" ;;
    push)       cmd_push "$@" ;;
    -h|--help)  usage ;;
    *) echo "seed.sh: unknown command: $cmd" >&2; usage ;;
esac
