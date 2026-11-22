# 0172: `void` is a value, the success of an operation with nothing to return

## Status

Accepted (2026-11-22). Amends 0144: a function that may fail with nothing
to return answers `void | E`, not `null | E`.

## Context

An operation with nothing to return but which may fail (writing a file,
closing a stream, removing a directory) answered `null | IOError`. Under
0144, `null` is a failure: such a function returned a failure when it
succeeded, and `written :: write_file(p, t) else return written` was
refused, every value going to a clause that leaves. `null` meant nothing
there: it stood in for a success the type system had no word for.

The checker already accepted `void | IOError`, and built `T | void` for an
`if` without `else`, but `void` had no value at run time: a bare `return`
in such a function returned nothing where one value was due, and a
`Task<void>` that finished was seen as cancelled, its result never stored.

## Decision

- **`void` is a type with one value.** A function declared `-> void`
  still returns nothing: its calling convention does not change. Where a
  slot holds a value whatever its type (a union member, a type argument,
  an element of an array, a field), `void` is that one value.
- **`void` may be a member of a union**, beside `null`: they are two
  types, `null` the absence of a value, `void` the success of an operation
  that has none to give. A bare `else` takes `null` and the errors, never
  `void`.
- **In a function whose result admits `void`**, a bare `return`, or a
  body that reaches its end without a trailing expression, gives `void`.
  A trailing expression of the result type is the value, as in any
  function; one of another type is an error, as in any function that
  returns a value.
- **A call of a function that returns nothing, written where a value is
  expected, gives `void`**: `task.result.push(entry())` with `entry`
  returning nothing stores it.
- **At run time, `void` has its own tag**, reserved beside `null`'s: the
  box of tag 1, with no payload. `r is void` tests it.

## Consequences

- `null | E` results become `void | E` across the standard library;
  `return null` in them becomes `return`, and a caller's
  `else is null {} else return x` becomes `else return x`.
- A `Task<void>` that finishes is no longer seen as cancelled.
- A local of type `void` holds nothing; reading it where a value is due
  gives the one value.

## Set aside

- `void` as `null` at run time: cheaper, but a generic `T | null` with
  `T = void` would see a success as absent, and `void | null` would have to
  be refused.
- A bare `return` in an `else` clause that would hand the failure up:
  0144 writes what is returned.
- A unit struct in the prelude (`Done`): a new name for what `void` says.
