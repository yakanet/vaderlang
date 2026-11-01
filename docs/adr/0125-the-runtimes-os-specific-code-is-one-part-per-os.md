# 0125: The runtime's OS-specific code is one part per OS

## Status

Accepted (2026-11-01).

## Context

The services of the OS had left the C runtime for `@extern` bindings in
`lib/system`, the async scheduler and the profiler for Vader. What stayed was
still written per OS, as 31 `#if` spread through seven parts: reserving and
committing the old generation, the RAM probe, the C stack's base for the
conservative scan, the VM's library loader, a fatal report on a Windows console,
binary standard streams, and the accessors of 0013 and 0124. A reader of the
collector met `mmap` and `VirtualAlloc` side by side, and nothing listed what a
new target has to provide.

Odin splits its portable layer by concern and by platform (`dir_windows`,
`dir_posix`, `file_windows`, ...). At this size, about 270 lines across both
OSes, that is nine files of 10 to 80 lines.

## Decision

One part per OS: `rt/os_posix.c` for Linux and Darwin, `rt/os_windows.c`. The
unity includes the part of the OS it builds for.

The other parts call a `vader_os_*` function that `rt/internal.h` declares, and
each OS part defines all of them, as a no-op where its OS has nothing to do
(committing pages on POSIX, text mode, the console). The accessors and the
library loader keep the names `vader.h` gives them and move as they are.

The differences within POSIX (Darwin's `st_mtimespec`, its stack base, `.dylib`)
stay as `#if` inside `rt/os_posix.c`.

`rt/host.c` keeps what every host defines whichever OS binds it:
`vader_last_errno` and `vader_ptr_at`, since the interpreter runs a pinned
target's bodies on any host, and the identification of the target
(`vader_current_os`, `vader_current_arch`).

## Consequences

The collector, the traps and the FFI have one path each. A port of the C runtime
is a part `rt/os_<target>.c` defining the `vader_os_*` list, the accessors
`vader.h` declares for it and the library loader, plus one arm in the unity's
`#if`.

This is a layout for the C runtime, not the target model TODO.md asks for: it
does not say how the standard library marks a service unavailable on a target.

`tests/runtime_parts.test.ts` parses a part named after an OS only on a host of
that OS, the one where the unity includes it.
