## Types you rarely write

Inference fills in the types of locals, lambdas and generic calls. `::` binds a constant, `:=` a variable, and that is the whole ceremony.

## No null by accident

A value can be null only when its type says so, `T | null`. After `if user == null { return }`, the compiler knows `user` is a `User`.

## Errors are values

There are no exceptions. A function that can fail returns a union, `string | IOError`, and the caller handles it like any other value.

## Functions, not classes

There are no classes and no inheritance. `a.f(b)` calls `f(a, b)`, so any function reads like a method of its first argument.

## Compile time, not macros

`@comptime` runs ordinary Vader during the build and keeps what it computes: tables, constants, checks.

## Written in Vader

The compiler compiles itself, to the same C byte for byte, and a C compiler is enough to rebuild it from the seed in the repository.
