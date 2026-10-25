# 0111: An async singleton shares one task

## Status

Accepted (2026-10-25). Amends 0068: a singleton may await.

## Context

0068 refused a singleton that awaits (T3103): a body that suspends would let
another call see the instance half built. Lifting it ran into what an `async` call
returns. It does not run the body: it builds a frame, and whoever awaits drives
it with `resume`. Kept as the instance, the frame would serve the first await
only: once finished, a coroutine answers `Suspended` to every later `resume`, so
a second `await` would never complete. `race`, `join_any` and `timeout` also
`cancel` their losers, and a cancelled frame tears itself down, under every other
awaiter of a shared one.

## Decision

- **An `async` singleton keeps a shared task.** `std/async` gains `share(x)`, an
  awaitable that drives `x` until it completes and then hands its result to every
  later `resume`. Several awaiters may drive it, each `resume` advancing the one
  task. Its `cancel` does nothing, so a loser of a `race` leaves the task to the
  others. A `resume` that comes while the task is being driven comes from inside
  it: the body awaits its own task, which panics. The accessor keeps
  `share(init())`, so every call awaits one run of the body.
- **`share` lives in `std/async`, not in the prelude.** The prelude cannot trap:
  `panic` is in `std/abort`, kept out of `std/core` so that every program's
  interning order stays as it is. The lowering finds `share` as it finds
  `run_async_main`, and an `async` singleton in a program that does not import
  `std/async` is T3103.

## Consequences

- Set aside: a frame that keeps its own result after completion. It would touch
  every `async` function (a field per frame), and a shared frame would still need
  to ignore `cancel` and catch a re-entrant `resume`.
- `share` is public: any awaitable can be awaited more than once through it.
