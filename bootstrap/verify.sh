#!/usr/bin/env bash
# Fixed-point check : the committed seed builds the full compiler (via
# bootstrap/build.sh), and that compiler reproduces both itself and the seed
# byte-for-byte. Formalises TODO §2.7 / docs/BOOTSTRAP.md Phase 4. Run on demand
# / before releases — too slow for every PR. Honours $CC (passed through to
# bootstrap/build.sh).
set -euo pipefail
cd "$(dirname "$0")/.."

# build.sh runs the whole chain: seed -> stage1 -> build/main.c (stage1's C for
# the full compiler) -> build/vader. build/main.c is the fixed-point anchor.
./bootstrap/build.sh

# (a) full-compiler self-reproduction : vader re-emits main.vader, must match
#     stage1's emission (build/main.c).
./build/vader build vader/cli/main.vader --target=c --out=build/main2.c
if ! cmp -s build/main.c build/main2.c; then
  echo "FIXED-POINT FAILED — the full compiler is not self-reproducing" >&2
  diff -u build/main.c build/main2.c | head -80 >&2
  exit 1
fi

# (b) seed freshness : vader re-emits bootstrap.vader, must match the committed seed.
./build/vader build vader/bootstrap/bootstrap.vader --target=c --out=build/bootstrap.new.c
if ! cmp -s build/bootstrap.new.c <(gunzip -c bootstrap/bootstrap.c.gz); then
  echo "STALE SEED — bootstrap.c.gz no longer matches bootstrap.vader; run bootstrap/regenerate.sh" >&2
  exit 1
fi

echo "fixed-point OK : main.c reproduced byte-identical, seed up to date"
