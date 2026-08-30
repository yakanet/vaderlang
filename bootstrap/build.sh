#!/usr/bin/env bash
# Build the full Vader compiler from the committed C seed — TWO stages:
#   seed   ─cc→                 build/stage0  (bootstrap compiler; emits C only)
#   stage0 ─emit C→ cc release→ build/vader   (= stage1, the shipped compiler)
#
# stage1 behaves exactly as a stage2 would — that is what `verify.sh` proves — and
# only its machine code comes from the seed's codegen instead of the tree's. The
# distance between the two is the seed's AGE, which `.githooks/pre-push` keeps at
# zero for anything published. `--three-stage` adds the extra round:
#   stage1 ─build native→  build/vader  (= stage2), with stage1 kept for comparison
# which is what `verify.sh` needs, since the fixed point compares the two.
#
# Needs only a C compiler — no Bun, no TS, no pre-existing vader binary.
# The C compiler defaults to `cc`; override with `CC=clang bootstrap/build.sh`. It
# is resolved to an absolute path and passed to stage1 via --cc, so the compiler
# stage1 spawns is exactly the one used here. stage0 is a throwaway built -O1
# (STAGE0_CFLAGS): -O0 compiles faster but it runs the heavy work, and -O1 wins the
# total by ~11 s. stage1 is built -O3+LTO in BOTH modes — under `--three-stage` it
# is a throwaway too, but `verify.sh` compares its emission against stage2's, and
# two binaries built differently do not answer the question that check asks.
# Pass --dist to also assemble a self-contained dist/vader-<os>-<arch>/ bundle
# (binary + lib/ + runtime/c). See docs/BOOTSTRAP.md.
set -euo pipefail
cd "$(dirname "$0")/.."

dist=0
three_stage=0
for arg in "$@"; do
  case "$arg" in
    --dist) dist=1 ;;
    --three-stage) three_stage=1 ;;
    *) echo "build.sh: unknown argument: $arg (--dist, --three-stage)" >&2; exit 2 ;;
  esac
done

CC_ABS="$(command -v "${CC:-cc}" || true)"
if [ -z "$CC_ABS" ]; then
  echo "build.sh: C compiler '${CC:-cc}' not found on PATH (set CC=...)" >&2
  exit 1
fi
STAGE0_CFLAGS="${STAGE0_CFLAGS:--O1}"
runtime="runtime/c/vader_runtime.c"

# Arena sizing is RAM-proportional (runtime/c/vader_runtime.c::vader_gc_init —
# old init + cap derived from physical RAM, single VADER_GC_RAM_PERCENT knob), so
# the bootstrap self-compiles at a saner initial size on any machine with no manual
# override. This used to pin VADER_GC_YOUNG_BYTES / VADER_GC_OLD_BYTES to avoid the
# default-256-MB-old GC thrash; the RAM model + auto-grow now handle that. Any
# VADER_GC_* value the caller exports still wins (advanced escape hatch).

if [ -t 1 ]; then b='\033[1m'; g='\033[1;32m'; r='\033[0m'; else b=''; g=''; r=''; fi
step() { printf '%b==>%b %s\n' "$b" "$r" "$*"; }

mkdir -p build

cc_jobs() {
    n=$(getconf _NPROCESSORS_ONLN 2>/dev/null) || n=""
    [ -n "$n" ] || n=$(nproc 2>/dev/null) || n=""
    [ -n "$n" ] || n=$(sysctl -n hw.ncpu 2>/dev/null) || n=""
    case "$n" in ''|*[!0-9]*|0) n=4 ;; esac
    echo "$n"
}
CC_JOBS="${CC_JOBS:-$(cc_jobs)}"
case "$CC_JOBS" in ''|*[!0-9]*|0) CC_JOBS=$(cc_jobs) ;; esac

# Release codegen policy, DUPLICATED from `vader/pipeline/emit.vader` — which
# calls itself its single source of truth, and is right to. The two-stage build
# hands `build/vader` to a `cc` this script drives, so the script has to know the
# policy; there is no compiler in the loop yet to ask. Keep the two in step: the
# flags, the toolchain probe and the import limit all live there.
release_cflags() {
    echo "-std=c11 -O3 -DNDEBUG -falign-functions=64"
}

cc_flavour() {
    banner=$("$CC_ABS" --version 2>/dev/null | tr '[:upper:]' '[:lower:]') || banner=""
    case "$banner" in
      *clang*) echo clang ;;
      *gcc*|*"free software foundation"*) echo gcc ;;
      *) echo unknown ;;
    esac
}

lto_compile_flags() {
    case "$(cc_flavour)" in
      clang) echo "-flto=thin" ;;
      gcc)   echo "-flto=auto" ;;
      *)     echo "" ;;
    esac
}

lto_link_flags() {
    case "$(cc_flavour)" in
      clang) echo "-flto=thin -O3 -Wl,-mllvm,-import-instr-limit=300" ;;
      gcc)   echo "-flto=auto -O3" ;;
      *)     echo "" ;;
    esac
}

compile_unit() {
    unit_log="$UNIT_OBJDIR/$(basename "$1" .c).cclog"
    if ! "$CC_ABS" $UNIT_CFLAGS -Iruntime/c -c "$1" -o "$UNIT_OBJDIR/$(basename "$1" .c).o" \
         >"$unit_log" 2>&1; then
        echo "cc failed on $1" >&2
        cat "$unit_log" >&2
        return 1
    fi
    if [ -s "$unit_log" ]; then
        cat "$unit_log" >&2
    fi
    rm -f "$unit_log"
    return 0
}
export -f compile_unit

cc_link_parallel() {
    UNIT_CFLAGS="$1"
    UNIT_OBJDIR="$2"
    unit_out="$3"
    unit_ldflags="$4"
    shift 4
    export CC_ABS UNIT_CFLAGS UNIT_OBJDIR
    printf '%s\n' "$@" \
      | xargs -P "$CC_JOBS" -I{} bash -c 'compile_unit "$@"' _ {}
    "$CC_ABS" $unit_ldflags -o "$unit_out" "$UNIT_OBJDIR"/*.o -lm
}

host_target() {
    case "$(uname -s)" in
      Darwin)  os=darwin ;;
      Linux)   os=linux ;;
      MINGW*|MSYS*|CYGWIN*) os=windows ;;
      *) echo "bootstrap/build.sh: unsupported OS $(uname -s)" >&2; exit 1 ;;
    esac
    case "$(uname -m)" in
      arm64|aarch64) arch=arm64 ;;
      x86_64|amd64)  arch=x86_64 ;;
      *) echo "bootstrap/build.sh: unsupported arch $(uname -m)" >&2; exit 1 ;;
    esac
    printf '%s-%s' "$os" "$arch"
}

# The seed is a SET: the units every target shares, plus the ones that differ
# for this host. A unit lands in the second group only when the targets actually
# emitted different bytes for it, so today there are none — the list is built by
# globbing rather than hardcoded, and starts working the day one appears.
HOST_TARGET="$(host_target)"
# `bootstrap-<module>.c` is shared; `bootstrap.<target>-<module>.c` belongs to
# one target. The two patterns cannot overlap — a shared unit has no dot after
# `bootstrap` — so the host's set is the union with the globals TU.
seed_shared=$(ls bootstrap/seed/bootstrap.split.g.c bootstrap/seed/bootstrap-*.c 2>/dev/null || true)
seed_host=$(ls bootstrap/seed/bootstrap."$HOST_TARGET"-*.c 2>/dev/null || true)
if [ -z "$seed_shared" ]; then
    echo "bootstrap/build.sh: no seed under bootstrap/seed/ — run bootstrap/seed.sh regenerate" >&2
    exit 1
fi

# Two stages by default: stage1 is built `--release` and IS the shipped compiler.
# It behaves exactly as stage2 would — `verify.sh` is what proves that — and only
# its machine code comes from the seed's codegen rather than from the tree's. The
# gap between the two is the seed's AGE, which the pre-push hook keeps at zero.
# `--three-stage` adds the round `verify.sh` needs to compare the two ; only the
# OUTPUT PATH differs between the modes.
#
# stage1 carries the release flags in BOTH modes, and that is load-bearing rather
# than tidy. It was `-O1` under `--three-stage` (stage1 is a throwaway there, and
# skipping -O3 saved ~11 s), which made `verify.sh` compare an -O1 binary's
# emission against an -O3+LTO binary's — folding "does the compiler behave the
# same at either -O level" into a check that only claims to test the fixed point.
# On 2026-08-30 that reported a fixed-point failure on linux-x86_64 which was
# nothing of the sort: with matched flags the fixed point holds there, byte for
# byte. The mismatch was still telling the truth about something — the SAME C at
# two -O levels really does emit differently on x86_64, which is UB in the
# compiler and is tracked separately. A gate must test one thing.
if [ "$three_stage" = 1 ]; then
    stages=3
    stage1_out=build/stage1
else
    stages=2
    stage1_out=build/vader
fi
stage1_cflags="$(release_cflags) $(lto_compile_flags)"
stage1_ldflags="$(lto_link_flags)"

step "[1/$stages] Building stage0 (bootstrap compiler, from the seed)  [$CC_ABS $STAGE0_CFLAGS, $HOST_TARGET, -j$CC_JOBS]"
rm -rf build/work/stage0
mkdir -p build/work/stage0
cc_link_parallel "$STAGE0_CFLAGS" build/work/stage0 build/stage0 "$STAGE0_CFLAGS" $seed_shared $seed_host "$runtime"

step "[2/$stages] Building stage1 (full compiler, via stage0)  — self-compiles"
rm -rf build/work/stage1
mkdir -p build/work/stage1
./build/stage0 vader/cli/main.vader build/work/stage1/stage1
cc_link_parallel "$stage1_cflags" build/work/stage1 "$stage1_out" "$stage1_ldflags" build/work/stage1/*.c "$runtime"

if [ "$three_stage" = 1 ]; then
    step "[3/3] Building vader = stage2 (via stage1, --release)"
    rm -rf build/work/stage2
    mkdir -p build/work/stage2
    ./build/stage1 build --release --emit=executable --out=build/work/stage2/vader --cc="$CC_ABS" vader/cli/main.vader
    # `cc -o vader` writes `vader` on Unix and `vader.exe` on Windows — the same
    # reason `vader/pipeline::linked_binary` probes instead of guessing.
    if [ -f build/work/stage2/vader ]; then
        mv build/work/stage2/vader build/vader
    elif [ -f build/work/stage2/vader.exe ]; then
        mv build/work/stage2/vader.exe build/vader.exe
    else
        echo "build.sh: stage1 produced no binary under build/work/stage2" >&2
        exit 1
    fi
fi

printf '%b==> done%b  vader built at build/vader\n' "$g" "$r"
./build/vader --version

if [ "$dist" = 1 ]; then
  os="$(uname -s)"; arch="$(uname -m)"
  case "$os" in
    Darwin) os=darwin ;;
    Linux)  os=linux ;;
    *)      os="$(printf '%s' "$os" | tr '[:upper:]' '[:lower:]')" ;;
  esac
  case "$arch" in
    arm64|aarch64) arch=arm64 ;;
    x86_64|amd64)  arch=x64 ;;
  esac
  out="dist/vader-${os}-${arch}"

  step "[dist] Bundling $out  (vader + lib/ + src/vader + runtime/c)"
  rm -rf "$out"
  mkdir -p "$out/runtime" "$out/src"
  cp build/vader "$out/vader"
  # `lib/` holds every namespace the toolchain ships FOR CONSUMPTION, copied
  # WHOLE rather than namespace by namespace — a named list silently stops
  # shipping the next namespace added, which is exactly how `toolchain/` came to
  # be missing from a bundle while the checkout was fine.
  # `default_library_root` probes `<exe>/lib` with the `std/io/io.vader` marker.
  #
  # The compiler's sources go to `src/`, NOT into `lib/`: they must ship (a
  # `build.vader` is compiled, and an import resolves from source), but the
  # compiler is not a library — it is the implementation a driver links. Keeping
  # it out of `lib/` makes that structural rather than policed.
  cp -R lib "$out/lib"
  cp -R vader "$out/src/vader"
  # Drop the human front-ends -- see bootstrap/dist-exclude.txt, which carries the
  # list, the reason it names what to DROP, and the trim-then-filter rule its three
  # readers share.
  sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//' bootstrap/dist-exclude.txt \
    | grep -Ev '^(#|$)' \
    | while read -r excluded; do
        rm -rf "$out/src/vader/$excluded"
      done
  cp -R runtime/c "$out/runtime/"

  printf '%b==> dist%b  %s ready — a self-contained toolchain (resolves lib/ + runtime/c/ next to the binary, so it runs — and drives builds — from any directory).\n' "$g" "$r" "$out"
fi
