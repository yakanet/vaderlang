# 0099: An array has no `==`, its comparisons are named

## Status

Accepted (2026-10-06, `14f8e6a90`). Recorded 2026-10-20.

## Context

The equality work gave `==` one meaning, value equality through `Equals`, and
identity its own operator, `===`. A struct compares only once it implements
`Equals`; without one, `==` is T3043 rather than a silent reference compare.

Arrays were first given value equality, `T[] implements<T: Equals> Equals`,
element by element, and it was taken back the same day:

- `==` is O(1) everywhere else, strings included since they are interned atoms.
  Comparing two arrays walks both, and an operator hides that.
- An array is a reference type that has not opted into value equality, as a struct
  without `Equals` has not.
- Value equality on a mutable object makes collection keys fragile: a key changed
  after it was inserted is no longer found. Since 0067 no type marks an array
  read-only, so every array may change.
- Go makes the same choice and refuses `==` on slices.
- Through an erased `Equals` slot the impl was not reached: `same([1, 2], [1, 2])`
  under `fn<T: Equals>` stopped on a vtable miss, the array instance being
  materialised only where a direct `==` on arrays appeared.

## Decision

- **An array has no `==` and no `!=`**: T3043, whose detail points at
  `content_equals`, `is_permutation_of` and `===`.
- **`std/core` names each walk**, for any `T: Equals` element:
  `content_equals` (the same length, equal elements in the same order),
  `is_permutation_of` (the same elements in some order, each as many times;
  quadratic, so that `Equals` is all it needs), `contains_all` and `is_disjoint`.
- **An array does not meet an `Equals` bound**: `[1] in rows` with
  `rows: i32[][]` and `same(a, b)` with `fn<T: Equals>` are T3043 / T3006, and an
  array of arrays has no `content_equals`.
- **A distinct over an array opts in** by implementing `Equals`
  (`Row :: i32[]`, `Row implements Equals`) and compares through that impl;
  `i32[](row)` gives the array back for the methods above.

## Consequences

- The cost of a comparison is in its name, and `===` stays the cheap identity
  test.
- A struct holding an array writes its own `Equals`, calling `content_equals` on
  the field.
- `tests/diag_corpus/typecheck/t3043_array_eq_no_equals` pins the refusal, and
  `tests/snippets/array_content_comparison` the four comparisons.
