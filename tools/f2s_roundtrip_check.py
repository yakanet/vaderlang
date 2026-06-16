#!/usr/bin/env python3
# tools/f2s_roundtrip_check.py — exhaustive correctness check for the pure-Vader
# Ryu shortest-f32 formatter (stdlib/std/core/f2s.vader).
#
# For a spread of f32 bit patterns (full-bit-space random + edge cases), emits a
# Vader program that reconstructs each f32 from its raw u32 bits
# (`u32.from_bits()`) and prints `f32.to_string()`, builds it natively, runs it,
# and checks each line ROUND-TRIPS: float(line) rounded to f32 has the same bits.
# When numpy is available it also checks the digits match numpy.float32's repr
# (the shortest-f32 oracle).
#
# Usage:  python3 tools/f2s_roundtrip_check.py [N]   (N random doubles, default 20000)

import random, struct, subprocess, re, os, sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), ".."))
N = int(sys.argv[1]) if len(sys.argv) > 1 else 20000
M32 = (1 << 32) - 1

try:
    import numpy as _np
    def f32_shortest(bits):
        return repr(_np.float32(struct.unpack('<f', struct.pack('<I', bits))[0]))
    HAVE_NP = True
except ImportError:
    HAVE_NP = False


def f32_bits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def is_finite_f32_bits(b):
    return ((b >> 23) & 0xFF) != 0xFF   # exclude inf / nan


def digits_only(s):
    s = s.lstrip('-')
    s = re.split('[eE]', s)[0].replace('.', '')
    return (s.lstrip('0').rstrip('0')) or '0'


def build_values():
    random.seed(0xF2)
    vals = []
    edge = [0.0, -0.0, 1.0, -1.0, 0.5, 0.1, 0.2, 0.3, 100.0, 1e7, 1e20, 1e-7,
            3.14, 16777216.0, 3.4028235e38, 1.1754944e-38, 1.4e-45,
            123456.7, 0.000123, -2.5]
    for x in edge:
        vals.append(f32_bits(x))
    for e in range(-30, 31):
        vals.append(f32_bits(float(f"1e{e}")))
    for _ in range(N):
        b = random.getrandbits(32)
        if is_finite_f32_bits(b):
            vals.append(b)
    return list(dict.fromkeys(vals))


def main():
    vals = build_values()
    os.makedirs("/tmp/f2s_check", exist_ok=True)
    src = '/tmp/f2s_check/_main.vader'
    with open(src, "w") as f:
        f.write('module "main"\nimport "std/io" { println }\nBITS :: [\n')
        for b in vals:
            f.write(f"    0x{b:08X}_u32,\n")
        f.write("]\nmain :: fn() -> i32 {\n    for b in BITS { println(b.from_bits().to_string()) }\n    return 0\n}\n")

    print(f"checking {len(vals)} f32 values (numpy shortest oracle: {HAVE_NP}) ...")
    r = subprocess.run(["./build/vader", "build", src, "--target=native"],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        print("BUILD FAILED"); print(r.stdout[-2000:]); print(r.stderr[-2000:]); return 1
    out = subprocess.run(["/tmp/f2s_check/_main"], capture_output=True, text=True)
    lines = out.stdout.splitlines()
    if len(lines) != len(vals):
        print(f"line count mismatch: {len(lines)} vs {len(vals)}"); return 1

    rt_fail, short_fail = [], []
    for b, line in zip(vals, lines):
        try:
            back = f32_bits(float(line))   # parse as f64, round to f32, take bits
        except ValueError:
            rt_fail.append((hex(b), line)); continue
        if back != b:
            rt_fail.append((hex(b), line)); continue
        if HAVE_NP and digits_only(line) != digits_only(f32_shortest(b)):
            short_fail.append((hex(b), line, f32_shortest(b)))

    print(f"round-trip failures: {len(rt_fail)}")
    for t in rt_fail[:20]:
        print("  RT", t)
    print(f"shortest-mismatch vs numpy float32: {len(short_fail)}")
    for t in short_fail[:20]:
        print("  SH", t)
    ok = not rt_fail and not short_fail
    print("ALL GOOD" if ok else "FAILURES PRESENT")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
