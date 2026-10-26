# 0072: A generic function as a value is instantiated where it is used

## Status

Accepted (2026-10-18). Step 5 of the type-system charter (D1, choice F4). Builds on
0070 (a generic call instantiates its callee afresh) and 0071 (a call carries its
written type arguments).

## Context

A generic function's type carries its quantifier (`FnType.type_params`, 0070), and a
call instantiates it. A function named anywhere else kept the quantifier:
`apply(name_of, 5)` was T3001 (`expected fn(i32) -> string, got fn(T) -> string`),
`g :: id` then `g(3)` passed `check` and stopped the build on an unmaterialised
callee, and `id<i32>` did not parse outside a call.

Two choices were open:

- **(a)** instantiate the function where it is used, against the slot it fills,
  and let a local `::` binding with no annotation alias it;
- **(b)** require a function type at the binding (`g: fn(i32) -> i32: id`) and
  refuse `g :: id`.

## Decision

- **(a).** A name designating a generic function outside a call is instantiated
  against the function type of the slot it fills: each quantified parameter becomes
  a fresh inference variable, bound by unifying the instance with the slot. The
  slot of a generic call may itself hold that call's variables (`xs.map(name_of)`);
  they solve together.
- **Written arguments** (`name_of<i32>`, `pair<i64>`) fix the first parameters, as
  on a call; the slot binds the rest.
- **A local `::` binding with no annotation whose value names a generic function
  is an alias** (`TypedProgram.fn_aliases`): it has no slot, and each use of it
  names the function. A call through it is a direct call of the function, a use as
  a value is instantiated like the function's own name. A module constant is no
  alias: an exported one would alias across modules. It takes an annotation.
- The site is recorded in the call-site record under its own role,
  `CallRole.Reference`, with the type each parameter takes. The lowering names the
  instance from it, and the growing-recursion check (T3104) reads it like a call.
- A generic function used as a value with neither a function-typed slot nor its
  type arguments is T3069.

## Consequences

- An instance of a generic function shares its origin's symbol id, so a value, an
  address or a closure made of one resolves by mangle first, as a direct call does.
- A mutable binding (`m := id`) is not an alias: it holds one value, and has no slot
  type to instantiate against, so it is T3069.
- A generic method of a trait used as a value is not covered: its own parameters
  are not instantiated in the lowering yet.
- The language server keeps an alias's name its own: renaming `g` renames its uses,
  and `id` is an implicit reference wherever `g` names it.
