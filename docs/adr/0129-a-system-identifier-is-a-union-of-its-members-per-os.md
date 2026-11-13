# 0129: A system identifier is a union of its members per OS

## Status

Accepted (2026-11-08). Amends 0128.

## Context

Descriptors, pids and Windows handles travelled as `i64`: `watch_readable(fd: i64)`,
`watch_exit(child: i64)`, `wait_readable(fd: i64)`. An `i64` adds and multiplies,
yet the value only goes back to the system that handed it out. `ChildProcess`
had two shapes, a pid and two descriptors on POSIX, three handles stored as
`u64` and read back through `ptr_at` on Windows, and `await_child` two bodies.

## Decision

- **One member per OS, one union per kind.** `Fd` and `Pid` (`system/posix`)
  are distinct types over `i32`; `PipeHandle` and `ProcessHandle`
  (`system/windows`) over `CPointer`. `Descriptor :: Fd | PipeHandle` (`std/io`,
  with `STDIN`; a third member since 0136) and `Process :: Pid | ProcessHandle`
  (`std/process`) are what the standard library hands out and takes back.
- **The union is opaque.** It compares with `==` and nothing else: no operator,
  no conversion to or from an integer, no interpolation, no ordering. The only
  way to the integer is to name a member (`is Fd`, `Fd(42)`), so to import
  `system/posix`.
- **The members stay exported**: a program written for Linux alone can take its
  `Fd` back. Members only `system/*` and the standard library may use are left
  for later.
- **Two kinds, not one `SystemHandle`**: on POSIX, a pid passed for a descriptor
  would then go unnoticed.
- **The members of the Windows kinds are over `CPointer`, not `Handle`**: a name
  over a distinct type is an alias of it, and the two kinds would pass for one
  another and for any `Handle`. A Win32 call takes `Handle(d)`.
- **The system calls of `system/*` keep `i32` and `Handle`**; the standard
  library converts, in a body selected per OS, by an `@unreachable match` that
  stops the program on the other member.
- **The scheduler's intrinsics keep machine words** (`i64`), which is what C and
  the VM exchange. The VM serves a guest by calling the host's own functions,
  and it could not rebuild a `PipeHandle` from an integer.
- **The waits on a descriptor live in `std/runtime/wait`**, a module that imports
  nothing; `std/io` wraps them over `Descriptor`. This amends 0128, where
  `std/io` exported them in `i64`.

Set aside:

- **A distinct type over `i64`**: it takes the operators of its backing, so
  `fd + 1` compiles, and `Descriptor(42)` makes one from any integer.
- **The waits in `std/runtime/scheduler`**: `std/io` would load the scheduler,
  and a program that loads it puts a gate on every `@singleton` and every
  computed constant. A hot loop reading a singleton and a computed constant
  took 0.97 s without it and 1.18 s with it (native, `--release`, nine
  alternated runs).
- **Gates armed only when a program refers to `spawn_thread`**, the one way to
  a second thread: a change to the lowering for a cost this module avoids.
- **A private intrinsic in `std/io`** that the VM serves through the scheduler's:
  two declarations of one intrinsic.

## Consequences

- `ChildProcess` holds `process`, `out_pipe` and `err_pipe` on every OS,
  `await_child` has one body, and `drain_pipe` takes the pipe it drains.
- `ptr_at` remains for the handles `create_watched_pipe` writes into a lent
  buffer, and for the placeholder `run_attached` hands `CreateProcess`: a
  `CPointer[]` does not cross the FFI.
