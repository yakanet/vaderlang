#!/usr/bin/env bash
# Build the full Vader compiler from the committed C seed — a 3-stage bootstrap:
#   seed   ─cc→            build/stage0   (bootstrap compiler; emits C only)
#   stage0 ─emit C→ cc→    build/stage1   (intermediate full compiler)
#   stage1 ─build native→  build/vader    (= stage2, the shipped compiler)
#
# Needs only a C compiler and gzip — no Bun, no TS, no pre-existing vader binary.
# The C compiler defaults to `cc`; override with `CC=clang bootstrap/build.sh`. It
# is resolved to an absolute path and passed to stage1 via --cc, so the compiler
# stage1 spawns is exactly the one used here. stage0 & stage1 are throwaways built
# -O0 (STAGE0_CFLAGS); only stage2/vader is built -O3 (via stage1's --release).
# Pass --dist to also assemble a self-contained dist/vader-<os>-<arch>/ bundle
# (binary + stdlib + runtime/c). See docs/BOOTSTRAP.md.
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

if [ -t 1 ]; then b='\033[1m'; g='\033[1;32m'; r='\033[0m'; else b=''; g=''; r=''; fi
step() { printf '%b==>%b %s\n' "$b" "$r" "$*"; }

mkdir -p build

step "[1/3] Building stage0 (bootstrap compiler, from the seed)  [$CC_ABS $STAGE0_CFLAGS]"
gunzip -c bootstrap/bootstrap.c.gz > build/bootstrap.c
"$CC_ABS" $STAGE0_CFLAGS -o build/stage0 build/bootstrap.c "$runtime" -Iruntime/c -lm

step "[2/3] Building stage1 (full compiler, via stage0)  — self-compiles ~30 kLoC, ~30s"
./build/stage0 vader/cli/main.vader build/stage1.c
"$CC_ABS" $STAGE0_CFLAGS -o build/stage1 build/stage1.c "$runtime" -Iruntime/c -lm

step "[3/3] Building vader = stage2 (via stage1, --release)  — ~30s"
./build/stage1 build vader/cli/main.vader --release --target=native --out=build/vader --cc="$CC_ABS"

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

  step "[dist] Bundling $out  (vader + stdlib + runtime/c)"
  rm -rf "$out"
  mkdir -p "$out/runtime"
  cp build/vader "$out/vader"
  cp -R stdlib "$out/stdlib"
  cp -R runtime/c "$out/runtime/"

  printf '%b==> dist%b  %s ready — a self-contained toolchain (resolves stdlib/ + runtime/c/ next to the binary, so it runs from any directory).\n' "$g" "$r" "$out"
fi
