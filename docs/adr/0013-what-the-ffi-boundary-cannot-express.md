# 0013 — What the FFI boundary cannot express

## Status

Accepted (2026-09-05).

## Context

`std/io::is_dir` has been implemented three times, each attempt with its
reasoning retyped into a comment the next attempt had to rewrite. The question
underneath it — *how does Vader read one member of a C struct?* — is the same
question `termios`, `dirent`, `stat` and every future binding ask, so it is worth
settling once.

**Attempt 1, a `@c_struct` mirror of `struct stat`.** A mirror declares the
fields Vader cares about, and the shim copies them BY NAME, so no Vader offset
ever meets a C one. What made this look safe is what killed it: the interpreter
has no C layout, so it builds its own block from the DECLARED fields at natural
alignment from offset zero and hands that address to the real callee. The mirror
is therefore correct only while it is a contiguous **leading prefix** of the C
type. `st_mode` leads on no architecture — offset 24 on linux-x86_64, 16 on
linux-arm64 — so the build-time offset assert refuses a partial mirror on *both*.
And a full leading-prefix mirror fails too: the two arches disagree on field
ORDER (`dev, ino, nlink, mode` against `dev, ino, mode, nlink`). No width axis
and no architecture axis can express that. `struct stat` is not "ambiguous
between arches"; it is **inexpressible**, and adding an arch axis — or bringing
back the `@c_size` escape that was removed for this exact case — would not change
that.

**Attempt 2, `opendir`.** Asking a different syscall removes the layout question
entirely, which is why it looked like the deeper fix. It answers a *different*
question: `opendir` needs READ permission on the directory where `stat` needs
only traverse rights on the parent. A directory with mode 0700 owned by someone
else answered "not a directory".

## Decision

The FFI boundary can express:

- a C **function**, through `@extern` + `@c_header` — the header is the only
  check that the Vader signature matches the real prototype;
- a C struct that crosses as an **address**, through `@c_struct`, as long as the
  mirror is a contiguous leading prefix and every field's width is asserted;
- an **opaque region** whose size is known but whose layout is not, as a `u8[]`
  plus a size constant taken HIGH — `posix::TERMIOS_BYTES` is the reference. A
  size is not an offset, which is why no architecture axis is needed;
- a **pointer** the callee fills, through `@c_pointer` or a lent array.

It cannot express **an offset that moves** or **a field order that moves**. When
a binding needs one of those, the escape is a named-member accessor in
`runtime/c/`, compiled by the same `cc` that owns the header: reading a NAMED
member of a C struct is the one step a Vader FFI call cannot take for itself.
`vader_dirent_name`, `vader_find_data_name` and `vader_path_kind` are that, and
nothing more — the accessor resolves the member; the policy stays in Vader.

An accessor that returns an ordinal is met on the Vader side by named constants,
not an enum. An enum would say it better — `vader_current_os` pairs with
`std/target::Os` exactly that way — but that pairing works because `current_os`
is `@intrinsic`. `@extern` cannot carry an enum (T3050), so a wrapper would be
needed, and a wrapper gives the binding module a BODY. `system/posix` and
`system/windows` are declaration-only by construction, and the moment one of them
emits a unit the module set stops matching across targets, which
`--seed-targets` refuses outright. Measured, not assumed: adding the wrapper
produced `windows-x86_64` and `darwin-arm64` emitted different module sets.

So a binding module stays declarations and constants. The C side carries the
comment saying the values must match.

## Consequences

The runtime keeps a small, growing set of accessors, and each new field costs one
of them rather than one policy function. `std/io::is_dir` reads
`sys_path_kind(path) == PATH_DIRECTORY`; a future `file_size` or `mtime`
costs an accessor each and no new mechanism.

Two things this deliberately does NOT buy back:

- **`@c_size` stays removed.** It would have let a mirror declare a size without
  offsets, which is exactly the shape that made attempt 1 wrong under the
  interpreter.
- **Windows answers the same questions at a different layer.** `GetFileAttributesW`
  returns a bitmask Vader can test directly, so `is_dir`'s Windows body keeps its
  policy in Vader while the POSIX body reaches an accessor. The asymmetry is the
  platform's, not the language's.

A cost worth naming: an accessor is invisible to the `@c_header` check, since it
is our own function and its prototype is generated from its Vader declaration. It
buys layout independence by moving the risk from "the mirror disagrees with the
header" to "the accessor disagrees with its Vader declaration" — a smaller
surface, one line each, but not zero.
