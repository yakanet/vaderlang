#!/usr/bin/env bash
# Fixed-point check : build the 3-stage toolchain, then confirm stage1 and
# stage2 (vader) emit identical C for main.vader, and the committed seed is
# fresh. Formalises TODO §2.7 / docs/BOOTSTRAP.md Phase 4. Run on demand /
# before releases — too slow for every PR. Honours $CC (via bootstrap/build.sh).
set -euo pipefail
cd "$(dirname "$0")/.."

./bootstrap/build.sh

# (a) fixed point : stage1 and stage2 must emit identical C for main.vader.
# Re-emit from both with the SAME flags (--emit=c, no --release) so the diff
# reflects only compiler behaviour, not the build's debug/release split.
rm -rf build/work/verify
mkdir -p build/work/verify
./build/stage1 build --emit=c --out=build/work/verify/fp1.c vader/cli/main.vader
./build/vader  build --emit=c --out=build/work/verify/fp2.c vader/cli/main.vader 2>/dev/null
if ! cmp -s build/work/verify/fp1.c build/work/verify/fp2.c; then
  echo "FIXED-POINT FAILED — stage1 and stage2 disagree on main.vader's C" >&2
  diff -u build/work/verify/fp1.c build/work/verify/fp2.c | head -80 >&2
  exit 1
fi

# (c) seed freshness, for EVERY target. `seed.sh check` re-emits the whole set
# against one shared atom table and diffs the tree, so a unit that exists for one
# target and not another is caught too. That subsumes the old target-independence
# check this used to carry: the seed no longer has to be target-independent — it
# carries each target's units, and the emitter stores a unit once only when every
# target produced the same bytes for it.
#
# Delegated to `seed.sh check`, which owns the emission flags
# (`--release` keeps `#line` out of the seed) — duplicating them here is how a
# release gate silently stops certifying what it claims to. `--full` forces the
# real re-emission rather than its git-only shortcut: this is the pre-release
# check, so it earns the 4 s. VADER pins the compiler to the one build.sh just
# produced above, so the freshness verdict is about *this* toolchain.
set +e
VADER=./build/vader ./bootstrap/seed.sh check --full --quiet >/dev/null
seed_verdict=$?
set -e
if [ "$seed_verdict" != 0 ]; then
  echo "STALE SEED — bootstrap/seed/ no longer matches bootstrap.vader; run bootstrap/seed.sh regenerate" >&2
  exit 1
fi

echo "fixed-point OK : stage1 == stage2, seed up to date for every target"
