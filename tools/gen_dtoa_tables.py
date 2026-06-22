#!/usr/bin/env python3
# tools/gen_dtoa_tables.py — regenerate stdlib/std/core/dtoa_tables.vader.
#
# Recomputes the two Ryu double-to-shortest power-of-5 lookup tables from
# scratch with Python big integers, so there is no hand-transcription risk.
# The output drives the pure-Vader Ryu formatter in stdlib/std/core/dtoa.vader.
#
# Reference: Ulf Adams, "Ryu: fast float-to-string conversion" (PLDI 2018),
# ulfjack/ryu @ ryu/d2s_full_table.h. Both tables store a 128-bit value as
# two u64 halves {low, high} = low + (high << 64); index [0] is the low word.
#
# Definitions (DOUBLE_POW5_BITCOUNT = DOUBLE_POW5_INV_BITCOUNT = 125):
#   pow5bits(e)        = ((e * 1217359) >> 19) + 1    (bit length of 5^e)
#   DOUBLE_POW5_SPLIT[i]:
#       shift = pow5bits(i) - 125
#       shift <= 0 -> 5^i << (-shift)              (exact, small i)
#       shift  > 0 -> floor(5^i / 2^shift)         (top 125 bits, truncated)
#   DOUBLE_POW5_INV_SPLIT[q]:
#       k = pow5bits(q) - 1 + 125
#       floor(2^k / 5^q) + 1                        (round up the reciprocal)
#
# Validated against the reference header's first 8 rows and last row of each
# table before emitting (see EXPECT_* below).

POW5_BITCOUNT = 125
POW5_INV_BITCOUNT = 125
POW5_SPLIT_ROWS = 326       # i in [0, 326)
POW5_INV_SPLIT_ROWS = 342   # q in [0, 342)
# f32 (Ryu f2s) tables: a single u64 each, derived from the f64 tables. NOTE the
# two effective bitcounts DIFFER (matching ryu's f2s_full_table.h):
#   FLOAT_POW5_SPLIT[i]     = DOUBLE_POW5_SPLIT[i] >> 64           → FLOAT_POW5_BITCOUNT     = 61
#   FLOAT_POW5_INV_SPLIT[q] = (DOUBLE_POW5_INV_SPLIT[q] >> 66) + 1 → FLOAT_POW5_INV_BITCOUNT = 59
# (the INV table takes 2 extra low bits off the f64 high word, hence 125-66=59).
FLOAT_POW5_SPLIT_ROWS = 47       # i in [0, 47)
FLOAT_POW5_INV_SPLIT_ROWS = 55   # q in [0, 55)
MASK64 = (1 << 64) - 1


def float_split_value(i: int) -> int:
    return split_value(i) >> 64


def float_inv_split_value(q: int) -> int:
    return (inv_split_value(q) >> 66) + 1


def pow5bits(e: int) -> int:
    return ((e * 1217359) >> 19) + 1


def split_value(i: int) -> int:
    shift = pow5bits(i) - POW5_BITCOUNT
    pow5 = 5 ** i
    if shift <= 0:
        return pow5 << (-shift)
    # floor(5^i / 2^shift)
    return pow5 >> shift


def inv_split_value(q: int) -> int:
    k = pow5bits(q) - 1 + POW5_INV_BITCOUNT
    return (1 << k) // (5 ** q) + 1


def halves(v: int):
    return (v & MASK64, v >> 64)


# Ground truth sampled verbatim from ulfjack/ryu ryu/d2s_full_table.h.
EXPECT_INV = {
    0: (1, 2305843009213693952),
    1: (11068046444225730970, 1844674407370955161),
    2: (5165088340638674453, 1475739525896764129),
    3: (7821419487252849886, 1180591620717411303),
    4: (8824922364862649494, 1888946593147858085),
    5: (7059937891890119595, 1511157274518286468),
    6: (13026647942995916322, 1208925819614629174),
    7: (9774590264567735146, 1934281311383406679),
    341: (673562245690857633, 1345193707530136767),
}
EXPECT_SPLIT = {
    0: (0, 1152921504606846976),
    1: (0, 1441151880758558720),
    2: (0, 1801439850948198400),
    3: (0, 2251799813685248000),
    4: (0, 1407374883553280000),
    5: (0, 1759218604441600000),
    6: (0, 2199023255552000000),
    7: (0, 1374389534720000000),
    325: (8710297504448807696, 1780059086805761106),
}
# f32 (Ryu f2s) reference rows, from ulfjack/ryu ryu/f2s_full_table.h.
EXPECT_FLOAT_INV = {
    0: 576460752303423489, 1: 461168601842738791, 2: 368934881474191033,
    3: 295147905179352826, 4: 472236648286964522, 5: 377789318629571618,
    54: 441711766194596083,
}
EXPECT_FLOAT_SPLIT = {
    0: 1152921504606846976, 1: 1441151880758558720, 2: 1801439850948198400,
    3: 2251799813685248000, 4: 1407374883553280000, 5: 1759218604441600000,
    46: 2019483917365790221,
}


def validate():
    for q, want in EXPECT_INV.items():
        got = halves(inv_split_value(q))
        assert got == want, f"INV[{q}] = {got}, expected {want}"
    for i, want in EXPECT_SPLIT.items():
        got = halves(split_value(i))
        assert got == want, f"SPLIT[{i}] = {got}, expected {want}"
    for q, want in EXPECT_FLOAT_INV.items():
        got = float_inv_split_value(q)
        assert got == want, f"FLOAT_INV[{q}] = {got}, expected {want}"
    for i, want in EXPECT_FLOAT_SPLIT.items():
        got = float_split_value(i)
        assert got == want, f"FLOAT_SPLIT[{i}] = {got}, expected {want}"
    print("validation OK: all sampled reference rows match")


def emit_array(name: str, values, out):
    # Typed const array (`NAME: u64[]: [...]`) with bare values — the element
    # annotation coerces each literal to u64 (typed numeric suffixes were removed).
    out.append(f"{name}: u64[]: [")
    line = "    "
    for idx, v in enumerate(values):
        tok = f"{v},"
        if len(line) + len(tok) + 1 > 96 and line.strip():
            out.append(line.rstrip())
            line = "    "
        line += tok + " "
    if line.strip():
        out.append(line.rstrip())
    out.append("]")
    out.append("")


def main():
    validate()

    split_lo = [split_value(i) & MASK64 for i in range(POW5_SPLIT_ROWS)]
    split_hi = [split_value(i) >> 64 for i in range(POW5_SPLIT_ROWS)]
    inv_lo = [inv_split_value(q) & MASK64 for q in range(POW5_INV_SPLIT_ROWS)]
    inv_hi = [inv_split_value(q) >> 64 for q in range(POW5_INV_SPLIT_ROWS)]

    out = []
    out.append("// stdlib/std/core/dtoa_tables.vader — Ryu power-of-5 lookup tables.")
    out.append("//")
    out.append("// GENERATED by tools/gen_dtoa_tables.py — do not edit by hand. Rerun the")
    out.append("// generator to regenerate. Drives the pure-Vader shortest-double formatter")
    out.append("// in dtoa.vader (Ryu, Adams 2018). Each 128-bit table entry is split into a")
    out.append("// `_LO` (low 64 bits) and `_HI` (high 64 bits) array, indexed in lockstep;")
    out.append("// value = LO[i] + (HI[i] << 64). Part of `module \"std/core\"`.")
    out.append("//")
    out.append(f"// DOUBLE_POW5_SPLIT     : {POW5_SPLIT_ROWS} rows  (5^i,  used when e2 < 0)")
    out.append(f"// DOUBLE_POW5_INV_SPLIT : {POW5_INV_SPLIT_ROWS} rows  (1/5^q, used when e2 >= 0)")
    out.append(f"// bitcount = {POW5_BITCOUNT} for both.")
    out.append("")
    out.append('module "std/core"')
    out.append("")
    out.append("// ---- 5^i (multiply path, e2 < 0) ------------------------------------------")
    out.append("")
    emit_array("DOUBLE_POW5_SPLIT_LO", split_lo, out)
    emit_array("DOUBLE_POW5_SPLIT_HI", split_hi, out)
    out.append("// ---- 1/5^q reciprocal (multiply path, e2 >= 0) ----------------------------")
    out.append("")
    emit_array("DOUBLE_POW5_INV_SPLIT_LO", inv_lo, out)
    emit_array("DOUBLE_POW5_INV_SPLIT_HI", inv_hi, out)

    float_split = [float_split_value(i) for i in range(FLOAT_POW5_SPLIT_ROWS)]
    float_inv = [float_inv_split_value(q) for q in range(FLOAT_POW5_INV_SPLIT_ROWS)]
    out.append("// ---- f32 (Ryu f2s) : single-u64 tables, derived from the f64 tables -------")
    out.append(f"// FLOAT_POW5_SPLIT     : {FLOAT_POW5_SPLIT_ROWS} rows  (5^i,  used when e2 < 0)")
    out.append(f"// FLOAT_POW5_INV_SPLIT : {FLOAT_POW5_INV_SPLIT_ROWS} rows  (1/5^q, used when e2 >= 0)")
    out.append("// bitcount: SPLIT = 61 (f64 hi, >>64), INV = 59 (f64 hi >>2, i.e. >>66) — they differ.")
    out.append("")
    emit_array("FLOAT_POW5_SPLIT", float_split, out)
    emit_array("FLOAT_POW5_INV_SPLIT", float_inv, out)

    text = "\n".join(out) + "\n"
    import os
    dest = os.path.join(os.path.dirname(__file__), "..", "stdlib", "std", "core", "dtoa_tables.vader")
    dest = os.path.normpath(dest)
    with open(dest, "w") as f:
        f.write(text)
    print(f"wrote {dest}")
    print(f"  SPLIT rows={POW5_SPLIT_ROWS}  INV rows={POW5_INV_SPLIT_ROWS}")


if __name__ == "__main__":
    main()
