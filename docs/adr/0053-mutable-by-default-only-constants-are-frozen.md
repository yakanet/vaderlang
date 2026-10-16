# 0053 — Mutable by default; only constants are frozen

## Status

Accepted (2026-10-09). The migration landed with 0067 and
[0069](0069-the-marker-leaves-the-grammar-without-a-transition.md): this record
supersedes 0017, 0022, 0032–0036, 0039, 0040, 0045, 0049–0052 and the rights half of
0034, 0041, 0043 and 0044.

**Carried out by [0067](0067-the-frozen-values-decide-what-may-be-written.md)
(2026-10-16)**: the rights no longer decide, the frozen values do. Module variables
are not `NAME := value`: the form gave way to `@singleton`
([0068](0068-a-module-keeps-state-in-a-singleton.md)); a view is never copied, and a
variant's data is frozen too.

## Context

Since 0017, every written type was a read-only slot and `!` granted mutation, level
by level. Twenty records refined it: invariance of a mutable level's elements, the
rights a type parameter binds, the variance of an impl against its trait, then the
deduction of a parameter's and an annotated local's `!` from its body (0051, 0052).

What it protected, by a survey of 2026-10-06: a module constant in `.rodata` (a write
there is a `SIGBUS` natively, and lost silently in the VM), a constant rebuilt at each
read (a write there is lost), a `bytes()` view aliasing an interned string, and the
direction of data at the FFI. No bug was ever caught through a parameter's `!`: the
known catches all came from constants.

What it cost, measured on 2026-10-09 at `b75e0a7e2`:

- 1 645 markers still written in `vader/`, `lib/`, `bench/` and `examples/` after
  the deduction, on fields, returns, fn types and type arguments;
- typecheck of the compiler at ~1 160 ms in two rounds, against ~540 ms before the
  deduction; `vader check` of the compiler twice as slow;
- thirteen diagnostic codes, and a model to learn before writing a loop: per-level
  rights, invariance, deduced against written.

Nine small programs were checked against the compiler of that day. Eight failed;
three of them were correct code (an accumulator returned and then extended, a
callback that updates its argument, a field updated through its struct). In three
cases, following the error's advice led to a second error. One advice pointed into
the standard library, where the user can change nothing.

## Decision

**Everything is mutable, except the value of a module constant and a view of a
string's bytes. A frozen value is never modified in place: what is stored elsewhere
is a copy of it.**

- **No `!`.** Parameters, locals, fields, returns, fn types and type arguments carry
  no rights. Emitted C does not change: it never depended on them, except for the
  three points below.
- **Frozen values.** The value of a module constant (`NAME :: value`), deeply; and a
  string's bytes (`s.bytes()`), which alias the interned string.
- **Module variables.** `NAME := value`, or `NAME: T = value` with a type: a
  writable global rooted for the collector — the storage a marked module constant
  (`NAME: T[]!: value`) has today.
- **Two static errors, at the site of the fault:**
  - writing through a path rooted at a frozen value (`LIMITS[0] = 5`,
    `CONFIG.items.push(x)`); the message offers a module variable;
  - passing a frozen value to a parameter its callee modifies (`double_all(LIMITS)`);
    the message offers `.clone()`.
- **A frozen value stored elsewhere is copied:** bound to a name, put in a field or
  an element, returned, or handed to a parameter its callee stores. The copy is
  left out wherever nothing modifies what was stored.
- **Effects.** Whether a function modifies or stores a parameter is a summary
  computed once over the call graph, without typecheck rounds. An intrinsic's effect
  is the compiler's own knowledge; an abstract trait member's is the union of its
  impls' (the whole program is compiled); a function value's is assumed to modify.
- **FFI.** A parameter of an `@extern` is read by C by default (`const void*`,
  nothing copied back). `@c_out` says C writes it: `void*`, the `@c_struct` mirror is
  copied back, and a frozen value is refused there. Without `@c_out`, a mirror is cast
  to `const void*`, so that with `@c_header` the C compiler reports a missing one.

The three points where emitted code read the read-only bit: `emit_array_set` skips
the `buf == NULL` test because a `bytes()` view could not be written; the data pool
puts a constant in `.rodata` and a marked one in a writable global; the FFI chooses
`void*` or `const void*`. They are rewired to frozen values, module variables and
`@c_out`.

## Consequences

- **No longer checked:** that a function leaves an ordinary argument unmodified, as
  in Go, Java or Python. A frozen value stays protected, statically.
- **Removed:** the deduction rounds (0051, 0052), W0017 / W0018 and `vader fix` for
  `!`, most of T3070–T3077, T3095, the invariance of mutable levels, the rights a
  type parameter binds, and the read-only bit of the type IR.
- **Copies:** a constant stored into a container that something modifies is copied
  at each store. The compiler stores type singletons (`TY_*`) in about 160 places;
  the cost is measured during the migration, and a store whose type nothing ever
  modifies needs no copy.
- **Migration:** 1 645 markers removed mechanically; 6 marked constants become
  module variables; 40 FFI parameters take `@c_out`.
