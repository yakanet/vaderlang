# 0155: What Vader cannot write is a member of `Intrinsic`

## Status

Accepted (2026-11-16).

## Context

One decorator, `@intrinsic`, covered five mechanisms: about forty bodyless free
functions the VM and the C runtime provide (`byte_len`, `collect`, `park`), an op
standing for a function (`new_byte_buffer`), the impls of the primitives (`Add`,
`Equals`, `Hash`...), the array methods (`T[] implements ArrayOps`) and the
buffer's (`Buffer implements ByteAccess`). The compiler found each one again
downstream from a string: two tables keyed by mangled name, seven readers of the
mangle, the lowering by member name and arity.

A declaration was never confronted with what implements it: a missing host was
a panic at emission, with no span. The missing body also took paths of its own
through the passes: a fallback in the impl lookup, a skip when surfacing members,
stubs the resolver made for a bodyless impl, a string table in the effect
summary, and eight tests of the decorator's name.

## Decision

- **A trait of `std/core`, `Intrinsic`, declares what Vader cannot write.** Its
  members are static, called on the trait (`Intrinsic.byte_len(s)`), the only
  trait whose members are. The toolchain implements it; `X implements Intrinsic`
  is an error. A member's name is its identity: the host import is
  `std_core$Intrinsic$<member>`, and `IntrinsicId` is found from the name alone.
  A generic member is imported once per instance
  (`std_core$Intrinsic$deep_copy__Shape`), so each backend serves a concrete type.
- **Everything else in the standard library is Vader.** A free function, an impl
  of a primitive, an array function wraps a member or a native operator:
  `export byte_len :: fn(s: string) -> i64 = Intrinsic.byte_len(s)`,
  `i32 implements Add -> self + other`.
- **A shape rule, never a name.** A function whose body is one primitive
  operation on its parameters, in order (a member of `Intrinsic`, or a native
  operator on scalars), lowers at each call as that operation. The rule is read
  by the type checker and the lowering, for every call form. A debug build keeps
  the call, so a breakpoint in the function is hit.
- **The array methods are free functions** (`len`, `push`...), not a trait
  nobody used as a bound; a distinct over an array no longer exposes them.
- **`@intrinsic` is gone.** A bodyless free function must be `@extern`.

Rejected: `@intrinsic(.X)` on the declaration (the compiler's enum would become
language surface, and the declaration would still say nothing a backend checks);
a dedicated IR node for a host call (a member already takes the path of a
bodyless function: lowering, instantiation, import table); recognising the
wrappers in a mid-IR pass (too late for the lowering's own optimisations, which
read typed array nodes).

## Consequences

Adding what Vader cannot write is one member, one `IntrinsicId` variant, and an
arm in each backend's exhaustive match, which the build enforces. Every impl of
a primitive is a real function, so a vtable over an erased primitive calls it
like any other; measured on the VM, the dispatch got slightly faster, not slower.
The members are unstable: a program calls the library functions that wrap them.
