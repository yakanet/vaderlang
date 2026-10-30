# 0120: An iterator step returns its element or `Stop`

## Status

Accepted (2026-10-30).

## Context

`Iterator.next` returned a pair, `[T, Continuation]`: the element, then whether
the iteration went on. The pair had two costs.

- At the end, `next` had to hand over a `T` it did not have. An implementation
  returned whatever it held (a range its cursor, `StringChars` a space), and one
  with nothing at hand, an iterator over an empty array, could only be a
  generator, whose synthesised `next` pairs the type's zero. `array_iter` existed
  for that reason alone.
- The pair crossed the call in registers only on a direct call with a scalar
  `T`. Through `Iterator<T>`, in an erased generic, or with a struct element,
  every step allocated a tuple on the heap.

The async protocol already ends with a type of its own: `resume` returns
`T | Suspended`.

## Decision

- `next :: fn(self) -> T | Stop`, with `Stop :: struct {}` and the constant
  `STOP :: Stop {}` in `std/core`. `return STOP` allocates nothing, where
  `return Stop {}` allocates, and gives `next` a GC frame on every call.
- The lowering reads the step through one file, `vader/lower/iterator_step.vader`:
  the end is a type test against `Stop`, the element a cast, and a generator's
  synthesised `next` returns `STOP` when it is done.
- The array's `Into<Iterator<T>>` writes its `yield` in place; `array_iter` goes.
- An element type that can hold `Stop` (`Iterator<Stop>`, `Iterator<A | Stop>`)
  is an error: `next` could no longer say the iteration is over. In a generic
  function, the call that instantiates the parameter gets it.

Set aside:

- **A `next` that calls back** (`fn(self, emit: fn(T) -> void)`): iteration
  becomes pushed, so `zip`, `take` and `peek`, which pull, need a buffer, and an
  indirect call per element does not fuse through an erased `Iterator<T>`.
- **A one-variant enum for `Stop`**: a boxed enum carries the tag of its
  representation, so `v is Stop` held for an `i64` on the VM.
- **A built-in unit like `null`**: new syntax for no measured gain over a
  field-less struct and its constant.
- **Keeping the pair and passing it through out-parameters**: it fixes the
  direct call only, and leaves the filler element.

## Consequences

- Measured on the protocol in isolation, `--release`, best of five: an `i64`
  iterator walked through the trait goes from 219 to 21 ms natively, a struct
  iterator from 276 to 34 ms. On `bench/`, `map_iter` gains 29 % and
  `binary_trees` 10 %.
- A `for` over a concrete `i64` iterator is 27 % slower on the VM (145 to 185 ms):
  the register engine does not translate the type test and runs it boxed. An op
  for `x is SomeStruct` is the remedy, in a change of its own.
- A `null` element needs no special case: `U | null` steps as `U | null | Stop`.
