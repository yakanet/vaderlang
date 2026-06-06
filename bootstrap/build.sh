#!/usr/bin/env bash
# Build the full Vader compiler from the committed C seed, in one shot:
#   seed (bootstrap.c.gz) -> stage1 -> stage1 compiles main.vader -> build/vader
#
# Needs only a C compiler and gzip — no Bun, no TS, no pre-existing vader binary.
# The C compiler defaults to `cc`; override with `CC=clang bootstrap/build.sh`
# (CFLAGS is overridable too). See docs/BOOTSTRAP.md.
set -euo pipefail
cd "$(dirname "$0")/.."

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--O2}"
runtime="runtime/c/vader_runtime.c"

if [ -t 1 ]; then b='\033[1m'; g='\033[1;32m'; r='\033[0m'; else b=''; g=''; r=''; fi
step() { printf '%b==>%b %s\n' "$b" "$r" "$*"; }

mkdir -p build

step "[1/4] Decompressing seed  bootstrap/bootstrap.c.gz -> build/bootstrap.c"
gunzip -c bootstrap/bootstrap.c.gz > build/bootstrap.c

step "[2/4] Compiling stage1 from the seed  ($CC $CFLAGS)"
"$CC" $CFLAGS -o build/stage1 build/bootstrap.c "$runtime" -Iruntime/c -lm

step "[3/4] stage1 -> emitting the full compiler's C  build/main.c  (self-compiles ~30 kLoC, ~30s)"
./build/stage1 vader/cli/main.vader build/main.c

step "[4/4] Compiling the full compiler  ($CC $CFLAGS) -> build/vader"
"$CC" $CFLAGS -o build/vader build/main.c "$runtime" -Iruntime/c -lm

printf '%b==> done%b  vader built at build/vader\n' "$g" "$r"
./build/vader --version
