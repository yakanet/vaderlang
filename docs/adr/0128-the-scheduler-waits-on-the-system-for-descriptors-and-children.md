# 0128: The scheduler waits on the system for descriptors and children

## Status

Accepted (2026-11-08). Amends 0127.

**Amended by [0129](0129-a-system-identifier-is-a-union-of-its-members-per-os.md)
(2026-11-08)**: the waits on a descriptor live in `std/runtime/wait`, in machine
words, and `std/io` wraps them over a `Descriptor`.

## Context

Tasks share one system thread (0127). A read of stdin blocked it, and every task
with it. `spawn` polled its child and slept 2 ms between two polls: 500 wakes a
second per child, and up to 2 ms added to the end of each. With no thread ready,
the scheduler could wait for the nearest sleep and nothing else.

## Decision

- **Watch, then park.** `watch_readable(fd)` and `watch_exit(child)`
  (`std/runtime/scheduler`) make the running thread's next park end on the
  event. A watch lasts that one park, which a `wake` can end first; the contract
  of `park` already allows a wake meant for something else, so the caller loops
  on what it waits for. A watch is one more source of wakes, not a new kind of
  wait.
- **The system follows them**: kqueue on macOS, epoll on Linux, where the end of
  a child reads on its pidfd, which the runtime opens and closes. Registrations
  are one-shot, and the scheduler drops a watch whose thread has parked again or
  ended.
- **Windows waits on a completion port.** An anonymous pipe takes no overlapped
  read, so the pipes of a child are named pipes the runtime makes, and a watch
  is a read of no byte on the parent's end: it ends once the pipe holds data or
  has lost its writer, and takes nothing. The thread pool waits on a copy of the
  child's handle (`RegisterWaitForSingleObject`) and posts its end. stdin, a
  console or an anonymous pipe, is waited on by a thread of its own: on a pipe
  it reads no byte, on a console it reads ahead and keeps the text for the next
  read, since a console echoes what is typed only while a read is under way.
  The library reaches the console's text and the named pipes through two
  functions of the runtime it binds (`vader_console_read`,
  `vader_overlapped_pipe`): no intrinsic, so no seed to regenerate.
- **A watch the system refuses ends the park after 2 ms**: no pidfd (Linux
  before 5.3), a descriptor epoll does not follow, a handle opened without
  overlapped I/O, on which a read of no byte would block.
- **Once a turn, at most every millisecond.** With a watch set, the scheduler
  reads the clock each time it has run every thread that was ready, and asks the
  system without waiting when a millisecond has passed since it last answered.
  Threads that never park do not starve one that watches, and a turn costs a
  clock read, not a system call. With none ready, it waits on the system until
  the nearest deadline. A deadlock is no thread ready, no sleep and no watch.
- **The virtual clock** counts the sleeps alone: with no thread ready, the
  scheduler asks the system without waiting, jumps to the nearest deadline when
  the system has nothing, and waits on the system when no sleep is pending.
- **stdin**: `std/io` calls `wait_readable(0)` before each read. It parks until
  the descriptor reads, and returns at once when no other thread exists, so a
  program without tasks reads as it did. It belongs to `std/io`: loading
  `std/runtime/scheduler` arms a gate on every `@singleton` and computed
  constant, and almost every program loads `std/io`. It is exported because the
  VM serves it by calling the host's. The task check counts it as a call that
  parks, so a read of stdin while holding a lock is an error.
- **A wait with a deadline**: `wait_readable_for(fd, nanos)` (`std/io`) watches
  `fd` and arms a timer for the same park, which ends on whichever comes first,
  and reports whether `fd` reads; `wait_readable` is its case with no deadline.
  `poll_stdin` parks on it, then asks the system, which answers at once after a
  wait that saw stdin read, and waits itself when no other thread exists. The
  deadline sits beside the watch: a combinator such as `timeout` cancels a task
  when time runs out, and nothing ends a park on a descriptor from outside.
  On Windows, the reader's read of no byte on a stdin pipe outlives a wait
  given up, and the system makes every other operation on the pipe wait behind
  it until data comes: stdin is not ready while it is under way, and
  `poll_stdin`, alone, ends it (`CancelSynchronousIo`) before it peeks.
- **`spawn`** watches the pipes it has not drained to their end and the end of
  the child, then parks; each wake drains and reaps as the poll did.

Set aside:

- **`SIGCHLD`** for the end of a child: state of the whole process, a handler a
  program may install, and `EINTR` in every wait.
- **pidfd alone**: `spawn` would stop working on Linux before 5.3.
- **The watch carried by the park** (`park_until_readable(fd)`): one primitive per
  kind of wait, and `spawn`, which waits for two pipes and a child, could not say
  so.
- **Asking the system at every turn of the ready queue**, the first version: a
  `kevent` without waiting costs 12.4 microseconds on macOS, a clock read 15 ns.
  Two threads handing control to each other 2 million times took 12.5 s instead
  of 0.16 s while a third waited on stdin; asked at most every millisecond,
  0.16 s.
- **Backing off by turns** (twice as many turns skipped after each question that
  finds nothing): no clock read, but nothing bounds the wait in time when the
  threads compute between two switches.
- **The reactor on a system thread of its own**: the ready queue would need a
  lock on every switch.
- **`WaitForMultipleObjects` on Windows**, events in place of the port: 64
  handles at most, three per child, which a parallel build on a large machine
  passes.
- **A job object posting the end of a child to the port**: Windows does not
  guarantee its messages arrive.
- **A console thread that only waits for a key**: the console would echo
  nothing while the task waits, and the read would then block until Enter.

## Consequences

- `spawn` wakes when its child writes or ends.
- While threads run, a descriptor that becomes ready, or a child that ends,
  waits up to a millisecond and a turn before its thread is woken.
- Writes and file reads still block every task.
- On Windows, a console read ahead for a task that is then cancelled keeps its
  line for the next read of stdin, which a child started by `run_attached`
  would otherwise have read.
