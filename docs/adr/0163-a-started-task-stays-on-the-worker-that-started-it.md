# 0163: A started task stays on the worker that started it

## Status

Accepted (2026-11-20), on the branch that spreads tasks over several cores.

## Context

With several workers, each worker has a young generation of its own, which only
its own minors collect: no other worker holds a pointer into it, so a minor needs
no synchronisation. A task launched under the monitor waits, unstarted, in a pool
any worker takes from; once a worker starts it, the task never leaves it.

Pinning leaves load imbalance: tasks that park as soon as they start (pool workers
waiting for jobs) used to pile up on the first worker to look. Starting a task on
the worker with fewest tasks, among those resting or just roused, fixed most of it:
`bench/tasks_pool` on 8 cores went from a median of 0.17 s to 0.06 s. On 2 and 4
cores, runs stay bimodal: a task count says nothing of which tasks compute, and the
right placement depends on a load nobody knows when the task starts.

Moving a started task to a resting worker, as Go does, was explored and measured.

## Decision

A started task stays on its worker. Balance comes from where an unstarted task
starts, never from moving one that started.

Moving a started task meets two obstacles:

- **The C compiler caches the worker's address.** `vader_worker` is thread-local;
  clang computes its address once per function and keeps it in a callee-saved
  register across calls. In `tasks_pool`, `std_task$receive__i64` takes it on entry
  and still writes the worker's `defer` stack through it after
  `vader_scheduler_mutex_wait`; every emitted function pops its shadow frame
  through `vader_gc_top` the same way. A task resumed on another system thread
  would write the state of the worker it left. No C option forbids the caching.
- **The collector needs a promoting minor.** An old object of the worker left may
  point into its young generation, and the moved task may reach it. Moving the task
  requires that nothing old points there any more: a minor of that worker that
  promotes every live young object, not only what the task reaches, which would
  need a trace of the old generation.

Rejected:

- reading the worker through an opaque function at every access: measured from +2
  to +12 % on the benches, +28 % on `task_switch`;
- keeping the state of a running thread (shadow stack, defers, the mutex it let go)
  in the virtual thread's record, reached through a `self` the emitted code holds,
  and the worker through `self->worker`, which C reads again after a call: it is
  the sound form of moving tasks, but it changes the emitted code of every function
  and the runtime with it, for a case pinning plus balanced starts leave narrow;
- waking first a parked receiver whose worker rests, to send work where a core is
  free instead of moving tasks: `tasks_pool` medians on 2, 4 and 8 cores barely
  moved (332 to 288 ms, 228 to 229, 66 to 66).

## Consequences

- Tasks that compute for long without parking, with unequal loads, can leave a core
  idle while another runs two of them.
- The young generation stays private to its worker, and a minor needs nothing from
  the others.
- Reopening this means first moving the running state into the thread's record, so
  that no emitted code holds the worker across a park; the promoting minor comes
  after.
- What a minor costs no longer grows with the old generation (the card tables keep
  a byte per group of 64 cards), which a promoting minor would also need.
