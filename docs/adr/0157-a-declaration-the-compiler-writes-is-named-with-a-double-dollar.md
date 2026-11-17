# 0157: A declaration the compiler writes is named with a double dollar

## Status

Accepted (2026-11-17). Extends [0113](0113-a-mangled-name-is-a-c-identifier-with-dollar.md).

## Context

An interceptor writes declarations as source beside the function it wraps: the
body under a new name, the singleton holding its state and its site, the struct
that singleton builds. They were named `__intercepted_g`, `__layer_g`: names a
user may write too, so a project declaring one met a duplicate it never wrote.
Chaining interceptors adds a declaration per layer, and source stages will write
more.

## Decision

- **A declaration the compiler writes is named `base$$word`** (`fib$$intercepted`,
  `fib$$layer`): the name it serves, `$$`, then the word of its role. The lexer
  reads a `$` in no name a user writes, so no written declaration takes it.
- **Only source the compiler writes may spell it**: `parse_compiler_written` lexes a
  name ending in `$$` and a word, and nothing else with a `$`.
- **The words are one closed enum, `GeneratedRole`**, beside the roles of the
  functions the compiler derives (`DerivedRole`, `vader/core/mangle`). A test
  checks no word is both: a role added later cannot take a word in silence.
- Every other name the compiler spells with a `$` (`$genstate_f`, `$array`) follows
  its module directly, where this one follows a declaration's name: the two never
  meet.

Rejected: reserving `__` (a rule on what users may write, for a problem only the
compiler has); `$$$` (no collision either, but heavy to read in a stack trace);
renaming after the parse (the glue would no longer show its real names).

## Consequences

A stack trace and the debugger show `fib$$intercepted`, recognisable as the
compiler's. The hidden constants of the comptime pass (`__decorator_argument_*`)
still use `__` and can move to the same scheme.
