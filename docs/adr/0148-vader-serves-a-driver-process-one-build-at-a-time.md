# 0148: `vader` serves a driver process, one build at a time

## Status

Accepted (2026-11-14). Completes
[0145](0145-a-build-driver-is-a-thin-client-that-re-reads-the-sources.md):
the driver leaves `vader`'s process.

## Context

0145 made a project's driver a thin client of the `vader` that starts it, over
its standard streams. What it left open is what crosses the pipe besides the
events and requests: how a driver starts, what its command line carries, how a
build ends, what a driver that hangs up or goes silent means, and how a driver
that builds twice shares one pipe.

## Decision

- **A driver starts with four arguments**: the project folder, the mode, the C
  compiler `vader` resolved and the linker flags. The rest of the command's
  request stays with `vader`, which runs the build.
- **A build opens with the configuration, what the driver did before pulling
  the stream, then `Next`.** A module asked for before the stream is read by
  the first round.
- **The end frame carries the build's outcome and the generated files.** Once
  the driver had its say on it, the build prints what it holds, then takes the
  driver's requests until the driver's exit stops it, which prints the rest:
  the build alone decides that a module came too late, and the driver prints
  only the reports of a context that opened no build.
- **A driver whose output ends stopped.** Before a configuration, it started
  no build; during one, the build closes on what arrived, and a crash fails
  through the driver's exit code. The exit code of the command is the worst of
  the builds' and the driver's.
- **Builds run one at a time.** Opening a build stops the one left open, and
  `vader` serves builds one after the other until the driver's output ends.
- **What is bounded is the driver's silence**: ten minutes for each frame
  `vader` waits for, after which the driver is killed. The project's
  compilation is `vader`'s and does not count.
- **A driver is a debug build, cached on its source and the fingerprint of
  `lib/toolchain`**, which the driver also sends in its configuration; a
  driver whose fingerprint differs is refused with a message, not rebuilt
  behind the user's back, since its side effects would run twice.

## Consequences

A driver compiles from `lib/` alone: a cold driven build of a small project
fell from about 4 s to under 1 s, and a new `vader` with the same
`lib/toolchain` reuses the cached driver. A driver no longer runs on its own:
it waits for `vader` on its standard input.

A cached driver keeps the `std` and C runtime it was linked with until its
source or `lib/toolchain` changes.

`std/process` cannot wait for a child with a deadline, and a task may not share
the child another one reads: the bound is a task that sleeps, then kills a copy
of the child, the same process. A wait with a deadline in `std/process` would
replace it; it needs the scheduler to end a park at a given time.

The compiler's sources are no longer needed to build a driver.
