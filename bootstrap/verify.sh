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
./build/stage1 build --emit=c --out=build/fp1.c vader/cli/main.vader
./build/vader  build --emit=c --out=build/fp2.c vader/cli/main.vader 2>/dev/null
if ! cmp -s build/fp1.c build/fp2.c; then
  echo "FIXED-POINT FAILED — stage1 and stage2 disagree on main.vader's C" >&2
  diff -u build/fp1.c build/fp2.c | head -80 >&2
  exit 1
fi

# (c) seed freshness : delegated to `seed.sh check`, which owns the emission flags
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
  echo "STALE SEED — bootstrap.c no longer matches bootstrap.vader; run bootstrap/seed.sh regenerate" >&2
  exit 1
fi

# (d) the seed is target-INDEPENDENT. Unnamed until the target model landed, and
# load-bearing from that moment: `seed.sh` emits with no `--target`, so it bakes
# whatever machine regenerated it, while `seed.sh check` compares byte for byte.
# The day something in the bootstrap closure selects on `@target` or reads
# `VADER_OS`, a seed regenerated on macOS stops being re-emittable on Linux and
# THIS job goes stale permanently — insatisfiable, on a runner nobody suspects.
#
# It holds today only because nothing in the closure uses either, so the baked
# constants are eliminated. That is a property, not a guarantee, and §10.2 of the
# target plan says the closure is the ONLY place `@target` would be useful — so
# the first real client trips this. Failing here names the cause; failing in CI
# a week later does not.
#
# One foreign target is enough: if the emission depended on the target at all,
# it would differ from the committed seed. 4 s.
./build/vader build --release --emit=c --out=build/seed.foreign.c \
  --target=linux-x86_64 vader/bootstrap/bootstrap.vader >/dev/null 2>&1
if ! cmp -s build/seed.foreign.c bootstrap/bootstrap.c; then
  echo "TARGET-DEPENDENT SEED — bootstrap.c differs when emitted for linux-x86_64." >&2
  echo "  The bootstrap closure now selects on the target, so one committed seed" >&2
  echo "  can no longer serve three platforms. See the target plan §10.3: pin a" >&2
  echo "  canonical emission target, keep \`@target\` out of the closure, or commit" >&2
  echo "  one seed per platform. None is free." >&2
  exit 1
fi

echo "fixed-point OK : stage1 == stage2, seed up to date, seed target-independent"
