# 0060 — An array argument widens its element when its callee only reads it

## Status

Accepted (2026-10-14). Replaces the covariance that the read-only bit granted an
array, which the rights of ADR 0053 are about to take out of the types.

## Context

An array is shared, not copied: a `Circle[]` seen as a `(Circle | null)[]` lets
a write through the wider alias put a `null` into the caller's buffer. The only
covariance of the language was that of an array into a read-only target, on the
grounds that nothing writes through it. Three things were wrong with it:

- the rights are leaving the types (ADR 0053), and the bit with them;
- a method-form receiver was compared by shape, so it was covariant even into a
  method that pushes into it: `circles.add_null()` compiled, then trapped;
- a struct array never widened to a trait array (`Circle[]` to `Shape[]`):
  `is_assignable` has no impls to consult.

The covariance served four sites of the tree: two `push_all` into a union array,
one argument of a private function, and one snippet's local view.

## Decision

- **The element of an array is invariant** wherever the array is bound, stored or
  returned; only its `!` may differ.
- **An argument may widen it**, receiver included, at any depth: into a union that
  holds it, or into a trait it implements, provided the wider element reads the
  slots the source is laid out in. The typecheck accepts the argument and notes
  the depth (`TypedProgram.widened_arguments`).
- **The effect summary of ADR 0059 decides it** once every module is typed: the
  widening is sound when no function the call may run replaces an element, nor
  grows, keeps, returns or hands to unseen code an array on the way down to the
  widened element. Shrinking is sound, and so is keeping or returning the element
  itself. A breach is T3102, at the argument, naming what the callee does. A
  widening no call decides, such as a method value `circles.add`, is T3102 too.
- **One entry point checks a project**, `vader/pipeline/check`: the typecheck,
  then the checks that need the whole program typed. The typecheck cannot import
  the summary it feeds; the CLI, the dumps and the LSP all go through it.
- **No annotation, no boundary.** An exported function is deduced like any other:
  until packages are compiled apart, the whole program is summarised. A package
  compiled apart will carry the summary of its exports in its interface.
- **A frame that outlives the call is no escape.** The frame of a generator or an
  `async` function, and the bindings a lambda captures, are reached only by the
  code the walk reads; what that code yields or returns is stored. Without this,
  every array read through an iterator chain kept it.
- A fresh literal is no widening: it takes the slot's element, a trait included.

## Consequences

- `total(circles)` with `total :: fn(shapes: Shape[])`, the example of the type
  system charter, compiles and runs, natively and on the VM.
- The receiver hole is closed: `circles.add_null()` is T3102.
- The verdict reads the effect summary that every check runs (ADR 0059).
- A widened argument whose callee is a function value is refused: there is no
  body to read.
- Still invariant: a local, a field, a return, a named function converted to a
  function type (`fn(Shape[])` for `fn(Circle[])`), and the operands of an
  operator, an `in` or an index. An array whose element changes representation
  (`i32[]` to `(i32 | string)[]`) is refused. Each could be added later: a local
  through the summary's view of the binding, the operands by routing them
  through the same acceptance, the representation through a converted copy.
