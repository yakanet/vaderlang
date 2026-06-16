#!/usr/bin/env python3
# tools/dtoa_roundtrip_check.py — exhaustive correctness check for the pure-Vader
# Ryu shortest-double formatter (stdlib/std/core/dtoa.vader).
#
# For a large spread of f64 bit patterns (full-bit-space random + edge cases +
# powers of ten), this:
#   1. emits a Vader program that reconstructs each double from its raw bits
#      (`u64.from_bits()`) and prints `f64.to_string()` ;
#   2. builds it natively with ./build/vader and runs it ;
#   3. checks each line ROUND-TRIPS (Python float(line) has the same bits) and
#      that its significant digits match Python's `repr` (i.e. Ryu produced the
#      same SHORTEST decimal CPython's dtoa does).
#
# This is a developer tool, not part of the Bun suite: `vader test` runs on the
# bytecode VM whose host `parse_float` mishandles subnormals, and std/core can't
# host @tests (it can't be a `vader test` entry — primitive @intrinsic trait
# members don't resolve as the entry module). The native build/run path here has
# neither limitation, so it is the authoritative round-trip oracle.
#
# Usage:  python3 tools/dtoa_roundtrip_check.py [N]
#   N = number of random full-bit-space doubles (default 15000). Values are
#   emitted as one big array literal, so very large N slows the compile.

import random, struct, subprocess, re, os, sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), ".."))
N = int(sys.argv[1]) if len(sys.argv) > 1 else 15000
M64 = (1 << 64) - 1


def bits(x):
    return struct.unpack('<Q', struct.pack('<d', x))[0]


def is_finite_bits(b):
    return ((b >> 52) & 0x7FF) != 0x7FF   # exclude inf / nan


def digits_only(s):
    s = s.lstrip('-')
    s = re.split('[eE]', s)[0].replace('.', '')
    s = s.lstrip('0').rstrip('0')
    return s or '0'


def build_values():
    random.seed(0xD704A)
    vals = []
    edge = [0.0, -0.0, 1.0, -1.0, 2.0, 0.5, 0.1, 0.2, 0.3, 10.0, 100.0, 1e7,
            1e20, 1e21, 1e22, 1e-7, 5e-324, 2.2250738585072009e-308,
            2.2250738585072014e-308, 1.7976931348623157e308,
            3.141592653589793, 2.718281828459045, 9.999999999999999,
            123456789.123456789, 0.000123456789, 6.022e23, 1.602176634e-19,
            1234.5678, 9007199254740992.0, 9007199254740993.0]
    for x in edge:
        vals.append(bits(x))
    for e in range(-30, 31):
        vals.append(bits(float(f"1e{e}")))
    for _ in range(N):
        b = random.getrandbits(64)
        if is_finite_bits(b):
            vals.append(b)
    for _ in range(N // 5):
        m = random.randint(1, 10 ** random.randint(1, 17))
        e = random.randint(-30, 30)
        try:
            vals.append(bits(float(f"{m}e{e}")))
        except (ValueError, OverflowError):
            pass
    return list(dict.fromkeys(vals))


def main():
    vals = build_values()
    os.makedirs("/tmp/dtoa_check", exist_ok=True)
    src = '/tmp/dtoa_check/_main.vader'
    with open(src, "w") as f:
        f.write('module "main"\nimport "std/io" { println }\nBITS :: [\n')
        for b in vals:
            f.write(f"    0x{b:016X}_u64,\n")
        f.write("]\nmain :: fn() -> i32 {\n    for b in BITS { println(b.from_bits().to_string()) }\n    return 0\n}\n")

    print(f"checking {len(vals)} doubles ...")
    r = subprocess.run(["./build/vader", "build", src, "--target=native"],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        print("BUILD FAILED"); print(r.stdout[-2000:]); print(r.stderr[-2000:])
        return 1
    out = subprocess.run(["/tmp/dtoa_check/_main"], capture_output=True, text=True)
    lines = out.stdout.splitlines()
    if len(lines) != len(vals):
        print(f"line count mismatch: {len(lines)} vs {len(vals)}"); return 1

    rt_fail, short_fail = [], []
    for b, line in zip(vals, lines):
        x = struct.unpack('<d', struct.pack('<Q', b))[0]
        try:
            back = bits(float(line))
        except ValueError:
            rt_fail.append((hex(b), line)); continue
        if back != b:
            rt_fail.append((hex(b), line, repr(x))); continue
        if digits_only(line) != digits_only(repr(x)):
            short_fail.append((hex(b), line, repr(x)))

    print(f"round-trip failures: {len(rt_fail)}")
    for t in rt_fail[:20]:
        print("  RT", t)
    print(f"shortest-mismatch vs CPython repr: {len(short_fail)}")
    for t in short_fail[:20]:
        print("  SH", t)
    ok = not rt_fail and not short_fail
    print("ALL GOOD" if ok else "FAILURES PRESENT")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
