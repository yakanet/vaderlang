# 0130: A poll of stdin waits for the reader's read instead of cancelling it

## Status

Accepted (2026-11-08). Amends 0128.

## Context

On Windows, a wait for stdin on a pipe is a read of no byte, which a thread of
the runtime makes (the reader): the handle a program inherits takes no
overlapped I/O. A wait given up leaves that read under way, and the system makes
every other operation on the pipe wait behind it, a peek included. `poll_stdin`,
alone, peeks, so it cancelled the read first (`CancelSynchronousIo`, in a loop,
since the reader may not have begun it).

Under load, the reader may begin its read only once the poll cancels. A cancel
that lands while the reader enters `ReadFile` is lost: the read stays under way,
and `CancelSynchronousIo` returns only once it ends, that is once data comes. A
program then polls past its deadline; the virtual threads fixture, whose harness
writes to stdin only after the poll's message, never ends. Traced beside a full
suite: 25 to 38 hangs in 1200 runs. Fed after 5 s instead, 74 runs in 900
resumed, each read ending with success and the cancel returning only then.

## Decision

- **The read is never cancelled.** It ends once the pipe holds data or has lost
  its writer, which is what a poll asks. A poll that finds it under way waits
  for it within its deadline (`await_stdin_reader`, `system/windows`), answers
  false when the deadline comes first, and peeks only once no read is under way.
- **A read of stdin changes nothing**: it waits behind the reader's read, as it
  would wait for data.

Set aside:

- **A reader that peeks in slices instead of reading**: nothing would be left
  under way, but a thread waiting on stdin would wake at every slice.
- **Reopening the pipe for overlapped I/O**, to cancel with `CancelIoEx`: an
  anonymous pipe is not guaranteed to reopen that way.

## Consequences

- `CancelSynchronousIo` leaves the runtime.
- A read made for a wait given up stays under way until data comes or the
  writer goes, on the reader's own thread.
