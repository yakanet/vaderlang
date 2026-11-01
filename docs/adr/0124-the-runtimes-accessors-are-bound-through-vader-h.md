# 0124: The runtime's accessors are bound through `vader.h`

## Status

Accepted (2026-11-01). Amends [0013](0013-what-the-ffi-boundary-cannot-express.md):
the cost it names under Consequences, not its decision.

## Context

0013 sends what an `@extern` cannot reach (a macro, a member whose offset moves)
to a named accessor in `runtime/c/`, and names the price: the accessor is our own
function, so no header declares it, and the compiler synthesises its prototype
from the Vader declaration. Nothing compared the two.

The comparison was missing in fact, not only in principle. The seeds declared
`vader_dirent_name(void*)` while the runtime defined it on a `const void*`, and
nobody saw it: the two declarations never meet in one translation unit.

The accessors are eight: `vader_last_errno`, `vader_ptr_at`, and per platform
`vader_find_data_name` (Windows) or `vader_environ`, `vader_path_kind`,
`vader_path_mtime`, `vader_stream_size`, `vader_dirent_name` (POSIX).

## Decision

`vader.h` declares the eight, and the two binding modules name them through a
library whose header it is:

```vader
VADER_RUNTIME :: CLibrary { .name = "", .header = "vader.h" }

@extern(VADER_RUNTIME, "vader_path_kind")
export sys_path_kind :: fn(path: string) -> i32
```

The empty `name` is the running process, where `vader run` already found them.
The constant is private to each module, `system/posix` and `system/windows`: a
public one in `std/ffi` would offer every program a way into the runtime.

## Consequences

`cc` now compiles each accessor call against the prototype the runtime's own
definition is compiled against. A wrong argument count, or an integer passed
where a pointer goes, stops the build. A wrong integer WIDTH still does not: C
converts integers in silence, and the driver turns no warning into an error. That
holds for every header-bound `@extern`, `write` included.

A `vader.h` prototype must stay compatible with what the committed seeds declare,
since the seed is compiled against the current `vader.h`: an incompatible one
stops the bootstrap before a new seed can be emitted. That is why
`vader_dirent_name` takes a `void*`.

The profiler's `vader_prof_*` hooks keep a synthesised prototype: only the
compiler calls them (`vader/support/profile`), and the profiler is due to leave C.
