# 0127: Concurrency is tasks on virtual threads, checked on the data

## Status

Accepted (2026-11-07). Replaces 0111. Amends 0060, 0068, 0090 and 0119.
Amended (2026-11-08): the `Async<T>` trait leaves `std/core` too, since nothing
implemented it and nothing called it.
Amended (2026-11-08): cancelling a task cancels the tasks it launched, and the
combinators that cancel cancel their tasks when the task waiting in them is.

## Context

Concurrency was stackless: a function that used `await` declared `-> Async<T>`
and was compiled into a state machine, resumed by whoever awaited it. It split
functions in two kinds, and every caller of an async function had to be one.

- The lowering hoisted each `await` ahead of its statement (an ANF sink), so the
  operands evaluated before it had to be bound first, and an `await` that runs
  only sometimes could not be hoisted: the right operand of `&&`, `||` and `??`,
  a loop condition and a `match` guard refused it (M5009), as did a nested lambda
  and a `defer` body (T3064).
- A task was a frame of the state machine: only a suspended async function could
  be cancelled, a finished one answered `Suspended` to every later `resume`, and
  awaiting one value twice needed `share` (0111).
- A hand-written awaitable implemented `resume` and reported its deadline in
  `Suspended.wake_at`, a protocol every combinator had to follow.
- Nothing stopped two coroutines from writing the same value; with threads, the
  same program would race.

## Decision

- **One kind of task.** `launch(entry)` (`std/task`) runs `entry` on a virtual
  thread: a stack of its own, 8 MiB reserved and committed as it is written. A
  task parks wherever it waits, however deep in its calls; nothing marks a
  function as one that may park. `t.join()` gives back the result, the same at
  every join. The scheduler is C (`runtime/c/rt/sched.c`); the VM serves its
  primitives through the host's.
- **`await` leaves the language**, with `-> Async<T>` as a marker and the
  `Async<T>` trait, `Suspended`, `block_on`, `share` and `std/async`. Generators
  stay stackless: they are iteration, and a stack per generator would cost an
  allocation per `for`.
- **Safety is decided on the data**, at the gates a value crosses between tasks:
  the captures of the lambda passed to `launch`, the result of a `join`, a channel
  message, the value of a `Shared`, a `@singleton`, a function value a task runs.
  The effect summary says what each side does to the value until the `join` that
  ends the task; a value both sides only read, or that only the task touches,
  passes, any other mix is an error naming both sides (T3128 to T3135). Nothing
  is written in user code.
- **The synchronised types are a closed list** the compiler knows, in `std/task`:
  `Task`, `Channel`, `Shared`, `AtomicInt`, `AtomicBool`. `deep_copy` (`std/core`)
  is the way out the errors propose.
- **Cancellation runs the task's pending defers** on its own stack, and its
  `join` gives `Cancelled`. A combinator returns once every task it cancelled has
  run its defers. When `main` returns, the tasks still running are cancelled,
  stderr names them, and the exit code is not zero.
- **Cancellation cascades by launch.** A cancelled task first cancels the tasks
  it launched that still run, and waits for them, then runs its own defers. The
  check counts the `join` that follows a launch as the end of the task; a task
  cancelled inside that `join` used to leave the joined task running while its
  caller went on, a race the check accepted. Cancelled first, the children keep
  under cancellation the order of the normal path: a defer placed before a `join`
  runs after the end of the joined task. What the defers launch runs on, as what
  a task launches does when it returns. The runtime keeps the launcher of each
  thread, so the rule holds for every thread, those of `std/runtime/scheduler`
  and the VM's guest threads included. `try_join_all`, `race`, `join_any` and
  `timeout` cancel their tasks in a defer, for the tasks another task launched.
- **A singleton that returns a `Task<T>`** replaces the async singleton: a task is
  joined as often as needed. A `@singleton` and a constant whose value runs code
  wait on a gate while another thread builds them, in a program that loads
  `std/runtime/scheduler`; the same thread coming back still stops the program.

Set aside:

- **Keeping the stackless form beside tasks**: two models of one thing, and the
  ANF machinery stays with its restrictions.
- **A keyword** (`async e`, `spawn e`): `async` reads as Node's, where a function
  is coloured, and `spawn` is taken by `std/process`. A lambda literal already
  says what runs in the task and is where its captures are ranged.
- **Annotations at function boundaries** (`Send`, `Sendable`, `sending`): Vader
  sees the whole program, so the summary deduces what they would state.
- **An implicit copy at each gate**: a hidden cost, and a value written on one
  side would silently stop being seen by the other.
- **A `scope` that joins its tasks**: the position of the `join` already bounds a
  task for the check.
- **Cancelling the children after the defers of their launcher**, from
  `std/task`: a defer placed before a `join` would run while the joined task still
  runs. The order kept has a price: a defer of the cancelled task cannot ask its
  children to stop by a message, they have stopped already.
- **No longer counting a `join` as the end of a task**: the check would refuse a
  task that waits for the tasks it launched, the common shape.
- **The tasks launched by the defers of a cancelled task born cancelled**: one
  cancelled before it starts never runs the end of `std/task`, so a `join` of it
  in that defer would wait forever.

## Consequences

- A switch costs 20 to 30 ns on macOS arm64, a parked thread 17.5 KiB resident
  (5.2 KiB on Linux, 6.3 KiB on Windows), measured 2026-11-07 on 10 000 parked
  threads. The task check adds about 7 % to the type check of the compiler
  (580 to 620 ms).
- Tasks share one system thread for now; the rules are those of tasks spread over
  cores, so a program keeps its meaning when they are.
- I/O in `std/io` blocks every task. A stop runs the pending defers of the thread
  that stops, not those of the others.
- A defer of a cancelled task's child that waits for what only a defer of the
  cancelled task provides is a deadlock.
- A task the cascade cancels before it starts, one launched by a task that
  cancels itself before it parks, is never marked ended: a `join` of it waits
  forever.
- `M5009` and `T3064` are retired, and the `async` case of `T3103` with them.
