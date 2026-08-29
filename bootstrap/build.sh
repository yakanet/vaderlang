#!/usr/bin/env bash
# Build the full Vader compiler from the committed C seed — a 3-stage bootstrap:
#   seed   ─cc→            build/stage0   (bootstrap compiler; emits C only)
#   stage0 ─emit C→ cc→    build/stage1   (intermediate full compiler)
#   stage1 ─build native→  build/vader    (= stage2, the shipped compiler)
#
# Needs only a C compiler — no Bun, no TS, no pre-existing vader binary.
# The C compiler defaults to `cc`; override with `CC=clang bootstrap/build.sh`. It
# is resolved to an absolute path and passed to stage1 via --cc, so the compiler
# stage1 spawns is exactly the one used here. stage0 & stage1 are throwaways built
# -O0 (STAGE0_CFLAGS); only stage2/vader is built -O3 (via stage1's --release).
# Pass --dist to also assemble a self-contained dist/vader-<os>-<arch>/ bundle
# (binary + lib/ + runtime/c). See docs/BOOTSTRAP.md.
set -euo pipefail
cd "$(dirname "$0")/.."

dist=0
for arg in "$@"; do
  case "$arg" in
    --dist) dist=1 ;;
    *) echo "build.sh: unknown argument: $arg (only --dist is supported)" >&2; exit 2 ;;
  esac
done

CC_ABS="$(command -v "${CC:-cc}" || true)"
if [ -z "$CC_ABS" ]; then
  echo "build.sh: C compiler '${CC:-cc}' not found on PATH (set CC=...)" >&2
  exit 1
fi
STAGE0_CFLAGS="${STAGE0_CFLAGS:--O0}"   # stage0 & stage1 are throwaways — fast cc
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
seed_shared=$(ls bootstrap/seed/bootstrap.split.*.c 2>/dev/null)
seed_host=$(ls bootstrap/seed/bootstrap."$HOST_TARGET".split.*.c 2>/dev/null || true)
if [ -z "$seed_shared" ]; then
    echo "bootstrap/build.sh: no seed under bootstrap/seed/ — run bootstrap/seed.sh regenerate" >&2
    exit 1
fi

step "[1/3] Building stage0 (bootstrap compiler, from the seed)  [$CC_ABS $STAGE0_CFLAGS, $HOST_TARGET]"
"$CC_ABS" $STAGE0_CFLAGS -o build/stage0 $seed_shared $seed_host "$runtime" -Iruntime/c -lm

step "[2/3] Building stage1 (full compiler, via stage0)  — self-compiles"
./build/stage0 vader/cli/main.vader build/stage1.c
"$CC_ABS" $STAGE0_CFLAGS -o build/stage1 build/stage1.c "$runtime" -Iruntime/c -lm

step "[3/3] Building vader = stage2 (via stage1, --release)"
./build/stage1 build --release --emit=executable --out=build/vader --cc="$CC_ABS" vader/cli/main.vader

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
