# 0154: A driver reads the value of a decorator

## Status

Accepted (2026-11-16). Supersedes the part of
[0153](0153-a-driver-reads-a-decorator-as-written.md) that has a driver receive a
decorator as written. Reflection at compile time stays as 0153 has it.

## Context

The compiler computes the value of every declared decorator written, `@comptime`
arguments and defaults included, and the driver received the arguments as
written: `@Route(@comptime versioned("/users"))` reached it as a call it cannot
run, and a field left out did not reach it at all. Reflection, the reader 0153
left the value to, is not built, so a value computed at compile time had no
reader. A driver that generates code from a decorator, a router from `@Route`,
needs the value to decide anything.

## Decision

- **A declared decorator crosses with its value.** It arrives with one named
  argument per field of its declaration, in their order, holding the value the
  compiler computed as a literal: a number, a boolean, a character, a string,
  an enum variant (`.Get`), `null`, or an array of these. A field left out
  arrives with its default.
- **Spans stay the source's.** A field given an argument keeps that argument's
  span, so a report points at what the user wrote ; a default takes the span of
  the decorator.
- **No new model of values.** The literals are nodes of `toolchain/ast`, which
  the protocol's codec already carries ; a driver reads them as it read a
  written literal (`argument_named`, `string_literal_text`).
- **A decorator of the compiler crosses as written.** Its arguments are literals
  already, and nothing computes its value.

Rejected: keeping the written arguments and adding the value beside them, two
forms of one decorator to keep in step.

## Consequences

The written form of an argument (`@comptime versioned(...)`) no longer reaches a
driver ; the source shows it. A check on a computed value (two routes on one
path) can be made by a driver, at build time. Reflection (`@decorator(f, T)`,
`@decorated(T)`) remains the way for code compiled with the program to read a
decorator, without a driver.
