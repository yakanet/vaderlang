#!/usr/bin/env bash
# Fixed-point check : build the 3-stage toolchain, then confirm stage1 and
# stage2 (vader) emit identical C for main.vader, and the committed seed is
# fresh. Formalises TODO §2.7 / docs/BOOTSTRAP.md Phase 4. Run on demand /
# before releases — too slow for every PR. Honours $CC (via bootstrap/build.sh).
set -euo pipefail
cd "$(dirname "$0")/.."

./bootstrap/build.sh

# (a) fixed point : stage1 and stage2 must emit identical C for main.vader.
# Re-emit from both with the SAME flags (--target=c, no --release) so the diff
# reflects only compiler behaviour, not the build's debug/release split.
./build/stage1 build vader/cli/main.vader --target=c --out=build/fp1.c
./build/vader  build vader/cli/main.vader --target=c --out=build/fp2.c 2>/dev/null
if ! cmp -s build/fp1.c build/fp2.c; then
  echo "FIXED-POINT FAILED — stage1 and stage2 disagree on main.vader's C" >&2
  diff -u build/fp1.c build/fp2.c | head -80 >&2
  exit 1
fi

# (c) seed freshness : vader re-emits bootstrap.vader, must match the committed
# seed. --release mirrors regenerate.sh : it keeps `#line` out of the seed (the
# c-emit gates them on !release), so a populated debug table doesn't bloat the
# committed artifact. For --target=c, --release only drops `#line`.
./build/vader build vader/bootstrap/bootstrap.vader --release --target=c --out=build/bootstrap.new.c
if ! cmp -s build/bootstrap.new.c <(gunzip -c bootstrap/bootstrap.c.gz); then
  echo "STALE SEED — bootstrap.c.gz no longer matches bootstrap.vader; run bootstrap/regenerate.sh" >&2
  exit 1
fi

echo "fixed-point OK : stage1 == stage2, seed up to date"
