#!/usr/bin/env bash
# Fixed-point check : the committed seed builds stage1, stage1 rebuilds the full
# compiler, and the full compiler reproduces both itself and the seed
# byte-for-byte. Formalises TODO §2.7 / docs/BOOTSTRAP.md Phase 4. Run on demand
# / before releases — too slow for every PR.
set -euo pipefail
cd "$(dirname "$0")/.."

# Compiling vader/cli/main.vader is large — raise the GC arenas so stage1 and
# the rebuilt compiler don't OOM on self-input (see docs/BOOTSTRAP.md §9).
export VADER_GC_YOUNG_BYTES="${VADER_GC_YOUNG_BYTES:-$((256 * 1024 * 1024))}"
export VADER_GC_OLD_BYTES="${VADER_GC_OLD_BYTES:-$((1024 * 1024 * 1024))}"

./bootstrap/build.sh                                  # build/stage1 from the seed

# stage1 (build-only, positional <in> <out>) emits the FULL compiler's C, then cc it.
./build/stage1 vader/cli/main.vader build/main1.c
cc -O2 -o build/vader build/main1.c runtime/c/vader_runtime.c -Iruntime/c -lm

# (a) full-compiler self-reproduction : vader re-emits main.vader, must match.
./build/vader build vader/cli/main.vader --target=c --out=build/main2.c
if ! cmp -s build/main1.c build/main2.c; then
  echo "FIXED-POINT FAILED — the full compiler is not self-reproducing" >&2
  diff -u build/main1.c build/main2.c | head -80 >&2
  exit 1
fi

# (b) seed freshness : vader re-emits bootstrap.vader, must match the committed seed.
./build/vader build vader/bootstrap/bootstrap.vader --target=c --out=build/bootstrap.new.c
if ! cmp -s build/bootstrap.new.c <(gunzip -c bootstrap/bootstrap.c.gz); then
  echo "STALE SEED — bootstrap.c.gz no longer matches bootstrap.vader; run bootstrap/regenerate.sh" >&2
  exit 1
fi

echo "fixed-point OK : main.c reproduced byte-identical, seed up to date"
