# 0104: A young survivor is promoted at its first collection

## Status

Accepted (2026-10-21). Supersedes in part
[0007](0007-generational-gc-copying-young-non-moving-old.md): the tenure age.

**Amended by
[0105](0105-a-major-leaves-the-card-table-as-its-minor-left-it.md)
(2026-10-21)**: the `+3 %` on `vader test vader` below, and the third consequence,
no longer hold. A major no longer re-arms the card table, and `vader test vader`
runs fewer instructions than at age 2 (242.0 G against 250.6 G).

## Context

Under 0007 a young survivor was promoted at its second minor (`VADER_TENURE_AGE`
2): the first minor copied it into young to-space, the second copied it again,
into the old slab. An object that lives long is copied twice.

The workload 0007 names, the compiler compiling itself, is that shape: its AST,
types and IR live through the whole compilation, and 30 % of the bytes it
allocates survive a minor. The collector took about 46 % of its samples.

Measured on 2026-10-21 (Mac M-series, release builds, alternated runs, every
output byte-identical between the two ages):

| Workload | Age 2 | Age 1 |
|---|---|---|
| Self-compile, wall time | 2.91 s | 2.65 s (−8.9 %) |
| Self-compile, bytes copied by the GC | 871 MB | 408 MB |
| Self-compile, collections | 46 | 36 |
| LSP, 100 edits each re-analysed: steady / peak RSS | ~505 / ~655 MB | ~417 / 585 MB |
| `vader test vader`, wall time | 20.9 s | 21.6 s (+3 %) |
| `vader test vader`, peak RSS | 1378 MB | 1019 MB (−26 %) |
| `vader test vader`, majors | 26 | 39 |

The self-compile peaks 5 to 10 % higher at age 1. Compiling the small snippets CI
compiles is 1.8 % faster and takes 1 to 5 MB more per process. The 27 native
benchmarks and the 7 VM ones stay within noise: most never collect. The 3 % on
`vader test vader` assumes freed large old regions binned by size (`3f6a8f5db`);
under the linear best-fit search before it, it was 10 %.

An adversarial program, a ring of cells that each live about one minor, runs
faster at age 1 (−21 % and −31 % on the two larger windows) but holds more
memory: 68 MB grows to 141 MB on the smallest window, 444 MB to 620 MB (+40 %)
on the largest.

Other runtimes: OCaml promotes every survivor of a minor, and bounds the floating
garbage with an incremental major paced by promotion (`space_overhead`). V8 and
.NET promote at about the second survival. HotSpot starts at 15 and lowers the
threshold once survivors overflow their space, which a self-compile would
trigger. Ruby ages to 3, but its young objects do not move, so ageing costs it no
copy.

## Decision

`VADER_TENURE_AGE` is 1: a minor promotes every object that survives it. The
constant stays `-D`-tunable.

## Consequences

- A long-lived object is copied once, straight into the old slab.
- A medium-lived object reaches the old slab and waits there for the next major,
  which starts only once the old footprint passes `live × 1.5`
  (`VADER_GC_OLD_HEADROOM_NUM/DEN`), and never below 64 MB
  (`VADER_GC_OLD_MAJOR_FLOOR`). Those two knobs bound the floating garbage. What
  OCaml adds, and Vader does not have, is a major done in slices as it promotes.
- `vader test vader` is slower: every survivor is promoted, majors are more
  frequent, and more freed small slots are reused, which are scattered.
- Young to-space becomes a fallback: it receives an object only when the old
  reservation cannot take it. The two halves still swap at every minor, so
  allocation uses both.
