# 0174: A type parameter written beside `null` cannot hold `null`

## Status

Accepted (2026-11-22).

## Context

A type parameter may be bound to any type, `null` included, and a union with
`null` holds one `null`. A signature that writes `T | null` uses that `null` to
say a value is absent: `first` on an empty array, `m[k]` on an absent key,
`put_absent` when it stored the value. With `T = i32 | null`, the `null` of an
element and the `null` of the absence read alike:

- `[null, 1].first()` is `null`, as for an empty array;
- `m["a"]` is `null` on a `Map<string, i32 | null>` that holds `"a"`;
- `put_absent("a", 5)` returns `null`, which its contract reads as "stored",
  while the map kept its `null`.

The standard library worked around it case by case: a note on `Map`, and
`Queue.remove_first`, which exists only to hand a `null` item back as itself.

Measured on the whole tree (`lib/`, `vader/`, `tools/`, the snippets and the
examples), with a probe at each instance: one site bound such a parameter to a
nullable type, `copy_baked_values`, which used the two `null`s on purpose to
hold three states with `k in m` and `m[k]`. None of the 86 nullable arrays
called `first`, `last` or `remove_last`.

## Decision

- **A type parameter written beside `null` in a signature (`T | null`) cannot
  be bound to a type that can hold `null`** (T3150). It is checked where the
  instance turns concrete, as T3121 is for `Stop` (0120): a generic call, a
  generic function taken as a value or as a method value, and the read `m[k]`
  through the `Index` impl of a generic struct.
- **A type parameter passes**: a generic body that hands its own `T` to such a
  signature is not checked, its instance is checked where it gets one.
- **`drop_last`** joins `remove_last` in `std/core`: it removes the last
  element and hands nothing back, so it takes an array whose elements can be
  `null`. `remove_value` and `remove_where` call it.
- `copy_baked_values` names its third state: the deferred decls in a `Set`,
  the values the VM baked in a `Map` of non-null values.

Set aside:

- **No type parameter holds `null` unless it says so** (`<T>` non-null by
  default, an opt-in marker for the others). Of the 114 generic functions
  `std` exports, 15 write a parameter beside `null`; the others store or move
  their `T` (`push`, `len`, indexing, `put`, `map`) and a nullable element is
  legitimate there. The default would put the marker on most of them.
- **A bound naming `null`** (`T: Something & null`): a bound names traits
  (R2042 rejects `T: Bump | null`), and `&` would read as "is both".
- **A sentinel type for the absence** (`V | Absent`, as `Stop` for an iterator
  step): `else` handles `null` and the errors, so `m[k] else 0` would be lost.
- **Checking only the instances whose result is read**: a call whose result is
  thrown away cannot confuse its caller, but the check would move from the
  instance to every place a value is consumed. `drop_last` covers the case
  measured; a function with nothing to hand back is the answer to the next one.
- **Propagating the check through a generic body** that reads such a result on
  its own `T` without writing `T | null` in its signature: no site in the tree
  does it, and it would need a summary per generic function.

## Consequences

- A `Map` whose `V` can hold `null` is still written and iterated; `m[k]` and
  `put_absent` on it are errors. `k in m` and a `for` over the map still work.
- A generic body that reads `T | null` from a function on its own `T` without
  saying so in its signature keeps the ambiguity for its callers.
