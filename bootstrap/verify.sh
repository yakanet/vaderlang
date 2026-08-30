#!/usr/bin/env bash
# Fixed-point check : build the 3-stage toolchain, then confirm stage1 and
# stage2 (vader) emit identical C for main.vader, and the committed seed is
# fresh. Formalises TODO §2.7 / docs/BOOTSTRAP.md Phase 4. Run on demand /
# before releases — too slow for every PR. Honours $CC (via bootstrap/build.sh).
set -euo pipefail
cd "$(dirname "$0")/.."

./bootstrap/build.sh

# (a) fixed point : stage1 and stage2 must emit identical C for main.vader.
#
# Only ONE emission is needed. `build/work/stage2/` already IS stage1's — build.sh
# just wrote it — so stage2's own is the only thing missing. Same flags on both
# sides (`--release`, split being the default), which is the mode actually shipped;
# `--emit=c` and `--emit=executable` produce identical C, verified.
#
# `diff -r` and not `cmp`: the emission is a TREE of one unit per module, and a
# unit present on one side only is exactly what a comparison of concatenated
# output would miss. The .o files live beside the sources because that is where
# the CLI writes them, so they are excluded rather than moved.
if [ ! -d build/work/stage2 ]; then
  echo "verify.sh: build/work/stage2 is missing — build.sh did not produce step 3" >&2
  exit 2
fi
rm -rf build/work/verify
mkdir -p build/work/verify
./build/vader build --release --emit=c --out=build/work/verify/vader vader/cli/main.vader

# `diff -r` of two EMPTY trees returns 0, so the gate would pass vacuously on an
# emission that wrote nothing. The old `cmp` on two files at least required both
# to exist; this restores that much.
emitted=$(ls build/work/verify/*.c 2>/dev/null | wc -l | tr -d ' ')
if [ "$emitted" -lt 2 ]; then
  echo "verify.sh: only $emitted unit(s) emitted — refusing to certify a fixed point" >&2
  exit 2
fi

# diff exits 1 on a difference and 2 on an ERROR (missing or unreadable path).
# Folding them together reports a structural problem as a fixed-point failure,
# which sends the reader looking for a compiler bug that is not there.
set +e
diff -r -q --exclude='*.o' build/work/stage2 build/work/verify >/dev/null
fp_rc=$?
set -e
if [ "$fp_rc" = 2 ]; then
  echo "verify.sh: diff failed structurally comparing stage2 against the re-emission" >&2
  exit 2
fi
if [ "$fp_rc" != 0 ]; then
  echo "FIXED-POINT FAILED — stage1 and stage2 disagree on main.vader's C" >&2
  diff -r --exclude='*.o' build/work/stage2 build/work/verify | head -80 >&2
  exit 1
fi

# (a2) the DEBUG emission, which the release comparison above no longer covers:
# `--release` off means `prepare_cfg_bytecode_with` fills the per-op debug table
# and c_emit keeps `#line`. A divergence confined to that surface — the span and
# file provenance a DAP session reads — would otherwise pass unseen. A snippet is
# enough: what is under test is the emitter path, not the input's size.
rm -rf build/work/verify-debug
mkdir -p build/work/verify-debug/a build/work/verify-debug/b
DBG_SNIPPET=tests/snippets/return_42/_main.vader
# The SAME basename on both sides: every unit `#include`s the header by basename,
# so two different prefixes would diverge on that line alone and report a failure
# that is entirely an artefact of the test.
./build/stage1 build --emit=c --out=build/work/verify-debug/a/dbg "$DBG_SNIPPET"
./build/vader  build --emit=c --out=build/work/verify-debug/b/dbg "$DBG_SNIPPET" 2>/dev/null
set +e
diff -r -q --exclude='*.o' build/work/verify-debug/a build/work/verify-debug/b >/dev/null
dbg_rc=$?
set -e
if [ "$dbg_rc" = 2 ]; then
  echo "verify.sh: diff failed structurally on the debug emission" >&2
  exit 2
fi
if [ "$dbg_rc" != 0 ]; then
  echo "FIXED-POINT FAILED (debug emission) — stage1 and stage2 disagree" >&2
  diff -r --exclude='*.o' build/work/verify-debug/a build/work/verify-debug/b | head -40 >&2
  exit 1
fi

# (b) reproducibility : the same stage1, the same input, twice -> the same binary.
#
# This is the property the mono build used to carry by being the only path, and
# the one that has to stand on its own before the mono emitter can go (TODO §3.5
# a'). Only step 3 is rebuilt: it is the step the CLI drives, and the two before
# it are plain `cc` invocations this script's own build.sh makes.
#
# The output path deliberately differs from step 3's. Objects embed it and do
# differ; the linker absorbs that, and the binary must not.
CC_ABS="$(command -v "${CC:-cc}" || true)"
rm -rf build/work/repro
mkdir -p build/work/repro
./build/stage1 build --release --emit=executable \
  --out=build/work/repro/vader --cc="$CC_ABS" vader/cli/main.vader >/dev/null
if ! cmp -s build/work/repro/vader build/vader; then
  echo "NOT REPRODUCIBLE — two split builds of the same input differ" >&2
  ls -l build/work/repro/vader build/vader >&2
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
