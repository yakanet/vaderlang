# 0113: A mangled name is a C identifier, `$` included

## Status

Accepted (2026-10-25).

## Context

A mangled name joins a module, a declaration and, for an impl member, its target,
its trait and the member. Three steps lost information on the way:

- A module path turned `/` into `_`, while `_` is legal in a path: `a/b` and `a_b`
  shared every name, so a type implementing the trait `C` of one passed for the
  `C` of the other, without a word.
- A type qualified by its module was joined with `_` (`a_b_C`), where every other
  part is joined with `$`: the type `C` of `a/b` and the type `b_C` of `a` met in
  one name, and one of two impls was lost.
- The C backend turned every byte outside `[A-Za-z0-9_]` into `_`, `$` included,
  so even two names the bytecode kept apart met again in C.

## Decision

- **A `_` of a module path doubles, `/` becomes `_`** (`std/string_builder` is
  `std_string__builder`, `a_b` is `a__b`). A path matches
  `[a-z][a-z0-9_]*(/[a-z][a-z0-9_]*)*`, where no segment starts with `_`, so the
  fragment maps back to one path.
- **`$` separates every part**, a type qualified by its module included
  (`a_b$C`, `a$b_C`). No Vader identifier and no module path holds a `$`.
- **`$` stays in the C name.** It is an identifier byte to clang, gcc and mingw,
  even under `-std=c11`, and lldb sets breakpoints on such names and calls them.
  A C name is the mangled name itself, and a C keyword takes a `$` suffix, which
  ends no mangled name.
- **No mangled name holds another byte.** An impl on a type with no declaration
  takes a `$` token (`$array`, `$tuple`, `$fn`, `$union`) that no declared name
  can spell. A captured local's cell is named like a tuple shape, spelled then
  hashed. A vtable key's `.` becomes `$` in its C dispatcher. The C backend stops
  on any other byte instead of rewriting it, and an FFI adapter's symbol is the
  mangled name behind a prefix.

## Consequences

- No escaping and no table: a C name depends on its own mangled name only, not on
  the rest of the program. Set aside: an escape for every byte outside the C
  identifier class, as JNI writes `_1` for `_`, which makes most names harder to
  read, and a program-wide table appending a suffix to colliding names, which lets
  one new function rename another.
- The generated C relies on an extension: a C compiler that refuses `$` in an
  identifier cannot build it. clang warns about it under `-pedantic` only.
- A type's display is still flattened by `sanitise_ident` where it names an
  instance (`Box<Box<i32>>` gives `snippet_Box_snippet_Box_i32__`) or the
  concrete tuple, fn or union target of an impl, so two argument lists or two
  shapes can still share a name.
