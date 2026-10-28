# 0114: A default body is checked once, in its trait

## Status

Accepted (2026-10-28). Supersedes
[0012](0012-materialised-clone-spans-are-deterministic-per-impl.md): no body is
copied any more, and a member declared from its trait is identified by its node
id, not by a span.

## Context

The resolver used to copy each default method into every impl that did not write
it, with `Self` and the trait's parameters substituted, and the type checker
checked each copy. The lowerer read the copies' types. That had four costs:

- A type test on `Self` was settled in each copy, where `self` has the impl's
  type, and the type checker reported it as dead (T3040, W0014, T3013, W0005). A
  guard silenced these when the tested value had the impl's type, which is wrong
  both ways: in the copy for `i32`, `x: i32; x is string` was no longer reported,
  while `opt: Self | null; opt is Square` still was.
- An error in a default body was reported once per impl, at a synthetic
  `<clone>:` position, and never for a trait with no impl.
- `is Square { side }` in a default body with two impls or more failed at
  lowering (M5007).
- Every impl paid for a full check of every body it inherited.

## Decision

- **D1. `Self` in a default body is a type parameter of its own**, minted per trait
  by the resolver and bounded by the trait at its own parameters plus its
  `requires` (`Shape & Named`). Set aside: the built-in `Self` plus a "current
  trait" at every reader. A probe found 72 type-checker sites specific to type
  parameters against 17 to `Self`; with a bounded parameter, 3 snippets of 497
  changed and no diagnostic fixture, with `Self` alone, 9 snippets and T3008 on
  every `self.f()`.
- **D2. The body is checked against the trait's bounds**, as a `fn<T>` is: an
  operation on a parameter of the trait needs its bound (`Counter<Step: Add>`).
  Set aside: checking again per impl, which keeps the per-impl reports.
- **D3. An inherited member is a declaration without a body** that names the
  trait's member (`FnDecl.inherits`). Impl tables, vtables and the language
  server keep one declaration per (impl, member). Set aside: an (impl, member)
  key at every reader.
- **D4. The trait's parameters are substituted per impl**, so they erase nothing
  in the body: T3087 does not fire there, and T3040 reads `Box<T>` as able to
  overlap `Box<i32>`. Each impl reads the body's type tests again at its own
  arguments, and reports T3087 when its instances cannot tell them apart.

The lowerer reads the trait's body for each impl as it reads a generic function
for each instance, `Self` bound to the impl's type and the trait's parameters to
its arguments (`vader/lower/inherited.vader`). Lowering one declaration twice by
another path loses what an instance keeps apart, a `defer` capturing a parameter
among them.

## Consequences

- An error in a default body is reported once, at its own position, with or
  without an impl. Growing the receiver of a recursive default (T3104) is
  reported in the trait too.
- A default body that relies on what one impl happens to provide no longer
  compiles: the trait has to say it in a bound.
- Every reader of a body reaches it through `inherits`: the effects index, the
  async and generator scan, the impls of arrays. One that reads `body` alone sees
  an inherited member as bodyless.
- An inherited member is typed from its trait's member, read in the trait's
  module: its signature names what the trait's file imports. A default with an
  expression body may leave out its return type; every reader takes the one its
  body gives, recorded once per trait member.
- An impl member is identified by its node id: its type, and the array impl a
  call reaches. A member declared for an impl from its trait is written
  nowhere: its name and an inherited member's parameters take a span that names
  no source.
- An editor reaches the default from a call of an inherited member: its
  references, its definition, its hover.
