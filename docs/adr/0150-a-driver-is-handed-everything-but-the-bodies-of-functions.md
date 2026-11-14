# 0150: A driver is handed everything but the bodies of functions

## Status

Accepted (2026-11-14). Supersedes in part
[0147](0147-a-driver-is-handed-the-surface-of-the-elaborated-declarations.md):
its decision that only the surface of a declaration crosses, without values.

## Context

0147 sent a driver the surface of each declaration and opened it a little at a
time. The next step was constants. The value of a constant is an expression,
and `ConstDecl.value` is not optional, so a constant could not cross without a
value unless the node held a stand-in.

A plugin is written by any user of the language, so the API it reads has to be
predictable. A declaration that crosses or not depending on the form of its
value fails that: `MAX :: 4096` would arrive and `MAX :: 4 * 1024` would not.
A field that reads null when the source wrote something leaves the plugin
unable to tell an absence from an omission. Other tools draw the line in
different places. Java's annotation processors show every declaration, and the
value of a constant only when it is a compile-time constant. KSP shows
signatures without bodies. Rust and Swift macros, like Jai, see the whole tree
of what they are given. The line a reader guesses without being told is "all
but the bodies".

## Decision

- **Every declaration the source writes crosses**, constants and assertions
  included. None the compiler made does: the helper the parser writes to compute
  a `@comptime` constant stays behind, as a member an impl takes from its trait
  already did.
- **What a declaration writes outside the body of a function crosses as it is
  written**: the value of a constant, the defaults of fields and parameters,
  the data of a variant, what a struct spreads, every type. A `@comptime`
  constant crosses with the expression it is written with, not the call to its
  helper. A call crosses with the arguments written: the type checker puts
  them in the order of the parameters and fills in the omitted defaults in
  place, so it keeps the written list aside for this (`CallExpr.written_args`).
- **The body of a function does not cross**, a trait member's default
  included. A plugin that needs one will ask for it, as it asks for a vaderdoc
  ([0149](0149-a-driver-asks-its-build-for-what-does-not-cross.md)).
- **One codec for every expression.** A value may hold a lambda or a block, so
  the codec covers statements and patterns too. A type is an expression in the
  tree and crosses through the same codec. An operator crosses as its spelling.
- Decorators do not cross yet: their shape waits on the plan for user
  decorators. Until they do, a `@comptime` constant arrives without its
  marker; when they do, the `@comptime` decorator the parser adds to such a
  constant is one the compiler made, and stays behind.

## Consequences

A plugin sees every declaration, and each field it reads is either what the
source wrote or empty by a rule it can name: a function body, a decorator, a
vaderdoc. A rule over the names of constants, or a derive that follows an
alias `Celsius :: f64`, now has what it needs.

The codec holds what a function body is made of, so sending a body later costs
no new code on the wire, only the question that asks for it. The frames grow
with the values and defaults of the delivered modules, which are small next to
the bodies that still stay behind.
