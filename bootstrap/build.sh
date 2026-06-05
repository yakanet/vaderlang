#!/usr/bin/env bash
# Build stage1 (the build-only compiler) from the committed C seed.
# Needs only a C compiler + gzip — no Bun, no TS, no pre-existing vader binary.
# See docs/BOOTSTRAP.md.
set -euo pipefail
cd "$(dirname "$0")/.."

mkdir -p build
gunzip -c bootstrap/bootstrap.c.gz > build/bootstrap.c
cc -O2 -o build/stage1 build/bootstrap.c runtime/c/vader_runtime.c -Iruntime/c -lm

echo "stage1 built at build/stage1"
echo "smoke test (stage1 compiles a trivial snippet to C):"
./build/stage1 tests/snippets/return_42/_main.vader build/_smoke.c && echo "  ok"
