# 0166: A worker allocates in old regions of its own

## Status

Accepted (2026-11-21), on the branch that spreads tasks over several cores.

## Context

The old generation hands out small objects from regions of 256 KB, one size
class per region, and keeps for each class one current region and one free list
that the sweep of a major rebuilds. Every allocation in old took one lock as
soon as several workers ran. A minor promotes each survivor into old, so each
promotion took the lock, and the minors of the workers run at the same time.

Measured on an Apple M-series laptop:

- six rounds of eight tasks, each building 150 000 linked structs that hold a
  string and an array, part of them kept: 2.36 s on one worker, 3.04 s on
  eight, with 15.4 s of system time spent waiting for the lock;
- the parse of the modules of `vader check` spread over tasks: faster on two
  workers, slower on four and eight than on one, the minors of the workers
  waiting for the lock in `vader_gc_evacuate`.

## Decision

A region of small objects belongs to at most one worker at a time:

- each worker keeps one current region per size class and allocates in it
  without the lock: from the free slots of the region, then from its bump;
- the lock is taken only to take a region: one with room from the pool of its
  class, else a fresh one carved from the reservation;
- the free slots belong to their region, not to the class;
- the sweep of a major, which runs with the world stopped, takes every region
  back from the workers, rebuilds the free slots of each one and puts each
  region with room in the pool of its class;
- the bytes a worker allocates in old are counted in the worker and added to
  the total at the end of each of its minors and when it takes a region: the
  readers of the total (the trigger of a major, the size of young, the
  statistics) compare it to thresholds;
- a large object keeps its region of its own, taken under the lock.

The worker that owns a new object is the one whose memory receives it: the
worker collected for a promotion, the copier for `deep_copy`, the running worker
for an allocation under the monitor.

Rejected:

- a cache of free slots per worker over the free lists of the classes: the
  structure stays shared, and the cache is one more state to keep in step;
- one atomic bump per class shared by the workers: the contention moves to one
  cache line;
- an atomic addition to the total on each allocation: one shared write per
  promoted object;
- regions per worker for large objects: they are rare, and each one already
  costs a region.

## Consequences

- The load test above takes 0.78 s on eight workers, with 0.6 s of system time;
  the parse spread over tasks shortens the load of `vader check` as workers are
  added.
- A worker holds up to one partly filled region per class it allocates in: at
  most 16 MB per worker if it touches every class.
- The total of old bytes lags by what each worker allocated since its last
  minor.
- One worker behaves as before: one current region per class, no lock.
