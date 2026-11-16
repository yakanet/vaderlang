# 0152: A decorator is a declared type

## Status

Accepted (2026-11-15).

**Superseded in part by
[0153](0153-a-driver-reads-a-decorator-as-written.md) (2026-11-16)**: a driver
reads a decorator as written; its value stays in the compiler, for reflection.

## Context

The compiler knows a closed table of decorators (`lib/toolchain/parser/decorators.vader`)
and rejects any other name (R2010). A build plugin that derives code from a
declaration, or gathers every declaration of a kind (routes, commands, a
registry), has no way to mark the code it reads: the choice falls back to whole
modules, which does not describe a table of routes.

Every system with code generators declares its annotations and imports them:
Java's `@interface`, Kotlin's `annotation class`, C#'s attribute classes, Rust's
derive helpers. Jai's free notes are the exception, and a misspelt note says
nothing.

## Decision

- **A decorator is a kind of type**, written like a struct:
  `Route :: decorator(.Function, repeatable = true) { method: Method, path: string }`,
  then `@Route(.Get, "/users/{id}")`. The parentheses are an ordinary argument
  list: the places it may be written (`DecoratorTarget` of `std/core`), and named
  options. Without them, it may be written anywhere.
- **Its fields hold compile-time values**: scalars, strings, enums, arrays of
  these. Its arguments are typed against the fields, positional or named, and
  evaluated by the compiler where they are written.
- **It changes nothing in the program it decorates.** Nothing of it remains after
  compilation but the code a reader made it produce. Its type stays an ordinary
  type: a plugin decodes values of it, a test builds one.
- **The name's casing is free.** The compiler's own decorators keep their
  snake_case names.
- **The compiler's decorators are declared the same way, in `std/core`**, and
  their names are reserved: declaring a decorator `test`, `extern` or `target` is
  an error, while a function or a variable may still take the name. A name
  after `@` is looked up among decorators only, and the compiler's decorators
  are not names of values. The passes that run before names are resolved
  (target selection, test discovery, reachability) therefore recognise them by
  name with no ambiguity, and the compiler names them through one enum instead
  of strings. No resolved identity travels through lowering and emission.
- **Nothing reserved stays behind `@`**: a declared decorator above a
  declaration, an intrinsic in an expression. The forms that are neither
  (`@comptime`, `@partial`, `@unreachable`, `@assert`, `@returns`, `@ensures`)
  move to their own designs.

Rejected: free notes (a typo is silent, no arguments are checked, the editor
cannot complete them); names declared by the build file (`check` and the editor
would have to run it); one generic `@note("...")` (strings again); a struct
marked by a meta-decorator (a decorator of its own, for what a keyword says);
decorators that run code on the declaration (macros: user code in every check
and every keystroke, and a transformation of the code the plugins do not do);
`|` between places (it means "one of" in a union and a pattern); a separate
scope for decorator names, or a resolved identity carried down to the
backends, both of which reserved names make unnecessary.

## Consequences

A plugin reads a decorator as a typed value instead of re-reading the
arguments as written. A library ships its decorators beside its runtime code,
and its plugin beside them, as `serde` and `serde_derive` do.

A user cannot name a decorator after one of the compiler's. The table of
decorators disappears once every compiler decorator is declared, and with it
the strings the compiler compares decorator names against.

Reading decorators from generic code at compile time (reflection) and
decorators that wrap the function they decorate are separate decisions.
