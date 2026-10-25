#!/usr/bin/env bash
# Fixed-point check : build the 3-stage toolchain, then confirm stage1 and
# stage2 (vader) emit identical C for main.vader, that the build reproduces, and
# that the tree's bootstrap entry writes that same C.
# Described in docs/BOOTSTRAP.md. It is also the seed's
# viability gate: `bootstrap/seed.sh check` (the pre-push hook) and the CI
# `fixed-point` job both run it. Honours $CC.
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
# Same flags is not enough: the two EMITTING BINARIES must also be built the same
# way, which `build.sh` guarantees (ADR 0004).
#
# `diff -r` and not `cmp`: the emission is a TREE of one unit per module, and a
# unit present on one side only is exactly what a comparison of concatenated
# output would miss. A native build writes its C under `c/` beside the binary,
# and its objects under `obj/`: the C is what is compared.
if [ ! -d build/work/stage2/c ]; then
  echo "verify.sh: build/work/stage2/c is missing — build.sh did not produce step 3" >&2
  exit 2
fi
rm -rf build/work/verify
mkdir -p build/work/verify
./build/vader build --release --emit=c --out=build/work/verify/vader vader/tools/cli/main.vader

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
diff -r -q build/work/stage2/c build/work/verify >/dev/null
fp_rc=$?
set -e
if [ "$fp_rc" = 2 ]; then
  echo "verify.sh: diff failed structurally comparing stage2 against the re-emission" >&2
  exit 2
fi
if [ "$fp_rc" != 0 ]; then
  echo "FIXED-POINT FAILED — stage1 and stage2 disagree on main.vader's C" >&2
  echo "  stage1's codegen is the seed's; if the seed carries a bug the tree has fixed, reseed: bootstrap/seed.sh regenerate" >&2
  diff -r build/work/stage2/c build/work/verify | head -80 >&2
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
  --out=build/work/repro/vader --cc="$CC_ABS" vader/tools/cli/main.vader >/dev/null
if ! cmp -s build/work/repro/vader build/vader; then
  echo "NOT REPRODUCIBLE — two split builds of the same input differ" >&2
  ls -l build/work/repro/vader build/vader >&2
  exit 1
fi

# (c) the tree's bootstrap entry, which nothing else compiles between reseeds, must
# write the C (a) re-emitted. Same basename as (a):
# every unit includes its header by it.
rm -rf build/work/tree-bootstrap
mkdir -p build/work/tree-bootstrap/bin build/work/tree-bootstrap/emit
./build/vader build --release --emit=executable \
  --out=build/work/tree-bootstrap/bin/bootstrap --cc="$CC_ABS" vader/bootstrap/bootstrap.vader >/dev/null
build/work/tree-bootstrap/bin/bootstrap vader/tools/cli/main.vader build/work/tree-bootstrap/emit/vader
set +e
diff -r -q build/work/verify build/work/tree-bootstrap/emit >/dev/null
tb_rc=$?
set -e
if [ "$tb_rc" = 2 ]; then
  echo "verify.sh: diff failed structurally comparing the bootstrap entry's emission" >&2
  exit 2
fi
if [ "$tb_rc" != 0 ]; then
  echo "BOOTSTRAP ENTRY DIVERGES: vader/bootstrap/bootstrap.vader does not write the C the CLI writes" >&2
  diff -r build/work/verify build/work/tree-bootstrap/emit | head -40 >&2
  exit 1
fi

echo "fixed-point OK : stage1 == stage2"
