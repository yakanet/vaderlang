# 0001 — Comments explain the code; reasoning lives in an ADR

## Status

Accepted (2026-08-30).

## Context

Comments in this tree had started carrying the reasoning that produced the code:
what was tried, what was measured, which hypothesis fell, which flag reproduced a
bug. Two problems surfaced on the same day.

A conclusion written into a comment and later disproved becomes a **lie sitting in
the source**. One added during a GC hunt claimed a fix closed a bug; the next
measurement showed 80 errors before and 80 after. Had it been committed, nothing
would have made a later reader doubt it.

And a comment is the wrong container: it holds neither a table of eliminated
hypotheses nor a reproduction command, so the narrative crowds out the constraint
the next reader actually came for.

A measurement in the comment ages badly for a third reason — a benchmark figure is
true of one machine on one day, and nobody re-runs it when the comment is next
read.

## Decision

A comment serves the reader of the code below it. It explains code that is hard
to read, and the constraints that code must respect. Nothing else.

The reasoning that produced the code goes in `docs/adr/`.

The line: *"do not swap these two lines, a GC can land between them"* is a
constraint and stays. *"We tried A, it failed, hence B"* is reasoning and leaves.
So does any date, tool name, run outcome, commit hash, or benchmark number.

A one-line pointer from the code to the record is fine.

Applies to every language in the tree, `runtime/c/` included.

## Consequences

`docs/adr/` is created and versioned, so a record survives a clone.

A sweep over the existing tree is owed. Measured 2026-08-30, on the tree at
`468b0a1ef`:

| zone | files | code | comment | ratio |
|---|---|---|---|---|
| `vader/` | 248 | 66 234 | 26 871 | 0.41 |
| `lib/` | 50 | 9 582 | 5 031 | 0.53 |
| `runtime/c/` | 2 | 3 671 | 1 924 | 0.52 |
| `tests/` (.ts) | 30 | 3 834 | 1 889 | 0.49 |
| **total** | | **83 321** | **35 715** | **0.43** |

Nearly four comment lines per ten of code. But the shape matters more than the
ratio: `runtime/c/` holds **446 blocks, median 3 lines, mean 4.3** — one every
~8 lines of code — and the 19 blocks of 15 lines or more are only 18 % of the
total. It is uniform density, not a handful of essays, so it cannot be fixed by
deleting a few blocks.

And the narrative share is small: **111 comment lines out of 33 842 carry a
narrative or measurement marker — 0.33 %**, some of them still false positives.
That is a few dozen sites, well under the threshold where tooling pays for itself.

⚠️ A first pass at that figure said 2.2 %, and was wrong: the pattern matched
"the **old** generation", "the old slab", "the old live set" — the old *heap*, not
the past. Worth remembering before acting on a regex over prose.

By hand is the point: several of those sentences are constraints wearing a
historical tense (*"splitting used to give every function external linkage, which
forbids `cc` from inlining"*). Those get rewritten in the present, not deleted.

Recorded in the project's coding-style guide, §2 and §8.
