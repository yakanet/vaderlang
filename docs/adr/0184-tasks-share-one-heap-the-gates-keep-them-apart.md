# 0184: Tasks share one heap, the gates keep them apart

## Status

Accepted (2026-11-26). Amends 0127. Not implemented yet: the global monitor
still stands in the code until the redesign of the concurrency model replaces
it.

## Context

The task model of 0127 was designed for one system thread. Spreading tasks over
several workers (0163, 0166) kept its centre: one global monitor, which is two
things at once.

- **The lock of all shared state**: a `Shared`, the atomics, the records of the
  tasks, the gates of the `@singleton`s. It is re-entrant and released at every
  park, which is why a `locked` body may not park (T3132).
- **The gate of the collector**: each worker has a private young generation
  (0163), and a value that becomes reachable from another worker must leave it
  first. Entering the monitor to publish (`locked`, `launch`, the end of a task,
  `send`) runs a full minor of the worker as soon as the value reaches its
  young generation.

Measured on 8 workers (macOS arm64, native release, 2026-11-26): an
uncontended lock costs 6 to 14 ns, a forced minor 1 to 3 µs with an almost
empty young generation, about a hundred times the lock. A `locked` whose body
captures a variable pays it, though nothing is published: the closure was
allocated in the young generation just before.

Three memory models were weighed against a corpus of fifteen programs:

- **A, shared memory made safe by inference**: the evolution of 0127.
- **B, isolated tasks and messages** (Erlang, Goose): a heap per task, a value
  moved when its sender is done with it, copied otherwise; no `Shared`, the
  state is a task one queries. Noisy for small shared state, and a copy of a
  pointer-rich graph costs about 25 ns per object (`deep_copy`), more than
  building it.
- **C, owned resources and atomic behaviours** (Verona): a body never waits,
  a result comes back through a task.

For the collector: a parallel minor that stops every worker (OCaml 5), a
promotion at the gate with no global lock, or heaps that follow the tree of
launches and pin what crosses (MaPLe).

## Decision

- **One heap, isolation checked statically.** The gates of 0127 decide what a
  task may touch; the heap is not split per task. The language keeps `Shared`
  with a lock per value, adds `freeze` (0185), moves a value at a gate when its
  sender is done with it, and copies only where `deep_copy` is written.
- **The private young generation per worker stays.** A parallel minor that
  stops every worker would be a step back; heaps per task tree only serve
  fork-join and cost the most.
- **The monitor splits in two.**
  1. A lock per `Shared`, which parks the virtual thread that waits for it
     (0183). `locked(a, b, f)` takes several in a fixed order.
  2. The gate of the collector becomes a promotion at publication (a send, a
     launch, a write into a `Shared`, a `freeze`), tied to no lock. Under a
     lock, a worker still allocates in the old generation.
- **The major collection keeps stopping every worker.** A concurrent mark comes
  if pauses call for it. Moving a started task stays out of scope (0163).

## Consequences

- The records of the tasks, the gates of the singletons and the atomics need an
  exclusion of their own; the atomics become real atomics. The monitor then
  goes.
- What the monitor kept per worker (allocating in the old generation while
  held, the objects born there and published at release) moves to the task: a
  task parked under a lock lets its worker run others, which allocate in the
  young generation.
- A deadlock between locks is possible and must be reported with the holders
  named.
- A cheap publication is the core of the work, not an optimisation. Two steps
  come first, apart from the redesign: a minor whose card scan follows the
  dirty groups instead of every old region (done, 2026-11-26), and a `locked`
  that publishes nothing when its body writes into the guarded value only
  scalars, strings or what it allocates itself. Promoting only the subgraph
  given away, with forwarding pointers, is decided after measuring those: it
  would make the gate check carry memory safety, not only the absence of races,
  with `VADER_GC_VERIFY` as its net.
