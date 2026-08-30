# Architecture decision records

One file per decision, `NNNN-kebab-title.md`, numbered in the order they were
taken. A record is **append-only in spirit**: when a decision is reversed, add a
new record that supersedes it and mark the old one, rather than editing history.

## What goes here, and what does not

A record holds the reasoning: what was tried, what was measured, which hypotheses
fell, why one design won over another, and what the code used to do. A comment
holds what the reader of the code below it needs — the constraints it must
respect, and whatever makes it hard to read. Nothing else.

The split is about lifetime. A record is read years later by someone asking "why
is it like this?". A comment is read by someone in the middle of a file who needs
to not break it, and is almost never revisited — which is why a conclusion written
there and later disproved becomes a lie nothing makes the reader doubt.

Benchmark figures belong here for the same reason: they are true of one machine on
one day. A one-line pointer from the code to a record is fine and often useful.

The rule lives in the project's coding-style guide (§2 and §8).

## Format

Status / Context / Decision / Consequences. Short. A record that needs ten pages
is usually two decisions.
