# 0135: A descriptor is watched for a read and for a write, and released before it closes

## Status

Accepted (2026-11-13). Amends 0128.

## Context

The scheduler watched a descriptor for a read (0128). A socket needs more:

- a write to a socket whose buffer is full, and a connection under way, wait
  for the descriptor to take a write;
- two tasks hold one connection, one reading and one writing;
- a task parked on a socket another task closes waited for ever, and the
  system hands the number of a closed descriptor out again, so the park could
  then end on a socket that is not the task's.

The watches were a flat array, searched at each watch and at each report. With
one connection exchanging and the others parked, the time spent in the runtime
grew with the parked ones: 0.03 s for 20 000 exchanges with none, 0.17 s with
3 000.

## Decision

- **A watch is a kind and an identifier**, and there is one at most of each:
  a descriptor to read, a descriptor to write, a child to end. They are kept in
  an array with no hole and found through an open-addressing index, so a watch
  and a report cost the same whatever the number of watches.
- **One thread a side.** A second thread that watches what another already
  waits for is not refused: it sleeps as for a watch the system will not take
  (0128), then checks again.
- **The system follows both sides.** kqueue takes one one-shot filter a side.
  epoll holds one registration for a descriptor: it is armed with the sides
  waited for, and armed again with the side left once it has reported the
  other.
- **`wait_writable` and `wait_writable_for`** (`std/runtime/wait`) mirror the
  two waits for a read. They are intrinsics: the task check counts them as
  calls that park.
- **`stop_waiting(fd)`** ends the parks on `fd`, each returning as if `fd` were
  ready, without asking the system about `fd` again. The owner of the
  descriptor calls it before closing, and marks the descriptor closed first:
  the woken task reads that mark, never the descriptor.
- **Windows** watches for a write only a socket it follows (0136): on any
  other handle the wait returns at once.

Set aside:

- **A list of waiting threads a side**: several tasks accepting on one listener
  would wake without the sleep. No program needs it today.
- **A function of the runtime bound with `@extern`** in place of the
  intrinsics, which needs no new seed: the task check would not know the call
  parks, and a write made while holding a lock would pass.
- **Closing the descriptor and letting the system report it**: kqueue and epoll
  drop a closed descriptor without a report.

## Consequences

- `std/net` parks a write to a full socket and a `connect`, and a `close` ends
  the reads, the writes and the accepts parked on the socket.
- The time spent in the runtime no longer grows with the parked connections:
  0.05 s for 20 000 exchanges with 3 000 of them. What the kernel spends still
  does.
- The seed is regenerated: the VM serves the waits of the program it runs with
  the host's own.
